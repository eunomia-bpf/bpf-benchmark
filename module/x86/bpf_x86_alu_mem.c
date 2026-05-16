// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: memory-source ALU instructions.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_addl_mem(void) {}
__bpf_kfunc void bpf_x86_xorb_sib(void) {}
__bpf_kfunc void bpf_x86_xorl_mem(void) {}
__bpf_kfunc void bpf_x86_xorw_mem(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_alu_mem_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_addl_mem)
BTF_ID_FLAGS(func, bpf_x86_xorb_sib)
BTF_ID_FLAGS(func, bpf_x86_xorl_mem)
BTF_ID_FLAGS(func, bpf_x86_xorw_mem)
BTF_KFUNCS_END(bpf_x86_alu_mem_kfunc_ids)

static __always_inline int
decode_alu_mem_payload(u64 payload, u8 *dst_reg, u8 *base_reg, s16 *offset,
		       bool need_tmp2)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);

	if (payload >> 24)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;
	(void)need_tmp2;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*base_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int
decode_alu_sib_payload(u64 payload, u8 *dst_reg, u8 *base_reg,
		       u8 *index_reg, u8 *scale_log2, s16 *offset,
		       bool need_value)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*index_reg = kinsn_payload_reg(payload, 8);
	*scale_log2 = (payload >> 12) & 0x3;
	*offset = kinsn_payload_s16(payload, 16);

	if (payload >> 32)
		return -EINVAL;
	if (payload & (0x3ULL << 14))
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10 ||
	    *index_reg >= BPF_REG_10)
		return -EINVAL;
	(void)need_value;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*base_reg) ||
	    !kinsn_x86_reg_valid(*index_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_alu32_mem(u64 payload, struct bpf_insn *insn_buf,
				 u8 op)
{
	u8 dst_reg, base_reg, value_reg;
	u32 scratch_mask;
	s16 offset;
	int cnt = 0;
	int err;

	err = decode_alu_mem_payload(payload, &dst_reg, &base_reg, &offset,
				     false);
	if (err)
		return err;

	value_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, 0);
	scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_W, value_reg, base_reg, offset);
	insn_buf[cnt++] = BPF_ALU32_REG(op, dst_reg, value_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_addl_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_alu32_mem(payload, insn_buf, BPF_ADD);
}

static int instantiate_xorl_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_alu32_mem(payload, insn_buf, BPF_XOR);
}

static int instantiate_xor_narrow_mem(u64 payload, struct bpf_insn *insn_buf,
				      u32 mask, u8 size)
{
	u8 dst_reg, base_reg, value_reg, high_reg;
	u32 scratch_mask;
	s16 offset;
	int cnt = 0;
	int err;

	err = decode_alu_mem_payload(payload, &dst_reg, &base_reg, &offset,
				     true);
	if (err)
		return err;

	value_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, 0);
	high_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, value_reg);
	scratch_mask = KINSN_X86_SCRATCH_MASK(value_reg) |
		       KINSN_X86_SCRATCH_MASK(high_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_LDX_MEM(size, value_reg, base_reg, offset);
	insn_buf[cnt++] = BPF_MOV64_REG(high_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, high_reg, (s32)~mask);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_XOR, dst_reg, value_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, dst_reg, mask);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, high_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_xorw_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_xor_narrow_mem(payload, insn_buf, 0xffff, BPF_H);
}

static int instantiate_xorb_sib(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2, addr_reg, value_reg;
	u32 scratch_mask;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_alu_sib_payload(payload, &dst_reg, &base_reg, &index_reg,
				     &scale_log2, &offset, true);
	if (err)
		return err;

	addr_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, index_reg);
	value_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, addr_reg);
	scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg) |
		       KINSN_X86_SCRATCH_MASK(value_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg, index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_B, value_reg, addr_reg,
				      offset);
	insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, addr_reg, -256);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_XOR, dst_reg, value_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, dst_reg, 0xff);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, addr_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static __always_inline void emit_rex8_mem(u8 *buf, u32 *len, u8 reg_field,
					  u8 base_reg, u8 index_reg,
					  bool has_index)
{
	u8 rex = 0x40;

	if (kinsn_x86_ext(reg_field))
		rex |= 0x04;
	if (has_index && kinsn_x86_ext(index_reg))
		rex |= 0x02;
	if (kinsn_x86_ext(base_reg))
		rex |= 0x01;
	if (rex != 0x40 || kinsn_x86_needs_rex8(reg_field) ||
	    (has_index && kinsn_x86_needs_rex8(index_reg)))
		kinsn_emit_u8(buf, len, rex);
}

static int emit_alu_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, u8 opcode,
			    bool is16, bool is8)
{
	u8 buf[16];
	u8 dst_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_alu_mem_payload(payload, &dst_reg, &base_reg, &offset,
				     is16);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg))
		return -EINVAL;

	if (is16)
		kinsn_emit_u8(buf, &len, 0x66);
	if (is8)
		emit_rex8_mem(buf, &len, dst_reg, base_reg, 0, false);
	else
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, opcode);
	kinsn_emit_modrm_mem(buf, &len, dst_reg, base_reg, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_addl_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_alu_mem_x86(image, off, emit, payload, prog, 0x03,
				false, false);
}

static int emit_xorl_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_alu_mem_x86(image, off, emit, payload, prog, 0x33,
				false, false);
}

static int emit_xorw_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_alu_mem_x86(image, off, emit, payload, prog, 0x33,
				true, false);
}

static int emit_xorb_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;

	err = decode_alu_sib_payload(payload, &dst_reg, &base_reg, &index_reg,
				     &scale_log2, &offset, true);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    !kinsn_x86_valid(index_reg))
		return -EINVAL;

	emit_rex8_mem(buf, &len, dst_reg, base_reg, index_reg, true);
	kinsn_emit_u8(buf, &len, 0x32);
	kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_addl_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_addl_mem,
	.emit_x86 = emit_addl_mem_x86,
};

const struct bpf_kinsn bpf_x86_xorb_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 19 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_xorb_sib,
	.emit_x86 = emit_xorb_sib_x86,
};

const struct bpf_kinsn bpf_x86_xorl_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_xorl_mem,
	.emit_x86 = emit_xorl_mem_x86,
};

const struct bpf_kinsn bpf_x86_xorw_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 9 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_xorw_mem,
	.emit_x86 = emit_xorw_mem_x86,
};

static const struct bpf_kinsn * const bpf_x86_alu_mem_kinsn_descs[] = {
	&bpf_x86_addl_mem_desc,
	&bpf_x86_xorb_sib_desc,
	&bpf_x86_xorl_mem_desc,
	&bpf_x86_xorw_mem_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_alu_mem,
		       "BpfReJIT x86 kinsns: memory-source ALU",
		       bpf_x86_alu_mem_kfunc_ids,
		       bpf_x86_alu_mem_kinsn_descs);
