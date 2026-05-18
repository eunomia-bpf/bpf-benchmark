// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: LEA — x86 flagless base/index/displacement add.
 *
 * Semantics: dst = (has_base ? base : 0) +
 *		   (has_index ? index << scale_log2 : 0) + disp.
 */

#include "kinsn_x86_emit.h"

#define KINSN_X86_LEA_FORM_REG		1
#define KINSN_X86_LEA_FORM_ARCH_REG	9

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_leaq(void) {}
__bpf_kfunc void bpf_x86_leal(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_lea_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_leal)
BTF_ID_FLAGS(func, bpf_x86_leaq)
BTF_KFUNCS_END(bpf_x86_lea_kfunc_ids)

static __always_inline int decode_lea_payload(u64 payload,
					      u8 *dst_reg,
					      u8 *base_reg,
					      u8 *index_reg,
					      u8 *scale_log2,
					      bool *has_base,
					      bool *has_index,
					      bool *arch_reg,
					      s32 *disp)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != KINSN_X86_LEA_FORM_REG &&
	    (payload & 0xf) != KINSN_X86_LEA_FORM_ARCH_REG)
		return -EINVAL;

	*arch_reg = (payload & 0xf) == KINSN_X86_LEA_FORM_ARCH_REG;
	*dst_reg = kinsn_payload_reg(payload, 4);
	*base_reg = kinsn_payload_reg(payload, 8);
	*index_reg = kinsn_payload_reg(payload, 12);
	*scale_log2 = (payload >> 16) & 0x3;
	*has_index = (payload >> 18) & 1;
	*has_base = (payload >> 19) & 1;
	*disp = (s32)((u32)(payload >> 20));

	if (payload >> 52)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg))
		return -EINVAL;
	if (*has_base) {
		if (!kinsn_x86_operand_valid(*base_reg))
			return -EINVAL;
	} else {
		if (*base_reg)
			return -EINVAL;
	}
	if (*has_index) {
		if (!kinsn_x86_operand_valid(*index_reg))
			return -EINVAL;
	} else {
		if (*index_reg || *scale_log2)
			return -EINVAL;
	}
	return 0;
}

static __always_inline struct bpf_insn lea_mov(u8 width, u8 dst, u8 src)
{
	return width == 64 ? BPF_MOV64_REG(dst, src) : BPF_MOV32_REG(dst, src);
}

static __always_inline struct bpf_insn lea_mov_imm(u8 width, u8 dst, s32 imm)
{
	return width == 64 ? BPF_MOV64_IMM(dst, imm) : BPF_MOV32_IMM(dst, imm);
}

static __always_inline struct bpf_insn lea_alu_imm(u8 width, u8 op, u8 dst,
						   s32 imm)
{
	return width == 64 ? BPF_ALU64_IMM(op, dst, imm) :
			     BPF_ALU32_IMM(op, dst, imm);
}

static __always_inline struct bpf_insn lea_alu_reg(u8 width, u8 op, u8 dst,
						   u8 src)
{
	return width == 64 ? BPF_ALU64_REG(op, dst, src) :
			     BPF_ALU32_REG(op, dst, src);
}

