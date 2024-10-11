module Libcrux_ml_dsa.Simd.Avx2.Encoding.T0
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

val change_interval (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256)
    : Prims.Pure Libcrux_intrinsics.Avx2_extract.t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

let deserialize__COEFFICIENT_MASK: i32 =
  (Rust_primitives.mk_i32 1 <<! Rust_primitives.mk_i32 13 <: i32) -! Rust_primitives.mk_i32 1

val deserialize (serialized: t_Slice u8)
    : Prims.Pure Libcrux_intrinsics.Avx2_extract.t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val serialize (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256)
    : Prims.Pure (t_Array u8 (Rust_primitives.mk_usize 13)) Prims.l_True (fun _ -> Prims.l_True)
