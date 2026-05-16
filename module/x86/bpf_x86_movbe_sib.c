// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOVBE SIB loads.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movbe16_sib(void) {}
__bpf_kfunc void bpf_x86_movbe32_sib(void) {}
__bpf_kfunc void bpf_x86_movbe64_sib(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_movbe_sib_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movbe16_sib)
BTF_ID_FLAGS(func, bpf_x86_movbe32_sib)
BTF_ID_FLAGS(func, bpf_x86_movbe64_sib)
BTF_KFUNCS_END(bpf_x86_movbe_sib_kfunc_ids)

static __always_inline int decode_movbe_sib_payload(u64 payload,
						    u8 *dst_reg, u8 *base_reg,
						    u8 *index_reg, u8 *scale_log2,
						    s16 *offset)
{
	*dst_reg = kinsn_payload_reg(payload, 0);
	*base_reg = kinsn_payload_reg(payload, 4);
	*index_reg = kinsn_payload_reg(payload, 8);
	*scale_log2 = (payload >> 12) & 0x3;
	*offset = kinsn_payload_s16(payload, 16);

	if (payload >> 32)
		return -EINVAL;
	if (payload & (0x3ULL << 14))
		return -EINVAL;
	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10 ||
	    *index_reg >= BPF_REG_10)
		return -EINVAL;

	return 0;
}

static int instantiate_movbe_sib(u64 payload, struct bpf_insn *insn_buf,
				 u8 size)
{
	u8 dst_reg, base_reg, index_reg, scale_log2, addr_reg, high_reg;
	bool need_tmp = size == BPF_H;
	u32 scratch_mask;
	s16 offset;
	int add_count;
	int cnt = 0;
	int err;

	err = decode_movbe_sib_payload(payload, &dst_reg, &base_reg,
				       &index_reg, &scale_log2, &offset);
	if (err)
		return err;

	addr_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, index_reg);
	scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg);
	if (need_tmp) {
		high_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg,
						    addr_reg);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(high_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (need_tmp) {
		insn_buf[cnt++] = BPF_MOV64_REG(high_reg, dst_reg);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, high_reg, 16);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, high_reg, 16);
	}

	insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, base_reg);
	add_count = 1 << scale_log2;
	while (add_count--)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg, index_reg);
	insn_buf[cnt++] = BPF_LDX_MEM(size, dst_reg, addr_reg, offset);
	insn_buf[cnt++] = BPF_BSWAP(dst_reg, kinsn_bpf_size_bits(size));
	if (need_tmp)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, high_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movbe16_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movbe_sib(payload, insn_buf, BPF_H);
}

static int instantiate_movbe32_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movbe_sib(payload, insn_buf, BPF_W);
}

static int instantiate_movbe64_sib(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movbe_sib(payload, insn_buf, BPF_DW);
}

static int emit_movbe_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	s16 offset;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_MOVBE))
		return -EOPNOTSUPP;

	err = decode_movbe_sib_payload(payload, &dst_reg, &base_reg,
				       &index_reg, &scale_log2, &offset);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    !kinsn_x86_valid(index_reg))
		return -EINVAL;

	if (size == BPF_H)
		kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex(buf, &len, size == BPF_DW, kinsn_x86_ext(dst_reg),
		       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0x38);
	kinsn_emit_u8(buf, &len, 0xf0);
	kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
			   scale_log2, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movbe16_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_movbe_sib_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_movbe32_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_movbe_sib_x86(image, off, emit, payload, prog, BPF_W);
}

static int emit_movbe64_sib_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_movbe_sib_x86(image, off, emit, payload, prog, BPF_DW);
}

const struct bpf_kinsn bpf_x86_movbe16_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 19 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movbe16_sib,
	.emit_x86 = emit_movbe16_sib_x86,
};

const struct bpf_kinsn bpf_x86_movbe32_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 13 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movbe32_sib,
	.emit_x86 = emit_movbe32_sib_x86,
};

const struct bpf_kinsn bpf_x86_movbe64_sib_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 13 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movbe64_sib,
	.emit_x86 = emit_movbe64_sib_x86,
};

static const struct bpf_kinsn * const bpf_x86_movbe_sib_kinsn_descs[] = {
	&bpf_x86_movbe16_sib_desc,
	&bpf_x86_movbe32_sib_desc,
	&bpf_x86_movbe64_sib_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_movbe_sib,
		       "BpfReJIT x86 kinsns: MOVBE SIB loads",
		       bpf_x86_movbe_sib_kfunc_ids,
		       bpf_x86_movbe_sib_kinsn_descs);
