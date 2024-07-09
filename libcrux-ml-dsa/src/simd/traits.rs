// Each field element occupies 32 bits and the size of a simd_unit is 256 bits.
pub(crate) const COEFFICIENTS_IN_SIMD_UNIT: usize = 8;

pub const FIELD_MODULUS: i32 = 8_380_417;

// FIELD_MODULUS^{-1} mod MONTGOMERY_R
pub const INVERSE_OF_MODULUS_MOD_MONTGOMERY_R: u64 = 58_728_449;

pub(crate) trait Operations: Copy + Clone {
    #[allow(non_snake_case)]
    fn ZERO() -> Self;

    fn from_i32_array(array: &[i32]) -> Self;
    fn to_i32_array(simd_unit: Self) -> [i32; COEFFICIENTS_IN_SIMD_UNIT];

    // Basic arithmetic
    fn add(lhs: &Self, rhs: &Self) -> Self;
    fn subtract(lhs: &Self, rhs: &Self) -> Self;

    // Modular operations
    fn montgomery_multiply(lhs: Self, rhs: Self) -> Self;
    fn montgomery_multiply_by_constant(simd_unit: Self, c: i32) -> Self;

    // Decomposition operations
    fn power2round(simd_unit: Self) -> (Self, Self);

    // NTT
    fn ntt_at_layer_0(simd_unit: Self, zeta0: i32, zeta1: i32, zeta2: i32, zeta3: i32) -> Self;
    fn ntt_at_layer_1(simd_unit: Self, zeta0: i32, zeta1: i32) -> Self;
    fn ntt_at_layer_2(simd_unit: Self, zeta: i32) -> Self;

    // Inverse NTT
    fn invert_ntt_at_layer_0(
        simd_unit: Self,
        zeta0: i32,
        zeta1: i32,
        zeta2: i32,
        zeta3: i32,
    ) -> Self;
    fn invert_ntt_at_layer_1(simd_unit: Self, zeta0: i32, zeta1: i32) -> Self;
    fn invert_ntt_at_layer_2(simd_unit: Self, zeta: i32) -> Self;
}

// hax does not support trait with default implementations, so we use the
// following pattern.
pub fn montgomery_multiply_by_fer<S: Operations>(simd_unit: S, fer: i32) -> S {
    S::montgomery_multiply_by_constant(simd_unit, fer)
}
