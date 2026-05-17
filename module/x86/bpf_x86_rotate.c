// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: ROLQ/RORXL — rotate lowering for x86-64
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_roll(void) {}
__bpf_kfunc void bpf_x86_rolq(void) {}
__bpf_kfunc void bpf_x86_rorxl(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_rotate_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_roll)
BTF_ID_FLAGS(func, bpf_x86_rolq)
BTF_ID_FLAGS(func, bpf_x86_rorxl)
BTF_KFUNCS_END(bpf_x86_rotate_kfunc_ids)

enum x86_rotate_form {
	X86_ROTATE_FORM_RR = 1,
	X86_ROTATE_FORM_IMM = 2,
	X86_ROTATE_FORM_ARCH_RR = 12,
	X86_ROTATE_FORM_ARCH_IMM = 13,
};

struct rotate_payload {
	u8 dst_reg;
	u8 src_reg;
	u8 shift;
};

static __always_inline u8 rotate_payload_form(u64 payload)
{
	return kinsn_payload_decode(payload) & 0xf;
}

static __always_inline int decode_rotate_payload(u64 payload, u8 shift_mask,
						 struct rotate_payload *rot)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_ROTATE_FORM_IMM &&
	    (payload & 0xf) != X86_ROTATE_FORM_ARCH_IMM)
		return -EINVAL;
	rot->dst_reg = (payload >> 4) & 0xf;
	rot->src_reg = (payload >> 8) & 0xf;
	rot->shift = ((payload >> 12) & 0xff) & shift_mask;
	if (payload >> 20)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(rot->dst_reg) ||
	    !kinsn_x86_operand_valid(rot->src_reg))
		return -EINVAL;
	return 0;
}

static __always_inline int decode_rotate64_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *shift)
{
	struct rotate_payload rot;
	int err;

	err = decode_rotate_payload(payload, 63, &rot);
	if (err)
		return err;
	*dst_reg = rot.dst_reg;
	*src_reg = rot.src_reg;
	*shift = rot.shift;
	return 0;
}

static __always_inline int decode_rotate32_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *shift)
{
	struct rotate_payload rot;
	int err;

	err = decode_rotate_payload(payload, 31, &rot);
	if (err)
		return err;
	*dst_reg = rot.dst_reg;
	*src_reg = rot.src_reg;
	*shift = rot.shift;
	return 0;
}

static __always_inline int decode_rotate_cl_payload(u64 payload,
						    u8 *dst_reg,
						    u8 *cnt_reg)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_ROTATE_FORM_RR &&
	    (payload & 0xf) != X86_ROTATE_FORM_ARCH_RR)
		return -EINVAL;
	*dst_reg = (payload >> 4) & 0xf;
	*cnt_reg = (payload >> 8) & 0xf;

	if (payload >> 12)
		return -EINVAL;
	if (*cnt_reg != BPF_REG_4)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg))
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
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_rotate_payload(payload, width - 1, &rot);
	if (err)
		return err;

	arch_reg = rotate_payload_form(payload) == X86_ROTATE_FORM_ARCH_IMM;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      rot.src_reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				 rot.src_reg);
	if (rot.shift) {
		insn_buf[cnt++] = rotate_mov(width, KINSN_X86_SCRATCH1,
					     KINSN_X86_SCRATCH0);
		insn_buf[cnt++] = rotate_alu_imm(width, BPF_LSH,
						 KINSN_X86_SCRATCH0,
						 rot.shift);
		insn_buf[cnt++] = rotate_alu_imm(width, BPF_RSH,
						 KINSN_X86_SCRATCH1,
						 width - rot.shift);
		insn_buf[cnt++] = rotate_alu_reg(width, BPF_OR,
						 KINSN_X86_SCRATCH0,
						 KINSN_X86_SCRATCH1);
	}
	if (width == 32) {
		if (arch_reg)
			kinsn_x86_write32_arch(insn_buf, &cnt, rot.dst_reg,
					       KINSN_X86_SCRATCH0,
					       scratch_mask);
		else
			kinsn_x86_write32(insn_buf, &cnt, rot.dst_reg,
					  KINSN_X86_SCRATCH0, scratch_mask);
	} else {
		if (arch_reg)
			kinsn_x86_write64_arch(insn_buf, &cnt, rot.dst_reg,
					       KINSN_X86_SCRATCH0,
					       scratch_mask);
		else
			kinsn_x86_write64(insn_buf, &cnt, rot.dst_reg,
					  KINSN_X86_SCRATCH0, scratch_mask);
	}
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
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

static int instantiate_rolq_cl(u64 payload, struct bpf_insn *insn_buf);
static int instantiate_roll_cl(u64 payload, struct bpf_insn *insn_buf);

