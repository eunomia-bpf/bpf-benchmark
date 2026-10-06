// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 koperation: MOV-family instructions.
 *
 * Public kfunc names identify the x86 instruction only.  Operand encoding
 * variants (rr, mem, sib, store, imm-store) live in the payload form tag.
 */

#include "kop_x86_emit.h"

#define X86_FORM_RR		1
#define X86_FORM_IMM		2
#define X86_FORM_SIB_RR		3
#define X86_FORM_MEM		4
#define X86_FORM_SIB		5
#define X86_FORM_STORE		6
#define X86_FORM_STORE_IMM	7
#define X86_FORM_ARCH_MEM	9
#define X86_FORM_ARCH_STORE	10
#define X86_FORM_ARCH_STORE_IMM	11
#define X86_FORM_ARCH_RR	12
#define X86_FORM_ARCH_IMM	13
#define X86_FORM_ARCH_SIB	14
#define X86_FORM_ARCH_TO_BPF_RR	15
#define X86_FORM_BPF_TO_ARCH_RR	X86_FORM_SIB_RR

struct mov_rr_payload {
	u8 dst_reg;
	u8 src_reg;
	bool dst_arch;
	bool src_arch;
	bool dst_raw_bpf;
	bool src_raw_bpf;
};

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movb(void) {}
__bpf_kfunc void bpf_x86_movw(void) {}
__bpf_kfunc void bpf_x86_movl(void) {}
__bpf_kfunc void bpf_x86_movq(void) {}
__bpf_kfunc void bpf_x86_movzbl(void) {}
__bpf_kfunc void bpf_x86_movzwl(void) {}
__bpf_kfunc void bpf_x86_movswl(void) {}
__bpf_kfunc void bpf_x86_movsxd(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movb)
BTF_ID_FLAGS(func, bpf_x86_movl)
BTF_ID_FLAGS(func, bpf_x86_movq)
BTF_ID_FLAGS(func, bpf_x86_movswl)
BTF_ID_FLAGS(func, bpf_x86_movsxd)
BTF_ID_FLAGS(func, bpf_x86_movw)
BTF_ID_FLAGS(func, bpf_x86_movzbl)
BTF_ID_FLAGS(func, bpf_x86_movzwl)
BTF_KFUNCS_END(bpf_x86_mov_kfunc_ids)

static __always_inline u8 mov_payload_form(u64 decoded)
{
	return decoded & 0xf;
}

static __always_inline bool mov_form_dst_arch(u8 form)
{
	return form == X86_FORM_ARCH_RR ||
	       form == X86_FORM_BPF_TO_ARCH_RR ||
	       form == X86_FORM_ARCH_IMM;
}

static __always_inline bool mov_form_src_arch(u8 form)
{
	return form == X86_FORM_ARCH_RR || form == X86_FORM_ARCH_TO_BPF_RR;
}

static __always_inline bool mov_form_dst_raw_bpf(u8 form)
{
	return form == X86_FORM_ARCH_TO_BPF_RR;
}

static __always_inline bool mov_form_src_raw_bpf(u8 form)
{
	return form == X86_FORM_BPF_TO_ARCH_RR;
}

static __always_inline int decode_rr_any(u64 payload,
					 struct mov_rr_payload *rr)
{
	u8 form;

	payload = kop_payload_decode(payload);
	form = mov_payload_form(payload);
	if ((form != X86_FORM_RR &&
	     form != X86_FORM_ARCH_RR &&
	     form != X86_FORM_ARCH_TO_BPF_RR &&
	     form != X86_FORM_BPF_TO_ARCH_RR) ||
	    payload >> 12)
		return -EINVAL;

