use crate::{
    arithmetic::shift_left_then_reduce,
    constants::BITS_IN_LOWER_PART_OF_T,
    ntt::{invert_ntt_montgomery, invert_ntt_montgomery_mut, ntt, ntt_multiply_montgomery},
    polynomial::PolynomialRingElement,
    simd::traits::Operations,
};

/// Compute InvertNTT(Â ◦ ŝ₁) + s₂
#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn compute_As1_plus_s2<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    A_as_ntt: [[PolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A],
    s1: &[PolynomialRingElement<SIMDUnit>; COLUMNS_IN_A],
    s2: &[PolynomialRingElement<SIMDUnit>; ROWS_IN_A],
) -> [PolynomialRingElement<SIMDUnit>; ROWS_IN_A] {
    let mut result = [PolynomialRingElement::<SIMDUnit>::ZERO(); ROWS_IN_A];
    let s1_ntt = s1.map(|s1_j| ntt::<SIMDUnit>(s1_j));

    for (i, row) in A_as_ntt.into_iter().enumerate() {
        for (j, ring_element) in row.into_iter().enumerate() {
            let product = ntt_multiply_montgomery::<SIMDUnit>(&ring_element, &s1_ntt[j]);
            PolynomialRingElement::add_mut(&mut result[i], &product);
        }

        invert_ntt_montgomery_mut::<SIMDUnit>(&mut result[i]);
        PolynomialRingElement::add_mut(&mut result[i], &s2[i]);
    }

    result
}

/// Compute InvertNTT(Â ◦ ŷ)
#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn compute_A_times_mask<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    A_as_ntt: &[[PolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A],
    mask: &[PolynomialRingElement<SIMDUnit>; COLUMNS_IN_A],
) -> [PolynomialRingElement<SIMDUnit>; ROWS_IN_A] {
    let mut result = [PolynomialRingElement::<SIMDUnit>::ZERO(); ROWS_IN_A];

    for (i, row) in A_as_ntt.iter().enumerate() {
        for (j, ring_element) in row.iter().enumerate() {
            let product = ntt_multiply_montgomery(&ring_element, &ntt(mask[j]));
            PolynomialRingElement::<SIMDUnit>::add_mut(&mut result[i], &product);
        }

        invert_ntt_montgomery_mut(&mut result[i]);
    }

    result
}

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn vector_times_ring_element<SIMDUnit: Operations, const DIMENSION: usize>(
    vector: &[PolynomialRingElement<SIMDUnit>; DIMENSION],
    ring_element: &PolynomialRingElement<SIMDUnit>,
) -> [PolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [PolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for (i, vector_ring_element) in vector.iter().enumerate() {
        result[i] =
            invert_ntt_montgomery(ntt_multiply_montgomery(vector_ring_element, ring_element));
    }

    result
}

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn add_vectors<SIMDUnit: Operations, const DIMENSION: usize>(
    lhs: &[PolynomialRingElement<SIMDUnit>; DIMENSION],
    rhs: &[PolynomialRingElement<SIMDUnit>; DIMENSION],
) -> [PolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [PolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for i in 0..DIMENSION {
        result[i] = PolynomialRingElement::<SIMDUnit>::add(&lhs[i], &rhs[i]);
    }

    result
}

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn subtract_vectors<SIMDUnit: Operations, const DIMENSION: usize>(
    lhs: &[PolynomialRingElement<SIMDUnit>; DIMENSION],
    rhs: &[PolynomialRingElement<SIMDUnit>; DIMENSION],
) -> [PolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [PolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for i in 0..DIMENSION {
        result[i] = PolynomialRingElement::<SIMDUnit>::subtract(&lhs[i], &rhs[i]);
    }

    result
}

/// Compute InvertNTT(Â ◦ ẑ - ĉ ◦ NTT(t₁2ᵈ))
#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn compute_w_approx<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    A_as_ntt: &[[PolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A],
    signer_response: &[PolynomialRingElement<SIMDUnit>; COLUMNS_IN_A],
    verifier_challenge_as_ntt: &PolynomialRingElement<SIMDUnit>,
    t1_w: &mut [PolynomialRingElement<SIMDUnit>; ROWS_IN_A],
) {
    for (i, row) in A_as_ntt.iter().enumerate() {
        let t1_shifted =
            shift_left_then_reduce::<SIMDUnit, { BITS_IN_LOWER_PART_OF_T as i32 }>(t1_w[i]);
        let challenge_times_t1_shifted =
            ntt_multiply_montgomery(&verifier_challenge_as_ntt, &ntt(t1_shifted));

        // XXX: This could be nicer
        let mut tmp = PolynomialRingElement::<SIMDUnit>::ZERO();
        for (j, ring_element) in row.iter().enumerate() {
            let product = ntt_multiply_montgomery(&ring_element, &ntt(signer_response[j]));
            tmp = PolynomialRingElement::<SIMDUnit>::add(&tmp, &product);
        }

        t1_w[i] = PolynomialRingElement::<SIMDUnit>::subtract(&tmp, &challenge_times_t1_shifted);
        invert_ntt_montgomery_mut(&mut t1_w[i]);
    }
}