static int instantiate_rolq(u64 payload, struct bpf_insn *insn_buf)
{
	switch (rotate_payload_form(payload)) {
	case X86_ROTATE_FORM_IMM:
	case X86_ROTATE_FORM_ARCH_IMM:
		return instantiate_rotate64(payload, insn_buf);
	case X86_ROTATE_FORM_RR:
	case X86_ROTATE_FORM_ARCH_RR:
		return instantiate_rolq_cl(payload, insn_buf);
	default:
		return -EINVAL;
	}
}

static int instantiate_roll(u64 payload, struct bpf_insn *insn_buf)
{
	switch (rotate_payload_form(payload)) {
	case X86_ROTATE_FORM_IMM:
	case X86_ROTATE_FORM_ARCH_IMM:
		return instantiate_rotate32(payload, insn_buf);
	case X86_ROTATE_FORM_RR:
	case X86_ROTATE_FORM_ARCH_RR:
		return instantiate_roll_cl(payload, insn_buf);
	default:
		return -EINVAL;
	}
}

static int instantiate_rolq_cl(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, cnt_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg);
	if (err)
		return err;

	arch_reg = rotate_payload_form(payload) == X86_ROTATE_FORM_ARCH_RR;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      dst_reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				 dst_reg);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH1,
				      cnt_reg);
	else
		insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1, cnt_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 63);
	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH2,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_LSH, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_NEG, KINSN_X86_SCRATCH1, 0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 63);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_RSH, KINSN_X86_SCRATCH2,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);
	if (arch_reg)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_roll_cl(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, cnt_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg);
	if (err)
		return err;

	arch_reg = rotate_payload_form(payload) == X86_ROTATE_FORM_ARCH_RR;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read32_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      dst_reg);
	else
		kinsn_x86_read32(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				 dst_reg);
	if (arch_reg)
		kinsn_x86_read32_arch(insn_buf, &cnt, KINSN_X86_SCRATCH1,
				      cnt_reg);
	else
		insn_buf[cnt++] = BPF_MOV32_REG(KINSN_X86_SCRATCH1, cnt_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, KINSN_X86_SCRATCH1, 31);
	insn_buf[cnt++] = BPF_MOV32_REG(KINSN_X86_SCRATCH2,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_LSH, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_NEG, KINSN_X86_SCRATCH1, 0);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, KINSN_X86_SCRATCH1, 31);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_RSH, KINSN_X86_SCRATCH2,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_OR, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);
	if (arch_reg)
		kinsn_x86_write32_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else
		kinsn_x86_write32(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
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
	u8 dst_reg, src_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &shift);
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
	u8 dst_reg, src_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &shift);
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
	u8 dst_reg, src_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &shift);
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
	u8 dst_reg, cnt_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg);
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
	u8 dst_reg, cnt_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	emit_rol_cl(buf, &len, false, dst_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_rolq_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog)
{
	switch (rotate_payload_form(payload)) {
	case X86_ROTATE_FORM_IMM:
	case X86_ROTATE_FORM_ARCH_IMM:
		return emit_rotate64_x86(image, off, emit, payload, prog);
	case X86_ROTATE_FORM_RR:
	case X86_ROTATE_FORM_ARCH_RR:
		return emit_rolq_cl_x86(image, off, emit, payload, prog);
	default:
		return -EINVAL;
	}
}

static int emit_roll_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog)
{
	switch (rotate_payload_form(payload)) {
	case X86_ROTATE_FORM_IMM:
	case X86_ROTATE_FORM_ARCH_IMM:
		return emit_roll_imm_x86(image, off, emit, payload, prog);
	case X86_ROTATE_FORM_RR:
	case X86_ROTATE_FORM_ARCH_RR:
		return emit_roll_cl_x86(image, off, emit, payload, prog);
	default:
		return -EINVAL;
	}
}

const struct bpf_kinsn bpf_x86_rolq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 15 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rolq,
	.emit_x86 = emit_rolq_x86,
};

const struct bpf_kinsn bpf_x86_roll_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 15 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_roll,
	.emit_x86 = emit_roll_x86,
};

const struct bpf_kinsn bpf_x86_rorxl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate32,
	.emit_x86 = emit_rotate32_x86,
};

static const struct bpf_kinsn * const bpf_x86_rotate_kinsn_descs[] = {
	&bpf_x86_roll_desc,
	&bpf_x86_rolq_desc,
	&bpf_x86_rorxl_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_rotate, "BpfReJIT x86 kinsns: ROL/RORX",
		       bpf_x86_rotate_kfunc_ids, bpf_x86_rotate_kinsn_descs);