	rr->dst_reg = kop_payload_reg(payload, 4);
	rr->src_reg = kop_payload_reg(payload, 8);
	rr->dst_arch = mov_form_dst_arch(form);
	rr->src_arch = mov_form_src_arch(form);
	rr->dst_raw_bpf = mov_form_dst_raw_bpf(form);
	rr->src_raw_bpf = mov_form_src_raw_bpf(form);
	if (!kop_x86_operand_valid(rr->dst_reg) ||
	    !kop_x86_operand_valid(rr->src_reg))
		return -EINVAL;
	if ((rr->dst_raw_bpf && rr->dst_reg >= BPF_REG_10) ||
	    (rr->src_raw_bpf && rr->src_reg >= BPF_REG_10))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_mem(u64 payload, u8 expected_form,
				      u8 *reg, u8 *base_reg, s16 *offset)
{
	payload = kop_payload_decode(payload);
	if (mov_payload_form(payload) != expected_form || payload >> 28)
		return -EINVAL;

	*reg = kop_payload_reg(payload, 4);
	*base_reg = kop_payload_reg(payload, 8);
	*offset = kop_payload_s16(payload, 12);
	if (!kop_x86_operand_valid(*reg) ||
	    !kop_x86_operand_valid(*base_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store(u64 payload, u8 expected_form,
					u8 *src_reg, u8 *base_reg,
					s16 *offset, u8 *byte_lane)
{
	payload = kop_payload_decode(payload);
	if (mov_payload_form(payload) != expected_form || payload >> 30)
		return -EINVAL;

	*src_reg = kop_payload_reg(payload, 4);
	*base_reg = kop_payload_reg(payload, 8);
	*offset = kop_payload_s16(payload, 12);
	*byte_lane = (payload >> 28) & 0x3;
	if (!kop_x86_operand_valid(*src_reg) ||
	    !kop_x86_operand_valid(*base_reg) ||
	    *byte_lane > 1)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_imm_any(u64 payload, u8 *dst_reg,
					  s32 *imm, bool *arch_reg)
{
	payload = kop_payload_decode(payload);
	*arch_reg = mov_payload_form(payload) == X86_FORM_ARCH_IMM;
	if ((mov_payload_form(payload) != X86_FORM_IMM &&
	     mov_payload_form(payload) != X86_FORM_ARCH_IMM) ||
	    payload >> 40)
		return -EINVAL;

	*dst_reg = kop_payload_reg(payload, 4);
	*imm = kop_payload_s32(payload, 8);
	if (!kop_x86_operand_valid(*dst_reg))
		return -EINVAL;
	return 0;
}

static __always_inline int decode_sib(u64 payload, u8 *dst_reg, u8 *base_reg,
				      u8 *index_reg, u8 *scale_log2,
				      s16 *offset, bool allow_stack_dst)
{
	u8 form;

	(void)allow_stack_dst;
	payload = kop_payload_decode(payload);
	form = mov_payload_form(payload);
	if ((form != X86_FORM_SIB && form != X86_FORM_ARCH_SIB) ||
	    payload >> 36)
		return -EINVAL;

	*dst_reg = kop_payload_reg(payload, 4);
	*base_reg = kop_payload_reg(payload, 8);
	*index_reg = kop_payload_reg(payload, 12);
	*scale_log2 = (payload >> 16) & 0x3;
	*offset = kop_payload_s16(payload, 20);
	if (payload & (0x3ULL << 18))
		return -EINVAL;
	if (!kop_x86_operand_valid(*dst_reg) ||
	    !kop_x86_operand_valid(*base_reg) ||
	    !kop_x86_operand_valid(*index_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store_imm(u64 payload, u8 expected_form,
					    u8 *base_reg, s16 *offset,
					    s32 *imm)
{
	payload = kop_payload_decode(payload);
	if (mov_payload_form(payload) != expected_form || payload >> 56)
		return -EINVAL;

	*base_reg = kop_payload_reg(payload, 4);
	*offset = kop_payload_s16(payload, 8);
	*imm = kop_payload_s32(payload, 24);
	if (!kop_x86_operand_valid(*base_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_movq_reg(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;
	insn_buf[0] = BPF_MOV64_REG(rr.dst_reg, rr.src_reg);
	return 1;
}

static int instantiate_movl_reg(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;
	insn_buf[0] = BPF_MOV32_REG(rr.dst_reg, rr.src_reg);
	return 1;
}

static int instantiate_mov_imm(u64 payload, struct bpf_insn *insn_buf, bool is64)
{
	u8 dst_reg;
	s32 imm;
	bool arch_reg;
	int err;

	err = decode_imm_any(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	insn_buf[0] = is64 ? BPF_MOV64_IMM(dst_reg, imm) : BPF_MOV32_IMM(dst_reg, imm);
	return 1;
}

static int instantiate_movb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	s32 imm;
	bool arch_reg;
	int err;

	err = decode_imm_any(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	if (!kop_x86_reg_is_bpf_writable(dst_reg) || imm < 0 || imm > 0xff)
		return -EINVAL;
	insn_buf[0] = BPF_ALU64_IMM(BPF_AND, dst_reg, -256);
	insn_buf[1] = BPF_ALU64_IMM(BPF_OR, dst_reg, imm);
	return 2;
}

static int instantiate_movzx_rr(u64 payload, struct bpf_insn *insn_buf, u32 mask)
{
	struct mov_rr_payload rr;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV32_REG(rr.dst_reg, rr.src_reg);
	insn_buf[1] = BPF_ALU32_IMM(BPF_AND, rr.dst_reg, mask);
	return 2;
}

static int instantiate_movswl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV32_REG(rr.dst_reg, rr.src_reg);
	insn_buf[1] = BPF_ALU32_IMM(BPF_LSH, rr.dst_reg, 16);
	insn_buf[2] = BPF_ALU32_IMM(BPF_ARSH, rr.dst_reg, 16);
	return 3;
}

static int instantiate_mov_mem(u64 payload, struct bpf_insn *insn_buf, u8 size,
			       bool arch_base)
{
	u8 dst_reg, base_reg;
	s16 offset;
	int err;

	err = decode_mem(payload, arch_base ? X86_FORM_ARCH_MEM : X86_FORM_MEM,
			 &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
	return 1;
}

/* A replacing load may use its own destination for the effective address.
 * Read every aliased source before overwriting it, without scratch spills.
 */
static int instantiate_mov_address(u8 dst_reg, u8 base_reg, u8 index_reg,
				   u8 scale_log2, struct bpf_insn *insn_buf)
{
	int cnt = 0;
	int i;

	if (dst_reg == base_reg && dst_reg == index_reg) {
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MUL, dst_reg,
						 1 + (1U << scale_log2));
	} else if (dst_reg == base_reg) {
		for (i = 0; i < (1U << scale_log2); i++)
			insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, index_reg);
	} else {
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, index_reg);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MUL, dst_reg,
						 1U << scale_log2);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, base_reg);
	}
	return cnt;
}

static int instantiate_mov_sib(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	int cnt;
	int err;

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg,
			 &scale_log2, &offset, true);
	if (err)
		return err;

	cnt = instantiate_mov_address(dst_reg, base_reg, index_reg,
				      scale_log2, insn_buf);
	insn_buf[cnt++] = BPF_LDX_MEM(size, dst_reg, dst_reg, offset);
	return cnt;
}

static int mov_store_temp(u8 src_reg, u8 base_reg)
{
	u8 reg;

	for (reg = BPF_REG_0; reg < BPF_REG_10; reg++) {
		if (reg != src_reg && reg != base_reg)
			return reg;
	}
	return -EINVAL;
}

static int instantiate_store_reg(u64 payload, struct bpf_insn *insn_buf,
				 u8 size, bool arch_base)
{
	u8 src_reg, base_reg, byte_lane;
	s16 offset;
	int temp;
	int err;

	err = decode_store(payload,
			   arch_base ? X86_FORM_ARCH_STORE : X86_FORM_STORE,
			   &src_reg, &base_reg, &offset, &byte_lane);
	if (err)
		return err;
	if (byte_lane && size != BPF_B)
		return -EINVAL;
	if (!byte_lane) {
		insn_buf[0] = BPF_STX_MEM(size, base_reg, src_reg, offset);
		return 1;
	}
	temp = mov_store_temp(src_reg, base_reg);
	if (temp < 0)
		return temp;
	insn_buf[0] = BPF_STX_MEM(BPF_DW, BPF_REG_10, temp, KOP_X86_PROOF_RHS_OFF);
	insn_buf[1] = BPF_MOV64_REG(temp, src_reg);
	insn_buf[2] = BPF_ALU64_IMM(BPF_RSH, temp, 8);
	insn_buf[3] = BPF_STX_MEM(BPF_B, base_reg, temp, offset);
	insn_buf[4] = BPF_LDX_MEM(BPF_DW, temp, BPF_REG_10, KOP_X86_PROOF_RHS_OFF);
	return 5;
}

static int instantiate_mov_imm_store(u64 payload, struct bpf_insn *insn_buf,
				     u8 size, bool arch_base)
{
	u8 base_reg;
	s16 offset;
	s32 imm;
	int err;

	err = decode_store_imm(payload,
			       arch_base ? X86_FORM_ARCH_STORE_IMM :
					   X86_FORM_STORE_IMM,
			       &base_reg, &offset, &imm);
	if (err)
		return err;
	if (size == BPF_B && (imm < 0 || imm > 0xff))
		return -EINVAL;
	if (size == BPF_H && (imm < -32768 || imm > 0xffff))
		return -EINVAL;

	insn_buf[0] = BPF_ST_MEM(size, base_reg, offset, imm);
	return 1;
}

static int instantiate_movb(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_IMM:
	case X86_FORM_ARCH_IMM:
		return instantiate_movb_imm(payload, insn_buf);
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_B, false);
	case X86_FORM_ARCH_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_B, true);
	case X86_FORM_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_B, false);
	case X86_FORM_ARCH_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_B, true);
	default:
		return -EINVAL;
	}
}

static int instantiate_movw(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_H, false);
	case X86_FORM_ARCH_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_H, true);
	case X86_FORM_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_H, false);
	case X86_FORM_ARCH_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_H, true);
	default:
		return -EINVAL;
	}
}

