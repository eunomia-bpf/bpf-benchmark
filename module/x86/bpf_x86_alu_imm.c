// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: immediate ALU instructions.
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_addb_imm(void) {}
__bpf_kfunc void bpf_x86_shrq_imm(void) {}
__bpf_kfunc void bpf_x86_andb_imm(void) {}
__bpf_kfunc void bpf_x86_andl_imm32(void) {}
__bpf_kfunc void bpf_x86_incq(void) {}
__bpf_kfunc void bpf_x86_sbbl_imm0(void) {}
__bpf_kfunc void bpf_x86_xorb_imm(void) {}
__bpf_kfunc void bpf_x86_xorb_rr(void) {}
__bpf_kfunc void bpf_x86_xorl_rr(void) {}
__bpf_kfunc void bpf_x86_orb_rr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_alu_imm_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_addb_imm)
BTF_ID_FLAGS(func, bpf_x86_andb_imm)
BTF_ID_FLAGS(func, bpf_x86_andl_imm32)
BTF_ID_FLAGS(func, bpf_x86_incq)
BTF_ID_FLAGS(func, bpf_x86_sbbl_imm0)
BTF_ID_FLAGS(func, bpf_x86_shrq_imm)
BTF_ID_FLAGS(func, bpf_x86_xorb_imm)
BTF_ID_FLAGS(func, bpf_x86_xorb_rr)
BTF_ID_FLAGS(func, bpf_x86_xorl_rr)
BTF_ID_FLAGS(func, bpf_x86_orb_rr)
BTF_KFUNCS_END(bpf_x86_alu_imm_kfunc_ids)

