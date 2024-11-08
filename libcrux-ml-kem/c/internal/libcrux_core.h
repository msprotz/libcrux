/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 3a133fe0eee9bd3928d5bb16c24ddd2dd0f3ee7f
 * Eurydice: 1fff1c51ae6e6c87eafd28ec9d5594f54bc91c0c
 * Karamel: c31a22c1e07d2118c07ee5cebb640d863e31a198
 * F*: 2c32d6e230851bbceadac7a21fc418fa2bb7e4bc
 * Libcrux: 38837f1aab3f2ae348a0cb53cf44d97652e2c977
 */

#ifndef __internal_libcrux_core_H
#define __internal_libcrux_core_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../libcrux_core.h"
#include "eurydice_glue.h"

#define CORE_NUM__U32_8__BITS (32U)

static inline uint32_t core_num__u8_6__count_ones(uint8_t x0);

#define LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE ((size_t)32U)

void libcrux_ml_kem_constant_time_ops_compare_ciphertexts_select_shared_secret_in_constant_time(
    Eurydice_slice lhs_c, Eurydice_slice rhs_c, Eurydice_slice lhs_s,
    Eurydice_slice rhs_s, uint8_t ret[32U]);

#define LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT ((size_t)12U)

#define LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT ((size_t)256U)

#define LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * (size_t)12U)

#define LIBCRUX_ML_KEM_CONSTANTS_BYTES_PER_RING_ELEMENT \
  (LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_KEM_CONSTANTS_CPA_PKE_KEY_GENERATION_SEED_SIZE ((size_t)32U)

#define LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE ((size_t)32U)

typedef struct libcrux_ml_kem_utils_extraction_helper_Keypair1024_s {
  uint8_t fst[1536U];
  uint8_t snd[1568U];
} libcrux_ml_kem_utils_extraction_helper_Keypair1024;

typedef struct libcrux_ml_kem_utils_extraction_helper_Keypair512_s {
  uint8_t fst[768U];
  uint8_t snd[800U];
} libcrux_ml_kem_utils_extraction_helper_Keypair512;

typedef struct libcrux_ml_kem_utils_extraction_helper_Keypair768_s {
  uint8_t fst[1152U];
  uint8_t snd[1184U];
} libcrux_ml_kem_utils_extraction_helper_Keypair768;

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemPublicKey<SIZE>)#16}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_5a
with const generics
- SIZE= 1568
*/
libcrux_ml_kem_types_MlKemPublicKey_64 libcrux_ml_kem_types_from_5a_af(
    uint8_t value[1568U]);

/**
This function found in impl
{libcrux_ml_kem::types::MlKemKeyPair<PRIVATE_KEY_SIZE, PUBLIC_KEY_SIZE>#21}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_3a
with const generics
- PRIVATE_KEY_SIZE= 3168
- PUBLIC_KEY_SIZE= 1568
*/
libcrux_ml_kem_mlkem1024_MlKem1024KeyPair libcrux_ml_kem_types_from_3a_94(
    libcrux_ml_kem_types_MlKemPrivateKey_83 sk,
    libcrux_ml_kem_types_MlKemPublicKey_64 pk);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemPrivateKey<SIZE>)#9}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_7f
with const generics
- SIZE= 3168
*/
libcrux_ml_kem_types_MlKemPrivateKey_83 libcrux_ml_kem_types_from_7f_39(
    uint8_t value[3168U]);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemPublicKey<SIZE>)#16}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_5a
with const generics
- SIZE= 1184
*/
libcrux_ml_kem_types_MlKemPublicKey_30 libcrux_ml_kem_types_from_5a_d0(
    uint8_t value[1184U]);

/**
This function found in impl
{libcrux_ml_kem::types::MlKemKeyPair<PRIVATE_KEY_SIZE, PUBLIC_KEY_SIZE>#21}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_3a
with const generics
- PRIVATE_KEY_SIZE= 2400
- PUBLIC_KEY_SIZE= 1184
*/
libcrux_ml_kem_mlkem768_MlKem768KeyPair libcrux_ml_kem_types_from_3a_74(
    libcrux_ml_kem_types_MlKemPrivateKey_d9 sk,
    libcrux_ml_kem_types_MlKemPublicKey_30 pk);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemPrivateKey<SIZE>)#9}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_7f
with const generics
- SIZE= 2400
*/
libcrux_ml_kem_types_MlKemPrivateKey_d9 libcrux_ml_kem_types_from_7f_28(
    uint8_t value[2400U]);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemPublicKey<SIZE>)#16}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_5a
