// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: BMI1 scalar bit instructions.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_bextrq(void) {}
__bpf_kfunc void bpf_x86_blsiq(void) {}
__bpf_kfunc void bpf_x86_blsrq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_bmi1_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_bextrq)
BTF_ID_FLAGS(func, bpf_x86_blsiq)
BTF_ID_FLAGS(func, bpf_x86_blsrq)
BTF_KFUNCS_END(bpf_x86_bmi1_kfunc_ids)

static __always_inline int decode_bmi1_payload(u64 payload, u8 *dst_reg,
					       u8 *src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_bextr_payload(u64 payload, u8 *dst_reg,
						u8 *src_reg, u8 *ctl_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*ctl_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg) ||
	    !kinsn_x86_operand_valid(*ctl_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_bextrq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, ctl_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	u32 restore_mask;
	int j_start_ge, j_len_eq, j_len_ge, j_done;
	int zero_label, write_label;
	int cnt = 0;
	int err;

	err = decode_bextr_payload(payload, &dst_reg, &src_reg, &ctl_reg);
	if (err)
		return err;
	restore_mask = scratch_mask;
	if (kinsn_x86_is_scratch(dst_reg))
		restore_mask &= ~KINSN_X86_SCRATCH_MASK(dst_reg);

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, src_reg);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1, ctl_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH2,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH2, 0xff);
	j_start_ge = cnt;
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JGE, KINSN_X86_SCRATCH2, 64, 0);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_RSH, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KINSN_X86_SCRATCH1, 8);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KINSN_X86_SCRATCH1, 0xff);
	j_len_eq = cnt;
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JEQ, KINSN_X86_SCRATCH1, 0, 0);
	j_len_ge = cnt;
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JGE, KINSN_X86_SCRATCH1, 64, 0);
	insn_buf[cnt++] = BPF_MOV64_IMM(KINSN_X86_SCRATCH2, 1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_LSH, KINSN_X86_SCRATCH2,
					KINSN_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, KINSN_X86_SCRATCH2, -1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);
	write_label = cnt;
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, restore_mask);
	j_done = cnt;
	insn_buf[cnt++] = BPF_JMP_A(0);
	zero_label = cnt;
	insn_buf[cnt++] = BPF_MOV64_IMM(KINSN_X86_SCRATCH0, 0);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, restore_mask);

	insn_buf[j_start_ge].off = zero_label - j_start_ge - 1;
	insn_buf[j_len_eq].off = zero_label - j_len_eq - 1;
	insn_buf[j_len_ge].off = write_label - j_len_ge - 1;
	insn_buf[j_done].off = cnt - j_done - 1;
	return cnt;
}

static int instantiate_blsiq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, src_reg);
	insn_buf[cnt++] = BPF_MOV64_IMM(KINSN_X86_SCRATCH1, 0);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_SUB, KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_blsrq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, src_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, KINSN_X86_SCRATCH1, -1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
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

static void emit_bextr_rrr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg,
			   u8 ctl_reg)
{
	u8 vex2 = 0xe2;
	u8 ctl_no = kinsn_x86_reg_no(ctl_reg);

	if (kinsn_x86_ext(dst_reg))
		vex2 &= ~0x80;
	if (kinsn_x86_ext(src_reg))
		vex2 &= ~0x20;

	kinsn_emit_u8(buf, len, 0xc4);
	kinsn_emit_u8(buf, len, vex2);
	kinsn_emit_u8(buf, len, 0x80 | (((~ctl_no) & 0xf) << 3));
	kinsn_emit_u8(buf, len, 0xf7);
	kinsn_emit_u8(buf, len, 0xc0 |
		       (kinsn_x86_code(dst_reg) << 3) |
		       kinsn_x86_code(src_reg));
}

static int emit_bextrq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 buf[8];
	u8 dst_reg, src_reg, ctl_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_BMI1))
		return -EOPNOTSUPP;

	err = decode_bextr_payload(payload, &dst_reg, &src_reg, &ctl_reg);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	ctl_reg = kinsn_x86_reg_for_prog(prog, ctl_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg) ||
	    !kinsn_x86_valid(ctl_reg))
		return -EINVAL;

	emit_bextr_rrr(buf, &len, dst_reg, src_reg, ctl_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_bmi1_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog, u8 opcode_ext)
{
	u8 buf[8];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_BMI1))
		return -EOPNOTSUPP;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	emit_bmi1_rr(buf, &len, dst_reg, src_reg, opcode_ext);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_blsiq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_bmi1_x86(image, off, emit, payload, prog, 3);
}

static int emit_blsrq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_bmi1_x86(image, off, emit, payload, prog, 1);
}

const struct bpf_kinsn bpf_x86_bextrq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 21 + KINSN_X86_SAVE_RESTORE_INSN_CNT * 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_bextrq,
	.emit_x86 = emit_bextrq_x86,
};

const struct bpf_kinsn bpf_x86_blsiq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 8 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_blsiq,
	.emit_x86 = emit_blsiq_x86,
};

const struct bpf_kinsn bpf_x86_blsrq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 8 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_blsrq,
	.emit_x86 = emit_blsrq_x86,
};

static const struct bpf_kinsn * const bpf_x86_bmi1_kinsn_descs[] = {
	&bpf_x86_bextrq_desc,
	&bpf_x86_blsiq_desc,
	&bpf_x86_blsrq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_bmi1,
		       "BpfReJIT x86 kinsns: BMI1 BEXTR/BLSI/BLSR",
		       bpf_x86_bmi1_kfunc_ids,
		       bpf_x86_bmi1_kinsn_descs);
