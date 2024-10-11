module Libcrux_ml_dsa.Simd.Avx2.Encoding.Error
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let deserialize_to_unsigned_when_eta_is_2_ (bytes: t_Slice u8) =
  let _:Prims.unit =
    if true
    then
      let _:Prims.unit =
        Hax_lib.v_assert ((Core.Slice.impl__len #u8 bytes <: usize) =. Rust_primitives.mk_usize 3
            <:
            bool)
      in
      ()
  in
  let bytes_in_simd_unit:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (cast (bytes.[ Rust_primitives.mk_usize 2 ]
            <:
            u8)
        <:
        i32)
      (cast (bytes.[ Rust_primitives.mk_usize 2 ] <: u8) <: i32)
      (((cast (bytes.[ Rust_primitives.mk_usize 2 ] <: u8) <: i32) <<! Rust_primitives.mk_i32 8
          <:
          i32) |.
        (cast (bytes.[ Rust_primitives.mk_usize 1 ] <: u8) <: i32)
        <:
        i32)
      (cast (bytes.[ Rust_primitives.mk_usize 1 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 1 ] <: u8) <: i32)
      (((cast (bytes.[ Rust_primitives.mk_usize 1 ] <: u8) <: i32) <<! Rust_primitives.mk_i32 8
          <:
          i32) |.
        (cast (bytes.[ Rust_primitives.mk_usize 0 ] <: u8) <: i32)
        <:
        i32)
      (cast (bytes.[ Rust_primitives.mk_usize 0 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 0 ] <: u8) <: i32)
  in
  let coefficients:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srlv_epi32 bytes_in_simd_unit
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 5)
          (Rust_primitives.mk_i32 2)
          (Rust_primitives.mk_i32 7)
          (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 1)
          (Rust_primitives.mk_i32 6)
          (Rust_primitives.mk_i32 3)
          (Rust_primitives.mk_i32 0)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  Libcrux_intrinsics.Avx2_extract.mm256_and_si256 coefficients
    (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 deserialize_to_unsigned_when_eta_is_2___COEFFICIENT_MASK

      <:
      Libcrux_intrinsics.Avx2_extract.t_Vec256)

let deserialize_to_unsigned_when_eta_is_4_ (bytes: t_Slice u8) =
  let _:Prims.unit =
    if true
    then
      let _:Prims.unit =
        Hax_lib.v_assert ((Core.Slice.impl__len #u8 bytes <: usize) =. Rust_primitives.mk_usize 4
            <:
            bool)
      in
      ()
  in
  let bytes_in_simd_unit:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (cast (bytes.[ Rust_primitives.mk_usize 3 ]
            <:
            u8)
        <:
        i32)
      (cast (bytes.[ Rust_primitives.mk_usize 3 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 2 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 2 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 1 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 1 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 0 ] <: u8) <: i32)
      (cast (bytes.[ Rust_primitives.mk_usize 0 ] <: u8) <: i32)
  in
  let coefficients:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srlv_epi32 bytes_in_simd_unit
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 0)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  Libcrux_intrinsics.Avx2_extract.mm256_and_si256 coefficients
    (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 deserialize_to_unsigned_when_eta_is_4___COEFFICIENT_MASK

      <:
      Libcrux_intrinsics.Avx2_extract.t_Vec256)

let deserialize_to_unsigned (v_ETA: usize) (serialized: t_Slice u8) =
  match cast (v_ETA <: usize) <: u8 with
  | 2 -> deserialize_to_unsigned_when_eta_is_2_ serialized
  | 4 -> deserialize_to_unsigned_when_eta_is_4_ serialized
  | _ ->
    Rust_primitives.Hax.never_to_any (Core.Panicking.panic "internal error: entered unreachable code"

        <:
        Rust_primitives.Hax.t_Never)

let deserialize (v_ETA: usize) (serialized: t_Slice u8) =
  let unsigned:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    deserialize_to_unsigned v_ETA serialized
  in
  Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (
          cast (v_ETA <: usize) <: i32)
      <:
      Libcrux_intrinsics.Avx2_extract.t_Vec256)
    unsigned

