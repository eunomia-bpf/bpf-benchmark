// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ENDIAN_LOAD — fused load-and-byte-swap via REV (ARM64)
 *
 * Registers three kfuncs with KF_INLINE_EMIT:
 *   bpf_endian_load16(void *addr) -> u64  (16-bit load + bswap)
 *   bpf_endian_load32(void *addr) -> u64  (32-bit load + bswap)
 *   bpf_endian_load64(void *addr) -> u64  (64-bit load + bswap)
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = addr)
 *
 * Emitted ARM64 sequences:
 *   bpf_endian_load16: LDRH W7, [X0]  +  REV16 W7, W7  +  AND X7, X7, #0xFFFF
 *   bpf_endian_load32: LDR  W7, [X0]  +  REV   W7, W7
 *   bpf_endian_load64: LDR  X7, [X0]  +  REV   X7, X7
 */

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/string.h>

/* ---- kfunc fallback implementations ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_endian_load16(u64 addr)
{
	u16 val = *(const u16 *)(unsigned long)addr;
	return __builtin_bswap16(val);
}

__bpf_kfunc u64 bpf_endian_load32(u64 addr)
{
	u32 val = *(const u32 *)(unsigned long)addr;
	return __builtin_bswap32(val);
}

__bpf_kfunc u64 bpf_endian_load64(u64 addr)
{
	u64 val = *(const u64 *)(unsigned long)addr;
	return __builtin_bswap64(val);
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc registration with KF_INLINE_EMIT ---- */

BTF_KFUNCS_START(bpf_endian_kfunc_ids)
BTF_ID_FLAGS(func, bpf_endian_load16, KF_INLINE_EMIT);
BTF_ID_FLAGS(func, bpf_endian_load32, KF_INLINE_EMIT);
BTF_ID_FLAGS(func, bpf_endian_load64, KF_INLINE_EMIT);
BTF_KFUNCS_END(bpf_endian_kfunc_ids)

static const struct btf_kfunc_id_set bpf_endian_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_endian_kfunc_ids,
};

/* ---- ARM64 JIT emit callbacks ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0  -> X7   (return value)
 *   BPF_REG_1  -> X0   (arg1 = addr)
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */

/*
 * LDRH Wt, [Xn]  (Load Register Halfword, unsigned offset=0)
 *   01 111 0 01 01 imm12(0) Rn Rt
 *   = 0x79400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldrh(u8 rt, u8 rn)
{
	return 0x79400000U | ((u32)rn << 5) | (u32)rt;
}

/*
 * LDR Wt, [Xn]  (Load Register 32-bit, unsigned offset=0)
 *   10 111 0 01 01 imm12(0) Rn Rt
 *   = 0xB9400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldr_w(u8 rt, u8 rn)
{
	return 0xB9400000U | ((u32)rn << 5) | (u32)rt;
}

/*
 * LDR Xt, [Xn]  (Load Register 64-bit, unsigned offset=0)
 *   11 111 0 01 01 imm12(0) Rn Rt
 *   = 0xF9400000 | (Rn << 5) | Rt
 */
static inline u32 a64_ldr_x(u8 rt, u8 rn)
{
	return 0xF9400000U | ((u32)rn << 5) | (u32)rt;
}

/*
 * REV16 Wt, Wn  (Reverse bytes in 16-bit halfwords, 32-bit)
 *   0 1 01 1010 11 00000 00001 0 Rn Rd
 *   = 0x5AC00400 | (Rn << 5) | Rd
 */
static inline u32 a64_rev16_w(u8 rd, u8 rn)
{
	return 0x5AC00400U | ((u32)rn << 5) | (u32)rd;
}

/*
 * REV Wt, Wn  (Reverse bytes in 32-bit word)
 *   0 1 01 1010 11 00000 00010 0 Rn Rd
 *   = 0x5AC00800 | (Rn << 5) | Rd
 */
static inline u32 a64_rev_w(u8 rd, u8 rn)
{
	return 0x5AC00800U | ((u32)rn << 5) | (u32)rd;
}

/*
 * REV Xt, Xn  (Reverse bytes in 64-bit doubleword)
 *   1 1 01 1010 11 00000 00011 0 Rn Rd
 *   = 0xDAC00C00 | (Rn << 5) | Rd
 */
static inline u32 a64_rev_x(u8 rd, u8 rn)
{
	return 0xDAC00C00U | ((u32)rn << 5) | (u32)rd;
}

/*
 * AND Xt, Xn, #imm  (Logical immediate, 64-bit)
 * For #0xFFFF (16 bits set from bit 0):
 *   N=0, immr=0, imms=001111 (0xF)
 *   1 00 100100 N(0) immr(000000) imms(001111) Rn Rd
 *   = 0x92400000 | (0xF << 10) | (Rn << 5) | Rd
 */
