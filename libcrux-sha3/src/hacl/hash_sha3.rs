#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(unused_assignments)]
#![allow(unused_mut)]
#![allow(unreachable_patterns)]
#![allow(const_item_mutation)]

#[inline(always)]
fn block_len(a: crate::hacl::streaming_types::hash_alg) -> u32 {
    match a {
        crate::hacl::streaming_types::hash_alg::SHA3_224 => 144u32,
        crate::hacl::streaming_types::hash_alg::SHA3_256 => 136u32,
        crate::hacl::streaming_types::hash_alg::SHA3_384 => 104u32,
        crate::hacl::streaming_types::hash_alg::SHA3_512 => 72u32,
        crate::hacl::streaming_types::hash_alg::Shake128 => 168u32,
        crate::hacl::streaming_types::hash_alg::Shake256 => 136u32,
        _ => panic!("Precondition of the function most likely violated"),
    }
}

#[inline(always)]
fn hash_len(a: crate::hacl::streaming_types::hash_alg) -> u32 {
    match a {
        crate::hacl::streaming_types::hash_alg::SHA3_224 => 28u32,
        crate::hacl::streaming_types::hash_alg::SHA3_256 => 32u32,
        crate::hacl::streaming_types::hash_alg::SHA3_384 => 48u32,
        crate::hacl::streaming_types::hash_alg::SHA3_512 => 64u32,
        _ => panic!("Precondition of the function most likely violated"),
    }
}

#[inline(always)]
pub fn update_multi_sha3(
    a: crate::hacl::streaming_types::hash_alg,
    s: &mut [u64],
    blocks: &mut [u8],
    n_blocks: u32,
) -> () {
    for i in 0u32..n_blocks {
        let block: (&mut [u8], &mut [u8]) =
            blocks.split_at_mut(i.wrapping_mul(block_len(a)) as usize);
        absorb_inner(block_len(a), block.1, s)
    }
}

#[inline(always)]
pub fn update_last_sha3(
    a: crate::hacl::streaming_types::hash_alg,
    s: &mut [u64],
    input: &mut [u8],
    input_len: u32,
) -> () {
    let suffix: u8 = if a == crate::hacl::streaming_types::hash_alg::Shake128
        || a == crate::hacl::streaming_types::hash_alg::Shake256
    {
        0x1fu8
    } else {
        0x06u8
    };
    let len: u32 = block_len(a);
    if input_len == len {
        absorb_inner(len, input, s);
        let mut lastBlock_: [u8; 200] = [0u8; 200usize];
        let lastBlock: (&mut [u8], &mut [u8]) = (&mut lastBlock_).split_at_mut(0usize);
        (lastBlock.1[0usize..0usize])
            .copy_from_slice(&(&mut input[input_len as usize..])[0usize..0usize]);
        lastBlock.1[0usize] = suffix;
        loadState(len, lastBlock.1, s);
        if !(suffix & 0x80u8 == 0u8) && 0u32 == len.wrapping_sub(1u32) {
            state_permute(s)
        };
        let mut nextBlock_: [u8; 200] = [0u8; 200usize];
        let nextBlock: (&mut [u8], &mut [u8]) = (&mut nextBlock_).split_at_mut(0usize);
        nextBlock.1[len.wrapping_sub(1u32) as usize] = 0x80u8;
        loadState(len, nextBlock.1, s);
        state_permute(s)
    } else {
        let mut lastBlock_: [u8; 200] = [0u8; 200usize];
        let lastBlock: (&mut [u8], &mut [u8]) = (&mut lastBlock_).split_at_mut(0usize);
        (lastBlock.1[0usize..input_len as usize])
            .copy_from_slice(&input[0usize..input_len as usize]);
        lastBlock.1[input_len as usize] = suffix;
        loadState(len, lastBlock.1, s);
        if !(suffix & 0x80u8 == 0u8) && input_len == len.wrapping_sub(1u32) {
            state_permute(s)
        };
        let mut nextBlock_: [u8; 200] = [0u8; 200usize];
        let nextBlock: (&mut [u8], &mut [u8]) = (&mut nextBlock_).split_at_mut(0usize);
        nextBlock.1[len.wrapping_sub(1u32) as usize] = 0x80u8;
        loadState(len, nextBlock.1, s);
        state_permute(s)
    }
}

