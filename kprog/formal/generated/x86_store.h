/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_STORE_H
#define KPROG_FORMAL_GENERATED_X86_STORE_H
/*
 * x86-64 `MOV_STORE` handler-composition contract. The width resolution is
 * closed over the five X86_WIDTH_* codes (including the 0 "absent" code) and
 * yields one width, used for both the immediate value and the memory write; an
 * absent FLAGS code means 64 bits, so the resolution is total and there is no
 * unsupported arm. The displacement form, the value source, and the AUX shift
 * source are all selected by the opcode, and the arm table is closed over the
 * one fact the branch chain consults - whether the destination register is the
 * stack pointer. The contract selects these; the value transformation and the
 * effective address stay in X86_SIM_L_EXEC_STORE.
 */
#define KPROG_X86_STORE_ARM_STACK 0U
#define KPROG_X86_STORE_ARM_MEMORY 1U

/* The FLAGS width codes, including the 0 "absent" code. */
#define X86_WIDTH_64 8U
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define KPROG_X86_STORE_WIDTH_ABSENT 0U
/*
 * FLAGS_WIDTH is the opcode's FLAGS code, 0 when it carries none; the store
 * width then defaults to 64 bits. The same width is used for the immediate
 * value and for the memory write. Test the raw operand first; a nonzero
 * expression is evaluated again for byte capture. No flags are written.
 */
#define KPROG_X86_STORE_WIDTH_DECL(NAME, FLAGS_WIDTH) \
    const __u8 NAME = (FLAGS_WIDTH) ? (FLAGS_WIDTH) : X86_WIDTH_64
#define KPROG_X86_STORE_WIDTH_INTO(OUTPUT, FLAGS_WIDTH) \
    do { KPROG_X86_STORE_WIDTH_DECL(__kprog_x86_st_width, FLAGS_WIDTH); \
         (OUTPUT)=__kprog_x86_st_width; } while (0)
#define KPROG_X86_STORE_WIDTH(FLAGS_WIDTH) \
    ({ KPROG_X86_STORE_WIDTH_DECL(__kprog_x86_st_width, FLAGS_WIDTH); \
       __kprog_x86_st_width; })
/*
 * IS_STORE_IMM is true only for `_MOV_STORE_IMM`; IMM is the instruction
 * immediate artifact field. The immediate store takes its displacement from the
 * artifact's high 32 bits, sign-extended; the register store takes the whole
 * field sign-extended. Each input is evaluated once. No flags are written.
 */
#define KPROG_X86_STORE_DISP_DECL(NAME, IS_STORE_IMM, IMM) \
    __s64 NAME = (IS_STORE_IMM) ? (__s64)(__s32)((IMM) >> 32) : (__s64)(IMM)
#define KPROG_X86_STORE_DISP_INTO(OUTPUT, IS_STORE_IMM, IMM) \
    do { KPROG_X86_STORE_DISP_DECL(__kprog_x86_st_disp, IS_STORE_IMM, IMM); \
         (OUTPUT)=__kprog_x86_st_disp; } while (0)
#define KPROG_X86_STORE_DISP(IS_STORE_IMM, IMM) \
    ({ KPROG_X86_STORE_DISP_DECL(__kprog_x86_st_disp, IS_STORE_IMM, IMM); \
       __kprog_x86_st_disp; })
/*
 * IS_STORE_IMM selects the value's source; WIDTH is the resolved store width.
 * The immediate store takes the width-aware immediate rule, the register store
 * the register read. The unselected source stays unread. The immediate rule
 * reads WIDTH once, and IMM twice when WIDTH is64 (sign test, then value),
 * otherwise IMM once. No flags are written.
 */
#define KPROG_X86_STORE_VALUE_DECL(NAME, IS_STORE_IMM, IMM, WIDTH, SRC_VALUE) \
    __u64 NAME = (IS_STORE_IMM) ? KPROG_X86_IMMEDIATE_VALUE((IMM), (WIDTH)) : (SRC_VALUE)
