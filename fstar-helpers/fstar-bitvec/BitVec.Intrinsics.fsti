module BitVec.Intrinsics

open Core
open Rust_primitives
open FStar.Mul
open BitVec.Utils
open BitVec.Equality
open Tactics.Utils

(*** The intrinsics *)

let mm256_slli_epi16 (shift: i32 {v shift >= 0 /\ v shift <= 16}) (vec: bit_vec 256): bit_vec 256
  = mk_bv (fun i -> let nth_bit = i % 16 in
                 if nth_bit >= v shift 
                 then vec (i - v shift)
                 else 0)

let mm256_srli_epi16 (shift: i32 {v shift >= 0 /\ v shift <= 16}) (vec: bit_vec 256): bit_vec 256
  = mk_bv (fun i -> let nth_bit = i % 16 in
                 if nth_bit < 16 - v shift then vec (i + v shift) else 0)

let mm256_castsi256_si128 (vec: bit_vec 256): bit_vec 128
  = mk_bv (fun i -> vec i)
let mm256_extracti128_si256 (control: i32{control == 1l}) (vec: bit_vec 256): bit_vec 128
  = mk_bv (fun i -> vec (i + 128))

let mm256_set_epi32 (x0 x1 x2 x3 x4 x5 x6 x7: i32)
  : bit_vec 256
  = mk_bv (fun i ->
      let h (x: i32) = get_bit x (sz (i % 32)) in
      match i / 32 with
      |  0 -> h x7 |  1 -> h x6 |  2 -> h x5 |  3 -> h x4
      |  4 -> h x3 |  5 -> h x2 |  6 -> h x1  |  7 -> h x0)

let mm256_set_epi16 (x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15: i16)
  : bit_vec 256
  = mk_bv (fun i ->
      let h (x: i16) = get_bit x (sz (i % 16)) in
      match i / 16 with
      |  0 -> h x15 |  1 -> h x14 |  2 -> h x13 |  3 -> h x12
      |  4 -> h x11 |  5 -> h x10 |  6 -> h x9  |  7 -> h x8
      |  8 -> h x7  |  9 -> h x6  | 10 -> h x5  | 11 -> h x4
      | 12 -> h x3  | 13 -> h x2  | 14 -> h x1  | 15 -> h x0
    )

let mm256_set_epi8
  (x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15 x16 x17 x18 x19 x20 x21 x22 x23 x24 x25 x26 x27 x28 x29 x30 x31: i8)
  : bit_vec 256
  = mk_bv (fun i ->
      let h (x: i8) = get_bit x (sz (i % 8)) in
      match i / 8 with
      | 0  -> h x31 | 1  -> h x30 | 2  -> h x29 | 3  -> h x28
      | 4  -> h x27 | 5  -> h x26 | 6  -> h x25 | 7  -> h x24
      | 8  -> h x23 | 9  -> h x22 | 10 -> h x21 | 11 -> h x20
      | 12 -> h x19 | 13 -> h x18 | 14 -> h x17 | 15 -> h x16
      | 16 -> h x15 | 17 -> h x14 | 18 -> h x13 | 19 -> h x12
      | 20 -> h x11 | 21 -> h x10 | 22 -> h x9  | 23 -> h x8
      | 24 -> h x7  | 25 -> h x6  | 26 -> h x5  | 27 -> h x4
      | 28 -> h x3  | 29 -> h x2  | 30 -> h x1  | 31 -> h x0
    )

val mm256_set1_epi16_no_semantics: i16 -> bit_vec 256
let mm256_set1_epi16_pow2_minus_one (n: nat): bit_vec 256
  = mk_bv (fun i -> if i <= n then 1 else 0)

let mm256_and_si256 (x y: bit_vec 256): bit_vec 256
  = mk_bv (fun i -> if y i = 0 then 0 else x i)


let mm256_set1_epi16 (constant: i16)
  (#[Tactics.exact (match unify_app (quote constant) (quote (fun n -> ((1s <<! Int32.int_to_t n <: i16) -! 1s <: i16))) [] with
     | Some [x] -> `(mm256_set1_epi16_pow2_minus_one (`#x))
     | _ -> (quote (mm256_set1_epi16_no_semantics constant))
  )]result: bit_vec 256)
  : bit_vec 256 = result

private let saturate8 (v: bit_vec 16): bit_vec 8
  = let on_upper_bits (+) (f: (n:nat{n >= 8 && n <= 15}) -> _) 
        = f 8 + f 9 + f 10 + f 11 + f 12 + f 13 + f 14 + f 15 
    in
    let any1 = on_upper_bits ( ||  ) (fun i -> v i = 1) in
    let all1 = on_upper_bits ( && ) (fun i -> v i = 1) in
    let negative = v 15 = 1 in
    mk_bv (fun i ->
      let last_bit = i = 7 in
      if negative
      then if last_bit 
           then 1
           else if all1
                then v i
                else 0
      else if any1
           then if last_bit
                then 0
                else 1
           else v i
    )

