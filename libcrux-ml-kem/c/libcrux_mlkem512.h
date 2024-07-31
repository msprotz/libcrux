/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 45b95e0f63cb830202c0b3ca00a341a3451a02ba
 * Eurydice: c959e0871805e4cc6ced4bde7d8493f1dccfdcc3
 * Karamel: d5759a8b96e9f104664a88a83043d5761fcc9732
 * F*: b2931dfbe46e839cd757220c63d48c71335bb1ae
 * Libcrux: b5ddab9fb634b6e85a54bb44b7c32a3fba483843
 */

#ifndef __libcrux_mlkem512_H
#define __libcrux_mlkem512_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"

#define LIBCRUX_ML_KEM_MLKEM512_VECTOR_U_COMPRESSION_FACTOR_512 ((size_t)10U)

#define LIBCRUX_ML_KEM_MLKEM512_C1_BLOCK_SIZE_512          \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_MLKEM512_VECTOR_U_COMPRESSION_FACTOR_512 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_RANK_512 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM512_C1_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_C1_BLOCK_SIZE_512 * LIBCRUX_ML_KEM_MLKEM512_RANK_512)

#define LIBCRUX_ML_KEM_MLKEM512_VECTOR_V_COMPRESSION_FACTOR_512 ((size_t)4U)

#define LIBCRUX_ML_KEM_MLKEM512_C2_SIZE_512                \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_MLKEM512_VECTOR_V_COMPRESSION_FACTOR_512 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_CIPHERTEXT_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_C1_SIZE_512 + LIBCRUX_ML_KEM_MLKEM512_C2_SIZE_512)

#define LIBCRUX_ML_KEM_MLKEM512_T_AS_NTT_ENCODED_SIZE_512  \
  (LIBCRUX_ML_KEM_MLKEM512_RANK_512 *                      \
   LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_PUBLIC_KEY_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_T_AS_NTT_ENCODED_SIZE_512 + (size_t)32U)

#define LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_SECRET_KEY_SIZE_512 \
  (LIBCRUX_ML_KEM_MLKEM512_RANK_512 *                       \
   LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *  \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA1 ((size_t)3U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA1_RANDOMNESS_SIZE \
  (LIBCRUX_ML_KEM_MLKEM512_ETA1 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA2 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM512_ETA2_RANDOMNESS_SIZE \
  (LIBCRUX_ML_KEM_MLKEM512_ETA2 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM512_IMPLICIT_REJECTION_HASH_INPUT_SIZE \
  (LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE +                   \
   LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_CIPHERTEXT_SIZE_512)

typedef libcrux_ml_kem_types_MlKemCiphertext____768size_t
    libcrux_ml_kem_mlkem512_MlKem512Ciphertext;

typedef libcrux_ml_kem_types_MlKemKeyPair____1632size_t__800size_t
    libcrux_ml_kem_mlkem512_MlKem512KeyPair;

typedef libcrux_ml_kem_types_MlKemPrivateKey____1632size_t
    libcrux_ml_kem_mlkem512_MlKem512PrivateKey;

typedef libcrux_ml_kem_types_MlKemPublicKey____800size_t
    libcrux_ml_kem_mlkem512_MlKem512PublicKey;

#define LIBCRUX_ML_KEM_MLKEM512_RANKED_BYTES_PER_RING_ELEMENT_512 \
  (LIBCRUX_ML_KEM_MLKEM512_RANK_512 *                             \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM512_SECRET_KEY_SIZE_512      \
  (LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_SECRET_KEY_SIZE_512 + \
   LIBCRUX_ML_KEM_MLKEM512_CPA_PKE_PUBLIC_KEY_SIZE_512 + \
   LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE +              \
   LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE)

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem512_H_DEFINED
#endif
