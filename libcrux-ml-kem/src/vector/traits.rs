pub const MONTGOMERY_R_SQUARED_MOD_FIELD_MODULUS: i16 = 1353;
pub const FIELD_MODULUS: i16 = 3329;
pub const FIELD_ELEMENTS_IN_VECTOR: usize = 16;
pub const INVERSE_OF_MODULUS_MOD_MONTGOMERY_R: u32 = 62209; // FIELD_MODULUS^{-1} mod MONTGOMERY_R
pub const BARRETT_SHIFT: i32 = 26;
pub const BARRETT_R: i32 = 1 << BARRETT_SHIFT;

#[cfg(not(eurydice))]
#[hax_lib::attributes]
pub trait Repr: Copy + Clone {
    #[requires(true)]
    fn repr(x: Self) -> [i16; 16];
}

#[cfg(not(eurydice))]
#[hax_lib::attributes]
pub trait ArithOperations: Copy + Clone + Repr {
    #[allow(non_snake_case)]
    #[requires(true)]
    #[ensures(|result| fstar!("f_repr $result == Seq.create 16 0s"))]
    fn ZERO() -> Self;
  
    #[requires(array.len() == 16)]
    #[ensures(|result| fstar!("f_repr $result == $array"))]
    fn from_i16_array(array: &[i16]) -> Self;
     
    #[requires(true)]
    #[ensures(|result| fstar!("f_repr $x == $result"))]
    fn to_i16_array(x: Self) -> [i16; 16];

    // Basic arithmetic
    #[requires(fstar!("forall i. i < 16 ==> 
        Spec.Utils.is_intb (pow2 15 - 1) (v (Seq.index (f_repr ${lhs}) i) + v (Seq.index (f_repr ${rhs}) i))"))]
    #[ensures(|result| fstar!("forall i. i < 16 ==> 
        (v (Seq.index (f_repr ${result}) i) == 
         v (Seq.index (f_repr ${lhs}) i) + v (Seq.index (f_repr ${rhs}) i))"))]
    fn add(lhs: Self, rhs: &Self) -> Self;

    #[requires(fstar!("forall i. i < 16 ==> 
        Spec.Utils.is_intb (pow2 15 - 1) (v (Seq.index (f_repr ${lhs}) i) - v (Seq.index (f_repr ${rhs}) i))"))]
    #[ensures(|result| fstar!("forall i. i < 16 ==> 
        (v (Seq.index (f_repr ${result}) i) == 
         v (Seq.index (f_repr ${lhs}) i) - v (Seq.index (f_repr ${rhs}) i))"))]
    fn sub(lhs: Self, rhs: &Self) -> Self;

    #[requires(fstar!("forall i. i < 16 ==> 
        Spec.Utils.is_intb (pow2 15 - 1) (v (Seq.index (f_repr ${vec}) i) * v c)"))]
    #[ensures(|result| fstar!("forall i. i < 16 ==> 
        (v (Seq.index (f_repr ${result}) i) == 
         v (Seq.index (f_repr ${vec}) i) * v c)"))]
    fn multiply_by_constant(vec: Self, c: i16) -> Self;

    // Bitwise operations
    #[requires(true)]
    #[ensures(|result| fstar!("f_repr $result == Spec.Utils.map_array (fun x -> x &. c) (f_repr $v)"))]
    fn bitwise_and_with_constant(v: Self, c: i16) -> Self;

    #[requires(SHIFT_BY >= 0 && SHIFT_BY < 16)]
    #[ensures(|result| fstar!("(v_SHIFT_BY >=. 0l /\\ v_SHIFT_BY <. 16l) ==> f_repr $result == Spec.Utils.map_array (fun x -> x >>! ${SHIFT_BY}) (f_repr $v)"))]
    fn shift_right<const SHIFT_BY: i32>(v: Self) -> Self;
    // fn shift_left<const SHIFT_BY: i32>(v: Self) -> Self;

    // Modular operations
    #[requires(fstar!("Spec.Utils.is_i16b_array (pow2 12 - 1) (f_repr $v)"))]
    #[ensures(|result| fstar!("f_repr $result == Spec.Utils.map_array (fun x -> if x >=. 3329s then x -! 3329s else x) (f_repr $v)"))]
    fn cond_subtract_3329(v: Self) -> Self;

