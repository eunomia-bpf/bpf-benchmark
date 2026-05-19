// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOV-family instructions.
 *
 * Public kfunc names identify the x86 instruction only.  Operand encoding
 * variants (rr, mem, sib, store, imm-store) live in the payload form tag.
 */

#include "kinsn_x86_emit.h"

#define X86_FORM_RR		1
#define X86_FORM_IMM		2
#define X86_FORM_SIB_RR		3
#define X86_FORM_MEM		4
#define X86_FORM_SIB		5
#define X86_FORM_STORE		6
#define X86_FORM_STORE_IMM	7
#define X86_FORM_FRAME		8
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

	payload = kinsn_payload_decode(payload);
	form = mov_payload_form(payload);
	if ((form != X86_FORM_RR &&
	     form != X86_FORM_ARCH_RR &&
	     form != X86_FORM_ARCH_TO_BPF_RR &&
	     form != X86_FORM_BPF_TO_ARCH_RR) ||
	    payload >> 12)
		return -EINVAL;

	rr->dst_reg = kinsn_payload_reg(payload, 4);
	rr->src_reg = kinsn_payload_reg(payload, 8);
	rr->dst_arch = mov_form_dst_arch(form);
	rr->src_arch = mov_form_src_arch(form);
	rr->dst_raw_bpf = mov_form_dst_raw_bpf(form);
	rr->src_raw_bpf = mov_form_src_raw_bpf(form);
	if (!kinsn_x86_operand_valid(rr->dst_reg) ||
	    !kinsn_x86_operand_valid(rr->src_reg))
		return -EINVAL;
	if ((rr->dst_raw_bpf && rr->dst_reg >= BPF_REG_10) ||
	    (rr->src_raw_bpf && rr->src_reg >= BPF_REG_10))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_rr(u64 payload, u8 *dst_reg, u8 *src_reg)
{
	struct mov_rr_payload rr;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;
	if (rr.dst_arch || rr.src_arch)
		return -EINVAL;
	*dst_reg = rr.dst_reg;
	*src_reg = rr.src_reg;
	return 0;
}

static __always_inline int decode_mem(u64 payload, u8 expected_form,
				      u8 *reg, u8 *base_reg, s16 *offset)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != expected_form || payload >> 28)
		return -EINVAL;

	*reg = kinsn_payload_reg(payload, 4);
	*base_reg = kinsn_payload_reg(payload, 8);
	*offset = kinsn_payload_s16(payload, 12);
	if (!kinsn_x86_operand_valid(*reg) ||
	    !kinsn_x86_operand_valid(*base_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store(u64 payload, u8 expected_form,
					u8 *src_reg, u8 *base_reg,
					s16 *offset, u8 *byte_lane)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != expected_form || payload >> 30)
		return -EINVAL;

	*src_reg = kinsn_payload_reg(payload, 4);
	*base_reg = kinsn_payload_reg(payload, 8);
	*offset = kinsn_payload_s16(payload, 12);
	*byte_lane = (payload >> 28) & 0x3;
	if (!kinsn_x86_operand_valid(*src_reg) ||
	    !kinsn_x86_operand_valid(*base_reg) ||
	    *byte_lane > 1)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_imm_any(u64 payload, u8 *dst_reg,
					  s32 *imm, bool *arch_reg)
{
	payload = kinsn_payload_decode(payload);
	*arch_reg = mov_payload_form(payload) == X86_FORM_ARCH_IMM;
	if ((mov_payload_form(payload) != X86_FORM_IMM &&
	     mov_payload_form(payload) != X86_FORM_ARCH_IMM) ||
	    payload >> 40)
		return -EINVAL;

	*dst_reg = kinsn_payload_reg(payload, 4);
	*imm = kinsn_payload_s32(payload, 8);
	if (!kinsn_x86_operand_valid(*dst_reg))
		return -EINVAL;
	return 0;
}

static __always_inline int decode_imm(u64 payload, u8 *dst_reg, s32 *imm)
{
	bool arch_reg;
	int err;

	err = decode_imm_any(payload, dst_reg, imm, &arch_reg);
	if (err)
		return err;
	return arch_reg ? -EINVAL : 0;
}

static __always_inline int decode_frame(u64 payload, u8 *dst_reg, u8 *src_reg)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != X86_FORM_FRAME || payload >> 12)
		return -EINVAL;

	*dst_reg = kinsn_payload_reg(payload, 4);
	*src_reg = kinsn_payload_reg(payload, 8);
	if ((*dst_reg == BPF_REG_10 && *src_reg == KINSN_X86_REG_RSP) ||
	    (*dst_reg == KINSN_X86_REG_RSP && *src_reg == BPF_REG_10))
		return 0;
	return -EINVAL;
}

