// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: CMP, TEST, SETcc, and CMOV.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_cmpb(void) {}
__bpf_kfunc void bpf_x86_cmpq(void) {}
__bpf_kfunc void bpf_x86_cmpl(void) {}
__bpf_kfunc void bpf_x86_cmpw(void) {}
__bpf_kfunc void bpf_x86_testq(void) {}
__bpf_kfunc void bpf_x86_testl(void) {}
__bpf_kfunc void bpf_x86_testb(void) {}
__bpf_kfunc void bpf_x86_testw(void) {}
__bpf_kfunc void bpf_x86_cmovnel(void) {}
__bpf_kfunc void bpf_x86_cmovel(void) {}
__bpf_kfunc void bpf_x86_cmovneq(void) {}
__bpf_kfunc void bpf_x86_cmoveq(void) {}
__bpf_kfunc void bpf_x86_cmovbl(void) {}
__bpf_kfunc void bpf_x86_cmovbq(void) {}
__bpf_kfunc void bpf_x86_sete(void) {}
__bpf_kfunc void bpf_x86_setge(void) {}
__bpf_kfunc void bpf_x86_setne(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_cmov_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_cmovbl)
BTF_ID_FLAGS(func, bpf_x86_cmovbq)
BTF_ID_FLAGS(func, bpf_x86_cmovel)
BTF_ID_FLAGS(func, bpf_x86_cmoveq)
BTF_ID_FLAGS(func, bpf_x86_cmovnel)
BTF_ID_FLAGS(func, bpf_x86_cmovneq)
BTF_ID_FLAGS(func, bpf_x86_cmpb)
BTF_ID_FLAGS(func, bpf_x86_cmpl)
BTF_ID_FLAGS(func, bpf_x86_cmpq)
BTF_ID_FLAGS(func, bpf_x86_cmpw)
BTF_ID_FLAGS(func, bpf_x86_sete)
BTF_ID_FLAGS(func, bpf_x86_setge)
BTF_ID_FLAGS(func, bpf_x86_setne)
BTF_ID_FLAGS(func, bpf_x86_testb)
BTF_ID_FLAGS(func, bpf_x86_testl)
BTF_ID_FLAGS(func, bpf_x86_testq)
BTF_ID_FLAGS(func, bpf_x86_testw)
BTF_KFUNCS_END(bpf_x86_cmov_kfunc_ids)

enum x86_flag_payload_kind {
	X86_FLAG_PAYLOAD_STACK = 5,
	X86_FLAG_PAYLOAD_ARCH_STACK = 6,
};

enum x86_operand_form {
	X86_OPERAND_FORM_RR = 1,
	X86_OPERAND_FORM_IMM = 2,
	X86_OPERAND_FORM_SIB_RR = 3,
	X86_OPERAND_FORM_MEM_IMM = 4,
	X86_OPERAND_FORM_ARCH_MEM_IMM = 9,
	X86_OPERAND_FORM_ARCH_RR = 12,
	X86_OPERAND_FORM_ARCH_IMM = 13,
};

static __always_inline u8 payload_form(u64 payload)
{
	return kinsn_payload_decode(payload) & 0xf;
}

static __always_inline bool bpf_reg_ok(u8 reg)
{
	return kinsn_x86_operand_valid(reg);
}

static __always_inline bool bpf_gpr_ok(u8 reg)
{
	return kinsn_bpf_gpr_valid(reg);
}

static __always_inline void store_cmp_sge_reg(struct bpf_insn *insn_buf,
					      int *cnt, u8 left_reg,
					      u8 right_reg, bool is32)
{
	insn_buf[(*cnt)++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
					KINSN_X86_SHADOW_GE_OFF, 0);
	insn_buf[(*cnt)++] = is32 ?
		BPF_JMP32_REG(BPF_JSLT, left_reg, right_reg, 1) :
		BPF_JMP_REG(BPF_JSLT, left_reg, right_reg, 1);
	insn_buf[(*cnt)++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
					KINSN_X86_SHADOW_GE_OFF, 1);
}

static __always_inline void store_cmp_sge_imm(struct bpf_insn *insn_buf,
					      int *cnt, u8 left_reg,
					      s32 imm, bool is32)
{
	insn_buf[(*cnt)++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
					KINSN_X86_SHADOW_GE_OFF, 0);
	insn_buf[(*cnt)++] = is32 ?
		BPF_JMP32_IMM(BPF_JSLT, left_reg, imm, 1) :
		BPF_JMP_IMM(BPF_JSLT, left_reg, imm, 1);
	insn_buf[(*cnt)++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
					KINSN_X86_SHADOW_GE_OFF, 1);
}

static __always_inline void sign_extend_narrow(struct bpf_insn *insn_buf,
					       int *cnt, u8 reg, u8 width)
{
	u8 shift = 64 - width;

	insn_buf[(*cnt)++] = BPF_ALU64_IMM(BPF_LSH, reg, shift);
	insn_buf[(*cnt)++] = BPF_ALU64_IMM(BPF_ARSH, reg, shift);
}

