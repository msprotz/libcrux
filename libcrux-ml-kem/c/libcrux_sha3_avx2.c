/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 0f1b5e50fa4e96ed9e650d8334e1afbf2bf319b1
 * Eurydice: f415f299462ee62cdddcb42ae16b10bb6a7e4f0a
 * Karamel: 65aab550cf3ba36d52ae6ad1ad962bb573406395
 * F*: a32b316e521fa4f239b610ec8f1d15e78d62cbe8-dirty
 * Libcrux: fd115e1b6265143551fbd8d7924c933d055de75d
 */

#include "internal/libcrux_sha3_avx2.h"

#include "internal/libcrux_core.h"

static KRML_MUSTINLINE core_core_arch_x86___m256i zero(void) {
  return libcrux_intrinsics_avx2_mm256_set1_epi64x((int64_t)0);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_veor5q_u64(core_core_arch_x86___m256i a, core_core_arch_x86___m256i b,
            core_core_arch_x86___m256i c, core_core_arch_x86___m256i d,
            core_core_arch_x86___m256i e) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  core_core_arch_x86___m256i cd = libcrux_intrinsics_avx2_mm256_xor_si256(c, d);
  core_core_arch_x86___m256i abcd =
      libcrux_intrinsics_avx2_mm256_xor_si256(ab, cd);
  return libcrux_intrinsics_avx2_mm256_xor_si256(abcd, e);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor5(core_core_arch_x86___m256i a, core_core_arch_x86___m256i b,
     core_core_arch_x86___m256i c, core_core_arch_x86___m256i d,
     core_core_arch_x86___m256i e) {
  return _veor5q_u64(a, b, c, d, e);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___1int32_t_63int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)1, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)63, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vrax1q_u64(core_core_arch_x86___m256i a, core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i uu____0 = a;
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, rotate_left___1int32_t_63int32_t(b));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i rotate_left1_and_xor(
    core_core_arch_x86___m256i a, core_core_arch_x86___m256i b) {
  return _vrax1q_u64(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vbcaxq_u64(core_core_arch_x86___m256i a, core_core_arch_x86___m256i b,
            core_core_arch_x86___m256i c) {
  core_core_arch_x86___m256i uu____0 = a;
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_andnot_si256(c, b));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
and_not_xor(core_core_arch_x86___m256i a, core_core_arch_x86___m256i b,
            core_core_arch_x86___m256i c) {
  return _vbcaxq_u64(a, b, c);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_veorq_n_u64(core_core_arch_x86___m256i a, uint64_t c) {
  core_core_arch_x86___m256i c0 =
      libcrux_intrinsics_avx2_mm256_set1_epi64x((int64_t)c);
  return libcrux_intrinsics_avx2_mm256_xor_si256(a, c0);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_constant(core_core_arch_x86___m256i a, uint64_t c) {
  return _veorq_n_u64(a, c);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor0(core_core_arch_x86___m256i a, core_core_arch_x86___m256i b) {
  return libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
}

static KRML_MUSTINLINE void slice_4(Eurydice_slice a[4U], size_t start,
                                    size_t len, Eurydice_slice ret[4U]) {
  Eurydice_slice uu____0 = Eurydice_slice_subslice(
      a[0U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + len}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  Eurydice_slice uu____1 = Eurydice_slice_subslice(
      a[1U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + len}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  Eurydice_slice uu____2 = Eurydice_slice_subslice(
      a[2U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + len}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  ret[0U] = uu____0;
  ret[1U] = uu____1;
  ret[2U] = uu____2;
  ret[3U] = Eurydice_slice_subslice(a[3U],
                                    (CLITERAL(core_ops_range_Range__size_t){
                                        .start = start, .end = start + len}),
                                    uint8_t, core_ops_range_Range__size_t,
                                    Eurydice_slice);
}

static KRML_MUSTINLINE void slice_n(Eurydice_slice a[4U], size_t start,
                                    size_t len, Eurydice_slice ret[4U]) {
  Eurydice_slice uu____0[4U];
  memcpy(uu____0, a, (size_t)4U * sizeof(Eurydice_slice));
  Eurydice_slice ret0[4U];
  slice_4(uu____0, start, len, ret0);
  memcpy(ret, ret0, (size_t)4U * sizeof(Eurydice_slice));
}

static KRML_MUSTINLINE
    K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_
    split_at_mut_4(Eurydice_slice out[4U], size_t mid) {
  Eurydice_slice out0 = out[0U];
  Eurydice_slice out1 = out[1U];
  Eurydice_slice out2 = out[2U];
  Eurydice_slice out3 = out[3U];
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____0 =
      core_slice___Slice_T___split_at_mut(
          out0, mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out00 = uu____0.fst;
  Eurydice_slice out01 = uu____0.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____1 =
      core_slice___Slice_T___split_at_mut(
          out1, mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out10 = uu____1.fst;
  Eurydice_slice out11 = uu____1.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____2 =
      core_slice___Slice_T___split_at_mut(
          out2, mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out20 = uu____2.fst;
  Eurydice_slice out21 = uu____2.snd;
  K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t uu____3 =
      core_slice___Slice_T___split_at_mut(
          out3, mid, uint8_t,
          K___Eurydice_slice_uint8_t_Eurydice_slice_uint8_t);
  Eurydice_slice out30 = uu____3.fst;
  Eurydice_slice out31 = uu____3.snd;
  K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_ lit;
  lit.fst[0U] = out00;
  lit.fst[1U] = out10;
  lit.fst[2U] = out20;
  lit.fst[3U] = out30;
  lit.snd[0U] = out01;
  lit.snd[1U] = out11;
  lit.snd[2U] = out21;
  lit.snd[3U] = out31;
  return lit;
}

static KRML_MUSTINLINE
    K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_
    split_at_mut_n(Eurydice_slice a[4U], size_t mid) {
  return split_at_mut_4(a, mid);
}

static KRML_MUSTINLINE
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
    new__core_core_arch_x86___m256i_4size_t(void) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
      lit;
  lit.st[0U][0U] = zero();
  lit.st[0U][1U] = zero();
  lit.st[0U][2U] = zero();
  lit.st[0U][3U] = zero();
  lit.st[0U][4U] = zero();
  lit.st[1U][0U] = zero();
  lit.st[1U][1U] = zero();
  lit.st[1U][2U] = zero();
  lit.st[1U][3U] = zero();
  lit.st[1U][4U] = zero();
  lit.st[2U][0U] = zero();
  lit.st[2U][1U] = zero();
  lit.st[2U][2U] = zero();
  lit.st[2U][3U] = zero();
  lit.st[2U][4U] = zero();
  lit.st[3U][0U] = zero();
  lit.st[3U][1U] = zero();
  lit.st[3U][2U] = zero();
  lit.st[3U][3U] = zero();
  lit.st[3U][4U] = zero();
  lit.st[4U][0U] = zero();
  lit.st[4U][1U] = zero();
  lit.st[4U][2U] = zero();
  lit.st[4U][3U] = zero();
  lit.st[4U][4U] = zero();
  return lit;
}

static KRML_MUSTINLINE void load_block___136size_t(
    core_core_arch_x86___m256i (*s)[5U], Eurydice_slice blocks[4U]) {
  for (size_t i = (size_t)0U; i < (size_t)136U / (size_t)32U; i++) {
    size_t i0 = i;
    core_core_arch_x86___m256i v00 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[0U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v10 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[1U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v20 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[2U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v30 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[3U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v0l =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v00, v10);
    core_core_arch_x86___m256i v1h =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v00, v10);
    core_core_arch_x86___m256i v2l =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v20, v30);
    core_core_arch_x86___m256i v3h =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v20, v30);
    core_core_arch_x86___m256i v0 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32, v0l, v2l, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v1 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32, v1h, v3h, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v2 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49, v0l, v2l, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v3 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49, v1h, v3h, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i uu____0 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U], v0);
    s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U] = uu____0;
    core_core_arch_x86___m256i uu____1 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)1U) % (size_t)5U],
            v1);
    s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)4U * i0 + (size_t)1U) % (size_t)5U] = uu____1;
    core_core_arch_x86___m256i uu____2 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)2U) % (size_t)5U],
            v2);
    s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
     [((size_t)4U * i0 + (size_t)2U) % (size_t)5U] = uu____2;
    core_core_arch_x86___m256i uu____3 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)3U) % (size_t)5U],
            v3);
    s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
     [((size_t)4U * i0 + (size_t)3U) % (size_t)5U] = uu____3;
  }
  size_t rem = (size_t)136U % (size_t)32U;
  size_t start = (size_t)32U * ((size_t)136U / (size_t)32U);
  uint8_t u8s[32U] = {0U};
  Eurydice_slice uu____4 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                              .end = (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____4,
      Eurydice_slice_subslice(blocks[0U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____5 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)8U,
                                              .end = (size_t)16U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____5,
      Eurydice_slice_subslice(blocks[1U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____6 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)16U,
                                              .end = (size_t)24U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____6,
      Eurydice_slice_subslice(blocks[2U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____7 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)24U,
                                              .end = (size_t)32U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____7,
      Eurydice_slice_subslice(blocks[3U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  core_core_arch_x86___m256i u = libcrux_intrinsics_avx2_mm256_loadu_si256_u8(
      core_array___Array_T__N__23__as_slice((size_t)32U, u8s, uint8_t,
                                            Eurydice_slice));
  size_t i0 = (size_t)4U * ((size_t)136U / (size_t)32U) / (size_t)5U;
  size_t j0 = (size_t)4U * ((size_t)136U / (size_t)32U) % (size_t)5U;
  core_core_arch_x86___m256i uu____8 =
      libcrux_intrinsics_avx2_mm256_xor_si256(s[i0][j0], u);
  s[i0][j0] = uu____8;
  if (rem == (size_t)16U) {
    uint8_t u8s0[32U] = {0U};
    Eurydice_slice uu____9 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                .end = (size_t)8U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____9,
        Eurydice_slice_subslice(
            blocks[0U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____10 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)8U,
                                                .end = (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____10,
        Eurydice_slice_subslice(
            blocks[1U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____11 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)16U,
                                                .end = (size_t)24U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____11,
        Eurydice_slice_subslice(
            blocks[2U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____12 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)24U,
                                                .end = (size_t)32U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____12,
        Eurydice_slice_subslice(
            blocks[3U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    core_core_arch_x86___m256i u0 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(
            core_array___Array_T__N__23__as_slice((size_t)32U, u8s0, uint8_t,
                                                  Eurydice_slice));
    size_t i =
        ((size_t)4U * ((size_t)136U / (size_t)32U) + (size_t)1U) / (size_t)5U;
    size_t j =
        ((size_t)4U * ((size_t)136U / (size_t)32U) + (size_t)1U) % (size_t)5U;
    core_core_arch_x86___m256i uu____13 =
        libcrux_intrinsics_avx2_mm256_xor_si256(s[i][j], u0);
    s[i][j] = uu____13;
  }
}

static KRML_MUSTINLINE void load_block___136size_t0(
    core_core_arch_x86___m256i (*a)[5U], Eurydice_slice b[4U]) {
  core_core_arch_x86___m256i(*uu____0)[5U] = a;
  Eurydice_slice uu____1[4U];
  memcpy(uu____1, b, (size_t)4U * sizeof(Eurydice_slice));
  load_block___136size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___36int32_t_28int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)36, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)28, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___36int32_t_28int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___36int32_t_28int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___36int32_t_28int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___36int32_t_28int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___3int32_t_61int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)3, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)61, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___3int32_t_61int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___3int32_t_61int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___3int32_t_61int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___3int32_t_61int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___41int32_t_23int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)41, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)23, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___41int32_t_23int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___41int32_t_23int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___41int32_t_23int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___41int32_t_23int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___18int32_t_46int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)18, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)46, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___18int32_t_46int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___18int32_t_46int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___18int32_t_46int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___18int32_t_46int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___1int32_t_63int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___1int32_t_63int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___1int32_t_63int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___1int32_t_63int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___44int32_t_20int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)44, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)20, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___44int32_t_20int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___44int32_t_20int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___44int32_t_20int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___44int32_t_20int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___10int32_t_54int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)10, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)54, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___10int32_t_54int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___10int32_t_54int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___10int32_t_54int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___10int32_t_54int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___45int32_t_19int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)45, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)19, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___45int32_t_19int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___45int32_t_19int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___45int32_t_19int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___45int32_t_19int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___2int32_t_62int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)2, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)62, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___2int32_t_62int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___2int32_t_62int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___2int32_t_62int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___2int32_t_62int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___62int32_t_2int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)62, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)2, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___62int32_t_2int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___62int32_t_2int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___62int32_t_2int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___62int32_t_2int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___6int32_t_58int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)6, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)58, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___6int32_t_58int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___6int32_t_58int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___6int32_t_58int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___6int32_t_58int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___43int32_t_21int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)43, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)21, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___43int32_t_21int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___43int32_t_21int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___43int32_t_21int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___43int32_t_21int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___15int32_t_49int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)15, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)49, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___15int32_t_49int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___15int32_t_49int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___15int32_t_49int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___15int32_t_49int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___61int32_t_3int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)61, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)3, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___61int32_t_3int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___61int32_t_3int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___61int32_t_3int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___61int32_t_3int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___28int32_t_36int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)28, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)36, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___28int32_t_36int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___28int32_t_36int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___28int32_t_36int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___28int32_t_36int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___55int32_t_9int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)55, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)9, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___55int32_t_9int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___55int32_t_9int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___55int32_t_9int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___55int32_t_9int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___25int32_t_39int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)25, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)39, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___25int32_t_39int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___25int32_t_39int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___25int32_t_39int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___25int32_t_39int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___21int32_t_43int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)21, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)43, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___21int32_t_43int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___21int32_t_43int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___21int32_t_43int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___21int32_t_43int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___56int32_t_8int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)56, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)8, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___56int32_t_8int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___56int32_t_8int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___56int32_t_8int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___56int32_t_8int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___27int32_t_37int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)27, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)37, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___27int32_t_37int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___27int32_t_37int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___27int32_t_37int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___27int32_t_37int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___20int32_t_44int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)20, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)44, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___20int32_t_44int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___20int32_t_44int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___20int32_t_44int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___20int32_t_44int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___39int32_t_25int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)39, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)25, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___39int32_t_25int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___39int32_t_25int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___39int32_t_25int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___39int32_t_25int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___8int32_t_56int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)8, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)56, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___8int32_t_56int32_t(core_core_arch_x86___m256i a,
                                core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___8int32_t_56int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___8int32_t_56int32_t(core_core_arch_x86___m256i a,
                                    core_core_arch_x86___m256i b) {
  return _vxarq_u64___8int32_t_56int32_t(a, b);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
rotate_left___14int32_t_50int32_t(core_core_arch_x86___m256i x) {
  core_core_arch_x86___m256i uu____0 = libcrux_intrinsics_avx2_mm256_slli_epi64(
      (int32_t)14, x, core_core_arch_x86___m256i);
  return libcrux_intrinsics_avx2_mm256_xor_si256(
      uu____0, libcrux_intrinsics_avx2_mm256_srli_epi64(
                   (int32_t)50, x, core_core_arch_x86___m256i));
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
_vxarq_u64___14int32_t_50int32_t(core_core_arch_x86___m256i a,
                                 core_core_arch_x86___m256i b) {
  core_core_arch_x86___m256i ab = libcrux_intrinsics_avx2_mm256_xor_si256(a, b);
  return rotate_left___14int32_t_50int32_t(ab);
}

static KRML_MUSTINLINE core_core_arch_x86___m256i
xor_and_rotate___14int32_t_50int32_t(core_core_arch_x86___m256i a,
                                     core_core_arch_x86___m256i b) {
  return _vxarq_u64___14int32_t_50int32_t(a, b);
}

static KRML_MUSTINLINE void theta_rho__core_core_arch_x86___m256i_4size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s) {
  core_core_arch_x86___m256i uu____0 =
      xor5(s->st[0U][0U], s->st[1U][0U], s->st[2U][0U], s->st[3U][0U],
           s->st[4U][0U]);
  core_core_arch_x86___m256i uu____1 =
      xor5(s->st[0U][1U], s->st[1U][1U], s->st[2U][1U], s->st[3U][1U],
           s->st[4U][1U]);
  core_core_arch_x86___m256i uu____2 =
      xor5(s->st[0U][2U], s->st[1U][2U], s->st[2U][2U], s->st[3U][2U],
           s->st[4U][2U]);
  core_core_arch_x86___m256i uu____3 =
      xor5(s->st[0U][3U], s->st[1U][3U], s->st[2U][3U], s->st[3U][3U],
           s->st[4U][3U]);
  core_core_arch_x86___m256i c[5U] = {
      uu____0, uu____1, uu____2, uu____3,
      xor5(s->st[0U][4U], s->st[1U][4U], s->st[2U][4U], s->st[3U][4U],
           s->st[4U][4U])};
  core_core_arch_x86___m256i uu____4 =
      rotate_left1_and_xor(c[((size_t)0U + (size_t)4U) % (size_t)5U],
                           c[((size_t)0U + (size_t)1U) % (size_t)5U]);
  core_core_arch_x86___m256i uu____5 =
      rotate_left1_and_xor(c[((size_t)1U + (size_t)4U) % (size_t)5U],
                           c[((size_t)1U + (size_t)1U) % (size_t)5U]);
  core_core_arch_x86___m256i uu____6 =
      rotate_left1_and_xor(c[((size_t)2U + (size_t)4U) % (size_t)5U],
                           c[((size_t)2U + (size_t)1U) % (size_t)5U]);
  core_core_arch_x86___m256i uu____7 =
      rotate_left1_and_xor(c[((size_t)3U + (size_t)4U) % (size_t)5U],
                           c[((size_t)3U + (size_t)1U) % (size_t)5U]);
  core_core_arch_x86___m256i t[5U] = {
      uu____4, uu____5, uu____6, uu____7,
      rotate_left1_and_xor(c[((size_t)4U + (size_t)4U) % (size_t)5U],
                           c[((size_t)4U + (size_t)1U) % (size_t)5U])};
  core_core_arch_x86___m256i uu____8 = xor0(s->st[0U][0U], t[0U]);
  s->st[0U][0U] = uu____8;
  core_core_arch_x86___m256i uu____9 =
      xor_and_rotate___36int32_t_28int32_t(s->st[1U][0U], t[0U]);
  s->st[1U][0U] = uu____9;
  core_core_arch_x86___m256i uu____10 =
      xor_and_rotate___3int32_t_61int32_t(s->st[2U][0U], t[0U]);
  s->st[2U][0U] = uu____10;
  core_core_arch_x86___m256i uu____11 =
      xor_and_rotate___41int32_t_23int32_t(s->st[3U][0U], t[0U]);
  s->st[3U][0U] = uu____11;
  core_core_arch_x86___m256i uu____12 =
      xor_and_rotate___18int32_t_46int32_t(s->st[4U][0U], t[0U]);
  s->st[4U][0U] = uu____12;
  core_core_arch_x86___m256i uu____13 =
      xor_and_rotate___1int32_t_63int32_t(s->st[0U][1U], t[1U]);
  s->st[0U][1U] = uu____13;
  core_core_arch_x86___m256i uu____14 =
      xor_and_rotate___44int32_t_20int32_t(s->st[1U][1U], t[1U]);
  s->st[1U][1U] = uu____14;
  core_core_arch_x86___m256i uu____15 =
      xor_and_rotate___10int32_t_54int32_t(s->st[2U][1U], t[1U]);
  s->st[2U][1U] = uu____15;
  core_core_arch_x86___m256i uu____16 =
      xor_and_rotate___45int32_t_19int32_t(s->st[3U][1U], t[1U]);
  s->st[3U][1U] = uu____16;
  core_core_arch_x86___m256i uu____17 =
      xor_and_rotate___2int32_t_62int32_t(s->st[4U][1U], t[1U]);
  s->st[4U][1U] = uu____17;
  core_core_arch_x86___m256i uu____18 =
      xor_and_rotate___62int32_t_2int32_t(s->st[0U][2U], t[2U]);
  s->st[0U][2U] = uu____18;
  core_core_arch_x86___m256i uu____19 =
      xor_and_rotate___6int32_t_58int32_t(s->st[1U][2U], t[2U]);
  s->st[1U][2U] = uu____19;
  core_core_arch_x86___m256i uu____20 =
      xor_and_rotate___43int32_t_21int32_t(s->st[2U][2U], t[2U]);
  s->st[2U][2U] = uu____20;
  core_core_arch_x86___m256i uu____21 =
      xor_and_rotate___15int32_t_49int32_t(s->st[3U][2U], t[2U]);
  s->st[3U][2U] = uu____21;
  core_core_arch_x86___m256i uu____22 =
      xor_and_rotate___61int32_t_3int32_t(s->st[4U][2U], t[2U]);
  s->st[4U][2U] = uu____22;
  core_core_arch_x86___m256i uu____23 =
      xor_and_rotate___28int32_t_36int32_t(s->st[0U][3U], t[3U]);
  s->st[0U][3U] = uu____23;
  core_core_arch_x86___m256i uu____24 =
      xor_and_rotate___55int32_t_9int32_t(s->st[1U][3U], t[3U]);
  s->st[1U][3U] = uu____24;
  core_core_arch_x86___m256i uu____25 =
      xor_and_rotate___25int32_t_39int32_t(s->st[2U][3U], t[3U]);
  s->st[2U][3U] = uu____25;
  core_core_arch_x86___m256i uu____26 =
      xor_and_rotate___21int32_t_43int32_t(s->st[3U][3U], t[3U]);
  s->st[3U][3U] = uu____26;
  core_core_arch_x86___m256i uu____27 =
      xor_and_rotate___56int32_t_8int32_t(s->st[4U][3U], t[3U]);
  s->st[4U][3U] = uu____27;
  core_core_arch_x86___m256i uu____28 =
      xor_and_rotate___27int32_t_37int32_t(s->st[0U][4U], t[4U]);
  s->st[0U][4U] = uu____28;
  core_core_arch_x86___m256i uu____29 =
      xor_and_rotate___20int32_t_44int32_t(s->st[1U][4U], t[4U]);
  s->st[1U][4U] = uu____29;
  core_core_arch_x86___m256i uu____30 =
      xor_and_rotate___39int32_t_25int32_t(s->st[2U][4U], t[4U]);
  s->st[2U][4U] = uu____30;
  core_core_arch_x86___m256i uu____31 =
      xor_and_rotate___8int32_t_56int32_t(s->st[3U][4U], t[4U]);
  s->st[3U][4U] = uu____31;
  core_core_arch_x86___m256i uu____32 =
      xor_and_rotate___14int32_t_50int32_t(s->st[4U][4U], t[4U]);
  s->st[4U][4U] = uu____32;
}

static KRML_MUSTINLINE void pi__core_core_arch_x86___m256i_4size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s) {
  core_core_arch_x86___m256i old[5U][5U];
  memcpy(old, s->st, (size_t)5U * sizeof(core_core_arch_x86___m256i[5U]));
  s->st[0U][1U] = old[1U][1U];
  s->st[0U][2U] = old[2U][2U];
  s->st[0U][3U] = old[3U][3U];
  s->st[0U][4U] = old[4U][4U];
  s->st[1U][0U] = old[0U][3U];
  s->st[1U][1U] = old[1U][4U];
  s->st[1U][2U] = old[2U][0U];
  s->st[1U][3U] = old[3U][1U];
  s->st[1U][4U] = old[4U][2U];
  s->st[2U][0U] = old[0U][1U];
  s->st[2U][1U] = old[1U][2U];
  s->st[2U][2U] = old[2U][3U];
  s->st[2U][3U] = old[3U][4U];
  s->st[2U][4U] = old[4U][0U];
  s->st[3U][0U] = old[0U][4U];
  s->st[3U][1U] = old[1U][0U];
  s->st[3U][2U] = old[2U][1U];
  s->st[3U][3U] = old[3U][2U];
  s->st[3U][4U] = old[4U][3U];
  s->st[4U][0U] = old[0U][2U];
  s->st[4U][1U] = old[1U][3U];
  s->st[4U][2U] = old[2U][4U];
  s->st[4U][3U] = old[3U][0U];
  s->st[4U][4U] = old[4U][1U];
}

static KRML_MUSTINLINE void chi__core_core_arch_x86___m256i_4size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s) {
  core_core_arch_x86___m256i old[5U][5U];
  memcpy(old, s->st, (size_t)5U * sizeof(core_core_arch_x86___m256i[5U]));
  KRML_MAYBE_FOR5(
      i0, (size_t)0U, (size_t)5U, (size_t)1U, size_t i1 = i0;
      KRML_MAYBE_FOR5(i, (size_t)0U, (size_t)5U, (size_t)1U, size_t j = i;
                      core_core_arch_x86___m256i uu____0 = and_not_xor(
                          s->st[i1][j], old[i1][(j + (size_t)2U) % (size_t)5U],
                          old[i1][(j + (size_t)1U) % (size_t)5U]);
                      s->st[i1][j] = uu____0;););
}