pub struct hash_buf {
    pub fst: crate::hacl::streaming_types::hash_alg,
    pub snd: Vec<u64>,
}

pub struct state_t {
    pub block_state: hash_buf,
    pub buf: Vec<u8>,
    pub total_len: u64,
}

#[inline(always)]
pub fn get_alg(s: &mut [state_t]) -> crate::hacl::streaming_types::hash_alg {
    let mut block_state: &mut hash_buf = &mut (s[0usize]).block_state;
    (*block_state).fst
}

#[inline(always)]
pub fn malloc(a: crate::hacl::streaming_types::hash_alg) -> Vec<state_t> {
    let mut buf: Vec<u8> = vec![0u8; block_len(a) as usize];
    let mut buf0: Vec<u64> = vec![0u64; 25usize];
    let mut block_state: hash_buf = hash_buf { fst: a, snd: buf0 };
    let s: &mut [u64] = &mut block_state.snd;
    (s[0usize..25usize]).copy_from_slice(&[0u64; 25usize]);
    let mut s0: state_t = state_t {
        block_state: block_state,
        buf: buf,
        total_len: 0u32 as u64,
    };
    let mut p: Vec<state_t> = {
        let mut tmp: Vec<state_t> = Vec::new();
        tmp.push(s0);
        tmp
    };
    p
}

#[inline(always)]
pub fn copy(state: &mut [state_t]) -> Vec<state_t> {
    let mut block_state0: &mut hash_buf = &mut (state[0usize]).block_state;
    let buf0: &mut [u8] = &mut (state[0usize]).buf;
    let total_len0: u64 = (state[0usize]).total_len;
    let i: crate::hacl::streaming_types::hash_alg = (*block_state0).fst;
    let mut buf: Vec<u8> = vec![0u8; block_len(i) as usize];
    ((&mut buf)[0usize..block_len(i) as usize])
        .copy_from_slice(&buf0[0usize..block_len(i) as usize]);
    let mut buf1: Vec<u64> = vec![0u64; 25usize];
    let mut block_state: hash_buf = hash_buf { fst: i, snd: buf1 };
    let s_src: &mut [u64] = &mut (*block_state0).snd;
    let s_dst: &mut [u64] = &mut block_state.snd;
    (s_dst[0usize..25usize]).copy_from_slice(&s_src[0usize..25usize]);
    let mut s: state_t = state_t {
        block_state: block_state,
        buf: buf,
        total_len: total_len0,
    };
    let mut p: Vec<state_t> = {
        let mut tmp: Vec<state_t> = Vec::new();
        tmp.push(s);
        tmp
    };
    p
}

#[inline(always)]
pub fn reset(state: &mut [state_t]) -> () {
    let mut block_state: &mut hash_buf = &mut (state[0usize]).block_state;
    let i: crate::hacl::streaming_types::hash_alg = (*block_state).fst;
    crate::lowstar::ignore::ignore::<crate::hacl::streaming_types::hash_alg>(i);
    let s: &mut [u64] = &mut (*block_state).snd;
    (s[0usize..25usize]).copy_from_slice(&[0u64; 25usize]);
    (state[0usize]).total_len = 0u32 as u64
}

