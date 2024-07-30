/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 45b95e0f63cb830202c0b3ca00a341a3451a02ba
 * Eurydice: 0eb8a17354fd62586cb9f7515af23f4488c2267e
 * Karamel: d5759a8b96e9f104664a88a83043d5761fcc9732
 * F*: b2931dfbe46e839cd757220c63d48c71335bb1ae
 * Libcrux: 3c17ede9a23cf909c9b39d1789bb88291c7d6896
 */

#ifndef __libcrux_mlkem_neon_H
#define __libcrux_mlkem_neon_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"
#include "libcrux_mlkem_portable.h"
#include "libcrux_sha3_neon.h"

void libcrux_ml_kem_hash_functions_neon_G(Eurydice_slice input,
                                          uint8_t ret[64U]);

void libcrux_ml_kem_hash_functions_neon_H(Eurydice_slice input,
                                          uint8_t ret[32U]);

typedef struct libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector_s {
  core_core_arch_arm_shared_neon_int16x8_t low;
  core_core_arch_arm_shared_neon_int16x8_t high;
} libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector;

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_vector_type_ZERO(void);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___ZERO(
    void);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_vector_type_from_i16_array(Eurydice_slice array);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___from_i16_array(
    Eurydice_slice array);

void libcrux_ml_kem_vector_neon_vector_type_to_i16_array(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t ret[16U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___to_i16_array(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector x, int16_t ret[16U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_add(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector lhs,
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *rhs);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___add(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector lhs,
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *rhs);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_sub(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector lhs,
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *rhs);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___sub(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector lhs,
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *rhs);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_multiply_by_constant(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___multiply_by_constant(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_bitwise_and_with_constant(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___bitwise_and_with_constant(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_cond_subtract_3329(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___cond_subtract_3329(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v);

#define LIBCRUX_ML_KEM_VECTOR_NEON_ARITHMETIC_BARRETT_MULTIPLIER \
  ((int16_t)20159)

core_core_arch_arm_shared_neon_int16x8_t
libcrux_ml_kem_vector_neon_arithmetic_barrett_reduce_int16x8_t(
    core_core_arch_arm_shared_neon_int16x8_t v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_barrett_reduce(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___barrett_reduce(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v);

core_core_arch_arm_shared_neon_int16x8_t
libcrux_ml_kem_vector_neon_arithmetic_montgomery_reduce_int16x8_t(
    core_core_arch_arm_shared_neon_int16x8_t low,
    core_core_arch_arm_shared_neon_int16x8_t high);

core_core_arch_arm_shared_neon_int16x8_t
libcrux_ml_kem_vector_neon_arithmetic_montgomery_multiply_by_constant_int16x8_t(
    core_core_arch_arm_shared_neon_int16x8_t v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_arithmetic_montgomery_multiply_by_constant(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___montgomery_multiply_by_constant(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_compress_compress_1(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___compress_1(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v);

int16_t libcrux_ml_kem_vector_neon_compress_mask_n_least_significant_bits(
    int16_t coefficient_bits);

core_core_arch_arm_shared_neon_int16x8_t
libcrux_ml_kem_vector_neon_arithmetic_montgomery_multiply_int16x8_t(
    core_core_arch_arm_shared_neon_int16x8_t v,
    core_core_arch_arm_shared_neon_int16x8_t c);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_ntt_layer_1_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t zeta1,
    int16_t zeta2, int16_t zeta3, int16_t zeta4);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___ntt_layer_1_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, int16_t zeta1,
    int16_t zeta2, int16_t zeta3, int16_t zeta4);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_ntt_layer_2_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t zeta1,
    int16_t zeta2);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___ntt_layer_2_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, int16_t zeta1,
    int16_t zeta2);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_ntt_layer_3_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t zeta);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___ntt_layer_3_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, int16_t zeta);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_inv_ntt_layer_1_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t zeta1,
    int16_t zeta2, int16_t zeta3, int16_t zeta4);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___inv_ntt_layer_1_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, int16_t zeta1,
    int16_t zeta2, int16_t zeta3, int16_t zeta4);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_inv_ntt_layer_2_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t zeta1,
    int16_t zeta2);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___inv_ntt_layer_2_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, int16_t zeta1,
    int16_t zeta2);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_inv_ntt_layer_3_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, int16_t zeta);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___inv_ntt_layer_3_step(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, int16_t zeta);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_ntt_ntt_multiply(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *lhs,
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *rhs, int16_t zeta1,
    int16_t zeta2, int16_t zeta3, int16_t zeta4);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___ntt_multiply(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *lhs,
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *rhs, int16_t zeta1,
    int16_t zeta2, int16_t zeta3, int16_t zeta4);

void libcrux_ml_kem_vector_neon_serialize_serialize_1(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, uint8_t ret[2U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___serialize_1(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, uint8_t ret[2U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_serialize_deserialize_1(Eurydice_slice a);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___deserialize_1(
    Eurydice_slice a);

void libcrux_ml_kem_vector_neon_serialize_serialize_4(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, uint8_t ret[8U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___serialize_4(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, uint8_t ret[8U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_serialize_deserialize_4(Eurydice_slice v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___deserialize_4(
    Eurydice_slice a);

void libcrux_ml_kem_vector_neon_serialize_serialize_5(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, uint8_t ret[10U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___serialize_5(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, uint8_t ret[10U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_serialize_deserialize_5(Eurydice_slice v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___deserialize_5(
    Eurydice_slice a);

void libcrux_ml_kem_vector_neon_serialize_serialize_10(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, uint8_t ret[20U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___serialize_10(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, uint8_t ret[20U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_serialize_deserialize_10(Eurydice_slice v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___deserialize_10(
    Eurydice_slice a);

void libcrux_ml_kem_vector_neon_serialize_serialize_11(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, uint8_t ret[22U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___serialize_11(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, uint8_t ret[22U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_serialize_deserialize_11(Eurydice_slice v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___deserialize_11(
    Eurydice_slice a);

void libcrux_ml_kem_vector_neon_serialize_serialize_12(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector v, uint8_t ret[24U]);

void libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___serialize_12(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector a, uint8_t ret[24U]);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_serialize_deserialize_12(Eurydice_slice v);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___deserialize_12(
    Eurydice_slice a);

size_t libcrux_ml_kem_vector_neon_rej_sample(Eurydice_slice a,
                                             Eurydice_slice result);

size_t
libcrux_ml_kem_vector_neon___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___rej_sample(
    Eurydice_slice a, Eurydice_slice out);

libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
libcrux_ml_kem_vector_neon_vector_type___core__clone__Clone_for_libcrux_ml_kem__vector__neon__vector_type__SIMD128Vector___clone(
    libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector *self);

typedef struct
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector_s {
  libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector coefficients[16U];
} libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector;

typedef struct
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      secret_as_ntt[2U];
} libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t_s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t
      ind_cpa_private_key;
  uint8_t implicit_rejection_value[32U];
} libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t;

typedef struct
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      t_as_ntt[2U];
  uint8_t seed_for_A[32U];
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      A[2U][2U];
} libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t_s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t
      ind_cpa_public_key;
  uint8_t public_key_hash[32U];
} libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t_s {
  libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t
      private_key;
  libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t
      public_key;
} libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__2size_t;

typedef struct
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      secret_as_ntt[3U];
} libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t_s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t
      ind_cpa_private_key;
  uint8_t implicit_rejection_value[32U];
} libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t;

typedef struct
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      t_as_ntt[3U];
  uint8_t seed_for_A[32U];
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      A[3U][3U];
} libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t_s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t
      ind_cpa_public_key;
  uint8_t public_key_hash[32U];
} libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t_s {
  libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t
      private_key;
  libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t
      public_key;
} libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__3size_t;

typedef struct
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      secret_as_ntt[4U];
} libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t_s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t
      ind_cpa_private_key;
  uint8_t implicit_rejection_value[32U];
} libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t;

typedef struct
    libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      t_as_ntt[4U];
  uint8_t seed_for_A[32U];
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector
      A[4U][4U];
} libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t_s {
  libcrux_ml_kem_ind_cpa_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t
      ind_cpa_public_key;
  uint8_t public_key_hash[32U];
} libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t;

typedef struct
    libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t_s {
  libcrux_ml_kem_ind_cca_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t
      private_key;
  libcrux_ml_kem_ind_cca_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t
      public_key;
} libcrux_ml_kem_ind_cca_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_neon_vector_type_SIMD128Vector__4size_t;

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem_neon_H_DEFINED
#endif
