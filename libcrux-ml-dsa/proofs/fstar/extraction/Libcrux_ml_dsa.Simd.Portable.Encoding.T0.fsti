module Libcrux_ml_dsa.Simd.Portable.Encoding.T0
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

val change_t0_interval (t0: i32) : Prims.Pure i32 Prims.l_True (fun _ -> Prims.l_True)

let deserialize__BITS_IN_LOWER_PART_OF_T_MASK: i32 =
  (1l <<! (cast (Libcrux_ml_dsa.Constants.v_BITS_IN_LOWER_PART_OF_T <: usize) <: i32) <: i32) -! 1l

val serialize (simd_unit: Libcrux_ml_dsa.Simd.Portable.Vector_type.t_PortableSIMDUnit)
    : Prims.Pure (t_Array u8 (sz 13)) Prims.l_True (fun _ -> Prims.l_True)

val deserialize (serialized: t_Slice u8)
    : Prims.Pure Libcrux_ml_dsa.Simd.Portable.Vector_type.t_PortableSIMDUnit
      Prims.l_True
      (fun _ -> Prims.l_True)
