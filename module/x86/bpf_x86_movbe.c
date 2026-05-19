// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsns: MOVBE indexed loads.
 */

#include <asm/cpufeature.h>

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_movbe16(void) {}
__bpf_kfunc void bpf_x86_movbe32(void) {}
__bpf_kfunc void bpf_x86_movbe64(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_movbe_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_movbe16)
BTF_ID_FLAGS(func, bpf_x86_movbe32)
BTF_ID_FLAGS(func, bpf_x86_movbe64)
BTF_KFUNCS_END(bpf_x86_movbe_kfunc_ids)

static __always_inline int decode_movbe_payload(u64 payload,
						    u8 *dst_reg, u8 *base_reg,
						    u8 *index_reg, u8 *scale_log2,
						    s16 *offset, bool *indexed)
{
	payload = kinsn_payload_decode(payload);
	if ((payload & 0xf) == 4) {
		if (payload >> 28)
			return -EINVAL;
		*dst_reg = kinsn_payload_reg(payload, 4);
		*base_reg = kinsn_payload_reg(payload, 8);
		*index_reg = 0;
		*scale_log2 = 0;
		*offset = kinsn_payload_s16(payload, 12);
		*indexed = false;
	} else if ((payload & 0xf) == 5) {
		if (payload >> 36)
			return -EINVAL;
		*dst_reg = kinsn_payload_reg(payload, 4);
		*base_reg = kinsn_payload_reg(payload, 8);
		*index_reg = kinsn_payload_reg(payload, 12);
		*scale_log2 = (payload >> 16) & 0x3;
		*offset = kinsn_payload_s16(payload, 20);
		*indexed = true;
		if (payload & (0x3ULL << 18))
			return -EINVAL;
	} else {
		return -EINVAL;
	}

	if (*dst_reg >= BPF_REG_10 || *base_reg > BPF_REG_10 ||
	    (*indexed && *index_reg >= BPF_REG_10))
		return -EINVAL;

	return 0;
}

static bool movbe16_direct_scratch(u8 dst_reg, u8 base_reg, u8 *high_reg,
				   u8 *value_reg)
{
	u8 reg;

	*high_reg = 0;
	*value_reg = 0;
	for (reg = KINSN_X86_SCRATCH0; reg <= KINSN_X86_SCRATCH2; reg++) {
		if (reg == dst_reg || reg == base_reg)
			continue;
		if (!*high_reg) {
			*high_reg = reg;
			continue;
		}
		*value_reg = reg;
		return true;
	}
	return false;
}

static int instantiate_movbe16_direct(u8 dst_reg, u8 base_reg, s16 offset,
				      struct bpf_insn *insn_buf)
{
	u8 high_reg, value_reg;
	u32 scratch_mask;
	int cnt = 0;

	if (!movbe16_direct_scratch(dst_reg, base_reg, &high_reg, &value_reg))
		return -EINVAL;

	scratch_mask = KINSN_X86_SCRATCH_MASK(high_reg) |
		       KINSN_X86_SCRATCH_MASK(value_reg);
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	insn_buf[cnt++] = BPF_MOV64_REG(high_reg, dst_reg);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, high_reg, 16);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, high_reg, 16);
	insn_buf[cnt++] = BPF_LDX_MEM(BPF_H, value_reg, base_reg, offset);
	insn_buf[cnt++] = BPF_BSWAP(value_reg, 16);
	insn_buf[cnt++] = BPF_MOV64_REG(dst_reg, high_reg);
	insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, value_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movbe_indexed(u64 payload, struct bpf_insn *insn_buf,
				 u8 size)
{
	u8 dst_reg, base_reg, index_reg, scale_log2, addr_reg, value_reg, high_reg;
	bool need_tmp = size == BPF_H;
	bool indexed;
	u32 scratch_mask;
	u8 bytes = kinsn_bpf_size_bits(size) / 8;
	s16 offset;
	int add_count;
	int i;
	int cnt = 0;
	int err;

	err = decode_movbe_payload(payload, &dst_reg, &base_reg,
				       &index_reg, &scale_log2, &offset,
				       &indexed);
	if (err)
		return err;

	if (!indexed && (size == BPF_W || size == BPF_DW)) {
		insn_buf[cnt++] = BPF_LDX_MEM(size, dst_reg, base_reg, offset);
		insn_buf[cnt++] = BPF_BSWAP(dst_reg, size == BPF_W ? 32 : 64);
		return cnt;
	}
	if (!indexed && size == BPF_H) {
		err = instantiate_movbe16_direct(dst_reg, base_reg, offset,
						 insn_buf);
		if (err != -EINVAL)
			return err;
	}

	addr_reg = kinsn_x86_scratch_avoid(dst_reg, base_reg, index_reg);
	value_reg = kinsn_x86_scratch_avoid4(dst_reg, base_reg, index_reg,
					     addr_reg);
	scratch_mask = KINSN_X86_SCRATCH_MASK(addr_reg) |
		       KINSN_X86_SCRATCH_MASK(value_reg);
	if (need_tmp) {
		high_reg = kinsn_x86_scratch_avoid4(dst_reg, base_reg,
						     addr_reg, value_reg);
		scratch_mask |= KINSN_X86_SCRATCH_MASK(high_reg);
	}
	kinsn_x86_save_scratch(insn_buf, &cnt, scratch_mask);
	if (need_tmp) {
		insn_buf[cnt++] = BPF_MOV64_REG(high_reg, dst_reg);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_RSH, high_reg, 16);
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, high_reg, 16);
	}

	insn_buf[cnt++] = BPF_MOV64_REG(addr_reg, base_reg);
	if (indexed) {
		add_count = 1 << scale_log2;
		while (add_count--)
			insn_buf[cnt++] = BPF_ALU64_REG(BPF_ADD, addr_reg,
							index_reg);
	}
	insn_buf[cnt++] = BPF_MOV64_IMM(dst_reg, 0);
	for (i = 0; i < bytes; i++) {
		insn_buf[cnt++] = BPF_LDX_MEM(BPF_B, value_reg, addr_reg,
					      offset + i);
		if (i != bytes - 1)
			insn_buf[cnt++] = BPF_ALU64_IMM(BPF_LSH, value_reg,
							(bytes - 1 - i) * 8);
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, value_reg);
	}
	if (need_tmp)
		insn_buf[cnt++] = BPF_ALU64_REG(BPF_OR, dst_reg, high_reg);
	kinsn_x86_restore_scratch(insn_buf, &cnt, scratch_mask);
	return cnt;
}

