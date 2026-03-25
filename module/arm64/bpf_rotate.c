// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE - 64-bit rotate left via EXTR on ARM64
 */

#include "kinsn_common.h"

static __always_inline int decode_rotate_payload(u64 payload,
						 u8 *dst_reg,
						 u8 *src_reg,
						 u8 *tmp_reg,
						 u8 *shift)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*shift = kinsn_payload_u8(payload, 8) & 63;
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 || *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;

	return 0;
}

static int instantiate_rotate(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	if (!shift) {
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
		return cnt;
	}

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_reg, src_reg);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, tmp_reg, 64 - shift);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	return cnt;
}

static inline u32 a64_extr_x(u8 rd, u8 rn, u8 rm, u8 lsb)
{
	return 0x93C00000U |
	       ((u32)rm << 16) |
	       ((u32)lsb << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_rotate_arm64(u32 *image, int *idx, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	src_reg = kinsn_arm64_reg(src_reg);
	if (dst_reg == 0xff || src_reg == 0xff)
		return -EINVAL;

	insn = a64_extr_x(dst_reg, src_reg, src_reg, (-shift) & 63);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

const struct bpf_kinsn bpf_rotate64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate,
	.emit_arm64 = emit_rotate_arm64,
};

DEFINE_KINSN_V2_MODULE(bpf_rotate, "BpfReJIT kinsn: ROTATE (EXTR)",
		       BPF_KINSN_DESC_ENTRY(bpf_rotate64_desc));