static __always_inline int decode_reg_imm_payload(u64 payload,
						  u8 *dst_reg,
						  u32 *imm)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*imm = (u32)(payload >> 8);

	if (payload >> 40)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_imm_tmp_payload(u64 payload,
						      u8 *dst_reg,
						      u8 *tmp_reg,
						      u8 *imm)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*tmp_reg = kinsn_payload_reg(payload, 4);
	*imm = kinsn_payload_u8(payload, 8);

	if (payload >> 16)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*dst_reg == *tmp_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*tmp_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_payload(u64 payload, u8 *dst_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_reg_tmp_payload(u64 payload,
						      u8 *dst_reg,
						      u8 *src_reg,
						      u8 *tmp_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*tmp_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 ||
	    *tmp_reg > BPF_REG_10)
		return -EINVAL;
	if (*tmp_reg == *dst_reg || *tmp_reg == *src_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*src_reg) ||
	    !kinsn_x86_reg_valid(*tmp_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_reg_reg_tmp2_payload(u64 payload,
						       u8 *dst_reg,
						       u8 *src_reg,
						       u8 *tmp_dst_reg,
						       u8 *tmp_src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*tmp_dst_reg = kinsn_payload_reg(payload, 8);
	*tmp_src_reg = kinsn_payload_reg(payload, 12);

	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;
	if (!kinsn_x86_reg_is_shadowed(*dst_reg) &&
	    !kinsn_x86_reg_is_shadowed(*src_reg)) {
		if (payload >> 8)
			return -EINVAL;
		return 0;
	}
	if (payload >> 16)
		return -EINVAL;
	if (!kinsn_bpf_gpr_valid(*tmp_dst_reg) ||
	    !kinsn_bpf_gpr_valid(*tmp_src_reg))
		return -EINVAL;
	if (*tmp_dst_reg == *tmp_src_reg && *dst_reg != *src_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_is_shadowed(*dst_reg) &&
	    (*tmp_dst_reg == *dst_reg || *tmp_src_reg == *dst_reg))
		return -EINVAL;
	if (!kinsn_x86_reg_is_shadowed(*src_reg) &&
	    (*tmp_dst_reg == *src_reg || *tmp_src_reg == *src_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_byte_reg_reg_tmp2_payload(u64 payload,
							    u8 *dst_reg,
							    u8 *src_reg,
							    u8 *tmp_dst_reg,
							    u8 *tmp_src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*tmp_dst_reg = kinsn_payload_reg(payload, 8);
	*tmp_src_reg = kinsn_payload_reg(payload, 12);

	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;
	if (!kinsn_x86_reg_is_shadowed(*dst_reg)) {
		if (payload >> 12)
			return -EINVAL;
		*tmp_src_reg = *tmp_dst_reg;
	} else if (payload >> 16) {
		return -EINVAL;
	}
	if (!kinsn_bpf_gpr_valid(*tmp_src_reg))
		return -EINVAL;
	if (kinsn_x86_reg_is_shadowed(*dst_reg) &&
	    !kinsn_bpf_gpr_valid(*tmp_dst_reg))
		return -EINVAL;
	if (!kinsn_x86_reg_is_shadowed(*src_reg) && *tmp_src_reg == *src_reg)
		return -EINVAL;
	if (!kinsn_x86_reg_is_shadowed(*dst_reg) && *tmp_src_reg == *dst_reg)
		return -EINVAL;
	if (kinsn_x86_reg_is_shadowed(*dst_reg) &&
	    *tmp_dst_reg == *tmp_src_reg)
		return -EINVAL;

	return 0;
}

static __always_inline int decode_sbb_payload(u64 payload,
					      u8 *dst_reg,
					      u8 *cond_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*cond_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *cond_reg >= BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) ||
	    !kinsn_x86_reg_valid(*cond_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_shrq_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 imm;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 63)
		return -EINVAL;

	insn_buf[0] = BPF_ALU64_IMM(BPF_RSH, dst_reg, imm);
	return 1;
}

static int instantiate_addb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, tmp_reg, imm;
	int err;

	err = decode_reg_imm_tmp_payload(payload, &dst_reg, &tmp_reg, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV64_REG(tmp_reg, dst_reg);
	insn_buf[1] = BPF_ALU64_IMM(BPF_AND, tmp_reg, 0xff);
	insn_buf[2] = BPF_ALU64_IMM(BPF_ADD, tmp_reg, imm);
	insn_buf[3] = BPF_ALU64_IMM(BPF_AND, tmp_reg, 0xff);
	insn_buf[4] = BPF_ALU64_IMM(BPF_AND, dst_reg, -256);
	insn_buf[5] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	return 6;
}

static int instantiate_andb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, tmp_reg, imm;
	int err;

	err = decode_reg_imm_tmp_payload(payload, &dst_reg, &tmp_reg, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV64_REG(tmp_reg, dst_reg);
	insn_buf[1] = BPF_ALU64_IMM(BPF_AND, tmp_reg, imm);
	insn_buf[2] = BPF_ALU64_IMM(BPF_AND, dst_reg, -256);
	insn_buf[3] = BPF_ALU64_REG(BPF_OR, dst_reg, tmp_reg);
	return 4;
}

static int instantiate_andl_imm32(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 imm;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;

	insn_buf[0] = BPF_ALU32_IMM(BPF_AND, dst_reg, (s32)imm);
	return 1;
}

static int instantiate_incq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	int err;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_ALU64_IMM(BPF_ADD, dst_reg, 1);
	return 1;
}

static int instantiate_sbbl_imm0(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, cond_reg;
	int err;

	err = decode_sbb_payload(payload, &dst_reg, &cond_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_IMM(BPF_JEQ, cond_reg, 0, 1);
	insn_buf[1] = BPF_ALU32_IMM(BPF_SUB, dst_reg, 1);
	return 2;
}

static int instantiate_xorb_imm(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg;
	u32 imm;
	int err;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 0xff)
		return -EINVAL;

	insn_buf[0] = BPF_ALU64_IMM(BPF_XOR, dst_reg, imm);
	return 1;
}

static int instantiate_xorb_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_reg;
	int err;

	err = decode_reg_reg_tmp_payload(payload, &dst_reg, &src_reg, &tmp_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_MOV64_REG(tmp_reg, src_reg);
	insn_buf[1] = BPF_ALU64_IMM(BPF_AND, tmp_reg, 0xff);
	insn_buf[2] = BPF_ALU64_REG(BPF_XOR, dst_reg, tmp_reg);
	return 3;
}

static int instantiate_xorl_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_dst_reg, tmp_src_reg;
	u8 dst_eval_reg, src_eval_reg;
	int cnt = 0;
	int err;

	err = decode_reg_reg_tmp2_payload(payload, &dst_reg, &src_reg,
					  &tmp_dst_reg, &tmp_src_reg);
	if (err)
		return err;

	dst_eval_reg = dst_reg;
	src_eval_reg = src_reg;
	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, tmp_dst_reg, BPF_REG_10,
					      kinsn_x86_shadow_reg_off(dst_reg));
		dst_eval_reg = tmp_dst_reg;
	}
	if (kinsn_x86_reg_is_shadowed(src_reg)) {
		if (src_reg == dst_reg)
			src_eval_reg = dst_eval_reg;
		else {
			insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, tmp_src_reg,
						      BPF_REG_10,
						      kinsn_x86_shadow_reg_off(src_reg));
			src_eval_reg = tmp_src_reg;
		}
	}
	insn_buf[cnt++] = BPF_ALU32_REG(BPF_XOR, dst_eval_reg, src_eval_reg);
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, dst_eval_reg,
					      kinsn_x86_shadow_reg_off(dst_reg));
	return cnt;
}

