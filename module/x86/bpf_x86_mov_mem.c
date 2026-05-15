// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: direct memory loads.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movzbl_mem(void) {}
__bpf_kfunc void bpf_x86_movzwl_mem(void) {}
__bpf_kfunc void bpf_x86_movl_mem(void) {}
__bpf_kfunc void bpf_x86_movq_mem(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_mem_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movl_mem)
BTF_ID_FLAGS(func, bpf_x86_movq_mem)
BTF_ID_FLAGS(func, bpf_x86_movzbl_mem)
BTF_ID_FLAGS(func, bpf_x86_movzwl_mem)
BTF_KFUNCS_END(bpf_x86_mov_mem_kfunc_ids)

static __always_inline int decode_mov_mem_payload(u64 payload, u8 *dst_reg,
						  u8 *base_reg, s16 *offset)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*offset = kinsn_payload_s16(payload, 8);

	if (payload >> 24)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_mov_mem(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg;
	s16 offset;
	int err;

	err = decode_mov_mem_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	insn_buf[0] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
	return 1;
}

static int instantiate_movzwl_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_mem(payload, insn_buf, BPF_H);
}

static int instantiate_movzbl_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_mem(payload, insn_buf, BPF_B);
}

static int instantiate_movl_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_mem(payload, insn_buf, BPF_W);
}

static int instantiate_movq_mem(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_mem(payload, insn_buf, BPF_DW);
}

static int emit_mov_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg;
	s16 offset;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_mov_mem_payload(payload, &dst_reg, &base_reg, &offset);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg))
		return -EINVAL;

	switch (size) {
	case BPF_B:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb6);
		break;
	case BPF_H:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb7);
		break;
	case BPF_W:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	case BPF_DW:
		kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(dst_reg),
			       false, kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	default:
		return -EINVAL;
	}

	kinsn_emit_modrm_mem(buf, &len, dst_reg, base_reg, offset);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_movzwl_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_movzbl_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_B);
}

static int emit_movl_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_W);
}

static int emit_movq_mem_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_mov_mem_x86(image, off, emit, payload, prog, BPF_DW);
}

const struct bpf_kinsn bpf_x86_movzwl_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzwl_mem,
	.emit_x86 = emit_movzwl_mem_x86,
};

const struct bpf_kinsn bpf_x86_movzbl_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzbl_mem,
	.emit_x86 = emit_movzbl_mem_x86,
};

const struct bpf_kinsn bpf_x86_movl_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movl_mem,
	.emit_x86 = emit_movl_mem_x86,
};

const struct bpf_kinsn bpf_x86_movq_mem_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movq_mem,
	.emit_x86 = emit_movq_mem_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_mem_kinsn_descs[] = {
	&bpf_x86_movl_mem_desc,
	&bpf_x86_movq_mem_desc,
	&bpf_x86_movzbl_mem_desc,
	&bpf_x86_movzwl_mem_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov_mem,
		       "BpfReJIT x86 kinsns: MOV/MOVZX direct loads",
		       bpf_x86_mov_mem_kfunc_ids,
		       bpf_x86_mov_mem_kinsn_descs);
