// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: TEST and CMOV.
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_testq_rr(void) {}
__bpf_kfunc void bpf_x86_cmovneq_rr(void) {}
__bpf_kfunc void bpf_x86_cmoveq_rr(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_cmov_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_cmoveq_rr)
BTF_ID_FLAGS(func, bpf_x86_cmovneq_rr)
BTF_ID_FLAGS(func, bpf_x86_testq_rr)
BTF_KFUNCS_END(bpf_x86_cmov_kfunc_ids)

static __always_inline int decode_test_payload(u64 payload, u8 *reg)
{
	*reg = kinsn_payload_reg(payload, 0);

	if (payload >> 4)
		return -EINVAL;
	if (*reg > BPF_REG_10 || !kinsn_x86_reg_valid(*reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_cmov_payload(u64 payload,
					       u8 *dst_reg,
					       u8 *src_reg,
					       u8 *cond_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*cond_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (*dst_reg > BPF_REG_10 || *src_reg > BPF_REG_10 ||
	    *cond_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*dst_reg) || !kinsn_x86_reg_valid(*src_reg) ||
	    !kinsn_x86_reg_valid(*cond_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_testq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	u8 reg;
	int err;

	err = decode_test_payload(payload, &reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int instantiate_cmov(u64 payload, struct bpf_insn *insn_buf, bool move_on_eq)
{
	u8 dst_reg, src_reg, cond_reg;
	int err;

	err = decode_cmov_payload(payload, &dst_reg, &src_reg, &cond_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_IMM(move_on_eq ? BPF_JNE : BPF_JEQ, cond_reg, 0, 1);
	insn_buf[1] = BPF_MOV64_REG(dst_reg, src_reg);
	return 2;
}

static int instantiate_cmovneq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov(payload, insn_buf, false);
}

static int instantiate_cmoveq_rr(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_cmov(payload, insn_buf, true);
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

static int emit_testq_rr_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 buf[4];
	u8 reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_test_payload(payload, &reg);
	if (err)
		return err;

	emit_rex_rr(buf, &len, true, reg, reg);
	emit_u8(buf, &len, 0x85);
	emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(reg) << 3) |
		kinsn_x86_reg_code(reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_cmov_x86(u8 *image, u32 *off, bool emit,
			 u64 payload, const struct bpf_prog *prog, u8 cc)
{
	u8 buf[8];
	u8 dst_reg, src_reg, cond_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	err = decode_cmov_payload(payload, &dst_reg, &src_reg, &cond_reg);
	if (err)
		return err;

	emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	emit_u8(buf, &len, 0x0F);
	emit_u8(buf, &len, cc);
	emit_u8(buf, &len, 0xC0 |
		(kinsn_x86_reg_code(dst_reg) << 3) |
		kinsn_x86_reg_code(src_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

static int emit_cmovneq_rr_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x45);
}

static int emit_cmoveq_rr_x86(u8 *image, u32 *off, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	return emit_cmov_x86(image, off, emit, payload, prog, 0x44);
}

const struct bpf_kinsn bpf_x86_testq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_testq_rr,
	.emit_x86 = emit_testq_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmovneq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmovneq_rr,
	.emit_x86 = emit_cmovneq_rr_x86,
};

const struct bpf_kinsn bpf_x86_cmoveq_rr_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 2,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_cmoveq_rr,
	.emit_x86 = emit_cmoveq_rr_x86,
};

static const struct bpf_kinsn * const bpf_x86_cmov_kinsn_descs[] = {
	&bpf_x86_cmoveq_rr_desc,
	&bpf_x86_cmovneq_rr_desc,
	&bpf_x86_testq_rr_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_cmov, "BpfReJIT x86 kinsns: TEST/CMOV",
		       bpf_x86_cmov_kfunc_ids, bpf_x86_cmov_kinsn_descs);
