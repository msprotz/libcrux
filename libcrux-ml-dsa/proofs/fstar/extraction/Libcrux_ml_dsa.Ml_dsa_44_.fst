module Libcrux_ml_dsa.Ml_dsa_44_
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

let v_BITS_PER_COMMITMENT_COEFFICIENT: usize = Rust_primitives.mk_usize 6

let v_BITS_PER_ERROR_COEFFICIENT: usize = Rust_primitives.mk_usize 3

let v_BITS_PER_GAMMA1_COEFFICIENT: usize = Rust_primitives.mk_usize 18

let v_COLUMNS_IN_A: usize = Rust_primitives.mk_usize 4

let v_COMMITMENT_HASH_SIZE: usize = Rust_primitives.mk_usize 32

let v_COMMITMENT_RING_ELEMENT_SIZE: usize =
  (v_BITS_PER_COMMITMENT_COEFFICIENT *! Libcrux_ml_dsa.Constants.v_COEFFICIENTS_IN_RING_ELEMENT
    <:
    usize) /!
  Rust_primitives.mk_usize 8

let v_ERROR_RING_ELEMENT_SIZE: usize =
  (v_BITS_PER_ERROR_COEFFICIENT *! Libcrux_ml_dsa.Constants.v_COEFFICIENTS_IN_RING_ELEMENT <: usize) /!
  Rust_primitives.mk_usize 8

let v_ETA: usize = Rust_primitives.mk_usize 2

let v_GAMMA1_EXPONENT: usize = Rust_primitives.mk_usize 17

let v_GAMMA1_RING_ELEMENT_SIZE: usize =
  (v_BITS_PER_GAMMA1_COEFFICIENT *! Libcrux_ml_dsa.Constants.v_COEFFICIENTS_IN_RING_ELEMENT <: usize
  ) /!
  Rust_primitives.mk_usize 8

let v_GAMMA2: i32 =
  (Libcrux_ml_dsa.Constants.v_FIELD_MODULUS -! Rust_primitives.mk_i32 1 <: i32) /!
  Rust_primitives.mk_i32 88

let v_MAX_ONES_IN_HINT: usize = Rust_primitives.mk_usize 80

let v_ONES_IN_VERIFIER_CHALLENGE: usize = Rust_primitives.mk_usize 39

let v_BETA: i32 = cast (v_ONES_IN_VERIFIER_CHALLENGE *! v_ETA <: usize) <: i32

let v_ROWS_IN_A: usize = Rust_primitives.mk_usize 4

let v_COMMITMENT_VECTOR_SIZE: usize = v_COMMITMENT_RING_ELEMENT_SIZE *! v_ROWS_IN_A

let v_SIGNATURE_SIZE: usize =
  ((v_COMMITMENT_HASH_SIZE +! (v_COLUMNS_IN_A *! v_GAMMA1_RING_ELEMENT_SIZE <: usize) <: usize) +!
    v_MAX_ONES_IN_HINT
    <:
    usize) +!
  v_ROWS_IN_A

let v_SIGNING_KEY_SIZE: usize =
  (((Libcrux_ml_dsa.Constants.v_SEED_FOR_A_SIZE +! Libcrux_ml_dsa.Constants.v_SEED_FOR_SIGNING_SIZE
        <:
        usize) +!
      Libcrux_ml_dsa.Constants.v_BYTES_FOR_VERIFICATION_KEY_HASH
      <:
      usize) +!
    ((v_ROWS_IN_A +! v_COLUMNS_IN_A <: usize) *! v_ERROR_RING_ELEMENT_SIZE <: usize)
    <:
    usize) +!
  (v_ROWS_IN_A *! Libcrux_ml_dsa.Constants.v_RING_ELEMENT_OF_T0S_SIZE <: usize)