static int instantiate_movl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return instantiate_movl_reg(payload, insn_buf);
	case X86_FORM_IMM:
	case X86_FORM_ARCH_IMM:
		return instantiate_mov_imm(payload, insn_buf, false);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_W, false);
	case X86_FORM_ARCH_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_W, true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_W);
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_W, false);
	case X86_FORM_ARCH_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_W, true);
	case X86_FORM_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_W, false);
	case X86_FORM_ARCH_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_W, true);
	default:
		return -EINVAL;
	}
}

static int instantiate_movq(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return instantiate_movq_reg(payload, insn_buf);
	case X86_FORM_IMM:
	case X86_FORM_ARCH_IMM:
		return instantiate_mov_imm(payload, insn_buf, true);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_DW, false);
	case X86_FORM_ARCH_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_DW, true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_DW);
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_DW, false);
	case X86_FORM_ARCH_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_DW, true);
	case X86_FORM_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_DW, false);
	case X86_FORM_ARCH_STORE_IMM:
		return instantiate_mov_imm_store(payload, insn_buf, BPF_DW, true);
	default:
		return -EINVAL;
	}
}

static int instantiate_movzbl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return instantiate_movzx_rr(payload, insn_buf, 0xff);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_B, false);
	case X86_FORM_ARCH_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_B, true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_B);
	default:
		return -EINVAL;
	}
}

