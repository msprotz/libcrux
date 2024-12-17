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
 * Libcrux: 229548656e4eaa1324c514638f9f8d135499a5c1
 */

#ifndef __libcrux_mldsa65_portable_H
#define __libcrux_mldsa65_portable_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"
#include "libcrux_sha3_portable.h"

#define LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT ((size_t)8U)

#define LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT ((size_t)256U)

#define LIBCRUX_ML_DSA_SIMD_TRAITS_SIMD_UNITS_IN_RING_ELEMENT \
  (LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT /    \
   LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT)

#define LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T ((size_t)13U)

#define LIBCRUX_ML_DSA_CONSTANTS_FIELD_MODULUS_MINUS_ONE_BIT_LENGTH \
  ((size_t)23U)

#define LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_UPPER_PART_OF_T         \
  (LIBCRUX_ML_DSA_CONSTANTS_FIELD_MODULUS_MINUS_ONE_BIT_LENGTH - \
   LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T)

#define LIBCRUX_ML_DSA_CONSTANTS_BYTES_FOR_VERIFICATION_KEY_HASH ((size_t)64U)

#define LIBCRUX_ML_DSA_CONSTANTS_CONTEXT_MAX_LEN ((size_t)255U)

#define LIBCRUX_ML_DSA_CONSTANTS_FIELD_MODULUS ((int32_t)8380417)

#define LIBCRUX_ML_DSA_CONSTANTS_KEY_GENERATION_RANDOMNESS_SIZE ((size_t)32U)

#define LIBCRUX_ML_DSA_CONSTANTS_MASK_SEED_SIZE ((size_t)64U)

#define LIBCRUX_ML_DSA_CONSTANTS_MESSAGE_REPRESENTATIVE_SIZE ((size_t)64U)

#define LIBCRUX_ML_DSA_CONSTANTS_REJECTION_SAMPLE_BOUND_SIGN ((size_t)814U)

#define LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE \
  (LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T *     \
   LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T1S_SIZE \
  (LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_UPPER_PART_OF_T *     \
   LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE ((size_t)32U)

#define LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_ERROR_VECTORS_SIZE ((size_t)64U)

#define LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_SIGNING_SIZE ((size_t)32U)

#define LIBCRUX_ML_DSA_CONSTANTS_SIGNING_RANDOMNESS_SIZE ((size_t)32U)

#define LIBCRUX_ML_DSA_ENCODING_T0_OUTPUT_BYTES_PER_SIMD_UNIT ((size_t)13U)

#define LIBCRUX_ML_DSA_ENCODING_T1_SERIALIZE_OUTPUT_BYTES_PER_SIMD_UNIT \
  ((size_t)10U)

typedef struct libcrux_ml_dsa_hash_functions_portable_Shake128X4_s {
  libcrux_sha3_generic_keccak_KeccakState_17 state0;
  libcrux_sha3_generic_keccak_KeccakState_17 state1;
  libcrux_sha3_generic_keccak_KeccakState_17 state2;
  libcrux_sha3_generic_keccak_KeccakState_17 state3;
} libcrux_ml_dsa_hash_functions_portable_Shake128X4;

static KRML_MUSTINLINE libcrux_ml_dsa_hash_functions_portable_Shake128X4
libcrux_ml_dsa_hash_functions_portable_init_absorb(Eurydice_slice input0,
                                                   Eurydice_slice input1,
                                                   Eurydice_slice input2,
                                                   Eurydice_slice input3) {
  libcrux_sha3_generic_keccak_KeccakState_17 state0 =
      libcrux_sha3_portable_incremental_shake128_init();
  libcrux_sha3_portable_incremental_shake128_absorb_final(&state0, input0);
  libcrux_sha3_generic_keccak_KeccakState_17 state1 =
      libcrux_sha3_portable_incremental_shake128_init();
  libcrux_sha3_portable_incremental_shake128_absorb_final(&state1, input1);
  libcrux_sha3_generic_keccak_KeccakState_17 state2 =
      libcrux_sha3_portable_incremental_shake128_init();
  libcrux_sha3_portable_incremental_shake128_absorb_final(&state2, input2);
  libcrux_sha3_generic_keccak_KeccakState_17 state3 =
      libcrux_sha3_portable_incremental_shake128_init();
  libcrux_sha3_portable_incremental_shake128_absorb_final(&state3, input3);
  return (CLITERAL(libcrux_ml_dsa_hash_functions_portable_Shake128X4){
      .state0 = state0, .state1 = state1, .state2 = state2, .state3 = state3});
}

typedef libcrux_sha3_portable_KeccakState
    libcrux_ml_dsa_hash_functions_portable_Shake256;

static KRML_MUSTINLINE libcrux_sha3_portable_KeccakState
libcrux_ml_dsa_hash_functions_portable_init_absorb_final_shake256(
    Eurydice_slice input) {
  libcrux_sha3_generic_keccak_KeccakState_17 state =
      libcrux_sha3_portable_incremental_shake256_init();
  libcrux_sha3_portable_incremental_shake256_absorb_final(&state, input);
  return state;
}

typedef struct libcrux_ml_dsa_hash_functions_portable_Shake256X4_s {
  libcrux_sha3_generic_keccak_KeccakState_17 state0;
  libcrux_sha3_generic_keccak_KeccakState_17 state1;
  libcrux_sha3_generic_keccak_KeccakState_17 state2;
  libcrux_sha3_generic_keccak_KeccakState_17 state3;
} libcrux_ml_dsa_hash_functions_portable_Shake256X4;

static KRML_MUSTINLINE libcrux_ml_dsa_hash_functions_portable_Shake256X4
libcrux_ml_dsa_hash_functions_portable_init_absorb_x4(Eurydice_slice input0,
                                                      Eurydice_slice input1,
                                                      Eurydice_slice input2,
                                                      Eurydice_slice input3) {
  libcrux_sha3_generic_keccak_KeccakState_17 state0 =
      libcrux_sha3_portable_incremental_shake256_init();
  libcrux_sha3_portable_incremental_shake256_absorb_final(&state0, input0);
  libcrux_sha3_generic_keccak_KeccakState_17 state1 =
      libcrux_sha3_portable_incremental_shake256_init();
  libcrux_sha3_portable_incremental_shake256_absorb_final(&state1, input1);
  libcrux_sha3_generic_keccak_KeccakState_17 state2 =
      libcrux_sha3_portable_incremental_shake256_init();
  libcrux_sha3_portable_incremental_shake256_absorb_final(&state2, input2);
  libcrux_sha3_generic_keccak_KeccakState_17 state3 =
      libcrux_sha3_portable_incremental_shake256_init();
  libcrux_sha3_portable_incremental_shake256_absorb_final(&state3, input3);
  return (CLITERAL(libcrux_ml_dsa_hash_functions_portable_Shake256X4){
      .state0 = state0, .state1 = state1, .state2 = state2, .state3 = state3});
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_shake256(
    libcrux_sha3_portable_KeccakState *state, uint8_t ret[136U]) {
  uint8_t out[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_first_block(
      state, Eurydice_array_to_slice((size_t)136U, out, uint8_t));
  memcpy(ret, out, (size_t)136U * sizeof(uint8_t));
}

typedef struct uint8_t_136size_t__x4_s {
  uint8_t fst[136U];
  uint8_t snd[136U];
  uint8_t thd[136U];
  uint8_t f3[136U];
} uint8_t_136size_t__x4;

static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_x4(
    libcrux_ml_dsa_hash_functions_portable_Shake256X4 *state) {
  uint8_t out0[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_first_block(
      &state->state0, Eurydice_array_to_slice((size_t)136U, out0, uint8_t));
  uint8_t out1[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_first_block(
      &state->state1, Eurydice_array_to_slice((size_t)136U, out1, uint8_t));
  uint8_t out2[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_first_block(
      &state->state2, Eurydice_array_to_slice((size_t)136U, out2, uint8_t));
  uint8_t out3[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_first_block(
      &state->state3, Eurydice_array_to_slice((size_t)136U, out3, uint8_t));
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

static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_squeeze_first_five_blocks(
    libcrux_ml_dsa_hash_functions_portable_Shake128X4 *state, uint8_t *out0,
    uint8_t *out1, uint8_t *out2, uint8_t *out3) {
  libcrux_sha3_portable_incremental_shake128_squeeze_first_five_blocks(
      &state->state0, Eurydice_array_to_slice((size_t)840U, out0, uint8_t));
  libcrux_sha3_portable_incremental_shake128_squeeze_first_five_blocks(
      &state->state1, Eurydice_array_to_slice((size_t)840U, out1, uint8_t));
  libcrux_sha3_portable_incremental_shake128_squeeze_first_five_blocks(
      &state->state2, Eurydice_array_to_slice((size_t)840U, out2, uint8_t));
  libcrux_sha3_portable_incremental_shake128_squeeze_first_five_blocks(
      &state->state3, Eurydice_array_to_slice((size_t)840U, out3, uint8_t));
}

typedef struct uint8_t_168size_t__x4_s {
  uint8_t fst[168U];
  uint8_t snd[168U];
  uint8_t thd[168U];
  uint8_t f3[168U];
} uint8_t_168size_t__x4;

static KRML_MUSTINLINE uint8_t_168size_t__x4
libcrux_ml_dsa_hash_functions_portable_squeeze_next_block(
    libcrux_ml_dsa_hash_functions_portable_Shake128X4 *state) {
  uint8_t out0[168U] = {0U};
  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
      &state->state0, Eurydice_array_to_slice((size_t)168U, out0, uint8_t));
  uint8_t out1[168U] = {0U};
  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
      &state->state1, Eurydice_array_to_slice((size_t)168U, out1, uint8_t));
  uint8_t out2[168U] = {0U};
  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
      &state->state2, Eurydice_array_to_slice((size_t)168U, out2, uint8_t));
  uint8_t out3[168U] = {0U};
  libcrux_sha3_portable_incremental_shake128_squeeze_next_block(
      &state->state3, Eurydice_array_to_slice((size_t)168U, out3, uint8_t));
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

static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_shake256(
    libcrux_sha3_portable_KeccakState *state, uint8_t ret[136U]) {
  uint8_t out[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_next_block(
      state, Eurydice_array_to_slice((size_t)136U, out, uint8_t));
  memcpy(ret, out, (size_t)136U * sizeof(uint8_t));
}

static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4(
    libcrux_ml_dsa_hash_functions_portable_Shake256X4 *state) {
  uint8_t out0[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_next_block(
      &state->state0, Eurydice_array_to_slice((size_t)136U, out0, uint8_t));
  uint8_t out1[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_next_block(
      &state->state1, Eurydice_array_to_slice((size_t)136U, out1, uint8_t));
  uint8_t out2[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_next_block(
      &state->state2, Eurydice_array_to_slice((size_t)136U, out2, uint8_t));
  uint8_t out3[136U] = {0U};
  libcrux_sha3_portable_incremental_shake256_squeeze_next_block(
      &state->state3, Eurydice_array_to_slice((size_t)136U, out3, uint8_t));
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
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake128X4)}
*/
static KRML_MUSTINLINE libcrux_ml_dsa_hash_functions_portable_Shake128X4
libcrux_ml_dsa_hash_functions_portable_init_absorb_ed(Eurydice_slice input0,
                                                      Eurydice_slice input1,
                                                      Eurydice_slice input2,
                                                      Eurydice_slice input3) {
  return libcrux_ml_dsa_hash_functions_portable_init_absorb(input0, input1,
                                                            input2, input3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake128X4)}
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_squeeze_first_five_blocks_ed(
    libcrux_ml_dsa_hash_functions_portable_Shake128X4 *self, uint8_t *out0,
    uint8_t *out1, uint8_t *out2, uint8_t *out3) {
  libcrux_ml_dsa_hash_functions_portable_squeeze_first_five_blocks(
      self, out0, out1, out2, out3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake128X4)}
*/
static KRML_MUSTINLINE uint8_t_168size_t__x4
libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_ed(
    libcrux_ml_dsa_hash_functions_portable_Shake128X4 *self) {
  return libcrux_ml_dsa_hash_functions_portable_squeeze_next_block(self);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::portable::Shake256)#2}
*/
static KRML_MUSTINLINE libcrux_sha3_portable_KeccakState
libcrux_ml_dsa_hash_functions_portable_init_absorb_final_5c(
    Eurydice_slice input) {
  return libcrux_ml_dsa_hash_functions_portable_init_absorb_final_shake256(
      input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::portable::Shake256)#2}
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_5c(
    libcrux_sha3_portable_KeccakState *self, uint8_t ret[136U]) {
  libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_shake256(self,
                                                                      ret);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::portable::Shake256)#2}
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_5c(
    libcrux_sha3_portable_KeccakState *self, uint8_t ret[136U]) {
  libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_shake256(self, ret);
}

typedef libcrux_sha3_portable_incremental_Shake256Xof
    libcrux_ml_dsa_hash_functions_portable_Shake256Xof;

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::Xof for
libcrux_ml_dsa::hash_functions::portable::Shake256Xof)#4}
*/
static inline void libcrux_ml_dsa_hash_functions_portable_absorb_83(
    libcrux_sha3_portable_incremental_Shake256Xof *self, Eurydice_slice input) {
  libcrux_sha3_portable_incremental_absorb_68(self, input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::Xof for
libcrux_ml_dsa::hash_functions::portable::Shake256Xof)#4}
*/
static inline void libcrux_ml_dsa_hash_functions_portable_absorb_final_83(
    libcrux_sha3_portable_incremental_Shake256Xof *self, Eurydice_slice input) {
  libcrux_sha3_portable_incremental_absorb_final_68(self, input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::Xof for
libcrux_ml_dsa::hash_functions::portable::Shake256Xof)#4}
*/
static inline libcrux_sha3_portable_incremental_Shake256Xof
libcrux_ml_dsa_hash_functions_portable_init_83(void) {
  return libcrux_sha3_portable_incremental_new_68();
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::Xof for
libcrux_ml_dsa::hash_functions::portable::Shake256Xof)#4}
*/
static inline void libcrux_ml_dsa_hash_functions_portable_squeeze_83(
    libcrux_sha3_portable_incremental_Shake256Xof *self, Eurydice_slice out) {
  libcrux_sha3_portable_incremental_squeeze_68(self, out);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake256X4)#3}
*/
static KRML_MUSTINLINE libcrux_ml_dsa_hash_functions_portable_Shake256X4
libcrux_ml_dsa_hash_functions_portable_init_absorb_x4_50(
    Eurydice_slice input0, Eurydice_slice input1, Eurydice_slice input2,
    Eurydice_slice input3) {
  return libcrux_ml_dsa_hash_functions_portable_init_absorb_x4(input0, input1,
                                                               input2, input3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake256X4)#3}
*/
static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_x4_50(
    libcrux_ml_dsa_hash_functions_portable_Shake256X4 *self) {
  return libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_x4(self);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake256X4)#3}
*/
static KRML_MUSTINLINE uint8_t_136size_t__x4
libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4_50(
    libcrux_ml_dsa_hash_functions_portable_Shake256X4 *self) {
  return libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4(self);
}

#define LIBCRUX_ML_DSA_HASH_FUNCTIONS_SHAKE128_BLOCK_SIZE ((size_t)168U)

#define LIBCRUX_ML_DSA_HASH_FUNCTIONS_SHAKE128_FIVE_BLOCKS_SIZE \
  (LIBCRUX_ML_DSA_HASH_FUNCTIONS_SHAKE128_BLOCK_SIZE * (size_t)5U)

#define LIBCRUX_ML_DSA_HASH_FUNCTIONS_SHAKE256_BLOCK_SIZE ((size_t)136U)

#define LIBCRUX_ML_DSA_ML_DSA_65_ONES_IN_VERIFIER_CHALLENGE ((size_t)49U)

#define LIBCRUX_ML_DSA_ML_DSA_65_ETA ((size_t)4U)

#define LIBCRUX_ML_DSA_ML_DSA_65_BETA                              \
  ((int32_t)(LIBCRUX_ML_DSA_ML_DSA_65_ONES_IN_VERIFIER_CHALLENGE * \
             LIBCRUX_ML_DSA_ML_DSA_65_ETA))

#define LIBCRUX_ML_DSA_ML_DSA_65_BITS_PER_COMMITMENT_COEFFICIENT ((size_t)4U)

#define LIBCRUX_ML_DSA_ML_DSA_65_BITS_PER_ERROR_COEFFICIENT ((size_t)4U)

#define LIBCRUX_ML_DSA_ML_DSA_65_BITS_PER_GAMMA1_COEFFICIENT ((size_t)20U)

#define LIBCRUX_ML_DSA_ML_DSA_65_COLUMNS_IN_A ((size_t)5U)

#define LIBCRUX_ML_DSA_ML_DSA_65_COMMITMENT_HASH_SIZE ((size_t)48U)

#define LIBCRUX_ML_DSA_ML_DSA_65_COMMITMENT_RING_ELEMENT_SIZE \
  (LIBCRUX_ML_DSA_ML_DSA_65_BITS_PER_COMMITMENT_COEFFICIENT * \
   LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_DSA_ML_DSA_65_ROWS_IN_A ((size_t)6U)

#define LIBCRUX_ML_DSA_ML_DSA_65_COMMITMENT_VECTOR_SIZE    \
  (LIBCRUX_ML_DSA_ML_DSA_65_COMMITMENT_RING_ELEMENT_SIZE * \
   LIBCRUX_ML_DSA_ML_DSA_65_ROWS_IN_A)

#define LIBCRUX_ML_DSA_ML_DSA_65_ERROR_RING_ELEMENT_SIZE \
  (LIBCRUX_ML_DSA_ML_DSA_65_BITS_PER_ERROR_COEFFICIENT * \
   LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_DSA_ML_DSA_65_GAMMA1_EXPONENT ((size_t)19U)

#define LIBCRUX_ML_DSA_ML_DSA_65_GAMMA1_RING_ELEMENT_SIZE \
  (LIBCRUX_ML_DSA_ML_DSA_65_BITS_PER_GAMMA1_COEFFICIENT * \
   LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_DSA_ML_DSA_65_GAMMA2 \
  ((LIBCRUX_ML_DSA_CONSTANTS_FIELD_MODULUS - (int32_t)1) / (int32_t)32)

#define LIBCRUX_ML_DSA_ML_DSA_65_MAX_ONES_IN_HINT ((size_t)55U)

typedef libcrux_ml_dsa_types_MLDSASigningKey_22
    libcrux_ml_dsa_ml_dsa_65_MLDSA65SigningKey;

typedef libcrux_ml_dsa_types_MLDSAVerificationKey_ea
    libcrux_ml_dsa_ml_dsa_65_MLDSA65VerificationKey;

#define LIBCRUX_ML_DSA_ML_DSA_65_SIGNATURE_SIZE            \
  (LIBCRUX_ML_DSA_ML_DSA_65_COMMITMENT_HASH_SIZE +         \
   LIBCRUX_ML_DSA_ML_DSA_65_COLUMNS_IN_A *                 \
       LIBCRUX_ML_DSA_ML_DSA_65_GAMMA1_RING_ELEMENT_SIZE + \
   LIBCRUX_ML_DSA_ML_DSA_65_MAX_ONES_IN_HINT +             \
   LIBCRUX_ML_DSA_ML_DSA_65_ROWS_IN_A)

#define LIBCRUX_ML_DSA_ML_DSA_65_SIGNING_KEY_SIZE             \
  (LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE +                 \
   LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_SIGNING_SIZE +           \
   LIBCRUX_ML_DSA_CONSTANTS_BYTES_FOR_VERIFICATION_KEY_HASH + \
   (LIBCRUX_ML_DSA_ML_DSA_65_ROWS_IN_A +                      \
    LIBCRUX_ML_DSA_ML_DSA_65_COLUMNS_IN_A) *                  \
       LIBCRUX_ML_DSA_ML_DSA_65_ERROR_RING_ELEMENT_SIZE +     \
   LIBCRUX_ML_DSA_ML_DSA_65_ROWS_IN_A *                       \
       LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE)

#define LIBCRUX_ML_DSA_ML_DSA_65_VERIFICATION_KEY_SIZE                \
  (LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE +                         \
   LIBCRUX_ML_DSA_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *            \
       LIBCRUX_ML_DSA_ML_DSA_65_ROWS_IN_A *                           \
       (LIBCRUX_ML_DSA_CONSTANTS_FIELD_MODULUS_MINUS_ONE_BIT_LENGTH - \
        LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T) /           \
       (size_t)8U)

#define LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS ((int32_t)8380417)

#define LIBCRUX_ML_DSA_SIMD_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R \
  (58728449ULL)

typedef struct uint8_t_x2_s {
  uint8_t fst;
  uint8_t snd;
} uint8_t_x2;

static KRML_MUSTINLINE uint16_t
libcrux_ml_dsa_samplex4_generate_domain_separator(uint8_t_x2 _) {
  uint8_t row = _.fst;
  uint8_t column = _.snd;
  return (uint32_t)(uint16_t)column | (uint32_t)(uint16_t)row << 8U;
}

typedef struct libcrux_ml_dsa_pre_hash_DomainSeparationContext_s {
  Eurydice_slice context;
  Option_30 pre_hash_oid;
} libcrux_ml_dsa_pre_hash_DomainSeparationContext;

#define libcrux_ml_dsa_pre_hash_ContextTooLongError 0

typedef uint8_t libcrux_ml_dsa_pre_hash_DomainSeparationError;

/**
A monomorphic instance of core.result.Result
with types libcrux_ml_dsa_pre_hash_DomainSeparationContext,
libcrux_ml_dsa_pre_hash_DomainSeparationError

*/
typedef struct Result_a8_s {
  Result_a9_tags tag;
  union {
    libcrux_ml_dsa_pre_hash_DomainSeparationContext case_Ok;
    libcrux_ml_dsa_pre_hash_DomainSeparationError case_Err;
  } val;
} Result_a8;

/**
 `context` must be at most 255 bytes long.
*/
/**
This function found in impl
{libcrux_ml_dsa::pre_hash::DomainSeparationContext<'a>#1}
*/
static inline Result_a8 libcrux_ml_dsa_pre_hash_new_45(Eurydice_slice context,
                                                       Option_30 pre_hash_oid) {
  Result_a8 uu____0;
  if (Eurydice_slice_len(context, uint8_t) >
      LIBCRUX_ML_DSA_CONSTANTS_CONTEXT_MAX_LEN) {
    uu____0 = (CLITERAL(Result_a8){
        .tag = Err,
        .val = {.case_Err = libcrux_ml_dsa_pre_hash_ContextTooLongError}});
  } else {
    uu____0 = (CLITERAL(Result_a8){
        .tag = Ok,
        .val = {
            .case_Ok = {.context = context, .pre_hash_oid = pre_hash_oid}}});
  }
  return uu____0;
}

/**
 Returns the pre-hash OID, if any.
*/
/**
This function found in impl
{libcrux_ml_dsa::pre_hash::DomainSeparationContext<'a>#1}
*/
static inline Option_30 *libcrux_ml_dsa_pre_hash_pre_hash_oid_45(
    libcrux_ml_dsa_pre_hash_DomainSeparationContext *self) {
  return &self->pre_hash_oid;
}

/**
 Returns the context, guaranteed to be at most 255 bytes long.
*/
/**
This function found in impl
{libcrux_ml_dsa::pre_hash::DomainSeparationContext<'a>#1}
*/
static inline Eurydice_slice libcrux_ml_dsa_pre_hash_context_45(
    libcrux_ml_dsa_pre_hash_DomainSeparationContext *self) {
  return self->context;
}

static KRML_MUSTINLINE void libcrux_ml_dsa_sample_update_seed(
    uint8_t seed[66U], uint16_t *domain_separator, uint8_t ret[66U]) {
  seed[64U] = (uint8_t)domain_separator[0U];
  seed[65U] = (uint8_t)((uint32_t)domain_separator[0U] >> 8U);
  domain_separator[0U] = (uint32_t)domain_separator[0U] + 1U;
  memcpy(ret, seed, (size_t)66U * sizeof(uint8_t));
}

static KRML_MUSTINLINE bool libcrux_ml_dsa_sample_inside_out_shuffle(
    Eurydice_slice randomness, size_t *out_index, uint64_t *signs,
    int32_t *result) {
  bool done = false;
  for (size_t i = (size_t)0U; i < Eurydice_slice_len(randomness, uint8_t);
       i++) {
    size_t _cloop_j = i;
    uint8_t *byte =
        &Eurydice_slice_index(randomness, _cloop_j, uint8_t, uint8_t *);
    if (!done) {
      size_t sample_at = (size_t)byte[0U];
      if (sample_at <= out_index[0U]) {
        result[out_index[0U]] = result[sample_at];
        out_index[0U] = out_index[0U] + (size_t)1U;
        result[sample_at] =
            (int32_t)1 - (int32_t)2 * (int32_t)(signs[0U] & 1ULL);
        signs[0U] = signs[0U] >> 1U;
        size_t uu____0 = out_index[0U];
        done = uu____0 == Eurydice_slice_len(Eurydice_array_to_slice(
                                                 (size_t)256U, result, int32_t),
                                             int32_t);
      } else {
        size_t uu____1 = out_index[0U];
        done = uu____1 == Eurydice_slice_len(Eurydice_array_to_slice(
                                                 (size_t)256U, result, int32_t),
                                             int32_t);
      }
    }
  }
  return done;
}

static const uint8_t libcrux_ml_dsa_pre_hash_SHAKE128_OID[11U] = {
    6U, 9U, 96U, 134U, 72U, 1U, 101U, 3U, 4U, 2U, 11U};

/**
This function found in impl {(libcrux_ml_dsa::pre_hash::PreHash<256: usize> for
libcrux_ml_dsa::pre_hash::SHAKE128_PH)}
*/
static inline void libcrux_ml_dsa_pre_hash_oid_bd(uint8_t ret[11U]) {
  memcpy(ret, libcrux_ml_dsa_pre_hash_SHAKE128_OID,
         (size_t)11U * sizeof(uint8_t));
}

typedef struct libcrux_ml_dsa_pre_hash_SHAKE128_PH_s {
} libcrux_ml_dsa_pre_hash_SHAKE128_PH;

typedef struct libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_s {
  int32_t coefficients[8U];
} libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit;

static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_vector_type_ZERO(void) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit lit;
  lit.coefficients[0U] = (int32_t)0;
  lit.coefficients[1U] = (int32_t)0;
  lit.coefficients[2U] = (int32_t)0;
  lit.coefficients[3U] = (int32_t)0;
  lit.coefficients[4U] = (int32_t)0;
  lit.coefficients[5U] = (int32_t)0;
  lit.coefficients[6U] = (int32_t)0;
  lit.coefficients[7U] = (int32_t)0;
  return lit;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_ZERO_36(void) {
  return libcrux_ml_dsa_simd_portable_vector_type_ZERO();
}

static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_vector_type_from_coefficient_array(
    Eurydice_slice array) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit lit;
  int32_t ret[8U];
  Result_6c dst;
  Eurydice_slice_to_array2(
      &dst, Eurydice_slice_subslice2(array, (size_t)0U, (size_t)8U, int32_t),
      Eurydice_slice, int32_t[8U]);
  unwrap_26_55(dst, ret);
  memcpy(lit.coefficients, ret, (size_t)8U * sizeof(int32_t));
  return lit;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_from_coefficient_array_36(Eurydice_slice array) {
  return libcrux_ml_dsa_simd_portable_vector_type_from_coefficient_array(array);
}

static inline void
libcrux_ml_dsa_simd_portable_vector_type_to_coefficient_array(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *x,
    int32_t ret[8U]) {
  memcpy(ret, x->coefficients, (size_t)8U * sizeof(int32_t));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline void libcrux_ml_dsa_simd_portable_to_coefficient_array_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *self,
    int32_t ret[8U]) {
  libcrux_ml_dsa_simd_portable_vector_type_to_coefficient_array(self, ret);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_arithmetic_add(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *lhs,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *rhs) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit sum =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice((size_t)8U, sum.coefficients, int32_t),
               int32_t);
       i++) {
    size_t i0 = i;
    sum.coefficients[i0] = lhs->coefficients[i0] + rhs->coefficients[i0];
  }
  return sum;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_add_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *lhs,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *rhs) {
  return libcrux_ml_dsa_simd_portable_arithmetic_add(lhs, rhs);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_arithmetic_subtract(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *lhs,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *rhs) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit difference =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, difference.coefficients, int32_t),
                              int32_t);
       i++) {
    size_t i0 = i;
    difference.coefficients[i0] = lhs->coefficients[i0] - rhs->coefficients[i0];
  }
  return difference;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_subtract_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *lhs,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *rhs) {
  return libcrux_ml_dsa_simd_portable_arithmetic_subtract(lhs, rhs);
}

static KRML_MUSTINLINE bool
libcrux_ml_dsa_simd_portable_arithmetic_infinity_norm_exceeds(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t bound) {
  bool exceeds = false;
  core_ops_range_Range_08 lit;
  lit.start = (size_t)0U;
  lit.end = Eurydice_slice_len(
      Eurydice_array_to_slice((size_t)8U, simd_unit.coefficients, int32_t),
      int32_t);
  core_ops_range_Range_08 iter =
      core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
          lit, core_ops_range_Range_08, core_ops_range_Range_08);
  while (true) {
    Option_08 uu____0 =
        core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A__TraitClause_0___6__next(
            &iter, size_t, Option_08);
    if (uu____0.tag == None) {
      return exceeds;
    } else {
      size_t _cloop_k = uu____0.f0;
      int32_t coefficient = simd_unit.coefficients[_cloop_k];
      int32_t sign = coefficient >> 31U;
      int32_t normalized = coefficient - (sign & (int32_t)2 * coefficient);
      bool uu____1;
      if (exceeds) {
        uu____1 = true;
      } else {
        uu____1 = normalized >= bound;
      }
      exceeds = uu____1;
    }
  }
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline bool libcrux_ml_dsa_simd_portable_infinity_norm_exceeds_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t bound) {
  return libcrux_ml_dsa_simd_portable_arithmetic_infinity_norm_exceeds(
      simd_unit, bound);
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT (32U)

static KRML_MUSTINLINE uint64_t
libcrux_ml_dsa_simd_portable_arithmetic_get_n_least_significant_bits(
    uint8_t n, uint64_t value) {
  return value & ((1ULL << (uint32_t)n) - 1ULL);
}

static KRML_MUSTINLINE int32_t
libcrux_ml_dsa_simd_portable_arithmetic_montgomery_reduce_element(
    int64_t value) {
  uint64_t t =
      libcrux_ml_dsa_simd_portable_arithmetic_get_n_least_significant_bits(
          LIBCRUX_ML_DSA_SIMD_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT,
          (uint64_t)value) *
      LIBCRUX_ML_DSA_SIMD_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R;
  int32_t k = (int32_t)
      libcrux_ml_dsa_simd_portable_arithmetic_get_n_least_significant_bits(
          LIBCRUX_ML_DSA_SIMD_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT, t);
  int64_t k_times_modulus =
      (int64_t)k * (int64_t)LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS;
  int32_t c =
      (int32_t)(k_times_modulus >>
                (uint32_t)
                    LIBCRUX_ML_DSA_SIMD_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT);
  int32_t value_high =
      (int32_t)(value >>
                (uint32_t)
                    LIBCRUX_ML_DSA_SIMD_PORTABLE_ARITHMETIC_MONTGOMERY_SHIFT);
  return value_high - c;
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *lhs,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *rhs) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit product =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, product.coefficients, int32_t),
                              int32_t);
       i++) {
    size_t i0 = i;
    product.coefficients[i0] =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_reduce_element(
            (int64_t)lhs->coefficients[i0] * (int64_t)rhs->coefficients[i0]);
  }
  return product;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_montgomery_multiply_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit lhs,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit rhs) {
  return libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply(&lhs,
                                                                     &rhs);
}

static KRML_MUSTINLINE int32_t
libcrux_ml_dsa_simd_portable_arithmetic_reduce_element(int32_t fe) {
  int32_t quotient = (fe + ((int32_t)1 << 22U)) >> 23U;
  return fe - quotient * LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS;
}

typedef struct int32_t_x2_s {
  int32_t fst;
  int32_t snd;
} int32_t_x2;

static KRML_MUSTINLINE int32_t_x2
libcrux_ml_dsa_simd_portable_arithmetic_power2round_element(int32_t t) {
  int32_t t2 = t + (t >> 31U & LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  int32_t t1 =
      (t2 - (int32_t)1 +
       ((int32_t)1
        << (uint32_t)(LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T -
                      (size_t)1U))) >>
      (uint32_t)LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T;
  int32_t t0 =
      t2 - (t1 << (uint32_t)LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T);
  return (CLITERAL(int32_t_x2){.fst = t0, .snd = t1});
}

typedef struct libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2_s {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit fst;
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit snd;
} libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2;

static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2
libcrux_ml_dsa_simd_portable_arithmetic_power2round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t0_simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t1_simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t);
       i++) {
    size_t i0 = i;
    int32_t t = simd_unit.coefficients[i0];
    int32_t_x2 uu____0 =
        libcrux_ml_dsa_simd_portable_arithmetic_power2round_element(t);
    int32_t t0 = uu____0.fst;
    int32_t t1 = uu____0.snd;
    t0_simd_unit.coefficients[i0] = t0;
    t1_simd_unit.coefficients[i0] = t1;
  }
  return (
      CLITERAL(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2){
          .fst = t0_simd_unit, .snd = t1_simd_unit});
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2
libcrux_ml_dsa_simd_portable_power2round_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit) {
  return libcrux_ml_dsa_simd_portable_arithmetic_power2round(simd_unit);
}

static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_portable_sample_rejection_sample_less_than_field_modulus(
    Eurydice_slice randomness, Eurydice_slice out) {
  size_t sampled = (size_t)0U;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(randomness, uint8_t) / (size_t)3U; i++) {
    size_t _cloop_i = i;
    Eurydice_slice bytes =
        Eurydice_slice_subslice2(randomness, _cloop_i * (size_t)3U,
                                 _cloop_i * (size_t)3U + (size_t)3U, uint8_t);
    int32_t b0 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *);
    int32_t b1 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *);
    int32_t b2 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *);
    int32_t coefficient = ((b2 << 16U | b1 << 8U) | b0) & (int32_t)8388607;
    if (coefficient < LIBCRUX_ML_DSA_CONSTANTS_FIELD_MODULUS) {
      Eurydice_slice_index(out, sampled, int32_t, int32_t *) = coefficient;
      sampled++;
    }
  }
  return sampled;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline size_t
libcrux_ml_dsa_simd_portable_rejection_sample_less_than_field_modulus_36(
    Eurydice_slice randomness, Eurydice_slice out) {
  return libcrux_ml_dsa_simd_portable_sample_rejection_sample_less_than_field_modulus(
      randomness, out);
}

static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_portable_sample_rejection_sample_less_than_eta_equals_2(
    Eurydice_slice randomness, Eurydice_slice out) {
  size_t sampled = (size_t)0U;
  for (size_t i = (size_t)0U; i < Eurydice_slice_len(randomness, uint8_t);
       i++) {
    size_t _cloop_j = i;
    uint8_t *byte =
        &Eurydice_slice_index(randomness, _cloop_j, uint8_t, uint8_t *);
    uint8_t try_0 = Eurydice_bitand_pv_u8(byte, 15U);
    uint8_t try_1 = Eurydice_shr_pv_u8(byte, (int32_t)4);
    if (try_0 < 15U) {
      int32_t try_00 = (int32_t)try_0;
      int32_t try_0_mod_5 = try_00 - (try_00 * (int32_t)26 >> 7U) * (int32_t)5;
      Eurydice_slice_index(out, sampled, int32_t, int32_t *) =
          (int32_t)2 - try_0_mod_5;
      sampled++;
    }
    if (try_1 < 15U) {
      int32_t try_10 = (int32_t)try_1;
      int32_t try_1_mod_5 = try_10 - (try_10 * (int32_t)26 >> 7U) * (int32_t)5;
      Eurydice_slice_index(out, sampled, int32_t, int32_t *) =
          (int32_t)2 - try_1_mod_5;
      sampled++;
    }
  }
  return sampled;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline size_t
libcrux_ml_dsa_simd_portable_rejection_sample_less_than_eta_equals_2_36(
    Eurydice_slice randomness, Eurydice_slice out) {
  return libcrux_ml_dsa_simd_portable_sample_rejection_sample_less_than_eta_equals_2(
      randomness, out);
}

static KRML_MUSTINLINE size_t
libcrux_ml_dsa_simd_portable_sample_rejection_sample_less_than_eta_equals_4(
    Eurydice_slice randomness, Eurydice_slice out) {
  size_t sampled = (size_t)0U;
  for (size_t i = (size_t)0U; i < Eurydice_slice_len(randomness, uint8_t);
       i++) {
    size_t _cloop_j = i;
    uint8_t *byte =
        &Eurydice_slice_index(randomness, _cloop_j, uint8_t, uint8_t *);
    uint8_t try_0 = Eurydice_bitand_pv_u8(byte, 15U);
    uint8_t try_1 = Eurydice_shr_pv_u8(byte, (int32_t)4);
    if (try_0 < 9U) {
      Eurydice_slice_index(out, sampled, int32_t, int32_t *) =
          (int32_t)4 - (int32_t)try_0;
      sampled++;
    }
    if (try_1 < 9U) {
      Eurydice_slice_index(out, sampled, int32_t, int32_t *) =
          (int32_t)4 - (int32_t)try_1;
      sampled++;
    }
  }
  return sampled;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline size_t
libcrux_ml_dsa_simd_portable_rejection_sample_less_than_eta_equals_4_36(
    Eurydice_slice randomness, Eurydice_slice out) {
  return libcrux_ml_dsa_simd_portable_sample_rejection_sample_less_than_eta_equals_4(
      randomness, out);
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 \
  ((int32_t)1 << 17U)

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_gamma1_serialize_when_gamma1_is_2_pow_17(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t) /
               (size_t)4U;
       i++) {
    size_t i0 = i;
    Eurydice_slice coefficients =
        Eurydice_array_to_subslice2(simd_unit.coefficients, i0 * (size_t)4U,
                                    i0 * (size_t)4U + (size_t)4U, int32_t);
    int32_t coefficient0 =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        Eurydice_slice_index(coefficients, (size_t)0U, int32_t, int32_t *);
    int32_t coefficient1 =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        Eurydice_slice_index(coefficients, (size_t)1U, int32_t, int32_t *);
    int32_t coefficient2 =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        Eurydice_slice_index(coefficients, (size_t)2U, int32_t, int32_t *);
    int32_t coefficient3 =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        Eurydice_slice_index(coefficients, (size_t)3U, int32_t, int32_t *);
    Eurydice_slice_index(serialized, (size_t)9U * i0, uint8_t, uint8_t *) =
        (uint8_t)coefficient0;
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)1U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient0 >> 8U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)2U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient0 >> 16U);
    size_t uu____0 = (size_t)9U * i0 + (size_t)2U;
    Eurydice_slice_index(serialized, uu____0, uint8_t, uint8_t *) =
        (uint32_t)Eurydice_slice_index(serialized, uu____0, uint8_t,
                                       uint8_t *) |
        (uint32_t)(uint8_t)(coefficient1 << 2U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)3U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient1 >> 6U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)4U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient1 >> 14U);
    size_t uu____1 = (size_t)9U * i0 + (size_t)4U;
    Eurydice_slice_index(serialized, uu____1, uint8_t, uint8_t *) =
        (uint32_t)Eurydice_slice_index(serialized, uu____1, uint8_t,
                                       uint8_t *) |
        (uint32_t)(uint8_t)(coefficient2 << 4U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)5U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient2 >> 4U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)6U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient2 >> 12U);
    size_t uu____2 = (size_t)9U * i0 + (size_t)6U;
    Eurydice_slice_index(serialized, uu____2, uint8_t, uint8_t *) =
        (uint32_t)Eurydice_slice_index(serialized, uu____2, uint8_t,
                                       uint8_t *) |
        (uint32_t)(uint8_t)(coefficient3 << 6U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)7U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient3 >> 2U);
    Eurydice_slice_index(serialized, (size_t)9U * i0 + (size_t)8U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient3 >> 10U);
  }
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 \
  ((int32_t)1 << 19U)

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_gamma1_serialize_when_gamma1_is_2_pow_19(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t) /
               (size_t)2U;
       i++) {
    size_t i0 = i;
    Eurydice_slice coefficients =
        Eurydice_array_to_subslice2(simd_unit.coefficients, i0 * (size_t)2U,
                                    i0 * (size_t)2U + (size_t)2U, int32_t);
    int32_t coefficient0 =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 -
        Eurydice_slice_index(coefficients, (size_t)0U, int32_t, int32_t *);
    int32_t coefficient1 =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_SERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 -
        Eurydice_slice_index(coefficients, (size_t)1U, int32_t, int32_t *);
    Eurydice_slice_index(serialized, (size_t)5U * i0, uint8_t, uint8_t *) =
        (uint8_t)coefficient0;
    Eurydice_slice_index(serialized, (size_t)5U * i0 + (size_t)1U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient0 >> 8U);
    Eurydice_slice_index(serialized, (size_t)5U * i0 + (size_t)2U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient0 >> 16U);
    size_t uu____0 = (size_t)5U * i0 + (size_t)2U;
    Eurydice_slice_index(serialized, uu____0, uint8_t, uint8_t *) =
        (uint32_t)Eurydice_slice_index(serialized, uu____0, uint8_t,
                                       uint8_t *) |
        (uint32_t)(uint8_t)(coefficient1 << 4U);
    Eurydice_slice_index(serialized, (size_t)5U * i0 + (size_t)3U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient1 >> 4U);
    Eurydice_slice_index(serialized, (size_t)5U * i0 + (size_t)4U, uint8_t,
                         uint8_t *) = (uint8_t)(coefficient1 >> 12U);
  }
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 \
  ((int32_t)1 << 17U)

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_BITMASK \
  ((LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1                     \
    << 1U) -                                                                                                    \
   (int32_t)1)

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_gamma1_deserialize_when_gamma1_is_2_pow_17(
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(serialized, uint8_t) / (size_t)9U; i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)9U, i0 * (size_t)9U + (size_t)9U, uint8_t);
    int32_t coefficient0 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *);
    coefficient0 =
        coefficient0 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *)
            << 8U;
    coefficient0 =
        coefficient0 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *)
            << 16U;
    coefficient0 =
        coefficient0 &
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_BITMASK;
    int32_t coefficient1 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *) >>
        2U;
    coefficient1 =
        coefficient1 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t, uint8_t *)
            << 6U;
    coefficient1 =
        coefficient1 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t, uint8_t *)
            << 14U;
    coefficient1 =
        coefficient1 &
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_BITMASK;
    int32_t coefficient2 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t, uint8_t *) >>
        4U;
    coefficient2 =
        coefficient2 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)5U, uint8_t, uint8_t *)
            << 4U;
    coefficient2 =
        coefficient2 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)6U, uint8_t, uint8_t *)
            << 12U;
    coefficient2 =
        coefficient2 &
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_BITMASK;
    int32_t coefficient3 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)6U, uint8_t, uint8_t *) >>
        6U;
    coefficient3 =
        coefficient3 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)7U, uint8_t, uint8_t *)
            << 2U;
    coefficient3 =
        coefficient3 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)8U, uint8_t, uint8_t *)
            << 10U;
    coefficient3 =
        coefficient3 &
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1_TIMES_2_BITMASK;
    simd_unit.coefficients[(size_t)4U * i0] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        coefficient0;
    simd_unit.coefficients[(size_t)4U * i0 + (size_t)1U] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        coefficient1;
    simd_unit.coefficients[(size_t)4U * i0 + (size_t)2U] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        coefficient2;
    simd_unit.coefficients[(size_t)4U * i0 + (size_t)3U] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_17_GAMMA1 -
        coefficient3;
  }
  return simd_unit;
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 \
  ((int32_t)1 << 19U)

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1_TIMES_2_BITMASK \
  ((LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1                     \
    << 1U) -                                                                                                    \
   (int32_t)1)

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_gamma1_deserialize_when_gamma1_is_2_pow_19(
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(serialized, uint8_t) / (size_t)5U; i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)5U, i0 * (size_t)5U + (size_t)5U, uint8_t);
    int32_t coefficient0 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *);
    coefficient0 =
        coefficient0 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *)
            << 8U;
    coefficient0 =
        coefficient0 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *)
            << 16U;
    coefficient0 =
        coefficient0 &
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1_TIMES_2_BITMASK;
    int32_t coefficient1 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *) >>
        4U;
    coefficient1 =
        coefficient1 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t, uint8_t *)
            << 4U;
    coefficient1 =
        coefficient1 |
        (int32_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t, uint8_t *)
            << 12U;
    simd_unit.coefficients[(size_t)2U * i0] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 -
        coefficient0;
    simd_unit.coefficients[(size_t)2U * i0 + (size_t)1U] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_GAMMA1_DESERIALIZE_WHEN_GAMMA1_IS_2_POW_19_GAMMA1 -
        coefficient1;
  }
  return simd_unit;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_commitment_serialize(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  switch ((uint8_t)Eurydice_slice_len(serialized, uint8_t)) {
    case 4U: {
      for (size_t i = (size_t)0U;
           i <
           Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t) /
               (size_t)2U;
           i++) {
        size_t i0 = i;
        Eurydice_slice coefficients =
            Eurydice_array_to_subslice2(simd_unit.coefficients, i0 * (size_t)2U,
                                        i0 * (size_t)2U + (size_t)2U, int32_t);
        uint8_t coefficient0 = (uint8_t)Eurydice_slice_index(
            coefficients, (size_t)0U, int32_t, int32_t *);
        uint8_t coefficient1 = (uint8_t)Eurydice_slice_index(
            coefficients, (size_t)1U, int32_t, int32_t *);
        Eurydice_slice_index(serialized, i0, uint8_t, uint8_t *) =
            (uint32_t)coefficient1 << 4U | (uint32_t)coefficient0;
      }
      break;
    }
    case 6U: {
      for (size_t i = (size_t)0U;
           i <
           Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t) /
               (size_t)4U;
           i++) {
        size_t i0 = i;
        Eurydice_slice coefficients =
            Eurydice_array_to_subslice2(simd_unit.coefficients, i0 * (size_t)4U,
                                        i0 * (size_t)4U + (size_t)4U, int32_t);
        uint8_t coefficient0 = (uint8_t)Eurydice_slice_index(
            coefficients, (size_t)0U, int32_t, int32_t *);
        uint8_t coefficient1 = (uint8_t)Eurydice_slice_index(
            coefficients, (size_t)1U, int32_t, int32_t *);
        uint8_t coefficient2 = (uint8_t)Eurydice_slice_index(
            coefficients, (size_t)2U, int32_t, int32_t *);
        uint8_t coefficient3 = (uint8_t)Eurydice_slice_index(
            coefficients, (size_t)3U, int32_t, int32_t *);
        Eurydice_slice_index(serialized, (size_t)3U * i0, uint8_t, uint8_t *) =
            (uint32_t)coefficient1 << 6U | (uint32_t)coefficient0;
        Eurydice_slice_index(serialized, (size_t)3U * i0 + (size_t)1U, uint8_t,
                             uint8_t *) =
            (uint32_t)coefficient2 << 4U | (uint32_t)coefficient1 >> 2U;
        Eurydice_slice_index(serialized, (size_t)3U * i0 + (size_t)2U, uint8_t,
                             uint8_t *) =
            (uint32_t)coefficient3 << 2U | (uint32_t)coefficient2 >> 4U;
      }
      break;
    }
    default: {
      KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                        "panic!");
      KRML_HOST_EXIT(255U);
    }
  }
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline void libcrux_ml_dsa_simd_portable_commitment_serialize_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_encoding_commitment_serialize(simd_unit,
                                                             serialized);
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA \
  ((int32_t)2)

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_error_serialize_when_eta_is_2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  uint8_t coefficient0 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[0U]);
  uint8_t coefficient1 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[1U]);
  uint8_t coefficient2 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[2U]);
  uint8_t coefficient3 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[3U]);
  uint8_t coefficient4 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[4U]);
  uint8_t coefficient5 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[5U]);
  uint8_t coefficient6 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[6U]);
  uint8_t coefficient7 =
      (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_2_ETA -
                simd_unit.coefficients[7U]);
  Eurydice_slice_index(serialized, (size_t)0U, uint8_t, uint8_t *) =
      ((uint32_t)coefficient2 << 6U | (uint32_t)coefficient1 << 3U) |
      (uint32_t)coefficient0;
  Eurydice_slice_index(serialized, (size_t)1U, uint8_t, uint8_t *) =
      (((uint32_t)coefficient5 << 7U | (uint32_t)coefficient4 << 4U) |
       (uint32_t)coefficient3 << 1U) |
      (uint32_t)coefficient2 >> 2U;
  Eurydice_slice_index(serialized, (size_t)2U, uint8_t, uint8_t *) =
      ((uint32_t)coefficient7 << 5U | (uint32_t)coefficient6 << 2U) |
      (uint32_t)coefficient5 >> 1U;
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_4_ETA \
  ((int32_t)4)

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_error_serialize_when_eta_is_4(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t) /
               (size_t)2U;
       i++) {
    size_t i0 = i;
    Eurydice_slice coefficients =
        Eurydice_array_to_subslice2(simd_unit.coefficients, i0 * (size_t)2U,
                                    i0 * (size_t)2U + (size_t)2U, int32_t);
    uint8_t coefficient0 =
        (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_4_ETA -
                  Eurydice_slice_index(coefficients, (size_t)0U, int32_t,
                                       int32_t *));
    uint8_t coefficient1 =
        (uint8_t)(LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_SERIALIZE_WHEN_ETA_IS_4_ETA -
                  Eurydice_slice_index(coefficients, (size_t)1U, int32_t,
                                       int32_t *));
    Eurydice_slice_index(serialized, i0, uint8_t, uint8_t *) =
        (uint32_t)coefficient1 << 4U | (uint32_t)coefficient0;
  }
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA \
  ((int32_t)2)

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_error_deserialize_when_eta_is_2(
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  int32_t byte0 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)0U, uint8_t, uint8_t *);
  int32_t byte1 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)1U, uint8_t, uint8_t *);
  int32_t byte2 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)2U, uint8_t, uint8_t *);
  simd_unit.coefficients[0U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      (byte0 & (int32_t)7);
  simd_unit.coefficients[1U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      (byte0 >> 3U & (int32_t)7);
  simd_unit.coefficients[2U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      ((byte0 >> 6U | byte1 << 2U) & (int32_t)7);
  simd_unit.coefficients[3U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      (byte1 >> 1U & (int32_t)7);
  simd_unit.coefficients[4U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      (byte1 >> 4U & (int32_t)7);
  simd_unit.coefficients[5U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      ((byte1 >> 7U | byte2 << 1U) & (int32_t)7);
  simd_unit.coefficients[6U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      (byte2 >> 2U & (int32_t)7);
  simd_unit.coefficients[7U] =
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_2_ETA -
      (byte2 >> 5U & (int32_t)7);
  return simd_unit;
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_4_ETA \
  ((int32_t)4)

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_error_deserialize_when_eta_is_4(
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U; i < Eurydice_slice_len(serialized, uint8_t);
       i++) {
    size_t i0 = i;
    uint8_t *byte = &Eurydice_slice_index(serialized, i0, uint8_t, uint8_t *);
    uint8_t uu____0 = Eurydice_bitand_pv_u8(byte, 15U);
    simd_unit.coefficients[(size_t)2U * i0] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_4_ETA -
        (int32_t)uu____0;
    uint8_t uu____1 = Eurydice_shr_pv_u8(byte, (int32_t)4);
    simd_unit.coefficients[(size_t)2U * i0 + (size_t)1U] =
        LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_ERROR_DESERIALIZE_WHEN_ETA_IS_4_ETA -
        (int32_t)uu____1;
  }
  return simd_unit;
}

static KRML_MUSTINLINE int32_t
libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(int32_t t0) {
  return ((int32_t)1
          << (uint32_t)(LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T -
                        (size_t)1U)) -
         t0;
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_encoding_t0_serialize(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    uint8_t ret[13U]) {
  uint8_t serialized[13U] = {0U};
  int32_t coefficient0 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[0U]);
  int32_t coefficient1 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[1U]);
  int32_t coefficient2 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[2U]);
  int32_t coefficient3 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[3U]);
  int32_t coefficient4 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[4U]);
  int32_t coefficient5 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[5U]);
  int32_t coefficient6 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[6U]);
  int32_t coefficient7 =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(
          simd_unit.coefficients[7U]);
  serialized[0U] = (uint8_t)coefficient0;
  serialized[1U] = (uint8_t)(coefficient0 >> 8U);
  size_t uu____0 = (size_t)1U;
  serialized[uu____0] =
      (uint32_t)serialized[uu____0] | (uint32_t)(uint8_t)(coefficient1 << 5U);
  serialized[2U] = (uint8_t)(coefficient1 >> 3U);
  serialized[3U] = (uint8_t)(coefficient1 >> 11U);
  size_t uu____1 = (size_t)3U;
  serialized[uu____1] =
      (uint32_t)serialized[uu____1] | (uint32_t)(uint8_t)(coefficient2 << 2U);
  serialized[4U] = (uint8_t)(coefficient2 >> 6U);
  size_t uu____2 = (size_t)4U;
  serialized[uu____2] =
      (uint32_t)serialized[uu____2] | (uint32_t)(uint8_t)(coefficient3 << 7U);
  serialized[5U] = (uint8_t)(coefficient3 >> 1U);
  serialized[6U] = (uint8_t)(coefficient3 >> 9U);
  size_t uu____3 = (size_t)6U;
  serialized[uu____3] =
      (uint32_t)serialized[uu____3] | (uint32_t)(uint8_t)(coefficient4 << 4U);
  serialized[7U] = (uint8_t)(coefficient4 >> 4U);
  serialized[8U] = (uint8_t)(coefficient4 >> 12U);
  size_t uu____4 = (size_t)8U;
  serialized[uu____4] =
      (uint32_t)serialized[uu____4] | (uint32_t)(uint8_t)(coefficient5 << 1U);
  serialized[9U] = (uint8_t)(coefficient5 >> 7U);
  size_t uu____5 = (size_t)9U;
  serialized[uu____5] =
      (uint32_t)serialized[uu____5] | (uint32_t)(uint8_t)(coefficient6 << 6U);
  serialized[10U] = (uint8_t)(coefficient6 >> 2U);
  serialized[11U] = (uint8_t)(coefficient6 >> 10U);
  size_t uu____6 = (size_t)11U;
  serialized[uu____6] =
      (uint32_t)serialized[uu____6] | (uint32_t)(uint8_t)(coefficient7 << 3U);
  serialized[12U] = (uint8_t)(coefficient7 >> 5U);
  memcpy(ret, serialized, (size_t)13U * sizeof(uint8_t));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline void libcrux_ml_dsa_simd_portable_t0_serialize_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    uint8_t ret[13U]) {
  libcrux_ml_dsa_simd_portable_encoding_t0_serialize(simd_unit, ret);
}

