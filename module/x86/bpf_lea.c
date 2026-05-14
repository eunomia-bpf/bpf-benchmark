// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: LEA — x86 flagless base/index/displacement add.
 *
 * Semantics: dst = (has_base ? base : 0) +
 *		   (has_index ? index << scale_log2 : 0) + disp.
 */

#include "kinsn_common.h"

#define KINSN_X86_REG_R9 11

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_lea64(void) {}
__bpf_kfunc void bpf_lea32(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_lea_kfunc_ids)
BTF_ID_FLAGS(func, bpf_lea32)
BTF_ID_FLAGS(func, bpf_lea64)
BTF_KFUNCS_END(bpf_lea_kfunc_ids)

static __always_inline s32 kinsn_payload_s32(u64 payload, u8 shift)
{
	return (s32)((u32)(payload >> shift));
}

static __always_inline int decode_lea_payload(u64 payload,
					      u8 *dst_reg,
					      u8 *base_reg,
					      u8 *index_reg,
					      u8 *scale_log2,
					      bool *has_base,
					      bool *has_index,
					      s32 *disp)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*index_reg = kinsn_payload_reg(payload, 8);
	*scale_log2 = kinsn_payload_reg(payload, 12) & 0x3;
	*has_index = (payload >> 14) & 1;
	*has_base = (payload >> 15) & 1;
	*disp = kinsn_payload_s32(payload, 16);

	if (payload >> 48)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10)
		return -EINVAL;
	if (*has_base) {
		if (*base_reg > BPF_REG_10)
			return -EINVAL;
	} else {
		if (*base_reg)
			return -EINVAL;
	}
	if (*has_index) {
		if (*index_reg > BPF_REG_10)
			return -EINVAL;
	} else {
		if (*index_reg || *scale_log2)
			return -EINVAL;
	}

	return 0;
}

static int instantiate_lea64(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool has_base, has_index;
	s32 disp;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_lea_payload(payload, &dst_reg, &base_reg, &index_reg,
				 &scale_log2, &has_base, &has_index, &disp);
	if (err)
		return err;

	if (has_base && has_index && dst_reg == index_reg && dst_reg != base_reg) {
		if (scale_log2)
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, scale_log2);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, base_reg);
	} else if (has_base) {
		if (dst_reg != base_reg)
			insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, base_reg);
		if (has_index) {
			if (dst_reg == index_reg && scale_log2) {
				insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MUL, dst_reg,
								(1 << scale_log2) + 1);
			} else {
				add_count = 1 << scale_log2;
				while (add_count--)
					insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg,
									index_reg);
			}
		}
	} else if (has_index) {
		if (dst_reg != index_reg)
			insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, index_reg);
		if (scale_log2)
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, scale_log2);
	} else if (!has_base) {
		insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, disp);
	}

	if (disp && (has_base || has_index))
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, dst_reg, disp);
	if (!cnt)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, dst_reg);

	return cnt;
}

static int instantiate_lea32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool has_base, has_index;
	s32 disp;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_lea_payload(payload, &dst_reg, &base_reg, &index_reg,
				 &scale_log2, &has_base, &has_index, &disp);
	if (err)
		return err;

	if (has_base && has_index && dst_reg == base_reg && dst_reg == index_reg) {
		insn_buf[cnt++] = BPF_ALU32_IMM(BPF_MUL, dst_reg, (1 << scale_log2) + 1);
	} else if (has_base && (!has_index || dst_reg != index_reg)) {
		if (dst_reg != base_reg)
			insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, base_reg);
		if (has_index) {
			add_count = 1 << scale_log2;
			while (add_count--)
				insn_buf[cnt++] = BPF_ALU32_REG(BPF_ADD, dst_reg, index_reg);
		}
	} else if (has_index) {
		if (dst_reg != index_reg)
			insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, index_reg);
		if (scale_log2)
			insn_buf[cnt++] = BPF_ALU32_IMM(BPF_LSH, dst_reg, scale_log2);
		if (has_base)
			insn_buf[cnt++] = BPF_ALU32_REG(BPF_ADD, dst_reg, base_reg);
	} else if (!has_base) {
		insn_buf[cnt++] = BPF_MOV32_IMM(dst_reg, disp);
	}

	if (disp && (has_base || has_index))
		insn_buf[cnt++] = BPF_ALU32_IMM(BPF_ADD, dst_reg, disp);
	if (!cnt)
		insn_buf[cnt++] = BPF_MOV32_REG(dst_reg, dst_reg);

	return cnt;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_s32(u8 *buf, u32 *len, s32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
}

static __always_inline bool lea_prog_uses_priv_stack(const struct bpf_prog *prog)
{
	return prog && prog->aux && prog->aux->priv_stack_ptr;
}

