// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: SHLD/SHRD immediate.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_shldl_imm(void) {}
__bpf_kfunc void bpf_x86_shldq_imm(void) {}
__bpf_kfunc void bpf_x86_shrdl_imm(void) {}
__bpf_kfunc void bpf_x86_shrdq_imm(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_shd_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_shldl_imm)
BTF_ID_FLAGS(func, bpf_x86_shldq_imm)
BTF_ID_FLAGS(func, bpf_x86_shrdl_imm)
BTF_ID_FLAGS(func, bpf_x86_shrdq_imm)
BTF_KFUNCS_END(bpf_x86_shd_kfunc_ids)

static __always_inline int decode_shd_payload(u64 payload, u8 *dst_reg,
					      u8 *src_reg, u8 *imm,
					      u8 *tmp_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*imm = kinsn_payload_u8(payload, 8);
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (payload >> 20)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *src_reg >= BPF_REG_10 ||
	    *tmp_reg >= BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*src_reg) ||
	    !kinsn_x86_reg_valid(*tmp_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_shd_imm(u64 payload, struct bpf_insn *insn_buf,
			       bool is64, bool left)
{
	u8 dst_reg, src_reg, imm, tmp_reg;
	u8 width = is64 ? 64 : 32;
	int err;

	err = decode_shd_payload(payload, &dst_reg, &src_reg, &imm, &tmp_reg);
	if (err)
		return err;
	if (imm == 0 || imm >= width)
		return -EINVAL;

	if (is64) {
		insn_buf[0] = BPF_MOV64_REG(tmp_reg, src_reg);
		if (left) {
			insn_buf[1] = BPF_ALU64_IMM(BPF_RSH, tmp_reg, width - imm);
			insn_buf[2] = BPF_ALU64_IMM(BPF_LSH, dst_reg, imm);
		} else {
			insn_buf[1] = BPF_ALU64_IMM(BPF_LSH, tmp_reg, width - imm);
			insn_buf[2] = BPF_ALU64_IMM(BPF_RSH, dst_reg, imm);
		}
		insn_buf[3] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	} else {
		insn_buf[0] = BPF_MOV32_REG(tmp_reg, src_reg);
		if (left) {
			insn_buf[1] = BPF_ALU32_IMM(BPF_RSH, tmp_reg, width - imm);
			insn_buf[2] = BPF_ALU32_IMM(BPF_LSH, dst_reg, imm);
		} else {
			insn_buf[1] = BPF_ALU32_IMM(BPF_LSH, tmp_reg, width - imm);
			insn_buf[2] = BPF_ALU32_IMM(BPF_RSH, dst_reg, imm);
		}
		insn_buf[3] = BPF_ALU32_REG(BPF_OR, dst_reg, tmp_reg);
	}
	return 4;
}

static int instantiate_shldl_imm(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_shd_imm(payload, insn_buf, false, true);
}

static int instantiate_shldq_imm(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_shd_imm(payload, insn_buf, true, true);
}

static int instantiate_shrdl_imm(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_shd_imm(payload, insn_buf, false, false);
}

static int instantiate_shrdq_imm(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_shd_imm(payload, insn_buf, true, false);
}

static int emit_shd_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, bool is64,
			    bool left)
{
	u8 buf[8];
	u8 dst_reg, src_reg, imm, tmp_reg;
	u32 len = 0;
	int err;

	err = decode_shd_payload(payload, &dst_reg, &src_reg, &imm, &tmp_reg);
	if (err)
		return err;
	if (imm == 0 || imm >= (is64 ? 64 : 32))
		return -EINVAL;
	(void)tmp_reg;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, is64, kinsn_x86_ext(src_reg), false,
		       kinsn_x86_ext(dst_reg));
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, left ? 0xa4 : 0xac);
	kinsn_emit_u8(buf, &len, 0xc0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));
	kinsn_emit_u8(buf, &len, imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_shldl_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, false, true);
}

static int emit_shldq_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, true, true);
}

static int emit_shrdl_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, false, false);
}

static int emit_shrdq_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, true, false);
}

const struct bpf_kinsn bpf_x86_shldl_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 5,
	.instantiate_insn = instantiate_shldl_imm,
	.emit_x86 = emit_shldl_imm_x86,
};

const struct bpf_kinsn bpf_x86_shldq_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 5,
	.instantiate_insn = instantiate_shldq_imm,
	.emit_x86 = emit_shldq_imm_x86,
};

const struct bpf_kinsn bpf_x86_shrdl_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 5,
	.instantiate_insn = instantiate_shrdl_imm,
	.emit_x86 = emit_shrdl_imm_x86,
};

const struct bpf_kinsn bpf_x86_shrdq_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 5,
	.instantiate_insn = instantiate_shrdq_imm,
	.emit_x86 = emit_shrdq_imm_x86,
};

static const struct bpf_kinsn * const bpf_x86_shd_kinsn_descs[] = {
	&bpf_x86_shldl_imm_desc,
	&bpf_x86_shldq_imm_desc,
	&bpf_x86_shrdl_imm_desc,
	&bpf_x86_shrdq_imm_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_shd,
		       "BpfReJIT x86 kinsns: SHLD/SHRD immediate",
		       bpf_x86_shd_kfunc_ids, bpf_x86_shd_kinsn_descs);