static __always_inline int decode_sib(u64 payload, u8 *dst_reg, u8 *base_reg,
				      u8 *index_reg, u8 *scale_log2,
				      s16 *offset, bool allow_shadow_dst)
{
	u8 form;

	(void)allow_shadow_dst;
	payload = kinsn_payload_decode(payload);
	form = mov_payload_form(payload);
	if ((form != X86_FORM_SIB && form != X86_FORM_ARCH_SIB) ||
	    payload >> 36)
		return -EINVAL;

	*dst_reg = kinsn_payload_reg(payload, 4);
	*base_reg = kinsn_payload_reg(payload, 8);
	*index_reg = kinsn_payload_reg(payload, 12);
	*scale_log2 = (payload >> 16) & 0x3;
	*offset = kinsn_payload_s16(payload, 20);
	if (payload & (0x3ULL << 18))
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*base_reg) ||
	    !kinsn_x86_operand_valid(*index_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store_imm(u64 payload, u8 expected_form,
					    u8 *base_reg, s16 *offset,
					    s32 *imm)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != expected_form || payload >> 56)
		return -EINVAL;

	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);
	*imm = kinsn_payload_s32(payload, 24);
	if (!kinsn_x86_operand_valid(*base_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int instantiate_movq_value(u8 dst_reg, u8 src_reg,
						  struct bpf_insn *insn_buf,
						  bool dst_arch,
						  bool src_arch,
						  bool dst_raw_bpf,
						  bool src_raw_bpf)
{
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool src_shadowed = !src_raw_bpf &&
			    (src_arch ? kinsn_x86_arch_reg_is_shadowed(src_reg) :
					kinsn_x86_reg_is_shadowed(src_reg));
	bool dst_shadowed = !dst_raw_bpf &&
			    (dst_arch ? kinsn_x86_arch_reg_is_shadowed(dst_reg) :
					kinsn_x86_reg_is_shadowed(dst_reg));
	int cnt = 0;

	if (!src_shadowed && !dst_shadowed) {
		insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
		return 1;
	}
	if (!dst_shadowed) {
		if (src_raw_bpf)
			insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
		else if (src_arch)
			kinsn_x86_read64_arch(insn_buf, &cnt, dst_reg, src_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, dst_reg, src_reg);
		return cnt ? cnt : 1;
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (src_raw_bpf)
		insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH0, src_reg);
	else if (src_arch)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      src_reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				  src_reg);
	if (dst_arch)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movq_reg(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	return instantiate_movq_value(rr.dst_reg, rr.src_reg, insn_buf,
				      rr.dst_arch, rr.src_arch,
				      rr.dst_raw_bpf, rr.src_raw_bpf);
}

static int instantiate_movl_reg(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	u8 value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool src_shadowed, dst_shadowed;
	int cnt = 0;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	src_shadowed = !rr.src_raw_bpf &&
		       (rr.src_arch ? kinsn_x86_arch_reg_is_shadowed(rr.src_reg) :
				      kinsn_x86_reg_is_shadowed(rr.src_reg));
	dst_shadowed = !rr.dst_raw_bpf &&
		       (rr.dst_arch ? kinsn_x86_arch_reg_is_shadowed(rr.dst_reg) :
				      kinsn_x86_reg_is_shadowed(rr.dst_reg));
	if (!dst_shadowed && !src_shadowed) {
		insn_buf[0] = BPF_STX_MEM(BPF_W, BPF_REG_10, rr.src_reg,
					  KINSN_X86_PROOF_LHS_OFF);
		insn_buf[1] = BPF_MOV64_IMM(rr.dst_reg, 0);
		insn_buf[2] = BPF_LDX_MEM(BPF_W, rr.dst_reg, BPF_REG_10,
					  KINSN_X86_PROOF_LHS_OFF);
		return 3;
	}

	value_reg = dst_shadowed ? KINSN_X86_SCRATCH0 : rr.dst_reg;
	if (dst_shadowed)
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (rr.src_raw_bpf)
		insn_buf[cnt++] = BPF_MOV32_REG(value_reg, rr.src_reg);
	else if (rr.src_arch)
		kinsn_x86_read32_arch(insn_buf, &cnt, value_reg, rr.src_reg);
	else
		kinsn_x86_read32(insn_buf, &cnt, value_reg, rr.src_reg);
	insn_buf[cnt++] = BPF_MOV32_REG(value_reg, value_reg);
	if (dst_shadowed) {
		if (rr.dst_arch)
			kinsn_x86_write32_arch(insn_buf, &cnt, rr.dst_reg,
					       value_reg, scratch_mask);
		else
			kinsn_x86_write32(insn_buf, &cnt, rr.dst_reg,
					  value_reg, scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_mov_imm(u64 payload, struct bpf_insn *insn_buf, bool is64)
{
	u8 dst_reg;
	s32 imm;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool arch_reg, dst_shadowed;
	int cnt = 0;
	int err;

	err = decode_imm_any(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;

	dst_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(dst_reg) :
				  kinsn_x86_reg_is_shadowed(dst_reg);
	if (!dst_shadowed) {
		insn_buf[0] = is64 ? BPF_MOV64_IMM(dst_reg, imm) :
				      BPF_MOV32_IMM(dst_reg, imm);
		return 1;
	}

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = is64 ? BPF_MOV64_IMM(KINSN_X86_SCRATCH0, imm) :
				  BPF_MOV32_IMM(KINSN_X86_SCRATCH0, imm);
	if (is64) {
		if (arch_reg)
			kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
					       KINSN_X86_SCRATCH0,
					       scratch_mask);
		else
			kinsn_x86_write64(insn_buf, &cnt, dst_reg,
					  KINSN_X86_SCRATCH0, scratch_mask);
	} else {
		if (arch_reg)
			kinsn_x86_write32_arch(insn_buf, &cnt, dst_reg,
					       KINSN_X86_SCRATCH0,
					       scratch_mask);
		else
			kinsn_x86_write32(insn_buf, &cnt, dst_reg,
					  KINSN_X86_SCRATCH0, scratch_mask);
	}
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movq_frame(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_frame(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0, src_reg);
	kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			       scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, value_reg;
	u32 scratch_mask;
	s32 imm;
	bool arch_reg, dst_shadowed;
	int cnt = 0;
	int err;

	err = decode_imm_any(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	if (imm < 0 || imm > 0xff)
		return -EINVAL;

	dst_shadowed = arch_reg ? kinsn_x86_arch_reg_is_shadowed(dst_reg) :
				  kinsn_x86_reg_is_shadowed(dst_reg);
	if (!dst_shadowed &&
	    !kinsn_x86_is_scratch(dst_reg)) {
		insn_buf[0] = BPF_ALU64_IMM(BPF_AND, dst_reg, -256);
		insn_buf[1] = BPF_ALU64_IMM(BPF_OR, dst_reg, imm);
		return 2;
	}

	value_reg = kinsn_x86_scratch_avoid(dst_reg, 0, 0);
	scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, value_reg, dst_reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, value_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, value_reg, -256);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_OR, value_reg, imm);
	if (arch_reg)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg, value_reg,
				       scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movzx_rr(u64 payload, struct bpf_insn *insn_buf, u32 mask)
{
	struct mov_rr_payload rr;
	u8 value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool src_shadowed, dst_shadowed;
	int cnt = 0;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	src_shadowed = rr.src_arch ? kinsn_x86_arch_reg_is_shadowed(rr.src_reg) :
				     kinsn_x86_reg_is_shadowed(rr.src_reg);
	dst_shadowed = rr.dst_arch ? kinsn_x86_arch_reg_is_shadowed(rr.dst_reg) :
				     kinsn_x86_reg_is_shadowed(rr.dst_reg);
	if (!dst_shadowed && !src_shadowed) {
		insn_buf[0] = BPF_MOV32_REG(rr.dst_reg, rr.src_reg);
		insn_buf[1] = BPF_ALU32_IMM(BPF_AND, rr.dst_reg, mask);
		return 2;
	}

	value_reg = dst_shadowed ? KINSN_X86_SCRATCH0 : rr.dst_reg;
	if (dst_shadowed)
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (rr.src_arch)
		kinsn_x86_read32_arch(insn_buf, &cnt, value_reg, rr.src_reg);
	else
		kinsn_x86_read32(insn_buf, &cnt, value_reg, rr.src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, value_reg, mask);
	if (dst_shadowed) {
		if (rr.dst_arch)
			kinsn_x86_write32_arch(insn_buf, &cnt, rr.dst_reg,
					       value_reg, scratch_mask);
		else
			kinsn_x86_write32(insn_buf, &cnt, rr.dst_reg,
					  value_reg, scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_movswl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	struct mov_rr_payload rr;
	u8 value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	bool src_shadowed, dst_shadowed;
	int cnt = 0;
	int err;

	err = decode_rr_any(payload, &rr);
	if (err)
		return err;

	src_shadowed = rr.src_arch ? kinsn_x86_arch_reg_is_shadowed(rr.src_reg) :
				     kinsn_x86_reg_is_shadowed(rr.src_reg);
	dst_shadowed = rr.dst_arch ? kinsn_x86_arch_reg_is_shadowed(rr.dst_reg) :
				     kinsn_x86_reg_is_shadowed(rr.dst_reg);
	if (!dst_shadowed && !src_shadowed) {
		insn_buf[0] = BPF_MOV32_REG(rr.dst_reg, rr.src_reg);
		insn_buf[1] = BPF_ALU32_IMM(BPF_LSH, rr.dst_reg, 16);
		insn_buf[2] = BPF_ALU32_IMM(BPF_ARSH, rr.dst_reg, 16);
		return 3;
	}

	value_reg = dst_shadowed ? KINSN_X86_SCRATCH0 : rr.dst_reg;
	if (dst_shadowed)
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (rr.src_arch)
		kinsn_x86_read32_arch(insn_buf, &cnt, value_reg, rr.src_reg);
	else
		kinsn_x86_read32(insn_buf, &cnt, value_reg, rr.src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, value_reg, 16);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_ARSH, value_reg, 16);
	if (dst_shadowed) {
		if (rr.dst_arch)
			kinsn_x86_write32_arch(insn_buf, &cnt, rr.dst_reg,
					       value_reg, scratch_mask);
		else
			kinsn_x86_write32(insn_buf, &cnt, rr.dst_reg,
					  value_reg, scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_mov_mem(u64 payload, struct bpf_insn *insn_buf, u8 size,
			       bool arch_base)
{
	u8 dst_reg, base_reg, addr_reg, value_reg;
	u32 scratch_mask = 0;
	bool dst_shadowed;
	s16 offset;
	int cnt = 0;
	int err;

	err = decode_mem(payload, arch_base ? X86_FORM_ARCH_MEM : X86_FORM_MEM,
			 &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	addr_reg = base_reg;
	value_reg = dst_reg;
	dst_shadowed = arch_base ? kinsn_x86_arch_reg_is_shadowed(dst_reg) :
				   kinsn_x86_reg_is_shadowed(dst_reg);
	if ((arch_base && kinsn_x86_arch_reg_is_shadowed(base_reg)) ||
	    (!arch_base && kinsn_x86_reg_is_shadowed(base_reg))) {
		addr_reg = kinsn_x86_scratch_avoid(dst_reg, 0, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(addr_reg);
	}
	if (dst_shadowed || kinsn_x86_is_scratch(dst_reg)) {
		value_reg = kinsn_x86_scratch_avoid(addr_reg, dst_reg, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(value_reg);
	}

	if (scratch_mask)
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (addr_reg != base_reg) {
		if (arch_base)
			kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg,
					      base_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, addr_reg, base_reg);
	}
	insn_buf[cnt++] = BPF_LDX_MEM(size, value_reg, addr_reg, offset);
	if (value_reg != dst_reg) {
		if (arch_base)
			kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
					       value_reg, scratch_mask);
		else
			kinsn_x86_write64(insn_buf, &cnt, dst_reg, value_reg,
					  scratch_mask);
	}
	if (scratch_mask)
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_mov_sib(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	u8 addr_reg = KINSN_X86_SCRATCH0;
	u8 index_eval_reg = KINSN_X86_SCRATCH1;
	u8 value_reg = KINSN_X86_SCRATCH2;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;
	bool arch_regs;

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg,
			 &scale_log2, &offset, true);
	if (err)
		return err;
	arch_regs = mov_payload_form(kinsn_payload_decode(payload)) ==
		    X86_FORM_ARCH_SIB;

	if (!arch_regs) {
		if (dst_reg >= BPF_REG_10 || base_reg > BPF_REG_10 ||
		    index_reg >= BPF_REG_10)
			return -EINVAL;

		addr_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg,
						   index_reg);
		if (addr_reg == dst_reg || addr_reg == base_reg ||
		    addr_reg == index_reg)
			return -EINVAL;

		scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg);
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, base_reg);
		add_count = 1 << scale_log2;
		while (add_count--)
			insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg,
							index_reg);
		insn_buf[cnt++] = BPF_LDX_MEM(size, dst_reg, addr_reg,
					      offset);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_regs) {
		kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg, base_reg);
		kinsn_x86_read64_arch(insn_buf, &cnt, index_eval_reg,
				      index_reg);
	} else {
		kinsn_x86_read64(insn_buf, &cnt, addr_reg, base_reg);
		kinsn_x86_read64(insn_buf, &cnt, index_eval_reg, index_reg);
	}
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg,
						index_eval_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(size, value_reg, addr_reg, offset);
	if (arch_regs)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg, value_reg,
				       scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_store_reg(u64 payload, struct bpf_insn *insn_buf,
				 u8 size, bool arch_base)
{
	u8 src_reg, base_reg, addr_reg, value_reg, byte_lane;
	u32 scratch_mask = 0;
	s16 offset;
	int cnt = 0;
	int err;

	err = decode_store(payload,
			   arch_base ? X86_FORM_ARCH_STORE : X86_FORM_STORE,
			   &src_reg, &base_reg, &offset, &byte_lane);
	if (err)
		return err;
	if (byte_lane && size != BPF_B)
		return -EINVAL;
	if (!arch_base && src_reg != BPF_REG_10 &&
	    !kinsn_x86_reg_is_shadowed(src_reg) && src_reg >= BPF_REG_10)
		return -EINVAL;

	addr_reg = base_reg;
	value_reg = src_reg;
	if ((arch_base && kinsn_x86_arch_reg_is_shadowed(base_reg)) ||
	    (!arch_base && kinsn_x86_reg_is_shadowed(base_reg))) {
		addr_reg = kinsn_x86_scratch_avoid(src_reg, 0, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(addr_reg);
	}
	if ((arch_base && kinsn_x86_arch_reg_is_shadowed(src_reg)) ||
	    (!arch_base && kinsn_x86_reg_is_shadowed(src_reg)) || byte_lane) {
		value_reg = kinsn_x86_scratch_avoid(addr_reg, src_reg, 0);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(value_reg);
	}
	if (scratch_mask) {
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		if (addr_reg != base_reg) {
			if (arch_base)
				kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg,
						      base_reg);
			else
				kinsn_x86_read64(insn_buf, &cnt, addr_reg,
						 base_reg);
		}
	}
	if (value_reg != src_reg) {
		if (arch_base)
			kinsn_x86_read64_arch(insn_buf, &cnt, value_reg,
					      src_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, value_reg, src_reg);
		if (byte_lane)
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, value_reg, 8);
	}

	insn_buf[cnt++] = BPF_STX_MEM(size, addr_reg, value_reg, offset);
	if (scratch_mask)
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_mov_imm_store(u64 payload, struct bpf_insn *insn_buf,
				     u8 size, bool arch_base)
{
	u8 base_reg, addr_reg;
	u32 scratch_mask = 0;
	s16 offset;
	s32 imm;
	int cnt = 0;
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

	addr_reg = base_reg;
	if ((arch_base && kinsn_x86_arch_reg_is_shadowed(base_reg)) ||
	    (!arch_base && kinsn_x86_reg_is_shadowed(base_reg))) {
		addr_reg = KINSN_X86_SCRATCH0;
		scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg);
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		if (arch_base)
			kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg,
					      base_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, addr_reg, base_reg);
	}
	insn_buf[cnt++] = BPF_ST_MEM(size, addr_reg, offset, imm);
	if (scratch_mask)
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movb(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	case X86_FORM_FRAME:
		return instantiate_movq_frame(payload, insn_buf);
	default:
		return -EINVAL;
	}
}

static int instantiate_movzbl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	u8 dst_reg, base_reg, index_reg, scale_log2;
	u8 addr_reg = KINSN_X86_SCRATCH0;
	u8 index_eval_reg = KINSN_X86_SCRATCH1;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;
	bool arch_regs;

	if (mov_payload_form(kinsn_payload_decode(payload)) == X86_FORM_RR ||
	    mov_payload_form(kinsn_payload_decode(payload)) == X86_FORM_ARCH_RR) {
		err = decode_rr_any(payload, &rr);
		if (err)
			return err;
		scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		if (rr.src_arch)
			kinsn_x86_read64_arch(insn_buf, &cnt,
					      KINSN_X86_SCRATCH0,
					      rr.src_reg);
		else
			kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
					 rr.src_reg);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH,
						KINSN_X86_SCRATCH0, 32);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ARSH,
						KINSN_X86_SCRATCH0, 32);
		if (rr.dst_arch)
			kinsn_x86_write64_arch(insn_buf, &cnt, rr.dst_reg,
					       KINSN_X86_SCRATCH0,
					       scratch_mask);
		else
			kinsn_x86_write64(insn_buf, &cnt, rr.dst_reg,
					  KINSN_X86_SCRATCH0, scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg, &scale_log2,
			 &offset, false);
	if (err)
		return err;
	arch_regs = mov_payload_form(kinsn_payload_decode(payload)) ==
		    X86_FORM_ARCH_SIB;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_regs) {
		kinsn_x86_read64_arch(insn_buf, &cnt, addr_reg, base_reg);
		kinsn_x86_read64_arch(insn_buf, &cnt, index_eval_reg,
				      index_reg);
	} else {
		kinsn_x86_read64(insn_buf, &cnt, addr_reg, base_reg);
		kinsn_x86_read64(insn_buf, &cnt, index_eval_reg, index_reg);
	}
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg,
						index_eval_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_W, KINSN_X86_SCRATCH0, addr_reg,
				      offset);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, KINSN_X86_SCRATCH0, 32);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ARSH, KINSN_X86_SCRATCH0, 32);
	if (arch_regs)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
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
			 kinsn_x86_reg_for_prog(prog, rr.dst_reg);
	src_reg = rr.src_arch ? rr.src_reg :
			 kinsn_x86_reg_for_prog(prog, rr.src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, is64, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
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
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	if (!is64) {
		kinsn_emit_rex_rr(buf, &len, false, 0, dst_reg);
		kinsn_emit_u8(buf, &len, 0xb8 | kinsn_x86_code(dst_reg));
		kinsn_emit_s32(buf, &len, imm);
	} else {
		kinsn_emit_rex_rr(buf, &len, true, 0, dst_reg);
		kinsn_emit_u8(buf, &len, 0xc7);
		kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_code(dst_reg));
		kinsn_emit_s32(buf, &len, imm);
	}

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movq_frame_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_frame(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, true, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_u8(buf, &len, 0xc0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
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
			 kinsn_x86_reg_for_prog(prog, rr.dst_reg);
	src_reg = rr.src_arch ? rr.src_reg :
			 kinsn_x86_reg_for_prog(prog, rr.src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	if (src_is_byte)
		kinsn_emit_rex8(buf, &len, dst_reg, src_reg, true, false, true);
	else
		kinsn_emit_rex_rr(buf, &len, false, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, opcode);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(dst_reg) << 3) |
		      kinsn_x86_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
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
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	}
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg))
		return -EINVAL;

	switch (size) {
	case BPF_B:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb6);
		break;
	case BPF_H:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb7);
		break;
	case BPF_W:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	case BPF_DW:
		kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	default:
		return -EINVAL;
	}

	kinsn_emit_modrm_mem(buf, &len, dst_reg, base_reg, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
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
	arch_regs = mov_payload_form(kinsn_payload_decode(payload)) ==
		    X86_FORM_ARCH_SIB;

	if (!arch_regs) {
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
		index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	}
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    !kinsn_x86_valid(index_reg))
		return -EINVAL;

	switch (size) {
	case BPF_B:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb6);
		break;
	case BPF_H:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb7);
		break;
	case BPF_W:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	case BPF_DW:
		kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	default:
		return -EINVAL;
	}

	kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static void emit_store_reg_prefix(u8 *buf, u32 *len, u8 size, u8 src_reg,
				  u8 base_reg, u8 byte_lane)
{
	u32 before_rex;

	if (size == BPF_H)
		kinsn_emit_u8(buf, len, 0x66);
	before_rex = *len;
	if (!byte_lane)
		kinsn_emit_rex(buf, len, size == BPF_DW,
			       kinsn_x86_ext(src_reg), false,
			       kinsn_x86_ext(base_reg));
	if (size == BPF_B && !byte_lane && *len == before_rex &&
	    kinsn_x86_needs_rex8(src_reg))
		kinsn_emit_u8(buf, len, 0x40);
	kinsn_emit_u8(buf, len, size == BPF_B ? 0x88 : 0x89);
}

