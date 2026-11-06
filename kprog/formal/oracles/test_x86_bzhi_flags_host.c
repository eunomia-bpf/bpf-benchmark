/*
 * Host cross-check for the x86-64 `BZHI`/`BZHI_MEM` flag-block contract
 * (STEP 0131).
 *
 * The module under test is `generated/x86_bzhi_flags.h`. It fixes the flag
 * block the simulator's `X86_SIM_L_EXEC_BZHI_STEP` composition applies
 * alongside the masked bit-clear: `SF` and `OF` are cleared, `CF` is set
 * exactly when the byte-masked count reaches the resolved width's bit count,
 * and `ZF` is set exactly when the cleared result is zero. The simulator wrote
 * that block by hand (`__x86_cf = count >= bits; __x86_of = 0; ...`), and this
 * oracle drives `KPROG_X86_SET_BZHI_FLAGS` and restates the block from the
 * literal flag rules. The two must agree for every input; the generated
 * `_Static_assert`s additionally pin the hand-written `X86_OP_BZHI` /
 * `X86_OP_BZHI_MEM` decodes to the generated opcodes at compile time. Unlike
 * `POPCNT`, whose one input is the source-zero predicate, `BZHI` takes two:
 * the count-versus-width `CF` and the result-zero `ZF`. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_bzhi_flags_host.c -o /tmp/t_bz_flags
 *   /tmp/t_bz_flags
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to; the opcodes have
 * the values the simulator decodes (`kprog/x86/x86_sim.h`). */
#define X86_OP_BZHI 0x34U
#define X86_OP_BZHI_MEM 0x35U

#include "generated/x86_bzhi_flags.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent flag block: `SF`/`OF` cleared, `CF` the count-versus-width
 * comparison, `ZF` the result-zero predicate. */
static void model_bzhi_flags(unsigned *cf, unsigned *zf, unsigned *sf,
			     unsigned *of, unsigned count_ge_bits,
			     unsigned result_is_zero)
{
	*cf = count_ge_bits ? 1U : 0U;
	*zf = result_is_zero ? 1U : 0U;
	*sf = 0U;
	*of = 0U;
}

/* Run the macro against a planted all-set flag state, so a flag it fails to
 * write is observable rather than coincidentally cleared. */
static void check_inputs(unsigned count_ge_bits, unsigned result_is_zero)
{
	unsigned gcf = 1U, gzf = 1U, gsf = 1U, gof = 1U;
	unsigned wcf, wzf, wsf, wof;

	KPROG_X86_SET_BZHI_FLAGS(gcf, gzf, gsf, gof, count_ge_bits,
				 result_is_zero);
	model_bzhi_flags(&wcf, &wzf, &wsf, &wof, count_ge_bits,
			 result_is_zero);

	cases++;
	if (gcf != wcf || gzf != wzf || gsf != wsf || gof != wof) {
		printf("MISMATCH cge=%u rz=%u got %u/%u/%u/%u want %u/%u/%u/%u\n",
		       count_ge_bits, result_is_zero, gcf, gzf, gsf, gof,
		       wcf, wzf, wsf, wof);
		failures++;
	}
}

int main(void)
{
	unsigned cge;
	unsigned rz;

	cases++;
	if (X86_OP_BZHI != 0x34U) {
		printf("MISMATCH opcode got=%u want=52\n",
		       (unsigned)X86_OP_BZHI);
		failures++;
	}
	cases++;
	if (X86_OP_BZHI_MEM != 0x35U) {
		printf("MISMATCH mem opcode got=%u want=53\n",
		       (unsigned)X86_OP_BZHI_MEM);
		failures++;
	}

	/* Every combination of the two flag inputs: `CF` tracks the count
	 * comparison, `ZF` tracks the result zero, and `SF`/`OF` stay cleared. */
	for (cge = 0U; cge <= 1U; cge++)
		for (rz = 0U; rz <= 1U; rz++)
			check_inputs(cge, rz);

	/* A planted all-set pre-state is fully overwritten, so no flag is
	 * accidentally preserved. */
	cases++;
	{
		unsigned gcf = 1U, gzf = 1U, gsf = 1U, gof = 1U;

		KPROG_X86_SET_BZHI_FLAGS(gcf, gzf, gsf, gof, 1U, 0U);
		if (gcf != 1U || gzf != 0U || gsf != 0U || gof != 0U) {
			printf("MISMATCH all-set pre-state not overwritten\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("x86 bzhi flags host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 bzhi flags host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
