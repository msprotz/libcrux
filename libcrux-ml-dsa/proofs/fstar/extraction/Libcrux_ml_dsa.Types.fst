module Libcrux_ml_dsa.Types
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let _ =
  (* This module has implicit dependencies, here we make them explicit. *)
  (* The implicit dependencies arise from typeclasses instances. *)
  let open Libcrux_ml_dsa.Simd.Traits in
  ()

let impl__len (v_SIZE: usize) (_: Prims.unit) = v_SIZE

let impl_2__len (v_SIZE: usize) (_: Prims.unit) = v_SIZE

let impl_4__len (v_SIZE: usize) (_: Prims.unit) = v_SIZE

let t_SigningError_cast_to_repr (x: t_SigningError) =
  match x with
  | SigningError_RejectionSamplingError  -> Rust_primitives.mk_isize 0
  | SigningError_ContextTooLongError  -> Rust_primitives.mk_isize 1

let t_VerificationError_cast_to_repr (x: t_VerificationError) =
  match x with
  | VerificationError_MalformedHintError  -> Rust_primitives.mk_isize 0
  | VerificationError_SignerResponseExceedsBoundError  -> Rust_primitives.mk_isize 1
  | VerificationError_CommitmentHashesDontMatchError  -> Rust_primitives.mk_isize 3
  | VerificationError_ContextTooLongError  -> Rust_primitives.mk_isize 6

let impl_4__as_slice (v_SIZE: usize) (self: t_MLDSASignature v_SIZE) = self._0 <: t_Slice u8

let impl__as_slice (v_SIZE: usize) (self: t_MLDSASigningKey v_SIZE) = self._0 <: t_Slice u8

let impl_2__as_slice (v_SIZE: usize) (self: t_MLDSAVerificationKey v_SIZE) = self._0 <: t_Slice u8