#define LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK \
  (((int32_t)1 << (uint32_t)(int32_t)                                                     \
        LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_LOWER_PART_OF_T) -                               \
   (int32_t)1)

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_t0_deserialize(
    Eurydice_slice serialized) {
  int32_t byte0 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)0U, uint8_t, uint8_t *);
  int32_t byte1 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)1U, uint8_t, uint8_t *);
  int32_t byte2 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)2U, uint8_t, uint8_t *);
  int32_t byte3 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)3U, uint8_t, uint8_t *);
  int32_t byte4 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)4U, uint8_t, uint8_t *);
  int32_t byte5 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)5U, uint8_t, uint8_t *);
  int32_t byte6 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)6U, uint8_t, uint8_t *);
  int32_t byte7 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)7U, uint8_t, uint8_t *);
  int32_t byte8 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)8U, uint8_t, uint8_t *);
  int32_t byte9 =
      (int32_t)Eurydice_slice_index(serialized, (size_t)9U, uint8_t, uint8_t *);
  int32_t byte10 = (int32_t)Eurydice_slice_index(serialized, (size_t)10U,
                                                 uint8_t, uint8_t *);
  int32_t byte11 = (int32_t)Eurydice_slice_index(serialized, (size_t)11U,
                                                 uint8_t, uint8_t *);
  int32_t byte12 = (int32_t)Eurydice_slice_index(serialized, (size_t)12U,
                                                 uint8_t, uint8_t *);
  int32_t coefficient0 = byte0;
  coefficient0 = coefficient0 | byte1 << 8U;
  coefficient0 =
      coefficient0 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient1 = byte1 >> 5U;
  coefficient1 = coefficient1 | byte2 << 3U;
  coefficient1 = coefficient1 | byte3 << 11U;
  coefficient1 =
      coefficient1 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient2 = byte3 >> 2U;
  coefficient2 = coefficient2 | byte4 << 6U;
  coefficient2 =
      coefficient2 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient3 = byte4 >> 7U;
  coefficient3 = coefficient3 | byte5 << 1U;
  coefficient3 = coefficient3 | byte6 << 9U;
  coefficient3 =
      coefficient3 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient4 = byte6 >> 4U;
  coefficient4 = coefficient4 | byte7 << 4U;
  coefficient4 = coefficient4 | byte8 << 12U;
  coefficient4 =
      coefficient4 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient5 = byte8 >> 1U;
  coefficient5 = coefficient5 | byte9 << 7U;
  coefficient5 =
      coefficient5 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient6 = byte9 >> 6U;
  coefficient6 = coefficient6 | byte10 << 2U;
  coefficient6 = coefficient6 | byte11 << 10U;
  coefficient6 =
      coefficient6 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  int32_t coefficient7 = byte11 >> 3U;
  coefficient7 = coefficient7 | byte12 << 5U;
  coefficient7 =
      coefficient7 &
      LIBCRUX_ML_DSA_SIMD_PORTABLE_ENCODING_T0_DESERIALIZE_BITS_IN_LOWER_PART_OF_T_MASK;
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  simd_unit.coefficients[0U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient0);
  simd_unit.coefficients[1U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient1);
  simd_unit.coefficients[2U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient2);
  simd_unit.coefficients[3U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient3);
  simd_unit.coefficients[4U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient4);
  simd_unit.coefficients[5U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient5);
  simd_unit.coefficients[6U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient6);
  simd_unit.coefficients[7U] =
      libcrux_ml_dsa_simd_portable_encoding_t0_change_t0_interval(coefficient7);
  return simd_unit;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_t0_deserialize_36(Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_portable_encoding_t0_deserialize(serialized);
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_encoding_t1_serialize(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    uint8_t ret[10U]) {
  uint8_t serialized[10U] = {0U};
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t) /
               (size_t)4U;
       i++) {
    size_t i0 = i;
    Eurydice_slice coefficients =
        Eurydice_array_to_subslice2(simd_unit.coefficients, i0 * (size_t)4U,
                                    i0 * (size_t)4U + (size_t)4U, int32_t);
    serialized[(size_t)5U * i0] =
        (uint8_t)(Eurydice_slice_index(coefficients, (size_t)0U, int32_t,
                                       int32_t *) &
                  (int32_t)255);
    serialized[(size_t)5U * i0 + (size_t)1U] =
        (uint32_t)(uint8_t)(Eurydice_slice_index(coefficients, (size_t)1U,
                                                 int32_t, int32_t *) &
                            (int32_t)63)
            << 2U |
        (uint32_t)(uint8_t)(Eurydice_slice_index(coefficients, (size_t)0U,
                                                 int32_t, int32_t *) >>
                                8U &
                            (int32_t)3);
    serialized[(size_t)5U * i0 + (size_t)2U] =
        (uint32_t)(uint8_t)(Eurydice_slice_index(coefficients, (size_t)2U,
                                                 int32_t, int32_t *) &
                            (int32_t)15)
            << 4U |
        (uint32_t)(uint8_t)(Eurydice_slice_index(coefficients, (size_t)1U,
                                                 int32_t, int32_t *) >>
                                6U &
                            (int32_t)15);
    serialized[(size_t)5U * i0 + (size_t)3U] =
        (uint32_t)(uint8_t)(Eurydice_slice_index(coefficients, (size_t)3U,
                                                 int32_t, int32_t *) &
                            (int32_t)3)
            << 6U |
        (uint32_t)(uint8_t)(Eurydice_slice_index(coefficients, (size_t)2U,
                                                 int32_t, int32_t *) >>
                                4U &
                            (int32_t)63);
    serialized[(size_t)5U * i0 + (size_t)4U] =
        (uint8_t)(Eurydice_slice_index(coefficients, (size_t)3U, int32_t,
                                       int32_t *) >>
                      2U &
                  (int32_t)255);
  }
  memcpy(ret, serialized, (size_t)10U * sizeof(uint8_t));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline void libcrux_ml_dsa_simd_portable_t1_serialize_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    uint8_t ret[10U]) {
  libcrux_ml_dsa_simd_portable_encoding_t1_serialize(simd_unit, ret);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_t1_deserialize(
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  int32_t mask = ((int32_t)1 << (uint32_t)
                      LIBCRUX_ML_DSA_CONSTANTS_BITS_IN_UPPER_PART_OF_T) -
                 (int32_t)1;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(serialized, uint8_t) / (size_t)5U; i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * (size_t)5U, i0 * (size_t)5U + (size_t)5U, uint8_t);
    int32_t byte0 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)0U, uint8_t, uint8_t *);
    int32_t byte1 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)1U, uint8_t, uint8_t *);
    int32_t byte2 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)2U, uint8_t, uint8_t *);
    int32_t byte3 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)3U, uint8_t, uint8_t *);
    int32_t byte4 =
        (int32_t)Eurydice_slice_index(bytes, (size_t)4U, uint8_t, uint8_t *);
    simd_unit.coefficients[(size_t)4U * i0] = (byte0 | byte1 << 8U) & mask;
    simd_unit.coefficients[(size_t)4U * i0 + (size_t)1U] =
        (byte1 >> 2U | byte2 << 6U) & mask;
    simd_unit.coefficients[(size_t)4U * i0 + (size_t)2U] =
        (byte2 >> 4U | byte3 << 4U) & mask;
    simd_unit.coefficients[(size_t)4U * i0 + (size_t)3U] =
        (byte3 >> 6U | byte4 << 2U) & mask;
  }
  return simd_unit;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_t1_deserialize_36(Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_portable_encoding_t1_deserialize(serialized);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t c) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t);
       i++) {
    size_t i0 = i;
    simd_unit.coefficients[i0] =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_reduce_element(
            (int64_t)simd_unit.coefficients[i0] * (int64_t)c);
  }
  return simd_unit;
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 16
- ZETA= 25847
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_99(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)16U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)16U], (int32_t)25847);
    re[j + (size_t)16U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_7(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_99(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 8
- ZETA= -2608894
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_990(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)8U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)8U], (int32_t)-2608894);
    re[j + (size_t)8U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 8
- ZETA= -518909
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)8U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)8U], (int32_t)-518909);
    re[j + (size_t)8U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_6(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_990(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 4
- ZETA= 237124
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_991(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)4U], (int32_t)237124);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 4
- ZETA= -777960
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a8(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)4U], (int32_t)-777960);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 4
- ZETA= -876248
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)4U], (int32_t)-876248);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 4
- ZETA= 466468
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_d9(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)4U], (int32_t)466468);
    re[j + (size_t)4U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_5(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_991(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a8(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a0(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_d9(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 2
- ZETA= 1826347
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_992(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)1826347);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 4
- STEP_BY= 2
- ZETA= 2353451
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_6b(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)4U; i < (size_t)4U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)2353451);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 2
- ZETA= -359251
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)-359251);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 12
- STEP_BY= 2
- ZETA= -2091905
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_95(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)12U; i < (size_t)12U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)-2091905);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 2
- ZETA= 3119733
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)3119733);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 20
- STEP_BY= 2
- ZETA= -2884855
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_de(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)20U; i < (size_t)20U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)-2884855);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 2
- ZETA= 3111497
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_d90(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)3111497);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 28
- STEP_BY= 2
- ZETA= 2680103
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3b(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)28U; i < (size_t)28U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)2U], (int32_t)2680103);
    re[j + (size_t)2U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_4(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_992(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_6b(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a80(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_95(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a1(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_de(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_d90(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3b(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 1
- ZETA= 2725464
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_993(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)2725464);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 2
- STEP_BY= 1
- ZETA= 1024112
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_1c(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)2U; i < (size_t)2U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)1024112);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 4
- STEP_BY= 1
- ZETA= -1079900
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_6b0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)4U; i < (size_t)4U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-1079900);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 6
- STEP_BY= 1
- ZETA= 3585928
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_44(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)6U; i < (size_t)6U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)3585928);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 1
- ZETA= -549488
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a81(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-549488);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 10
- STEP_BY= 1
- ZETA= -1119584
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_1f(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)10U; i < (size_t)10U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-1119584);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 12
- STEP_BY= 1
- ZETA= 2619752
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_950(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)12U; i < (size_t)12U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)2619752);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 14
- STEP_BY= 1
- ZETA= -2108549
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3b0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)14U; i < (size_t)14U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-2108549);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 1
- ZETA= -2118186
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-2118186);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 18
- STEP_BY= 1
- ZETA= -3859737
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_e4(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)18U; i < (size_t)18U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-3859737);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 20
- STEP_BY= 1
- ZETA= -1399561
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_de0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)20U; i < (size_t)20U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-1399561);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 22
- STEP_BY= 1
- ZETA= -3277672
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_05(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)22U; i < (size_t)22U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-3277672);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 1
- ZETA= 1757237
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_d91(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)1757237);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 26
- STEP_BY= 1
- ZETA= -19422
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3a(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)26U; i < (size_t)26U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)-19422);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 28
- STEP_BY= 1
- ZETA= 4010497
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3b1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)28U; i < (size_t)28U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)4010497);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.ntt.outer_3_plus
with const generics
- OFFSET= 30
- STEP_BY= 1
- ZETA= 280005
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)30U; i < (size_t)30U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[j + (size_t)1U], (int32_t)280005);
    re[j + (size_t)1U] =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j], &t);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j], &t);
    re[j] = uu____1;
  }
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_3(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_993(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_1c(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_6b0(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_44(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a81(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_1f(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_950(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3b0(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_7a2(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_e4(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_de0(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_05(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_d91(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3a(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_3b1(re);
  libcrux_ml_dsa_simd_portable_ntt_outer_3_plus_a0(re);
}

static KRML_MUSTINLINE int32_t
libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
    int32_t fe, int32_t fer) {
  return libcrux_ml_dsa_simd_portable_arithmetic_montgomery_reduce_element(
      (int64_t)fe * (int64_t)fer);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_ntt_simd_unit_ntt_at_layer_2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t zeta) {
  int32_t t =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[4U], zeta);
  simd_unit.coefficients[4U] = simd_unit.coefficients[0U] - t;
  simd_unit.coefficients[0U] = simd_unit.coefficients[0U] + t;
  int32_t t0 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[5U], zeta);
  simd_unit.coefficients[5U] = simd_unit.coefficients[1U] - t0;
  simd_unit.coefficients[1U] = simd_unit.coefficients[1U] + t0;
  int32_t t1 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[6U], zeta);
  simd_unit.coefficients[6U] = simd_unit.coefficients[2U] - t1;
  simd_unit.coefficients[2U] = simd_unit.coefficients[2U] + t1;
  int32_t t2 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[7U], zeta);
  simd_unit.coefficients[7U] = simd_unit.coefficients[3U] - t2;
  simd_unit.coefficients[3U] = simd_unit.coefficients[3U] + t2;
  return simd_unit;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re, size_t index,
    int32_t zeta) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
      libcrux_ml_dsa_simd_portable_ntt_simd_unit_ntt_at_layer_2(re[index],
                                                                zeta);
  re[index] = uu____0;
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)0U,
                                                        (int32_t)2706023);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)1U,
                                                        (int32_t)95776);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)2U,
                                                        (int32_t)3077325);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)3U,
                                                        (int32_t)3530437);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)4U,
                                                        (int32_t)-1661693);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)5U,
                                                        (int32_t)-3592148);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)6U,
                                                        (int32_t)-2537516);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)7U,
                                                        (int32_t)3915439);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)8U,
                                                        (int32_t)-3861115);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)9U,
                                                        (int32_t)-3043716);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)10U,
                                                        (int32_t)3574422);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)11U,
                                                        (int32_t)-2867647);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)12U,
                                                        (int32_t)3539968);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)13U,
                                                        (int32_t)-300467);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)14U,
                                                        (int32_t)2348700);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)15U,
                                                        (int32_t)-539299);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)16U,
                                                        (int32_t)-1699267);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)17U,
                                                        (int32_t)-1643818);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)18U,
                                                        (int32_t)3505694);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)19U,
                                                        (int32_t)-3821735);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)20U,
                                                        (int32_t)3507263);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)21U,
                                                        (int32_t)-2140649);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)22U,
                                                        (int32_t)-1600420);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)23U,
                                                        (int32_t)3699596);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)24U,
                                                        (int32_t)811944);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)25U,
                                                        (int32_t)531354);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)26U,
                                                        (int32_t)954230);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)27U,
                                                        (int32_t)3881043);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)28U,
                                                        (int32_t)3900724);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)29U,
                                                        (int32_t)-2556880);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)30U,
                                                        (int32_t)2071892);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2_round(re, (size_t)31U,
                                                        (int32_t)-2797779);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_ntt_simd_unit_ntt_at_layer_1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t zeta1, int32_t zeta2) {
  int32_t t =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[2U], zeta1);
  simd_unit.coefficients[2U] = simd_unit.coefficients[0U] - t;
  simd_unit.coefficients[0U] = simd_unit.coefficients[0U] + t;
  int32_t t0 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[3U], zeta1);
  simd_unit.coefficients[3U] = simd_unit.coefficients[1U] - t0;
  simd_unit.coefficients[1U] = simd_unit.coefficients[1U] + t0;
  int32_t t1 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[6U], zeta2);
  simd_unit.coefficients[6U] = simd_unit.coefficients[4U] - t1;
  simd_unit.coefficients[4U] = simd_unit.coefficients[4U] + t1;
  int32_t t2 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[7U], zeta2);
  simd_unit.coefficients[7U] = simd_unit.coefficients[5U] - t2;
  simd_unit.coefficients[5U] = simd_unit.coefficients[5U] + t2;
  return simd_unit;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re, size_t index,
    int32_t zeta_0, int32_t zeta_1) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
      libcrux_ml_dsa_simd_portable_ntt_simd_unit_ntt_at_layer_1(re[index],
                                                                zeta_0, zeta_1);
  re[index] = uu____0;
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)0U, (int32_t)-3930395, (int32_t)-1528703);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)1U, (int32_t)-3677745, (int32_t)-3041255);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)2U, (int32_t)-1452451, (int32_t)3475950);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)3U, (int32_t)2176455, (int32_t)-1585221);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)4U, (int32_t)-1257611, (int32_t)1939314);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)5U, (int32_t)-4083598, (int32_t)-1000202);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)6U, (int32_t)-3190144, (int32_t)-3157330);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)7U, (int32_t)-3632928, (int32_t)126922);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)8U, (int32_t)3412210, (int32_t)-983419);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)9U, (int32_t)2147896, (int32_t)2715295);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)10U, (int32_t)-2967645, (int32_t)-3693493);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)11U, (int32_t)-411027, (int32_t)-2477047);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)12U, (int32_t)-671102, (int32_t)-1228525);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)13U, (int32_t)-22981, (int32_t)-1308169);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)14U, (int32_t)-381987, (int32_t)1349076);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)15U, (int32_t)1852771, (int32_t)-1430430);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)16U, (int32_t)-3343383, (int32_t)264944);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)17U, (int32_t)508951, (int32_t)3097992);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)18U, (int32_t)44288, (int32_t)-1100098);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)19U, (int32_t)904516, (int32_t)3958618);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)20U, (int32_t)-3724342, (int32_t)-8578);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)21U, (int32_t)1653064, (int32_t)-3249728);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)22U, (int32_t)2389356, (int32_t)-210977);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)23U, (int32_t)759969, (int32_t)-1316856);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)24U, (int32_t)189548, (int32_t)-3553272);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)25U, (int32_t)3159746, (int32_t)-1851402);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)26U, (int32_t)-2409325, (int32_t)-177440);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)27U, (int32_t)1315589, (int32_t)1341330);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)28U, (int32_t)1285669, (int32_t)-1584928);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)29U, (int32_t)-812732, (int32_t)-1439742);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)30U, (int32_t)-3019102, (int32_t)-3881060);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1_round(
      re, (size_t)31U, (int32_t)-3628969, (int32_t)3839961);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_ntt_simd_unit_ntt_at_layer_0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t zeta0, int32_t zeta1, int32_t zeta2, int32_t zeta3) {
  int32_t t =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[1U], zeta0);
  simd_unit.coefficients[1U] = simd_unit.coefficients[0U] - t;
  simd_unit.coefficients[0U] = simd_unit.coefficients[0U] + t;
  int32_t t0 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[3U], zeta1);
  simd_unit.coefficients[3U] = simd_unit.coefficients[2U] - t0;
  simd_unit.coefficients[2U] = simd_unit.coefficients[2U] + t0;
  int32_t t1 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[5U], zeta2);
  simd_unit.coefficients[5U] = simd_unit.coefficients[4U] - t1;
  simd_unit.coefficients[4U] = simd_unit.coefficients[4U] + t1;
  int32_t t2 =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          simd_unit.coefficients[7U], zeta3);
  simd_unit.coefficients[7U] = simd_unit.coefficients[6U] - t2;
  simd_unit.coefficients[6U] = simd_unit.coefficients[6U] + t2;
  return simd_unit;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re, size_t index,
    int32_t zeta_0, int32_t zeta_1, int32_t zeta_2, int32_t zeta_3) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
      libcrux_ml_dsa_simd_portable_ntt_simd_unit_ntt_at_layer_0(
          re[index], zeta_0, zeta_1, zeta_2, zeta_3);
  re[index] = uu____0;
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)0U, (int32_t)2091667, (int32_t)3407706, (int32_t)2316500,
      (int32_t)3817976);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)1U, (int32_t)-3342478, (int32_t)2244091, (int32_t)-2446433,
      (int32_t)-3562462);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)2U, (int32_t)266997, (int32_t)2434439, (int32_t)-1235728,
      (int32_t)3513181);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)3U, (int32_t)-3520352, (int32_t)-3759364, (int32_t)-1197226,
      (int32_t)-3193378);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)4U, (int32_t)900702, (int32_t)1859098, (int32_t)909542,
      (int32_t)819034);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)5U, (int32_t)495491, (int32_t)-1613174, (int32_t)-43260,
      (int32_t)-522500);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)6U, (int32_t)-655327, (int32_t)-3122442, (int32_t)2031748,
      (int32_t)3207046);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)7U, (int32_t)-3556995, (int32_t)-525098, (int32_t)-768622,
      (int32_t)-3595838);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)8U, (int32_t)342297, (int32_t)286988, (int32_t)-2437823,
      (int32_t)4108315);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)9U, (int32_t)3437287, (int32_t)-3342277, (int32_t)1735879,
      (int32_t)203044);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)10U, (int32_t)2842341, (int32_t)2691481, (int32_t)-2590150,
      (int32_t)1265009);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)11U, (int32_t)4055324, (int32_t)1247620, (int32_t)2486353,
      (int32_t)1595974);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)12U, (int32_t)-3767016, (int32_t)1250494, (int32_t)2635921,
      (int32_t)-3548272);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)13U, (int32_t)-2994039, (int32_t)1869119, (int32_t)1903435,
      (int32_t)-1050970);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)14U, (int32_t)-1333058, (int32_t)1237275, (int32_t)-3318210,
      (int32_t)-1430225);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)15U, (int32_t)-451100, (int32_t)1312455, (int32_t)3306115,
      (int32_t)-1962642);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)16U, (int32_t)-1279661, (int32_t)1917081, (int32_t)-2546312,
      (int32_t)-1374803);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)17U, (int32_t)1500165, (int32_t)777191, (int32_t)2235880,
      (int32_t)3406031);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)18U, (int32_t)-542412, (int32_t)-2831860, (int32_t)-1671176,
      (int32_t)-1846953);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)19U, (int32_t)-2584293, (int32_t)-3724270, (int32_t)594136,
      (int32_t)-3776993);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)20U, (int32_t)-2013608, (int32_t)2432395, (int32_t)2454455,
      (int32_t)-164721);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)21U, (int32_t)1957272, (int32_t)3369112, (int32_t)185531,
      (int32_t)-1207385);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)22U, (int32_t)-3183426, (int32_t)162844, (int32_t)1616392,
      (int32_t)3014001);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)23U, (int32_t)810149, (int32_t)1652634, (int32_t)-3694233,
      (int32_t)-1799107);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)24U, (int32_t)-3038916, (int32_t)3523897, (int32_t)3866901,
      (int32_t)269760);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)25U, (int32_t)2213111, (int32_t)-975884, (int32_t)1717735,
      (int32_t)472078);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)26U, (int32_t)-426683, (int32_t)1723600, (int32_t)-1803090,
      (int32_t)1910376);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)27U, (int32_t)-1667432, (int32_t)-1104333, (int32_t)-260646,
      (int32_t)-3833893);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)28U, (int32_t)-2939036, (int32_t)-2235985, (int32_t)-420899,
      (int32_t)-2286327);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)29U, (int32_t)183443, (int32_t)-976891, (int32_t)1612842,
      (int32_t)-3545687);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)30U, (int32_t)-554416, (int32_t)3919660, (int32_t)-48306,
      (int32_t)-1362209);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0_round(
      re, (size_t)31U, (int32_t)3937738, (int32_t)1400424, (int32_t)-846154,
      (int32_t)1976782);
}

