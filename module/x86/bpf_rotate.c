// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE — 64-bit rotate left via ROL instruction
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_rotate64(void) {}
__bpf_kfunc_end_defs();

static __always_inline int decode_rotate_payload(u64 payload,
						 u8 *dst_reg,
						 u8 *src_reg,
						 u8 *tmp_reg,
						 u8 *shift)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*shift = kinsn_payload_u8(payload, 8) & 63;
	*tmp_reg = kinsn_payload_reg(payload, 16);

	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 || *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;

	return 0;
}

static int instantiate_rotate(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg, shift;
	int cnt = 0;
	int err;

	err = decode_rotate_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
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

static void emit_mov_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg)
{
	emit_rex_rr(buf, len, true, src_reg, dst_reg);
	emit_u8(buf, len, 0x89);
	emit_u8(buf, len, 0xC0 |
		(kinsn_x86_reg_code(src_reg) << 3) |
		kinsn_x86_reg_code(dst_reg));
}

static void emit_rol_imm(u8 *buf, u32 *len, u8 dst_reg, u8 imm8)
{
	emit_rex_rr(buf, len, true, 0, dst_reg);
	emit_u8(buf, len, 0xC1);
	emit_u8(buf, len, 0xC0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, len, imm8);
}

static int emit_rotate_x86(u8 *image, u32 *off, bool emit,
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

	err = decode_rotate_payload(payload, &dst_reg, &src_reg, &tmp_reg, &shift);
	if (err)
		return err;
	if (!kinsn_x86_reg_valid(dst_reg) || !kinsn_x86_reg_valid(src_reg))
		return -EINVAL;

	if (dst_reg != src_reg)
		emit_mov_rr(buf, &len, dst_reg, src_reg);
	if (shift)
		emit_rol_imm(buf, &len, dst_reg, shift);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_rotate64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_rotate,
	.emit_x86 = emit_rotate_x86,
};

DEFINE_KINSN_V2_MODULE(bpf_rotate, "BpfReJIT kinsn: ROTATE (ROL)");
