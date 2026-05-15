// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: CMP, TEST, SETcc, and CMOV.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_cmpq_rr(void) {}
__bpf_kfunc void bpf_x86_cmpl_rr(void) {}
__bpf_kfunc void bpf_x86_cmpq_imm32(void) {}
__bpf_kfunc void bpf_x86_cmpl_imm32(void) {}
__bpf_kfunc void bpf_x86_testq_rr(void) {}
__bpf_kfunc void bpf_x86_testl_rr(void) {}
__bpf_kfunc void bpf_x86_testb_rr(void) {}
__bpf_kfunc void bpf_x86_testb_imm(void) {}
__bpf_kfunc void bpf_x86_cmovnel_rr(void) {}
__bpf_kfunc void bpf_x86_cmovel_rr(void) {}
__bpf_kfunc void bpf_x86_cmovneq_rr(void) {}
__bpf_kfunc void bpf_x86_cmoveq_rr(void) {}
__bpf_kfunc void bpf_x86_cmovbl_rr(void) {}
__bpf_kfunc void bpf_x86_cmovbq_rr(void) {}
__bpf_kfunc void bpf_x86_sete_r(void) {}
__bpf_kfunc void bpf_x86_setge_r(void) {}
__bpf_kfunc void bpf_x86_setne_r(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_cmov_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_cmpl_imm32)
BTF_ID_FLAGS(func, bpf_x86_cmpl_rr)
BTF_ID_FLAGS(func, bpf_x86_cmpq_imm32)
BTF_ID_FLAGS(func, bpf_x86_cmpq_rr)
BTF_ID_FLAGS(func, bpf_x86_cmovbl_rr)
BTF_ID_FLAGS(func, bpf_x86_cmovbq_rr)
BTF_ID_FLAGS(func, bpf_x86_cmovel_rr)
BTF_ID_FLAGS(func, bpf_x86_cmoveq_rr)
BTF_ID_FLAGS(func, bpf_x86_cmovnel_rr)
BTF_ID_FLAGS(func, bpf_x86_cmovneq_rr)
BTF_ID_FLAGS(func, bpf_x86_sete_r)
BTF_ID_FLAGS(func, bpf_x86_setge_r)
BTF_ID_FLAGS(func, bpf_x86_setne_r)
BTF_ID_FLAGS(func, bpf_x86_testb_imm)
BTF_ID_FLAGS(func, bpf_x86_testb_rr)
BTF_ID_FLAGS(func, bpf_x86_testl_rr)
BTF_ID_FLAGS(func, bpf_x86_testq_rr)
BTF_KFUNCS_END(bpf_x86_cmov_kfunc_ids)

enum x86_flag_proof_kind {
	X86_FLAG_PROOF_CMP_RR64 = 1,
	X86_FLAG_PROOF_CMP_IMM64 = 2,
	X86_FLAG_PROOF_CMP_RR32 = 3,
	X86_FLAG_PROOF_CMP_IMM32 = 4,
};

static __always_inline bool x86_flag_proof_kind_valid(u8 kind)
{
	return kind >= X86_FLAG_PROOF_CMP_RR64 &&
	       kind <= X86_FLAG_PROOF_CMP_IMM32;
}

static __always_inline bool x86_flag_proof_kind_rr(u8 kind)
{
	return kind == X86_FLAG_PROOF_CMP_RR64 ||
	       kind == X86_FLAG_PROOF_CMP_RR32;
}

static __always_inline bool x86_flag_proof_kind_32(u8 kind)
{
	return kind == X86_FLAG_PROOF_CMP_RR32 ||
	       kind == X86_FLAG_PROOF_CMP_IMM32;
}

static __always_inline bool bpf_reg_ok(u8 reg)
{
	return reg <= BPF_REG_10 && kinsn_x86_reg_valid(reg);
}

static __always_inline bool bpf_gpr_ok(u8 reg)
{
	return reg < BPF_REG_10 && kinsn_x86_reg_valid(reg);
}

