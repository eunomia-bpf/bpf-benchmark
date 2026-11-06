/*
 * Host cross-check for the x86-64 `DIV` resolved-width case-selection contract
 * (STEP 0115).
 *
 * The module under test is `generated/x86_div.h`. It fixes the body the
 * simulator's `X86_OP_DIV` arm selects from a *resolved* operand width code:
 * the byte case at the 8-bit code, the word case at the 16-bit code, the dword
 * case at the 32-bit code, and the qword case at every other code (including
 * the absent `0`), so the ladder is total. The simulator writes that ladder by
 * hand as a chain of `if (__x86_l_width == X86_WIDTH_*)`, and this oracle
 * drives the contract's `KPROG_X86_DIV_ARM` / `KPROG_X86_DIV_ARM_COUNT` /
 * `KPROG_X86_DIV_ARM_B*` and restates the selection from the raw width codes.
 * The two must agree on every byte the selector can see; the generated
 * `_Static_assert`s additionally pin the hand-written `X86_OP_DIV` /
 * `X86_WIDTH_*` decodes to the generated table at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_div_host.c -o /tmp/t_div
 *   /tmp/t_div
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. The width
 * codes have the same values the simulator decodes. */
#define X86_OP_DIV 0x1aU
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_div.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent width codes the byte/word/dword cases are selected at. */
#define MODEL_BYTE_CODE 1U
#define MODEL_WORD_CODE 2U
#define MODEL_DWORD_CODE 4U
#define MODEL_QWORD_CODE 8U

/* The independent selection: a resolved width code names the byte/word/dword
 * cases exactly at their own 8/16/32-bit codes, and the qword case at every
 * other code (including the absent `0`), so the ladder is total. */
static int model_arm(unsigned width)
{
	if (width == MODEL_BYTE_CODE)
		return (int)KPROG_X86_DIV_ARM_B8;
	if (width == MODEL_WORD_CODE)
		return (int)KPROG_X86_DIV_ARM_B16;
	if (width == MODEL_DWORD_CODE)
		return (int)KPROG_X86_DIV_ARM_B32;
	return (int)KPROG_X86_DIV_ARM_B64;
}

int main(void)
{
	unsigned width;

	cases++;
	if (KPROG_X86_DIV_ARM_COUNT != 4U) {
		printf("MISMATCH count got=%u want=4\n",
		       (unsigned)KPROG_X86_DIV_ARM_COUNT);
		failures++;
	}

	cases++;
	if (X86_OP_DIV != 0x1aU) {
		printf("MISMATCH opcode got=%u want=26\n", (unsigned)X86_OP_DIV);
		failures++;
	}

	cases++;
	if (KPROG_X86_DIV_ARM_B8 == KPROG_X86_DIV_ARM_B16 ||
	    KPROG_X86_DIV_ARM_B16 == KPROG_X86_DIV_ARM_B32 ||
	    KPROG_X86_DIV_ARM_B32 == KPROG_X86_DIV_ARM_B64 ||
	    KPROG_X86_DIV_ARM_B8 == KPROG_X86_DIV_ARM_B64) {
		printf("MISMATCH case codes not distinct\n");
		failures++;
	}

	/* The selector returns the case the independent model names, over the
	 * whole byte range the resolved width code can take. */
	for (width = 0; width <= 0xffU; width++) {
		unsigned got = KPROG_X86_DIV_ARM((__u8)width);
		int want = model_arm(width);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH arm width=%u got=%u want=%d\n",
			       width, got, want);
			failures++;
		}
	}

	/* Each real byte/word/dword code reaches its own case, and a code that
	 * is none of them (here the 64-bit code and the absent code) reaches the
	 * default qword case. */
	cases++;
	if (KPROG_X86_DIV_ARM(X86_WIDTH_8) != KPROG_X86_DIV_ARM_B8 ||
	    KPROG_X86_DIV_ARM(X86_WIDTH_16) != KPROG_X86_DIV_ARM_B16 ||
	    KPROG_X86_DIV_ARM(X86_WIDTH_32) != KPROG_X86_DIV_ARM_B32 ||
	    KPROG_X86_DIV_ARM(X86_WIDTH_64) != KPROG_X86_DIV_ARM_B64 ||
	    KPROG_X86_DIV_ARM(0U) != KPROG_X86_DIV_ARM_B64 ||
	    KPROG_X86_DIV_ARM(3U) != KPROG_X86_DIV_ARM_B64) {
		printf("MISMATCH width arm drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 div host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 div host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
