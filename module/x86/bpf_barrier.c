// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: SPECULATION_BARRIER — LFENCE instruction for Spectre v1
 *
 * Registers a kfunc bpf_speculation_barrier(void) with KF_INLINE_EMIT.
 * When inlined by the x86 JIT, emits an LFENCE instruction instead of a
 * function call. LFENCE is the Intel-recommended Spectre v1 mitigation
 * that serializes speculative execution.
 *
 * Emitted x86-64 sequence (3 bytes):
 *   0F AE E8       lfence
 */

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/string.h>

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc void bpf_speculation_barrier(void)
{
	/* Fallback: actual LFENCE via inline asm when called as a real kfunc. */
	asm volatile("lfence" ::: "memory");
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc registration with KF_INLINE_EMIT ---- */

BTF_KFUNCS_START(bpf_barrier_kfunc_ids)
BTF_ID_FLAGS(func, bpf_speculation_barrier, KF_INLINE_EMIT);
BTF_KFUNCS_END(bpf_barrier_kfunc_ids)

static const struct btf_kfunc_id_set bpf_barrier_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_barrier_kfunc_ids,
};

/* ---- x86 JIT emit callback ---- */

static int emit_barrier_x86(u8 *image, u32 *off, bool emit,
			     const struct bpf_insn *insn,
			     struct bpf_prog *prog)
{
	/*
	 * LFENCE: 0F AE E8 (3 bytes)
	 *
	 * Intel SDM Vol. 3A, Section 15.5.5: LFENCE serializes instruction
	 * execution, preventing speculative loads from executing past this
	 * point. This is the recommended Spectre v1 mitigation.
	 */
	static const u8 insns[] = {
		0x0F, 0xAE, 0xE8,	/* lfence */
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)insn;
	(void)prog;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));

	*off += sizeof(insns);
	return sizeof(insns);
}

static struct bpf_kfunc_inline_ops barrier_ops = {
	.emit_x86 = emit_barrier_x86,
	.max_emit_bytes = 4,
};

/* ---- module init/exit ---- */

static int __init bpf_barrier_init(void)
{
	int ret;

	ret = bpf_register_kfunc_inline_ops("bpf_speculation_barrier",
					     &barrier_ops);
	if (ret)
		return ret;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
					 &bpf_barrier_kfunc_set);
	if (ret)
		bpf_unregister_kfunc_inline_ops("bpf_speculation_barrier");

	return ret;
}

static void __exit bpf_barrier_exit(void)
{
	bpf_unregister_kfunc_inline_ops("bpf_speculation_barrier");
}

module_init(bpf_barrier_init);
module_exit(bpf_barrier_exit);

MODULE_DESCRIPTION("BpfReJIT kinsn: SPECULATION_BARRIER (LFENCE) inline kfunc");
MODULE_LICENSE("GPL");
