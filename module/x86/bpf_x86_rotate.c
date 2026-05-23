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

static int instantiate_rotate_bpf(u64 payload, struct bpf_insn *insn_buf,
				  u8 width)
{
	struct rotate_payload rot;
	u8 scratch;
	u32 scratch_mask;
	int cnt = 0;
	int err;

	if (rotate_payload_form(payload) != X86_ROTATE_FORM_IMM)
		return -EINVAL;

	err = decode_rotate_payload(payload, width - 1, &rot);
	if (err)
		return err;
	if (rot.shift == 0)
		return -EINVAL;
	if (!kinsn_x86_reg_is_bpf_writable(rot.dst_reg) ||
	    !kinsn_x86_reg_is_bpf_writable(rot.src_reg))
		return -EINVAL;

	scratch = kinsn_x86_scratch_avoid(rot.dst_reg, rot.src_reg, 0);
	scratch_mask = KINSN_X86_SCRATCH_MASK(scratch);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (rot.dst_reg != rot.src_reg)
		insn_buf[cnt++] = rotate_mov(width, rot.dst_reg, rot.src_reg);
	insn_buf[cnt++] = rotate_mov(width, scratch, rot.dst_reg);
	insn_buf[cnt++] = rotate_alu_imm(width, BPF_LSH, rot.dst_reg,
					 rot.shift);
	insn_buf[cnt++] = rotate_alu_imm(width, BPF_RSH, scratch,
					 width - rot.shift);
	insn_buf[cnt++] = rotate_alu_reg(width, BPF_OR, rot.dst_reg,
					 scratch);
	if (width == 32)
		kinsn_x86_write32(insn_buf, &cnt, rot.dst_reg, rot.dst_reg,
				  scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, rot.dst_reg, rot.dst_reg,
				  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_rotate64(u64 payload, struct bpf_insn *insn_buf)
{
	int err = instantiate_rotate_bpf(payload, insn_buf, 64);

	if (err != -EINVAL)
		return err;
	return instantiate_rotate(payload, insn_buf, 64);
}

static int instantiate_rotate32(u64 payload, struct bpf_insn *insn_buf)
{
	int err = instantiate_rotate_bpf(payload, insn_buf, 32);

	if (err != -EINVAL)
		return err;
	return instantiate_rotate(payload, insn_buf, 32);
}

static int instantiate_rol_cl(u64 payload, struct bpf_insn *insn_buf,
			      u8 width);

static int instantiate_rolq(u64 payload, struct bpf_insn *insn_buf)
{
	switch (rotate_payload_form(payload)) {
	case X86_ROTATE_FORM_IMM:
	case X86_ROTATE_FORM_ARCH_IMM:
		return instantiate_rotate64(payload, insn_buf);
	case X86_ROTATE_FORM_RR:
	case X86_ROTATE_FORM_ARCH_RR:
		return instantiate_rol_cl(payload, insn_buf, 64);
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
		return instantiate_rol_cl(payload, insn_buf, 32);
	default:
		return -EINVAL;
	}
}

static int instantiate_rol_cl(u64 payload, struct bpf_insn *insn_buf,
			      u8 width)
{
	u8 dst_reg, cnt_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	bool arch_reg;
	bool width64;
	u8 shift_mask;
	int cnt = 0;
	int err;

	if (width != 32 && width != 64)
		return -EINVAL;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg);
	if (err)
		return err;

	width64 = width == 64;
	shift_mask = width - 1;
	arch_reg = rotate_payload_form(payload) == X86_ROTATE_FORM_ARCH_RR;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg,
		       width64, arch_reg);
	if (arch_reg)
		kinsn_x86_read(insn_buf, &cnt, KINSN_X86_SCRATCH1,
			       cnt_reg, width64, true);
	else
		insn_buf[cnt++] = rotate_mov(width, KINSN_X86_SCRATCH1,
					     cnt_reg);
	insn_buf[cnt++] = rotate_alu_imm(width, BPF_AND,
					 KINSN_X86_SCRATCH1, shift_mask);
	insn_buf[cnt++] = rotate_mov(width, KINSN_X86_SCRATCH2,
				     KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = rotate_alu_reg(width, BPF_LSH,
					 KINSN_X86_SCRATCH0,
					 KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = rotate_alu_imm(width, BPF_NEG,
					 KINSN_X86_SCRATCH1, 0);
	insn_buf[cnt++] = rotate_alu_imm(width, BPF_AND,
					 KINSN_X86_SCRATCH1, shift_mask);
	insn_buf[cnt++] = rotate_alu_reg(width, BPF_RSH,
					 KINSN_X86_SCRATCH2,
					 KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = rotate_alu_reg(width, BPF_OR,
					 KINSN_X86_SCRATCH0,
					 KINSN_X86_SCRATCH2);
	kinsn_x86_write(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			scratch_mask, width64, arch_reg);
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

static int emit_rol_imm_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog,
			    u8 width)
{
	u8 buf[16];
	struct rotate_payload rot;
	u32 len = 0;
	int err;

	(void)prog;

	if (width != 32 && width != 64)
		return -EINVAL;

	err = decode_rotate_payload(payload, width - 1, &rot);
	if (err)
		return err;
	if (rot.dst_reg != rot.src_reg || !rot.shift)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(rot.dst_reg))
		return -EINVAL;

	emit_rol_imm(buf, &len, width == 64, rot.dst_reg, rot.shift);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_rotate32_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
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

static int emit_rol_cl_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog,
			   u8 width)
{
	u8 buf[8];
	u8 dst_reg, cnt_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (width != 32 && width != 64)
		return -EINVAL;

	err = decode_rotate_cl_payload(payload, &dst_reg, &cnt_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;
	(void)cnt_reg;

	emit_rol_cl(buf, &len, width == 64, dst_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_rol_x86(u8 *image, u32 *off, bool emit, u64 payload,
			const struct bpf_prog *prog, u8 width)
{
	switch (rotate_payload_form(payload)) {
	case X86_ROTATE_FORM_IMM:
	case X86_ROTATE_FORM_ARCH_IMM:
		return emit_rol_imm_x86(image, off, emit, payload, prog,
					width);
	case X86_ROTATE_FORM_RR:
	case X86_ROTATE_FORM_ARCH_RR:
		return emit_rol_cl_x86(image, off, emit, payload, prog,
				       width);
	default:
		return -EINVAL;
	}
}

static int emit_rolq_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_rol_x86(image, off, emit, payload, prog, 64);
}

static int emit_roll_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_rol_x86(image, off, emit, payload, prog, 32);
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
