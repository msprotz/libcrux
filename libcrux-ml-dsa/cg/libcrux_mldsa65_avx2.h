/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: a68994d00017b76a805d0115ca06c1f2c1805e79
 * Eurydice: b665364a6d86749566ce2d650d13fa12c8fab2c5
 * Karamel: 96572bc631fde691a2aea7bce5a5a3838b3a5968
 * F*: b0961063393215ca65927f017720cb365a193833-dirty
 * Libcrux: 11a2dcf9b3f0c4803b93a53caa737ed8eac8bfd1
 */

#ifndef __libcrux_mldsa65_avx2_H
#define __libcrux_mldsa65_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "intrinsics/libcrux_intrinsics_avx2.h"
#include "libcrux_core.h"
#include "libcrux_mldsa65_portable.h"
#include "libcrux_sha3_avx2.h"
#include "libcrux_sha3_portable.h"

typedef libcrux_sha3_avx2_x4_incremental_KeccakState
    libcrux_ml_dsa_hash_functions_simd256_Shake128x4;

/**
 Init the state and absorb 4 blocks in parallel.
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_sha3_avx2_x4_incremental_KeccakState
libcrux_ml_dsa_hash_functions_simd256_init_absorb(Eurydice_slice input0,
                                                  Eurydice_slice input1,
                                                  Eurydice_slice input2,
                                                  Eurydice_slice input3) {
  libcrux_sha3_generic_keccak_KeccakState_55 state =
      libcrux_sha3_avx2_x4_incremental_init();
  libcrux_sha3_avx2_x4_incremental_shake128_absorb_final(&state, input0, input1,
                                                         input2, input3);
  return state;
}

typedef libcrux_sha3_portable_KeccakState
    libcrux_ml_dsa_hash_functions_simd256_Shake256;

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_sha3_portable_KeccakState
libcrux_ml_dsa_hash_functions_simd256_init_absorb_final_shake256(
    Eurydice_slice input) {
  libcrux_sha3_generic_keccak_KeccakState_17 state =
      libcrux_sha3_portable_incremental_shake256_init();
  libcrux_sha3_portable_incremental_shake256_absorb_final(&state, input);
  return state;
}

typedef libcrux_sha3_avx2_x4_incremental_KeccakState
    libcrux_ml_dsa_hash_functions_simd256_Shake256x4;

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_sha3_avx2_x4_incremental_KeccakState
libcrux_ml_dsa_hash_functions_simd256_init_absorb_x4(Eurydice_slice input0,
                                                     Eurydice_slice input1,
                                                     Eurydice_slice input2,
                                                     Eurydice_slice input3) {
  libcrux_sha3_generic_keccak_KeccakState_55 state =
      libcrux_sha3_avx2_x4_incremental_init();
  libcrux_sha3_avx2_x4_incremental_shake256_absorb_final(&state, input0, input1,
                                                         input2, input3);
  return state;
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_shake256(
    libcrux_sha3_portable_KeccakState *state, uint8_t ret[136U]) {
  uint8_t out[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_first_block(
      state, Eurydice_array_to_slice((size_t)136U, out, uint8_t));
  memcpy(ret, out, (size_t)136U * sizeof(uint8_t));
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_x4(
    libcrux_sha3_avx2_x4_incremental_KeccakState *state) {
  uint8_t out0[136U] = {0U};
  uint8_t out1[136U] = {0U};
  uint8_t out2[136U] = {0U};
  uint8_t out3[136U] = {0U};
  libcrux_sha3_avx2_x4_incremental_shake256_squeeze_first_block(
      state, Eurydice_array_to_slice((size_t)136U, out0, uint8_t),
      Eurydice_array_to_slice((size_t)136U, out1, uint8_t),
      Eurydice_array_to_slice((size_t)136U, out2, uint8_t),
      Eurydice_array_to_slice((size_t)136U, out3, uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out0[136U];
  memcpy(copy_of_out0, out0, (size_t)136U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out1[136U];
  memcpy(copy_of_out1, out1, (size_t)136U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out2[136U];
  memcpy(copy_of_out2, out2, (size_t)136U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out3[136U];
  memcpy(copy_of_out3, out3, (size_t)136U * sizeof(uint8_t));
  uint8_t_136size_t__x4 lit;
  memcpy(lit.fst, copy_of_out0, (size_t)136U * sizeof(uint8_t));
  memcpy(lit.snd, copy_of_out1, (size_t)136U * sizeof(uint8_t));
  memcpy(lit.thd, copy_of_out2, (size_t)136U * sizeof(uint8_t));
  memcpy(lit.f3, copy_of_out3, (size_t)136U * sizeof(uint8_t));
  return lit;
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_squeeze_first_five_blocks(
    libcrux_sha3_avx2_x4_incremental_KeccakState *state, uint8_t *out0,
    uint8_t *out1, uint8_t *out2, uint8_t *out3) {
  libcrux_sha3_avx2_x4_incremental_shake128_squeeze_first_five_blocks(
      state, Eurydice_array_to_slice((size_t)840U, out0, uint8_t),
      Eurydice_array_to_slice((size_t)840U, out1, uint8_t),
      Eurydice_array_to_slice((size_t)840U, out2, uint8_t),
      Eurydice_array_to_slice((size_t)840U, out3, uint8_t));
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE uint8_t_168size_t__x4
libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block(
    libcrux_sha3_avx2_x4_incremental_KeccakState *state) {
  uint8_t out0[168U] = {0U};
  uint8_t out1[168U] = {0U};
  uint8_t out2[168U] = {0U};
  uint8_t out3[168U] = {0U};
  libcrux_sha3_avx2_x4_incremental_shake128_squeeze_next_block(
      state, Eurydice_array_to_slice((size_t)168U, out0, uint8_t),
      Eurydice_array_to_slice((size_t)168U, out1, uint8_t),
      Eurydice_array_to_slice((size_t)168U, out2, uint8_t),
      Eurydice_array_to_slice((size_t)168U, out3, uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out0[168U];
  memcpy(copy_of_out0, out0, (size_t)168U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out1[168U];
  memcpy(copy_of_out1, out1, (size_t)168U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out2[168U];
  memcpy(copy_of_out2, out2, (size_t)168U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out3[168U];
  memcpy(copy_of_out3, out3, (size_t)168U * sizeof(uint8_t));
  uint8_t_168size_t__x4 lit;
  memcpy(lit.fst, copy_of_out0, (size_t)168U * sizeof(uint8_t));
  memcpy(lit.snd, copy_of_out1, (size_t)168U * sizeof(uint8_t));
  memcpy(lit.thd, copy_of_out2, (size_t)168U * sizeof(uint8_t));
  memcpy(lit.f3, copy_of_out3, (size_t)168U * sizeof(uint8_t));
  return lit;
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_shake256(
    libcrux_sha3_portable_KeccakState *state, uint8_t ret[136U]) {
  uint8_t out[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_next_block(
      state, Eurydice_array_to_slice((size_t)136U, out, uint8_t));
  memcpy(ret, out, (size_t)136U * sizeof(uint8_t));
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4(
    libcrux_sha3_avx2_x4_incremental_KeccakState *state) {
  uint8_t out0[136U] = {0U};
  uint8_t out1[136U] = {0U};
  uint8_t out2[136U] = {0U};
  uint8_t out3[136U] = {0U};
  libcrux_sha3_avx2_x4_incremental_shake256_squeeze_next_block(
      state, Eurydice_array_to_slice((size_t)136U, out0, uint8_t),
      Eurydice_array_to_slice((size_t)136U, out1, uint8_t),
      Eurydice_array_to_slice((size_t)136U, out2, uint8_t),
      Eurydice_array_to_slice((size_t)136U, out3, uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out0[136U];
  memcpy(copy_of_out0, out0, (size_t)136U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out1[136U];
  memcpy(copy_of_out1, out1, (size_t)136U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out2[136U];
  memcpy(copy_of_out2, out2, (size_t)136U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_out3[136U];
  memcpy(copy_of_out3, out3, (size_t)136U * sizeof(uint8_t));
  uint8_t_136size_t__x4 lit;
  memcpy(lit.fst, copy_of_out0, (size_t)136U * sizeof(uint8_t));
  memcpy(lit.snd, copy_of_out1, (size_t)136U * sizeof(uint8_t));
  memcpy(lit.thd, copy_of_out2, (size_t)136U * sizeof(uint8_t));
  memcpy(lit.f3, copy_of_out3, (size_t)136U * sizeof(uint8_t));
  return lit;
}

/**
 Init the state and absorb 4 blocks in parallel.
*/
/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::XofX4
for libcrux_ml_dsa::hash_functions::simd256::Shake128x4)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_sha3_avx2_x4_incremental_KeccakState
libcrux_ml_dsa_hash_functions_simd256_init_absorb_7b(Eurydice_slice input0,
                                                     Eurydice_slice input1,
                                                     Eurydice_slice input2,
                                                     Eurydice_slice input3) {
  return libcrux_ml_dsa_hash_functions_simd256_init_absorb(input0, input1,
                                                           input2, input3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::XofX4
for libcrux_ml_dsa::hash_functions::simd256::Shake128x4)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_squeeze_first_five_blocks_7b(
    libcrux_sha3_avx2_x4_incremental_KeccakState *self, uint8_t *out0,
    uint8_t *out1, uint8_t *out2, uint8_t *out3) {
  libcrux_ml_dsa_hash_functions_simd256_squeeze_first_five_blocks(
      self, out0, out1, out2, out3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::XofX4
for libcrux_ml_dsa::hash_functions::simd256::Shake128x4)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE uint8_t_168size_t__x4
libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_7b(
    libcrux_sha3_avx2_x4_incremental_KeccakState *self) {
  return libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block(self);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::simd256::Shake256)#1}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_sha3_portable_KeccakState
libcrux_ml_dsa_hash_functions_simd256_init_absorb_final_d9(
    Eurydice_slice input) {
  return libcrux_ml_dsa_hash_functions_simd256_init_absorb_final_shake256(
      input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::simd256::Shake256)#1}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_d9(
    libcrux_sha3_portable_KeccakState *self, uint8_t ret[136U]) {
  libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_shake256(self, ret);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::simd256::Shake256)#1}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_d9(
    libcrux_sha3_portable_KeccakState *self, uint8_t ret[136U]) {
  libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_shake256(self, ret);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::simd256::Shake256x4)#2}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_sha3_avx2_x4_incremental_KeccakState
libcrux_ml_dsa_hash_functions_simd256_init_absorb_x4_fb(Eurydice_slice input0,
                                                        Eurydice_slice input1,
                                                        Eurydice_slice input2,
                                                        Eurydice_slice input3) {
  return libcrux_ml_dsa_hash_functions_simd256_init_absorb_x4(input0, input1,
                                                              input2, input3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::simd256::Shake256x4)#2}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_x4_fb(
    libcrux_sha3_avx2_x4_incremental_KeccakState *self) {
  return libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_x4(self);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::simd256::Shake256x4)#2}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4_fb(
    libcrux_sha3_avx2_x4_incremental_KeccakState *self) {
  return libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4(self);
}

typedef __m256i libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit;

KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i libcrux_ml_dsa_simd_avx2_vector_type_ZERO(void) {
  return libcrux_intrinsics_avx2_mm256_setzero_si256();
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i libcrux_ml_dsa_simd_avx2_ZERO_a2(void) {
  return libcrux_ml_dsa_simd_avx2_vector_type_ZERO();
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i
libcrux_ml_dsa_simd_avx2_vector_type_from_coefficient_array(
    Eurydice_slice coefficient_array) {
  return libcrux_intrinsics_avx2_mm256_loadu_si256_i32(coefficient_array);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_from_coefficient_array_a2(
    Eurydice_slice coefficient_array) {
  return libcrux_ml_dsa_simd_avx2_vector_type_from_coefficient_array(
      coefficient_array);
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_vector_type_to_coefficient_array(
    __m256i *x, int32_t ret[8U]) {
  int32_t coefficient_array[8U] = {0U};
  libcrux_intrinsics_avx2_mm256_storeu_si256_i32(
      Eurydice_array_to_slice((size_t)8U, coefficient_array, int32_t), x[0U]);
  memcpy(ret, coefficient_array, (size_t)8U * sizeof(int32_t));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_to_coefficient_array_a2(
    __m256i *self, int32_t ret[8U]) {
  libcrux_ml_dsa_simd_avx2_vector_type_to_coefficient_array(self, ret);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_arithmetic_add(__m256i lhs, __m256i rhs) {
  return libcrux_intrinsics_avx2_mm256_add_epi32(lhs, rhs);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i libcrux_ml_dsa_simd_avx2_add_a2(__m256i *lhs,
                                                               __m256i *rhs) {
  return libcrux_ml_dsa_simd_avx2_arithmetic_add(lhs[0U], rhs[0U]);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_arithmetic_subtract(__m256i lhs, __m256i rhs) {
  return libcrux_intrinsics_avx2_mm256_sub_epi32(lhs, rhs);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_subtract_a2(__m256i *lhs, __m256i *rhs) {
  return libcrux_ml_dsa_simd_avx2_arithmetic_subtract(lhs[0U], rhs[0U]);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE bool
libcrux_ml_dsa_simd_avx2_arithmetic_infinity_norm_exceeds(__m256i simd_unit,
                                                          int32_t bound) {
  __m256i absolute_values = libcrux_intrinsics_avx2_mm256_abs_epi32(simd_unit);
  __m256i bound0 = libcrux_intrinsics_avx2_mm256_set1_epi32(bound - (int32_t)1);
  __m256i compare_with_bound =
      libcrux_intrinsics_avx2_mm256_cmpgt_epi32(absolute_values, bound0);
  int32_t result = libcrux_intrinsics_avx2_mm256_testz_si256(
      compare_with_bound, compare_with_bound);
  bool uu____0;
  if (result == (int32_t)1) {
    uu____0 = false;
  } else {
    uu____0 = true;
  }
  return uu____0;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE bool libcrux_ml_dsa_simd_avx2_infinity_norm_exceeds_a2(
    __m256i simd_unit, int32_t bound) {
  return libcrux_ml_dsa_simd_avx2_arithmetic_infinity_norm_exceeds(simd_unit,
                                                                   bound);
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i
libcrux_ml_dsa_simd_avx2_arithmetic_to_unsigned_representatives(__m256i t) {
  __m256i signs =
      libcrux_intrinsics_avx2_mm256_srai_epi32((int32_t)31, t, __m256i);
  __m256i conditional_add_field_modulus =
      libcrux_intrinsics_avx2_mm256_and_si256(
          signs, libcrux_intrinsics_avx2_mm256_set1_epi32(
                     LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS));
  return libcrux_intrinsics_avx2_mm256_add_epi32(t,
                                                 conditional_add_field_modulus);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(__m256i lhs,
                                                        __m256i rhs) {
  __m256i field_modulus = libcrux_intrinsics_avx2_mm256_set1_epi32(
      LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  __m256i inverse_of_modulus_mod_montgomery_r =
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          (int32_t)
              LIBCRUX_ML_DSA_SIMD_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R);
  __m256i prod02 = libcrux_intrinsics_avx2_mm256_mul_epi32(lhs, rhs);
  __m256i prod13 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, lhs, __m256i),
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, rhs, __m256i));
  __m256i k02 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      prod02, inverse_of_modulus_mod_montgomery_r);
  __m256i k13 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      prod13, inverse_of_modulus_mod_montgomery_r);
  __m256i c02 = libcrux_intrinsics_avx2_mm256_mul_epi32(k02, field_modulus);
  __m256i c13 = libcrux_intrinsics_avx2_mm256_mul_epi32(k13, field_modulus);
  __m256i res02 = libcrux_intrinsics_avx2_mm256_sub_epi32(prod02, c02);
  __m256i res13 = libcrux_intrinsics_avx2_mm256_sub_epi32(prod13, c13);
  __m256i res02_shifted =
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, res02, __m256i);
  return libcrux_intrinsics_avx2_mm256_blend_epi32((int32_t)170, res02_shifted,
                                                   res13, __m256i);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_montgomery_multiply_a2(__m256i lhs, __m256i rhs) {
  return libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(lhs, rhs);
}

typedef struct core_core_arch_x86___m256i_x2_s {
  __m256i fst;
  __m256i snd;
} core_core_arch_x86___m256i_x2;

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_arithmetic_power2round(__m256i r) {
  __m256i r2 =
      libcrux_ml_dsa_simd_avx2_arithmetic_to_unsigned_representatives(r);
  __m256i r1 = libcrux_intrinsics_avx2_mm256_add_epi32(
      r2, libcrux_intrinsics_avx2_mm256_set1_epi32(
              ((int32_t)1
               << (uint32_t)(LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T -
                             (size_t)1U)) -
              (int32_t)1));
  __m256i r10 =
      libcrux_intrinsics_avx2_mm256_srai_epi32((int32_t)13, r1, __m256i);
  __m256i r0 =
      libcrux_intrinsics_avx2_mm256_slli_epi32((int32_t)13, r10, __m256i);
  __m256i r00 = libcrux_intrinsics_avx2_mm256_sub_epi32(r2, r0);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = r00, .snd = r10});
}

typedef struct libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x2_s {
  __m256i fst;
  __m256i snd;
} libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x2;

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x2
libcrux_ml_dsa_simd_avx2_power2round_a2(__m256i simd_unit) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_arithmetic_power2round(simd_unit);
  __m256i lower = uu____0.fst;
  __m256i upper = uu____0.snd;
  return (CLITERAL(libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x2){
      .fst = lower, .snd = upper});
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_REJECTION_SAMPLE_LESS_THAN_FIELD_MODULUS_BYTESTREAM_TO_POTENTIAL_COEFFICIENTS_COEFFICIENT_MASK \
  (((int32_t)1 << 23U) - (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_field_modulus_bytestream_to_potential_coefficients(
    Eurydice_slice serialized) {
  uint8_t serialized_extended[32U] = {0U};
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_to(
      (size_t)32U, serialized_extended, (size_t)24U, uint8_t, size_t);
  Eurydice_slice_copy(uu____0, serialized, uint8_t);
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_loadu_si256_u8(
      Eurydice_array_to_slice((size_t)32U, serialized_extended, uint8_t));
  __m256i coefficients0 = libcrux_intrinsics_avx2_mm256_permutevar8x32_epi32(
      coefficients, libcrux_intrinsics_avx2_mm256_set_epi32(
                        (int32_t)0, (int32_t)5, (int32_t)4, (int32_t)3,
                        (int32_t)0, (int32_t)2, (int32_t)1, (int32_t)0));
  __m256i coefficients1 = libcrux_intrinsics_avx2_mm256_shuffle_epi8(
      coefficients0,
      libcrux_intrinsics_avx2_mm256_set_epi8(
          (int8_t)-1, (int8_t)11, (int8_t)10, (int8_t)9, (int8_t)-1, (int8_t)8,
          (int8_t)7, (int8_t)6, (int8_t)-1, (int8_t)5, (int8_t)4, (int8_t)3,
          (int8_t)-1, (int8_t)2, (int8_t)1, (int8_t)0, (int8_t)-1, (int8_t)11,
          (int8_t)10, (int8_t)9, (int8_t)-1, (int8_t)8, (int8_t)7, (int8_t)6,
          (int8_t)-1, (int8_t)5, (int8_t)4, (int8_t)3, (int8_t)-1, (int8_t)2,
          (int8_t)1, (int8_t)0));
  return libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients1,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_REJECTION_SAMPLE_LESS_THAN_FIELD_MODULUS_BYTESTREAM_TO_POTENTIAL_COEFFICIENTS_COEFFICIENT_MASK));
}

static const uint8_t
    libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE
        [16U][16U] = {{255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U},
                      {4U, 5U, 6U, 7U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U},
                      {8U, 9U, 10U, 11U, 255U, 255U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 8U, 9U, 10U, 11U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U},
                      {4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 255U,
                       255U, 255U, 255U},
                      {12U, 13U, 14U, 15U, 255U, 255U, 255U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 12U, 13U, 14U, 15U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U},
                      {4U, 5U, 6U, 7U, 12U, 13U, 14U, 15U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 12U, 13U, 14U, 15U, 255U,
                       255U, 255U, 255U},
                      {8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 255U, 255U, 255U,
                       255U, 255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U,
                       255U, 255U, 255U, 255U},
                      {4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U,
                       255U, 255U, 255U, 255U},
                      {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U,
                       13U, 14U, 15U}};

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_field_modulus_sample(
    Eurydice_slice input, Eurydice_slice output) {
  __m256i field_modulus = libcrux_intrinsics_avx2_mm256_set1_epi32(
      LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  __m256i potential_coefficients =
      libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_field_modulus_bytestream_to_potential_coefficients(
          input);
  __m256i compare_with_field_modulus =
      libcrux_intrinsics_avx2_mm256_cmpgt_epi32(field_modulus,
                                                potential_coefficients);
  int32_t good = libcrux_intrinsics_avx2_mm256_movemask_ps(
      libcrux_intrinsics_avx2_mm256_castsi256_ps(compare_with_field_modulus));
  int32_t good_lower_half = good & (int32_t)15;
  int32_t good_upper_half = good >> 4U;
  uint8_t lower_shuffles[16U];
  memcpy(lower_shuffles,
         libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE[(
             size_t)good_lower_half],
         (size_t)16U * sizeof(uint8_t));
  __m128i lower_shuffles0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, lower_shuffles, uint8_t));
  __m128i lower_coefficients =
      libcrux_intrinsics_avx2_mm256_castsi256_si128(potential_coefficients);
  __m128i lower_coefficients0 = libcrux_intrinsics_avx2_mm_shuffle_epi8(
      lower_coefficients, lower_shuffles0);
  libcrux_intrinsics_avx2_mm_storeu_si128_i32(
      Eurydice_slice_subslice2(output, (size_t)0U, (size_t)4U, int32_t),
      lower_coefficients0);
  size_t sampled_count = (size_t)core_num__i32_2__count_ones(good_lower_half);
  uint8_t upper_shuffles[16U];
  memcpy(upper_shuffles,
         libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE[(
             size_t)good_upper_half],
         (size_t)16U * sizeof(uint8_t));
  __m128i upper_shuffles0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, upper_shuffles, uint8_t));
  __m128i upper_coefficients = libcrux_intrinsics_avx2_mm256_extracti128_si256(
      (int32_t)1, potential_coefficients, __m128i);
  __m128i upper_coefficients0 = libcrux_intrinsics_avx2_mm_shuffle_epi8(
      upper_coefficients, upper_shuffles0);
  libcrux_intrinsics_avx2_mm_storeu_si128_i32(
      Eurydice_slice_subslice2(output, sampled_count,
                               sampled_count + (size_t)4U, int32_t),
      upper_coefficients0);
  size_t uu____0 = sampled_count;
  return uu____0 + (size_t)core_num__i32_2__count_ones(good_upper_half);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_field_modulus_a2(
    Eurydice_slice randomness, Eurydice_slice out) {
  return libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_field_modulus_sample(
      randomness, out);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_ERROR_DESERIALIZE_TO_UNSIGNED_WHEN_ETA_IS_2_COEFFICIENT_MASK \
  (((int32_t)1 << 3U) - (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_error_deserialize_to_unsigned_when_eta_is_2(
    Eurydice_slice bytes) {
  __m256i bytes_in_simd_unit = libcrux_intrinsics_avx2_mm256_set_epi32(
      (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *)
              << 8U |
          (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *)
              << 8U |
          (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *));
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_srlv_epi32(
      bytes_in_simd_unit, libcrux_intrinsics_avx2_mm256_set_epi32(
                              (int32_t)5, (int32_t)2, (int32_t)7, (int32_t)4,
                              (int32_t)1, (int32_t)6, (int32_t)3, (int32_t)0));
  return libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_ERROR_DESERIALIZE_TO_UNSIGNED_WHEN_ETA_IS_2_COEFFICIENT_MASK));
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_ERROR_DESERIALIZE_TO_UNSIGNED_WHEN_ETA_IS_4_COEFFICIENT_MASK \
  (((int32_t)1 << 4U) - (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_error_deserialize_to_unsigned_when_eta_is_4(
    Eurydice_slice bytes) {
  __m256i bytes_in_simd_unit = libcrux_intrinsics_avx2_mm256_set_epi32(
      (int32_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *),
      (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *));
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_srlv_epi32(
      bytes_in_simd_unit, libcrux_intrinsics_avx2_mm256_set_epi32(
                              (int32_t)4, (int32_t)0, (int32_t)4, (int32_t)0,
                              (int32_t)4, (int32_t)0, (int32_t)4, (int32_t)0));
  return libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_ERROR_DESERIALIZE_TO_UNSIGNED_WHEN_ETA_IS_4_COEFFICIENT_MASK));
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.avx2.encoding.error.deserialize_to_unsigned with const
generics
- ETA= 4
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_error_deserialize_to_unsigned_ac(
    Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_avx2_encoding_error_deserialize_to_unsigned_when_eta_is_4(
      serialized);
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.avx2.rejection_sample.less_than_eta.shift_interval with
const generics
- ETA= 2
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_shift_interval_fd(
    __m256i coefficients) {
  __m256i uu____0;
  __m256i quotient = libcrux_intrinsics_avx2_mm256_mullo_epi32(
      coefficients, libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)26));
  __m256i quotient0 =
      libcrux_intrinsics_avx2_mm256_srai_epi32((int32_t)7, quotient, __m256i);
  __m256i quotient1 = libcrux_intrinsics_avx2_mm256_mullo_epi32(
      quotient0, libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)5));
  __m256i coefficients_mod_5 =
      libcrux_intrinsics_avx2_mm256_sub_epi32(coefficients, quotient1);
  uu____0 = libcrux_intrinsics_avx2_mm256_sub_epi32(
      libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)(size_t)2U),
      coefficients_mod_5);
  return uu____0;
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.avx2.rejection_sample.less_than_eta.sample with const
generics
- ETA= 2
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_sample_fd(
    Eurydice_slice input, Eurydice_slice output) {
  __m256i potential_coefficients =
      libcrux_ml_dsa_simd_avx2_encoding_error_deserialize_to_unsigned_ac(input);
  int32_t interval_boundary;
  interval_boundary = (int32_t)15;
  __m256i compare_with_interval_boundary =
      libcrux_intrinsics_avx2_mm256_cmpgt_epi32(
          libcrux_intrinsics_avx2_mm256_set1_epi32(interval_boundary),
          potential_coefficients);
  int32_t good = libcrux_intrinsics_avx2_mm256_movemask_ps(
      libcrux_intrinsics_avx2_mm256_castsi256_ps(
          compare_with_interval_boundary));
  int32_t good_lower_half = good & (int32_t)15;
  int32_t good_upper_half = good >> 4U;
  __m256i shifted =
      libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_shift_interval_fd(
          potential_coefficients);
  uint8_t lower_shuffles[16U];
  memcpy(lower_shuffles,
         libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE[(
             size_t)good_lower_half],
         (size_t)16U * sizeof(uint8_t));
  __m128i lower_shuffles0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, lower_shuffles, uint8_t));
  __m128i lower_coefficients =
      libcrux_intrinsics_avx2_mm256_castsi256_si128(shifted);
  __m128i lower_coefficients0 = libcrux_intrinsics_avx2_mm_shuffle_epi8(
      lower_coefficients, lower_shuffles0);
  libcrux_intrinsics_avx2_mm_storeu_si128_i32(
      Eurydice_slice_subslice2(output, (size_t)0U, (size_t)4U, int32_t),
      lower_coefficients0);
  size_t sampled_count = (size_t)core_num__i32_2__count_ones(good_lower_half);
  uint8_t upper_shuffles[16U];
  memcpy(upper_shuffles,
         libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE[(
             size_t)good_upper_half],
         (size_t)16U * sizeof(uint8_t));
  __m128i upper_shuffles0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, upper_shuffles, uint8_t));
  __m128i upper_coefficients = libcrux_intrinsics_avx2_mm256_extracti128_si256(
      (int32_t)1, shifted, __m128i);
  __m128i upper_coefficients0 = libcrux_intrinsics_avx2_mm_shuffle_epi8(
      upper_coefficients, upper_shuffles0);
  libcrux_intrinsics_avx2_mm_storeu_si128_i32(
      Eurydice_slice_subslice2(output, sampled_count,
                               sampled_count + (size_t)4U, int32_t),
      upper_coefficients0);
  size_t uu____0 = sampled_count;
  return uu____0 + (size_t)core_num__i32_2__count_ones(good_upper_half);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_equals_2_a2(
    Eurydice_slice randomness, Eurydice_slice out) {
  return libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_sample_fd(
      randomness, out);
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.avx2.rejection_sample.less_than_eta.shift_interval with
const generics
- ETA= 4
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_shift_interval_ac(
    __m256i coefficients) {
  return libcrux_intrinsics_avx2_mm256_sub_epi32(
      libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)(size_t)4U),
      coefficients);
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.avx2.rejection_sample.less_than_eta.sample with const
generics
- ETA= 4
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_sample_ac(
    Eurydice_slice input, Eurydice_slice output) {
  __m256i potential_coefficients =
      libcrux_ml_dsa_simd_avx2_encoding_error_deserialize_to_unsigned_ac(input);
  int32_t interval_boundary;
  interval_boundary = (int32_t)9;
  __m256i compare_with_interval_boundary =
      libcrux_intrinsics_avx2_mm256_cmpgt_epi32(
          libcrux_intrinsics_avx2_mm256_set1_epi32(interval_boundary),
          potential_coefficients);
  int32_t good = libcrux_intrinsics_avx2_mm256_movemask_ps(
      libcrux_intrinsics_avx2_mm256_castsi256_ps(
          compare_with_interval_boundary));
  int32_t good_lower_half = good & (int32_t)15;
  int32_t good_upper_half = good >> 4U;
  __m256i shifted =
      libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_shift_interval_ac(
          potential_coefficients);
  uint8_t lower_shuffles[16U];
  memcpy(lower_shuffles,
         libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE[(
             size_t)good_lower_half],
         (size_t)16U * sizeof(uint8_t));
  __m128i lower_shuffles0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, lower_shuffles, uint8_t));
  __m128i lower_coefficients =
      libcrux_intrinsics_avx2_mm256_castsi256_si128(shifted);
  __m128i lower_coefficients0 = libcrux_intrinsics_avx2_mm_shuffle_epi8(
      lower_coefficients, lower_shuffles0);
  libcrux_intrinsics_avx2_mm_storeu_si128_i32(
      Eurydice_slice_subslice2(output, (size_t)0U, (size_t)4U, int32_t),
      lower_coefficients0);
  size_t sampled_count = (size_t)core_num__i32_2__count_ones(good_lower_half);
  uint8_t upper_shuffles[16U];
  memcpy(upper_shuffles,
         libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_SHUFFLE_TABLE[(
             size_t)good_upper_half],
         (size_t)16U * sizeof(uint8_t));
  __m128i upper_shuffles0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, upper_shuffles, uint8_t));
  __m128i upper_coefficients = libcrux_intrinsics_avx2_mm256_extracti128_si256(
      (int32_t)1, shifted, __m128i);
  __m128i upper_coefficients0 = libcrux_intrinsics_avx2_mm_shuffle_epi8(
      upper_coefficients, upper_shuffles0);
  libcrux_intrinsics_avx2_mm_storeu_si128_i32(
      Eurydice_slice_subslice2(output, sampled_count,
                               sampled_count + (size_t)4U, int32_t),
      upper_coefficients0);
  size_t uu____0 = sampled_count;
  return uu____0 + (size_t)core_num__i32_2__count_ones(good_upper_half);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_equals_4_a2(
    Eurydice_slice randomness, Eurydice_slice out) {
  return libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_sample_ac(
      randomness, out);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 \
  ((int32_t)1 << 17U)

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 \
  ((int32_t)1 << 19U)

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 \
  ((int32_t)1 << 17U)

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_MASK \
  ((LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1                  \
    << 1U) -                                                                                             \
   (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_gamma1_deserialize_when_gamma1_is_2_pow_17(
    Eurydice_slice serialized) {
  __m128i serialized_lower = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_slice_subslice2(serialized, (size_t)0U, (size_t)16U, uint8_t));
  __m128i serialized_upper = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_slice_subslice2(serialized, (size_t)2U, (size_t)18U, uint8_t));
  __m256i serialized0 = libcrux_intrinsics_avx2_mm256_set_m128i(
      serialized_upper, serialized_lower);
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_shuffle_epi8(
      serialized0,
      libcrux_intrinsics_avx2_mm256_set_epi8(
          (int8_t)-1, (int8_t)15, (int8_t)14, (int8_t)13, (int8_t)-1,
          (int8_t)13, (int8_t)12, (int8_t)11, (int8_t)-1, (int8_t)11,
          (int8_t)10, (int8_t)9, (int8_t)-1, (int8_t)9, (int8_t)8, (int8_t)7,
          (int8_t)-1, (int8_t)8, (int8_t)7, (int8_t)6, (int8_t)-1, (int8_t)6,
          (int8_t)5, (int8_t)4, (int8_t)-1, (int8_t)4, (int8_t)3, (int8_t)2,
          (int8_t)-1, (int8_t)2, (int8_t)1, (int8_t)0));
  __m256i coefficients0 = libcrux_intrinsics_avx2_mm256_srlv_epi32(
      coefficients, libcrux_intrinsics_avx2_mm256_set_epi32(
                        (int32_t)6, (int32_t)4, (int32_t)2, (int32_t)0,
                        (int32_t)6, (int32_t)4, (int32_t)2, (int32_t)0));
  __m256i coefficients1 = libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients0,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_MASK));
  return libcrux_intrinsics_avx2_mm256_sub_epi32(
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1),
      coefficients1);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 \
  ((int32_t)1 << 19U)

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1_TIMES_2_MASK \
  ((LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1                  \
    << 1U) -                                                                                             \
   (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_gamma1_deserialize_when_gamma1_is_2_pow_19(
    Eurydice_slice serialized) {
  __m128i serialized_lower = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_slice_subslice2(serialized, (size_t)0U, (size_t)16U, uint8_t));
  __m128i serialized_upper = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_slice_subslice2(serialized, (size_t)4U, (size_t)20U, uint8_t));
  __m256i serialized0 = libcrux_intrinsics_avx2_mm256_set_m128i(
      serialized_upper, serialized_lower);
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_shuffle_epi8(
      serialized0,
      libcrux_intrinsics_avx2_mm256_set_epi8(
          (int8_t)-1, (int8_t)15, (int8_t)14, (int8_t)13, (int8_t)-1,
          (int8_t)13, (int8_t)12, (int8_t)11, (int8_t)-1, (int8_t)10, (int8_t)9,
          (int8_t)8, (int8_t)-1, (int8_t)8, (int8_t)7, (int8_t)6, (int8_t)-1,
          (int8_t)9, (int8_t)8, (int8_t)7, (int8_t)-1, (int8_t)7, (int8_t)6,
          (int8_t)5, (int8_t)-1, (int8_t)4, (int8_t)3, (int8_t)2, (int8_t)-1,
          (int8_t)2, (int8_t)1, (int8_t)0));
  __m256i coefficients0 = libcrux_intrinsics_avx2_mm256_srlv_epi32(
      coefficients, libcrux_intrinsics_avx2_mm256_set_epi32(
                        (int32_t)4, (int32_t)0, (int32_t)4, (int32_t)0,
                        (int32_t)4, (int32_t)0, (int32_t)4, (int32_t)0));
  __m256i coefficients1 = libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients0,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1_TIMES_2_MASK));
  return libcrux_intrinsics_avx2_mm256_sub_epi32(
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1),
      coefficients1);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA \
  ((int32_t)2)

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_4_ETA \
  ((int32_t)4)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_t0_change_interval(__m256i simd_unit) {
  __m256i interval_end = libcrux_intrinsics_avx2_mm256_set1_epi32(
      (int32_t)1
      << (uint32_t)(LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T -
                    (size_t)1U));
  return libcrux_intrinsics_avx2_mm256_sub_epi32(interval_end, simd_unit);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_encoding_t0_serialize(
    __m256i simd_unit, uint8_t ret[13U]) {
  uint8_t serialized[16U] = {0U};
  __m256i simd_unit0 =
      libcrux_ml_dsa_simd_avx2_encoding_t0_change_interval(simd_unit);
  __m256i adjacent_2_combined = libcrux_intrinsics_avx2_mm256_sllv_epi32(
      simd_unit0, libcrux_intrinsics_avx2_mm256_set_epi32(
                      (int32_t)0, (int32_t)19, (int32_t)0, (int32_t)19,
                      (int32_t)0, (int32_t)19, (int32_t)0, (int32_t)19));
  __m256i adjacent_2_combined0 = libcrux_intrinsics_avx2_mm256_srli_epi64(
      (int32_t)19, adjacent_2_combined, __m256i);
  __m256i adjacent_4_combined =
      libcrux_intrinsics_avx2_mm256_permutevar8x32_epi32(
          adjacent_2_combined0,
          libcrux_intrinsics_avx2_mm256_set_epi32(
              (int32_t)0, (int32_t)0, (int32_t)0, (int32_t)0, (int32_t)6,
              (int32_t)4, (int32_t)2, (int32_t)0));
  __m256i adjacent_4_combined0 = libcrux_intrinsics_avx2_mm256_sllv_epi32(
      adjacent_4_combined, libcrux_intrinsics_avx2_mm256_set_epi32(
                               (int32_t)0, (int32_t)6, (int32_t)0, (int32_t)6,
                               (int32_t)0, (int32_t)6, (int32_t)0, (int32_t)6));
  __m256i adjacent_4_combined1 = libcrux_intrinsics_avx2_mm256_srli_epi64(
      (int32_t)6, adjacent_4_combined0, __m256i);
  __m256i second_4_combined = libcrux_intrinsics_avx2_mm256_bsrli_epi128(
      (int32_t)8, adjacent_4_combined1, __m256i);
  __m256i least_12_bits_shifted_up = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)52, second_4_combined, __m256i);
  __m256i bits_sequential = libcrux_intrinsics_avx2_mm256_add_epi64(
      adjacent_4_combined1, least_12_bits_shifted_up);
  __m256i bits_sequential0 = libcrux_intrinsics_avx2_mm256_srlv_epi64(
      bits_sequential, libcrux_intrinsics_avx2_mm256_set_epi64x(
                           (int64_t)0, (int64_t)0, (int64_t)12, (int64_t)0));
  __m128i bits_sequential1 =
      libcrux_intrinsics_avx2_mm256_castsi256_si128(bits_sequential0);
  libcrux_intrinsics_avx2_mm_storeu_bytes_si128(
      Eurydice_array_to_slice((size_t)16U, serialized, uint8_t),
      bits_sequential1);
  uint8_t ret0[13U];
  Result_b0 dst;
  Eurydice_slice_to_array2(
      &dst,
      Eurydice_array_to_subslice2(serialized, (size_t)0U, (size_t)13U, uint8_t),
      Eurydice_slice, uint8_t[13U]);
  unwrap_26_23(dst, ret0);
  memcpy(ret, ret0, (size_t)13U * sizeof(uint8_t));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_t0_serialize_a2(
    __m256i simd_unit, uint8_t ret[13U]) {
  libcrux_ml_dsa_simd_avx2_encoding_t0_serialize(simd_unit, ret);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_T0_DESERIALIZE_COEFFICIENT_MASK \
  (((int32_t)1 << 13U) - (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_t0_deserialize(Eurydice_slice serialized) {
  uint8_t serialized_extended[16U] = {0U};
  Eurydice_slice_copy(
      Eurydice_array_to_subslice2(serialized_extended, (size_t)0U, (size_t)13U,
                                  uint8_t),
      serialized, uint8_t);
  __m128i serialized0 = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, serialized_extended, uint8_t));
  __m256i serialized1 =
      libcrux_intrinsics_avx2_mm256_set_m128i(serialized0, serialized0);
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_shuffle_epi8(
      serialized1,
      libcrux_intrinsics_avx2_mm256_set_epi8(
          (int8_t)-1, (int8_t)-1, (int8_t)12, (int8_t)11, (int8_t)-1,
          (int8_t)11, (int8_t)10, (int8_t)9, (int8_t)-1, (int8_t)-1, (int8_t)9,
          (int8_t)8, (int8_t)-1, (int8_t)8, (int8_t)7, (int8_t)6, (int8_t)-1,
          (int8_t)6, (int8_t)5, (int8_t)4, (int8_t)-1, (int8_t)-1, (int8_t)4,
          (int8_t)3, (int8_t)-1, (int8_t)3, (int8_t)2, (int8_t)1, (int8_t)-1,
          (int8_t)-1, (int8_t)1, (int8_t)0));
  __m256i coefficients0 = libcrux_intrinsics_avx2_mm256_srlv_epi32(
      coefficients, libcrux_intrinsics_avx2_mm256_set_epi32(
                        (int32_t)3, (int32_t)6, (int32_t)1, (int32_t)4,
                        (int32_t)7, (int32_t)2, (int32_t)5, (int32_t)0));
  __m256i coefficients1 = libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients0,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_T0_DESERIALIZE_COEFFICIENT_MASK));
  return libcrux_ml_dsa_simd_avx2_encoding_t0_change_interval(coefficients1);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_t0_deserialize_a2(Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_avx2_encoding_t0_deserialize(serialized);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_encoding_t1_serialize(
    __m256i simd_unit, uint8_t ret[10U]) {
  uint8_t serialized[24U] = {0U};
  __m256i adjacent_2_combined = libcrux_intrinsics_avx2_mm256_sllv_epi32(
      simd_unit, libcrux_intrinsics_avx2_mm256_set_epi32(
                     (int32_t)0, (int32_t)22, (int32_t)0, (int32_t)22,
                     (int32_t)0, (int32_t)22, (int32_t)0, (int32_t)22));
  __m256i adjacent_2_combined0 = libcrux_intrinsics_avx2_mm256_srli_epi64(
      (int32_t)22, adjacent_2_combined, __m256i);
  __m256i adjacent_4_combined =
      libcrux_intrinsics_avx2_mm256_permutevar8x32_epi32(
          adjacent_2_combined0,
          libcrux_intrinsics_avx2_mm256_set_epi32(
              (int32_t)0, (int32_t)0, (int32_t)6, (int32_t)4, (int32_t)0,
              (int32_t)0, (int32_t)2, (int32_t)0));
  __m256i adjacent_4_combined0 = libcrux_intrinsics_avx2_mm256_sllv_epi32(
      adjacent_4_combined,
      libcrux_intrinsics_avx2_mm256_set_epi32(
          (int32_t)0, (int32_t)12, (int32_t)0, (int32_t)12, (int32_t)0,
          (int32_t)12, (int32_t)0, (int32_t)12));
  __m256i adjacent_4_combined1 = libcrux_intrinsics_avx2_mm256_srli_epi64(
      (int32_t)12, adjacent_4_combined0, __m256i);
  __m128i lower_4 =
      libcrux_intrinsics_avx2_mm256_castsi256_si128(adjacent_4_combined1);
  libcrux_intrinsics_avx2_mm_storeu_bytes_si128(
      Eurydice_array_to_subslice2(serialized, (size_t)0U, (size_t)16U, uint8_t),
      lower_4);
  __m128i upper_4 = libcrux_intrinsics_avx2_mm256_extracti128_si256(
      (int32_t)1, adjacent_4_combined1, __m128i);
  libcrux_intrinsics_avx2_mm_storeu_bytes_si128(
      Eurydice_array_to_subslice2(serialized, (size_t)5U, (size_t)21U, uint8_t),
      upper_4);
  uint8_t ret0[10U];
  Result_9d dst;
  Eurydice_slice_to_array2(
      &dst,
      Eurydice_array_to_subslice2(serialized, (size_t)0U, (size_t)10U, uint8_t),
      Eurydice_slice, uint8_t[10U]);
  unwrap_26_ce(dst, ret0);
  memcpy(ret, ret0, (size_t)10U * sizeof(uint8_t));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_t1_serialize_a2(
    __m256i simd_unit, uint8_t ret[10U]) {
  libcrux_ml_dsa_simd_avx2_encoding_t1_serialize(simd_unit, ret);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_T1_DESERIALIZE_COEFFICIENT_MASK \
  (((int32_t)1 << 10U) - (int32_t)1)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_encoding_t1_deserialize(Eurydice_slice bytes) {
  uint8_t bytes_extended[16U] = {0U};
  Eurydice_slice_copy(Eurydice_array_to_subslice2(bytes_extended, (size_t)0U,
                                                  (size_t)10U, uint8_t),
                      bytes, uint8_t);
  __m128i bytes_loaded = libcrux_intrinsics_avx2_mm_loadu_si128(
      Eurydice_array_to_slice((size_t)16U, bytes_extended, uint8_t));
  __m256i bytes_loaded0 =
      libcrux_intrinsics_avx2_mm256_set_m128i(bytes_loaded, bytes_loaded);
  __m256i coefficients = libcrux_intrinsics_avx2_mm256_shuffle_epi8(
      bytes_loaded0,
      libcrux_intrinsics_avx2_mm256_set_epi8(
          (int8_t)-1, (int8_t)-1, (int8_t)9, (int8_t)8, (int8_t)-1, (int8_t)-1,
          (int8_t)8, (int8_t)7, (int8_t)-1, (int8_t)-1, (int8_t)7, (int8_t)6,
          (int8_t)-1, (int8_t)-1, (int8_t)6, (int8_t)5, (int8_t)-1, (int8_t)-1,
          (int8_t)4, (int8_t)3, (int8_t)-1, (int8_t)-1, (int8_t)3, (int8_t)2,
          (int8_t)-1, (int8_t)-1, (int8_t)2, (int8_t)1, (int8_t)-1, (int8_t)-1,
          (int8_t)1, (int8_t)0));
  __m256i coefficients0 = libcrux_intrinsics_avx2_mm256_srlv_epi32(
      coefficients, libcrux_intrinsics_avx2_mm256_set_epi32(
                        (int32_t)6, (int32_t)4, (int32_t)2, (int32_t)0,
                        (int32_t)6, (int32_t)4, (int32_t)2, (int32_t)0));
  return libcrux_intrinsics_avx2_mm256_and_si256(
      coefficients0,
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          LIBCRUX_ML_DSA_SIMD_AVX2_ENCODING_T1_DESERIALIZE_COEFFICIENT_MASK));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_t1_deserialize_a2(Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_avx2_encoding_t1_deserialize(serialized);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7 \
  ((size_t)2U * LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT)

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
    __m256i *re, size_t index, __m256i zeta, size_t step_by,
    __m256i field_modulus, __m256i inverse_of_modulus_mod_montgomery_r) {
  __m256i prod02 =
      libcrux_intrinsics_avx2_mm256_mul_epi32(re[index + step_by], zeta);
  __m256i prod13 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245,
                                                  re[index + step_by], __m256i),
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, zeta, __m256i));
  __m256i k02 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      prod02, inverse_of_modulus_mod_montgomery_r);
  __m256i k13 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      prod13, inverse_of_modulus_mod_montgomery_r);
  __m256i c02 = libcrux_intrinsics_avx2_mm256_mul_epi32(k02, field_modulus);
  __m256i c13 = libcrux_intrinsics_avx2_mm256_mul_epi32(k13, field_modulus);
  __m256i res02 = libcrux_intrinsics_avx2_mm256_sub_epi32(prod02, c02);
  __m256i res13 = libcrux_intrinsics_avx2_mm256_sub_epi32(prod13, c13);
  __m256i res02_shifted =
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, res02, __m256i);
  __m256i t = libcrux_intrinsics_avx2_mm256_blend_epi32(
      (int32_t)170, res02_shifted, res13, __m256i);
  re[index + step_by] =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[index], t);
  re[index] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[index], t);
}