static __always_inline int decode_cmp_rr_payload(u64 payload, u8 *left_reg,
						 u8 *right_reg)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_OPERAND_FORM_RR &&
	    (payload & 0xf) != X86_OPERAND_FORM_ARCH_RR)
		return -EINVAL;
	*left_reg = kinsn_payload_reg(payload, 4);
	*right_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!bpf_reg_ok(*left_reg) || !bpf_reg_ok(*right_reg))
		return -EINVAL;
	if ((payload & 0xf) == X86_OPERAND_FORM_ARCH_RR &&
	    *left_reg != BPF_REG_10 && *right_reg != BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmp_imm_payload(u64 payload, u8 *reg,
						  s32 *imm)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_OPERAND_FORM_IMM &&
	    (payload & 0xf) != X86_OPERAND_FORM_ARCH_IMM)
		return -EINVAL;
	*reg = kinsn_payload_reg(payload, 4);
	*imm = kinsn_payload_s32(payload, 8);

	if (payload >> 40)
		return -EINVAL;
	if (!bpf_reg_ok(*reg))
		return -EINVAL;
	if ((payload & 0xf) == X86_OPERAND_FORM_ARCH_IMM &&
	    *reg != BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmp_sib_rr_payload(u64 payload,
						     u8 *base_reg,
						     u8 *index_reg,
						     u8 *scale_log2,
						     s16 *offset,
						     u8 *rhs_reg)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_OPERAND_FORM_SIB_RR)
		return -EINVAL;
	*base_reg = kinsn_payload_reg(payload, 4);
	*index_reg = kinsn_payload_reg(payload, 8);
	*scale_log2 = (payload >> 12) & 0x3;
	*rhs_reg = kinsn_payload_reg(payload, 16);
	*offset = kinsn_payload_s16(payload, 20);

	if (payload >> 36)
		return -EINVAL;
	if (payload & (0x3ULL << 14))
		return -EINVAL;
	if (!bpf_gpr_ok(*base_reg) || !bpf_gpr_ok(*index_reg) ||
	    !bpf_reg_ok(*rhs_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmp_mem_imm_payload(u64 payload,
						      u8 *base_reg,
						      s16 *offset,
						      s32 *imm)
{
	payload = kinsn_payload_decode(payload);
	if (((payload & 0xf) != X86_OPERAND_FORM_MEM_IMM &&
	     (payload & 0xf) != X86_OPERAND_FORM_ARCH_MEM_IMM) ||
	    payload >> 56)
		return -EINVAL;

	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);
	*imm = kinsn_payload_s32(payload, 24);
	if (*base_reg > BPF_REG_10 || !kinsn_x86_reg_valid(*base_reg))
		return -EINVAL;
	if ((payload & 0xf) == X86_OPERAND_FORM_ARCH_MEM_IMM &&
	    *base_reg != BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_test_rr_payload(u64 payload,
						  u8 *left_reg,
						  u8 *right_reg)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_OPERAND_FORM_RR &&
	    (payload & 0xf) != X86_OPERAND_FORM_ARCH_RR)
		return -EINVAL;
	*left_reg = kinsn_payload_reg(payload, 4);
	*right_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!bpf_reg_ok(*left_reg) || !bpf_reg_ok(*right_reg))
		return -EINVAL;
	if ((payload & 0xf) == X86_OPERAND_FORM_ARCH_RR &&
	    *left_reg != BPF_REG_10 && *right_reg != BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_testb_imm_payload(u64 payload,
						    u8 *reg,
						    u8 *imm)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_OPERAND_FORM_IMM &&
	    (payload & 0xf) != X86_OPERAND_FORM_ARCH_IMM)
		return -EINVAL;
	*reg = kinsn_payload_reg(payload, 4);
	*imm = kinsn_payload_u8(payload, 8);

	if (payload >> 16)
		return -EINVAL;
	if (!bpf_reg_ok(*reg))
		return -EINVAL;
	if ((payload & 0xf) == X86_OPERAND_FORM_ARCH_IMM &&
	    *reg != BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_test_mem_imm_payload(u64 payload,
						       u8 *base_reg,
						       s16 *offset,
						       u8 *imm)
{
	s32 wide_imm;
	int err;

	err = decode_cmp_mem_imm_payload(payload, base_reg, offset,
					 &wide_imm);
	if (err)
		return err;
	if (wide_imm < 0 || wide_imm > 0xff)
		return -EINVAL;
	*imm = wide_imm;
	return 0;
}

static __always_inline int decode_cmov_payload(u64 payload,
					       u8 *dst_reg,
					       u8 *src_reg,
					       u8 *cond_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*cond_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 ||
	    *cond_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) || !kinsn_x86_reg_valid(*src_reg) ||
	    !kinsn_x86_reg_valid(*cond_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmov_emit_payload(u64 payload,
						    u8 *dst_reg,
						    u8 *src_reg)
{
	payload = kinsn_payload_decode(payload);
	u8 kind = kinsn_payload_reg(payload, 12);

	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (!bpf_reg_ok(*dst_reg) || !bpf_reg_ok(*src_reg))
		return -EINVAL;
	if (!kind) {
		u8 cond_reg = kinsn_payload_reg(payload, 8);

		if (payload >> 12)
			return -EINVAL;
		if (!bpf_reg_ok(cond_reg))
			return -EINVAL;
		return 0;
	}
	if (kind == X86_FLAG_PAYLOAD_STACK ||
	    kind == X86_FLAG_PAYLOAD_ARCH_STACK) {
		if (payload >> 16)
			return -EINVAL;
		if (payload & (0xfULL << 8))
			return -EINVAL;
		if (kind == X86_FLAG_PAYLOAD_ARCH_STACK &&
		    *dst_reg != BPF_REG_10 && *src_reg != BPF_REG_10)
			return -EINVAL;
		return 0;
	}
	return -EINVAL;
}

static __always_inline int decode_setcc_payload(u64 payload,
						u8 *dst_reg,
						u8 *cond_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*cond_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!bpf_reg_ok(*dst_reg) || !bpf_reg_ok(*cond_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_setcc_emit_payload(u64 payload, u8 *dst_reg)
{
	payload = kinsn_payload_decode(payload);
	u8 kind = kinsn_payload_reg(payload, 16);

	*dst_reg = kinsn_payload_reg(payload, 0);
	if (!kind) {
		u8 cond_reg = kinsn_payload_reg(payload, 4);

		if (payload >> 8)
			return -EINVAL;
		if (!bpf_reg_ok(*dst_reg) || !bpf_reg_ok(cond_reg))
			return -EINVAL;
		return 0;
	}
	if (kind == X86_FLAG_PAYLOAD_STACK) {
		if (payload >> 20)
			return -EINVAL;
		if ((payload & (0xfULL << 4)) || (payload & (0xfULL << 8)) ||
		    (payload & (0xfULL << 12)))
			return -EINVAL;
		if (!bpf_reg_ok(*dst_reg))
			return -EINVAL;
		return 0;
	}
	return -EINVAL;
}

static int instantiate_cmp_rr_flags(u64 payload, struct bpf_insn *insn_buf,
				    bool is32)
{
	u8 left_reg, right_reg;
	u8 left_eval_reg, right_eval_reg;
	u32 scratch_mask = 0;
	bool arch_reg, left_shadowed, right_shadowed;
	int cnt = 0;
	int err;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_RR;
	left_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(left_reg) :
				   kinsn_x86_reg_is_shadowed(left_reg);
	right_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(right_reg) :
				    kinsn_x86_reg_is_shadowed(right_reg);
	left_eval_reg = left_reg;
	right_eval_reg = right_reg;
	if (left_shadowed) {
		left_eval_reg = kinsn_x86_scratch_avoid(right_reg, 0, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(left_eval_reg);
	}
	if (right_shadowed) {
		right_eval_reg = kinsn_x86_scratch_avoid(left_reg,
							 left_eval_reg, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(right_eval_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (left_shadowed) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt, left_eval_reg,
					      left_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, left_eval_reg,
					 left_reg);
	}
	if (right_shadowed) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt, right_eval_reg,
					      right_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, right_eval_reg,
					 right_reg);
	}
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, left_eval_reg,
				      KINSN_X86_PROOF_LHS_OFF);
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, right_eval_reg,
				      KINSN_X86_PROOF_RHS_OFF);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = is32 ? BPF_JMP32_REG(BPF_JNE, left_eval_reg, right_eval_reg, 1) :
				  BPF_JMP_REG(BPF_JNE, left_eval_reg, right_eval_reg, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = is32 ? BPF_JMP32_REG(BPF_JGE, left_eval_reg, right_eval_reg, 1) :
				  BPF_JMP_REG(BPF_JGE, left_eval_reg, right_eval_reg, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	store_cmp_sge_reg(insn_buf, &cnt, left_eval_reg, right_eval_reg,
			  is32);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmp_imm_flags(u64 payload, struct bpf_insn *insn_buf,
				     bool is32)
{
	u8 reg, eval_reg;
	u32 scratch_mask = 0;
	s32 imm;
	bool arch_reg, reg_shadowed;
	int cnt = 0;
	int err;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_IMM;
	reg_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(reg) :
				  kinsn_x86_reg_is_shadowed(reg);
	eval_reg = reg;
	if (reg_shadowed) {
		eval_reg = kinsn_x86_scratch_avoid(reg, 0, 0);
		scratch_mask = KINSN_X86_SCRATCH_MASK(eval_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (reg_shadowed) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt, eval_reg, reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, eval_reg, reg);
	}
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, eval_reg,
				      KINSN_X86_PROOF_LHS_OFF);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_DW, BPF_REG_10,
				     KINSN_X86_PROOF_RHS_OFF, imm);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = is32 ? BPF_JMP32_IMM(BPF_JNE, eval_reg, imm, 1) :
				  BPF_JMP_IMM(BPF_JNE, eval_reg, imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = is32 ? BPF_JMP32_IMM(BPF_JGE, eval_reg, imm, 1) :
				  BPF_JMP_IMM(BPF_JGE, eval_reg, imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	store_cmp_sge_imm(insn_buf, &cnt, eval_reg, imm, is32);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmp_mem_imm_flags(u64 payload, struct bpf_insn *insn_buf,
					 u8 size, bool is32)
{
	u8 base_reg, value_reg;
	u32 scratch_mask;
	s16 offset;
	s32 imm;
	bool arch_mem;
	u8 addr_reg;
	s32 sge_imm;
	int cnt = 0;
	int err;

	err = decode_cmp_mem_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;
	if (size == BPF_B && (imm < 0 || imm > 0xff))
		return -EINVAL;
	sge_imm = imm;

	arch_mem = payload_form(payload) == X86_OPERAND_FORM_ARCH_MEM_IMM;
	value_reg = kinsn_x86_scratch_avoid(base_reg, 0, 0);
	addr_reg = base_reg;
	scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg);
	if (arch_mem) {
		addr_reg = kinsn_x86_scratch_avoid(base_reg, value_reg, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(addr_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_mem)
		kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg, base_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(size, value_reg, addr_reg, offset);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = is32 ? BPF_JMP32_IMM(BPF_JNE, value_reg, imm, 1) :
				  BPF_JMP_IMM(BPF_JNE, value_reg, imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = is32 ? BPF_JMP32_IMM(BPF_JGE, value_reg, imm, 1) :
				  BPF_JMP_IMM(BPF_JGE, value_reg, imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	if (size == BPF_B) {
		sign_extend_narrow(insn_buf, &cnt, value_reg, 8);
		sge_imm = (s8)imm;
	} else if (size == BPF_H) {
		sign_extend_narrow(insn_buf, &cnt, value_reg, 16);
		sge_imm = (s16)imm;
	}
	store_cmp_sge_imm(insn_buf, &cnt, value_reg, sge_imm, is32);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmp_narrow_rr_flags(u64 payload, struct bpf_insn *insn_buf,
					   u32 mask)
{
	u8 left_reg, right_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_RR;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg) {
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      left_reg);
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH1,
				      right_reg);
	} else {
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				 left_reg);
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1,
				 right_reg);
	}
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH0, mask);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, mask);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_REG(BPF_JNE, KINSN_X86_SCRATCH0,
				      KINSN_X86_SCRATCH1, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_REG(BPF_JGE, KINSN_X86_SCRATCH0,
				      KINSN_X86_SCRATCH1, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	sign_extend_narrow(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			   mask == 0xff ? 8 : 16);
	sign_extend_narrow(insn_buf, &cnt, KINSN_X86_SCRATCH1,
			   mask == 0xff ? 8 : 16);
	store_cmp_sge_reg(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			  KINSN_X86_SCRATCH1, false);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmpb_imm_flags(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	s32 imm;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;
	if (imm < 0 || imm > 0xff)
		return -EINVAL;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_IMM;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH0, 0xff);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JNE, KINSN_X86_SCRATCH0, imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JGE, KINSN_X86_SCRATCH0, imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	sign_extend_narrow(insn_buf, &cnt, KINSN_X86_SCRATCH0, 8);
	store_cmp_sge_imm(insn_buf, &cnt, KINSN_X86_SCRATCH0, (s8)imm,
			  false);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmpw_imm_flags(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	s32 imm;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;
	if (imm < 0 || imm > 0xffff)
		return -EINVAL;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_IMM;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH0,
					0xffff);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JNE, KINSN_X86_SCRATCH0,
				      imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JGE, KINSN_X86_SCRATCH0,
				      imm, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	sign_extend_narrow(insn_buf, &cnt, KINSN_X86_SCRATCH0, 16);
	store_cmp_sge_imm(insn_buf, &cnt, KINSN_X86_SCRATCH0, (s16)imm,
			  false);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmpq_sib_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 base_reg, index_reg, scale_log2, rhs_reg;
	u8 addr_tmp_reg, value_tmp_reg, rhs_eval_reg;
	u32 scratch_mask;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_cmp_sib_rr_payload(payload, &base_reg, &index_reg,
					&scale_log2, &offset, &rhs_reg);
	if (err)
		return err;

	addr_tmp_reg = kinsn_x86_scratch_avoid(base_reg, index_reg, rhs_reg);
	value_tmp_reg = kinsn_x86_scratch_avoid(base_reg, index_reg,
						addr_tmp_reg);
	rhs_eval_reg = rhs_reg;
	scratch_mask = KINSN_X86_SCRATCH_MASK(addr_tmp_reg) |
		       KINSN_X86_SCRATCH_MASK(value_tmp_reg);
	if (kinsn_x86_reg_is_shadowed(rhs_reg)) {
		rhs_eval_reg = kinsn_x86_scratch_avoid4(base_reg, index_reg,
							addr_tmp_reg,
							value_tmp_reg);
		if (rhs_eval_reg == addr_tmp_reg || rhs_eval_reg == value_tmp_reg)
			return -EINVAL;
		scratch_mask |= KINSN_X86_SCRATCH_MASK(rhs_eval_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_MOV64_REG(addr_tmp_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_tmp_reg,
						index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, value_tmp_reg, addr_tmp_reg,
				      offset);

	if (kinsn_x86_reg_is_shadowed(rhs_reg))
		kinsn_x86_read64(insn_buf, &cnt, rhs_eval_reg, rhs_reg);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_REG(BPF_JNE, value_tmp_reg, rhs_eval_reg, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_REG(BPF_JGE, value_tmp_reg, rhs_eval_reg, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 1);
	store_cmp_sge_reg(insn_buf, &cnt, value_tmp_reg, rhs_eval_reg,
			  false);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmpq(u64 payload, struct bpf_insn *insn_buf)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return instantiate_cmp_rr_flags(payload, insn_buf, false);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return instantiate_cmp_imm_flags(payload, insn_buf, false);
	case X86_OPERAND_FORM_SIB_RR:
		return instantiate_cmpq_sib_rr(payload, insn_buf);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return instantiate_cmp_mem_imm_flags(payload, insn_buf,
						     BPF_DW, false);
	default:
		return -EINVAL;
	}
}

static int instantiate_cmpb(u64 payload, struct bpf_insn *insn_buf)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return instantiate_cmp_narrow_rr_flags(payload, insn_buf, 0xff);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return instantiate_cmpb_imm_flags(payload, insn_buf);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return instantiate_cmp_mem_imm_flags(payload, insn_buf,
						     BPF_B, false);
	default:
		return -EINVAL;
	}
}

static int instantiate_cmpl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return instantiate_cmp_rr_flags(payload, insn_buf, true);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return instantiate_cmp_imm_flags(payload, insn_buf, true);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return instantiate_cmp_mem_imm_flags(payload, insn_buf,
						     BPF_W, true);
	default:
		return -EINVAL;
	}
}

static int instantiate_cmpw(u64 payload, struct bpf_insn *insn_buf)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return instantiate_cmp_narrow_rr_flags(payload, insn_buf,
						       0xffff);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return instantiate_cmpw_imm_flags(payload, insn_buf);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return instantiate_cmp_mem_imm_flags(payload, insn_buf,
						     BPF_H, false);
	default:
		return -EINVAL;
	}
}

static int instantiate_test_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 left_reg, right_reg, value_reg, right_eval_reg;
	u32 scratch_mask;
	bool arch_reg, right_shadowed;
	int cnt = 0;
	int err;

	err = decode_test_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_RR;
	right_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(right_reg) :
				    kinsn_x86_reg_is_shadowed(right_reg);
	right_eval_reg = right_reg;
	value_reg = kinsn_x86_scratch_avoid(left_reg, right_reg, 0);
	scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg);
	if (right_shadowed) {
		right_eval_reg = kinsn_x86_scratch_avoid(left_reg, right_reg,
							 value_reg);
		if (right_eval_reg == value_reg)
			return -EINVAL;
		scratch_mask |= KINSN_X86_SCRATCH_MASK(right_eval_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, value_reg, left_reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, value_reg, left_reg);
	if (right_shadowed) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt, right_eval_reg,
					      right_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, right_eval_reg,
					 right_reg);
	}
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, value_reg, right_eval_reg);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JNE, value_reg, 0, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_testw_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 left_reg, right_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_test_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_RR;
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg) {
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      left_reg);
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH1,
				      right_reg);
	} else {
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				 left_reg);
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1,
				 right_reg);
	}
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH0,
					0xffff);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JNE, KINSN_X86_SCRATCH0, 0, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_testb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg, eval_reg, imm;
	u32 scratch_mask;
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_testb_imm_payload(payload, &reg, &imm);
	if (err)
		return err;

	arch_reg = payload_form(payload) == X86_OPERAND_FORM_ARCH_IMM;
	eval_reg = kinsn_x86_scratch_avoid(reg, 0, 0);
	scratch_mask = KINSN_X86_SCRATCH_MASK(eval_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, eval_reg, reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, eval_reg, reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, eval_reg, imm);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JNE, eval_reg, 0, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_testb_mem_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 base_reg, addr_reg, value_reg, imm;
	u32 scratch_mask;
	s16 offset;
	bool arch_mem;
	int cnt = 0;
	int err;

	err = decode_test_mem_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;

	arch_mem = payload_form(payload) == X86_OPERAND_FORM_ARCH_MEM_IMM;
	value_reg = kinsn_x86_scratch_avoid(base_reg, 0, 0);
	addr_reg = base_reg;
	scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg);
	if (arch_mem) {
		addr_reg = kinsn_x86_scratch_avoid(base_reg, value_reg, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(addr_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_mem)
		kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg, base_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_B, value_reg, addr_reg, offset);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, value_reg, imm);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_CF_OFF, 0);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JNE, value_reg, 0, 1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_W, BPF_REG_10,
				     KINSN_X86_SHADOW_ZF_OFF, 1);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_testq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_test_rr(payload, insn_buf);
}

