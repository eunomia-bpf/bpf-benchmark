// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: ROLQ/RORXL — rotate lowering for x86-64
 */

#include "kinsn_x86_emit.h"

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

struct rotate_payload {
	u8 dst_reg;
	u8 src_reg;
	u8 tmp_dst_reg;
	u8 tmp_src_reg;
	u8 shift;
	bool shadow;
};

static __always_inline int decode_rotate_payload(u64 payload, u8 shift_mask,
						 struct rotate_payload *rot)
{
	payload = kinsn_payload_decode(payload);
	rot->shift = ((payload >> 8) & 0xff) & shift_mask;
	rot->shadow = !!(payload >> 20);
	if (rot->shadow) {
		if (payload >> 28)
			return -EINVAL;
		rot->tmp_dst_reg = payload & 0xf;
		rot->tmp_src_reg = (payload >> 4) & 0xf;
		rot->dst_reg = (payload >> 20) & 0xf;
		rot->src_reg = (payload >> 24) & 0xf;
		if (!kinsn_x86_operand_valid(rot->dst_reg) ||
		    !kinsn_x86_operand_valid(rot->src_reg) ||
		    !kinsn_bpf_gpr_valid(rot->tmp_dst_reg) ||
		    !kinsn_bpf_gpr_valid(rot->tmp_src_reg))
			return -EINVAL;
		if (rot->tmp_dst_reg == rot->tmp_src_reg)
			return -EINVAL;
		if (!kinsn_x86_reg_is_shadowed(rot->dst_reg) &&
		    (rot->tmp_dst_reg == rot->dst_reg ||
		     rot->tmp_src_reg == rot->dst_reg))
			return -EINVAL;
		if (!kinsn_x86_reg_is_shadowed(rot->src_reg) &&
		    (rot->tmp_dst_reg == rot->src_reg ||
		     rot->tmp_src_reg == rot->src_reg))
			return -EINVAL;
		return 0;
	}

	rot->dst_reg = payload & 0xf;
	rot->src_reg = (payload >> 4) & 0xf;
	rot->tmp_src_reg = (payload >> 16) & 0xf;
	rot->tmp_dst_reg = rot->dst_reg;
	if (rot->dst_reg > BPF_REG_10 || rot->src_reg > BPF_REG_10 ||
	    rot->tmp_src_reg > BPF_REG_10)
		return -EINVAL;
	if (rot->tmp_src_reg == rot->dst_reg ||
	    rot->tmp_src_reg == rot->src_reg)
		return -EINVAL;
	return 0;
}

static __always_inline int decode_rotate64_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	struct rotate_payload rot;
	int err;

	err = decode_rotate_payload(payload, 63, &rot);
	if (err)
		return err;
	*dst_reg = rot.dst_reg;
	*src_reg = rot.src_reg;
	*tmp_reg = rot.tmp_src_reg;
	*shift = rot.shift;
	return 0;
}

static __always_inline int decode_rotate32_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	struct rotate_payload rot;
	int err;

	err = decode_rotate_payload(payload, 31, &rot);
	if (err)
		return err;
	*dst_reg = rot.dst_reg;
	*src_reg = rot.src_reg;
	*tmp_reg = rot.tmp_src_reg;
	*shift = rot.shift;
	return 0;
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

static __always_inline struct bpf_insn rotate_mov(u8 width, u8 dst, u8 src)
{
	return width == 64 ? BPF_MOV64_REG(dst, src) : BPF_MOV32_REG(dst, src);
}

static __always_inline struct bpf_insn rotate_alu_imm(u8 width, u8 op, u8 dst,
						      s32 imm)
{
	return width == 64 ? BPF_ALU64_IMM(op, dst, imm) :
			     BPF_ALU32_IMM(op, dst, imm);
}

static __always_inline struct bpf_insn rotate_alu_reg(u8 width, u8 op, u8 dst,
						      u8 src)
{
	return width == 64 ? BPF_ALU64_REG(op, dst, src) :
			     BPF_ALU32_REG(op, dst, src);
}

