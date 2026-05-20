// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsns: CMP/CCMP/CSET.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_cmp_x(void) {}
__bpf_kfunc void bpf_arm64_cmp_w(void) {}
__bpf_kfunc void bpf_arm64_ccmp_x(void) {}
__bpf_kfunc void bpf_arm64_ccmp_w(void) {}
__bpf_kfunc void bpf_arm64_cset_x_cond(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_ccmp_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_ccmp_w)
BTF_ID_FLAGS(func, bpf_arm64_ccmp_x)
BTF_ID_FLAGS(func, bpf_arm64_cmp_w)
BTF_ID_FLAGS(func, bpf_arm64_cmp_x)
BTF_ID_FLAGS(func, bpf_arm64_cset_x_cond)
BTF_KFUNCS_END(bpf_arm64_ccmp_kfunc_ids)

#define KINSN_CCMP_MAX_TERMS	4
#define KINSN_CCMP_MODE_FAIL_EQ	0
#define KINSN_CCMP_MODE_FAIL_NE	1

#define A64_COND_EQ		0x0U
#define A64_COND_NE		0x1U
#define A64_NZCV_Z_CLEAR	0x0U
#define A64_NZCV_Z_SET		0x4U

struct ccmp_payload {
	u8 dst_reg;
	u8 count;
	u8 mode;
	u8 width32;
	u8 regs[KINSN_CCMP_MAX_TERMS];
};

