/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _KINSN_X86_EMIT_H
#define _KINSN_X86_EMIT_H

#include "kinsn_common.h"

static __always_inline s32 kinsn_payload_s32(u64 payload, u8 shift)
{
	payload = kinsn_payload_decode(payload);
	return (s32)((u32)(payload >> shift));
}

static __always_inline u8 kinsn_x86_reg_for_prog(const struct bpf_prog *prog,
						 u8 x86_reg)
{
	(void)prog;
	return x86_reg;
}

static __always_inline u8 kinsn_x86_code(u8 reg)
{
	if (reg == KINSN_X86_REG_R9)
		return 1;
	return kinsn_x86_reg_code(reg);
}

static __always_inline bool kinsn_x86_ext(u8 reg)
{
	if (reg == KINSN_X86_REG_R9)
		return true;
	return kinsn_x86_reg_ext(reg);
}

static __always_inline bool kinsn_x86_valid(u8 reg)
{
	return kinsn_x86_code(reg) != 0xff;
}

static __always_inline bool kinsn_x86_needs_rex8(u8 reg)
{
	switch (reg) {
	case BPF_REG_1:
	case BPF_REG_2:
	case BPF_REG_5:
	case BPF_REG_7:
	case BPF_REG_8:
	case BPF_REG_9:
	case BPF_REG_10:
	case KINSN_X86_REG_R9:
	case KINSN_X86_REG_R10:
	case KINSN_X86_REG_R11:
	case KINSN_X86_REG_R12:
	case KINSN_X86_REG_RSP:
		return true;
	default:
		return false;
	}
}

#define KINSN_X86_SHADOW_RAX_OFF	-512
#define KINSN_X86_SHADOW_RCX_OFF	-504
#define KINSN_X86_SHADOW_RDX_OFF	-496
#define KINSN_X86_SHADOW_RBX_OFF	-488
#define KINSN_X86_SHADOW_RSP_OFF	-480
#define KINSN_X86_SHADOW_RBP_OFF	-472
#define KINSN_X86_SHADOW_RSI_OFF	-464
#define KINSN_X86_SHADOW_RDI_OFF	-456
#define KINSN_X86_SHADOW_R8_OFF		-448
#define KINSN_X86_SHADOW_R9_OFF		-440
#define KINSN_X86_SHADOW_R10_OFF	-432
#define KINSN_X86_SHADOW_R11_OFF	-424
#define KINSN_X86_SHADOW_R12_OFF	-416
#define KINSN_X86_SHADOW_R13_OFF	-408
#define KINSN_X86_SHADOW_R14_OFF	-400
#define KINSN_X86_SHADOW_R15_OFF	-392
#define KINSN_X86_SHADOW_ZF_OFF		-384
#define KINSN_X86_SHADOW_CF_OFF		-380
#define KINSN_X86_SCRATCH_R6_OFF	-376
#define KINSN_X86_SCRATCH_R7_OFF	-368
#define KINSN_X86_SCRATCH_R8_OFF	-360
#define KINSN_X86_SHADOW_GE_OFF		-352
#define KINSN_X86_SHADOW_SF_OFF		-348
#define KINSN_X86_PROOF_LHS_OFF		-344
#define KINSN_X86_PROOF_RHS_OFF		-336

#define KINSN_X86_SCRATCH0		BPF_REG_6
#define KINSN_X86_SCRATCH1		BPF_REG_7
#define KINSN_X86_SCRATCH2		BPF_REG_8
#define KINSN_X86_SCRATCH_MASK(REG)	(1U << (REG))
#define KINSN_X86_SAVE_RESTORE_INSN_CNT	6

static __always_inline bool kinsn_x86_reg_is_shadowed(u8 reg)
{
	return reg <= BPF_REG_10 ||
	       (reg >= KINSN_X86_REG_R9 && reg <= KINSN_X86_REG_RSP);
}

static __always_inline bool kinsn_x86_reg_is_bpf_writable(u8 reg)
{
	return reg < BPF_REG_10;
}