static int instantiate_movzwl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return instantiate_movzx_rr(payload, insn_buf, 0xffff);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_H, false);
	case X86_FORM_ARCH_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_H, true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_H);
	default:
		return -EINVAL;
	}
}

static int instantiate_movsxd(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	u8 dst_reg;
	u8 form = mov_payload_form(kop_payload_decode(payload));
	int cnt;
	int err;

	if (form == X86_FORM_RR || form == X86_FORM_ARCH_RR) {
		err = decode_rr_any(payload, &rr);
		if (err)
			return err;
		dst_reg = rr.dst_reg;
		insn_buf[0] = BPF_MOV64_REG(dst_reg, rr.src_reg);
		cnt = 1;
	} else {
		cnt = instantiate_mov_sib(payload, insn_buf, BPF_W);
		if (cnt < 0)
			return cnt;
		dst_reg = kop_payload_reg(kop_payload_decode(payload), 4);
	}

	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, 32);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ARSH, dst_reg, 32);
	return cnt;
}

static int emit_mov_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog, bool is64)
{
	struct mov_rr_payload rr;
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	dst_reg = rr.dst_arch ? rr.dst_reg :
			 kop_x86_reg_for_prog(prog, rr.dst_reg);
	src_reg = rr.src_arch ? rr.src_reg :
			 kop_x86_reg_for_prog(prog, rr.src_reg);
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(src_reg))
		return -EINVAL;

	kop_emit_rex_rr(buf, &len, is64, src_reg, dst_reg);
	kop_emit_u8(buf, &len, 0x89);
	kop_emit_u8(buf, &len, 0xC0 |
		      (kop_x86_code(src_reg) << 3) |
		      kop_x86_code(dst_reg));

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_mov_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, bool is64)
{
	u8 buf[8];
	u8 dst_reg;
	s32 imm;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_imm_any(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;

	if (!arch_reg)
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
	if (!kop_x86_valid(dst_reg))
		return -EINVAL;

	if (!is64) {
		kop_emit_rex_rr(buf, &len, false, 0, dst_reg);
		kop_emit_u8(buf, &len, 0xb8 | kop_x86_code(dst_reg));
		kop_emit_s32(buf, &len, imm);
	} else {
		kop_emit_rex_rr(buf, &len, true, 0, dst_reg);
		kop_emit_u8(buf, &len, 0xc7);
		kop_emit_u8(buf, &len, 0xc0 | kop_x86_code(dst_reg));
		kop_emit_s32(buf, &len, imm);
	}

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_movzx_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog, u8 opcode,
			     bool src_is_byte)
{
	struct mov_rr_payload rr;
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	dst_reg = rr.dst_arch ? rr.dst_reg :
			 kop_x86_reg_for_prog(prog, rr.dst_reg);
	src_reg = rr.src_arch ? rr.src_reg :
			 kop_x86_reg_for_prog(prog, rr.src_reg);
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(src_reg))
		return -EINVAL;

	if (src_is_byte)
		kop_emit_rex8(buf, &len, dst_reg, src_reg, true, false, true);
	else
		kop_emit_rex_rr(buf, &len, false, dst_reg, src_reg);
	kop_emit_u8(buf, &len, 0x0f);
	kop_emit_u8(buf, &len, opcode);
	kop_emit_u8(buf, &len, 0xC0 |
		      (kop_x86_code(dst_reg) << 3) |
		      kop_x86_code(src_reg));

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_mov_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, u8 size,
			    bool arch_base)
{
	u8 buf[16];
	u8 dst_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_mem(payload, arch_base ? X86_FORM_ARCH_MEM : X86_FORM_MEM,
			 &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	if (!arch_base) {
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
		base_reg = kop_x86_reg_for_prog(prog, base_reg);
	}
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(base_reg))
		return -EINVAL;

	switch (size) {
	case BPF_B:
		kop_emit_rex(buf, &len, false, kop_x86_ext(dst_reg),
			       false, kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x0f);
		kop_emit_u8(buf, &len, 0xb6);
		break;
	case BPF_H:
		kop_emit_rex(buf, &len, false, kop_x86_ext(dst_reg),
			       false, kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x0f);
		kop_emit_u8(buf, &len, 0xb7);
		break;
	case BPF_W:
		kop_emit_rex(buf, &len, false, kop_x86_ext(dst_reg),
			       false, kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x8b);
		break;
	case BPF_DW:
		kop_emit_rex(buf, &len, true, kop_x86_ext(dst_reg),
			       false, kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x8b);
		break;
	default:
		return -EINVAL;
	}

	kop_emit_modrm_mem(buf, &len, dst_reg, base_reg, offset);

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_mov_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;
	bool arch_regs;

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg,
			 &scale_log2, &offset, true);
	if (err)
		return err;
	arch_regs = mov_payload_form(kop_payload_decode(payload)) ==
		    X86_FORM_ARCH_SIB;

	if (!arch_regs) {
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
		base_reg = kop_x86_reg_for_prog(prog, base_reg);
		index_reg = kop_x86_reg_for_prog(prog, index_reg);
	}
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(base_reg) ||
	    !kop_x86_valid(index_reg))
		return -EINVAL;

	switch (size) {
	case BPF_B:
		kop_emit_rex(buf, &len, false, kop_x86_ext(dst_reg),
			       kop_x86_ext(index_reg), kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x0f);
		kop_emit_u8(buf, &len, 0xb6);
		break;
	case BPF_H:
		kop_emit_rex(buf, &len, false, kop_x86_ext(dst_reg),
			       kop_x86_ext(index_reg), kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x0f);
		kop_emit_u8(buf, &len, 0xb7);
		break;
	case BPF_W:
		kop_emit_rex(buf, &len, false, kop_x86_ext(dst_reg),
			       kop_x86_ext(index_reg), kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x8b);
		break;
	case BPF_DW:
		kop_emit_rex(buf, &len, true, kop_x86_ext(dst_reg),
			       kop_x86_ext(index_reg), kop_x86_ext(base_reg));
		kop_emit_u8(buf, &len, 0x8b);
		break;
	default:
		return -EINVAL;
	}

	kop_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kop_emit_finish(image, off, emit, buf, len);
}

