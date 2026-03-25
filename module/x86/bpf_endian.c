// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ENDIAN_LOAD — fused load-and-byte-swap for x86-64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_endian_load16(void) {}
__bpf_kfunc void bpf_endian_load32(void) {}
__bpf_kfunc void bpf_endian_load64(void) {}
__bpf_kfunc_end_defs();

static __always_inline int decode_endian_payload(u64 payload,
						 u8 *dst_reg,
						 u8 *base_reg,
						 s16 *offset)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);

	if (*dst_reg > BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_endian(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg;
	u8 bits;
	s16 offset;
	int err;

	err = decode_endian_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;
	bits = kinsn_bpf_size_bits(size);
	if (!bits)
		return -EINVAL;

	insn_buf[0] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
	insn_buf[1] = BPF_BSWAP(dst_reg, bits);
	return 2;
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

static void emit_load16_zx(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg,
			   s16 offset)
{
	emit_rex(buf, len, false, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xB7);
	emit_mem_modrm(buf, len, dst_reg, base_reg, offset);
}

static void emit_load32(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg, s16 offset)
{
	emit_rex(buf, len, false, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x8B);
	emit_mem_modrm(buf, len, dst_reg, base_reg, offset);
}

static void emit_load64(u8 *buf, u32 *len, u8 dst_reg, u8 base_reg, s16 offset)
{
	emit_rex(buf, len, true, kinsn_x86_reg_ext(dst_reg),
		 kinsn_x86_reg_ext(base_reg));
	emit_u8(buf, len, 0x8B);
	emit_mem_modrm(buf, len, dst_reg, base_reg, offset);
}

static void emit_rol16_8(u8 *buf, u32 *len, u8 dst_reg)
{
	emit_u8(buf, len, 0x66);
	emit_rex(buf, len, false, false, kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, 0x08);
}

static void emit_bswap32(u8 *buf, u32 *len, u8 dst_reg)
{
	emit_rex(buf, len, false, false, kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xC8 + kinsn_x86_reg_code(dst_reg));
}

static void emit_bswap64(u8 *buf, u32 *len, u8 dst_reg)
{
	emit_rex(buf, len, true, false, kinsn_x86_reg_ext(dst_reg));
	emit_u8(buf, len, 0x0F);
	emit_u8(buf, len, 0xC8 + kinsn_x86_reg_code(dst_reg));
}

static int emit_endian_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_endian_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(base_reg))
		return -EINVAL;

	switch (size) {
	case BPF_H:
		emit_load16_zx(buf, &len, dst_reg, base_reg, offset);
		emit_rol16_8(buf, &len, dst_reg);
		break;
	case BPF_W:
		emit_load32(buf, &len, dst_reg, base_reg, offset);
		emit_bswap32(buf, &len, dst_reg);
		break;
	case BPF_DW:
		emit_load64(buf, &len, dst_reg, base_reg, offset);
		emit_bswap64(buf, &len, dst_reg);
		break;
	default:
		return -EINVAL;
	}

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int instantiate_endian16(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_endian(payload, insn_buf, BPF_H);
}

static int instantiate_endian32(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_endian(payload, insn_buf, BPF_W);
}

static int instantiate_endian64(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_endian(payload, insn_buf, BPF_DW);
}

static int emit_endian16_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	return emit_endian_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_endian32_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	return emit_endian_x86(image, off, emit, payload, prog, BPF_W);
}

static int emit_endian64_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	return emit_endian_x86(image, off, emit, payload, prog, BPF_DW);
}

const struct bpf_kinsn bpf_endian_load16_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_endian16,
	.emit_x86 = emit_endian16_x86,
};

const struct bpf_kinsn bpf_endian_load32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_endian32,
	.emit_x86 = emit_endian32_x86,
};

const struct bpf_kinsn bpf_endian_load64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_endian64,
	.emit_x86 = emit_endian64_x86,
};

DEFINE_KINSN_V2_MODULE(bpf_endian, "BpfReJIT kinsn: ENDIAN_LOAD");