with const generics
- SIZE= 800
*/
libcrux_ml_kem_types_MlKemPublicKey_52 libcrux_ml_kem_types_from_5a_4d(
    uint8_t value[800U]);

/**
This function found in impl
{libcrux_ml_kem::types::MlKemKeyPair<PRIVATE_KEY_SIZE, PUBLIC_KEY_SIZE>#21}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_3a
with const generics
- PRIVATE_KEY_SIZE= 1632
- PUBLIC_KEY_SIZE= 800
*/
libcrux_ml_kem_types_MlKemKeyPair_3e libcrux_ml_kem_types_from_3a_fa(
    libcrux_ml_kem_types_MlKemPrivateKey_fa sk,
    libcrux_ml_kem_types_MlKemPublicKey_52 pk);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemPrivateKey<SIZE>)#9}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_7f
with const generics
- SIZE= 1632
*/
libcrux_ml_kem_types_MlKemPrivateKey_fa libcrux_ml_kem_types_from_7f_2a(
    uint8_t value[1632U]);

/**
This function found in impl {libcrux_ml_kem::types::MlKemPublicKey<SIZE>#20}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.as_slice_fd
with const generics
- SIZE= 1184
*/
uint8_t *libcrux_ml_kem_types_as_slice_fd_d0(
    libcrux_ml_kem_types_MlKemPublicKey_30 *self);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemCiphertext<SIZE>)#2}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_01
with const generics
- SIZE= 1088
*/
libcrux_ml_kem_mlkem768_MlKem768Ciphertext libcrux_ml_kem_types_from_01_80(
    uint8_t value[1088U]);

/**
This function found in impl {(core::convert::AsRef<@Slice<u8>> for
libcrux_ml_kem::types::MlKemCiphertext<SIZE>)#1}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.as_ref_00
with const generics
- SIZE= 1088
*/
Eurydice_slice libcrux_ml_kem_types_as_ref_00_80(
    libcrux_ml_kem_mlkem768_MlKem768Ciphertext *self);

/**
 Pad the `slice` with `0`s at the end.
*/
/**
A monomorphic instance of libcrux_ml_kem.utils.into_padded_array
with const generics
- LEN= 1120
*/
void libcrux_ml_kem_utils_into_padded_array_15(Eurydice_slice slice,
                                               uint8_t ret[1120U]);

/**
This function found in impl {libcrux_ml_kem::types::MlKemPublicKey<SIZE>#20}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.as_slice_fd
with const generics
- SIZE= 800
*/
uint8_t *libcrux_ml_kem_types_as_slice_fd_4d(
    libcrux_ml_kem_types_MlKemPublicKey_52 *self);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemCiphertext<SIZE>)#2}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_01
with const generics
- SIZE= 768
*/
libcrux_ml_kem_types_MlKemCiphertext_1a libcrux_ml_kem_types_from_01_d0(
    uint8_t value[768U]);

/**
This function found in impl {(core::convert::AsRef<@Slice<u8>> for
libcrux_ml_kem::types::MlKemCiphertext<SIZE>)#1}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.as_ref_00
with const generics
- SIZE= 768
*/
Eurydice_slice libcrux_ml_kem_types_as_ref_00_d0(
    libcrux_ml_kem_types_MlKemCiphertext_1a *self);

/**
 Pad the `slice` with `0`s at the end.
*/
/**
A monomorphic instance of libcrux_ml_kem.utils.into_padded_array
with const generics
- LEN= 800
*/
void libcrux_ml_kem_utils_into_padded_array_4d(Eurydice_slice slice,
                                               uint8_t ret[800U]);

/**
This function found in impl {libcrux_ml_kem::types::MlKemPublicKey<SIZE>#20}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.as_slice_fd
with const generics
- SIZE= 1568
*/
uint8_t *libcrux_ml_kem_types_as_slice_fd_af(
    libcrux_ml_kem_types_MlKemPublicKey_64 *self);

/**
A monomorphic instance of core.result.Result
with types uint8_t[32size_t], core_array_TryFromSliceError

*/
typedef struct core_result_Result_fb_s {
  core_result_Result_a9_tags tag;
  union {
    uint8_t case_Ok[32U];
    core_array_TryFromSliceError case_Err;
  } val;
} core_result_Result_fb;

/**
This function found in impl {core::result::Result<T, E>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of core.result.unwrap_26
with types uint8_t[32size_t], core_array_TryFromSliceError

*/
void core_result_unwrap_26_b3(core_result_Result_fb self, uint8_t ret[32U]);

/**
 Pad the `slice` with `0`s at the end.
*/
/**
A monomorphic instance of libcrux_ml_kem.utils.into_padded_array
with const generics
- LEN= 34
*/
void libcrux_ml_kem_utils_into_padded_array_b6(Eurydice_slice slice,
                                               uint8_t ret[34U]);