static void emit_store_reg_prefix(u8 *buf, u32 *len, u8 size, u8 src_reg,
				  u8 base_reg)
{
	u32 before_rex;

	if (size == BPF_H)
		kop_emit_u8(buf, len, 0x66);
	before_rex = *len;
	kop_emit_rex(buf, len, size == BPF_DW,
		     kop_x86_ext(src_reg), false, kop_x86_ext(base_reg));
	if (size == BPF_B && *len == before_rex && kop_x86_needs_rex8(src_reg))
		kop_emit_u8(buf, len, 0x40);
	kop_emit_u8(buf, len, size == BPF_B ? 0x88 : 0x89);
}

static void emit_mov_store_slot(u8 *buf, u32 *len, u8 temp, u8 frame, bool load)
{
	kop_emit_rex(buf, len, true, kop_x86_ext(temp), false, kop_x86_ext(frame));
	kop_emit_u8(buf, len, load ? 0x8b : 0x89);
	kop_emit_modrm_mem(buf, len, temp, frame, KOP_X86_PROOF_RHS_OFF);
}

static int emit_store_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 size, bool arch_base)
{
	u8 buf[32];
	u8 src_reg, base_reg, byte_lane;
	u8 frame = kop_x86_reg_for_prog(prog, BPF_REG_10);
	s16 offset;
	u32 len = 0;
	int temp = -1;
	int err;

	err = decode_store(payload,
			   arch_base ? X86_FORM_ARCH_STORE : X86_FORM_STORE,
			   &src_reg, &base_reg, &offset, &byte_lane);
	if (err)
		return err;
	if (byte_lane && size != BPF_B)
		return -EINVAL;
	if (byte_lane) {
		temp = mov_store_temp(src_reg, base_reg);
		if (temp < 0)
			return temp;
		temp = kop_x86_reg_for_prog(prog, temp);
	}
	src_reg = kop_x86_reg_for_prog(prog, src_reg);
	base_reg = kop_x86_reg_for_prog(prog, base_reg);
	if (!kop_x86_valid(src_reg) || !kop_x86_valid(base_reg))
		return -EINVAL;
	if (temp >= 0) {
		/* Extract bits 15:8 in a live temporary. This also supports high-byte
		 * stores with extended bases, which cannot encode AH/CH/DH/BH.
		 */
		emit_mov_store_slot(buf, &len, temp, frame, false);
		kop_emit_rex_rr(buf, &len, true, src_reg, temp);
		kop_emit_u8(buf, &len, 0x89);
		kop_emit_u8(buf, &len, 0xc0 | (kop_x86_code(src_reg) << 3) | kop_x86_code(temp));
		kop_emit_rex_rr(buf, &len, true, 0, temp);
		kop_emit_u8(buf, &len, 0xc1);
		kop_emit_u8(buf, &len, 0xe8 | kop_x86_code(temp));
		kop_emit_u8(buf, &len, 8);
		src_reg = temp;
	}
	emit_store_reg_prefix(buf, &len, size, src_reg, base_reg);
	kop_emit_modrm_mem(buf, &len, src_reg, base_reg, offset);
	if (temp >= 0)
		emit_mov_store_slot(buf, &len, temp, frame, true);
	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_mov_imm_store_x86(u8 *image, u32 *off, bool emit, u64 payload,
				  const struct bpf_prog *prog, u8 size,
				  bool arch_base)
{
	u8 buf[16];
	u8 base_reg;
	s16 offset;
	s32 imm;
	u32 len = 0;
	int err;

	err = decode_store_imm(payload,
			       arch_base ? X86_FORM_ARCH_STORE_IMM :
					   X86_FORM_STORE_IMM,
			       &base_reg, &offset, &imm);
	if (err)
		return err;
	if (size == BPF_B && (imm < 0 || imm > 0xff))
		return -EINVAL;
	if (size == BPF_H && (imm < -32768 || imm > 0xffff))
		return -EINVAL;

	base_reg = kop_x86_reg_for_prog(prog, base_reg);
	if (!kop_x86_valid(base_reg))
		return -EINVAL;

	if (size == BPF_H)
		kop_emit_u8(buf, &len, 0x66);
	kop_emit_rex(buf, &len, size == BPF_DW, false, false,
		       kop_x86_ext(base_reg));
	kop_emit_u8(buf, &len, size == BPF_B ? 0xc6 : 0xc7);
	kop_emit_modrm_mem(buf, &len, 0, base_reg, offset);
	if (size == BPF_B) {
		kop_emit_u8(buf, &len, (u8)imm);
	} else if (size == BPF_H) {
		kop_emit_u8(buf, &len, (u8)imm);
		kop_emit_u8(buf, &len, (u8)((u32)imm >> 8));
	} else {
		kop_emit_s32(buf, &len, imm);
	}

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_movb_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg;
	s32 imm;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_imm_any(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	if (!kop_x86_reg_is_bpf_writable(dst_reg) || imm < 0 || imm > 0xff)
		return -EINVAL;

	dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
	if (!kop_x86_valid(dst_reg))
		return -EINVAL;

	kop_emit_rex8_rm(buf, &len, dst_reg);
	kop_emit_u8(buf, &len, 0xc6);
	kop_emit_u8(buf, &len, 0xc0 | kop_x86_code(dst_reg));
	kop_emit_u8(buf, &len, (u8)imm);

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_movb_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_IMM:
	case X86_FORM_ARCH_IMM:
		return emit_movb_imm_x86(image, off, emit, payload, prog);
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_B,
					  false);
	case X86_FORM_ARCH_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_B,
					  true);
	case X86_FORM_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_B, false);
	case X86_FORM_ARCH_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_B, true);
	default:
		return -EINVAL;
	}
}

