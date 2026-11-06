/*
 * Host cross-check for the x86-64 `BZHI`/`BZHI_MEM` flag-block contract
 * (STEP 0131).
 *
 * The module under test is `generated/x86_bzhi_flags.h`. It fixes the flag
 * block the simulator's `X86_SIM_L_EXEC_BZHI_STEP` composition applies
 * alongside the masked bit-clear. CF compares the byte count with operand
 * size, ZF and SF follow the result, and OF is clear. The oracle exhausts all
 * three Boolean inputs and checks that the macro overwrites incoming flags.
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

/* Independent count, zero and sign inputs; OF is always clear. */
static void model_bzhi_flags(unsigned *cf, unsigned *zf, unsigned *sf,
			     unsigned *of, unsigned count_ge_bits,
			     unsigned result_is_zero, unsigned result_is_negative)
{
	*cf = count_ge_bits ? 1U : 0U;
	*zf = result_is_zero ? 1U : 0U;
	*sf = result_is_negative ? 1U : 0U;
	*of = 0U;
}

/* Run the macro against a planted all-set flag state, so a flag it fails to
 * write is observable rather than coincidentally cleared. */
static void check_inputs(unsigned count_ge_bits, unsigned result_is_zero, unsigned result_is_negative)
{
	unsigned gcf = 1U, gzf = 1U, gsf = 1U, gof = 1U;
	unsigned wcf, wzf, wsf, wof;

	KPROG_X86_SET_BZHI_FLAGS(gcf, gzf, gsf, gof, count_ge_bits,
				 result_is_zero, result_is_negative);
	model_bzhi_flags(&wcf, &wzf, &wsf, &wof, count_ge_bits,
			 result_is_zero, result_is_negative);

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
	unsigned rn;

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

	/* Exhaust the three independent flag inputs. */
	for (cge = 0U; cge <= 1U; cge++)
		for (rz = 0U; rz <= 1U; rz++)
			for (rn = 0U; rn <= 1U; rn++)
				check_inputs(cge, rz, rn);

	/* A planted all-set pre-state is fully overwritten, so no flag is
	 * accidentally preserved. */
	cases++;
	{
		unsigned gcf = 1U, gzf = 1U, gsf = 1U, gof = 1U;

		KPROG_X86_SET_BZHI_FLAGS(gcf, gzf, gsf, gof, 1U, 0U, 0U);
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
