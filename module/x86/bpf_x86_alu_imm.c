// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: immediate ALU instructions.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_shrq_imm(void) {}
__bpf_kfunc void bpf_x86_andl_imm32(void) {}
__bpf_kfunc void bpf_x86_sbbl_imm0(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_alu_imm_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_andl_imm32)
BTF_ID_FLAGS(func, bpf_x86_sbbl_imm0)
BTF_ID_FLAGS(func, bpf_x86_shrq_imm)
BTF_KFUNCS_END(bpf_x86_alu_imm_kfunc_ids)

static __always_inline int decode_reg_imm_payload(u64 payload,
						  u8 *dst_reg,
						  u32 *imm)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*imm = (u32)(payload >> 8);

	if (payload >> 40)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_sbb_payload(u64 payload,
					      u8 *dst_reg,
					      u8 *cond_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*cond_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *cond_reg >= BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*cond_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_shrq_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 imm;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 63)
		return -EINVAL;

	insn_buf[0] = BPF_ALU64_IMM(BPF_RSH, dst_reg, imm);
	return 1;
}

static int instantiate_andl_imm32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 imm;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_ALU32_IMM(BPF_AND, dst_reg, (s32)imm);
	return 1;
}

static int instantiate_sbbl_imm0(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, cond_reg;
	int err;

	err = decode_sbb_payload(payload, &dst_reg, &cond_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_IMM(BPF_JEQ, cond_reg, 0, 1);
	insn_buf[1] = BPF_ALU32_IMM(BPF_SUB, dst_reg, 1);
	return 2;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_u32(u8 *buf, u32 *len, u32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
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

static int emit_shrq_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg;
	u32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 63)
		return -EINVAL;

	emit_rex_rr(buf, &len, true, 0, dst_reg);
	emit_u8(buf, &len, 0xC1);
	emit_u8(buf, &len, 0xE8 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, (u8)imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_andl_imm32_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg;
	u32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;

	emit_rex_rr(buf, &len, false, 0, dst_reg);
	emit_u8(buf, &len, 0x81);
	emit_u8(buf, &len, 0xE0 | kinsn_x86_reg_code(dst_reg));
	emit_u32(buf, &len, imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_sbbl_imm0_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cond_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_sbb_payload(payload, &dst_reg, &cond_reg);
	if (err)
		return err;
	(void)cond_reg;

	emit_rex_rr(buf, &len, false, 0, dst_reg);
	emit_u8(buf, &len, 0x83);
	emit_u8(buf, &len, 0xd8 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, 0);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_x86_shrq_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_shrq_imm,
	.emit_x86 = emit_shrq_imm_x86,
};

const struct bpf_kinsn bpf_x86_andl_imm32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_andl_imm32,
	.emit_x86 = emit_andl_imm32_x86,
};

const struct bpf_kinsn bpf_x86_sbbl_imm0_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_sbbl_imm0,
	.emit_x86 = emit_sbbl_imm0_x86,
};

static const struct bpf_kinsn * const bpf_x86_alu_imm_kinsn_descs[] = {
	&bpf_x86_andl_imm32_desc,
	&bpf_x86_sbbl_imm0_desc,
	&bpf_x86_shrq_imm_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_alu_imm,
		       "BpfReJIT x86 kinsns: immediate ALU",
		       bpf_x86_alu_imm_kfunc_ids,
		       bpf_x86_alu_imm_kinsn_descs);