static int emit_movw_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_H,
					  false);
	case X86_FORM_ARCH_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_H,
					  true);
	case X86_FORM_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_H, false);
	case X86_FORM_ARCH_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_H, true);
	default:
		return -EINVAL;
	}
}

static int emit_movl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return emit_mov_rr_x86(image, off, emit, payload, prog, false);
	case X86_FORM_IMM:
	case X86_FORM_ARCH_IMM:
		return emit_mov_imm_x86(image, off, emit, payload, prog, false);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_W,
					false);
	case X86_FORM_ARCH_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_W,
					true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_W);
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_W,
					  false);
	case X86_FORM_ARCH_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_W,
					  true);
	case X86_FORM_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_W, false);
	case X86_FORM_ARCH_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_W, true);
	default:
		return -EINVAL;
	}
}

static int emit_movq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return emit_mov_rr_x86(image, off, emit, payload, prog, true);
	case X86_FORM_IMM:
	case X86_FORM_ARCH_IMM:
		return emit_mov_imm_x86(image, off, emit, payload, prog, true);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_DW,
					false);
	case X86_FORM_ARCH_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_DW,
					true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_DW);
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog,
					  BPF_DW, false);
	case X86_FORM_ARCH_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog,
					  BPF_DW, true);
	case X86_FORM_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_DW, false);
	case X86_FORM_ARCH_STORE_IMM:
		return emit_mov_imm_store_x86(image, off, emit, payload, prog,
					      BPF_DW, true);
	default:
		return -EINVAL;
	}
}

