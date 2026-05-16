// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOV register-to-register.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movl_rr(void) {}
__bpf_kfunc void bpf_x86_movq_rr(void) {}
__bpf_kfunc void bpf_x86_movswl_rr(void) {}
__bpf_kfunc void bpf_x86_movzbl_rr(void) {}
__bpf_kfunc void bpf_x86_movzwl_rr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_reg_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movl_rr)
BTF_ID_FLAGS(func, bpf_x86_movq_rr)
BTF_ID_FLAGS(func, bpf_x86_movswl_rr)
BTF_ID_FLAGS(func, bpf_x86_movzbl_rr)
BTF_ID_FLAGS(func, bpf_x86_movzwl_rr)
BTF_KFUNCS_END(bpf_x86_mov_reg_kfunc_ids)

static __always_inline int decode_mov_rr_payload(u64 payload, u8 *dst_reg,
						 u8 *src_reg)
{
	payload = kinsn_payload_decode(payload);
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int instantiate_movq_value(u8 dst_reg, u8 src_reg,
						  struct bpf_insn *insn_buf)
{
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;

	if (!kinsn_x86_reg_is_shadowed(src_reg) &&
	    !kinsn_x86_reg_is_shadowed(dst_reg)) {
		insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
		return 1;
	}
	if (!kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_read64(insn_buf, &cnt, dst_reg, src_reg);
		return cnt ? cnt : 1;
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read64(insn_buf, &cnt, KINSN_X86_SCRATCH0, src_reg);
	kinsn_x86_write64(insn_buf, &cnt, dst_reg, KINSN_X86_SCRATCH0,
			  scratch_mask);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movzx_rr(u64 payload, struct bpf_insn *insn_buf, u32 mask)
{
	u8 dst_reg, src_reg, value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
		insn_buf[1] = BPF_ALU32_IMM(BPF_AND, dst_reg, mask);
		return 2;
	}

	value_reg = kinsn_x86_reg_is_shadowed(dst_reg) ? KINSN_X86_SCRATCH0 : dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read32(insn_buf, &cnt, value_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_AND, value_reg, mask);
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_write32(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_movq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	return instantiate_movq_value(dst_reg, src_reg, insn_buf);
}

static int instantiate_movl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
		return 1;
	}

	value_reg = kinsn_x86_reg_is_shadowed(dst_reg) ? KINSN_X86_SCRATCH0 : dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read32(insn_buf, &cnt, value_reg, src_reg);
	insn_buf[cnt++] = BPF_MOV32_REG(value_reg, value_reg);
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_write32(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int instantiate_movzbl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movzx_rr(payload, insn_buf, 0xff);
}

static int instantiate_movzwl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movzx_rr(payload, insn_buf, 0xffff);
}

static int instantiate_movswl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, value_reg;
	u32 scratch_mask = KINSN_X86_SCRATCH_MASK(KINSN_X86_SCRATCH0);
	int cnt = 0;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	if (!kinsn_x86_reg_is_shadowed(dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(src_reg)) {
		insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
		insn_buf[1] = BPF_ALU32_IMM(BPF_LSH, dst_reg, 16);
		insn_buf[2] = BPF_ALU32_IMM(BPF_ARSH, dst_reg, 16);
		return 3;
	}

	value_reg = kinsn_x86_reg_is_shadowed(dst_reg) ? KINSN_X86_SCRATCH0 : dst_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kinsn_x86_read32(insn_buf, &cnt, value_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, value_reg, 16);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_ARSH, value_reg, 16);
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		kinsn_x86_write32(insn_buf, &cnt, dst_reg, value_reg,
				  scratch_mask);
		kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	}
	return cnt;
}

static int emit_movq_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, true, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movl_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex_rr(buf, &len, false, src_reg, dst_reg);
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(src_reg) << 3) |
		      kinsn_x86_code(dst_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movzx_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog, u8 opcode,
			     bool src_is_byte)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	if (src_is_byte)
		kinsn_emit_rex8(buf, &len, dst_reg, src_reg, true, false, true);
	else
		kinsn_emit_rex_rr(buf, &len, false, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, opcode);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(dst_reg) << 3) |
		      kinsn_x86_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movzbl_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xb6, true);
}

static int emit_movzwl_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xb7, false);
}

static int emit_movswl_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog)
{
	return emit_movzx_rr_x86(image, off, emit, payload, prog, 0xbf, false);
}

const struct bpf_kinsn bpf_x86_movq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movq_rr,
	.emit_x86 = emit_movq_rr_x86,
};

const struct bpf_kinsn bpf_x86_movl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movl_rr,
	.emit_x86 = emit_movl_rr_x86,
};

const struct bpf_kinsn bpf_x86_movzbl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movzbl_rr,
	.emit_x86 = emit_movzbl_rr_x86,
};

const struct bpf_kinsn bpf_x86_movzwl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movzwl_rr,
	.emit_x86 = emit_movzwl_rr_x86,
};

const struct bpf_kinsn bpf_x86_movswl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movswl_rr,
	.emit_x86 = emit_movswl_rr_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_reg_kinsn_descs[] = {
	&bpf_x86_movl_rr_desc,
	&bpf_x86_movq_rr_desc,
	&bpf_x86_movswl_rr_desc,
	&bpf_x86_movzbl_rr_desc,
	&bpf_x86_movzwl_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov_reg, "BpfReJIT x86 kinsns: MOV",
		       bpf_x86_mov_reg_kfunc_ids, bpf_x86_mov_reg_kinsn_descs);
