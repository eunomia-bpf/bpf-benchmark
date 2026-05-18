// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsn: POPCNT r64, r/m64.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_popcntq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_popcnt_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_popcntq)
BTF_KFUNCS_END(bpf_x86_popcnt_kfunc_ids)

#define X86_FORM_RR		1
#define X86_FORM_ARCH_RR	12

static __always_inline int decode_popcnt_payload(u64 payload, u8 *dst_reg,
						 u8 *src_reg,
						 bool *arch_reg)
{
	payload = kinsn_payload_decode(payload);
	*arch_reg = (payload & 0xf) == X86_FORM_ARCH_RR;
	if ((payload & 0xf) != X86_FORM_RR &&
	    (payload & 0xf) != X86_FORM_ARCH_RR)
		return -EINVAL;
	*dst_reg = kinsn_payload_reg(payload, 4);
	*src_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static __always_inline void emit_ldimm64(struct bpf_insn *insn_buf, int *cnt,
					 u8 dst_reg, u64 imm)
{
	struct bpf_insn insns[] = { BPF_LD_IMM64(dst_reg, imm) };

	insn_buf[(*cnt)++] = insns[0];
	insn_buf[(*cnt)++] = insns[1];
}

static int instantiate_popcntq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1) |
			   KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH2);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg, &arch_reg);
	if (err)
		return err;

	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kinsn_x86_read64_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      src_reg);
	else
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				 src_reg);

	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KINSN_X86_SCRATCH1, 1);
	emit_ldimm64(insn_buf, &cnt, KINSN_X86_SCRATCH2,
		     0x5555555555555555ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_SUB, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);

	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KINSN_X86_SCRATCH1, 2);
	emit_ldimm64(insn_buf, &cnt, KINSN_X86_SCRATCH2,
		     0x3333333333333333ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);

	insn_buf[cnt++] = BPF_MOV64_REG(KINSN_X86_SCRATCH1,
					KINSN_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KINSN_X86_SCRATCH1, 4);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	emit_ldimm64(insn_buf, &cnt, KINSN_X86_SCRATCH2,
		     0x0f0f0f0f0f0f0f0fULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);

	emit_ldimm64(insn_buf, &cnt, KINSN_X86_SCRATCH2,
		     0x0101010101010101ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MUL, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KINSN_X86_SCRATCH0, 56);
	if (arch_reg)
		kinsn_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
	else
		kinsn_x86_write64(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_popcntq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, src_reg;
	bool arch_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_POPCNT))
		return -EOPNOTSUPP;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg, &arch_reg);
	if (err)
		return err;
	if (!arch_reg) {
		dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
		src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	}
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_u8(buf, &len, 0xf3);
	kinsn_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0xb8);
	kinsn_emit_u8(buf, &len, 0xc0 |
		       (kinsn_x86_code(dst_reg) << 3) |
		       kinsn_x86_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_popcntq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 32 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_popcntq,
	.emit_x86 = emit_popcntq_x86,
};

static const struct bpf_kinsn * const bpf_x86_popcnt_kinsn_descs[] = {
	&bpf_x86_popcntq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_popcnt,
		       "BpfReJIT x86 kinsn: POPCNT",
		       bpf_x86_popcnt_kfunc_ids,
		       bpf_x86_popcnt_kinsn_descs);