    #[requires(fstar!("Spec.Utils.is_i16b_array 28296 (f_repr $vector)"))]
    fn barrett_reduce(vector: Self) -> Self;

    #[requires(fstar!("Spec.Utils.is_i16b 1664 c"))]
    fn montgomery_multiply_by_constant(v: Self, c: i16) -> Self;

}

#[cfg(not(eurydice))]
#[hax_lib::attributes]
pub trait NTTOperations: Copy + Clone + Repr {
    // NTT
    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\ 
                       Spec.Utils.is_i16b 1664 zeta2 /\\ Spec.Utils.is_i16b 1664 zeta3 /\\
                       Spec.Utils.is_i16b_array (11207+5*3328) (f_repr ${a})"))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array (11207+6*3328) (f_repr $out)"))]
    fn ntt_layer_1_step(a: Self, zeta0: i16, zeta1: i16, zeta2: i16, zeta3: i16) -> Self;
    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\
                       Spec.Utils.is_i16b_array (11207+4*3328) (f_repr ${a})"))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array (11207+5*3328) (f_repr $out)"))]
    fn ntt_layer_2_step(a: Self, zeta0: i16, zeta1: i16) -> Self;
    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta /\\
                       Spec.Utils.is_i16b_array (11207+3*3328) (f_repr ${a})"))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array (11207+4*3328) (f_repr $out)"))]
    fn ntt_layer_3_step(a: Self, zeta: i16) -> Self;

    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\ 
                       Spec.Utils.is_i16b 1664 zeta2 /\\ Spec.Utils.is_i16b 1664 zeta3 /\\
                       Spec.Utils.is_i16b_array (4 * 3328) (f_repr ${a})"))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array 3328 (f_repr $out)"))]
    fn inv_ntt_layer_1_step(a: Self, zeta0: i16, zeta1: i16, zeta2: i16, zeta3: i16) -> Self;
    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\
                       Spec.Utils.is_i16b_array 3328 (f_repr ${a})"))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array 3328 (f_repr $out)"))]
    fn inv_ntt_layer_2_step(a: Self, zeta0: i16, zeta1: i16) -> Self;
    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta/\\
                       Spec.Utils.is_i16b_array 3328 (f_repr ${a})"))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array 3328 (f_repr $out)"))]
    fn inv_ntt_layer_3_step(a: Self, zeta: i16) -> Self;

    #[requires(fstar!("Spec.Utils.is_i16b 1664 zeta0 /\\ Spec.Utils.is_i16b 1664 zeta1 /\\
                       Spec.Utils.is_i16b 1664 zeta2 /\\ Spec.Utils.is_i16b 1664 zeta3 /\\
                       Spec.Utils.is_i16b_array 3228 (f_repr ${lhs}) /\\
                       Spec.Utils.is_i16b_array 3228 (f_repr ${rhs}) "))]
    #[ensures(|out| fstar!("Spec.Utils.is_i16b_array 3328 (f_repr $out)"))]
    fn ntt_multiply(lhs: &Self, rhs: &Self, zeta0: i16, zeta1: i16, zeta2: i16, zeta3: i16)
        -> Self;
}

