/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/bhargava/Desktop/repositories/karamel/krml -tmpdir dist/ -skip-compilation obj/FStar_Pervasives_Native.krml obj/FStar_Pervasives.krml obj/FStar_Mul.krml obj/FStar_Squash.krml obj/FStar_Classical.krml obj/FStar_Preorder.krml obj/FStar_Sealed.krml obj/FStar_Range.krml obj/FStar_Calc.krml obj/FStar_StrongExcludedMiddle.krml obj/FStar_Classical_Sugar.krml obj/FStar_List_Tot_Base.krml obj/FStar_List_Tot_Properties.krml obj/FStar_List_Tot.krml obj/FStar_Seq_Base.krml obj/FStar_Seq_Properties.krml obj/FStar_Seq.krml obj/FStar_Math_Lib.krml obj/FStar_Math_Lemmas.krml obj/FStar_BitVector.krml obj/FStar_UInt.krml obj/FStar_UInt32.krml obj/FStar_Int.krml obj/FStar_Int16.krml obj/FStar_Float.krml obj/FStar_Char.krml obj/FStar_Issue.krml obj/FStar_Monotonic_Pure.krml obj/FStar_Sealed_Inhabited.krml obj/FStar_Order.krml obj/FStar_VConfig.krml obj/FStar_Ghost.krml obj/FStar_PropositionalExtensionality.krml obj/FStar_FunctionalExtensionality.krml obj/FStar_Set.krml obj/FStar_ErasedLogic.krml obj/FStar_PredicateExtensionality.krml obj/FStar_TSet.krml obj/FStar_Monotonic_Heap.krml obj/FStar_Heap.krml obj/FStar_Map.krml obj/FStar_Monotonic_Witnessed.krml obj/FStar_Monotonic_HyperHeap.krml obj/FStar_Monotonic_HyperStack.krml obj/FStar_HyperStack.krml obj/FStar_HyperStack_ST.krml obj/FStar_Universe.krml obj/FStar_GSet.krml obj/FStar_ModifiesGen.krml obj/FStar_IndefiniteDescription.krml obj/FStar_BigOps.krml obj/LowStar_Monotonic_Buffer.krml obj/LowStar_Buffer.krml obj/LowStar_BufferOps.krml obj/Spec_Loops.krml obj/FStar_UInt64.krml obj/C_Loops.krml obj/FStar_Int64.krml obj/FStar_Int32.krml obj/FStar_Int8.krml obj/FStar_UInt16.krml obj/FStar_UInt8.krml obj/FStar_Int_Cast.krml obj/FStar_Exn.krml obj/FStar_ST.krml obj/FStar_All.krml obj/FStar_List.krml obj/FStar_BV.krml obj/FStar_UInt128.krml obj/FStar_Int_Cast_Full.krml obj/FStar_Int128.krml obj/Lib_IntTypes.krml obj/Lib_Loops.krml obj/Rust_primitives_Integers.krml obj/Rust_primitives_Arrays.krml obj/Rust_primitives.krml obj/Core_Ops_Index_IndexMut.krml obj/Core_Ops_Index.krml obj/Core_Ops.krml obj/Core_Slice_Iter.krml obj/Core_Slice.krml obj/Rust_primitives_Hax.krml obj/Core_Iter_Adapters_Step_by.krml obj/Core_Iter_Adapters_Enumerate.krml obj/Core_Iter_Traits_Iterator.krml obj/Core_Ops_Range.krml obj/Core_Iter.krml obj/Core_Num_Error.krml obj/Core_Result.krml obj/Core_Num.krml obj/Core.krml obj/Core_Option.krml obj/Core_Panicking.krml obj/Rust_primitives_Hax_Monomorphized_update_at.krml obj/Libcrux_Digest.krml obj/Libcrux_Kem_Kyber_Constants.krml obj/Libcrux_Kem_Kyber_Compress.krml obj/Core_Array.krml obj/Core_Convert.krml obj/Libcrux_Kem_Kyber_Arithmetic.krml obj/Libcrux_Kem_Kyber_Serialize.krml obj/Libcrux_Kem_MLKEM.krml -warn-error @4@5@18 -fparentheses -bundle LowStar.*,Prims -bundle Libcrux.Kem.MLKEM=Rust_primitives.*,Rust_primitives,Core.*,Core,Hax_lib.*,Hax_lib,Libcrux.Kem.Kyber.* -minimal -bundle FStar.* -add-include <stdint.h> -add-include "krml/internal/target.h" -bundle Hacl.Spec.*,Spec.*[rename=Hacl_Spec] -bundle Lib.*[rename=Hacl_Lib] -drop Lib.IntVector.Intrinsics -drop Lib.IntTypes.Intrinsics -drop Lib.IntTypes.Intrinsics_128 -fparentheses -fno-shadow -fcurly-braces -fnoreturn-else -bundle Prims,C.Failure,C,C.String,C.Loops,Spec.Loops,C.Endianness,FStar.*,LowStar.*[rename=Hacl_Krmllib] -bundle Meta.* -minimal -add-early-include <string.h> -add-early-include "krml/internal/types.h" -add-early-include "krml/lowstar_endianness.h" -dmonomorphization
  F* version: fe6dec16
  KaRaMeL version: a7be2a7c
 */

#include "Libcrux_Digest.h"

bool Libcrux_Digest_uu___is_Algorithm_Sha1(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha1:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha224(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha224:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha256(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha256:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha384(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha384:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha512(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha512:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Blake2s(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Blake2s:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Blake2b(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Blake2b:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha3_224_(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha3_224_:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha3_256_(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha3_256_:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha3_384_(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha3_384_:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Libcrux_Digest_uu___is_Algorithm_Sha3_512_(Libcrux_Digest_t_Algorithm projectee)
{
  switch (projectee)
  {
    case Libcrux_Digest_Algorithm_Sha3_512_:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

uint32_t Libcrux_Digest_digest_size(Libcrux_Digest_t_Algorithm mode)
{
  switch (mode)
  {
    case Libcrux_Digest_Algorithm_Sha1:
      {
        return 20U;
      }
    case Libcrux_Digest_Algorithm_Sha224:
      {
        return 28U;
      }
    case Libcrux_Digest_Algorithm_Sha256:
      {
        return 32U;
      }
    case Libcrux_Digest_Algorithm_Sha384:
      {
        return 48U;
      }
    case Libcrux_Digest_Algorithm_Sha512:
      {
        return 64U;
      }
    case Libcrux_Digest_Algorithm_Blake2s:
      {
        return 32U;
      }
    case Libcrux_Digest_Algorithm_Blake2b:
      {
        return 64U;
      }
    case Libcrux_Digest_Algorithm_Sha3_224_:
      {
        return 28U;
      }
    case Libcrux_Digest_Algorithm_Sha3_256_:
      {
        return 32U;
      }
    case Libcrux_Digest_Algorithm_Sha3_384_:
      {
        return 48U;
      }
    case Libcrux_Digest_Algorithm_Sha3_512_:
      {
        return 64U;
      }
    default:
      {
        KRML_HOST_EPRINTF("KaRaMeL incomplete match at %s:%d\n", __FILE__, __LINE__);
        KRML_HOST_EXIT(253U);
      }
  }
}