#[inline(always)]
pub fn update(
    state: &mut [state_t],
    chunk: &mut [u8],
    chunk_len: u32,
) -> crate::hacl::streaming_types::error_code {
    let mut block_state: &mut hash_buf = &mut (state[0usize]).block_state;
    let total_len: u64 = (state[0usize]).total_len;
    let i: crate::hacl::streaming_types::hash_alg = (*block_state).fst;
    if chunk_len as u64 > 0xFFFFFFFFFFFFFFFFu64.wrapping_sub(total_len) {
        crate::hacl::streaming_types::error_code::MaximumLengthExceeded
    } else {
        let sz: u32 = if total_len.wrapping_rem(block_len(i) as u64) == 0u64 && total_len > 0u64 {
            block_len(i)
        } else {
            total_len.wrapping_rem(block_len(i) as u64) as u32
        };
        if chunk_len <= (block_len(i)).wrapping_sub(sz) {
            let buf: &mut [u8] = &mut (state[0usize]).buf;
            let total_len1: u64 = (state[0usize]).total_len;
            let sz1: u32 =
                if total_len1.wrapping_rem(block_len(i) as u64) == 0u64 && total_len1 > 0u64 {
                    block_len(i)
                } else {
                    total_len1.wrapping_rem(block_len(i) as u64) as u32
                };
            let buf2: (&mut [u8], &mut [u8]) = buf.split_at_mut(sz1 as usize);
            (buf2.1[0usize..chunk_len as usize])
                .copy_from_slice(&chunk[0usize..chunk_len as usize]);
            let total_len2: u64 = total_len1.wrapping_add(chunk_len as u64);
            (state[0usize]).total_len = total_len2
        } else if sz == 0u32 {
            let buf: &mut [u8] = &mut (state[0usize]).buf;
            let total_len1: u64 = (state[0usize]).total_len;
            let sz1: u32 =
                if total_len1.wrapping_rem(block_len(i) as u64) == 0u64 && total_len1 > 0u64 {
                    block_len(i)
                } else {
                    total_len1.wrapping_rem(block_len(i) as u64) as u32
                };
            if !(sz1 == 0u32) {
                let a1: crate::hacl::streaming_types::hash_alg = (*block_state).fst;
                let s1: &mut [u64] = &mut (*block_state).snd;
                update_multi_sha3(a1, s1, buf, (block_len(i)).wrapping_div(block_len(a1)))
            };
            let ite: u32 = if (chunk_len as u64).wrapping_rem(block_len(i) as u64) == 0u64
                && chunk_len as u64 > 0u64
            {
                block_len(i)
            } else {
                (chunk_len as u64).wrapping_rem(block_len(i) as u64) as u32
            };
            let n_blocks: u32 = chunk_len.wrapping_sub(ite).wrapping_div(block_len(i));
            let data1_len: u32 = n_blocks.wrapping_mul(block_len(i));
            let data2_len: u32 = chunk_len.wrapping_sub(data1_len);
            let data1: (&mut [u8], &mut [u8]) = chunk.split_at_mut(0usize);
            let data2: (&mut [u8], &mut [u8]) = data1.1.split_at_mut(data1_len as usize);
            let a1: crate::hacl::streaming_types::hash_alg = (*block_state).fst;
            let s1: &mut [u64] = &mut (*block_state).snd;
            update_multi_sha3(a1, s1, data2.0, data1_len.wrapping_div(block_len(a1)));
            let dst: (&mut [u8], &mut [u8]) = buf.split_at_mut(0usize);
            (dst.1[0usize..data2_len as usize])
                .copy_from_slice(&data2.1[0usize..data2_len as usize]);
            (state[0usize]).total_len = total_len1.wrapping_add(chunk_len as u64)
        } else {
            let diff: u32 = (block_len(i)).wrapping_sub(sz);
            let chunk1: (&mut [u8], &mut [u8]) = chunk.split_at_mut(0usize);
            let chunk2: (&mut [u8], &mut [u8]) = chunk1.1.split_at_mut(diff as usize);
            let buf: &mut [u8] = &mut (state[0usize]).buf;
            let total_len1: u64 = (state[0usize]).total_len;
            let sz1: u32 =
                if total_len1.wrapping_rem(block_len(i) as u64) == 0u64 && total_len1 > 0u64 {
                    block_len(i)
                } else {
                    total_len1.wrapping_rem(block_len(i) as u64) as u32
                };
            let buf2: (&mut [u8], &mut [u8]) = buf.split_at_mut(sz1 as usize);
            (buf2.1[0usize..diff as usize]).copy_from_slice(&chunk2.0[0usize..diff as usize]);
            let total_len2: u64 = total_len1.wrapping_add(diff as u64);
            (state[0usize]).total_len = total_len2;
            let buf0: &mut [u8] = &mut (state[0usize]).buf;
            let total_len10: u64 = (state[0usize]).total_len;
            let sz10: u32 =
                if total_len10.wrapping_rem(block_len(i) as u64) == 0u64 && total_len10 > 0u64 {
                    block_len(i)
                } else {
                    total_len10.wrapping_rem(block_len(i) as u64) as u32
                };
            if !(sz10 == 0u32) {
                let a1: crate::hacl::streaming_types::hash_alg = (*block_state).fst;
                let s1: &mut [u64] = &mut (*block_state).snd;
                update_multi_sha3(a1, s1, buf0, (block_len(i)).wrapping_div(block_len(a1)))
            };
            let ite: u32 =
                if (chunk_len.wrapping_sub(diff) as u64).wrapping_rem(block_len(i) as u64) == 0u64
                    && chunk_len.wrapping_sub(diff) as u64 > 0u64
                {
                    block_len(i)
                } else {
                    (chunk_len.wrapping_sub(diff) as u64).wrapping_rem(block_len(i) as u64) as u32
                };
            let n_blocks: u32 = chunk_len
                .wrapping_sub(diff)
                .wrapping_sub(ite)
                .wrapping_div(block_len(i));
            let data1_len: u32 = n_blocks.wrapping_mul(block_len(i));
            let data2_len: u32 = chunk_len.wrapping_sub(diff).wrapping_sub(data1_len);
            let data1: (&mut [u8], &mut [u8]) = chunk2.1.split_at_mut(0usize);
            let data2: (&mut [u8], &mut [u8]) = data1.1.split_at_mut(data1_len as usize);
            let a1: crate::hacl::streaming_types::hash_alg = (*block_state).fst;
            let s1: &mut [u64] = &mut (*block_state).snd;
            update_multi_sha3(a1, s1, data2.0, data1_len.wrapping_div(block_len(a1)));
            let dst: (&mut [u8], &mut [u8]) = buf0.split_at_mut(0usize);
            (dst.1[0usize..data2_len as usize])
                .copy_from_slice(&data2.1[0usize..data2_len as usize]);
            (state[0usize]).total_len =
                total_len10.wrapping_add(chunk_len.wrapping_sub(diff) as u64)
        };
        crate::hacl::streaming_types::error_code::Success
    }
}