static int instantiate_orb_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp_dst_reg, tmp_src_reg;
	u8 dst_eval_reg;
	int cnt = 0;
	int err;

	err = decode_byte_reg_reg_tmp2_payload(payload, &dst_reg, &src_reg,
					       &tmp_dst_reg, &tmp_src_reg);
	if (err)
		return err;

	if (kinsn_x86_reg_is_shadowed(src_reg))
		insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, tmp_src_reg, BPF_REG_10,
					      kinsn_x86_shadow_reg_off(src_reg));
	else
		insn_buf[cnt++] = BPF_MOV64_REG(tmp_src_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_AND, tmp_src_reg, 0xff);

	if (kinsn_x86_reg_is_shadowed(dst_reg)) {
		insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, tmp_dst_reg, BPF_REG_10,
					      kinsn_x86_shadow_reg_off(dst_reg));
		dst_eval_reg = tmp_dst_reg;
	} else {
		dst_eval_reg = dst_reg;
	}
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_eval_reg, tmp_src_reg);
	if (kinsn_x86_reg_is_shadowed(dst_reg))
		insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, dst_eval_reg,
					      kinsn_x86_shadow_reg_off(dst_reg));
	return cnt;
}

static void emit_u8(u8 *buf, u32 *len, u8 byte)
{
	buf[(*len)++] = byte;
}

static void emit_u32(u8 *buf, u32 *len, u32 value)
{
	memcpy(buf + *len, &value, sizeof(value));
	*len += sizeof(value);
}

static void emit_rex_rr(u8 *buf, u32 *len, bool is64, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (is64)
		rex |= 0x08;
	if (kinsn_x86_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_ext(rm))
		rex |= 0x01;
	if (rex != 0x40)
		emit_u8(buf, len, rex);
}

static __always_inline bool x86_reg_needs_rex8(u8 bpf_reg)
{
	return kinsn_x86_needs_rex8(bpf_reg);
}

static void emit_rex8_rm(u8 *buf, u32 *len, u8 rm)
{
	u8 rex = 0x40;

	if (kinsn_x86_ext(rm))
		rex |= 0x01;
	if (rex != 0x40 || x86_reg_needs_rex8(rm))
		emit_u8(buf, len, rex);
}

static void emit_rex8_rr(u8 *buf, u32 *len, u8 reg, u8 rm)
{
	u8 rex = 0x40;

	if (kinsn_x86_ext(reg))
		rex |= 0x04;
	if (kinsn_x86_ext(rm))
		rex |= 0x01;
	if (rex != 0x40 || x86_reg_needs_rex8(reg) || x86_reg_needs_rex8(rm))
		emit_u8(buf, len, rex);
}

