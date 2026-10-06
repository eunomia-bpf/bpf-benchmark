// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsn: BMI1 scalar bit instructions.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_bextrq(void) {}
__bpf_kfunc void bpf_x86_blsiq(void) {}
__bpf_kfunc void bpf_x86_blsrq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_bmi1_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_bextrq)
BTF_ID_FLAGS(func, bpf_x86_blsiq)
BTF_ID_FLAGS(func, bpf_x86_blsrq)
BTF_KFUNCS_END(bpf_x86_bmi1_kfunc_ids)

static __always_inline int decode_bmi1_payload(u64 payload, u8 *dst_reg,
					       u8 *src_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);

	if (payload >> 8)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;

	return 0;
}

static __always_inline int decode_bextr_payload(u64 payload, u8 *dst_reg,
						u8 *src_reg, u8 *ctl_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*ctl_reg = kinsn_payload_reg(payload, 8);

	if (payload >> 12)
		return -EINVAL;
	if (!kinsn_x86_operand_valid(*dst_reg) ||
	    !kinsn_x86_operand_valid(*src_reg) ||
	    !kinsn_x86_operand_valid(*ctl_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_bextr_leaf(u8 dst_reg, u8 src_reg, u8 start,
				  u8 length, struct bpf_insn *insn_buf)
{
	int cnt = 0;

	if (!length) {
		insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 0);
		return cnt;
	}
	insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, start);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, 64 - length);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, 64 - length);
	return cnt;
}

static int instantiate_bextr_length_tree(u8 dst_reg, u8 src_reg, u8 ctl_reg,
					 u8 start, u8 depth, u8 base,
					 struct bpf_insn *insn_buf)
{
	int cnt = 0;
	int branch;
	int join;

	if (!depth)
		return instantiate_bextr_leaf(dst_reg, src_reg, start, base, insn_buf);
	branch = cnt++;
	cnt += instantiate_bextr_length_tree(dst_reg, src_reg, ctl_reg, start,
					    depth - 1, base, insn_buf + cnt);
	join = cnt++;
	insn_buf[branch] = BPF_JMP_IMM(BPF_JSET, ctl_reg,
				      1U << (depth + 7), cnt - branch - 1);
	cnt += instantiate_bextr_length_tree(dst_reg, src_reg, ctl_reg, start,
					    depth - 1, base + (1U << (depth - 1)),
					    insn_buf + cnt);
	insn_buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

static int instantiate_bextr_length(u8 dst_reg, u8 src_reg, u8 ctl_reg,
				    u8 start, struct bpf_insn *insn_buf)
{
	int cnt = 1;
	int join;

	cnt += instantiate_bextr_length_tree(dst_reg, src_reg, ctl_reg, start,
					    6, 0, insn_buf + cnt);
	join = cnt++;
	/* Lengths 64..255 keep every bit of the shifted source. */
	insn_buf[0] = BPF_JMP_IMM(BPF_JSET, ctl_reg, 0xc000, cnt - 1);
	insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, start);
	insn_buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

/* Capture all eight start bits, then length bits, before writing dst.
 * This includes ctl=dst and ctl=src; start>=64 always returns zero.
 */
static int instantiate_bextr_start_tree(u8 dst_reg, u8 src_reg, u8 ctl_reg,
					u8 depth, u16 base,
					struct bpf_insn *insn_buf)
{
	int cnt = 0;
	int branch;
	int join;

	if (!depth) {
		if (base >= 64) {
			insn_buf[0] = BPF_MOV64_IMM(dst_reg, 0);
			return 1;
		}
		return instantiate_bextr_length(dst_reg, src_reg, ctl_reg, base, insn_buf);
	}
	branch = cnt++;
	cnt += instantiate_bextr_start_tree(dst_reg, src_reg, ctl_reg,
					   depth - 1, base, insn_buf + cnt);
	join = cnt++;
	insn_buf[branch] = BPF_JMP_IMM(BPF_JSET, ctl_reg,
				      1U << (depth - 1), cnt - branch - 1);
	cnt += instantiate_bextr_start_tree(dst_reg, src_reg, ctl_reg,
					   depth - 1, base + (1U << (depth - 1)),
					   insn_buf + cnt);
	insn_buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

static int instantiate_bextrq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, ctl_reg;
	int err;

