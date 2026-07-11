/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _KOP_X86_EMIT_H
#define _KOP_X86_EMIT_H

#include "kop_common.h"

static __always_inline s32 kop_payload_s32(u64 payload, u8 shift)
{
	payload = kop_payload_decode(payload);
	return (s32)((u32)(payload >> shift));
}

static __always_inline u8 kop_x86_reg_for_prog(const struct bpf_prog *prog,
							 u8 x86_reg)
{
	if (x86_reg == BPF_REG_10 && prog && prog->aux &&
	    prog->aux->priv_stack_ptr)
		return KOP_X86_REG_R9;
	return x86_reg;
}

static __always_inline u8 kop_x86_code(u8 reg)
{
	return kop_x86_reg_code(reg);
}

static __always_inline bool kop_x86_ext(u8 reg)
{
	return kop_x86_reg_ext(reg);
}

static __always_inline bool kop_x86_valid(u8 reg)
{
	return kop_x86_reg_valid(reg);
}

static __always_inline bool kop_x86_needs_rex8(u8 reg)
{
	switch (reg) {
	case BPF_REG_1:
	case BPF_REG_2:
	case BPF_REG_5:
	case BPF_REG_7:
	case BPF_REG_8:
	case BPF_REG_9:
	case BPF_REG_10:
	case KOP_X86_REG_R9:
	case KOP_X86_REG_R10:
	case KOP_X86_REG_R11:
	case KOP_X86_REG_R12:
	case KOP_X86_REG_RSP:
		return true;
	default:
		return false;
	}
}

#define KOP_X86_SCRATCH_R6_OFF	-40
#define KOP_X86_SCRATCH_R7_OFF	-32
#define KOP_X86_SCRATCH_R8_OFF	-24
#define KOP_X86_PROOF_LHS_OFF		-16
#define KOP_X86_PROOF_RHS_OFF		-8
#define KOP_X86_STACK_BYTES		40

#define KOP_X86_SCRATCH0		BPF_REG_6
#define KOP_X86_SCRATCH1		BPF_REG_7
#define KOP_X86_SCRATCH2		BPF_REG_8
#define KOP_X86_SCRATCH_MASK(REG)	(1U << (REG))
#define KOP_X86_SAVE_RESTORE_INSN_CNT	6

static __always_inline bool kop_x86_reg_is_bpf_writable(u8 reg)
{
	return reg < BPF_REG_10;
}

static __always_inline bool kop_x86_is_scratch(u8 reg)
{
	return reg >= KOP_X86_SCRATCH0 && reg <= KOP_X86_SCRATCH2;
}

static __always_inline bool kop_x86_reg_uses_stack_slot(u8 reg)
{
	(void)reg;
	return false;
}

static __always_inline bool kop_x86_arch_reg_uses_stack_slot(u8 reg)
{
	return kop_x86_is_scratch(reg);
}

static __always_inline s16 kop_x86_scratch_off(u8 reg)
{
	switch (reg) {
	case KOP_X86_SCRATCH0:
		return KOP_X86_SCRATCH_R6_OFF;
	case KOP_X86_SCRATCH1:
		return KOP_X86_SCRATCH_R7_OFF;
	case KOP_X86_SCRATCH2:
		return KOP_X86_SCRATCH_R8_OFF;
	default:
		return 0;
	}
}

static __always_inline u8 kop_x86_scratch_avoid(u8 a, u8 b, u8 c)
{
	u8 reg;

	for (reg = KOP_X86_SCRATCH0; reg <= KOP_X86_SCRATCH2; reg++) {
		if (reg != a && reg != b && reg != c)
			return reg;
	}
	return KOP_X86_SCRATCH0;
}

static __always_inline u8 kop_x86_scratch_avoid4(u8 a, u8 b, u8 c, u8 d)
{
	u8 reg;

	for (reg = KOP_X86_SCRATCH0; reg <= KOP_X86_SCRATCH2; reg++) {
		if (reg != a && reg != b && reg != c && reg != d)
			return reg;
	}
	return KOP_X86_SCRATCH0;
}

static __always_inline void kop_x86_save_scratch(struct bpf_insn *insn_buf,
						   int *cnt, u32 mask)
{
	if (mask & KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
						 KOP_X86_SCRATCH0,
						 KOP_X86_SCRATCH_R6_OFF);
	if (mask & KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
						 KOP_X86_SCRATCH1,
						 KOP_X86_SCRATCH_R7_OFF);
	if (mask & KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH2))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
						 KOP_X86_SCRATCH2,
						 KOP_X86_SCRATCH_R8_OFF);
}