let mm_movemask_epi8_bv (a: bit_vec 128): bit_vec 128
  = mk_bv (fun j ->
             if j < 16
             then a ((j * 8) + 7)
             else 0
          )

let mm_movemask_epi8 (a: bit_vec 128): i32
  = bit_vec_to_int_t 32 (mk_bv (fun i -> mm_movemask_epi8_bv a i))

let mm_packs_epi16 (a b: bit_vec 128): bit_vec 128
  = mk_bv (fun i ->
      let nth_block = i / 8 in
      let offset8 = nth_block * 8 in
      let offset16' = nth_block * 16 in
      let offset16 = offset16' % 128 in
      let vec: bit_vec 128 = if offset16' < 128 then a else b in
      saturate8 (mk_bv (fun j -> vec (offset16 + j))) (i - offset8)
    )



// This is a very specialized version of mm256_mullo_epi16
let mm256_mullo_epi16_specialized1 (a: bit_vec 256): bit_vec 256 =
  mk_bv (fun i -> 
    let nth_bit = i % 16 in
    let nth_i16 = i / 16 in
    let shift = if nth_i16 >= 8 then 23 - nth_i16 else 15 - nth_i16 in
    if nth_bit >= shift then a (i - shift) else 0
  )
  
// This is a very specialized version of mm256_mullo_epi16
let mm256_mullo_epi16_specialized2 (a: bit_vec 256): bit_vec 256 =
  mk_bv (fun i -> 
    let nth_bit = i % 16 in
    let nth_i16 = i / 16 in
    let shift = if nth_i16 % 2 = 0 then 4 else 0 in
    if nth_bit >= shift then a (i - shift) else 0
  )

// This term will be stuck, we don't know anything about it
val mm256_mullo_epi16_no_semantics (a count: bit_vec 256): bit_vec 256

open FStar.Tactics.V2



let mm256_mullo_epi16
    (a count: bit_vec 256) 
    (#[(
      if match unify_app (quote count) (quote (fun x -> mm256_set_epi16 (1s <<! 8l <: i16) (x <<! 9l <: i16)
                                                               (1s <<! 10l <: i16) (1s <<! 11l <: i16) (1s <<! 12l <: i16) (1s <<! 13l <: i16)
                                                               (1s <<! 14l <: i16) (-32768s) (1s <<! 8l <: i16) (1s <<! 9l <: i16) (1s <<! 10l <: i16)
                                                               (1s <<! 11l <: i16) (1s <<! 12l <: i16) (1s <<! 13l <: i16) (1s <<! 14l <: i16) (-32768s))) [] with
         | Some [x] -> unquote x = 1s
         | _ -> false
      then Tactics.exact (quote (mm256_mullo_epi16_specialized1 a))
      else if match unify_app (quote count) (quote (fun x -> mm256_set_epi16 (1s <<! 0l <: i16) (x <<! 4l <: i16)
                                                               (1s <<! 0l <: i16) (1s <<! 4l <: i16) (1s <<! 0l <: i16) (1s <<! 4l <: i16) (1s <<! 0l <: i16)
                                                               (1s <<! 4l <: i16) (1s <<! 0l <: i16) (1s <<! 4l <: i16) (1s <<! 0l <: i16) (1s <<! 4l <: i16)
                                                               (1s <<! 0l <: i16) (1s <<! 4l <: i16) (1s <<! 0l <: i16) (1s <<! 4l <: i16))) [] with
              | Some [x] -> unquote x = 1s
              | _ -> false
           then Tactics.exact (quote (mm256_mullo_epi16_specialized2 a))
           else 
             Tactics.exact (quote (mm256_mullo_epi16_no_semantics a count))
    )]result: bit_vec 256): bit_vec 256 = result

let madd_rhs (n: nat {n < 16}) = 
  mm256_set_epi16 
    (1s <<! Int32.int_to_t n <: i16) 
    1s 
    (1s <<! Int32.int_to_t n <: i16) 
    1s
    (1s <<! Int32.int_to_t n <: i16) 
    1s 
    (1s <<! Int32.int_to_t n <: i16)
    1s 
    (1s <<! Int32.int_to_t n <: i16) 
    1s 
    (1s <<! Int32.int_to_t n <: i16) 
    1s
    (1s <<! Int32.int_to_t n <: i16) 
    1s 
    (1s <<! Int32.int_to_t n <: i16) 
    1s

