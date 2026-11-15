/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_MEM_DISPATCH_H
#define KPROG_FORMAL_GENERATED_X86_MEM_DISPATCH_H
/*
 * x86-64 memory read-dispatch classification. The three selector facts form a
 * closed table, so the predicate is total and has no unsupported arm. Unlike
 * the AArch64 dispatch, the first test is register identity (is the base the
 * stack pointer) rather than a memory tag; the ABI test follows and is gated on
 * width 64, so an ABI base off width 64 falls through to the ordinary load.
 * `KPROG_X86_MEM_SRC_*` names the value source the read path must use. This
 * contract selects a value source only; the ABI packet tag refinement stays in
 * X86_SIM_L_EXEC_MOV_LOAD.
 */
#define KPROG_X86_MEM_SRC_STACK 0U
#define KPROG_X86_MEM_SRC_ABI_PTR_LOAD 1U
#define KPROG_X86_MEM_SRC_NORMAL_LOAD 2U
/*
 * BASE_IS_RSP is true when the base register is the stack pointer; BASE_TAG is
 * the base register's memory tag; WIDTH is the X86_WIDTH_* effective access
 * code. Inputs are evaluated at most once, in stack/tag/width order and only
 * when reached by the short circuit. No flags are written.
 */
#define KPROG_X86_MEM_READ_SRC_DECL(NAME, BASE_IS_RSP, BASE_TAG, WIDTH) \
		__u8 NAME;                                    \
		if (BASE_IS_RSP)                                            \
			NAME = KPROG_X86_MEM_SRC_STACK;           \
		else if ((BASE_TAG) == X86_SIM_TAG_ABI &&                   \
			 (WIDTH) == X86_WIDTH_64)                             \
			NAME = KPROG_X86_MEM_SRC_ABI_PTR_LOAD;    \
		else                                                        \
			NAME = KPROG_X86_MEM_SRC_NORMAL_LOAD
#define KPROG_X86_MEM_READ_SRC_INTO(OUTPUT, BASE_IS_RSP, BASE_TAG, WIDTH) \
    do { KPROG_X86_MEM_READ_SRC_DECL(__kprog_x86_md_src, BASE_IS_RSP, BASE_TAG, WIDTH); \
         (OUTPUT)=__kprog_x86_md_src; } while (0)
#define KPROG_X86_MEM_READ_SRC(BASE_IS_RSP, BASE_TAG, WIDTH) \
    ({ KPROG_X86_MEM_READ_SRC_DECL(__kprog_x86_md_src, BASE_IS_RSP, BASE_TAG, WIDTH); \
       __kprog_x86_md_src; })
#endif
