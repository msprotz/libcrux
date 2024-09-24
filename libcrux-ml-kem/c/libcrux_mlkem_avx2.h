/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 28d543bfacc902ba9cc2a734b76baae9583892a4
 * Eurydice: 1a65dbf3758fe310833718c645a64266294a29ac
 * Karamel: 15d4bce74a2d43e34a64f48f8311b7d9bcb0e152
 * F*: 650b216aeb5901ec6f1c44ff275acd924e54bdbd
 * Libcrux: b1ecb428c60dd375b8bdd05c258cd0e4d5f1fec1
 */

#ifndef __libcrux_mlkem_avx2_H
#define __libcrux_mlkem_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"
#include "libcrux_mlkem_portable.h"
#include "libcrux_sha3.h"
#include "libcrux_sha3_avx2.h"

void libcrux_ml_kem_hash_functions_avx2_G(Eurydice_slice input,
                                          uint8_t ret[64U]);

void libcrux_ml_kem_hash_functions_avx2_H(Eurydice_slice input,
                                          uint8_t ret[32U]);

__m256i libcrux_ml_kem_vector_avx2_vec_zero(void);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_ZERO_09(void);

__m256i libcrux_ml_kem_vector_avx2_vec_from_i16_array(Eurydice_slice array);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_from_i16_array_09(Eurydice_slice array);

void libcrux_ml_kem_vector_avx2_vec_to_i16_array(__m256i v, int16_t ret[16U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_to_i16_array_09(__m256i x, int16_t ret[16U]);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_add(__m256i lhs, __m256i rhs);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_add_09(__m256i lhs, __m256i *rhs);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_sub(__m256i lhs, __m256i rhs);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_sub_09(__m256i lhs, __m256i *rhs);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_multiply_by_constant(
    __m256i vector, int16_t constant);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_multiply_by_constant_09(__m256i vec,
                                                           int16_t c);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_bitwise_and_with_constant(
    __m256i vector, int16_t constant);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_bitwise_and_with_constant_09(
    __m256i vector, int16_t constant);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_cond_subtract_3329(
    __m256i vector);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_cond_subtract_3329_09(__m256i vector);

#define LIBCRUX_ML_KEM_VECTOR_AVX2_ARITHMETIC_BARRETT_MULTIPLIER \
  ((int16_t)20159)

/**
 See Section 3.2 of the implementation notes document for an explanation
 of this code.
*/
__m256i libcrux_ml_kem_vector_avx2_arithmetic_barrett_reduce(__m256i vector);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_barrett_reduce_09(__m256i vector);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_by_constant(
    __m256i vector, int16_t constant);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_montgomery_multiply_by_constant_09(
    __m256i vector, int16_t constant);

__m256i libcrux_ml_kem_vector_avx2_compress_compress_message_coefficient(
    __m256i vector);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_compress_1_09(__m256i vector);

__m256i libcrux_ml_kem_vector_avx2_compress_mulhi_mm256_epi32(__m256i lhs,
                                                              __m256i rhs);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_by_constants(
    __m256i vec, __m256i constants);

__m256i libcrux_ml_kem_vector_avx2_ntt_ntt_layer_1_step(
    __m256i vector, int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_ntt_layer_1_step_09(
    __m256i vector, int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3);

__m256i libcrux_ml_kem_vector_avx2_ntt_ntt_layer_2_step(__m256i vector,
                                                        int16_t zeta0,
                                                        int16_t zeta1);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_ntt_layer_2_step_09(__m256i vector,
                                                       int16_t zeta0,
                                                       int16_t zeta1);

__m128i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_m128i_by_constants(
    __m128i vec, __m128i constants);

__m256i libcrux_ml_kem_vector_avx2_ntt_ntt_layer_3_step(__m256i vector,
                                                        int16_t zeta);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_ntt_layer_3_step_09(__m256i vector,
                                                       int16_t zeta);

__m256i libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_1_step(
    __m256i vector, int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_inv_ntt_layer_1_step_09(
    __m256i vector, int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3);

__m256i libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_2_step(__m256i vector,
                                                            int16_t zeta0,
                                                            int16_t zeta1);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_inv_ntt_layer_2_step_09(__m256i vector,
                                                           int16_t zeta0,
                                                           int16_t zeta1);

__m256i libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_3_step(__m256i vector,
                                                            int16_t zeta);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_inv_ntt_layer_3_step_09(__m256i vector,
                                                           int16_t zeta);

__m256i libcrux_ml_kem_vector_avx2_arithmetic_montgomery_reduce_i32s(
    __m256i vec);

__m256i libcrux_ml_kem_vector_avx2_ntt_ntt_multiply(__m256i lhs, __m256i rhs,
                                                    int16_t zeta0,
                                                    int16_t zeta1,
                                                    int16_t zeta2,
                                                    int16_t zeta3);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_ntt_multiply_09(__m256i *lhs, __m256i *rhs,
                                                   int16_t zeta0, int16_t zeta1,
                                                   int16_t zeta2,
                                                   int16_t zeta3);

void libcrux_ml_kem_vector_avx2_serialize_serialize_1(__m256i vector,
                                                      uint8_t ret[2U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_serialize_1_09(__m256i vector, uint8_t ret[2U]);

__m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_1(
    Eurydice_slice bytes);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_deserialize_1_09(Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_4(__m256i vector,
                                                      uint8_t ret[8U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_serialize_4_09(__m256i vector, uint8_t ret[8U]);

__m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_4(
    Eurydice_slice bytes);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_deserialize_4_09(Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_5(__m256i vector,
                                                      uint8_t ret[10U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_serialize_5_09(__m256i vector,
                                               uint8_t ret[10U]);

__m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_5(
    Eurydice_slice bytes);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_deserialize_5_09(Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_10(__m256i vector,
                                                       uint8_t ret[20U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_serialize_10_09(__m256i vector,
                                                uint8_t ret[20U]);

__m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_10(
    Eurydice_slice bytes);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_deserialize_10_09(Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_11(__m256i vector,
                                                       uint8_t ret[22U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_serialize_11_09(__m256i vector,
                                                uint8_t ret[22U]);

__m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_11(
    Eurydice_slice bytes);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_deserialize_11_09(Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_12(__m256i vector,
                                                       uint8_t ret[24U]);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
void libcrux_ml_kem_vector_avx2_serialize_12_09(__m256i vector,
                                                uint8_t ret[24U]);

__m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_12(
    Eurydice_slice bytes);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
__m256i libcrux_ml_kem_vector_avx2_deserialize_12_09(Eurydice_slice bytes);

size_t libcrux_ml_kem_vector_avx2_sampling_rejection_sample(
    Eurydice_slice input, Eurydice_slice output);

/**
This function found in impl {(libcrux_ml_kem::vector::traits::Operations for
libcrux_ml_kem::vector::avx2::SIMD256Vector)#2}
*/
size_t libcrux_ml_kem_vector_avx2_rej_sample_09(Eurydice_slice input,
                                                Eurydice_slice output);

/**
This function found in impl {(core::clone::Clone for
libcrux_ml_kem::vector::avx2::SIMD256Vector)}
*/
__m256i libcrux_ml_kem_vector_avx2_clone_78(__m256i *self);

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem_avx2_H_DEFINED
#endif
