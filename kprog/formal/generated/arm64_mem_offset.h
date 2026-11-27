/* Canonical simulator C; edit directly. Historical origin: generate_arm64_mem_offset_spec.py from arm64_mem_offset_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_MEM_OFFSET_H
#define KPROG_FORMAL_GENERATED_ARM64_MEM_OFFSET_H
/*
 * AArch64 load/store address offset: a pre/post-indexed access contributes no
 * immediate here (its writeback applies it separately), an offset access
 * contributes the immediate, and an indexed access adds the index register.
 * The accumulation is 64-bit two's-complement wrapping, which is the same bit
 * pattern as the C code's signed `__s64` addition.
 */
/*
 * PREPOST and HAS_INDEX are booleans; IMM and INDEX are the 64-bit immediate
 * and (already source-modified) index register value. IMM and INDEX are each
 * evaluated exactly once and no NZCV is written. The result is the raw 64-bit
 * offset; the caller adds it to the base register.
 */
#define KPROG_ARM64_MEM_OFFSET_INTO(OUTPUT, PREPOST, HAS_INDEX, IMM, INDEX)              \
	do { \
		__u64 __kprog_a64_mbo_imm = (IMM); \
		__u64 __kprog_a64_mbo_index = (INDEX); \
		const int __kprog_a64_mbo_prepost = (PREPOST) ? 1 : 0; \
		const int __kprog_a64_mbo_has_index = (HAS_INDEX) ? 1 : 0; \
		__u64 __kprog_a64_mbo_base = \
			__kprog_a64_mbo_prepost ? 0ULL : __kprog_a64_mbo_imm; \
		__u64 __kprog_a64_mbo_result = __kprog_a64_mbo_base; \
 \
		if (__kprog_a64_mbo_has_index) \
			__kprog_a64_mbo_result = __kprog_a64_mbo_base + \
				__kprog_a64_mbo_index; \
		(OUTPUT) = __kprog_a64_mbo_result; \
	} while (0)
#define KPROG_ARM64_MEM_OFFSET(PREPOST, HAS_INDEX, IMM, INDEX) \
    ({ __u64 __kprog_address_result; \
       KPROG_ARM64_MEM_OFFSET_INTO(__kprog_address_result, (PREPOST), (HAS_INDEX), (IMM), (INDEX)); \
       __kprog_address_result; })
#endif
