// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: immediate ALU instructions.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_addb(void) {}
__bpf_kfunc void bpf_x86_andb(void) {}
__bpf_kfunc void bpf_x86_andq(void) {}
__bpf_kfunc void bpf_x86_andl(void) {}
__bpf_kfunc void bpf_x86_incq(void) {}
__bpf_kfunc void bpf_x86_sbbl(void) {}
__bpf_kfunc void bpf_x86_xorb_imm(void) {}
__bpf_kfunc void bpf_x86_xorb_rr(void) {}
__bpf_kfunc void bpf_x86_orb(void) {}
__bpf_kfunc void bpf_x86_addq(void) {}
__bpf_kfunc void bpf_x86_addl(void) {}
__bpf_kfunc void bpf_x86_subq(void) {}
__bpf_kfunc void bpf_x86_subl(void) {}
__bpf_kfunc void bpf_x86_xorq(void) {}
__bpf_kfunc void bpf_x86_xorl(void) {}
__bpf_kfunc void bpf_x86_orq(void) {}
__bpf_kfunc void bpf_x86_orl(void) {}
__bpf_kfunc void bpf_x86_shlq(void) {}
__bpf_kfunc void bpf_x86_shll(void) {}
__bpf_kfunc void bpf_x86_shrq(void) {}
__bpf_kfunc void bpf_x86_shrl(void) {}
__bpf_kfunc void bpf_x86_sarq(void) {}
__bpf_kfunc void bpf_x86_sarl(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_alu_imm_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_addb)
BTF_ID_FLAGS(func, bpf_x86_addl)
BTF_ID_FLAGS(func, bpf_x86_addq)
BTF_ID_FLAGS(func, bpf_x86_andb)
BTF_ID_FLAGS(func, bpf_x86_andl)
BTF_ID_FLAGS(func, bpf_x86_andq)
BTF_ID_FLAGS(func, bpf_x86_incq)
BTF_ID_FLAGS(func, bpf_x86_orb)
BTF_ID_FLAGS(func, bpf_x86_orl)
BTF_ID_FLAGS(func, bpf_x86_orq)
BTF_ID_FLAGS(func, bpf_x86_sarl)
BTF_ID_FLAGS(func, bpf_x86_sarq)
BTF_ID_FLAGS(func, bpf_x86_sbbl)
BTF_ID_FLAGS(func, bpf_x86_shll)
BTF_ID_FLAGS(func, bpf_x86_shlq)
BTF_ID_FLAGS(func, bpf_x86_shrl)
BTF_ID_FLAGS(func, bpf_x86_shrq)
BTF_ID_FLAGS(func, bpf_x86_subl)
BTF_ID_FLAGS(func, bpf_x86_subq)
BTF_ID_FLAGS(func, bpf_x86_xorb_imm)
BTF_ID_FLAGS(func, bpf_x86_xorb_rr)
BTF_ID_FLAGS(func, bpf_x86_xorl)
BTF_ID_FLAGS(func, bpf_x86_xorq)
BTF_KFUNCS_END(bpf_x86_alu_imm_kfunc_ids)

