/* Canonical simulator C; edited directly (formal/README.md, M4). */
#ifndef KPROG_FORMAL_GENERATED_ARM64_STLXR_H
#define KPROG_FORMAL_GENERATED_ARM64_STLXR_H
/*
 * Encode the explicitly supplied Boolean failure outcome as architectural
 * zero/one status. The caller obtains this outcome from the bound environment
 * and performs a memory write only for success. Unknown opcodes reach the
 * caller-supplied unsupported arm.
 */
#include "arm64_width.h"
_Static_assert(ARM64_OP_STLXR == 56U, "arm64 stlxr code drift");
#define KPROG_ARM64_STLXR_HANDLED(OP)                                       \
	(((OP) == ARM64_OP_STLXR))
_Static_assert(KPROG_ARM64_STLXR_HANDLED(ARM64_OP_STLXR), "arm64 stlxr coverage drift");
/*
 * The numeric case label 56U tracks the ARM64_OP_STLXR value defined in
 * kprog/arm64/arm64_sim.h. OP is the opcode and WIDTH the destination
 * width code; FAILURE is a Boolean environment outcome. Each argument is read
 * once and no arm writes NZCV. The caller writes the result back at 32 bits.
 */
#define KPROG_ARM64_STLXR_VALUE_INTO(OUTPUT, OP, WIDTH, FAILURE, UNSUPPORTED)            \
	do { \
		const __u64 __kprog_a64_stlxr_op = (OP); \
		const __u64 __kprog_a64_stlxr_width = (WIDTH); \
		__u64 __kprog_a64_stlxr_failure = !!(FAILURE); \
		__u64 __kprog_a64_stlxr_wmask = KPROG_ARM64_WIDTH_MASK(__kprog_a64_stlxr_width); \
		__u64 __kprog_a64_stlxr_result = 0; \
 \
		switch (__kprog_a64_stlxr_op) { \
		case 56U:                           \
			__kprog_a64_stlxr_result = __kprog_a64_stlxr_failure & __kprog_a64_stlxr_wmask; \
			break; \
		default: \
			UNSUPPORTED; \
			break; \
		} \
		(OUTPUT) = __kprog_a64_stlxr_result; \
	} while (0)
#define KPROG_ARM64_STLXR_VALUE(OP, WIDTH, FAILURE, UNSUPPORTED) \
    ({ __u64 __kprog_stlxr_result; \
       KPROG_ARM64_STLXR_VALUE_INTO(__kprog_stlxr_result, (OP), (WIDTH), (FAILURE), UNSUPPORTED); \
       __kprog_stlxr_result; })
#endif
