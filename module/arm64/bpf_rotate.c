// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE - 32/64-bit rotate left via EXTR on ARM64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_rotate64(void) {}
__bpf_kfunc void bpf_rotate32(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_rotate_kfunc_ids)
BTF_ID_FLAGS(func, bpf_rotate64)
BTF_ID_FLAGS(func, bpf_rotate32)
BTF_KFUNCS_END(bpf_rotate_kfunc_ids)

static __always_inline int decode_rotate_payload(u64 payload,
						 u8 shift_mask,
						 u8 *dst_reg,
						 u8 *src_reg,
						 u8 *tmp_reg,
						 u8 *shift)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*shift = kinsn_payload_u8(payload, 8) & shift_mask;
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 || *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_rotate64_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	return decode_rotate_payload(payload, 63, dst_reg, src_reg, tmp_reg, shift);
}

static __always_inline int decode_rotate32_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	return decode_rotate_payload(payload, 31, dst_reg, src_reg, tmp_reg, shift);
}

static int instantiate_rotate64(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
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

static int instantiate_rotate32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	if (!shift) {
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, src_reg);
		return cnt;
	}

	insn_buf[cnt++] = BPF_MOV32_REG(tmp_reg, src_reg);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_RSH, tmp_reg, 32 - shift);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_OR, dst_reg, tmp_reg);
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

static inline u32 a64_extr_w(u8 rd, u8 rn, u8 rm, u8 lsb)
{
	return 0x13800000U |
	       ((u32)rm << 16) |
	       ((u32)lsb << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_rotate_arm64(u32 *image, int *idx, bool emit,
			     u64 payload, const struct bpf_prog *prog,
			     bool is64)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	if (is64)
		err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	else
		err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	src_reg = kinsn_arm64_reg(src_reg);
	if (dst_reg == 0xff || src_reg == 0xff)
		return -EINVAL;

	if (is64)
		insn = a64_extr_x(dst_reg, src_reg, src_reg, (-shift) & 63);
	else
		insn = a64_extr_w(dst_reg, src_reg, src_reg, (-shift) & 31);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

static int emit_rotate64_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_rotate_arm64(image, idx, emit, payload, prog, true);
}

static int emit_rotate32_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_rotate_arm64(image, idx, emit, payload, prog, false);
}

const struct bpf_kinsn bpf_rotate64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate64,
	.emit_arm64 = emit_rotate64_arm64,
};

const struct bpf_kinsn bpf_rotate32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate32,
	.emit_arm64 = emit_rotate32_arm64,
};

static const struct bpf_kinsn * const bpf_rotate_kinsn_descs[] = {
	&bpf_rotate64_desc,
	&bpf_rotate32_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_rotate, "BpfReJIT kinsn: ROTATE (EXTR)",
		       bpf_rotate_kfunc_ids, bpf_rotate_kinsn_descs);
