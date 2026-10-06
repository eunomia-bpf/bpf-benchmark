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

static int popcnt_temp(u8 dst_reg, u8 src_reg)
{
	u8 reg;

	for (reg = BPF_REG_0; reg < BPF_REG_10; reg++) {
		if (reg != dst_reg && reg != src_reg)
			return reg;
	}
	return -EINVAL;
}

static int instantiate_popcntq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg;
	int temp;
	int cnt = 0;
	int i;
	int err;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	temp = popcnt_temp(dst_reg, src_reg);
	if (temp < 0)
		return temp;
	insn_buf[cnt++] = BPF_STX_MEM(BPF_DW, BPF_REG_10, temp, KINSN_X86_PROOF_RHS_OFF);
	insn_buf[cnt++] = BPF_MOV64_REG(temp, src_reg);
	insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 64);
	/* Subtract one for each zero bit; counter starts at 64. */
	for (i = 0; i < 64; i++) {
		insn_buf[cnt++] = BPF_JMP_IMM(BPF_JSET, temp, 1, 1);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_ADD, dst_reg, -1);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, temp, 1);
	}
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_DW, temp, BPF_REG_10, KINSN_X86_PROOF_RHS_OFF);
	return cnt;
}

static int emit_popcntq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog,
			 const u8 *final_ip)
{
	u8 buf[24];
	u8 dst_reg, src_reg;
	u8 frame = kinsn_x86_reg_for_prog(prog, BPF_REG_10);
	int temp;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_POPCNT))
		return -EOPNOTSUPP;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg);
	if (err)
		return err;
	temp = popcnt_temp(dst_reg, src_reg);
	if (temp < 0)
		return temp;
	temp = kinsn_x86_reg_for_prog(prog, temp);
	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	src_reg = kinsn_x86_reg_for_prog(prog, src_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(temp), false, kinsn_x86_ext(frame));
	kinsn_emit_u8(buf, &len, 0x89);
	kinsn_emit_modrm_mem(buf, &len, temp, frame, KINSN_X86_PROOF_RHS_OFF);

	kinsn_emit_u8(buf, &len, 0xf3);
	kinsn_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0xb8);
	kinsn_emit_u8(buf, &len, 0xc0 |
		       (kinsn_x86_code(dst_reg) << 3) |
		       kinsn_x86_code(src_reg));

	kinsn_emit_rex(buf, &len, true, kinsn_x86_ext(temp), false, kinsn_x86_ext(frame));
	kinsn_emit_u8(buf, &len, 0x8b);
	kinsn_emit_modrm_mem(buf, &len, temp, frame, KINSN_X86_PROOF_RHS_OFF);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

const struct bpf_kinsn bpf_x86_popcntq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 196,
	.max_emit_bytes = 24,
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
