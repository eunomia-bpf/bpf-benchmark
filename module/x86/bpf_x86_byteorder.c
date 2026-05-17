// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: byte-order instructions.
 */

#include "kinsn_x86_emit.h"

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

static __always_inline int decode_reg_payload(u64 payload, u8 *dst_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_imm_payload(u64 payload, u8 *dst_reg,
						  u8 *imm, bool *arch_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*imm = kinsn_payload_u8(payload, 8);
	*arch_reg = !!(payload & (1ULL << 16));

	if (payload >> 17)
		return -EINVAL;
	if (payload & (0xfULL << 4))
		return -EINVAL;
	if (!*arch_reg && *dst_reg >= BPF_REG_10)
		return -EINVAL;
	if (*arch_reg && *dst_reg != BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_rolw_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, imm;
	bool arch_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	(void)arch_reg;
	if (imm != 8)
		return -EINVAL;

	if (arch_reg) {
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		kinsn_x86_read32_arch(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				      dst_reg);
		insn_buf[cnt++] = BPF_BSWAP(KINSN_X86_SCRATCH0, 16);
		kinsn_x86_write32_arch(insn_buf, &cnt, dst_reg,
				       KINSN_X86_SCRATCH0, scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
		return cnt;
	}
	insn_buf[0] = BPF_BSWAP(dst_reg, 16);
	return 1;
}

static int instantiate_bswap(u64 payload, struct bpf_insn *insn_buf, u8 bits)
{
	u8 dst_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
		kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0,
				  dst_reg);
		insn_buf[cnt++] = BPF_BSWAP(KINSN_X86_SCRATCH0, bits);
		kinsn_x86_write64(insn_buf, &cnt, dst_reg,
				  KINSN_X86_SCRATCH0, scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
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
			     const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, imm;
	bool arch_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm, &arch_reg);
	if (err)
		return err;
	if (imm != 8)
		return -EINVAL;

	kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex(buf, &len, false, false, false, kinsn_x86_ext(dst_reg));
	kinsn_emit_u8(buf, &len, 0xc1);
	kinsn_emit_u8(buf, &len, 0xc0 | kinsn_x86_code(dst_reg));
	kinsn_emit_u8(buf, &len, imm);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_bswap_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, bool is64)
{
	u8 buf[4];
	u8 dst_reg;
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	kinsn_emit_rex(buf, &len, is64, false, false, kinsn_x86_ext(dst_reg));
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0xc8 + kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_bswapl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	return emit_bswap_x86(image, off, emit, payload, prog, false);
}

static int emit_bswapq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog)
{
	return emit_bswap_x86(image, off, emit, payload, prog, true);
}

const struct bpf_kinsn bpf_x86_rolw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_rolw_imm,
	.emit_x86 = emit_rolw_imm_x86,
};

const struct bpf_kinsn bpf_x86_bswapl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_bswapl,
	.emit_x86 = emit_bswapl_x86,
};

const struct bpf_kinsn bpf_x86_bswapq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_bswapq,
	.emit_x86 = emit_bswapq_x86,
};

static const struct bpf_kinsn * const bpf_x86_byteorder_kinsn_descs[] = {
	&bpf_x86_bswapl_desc,
	&bpf_x86_bswapq_desc,
	&bpf_x86_rolw_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_byteorder,
		       "BpfReJIT x86 kinsns: ROL/BSWAP",
		       bpf_x86_byteorder_kfunc_ids,
		       bpf_x86_byteorder_kinsn_descs);
