// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsns: LDP/STP.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_ldp_x(void) {}
__bpf_kfunc void bpf_arm64_stp_x(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_ldp_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_ldp_x)
BTF_ID_FLAGS(func, bpf_arm64_stp_x)
BTF_KFUNCS_END(bpf_arm64_ldp_kfunc_ids)

static __always_inline bool a64_ldstp_soff_ok(s16 offset)
{
	return offset >= -512 && offset <= 504 && !(offset & 7);
}

static __always_inline u32 a64_ldp_x(u8 rt, u8 rt2, u8 rn, s16 offset)
{
	u32 imm7 = ((u32)((s32)(offset / 8))) & 0x7fU;

	return 0xA9400000U |
	       (imm7 << 15) |
	       ((u32)rt2 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}

static __always_inline u32 a64_stp_x(u8 rt, u8 rt2, u8 rn, s16 offset)
{
	u32 imm7 = ((u32)((s32)(offset / 8))) & 0x7fU;

	return 0xA9000000U |
	       (imm7 << 15) |
	       ((u32)rt2 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}

static __always_inline int decode_pair_payload(u64 payload, u8 *lane0_reg,
					       u8 *lane1_reg, u8 *base_reg,
					       s16 *offset)
{
	*lane0_reg = kinsn_payload_reg(payload, 0);
	*lane1_reg = kinsn_payload_reg(payload, 4);
	*base_reg = kinsn_payload_reg(payload, 8);
	*offset = kinsn_payload_s16(payload, 12);

	if (payload >> 28)
		return -EINVAL;
	if (*lane0_reg > BPF_REG_10 || *lane1_reg > BPF_REG_10 ||
	    *base_reg > BPF_REG_10)
		return -EINVAL;
	if (!a64_ldstp_soff_ok(*offset))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_ldp_payload(u64 payload, u8 *dst_lo_reg,
					      u8 *dst_hi_reg, u8 *base_reg,
					      s16 *offset)
{
	int err;

	err = decode_pair_payload(payload, dst_lo_reg, dst_hi_reg,
				  base_reg, offset);
	if (err)
		return err;
	if (*dst_lo_reg == *dst_hi_reg)
		return -EINVAL;
	if (*dst_lo_reg == BPF_REG_10 || *dst_hi_reg == BPF_REG_10)
		return -EINVAL;
	if (*base_reg == *dst_lo_reg || *base_reg == *dst_hi_reg)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_stp_payload(u64 payload, u8 *src_lo_reg,
					      u8 *src_hi_reg, u8 *base_reg,
					      s16 *offset)
{
	return decode_pair_payload(payload, src_lo_reg, src_hi_reg,
				   base_reg, offset);
}

static int instantiate_ldp(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_lo_reg, dst_hi_reg, base_reg;
	s16 offset;
	int err;

	err = decode_ldp_payload(payload, &dst_lo_reg, &dst_hi_reg,
				 &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_LDX_MEM(BPF_DW, dst_lo_reg, base_reg, offset);
	insn_buf[1] = BPF_LDX_MEM(BPF_DW, dst_hi_reg, base_reg, offset + 8);
	return 2;
}

static int instantiate_stp(u64 payload, struct bpf_insn *insn_buf)
{
	u8 src_lo_reg, src_hi_reg, base_reg;
	s16 offset;
	int err;

	err = decode_stp_payload(payload, &src_lo_reg, &src_hi_reg,
				 &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_STX_MEM(BPF_DW, base_reg, src_lo_reg, offset);
	insn_buf[1] = BPF_STX_MEM(BPF_DW, base_reg, src_hi_reg, offset + 8);
	return 2;
}

static int emit_ldp_arm64(u32 *image, int *idx, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	u8 dst_lo_reg, dst_hi_reg, base_reg;
	u32 insn;
	s16 offset;
	int err;

	(void)prog;

	err = decode_ldp_payload(payload, &dst_lo_reg, &dst_hi_reg,
				 &base_reg, &offset);
	if (err)
		return err;

	dst_lo_reg = kinsn_arm64_reg(dst_lo_reg);
	dst_hi_reg = kinsn_arm64_reg(dst_hi_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (dst_lo_reg == 0xff || dst_hi_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	insn = a64_ldp_x(dst_lo_reg, dst_hi_reg, base_reg, offset);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

static int emit_stp_arm64(u32 *image, int *idx, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	u8 src_lo_reg, src_hi_reg, base_reg;
	u32 insn;
	s16 offset;
	int err;

	(void)prog;

	err = decode_stp_payload(payload, &src_lo_reg, &src_hi_reg,
				 &base_reg, &offset);
	if (err)
		return err;

	src_lo_reg = kinsn_arm64_reg(src_lo_reg);
	src_hi_reg = kinsn_arm64_reg(src_hi_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (src_lo_reg == 0xff || src_hi_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	insn = a64_stp_x(src_lo_reg, src_hi_reg, base_reg, offset);
	return kinsn_arm64_emit_one(image, idx, emit, insn);
}

const struct bpf_kinsn bpf_arm64_ldp_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_ldp,
	.emit_arm64 = emit_ldp_arm64,
};

const struct bpf_kinsn bpf_arm64_stp_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_stp,
	.emit_arm64 = emit_stp_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_ldp_kinsn_descs[] = {
	&bpf_arm64_ldp_x_desc,
	&bpf_arm64_stp_x_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_ldp, "BpfReJIT arm64 kinsns: LDP/STP",
		       bpf_arm64_ldp_kfunc_ids, bpf_arm64_ldp_kinsn_descs);