/**
This function found in impl {(core::convert::From<@Array<u8, SIZE>> for
libcrux_ml_kem::types::MlKemCiphertext<SIZE>)#2}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.from_01
with const generics
- SIZE= 1568
*/
libcrux_ml_kem_types_MlKemCiphertext_64 libcrux_ml_kem_types_from_01_af(
    uint8_t value[1568U]);

/**
 Pad the `slice` with `0`s at the end.
*/
/**
A monomorphic instance of libcrux_ml_kem.utils.into_padded_array
with const generics
- LEN= 33
*/
void libcrux_ml_kem_utils_into_padded_array_c8(Eurydice_slice slice,
                                               uint8_t ret[33U]);

/**
This function found in impl {(core::convert::AsRef<@Slice<u8>> for
libcrux_ml_kem::types::MlKemCiphertext<SIZE>)#1}
*/
/**
A monomorphic instance of libcrux_ml_kem.types.as_ref_00
with const generics
- SIZE= 1568
*/
Eurydice_slice libcrux_ml_kem_types_as_ref_00_af(
    libcrux_ml_kem_types_MlKemCiphertext_64 *self);

/**
 Pad the `slice` with `0`s at the end.
*/
/**
A monomorphic instance of libcrux_ml_kem.utils.into_padded_array
with const generics
- LEN= 1600
*/
void libcrux_ml_kem_utils_into_padded_array_7f(Eurydice_slice slice,
                                               uint8_t ret[1600U]);

/**
 Pad the `slice` with `0`s at the end.
*/
/**
A monomorphic instance of libcrux_ml_kem.utils.into_padded_array
with const generics
- LEN= 64
*/
void libcrux_ml_kem_utils_into_padded_array_24(Eurydice_slice slice,
                                               uint8_t ret[64U]);

/**
A monomorphic instance of core.result.Result
with types uint8_t[24size_t], core_array_TryFromSliceError

*/
typedef struct core_result_Result_b2_s {
  core_result_Result_a9_tags tag;
  union {
    uint8_t case_Ok[24U];
    core_array_TryFromSliceError case_Err;
  } val;
} core_result_Result_b2;

/**
This function found in impl {core::result::Result<T, E>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of core.result.unwrap_26
with types uint8_t[24size_t], core_array_TryFromSliceError

*/
void core_result_unwrap_26_70(core_result_Result_b2 self, uint8_t ret[24U]);

/**
A monomorphic instance of core.result.Result
with types uint8_t[20size_t], core_array_TryFromSliceError

*/
typedef struct core_result_Result_e1_s {
  core_result_Result_a9_tags tag;
  union {
    uint8_t case_Ok[20U];
    core_array_TryFromSliceError case_Err;
  } val;
} core_result_Result_e1;

/**
This function found in impl {core::result::Result<T, E>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of core.result.unwrap_26
with types uint8_t[20size_t], core_array_TryFromSliceError

*/
void core_result_unwrap_26_20(core_result_Result_e1 self, uint8_t ret[20U]);

/**
A monomorphic instance of core.result.Result
with types uint8_t[10size_t], core_array_TryFromSliceError

*/
typedef struct core_result_Result_9d_s {
  core_result_Result_a9_tags tag;
  union {
    uint8_t case_Ok[10U];
    core_array_TryFromSliceError case_Err;
  } val;
} core_result_Result_9d;

/**
This function found in impl {core::result::Result<T, E>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of core.result.unwrap_26
with types uint8_t[10size_t], core_array_TryFromSliceError

*/
void core_result_unwrap_26_ce(core_result_Result_9d self, uint8_t ret[10U]);

/**
A monomorphic instance of core.result.Result
with types int16_t[16size_t], core_array_TryFromSliceError

*/
typedef struct core_result_Result_0a_s {
  core_result_Result_a9_tags tag;
  union {
    int16_t case_Ok[16U];
    core_array_TryFromSliceError case_Err;
  } val;
} core_result_Result_0a;

/**
This function found in impl {core::result::Result<T, E>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of core.result.unwrap_26
with types int16_t[16size_t], core_array_TryFromSliceError

*/
void core_result_unwrap_26_00(core_result_Result_0a self, int16_t ret[16U]);

typedef struct Eurydice_slice_uint8_t_4size_t__x2_s {
  Eurydice_slice fst[4U];
  Eurydice_slice snd[4U];
} Eurydice_slice_uint8_t_4size_t__x2;

#if defined(__cplusplus)
}
#endif

#define __internal_libcrux_core_H_DEFINED
#endif
