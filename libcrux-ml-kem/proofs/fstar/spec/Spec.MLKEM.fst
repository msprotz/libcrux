module Spec.MLKEM
#set-options "--fuel 0 --ifuel 1 --z3rlimit 200"
open FStar.Mul
open Core
open Spec.Utils

(** ML-KEM Constants *)
let v_BITS_PER_COEFFICIENT: usize = sz 12

let v_COEFFICIENTS_IN_RING_ELEMENT: usize = sz 256

let v_BITS_PER_RING_ELEMENT: usize = sz 3072 // v_COEFFICIENTS_IN_RING_ELEMENT *! sz 12

let v_BYTES_PER_RING_ELEMENT: usize = sz 384 // v_BITS_PER_RING_ELEMENT /! sz 8

let v_CPA_PKE_KEY_GENERATION_SEED_SIZE: usize = sz 32

let v_FIELD_MODULUS: i32 = 3329l

let v_H_DIGEST_SIZE: usize = sz 32 
// same as  Libcrux.Digest.digest_size (Libcrux.Digest.Algorithm_Sha3_256_ <: Libcrux.Digest.t_Algorithm)

let v_REJECTION_SAMPLING_SEED_SIZE: usize =  sz 840 // sz 168 *! sz 5

let v_SHARED_SECRET_SIZE: usize = v_H_DIGEST_SIZE

type params_ = {
    v_RANK: usize;
    v_ETA1: usize;
    v_ETA2: usize;
    v_VECTOR_U_COMPRESSION_FACTOR: usize;
    v_VECTOR_V_COMPRESSION_FACTOR: usize;
}

let valid_params p =
  (v p.v_RANK < pow2 32) /\
  (p.v_RANK = sz 2 || p.v_RANK = sz 3 || p.v_RANK = sz 4) /\
  (p.v_ETA1 = sz 2 || p.v_ETA1 = sz 3) /\
  p.v_ETA2 =. sz 2 /\
  (p.v_VECTOR_U_COMPRESSION_FACTOR = sz 10 || p.v_VECTOR_U_COMPRESSION_FACTOR = sz 11) /\
  (p.v_VECTOR_V_COMPRESSION_FACTOR = sz 4 || p.v_VECTOR_V_COMPRESSION_FACTOR = sz 5)

let params = p:params_{valid_params p}

val v_ETA1_RANDOMNESS_SIZE (p:params) : u:usize{u == sz 128 \/ u == sz 192}
let v_ETA1_RANDOMNESS_SIZE (p:params) = p.v_ETA1 *! sz 64

val v_ETA2_RANDOMNESS_SIZE (p:params) : u:usize{u == sz 128}
let v_ETA2_RANDOMNESS_SIZE (p:params) = p.v_ETA2 *! sz 64

val v_RANKED_BYTES_PER_RING_ELEMENT (p:params) : u:usize{u = sz 768 \/ u = sz 1152 \/ u = sz 1536}
let v_RANKED_BYTES_PER_RING_ELEMENT (p:params)  = p.v_RANK *! v_BYTES_PER_RING_ELEMENT

let v_T_AS_NTT_ENCODED_SIZE (p:params) = v_RANKED_BYTES_PER_RING_ELEMENT p
let v_CPA_PKE_SECRET_KEY_SIZE (p:params) = v_RANKED_BYTES_PER_RING_ELEMENT p

val v_CPA_PKE_PUBLIC_KEY_SIZE (p:params) : u:usize{u = sz 800 \/ u = sz 1184 \/ u = sz 1568}
let v_CPA_PKE_PUBLIC_KEY_SIZE (p:params) = v_RANKED_BYTES_PER_RING_ELEMENT p +! sz 32

val v_SECRET_KEY_SIZE (p:params) : u:usize{u = sz 1632 \/ u = sz 2400 \/ u = sz 3168}
let v_SECRET_KEY_SIZE (p:params) =
  (v_CPA_PKE_SECRET_KEY_SIZE p +! v_CPA_PKE_PUBLIC_KEY_SIZE p +! v_H_DIGEST_SIZE +! v_SHARED_SECRET_SIZE)