static int emit_shrq_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg;
	u32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 63)
		return -EINVAL;

	emit_rex_rr(buf, &len, true, 0, dst_reg);
	emit_u8(buf, &len, 0xC1);
	emit_u8(buf, &len, 0xE8 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, (u8)imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_addb_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, tmp_reg, imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_tmp_payload(payload, &dst_reg, &tmp_reg, &imm);
	if (err)
		return err;
	(void)tmp_reg;

	emit_rex8_rm(buf, &len, dst_reg);
	emit_u8(buf, &len, 0x80);
	emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_andb_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, tmp_reg, imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_tmp_payload(payload, &dst_reg, &tmp_reg, &imm);
	if (err)
		return err;
	(void)tmp_reg;

	emit_rex8_rm(buf, &len, dst_reg);
	emit_u8(buf, &len, 0x80);
	emit_u8(buf, &len, 0xe0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_xorb_imm_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg;
	u32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;
	if (imm > 0xff)
		return -EINVAL;

	emit_rex8_rm(buf, &len, dst_reg);
	emit_u8(buf, &len, 0x80);
	emit_u8(buf, &len, 0xf0 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, (u8)imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_xorb_rr_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, src_reg, tmp_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_reg_tmp_payload(payload, &dst_reg, &src_reg, &tmp_reg);
	if (err)
		return err;
	(void)tmp_reg;

	emit_rex8_rr(buf, &len, src_reg, dst_reg);
	emit_u8(buf, &len, 0x30);
	emit_u8(buf, &len, 0xc0 | (kinsn_x86_reg_code(src_reg) << 3) |
			 kinsn_x86_reg_code(dst_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_xorl_rr_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, src_reg, tmp_dst_reg, tmp_src_reg;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_reg_tmp2_payload(payload, &dst_reg, &src_reg,
					  &tmp_dst_reg, &tmp_src_reg);
	if (err)
		return err;
	(void)tmp_dst_reg;
	(void)tmp_src_reg;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	emit_rex_rr(buf, &len, false, src_reg, dst_reg);
	emit_u8(buf, &len, 0x31);
	emit_u8(buf, &len, 0xc0 | (kinsn_x86_code(src_reg) << 3) |
			 kinsn_x86_code(dst_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_orb_rr_x86(u8 *image, u32 *off, bool emit,
			   u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg, src_reg, tmp_dst_reg, tmp_src_reg;
	u32 len = 0;
	int err;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_byte_reg_reg_tmp2_payload(payload, &dst_reg, &src_reg,
					       &tmp_dst_reg, &tmp_src_reg);
	if (err)
		return err;
	(void)tmp_dst_reg;
	(void)tmp_src_reg;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	emit_rex8_rr(buf, &len, src_reg, dst_reg);
	emit_u8(buf, &len, 0x08);
	emit_u8(buf, &len, 0xc0 | (kinsn_x86_code(src_reg) << 3) |
			 kinsn_x86_code(dst_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_andl_imm32_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg;
	u32 imm;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_imm_payload(payload, &dst_reg, &imm);
	if (err)
		return err;

	emit_rex_rr(buf, &len, false, 0, dst_reg);
	emit_u8(buf, &len, 0x81);
	emit_u8(buf, &len, 0xE0 | kinsn_x86_reg_code(dst_reg));
	emit_u32(buf, &len, imm);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_incq_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 dst_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_reg_payload(payload, &dst_reg);
	if (err)
		return err;

	emit_rex_rr(buf, &len, true, 0, dst_reg);
	emit_u8(buf, &len, 0xff);
	emit_u8(buf, &len, 0xc0 | kinsn_x86_reg_code(dst_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_sbbl_imm0_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, cond_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_sbb_payload(payload, &dst_reg, &cond_reg);
	if (err)
		return err;
	(void)cond_reg;

	emit_rex_rr(buf, &len, false, 0, dst_reg);
	emit_u8(buf, &len, 0x83);
	emit_u8(buf, &len, 0xd8 | kinsn_x86_reg_code(dst_reg));
	emit_u8(buf, &len, 0);

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_x86_shrq_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_shrq_imm,
	.emit_x86 = emit_shrq_imm_x86,
};

const struct bpf_kinsn bpf_x86_addb_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_addb_imm,
	.emit_x86 = emit_addb_imm_x86,
};

const struct bpf_kinsn bpf_x86_andb_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_andb_imm,
	.emit_x86 = emit_andb_imm_x86,
};

const struct bpf_kinsn bpf_x86_andl_imm32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_andl_imm32,
	.emit_x86 = emit_andl_imm32_x86,
};

const struct bpf_kinsn bpf_x86_incq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_incq,
	.emit_x86 = emit_incq_x86,
};

const struct bpf_kinsn bpf_x86_sbbl_imm0_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_sbbl_imm0,
	.emit_x86 = emit_sbbl_imm0_x86,
};

const struct bpf_kinsn bpf_x86_xorb_imm_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_xorb_imm,
	.emit_x86 = emit_xorb_imm_x86,
};

const struct bpf_kinsn bpf_x86_xorb_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 3,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_xorb_rr,
	.emit_x86 = emit_xorb_rr_x86,
};

const struct bpf_kinsn bpf_x86_xorl_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_xorl_rr,
	.emit_x86 = emit_xorl_rr_x86,
};

const struct bpf_kinsn bpf_x86_orb_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_orb_rr,
	.emit_x86 = emit_orb_rr_x86,
};

static const struct bpf_kinsn * const bpf_x86_alu_imm_kinsn_descs[] = {
	&bpf_x86_addb_imm_desc,
	&bpf_x86_andb_imm_desc,
	&bpf_x86_andl_imm32_desc,
	&bpf_x86_incq_desc,
	&bpf_x86_sbbl_imm0_desc,
	&bpf_x86_shrq_imm_desc,
	&bpf_x86_orb_rr_desc,
	&bpf_x86_xorb_imm_desc,
	&bpf_x86_xorb_rr_desc,
	&bpf_x86_xorl_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_alu_imm,
		       "BpfReJIT x86 kinsns: immediate ALU",
		       bpf_x86_alu_imm_kfunc_ids,
		       bpf_x86_alu_imm_kinsn_descs);
