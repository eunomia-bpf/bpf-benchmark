// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsns: MOV register-to-register.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_mov_x(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_mov_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_mov_x)
BTF_KFUNCS_END(bpf_arm64_mov_kfunc_ids)

static __always_inline int decode_mov_payload(u64 payload, u8 *dst_reg,
						 u8 *src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_mov_x(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_mov_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
	return 1;
}

static inline u32 a64_mov_x(u8 rd, u8 rm)
{
	return 0xAA0003E0U | ((u32)rm << 16) | (u32)rd;
}

static int emit_mov_x_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog,
			       const u32 *final_ip)
{
	u8 dst_reg, src_reg;
	u32 insn;
	int err;

	(void)prog;
	(void)final_ip;

	err = decode_mov_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	src_reg = kinsn_arm64_reg(src_reg);
	if (dst_reg == 0xff || src_reg == 0xff)
		return -EINVAL;

	insn = a64_mov_x(dst_reg, src_reg);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

const struct bpf_kinsn bpf_arm64_mov_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_mov_x,
	.emit_arm64 = emit_mov_x_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_mov_kinsn_descs[] = {
	&bpf_arm64_mov_x_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_mov, "BpfReJIT arm64 kinsns: MOV",
		       bpf_arm64_mov_kfunc_ids, bpf_arm64_mov_kinsn_descs);
