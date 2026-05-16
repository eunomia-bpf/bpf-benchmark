// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: BMI1 scalar bit instructions.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_blsiq(void) {}
__bpf_kfunc void bpf_x86_blsrq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_bmi1_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_blsiq)
BTF_ID_FLAGS(func, bpf_x86_blsrq)
BTF_KFUNCS_END(bpf_x86_bmi1_kfunc_ids)

static __always_inline int decode_bmi1_payload(u64 payload, u8 *dst_reg,
					       u8 *src_reg, u8 *tmp_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*tmp_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *src_reg >= BPF_REG_10 ||
	    *tmp_reg >= BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;

	return 0;
}

static int instantiate_blsiq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg;
	int cnt = 0;
	int err;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg, &tmp_reg);
	if (err)
		return err;

	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_MOV64_IMM(tmp_reg, 0);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_SUB, tmp_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, dst_reg, tmp_reg);
	return cnt;
}

static int instantiate_blsrq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg;
	int cnt = 0;
	int err;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg, &tmp_reg);
	if (err)
		return err;

	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(tmp_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, tmp_reg, -1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, dst_reg, tmp_reg);
	return cnt;
}

static __always_inline u8 kinsn_x86_reg_no(u8 reg)
{
	return kinsn_x86_code(reg) | (kinsn_x86_ext(reg) ? 8 : 0);
}

static void emit_bmi1_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg,
			 u8 opcode_ext)
{
	u8 vex2 = 0xe2;
	u8 dst_no = kinsn_x86_reg_no(dst_reg);
	u8 vex3 = 0x80 | (((~dst_no) & 0xf) << 3);

	if (kinsn_x86_ext(src_reg))
		vex2 &= ~0x20;

	kinsn_emit_u8(buf, len, 0xc4);
	kinsn_emit_u8(buf, len, vex2);
	kinsn_emit_u8(buf, len, vex3);
	kinsn_emit_u8(buf, len, 0xf3);
	kinsn_emit_u8(buf, len, 0xc0 |
		       (opcode_ext << 3) |
		       kinsn_x86_code(src_reg));
}

static int emit_bmi1_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog, u8 opcode_ext)
{
	u8 buf[8];
	u8 dst_reg, src_reg, tmp_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!boot_cpu_has(X86_FEATURE_BMI1))
		return -EOPNOTSUPP;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg, &tmp_reg);
	if (err)
		return err;
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	emit_bmi1_rr(buf, &len, dst_reg, src_reg, opcode_ext);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_blsiq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog)
{
	return emit_bmi1_x86(image, off, emit, payload, prog, 3);
}

static int emit_blsrq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog)
{
	return emit_bmi1_x86(image, off, emit, payload, prog, 1);
}

const struct bpf_kinsn bpf_x86_blsiq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_blsiq,
	.emit_x86 = emit_blsiq_x86,
};

const struct bpf_kinsn bpf_x86_blsrq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_blsrq,
	.emit_x86 = emit_blsrq_x86,
};

static const struct bpf_kinsn * const bpf_x86_bmi1_kinsn_descs[] = {
	&bpf_x86_blsiq_desc,
	&bpf_x86_blsrq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_bmi1,
		       "BpfReJIT x86 kinsns: BMI1 BLSI/BLSR",
		       bpf_x86_bmi1_kfunc_ids,
		       bpf_x86_bmi1_kinsn_descs);
