use crate::Error;

#[derive(Debug)]
pub struct Signature<const LEN: usize>([u8; LEN]);

#[derive(Debug, Clone)]
struct PublicKey<const LEN: usize> {
    n: [u8; LEN],
}

pub struct PrivateKey<const LEN: usize> {
    pk: PublicKey<LEN>,
    d: [u8; LEN],
}

const E_BITS: u32 = 17;
const E: [u8; 3] = [1, 0, 1];

fn hacl_hash_alg(alg: crate::DigestAlgorithm) -> libcrux_hacl_rs::streaming_types::hash_alg {
    match alg {
        crate::DigestAlgorithm::Sha2_256 => libcrux_hacl_rs::streaming_types::hash_alg::SHA2_256,
        crate::DigestAlgorithm::Sha2_384 => libcrux_hacl_rs::streaming_types::hash_alg::SHA2_384,
        crate::DigestAlgorithm::Sha2_512 => libcrux_hacl_rs::streaming_types::hash_alg::SHA2_512,
    }
}

// next up: generate these in macros

macro_rules! impl_rsapss {
    ($sign_fn:ident, $verify_fn:ident, $bits:literal, $bytes:literal) => {
        fn $sign_fn(
            alg: crate::DigestAlgorithm,
            sk: &PrivateKey<$bytes>,
            msg: &[u8],
            salt: &[u8],
            sig: &mut Signature<$bytes>,
        ) -> Result<(), Error> {
            let alg = hacl_hash_alg(alg);

            let salt_len = salt.len().try_into().map_err(|_| Error::SaltTooLarge)?;
            let msg_len = msg.len().try_into().map_err(|_| Error::MessageTooLarge)?;

            let skey = crate::hacl::rsapss::new_rsapss_load_skey(
                $bits, E_BITS, $bits, &sk.pk.n, &E, &sk.d,
            );

            match crate::hacl::rsapss::rsapss_sign(
                alg, $bits, E_BITS, $bits, &skey, salt_len, salt, msg_len, msg, &mut sig.0,
            ) {
                true => Ok(()),
                false => Err(Error::SigningFailed),
            }
        }

        fn $verify_fn(
            alg: crate::DigestAlgorithm,
            pk: &PublicKey<$bytes>,
            msg: &[u8],
            salt_len: u32,
            sig: &Signature<$bytes>,
        ) -> Result<(), Error> {
            let alg = hacl_hash_alg(alg);

            let msg_len = msg.len().try_into().map_err(|_| Error::MessageTooLarge)?;

            match crate::hacl::rsapss::rsapss_pkey_verify(
                alg, $bits, E_BITS, &pk.n, &E, salt_len, $bytes, /*signature length*/
                &sig.0, msg_len, msg,
            ) {
                true => Ok(()),
                false => Err(Error::VerificationFailed),
            }
        }
    };
}

impl_rsapss!(sign_2048, verify_2048, 2048, 256);
impl_rsapss!(sign_3072, verify_3072, 3072, 384);
impl_rsapss!(sign_4096, verify_4096, 4096, 512);
impl_rsapss!(sign_6144, verify_6144, 6144, 768);
impl_rsapss!(sign_8192, verify_8192, 8192, 1024);

#[cfg(test)]
mod tests {
    use super::*;

    const MODULUS: [u8; 256] = [
        0xd2, 0x78, 0x16, 0xcb, 0x72, 0xbb, 0x6e, 0x27, 0xdb, 0x10, 0x1a, 0x6f, 0x3e, 0x64, 0x62,
        0x93, 0xd9, 0xec, 0xa7, 0xb3, 0x98, 0xe3, 0x36, 0x6c, 0x9e, 0x69, 0x31, 0xc4, 0x5d, 0xd7,
        0x24, 0xd3, 0xf8, 0x90, 0xb0, 0xd0, 0x57, 0x78, 0x3e, 0xdd, 0xee, 0xf0, 0xc9, 0x0e, 0x98,
        0x6d, 0xad, 0xe9, 0x46, 0x47, 0xc5, 0xcb, 0x4d, 0xa4, 0xc6, 0x9c, 0x83, 0x1a, 0x13, 0x9f,
        0xb7, 0x8d, 0xe7, 0xe3, 0x79, 0x97, 0xf2, 0x9e, 0x36, 0x5c, 0x96, 0xaa, 0xf6, 0x29, 0xfe,
        0x6e, 0x3c, 0x0d, 0xb0, 0xcb, 0x04, 0x7d, 0x35, 0xd3, 0xeb, 0xf7, 0xee, 0x36, 0x59, 0xda,
        0xb5, 0xb2, 0x34, 0x08, 0x86, 0x87, 0x27, 0x02, 0x4b, 0x49, 0xb3, 0x85, 0x33, 0x9b, 0x63,
        0x8f, 0x28, 0x3b, 0x27, 0x83, 0x65, 0xf9, 0x62, 0x23, 0xe0, 0x8b, 0x15, 0x1d, 0xd3, 0x00,
        0xb1, 0xd6, 0x37, 0x3e, 0x7b, 0xa7, 0x1d, 0xc7, 0x63, 0x79, 0xe2, 0xa2, 0xca, 0x2d, 0xa4,
        0xb6, 0xcd, 0xef, 0x8d, 0x73, 0xec, 0x56, 0xfc, 0x0b, 0xac, 0xcb, 0x80, 0x53, 0xcf, 0x34,
        0x2f, 0x29, 0xb0, 0xe7, 0xf0, 0xb9, 0x24, 0xf4, 0xe4, 0x99, 0xb2, 0x58, 0xc0, 0x9e, 0x1f,
        0xf5, 0x43, 0x6e, 0xca, 0xc6, 0xeb, 0x65, 0xd0, 0x5f, 0xdb, 0x13, 0x4c, 0x8c, 0xca, 0x82,
        0xd9, 0xad, 0xc1, 0xfd, 0x7a, 0xd9, 0x78, 0xc7, 0xed, 0xdf, 0xc9, 0x70, 0x54, 0xd3, 0x80,
        0x5f, 0x06, 0x48, 0x11, 0x6e, 0xfb, 0x9b, 0x46, 0xfa, 0x02, 0x65, 0xde, 0xcc, 0xe9, 0x6e,
        0x91, 0x98, 0x93, 0x3d, 0x3d, 0x6d, 0xb1, 0x99, 0xa4, 0x73, 0xc1, 0x2c, 0xa2, 0x16, 0x55,
        0x97, 0xf3, 0x0f, 0x67, 0xf7, 0x9a, 0x78, 0x74, 0x15, 0x66, 0xb1, 0xd4, 0xdc, 0x98, 0x47,
        0x8a, 0x50, 0xb6, 0x2d, 0x63, 0xf9, 0xce, 0xa2, 0x76, 0x70, 0x91, 0xa8, 0x3b, 0x00, 0x28,
        0x01,
    ];

