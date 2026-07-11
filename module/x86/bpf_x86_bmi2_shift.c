// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 koperation: BMI2 variable shifts.
 */

#include <asm/cpufeature.h>

#include "kop_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_shlxl(void) {}
__bpf_kfunc void bpf_x86_shlxq(void) {}
__bpf_kfunc void bpf_x86_shrxl(void) {}
__bpf_kfunc void bpf_x86_shrxq(void) {}
__bpf_kfunc void bpf_x86_bzhil(void) {}
__bpf_kfunc void bpf_x86_bzhiq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_bmi2_shift_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_bzhil)
BTF_ID_FLAGS(func, bpf_x86_bzhiq)
BTF_ID_FLAGS(func, bpf_x86_shlxl)
BTF_ID_FLAGS(func, bpf_x86_shlxq)
BTF_ID_FLAGS(func, bpf_x86_shrxl)
BTF_ID_FLAGS(func, bpf_x86_shrxq)
BTF_KFUNCS_END(bpf_x86_bmi2_shift_kfunc_ids)

static __always_inline int decode_bmi2_shift_payload(u64 payload, u8 *dst_reg,
						     u8 *src_reg,
						     u8 *cnt_reg)
{
	payload = kop_payload_decode(payload);
	*dst_reg = kop_payload_reg(payload, 0);
	*src_reg = kop_payload_reg(payload, 4);
	*cnt_reg = kop_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!kop_x86_operand_valid(*dst_reg) ||
	    !kop_x86_operand_valid(*src_reg) ||
	    !kop_x86_operand_valid(*cnt_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_bmi2_shift(u64 payload, struct bpf_insn *insn_buf,
				  bool is64, bool left)
{
	u8 dst_reg, src_reg, cnt_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1);
	int cnt = 0;
	int err;

	err = decode_bmi2_shift_payload(payload, &dst_reg, &src_reg, &cnt_reg);
	if (err)
		return err;

	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kop_x86_read(insn_buf, &cnt, KOP_X86_SCRATCH0, src_reg, is64,
		       false);
	kop_x86_read(insn_buf, &cnt, KOP_X86_SCRATCH1, cnt_reg, is64,
		       false);
	insn_buf[cnt++] = is64 ?
		BPF_ALU64_REG(left ? BPF_LSH : BPF_RSH, KOP_X86_SCRATCH0,
			      KOP_X86_SCRATCH1) :
		BPF_ALU32_REG(left ? BPF_LSH : BPF_RSH, KOP_X86_SCRATCH0,
			      KOP_X86_SCRATCH1);
	kop_x86_write(insn_buf, &cnt, dst_reg, KOP_X86_SCRATCH0,
			scratch_mask, is64, false);
	kop_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_shlxl(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bmi2_shift(payload, insn_buf, false, true);
}

static int instantiate_shlxq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bmi2_shift(payload, insn_buf, true, true);
}

static int instantiate_shrxl(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bmi2_shift(payload, insn_buf, false, false);
}

static int instantiate_shrxq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bmi2_shift(payload, insn_buf, true, false);
}