static __always_inline int decode_reg_imm_payload(u64 payload,
						  u8 *dst_reg,
						  u32 *imm)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*imm = (u32)(payload >> 8);

	if (payload >> 40)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_imm8_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *imm)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*imm = kinsn_payload_u8(payload, 8);

	if (payload >> 16)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_payload(u64 payload, u8 *dst_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_reg_payload(u64 payload,
						  u8 *dst_reg,
						  u8 *src_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_sbb_payload(u64 payload,
					      u8 *dst_reg,
					      u8 *cond_reg)
{
	payload = kinsn_payload_decode(payload);
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

#define KINSN_X86_ALU_FORM_RR		1
#define KINSN_X86_ALU_FORM_IMM		2

struct kinsn_x86_alu_payload {
	u8 form;
	u8 dst_reg;
	u8 src_reg;
	s32 imm;
};

/*
 * One kinsn name covers one x86 mnemonic+width, while this payload describes
 * the operand form. That keeps final native emission one instruction
 * (for example, bpf_x86_addq -> one addq) without creating separate kfuncs
 * for addq_rr/addq_imm/addq_mem. Verifier scratch registers are internal to
 * instantiate_insn() and are not part of the payload ABI.
 */
static __always_inline int decode_x86_alu_payload(u64 payload,
						  struct kinsn_x86_alu_payload *alu)
{
	payload = kinsn_payload_decode(payload);
	alu->form = payload & 0xf;

	if (alu->form == KINSN_X86_ALU_FORM_RR) {
		alu->dst_reg = (payload >> 4) & 0xf;
		alu->src_reg = (payload >> 8) & 0xf;
		if (payload >> 12)
			return -EINVAL;
		if (!kinsn_x86_operand_valid(alu->dst_reg) ||
		    !kinsn_x86_operand_valid(alu->src_reg))
			return -EINVAL;
		return 0;
	}

	if (alu->form == KINSN_X86_ALU_FORM_IMM) {
		alu->dst_reg = (payload >> 4) & 0xf;
		alu->src_reg = 0;
		alu->imm = (s32)((u32)(payload >> 8));
		if (payload >> 40)
			return -EINVAL;
		if (!kinsn_x86_operand_valid(alu->dst_reg))
			return -EINVAL;
		return 0;
	}

	return -EINVAL;
}

static __always_inline bool x86_alu_is_shift(u8 op)
{
	return op == BPF_LSH || op == BPF_RSH || op == BPF_ARSH;
}

static __always_inline int emit_bpf_alu_reg(struct bpf_insn *insn, u8 op,
					    u8 width, u8 dst_reg, u8 src_reg)
{
	if (width == 64)
		*insn = BPF_ALU64_REG(op, dst_reg, src_reg);
	else if (width == 32)
		*insn = BPF_ALU32_REG(op, dst_reg, src_reg);
	else
		return -EINVAL;
	return 0;
}

static __always_inline int emit_bpf_alu_imm(struct bpf_insn *insn, u8 op,
					    u8 width, u8 dst_reg, s32 imm)
{
	if (width == 64)
		*insn = BPF_ALU64_IMM(op, dst_reg, imm);
	else if (width == 32)
		*insn = BPF_ALU32_IMM(op, dst_reg, imm);
	else
		return -EINVAL;
	return 0;
}

static int instantiate_x86_alu(u64 payload, struct bpf_insn *insn_buf,
			       u8 op, u8 width)
{
	struct kinsn_x86_alu_payload decoded;
	const struct kinsn_x86_alu_payload *alu = &decoded;
	u8 dst_eval_reg, src_eval_reg;
	u32 scratch_mask;
	int cnt = 0;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;

	if (alu->form == KINSN_X86_ALU_FORM_IMM) {
		if (x86_alu_is_shift(op) &&
		    (alu->imm < 0 || alu->imm >= width))
			return -EINVAL;
		dst_eval_reg = alu->dst_reg;
		if (kinsn_x86_reg_is_shadowed(alu->dst_reg)) {
			dst_eval_reg = KINSN_X86_SCRATCH0;
			scratch_mask = KINSN_X86_SCRATCH_MASK(dst_eval_reg);
			kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
			kinsn_x86_read64(insn_buf, &cnt, dst_eval_reg,
					  alu->dst_reg);
		}
		err = emit_bpf_alu_imm(&insn_buf[cnt++], op, width,
				       dst_eval_reg, alu->imm);
		if (err)
			return err;
		if (kinsn_x86_reg_is_shadowed(alu->dst_reg)) {
			kinsn_x86_write64(insn_buf, &cnt, alu->dst_reg,
					  dst_eval_reg, scratch_mask);
			kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		}
		return cnt;
	}

	if (x86_alu_is_shift(op))
		return -EINVAL;
	if (op == BPF_XOR && alu->dst_reg == alu->src_reg) {
		if (kinsn_x86_reg_is_shadowed(alu->dst_reg)) {
			scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
			kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
			insn_buf[cnt++] = BPF_MOV64_IMM(KINSN_X86_SCRATCH0, 0);
			kinsn_x86_write64(insn_buf, &cnt, alu->dst_reg,
					  KINSN_X86_SCRATCH0, scratch_mask);
			kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
			return cnt;
		}
		if (width == 32)
			insn_buf[0] = BPF_MOV32_IMM(alu->dst_reg, 0);
		else
			insn_buf[0] = BPF_MOV64_IMM(alu->dst_reg, 0);
		return 1;
	}

	dst_eval_reg = alu->dst_reg;
	src_eval_reg = alu->src_reg;
	if (kinsn_x86_reg_is_shadowed(alu->dst_reg) ||
	    kinsn_x86_reg_is_shadowed(alu->src_reg)) {
		dst_eval_reg = KINSN_X86_SCRATCH0;
		src_eval_reg = alu->src_reg == alu->dst_reg ?
			       dst_eval_reg : KINSN_X86_SCRATCH1;
		scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
		if (src_eval_reg == KINSN_X86_SCRATCH1)
			scratch_mask |= KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		kinsn_x86_read64(insn_buf, &cnt, dst_eval_reg, alu->dst_reg);
		if (src_eval_reg != dst_eval_reg)
			kinsn_x86_read64(insn_buf, &cnt, src_eval_reg,
					  alu->src_reg);
	}
	err = emit_bpf_alu_reg(&insn_buf[cnt++], op, width,
			       dst_eval_reg, src_eval_reg);
	if (err)
		return err;
	if (kinsn_x86_reg_is_shadowed(alu->dst_reg) ||
	    kinsn_x86_reg_is_shadowed(alu->src_reg)) {
		if (width == 32)
			insn_buf[cnt++] = BPF_MOV32_REG(dst_eval_reg, dst_eval_reg);
		kinsn_x86_write64(insn_buf, &cnt, alu->dst_reg, dst_eval_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_addb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, imm;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_reg_imm8_payload(payload, &dst_reg, &imm);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 0xff);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, KINSN_X86_SCRATCH1, imm);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 0xff);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH0, -256);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_andb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, imm;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_reg_imm8_payload(payload, &dst_reg, &imm);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, imm);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH0, -256);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_incq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	int err;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_ALU64_IMM(BPF_ADD, dst_reg, 1);
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

