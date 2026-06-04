// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: fused CMP + CMOV.
 *
 * Standalone CMP/TEST/SETcc/CMOV kinsns need a cross-kinsn flags channel.
 * Keep this module to single-basic-block fused forms that prove themselves
 * directly with BPF conditional branches and introduce no module-private
 * private flag state.
 */

#include "kinsn_x86_emit.h"

#define X86_OPERAND_FORM_RR 1

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_cmp_cmove(void) {}
__bpf_kfunc void bpf_x86_cmp_cmovne(void) {}
__bpf_kfunc void bpf_x86_cmp_cmovb(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_cmov_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_cmp_cmovb)
BTF_ID_FLAGS(func, bpf_x86_cmp_cmove)
BTF_ID_FLAGS(func, bpf_x86_cmp_cmovne)
BTF_KFUNCS_END(bpf_x86_cmov_kfunc_ids)

enum cmp_cmov_cond {
	CMP_CMOV_EQ,
	CMP_CMOV_NE,
	CMP_CMOV_B,
};

static __always_inline int decode_cmp_cmov_rr_payload(u64 payload,
						      u8 *left_reg,
						      u8 *right_reg,
						      u8 *dst_reg,
						      u8 *src_reg,
						      bool *cmp32,
						      bool *value32)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_OPERAND_FORM_RR || payload >> 22)
		return -EINVAL;

	*left_reg = kinsn_payload_reg(payload, 4);
	*right_reg = kinsn_payload_reg(payload, 8);
	*dst_reg = kinsn_payload_reg(payload, 12);
	*src_reg = kinsn_payload_reg(payload, 16);
	*cmp32 = payload & (1ULL << 20);
	*value32 = payload & (1ULL << 21);

	if (!kinsn_x86_operand_valid(*left_reg) ||
	    !kinsn_x86_operand_valid(*right_reg) ||
	    !kinsn_bpf_gpr_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;
	return 0;
}

static int instantiate_cmp_cmov_rr(u64 payload, struct bpf_insn *insn_buf,
				   enum cmp_cmov_cond cond)
{
	u8 left_reg, right_reg, dst_reg, src_reg;
	bool cmp32, value32;
	u8 jmp_op;
	int cnt = 0;
	int err;

	err = decode_cmp_cmov_rr_payload(payload, &left_reg, &right_reg,
					 &dst_reg, &src_reg, &cmp32,
					 &value32);
	if (err)
		return err;

	switch (cond) {
	case CMP_CMOV_EQ:
		jmp_op = BPF_JNE;
		break;
	case CMP_CMOV_NE:
		jmp_op = BPF_JEQ;
		break;
	case CMP_CMOV_B:
		jmp_op = BPF_JGE;
		break;
	default:
		return -EINVAL;
	}

	insn_buf[cnt++] = cmp32 ? BPF_JMP32_REG(jmp_op, left_reg, right_reg, 1) :
				  BPF_JMP_REG(jmp_op, left_reg, right_reg, 1);
	insn_buf[cnt++] = value32 ? BPF_MOV32_REG(dst_reg, src_reg) :
				    BPF_MOV64_REG(dst_reg, src_reg);
	return cnt;
}

static int instantiate_cmp_cmove(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmp_cmov_rr(payload, insn_buf, CMP_CMOV_EQ);
}

static int instantiate_cmp_cmovne(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmp_cmov_rr(payload, insn_buf, CMP_CMOV_NE);
}

static int instantiate_cmp_cmovb(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmp_cmov_rr(payload, insn_buf, CMP_CMOV_B);
}

static int emit_cmp_cmov_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog, u8 cc)
{
	u8 buf[16];
	u8 left_reg, right_reg, dst_reg, src_reg;
	bool cmp32, value32;
	u32 len = 0;
	int err;

	err = decode_cmp_cmov_rr_payload(payload, &left_reg, &right_reg,
					 &dst_reg, &src_reg, &cmp32,
					 &value32);
	if (err)
		return err;

	left_reg = kinsn_x86_reg_for_prog(prog, left_reg);
	right_reg = kinsn_x86_reg_for_prog(prog, right_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(left_reg) || !kinsn_x86_valid(right_reg) ||
	    !kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, !cmp32, right_reg, left_reg);
	kinsn_emit_u8(buf, &len, 0x39);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(right_reg) << 3) |
		kinsn_x86_reg_code(left_reg));
	kinsn_emit_rex_rr(buf, &len, !value32, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0F);
	kinsn_emit_u8(buf, &len, cc);
	kinsn_emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_cmp_cmove_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			      const u8 *final_ip)
{
	(void)final_ip;
	return emit_cmp_cmov_rr_x86(image, off, emit, payload, prog, 0x44);
}

static int emit_cmp_cmovne_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog,
			       const u8 *final_ip)
{
	(void)final_ip;
	return emit_cmp_cmov_rr_x86(image, off, emit, payload, prog, 0x45);
}

static int emit_cmp_cmovb_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog,
			      const u8 *final_ip)
{
	(void)final_ip;
	return emit_cmp_cmov_rr_x86(image, off, emit, payload, prog, 0x42);
}

const struct bpf_kinsn bpf_x86_cmp_cmove_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_cmp_cmove,
	.emit_x86 = emit_cmp_cmove_x86,
};

const struct bpf_kinsn bpf_x86_cmp_cmovne_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_cmp_cmovne,
	.emit_x86 = emit_cmp_cmovne_x86,
};

const struct bpf_kinsn bpf_x86_cmp_cmovb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_cmp_cmovb,
	.emit_x86 = emit_cmp_cmovb_x86,
};

static const struct bpf_kinsn * const bpf_x86_cmov_kinsn_descs[] = {
	&bpf_x86_cmp_cmovb_desc,
	&bpf_x86_cmp_cmove_desc,
	&bpf_x86_cmp_cmovne_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_cmov, "BpfReJIT x86 kinsns: fused CMP/CMOV",
		       bpf_x86_cmov_kfunc_ids, bpf_x86_cmov_kinsn_descs);
