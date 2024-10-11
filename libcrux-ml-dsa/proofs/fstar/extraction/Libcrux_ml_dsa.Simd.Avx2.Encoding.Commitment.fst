module Libcrux_ml_dsa.Simd.Avx2.Encoding.Commitment
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let serialize (v_OUTPUT_SIZE: usize) (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let serialized:t_Array u8 (Rust_primitives.mk_usize 19) =
    Rust_primitives.Hax.repeat (Rust_primitives.mk_u8 0) (Rust_primitives.mk_usize 19)
  in
  match cast (v_OUTPUT_SIZE <: usize) <: u8 with
  | 4 ->
    let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_sllv_epi32 simd_unit
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
      Libcrux_intrinsics.Avx2_extract.mm256_srli_epi64 (Rust_primitives.mk_i32 28)
        adjacent_2_combined
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
    let serialized:t_Array u8 (Rust_primitives.mk_usize 19) =
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
  | 6 ->
    let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_sllv_epi32 simd_unit
        (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 26)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 26)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 26)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 26)
          <:
          Libcrux_intrinsics.Avx2_extract.t_Vec256)
    in
    let adjacent_2_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_srli_epi64 (Rust_primitives.mk_i32 26)
        adjacent_2_combined
    in
    let adjacent_3_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_shuffle_epi8 adjacent_2_combined
        (Libcrux_intrinsics.Avx2_extract.mm256_set_epi8 (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 9)
            (Rust_primitives.mk_i8 8) (Rust_primitives.mk_i8 1) (Rust_primitives.mk_i8 0)
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1)) (Rust_primitives.mk_i8 (-1))
            (Rust_primitives.mk_i8 9) (Rust_primitives.mk_i8 8) (Rust_primitives.mk_i8 1)
            (Rust_primitives.mk_i8 0)
          <:
          Libcrux_intrinsics.Avx2_extract.t_Vec256)
    in
    let adjacent_3_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi16 adjacent_3_combined
        (Libcrux_intrinsics.Avx2_extract.mm256_set_epi16 (Rust_primitives.mk_i16 1)
            (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1)
            (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1)
            (Rust_primitives.mk_i16 1 <<! Rust_primitives.mk_i32 4 <: i16)
            (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1)
            (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1) (Rust_primitives.mk_i16 1)
            (Rust_primitives.mk_i16 1)
            (Rust_primitives.mk_i16 1 <<! Rust_primitives.mk_i32 4 <: i16)
          <:
          Libcrux_intrinsics.Avx2_extract.t_Vec256)
    in
    let adjacent_3_combined:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_srlv_epi32 adjacent_3_combined
        (Libcrux_intrinsics.Avx2_extract.mm256_set_epi32 (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 4)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 0)
            (Rust_primitives.mk_i32 4)
          <:
          Libcrux_intrinsics.Avx2_extract.t_Vec256)
    in
    let lower_3_:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
      Libcrux_intrinsics.Avx2_extract.mm256_castsi256_si128 adjacent_3_combined
    in
    let serialized:t_Array u8 (Rust_primitives.mk_usize 19) =
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
            lower_3_
          <:
          t_Slice u8)
    in
    let upper_3_:Libcrux_intrinsics.Avx2_extract.t_Vec128 =
      Libcrux_intrinsics.Avx2_extract.mm256_extracti128_si256 (Rust_primitives.mk_i32 1)
        adjacent_3_combined
    in
    let serialized:t_Array u8 (Rust_primitives.mk_usize 19) =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_range serialized
        ({
            Core.Ops.Range.f_start = Rust_primitives.mk_usize 3;
            Core.Ops.Range.f_end = Rust_primitives.mk_usize 19
          }
          <:
          Core.Ops.Range.t_Range usize)
        (Libcrux_intrinsics.Avx2_extract.mm_storeu_bytes_si128 (serialized.[ {
                  Core.Ops.Range.f_start = Rust_primitives.mk_usize 3;
                  Core.Ops.Range.f_end = Rust_primitives.mk_usize 19
                }
                <:
                Core.Ops.Range.t_Range usize ]
              <:
              t_Slice u8)
            upper_3_
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
                Core.Ops.Range.f_end = Rust_primitives.mk_usize 6
              }
              <:
              Core.Ops.Range.t_Range usize ]
            <:
            t_Slice u8)
        <:
        Core.Result.t_Result (t_Array u8 v_OUTPUT_SIZE) Core.Array.t_TryFromSliceError)
  | _ ->
    Rust_primitives.Hax.never_to_any (Core.Panicking.panic "internal error: entered unreachable code"

        <:
        Rust_primitives.Hax.t_Never)
