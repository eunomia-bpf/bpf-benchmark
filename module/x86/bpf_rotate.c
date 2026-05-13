// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE — rotate lowering for x86-64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_rotate64(void) {}
__bpf_kfunc void bpf_rotate32(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_rotate_kfunc_ids)
BTF_ID_FLAGS(func, bpf_rotate32)
BTF_ID_FLAGS(func, bpf_rotate64)
BTF_KFUNCS_END(bpf_rotate_kfunc_ids)

static __always_inline int decode_rotate_payload(u64 payload,
						 u8 shift_mask,
						 u8 *dst_reg,
						 u8 *src_reg,
						 u8 *tmp_reg,
						 u8 *shift)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*shift = kinsn_payload_u8(payload, 8) & shift_mask;
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 || *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_rotate64_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	return decode_rotate_payload(payload, 63, dst_reg, src_reg, tmp_reg, shift);
}

static __always_inline int decode_rotate32_payload(u64 payload,
						   u8 *dst_reg,
						   u8 *src_reg,
						   u8 *tmp_reg,
						   u8 *shift)
{
	return decode_rotate_payload(payload, 31, dst_reg, src_reg, tmp_reg, shift);
}

static int instantiate_rotate64(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	if (!shift) {
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
		return cnt;
	}

	insn_buf[cnt++] = BPF_MOV64_REG(tmp_reg, src_reg);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, tmp_reg, 64 - shift);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	return cnt;
}

static int instantiate_rotate32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;

	if (!shift) {
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, src_reg);
		return cnt;
	}

	insn_buf[cnt++] = BPF_MOV32_REG(tmp_reg, src_reg);
	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[cnt++] = BPF_ALU32_IMM(BPF_RSH, tmp_reg, 32 - shift);
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_OR, dst_reg, tmp_reg);
	return cnt;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_rex_rr(u8 *buf, u32 *len, bool is64, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (kinsn_x86_reg_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_reg_ext(rm))
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_mov_rr(u8 *buf, u32 *len, bool is64, u8 dst_reg, u8 src_reg)
{
	emit_rex_rr(buf, len, is64, src_reg, dst_reg);
	emit_u8(buf, len, 0x89);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(src_reg) << 3) |
		kinsn_x86_reg_code(dst_reg));
}

static void emit_rol_imm(u8 *buf, u32 *len, bool is64, u8 dst_reg, u8 imm8)
{
	emit_rex_rr(buf, len, is64, 0, dst_reg);
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, imm8);
}

static void emit_rorx32_imm(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg, u8 imm8)
{
	u8 vex2 = 0x43;

	if (!kinsn_x86_reg_ext(dst_reg))
		vex2 |= 0x80;
	if (!kinsn_x86_reg_ext(src_reg))
		vex2 |= 0x20;

	emit_u8(buf, len, 0xC4);
	emit_u8(buf, len, vex2);
	emit_u8(buf, len, 0x7B);
	emit_u8(buf, len, 0xF0);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));
	emit_u8(buf, len, imm8);
}

static int emit_rotate_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog,
			   bool is64)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	if (is64)
		err = decode_rotate64_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	else
		err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(src_reg))
		return -EINVAL;

	if (dst_reg != src_reg || (!is64 && !shift))
		emit_mov_rr(buf, &len, is64, dst_reg, src_reg);
	if (shift)
		emit_rol_imm(buf, &len, is64, dst_reg, shift);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_rotate64_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	return emit_rotate_x86(image, off, emit, payload, prog, true);
}

static int emit_rotate32_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[16];
	u8 dst_reg, src_reg, tmp_reg, shift;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_rotate32_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(src_reg))
		return -EINVAL;

	emit_rorx32_imm(buf, &len, dst_reg, src_reg, (-shift) & 31);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_rotate64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate64,
	.emit_x86 = emit_rotate64_x86,
};

const struct bpf_kinsn bpf_rotate32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate32,
	.emit_x86 = emit_rotate32_x86,
};

static const struct bpf_kinsn * const bpf_rotate_kinsn_descs[] = {
	&bpf_rotate32_desc,
	&bpf_rotate64_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_rotate, "BpfReJIT kinsn: ROTATE",
		       bpf_rotate_kfunc_ids, bpf_rotate_kinsn_descs);