	err = decode_bextr_payload(payload, &dst_reg, &src_reg, &ctl_reg);
	if (err)
		return err;
	return instantiate_bextr_start_tree(dst_reg, src_reg, ctl_reg, 8, 0, insn_buf);
}

/* Shift past zero low bits. The first set bit and its position live in
 * control flow, so neither operands nor other registers need spill slots.
 */
static int instantiate_bls_scan(bool isolate, u8 dst_reg, u8 remaining,
				u8 shift, struct bpf_insn *insn_buf)
{
	int cnt = 0;
	int branch;
	int join;

	if (!remaining) {
		insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 0);
		return cnt;
	}
	branch = cnt++;
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, 1);
	cnt += instantiate_bls_scan(isolate, dst_reg, remaining - 1,
				    shift + 1, insn_buf + cnt);
	join = cnt++;
	insn_buf[branch] = BPF_JMP_IMM(BPF_JSET, dst_reg, 1, cnt - branch - 1);
	insn_buf[cnt++] = isolate ? BPF_MOV64_IMM(dst_reg, 1) :
		BPF_ALU64_IMM(BPF_ADD, dst_reg, -1);
	if (shift)
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst_reg, shift);
	insn_buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

static int instantiate_bls(u64 payload, struct bpf_insn *insn_buf, bool isolate)
{
	u8 dst_reg, src_reg;
	int err;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	insn_buf[0] = BPF_MOV64_REG(dst_reg, src_reg);
	return 1 + instantiate_bls_scan(isolate, dst_reg, 64, 0, insn_buf + 1);
}

static int instantiate_blsiq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bls(payload, insn_buf, true);
}

static int instantiate_blsrq(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_bls(payload, insn_buf, false);
}

static __always_inline u8 kinsn_x86_reg_no(u8 reg)
{
	return kinsn_x86_code(reg) | (kinsn_x86_ext(reg) ? 8 : 0);
}

static void emit_bmi1_rr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg,
			 u8 opcode_ext)
{
	u8 vex2 = 0xe2;
	u8 dst_no = kinsn_x86_reg_no(dst_reg);
	u8 vex3 = 0x80 | (((~dst_no) & 0xf) << 3);

	if (kinsn_x86_ext(src_reg))
		vex2 &= ~0x20;

	kinsn_emit_u8(buf, len, 0xc4);
	kinsn_emit_u8(buf, len, vex2);
	kinsn_emit_u8(buf, len, vex3);
	kinsn_emit_u8(buf, len, 0xf3);
	kinsn_emit_u8(buf, len, 0xc0 |
		       (opcode_ext << 3) |
		       kinsn_x86_code(src_reg));
}

static void emit_bextr_rrr(u8 *buf, u32 *len, u8 dst_reg, u8 src_reg,
			   u8 ctl_reg)
{
	u8 vex2 = 0xe2;
	u8 ctl_no = kinsn_x86_reg_no(ctl_reg);

	if (kinsn_x86_ext(dst_reg))
		vex2 &= ~0x80;
	if (kinsn_x86_ext(src_reg))
		vex2 &= ~0x20;

	kinsn_emit_u8(buf, len, 0xc4);
	kinsn_emit_u8(buf, len, vex2);
	kinsn_emit_u8(buf, len, 0x80 | (((~ctl_no) & 0xf) << 3));
	kinsn_emit_u8(buf, len, 0xf7);
	kinsn_emit_u8(buf, len, 0xc0 |
		       (kinsn_x86_code(dst_reg) << 3) |
		       kinsn_x86_code(src_reg));
}

static int emit_bextrq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			   const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 buf[8];
	u8 dst_reg, src_reg, ctl_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_BMI1))
		return -EOPNOTSUPP;

	err = decode_bextr_payload(payload, &dst_reg, &src_reg, &ctl_reg);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	ctl_reg = kinsn_x86_reg_for_prog(prog, ctl_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg) ||
	    !kinsn_x86_valid(ctl_reg))
		return -EINVAL;

	emit_bextr_rrr(buf, &len, dst_reg, src_reg, ctl_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_bmi1_x86(u8 *image, u32 *off, bool emit, u64 payload,
			 const struct bpf_prog *prog, u8 opcode_ext)
{
	u8 buf[8];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_BMI1))
		return -EOPNOTSUPP;

	err = decode_bmi1_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	emit_bmi1_rr(buf, &len, dst_reg, src_reg, opcode_ext);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_blsiq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_bmi1_x86(image, off, emit, payload, prog, 3);
}

static int emit_blsrq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			  const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	return emit_bmi1_x86(image, off, emit, payload, prog, 1);
}

const struct bpf_kinsn bpf_x86_bextrq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 25214,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_bextrq,
	.emit_x86 = emit_bextrq_x86,
};

const struct bpf_kinsn bpf_x86_blsiq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 321,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_blsiq,
	.emit_x86 = emit_blsiq_x86,
};

const struct bpf_kinsn bpf_x86_blsrq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 321,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_blsrq,
	.emit_x86 = emit_blsrq_x86,
};

static const struct bpf_kinsn * const bpf_x86_bmi1_kinsn_descs[] = {
	&bpf_x86_bextrq_desc,
	&bpf_x86_blsiq_desc,
	&bpf_x86_blsrq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_bmi1,
		       "BpfReJIT x86 kinsn: BMI1 BEXTR/BLSI/BLSR",
		       bpf_x86_bmi1_kfunc_ids,
		       bpf_x86_bmi1_kinsn_descs);