#[inline(always)]
fn digest_(
    a: crate::hacl::streaming_types::hash_alg,
    state: &mut [state_t],
    output: &mut [u8],
    l: u32,
) -> () {
    let mut block_state: &mut hash_buf = &mut (state[0usize]).block_state;
    let buf_: &mut [u8] = &mut (state[0usize]).buf;
    let total_len: u64 = (state[0usize]).total_len;
    let r: u32 = if total_len.wrapping_rem(block_len(a) as u64) == 0u64 && total_len > 0u64 {
        block_len(a)
    } else {
        total_len.wrapping_rem(block_len(a) as u64) as u32
    };
    let buf_1: (&mut [u8], &mut [u8]) = buf_.split_at_mut(0usize);
    let mut buf: [u64; 25] = [0u64; 25usize];
    let mut tmp_block_state: hash_buf = hash_buf {
        fst: a,
        snd: Vec::from(buf),
    };
    let s_src: &mut [u64] = &mut (*block_state).snd;
    let s_dst: &mut [u64] = &mut tmp_block_state.snd;
    (s_dst[0usize..25usize]).copy_from_slice(&s_src[0usize..25usize]);
    let buf_multi: (&mut [u8], &mut [u8]) = buf_1.1.split_at_mut(0usize);
    let ite: u32 = if r.wrapping_rem(block_len(a)) == 0u32 && r > 0u32 {
        block_len(a)
    } else {
        r.wrapping_rem(block_len(a))
    };
    let buf_last: (&mut [u8], &mut [u8]) = buf_multi.1.split_at_mut(r.wrapping_sub(ite) as usize);
    let a1: crate::hacl::streaming_types::hash_alg = tmp_block_state.fst;
    let s: &mut [u64] = &mut tmp_block_state.snd;
    update_multi_sha3(a1, s, buf_last.0, 0u32.wrapping_div(block_len(a1)));
    let a10: crate::hacl::streaming_types::hash_alg = tmp_block_state.fst;
    let s0: &mut [u64] = &mut tmp_block_state.snd;
    update_last_sha3(a10, s0, buf_last.1, r);
    let a11: crate::hacl::streaming_types::hash_alg = tmp_block_state.fst;
    let s1: &mut [u64] = &mut tmp_block_state.snd;
    if a11 == crate::hacl::streaming_types::hash_alg::Shake128
        || a11 == crate::hacl::streaming_types::hash_alg::Shake256
    {
        squeeze0(s1, block_len(a11), l, output)
    } else {
        squeeze0(s1, block_len(a11), hash_len(a11), output)
    }
}

