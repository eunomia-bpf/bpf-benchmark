// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 koperation: IMUL.
 */

#include "kop_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_imulq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_imul_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_imulq)
BTF_KFUNCS_END(bpf_x86_imul_kfunc_ids)

#define X86_FORM_RR		1
#define X86_FORM_ARCH_RR	12

static __always_inline int decode_imul_rr_payload(u64 payload, u8 *dst_reg,
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

static int instantiate_imulq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask;
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_imul_rr_payload(payload, &dst_reg, &src_reg, &arch_reg);
	if (err)
		return err;

	if (!arch_reg &&
	    !kop_x86_reg_uses_stack_slot(dst_reg) &&
	    !kop_x86_reg_uses_stack_slot(src_reg)) {
		insn_buf[0] = BPF_ALU64_REG(BPF_MUL, dst_reg, src_reg);
		return 1;
	}
	scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0) |
		       KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1);
	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg) {
		kop_x86_read64_arch(insn_buf, &cnt, KOP_X86_SCRATCH0,
				      dst_reg);
		kop_x86_read64_arch(insn_buf, &cnt, KOP_X86_SCRATCH1,
				      src_reg);
	} else {
		kop_x86_read64(insn_buf, &cnt, KOP_X86_SCRATCH0,
				 dst_reg);
		kop_x86_read64(insn_buf, &cnt, KOP_X86_SCRATCH1,
				 src_reg);
	}
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MUL, KOP_X86_SCRATCH0,
					KOP_X86_SCRATCH1);
	if (arch_reg)
		kop_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KOP_X86_SCRATCH0, scratch_mask);
	else
		kop_x86_write64(insn_buf, &cnt, dst_reg,
				  KOP_X86_SCRATCH0, scratch_mask);
	kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_imulq_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_imul_rr_payload(payload, &dst_reg, &src_reg, &arch_reg);
	if (err)
		return err;

	if (!arch_reg) {
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
		src_reg = kop_x86_reg_for_prog(prog, src_reg);
	}
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(src_reg))
		return -EINVAL;

	kop_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kop_emit_u8(buf, &len, 0x0f);
	kop_emit_u8(buf, &len, 0xaf);
	kop_emit_u8(buf, &len, 0xc0 |
		      (kop_x86_code(dst_reg) << 3) |
		      kop_x86_code(src_reg));

	return kop_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kop bpf_x86_imulq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 8 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_imulq_rr,
	.emit_x86 = emit_imulq_rr_x86,
};

static const struct bpf_kop * const bpf_x86_imul_kop_descs[] = {
	&bpf_x86_imulq_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_imul, "BpfReJIT x86 koperation: IMUL",
		       bpf_x86_imul_kfunc_ids, bpf_x86_imul_kop_descs);
