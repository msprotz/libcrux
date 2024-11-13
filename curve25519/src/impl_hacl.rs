use super::*;

/// Implementation of Curve25519 backed by Hacl.
pub struct HaclCurve25519;

impl Curve25519 for HaclCurve25519 {
    // the hacl::ecdh function requires all parameters to be 32 byte long, which we enforce using
    // types.
    fn secret_to_public(pk: &mut [u8; PK_LEN], sk: &[u8; SK_LEN]) {
        crate::hacl::secret_to_public(pk, sk)
    }

    // the hacl::ecdh function requires all parameters to be 32 byte long, which we enforce using
    // types.
    fn ecdh(out: &mut [u8; SHK_LEN], pk: &[u8; PK_LEN], sk: &[u8; SK_LEN]) -> Result<(), Error> {
        if crate::hacl::ecdh(out, sk, pk) {
            Ok(())
        } else {
            Err(Error)
        }
    }
}
