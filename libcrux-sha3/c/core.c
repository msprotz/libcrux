/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_sha3.llbc
  F* version: 58c915a8
  KaRaMeL version: 04cb86b9
 */

#include "internal/core.h"

void
core_result__core__result__Result_T__E___unwrap__uint8_t_8size_t__core_array_TryFromSliceError(
  core_result_Result__uint8_t_8size_t__core_array_TryFromSliceError self,
  uint8_t ret[8U]
)
{
  if (self.tag == core_result_Ok)
  {
    uint8_t f0[8U];
    memcpy(f0, self.val.case_Ok, (size_t)8U * sizeof (uint8_t));
    memcpy(ret, f0, (size_t)8U * sizeof (uint8_t));
  }
  else
  {
    KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "unwrap not Ok");
    KRML_HOST_EXIT(255U);
  }
}