val v_C1_BLOCK_SIZE (p:params): u:usize{(u = sz 320 \/ u = sz 352) /\ v u == 32 * v p.v_VECTOR_U_COMPRESSION_FACTOR}
let v_C1_BLOCK_SIZE (p:params) = sz 32 *! p.v_VECTOR_U_COMPRESSION_FACTOR

val v_C1_SIZE (p:params) : u:usize{(u >=. sz 640 /\ u <=. sz 1448) /\ 
                                    v u == v (v_C1_BLOCK_SIZE p) * v p.v_RANK}
let v_C1_SIZE (p:params) = v_C1_BLOCK_SIZE p *! p.v_RANK

val v_C2_SIZE (p:params) : u:usize{(u = sz 128 \/ u = sz 160) /\ v u == 32 * v p.v_VECTOR_V_COMPRESSION_FACTOR }
let v_C2_SIZE (p:params) = sz 32 *! p.v_VECTOR_V_COMPRESSION_FACTOR

val v_CPA_PKE_CIPHERTEXT_SIZE (p:params) : u:usize {v u = v (v_C1_SIZE p) + v (v_C2_SIZE p)}
let v_CPA_PKE_CIPHERTEXT_SIZE (p:params) = v_C1_SIZE p +! v_C2_SIZE p

val v_IMPLICIT_REJECTION_HASH_INPUT_SIZE (p:params): u:usize{v u == v v_SHARED_SECRET_SIZE + 
                                                                    v (v_CPA_PKE_CIPHERTEXT_SIZE p)}
let v_IMPLICIT_REJECTION_HASH_INPUT_SIZE (p:params) =
    v_SHARED_SECRET_SIZE +! v_CPA_PKE_CIPHERTEXT_SIZE p

val v_KEY_GENERATION_SEED_SIZE: u:usize{u = sz 64}
let v_KEY_GENERATION_SEED_SIZE: usize =
  v_CPA_PKE_KEY_GENERATION_SEED_SIZE +!
  v_SHARED_SECRET_SIZE

(** ML-KEM Types *)

type t_MLKEMPublicKey (p:params) = t_Array u8 (v_CPA_PKE_PUBLIC_KEY_SIZE p)
type t_MLKEMPrivateKey (p:params) = t_Array u8 (v_SECRET_KEY_SIZE p)
type t_MLKEMKeyPair (p:params) = t_MLKEMPrivateKey p & t_MLKEMPublicKey p

type t_MLKEMCPAPrivateKey (p:params) = t_Array u8 (v_CPA_PKE_SECRET_KEY_SIZE p)
type t_MLKEMCPAKeyPair (p:params) = t_MLKEMCPAPrivateKey p & t_MLKEMPublicKey p

type t_MLKEMCiphertext (p:params) = t_Array u8 (v_CPA_PKE_CIPHERTEXT_SIZE p)
type t_MLKEMSharedSecret = t_Array u8 (v_SHARED_SECRET_SIZE)

(** MLKEM Math and Sampling *)

type field_element = n:nat{n < v v_FIELD_MODULUS}
type polynomial (ntt:bool) = t_Array field_element (sz 256)
type vector (p:params) (ntt:bool) = t_Array (polynomial ntt) p.v_RANK
type matrix (p:params) (ntt:bool) = t_Array (vector p ntt) p.v_RANK

val field_add: field_element -> field_element -> field_element
let field_add a b = (a + b) % v v_FIELD_MODULUS

val field_sub: field_element -> field_element -> field_element
let field_sub a b = (a - b) % v v_FIELD_MODULUS

val field_mul: field_element -> field_element -> field_element
let field_mul a b = (a * b) % v v_FIELD_MODULUS

val poly_add: #ntt:bool -> polynomial ntt -> polynomial ntt -> polynomial ntt
let poly_add a b = map2 field_add a b

val poly_sub: #ntt:bool -> polynomial ntt -> polynomial ntt -> polynomial ntt
let poly_sub a b = map2 field_sub a b