static __always_inline int x86_high_byte_code(u8 reg)
{
	if (kinsn_x86_ext(reg) || kinsn_x86_code(reg) > 3)
		return -EINVAL;
	return kinsn_x86_code(reg) + 4;
}

static int emit_store_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 size,
			      bool arch_base)
{
	u8 buf[16];
	u8 src_reg, base_reg, modrm_src, byte_lane;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_store(payload,
			   arch_base ? X86_FORM_ARCH_STORE : X86_FORM_STORE,
			   &src_reg, &base_reg, &offset, &byte_lane);
	if (err)
		return err;
	if (byte_lane && size != BPF_B)
		return -EINVAL;

	if (!arch_base) {
		src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	}
	if (!kinsn_x86_valid(src_reg) || !kinsn_x86_valid(base_reg))
		return -EINVAL;
	if (byte_lane && kinsn_x86_ext(base_reg))
		return -EINVAL;

	if (byte_lane) {
		err = x86_high_byte_code(src_reg);
		if (err < 0)
			return err;
		modrm_src = err;
	} else {
		modrm_src = src_reg;
	}

	emit_store_reg_prefix(buf, &len, size, src_reg, base_reg, byte_lane);
	if (byte_lane)
		kinsn_emit_modrm_mem_raw(buf, &len, modrm_src, base_reg, offset);
	else
		kinsn_emit_modrm_mem(buf, &len, modrm_src, base_reg, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
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

	if (!arch_base)
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(base_reg))
		return -EINVAL;

	if (size == BPF_H)
		kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex(buf, &len, size == BPF_DW, false, false,
		       kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, size == BPF_B ? 0xc6 : 0xc7);
	kinsn_emit_modrm_mem(buf, &len, 0, base_reg, offset);
	if (size == BPF_B) {
		kinsn_emit_u8(buf, &len, (u8)imm);
	} else if (size == BPF_H) {
		kinsn_emit_u8(buf, &len, (u8)imm);
		kinsn_emit_u8(buf, &len, (u8)((u32)imm >> 8));
	} else {
		kinsn_emit_s32(buf, &len, imm);
	}

	return kinsn_emit_finish(image, off, emit, buf, len);
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
	if (imm < 0 || imm > 0xff)
		return -EINVAL;

	if (!arch_reg)
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;

	kinsn_emit_rex8_rm(buf, &len, dst_reg);
	kinsn_emit_u8(buf, &len, 0xc6);
	kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_code(dst_reg));
	kinsn_emit_u8(buf, &len, (u8)imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movb_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
	case X86_FORM_FRAME:
		return emit_movq_frame_x86(image, off, emit, payload, prog);
	default:
		return -EINVAL;
	}
}

