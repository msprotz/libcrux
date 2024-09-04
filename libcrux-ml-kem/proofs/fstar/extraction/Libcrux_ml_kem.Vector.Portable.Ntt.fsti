module Libcrux_ml_kem.Vector.Portable.Ntt
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

val inv_ntt_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
      (i j: usize)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires v i < 16 /\ v j < 16 /\ Spec.Utils.is_i16b 1664 zeta)
      (fun _ -> Prims.l_True)

val inv_ntt_layer_1_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1 zeta2 zeta3: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires
        Spec.Utils.is_i16b 1664 zeta0 /\ Spec.Utils.is_i16b 1664 zeta1 /\
        Spec.Utils.is_i16b 1664 zeta2 /\ Spec.Utils.is_i16b 1664 zeta3)
      (fun _ -> Prims.l_True)

val inv_ntt_layer_2_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires Spec.Utils.is_i16b 1664 zeta0 /\ Spec.Utils.is_i16b 1664 zeta1)
      (fun _ -> Prims.l_True)

val inv_ntt_layer_3_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires Spec.Utils.is_i16b 1664 zeta)
      (fun _ -> Prims.l_True)

/// Compute the product of two Kyber binomials with respect to the
/// modulus `X² - zeta`.
/// This function almost implements <strong>Algorithm 11</strong> of the
/// NIST FIPS 203 standard, which is reproduced below:
/// ```plaintext
/// Input:  a₀, a₁, b₀, b₁ ∈ ℤq.
/// Input: γ ∈ ℤq.
/// Output: c₀, c₁ ∈ ℤq.
/// c₀ ← a₀·b₀ + a₁·b₁·γ
/// c₁ ← a₀·b₁ + a₁·b₀
/// return c₀, c₁
/// ```
/// We say \"almost\" because the coefficients output by this function are in
/// the Montgomery domain (unlike in the specification).
/// The NIST FIPS 203 standard can be found at
/// <https://csrc.nist.gov/pubs/fips/203/ipd>.
val ntt_multiply_binomials
      (a b: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
      (i j: usize)
      (out: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires v i < 16 /\ v j < 16 /\ Spec.Utils.is_i16b 1664 zeta)
      (ensures
        fun out_future ->
          let out_future:Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector = out_future in
          let x, y =
            Spec.MLKEM.Math.poly_base_case_multiply (v (Seq.index a.f_elements (v i)) % 3329)
              (v (Seq.index a.f_elements (v j)) % 3329)
              (v (Seq.index b.f_elements (v i)) % 3329)
              (v (Seq.index b.f_elements (v j)) % 3329)
              ((v zeta * 169) % 3329)
          in
          (x == v (Seq.index out_future.f_elements (v i)) % 3329 /\
            y == v (Seq.index out_future.f_elements (v j)) % 3329))

val ntt_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta: i16)
      (i j: usize)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires v i < 16 /\ v j < 16 /\ Spec.Utils.is_i16b 1664 zeta)
      (fun _ -> Prims.l_True)

val ntt_layer_1_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1 zeta2 zeta3: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires
        Spec.Utils.is_i16b 1664 zeta0 /\ Spec.Utils.is_i16b 1664 zeta1 /\
        Spec.Utils.is_i16b 1664 zeta2 /\ Spec.Utils.is_i16b 1664 zeta3)
      (fun _ -> Prims.l_True)

val ntt_layer_2_step
      (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires Spec.Utils.is_i16b 1664 zeta0 /\ Spec.Utils.is_i16b 1664 zeta1)
      (fun _ -> Prims.l_True)

val ntt_layer_3_step (vec: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector) (zeta: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      (requires Spec.Utils.is_i16b 1664 zeta)
      (fun _ -> Prims.l_True)

val ntt_multiply
      (lhs rhs: Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (zeta0 zeta1 zeta2 zeta3: i16)
    : Prims.Pure Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector
      Prims.l_True
      (fun _ -> Prims.l_True)
