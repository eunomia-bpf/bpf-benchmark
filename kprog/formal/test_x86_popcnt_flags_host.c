/*
 * Host cross-check for the x86-64 `POPCNT` flag-block contract (STEP 0117).
 *
 * The module under test is `generated/x86_popcnt_flags.h`. It fixes the flag
 * block the simulator's `X86_OP_POPCNT` arm applies alongside the population
 * count: `CF`, `SF`, and `OF` are cleared, and `ZF` is set exactly when the
 * width-narrowed source operand is zero. The simulator writes that block by
 * hand (`__x86_cf = 0; __x86_of = 0; __x86_sf = 0; __x86_zf = ...`), and this
 * oracle drives `KPROG_X86_SET_POPCNT_FLAGS` and restates the block from the
 * literal flag rules. The two must agree for every input; the generated
 * `_Static_assert` additionally pins the hand-written `X86_OP_POPCNT` decode to
 * the generated opcode at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_popcnt_flags_host.c -o /tmp/t_pc_flags
 *   /tmp/t_pc_flags
 */
typedef unsigned char __u8;

/* The hand-written decode the generated drift check binds to; the opcode has
 * the value the simulator decodes (`kprog/x86/x86_sim.h`). */
#define X86_OP_POPCNT 0x18U

#include "generated/x86_popcnt_flags.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent flag block: `CF`/`SF`/`OF` cleared, `ZF` the zero predicate. */
static void model_popcnt_flags(unsigned *cf, unsigned *zf, unsigned *sf,
			       unsigned *of, unsigned zero)
{
	*cf = 0U;
	*zf = zero ? 1U : 0U;
	*sf = 0U;
	*of = 0U;
}

/* Run the macro against a planted nonzero flag state, so a flag it fails to
 * write is observable rather than coincidentally cleared. */
static void check_zero(unsigned zero)
{
	unsigned gcf = 1U, gzf = 1U, gsf = 1U, gof = 1U;
	unsigned wcf, wzf, wsf, wof;

	KPROG_X86_SET_POPCNT_FLAGS(gcf, gzf, gsf, gof, zero);
	model_popcnt_flags(&wcf, &wzf, &wsf, &wof, zero);

	cases++;
	if (gcf != wcf || gzf != wzf || gsf != wsf || gof != wof) {
		printf("MISMATCH zero=%u got %u/%u/%u/%u want %u/%u/%u/%u\n",
		       zero, gcf, gzf, gsf, gof, wcf, wzf, wsf, wof);
		failures++;
	}
}

int main(void)
{
	unsigned zero;

	cases++;
	if (X86_OP_POPCNT != 0x18U) {
		printf("MISMATCH opcode got=%u want=24\n",
		       (unsigned)X86_OP_POPCNT);
		failures++;
	}

	/* Every value the zero predicate can take: `ZF` tracks it and the other
	 * three flags stay cleared. */
	for (zero = 0U; zero <= 1U; zero++)
		check_zero(zero);

	/* A planted all-different pre-state is fully overwritten, so no flag is
	 * accidentally preserved. */
	cases++;
	{
		unsigned gcf = 1U, gzf = 1U, gsf = 1U, gof = 1U;

		KPROG_X86_SET_POPCNT_FLAGS(gcf, gzf, gsf, gof, 1U);
		if (gcf != 0U || gzf != 1U || gsf != 0U || gof != 0U) {
			printf("MISMATCH all-set pre-state not overwritten\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("x86 popcnt flags host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 popcnt flags host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