let v_VERIFICATION_KEY_SIZE: usize =
  Libcrux_ml_dsa.Constants.v_SEED_FOR_A_SIZE +!
  (((Libcrux_ml_dsa.Constants.v_COEFFICIENTS_IN_RING_ELEMENT *! v_ROWS_IN_A <: usize) *!
      (Libcrux_ml_dsa.Constants.v_FIELD_MODULUS_MINUS_ONE_BIT_LENGTH -!
        Libcrux_ml_dsa.Constants.v_BITS_IN_LOWER_PART_OF_T
        <:
        usize)
      <:
      usize) /!
    Rust_primitives.mk_usize 8
    <:
    usize)

/// Sign with ML-DSA 44
/// Sign a `message` with the ML-DSA `signing_key`.
/// The parameter `context` is used for domain separation
/// and is a byte string of length at most 255 bytes. It
/// may also be empty.
/// This function returns an [`MLDSA44Signature`].
let sign
      (signing_key: Libcrux_ml_dsa.Types.t_MLDSASigningKey (Rust_primitives.mk_usize 2560))
      (message context: t_Slice u8)
      (randomness: t_Array u8 (Rust_primitives.mk_usize 32))
    : Core.Result.t_Result (Libcrux_ml_dsa.Types.t_MLDSASignature (Rust_primitives.mk_usize 2420))
      Libcrux_ml_dsa.Ml_dsa_generic.t_SigningError =
  Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.sign (Rust_primitives.mk_usize 4)
    (Rust_primitives.mk_usize 4) (Rust_primitives.mk_usize 2) (Rust_primitives.mk_usize 96)
    (Rust_primitives.mk_usize 17) (Rust_primitives.mk_i32 95232) (Rust_primitives.mk_usize 192)
    (Rust_primitives.mk_usize 768) (Rust_primitives.mk_usize 32) (Rust_primitives.mk_usize 39)
    (Rust_primitives.mk_usize 80) (Rust_primitives.mk_usize 576) (Rust_primitives.mk_usize 2560)
    (Rust_primitives.mk_usize 2420) signing_key.Libcrux_ml_dsa.Types._0 message context randomness

/// Sign with HashML-DSA 44, with a SHAKE128 pre-hashing
/// Sign a digest of `message` derived using `pre_hash` with the
/// ML-DSA `signing_key`.
/// The parameter `context` is used for domain separation
/// and is a byte string of length at most 255 bytes. It
/// may also be empty.
/// This function returns an [`MLDSA44Signature`].
let sign_pre_hashed_shake128
      (signing_key: Libcrux_ml_dsa.Types.t_MLDSASigningKey (Rust_primitives.mk_usize 2560))
      (message context: t_Slice u8)
      (randomness: t_Array u8 (Rust_primitives.mk_usize 32))
    : Core.Result.t_Result (Libcrux_ml_dsa.Types.t_MLDSASignature (Rust_primitives.mk_usize 2420))
      Libcrux_ml_dsa.Ml_dsa_generic.t_SigningError =
  Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.sign_pre_hashed_shake128 (Rust_primitives.mk_usize 4)
    (Rust_primitives.mk_usize 4) (Rust_primitives.mk_usize 2) (Rust_primitives.mk_usize 96)
    (Rust_primitives.mk_usize 17) (Rust_primitives.mk_i32 95232) (Rust_primitives.mk_usize 192)
    (Rust_primitives.mk_usize 768) (Rust_primitives.mk_usize 32) (Rust_primitives.mk_usize 39)
    (Rust_primitives.mk_usize 80) (Rust_primitives.mk_usize 576) (Rust_primitives.mk_usize 2560)
    (Rust_primitives.mk_usize 2420) signing_key.Libcrux_ml_dsa.Types._0 message context randomness

