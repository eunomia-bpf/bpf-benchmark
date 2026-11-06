/*
 * Host cross-check for the AArch64 stack slot-tag write action contract
 * (STEP 0137).
 *
 * The module under test is `generated/arm64_stack_write_tag_action.h`. It
 * fixes the three slot-tag actions the simulator's
 * `ARM64_SIM_L_STACK_WRITE_TAG` helper selects between from a closed pair of
 * facts: whether the access width is 64 bits and whether the stack slot is
 * 8-aligned. The word-and-tag action fires exactly at the 64-bit aligned
 * access, the clear-and-write-bytes action at every aligned sub-qword
 * access, and the plain byte write otherwise. This oracle drives the
 * contract's `KPROG_ARM64_STACK_WRITE_TAG_ACTION` and restates the 3-way
 * selection from the two raw facts with no reference to the generated
 * selector. The two must agree; the generated `_Static_assert`s
 * additionally pin the action codes and the selector's four fact-pair
 * selections at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stack_write_tag_action_host.c \
 *       -o /tmp/t_swta
 *   /tmp/t_swta
 */
typedef unsigned char __u8;

#include "generated/arm64_stack_write_tag_action.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 3-way selection: the qword write and tag store exactly when
 * the access is 64-bit and the slot is 8-aligned, the aligned tag clear and
 * byte-ladder write at every aligned sub-qword access, and the plain byte
 * write otherwise. Restated from the two raw facts. */
static unsigned model_action(unsigned w64, unsigned aligned)
{
	if (w64 && aligned)
		return 0;
	if (aligned)
		return 1;
	return 2;
}

int main(void)
{
	unsigned w64;
	unsigned aligned;

	cases++;
	if (KPROG_ARM64_STACK_WRITE_TAG_ACTION_COUNT != 3U) {
		printf("MISMATCH action count got=%u want=3\n",
		       (unsigned)KPROG_ARM64_STACK_WRITE_TAG_ACTION_COUNT);
		failures++;
	}

	/* The action-code defines name the three distinct codes. */
	cases++;
	if (KPROG_ARM64_STACK_WRITE_TAG_ACTION_WRITE_WORD_AND_TAG != 0U ||
	    KPROG_ARM64_STACK_WRITE_TAG_ACTION_CLEAR_TAG_AND_WRITE_BYTES !=
	    1U ||
	    KPROG_ARM64_STACK_WRITE_TAG_ACTION_WRITE_BYTES_NO_TAG != 2U) {
		printf("MISMATCH action code defines drift\n");
		failures++;
	}

	/* The full selection table: every fact pair crossed against the
	 * independent 3-way statement. */
	for (w64 = 0; w64 <= 1U; w64++) {
		for (aligned = 0; aligned <= 1U; aligned++) {
			unsigned got =
				KPROG_ARM64_STACK_WRITE_TAG_ACTION(w64,
								    aligned);
			unsigned want = model_action(w64, aligned);

			cases++;
			if (got != want) {
				printf("MISMATCH action w64=%u aligned=%u "
				       "got=%u want=%u\n",
				       w64, aligned, got, want);
				failures++;
			}
		}
	}

	/* The selector is a plain expression in its inputs: feeding the facts
	 * the helper actually computes (the width-64 test and an 8-aligned
	 * slot test) at each width code must reach the same actions. */
	{
		static const unsigned widths[] = { 1U, 2U, 4U, 8U };
		unsigned wi;
		unsigned ai;

		for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
			for (ai = 0; ai <= 1U; ai++) {
				unsigned w64f = (widths[wi] == 8U);

				cases++;
				if (KPROG_ARM64_STACK_WRITE_TAG_ACTION(
						    w64f, ai) !=
				    model_action(w64f, ai)) {
					printf("MISMATCH width code w=%u "
					       "aligned=%u\n",
					       widths[wi], ai);
					failures++;
				}
			}
		}
	}

	/* The three actions name three distinct codes. */
	cases++;
	{
		unsigned a = KPROG_ARM64_STACK_WRITE_TAG_ACTION(1, 1);
		unsigned b = KPROG_ARM64_STACK_WRITE_TAG_ACTION(0, 1);
		unsigned c = KPROG_ARM64_STACK_WRITE_TAG_ACTION(0, 0);

		if (a == b || a == c || b == c) {
			printf("MISMATCH action codes not distinct\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 stack write tag action host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 stack write tag action host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
