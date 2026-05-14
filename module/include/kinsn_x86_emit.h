/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _KINSN_X86_EMIT_H
#define _KINSN_X86_EMIT_H

#include "kinsn_common.h"

#define KINSN_X86_REG_R9 11

static __always_inline s32 kinsn_payload_s32(u64 payload, u8 shift)
{
	return (s32)((u32)(payload >> shift));
}

static __always_inline bool kinsn_x86_prog_uses_priv_stack(const struct bpf_prog *prog)
{
	return prog && prog->aux && prog->aux->priv_stack_ptr;
}

static __always_inline u8 kinsn_x86_reg_for_prog(const struct bpf_prog *prog,
						 u8 bpf_reg)
{
	if (bpf_reg == BPF_REG_10 && kinsn_x86_prog_uses_priv_stack(prog))
		return KINSN_X86_REG_R9;
	return bpf_reg;
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

#endif /* _KINSN_X86_EMIT_H */
