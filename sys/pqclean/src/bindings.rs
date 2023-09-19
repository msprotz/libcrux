/* automatically generated by rust-bindgen 0.68.1 */

pub const SHAKE128_RATE: u32 = 168;
pub const SHAKE256_RATE: u32 = 136;
pub const SHA3_256_RATE: u32 = 136;
pub const SHA3_384_RATE: u32 = 104;
pub const SHA3_512_RATE: u32 = 72;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct shake128incctx {
    pub ctx: *mut u64,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct shake128ctx {
    pub ctx: *mut u64,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct shake256incctx {
    pub ctx: *mut u64,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct shake256ctx {
    pub ctx: *mut u64,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct sha3_256incctx {
    pub ctx: *mut u64,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct sha3_384incctx {
    pub ctx: *mut u64,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct sha3_512incctx {
    pub ctx: *mut u64,
}
extern "C" {
    pub fn shake128_absorb(state: *mut shake128ctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn shake128_squeezeblocks(output: *mut u8, nblocks: usize, state: *mut shake128ctx);
}
extern "C" {
    pub fn shake128_ctx_release(state: *mut shake128ctx);
}
extern "C" {
    pub fn shake128_ctx_clone(dest: *mut shake128ctx, src: *const shake128ctx);
}
extern "C" {
    pub fn shake128_inc_init(state: *mut shake128incctx);
}
extern "C" {
    pub fn shake128_inc_absorb(state: *mut shake128incctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn shake128_inc_finalize(state: *mut shake128incctx);
}
extern "C" {
    pub fn shake128_inc_squeeze(output: *mut u8, outlen: usize, state: *mut shake128incctx);
}
extern "C" {
    pub fn shake128_inc_ctx_clone(dest: *mut shake128incctx, src: *const shake128incctx);
}
extern "C" {
    pub fn shake128_inc_ctx_release(state: *mut shake128incctx);
}
extern "C" {
    pub fn shake256_absorb(state: *mut shake256ctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn shake256_squeezeblocks(output: *mut u8, nblocks: usize, state: *mut shake256ctx);
}
extern "C" {
    pub fn shake256_ctx_release(state: *mut shake256ctx);
}
extern "C" {
    pub fn shake256_ctx_clone(dest: *mut shake256ctx, src: *const shake256ctx);
}
extern "C" {
    pub fn shake256_inc_init(state: *mut shake256incctx);
}
extern "C" {
    pub fn shake256_inc_absorb(state: *mut shake256incctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn shake256_inc_finalize(state: *mut shake256incctx);
}
extern "C" {
    pub fn shake256_inc_squeeze(output: *mut u8, outlen: usize, state: *mut shake256incctx);
}
extern "C" {
    pub fn shake256_inc_ctx_clone(dest: *mut shake256incctx, src: *const shake256incctx);
}
extern "C" {
    pub fn shake256_inc_ctx_release(state: *mut shake256incctx);
}
extern "C" {
    pub fn shake128(output: *mut u8, outlen: usize, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn shake256(output: *mut u8, outlen: usize, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn sha3_256_inc_init(state: *mut sha3_256incctx);
}
extern "C" {
    pub fn sha3_256_inc_absorb(state: *mut sha3_256incctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn sha3_256_inc_finalize(output: *mut u8, state: *mut sha3_256incctx);
}
extern "C" {
    pub fn sha3_256_inc_ctx_clone(dest: *mut sha3_256incctx, src: *const sha3_256incctx);
}
extern "C" {
    pub fn sha3_256_inc_ctx_release(state: *mut sha3_256incctx);
}
extern "C" {
    pub fn sha3_256(output: *mut u8, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn sha3_384_inc_init(state: *mut sha3_384incctx);
}
extern "C" {
    pub fn sha3_384_inc_absorb(state: *mut sha3_384incctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn sha3_384_inc_finalize(output: *mut u8, state: *mut sha3_384incctx);
}
extern "C" {
    pub fn sha3_384_inc_ctx_clone(dest: *mut sha3_384incctx, src: *const sha3_384incctx);
}
extern "C" {
    pub fn sha3_384_inc_ctx_release(state: *mut sha3_384incctx);
}
extern "C" {
    pub fn sha3_384(output: *mut u8, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn sha3_512_inc_init(state: *mut sha3_512incctx);
}
extern "C" {
    pub fn sha3_512_inc_absorb(state: *mut sha3_512incctx, input: *const u8, inlen: usize);
}
extern "C" {
    pub fn sha3_512_inc_finalize(output: *mut u8, state: *mut sha3_512incctx);
}
extern "C" {
    pub fn sha3_512_inc_ctx_clone(dest: *mut sha3_512incctx, src: *const sha3_512incctx);
}
extern "C" {
    pub fn sha3_512_inc_ctx_release(state: *mut sha3_512incctx);
}
extern "C" {
    pub fn sha3_512(output: *mut u8, input: *const u8, inlen: usize);
}
