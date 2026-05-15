// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: SIB memory loads.
 *
 * Each kinsn maps to one final x86 memory-load instruction using
 * disp(base,index,scale) addressing.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movzbl_sib(void) {}
__bpf_kfunc void bpf_x86_movzwl_sib(void) {}
__bpf_kfunc void bpf_x86_movl_sib(void) {}
__bpf_kfunc void bpf_x86_movq_sib(void) {}
__bpf_kfunc void bpf_x86_movsxd_sib(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_sib_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movl_sib)
BTF_ID_FLAGS(func, bpf_x86_movq_sib)
BTF_ID_FLAGS(func, bpf_x86_movsxd_sib)
BTF_ID_FLAGS(func, bpf_x86_movzbl_sib)
BTF_ID_FLAGS(func, bpf_x86_movzwl_sib)
BTF_KFUNCS_END(bpf_x86_mov_sib_kfunc_ids)

static __always_inline int decode_mov_sib_payload(u64 payload, u8 *dst_reg,
						  u8 *base_reg, u8 *index_reg,
						  u8 *scale_log2, s16 *offset)
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
	if (*dst_reg == *base_reg || *dst_reg == *index_reg)
		return -EINVAL;

	return 0;
}

static __always_inline int
decode_mov_sib_tmp_payload(u64 payload, u8 *dst_reg, u8 *base_reg,
			   u8 *index_reg, u8 *scale_log2, s16 *offset,
			   u8 *tmp_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*index_reg = kinsn_payload_reg(payload, 8);
	*scale_log2 = (payload >> 12) & 0x3;
	*offset = kinsn_payload_s16(payload, 16);
	*tmp_reg = kinsn_payload_reg(payload, 32);

	if (payload >> 36)
		return -EINVAL;
	if (payload & (0x3ULL << 14))
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10 ||
	    *index_reg >= BPF_REG_10 || *tmp_reg >= BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *base_reg ||
	    *tmp_reg == *index_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*base_reg) ||
	    !kinsn_x86_reg_valid(*index_reg) ||
	    !kinsn_x86_reg_valid(*tmp_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_mov_sib(u64 payload, struct bpf_insn *insn_buf, u8 size)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_mov_sib_payload(payload, &dst_reg, &base_reg, &index_reg,
				     &scale_log2, &offset);
	if (err)
		return err;

	insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(size, dst_reg, dst_reg, offset);
	return cnt;
}

static int instantiate_movzwl_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_sib(payload, insn_buf, BPF_H);
}

static int instantiate_movzbl_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_sib(payload, insn_buf, BPF_B);
}

static int instantiate_movl_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_sib(payload, insn_buf, BPF_W);
}

static int instantiate_movq_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_mov_sib(payload, insn_buf, BPF_DW);
}

static int instantiate_movsxd_sib(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2, tmp_reg;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_mov_sib_tmp_payload(payload, &dst_reg, &base_reg,
					 &index_reg, &scale_log2, &offset,
					 &tmp_reg);
	if (err)
		return err;

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, tmp_reg, index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_W, dst_reg, tmp_reg, offset);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, 32);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ARSH, dst_reg, 32);
	return cnt;
}

static int emit_mov_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_mov_sib_payload(payload, &dst_reg, &base_reg, &index_reg,
				     &scale_log2, &offset);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    !kinsn_x86_valid(index_reg))
		return -EINVAL;

	switch (size) {
	case BPF_B:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb6);
		break;
	case BPF_H:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x0f);
		kinsn_emit_u8(buf, &len, 0xb7);
		break;
	case BPF_W:
		kinsn_emit_rex(buf, &len, false, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	case BPF_DW:
		kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(dst_reg),
			       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
		kinsn_emit_u8(buf, &len, 0x8b);
		break;
	default:
		return -EINVAL;
	}

	kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_movzwl_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_movzbl_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_B);
}

static int emit_movl_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_W);
}

static int emit_movq_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog)
{
	return emit_mov_sib_x86(image, off, emit, payload, prog, BPF_DW);
}

static int emit_movsxd_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2, tmp_reg;
	s16 offset;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_mov_sib_tmp_payload(payload, &dst_reg, &base_reg,
					 &index_reg, &scale_log2, &offset,
					 &tmp_reg);
	if (err)
		return err;
	(void)tmp_reg;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    !kinsn_x86_valid(index_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(dst_reg),
		       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0x63);
	kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_x86_movzbl_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzbl_sib,
	.emit_x86 = emit_movzbl_sib_x86,
};

const struct bpf_kinsn bpf_x86_movzwl_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movzwl_sib,
	.emit_x86 = emit_movzwl_sib_x86,
};

const struct bpf_kinsn bpf_x86_movl_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movl_sib,
	.emit_x86 = emit_movl_sib_x86,
};

const struct bpf_kinsn bpf_x86_movq_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movq_sib,
	.emit_x86 = emit_movq_sib_x86,
};

const struct bpf_kinsn bpf_x86_movsxd_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 12,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movsxd_sib,
	.emit_x86 = emit_movsxd_sib_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_sib_kinsn_descs[] = {
	&bpf_x86_movl_sib_desc,
	&bpf_x86_movq_sib_desc,
	&bpf_x86_movsxd_sib_desc,
	&bpf_x86_movzbl_sib_desc,
	&bpf_x86_movzwl_sib_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov_sib,
		       "BpfReJIT x86 kinsns: MOV/MOVZX SIB loads",
		       bpf_x86_mov_sib_kfunc_ids,
		       bpf_x86_mov_sib_kinsn_descs);
