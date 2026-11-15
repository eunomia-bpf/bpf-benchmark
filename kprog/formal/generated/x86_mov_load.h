/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_MOV_LOAD_H
#define KPROG_FORMAL_GENERATED_X86_MOV_LOAD_H
/*
 * x86-64 `MOV_LOAD` handler-composition contract. The width resolution is
 * closed over the five X86_WIDTH_* codes (including the 0 "absent" code): the
 * write width defaults to 64 bits and the memory width defaults to the write
 * width, so both are total and there is no unsupported arm. The arm table is
 * closed over its five selector facts. Unlike the shared read body the first
 * test is register identity (is the base the stack pointer) rather than a
 * memory tag, the ABI pointer arm is gated on `_MOV_LOAD` and on a 64-bit
 * write width, and every other access takes the ordinary scalar load at the
 * resolved memory width. The contract selects an arm and resolves the two
 * widths; the value transformation (sign extension) and the ABI tag policy
 * stay in X86_SIM_L_EXEC_MOV_LOAD.
 */
#define KPROG_X86_MOV_LOAD_ARM_STACK 0U
#define KPROG_X86_MOV_LOAD_ARM_ABI_PTR 1U
#define KPROG_X86_MOV_LOAD_ARM_ORDINARY 2U

/* The AUX memory-width codes, including the 0 "absent" code. */
#define X86_WIDTH_64 8U
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define KPROG_X86_MOV_LOAD_WIDTH_ABSENT 0U
/*
 * FLAGS_WIDTH is the opcode's FLAGS code, 0 when it carries none; the write
 * width defaults to 64 bits. Test the raw operand before byte capture;
 * a nonzero expression is evaluated again for the captured value.
 * No flags are written.
 */
#define KPROG_X86_MOV_LOAD_WRITE_DECL(NAME, FLAGS_WIDTH) \
    __u8 NAME = (FLAGS_WIDTH) ? (FLAGS_WIDTH) : X86_WIDTH_64
#define KPROG_X86_MOV_LOAD_WRITE_WIDTH_INTO(OUTPUT, FLAGS_WIDTH) \
    do { KPROG_X86_MOV_LOAD_WRITE_DECL(__kprog_x86_ml_write, FLAGS_WIDTH); \
         (OUTPUT)=__kprog_x86_ml_write; } while (0)
#define KPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS_WIDTH) \
    ({ KPROG_X86_MOV_LOAD_WRITE_DECL(__kprog_x86_ml_write, FLAGS_WIDTH); \
       __kprog_x86_ml_write; })
/*
 * AUX is the addressing AUX word; its memory-width field is 0 when the mode
 * carries no width, in which case the write width is used. AUX is evaluated
 * once, before any FLAGS_WIDTH evaluation. A zero field selects the write
 * width's raw test/capture behavior above. No flags are written.
 */
#define KPROG_X86_MOV_LOAD_WRITE_ASSIGN(OUTPUT, FLAGS_WIDTH) \
    OUTPUT = KPROG_X86_MOV_LOAD_WRITE_WIDTH(FLAGS_WIDTH)
/* WRITE selects expression assignment or its standard-C statement form;
 * both use the same write-width declaration and preserve lazy evaluation. */
#define KPROG_X86_MOV_LOAD_MEM_DECL(NAME, FLAGS_WIDTH, AUX, WRITE) \
    __u8 NAME = X86_MEM_AUX_MEM_WIDTH(AUX); \
    if (!NAME) WRITE(NAME, FLAGS_WIDTH)
#define KPROG_X86_MOV_LOAD_MEM_WIDTH_INTO(OUTPUT, FLAGS_WIDTH, AUX) \
    do { KPROG_X86_MOV_LOAD_MEM_DECL(__kprog_x86_ml_mem, FLAGS_WIDTH, AUX, \
             KPROG_X86_MOV_LOAD_WRITE_WIDTH_INTO); \
         (OUTPUT)=__kprog_x86_ml_mem; } while (0)
#define KPROG_X86_MOV_LOAD_MEM_WIDTH(FLAGS_WIDTH, AUX) \
    ({ KPROG_X86_MOV_LOAD_MEM_DECL(__kprog_x86_ml_mem, FLAGS_WIDTH, AUX, \
           KPROG_X86_MOV_LOAD_WRITE_ASSIGN); \
       __kprog_x86_ml_mem; })
/*
 * BASE_IS_RSP is true when the base register is the stack pointer; IS_MOV_LOAD
 * is true only for the plain `_MOV_LOAD` opcode; MEM_WIDTH and WRITE_WIDTH are
 * the two resolved width codes; BASE_TAG is the base register's memory tag.
 * Inputs are evaluated at most once and only when reached by the short
 * circuit. In particular BASE_TAG is not read on a stack or nonpointer arm.
 * No flags are written.
 */
#define KPROG_X86_MOV_LOAD_ARM_DECL(NAME, BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH, WRITE_WIDTH, BASE_TAG) \
		__u8 NAME;                                    \
		if (BASE_IS_RSP)                                            \
			NAME = KPROG_X86_MOV_LOAD_ARM_STACK;  \
		else if ((IS_MOV_LOAD) &&                                   \
			 (MEM_WIDTH) == X86_WIDTH_64 &&                     \
			 (WRITE_WIDTH) == X86_WIDTH_64 &&                   \
			 (BASE_TAG) == X86_SIM_TAG_ABI)                     \
			NAME =                                 \
				KPROG_X86_MOV_LOAD_ARM_ABI_PTR;              \
		else                                                        \
			NAME = KPROG_X86_MOV_LOAD_ARM_ORDINARY
#define KPROG_X86_MOV_LOAD_ARM_INTO(OUTPUT, BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH, WRITE_WIDTH, BASE_TAG) \
    do { KPROG_X86_MOV_LOAD_ARM_DECL(__kprog_x86_ml_arm, BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH, WRITE_WIDTH, BASE_TAG); \
         (OUTPUT)=__kprog_x86_ml_arm; } while (0)
#define KPROG_X86_MOV_LOAD_ARM(BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH, WRITE_WIDTH, BASE_TAG) \
    ({ KPROG_X86_MOV_LOAD_ARM_DECL(__kprog_x86_ml_arm, BASE_IS_RSP, IS_MOV_LOAD, MEM_WIDTH, WRITE_WIDTH, BASE_TAG); \
       __kprog_x86_ml_arm; })
#endif
