// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: BITFIELD_EXTRACT — bit-field extraction for x86-64
 */

#include "kinsn_common.h"

static __always_inline int decode_extract_payload(u64 payload,
						  u8 *dst_reg,
						  u8 *start,
						  u8 *bit_len)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*start = kinsn_payload_u8(payload, 8);
	*bit_len = kinsn_payload_u8(payload, 16);

	if (*dst_reg > BPF_REG_10)
		return -EINVAL;
	if (*start >= 64 || !*bit_len || *bit_len > 32 || *start + *bit_len > 64)
		return -EINVAL;

	return 0;
}

static int instantiate_extract(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, start, bit_len;
	u32 mask;
	int cnt = 0;
	int err;

	err = decode_extract_payload(payload, &dst_reg, &start, &bit_len);
	if (err)
		return err;

	if (start)
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, start);
	mask = bit_len == 32 ? U32_MAX : ((1U << bit_len) - 1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, dst_reg, mask);
	return cnt;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_u32(u8 *buf, u32 *len, u32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
}

static void emit_rex_rr(u8 *buf, u32 *len, bool is64, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (kinsn_x86_reg_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_reg_ext(rm))
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_shr_imm(u8 *buf, u32 *len, u8 dst_reg, u8 imm8)
{
	emit_rex_rr(buf, len, true, 0, dst_reg);
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xE8 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, imm8);
}

static void emit_and_imm32(u8 *buf, u32 *len, u8 dst_reg, u32 imm32)
{
	emit_rex_rr(buf, len, false, 0, dst_reg);
	emit_u8(buf, len, 0x81);
	emit_u8(buf, len, 0xE0 | kinsn_x86_reg_code(dst_reg));
	emit_u32(buf, len, imm32);
}

static int emit_extract_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, start, bit_len;
	u32 mask;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_extract_payload(payload, &dst_reg, &start, &bit_len);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg))
		return -EINVAL;

	mask = bit_len == 32 ? U32_MAX : ((1U << bit_len) - 1);
	if (start)
		emit_shr_imm(buf, &len, dst_reg, start);
	emit_and_imm32(buf, &len, dst_reg, mask);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_extract64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_extract,
	.emit_x86 = emit_extract_x86,
};

DEFINE_KINSN_V2_MODULE(bpf_extract, "BpfReJIT kinsn: BITFIELD_EXTRACT",
		       BPF_KINSN_DESC_ENTRY(bpf_extract64_desc));
