// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsns: direct stores.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_strb(void) {}
__bpf_kfunc void bpf_arm64_strh(void) {}
__bpf_kfunc void bpf_arm64_str_w(void) {}
__bpf_kfunc void bpf_arm64_str_x(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_str_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_str_w)
BTF_ID_FLAGS(func, bpf_arm64_str_x)
BTF_ID_FLAGS(func, bpf_arm64_strb)
BTF_ID_FLAGS(func, bpf_arm64_strh)
BTF_KFUNCS_END(bpf_arm64_str_kfunc_ids)

#define ARM64_STR_FORM_REG	1
#define ARM64_STR_FORM_ZERO	2

static __always_inline int decode_store_reg_payload(u64 payload, u8 *src_reg,
						    u8 *base_reg, s16 *offset)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) == ARM64_STR_FORM_REG) {
		*src_reg = kinsn_payload_reg(payload, 4);
		*base_reg = kinsn_payload_reg(payload, 8);
		*offset = kinsn_payload_s16(payload, 12);

		if (payload >> 28)
			return -EINVAL;
	} else {
		*src_reg = kinsn_payload_reg(payload, 0);
		*base_reg = kinsn_payload_reg(payload, 4);
		*offset = kinsn_payload_s16(payload, 8);

		if (payload >> 24)
			return -EINVAL;
	}
	if (*src_reg >= BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store_imm_payload(u64 payload, u8 *base_reg,
						    s16 *offset, u8 *imm)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) == ARM64_STR_FORM_ZERO) {
		*base_reg = kinsn_payload_reg(payload, 4);
		*offset = kinsn_payload_s16(payload, 8);
		*imm = kinsn_payload_u8(payload, 24);

		if (payload >> 32)
			return -EINVAL;
	} else {
		*base_reg = kinsn_payload_reg(payload, 0);
		*offset = kinsn_payload_s16(payload, 4);
		*imm = kinsn_payload_u8(payload, 20);

		if (payload >> 28)
			return -EINVAL;
	}
	if (*base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_store_reg(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 src_reg, base_reg;
	s16 offset;
	int err;

	err = decode_store_reg_payload(payload, &src_reg, &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_STX_MEM(size, base_reg, src_reg, offset);
	return 1;
}

static int instantiate_strb_zero_mem(u64 payload, struct bpf_insn *insn_buf);

static int instantiate_strb(u64 payload, struct bpf_insn *insn_buf)
{
	if ((kinsn_payload_decode(payload) & 0xf) == ARM64_STR_FORM_ZERO)
		return instantiate_strb_zero_mem(payload, insn_buf);
	return instantiate_store_reg(payload, insn_buf, BPF_B);
}

static int instantiate_strh(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_H);
}

static int instantiate_str_w(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_W);
}

static int instantiate_str_x(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_DW);
}

static int instantiate_strb_zero_mem(u64 payload, struct bpf_insn *insn_buf)
{
	u8 base_reg, imm;
	s16 offset;
	int err;

	err = decode_store_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;
	if (imm)
		return -EINVAL;

	insn_buf[0] = BPF_ST_MEM(BPF_B, base_reg, offset, 0);
	return 1;
}

static inline bool a64_scaled_uoff_ok(s16 offset, u8 shift)
{
	return offset >= 0 && offset <= (0x0fff << shift) &&
	       !(offset & ((1 << shift) - 1));
}

static inline bool a64_unscaled_soff_ok(s16 offset)
{
	return offset >= -256 && offset <= 255;
}

