/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /nix/store/c9m211bm84ncjmaxx27ki9dymd4qkwm2-ocaml4.14.1-eurydice-dirty/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc
  F* version: <unknown>
  KaRaMeL version: <unknown>
 */

#ifndef __core_H
#define __core_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"

typedef struct core_ops_range_Range__size_t_s
{
  size_t start;
  size_t end;
}
core_ops_range_Range__size_t;

extern uint8_t Eurydice_bitand_pv_u8(uint8_t *x, uint8_t y);

extern uint8_t Eurydice_shr_pv_u8(uint8_t *x, int32_t y);

#define core_option_None 0
#define core_option_Some 1

typedef uint8_t core_option_Option__size_t_tags;

#if defined(__cplusplus)
}
#endif

#define __core_H_DEFINED
#endif
