/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_SETCC_MEM_H
#define KPROG_FORMAL_GENERATED_X86_SETCC_MEM_H
/*
 * x86-64 `SETCC_MEM` handler-composition contract. The condition code comes
 * from the AUX source-shift byte, the width is the opcode's constant 8-bit
 * code, and the destination register number drives both the base-pointer test
 * and the arm test. The contract selects these; the condition expression table
 * stays in KPROG_X86_EVAL_CC, the effective address in KPROG_X86_MEM_OFFSET,
 * and the write in KPROG_X86_MEM_STORE.
 */
#define KPROG_X86_SETCC_MEM_NONE_REG 0xffU
#define KPROG_X86_SETCC_MEM_RSP_REG 4U
/* The opcode's constant access width: the 8-bit width code, one byte wide. */
#define KPROG_X86_SETCC_MEM_WIDTH_CODE 1U
_Static_assert(KPROG_X86_SETCC_MEM_NONE_REG == X86_REG_NONE,
	       "x86 setcc_mem null-base register drift");
_Static_assert(KPROG_X86_SETCC_MEM_RSP_REG == X86_RSP,
	       "x86 setcc_mem stack register drift");
_Static_assert(KPROG_X86_SETCC_MEM_WIDTH_CODE == X86_WIDTH_8,
	       "x86 setcc_mem width drift");
_Static_assert(X86_OP_SETCC_MEM == 0x3eU, "x86 setcc_mem opcode drift");
/*
 * AUX is the register AUX word. The condition code is the source-shift byte at
 * bits 24..31, the same field the register forms of the immediate store and
 * load handlers use for their shift amount; the payload byte at bits 0..7
 * names nothing for this opcode.
 */
#define KPROG_X86_SETCC_MEM_CONDITION(AUX) ((__u8)(((AUX) >> 24) & 0xffU))
/* The base-pointer codes. */
#define KPROG_X86_SETCC_MEM_BASE_NULL 0U
#define KPROG_X86_SETCC_MEM_BASE_REGISTER 1U
/*
 * DST is the destination register number. KPROG_X86_SETCC_MEM_BASE_NULL means
 * the handler forms process null as the base pointer and adds the addressing
 * offset to it; the base test is evaluated before the arm test, so a null base
 * is what the arm store then writes through. DST is evaluated once.
 */
#define KPROG_X86_SETCC_MEM_BASE_DECL(NAME, DST) \
    __u8 NAME; \
    if ((DST) == KPROG_X86_SETCC_MEM_NONE_REG) NAME=KPROG_X86_SETCC_MEM_BASE_NULL; \
    else NAME=KPROG_X86_SETCC_MEM_BASE_REGISTER
#define KPROG_X86_SETCC_MEM_BASE_INTO(OUTPUT, DST) \
    do { KPROG_X86_SETCC_MEM_BASE_DECL(__kprog_x86_scm_base, DST); \
         (OUTPUT)=__kprog_x86_scm_base; } while (0)
#define KPROG_X86_SETCC_MEM_BASE(DST) \
    ({ KPROG_X86_SETCC_MEM_BASE_DECL(__kprog_x86_scm_base, DST); \
       __kprog_x86_scm_base; })
/* The arm codes. */
#define KPROG_X86_SETCC_MEM_ARM_STACK 0U
#define KPROG_X86_SETCC_MEM_ARM_MEMORY 1U
/*
 * DST_IS_RSP is true when the destination register number is the stack pointer;
 * a stack-pointer destination writes through the stack helper, every other
 * destination through the ordinary one-byte little-endian store. The null-base
 * register is not the stack pointer, so a null base always takes the memory
 * arm. DST_IS_RSP is evaluated once.
 */
#define KPROG_X86_SETCC_MEM_ARM_DECL(NAME, DST_IS_RSP) \
    __u8 NAME; \
    if (DST_IS_RSP) NAME=KPROG_X86_SETCC_MEM_ARM_STACK; \
    else NAME=KPROG_X86_SETCC_MEM_ARM_MEMORY
#define KPROG_X86_SETCC_MEM_ARM_INTO(OUTPUT, DST_IS_RSP) \
    do { KPROG_X86_SETCC_MEM_ARM_DECL(__kprog_x86_scm_arm, DST_IS_RSP); \
         (OUTPUT)=__kprog_x86_scm_arm; } while (0)
#define KPROG_X86_SETCC_MEM_ARM(DST_IS_RSP) \
    ({ KPROG_X86_SETCC_MEM_ARM_DECL(__kprog_x86_scm_arm, DST_IS_RSP); \
       __kprog_x86_scm_arm; })
#endif
