// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ENDIAN_LOAD - fused load-and-byte-swap via REV
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_endian_load16(void) {}
__bpf_kfunc void bpf_endian_load32(void) {}
__bpf_kfunc void bpf_endian_load64(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_endian_kfunc_ids)
BTF_ID_FLAGS(func, bpf_endian_load16)
BTF_ID_FLAGS(func, bpf_endian_load32)
BTF_ID_FLAGS(func, bpf_endian_load64)
BTF_KFUNCS_END(bpf_endian_kfunc_ids)

static __always_inline int decode_endian_payload(u64 payload,
						 u8 *dst_reg,
						 u8 *base_reg,
						 s16 *offset)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);

	if (*dst_reg > BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_endian(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg;
	u8 bits;
	s16 offset;
	int err;

	err = decode_endian_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;
	bits = kinsn_bpf_size_bits(size);
	if (!bits)
		return -EINVAL;

	insn_buf[0] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
	insn_buf[1] = BPF_BSWAP(dst_reg, bits);
	return 2;
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

static inline u32 a64_ldrh(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 1))
		return 0x79400000U |
		       ((((u32)offset) >> 1) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0x78400000U |
	       ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

/*
 * LDR Wt, [Xn]  (Load Register 32-bit, unsigned offset=0)
 *   10 111 0 01 01 imm12(0) Rn Rt
 *   = 0xB9400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldr_w(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 2))
		return 0xB9400000U |
		       ((((u32)offset) >> 2) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0xB8400000U |
	       ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

/*
 * LDR Xt, [Xn]  (Load Register 64-bit, unsigned offset=0)
 *   11 111 0 01 01 imm12(0) Rn Rt
 *   = 0xF9400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldr_x(u8 rt, u8 rn, s16 offset)
{
	if (a64_scaled_uoff_ok(offset, 3))
		return 0xF9400000U |
		       ((((u32)offset) >> 3) << 10) |
		       ((u32)rn << 5) | (u32)rt;

	return 0xF8400000U |
	       ((((u32)offset) & 0x1ffU) << 12) |
	       ((u32)rn << 5) | (u32)rt;
}

/*
 * REV16 Wt, Wn  (Reverse bytes in 16-bit halfwords, 32-bit)
 *   0 1 01 1010 11 00000 00001 0 Rn Rd
 *   = 0x5AC00400 | (Rn << 5) | Rd
 */
static inline u32 a64_rev16_w(u8 rd, u8 rn)
{
	return 0x5AC00400U | ((u32)rn << 5) | (u32)rd;
}

/*
 * REV Wt, Wn  (Reverse bytes in 32-bit word)
 *   0 1 01 1010 11 00000 00010 0 Rn Rd
 *   = 0x5AC00800 | (Rn << 5) | Rd
 */
static inline u32 a64_rev_w(u8 rd, u8 rn)
{
	return 0x5AC00800U | ((u32)rn << 5) | (u32)rd;
}

/*
 * REV Xt, Xn  (Reverse bytes in 64-bit doubleword)
 *   1 1 01 1010 11 00000 00011 0 Rn Rd
 *   = 0xDAC00C00 | (Rn << 5) | Rd
 */
static inline u32 a64_rev_x(u8 rd, u8 rn)
{
	return 0xDAC00C00U | ((u32)rn << 5) | (u32)rd;
}

/*
 * AND Xt, Xn, #imm  (Logical immediate, 64-bit)
 * For #0xFFFF (16 bits set from bit 0):
 *   N=0, immr=0, imms=001111 (0xF)
 *   1 00 100100 N(0) immr(000000) imms(001111) Rn Rd
 *   = 0x92400000 | (0xF << 10) | (Rn << 5) | Rd
 */
static inline u32 a64_and_imm_0xffff(u8 rd, u8 rn)
{
	return 0x92400000U | (0xFU << 10) | ((u32)rn << 5) | (u32)rd;
}

static int emit_endian_load16_arm64(u32 *image, int *idx, bool emit,
				    u64 payload, const struct bpf_prog *prog)
{
	u32 insns[3];
	u8 dst_reg, base_reg;
	s16 offset;
	int err;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)prog;

	err = decode_endian_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;
	if (!a64_scaled_uoff_ok(offset, 1) && !a64_unscaled_soff_ok(offset))
		return -EINVAL;

	dst_reg = kinsn_arm64_reg(dst_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (dst_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	insns[0] = a64_ldrh(dst_reg, base_reg, offset);
	insns[1] = a64_rev16_w(dst_reg, dst_reg);
	insns[2] = a64_and_imm_0xffff(dst_reg, dst_reg);

	if (emit) {
		int i;

		for (i = 0; i < 3; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 3;
	return 3;
}

static int emit_endian_load32_arm64(u32 *image, int *idx, bool emit,
				    u64 payload, const struct bpf_prog *prog)
{
	u32 insns[2];
	u8 dst_reg, base_reg;
	s16 offset;
	int err;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)prog;

	err = decode_endian_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;
	if (!a64_scaled_uoff_ok(offset, 2) && !a64_unscaled_soff_ok(offset))
		return -EINVAL;

	dst_reg = kinsn_arm64_reg(dst_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (dst_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	insns[0] = a64_ldr_w(dst_reg, base_reg, offset);
	insns[1] = a64_rev_w(dst_reg, dst_reg);

	if (emit) {
		int i;

		for (i = 0; i < 2; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 2;
	return 2;
}

static int emit_endian_load64_arm64(u32 *image, int *idx, bool emit,
				    u64 payload, const struct bpf_prog *prog)
{
	u32 insns[2];
	u8 dst_reg, base_reg;
	s16 offset;
	int err;

	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)prog;

	err = decode_endian_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;
	if (!a64_scaled_uoff_ok(offset, 3) && !a64_unscaled_soff_ok(offset))
		return -EINVAL;

	dst_reg = kinsn_arm64_reg(dst_reg);
	base_reg = kinsn_arm64_reg(base_reg);
	if (dst_reg == 0xff || base_reg == 0xff)
		return -EINVAL;

	insns[0] = a64_ldr_x(dst_reg, base_reg, offset);
	insns[1] = a64_rev_x(dst_reg, dst_reg);

	if (emit) {
		int i;

		for (i = 0; i < 2; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 2;
	return 2;
}

static int instantiate_endian16(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_endian(payload, insn_buf, BPF_H);
}

static int instantiate_endian32(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_endian(payload, insn_buf, BPF_W);
}

static int instantiate_endian64(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_endian(payload, insn_buf, BPF_DW);
}

const struct bpf_kinsn bpf_endian_load16_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 12,
	.instantiate_insn = instantiate_endian16,
	.emit_arm64 = emit_endian_load16_arm64,
};

const struct bpf_kinsn bpf_endian_load32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_endian32,
	.emit_arm64 = emit_endian_load32_arm64,
};

const struct bpf_kinsn bpf_endian_load64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_endian64,
	.emit_arm64 = emit_endian_load64_arm64,
};

static const struct bpf_kinsn * const bpf_endian_kinsn_descs[] = {
	&bpf_endian_load16_desc,
	&bpf_endian_load32_desc,
	&bpf_endian_load64_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_endian, "BpfReJIT kinsn: ENDIAN_LOAD (REV)",
		       bpf_endian_kfunc_ids, bpf_endian_kinsn_descs);
