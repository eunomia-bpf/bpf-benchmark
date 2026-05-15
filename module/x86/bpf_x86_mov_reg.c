// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOV register-to-register.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movq_rr(void) {}
__bpf_kfunc void bpf_x86_movswl_rr(void) {}
__bpf_kfunc void bpf_x86_movzbl_rr(void) {}
__bpf_kfunc void bpf_x86_movzwl_rr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_mov_reg_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movq_rr)
BTF_ID_FLAGS(func, bpf_x86_movswl_rr)
BTF_ID_FLAGS(func, bpf_x86_movzbl_rr)
BTF_ID_FLAGS(func, bpf_x86_movzwl_rr)
BTF_KFUNCS_END(bpf_x86_mov_reg_kfunc_ids)

static __always_inline int decode_mov_rr_payload(u64 payload, u8 *dst_reg,
						 u8 *src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) || !kinsn_x86_reg_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_movzx_rr(u64 payload, struct bpf_insn *insn_buf, u32 mask)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
	insn_buf[1] = BPF_ALU32_IMM(BPF_AND, dst_reg, mask);
	return 2;
}

static int instantiate_movq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
	return 1;
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
	u8 dst_reg, src_reg;
	int err;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV32_REG(dst_reg, src_reg);
	insn_buf[1] = BPF_ALU32_IMM(BPF_LSH, dst_reg, 16);
	insn_buf[2] = BPF_ALU32_IMM(BPF_ARSH, dst_reg, 16);
	return 3;
}

static int emit_movq_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

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

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static void emit_movzbl_rex(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	u8 rex = 0x40;

	if (kinsn_x86_ext(dst_reg))
		rex |= 0x04;
	if (kinsn_x86_ext(src_reg))
		rex |= 0x01;
	if (rex != 0x40 || kinsn_x86_needs_rex8(src_reg))
		kinsn_emit_u8(buf, len, rex);
}

static int emit_movzx_rr_x86(u8 *image, u32 *off, bool emit, u64 payload,
			     const struct bpf_prog *prog, u8 opcode,
			     bool src_is_byte)
{
	u8 dst_reg, src_reg;
	u8 buf[4];
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_mov_rr_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	if (src_is_byte)
		emit_movzbl_rex(buf, &len, dst_reg, src_reg);
	else
		kinsn_emit_rex_rr(buf, &len, false, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, opcode);
	kinsn_emit_u8(buf, &len, 0xC0 |
		      (kinsn_x86_code(dst_reg) << 3) |
		      kinsn_x86_code(src_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
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
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movq_rr,
	.emit_x86 = emit_movq_rr_x86,
};

const struct bpf_kinsn bpf_x86_movzbl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movzbl_rr,
	.emit_x86 = emit_movzbl_rr_x86,
};

const struct bpf_kinsn bpf_x86_movzwl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movzwl_rr,
	.emit_x86 = emit_movzwl_rr_x86,
};

const struct bpf_kinsn bpf_x86_movswl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 3,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_movswl_rr,
	.emit_x86 = emit_movswl_rr_x86,
};

static const struct bpf_kinsn * const bpf_x86_mov_reg_kinsn_descs[] = {
	&bpf_x86_movq_rr_desc,
	&bpf_x86_movswl_rr_desc,
	&bpf_x86_movzbl_rr_desc,
	&bpf_x86_movzwl_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_mov_reg, "BpfReJIT x86 kinsns: MOV",
		       bpf_x86_mov_reg_kfunc_ids, bpf_x86_mov_reg_kinsn_descs);