static int instantiate_xorb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 imm;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 0xff)
		return -EINVAL;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KINSN_X86_SCRATCH0, imm);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_xorb_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_reg_reg_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 0xff);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_XOR, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_orb_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_reg_reg_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 0xff);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_x86_alu(u8 *image, u32 *off, bool emit, u64 payload,
			const struct bpf_prog *prog, u8 width, u8 op,
			u8 rr_opcode, u8 imm_group)
{
	struct kinsn_x86_alu_payload decoded;
	const struct kinsn_x86_alu_payload *alu = &decoded;
	u8 buf[8];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	err = decode_x86_alu_payload(payload, &decoded);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, alu->dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	if (alu->form == KINSN_X86_ALU_FORM_RR) {
		if (x86_alu_is_shift(op))
			return -EINVAL;
		src_reg = kinsn_x86_reg_for_prog(prog, alu->src_reg);
		if (!kinsn_x86_valid(src_reg))
			return -EINVAL;
		kinsn_emit_rex_rr(buf, &len, width == 64, src_reg, dst_reg);
		kinsn_emit_u8(buf, &len, rr_opcode);
		kinsn_emit_u8(buf, &len, 0xc0 |
			      (kinsn_x86_code(src_reg) << 3) |
			      kinsn_x86_code(dst_reg));
	} else {
		if (x86_alu_is_shift(op)) {
			if (alu->imm < 0 || alu->imm >= width)
				return -EINVAL;
			kinsn_emit_rex_rr(buf, &len, width == 64, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0xc1);
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			kinsn_emit_u8(buf, &len, (u8)alu->imm);
		} else {
			kinsn_emit_rex_rr(buf, &len, width == 64, 0, dst_reg);
			kinsn_emit_u8(buf, &len, 0x81);
			kinsn_emit_u8(buf, &len, 0xc0 | (imm_group << 3) |
				      kinsn_x86_code(dst_reg));
			kinsn_emit_s32(buf, &len, alu->imm);
		}
	}

	return kinsn_emit_finish(image, off, emit, buf, len);
}

