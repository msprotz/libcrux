/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc --log Phase2.6,Phase2.7
  F* version: 58c915a8
  KaRaMeL version: 40e3a603
 */

#ifndef __libcrux_sha3_neon_H
#define __libcrux_sha3_neon_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "intrinsics/libcrux_intrinsics_arm64.h"

#include "libcrux_sha3_internal.h"
#include "libcrux_core.h"
#include "eurydice_glue.h"

void libcrux_sha3_neon_sha512(Eurydice_slice digest, Eurydice_slice data);

void libcrux_sha3_neon_sha256(Eurydice_slice digest, Eurydice_slice data);

void
libcrux_sha3_neon_x2_shake256(
  Eurydice_slice input0,
  Eurydice_slice input1,
  Eurydice_slice out0,
  Eurydice_slice out1
);

typedef struct libcrux_sha3_neon_x2_incremental_KeccakState2_s
{ libcrux_sha3_generic_keccak_KeccakState__uint64_t__1size_t state[2U]; }
libcrux_sha3_neon_x2_incremental_KeccakState2;

libcrux_sha3_neon_x2_incremental_KeccakState2
libcrux_sha3_neon_x2_incremental_shake128_init(void);

void
libcrux_sha3_neon_x2_incremental_shake128_absorb_final(
  libcrux_sha3_neon_x2_incremental_KeccakState2 *s,
  Eurydice_slice data0,
  Eurydice_slice data1
);

void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_next_block(
  libcrux_sha3_neon_x2_incremental_KeccakState2 *s,
  Eurydice_slice out0,
  Eurydice_slice out1
);

void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_first_three_blocks(
  libcrux_sha3_neon_x2_incremental_KeccakState2 *s,
  Eurydice_slice out0,
  Eurydice_slice out1
);

void libcrux_sha3_neon_sha224(Eurydice_slice digest, Eurydice_slice data);

void libcrux_sha3_neon_sha384(Eurydice_slice digest, Eurydice_slice data);

#if defined(__cplusplus)
}
#endif

#define __libcrux_sha3_neon_H_DEFINED
#endif
