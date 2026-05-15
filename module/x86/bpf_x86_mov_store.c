// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: direct memory stores.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movb_mem_reg(void) {}
__bpf_kfunc void bpf_x86_movw_mem_reg(void) {}
__bpf_kfunc void bpf_x86_movl_mem_reg(void) {}
__bpf_kfunc void bpf_x86_movq_mem_reg(void) {}
__bpf_kfunc void bpf_x86_movb_imm_mem(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_store_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movb_imm_mem)
BTF_ID_FLAGS(func, bpf_x86_movb_mem_reg)
BTF_ID_FLAGS(func, bpf_x86_movl_mem_reg)
BTF_ID_FLAGS(func, bpf_x86_movq_mem_reg)
BTF_ID_FLAGS(func, bpf_x86_movw_mem_reg)
BTF_KFUNCS_END(bpf_x86_mov_store_kfunc_ids)

static __always_inline int decode_store_reg_payload(u64 payload, u8 *src_reg,
						    u8 *base_reg, s16 *offset)
{
	*src_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);

	if (payload >> 24)
		return -EINVAL;
	if (*src_reg >= BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_store_imm_payload(u64 payload, u8 *base_reg,
						    s16 *offset, u8 *imm)
{
	*base_reg = kinsn_payload_reg(payload, 0);
	*offset = kinsn_payload_s16(payload, 4);
	*imm = kinsn_payload_u8(payload, 20);

	if (payload >> 28)
		return -EINVAL;
	if (*base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_store_reg(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 src_reg, base_reg;
	s16 offset;
	int err;

	err = decode_store_reg_payload(payload, &src_reg, &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_STX_MEM(size, base_reg, src_reg, offset);
	return 1;
}

static int instantiate_movb_mem_reg(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_B);
}

static int instantiate_movw_mem_reg(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_H);
}

static int instantiate_movl_mem_reg(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_W);
}

static int instantiate_movq_mem_reg(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_store_reg(payload, insn_buf, BPF_DW);
}

static int instantiate_movb_imm_mem(u64 payload, struct bpf_insn *insn_buf)
{
	u8 base_reg, imm;
	s16 offset;
	int err;

	err = decode_store_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_ST_MEM(BPF_B, base_reg, offset, imm);
	return 1;
}

static void emit_store_reg_prefix(u8 *buf, u32 *len, u8 size, u8 src_reg,
				  u8 base_reg)
{
	u32 before_rex;

	if (size == BPF_H)
		kinsn_emit_u8(buf, len, 0x66);
	before_rex = *len;
	kinsn_emit_rex(buf, len, size == BPF_DW, kinsn_x86_ext(src_reg),
		       false, kinsn_x86_ext(base_reg));
	if (size == BPF_B && *len == before_rex && kinsn_x86_needs_rex8(src_reg))
		kinsn_emit_u8(buf, len, 0x40);
	kinsn_emit_u8(buf, len, size == BPF_B ? 0x88 : 0x89);
}

static int emit_store_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 src_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_store_reg_payload(payload, &src_reg, &base_reg, &offset);
	if (err)
		return err;

	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(src_reg) || !kinsn_x86_valid(base_reg))
		return -EINVAL;

	emit_store_reg_prefix(buf, &len, size, src_reg, base_reg);
	kinsn_emit_modrm_mem(buf, &len, src_reg, base_reg, offset);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_movb_mem_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
				 const struct bpf_prog *prog)
{
	return emit_store_reg_x86(image, off, emit, payload, prog, BPF_B);
}

static int emit_movw_mem_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
				 const struct bpf_prog *prog)
{
	return emit_store_reg_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_movl_mem_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
				 const struct bpf_prog *prog)
{
	return emit_store_reg_x86(image, off, emit, payload, prog, BPF_W);
}

static int emit_movq_mem_reg_x86(u8 *image, u32 *off, bool emit, u64 payload,
				 const struct bpf_prog *prog)
{
	return emit_store_reg_x86(image, off, emit, payload, prog, BPF_DW);
}

static int emit_movb_imm_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
				 const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 base_reg, imm;
	s16 offset;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_store_imm_payload(payload, &base_reg, &offset, &imm);
	if (err)
		return err;

	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(base_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, false, false, false, kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0xc6);
	kinsn_emit_modrm_mem(buf, &len, 0, base_reg, offset);
	kinsn_emit_u8(buf, &len, imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_x86_movb_mem_reg_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movb_mem_reg,
	.emit_x86 = emit_movb_mem_reg_x86,
};

const struct bpf_kinsn bpf_x86_movw_mem_reg_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movw_mem_reg,
	.emit_x86 = emit_movw_mem_reg_x86,
};

const struct bpf_kinsn bpf_x86_movl_mem_reg_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movl_mem_reg,
	.emit_x86 = emit_movl_mem_reg_x86,
};

const struct bpf_kinsn bpf_x86_movq_mem_reg_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movq_mem_reg,
	.emit_x86 = emit_movq_mem_reg_x86,
};

const struct bpf_kinsn bpf_x86_movb_imm_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movb_imm_mem,
	.emit_x86 = emit_movb_imm_mem_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_store_kinsn_descs[] = {
	&bpf_x86_movb_imm_mem_desc,
	&bpf_x86_movb_mem_reg_desc,
	&bpf_x86_movl_mem_reg_desc,
	&bpf_x86_movq_mem_reg_desc,
	&bpf_x86_movw_mem_reg_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov_store,
		       "BpfReJIT x86 kinsns: MOV stores",
		       bpf_x86_mov_store_kfunc_ids,
		       bpf_x86_mov_store_kinsn_descs);
