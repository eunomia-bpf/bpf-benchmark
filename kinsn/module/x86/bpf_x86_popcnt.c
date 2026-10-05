// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kop: POPCNT r64, r/m64.
 */

#include <asm/cpufeature.h>

#include "kop_x86_emit.h"

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
	payload = kop_payload_decode(payload);
	*arch_reg = (payload & 0xf) == X86_FORM_ARCH_RR;
	if ((payload & 0xf) != X86_FORM_RR &&
	    (payload & 0xf) != X86_FORM_ARCH_RR)
		return -EINVAL;
	*dst_reg = kop_payload_reg(payload, 4);
	*src_reg = kop_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!kop_x86_operand_valid(*dst_reg) ||
	    !kop_x86_operand_valid(*src_reg))
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

static int instantiate_popcntq_bpf(u8 dst_reg, u8 src_reg,
				   struct bpf_insn *insn_buf)
{
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1);
	int cnt = 0;

	if (kop_x86_is_scratch(dst_reg) || kop_x86_is_scratch(src_reg))
		return -EINVAL;

	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);

	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH0, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH0, 1);
	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH1,
		     0x5555555555555555ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_SUB, dst_reg,
					KOP_X86_SCRATCH0);

	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH0, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH0, 2);
	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH1,
		     0x3333333333333333ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, dst_reg,
					KOP_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg,
					KOP_X86_SCRATCH0);

	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH0, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH0, 4);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg,
					KOP_X86_SCRATCH0);
	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH1,
		     0x0f0f0f0f0f0f0f0fULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, dst_reg,
					KOP_X86_SCRATCH1);

	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH1,
		     0x0101010101010101ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MUL, dst_reg,
					KOP_X86_SCRATCH1);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, 56);
	kop_x86_write64(insn_buf, &cnt, dst_reg, dst_reg, scratch_mask);
	kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_popcntq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH2);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg, &arch_reg);
	if (err)
		return err;
	if (!arch_reg) {
		err = instantiate_popcntq_bpf(dst_reg, src_reg, insn_buf);
		if (err != -EINVAL)
			return err;
	}

	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kop_x86_read64_arch(insn_buf, &cnt, KOP_X86_SCRATCH0,
				      src_reg);
	else
		kop_x86_read64(insn_buf, &cnt, KOP_X86_SCRATCH0,
				 src_reg);

	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH1,
					KOP_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH1, 1);
	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH2,
		     0x5555555555555555ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH1,
					KOP_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_SUB, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH1);

	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH1,
					KOP_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH1, 2);
	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH2,
		     0x3333333333333333ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH1,
					KOP_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH1);

	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH1,
					KOP_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH1, 4);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH1);
	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH2,
		     0x0f0f0f0f0f0f0f0fULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH2);

	emit_ldimm64(insn_buf, &cnt, KOP_X86_SCRATCH2,
		     0x0101010101010101ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MUL, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH2);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, KOP_X86_SCRATCH0, 56);
	if (arch_reg)
		kop_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KOP_X86_SCRATCH0, scratch_mask);
	else
		kop_x86_write64(insn_buf, &cnt, dst_reg,
				  KOP_X86_SCRATCH0, scratch_mask);
	kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_popcntq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog,
			 const u8 *final_ip)
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
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
		src_reg = kop_x86_reg_for_prog(prog, src_reg);
	}
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(src_reg))
		return -EINVAL;

	kop_emit_u8(buf, &len, 0xf3);
	kop_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kop_emit_u8(buf, &len, 0x0f);
	kop_emit_u8(buf, &len, 0xb8);
	kop_emit_u8(buf, &len, 0xc0 |
		       (kop_x86_code(dst_reg) << 3) |
		       kop_x86_code(src_reg));

	return kop_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kop bpf_x86_popcntq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 32 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_popcntq,
	.emit_x86 = emit_popcntq_x86,
};

static const struct bpf_kop * const bpf_x86_popcnt_kop_descs[] = {
	&bpf_x86_popcntq_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_popcnt,
		       "BpfReJIT x86 kop: POPCNT",
		       bpf_x86_popcnt_kfunc_ids,
		       bpf_x86_popcnt_kop_descs);