static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_ntt_ntt(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit re[32U],
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret[32U]) {
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_7(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_6(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_5(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_4(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_3(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_2(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_1(re);
  libcrux_ml_dsa_simd_portable_ntt_ntt_at_layer_0(re);
  memcpy(ret, re,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline void libcrux_ml_dsa_simd_portable_ntt_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_units[32U],
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
      copy_of_simd_units[32U];
  memcpy(copy_of_simd_units, simd_units,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret0[32U];
  libcrux_ml_dsa_simd_portable_ntt_ntt(copy_of_simd_units, ret0);
  memcpy(ret, ret0,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_invntt_simd_unit_invert_ntt_at_layer_0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t zeta0, int32_t zeta1, int32_t zeta2, int32_t zeta3) {
  int32_t a_minus_b = simd_unit.coefficients[1U] - simd_unit.coefficients[0U];
  simd_unit.coefficients[0U] =
      simd_unit.coefficients[0U] + simd_unit.coefficients[1U];
  simd_unit.coefficients[1U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b, zeta0);
  int32_t a_minus_b0 = simd_unit.coefficients[3U] - simd_unit.coefficients[2U];
  simd_unit.coefficients[2U] =
      simd_unit.coefficients[2U] + simd_unit.coefficients[3U];
  simd_unit.coefficients[3U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b0, zeta1);
  int32_t a_minus_b1 = simd_unit.coefficients[5U] - simd_unit.coefficients[4U];
  simd_unit.coefficients[4U] =
      simd_unit.coefficients[4U] + simd_unit.coefficients[5U];
  simd_unit.coefficients[5U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b1, zeta2);
  int32_t a_minus_b2 = simd_unit.coefficients[7U] - simd_unit.coefficients[6U];
  simd_unit.coefficients[6U] =
      simd_unit.coefficients[6U] + simd_unit.coefficients[7U];
  simd_unit.coefficients[7U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b2, zeta3);
  return simd_unit;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re, size_t index,
    int32_t zeta0, int32_t zeta1, int32_t zeta2, int32_t zeta3) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
      libcrux_ml_dsa_simd_portable_invntt_simd_unit_invert_ntt_at_layer_0(
          re[index], zeta0, zeta1, zeta2, zeta3);
  re[index] = uu____0;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)0U, (int32_t)1976782, (int32_t)-846154, (int32_t)1400424,
      (int32_t)3937738);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)1U, (int32_t)-1362209, (int32_t)-48306, (int32_t)3919660,
      (int32_t)-554416);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)2U, (int32_t)-3545687, (int32_t)1612842, (int32_t)-976891,
      (int32_t)183443);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)3U, (int32_t)-2286327, (int32_t)-420899, (int32_t)-2235985,
      (int32_t)-2939036);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)4U, (int32_t)-3833893, (int32_t)-260646, (int32_t)-1104333,
      (int32_t)-1667432);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)5U, (int32_t)1910376, (int32_t)-1803090, (int32_t)1723600,
      (int32_t)-426683);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)6U, (int32_t)472078, (int32_t)1717735, (int32_t)-975884,
      (int32_t)2213111);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)7U, (int32_t)269760, (int32_t)3866901, (int32_t)3523897,
      (int32_t)-3038916);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)8U, (int32_t)-1799107, (int32_t)-3694233, (int32_t)1652634,
      (int32_t)810149);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)9U, (int32_t)3014001, (int32_t)1616392, (int32_t)162844,
      (int32_t)-3183426);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)10U, (int32_t)-1207385, (int32_t)185531, (int32_t)3369112,
      (int32_t)1957272);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)11U, (int32_t)-164721, (int32_t)2454455, (int32_t)2432395,
      (int32_t)-2013608);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)12U, (int32_t)-3776993, (int32_t)594136, (int32_t)-3724270,
      (int32_t)-2584293);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)13U, (int32_t)-1846953, (int32_t)-1671176, (int32_t)-2831860,
      (int32_t)-542412);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)14U, (int32_t)3406031, (int32_t)2235880, (int32_t)777191,
      (int32_t)1500165);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)15U, (int32_t)-1374803, (int32_t)-2546312, (int32_t)1917081,
      (int32_t)-1279661);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)16U, (int32_t)-1962642, (int32_t)3306115, (int32_t)1312455,
      (int32_t)-451100);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)17U, (int32_t)-1430225, (int32_t)-3318210, (int32_t)1237275,
      (int32_t)-1333058);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)18U, (int32_t)-1050970, (int32_t)1903435, (int32_t)1869119,
      (int32_t)-2994039);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)19U, (int32_t)-3548272, (int32_t)2635921, (int32_t)1250494,
      (int32_t)-3767016);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)20U, (int32_t)1595974, (int32_t)2486353, (int32_t)1247620,
      (int32_t)4055324);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)21U, (int32_t)1265009, (int32_t)-2590150, (int32_t)2691481,
      (int32_t)2842341);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)22U, (int32_t)203044, (int32_t)1735879, (int32_t)-3342277,
      (int32_t)3437287);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)23U, (int32_t)4108315, (int32_t)-2437823, (int32_t)286988,
      (int32_t)342297);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)24U, (int32_t)-3595838, (int32_t)-768622, (int32_t)-525098,
      (int32_t)-3556995);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)25U, (int32_t)3207046, (int32_t)2031748, (int32_t)-3122442,
      (int32_t)-655327);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)26U, (int32_t)-522500, (int32_t)-43260, (int32_t)-1613174,
      (int32_t)495491);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)27U, (int32_t)819034, (int32_t)909542, (int32_t)1859098,
      (int32_t)900702);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)28U, (int32_t)-3193378, (int32_t)-1197226, (int32_t)-3759364,
      (int32_t)-3520352);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)29U, (int32_t)3513181, (int32_t)-1235728, (int32_t)2434439,
      (int32_t)266997);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)30U, (int32_t)-3562462, (int32_t)-2446433, (int32_t)2244091,
      (int32_t)-3342478);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0_round(
      re, (size_t)31U, (int32_t)3817976, (int32_t)2316500, (int32_t)3407706,
      (int32_t)2091667);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_invntt_simd_unit_invert_ntt_at_layer_1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t zeta0, int32_t zeta1) {
  int32_t a_minus_b = simd_unit.coefficients[2U] - simd_unit.coefficients[0U];
  simd_unit.coefficients[0U] =
      simd_unit.coefficients[0U] + simd_unit.coefficients[2U];
  simd_unit.coefficients[2U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b, zeta0);
  int32_t a_minus_b0 = simd_unit.coefficients[3U] - simd_unit.coefficients[1U];
  simd_unit.coefficients[1U] =
      simd_unit.coefficients[1U] + simd_unit.coefficients[3U];
  simd_unit.coefficients[3U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b0, zeta0);
  int32_t a_minus_b1 = simd_unit.coefficients[6U] - simd_unit.coefficients[4U];
  simd_unit.coefficients[4U] =
      simd_unit.coefficients[4U] + simd_unit.coefficients[6U];
  simd_unit.coefficients[6U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b1, zeta1);
  int32_t a_minus_b2 = simd_unit.coefficients[7U] - simd_unit.coefficients[5U];
  simd_unit.coefficients[5U] =
      simd_unit.coefficients[5U] + simd_unit.coefficients[7U];
  simd_unit.coefficients[7U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b2, zeta1);
  return simd_unit;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re, size_t index,
    int32_t zeta_00, int32_t zeta_01) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
      libcrux_ml_dsa_simd_portable_invntt_simd_unit_invert_ntt_at_layer_1(
          re[index], zeta_00, zeta_01);
  re[index] = uu____0;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)0U, (int32_t)3839961, (int32_t)-3628969);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)1U, (int32_t)-3881060, (int32_t)-3019102);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)2U, (int32_t)-1439742, (int32_t)-812732);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)3U, (int32_t)-1584928, (int32_t)1285669);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)4U, (int32_t)1341330, (int32_t)1315589);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)5U, (int32_t)-177440, (int32_t)-2409325);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)6U, (int32_t)-1851402, (int32_t)3159746);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)7U, (int32_t)-3553272, (int32_t)189548);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)8U, (int32_t)-1316856, (int32_t)759969);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)9U, (int32_t)-210977, (int32_t)2389356);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)10U, (int32_t)-3249728, (int32_t)1653064);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)11U, (int32_t)-8578, (int32_t)-3724342);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)12U, (int32_t)3958618, (int32_t)904516);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)13U, (int32_t)-1100098, (int32_t)44288);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)14U, (int32_t)3097992, (int32_t)508951);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)15U, (int32_t)264944, (int32_t)-3343383);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)16U, (int32_t)-1430430, (int32_t)1852771);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)17U, (int32_t)1349076, (int32_t)-381987);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)18U, (int32_t)-1308169, (int32_t)-22981);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)19U, (int32_t)-1228525, (int32_t)-671102);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)20U, (int32_t)-2477047, (int32_t)-411027);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)21U, (int32_t)-3693493, (int32_t)-2967645);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)22U, (int32_t)2715295, (int32_t)2147896);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)23U, (int32_t)-983419, (int32_t)3412210);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)24U, (int32_t)126922, (int32_t)-3632928);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)25U, (int32_t)-3157330, (int32_t)-3190144);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)26U, (int32_t)-1000202, (int32_t)-4083598);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)27U, (int32_t)1939314, (int32_t)-1257611);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)28U, (int32_t)-1585221, (int32_t)2176455);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)29U, (int32_t)3475950, (int32_t)-1452451);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)30U, (int32_t)-3041255, (int32_t)-3677745);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1_round(
      re, (size_t)31U, (int32_t)-1528703, (int32_t)-3930395);
}

static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_invntt_simd_unit_invert_ntt_at_layer_2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    int32_t zeta) {
  int32_t a_minus_b = simd_unit.coefficients[4U] - simd_unit.coefficients[0U];
  simd_unit.coefficients[0U] =
      simd_unit.coefficients[0U] + simd_unit.coefficients[4U];
  simd_unit.coefficients[4U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b, zeta);
  int32_t a_minus_b0 = simd_unit.coefficients[5U] - simd_unit.coefficients[1U];
  simd_unit.coefficients[1U] =
      simd_unit.coefficients[1U] + simd_unit.coefficients[5U];
  simd_unit.coefficients[5U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b0, zeta);
  int32_t a_minus_b1 = simd_unit.coefficients[6U] - simd_unit.coefficients[2U];
  simd_unit.coefficients[2U] =
      simd_unit.coefficients[2U] + simd_unit.coefficients[6U];
  simd_unit.coefficients[6U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b1, zeta);
  int32_t a_minus_b2 = simd_unit.coefficients[7U] - simd_unit.coefficients[3U];
  simd_unit.coefficients[3U] =
      simd_unit.coefficients[3U] + simd_unit.coefficients[7U];
  simd_unit.coefficients[7U] =
      libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_fe_by_fer(
          a_minus_b2, zeta);
  return simd_unit;
}

static inline void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re, size_t index,
    int32_t zeta1) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
      libcrux_ml_dsa_simd_portable_invntt_simd_unit_invert_ntt_at_layer_2(
          re[index], zeta1);
  re[index] = uu____0;
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)0U, (int32_t)-2797779);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)1U, (int32_t)2071892);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)2U, (int32_t)-2556880);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)3U, (int32_t)3900724);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)4U, (int32_t)3881043);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)5U, (int32_t)954230);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)6U, (int32_t)531354);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)7U, (int32_t)811944);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)8U, (int32_t)3699596);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)9U, (int32_t)-1600420);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)10U, (int32_t)-2140649);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)11U, (int32_t)3507263);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)12U, (int32_t)-3821735);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)13U, (int32_t)3505694);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)14U, (int32_t)-1643818);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)15U, (int32_t)-1699267);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)16U, (int32_t)-539299);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)17U, (int32_t)2348700);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)18U, (int32_t)-300467);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)19U, (int32_t)3539968);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)20U, (int32_t)-2867647);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)21U, (int32_t)3574422);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)22U, (int32_t)-3043716);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)23U, (int32_t)-3861115);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)24U, (int32_t)3915439);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)25U, (int32_t)-2537516);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)26U, (int32_t)-3592148);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)27U, (int32_t)-1661693);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)28U, (int32_t)3530437);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)29U, (int32_t)3077325);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)30U, (int32_t)95776);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2_round(
      re, (size_t)31U, (int32_t)2706023);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 1
- ZETA= 280005
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_99(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)280005);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 2
- STEP_BY= 1
- ZETA= 4010497
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_1c(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)2U; i < (size_t)2U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)4010497);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 4
- STEP_BY= 1
- ZETA= -19422
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_6b(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)4U; i < (size_t)4U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-19422);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 6
- STEP_BY= 1
- ZETA= 1757237
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_44(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)6U; i < (size_t)6U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)1757237);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 1
- ZETA= -3277672
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a8(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-3277672);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 10
- STEP_BY= 1
- ZETA= -1399561
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_1f(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)10U; i < (size_t)10U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-1399561);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 12
- STEP_BY= 1
- ZETA= -3859737
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_95(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)12U; i < (size_t)12U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-3859737);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 14
- STEP_BY= 1
- ZETA= -2118186
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3b(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)14U; i < (size_t)14U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2118186);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 1
- ZETA= -2108549
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2108549);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 18
- STEP_BY= 1
- ZETA= 2619752
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_e4(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)18U; i < (size_t)18U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2619752);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 20
- STEP_BY= 1
- ZETA= -1119584
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_de(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)20U; i < (size_t)20U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-1119584);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 22
- STEP_BY= 1
- ZETA= -549488
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_05(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)22U; i < (size_t)22U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-549488);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 1
- ZETA= 3585928
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_d9(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)3585928);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 26
- STEP_BY= 1
- ZETA= -1079900
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3a(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)26U; i < (size_t)26U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-1079900);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 28
- STEP_BY= 1
- ZETA= 1024112
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3b0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)28U; i < (size_t)28U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)1024112);
    re[j + (size_t)1U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 30
- STEP_BY= 1
- ZETA= 2725464
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)30U; i < (size_t)30U + (size_t)1U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)1U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)1U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2725464);
    re[j + (size_t)1U] = uu____1;
  }
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_3(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_99(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_1c(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_6b(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_44(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a8(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_1f(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_95(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3b(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_e4(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_de(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_05(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_d9(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3a(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3b0(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a0(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 2
- ZETA= 2680103
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_990(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2680103);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 4
- STEP_BY= 2
- ZETA= 3111497
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_6b0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)4U; i < (size_t)4U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)3111497);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 2
- ZETA= -2884855
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2884855);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 12
- STEP_BY= 2
- ZETA= 3119733
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_950(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)12U; i < (size_t)12U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)3119733);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 2
- ZETA= -2091905
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2091905);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 20
- STEP_BY= 2
- ZETA= -359251
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_de0(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)20U; i < (size_t)20U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-359251);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 2
- ZETA= 2353451
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_d90(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)2353451);
    re[j + (size_t)2U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 28
- STEP_BY= 2
- ZETA= 1826347
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3b1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)28U; i < (size_t)28U + (size_t)2U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)2U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)2U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)1826347);
    re[j + (size_t)2U] = uu____1;
  }
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_4(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_990(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_6b0(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a80(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_950(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a0(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_de0(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_d90(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_3b1(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 4
- ZETA= 466468
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_991(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)4U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)4U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)466468);
    re[j + (size_t)4U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 8
- STEP_BY= 4
- ZETA= -876248
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a81(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)8U; i < (size_t)8U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)4U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)4U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-876248);
    re[j + (size_t)4U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 4
- ZETA= -777960
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a1(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)4U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)4U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-777960);
    re[j + (size_t)4U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 24
- STEP_BY= 4
- ZETA= 237124
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_d91(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)24U; i < (size_t)24U + (size_t)4U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)4U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)4U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)237124);
    re[j + (size_t)4U] = uu____1;
  }
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_5(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_991(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_a81(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a1(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_d91(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 8
- ZETA= -518909
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_992(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)8U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)8U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)8U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-518909);
    re[j + (size_t)8U] = uu____1;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 16
- STEP_BY= 8
- ZETA= -2608894
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a2(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)16U; i < (size_t)16U + (size_t)8U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)8U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)8U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)-2608894);
    re[j + (size_t)8U] = uu____1;
  }
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_6(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_992(re);
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_7a2(re);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.invntt.outer_3_plus
with const generics
- OFFSET= 0
- STEP_BY= 16
- ZETA= 25847
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_993(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  for (size_t i = (size_t)0U; i < (size_t)0U + (size_t)16U; i++) {
    size_t j = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit a_minus_b =
        libcrux_ml_dsa_simd_portable_arithmetic_subtract(&re[j + (size_t)16U],
                                                         &re[j]);
    re[j] = libcrux_ml_dsa_simd_portable_arithmetic_add(&re[j],
                                                        &re[j + (size_t)16U]);
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____1 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            a_minus_b, (int32_t)25847);
    re[j + (size_t)16U] = uu____1;
  }
}

static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_7(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *re) {
  libcrux_ml_dsa_simd_portable_invntt_outer_3_plus_993(re);
}