static __always_inline int decode_reg_payload(u64 payload, u8 *reg)
{
	*reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_ccmp_reg_payload(u64 payload, u8 *reg,
						   u8 *mode)
{
	*reg = kinsn_payload_reg(payload, 0);
	*mode = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*reg > BPF_REG_10)
		return -EINVAL;
	if (*mode != KINSN_CCMP_MODE_FAIL_EQ &&
	    *mode != KINSN_CCMP_MODE_FAIL_NE)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cset_payload(u64 payload,
					       struct ccmp_payload *out)
{
	u8 i;
	u8 count_bits;

	out->dst_reg = kinsn_payload_reg(payload, 0);
	count_bits = (payload >> 4) & 0x3;
	if (count_bits > KINSN_CCMP_MAX_TERMS - 2)
		return -EINVAL;
	out->count = count_bits + 2;
	out->mode = (payload >> 6) & 0x1;
	out->width32 = (payload >> 7) & 0x1;

	if (payload >> 24)
		return -EINVAL;
	if (out->dst_reg > BPF_REG_9)
		return -EINVAL;
	if (out->mode != KINSN_CCMP_MODE_FAIL_EQ &&
	    out->mode != KINSN_CCMP_MODE_FAIL_NE)
		return -EINVAL;

	for (i = 0; i < KINSN_CCMP_MAX_TERMS; i++) {
		out->regs[i] = kinsn_payload_reg(payload, 8 + 4 * i);
		if (i >= out->count) {
			if (out->regs[i])
				return -EINVAL;
			continue;
		}
		if (out->regs[i] > BPF_REG_10)
			return -EINVAL;
		if (out->regs[i] == out->dst_reg)
			return -EINVAL;
	}

	return 0;
}

static int instantiate_cmp(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	int err;

	err = decode_reg_payload(payload, &reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_ccmp(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg, mode;
	int err;

	err = decode_ccmp_reg_payload(payload, &reg, &mode);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_cset(u64 payload, struct bpf_insn *insn_buf)
{
	struct ccmp_payload decoded;
	u8 class, op;
	int cnt = 0;
	int err;
	u8 i;

	err = decode_cset_payload(payload, &decoded);
	if (err)
		return err;

	class = decoded.width32 ? BPF_JMP32 : BPF_JMP;
	op = decoded.mode == KINSN_CCMP_MODE_FAIL_EQ ? BPF_JEQ : BPF_JNE;

	insn_buf[cnt++] = BPF_MOV64_IMM(decoded.dst_reg, 0);
	for (i = 0; i < decoded.count; i++)
		insn_buf[cnt++] = BPF_RAW_INSN(class | op | BPF_K,
					       decoded.regs[i], 0,
					       decoded.count - i, 0);
	insn_buf[cnt++] = BPF_MOV64_IMM(decoded.dst_reg, 1);

	return cnt;
}

static __always_inline u32 a64_cmp_imm(u8 sf, u8 rn)
{
	return (sf ? 0xF100001FU : 0x7100001FU) | ((u32)rn << 5);
}

static __always_inline u32 a64_ccmp_imm(u8 sf, u8 rn, u8 nzcv, u8 cond)
{
	return (sf ? 0xFA400800U : 0x7A400800U) |
	       ((u32)cond << 12) |
	       ((u32)rn << 5) |
	       (u32)nzcv;
}

static __always_inline u32 a64_cset_x(u8 rd, u8 cond)
{
	u8 inv = cond ^ 1U;

	return 0x9A800400U |
	       (31U << 16) |
	       ((u32)inv << 12) |
	       (31U << 5) |
	       (u32)rd;
}

static __always_inline void ccmp_mode_fields(u8 mode, u8 *continue_cond,
					     u8 *poison_nzcv)
{
	if (mode == KINSN_CCMP_MODE_FAIL_EQ) {
		*continue_cond = A64_COND_NE;
		*poison_nzcv = A64_NZCV_Z_SET;
	} else {
		*continue_cond = A64_COND_EQ;
		*poison_nzcv = A64_NZCV_Z_CLEAR;
	}
}

static int emit_cmp_arm64(u32 *image, int *idx, bool emit, u64 payload,
			  const struct bpf_prog *prog, bool width32)
{
	u8 reg;
	u32 insn;
	int err;

	(void)prog;

	err = decode_reg_payload(payload, &reg);
	if (err)
		return err;

	reg = kinsn_arm64_reg(reg);
	if (reg == 0xff)
		return -EINVAL;

	insn = a64_cmp_imm(width32 ? 0 : 1, reg);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

static int emit_ccmp_arm64(u32 *image, int *idx, bool emit, u64 payload,
			   const struct bpf_prog *prog, bool width32)
{
	u8 reg, mode, continue_cond, poison_nzcv;
	u32 insn;
	int err;

	(void)prog;

	err = decode_ccmp_reg_payload(payload, &reg, &mode);
	if (err)
		return err;

	reg = kinsn_arm64_reg(reg);
	if (reg == 0xff)
		return -EINVAL;

	ccmp_mode_fields(mode, &continue_cond, &poison_nzcv);
	insn = a64_ccmp_imm(width32 ? 0 : 1, reg, poison_nzcv, continue_cond);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

static int emit_cset_arm64(u32 *image, int *idx, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	struct ccmp_payload decoded;
	u8 dst_reg, continue_cond, poison_nzcv;
	u32 insn;
	int err;

	(void)prog;

	err = decode_cset_payload(payload, &decoded);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(decoded.dst_reg);
	if (dst_reg == 0xff)
		return -EINVAL;

	ccmp_mode_fields(decoded.mode, &continue_cond, &poison_nzcv);
	(void)poison_nzcv;
	insn = a64_cset_x(dst_reg, continue_cond);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

static int emit_cmp_x_arm64(u32 *image, int *idx, bool emit,
				 u64 payload, const struct bpf_prog *prog)
{
	return emit_cmp_arm64(image, idx, emit, payload, prog, false);
}

static int emit_cmp_w_arm64(u32 *image, int *idx, bool emit,
				 u64 payload, const struct bpf_prog *prog)
{
	return emit_cmp_arm64(image, idx, emit, payload, prog, true);
}

static int emit_ccmp_x_arm64(u32 *image, int *idx, bool emit,
				  u64 payload, const struct bpf_prog *prog)
{
	return emit_ccmp_arm64(image, idx, emit, payload, prog, false);
}

static int emit_ccmp_w_arm64(u32 *image, int *idx, bool emit,
				  u64 payload, const struct bpf_prog *prog)
{
	return emit_ccmp_arm64(image, idx, emit, payload, prog, true);
}

const struct bpf_kinsn bpf_arm64_cmp_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_cmp,
	.emit_arm64 = emit_cmp_x_arm64,
};

const struct bpf_kinsn bpf_arm64_cmp_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_cmp,
	.emit_arm64 = emit_cmp_w_arm64,
};

const struct bpf_kinsn bpf_arm64_ccmp_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ccmp,
	.emit_arm64 = emit_ccmp_x_arm64,
};

const struct bpf_kinsn bpf_arm64_ccmp_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ccmp,
	.emit_arm64 = emit_ccmp_w_arm64,
};

const struct bpf_kinsn bpf_arm64_cset_x_cond_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = KINSN_CCMP_MAX_TERMS + 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_cset,
	.emit_arm64 = emit_cset_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_ccmp_kinsn_descs[] = {
	&bpf_arm64_ccmp_w_desc,
	&bpf_arm64_ccmp_x_desc,
	&bpf_arm64_cmp_w_desc,
	&bpf_arm64_cmp_x_desc,
	&bpf_arm64_cset_x_cond_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_ccmp, "BpfReJIT arm64 kinsns: CMP/CCMP/CSET",
		       bpf_arm64_ccmp_kfunc_ids, bpf_arm64_ccmp_kinsn_descs);