static __always_inline u8 lea_x86_reg_for_prog(const struct bpf_prog *prog,
					       u8 bpf_reg)
{
	if (bpf_reg == BPF_REG_10 && lea_prog_uses_priv_stack(prog))
		return KINSN_X86_REG_R9;
	return bpf_reg;
}

static __always_inline u8 lea_x86_reg_code(u8 reg)
{
	if (reg == KINSN_X86_REG_R9)
		return 1;
	return kinsn_x86_reg_code(reg);
}

static __always_inline bool lea_x86_reg_ext(u8 reg)
{
	if (reg == KINSN_X86_REG_R9)
		return true;
	return kinsn_x86_reg_ext(reg);
}

static __always_inline bool lea_x86_reg_valid(u8 reg)
{
	return lea_x86_reg_code(reg) != 0xff;
}

static void emit_rex_lea(u8 *buf, u32 *len, bool is64,
			 u8 dst_reg, u8 base_reg, u8 index_reg,
			 bool has_base, bool has_index)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (lea_x86_reg_ext(dst_reg))
		rex |= 0x04;
	if (has_index && lea_x86_reg_ext(index_reg))
		rex |= 0x02;
	if (has_base && lea_x86_reg_ext(base_reg))
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static void emit_lea(u8 *buf, u32 *len, bool is64,
		     u8 dst_reg, u8 base_reg, u8 index_reg,
		     u8 scale_log2, bool has_base, bool has_index, s32 disp)
{
	u8 base_code = has_base ? lea_x86_reg_code(base_reg) : 5;
	u8 index_code = has_index ? lea_x86_reg_code(index_reg) : 4;
	u8 mod;

	emit_rex_lea(buf, len, is64, dst_reg, base_reg, index_reg,
		     has_base, has_index);
	emit_u8(buf, len, 0x8D);

	if (has_base && !has_index) {
		if (!disp && base_code != 5)
			mod = 0x00;
		else if (disp >= -128 && disp <= 127)
			mod = 0x40;
		else
			mod = 0x80;

		emit_u8(buf, len, mod | (lea_x86_reg_code(dst_reg) << 3) | base_code);
		if (mod == 0x40)
			emit_u8(buf, len, (u8)disp);
		else if (mod == 0x80)
			emit_s32(buf, len, disp);
		return;
	}

	if (!has_base)
		mod = 0x00;
	else if (!disp && base_code != 5)
		mod = 0x00;
	else if (disp >= -128 && disp <= 127)
		mod = 0x40;
	else
		mod = 0x80;

	emit_u8(buf, len, mod | (lea_x86_reg_code(dst_reg) << 3) | 0x04);
	emit_u8(buf, len, (scale_log2 << 6) | (index_code << 3) | base_code);
	if (mod == 0x40)
		emit_u8(buf, len, (u8)disp);
	else if (mod == 0x80 || !has_base)
		emit_s32(buf, len, disp);
}

static int emit_lea_x86(u8 *image, u32 *off, bool emit,
			u64 payload, const struct bpf_prog *prog,
			bool is64)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool has_base, has_index;
	s32 disp;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_lea_payload(payload, &dst_reg, &base_reg, &index_reg,
				 &scale_log2, &has_base, &has_index, &disp);
	if (err)
		return err;

	dst_reg = lea_x86_reg_for_prog(prog, dst_reg);
	if (has_base)
		base_reg = lea_x86_reg_for_prog(prog, base_reg);
	if (has_index)
		index_reg = lea_x86_reg_for_prog(prog, index_reg);

	if (!lea_x86_reg_valid(dst_reg))
		return -EINVAL;
	if (has_base && !lea_x86_reg_valid(base_reg))
		return -EINVAL;
	if (has_index && !lea_x86_reg_valid(index_reg))
		return -EINVAL;

	emit_lea(buf, &len, is64, dst_reg, base_reg, index_reg,
		 scale_log2, has_base, has_index, disp);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_lea64_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	return emit_lea_x86(image, off, emit, payload, prog, true);
}

static int emit_lea32_x86(u8 *image, u32 *off, bool emit,
			  u64 payload, const struct bpf_prog *prog)
{
	return emit_lea_x86(image, off, emit, payload, prog, false);
}

const struct bpf_kinsn bpf_lea64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_lea64,
	.emit_x86 = emit_lea64_x86,
};

const struct bpf_kinsn bpf_lea32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_lea32,
	.emit_x86 = emit_lea32_x86,
};

static const struct bpf_kinsn * const bpf_lea_kinsn_descs[] = {
	&bpf_lea32_desc,
	&bpf_lea64_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_lea, "BpfReJIT kinsn: LEA",
		       bpf_lea_kfunc_ids, bpf_lea_kinsn_descs);