static inline void libcrux_ml_dsa_simd_portable_invntt_invert_ntt_montgomery(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit re[32U],
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret[32U]) {
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_0(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_1(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_2(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_3(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_4(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_5(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_6(re);
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_at_layer_7(re);
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_arithmetic_montgomery_multiply_by_constant(
            re[i0], (int32_t)41978);
    re[i0] = uu____0;
  }
  memcpy(ret, re,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline void libcrux_ml_dsa_simd_portable_invert_ntt_montgomery_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_units[32U],
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
      copy_of_simd_units[32U];
  memcpy(copy_of_simd_units, simd_units,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret0[32U];
  libcrux_ml_dsa_simd_portable_invntt_invert_ntt_montgomery(copy_of_simd_units,
                                                            ret0);
  memcpy(ret, ret0,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
}

typedef struct libcrux_ml_dsa_samplex4_portable_PortableSampler_s {
} libcrux_ml_dsa_samplex4_portable_PortableSampler;

typedef struct uint8_t_840size_t__x4_s {
  uint8_t fst[840U];
  uint8_t snd[840U];
  uint8_t thd[840U];
  uint8_t f3[840U];
} uint8_t_840size_t__x4;

typedef struct size_t_x2_s {
  size_t fst;
  size_t snd;
} size_t_x2;

/**
A monomorphic instance of K.
with types uint8_t[4032size_t], uint8_t[1952size_t]

*/
typedef struct tuple_a0_s {
  uint8_t fst[4032U];
  uint8_t snd[1952U];
} tuple_a0;

/**
A monomorphic instance of libcrux_ml_dsa.polynomial.PolynomialRingElement
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit

*/
typedef struct libcrux_ml_dsa_polynomial_PolynomialRingElement_9b_s {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_units[32U];
} libcrux_ml_dsa_polynomial_PolynomialRingElement_9b;

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.ZERO_ff
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_polynomial_ZERO_ff_ba(void) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b lit;
  lit.simd_units[0U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[1U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[2U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[3U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[4U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[5U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[6U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[7U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[8U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[9U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[10U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[11U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[12U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[13U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[14U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[15U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[16U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[17U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[18U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[19U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[20U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[21U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[22U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[23U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[24U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[25U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[26U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[27U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[28U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[29U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[30U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  lit.simd_units[31U] = libcrux_ml_dsa_simd_portable_ZERO_36();
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.SampleArgs
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- $840size_t
- $6size_t
- $5size_t
*/
typedef struct libcrux_ml_dsa_sample_SampleArgs_4e_s {
  uint8_t_840size_t__x4 *rand_stack;
  Eurydice_slice tmp_stack;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b (*out)[5U];
  Eurydice_slice indices;
} libcrux_ml_dsa_sample_SampleArgs_4e;

/**
This function found in impl {libcrux_ml_dsa::sample::SampleArgs<'a, SIMDUnit,
STACK_SIZE, ROWS_IN_A, COLUMNS_IN_A>[TraitClause@0, TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.sample.new_29
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- STACK_SIZE= 840
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static inline libcrux_ml_dsa_sample_SampleArgs_4e
libcrux_ml_dsa_sample_new_29_ab(
    uint8_t_840size_t__x4 *rand_stack, Eurydice_slice tmp_stack,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b (*out)[5U],
    Eurydice_slice indices) {
  libcrux_ml_dsa_sample_SampleArgs_4e lit;
  lit.rand_stack = rand_stack;
  lit.tmp_stack = tmp_stack;
  lit.out = out;
  lit.indices = indices;
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_four_ring_elements
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake128X4 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_sample_sample_four_ring_elements_49(
    uint8_t seed0[34U], uint16_t domain_separator0, uint16_t domain_separator1,
    uint16_t domain_seperator2, uint16_t domain_separator3,
    libcrux_ml_dsa_sample_SampleArgs_4e *memory) {
  KRML_HOST_EPRINTF(
      "KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
      "Eurydice error: Failure(\"Error looking trait impl: "
      "core::slice::iter::{core::iter::traits::iterator::Iterator for "
      "core::slice::iter::Iter<\'a, T>[TraitClause@0]}#182<\'_, (usize, "
      "usize)>[core::marker::Sized<(usize, usize)>] enumerate\")\n");
  KRML_HOST_EXIT(255U);
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.matrix_A_6_by_5
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake128X4 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_samplex4_matrix_A_6_by_5_49(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U][5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b A[6U][5U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    A[i][0U] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
    A[i][1U] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
    A[i][2U] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
    A[i][3U] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
    A[i][4U] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  uint8_t uu____0[840U] = {0U};
  uint8_t uu____1[840U] = {0U};
  uint8_t_840size_t__x4 rand_stack;
  rand_stack.fst[0U] = 0U;
  rand_stack.fst[1U] = 0U;
  rand_stack.fst[2U] = 0U;
  rand_stack.fst[3U] = 0U;
  rand_stack.fst[4U] = 0U;
  rand_stack.fst[5U] = 0U;
  rand_stack.fst[6U] = 0U;
  rand_stack.fst[7U] = 0U;
  rand_stack.fst[8U] = 0U;
  rand_stack.fst[9U] = 0U;
  rand_stack.fst[10U] = 0U;
  rand_stack.fst[11U] = 0U;
  rand_stack.fst[12U] = 0U;
  rand_stack.fst[13U] = 0U;
  rand_stack.fst[14U] = 0U;
  rand_stack.fst[15U] = 0U;
  rand_stack.fst[16U] = 0U;
  rand_stack.fst[17U] = 0U;
  rand_stack.fst[18U] = 0U;
  rand_stack.fst[19U] = 0U;
  rand_stack.fst[20U] = 0U;
  rand_stack.fst[21U] = 0U;
  rand_stack.fst[22U] = 0U;
  rand_stack.fst[23U] = 0U;
  rand_stack.fst[24U] = 0U;
  rand_stack.fst[25U] = 0U;
  rand_stack.fst[26U] = 0U;
  rand_stack.fst[27U] = 0U;
  rand_stack.fst[28U] = 0U;
  rand_stack.fst[29U] = 0U;
  rand_stack.fst[30U] = 0U;
  rand_stack.fst[31U] = 0U;
  rand_stack.fst[32U] = 0U;
  rand_stack.fst[33U] = 0U;
  rand_stack.fst[34U] = 0U;
  rand_stack.fst[35U] = 0U;
  rand_stack.fst[36U] = 0U;
  rand_stack.fst[37U] = 0U;
  rand_stack.fst[38U] = 0U;
  rand_stack.fst[39U] = 0U;
  rand_stack.fst[40U] = 0U;
  rand_stack.fst[41U] = 0U;
  rand_stack.fst[42U] = 0U;
  rand_stack.fst[43U] = 0U;
  rand_stack.fst[44U] = 0U;
  rand_stack.fst[45U] = 0U;
  rand_stack.fst[46U] = 0U;
  rand_stack.fst[47U] = 0U;
  rand_stack.fst[48U] = 0U;
  rand_stack.fst[49U] = 0U;
  rand_stack.fst[50U] = 0U;
  rand_stack.fst[51U] = 0U;
  rand_stack.fst[52U] = 0U;
  rand_stack.fst[53U] = 0U;
  rand_stack.fst[54U] = 0U;
  rand_stack.fst[55U] = 0U;
  rand_stack.fst[56U] = 0U;
  rand_stack.fst[57U] = 0U;
  rand_stack.fst[58U] = 0U;
  rand_stack.fst[59U] = 0U;
  rand_stack.fst[60U] = 0U;
  rand_stack.fst[61U] = 0U;
  rand_stack.fst[62U] = 0U;
  rand_stack.fst[63U] = 0U;
  rand_stack.fst[64U] = 0U;
  rand_stack.fst[65U] = 0U;
  rand_stack.fst[66U] = 0U;
  rand_stack.fst[67U] = 0U;
  rand_stack.fst[68U] = 0U;
  rand_stack.fst[69U] = 0U;
  rand_stack.fst[70U] = 0U;
  rand_stack.fst[71U] = 0U;
  rand_stack.fst[72U] = 0U;
  rand_stack.fst[73U] = 0U;
  rand_stack.fst[74U] = 0U;
  rand_stack.fst[75U] = 0U;
  rand_stack.fst[76U] = 0U;
  rand_stack.fst[77U] = 0U;
  rand_stack.fst[78U] = 0U;
  rand_stack.fst[79U] = 0U;
  rand_stack.fst[80U] = 0U;
  rand_stack.fst[81U] = 0U;
  rand_stack.fst[82U] = 0U;
  rand_stack.fst[83U] = 0U;
  rand_stack.fst[84U] = 0U;
  rand_stack.fst[85U] = 0U;
  rand_stack.fst[86U] = 0U;
  rand_stack.fst[87U] = 0U;
  rand_stack.fst[88U] = 0U;
  rand_stack.fst[89U] = 0U;
  rand_stack.fst[90U] = 0U;
  rand_stack.fst[91U] = 0U;
  rand_stack.fst[92U] = 0U;
  rand_stack.fst[93U] = 0U;
  rand_stack.fst[94U] = 0U;
  rand_stack.fst[95U] = 0U;
  rand_stack.fst[96U] = 0U;
  rand_stack.fst[97U] = 0U;
  rand_stack.fst[98U] = 0U;
  rand_stack.fst[99U] = 0U;
  rand_stack.fst[100U] = 0U;
  rand_stack.fst[101U] = 0U;
  rand_stack.fst[102U] = 0U;
  rand_stack.fst[103U] = 0U;
  rand_stack.fst[104U] = 0U;
  rand_stack.fst[105U] = 0U;
  rand_stack.fst[106U] = 0U;
  rand_stack.fst[107U] = 0U;
  rand_stack.fst[108U] = 0U;
  rand_stack.fst[109U] = 0U;
  rand_stack.fst[110U] = 0U;
  rand_stack.fst[111U] = 0U;
  rand_stack.fst[112U] = 0U;
  rand_stack.fst[113U] = 0U;
  rand_stack.fst[114U] = 0U;
  rand_stack.fst[115U] = 0U;
  rand_stack.fst[116U] = 0U;
  rand_stack.fst[117U] = 0U;
  rand_stack.fst[118U] = 0U;
  rand_stack.fst[119U] = 0U;
  rand_stack.fst[120U] = 0U;
  rand_stack.fst[121U] = 0U;
  rand_stack.fst[122U] = 0U;
  rand_stack.fst[123U] = 0U;
  rand_stack.fst[124U] = 0U;
  rand_stack.fst[125U] = 0U;
  rand_stack.fst[126U] = 0U;
  rand_stack.fst[127U] = 0U;
  rand_stack.fst[128U] = 0U;
  rand_stack.fst[129U] = 0U;
  rand_stack.fst[130U] = 0U;
  rand_stack.fst[131U] = 0U;
  rand_stack.fst[132U] = 0U;
  rand_stack.fst[133U] = 0U;
  rand_stack.fst[134U] = 0U;
  rand_stack.fst[135U] = 0U;
  rand_stack.fst[136U] = 0U;
  rand_stack.fst[137U] = 0U;
  rand_stack.fst[138U] = 0U;
  rand_stack.fst[139U] = 0U;
  rand_stack.fst[140U] = 0U;
  rand_stack.fst[141U] = 0U;
  rand_stack.fst[142U] = 0U;
  rand_stack.fst[143U] = 0U;
  rand_stack.fst[144U] = 0U;
  rand_stack.fst[145U] = 0U;
  rand_stack.fst[146U] = 0U;
  rand_stack.fst[147U] = 0U;
  rand_stack.fst[148U] = 0U;
  rand_stack.fst[149U] = 0U;
  rand_stack.fst[150U] = 0U;
  rand_stack.fst[151U] = 0U;
  rand_stack.fst[152U] = 0U;
  rand_stack.fst[153U] = 0U;
  rand_stack.fst[154U] = 0U;
  rand_stack.fst[155U] = 0U;
  rand_stack.fst[156U] = 0U;
  rand_stack.fst[157U] = 0U;
  rand_stack.fst[158U] = 0U;
  rand_stack.fst[159U] = 0U;
  rand_stack.fst[160U] = 0U;
  rand_stack.fst[161U] = 0U;
  rand_stack.fst[162U] = 0U;
  rand_stack.fst[163U] = 0U;
  rand_stack.fst[164U] = 0U;
  rand_stack.fst[165U] = 0U;
  rand_stack.fst[166U] = 0U;
  rand_stack.fst[167U] = 0U;
  rand_stack.fst[168U] = 0U;
  rand_stack.fst[169U] = 0U;
  rand_stack.fst[170U] = 0U;
  rand_stack.fst[171U] = 0U;
  rand_stack.fst[172U] = 0U;
  rand_stack.fst[173U] = 0U;
  rand_stack.fst[174U] = 0U;
  rand_stack.fst[175U] = 0U;
  rand_stack.fst[176U] = 0U;
  rand_stack.fst[177U] = 0U;
  rand_stack.fst[178U] = 0U;
  rand_stack.fst[179U] = 0U;
  rand_stack.fst[180U] = 0U;
  rand_stack.fst[181U] = 0U;
  rand_stack.fst[182U] = 0U;
  rand_stack.fst[183U] = 0U;
  rand_stack.fst[184U] = 0U;
  rand_stack.fst[185U] = 0U;
  rand_stack.fst[186U] = 0U;
  rand_stack.fst[187U] = 0U;
  rand_stack.fst[188U] = 0U;
  rand_stack.fst[189U] = 0U;
  rand_stack.fst[190U] = 0U;
  rand_stack.fst[191U] = 0U;
  rand_stack.fst[192U] = 0U;
  rand_stack.fst[193U] = 0U;
  rand_stack.fst[194U] = 0U;
  rand_stack.fst[195U] = 0U;
  rand_stack.fst[196U] = 0U;
  rand_stack.fst[197U] = 0U;
  rand_stack.fst[198U] = 0U;
  rand_stack.fst[199U] = 0U;
  rand_stack.fst[200U] = 0U;
  rand_stack.fst[201U] = 0U;
  rand_stack.fst[202U] = 0U;
  rand_stack.fst[203U] = 0U;
  rand_stack.fst[204U] = 0U;
  rand_stack.fst[205U] = 0U;
  rand_stack.fst[206U] = 0U;
  rand_stack.fst[207U] = 0U;
  rand_stack.fst[208U] = 0U;
  rand_stack.fst[209U] = 0U;
  rand_stack.fst[210U] = 0U;
  rand_stack.fst[211U] = 0U;
  rand_stack.fst[212U] = 0U;
  rand_stack.fst[213U] = 0U;
  rand_stack.fst[214U] = 0U;
  rand_stack.fst[215U] = 0U;
  rand_stack.fst[216U] = 0U;
  rand_stack.fst[217U] = 0U;
  rand_stack.fst[218U] = 0U;
  rand_stack.fst[219U] = 0U;
  rand_stack.fst[220U] = 0U;
  rand_stack.fst[221U] = 0U;
  rand_stack.fst[222U] = 0U;
  rand_stack.fst[223U] = 0U;
  rand_stack.fst[224U] = 0U;
  rand_stack.fst[225U] = 0U;
  rand_stack.fst[226U] = 0U;
  rand_stack.fst[227U] = 0U;
  rand_stack.fst[228U] = 0U;
  rand_stack.fst[229U] = 0U;
  rand_stack.fst[230U] = 0U;
  rand_stack.fst[231U] = 0U;
  rand_stack.fst[232U] = 0U;
  rand_stack.fst[233U] = 0U;
  rand_stack.fst[234U] = 0U;
  rand_stack.fst[235U] = 0U;
  rand_stack.fst[236U] = 0U;
  rand_stack.fst[237U] = 0U;
  rand_stack.fst[238U] = 0U;
  rand_stack.fst[239U] = 0U;
  rand_stack.fst[240U] = 0U;
  rand_stack.fst[241U] = 0U;
  rand_stack.fst[242U] = 0U;
  rand_stack.fst[243U] = 0U;
  rand_stack.fst[244U] = 0U;
  rand_stack.fst[245U] = 0U;
  rand_stack.fst[246U] = 0U;
  rand_stack.fst[247U] = 0U;
  rand_stack.fst[248U] = 0U;
  rand_stack.fst[249U] = 0U;
  rand_stack.fst[250U] = 0U;
  rand_stack.fst[251U] = 0U;
  rand_stack.fst[252U] = 0U;
  rand_stack.fst[253U] = 0U;
  rand_stack.fst[254U] = 0U;
  rand_stack.fst[255U] = 0U;
  rand_stack.fst[256U] = 0U;
  rand_stack.fst[257U] = 0U;
  rand_stack.fst[258U] = 0U;
  rand_stack.fst[259U] = 0U;
  rand_stack.fst[260U] = 0U;
  rand_stack.fst[261U] = 0U;
  rand_stack.fst[262U] = 0U;
  rand_stack.fst[263U] = 0U;
  rand_stack.fst[264U] = 0U;
  rand_stack.fst[265U] = 0U;
  rand_stack.fst[266U] = 0U;
  rand_stack.fst[267U] = 0U;
  rand_stack.fst[268U] = 0U;
  rand_stack.fst[269U] = 0U;
  rand_stack.fst[270U] = 0U;
  rand_stack.fst[271U] = 0U;
  rand_stack.fst[272U] = 0U;
  rand_stack.fst[273U] = 0U;
  rand_stack.fst[274U] = 0U;
  rand_stack.fst[275U] = 0U;
  rand_stack.fst[276U] = 0U;
  rand_stack.fst[277U] = 0U;
  rand_stack.fst[278U] = 0U;
  rand_stack.fst[279U] = 0U;
  rand_stack.fst[280U] = 0U;
  rand_stack.fst[281U] = 0U;
  rand_stack.fst[282U] = 0U;
  rand_stack.fst[283U] = 0U;
  rand_stack.fst[284U] = 0U;
  rand_stack.fst[285U] = 0U;
  rand_stack.fst[286U] = 0U;
  rand_stack.fst[287U] = 0U;
  rand_stack.fst[288U] = 0U;
  rand_stack.fst[289U] = 0U;
  rand_stack.fst[290U] = 0U;
  rand_stack.fst[291U] = 0U;
  rand_stack.fst[292U] = 0U;
  rand_stack.fst[293U] = 0U;
  rand_stack.fst[294U] = 0U;
  rand_stack.fst[295U] = 0U;
  rand_stack.fst[296U] = 0U;
  rand_stack.fst[297U] = 0U;
  rand_stack.fst[298U] = 0U;
  rand_stack.fst[299U] = 0U;
  rand_stack.fst[300U] = 0U;
  rand_stack.fst[301U] = 0U;
  rand_stack.fst[302U] = 0U;
  rand_stack.fst[303U] = 0U;
  rand_stack.fst[304U] = 0U;
  rand_stack.fst[305U] = 0U;
  rand_stack.fst[306U] = 0U;
  rand_stack.fst[307U] = 0U;
  rand_stack.fst[308U] = 0U;
  rand_stack.fst[309U] = 0U;
  rand_stack.fst[310U] = 0U;
  rand_stack.fst[311U] = 0U;
  rand_stack.fst[312U] = 0U;
  rand_stack.fst[313U] = 0U;
  rand_stack.fst[314U] = 0U;
  rand_stack.fst[315U] = 0U;
  rand_stack.fst[316U] = 0U;
  rand_stack.fst[317U] = 0U;
  rand_stack.fst[318U] = 0U;
  rand_stack.fst[319U] = 0U;
  rand_stack.fst[320U] = 0U;
  rand_stack.fst[321U] = 0U;
  rand_stack.fst[322U] = 0U;
  rand_stack.fst[323U] = 0U;
  rand_stack.fst[324U] = 0U;
  rand_stack.fst[325U] = 0U;
  rand_stack.fst[326U] = 0U;
  rand_stack.fst[327U] = 0U;
  rand_stack.fst[328U] = 0U;
  rand_stack.fst[329U] = 0U;
  rand_stack.fst[330U] = 0U;
  rand_stack.fst[331U] = 0U;
  rand_stack.fst[332U] = 0U;
  rand_stack.fst[333U] = 0U;
  rand_stack.fst[334U] = 0U;
  rand_stack.fst[335U] = 0U;
  rand_stack.fst[336U] = 0U;
  rand_stack.fst[337U] = 0U;
  rand_stack.fst[338U] = 0U;
  rand_stack.fst[339U] = 0U;
  rand_stack.fst[340U] = 0U;
  rand_stack.fst[341U] = 0U;
  rand_stack.fst[342U] = 0U;
  rand_stack.fst[343U] = 0U;
  rand_stack.fst[344U] = 0U;
  rand_stack.fst[345U] = 0U;
  rand_stack.fst[346U] = 0U;
  rand_stack.fst[347U] = 0U;
  rand_stack.fst[348U] = 0U;
  rand_stack.fst[349U] = 0U;
  rand_stack.fst[350U] = 0U;
  rand_stack.fst[351U] = 0U;
  rand_stack.fst[352U] = 0U;
  rand_stack.fst[353U] = 0U;
  rand_stack.fst[354U] = 0U;
  rand_stack.fst[355U] = 0U;
  rand_stack.fst[356U] = 0U;
  rand_stack.fst[357U] = 0U;
  rand_stack.fst[358U] = 0U;
  rand_stack.fst[359U] = 0U;
  rand_stack.fst[360U] = 0U;
  rand_stack.fst[361U] = 0U;
  rand_stack.fst[362U] = 0U;
  rand_stack.fst[363U] = 0U;
  rand_stack.fst[364U] = 0U;
  rand_stack.fst[365U] = 0U;
  rand_stack.fst[366U] = 0U;
  rand_stack.fst[367U] = 0U;
  rand_stack.fst[368U] = 0U;
  rand_stack.fst[369U] = 0U;
  rand_stack.fst[370U] = 0U;
  rand_stack.fst[371U] = 0U;
  rand_stack.fst[372U] = 0U;
  rand_stack.fst[373U] = 0U;
  rand_stack.fst[374U] = 0U;
  rand_stack.fst[375U] = 0U;
  rand_stack.fst[376U] = 0U;
  rand_stack.fst[377U] = 0U;
  rand_stack.fst[378U] = 0U;
  rand_stack.fst[379U] = 0U;
  rand_stack.fst[380U] = 0U;
  rand_stack.fst[381U] = 0U;
  rand_stack.fst[382U] = 0U;
  rand_stack.fst[383U] = 0U;
  rand_stack.fst[384U] = 0U;
  rand_stack.fst[385U] = 0U;
  rand_stack.fst[386U] = 0U;
  rand_stack.fst[387U] = 0U;
  rand_stack.fst[388U] = 0U;
  rand_stack.fst[389U] = 0U;
  rand_stack.fst[390U] = 0U;
  rand_stack.fst[391U] = 0U;
  rand_stack.fst[392U] = 0U;
  rand_stack.fst[393U] = 0U;
  rand_stack.fst[394U] = 0U;
  rand_stack.fst[395U] = 0U;
  rand_stack.fst[396U] = 0U;
  rand_stack.fst[397U] = 0U;
  rand_stack.fst[398U] = 0U;
  rand_stack.fst[399U] = 0U;
  rand_stack.fst[400U] = 0U;
  rand_stack.fst[401U] = 0U;
  rand_stack.fst[402U] = 0U;
  rand_stack.fst[403U] = 0U;
  rand_stack.fst[404U] = 0U;
  rand_stack.fst[405U] = 0U;
  rand_stack.fst[406U] = 0U;
  rand_stack.fst[407U] = 0U;
  rand_stack.fst[408U] = 0U;
  rand_stack.fst[409U] = 0U;
  rand_stack.fst[410U] = 0U;
  rand_stack.fst[411U] = 0U;
  rand_stack.fst[412U] = 0U;
  rand_stack.fst[413U] = 0U;
  rand_stack.fst[414U] = 0U;
  rand_stack.fst[415U] = 0U;
  rand_stack.fst[416U] = 0U;
  rand_stack.fst[417U] = 0U;
  rand_stack.fst[418U] = 0U;
  rand_stack.fst[419U] = 0U;
  rand_stack.fst[420U] = 0U;
  rand_stack.fst[421U] = 0U;
  rand_stack.fst[422U] = 0U;
  rand_stack.fst[423U] = 0U;
  rand_stack.fst[424U] = 0U;
  rand_stack.fst[425U] = 0U;
  rand_stack.fst[426U] = 0U;
  rand_stack.fst[427U] = 0U;
  rand_stack.fst[428U] = 0U;
  rand_stack.fst[429U] = 0U;
  rand_stack.fst[430U] = 0U;
  rand_stack.fst[431U] = 0U;
  rand_stack.fst[432U] = 0U;
  rand_stack.fst[433U] = 0U;
  rand_stack.fst[434U] = 0U;
  rand_stack.fst[435U] = 0U;
  rand_stack.fst[436U] = 0U;
  rand_stack.fst[437U] = 0U;
  rand_stack.fst[438U] = 0U;
  rand_stack.fst[439U] = 0U;
  rand_stack.fst[440U] = 0U;
  rand_stack.fst[441U] = 0U;
  rand_stack.fst[442U] = 0U;
  rand_stack.fst[443U] = 0U;
  rand_stack.fst[444U] = 0U;
  rand_stack.fst[445U] = 0U;
  rand_stack.fst[446U] = 0U;
  rand_stack.fst[447U] = 0U;
  rand_stack.fst[448U] = 0U;
  rand_stack.fst[449U] = 0U;
  rand_stack.fst[450U] = 0U;
  rand_stack.fst[451U] = 0U;
  rand_stack.fst[452U] = 0U;
  rand_stack.fst[453U] = 0U;
  rand_stack.fst[454U] = 0U;
  rand_stack.fst[455U] = 0U;
  rand_stack.fst[456U] = 0U;
  rand_stack.fst[457U] = 0U;
  rand_stack.fst[458U] = 0U;
  rand_stack.fst[459U] = 0U;
  rand_stack.fst[460U] = 0U;
  rand_stack.fst[461U] = 0U;
  rand_stack.fst[462U] = 0U;
  rand_stack.fst[463U] = 0U;
  rand_stack.fst[464U] = 0U;
  rand_stack.fst[465U] = 0U;
  rand_stack.fst[466U] = 0U;
  rand_stack.fst[467U] = 0U;
  rand_stack.fst[468U] = 0U;
  rand_stack.fst[469U] = 0U;
  rand_stack.fst[470U] = 0U;
  rand_stack.fst[471U] = 0U;
  rand_stack.fst[472U] = 0U;
  rand_stack.fst[473U] = 0U;
  rand_stack.fst[474U] = 0U;
  rand_stack.fst[475U] = 0U;
  rand_stack.fst[476U] = 0U;
  rand_stack.fst[477U] = 0U;
  rand_stack.fst[478U] = 0U;
  rand_stack.fst[479U] = 0U;
  rand_stack.fst[480U] = 0U;
  rand_stack.fst[481U] = 0U;
  rand_stack.fst[482U] = 0U;
  rand_stack.fst[483U] = 0U;
  rand_stack.fst[484U] = 0U;
  rand_stack.fst[485U] = 0U;
  rand_stack.fst[486U] = 0U;
  rand_stack.fst[487U] = 0U;
  rand_stack.fst[488U] = 0U;
  rand_stack.fst[489U] = 0U;
  rand_stack.fst[490U] = 0U;
  rand_stack.fst[491U] = 0U;
  rand_stack.fst[492U] = 0U;
  rand_stack.fst[493U] = 0U;
  rand_stack.fst[494U] = 0U;
  rand_stack.fst[495U] = 0U;
  rand_stack.fst[496U] = 0U;
  rand_stack.fst[497U] = 0U;
  rand_stack.fst[498U] = 0U;
  rand_stack.fst[499U] = 0U;
  rand_stack.fst[500U] = 0U;
  rand_stack.fst[501U] = 0U;
  rand_stack.fst[502U] = 0U;
  rand_stack.fst[503U] = 0U;
  rand_stack.fst[504U] = 0U;
  rand_stack.fst[505U] = 0U;
  rand_stack.fst[506U] = 0U;
  rand_stack.fst[507U] = 0U;
  rand_stack.fst[508U] = 0U;
  rand_stack.fst[509U] = 0U;
  rand_stack.fst[510U] = 0U;
  rand_stack.fst[511U] = 0U;
  rand_stack.fst[512U] = 0U;
  rand_stack.fst[513U] = 0U;
  rand_stack.fst[514U] = 0U;
  rand_stack.fst[515U] = 0U;
  rand_stack.fst[516U] = 0U;
  rand_stack.fst[517U] = 0U;
  rand_stack.fst[518U] = 0U;
  rand_stack.fst[519U] = 0U;
  rand_stack.fst[520U] = 0U;
  rand_stack.fst[521U] = 0U;
  rand_stack.fst[522U] = 0U;
  rand_stack.fst[523U] = 0U;
  rand_stack.fst[524U] = 0U;
  rand_stack.fst[525U] = 0U;
  rand_stack.fst[526U] = 0U;
  rand_stack.fst[527U] = 0U;
  rand_stack.fst[528U] = 0U;
  rand_stack.fst[529U] = 0U;
  rand_stack.fst[530U] = 0U;
  rand_stack.fst[531U] = 0U;
  rand_stack.fst[532U] = 0U;
  rand_stack.fst[533U] = 0U;
  rand_stack.fst[534U] = 0U;
  rand_stack.fst[535U] = 0U;
  rand_stack.fst[536U] = 0U;
  rand_stack.fst[537U] = 0U;
  rand_stack.fst[538U] = 0U;
  rand_stack.fst[539U] = 0U;
  rand_stack.fst[540U] = 0U;
  rand_stack.fst[541U] = 0U;
  rand_stack.fst[542U] = 0U;
  rand_stack.fst[543U] = 0U;
  rand_stack.fst[544U] = 0U;
  rand_stack.fst[545U] = 0U;
  rand_stack.fst[546U] = 0U;
  rand_stack.fst[547U] = 0U;
  rand_stack.fst[548U] = 0U;
  rand_stack.fst[549U] = 0U;
  rand_stack.fst[550U] = 0U;
  rand_stack.fst[551U] = 0U;
  rand_stack.fst[552U] = 0U;
  rand_stack.fst[553U] = 0U;
  rand_stack.fst[554U] = 0U;
  rand_stack.fst[555U] = 0U;
  rand_stack.fst[556U] = 0U;
  rand_stack.fst[557U] = 0U;
  rand_stack.fst[558U] = 0U;
  rand_stack.fst[559U] = 0U;
  rand_stack.fst[560U] = 0U;
  rand_stack.fst[561U] = 0U;
  rand_stack.fst[562U] = 0U;
  rand_stack.fst[563U] = 0U;
  rand_stack.fst[564U] = 0U;
  rand_stack.fst[565U] = 0U;
  rand_stack.fst[566U] = 0U;
  rand_stack.fst[567U] = 0U;
  rand_stack.fst[568U] = 0U;
  rand_stack.fst[569U] = 0U;
  rand_stack.fst[570U] = 0U;
  rand_stack.fst[571U] = 0U;
  rand_stack.fst[572U] = 0U;
  rand_stack.fst[573U] = 0U;
  rand_stack.fst[574U] = 0U;
  rand_stack.fst[575U] = 0U;
  rand_stack.fst[576U] = 0U;
  rand_stack.fst[577U] = 0U;
  rand_stack.fst[578U] = 0U;
  rand_stack.fst[579U] = 0U;
  rand_stack.fst[580U] = 0U;
  rand_stack.fst[581U] = 0U;
  rand_stack.fst[582U] = 0U;
  rand_stack.fst[583U] = 0U;
  rand_stack.fst[584U] = 0U;
  rand_stack.fst[585U] = 0U;
  rand_stack.fst[586U] = 0U;
  rand_stack.fst[587U] = 0U;
  rand_stack.fst[588U] = 0U;
  rand_stack.fst[589U] = 0U;
  rand_stack.fst[590U] = 0U;
  rand_stack.fst[591U] = 0U;
  rand_stack.fst[592U] = 0U;
  rand_stack.fst[593U] = 0U;
  rand_stack.fst[594U] = 0U;
  rand_stack.fst[595U] = 0U;
  rand_stack.fst[596U] = 0U;
  rand_stack.fst[597U] = 0U;
  rand_stack.fst[598U] = 0U;
  rand_stack.fst[599U] = 0U;
  rand_stack.fst[600U] = 0U;
  rand_stack.fst[601U] = 0U;
  rand_stack.fst[602U] = 0U;
  rand_stack.fst[603U] = 0U;
  rand_stack.fst[604U] = 0U;
  rand_stack.fst[605U] = 0U;
  rand_stack.fst[606U] = 0U;
  rand_stack.fst[607U] = 0U;
  rand_stack.fst[608U] = 0U;
  rand_stack.fst[609U] = 0U;
  rand_stack.fst[610U] = 0U;
  rand_stack.fst[611U] = 0U;
  rand_stack.fst[612U] = 0U;
  rand_stack.fst[613U] = 0U;
  rand_stack.fst[614U] = 0U;
  rand_stack.fst[615U] = 0U;
  rand_stack.fst[616U] = 0U;
  rand_stack.fst[617U] = 0U;
  rand_stack.fst[618U] = 0U;
  rand_stack.fst[619U] = 0U;
  rand_stack.fst[620U] = 0U;
  rand_stack.fst[621U] = 0U;
  rand_stack.fst[622U] = 0U;
  rand_stack.fst[623U] = 0U;
  rand_stack.fst[624U] = 0U;
  rand_stack.fst[625U] = 0U;
  rand_stack.fst[626U] = 0U;
  rand_stack.fst[627U] = 0U;
  rand_stack.fst[628U] = 0U;
  rand_stack.fst[629U] = 0U;
  rand_stack.fst[630U] = 0U;
  rand_stack.fst[631U] = 0U;
  rand_stack.fst[632U] = 0U;
  rand_stack.fst[633U] = 0U;
  rand_stack.fst[634U] = 0U;
  rand_stack.fst[635U] = 0U;
  rand_stack.fst[636U] = 0U;
  rand_stack.fst[637U] = 0U;
  rand_stack.fst[638U] = 0U;
  rand_stack.fst[639U] = 0U;
  rand_stack.fst[640U] = 0U;
  rand_stack.fst[641U] = 0U;
  rand_stack.fst[642U] = 0U;
  rand_stack.fst[643U] = 0U;
  rand_stack.fst[644U] = 0U;
  rand_stack.fst[645U] = 0U;
  rand_stack.fst[646U] = 0U;
  rand_stack.fst[647U] = 0U;
  rand_stack.fst[648U] = 0U;
  rand_stack.fst[649U] = 0U;
  rand_stack.fst[650U] = 0U;
  rand_stack.fst[651U] = 0U;
  rand_stack.fst[652U] = 0U;
  rand_stack.fst[653U] = 0U;
  rand_stack.fst[654U] = 0U;
  rand_stack.fst[655U] = 0U;
  rand_stack.fst[656U] = 0U;
  rand_stack.fst[657U] = 0U;
  rand_stack.fst[658U] = 0U;
  rand_stack.fst[659U] = 0U;
  rand_stack.fst[660U] = 0U;
  rand_stack.fst[661U] = 0U;
  rand_stack.fst[662U] = 0U;
  rand_stack.fst[663U] = 0U;
  rand_stack.fst[664U] = 0U;
  rand_stack.fst[665U] = 0U;
  rand_stack.fst[666U] = 0U;
  rand_stack.fst[667U] = 0U;
  rand_stack.fst[668U] = 0U;
  rand_stack.fst[669U] = 0U;
  rand_stack.fst[670U] = 0U;
  rand_stack.fst[671U] = 0U;
  rand_stack.fst[672U] = 0U;
  rand_stack.fst[673U] = 0U;
  rand_stack.fst[674U] = 0U;
  rand_stack.fst[675U] = 0U;
  rand_stack.fst[676U] = 0U;
  rand_stack.fst[677U] = 0U;
  rand_stack.fst[678U] = 0U;
  rand_stack.fst[679U] = 0U;
  rand_stack.fst[680U] = 0U;
  rand_stack.fst[681U] = 0U;
  rand_stack.fst[682U] = 0U;
  rand_stack.fst[683U] = 0U;
  rand_stack.fst[684U] = 0U;
  rand_stack.fst[685U] = 0U;
  rand_stack.fst[686U] = 0U;
  rand_stack.fst[687U] = 0U;
  rand_stack.fst[688U] = 0U;
  rand_stack.fst[689U] = 0U;
  rand_stack.fst[690U] = 0U;
  rand_stack.fst[691U] = 0U;
  rand_stack.fst[692U] = 0U;
  rand_stack.fst[693U] = 0U;
  rand_stack.fst[694U] = 0U;
  rand_stack.fst[695U] = 0U;
  rand_stack.fst[696U] = 0U;
  rand_stack.fst[697U] = 0U;
  rand_stack.fst[698U] = 0U;
  rand_stack.fst[699U] = 0U;
  rand_stack.fst[700U] = 0U;
  rand_stack.fst[701U] = 0U;
  rand_stack.fst[702U] = 0U;
  rand_stack.fst[703U] = 0U;
  rand_stack.fst[704U] = 0U;
  rand_stack.fst[705U] = 0U;
  rand_stack.fst[706U] = 0U;
  rand_stack.fst[707U] = 0U;
  rand_stack.fst[708U] = 0U;
  rand_stack.fst[709U] = 0U;
  rand_stack.fst[710U] = 0U;
  rand_stack.fst[711U] = 0U;
  rand_stack.fst[712U] = 0U;
  rand_stack.fst[713U] = 0U;
  rand_stack.fst[714U] = 0U;
  rand_stack.fst[715U] = 0U;
  rand_stack.fst[716U] = 0U;
  rand_stack.fst[717U] = 0U;
  rand_stack.fst[718U] = 0U;
  rand_stack.fst[719U] = 0U;
  rand_stack.fst[720U] = 0U;
  rand_stack.fst[721U] = 0U;
  rand_stack.fst[722U] = 0U;
  rand_stack.fst[723U] = 0U;
  rand_stack.fst[724U] = 0U;
  rand_stack.fst[725U] = 0U;
  rand_stack.fst[726U] = 0U;
  rand_stack.fst[727U] = 0U;
  rand_stack.fst[728U] = 0U;
  rand_stack.fst[729U] = 0U;
  rand_stack.fst[730U] = 0U;
  rand_stack.fst[731U] = 0U;
  rand_stack.fst[732U] = 0U;
  rand_stack.fst[733U] = 0U;
  rand_stack.fst[734U] = 0U;
  rand_stack.fst[735U] = 0U;
  rand_stack.fst[736U] = 0U;
  rand_stack.fst[737U] = 0U;
  rand_stack.fst[738U] = 0U;
  rand_stack.fst[739U] = 0U;
  rand_stack.fst[740U] = 0U;
  rand_stack.fst[741U] = 0U;
  rand_stack.fst[742U] = 0U;
  rand_stack.fst[743U] = 0U;
  rand_stack.fst[744U] = 0U;
  rand_stack.fst[745U] = 0U;
  rand_stack.fst[746U] = 0U;
  rand_stack.fst[747U] = 0U;
  rand_stack.fst[748U] = 0U;
  rand_stack.fst[749U] = 0U;
  rand_stack.fst[750U] = 0U;
  rand_stack.fst[751U] = 0U;
  rand_stack.fst[752U] = 0U;
  rand_stack.fst[753U] = 0U;
  rand_stack.fst[754U] = 0U;
  rand_stack.fst[755U] = 0U;
  rand_stack.fst[756U] = 0U;
  rand_stack.fst[757U] = 0U;
  rand_stack.fst[758U] = 0U;
  rand_stack.fst[759U] = 0U;
  rand_stack.fst[760U] = 0U;
  rand_stack.fst[761U] = 0U;
  rand_stack.fst[762U] = 0U;
  rand_stack.fst[763U] = 0U;
  rand_stack.fst[764U] = 0U;
  rand_stack.fst[765U] = 0U;
  rand_stack.fst[766U] = 0U;
  rand_stack.fst[767U] = 0U;
  rand_stack.fst[768U] = 0U;
  rand_stack.fst[769U] = 0U;
  rand_stack.fst[770U] = 0U;
  rand_stack.fst[771U] = 0U;
  rand_stack.fst[772U] = 0U;
  rand_stack.fst[773U] = 0U;
  rand_stack.fst[774U] = 0U;
  rand_stack.fst[775U] = 0U;
  rand_stack.fst[776U] = 0U;
  rand_stack.fst[777U] = 0U;
  rand_stack.fst[778U] = 0U;
  rand_stack.fst[779U] = 0U;
  rand_stack.fst[780U] = 0U;
  rand_stack.fst[781U] = 0U;
  rand_stack.fst[782U] = 0U;
  rand_stack.fst[783U] = 0U;
  rand_stack.fst[784U] = 0U;
  rand_stack.fst[785U] = 0U;
  rand_stack.fst[786U] = 0U;
  rand_stack.fst[787U] = 0U;
  rand_stack.fst[788U] = 0U;
  rand_stack.fst[789U] = 0U;
  rand_stack.fst[790U] = 0U;
  rand_stack.fst[791U] = 0U;
  rand_stack.fst[792U] = 0U;
  rand_stack.fst[793U] = 0U;
  rand_stack.fst[794U] = 0U;
  rand_stack.fst[795U] = 0U;
  rand_stack.fst[796U] = 0U;
  rand_stack.fst[797U] = 0U;
  rand_stack.fst[798U] = 0U;
  rand_stack.fst[799U] = 0U;
  rand_stack.fst[800U] = 0U;
  rand_stack.fst[801U] = 0U;
  rand_stack.fst[802U] = 0U;
  rand_stack.fst[803U] = 0U;
  rand_stack.fst[804U] = 0U;
  rand_stack.fst[805U] = 0U;
  rand_stack.fst[806U] = 0U;
  rand_stack.fst[807U] = 0U;
  rand_stack.fst[808U] = 0U;
  rand_stack.fst[809U] = 0U;
  rand_stack.fst[810U] = 0U;
  rand_stack.fst[811U] = 0U;
  rand_stack.fst[812U] = 0U;
  rand_stack.fst[813U] = 0U;
  rand_stack.fst[814U] = 0U;
  rand_stack.fst[815U] = 0U;
  rand_stack.fst[816U] = 0U;
  rand_stack.fst[817U] = 0U;
  rand_stack.fst[818U] = 0U;
  rand_stack.fst[819U] = 0U;
  rand_stack.fst[820U] = 0U;
  rand_stack.fst[821U] = 0U;
  rand_stack.fst[822U] = 0U;
  rand_stack.fst[823U] = 0U;
  rand_stack.fst[824U] = 0U;
  rand_stack.fst[825U] = 0U;
  rand_stack.fst[826U] = 0U;
  rand_stack.fst[827U] = 0U;
  rand_stack.fst[828U] = 0U;
  rand_stack.fst[829U] = 0U;
  rand_stack.fst[830U] = 0U;
  rand_stack.fst[831U] = 0U;
  rand_stack.fst[832U] = 0U;
  rand_stack.fst[833U] = 0U;
  rand_stack.fst[834U] = 0U;
  rand_stack.fst[835U] = 0U;
  rand_stack.fst[836U] = 0U;
  rand_stack.fst[837U] = 0U;
  rand_stack.fst[838U] = 0U;
  rand_stack.fst[839U] = 0U;
  memcpy(rand_stack.snd, uu____0, (size_t)840U * sizeof(uint8_t));
  memcpy(rand_stack.thd, uu____1, (size_t)840U * sizeof(uint8_t));
  rand_stack.f3[0U] = 0U;
  rand_stack.f3[1U] = 0U;
  rand_stack.f3[2U] = 0U;
  rand_stack.f3[3U] = 0U;
  rand_stack.f3[4U] = 0U;
  rand_stack.f3[5U] = 0U;
  rand_stack.f3[6U] = 0U;
  rand_stack.f3[7U] = 0U;
  rand_stack.f3[8U] = 0U;
  rand_stack.f3[9U] = 0U;
  rand_stack.f3[10U] = 0U;
  rand_stack.f3[11U] = 0U;
  rand_stack.f3[12U] = 0U;
  rand_stack.f3[13U] = 0U;
  rand_stack.f3[14U] = 0U;
  rand_stack.f3[15U] = 0U;
  rand_stack.f3[16U] = 0U;
  rand_stack.f3[17U] = 0U;
  rand_stack.f3[18U] = 0U;
  rand_stack.f3[19U] = 0U;
  rand_stack.f3[20U] = 0U;
  rand_stack.f3[21U] = 0U;
  rand_stack.f3[22U] = 0U;
  rand_stack.f3[23U] = 0U;
  rand_stack.f3[24U] = 0U;
  rand_stack.f3[25U] = 0U;
  rand_stack.f3[26U] = 0U;
  rand_stack.f3[27U] = 0U;
  rand_stack.f3[28U] = 0U;
  rand_stack.f3[29U] = 0U;
  rand_stack.f3[30U] = 0U;
  rand_stack.f3[31U] = 0U;
  rand_stack.f3[32U] = 0U;
  rand_stack.f3[33U] = 0U;
  rand_stack.f3[34U] = 0U;
  rand_stack.f3[35U] = 0U;
  rand_stack.f3[36U] = 0U;
  rand_stack.f3[37U] = 0U;
  rand_stack.f3[38U] = 0U;
  rand_stack.f3[39U] = 0U;
  rand_stack.f3[40U] = 0U;
  rand_stack.f3[41U] = 0U;
  rand_stack.f3[42U] = 0U;
  rand_stack.f3[43U] = 0U;
  rand_stack.f3[44U] = 0U;
  rand_stack.f3[45U] = 0U;
  rand_stack.f3[46U] = 0U;
  rand_stack.f3[47U] = 0U;
  rand_stack.f3[48U] = 0U;
  rand_stack.f3[49U] = 0U;
  rand_stack.f3[50U] = 0U;
  rand_stack.f3[51U] = 0U;
  rand_stack.f3[52U] = 0U;
  rand_stack.f3[53U] = 0U;
  rand_stack.f3[54U] = 0U;
  rand_stack.f3[55U] = 0U;
  rand_stack.f3[56U] = 0U;
  rand_stack.f3[57U] = 0U;
  rand_stack.f3[58U] = 0U;
  rand_stack.f3[59U] = 0U;
  rand_stack.f3[60U] = 0U;
  rand_stack.f3[61U] = 0U;
  rand_stack.f3[62U] = 0U;
  rand_stack.f3[63U] = 0U;
  rand_stack.f3[64U] = 0U;
  rand_stack.f3[65U] = 0U;
  rand_stack.f3[66U] = 0U;
  rand_stack.f3[67U] = 0U;
  rand_stack.f3[68U] = 0U;
  rand_stack.f3[69U] = 0U;
  rand_stack.f3[70U] = 0U;
  rand_stack.f3[71U] = 0U;
  rand_stack.f3[72U] = 0U;
  rand_stack.f3[73U] = 0U;
  rand_stack.f3[74U] = 0U;
  rand_stack.f3[75U] = 0U;
  rand_stack.f3[76U] = 0U;
  rand_stack.f3[77U] = 0U;
  rand_stack.f3[78U] = 0U;
  rand_stack.f3[79U] = 0U;
  rand_stack.f3[80U] = 0U;
  rand_stack.f3[81U] = 0U;
  rand_stack.f3[82U] = 0U;
  rand_stack.f3[83U] = 0U;
  rand_stack.f3[84U] = 0U;
  rand_stack.f3[85U] = 0U;
  rand_stack.f3[86U] = 0U;
  rand_stack.f3[87U] = 0U;
  rand_stack.f3[88U] = 0U;
  rand_stack.f3[89U] = 0U;
  rand_stack.f3[90U] = 0U;
  rand_stack.f3[91U] = 0U;
  rand_stack.f3[92U] = 0U;
  rand_stack.f3[93U] = 0U;
  rand_stack.f3[94U] = 0U;
  rand_stack.f3[95U] = 0U;
  rand_stack.f3[96U] = 0U;
  rand_stack.f3[97U] = 0U;
  rand_stack.f3[98U] = 0U;
  rand_stack.f3[99U] = 0U;
  rand_stack.f3[100U] = 0U;
  rand_stack.f3[101U] = 0U;
  rand_stack.f3[102U] = 0U;
  rand_stack.f3[103U] = 0U;
  rand_stack.f3[104U] = 0U;
  rand_stack.f3[105U] = 0U;
  rand_stack.f3[106U] = 0U;
  rand_stack.f3[107U] = 0U;
  rand_stack.f3[108U] = 0U;
  rand_stack.f3[109U] = 0U;
  rand_stack.f3[110U] = 0U;
  rand_stack.f3[111U] = 0U;
  rand_stack.f3[112U] = 0U;
  rand_stack.f3[113U] = 0U;
  rand_stack.f3[114U] = 0U;
  rand_stack.f3[115U] = 0U;
  rand_stack.f3[116U] = 0U;
  rand_stack.f3[117U] = 0U;
  rand_stack.f3[118U] = 0U;
  rand_stack.f3[119U] = 0U;
  rand_stack.f3[120U] = 0U;
  rand_stack.f3[121U] = 0U;
  rand_stack.f3[122U] = 0U;
  rand_stack.f3[123U] = 0U;
  rand_stack.f3[124U] = 0U;
  rand_stack.f3[125U] = 0U;
  rand_stack.f3[126U] = 0U;
  rand_stack.f3[127U] = 0U;
  rand_stack.f3[128U] = 0U;
  rand_stack.f3[129U] = 0U;
  rand_stack.f3[130U] = 0U;
  rand_stack.f3[131U] = 0U;
  rand_stack.f3[132U] = 0U;
  rand_stack.f3[133U] = 0U;
  rand_stack.f3[134U] = 0U;
  rand_stack.f3[135U] = 0U;
  rand_stack.f3[136U] = 0U;
  rand_stack.f3[137U] = 0U;
  rand_stack.f3[138U] = 0U;
  rand_stack.f3[139U] = 0U;
  rand_stack.f3[140U] = 0U;
  rand_stack.f3[141U] = 0U;
  rand_stack.f3[142U] = 0U;
  rand_stack.f3[143U] = 0U;
  rand_stack.f3[144U] = 0U;
  rand_stack.f3[145U] = 0U;
  rand_stack.f3[146U] = 0U;
  rand_stack.f3[147U] = 0U;
  rand_stack.f3[148U] = 0U;
  rand_stack.f3[149U] = 0U;
  rand_stack.f3[150U] = 0U;
  rand_stack.f3[151U] = 0U;
  rand_stack.f3[152U] = 0U;
  rand_stack.f3[153U] = 0U;
  rand_stack.f3[154U] = 0U;
  rand_stack.f3[155U] = 0U;
  rand_stack.f3[156U] = 0U;
  rand_stack.f3[157U] = 0U;
  rand_stack.f3[158U] = 0U;
  rand_stack.f3[159U] = 0U;
  rand_stack.f3[160U] = 0U;
  rand_stack.f3[161U] = 0U;
  rand_stack.f3[162U] = 0U;
  rand_stack.f3[163U] = 0U;
  rand_stack.f3[164U] = 0U;
  rand_stack.f3[165U] = 0U;
  rand_stack.f3[166U] = 0U;
  rand_stack.f3[167U] = 0U;
  rand_stack.f3[168U] = 0U;
  rand_stack.f3[169U] = 0U;
  rand_stack.f3[170U] = 0U;
  rand_stack.f3[171U] = 0U;
  rand_stack.f3[172U] = 0U;
  rand_stack.f3[173U] = 0U;
  rand_stack.f3[174U] = 0U;
  rand_stack.f3[175U] = 0U;
  rand_stack.f3[176U] = 0U;
  rand_stack.f3[177U] = 0U;
  rand_stack.f3[178U] = 0U;
  rand_stack.f3[179U] = 0U;
  rand_stack.f3[180U] = 0U;
  rand_stack.f3[181U] = 0U;
  rand_stack.f3[182U] = 0U;
  rand_stack.f3[183U] = 0U;
  rand_stack.f3[184U] = 0U;
  rand_stack.f3[185U] = 0U;
  rand_stack.f3[186U] = 0U;
  rand_stack.f3[187U] = 0U;
  rand_stack.f3[188U] = 0U;
  rand_stack.f3[189U] = 0U;
  rand_stack.f3[190U] = 0U;
  rand_stack.f3[191U] = 0U;
  rand_stack.f3[192U] = 0U;
  rand_stack.f3[193U] = 0U;
  rand_stack.f3[194U] = 0U;
  rand_stack.f3[195U] = 0U;
  rand_stack.f3[196U] = 0U;
  rand_stack.f3[197U] = 0U;
  rand_stack.f3[198U] = 0U;
  rand_stack.f3[199U] = 0U;
  rand_stack.f3[200U] = 0U;
  rand_stack.f3[201U] = 0U;
  rand_stack.f3[202U] = 0U;
  rand_stack.f3[203U] = 0U;
  rand_stack.f3[204U] = 0U;
  rand_stack.f3[205U] = 0U;
  rand_stack.f3[206U] = 0U;
  rand_stack.f3[207U] = 0U;
  rand_stack.f3[208U] = 0U;
  rand_stack.f3[209U] = 0U;
  rand_stack.f3[210U] = 0U;
  rand_stack.f3[211U] = 0U;
  rand_stack.f3[212U] = 0U;
  rand_stack.f3[213U] = 0U;
  rand_stack.f3[214U] = 0U;
  rand_stack.f3[215U] = 0U;
  rand_stack.f3[216U] = 0U;
  rand_stack.f3[217U] = 0U;
  rand_stack.f3[218U] = 0U;
  rand_stack.f3[219U] = 0U;
  rand_stack.f3[220U] = 0U;
  rand_stack.f3[221U] = 0U;
  rand_stack.f3[222U] = 0U;
  rand_stack.f3[223U] = 0U;
  rand_stack.f3[224U] = 0U;
  rand_stack.f3[225U] = 0U;
  rand_stack.f3[226U] = 0U;
  rand_stack.f3[227U] = 0U;
  rand_stack.f3[228U] = 0U;
  rand_stack.f3[229U] = 0U;
  rand_stack.f3[230U] = 0U;
  rand_stack.f3[231U] = 0U;
  rand_stack.f3[232U] = 0U;
  rand_stack.f3[233U] = 0U;
  rand_stack.f3[234U] = 0U;
  rand_stack.f3[235U] = 0U;
  rand_stack.f3[236U] = 0U;
  rand_stack.f3[237U] = 0U;
  rand_stack.f3[238U] = 0U;
  rand_stack.f3[239U] = 0U;
  rand_stack.f3[240U] = 0U;
  rand_stack.f3[241U] = 0U;
  rand_stack.f3[242U] = 0U;
  rand_stack.f3[243U] = 0U;
  rand_stack.f3[244U] = 0U;
  rand_stack.f3[245U] = 0U;
  rand_stack.f3[246U] = 0U;
  rand_stack.f3[247U] = 0U;
  rand_stack.f3[248U] = 0U;
  rand_stack.f3[249U] = 0U;
  rand_stack.f3[250U] = 0U;
  rand_stack.f3[251U] = 0U;
  rand_stack.f3[252U] = 0U;
  rand_stack.f3[253U] = 0U;
  rand_stack.f3[254U] = 0U;
  rand_stack.f3[255U] = 0U;
  rand_stack.f3[256U] = 0U;
  rand_stack.f3[257U] = 0U;
  rand_stack.f3[258U] = 0U;
  rand_stack.f3[259U] = 0U;
  rand_stack.f3[260U] = 0U;
  rand_stack.f3[261U] = 0U;
  rand_stack.f3[262U] = 0U;
  rand_stack.f3[263U] = 0U;
  rand_stack.f3[264U] = 0U;
  rand_stack.f3[265U] = 0U;
  rand_stack.f3[266U] = 0U;
  rand_stack.f3[267U] = 0U;
  rand_stack.f3[268U] = 0U;
  rand_stack.f3[269U] = 0U;
  rand_stack.f3[270U] = 0U;
  rand_stack.f3[271U] = 0U;
  rand_stack.f3[272U] = 0U;
  rand_stack.f3[273U] = 0U;
  rand_stack.f3[274U] = 0U;
  rand_stack.f3[275U] = 0U;
  rand_stack.f3[276U] = 0U;
  rand_stack.f3[277U] = 0U;
  rand_stack.f3[278U] = 0U;
  rand_stack.f3[279U] = 0U;
  rand_stack.f3[280U] = 0U;
  rand_stack.f3[281U] = 0U;
  rand_stack.f3[282U] = 0U;
  rand_stack.f3[283U] = 0U;
  rand_stack.f3[284U] = 0U;
  rand_stack.f3[285U] = 0U;
  rand_stack.f3[286U] = 0U;
  rand_stack.f3[287U] = 0U;
  rand_stack.f3[288U] = 0U;
  rand_stack.f3[289U] = 0U;
  rand_stack.f3[290U] = 0U;
  rand_stack.f3[291U] = 0U;
  rand_stack.f3[292U] = 0U;
  rand_stack.f3[293U] = 0U;
  rand_stack.f3[294U] = 0U;
  rand_stack.f3[295U] = 0U;
  rand_stack.f3[296U] = 0U;
  rand_stack.f3[297U] = 0U;
  rand_stack.f3[298U] = 0U;
  rand_stack.f3[299U] = 0U;
  rand_stack.f3[300U] = 0U;
  rand_stack.f3[301U] = 0U;
  rand_stack.f3[302U] = 0U;
  rand_stack.f3[303U] = 0U;
  rand_stack.f3[304U] = 0U;
  rand_stack.f3[305U] = 0U;
  rand_stack.f3[306U] = 0U;
  rand_stack.f3[307U] = 0U;
  rand_stack.f3[308U] = 0U;
  rand_stack.f3[309U] = 0U;
  rand_stack.f3[310U] = 0U;
  rand_stack.f3[311U] = 0U;
  rand_stack.f3[312U] = 0U;
  rand_stack.f3[313U] = 0U;
  rand_stack.f3[314U] = 0U;
  rand_stack.f3[315U] = 0U;
  rand_stack.f3[316U] = 0U;
  rand_stack.f3[317U] = 0U;
  rand_stack.f3[318U] = 0U;
  rand_stack.f3[319U] = 0U;
  rand_stack.f3[320U] = 0U;
  rand_stack.f3[321U] = 0U;
  rand_stack.f3[322U] = 0U;
  rand_stack.f3[323U] = 0U;
  rand_stack.f3[324U] = 0U;
  rand_stack.f3[325U] = 0U;
  rand_stack.f3[326U] = 0U;
  rand_stack.f3[327U] = 0U;
  rand_stack.f3[328U] = 0U;
  rand_stack.f3[329U] = 0U;
  rand_stack.f3[330U] = 0U;
  rand_stack.f3[331U] = 0U;
  rand_stack.f3[332U] = 0U;
  rand_stack.f3[333U] = 0U;
  rand_stack.f3[334U] = 0U;
  rand_stack.f3[335U] = 0U;
  rand_stack.f3[336U] = 0U;
  rand_stack.f3[337U] = 0U;
  rand_stack.f3[338U] = 0U;
  rand_stack.f3[339U] = 0U;
  rand_stack.f3[340U] = 0U;
  rand_stack.f3[341U] = 0U;
  rand_stack.f3[342U] = 0U;
  rand_stack.f3[343U] = 0U;
  rand_stack.f3[344U] = 0U;
  rand_stack.f3[345U] = 0U;
  rand_stack.f3[346U] = 0U;
  rand_stack.f3[347U] = 0U;
  rand_stack.f3[348U] = 0U;
  rand_stack.f3[349U] = 0U;
  rand_stack.f3[350U] = 0U;
  rand_stack.f3[351U] = 0U;
  rand_stack.f3[352U] = 0U;
  rand_stack.f3[353U] = 0U;
  rand_stack.f3[354U] = 0U;
  rand_stack.f3[355U] = 0U;
  rand_stack.f3[356U] = 0U;
  rand_stack.f3[357U] = 0U;
  rand_stack.f3[358U] = 0U;
  rand_stack.f3[359U] = 0U;
  rand_stack.f3[360U] = 0U;
  rand_stack.f3[361U] = 0U;
  rand_stack.f3[362U] = 0U;
  rand_stack.f3[363U] = 0U;
  rand_stack.f3[364U] = 0U;
  rand_stack.f3[365U] = 0U;
  rand_stack.f3[366U] = 0U;
  rand_stack.f3[367U] = 0U;
  rand_stack.f3[368U] = 0U;
  rand_stack.f3[369U] = 0U;
  rand_stack.f3[370U] = 0U;
  rand_stack.f3[371U] = 0U;
  rand_stack.f3[372U] = 0U;
  rand_stack.f3[373U] = 0U;
  rand_stack.f3[374U] = 0U;
  rand_stack.f3[375U] = 0U;
  rand_stack.f3[376U] = 0U;
  rand_stack.f3[377U] = 0U;
  rand_stack.f3[378U] = 0U;
  rand_stack.f3[379U] = 0U;
  rand_stack.f3[380U] = 0U;
  rand_stack.f3[381U] = 0U;
  rand_stack.f3[382U] = 0U;
  rand_stack.f3[383U] = 0U;
  rand_stack.f3[384U] = 0U;
  rand_stack.f3[385U] = 0U;
  rand_stack.f3[386U] = 0U;
  rand_stack.f3[387U] = 0U;
  rand_stack.f3[388U] = 0U;
  rand_stack.f3[389U] = 0U;
  rand_stack.f3[390U] = 0U;
  rand_stack.f3[391U] = 0U;
  rand_stack.f3[392U] = 0U;
  rand_stack.f3[393U] = 0U;
  rand_stack.f3[394U] = 0U;
  rand_stack.f3[395U] = 0U;
  rand_stack.f3[396U] = 0U;
  rand_stack.f3[397U] = 0U;
  rand_stack.f3[398U] = 0U;
  rand_stack.f3[399U] = 0U;
  rand_stack.f3[400U] = 0U;
  rand_stack.f3[401U] = 0U;
  rand_stack.f3[402U] = 0U;
  rand_stack.f3[403U] = 0U;
  rand_stack.f3[404U] = 0U;
  rand_stack.f3[405U] = 0U;
  rand_stack.f3[406U] = 0U;
  rand_stack.f3[407U] = 0U;
  rand_stack.f3[408U] = 0U;
  rand_stack.f3[409U] = 0U;
  rand_stack.f3[410U] = 0U;
  rand_stack.f3[411U] = 0U;
  rand_stack.f3[412U] = 0U;
  rand_stack.f3[413U] = 0U;
  rand_stack.f3[414U] = 0U;
  rand_stack.f3[415U] = 0U;
  rand_stack.f3[416U] = 0U;
  rand_stack.f3[417U] = 0U;
  rand_stack.f3[418U] = 0U;
  rand_stack.f3[419U] = 0U;
  rand_stack.f3[420U] = 0U;
  rand_stack.f3[421U] = 0U;
  rand_stack.f3[422U] = 0U;
  rand_stack.f3[423U] = 0U;
  rand_stack.f3[424U] = 0U;
  rand_stack.f3[425U] = 0U;
  rand_stack.f3[426U] = 0U;
  rand_stack.f3[427U] = 0U;
  rand_stack.f3[428U] = 0U;
  rand_stack.f3[429U] = 0U;
  rand_stack.f3[430U] = 0U;
  rand_stack.f3[431U] = 0U;
  rand_stack.f3[432U] = 0U;
  rand_stack.f3[433U] = 0U;
  rand_stack.f3[434U] = 0U;
  rand_stack.f3[435U] = 0U;
  rand_stack.f3[436U] = 0U;
  rand_stack.f3[437U] = 0U;
  rand_stack.f3[438U] = 0U;
  rand_stack.f3[439U] = 0U;
  rand_stack.f3[440U] = 0U;
  rand_stack.f3[441U] = 0U;
  rand_stack.f3[442U] = 0U;
  rand_stack.f3[443U] = 0U;
  rand_stack.f3[444U] = 0U;
  rand_stack.f3[445U] = 0U;
  rand_stack.f3[446U] = 0U;
  rand_stack.f3[447U] = 0U;
  rand_stack.f3[448U] = 0U;
  rand_stack.f3[449U] = 0U;
  rand_stack.f3[450U] = 0U;
  rand_stack.f3[451U] = 0U;
  rand_stack.f3[452U] = 0U;
  rand_stack.f3[453U] = 0U;
  rand_stack.f3[454U] = 0U;
  rand_stack.f3[455U] = 0U;
  rand_stack.f3[456U] = 0U;
  rand_stack.f3[457U] = 0U;
  rand_stack.f3[458U] = 0U;
  rand_stack.f3[459U] = 0U;
  rand_stack.f3[460U] = 0U;
  rand_stack.f3[461U] = 0U;
  rand_stack.f3[462U] = 0U;
  rand_stack.f3[463U] = 0U;
  rand_stack.f3[464U] = 0U;
  rand_stack.f3[465U] = 0U;
  rand_stack.f3[466U] = 0U;
  rand_stack.f3[467U] = 0U;
  rand_stack.f3[468U] = 0U;
  rand_stack.f3[469U] = 0U;
  rand_stack.f3[470U] = 0U;
  rand_stack.f3[471U] = 0U;
  rand_stack.f3[472U] = 0U;
  rand_stack.f3[473U] = 0U;
  rand_stack.f3[474U] = 0U;
  rand_stack.f3[475U] = 0U;
  rand_stack.f3[476U] = 0U;
  rand_stack.f3[477U] = 0U;
  rand_stack.f3[478U] = 0U;
  rand_stack.f3[479U] = 0U;
  rand_stack.f3[480U] = 0U;
  rand_stack.f3[481U] = 0U;
  rand_stack.f3[482U] = 0U;
  rand_stack.f3[483U] = 0U;
  rand_stack.f3[484U] = 0U;
  rand_stack.f3[485U] = 0U;
  rand_stack.f3[486U] = 0U;
  rand_stack.f3[487U] = 0U;
  rand_stack.f3[488U] = 0U;
  rand_stack.f3[489U] = 0U;
  rand_stack.f3[490U] = 0U;
  rand_stack.f3[491U] = 0U;
  rand_stack.f3[492U] = 0U;
  rand_stack.f3[493U] = 0U;
  rand_stack.f3[494U] = 0U;
  rand_stack.f3[495U] = 0U;
  rand_stack.f3[496U] = 0U;
  rand_stack.f3[497U] = 0U;
  rand_stack.f3[498U] = 0U;
  rand_stack.f3[499U] = 0U;
  rand_stack.f3[500U] = 0U;
  rand_stack.f3[501U] = 0U;
  rand_stack.f3[502U] = 0U;
  rand_stack.f3[503U] = 0U;
  rand_stack.f3[504U] = 0U;
  rand_stack.f3[505U] = 0U;
  rand_stack.f3[506U] = 0U;
  rand_stack.f3[507U] = 0U;
  rand_stack.f3[508U] = 0U;
  rand_stack.f3[509U] = 0U;
  rand_stack.f3[510U] = 0U;
  rand_stack.f3[511U] = 0U;
  rand_stack.f3[512U] = 0U;
  rand_stack.f3[513U] = 0U;
  rand_stack.f3[514U] = 0U;
  rand_stack.f3[515U] = 0U;
  rand_stack.f3[516U] = 0U;
  rand_stack.f3[517U] = 0U;
  rand_stack.f3[518U] = 0U;
  rand_stack.f3[519U] = 0U;
  rand_stack.f3[520U] = 0U;
  rand_stack.f3[521U] = 0U;
  rand_stack.f3[522U] = 0U;
  rand_stack.f3[523U] = 0U;
  rand_stack.f3[524U] = 0U;
  rand_stack.f3[525U] = 0U;
  rand_stack.f3[526U] = 0U;
  rand_stack.f3[527U] = 0U;
  rand_stack.f3[528U] = 0U;
  rand_stack.f3[529U] = 0U;
  rand_stack.f3[530U] = 0U;
  rand_stack.f3[531U] = 0U;
  rand_stack.f3[532U] = 0U;
  rand_stack.f3[533U] = 0U;
  rand_stack.f3[534U] = 0U;
  rand_stack.f3[535U] = 0U;
  rand_stack.f3[536U] = 0U;
  rand_stack.f3[537U] = 0U;
  rand_stack.f3[538U] = 0U;
  rand_stack.f3[539U] = 0U;
  rand_stack.f3[540U] = 0U;
  rand_stack.f3[541U] = 0U;
  rand_stack.f3[542U] = 0U;
  rand_stack.f3[543U] = 0U;
  rand_stack.f3[544U] = 0U;
  rand_stack.f3[545U] = 0U;
  rand_stack.f3[546U] = 0U;
  rand_stack.f3[547U] = 0U;
  rand_stack.f3[548U] = 0U;
  rand_stack.f3[549U] = 0U;
  rand_stack.f3[550U] = 0U;
  rand_stack.f3[551U] = 0U;
  rand_stack.f3[552U] = 0U;
  rand_stack.f3[553U] = 0U;
  rand_stack.f3[554U] = 0U;
  rand_stack.f3[555U] = 0U;
  rand_stack.f3[556U] = 0U;
  rand_stack.f3[557U] = 0U;
  rand_stack.f3[558U] = 0U;
  rand_stack.f3[559U] = 0U;
  rand_stack.f3[560U] = 0U;
  rand_stack.f3[561U] = 0U;
  rand_stack.f3[562U] = 0U;
  rand_stack.f3[563U] = 0U;
  rand_stack.f3[564U] = 0U;
  rand_stack.f3[565U] = 0U;
  rand_stack.f3[566U] = 0U;
  rand_stack.f3[567U] = 0U;
  rand_stack.f3[568U] = 0U;
  rand_stack.f3[569U] = 0U;
  rand_stack.f3[570U] = 0U;
  rand_stack.f3[571U] = 0U;
  rand_stack.f3[572U] = 0U;
  rand_stack.f3[573U] = 0U;
  rand_stack.f3[574U] = 0U;
  rand_stack.f3[575U] = 0U;
  rand_stack.f3[576U] = 0U;
  rand_stack.f3[577U] = 0U;
  rand_stack.f3[578U] = 0U;
  rand_stack.f3[579U] = 0U;
  rand_stack.f3[580U] = 0U;
  rand_stack.f3[581U] = 0U;
  rand_stack.f3[582U] = 0U;
  rand_stack.f3[583U] = 0U;
  rand_stack.f3[584U] = 0U;
  rand_stack.f3[585U] = 0U;
  rand_stack.f3[586U] = 0U;
  rand_stack.f3[587U] = 0U;
  rand_stack.f3[588U] = 0U;
  rand_stack.f3[589U] = 0U;
  rand_stack.f3[590U] = 0U;
  rand_stack.f3[591U] = 0U;
  rand_stack.f3[592U] = 0U;
  rand_stack.f3[593U] = 0U;
  rand_stack.f3[594U] = 0U;
  rand_stack.f3[595U] = 0U;
  rand_stack.f3[596U] = 0U;
  rand_stack.f3[597U] = 0U;
  rand_stack.f3[598U] = 0U;
  rand_stack.f3[599U] = 0U;
  rand_stack.f3[600U] = 0U;
  rand_stack.f3[601U] = 0U;
  rand_stack.f3[602U] = 0U;
  rand_stack.f3[603U] = 0U;
  rand_stack.f3[604U] = 0U;
  rand_stack.f3[605U] = 0U;
  rand_stack.f3[606U] = 0U;
  rand_stack.f3[607U] = 0U;
  rand_stack.f3[608U] = 0U;
  rand_stack.f3[609U] = 0U;
  rand_stack.f3[610U] = 0U;
  rand_stack.f3[611U] = 0U;
  rand_stack.f3[612U] = 0U;
  rand_stack.f3[613U] = 0U;
  rand_stack.f3[614U] = 0U;
  rand_stack.f3[615U] = 0U;
  rand_stack.f3[616U] = 0U;
  rand_stack.f3[617U] = 0U;
  rand_stack.f3[618U] = 0U;
  rand_stack.f3[619U] = 0U;
  rand_stack.f3[620U] = 0U;
  rand_stack.f3[621U] = 0U;
  rand_stack.f3[622U] = 0U;
  rand_stack.f3[623U] = 0U;
  rand_stack.f3[624U] = 0U;
  rand_stack.f3[625U] = 0U;
  rand_stack.f3[626U] = 0U;
  rand_stack.f3[627U] = 0U;
  rand_stack.f3[628U] = 0U;
  rand_stack.f3[629U] = 0U;
  rand_stack.f3[630U] = 0U;
  rand_stack.f3[631U] = 0U;
  rand_stack.f3[632U] = 0U;
  rand_stack.f3[633U] = 0U;
  rand_stack.f3[634U] = 0U;
  rand_stack.f3[635U] = 0U;
  rand_stack.f3[636U] = 0U;
  rand_stack.f3[637U] = 0U;
  rand_stack.f3[638U] = 0U;
  rand_stack.f3[639U] = 0U;
  rand_stack.f3[640U] = 0U;
  rand_stack.f3[641U] = 0U;
  rand_stack.f3[642U] = 0U;
  rand_stack.f3[643U] = 0U;
  rand_stack.f3[644U] = 0U;
  rand_stack.f3[645U] = 0U;
  rand_stack.f3[646U] = 0U;
  rand_stack.f3[647U] = 0U;
  rand_stack.f3[648U] = 0U;
  rand_stack.f3[649U] = 0U;
  rand_stack.f3[650U] = 0U;
  rand_stack.f3[651U] = 0U;
  rand_stack.f3[652U] = 0U;
  rand_stack.f3[653U] = 0U;
  rand_stack.f3[654U] = 0U;
  rand_stack.f3[655U] = 0U;
  rand_stack.f3[656U] = 0U;
  rand_stack.f3[657U] = 0U;
  rand_stack.f3[658U] = 0U;
  rand_stack.f3[659U] = 0U;
  rand_stack.f3[660U] = 0U;
  rand_stack.f3[661U] = 0U;
  rand_stack.f3[662U] = 0U;
  rand_stack.f3[663U] = 0U;
  rand_stack.f3[664U] = 0U;
  rand_stack.f3[665U] = 0U;
  rand_stack.f3[666U] = 0U;
  rand_stack.f3[667U] = 0U;
  rand_stack.f3[668U] = 0U;
  rand_stack.f3[669U] = 0U;
  rand_stack.f3[670U] = 0U;
  rand_stack.f3[671U] = 0U;
  rand_stack.f3[672U] = 0U;
  rand_stack.f3[673U] = 0U;
  rand_stack.f3[674U] = 0U;
  rand_stack.f3[675U] = 0U;
  rand_stack.f3[676U] = 0U;
  rand_stack.f3[677U] = 0U;
  rand_stack.f3[678U] = 0U;
  rand_stack.f3[679U] = 0U;
  rand_stack.f3[680U] = 0U;
  rand_stack.f3[681U] = 0U;
  rand_stack.f3[682U] = 0U;
  rand_stack.f3[683U] = 0U;
  rand_stack.f3[684U] = 0U;
  rand_stack.f3[685U] = 0U;
  rand_stack.f3[686U] = 0U;
  rand_stack.f3[687U] = 0U;
  rand_stack.f3[688U] = 0U;
  rand_stack.f3[689U] = 0U;
  rand_stack.f3[690U] = 0U;
  rand_stack.f3[691U] = 0U;
  rand_stack.f3[692U] = 0U;
  rand_stack.f3[693U] = 0U;
  rand_stack.f3[694U] = 0U;
  rand_stack.f3[695U] = 0U;
  rand_stack.f3[696U] = 0U;
  rand_stack.f3[697U] = 0U;
  rand_stack.f3[698U] = 0U;
  rand_stack.f3[699U] = 0U;
  rand_stack.f3[700U] = 0U;
  rand_stack.f3[701U] = 0U;
  rand_stack.f3[702U] = 0U;
  rand_stack.f3[703U] = 0U;
  rand_stack.f3[704U] = 0U;
  rand_stack.f3[705U] = 0U;
  rand_stack.f3[706U] = 0U;
  rand_stack.f3[707U] = 0U;
  rand_stack.f3[708U] = 0U;
  rand_stack.f3[709U] = 0U;
  rand_stack.f3[710U] = 0U;
  rand_stack.f3[711U] = 0U;
  rand_stack.f3[712U] = 0U;
  rand_stack.f3[713U] = 0U;
  rand_stack.f3[714U] = 0U;
  rand_stack.f3[715U] = 0U;
  rand_stack.f3[716U] = 0U;
  rand_stack.f3[717U] = 0U;
  rand_stack.f3[718U] = 0U;
  rand_stack.f3[719U] = 0U;
  rand_stack.f3[720U] = 0U;
  rand_stack.f3[721U] = 0U;
  rand_stack.f3[722U] = 0U;
  rand_stack.f3[723U] = 0U;
  rand_stack.f3[724U] = 0U;
  rand_stack.f3[725U] = 0U;
  rand_stack.f3[726U] = 0U;
  rand_stack.f3[727U] = 0U;
  rand_stack.f3[728U] = 0U;
  rand_stack.f3[729U] = 0U;
  rand_stack.f3[730U] = 0U;
  rand_stack.f3[731U] = 0U;
  rand_stack.f3[732U] = 0U;
  rand_stack.f3[733U] = 0U;
  rand_stack.f3[734U] = 0U;
  rand_stack.f3[735U] = 0U;
  rand_stack.f3[736U] = 0U;
  rand_stack.f3[737U] = 0U;
  rand_stack.f3[738U] = 0U;
  rand_stack.f3[739U] = 0U;
  rand_stack.f3[740U] = 0U;
  rand_stack.f3[741U] = 0U;
  rand_stack.f3[742U] = 0U;
  rand_stack.f3[743U] = 0U;
  rand_stack.f3[744U] = 0U;
  rand_stack.f3[745U] = 0U;
  rand_stack.f3[746U] = 0U;
  rand_stack.f3[747U] = 0U;
  rand_stack.f3[748U] = 0U;
  rand_stack.f3[749U] = 0U;
  rand_stack.f3[750U] = 0U;
  rand_stack.f3[751U] = 0U;
  rand_stack.f3[752U] = 0U;
  rand_stack.f3[753U] = 0U;
  rand_stack.f3[754U] = 0U;
  rand_stack.f3[755U] = 0U;
  rand_stack.f3[756U] = 0U;
  rand_stack.f3[757U] = 0U;
  rand_stack.f3[758U] = 0U;
  rand_stack.f3[759U] = 0U;
  rand_stack.f3[760U] = 0U;
  rand_stack.f3[761U] = 0U;
  rand_stack.f3[762U] = 0U;
  rand_stack.f3[763U] = 0U;
  rand_stack.f3[764U] = 0U;
  rand_stack.f3[765U] = 0U;
  rand_stack.f3[766U] = 0U;
  rand_stack.f3[767U] = 0U;
  rand_stack.f3[768U] = 0U;
  rand_stack.f3[769U] = 0U;
  rand_stack.f3[770U] = 0U;
  rand_stack.f3[771U] = 0U;
  rand_stack.f3[772U] = 0U;
  rand_stack.f3[773U] = 0U;
  rand_stack.f3[774U] = 0U;
  rand_stack.f3[775U] = 0U;
  rand_stack.f3[776U] = 0U;
  rand_stack.f3[777U] = 0U;
  rand_stack.f3[778U] = 0U;
  rand_stack.f3[779U] = 0U;
  rand_stack.f3[780U] = 0U;
  rand_stack.f3[781U] = 0U;
  rand_stack.f3[782U] = 0U;
  rand_stack.f3[783U] = 0U;
  rand_stack.f3[784U] = 0U;
  rand_stack.f3[785U] = 0U;
  rand_stack.f3[786U] = 0U;
  rand_stack.f3[787U] = 0U;
  rand_stack.f3[788U] = 0U;
  rand_stack.f3[789U] = 0U;
  rand_stack.f3[790U] = 0U;
  rand_stack.f3[791U] = 0U;
  rand_stack.f3[792U] = 0U;
  rand_stack.f3[793U] = 0U;
  rand_stack.f3[794U] = 0U;
  rand_stack.f3[795U] = 0U;
  rand_stack.f3[796U] = 0U;
  rand_stack.f3[797U] = 0U;
  rand_stack.f3[798U] = 0U;
  rand_stack.f3[799U] = 0U;
  rand_stack.f3[800U] = 0U;
  rand_stack.f3[801U] = 0U;
  rand_stack.f3[802U] = 0U;
  rand_stack.f3[803U] = 0U;
  rand_stack.f3[804U] = 0U;
  rand_stack.f3[805U] = 0U;
  rand_stack.f3[806U] = 0U;
  rand_stack.f3[807U] = 0U;
  rand_stack.f3[808U] = 0U;
  rand_stack.f3[809U] = 0U;
  rand_stack.f3[810U] = 0U;
  rand_stack.f3[811U] = 0U;
  rand_stack.f3[812U] = 0U;
  rand_stack.f3[813U] = 0U;
  rand_stack.f3[814U] = 0U;
  rand_stack.f3[815U] = 0U;
  rand_stack.f3[816U] = 0U;
  rand_stack.f3[817U] = 0U;
  rand_stack.f3[818U] = 0U;
  rand_stack.f3[819U] = 0U;
  rand_stack.f3[820U] = 0U;
  rand_stack.f3[821U] = 0U;
  rand_stack.f3[822U] = 0U;
  rand_stack.f3[823U] = 0U;
  rand_stack.f3[824U] = 0U;
  rand_stack.f3[825U] = 0U;
  rand_stack.f3[826U] = 0U;
  rand_stack.f3[827U] = 0U;
  rand_stack.f3[828U] = 0U;
  rand_stack.f3[829U] = 0U;
  rand_stack.f3[830U] = 0U;
  rand_stack.f3[831U] = 0U;
  rand_stack.f3[832U] = 0U;
  rand_stack.f3[833U] = 0U;
  rand_stack.f3[834U] = 0U;
  rand_stack.f3[835U] = 0U;
  rand_stack.f3[836U] = 0U;
  rand_stack.f3[837U] = 0U;
  rand_stack.f3[838U] = 0U;
  rand_stack.f3[839U] = 0U;
  int32_t tmp_stack[4U][263U] = {{0U}};
  size_t_x2 buf0[0U] = {};
  libcrux_ml_dsa_sample_SampleArgs_4e memory = libcrux_ml_dsa_sample_new_29_ab(
      &rand_stack,
      Eurydice_array_to_slice((size_t)4U, tmp_stack, int32_t[263U]), A,
      Eurydice_array_to_slice((size_t)0U, buf0, size_t_x2));
  size_t_x2 buf[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)0U, .snd = (size_t)0U}),
      (CLITERAL(size_t_x2){.fst = (size_t)0U, .snd = (size_t)1U}),
      (CLITERAL(size_t_x2){.fst = (size_t)0U, .snd = (size_t)2U}),
      (CLITERAL(size_t_x2){.fst = (size_t)0U, .snd = (size_t)3U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf, size_t_x2);
  uint8_t uu____2[34U];
  memcpy(uu____2, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____2,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 0U, .snd = 0U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 0U, .snd = 1U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 0U, .snd = 2U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 0U, .snd = 3U})),
      &memory);
  size_t_x2 buf1[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)0U, .snd = (size_t)4U}),
      (CLITERAL(size_t_x2){.fst = (size_t)1U, .snd = (size_t)0U}),
      (CLITERAL(size_t_x2){.fst = (size_t)1U, .snd = (size_t)1U}),
      (CLITERAL(size_t_x2){.fst = (size_t)1U, .snd = (size_t)2U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf1, size_t_x2);
  uint8_t uu____3[34U];
  memcpy(uu____3, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____3,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 0U, .snd = 4U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 1U, .snd = 0U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 1U, .snd = 1U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 1U, .snd = 2U})),
      &memory);
  size_t_x2 buf2[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)1U, .snd = (size_t)3U}),
      (CLITERAL(size_t_x2){.fst = (size_t)1U, .snd = (size_t)4U}),
      (CLITERAL(size_t_x2){.fst = (size_t)2U, .snd = (size_t)0U}),
      (CLITERAL(size_t_x2){.fst = (size_t)2U, .snd = (size_t)1U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf2, size_t_x2);
  uint8_t uu____4[34U];
  memcpy(uu____4, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____4,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 1U, .snd = 3U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 1U, .snd = 4U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 2U, .snd = 0U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 2U, .snd = 1U})),
      &memory);
  size_t_x2 buf3[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)2U, .snd = (size_t)2U}),
      (CLITERAL(size_t_x2){.fst = (size_t)2U, .snd = (size_t)3U}),
      (CLITERAL(size_t_x2){.fst = (size_t)2U, .snd = (size_t)4U}),
      (CLITERAL(size_t_x2){.fst = (size_t)3U, .snd = (size_t)0U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf3, size_t_x2);
  uint8_t uu____5[34U];
  memcpy(uu____5, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____5,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 2U, .snd = 2U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 2U, .snd = 3U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 2U, .snd = 4U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 3U, .snd = 0U})),
      &memory);
  size_t_x2 buf4[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)3U, .snd = (size_t)1U}),
      (CLITERAL(size_t_x2){.fst = (size_t)3U, .snd = (size_t)2U}),
      (CLITERAL(size_t_x2){.fst = (size_t)3U, .snd = (size_t)3U}),
      (CLITERAL(size_t_x2){.fst = (size_t)3U, .snd = (size_t)4U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf4, size_t_x2);
  uint8_t uu____6[34U];
  memcpy(uu____6, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____6,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 3U, .snd = 1U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 3U, .snd = 2U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 3U, .snd = 3U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 3U, .snd = 4U})),
      &memory);
  size_t_x2 buf5[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)4U, .snd = (size_t)0U}),
      (CLITERAL(size_t_x2){.fst = (size_t)4U, .snd = (size_t)1U}),
      (CLITERAL(size_t_x2){.fst = (size_t)4U, .snd = (size_t)2U}),
      (CLITERAL(size_t_x2){.fst = (size_t)4U, .snd = (size_t)3U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf5, size_t_x2);
  uint8_t uu____7[34U];
  memcpy(uu____7, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____7,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 4U, .snd = 0U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 4U, .snd = 1U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 4U, .snd = 2U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 4U, .snd = 3U})),
      &memory);
  size_t_x2 buf6[4U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)4U, .snd = (size_t)4U}),
      (CLITERAL(size_t_x2){.fst = (size_t)5U, .snd = (size_t)0U}),
      (CLITERAL(size_t_x2){.fst = (size_t)5U, .snd = (size_t)1U}),
      (CLITERAL(size_t_x2){.fst = (size_t)5U, .snd = (size_t)2U})};
  memory.indices = Eurydice_array_to_slice((size_t)4U, buf6, size_t_x2);
  uint8_t uu____8[34U];
  memcpy(uu____8, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____8,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 4U, .snd = 4U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 0U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 1U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 2U})),
      &memory);
  size_t_x2 buf7[2U] = {
      (CLITERAL(size_t_x2){.fst = (size_t)5U, .snd = (size_t)3U}),
      (CLITERAL(size_t_x2){.fst = (size_t)5U, .snd = (size_t)4U})};
  memory.indices = Eurydice_array_to_slice((size_t)2U, buf7, size_t_x2);
  uint8_t uu____9[34U];
  memcpy(uu____9, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_sample_sample_four_ring_elements_49(
      uu____9,
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 3U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 4U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 5U})),
      libcrux_ml_dsa_samplex4_generate_domain_separator(
          (CLITERAL(uint8_t_x2){.fst = 5U, .snd = 6U})),
      &memory);
  memcpy(ret, A,
         (size_t)6U *
             sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]));
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.matrix_A_generic
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake128X4 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static inline void libcrux_ml_dsa_samplex4_matrix_A_generic_49(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U][5U]) {
  uint8_t_x2 uu____0 = {.fst = (uint8_t)(size_t)6U, .snd = (uint8_t)(size_t)5U};
  switch (uu____0.fst) {
    case 6U: {
      switch (uu____0.snd) {
        case 5U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[34U];
          memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
          libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret0[6U][5U];
          libcrux_ml_dsa_samplex4_matrix_A_6_by_5_49(copy_of_seed, ret0);
          memcpy(
              ret, ret0,
              (size_t)6U *
                  sizeof(
                      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]));
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
This function found in impl {(libcrux_ml_dsa::samplex4::X4Sampler for
libcrux_ml_dsa::samplex4::portable::PortableSampler)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.samplex4.portable.matrix_A_36
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_samplex4_portable_matrix_A_36_2f(
    uint8_t seed[34U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U][5U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed[34U];
  memcpy(copy_of_seed, seed, (size_t)34U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret0[6U][5U];
  libcrux_ml_dsa_samplex4_matrix_A_generic_49(copy_of_seed, ret0);
  memcpy(ret, ret0,
         (size_t)6U *
             sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]));
}

/**
A monomorphic instance of K.
with types libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[5size_t],
libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[6size_t]

*/
typedef struct tuple_ce_s {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b fst[5U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b snd[6U];
} tuple_ce;

typedef struct
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4_s {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b fst;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b snd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b thd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b f3;
} libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4;

/**
A monomorphic instance of
libcrux_ml_dsa.sample.rejection_sample_less_than_eta_equals_2 with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics

*/
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_eta_equals_2_ba(
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
          libcrux_ml_dsa_simd_portable_rejection_sample_less_than_eta_equals_2_36(
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
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics

*/
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_eta_equals_4_ba(
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
          libcrux_ml_dsa_simd_portable_rejection_sample_less_than_eta_equals_4_36(
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
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ETA= 4
*/
static KRML_MUSTINLINE bool
libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
    Eurydice_slice randomness, size_t *sampled, int32_t *out) {
  return libcrux_ml_dsa_sample_rejection_sample_less_than_eta_equals_4_ba(
      randomness, sampled, out);
}

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.from_i32_array_ff
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(Eurydice_slice array) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result =
      libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  for (size_t i = (size_t)0U;
       i < LIBCRUX_ML_DSA_SIMD_TRAITS_SIMD_UNITS_IN_RING_ELEMENT; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_from_coefficient_array_36(
            Eurydice_slice_subslice2(
                array,
                i0 * LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT,
                (i0 + (size_t)1U) *
                    LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT,
                int32_t));
    result.simd_units[i0] = uu____0;
  }
  return result;
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_four_error_ring_elements
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
- ETA= 4
*/
static KRML_MUSTINLINE
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4
    libcrux_ml_dsa_sample_sample_four_error_ring_elements_92(
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
  libcrux_ml_dsa_hash_functions_portable_Shake256X4 state =
      libcrux_ml_dsa_hash_functions_portable_init_absorb_x4_50(
          Eurydice_array_to_slice((size_t)66U, seed0, uint8_t),
          Eurydice_array_to_slice((size_t)66U, seed1, uint8_t),
          Eurydice_array_to_slice((size_t)66U, seed2, uint8_t),
          Eurydice_array_to_slice((size_t)66U, seed3, uint8_t));
  uint8_t_136size_t__x4 randomnesses0 =
      libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_x4_50(&state);
  int32_t out0[263U] = {0U};
  int32_t out1[263U] = {0U};
  int32_t out2[263U] = {0U};
  int32_t out3[263U] = {0U};
  size_t sampled0 = (size_t)0U;
  size_t sampled1 = (size_t)0U;
  size_t sampled2 = (size_t)0U;
  size_t sampled3 = (size_t)0U;
  bool done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.fst, uint8_t),
      &sampled0, out0);
  bool done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.snd, uint8_t),
      &sampled1, out1);
  bool done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
      Eurydice_array_to_slice((size_t)136U, randomnesses0.thd, uint8_t),
      &sampled2, out2);
  bool done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
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
                libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4_50(
                    &state);
            if (!done0) {
              done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.fst,
                                          uint8_t),
                  &sampled0, out0);
            }
            if (!done1) {
              done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.snd,
                                          uint8_t),
                  &sampled1, out1);
            }
            if (!done2) {
              done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.thd,
                                          uint8_t),
                  &sampled2, out2);
            }
            if (!done3) {
              done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                  Eurydice_array_to_slice((size_t)136U, randomnesses.f3,
                                          uint8_t),
                  &sampled3, out3);
            }
          }
        } else {
          uint8_t_136size_t__x4 randomnesses =
              libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4_50(
                  &state);
          if (!done0) {
            done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                Eurydice_array_to_slice((size_t)136U, randomnesses.fst,
                                        uint8_t),
                &sampled0, out0);
          }
          if (!done1) {
            done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                Eurydice_array_to_slice((size_t)136U, randomnesses.snd,
                                        uint8_t),
                &sampled1, out1);
          }
          if (!done2) {
            done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                Eurydice_array_to_slice((size_t)136U, randomnesses.thd,
                                        uint8_t),
                &sampled2, out2);
          }
          if (!done3) {
            done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
                Eurydice_array_to_slice((size_t)136U, randomnesses.f3, uint8_t),
                &sampled3, out3);
          }
        }
      } else {
        uint8_t_136size_t__x4 randomnesses =
            libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4_50(
                &state);
        if (!done0) {
          done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
              Eurydice_array_to_slice((size_t)136U, randomnesses.fst, uint8_t),
              &sampled0, out0);
        }
        if (!done1) {
          done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
              Eurydice_array_to_slice((size_t)136U, randomnesses.snd, uint8_t),
              &sampled1, out1);
        }
        if (!done2) {
          done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
              Eurydice_array_to_slice((size_t)136U, randomnesses.thd, uint8_t),
              &sampled2, out2);
        }
        if (!done3) {
          done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
              Eurydice_array_to_slice((size_t)136U, randomnesses.f3, uint8_t),
              &sampled3, out3);
        }
      }
    } else {
      uint8_t_136size_t__x4 randomnesses =
          libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_x4_50(
              &state);
      if (!done0) {
        done0 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
            Eurydice_array_to_slice((size_t)136U, randomnesses.fst, uint8_t),
            &sampled0, out0);
      }
      if (!done1) {
        done1 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
            Eurydice_array_to_slice((size_t)136U, randomnesses.snd, uint8_t),
            &sampled1, out1);
      }
      if (!done2) {
        done2 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
            Eurydice_array_to_slice((size_t)136U, randomnesses.thd, uint8_t),
            &sampled2, out2);
      }
      if (!done3) {
        done3 = libcrux_ml_dsa_sample_rejection_sample_less_than_eta_73(
            Eurydice_array_to_slice((size_t)136U, randomnesses.f3, uint8_t),
            &sampled3, out3);
      }
    }
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(
          Eurydice_array_to_slice((size_t)263U, out0, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____1 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(
          Eurydice_array_to_slice((size_t)263U, out1, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____2 =
      libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(
          Eurydice_array_to_slice((size_t)263U, out2, int32_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4
      lit;
  lit.fst = uu____0;
  lit.snd = uu____1;
  lit.thd = uu____2;
  lit.f3 = libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(
      Eurydice_array_to_slice((size_t)263U, out3, int32_t));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.sample_s1_and_s2_5_by_6
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
- ETA= 4
- S1_DIMENSION= 5
- S2_DIMENSION= 6
*/
static KRML_MUSTINLINE tuple_ce
libcrux_ml_dsa_samplex4_sample_s1_and_s2_5_by_6_fe(uint8_t seed_base[66U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s1[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    s1[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s2[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    s2[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base[66U];
  memcpy(copy_of_seed_base, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4
      four = libcrux_ml_dsa_sample_sample_four_error_ring_elements_92(
          copy_of_seed_base, 0U, 1U, 2U, 3U);
  s1[0U] = four.fst;
  s1[1U] = four.snd;
  s1[2U] = four.thd;
  s1[3U] = four.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base0[66U];
  memcpy(copy_of_seed_base0, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4
      four0 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_92(
          copy_of_seed_base0, 4U, 5U, 6U, 7U);
  s1[4U] = four0.fst;
  s2[0U] = four0.snd;
  s2[1U] = four0.thd;
  s2[2U] = four0.f3;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed_base1[66U];
  memcpy(copy_of_seed_base1, seed_base, (size_t)66U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x4
      four1 = libcrux_ml_dsa_sample_sample_four_error_ring_elements_92(
          copy_of_seed_base1, 8U, 9U, 10U, 11U);
  s2[3U] = four1.fst;
  s2[4U] = four1.snd;
  s2[5U] = four1.thd;
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s2[6U];
  memcpy(
      copy_of_s2, s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  tuple_ce lit;
  memcpy(
      lit.fst, copy_of_s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  memcpy(
      lit.snd, copy_of_s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.samplex4.sample_s1_and_s2
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
- ETA= 4
- S1_DIMENSION= 5
- S2_DIMENSION= 6
*/
static KRML_MUSTINLINE tuple_ce
libcrux_ml_dsa_samplex4_sample_s1_and_s2_fe(uint8_t seed[66U]) {
  uint8_t_x2 uu____0 = {.fst = (uint8_t)(size_t)5U, .snd = (uint8_t)(size_t)6U};
  switch (uu____0.fst) {
    case 5U: {
      switch (uu____0.snd) {
        case 6U: {
          /* Passing arrays by value in Rust generates a copy in C */
          uint8_t copy_of_seed[66U];
          memcpy(copy_of_seed, seed, (size_t)66U * sizeof(uint8_t));
          return libcrux_ml_dsa_samplex4_sample_s1_and_s2_5_by_6_fe(
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
A monomorphic instance of libcrux_ml_dsa.ntt.ntt
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_ntt_ntt_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0[32U];
  memcpy(uu____0, re.simd_units,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b lit;
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret[32U];
  libcrux_ml_dsa_simd_portable_ntt_36(uu____0, ret);
  memcpy(lit.simd_units, ret,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.compute_As1_plus_s2.closure
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_matrix_compute_As1_plus_s2_closure_2f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s) {
  return libcrux_ml_dsa_ntt_ntt_ba(s);
}

/**
A monomorphic instance of libcrux_ml_dsa.ntt.ntt_multiply_montgomery
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *lhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *rhs) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b out =
      libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, out.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_montgomery_multiply_36(
            lhs->simd_units[i0], rhs->simd_units[i0]);
    out.simd_units[i0] = uu____0;
  }
  return out;
}

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.add_ff
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_polynomial_add_ff_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *self,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *rhs) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b sum =
      libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, sum.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_add_36(&self->simd_units[i0],
                                            &rhs->simd_units[i0]);
    sum.simd_units[i0] = uu____0;
  }
  return sum;
}

/**
A monomorphic instance of libcrux_ml_dsa.ntt.invert_ntt_montgomery
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_ntt_invert_ntt_montgomery_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0[32U];
  memcpy(uu____0, re.simd_units,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b lit;
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit ret[32U];
  libcrux_ml_dsa_simd_portable_invert_ntt_montgomery_36(uu____0, ret);
  memcpy(lit.simd_units, ret,
         (size_t)32U *
             sizeof(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit));
  return lit;
}

/**
 Compute InvertNTT(Â ◦ ŝ₁) + s₂
*/
/**
A monomorphic instance of libcrux_ml_dsa.matrix.compute_As1_plus_s2
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_compute_As1_plus_s2_2f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b (*A_as_ntt)[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *s1,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *s2,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s1_ntt[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    s1_ntt[i] =
        libcrux_ml_dsa_matrix_compute_As1_plus_s2_closure_2f(copy_of_s1[i]);
  }
  for (size_t i0 = (size_t)0U;
       i0 < Eurydice_slice_len(
                Eurydice_array_to_slice(
                    (size_t)6U, A_as_ntt,
                    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]),
                libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]);
       i0++) {
    size_t i1 = i0;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *row = A_as_ntt[i1];
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)5U, row,
                     libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
                 libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
         i++) {
      size_t j = i;
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
          &row[j];
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b product =
          libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(ring_element,
                                                        &s1_ntt[j]);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____1 =
          libcrux_ml_dsa_polynomial_add_ff_ba(&result[i1], &product);
      result[i1] = uu____1;
    }
    result[i1] = libcrux_ml_dsa_ntt_invert_ntt_montgomery_ba(result[i1]);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____3 =
        libcrux_ml_dsa_polynomial_add_ff_ba(&result[i1], &s2[i1]);
    result[i1] = uu____3;
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

typedef struct
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2_s {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b fst[6U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b snd[6U];
} libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2;

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.power2round_vector
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
*/
static KRML_MUSTINLINE
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2
    libcrux_ml_dsa_arithmetic_power2round_vector_07(
        libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t0[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    t0[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    t1[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i0 = (size_t)0U;
       i0 < Eurydice_slice_len(
                Eurydice_array_to_slice(
                    (size_t)6U, t,
                    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
                libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i0++) {
    size_t i1 = i0;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element = &t[i1];
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)32U, ring_element->simd_units,
                     libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
                 libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
         i++) {
      size_t j = i;
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
          &ring_element->simd_units[j];
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2 uu____0 =
          libcrux_ml_dsa_simd_portable_power2round_36(simd_unit[0U]);
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t0_unit =
          uu____0.fst;
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit t1_unit =
          uu____0.snd;
      t0[i1].simd_units[j] = t0_unit;
      t1[i1].simd_units[j] = t1_unit;
    }
  }
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t0[6U];
  memcpy(
      copy_of_t0, t0,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t1[6U];
  memcpy(
      copy_of_t1, t1,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2
      lit;
  memcpy(
      lit.fst, copy_of_t0,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  memcpy(
      lit.snd, copy_of_t1,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.t1.serialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_t1_serialize_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re, uint8_t ret[320U]) {
  uint8_t serialized[320U] = {0U};
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &re.simd_units[i0];
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        serialized,
        i0 * LIBCRUX_ML_DSA_ENCODING_T1_SERIALIZE_OUTPUT_BYTES_PER_SIMD_UNIT,
        (i0 + (size_t)1U) *
            LIBCRUX_ML_DSA_ENCODING_T1_SERIALIZE_OUTPUT_BYTES_PER_SIMD_UNIT,
        uint8_t);
    uint8_t ret0[10U];
    libcrux_ml_dsa_simd_portable_t1_serialize_36(simd_unit[0U], ret0);
    Eurydice_slice_copy(
        uu____0, Eurydice_array_to_slice((size_t)10U, ret0, uint8_t), uint8_t);
  }
  memcpy(ret, serialized, (size_t)320U * sizeof(uint8_t));
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.verification_key.generate_serialized with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics
- ROWS_IN_A= 6
- VERIFICATION_KEY_SIZE= 1952
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_verification_key_generate_serialized_2f(
    Eurydice_slice seed_for_A,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1[6U],
    uint8_t ret[1952U]) {
  uint8_t verification_key_serialized[1952U] = {0U};
  Eurydice_slice_copy(Eurydice_array_to_subslice2(
                          verification_key_serialized, (size_t)0U,
                          LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE, uint8_t),
                      seed_for_A, uint8_t);
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, t1,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element = &t1[i0];
    size_t offset = LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE +
                    i0 * LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T1S_SIZE;
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        verification_key_serialized, offset,
        offset + LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T1S_SIZE, uint8_t);
    uint8_t ret0[320U];
    libcrux_ml_dsa_encoding_t1_serialize_ba(ring_element[0U], ret0);
    Eurydice_slice_copy(
        uu____0, Eurydice_array_to_slice((size_t)320U, ret0, uint8_t), uint8_t);
  }
  memcpy(ret, verification_key_serialized, (size_t)1952U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256
with const generics
- OUTPUT_LENGTH= 64
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_hash_functions_portable_shake256_24(
    Eurydice_slice input, uint8_t *out) {
  libcrux_sha3_portable_shake256(
      Eurydice_array_to_slice((size_t)64U, out, uint8_t), input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::portable::Shake256)#2}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256_5c
with const generics
- OUTPUT_LENGTH= 64
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_shake256_5c_24(Eurydice_slice input,
                                                      uint8_t *out) {
  libcrux_ml_dsa_hash_functions_portable_shake256_24(input, out);
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.encoding.error.serialize
with const generics
- ETA= 4
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_error_serialize_ac(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_encoding_error_serialize_when_eta_is_4(
      simd_unit, serialized);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.error_serialize_36
with const generics
- ETA= 4
*/
static inline void libcrux_ml_dsa_simd_portable_error_serialize_36_ac(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_encoding_error_serialize_ac(simd_unit,
                                                           serialized);
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.error.serialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ETA= 4
- OUTPUT_SIZE= 128
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_error_serialize_ea(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re,
    Eurydice_slice serialized) {
  size_t output_bytes_per_simd_unit;
  output_bytes_per_simd_unit = (size_t)4U;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &re.simd_units[i0];
    libcrux_ml_dsa_simd_portable_error_serialize_36_ac(
        simd_unit[0U],
        Eurydice_slice_subslice2(serialized, i0 * output_bytes_per_simd_unit,
                                 (i0 + (size_t)1U) * output_bytes_per_simd_unit,
                                 uint8_t));
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.t0.serialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_t0_serialize_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &re.simd_units[i0];
    Eurydice_slice uu____0 = Eurydice_slice_subslice2(
        serialized, i0 * LIBCRUX_ML_DSA_ENCODING_T0_OUTPUT_BYTES_PER_SIMD_UNIT,
        (i0 + (size_t)1U) *
            LIBCRUX_ML_DSA_ENCODING_T0_OUTPUT_BYTES_PER_SIMD_UNIT,
        uint8_t);
    uint8_t ret[13U];
    libcrux_ml_dsa_simd_portable_t0_serialize_36(simd_unit[0U], ret);
    Eurydice_slice_copy(
        uu____0, Eurydice_array_to_slice((size_t)13U, ret, uint8_t), uint8_t);
  }
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.signing_key.generate_serialized with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_signing_key_generate_serialized_d2(
    Eurydice_slice seed_for_A, Eurydice_slice seed_for_signing,
    Eurydice_slice verification_key,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s1[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s2[6U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t0[6U],
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
  libcrux_ml_dsa_hash_functions_portable_shake256_5c_24(verification_key,
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
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t _cloop_j = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
        &s1[_cloop_j];
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____1 =
        ring_element[0U];
    libcrux_ml_dsa_encoding_error_serialize_ea(
        uu____1, Eurydice_array_to_subslice2(signing_key_serialized, offset,
                                             offset + (size_t)128U, uint8_t));
    offset = offset + (size_t)128U;
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, s2,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t _cloop_j = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
        &s2[_cloop_j];
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____2 =
        ring_element[0U];
    libcrux_ml_dsa_encoding_error_serialize_ea(
        uu____2, Eurydice_array_to_subslice2(signing_key_serialized, offset,
                                             offset + (size_t)128U, uint8_t));
    offset = offset + (size_t)128U;
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, t0,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t _cloop_j = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
        &t0[_cloop_j];
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____3 =
        ring_element[0U];
    libcrux_ml_dsa_encoding_t0_serialize_ba(
        uu____3, Eurydice_array_to_subslice2(
                     signing_key_serialized, offset,
                     offset + LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE,
                     uint8_t));
    offset = offset + LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE;
  }
  memcpy(ret, signing_key_serialized, (size_t)4032U * sizeof(uint8_t));
}

/**
 Generate a key pair.
*/
/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.generate_key_pair
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
- VERIFICATION_KEY_SIZE= 1952
*/
static KRML_MUSTINLINE tuple_a0
libcrux_ml_dsa_ml_dsa_generic_generate_key_pair_c3(uint8_t randomness[32U]) {
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
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b a_as_ntt[6U][5U];
  uint8_t ret[34U];
  libcrux_ml_dsa_utils_into_padded_array_b6(seed_for_a, ret);
  libcrux_ml_dsa_samplex4_portable_matrix_A_36_2f(ret, a_as_ntt);
  uint8_t ret0[66U];
  libcrux_ml_dsa_utils_into_padded_array_20(seed_for_error_vectors, ret0);
  tuple_ce uu____2 = libcrux_ml_dsa_samplex4_sample_s1_and_s2_fe(ret0);
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s1[5U];
  memcpy(
      s1, uu____2.fst,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s2[6U];
  memcpy(
      s2, uu____2.snd,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t[6U];
  libcrux_ml_dsa_matrix_compute_As1_plus_s2_2f(a_as_ntt, s1, s2, t);
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t[6U];
  memcpy(
      copy_of_t, t,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2
      uu____4 = libcrux_ml_dsa_arithmetic_power2round_vector_07(copy_of_t);
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t0[6U];
  memcpy(
      t0, uu____4.fst,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1[6U];
  memcpy(
      t1, uu____4.snd,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  Eurydice_slice uu____5 = seed_for_a;
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t1[6U];
  memcpy(
      copy_of_t1, t1,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  uint8_t verification_key_serialized[1952U];
  libcrux_ml_dsa_encoding_verification_key_generate_serialized_2f(
      uu____5, copy_of_t1, verification_key_serialized);
  Eurydice_slice uu____7 = seed_for_a;
  Eurydice_slice uu____8 = seed_for_signing;
  Eurydice_slice uu____9 = Eurydice_array_to_slice(
      (size_t)1952U, verification_key_serialized, uint8_t);
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s1[5U];
  memcpy(
      copy_of_s1, s1,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s2[6U];
  memcpy(
      copy_of_s2, s2,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t0[6U];
  memcpy(
      copy_of_t0, t0,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  uint8_t signing_key_serialized[4032U];
  libcrux_ml_dsa_encoding_signing_key_generate_serialized_d2(
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
libcrux_ml_dsa.ml_dsa_generic.instantiations.portable.generate_key_pair with
const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
- VERIFICATION_KEY_SIZE= 1952
*/
static inline tuple_a0
libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_generate_key_pair_52(
    uint8_t randomness[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_generate_key_pair_c3(copy_of_randomness);
}

/**
 Generate an ML-DSA-65 Key Pair
*/
static inline libcrux_ml_dsa_ml_dsa_65_MLDSA65KeyPair
libcrux_ml_dsa_ml_dsa_65_portable_generate_key_pair(uint8_t randomness[32U]) {
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  tuple_a0 uu____1 =
      libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_generate_key_pair_52(
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
A monomorphic instance of K.
with types int32_t[256size_t][6size_t], size_t

*/
typedef struct tuple_e6_s {
  int32_t fst[6U][256U];
  size_t snd;
} tuple_e6;

/**
A monomorphic instance of core.option.Option
with types libcrux_ml_dsa_pre_hash_DomainSeparationContext

*/
typedef struct Option_84_s {
  Option_08_tags tag;
  libcrux_ml_dsa_pre_hash_DomainSeparationContext f0;
} Option_84;

/**
A monomorphic instance of K.
with types uint8_t[32size_t], uint8_t[32size_t], uint8_t[64size_t],
libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[5size_t],
libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[6size_t],
libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[6size_t]

*/
typedef struct tuple_f0_s {
  uint8_t fst[32U];
  uint8_t snd[32U];
  uint8_t thd[64U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b f3[5U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b f4[6U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b f5[6U];
} tuple_f0;

/**
A monomorphic instance of
libcrux_ml_dsa.simd.portable.encoding.error.deserialize with const generics
- ETA= 4
*/
static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_error_deserialize_ac(
    Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_portable_encoding_error_deserialize_when_eta_is_4(
      serialized);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.error_deserialize_36
with const generics
- ETA= 4
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_error_deserialize_36_ac(
    Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_portable_encoding_error_deserialize_ac(serialized);
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.error.deserialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ETA= 4
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_error_deserialize_73(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *result) {
  size_t chunk_size;
  chunk_size = (size_t)4U;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, result->simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_error_deserialize_36_ac(
            Eurydice_slice_subslice2(serialized, i0 * chunk_size,
                                     (i0 + (size_t)1U) * chunk_size, uint8_t));
    result->simd_units[i0] = uu____0;
  }
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.error.deserialize_to_vector_then_ntt with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics
- DIMENSION= 5
- ETA= 4
- RING_ELEMENT_SIZE= 128
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_error_deserialize_to_vector_then_ntt_76(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ring_elements[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    ring_elements[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(serialized, uint8_t) / (size_t)128U; i++) {
    size_t i0 = i;
    Eurydice_slice bytes =
        Eurydice_slice_subslice2(serialized, i0 * (size_t)128U,
                                 i0 * (size_t)128U + (size_t)128U, uint8_t);
    libcrux_ml_dsa_encoding_error_deserialize_73(bytes, &ring_elements[i0]);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_ntt_ntt_ba(ring_elements[i0]);
    ring_elements[i0] = uu____0;
  }
  memcpy(
      ret, ring_elements,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.error.deserialize_to_vector_then_ntt with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics
- DIMENSION= 6
- ETA= 4
- RING_ELEMENT_SIZE= 128
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_error_deserialize_to_vector_then_ntt_5d(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ring_elements[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    ring_elements[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(serialized, uint8_t) / (size_t)128U; i++) {
    size_t i0 = i;
    Eurydice_slice bytes =
        Eurydice_slice_subslice2(serialized, i0 * (size_t)128U,
                                 i0 * (size_t)128U + (size_t)128U, uint8_t);
    libcrux_ml_dsa_encoding_error_deserialize_73(bytes, &ring_elements[i0]);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_ntt_ntt_ba(ring_elements[i0]);
    ring_elements[i0] = uu____0;
  }
  memcpy(
      ret, ring_elements,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.t0.deserialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_t0_deserialize_ba(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *result) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, result->simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_t0_deserialize_36(Eurydice_slice_subslice2(
            serialized,
            i0 * LIBCRUX_ML_DSA_ENCODING_T0_OUTPUT_BYTES_PER_SIMD_UNIT,
            (i0 + (size_t)1U) *
                LIBCRUX_ML_DSA_ENCODING_T0_OUTPUT_BYTES_PER_SIMD_UNIT,
            uint8_t));
    result->simd_units[i0] = uu____0;
  }
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.t0.deserialize_to_vector_then_ntt with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics
- DIMENSION= 6
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_t0_deserialize_to_vector_then_ntt_07(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ring_elements[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    ring_elements[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(serialized, uint8_t) /
               LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE;
       i++) {
    size_t i0 = i;
    Eurydice_slice bytes = Eurydice_slice_subslice2(
        serialized, i0 * LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE,
        i0 * LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE +
            LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T0S_SIZE,
        uint8_t);
    libcrux_ml_dsa_encoding_t0_deserialize_ba(bytes, &ring_elements[i0]);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_ntt_ntt_ba(ring_elements[i0]);
    ring_elements[i0] = uu____0;
  }
  memcpy(
      ret, ring_elements,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of
libcrux_ml_dsa.encoding.signing_key.deserialize_then_ntt with types
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
- ETA= 4
- ERROR_RING_ELEMENT_SIZE= 128
- SIGNING_KEY_SIZE= 4032
*/
static KRML_MUSTINLINE tuple_f0
libcrux_ml_dsa_encoding_signing_key_deserialize_then_ntt_c6(
    uint8_t *serialized) {
  Eurydice_slice_uint8_t_x2 uu____0 = Eurydice_slice_split_at(
      Eurydice_array_to_slice((size_t)4032U, serialized, uint8_t),
      LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE, uint8_t,
      Eurydice_slice_uint8_t_x2);
  Eurydice_slice seed_for_A = uu____0.fst;
  Eurydice_slice remaining_serialized0 = uu____0.snd;
  Eurydice_slice_uint8_t_x2 uu____1 = Eurydice_slice_split_at(
      remaining_serialized0, LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_SIGNING_SIZE,
      uint8_t, Eurydice_slice_uint8_t_x2);
  Eurydice_slice seed_for_signing = uu____1.fst;
  Eurydice_slice remaining_serialized1 = uu____1.snd;
  Eurydice_slice_uint8_t_x2 uu____2 = Eurydice_slice_split_at(
      remaining_serialized1,
      LIBCRUX_ML_DSA_CONSTANTS_BYTES_FOR_VERIFICATION_KEY_HASH, uint8_t,
      Eurydice_slice_uint8_t_x2);
  Eurydice_slice verification_key_hash = uu____2.fst;
  Eurydice_slice remaining_serialized2 = uu____2.snd;
  Eurydice_slice_uint8_t_x2 uu____3 =
      Eurydice_slice_split_at(remaining_serialized2, (size_t)128U * (size_t)5U,
                              uint8_t, Eurydice_slice_uint8_t_x2);
  Eurydice_slice s1_serialized = uu____3.fst;
  Eurydice_slice remaining_serialized = uu____3.snd;
  Eurydice_slice_uint8_t_x2 uu____4 =
      Eurydice_slice_split_at(remaining_serialized, (size_t)128U * (size_t)6U,
                              uint8_t, Eurydice_slice_uint8_t_x2);
  Eurydice_slice s2_serialized = uu____4.fst;
  Eurydice_slice t0_serialized = uu____4.snd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s1_as_ntt[5U];
  libcrux_ml_dsa_encoding_error_deserialize_to_vector_then_ntt_76(s1_serialized,
                                                                  s1_as_ntt);
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s2_as_ntt[6U];
  libcrux_ml_dsa_encoding_error_deserialize_to_vector_then_ntt_5d(s2_serialized,
                                                                  s2_as_ntt);
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t0_as_ntt[6U];
  libcrux_ml_dsa_encoding_t0_deserialize_to_vector_then_ntt_07(t0_serialized,
                                                               t0_as_ntt);
  uint8_t uu____5[32U];
  Result_fb dst0;
  Eurydice_slice_to_array2(&dst0, seed_for_A, Eurydice_slice, uint8_t[32U]);
  unwrap_26_b3(dst0, uu____5);
  uint8_t uu____6[32U];
  Result_fb dst1;
  Eurydice_slice_to_array2(&dst1, seed_for_signing, Eurydice_slice,
                           uint8_t[32U]);
  unwrap_26_b3(dst1, uu____6);
  uint8_t uu____7[64U];
  Result_f2 dst;
  Eurydice_slice_to_array2(&dst, verification_key_hash, Eurydice_slice,
                           uint8_t[64U]);
  unwrap_26_4b(dst, uu____7);
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s1_as_ntt[5U];
  memcpy(
      copy_of_s1_as_ntt, s1_as_ntt,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_s2_as_ntt[6U];
  memcpy(
      copy_of_s2_as_ntt, s2_as_ntt,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t0_as_ntt[6U];
  memcpy(
      copy_of_t0_as_ntt, t0_as_ntt,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  tuple_f0 lit;
  memcpy(lit.fst, uu____5, (size_t)32U * sizeof(uint8_t));
  memcpy(lit.snd, uu____6, (size_t)32U * sizeof(uint8_t));
  memcpy(lit.thd, uu____7, (size_t)64U * sizeof(uint8_t));
  memcpy(
      lit.f3, copy_of_s1_as_ntt,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  memcpy(
      lit.f4, copy_of_s2_as_ntt,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  memcpy(
      lit.f5, copy_of_t0_as_ntt,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  return lit;
}

/**
 This corresponds to line 6 in algorithm 7 in FIPS 204 (line 7 in algorithm
 8, resp.).

 If `domain_separation_context` is supplied, applies domain
 separation and length encoding to the context string,
 before appending the message (in the regular variant) or the
 pre-hash OID as well as the pre-hashed message digest. Otherwise,
 it is assumed that `message` already contains domain separation
 information.

 In FIPS 204 M' is the concatenation of the domain separated context, any
 potential pre-hash OID and the message (or the message pre-hash). We do not
 explicitely construct the concatenation in memory since it is of statically
 unknown length, but feed its components directly into the incremental XOF.

 Refer to line 10 of Algorithm 2 (and line 5 of Algorithm 3, resp.) in [FIPS
 204](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.204.pdf#section.5)
 for details on the domain separation for regular ML-DSA. Line
 23 of Algorithm 4 (and line 18 of Algorithm 5,resp.) describe domain separation
 for the HashMl-DSA variant.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.derive_message_representative with types
libcrux_ml_dsa_hash_functions_portable_Shake256Xof with const generics

*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_ml_dsa_generic_derive_message_representative_7b(
    uint8_t verification_key_hash[64U], Option_84 domain_separation_context,
    Eurydice_slice message, uint8_t *message_representative) {
  libcrux_sha3_portable_incremental_Shake256Xof shake =
      libcrux_ml_dsa_hash_functions_portable_init_83();
  libcrux_ml_dsa_hash_functions_portable_absorb_83(
      &shake,
      Eurydice_array_to_slice((size_t)64U, verification_key_hash, uint8_t));
  if (domain_separation_context.tag == Some) {
    libcrux_ml_dsa_pre_hash_DomainSeparationContext domain_separation_context0 =
        domain_separation_context.f0;
    libcrux_sha3_portable_incremental_Shake256Xof *uu____0 = &shake;
    uint8_t buf0[1U] = {
        (uint8_t)core_option__core__option__Option_T__TraitClause_0___is_some(
            libcrux_ml_dsa_pre_hash_pre_hash_oid_45(
                &domain_separation_context0),
            uint8_t[11U], bool)};
    libcrux_ml_dsa_hash_functions_portable_absorb_83(
        uu____0, Eurydice_array_to_slice((size_t)1U, buf0, uint8_t));
    libcrux_sha3_portable_incremental_Shake256Xof *uu____1 = &shake;
    uint8_t buf[1U] = {(uint8_t)Eurydice_slice_len(
        libcrux_ml_dsa_pre_hash_context_45(&domain_separation_context0),
        uint8_t)};
    libcrux_ml_dsa_hash_functions_portable_absorb_83(
        uu____1, Eurydice_array_to_slice((size_t)1U, buf, uint8_t));
    libcrux_ml_dsa_hash_functions_portable_absorb_83(
        &shake,
        libcrux_ml_dsa_pre_hash_context_45(&domain_separation_context0));
    Option_30 *uu____2 =
        libcrux_ml_dsa_pre_hash_pre_hash_oid_45(&domain_separation_context0);
    if (uu____2->tag == Some) {
      uint8_t *pre_hash_oid = uu____2->f0;
      libcrux_ml_dsa_hash_functions_portable_absorb_83(
          &shake, Eurydice_array_to_slice((size_t)11U, pre_hash_oid, uint8_t));
    }
  }
  libcrux_ml_dsa_hash_functions_portable_absorb_final_83(&shake, message);
  libcrux_ml_dsa_hash_functions_portable_squeeze_83(
      &shake,
      Eurydice_array_to_slice((size_t)64U, message_representative, uint8_t));
}

/**
A monomorphic instance of core.option.Option
with types libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[5size_t]

*/
typedef struct Option_f3_s {
  Option_08_tags tag;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b f0[5U];
} Option_f3;

/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256
with const generics
- OUTPUT_LENGTH= 576
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_hash_functions_portable_shake256_1b(
    Eurydice_slice input, uint8_t *out) {
  libcrux_sha3_portable_shake256(
      Eurydice_array_to_slice((size_t)576U, out, uint8_t), input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake256X4)#3}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256_x4_50
with const generics
- OUT_LEN= 576
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_shake256_x4_50_1b(
    Eurydice_slice input0, Eurydice_slice input1, Eurydice_slice input2,
    Eurydice_slice input3, uint8_t *out0, uint8_t *out1, uint8_t *out2,
    uint8_t *out3) {
  libcrux_ml_dsa_hash_functions_portable_shake256_1b(input0, out0);
  libcrux_ml_dsa_hash_functions_portable_shake256_1b(input1, out1);
  libcrux_ml_dsa_hash_functions_portable_shake256_1b(input2, out2);
  libcrux_ml_dsa_hash_functions_portable_shake256_1b(input3, out3);
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.portable.encoding.gamma1.deserialize with const generics
- GAMMA1_EXPONENT= 19
*/
static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_encoding_gamma1_deserialize_36(
    Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_portable_encoding_gamma1_deserialize_when_gamma1_is_2_pow_19(
      serialized);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.gamma1_deserialize_36
with const generics
- GAMMA1_EXPONENT= 19
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_gamma1_deserialize_36_36(
    Eurydice_slice serialized) {
  return libcrux_ml_dsa_simd_portable_encoding_gamma1_deserialize_36(
      serialized);
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.gamma1.deserialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- GAMMA1_EXPONENT= 19
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_gamma1_deserialize_61(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *result) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, result->simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_gamma1_deserialize_36_36(
            Eurydice_slice_subslice2(
                serialized, i0 * ((size_t)19U + (size_t)1U),
                (i0 + (size_t)1U) * ((size_t)19U + (size_t)1U), uint8_t));
    result->simd_units[i0] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256
with const generics
- OUTPUT_LENGTH= 640
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_hash_functions_portable_shake256_c8(
    Eurydice_slice input, uint8_t *out) {
  libcrux_sha3_portable_shake256(
      Eurydice_array_to_slice((size_t)640U, out, uint8_t), input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::XofX4
for libcrux_ml_dsa::hash_functions::portable::Shake256X4)#3}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256_x4_50
with const generics
- OUT_LEN= 640
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_shake256_x4_50_c8(
    Eurydice_slice input0, Eurydice_slice input1, Eurydice_slice input2,
    Eurydice_slice input3, uint8_t *out0, uint8_t *out1, uint8_t *out2,
    uint8_t *out3) {
  libcrux_ml_dsa_hash_functions_portable_shake256_c8(input0, out0);
  libcrux_ml_dsa_hash_functions_portable_shake256_c8(input1, out1);
  libcrux_ml_dsa_hash_functions_portable_shake256_c8(input2, out2);
  libcrux_ml_dsa_hash_functions_portable_shake256_c8(input3, out3);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::portable::Shake256)#2}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256_5c
with const generics
- OUTPUT_LENGTH= 576
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_shake256_5c_1b(Eurydice_slice input,
                                                      uint8_t *out) {
  libcrux_ml_dsa_hash_functions_portable_shake256_1b(input, out);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake256::DsaXof
for libcrux_ml_dsa::hash_functions::portable::Shake256)#2}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake256_5c
with const generics
- OUTPUT_LENGTH= 640
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_shake256_5c_c8(Eurydice_slice input,
                                                      uint8_t *out) {
  libcrux_ml_dsa_hash_functions_portable_shake256_c8(input, out);
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_mask_ring_element
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256 with const generics
- GAMMA1_EXPONENT= 19
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_sample_sample_mask_ring_element_20(
    uint8_t seed[66U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *result) {
  uint8_t out[640U] = {0U};
  libcrux_ml_dsa_hash_functions_portable_shake256_5c_c8(
      Eurydice_array_to_slice((size_t)66U, seed, uint8_t), out);
  libcrux_ml_dsa_encoding_gamma1_deserialize_61(
      Eurydice_array_to_slice((size_t)640U, out, uint8_t), result);
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_mask_vector
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
- DIMENSION= 5
- GAMMA1_EXPONENT= 19
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_sample_sample_mask_vector_0e(
    uint8_t seed[66U], uint16_t *domain_separator,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b mask[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    mask[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed0[66U];
  memcpy(copy_of_seed0, seed, (size_t)66U * sizeof(uint8_t));
  uint8_t seed0[66U];
  libcrux_ml_dsa_sample_update_seed(copy_of_seed0, domain_separator, seed0);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed1[66U];
  memcpy(copy_of_seed1, seed, (size_t)66U * sizeof(uint8_t));
  uint8_t seed1[66U];
  libcrux_ml_dsa_sample_update_seed(copy_of_seed1, domain_separator, seed1);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed2[66U];
  memcpy(copy_of_seed2, seed, (size_t)66U * sizeof(uint8_t));
  uint8_t seed2[66U];
  libcrux_ml_dsa_sample_update_seed(copy_of_seed2, domain_separator, seed2);
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_seed3[66U];
  memcpy(copy_of_seed3, seed, (size_t)66U * sizeof(uint8_t));
  uint8_t seed3[66U];
  libcrux_ml_dsa_sample_update_seed(copy_of_seed3, domain_separator, seed3);
  uint8_t out0[640U] = {0U};
  uint8_t out1[640U] = {0U};
  uint8_t out2[640U] = {0U};
  uint8_t out3[640U] = {0U};
  libcrux_ml_dsa_hash_functions_portable_shake256_x4_50_c8(
      Eurydice_array_to_slice((size_t)66U, seed0, uint8_t),
      Eurydice_array_to_slice((size_t)66U, seed1, uint8_t),
      Eurydice_array_to_slice((size_t)66U, seed2, uint8_t),
      Eurydice_array_to_slice((size_t)66U, seed3, uint8_t), out0, out1, out2,
      out3);
  libcrux_ml_dsa_encoding_gamma1_deserialize_61(
      Eurydice_array_to_slice((size_t)640U, out0, uint8_t), mask);
  libcrux_ml_dsa_encoding_gamma1_deserialize_61(
      Eurydice_array_to_slice((size_t)640U, out1, uint8_t), &mask[1U]);
  libcrux_ml_dsa_encoding_gamma1_deserialize_61(
      Eurydice_array_to_slice((size_t)640U, out2, uint8_t), &mask[2U]);
  libcrux_ml_dsa_encoding_gamma1_deserialize_61(
      Eurydice_array_to_slice((size_t)640U, out3, uint8_t), &mask[3U]);
  for (size_t i = (size_t)4U; i < (size_t)5U; i++) {
    size_t i0 = i;
    seed[64U] = (uint8_t)domain_separator[0U];
    seed[65U] = (uint8_t)((uint32_t)domain_separator[0U] >> 8U);
    domain_separator[0U] = (uint32_t)domain_separator[0U] + 1U;
    /* Passing arrays by value in Rust generates a copy in C */
    uint8_t copy_of_seed[66U];
    memcpy(copy_of_seed, seed, (size_t)66U * sizeof(uint8_t));
    libcrux_ml_dsa_sample_sample_mask_ring_element_20(copy_of_seed, &mask[i0]);
  }
  memcpy(
      ret, mask,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.compute_A_times_mask.closure
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static inline libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_matrix_compute_A_times_mask_closure_2f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s) {
  return libcrux_ml_dsa_ntt_ntt_ba(s);
}

/**
 Compute InvertNTT(Â ◦ ŷ)
*/
/**
A monomorphic instance of libcrux_ml_dsa.matrix.compute_A_times_mask
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_compute_A_times_mask_2f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b (*A_as_ntt)[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *mask,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_mask[5U];
  memcpy(
      copy_of_mask, mask,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b mask_ntt[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    mask_ntt[i] =
        libcrux_ml_dsa_matrix_compute_A_times_mask_closure_2f(copy_of_mask[i]);
  }
  for (size_t i0 = (size_t)0U;
       i0 < Eurydice_slice_len(
                Eurydice_array_to_slice(
                    (size_t)6U, A_as_ntt,
                    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]),
                libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]);
       i0++) {
    size_t i1 = i0;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *row = A_as_ntt[i1];
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)5U, row,
                     libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
                 libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
         i++) {
      size_t j = i;
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
          &row[j];
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b product =
          libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(ring_element,
                                                        &mask_ntt[j]);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____1 =
          libcrux_ml_dsa_polynomial_add_ff_ba(&result[i1], &product);
      result[i1] = uu____1;
    }
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____2 =
        libcrux_ml_dsa_ntt_invert_ntt_montgomery_ba(result[i1]);
    result[i1] = uu____2;
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.portable.arithmetic.decompose_element with const generics
- GAMMA2= 261888
*/
static KRML_MUSTINLINE int32_t_x2
libcrux_ml_dsa_simd_portable_arithmetic_decompose_element_80(int32_t r) {
  int32_t r2 = r + (r >> 31U & LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  int32_t ALPHA = (int32_t)261888 * (int32_t)2;
  int32_t ceil_of_r_by_128 = (r2 + (int32_t)127) >> 7U;
  int32_t r1;
  switch (ALPHA) {
    case 190464: {
      int32_t result =
          (ceil_of_r_by_128 * (int32_t)11275 + ((int32_t)1 << 23U)) >> 24U;
      r1 = (result ^ ((int32_t)43 - result) >> 31U) & result;
      break;
    }
    case 523776: {
      int32_t result =
          (ceil_of_r_by_128 * (int32_t)1025 + ((int32_t)1 << 21U)) >> 22U;
      r1 = result & (int32_t)15;
      break;
    }
    default: {
      KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                        "panic!");
      KRML_HOST_EXIT(255U);
    }
  }
  int32_t r0 = r2 - r1 * ALPHA;
  r0 = r0 -
       (((LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS - (int32_t)1) / (int32_t)2 -
         r0) >>
            31U &
        LIBCRUX_ML_DSA_SIMD_TRAITS_FIELD_MODULUS);
  return (CLITERAL(int32_t_x2){.fst = r0, .snd = r1});
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.arithmetic.decompose
with const generics
- GAMMA2= 261888
*/
static KRML_MUSTINLINE
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2
    libcrux_ml_dsa_simd_portable_arithmetic_decompose_80(
        libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit low =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit high =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice((size_t)8U, low.coefficients, int32_t),
               int32_t);
       i++) {
    size_t i0 = i;
    int32_t_x2 uu____0 =
        libcrux_ml_dsa_simd_portable_arithmetic_decompose_element_80(
            simd_unit.coefficients[i0]);
    int32_t low_part = uu____0.fst;
    int32_t high_part = uu____0.snd;
    low.coefficients[i0] = low_part;
    high.coefficients[i0] = high_part;
  }
  return (
      CLITERAL(libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2){
          .fst = low, .snd = high});
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.decompose_36
with const generics
- GAMMA2= 261888
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2
libcrux_ml_dsa_simd_portable_decompose_36_80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit) {
  return libcrux_ml_dsa_simd_portable_arithmetic_decompose_80(simd_unit);
}

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.decompose_vector
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
- GAMMA2= 261888
*/
static KRML_MUSTINLINE
    libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2
    libcrux_ml_dsa_arithmetic_decompose_vector_2f(
        libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b vector_low[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    vector_low[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b vector_high[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    vector_high[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i0 = (size_t)0U; i0 < (size_t)6U; i0++) {
    size_t i1 = i0;
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)32U, vector_low->simd_units,
                     libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
                 libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
         i++) {
      size_t j = i;
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_x2 uu____0 =
          libcrux_ml_dsa_simd_portable_decompose_36_80(t[i1].simd_units[j]);
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit low =
          uu____0.fst;
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit high =
          uu____0.snd;
      vector_low[i1].simd_units[j] = low;
      vector_high[i1].simd_units[j] = high;
    }
  }
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_vector_low[6U];
  memcpy(
      copy_of_vector_low, vector_low,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_vector_high[6U];
  memcpy(
      copy_of_vector_high, vector_high,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2
      lit;
  memcpy(
      lit.fst, copy_of_vector_low,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  memcpy(
      lit.snd, copy_of_vector_high,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.commitment.serialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_commitment_serialize_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re,
    Eurydice_slice serialized) {
  size_t output_bytes_per_simd_unit =
      Eurydice_slice_len(serialized, uint8_t) / ((size_t)8U * (size_t)4U);
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &re.simd_units[i0];
    libcrux_ml_dsa_simd_portable_commitment_serialize_36(
        simd_unit[0U],
        Eurydice_slice_subslice2(serialized, i0 * output_bytes_per_simd_unit,
                                 (i0 + (size_t)1U) * output_bytes_per_simd_unit,
                                 uint8_t));
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.commitment.serialize_vector
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
- RING_ELEMENT_SIZE= 128
- OUTPUT_SIZE= 768
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_encoding_commitment_serialize_vector_5d(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b vector[6U],
    uint8_t ret[768U]) {
  uint8_t serialized[768U] = {0U};
  size_t offset = (size_t)0U;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, vector,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t _cloop_j = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
        &vector[_cloop_j];
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        ring_element[0U];
    libcrux_ml_dsa_encoding_commitment_serialize_ba(
        uu____0, Eurydice_array_to_subslice2(serialized, offset,
                                             offset + (size_t)128U, uint8_t));
    offset = offset + (size_t)128U;
  }
  memcpy(ret, serialized, (size_t)768U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_dsa.sample.sample_challenge_ring_element
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_hash_functions_portable_Shake256 with const generics
- NUMBER_OF_ONES= 49
- SEED_SIZE= 48
*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_sample_sample_challenge_ring_element_83(uint8_t seed[48U]) {
  libcrux_sha3_portable_KeccakState state =
      libcrux_ml_dsa_hash_functions_portable_init_absorb_final_5c(
          Eurydice_array_to_slice((size_t)48U, seed, uint8_t));
  uint8_t randomness0[136U];
  libcrux_ml_dsa_hash_functions_portable_squeeze_first_block_5c(&state,
                                                                randomness0);
  uint8_t ret[8U];
  Result_15 dst;
  Eurydice_slice_to_array2(
      &dst,
      Eurydice_array_to_subslice2(randomness0, (size_t)0U, (size_t)8U, uint8_t),
      Eurydice_slice, uint8_t[8U]);
  unwrap_26_68(dst, ret);
  uint64_t signs = core_num__u64_9__from_le_bytes(ret);
  int32_t result[256U] = {0U};
  size_t out_index =
      Eurydice_slice_len(Eurydice_array_to_slice((size_t)256U, result, int32_t),
                         int32_t) -
      (size_t)49U;
  Eurydice_slice uu____0 = Eurydice_array_to_subslice_from(
      (size_t)136U, randomness0, (size_t)8U, uint8_t, size_t);
  bool done = libcrux_ml_dsa_sample_inside_out_shuffle(uu____0, &out_index,
                                                       &signs, result);
  while (true) {
    if (done) {
      break;
    } else {
      uint8_t randomness[136U];
      libcrux_ml_dsa_hash_functions_portable_squeeze_next_block_5c(&state,
                                                                   randomness);
      done = libcrux_ml_dsa_sample_inside_out_shuffle(
          Eurydice_array_to_slice((size_t)136U, randomness, uint8_t),
          &out_index, &signs, result);
    }
  }
  return libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(
      Eurydice_array_to_slice((size_t)256U, result, int32_t));
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.vector_times_ring_element
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_vector_times_ring_element_4f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *vector,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)5U, vector,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *vector_ring_element =
        &vector[i0];
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_ntt_invert_ntt_montgomery_ba(
            libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(vector_ring_element,
                                                          ring_element));
    result[i0] = uu____0;
  }
  memcpy(
      ret, result,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.vector_times_ring_element
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_vector_times_ring_element_07(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *vector,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, vector,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *vector_ring_element =
        &vector[i0];
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_ntt_invert_ntt_montgomery_ba(
            libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(vector_ring_element,
                                                          ring_element));
    result[i0] = uu____0;
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.add_vectors
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_add_vectors_4f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *lhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *rhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[5U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_polynomial_add_ff_ba(&lhs[i0], &rhs[i0]);
    result[i0] = uu____0;
  }
  memcpy(
      ret, result,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.subtract_ff
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_polynomial_subtract_ff_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *self,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *rhs) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b difference =
      libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, difference.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_subtract_36(&self->simd_units[i0],
                                                 &rhs->simd_units[i0]);
    difference.simd_units[i0] = uu____0;
  }
  return difference;
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.subtract_vectors
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_subtract_vectors_07(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *lhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *rhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_polynomial_subtract_ff_ba(&lhs[i0], &rhs[i0]);
    result[i0] = uu____0;
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.infinity_norm_exceeds_ff
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static inline bool libcrux_ml_dsa_polynomial_infinity_norm_exceeds_ff_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *self, int32_t bound) {
  bool exceeds = false;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, self->simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    bool uu____0;
    if (exceeds) {
      uu____0 = true;
    } else {
      uu____0 = libcrux_ml_dsa_simd_portable_infinity_norm_exceeds_36(
          self->simd_units[i0], bound);
    }
    exceeds = uu____0;
  }
  return exceeds;
}

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.vector_infinity_norm_exceeds
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 5
*/
static KRML_MUSTINLINE bool
libcrux_ml_dsa_arithmetic_vector_infinity_norm_exceeds_4f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b vector[5U],
    int32_t bound) {
  bool exceeds = false;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)5U, vector,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t _cloop_j = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
        &vector[_cloop_j];
    bool uu____0;
    if (exceeds) {
      uu____0 = true;
    } else {
      uu____0 = libcrux_ml_dsa_polynomial_infinity_norm_exceeds_ff_ba(
          ring_element, bound);
    }
    exceeds = uu____0;
  }
  return exceeds;
}

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.vector_infinity_norm_exceeds
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
*/
static KRML_MUSTINLINE bool
libcrux_ml_dsa_arithmetic_vector_infinity_norm_exceeds_07(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b vector[6U],
    int32_t bound) {
  bool exceeds = false;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)6U, vector,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t _cloop_j = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
        &vector[_cloop_j];
    bool uu____0;
    if (exceeds) {
      uu____0 = true;
    } else {
      uu____0 = libcrux_ml_dsa_polynomial_infinity_norm_exceeds_ff_ba(
          ring_element, bound);
    }
    exceeds = uu____0;
  }
  return exceeds;
}

/**
A monomorphic instance of libcrux_ml_dsa.matrix.add_vectors
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_add_vectors_07(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *lhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *rhs,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_polynomial_add_ff_ba(&lhs[i0], &rhs[i0]);
    result[i0] = uu____0;
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of K.
with types size_t, libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit

*/
typedef struct tuple_ca_s {
  size_t fst;
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit snd;
} tuple_ca;

/**
A monomorphic instance of
libcrux_ml_dsa.simd.portable.arithmetic.compute_one_hint with const generics
- GAMMA2= 261888
*/
static KRML_MUSTINLINE int32_t
libcrux_ml_dsa_simd_portable_arithmetic_compute_one_hint_80(int32_t low,
                                                            int32_t high) {
  int32_t uu____0;
  if (!(low > (int32_t)261888)) {
    if (!(low < -(int32_t)261888)) {
      if (low == -(int32_t)261888) {
        if (!(high != (int32_t)0)) {
          uu____0 = (int32_t)0;
          return uu____0;
        }
      } else {
        uu____0 = (int32_t)0;
        return uu____0;
      }
    }
  }
  uu____0 = (int32_t)1;
  return uu____0;
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.arithmetic.compute_hint
with const generics
- GAMMA2= 261888
*/
static KRML_MUSTINLINE tuple_ca
libcrux_ml_dsa_simd_portable_arithmetic_compute_hint_80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit low,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit high) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit hint =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  size_t one_hints_count = (size_t)0U;
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice((size_t)8U, hint.coefficients, int32_t),
               int32_t);
       i++) {
    size_t i0 = i;
    hint.coefficients[i0] =
        libcrux_ml_dsa_simd_portable_arithmetic_compute_one_hint_80(
            low.coefficients[i0], high.coefficients[i0]);
    one_hints_count = one_hints_count + (size_t)hint.coefficients[i0];
  }
  return (CLITERAL(tuple_ca){.fst = one_hints_count, .snd = hint});
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.compute_hint_36
with const generics
- GAMMA2= 261888
*/
static inline tuple_ca libcrux_ml_dsa_simd_portable_compute_hint_36_80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit low,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit high) {
  return libcrux_ml_dsa_simd_portable_arithmetic_compute_hint_80(low, high);
}

/**
This function found in impl
{libcrux_ml_dsa::polynomial::PolynomialRingElement<SIMDUnit>[TraitClause@0,
TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.polynomial.to_i32_array_ff
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static inline void libcrux_ml_dsa_polynomial_to_i32_array_ff_ba(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *self,
    int32_t ret[256U]) {
  int32_t result[256U] = {0U};
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, self->simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &self->simd_units[i0];
    Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
        result, i0 * LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT,
        (i0 + (size_t)1U) *
            LIBCRUX_ML_DSA_SIMD_TRAITS_COEFFICIENTS_IN_SIMD_UNIT,
        int32_t);
    int32_t ret0[8U];
    libcrux_ml_dsa_simd_portable_to_coefficient_array_36(simd_unit, ret0);
    Eurydice_slice_copy(
        uu____0, Eurydice_array_to_slice((size_t)8U, ret0, int32_t), int32_t);
  }
  memcpy(ret, result, (size_t)256U * sizeof(int32_t));
}

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.make_hint
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
- GAMMA2= 261888
*/
static KRML_MUSTINLINE tuple_e6 libcrux_ml_dsa_arithmetic_make_hint_2f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b low[6U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b high[6U]) {
  int32_t hint[6U][256U] = {{0U}};
  size_t true_hints = (size_t)0U;
  for (size_t i0 = (size_t)0U; i0 < (size_t)6U; i0++) {
    size_t i1 = i0;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b hint_simd =
        libcrux_ml_dsa_polynomial_ZERO_ff_ba();
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)32U, hint_simd.simd_units,
                     libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
                 libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
         i++) {
      size_t j = i;
      tuple_ca uu____0 = libcrux_ml_dsa_simd_portable_compute_hint_36_80(
          low[i1].simd_units[j], high[i1].simd_units[j]);
      size_t one_hints_count = uu____0.fst;
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit current_hint =
          uu____0.snd;
      hint_simd.simd_units[j] = current_hint;
      true_hints = true_hints + one_hints_count;
    }
    int32_t uu____1[256U];
    libcrux_ml_dsa_polynomial_to_i32_array_ff_ba(&hint_simd, uu____1);
    memcpy(hint[i1], uu____1, (size_t)256U * sizeof(int32_t));
  }
  /* Passing arrays by value in Rust generates a copy in C */
  int32_t copy_of_hint[6U][256U];
  memcpy(copy_of_hint, hint, (size_t)6U * sizeof(int32_t[256U]));
  tuple_e6 lit;
  memcpy(lit.fst, copy_of_hint, (size_t)6U * sizeof(int32_t[256U]));
  lit.snd = true_hints;
  return lit;
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.signature.Signature
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- $48size_t
- $5size_t
- $6size_t
*/
typedef struct libcrux_ml_dsa_encoding_signature_Signature_44_s {
  uint8_t commitment_hash[48U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b signer_response[5U];
  int32_t hint[6U][256U];
} libcrux_ml_dsa_encoding_signature_Signature_44;

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.encoding.gamma1.serialize
with const generics
- GAMMA1_EXPONENT= 19
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_simd_portable_encoding_gamma1_serialize_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_encoding_gamma1_serialize_when_gamma1_is_2_pow_19(
      simd_unit, serialized);
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.gamma1_serialize_36
with const generics
- GAMMA1_EXPONENT= 19
*/
static inline void libcrux_ml_dsa_simd_portable_gamma1_serialize_36_36(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    Eurydice_slice serialized) {
  libcrux_ml_dsa_simd_portable_encoding_gamma1_serialize_36(simd_unit,
                                                            serialized);
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.gamma1.serialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- GAMMA1_EXPONENT= 19
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_gamma1_serialize_61(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re,
    Eurydice_slice serialized) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &re.simd_units[i0];
    libcrux_ml_dsa_simd_portable_gamma1_serialize_36_36(
        simd_unit[0U],
        Eurydice_slice_subslice2(serialized, i0 * ((size_t)19U + (size_t)1U),
                                 (i0 + (size_t)1U) * ((size_t)19U + (size_t)1U),
                                 uint8_t));
  }
}

/**
This function found in impl
{libcrux_ml_dsa::encoding::signature::Signature<SIMDUnit, COMMITMENT_HASH_SIZE,
COLUMNS_IN_A, ROWS_IN_A>[TraitClause@0, TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.encoding.signature.serialize_92
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- COMMITMENT_HASH_SIZE= 48
- COLUMNS_IN_A= 5
- ROWS_IN_A= 6
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- MAX_ONES_IN_HINT= 55
- SIGNATURE_SIZE= 3309
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_encoding_signature_serialize_92_76(
    libcrux_ml_dsa_encoding_signature_Signature_44 *self, uint8_t ret[3309U]) {
  uint8_t signature[3309U] = {0U};
  size_t offset = (size_t)0U;
  Eurydice_slice uu____0 = Eurydice_array_to_subslice2(
      signature, offset, offset + (size_t)48U, uint8_t);
  Eurydice_slice_copy(
      uu____0,
      Eurydice_array_to_slice((size_t)48U, self->commitment_hash, uint8_t),
      uint8_t);
  offset = offset + (size_t)48U;
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____1 =
        self->signer_response[i0];
    libcrux_ml_dsa_encoding_gamma1_serialize_61(
        uu____1, Eurydice_array_to_subslice2(signature, offset,
                                             offset + (size_t)640U, uint8_t));
    offset = offset + (size_t)640U;
  }
  size_t true_hints_seen = (size_t)0U;
  for (size_t i0 = (size_t)0U; i0 < (size_t)6U; i0++) {
    size_t i1 = i0;
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice((size_t)256U, self->hint[i1], int32_t),
                 int32_t);
         i++) {
      size_t j = i;
      if (self->hint[i1][j] == (int32_t)1) {
        signature[offset + true_hints_seen] = (uint8_t)j;
        true_hints_seen++;
      }
    }
    signature[offset + (size_t)55U + i1] = (uint8_t)true_hints_seen;
  }
  memcpy(ret, signature, (size_t)3309U * sizeof(uint8_t));
}

/**
 The internal signing API.

 If no `domain_separation_context` is supplied, it is assumed that
 `message` already contains the domain separation.
*/
/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.sign_internal
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
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
static KRML_MUSTINLINE Result_2e libcrux_ml_dsa_ml_dsa_generic_sign_internal_3f(
    uint8_t *signing_key, Eurydice_slice message,
    Option_84 domain_separation_context, uint8_t randomness[32U]) {
  tuple_f0 uu____0 =
      libcrux_ml_dsa_encoding_signing_key_deserialize_then_ntt_c6(signing_key);
  uint8_t seed_for_A[32U];
  memcpy(seed_for_A, uu____0.fst, (size_t)32U * sizeof(uint8_t));
  uint8_t seed_for_signing[32U];
  memcpy(seed_for_signing, uu____0.snd, (size_t)32U * sizeof(uint8_t));
  uint8_t verification_key_hash[64U];
  memcpy(verification_key_hash, uu____0.thd, (size_t)64U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s1_as_ntt[5U];
  memcpy(
      s1_as_ntt, uu____0.f3,
      (size_t)5U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b s2_as_ntt[6U];
  memcpy(
      s2_as_ntt, uu____0.f4,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t0_as_ntt[6U];
  memcpy(
      t0_as_ntt, uu____0.f5,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b A_as_ntt[6U][5U];
  uint8_t ret[34U];
  libcrux_ml_dsa_utils_into_padded_array_b6(
      Eurydice_array_to_slice((size_t)32U, seed_for_A, uint8_t), ret);
  libcrux_ml_dsa_samplex4_portable_matrix_A_36_2f(ret, A_as_ntt);
  uint8_t message_representative[64U] = {0U};
  uint8_t uu____1[64U];
  memcpy(uu____1, verification_key_hash, (size_t)64U * sizeof(uint8_t));
  libcrux_ml_dsa_ml_dsa_generic_derive_message_representative_7b(
      uu____1, domain_separation_context, message, message_representative);
  uint8_t mask_seed[64U] = {0U};
  libcrux_sha3_portable_incremental_Shake256Xof shake0 =
      libcrux_ml_dsa_hash_functions_portable_init_83();
  libcrux_ml_dsa_hash_functions_portable_absorb_83(
      &shake0, Eurydice_array_to_slice((size_t)32U, seed_for_signing, uint8_t));
  libcrux_ml_dsa_hash_functions_portable_absorb_83(
      &shake0, Eurydice_array_to_slice((size_t)32U, randomness, uint8_t));
  libcrux_ml_dsa_hash_functions_portable_absorb_final_83(
      &shake0,
      Eurydice_array_to_slice((size_t)64U, message_representative, uint8_t));
  libcrux_ml_dsa_hash_functions_portable_squeeze_83(
      &shake0, Eurydice_array_to_slice((size_t)64U, mask_seed, uint8_t));
  uint16_t domain_separator_for_mask = 0U;
  int32_t BETA = (int32_t)((size_t)49U * (size_t)4U);
  size_t attempt = (size_t)0U;
  Option_67 commitment_hash0 = {.tag = None};
  Option_f3 signer_response0 = {.tag = None};
  Option_f0 hint0 = {.tag = None};
  while (true) {
    if (attempt < LIBCRUX_ML_DSA_CONSTANTS_REJECTION_SAMPLE_BOUND_SIGN) {
      attempt++;
      uint8_t uu____2[66U];
      libcrux_ml_dsa_utils_into_padded_array_20(
          Eurydice_array_to_slice((size_t)64U, mask_seed, uint8_t), uu____2);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b mask[5U];
      libcrux_ml_dsa_sample_sample_mask_vector_0e(
          uu____2, &domain_separator_for_mask, mask);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b A_times_mask[6U];
      libcrux_ml_dsa_matrix_compute_A_times_mask_2f(A_as_ntt, mask,
                                                    A_times_mask);
      /* Passing arrays by value in Rust generates a copy in C */
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          copy_of_A_times_mask[6U];
      memcpy(copy_of_A_times_mask, A_times_mask,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit_6size_t__x2
          uu____4 = libcrux_ml_dsa_arithmetic_decompose_vector_2f(
              copy_of_A_times_mask);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b w0[6U];
      memcpy(w0, uu____4.fst,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b commitment[6U];
      memcpy(commitment, uu____4.snd,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      uint8_t commitment_hash_candidate[48U] = {0U};
      /* Passing arrays by value in Rust generates a copy in C */
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          copy_of_commitment0[6U];
      memcpy(copy_of_commitment0, commitment,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      uint8_t commitment_serialized[768U];
      libcrux_ml_dsa_encoding_commitment_serialize_vector_5d(
          copy_of_commitment0, commitment_serialized);
      libcrux_sha3_portable_incremental_Shake256Xof shake =
          libcrux_ml_dsa_hash_functions_portable_init_83();
      libcrux_ml_dsa_hash_functions_portable_absorb_83(
          &shake, Eurydice_array_to_slice((size_t)64U, message_representative,
                                          uint8_t));
      libcrux_ml_dsa_hash_functions_portable_absorb_final_83(
          &shake, Eurydice_array_to_slice((size_t)768U, commitment_serialized,
                                          uint8_t));
      libcrux_ml_dsa_hash_functions_portable_squeeze_83(
          &shake, Eurydice_array_to_slice((size_t)48U,
                                          commitment_hash_candidate, uint8_t));
      /* Passing arrays by value in Rust generates a copy in C */
      uint8_t copy_of_commitment_hash_candidate[48U];
      memcpy(copy_of_commitment_hash_candidate, commitment_hash_candidate,
             (size_t)48U * sizeof(uint8_t));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          verifier_challenge_as_ntt = libcrux_ml_dsa_ntt_ntt_ba(
              libcrux_ml_dsa_sample_sample_challenge_ring_element_83(
                  copy_of_commitment_hash_candidate));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b challenge_times_s1[5U];
      libcrux_ml_dsa_matrix_vector_times_ring_element_4f(
          s1_as_ntt, &verifier_challenge_as_ntt, challenge_times_s1);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b challenge_times_s2[6U];
      libcrux_ml_dsa_matrix_vector_times_ring_element_07(
          s2_as_ntt, &verifier_challenge_as_ntt, challenge_times_s2);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          signer_response_candidate[5U];
      libcrux_ml_dsa_matrix_add_vectors_4f(mask, challenge_times_s1,
                                           signer_response_candidate);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          w0_minus_challenge_times_s2[6U];
      libcrux_ml_dsa_matrix_subtract_vectors_07(w0, challenge_times_s2,
                                                w0_minus_challenge_times_s2);
      /* Passing arrays by value in Rust generates a copy in C */
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          copy_of_signer_response_candidate[5U];
      memcpy(copy_of_signer_response_candidate, signer_response_candidate,
             (size_t)5U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      if (!libcrux_ml_dsa_arithmetic_vector_infinity_norm_exceeds_4f(
              copy_of_signer_response_candidate,
              ((int32_t)1 << (uint32_t)(size_t)19U) - BETA)) {
        /* Passing arrays by value in Rust generates a copy in C */
        libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
            copy_of_w0_minus_challenge_times_s2[6U];
        memcpy(copy_of_w0_minus_challenge_times_s2, w0_minus_challenge_times_s2,
               (size_t)6U *
                   sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
        if (!libcrux_ml_dsa_arithmetic_vector_infinity_norm_exceeds_07(
                copy_of_w0_minus_challenge_times_s2, (int32_t)261888 - BETA)) {
          libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
              challenge_times_t0[6U];
          libcrux_ml_dsa_matrix_vector_times_ring_element_07(
              t0_as_ntt, &verifier_challenge_as_ntt, challenge_times_t0);
          /* Passing arrays by value in Rust generates a copy in C */
          libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
              copy_of_challenge_times_t0[6U];
          memcpy(
              copy_of_challenge_times_t0, challenge_times_t0,
              (size_t)6U *
                  sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
          if (!libcrux_ml_dsa_arithmetic_vector_infinity_norm_exceeds_07(
                  copy_of_challenge_times_t0, (int32_t)261888)) {
            libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
                w0_minus_c_times_s2_plus_c_times_t0[6U];
            libcrux_ml_dsa_matrix_add_vectors_07(
                w0_minus_challenge_times_s2, challenge_times_t0,
                w0_minus_c_times_s2_plus_c_times_t0);
            /* Passing arrays by value in Rust generates a copy in C */
            libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
                copy_of_w0_minus_c_times_s2_plus_c_times_t0[6U];
            memcpy(
                copy_of_w0_minus_c_times_s2_plus_c_times_t0,
                w0_minus_c_times_s2_plus_c_times_t0,
                (size_t)6U *
                    sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
            /* Passing arrays by value in Rust generates a copy in C */
            libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
                copy_of_commitment[6U];
            memcpy(
                copy_of_commitment, commitment,
                (size_t)6U *
                    sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
            tuple_e6 uu____12 = libcrux_ml_dsa_arithmetic_make_hint_2f(
                copy_of_w0_minus_c_times_s2_plus_c_times_t0,
                copy_of_commitment);
            int32_t hint_candidate[6U][256U];
            memcpy(hint_candidate, uu____12.fst,
                   (size_t)6U * sizeof(int32_t[256U]));
            size_t ones_in_hint = uu____12.snd;
            if (!(ones_in_hint > (size_t)55U)) {
              attempt = LIBCRUX_ML_DSA_CONSTANTS_REJECTION_SAMPLE_BOUND_SIGN;
              /* Passing arrays by value in Rust generates a copy in C */
              uint8_t copy_of_commitment_hash_candidate0[48U];
              memcpy(copy_of_commitment_hash_candidate0,
                     commitment_hash_candidate, (size_t)48U * sizeof(uint8_t));
              Option_67 lit0;
              lit0.tag = Some;
              memcpy(lit0.f0, copy_of_commitment_hash_candidate0,
                     (size_t)48U * sizeof(uint8_t));
              commitment_hash0 = lit0;
              /* Passing arrays by value in Rust generates a copy in C */
              libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
                  copy_of_signer_response_candidate0[5U];
              memcpy(
                  copy_of_signer_response_candidate0, signer_response_candidate,
                  (size_t)5U *
                      sizeof(
                          libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
              Option_f3 lit1;
              lit1.tag = Some;
              memcpy(
                  lit1.f0, copy_of_signer_response_candidate0,
                  (size_t)5U *
                      sizeof(
                          libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
              signer_response0 = lit1;
              /* Passing arrays by value in Rust generates a copy in C */
              int32_t copy_of_hint_candidate[6U][256U];
              memcpy(copy_of_hint_candidate, hint_candidate,
                     (size_t)6U * sizeof(int32_t[256U]));
              Option_f0 lit;
              lit.tag = Some;
              memcpy(lit.f0, copy_of_hint_candidate,
                     (size_t)6U * sizeof(int32_t[256U]));
              hint0 = lit;
            }
          }
        }
      }
    } else {
      break;
    }
  }
  Result_2e uu____16;
  if (commitment_hash0.tag == None) {
    uu____16 = (CLITERAL(Result_2e){
        .tag = Err,
        .val = {.case_Err = libcrux_ml_dsa_types_RejectionSamplingError}});
  } else {
    uint8_t commitment_hash1[48U];
    memcpy(commitment_hash1, commitment_hash0.f0,
           (size_t)48U * sizeof(uint8_t));
    uint8_t commitment_hash[48U];
    memcpy(commitment_hash, commitment_hash1, (size_t)48U * sizeof(uint8_t));
    if (signer_response0.tag == None) {
      uu____16 = (CLITERAL(Result_2e){
          .tag = Err,
          .val = {.case_Err = libcrux_ml_dsa_types_RejectionSamplingError}});
    } else {
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b signer_response1[5U];
      memcpy(signer_response1, signer_response0.f0,
             (size_t)5U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b signer_response[5U];
      memcpy(signer_response, signer_response1,
             (size_t)5U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      if (hint0.tag == None) {
        uu____16 = (CLITERAL(Result_2e){
            .tag = Err,
            .val = {.case_Err = libcrux_ml_dsa_types_RejectionSamplingError}});
      } else {
        int32_t hint1[6U][256U];
        memcpy(hint1, hint0.f0, (size_t)6U * sizeof(int32_t[256U]));
        int32_t hint[6U][256U];
        memcpy(hint, hint1, (size_t)6U * sizeof(int32_t[256U]));
        /* Passing arrays by value in Rust generates a copy in C */
        uint8_t copy_of_commitment_hash[48U];
        memcpy(copy_of_commitment_hash, commitment_hash,
               (size_t)48U * sizeof(uint8_t));
        /* Passing arrays by value in Rust generates a copy in C */
        libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
            copy_of_signer_response[5U];
        memcpy(copy_of_signer_response, signer_response,
               (size_t)5U *
                   sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
        /* Passing arrays by value in Rust generates a copy in C */
        int32_t copy_of_hint[6U][256U];
        memcpy(copy_of_hint, hint, (size_t)6U * sizeof(int32_t[256U]));
        uint8_t signature[3309U];
        libcrux_ml_dsa_encoding_signature_Signature_44 lit0;
        memcpy(lit0.commitment_hash, copy_of_commitment_hash,
               (size_t)48U * sizeof(uint8_t));
        memcpy(lit0.signer_response, copy_of_signer_response,
               (size_t)5U *
                   sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
        memcpy(lit0.hint, copy_of_hint, (size_t)6U * sizeof(int32_t[256U]));
        libcrux_ml_dsa_encoding_signature_serialize_92_76(&lit0, signature);
        /* Passing arrays by value in Rust generates a copy in C */
        uint8_t copy_of_signature[3309U];
        memcpy(copy_of_signature, signature, (size_t)3309U * sizeof(uint8_t));
        Result_2e lit;
        lit.tag = Ok;
        lit.val.case_Ok = libcrux_ml_dsa_types_new_8f_fa(copy_of_signature);
        uu____16 = lit;
        return uu____16;
      }
    }
  }
  return uu____16;
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.sign
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_portable_Shake256X4 with const generics
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
static KRML_MUSTINLINE Result_2e libcrux_ml_dsa_ml_dsa_generic_sign_3f(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  Result_a8 uu____0 = libcrux_ml_dsa_pre_hash_new_45(
      context, (CLITERAL(Option_30){.tag = None}));
  Result_2e uu____1;
  if (uu____0.tag == Ok) {
    libcrux_ml_dsa_pre_hash_DomainSeparationContext dsc = uu____0.val.case_Ok;
    libcrux_ml_dsa_pre_hash_DomainSeparationContext domain_separation_context =
        dsc;
    uint8_t *uu____2 = signing_key;
    Eurydice_slice uu____3 = message;
    Option_84 uu____4 = {.tag = Some, .f0 = domain_separation_context};
    /* Passing arrays by value in Rust generates a copy in C */
    uint8_t copy_of_randomness[32U];
    memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
    uu____1 = libcrux_ml_dsa_ml_dsa_generic_sign_internal_3f(
        uu____2, uu____3, uu____4, copy_of_randomness);
  } else {
    uu____1 = (CLITERAL(Result_2e){
        .tag = Err,
        .val = {.case_Err = libcrux_ml_dsa_types_ContextTooLongError}});
  }
  return uu____1;
}

/**
 Sign.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.portable.sign with const generics
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
static inline Result_2e
libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_sign_f3(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  uint8_t *uu____0 = signing_key;
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_sign_3f(uu____0, uu____1, uu____2,
                                               copy_of_randomness);
}

/**
 Generate an ML-DSA-65 Signature

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
static inline Result_2e libcrux_ml_dsa_ml_dsa_65_portable_sign(
    libcrux_ml_dsa_types_MLDSASigningKey_22 *signing_key,
    Eurydice_slice message, Eurydice_slice context, uint8_t randomness[32U]) {
  uint8_t *uu____0 = libcrux_ml_dsa_types_as_ref_9b_09(signing_key);
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_sign_f3(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake128
with const generics
- OUTPUT_LENGTH= 256
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_hash_functions_portable_shake128_6b(
    Eurydice_slice input, uint8_t *out) {
  libcrux_sha3_portable_shake128(
      Eurydice_array_to_slice((size_t)256U, out, uint8_t), input);
}

/**
This function found in impl {(libcrux_ml_dsa::hash_functions::shake128::Xof for
libcrux_ml_dsa::hash_functions::portable::Shake128)#1}
*/
/**
A monomorphic instance of libcrux_ml_dsa.hash_functions.portable.shake128_a0
with const generics
- OUTPUT_LENGTH= 256
*/
static KRML_MUSTINLINE void
libcrux_ml_dsa_hash_functions_portable_shake128_a0_6b(Eurydice_slice input,
                                                      uint8_t *out) {
  libcrux_ml_dsa_hash_functions_portable_shake128_6b(input, out);
}

/**
This function found in impl {(libcrux_ml_dsa::pre_hash::PreHash<256: usize> for
libcrux_ml_dsa::pre_hash::SHAKE128_PH)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.pre_hash.hash_bd
with types libcrux_ml_dsa_hash_functions_portable_Shake128
with const generics

*/
static KRML_MUSTINLINE void libcrux_ml_dsa_pre_hash_hash_bd_54(
    Eurydice_slice message, uint8_t ret[256U]) {
  uint8_t output[256U] = {0U};
  libcrux_ml_dsa_hash_functions_portable_shake128_a0_6b(message, output);
  memcpy(ret, output, (size_t)256U * sizeof(uint8_t));
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.sign_pre_hashed
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
libcrux_ml_dsa_hash_functions_portable_Shake256Xof,
libcrux_ml_dsa_hash_functions_portable_Shake256X4,
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
static KRML_MUSTINLINE Result_2e
libcrux_ml_dsa_ml_dsa_generic_sign_pre_hashed_da(uint8_t *signing_key,
                                                 Eurydice_slice message,
                                                 Eurydice_slice context,
                                                 uint8_t randomness[32U]) {
  Result_2e uu____0;
  if (Eurydice_slice_len(context, uint8_t) >
      LIBCRUX_ML_DSA_CONSTANTS_CONTEXT_MAX_LEN) {
    uu____0 = (CLITERAL(Result_2e){
        .tag = Err,
        .val = {.case_Err = libcrux_ml_dsa_types_ContextTooLongError}});
  } else {
    uint8_t pre_hashed_message[256U];
    libcrux_ml_dsa_pre_hash_hash_bd_54(message, pre_hashed_message);
    Eurydice_slice uu____1 = context;
    Option_30 lit;
    lit.tag = Some;
    uint8_t ret[11U];
    libcrux_ml_dsa_pre_hash_oid_bd(ret);
    memcpy(lit.f0, ret, (size_t)11U * sizeof(uint8_t));
    Result_a8 uu____2 = libcrux_ml_dsa_pre_hash_new_45(uu____1, lit);
    if (uu____2.tag == Ok) {
      libcrux_ml_dsa_pre_hash_DomainSeparationContext dsc = uu____2.val.case_Ok;
      libcrux_ml_dsa_pre_hash_DomainSeparationContext
          domain_separation_context = dsc;
      uint8_t *uu____3 = signing_key;
      Eurydice_slice uu____4 =
          Eurydice_array_to_slice((size_t)256U, pre_hashed_message, uint8_t);
      Option_84 uu____5 = {.tag = Some, .f0 = domain_separation_context};
      /* Passing arrays by value in Rust generates a copy in C */
      uint8_t copy_of_randomness[32U];
      memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
      uu____0 = libcrux_ml_dsa_ml_dsa_generic_sign_internal_3f(
          uu____3, uu____4, uu____5, copy_of_randomness);
    } else {
      uu____0 = (CLITERAL(Result_2e){
          .tag = Err,
          .val = {.case_Err = libcrux_ml_dsa_types_ContextTooLongError}});
    }
  }
  return uu____0;
}

/**
 Sign (pre-hashed).
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.portable.sign_pre_hashed_shake128
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
static inline Result_2e
libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_sign_pre_hashed_shake128_f3(
    uint8_t *signing_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t randomness[32U]) {
  uint8_t *uu____0 = signing_key;
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_sign_pre_hashed_da(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
 Generate a HashML-DSA-65 Signature, with a SHAKE128 pre-hashing

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
static inline Result_2e
libcrux_ml_dsa_ml_dsa_65_portable_sign_pre_hashed_shake128(
    libcrux_ml_dsa_types_MLDSASigningKey_22 *signing_key,
    Eurydice_slice message, Eurydice_slice context, uint8_t randomness[32U]) {
  uint8_t *uu____0 = libcrux_ml_dsa_types_as_ref_9b_09(signing_key);
  Eurydice_slice uu____1 = message;
  Eurydice_slice uu____2 = context;
  /* Passing arrays by value in Rust generates a copy in C */
  uint8_t copy_of_randomness[32U];
  memcpy(copy_of_randomness, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_sign_pre_hashed_shake128_f3(
      uu____0, uu____1, uu____2, copy_of_randomness);
}

/**
A monomorphic instance of K.
with types uint8_t[32size_t], libcrux_ml_dsa_polynomial_PolynomialRingElement
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[6size_t]

*/
typedef struct tuple_93_s {
  uint8_t fst[32U];
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b snd[6U];
} tuple_93;

/**
A monomorphic instance of libcrux_ml_dsa.encoding.t1.deserialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics

*/
static inline void libcrux_ml_dsa_encoding_t1_deserialize_ba(
    Eurydice_slice serialized,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *result) {
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, result->simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_t1_deserialize_36(
            Eurydice_slice_subslice2(serialized, i0 * (size_t)10U,
                                     (i0 + (size_t)1U) * (size_t)10U, uint8_t));
    result->simd_units[i0] = uu____0;
  }
}

/**
A monomorphic instance of libcrux_ml_dsa.encoding.verification_key.deserialize
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- VERIFICATION_KEY_SIZE= 1952
*/
static KRML_MUSTINLINE tuple_93
libcrux_ml_dsa_encoding_verification_key_deserialize_2f(uint8_t *serialized) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    t1[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  Eurydice_slice_uint8_t_x2 uu____0 = Eurydice_slice_split_at(
      Eurydice_array_to_slice((size_t)1952U, serialized, uint8_t),
      LIBCRUX_ML_DSA_CONSTANTS_SEED_FOR_A_SIZE, uint8_t,
      Eurydice_slice_uint8_t_x2);
  Eurydice_slice seed_for_A = uu____0.fst;
  Eurydice_slice serialized_remaining = uu____0.snd;
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_encoding_t1_deserialize_ba(
        Eurydice_slice_subslice2(
            serialized_remaining,
            i0 * LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T1S_SIZE,
            (i0 + (size_t)1U) *
                LIBCRUX_ML_DSA_CONSTANTS_RING_ELEMENT_OF_T1S_SIZE,
            uint8_t),
        &t1[i0]);
  }
  uint8_t uu____1[32U];
  Result_fb dst;
  Eurydice_slice_to_array2(&dst, seed_for_A, Eurydice_slice, uint8_t[32U]);
  unwrap_26_b3(dst, uu____1);
  /* Passing arrays by value in Rust generates a copy in C */
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t1[6U];
  memcpy(
      copy_of_t1, t1,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  tuple_93 lit;
  memcpy(lit.fst, uu____1, (size_t)32U * sizeof(uint8_t));
  memcpy(
      lit.snd, copy_of_t1,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  return lit;
}

/**
A monomorphic instance of core.result.Result
with types libcrux_ml_dsa_encoding_signature_Signature
libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit[[$6size_t]][[$5size_t]][[$48size_t]],
libcrux_ml_dsa_types_VerificationError

*/
typedef struct Result_ef_s {
  Result_a9_tags tag;
  union {
    libcrux_ml_dsa_encoding_signature_Signature_44 case_Ok;
    libcrux_ml_dsa_types_VerificationError case_Err;
  } val;
} Result_ef;

/**
This function found in impl
{libcrux_ml_dsa::encoding::signature::Signature<SIMDUnit, COMMITMENT_HASH_SIZE,
COLUMNS_IN_A, ROWS_IN_A>[TraitClause@0, TraitClause@1]}
*/
/**
A monomorphic instance of libcrux_ml_dsa.encoding.signature.deserialize_92
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- COMMITMENT_HASH_SIZE= 48
- COLUMNS_IN_A= 5
- ROWS_IN_A= 6
- GAMMA1_EXPONENT= 19
- GAMMA1_RING_ELEMENT_SIZE= 640
- MAX_ONES_IN_HINT= 55
- SIGNATURE_SIZE= 3309
*/
static KRML_MUSTINLINE Result_ef
libcrux_ml_dsa_encoding_signature_deserialize_92_76(uint8_t *serialized) {
  Eurydice_slice_uint8_t_x2 uu____0 = Eurydice_slice_split_at(
      Eurydice_array_to_slice((size_t)3309U, serialized, uint8_t), (size_t)48U,
      uint8_t, Eurydice_slice_uint8_t_x2);
  Eurydice_slice commitment_hash = uu____0.fst;
  Eurydice_slice rest_of_serialized = uu____0.snd;
  Eurydice_slice_uint8_t_x2 uu____1 =
      Eurydice_slice_split_at(rest_of_serialized, (size_t)640U * (size_t)5U,
                              uint8_t, Eurydice_slice_uint8_t_x2);
  Eurydice_slice signer_response_serialized = uu____1.fst;
  Eurydice_slice hint_serialized = uu____1.snd;
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b signer_response[5U];
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    signer_response[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U; i < (size_t)5U; i++) {
    size_t i0 = i;
    libcrux_ml_dsa_encoding_gamma1_deserialize_61(
        Eurydice_slice_subslice2(signer_response_serialized, i0 * (size_t)640U,
                                 (i0 + (size_t)1U) * (size_t)640U, uint8_t),
        &signer_response[i0]);
  }
  int32_t hint[6U][256U] = {{0U}};
  size_t previous_true_hints_seen = (size_t)0U;
  size_t i = (size_t)0U;
  bool malformed_hint = false;
  while (true) {
    if (i < (size_t)6U) {
      if (malformed_hint) {
        break;
      } else {
        size_t current_true_hints_seen = (size_t)Eurydice_slice_index(
            hint_serialized, (size_t)55U + i, uint8_t, uint8_t *);
        size_t j;
        bool uu____2;
        bool uu____3;
        size_t uu____4;
        size_t uu____5;
        bool uu____6;
        size_t uu____7;
        size_t uu____8;
        bool uu____9;
        uint8_t uu____10;
        size_t uu____11;
        uint8_t uu____12;
        size_t uu____13;
        size_t uu____14;
        bool uu____15;
        size_t uu____16;
        size_t uu____17;
        uint8_t uu____18;
        size_t uu____19;
        bool uu____20;
        size_t uu____21;
        if (!(current_true_hints_seen < previous_true_hints_seen)) {
          if (!(previous_true_hints_seen > (size_t)55U)) {
            j = previous_true_hints_seen;
            while (true) {
              uu____2 = malformed_hint;
              if (uu____2) {
                break;
              } else {
                uu____4 = j;
                uu____5 = current_true_hints_seen;
                uu____3 = uu____4 < uu____5;
                if (uu____3) {
                  uu____7 = j;
                  uu____8 = previous_true_hints_seen;
                  uu____6 = uu____7 > uu____8;
                  if (uu____6) {
                    uu____11 = j;
                    uu____10 = Eurydice_slice_index(hint_serialized, uu____11,
                                                    uint8_t, uint8_t *);
                    uu____14 = j;
                    uu____13 = uu____14 - (size_t)1U;
                    uu____12 = Eurydice_slice_index(hint_serialized, uu____13,
                                                    uint8_t, uint8_t *);
                    uu____9 = uu____10 <= uu____12;
                    if (uu____9) {
                      malformed_hint = true;
                      uu____15 = malformed_hint;
                      if (!uu____15) {
                        uu____16 = i;
                        uu____19 = j;
                        uu____18 = Eurydice_slice_index(
                            hint_serialized, uu____19, uint8_t, uint8_t *);
                        uu____17 = (size_t)uu____18;
                        hint[uu____16][uu____17] = (int32_t)1;
                        j++;
                      }
                      continue;
                    }
                  }
                  uu____15 = malformed_hint;
                  if (!uu____15) {
                    uu____16 = i;
                    uu____19 = j;
                    uu____18 = Eurydice_slice_index(hint_serialized, uu____19,
                                                    uint8_t, uint8_t *);
                    uu____17 = (size_t)uu____18;
                    hint[uu____16][uu____17] = (int32_t)1;
                    j++;
                  }
                } else {
                  break;
                }
              }
            }
            uu____20 = malformed_hint;
            if (!uu____20) {
              uu____21 = current_true_hints_seen;
              previous_true_hints_seen = uu____21;
              i++;
            }
            continue;
          }
        }
        malformed_hint = true;
        j = previous_true_hints_seen;
        while (true) {
          uu____2 = malformed_hint;
          if (uu____2) {
            break;
          } else {
            uu____4 = j;
            uu____5 = current_true_hints_seen;
            uu____3 = uu____4 < uu____5;
            if (uu____3) {
              uu____7 = j;
              uu____8 = previous_true_hints_seen;
              uu____6 = uu____7 > uu____8;
              if (uu____6) {
                uu____11 = j;
                uu____10 = Eurydice_slice_index(hint_serialized, uu____11,
                                                uint8_t, uint8_t *);
                uu____14 = j;
                uu____13 = uu____14 - (size_t)1U;
                uu____12 = Eurydice_slice_index(hint_serialized, uu____13,
                                                uint8_t, uint8_t *);
                uu____9 = uu____10 <= uu____12;
                if (uu____9) {
                  malformed_hint = true;
                  uu____15 = malformed_hint;
                  if (!uu____15) {
                    uu____16 = i;
                    uu____19 = j;
                    uu____18 = Eurydice_slice_index(hint_serialized, uu____19,
                                                    uint8_t, uint8_t *);
                    uu____17 = (size_t)uu____18;
                    hint[uu____16][uu____17] = (int32_t)1;
                    j++;
                  }
                  continue;
                }
              }
              uu____15 = malformed_hint;
              if (!uu____15) {
                uu____16 = i;
                uu____19 = j;
                uu____18 = Eurydice_slice_index(hint_serialized, uu____19,
                                                uint8_t, uint8_t *);
                uu____17 = (size_t)uu____18;
                hint[uu____16][uu____17] = (int32_t)1;
                j++;
              }
            } else {
              break;
            }
          }
        }
        uu____20 = malformed_hint;
        if (!uu____20) {
          uu____21 = current_true_hints_seen;
          previous_true_hints_seen = uu____21;
          i++;
        }
      }
    } else {
      break;
    }
  }
  i = previous_true_hints_seen;
  while (true) {
    if (i < (size_t)55U) {
      if (malformed_hint) {
        break;
      } else {
        if (Eurydice_slice_index(hint_serialized, i, uint8_t, uint8_t *) !=
            0U) {
          malformed_hint = true;
        }
        i++;
      }
    } else {
      break;
    }
  }
  Result_ef uu____22;
  if (malformed_hint) {
    uu____22 = (CLITERAL(Result_ef){
        .tag = Err,
        .val = {.case_Err = libcrux_ml_dsa_types_MalformedHintError}});
  } else {
    uint8_t uu____23[48U];
    Result_ae dst;
    Eurydice_slice_to_array2(&dst, commitment_hash, Eurydice_slice,
                             uint8_t[48U]);
    unwrap_26_28(dst, uu____23);
    /* Passing arrays by value in Rust generates a copy in C */
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
        copy_of_signer_response[5U];
    memcpy(copy_of_signer_response, signer_response,
           (size_t)5U *
               sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
    /* Passing arrays by value in Rust generates a copy in C */
    int32_t copy_of_hint[6U][256U];
    memcpy(copy_of_hint, hint, (size_t)6U * sizeof(int32_t[256U]));
    Result_ef lit;
    lit.tag = Ok;
    memcpy(lit.val.case_Ok.commitment_hash, uu____23,
           (size_t)48U * sizeof(uint8_t));
    memcpy(lit.val.case_Ok.signer_response, copy_of_signer_response,
           (size_t)5U *
               sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
    memcpy(lit.val.case_Ok.hint, copy_of_hint,
           (size_t)6U * sizeof(int32_t[256U]));
    uu____22 = lit;
  }
  return uu____22;
}

/**
A monomorphic instance of
libcrux_ml_dsa.simd.portable.arithmetic.shift_left_then_reduce with const
generics
- SHIFT_BY= 13
*/
static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_arithmetic_shift_left_then_reduce_84(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit out =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, simd_unit.coefficients, int32_t),
                              int32_t);
       i++) {
    size_t i0 = i;
    out.coefficients[i0] =
        libcrux_ml_dsa_simd_portable_arithmetic_reduce_element(
            simd_unit.coefficients[i0] << (uint32_t)(int32_t)13);
  }
  return out;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.shift_left_then_reduce_36
with const generics
- SHIFT_BY= 13
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_shift_left_then_reduce_36_84(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit) {
  return libcrux_ml_dsa_simd_portable_arithmetic_shift_left_then_reduce_84(
      simd_unit);
}

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.shift_left_then_reduce
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- SHIFT_BY= 13
*/
static KRML_MUSTINLINE libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
libcrux_ml_dsa_arithmetic_shift_left_then_reduce_b9(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b out =
      libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)32U, re.simd_units,
                   libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
               libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *simd_unit =
        &re.simd_units[i0];
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
        libcrux_ml_dsa_simd_portable_shift_left_then_reduce_36_84(
            simd_unit[0U]);
    out.simd_units[i0] = uu____0;
  }
  return out;
}

/**
 Compute InvertNTT(Â ◦ ẑ - ĉ ◦ NTT(t₁2ᵈ))
*/
/**
A monomorphic instance of libcrux_ml_dsa.matrix.compute_w_approx
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- ROWS_IN_A= 6
- COLUMNS_IN_A= 5
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_matrix_compute_w_approx_2f(
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b (*A_as_ntt)[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b signer_response[5U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
        verifier_challenge_as_ntt,
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1[6U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(
               Eurydice_array_to_slice(
                   (size_t)5U, signer_response,
                   libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
               libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
       i++) {
    size_t i0 = i;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____0 =
        libcrux_ml_dsa_ntt_ntt_ba(signer_response[i0]);
    signer_response[i0] = uu____0;
  }
  for (size_t i0 = (size_t)0U;
       i0 < Eurydice_slice_len(
                Eurydice_array_to_slice(
                    (size_t)6U, A_as_ntt,
                    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]),
                libcrux_ml_dsa_polynomial_PolynomialRingElement_9b[5U]);
       i0++) {
    size_t i1 = i0;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *row = A_as_ntt[i1];
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)5U, row,
                     libcrux_ml_dsa_polynomial_PolynomialRingElement_9b),
                 libcrux_ml_dsa_polynomial_PolynomialRingElement_9b);
         i++) {
      size_t j = i;
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b *ring_element =
          &row[j];
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b product =
          libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(ring_element,
                                                        &signer_response[j]);
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____1 =
          libcrux_ml_dsa_polynomial_add_ff_ba(&result[i1], &product);
      result[i1] = uu____1;
    }
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1_shifted =
        libcrux_ml_dsa_arithmetic_shift_left_then_reduce_b9(t1[i1]);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1_shifted0 =
        libcrux_ml_dsa_ntt_ntt_ba(t1_shifted);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
        challenge_times_t1_shifted =
            libcrux_ml_dsa_ntt_ntt_multiply_montgomery_ba(
                &verifier_challenge_as_ntt, &t1_shifted0);
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____2 =
        libcrux_ml_dsa_ntt_invert_ntt_montgomery_ba(
            libcrux_ml_dsa_polynomial_subtract_ff_ba(
                &result[i1], &challenge_times_t1_shifted));
    result[i1] = uu____2;
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.arithmetic.use_one_hint
with const generics
- GAMMA2= 261888
*/
static KRML_MUSTINLINE int32_t
libcrux_ml_dsa_simd_portable_arithmetic_use_one_hint_80(int32_t r,
                                                        int32_t hint) {
  int32_t_x2 uu____0 =
      libcrux_ml_dsa_simd_portable_arithmetic_decompose_element_80(r);
  int32_t r0 = uu____0.fst;
  int32_t r1 = uu____0.snd;
  int32_t uu____1;
  if (hint == (int32_t)0) {
    uu____1 = r1;
  } else if (r0 > (int32_t)0) {
    uu____1 = (r1 + hint) & (int32_t)15;
  } else {
    uu____1 = (r1 - hint) & (int32_t)15;
  }
  return uu____1;
}

/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.arithmetic.use_hint
with const generics
- GAMMA2= 261888
*/
static KRML_MUSTINLINE libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_arithmetic_use_hint_80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit hint) {
  libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit result =
      libcrux_ml_dsa_simd_portable_vector_type_ZERO();
  for (size_t i = (size_t)0U;
       i < Eurydice_slice_len(Eurydice_array_to_slice(
                                  (size_t)8U, result.coefficients, int32_t),
                              int32_t);
       i++) {
    size_t i0 = i;
    int32_t uu____0 = libcrux_ml_dsa_simd_portable_arithmetic_use_one_hint_80(
        simd_unit.coefficients[i0], hint.coefficients[i0]);
    result.coefficients[i0] = uu____0;
  }
  return result;
}

/**
This function found in impl {(libcrux_ml_dsa::simd::traits::Operations for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
/**
A monomorphic instance of libcrux_ml_dsa.simd.portable.use_hint_36
with const generics
- GAMMA2= 261888
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_use_hint_36_80(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit simd_unit,
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit hint) {
  return libcrux_ml_dsa_simd_portable_arithmetic_use_hint_80(simd_unit, hint);
}

/**
A monomorphic instance of libcrux_ml_dsa.arithmetic.use_hint
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
with const generics
- DIMENSION= 6
- GAMMA2= 261888
*/
static KRML_MUSTINLINE void libcrux_ml_dsa_arithmetic_use_hint_2f(
    int32_t hint[6U][256U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b re_vector[6U],
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b ret[6U]) {
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b result[6U];
  for (size_t i = (size_t)0U; i < (size_t)6U; i++) {
    result[i] = libcrux_ml_dsa_polynomial_ZERO_ff_ba();
  }
  for (size_t i0 = (size_t)0U; i0 < (size_t)6U; i0++) {
    size_t i1 = i0;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b hint_simd =
        libcrux_ml_dsa_polynomial_from_i32_array_ff_ba(
            Eurydice_array_to_slice((size_t)256U, hint[i1], int32_t));
    for (size_t i = (size_t)0U;
         i < Eurydice_slice_len(
                 Eurydice_array_to_slice(
                     (size_t)32U, result->simd_units,
                     libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit),
                 libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit);
         i++) {
      size_t j = i;
      libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit uu____0 =
          libcrux_ml_dsa_simd_portable_use_hint_36_80(
              re_vector[i1].simd_units[j], hint_simd.simd_units[j]);
      result[i1].simd_units[j] = uu____0;
    }
  }
  memcpy(
      ret, result,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
}

/**
 The internal verification API.

 If no `domain_separation_context` is supplied, it is assumed that
 `message` already contains the domain separation.
*/
/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.verify_internal
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
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
static KRML_MUSTINLINE Result_41
libcrux_ml_dsa_ml_dsa_generic_verify_internal_51(
    uint8_t *verification_key_serialized, Eurydice_slice message,
    Option_84 domain_separation_context, uint8_t *signature_serialized) {
  tuple_93 uu____0 = libcrux_ml_dsa_encoding_verification_key_deserialize_2f(
      verification_key_serialized);
  uint8_t seed_for_A[32U];
  memcpy(seed_for_A, uu____0.fst, (size_t)32U * sizeof(uint8_t));
  libcrux_ml_dsa_polynomial_PolynomialRingElement_9b t1[6U];
  memcpy(
      t1, uu____0.snd,
      (size_t)6U * sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
  Result_ef uu____1 =
      libcrux_ml_dsa_encoding_signature_deserialize_92_76(signature_serialized);
  Result_41 uu____2;
  if (uu____1.tag == Ok) {
    libcrux_ml_dsa_encoding_signature_Signature_44 s = uu____1.val.case_Ok;
    libcrux_ml_dsa_encoding_signature_Signature_44 signature = s;
    libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____3[5U];
    memcpy(uu____3, signature.signer_response,
           (size_t)5U *
               sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
    if (libcrux_ml_dsa_arithmetic_vector_infinity_norm_exceeds_4f(
            uu____3, ((int32_t)2 << (uint32_t)(size_t)19U) - (int32_t)196)) {
      uu____2 = (CLITERAL(Result_41){
          .tag = Err,
          .f0 = libcrux_ml_dsa_types_SignerResponseExceedsBoundError});
    } else {
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b A_as_ntt[6U][5U];
      uint8_t ret[34U];
      libcrux_ml_dsa_utils_into_padded_array_b6(
          Eurydice_array_to_slice((size_t)32U, seed_for_A, uint8_t), ret);
      libcrux_ml_dsa_samplex4_portable_matrix_A_36_2f(ret, A_as_ntt);
      uint8_t verification_key_hash[64U] = {0U};
      libcrux_ml_dsa_hash_functions_portable_shake256_5c_24(
          Eurydice_array_to_slice((size_t)1952U, verification_key_serialized,
                                  uint8_t),
          verification_key_hash);
      uint8_t message_representative[64U] = {0U};
      uint8_t uu____4[64U];
      memcpy(uu____4, verification_key_hash, (size_t)64U * sizeof(uint8_t));
      libcrux_ml_dsa_ml_dsa_generic_derive_message_representative_7b(
          uu____4, domain_separation_context, message, message_representative);
      uint8_t uu____5[48U];
      memcpy(uu____5, signature.commitment_hash, (size_t)48U * sizeof(uint8_t));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b
          verifier_challenge_as_ntt = libcrux_ml_dsa_ntt_ntt_ba(
              libcrux_ml_dsa_sample_sample_challenge_ring_element_83(uu____5));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b(*uu____6)[5U] =
          A_as_ntt;
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____7[5U];
      memcpy(uu____7, signature.signer_response,
             (size_t)5U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b uu____8 =
          verifier_challenge_as_ntt;
      /* Passing arrays by value in Rust generates a copy in C */
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_t1[6U];
      memcpy(copy_of_t1, t1,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b w_approx[6U];
      libcrux_ml_dsa_matrix_compute_w_approx_2f(uu____6, uu____7, uu____8,
                                                copy_of_t1, w_approx);
      uint8_t commitment_hash[48U] = {0U};
      int32_t uu____10[6U][256U];
      memcpy(uu____10, signature.hint, (size_t)6U * sizeof(int32_t[256U]));
      /* Passing arrays by value in Rust generates a copy in C */
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_w_approx[6U];
      memcpy(copy_of_w_approx, w_approx,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b commitment[6U];
      libcrux_ml_dsa_arithmetic_use_hint_2f(uu____10, copy_of_w_approx,
                                            commitment);
      /* Passing arrays by value in Rust generates a copy in C */
      libcrux_ml_dsa_polynomial_PolynomialRingElement_9b copy_of_commitment[6U];
      memcpy(copy_of_commitment, commitment,
             (size_t)6U *
                 sizeof(libcrux_ml_dsa_polynomial_PolynomialRingElement_9b));
      uint8_t commitment_serialized[768U];
      libcrux_ml_dsa_encoding_commitment_serialize_vector_5d(
          copy_of_commitment, commitment_serialized);
      libcrux_sha3_portable_incremental_Shake256Xof shake =
          libcrux_ml_dsa_hash_functions_portable_init_83();
      libcrux_ml_dsa_hash_functions_portable_absorb_83(
          &shake, Eurydice_array_to_slice((size_t)64U, message_representative,
                                          uint8_t));
      libcrux_ml_dsa_hash_functions_portable_absorb_final_83(
          &shake, Eurydice_array_to_slice((size_t)768U, commitment_serialized,
                                          uint8_t));
      libcrux_ml_dsa_hash_functions_portable_squeeze_83(
          &shake,
          Eurydice_array_to_slice((size_t)48U, commitment_hash, uint8_t));
      if (core_array_equality___core__cmp__PartialEq__Array_U__N___for__Array_T__N____eq(
              (size_t)48U, signature.commitment_hash, commitment_hash, uint8_t,
              uint8_t, bool)) {
        uu____2 = (CLITERAL(Result_41){.tag = Ok});
      } else {
        uu____2 = (CLITERAL(Result_41){
            .tag = Err,
            .f0 = libcrux_ml_dsa_types_CommitmentHashesDontMatchError});
      }
    }
  } else {
    libcrux_ml_dsa_types_VerificationError e = uu____1.val.case_Err;
    uu____2 = (CLITERAL(Result_41){.tag = Err, .f0 = e});
  }
  return uu____2;
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.verify
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
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
static KRML_MUSTINLINE Result_41 libcrux_ml_dsa_ml_dsa_generic_verify_51(
    uint8_t *verification_key_serialized, Eurydice_slice message,
    Eurydice_slice context, uint8_t *signature_serialized) {
  Result_a8 uu____0 = libcrux_ml_dsa_pre_hash_new_45(
      context, (CLITERAL(Option_30){.tag = None}));
  Result_41 uu____1;
  if (uu____0.tag == Ok) {
    libcrux_ml_dsa_pre_hash_DomainSeparationContext dsc = uu____0.val.case_Ok;
    libcrux_ml_dsa_pre_hash_DomainSeparationContext domain_separation_context =
        dsc;
    uu____1 = libcrux_ml_dsa_ml_dsa_generic_verify_internal_51(
        verification_key_serialized, message,
        (CLITERAL(Option_84){.tag = Some, .f0 = domain_separation_context}),
        signature_serialized);
  } else {
    uu____1 = (CLITERAL(Result_41){
        .tag = Err,
        .f0 = libcrux_ml_dsa_types_VerificationContextTooLongError});
  }
  return uu____1;
}

/**
 Verify.
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.portable.verify with const generics
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
static inline Result_41
libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_verify_01(
    uint8_t *verification_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_verify_51(verification_key, message,
                                                 context, signature);
}

/**
 Verify an ML-DSA-65 Signature

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
static inline Result_41 libcrux_ml_dsa_ml_dsa_65_portable_verify(
    libcrux_ml_dsa_types_MLDSAVerificationKey_ea *verification_key,
    Eurydice_slice message, Eurydice_slice context,
    libcrux_ml_dsa_ml_dsa_65_MLDSA65Signature *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_verify_01(
      libcrux_ml_dsa_types_as_ref_66_97(verification_key), message, context,
      libcrux_ml_dsa_types_as_ref_8f_fa(signature));
}

/**
A monomorphic instance of libcrux_ml_dsa.ml_dsa_generic.verify_pre_hashed
with types libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit,
libcrux_ml_dsa_samplex4_portable_PortableSampler,
libcrux_ml_dsa_hash_functions_portable_Shake128,
libcrux_ml_dsa_hash_functions_portable_Shake128X4,
libcrux_ml_dsa_hash_functions_portable_Shake256,
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
static KRML_MUSTINLINE Result_41
libcrux_ml_dsa_ml_dsa_generic_verify_pre_hashed_3b(
    uint8_t *verification_key_serialized, Eurydice_slice message,
    Eurydice_slice context, uint8_t *signature_serialized) {
  uint8_t pre_hashed_message[256U];
  libcrux_ml_dsa_pre_hash_hash_bd_54(message, pre_hashed_message);
  Eurydice_slice uu____0 = context;
  Option_30 lit;
  lit.tag = Some;
  uint8_t ret[11U];
  libcrux_ml_dsa_pre_hash_oid_bd(ret);
  memcpy(lit.f0, ret, (size_t)11U * sizeof(uint8_t));
  Result_a8 uu____1 = libcrux_ml_dsa_pre_hash_new_45(uu____0, lit);
  Result_41 uu____2;
  if (uu____1.tag == Ok) {
    libcrux_ml_dsa_pre_hash_DomainSeparationContext dsc = uu____1.val.case_Ok;
    libcrux_ml_dsa_pre_hash_DomainSeparationContext domain_separation_context =
        dsc;
    uu____2 = libcrux_ml_dsa_ml_dsa_generic_verify_internal_51(
        verification_key_serialized,
        Eurydice_array_to_slice((size_t)256U, pre_hashed_message, uint8_t),
        (CLITERAL(Option_84){.tag = Some, .f0 = domain_separation_context}),
        signature_serialized);
  } else {
    uu____2 = (CLITERAL(Result_41){
        .tag = Err,
        .f0 = libcrux_ml_dsa_types_VerificationContextTooLongError});
  }
  return uu____2;
}

/**
 Verify (pre-hashed with SHAKE-128).
*/
/**
A monomorphic instance of
libcrux_ml_dsa.ml_dsa_generic.instantiations.portable.verify_pre_hashed_shake128
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
static inline Result_41
libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_verify_pre_hashed_shake128_01(
    uint8_t *verification_key, Eurydice_slice message, Eurydice_slice context,
    uint8_t *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_verify_pre_hashed_3b(
      verification_key, message, context, signature);
}

/**
 Verify a HashML-DSA-65 Signature, with a SHAKE128 pre-hashing

 The parameter `context` is used for domain separation
 and is a byte string of length at most 255 bytes. It
 may also be empty.
*/
static inline Result_41
libcrux_ml_dsa_ml_dsa_65_portable_verify_pre_hashed_shake128(
    libcrux_ml_dsa_types_MLDSAVerificationKey_ea *verification_key,
    Eurydice_slice message, Eurydice_slice context,
    libcrux_ml_dsa_ml_dsa_65_MLDSA65Signature *signature) {
  return libcrux_ml_dsa_ml_dsa_generic_instantiations_portable_verify_pre_hashed_shake128_01(
      libcrux_ml_dsa_types_as_ref_66_97(verification_key), message, context,
      libcrux_ml_dsa_types_as_ref_8f_fa(signature));
}

#define LIBCRUX_ML_DSA_PRE_HASH_PRE_HASH_OID_LEN ((size_t)11U)

typedef uint8_t libcrux_ml_dsa_pre_hash_PreHashOID[11U];

/**
This function found in impl
{(core::convert::From<libcrux_ml_dsa::pre_hash::DomainSeparationError> for
libcrux_ml_dsa::types::SigningError)#2}
*/
static inline libcrux_ml_dsa_types_SigningError libcrux_ml_dsa_pre_hash_from_4b(
    libcrux_ml_dsa_pre_hash_DomainSeparationError e) {
  return libcrux_ml_dsa_types_ContextTooLongError;
}

/**
This function found in impl
{(core::convert::From<libcrux_ml_dsa::pre_hash::DomainSeparationError> for
libcrux_ml_dsa::types::VerificationError)#3}
*/
static inline libcrux_ml_dsa_types_VerificationError
libcrux_ml_dsa_pre_hash_from_b6(
    libcrux_ml_dsa_pre_hash_DomainSeparationError e) {
  return libcrux_ml_dsa_types_VerificationContextTooLongError;
}

/**
This function found in impl {(core::clone::Clone for
libcrux_ml_dsa::simd::portable::vector_type::PortableSIMDUnit)}
*/
static inline libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit
libcrux_ml_dsa_simd_portable_vector_type_clone_ae(
    libcrux_ml_dsa_simd_portable_vector_type_PortableSIMDUnit *self) {
  return self[0U];
}

typedef int32_t libcrux_ml_dsa_simd_traits_FieldElementTimesMontgomeryR;

typedef int32_t libcrux_ml_dsa_simd_portable_vector_type_FieldElement;

typedef Result_a8 libcrux_ml_dsa_pre_hash_PreHashResult;

typedef struct libcrux_ml_dsa_hash_functions_portable_Shake128_s {
} libcrux_ml_dsa_hash_functions_portable_Shake128;

#if defined(__cplusplus)
}
#endif

#define __libcrux_mldsa65_portable_H_DEFINED
#endif
