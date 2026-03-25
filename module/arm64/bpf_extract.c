// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: BITFIELD_EXTRACT - bit-field extraction via UBFM
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

static inline u32 a64_ubfm_x(u8 rd, u8 rn, u8 immr, u8 imms)
{
	return 0xD3400000U |
	       ((u32)immr << 16) |
	       ((u32)imms << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_extract_arm64(u32 *image, int *idx, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	u8 dst_reg, start, bit_len;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_extract_payload(payload, &dst_reg, &start, &bit_len);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	if (dst_reg == 0xff)
		return -EINVAL;

	insn = a64_ubfm_x(dst_reg, dst_reg, start, start + bit_len - 1);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

const struct bpf_kinsn bpf_extract64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_extract,
	.emit_arm64 = emit_extract_arm64,
};

DEFINE_KINSN_V2_MODULE(bpf_extract, "BpfReJIT kinsn: BITFIELD_EXTRACT");