static int instantiate_bzhi(u64 payload, struct bpf_insn *insn_buf, bool is64)
{
	u8 dst_reg, src_reg, cnt_reg;
	u32 scratch_mask = KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH0) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH1) |
			   KOP_X86_SCRATCH_MASK(KOP_X86_SCRATCH2);
	u32 restore_mask;
	int j_count_ge, write_label;
	int cnt = 0;
	int err;

	err = decode_bmi2_shift_payload(payload, &dst_reg, &src_reg, &cnt_reg);
	if (err)
		return err;
	restore_mask = scratch_mask;
	if (kop_x86_is_scratch(dst_reg))
		restore_mask &= ~KOP_X86_SCRATCH_MASK(dst_reg);

	kop_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	kop_x86_read(insn_buf, &cnt, KOP_X86_SCRATCH0, src_reg, is64,
		       false);
	kop_x86_read(insn_buf, &cnt, KOP_X86_SCRATCH1, cnt_reg, is64,
		       false);
	j_count_ge = cnt;
	insn_buf[cnt++] = BPF_JMP_IMM(BPF_JGE, KOP_X86_SCRATCH1,
				      is64 ? 64 : 32, 0);
	insn_buf[cnt++] = is64 ?
		BPF_MOV64_IMM(KOP_X86_SCRATCH2, 1) :
		BPF_MOV32_IMM(KOP_X86_SCRATCH2, 1);
	insn_buf[cnt++] = is64 ?
		BPF_ALU64_REG(BPF_LSH, KOP_X86_SCRATCH2,
			      KOP_X86_SCRATCH1) :
		BPF_ALU32_REG(BPF_LSH, KOP_X86_SCRATCH2,
			      KOP_X86_SCRATCH1);
	insn_buf[cnt++] = is64 ?
		BPF_ALU64_IMM(BPF_ADD, KOP_X86_SCRATCH2, -1) :
		BPF_ALU32_IMM(BPF_ADD, KOP_X86_SCRATCH2, -1);
	insn_buf[cnt++] = is64 ?
		BPF_ALU64_REG(BPF_AND, KOP_X86_SCRATCH0,
			      KOP_X86_SCRATCH2) :
		BPF_ALU32_REG(BPF_AND, KOP_X86_SCRATCH0,
			      KOP_X86_SCRATCH2);
	write_label = cnt;
	kop_x86_write(insn_buf, &cnt, dst_reg, KOP_X86_SCRATCH0,
			scratch_mask, is64, false);
	kop_x86_restore_scratch(insn_buf, &cnt, restore_mask);

	insn_buf[j_count_ge].off = write_label - j_count_ge - 1;
	return cnt;
}

static int instantiate_bzhil(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bzhi(payload, insn_buf, false);
}

static int instantiate_bzhiq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bzhi(payload, insn_buf, true);
}

static __always_inline u8 kop_x86_reg_no(u8 reg)
{
	return kop_x86_code(reg) | (kop_x86_ext(reg) ? 8 : 0);
}

static void emit_bmi2_shift_rrr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg,
				u8 cnt_reg, bool is64, bool left)
{
	u8 vex2 = 0xe2;
	u8 cnt_no = kop_x86_reg_no(cnt_reg);
	u8 vex3 = (is64 ? 0x80 : 0x00) | (((~cnt_no) & 0xf) << 3) |
		  (left ? 0x01 : 0x03);

	if (kop_x86_ext(dst_reg))
		vex2 &= ~0x80;
	if (kop_x86_ext(src_reg))
		vex2 &= ~0x20;

	kop_emit_u8(buf, len, 0xc4);
	kop_emit_u8(buf, len, vex2);
	kop_emit_u8(buf, len, vex3);
	kop_emit_u8(buf, len, 0xf7);
	kop_emit_u8(buf, len, 0xc0 |
		       (kop_x86_code(dst_reg) << 3) |
		       kop_x86_code(src_reg));
}

static void emit_bzhi_rrr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg,
			  u8 cnt_reg, bool is64)
{
	u8 vex2 = 0xe2;
	u8 cnt_no = kop_x86_reg_no(cnt_reg);
	u8 vex3 = (is64 ? 0x80 : 0x00) | (((~cnt_no) & 0xf) << 3);

	if (kop_x86_ext(dst_reg))
		vex2 &= ~0x80;
	if (kop_x86_ext(src_reg))
		vex2 &= ~0x20;

	kop_emit_u8(buf, len, 0xc4);
	kop_emit_u8(buf, len, vex2);
	kop_emit_u8(buf, len, vex3);
	kop_emit_u8(buf, len, 0xf5);
	kop_emit_u8(buf, len, 0xc0 |
		       (kop_x86_code(dst_reg) << 3) |
		       kop_x86_code(src_reg));
}

