use crate::{
    constants::{COEFFICIENTS_IN_RING_ELEMENT, FIELD_MODULUS},
    hash_functions::*,
    hax_utils::hax_debug_assert,
    helper::cloop,
    polynomial::{from_i16_array, PolynomialRingElement},
    simd::{simd_trait::*,Vector}
};

/// If `bytes` contains a set of uniformly random bytes, this function
/// uniformly samples a ring element `â` that is treated as being the NTT representation
/// of the corresponding polynomial `a`.
///
/// Since rejection sampling is used, it is possible the supplied bytes are
/// not enough to sample the element, in which case an `Err` is returned and the
/// caller must try again with a fresh set of bytes.
///
/// This function <strong>partially</strong> implements <strong>Algorithm 6</strong> of the NIST FIPS 203 standard,
/// We say "partially" because this implementation only accepts a finite set of
/// bytes as input and returns an error if the set is not enough; Algorithm 6 of
/// the FIPS 203 standard on the other hand samples from an infinite stream of bytes
/// until the ring element is filled. Algorithm 6 is reproduced below:
///
/// ```plaintext
/// Input: byte stream B ∈ 𝔹*.
/// Output: array â ∈ ℤ₂₅₆.
///
/// i ← 0
/// j ← 0
/// while j < 256 do
///     d₁ ← B[i] + 256·(B[i+1] mod 16)
///     d₂ ← ⌊B[i+1]/16⌋ + 16·B[i+2]
///     if d₁ < q then
///         â[j] ← d₁
///         j ← j + 1
///     end if
///     if d₂ < q and j < 256 then
///         â[j] ← d₂
///         j ← j + 1
///     end if
///     i ← i + 3
/// end while
/// return â
/// ```
///
/// The NIST FIPS 203 standard can be found at
/// <https://csrc.nist.gov/pubs/fips/203/ipd>.
fn sample_from_uniform_distribution_next<const K: usize, const N: usize>(
    randomness: [[u8; N]; K],
    sampled_coefficients: &mut [usize; K],
    out: &mut [[i16; 256]; K],
) -> bool {
    for r in 0..N/12 {
        for i in 0..K {
            if sampled_coefficients[i] < COEFFICIENTS_IN_RING_ELEMENT {
                let (sampled,vec) = Vector::rej_sample(&randomness[i][r*12..r*12+12]);
                let pick = core::cmp::min(COEFFICIENTS_IN_RING_ELEMENT-sampled_coefficients[i],sampled);
                out[i][sampled_coefficients[i]..sampled_coefficients[i]+pick].copy_from_slice(&vec[0..pick]);
                sampled_coefficients[i] += pick;
            }
        }
    }
    let mut done = true;
    for i in 0..K {
        if sampled_coefficients[i] < COEFFICIENTS_IN_RING_ELEMENT {done = false}
    }
    done
}

pub(super) fn sample_from_xof<const K: usize>(seeds: [[u8; 34]; K]) -> [PolynomialRingElement; K] {
    let mut sampled_coefficients: [usize; K] = [0; K];
    let mut out: [[i16; 256]; K] = [[0; 256]; K];

    let mut xof_state = absorb(seeds);
    let randomness = squeeze_three_blocks(&mut xof_state);

    let mut done =
        sample_from_uniform_distribution_next(randomness, &mut sampled_coefficients, &mut out);

    // Requiring more than 5 blocks to sample a ring element should be very
    // unlikely according to:
    // https://eprint.iacr.org/2023/708.pdf
    // To avoid failing here, we squeeze more blocks out of the state until
    // we have enough.
    while !done {
        let randomness = squeeze_block(&mut xof_state);
        done =
            sample_from_uniform_distribution_next(randomness, &mut sampled_coefficients, &mut out);
    }
    // XXX: We have to manually free the state here due to a Eurydice issue.
    free_state(xof_state);

    out.map(from_i16_array)
}

