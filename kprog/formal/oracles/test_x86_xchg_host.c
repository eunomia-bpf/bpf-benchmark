/*
 * Host cross-check for the x86-64 `XCHG` width-keyed arm-selection contract
 * (STEP 0114).
 *
 * The module under test is `generated/x86_xchg.h`. It fixes the body the
 * simulator's `X86_OP_XCHG` arm selects from a *resolved* operand width code:
 * the pointer-swap arm at the full 64-bit code (`8`), the subword-value-swap
 * arm at every other code. The simulator writes that selection by hand as
 * `if (__x86_l_width == X86_WIDTH_64)`, and this oracle drives the contract's
 * `KPROG_X86_XCHG_ARM` / `KPROG_X86_XCHG_ARM_COUNT` / `KPROG_X86_XCHG_FULL_WIDTH`
 * and restates the selection from the raw width codes. The two must agree on
 * every byte the selector can see; the generated `_Static_assert`s
 * additionally pin the hand-written `X86_OP_XCHG` / `X86_WIDTH_*` decodes to
 * the generated table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_xchg_host.c -o /tmp/t_xchg
 *   /tmp/t_xchg
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. The width
 * codes have the same values the simulator decodes. */
#define X86_OP_XCHG 0x19U
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_xchg.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 64-bit width code the pointer-swap arm is selected at. */
#define MODEL_FULL_WIDTH_CODE 8U

/* The independent selection: a resolved width code names the pointer-swap arm
 * exactly at the full 64-bit code, the subword arm at every other code. */
static int model_arm(unsigned width)
{
	return width == MODEL_FULL_WIDTH_CODE
		? (int)KPROG_X86_XCHG_ARM_POINTER_SWAP
		: (int)KPROG_X86_XCHG_ARM_SUBWORD_SWAP;
}

int main(void)
{
	unsigned width;

	cases++;
	if (KPROG_X86_XCHG_ARM_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_X86_XCHG_ARM_COUNT);
		failures++;
	}

	cases++;
	if (KPROG_X86_XCHG_FULL_WIDTH != MODEL_FULL_WIDTH_CODE) {
		printf("MISMATCH full-width got=%u want=%u\n",
		       (unsigned)KPROG_X86_XCHG_FULL_WIDTH,
		       (unsigned)MODEL_FULL_WIDTH_CODE);
		failures++;
	}

	cases++;
	if (KPROG_X86_XCHG_ARM_POINTER_SWAP == KPROG_X86_XCHG_ARM_SUBWORD_SWAP) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	/* The selector returns the arm the independent model names, over the
	 * whole byte range the resolved width code can take. */
	for (width = 0; width <= 0xffU; width++) {
		unsigned got = KPROG_X86_XCHG_ARM((__u8)width);
		int want = model_arm(width);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH arm width=%u got=%u want=%d\n",
			       width, got, want);
			failures++;
		}
	}

	/* Only the 64-bit width code reaches the pointer arm; every narrower
	 * real code reaches the subword arm. */
	cases++;
	if (KPROG_X86_XCHG_ARM(X86_WIDTH_64) != KPROG_X86_XCHG_ARM_POINTER_SWAP ||
	    KPROG_X86_XCHG_ARM(X86_WIDTH_32) != KPROG_X86_XCHG_ARM_SUBWORD_SWAP ||
	    KPROG_X86_XCHG_ARM(X86_WIDTH_16) != KPROG_X86_XCHG_ARM_SUBWORD_SWAP ||
	    KPROG_X86_XCHG_ARM(X86_WIDTH_8) != KPROG_X86_XCHG_ARM_SUBWORD_SWAP) {
		printf("MISMATCH width arm drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 xchg host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 xchg host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
