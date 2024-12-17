module Libcrux_ml_kem.Hash_functions.Portable
#set-options "--fuel 0 --ifuel 1 --z3rlimit 80"
open Core
open FStar.Mul

assume
val t_PortableHash': v_K: usize -> eqtype

let t_PortableHash (v_K: usize) = t_PortableHash' v_K

[@@ FStar.Tactics.Typeclasses.tcinstance]
assume
val impl': v_K: usize -> Libcrux_ml_kem.Hash_functions.t_Hash (t_PortableHash v_K) v_K

let impl (v_K: usize) = impl' v_K

assume
val v_G': input: t_Slice u8
  -> Prims.Pure (t_Array u8 (sz 64))
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Array u8 (sz 64) = result in
          result == Spec.Utils.v_G input)

let v_G = v_G'

assume
val v_H': input: t_Slice u8
  -> Prims.Pure (t_Array u8 (sz 32))
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Array u8 (sz 32) = result in
          result == Spec.Utils.v_H input)

let v_H = v_H'

assume
val v_PRF': v_LEN: usize -> input: t_Slice u8
  -> Prims.Pure (t_Array u8 v_LEN)
      (requires v v_LEN < pow2 32)
      (ensures
        fun result ->
          let result:t_Array u8 v_LEN = result in
          result == Spec.Utils.v_PRF v_LEN input)

let v_PRF (v_LEN: usize) = v_PRF' v_LEN

assume
val v_PRFxN': v_K: usize -> v_LEN: usize -> input: t_Array (t_Array u8 (sz 33)) v_K
  -> Prims.Pure (t_Array (t_Array u8 v_LEN) v_K)
      (requires v v_LEN < pow2 32 /\ (v v_K == 2 \/ v v_K == 3 \/ v v_K == 4))
      (ensures
        fun result ->
          let result:t_Array (t_Array u8 v_LEN) v_K = result in
          result == Spec.Utils.v_PRFxN v_K v_LEN input)

let v_PRFxN (v_K v_LEN: usize) = v_PRFxN' v_K v_LEN

assume
val shake128_init_absorb_final': v_K: usize -> input: t_Array (t_Array u8 (sz 34)) v_K
  -> Prims.Pure (t_PortableHash v_K) Prims.l_True (fun _ -> Prims.l_True)

let shake128_init_absorb_final (v_K: usize) = shake128_init_absorb_final' v_K

assume
val shake128_squeeze_first_three_blocks': v_K: usize -> st: t_PortableHash v_K
  -> Prims.Pure (t_PortableHash v_K & t_Array (t_Array u8 (sz 504)) v_K)
      Prims.l_True
      (fun _ -> Prims.l_True)

let shake128_squeeze_first_three_blocks (v_K: usize) = shake128_squeeze_first_three_blocks' v_K

assume
val shake128_squeeze_next_block': v_K: usize -> st: t_PortableHash v_K
  -> Prims.Pure (t_PortableHash v_K & t_Array (t_Array u8 (sz 168)) v_K)
      Prims.l_True
      (fun _ -> Prims.l_True)

let shake128_squeeze_next_block (v_K: usize) = shake128_squeeze_next_block' v_K
