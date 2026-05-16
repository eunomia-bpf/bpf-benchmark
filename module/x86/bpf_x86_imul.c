// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: IMUL.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_imulq_rr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_imul_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_imulq_rr)
BTF_KFUNCS_END(bpf_x86_imul_kfunc_ids)

static __always_inline int decode_imul_rr_payload(u64 payload, u8 *dst_reg,
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

static int instantiate_imulq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	u32 scratch_mask;
	int cnt = 0;
	int err;

	err = decode_imul_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_ALU64_REG(BPF_MUL, dst_reg, src_reg);
		return 1;
	}
	scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0) |
		       KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH1);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, dst_reg);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH1, src_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MUL, KINSN_X86_SCRATCH0,
					KINSN_X86_SCRATCH1);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_imulq_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_imul_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0xaf);
	kinsn_emit_u8(buf, &len, 0xc0 |
		      (kinsn_x86_code(dst_reg) << 3) |
		      kinsn_x86_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_imulq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 8 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_imulq_rr,
	.emit_x86 = emit_imulq_rr_x86,
};

static const struct bpf_kinsn * const bpf_x86_imul_kinsn_descs[] = {
	&bpf_x86_imulq_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_imul, "BpfReJIT x86 kinsns: IMUL",
		       bpf_x86_imul_kfunc_ids, bpf_x86_imul_kinsn_descs);
