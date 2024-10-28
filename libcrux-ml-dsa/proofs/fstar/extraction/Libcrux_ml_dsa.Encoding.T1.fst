module Libcrux_ml_dsa.Encoding.T1
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let _ =
  (* This module has implicit dependencies, here we make them explicit. *)
  (* The implicit dependencies arise from typeclasses instances. *)
  let open Libcrux_ml_dsa.Simd.Traits in
  ()

let deserialize
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (serialized: t_Slice u8)
     =
  let serialized_chunks:Core.Slice.Iter.t_Chunks u8 =
    Core.Slice.impl__chunks #u8 serialized (sz 10)
  in
  let result:Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit =
    Libcrux_ml_dsa.Polynomial.impl__ZERO #v_SIMDUnit ()
  in
  let result, serialized_chunks:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit &
    Core.Slice.Iter.t_Chunks u8) =
    Rust_primitives.Hax.Folds.fold_range (sz 0)
      (Core.Slice.impl__len #v_SIMDUnit
          (result.Libcrux_ml_dsa.Polynomial.f_simd_units <: t_Slice v_SIMDUnit)
        <:
        usize)
      (fun temp_0_ temp_1_ ->
          let result, serialized_chunks:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement
            v_SIMDUnit &
            Core.Slice.Iter.t_Chunks u8) =
            temp_0_
          in
          let _:usize = temp_1_ in
          true)
      (result, serialized_chunks
        <:
        (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit & Core.Slice.Iter.t_Chunks u8)
      )
      (fun temp_0_ i ->
          let result, serialized_chunks:(Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement
            v_SIMDUnit &
            Core.Slice.Iter.t_Chunks u8) =
            temp_0_
          in
          let i:usize = i in
          let tmp0, out:(Core.Slice.Iter.t_Chunks u8 & Core.Option.t_Option (t_Slice u8)) =
            Core.Iter.Traits.Iterator.f_next #(Core.Slice.Iter.t_Chunks u8)
              #FStar.Tactics.Typeclasses.solve
              serialized_chunks
          in
          let serialized_chunks:Core.Slice.Iter.t_Chunks u8 = tmp0 in
          ({
              result with
              Libcrux_ml_dsa.Polynomial.f_simd_units
              =
              Rust_primitives.Hax.Monomorphized_update_at.update_at_usize result
                  .Libcrux_ml_dsa.Polynomial.f_simd_units
                i
                (Libcrux_ml_dsa.Simd.Traits.f_t1_deserialize #v_SIMDUnit
                    #FStar.Tactics.Typeclasses.solve
                    (Core.Option.impl__unwrap #(t_Slice u8) out <: t_Slice u8)
                  <:
                  v_SIMDUnit)
            }
            <:
            Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit),
          serialized_chunks
          <:
          (Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit &
            Core.Slice.Iter.t_Chunks u8))
  in
  result

let serialize
      (#v_SIMDUnit: Type0)
      (#[FStar.Tactics.Typeclasses.tcresolve ()]
          i1:
          Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit)
      (re: Libcrux_ml_dsa.Polynomial.t_PolynomialRingElement v_SIMDUnit)
     =
  let serialized:t_Array u8 (sz 320) = Rust_primitives.Hax.repeat 0uy (sz 320) in
  let serialized:t_Array u8 (sz 320) =
    Rust_primitives.Hax.Folds.fold_enumerated_slice (re.Libcrux_ml_dsa.Polynomial.f_simd_units
        <:
        t_Slice v_SIMDUnit)
      (fun serialized temp_1_ ->
          let serialized:t_Array u8 (sz 320) = serialized in
          let _:usize = temp_1_ in
          true)
      serialized
      (fun serialized temp_1_ ->
          let serialized:t_Array u8 (sz 320) = serialized in
          let i, simd_unit:(usize & v_SIMDUnit) = temp_1_ in
          Rust_primitives.Hax.Monomorphized_update_at.update_at_range serialized
            ({
                Core.Ops.Range.f_start = i *! serialize__OUTPUT_BYTES_PER_SIMD_UNIT <: usize;
                Core.Ops.Range.f_end
                =
                (i +! sz 1 <: usize) *! serialize__OUTPUT_BYTES_PER_SIMD_UNIT <: usize
              }
              <:
              Core.Ops.Range.t_Range usize)
            (Core.Slice.impl__copy_from_slice #u8
                (serialized.[ {
                      Core.Ops.Range.f_start = i *! serialize__OUTPUT_BYTES_PER_SIMD_UNIT <: usize;
                      Core.Ops.Range.f_end
                      =
                      (i +! sz 1 <: usize) *! serialize__OUTPUT_BYTES_PER_SIMD_UNIT <: usize
                    }
                    <:
                    Core.Ops.Range.t_Range usize ]
                  <:
                  t_Slice u8)
                (Libcrux_ml_dsa.Simd.Traits.f_t1_serialize #v_SIMDUnit
                    #FStar.Tactics.Typeclasses.solve
                    simd_unit
                  <:
                  t_Slice u8)
              <:
              t_Slice u8)
          <:
          t_Array u8 (sz 320))
  in
  serialized