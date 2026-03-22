// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: SPECULATION_BARRIER — speculation barrier for ARM64
 *
 * Registers a kfunc bpf_speculation_barrier(void) with KF_INLINE_EMIT.
 * When inlined by the ARM64 JIT, emits a speculation barrier sequence.
 *
 * Strategy:
 *   - Emit DSB SY + ISB for maximum compatibility across all ARMv8 cores.
 *   - ARMv8.5-SB adds a dedicated SB (Speculation Barrier) instruction,
 *     but DSB SY + ISB provides equivalent speculation serialization on
 *     all ARMv8.0+ implementations.
 *
 * BPF register mapping: irrelevant — no arguments, no return value.
 *
 * Emitted ARM64 sequence (2 instructions, 8 bytes):
 *   DSB SY    — Data Synchronization Barrier (full system)
 *   ISB       — Instruction Synchronization Barrier
 *
 * DSB SY encoding:
 *   1101010100 0 00 011 0011 CRm(1111) 1 opc(00) 11111
 *   = 0xD5033F9F
 *
 * ISB encoding:
 *   1101010100 0 00 011 0011 CRm(1111) 1 opc(10) 11111
 *   = 0xD5033FDF
 */

#include "kinsn_common.h"

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc void bpf_speculation_barrier(void)
{
	/* Fallback: DSB SY + ISB via inline asm when called as a real kfunc. */
	asm volatile("dsb sy\nisb" ::: "memory");
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET(bpf_barrier, bpf_speculation_barrier);

/* ---- ARM64 JIT emit callback ---- */

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
			      const struct bpf_insn *insn,
			      struct bpf_prog *prog)
{
	if (!idx)
		return -EINVAL;

	(void)insn;
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

static struct bpf_kfunc_inline_ops barrier_ops = {
	.emit_arm64 = emit_barrier_arm64,
	.max_emit_bytes = 8,
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_barrier, "bpf_speculation_barrier", &barrier_ops,
		    "BpfReJIT kinsn: SPECULATION_BARRIER (DSB SY + ISB) inline kfunc for ARM64");
