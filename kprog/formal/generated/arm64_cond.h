/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_COND_H
#define KPROG_FORMAL_GENERATED_ARM64_COND_H

_Static_assert(ARM64_COND_EQ == 0U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_NE == 1U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_CS == 2U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_CC == 3U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_MI == 4U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_PL == 5U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_VS == 6U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_VC == 7U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_HI == 8U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_LS == 9U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_GE == 10U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_LT == 11U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_GT == 12U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_LE == 13U, "AArch64 condition code drift");
_Static_assert(ARM64_COND_AL == 14U, "AArch64 condition code drift");

#define KPROG_ARM64_EVAL_COND_DECL(NAME, COND, N, Z, C, V, UNSUPPORTED) \
    int NAME; \
    if ((COND) == ARM64_COND_EQ) NAME=(Z); \
    else if ((COND) == ARM64_COND_NE) NAME=(!(Z)); \
    else if ((COND) == ARM64_COND_CS) NAME=(C); \
    else if ((COND) == ARM64_COND_CC) NAME=(!(C)); \
    else if ((COND) == ARM64_COND_MI) NAME=(N); \
    else if ((COND) == ARM64_COND_PL) NAME=(!(N)); \
    else if ((COND) == ARM64_COND_VS) NAME=(V); \
    else if ((COND) == ARM64_COND_VC) NAME=(!(V)); \
    else if ((COND) == ARM64_COND_HI) NAME=((C) && (!(Z))); \
    else if ((COND) == ARM64_COND_LS) NAME=((!(C)) || (Z)); \
    else if ((COND) == ARM64_COND_GE) NAME=((N) == (V)); \
    else if ((COND) == ARM64_COND_LT) NAME=((N) != (V)); \
    else if ((COND) == ARM64_COND_GT) NAME=((!(Z)) && ((N) == (V))); \
    else if ((COND) == ARM64_COND_LE) NAME=((Z) || ((N) != (V))); \
    else if ((COND) == ARM64_COND_AL) NAME=1; \
    else { UNSUPPORTED; NAME=0; }
#define KPROG_ARM64_EVAL_COND_INTO(OUTPUT, COND, N, Z, C, V, UNSUPPORTED) \
    do { KPROG_ARM64_EVAL_COND_DECL(__kprog_a64_cond, COND, N, Z, C, V, UNSUPPORTED); \
         (OUTPUT)=__kprog_a64_cond; } while (0)
#define KPROG_ARM64_EVAL_COND(COND, N, Z, C, V, UNSUPPORTED) \
    ({ KPROG_ARM64_EVAL_COND_DECL(__kprog_a64_cond, COND, N, Z, C, V, UNSUPPORTED); \
       __kprog_a64_cond; })

#endif
