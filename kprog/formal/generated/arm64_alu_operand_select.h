/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_ALU_OPERAND_SELECT_H
#define KPROG_FORMAL_GENERATED_ARM64_ALU_OPERAND_SELECT_H
/* Three immediate labels select IMM; the register label selects its source.
 * The common ALU body retains the operation encoded in AUX.
 */
_Static_assert(ARM64_OP_ADD_IMM == 3U, "arm64 alu operand select code drift");
_Static_assert(ARM64_OP_SUB_IMM == 4U, "arm64 alu operand select code drift");
_Static_assert(ARM64_OP_ALU_IMM == 6U, "arm64 alu operand select code drift");
_Static_assert(ARM64_OP_ALU_REG == 7U, "arm64 alu operand select code drift");
/*
 * OP is the arm opcode. OP is evaluated exactly once. The result is 1 exactly
 * when OP is the immediate case label (the decoded-immediate form) and 0
 * otherwise (the register form).
 */
#define KPROG_ARM64_ALU_OPERAND_SELECT_DECL(NAME, OP) \
		__u8 NAME = 0U; \
 \
		switch (OP) { \
		case 3U: \
			NAME = 1U; \
			break; \
		case 4U: \
			NAME = 1U; \
			break; \
		case 6U: \
			NAME = 1U; \
			break; \
		default: \
			break; \
		}
#define KPROG_ARM64_ALU_OPERAND_SELECT_INTO(OUTPUT, OP) \
    do { KPROG_ARM64_ALU_OPERAND_SELECT_DECL(__kprog_a64_aso_select, OP); \
         (OUTPUT)=__kprog_a64_aso_select; } while (0)
#define KPROG_ARM64_ALU_OPERAND_SELECT(OP) \
    ({ KPROG_ARM64_ALU_OPERAND_SELECT_DECL(__kprog_a64_aso_select, OP); \
       __kprog_a64_aso_select; })
#endif