static int instantiate_testl(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_test_rr(payload, insn_buf);
}

static int instantiate_testw(u64 payload, struct bpf_insn *insn_buf)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return instantiate_testw_rr(payload, insn_buf);
	default:
		return -EINVAL;
	}
}

static int instantiate_testb(u64 payload, struct bpf_insn *insn_buf)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return instantiate_test_rr(payload, insn_buf);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return instantiate_testb_imm(payload, insn_buf);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return instantiate_testb_mem_imm(payload, insn_buf);
	default:
		return -EINVAL;
	}
}

static int instantiate_cmov(u64 payload, struct bpf_insn *insn_buf, bool move_on_eq)
{
	u8 dst_reg, src_reg, cond_reg;
	int err;

	err = decode_cmov_payload(payload, &dst_reg, &src_reg, &cond_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_IMM(move_on_eq ? BPF_JNE : BPF_JEQ, cond_reg, 0, 1);
	insn_buf[1] = BPF_MOV64_REG(dst_reg, src_reg);
	return 2;
}

static int instantiate_cmov_nonzero(u64 payload, struct bpf_insn *insn_buf,
				    bool is64)
{
	u8 dst_reg, src_reg, cond_reg;
	int err;

	err = decode_cmov_payload(payload, &dst_reg, &src_reg, &cond_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_IMM(BPF_JEQ, cond_reg, 0, 1);
	insn_buf[1] = is64 ? BPF_MOV64_REG(dst_reg, src_reg) :
			      BPF_MOV32_REG(dst_reg, src_reg);
	return 2;
}

static int instantiate_cmov_stack(u64 payload, struct bpf_insn *insn_buf,
				  bool move_on_set, bool is64, s16 flag_off)
{
	u8 dst_reg, src_reg;
	u8 flag_reg, value_reg;
	u32 scratch_mask;
	bool arch_reg;
	bool src_shadowed, dst_shadowed;
	s16 move_cnt = 1;
	int cnt = 0;
	int err;

	err = decode_cmov_emit_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	arch_reg = kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_ARCH_STACK;
	src_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(src_reg) :
				  kinsn_x86_reg_is_shadowed(src_reg);
	dst_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(dst_reg) :
				  kinsn_x86_reg_is_shadowed(dst_reg);
	flag_reg = kinsn_x86_scratch_avoid(dst_reg, src_reg, 0);
	value_reg = kinsn_x86_scratch_avoid(dst_reg, src_reg, flag_reg);
	if (value_reg == flag_reg)
		return -EINVAL;
	scratch_mask = KINSN_X86_SCRATCH_MASK(flag_reg) |
		       KINSN_X86_SCRATCH_MASK(value_reg);
	if (src_shadowed)
		move_cnt = is64 ? 2 : 3;
	else if (dst_shadowed)
		move_cnt = is64 ? 1 : 2;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_W, flag_reg, BPF_REG_10, flag_off);
	insn_buf[cnt++] = BPF_JMP_IMM(move_on_set ? BPF_JEQ : BPF_JNE,
				      flag_reg, 0, move_cnt);
	if (src_shadowed) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt, value_reg,
					      src_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, value_reg, src_reg);
		if (!is64)
			insn_buf[cnt++] = BPF_MOV32_REG(value_reg, value_reg);
		if (is64) {
			if (arch_reg)
				kinsn_x86_write64_arch(insn_buf, &cnt,
						       dst_reg, value_reg,
						       scratch_mask);
			else
				kinsn_x86_write64(insn_buf, &cnt, dst_reg,
						  value_reg, scratch_mask);
		} else {
			if (arch_reg)
				kinsn_x86_write32_arch(insn_buf, &cnt,
						       dst_reg, value_reg,
						       scratch_mask);
			else
				kinsn_x86_write32(insn_buf, &cnt, dst_reg,
						  value_reg, scratch_mask);
		}
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}
	if (dst_shadowed) {
		if (is64) {
			kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
					       src_reg, scratch_mask);
		} else {
			insn_buf[cnt++] = BPF_MOV32_REG(value_reg, src_reg);
			if (arch_reg)
				kinsn_x86_write32_arch(insn_buf, &cnt,
						       dst_reg, value_reg,
						       scratch_mask);
			else
				kinsn_x86_write32(insn_buf, &cnt, dst_reg,
						  value_reg, scratch_mask);
		}
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}
	insn_buf[cnt++] = is64 ? BPF_MOV64_REG(dst_reg, src_reg) :
			      BPF_MOV32_REG(dst_reg, src_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_cmov_eqne(u64 payload, struct bpf_insn *insn_buf,
				 bool move_on_eq, bool is64)
{
	if (kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_STACK ||
	    kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_ARCH_STACK)
		return instantiate_cmov_stack(payload, insn_buf, move_on_eq,
					      is64, KINSN_X86_SHADOW_ZF_OFF);
	return instantiate_cmov(payload, insn_buf, move_on_eq);
}

static int instantiate_cmovnel(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, false, false);
}