static __always_inline int decode_cmp_rr_payload(u64 payload, u8 *left_reg,
						 u8 *right_reg)
{
	*left_reg = kinsn_payload_reg(payload, 0);
	*right_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!bpf_reg_ok(*left_reg) || !bpf_reg_ok(*right_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmp_imm_payload(u64 payload, u8 *reg,
						  s32 *imm)
{
	*reg = kinsn_payload_reg(payload, 0);
	*imm = kinsn_payload_s32(payload, 8);

	if (payload >> 40)
		return -EINVAL;
	if (payload & (0xfULL << 4))
		return -EINVAL;
	if (!bpf_reg_ok(*reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_test_payload(u64 payload, u8 *reg)
{
	*reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*reg > BPF_REG_10 || !kinsn_x86_reg_valid(*reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_test_rr_payload(u64 payload,
						  u8 *left_reg,
						  u8 *right_reg)
{
	*left_reg = kinsn_payload_reg(payload, 0);
	*right_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*left_reg > BPF_REG_10 || *right_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*left_reg) || !kinsn_x86_reg_valid(*right_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_testb_imm_payload(u64 payload,
						    u8 *reg,
						    u8 *imm)
{
	*reg = kinsn_payload_reg(payload, 0);
	*imm = kinsn_payload_u8(payload, 8);

	if (payload >> 16)
		return -EINVAL;
	if (payload & (0xfULL << 4))
		return -EINVAL;
	if (*reg > BPF_REG_10 || !kinsn_x86_reg_valid(*reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmov_payload(u64 payload,
					       u8 *dst_reg,
					       u8 *src_reg,
					       u8 *cond_reg)
{
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
	if (!x86_flag_proof_kind_valid(kind))
		return -EINVAL;
	if (!bpf_reg_ok(kinsn_payload_reg(payload, 8)))
		return -EINVAL;
	if (x86_flag_proof_kind_rr(kind) &&
	    !bpf_reg_ok(kinsn_payload_reg(payload, 16)))
		return -EINVAL;
	if (!x86_flag_proof_kind_rr(kind) && (payload >> 48))
		return -EINVAL;
	if (x86_flag_proof_kind_rr(kind) && (payload >> 20))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_setcc_payload(u64 payload,
						u8 *dst_reg,
						u8 *cond_reg,
						u8 *tmp_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*cond_reg = kinsn_payload_reg(payload, 4);
	*tmp_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *cond_reg >= BPF_REG_10 ||
	    *tmp_reg >= BPF_REG_10)
		return -EINVAL;
	if (*dst_reg == *cond_reg)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *cond_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*cond_reg) ||
	    !kinsn_x86_reg_valid(*tmp_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_setcc_emit_payload(u64 payload, u8 *dst_reg)
{
	u8 kind = kinsn_payload_reg(payload, 16);

	*dst_reg = kinsn_payload_reg(payload, 0);
	if (!bpf_gpr_ok(*dst_reg))
		return -EINVAL;
	if (!kind) {
		u8 cond_reg = kinsn_payload_reg(payload, 4);
		u8 tmp_reg = kinsn_payload_reg(payload, 8);

		if (payload >> 12)
			return -EINVAL;
		if (!bpf_gpr_ok(cond_reg) || !bpf_gpr_ok(tmp_reg))
			return -EINVAL;
		return 0;
	}
	if (!x86_flag_proof_kind_valid(kind))
		return -EINVAL;
	if (!bpf_gpr_ok(kinsn_payload_reg(payload, 4)) ||
	    !bpf_gpr_ok(kinsn_payload_reg(payload, 8)) ||
	    !bpf_gpr_ok(kinsn_payload_reg(payload, 12)))
		return -EINVAL;
	if (x86_flag_proof_kind_rr(kind) &&
	    !bpf_gpr_ok(kinsn_payload_reg(payload, 20)))
		return -EINVAL;
	if (!x86_flag_proof_kind_rr(kind) && (payload >> 52))
		return -EINVAL;
	if (x86_flag_proof_kind_rr(kind) && (payload >> 24))
		return -EINVAL;

	return 0;
}

static int instantiate_cmp_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 left_reg, right_reg;
	int err;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_cmp_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	s32 imm;
	int err;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_testq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	int err;

	err = decode_test_payload(payload, &reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_test_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 left_reg, right_reg;
	int err;

	err = decode_test_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_testb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg, imm;
	int err;

	err = decode_testb_imm_payload(payload, &reg, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_testb_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_test_rr(payload, insn_buf);
}

static int instantiate_testl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_test_rr(payload, insn_buf);
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

static int instantiate_cmov_cmp(u64 payload, struct bpf_insn *insn_buf,
				bool move_on_eq, bool is64)
{
	u8 dst_reg = kinsn_payload_reg(payload, 0);
	u8 src_reg = kinsn_payload_reg(payload, 4);
	u8 left_reg = kinsn_payload_reg(payload, 8);
	u8 kind = kinsn_payload_reg(payload, 12);
	int skip_op = move_on_eq ? BPF_JNE : BPF_JEQ;
	int err;

	err = decode_cmov_emit_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (x86_flag_proof_kind_rr(kind)) {
		u8 right_reg = kinsn_payload_reg(payload, 16);

		insn_buf[0] = x86_flag_proof_kind_32(kind) ?
			      BPF_JMP32_REG(skip_op, left_reg, right_reg, 1) :
			      BPF_JMP_REG(skip_op, left_reg, right_reg, 1);
	} else {
		s32 imm = kinsn_payload_s32(payload, 16);

		insn_buf[0] = x86_flag_proof_kind_32(kind) ?
			      BPF_JMP32_IMM(skip_op, left_reg, imm, 1) :
			      BPF_JMP_IMM(skip_op, left_reg, imm, 1);
	}
	insn_buf[1] = is64 ? BPF_MOV64_REG(dst_reg, src_reg) :
			      BPF_MOV32_REG(dst_reg, src_reg);
	return 2;
}

static int instantiate_cmov_eqne(u64 payload, struct bpf_insn *insn_buf,
				 bool move_on_eq, bool is64)
{
	if (kinsn_payload_reg(payload, 12))
		return instantiate_cmov_cmp(payload, insn_buf, move_on_eq, is64);
	return instantiate_cmov(payload, insn_buf, move_on_eq);
}

static int instantiate_cmovnel_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, false, false);
}

static int instantiate_cmovel_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, true, false);
}

static int instantiate_cmovneq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, false, true);
}

static int instantiate_cmoveq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_eqne(payload, insn_buf, true, true);
}

static int instantiate_cmovbl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_nonzero(payload, insn_buf, false);
}

static int instantiate_cmovbq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov_nonzero(payload, insn_buf, true);
}

static int instantiate_setcc(u64 payload, struct bpf_insn *insn_buf, u8 op)
{
	u8 dst_reg, cond_reg, tmp_reg;
	int cnt = 0;
	int err;

	err = decode_setcc_payload(payload, &dst_reg, &cond_reg, &tmp_reg);
	if (err)
		return err;

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, tmp_reg, -256);
	insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 0);
	insn_buf[cnt++] = BPF_JMP_IMM(op, cond_reg, 0, 1);
	insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	return cnt;
}

static int instantiate_setcc_cmp(u64 payload, struct bpf_insn *insn_buf, u8 op)
{
	u8 dst_reg = kinsn_payload_reg(payload, 0);
	u8 left_reg = kinsn_payload_reg(payload, 4);
	u8 tmp_high_reg = kinsn_payload_reg(payload, 8);
	u8 tmp_cmp_reg = kinsn_payload_reg(payload, 12);
	u8 kind = kinsn_payload_reg(payload, 16);
	int cnt = 0;

	if (decode_setcc_emit_payload(payload, &dst_reg))
		return -EINVAL;
	if (tmp_high_reg == dst_reg || tmp_cmp_reg == dst_reg ||
	    tmp_high_reg == tmp_cmp_reg)
		return -EINVAL;

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_cmp_reg, left_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(tmp_high_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, tmp_high_reg, -256);
	insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 0);

	if (x86_flag_proof_kind_rr(kind)) {
		u8 right_reg = kinsn_payload_reg(payload, 20);

		if (right_reg == dst_reg || tmp_high_reg == right_reg ||
		    tmp_cmp_reg == right_reg)
			return -EINVAL;
		insn_buf[cnt++] = x86_flag_proof_kind_32(kind) ?
				  BPF_JMP32_REG(op, tmp_cmp_reg, right_reg, 1) :
				  BPF_JMP_REG(op, tmp_cmp_reg, right_reg, 1);
	} else {
		s32 imm = kinsn_payload_s32(payload, 20);

		insn_buf[cnt++] = x86_flag_proof_kind_32(kind) ?
				  BPF_JMP32_IMM(op, tmp_cmp_reg, imm, 1) :
				  BPF_JMP_IMM(op, tmp_cmp_reg, imm, 1);
	}

	insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_high_reg);
	return cnt;
}

