// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: SPECULATION_BARRIER — LFENCE instruction for Spectre v1
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_speculation_barrier(void) {}
__bpf_kfunc_end_defs();

static int instantiate_barrier(u64 payload, struct bpf_insn *insn_buf)
{
	if (payload)
		return -EINVAL;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int emit_barrier_x86(u8 *image, u32 *off, bool emit,
			    u64 payload, const struct bpf_prog *prog)
{
	static const u8 insns[] = {
		0x0F, 0xAE, 0xE8,
	};

	(void)prog;

	if (payload)
		return -EINVAL;
	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));
	*off += sizeof(insns);
	return sizeof(insns);
}

const struct bpf_kinsn bpf_speculation_barrier_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_barrier,
	.emit_x86 = emit_barrier_x86,
};

DEFINE_KINSN_V2_MODULE(bpf_barrier,
		       "BpfReJIT kinsn: SPECULATION_BARRIER (LFENCE)");