#define LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6 \
  (((size_t)1U << 6U) / LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT)

/**
 This is equivalent to the pqclean 0 and 1

 This does 32 Montgomery multiplications (192 multiplications).
 This is the same as in pqclean. The only difference is locality of registers.
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6(
    __m256i *re) {
  __m256i field_modulus = libcrux_intrinsics_avx2_mm256_set1_epi32(
      LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  __m256i inverse_of_modulus_mod_montgomery_r =
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          (int32_t)
              LIBCRUX_ML_DSA_SIMD_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R);
  __m256i zeta7 = libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)25847);
  __m256i zeta60 = libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)-2608894);
  __m256i zeta61 = libcrux_intrinsics_avx2_mm256_set1_epi32((int32_t)-518909);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U + (size_t)1U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U + (size_t)2U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U + (size_t)3U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)8U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)8U + (size_t)1U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)8U + (size_t)2U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)8U + (size_t)3U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U + (size_t)1U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U + (size_t)2U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)0U + (size_t)3U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)16U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)16U + (size_t)1U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)16U + (size_t)2U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)16U + (size_t)3U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U + (size_t)1U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U + (size_t)2U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U + (size_t)3U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)12U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)12U + (size_t)1U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)12U + (size_t)2U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)12U + (size_t)3U, zeta7,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_7,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U + (size_t)1U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U + (size_t)2U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)4U + (size_t)3U, zeta60,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)20U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)20U + (size_t)1U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)20U + (size_t)2U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6_mul(
      re, (size_t)20U + (size_t)3U, zeta61,
      LIBCRUX_ML_DSA_SIMD_AVX2_NTT_NTT_AT_LAYER_7_AND_6_STEP_BY_6,
      field_modulus, inverse_of_modulus_mod_montgomery_r);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.ntt.ntt_at_layer_5_to_3.round
with const generics
- STEP= 32
- STEP_BY= 4
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_f6(__m256i *re,
                                                          size_t index,
                                                          int32_t zeta) {
  __m256i rhs = libcrux_intrinsics_avx2_mm256_set1_epi32(zeta);
  size_t offset = index * (size_t)32U * (size_t)2U /
                  LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT;
  for (size_t i = offset; i < offset + (size_t)4U; i++) {
    size_t j = i;
    __m256i t = libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
        re[j + (size_t)4U], rhs);
    re[j + (size_t)4U] = libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j], t);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], t);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.ntt.ntt_at_layer_5_to_3.round
with const generics
- STEP= 16
- STEP_BY= 2
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(__m256i *re,
                                                          size_t index,
                                                          int32_t zeta) {
  __m256i rhs = libcrux_intrinsics_avx2_mm256_set1_epi32(zeta);
  size_t offset = index * (size_t)16U * (size_t)2U /
                  LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT;
  for (size_t i = offset; i < offset + (size_t)2U; i++) {
    size_t j = i;
    __m256i t = libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
        re[j + (size_t)2U], rhs);
    re[j + (size_t)2U] = libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j], t);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], t);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.ntt.ntt_at_layer_5_to_3.round
with const generics
- STEP= 8
- STEP_BY= 1
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(__m256i *re,
                                                          size_t index,
                                                          int32_t zeta) {
  __m256i rhs = libcrux_intrinsics_avx2_mm256_set1_epi32(zeta);
  size_t offset = index * (size_t)8U * (size_t)2U /
                  LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT;
  for (size_t i = offset; i < offset + (size_t)1U; i++) {
    size_t j = i;
    __m256i t = libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
        re[j + (size_t)1U], rhs);
    re[j + (size_t)1U] = libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j], t);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], t);
  }
}

/**
 Layer 5, 4, 3

 Each layer does 16 Montgomery multiplications -> 3*16 = 48 total
 pqclean does 4 * 4 on each layer -> 48 total | plus 4 * 4 shuffles every time
 (48)
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_f6(re, (size_t)0U,
                                                            (int32_t)237124);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_f6(re, (size_t)1U,
                                                            (int32_t)-777960);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_f6(re, (size_t)2U,
                                                            (int32_t)-876248);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_f6(re, (size_t)3U,
                                                            (int32_t)466468);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)0U,
                                                            (int32_t)1826347);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)1U,
                                                            (int32_t)2353451);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)2U,
                                                            (int32_t)-359251);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)3U,
                                                            (int32_t)-2091905);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)4U,
                                                            (int32_t)3119733);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)5U,
                                                            (int32_t)-2884855);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)6U,
                                                            (int32_t)3111497);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_90(re, (size_t)7U,
                                                            (int32_t)2680103);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)0U,
                                                            (int32_t)2725464);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)1U,
                                                            (int32_t)1024112);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)2U,
                                                            (int32_t)-1079900);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)3U,
                                                            (int32_t)3585928);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)4U,
                                                            (int32_t)-549488);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)5U,
                                                            (int32_t)-1119584);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)6U,
                                                            (int32_t)2619752);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)7U,
                                                            (int32_t)-2108549);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)8U,
                                                            (int32_t)-2118186);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)9U,
                                                            (int32_t)-3859737);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)10U,
                                                            (int32_t)-1399561);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)11U,
                                                            (int32_t)-3277672);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)12U,
                                                            (int32_t)1757237);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)13U,
                                                            (int32_t)-19422);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)14U,
                                                            (int32_t)4010497);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3_round_7b(re, (size_t)15U,
                                                            (int32_t)280005);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_ntt_butterfly_8(__m256i a, __m256i b, int32_t zeta0,
                                         int32_t zeta1) {
  __m256i summands = libcrux_intrinsics_avx2_mm256_set_m128i(
      libcrux_intrinsics_avx2_mm256_castsi256_si128(b),
      libcrux_intrinsics_avx2_mm256_castsi256_si128(a));
  __m256i zeta_multiplicands = libcrux_intrinsics_avx2_mm256_permute2x128_si256(
      (int32_t)19, b, a, __m256i);
  __m256i zetas = libcrux_intrinsics_avx2_mm256_set_epi32(
      zeta1, zeta1, zeta1, zeta1, zeta0, zeta0, zeta0, zeta0);
  __m256i zeta_products =
      libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
          zeta_multiplicands, zetas);
  __m256i add_terms =
      libcrux_ml_dsa_simd_avx2_arithmetic_add(summands, zeta_products);
  __m256i sub_terms =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(summands, zeta_products);
  __m256i a_out = libcrux_intrinsics_avx2_mm256_set_m128i(
      libcrux_intrinsics_avx2_mm256_castsi256_si128(sub_terms),
      libcrux_intrinsics_avx2_mm256_castsi256_si128(add_terms));
  __m256i b_out = libcrux_intrinsics_avx2_mm256_permute2x128_si256(
      (int32_t)19, sub_terms, add_terms, __m256i);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = a_out, .snd = b_out});
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
    __m256i *re, size_t index, int32_t zeta_0, int32_t zeta_1) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_ntt_butterfly_8(
          re[index], re[index + (size_t)1U], zeta_0, zeta_1);
  __m256i a = uu____0.fst;
  __m256i b = uu____0.snd;
  re[index] = a;
  re[index + (size_t)1U] = b;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2(__m256i *re) {
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)0U, (int32_t)2706023, (int32_t)95776);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)2U, (int32_t)3077325, (int32_t)3530437);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)4U, (int32_t)-1661693, (int32_t)-3592148);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)6U, (int32_t)-2537516, (int32_t)3915439);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)8U, (int32_t)-3861115, (int32_t)-3043716);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)10U, (int32_t)3574422, (int32_t)-2867647);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)12U, (int32_t)3539968, (int32_t)-300467);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)14U, (int32_t)2348700, (int32_t)-539299);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)16U, (int32_t)-1699267, (int32_t)-1643818);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)18U, (int32_t)3505694, (int32_t)-3821735);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)20U, (int32_t)3507263, (int32_t)-2140649);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)22U, (int32_t)-1600420, (int32_t)3699596);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)24U, (int32_t)811944, (int32_t)531354);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)26U, (int32_t)954230, (int32_t)3881043);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)28U, (int32_t)3900724, (int32_t)-2556880);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2_round(
      re, (size_t)30U, (int32_t)2071892, (int32_t)-2797779);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_ntt_butterfly_4(__m256i a, __m256i b, int32_t zeta_a0,
                                         int32_t zeta_a1, int32_t zeta_b0,
                                         int32_t zeta_b1) {
  __m256i summands = libcrux_intrinsics_avx2_mm256_unpacklo_epi64(a, b);
  __m256i zeta_multiplicands =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(a, b);
  __m256i zetas = libcrux_intrinsics_avx2_mm256_set_epi32(
      zeta_b1, zeta_b1, zeta_a1, zeta_a1, zeta_b0, zeta_b0, zeta_a0, zeta_a0);
  __m256i zeta_products =
      libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
          zeta_multiplicands, zetas);
  __m256i add_terms =
      libcrux_ml_dsa_simd_avx2_arithmetic_add(summands, zeta_products);
  __m256i sub_terms =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(summands, zeta_products);
  __m256i a_out =
      libcrux_intrinsics_avx2_mm256_unpacklo_epi64(add_terms, sub_terms);
  __m256i b_out =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(add_terms, sub_terms);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = a_out, .snd = b_out});
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
    __m256i *re, size_t index, int32_t zeta_0, int32_t zeta_1, int32_t zeta_2,
    int32_t zeta_3) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_ntt_butterfly_4(
          re[index], re[index + (size_t)1U], zeta_0, zeta_1, zeta_2, zeta_3);
  __m256i a = uu____0.fst;
  __m256i b = uu____0.snd;
  re[index] = a;
  re[index + (size_t)1U] = b;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1(__m256i *re) {
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)0U, (int32_t)-3930395, (int32_t)-1528703, (int32_t)-3677745,
      (int32_t)-3041255);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)2U, (int32_t)-1452451, (int32_t)3475950, (int32_t)2176455,
      (int32_t)-1585221);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)4U, (int32_t)-1257611, (int32_t)1939314, (int32_t)-4083598,
      (int32_t)-1000202);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)6U, (int32_t)-3190144, (int32_t)-3157330, (int32_t)-3632928,
      (int32_t)126922);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)8U, (int32_t)3412210, (int32_t)-983419, (int32_t)2147896,
      (int32_t)2715295);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)10U, (int32_t)-2967645, (int32_t)-3693493, (int32_t)-411027,
      (int32_t)-2477047);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)12U, (int32_t)-671102, (int32_t)-1228525, (int32_t)-22981,
      (int32_t)-1308169);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)14U, (int32_t)-381987, (int32_t)1349076, (int32_t)1852771,
      (int32_t)-1430430);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)16U, (int32_t)-3343383, (int32_t)264944, (int32_t)508951,
      (int32_t)3097992);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)18U, (int32_t)44288, (int32_t)-1100098, (int32_t)904516,
      (int32_t)3958618);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)20U, (int32_t)-3724342, (int32_t)-8578, (int32_t)1653064,
      (int32_t)-3249728);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)22U, (int32_t)2389356, (int32_t)-210977, (int32_t)759969,
      (int32_t)-1316856);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)24U, (int32_t)189548, (int32_t)-3553272, (int32_t)3159746,
      (int32_t)-1851402);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)26U, (int32_t)-2409325, (int32_t)-177440, (int32_t)1315589,
      (int32_t)1341330);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)28U, (int32_t)1285669, (int32_t)-1584928, (int32_t)-812732,
      (int32_t)-1439742);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1_round(
      re, (size_t)30U, (int32_t)-3019102, (int32_t)-3881060, (int32_t)-3628969,
      (int32_t)3839961);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_ntt_butterfly_2(__m256i a, __m256i b, int32_t zeta_a0,
                                         int32_t zeta_a1, int32_t zeta_a2,
                                         int32_t zeta_a3, int32_t zeta_b0,
                                         int32_t zeta_b1, int32_t zeta_b2,
                                         int32_t zeta_b3) {
  __m256i a_shuffled =
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)216, a, __m256i);
  __m256i b_shuffled =
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)216, b, __m256i);
  __m256i summands =
      libcrux_intrinsics_avx2_mm256_unpacklo_epi64(a_shuffled, b_shuffled);
  __m256i zeta_multiplicands =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(a_shuffled, b_shuffled);
  __m256i zetas = libcrux_intrinsics_avx2_mm256_set_epi32(
      zeta_b3, zeta_b2, zeta_a3, zeta_a2, zeta_b1, zeta_b0, zeta_a1, zeta_a0);
  __m256i zeta_products =
      libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
          zeta_multiplicands, zetas);
  __m256i add_terms =
      libcrux_ml_dsa_simd_avx2_arithmetic_add(summands, zeta_products);
  __m256i sub_terms =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(summands, zeta_products);
  __m256i a_terms_shuffled =
      libcrux_intrinsics_avx2_mm256_unpacklo_epi64(add_terms, sub_terms);
  __m256i b_terms_shuffled =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(add_terms, sub_terms);
  __m256i a_out = libcrux_intrinsics_avx2_mm256_shuffle_epi32(
      (int32_t)216, a_terms_shuffled, __m256i);
  __m256i b_out = libcrux_intrinsics_avx2_mm256_shuffle_epi32(
      (int32_t)216, b_terms_shuffled, __m256i);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = a_out, .snd = b_out});
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
    __m256i *re, size_t index, int32_t zeta_0, int32_t zeta_1, int32_t zeta_2,
    int32_t zeta_3, int32_t zeta_4, int32_t zeta_5, int32_t zeta_6,
    int32_t zeta_7) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_ntt_butterfly_2(
          re[index], re[index + (size_t)1U], zeta_0, zeta_1, zeta_2, zeta_3,
          zeta_4, zeta_5, zeta_6, zeta_7);
  __m256i a = uu____0.fst;
  __m256i b = uu____0.snd;
  re[index] = a;
  re[index + (size_t)1U] = b;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0(__m256i *re) {
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)0U, (int32_t)2091667, (int32_t)3407706, (int32_t)2316500,
      (int32_t)3817976, (int32_t)-3342478, (int32_t)2244091, (int32_t)-2446433,
      (int32_t)-3562462);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)2U, (int32_t)266997, (int32_t)2434439, (int32_t)-1235728,
      (int32_t)3513181, (int32_t)-3520352, (int32_t)-3759364, (int32_t)-1197226,
      (int32_t)-3193378);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)4U, (int32_t)900702, (int32_t)1859098, (int32_t)909542,
      (int32_t)819034, (int32_t)495491, (int32_t)-1613174, (int32_t)-43260,
      (int32_t)-522500);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)6U, (int32_t)-655327, (int32_t)-3122442, (int32_t)2031748,
      (int32_t)3207046, (int32_t)-3556995, (int32_t)-525098, (int32_t)-768622,
      (int32_t)-3595838);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)8U, (int32_t)342297, (int32_t)286988, (int32_t)-2437823,
      (int32_t)4108315, (int32_t)3437287, (int32_t)-3342277, (int32_t)1735879,
      (int32_t)203044);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)10U, (int32_t)2842341, (int32_t)2691481, (int32_t)-2590150,
      (int32_t)1265009, (int32_t)4055324, (int32_t)1247620, (int32_t)2486353,
      (int32_t)1595974);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)12U, (int32_t)-3767016, (int32_t)1250494, (int32_t)2635921,
      (int32_t)-3548272, (int32_t)-2994039, (int32_t)1869119, (int32_t)1903435,
      (int32_t)-1050970);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)14U, (int32_t)-1333058, (int32_t)1237275, (int32_t)-3318210,
      (int32_t)-1430225, (int32_t)-451100, (int32_t)1312455, (int32_t)3306115,
      (int32_t)-1962642);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)16U, (int32_t)-1279661, (int32_t)1917081, (int32_t)-2546312,
      (int32_t)-1374803, (int32_t)1500165, (int32_t)777191, (int32_t)2235880,
      (int32_t)3406031);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)18U, (int32_t)-542412, (int32_t)-2831860, (int32_t)-1671176,
      (int32_t)-1846953, (int32_t)-2584293, (int32_t)-3724270, (int32_t)594136,
      (int32_t)-3776993);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)20U, (int32_t)-2013608, (int32_t)2432395, (int32_t)2454455,
      (int32_t)-164721, (int32_t)1957272, (int32_t)3369112, (int32_t)185531,
      (int32_t)-1207385);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)22U, (int32_t)-3183426, (int32_t)162844, (int32_t)1616392,
      (int32_t)3014001, (int32_t)810149, (int32_t)1652634, (int32_t)-3694233,
      (int32_t)-1799107);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)24U, (int32_t)-3038916, (int32_t)3523897, (int32_t)3866901,
      (int32_t)269760, (int32_t)2213111, (int32_t)-975884, (int32_t)1717735,
      (int32_t)472078);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)26U, (int32_t)-426683, (int32_t)1723600, (int32_t)-1803090,
      (int32_t)1910376, (int32_t)-1667432, (int32_t)-1104333, (int32_t)-260646,
      (int32_t)-3833893);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)28U, (int32_t)-2939036, (int32_t)-2235985, (int32_t)-420899,
      (int32_t)-2286327, (int32_t)183443, (int32_t)-976891, (int32_t)1612842,
      (int32_t)-3545687);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0_round(
      re, (size_t)30U, (int32_t)-554416, (int32_t)3919660, (int32_t)-48306,
      (int32_t)-1362209, (int32_t)3937738, (int32_t)1400424, (int32_t)-846154,
      (int32_t)1976782);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_ntt_ntt(__m256i re[32U],
                                                             __m256i ret[32U]) {
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_7_and_6(re);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_5_to_3(re);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_2(re);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_1(re);
  libcrux_ml_dsa_simd_avx2_ntt_ntt_at_layer_0(re);
  memcpy(ret, re, (size_t)32U * sizeof(__m256i));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i libcrux_ml_dsa_simd_avx2_ntt_closure_a2(__m256i **state,
                                                              size_t i) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"unexpected / ill-typed projection\")\n");
  KRML_HOST_EXIT(255U);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_ntt_a2(
    __m256i simd_units[32U], __m256i ret[32U]) {
  __m256i re[32U];
  for (size_t i = (size_t)0U; i < (size_t)32U; i++) {
    re[i] = libcrux_intrinsics_avx2_mm256_setzero_si256();
  }
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_DSA_SIMD_TRAITS_SIMD_UNITS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    re[i0] = simd_units[i0];
  }
  /* Passing arrays by value in Rust generates a copy in C */
  __m256i copy_of_re[32U];
  memcpy(copy_of_re, re, (size_t)32U * sizeof(__m256i));
  __m256i result[32U];
  libcrux_ml_dsa_simd_avx2_ntt_ntt(copy_of_re, result);
  __m256i ret0[32U];
  for (size_t i = (size_t)0U; i < (size_t)32U; i++) {
    ret0[i] = KRML_EABORT(
        __m256i,
        "Eurydice error: Failure(\"unexpected / ill-typed projection\")\n");
  }
  memcpy(ret, ret0, (size_t)32U * sizeof(__m256i));
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_invntt_simd_unit_invert_ntt_at_layer_0(
    __m256i simd_unit0, __m256i simd_unit1, int32_t zeta00, int32_t zeta01,
    int32_t zeta02, int32_t zeta03, int32_t zeta10, int32_t zeta11,
    int32_t zeta12, int32_t zeta13) {
  __m256i a_shuffled0 = libcrux_intrinsics_avx2_mm256_shuffle_epi32(
      (int32_t)216, simd_unit0, __m256i);
  __m256i b_shuffled0 = libcrux_intrinsics_avx2_mm256_shuffle_epi32(
      (int32_t)216, simd_unit1, __m256i);
  __m256i lo_values =
      libcrux_intrinsics_avx2_mm256_unpacklo_epi64(a_shuffled0, b_shuffled0);
  __m256i hi_values =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(a_shuffled0, b_shuffled0);
  __m256i sums = libcrux_ml_dsa_simd_avx2_arithmetic_add(lo_values, hi_values);
  __m256i differences =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(hi_values, lo_values);
  __m256i zetas = libcrux_intrinsics_avx2_mm256_set_epi32(
      zeta13, zeta12, zeta03, zeta02, zeta11, zeta10, zeta01, zeta00);
  __m256i products = libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
      differences, zetas);
  __m256i a_shuffled =
      libcrux_intrinsics_avx2_mm256_unpacklo_epi64(sums, products);
  __m256i b_shuffled =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(sums, products);
  __m256i a = libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)216,
                                                          a_shuffled, __m256i);
  __m256i b = libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)216,
                                                          b_shuffled, __m256i);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = a, .snd = b});
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
    __m256i *re, size_t index, int32_t zeta00, int32_t zeta01, int32_t zeta02,
    int32_t zeta03, int32_t zeta10, int32_t zeta11, int32_t zeta12,
    int32_t zeta13) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_invntt_simd_unit_invert_ntt_at_layer_0(
          re[index], re[index + (size_t)1U], zeta00, zeta01, zeta02, zeta03,
          zeta10, zeta11, zeta12, zeta13);
  __m256i lhs0 = uu____0.fst;
  __m256i lhs = uu____0.snd;
  re[index] = lhs0;
  re[index + (size_t)1U] = lhs;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)0U, (int32_t)1976782, (int32_t)-846154, (int32_t)1400424,
      (int32_t)3937738, (int32_t)-1362209, (int32_t)-48306, (int32_t)3919660,
      (int32_t)-554416);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)2U, (int32_t)-3545687, (int32_t)1612842, (int32_t)-976891,
      (int32_t)183443, (int32_t)-2286327, (int32_t)-420899, (int32_t)-2235985,
      (int32_t)-2939036);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)4U, (int32_t)-3833893, (int32_t)-260646, (int32_t)-1104333,
      (int32_t)-1667432, (int32_t)1910376, (int32_t)-1803090, (int32_t)1723600,
      (int32_t)-426683);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)6U, (int32_t)472078, (int32_t)1717735, (int32_t)-975884,
      (int32_t)2213111, (int32_t)269760, (int32_t)3866901, (int32_t)3523897,
      (int32_t)-3038916);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)8U, (int32_t)-1799107, (int32_t)-3694233, (int32_t)1652634,
      (int32_t)810149, (int32_t)3014001, (int32_t)1616392, (int32_t)162844,
      (int32_t)-3183426);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)10U, (int32_t)-1207385, (int32_t)185531, (int32_t)3369112,
      (int32_t)1957272, (int32_t)-164721, (int32_t)2454455, (int32_t)2432395,
      (int32_t)-2013608);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)12U, (int32_t)-3776993, (int32_t)594136, (int32_t)-3724270,
      (int32_t)-2584293, (int32_t)-1846953, (int32_t)-1671176,
      (int32_t)-2831860, (int32_t)-542412);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)14U, (int32_t)3406031, (int32_t)2235880, (int32_t)777191,
      (int32_t)1500165, (int32_t)-1374803, (int32_t)-2546312, (int32_t)1917081,
      (int32_t)-1279661);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)16U, (int32_t)-1962642, (int32_t)3306115, (int32_t)1312455,
      (int32_t)-451100, (int32_t)-1430225, (int32_t)-3318210, (int32_t)1237275,
      (int32_t)-1333058);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)18U, (int32_t)-1050970, (int32_t)1903435, (int32_t)1869119,
      (int32_t)-2994039, (int32_t)-3548272, (int32_t)2635921, (int32_t)1250494,
      (int32_t)-3767016);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)20U, (int32_t)1595974, (int32_t)2486353, (int32_t)1247620,
      (int32_t)4055324, (int32_t)1265009, (int32_t)-2590150, (int32_t)2691481,
      (int32_t)2842341);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)22U, (int32_t)203044, (int32_t)1735879, (int32_t)-3342277,
      (int32_t)3437287, (int32_t)4108315, (int32_t)-2437823, (int32_t)286988,
      (int32_t)342297);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)24U, (int32_t)-3595838, (int32_t)-768622, (int32_t)-525098,
      (int32_t)-3556995, (int32_t)3207046, (int32_t)2031748, (int32_t)-3122442,
      (int32_t)-655327);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)26U, (int32_t)-522500, (int32_t)-43260, (int32_t)-1613174,
      (int32_t)495491, (int32_t)819034, (int32_t)909542, (int32_t)1859098,
      (int32_t)900702);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)28U, (int32_t)-3193378, (int32_t)-1197226, (int32_t)-3759364,
      (int32_t)-3520352, (int32_t)3513181, (int32_t)-1235728, (int32_t)2434439,
      (int32_t)266997);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)30U, (int32_t)-3562462, (int32_t)-2446433, (int32_t)2244091,
      (int32_t)-3342478, (int32_t)3817976, (int32_t)2316500, (int32_t)3407706,
      (int32_t)2091667);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_invntt_simd_unit_invert_ntt_at_layer_1(
    __m256i simd_unit0, __m256i simd_unit1, int32_t zeta00, int32_t zeta01,
    int32_t zeta10, int32_t zeta11) {
  __m256i lo_values =
      libcrux_intrinsics_avx2_mm256_unpacklo_epi64(simd_unit0, simd_unit1);
  __m256i hi_values =
      libcrux_intrinsics_avx2_mm256_unpackhi_epi64(simd_unit0, simd_unit1);
  __m256i sums = libcrux_ml_dsa_simd_avx2_arithmetic_add(lo_values, hi_values);
  __m256i differences =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(hi_values, lo_values);
  __m256i zetas = libcrux_intrinsics_avx2_mm256_set_epi32(
      zeta11, zeta11, zeta01, zeta01, zeta10, zeta10, zeta00, zeta00);
  __m256i products = libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
      differences, zetas);
  __m256i a = libcrux_intrinsics_avx2_mm256_unpacklo_epi64(sums, products);
  __m256i b = libcrux_intrinsics_avx2_mm256_unpackhi_epi64(sums, products);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = a, .snd = b});
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
    __m256i *re, size_t index, int32_t zeta_00, int32_t zeta_01,
    int32_t zeta_10, int32_t zeta_11) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_invntt_simd_unit_invert_ntt_at_layer_1(
          re[index], re[index + (size_t)1U], zeta_00, zeta_01, zeta_10,
          zeta_11);
  __m256i lhs0 = uu____0.fst;
  __m256i lhs = uu____0.snd;
  re[index] = lhs0;
  re[index + (size_t)1U] = lhs;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)0U, (int32_t)3839961, (int32_t)-3628969, (int32_t)-3881060,
      (int32_t)-3019102);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)2U, (int32_t)-1439742, (int32_t)-812732, (int32_t)-1584928,
      (int32_t)1285669);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)4U, (int32_t)1341330, (int32_t)1315589, (int32_t)-177440,
      (int32_t)-2409325);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)6U, (int32_t)-1851402, (int32_t)3159746, (int32_t)-3553272,
      (int32_t)189548);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)8U, (int32_t)-1316856, (int32_t)759969, (int32_t)-210977,
      (int32_t)2389356);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)10U, (int32_t)-3249728, (int32_t)1653064, (int32_t)-8578,
      (int32_t)-3724342);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)12U, (int32_t)3958618, (int32_t)904516, (int32_t)-1100098,
      (int32_t)44288);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)14U, (int32_t)3097992, (int32_t)508951, (int32_t)264944,
      (int32_t)-3343383);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)16U, (int32_t)-1430430, (int32_t)1852771, (int32_t)1349076,
      (int32_t)-381987);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)18U, (int32_t)-1308169, (int32_t)-22981, (int32_t)-1228525,
      (int32_t)-671102);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)20U, (int32_t)-2477047, (int32_t)-411027, (int32_t)-3693493,
      (int32_t)-2967645);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)22U, (int32_t)2715295, (int32_t)2147896, (int32_t)-983419,
      (int32_t)3412210);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)24U, (int32_t)126922, (int32_t)-3632928, (int32_t)-3157330,
      (int32_t)-3190144);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)26U, (int32_t)-1000202, (int32_t)-4083598, (int32_t)1939314,
      (int32_t)-1257611);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)28U, (int32_t)-1585221, (int32_t)2176455, (int32_t)3475950,
      (int32_t)-1452451);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)30U, (int32_t)-3041255, (int32_t)-3677745, (int32_t)-1528703,
      (int32_t)-3930395);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE core_core_arch_x86___m256i_x2