/// Given a series of uniformly random bytes in `randomness`, for some number `eta`,
/// the `sample_from_binomial_distribution_{eta}` functions sample
/// a ring element from a binomial distribution centered at 0 that uses two sets
/// of `eta` coin flips. If, for example,
/// `eta = ETA`, each ring coefficient is a value `v` such
/// such that `v ∈ {-ETA, -ETA + 1, ..., 0, ..., ETA + 1, ETA}` and:
///
/// ```plaintext
/// - If v < 0, Pr[v] = Pr[-v]
/// - If v >= 0, Pr[v] = BINOMIAL_COEFFICIENT(2 * ETA; ETA - v) / 2 ^ (2 * ETA)
/// ```
///
/// The values `v < 0` are mapped to the appropriate `KyberFieldElement`.
///
/// The expected value is:
///
/// ```plaintext
/// E[X] = (-ETA)Pr[-ETA] + (-(ETA - 1))Pr[-(ETA - 1)] + ... + (ETA - 1)Pr[ETA - 1] + (ETA)Pr[ETA]
///      = 0 since Pr[-v] = Pr[v] when v < 0.
/// ```
///
/// And the variance is:
///
/// ```plaintext
/// Var(X) = E[(X - E[X])^2]
///        = E[X^2]
///        = sum_(v=-ETA to ETA)v^2 * (BINOMIAL_COEFFICIENT(2 * ETA; ETA - v) / 2^(2 * ETA))
///        = ETA / 2
/// ```
///
/// This function implements <strong>Algorithm 7</strong> of the NIST FIPS 203 standard, which is
/// reproduced below:
///
/// ```plaintext
/// Input: byte array B ∈ 𝔹^{64η}.
/// Output: array f ∈ ℤ₂₅₆.
///
/// b ← BytesToBits(B)
/// for (i ← 0; i < 256; i++)
///     x ← ∑(j=0 to η - 1) b[2iη + j]
///     y ← ∑(j=0 to η - 1) b[2iη + η + j]
///     f[i] ← x−y mod q
/// end for
/// return f
/// ```
///
/// The NIST FIPS 203 standard can be found at
/// <https://csrc.nist.gov/pubs/fips/203/ipd>.
#[cfg_attr(hax, hax_lib::requires(randomness.len() == 2 * 64))]
// TODO: Remove or replace with something that works and is useful for the proof.
// #[cfg_attr(hax, hax_lib::ensures(|result|
//     hax_lib::forall(|i:usize|
//         hax_lib::implies(i < result.coefficients.len(), || result.coefficients[i].abs() <= 2
// ))))]
fn sample_from_binomial_distribution_2(randomness: &[u8]) -> PolynomialRingElement {
    let mut sampled_i16s = [0i16; 256];

    cloop! {
        for (chunk_number, byte_chunk) in randomness.chunks_exact(4).enumerate() {
            let random_bits_as_u32: u32 = (byte_chunk[0] as u32)
                | (byte_chunk[1] as u32) << 8
                | (byte_chunk[2] as u32) << 16
                | (byte_chunk[3] as u32) << 24;

            let even_bits = random_bits_as_u32 & 0x55555555;
            let odd_bits = (random_bits_as_u32 >> 1) & 0x55555555;
            let coin_toss_outcomes = even_bits + odd_bits;

            cloop! {
                for outcome_set in (0..u32::BITS).step_by(4) {
                    let outcome_1 = ((coin_toss_outcomes >> outcome_set) & 0x3) as i16;
                    let outcome_2 = ((coin_toss_outcomes >> (outcome_set + 2)) & 0x3) as i16;

                    let offset = (outcome_set >> 2) as usize;
                    sampled_i16s[8 * chunk_number + offset] = outcome_1 - outcome_2;
                }
            }
        }
    }
    from_i16_array(sampled_i16s)
}

#[cfg_attr(hax, hax_lib::requires(randomness.len() == 3 * 64))]
// TODO: Remove or replace with something that works and is useful for the proof.
// #[cfg_attr(hax, hax_lib::ensures(|result|
//     hax_lib::forall(|i:usize|
//         hax_lib::implies(i < result.coefficients.len(), || result.coefficients[i].abs() <= 3
// ))))]
fn sample_from_binomial_distribution_3(randomness: &[u8]) -> PolynomialRingElement {
    let mut sampled_i16s = [0i16; 256];

    cloop! {
        for (chunk_number, byte_chunk) in randomness.chunks_exact(3).enumerate() {
            let random_bits_as_u24: u32 =
                (byte_chunk[0] as u32) | (byte_chunk[1] as u32) << 8 | (byte_chunk[2] as u32) << 16;

            let first_bits = random_bits_as_u24 & 0x00249249;
            let second_bits = (random_bits_as_u24 >> 1) & 0x00249249;
            let third_bits = (random_bits_as_u24 >> 2) & 0x00249249;

            let coin_toss_outcomes = first_bits + second_bits + third_bits;

            cloop! {
                for outcome_set in (0..24).step_by(6) {
                    let outcome_1 = ((coin_toss_outcomes >> outcome_set) & 0x7) as i16;
                    let outcome_2 = ((coin_toss_outcomes >> (outcome_set + 3)) & 0x7) as i16;

                    let offset = (outcome_set / 6) as usize;
                    sampled_i16s[4 * chunk_number + offset] = outcome_1 - outcome_2;
                }
            }
        }
    }
    from_i16_array(sampled_i16s)
}

#[inline(always)]
pub(super) fn sample_from_binomial_distribution<const ETA: usize>(
    randomness: &[u8],
) -> PolynomialRingElement {
    hax_debug_assert!(randomness.len() == ETA * 64);

    match ETA as u32 {
        2 => sample_from_binomial_distribution_2(randomness),
        3 => sample_from_binomial_distribution_3(randomness),
        _ => unreachable!(),
    }
}