static int instantiate_movbe16_indexed(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movbe_indexed(payload, insn_buf, BPF_H);
}

static int instantiate_movbe32_indexed(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movbe_indexed(payload, insn_buf, BPF_W);
}

static int instantiate_movbe64_indexed(u64 payload, struct bpf_insn *insn_buf)
{
	return instantiate_movbe_indexed(payload, insn_buf, BPF_DW);
}

static int emit_movbe_indexed_x86(u8 *image, u32 *off, bool emit, u64 payload,
			      const struct bpf_prog *prog, u8 size)
{
	u8 buf[16];
	u8 dst_reg, base_reg, index_reg, scale_log2;
	bool indexed;
	s16 offset;
	u32 len = 0;
	int err;

	if (!boot_cpu_has(X86_FEATURE_MOVBE))
		return -EOPNOTSUPP;

	err = decode_movbe_payload(payload, &dst_reg, &base_reg,
				       &index_reg, &scale_log2, &offset,
				       &indexed);
	if (err)
		return err;

	dst_reg = kinsn_x86_reg_for_prog(prog, dst_reg);
	base_reg = kinsn_x86_reg_for_prog(prog, base_reg);
	if (indexed)
		index_reg = kinsn_x86_reg_for_prog(prog, index_reg);
	if (!kinsn_x86_valid(dst_reg) || !kinsn_x86_valid(base_reg) ||
	    (indexed && !kinsn_x86_valid(index_reg)))
		return -EINVAL;

	if (size == BPF_H)
		kinsn_emit_u8(buf, &len, 0x66);
	kinsn_emit_rex(buf, &len, size == BPF_DW, kinsn_x86_ext(dst_reg),
		       kinsn_x86_ext(index_reg), kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, &len, 0x0f);
	kinsn_emit_u8(buf, &len, 0x38);
	kinsn_emit_u8(buf, &len, 0xf0);
	if (indexed)
		kinsn_emit_sib_mem(buf, &len, dst_reg, base_reg, index_reg,
				   scale_log2, offset);
	else
		kinsn_emit_modrm_mem(buf, &len, dst_reg, base_reg, offset);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_movbe16_indexed_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_movbe_indexed_x86(image, off, emit, payload, prog, BPF_H);
}

static int emit_movbe32_indexed_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_movbe_indexed_x86(image, off, emit, payload, prog, BPF_W);
}

static int emit_movbe64_indexed_x86(u8 *image, u32 *off, bool emit, u64 payload,
				const struct bpf_prog *prog)
{
	return emit_movbe_indexed_x86(image, off, emit, payload, prog, BPF_DW);
}

const struct bpf_kinsn bpf_x86_movbe16_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 19 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movbe16_indexed,
	.emit_x86 = emit_movbe16_indexed_x86,
};

const struct bpf_kinsn bpf_x86_movbe32_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 18 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movbe32_indexed,
	.emit_x86 = emit_movbe32_indexed_x86,
};

const struct bpf_kinsn bpf_x86_movbe64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 30 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 16,
	.instantiate_insn = instantiate_movbe64_indexed,
	.emit_x86 = emit_movbe64_indexed_x86,
};

static const struct bpf_kinsn * const bpf_x86_movbe_kinsn_descs[] = {
	&bpf_x86_movbe16_desc,
	&bpf_x86_movbe32_desc,
	&bpf_x86_movbe64_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_movbe,
		       "BpfReJIT x86 kinsns: MOVBE indexed loads",
		       bpf_x86_movbe_kfunc_ids,
		       bpf_x86_movbe_kinsn_descs);