    const PRIVATE_EXPONENT: [u8; 256] = [
        0x5a, 0x90, 0x21, 0xfe, 0xd9, 0x17, 0x9d, 0x86, 0xb8, 0xd4, 0x6d, 0x0b, 0x81, 0x25, 0x60,
        0xe5, 0x8d, 0xd8, 0x2f, 0x31, 0x30, 0x90, 0x54, 0x52, 0xd8, 0xb7, 0x1b, 0x1b, 0x0b, 0xe6,
        0x0f, 0x8a, 0xc6, 0x62, 0x3c, 0x32, 0xe9, 0xf0, 0x6b, 0xdc, 0xc3, 0x7c, 0x08, 0x87, 0xa7,
        0x3f, 0x4a, 0x9e, 0x1e, 0x07, 0xb4, 0x2c, 0x8e, 0xf4, 0x60, 0x21, 0xe8, 0xa7, 0xc7, 0xd9,
        0xe9, 0xf9, 0xbd, 0xd6, 0x3b, 0xf4, 0x0e, 0x09, 0xd6, 0x0a, 0x71, 0x2a, 0x8f, 0x51, 0xf2,
        0x91, 0x2c, 0x76, 0x17, 0xa4, 0xc4, 0x01, 0xbc, 0xaf, 0xbb, 0xd1, 0xab, 0x46, 0xe7, 0xd3,
        0x1c, 0x6b, 0xd9, 0xc7, 0xf1, 0x5b, 0x26, 0x85, 0xee, 0x2f, 0x80, 0x77, 0xc8, 0x85, 0x0c,
        0x8a, 0x05, 0x1d, 0xaf, 0x1a, 0xf3, 0x3e, 0x23, 0xe4, 0x9c, 0x32, 0x3c, 0x9b, 0xe0, 0xb7,
        0x63, 0xce, 0x71, 0x67, 0x09, 0x7e, 0x17, 0x69, 0x74, 0x9a, 0xec, 0x2a, 0x71, 0xf4, 0xeb,
        0xe2, 0x84, 0x23, 0x8b, 0xa8, 0x27, 0x69, 0x19, 0x53, 0x52, 0x8f, 0xc3, 0x62, 0xd5, 0x2a,
        0x43, 0xb0, 0x78, 0x90, 0x54, 0x98, 0x22, 0x12, 0x2d, 0x32, 0x28, 0xcf, 0xf9, 0x04, 0x1c,
        0x4f, 0x28, 0xb7, 0xad, 0x98, 0x1a, 0xdf, 0x2e, 0xdb, 0x94, 0xd5, 0x3d, 0xe2, 0xa9, 0x29,
        0x3c, 0x3e, 0xaa, 0x81, 0x2a, 0x61, 0x8d, 0x4b, 0x41, 0x2f, 0xda, 0x99, 0x8b, 0x78, 0x7a,
        0xd5, 0xec, 0x93, 0x53, 0x5a, 0x84, 0x43, 0x47, 0x1a, 0xaf, 0x68, 0xa7, 0x5f, 0x4e, 0x62,
        0xe5, 0xcf, 0x07, 0xc9, 0x2b, 0x67, 0x34, 0x82, 0x27, 0xf6, 0xe0, 0x6d, 0x51, 0xca, 0x21,
        0xea, 0xfa, 0x32, 0xf0, 0x9f, 0x84, 0xb4, 0xfb, 0xaf, 0x25, 0x1e, 0x91, 0x08, 0x94, 0x5e,
        0x83, 0x7f, 0x0f, 0x6a, 0x86, 0x98, 0x77, 0xb8, 0xb0, 0xca, 0xd0, 0x34, 0x10, 0x69, 0x59,
        0x21,
    ];

    #[test]
    fn self_test_rsa_pss() {
        let pk = PublicKey { n: MODULUS };
        let sk = PrivateKey {
            pk: pk.clone(),
            d: PRIVATE_EXPONENT,
        };
        let salt = [1, 2, 3, 4, 5];
        let msg = [7, 8, 9, 10];
        let mut signature = Signature([0u8; 256]);
        sign_2048(
            crate::DigestAlgorithm::Sha2_256,
            &sk,
            &salt,
            &msg,
            &mut signature,
        )
        .unwrap();
        println!("signature: {:x?}", signature);
        verify_2048(
            crate::DigestAlgorithm::Sha2_256,
            &pk,
            &msg,
            salt.len() as u32,
            &signature,
        )
        .expect("Error verifying signature");
    }
}