static int emit_bmi2_shift_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog, bool is64,
			       bool left)
{
	u8 buf[8];
	u8 dst_reg, src_reg, cnt_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_BMI2))
		return -EOPNOTSUPP;

	err = decode_bmi2_shift_payload(payload, &dst_reg, &src_reg, &cnt_reg);
	if (err)
		return err;
	dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
	src_reg = kop_x86_reg_for_prog(prog, src_reg);
	cnt_reg = kop_x86_reg_for_prog(prog, cnt_reg);
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(src_reg) ||
	    !kop_x86_valid(cnt_reg))
		return -EINVAL;

	emit_bmi2_shift_rrr(buf, &len, dst_reg, src_reg, cnt_reg, is64,
			    left);
	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_bzhi_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog, bool is64)
{
	u8 buf[8];
	u8 dst_reg, src_reg, cnt_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_BMI2))
		return -EOPNOTSUPP;

	err = decode_bmi2_shift_payload(payload, &dst_reg, &src_reg, &cnt_reg);
	if (err)
		return err;
	dst_reg = kop_x86_reg_for_prog(prog, dst_reg);
	src_reg = kop_x86_reg_for_prog(prog, src_reg);
	cnt_reg = kop_x86_reg_for_prog(prog, cnt_reg);
	if (!kop_x86_valid(dst_reg) || !kop_x86_valid(src_reg) ||
	    !kop_x86_valid(cnt_reg))
		return -EINVAL;

	emit_bzhi_rrr(buf, &len, dst_reg, src_reg, cnt_reg, is64);
	return kop_emit_finish(image, off, emit, buf, len);
}

static int emit_shlxl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, const u8 *final_ip)
{
	return emit_bmi2_shift_x86(image, off, emit, payload, prog, false,
				   true);
}

static int emit_shlxq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, const u8 *final_ip)
{
	return emit_bmi2_shift_x86(image, off, emit, payload, prog, true,
				   true);
}

static int emit_shrxl_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, const u8 *final_ip)
{
	return emit_bmi2_shift_x86(image, off, emit, payload, prog, false,
				   false);
}

static int emit_shrxq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, const u8 *final_ip)
{
	return emit_bmi2_shift_x86(image, off, emit, payload, prog, true,
				   false);
}

static int emit_bzhil_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, const u8 *final_ip)
{
	return emit_bzhi_x86(image, off, emit, payload, prog, false);
}

static int emit_bzhiq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog, const u8 *final_ip)
{
	return emit_bzhi_x86(image, off, emit, payload, prog, true);
}

const struct bpf_kop bpf_x86_shlxl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_shlxl,
	.emit_x86 = emit_shlxl_x86,
};

const struct bpf_kop bpf_x86_shlxq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_shlxq,
	.emit_x86 = emit_shlxq_x86,
};

const struct bpf_kop bpf_x86_shrxl_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_shrxl,
	.emit_x86 = emit_shrxl_x86,
};

const struct bpf_kop bpf_x86_shrxq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 4 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_shrxq,
	.emit_x86 = emit_shrxq_x86,
};

const struct bpf_kop bpf_x86_bzhil_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_bzhil,
	.emit_x86 = emit_bzhil_x86,
};

const struct bpf_kop bpf_x86_bzhiq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 10 + KOP_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_bzhiq,
	.emit_x86 = emit_bzhiq_x86,
};

static const struct bpf_kop * const bpf_x86_bmi2_shift_kop_descs[] = {
	&bpf_x86_bzhil_desc,
	&bpf_x86_bzhiq_desc,
	&bpf_x86_shlxl_desc,
	&bpf_x86_shlxq_desc,
	&bpf_x86_shrxl_desc,
	&bpf_x86_shrxq_desc,
};

DEFINE_KOP_V2_MODULE(bpf_x86_bmi2_shift,
		       "BpfReJIT x86 koperation: BMI2 variable shifts and BZHI",
		       bpf_x86_bmi2_shift_kfunc_ids,
		       bpf_x86_bmi2_shift_kop_descs);
