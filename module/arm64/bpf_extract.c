// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: BITFIELD_EXTRACT — bit-field extraction via UBFX (ARM64)
 *
 * Registers a kfunc bpf_extract64(u64 val, u32 start, u32 len) with
 * KF_INLINE_EMIT.  Extracts bits [start, start+len) from val.
 *
 * BPF register -> ARM64 register mapping (from bpf_jit_comp.c bpf2a64[]):
 *   BPF_REG_0 = X7  (return value)
 *   BPF_REG_1 = X0  (arg1 = val)
 *   BPF_REG_2 = X1  (arg2 = start)
 *   BPF_REG_3 = X2  (arg3 = len)
 *
 * ARM64 has UBFX Xd, Xn, #lsb, #width which extracts a bitfield using
 * immediate operands.  However, start and len come in registers at JIT
 * time (they are BPF program values, not compile-time constants), so we
 * cannot use UBFX directly.
 *
 * Instead we use a LSR + AND mask sequence via variable-shift instructions:
 *   LSR   X7, X0, X1     ; X7 = val >> start  (logical shift right)
 *   MOV   X10, #1         ; tmp = 1 (use TMP_REG_1 = X10)
 *   LSL   X10, X10, X2   ; tmp = 1 << len
 *   SUB   X10, X10, #1   ; tmp = (1 << len) - 1  (mask)
 *   AND   X7, X7, X10    ; X7 = (val >> start) & mask
 *
 * 5 instructions, 20 bytes.
 */

#include "kinsn_common.h"

/* ---- kfunc fallback implementation ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_extract64(u64 val, u32 start, u32 len)
{
	if (start >= 64 || len == 0 || len > 64)
		return 0;
	if (start + len > 64)
		len = 64 - start;
	return (val >> start) & (len >= 64 ? ~0ULL : (1ULL << len) - 1);
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET(bpf_extract, bpf_extract64)

/* ---- ARM64 JIT emit callback ---- */

/*
 * ARM64 register IDs matching bpf2a64[] in bpf_jit_comp.c:
 *   BPF_REG_0  -> X7   (return value)
 *   BPF_REG_1  -> X0   (arg1 = val)
 *   BPF_REG_2  -> X1   (arg2 = start)
 *   BPF_REG_3  -> X2   (arg3 = len)
 *   TMP_REG_1  -> X10  (scratch)
 */
#define ARM64_BPF_R0	7	/* X7 */
#define ARM64_BPF_R1	0	/* X0 */
#define ARM64_BPF_R2	1	/* X1 */
#define ARM64_BPF_R3	2	/* X2 */
#define ARM64_TMP	10	/* X10, TMP_REG_1 */

/*
 * LSRV Xd, Xn, Xm  (64-bit logical shift right variable)
 *   1 00 11010110 Rm 001001 Rn Rd
 */
static inline u32 a64_lsrv(u8 rd, u8 rn, u8 rm)
{
	return (1U << 31) |		/* sf=1 */
	       (0x0D6U << 21) |	/* 00 11010110 */
	       ((u32)rm << 16) |
	       (0x09U << 10) |		/* 001001 */
	       ((u32)rn << 5) |
	       (u32)rd;
}

/*
 * LSLV Xd, Xn, Xm  (64-bit logical shift left variable)
 *   1 00 11010110 Rm 001000 Rn Rd
 */
static inline u32 a64_lslv(u8 rd, u8 rn, u8 rm)
{
	return (1U << 31) |		/* sf=1 */
	       (0x0D6U << 21) |	/* 00 11010110 */
	       ((u32)rm << 16) |
	       (0x08U << 10) |		/* 001000 */
	       ((u32)rn << 5) |
	       (u32)rd;
}

/*
 * MOVZ Xd, #imm16, LSL#0  (64-bit)
 *   1 10 100101 00 imm16 Rd
 */
static inline u32 a64_movz(u8 rd, u16 imm16)
{
	return (0xD2800000U) |		/* 1 10 100101 00 ... */
	       ((u32)imm16 << 5) |
	       (u32)rd;
}

/*
 * SUB Xd, Xn, #imm12  (64-bit, immediate)
 *   1 1 0 10001 0 0 imm12 Rn Rd
 */
static inline u32 a64_sub_i(u8 rd, u8 rn, u16 imm12)
{
	return (0xD1000000U) |		/* 1 1 0 10001 0 0 ... */
	       ((u32)(imm12 & 0xFFF) << 10) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

/*
 * AND Xd, Xn, Xm  (64-bit, logical shifted register, shift=LSL #0)
 *   1 00 01010 00 0 Rm 000000 Rn Rd
 */
static inline u32 a64_and(u8 rd, u8 rn, u8 rm)
{
	return (0x8A000000U) |		/* 1 00 01010 00 0 ... */
	       ((u32)rm << 16) |
	       ((u32)rn << 5) |
	       (u32)rd;
}

static int emit_extract_arm64(u32 *image, int *idx, bool emit,
			      const struct bpf_insn *insn,
			      struct bpf_prog *prog)
{
	/*
	 * LSR  X7, X0, X1     ; val >> start
	 * MOVZ X10, #1        ; tmp = 1
	 * LSL  X10, X10, X2   ; tmp = 1 << len
	 * SUB  X10, X10, #1   ; tmp = mask = (1 << len) - 1
	 * AND  X7, X7, X10    ; result = (val >> start) & mask
	 */
	u32 insns[5];

	if (!idx)
		return -EINVAL;

	(void)insn;
	(void)prog;

	insns[0] = a64_lsrv(ARM64_BPF_R0, ARM64_BPF_R1, ARM64_BPF_R2);
	insns[1] = a64_movz(ARM64_TMP, 1);
	insns[2] = a64_lslv(ARM64_TMP, ARM64_TMP, ARM64_BPF_R3);
	insns[3] = a64_sub_i(ARM64_TMP, ARM64_TMP, 1);
	insns[4] = a64_and(ARM64_BPF_R0, ARM64_BPF_R0, ARM64_TMP);

	if (emit) {
		int i;

		if (!image)
			return -EINVAL;
		for (i = 0; i < 5; i++)
			image[*idx + i] = cpu_to_le32(insns[i]);
	}

	*idx += 5;
	return 5;	/* 5 instructions emitted */
}

static struct bpf_kfunc_inline_ops extract_ops = {
	.emit_arm64 = emit_extract_arm64,
	.max_emit_bytes = 32,	/* 5 insns * 4 bytes = 20, round up */
};

/* ---- module definition ---- */

DEFINE_KINSN_MODULE(bpf_extract, "bpf_extract64", &extract_ops,
		    "BpfReJIT kinsn: BITFIELD_EXTRACT (UBFX/LSR+AND) inline kfunc for ARM64");
