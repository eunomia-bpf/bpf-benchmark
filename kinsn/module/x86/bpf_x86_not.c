// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 koperation: NOT.
 */

#include "kop_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_notb(void) {}
__bpf_kfunc void bpf_x86_notl(void) {}
__bpf_kfunc void bpf_x86_notq(void) {}
__bpf_kfunc void bpf_x86_notw(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_not_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_notb)
BTF_ID_FLAGS(func, bpf_x86_notl)
BTF_ID_FLAGS(func, bpf_x86_notq)
BTF_ID_FLAGS(func, bpf_x86_notw)
BTF_KFUNCS_END(bpf_x86_not_kfunc_ids)

#define X86_FORM_IMM		2
#define X86_FORM_ARCH_IMM	13

static __always_inline int decode_not_payload(u64 payload, u8 *dst_reg,
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

static int instantiate_not_narrow(u64 payload, struct bpf_insn *insn_buf,
				  u32 mask)
{
	u8 dst_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_not_payload(payload, &dst_reg, &arch_reg);
	if (err)
		return err;

	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kop_x86_read64_arch(insn_buf, &cnt, KOP_X86_SCRATCH0,
				      dst_reg);
	else
		kop_x86_read64(insn_buf, &cnt, KOP_X86_SCRATCH0,
				 dst_reg);
	insn_buf[cnt++] = BPF_MOV64_REG(KOP_X86_SCRATCH1,
					KOP_X86_SCRATCH0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KOP_X86_SCRATCH1,
					~mask);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KOP_X86_SCRATCH0,
					mask);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, KOP_X86_SCRATCH0,
					mask);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, KOP_X86_SCRATCH0,
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

static int instantiate_notb_r(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_not_narrow(payload, insn_buf, 0xff);
}

static int instantiate_notw_r(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_not_narrow(payload, insn_buf, 0xffff);
}

static int instantiate_notl_r(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_not_payload(payload, &dst_reg, &arch_reg);
	if (err)
		return err;

	if (!arch_reg && !kop_x86_reg_uses_stack_slot(dst_reg)) {
		insn_buf[0] = BPF_ALU32_IMM(BPF_XOR, dst_reg, -1);
		return 1;
	}
	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kop_x86_read32_arch(insn_buf, &cnt, KOP_X86_SCRATCH0,
				      dst_reg);
	else
		kop_x86_read32(insn_buf, &cnt, KOP_X86_SCRATCH0,
				 dst_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_XOR, KOP_X86_SCRATCH0, -1);
	if (arch_reg)
		kop_x86_write32_arch(insn_buf, &cnt, dst_reg,
				       KOP_X86_SCRATCH0, scratch_mask);
	else
		kop_x86_write32(insn_buf, &cnt, dst_reg,
				  KOP_X86_SCRATCH0, scratch_mask);
	kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_notq_r(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0);
	bool arch_reg;
	int cnt = 0;
	int err;

	err = decode_not_payload(payload, &dst_reg, &arch_reg);
	if (err)
		return err;

	if (!arch_reg && !kop_x86_reg_uses_stack_slot(dst_reg)) {
		insn_buf[0] = BPF_ALU64_IMM(BPF_XOR, dst_reg, -1);
		return 1;
	}
	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (arch_reg)
		kop_x86_read64_arch(insn_buf, &cnt, KOP_X86_SCRATCH0,
				      dst_reg);
	else
		kop_x86_read64(insn_buf, &cnt, KOP_X86_SCRATCH0,
				 dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_XOR, KOP_X86_SCRATCH0, -1);
	if (arch_reg)
		kop_x86_write64_arch(insn_buf, &cnt, dst_reg,
				       KOP_X86_SCRATCH0, scratch_mask);
	else
		kop_x86_write64(insn_buf, &cnt, dst_reg,
				  KOP_X86_SCRATCH0, scratch_mask);
	kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int emit_not_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, bool is64,
			  bool is16, bool is8)
{
	u8 buf[8];
	u8 dst_reg;
	bool arch_reg;
	u32 len = 0;
	int err;

	err = decode_not_payload(payload, &dst_reg, &arch_reg);
	if (err)
		return err;

	if (!arch_reg)
		dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
	if (!kop_x86_valid(dst_reg))
		return -EINVAL;

	if (is16)
		kop_emit_u8(buf, &len, 0x66);
	if (is8)
		kop_emit_rex8_rm(buf, &len, dst_reg);
	else
		kop_emit_rex(buf, &len, is64, false, false,
			       kop_x86_ext(dst_reg));
	kop_emit_u8(buf, &len, is8 ? 0xf6 : 0xf7);
	kop_emit_u8(buf, &len, 0xd0 | kop_x86_code(dst_reg));

	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_notb_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_not_r_x86(image, off, emit, payload, prog, false, false, true);
}

static int emit_notw_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_not_r_x86(image, off, emit, payload, prog, false, true, false);
}

static int emit_notl_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_not_r_x86(image, off, emit, payload, prog, false, false, false);
}

static int emit_notq_r_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_not_r_x86(image, off, emit, payload, prog, true, false, false);
}

const struct bpf_kop bpf_x86_notb_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 11 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_notb_r,
	.emit_x86 = emit_notb_r_x86,
};

const struct bpf_kop bpf_x86_notl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 3,
	.instantiate_insn = instantiate_notl_r,
	.emit_x86 = emit_notl_r_x86,
};

const struct bpf_kop bpf_x86_notq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 3,
	.instantiate_insn = instantiate_notq_r,
	.emit_x86 = emit_notq_r_x86,
};

const struct bpf_kop bpf_x86_notw_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 11 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_notw_r,
	.emit_x86 = emit_notw_r_x86,
};

static const struct bpf_kop * const bpf_x86_not_kop_descs[] = {
	&bpf_x86_notb_desc,
	&bpf_x86_notl_desc,
	&bpf_x86_notq_desc,
	&bpf_x86_notw_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_not, "BpfReJIT x86 koperation: NOT",
		       bpf_x86_not_kfunc_ids, bpf_x86_not_kop_descs);