val mm256_madd_epi16_no_semantic: bit_vec 256 -> bit_vec 256 -> bit_vec 256

let forall_bool (#max: pos) (f: (n: nat {n < max}) -> bool)
  : r:bool {r <==> (forall i. f i)}
  = let rec h (n: nat {n <= max}): r:bool {r <==> (forall i. i < n ==> f i)} = 
        match n with
        | 0 -> true
        | _ -> f (n - 1) && h (n - 1)
    in h max

/// We view `x` as a sequence of pairs of 16 bits, of the shape
/// `(0b0…0a₁…aₙ, 0b0…0b₁…bₙ)`: only the last `n` bits are non-zero.
/// We output a sequence of 32 bits `0b0…0b₁…bₙa₁…aₙ`.
let mm256_madd_epi16_specialized' (x: bit_vec 256) (n: nat {n < 16}): bit_vec 256 =
  mk_bv (fun i -> let j = i % 32 in
               // `x i` is the `j`th bit in the `i/32`th pair of 16 bits `(0b0…0a₁…aₙ, 0b0…0b₁…bₙ)`
               // we want to construct the `j`th bit of `0b0…0b₁…bₙa₁…aₙ`
               let is_zero = 
                 // `|b₁…bₙa₁…aₙ| = n * 2`: if we're above that, we want to produce the bit `0`
                 j >= n * 2
               in
               if is_zero
               then 0
               else if j < n
                    then x i        // we want to produce the bit `aⱼ`
                    else 
                      // the bit from `b` is in the second item of the pair `(0b0…0a₁…aₙ, 0b0…0b₁…bₙ)`
                      x (i - n + 16)
         )
  
let mm256_madd_epi16_specialized (x: bit_vec 256) (n: nat {n < 16}) =
  if forall_bool (fun (i: nat {i < 256}) -> i % 16 < n || x i = 0)
  then mm256_madd_epi16_specialized' x n
  else mm256_madd_epi16_no_semantic x (madd_rhs n)

val mm256_shuffle_epi8_no_semantics (a b: bit_vec 256): bit_vec 256
let mm256_shuffle_epi8_i8 (a: bit_vec 256) (b: list _ {List.Tot.length b == 32}): bit_vec 256 =
  mk_bv (fun i -> 
     let nth = i / 8 in
     let index = List.Tot.index b (31 - nth) in
     if index < 0 then 0
                  else let index = index % 16 in
                       a (index * 8 + i % 8 + i / 128 * 128))

let mm256_shuffle_epi8
  (x y: bit_vec 256) 
  (#[(
    let t = match unify_app (quote y) 
      (quote (fun x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15 x16 x17 x18 x19 x20 x21 x22 x23 x24 x25 x26 x27 x28 x29 x30 x31 -> 
        mm256_set_epi8
          (Int8.int_to_t x0 ) (Int8.int_to_t x1 ) (Int8.int_to_t x2 ) (Int8.int_to_t x3 ) (Int8.int_to_t x4 ) (Int8.int_to_t x5 ) (Int8.int_to_t x6 ) (Int8.int_to_t x7 )
          (Int8.int_to_t x8 ) (Int8.int_to_t x9 ) (Int8.int_to_t x10) (Int8.int_to_t x11) (Int8.int_to_t x12) (Int8.int_to_t x13) (Int8.int_to_t x14) (Int8.int_to_t x15)
          (Int8.int_to_t x16) (Int8.int_to_t x17) (Int8.int_to_t x18) (Int8.int_to_t x19) (Int8.int_to_t x20) (Int8.int_to_t x21) (Int8.int_to_t x22) (Int8.int_to_t x23)
          (Int8.int_to_t x24) (Int8.int_to_t x25) (Int8.int_to_t x26) (Int8.int_to_t x27) (Int8.int_to_t x28) (Int8.int_to_t x29) (Int8.int_to_t x30) (Int8.int_to_t x31))) [] with
    | Some [x0;x1;x2;x3;x4;x5;x6;x7;x8;x9;x10;x11;x12;x13;x14;x15;x16;x17;x18;x19;x20;x21;x22;x23;x24;x25;x26;x27;x28;x29;x30;x31] ->
      `(mm256_shuffle_epi8_i8 (`@x)
                              (mk_list_32
                                 (`#x0 ) (`#x1 ) (`#x2 ) (`#x3 ) (`#x4 ) (`#x5 ) (`#x6 ) (`#x7 )
                                 (`#x8 ) (`#x9 ) (`#x10) (`#x11) (`#x12) (`#x13) (`#x14) (`#x15)
                                 (`#x16) (`#x17) (`#x18) (`#x19) (`#x20) (`#x21) (`#x22) (`#x23) 
                                 (`#x24) (`#x25) (`#x26) (`#x27) (`#x28) (`#x29) (`#x30) (`#x31)))
    | _ -> quote (mm256_shuffle_epi8_no_semantics x y) in
    exact t
  )]result: bit_vec 256)
  : bit_vec 256 
  = result

val mm256_permutevar8x32_epi32_no_semantics (a b: bit_vec 256): bit_vec 256
let mm256_permutevar8x32_epi32_i32 (a: bit_vec 256) (b: list _ {List.Tot.length b == 8}): bit_vec 256 =
  mk_bv (fun i ->
     let j = i / 32 in
     let index = (List.Tot.index b (7 - j) % 8) * 32 in
     a (index + i % 32))

let mm256_permutevar8x32_epi32
  (x y: bit_vec 256) 
  (#[(
    let t = match unify_app (quote y) 
      (quote (fun x0 x1 x2 x3 x4 x5 x6 x7 -> 
        mm256_set_epi32
          (Int32.int_to_t x0) (Int32.int_to_t x1) (Int32.int_to_t x2) (Int32.int_to_t x3) 
          (Int32.int_to_t x4) (Int32.int_to_t x5) (Int32.int_to_t x6) (Int32.int_to_t x7))) [] with
    | Some [x0;x1;x2;x3;x4;x5;x6;x7] ->
      `(mm256_permutevar8x32_epi32_i32 (`@x)
                              (mk_list_8 (`#x0 ) (`#x1 ) (`#x2 ) (`#x3 ) (`#x4 ) (`#x5 ) (`#x6 ) (`#x7 )))
    | _ -> quote (mm256_permutevar8x32_epi32_no_semantics x y) in
    exact t
  )]result: bit_vec 256)
  : bit_vec 256 
  = result

let mm256_madd_epi16
  (x y: bit_vec 256)
  (#[(
    let t = match unify_app (quote y) (quote (fun n -> madd_rhs n)) [delta_only [`%madd_rhs]] with
    | Some [n] -> `(mm256_madd_epi16_specialized (`@x) (`#n))
    | _ -> quote (mm256_madd_epi16_no_semantic x y) in
    exact t
  )]result: bit_vec 256)
  : bit_vec 256
  = result

val mm_storeu_bytes_si128 (_output: t_Slice u8) (vec: bit_vec 128): t_Slice u8

open FStar.Stubs.Tactics.V2.Builtins
open FStar.Stubs.Tactics.V2
open FStar.Tactics.V2.Derived
open FStar.Tactics.V2

let rec bv_to_string #len (bv: bit_vec len): string
  = if len = 0 then ""
               else string_of_int (bv (len - 1)) 
                  ^ bv_to_string #(len - 1) (mk_bv (fun i -> bv i))

let bv_of_string #len (s: string): Tac (bit_vec len)
  = let l = FStar.String.list_of_string s 
          |> filter (function ' ' | '\n' -> false | _ -> true)
          |> map #_ #bit (function '1' -> 1 <: bit | '0' -> 0 | c -> fail ("expected 0 or 1, got [" ^ String.string_of_char c ^ "]")) in
    if FStar.List.Tot.length l = len
    then mk_bv (fun (i: nat {i < len}) -> List.Tot.index l i)
    else fail ("expected a bv of length " ^ string_of_int len ^ ", got a bv of length " ^ string_of_int (FStar.List.Tot.length l))

let call_native_intrinsic' #ilen name raw_args (bitvecs: list (bit_vec ilen)) : Tac string =
  let bitvecs = List.Tot.map bv_to_string bitvecs in
  let args = List.Tot.append raw_args bitvecs in
  let result = launch_process "bash" ("/tmp/run.sh"::name::args) "" in
  print ("process stdout is [" ^ result ^ "]");
  FStar.String.list_of_string result
    |> filter (function ' ' | '\n' -> false | _ -> true)
    |> String.string_of_list

let call_native_intrinsic #ilen olen name raw_args (bitvecs: list (bit_vec ilen)) : Tac (bit_vec olen) =
  bv_of_string (call_native_intrinsic' #ilen name raw_args bitvecs)

let random_bv len: Tac (bit_vec len) 
  = call_native_intrinsic #1 _ "rand" [string_of_int len] []

let tassert (x: bool): Tac unit
  = if x then () else fail "tassert"


private let example: bit_vec 256 = mk_bv (fun i -> if i % 16 = 15 then 1 else 0)

private let x = bv_to_string example
private let y = bv_to_string (mm256_srli_epi16 15l example)