static KRML_MUSTINLINE void iota__core_core_arch_x86___m256i_4size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    size_t i) {
  core_core_arch_x86___m256i uu____0 = xor_constant(
      s->st[0U][0U], libcrux_sha3_generic_keccak_ROUNDCONSTANTS[i]);
  s->st[0U][0U] = uu____0;
}

static KRML_MUSTINLINE void keccakf1600__core_core_arch_x86___m256i_4size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s) {
  for (size_t i = (size_t)0U; i < (size_t)24U; i++) {
    size_t i0 = i;
    theta_rho__core_core_arch_x86___m256i_4size_t(s);
    pi__core_core_arch_x86___m256i_4size_t(s);
    chi__core_core_arch_x86___m256i_4size_t(s);
    iota__core_core_arch_x86___m256i_4size_t(s, i0);
  }
}

static KRML_MUSTINLINE void
absorb_block__core_core_arch_x86___m256i_4size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice blocks[4U]) {
  core_core_arch_x86___m256i(*uu____0)[5U] = s->st;
  Eurydice_slice uu____1[4U];
  memcpy(uu____1, blocks, (size_t)4U * sizeof(Eurydice_slice));
  load_block___136size_t0(uu____0, uu____1);
  keccakf1600__core_core_arch_x86___m256i_4size_t(s);
}

