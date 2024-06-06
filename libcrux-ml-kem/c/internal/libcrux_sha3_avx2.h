/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc --log Phase2.6,Phase2.7
  F* version: 58c915a8
  KaRaMeL version: 40e3a603
 */

#ifndef __internal_libcrux_sha3_avx2_H
#define __internal_libcrux_sha3_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "intrinsics/libcrux_intrinsics_avx2.h"

#include "internal/libcrux_core.h"
#include "../libcrux_sha3_avx2.h"
#include "eurydice_glue.h"

typedef libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
libcrux_sha3_avx2_x4_incremental_KeccakState4;

void
libcrux_sha3_generic_keccak_absorb_final__core_core_arch_x86___m256i_4size_t_168size_t_31uint8_t(
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t *s,
  Eurydice_slice last[4U]
);

void
libcrux_sha3_generic_keccak_squeeze_first_three_blocks__core_core_arch_x86___m256i_4size_t_168size_t(
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t *s,
  Eurydice_slice out[4U]
);

#if defined(__cplusplus)
}
#endif

#define __internal_libcrux_sha3_avx2_H_DEFINED
#endif