#[inline(always)]
pub fn digest(
    state: &mut [state_t],
    output: &mut [u8],
) -> crate::hacl::streaming_types::error_code {
    let a1: crate::hacl::streaming_types::hash_alg = get_alg(state);
    if a1 == crate::hacl::streaming_types::hash_alg::Shake128
        || a1 == crate::hacl::streaming_types::hash_alg::Shake256
    {
        crate::hacl::streaming_types::error_code::InvalidAlgorithm
    } else {
        digest_(a1, state, output, hash_len(a1));
        crate::hacl::streaming_types::error_code::Success
    }
}

#[inline(always)]
pub fn squeeze(
    s: &mut [state_t],
    dst: &mut [u8],
    l: u32,
) -> crate::hacl::streaming_types::error_code {
    let a1: crate::hacl::streaming_types::hash_alg = get_alg(s);
    if !(a1 == crate::hacl::streaming_types::hash_alg::Shake128
        || a1 == crate::hacl::streaming_types::hash_alg::Shake256)
    {
        crate::hacl::streaming_types::error_code::InvalidAlgorithm
    } else if l == 0u32 {
        crate::hacl::streaming_types::error_code::InvalidLength
    } else {
        digest_(a1, s, dst, l);
        crate::hacl::streaming_types::error_code::Success
    }
}

#[inline(always)]
pub fn block_len0(s: &mut [state_t]) -> u32 {
    let a1: crate::hacl::streaming_types::hash_alg = get_alg(s);
    block_len(a1)
}

#[inline(always)]
pub fn hash_len0(s: &mut [state_t]) -> u32 {
    let a1: crate::hacl::streaming_types::hash_alg = get_alg(s);
    hash_len(a1)
}

#[inline(always)]
pub fn is_shake(s: &mut [state_t]) -> bool {
    let uu____0: crate::hacl::streaming_types::hash_alg = get_alg(s);
    uu____0 == crate::hacl::streaming_types::hash_alg::Shake128
        || uu____0 == crate::hacl::streaming_types::hash_alg::Shake256
}

#[inline(always)]
pub fn shake128_hacl(
    inputByteLen: u32,
    input: &mut [u8],
    outputByteLen: u32,
    output: &mut [u8],
) -> () {
    keccak(
        1344u32,
        256u32,
        inputByteLen,
        input,
        0x1Fu8,
        outputByteLen,
        output,
    )
}