static int instantiate_cmovel(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, true, false);
}

static int instantiate_cmovneq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, false, true);
}

static int instantiate_cmoveq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, true, true);
}

static int instantiate_cmovbl(u64 payload, struct bpf_insn *insn_buf)
{
	if (kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_STACK ||
	    kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_ARCH_STACK)
		return instantiate_cmov_stack(payload, insn_buf, true, false,
					      KINSN_X86_SHADOW_CF_OFF);
	return instantiate_cmov_nonzero(payload, insn_buf, false);
}

static int instantiate_cmovbq(u64 payload, struct bpf_insn *insn_buf)
{
	if (kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_STACK ||
	    kinsn_payload_reg(payload, 12) == X86_FLAG_PAYLOAD_ARCH_STACK)
		return instantiate_cmov_stack(payload, insn_buf, true, true,
					      KINSN_X86_SHADOW_CF_OFF);
	return instantiate_cmov_nonzero(payload, insn_buf, true);
}

static int instantiate_setcc(u64 payload, struct bpf_insn *insn_buf, u8 op)
{
	u8 dst_reg, cond_reg, high_reg, cond_eval_reg;
	u32 scratch_mask;
	int cnt = 0;
	int err;

	err = decode_setcc_payload(payload, &dst_reg, &cond_reg);
	if (err)
		return err;

	high_reg = kinsn_x86_scratch_avoid(dst_reg, cond_reg, 0);
	cond_eval_reg = cond_reg;
	scratch_mask = KINSN_X86_SCRATCH_MASK(high_reg);
	if (kinsn_x86_reg_is_shadowed(cond_reg)) {
		cond_eval_reg = kinsn_x86_scratch_avoid(dst_reg, cond_reg,
							high_reg);
		if (cond_eval_reg == high_reg)
			return -EINVAL;
		scratch_mask |= KINSN_X86_SCRATCH_MASK(cond_eval_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, high_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, high_reg, -256);
	if (kinsn_x86_reg_is_shadowed(cond_reg))
		kinsn_x86_read64(insn_buf, &cnt, cond_eval_reg, cond_reg);
	insn_buf[cnt++] = BPF_JMP_IMM(op, cond_eval_reg, 0, 1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_OR, high_reg, 1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, high_reg, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_setcc_stack_flag(u64 payload, struct bpf_insn *insn_buf,
					s16 flag_off, bool invert)
{
	u8 dst_reg = kinsn_payload_reg(payload, 0);
	u8 tmp_high_reg, tmp_flag_reg;
	u32 scratch_mask;
	int cnt = 0;

	if (decode_setcc_emit_payload(payload, &dst_reg))
		return -EINVAL;

	tmp_high_reg = kinsn_x86_scratch_avoid(dst_reg, 0, 0);
	tmp_flag_reg = kinsn_x86_scratch_avoid(dst_reg, tmp_high_reg, 0);
	if (tmp_high_reg == tmp_flag_reg)
		return -EINVAL;
	scratch_mask = KINSN_X86_SCRATCH_MASK(tmp_high_reg) |
		       KINSN_X86_SCRATCH_MASK(tmp_flag_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, tmp_high_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, tmp_high_reg, -256);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_W, tmp_flag_reg, BPF_REG_10,
				      flag_off);
	if (invert)
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, tmp_flag_reg, 1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, tmp_high_reg, tmp_flag_reg);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, tmp_high_reg,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_setcc_dispatch(u64 payload, struct bpf_insn *insn_buf,
				      u8 op)
{
	if (kinsn_payload_reg(payload, 16) == X86_FLAG_PAYLOAD_STACK) {
		if (op == BPF_JNE)
			return instantiate_setcc_stack_flag(payload, insn_buf,
							   KINSN_X86_SHADOW_ZF_OFF,
							   false);
		if (op == BPF_JEQ)
			return instantiate_setcc_stack_flag(payload, insn_buf,
							   KINSN_X86_SHADOW_ZF_OFF,
							   true);
		if (op == BPF_JSLT)
			return instantiate_setcc_stack_flag(payload, insn_buf,
							   KINSN_X86_SHADOW_GE_OFF,
							   false);
		return -EINVAL;
	}
	return instantiate_setcc(payload, insn_buf, op);
}

static int instantiate_setne_r(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_setcc_dispatch(payload, insn_buf, BPF_JEQ);
}

static int instantiate_sete_r(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_setcc_dispatch(payload, insn_buf, BPF_JNE);
}

static int instantiate_setge_r(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_setcc_dispatch(payload, insn_buf, BPF_JSLT);
}

static int emit_cmp_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog, bool is64)
{
	u8 buf[4];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	kinsn_emit_rex_rr(buf, &len, is64, right_reg, left_reg);
	kinsn_emit_u8(buf, &len, 0x39);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmpb_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	kinsn_emit_rex8_rr(buf, &len, right_reg, left_reg);
	kinsn_emit_u8(buf, &len, 0x38);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmpw_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 buf[5];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex_rr(buf, &len, false, right_reg, left_reg);
	kinsn_emit_u8(buf, &len, 0x39);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmp_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, bool is64)
{
	u8 buf[8];
	u8 reg;
	s32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;

	if (imm >= S8_MIN && imm <= S8_MAX) {
		kinsn_emit_rex_rr(buf, &len, is64, 0, reg);
		kinsn_emit_u8(buf, &len, 0x83);
		kinsn_emit_u8(buf, &len, 0xF8 | kinsn_x86_reg_code(reg));
		kinsn_emit_u8(buf, &len, (u8)imm);
		return kinsn_emit_finish(image, off, emit, buf, len);
	}

	if (reg == BPF_REG_0) {
		kinsn_emit_rex_rr(buf, &len, is64, 0, reg);
		kinsn_emit_u8(buf, &len, 0x3D);
		kinsn_emit_s32(buf, &len, imm);
		return kinsn_emit_finish(image, off, emit, buf, len);
	}

	kinsn_emit_rex_rr(buf, &len, is64, 0, reg);
	kinsn_emit_u8(buf, &len, 0x81);
	kinsn_emit_u8(buf, &len, 0xF8 | kinsn_x86_reg_code(reg));
	kinsn_emit_s32(buf, &len, imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmpb_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 reg;
	s32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;
	if (imm < 0 || imm > 0xff)
		return -EINVAL;

	kinsn_emit_rex8_rm(buf, &len, reg);
	kinsn_emit_u8(buf, &len, 0x80);
	kinsn_emit_u8(buf, &len, 0xf8 | kinsn_x86_reg_code(reg));
	kinsn_emit_u8(buf, &len, (u8)imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmpw_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 reg;
	s32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;
	if (imm < 0 || imm > 0xffff)
		return -EINVAL;

	kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex_rr(buf, &len, false, 0, reg);
	kinsn_emit_u8(buf, &len, 0x81);
	kinsn_emit_u8(buf, &len, 0xf8 | kinsn_x86_reg_code(reg));
	kinsn_emit_u8(buf, &len, (u8)imm);
	kinsn_emit_u8(buf, &len, (u8)(imm >> 8));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmp_mem_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog, u8 size, bool is64)
{
	u8 buf[16];
	u8 base_reg;
	s16 offset;
	s32 imm;
	bool arch_mem;
	u32 len = 0;
	int err;

	err = decode_cmp_mem_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;
	if (size == BPF_B && (imm < 0 || imm > 0xff))
		return -EINVAL;
	if (size == BPF_H && (imm < 0 || imm > 0xffff))
		return -EINVAL;

	arch_mem = payload_form(payload) == X86_OPERAND_FORM_ARCH_MEM_IMM;
	if (!arch_mem)
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(base_reg))
		return -EINVAL;

	if (size == BPF_B) {
		kinsn_emit_rex8_mem(buf, &len, base_reg);
		kinsn_emit_u8(buf, &len, 0x80);
		kinsn_emit_modrm_mem_raw(buf, &len, 7, base_reg, offset);
		kinsn_emit_u8(buf, &len, (u8)imm);
		return kinsn_emit_finish(image, off, emit, buf, len);
	}

	if (size == BPF_H)
		kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex_rr(buf, &len, is64, 0, base_reg);
	if (imm >= -128 && imm <= 127) {
		kinsn_emit_u8(buf, &len, 0x83);
		kinsn_emit_modrm_mem_raw(buf, &len, 7, base_reg, offset);
		kinsn_emit_u8(buf, &len, (u8)imm);
	} else if (size == BPF_H) {
		kinsn_emit_u8(buf, &len, 0x81);
		kinsn_emit_modrm_mem_raw(buf, &len, 7, base_reg, offset);
		kinsn_emit_u8(buf, &len, (u8)imm);
		kinsn_emit_u8(buf, &len, (u8)(imm >> 8));
	} else {
		kinsn_emit_u8(buf, &len, 0x81);
		kinsn_emit_modrm_mem_raw(buf, &len, 7, base_reg, offset);
		kinsn_emit_s32(buf, &len, imm);
	}

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmpq_sib_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 base_reg, index_reg, scale_log2, rhs_reg;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_cmp_sib_rr_payload(payload, &base_reg, &index_reg,
					&scale_log2, &offset, &rhs_reg);
	if (err)
		return err;

	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	rhs_reg = kinsn_x86_reg_for_prog(prog, rhs_reg);
	if (!kinsn_x86_valid(base_reg) || !kinsn_x86_valid(index_reg) ||
	    !kinsn_x86_valid(rhs_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(rhs_reg),
		       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0x39);
	kinsn_emit_sib_mem(buf, &len, rhs_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmpq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return emit_cmp_rr_x86(image, off, emit, payload, prog, true);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return emit_cmp_imm_x86(image, off, emit, payload, prog, true);
	case X86_OPERAND_FORM_SIB_RR:
		return emit_cmpq_sib_rr_x86(image, off, emit, payload, prog);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return emit_cmp_mem_imm_x86(image, off, emit, payload, prog,
					    BPF_DW, true);
	default:
		return -EINVAL;
	}
}

static int emit_cmpb_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return emit_cmpb_rr_x86(image, off, emit, payload, prog);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return emit_cmpb_imm_x86(image, off, emit, payload, prog);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return emit_cmp_mem_imm_x86(image, off, emit, payload, prog,
					    BPF_B, false);
	default:
		return -EINVAL;
	}
}

static int emit_cmpl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return emit_cmp_rr_x86(image, off, emit, payload, prog, false);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return emit_cmp_imm_x86(image, off, emit, payload, prog, false);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return emit_cmp_mem_imm_x86(image, off, emit, payload, prog,
					    BPF_W, false);
	default:
		return -EINVAL;
	}
}