#define DEFINE_X86_ALU_FUNCS(name, bpf_op, width, rr_opcode, imm_group)	\
static int instantiate_##name(u64 payload, struct bpf_insn *insn_buf)	\
{									\
	return instantiate_x86_alu(payload, insn_buf, bpf_op, width);	\
}									\
									\
static int emit_##name##_x86(u8 *image, u32 *off, bool emit,		\
			     u64 payload, const struct bpf_prog *prog)	\
{									\
	return emit_x86_alu(image, off, emit, payload, prog, width,	\
			    bpf_op, rr_opcode, imm_group);		\
}

DEFINE_X86_ALU_FUNCS(addq, BPF_ADD, 64, 0x01, 0)
DEFINE_X86_ALU_FUNCS(addl, BPF_ADD, 32, 0x01, 0)
DEFINE_X86_ALU_FUNCS(subq, BPF_SUB, 64, 0x29, 5)
DEFINE_X86_ALU_FUNCS(subl, BPF_SUB, 32, 0x29, 5)
DEFINE_X86_ALU_FUNCS(andq, BPF_AND, 64, 0x21, 4)
DEFINE_X86_ALU_FUNCS(andl, BPF_AND, 32, 0x21, 4)
DEFINE_X86_ALU_FUNCS(xorq, BPF_XOR, 64, 0x31, 6)
DEFINE_X86_ALU_FUNCS(xorl, BPF_XOR, 32, 0x31, 6)
DEFINE_X86_ALU_FUNCS(orq, BPF_OR, 64, 0x09, 1)
DEFINE_X86_ALU_FUNCS(orl, BPF_OR, 32, 0x09, 1)
DEFINE_X86_ALU_FUNCS(shlq, BPF_LSH, 64, 0, 4)
DEFINE_X86_ALU_FUNCS(shll, BPF_LSH, 32, 0, 4)
DEFINE_X86_ALU_FUNCS(shrq, BPF_RSH, 64, 0, 5)
DEFINE_X86_ALU_FUNCS(shrl, BPF_RSH, 32, 0, 5)
DEFINE_X86_ALU_FUNCS(sarq, BPF_ARSH, 64, 0, 7)
DEFINE_X86_ALU_FUNCS(sarl, BPF_ARSH, 32, 0, 7)

static int emit_alu8_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog, u8 modrm_base)
{
	u8 buf[4];
	u8 dst_reg, imm;
	u32 len = 0;
	int err;

	err = decode_reg_imm8_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	kinsn_emit_rex8_rm(buf, &len, dst_reg);
	kinsn_emit_u8(buf, &len, 0x80);
	kinsn_emit_u8(buf, &len, modrm_base | kinsn_x86_code(dst_reg));
	kinsn_emit_u8(buf, &len, imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

#define DEFINE_ALU8_IMM_EMIT(name, modrm_base)				\
static int emit_##name##_x86(u8 *image, u32 *off, bool emit,		\
			     u64 payload, const struct bpf_prog *prog)	\
{									\
	return emit_alu8_imm_x86(image, off, emit, payload, prog,	\
				 modrm_base);				\
}

DEFINE_ALU8_IMM_EMIT(addb_imm, 0xc0)
DEFINE_ALU8_IMM_EMIT(andb_imm, 0xe0)
DEFINE_ALU8_IMM_EMIT(xorb_imm, 0xf0)

static int emit_xorb_rr_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	err = decode_reg_reg_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex8_rr(buf, &len, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x30);
	kinsn_emit_u8(buf, &len, 0xc0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_orb_rr_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	err = decode_reg_reg_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex8_rr(buf, &len, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x08);
	kinsn_emit_u8(buf, &len, 0xc0 | (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_incq_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	kinsn_emit_rex_rr(buf, &len, true, 0, dst_reg);
	kinsn_emit_u8(buf, &len, 0xff);
	kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_sbbl_imm0_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cond_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_sbb_payload(payload, &dst_reg, &cond_reg);
	if (err)
		return err;
	(void)cond_reg;

	kinsn_emit_rex_rr(buf, &len, false, 0, dst_reg);
	kinsn_emit_u8(buf, &len, 0x83);
	kinsn_emit_u8(buf, &len, 0xd8 | kinsn_x86_reg_code(dst_reg));
	kinsn_emit_u8(buf, &len, 0);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_addb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_addb_imm,
	.emit_x86 = emit_addb_imm_x86,
};

const struct bpf_kinsn bpf_x86_andb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_andb_imm,
	.emit_x86 = emit_andb_imm_x86,
};

const struct bpf_kinsn bpf_x86_incq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_incq,
	.emit_x86 = emit_incq_x86,
};

const struct bpf_kinsn bpf_x86_sbbl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_sbbl_imm0,
	.emit_x86 = emit_sbbl_imm0_x86,
};