#[cfg(not(eurydice))]
#[hax_lib::attributes]
pub trait SerializeOperations: Copy + Clone + Repr {
    // Compression
    #[requires(true)]
    fn compress_1(v: Self) -> Self;
    #[requires(COEFFICIENT_BITS == 4 || COEFFICIENT_BITS == 5 ||
               COEFFICIENT_BITS == 10 || COEFFICIENT_BITS == 11)]
    fn compress<const COEFFICIENT_BITS: i32>(v: Self) -> Self;
    #[requires(COEFFICIENT_BITS == 4 || COEFFICIENT_BITS == 5 ||
        COEFFICIENT_BITS == 10 || COEFFICIENT_BITS == 11)]
    fn decompress_ciphertext_coefficient<const COEFFICIENT_BITS: i32>(v: Self) -> Self;

    // Serialization and deserialization
    #[requires(fstar!("Spec.MLKEM.serialize_pre 1 (f_repr $a)"))]
    #[ensures(|result| fstar!("Spec.MLKEM.serialize_pre 1 (f_repr $a) ==> Spec.MLKEM.serialize_post 1 (f_repr $a) $result"))]
    fn serialize_1(a: Self) -> [u8; 2];
    #[requires(a.len() == 2)]
    #[ensures(|result| fstar!("sz (Seq.length $a) =. sz 2 ==> Spec.MLKEM.deserialize_post 1 $a (f_repr $result)"))]
    fn deserialize_1(a: &[u8]) -> Self;

    #[requires(fstar!("Spec.MLKEM.serialize_pre 4 (f_repr $a)"))]
    #[ensures(|result| fstar!("Spec.MLKEM.serialize_pre 4 (f_repr $a) ==> Spec.MLKEM.serialize_post 4 (f_repr $a) $result"))]
    fn serialize_4(a: Self) -> [u8; 8];
    #[requires(a.len() == 8)]
    #[ensures(|result| fstar!("sz (Seq.length $a) =. sz 8 ==> Spec.MLKEM.deserialize_post 4 $a (f_repr $result)"))]
    fn deserialize_4(a: &[u8]) -> Self;

    fn serialize_5(a: Self) -> [u8; 10];
    #[requires(a.len() == 10)]
    fn deserialize_5(a: &[u8]) -> Self;

    #[requires(fstar!("Spec.MLKEM.serialize_pre 10 (f_repr $a)"))]
    #[ensures(|result| fstar!("Spec.MLKEM.serialize_pre 10 (f_repr $a) ==> Spec.MLKEM.serialize_post 10 (f_repr $a) $result"))]
    fn serialize_10(a: Self) -> [u8; 20];
    #[requires(a.len() == 20)]
    #[ensures(|result| fstar!("sz (Seq.length $a) =. sz 20 ==> Spec.MLKEM.deserialize_post 10 $a (f_repr $result)"))]
    fn deserialize_10(a: &[u8]) -> Self;

    fn serialize_11(a: Self) -> [u8; 22];
    #[requires(a.len() == 22)]
    fn deserialize_11(a: &[u8]) -> Self;

    #[requires(fstar!("Spec.MLKEM.serialize_pre 12 (f_repr $a)"))]
    #[ensures(|result| fstar!("Spec.MLKEM.serialize_pre 12 (f_repr $a) ==> Spec.MLKEM.serialize_post 12 (f_repr $a) $result"))]
    fn serialize_12(a: Self) -> [u8; 24];
    #[requires(a.len() == 24)]
    #[ensures(|result| fstar!("sz (Seq.length $a) =. sz 24 ==> Spec.MLKEM.deserialize_post 12 $a (f_repr $result)"))]
    fn deserialize_12(a: &[u8]) -> Self;

    #[requires(a.len() == 24 && out.len() == 16)]
    #[ensures(|result|
        fstar!("Seq.length $out_future == Seq.length $out /\\ v $result <= 16")
    )]
    fn rej_sample(a: &[u8], out: &mut [i16]) -> usize;
}

#[cfg(not(eurydice))]
#[hax_lib::attributes]
pub trait Operations: Copy + Clone + ArithOperations + NTTOperations + SerializeOperations {}

