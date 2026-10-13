/*
 * Host cross-check for the x86-64 ALU-token flag-body-selection contract
 * (STEP 0147).
 *
 * The module under test is `generated/x86_alu_flag_arm.h`. It fixes the
 * flag-setting body the simulator's `X86_SIM_L_SET_ALU_FLAGS` macro selects
 * from an `X86_ALU_*` operation token: the sum body at ADD/ADC, the increment
 * body at INC, the decrement body at DEC, the difference body at SUB, the
 * borrow-difference body at SBB, the negation body at NEG, the no-op body at
 * NOT, the shift body at SHL/SHR/SAR/ROL, the multiply body at IMUL, and the
 * bitwise body at every other token (the XOR/OR/AND default), so the ladder is
 * total. The simulator used to write that ladder by hand as a chain of
 * `if ((ALU) == X86_ALU_*)`, and this oracle drives the contract's
 * `KPROG_X86_ALU_FLAG_ARM` / `..._COUNT` / `..._ARM_*` and restates the
 * selection from the raw tokens. The two must agree on every token the
 * selector can see; the generated `_Static_assert`s additionally pin the
 * hand-written `X86_ALU_*` decodes to the generated table at compile time.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_alu_flag_arm_host.c -o /tmp/t_afa
 *   /tmp/t_afa
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. The ALU tokens
 * have the same values the simulator decodes. */
#define X86_ALU_ADD 0U
#define X86_ALU_SUB 1U
#define X86_ALU_XOR 2U
#define X86_ALU_OR 3U
#define X86_ALU_AND 4U
#define X86_ALU_SHL 5U
#define X86_ALU_SHR 6U
#define X86_ALU_SAR 7U
#define X86_ALU_ROL 8U
#define X86_ALU_IMUL 9U
#define X86_ALU_INC 10U
#define X86_ALU_NOT 11U
#define X86_ALU_SBB 12U
#define X86_ALU_DEC 13U
#define X86_ALU_NEG 14U
#define X86_ALU_ADC 15U

#include "generated/x86_alu_flag_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent arm codes, restated as literals so the model is independent
 * of the generated `.._ARM_*` values. */
#define MODEL_ADD 0
#define MODEL_INC 1
#define MODEL_DEC 2
#define MODEL_SUB 3
#define MODEL_SBB 4
#define MODEL_NEG 5
#define MODEL_NOT 6
#define MODEL_SHIFT 7
#define MODEL_IMUL 8
#define MODEL_LOGIC 9

/* The independent selection: an `X86_ALU_*` token names the flag body for its
 * own family, the ADD/ADC pair the sum body and the SHL/SHR/SAR/ROL quadruple
 * the shift body, and the bitwise body at every other token (including the
 * absent-style unknown token), so the ladder is total. */
static int model_arm(unsigned alu)
{
	switch (alu) {
	case X86_ALU_ADD:
	case X86_ALU_ADC:
		return MODEL_ADD;
	case X86_ALU_INC:
		return MODEL_INC;
	case X86_ALU_DEC:
		return MODEL_DEC;
	case X86_ALU_SUB:
		return MODEL_SUB;
	case X86_ALU_SBB:
		return MODEL_SBB;
	case X86_ALU_NEG:
		return MODEL_NEG;
	case X86_ALU_NOT:
		return MODEL_NOT;
	case X86_ALU_SHL:
	case X86_ALU_SHR:
	case X86_ALU_SAR:
	case X86_ALU_ROL:
		return MODEL_SHIFT;
	case X86_ALU_IMUL:
		return MODEL_IMUL;
	default:
		return MODEL_LOGIC;
	}
}

int main(void)
{
	unsigned alu;

	cases++;
	if (KPROG_X86_ALU_FLAG_ARM_COUNT != 10U) {
		printf("MISMATCH body count drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_ALU_FLAG_ARM_ADD == KPROG_X86_ALU_FLAG_ARM_INC ||
	    KPROG_X86_ALU_FLAG_ARM_INC == KPROG_X86_ALU_FLAG_ARM_DEC ||
	    KPROG_X86_ALU_FLAG_ARM_DEC == KPROG_X86_ALU_FLAG_ARM_SUB ||
	    KPROG_X86_ALU_FLAG_ARM_SUB == KPROG_X86_ALU_FLAG_ARM_SBB ||
	    KPROG_X86_ALU_FLAG_ARM_SBB == KPROG_X86_ALU_FLAG_ARM_NEG ||
	    KPROG_X86_ALU_FLAG_ARM_NEG == KPROG_X86_ALU_FLAG_ARM_NOT ||
	    KPROG_X86_ALU_FLAG_ARM_NOT == KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM_SHIFT == KPROG_X86_ALU_FLAG_ARM_IMUL ||
	    KPROG_X86_ALU_FLAG_ARM_IMUL == KPROG_X86_ALU_FLAG_ARM_LOGIC ||
	    KPROG_X86_ALU_FLAG_ARM_ADD == KPROG_X86_ALU_FLAG_ARM_LOGIC) {
		printf("MISMATCH body codes not distinct\n");
		failures++;
	}

	/* The selector returns the body the independent model names, over the
	 * whole byte range the ALU token can take. */
	for (alu = 0; alu <= 0xffU; alu++) {
		unsigned got = KPROG_X86_ALU_FLAG_ARM((__u8)alu);
		int want = model_arm(alu);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH arm alu=%u got=%u want=%d\n",
			       alu, got, want);
			failures++;
		}
	}

	/* Each real ALU token reaches its own body, and a token that is none of
	 * the routed families (here the bitwise codes and an unknown token)
	 * reaches the default bitwise body. */
	cases++;
	if (KPROG_X86_ALU_FLAG_ARM(X86_ALU_ADD) != KPROG_X86_ALU_FLAG_ARM_ADD ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_ADC) != KPROG_X86_ALU_FLAG_ARM_ADD ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_INC) != KPROG_X86_ALU_FLAG_ARM_INC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_DEC) != KPROG_X86_ALU_FLAG_ARM_DEC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SUB) != KPROG_X86_ALU_FLAG_ARM_SUB ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SBB) != KPROG_X86_ALU_FLAG_ARM_SBB ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_NEG) != KPROG_X86_ALU_FLAG_ARM_NEG ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_NOT) != KPROG_X86_ALU_FLAG_ARM_NOT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SHL) != KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_ROL) != KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_IMUL) != KPROG_X86_ALU_FLAG_ARM_IMUL ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_XOR) != KPROG_X86_ALU_FLAG_ARM_LOGIC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_OR) != KPROG_X86_ALU_FLAG_ARM_LOGIC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_AND) != KPROG_X86_ALU_FLAG_ARM_LOGIC ||
	    KPROG_X86_ALU_FLAG_ARM(0xffU) != KPROG_X86_ALU_FLAG_ARM_LOGIC) {
		printf("MISMATCH token body drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 alu flag arm host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 alu flag arm host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
