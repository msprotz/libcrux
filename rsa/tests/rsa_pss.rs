use libcrux_rsa::{sign_2048, verify_2048, DigestAlgorithm, PrivateKey, PublicKey, Signature};

const MODULUS: [u8; 256] = [
    0xd2, 0x78, 0x16, 0xcb, 0x72, 0xbb, 0x6e, 0x27, 0xdb, 0x10, 0x1a, 0x6f, 0x3e, 0x64, 0x62, 0x93,
    0xd9, 0xec, 0xa7, 0xb3, 0x98, 0xe3, 0x36, 0x6c, 0x9e, 0x69, 0x31, 0xc4, 0x5d, 0xd7, 0x24, 0xd3,
    0xf8, 0x90, 0xb0, 0xd0, 0x57, 0x78, 0x3e, 0xdd, 0xee, 0xf0, 0xc9, 0x0e, 0x98, 0x6d, 0xad, 0xe9,
    0x46, 0x47, 0xc5, 0xcb, 0x4d, 0xa4, 0xc6, 0x9c, 0x83, 0x1a, 0x13, 0x9f, 0xb7, 0x8d, 0xe7, 0xe3,
    0x79, 0x97, 0xf2, 0x9e, 0x36, 0x5c, 0x96, 0xaa, 0xf6, 0x29, 0xfe, 0x6e, 0x3c, 0x0d, 0xb0, 0xcb,
    0x04, 0x7d, 0x35, 0xd3, 0xeb, 0xf7, 0xee, 0x36, 0x59, 0xda, 0xb5, 0xb2, 0x34, 0x08, 0x86, 0x87,
    0x27, 0x02, 0x4b, 0x49, 0xb3, 0x85, 0x33, 0x9b, 0x63, 0x8f, 0x28, 0x3b, 0x27, 0x83, 0x65, 0xf9,
    0x62, 0x23, 0xe0, 0x8b, 0x15, 0x1d, 0xd3, 0x00, 0xb1, 0xd6, 0x37, 0x3e, 0x7b, 0xa7, 0x1d, 0xc7,
    0x63, 0x79, 0xe2, 0xa2, 0xca, 0x2d, 0xa4, 0xb6, 0xcd, 0xef, 0x8d, 0x73, 0xec, 0x56, 0xfc, 0x0b,
    0xac, 0xcb, 0x80, 0x53, 0xcf, 0x34, 0x2f, 0x29, 0xb0, 0xe7, 0xf0, 0xb9, 0x24, 0xf4, 0xe4, 0x99,
    0xb2, 0x58, 0xc0, 0x9e, 0x1f, 0xf5, 0x43, 0x6e, 0xca, 0xc6, 0xeb, 0x65, 0xd0, 0x5f, 0xdb, 0x13,
    0x4c, 0x8c, 0xca, 0x82, 0xd9, 0xad, 0xc1, 0xfd, 0x7a, 0xd9, 0x78, 0xc7, 0xed, 0xdf, 0xc9, 0x70,
    0x54, 0xd3, 0x80, 0x5f, 0x06, 0x48, 0x11, 0x6e, 0xfb, 0x9b, 0x46, 0xfa, 0x02, 0x65, 0xde, 0xcc,
    0xe9, 0x6e, 0x91, 0x98, 0x93, 0x3d, 0x3d, 0x6d, 0xb1, 0x99, 0xa4, 0x73, 0xc1, 0x2c, 0xa2, 0x16,
    0x55, 0x97, 0xf3, 0x0f, 0x67, 0xf7, 0x9a, 0x78, 0x74, 0x15, 0x66, 0xb1, 0xd4, 0xdc, 0x98, 0x47,
    0x8a, 0x50, 0xb6, 0x2d, 0x63, 0xf9, 0xce, 0xa2, 0x76, 0x70, 0x91, 0xa8, 0x3b, 0x00, 0x28, 0x01,
];

