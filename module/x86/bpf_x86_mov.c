// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOV-family instructions.
 *
 * Public kfunc names identify the x86 instruction only.  Operand encoding
 * variants (rr, mem, sib, store, imm-store) live in the payload form tag.
 */

#include "kinsn_x86_emit.h"

#define X86_FORM_RR		1
#define X86_FORM_MEM		4
#define X86_FORM_SIB		5
#define X86_FORM_STORE		6
#define X86_FORM_STORE_IMM	7

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

static __always_inline int decode_rr(u64 payload, u8 *dst_reg, u8 *src_reg)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != X86_FORM_RR || payload >> 12)
		return -EINVAL;

	*dst_reg = kinsn_payload_reg(payload, 4);
	*src_reg = kinsn_payload_reg(payload, 8);
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;

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
	if (!kinsn_x86_operand_valid(*reg) || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_sib(u64 payload, u8 *dst_reg, u8 *base_reg,
				      u8 *index_reg, u8 *scale_log2,
				      s16 *offset, bool allow_shadow_dst)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != X86_FORM_SIB || payload >> 36)
		return -EINVAL;

	*dst_reg = kinsn_payload_reg(payload, 4);
	*base_reg = kinsn_payload_reg(payload, 8);
	*index_reg = kinsn_payload_reg(payload, 12);
	*scale_log2 = (payload >> 16) & 0x3;
	*offset = kinsn_payload_s16(payload, 20);
	if (payload & (0x3ULL << 18))
		return -EINVAL;
	if (*base_reg > BPF_REG_10 || *index_reg >= BPF_REG_10)
		return -EINVAL;
	if (!allow_shadow_dst && kinsn_x86_reg_is_shadowed(*dst_reg))
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*base_reg) ||
	    !kinsn_x86_reg_valid(*index_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store_imm(u64 payload, u8 *base_reg,
					    s16 *offset, u8 *imm)
{
	payload = kinsn_payload_decode(payload);
	if (mov_payload_form(payload) != X86_FORM_STORE_IMM || payload >> 32)
		return -EINVAL;

	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);
	*imm = kinsn_payload_u8(payload, 24);
	if (*base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int instantiate_movq_value(u8 dst_reg, u8 src_reg,
						  struct bpf_insn *insn_buf)
{
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;

	if (!kinsn_x86_reg_is_shadowed(src_reg) &&
	    !kinsn_x86_reg_is_shadowed(dst_reg)) {
		insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
		return 1;
	}
	if (!kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_read64(insn_buf, &cnt, dst_reg, src_reg);
		return cnt ? cnt : 1;
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, src_reg);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movq_reg(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_rr(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	return instantiate_movq_value(dst_reg, src_reg, insn_buf);
}

static int instantiate_movl_reg(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_rr(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
		return 1;
	}

	value_reg = kinsn_x86_reg_is_shadowed(dst_reg) ? KINSN_X86_SCRATCH0 : dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read32(insn_buf, &cnt, value_reg, src_reg);
	insn_buf[cnt++] = BPF_MOV32_REG(value_reg, value_reg);
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_write32(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_movzx_rr(u64 payload, struct bpf_insn *insn_buf, u32 mask)
{
	u8 dst_reg, src_reg, value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_rr(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
		insn_buf[1] = BPF_ALU32_IMM(BPF_AND, dst_reg, mask);
		return 2;
	}

	value_reg = kinsn_x86_reg_is_shadowed(dst_reg) ? KINSN_X86_SCRATCH0 : dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read32(insn_buf, &cnt, value_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, value_reg, mask);
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_write32(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_movswl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_rr(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
		insn_buf[1] = BPF_ALU32_IMM(BPF_LSH, dst_reg, 16);
		insn_buf[2] = BPF_ALU32_IMM(BPF_ARSH, dst_reg, 16);
		return 3;
	}

	value_reg = kinsn_x86_reg_is_shadowed(dst_reg) ? KINSN_X86_SCRATCH0 : dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read32(insn_buf, &cnt, value_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, value_reg, 16);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_ARSH, value_reg, 16);
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_write32(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_mov_mem(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	s16 offset;
	int cnt = 0;
	int err;

	err = decode_mem(payload, X86_FORM_MEM, &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		insn_buf[cnt++] = BPF_LDX_MEM(size, KINSN_X86_SCRATCH0,
					      base_reg, offset);
		kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}

	insn_buf[0] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
	return 1;
}

static int instantiate_mov_sib(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg, index_reg, scale_log2, addr_reg, value_reg;
	u32 scratch_mask = 0;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg,
			 &scale_log2, &offset, true);
	if (err)
		return err;

	addr_reg = dst_reg;
	value_reg = dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg) ||
	    dst_reg == base_reg || dst_reg == index_reg) {
		addr_reg = kinsn_x86_scratch_avoid(base_reg, index_reg, 0);
		scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg);
		if (kinsn_x86_reg_is_shadowed(dst_reg)) {
			value_reg = kinsn_x86_scratch_avoid(base_reg, index_reg,
							    addr_reg);
			scratch_mask |= KINSN_X86_SCRATCH_MASK(value_reg);
		}
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	}
	insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg, index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(size, value_reg, addr_reg, offset);
	if (scratch_mask) {
		kinsn_x86_write64(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_store_reg(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 src_reg, base_reg, value_reg;
	u32 scratch_mask;
	s16 offset;
	int cnt = 0;
	int err;

	err = decode_mem(payload, X86_FORM_STORE, &src_reg, &base_reg, &offset);
	if (err)
		return err;
	if (!kinsn_x86_reg_is_shadowed(src_reg) && src_reg >= BPF_REG_10)
		return -EINVAL;

	if (kinsn_x86_reg_is_shadowed(src_reg)) {
		value_reg = kinsn_x86_scratch_avoid(base_reg, 0, 0);
		scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg);
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		kinsn_x86_read64(insn_buf, &cnt, value_reg, src_reg);
		insn_buf[cnt++] = BPF_STX_MEM(size, base_reg, value_reg,
					      offset);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}

	insn_buf[cnt++] = BPF_STX_MEM(size, base_reg, src_reg, offset);
	return cnt;
}

static int instantiate_movb_imm_store(u64 payload, struct bpf_insn *insn_buf)
{
	u8 base_reg, imm;
	s16 offset;
	int err;

	err = decode_store_imm(payload, &base_reg, &offset, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_ST_MEM(BPF_B, base_reg, offset, imm);
	return 1;
}

static int instantiate_movb(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_B);
	case X86_FORM_STORE_IMM:
		return instantiate_movb_imm_store(payload, insn_buf);
	default:
		return -EINVAL;
	}
}

static int instantiate_movw(u64 payload, struct bpf_insn *insn_buf)
{
	if (mov_payload_form(kinsn_payload_decode(payload)) != X86_FORM_STORE)
		return -EINVAL;
	return instantiate_store_reg(payload, insn_buf, BPF_H);
}

static int instantiate_movl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return instantiate_movl_reg(payload, insn_buf);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_W);
	case X86_FORM_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_W);
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_W);
	default:
		return -EINVAL;
	}
}

