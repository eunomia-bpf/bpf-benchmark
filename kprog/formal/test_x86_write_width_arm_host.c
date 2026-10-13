/*
 * Host cross-check for the x86-64 register-write width body-selection contract
 * (STEP 0145).
 *
 * The module under test is `generated/x86_write_width_arm.h`. It fixes the
 * writeback body the simulator's `X86_SIM_L_WRITE_REG_WIDTH_SHIFT` macro
 * selects from a *resolved* operand width code: the byte body at the 8-bit
 * code, the word body at the 16-bit code, the dword body at the 32-bit code,
 * and the qword body at every other code (including the absent `0`), so the
 * ladder is total. The simulator used to write that ladder by hand as a chain
 * of `if (__x86_wr_width == X86_WIDTH_*)`, and this oracle drives the
 * contract's `KPROG_X86_WRITE_WIDTH_ARM` / `..._COUNT` / `..._B*` and restates
 * the selection from the raw width codes. The two must agree on every byte the
 * selector can see; the generated `_Static_assert`s additionally pin the
 * hand-written `X86_WIDTH_*` decodes to the generated table at compile time.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_write_width_arm_host.c -o /tmp/t_www
 *   /tmp/t_www
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. The width codes
 * have the same values the simulator decodes. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_write_width_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent width codes the byte/word/dword bodies are selected at. */
#define MODEL_BYTE_CODE 1U
#define MODEL_WORD_CODE 2U
#define MODEL_DWORD_CODE 4U
#define MODEL_QWORD_CODE 8U

/* The independent selection: a resolved width code names the byte/word/dword
 * bodies exactly at their own 8/16/32-bit codes, and the qword body at every
 * other code (including the absent `0`), so the ladder is total. */
static int model_arm(unsigned width)
{
	if (width == MODEL_BYTE_CODE)
		return (int)KPROG_X86_WRITE_WIDTH_ARM_B8;
	if (width == MODEL_WORD_CODE)
		return (int)KPROG_X86_WRITE_WIDTH_ARM_B16;
	if (width == MODEL_DWORD_CODE)
		return (int)KPROG_X86_WRITE_WIDTH_ARM_B32;
	return (int)KPROG_X86_WRITE_WIDTH_ARM_B64;
}

int main(void)
{
	unsigned width;

	if (KPROG_X86_WRITE_WIDTH_ARM_COUNT != 4U) {
		printf("MISMATCH body count drift\n");
		failures++;
	}
	cases++;

	if (KPROG_X86_WRITE_WIDTH_ARM_B8 == KPROG_X86_WRITE_WIDTH_ARM_B16 ||
	    KPROG_X86_WRITE_WIDTH_ARM_B16 == KPROG_X86_WRITE_WIDTH_ARM_B32 ||
	    KPROG_X86_WRITE_WIDTH_ARM_B32 == KPROG_X86_WRITE_WIDTH_ARM_B64 ||
	    KPROG_X86_WRITE_WIDTH_ARM_B8 == KPROG_X86_WRITE_WIDTH_ARM_B64) {
		printf("MISMATCH body codes not distinct\n");
		failures++;
	}

	/* The selector returns the body the independent model names, over the
	 * whole byte range the resolved width code can take. */
	for (width = 0; width <= 0xffU; width++) {
		unsigned got = KPROG_X86_WRITE_WIDTH_ARM((__u8)width);
		int want = model_arm(width);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH arm width=%u got=%u want=%d\n",
			       width, got, want);
			failures++;
		}
	}

	/* Each real byte/word/dword code reaches its own body, and a code that
	 * is none of them (here the 64-bit code and the absent code) reaches the
	 * default qword body. */
	cases++;
	if (KPROG_X86_WRITE_WIDTH_ARM(X86_WIDTH_8) != KPROG_X86_WRITE_WIDTH_ARM_B8 ||
	    KPROG_X86_WRITE_WIDTH_ARM(X86_WIDTH_16) != KPROG_X86_WRITE_WIDTH_ARM_B16 ||
	    KPROG_X86_WRITE_WIDTH_ARM(X86_WIDTH_32) != KPROG_X86_WRITE_WIDTH_ARM_B32 ||
	    KPROG_X86_WRITE_WIDTH_ARM(X86_WIDTH_64) != KPROG_X86_WRITE_WIDTH_ARM_B64 ||
	    KPROG_X86_WRITE_WIDTH_ARM(0U) != KPROG_X86_WRITE_WIDTH_ARM_B64 ||
	    KPROG_X86_WRITE_WIDTH_ARM(3U) != KPROG_X86_WRITE_WIDTH_ARM_B64) {
		printf("MISMATCH width body drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 write width host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 write width host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