static inline u32 a64_strb(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 0))
		return 0x39000000U | ((u32)((u16)offset) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0x38000000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static inline u32 a64_strh(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 1))
		return 0x79000000U | ((((u32)offset) >> 1) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0x78000000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static inline u32 a64_str_w(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 2))
		return 0xB9000000U | ((((u32)offset) >> 2) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0xB8000000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static inline u32 a64_str_x(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 3))
		return 0xF9000000U | ((((u32)offset) >> 3) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0xF8000000U | ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

static int emit_store_reg_arm64(u32 *image, int *idx, bool emit, u64 payload,
				const struct bpf_prog *prog, u8 size)
{
	u8 src_reg, base_reg;
	s16 offset;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_store_reg_payload(payload, &src_reg, &base_reg, &offset);
	if (err)
		return err;

	src_reg = kinsn_arm64_reg(src_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (src_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	switch (size) {
	case BPF_B:
		if (!a64_scaled_uoff_ok(offset, 0) && !a64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_strb(src_reg, base_reg, offset);
		break;
	case BPF_H:
		if (!a64_scaled_uoff_ok(offset, 1) && !a64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_strh(src_reg, base_reg, offset);
		break;
	case BPF_W:
		if (!a64_scaled_uoff_ok(offset, 2) && !a64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_str_w(src_reg, base_reg, offset);
		break;
	case BPF_DW:
		if (!a64_scaled_uoff_ok(offset, 3) && !a64_unscaled_soff_ok(offset))
			return -EINVAL;
		insn = a64_str_x(src_reg, base_reg, offset);
		break;
	default:
		return -EINVAL;
	}

	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

static int emit_strb_fixed_arm64(u32 *image, int *idx, bool emit, u64 payload,
				 const struct bpf_prog *prog, u8 src_reg);

static int emit_strb_arm64(u32 *image, int *idx, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	if ((kinsn_payload_decode(payload) & 0xf) == ARM64_STR_FORM_ZERO)
		return emit_strb_fixed_arm64(image, idx, emit, payload, prog, 31);
	return emit_store_reg_arm64(image, idx, emit, payload, prog, BPF_B);
}

static int emit_strh_arm64(u32 *image, int *idx, bool emit,
				   u64 payload, const struct bpf_prog *prog)
{
	return emit_store_reg_arm64(image, idx, emit, payload, prog, BPF_H);
}

static int emit_str_w_arm64(u32 *image, int *idx, bool emit,
				    u64 payload, const struct bpf_prog *prog)
{
	return emit_store_reg_arm64(image, idx, emit, payload, prog, BPF_W);
}

static int emit_str_x_arm64(u32 *image, int *idx, bool emit,
				    u64 payload, const struct bpf_prog *prog)
{
	return emit_store_reg_arm64(image, idx, emit, payload, prog, BPF_DW);
}

static int emit_strb_fixed_arm64(u32 *image, int *idx, bool emit, u64 payload,
				 const struct bpf_prog *prog, u8 src_reg)
{
	u8 base_reg, imm;
	s16 offset;
	u32 insn;
	int err;

	(void)prog;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_store_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;
	(void)imm;

	base_reg = kinsn_arm64_reg(base_reg);
	if (base_reg == 0xff)
		return -EINVAL;
	if (!a64_scaled_uoff_ok(offset, 0) && !a64_unscaled_soff_ok(offset))
		return -EINVAL;

	insn = a64_strb(src_reg, base_reg, offset);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

const struct bpf_kinsn bpf_arm64_strb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_strb,
	.emit_arm64 = emit_strb_arm64,
};

const struct bpf_kinsn bpf_arm64_strh_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_strh,
	.emit_arm64 = emit_strh_arm64,
};

const struct bpf_kinsn bpf_arm64_str_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_str_w,
	.emit_arm64 = emit_str_w_arm64,
};

const struct bpf_kinsn bpf_arm64_str_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_str_x,
	.emit_arm64 = emit_str_x_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_str_kinsn_descs[] = {
	&bpf_arm64_str_w_desc,
	&bpf_arm64_str_x_desc,
	&bpf_arm64_strb_desc,
	&bpf_arm64_strh_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_str, "BpfReJIT arm64 kinsns: STR",
		       bpf_arm64_str_kfunc_ids, bpf_arm64_str_kinsn_descs);