static int emit_movzbl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
			   const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
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
			   const struct bpf_prog *prog)
{
	return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xbf, false);
}

static int emit_movsxd_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	struct mov_rr_payload rr;
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;
	bool arch_regs;

	if (mov_payload_form(kinsn_payload_decode(payload)) == X86_FORM_RR ||
	    mov_payload_form(kinsn_payload_decode(payload)) == X86_FORM_ARCH_RR) {
		err = decode_rr_any(payload, &rr);
		if (err)
			return err;
		dst_reg = rr.dst_arch ? rr.dst_reg :
				 kinsn_x86_reg_for_prog(prog, rr.dst_reg);
		base_reg = rr.src_arch ? rr.src_reg :
				  kinsn_x86_reg_for_prog(prog, rr.src_reg);
		if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg))
			return -EINVAL;
		kinsn_emit_rex_rr(buf, &len, true, dst_reg, base_reg);
		kinsn_emit_u8(buf, &len, 0x63);
		kinsn_emit_u8(buf, &len, 0xc0 |
			      (kinsn_x86_code(dst_reg) << 3) |
			      kinsn_x86_code(base_reg));
		return kinsn_emit_finish(image, off, emit, buf, len);
	}

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg, &scale_log2,
			 &offset, false);
	if (err)
		return err;
	arch_regs = mov_payload_form(kinsn_payload_decode(payload)) ==
		    X86_FORM_ARCH_SIB;

	if (!arch_regs) {
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
		base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
		index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	}
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    !kinsn_x86_valid(index_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(dst_reg),
		       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0x63);
	kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_movb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movb,
	.emit_x86 = emit_movb_x86,
};

