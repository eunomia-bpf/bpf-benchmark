// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsns: TST and CSEL.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_tst_rr(void) {}
__bpf_kfunc void bpf_arm64_csel_ne_rrr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_csel_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_csel_ne_rrr)
BTF_ID_FLAGS(func, bpf_arm64_tst_rr)
BTF_KFUNCS_END(bpf_arm64_csel_kfunc_ids)

#define COND_NE 0x1

static __always_inline int decode_tst_payload(u64 payload, u8 *reg)
{
	*reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_csel_payload(u64 payload,
					       u8 *dst_reg,
					       u8 *true_reg,
					       u8 *false_reg,
					       u8 *cond_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*true_reg = kinsn_payload_reg(payload, 4);
	*false_reg = kinsn_payload_reg(payload, 8);
	*cond_reg = kinsn_payload_reg(payload, 12);

	if (payload >> 16)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *true_reg > BPF_REG_10 ||
	    *false_reg > BPF_REG_10 || *cond_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_tst_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	int err;

	err = decode_tst_payload(payload, &reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_csel_ne_rrr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, true_reg, false_reg, cond_reg;
	int err;

	err = decode_csel_payload(payload, &dst_reg, &true_reg, &false_reg,
				  &cond_reg);
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

static inline u32 a64_csel(u8 rd, u8 rn, u8 rm, u8 cond)
{
	return (1U << 31) | 0x1A800000U |
	       ((u32)rm << 16) |
	       ((u32)cond << 12) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_tst_rr_arm64(u32 *image, int *idx, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 reg;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_tst_payload(payload, &reg);
	if (err)
		return err;

	reg = kinsn_arm64_reg(reg);
	if (reg == 0xff)
		return -EINVAL;

	insn = a64_tst(reg, reg);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

static int emit_csel_ne_rrr_arm64(u32 *image, int *idx, bool emit,
				  u64 payload, const struct bpf_prog *prog)
{
	u8 dst_reg, true_reg, false_reg, cond_reg;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_csel_payload(payload, &dst_reg, &true_reg, &false_reg,
				  &cond_reg);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	true_reg = kinsn_arm64_reg(true_reg);
	false_reg = kinsn_arm64_reg(false_reg);
	cond_reg = kinsn_arm64_reg(cond_reg);
	if (dst_reg == 0xff || true_reg == 0xff ||
	    false_reg == 0xff || cond_reg == 0xff)
		return -EINVAL;

	insn = a64_csel(dst_reg, true_reg, false_reg, COND_NE);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

const struct bpf_kinsn bpf_arm64_tst_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_tst_rr,
	.emit_arm64 = emit_tst_rr_arm64,
};

const struct bpf_kinsn bpf_arm64_csel_ne_rrr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_csel_ne_rrr,
	.emit_arm64 = emit_csel_ne_rrr_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_csel_kinsn_descs[] = {
	&bpf_arm64_csel_ne_rrr_desc,
	&bpf_arm64_tst_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_csel, "BpfReJIT arm64 kinsns: TST/CSEL",
		       bpf_arm64_csel_kfunc_ids, bpf_arm64_csel_kinsn_descs);