static __always_inline void kop_x86_restore_scratch(struct bpf_insn *insn_buf,
						      int *cnt, u32 mask)
{
	if (mask & KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH2))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, KOP_X86_SCRATCH2,
						 BPF_REG_10,
						 KOP_X86_SCRATCH_R8_OFF);
	if (mask & KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, KOP_X86_SCRATCH1,
						 BPF_REG_10,
						 KOP_X86_SCRATCH_R7_OFF);
	if (mask & KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, KOP_X86_SCRATCH0,
						 BPF_REG_10,
						 KOP_X86_SCRATCH_R6_OFF);
}

static __always_inline void kop_x86_read(struct bpf_insn *insn_buf,
					   int *cnt, u8 dst_reg, u8 src_reg,
					   bool width64, bool arch_regs)
{
	bool stacked = arch_regs ? kop_x86_arch_reg_uses_stack_slot(src_reg) :
				   kop_x86_reg_uses_stack_slot(src_reg);

	if (stacked)
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kop_x86_scratch_off(src_reg));
	else if (dst_reg != src_reg) {
		if (width64)
			insn_buf[(*cnt)++] = BPF_MOV64_REG(dst_reg, src_reg);
		else
			insn_buf[(*cnt)++] = BPF_MOV32_REG(dst_reg, src_reg);
	}
}

static __always_inline void kop_x86_read64(struct bpf_insn *insn_buf,
					     int *cnt, u8 dst_reg, u8 src_reg)
{
	kop_x86_read(insn_buf, cnt, dst_reg, src_reg, true, false);
}

static __always_inline void kop_x86_read32(struct bpf_insn *insn_buf,
					     int *cnt, u8 dst_reg, u8 src_reg)
{
	kop_x86_read(insn_buf, cnt, dst_reg, src_reg, false, false);
}

static __always_inline void kop_x86_write(struct bpf_insn *insn_buf,
					      int *cnt, u8 dst_reg,
					      u8 value_reg, u32 saved_mask,
					      bool width64, bool arch_regs)
{
	bool stacked = arch_regs ? kop_x86_arch_reg_uses_stack_slot(dst_reg) :
				   kop_x86_reg_uses_stack_slot(dst_reg);

	if (stacked)
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kop_x86_scratch_off(dst_reg));
	else if (dst_reg != value_reg) {
		if (width64)
			insn_buf[(*cnt)++] = BPF_MOV64_REG(dst_reg, value_reg);
		else
			insn_buf[(*cnt)++] = BPF_MOV32_REG(dst_reg, value_reg);
	}
	(void)saved_mask;
}

static __always_inline void kop_x86_write64(struct bpf_insn *insn_buf,
					      int *cnt, u8 dst_reg,
					      u8 value_reg, u32 saved_mask)
{
	kop_x86_write(insn_buf, cnt, dst_reg, value_reg, saved_mask, true,
			false);
}

static __always_inline void kop_x86_write32(struct bpf_insn *insn_buf,
					      int *cnt, u8 dst_reg,
					      u8 value_reg, u32 saved_mask)
{
	kop_x86_write(insn_buf, cnt, dst_reg, value_reg, saved_mask, false,
			false);
}

static __always_inline void kop_x86_read64_arch(struct bpf_insn *insn_buf,
						  int *cnt, u8 dst_reg,
						  u8 src_reg)
{
	kop_x86_read(insn_buf, cnt, dst_reg, src_reg, true, true);
}

static __always_inline void kop_x86_read32_arch(struct bpf_insn *insn_buf,
						  int *cnt, u8 dst_reg,
						  u8 src_reg)
{
	kop_x86_read(insn_buf, cnt, dst_reg, src_reg, false, true);
}

static __always_inline void kop_x86_write64_arch(struct bpf_insn *insn_buf,
						   int *cnt, u8 dst_reg,
						   u8 value_reg,
						   u32 saved_mask)
{
	kop_x86_write(insn_buf, cnt, dst_reg, value_reg, saved_mask, true,
			true);
}

static __always_inline void kop_x86_write32_arch(struct bpf_insn *insn_buf,
						   int *cnt, u8 dst_reg,
						   u8 value_reg,
						   u32 saved_mask)
{
	kop_x86_write(insn_buf, cnt, dst_reg, value_reg, saved_mask, false,
			true);
}

