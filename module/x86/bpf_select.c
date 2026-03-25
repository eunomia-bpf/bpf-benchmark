// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: COND_SELECT — branchless conditional select via CMOV
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

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_rex_rr(u8 *buf, u32 *len, bool is64, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (kinsn_x86_reg_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_reg_ext(rm))
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_mov_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	emit_rex_rr(buf, len, true, src_reg, dst_reg);
	emit_u8(buf, len, 0x89);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(src_reg) << 3) |
		kinsn_x86_reg_code(dst_reg));
}

static void emit_test_rr(u8 *buf, u32 *len, u8 reg)
{
	emit_rex_rr(buf, len, true, reg, reg);
	emit_u8(buf, len, 0x85);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(reg) << 3) |
		kinsn_x86_reg_code(reg));
}

static void emit_cmov_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg, u8 cc)
{
	emit_rex_rr(buf, len, true, dst_reg, src_reg);
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, cc);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));
}

static int emit_select_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, true_reg, false_reg, cond_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_select_payload(payload, &dst_reg, &true_reg,
				    &false_reg, &cond_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(true_reg) ||
	    !kinsn_x86_reg_valid(false_reg) || !kinsn_x86_reg_valid(cond_reg))
		return -EINVAL;

	if (dst_reg != false_reg && dst_reg != true_reg)
		emit_mov_rr(buf, &len, dst_reg, false_reg);

	emit_test_rr(buf, &len, cond_reg);
	if (dst_reg == true_reg)
		emit_cmov_rr(buf, &len, dst_reg, false_reg, 0x44);
	else
		emit_cmov_rr(buf, &len, dst_reg, true_reg, 0x45);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_select64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_select,
	.emit_x86 = emit_select_x86,
};

DEFINE_KINSN_V2_MODULE(bpf_select, "BpfReJIT kinsn: COND_SELECT (CMOV)",
		       BPF_KINSN_DESC_ENTRY(bpf_select64_desc));
