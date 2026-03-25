// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: COND_SELECT - branchless conditional select via CSEL
 */

#include "kinsn_common.h"

#define KINSN_SELECT_COND_NEZ 0

static __always_inline int decode_select_payload(u64 payload,
						 u8 *dst_reg,
						 u8 *true_reg,
						 u8 *false_reg,
						 u8 *cond_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*true_reg = kinsn_payload_reg(payload, 4);
	*false_reg = kinsn_payload_reg(payload, 8);
	*cond_reg = kinsn_payload_reg(payload, 12);

	if (kinsn_payload_reg(payload, 16) != KINSN_SELECT_COND_NEZ)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *true_reg > BPF_REG_10 ||
	    *false_reg > BPF_REG_10 || *cond_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_select(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, true_reg, false_reg, cond_reg;
	int err;

	err = decode_select_payload(payload, &dst_reg, &true_reg,
				    &false_reg, &cond_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_IMM(BPF_JEQ, cond_reg, 0, 2);
	insn_buf[1] = BPF_MOV64_REG(dst_reg, true_reg);
	insn_buf[2] = BPF_JMP_A(1);
	insn_buf[3] = BPF_MOV64_REG(dst_reg, false_reg);
	return 4;
}

static inline u32 a64_tst(u8 rn, u8 rm)
{
	return 0xEA000000U | ((u32)rm << 16) | ((u32)rn << 5) | 31U;
}

#define COND_NE 0x1

static inline u32 a64_csel(u8 rd, u8 rn, u8 rm, u8 cond)
{
	return (1U << 31) | 0x1A800000U |
	       ((u32)rm << 16) |
	       ((u32)cond << 12) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_select_arm64(u32 *image, int *idx, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 dst_reg, true_reg, false_reg, cond_reg;
	u32 tst_insn, csel_insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_select_payload(payload, &dst_reg, &true_reg,
				    &false_reg, &cond_reg);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	true_reg = kinsn_arm64_reg(true_reg);
	false_reg = kinsn_arm64_reg(false_reg);
	cond_reg = kinsn_arm64_reg(cond_reg);
	if (dst_reg == 0xff || true_reg == 0xff ||
	    false_reg == 0xff || cond_reg == 0xff)
		return -EINVAL;

	tst_insn = a64_tst(cond_reg, cond_reg);
	csel_insn = a64_csel(dst_reg, true_reg, false_reg, COND_NE);
	if (emit) {
		image[*idx] = cpu_to_le32(tst_insn);
		image[*idx + 1] = cpu_to_le32(csel_insn);
	}
	*idx += 2;
	return 2;
}

const struct bpf_kinsn bpf_select64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_select,
	.emit_arm64 = emit_select_arm64,
};

DEFINE_KINSN_V2_MODULE(bpf_select, "BpfReJIT kinsn: COND_SELECT (CSEL)",
		       BPF_KINSN_DESC_ENTRY(bpf_select64_desc));