static int emit_cmpw_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return emit_cmpw_rr_x86(image, off, emit, payload, prog);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return emit_cmpw_imm_x86(image, off, emit, payload, prog);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return emit_cmp_mem_imm_x86(image, off, emit, payload, prog,
					    BPF_H, false);
	default:
		return -EINVAL;
	}
}

static int emit_test_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, bool is_byte, bool is64)
{
	u8 buf[4];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_test_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(left_reg) || !kinsn_x86_reg_valid(right_reg))
		return -EINVAL;

	if (is_byte)
		kinsn_emit_rex8_rr(buf, &len, right_reg, left_reg);
	else
		kinsn_emit_rex_rr(buf, &len, is64, right_reg, left_reg);
	kinsn_emit_u8(buf, &len, is_byte ? 0x84 : 0x85);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_testq_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	return emit_test_rr_x86(image, off, emit, payload, prog, false, true);
}

static int emit_testl_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	return emit_test_rr_x86(image, off, emit, payload, prog, false, false);
}

static int emit_testw_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	u8 buf[5];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_test_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(left_reg) || !kinsn_x86_reg_valid(right_reg))
		return -EINVAL;

	kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex_rr(buf, &len, false, right_reg, left_reg);
	kinsn_emit_u8(buf, &len, 0x85);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_testb_imm_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 reg, imm;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_testb_imm_payload(payload, &reg, &imm);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(reg))
		return -EINVAL;

	if (reg == BPF_REG_0) {
		kinsn_emit_u8(buf, &len, 0xa8);
		kinsn_emit_u8(buf, &len, imm);
	} else {
		kinsn_emit_rex8_rm(buf, &len, reg);
		kinsn_emit_u8(buf, &len, 0xf6);
		kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(reg));
		kinsn_emit_u8(buf, &len, imm);
	}

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_testb_mem_imm_x86(u8 *image, u32 *off, bool emit,
				  u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 base_reg, imm;
	s16 offset;
	bool arch_mem;
	u32 len = 0;
	int err;

	err = decode_test_mem_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;

	arch_mem = payload_form(payload) == X86_OPERAND_FORM_ARCH_MEM_IMM;
	if (!arch_mem)
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(base_reg))
		return -EINVAL;

	kinsn_emit_rex8_mem(buf, &len, base_reg);
	kinsn_emit_u8(buf, &len, 0xf6);
	kinsn_emit_modrm_mem_raw(buf, &len, 0, base_reg, offset);
	kinsn_emit_u8(buf, &len, imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_testb_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return emit_test_rr_x86(image, off, emit, payload, prog, true, false);
	case X86_OPERAND_FORM_IMM:
	case X86_OPERAND_FORM_ARCH_IMM:
		return emit_testb_imm_x86(image, off, emit, payload, prog);
	case X86_OPERAND_FORM_MEM_IMM:
	case X86_OPERAND_FORM_ARCH_MEM_IMM:
		return emit_testb_mem_imm_x86(image, off, emit, payload, prog);
	default:
		return -EINVAL;
	}
}