#[cfg(eurydice)]
pub trait Operations: Copy + Clone {
    #[allow(non_snake_case)]
    fn ZERO() -> Self;
    fn from_i16_array(array: &[i16]) -> Self;
    fn to_i16_array(x: Self) -> [i16; 16];
    fn add(lhs: Self, rhs: &Self) -> Self;
    fn sub(lhs: Self, rhs: &Self) -> Self;
    fn multiply_by_constant(v: Self, c: i16) -> Self;
    fn bitwise_and_with_constant(v: Self, c: i16) -> Self;
    fn shift_right<const SHIFT_BY: i32>(v: Self) -> Self;
    fn cond_subtract_3329(v: Self) -> Self;
    fn barrett_reduce(vector: Self) -> Self;
    fn montgomery_multiply_by_constant(v: Self, c: i16) -> Self;
    fn ntt_layer_1_step(a: Self, zeta0: i16, zeta1: i16, zeta2: i16, zeta3: i16) -> Self;
    fn ntt_layer_2_step(a: Self, zeta0: i16, zeta1: i16) -> Self;
    fn ntt_layer_3_step(a: Self, zeta: i16) -> Self;
    fn inv_ntt_layer_1_step(a: Self, zeta0: i16, zeta1: i16, zeta2: i16, zeta3: i16) -> Self;
    fn inv_ntt_layer_2_step(a: Self, zeta0: i16, zeta1: i16) -> Self;
    fn inv_ntt_layer_3_step(a: Self, zeta: i16) -> Self;
    fn ntt_multiply(lhs: &Self, rhs: &Self, zeta0: i16, zeta1: i16, zeta2: i16, zeta3: i16)
        -> Self;
    fn compress_1(v: Self) -> Self;
    fn compress<const COEFFICIENT_BITS: i32>(v: Self) -> Self;
    fn decompress_ciphertext_coefficient<const COEFFICIENT_BITS: i32>(v: Self) -> Self;
    fn serialize_1(a: Self) -> [u8; 2];
    fn deserialize_1(a: &[u8]) -> Self;
    fn serialize_4(a: Self) -> [u8; 8];
    fn deserialize_4(a: &[u8]) -> Self;
    fn serialize_5(a: Self) -> [u8; 10];
    fn deserialize_5(a: &[u8]) -> Self;
    fn serialize_10(a: Self) -> [u8; 20];
    fn deserialize_10(a: &[u8]) -> Self;
    fn serialize_11(a: Self) -> [u8; 22];
    fn deserialize_11(a: &[u8]) -> Self;
    fn serialize_12(a: Self) -> [u8; 24];
    fn deserialize_12(a: &[u8]) -> Self;
    fn rej_sample(a: &[u8], out: &mut [i16]) -> usize;
}

// hax does not support trait with default implementations, so we use the following pattern
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b 1664 $fer"))]
pub fn montgomery_multiply_fe<T: Operations>(v: T, fer: i16) -> T {
    T::montgomery_multiply_by_constant(v, fer)
}

pub fn to_standard_domain<T: Operations>(v: T) -> T {
    T::montgomery_multiply_by_constant(v, MONTGOMERY_R_SQUARED_MOD_FIELD_MODULUS as i16)
}

#[hax_lib::fstar::verification_status(lax)]
#[hax_lib::fstar::options("--z3rlimit 100")]
#[hax_lib::requires(fstar!("Spec.Utils.is_i16b_array 3328 (i1._super_13198556198845860418._super_8706949974463268012.f_repr a)"))]
#[hax_lib::ensures(|result| fstar!("forall i.
                                       (let x = Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${a}) i in
                                        let y = Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${result}) i in
                                        (v y >= 0 /\\ v y <= 3328 /\\ (v y % 3329 == v x % 3329)))"))]
pub fn to_unsigned_representative<T: Operations>(a: T) -> T {
    let t = T::shift_right::<15>(a);
    let fm = T::bitwise_and_with_constant(t, FIELD_MODULUS);
    T::add(a, &fm)
}

#[hax_lib::fstar::options("--z3rlimit 100")]
#[hax_lib::requires(fstar!("forall i. let x = Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${vec}) i in 
                                      (x == 0s \\/ x == 1s)"))]
pub fn decompress_1<T: Operations>(vec: T) -> T {
    let z = T::ZERO();
    hax_lib::fstar!("assert(forall i. Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${z}) i == 0s)");
    hax_lib::fstar!("assert(forall i. let x = Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${vec}) i in 
                                      ((0 - v x) == 0 \\/ (0 - v x) == -1))"); 
    hax_lib::fstar!("assert(forall i. i < 16 ==>
                                      Spec.Utils.is_intb (pow2 15 - 1) 
                                        (0 - v (Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${vec}) i)))");                               
    
    let s = T::sub(z, &vec);
    hax_lib::fstar!("assert(forall i. Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${s}) i == 0s \\/ 
                                      Seq.index (i1._super_13198556198845860418._super_8706949974463268012.f_repr ${s}) i == -1s)");
    hax_lib::fstar!("assert (i1.f_bitwise_and_with_constant_pre ${s} 1665s)");
    let res = T::bitwise_and_with_constant(s, 1665);
    res
}

/// Internal vectors.
///
/// Used in the unpacked API.
pub trait VectorType: Operations {}

impl<T: Operations> VectorType for T {}