const PRIVATE_EXPONENT: [u8; 256] = [
    0x5a, 0x90, 0x21, 0xfe, 0xd9, 0x17, 0x9d, 0x86, 0xb8, 0xd4, 0x6d, 0x0b, 0x81, 0x25, 0x60, 0xe5,
    0x8d, 0xd8, 0x2f, 0x31, 0x30, 0x90, 0x54, 0x52, 0xd8, 0xb7, 0x1b, 0x1b, 0x0b, 0xe6, 0x0f, 0x8a,
    0xc6, 0x62, 0x3c, 0x32, 0xe9, 0xf0, 0x6b, 0xdc, 0xc3, 0x7c, 0x08, 0x87, 0xa7, 0x3f, 0x4a, 0x9e,
    0x1e, 0x07, 0xb4, 0x2c, 0x8e, 0xf4, 0x60, 0x21, 0xe8, 0xa7, 0xc7, 0xd9, 0xe9, 0xf9, 0xbd, 0xd6,
    0x3b, 0xf4, 0x0e, 0x09, 0xd6, 0x0a, 0x71, 0x2a, 0x8f, 0x51, 0xf2, 0x91, 0x2c, 0x76, 0x17, 0xa4,
    0xc4, 0x01, 0xbc, 0xaf, 0xbb, 0xd1, 0xab, 0x46, 0xe7, 0xd3, 0x1c, 0x6b, 0xd9, 0xc7, 0xf1, 0x5b,
    0x26, 0x85, 0xee, 0x2f, 0x80, 0x77, 0xc8, 0x85, 0x0c, 0x8a, 0x05, 0x1d, 0xaf, 0x1a, 0xf3, 0x3e,
    0x23, 0xe4, 0x9c, 0x32, 0x3c, 0x9b, 0xe0, 0xb7, 0x63, 0xce, 0x71, 0x67, 0x09, 0x7e, 0x17, 0x69,
    0x74, 0x9a, 0xec, 0x2a, 0x71, 0xf4, 0xeb, 0xe2, 0x84, 0x23, 0x8b, 0xa8, 0x27, 0x69, 0x19, 0x53,
    0x52, 0x8f, 0xc3, 0x62, 0xd5, 0x2a, 0x43, 0xb0, 0x78, 0x90, 0x54, 0x98, 0x22, 0x12, 0x2d, 0x32,
    0x28, 0xcf, 0xf9, 0x04, 0x1c, 0x4f, 0x28, 0xb7, 0xad, 0x98, 0x1a, 0xdf, 0x2e, 0xdb, 0x94, 0xd5,
    0x3d, 0xe2, 0xa9, 0x29, 0x3c, 0x3e, 0xaa, 0x81, 0x2a, 0x61, 0x8d, 0x4b, 0x41, 0x2f, 0xda, 0x99,
    0x8b, 0x78, 0x7a, 0xd5, 0xec, 0x93, 0x53, 0x5a, 0x84, 0x43, 0x47, 0x1a, 0xaf, 0x68, 0xa7, 0x5f,
    0x4e, 0x62, 0xe5, 0xcf, 0x07, 0xc9, 0x2b, 0x67, 0x34, 0x82, 0x27, 0xf6, 0xe0, 0x6d, 0x51, 0xca,
    0x21, 0xea, 0xfa, 0x32, 0xf0, 0x9f, 0x84, 0xb4, 0xfb, 0xaf, 0x25, 0x1e, 0x91, 0x08, 0x94, 0x5e,
    0x83, 0x7f, 0x0f, 0x6a, 0x86, 0x98, 0x77, 0xb8, 0xb0, 0xca, 0xd0, 0x34, 0x10, 0x69, 0x59, 0x21,
];

#[test]
fn self_test_rsa_pss() {
    let pk = PublicKey::from(MODULUS);
    let sk = PrivateKey::from_components(MODULUS, PRIVATE_EXPONENT);
    let salt = [1, 2, 3, 4, 5];
    let msg = [7, 8, 9, 10];
    let mut signature = Signature::new();
    sign_2048(DigestAlgorithm::Sha2_256, &sk, &msg, &salt, &mut signature).unwrap();
    eprintln!("signature: {:x?}", signature);
    verify_2048(
        DigestAlgorithm::Sha2_256,
        &pk,
        &msg,
        salt.len() as u32,
        &signature,
    )
    .expect("Error verifying signature");
}

