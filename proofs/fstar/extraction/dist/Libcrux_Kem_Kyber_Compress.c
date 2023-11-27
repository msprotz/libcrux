/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/bhargava/Desktop/repositories/karamel/krml -tmpdir dist/ -skip-compilation obj/FStar_Pervasives_Native.krml obj/FStar_Pervasives.krml obj/FStar_Mul.krml obj/FStar_Squash.krml obj/FStar_Classical.krml obj/FStar_Preorder.krml obj/FStar_Sealed.krml obj/FStar_Range.krml obj/FStar_Calc.krml obj/FStar_StrongExcludedMiddle.krml obj/FStar_Classical_Sugar.krml obj/FStar_List_Tot_Base.krml obj/FStar_List_Tot_Properties.krml obj/FStar_List_Tot.krml obj/FStar_Seq_Base.krml obj/FStar_Seq_Properties.krml obj/FStar_Seq.krml obj/FStar_Math_Lib.krml obj/FStar_Math_Lemmas.krml obj/FStar_BitVector.krml obj/FStar_UInt.krml obj/FStar_UInt32.krml obj/FStar_Int.krml obj/FStar_Int16.krml obj/FStar_Float.krml obj/FStar_Char.krml obj/FStar_Issue.krml obj/FStar_Monotonic_Pure.krml obj/FStar_Sealed_Inhabited.krml obj/FStar_Order.krml obj/FStar_VConfig.krml obj/FStar_Ghost.krml obj/FStar_PropositionalExtensionality.krml obj/FStar_FunctionalExtensionality.krml obj/FStar_Set.krml obj/FStar_ErasedLogic.krml obj/FStar_PredicateExtensionality.krml obj/FStar_TSet.krml obj/FStar_Monotonic_Heap.krml obj/FStar_Heap.krml obj/FStar_Map.krml obj/FStar_Monotonic_Witnessed.krml obj/FStar_Monotonic_HyperHeap.krml obj/FStar_Monotonic_HyperStack.krml obj/FStar_HyperStack.krml obj/FStar_HyperStack_ST.krml obj/FStar_Universe.krml obj/FStar_GSet.krml obj/FStar_ModifiesGen.krml obj/FStar_IndefiniteDescription.krml obj/FStar_BigOps.krml obj/LowStar_Monotonic_Buffer.krml obj/LowStar_Buffer.krml obj/LowStar_BufferOps.krml obj/Spec_Loops.krml obj/FStar_UInt64.krml obj/C_Loops.krml obj/FStar_Int64.krml obj/FStar_Int32.krml obj/FStar_Int8.krml obj/FStar_UInt16.krml obj/FStar_UInt8.krml obj/FStar_Int_Cast.krml obj/FStar_Exn.krml obj/FStar_ST.krml obj/FStar_All.krml obj/FStar_List.krml obj/FStar_BV.krml obj/FStar_UInt128.krml obj/FStar_Int_Cast_Full.krml obj/FStar_Int128.krml obj/Lib_IntTypes.krml obj/Lib_Loops.krml obj/Rust_primitives_Integers.krml obj/Rust_primitives_Arrays.krml obj/Rust_primitives.krml obj/Core_Ops_Index_IndexMut.krml obj/Core_Ops_Index.krml obj/Core_Ops.krml obj/Core_Slice_Iter.krml obj/Core_Slice.krml obj/Rust_primitives_Hax.krml obj/Core_Iter_Adapters_Step_by.krml obj/Core_Iter_Adapters_Enumerate.krml obj/Core_Iter_Traits_Iterator.krml obj/Core_Ops_Range.krml obj/Core_Iter.krml obj/Core_Num_Error.krml obj/Core_Result.krml obj/Core_Num.krml obj/Core.krml obj/Core_Option.krml obj/Core_Panicking.krml obj/Rust_primitives_Hax_Monomorphized_update_at.krml obj/Libcrux_Digest.krml obj/Libcrux_Kem_Kyber_Constants.krml obj/Libcrux_Kem_Kyber_Compress.krml obj/Core_Array.krml obj/Core_Convert.krml obj/Libcrux_Kem_Kyber_Arithmetic.krml obj/Libcrux_Kem_Kyber_Serialize.krml -warn-error @4@5@18 -fparentheses -bundle LowStar.*,Prims -bundle Libcrux.Kem.Kyber.Compress=Rust_primitives.*,Rust_primitives,Core.*,Core,Hax_lib.*,Hax_lib,Libcrux.Kem.Kyber.*,Libcrux.Kem.Kyber.Compress -minimal -bundle FStar.* -add-include <stdint.h> -add-include "krml/internal/target.h" -bundle Hacl.Spec.*,Spec.*[rename=Hacl_Spec] -bundle Lib.*[rename=Hacl_Lib] -drop Lib.IntVector.Intrinsics -drop Lib.IntTypes.Intrinsics -drop Lib.IntTypes.Intrinsics_128 -fparentheses -fno-shadow -fcurly-braces -fnoreturn-else -bundle Prims,C.Failure,C,C.String,C.Loops,Spec.Loops,C.Endianness,FStar.*,LowStar.*[rename=Hacl_Krmllib] -bundle Meta.* -minimal -add-early-include <string.h> -add-early-include "krml/internal/types.h" -add-early-include "krml/lowstar_endianness.h" -dmonomorphization
  F* version: fe6dec16
  KaRaMeL version: a7be2a7c
 */

#include "Libcrux_Kem_Kyber_Compress.h"

static int32_t v_FIELD_MODULUS = (int32_t)3329;

uint32_t Libcrux_Kem_Kyber_Compress_get_n_least_significant_bits(uint8_t n, uint32_t value)
{
  return value & ((1U << (uint32_t)n) - 1U);
}

int32_t Libcrux_Kem_Kyber_Compress_compress_q(uint8_t coefficient_bits, uint16_t fe)
{
  uint32_t compressed = (uint32_t)fe << (uint32_t)((uint32_t)coefficient_bits + 1U);
  uint32_t compressed1 = compressed + (uint32_t)v_FIELD_MODULUS;
  uint32_t compressed2 = compressed1 / (uint32_t)(v_FIELD_MODULUS << (uint32_t)(int32_t)1);
  return
    (int32_t)Libcrux_Kem_Kyber_Compress_get_n_least_significant_bits(coefficient_bits, compressed2);
}

int32_t Libcrux_Kem_Kyber_Compress_decompress_q(uint8_t coefficient_bits, int32_t fe)
{
  uint32_t decompressed = (uint32_t)fe * (uint32_t)v_FIELD_MODULUS;
  uint32_t
  decompressed1 = (decompressed << (uint32_t)(int32_t)1) + (1U << (uint32_t)coefficient_bits);
  uint32_t decompressed2 = decompressed1 >> (uint32_t)((uint32_t)coefficient_bits + 1U);
  return (int32_t)decompressed2;
}

