module Libcrux_ml_kem.Vector.Portable.Ntt
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let inv_ntt_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
      (i j: usize)
     =
  let a_minus_b:i16 =
    (vec.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ j ] <: i16) -!
    (vec.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ i ] <: i16)
  in
  let o0:i16 =
    Libcrux_ml_kem.Vector.Portable.Arithmetic.barrett_reduce_element ((vec
            .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ i ]
          <:
          i16) +!
        (vec.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ j ] <: i16)
        <:
        i16)
  in
  let o1:i16 =
    Libcrux_ml_kem.Vector.Portable.Arithmetic.montgomery_multiply_fe_by_fer a_minus_b zeta
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    {
      vec with
      Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
      =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize vec
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
        i
        o0
    }
    <:
    Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    {
      vec with
      Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
      =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize vec
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
        j
        o1
    }
    <:
    Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
  in
  vec

#push-options "--z3rlimit 200"

let inv_ntt_layer_1_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1 zeta2 zeta3: i16)
     =
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta0 (sz 0) (sz 2)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta0 (sz 1) (sz 3)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta1 (sz 4) (sz 6)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta1 (sz 5) (sz 7)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta2 (sz 8) (sz 10)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta2 (sz 9) (sz 11)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta3 (sz 12) (sz 14)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta3 (sz 13) (sz 15)
  in
  let _:Prims.unit =
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 13));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 15));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 12));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 14));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 9));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 11));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 8));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 10));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 5));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 7));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 4));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 6));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 1));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 3));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 0));
    assert (Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements 2));
    assert (forall (i: nat). i < 16 ==> Spec.Utils.is_i16b 3328 (Seq.index vec.f_elements i))
  in
  vec

#pop-options

#push-options "--z3rlimit 100"

let inv_ntt_layer_2_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1: i16)
     =
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta0 (sz 0) (sz 4)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta0 (sz 1) (sz 5)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta0 (sz 2) (sz 6)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta0 (sz 3) (sz 7)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta1 (sz 8) (sz 12)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta1 (sz 9) (sz 13)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta1 (sz 10) (sz 14)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta1 (sz 11) (sz 15)
  in
  vec

#pop-options

#push-options "--z3rlimit 100"

let inv_ntt_layer_3_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
     =
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 0) (sz 8)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 1) (sz 9)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 2) (sz 10)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 3) (sz 11)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 4) (sz 12)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 5) (sz 13)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 6) (sz 14)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    inv_ntt_step vec zeta (sz 7) (sz 15)
  in
  vec

#pop-options

#push-options "--z3rlimit 250 --split_queries always --query_stats --ext context_prune"