static int instantiate_setcc_dispatch(u64 payload, struct bpf_insn *insn_buf,
				      u8 op)
{
	if (kinsn_payload_reg(payload, 16))
		return instantiate_setcc_cmp(payload, insn_buf, op);
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

static void emit_rex8_rr(u8 *buf, u32 *len, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (kinsn_x86_reg_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_reg_ext(rm))
		rex |= 0x01;
	if (rex != 0x40 || kinsn_x86_needs_rex8(reg) ||
	    kinsn_x86_needs_rex8(rm))
		emit_u8(buf, len, rex);
}

static void emit_rex8_r(u8 *buf, u32 *len, u8 rm)
{
	u8 rex = 0x40;

	if (kinsn_x86_reg_ext(rm))
		rex |= 0x01;
	if (rex != 0x40 || kinsn_x86_needs_rex8(rm))
		emit_u8(buf, len, rex);
}

static int emit_testq_rr_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_test_payload(payload, &reg);
	if (err)
		return err;

	emit_rex_rr(buf, &len, true, reg, reg);
	emit_u8(buf, &len, 0x85);
	emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(reg) << 3) |
		kinsn_x86_reg_code(reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_cmp_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog, bool is64)
{
	u8 buf[4];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_cmp_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;

	emit_rex_rr(buf, &len, is64, right_reg, left_reg);
	emit_u8(buf, &len, 0x39);
	emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
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

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_cmp_imm_payload(payload, &reg, &imm);
	if (err)
		return err;

	emit_rex_rr(buf, &len, is64, 0, reg);
	emit_u8(buf, &len, 0x81);
	emit_u8(buf, &len, 0xF8 | kinsn_x86_reg_code(reg));
	kinsn_emit_s32(buf, &len, imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_cmpq_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	return emit_cmp_rr_x86(image, off, emit, payload, prog, true);
}

static int emit_cmpl_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	return emit_cmp_rr_x86(image, off, emit, payload, prog, false);
}