static __always_inline bool kop_bpf_gpr_valid(u8 reg)
{
	return reg < BPF_REG_10 && kop_x86_reg_valid(reg);
}

static __always_inline bool kop_x86_operand_valid(u8 reg)
{
	return reg <= BPF_REG_10 && kop_x86_valid(reg);
}

static __always_inline void kop_emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static __always_inline void kop_emit_s32(u8 *buf, u32 *len, s32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
}

static __always_inline void kop_emit_rex(u8 *buf, u32 *len, bool is64,
					   bool reg_ext, bool index_ext,
					   bool base_ext)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (reg_ext)
		rex |= 0x04;
	if (index_ext)
		rex |= 0x02;
	if (base_ext)
		rex |= 0x01;
	if (rex != 0x40)
		kop_emit_u8(buf, len, rex);
}

static __always_inline void kop_emit_rex_rr(u8 *buf, u32 *len, bool is64,
					      u8 reg, u8 rm)
{
	kop_emit_rex(buf, len, is64, kop_x86_ext(reg), false,
		       kop_x86_ext(rm));
}

static __always_inline void kop_emit_rex8(u8 *buf, u32 *len, u8 reg, u8 rm,
					    bool has_reg, bool force_reg,
					    bool force_rm)
{
	u8 rex = 0x40;

	if (has_reg && kop_x86_ext(reg))
		rex |= 0x04;
	if (kop_x86_ext(rm))
		rex |= 0x01;
	if (rex != 0x40 ||
	    (force_reg && kop_x86_needs_rex8(reg)) ||
	    (force_rm && kop_x86_needs_rex8(rm)))
		kop_emit_u8(buf, len, rex);
}

static __always_inline void kop_emit_rex8_rm(u8 *buf, u32 *len, u8 rm)
{
	kop_emit_rex8(buf, len, 0, rm, false, false, true);
}

static __always_inline void kop_emit_rex8_mem(u8 *buf, u32 *len, u8 base)
{
	kop_emit_rex8(buf, len, 0, base, false, false, false);
}

static __always_inline void kop_emit_rex8_rr(u8 *buf, u32 *len,
					       u8 reg, u8 rm)
{
	kop_emit_rex8(buf, len, reg, rm, true, true, true);
}

static __always_inline int kop_emit_finish(u8 *image, u32 *off, bool emit,
					     u8 *buf, u32 len)
{
	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;
	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static __always_inline void kop_emit_sib_mem(u8 *buf, u32 *len, u8 reg_field,
					       u8 base_reg, u8 index_reg,
					       u8 scale_log2, s16 offset)
{
	u8 base_code = kop_x86_code(base_reg);
	u8 index_code = kop_x86_code(index_reg);
	u8 mod;

	if (!offset && base_code != 5)
		mod = 0x00;
	else if (offset >= -128 && offset <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	kop_emit_u8(buf, len, mod | (kop_x86_code(reg_field) << 3) | 0x04);
	kop_emit_u8(buf, len, (scale_log2 << 6) | (index_code << 3) | base_code);
	if (mod == 0x40)
		kop_emit_u8(buf, len, (u8)offset);
	else if (mod == 0x80)
		kop_emit_s32(buf, len, offset);
}

static __always_inline void kop_emit_modrm_mem_raw(u8 *buf, u32 *len,
						     u8 reg_field,
						     u8 base_reg,
						     s16 offset)
{
	u8 base_code = kop_x86_code(base_reg);
	u8 mod;

	if (!offset && base_code != 5)
		mod = 0x00;
	else if (offset >= -128 && offset <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	kop_emit_u8(buf, len, mod | ((reg_field & 0x7) << 3) | base_code);
	if (base_code == 4)
		kop_emit_u8(buf, len, 0x24);
	if (mod == 0x40)
		kop_emit_u8(buf, len, (u8)offset);
	else if (mod == 0x80)
		kop_emit_s32(buf, len, offset);
}

static __always_inline void kop_emit_modrm_mem(u8 *buf, u32 *len,
						 u8 reg_field, u8 base_reg,
						 s16 offset)
{
	kop_emit_modrm_mem_raw(buf, len, kop_x86_code(reg_field),
				 base_reg, offset);
}

#endif /* _KOP_X86_EMIT_H */