static int instantiate_movq(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return instantiate_movq_reg(payload, insn_buf);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_DW);
	case X86_FORM_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_DW);
	case X86_FORM_STORE:
		return instantiate_store_reg(payload, insn_buf, BPF_DW);
	default:
		return -EINVAL;
	}
}

static int instantiate_movzbl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return instantiate_movzx_rr(payload, insn_buf, 0xff);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_B);
	case X86_FORM_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_B);
	default:
		return -EINVAL;
	}
}

static int instantiate_movzwl(u64 payload, struct bpf_insn *insn_buf)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return instantiate_movzx_rr(payload, insn_buf, 0xffff);
	case X86_FORM_MEM:
		return instantiate_mov_mem(payload, insn_buf, BPF_H);
	case X86_FORM_SIB:
		return instantiate_mov_sib(payload, insn_buf, BPF_H);
	default:
		return -EINVAL;
	}
}

static int instantiate_movsxd(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2, addr_reg;
	u32 scratch_mask;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg, &scale_log2,
			 &offset, false);
	if (err)
		return err;

	addr_reg = kinsn_x86_scratch_avoid(base_reg, index_reg, dst_reg);
	scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg, index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_W, dst_reg, addr_reg, offset);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, 32);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ARSH, dst_reg, 32);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_mov_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog, bool is64)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_rr(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, is64, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movzx_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog, u8 opcode,
			     bool src_is_byte)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_rr(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
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
			    const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_mem(payload, X86_FORM_MEM, &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
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

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg,
			 &scale_log2, &offset, true);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
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
				  u8 base_reg)
{
	u32 before_rex;

	if (size == BPF_H)
		kinsn_emit_u8(buf, len, 0x66);
	before_rex = *len;
	kinsn_emit_rex(buf, len, size == BPF_DW, kinsn_x86_ext(src_reg),
		       false, kinsn_x86_ext(base_reg));
	if (size == BPF_B && *len == before_rex && kinsn_x86_needs_rex8(src_reg))
		kinsn_emit_u8(buf, len, 0x40);
	kinsn_emit_u8(buf, len, size == BPF_B ? 0x88 : 0x89);
}

static int emit_store_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 src_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_mem(payload, X86_FORM_STORE, &src_reg, &base_reg, &offset);
	if (err)
		return err;

	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(src_reg) || !kinsn_x86_valid(base_reg))
		return -EINVAL;

	emit_store_reg_prefix(buf, &len, size, src_reg, base_reg);
	kinsn_emit_modrm_mem(buf, &len, src_reg, base_reg, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movb_imm_store_x86(u8 *image, u32 *off, bool emit, u64 payload,
				   const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 base_reg, imm;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_store_imm(payload, &base_reg, &offset, &imm);
	if (err)
		return err;

	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(base_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, false, false, false, kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0xc6);
	kinsn_emit_modrm_mem(buf, &len, 0, base_reg, offset);
	kinsn_emit_u8(buf, &len, imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movb_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_B);
	case X86_FORM_STORE_IMM:
		return emit_movb_imm_store_x86(image, off, emit, payload, prog);
	default:
		return -EINVAL;
	}
}

static int emit_movw_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	if (mov_payload_form(kinsn_payload_decode(payload)) != X86_FORM_STORE)
		return -EINVAL;
	return emit_store_reg_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_movl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return emit_mov_rr_x86(image, off, emit, payload, prog, false);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_W);
	case X86_FORM_SIB:
		return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_W);
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_W);
	default:
		return -EINVAL;
	}
}

static int emit_movq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return emit_mov_rr_x86(image, off, emit, payload, prog, true);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_DW);
	case X86_FORM_SIB:
		return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_DW);
	case X86_FORM_STORE:
		return emit_store_reg_x86(image, off, emit, payload, prog, BPF_DW);
	default:
		return -EINVAL;
	}
}

static int emit_movzbl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	switch (mov_payload_form(kinsn_payload_decode(payload))) {
	case X86_FORM_RR:
		return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xb6,
					 true);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_B);
	case X86_FORM_SIB:
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
		return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xb7,
					 false);
	case X86_FORM_MEM:
		return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_H);
	case X86_FORM_SIB:
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
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_sib(payload, &dst_reg, &base_reg, &index_reg, &scale_log2,
			 &offset, false);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
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