static int emit_testw_dispatch_x86(u8 *image, u32 *off, bool emit,
				   u64 payload, const struct bpf_prog *prog)
{
	switch (payload_form(payload)) {
	case X86_OPERAND_FORM_RR:
	case X86_OPERAND_FORM_ARCH_RR:
		return emit_testw_x86(image, off, emit, payload, prog);
	default:
		return -EINVAL;
	}
}

static int emit_cmov_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog, u8 cc,
			 bool is64)
{
	u8 buf[8];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_cmov_emit_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	kinsn_emit_rex_rr(buf, &len, is64, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0F);
	kinsn_emit_u8(buf, &len, cc);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmovneq_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x45, true);
}

static int emit_cmovnel_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x45, false);
}

static int emit_cmoveq_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x44, true);
}

static int emit_cmovel_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x44, false);
}

static int emit_cmovbl_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x42, false);
}

static int emit_cmovbq_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x42, true);
}

static int emit_setcc_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, u8 cc)
{
	u8 buf[4];
	u8 dst_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_setcc_emit_payload(payload, &dst_reg);
	if (err)
		return err;

	kinsn_emit_rex8_rm(buf, &len, dst_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, cc);
	kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_setne_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	return emit_setcc_x86(image, off, emit, payload, prog, 0x95);
}