let ntt_multiply_binomials
      (a b: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
      (i: usize)
      (out: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
     =
  let ai:i16 = a.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ sz 2 *! i <: usize ] in
  let bi:i16 = b.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ sz 2 *! i <: usize ] in
  let aj:i16 =
    a.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ (sz 2 *! i <: usize) +! sz 1 <: usize
    ]
  in
  let bj:i16 =
    b.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ (sz 2 *! i <: usize) +! sz 1 <: usize
    ]
  in
  let _:Prims.unit =
    assert (Spec.Utils.is_i16b 3328 ai);
    assert (Spec.Utils.is_i16b 3328 bi);
    assert (Spec.Utils.is_i16b 3328 aj);
    assert (Spec.Utils.is_i16b 3328 bj);
    assert_norm (3328 * 3328 < pow2 31)
  in
  let _:Prims.unit = Spec.Utils.lemma_mul_i16b 3328 3328 ai bi in
  let ai_bi:i32 = (cast (ai <: i16) <: i32) *! (cast (bi <: i16) <: i32) in
  let _:Prims.unit = Spec.Utils.lemma_mul_i16b 3328 3328 aj bj in
  let aj_bj___:i32 = (cast (aj <: i16) <: i32) *! (cast (bj <: i16) <: i32) in
  let _:Prims.unit = assert_norm (3328 * 3328 <= 3328 * pow2 15) in
  let aj_bj:i16 = Libcrux_ml_kem.Vector.Portable.Arithmetic.montgomery_reduce_element aj_bj___ in
  let _:Prims.unit = Spec.Utils.lemma_mul_i16b 3328 1664 aj_bj zeta in
  let aj_bj_zeta:i32 = (cast (aj_bj <: i16) <: i32) *! (cast (zeta <: i16) <: i32) in
  let ai_bi_aj_bj:i32 = ai_bi +! aj_bj_zeta in
  let _:Prims.unit = assert (Spec.Utils.is_i32b (3328 * 3328 + 3328 * 1664) ai_bi_aj_bj) in
  let _:Prims.unit = assert_norm (3328 * 3328 + 3328 * 1664 <= 3328 * pow2 15) in
  let o0:i16 = Libcrux_ml_kem.Vector.Portable.Arithmetic.montgomery_reduce_element ai_bi_aj_bj in
  let _:Prims.unit =
    calc ( == ) {
      v o0 % 3329;
      ( == ) { () }
      (v ai_bi_aj_bj * 169) % 3329;
      ( == ) { assert (v ai_bi_aj_bj == v ai_bi + v aj_bj_zeta) }
      ((v ai_bi + v aj_bj_zeta) * 169) % 3329;
      ( == ) { assert (v ai_bi == v ai * v bi) }
      (((v ai * v bi) + v aj_bj_zeta) * 169) % 3329;
      ( == ) { assert (v aj_bj_zeta == v aj_bj * v zeta) }
      (((v ai * v bi) + (v aj_bj * v zeta)) * 169) % 3329;
      ( == ) { Math.Lemmas.lemma_mod_mul_distr_l ((v ai * v bi) + (v aj_bj * v zeta)) 169 3329 }
      ((((v ai * v bi) + (v aj_bj * v zeta)) % 3329) * 169) % 3329;
      ( == ) { Math.Lemmas.lemma_mod_add_distr (v ai * v bi) (v aj_bj * v zeta) 3329 }
      ((((v ai * v bi) + ((v aj_bj * v zeta) % 3329)) % 3329) * 169) % 3329;
      ( == ) { Math.Lemmas.lemma_mod_mul_distr_l (v aj_bj) (v zeta) 3329 }
      ((((v ai * v bi) + (((v aj_bj % 3329) * v zeta) % 3329)) % 3329) * 169) % 3329;
      ( == ) { assert (v aj_bj % 3329 == (v aj_bj___ * 169) % 3329) }
      ((((v ai * v bi) + ((((v aj_bj___ * 169) % 3329) * v zeta) % 3329)) % 3329) * 169) % 3329;
      ( == ) { assert (v aj_bj___ == v aj * v bj) }
      ((((v ai * v bi) + ((((v aj * v bj * 169) % 3329) * v zeta) % 3329)) % 3329) * 169) % 3329;
      ( == ) { Math.Lemmas.lemma_mod_mul_distr_l (v aj * v bj * 169) (v zeta) 3329 }
      ((((v ai * v bi) + (((v aj * v bj * 169 * v zeta) % 3329))) % 3329) * 169) % 3329;
      ( == ) { Math.Lemmas.lemma_mod_add_distr (v ai * v bi) (v aj * v bj * 169 * v zeta) 3329 }
      ((((v ai * v bi) + ((v aj * v bj * 169 * v zeta))) % 3329) * 169) % 3329;
      ( == ) { Math.Lemmas.lemma_mod_mul_distr_l ((v ai * v bi) + ((v aj * v bj * 169 * v zeta)))
        169
        3329 }
      (((v ai * v bi) + ((v aj * v bj * 169 * v zeta))) * 169) % 3329;
    }
  in
  let _:Prims.unit = Spec.Utils.lemma_mul_i16b 3328 3328 ai bj in
  let ai_bj:i32 = (cast (ai <: i16) <: i32) *! (cast (bj <: i16) <: i32) in
  let _:Prims.unit = Spec.Utils.lemma_mul_i16b 3328 3328 aj bi in
  let aj_bi:i32 = (cast (aj <: i16) <: i32) *! (cast (bi <: i16) <: i32) in
  let ai_bj_aj_bi:i32 = ai_bj +! aj_bi in
  let _:Prims.unit = assert (Spec.Utils.is_i32b (3328 * 3328 + 3328 * 3328) ai_bj_aj_bi) in
  let _:Prims.unit = assert_norm (3328 * 3328 + 3328 * 3328 <= 3328 * pow2 15) in
  let o1:i16 = Libcrux_ml_kem.Vector.Portable.Arithmetic.montgomery_reduce_element ai_bj_aj_bi in
  let _:Prims.unit =
    calc ( == ) {
      v o1 % 3329;
      ( == ) { () }
      (v ai_bj_aj_bi * 169) % 3329;
      ( == ) { assert (v ai_bj_aj_bi == v ai_bj + v aj_bi) }
      ((v ai_bj + v aj_bi) * 169) % 3329;
      ( == ) { assert (v ai_bj == v ai * v bj) }
      ((v ai * v bj + v aj_bi) * 169) % 3329;
      ( == ) { assert (v aj_bi == v aj * v bi) }
      ((v ai * v bj + v aj * v bi) * 169) % 3329;
    }
  in
  let v__out0:t_Array i16 (sz 16) = out.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    {
      out with
      Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
      =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize out
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
        (sz 2 *! i <: usize)
        o0
    }
    <:
    Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
  in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    {
      out with
      Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
      =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize out
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
        ((sz 2 *! i <: usize) +! sz 1 <: usize)
        o1
    }
    <:
    Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
  in
  let _:Prims.unit =
    assert (Seq.index out.f_elements (2 * v i) == o0);
    assert (Seq.index out.f_elements (2 * v i + 1) == o1);
    assert (Spec.Utils.is_i16b_array 3328 out.f_elements);
    assert (forall k.
          (k <> 2 * v i /\ k <> 2 * v i + 1) ==> Seq.index out.f_elements k == Seq.index v__out0 k)
  in
  let _:Prims.unit = admit () in
  out