libcrux_ml_dsa_simd_avx2_invntt_simd_unit_invert_ntt_at_layer_2(
    __m256i simd_unit0, __m256i simd_unit1, int32_t zeta0, int32_t zeta1) {
  __m256i lo_values = libcrux_intrinsics_avx2_mm256_permute2x128_si256(
      (int32_t)32, simd_unit0, simd_unit1, __m256i);
  __m256i hi_values = libcrux_intrinsics_avx2_mm256_permute2x128_si256(
      (int32_t)49, simd_unit0, simd_unit1, __m256i);
  __m256i sums = libcrux_ml_dsa_simd_avx2_arithmetic_add(lo_values, hi_values);
  __m256i differences =
      libcrux_ml_dsa_simd_avx2_arithmetic_subtract(hi_values, lo_values);
  __m256i zetas = libcrux_intrinsics_avx2_mm256_set_epi32(
      zeta1, zeta1, zeta1, zeta1, zeta0, zeta0, zeta0, zeta0);
  __m256i products = libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply(
      differences, zetas);
  __m256i a = libcrux_intrinsics_avx2_mm256_permute2x128_si256(
      (int32_t)32, sums, products, __m256i);
  __m256i b = libcrux_intrinsics_avx2_mm256_permute2x128_si256(
      (int32_t)49, sums, products, __m256i);
  return (CLITERAL(core_core_arch_x86___m256i_x2){.fst = a, .snd = b});
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(__m256i *re,
                                                            size_t index,
                                                            int32_t zeta1,
                                                            int32_t zeta2) {
  core_core_arch_x86___m256i_x2 uu____0 =
      libcrux_ml_dsa_simd_avx2_invntt_simd_unit_invert_ntt_at_layer_2(
          re[index], re[index + (size_t)1U], zeta1, zeta2);
  __m256i lhs0 = uu____0.fst;
  __m256i lhs = uu____0.snd;
  re[index] = lhs0;
  re[index + (size_t)1U] = lhs;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)0U, (int32_t)-2797779, (int32_t)2071892);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)2U, (int32_t)-2556880, (int32_t)3900724);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)4U, (int32_t)3881043, (int32_t)954230);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)6U, (int32_t)531354, (int32_t)811944);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)8U, (int32_t)3699596, (int32_t)-1600420);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)10U, (int32_t)-2140649, (int32_t)3507263);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)12U, (int32_t)-3821735, (int32_t)3505694);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)14U, (int32_t)-1643818, (int32_t)-1699267);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)16U, (int32_t)-539299, (int32_t)2348700);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)18U, (int32_t)-300467, (int32_t)3539968);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)20U, (int32_t)-2867647, (int32_t)3574422);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)22U, (int32_t)-3043716, (int32_t)-3861115);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)24U, (int32_t)3915439, (int32_t)-2537516);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)26U, (int32_t)-3592148, (int32_t)-1661693);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)28U, (int32_t)3530437, (int32_t)3077325);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)30U, (int32_t)95776, (int32_t)2706023);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE __m256i
libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
    __m256i lhs, int32_t constant) {
  __m256i rhs = libcrux_intrinsics_avx2_mm256_set1_epi32(constant);
  __m256i field_modulus = libcrux_intrinsics_avx2_mm256_set1_epi32(
      LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  __m256i inverse_of_modulus_mod_montgomery_r =
      libcrux_intrinsics_avx2_mm256_set1_epi32(
          (int32_t)
              LIBCRUX_ML_DSA_SIMD_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R);
  __m256i prod02 = libcrux_intrinsics_avx2_mm256_mul_epi32(lhs, rhs);
  __m256i prod13 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, lhs, __m256i),
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, rhs, __m256i));
  __m256i k02 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      prod02, inverse_of_modulus_mod_montgomery_r);
  __m256i k13 = libcrux_intrinsics_avx2_mm256_mul_epi32(
      prod13, inverse_of_modulus_mod_montgomery_r);
  __m256i c02 = libcrux_intrinsics_avx2_mm256_mul_epi32(k02, field_modulus);
  __m256i c13 = libcrux_intrinsics_avx2_mm256_mul_epi32(k13, field_modulus);
  __m256i res02 = libcrux_intrinsics_avx2_mm256_sub_epi32(prod02, c02);
  __m256i res13 = libcrux_intrinsics_avx2_mm256_sub_epi32(prod13, c13);
  __m256i res02_shifted =
      libcrux_intrinsics_avx2_mm256_shuffle_epi32((int32_t)245, res02, __m256i);
  return libcrux_intrinsics_avx2_mm256_blend_epi32((int32_t)170, res02_shifted,
                                                   res13, __m256i);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 1
- ZETA= 280005
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_99(
    __m256i *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)280005);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 2
- STEP_BY= 1
- ZETA= 4010497
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_1c(
    __m256i *re) {
  for (size_t i = (size_t)2U; i < (size_t)2U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)4010497);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 4
- STEP_BY= 1
- ZETA= -19422
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_6b(
    __m256i *re) {
  for (size_t i = (size_t)4U; i < (size_t)4U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-19422);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 6
- STEP_BY= 1
- ZETA= 1757237
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_44(
    __m256i *re) {
  for (size_t i = (size_t)6U; i < (size_t)6U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)1757237);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 1
- ZETA= -3277672
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a8(
    __m256i *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-3277672);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 10
- STEP_BY= 1
- ZETA= -1399561
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_1f(
    __m256i *re) {
  for (size_t i = (size_t)10U; i < (size_t)10U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-1399561);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 12
- STEP_BY= 1
- ZETA= -3859737
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_95(
    __m256i *re) {
  for (size_t i = (size_t)12U; i < (size_t)12U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-3859737);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 14
- STEP_BY= 1
- ZETA= -2118186
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3b(
    __m256i *re) {
  for (size_t i = (size_t)14U; i < (size_t)14U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2118186);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 1
- ZETA= -2108549
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a(
    __m256i *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2108549);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 18
- STEP_BY= 1
- ZETA= 2619752
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_e4(
    __m256i *re) {
  for (size_t i = (size_t)18U; i < (size_t)18U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2619752);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 20
- STEP_BY= 1
- ZETA= -1119584
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_de(
    __m256i *re) {
  for (size_t i = (size_t)20U; i < (size_t)20U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-1119584);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 22
- STEP_BY= 1
- ZETA= -549488
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_05(
    __m256i *re) {
  for (size_t i = (size_t)22U; i < (size_t)22U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-549488);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 1
- ZETA= 3585928
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_d9(
    __m256i *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)3585928);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 26
- STEP_BY= 1
- ZETA= -1079900
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3a(
    __m256i *re) {
  for (size_t i = (size_t)26U; i < (size_t)26U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-1079900);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 28
- STEP_BY= 1
- ZETA= 1024112
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3b0(
    __m256i *re) {
  for (size_t i = (size_t)28U; i < (size_t)28U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)1024112);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 30
- STEP_BY= 1
- ZETA= 2725464
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a0(
    __m256i *re) {
  for (size_t i = (size_t)30U; i < (size_t)30U + (size_t)1U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)1U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)1U]);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2725464);
  }
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_3(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_99(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_1c(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_6b(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_44(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a8(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_1f(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_95(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3b(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_e4(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_de(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_05(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_d9(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3a(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3b0(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a0(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 2
- ZETA= 2680103
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_990(
    __m256i *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2680103);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 4
- STEP_BY= 2
- ZETA= 3111497
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_6b0(
    __m256i *re) {
  for (size_t i = (size_t)4U; i < (size_t)4U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)3111497);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 2
- ZETA= -2884855
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a80(
    __m256i *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2884855);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 12
- STEP_BY= 2
- ZETA= 3119733
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_950(
    __m256i *re) {
  for (size_t i = (size_t)12U; i < (size_t)12U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)3119733);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 2
- ZETA= -2091905
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a0(
    __m256i *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2091905);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 20
- STEP_BY= 2
- ZETA= -359251
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_de0(
    __m256i *re) {
  for (size_t i = (size_t)20U; i < (size_t)20U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-359251);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 2
- ZETA= 2353451
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_d90(
    __m256i *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2353451);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 28
- STEP_BY= 2
- ZETA= 1826347
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3b1(
    __m256i *re) {
  for (size_t i = (size_t)28U; i < (size_t)28U + (size_t)2U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)2U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)2U]);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)1826347);
  }
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_4(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_990(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_6b0(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a80(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_950(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a0(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_de0(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_d90(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_3b1(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 4
- ZETA= 466468
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_991(
    __m256i *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)4U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)4U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)4U]);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)466468);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 4
- ZETA= -876248
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a81(
    __m256i *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)4U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)4U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)4U]);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-876248);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 4
- ZETA= -777960
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a1(
    __m256i *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)4U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)4U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)4U]);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-777960);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 4
- ZETA= 237124
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_d91(
    __m256i *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)4U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)4U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)4U]);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)237124);
  }
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_5(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_991(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_a81(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a1(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_d91(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 8
- ZETA= -518909
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_992(
    __m256i *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)8U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)8U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)8U]);
    re[j + (size_t)8U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-518909);
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 8
- ZETA= -2608894
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a2(
    __m256i *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)8U; i++) {
    size_t j = i;
    __m256i a_minus_b =
        libcrux_ml_dsa_simd_avx2_arithmetic_subtract(re[j + (size_t)8U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)8U]);
    re[j + (size_t)8U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2608894);
  }
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_6(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_992(re);
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_7a2(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.avx2.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 16
- ZETA= 25847
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_993(
    __m256i *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)16U; i++) {
    size_t j = i;
    __m256i a_minus_b = libcrux_ml_dsa_simd_avx2_arithmetic_subtract(
        re[j + (size_t)16U], re[j]);
    re[j] = libcrux_ml_dsa_simd_avx2_arithmetic_add(re[j], re[j + (size_t)16U]);
    re[j + (size_t)16U] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)25847);
  }
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_7(
    __m256i *re) {
  libcrux_ml_dsa_simd_avx2_invntt_outer_3_plus_993(re);
}

KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_montgomery(__m256i re[32U],
                                                      __m256i ret[32U]) {
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_0(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_1(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_2(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_3(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_4(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_5(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_6(re);
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_at_layer_7(re);
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice((size_t)32U, re, __m256i),
                              __m256i);
       i++) {
    size_t i0 = i;
    re[i0] =
        libcrux_ml_dsa_simd_avx2_arithmetic_montgomery_multiply_by_constant(
            re[i0], (int32_t)41978);
  }
  memcpy(ret, re, (size_t)32U * sizeof(__m256i));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i libcrux_ml_dsa_simd_avx2_invert_ntt_montgomery_closure_a2(
    __m256i **state, size_t i) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"unexpected / ill-typed projection\")\n");
  KRML_HOST_EXIT(255U);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_avx2_invert_ntt_montgomery_a2(
    __m256i simd_units[32U], __m256i ret[32U]) {
  __m256i re[32U];
  for (size_t i = (size_t)0U; i < (size_t)32U; i++) {
    re[i] = libcrux_intrinsics_avx2_mm256_setzero_si256();
  }
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_DSA_SIMD_TRAITS_SIMD_UNITS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    re[i0] = simd_units[i0];
  }
  /* Passing arrays by value in Rust generates a copy in C */
  __m256i copy_of_re[32U];
  memcpy(copy_of_re, re, (size_t)32U * sizeof(__m256i));
  __m256i result[32U];
  libcrux_ml_dsa_simd_avx2_invntt_invert_ntt_montgomery(copy_of_re, result);
  __m256i ret0[32U];
  for (size_t i = (size_t)0U; i < (size_t)32U; i++) {
    ret0[i] = KRML_EABORT(
        __m256i,
        "Eurydice error: Failure(\"unexpected / ill-typed projection\")\n");
  }
  memcpy(ret, ret0, (size_t)32U * sizeof(__m256i));
}

/**
A monomorphic instance of libcrux_ml_dsa.polynomial.PolynomialRingElement
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit

*/
typedef struct libcrux_ml_dsa_polynomial_PolynomialRingElement_24_s {
  __m256i simd_units[32U];
} libcrux_ml_dsa_polynomial_PolynomialRingElement_24;

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.ZERO_ff
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_24
libcrux_ml_dsa_polynomial_ZERO_ff_ea(void) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 lit;
  lit.simd_units[0U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[1U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[2U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[3U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[4U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[5U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[6U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[7U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[8U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[9U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[10U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[11U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[12U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[13U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[14U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[15U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[16U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[17U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[18U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[19U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[20U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[21U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[22U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[23U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[24U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[25U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[26U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[27U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[28U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[29U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[30U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  lit.simd_units[31U] = libcrux_ml_dsa_simd_avx2_ZERO_a2();
  return lit;
}

typedef struct
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4_s {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 fst;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 snd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 thd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 f3;
} libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4;

/**
A monomorphic instance of
libcrux_ml_dsa.sample.rejection_sample_less_than_field_modulus with types
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
    Eurydice_slice randomness, size_t *sampled_coefficients, int32_t *out) {
  bool done = false;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(randomness, uint8_t) / (size_t)24U; i++) {
    size_t _cloop_i = i;
    Eurydice_slice random_bytes =
        Eurydice_slice_subslice2(randomness, _cloop_i * (size_t)24U,
                                 _cloop_i * (size_t)24U + (size_t)24U, uint8_t);
    if (!done) {
      Eurydice_slice uu____0 = random_bytes;
      size_t sampled =
          libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_field_modulus_a2(
              uu____0, Eurydice_array_to_subslice_from((size_t)263U, out,
                                                       sampled_coefficients[0U],
                                                       int32_t, size_t));
      sampled_coefficients[0U] = sampled_coefficients[0U] + sampled;
      if (sampled_coefficients[0U] >=
          LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        done = true;
      }
    }
  }
  return done;
}

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.from_i32_array_ff
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_24
libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(Eurydice_slice array) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 result =
      libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_DSA_SIMD_TRAITS_SIMD_UNITS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    result.simd_units[i0] = libcrux_ml_dsa_simd_avx2_from_coefficient_array_a2(
        Eurydice_slice_subslice2(
            array, i0 * LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT,
            (i0 + (size_t)1U) *
                LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT,
            int32_t));
  }
  return result;
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_four_ring_elements
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
libcrux_ml_dsa_sample_sample_four_ring_elements_ea(uint8_t seed0[34U],
                                                   uint16_t domain_separator0,
                                                   uint16_t domain_separator1,
                                                   uint16_t domain_seperator2,
                                                   uint16_t domain_separator3) {
  seed0[32U] = (uint8_t)domain_separator0;
  seed0[33U] = (uint8_t)((uint32_t)domain_separator0 >> 8U);
  uint8_t seed1[34U];
  memcpy(seed1, seed0, (size_t)34U * sizeof(uint8_t));
  seed1[32U] = (uint8_t)domain_separator1;
  seed1[33U] = (uint8_t)((uint32_t)domain_separator1 >> 8U);
  uint8_t seed2[34U];
  memcpy(seed2, seed0, (size_t)34U * sizeof(uint8_t));
  seed2[32U] = (uint8_t)domain_seperator2;
  seed2[33U] = (uint8_t)((uint32_t)domain_seperator2 >> 8U);
  uint8_t seed3[34U];
  memcpy(seed3, seed0, (size_t)34U * sizeof(uint8_t));
  seed3[32U] = (uint8_t)domain_separator3;
  seed3[33U] = (uint8_t)((uint32_t)domain_separator3 >> 8U);
  libcrux_ml_dsa_hash_functions_portable_Shake128X4 state =
      libcrux_ml_dsa_hash_functions_portable_init_absorb_ed(
          Eurydice_array_to_slice((size_t)34U, seed0, uint8_t),
          Eurydice_array_to_slice((size_t)34U, seed1, uint8_t),
          Eurydice_array_to_slice((size_t)34U, seed2, uint8_t),
          Eurydice_array_to_slice((size_t)34U, seed3, uint8_t));
  uint8_t randomness0[840U] = {0U};
  uint8_t randomness1[840U] = {0U};
  uint8_t randomness2[840U] = {0U};
  uint8_t randomness3[840U] = {0U};
  libcrux_ml_dsa_hash_functions_portable_squeeze_first_five_blocks_ed(
      &state, randomness0, randomness1, randomness2, randomness3);
  int32_t coefficients0[263U] = {0U};
  int32_t coefficients1[263U] = {0U};
  int32_t coefficients2[263U] = {0U};
  int32_t coefficients3[263U] = {0U};
  size_t sampled0 = (size_t)0U;
  size_t sampled1 = (size_t)0U;
  size_t sampled2 = (size_t)0U;
  size_t sampled3 = (size_t)0U;
  bool done0 =
      libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
          Eurydice_array_to_slice((size_t)840U, randomness0, uint8_t),
          &sampled0, coefficients0);
  bool done1 =
      libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
          Eurydice_array_to_slice((size_t)840U, randomness1, uint8_t),
          &sampled1, coefficients1);
  bool done2 =
      libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
          Eurydice_array_to_slice((size_t)840U, randomness2, uint8_t),
          &sampled2, coefficients2);
  bool done3 =
      libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
          Eurydice_array_to_slice((size_t)840U, randomness3, uint8_t),
          &sampled3, coefficients3);
  while (true) {
    if (done0) {
      if (done1) {
        if (done2) {
          if (done3) {
            break;
          } else {
            uint8_t_168size_t__x4 randomnesses =
                libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_ed(
                    &state);
            if (!done0) {
              done0 =
                  libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                      Eurydice_array_to_slice((size_t)168U, randomnesses.fst,
                                              uint8_t),
                      &sampled0, coefficients0);
            }
            if (!done1) {
              done1 =
                  libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                      Eurydice_array_to_slice((size_t)168U, randomnesses.snd,
                                              uint8_t),
                      &sampled1, coefficients1);
            }
            if (!done2) {
              done2 =
                  libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                      Eurydice_array_to_slice((size_t)168U, randomnesses.thd,
                                              uint8_t),
                      &sampled2, coefficients2);
            }
            if (!done3) {
              done3 =
                  libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                      Eurydice_array_to_slice((size_t)168U, randomnesses.f3,
                                              uint8_t),
                      &sampled3, coefficients3);
            }
          }
        } else {
          uint8_t_168size_t__x4 randomnesses =
              libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_ed(
                  &state);
          if (!done0) {
            done0 =
                libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                    Eurydice_array_to_slice((size_t)168U, randomnesses.fst,
                                            uint8_t),
                    &sampled0, coefficients0);
          }
          if (!done1) {
            done1 =
                libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                    Eurydice_array_to_slice((size_t)168U, randomnesses.snd,
                                            uint8_t),
                    &sampled1, coefficients1);
          }
          if (!done2) {
            done2 =
                libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                    Eurydice_array_to_slice((size_t)168U, randomnesses.thd,
                                            uint8_t),
                    &sampled2, coefficients2);
          }
          if (!done3) {
            done3 =
                libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                    Eurydice_array_to_slice((size_t)168U, randomnesses.f3,
                                            uint8_t),
                    &sampled3, coefficients3);
          }
        }
      } else {
        uint8_t_168size_t__x4 randomnesses =
            libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_ed(
                &state);
        if (!done0) {
          done0 =
              libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                  Eurydice_array_to_slice((size_t)168U, randomnesses.fst,
                                          uint8_t),
                  &sampled0, coefficients0);
        }
        if (!done1) {
          done1 =
              libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                  Eurydice_array_to_slice((size_t)168U, randomnesses.snd,
                                          uint8_t),
                  &sampled1, coefficients1);
        }
        if (!done2) {
          done2 =
              libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                  Eurydice_array_to_slice((size_t)168U, randomnesses.thd,
                                          uint8_t),
                  &sampled2, coefficients2);
        }
        if (!done3) {
          done3 =
              libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                  Eurydice_array_to_slice((size_t)168U, randomnesses.f3,
                                          uint8_t),
                  &sampled3, coefficients3);
        }
      }
    } else {
      uint8_t_168size_t__x4 randomnesses =
          libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_ed(&state);
      if (!done0) {
        done0 =
            libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                Eurydice_array_to_slice((size_t)168U, randomnesses.fst,
                                        uint8_t),
                &sampled0, coefficients0);
      }
      if (!done1) {
        done1 =
            libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                Eurydice_array_to_slice((size_t)168U, randomnesses.snd,
                                        uint8_t),
                &sampled1, coefficients1);
      }
      if (!done2) {
        done2 =
            libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                Eurydice_array_to_slice((size_t)168U, randomnesses.thd,
                                        uint8_t),
                &sampled2, coefficients2);
      }
      if (!done3) {
        done3 =
            libcrux_ml_dsa_sample_rejection_sample_less_than_field_modulus_ea(
                Eurydice_array_to_slice((size_t)168U, randomnesses.f3, uint8_t),
                &sampled3, coefficients3);
      }
    }
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 uu____0 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
          Eurydice_array_to_slice((size_t)263U, coefficients0, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 uu____1 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
          Eurydice_array_to_slice((size_t)263U, coefficients1, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 uu____2 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
          Eurydice_array_to_slice((size_t)263U, coefficients2, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      lit;
  lit.fst = uu____0;
  lit.snd = uu____1;
  lit.thd = uu____2;
  lit.f3 = libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
      Eurydice_array_to_slice((size_t)263U, coefficients3, int32_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.update_matrix
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline void libcrux_ml_dsa_samplex4_update_matrix_fe(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 (*m)[5U], size_t i,
    size_t j, libcrux_ml_dsa_polynomial_PolynomialRingElement_24 v) {
  m[i][j] = v;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.matrix_A_4_by_4
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_samplex4_matrix_A_4_by_4_fe(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret[6U][5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 A[6U][5U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    A[i][0U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][1U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][2U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][3U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][4U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed[34U];
  memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed,
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)0U,
                                           four_ring_elements.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)1U,
                                           four_ring_elements.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)2U,
                                           four_ring_elements.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)3U,
                                           four_ring_elements.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed0[34U];
  memcpy(copy_of_seed0, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements0 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed0,
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)0U,
                                           four_ring_elements0.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)1U,
                                           four_ring_elements0.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)2U,
                                           four_ring_elements0.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)3U,
                                           four_ring_elements0.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed1[34U];
  memcpy(copy_of_seed1, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements1 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed1,
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)0U,
                                           four_ring_elements1.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)1U,
                                           four_ring_elements1.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)2U,
                                           four_ring_elements1.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)3U,
                                           four_ring_elements1.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed2[34U];
  memcpy(copy_of_seed2, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements2 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed2,
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)0U,
                                           four_ring_elements2.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)1U,
                                           four_ring_elements2.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)2U,
                                           four_ring_elements2.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)3U,
                                           four_ring_elements2.f3);
  memcpy(ret, A,
         (size_t)6U *
             sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24[5U]));
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.matrix_A_6_by_5
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_samplex4_matrix_A_6_by_5_fe(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret[6U][5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 A[6U][5U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    A[i][0U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][1U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][2U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][3U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][4U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed[34U];
  memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed,
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)0U,
                                           four_ring_elements.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)1U,
                                           four_ring_elements.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)2U,
                                           four_ring_elements.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)3U,
                                           four_ring_elements.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed0[34U];
  memcpy(copy_of_seed0, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements0 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed0,
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 2U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)4U,
                                           four_ring_elements0.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)0U,
                                           four_ring_elements0.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)1U,
                                           four_ring_elements0.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)2U,
                                           four_ring_elements0.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed1[34U];
  memcpy(copy_of_seed1, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements1 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed1,
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 1U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)3U,
                                           four_ring_elements1.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)4U,
                                           four_ring_elements1.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)0U,
                                           four_ring_elements1.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)1U,
                                           four_ring_elements1.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed2[34U];
  memcpy(copy_of_seed2, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements2 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed2,
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 0U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)2U,
                                           four_ring_elements2.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)3U,
                                           four_ring_elements2.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)4U,
                                           four_ring_elements2.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)0U,
                                           four_ring_elements2.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed3[34U];
  memcpy(copy_of_seed3, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements3 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed3,
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 4U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)1U,
                                           four_ring_elements3.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)2U,
                                           four_ring_elements3.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)3U,
                                           four_ring_elements3.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)4U,
                                           four_ring_elements3.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed4[34U];
  memcpy(copy_of_seed4, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements4 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed4,
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)0U,
                                           four_ring_elements4.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)1U,
                                           four_ring_elements4.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)2U,
                                           four_ring_elements4.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)3U,
                                           four_ring_elements4.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed5[34U];
  memcpy(copy_of_seed5, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements5 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed5,
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 2U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)4U,
                                           four_ring_elements5.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)0U,
                                           four_ring_elements5.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)1U,
                                           four_ring_elements5.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)2U,
                                           four_ring_elements5.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed6[34U];
  memcpy(copy_of_seed6, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements6 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed6,
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 6U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)3U,
                                           four_ring_elements6.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)4U,
                                           four_ring_elements6.snd);
  memcpy(ret, A,
         (size_t)6U *
             sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24[5U]));
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.matrix_A_8_by_7
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_samplex4_matrix_A_8_by_7_fe(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret[6U][5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 A[6U][5U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    A[i][0U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][1U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][2U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][3U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
    A[i][4U] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed[34U];
  memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed,
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)0U,
                                           four_ring_elements.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)1U,
                                           four_ring_elements.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)2U,
                                           four_ring_elements.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)3U,
                                           four_ring_elements.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed0[34U];
  memcpy(copy_of_seed0, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements0 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed0,
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(0U, 6U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 0U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)4U,
                                           four_ring_elements0.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)5U,
                                           four_ring_elements0.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)0U, (size_t)6U,
                                           four_ring_elements0.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)0U,
                                           four_ring_elements0.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed1[34U];
  memcpy(copy_of_seed1, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements1 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed1,
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 4U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)1U,
                                           four_ring_elements1.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)2U,
                                           four_ring_elements1.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)3U,
                                           four_ring_elements1.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)4U,
                                           four_ring_elements1.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed2[34U];
  memcpy(copy_of_seed2, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements2 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed2,
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(1U, 6U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 1U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)5U,
                                           four_ring_elements2.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)1U, (size_t)6U,
                                           four_ring_elements2.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)0U,
                                           four_ring_elements2.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)1U,
                                           four_ring_elements2.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed3[34U];
  memcpy(copy_of_seed3, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements3 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed3,
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 5U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)2U,
                                           four_ring_elements3.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)3U,
                                           four_ring_elements3.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)4U,
                                           four_ring_elements3.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)5U,
                                           four_ring_elements3.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed4[34U];
  memcpy(copy_of_seed4, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements4 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed4,
          libcrux_ml_dsa_samplex4_generate_domain_separator(2U, 6U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 2U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)2U, (size_t)6U,
                                           four_ring_elements4.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)0U,
                                           four_ring_elements4.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)1U,
                                           four_ring_elements4.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)2U,
                                           four_ring_elements4.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed5[34U];
  memcpy(copy_of_seed5, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements5 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed5,
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(3U, 6U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)3U,
                                           four_ring_elements5.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)4U,
                                           four_ring_elements5.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)5U,
                                           four_ring_elements5.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)3U, (size_t)6U,
                                           four_ring_elements5.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed6[34U];
  memcpy(copy_of_seed6, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements6 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed6,
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 3U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)0U,
                                           four_ring_elements6.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)1U,
                                           four_ring_elements6.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)2U,
                                           four_ring_elements6.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)3U,
                                           four_ring_elements6.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed7[34U];
  memcpy(copy_of_seed7, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements7 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed7,
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(4U, 6U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 0U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)4U,
                                           four_ring_elements7.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)5U,
                                           four_ring_elements7.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)4U, (size_t)6U,
                                           four_ring_elements7.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)0U,
                                           four_ring_elements7.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed8[34U];
  memcpy(copy_of_seed8, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements8 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed8,
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 4U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)1U,
                                           four_ring_elements8.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)2U,
                                           four_ring_elements8.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)3U,
                                           four_ring_elements8.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)4U,
                                           four_ring_elements8.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed9[34U];
  memcpy(copy_of_seed9, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements9 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed9,
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(5U, 6U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 1U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)5U,
                                           four_ring_elements9.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)5U, (size_t)6U,
                                           four_ring_elements9.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)0U,
                                           four_ring_elements9.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)1U,
                                           four_ring_elements9.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed10[34U];
  memcpy(copy_of_seed10, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements10 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed10,
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 2U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 5U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)2U,
                                           four_ring_elements10.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)3U,
                                           four_ring_elements10.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)4U,
                                           four_ring_elements10.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)5U,
                                           four_ring_elements10.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed11[34U];
  memcpy(copy_of_seed11, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements11 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed11,
          libcrux_ml_dsa_samplex4_generate_domain_separator(6U, 6U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 0U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 1U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 2U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)6U, (size_t)6U,
                                           four_ring_elements11.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)0U,
                                           four_ring_elements11.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)1U,
                                           four_ring_elements11.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)2U,
                                           four_ring_elements11.f3);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed12[34U];
  memcpy(copy_of_seed12, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four_ring_elements12 = libcrux_ml_dsa_sample_sample_four_ring_elements_ea(
          copy_of_seed12,
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 3U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 4U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 5U),
          libcrux_ml_dsa_samplex4_generate_domain_separator(7U, 6U));
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)3U,
                                           four_ring_elements12.fst);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)4U,
                                           four_ring_elements12.snd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)5U,
                                           four_ring_elements12.thd);
  libcrux_ml_dsa_samplex4_update_matrix_fe(A, (size_t)7U, (size_t)6U,
                                           four_ring_elements12.f3);
  memcpy(ret, A,
         (size_t)6U *
             sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24[5U]));
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.matrix_A
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_samplex4_matrix_A_fe(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret[6U][5U]) {
  uint8_t_x2 uu____0 = {.fst = (uint8_t)(size_t)6U, .snd = (uint8_t)(size_t)5U};
  switch (uu____0.fst) {
    case 4U: {
      switch (uu____0.snd) {
        case 4U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[34U];
          memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
          libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret0[6U][5U];
          libcrux_ml_dsa_samplex4_matrix_A_4_by_4_fe(copy_of_seed, ret0);
          memcpy(
              ret, ret0,
              (size_t)6U *
                  sizeof(
                      libcrux_ml_dsa_polynomial_PolynomialRingElement_24[5U]));
          return;
        }
        default: {
        }
      }
      break;
    }
    case 6U: {
      switch (uu____0.snd) {
        case 5U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[34U];
          memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
          libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret0[6U][5U];
          libcrux_ml_dsa_samplex4_matrix_A_6_by_5_fe(copy_of_seed, ret0);
          memcpy(
              ret, ret0,
              (size_t)6U *
                  sizeof(
                      libcrux_ml_dsa_polynomial_PolynomialRingElement_24[5U]));
          return;
        }
        default: {
        }
      }
      break;
    }
    case 8U: {
      switch (uu____0.snd) {
        case 7U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[34U];
          memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
          libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret0[6U][5U];
          libcrux_ml_dsa_samplex4_matrix_A_8_by_7_fe(copy_of_seed, ret0);
          memcpy(
              ret, ret0,
              (size_t)6U *
                  sizeof(
                      libcrux_ml_dsa_polynomial_PolynomialRingElement_24[5U]));
          return;
        }
        default: {
        }
      }
      break;
    }
    default: {
    }
  }
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
A monomorphic instance of K.
with types libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit[5size_t],
libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit[6size_t]

*/
typedef struct tuple_ce0_s {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 fst[5U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 snd[6U];
} tuple_ce0;

/**
A monomorphic instance of
libcrux_ml_dsa.sample.rejection_sample_less_than_eta_equals_2 with types
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_eta_equals_2_ea(
    Eurydice_slice randomness, size_t *sampled_coefficients, int32_t *out) {
  bool done = false;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(randomness, uint8_t) / (size_t)4U; i++) {
    size_t _cloop_i = i;
    Eurydice_slice random_bytes =
        Eurydice_slice_subslice2(randomness, _cloop_i * (size_t)4U,
                                 _cloop_i * (size_t)4U + (size_t)4U, uint8_t);
    if (!done) {
      Eurydice_slice uu____0 = random_bytes;
      size_t sampled =
          libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_equals_2_a2(
              uu____0, Eurydice_array_to_subslice_from((size_t)263U, out,
                                                       sampled_coefficients[0U],
                                                       int32_t, size_t));
      sampled_coefficients[0U] = sampled_coefficients[0U] + sampled;
      if (sampled_coefficients[0U] >=
          LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        done = true;
      }
    }
  }
  return done;
}

/**
A monomorphic instance of
libcrux_ml_dsa.sample.rejection_sample_less_than_eta_equals_4 with types
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_eta_equals_4_ea(
    Eurydice_slice randomness, size_t *sampled_coefficients, int32_t *out) {
  bool done = false;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(randomness, uint8_t) / (size_t)4U; i++) {
    size_t _cloop_i = i;
    Eurydice_slice random_bytes =
        Eurydice_slice_subslice2(randomness, _cloop_i * (size_t)4U,
                                 _cloop_i * (size_t)4U + (size_t)4U, uint8_t);
    if (!done) {
      Eurydice_slice uu____0 = random_bytes;
      size_t sampled =
          libcrux_ml_dsa_simd_avx2_rejection_sample_less_than_eta_equals_4_a2(
              uu____0, Eurydice_array_to_subslice_from((size_t)263U, out,
                                                       sampled_coefficients[0U],
                                                       int32_t, size_t));
      sampled_coefficients[0U] = sampled_coefficients[0U] + sampled;
      if (sampled_coefficients[0U] >=
          LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT) {
        done = true;
      }
    }
  }
  return done;
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.rejection_sample_less_than_eta
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ETA= 4
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
    Eurydice_slice randomness, size_t *sampled, int32_t *out) {
  return libcrux_ml_dsa_sample_rejection_sample_less_than_eta_equals_4_ea(
      randomness, sampled, out);
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_four_error_ring_elements
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ETA= 4
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
    libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
        uint8_t seed_base[66U], uint16_t domain_separator0,
        uint16_t domain_separator1, uint16_t domain_seperator2,
        uint16_t domain_separator3) {
  uint8_t seed0[66U];
  memcpy(seed0, seed_base, (size_t)66U * sizeof(uint8_t));
  seed0[64U] = (uint8_t)domain_separator0;
  seed0[65U] = (uint8_t)((uint32_t)domain_separator0 >> 8U);
  uint8_t seed1[66U];
  memcpy(seed1, seed0, (size_t)66U * sizeof(uint8_t));
  seed1[64U] = (uint8_t)domain_separator1;
  seed1[65U] = (uint8_t)((uint32_t)domain_separator1 >> 8U);
  uint8_t seed2[66U];
  memcpy(seed2, seed0, (size_t)66U * sizeof(uint8_t));
  seed2[64U] = (uint8_t)domain_seperator2;
  seed2[65U] = (uint8_t)((uint32_t)domain_seperator2 >> 8U);
  uint8_t seed3[66U];
  memcpy(seed3, seed0, (size_t)66U * sizeof(uint8_t));
  seed3[64U] = (uint8_t)domain_separator3;
  seed3[65U] = (uint8_t)((uint32_t)domain_separator3 >> 8U);
  libcrux_sha3_avx2_x4_incremental_KeccakState state =
      libcrux_ml_dsa_hash_functions_simd256_init_absorb_x4_fb(
          Eurydice_array_to_slice((size_t)66U, seed0, uint8_t),
          Eurydice_array_to_slice((size_t)66U, seed1, uint8_t),
          Eurydice_array_to_slice((size_t)66U, seed2, uint8_t),
          Eurydice_array_to_slice((size_t)66U, seed3, uint8_t));
  uint8_t_136size_t__x4 randomnesses0 =
      libcrux_ml_dsa_hash_functions_simd256_squeeze_first_block_x4_fb(&state);
  int32_t out0[263U] = {0U};
  int32_t out1[263U] = {0U};
  int32_t out2[263U] = {0U};
  int32_t out3[263U] = {0U};
  size_t sampled0 = (size_t)0U;
  size_t sampled1 = (size_t)0U;
  size_t sampled2 = (size_t)0U;
  size_t sampled3 = (size_t)0U;
  bool done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.fst, uint8_t),
      &sampled0, out0);
  bool done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.snd, uint8_t),
      &sampled1, out1);
  bool done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.thd, uint8_t),
      &sampled2, out2);
  bool done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.f3, uint8_t),
      &sampled3, out3);
  while (true) {
    if (done0) {
      if (done1) {
        if (done2) {
          if (done3) {
            break;
          } else {
            uint8_t_136size_t__x4 randomnesses =
                libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4_fb(
                    &state);
            if (!done0) {
              done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.fst,
                                          uint8_t),
                  &sampled0, out0);
            }
            if (!done1) {
              done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.snd,
                                          uint8_t),
                  &sampled1, out1);
            }
            if (!done2) {
              done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.thd,
                                          uint8_t),
                  &sampled2, out2);
            }
            if (!done3) {
              done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.f3,
                                          uint8_t),
                  &sampled3, out3);
            }
          }
        } else {
          uint8_t_136size_t__x4 randomnesses =
              libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4_fb(
                  &state);
          if (!done0) {
            done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                Eurydice_array_to_slice((size_t)136U, randomnesses.fst,
                                        uint8_t),
                &sampled0, out0);
          }
          if (!done1) {
            done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                Eurydice_array_to_slice((size_t)136U, randomnesses.snd,
                                        uint8_t),
                &sampled1, out1);
          }
          if (!done2) {
            done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                Eurydice_array_to_slice((size_t)136U, randomnesses.thd,
                                        uint8_t),
                &sampled2, out2);
          }
          if (!done3) {
            done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
                Eurydice_array_to_slice((size_t)136U, randomnesses.f3, uint8_t),
                &sampled3, out3);
          }
        }
      } else {
        uint8_t_136size_t__x4 randomnesses =
            libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4_fb(
                &state);
        if (!done0) {
          done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
              Eurydice_array_to_slice((size_t)136U, randomnesses.fst, uint8_t),
              &sampled0, out0);
        }
        if (!done1) {
          done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
              Eurydice_array_to_slice((size_t)136U, randomnesses.snd, uint8_t),
              &sampled1, out1);
        }
        if (!done2) {
          done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
              Eurydice_array_to_slice((size_t)136U, randomnesses.thd, uint8_t),
              &sampled2, out2);
        }
        if (!done3) {
          done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
              Eurydice_array_to_slice((size_t)136U, randomnesses.f3, uint8_t),
              &sampled3, out3);
        }
      }
    } else {
      uint8_t_136size_t__x4 randomnesses =
          libcrux_ml_dsa_hash_functions_simd256_squeeze_next_block_x4_fb(
              &state);
      if (!done0) {
        done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
            Eurydice_array_to_slice((size_t)136U, randomnesses.fst, uint8_t),
            &sampled0, out0);
      }
      if (!done1) {
        done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
            Eurydice_array_to_slice((size_t)136U, randomnesses.snd, uint8_t),
            &sampled1, out1);
      }
      if (!done2) {
        done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
            Eurydice_array_to_slice((size_t)136U, randomnesses.thd, uint8_t),
            &sampled2, out2);
      }
      if (!done3) {
        done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_4d(
            Eurydice_array_to_slice((size_t)136U, randomnesses.f3, uint8_t),
            &sampled3, out3);
      }
    }
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 uu____0 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
          Eurydice_array_to_slice((size_t)263U, out0, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 uu____1 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
          Eurydice_array_to_slice((size_t)263U, out1, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 uu____2 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
          Eurydice_array_to_slice((size_t)263U, out2, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      lit;
  lit.fst = uu____0;
  lit.snd = uu____1;
  lit.thd = uu____2;
  lit.f3 = libcrux_ml_dsa_polynomial_from_i32_array_ff_ea(
      Eurydice_array_to_slice((size_t)263U, out3, int32_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.sample_s1_and_s2_4_by_4
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ETA= 4
- S1_DIMENSION= 5
- S2_DIMENSION= 6
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE tuple_ce0
libcrux_ml_dsa_samplex4_sample_s1_and_s2_4_by_4_4d(uint8_t seed_base[66U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s1[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    s1[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s2[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    s2[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base[66U];
  memcpy(copy_of_seed_base, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base, 0U, 1U, 2U, 3U);
  s1[0U] = four.fst;
  s1[1U] = four.snd;
  s1[2U] = four.thd;
  s1[3U] = four.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base0[66U];
  memcpy(copy_of_seed_base0, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four0 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base0, 4U, 5U, 6U, 7U);
  s2[0U] = four0.fst;
  s2[1U] = four0.snd;
  s2[2U] = four0.thd;
  s2[3U] = four0.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s2[6U];
  memcpy(
      copy_of_s2, s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  tuple_ce0 lit;
  memcpy(
      lit.fst, copy_of_s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  memcpy(
      lit.snd, copy_of_s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.sample_s1_and_s2_5_by_6
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ETA= 4
- S1_DIMENSION= 5
- S2_DIMENSION= 6
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE tuple_ce0
libcrux_ml_dsa_samplex4_sample_s1_and_s2_5_by_6_4d(uint8_t seed_base[66U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s1[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    s1[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s2[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    s2[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base[66U];
  memcpy(copy_of_seed_base, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base, 0U, 1U, 2U, 3U);
  s1[0U] = four.fst;
  s1[1U] = four.snd;
  s1[2U] = four.thd;
  s1[3U] = four.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base0[66U];
  memcpy(copy_of_seed_base0, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four0 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base0, 4U, 5U, 6U, 7U);
  s1[4U] = four0.fst;
  s2[0U] = four0.snd;
  s2[1U] = four0.thd;
  s2[2U] = four0.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base1[66U];
  memcpy(copy_of_seed_base1, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four1 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base1, 8U, 9U, 10U, 11U);
  s2[3U] = four1.fst;
  s2[4U] = four1.snd;
  s2[5U] = four1.thd;
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s2[6U];
  memcpy(
      copy_of_s2, s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  tuple_ce0 lit;
  memcpy(
      lit.fst, copy_of_s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  memcpy(
      lit.snd, copy_of_s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.sample_s1_and_s2_7_by_8
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ETA= 4
- S1_DIMENSION= 5
- S2_DIMENSION= 6
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE tuple_ce0
libcrux_ml_dsa_samplex4_sample_s1_and_s2_7_by_8_4d(uint8_t seed_base[66U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s1[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    s1[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s2[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    s2[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ea();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base[66U];
  memcpy(copy_of_seed_base, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base, 0U, 1U, 2U, 3U);
  s1[0U] = four.fst;
  s1[1U] = four.snd;
  s1[2U] = four.thd;
  s1[3U] = four.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base0[66U];
  memcpy(copy_of_seed_base0, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four0 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base0, 4U, 5U, 6U, 7U);
  s1[4U] = four0.fst;
  s1[5U] = four0.snd;
  s1[6U] = four0.thd;
  s2[0U] = four0.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base1[66U];
  memcpy(copy_of_seed_base1, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four1 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base1, 8U, 9U, 10U, 11U);
  s2[1U] = four1.fst;
  s2[2U] = four1.snd;
  s2[3U] = four1.thd;
  s2[4U] = four1.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base2[66U];
  memcpy(copy_of_seed_base2, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_x4
      four2 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_cb(
          copy_of_seed_base2, 12U, 13U, 14U, 15U);
  s2[5U] = four2.fst;
  s2[6U] = four2.snd;
  s2[7U] = four2.thd;
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s2[6U];
  memcpy(
      copy_of_s2, s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  tuple_ce0 lit;
  memcpy(
      lit.fst, copy_of_s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  memcpy(
      lit.snd, copy_of_s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.sample_s1_and_s2
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ETA= 4
- S1_DIMENSION= 5
- S2_DIMENSION= 6
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE tuple_ce0
libcrux_ml_dsa_samplex4_sample_s1_and_s2_4d(uint8_t seed[66U]) {
  uint8_t_x2 uu____0 = {.fst = (uint8_t)(size_t)5U, .snd = (uint8_t)(size_t)6U};
  switch (uu____0.fst) {
    case 4U: {
      switch (uu____0.snd) {
        case 4U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[66U];
          memcpy(copy_of_seed, seed, (size_t)66U * sizeof(uint8_t));
          return libcrux_ml_dsa_samplex4_sample_s1_and_s2_4_by_4_4d(
              copy_of_seed);
        }
        default: {
        }
      }
      break;
    }
    case 5U: {
      switch (uu____0.snd) {
        case 6U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[66U];
          memcpy(copy_of_seed, seed, (size_t)66U * sizeof(uint8_t));
          return libcrux_ml_dsa_samplex4_sample_s1_and_s2_5_by_6_4d(
              copy_of_seed);
        }
        default: {
        }
      }
      break;
    }
    case 7U: {
      switch (uu____0.snd) {
        case 8U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[66U];
          memcpy(copy_of_seed, seed, (size_t)66U * sizeof(uint8_t));
          return libcrux_ml_dsa_samplex4_sample_s1_and_s2_7_by_8_4d(
              copy_of_seed);
        }
        default: {
        }
      }
      break;
    }
    default: {
    }
  }
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Compute InvertNTT(Â ◦ ŝ₁) + s₂
*/
/**
A monomorphic instance of libcrux_ml_dsa.matrix.compute_As1_plus_s2
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_compute_As1_plus_s2_fe(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 (*A_as_ntt)[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 *s1,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 *s2,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 ret[6U]) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"Error looking trait impl: "
      "core::slice::iter::{core::iter::traits::iterator::Iterator for "
      "core::slice::iter::Iter<\'a, T>[TraitClause@0]}#182<\'_, "
      "@Array<libcrux_ml_dsa::polynomial::PolynomialRingElement<T@0>["
      "TraitClause@0, TraitClause@1], "
      "C@1>>[core::marker::Sized<@Array<libcrux_ml_dsa::polynomial::"
      "PolynomialRingElement<T@0>[TraitClause@0, TraitClause@1], C@1>>] "
      "enumerate\")\n");
  KRML_HOST_EXIT(255U);
}

typedef struct
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_6size_t__x2_s {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 fst[6U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 snd[6U];
} libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_6size_t__x2;

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.power2round_vector
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- DIMENSION= 6
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_6size_t__x2
    libcrux_ml_dsa_arithmetic_power2round_vector_a3(
        libcrux_ml_dsa_polynomial_PolynomialRingElement_24 t[6U]) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"Error looking trait impl: "
      "core::slice::iter::{core::iter::traits::iterator::Iterator for "
      "core::slice::iter::Iter<\'a, T>[TraitClause@0]}#182<\'_, "
      "libcrux_ml_dsa::polynomial::PolynomialRingElement<T@0>[TraitClause@0, "
      "TraitClause@1]>[core::marker::Sized<libcrux_ml_dsa::polynomial::"
      "PolynomialRingElement<T@0>[TraitClause@0, TraitClause@1]>] "
      "enumerate\")\n");
  KRML_HOST_EXIT(255U);
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.verification_key.generate_serialized with types
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit with const generics
- ROWS_IN_A= 6
- VERIFICATION_KEY_SIZE= 1952
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_verification_key_generate_serialized_fe(
    Eurydice_slice seed_for_A,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 t1[6U],
    uint8_t ret[1952U]) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"Error looking trait impl: "
      "core::slice::iter::{core::iter::traits::iterator::Iterator for "
      "core::slice::iter::Iter<\'a, T>[TraitClause@0]}#182<\'_, "
      "libcrux_ml_dsa::polynomial::PolynomialRingElement<T@0>[TraitClause@0, "
      "TraitClause@1]>[core::marker::Sized<libcrux_ml_dsa::polynomial::"
      "PolynomialRingElement<T@0>[TraitClause@0, TraitClause@1]>] "
      "enumerate\")\n");
  KRML_HOST_EXIT(255U);
}

/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.simd256.shake256
with const generics
- OUTPUT_LENGTH= 64
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_hash_functions_simd256_shake256_24(
    Eurydice_slice input, uint8_t *out) {
  libcrux_sha3_portable_shake256(
      Eurydice_array_to_slice((size_t)64U, out, uint8_t), input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::simd256::Shake256)#1}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.simd256.shake256_d9
with const generics
- OUTPUT_LENGTH= 64
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_simd256_shake256_d9_24(Eurydice_slice input,
                                                     uint8_t *out) {
  libcrux_ml_dsa_hash_functions_simd256_shake256_24(input, out);
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.error.serialize
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics
- ETA= 4
- OUTPUT_SIZE= 128
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_error_serialize_a8(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 re, uint8_t ret[128U]) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"Error looking trait impl: "
      "core::slice::iter::{core::iter::traits::iterator::Iterator for "
      "core::slice::iter::Iter<\'a, T>[TraitClause@0]}#182<\'_, "
      "T@0>[TraitClause@0] enumerate\")\n");
  KRML_HOST_EXIT(255U);
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.t0.serialize
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit
with const generics

*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_t0_serialize_ea(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 re, uint8_t ret[416U]) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"Error looking trait impl: "
      "core::slice::iter::{core::iter::traits::iterator::Iterator for "
      "core::slice::iter::Iter<\'a, T>[TraitClause@0]}#182<\'_, "
      "T@0>[TraitClause@0] enumerate\")\n");
  KRML_HOST_EXIT(255U);
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.signing_key.generate_serialized with types
libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake256 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_signing_key_generate_serialized_a9(
    Eurydice_slice seed_for_A, Eurydice_slice seed_for_signing,
    Eurydice_slice verification_key,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s1[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s2[6U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 t0[6U],
    uint8_t ret[4032U]) {
  uint8_t signing_key_serialized[4032U] = {0U};
  size_t offset = (size_t)0U;
  Eurydice_slice_copy(
      Eurydice_array_to_subslice2(
          signing_key_serialized, offset,
          offset + LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE, uint8_t),
      seed_for_A, uint8_t);
  offset = offset + LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE;
  Eurydice_slice_copy(
      Eurydice_array_to_subslice2(
          signing_key_serialized, offset,
          offset + LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_SIGNING_SIZE, uint8_t),
      seed_for_signing, uint8_t);
  offset = offset + LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_SIGNING_SIZE;
  uint8_t verification_key_hash[64U] = {0U};
  libcrux_ml_dsa_hash_functions_simd256_shake256_d9_24(verification_key,
                                                       verification_key_hash);
  Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
      signing_key_serialized, offset,
      offset + LIBCRUX_ML_DSA_CONSTANTS_BYTES_FOR_VERIFICATION_KEY_HASH,
      uint8_t);
  Eurydice_slice_copy(
      uu____0,
      Eurydice_array_to_slice((size_t)64U, verification_key_hash, uint8_t),
      uint8_t);
  offset = offset + LIBCRUX_ML_DSA_CONSTANTS_BYTES_FOR_VERIFICATION_KEY_HASH;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)5U, s1,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_24),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_24);
       i++) {
    size_t _cloop_i = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 *ring_element =
        &s1[_cloop_i];
    Eurydice_slice uu____1 = Eurydice_array_to_subslice2(
        signing_key_serialized, offset, offset + (size_t)128U, uint8_t);
    uint8_t ret0[128U];
    libcrux_ml_dsa_encoding_error_serialize_a8(ring_element[0U], ret0);
    Eurydice_slice_copy(
        uu____1, Eurydice_array_to_slice((size_t)128U, ret0, uint8_t), uint8_t);
    offset = offset + (size_t)128U;
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, s2,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_24),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_24);
       i++) {
    size_t _cloop_i = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 *ring_element =
        &s2[_cloop_i];
    Eurydice_slice uu____2 = Eurydice_array_to_subslice2(
        signing_key_serialized, offset, offset + (size_t)128U, uint8_t);
    uint8_t ret0[128U];
    libcrux_ml_dsa_encoding_error_serialize_a8(ring_element[0U], ret0);
    Eurydice_slice_copy(
        uu____2, Eurydice_array_to_slice((size_t)128U, ret0, uint8_t), uint8_t);
    offset = offset + (size_t)128U;
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, t0,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_24),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_24);
       i++) {
    size_t _cloop_i = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_24 *ring_element =
        &t0[_cloop_i];
    Eurydice_slice uu____3 = Eurydice_array_to_subslice2(
        signing_key_serialized, offset,
        offset + LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE, uint8_t);
    uint8_t ret0[416U];
    libcrux_ml_dsa_encoding_t0_serialize_ea(ring_element[0U], ret0);
    Eurydice_slice_copy(
        uu____3, Eurydice_array_to_slice((size_t)416U, ret0, uint8_t), uint8_t);
    offset = offset + LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE;
  }
  memcpy(ret, signing_key_serialized, (size_t)4032U * sizeof(uint8_t));
}

/**
 Generate a key pair.
*/
/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.generate_key_pair
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake128x4,
libcrux_ml_dsa_hash_functions_simd256_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
- VERIFICATION_KEY_SIZE= 1952
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE tuple_a0
libcrux_ml_dsa_ml_dsa_generic_generate_key_pair_bc(uint8_t randomness[32U]) {
  uint8_t seed_expanded0[128U] = {0U};
  libcrux_sha3_portable_incremental_Shake256Xof shake =
      libcrux_ml_dsa_hash_functions_portable_init_83();
  libcrux_ml_dsa_hash_functions_portable_absorb_83(
      &shake, Eurydice_array_to_slice((size_t)32U, randomness, uint8_t));
  uint8_t buf[2U] = {(uint8_t)(size_t)6U, (uint8_t)(size_t)5U};
  libcrux_ml_dsa_hash_functions_portable_absorb_final_83(
      &shake, Eurydice_array_to_slice((size_t)2U, buf, uint8_t));
  libcrux_ml_dsa_hash_functions_portable_squeeze_83(
      &shake, Eurydice_array_to_slice((size_t)128U, seed_expanded0, uint8_t));
  Eurydice_slice_uint8_t_x2 uu____0 = Eurydice_slice_split_at(
      Eurydice_array_to_slice((size_t)128U, seed_expanded0, uint8_t),
      LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE, uint8_t,
      Eurydice_slice_uint8_t_x2);
  Eurydice_slice seed_for_a = uu____0.fst;
  Eurydice_slice seed_expanded = uu____0.snd;
  Eurydice_slice_uint8_t_x2 uu____1 = Eurydice_slice_split_at(
      seed_expanded, LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_ERROR_VECTORS_SIZE,
      uint8_t, Eurydice_slice_uint8_t_x2);
  Eurydice_slice seed_for_error_vectors = uu____1.fst;
  Eurydice_slice seed_for_signing = uu____1.snd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 a_as_ntt[6U][5U];
  uint8_t ret[34U];
  libcrux_ml_dsa_utils_into_padded_array_b6(seed_for_a, ret);
  libcrux_ml_dsa_samplex4_matrix_A_fe(ret, a_as_ntt);
  uint8_t ret0[66U];
  libcrux_ml_dsa_utils_into_padded_array_20(seed_for_error_vectors, ret0);
  tuple_ce0 uu____2 = libcrux_ml_dsa_samplex4_sample_s1_and_s2_4d(ret0);
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s1[5U];
  memcpy(
      s1, uu____2.fst,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 s2[6U];
  memcpy(
      s2, uu____2.snd,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 t[6U];
  libcrux_ml_dsa_matrix_compute_As1_plus_s2_fe(a_as_ntt, s1, s2, t);
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_t[6U];
  memcpy(
      copy_of_t, t,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit_6size_t__x2
      uu____4 = libcrux_ml_dsa_arithmetic_power2round_vector_a3(copy_of_t);
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 t0[6U];
  memcpy(
      t0, uu____4.fst,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 t1[6U];
  memcpy(
      t1, uu____4.snd,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  Eurydice_slice uu____5 = seed_for_a;
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_t1[6U];
  memcpy(
      copy_of_t1, t1,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  uint8_t verification_key_serialized[1952U];
  libcrux_ml_dsa_encoding_verification_key_generate_serialized_fe(
      uu____5, copy_of_t1, verification_key_serialized);
  Eurydice_slice uu____7 = seed_for_a;
  Eurydice_slice uu____8 = seed_for_signing;
  Eurydice_slice uu____9 = Eurydice_array_to_slice(
      (size_t)1952U, verification_key_serialized, uint8_t);
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_s2[6U];
  memcpy(
      copy_of_s2, s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_24 copy_of_t0[6U];
  memcpy(
      copy_of_t0, t0,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_24));
  uint8_t signing_key_serialized[4032U];
  libcrux_ml_dsa_encoding_signing_key_generate_serialized_a9(
      uu____7, uu____8, uu____9, copy_of_s1, copy_of_s2, copy_of_t0,
      signing_key_serialized);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_signing_key_serialized[4032U];
  memcpy(copy_of_signing_key_serialized, signing_key_serialized,
         (size_t)4032U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_verification_key_serialized[1952U];
  memcpy(copy_of_verification_key_serialized, verification_key_serialized,
         (size_t)1952U * sizeof(uint8_t));
  tuple_a0 lit;
  memcpy(lit.fst, copy_of_signing_key_serialized,
         (size_t)4032U * sizeof(uint8_t));
  memcpy(lit.snd, copy_of_verification_key_serialized,
         (size_t)1952U * sizeof(uint8_t));
  return lit;
}

/**
 Generate key pair.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.avx2_feature.generate_key_pair
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
- VERIFICATION_KEY_SIZE= 1952
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline tuple_a0
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_generate_key_pair_52(
    uint8_t randomness[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_generate_key_pair_bc(copy_of_randomness);
}

/**
 Generate key pair.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.generate_key_pair with const
generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
- VERIFICATION_KEY_SIZE= 1952
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline tuple_a0
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_generate_key_pair_52(
    uint8_t randomness[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_generate_key_pair_52(
      copy_of_randomness);
}

/**
 Generate an ML-DSA-65 Key Pair
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline libcrux_ml_dsa_ml_dsa_65_MLDSA65KeyPair
libcrux_ml_dsa_ml_dsa_65_avx2_generate_key_pair(uint8_t randomness[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  tuple_a0 uu____1 =
      libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_generate_key_pair_52(
          copy_of_randomness);
  uint8_t signing_key[4032U];
  memcpy(signing_key, uu____1.fst, (size_t)4032U * sizeof(uint8_t));
  uint8_t verification_key[1952U];
  memcpy(verification_key, uu____1.snd, (size_t)1952U * sizeof(uint8_t));
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_signing_key[4032U];
  memcpy(copy_of_signing_key, signing_key, (size_t)4032U * sizeof(uint8_t));
  libcrux_ml_dsa_types_MLDSASigningKey_22 uu____3 =
      libcrux_ml_dsa_types_new_9b_09(copy_of_signing_key);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_verification_key[1952U];
  memcpy(copy_of_verification_key, verification_key,
         (size_t)1952U * sizeof(uint8_t));
  libcrux_ml_dsa_ml_dsa_65_MLDSA65KeyPair lit;
  lit.signing_key = uu____3;
  lit.verification_key =
      libcrux_ml_dsa_types_new_66_97(copy_of_verification_key);
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.sign
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake128x4,
libcrux_ml_dsa_hash_functions_simd256_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- GAMMA1_EXPONENT= 19
- GAMMA2= 261888
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
- GAMMA1_RING_ELEMENT_SIZE= 640
- SIGNING_KEY_SIZE= 4032
- SIGNATURE_SIZE= 3309
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE Result_2e libcrux_ml_dsa_ml_dsa_generic_sign_ea(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"TODO: TraitTypes "
      "core::result::{core::ops::try_trait::Try for core::result::Result<T, "
      "E>[TraitClause@0, TraitClause@1]}#26<T@0, T@1>[TraitClause@0, "
      "TraitClause@1]::Residual\")\n");
  KRML_HOST_EXIT(255U);
}

/**
 Sign.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.avx2_feature.sign with const
generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- GAMMA1_EXPONENT= 19
- GAMMA2= 261888
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
- GAMMA1_RING_ELEMENT_SIZE= 640
- SIGNING_KEY_SIZE= 4032
- SIGNATURE_SIZE= 3309
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_2e
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_sign_f3(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  uint8_t *uu____0 = signing_key;
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_sign_ea(uu____0, uu____1, uu____2,
                                               copy_of_randomness);
}

/**
 Sign.
*/
/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.sign
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- GAMMA1_EXPONENT= 19
- GAMMA2= 261888
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
- GAMMA1_RING_ELEMENT_SIZE= 640
- SIGNING_KEY_SIZE= 4032
- SIGNATURE_SIZE= 3309
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE Result_2e
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_sign_f3(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  uint8_t *uu____0 = signing_key;
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_sign_f3(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
 Generate an ML-DSA-65 Signature

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_2e libcrux_ml_dsa_ml_dsa_65_avx2_sign(
    libcrux_ml_dsa_types_MLDSASigningKey_22 *signing_key,
    Eurydice_slice message, Eurydice_slice context, uint8_t randomness[32U]) {
  uint8_t *uu____0 = libcrux_ml_dsa_types_as_raw_9b_09(signing_key);
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_sign_f3(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.sign_pre_hashed
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake128,
libcrux_ml_dsa_hash_functions_simd256_Shake128x4,
libcrux_ml_dsa_hash_functions_simd256_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_simd256_Shake256x4,
libcrux_ml_dsa_pre_hash_SHAKE128_PH with const generics
- PH_DIGEST_LEN= 256
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- GAMMA1_EXPONENT= 19
- GAMMA2= 261888
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
- GAMMA1_RING_ELEMENT_SIZE= 640
- SIGNING_KEY_SIZE= 4032
- SIGNATURE_SIZE= 3309
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE Result_2e
libcrux_ml_dsa_ml_dsa_generic_sign_pre_hashed_6e(uint8_t *signing_key,
                                                 Eurydice_slice message,
                                                 Eurydice_slice context,
                                                 uint8_t randomness[32U]) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "Eurydice error: Failure(\"expression_of_operand Constant: "
                    "TraitClause@13OID\")\n");
  KRML_HOST_EXIT(255U);
}

/**
 Sign (pre-hashed).
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.avx2_feature.sign_pre_hashed_shake128
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- GAMMA1_EXPONENT= 19
- GAMMA2= 261888
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
- GAMMA1_RING_ELEMENT_SIZE= 640
- SIGNING_KEY_SIZE= 4032
- SIGNATURE_SIZE= 3309
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_2e
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_sign_pre_hashed_shake128_f3(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  uint8_t *uu____0 = signing_key;
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_sign_pre_hashed_6e(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
 Sign (pre-hashed).
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.sign_pre_hashed_shake128 with
const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- GAMMA1_EXPONENT= 19
- GAMMA2= 261888
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
- GAMMA1_RING_ELEMENT_SIZE= 640
- SIGNING_KEY_SIZE= 4032
- SIGNATURE_SIZE= 3309
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_2e
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_sign_pre_hashed_shake128_f3(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  uint8_t *uu____0 = signing_key;
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_sign_pre_hashed_shake128_f3(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
 Generate a HashML-DSA-65 Signature, with a SHAKE128 pre-hashing

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_2e libcrux_ml_dsa_ml_dsa_65_avx2_sign_pre_hashed_shake128(
    libcrux_ml_dsa_types_MLDSASigningKey_22 *signing_key,
    Eurydice_slice message, Eurydice_slice context, uint8_t randomness[32U]) {
  uint8_t *uu____0 = libcrux_ml_dsa_types_as_raw_9b_09(signing_key);
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_sign_pre_hashed_shake128_f3(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.verify
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_simd256_Shake128x4,
libcrux_ml_dsa_hash_functions_simd256_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- SIGNATURE_SIZE= 3309
- VERIFICATION_KEY_SIZE= 1952
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- GAMMA2= 261888
- BETA= 196
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE Result_41 libcrux_ml_dsa_ml_dsa_generic_verify_d1(
    uint8_t *verification_key_serialized, Eurydice_slice message,
    Eurydice_slice context, uint8_t *signature_serialized) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"TODO: TraitTypes "
      "core::result::{core::ops::try_trait::Try for core::result::Result<T, "
      "E>[TraitClause@0, TraitClause@1]}#26<T@0, T@1>[TraitClause@0, "
      "TraitClause@1]::Residual\")\n");
  KRML_HOST_EXIT(255U);
}

/**
 Verify.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.avx2_feature.verify with const
generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- SIGNATURE_SIZE= 3309
- VERIFICATION_KEY_SIZE= 1952
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- GAMMA2= 261888
- BETA= 196
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_41
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_verify_01(
    uint8_t *verification_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_verify_d1(verification_key, message,
                                                 context, signature);
}

/**
 Verify.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.verify with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- SIGNATURE_SIZE= 3309
- VERIFICATION_KEY_SIZE= 1952
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- GAMMA2= 261888
- BETA= 196
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_41
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_verify_01(
    uint8_t *verification_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_verify_01(
      verification_key, message, context, signature);
}

/**
 Verify an ML-DSA-65 Signature

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_41 libcrux_ml_dsa_ml_dsa_65_avx2_verify(
    libcrux_ml_dsa_types_MLDSAVerificationKey_ea *verification_key,
    Eurydice_slice message, Eurydice_slice context,
    libcrux_ml_dsa_ml_dsa_65_MLDSA65Signature *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_verify_01(
      libcrux_ml_dsa_types_as_raw_66_97(verification_key), message, context,
      libcrux_ml_dsa_types_as_raw_8f_fa(signature));
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.verify_pre_hashed
with types libcrux_ml_dsa_simd_avx2_vector_type_AVX2SIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake128,
libcrux_ml_dsa_hash_functions_simd256_Shake128x4,
libcrux_ml_dsa_hash_functions_simd256_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_pre_hash_SHAKE128_PH with const generics
- PH_DIGEST_LEN= 256
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- SIGNATURE_SIZE= 3309
- VERIFICATION_KEY_SIZE= 1952
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- GAMMA2= 261888
- BETA= 196
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
*/
KRML_ATTRIBUTE_TARGET("avx2")
static KRML_MUSTINLINE Result_41
libcrux_ml_dsa_ml_dsa_generic_verify_pre_hashed_07(
    uint8_t *verification_key_serialized, Eurydice_slice message,
    Eurydice_slice context, uint8_t *signature_serialized) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "Eurydice error: Failure(\"expression_of_operand Constant: "
                    "TraitClause@11OID\")\n");
  KRML_HOST_EXIT(255U);
}

/**
 Verify (pre-hashed with SHAKE-128).
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.avx2_feature.verify_pre_hashed_shake128
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- SIGNATURE_SIZE= 3309
- VERIFICATION_KEY_SIZE= 1952
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- GAMMA2= 261888
- BETA= 196
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_41
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_verify_pre_hashed_shake128_01(
    uint8_t *verification_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_verify_pre_hashed_07(
      verification_key, message, context, signature);
}

/**
 Verify (pre-hashed with SHAKE-128).
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.avx2.verify_pre_hashed_shake128
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- SIGNATURE_SIZE= 3309
- VERIFICATION_KEY_SIZE= 1952
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- GAMMA2= 261888
- BETA= 196
- COMMITMENT_RING_ELEMENT_SIZE= 128
- COMMITMENT_VECTOR_SIZE= 768
- COMMITMENT_HASH_SIZE= 48
- ONES_IN_VERIFIER_CHALLENGE= 49
- MAX_ONES_IN_HINT= 55
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_41
libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_verify_pre_hashed_shake128_01(
    uint8_t *verification_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_avx2_feature_verify_pre_hashed_shake128_01(
      verification_key, message, context, signature);
}

/**
 Verify a HashML-DSA-65 Signature, with a SHAKE128 pre-hashing

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline Result_41
libcrux_ml_dsa_ml_dsa_65_avx2_verify_pre_hashed_shake128(
    libcrux_ml_dsa_types_MLDSAVerificationKey_ea *verification_key,
    Eurydice_slice message, Eurydice_slice context,
    libcrux_ml_dsa_ml_dsa_65_MLDSA65Signature *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_avx2_verify_pre_hashed_shake128_01(
      libcrux_ml_dsa_types_as_raw_66_97(verification_key), message, context,
      libcrux_ml_dsa_types_as_raw_8f_fa(signature));
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline bool
libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_is_bit_set(
    size_t number, uint8_t bit_position) {
  return (number & (size_t)1U << (uint32_t)bit_position) >>
             (uint32_t)bit_position ==
         (size_t)1U;
}

KRML_ATTRIBUTE_TARGET("avx2")
static inline void
libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_generate_shuffle_table(
    uint8_t ret[16U][16U]) {
  uint8_t byte_shuffles[16U][16U] = {
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U},
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
       255U, 255U, 255U, 255U}};
  for (size_t i0 = (size_t)0U; i0 < (size_t)1U << 4U; i0++) {
    size_t bit_pattern = i0;
    size_t byte_shuffles_index = (size_t)0U;
    for (uint8_t i = 0U; i < 4U; i = (uint32_t)i + 1U) {
      uint8_t bit_position = i;
      if (libcrux_ml_dsa_simd_avx2_rejection_sample_shuffle_table_is_bit_set(
              bit_pattern, bit_position)) {
        byte_shuffles[bit_pattern][byte_shuffles_index] =
            (uint32_t)bit_position * 4U;
        byte_shuffles_index++;
        byte_shuffles[bit_pattern][byte_shuffles_index] =
            (uint32_t)bit_position * 4U + 1U;
        byte_shuffles_index++;
        byte_shuffles[bit_pattern][byte_shuffles_index] =
            (uint32_t)bit_position * 4U + 2U;
        byte_shuffles_index++;
        byte_shuffles[bit_pattern][byte_shuffles_index] =
            (uint32_t)bit_position * 4U + 3U;
        byte_shuffles_index++;
      }
    }
  }
  memcpy(ret, byte_shuffles, (size_t)16U * sizeof(uint8_t[16U]));
}

/**
This function found in impl {(core::clone::Clone for
libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)#1}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i libcrux_ml_dsa_simd_avx2_vector_type_clone_0f(
    __m256i *self) {
  return self[0U];
}

/**
This function found in impl {(core::convert::From<core::core_arch::x86::__m256i>
for libcrux_ml_dsa::simd::avx2::vector_type::AVX2SIMDUnit)}
*/
KRML_ATTRIBUTE_TARGET("avx2")
static inline __m256i libcrux_ml_dsa_simd_avx2_vector_type_from_af(
    __m256i coefficients) {
  return coefficients;
}

#if defined(__cplusplus)
}
#endif

#define __libcrux_mldsa65_avx2_H_DEFINED
#endif