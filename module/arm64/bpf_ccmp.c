// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: CCMP - conditional compare chain via ARM64 CCMP
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_ccmp64(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_ccmp_kfunc_ids)
BTF_ID_FLAGS(func, bpf_ccmp64)
BTF_KFUNCS_END(bpf_ccmp_kfunc_ids)

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

static __always_inline int decode_ccmp_payload(u64 payload,
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

static int instantiate_ccmp(u64 payload, struct bpf_insn *insn_buf)
{
	struct ccmp_payload decoded;
	u8 class, op;
	int cnt = 0;
	int err;
	u8 i;

	err = decode_ccmp_payload(payload, &decoded);
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

static __always_inline void a64_emit(u32 *image, int *idx, bool emit, u32 insn)
{
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	(*idx)++;
}

static __always_inline u32 a64_cmp_imm(u8 sf, u8 rn, u16 imm12)
{
	u32 base = sf ? 0xF100001FU : 0x7100001FU;

	return base | ((u32)imm12 << 10) | ((u32)rn << 5);
}

static __always_inline u32 a64_ccmp_imm(u8 sf, u8 rn, u8 imm5,
					u8 nzcv, u8 cond)
{
	u32 base = sf ? 0xFA400800U : 0x7A400800U;

	return base |
	       ((u32)imm5 << 16) |
	       ((u32)cond << 12) |
	       ((u32)rn << 5) |
	       (u32)nzcv;
}

static __always_inline u8 a64_invert_eq_ne(u8 cond)
{
	return cond ^ 1U;
}

static __always_inline u32 a64_cset_x(u8 rd, u8 cond)
{
	u8 inv = a64_invert_eq_ne(cond);

	return 0x9A800400U |
	       (31U << 16) |
	       ((u32)inv << 12) |
	       (31U << 5) |
	       (u32)rd;
}

static int emit_ccmp_arm64(u32 *image, int *idx, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	struct ccmp_payload decoded;
	u8 regs[KINSN_CCMP_MAX_TERMS];
	u8 dst_reg, continue_cond, poison_nzcv, sf;
	int err;
	u8 i;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_ccmp_payload(payload, &decoded);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(decoded.dst_reg);
	if (dst_reg == 0xff)
		return -EINVAL;
	for (i = 0; i < decoded.count; i++) {
		regs[i] = kinsn_arm64_reg(decoded.regs[i]);
		if (regs[i] == 0xff)
			return -EINVAL;
	}

	sf = decoded.width32 ? 0 : 1;
	if (decoded.mode == KINSN_CCMP_MODE_FAIL_EQ) {
		continue_cond = A64_COND_NE;
		poison_nzcv = A64_NZCV_Z_SET;
	} else {
		continue_cond = A64_COND_EQ;
		poison_nzcv = A64_NZCV_Z_CLEAR;
	}

	a64_emit(image, idx, emit, a64_cmp_imm(sf, regs[0], 0));
	for (i = 1; i < decoded.count; i++)
		a64_emit(image, idx, emit,
			 a64_ccmp_imm(sf, regs[i], 0, poison_nzcv,
				      continue_cond));
	a64_emit(image, idx, emit, a64_cset_x(dst_reg, continue_cond));

	return decoded.count + 1;
}

const struct bpf_kinsn bpf_ccmp64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = KINSN_CCMP_MAX_TERMS + 2,
	.max_emit_bytes = (KINSN_CCMP_MAX_TERMS + 1) * 4,
	.instantiate_insn = instantiate_ccmp,
	.emit_arm64 = emit_ccmp_arm64,
};

static const struct bpf_kinsn * const bpf_ccmp_kinsn_descs[] = {
	&bpf_ccmp64_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_ccmp, "BpfReJIT kinsn: CCMP",
		       bpf_ccmp_kfunc_ids, bpf_ccmp_kinsn_descs);
