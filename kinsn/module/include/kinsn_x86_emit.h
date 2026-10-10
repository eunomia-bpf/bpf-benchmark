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
	if (x86_reg == BPF_REG_10 && prog && prog->aux &&
	    prog->aux->priv_stack_ptr)
		return KINSN_X86_REG_R9;
	return x86_reg;
}

static __always_inline u8 kinsn_x86_code(u8 reg)
{
	return kinsn_x86_reg_code(reg);
}

static __always_inline bool kinsn_x86_ext(u8 reg)
{
	return kinsn_x86_reg_ext(reg);
}

static __always_inline bool kinsn_x86_valid(u8 reg)
{
	return kinsn_x86_reg_valid(reg);
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

#define KINSN_X86_SAVE_RESTORE_INSN_CNT	6

static __always_inline bool kinsn_x86_reg_is_bpf_writable(u8 reg)
{
	return reg < BPF_REG_10;
}

static __always_inline bool kinsn_bpf_gpr_valid(u8 reg)
{
	return reg < BPF_REG_10 && kinsn_x86_reg_valid(reg);
}

static __always_inline bool kinsn_x86_operand_valid(u8 reg)
{
	return reg <= BPF_REG_10 && kinsn_x86_valid(reg);
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
