// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: BULK_MEMORY — REP MOVSB / REP STOSB for x86-64
 */

#include "kinsn_common.h"

#define KINSN_BULK_MAX_BYTES 128

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_memcpy_bulk(void) {}
__bpf_kfunc void bpf_memset_bulk(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_bulk_memory_kfunc_ids)
BTF_ID_FLAGS(func, bpf_memcpy_bulk)
BTF_ID_FLAGS(func, bpf_memset_bulk)
BTF_KFUNCS_END(bpf_bulk_memory_kfunc_ids)

static __always_inline bool kinsn_bulk_reg_valid(u8 reg)
{
	return reg <= BPF_REG_10;
}

static __always_inline bool kinsn_x86_reg_needs_rex8(u8 bpf_reg)
{
	switch (bpf_reg) {
	case BPF_REG_1:
	case BPF_REG_2:
	case BPF_REG_5:
	case BPF_REG_7:
	case BPF_REG_8:
	case BPF_REG_9:
	case BPF_REG_10:
		return true;
	default:
		return false;
	}
}

static __always_inline u8 kinsn_bulk_width_bytes(u8 width_class)
{
	if (width_class > 3)
		return 0;

	return 1U << width_class;
}

static __always_inline bool kinsn_bulk_offset_range_valid(s16 offset, u8 len)
{
	s32 end;

	if (!len)
		return false;

	end = (s32)offset + (s32)len - 1;
	return end >= S16_MIN && end <= S16_MAX;
}

static __always_inline int decode_memcpy_payload(u64 payload,
						 u8 *dst_base,
						 u8 *src_base,
						 s16 *dst_off,
						 s16 *src_off,
						 u8 *len,
						 u8 *tmp_reg)
{
	*dst_base = kinsn_payload_reg(payload, 0);
	*src_base = kinsn_payload_reg(payload, 4);
	*dst_off = kinsn_payload_s16(payload, 8);
	*src_off = kinsn_payload_s16(payload, 24);
	*len = kinsn_payload_u8(payload, 40) + 1;
	*tmp_reg = kinsn_payload_reg(payload, 48);

	if (payload >> 52)
		return -EINVAL;
	if (*len == 0 || *len > KINSN_BULK_MAX_BYTES)
		return -EINVAL;
	if (!kinsn_bulk_reg_valid(*dst_base) || !kinsn_bulk_reg_valid(*src_base) ||
	    !kinsn_bulk_reg_valid(*tmp_reg))
		return -EINVAL;
	if (*tmp_reg == BPF_REG_10 || *tmp_reg == *dst_base || *tmp_reg == *src_base)
		return -EINVAL;
	if (!kinsn_bulk_offset_range_valid(*dst_off, *len) ||
	    !kinsn_bulk_offset_range_valid(*src_off, *len))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_memset_payload(u64 payload,
						 u8 *dst_base,
						 u8 *val_reg,
						 s16 *dst_off,
						 u8 *len,
						 u8 *width_bytes,
						 bool *value_from_reg,
						 bool *zero_fill,
						 u8 *fill_imm8)
{
	u8 width_class;

	*dst_base = kinsn_payload_reg(payload, 0);
	*val_reg = kinsn_payload_reg(payload, 4);
	*dst_off = kinsn_payload_s16(payload, 8);
	*len = kinsn_payload_u8(payload, 24) + 1;
	width_class = (payload >> 32) & 0x3;
	*value_from_reg = (payload >> 34) & 0x1;
	*zero_fill = (payload >> 35) & 0x1;
	*fill_imm8 = kinsn_payload_u8(payload, 36);
	*width_bytes = kinsn_bulk_width_bytes(width_class);

	if (payload >> 44)
		return -EINVAL;
	if (*len == 0 || *len > KINSN_BULK_MAX_BYTES)
		return -EINVAL;
	if (!kinsn_bulk_reg_valid(*dst_base))
		return -EINVAL;
	if (*value_from_reg && !kinsn_bulk_reg_valid(*val_reg))
		return -EINVAL;
	if (!*width_bytes || *len % *width_bytes)
		return -EINVAL;
	if (!kinsn_bulk_offset_range_valid(*dst_off, *len))
		return -EINVAL;
	if (*zero_fill && *fill_imm8)
		return -EINVAL;

	return 0;
}

static int instantiate_memcpy(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_base, src_base, len, tmp_reg;
	s16 dst_off, src_off;
	int err;
	int i;
	int cnt = 0;

	err = decode_memcpy_payload(payload, &dst_base, &src_base,
				    &dst_off, &src_off, &len, &tmp_reg);
	if (err)
		return err;

	for (i = 0; i < len; i++) {
		insn_buf[cnt++] = BPF_LDX_MEM(BPF_B, tmp_reg, src_base, src_off + i);
		insn_buf[cnt++] = BPF_STX_MEM(BPF_B, dst_base, tmp_reg, dst_off + i);
	}

	return cnt;
}

static int instantiate_memset(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_base, val_reg, len, width_bytes, fill_imm8;
	s16 dst_off;
	bool value_from_reg, zero_fill;
	int err;
	int i;
	int cnt = 0;
	u8 fill = 0;

	err = decode_memset_payload(payload, &dst_base, &val_reg, &dst_off, &len,
				    &width_bytes, &value_from_reg, &zero_fill,
				    &fill_imm8);
	if (err)
		return err;
	(void)width_bytes;

	if (!zero_fill)
		fill = fill_imm8;

	for (i = 0; i < len; i++) {
		if (value_from_reg && !zero_fill)
			insn_buf[cnt++] = BPF_STX_MEM(BPF_B, dst_base, val_reg,
						      dst_off + i);
		else
			insn_buf[cnt++] = BPF_ST_MEM(BPF_B, dst_base, dst_off + i,
						     fill);
	}

	return cnt;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_s32(u8 *buf, u32 *len, s32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
}

static void emit_rex(u8 *buf, u32 *len, bool is64, bool reg_ext, bool rm_ext)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (reg_ext)
		rex |= 0x04;
	if (rm_ext)
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_rex_rm8(u8 *buf, u32 *len, bool reg_ext, u8 rm_reg)
{
	u8 rex = 0x40;

	if (reg_ext)
		rex |= 0x04;
	if (kinsn_x86_reg_ext(rm_reg))
		rex |= 0x01;
	if (reg_ext || kinsn_x86_reg_needs_rex8(rm_reg))
		emit_u8(buf, len, rex);
}

static void emit_mem_modrm(u8 *buf, u32 *len, u8 reg_field, u8 base_reg,
			   s16 offset)
{
	u8 modrm;
	u8 mod;

	if (!offset && base_reg != BPF_REG_10 && base_reg != BPF_REG_7) {
		modrm = (kinsn_x86_reg_code(reg_field) << 3) |
			kinsn_x86_reg_code(base_reg);
		emit_u8(buf, len, modrm);
		return;
	}

	if (offset >= -128 && offset <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	modrm = mod |
		(kinsn_x86_reg_code(reg_field) << 3) |
		kinsn_x86_reg_code(base_reg);
	emit_u8(buf, len, modrm);
	if (mod == 0x40)
		emit_u8(buf, len, (u8)offset);
	else
		emit_s32(buf, len, offset);
}

static void emit_push_reg(u8 *buf, u32 *len, u8 reg)
{
	if (kinsn_x86_reg_ext(reg))
		emit_u8(buf, len, 0x41);
	emit_u8(buf, len, 0x50 + kinsn_x86_reg_code(reg));
}

static void emit_pop_reg(u8 *buf, u32 *len, u8 reg)
{
	if (kinsn_x86_reg_ext(reg))
		emit_u8(buf, len, 0x41);
	emit_u8(buf, len, 0x58 + kinsn_x86_reg_code(reg));
}

static void emit_mov_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	emit_rex(buf, len, true, kinsn_x86_reg_ext(src_reg),
		 kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0x89);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(src_reg) << 3) |
		kinsn_x86_reg_code(dst_reg));
}