static __always_inline s16 kinsn_x86_shadow_reg_off(u8 reg)
{
	switch (reg) {
	case BPF_REG_0:
		return KINSN_X86_SHADOW_RAX_OFF;
	case BPF_REG_4:
		return KINSN_X86_SHADOW_RCX_OFF;
	case BPF_REG_3:
		return KINSN_X86_SHADOW_RDX_OFF;
	case BPF_REG_6:
		return KINSN_X86_SHADOW_RBX_OFF;
	case KINSN_X86_REG_RSP:
		return KINSN_X86_SHADOW_RSP_OFF;
	case BPF_REG_10:
		return KINSN_X86_SHADOW_RBP_OFF;
	case BPF_REG_2:
		return KINSN_X86_SHADOW_RSI_OFF;
	case BPF_REG_1:
		return KINSN_X86_SHADOW_RDI_OFF;
	case BPF_REG_5:
		return KINSN_X86_SHADOW_R8_OFF;
	case KINSN_X86_REG_R9:
		return KINSN_X86_SHADOW_R9_OFF;
	case KINSN_X86_REG_R10:
		return KINSN_X86_SHADOW_R10_OFF;
	case KINSN_X86_REG_R11:
		return KINSN_X86_SHADOW_R11_OFF;
	case KINSN_X86_REG_R12:
		return KINSN_X86_SHADOW_R12_OFF;
	case BPF_REG_7:
		return KINSN_X86_SHADOW_R13_OFF;
	case BPF_REG_8:
		return KINSN_X86_SHADOW_R14_OFF;
	case BPF_REG_9:
		return KINSN_X86_SHADOW_R15_OFF;
	default:
		return 0;
	}
}

static __always_inline bool kinsn_x86_arch_reg_is_shadowed(u8 reg)
{
	return kinsn_x86_shadow_reg_off(reg) != 0;
}

static __always_inline bool kinsn_x86_is_scratch(u8 reg)
{
	return reg >= KINSN_X86_SCRATCH0 && reg <= KINSN_X86_SCRATCH2;
}

static __always_inline s16 kinsn_x86_scratch_off(u8 reg)
{
	switch (reg) {
	case KINSN_X86_SCRATCH0:
		return KINSN_X86_SCRATCH_R6_OFF;
	case KINSN_X86_SCRATCH1:
		return KINSN_X86_SCRATCH_R7_OFF;
	case KINSN_X86_SCRATCH2:
		return KINSN_X86_SCRATCH_R8_OFF;
	default:
		return 0;
	}
}

static __always_inline u8 kinsn_x86_scratch_avoid(u8 a, u8 b, u8 c)
{
	u8 reg;

	for (reg = KINSN_X86_SCRATCH0; reg <= KINSN_X86_SCRATCH2; reg++) {
		if (reg != a && reg != b && reg != c)
			return reg;
	}
	return KINSN_X86_SCRATCH0;
}

static __always_inline u8 kinsn_x86_scratch_avoid4(u8 a, u8 b, u8 c, u8 d)
{
	u8 reg;

	for (reg = KINSN_X86_SCRATCH0; reg <= KINSN_X86_SCRATCH2; reg++) {
		if (reg != a && reg != b && reg != c && reg != d)
			return reg;
	}
	return KINSN_X86_SCRATCH0;
}

static __always_inline void kinsn_x86_save_scratch(struct bpf_insn *insn_buf,
						   int *cnt, u32 mask)
{
	insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
					 KINSN_X86_SCRATCH0,
					 KINSN_X86_SCRATCH_R6_OFF);
	insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
					 KINSN_X86_SCRATCH1,
					 KINSN_X86_SCRATCH_R7_OFF);
	insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10,
					 KINSN_X86_SCRATCH2,
					 KINSN_X86_SCRATCH_R8_OFF);
	(void)mask;
}

static __always_inline void kinsn_x86_restore_scratch(struct bpf_insn *insn_buf,
						      int *cnt, u32 mask)
{
	insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, KINSN_X86_SCRATCH2,
					 BPF_REG_10,
					 KINSN_X86_SCRATCH_R8_OFF);
	insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, KINSN_X86_SCRATCH1,
					 BPF_REG_10,
					 KINSN_X86_SCRATCH_R7_OFF);
	insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, KINSN_X86_SCRATCH0,
					 BPF_REG_10,
					 KINSN_X86_SCRATCH_R6_OFF);
	(void)mask;
}

