// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 koperation: REV byte-order instructions.
 */

#include "kop_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_rev16_w(void) {}
__bpf_kfunc void bpf_arm64_rev_w(void) {}
__bpf_kfunc void bpf_arm64_rev_x(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_rev_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_rev16_w)
BTF_ID_FLAGS(func, bpf_arm64_rev_w)
BTF_ID_FLAGS(func, bpf_arm64_rev_x)
BTF_KFUNCS_END(bpf_arm64_rev_kfunc_ids)

static __always_inline int decode_reg_payload(u64 payload, u8 *dst_reg)
{
	*dst_reg = kop_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_rev(u64 payload, struct bpf_insn *insn_buf, u8 bits)
{
	u8 dst_reg;
	int err;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_BSWAP(dst_reg, bits);
	return 1;
}

static int instantiate_rev16_w(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rev(payload, insn_buf, 16);
}

static int instantiate_rev_w(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rev(payload, insn_buf, 32);
}

static int instantiate_rev_x(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rev(payload, insn_buf, 64);
}

static inline u32 a64_rev16_w(u8 rd, u8 rn)
{
	return 0x5AC00400U | ((u32)rn << 5) | (u32)rd;
}

static inline u32 a64_rev_w(u8 rd, u8 rn)
{
	return 0x5AC00800U | ((u32)rn << 5) | (u32)rd;
}

static inline u32 a64_rev_x(u8 rd, u8 rn)
{
	return 0xDAC00C00U | ((u32)rn << 5) | (u32)rd;
}

static int emit_rev_arm64(u32 *image, int *idx, bool emit, u64 payload,
			  const struct bpf_prog *prog, u8 bits)
{
	u8 dst_reg;
	u32 insn;
	int err;

	(void)prog;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	dst_reg = kop_arm64_reg(dst_reg);
	if (dst_reg == 0xff)
		return -EINVAL;

	switch (bits) {
	case 16:
		insn = a64_rev16_w(dst_reg, dst_reg);
		break;
	case 32:
		insn = a64_rev_w(dst_reg, dst_reg);
		break;
	case 64:
		insn = a64_rev_x(dst_reg, dst_reg);
		break;
	default:
		return -EINVAL;
	}

	return kop_arm64_emit_one(image, idx, emit, insn);
}

static int emit_rev16_w_arm64(u32 *image, int *idx, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			      const u32 *final_ip)
{
	(void)final_ip;

	return emit_rev_arm64(image, idx, emit, payload, prog, 16);
}

static int emit_rev_w_arm64(u32 *image, int *idx, bool emit, u64 payload,
			    const struct bpf_prog *prog,
			    const u32 *final_ip)
{
	(void)final_ip;

	return emit_rev_arm64(image, idx, emit, payload, prog, 32);
}

static int emit_rev_x_arm64(u32 *image, int *idx, bool emit, u64 payload,
			    const struct bpf_prog *prog,
			    const u32 *final_ip)
{
	(void)final_ip;

	return emit_rev_arm64(image, idx, emit, payload, prog, 64);
}

const struct bpf_kop bpf_arm64_rev16_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rev16_w,
	.emit_arm64 = emit_rev16_w_arm64,
};

const struct bpf_kop bpf_arm64_rev_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rev_w,
	.emit_arm64 = emit_rev_w_arm64,
};

const struct bpf_kop bpf_arm64_rev_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rev_x,
	.emit_arm64 = emit_rev_x_arm64,
};

static const struct bpf_kop * const bpf_arm64_rev_kop_descs[] = {
	&bpf_arm64_rev16_w_desc,
	&bpf_arm64_rev_w_desc,
	&bpf_arm64_rev_x_desc,
};

DEFINE_KOP_V2_MODULE(bpf_arm64_rev, "BpfReJIT arm64 koperation: REV",
		       bpf_arm64_rev_kfunc_ids, bpf_arm64_rev_kop_descs);