static int instantiate_lea_shadow(struct bpf_insn *insn_buf, u8 width,
				  u8 dst_reg, u8 base_reg, u8 index_reg,
				  u8 scale_log2, bool has_base,
				  bool has_index, bool arch_reg, s32 disp)
{
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (has_base && has_index) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt,
					      KINSN_X86_SCRATCH1,
					      index_reg);
		else if (kinsn_x86_reg_is_shadowed(index_reg))
			kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1,
					  index_reg);
		else
			insn_buf[cnt++] = lea_mov(width, KINSN_X86_SCRATCH1,
						  index_reg);
	}

	if (has_base) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt,
					      KINSN_X86_SCRATCH0,
					      base_reg);
		else if (kinsn_x86_reg_is_shadowed(base_reg))
			kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
					  base_reg);
		else
			insn_buf[cnt++] = lea_mov(width, KINSN_X86_SCRATCH0,
						  base_reg);
	} else if (has_index) {
		if (arch_reg)
			kinsn_x86_read64_arch(insn_buf, &cnt,
					      KINSN_X86_SCRATCH0,
					      index_reg);
		else if (kinsn_x86_reg_is_shadowed(index_reg))
			kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
					  index_reg);
		else
			insn_buf[cnt++] = lea_mov(width, KINSN_X86_SCRATCH0,
						  index_reg);
		if (scale_log2)
			insn_buf[cnt++] = lea_alu_imm(width, BPF_LSH,
						      KINSN_X86_SCRATCH0,
						      scale_log2);
	} else {
		insn_buf[cnt++] = lea_mov_imm(width, KINSN_X86_SCRATCH0, disp);
	}

	if (has_base && has_index) {
		if (scale_log2) {
			insn_buf[cnt++] = lea_alu_imm(width, BPF_LSH,
						      KINSN_X86_SCRATCH1,
						      scale_log2);
		}
		insn_buf[cnt++] = lea_alu_reg(width, BPF_ADD,
					      KINSN_X86_SCRATCH0,
					      KINSN_X86_SCRATCH1);
	}

	if (disp && (has_base || has_index))
		insn_buf[cnt++] = lea_alu_imm(width, BPF_ADD,
					      KINSN_X86_SCRATCH0, disp);
	if (width == 32)
		insn_buf[cnt++] = BPF_MOV32_REG(KINSN_X86_SCRATCH0,
						KINSN_X86_SCRATCH0);
	if (width == 32 && arch_reg)
		kinsn_x86_write32_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else if (width == 32)
		kinsn_x86_write32(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	else if (arch_reg)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_lea64(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool has_base, has_index, arch_reg;
	s32 disp;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_lea_payload(payload, &dst_reg, &base_reg, &index_reg,
				 &scale_log2, &has_base, &has_index,
				 &arch_reg, &disp);
	if (err)
		return err;
	if (arch_reg ||
	    kinsn_x86_reg_is_shadowed(dst_reg) ||
	    (has_base && kinsn_x86_reg_is_shadowed(base_reg)) ||
	    (has_index && kinsn_x86_reg_is_shadowed(index_reg)))
		return instantiate_lea_shadow(insn_buf, 64, dst_reg, base_reg,
					      index_reg, scale_log2, has_base,
					      has_index, arch_reg, disp);

	if (has_base && has_index && dst_reg == index_reg && dst_reg != base_reg) {
		if (scale_log2)
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, scale_log2);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, base_reg);
	} else if (has_base) {
		if (dst_reg != base_reg)
			insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, base_reg);
		if (has_index) {
			if (dst_reg == index_reg && scale_log2) {
				insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MUL, dst_reg,
								(1 << scale_log2) + 1);
			} else {
				add_count = 1 << scale_log2;
				while (add_count--)
					insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg,
									index_reg);
			}
		}
	} else if (has_index) {
		if (dst_reg != index_reg)
			insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, index_reg);
		if (scale_log2)
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, scale_log2);
	} else if (!has_base) {
		insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, disp);
	}

	if (disp && (has_base || has_index))
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, dst_reg, disp);
	if (!cnt)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, dst_reg);

	return cnt;
}

static int instantiate_lea32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool has_base, has_index, arch_reg;
	s32 disp;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_lea_payload(payload, &dst_reg, &base_reg, &index_reg,
				 &scale_log2, &has_base, &has_index,
				 &arch_reg, &disp);
	if (err)
		return err;
	if (arch_reg ||
	    kinsn_x86_reg_is_shadowed(dst_reg) ||
	    (has_base && kinsn_x86_reg_is_shadowed(base_reg)) ||
	    (has_index && kinsn_x86_reg_is_shadowed(index_reg)))
		return instantiate_lea_shadow(insn_buf, 32, dst_reg, base_reg,
					      index_reg, scale_log2, has_base,
					      has_index, arch_reg, disp);

	if (has_base && has_index && dst_reg == base_reg && dst_reg == index_reg) {
		insn_buf[cnt++] = BPF_ALU32_IMM(BPF_MUL, dst_reg, (1 << scale_log2) + 1);
	} else if (has_base && (!has_index || dst_reg != index_reg)) {
		if (dst_reg != base_reg)
			insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, base_reg);
		if (has_index) {
			add_count = 1 << scale_log2;
			while (add_count--)
				insn_buf[cnt++] = BPF_ALU32_REG(BPF_ADD, dst_reg, index_reg);
		}
	} else if (has_index) {
		if (dst_reg != index_reg)
			insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, index_reg);
		if (scale_log2)
			insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, dst_reg, scale_log2);
		if (has_base)
			insn_buf[cnt++] = BPF_ALU32_REG(BPF_ADD, dst_reg, base_reg);
	} else if (!has_base) {
		insn_buf[cnt++] = BPF_MOV32_IMM(dst_reg, disp);
	}

	if (disp && (has_base || has_index))
		insn_buf[cnt++] = BPF_ALU32_IMM(BPF_ADD, dst_reg, disp);
	if (!cnt)
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, dst_reg);

	return cnt;
}