static __always_inline void kinsn_x86_read64(struct bpf_insn *insn_buf,
					     int *cnt, u8 dst_reg, u8 src_reg)
{
	if (kinsn_x86_reg_is_shadowed(src_reg))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kinsn_x86_shadow_reg_off(src_reg));
	else if (kinsn_x86_is_scratch(src_reg))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kinsn_x86_scratch_off(src_reg));
	else if (dst_reg != src_reg)
		insn_buf[(*cnt)++] = BPF_MOV64_REG(dst_reg, src_reg);
}

static __always_inline void kinsn_x86_read32(struct bpf_insn *insn_buf,
					     int *cnt, u8 dst_reg, u8 src_reg)
{
	if (kinsn_x86_reg_is_shadowed(src_reg))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kinsn_x86_shadow_reg_off(src_reg));
	else if (kinsn_x86_is_scratch(src_reg))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kinsn_x86_scratch_off(src_reg));
	else if (dst_reg != src_reg)
		insn_buf[(*cnt)++] = BPF_MOV32_REG(dst_reg, src_reg);
}

static __always_inline void kinsn_x86_write64(struct bpf_insn *insn_buf,
					      int *cnt, u8 dst_reg,
					      u8 value_reg, u32 saved_mask)
{
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kinsn_x86_shadow_reg_off(dst_reg));
	else if (kinsn_x86_is_scratch(dst_reg))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kinsn_x86_scratch_off(dst_reg));
	else if (dst_reg != value_reg)
		insn_buf[(*cnt)++] = BPF_MOV64_REG(dst_reg, value_reg);
	if (kinsn_x86_reg_is_bpf_writable(dst_reg) && dst_reg != value_reg)
		insn_buf[(*cnt)++] = BPF_MOV64_REG(dst_reg, value_reg);
	(void)saved_mask;
}

static __always_inline void kinsn_x86_write32(struct bpf_insn *insn_buf,
					      int *cnt, u8 dst_reg,
					      u8 value_reg, u32 saved_mask)
{
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kinsn_x86_shadow_reg_off(dst_reg));
	else if (kinsn_x86_is_scratch(dst_reg))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kinsn_x86_scratch_off(dst_reg));
	else if (dst_reg != value_reg)
		insn_buf[(*cnt)++] = BPF_MOV32_REG(dst_reg, value_reg);
	if (kinsn_x86_reg_is_bpf_writable(dst_reg) && dst_reg != value_reg)
		insn_buf[(*cnt)++] = BPF_MOV32_REG(dst_reg, value_reg);
	(void)saved_mask;
}

static __always_inline void kinsn_x86_read64_arch(struct bpf_insn *insn_buf,
						  int *cnt, u8 dst_reg,
						  u8 src_reg)
{
	if (kinsn_x86_arch_reg_is_shadowed(src_reg))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kinsn_x86_shadow_reg_off(src_reg));
	else
		kinsn_x86_read64(insn_buf, cnt, dst_reg, src_reg);
}

static __always_inline void kinsn_x86_read32_arch(struct bpf_insn *insn_buf,
						  int *cnt, u8 dst_reg,
						  u8 src_reg)
{
	if (kinsn_x86_arch_reg_is_shadowed(src_reg))
		insn_buf[(*cnt)++] = BPF_LDX_MEM(BPF_DW, dst_reg, BPF_REG_10,
						 kinsn_x86_shadow_reg_off(src_reg));
	else
		kinsn_x86_read32(insn_buf, cnt, dst_reg, src_reg);
}

static __always_inline void kinsn_x86_write64_arch(struct bpf_insn *insn_buf,
						   int *cnt, u8 dst_reg,
						   u8 value_reg,
						   u32 saved_mask)
{
	if (kinsn_x86_arch_reg_is_shadowed(dst_reg))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kinsn_x86_shadow_reg_off(dst_reg));
	else
		kinsn_x86_write64(insn_buf, cnt, dst_reg, value_reg,
				  saved_mask);
}

static __always_inline void kinsn_x86_write32_arch(struct bpf_insn *insn_buf,
						   int *cnt, u8 dst_reg,
						   u8 value_reg,
						   u32 saved_mask)
{
	if (kinsn_x86_arch_reg_is_shadowed(dst_reg))
		insn_buf[(*cnt)++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, value_reg,
						 kinsn_x86_shadow_reg_off(dst_reg));
	else
		kinsn_x86_write32(insn_buf, cnt, dst_reg, value_reg,
				  saved_mask);
}

