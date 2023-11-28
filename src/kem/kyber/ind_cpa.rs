use super::{
    arithmetic::PolynomialRingElement,
    constants::{
        BYTES_PER_RING_ELEMENT, COEFFICIENTS_IN_RING_ELEMENT, REJECTION_SAMPLING_SEED_SIZE,
        SHARED_SECRET_SIZE,
    },
    conversions::into_padded_array,
    conversions::{UpdatableArray, UpdatingArray},
    hash_functions::{XOFx4, G, H, PRF},
    matrix::*,
    ntt::*,
    sampling::{sample_from_binomial_distribution, sample_from_uniform_distribution},
    serialize::{
        compress_then_serialize_message, compress_then_serialize_ring_element_u,
        compress_then_serialize_ring_element_v, deserialize_then_decompress_message,
        deserialize_then_decompress_ring_element_u, deserialize_then_decompress_ring_element_v,
        deserialize_to_uncompressed_ring_element, serialize_uncompressed_ring_element,
    },
    types::PrivateKey,
    Error, KyberPublicKey,
};

pub fn serialize_secret_key<const SERIALIZED_KEY_LEN: usize>(
    private_key: &[u8],
    public_key: &[u8],
    implicit_rejection_value: &[u8],
) -> [u8; SERIALIZED_KEY_LEN] {
    UpdatableArray::new([0u8; SERIALIZED_KEY_LEN])
        .push(private_key)
        .push(public_key)
        .push(&H(public_key))
        .push(implicit_rejection_value)
        .array()
}

#[inline(always)]
#[allow(non_snake_case)]
fn sample_matrix_A<const K: usize>(
    seed: [u8; 34],
    transpose: bool,
) -> ([[PolynomialRingElement; K]; K], Option<Error>) {
    let mut A_transpose = [[PolynomialRingElement::ZERO; K]; K];
    let mut sampling_error = None;

    for i in 0..K {
        let mut seeds = [seed; K];
        for j in 0..K {
            seeds[j][32] = i as u8;
            seeds[j][33] = j as u8;
        }
        let xof_bytes = XOFx4::<REJECTION_SAMPLING_SEED_SIZE, K>(seeds);

        for j in 0..K {
            let sampled = sample_from_uniform_distribution(xof_bytes[j], &mut sampling_error);

            // A[i][j] = A_transpose[j][i]
            if transpose {
                A_transpose[j][i] = sampled;
            } else {
                A_transpose[i][j] = sampled;
            }
        }
    }

    (A_transpose, sampling_error)
}

// Work around hax limitations for C extraction
#[inline(always)]
fn update_domain_separator(value: &mut [u8;1]) {
    value[0] += 1;
}

/// Sample a vector of ring elements from a centered binomial distribution and
/// convert them into their NTT representations.
#[inline(always)]
fn sample_vector_cbd_then_ntt<
    const K: usize,
    const ETA: usize,
    const ETA_RANDOMNESS_SIZE: usize,
>(
    mut prf_input: [u8; 33],
    domain_separator: &mut [u8;1],
) -> [PolynomialRingElement; K] {
    let mut re_as_ntt = [PolynomialRingElement::ZERO; K];
    for i in 0..K {
        prf_input[32] = domain_separator[0];
        update_domain_separator(domain_separator);

        let prf_output: [u8; ETA_RANDOMNESS_SIZE] = PRF(&prf_input);

        let r = sample_from_binomial_distribution::<ETA>(&prf_output);
        re_as_ntt[i] = ntt_binomially_sampled_ring_element(r);
    }
    re_as_ntt
}

fn serialize_key<const K: usize, const OUT_LEN: usize>(
    key: [PolynomialRingElement; K],
) -> [u8; OUT_LEN] {
    let mut out = [0u8; OUT_LEN];

    // for (i, re) in key.into_iter().enumerate() {
    for i in 0..key.len() {
        let re = key[i];
        out[i * BYTES_PER_RING_ELEMENT..(i + 1) * BYTES_PER_RING_ELEMENT]
            .copy_from_slice(&serialize_uncompressed_ring_element(re));
    }

    out
}

#[allow(non_snake_case)]
pub(crate) fn generate_keypair<
    const K: usize,
    const PRIVATE_KEY_SIZE: usize,
    const PUBLIC_KEY_SIZE: usize,
    const RANKED_BYTES_PER_RING_ELEMENT: usize,
    const ETA1: usize,
    const ETA1_RANDOMNESS_SIZE: usize,