const N: [u8; 256] = [
    0xa2, 0xb4, 0x51, 0xa0, 0x7d, 0x0a, 0xa5, 0xf9, 0x6e, 0x45, 0x56, 0x71, 0x51, 0x35, 0x50, 0x51,
    0x4a, 0x8a, 0x5b, 0x46, 0x2e, 0xbe, 0xf7, 0x17, 0x09, 0x4f, 0xa1, 0xfe, 0xe8, 0x22, 0x24, 0xe6,
    0x37, 0xf9, 0x74, 0x6d, 0x3f, 0x7c, 0xaf, 0xd3, 0x18, 0x78, 0xd8, 0x03, 0x25, 0xb6, 0xef, 0x5a,
    0x17, 0x00, 0xf6, 0x59, 0x03, 0xb4, 0x69, 0x42, 0x9e, 0x89, 0xd6, 0xea, 0xc8, 0x84, 0x50, 0x97,
    0xb5, 0xab, 0x39, 0x31, 0x89, 0xdb, 0x92, 0x51, 0x2e, 0xd8, 0xa7, 0x71, 0x1a, 0x12, 0x53, 0xfa,
    0xcd, 0x20, 0xf7, 0x9c, 0x15, 0xe8, 0x24, 0x7f, 0x3d, 0x3e, 0x42, 0xe4, 0x6e, 0x48, 0xc9, 0x8e,
    0x25, 0x4a, 0x2f, 0xe9, 0x76, 0x53, 0x13, 0xa0, 0x3e, 0xff, 0x8f, 0x17, 0xe1, 0xa0, 0x29, 0x39,
    0x7a, 0x1f, 0xa2, 0x6a, 0x8d, 0xce, 0x26, 0xf4, 0x90, 0xed, 0x81, 0x29, 0x96, 0x15, 0xd9, 0x81,
    0x4c, 0x22, 0xda, 0x61, 0x04, 0x28, 0xe0, 0x9c, 0x7d, 0x96, 0x58, 0x59, 0x42, 0x66, 0xf5, 0xc0,
    0x21, 0xd0, 0xfc, 0xec, 0xa0, 0x8d, 0x94, 0x5a, 0x12, 0xbe, 0x82, 0xde, 0x4d, 0x1e, 0xce, 0x6b,
    0x4c, 0x03, 0x14, 0x5b, 0x5d, 0x34, 0x95, 0xd4, 0xed, 0x54, 0x11, 0xeb, 0x87, 0x8d, 0xaf, 0x05,
    0xfd, 0x7a, 0xfc, 0x3e, 0x09, 0xad, 0xa0, 0xf1, 0x12, 0x64, 0x22, 0xf5, 0x90, 0x97, 0x5a, 0x19,
    0x69, 0x81, 0x6f, 0x48, 0x69, 0x8b, 0xcb, 0xba, 0x1b, 0x4d, 0x9c, 0xae, 0x79, 0xd4, 0x60, 0xd8,
    0xf9, 0xf8, 0x5e, 0x79, 0x75, 0x00, 0x5d, 0x9b, 0xc2, 0x2c, 0x4e, 0x5a, 0xc0, 0xf7, 0xc1, 0xa4,
    0x5d, 0x12, 0x56, 0x9a, 0x62, 0x80, 0x7d, 0x3b, 0x9a, 0x02, 0xe5, 0xa5, 0x30, 0xe7, 0x73, 0x06,
    0x6f, 0x45, 0x3d, 0x1f, 0x5b, 0x4c, 0x2e, 0x9c, 0xf7, 0x82, 0x02, 0x83, 0xf7, 0x42, 0xb9, 0xd5,
];