static void emit_mov32_imm(u8 *buf, u32 *len, u8 dst_reg, u32 imm32)
{
	if (kinsn_x86_reg_ext(dst_reg))
		emit_u8(buf, len, 0x41);
	emit_u8(buf, len, 0xB8 + kinsn_x86_reg_code(dst_reg));
	memcpy(buf + *len, &imm32, sizeof(imm32));
	*len += sizeof(imm32);
}

static void emit_xor32_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	emit_rex(buf, len, false, kinsn_x86_reg_ext(src_reg),
		 kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0x31);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(src_reg) << 3) |
		kinsn_x86_reg_code(dst_reg));
}

static void emit_lea(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg, s16 offset)
{
	emit_rex(buf, len, true, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x8D);
	emit_mem_modrm(buf, len, dst_reg, base_reg, offset);
}

static void emit_addr_setup(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg, s16 offset)
{
	if (!offset) {
		if (dst_reg != base_reg)
			emit_mov_rr(buf, len, dst_reg, base_reg);
		return;
	}

	emit_lea(buf, len, dst_reg, base_reg, offset);
}

static void emit_movzx_r32_from_rm8(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	emit_rex_rm8(buf, len, kinsn_x86_reg_ext(dst_reg), src_reg);
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xB6);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));
}

static void emit_movzx_r32_from_mem8(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg,
				     s16 offset)
{
	emit_rex(buf, len, false, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xB6);
	emit_mem_modrm(buf, len, dst_reg, base_reg, offset);
}

static void emit_rep_movsb(u8 *buf, u32 *len)
{
	emit_u8(buf, len, 0xF3);
	emit_u8(buf, len, 0xA4);
}