const struct bpf_kinsn bpf_x86_xorb_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_xorb_imm,
	.emit_x86 = emit_xorb_imm_x86,
};

const struct bpf_kinsn bpf_x86_xorb_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 9 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_xorb_rr,
	.emit_x86 = emit_xorb_rr_x86,
};

const struct bpf_kinsn bpf_x86_orb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 9 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_orb_rr,
	.emit_x86 = emit_orb_rr_x86,
};

#define DEFINE_X86_ALU_DESC(name)					\
const struct bpf_kinsn bpf_x86_##name##_desc = {			\
	.owner = THIS_MODULE,						\
	.max_insn_cnt = 9 + KINSN_X86_SAVE_RESTORE_INSN_CNT,						\
	.max_emit_bytes = 8,						\
	.instantiate_insn = instantiate_##name,				\
	.emit_x86 = emit_##name##_x86,					\
}

DEFINE_X86_ALU_DESC(addq);
DEFINE_X86_ALU_DESC(addl);
DEFINE_X86_ALU_DESC(subq);
DEFINE_X86_ALU_DESC(subl);
DEFINE_X86_ALU_DESC(andq);
DEFINE_X86_ALU_DESC(andl);
DEFINE_X86_ALU_DESC(xorq);
DEFINE_X86_ALU_DESC(xorl);
DEFINE_X86_ALU_DESC(orq);
DEFINE_X86_ALU_DESC(orl);
DEFINE_X86_ALU_DESC(shlq);
DEFINE_X86_ALU_DESC(shll);
DEFINE_X86_ALU_DESC(shrq);
DEFINE_X86_ALU_DESC(shrl);
DEFINE_X86_ALU_DESC(sarq);
DEFINE_X86_ALU_DESC(sarl);

static const struct bpf_kinsn * const bpf_x86_alu_imm_kinsn_descs[] = {
	/*
	 * resolve_btfids stores the set in resolved BTF-id order, not source
	 * declaration order. Keep this array in the same order as .BTF_ids;
	 * otherwise a kfunc call gets the wrong kinsn descriptor and fails
	 * before verifier instruction processing starts.
	 */
	&bpf_x86_addb_desc,
	&bpf_x86_addl_desc,
	&bpf_x86_addq_desc,
	&bpf_x86_andb_desc,
	&bpf_x86_andl_desc,
	&bpf_x86_andq_desc,
	&bpf_x86_incq_desc,
	&bpf_x86_orb_desc,
	&bpf_x86_orl_desc,
	&bpf_x86_orq_desc,
	&bpf_x86_sarl_desc,
	&bpf_x86_sarq_desc,
	&bpf_x86_sbbl_desc,
	&bpf_x86_shll_desc,
	&bpf_x86_shlq_desc,
	&bpf_x86_shrl_desc,
	&bpf_x86_shrq_desc,
	&bpf_x86_subl_desc,
	&bpf_x86_subq_desc,
	&bpf_x86_xorb_imm_desc,
	&bpf_x86_xorb_rr_desc,
	&bpf_x86_xorl_desc,
	&bpf_x86_xorq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_alu_imm,
		       "BpfReJIT x86 kinsns: immediate ALU",
		       bpf_x86_alu_imm_kfunc_ids,
		       bpf_x86_alu_imm_kinsn_descs);