assume val poly_ntt: #p:params -> polynomial false -> polynomial true
assume val poly_inv_ntt: #p:params -> polynomial true -> polynomial false
assume val poly_mul_ntt: polynomial true -> polynomial true -> polynomial true

val vector_add: #p:params -> #ntt:bool -> vector p ntt -> vector p ntt -> vector p ntt
let vector_add #p a b = map2 poly_add a b

val vector_ntt: #p:params -> vector p false -> vector p true
let vector_ntt #p v = map_array (poly_ntt #p) v

val vector_inv_ntt: #p:params -> vector p true -> vector p false
let vector_inv_ntt #p v = map_array (poly_inv_ntt #p) v

val vector_mul_ntt: #p:params -> vector p true  -> vector p true -> vector p true
let vector_mul_ntt #p a b = map2 poly_mul_ntt a b

val vector_sum: #p:params -> #ntt:bool -> vector p ntt -> polynomial ntt
let vector_sum #p a = repeati (v p.v_RANK - 1)
     (fun i x -> poly_add x (Lib.Sequence.index #_ #(v p.v_RANK) a (i+1))) (Lib.Sequence.index #_ #(v p.v_RANK) a 0)

val vector_dot_product_ntt: #p:params -> vector p true -> vector p true -> polynomial true
let vector_dot_product_ntt a b = vector_sum (vector_mul_ntt a b)

val matrix_transpose: #p:params -> #ntt:bool -> matrix p ntt -> matrix p ntt
let matrix_transpose #p m =
  createi p.v_RANK (fun i -> 
    createi p.v_RANK (fun j ->
      m.[j].[i]))

val matrix_vector_mul_ntt: #p:params -> matrix p true -> vector p true -> vector p true
let matrix_vector_mul_ntt #p m v =
  createi p.v_RANK (fun i -> vector_dot_product_ntt m.[i] v)

val compute_As_plus_e_ntt: #p:params -> a:matrix p true -> s:vector p true -> e:vector p true -> vector p true
let compute_As_plus_e_ntt #p a s e = vector_add (matrix_vector_mul_ntt a s) e

let bits_to_bytes (#bytes: usize) (bv: bit_vec (v bytes * 8))
  : Pure (t_Array u8 bytes)
         (requires True)
         (ensures fun r -> (forall i. bit_vec_of_int_t_array r 8 i == bv i))
  = bit_vec_to_int_t_array 8 bv

let bytes_to_bits (#bytes: usize) (r: t_Array u8 bytes)
  : Pure (i: bit_vec (v bytes * 8))
         (requires True)
         (ensures fun f -> (forall i. bit_vec_of_int_t_array r 8 i == f i))
  = bit_vec_of_int_t_array r 8

unfold let retype_bit_vector #a #b (#_:unit{a == b}) (x: a): b = x


// note we take seed of size 32 not 34 as in hacspec
assume val sample_matrix_A_ntt: #p:params -> seed:t_Array u8 (sz 32) -> matrix p true
// note we take seed of size 32 not 33 as in hacspec
assume val sample_vector_cbd: #p:params -> seed:t_Array u8 (sz 32) -> domain_sep:usize -> vector p false
// note we take seed of size 32 not 33 as in hacspec

assume val sample_poly_binomial: v_ETA:usize{v v_ETA <= 3}  -> t_Array u8 (v_ETA *! sz 64) -> polynomial false

open Rust_primitives.Integers

val sample_poly_cbd: #p:params -> seed:t_Array u8 (sz 32) -> domain_sep:usize{v domain_sep < 256} -> polynomial false
let sample_poly_cbd #p seed domain_sep =
  let prf_input = Seq.append seed (Seq.create 1 (mk_int #u8_inttype (v domain_sep))) in
  let prf_output = v_PRF (v_ETA2_RANDOMNESS_SIZE p) prf_input in
  sample_poly_binomial p.v_ETA2 prf_output

let sample_vector_cbd_then_ntt (#p:params) (seed:t_Array u8 (sz 32)) (domain_sep:usize) : vector p true =
    vector_ntt (sample_vector_cbd #p seed domain_sep)

type dT = d: nat {d = 1 \/ d = 4 \/ d = 5 \/ d = 10 \/ d = 11 \/ d = 12}
let max_d (d:dT) = if d < 12 then pow2 d else v v_FIELD_MODULUS
type field_element_d (d:dT) = n:nat{n < max_d d}
type polynomial_d (d:dT) = t_Array (field_element_d d) (sz 256)
type vector_d (p:params) (d:dT) = t_Array (polynomial_d d) p.v_RANK


let compress_d (d: dT {d <> 12}) (x: field_element): field_element_d d
  = let r = (pow2 d * x + 1664) / v v_FIELD_MODULUS in
    assume (r * v v_FIELD_MODULUS < pow2 d * x + 1664);
    assume (pow2 d * x + 1664 < pow2 d * v v_FIELD_MODULUS + 1664);
    assume (r < pow2 d);
    r

let decompress_d (d: dT {d <> 12}) (x: field_element_d d): field_element
  = let r = (x * v v_FIELD_MODULUS + 1664) / pow2 d in
    assume (r < v v_FIELD_MODULUS);
    r
    

let byte_encode (d: dT) (coefficients: polynomial_d d): t_Array u8 (sz (32 * d))
  =  let coefficients' : t_Array nat (sz 256) = map_array #(field_element_d d) (fun x -> x <: nat) coefficients in
     bits_to_bytes #(sz (32 * d))
       (retype_bit_vector (bit_vec_of_nat_array coefficients' d))

let byte_decode (d: dT) (coefficients: t_Array u8 (sz (32 * d))): polynomial_d d
  = let bv = bytes_to_bits coefficients in
    let arr: t_Array nat (sz 256) = bit_vec_to_nat_array d (retype_bit_vector bv) in
    let p = map_array (fun (x: nat) -> x % v v_FIELD_MODULUS) arr in
    introduce forall i. (d < 12 ==> Seq.index p i < pow2 d)
    with assert (Seq.index p i == Seq.index p (v (sz i)));
    introduce forall i. (d == 12 ==> Seq.index p i < v v_FIELD_MODULUS)
    with assert (Seq.index p i == Seq.index p (v (sz i)));
    assert (forall i. (d < 12 ==> Seq.index p i < pow2 d) /\ (d == 12 ==> Seq.index p i < v v_FIELD_MODULUS));
    admit();
    p

let coerce_polynomial_12 #ntt (p:polynomial ntt): polynomial_d 12 = p
let coerce_vector_12 #ntt (#p:params) (v:vector p ntt): vector_d p 12 = v

let vector_encode_12 (#p:params) (#ntt:bool) (v: vector p ntt): t_Array u8 (v_T_AS_NTT_ENCODED_SIZE p)
  = let s: t_Array (t_Array _ (sz 384)) p.v_RANK = map_array (byte_encode 12) (coerce_vector_12 v) in
    flatten s

let vector_decode_12 (#p:params) (#ntt:bool) (arr: t_Array u8 (v_T_AS_NTT_ENCODED_SIZE p)): vector p ntt
  = createi p.v_RANK (fun block -> 
      let block_size = (sz (32 * 12)) in
      let slice = Seq.slice arr (v block * v block_size) 
                                (v block * v block_size + v block_size) in
      byte_decode 12 slice
    )

let compress_then_byte_encode #ntt (d: dT {d <> 12}) (coefficients: polynomial ntt): t_Array u8 (sz (32 * d))
  = let coefs: t_Array (field_element_d d) (sz 256) = map_array (compress_d d) coefficients
    in
    byte_encode d coefs

let byte_decode_then_decompress #ntt (d: dT {d <> 12}) (b:t_Array u8 (sz (32 * d))): polynomial ntt
  = map_array (decompress_d d) (byte_decode d b)

let compress_then_encode_message #ntt (p:polynomial ntt) : t_Array u8 v_SHARED_SECRET_SIZE
  = compress_then_byte_encode 1 p

let decode_then_decompress_message #ntt (b:t_Array u8 v_SHARED_SECRET_SIZE): polynomial ntt
  = byte_decode_then_decompress 1 b

let compress_then_encode_u (#p:params) (#ntt:bool) (vec: vector p ntt): t_Array u8 (v_C1_SIZE p)
  = let d = v p.v_VECTOR_U_COMPRESSION_FACTOR in
    flatten (map_array (compress_then_byte_encode d) vec)

let decode_then_decompress_u (#p:params) (#ntt:bool) (arr: t_Array u8 (v_C1_SIZE p)): vector p ntt
  = let d = p.v_VECTOR_U_COMPRESSION_FACTOR in
    createi p.v_RANK (fun block -> 
      let block_size = v_C1_BLOCK_SIZE p in
      let slice = Seq.slice arr (v block * v block_size) 
                                (v block * v block_size + v block_size) in
      byte_decode_then_decompress (v d) slice
    )

let compress_then_encode_v (#p:params) (#ntt:bool): polynomial ntt -> t_Array u8 (v_C2_SIZE p)
  = compress_then_byte_encode (v p.v_VECTOR_V_COMPRESSION_FACTOR)

let decode_then_decompress_v (#p:params) (#ntt:bool): t_Array u8 (v_C2_SIZE p) -> polynomial ntt
  = byte_decode_then_decompress (v p.v_VECTOR_V_COMPRESSION_FACTOR)

(** IND-CPA Functions *)

/// This function implements most of <strong>Algorithm 12</strong> of the
/// NIST FIPS 203 specification; this is the MLKEM CPA-PKE key generation algorithm.
///
/// We say "most of" since Algorithm 12 samples the required randomness within
/// the function itself, whereas this implementation expects it to be provided
/// through the `key_generation_seed` parameter.

val ind_cpa_generate_keypair (p:params) (randomness:t_Array u8 v_CPA_PKE_KEY_GENERATION_SEED_SIZE) :
                             t_MLKEMCPAKeyPair p
let ind_cpa_generate_keypair p randomness =
    let hashed = v_G randomness in
    let (seed_for_A, seed_for_secret_and_error) = split hashed (sz 32) in
    let matrix_A_as_ntt = sample_matrix_A_ntt #p seed_for_A in
    let secret_as_ntt = sample_vector_cbd_then_ntt #p seed_for_secret_and_error (sz 0) in
    let error_as_ntt = sample_vector_cbd_then_ntt #p seed_for_secret_and_error p.v_RANK in
    let t_as_ntt = compute_As_plus_e_ntt #p matrix_A_as_ntt secret_as_ntt error_as_ntt in
    let public_key_serialized = Seq.append (vector_encode_12 #p t_as_ntt) seed_for_A in
    let secret_key_serialized = vector_encode_12 #p secret_as_ntt in
    (secret_key_serialized,public_key_serialized)

/// This function implements <strong>Algorithm 13</strong> of the
/// NIST FIPS 203 specification; this is the MLKEM CPA-PKE encryption algorithm.

val ind_cpa_encrypt (p:params) (public_key: t_MLKEMPublicKey p)
                    (message: t_Array u8 v_SHARED_SECRET_SIZE)
                    (randomness:t_Array u8 v_SHARED_SECRET_SIZE) :
                    t_MLKEMCiphertext p

let ind_cpa_encrypt p public_key message randomness =
    let (t_as_ntt_bytes, seed_for_A) = split public_key (v_T_AS_NTT_ENCODED_SIZE p) in
    let t_as_ntt = vector_decode_12 #p t_as_ntt_bytes in 
    let matrix_A_as_ntt = sample_matrix_A_ntt #p seed_for_A in
    let r_as_ntt = sample_vector_cbd_then_ntt #p randomness (sz 0) in
    let error_1 = sample_vector_cbd #p randomness p.v_RANK in
    let error_2 = sample_poly_cbd #p randomness (p.v_RANK +! p.v_RANK) in
    let u = vector_add (vector_inv_ntt (matrix_vector_mul_ntt (matrix_transpose matrix_A_as_ntt) r_as_ntt)) error_1 in
    let mu = decode_then_decompress_message message in
    let v = poly_add (poly_add (vector_dot_product_ntt t_as_ntt r_as_ntt) error_2) mu in  
    let c1 = compress_then_encode_u #p u in
    let c2 = compress_then_encode_v #p v in
    concat c1 c2

/// This function implements <strong>Algorithm 14</strong> of the
/// NIST FIPS 203 specification; this is the MLKEM CPA-PKE decryption algorithm.

val ind_cpa_decrypt (p:params) (secret_key: t_MLKEMCPAPrivateKey p)
                    (ciphertext: t_MLKEMCiphertext p): 
                    t_MLKEMSharedSecret

let ind_cpa_decrypt p secret_key ciphertext =
    let (c1,c2) = split ciphertext (v_C1_SIZE p) in
    let u = decode_then_decompress_u #p c1 in
    let v = decode_then_decompress_v #p c2 in
    let secret_as_ntt = vector_decode_12 #p secret_key in
    let w = poly_sub v (poly_inv_ntt #p (vector_dot_product_ntt secret_as_ntt (vector_ntt u))) in
    compress_then_encode_message w

(** IND-CCA Functions *)


/// This function implements most of Algorithm 15 of the
/// NIST FIPS 203 specification; this is the MLKEM CCA-KEM key generation algorithm.
///
/// We say "most of" since Algorithm 15 samples the required randomness within
/// the function itself, whereas this implementation expects it to be provided
/// through the `randomness` parameter.
/// 
/// TODO: input validation

val ind_cca_generate_keypair (p:params) (randomness:t_Array u8 v_KEY_GENERATION_SEED_SIZE) :
                             t_MLKEMKeyPair p
let ind_cca_generate_keypair p randomness =
    let (ind_cpa_keypair_randomness, implicit_rejection_value) =
        split randomness v_CPA_PKE_KEY_GENERATION_SEED_SIZE in
        
    let (ind_cpa_secret_key,ind_cpa_public_key) = ind_cpa_generate_keypair p ind_cpa_keypair_randomness in
    let ind_cca_secret_key = Seq.append ind_cpa_secret_key (
                             Seq.append ind_cpa_public_key (
                             Seq.append (v_H ind_cpa_public_key) implicit_rejection_value)) in
    (ind_cca_secret_key, ind_cpa_public_key)

/// This function implements most of Algorithm 16 of the
/// NIST FIPS 203 specification; this is the MLKEM CCA-KEM encapsulation algorithm.
///
/// We say "most of" since Algorithm 16 samples the required randomness within
/// the function itself, whereas this implementation expects it to be provided
/// through the `randomness` parameter.
///
/// TODO: input validation

val ind_cca_encapsulate (p:params) (public_key: t_MLKEMPublicKey p)
                        (randomness:t_Array u8 v_SHARED_SECRET_SIZE) :
                        (t_MLKEMCiphertext p &  t_MLKEMSharedSecret)
let ind_cca_encapsulate p public_key randomness =
    let to_hash = concat randomness (v_H public_key) in
    let hashed = v_G to_hash in
    let (shared_secret, pseudorandomness) = split hashed v_SHARED_SECRET_SIZE in
    let ciphertext = ind_cpa_encrypt p public_key randomness pseudorandomness in
    (ciphertext,shared_secret)
    

/// This function implements Algorithm 17 of the
/// NIST FIPS 203 specification; this is the MLKEM CCA-KEM encapsulation algorithm.

val ind_cca_decapsulate (p:params) (secret_key: t_MLKEMPrivateKey p)
                        (ciphertext: t_MLKEMCiphertext p): 
                         t_MLKEMSharedSecret
let ind_cca_decapsulate p secret_key ciphertext =
    let (ind_cpa_secret_key,rest) = split secret_key (v_CPA_PKE_SECRET_KEY_SIZE p) in
    let (ind_cpa_public_key,rest) = split rest (v_CPA_PKE_PUBLIC_KEY_SIZE p) in
    let (ind_cpa_public_key_hash,implicit_rejection_value) = split rest v_H_DIGEST_SIZE in
    
    let decrypted = ind_cpa_decrypt p ind_cpa_secret_key ciphertext in
    let to_hash = concat decrypted ind_cpa_public_key_hash in
    let hashed = v_G to_hash in
    let (success_shared_secret, pseudorandomness) = split hashed v_SHARED_SECRET_SIZE in

    assert (Seq.length implicit_rejection_value = 32);
    let to_hash = concat implicit_rejection_value ciphertext in
    let rejection_shared_secret = v_J to_hash in

    let reencrypted = ind_cpa_encrypt p ind_cpa_public_key decrypted pseudorandomness in
    if reencrypted = ciphertext
    then success_shared_secret
    else rejection_shared_secret
   

(** MLKEM-768 Instantiation *)

let mlkem768_params : params = {
    v_RANK = sz 3;
    v_ETA1 = sz 2;
    v_ETA2 = sz 2;
    v_VECTOR_U_COMPRESSION_FACTOR = sz 10;
    v_VECTOR_V_COMPRESSION_FACTOR = sz 4;
}

let mlkem768_generate_keypair (randomness:t_Array u8 (sz 64)):
                              (t_Array u8 (sz 2400) & t_Array u8 (sz 1184)) =
    ind_cca_generate_keypair mlkem768_params randomness

let mlkem768_encapsulate (public_key: t_Array u8 (sz 1184)) (randomness: t_Array u8 (sz 32)):
                         (t_Array u8 (sz 1088) & t_Array u8 (sz 32)) =
    ind_cca_encapsulate mlkem768_params public_key randomness


let mlkem768_decapsulate (secret_key: t_Array u8 (sz 2400)) (ciphertext: t_Array u8 (sz 1088)):
                         t_Array u8 (sz 32) =
    ind_cca_decapsulate mlkem768_params secret_key ciphertext

(** MLKEM-1024 Instantiation *)

let mlkem1024_params : params = {
    v_RANK = sz 4;
    v_ETA1 = sz 2;
    v_ETA2 = sz 2;
    v_VECTOR_U_COMPRESSION_FACTOR = sz 11;
    v_VECTOR_V_COMPRESSION_FACTOR = sz 5;
}

let mlkem1024_generate_keypair (randomness:t_Array u8 (sz 64)):
                               (t_Array u8 (sz 3168) & t_Array u8 (sz 1568)) =
    ind_cca_generate_keypair mlkem1024_params randomness

let mlkem1024_encapsulate (public_key: t_Array u8 (sz 1568)) (randomness: t_Array u8 (sz 32)):
                          (t_Array u8 (sz 1568) & t_Array u8 (sz 32)) =
    ind_cca_encapsulate mlkem1024_params public_key randomness


let mlkem1024_decapsulate (secret_key: t_Array u8 (sz 3168)) (ciphertext: t_Array u8 (sz 1568)):
                           t_Array u8 (sz 32) =
    ind_cca_decapsulate mlkem1024_params secret_key ciphertext

(** MLKEM-512 Instantiation *)

let mlkem512_params : params = {
    v_RANK = sz 2;
    v_ETA1 = sz 3;
    v_ETA2 = sz 2;
    v_VECTOR_U_COMPRESSION_FACTOR = sz 10;
    v_VECTOR_V_COMPRESSION_FACTOR = sz 4;
}

let mlkem512_generate_keypair (randomness:t_Array u8 (sz 64)):
                              (t_Array u8 (sz 1632) & t_Array u8 (sz 800))  =
    ind_cca_generate_keypair mlkem512_params randomness

let mlkem512_encapsulate (public_key: t_Array u8 (sz 800)) (randomness: t_Array u8 (sz 32)):
                         (t_Array u8 (sz 768) & t_Array u8 (sz 32)) =
    ind_cca_encapsulate mlkem512_params public_key randomness


let mlkem512_decapsulate (secret_key: t_Array u8 (sz 1632)) (ciphertext: t_Array u8 (sz 768)):
                         t_Array u8 (sz 32) =
    ind_cca_decapsulate mlkem512_params secret_key ciphertext
