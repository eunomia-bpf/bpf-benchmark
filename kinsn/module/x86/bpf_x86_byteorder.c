// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 koperation: byte-order instructions.
 */

#include "kop_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_rolw(void) {}
__bpf_kfunc void bpf_x86_bswapl(void) {}
__bpf_kfunc void bpf_x86_bswapq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_byteorder_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_bswapl)
BTF_ID_FLAGS(func, bpf_x86_bswapq)
BTF_ID_FLAGS(func, bpf_x86_rolw)
BTF_KFUNCS_END(bpf_x86_byteorder_kfunc_ids)

#define X86_FORM_IMM		2
#define X86_FORM_ARCH_IMM	13

static __always_inline int decode_reg_payload(u64 payload, u8 *dst_reg,
					      bool *arch_reg)
{
	payload = kop_payload_decode(payload);
	*arch_reg = (payload & 0xf) == X86_FORM_ARCH_IMM;
	if ((payload & 0xf) != X86_FORM_IMM &&
	    (payload & 0xf) != X86_FORM_ARCH_IMM)
		return -EINVAL;
	*dst_reg = kop_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!kop_x86_operand_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_imm_payload(u64 payload, u8 *dst_reg,
						  u8 *imm, bool *arch_reg)
{
	payload = kop_payload_decode(payload);
	*arch_reg = (payload & 0xf) == X86_FORM_ARCH_IMM;
	if ((payload & 0xf) != X86_FORM_IMM &&
	    (payload & 0xf) != X86_FORM_ARCH_IMM)
		return -EINVAL;
	*dst_reg = kop_payload_reg(payload, 4);
	*imm = kop_payload_u8(payload, 8);

	if (payload >> 16)
		return -EINVAL;
	if (!kop_x86_operand_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_rolw_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, imm;
	bool arch_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	(void)arch_reg;
	if (imm != 8)
		return -EINVAL;

	if (arch_reg) {
		kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		kop_x86_read32_arch(insn_buf, &cnt, KOP_X86_SCRATCH0,
				      dst_reg);
		insn_buf[cnt++] = BPF_BSWAP(KOP_X86_SCRATCH0, 16);
		kop_x86_write32_arch(insn_buf, &cnt, dst_reg,
				       KOP_X86_SCRATCH0, scratch_mask);
		kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}
	insn_buf[0] = BPF_BSWAP(dst_reg, 16);
	return 1;
}

static int instantiate_bswap(u64 payload, struct bpf_insn *insn_buf, u8 bits)
{
	u8 dst_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_reg_payload(payload, &dst_reg, &arch_reg);
	if (err)
		return err;

	if (arch_reg || kop_x86_reg_uses_stack_slot(dst_reg)) {
		kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		if (arch_reg)
			kop_x86_read64_arch(insn_buf, &cnt,
					      KOP_X86_SCRATCH0, dst_reg);
		else
			kop_x86_read64(insn_buf, &cnt,
					  KOP_X86_SCRATCH0, dst_reg);
		insn_buf[cnt++] = BPF_BSWAP(KOP_X86_SCRATCH0, bits);
		if (arch_reg)
			kop_x86_write64_arch(insn_buf, &cnt, dst_reg,
					       KOP_X86_SCRATCH0,
					       scratch_mask);
		else
			kop_x86_write64(insn_buf, &cnt, dst_reg,
					  KOP_X86_SCRATCH0, scratch_mask);
		kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}
	insn_buf[0] = BPF_BSWAP(dst_reg, bits);
	return 1;
}

static int instantiate_bswapl(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bswap(payload, insn_buf, 32);
}

static int instantiate_bswapq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bswap(payload, insn_buf, 64);
}

static int emit_rolw_imm_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 buf[8];
	u8 dst_reg, imm;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	if (imm != 8)
		return -EINVAL;
	if (!arch_reg)
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);

	kop_emit_u8(buf, &len, 0x66);
	kop_emit_rex(buf, &len, false, false, false, kop_x86_ext(dst_reg));
	kop_emit_u8(buf, &len, 0xc1);
	kop_emit_u8(buf, &len, 0xc0 | kop_x86_code(dst_reg));
	kop_emit_u8(buf, &len, imm);

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_bswap_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, bool is64)
{
	u8 buf[4];
	u8 dst_reg;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_reg_payload(payload, &dst_reg, &arch_reg);
	if (err)
		return err;
	if (!arch_reg)
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);

	kop_emit_rex(buf, &len, is64, false, false, kop_x86_ext(dst_reg));
	kop_emit_u8(buf, &len, 0x0f);
	kop_emit_u8(buf, &len, 0xc8 + kop_x86_code(dst_reg));

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_bswapl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_bswap_x86(image, off, emit, payload, prog, false);
}

static int emit_bswapq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_bswap_x86(image, off, emit, payload, prog, true);
}

const struct bpf_kop bpf_x86_rolw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_rolw_imm,
	.emit_x86 = emit_rolw_imm_x86,
};

const struct bpf_kop bpf_x86_bswapl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_bswapl,
	.emit_x86 = emit_bswapl_x86,
};

const struct bpf_kop bpf_x86_bswapq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_bswapq,
	.emit_x86 = emit_bswapq_x86,
};

static const struct bpf_kop * const bpf_x86_byteorder_kop_descs[] = {
	&bpf_x86_bswapl_desc,
	&bpf_x86_bswapq_desc,
	&bpf_x86_rolw_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_byteorder,
		       "BpfReJIT x86 koperation: ROL/BSWAP",
		       bpf_x86_byteorder_kfunc_ids,
		       bpf_x86_byteorder_kop_descs);
