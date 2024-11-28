module Libcrux_ml_kem.Types
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

///An ML-KEM Ciphertext
type t_MlKemCiphertext (v_SIZE: usize) = { f_value:t_Array u8 v_SIZE }

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_1 (v_SIZE: usize) : Core.Default.t_Default (t_MlKemCiphertext v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_2 (v_SIZE: usize) : Core.Convert.t_AsRef (t_MlKemCiphertext v_SIZE) (t_Slice u8)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_3 (v_SIZE: usize) : Core.Convert.t_From (t_MlKemCiphertext v_SIZE) (t_Array u8 v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_4 (v_SIZE: usize) : Core.Convert.t_From (t_MlKemCiphertext v_SIZE) (t_Array u8 v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_5 (v_SIZE: usize) : Core.Convert.t_From (t_Array u8 v_SIZE) (t_MlKemCiphertext v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
let impl_6 (v_SIZE: usize) : Core.Convert.t_TryFrom (t_MlKemCiphertext v_SIZE) (t_Slice u8) =
  {
    f_Error = Core.Array.t_TryFromSliceError;
    f_try_from_pre = (fun (value: t_Slice u8) -> true);
    f_try_from_post
    =
    (fun
        (value: t_Slice u8)
        (out: Core.Result.t_Result (t_MlKemCiphertext v_SIZE) Core.Array.t_TryFromSliceError)
        ->
        true);
    f_try_from
    =
    fun (value: t_Slice u8) ->
      match
        Core.Convert.f_try_into #(t_Slice u8)
          #(t_Array u8 v_SIZE)
          #FStar.Tactics.Typeclasses.solve
          value
      with
      | Core.Result.Result_Ok value ->
        Core.Result.Result_Ok ({ f_value = value } <: t_MlKemCiphertext v_SIZE)
        <:
        Core.Result.t_Result (t_MlKemCiphertext v_SIZE) Core.Array.t_TryFromSliceError
      | Core.Result.Result_Err e ->
        Core.Result.Result_Err e
        <:
        Core.Result.t_Result (t_MlKemCiphertext v_SIZE) Core.Array.t_TryFromSliceError
  }

/// A reference to the raw byte slice.
val impl_7__as_slice (v_SIZE: usize) (self: t_MlKemCiphertext v_SIZE)
    : Prims.Pure (t_Array u8 v_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// The number of bytes
val impl_7__len: v_SIZE: usize -> Prims.unit
  -> Prims.Pure usize Prims.l_True (fun _ -> Prims.l_True)

///An ML-KEM Private key
type t_MlKemPrivateKey (v_SIZE: usize) = { f_value:t_Array u8 v_SIZE }

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_8 (v_SIZE: usize) : Core.Default.t_Default (t_MlKemPrivateKey v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_9 (v_SIZE: usize) : Core.Convert.t_AsRef (t_MlKemPrivateKey v_SIZE) (t_Slice u8)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_10 (v_SIZE: usize) : Core.Convert.t_From (t_MlKemPrivateKey v_SIZE) (t_Array u8 v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_11 (v_SIZE: usize) : Core.Convert.t_From (t_MlKemPrivateKey v_SIZE) (t_Array u8 v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_12 (v_SIZE: usize) : Core.Convert.t_From (t_Array u8 v_SIZE) (t_MlKemPrivateKey v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
let impl_13 (v_SIZE: usize) : Core.Convert.t_TryFrom (t_MlKemPrivateKey v_SIZE) (t_Slice u8) =
  {
    f_Error = Core.Array.t_TryFromSliceError;
    f_try_from_pre = (fun (value: t_Slice u8) -> true);
    f_try_from_post
    =
    (fun
        (value: t_Slice u8)
        (out: Core.Result.t_Result (t_MlKemPrivateKey v_SIZE) Core.Array.t_TryFromSliceError)
        ->
        true);
    f_try_from
    =
    fun (value: t_Slice u8) ->
      match
        Core.Convert.f_try_into #(t_Slice u8)
          #(t_Array u8 v_SIZE)
          #FStar.Tactics.Typeclasses.solve
          value
      with
      | Core.Result.Result_Ok value ->
        Core.Result.Result_Ok ({ f_value = value } <: t_MlKemPrivateKey v_SIZE)
        <:
        Core.Result.t_Result (t_MlKemPrivateKey v_SIZE) Core.Array.t_TryFromSliceError
      | Core.Result.Result_Err e ->
        Core.Result.Result_Err e
        <:
        Core.Result.t_Result (t_MlKemPrivateKey v_SIZE) Core.Array.t_TryFromSliceError
  }

/// A reference to the raw byte slice.
val impl_14__as_slice (v_SIZE: usize) (self: t_MlKemPrivateKey v_SIZE)
    : Prims.Pure (t_Array u8 v_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// The number of bytes
val impl_14__len: v_SIZE: usize -> Prims.unit
  -> Prims.Pure usize Prims.l_True (fun _ -> Prims.l_True)

///An ML-KEM Public key
type t_MlKemPublicKey (v_SIZE: usize) = { f_value:t_Array u8 v_SIZE }

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_15 (v_SIZE: usize) : Core.Default.t_Default (t_MlKemPublicKey v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_16 (v_SIZE: usize) : Core.Convert.t_AsRef (t_MlKemPublicKey v_SIZE) (t_Slice u8)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_17 (v_SIZE: usize) : Core.Convert.t_From (t_MlKemPublicKey v_SIZE) (t_Array u8 v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_18 (v_SIZE: usize) : Core.Convert.t_From (t_MlKemPublicKey v_SIZE) (t_Array u8 v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
val impl_19 (v_SIZE: usize) : Core.Convert.t_From (t_Array u8 v_SIZE) (t_MlKemPublicKey v_SIZE)

[@@ FStar.Tactics.Typeclasses.tcinstance]
let impl_20 (v_SIZE: usize) : Core.Convert.t_TryFrom (t_MlKemPublicKey v_SIZE) (t_Slice u8) =
  {
    f_Error = Core.Array.t_TryFromSliceError;
    f_try_from_pre = (fun (value: t_Slice u8) -> true);
    f_try_from_post
    =
    (fun
        (value: t_Slice u8)
        (out: Core.Result.t_Result (t_MlKemPublicKey v_SIZE) Core.Array.t_TryFromSliceError)
        ->
        true);
    f_try_from
    =
    fun (value: t_Slice u8) ->
      match
        Core.Convert.f_try_into #(t_Slice u8)
          #(t_Array u8 v_SIZE)
          #FStar.Tactics.Typeclasses.solve
          value
      with
      | Core.Result.Result_Ok value ->
        Core.Result.Result_Ok ({ f_value = value } <: t_MlKemPublicKey v_SIZE)
        <:
        Core.Result.t_Result (t_MlKemPublicKey v_SIZE) Core.Array.t_TryFromSliceError
      | Core.Result.Result_Err e ->
        Core.Result.Result_Err e
        <:
        Core.Result.t_Result (t_MlKemPublicKey v_SIZE) Core.Array.t_TryFromSliceError
  }

/// A reference to the raw byte slice.
val impl_21__as_slice (v_SIZE: usize) (self: t_MlKemPublicKey v_SIZE)
    : Prims.Pure (t_Array u8 v_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// The number of bytes
val impl_21__len: v_SIZE: usize -> Prims.unit
  -> Prims.Pure usize Prims.l_True (fun _ -> Prims.l_True)

/// An ML-KEM key pair
type t_MlKemKeyPair (v_PRIVATE_KEY_SIZE: usize) (v_PUBLIC_KEY_SIZE: usize) = {
  f_sk:t_MlKemPrivateKey v_PRIVATE_KEY_SIZE;
  f_pk:t_MlKemPublicKey v_PUBLIC_KEY_SIZE
}

/// Creates a new [`MlKemKeyPair`].
val impl__new
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (sk: t_Array u8 v_PRIVATE_KEY_SIZE)
      (pk: t_Array u8 v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Create a new [`MlKemKeyPair`] from the secret and public key.
val impl__from
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (sk: t_MlKemPrivateKey v_PRIVATE_KEY_SIZE)
      (pk: t_MlKemPublicKey v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Get a reference to the [`MlKemPublicKey<PUBLIC_KEY_SIZE>`].
val impl__public_key
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_MlKemPublicKey v_PUBLIC_KEY_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// Get a reference to the [`MlKemPrivateKey<PRIVATE_KEY_SIZE>`].
val impl__private_key
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_MlKemPrivateKey v_PRIVATE_KEY_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// Get a reference to the raw public key bytes.
val impl__pk
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_Array u8 v_PUBLIC_KEY_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// Get a reference to the raw private key bytes.
val impl__sk
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_Array u8 v_PRIVATE_KEY_SIZE) Prims.l_True (fun _ -> Prims.l_True)

/// Separate this key into the public and private key.
val impl__into_parts
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
    : Prims.Pure (t_MlKemPrivateKey v_PRIVATE_KEY_SIZE & t_MlKemPublicKey v_PUBLIC_KEY_SIZE)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Unpack an incoming private key into it's different parts.
/// We have this here in types to extract into a common core for C.
val unpack_private_key (v_CPA_SECRET_KEY_SIZE v_PUBLIC_KEY_SIZE: usize) (private_key: t_Slice u8)
    : Prims.Pure (t_Slice u8 & t_Slice u8 & t_Slice u8 & t_Slice u8)
      Prims.l_True
      (fun _ -> Prims.l_True)
