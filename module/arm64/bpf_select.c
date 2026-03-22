// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: COND_SELECT — branchless conditional select via CSEL (ARM64)
 *
 * Registers a kfunc bpf_select64(u64 a, u64 b, u64 cond) with KF_INLINE_EMIT.
 * Semantics: returns a if cond != 0, otherwise returns b.
 * When inlined by the ARM64 JIT, emits TST + CSEL instead of a BL.
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = a)
 *   BPF_REG_2 = X1  (arg2 = b)
 *   BPF_REG_3 = X2  (arg3 = cond)
 *
 * Emitted ARM64 sequence (2 instructions, 8 bytes):
 *   TST   X2, X2         ; set flags based on cond
 *   CSEL  X7, X0, X1, NE ; X7 = (cond != 0) ? X0(a) : X1(b)
 *
 * TST X2, X2 encoding (ANDS XZR, X2, X2):
 *   1 11 01010 00 0 Rm(00010) 000000 Rn(00010) Rd(11111)
 *   = 0xEA02005F
 *
 * CSEL X7, X0, X1, NE encoding:
 *   sf=1, op=0, S=0, cond=0001(NE), op2=00
 *   1 0 0 11010100 Rm(00001) cond(0001) 0 0 Rn(00000) Rd(00111)
 *   = 0x9A811007
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

/* ---- ARM64 JIT emit callback ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0 -> X7,  BPF_REG_1 -> X0,  BPF_REG_2 -> X1,  BPF_REG_3 -> X2
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */
#define ARM64_BPF_R2	1	/* X1 */
#define ARM64_BPF_R3	2	/* X2 */

/*
 * Encode TST Xn, Xm  (= ANDS XZR, Xn, Xm, 64-bit)
 *   31  30 29 28     24 23 22 21 20   16 15     10 9    5 4    0
 *   sf   1  1 01010   shift  0  Rm       imm6     Rn     Rd(=ZR)
 *   sf=1, opc=11(ANDS), shift=00(LSL), imm6=000000
 */
static inline u32 a64_tst(u8 rn, u8 rm)
{
	return (0xEA000000U) |		/* 1 11 01010 00 0 ... */
	       ((u32)rm << 16) |
	       ((u32)rn << 5) |
	       31U;			/* Rd = XZR = 31 */
}

/*
 * Encode CSEL Xd, Xn, Xm, cond  (64-bit, Conditional Select)
 *   31  30 29 28     21 20   16 15    12 11 10 9    5 4    0
 *   sf   0  0 11010100 Rm      cond      0  0  Rn    Rd
 *   sf=1 for 64-bit
 */
#define COND_NE  0x1

static inline u32 a64_csel(u8 rd, u8 rn, u8 rm, u8 cond)
{
	return (1U << 31) |		/* sf = 1 (64-bit) */
	       (0x1A800000U) |		/* 0 0 11010100 base */
	       ((u32)rm << 16) |
	       ((u32)cond << 12) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_select_arm64(u32 *image, int *idx, bool emit,
			     const struct bpf_insn *insn,
			     struct bpf_prog *prog)
{
	/*
	 * TST   X2, X2          — set flags based on cond
	 * CSEL  X7, X0, X1, NE  — X7 = (cond != 0) ? a : b
	 */
	u32 tst_insn  = a64_tst(ARM64_BPF_R3, ARM64_BPF_R3);
	u32 csel_insn = a64_csel(ARM64_BPF_R0, ARM64_BPF_R1, ARM64_BPF_R2,
				 COND_NE);

	if (!idx)
		return -EINVAL;

	(void)insn;
	(void)prog;

	if (emit) {
		if (!image)
			return -EINVAL;
		image[*idx] = cpu_to_le32(tst_insn);
		image[*idx + 1] = cpu_to_le32(csel_insn);
	}

	*idx += 2;
	return 2;	/* 2 instructions emitted */
}

static struct bpf_kfunc_inline_ops select_ops = {
	.emit_arm64 = emit_select_arm64,
	.max_emit_bytes = 16,
};

/* ---- module init/exit ---- */

static int __init bpf_select_init(void)
{
	int ret;

	ret = bpf_register_kfunc_inline_ops("bpf_select64", &select_ops);
	if (ret)
		return ret;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
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

MODULE_DESCRIPTION("BpfReJIT kinsn: COND_SELECT (CSEL) inline kfunc for ARM64");
MODULE_LICENSE("GPL");