const struct bpf_kinsn bpf_x86_movw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movw,
	.emit_x86 = emit_movw_x86,
};

const struct bpf_kinsn bpf_x86_movl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movl,
	.emit_x86 = emit_movl_x86,
};

const struct bpf_kinsn bpf_x86_movq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movq,
	.emit_x86 = emit_movq_x86,
};

const struct bpf_kinsn bpf_x86_movzbl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzbl,
	.emit_x86 = emit_movzbl_x86,
};

const struct bpf_kinsn bpf_x86_movzwl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzwl,
	.emit_x86 = emit_movzwl_x86,
};

const struct bpf_kinsn bpf_x86_movswl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movswl_rr,
	.emit_x86 = emit_movswl_x86,
};

const struct bpf_kinsn bpf_x86_movsxd_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 14 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movsxd,
	.emit_x86 = emit_movsxd_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_kinsn_descs[] = {
	&bpf_x86_movb_desc,
	&bpf_x86_movl_desc,
	&bpf_x86_movq_desc,
	&bpf_x86_movswl_desc,
	&bpf_x86_movsxd_desc,
	&bpf_x86_movw_desc,
	&bpf_x86_movzbl_desc,
	&bpf_x86_movzwl_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov, "BpfReJIT x86 kinsns: MOV family",
		       bpf_x86_mov_kfunc_ids, bpf_x86_mov_kinsn_descs);
