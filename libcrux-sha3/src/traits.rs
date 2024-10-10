/// A Keccak Item
/// This holds the internal state and depends on the architecture.
pub trait KeccakStateItem<const N: usize>: internal::KeccakItem<N> {}

// Implement the public trait for all items.
impl<const N: usize, T: internal::KeccakItem<N>> KeccakStateItem<N> for T {}

pub(crate) mod internal {
    use libcrux_secret_independence::*;
    /// A trait for multiplexing implementations.
    pub trait KeccakItem<const N: usize>: Clone + Copy {
        fn zero() -> Self;
        fn xor5(a: Self, b: Self, c: Self, d: Self, e: Self) -> Self;
        fn rotate_left1_and_xor(a: Self, b: Self) -> Self;
        fn xor_and_rotate<const LEFT: i32, const RIGHT: i32>(a: Self, b: Self) -> Self;
        fn and_not_xor(a: Self, b: Self, c: Self) -> Self;
        fn xor_constant(a: Self, c: U64) -> Self;
        fn xor(a: Self, b: Self) -> Self;
        fn load_block<const RATE: usize>(a: &mut [[Self; 5]; 5], b: [&[U8]; N]);
        fn store_block<const RATE: usize>(a: &[[Self; 5]; 5], b: [&mut [U8]; N]);
        fn load_block_full<const RATE: usize>(a: &mut [[Self; 5]; 5], b: [[U8; 200]; N]);
        fn store_block_full<const RATE: usize>(a: &[[Self; 5]; 5]) -> [[U8; 200]; N];
        fn slice_n(a: [&[U8]; N], start: usize, len: usize) -> [&[U8]; N];
        fn split_at_mut_n(a: [&mut [U8]; N], mid: usize) -> ([&mut [U8]; N], [&mut [U8]; N]);
        fn store<const RATE: usize>(state: &[[Self; 5]; 5], out: [&mut [U8]; N]);
    }
}
