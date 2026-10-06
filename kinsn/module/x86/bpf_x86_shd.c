// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsn: SHLD/SHRD immediate.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_shldl(void) {}
__bpf_kfunc void bpf_x86_shldq(void) {}
__bpf_kfunc void bpf_x86_shrdl(void) {}
__bpf_kfunc void bpf_x86_shrdq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_shd_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_shldl)
BTF_ID_FLAGS(func, bpf_x86_shldq)
BTF_ID_FLAGS(func, bpf_x86_shrdl)
BTF_ID_FLAGS(func, bpf_x86_shrdq)
BTF_KFUNCS_END(bpf_x86_shd_kfunc_ids)

static __always_inline int decode_shd_payload(u64 payload, u8 *dst_reg,
					      u8 *src_reg, u8 *imm,
					      bool *arch_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*imm = kinsn_payload_u8(payload, 8);
	*arch_reg = !!(payload & (1ULL << 16));

	if (payload >> 17)
		return -EINVAL;
	if (!kinsn_x86_reg_is_bpf_writable(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;
	if (*arch_reg && *dst_reg != BPF_REG_10 && *src_reg != BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int shd_temp(u8 dst_reg, u8 src_reg)
{
	u8 reg;

	for (reg = BPF_REG_0; reg < BPF_REG_10; reg++) {
		if (reg != dst_reg && reg != src_reg)
			return reg;
	}
	return -EINVAL;
}

static int instantiate_shd_imm(u64 payload, struct bpf_insn *insn_buf,
			       bool is64, bool left)
{
	u8 dst_reg, src_reg, imm;
	u8 width = is64 ? 64 : 32;
	bool arch_reg;
	int temp;
	int err;

	err = decode_shd_payload(payload, &dst_reg, &src_reg, &imm, &arch_reg);
	if (err)
		return err;
	if (imm == 0 || imm >= width)
		return -EINVAL;
	temp = shd_temp(dst_reg, src_reg);
	if (temp < 0)
		return temp;
	insn_buf[0] = BPF_STX_MEM(BPF_DW, BPF_REG_10, temp, KINSN_X86_PROOF_RHS_OFF);
	insn_buf[1] = is64 ? BPF_MOV64_REG(temp, src_reg) : BPF_MOV32_REG(temp, src_reg);
	insn_buf[2] = is64 ? BPF_ALU64_IMM(left ? BPF_LSH : BPF_RSH, dst_reg, imm) :
			    BPF_ALU32_IMM(left ? BPF_LSH : BPF_RSH, dst_reg, imm);
	insn_buf[3] = is64 ? BPF_ALU64_IMM(left ? BPF_RSH : BPF_LSH, temp, width - imm) :
			    BPF_ALU32_IMM(left ? BPF_RSH : BPF_LSH, temp, width - imm);
	insn_buf[4] = is64 ? BPF_ALU64_REG(BPF_OR, dst_reg, temp) :
			    BPF_ALU32_REG(BPF_OR, dst_reg, temp);
	insn_buf[5] = BPF_LDX_MEM(BPF_DW, temp, BPF_REG_10, KINSN_X86_PROOF_RHS_OFF);
	return 6;
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
	u8 buf[24];
	u8 dst_reg, src_reg, imm;
	bool arch_reg;
	u32 len = 0;
	u8 frame = kinsn_x86_reg_for_prog(prog, BPF_REG_10);
	int temp;
	int err;

	err = decode_shd_payload(payload, &dst_reg, &src_reg, &imm,
				 &arch_reg);
	if (err)
		return err;
	if (imm == 0 || imm >= (is64 ? 64 : 32))
		return -EINVAL;

	temp = shd_temp(dst_reg, src_reg);
	if (temp < 0)
		return temp;
	temp = kinsn_x86_reg_for_prog(prog, temp);
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	/* Match the proof's temporary memory effects; MOV preserves SHD flags. */
	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(temp), false, kinsn_x86_ext(frame));
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_modrm_mem(buf, &len, temp, frame, KINSN_X86_PROOF_RHS_OFF);

	kinsn_emit_rex(buf, &len, is64, kinsn_x86_ext(src_reg), false,
		       kinsn_x86_ext(dst_reg));
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, left ? 0xa4 : 0xac);
	kinsn_emit_u8(buf, &len, 0xc0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));
	kinsn_emit_u8(buf, &len, imm);

	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(temp), false, kinsn_x86_ext(frame));
	kinsn_emit_u8(buf, &len, 0x8b);
	kinsn_emit_modrm_mem(buf, &len, temp, frame, KINSN_X86_PROOF_RHS_OFF);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_shldl_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, false, true);
}

static int emit_shldq_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, true, true);
}

static int emit_shrdl_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, false, false);
}

static int emit_shrdq_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_shd_imm_x86(image, off, emit, payload, prog, true, false);
}

const struct bpf_kinsn bpf_x86_shldl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_shldl_imm,
	.emit_x86 = emit_shldl_imm_x86,
};

const struct bpf_kinsn bpf_x86_shldq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_shldq_imm,
	.emit_x86 = emit_shldq_imm_x86,
};

const struct bpf_kinsn bpf_x86_shrdl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_shrdl_imm,
	.emit_x86 = emit_shrdl_imm_x86,
};

const struct bpf_kinsn bpf_x86_shrdq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
	.max_emit_bytes = 24,
	.instantiate_insn = instantiate_shrdq_imm,
	.emit_x86 = emit_shrdq_imm_x86,
};

static const struct bpf_kinsn * const bpf_x86_shd_kinsn_descs[] = {
	&bpf_x86_shldl_desc,
	&bpf_x86_shldq_desc,
	&bpf_x86_shrdl_desc,
	&bpf_x86_shrdq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_shd,
		       "BpfReJIT x86 kinsn: SHLD/SHRD immediate",
		       bpf_x86_shd_kfunc_ids, bpf_x86_shd_kinsn_descs);
