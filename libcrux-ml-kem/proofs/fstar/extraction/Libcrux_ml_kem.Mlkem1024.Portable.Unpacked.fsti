module Libcrux_ml_kem.Mlkem1024.Portable.Unpacked
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

let _ =
  (* This module has implicit dependencies, here we make them explicit. *)
  (* The implicit dependencies arise from typeclasses instances. *)
  let open Libcrux_ml_kem.Ind_cca.Unpacked in
  let open Libcrux_ml_kem.Vector.Portable in
  let open Libcrux_ml_kem.Vector.Traits in
  ()

/// Get the serialized public key.
val serialized_public_key
      (public_key:
          Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemPublicKeyUnpacked (sz 4)
            Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (serialized: Libcrux_ml_kem.Types.t_MlKemPublicKey (sz 1568))
    : Prims.Pure (Libcrux_ml_kem.Types.t_MlKemPublicKey (sz 1568))
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Decapsulate ML-KEM 1024 (unpacked)
/// Generates an [`MlKemSharedSecret`].
/// The input is a reference to an unpacked key pair of type [`MlKem1024KeyPairUnpacked`]
/// and an [`MlKem1024Ciphertext`].
val decapsulate
      (private_key:
          Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemKeyPairUnpacked (sz 4)
            Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (ciphertext: Libcrux_ml_kem.Types.t_MlKemCiphertext (sz 1568))
    : Prims.Pure (t_Array u8 (sz 32)) Prims.l_True (fun _ -> Prims.l_True)

let _ =
        (* This module has implicit dependencies, here we make them explicit. *)
        (* The implicit dependencies arise from typeclasses instances. *)
        let open Libcrux_ml_kem.Vector.Portable in
        let open Libcrux_ml_kem.Vector.Neon in
        ()

/// Encapsulate ML-KEM 1024 (unpacked)
/// Generates an ([`MlKem1024Ciphertext`], [`MlKemSharedSecret`]) tuple.
/// The input is a reference to an unpacked public key of type [`MlKem1024PublicKeyUnpacked`],
/// the SHA3-256 hash of this public key, and [`SHARED_SECRET_SIZE`] bytes of `randomness`.
/// TODO: The F* prefix opens required modules, it should go away when the following issue is resolved:
/// <https://github.com/hacspec/hax/issues/770>
val encapsulate
      (public_key:
          Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemPublicKeyUnpacked (sz 4)
            Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      (randomness: t_Array u8 (sz 32))
    : Prims.Pure (Libcrux_ml_kem.Types.t_MlKemCiphertext (sz 1568) & t_Array u8 (sz 32))
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Generate ML-KEM 1024 Key Pair in "unpacked" form
val generate_key_pair
      (randomness: t_Array u8 (sz 64))
      (key_pair:
          Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemKeyPairUnpacked (sz 4)
            Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
    : Prims.Pure
      (Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemKeyPairUnpacked (sz 4)
          Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Create a new, empty unpacked key.
val init_key_pair: Prims.unit
  -> Prims.Pure
      (Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemKeyPairUnpacked (sz 4)
          Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Create a new, empty unpacked public key.
val init_public_key: Prims.unit
  -> Prims.Pure
      (Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemPublicKeyUnpacked (sz 4)
          Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      Prims.l_True
      (fun _ -> Prims.l_True)

/// Get the unpacked public key.
val unpacked_public_key
      (public_key: Libcrux_ml_kem.Types.t_MlKemPublicKey (sz 1568))
      (unpacked_public_key:
          Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemPublicKeyUnpacked (sz 4)
            Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
    : Prims.Pure
      (Libcrux_ml_kem.Ind_cca.Unpacked.t_MlKemPublicKeyUnpacked (sz 4)
          Libcrux_ml_kem.Vector.Portable.Vector_type.t_PortableVector)
      Prims.l_True
      (fun _ -> Prims.l_True)
