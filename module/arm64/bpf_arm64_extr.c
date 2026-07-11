// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 koperation: EXTR - 32/64-bit rotate left via EXTR on ARM64
 */

#include "kop_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_extr_x(void) {}
__bpf_kfunc void bpf_arm64_extr_w(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_extr_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_extr_w)
BTF_ID_FLAGS(func, bpf_arm64_extr_x)
BTF_KFUNCS_END(bpf_arm64_extr_kfunc_ids)

static __always_inline int decode_rotate_payload(u64 payload,
						 u8 shift_mask,
						 u8 *dst_reg,
						 u8 *src_reg,
						 u8 *tmp_reg,
						 u8 *shift)
{
	*dst_reg = kop_payload_reg(payload, 0);
	*src_reg = kop_payload_reg(payload, 4);
	*shift = kop_payload_u8(payload, 8) & shift_mask;
	*tmp_reg = kop_payload_reg(payload, 16);

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

	if (is64)
		err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	else
		err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	dst_reg = kop_arm64_reg(dst_reg);
	src_reg = kop_arm64_reg(src_reg);
	if (dst_reg == 0xff || src_reg == 0xff)
		return -EINVAL;

	if (is64)
		insn = a64_extr_x(dst_reg, src_reg, src_reg, (-shift) & 63);
	else
		insn = a64_extr_w(dst_reg, src_reg, src_reg, (-shift) & 31);
	return kop_arm64_emit_one(image, idx, emit, insn);
}

static int emit_rotate64_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog,
			       const u32 *final_ip)
{
	(void)final_ip;

	return emit_rotate_arm64(image, idx, emit, payload, prog, true);
}

static int emit_rotate32_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog,
			       const u32 *final_ip)
{
	(void)final_ip;

	return emit_rotate_arm64(image, idx, emit, payload, prog, false);
}

const struct bpf_kop bpf_arm64_extr_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate64,
	.emit_arm64 = emit_rotate64_arm64,
};

const struct bpf_kop bpf_arm64_extr_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate32,
	.emit_arm64 = emit_rotate32_arm64,
};

static const struct bpf_kop * const bpf_arm64_extr_kop_descs[] = {
	&bpf_arm64_extr_w_desc,
	&bpf_arm64_extr_x_desc,
};

DEFINE_KOP_V2_MODULE(bpf_arm64_extr, "BpfReJIT arm64 koperation: EXTR (EXTR)",
		       bpf_arm64_extr_kfunc_ids, bpf_arm64_extr_kop_descs);