static __always_inline bool kinsn_bpf_gpr_valid(u8 reg)
{
	return reg < BPF_REG_10 && kinsn_x86_reg_valid(reg);
}

static __always_inline bool kinsn_x86_operand_valid(u8 reg)
{
	return kinsn_x86_valid(reg);
}

static __always_inline void kinsn_emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static __always_inline void kinsn_emit_s32(u8 *buf, u32 *len, s32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
}

static __always_inline void kinsn_emit_rex(u8 *buf, u32 *len, bool is64,
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
		kinsn_emit_u8(buf, len, rex);
}

static __always_inline void kinsn_emit_rex_rr(u8 *buf, u32 *len, bool is64,
					      u8 reg, u8 rm)
{
	kinsn_emit_rex(buf, len, is64, kinsn_x86_ext(reg), false,
		       kinsn_x86_ext(rm));
}

static __always_inline void kinsn_emit_rex8(u8 *buf, u32 *len, u8 reg, u8 rm,
					    bool has_reg, bool force_reg,
					    bool force_rm)
{
	u8 rex = 0x40;

	if (has_reg && kinsn_x86_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_ext(rm))
		rex |= 0x01;
	if (rex != 0x40 ||
	    (force_reg && kinsn_x86_needs_rex8(reg)) ||
	    (force_rm && kinsn_x86_needs_rex8(rm)))
		kinsn_emit_u8(buf, len, rex);
}

static __always_inline void kinsn_emit_rex8_rm(u8 *buf, u32 *len, u8 rm)
{
	kinsn_emit_rex8(buf, len, 0, rm, false, false, true);
}

static __always_inline void kinsn_emit_rex8_mem(u8 *buf, u32 *len, u8 base)
{
	kinsn_emit_rex8(buf, len, 0, base, false, false, false);
}

static __always_inline void kinsn_emit_rex8_rr(u8 *buf, u32 *len,
					       u8 reg, u8 rm)
{
	kinsn_emit_rex8(buf, len, reg, rm, true, true, true);
}

static __always_inline int kinsn_emit_finish(u8 *image, u32 *off, bool emit,
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

static __always_inline void kinsn_emit_sib_mem(u8 *buf, u32 *len, u8 reg_field,
					       u8 base_reg, u8 index_reg,
					       u8 scale_log2, s16 offset)
{
	u8 base_code = kinsn_x86_code(base_reg);
	u8 index_code = kinsn_x86_code(index_reg);
	u8 mod;

	if (!offset && base_code != 5)
		mod = 0x00;
	else if (offset >= -128 && offset <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	kinsn_emit_u8(buf, len, mod | (kinsn_x86_code(reg_field) << 3) | 0x04);
	kinsn_emit_u8(buf, len, (scale_log2 << 6) | (index_code << 3) | base_code);
	if (mod == 0x40)
		kinsn_emit_u8(buf, len, (u8)offset);
	else if (mod == 0x80)
		kinsn_emit_s32(buf, len, offset);
}

static __always_inline void kinsn_emit_modrm_mem_raw(u8 *buf, u32 *len,
						     u8 reg_field,
						     u8 base_reg,
						     s16 offset)
{
	u8 base_code = kinsn_x86_code(base_reg);
	u8 mod;

	if (!offset && base_code != 5)
		mod = 0x00;
	else if (offset >= -128 && offset <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	kinsn_emit_u8(buf, len, mod | ((reg_field & 0x7) << 3) | base_code);
	if (base_code == 4)
		kinsn_emit_u8(buf, len, 0x24);
	if (mod == 0x40)
		kinsn_emit_u8(buf, len, (u8)offset);
	else if (mod == 0x80)
		kinsn_emit_s32(buf, len, offset);
}

static __always_inline void kinsn_emit_modrm_mem(u8 *buf, u32 *len,
						 u8 reg_field, u8 base_reg,
						 s16 offset)
{
	kinsn_emit_modrm_mem_raw(buf, len, kinsn_x86_code(reg_field),
				 base_reg, offset);
}

#endif /* _KINSN_X86_EMIT_H */