static int emit_sete_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	return emit_setcc_x86(image, off, emit, payload, prog, 0x94);
}

static int emit_setge_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	return emit_setcc_x86(image, off, emit, payload, prog, 0x9d);
}

const struct bpf_kinsn bpf_x86_cmpq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 32 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_cmpq,
	.emit_x86 = emit_cmpq_x86,
};

const struct bpf_kinsn bpf_x86_cmpb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 32 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_cmpb,
	.emit_x86 = emit_cmpb_x86,
};

const struct bpf_kinsn bpf_x86_cmpl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 24 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmpl,
	.emit_x86 = emit_cmpl_x86,
};

const struct bpf_kinsn bpf_x86_cmpw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 32 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_cmpw,
	.emit_x86 = emit_cmpw_x86,
};

const struct bpf_kinsn bpf_x86_testq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testq,
	.emit_x86 = emit_testq_x86,
};

const struct bpf_kinsn bpf_x86_testl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testl,
	.emit_x86 = emit_testl_x86,
};

const struct bpf_kinsn bpf_x86_testb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_testb,
	.emit_x86 = emit_testb_x86,
};

const struct bpf_kinsn bpf_x86_testw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 5,
	.instantiate_insn = instantiate_testw,
	.emit_x86 = emit_testw_dispatch_x86,
};

