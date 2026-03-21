// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: COND_SELECT — branchless conditional select via CMOV
 *
 * Registers a kfunc bpf_select64(u64 a, u64 b, u64 cond) with KF_INLINE_EMIT.
 * Semantics: returns a if cond != 0, otherwise returns b.
 * When inlined by the x86 JIT, emits a CMOVNZ sequence instead of a branch
 * or function call.
 *
 * BPF register -> x86 register mapping (from bpf_jit_comp.c):
 *   BPF_REG_0 = RAX (return value)
 *   BPF_REG_1 = RDI (arg1 = a)
 *   BPF_REG_2 = RSI (arg2 = b)
 *   BPF_REG_3 = RDX (arg3 = cond)
 *
 * Emitted x86-64 sequence (10 bytes):
 *   48 89 F0          mov rax, rsi        ; result = b (default)
 *   48 85 D2          test rdx, rdx       ; set ZF based on cond
 *   48 0F 45 C7       cmovnz rax, rdi     ; if cond != 0, result = a
 */

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/string.h>

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_select64(u64 a, u64 b, u64 cond)
{
	return cond ? a : b;
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc registration with KF_INLINE_EMIT ---- */

BTF_KFUNCS_START(bpf_select_kfunc_ids)
BTF_ID_FLAGS(func, bpf_select64, KF_INLINE_EMIT);
BTF_KFUNCS_END(bpf_select_kfunc_ids)

static const struct btf_kfunc_id_set bpf_select_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_select_kfunc_ids,
};

/* ---- x86 JIT emit callback ---- */

static int emit_select_x86(u8 *image, u32 *off, bool emit,
			    const struct bpf_insn *insn,
			    struct bpf_prog *prog)
{
	/*
	 * mov  rax, rsi         48 89 F0
	 * test rdx, rdx         48 85 D2
	 * cmovnz rax, rdi       48 0F 45 C7
	 */
	static const u8 insns[] = {
		0x48, 0x89, 0xF0,		/* mov rax, rsi    */
		0x48, 0x85, 0xD2,		/* test rdx, rdx   */
		0x48, 0x0F, 0x45, 0xC7,	/* cmovnz rax, rdi */
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

static struct bpf_kfunc_inline_ops select_ops = {
	.emit_x86 = emit_select_x86,
	.max_emit_bytes = 16,
};

/* ---- module init/exit ---- */

static int __init bpf_select_init(void)
{
	int ret;

	ret = bpf_register_kfunc_inline_ops("bpf_select64", &select_ops);
	if (ret)
		return ret;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_XDP,
					 &bpf_select_kfunc_set);
	if (ret)
		bpf_unregister_kfunc_inline_ops("bpf_select64");

	return ret;
}

static void __exit bpf_select_exit(void)
{
	bpf_unregister_kfunc_inline_ops("bpf_select64");
}

module_init(bpf_select_init);
module_exit(bpf_select_exit);

MODULE_DESCRIPTION("BpfReJIT kinsn: COND_SELECT (CMOV) inline kfunc");
MODULE_LICENSE("GPL");