static int instantiate_rotate(u64 payload, struct bpf_insn *insn_buf, u8 width)
{
	struct rotate_payload rot;
	int cnt = 0;
	int err;

	err = decode_rotate_payload(payload, width - 1, &rot);
	if (err)
		return err;

	if (rot.shadow) {
		if (kinsn_x86_reg_is_shadowed(rot.src_reg))
			insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, rot.tmp_src_reg,
						      BPF_REG_10,
						      kinsn_x86_shadow_reg_off(rot.src_reg));
		else
			insn_buf[cnt++] = BPF_MOV64_REG(rot.tmp_src_reg, rot.src_reg);
		insn_buf[cnt++] = rotate_mov(width, rot.tmp_dst_reg,
					     rot.tmp_src_reg);
		if (rot.shift) {
			insn_buf[cnt++] = rotate_alu_imm(width, BPF_LSH,
							 rot.tmp_dst_reg, rot.shift);
			insn_buf[cnt++] = rotate_alu_imm(width, BPF_RSH,
							 rot.tmp_src_reg, width - rot.shift);
			insn_buf[cnt++] = rotate_alu_reg(width, BPF_OR,
							 rot.tmp_dst_reg, rot.tmp_src_reg);
		}
		if (kinsn_x86_reg_is_shadowed(rot.dst_reg))
			insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
						      rot.tmp_dst_reg,
						      kinsn_x86_shadow_reg_off(rot.dst_reg));
		else
			insn_buf[cnt++] = BPF_MOV64_REG(rot.dst_reg, rot.tmp_dst_reg);
		return cnt;
	}

	if (!rot.shift)
		insn_buf[cnt++] = rotate_mov(width, rot.dst_reg, rot.src_reg);
	else {
		insn_buf[cnt++] = rotate_mov(width, rot.tmp_src_reg, rot.src_reg);
		if (rot.dst_reg != rot.src_reg)
			insn_buf[cnt++] = rotate_mov(width, rot.dst_reg,
						     rot.src_reg);
		insn_buf[cnt++] = rotate_alu_imm(width, BPF_LSH, rot.dst_reg,
						 rot.shift);
		insn_buf[cnt++] = rotate_alu_imm(width, BPF_RSH,
						 rot.tmp_src_reg, width - rot.shift);
		insn_buf[cnt++] = rotate_alu_reg(width, BPF_OR, rot.dst_reg,
						 rot.tmp_src_reg);
	}
	return cnt;
}

static int instantiate_rotate64(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rotate(payload, insn_buf, 64);
}

static int instantiate_rotate32(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rotate(payload, insn_buf, 32);
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

static void emit_rol_imm(u8 *buf, u32 *len, bool is64, u8 dst_reg, u8 imm8)
{
	kinsn_emit_rex_rr(buf, len, is64, 0, dst_reg);
	kinsn_emit_u8(buf, len, 0xC1);
	kinsn_emit_u8(buf, len, 0xC0 | kinsn_x86_code(dst_reg));
	kinsn_emit_u8(buf, len, imm8);
}

static void emit_rol_cl(u8 *buf, u32 *len, bool is64, u8 dst_reg)
{
	kinsn_emit_rex_rr(buf, len, is64, 0, dst_reg);
	kinsn_emit_u8(buf, len, 0xD3);
	kinsn_emit_u8(buf, len, 0xC0 | kinsn_x86_code(dst_reg));
}

static void emit_rorx32_imm(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg, u8 imm8)
{
	u8 vex2 = 0x43;

	if (!kinsn_x86_ext(dst_reg))
		vex2 |= 0x80;
	if (!kinsn_x86_ext(src_reg))
		vex2 |= 0x20;

	kinsn_emit_u8(buf, len, 0xC4);
	kinsn_emit_u8(buf, len, vex2);
	kinsn_emit_u8(buf, len, 0x7B);
	kinsn_emit_u8(buf, len, 0xF0);
	kinsn_emit_u8(buf, len, 0xC0 | (kinsn_x86_code(dst_reg) << 3) |
		      kinsn_x86_code(src_reg));
	kinsn_emit_u8(buf, len, imm8);
}

static int emit_rotate64_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (dst_reg != src_reg || !shift)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_imm(buf, &len, true, dst_reg, shift);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_rotate32_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(src_reg))
		return -EINVAL;

	emit_rorx32_imm(buf, &len, dst_reg, src_reg, (-shift) & 31);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_roll_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (dst_reg != src_reg || !shift)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_imm(buf, &len, false, dst_reg, shift);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_rolq_cl_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cnt_reg, tmp_shift_reg, tmp_value_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg,
				       &tmp_shift_reg, &tmp_value_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_cl(buf, &len, true, dst_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_roll_cl_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cnt_reg, tmp_shift_reg, tmp_value_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg,
				       &tmp_shift_reg, &tmp_value_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_cl(buf, &len, false, dst_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_rolq_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
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
	.max_insn_cnt = 6,
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
	.max_insn_cnt = 6,
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