const struct bpf_kinsn bpf_x86_cmovnel_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovnel,
	.emit_x86 = emit_cmovnel_x86,
};

const struct bpf_kinsn bpf_x86_cmovel_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovel,
	.emit_x86 = emit_cmovel_x86,
};

const struct bpf_kinsn bpf_x86_cmovneq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovneq,
	.emit_x86 = emit_cmovneq_x86,
};

const struct bpf_kinsn bpf_x86_cmoveq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmoveq,
	.emit_x86 = emit_cmoveq_x86,
};

const struct bpf_kinsn bpf_x86_cmovbl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovbl,
	.emit_x86 = emit_cmovbl_x86,
};

const struct bpf_kinsn bpf_x86_cmovbq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovbq,
	.emit_x86 = emit_cmovbq_x86,
};

const struct bpf_kinsn bpf_x86_setne_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_setne_r,
	.emit_x86 = emit_setne_r_x86,
};

const struct bpf_kinsn bpf_x86_sete_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_sete_r,
	.emit_x86 = emit_sete_r_x86,
};

const struct bpf_kinsn bpf_x86_setge_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_setge_r,
	.emit_x86 = emit_setge_r_x86,
};

static const struct bpf_kinsn * const bpf_x86_cmov_kinsn_descs[] = {
	&bpf_x86_cmovbl_desc,
	&bpf_x86_cmovbq_desc,
	&bpf_x86_cmovel_desc,
	&bpf_x86_cmoveq_desc,
	&bpf_x86_cmovnel_desc,
	&bpf_x86_cmovneq_desc,
	&bpf_x86_cmpb_desc,
	&bpf_x86_cmpl_desc,
	&bpf_x86_cmpq_desc,
	&bpf_x86_cmpw_desc,
	&bpf_x86_sete_desc,
	&bpf_x86_setge_desc,
	&bpf_x86_setne_desc,
	&bpf_x86_testb_desc,
	&bpf_x86_testl_desc,
	&bpf_x86_testq_desc,
	&bpf_x86_testw_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_cmov, "BpfReJIT x86 kinsns: CMP/TEST/SETcc/CMOV",
		       bpf_x86_cmov_kfunc_ids, bpf_x86_cmov_kinsn_descs);
