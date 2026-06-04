// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsn: PRFM hints for ARM64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_prfm_pldl1keep(void) {}
__bpf_kfunc void bpf_arm64_prfm_pldl1strm(void) {}
__bpf_kfunc void bpf_arm64_prfm_pldl2keep(void) {}
__bpf_kfunc void bpf_arm64_prfm_pldl2strm(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_prfm_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_prfm_pldl1keep)
BTF_ID_FLAGS(func, bpf_arm64_prfm_pldl1strm)
BTF_ID_FLAGS(func, bpf_arm64_prfm_pldl2keep)
BTF_ID_FLAGS(func, bpf_arm64_prfm_pldl2strm)
BTF_KFUNCS_END(bpf_arm64_prfm_kfunc_ids)

static __always_inline int decode_prfm_payload(u64 payload, u8 *ptr_reg)
{
	u8 hint_kind = (payload >> 4) & 0xf;

	*ptr_reg = kinsn_payload_reg(payload, 0);

	if (hint_kind)
		return -EINVAL;
	if (payload >> 8)
		return -EINVAL;
	if (*ptr_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_prfm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 ptr_reg;
	int err;

	err = decode_prfm_payload(payload, &ptr_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static __always_inline u32 a64_prfm(u8 rn, u8 prfop)
{
	return 0xF9800000U | ((u32)rn << 5) | prfop;
}

static int emit_prfm_arm64(u32 *image, int *idx, bool emit,
			   u64 payload, const struct bpf_prog *prog,
			   u8 prfop)
{
	u8 ptr_reg;
	u32 insn;
	int err;

	(void)prog;

	err = decode_prfm_payload(payload, &ptr_reg);
	if (err)
		return err;

	ptr_reg = kinsn_arm64_reg(ptr_reg);
	if (ptr_reg == 0xff)
		return -EINVAL;

	insn = a64_prfm(ptr_reg, prfop);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

static int emit_prfm_pldl1keep_arm64(u32 *image, int *idx, bool emit,
				     u64 payload, const struct bpf_prog *prog)
{
	return emit_prfm_arm64(image, idx, emit, payload, prog, 0);
}

static int emit_prfm_pldl1strm_arm64(u32 *image, int *idx, bool emit,
				     u64 payload, const struct bpf_prog *prog)
{
	return emit_prfm_arm64(image, idx, emit, payload, prog, 1);
}

static int emit_prfm_pldl2keep_arm64(u32 *image, int *idx, bool emit,
				     u64 payload, const struct bpf_prog *prog)
{
	return emit_prfm_arm64(image, idx, emit, payload, prog, 2);
}

static int emit_prfm_pldl2strm_arm64(u32 *image, int *idx, bool emit,
				     u64 payload, const struct bpf_prog *prog)
{
	return emit_prfm_arm64(image, idx, emit, payload, prog, 3);
}

const struct bpf_kinsn bpf_arm64_prfm_pldl1keep_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_prfm,
	.emit_arm64 = emit_prfm_pldl1keep_arm64,
};

const struct bpf_kinsn bpf_arm64_prfm_pldl1strm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_prfm,
	.emit_arm64 = emit_prfm_pldl1strm_arm64,
};

const struct bpf_kinsn bpf_arm64_prfm_pldl2keep_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_prfm,
	.emit_arm64 = emit_prfm_pldl2keep_arm64,
};

const struct bpf_kinsn bpf_arm64_prfm_pldl2strm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_prfm,
	.emit_arm64 = emit_prfm_pldl2strm_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_prfm_kinsn_descs[] = {
	&bpf_arm64_prfm_pldl1keep_desc,
	&bpf_arm64_prfm_pldl1strm_desc,
	&bpf_arm64_prfm_pldl2keep_desc,
	&bpf_arm64_prfm_pldl2strm_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_prfm, "BpfReJIT arm64 kinsn: PRFM",
		       bpf_arm64_prfm_kfunc_ids, bpf_arm64_prfm_kinsn_descs);
