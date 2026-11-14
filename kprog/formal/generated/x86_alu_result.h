/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_ALU_RESULT_H
#define KPROG_FORMAL_GENERATED_X86_ALU_RESULT_H
/*
 * The numeric case labels 0U..15U track the X86_ALU_* values defined in
 * generated/x86_alu_decode.h. This header intentionally does not include
 * x86_alu_decode.h, so it stays usable standalone. The shift arms delegate
 * to the shared shift-result helpers and the carry/borrow/not arms to the
 * shared one-step macros. INTO owns the single switch body; the expression
 * facade preserves the existing macro API for its current callers.
 * The result starts at the left operand, so the default arm (every operation
 * code beyond the sixteen case labels) keeps it, and `UNSUPPORTED` is the
 * caller's action at that arm.
 */
#define KPROG_X86_ALU_RESULT_INTO(OUTPUT, LHS, RHS, OP, WIDTH, UNSUPPORTED)              \
	do { \
		__u64 __kprog_x86_alu_res = (LHS); \
		switch ((OP)) { \
		case 0U: \
			__kprog_x86_alu_res = KPROG_X86_ADC_RESULT(LHS, RHS, 0); \
			break; \
		case 1U: \
			__kprog_x86_alu_res = KPROG_X86_SBB_RESULT(LHS, RHS, 0); \
			break; \
		case 2U: \
			__kprog_x86_alu_res = (LHS) ^ (RHS); \
			break; \
		case 3U: \
			__kprog_x86_alu_res = (LHS) | (RHS); \
			break; \
		case 4U: \
			__kprog_x86_alu_res = (LHS) & (RHS); \
			break; \
		case 5U: \
			__kprog_x86_alu_res = kprog_x86_shl_result(LHS, RHS, WIDTH); \
			break; \
		case 6U: \
			__kprog_x86_alu_res = kprog_x86_shr_result(LHS, RHS, WIDTH); \
			break; \
		case 7U: \
			__kprog_x86_alu_res = kprog_x86_sar_result(LHS, RHS, WIDTH); \
			break; \
		case 8U: \
			__kprog_x86_alu_res = kprog_x86_rol_result(LHS, RHS, WIDTH); \
			break; \
		case 9U: \
			__kprog_x86_alu_res = (LHS) * (RHS); \
			break; \
		case 10U: \
			__kprog_x86_alu_res = KPROG_X86_ADC_RESULT(LHS, 1, 0); \
			break; \
		case 11U: \
			__kprog_x86_alu_res = KPROG_X86_NOT_RESULT(LHS); \
			break; \
		case 12U: \
			__kprog_x86_alu_res = KPROG_X86_SBB_RESULT(LHS, RHS, 0); \
			break; \
		case 13U: \
			__kprog_x86_alu_res = KPROG_X86_SBB_RESULT(LHS, 1, 0); \
			break; \
		case 14U: \
			__kprog_x86_alu_res = KPROG_X86_SBB_RESULT(0, LHS, 0); \
			break; \
		case 15U: \
			__kprog_x86_alu_res = KPROG_X86_ADC_RESULT(LHS, RHS, 0); \
			break; \
		default: \
			UNSUPPORTED; \
			break; \
		} \
		(OUTPUT) = __kprog_x86_alu_res; \
	} while (0)

#define KPROG_X86_ALU_RESULT(LHS, RHS, OP, WIDTH, UNSUPPORTED) \
	({ __u64 __kprog_x86_alu_value; \
	   KPROG_X86_ALU_RESULT_INTO(__kprog_x86_alu_value, LHS, RHS, OP, WIDTH, UNSUPPORTED); \
	   __kprog_x86_alu_value; })
#endif