static int emit_cmpq_imm32_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_cmp_imm_x86(image, off, emit, payload, prog, true);
}

static int emit_cmpl_imm32_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_cmp_imm_x86(image, off, emit, payload, prog, false);
}

static int emit_test_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, bool is_byte)
{
	u8 buf[4];
	u8 left_reg, right_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_test_rr_payload(payload, &left_reg, &right_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(left_reg) || !kinsn_x86_reg_valid(right_reg))
		return -EINVAL;

	if (is_byte)
		emit_rex8_rr(buf, &len, right_reg, left_reg);
	else
		emit_rex_rr(buf, &len, false, right_reg, left_reg);
	emit_u8(buf, &len, is_byte ? 0x84 : 0x85);
	emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_testb_rr_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	return emit_test_rr_x86(image, off, emit, payload, prog, true);
}

static int emit_testl_rr_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	return emit_test_rr_x86(image, off, emit, payload, prog, false);
}

static int emit_testb_imm_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 reg, imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_testb_imm_payload(payload, &reg, &imm);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(reg))
		return -EINVAL;

	if (reg == BPF_REG_0) {
		emit_u8(buf, &len, 0xa8);
		emit_u8(buf, &len, imm);
	} else {
		emit_rex8_r(buf, &len, reg);
		emit_u8(buf, &len, 0xf6);
		emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(reg));
		emit_u8(buf, &len, imm);
	}

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
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

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_cmov_emit_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	emit_rex_rr(buf, &len, is64, dst_reg, src_reg);
	emit_u8(buf, &len, 0x0F);
	emit_u8(buf, &len, cc);
	emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_cmovneq_rr_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x45, true);
}

