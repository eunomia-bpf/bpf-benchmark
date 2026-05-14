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

static __always_inline int decode_popcnt_payload(u64 payload, u8 *dst_reg,
						 u8 *src_reg, u8 *tmp1_reg,
						 u8 *tmp2_reg)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*src_reg = kinsn_payload_reg(payload, 4);
	*tmp1_reg = kinsn_payload_reg(payload, 8);
	*tmp2_reg = kinsn_payload_reg(payload, 12);

	if (payload >> 16)
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *src_reg >= BPF_REG_10 ||
	    *tmp1_reg >= BPF_REG_10 || *tmp2_reg >= BPF_REG_10)
		return -EINVAL;
	if (*tmp1_reg == *dst_reg || *tmp1_reg == *src_reg ||
	    *tmp2_reg == *dst_reg || *tmp2_reg == *src_reg ||
	    *tmp1_reg == *tmp2_reg)
		return -EINVAL;

	return 0;
}

static __always_inline void emit_ldimm64(struct bpf_insn *insn_buf, int *cnt,
					 u8 dst_reg, u64 imm)
{
	struct bpf_insn insns[] = { BPF_LD_IMM64(dst_reg, imm) };

	insn_buf[(*cnt)++] = insns[0];
	insn_buf[(*cnt)++] = insns[1];
}

static int instantiate_popcntq(u64 payload, struct bpf_insn *insn_buf)
{
	u8 dst_reg, src_reg, tmp1_reg, tmp2_reg;
	int cnt = 0;
	int err;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg, &tmp1_reg,
				    &tmp2_reg);
	if (err)
		return err;

	if (dst_reg != src_reg)
		insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, src_reg);

	insn_buf[cnt++] = BPF_MOV64_REG(tmp1_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, tmp1_reg, 1);
	emit_ldimm64(insn_buf, &cnt, tmp2_reg, 0x5555555555555555ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, tmp1_reg, tmp2_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_SUB, dst_reg, tmp1_reg);

	insn_buf[cnt++] = BPF_MOV64_REG(tmp1_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, tmp1_reg, 2);
	emit_ldimm64(insn_buf, &cnt, tmp2_reg, 0x3333333333333333ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, dst_reg, tmp2_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, tmp1_reg, tmp2_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, tmp1_reg);

	insn_buf[cnt++] = BPF_MOV64_REG(tmp1_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, tmp1_reg, 4);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, dst_reg, tmp1_reg);
	emit_ldimm64(insn_buf, &cnt, tmp2_reg, 0x0f0f0f0f0f0f0f0fULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_AND, dst_reg, tmp2_reg);

	emit_ldimm64(insn_buf, &cnt, tmp2_reg, 0x0101010101010101ULL);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_MUL, dst_reg, tmp2_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, dst_reg, 56);
	return cnt;
}

static int emit_popcntq_x86(u8 *image, u32 *off, bool emit, u64 payload,
			    const struct bpf_prog *prog)
{
	u8 buf[8];
	u8 dst_reg, src_reg, tmp1_reg, tmp2_reg;
	u32 len = 0;
	int err;

	(void)prog;

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;
	if (!boot_cpu_has(X86_FEATURE_POPCNT))
		return -EOPNOTSUPP;

	err = decode_popcnt_payload(payload, &dst_reg, &src_reg, &tmp1_reg,
				    &tmp2_reg);
	if (err)
		return err;
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(src_reg))
		return -EINVAL;

	kinsn_emit_u8(buf, &len, 0xf3);
	kinsn_emit_rex_rr(buf, &len, true, dst_reg, src_reg);
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0xb8);
	kinsn_emit_u8(buf, &len, 0xc0 |
		       (kinsn_x86_code(dst_reg) << 3) |
		       kinsn_x86_code(src_reg));

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_x86_popcntq_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 24,
	.max_emit_bytes = 8,
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