>(
    key_generation_seed: &[u8],
) -> (
    (
        PrivateKey<PRIVATE_KEY_SIZE>,
        KyberPublicKey<PUBLIC_KEY_SIZE>,
    ),
    Option<Error>,
) {
    // (ρ,σ) := G(d)
    let hashed = G(key_generation_seed);
    let (seed_for_A, seed_for_secret_and_error) = hashed.split_at(32);

    let (A_transpose, sampling_A_error) = sample_matrix_A(into_padded_array(seed_for_A), true);

    let prf_input: [u8; 33] = into_padded_array(seed_for_secret_and_error);
    let mut domain_separator = [0];
    let secret_as_ntt = sample_vector_cbd_then_ntt::<K, ETA1, ETA1_RANDOMNESS_SIZE>(
        prf_input,
        &mut domain_separator,
    );
    let error_as_ntt = sample_vector_cbd_then_ntt::<K, ETA1, ETA1_RANDOMNESS_SIZE>(
        prf_input,
        &mut domain_separator,
    );

    // tˆ := Aˆ ◦ sˆ + eˆ
    let t_as_ntt = compute_As_plus_e(&A_transpose, &secret_as_ntt, &error_as_ntt);

    // pk := (Encode_12(tˆ mod^{+}q) || ρ)
    let public_key_serialized = UpdatableArray::new([0u8; PUBLIC_KEY_SIZE]);
    let public_key_serialized =
        public_key_serialized.push(&serialize_key::<K, RANKED_BYTES_PER_RING_ELEMENT>(t_as_ntt));
    let public_key_serialized = public_key_serialized.push(seed_for_A).array();

    // sk := Encode_12(sˆ mod^{+}q)
    let secret_key_serialized = serialize_key(secret_as_ntt);

    (
        (secret_key_serialized.into(), public_key_serialized.into()),
        sampling_A_error,
    )
}

fn compress_then_encode_u<
    const K: usize,
    const OUT_LEN: usize,
    const COMPRESSION_FACTOR: usize,
    const BLOCK_LEN: usize,
>(
    input: [PolynomialRingElement; K],
) -> [u8; OUT_LEN] {
    let mut out = [0u8; OUT_LEN];
    // for (i, re) in input.into_iter().enumerate() {
    for i in 0..input.len() {
        let re = input[i];
        out[i * (OUT_LEN / K)..(i + 1) * (OUT_LEN / K)].copy_from_slice(
            &compress_then_serialize_ring_element_u::<COMPRESSION_FACTOR, BLOCK_LEN>(re),
        );
    }

    out
}

#[allow(non_snake_case)]
pub(crate) fn encrypt<
    const K: usize,
    const CIPHERTEXT_SIZE: usize,
    const T_AS_NTT_ENCODED_SIZE: usize,
    const C1_LEN: usize,
    const C2_LEN: usize,
    const U_COMPRESSION_FACTOR: usize,
    const V_COMPRESSION_FACTOR: usize,
    const BLOCK_LEN: usize,
    const ETA1: usize,
    const ETA1_RANDOMNESS_SIZE: usize,
    const ETA2: usize,
    const ETA2_RANDOMNESS_SIZE: usize,
>(
    public_key: &[u8],
    message: [u8; SHARED_SECRET_SIZE],
    randomness: &[u8],
) -> (super::KyberCiphertext<CIPHERTEXT_SIZE>, Option<Error>) {
    // tˆ := Decode_12(pk)
    let mut t_as_ntt = [PolynomialRingElement::ZERO; K];
    // for (i, t_as_ntt_bytes) in public_key[..T_AS_NTT_ENCODED_SIZE]
    //     .chunks_exact(BYTES_PER_RING_ELEMENT)
    //     .enumerate()
    // {
    for i in 0..T_AS_NTT_ENCODED_SIZE / BYTES_PER_RING_ELEMENT {
        let t_as_ntt_bytes = &public_key
            [(i * BYTES_PER_RING_ELEMENT)..(i * BYTES_PER_RING_ELEMENT) + BYTES_PER_RING_ELEMENT];
        t_as_ntt[i] = deserialize_to_uncompressed_ring_element(t_as_ntt_bytes);
    }

    // ρ := pk + 12·k·n / 8
    // for i from 0 to k−1 do
    //     for j from 0 to k − 1 do
    //         AˆT[i][j] := Parse(XOF(ρ, i, j))
    //     end for
    // end for
    let seed = &public_key[T_AS_NTT_ENCODED_SIZE..];
    let (A_transpose, sampling_A_error) = sample_matrix_A(into_padded_array(seed), false);

    // for i from 0 to k−1 do
    //     r[i] := CBD{η1}(PRF(r, N))
    //     N := N + 1
    // end for
    // rˆ := NTT(r)
    let mut prf_input: [u8; 33] = into_padded_array(randomness);
    let mut domain_separator = [0];
    let r_as_ntt = sample_vector_cbd_then_ntt::<K, ETA1, ETA1_RANDOMNESS_SIZE>(
        prf_input,
        &mut domain_separator,
    );

    // for i from 0 to k−1 do
    //     e1[i] := CBD_{η2}(PRF(r,N))
    //     N := N + 1
    // end for
    let mut error_1 = [PolynomialRingElement::ZERO; K];
    for i in 0..K {
        prf_input[32] = domain_separator[0];
        update_domain_separator(&mut domain_separator);

        let prf_output: [u8; ETA2_RANDOMNESS_SIZE] = PRF(&prf_input);
        error_1[i] = sample_from_binomial_distribution::<ETA2>(&prf_output);
    }

    // e_2 := CBD{η2}(PRF(r, N))
    prf_input[32] = domain_separator[0];
    let prf_output: [u8; ETA2_RANDOMNESS_SIZE] = PRF(&prf_input);
    let error_2 = sample_from_binomial_distribution::<ETA2>(&prf_output);

    // u := NTT^{-1}(AˆT ◦ rˆ) + e_1
    let u = compute_vector_u(&A_transpose, &r_as_ntt, &error_1);

    // v := NTT^{−1}(tˆT ◦ rˆ) + e_2 + Decompress_q(Decode_1(m),1)
    let message_as_ring_element = deserialize_then_decompress_message(message);
    let v = compute_ring_element_v(&t_as_ntt, &r_as_ntt, &error_2, &message_as_ring_element);

    // c_1 := Encode_{du}(Compress_q(u,d_u))
    let c1 = compress_then_encode_u::<K, C1_LEN, U_COMPRESSION_FACTOR, BLOCK_LEN>(u);

    // c_2 := Encode_{dv}(Compress_q(v,d_v))
    let c2 = compress_then_serialize_ring_element_v::<V_COMPRESSION_FACTOR, C2_LEN>(v);

    let mut ciphertext: [u8; CIPHERTEXT_SIZE] = into_padded_array(&c1);
    ciphertext[C1_LEN..].copy_from_slice(c2.as_slice());
    (ciphertext.into(), sampling_A_error)
}