#[inline(always)]
pub fn shake256_hacl(
    inputByteLen: u32,
    input: &mut [u8],
    outputByteLen: u32,
    output: &mut [u8],
) -> () {
    keccak(
        1088u32,
        512u32,
        inputByteLen,
        input,
        0x1Fu8,
        outputByteLen,
        output,
    )
}

#[inline(always)]
pub fn sha3_224(output: &mut [u8], input: &mut [u8], input_len: u32) -> () {
    keccak(1152u32, 448u32, input_len, input, 0x06u8, 28u32, output)
}

#[inline(always)]
pub fn sha3_256(output: &mut [u8], input: &mut [u8], input_len: u32) -> () {
    keccak(1088u32, 512u32, input_len, input, 0x06u8, 32u32, output)
}

#[inline(always)]
pub fn sha3_384(output: &mut [u8], input: &mut [u8], input_len: u32) -> () {
    keccak(832u32, 768u32, input_len, input, 0x06u8, 48u32, output)
}

#[inline(always)]
pub fn sha3_512(output: &mut [u8], input: &mut [u8], input_len: u32) -> () {
    keccak(576u32, 1024u32, input_len, input, 0x06u8, 64u32, output)
}

const keccak_rotc: [u32; 24] = [
    1u32, 3u32, 6u32, 10u32, 15u32, 21u32, 28u32, 36u32, 45u32, 55u32, 2u32, 14u32, 27u32, 41u32,
    56u32, 8u32, 25u32, 43u32, 62u32, 18u32, 39u32, 61u32, 20u32, 44u32,
];

const keccak_piln: [usize; 24] = [
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20, 14, 22, 9, 6, 1,
];

const keccak_rndc: [u64; 24] = [
    0x0000000000000001u64,
    0x0000000000008082u64,
    0x800000000000808au64,
    0x8000000080008000u64,
    0x000000000000808bu64,
    0x0000000080000001u64,
    0x8000000080008081u64,
    0x8000000000008009u64,
    0x000000000000008au64,
    0x0000000000000088u64,
    0x0000000080008009u64,
    0x000000008000000au64,
    0x000000008000808bu64,
    0x800000000000008bu64,
    0x8000000000008089u64,
    0x8000000000008003u64,
    0x8000000000008002u64,
    0x8000000000000080u64,
    0x000000000000800au64,
    0x800000008000000au64,
    0x8000000080008081u64,
    0x8000000000008080u64,
    0x0000000080000001u64,
    0x8000000080008008u64,
];

#[inline(always)]
pub fn state_permute(s: &mut [u64]) -> () {
    let mut _C: [u64; 5] = [0u64; 5usize];
    for i in 0usize..24 {
        for i0 in 0..5 {
            _C[i0] = s[0 + 0] ^ (s[0 + 5] ^ (s[0 + 10] ^ (s[0 + 15] ^ s[0 + 20])))
        }
        for i0 in 0usize..5 {
            let uu____0: u64 = _C[(i0 + 1) % (5)];
            let _D: u64 = _C[(i0 + 4) % (5)] ^ (uu____0 << 1u32 | uu____0 >> 63);
            for i1 in 0..5 {
                s[i0 + 5 * i1] = s[i0 + 5 * i1] ^ _D
            }
        }
        // let x: u64 = s[1usize];
        unrolled_loop(s);
        for i0 in 0..5 {
            let v0: u64 = s[0 + (5 * (i0))] ^ !s[1 + (5 * (i0))] & s[2 + (5 * (i0))];
            let v1: u64 = s[1 + (5 * (i0))] ^ !s[2 + (5 * (i0))] & s[3 + (5 * (i0))];
            let v2: u64 = s[2 + (5 * (i0))] ^ !s[3 + (5 * (i0))] & s[4 + (5 * (i0))];
            let v3: u64 = s[3 + (5 * (i0))] ^ !s[4 + (5 * (i0))] & s[0 + (5 * (i0))];
            let v4: u64 = s[4 + (5 * (i0))] ^ !s[0 + (5 * (i0))] & s[1 + (5 * (i0))];
            s[0 + (5 * (i0))] = v0;
            s[1 + (5 * (i0))] = v1;
            s[2 + (5 * (i0))] = v2;
            s[3 + (5 * (i0))] = v3;
            s[4 + (5 * (i0))] = v4
        }
        let c: u64 = keccak_rndc[i];
        s[0usize] = s[0usize] ^ c
    }
}

