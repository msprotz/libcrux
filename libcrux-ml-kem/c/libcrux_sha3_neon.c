/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: e6a9a3d65857f37917f378fd98db7b7b4d0a060f
 * Eurydice: 907fef61b716e094dcd6b41a9a41f0850ac7fd73
 * Karamel: 21c28f3b016868a7cdd715382338bdcd9685a3b4
 * F*: b0961063393215ca65927f017720cb365a193833-dirty
 * Libcrux: 887cc3c3760e64d740774adb301e4bae530126d1
 */

#include "libcrux_sha3_neon.h"

/**
 A portable SHA3 224 implementation.
*/
KRML_MUSTINLINE void libcrux_sha3_neon_sha224(Eurydice_slice digest,
                                              Eurydice_slice data) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 A portable SHA3 256 implementation.
*/
KRML_MUSTINLINE void libcrux_sha3_neon_sha256(Eurydice_slice digest,
                                              Eurydice_slice data) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 A portable SHA3 384 implementation.
*/
KRML_MUSTINLINE void libcrux_sha3_neon_sha384(Eurydice_slice digest,
                                              Eurydice_slice data) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 A portable SHA3 512 implementation.
*/
KRML_MUSTINLINE void libcrux_sha3_neon_sha512(Eurydice_slice digest,
                                              Eurydice_slice data) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Run SHAKE256 on both inputs in parallel.

 Writes the two results into `out0` and `out1`
*/
KRML_MUSTINLINE void libcrux_sha3_neon_x2_shake256(Eurydice_slice input0,
                                                   Eurydice_slice input1,
                                                   Eurydice_slice out0,
                                                   Eurydice_slice out1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Initialise the `KeccakState2`.
*/
KRML_MUSTINLINE libcrux_sha3_neon_x2_incremental_KeccakState
libcrux_sha3_neon_x2_incremental_init(void) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Shake128 absorb `data0` and `data1` in the [`KeccakState`] `s`.
*/
KRML_MUSTINLINE void libcrux_sha3_neon_x2_incremental_shake128_absorb_final(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice data0,
    Eurydice_slice data1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Squeeze 2 times the first three blocks in parallel in the
 [`KeccakState`] and return the output in `out0` and `out1`.
*/
KRML_MUSTINLINE void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_first_three_blocks(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice out0,
    Eurydice_slice out1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Squeeze 2 times the next block in parallel in the
 [`KeccakState`] and return the output in `out0` and `out1`.
*/
KRML_MUSTINLINE void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_next_block(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice out0,
    Eurydice_slice out1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Squeeze five blocks
*/
KRML_MUSTINLINE void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_first_five_blocks(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice out0,
    Eurydice_slice out1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Shake256 absorb `data0` and `data1` in the [`KeccakState`] `s`.
*/
KRML_MUSTINLINE void libcrux_sha3_neon_x2_incremental_shake256_absorb_final(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice data0,
    Eurydice_slice data1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Squeeze block
*/
KRML_MUSTINLINE void
libcrux_sha3_neon_x2_incremental_shake256_squeeze_first_block(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice out0,
    Eurydice_slice out1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}

/**
 Squeeze next block
*/
KRML_MUSTINLINE void
libcrux_sha3_neon_x2_incremental_shake256_squeeze_next_block(
    libcrux_sha3_neon_x2_incremental_KeccakState *s, Eurydice_slice out0,
    Eurydice_slice out1) {
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__,
                    "panic!");
  KRML_HOST_EXIT(255U);
}
