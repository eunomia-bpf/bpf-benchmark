/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_REDUCTION_H
#define KPROG_FORMAL_GENERATED_ARM64_REDUCTION_H
#if defined(__COMPCERT__)
/* Reuse the existing pure C count, rather than an unsupported frontend builtin.
 * Each caller below supplies one byte; native compilation keeps ctpop. */
#include "x86_popcount.h"
#define KPROG_ARM64_POPCOUNT_BYTE(VALUE) kprog_x86_popcount_value(VALUE)
#else
#define KPROG_ARM64_POPCOUNT_BYTE(VALUE) __builtin_popcountll(VALUE)
#endif
/*
 * The two arms are the AArch64 byte-lane reductions the simulator applies to
 * the vector register: CNT (per-byte popcount) and UADDLV (sum of the eight
 * bytes). The popcount is written out per byte, so the macro calls no
 * hand-written helper. An opcode outside the two reaches the caller-supplied
 * unsupported arm.
 */
_Static_assert(ARM64_OP_CNT == 36U, "arm64 reduction code drift");
_Static_assert(ARM64_OP_UADDLV == 37U, "arm64 reduction code drift");
#define KPROG_ARM64_REDUCTION_HANDLED(OP)                                   \
	(((OP) == ARM64_OP_CNT) || \
	((OP) == ARM64_OP_UADDLV))
_Static_assert(KPROG_ARM64_REDUCTION_HANDLED(ARM64_OP_CNT), "arm64 reduction coverage drift");
_Static_assert(KPROG_ARM64_REDUCTION_HANDLED(ARM64_OP_UADDLV), "arm64 reduction coverage drift");
/*
 * The numeric case labels 36U and 37U track the ARM64_OP_CNT/UADDLV values
 * defined in kprog/arm64/arm64_sim.h. OP is the opcode, VALUE the vector
 * register contents. VALUE is evaluated exactly once and no arm writes NZCV.
 * The result is the raw 64-bit value; the caller stores it back into v0.
 */
#define KPROG_ARM64_REDUCTION_VALUE_DECL(NAME, OP, VALUE, UNSUPPORTED) \
		const __u64 __kprog_a64_red_op = (OP); \
		__u64 __kprog_a64_red_value = (VALUE); \
		__u64 __kprog_a64_red_out = 0; \
		__u64 NAME = 0; \
 \
		switch (__kprog_a64_red_op) { \
		case 36U: \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 0) & 0xffULL) << 0; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 8) & 0xffULL) << 8; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 16) & 0xffULL) << 16; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 24) & 0xffULL) << 24; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 32) & 0xffULL) << 32; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 40) & 0xffULL) << 40; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 48) & 0xffULL) << 48; \
			__kprog_a64_red_out |= (__u64)KPROG_ARM64_POPCOUNT_BYTE((__kprog_a64_red_value >> 56) & 0xffULL) << 56; \
			NAME = __kprog_a64_red_out; \
			__kprog_a64_red_out = 0; \
			break; \
		case 37U: \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 0) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 8) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 16) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 24) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 32) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 40) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 48) & 0xffULL; \
			__kprog_a64_red_out += (__kprog_a64_red_value >> 56) & 0xffULL; \
			NAME = __kprog_a64_red_out; \
			__kprog_a64_red_out = 0; \
			break; \
		default: \
			UNSUPPORTED; \
			break; \
		}
#define KPROG_ARM64_REDUCTION_VALUE_INTO(OUTPUT, OP, VALUE, UNSUPPORTED) \
    do { KPROG_ARM64_REDUCTION_VALUE_DECL(__kprog_a64_red_result, OP, VALUE, UNSUPPORTED); \
         (OUTPUT)=__kprog_a64_red_result; } while (0)
#define KPROG_ARM64_REDUCTION_VALUE(OP, VALUE, UNSUPPORTED) \
    ({ KPROG_ARM64_REDUCTION_VALUE_DECL(__kprog_a64_red_result, OP, VALUE, UNSUPPORTED); \
       __kprog_a64_red_result; })
#endif
