// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 kinsn: PREFETCH hints for x86-64
 */

#include "kinsn_x86_emit.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_x86_prefetchnta(void) {}
__bpf_kfunc void bpf_x86_prefetcht0(void) {}
__bpf_kfunc void bpf_x86_prefetcht1(void) {}
__bpf_kfunc void bpf_x86_prefetcht2(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_prefetch_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_prefetchnta)
BTF_ID_FLAGS(func, bpf_x86_prefetcht0)
BTF_ID_FLAGS(func, bpf_x86_prefetcht1)
BTF_ID_FLAGS(func, bpf_x86_prefetcht2)
BTF_KFUNCS_END(bpf_x86_prefetch_kfunc_ids)

static __always_inline int decode_prefetch_payload(u64 payload, u8 *ptr_reg)
{
	u8 hint_kind = (payload >> 4) & 0xf;

	*ptr_reg = kinsn_payload_reg(payload, 0);

	if (hint_kind)
		return -EINVAL;
	if (payload >> 8)
		return -EINVAL;
	if (*ptr_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*ptr_reg))
		return -EINVAL;

	return 0;
}

static int instantiate_prefetch(u64 payload, struct bpf_insn *insn_buf)
{
	u8 ptr_reg;
	int err;

	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static void emit_prefetch_mem(u8 *buf, u32 *len, u8 base_reg, u8 hint_reg)
{
	u8 rm = kinsn_x86_reg_code(base_reg);

	kinsn_emit_rex(buf, len, false, false, false, kinsn_x86_ext(base_reg));
	kinsn_emit_u8(buf, len, 0x0F);
	kinsn_emit_u8(buf, len, 0x18);

	if (rm == 4) {
		kinsn_emit_u8(buf, len, (hint_reg << 3) | 0x04);
		kinsn_emit_u8(buf, len, 0x24);
		return;
	}

	if (rm == 5) {
		kinsn_emit_u8(buf, len, 0x40 | (hint_reg << 3) | 0x05);
		kinsn_emit_u8(buf, len, 0);
		return;
	}

	kinsn_emit_u8(buf, len, (hint_reg << 3) | rm);
}

static int emit_prefetch_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog,
			     u8 hint_reg)
{
	u8 ptr_reg;
	u8 buf[6];
	u32 len = 0;
	int err;

	(void)prog;

	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	emit_prefetch_mem(buf, &len, ptr_reg, hint_reg);

	return kinsn_emit_finish(image, off, emit, buf, len);
}

static int emit_prefetchnta_x86(u8 *image, u32 *off, bool emit,
				u64 payload, const struct bpf_prog *prog)
{
	return emit_prefetch_x86(image, off, emit, payload, prog, 0);
}

static int emit_prefetcht0_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_prefetch_x86(image, off, emit, payload, prog, 1);
}

static int emit_prefetcht1_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_prefetch_x86(image, off, emit, payload, prog, 2);
}

static int emit_prefetcht2_x86(u8 *image, u32 *off, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	return emit_prefetch_x86(image, off, emit, payload, prog, 3);
}

const struct bpf_kinsn bpf_x86_prefetchnta_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetch,
	.emit_x86 = emit_prefetchnta_x86,
};

const struct bpf_kinsn bpf_x86_prefetcht0_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetch,
	.emit_x86 = emit_prefetcht0_x86,
};

const struct bpf_kinsn bpf_x86_prefetcht1_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetch,
	.emit_x86 = emit_prefetcht1_x86,
};

const struct bpf_kinsn bpf_x86_prefetcht2_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1 + KINSN_X86_SAVE_RESTORE_INSN_CNT,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetch,
	.emit_x86 = emit_prefetcht2_x86,
};

static const struct bpf_kinsn * const bpf_x86_prefetch_kinsn_descs[] = {
	&bpf_x86_prefetchnta_desc,
	&bpf_x86_prefetcht0_desc,
	&bpf_x86_prefetcht1_desc,
	&bpf_x86_prefetcht2_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_x86_prefetch, "BpfReJIT x86 kinsn: PREFETCH",
		       bpf_x86_prefetch_kfunc_ids, bpf_x86_prefetch_kinsn_descs);
