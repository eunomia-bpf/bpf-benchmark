/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_FLAG_OPERAND_H
#define KPROG_FORMAL_GENERATED_ARM64_FLAG_OPERAND_H
/*
 * The right-hand-operand selection shared by the six AArch64 flag-arm pairs
 * (SUBS/ADDS/CMP/TST/ANDS/CCMP): the `_IMM` member of each pair selects the
 * decoded immediate, every other (register) opcode selects the caller-supplied
 * register expression. The register expression is the caller's, because the
 * arithmetic/logical pairs rewrite it through the source modifier while CCMP
 * reads it directly. A code outside the six `_IMM` labels returns the register
 * expression.
 */
_Static_assert(ARM64_OP_SUBS_IMM == 48U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_SUBS_REG == 50U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_ADDS_IMM == 49U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_ADDS_REG == 66U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_CMP_IMM == 22U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_CMP_REG == 23U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_TST_IMM == 24U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_TST_REG == 25U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_ANDS_IMM == 55U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_ANDS_REG == 45U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_CCMP_IMM == 26U, "arm64 flag operand code drift");
_Static_assert(ARM64_OP_CCMP_REG == 27U, "arm64 flag operand code drift");
/*
 * OP is the arm opcode, IMM the decoded immediate and REG the register-form
 * right-hand expression. REG is evaluated once before OP; IMM is evaluated only
 * for an immediate opcode. The result is IMM for the six immediate case labels,
 * and the captured register expression otherwise.
 */
#define KPROG_ARM64_FLAG_RHS_DECL(NAME, OP, IMM, REG) \
		__u64 NAME = (REG); \
 \
		switch (OP) { \
		case 48U: \
			NAME = (IMM); \
			break; \
		case 49U: \
			NAME = (IMM); \
			break; \
		case 22U: \
			NAME = (IMM); \
			break; \
		case 24U: \
			NAME = (IMM); \
			break; \
		case 55U: \
			NAME = (IMM); \
			break; \
		case 26U: \
			NAME = (IMM); \
			break; \
		default: \
			break; \
		}
#define KPROG_ARM64_FLAG_RHS_INTO(OUTPUT, OP, IMM, REG) \
    do { KPROG_ARM64_FLAG_RHS_DECL(__kprog_a64_fo_rhs, OP, IMM, REG); \
         (OUTPUT)=__kprog_a64_fo_rhs; } while (0)
#define KPROG_ARM64_FLAG_RHS(OP, IMM, REG) \
    ({ KPROG_ARM64_FLAG_RHS_DECL(__kprog_a64_fo_rhs, OP, IMM, REG); \
       __kprog_a64_fo_rhs; })
#endif
