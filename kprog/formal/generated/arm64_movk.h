/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MOVK_H
#define KPROG_FORMAL_GENERATED_ARM64_MOVK_H
/*
 * AArch64 MOVK inserts the low 16 bits of an immediate at one of the four
 * architectural columns 0, 16, 32 and 48, keeping every other destination bit.
 * The column set is closed, so the macro is total over SHIFT and an out-of-set
 * column reaches the caller-supplied unsupported arm.
 */
#define KPROG_ARM64_MOVK_HANDLED(SHIFT)                                     \
	(((SHIFT) == 0U) || \
	((SHIFT) == 16U) || \
	((SHIFT) == 32U) || \
	((SHIFT) == 48U))
_Static_assert(KPROG_ARM64_MOVK_HANDLED(0U), "arm64 movk column coverage drift");
_Static_assert(KPROG_ARM64_MOVK_HANDLED(16U), "arm64 movk column coverage drift");
_Static_assert(KPROG_ARM64_MOVK_HANDLED(32U), "arm64 movk column coverage drift");
_Static_assert(KPROG_ARM64_MOVK_HANDLED(48U), "arm64 movk column coverage drift");
/*
 * SHIFT is the architectural bit column (0, 16, 32 or 48), which is exactly the
 * value `ARM64_SIM_L_SHIFT(AUX)` returns for `ARM64_AUX_MOVK(S)`. DST and IMM
 * are each evaluated exactly once, and no arm writes NZCV. The result is the
 * raw 64-bit value; the caller applies the destination width.
 */
#define KPROG_ARM64_MOVK_INSERT_DECL(NAME, DST, IMM, SHIFT, UNSUPPORTED) \
		__u64 __kprog_a64_movk_dst = (DST); \
		__u64 __kprog_a64_movk_imm = (IMM); \
		const __u64 __kprog_a64_movk_shift = (SHIFT); \
		__u64 __kprog_a64_movk_mask; \
		__u64 NAME; \
 \
		switch (__kprog_a64_movk_shift) { \
		case 0U: \
			__kprog_a64_movk_mask = 0xffffULL << 0U; \
			break; \
		case 16U: \
			__kprog_a64_movk_mask = 0xffffULL << 16U; \
			break; \
		case 32U: \
			__kprog_a64_movk_mask = 0xffffULL << 32U; \
			break; \
		case 48U: \
			__kprog_a64_movk_mask = 0xffffULL << 48U; \
			break; \
		default: \
			UNSUPPORTED; \
			__kprog_a64_movk_mask = 0; \
			break; \
		} \
		NAME = \
			(__kprog_a64_movk_dst & ~__kprog_a64_movk_mask) | \
			(((__kprog_a64_movk_imm << __kprog_a64_movk_shift) \
			  & __kprog_a64_movk_mask));
#define KPROG_ARM64_MOVK_INSERT_INTO(OUTPUT, DST, IMM, SHIFT, UNSUPPORTED) \
    do { KPROG_ARM64_MOVK_INSERT_DECL(__kprog_a64_movk_result, DST, IMM, SHIFT, UNSUPPORTED); \
         (OUTPUT)=__kprog_a64_movk_result; } while (0)
#define KPROG_ARM64_MOVK_INSERT(DST, IMM, SHIFT, UNSUPPORTED) \
    ({ KPROG_ARM64_MOVK_INSERT_DECL(__kprog_a64_movk_result, DST, IMM, SHIFT, UNSUPPORTED); \
       __kprog_a64_movk_result; })
#endif