/// Verify an ML-DSA-44 Signature
/// The parameter `context` is used for domain separation
/// and is a byte string of length at most 255 bytes. It
/// may also be empty.
/// Returns `Ok` when the `signature` is valid for the `message` and
/// `verification_key`, and a [`VerificationError`] otherwise.
let verify
      (verification_key:
          Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (Rust_primitives.mk_usize 1312))
      (message context: t_Slice u8)
      (signature: Libcrux_ml_dsa.Types.t_MLDSASignature (Rust_primitives.mk_usize 2420))
    : Core.Result.t_Result Prims.unit Libcrux_ml_dsa.Ml_dsa_generic.t_VerificationError =
  Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.verify (Rust_primitives.mk_usize 4)
    (Rust_primitives.mk_usize 4) (Rust_primitives.mk_usize 2420) (Rust_primitives.mk_usize 1312)
    (Rust_primitives.mk_usize 17) (Rust_primitives.mk_usize 576) (Rust_primitives.mk_i32 95232)
    (Rust_primitives.mk_i32 78) (Rust_primitives.mk_usize 192) (Rust_primitives.mk_usize 768)
    (Rust_primitives.mk_usize 32) (Rust_primitives.mk_usize 39) (Rust_primitives.mk_usize 80)
    verification_key.Libcrux_ml_dsa.Types._0 message context signature.Libcrux_ml_dsa.Types._0

/// Verify a HashML-DSA-44 Signature, with a SHAKE128 pre-hashing
/// The parameter `context` is used for domain separation
/// and is a byte string of length at most 255 bytes. It
/// may also be empty.
/// Returns `Ok` when the `signature` is valid for the `message` and
/// `verification_key`, and a [`VerificationError`] otherwise.
let verify_pre_hashed_shake128
      (verification_key:
          Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (Rust_primitives.mk_usize 1312))
      (message context: t_Slice u8)
      (signature: Libcrux_ml_dsa.Types.t_MLDSASignature (Rust_primitives.mk_usize 2420))
    : Core.Result.t_Result Prims.unit Libcrux_ml_dsa.Ml_dsa_generic.t_VerificationError =
  Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.verify_pre_hashed_shake128 (Rust_primitives.mk_usize 4)
    (Rust_primitives.mk_usize 4) (Rust_primitives.mk_usize 2420) (Rust_primitives.mk_usize 1312)
    (Rust_primitives.mk_usize 17) (Rust_primitives.mk_usize 576) (Rust_primitives.mk_i32 95232)
    (Rust_primitives.mk_i32 78) (Rust_primitives.mk_usize 192) (Rust_primitives.mk_usize 768)
    (Rust_primitives.mk_usize 32) (Rust_primitives.mk_usize 39) (Rust_primitives.mk_usize 80)
    verification_key.Libcrux_ml_dsa.Types._0 message context signature.Libcrux_ml_dsa.Types._0

/// Generate an ML-DSA 44 Key Pair
/// Generate an ML-DSA key pair. The input is a byte array of size
/// [`KEY_GENERATION_RANDOMNESS_SIZE`].
/// This function returns an [`MLDSA44KeyPair`].
let generate_key_pair (randomness: t_Array u8 (Rust_primitives.mk_usize 32))
    : Libcrux_ml_dsa.Types.t_MLDSAKeyPair (Rust_primitives.mk_usize 1312)
      (Rust_primitives.mk_usize 2560) =
  let signing_key, verification_key:(t_Array u8 (Rust_primitives.mk_usize 2560) &
    t_Array u8 (Rust_primitives.mk_usize 1312)) =
    Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.generate_key_pair (Rust_primitives.mk_usize 4)
      (Rust_primitives.mk_usize 4)
      (Rust_primitives.mk_usize 2)
      (Rust_primitives.mk_usize 96)
      (Rust_primitives.mk_usize 2560)
      (Rust_primitives.mk_usize 1312)
      randomness
  in
  {
    Libcrux_ml_dsa.Types.f_signing_key
    =
    Libcrux_ml_dsa.Types.MLDSASigningKey signing_key
    <:
    Libcrux_ml_dsa.Types.t_MLDSASigningKey (Rust_primitives.mk_usize 2560);
    Libcrux_ml_dsa.Types.f_verification_key
    =
    Libcrux_ml_dsa.Types.MLDSAVerificationKey verification_key
    <:
    Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (Rust_primitives.mk_usize 1312)
  }
  <:
  Libcrux_ml_dsa.Types.t_MLDSAKeyPair (Rust_primitives.mk_usize 1312)
    (Rust_primitives.mk_usize 2560)
