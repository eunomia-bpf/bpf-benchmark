// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: SPECULATION_BARRIER - DSB SY + ISB for ARM64
 */

#include "kinsn_common.h"

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_speculation_barrier(void) {}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_barrier_kfunc_ids)
BTF_ID_FLAGS(func, bpf_speculation_barrier)
BTF_KFUNCS_END(bpf_barrier_kfunc_ids)

static int instantiate_barrier(u64 payload, struct bpf_insn *insn_buf)
{
	if (payload)
		return -EINVAL;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

/*
 * DSB SY: Data Synchronization Barrier (full system scope)
 * Encoding: 1101010100 0 00 011 0011 1111 1 00 11111
 *           = 0xD5033F9F
 */
#define A64_DSB_SY	0xD5033F9FU

/*
 * ISB: Instruction Synchronization Barrier
 * Encoding: 1101010100 0 00 011 0011 1111 1 10 11111
 *           = 0xD5033FDF
 */
#define A64_ISB		0xD5033FDFU

static int emit_barrier_arm64(u32 *image, int *idx, bool emit,
			      u64 payload, const struct bpf_prog *prog)
{
	if (!idx)
		return -EINVAL;
	if (payload)
		return -EINVAL;

	(void)prog;

	if (emit) {
		if (!image)
			return -EINVAL;
		image[*idx]     = cpu_to_le32(A64_DSB_SY);
		image[*idx + 1] = cpu_to_le32(A64_ISB);
	}

	*idx += 2;
	return 2;	/* 2 instructions emitted */
}

const struct bpf_kinsn bpf_speculation_barrier_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 8,
	.instantiate_insn = instantiate_barrier,
	.emit_arm64 = emit_barrier_arm64,
};

static const struct bpf_kinsn * const bpf_barrier_kinsn_descs[] = {
	&bpf_speculation_barrier_desc,
};

DEFINE_KINSN_V2_MODULE(bpf_barrier,
		       "BpfReJIT kinsn: SPECULATION_BARRIER (DSB SY + ISB)",
		       bpf_barrier_kfunc_ids, bpf_barrier_kinsn_descs);
