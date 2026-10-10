// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 kinsn: EXTR - 32/64-bit rotate left via EXTR on ARM64
 */

#include "kinsn_common.h"

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
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*shift = kinsn_payload_u8(payload, 8) & shift_mask;
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (*dst_reg >= BPF_REG_10 || *src_reg > BPF_REG_10 ||
	    *tmp_reg > BPF_REG_10 || (*shift && *tmp_reg == BPF_REG_10))
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

/* The legacy temporary field is decoded for ABI compatibility, but never
 * written: carry is held in the branch path, not in program state. */
static int instantiate_rotate(u64 payload, struct bpf_insn *insn_buf, bool is64)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int i;
	int err;

	err = decode_rotate_payload(payload, is64 ? 63 : 31,
				    &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	insn_buf[cnt++] = is64 ? BPF_MOV64_REG(dst_reg, src_reg) :
				BPF_MOV32_REG(dst_reg, src_reg);
	for (i = 0; i < shift; i++) {
		insn_buf[cnt++] = is64 ? BPF_JMP_IMM(BPF_JSLT, dst_reg, 0, 2) :
					BPF_JMP32_IMM(BPF_JSLT, dst_reg, 0, 2);
		insn_buf[cnt++] = is64 ? BPF_ALU64_IMM(BPF_LSH, dst_reg, 1) :
					BPF_ALU32_IMM(BPF_LSH, dst_reg, 1);
		insn_buf[cnt++] = BPF_JMP_A(2);
		insn_buf[cnt++] = is64 ? BPF_ALU64_IMM(BPF_LSH, dst_reg, 1) :
					BPF_ALU32_IMM(BPF_LSH, dst_reg, 1);
		insn_buf[cnt++] = is64 ? BPF_ALU64_IMM(BPF_OR, dst_reg, 1) :
					BPF_ALU32_IMM(BPF_OR, dst_reg, 1);
	}
	return cnt;
}

static int instantiate_rotate64(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rotate(payload, insn_buf, true);
}

static int instantiate_rotate32(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_rotate(payload, insn_buf, false);
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

	dst_reg = kinsn_arm64_reg(dst_reg);
	src_reg = kinsn_arm64_reg(src_reg);
	tmp_reg = kinsn_arm64_reg(tmp_reg);
	if (dst_reg == 0xff || src_reg == 0xff || tmp_reg == 0xff)
		return -EINVAL;


	if (is64)
		insn = a64_extr_x(dst_reg, src_reg, src_reg, (-shift) & 63);
	else
		insn = a64_extr_w(dst_reg, src_reg, src_reg, (-shift) & 31);
	err = kinsn_arm64_emit_one(image, idx, emit, insn);
	if (err < 0)
		return err;
	return err;
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

const struct bpf_kinsn bpf_arm64_extr_x_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 316,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate64,
	.emit_arm64 = emit_rotate64_arm64,
};

const struct bpf_kinsn bpf_arm64_extr_w_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 156,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_rotate32,
	.emit_arm64 = emit_rotate32_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_extr_kinsn_descs[] = {
	&bpf_arm64_extr_w_desc,
	&bpf_arm64_extr_x_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_arm64_extr, "BpfReJIT arm64 kinsn: EXTR (EXTR)",
		       bpf_arm64_extr_kfunc_ids, bpf_arm64_extr_kinsn_descs);
