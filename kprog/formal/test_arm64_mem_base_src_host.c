/*
 * Host cross-check for the AArch64 memory base-address source contract
 * (STEP 0140).
 *
 * The module under test is `generated/arm64_mem_base_src.h`. It fixes the two
 * base-address sources the simulator's scalar memory helpers
 * (`ARM64_SIM_L_MEM_READ`, `ARM64_SIM_L_MEM_READ_TAG`, `ARM64_SIM_L_MEM_WRITE`)
 * select between from a single closed fact: whether the base register is the
 * stack pointer. The stack pointer register source fires exactly for a base of
 * `ARM64_SP`, the general-purpose register arena base source otherwise. This
 * oracle drives the contract's `KPROG_ARM64_MEM_BASE_SRC` and restates the
 * 2-way source selection from the raw fact with no reference to the generated
 * selector. The two must agree; the generated `_Static_assert`s additionally
 * pin the source codes and the selector's two fact selections at compile time.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mem_base_src_host.c \
 *       -o /tmp/t_mbs
 *   /tmp/t_mbs
 */
typedef unsigned char __u8;

#include "generated/arm64_mem_base_src.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 2-way source selection: the stack pointer register exactly
 * when the base register is the stack pointer, the gpr arena base otherwise.
 * Restated from the raw fact. */
static unsigned model_source(unsigned base_is_sp)
{
	if (base_is_sp)
		return 0;
	return 1;
}

int main(void)
{
	unsigned base_is_sp;

	cases++;
	if (KPROG_ARM64_MEM_BASE_SRC_COUNT != 2U) {
		printf("MISMATCH source count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_MEM_BASE_SRC_COUNT);
		failures++;
	}

	/* The source-code defines name the two distinct codes. */
	cases++;
	if (KPROG_ARM64_MEM_BASE_SRC_SP_REGISTER != 0U ||
	    KPROG_ARM64_MEM_BASE_SRC_GPR_BASE != 1U) {
		printf("MISMATCH source code defines drift\n");
		failures++;
	}

	/* The full selection table: the fact crossed against the independent
	 * 2-way statement. */
	for (base_is_sp = 0; base_is_sp <= 1U; base_is_sp++) {
		unsigned got = KPROG_ARM64_MEM_BASE_SRC(base_is_sp);
		unsigned want = model_source(base_is_sp);

		cases++;
		if (got != want) {
			printf("MISMATCH source base_is_sp=%u got=%u "
			       "want=%u\n", base_is_sp, got, want);
			failures++;
		}
	}

	/* The selector is a plain expression in its input: feeding the fact
	 * the helpers actually compute (the `BASE == ARM64_SP` test) at each
	 * register number must reach the same sources. */
	{
		static const unsigned regs[] = { 0U, 1U, 2U, 15U, 28U, 30U,
						 31U, 32U, 33U, 255U };
		unsigned ri;

		for (ri = 0; ri < sizeof(regs) / sizeof(regs[0]); ri++) {
			unsigned spf = (regs[ri] == 32U);

			cases++;
			if (KPROG_ARM64_MEM_BASE_SRC(spf) !=
			    model_source(spf)) {
				printf("MISMATCH register reg=%u\n", regs[ri]);
				failures++;
			}
		}
	}

	/* The two sources name two distinct codes. */
	cases++;
	{
		unsigned a = KPROG_ARM64_MEM_BASE_SRC(1);
		unsigned b = KPROG_ARM64_MEM_BASE_SRC(0);

		if (a == b) {
			printf("MISMATCH source codes not distinct\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 mem base src host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 mem base src host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