#[allow(non_snake_case)]
pub(crate) fn decrypt<
    const K: usize,
    const CIPHERTEXT_SIZE: usize,
    const VECTOR_U_ENCODED_SIZE: usize,
    const U_COMPRESSION_FACTOR: usize,
    const V_COMPRESSION_FACTOR: usize,
>(
    secret_key: &[u8],
    ciphertext: &super::KyberCiphertext<CIPHERTEXT_SIZE>,
) -> [u8; SHARED_SECRET_SIZE] {
    let mut u_as_ntt = [PolynomialRingElement::ZERO; K];
    let mut secret_as_ntt = [PolynomialRingElement::ZERO; K];

    // u := Decompress_q(Decode_{d_u}(c), d_u)
    // for (i, u_bytes) in ciphertext.value[..VECTOR_U_ENCODED_SIZE]
    //     .chunks_exact((COEFFICIENTS_IN_RING_ELEMENT * U_COMPRESSION_FACTOR) / 8)
    //     .enumerate()
    // {
    for i in 0..VECTOR_U_ENCODED_SIZE / ((COEFFICIENTS_IN_RING_ELEMENT * U_COMPRESSION_FACTOR) / 8)
    {
        let cipher_text = &ciphertext.value[0..VECTOR_U_ENCODED_SIZE];
        let u_bytes = &cipher_text[(i * ((COEFFICIENTS_IN_RING_ELEMENT * U_COMPRESSION_FACTOR) / 8))
            ..(i * ((COEFFICIENTS_IN_RING_ELEMENT * U_COMPRESSION_FACTOR) / 8))
                + ((COEFFICIENTS_IN_RING_ELEMENT * U_COMPRESSION_FACTOR) / 8)];
        let u = deserialize_then_decompress_ring_element_u::<U_COMPRESSION_FACTOR>(u_bytes);
        u_as_ntt[i] = ntt_vector_u::<U_COMPRESSION_FACTOR>(u);
    }

    // v := Decompress_q(Decode_{d_v}(c + d_u·k·n / 8), d_v)
    let v = deserialize_then_decompress_ring_element_v::<V_COMPRESSION_FACTOR>(
        &ciphertext.value[VECTOR_U_ENCODED_SIZE..],
    );

    // sˆ := Decode_12(sk)
    // for (i, secret_bytes) in secret_key.chunks_exact(BYTES_PER_RING_ELEMENT).enumerate() {
    for i in 0..secret_key.len() / BYTES_PER_RING_ELEMENT {
        let secret_bytes = &secret_key
            [(i * BYTES_PER_RING_ELEMENT)..(i * BYTES_PER_RING_ELEMENT) + BYTES_PER_RING_ELEMENT];
        secret_as_ntt[i] = deserialize_to_uncompressed_ring_element(secret_bytes);
    }

    // m := Encode_1(Compress_q(v − NTT^{−1}(sˆT ◦ NTT(u)) , 1))
    let message = compute_message(&v, &secret_as_ntt, &u_as_ntt);
    compress_then_serialize_message(message)
}
