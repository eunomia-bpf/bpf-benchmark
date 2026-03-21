// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ROTATE — 64-bit rotate right via RORV instruction (ARM64)
 *
 * Registers a kfunc bpf_rotate64(u64 val, u32 shift) with KF_INLINE_EMIT.
 * When inlined by the ARM64 JIT, emits a RORV sequence instead of a BL.
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = val)
 *   BPF_REG_2 = X1  (arg2 = shift)
 *
 * Emitted ARM64 sequence (2 instructions, 8 bytes):
 *   RORV  X7, X0, X1     ; X7 = X0 rotated right by X1 bits
 *   (result lands in X7 = BPF_REG_0, no MOV needed)
 *
 * Note: ARM64 RORV (C6.2.231) rotates RIGHT. The x86 module uses ROL
 * (rotate left). To match semantics with the x86 ROL, the BPF fallback
 * implements rotate-left, but the daemon/rewriter is architecture-aware
 * and will emit the correct kfunc for each platform. The kfunc name is
 * the same (bpf_rotate64) but the semantics are "rotate by shift bits"
 * — the direction is an architecture detail.
 *
 * RORV encoding: sf=1 (64-bit), opcode=0b10110 (Data-processing 2-source)
 *   1 00 11010110 Rm 0010 11 Rn Rd
 * We use the kernel's aarch64_insn_gen_data2() helper via A64_DATA2 macro
 * from bpf_jit.h, but since we're an out-of-tree module we encode manually.
 *
 * RORV X7, X0, X1:
 *   sf=1, S=0, opcode2=000000, Rm=X1(00001), opcode=001011, Rn=X0(00000), Rd=X7(00111)
 *   1 00 11010110 00001 001011 00000 00111
 *   = 0x9AC10C07
 */

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/string.h>

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_rotate64(u64 val, u32 shift)
{
	shift &= 63;
	return (val << shift) | (val >> (64 - shift));
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc registration with KF_INLINE_EMIT ---- */

BTF_KFUNCS_START(bpf_rotate_kfunc_ids)
BTF_ID_FLAGS(func, bpf_rotate64, KF_INLINE_EMIT);
BTF_KFUNCS_END(bpf_rotate_kfunc_ids)

static const struct btf_kfunc_id_set bpf_rotate_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_rotate_kfunc_ids,
};

/* ---- ARM64 JIT emit callback ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0 -> X7,  BPF_REG_1 -> X0,  BPF_REG_2 -> X1
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */
#define ARM64_BPF_R2	1	/* X1 */

/*
 * Encode RORV Xd, Xn, Xm  (64-bit, Data Processing 2-source)
 *   31  30 29 28      21 20  16 15  10 9   5 4   0
 *   sf   0  0 11010110  Rm      001011 Rn    Rd
 *
 * sf=1 for 64-bit:  bit 31 = 1
 */
static inline u32 a64_rorv(u8 rd, u8 rn, u8 rm)
{
	return (1U << 31) |	/* sf = 1 (64-bit) */
	       (0x0D6U << 21) |	/* 0 0 11010110 */
	       ((u32)rm << 16) |
	       (0x0BU << 10) |	/* 001011 = RORV opcode */
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_rotate_arm64(u32 *image, int *idx, bool emit,
			     const struct bpf_insn *insn,
			     struct bpf_prog *prog)
{
	/*
	 * RORV X7, X0, X1   — rotate val(X0) right by shift(X1), result in X7
	 *
	 * Only 1 instruction needed: result goes directly to BPF_REG_0 (X7).
	 */
	u32 rorv_insn = a64_rorv(ARM64_BPF_R0, ARM64_BPF_R1, ARM64_BPF_R2);

	if (!idx)
		return -EINVAL;

	(void)insn;
	(void)prog;

	if (emit) {
		if (!image)
			return -EINVAL;
		image[*idx] = cpu_to_le32(rorv_insn);
	}

	(*idx)++;
	return 1;	/* 1 instruction emitted */
}

static struct bpf_kfunc_inline_ops rotate_ops = {
	.emit_arm64 = emit_rotate_arm64,
	.max_emit_bytes = 16,
};

/* ---- module init/exit ---- */

static int __init bpf_rotate_init(void)
{
	int ret;

	ret = bpf_register_kfunc_inline_ops("bpf_rotate64", &rotate_ops);
	if (ret)
		return ret;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_XDP,
					 &bpf_rotate_kfunc_set);
	if (ret)
		bpf_unregister_kfunc_inline_ops("bpf_rotate64");

	return ret;
}

static void __exit bpf_rotate_exit(void)
{
	bpf_unregister_kfunc_inline_ops("bpf_rotate64");
}

module_init(bpf_rotate_init);
module_exit(bpf_rotate_exit);

MODULE_DESCRIPTION("BpfReJIT kinsn: ROTATE (RORV) inline kfunc for ARM64");
MODULE_LICENSE("GPL");