#[inline(always)]
#[inline(always)]
fn unrolled_loop(s: &mut [u64]) {
    let mut current = s[1];
    // for i0 in 0..24 {
    let r = keccak_rotc[0];
    let temp: u64 = s[keccak_piln[0]];
    s[keccak_piln[0]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[1];
    let temp: u64 = s[keccak_piln[1]];
    s[keccak_piln[1]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[2];
    let temp: u64 = s[keccak_piln[2]];
    s[keccak_piln[2]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[3];
    let temp: u64 = s[keccak_piln[3]];
    s[keccak_piln[3]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[4];
    let temp: u64 = s[keccak_piln[4]];
    s[keccak_piln[4]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[5];
    let temp: u64 = s[keccak_piln[5]];
    s[keccak_piln[5]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[6];
    let temp: u64 = s[keccak_piln[6]];
    s[keccak_piln[6]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[7];
    let temp: u64 = s[keccak_piln[7]];
    s[keccak_piln[7]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[8];
    let temp: u64 = s[keccak_piln[8]];
    s[keccak_piln[8]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[9];
    let temp: u64 = s[keccak_piln[9]];
    s[keccak_piln[9]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[10];
    let temp: u64 = s[keccak_piln[10]];
    s[keccak_piln[10]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[11];
    let temp: u64 = s[keccak_piln[11]];
    s[keccak_piln[11]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[12];
    let temp: u64 = s[keccak_piln[12]];
    s[keccak_piln[12]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[13];
    let temp: u64 = s[keccak_piln[13]];
    s[keccak_piln[13]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[14];
    let temp: u64 = s[keccak_piln[14]];
    s[keccak_piln[14]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[15];
    let temp: u64 = s[keccak_piln[15]];
    s[keccak_piln[15]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[16];
    let temp: u64 = s[keccak_piln[16]];
    s[keccak_piln[16]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[17];
    let temp: u64 = s[keccak_piln[17]];
    s[keccak_piln[17]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[18];
    let temp: u64 = s[keccak_piln[18]];
    s[keccak_piln[18]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[19];
    let temp: u64 = s[keccak_piln[19]];
    s[keccak_piln[19]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[20];
    let temp: u64 = s[keccak_piln[20]];
    s[keccak_piln[20]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[21];
    let temp: u64 = s[keccak_piln[21]];
    s[keccak_piln[21]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[22];
    let temp: u64 = s[keccak_piln[22]];
    s[keccak_piln[22]] = current << (r) | current >> (64u32 - r);
    current = temp;

    let r = keccak_rotc[23];
    let temp: u64 = s[keccak_piln[23]];
    s[keccak_piln[23]] = current << (r) | current >> (64u32 - r);
    current = temp;
    // }
}

#[inline(always)]
pub fn loadState(rateInBytes: u32, input: &mut [u8], s: &mut [u64]) -> () {
    let mut block: [u8; 200] = [0u8; 200usize];
    ((&mut block)[0usize..rateInBytes as usize])
        .copy_from_slice(&input[0usize..rateInBytes as usize]);
    for i in 0u32..25u32 {
        let u: u64 = crate::lowstar::endianness::load64_le(
            &mut (&mut block)[i.wrapping_mul(8u32) as usize..],
        );
        let x: u64 = u;
        s[i as usize] = s[i as usize] ^ x
    }
}

#[inline(always)]
fn storeState(rateInBytes: u32, s: &mut [u64], res: &mut [u8]) -> () {
    let mut block: [u8; 200] = [0u8; 200usize];
    for i in 0u32..25u32 {
        let sj: u64 = s[i as usize];
        crate::lowstar::endianness::store64_le(
            &mut (&mut block)[i.wrapping_mul(8u32) as usize..],
            sj,
        )
    }
    (res[0usize..rateInBytes as usize])
        .copy_from_slice(&(&mut (&mut block)[0usize..])[0usize..rateInBytes as usize])
}

#[inline(always)]
pub fn absorb_inner(rateInBytes: u32, block: &mut [u8], s: &mut [u64]) -> () {
    loadState(rateInBytes, block, s);
    state_permute(s)
}

#[inline(always)]
fn absorb(
    s: &mut [u64],
    rateInBytes: u32,
    inputByteLen: u32,
    input: &mut [u8],
    delimitedSuffix: u8,
) -> () {
    let n_blocks: u32 = inputByteLen.wrapping_div(rateInBytes);
    let rem: u32 = inputByteLen.wrapping_rem(rateInBytes);
    for i in 0u32..n_blocks {
        let block: (&mut [u8], &mut [u8]) =
            input.split_at_mut(i.wrapping_mul(rateInBytes) as usize);
        absorb_inner(rateInBytes, block.1, s)
    }
    let last: (&mut [u8], &mut [u8]) =
        input.split_at_mut(n_blocks.wrapping_mul(rateInBytes) as usize);
    let mut lastBlock_: [u8; 200] = [0u8; 200usize];
    let lastBlock: (&mut [u8], &mut [u8]) = (&mut lastBlock_).split_at_mut(0usize);
    (lastBlock.1[0usize..rem as usize]).copy_from_slice(&last.1[0usize..rem as usize]);
    lastBlock.1[rem as usize] = delimitedSuffix;
    loadState(rateInBytes, lastBlock.1, s);
    if !(delimitedSuffix & 0x80u8 == 0u8) && rem == rateInBytes.wrapping_sub(1u32) {
        state_permute(s)
    };
    let mut nextBlock_: [u8; 200] = [0u8; 200usize];
    let nextBlock: (&mut [u8], &mut [u8]) = (&mut nextBlock_).split_at_mut(0usize);
    nextBlock.1[rateInBytes.wrapping_sub(1u32) as usize] = 0x80u8;
    loadState(rateInBytes, nextBlock.1, s);
    state_permute(s)
}

#[inline(always)]
pub fn squeeze0(s: &mut [u64], rateInBytes: u32, outputByteLen: u32, output: &mut [u8]) -> () {
    let outBlocks: u32 = outputByteLen.wrapping_div(rateInBytes);
    let remOut: u32 = outputByteLen.wrapping_rem(rateInBytes);
    let blocks: (&mut [u8], &mut [u8]) = output.split_at_mut(0usize);
    let last: (&mut [u8], &mut [u8]) = blocks
        .1
        .split_at_mut(outputByteLen.wrapping_sub(remOut) as usize);
    for i in 0u32..outBlocks {
        storeState(
            rateInBytes,
            s,
            &mut last.0[i.wrapping_mul(rateInBytes) as usize..],
        );
        state_permute(s)
    }
    storeState(remOut, s, last.1)
}

#[inline(always)]
pub fn keccak(
    rate: u32,
    capacity: u32,
    inputByteLen: u32,
    input: &mut [u8],
    delimitedSuffix: u8,
    outputByteLen: u32,
    output: &mut [u8],
) -> () {
    crate::lowstar::ignore::ignore::<u32>(capacity);
    let rateInBytes: u32 = rate.wrapping_div(8u32);
    let mut s: [u64; 25] = [0u64; 25usize];
    absorb(&mut s, rateInBytes, inputByteLen, input, delimitedSuffix);
    squeeze0(&mut s, rateInBytes, outputByteLen, output)
}
