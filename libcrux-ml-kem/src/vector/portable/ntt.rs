use super::arithmetic::*;
use super::vector_type::*;

#[inline(always)]
#[hax_lib::requires(fstar!("v i < 16 /\\ v j < 16 /\\ Spec.Utils.is_i16b 1664 $zeta"))]
pub(crate) fn ntt_step(vec: &mut PortableVector, zeta: i16, i: usize, j: usize) {
    let t = montgomery_multiply_fe_by_fer(vec.elements[j], zeta);
    vec.elements[j] = vec.elements[i] - t;
    vec.elements[i] = vec.elements[i] + t;
}

#[inline(always)]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\ Spec.Utils.is_i16b 1664 zeta2 /\\ Spec.Utils.is_i16b 1664 zeta3"))]
pub(crate) fn ntt_layer_1_step(
    mut vec: PortableVector,
    zeta0: i16,
    zeta1: i16,
    zeta2: i16,
    zeta3: i16,
) -> PortableVector {
    ntt_step(&mut vec, zeta0, 0, 2);
    ntt_step(&mut vec, zeta0, 1, 3);
    ntt_step(&mut vec, zeta1, 4, 6);
    ntt_step(&mut vec, zeta1, 5, 7);
    ntt_step(&mut vec, zeta2, 8, 10);
    ntt_step(&mut vec, zeta2, 9, 11);
    ntt_step(&mut vec, zeta3, 12, 14);
    ntt_step(&mut vec, zeta3, 13, 15);
    vec
}

#[inline(always)]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1"))]
pub(crate) fn ntt_layer_2_step(mut vec: PortableVector, zeta0: i16, zeta1: i16) -> PortableVector {
    ntt_step(&mut vec, zeta0, 0, 4);
    ntt_step(&mut vec, zeta0, 1, 5);
    ntt_step(&mut vec, zeta0, 2, 6);
    ntt_step(&mut vec, zeta0, 3, 7);
    ntt_step(&mut vec, zeta1, 8, 12);
    ntt_step(&mut vec, zeta1, 9, 13);
    ntt_step(&mut vec, zeta1, 10, 14);
    ntt_step(&mut vec, zeta1, 11, 15);
    vec
}

#[inline(always)]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 zeta"))]
pub(crate) fn ntt_layer_3_step(mut vec: PortableVector, zeta: i16) -> PortableVector {
    ntt_step(&mut vec, zeta, 0, 8);
    ntt_step(&mut vec, zeta, 1, 9);
    ntt_step(&mut vec, zeta, 2, 10);
    ntt_step(&mut vec, zeta, 3, 11);
    ntt_step(&mut vec, zeta, 4, 12);
    ntt_step(&mut vec, zeta, 5, 13);
    ntt_step(&mut vec, zeta, 6, 14);
    ntt_step(&mut vec, zeta, 7, 15);
    vec
}

#[inline(always)]
#[hax_lib::requires(fstar!("v i < 16 /\\ v j < 16 /\\ Spec.Utils.is_i16b 1664 $zeta"))]
pub(crate) fn inv_ntt_step(vec: &mut PortableVector, zeta: i16, i: usize, j: usize) {
    let a_minus_b = vec.elements[j] - vec.elements[i];
    vec.elements[i] = barrett_reduce_element(vec.elements[i] + vec.elements[j]);
    vec.elements[j] = montgomery_multiply_fe_by_fer(a_minus_b, zeta);
}

#[inline(always)]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\ Spec.Utils.is_i16b 1664 zeta2 /\\ Spec.Utils.is_i16b 1664 zeta3"))]
pub(crate) fn inv_ntt_layer_1_step(
    mut vec: PortableVector,
    zeta0: i16,
    zeta1: i16,
    zeta2: i16,
    zeta3: i16,
) -> PortableVector {
    inv_ntt_step(&mut vec, zeta0, 0, 2);
    inv_ntt_step(&mut vec, zeta0, 1, 3);
    inv_ntt_step(&mut vec, zeta1, 4, 6);
    inv_ntt_step(&mut vec, zeta1, 5, 7);
    inv_ntt_step(&mut vec, zeta2, 8, 10);
    inv_ntt_step(&mut vec, zeta2, 9, 11);
    inv_ntt_step(&mut vec, zeta3, 12, 14);
    inv_ntt_step(&mut vec, zeta3, 13, 15);
    vec
}

#[inline(always)]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1"))]
pub(crate) fn inv_ntt_layer_2_step(
    mut vec: PortableVector,
    zeta0: i16,
    zeta1: i16,
) -> PortableVector {
    inv_ntt_step(&mut vec, zeta0, 0, 4);
    inv_ntt_step(&mut vec, zeta0, 1, 5);
    inv_ntt_step(&mut vec, zeta0, 2, 6);
    inv_ntt_step(&mut vec, zeta0, 3, 7);
    inv_ntt_step(&mut vec, zeta1, 8, 12);
    inv_ntt_step(&mut vec, zeta1, 9, 13);
    inv_ntt_step(&mut vec, zeta1, 10, 14);
    inv_ntt_step(&mut vec, zeta1, 11, 15);
    vec
}

#[inline(always)]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 zeta"))]
pub(crate) fn inv_ntt_layer_3_step(mut vec: PortableVector, zeta: i16) -> PortableVector {
    inv_ntt_step(&mut vec, zeta, 0, 8);
    inv_ntt_step(&mut vec, zeta, 1, 9);
    inv_ntt_step(&mut vec, zeta, 2, 10);
    inv_ntt_step(&mut vec, zeta, 3, 11);
    inv_ntt_step(&mut vec, zeta, 4, 12);
    inv_ntt_step(&mut vec, zeta, 5, 13);
    inv_ntt_step(&mut vec, zeta, 6, 14);
    inv_ntt_step(&mut vec, zeta, 7, 15);
    vec
}

