/*
 * Host cross-check for the x86-64 `MULX` width-keyed arm-selection contract
 * (STEP 0130).
 *
 * The module under test is `generated/x86_mulx_arm.h`. It fixes the body the
 * simulator's `X86_SIM_L_EXEC_MULX` macro selects from a *resolved* operand
 * width code: the single 32x32-product split at the 32-bit code (`4`), the
 * four-limb radix-`2^32` ladder at every other code. The simulator writes that
 * selection by hand as `if (__x86_l_width == X86_WIDTH_32)`, and this oracle
 * drives the contract's `KPROG_X86_MULX_ARM` / `KPROG_X86_MULX_ARM_COUNT` /
 * `KPROG_X86_MULX_SPECIAL_WIDTH` and restates the selection from the raw width
 * codes. The two must agree on every byte the selector can see; the generated
 * `_Static_assert`s additionally pin the hand-written `X86_OP_MULX` /
 * `X86_WIDTH_*` decodes to the generated table at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_mulx_arm_host.c -o /tmp/t_mulx_arm
 *   /tmp/t_mulx_arm
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. The width
 * codes have the same values the simulator decodes. */
#define X86_OP_MULX 0x39U
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_mulx_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent width code the single-product arm is selected at, and the
 * independent arm codes the two bodies carry. The model uses these literals
 * rather than the generated defines, so a drift in either generated code is a
 * mismatch, not a tautology. */
#define MODEL_SPECIAL_WIDTH_CODE 4U
#define MODEL_SINGLE_PRODUCT_CODE 0U
#define MODEL_LIMB_LADDER_CODE 1U

/* The independent selection: a resolved width code names the single-product
 * arm exactly at the 32-bit code, the ladder arm at every other code. */
static int model_arm(unsigned width)
{
	return width == MODEL_SPECIAL_WIDTH_CODE
		? (int)MODEL_SINGLE_PRODUCT_CODE
		: (int)MODEL_LIMB_LADDER_CODE;
}

int main(void)
{
	unsigned width;

	cases++;
	if (KPROG_X86_MULX_ARM_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_X86_MULX_ARM_COUNT);
		failures++;
	}

	cases++;
	if (KPROG_X86_MULX_SPECIAL_WIDTH != MODEL_SPECIAL_WIDTH_CODE) {
		printf("MISMATCH special-width got=%u want=%u\n",
		       (unsigned)KPROG_X86_MULX_SPECIAL_WIDTH,
		       (unsigned)MODEL_SPECIAL_WIDTH_CODE);
		failures++;
	}

	cases++;
	if (KPROG_X86_MULX_ARM_SINGLE_PRODUCT ==
	    KPROG_X86_MULX_ARM_LIMB_LADDER) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_MULX_ARM_SINGLE_PRODUCT != MODEL_SINGLE_PRODUCT_CODE ||
	    KPROG_X86_MULX_ARM_LIMB_LADDER != MODEL_LIMB_LADDER_CODE) {
		printf("MISMATCH arm code got=%u/%u want=%u/%u\n",
		       (unsigned)KPROG_X86_MULX_ARM_SINGLE_PRODUCT,
		       (unsigned)KPROG_X86_MULX_ARM_LIMB_LADDER,
		       (unsigned)MODEL_SINGLE_PRODUCT_CODE,
		       (unsigned)MODEL_LIMB_LADDER_CODE);
		failures++;
	}

	/* The selector returns the arm the independent model names, over the
	 * whole byte range the resolved width code can take. */
	for (width = 0; width <= 0xffU; width++) {
		unsigned got = KPROG_X86_MULX_ARM((__u8)width);
		int want = model_arm(width);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH arm width=%u got=%u want=%d\n",
			       width, got, want);
			failures++;
		}
	}

	/* Only the 32-bit width code reaches the single-product arm; every
	 * other real code reaches the ladder arm. */
	cases++;
	if (KPROG_X86_MULX_ARM(X86_WIDTH_32) !=
		KPROG_X86_MULX_ARM_SINGLE_PRODUCT ||
	    KPROG_X86_MULX_ARM(X86_WIDTH_64) !=
		KPROG_X86_MULX_ARM_LIMB_LADDER ||
	    KPROG_X86_MULX_ARM(X86_WIDTH_16) !=
		KPROG_X86_MULX_ARM_LIMB_LADDER ||
	    KPROG_X86_MULX_ARM(X86_WIDTH_8) !=
		KPROG_X86_MULX_ARM_LIMB_LADDER) {
		printf("MISMATCH width arm drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 mulx arm host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 mulx arm host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