static KRML_MUSTINLINE void load_block_full___136size_t(
    core_core_arch_x86___m256i (*s)[5U], uint8_t blocks[4U][200U]) {
  Eurydice_slice buf[4U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[2U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[3U],
                                                    uint8_t, Eurydice_slice)};
  load_block___136size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___136size_t0(
    core_core_arch_x86___m256i (*a)[5U], uint8_t b[4U][200U]) {
  core_core_arch_x86___m256i(*uu____0)[5U] = a;
  uint8_t uu____1[4U][200U];
  memcpy(uu____1, b, (size_t)4U * sizeof(uint8_t[200U]));
  load_block_full___136size_t(uu____0, uu____1);
}

static KRML_MUSTINLINE void
absorb_final__core_core_arch_x86___m256i_4size_t_136size_t_31uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice last[4U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[4U][200U] = {{0U}};
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice(
            (size_t)200U, blocks[i0],
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                    .end = last_len}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 31U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)136U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_x86___m256i(*uu____3)[5U] = s->st;
  uint8_t uu____4[4U][200U];
  memcpy(uu____4, blocks, (size_t)4U * sizeof(uint8_t[200U]));
  load_block_full___136size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_x86___m256i_4size_t(s);
}

static KRML_MUSTINLINE void store_block___136size_t(
    core_core_arch_x86___m256i (*s)[5U], Eurydice_slice out[4U]) {
  for (size_t i = (size_t)0U; i < (size_t)136U / (size_t)32U; i++) {
    size_t i0 = i;
    core_core_arch_x86___m256i v0l =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32,
            s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)2U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v1h =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32,
            s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)1U) % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)3U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v2l =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49,
            s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)2U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v3h =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49,
            s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)1U) % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)3U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v0 =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v0l, v1h);
    core_core_arch_x86___m256i v1 =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v0l, v1h);
    core_core_arch_x86___m256i v2 =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v2l, v3h);
    core_core_arch_x86___m256i v3 =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v2l, v3h);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[0U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v0);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[1U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v1);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[2U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v2);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[3U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v3);
  }
  size_t rem = (size_t)136U % (size_t)32U;
  size_t start = (size_t)32U * ((size_t)136U / (size_t)32U);
  uint8_t u8s[32U] = {0U};
  size_t i0 = (size_t)4U * ((size_t)136U / (size_t)32U) / (size_t)5U;
  size_t j0 = (size_t)4U * ((size_t)136U / (size_t)32U) % (size_t)5U;
  libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
      Eurydice_array_to_slice((size_t)32U, u8s, uint8_t, Eurydice_slice),
      s[i0][j0]);
  Eurydice_slice uu____0 = Eurydice_slice_subslice(
      out[0U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)0U, .end = (size_t)8U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____1 = Eurydice_slice_subslice(
      out[1U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____1,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)8U, .end = (size_t)16U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____2 = Eurydice_slice_subslice(
      out[2U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____2,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)16U, .end = (size_t)24U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____3 = Eurydice_slice_subslice(
      out[3U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____3,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)24U, .end = (size_t)32U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  if (rem == (size_t)16U) {
    uint8_t u8s0[32U] = {0U};
    size_t i =
        ((size_t)4U * ((size_t)136U / (size_t)32U) + (size_t)1U) / (size_t)5U;
    size_t j =
        ((size_t)4U * ((size_t)136U / (size_t)32U) + (size_t)1U) % (size_t)5U;
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_array_to_slice((size_t)32U, u8s0, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____4 = Eurydice_slice_subslice(
        out[0U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____4,
        Eurydice_array_to_subslice((size_t)32U, u8s0,
                                   (CLITERAL(core_ops_range_Range__size_t){
                                       .start = (size_t)0U, .end = (size_t)8U}),
                                   uint8_t, core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____5 = Eurydice_slice_subslice(
        out[1U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____5,
        Eurydice_array_to_subslice(
            (size_t)32U, u8s0,
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)8U,
                                                    .end = (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____6 = Eurydice_slice_subslice(
        out[2U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____6,
        Eurydice_array_to_subslice(
            (size_t)32U, u8s0,
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)16U,
                                                    .end = (size_t)24U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____7 = Eurydice_slice_subslice(
        out[3U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____7,
        Eurydice_array_to_subslice(
            (size_t)32U, u8s0,
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)24U,
                                                    .end = (size_t)32U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block_full___136size_t(
    core_core_arch_x86___m256i (*s)[5U], uint8_t ret[4U][200U]) {
  uint8_t out0[200U] = {0U};
  uint8_t out1[200U] = {0U};
  uint8_t out2[200U] = {0U};
  uint8_t out3[200U] = {0U};
  Eurydice_slice buf[4U] = {
      Eurydice_array_to_slice((size_t)200U, out0, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out1, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out2, uint8_t, Eurydice_slice),
      Eurydice_array_to_slice((size_t)200U, out3, uint8_t, Eurydice_slice)};
  store_block___136size_t(s, buf);
  uint8_t uu____0[200U];
  memcpy(uu____0, out0, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____1[200U];
  memcpy(uu____1, out1, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____2[200U];
  memcpy(uu____2, out2, (size_t)200U * sizeof(uint8_t));
  uint8_t uu____3[200U];
  memcpy(uu____3, out3, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[0U], uu____0, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[1U], uu____1, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[2U], uu____2, (size_t)200U * sizeof(uint8_t));
  memcpy(ret[3U], uu____3, (size_t)200U * sizeof(uint8_t));
}

static KRML_MUSTINLINE void store_block_full___136size_t0(
    core_core_arch_x86___m256i (*a)[5U], uint8_t ret[4U][200U]) {
  uint8_t ret0[4U][200U];
  store_block_full___136size_t(a, ret0);
  memcpy(ret, ret0, (size_t)4U * sizeof(uint8_t[200U]));
}

static KRML_MUSTINLINE void
squeeze_first_and_last__core_core_arch_x86___m256i_4size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out[4U]) {
  uint8_t b[4U][200U];
  store_block_full___136size_t0(s->st, b);
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void store_block___136size_t0(
    core_core_arch_x86___m256i (*a)[5U], Eurydice_slice b[4U]) {
  store_block___136size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_x86___m256i_4size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out[4U]) {
  store_block___136size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_x86___m256i_4size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out[4U]) {
  keccakf1600__core_core_arch_x86___m256i_4size_t(s);
  store_block___136size_t0(s->st, out);
}

static KRML_MUSTINLINE void
squeeze_last__core_core_arch_x86___m256i_4size_t_136size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        s,
    Eurydice_slice out[4U]) {
  keccakf1600__core_core_arch_x86___m256i_4size_t(&s);
  uint8_t b[4U][200U];
  store_block_full___136size_t0(s.st, b);
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      Eurydice_slice uu____0 = out[i0]; uint8_t *uu____1 = b[i0];
      core_ops_range_Range__size_t lit; lit.start = (size_t)0U;
      lit.end = core_slice___Slice_T___len(out[i0], uint8_t, size_t);
      core_slice___Slice_T___copy_from_slice(
          uu____0,
          Eurydice_array_to_subslice((size_t)200U, uu____1, lit, uint8_t,
                                     core_ops_range_Range__size_t,
                                     Eurydice_slice),
          uint8_t, void *););
}

static KRML_MUSTINLINE void
keccak__core_core_arch_x86___m256i_4size_t_136size_t_31uint8_t(
    Eurydice_slice data[4U], Eurydice_slice out[4U]) {
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
      s = new__core_core_arch_x86___m256i_4size_t();
  for (size_t i = (size_t)0U;
       i < core_slice___Slice_T___len(data[0U], uint8_t, size_t) / (size_t)136U;
       i++) {
    size_t i0 = i;
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *uu____0 = &s;
    Eurydice_slice uu____1[4U];
    memcpy(uu____1, data, (size_t)4U * sizeof(Eurydice_slice));
    Eurydice_slice ret[4U];
    slice_n(uu____1, i0 * (size_t)136U, (size_t)136U, ret);
    absorb_block__core_core_arch_x86___m256i_4size_t_136size_t(uu____0, ret);
  }
  size_t rem =
      core_slice___Slice_T___len(data[0U], uint8_t, size_t) % (size_t)136U;
  libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
      *uu____2 = &s;
  Eurydice_slice uu____3[4U];
  memcpy(uu____3, data, (size_t)4U * sizeof(Eurydice_slice));
  Eurydice_slice ret[4U];
  slice_n(uu____3, core_slice___Slice_T___len(data[0U], uint8_t, size_t) - rem,
          rem, ret);
  absorb_final__core_core_arch_x86___m256i_4size_t_136size_t_31uint8_t(uu____2,
                                                                       ret);
  size_t outlen = core_slice___Slice_T___len(out[0U], uint8_t, size_t);
  size_t blocks = outlen / (size_t)136U;
  size_t last = outlen - outlen % (size_t)136U;
  if (blocks == (size_t)0U) {
    squeeze_first_and_last__core_core_arch_x86___m256i_4size_t_136size_t(&s,
                                                                         out);
  } else {
    K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_
        uu____4 = split_at_mut_n(out, (size_t)136U);
    Eurydice_slice o0[4U];
    memcpy(o0, uu____4.fst, (size_t)4U * sizeof(Eurydice_slice));
    Eurydice_slice o1[4U];
    memcpy(o1, uu____4.snd, (size_t)4U * sizeof(Eurydice_slice));
    squeeze_first_block__core_core_arch_x86___m256i_4size_t_136size_t(&s, o0);
    core_ops_range_Range__size_t iter =
        core_iter_traits_collect___core__iter__traits__collect__IntoIterator_for_I__1__into_iter(
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)1U,
                                                    .end = blocks}),
            core_ops_range_Range__size_t, core_ops_range_Range__size_t);
    while (true) {
      if (core_iter_range___core__iter__traits__iterator__Iterator_for_core__ops__range__Range_A___6__next(
              &iter, size_t, core_option_Option__size_t)
              .tag == core_option_None) {
        break;
      } else {
        K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_
            uu____5 = split_at_mut_n(o1, (size_t)136U);
        Eurydice_slice o[4U];
        memcpy(o, uu____5.fst, (size_t)4U * sizeof(Eurydice_slice));
        Eurydice_slice orest[4U];
        memcpy(orest, uu____5.snd, (size_t)4U * sizeof(Eurydice_slice));
        squeeze_next_block__core_core_arch_x86___m256i_4size_t_136size_t(&s, o);
        memcpy(o1, orest, (size_t)4U * sizeof(Eurydice_slice));
      }
    }
    if (last < outlen) {
      squeeze_last__core_core_arch_x86___m256i_4size_t_136size_t(s, o1);
    }
  }
}

void libcrux_sha3_avx2_x4_shake256(Eurydice_slice input0, Eurydice_slice input1,
                                   Eurydice_slice input2, Eurydice_slice input3,
                                   Eurydice_slice out0, Eurydice_slice out1,
                                   Eurydice_slice out2, Eurydice_slice out3) {
  Eurydice_slice buf0[4U] = {input0, input1, input2, input3};
  Eurydice_slice buf[4U] = {out0, out1, out2, out3};
  keccak__core_core_arch_x86___m256i_4size_t_136size_t_31uint8_t(buf0, buf);
}

libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
libcrux_sha3_avx2_x4_incremental_shake128_init(void) {
  return new__core_core_arch_x86___m256i_4size_t();
}

static KRML_MUSTINLINE void load_block___168size_t(
    core_core_arch_x86___m256i (*s)[5U], Eurydice_slice blocks[4U]) {
  for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)32U; i++) {
    size_t i0 = i;
    core_core_arch_x86___m256i v00 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[0U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v10 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[1U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v20 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[2U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v30 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(Eurydice_slice_subslice(
            blocks[3U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = (size_t)32U * i0,
                .end = (size_t)32U * (i0 + (size_t)1U)}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice));
    core_core_arch_x86___m256i v0l =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v00, v10);
    core_core_arch_x86___m256i v1h =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v00, v10);
    core_core_arch_x86___m256i v2l =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v20, v30);
    core_core_arch_x86___m256i v3h =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v20, v30);
    core_core_arch_x86___m256i v0 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32, v0l, v2l, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v1 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32, v1h, v3h, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v2 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49, v0l, v2l, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v3 =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49, v1h, v3h, core_core_arch_x86___m256i);
    core_core_arch_x86___m256i uu____0 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U], v0);
    s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U] = uu____0;
    core_core_arch_x86___m256i uu____1 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)1U) % (size_t)5U],
            v1);
    s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
     [((size_t)4U * i0 + (size_t)1U) % (size_t)5U] = uu____1;
    core_core_arch_x86___m256i uu____2 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)2U) % (size_t)5U],
            v2);
    s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
     [((size_t)4U * i0 + (size_t)2U) % (size_t)5U] = uu____2;
    core_core_arch_x86___m256i uu____3 =
        libcrux_intrinsics_avx2_mm256_xor_si256(
            s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)3U) % (size_t)5U],
            v3);
    s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
     [((size_t)4U * i0 + (size_t)3U) % (size_t)5U] = uu____3;
  }
  size_t rem = (size_t)168U % (size_t)32U;
  size_t start = (size_t)32U * ((size_t)168U / (size_t)32U);
  uint8_t u8s[32U] = {0U};
  Eurydice_slice uu____4 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                              .end = (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____4,
      Eurydice_slice_subslice(blocks[0U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____5 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)8U,
                                              .end = (size_t)16U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____5,
      Eurydice_slice_subslice(blocks[1U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____6 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)16U,
                                              .end = (size_t)24U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____6,
      Eurydice_slice_subslice(blocks[2U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____7 = Eurydice_array_to_subslice(
      (size_t)32U, u8s,
      (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)24U,
                                              .end = (size_t)32U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____7,
      Eurydice_slice_subslice(blocks[3U],
                              (CLITERAL(core_ops_range_Range__size_t){
                                  .start = start, .end = start + (size_t)8U}),
                              uint8_t, core_ops_range_Range__size_t,
                              Eurydice_slice),
      uint8_t, void *);
  core_core_arch_x86___m256i u = libcrux_intrinsics_avx2_mm256_loadu_si256_u8(
      core_array___Array_T__N__23__as_slice((size_t)32U, u8s, uint8_t,
                                            Eurydice_slice));
  size_t i0 = (size_t)4U * ((size_t)168U / (size_t)32U) / (size_t)5U;
  size_t j0 = (size_t)4U * ((size_t)168U / (size_t)32U) % (size_t)5U;
  core_core_arch_x86___m256i uu____8 =
      libcrux_intrinsics_avx2_mm256_xor_si256(s[i0][j0], u);
  s[i0][j0] = uu____8;
  if (rem == (size_t)16U) {
    uint8_t u8s0[32U] = {0U};
    Eurydice_slice uu____9 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                .end = (size_t)8U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____9,
        Eurydice_slice_subslice(
            blocks[0U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____10 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)8U,
                                                .end = (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____10,
        Eurydice_slice_subslice(
            blocks[1U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____11 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)16U,
                                                .end = (size_t)24U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____11,
        Eurydice_slice_subslice(
            blocks[2U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____12 = Eurydice_array_to_subslice(
        (size_t)32U, u8s0,
        (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)24U,
                                                .end = (size_t)32U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____12,
        Eurydice_slice_subslice(
            blocks[3U],
            (CLITERAL(core_ops_range_Range__size_t){
                .start = start + (size_t)8U, .end = start + (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    core_core_arch_x86___m256i u0 =
        libcrux_intrinsics_avx2_mm256_loadu_si256_u8(
            core_array___Array_T__N__23__as_slice((size_t)32U, u8s0, uint8_t,
                                                  Eurydice_slice));
    size_t i =
        ((size_t)4U * ((size_t)168U / (size_t)32U) + (size_t)1U) / (size_t)5U;
    size_t j =
        ((size_t)4U * ((size_t)168U / (size_t)32U) + (size_t)1U) % (size_t)5U;
    core_core_arch_x86___m256i uu____13 =
        libcrux_intrinsics_avx2_mm256_xor_si256(s[i][j], u0);
    s[i][j] = uu____13;
  }
}

static KRML_MUSTINLINE void load_block_full___168size_t(
    core_core_arch_x86___m256i (*s)[5U], uint8_t blocks[4U][200U]) {
  Eurydice_slice buf[4U] = {Eurydice_array_to_slice((size_t)200U, blocks[0U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[1U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[2U],
                                                    uint8_t, Eurydice_slice),
                            Eurydice_array_to_slice((size_t)200U, blocks[3U],
                                                    uint8_t, Eurydice_slice)};
  load_block___168size_t(s, buf);
}

static KRML_MUSTINLINE void load_block_full___168size_t0(
    core_core_arch_x86___m256i (*a)[5U], uint8_t b[4U][200U]) {
  core_core_arch_x86___m256i(*uu____0)[5U] = a;
  uint8_t uu____1[4U][200U];
  memcpy(uu____1, b, (size_t)4U * sizeof(uint8_t[200U]));
  load_block_full___168size_t(uu____0, uu____1);
}

KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_absorb_final__core_core_arch_x86___m256i_4size_t_168size_t_31uint8_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice last[4U]) {
  size_t last_len = core_slice___Slice_T___len(last[0U], uint8_t, size_t);
  uint8_t blocks[4U][200U] = {{0U}};
  KRML_MAYBE_FOR4(
      i, (size_t)0U, (size_t)4U, (size_t)1U, size_t i0 = i;
      if (last_len > (size_t)0U) {
        Eurydice_slice uu____0 = Eurydice_array_to_subslice(
            (size_t)200U, blocks[i0],
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)0U,
                                                    .end = last_len}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
        core_slice___Slice_T___copy_from_slice(uu____0, last[i0], uint8_t,
                                               void *);
      } blocks[i0][last_len] = 31U;
      size_t uu____1 = i0; size_t uu____2 = (size_t)168U - (size_t)1U;
      blocks[uu____1][uu____2] = (uint32_t)blocks[uu____1][uu____2] | 128U;);
  core_core_arch_x86___m256i(*uu____3)[5U] = s->st;
  uint8_t uu____4[4U][200U];
  memcpy(uu____4, blocks, (size_t)4U * sizeof(uint8_t[200U]));
  load_block_full___168size_t0(uu____3, uu____4);
  keccakf1600__core_core_arch_x86___m256i_4size_t(s);
}

void libcrux_sha3_avx2_x4_incremental_shake128_absorb_final(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice data0, Eurydice_slice data1, Eurydice_slice data2,
    Eurydice_slice data3) {
  Eurydice_slice buf[4U] = {data0, data1, data2, data3};
  libcrux_sha3_generic_keccak_absorb_final__core_core_arch_x86___m256i_4size_t_168size_t_31uint8_t(
      s, buf);
}

static KRML_MUSTINLINE void store_block___168size_t(
    core_core_arch_x86___m256i (*s)[5U], Eurydice_slice out[4U]) {
  for (size_t i = (size_t)0U; i < (size_t)168U / (size_t)32U; i++) {
    size_t i0 = i;
    core_core_arch_x86___m256i v0l =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32,
            s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)2U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v1h =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)32,
            s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)1U) % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)3U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v2l =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49,
            s[(size_t)4U * i0 / (size_t)5U][(size_t)4U * i0 % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)2U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)2U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v3h =
        libcrux_intrinsics_avx2_mm256_permute2x128_si256(
            (int32_t)49,
            s[((size_t)4U * i0 + (size_t)1U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)1U) % (size_t)5U],
            s[((size_t)4U * i0 + (size_t)3U) / (size_t)5U]
             [((size_t)4U * i0 + (size_t)3U) % (size_t)5U],
            core_core_arch_x86___m256i);
    core_core_arch_x86___m256i v0 =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v0l, v1h);
    core_core_arch_x86___m256i v1 =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v0l, v1h);
    core_core_arch_x86___m256i v2 =
        libcrux_intrinsics_avx2_mm256_unpacklo_epi64(v2l, v3h);
    core_core_arch_x86___m256i v3 =
        libcrux_intrinsics_avx2_mm256_unpackhi_epi64(v2l, v3h);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[0U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v0);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[1U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v1);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[2U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v2);
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_slice_subslice(out[3U],
                                (CLITERAL(core_ops_range_Range__size_t){
                                    .start = (size_t)32U * i0,
                                    .end = (size_t)32U * (i0 + (size_t)1U)}),
                                uint8_t, core_ops_range_Range__size_t,
                                Eurydice_slice),
        v3);
  }
  size_t rem = (size_t)168U % (size_t)32U;
  size_t start = (size_t)32U * ((size_t)168U / (size_t)32U);
  uint8_t u8s[32U] = {0U};
  size_t i0 = (size_t)4U * ((size_t)168U / (size_t)32U) / (size_t)5U;
  size_t j0 = (size_t)4U * ((size_t)168U / (size_t)32U) % (size_t)5U;
  libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
      Eurydice_array_to_slice((size_t)32U, u8s, uint8_t, Eurydice_slice),
      s[i0][j0]);
  Eurydice_slice uu____0 = Eurydice_slice_subslice(
      out[0U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____0,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)0U, .end = (size_t)8U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____1 = Eurydice_slice_subslice(
      out[1U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____1,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)8U, .end = (size_t)16U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____2 = Eurydice_slice_subslice(
      out[2U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____2,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)16U, .end = (size_t)24U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  Eurydice_slice uu____3 = Eurydice_slice_subslice(
      out[3U],
      (CLITERAL(core_ops_range_Range__size_t){.start = start,
                                              .end = start + (size_t)8U}),
      uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
  core_slice___Slice_T___copy_from_slice(
      uu____3,
      Eurydice_array_to_subslice((size_t)32U, u8s,
                                 (CLITERAL(core_ops_range_Range__size_t){
                                     .start = (size_t)24U, .end = (size_t)32U}),
                                 uint8_t, core_ops_range_Range__size_t,
                                 Eurydice_slice),
      uint8_t, void *);
  if (rem == (size_t)16U) {
    uint8_t u8s0[32U] = {0U};
    size_t i =
        ((size_t)4U * ((size_t)168U / (size_t)32U) + (size_t)1U) / (size_t)5U;
    size_t j =
        ((size_t)4U * ((size_t)168U / (size_t)32U) + (size_t)1U) % (size_t)5U;
    libcrux_intrinsics_avx2_mm256_storeu_si256_u8(
        Eurydice_array_to_slice((size_t)32U, u8s0, uint8_t, Eurydice_slice),
        s[i][j]);
    Eurydice_slice uu____4 = Eurydice_slice_subslice(
        out[0U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____4,
        Eurydice_array_to_subslice((size_t)32U, u8s0,
                                   (CLITERAL(core_ops_range_Range__size_t){
                                       .start = (size_t)0U, .end = (size_t)8U}),
                                   uint8_t, core_ops_range_Range__size_t,
                                   Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____5 = Eurydice_slice_subslice(
        out[1U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____5,
        Eurydice_array_to_subslice(
            (size_t)32U, u8s0,
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)8U,
                                                    .end = (size_t)16U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____6 = Eurydice_slice_subslice(
        out[2U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____6,
        Eurydice_array_to_subslice(
            (size_t)32U, u8s0,
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)16U,
                                                    .end = (size_t)24U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
    Eurydice_slice uu____7 = Eurydice_slice_subslice(
        out[3U],
        (CLITERAL(core_ops_range_Range__size_t){.start = start + (size_t)8U,
                                                .end = start + (size_t)16U}),
        uint8_t, core_ops_range_Range__size_t, Eurydice_slice);
    core_slice___Slice_T___copy_from_slice(
        uu____7,
        Eurydice_array_to_subslice(
            (size_t)32U, u8s0,
            (CLITERAL(core_ops_range_Range__size_t){.start = (size_t)24U,
                                                    .end = (size_t)32U}),
            uint8_t, core_ops_range_Range__size_t, Eurydice_slice),
        uint8_t, void *);
  }
}

static KRML_MUSTINLINE void store_block___168size_t0(
    core_core_arch_x86___m256i (*a)[5U], Eurydice_slice b[4U]) {
  store_block___168size_t(a, b);
}

static KRML_MUSTINLINE void
squeeze_next_block__core_core_arch_x86___m256i_4size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out[4U]) {
  keccakf1600__core_core_arch_x86___m256i_4size_t(s);
  store_block___168size_t0(s->st, out);
}

void libcrux_sha3_avx2_x4_incremental_shake128_squeeze_next_block(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out0, Eurydice_slice out1, Eurydice_slice out2,
    Eurydice_slice out3) {
  Eurydice_slice buf[4U] = {out0, out1, out2, out3};
  squeeze_next_block__core_core_arch_x86___m256i_4size_t_168size_t(s, buf);
}

static KRML_MUSTINLINE void
squeeze_first_block__core_core_arch_x86___m256i_4size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out[4U]) {
  store_block___168size_t0(s->st, out);
}

KRML_MUSTINLINE void
libcrux_sha3_generic_keccak_squeeze_first_three_blocks__core_core_arch_x86___m256i_4size_t_168size_t(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out[4U]) {
  K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_ uu____0 =
      split_at_mut_n(out, (size_t)168U);
  Eurydice_slice o0[4U];
  memcpy(o0, uu____0.fst, (size_t)4U * sizeof(Eurydice_slice));
  Eurydice_slice o10[4U];
  memcpy(o10, uu____0.snd, (size_t)4U * sizeof(Eurydice_slice));
  squeeze_first_block__core_core_arch_x86___m256i_4size_t_168size_t(s, o0);
  K___Eurydice_slice_uint8_t_4size_t__Eurydice_slice_uint8_t_4size_t_ uu____1 =
      split_at_mut_n(o10, (size_t)168U);
  Eurydice_slice o1[4U];
  memcpy(o1, uu____1.fst, (size_t)4U * sizeof(Eurydice_slice));
  Eurydice_slice o2[4U];
  memcpy(o2, uu____1.snd, (size_t)4U * sizeof(Eurydice_slice));
  squeeze_next_block__core_core_arch_x86___m256i_4size_t_168size_t(s, o1);
  squeeze_next_block__core_core_arch_x86___m256i_4size_t_168size_t(s, o2);
}

void libcrux_sha3_avx2_x4_incremental_shake128_squeeze_first_three_blocks(
    libcrux_sha3_generic_keccak_KeccakState__core_core_arch_x86___m256i__4size_t
        *s,
    Eurydice_slice out0, Eurydice_slice out1, Eurydice_slice out2,
    Eurydice_slice out3) {
  Eurydice_slice buf[4U] = {out0, out1, out2, out3};
  libcrux_sha3_generic_keccak_squeeze_first_three_blocks__core_core_arch_x86___m256i_4size_t_168size_t(
      s, buf);
}