static int emit_movzbl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xb6,
					 true);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_B,
					false);
	case X86_FORM_ARCH_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_B,
					true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_B);
	default:
		return -EINVAL;
	}
}

static int emit_movzwl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	switch (mov_payload_form(kop_payload_decode(payload))) {
	case X86_FORM_RR:
	case X86_FORM_ARCH_RR:
	case X86_FORM_ARCH_TO_BPF_RR:
	case X86_FORM_BPF_TO_ARCH_RR:
		return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xb7,
					 false);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_H,
					false);
	case X86_FORM_ARCH_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_H,
					true);
	case X86_FORM_SIB:
	case X86_FORM_ARCH_SIB:
		return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_H);
	default:
		return -EINVAL;
	}
}

static int emit_movswl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xbf, false);
}

static int emit_movsxd_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	struct mov_rr_payload rr;
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;
	bool arch_regs;

	if (mov_payload_form(kop_payload_decode(payload)) == X86_FORM_RR ||
	    mov_payload_form(kop_payload_decode(payload)) == X86_FORM_ARCH_RR) {
		err = decode_rr_any(payload, &rr);
		if (err)
			return err;
		dst_reg = rr.dst_arch ? rr.dst_reg :
				 kop_x86_reg_for_prog(prog, rr.dst_reg);
		base_reg = rr.src_arch ? rr.src_reg :
				  kop_x86_reg_for_prog(prog, rr.src_reg);
		if (!kop_x86_valid(dst_reg) || !kop_x86_valid(base_reg))
			return -EINVAL;
		kop_emit_rex_rr(buf, &len, true, dst_reg, base_reg);
		kop_emit_u8(buf, &len, 0x63);
		kop_emit_u8(buf, &len, 0xc0 |
			      (kop_x86_code(dst_reg) << 3) |
			      kop_x86_code(base_reg));
		return kop_emit_finish(image, off, emit, buf, len);
	}

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg, &scale_log2,
			 &offset, false);
	if (err)
		return err;
	arch_regs = mov_payload_form(kop_payload_decode(payload)) ==
		    X86_FORM_ARCH_SIB;

	if (!arch_regs) {
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
		base_reg = kop_x86_reg_for_prog(prog, base_reg);
		index_reg = kop_x86_reg_for_prog(prog, index_reg);
	}
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(base_reg) ||
	    !kop_x86_valid(index_reg))
		return -EINVAL;

	kop_emit_rex(buf, &len, true, kop_x86_ext(dst_reg),
		       kop_x86_ext(index_reg), kop_x86_ext(base_reg));
	kop_emit_u8(buf, &len, 0x63);
	kop_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kop_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kop bpf_x86_movb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 32,
	.instantiate_insn = instantiate_movb,
	.emit_x86 = emit_movb_x86,
};

