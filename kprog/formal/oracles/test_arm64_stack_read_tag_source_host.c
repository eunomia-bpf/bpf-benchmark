/*
 * Host cross-check for the AArch64 stack slot-tag read source contract
 * (STEP 0138).
 *
 * The module under test is `generated/arm64_stack_read_tag_source.h`. It
 * fixes the two tag sources the simulator's `ARM64_SIM_L_STACK_READ_TAG`
 * helper selects between from a closed pair of facts: whether the read width
 * is 64 bits and whether the stack slot is 8-aligned. The stack-tag-array
 * source fires exactly at the 64-bit aligned read, the scalar default
 * otherwise. This oracle drives the contract's `KPROG_ARM64_STACK_READ_TAG_
 * SOURCE` and restates the 2-way source selection from the two raw facts
 * with no reference to the generated selector. The two must agree; the
 * generated `_Static_assert`s additionally pin the source codes and the
 * selector's four fact-pair selections at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stack_read_tag_source_host.c \
 *       -o /tmp/t_srts
 *   /tmp/t_srts
 */
typedef unsigned char __u8;

#include "generated/arm64_stack_read_tag_source.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 2-way source selection: the stack-tag-array source exactly
 * when the read is 64-bit and the slot is 8-aligned, the scalar default
 * otherwise. Restated from the two raw facts. */
static unsigned model_source(unsigned w64, unsigned aligned)
{
	if (w64 && aligned)
		return 0;
	return 1;
}

int main(void)
{
	unsigned w64;
	unsigned aligned;

	cases++;
	if (KPROG_ARM64_STACK_READ_TAG_SOURCE_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_STACK_READ_TAG_SOURCE_COUNT);
		failures++;
	}

	/* The source-code defines name the two distinct codes. */
	cases++;
	if (KPROG_ARM64_STACK_READ_TAG_SOURCE_STACK_TAG_ARRAY != 0U ||
	    KPROG_ARM64_STACK_READ_TAG_SOURCE_SCALAR_DEFAULT != 1U) {
		printf("MISMATCH source code defines drift\n");
		failures++;
	}

	/* The full selection table: every fact pair crossed against the
	 * independent 2-way statement. */
	for (w64 = 0; w64 <= 1U; w64++) {
		for (aligned = 0; aligned <= 1U; aligned++) {
			unsigned got =
				KPROG_ARM64_STACK_READ_TAG_SOURCE(w64,
								  aligned);
			unsigned want = model_source(w64, aligned);

			cases++;
			if (got != want) {
				printf("MISMATCH source w64=%u aligned=%u "
				       "got=%u want=%u\n",
				       w64, aligned, got, want);
				failures++;
			}
		}
	}

	/* The selector is a plain expression in its inputs: feeding the facts
	 * the helper actually computes (the width-64 test and an 8-aligned
	 * slot test) at each width code must reach the same sources. */
	{
		static const unsigned widths[] = { 1U, 2U, 4U, 8U };
		unsigned wi;
		unsigned ai;

		for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
			for (ai = 0; ai <= 1U; ai++) {
				unsigned w64f = (widths[wi] == 8U);

				cases++;
				if (KPROG_ARM64_STACK_READ_TAG_SOURCE(
						    w64f, ai) !=
				    model_source(w64f, ai)) {
					printf("MISMATCH width code w=%u "
					       "aligned=%u\n",
					       widths[wi], ai);
					failures++;
				}
			}
		}
	}

	/* The two sources name two distinct codes. */
	cases++;
	{
		unsigned a = KPROG_ARM64_STACK_READ_TAG_SOURCE(1, 1);
		unsigned b = KPROG_ARM64_STACK_READ_TAG_SOURCE(0, 0);

		if (a == b) {
			printf("MISMATCH source codes not distinct\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 stack read tag source host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 stack read tag source host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