static inline u32 a64_and_imm_0xffff(u8 rd, u8 rn)
{
	return 0x92400000U | (0xFU << 10) | ((u32)rn << 5) | (u32)rd;
}

/*
 * bpf_endian_load16: LDRH W7, [X0] + REV16 W7, W7 + AND X7, X7, #0xFFFF
 * 3 instructions, 12 bytes.
 * REV16 swaps bytes within each halfword of a 32-bit register, so bits
 * 31:16 may be non-zero garbage; AND clears them for a clean u16 result.
 */
static int emit_endian_load16_arm64(u32 *image, int *idx, bool emit,
				     const struct bpf_insn *insn,
				     struct bpf_prog *prog)
{
	u32 insns[3];

	if (!idx)
		return -EINVAL;

	(void)insn;
	(void)prog;

	insns[0] = a64_ldrh(ARM64_BPF_R0, ARM64_BPF_R1);
	insns[1] = a64_rev16_w(ARM64_BPF_R0, ARM64_BPF_R0);
	insns[2] = a64_and_imm_0xffff(ARM64_BPF_R0, ARM64_BPF_R0);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 3; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 3;
	return 3;
}

/*
 * bpf_endian_load32: LDR W7, [X0] + REV W7, W7
 * 2 instructions, 8 bytes.
 * 32-bit LDR zero-extends to 64-bit, and REV on W-register also
 * zero-extends, so the result is a clean u32 in X7.
 */
static int emit_endian_load32_arm64(u32 *image, int *idx, bool emit,
				     const struct bpf_insn *insn,
				     struct bpf_prog *prog)
{
	u32 insns[2];

	if (!idx)
		return -EINVAL;

	(void)insn;
	(void)prog;

	insns[0] = a64_ldr_w(ARM64_BPF_R0, ARM64_BPF_R1);
	insns[1] = a64_rev_w(ARM64_BPF_R0, ARM64_BPF_R0);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 2; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 2;
	return 2;
}

/*
 * bpf_endian_load64: LDR X7, [X0] + REV X7, X7
 * 2 instructions, 8 bytes.
 */
static int emit_endian_load64_arm64(u32 *image, int *idx, bool emit,
				     const struct bpf_insn *insn,
				     struct bpf_prog *prog)
{
	u32 insns[2];

	if (!idx)
		return -EINVAL;

	(void)insn;
	(void)prog;

	insns[0] = a64_ldr_x(ARM64_BPF_R0, ARM64_BPF_R1);
	insns[1] = a64_rev_x(ARM64_BPF_R0, ARM64_BPF_R0);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 2; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 2;
	return 2;
}

static struct bpf_kfunc_inline_ops endian_load16_ops = {
	.emit_arm64 = emit_endian_load16_arm64,
	.max_emit_bytes = 16,
};

static struct bpf_kfunc_inline_ops endian_load32_ops = {
	.emit_arm64 = emit_endian_load32_arm64,
	.max_emit_bytes = 16,
};

static struct bpf_kfunc_inline_ops endian_load64_ops = {
	.emit_arm64 = emit_endian_load64_arm64,
	.max_emit_bytes = 16,
};

/* ---- module init/exit ---- */

static int __init bpf_endian_init(void)
{
	int ret;

	ret = bpf_register_kfunc_inline_ops("bpf_endian_load16",
					      &endian_load16_ops);
	if (ret)
		return ret;

	ret = bpf_register_kfunc_inline_ops("bpf_endian_load32",
					      &endian_load32_ops);
	if (ret)
		goto err_unreg16;

	ret = bpf_register_kfunc_inline_ops("bpf_endian_load64",
					      &endian_load64_ops);
	if (ret)
		goto err_unreg32;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
					 &bpf_endian_kfunc_set);
	if (ret)
		goto err_unreg64;

	return 0;

err_unreg64:
	bpf_unregister_kfunc_inline_ops("bpf_endian_load64");
err_unreg32:
	bpf_unregister_kfunc_inline_ops("bpf_endian_load32");
err_unreg16:
	bpf_unregister_kfunc_inline_ops("bpf_endian_load16");
	return ret;
}

static void __exit bpf_endian_exit(void)
{
	bpf_unregister_kfunc_inline_ops("bpf_endian_load64");
	bpf_unregister_kfunc_inline_ops("bpf_endian_load32");
	bpf_unregister_kfunc_inline_ops("bpf_endian_load16");
}

module_init(bpf_endian_init);
module_exit(bpf_endian_exit);

MODULE_DESCRIPTION("BpfReJIT kinsn: ENDIAN_LOAD (REV) inline kfunc for ARM64");
MODULE_LICENSE("GPL");
