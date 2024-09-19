module BitVec.Utils

open Core
open FStar.FunctionalExtensionality
open BitVec.Equality
open Rust_primitives.BitVectors

let mk_bv #len (f: (i:nat{i < len}) -> bit) = on (i:nat {i < len}) f

let mk_list_32 #a (x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15 x16 x17 x18 x19 x20 x21 x22 x23 x24 x25 x26 x27 x28 x29 x30 x31: a)
  : (l:list a {List.Tot.length l == 32})
  = let l = [x0;x1;x2;x3;x4;x5;x6;x7;x8;x9;x10;x11;x12;x13;x14;x15;x16;x17;x18;x19;x20;x21;x22;x23;x24;x25;x26;x27;x28;x29;x30;x31] in
    assert_norm (List.Tot.length l == 32);
    l

let mk_list_8 #a (x0 x1 x2 x3 x4 x5 x6 x7: a)
  : (l:list a {List.Tot.length l == 8})
  = let l = [x0;x1;x2;x3;x4;x5;x6;x7] in
    assert_norm (List.Tot.length l == 8);
    l

let rw_get_bit_cast #t #u
  (x: int_t t) (nth: usize)
  : Lemma (requires v nth < bits u /\ v nth < bits u)
          (ensures eq2 #bit (get_bit (cast_mod #t #u x) nth) (if v nth < bits t then get_bit x nth else 0))
          [SMTPat (get_bit (cast_mod #t #u x) nth)]
  = ()

let rw_get_bit_shr #t #u (x: int_t t) (y: int_t u) (i: usize {v i < bits t})
  : Lemma (requires v y >= 0 /\ v y < bits t)
          (ensures eq2 #bit (get_bit (x >>! y) i )
                (if v i < bits t - v y
                    then get_bit x (mk_int (v i + v y))
                    else if signed t
                         then get_bit x (mk_int (bits t - 1))
                         else 0))
  = ()