#[test]
fn wycheproof_single_test() {
    let pk = PublicKey::from(N);
    let msg: [u8; 0] = [];
    let signature: [u8; 256] = [
        0x20, 0x08, 0x1f, 0x88, 0x94, 0xa1, 0x33, 0x0c, 0x4d, 0x50, 0x3f, 0x64, 0x28, 0x80, 0xe3,
        0xc3, 0x0e, 0x39, 0x8f, 0xc6, 0x23, 0x5c, 0x24, 0xf1, 0xbe, 0x75, 0x2e, 0x2d, 0x49, 0xcd,
        0x94, 0x93, 0xac, 0x0c, 0xf9, 0x99, 0xe2, 0x75, 0xc4, 0xf8, 0x9f, 0xf0, 0x8f, 0x0d, 0x9b,
        0xa4, 0xe2, 0x64, 0xa3, 0x32, 0x52, 0x5a, 0x61, 0x6d, 0x33, 0x6b, 0xd9, 0xe8, 0x22, 0xf4,
        0x1a, 0xb3, 0xf4, 0xfa, 0xe2, 0xf4, 0x8e, 0xc6, 0x6c, 0x2e, 0x52, 0x64, 0x2e, 0xd9, 0x3b,
        0x7c, 0xb9, 0x44, 0x39, 0x6f, 0xba, 0xa7, 0x27, 0xcb, 0xfd, 0xfc, 0x1f, 0x20, 0xaa, 0xce,
        0x99, 0xa6, 0xf2, 0xa7, 0x44, 0x75, 0xc3, 0x38, 0xf8, 0xd9, 0xf2, 0x2a, 0x38, 0xcb, 0x5b,
        0xc5, 0x17, 0x52, 0x07, 0x65, 0x03, 0xb3, 0xae, 0xf1, 0xe6, 0x5e, 0x5a, 0x8f, 0x85, 0x83,
        0xd9, 0xae, 0x73, 0x78, 0xde, 0xd0, 0x38, 0xcf, 0x51, 0x68, 0x98, 0xad, 0x06, 0xbe, 0xb9,
        0x0a, 0x42, 0xb8, 0x57, 0x64, 0x52, 0x6f, 0xce, 0xa4, 0x4f, 0x74, 0x25, 0x8f, 0xa4, 0xef,
        0xb1, 0xda, 0x25, 0x3d, 0x33, 0x7f, 0x65, 0x61, 0x91, 0x81, 0xce, 0xb8, 0x32, 0xdf, 0xe2,
        0x85, 0xce, 0x78, 0xae, 0x6b, 0x15, 0xf2, 0x04, 0xe2, 0x3b, 0xab, 0x27, 0x4e, 0x87, 0x44,
        0x5d, 0x9f, 0x5d, 0xf9, 0x7f, 0x41, 0xdc, 0x8e, 0x3a, 0x97, 0x73, 0x6b, 0x62, 0x59, 0x1d,
        0x07, 0x57, 0x44, 0xb2, 0x55, 0x2f, 0x90, 0xbc, 0xf1, 0xb1, 0x39, 0x3e, 0x1e, 0x76, 0x27,
        0xef, 0x1f, 0x98, 0x5f, 0x2b, 0xba, 0xbd, 0x52, 0xe4, 0x3a, 0x35, 0xd0, 0xdd, 0xf4, 0xc6,
        0x71, 0x26, 0xe3, 0x91, 0xf9, 0x22, 0xef, 0x7b, 0x1b, 0xb1, 0x91, 0x1c, 0xd6, 0xe1, 0xb3,
        0x03, 0xcb, 0x29, 0x10, 0xdd, 0x70, 0x67, 0x2b, 0xbf, 0xb6, 0x2e, 0xa4, 0xea, 0xad, 0x72,
        0x5c,
    ];
    verify_2048(DigestAlgorithm::Sha2_256, &pk, &msg, 0, &signature.into())
        .expect("Error verifying signature");

    let msg = [0x33, 0x32, 0x32, 0x32, 0x30, 0x34, 0x31, 0x30, 0x34, 0x36];
    let signature: [u8; 256] = [
        0x6b, 0x9a, 0x45, 0xec, 0x51, 0x7b, 0xf8, 0x38, 0xa5, 0x35, 0xed, 0x93, 0xfb, 0x36, 0xbb,
        0x02, 0x74, 0x71, 0xb1, 0x1d, 0x20, 0xd0, 0xbf, 0x6b, 0x1e, 0xda, 0xae, 0xef, 0xa2, 0x5b,
        0xcc, 0xdf, 0x58, 0x81, 0xf3, 0x44, 0x09, 0xa0, 0x42, 0xda, 0xdb, 0xe4, 0xa7, 0xb3, 0xc4,
        0x1b, 0xf2, 0x4a, 0xbe, 0x66, 0xc1, 0xf7, 0xf3, 0x7b, 0x92, 0xb9, 0x65, 0x8f, 0x59, 0xc5,
        0x5f, 0xa8, 0x8a, 0xa1, 0x63, 0x24, 0x65, 0xba, 0x82, 0x45, 0xc5, 0xf0, 0xc9, 0x8d, 0x08,
        0x2f, 0xca, 0xbb, 0x5e, 0x9f, 0xb8, 0x34, 0xd7, 0x27, 0xa3, 0x54, 0xf8, 0xf8, 0xa7, 0xfc,
        0xdb, 0x8d, 0x32, 0x30, 0x72, 0x54, 0x72, 0xa6, 0xa4, 0xec, 0xb6, 0xf3, 0xd9, 0x75, 0x40,
        0x77, 0x3e, 0x53, 0xeb, 0x45, 0x38, 0x3a, 0xcb, 0xe4, 0xbc, 0x81, 0x16, 0x8e, 0x24, 0x4f,
        0xe7, 0x69, 0xb1, 0xa7, 0xd5, 0x22, 0x0d, 0xbc, 0xaf, 0x83, 0x1e, 0x46, 0xc9, 0x3f, 0x6e,
        0xa7, 0xca, 0x2e, 0xe3, 0x0c, 0xe9, 0x28, 0x1d, 0xd9, 0x67, 0x4f, 0xcc, 0xdc, 0x79, 0x6f,
        0xd6, 0x14, 0x7b, 0xe4, 0xbd, 0x99, 0xc5, 0x3a, 0x12, 0xea, 0xcf, 0xd4, 0xb9, 0xb0, 0x09,
        0x72, 0xb0, 0x53, 0x9e, 0x3d, 0x94, 0xb8, 0x59, 0x11, 0x69, 0x4e, 0xa9, 0x8f, 0x27, 0x49,
        0x6b, 0x56, 0x7a, 0x29, 0xfd, 0x30, 0x87, 0x84, 0x2b, 0xa0, 0x14, 0x02, 0x90, 0x1d, 0x1b,
        0xb1, 0xba, 0x6b, 0x3c, 0x79, 0x31, 0xf1, 0x32, 0x9f, 0xf5, 0x64, 0x49, 0x89, 0xbd, 0xc1,
        0xf7, 0x02, 0x50, 0x59, 0xd0, 0xd0, 0x69, 0x51, 0x7f, 0xbb, 0x68, 0x2c, 0x0b, 0xe0, 0x49,
        0xec, 0x7e, 0x38, 0xb6, 0x14, 0xaf, 0x1c, 0xf9, 0xcc, 0x37, 0xea, 0xb7, 0x4e, 0x20, 0xe6,
        0xbc, 0xa4, 0x68, 0xf9, 0x3d, 0x3f, 0x13, 0x74, 0x95, 0x57, 0xb7, 0x01, 0x29, 0xef, 0x95,
        0xe5,
    ];
    verify_2048(DigestAlgorithm::Sha2_256, &pk, &msg, 32, &signature.into())
        .expect("Error verifying signature");
}
