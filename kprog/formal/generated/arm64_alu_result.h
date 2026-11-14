/* Canonical simulator C; edited directly (formal/README.md, M4). */
#ifndef KPROG_FORMAL_GENERATED_ARM64_ALU_RESULT_H
#define KPROG_FORMAL_GENERATED_ARM64_ALU_RESULT_H
/*
 * The numeric case labels 0U..5U track the ARM64_ALU_* values defined in
 * generated/arm64_decode.h. This header intentionally does not include
 * arm64_decode.h, so it stays usable standalone; load() re-checks the codes
 * against arm64_decode_spec.json and exits 1 if they drift.
 */
#define KPROG_ALU64_RESULT_INTO(OUTPUT, OP, LHS, RHS, UNSUPPORTED) \
	do { \
		__u64 __kprog_alu64_res = 0; \
		switch (OP) { \
		case 0U:                           \
			__kprog_alu64_res = (LHS) + (RHS); \
			break; \
		case 1U:                           \
			__kprog_alu64_res = (LHS) - (RHS); \
			break; \
		case 2U:                           \
			__kprog_alu64_res = (LHS) & (RHS); \
			break; \
		case 3U:                           \
			__kprog_alu64_res = (LHS) & ~(RHS); \
			break; \
		case 4U:                           \
			__kprog_alu64_res = (LHS) ^ (RHS); \
			break; \
		case 5U:                           \
			__kprog_alu64_res = (LHS) | (RHS); \
			break; \
		default: \
			UNSUPPORTED; \
			break; \
		} \
		(OUTPUT) = __kprog_alu64_res; \
	} while (0)

#define KPROG_ALU64_RESULT(OP, LHS, RHS, UNSUPPORTED) \
	({ __u64 __kprog_alu64_res_out; \
	   KPROG_ALU64_RESULT_INTO(__kprog_alu64_res_out, OP, LHS, RHS, UNSUPPORTED); \
	   __kprog_alu64_res_out; })
#endif
