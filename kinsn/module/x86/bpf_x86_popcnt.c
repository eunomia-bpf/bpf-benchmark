// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsn: POPCNT r64, r/m64.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_popcntq(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_popcnt_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_popcntq)
BTF_KFUNCS_END(bpf_x86_popcnt_kfunc_ids)

#define X86_FORM_RR		1
#define X86_FORM_ARCH_RR	12

static __always_inline int decode_popcnt_payload(u64 payload, u8 *dst_reg, u8 *src_reg)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) != X86_FORM_RR && (payload & 0xf) != X86_FORM_ARCH_RR)
		return -EINVAL;
	*dst_reg = kinsn_payload_reg(payload, 4);
	*src_reg = kinsn_payload_reg(payload, 8);
	if (payload >> 12)
		return -EINVAL;
	if (!kinsn_x86_reg_is_bpf_writable(*dst_reg) || !kinsn_x86_operand_valid(*src_reg))
		return -EINVAL;
	return 0;
}

static int popcnt_low_tree(u8 dst, struct bpf_insn *buf, u8 depth, u8 value)
{
	int cnt = 0, branch, join, bit, ones = 0;

	if (!depth) {
		for (bit = 0; bit < 7; bit++)
			ones += (value >> bit) & 1;
		buf[0] = BPF_ALU64_IMM(BPF_AND, dst, -128);
		buf[1] = BPF_ALU64_IMM(BPF_OR, dst, ones);
		return 2;
	}
	branch = cnt++;
	cnt += popcnt_low_tree(dst, buf + cnt, depth - 1, value);
	join = cnt++;
	buf[branch] = BPF_JMP_IMM(BPF_JSET, dst, 1U << (depth - 1), cnt - branch - 1);
	cnt += popcnt_low_tree(dst, buf + cnt, depth - 1, value + (1U << (depth - 1)));
	buf[join] = BPF_JMP_A(cnt - join - 1);
	return cnt;
}

static int popcnt_rotate(u8 dst, struct bpf_insn *buf, int count)
{
	int i, cnt = 0;

	for (i = 0; i < count; i++) {
		buf[cnt++] = BPF_JMP_IMM(BPF_JSLT, dst, 0, 2);
		buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst, 1);
		buf[cnt++] = BPF_JMP_A(2);
		buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, dst, 1);
		buf[cnt++] = BPF_ALU64_IMM(BPF_OR, dst, 1);
	}
	return cnt;
}

static int instantiate_popcntq(u64 payload, struct bpf_insn *buf)
{
	u8 dst, src;
	int cnt = 0, bit, branch, join, err;

	err = decode_popcnt_payload(payload, &dst, &src);
	if (err)
		return err;
	buf[cnt++] = BPF_MOV64_REG(dst, src);
	cnt += popcnt_low_tree(dst, buf + cnt, 7, 0);
	/* Bits 6:0 hold the count, which fits seven bits even after all 64
	 * source bits. Higher unprocessed bits remain intact until counted. */
	for (bit = 7; bit < 64; bit++) {
		cnt += popcnt_rotate(dst, buf + cnt, 64 - bit);
		branch = cnt++;
		cnt += popcnt_rotate(dst, buf + cnt, bit);
		join = cnt++;
		buf[branch] = BPF_JMP_IMM(BPF_JSET, dst, 1, cnt - branch - 1);
		buf[cnt++] = BPF_ALU64_IMM(BPF_AND, dst, -2);
		cnt += popcnt_rotate(dst, buf + cnt, bit);
		buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, dst, 1);
		buf[join] = BPF_JMP_A(cnt - join - 1);
	}
	return cnt;
}

static int emit_popcntq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 buf[24];
	u8 dst_reg, src_reg;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_POPCNT))
		return -EOPNOTSUPP;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_u8(buf, &len, 0xf3);
	kinsn_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0xb8);
	kinsn_emit_u8(buf, &len, 0xc0 |
		       (kinsn_x86_code(dst_reg) << 3) |
		       kinsn_x86_code(src_reg));

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_popcntq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 28954,
	.max_emit_bytes = 5,
	.instantiate_insn = instantiate_popcntq,
	.emit_x86 = emit_popcntq_x86,
};

static const struct bpf_kinsn * const bpf_x86_popcnt_kinsn_descs[] = {
	&bpf_x86_popcntq_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_popcnt,
		       "BpfReJIT x86 kinsn: POPCNT",
		       bpf_x86_popcnt_kfunc_ids,
		       bpf_x86_popcnt_kinsn_descs);