#define KPROG_X86_STORE_VALUE_INTO(OUTPUT, IS_STORE_IMM, IMM, WIDTH, SRC_VALUE) \
    do { KPROG_X86_STORE_VALUE_DECL(__kprog_x86_st_value, IS_STORE_IMM, IMM, WIDTH, SRC_VALUE); \
         (OUTPUT)=__kprog_x86_st_value; } while (0)
#define KPROG_X86_STORE_VALUE(IS_STORE_IMM, IMM, WIDTH, SRC_VALUE) \
    ({ KPROG_X86_STORE_VALUE_DECL(__kprog_x86_st_value, IS_STORE_IMM, IMM, WIDTH, SRC_VALUE); \
       __kprog_x86_st_value; })
/*
 * IS_STORE_IMM gates the AUX shift: only the register store reads the AUX
 * source-shift field. AUX is the register AUX word. Each input is evaluated
 * once. No flags are written.
 */
#define KPROG_X86_STORE_SRC_SHIFT_DECL(NAME, IS_STORE_IMM, AUX) \
    __u32 NAME = (IS_STORE_IMM) ? 0U : (__u32)X86_REG_AUX_GET_SRC_SHIFT(AUX)
#define KPROG_X86_STORE_SRC_SHIFT_INTO(OUTPUT, IS_STORE_IMM, AUX) \
    do { KPROG_X86_STORE_SRC_SHIFT_DECL(__kprog_x86_st_shift, IS_STORE_IMM, AUX); \
         (OUTPUT)=__kprog_x86_st_shift; } while (0)
#define KPROG_X86_STORE_SRC_SHIFT(IS_STORE_IMM, AUX) \
    ({ KPROG_X86_STORE_SRC_SHIFT_DECL(__kprog_x86_st_shift, IS_STORE_IMM, AUX); \
       __kprog_x86_st_shift; })
/*
 * The stored value is shifted right by the resolved source shift, which is 0
 * unless the register store's AUX shift field is nonzero. VALUE and SHIFT
 * keep C's unspecified operand order; counts at least64 remain undefined
 * as in the original body, with no masking or fallback. No flags are written.
 */
#define KPROG_X86_STORE_SHIFTED_VALUE_DECL(NAME, VALUE, SHIFT) \
    __u64 NAME = (VALUE) >> (SHIFT)
#define KPROG_X86_STORE_SHIFTED_VALUE_INTO(OUTPUT, VALUE, SHIFT) \
    do { KPROG_X86_STORE_SHIFTED_VALUE_DECL(__kprog_x86_st_shifted, VALUE, SHIFT); \
         (OUTPUT)=__kprog_x86_st_shifted; } while (0)
#define KPROG_X86_STORE_SHIFTED_VALUE(VALUE, SHIFT) \
    ({ KPROG_X86_STORE_SHIFTED_VALUE_DECL(__kprog_x86_st_shifted, VALUE, SHIFT); \
       __kprog_x86_st_shifted; })
/*
 * BASE_IS_RSP is true when the destination register is the stack pointer; a
 * stack-pointer destination writes through the stack helper, every other
 * destination through the ordinary little-endian store. Each input is
 * evaluated once. No flags are written.
 */
#define KPROG_X86_STORE_ARM_DECL(NAME, BASE_IS_RSP) \
    const __u8 NAME = (BASE_IS_RSP) ? KPROG_X86_STORE_ARM_STACK : KPROG_X86_STORE_ARM_MEMORY
#define KPROG_X86_STORE_ARM_INTO(OUTPUT, BASE_IS_RSP) \
    do { KPROG_X86_STORE_ARM_DECL(__kprog_x86_st_arm, BASE_IS_RSP); \
         (OUTPUT)=__kprog_x86_st_arm; } while (0)
#define KPROG_X86_STORE_ARM(BASE_IS_RSP) \
    ({ KPROG_X86_STORE_ARM_DECL(__kprog_x86_st_arm, BASE_IS_RSP); \
       __kprog_x86_st_arm; })
#endif
