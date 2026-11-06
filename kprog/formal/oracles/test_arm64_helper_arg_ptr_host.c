/*
 * Host cross-check for the AArch64 BPF helper-argument pointer contract
 * (STEP 0139).
 *
 * The module under test is `generated/arm64_helper_arg_ptr.h`. It fixes the
 * two pointer sources the simulator's `ARM64_SIM_L_HELPER_ARG_PTR` helper
 * selects between from a single closed fact: whether the argument register's
 * provenance tag is the stack tag. The stack arena pointer source fires
 * exactly for a stack-tagged register, the raw pointer otherwise. This oracle
 * drives the contract's `KPROG_ARM64_HELPER_ARG_PTR_BODY` and restates the
 * 2-way source selection from the raw fact with no reference to the generated
 * selector. The two must agree; the generated `_Static_assert`s additionally
 * pin the source codes and the selector's two fact selections at compile
 * time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_helper_arg_ptr_host.c \
 *       -o /tmp/t_hap
 *   /tmp/t_hap
 */
typedef unsigned char __u8;

#include "generated/arm64_helper_arg_ptr.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 2-way source selection: the stack arena pointer exactly
 * when the register's provenance tag is the stack tag, the raw pointer
 * otherwise. Restated from the raw fact. */
static unsigned model_source(unsigned stack_tagged)
{
	if (stack_tagged)
		return 0;
	return 1;
}

int main(void)
{
	unsigned stack_tagged;

	cases++;
	if (KPROG_ARM64_HELPER_ARG_PTR_BODY_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_HELPER_ARG_PTR_BODY_COUNT);
		failures++;
	}

	/* The source-code defines name the two distinct codes. */
	cases++;
	if (KPROG_ARM64_HELPER_ARG_PTR_BODY_STACK_ARENA_PTR != 0U ||
	    KPROG_ARM64_HELPER_ARG_PTR_BODY_RAW_PTR != 1U) {
		printf("MISMATCH source code defines drift\n");
		failures++;
	}

	/* The full selection table: the fact crossed against the independent
	 * 2-way statement. */
	for (stack_tagged = 0; stack_tagged <= 1U; stack_tagged++) {
		unsigned got =
			KPROG_ARM64_HELPER_ARG_PTR_BODY(stack_tagged);
		unsigned want = model_source(stack_tagged);

		cases++;
		if (got != want) {
			printf("MISMATCH source stack_tagged=%u got=%u "
			       "want=%u\n", stack_tagged, got, want);
			failures++;
		}
	}

	/* The selector is a plain expression in its input: feeding the fact
	 * the helper actually computes (the register-tag test) at each tag
	 * code must reach the same sources. */
	{
		static const unsigned tags[] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U,
						 7U, 8U };
		unsigned ti;

		for (ti = 0; ti < sizeof(tags) / sizeof(tags[0]); ti++) {
			unsigned stackf = (tags[ti] == 4U);

			cases++;
			if (KPROG_ARM64_HELPER_ARG_PTR_BODY(stackf) !=
			    model_source(stackf)) {
				printf("MISMATCH tag code tag=%u\n", tags[ti]);
				failures++;
			}
		}
	}

	/* The two sources name two distinct codes. */
	cases++;
	{
		unsigned a = KPROG_ARM64_HELPER_ARG_PTR_BODY(1);
		unsigned b = KPROG_ARM64_HELPER_ARG_PTR_BODY(0);

		if (a == b) {
			printf("MISMATCH source codes not distinct\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 helper arg pointer host cross-check: "
		       "FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 helper arg pointer host cross-check: OK "
	       "(%lu cases)\n", cases);
	return 0;
}