const struct bpf_kop bpf_x86_movw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movw,
	.emit_x86 = emit_movw_x86,
};

const struct bpf_kop bpf_x86_movl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movl,
	.emit_x86 = emit_movl_x86,
};

const struct bpf_kop bpf_x86_movq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movq,
	.emit_x86 = emit_movq_x86,
};

const struct bpf_kop bpf_x86_movzbl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzbl,
	.emit_x86 = emit_movzbl_x86,
};

const struct bpf_kop bpf_x86_movzwl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzwl,
	.emit_x86 = emit_movzwl_x86,
};

const struct bpf_kop bpf_x86_movswl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 3,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movswl_rr,
	.emit_x86 = emit_movswl_x86,
};

const struct bpf_kop bpf_x86_movsxd_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movsxd,
	.emit_x86 = emit_movsxd_x86,
};

static const struct bpf_kop * const bpf_x86_mov_kop_descs[] = {
	&bpf_x86_movb_desc,
	&bpf_x86_movl_desc,
	&bpf_x86_movq_desc,
	&bpf_x86_movswl_desc,
	&bpf_x86_movsxd_desc,
	&bpf_x86_movw_desc,
	&bpf_x86_movzbl_desc,
	&bpf_x86_movzwl_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_mov, "BpfReJIT x86 koperation: MOV family",
		       bpf_x86_mov_kfunc_ids, bpf_x86_mov_kop_descs);