#pop-options

#push-options "--admit_smt_queries true"

let ntt_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
      (i j: usize)
     =
  let t:i16 =
    Libcrux_ml_kem.Vector.Portable.Arithmetic.montgomery_multiply_fe_by_fer (vec
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ j ]
        <:
        i16)
      zeta
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    {
      vec with
      Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
      =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize vec
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
        j
        ((vec.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ i ] <: i16) -! t <: i16)
    }
    <:
    Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    {
      vec with
      Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
      =
      Rust_primitives.Hax.Monomorphized_update_at.update_at_usize vec
          .Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements
        i
        ((vec.Libcrux_ml_kem.Vector.Portable.Vector_type.f_elements.[ i ] <: i16) +! t <: i16)
    }
    <:
    Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
  in
  vec

#pop-options

#push-options "--z3rlimit 100"

let ntt_layer_1_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1 zeta2 zeta3: i16)
     =
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta0 (sz 0) (sz 2)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta0 (sz 1) (sz 3)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta1 (sz 4) (sz 6)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta1 (sz 5) (sz 7)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta2 (sz 8) (sz 10)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta2 (sz 9) (sz 11)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta3 (sz 12) (sz 14)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta3 (sz 13) (sz 15)
  in
  vec

#pop-options

#push-options "--z3rlimit 100"

let ntt_layer_2_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1: i16)
     =
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta0 (sz 0) (sz 4)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta0 (sz 1) (sz 5)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta0 (sz 2) (sz 6)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta0 (sz 3) (sz 7)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta1 (sz 8) (sz 12)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta1 (sz 9) (sz 13)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta1 (sz 10) (sz 14)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta1 (sz 11) (sz 15)
  in
  vec

#pop-options

#push-options "--z3rlimit 100"

let ntt_layer_3_step (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector) (zeta: i16) =
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 0) (sz 8)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 1) (sz 9)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 2) (sz 10)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 3) (sz 11)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 4) (sz 12)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 5) (sz 13)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 6) (sz 14)
  in
  let vec:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_step vec zeta (sz 7) (sz 15)
  in
  vec

#pop-options

#push-options "--z3rlimit 100"

let ntt_multiply
      (lhs rhs: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1 zeta2 zeta3: i16)
     =
  let nzeta0:i16 = Core.Ops.Arith.Neg.neg zeta0 in
  let nzeta1:i16 = Core.Ops.Arith.Neg.neg zeta1 in
  let nzeta2:i16 = Core.Ops.Arith.Neg.neg zeta2 in
  let nzeta3:i16 = Core.Ops.Arith.Neg.neg zeta3 in
  let _:Prims.unit = assert (Spec.Utils.is_i16b 1664 nzeta0) in
  let _:Prims.unit = assert (Spec.Utils.is_i16b 1664 nzeta1) in
  let _:Prims.unit = assert (Spec.Utils.is_i16b 1664 nzeta2) in
  let _:Prims.unit = assert (Spec.Utils.is_i16b 1664 nzeta3) in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    Libcrux_ml_kem.Vector.Portable.Vector_type.zero ()
  in
  let _:Prims.unit = assert (Spec.Utils.is_i16b_array 3328 out.f_elements) in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs zeta0 (sz 0) out
  in
  let _:Prims.unit = assert (Spec.Utils.is_i16b_array 3328 out.f_elements) in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs nzeta0 (sz 1) out
  in
  let _:Prims.unit = assert (Spec.Utils.is_i16b_array 3328 out.f_elements) in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs zeta1 (sz 2) out
  in
  let _:Prims.unit = assert (Spec.Utils.is_i16b_array 3328 out.f_elements) in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs nzeta1 (sz 3) out
  in
  let _:Prims.unit = assert (Spec.Utils.is_i16b_array 3328 out.f_elements) in
  let _:Prims.unit = admit () in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs zeta2 (sz 4) out
  in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs nzeta2 (sz 5) out
  in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs zeta3 (sz 6) out
  in
  let out:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector =
    ntt_multiply_binomials lhs rhs nzeta3 (sz 7) out
  in
  out

#pop-options