/// Compute the product of two Kyber binomials with respect to the
/// modulus `X² - zeta`.
///
/// This function almost implements <strong>Algorithm 11</strong> of the
/// NIST FIPS 203 standard, which is reproduced below:
///
/// ```plaintext
/// Input:  a₀, a₁, b₀, b₁ ∈ ℤq.
/// Input: γ ∈ ℤq.
/// Output: c₀, c₁ ∈ ℤq.
///
/// c₀ ← a₀·b₀ + a₁·b₁·γ
/// c₁ ← a₀·b₁ + a₁·b₀
/// return c₀, c₁
/// ```
/// We say "almost" because the coefficients output by this function are in
/// the Montgomery domain (unlike in the specification).
///
/// The NIST FIPS 203 standard can be found at
/// <https://csrc.nist.gov/pubs/fips/203/ipd>.
#[inline(always)]
#[hax_lib::requires(fstar!("v i < 16 /\\ v j < 16 /\\ Spec.Utils.is_i16b 1664 $zeta"))]
#[hax_lib::ensures(|()| fstar!("
        let (x,y) = 
          Spec.MLKEM.Math.poly_base_case_multiply 
            (v (Seq.index a.f_elements (v i)) % 3329)
            (v (Seq.index a.f_elements (v j)) % 3329)
            (v (Seq.index b.f_elements (v i)) % 3329)
            (v (Seq.index b.f_elements (v j)) % 3329)
            ((v zeta * 169) % 3329) in
          (x == v (Seq.index out_future.f_elements (v i)) % 3329 /\\
           y == v (Seq.index out_future.f_elements (v j)) % 3329))"))]
pub(crate) fn ntt_multiply_binomials(
    a: &PortableVector,
    b: &PortableVector,
    zeta: FieldElementTimesMontgomeryR,
    i: usize,
    j: usize,
    out: &mut PortableVector,
) {
    hax_lib::fstar!("Spec.Utils.lemma_mul_i16b 3328 3328 (Seq.index (${a}.f_elements) (v i)) (Seq.index (${b}.f_elements) (v i))");
    hax_lib::fstar!("Spec.Utils.lemma_mul_i16b 3328 3328 (Seq.index (${a}.f_elements) (v j)) (Seq.index (${b}.f_elements) (v j))");
    let ai_bi = (a.elements[i] as i32) * (b.elements[i] as i32);
    let aj_bj = montgomery_reduce_element((a.elements[j] as i32) * (b.elements[j] as i32));
    hax_lib::fstar!("Spec.Utils.lemma_mul_i16b 3328 1664 $aj_bj $zeta");
    let o0 = montgomery_reduce_element(
        ai_bi + (aj_bj as i32)* (zeta as i32),
    );
    hax_lib::fstar!("Spec.Utils.lemma_mul_i16b 3328 3328 (Seq.index (${a}.f_elements) (v i)) (Seq.index (${b}.f_elements) (v j))");
    hax_lib::fstar!("Spec.Utils.lemma_mul_i16b 3328 3328 (Seq.index (${a}.f_elements) (v j)) (Seq.index (${b}.f_elements) (v i))");
    let o1 = montgomery_reduce_element(
        (a.elements[i] as i32) * (b.elements[j] as i32)
            + (a.elements[j] as i32) * (b.elements[i] as i32),
    );
    out.elements[i] = o0;
    out.elements[j] = o1;
}

// #[inline(always)]
// pub(crate) fn ntt_multiply_binomials(
//     (a0, a1): (FieldElement, FieldElement),
//     (b0, b1): (FieldElement, FieldElement),
//     zeta: FieldElementTimesMontgomeryR,
// ) -> (MontgomeryFieldElement, MontgomeryFieldElement) {
//     (
//         montgomery_reduce_element(
//             (a0 as i32) * (b0 as i32)
//                 + (montgomery_reduce_element((a1 as i32) * (b1 as i32)) as i32) * (zeta as i32),
//         ),
//         montgomery_reduce_element((a0 as i32) * (b1 as i32) + (a1 as i32) * (b0 as i32)),
//     )
// }

#[inline(always)]
pub(crate) fn ntt_multiply(
    lhs: &PortableVector,
    rhs: &PortableVector,
    zeta0: i16,
    zeta1: i16,
    zeta2: i16,
    zeta3: i16,
) -> PortableVector {
    let mut out = zero();
    ntt_multiply_binomials(lhs, rhs, zeta0, 0, 1, &mut out);
    ntt_multiply_binomials(lhs, rhs, -zeta0, 2, 3, &mut out);
    ntt_multiply_binomials(lhs, rhs, zeta1, 4, 5, &mut out);
    ntt_multiply_binomials(lhs, rhs, -zeta1, 6, 7, &mut out);
    ntt_multiply_binomials(lhs, rhs, zeta2, 8, 9, &mut out);
    ntt_multiply_binomials(lhs, rhs, -zeta2, 10, 11, &mut out);
    ntt_multiply_binomials(lhs, rhs, zeta3, 12, 13, &mut out);
    ntt_multiply_binomials(lhs, rhs, -zeta3, 14, 15, &mut out);
    out
}
