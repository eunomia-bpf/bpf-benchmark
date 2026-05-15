// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: ROLQ/RORXL — rotate lowering for x86-64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_roll_cl(void) {}
__bpf_kfunc void bpf_x86_roll_imm(void) {}
__bpf_kfunc void bpf_x86_rolq_cl(void) {}
__bpf_kfunc void bpf_x86_rolq_imm(void) {}
__bpf_kfunc void bpf_x86_rorxl_imm(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_rotate_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_roll_cl)
BTF_ID_FLAGS(func, bpf_x86_roll_imm)
BTF_ID_FLAGS(func, bpf_x86_rolq_cl)
BTF_ID_FLAGS(func, bpf_x86_rolq_imm)
BTF_ID_FLAGS(func, bpf_x86_rorxl_imm)
BTF_KFUNCS_END(bpf_x86_rotate_kfunc_ids)

static __always_inline int decode_rotate_payload(u64 payload,
						 u8 shift_mask,
						 u8 *dst_reg,
						 u8 *src_reg,
						 u8 *tmp_reg,
						 u8 *shift)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*shift = kinsn_payload_u8(payload, 8) & shift_mask;
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 || *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_rotate64_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	return decode_rotate_payload(payload, 63, dst_reg, src_reg, tmp_reg, shift);
}

static __always_inline int decode_rotate32_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	return decode_rotate_payload(payload, 31, dst_reg, src_reg, tmp_reg, shift);
}

static __always_inline int decode_rotate_cl_payload(u64 payload,
						    u8 *dst_reg,
						    u8 *cnt_reg,
						    u8 *tmp_shift_reg,
						    u8 *tmp_value_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*cnt_reg = kinsn_payload_reg(payload, 4);
	*tmp_shift_reg = kinsn_payload_reg(payload, 8);
	*tmp_value_reg = kinsn_payload_reg(payload, 12);

	if (payload >> 16)
		return -EINVAL;
	if (*cnt_reg != BPF_REG_4)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *tmp_shift_reg >= BPF_REG_10 ||
	    *tmp_value_reg >= BPF_REG_10)
		return -EINVAL;
	if (*tmp_shift_reg == *dst_reg || *tmp_shift_reg == *cnt_reg ||
	    *tmp_value_reg == *dst_reg || *tmp_value_reg == *cnt_reg ||
	    *tmp_value_reg == *tmp_shift_reg)
		return -EINVAL;

	return 0;
}

static int instantiate_rotate64(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	if (!shift) {
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
		return cnt;
	}

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_reg, src_reg);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, tmp_reg, 64 - shift);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	return cnt;
}

static int instantiate_rotate32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	if (!shift) {
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, src_reg);
		return cnt;
	}

	insn_buf[cnt++] = BPF_MOV32_REG(tmp_reg, src_reg);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_RSH, tmp_reg, 32 - shift);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_OR, dst_reg, tmp_reg);
	return cnt;
}

static int instantiate_rolq_cl(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, cnt_reg, tmp_shift_reg, tmp_value_reg;
	int cnt = 0;
	int err;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg,
				       &tmp_shift_reg, &tmp_value_reg);
	if (err)
		return err;

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_shift_reg, cnt_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, tmp_shift_reg, 63);
	insn_buf[cnt++] = BPF_MOV64_REG(tmp_value_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_LSH, dst_reg, tmp_shift_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_NEG, tmp_shift_reg, 0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, tmp_shift_reg, 63);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_RSH, tmp_value_reg, tmp_shift_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_value_reg);
	return cnt;
}

static int instantiate_roll_cl(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, cnt_reg, tmp_shift_reg, tmp_value_reg;
	int cnt = 0;
	int err;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg,
				       &tmp_shift_reg, &tmp_value_reg);
	if (err)
		return err;

	insn_buf[cnt++] = BPF_MOV32_REG(tmp_shift_reg, cnt_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, tmp_shift_reg, 31);
	insn_buf[cnt++] = BPF_MOV32_REG(tmp_value_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_LSH, dst_reg, tmp_shift_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_NEG, tmp_shift_reg, 0);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, tmp_shift_reg, 31);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_RSH, tmp_value_reg, tmp_shift_reg);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_OR, dst_reg, tmp_value_reg);
	return cnt;
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

static void emit_rol_imm(u8 *buf, u32 *len, bool is64, u8 dst_reg, u8 imm8)
{
	emit_rex_rr(buf, len, is64, 0, dst_reg);
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, imm8);
}

static void emit_rol_cl(u8 *buf, u32 *len, bool is64, u8 dst_reg)
{
	emit_rex_rr(buf, len, is64, 0, dst_reg);
	emit_u8(buf, len, 0xD3);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
}

static void emit_rorx32_imm(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg, u8 imm8)
{
	u8 vex2 = 0x43;

	if (!kinsn_x86_reg_ext(dst_reg))
		vex2 |= 0x80;
	if (!kinsn_x86_reg_ext(src_reg))
		vex2 |= 0x20;

	emit_u8(buf, len, 0xC4);
	emit_u8(buf, len, vex2);
	emit_u8(buf, len, 0x7B);
	emit_u8(buf, len, 0xF0);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));
	emit_u8(buf, len, imm8);
}

static int emit_rotate64_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (dst_reg != src_reg || !shift)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_imm(buf, &len, true, dst_reg, shift);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_rotate32_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(src_reg))
		return -EINVAL;

	emit_rorx32_imm(buf, &len, dst_reg, src_reg, (-shift) & 31);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_roll_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (dst_reg != src_reg || !shift)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_imm(buf, &len, false, dst_reg, shift);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_rolq_cl_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cnt_reg, tmp_shift_reg, tmp_value_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg,
				       &tmp_shift_reg, &tmp_value_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_cl(buf, &len, true, dst_reg);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_roll_cl_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cnt_reg, tmp_shift_reg, tmp_value_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg,
				       &tmp_shift_reg, &tmp_value_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_cl(buf, &len, false, dst_reg);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_x86_rolq_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate64,
	.emit_x86 = emit_rotate64_x86,
};

const struct bpf_kinsn bpf_x86_rolq_cl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 8,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_rolq_cl,
	.emit_x86 = emit_rolq_cl_x86,
};

const struct bpf_kinsn bpf_x86_roll_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate32,
	.emit_x86 = emit_roll_imm_x86,
};

const struct bpf_kinsn bpf_x86_roll_cl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 8,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_roll_cl,
	.emit_x86 = emit_roll_cl_x86,
};

const struct bpf_kinsn bpf_x86_rorxl_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate32,
	.emit_x86 = emit_rotate32_x86,
};

static const struct bpf_kinsn * const bpf_x86_rotate_kinsn_descs[] = {
	&bpf_x86_roll_cl_desc,
	&bpf_x86_roll_imm_desc,
	&bpf_x86_rolq_cl_desc,
	&bpf_x86_rolq_imm_desc,
	&bpf_x86_rorxl_imm_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_rotate, "BpfReJIT x86 kinsns: ROL/RORX",
		       bpf_x86_rotate_kfunc_ids, bpf_x86_rotate_kinsn_descs);
