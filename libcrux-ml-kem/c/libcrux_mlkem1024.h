/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc
  F* version: b5cb71b8
  KaRaMeL version: 04cb86b9
 */

#ifndef __libcrux_mlkem1024_H
#define __libcrux_mlkem1024_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "libcrux_sha3.h"
#include "libcrux_polynomial.h"
#include "libcrux_platform.h"
#include "libcrux_core.h"
#include "eurydice_glue.h"

#define LIBCRUX_ML_KEM_MLKEM1024_VECTOR_U_COMPRESSION_FACTOR_1024 ((size_t)11U)

#define LIBCRUX_ML_KEM_MLKEM1024_C1_BLOCK_SIZE_1024 (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * LIBCRUX_ML_KEM_MLKEM1024_VECTOR_U_COMPRESSION_FACTOR_1024 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 ((size_t)4U)

#define LIBCRUX_ML_KEM_MLKEM1024_C1_SIZE_1024 (LIBCRUX_ML_KEM_MLKEM1024_C1_BLOCK_SIZE_1024 * LIBCRUX_ML_KEM_MLKEM1024_RANK_1024)

#define LIBCRUX_ML_KEM_MLKEM1024_VECTOR_V_COMPRESSION_FACTOR_1024 ((size_t)5U)

#define LIBCRUX_ML_KEM_MLKEM1024_C2_SIZE_1024 (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * LIBCRUX_ML_KEM_MLKEM1024_VECTOR_V_COMPRESSION_FACTOR_1024 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_CIPHERTEXT_SIZE_1024 (LIBCRUX_ML_KEM_MLKEM1024_C1_SIZE_1024 + LIBCRUX_ML_KEM_MLKEM1024_C2_SIZE_1024)

#define LIBCRUX_ML_KEM_MLKEM1024_T_AS_NTT_ENCODED_SIZE_1024 (LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 * LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_PUBLIC_KEY_SIZE_1024 (LIBCRUX_ML_KEM_MLKEM1024_T_AS_NTT_ENCODED_SIZE_1024 + (size_t)32U)

#define LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_SECRET_KEY_SIZE_1024 (LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 * LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA1 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA1_RANDOMNESS_SIZE (LIBCRUX_ML_KEM_MLKEM1024_ETA1 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA2 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA2_RANDOMNESS_SIZE (LIBCRUX_ML_KEM_MLKEM1024_ETA2 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM1024_IMPLICIT_REJECTION_HASH_INPUT_SIZE (LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE + LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_CIPHERTEXT_SIZE_1024)

#define LIBCRUX_ML_KEM_MLKEM1024_RANKED_BYTES_PER_RING_ELEMENT_1024 (LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 * LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_SECRET_KEY_SIZE_1024 (LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_SECRET_KEY_SIZE_1024 + LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_PUBLIC_KEY_SIZE_1024 + LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE + LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE)

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____G___4size_t(
  Eurydice_slice input,
  uint8_t ret[64U]
);

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____PRF___4size_t_32size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

typedef struct libcrux_ml_kem_hash_functions_portable_PortableHash____4size_t_s
{ libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t shake128_state[4U]; }
libcrux_ml_kem_hash_functions_portable_PortableHash____4size_t;

libcrux_ml_kem_hash_functions_portable_PortableHash____4size_t
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____shake128_init_absorb___4size_t(
  uint8_t input[4U][34U]
);

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____shake128_squeeze_three_blocks___4size_t(
  libcrux_ml_kem_hash_functions_portable_PortableHash____4size_t *self,
  uint8_t ret[4U][504U]
);

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____shake128_squeeze_block___4size_t(
  libcrux_ml_kem_hash_functions_portable_PortableHash____4size_t *self,
  uint8_t ret[4U][168U]
);

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____PRFxN___4size_t_128size_t(
  uint8_t (*input)[33U],
  uint8_t ret[4U][128U]
);

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____PRF___4size_t_128size_t(
  Eurydice_slice input,
  uint8_t ret[128U]
);

void
libcrux_ml_kem_mlkem1024_decapsulate(
  libcrux_ml_kem_types_MlKemPrivateKey____3168size_t *private_key,
  libcrux_ml_kem_types_MlKemCiphertext____1568size_t *ciphertext,
  uint8_t ret[32U]
);

void
libcrux_ml_kem_hash_functions_portable___libcrux_ml_kem__hash_functions__Hash_K__for_libcrux_ml_kem__hash_functions__portable__PortableHash_K____H___4size_t(
  Eurydice_slice input,
  uint8_t ret[32U]
);

K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_
libcrux_ml_kem_mlkem1024_encapsulate(
  libcrux_ml_kem_types_MlKemPublicKey____1568size_t *public_key,
  uint8_t randomness[32U]
);

libcrux_ml_kem_types_MlKemKeyPair____3168size_t__1568size_t
libcrux_ml_kem_mlkem1024_generate_key_pair(uint8_t randomness[64U]);

core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1568size_t__
libcrux_ml_kem_mlkem1024_validate_public_key(
  libcrux_ml_kem_types_MlKemPublicKey____1568size_t public_key
);

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem1024_H_DEFINED
#endif
