/*
 * Host cross-check for the AArch64 memory index-value source contract
 * (STEP 0142).
 *
 * The module under test is `generated/arm64_mem_index_value.h`. It fixes the
 * index-value source the simulator's `ARM64_SIM_L_MEM_BASE_OFF` selects between
 * from a single closed fact: whether the addressing mode carries an index
 * register. The source-modified index register value source fires exactly when
 * the addressing mode carries an index register, the literal zero source
 * otherwise (the sentinel index operand, which adds no index contribution).
 * This oracle drives the contract's `KPROG_ARM64_MEM_INDEX_VALUE` and restates
 * the 2-way source selection from the raw fact with no reference to the
 * generated selector. The two must agree, and the selector must name the same
 * source as the 0102 index-presence fact `KPROG_ARM64_MEM_INDEX_PRESENT`; the
 * generated `_Static_assert`s additionally pin the source codes and the
 * selector's two fact selections at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mem_index_value_host.c \
 *       -o /tmp/t_miv
 *   /tmp/t_miv
 */
typedef unsigned char __u8;

#include "generated/arm64_mem_index_value.h"
#include "generated/arm64_mem_index.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 2-way source selection: the source-modified index register
 * value exactly when the addressing mode carries an index register, the
 * literal zero source otherwise. Restated from the raw fact. */
static unsigned model_source(unsigned has_index)
{
	if (has_index)
		return 0;
	return 1;
}

int main(void)
{
	unsigned has_index;

	cases++;
	if (KPROG_ARM64_MEM_INDEX_VALUE_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_MEM_INDEX_VALUE_COUNT);
		failures++;
	}

	/* The source-code defines name the two distinct codes. */
	cases++;
	if (KPROG_ARM64_MEM_INDEX_VALUE_REGISTER != 0U ||
	    KPROG_ARM64_MEM_INDEX_VALUE_ZERO != 1U) {
		printf("MISMATCH source code defines drift\n");
		failures++;
	}

	/* The full selection table: the fact crossed against the independent
	 * 2-way statement. */
	for (has_index = 0; has_index <= 1U; has_index++) {
		unsigned got = KPROG_ARM64_MEM_INDEX_VALUE(has_index);
		unsigned want = model_source(has_index);

		cases++;
		if (got != want) {
			printf("MISMATCH source has_index=%u got=%u "
			       "want=%u\n", has_index, got, want);
			failures++;
		}
	}

	/* The selector is a plain expression in its input: feeding the fact
	 * the offset actually computes (the `MEM_INDEX_PRESENT` test) at each
	 * raw index operand must reach the same sources, so the index-value
	 * contract and the 0102 presence contract agree. */
	{
		static const unsigned raw[] = { 0U, 1U, 5U, 31U, 254U, 255U };
		unsigned ri;

		for (ri = 0; ri < sizeof(raw) / sizeof(raw[0]); ri++) {
			unsigned pres = KPROG_ARM64_MEM_INDEX_PRESENT(raw[ri]);

			cases++;
			if (KPROG_ARM64_MEM_INDEX_VALUE(pres) !=
			    model_source(pres)) {
				printf("MISMATCH raw index=%u present=%u\n",
				       raw[ri], pres);
				failures++;
			}
			cases++;
			if ((KPROG_ARM64_MEM_INDEX_VALUE(pres) ==
			     KPROG_ARM64_MEM_INDEX_VALUE_REGISTER) !=
			    (pres != 0U)) {
				printf("MISMATCH presence raw index=%u\n",
				       raw[ri]);
				failures++;
			}
		}
	}

	/* The two sources name two distinct codes. */
	cases++;
	{
		unsigned a = KPROG_ARM64_MEM_INDEX_VALUE(1);
		unsigned b = KPROG_ARM64_MEM_INDEX_VALUE(0);

		if (a == b) {
			printf("MISMATCH source codes not distinct\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 mem index value host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 mem index value host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
