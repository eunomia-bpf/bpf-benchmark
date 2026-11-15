/* Canonical simulator C. Edit directly; export the Lean AST with clightgen. */
#ifndef KPROG_FORMAL_GENERATED_X86_SETCC_H
#define KPROG_FORMAL_GENERATED_X86_SETCC_H
_Static_assert(X86_CC_O == 0U, "x86 condition code drift");
_Static_assert(X86_CC_NO == 1U, "x86 condition code drift");
_Static_assert(X86_CC_B == 2U, "x86 condition code drift");
_Static_assert(X86_CC_AE == 3U, "x86 condition code drift");
_Static_assert(X86_CC_E == 4U, "x86 condition code drift");
_Static_assert(X86_CC_NE == 5U, "x86 condition code drift");
_Static_assert(X86_CC_BE == 6U, "x86 condition code drift");
_Static_assert(X86_CC_A == 7U, "x86 condition code drift");
_Static_assert(X86_CC_S == 8U, "x86 condition code drift");
_Static_assert(X86_CC_NS == 9U, "x86 condition code drift");
_Static_assert(X86_CC_L == 12U, "x86 condition code drift");
_Static_assert(X86_CC_GE == 13U, "x86 condition code drift");
_Static_assert(X86_CC_LE == 14U, "x86 condition code drift");
_Static_assert(X86_CC_G == 15U, "x86 condition code drift");
#define KPROG_X86_SETCC_COND_NONE 0xffffU
_Static_assert(KPROG_X86_SETCC_COND_NONE == 0xffffU, "x86 setcc no-match sentinel drift");
/*
 * The raw condition byte is one of the supported `X86_CC_*` codes, or
 * KPROG_X86_SETCC_COND_NONE for a code outside the accepted subset. The fold
 * returns the matched code itself, so it also exposes the completeness of the
 * accepted subset to a caller that wants it. CC is the AUX payload byte.
 */
#define KPROG_X86_SETCC_COND_MATCHED(CC)                                   \
	 (CC) == X86_CC_O ? 0U : \
	 (CC) == X86_CC_NO ? 1U : \
	 (CC) == X86_CC_B ? 2U : \
	 (CC) == X86_CC_AE ? 3U : \
	 (CC) == X86_CC_E ? 4U : \
	 (CC) == X86_CC_NE ? 5U : \
	 (CC) == X86_CC_BE ? 6U : \
	 (CC) == X86_CC_A ? 7U : \
	 (CC) == X86_CC_S ? 8U : \
	 (CC) == X86_CC_NS ? 9U : \
	 (CC) == X86_CC_L ? 12U : \
	 (CC) == X86_CC_GE ? 13U : \
	 (CC) == X86_CC_LE ? 14U : \
	 (CC) == X86_CC_G ? 15U : \
	 KPROG_X86_SETCC_COND_NONE
/* The destination byte-lane codes. */
#define KPROG_X86_SETCC_LANE_LOW 0U
#define KPROG_X86_SETCC_LANE_HIGH 1U
/*
 * DST_SHIFT is the decoded AUX destination shift
 * (`KPROG_X86_REG_LANE_AUX_DST_SHIFT`). The C write helper tests the exact
 * value 8, so only 8 selects the high byte and every other value the low byte.
 */
#define KPROG_X86_SETCC_LANE_DECL(NAME, DST_SHIFT) \
    __u8 NAME; \
    if ((DST_SHIFT) == 8U) NAME=KPROG_X86_SETCC_LANE_HIGH; \
    else NAME=KPROG_X86_SETCC_LANE_LOW
#define KPROG_X86_SETCC_LANE_INTO(OUTPUT, DST_SHIFT) \
    do { KPROG_X86_SETCC_LANE_DECL(__kprog_x86_sc_lane, DST_SHIFT); \
         (OUTPUT)=__kprog_x86_sc_lane; } while (0)
#define KPROG_X86_SETCC_LANE(DST_SHIFT) \
    ({ KPROG_X86_SETCC_LANE_DECL(__kprog_x86_sc_lane, DST_SHIFT); \
       __kprog_x86_sc_lane; })
/*
 * The unsupported raw condition codes, listed so a reader does not have to
 * derive the complement.
 */
#define KPROG_X86_SETCC_UNSUPPORTED_CC_CODES "10, 11"
#endif
