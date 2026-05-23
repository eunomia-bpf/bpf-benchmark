// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: stack instructions.
 *
 * These are machine-instruction kinsns.  The verifier proof updates the
 * module-owned x86 shadow stack pointer; final x86 emission is exactly one
 * pushq/popq instruction.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_popq(void) {}
__bpf_kfunc void bpf_x86_pushq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_stack_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_popq)
BTF_ID_FLAGS(func, bpf_x86_pushq)
BTF_KFUNCS_END(bpf_x86_stack_kfunc_ids)

static __always_inline int decode_stack_reg(u64 payload, u8 *reg)
{
	payload = kinsn_payload_decode(payload);
	*reg = kinsn_payload_reg(payload, 0);
	if (payload >> 4)
		return -EINVAL;
	if (!kinsn_x86_valid(*reg))
		return -EINVAL;
	return 0;
}

static int instantiate_pushq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_stack_reg(payload, &src_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			      KINSN_X86_REG_RSP);
	kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH1, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, KINSN_X86_SCRATCH0, -8);
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, KINSN_X86_SCRATCH0,
				      KINSN_X86_SCRATCH1, 0);
	kinsn_x86_write64_arch(insn_buf, &cnt, KINSN_X86_REG_RSP,
			       KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_popq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_stack_reg(payload, &dst_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
			      KINSN_X86_REG_RSP);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, KINSN_X86_SCRATCH1,
				      KINSN_X86_SCRATCH0, 0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, KINSN_X86_SCRATCH0, 8);
	if (dst_reg == KINSN_X86_REG_RSP) {
		kinsn_x86_write64_arch(insn_buf, &cnt, KINSN_X86_REG_RSP,
				       KINSN_X86_SCRATCH1, scratch_mask);
	} else {
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH1, scratch_mask);
		kinsn_x86_write64_arch(insn_buf, &cnt, KINSN_X86_REG_RSP,
				       KINSN_X86_SCRATCH0, scratch_mask);
	}
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_stack_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 opcode_base)
{
	u8 buf[2];
	u8 reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_stack_reg(payload, &reg);
	if (err)
		return err;

	kinsn_emit_rex(buf, &len, false, false, false, kinsn_x86_ext(reg));
	kinsn_emit_u8(buf, &len, opcode_base + kinsn_x86_code(reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_popq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_stack_reg_x86(image, off, emit, payload, prog, 0x58);
}

static int emit_pushq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_stack_reg_x86(image, off, emit, payload, prog, 0x50);
}

const struct bpf_kinsn bpf_x86_popq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 2,
	.instantiate_insn = instantiate_popq,
	.emit_x86 = emit_popq_x86,
};

const struct bpf_kinsn bpf_x86_pushq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 2,
	.instantiate_insn = instantiate_pushq,
	.emit_x86 = emit_pushq_x86,
};

static const struct bpf_kinsn * const bpf_x86_stack_kinsn_descs[] = {
	&bpf_x86_popq_desc,
	&bpf_x86_pushq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_stack,
		       "BpfReJIT x86 kinsns: stack",
		       bpf_x86_stack_kfunc_ids,
		       bpf_x86_stack_kinsn_descs);
