/*
 * Host cross-check for the x86-64 stack word-path/byte-ladder body-selection
 * contract (STEP 0120).
 *
 * The module under test is `generated/x86_stack_arm.h`. It fixes the body the
 * simulator's `X86_SIM_L_STACK_WRITE` and `X86_SIM_L_STACK_READ` helpers select
 * between from two facts about a resolved access: whether the effective access
 * width is the full 64-bit code and whether the resolved stack index is
 * qword-aligned. Only when both hold does the helper touch the word arena
 * `q[INDEX >> 3]`, covering exactly the byte window `[index, index + 8)`; every
 * other width and every unaligned index goes through the little-endian byte
 * ladder over `b[]`. The helpers write that choice by hand as a
 * `width == 64 && index aligned` test, and this oracle drives the contract's
 * `KPROG_X86_STACK_ARM` / `.._COUNT` / `.._ARM_*` and restates the selection
 * from the raw 64-bit test and alignment test. The two must agree; the
 * generated `_Static_assert`s additionally pin the hand-written `X86_WIDTH_64`
 * decode to the generated table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_stack_arm_host.c -o /tmp/t_stack_arm
 *   /tmp/t_stack_arm
 */
typedef unsigned char __u8;

/* The hand-written decode the generated drift check binds to. */
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_stack_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent selection: the word-arena body exactly when the access is the
 * full 64-bit width code and the resolved index is qword-aligned, the
 * byte-ladder body otherwise. The arm codes are restated as literals so the
 * model is independent of the generated `.._ARM_*` values. */
static unsigned model_arm(unsigned is_w64, unsigned is_aligned)
{
	if (is_w64 && is_aligned)
		return 1;      /* word */
	return 0;              /* byte */
}

int main(void)
{
	unsigned is_w64;
	unsigned is_aligned;

	cases++;
	if (KPROG_X86_STACK_ARM_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_X86_STACK_ARM_COUNT);
		failures++;
	}

	cases++;
	if (X86_WIDTH_64 != KPROG_X86_STACK_ARM_WIDTH64 ||
	    KPROG_X86_STACK_ARM_WIDTH64 != 8U) {
		printf("MISMATCH decode width64=%u arm_width64=%u\n",
		       (unsigned)X86_WIDTH_64,
		       (unsigned)KPROG_X86_STACK_ARM_WIDTH64);
		failures++;
	}

	cases++;
	if (KPROG_X86_STACK_ARM_WORD == KPROG_X86_STACK_ARM_BYTE) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	/* The selector returns the body the independent model names, over the
	 * whole byte range of both facts. */
	for (is_w64 = 0; is_w64 <= 0xffU; is_w64++) {
		for (is_aligned = 0; is_aligned <= 0xffU; is_aligned++) {
			unsigned got = KPROG_X86_STACK_ARM((__u8)is_w64,
							   (__u8)is_aligned);
			unsigned want = model_arm(is_w64, is_aligned);

			cases++;
			if (got != want) {
				printf("MISMATCH arm w64=%u aligned=%u got=%u "
				       "want=%u\n", is_w64, is_aligned, got,
				       want);
				failures++;
			}
		}
	}

	/* Each fact pair reaches its own body: the full 64-bit code at an aligned
	 * index reaches the word arena, and every other pair the byte ladder.
	 * Both inputs are the closed boolean facts the helpers pass — a 64-bit
	 * test and an alignment test — not the raw width code. */
	cases++;
	if (KPROG_X86_STACK_ARM(X86_WIDTH_64 == X86_WIDTH_64, 1U) !=
		    KPROG_X86_STACK_ARM_WORD ||
	    KPROG_X86_STACK_ARM(X86_WIDTH_64 == X86_WIDTH_64, 0U) !=
		    KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(X86_WIDTH_32 == X86_WIDTH_64, 1U) !=
		    KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(X86_WIDTH_16 == X86_WIDTH_64, 1U) !=
		    KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(X86_WIDTH_8 == X86_WIDTH_64, 1U) !=
		    KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(0U == X86_WIDTH_64, 1U) !=
		    KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(X86_WIDTH_32 == X86_WIDTH_64, 0U) !=
		    KPROG_X86_STACK_ARM_BYTE ||
	    KPROG_X86_STACK_ARM(0U == X86_WIDTH_64, 0U) !=
		    KPROG_X86_STACK_ARM_BYTE) {
		printf("MISMATCH arm selection drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 stack arm host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 stack arm host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
