// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsns: direct loads.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_ldrb(void) {}
__bpf_kfunc void bpf_arm64_ldrh(void) {}
__bpf_kfunc void bpf_arm64_ldr_w(void) {}
__bpf_kfunc void bpf_arm64_ldr_x(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_ldr_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_ldr_w)
BTF_ID_FLAGS(func, bpf_arm64_ldr_x)
BTF_ID_FLAGS(func, bpf_arm64_ldrb)
BTF_ID_FLAGS(func, bpf_arm64_ldrh)
BTF_KFUNCS_END(bpf_arm64_ldr_kfunc_ids)

static __always_inline int decode_ldr_payload(u64 payload, u8 *dst_reg,
					      u8 *base_reg, s16 *offset)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);

	if (payload >> 24)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_ldr(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg;
	s16 offset;
	int err;

	err = decode_ldr_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
	return 1;
}

static int instantiate_ldrh_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_ldr(payload, insn_buf, BPF_H);
}

static int instantiate_ldrb_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_ldr(payload, insn_buf, BPF_B);
}

static int instantiate_ldr_w_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_ldr(payload, insn_buf, BPF_W);
}

static int instantiate_ldr_x_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_ldr(payload, insn_buf, BPF_DW);
}

static inline u32 a64_ldrh(u8 rt, u8 rn, s16 offset)
{
	if (kinsn_arm64_scaled_uoff_ok(offset, 1))
		return 0x79400000U | ((((u32)offset) >> 1) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0x78400000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static inline u32 a64_ldrb(u8 rt, u8 rn, s16 offset)
{
	if (kinsn_arm64_scaled_uoff_ok(offset, 0))
		return 0x39400000U | ((u32)((u16)offset) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0x38400000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static inline u32 a64_ldr_w(u8 rt, u8 rn, s16 offset)
{
	if (kinsn_arm64_scaled_uoff_ok(offset, 2))
		return 0xB9400000U | ((((u32)offset) >> 2) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0xB8400000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static inline u32 a64_ldr_x(u8 rt, u8 rn, s16 offset)
{
	if (kinsn_arm64_scaled_uoff_ok(offset, 3))
		return 0xF9400000U | ((((u32)offset) >> 3) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0xF8400000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static int emit_ldr_arm64(u32 *image, int *idx, bool emit, u64 payload,
			  const struct bpf_prog *prog, u8 size)
{
	u8 dst_reg, base_reg;
	s16 offset;
	u32 insn;
	int err;

	(void)prog;

	err = decode_ldr_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	dst_reg = kinsn_arm64_reg(dst_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (dst_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	switch (size) {
	case BPF_B:
		if (!kinsn_arm64_scaled_uoff_ok(offset, 0) &&
		    !kinsn_arm64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_ldrb(dst_reg, base_reg, offset);
		break;
	case BPF_H:
		if (!kinsn_arm64_scaled_uoff_ok(offset, 1) &&
		    !kinsn_arm64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_ldrh(dst_reg, base_reg, offset);
		break;
	case BPF_W:
		if (!kinsn_arm64_scaled_uoff_ok(offset, 2) &&
		    !kinsn_arm64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_ldr_w(dst_reg, base_reg, offset);
		break;
	case BPF_DW:
		if (!kinsn_arm64_scaled_uoff_ok(offset, 3) &&
		    !kinsn_arm64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_ldr_x(dst_reg, base_reg, offset);
		break;
	default:
		return -EINVAL;
	}

	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

static int emit_ldrh_mem_arm64(u32 *image, int *idx, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_ldr_arm64(image, idx, emit, payload, prog, BPF_H);
}

static int emit_ldrb_mem_arm64(u32 *image, int *idx, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_ldr_arm64(image, idx, emit, payload, prog, BPF_B);
}

static int emit_ldr_w_mem_arm64(u32 *image, int *idx, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_ldr_arm64(image, idx, emit, payload, prog, BPF_W);
}

static int emit_ldr_x_mem_arm64(u32 *image, int *idx, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_ldr_arm64(image, idx, emit, payload, prog, BPF_DW);
}

const struct bpf_kinsn bpf_arm64_ldrh_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ldrh_mem,
	.emit_arm64 = emit_ldrh_mem_arm64,
};

const struct bpf_kinsn bpf_arm64_ldrb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ldrb_mem,
	.emit_arm64 = emit_ldrb_mem_arm64,
};

const struct bpf_kinsn bpf_arm64_ldr_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ldr_w_mem,
	.emit_arm64 = emit_ldr_w_mem_arm64,
};

const struct bpf_kinsn bpf_arm64_ldr_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ldr_x_mem,
	.emit_arm64 = emit_ldr_x_mem_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_ldr_kinsn_descs[] = {
	&bpf_arm64_ldr_w_desc,
	&bpf_arm64_ldr_x_desc,
	&bpf_arm64_ldrb_desc,
	&bpf_arm64_ldrh_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_ldr, "BpfReJIT arm64 kinsns: LDR",
		       bpf_arm64_ldr_kfunc_ids, bpf_arm64_ldr_kinsn_descs);