static void emit_rep_stosb(u8 *buf, u32 *len)
{
	emit_u8(buf, len, 0xF3);
	emit_u8(buf, len, 0xAA);
}

static int emit_memcpy_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	u8 buf[48];
	u8 dst_base, src_base, len, tmp_reg;
	s16 dst_off, src_off;
	bool save_rdi, save_rsi, save_rcx;
	u32 len_bytes = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_memcpy_payload(payload, &dst_base, &src_base, &dst_off, &src_off,
				    &len, &tmp_reg);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_base) || !kinsn_x86_reg_valid(src_base) ||
	    !kinsn_x86_reg_valid(tmp_reg))
		return -EINVAL;

	save_rdi = tmp_reg != BPF_REG_1;
	save_rsi = tmp_reg != BPF_REG_2;
	save_rcx = tmp_reg != BPF_REG_4;

	if (save_rdi)
		emit_push_reg(buf, &len_bytes, BPF_REG_1);
	if (save_rsi)
		emit_push_reg(buf, &len_bytes, BPF_REG_2);
	if (save_rcx)
		emit_push_reg(buf, &len_bytes, BPF_REG_4);

	emit_addr_setup(buf, &len_bytes, BPF_REG_1, dst_base, dst_off);
	emit_addr_setup(buf, &len_bytes, BPF_REG_2, src_base, src_off);
	emit_mov32_imm(buf, &len_bytes, BPF_REG_4, len);
	emit_rep_movsb(buf, &len_bytes);
	emit_movzx_r32_from_mem8(buf, &len_bytes, tmp_reg, BPF_REG_2, -1);

	if (save_rcx)
		emit_pop_reg(buf, &len_bytes, BPF_REG_4);
	if (save_rsi)
		emit_pop_reg(buf, &len_bytes, BPF_REG_2);
	if (save_rdi)
		emit_pop_reg(buf, &len_bytes, BPF_REG_1);

	if (emit)
		memcpy(image + *off, buf, len_bytes);
	*off += len_bytes;
	return len_bytes;
}

static int emit_memset_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	u8 buf[48];
	u8 dst_base, val_reg, len, width_bytes, fill_imm8;
	s16 dst_off;
	bool value_from_reg, zero_fill;
	u32 len_bytes = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_memset_payload(payload, &dst_base, &val_reg, &dst_off, &len,
				    &width_bytes, &value_from_reg, &zero_fill,
				    &fill_imm8);
	if (err)
		return err;
	(void)width_bytes;
	if (!kinsn_x86_reg_valid(dst_base) ||
	    (value_from_reg && !kinsn_x86_reg_valid(val_reg)))
		return -EINVAL;

	emit_push_reg(buf, &len_bytes, BPF_REG_1);
	emit_push_reg(buf, &len_bytes, BPF_REG_4);
	emit_push_reg(buf, &len_bytes, BPF_REG_0);

	if (zero_fill)
		emit_xor32_rr(buf, &len_bytes, BPF_REG_0, BPF_REG_0);
	else if (value_from_reg)
		emit_movzx_r32_from_rm8(buf, &len_bytes, BPF_REG_0, val_reg);
	else
		emit_mov32_imm(buf, &len_bytes, BPF_REG_0, fill_imm8);
	emit_addr_setup(buf, &len_bytes, BPF_REG_1, dst_base, dst_off);
	emit_mov32_imm(buf, &len_bytes, BPF_REG_4, len);
	emit_rep_stosb(buf, &len_bytes);

	emit_pop_reg(buf, &len_bytes, BPF_REG_0);
	emit_pop_reg(buf, &len_bytes, BPF_REG_4);
	emit_pop_reg(buf, &len_bytes, BPF_REG_1);

	if (emit)
		memcpy(image + *off, buf, len_bytes);
	*off += len_bytes;
	return len_bytes;
}

const struct bpf_kinsn bpf_memcpy_bulk_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = KINSN_BULK_MAX_BYTES * 2,
	.max_emit_bytes = 48,
	.instantiate_insn = instantiate_memcpy,
	.emit_x86 = emit_memcpy_x86,
};

const struct bpf_kinsn bpf_memset_bulk_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = KINSN_BULK_MAX_BYTES,
	.max_emit_bytes = 48,
	.instantiate_insn = instantiate_memset,
	.emit_x86 = emit_memset_x86,
};

static const struct bpf_kinsn * const bpf_bulk_memory_kinsn_descs[] = {
	&bpf_memcpy_bulk_desc,
	&bpf_memset_bulk_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_bulk_memory,
		       "BpfReJIT kinsn: BULK_MEMORY (REP MOVSB/STOSB)",
		       bpf_bulk_memory_kfunc_ids,
		       bpf_bulk_memory_kinsn_descs);