let serialize_when_eta_is_2_
      (v_OUTPUT_SIZE: usize)
      (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256)
     =
  let serialized:t_Array u8 (Rust_primitives.mk_usize 16) =
    Rust_primitives.Hax.repeat (Rust_primitives.mk_u8 0) (Rust_primitives.mk_usize 16)
  in
  let simd_unit_shifted:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32
          serialize_when_eta_is_2___ETA
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
      simd_unit
  in
  let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sllv_epi32 simd_unit_shifted
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 29)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 29)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 29)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 29)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srli_epi64 (Rust_primitives.mk_i32 29) adjacent_2_combined
  in
  let adjacent_4_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_shuffle_epi8 adjacent_2_combined
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi8 (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 8) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 0)
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 8) (Rust_primitives.mk_i8 (-1))
          (Rust_primitives.mk_i8 0)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let adjacent_4_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_madd_epi16 adjacent_4_combined
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi16 (Rust_primitives.mk_i16 0)
          (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0)
          (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0)
          (Rust_primitives.mk_i16 1 <<! Rust_primitives.mk_i32 6 <: i16) (Rust_primitives.mk_i16 1)
          (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0)
          (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0) (Rust_primitives.mk_i16 0)
          (Rust_primitives.mk_i16 1 <<! Rust_primitives.mk_i32 6 <: i16) (Rust_primitives.mk_i16 1)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let adjacent_6_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_permutevar8x32_epi32 adjacent_4_combined
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 0)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let adjacent_6_combined:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
    Libcrux_intrinsics.Avx2_extract.mm256_castsi256_si128 adjacent_6_combined
  in
  let adjacent_6_combined:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
    Libcrux_intrinsics.Avx2_extract.mm_sllv_epi32 adjacent_6_combined
      (Libcrux_intrinsics.Avx2_extract.mm_set_epi32 (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 20)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec128)
  in
  let adjacent_6_combined:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
    Libcrux_intrinsics.Avx2_extract.mm_srli_epi64 (Rust_primitives.mk_i32 20) adjacent_6_combined
  in
  let serialized:t_Array u8 (Rust_primitives.mk_usize 16) =
    Rust_primitives.Hax.Monomorphized_update_at.update_at_range serialized
      ({
          Core.Ops.Range.f_start = Rust_primitives.mk_usize 0;
          Core.Ops.Range.f_end = Rust_primitives.mk_usize 16
        }
        <:
        Core.Ops.Range.t_Range usize)
      (Libcrux_intrinsics.Avx2_extract.mm_storeu_bytes_si128 (serialized.[ {
                Core.Ops.Range.f_start = Rust_primitives.mk_usize 0;
                Core.Ops.Range.f_end = Rust_primitives.mk_usize 16
              }
              <:
              Core.Ops.Range.t_Range usize ]
            <:
            t_Slice u8)
          adjacent_6_combined
        <:
        t_Slice u8)
  in
  Core.Result.impl__unwrap #(t_Array u8 v_OUTPUT_SIZE)
    #Core.Array.t_TryFromSliceError
    (Core.Convert.f_try_into #(t_Slice u8)
        #(t_Array u8 v_OUTPUT_SIZE)
        #FStar.Tactics.Typeclasses.solve
        (serialized.[ {
              Core.Ops.Range.f_start = Rust_primitives.mk_usize 0;
              Core.Ops.Range.f_end = Rust_primitives.mk_usize 3
            }
            <:
            Core.Ops.Range.t_Range usize ]
          <:
          t_Slice u8)
      <:
      Core.Result.t_Result (t_Array u8 v_OUTPUT_SIZE) Core.Array.t_TryFromSliceError)

let serialize_when_eta_is_4_
      (v_OUTPUT_SIZE: usize)
      (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256)
     =
  let serialized:t_Array u8 (Rust_primitives.mk_usize 16) =
    Rust_primitives.Hax.repeat (Rust_primitives.mk_u8 0) (Rust_primitives.mk_usize 16)
  in
  let simd_unit_shifted:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32
          serialize_when_eta_is_4___ETA
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
      simd_unit
  in
  let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sllv_epi32 simd_unit_shifted
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 28)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 28)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 28)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 28)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srli_epi64 (Rust_primitives.mk_i32 28) adjacent_2_combined
  in
  let adjacent_4_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_permutevar8x32_epi32 adjacent_2_combined
      (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 0)
          (Rust_primitives.mk_i32 6)
          (Rust_primitives.mk_i32 2)
          (Rust_primitives.mk_i32 4)
          (Rust_primitives.mk_i32 0)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let adjacent_4_combined:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
    Libcrux_intrinsics.Avx2_extract.mm256_castsi256_si128 adjacent_4_combined
  in
  let adjacent_4_combined:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
    Libcrux_intrinsics.Avx2_extract.mm_shuffle_epi8 adjacent_4_combined
      (Libcrux_intrinsics.Avx2_extract.mm_set_epi8 (Rust_primitives.mk_u8 240)
          (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240)
          (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240)
          (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240)
          (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 240) (Rust_primitives.mk_u8 12)
          (Rust_primitives.mk_u8 4) (Rust_primitives.mk_u8 8) (Rust_primitives.mk_u8 0)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec128)
  in
  let serialized:t_Array u8 (Rust_primitives.mk_usize 16) =
    Rust_primitives.Hax.Monomorphized_update_at.update_at_range serialized
      ({
          Core.Ops.Range.f_start = Rust_primitives.mk_usize 0;
          Core.Ops.Range.f_end = Rust_primitives.mk_usize 16
        }
        <:
        Core.Ops.Range.t_Range usize)
      (Libcrux_intrinsics.Avx2_extract.mm_storeu_bytes_si128 (serialized.[ {
                Core.Ops.Range.f_start = Rust_primitives.mk_usize 0;
                Core.Ops.Range.f_end = Rust_primitives.mk_usize 16
              }
              <:
              Core.Ops.Range.t_Range usize ]
            <:
            t_Slice u8)
          adjacent_4_combined
        <:
        t_Slice u8)
  in
  Core.Result.impl__unwrap #(t_Array u8 v_OUTPUT_SIZE)
    #Core.Array.t_TryFromSliceError
    (Core.Convert.f_try_into #(t_Slice u8)
        #(t_Array u8 v_OUTPUT_SIZE)
        #FStar.Tactics.Typeclasses.solve
        (serialized.[ {
              Core.Ops.Range.f_start = Rust_primitives.mk_usize 0;
              Core.Ops.Range.f_end = Rust_primitives.mk_usize 4
            }
            <:
            Core.Ops.Range.t_Range usize ]
          <:
          t_Slice u8)
      <:
      Core.Result.t_Result (t_Array u8 v_OUTPUT_SIZE) Core.Array.t_TryFromSliceError)

let serialize (v_OUTPUT_SIZE: usize) (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  match cast (v_OUTPUT_SIZE <: usize) <: u8 with
  | 3 -> serialize_when_eta_is_2_ v_OUTPUT_SIZE simd_unit
  | 4 -> serialize_when_eta_is_4_ v_OUTPUT_SIZE simd_unit
  | _ ->
    Rust_primitives.Hax.never_to_any (Core.Panicking.panic "internal error: entered unreachable code"

        <:
        Rust_primitives.Hax.t_Never)