static int emit_cmovnel_rr_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x45, false);
}

static int emit_cmoveq_rr_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x44, true);
}

static int emit_cmovel_rr_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x44, false);
}

static int emit_cmovbl_rr_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x42, false);
}

static int emit_cmovbq_rr_x86(u8 *image, u32 *off, bool emit,
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

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_setcc_emit_payload(payload, &dst_reg);
	if (err)
		return err;

	emit_rex8_r(buf, &len, dst_reg);
	emit_u8(buf, &len, 0x0f);
	emit_u8(buf, &len, cc);
	emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(dst_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
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

const struct bpf_kinsn bpf_x86_cmpq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_cmp_rr,
	.emit_x86 = emit_cmpq_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmpl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_cmp_rr,
	.emit_x86 = emit_cmpl_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmpq_imm32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 7,
	.instantiate_insn = instantiate_cmp_imm,
	.emit_x86 = emit_cmpq_imm32_x86,
};

const struct bpf_kinsn bpf_x86_cmpl_imm32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_cmp_imm,
	.emit_x86 = emit_cmpl_imm32_x86,
};

const struct bpf_kinsn bpf_x86_testq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testq_rr,
	.emit_x86 = emit_testq_rr_x86,
};

const struct bpf_kinsn bpf_x86_testb_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testb_imm,
	.emit_x86 = emit_testb_imm_x86,
};

const struct bpf_kinsn bpf_x86_testb_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testb_rr,
	.emit_x86 = emit_testb_rr_x86,
};

const struct bpf_kinsn bpf_x86_testl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testl_rr,
	.emit_x86 = emit_testl_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmovnel_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovnel_rr,
	.emit_x86 = emit_cmovnel_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmovel_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovel_rr,
	.emit_x86 = emit_cmovel_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmovneq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovneq_rr,
	.emit_x86 = emit_cmovneq_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmoveq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmoveq_rr,
	.emit_x86 = emit_cmoveq_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmovbl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovbl_rr,
	.emit_x86 = emit_cmovbl_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmovbq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovbq_rr,
	.emit_x86 = emit_cmovbq_rr_x86,
};

const struct bpf_kinsn bpf_x86_setne_r_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 7,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_setne_r,
	.emit_x86 = emit_setne_r_x86,
};

const struct bpf_kinsn bpf_x86_sete_r_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 7,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_sete_r,
	.emit_x86 = emit_sete_r_x86,
};

const struct bpf_kinsn bpf_x86_setge_r_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 7,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_setge_r,
	.emit_x86 = emit_setge_r_x86,
};

static const struct bpf_kinsn * const bpf_x86_cmov_kinsn_descs[] = {
	&bpf_x86_cmpl_imm32_desc,
	&bpf_x86_cmpl_rr_desc,
	&bpf_x86_cmpq_imm32_desc,
	&bpf_x86_cmpq_rr_desc,
	&bpf_x86_cmovbl_rr_desc,
	&bpf_x86_cmovbq_rr_desc,
	&bpf_x86_cmovel_rr_desc,
	&bpf_x86_cmoveq_rr_desc,
	&bpf_x86_cmovnel_rr_desc,
	&bpf_x86_cmovneq_rr_desc,
	&bpf_x86_sete_r_desc,
	&bpf_x86_setge_r_desc,
	&bpf_x86_setne_r_desc,
	&bpf_x86_testb_imm_desc,
	&bpf_x86_testb_rr_desc,
	&bpf_x86_testl_rr_desc,
	&bpf_x86_testq_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_cmov, "BpfReJIT x86 kinsns: CMP/TEST/SETcc/CMOV",
		       bpf_x86_cmov_kfunc_ids, bpf_x86_cmov_kinsn_descs);