static void emit_lea(u8 *buf, u32 *len, bool is64,
		     u8 dst_reg, u8 base_reg, u8 index_reg,
		     u8 scale_log2, bool has_base, bool has_index, s32 disp)
{
	u8 base_code = has_base ? kinsn_x86_code(base_reg) : 5;
	u8 index_code = has_index ? kinsn_x86_code(index_reg) : 4;
	u8 mod;

	kinsn_emit_rex(buf, len, is64, kinsn_x86_ext(dst_reg),
		       has_index && kinsn_x86_ext(index_reg),
		       has_base && kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, len, 0x8D);

	if (has_base && !has_index) {
		u8 rm = base_code == 4 ? 4 : base_code;

		if (!disp && base_code != 5)
			mod = 0x00;
		else if (disp >= -128 && disp <= 127)
			mod = 0x40;
		else
			mod = 0x80;

		kinsn_emit_u8(buf, len, mod | (kinsn_x86_code(dst_reg) << 3) | rm);
		if (base_code == 4)
			kinsn_emit_u8(buf, len, (4 << 3) | base_code);
		if (mod == 0x40)
			kinsn_emit_u8(buf, len, (u8)disp);
		else if (mod == 0x80)
			kinsn_emit_s32(buf, len, disp);
		return;
	}

	if (!has_base)
		mod = 0x00;
	else if (!disp && base_code != 5)
		mod = 0x00;
	else if (disp >= -128 && disp <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	kinsn_emit_u8(buf, len, mod | (kinsn_x86_code(dst_reg) << 3) | 0x04);
	kinsn_emit_u8(buf, len, (scale_log2 << 6) | (index_code << 3) | base_code);
	if (mod == 0x40)
		kinsn_emit_u8(buf, len, (u8)disp);
	else if (mod == 0x80 || !has_base)
		kinsn_emit_s32(buf, len, disp);
}

static int emit_lea_x86(u8 *image, u32 *off, bool emit,
			u64 payload, const struct bpf_prog *prog,
			bool is64)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool has_base, has_index, arch_reg;
	s32 disp;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_lea_payload(payload, &dst_reg, &base_reg, &index_reg,
				 &scale_log2, &has_base, &has_index,
				 &arch_reg, &disp);
	if (err)
		return err;

	if (!arch_reg) {
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
		if (has_base)
			base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
		if (has_index)
			index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	}

	if (!kinsn_x86_valid(dst_reg))
		return -EINVAL;
	if (has_base && !kinsn_x86_valid(base_reg))
		return -EINVAL;
	if (has_index && !kinsn_x86_valid(index_reg))
		return -EINVAL;

	emit_lea(buf, &len, is64, dst_reg, base_reg, index_reg,
		 scale_log2, has_base, has_index, disp);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_lea64_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	return emit_lea_x86(image, off, emit, payload, prog, true);
}

static int emit_lea32_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	return emit_lea_x86(image, off, emit, payload, prog, false);
}

const struct bpf_kinsn bpf_x86_leaq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_lea64,
	.emit_x86 = emit_lea64_x86,
};

const struct bpf_kinsn bpf_x86_leal_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_lea32,
	.emit_x86 = emit_lea32_x86,
};

static const struct bpf_kinsn * const bpf_x86_lea_kinsn_descs[] = {
	&bpf_x86_leal_desc,
	&bpf_x86_leaq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_lea, "BpfReJIT x86 kinsns: LEA",
		       bpf_x86_lea_kfunc_ids, bpf_x86_lea_kinsn_descs);
