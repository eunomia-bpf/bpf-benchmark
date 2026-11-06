/*
 * Host cross-check for the AArch64 register-number -> dispatch-cell contract
 * (STEP 0108).
 *
 * The module under test is `generated/arm64_reg_dispatch.h`. It fixes the value
 * the simulator's `ARM64_SIM_L_FOR_EACH_GPR` dispatch binds to each decoded
 * AArch64 register number: cell `n` is register number `n`, for the 31
 * general-purpose registers `x0 .. x30`. The zero register (`31`, `ARM64_XZR`),
 * the stack pointer (`32`, `ARM64_SP`) and the no-register sentinel (`0xff`,
 * `ARM64_REG_NONE`) are not dispatch cells.
 *
 * The simulator binds a register number to a cell name only by hand-written
 * X-macro order in `arm64_sim_local_bpf.h`; there is no generated header for
 * that binding. This oracle drives the contract's `KPROG_ARM64_GPR_CELL` /
 * `KPROG_ARM64_GPR_COUNT` and restates the same binding from the raw register
 * numbers, and the two must agree on every register number; the generated
 * `_Static_assert`s additionally pin the hand-written `ARM64_X<n>` decode to the
 * generated table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_reg_dispatch_host.c -o /tmp/t_ard
 *   /tmp/t_ard
 */
typedef unsigned char __u8;

/* The hand-written register decode the generated drift checks bind to. */
#define ARM64_X0 0U
#define ARM64_X1 1U
#define ARM64_X2 2U
#define ARM64_X3 3U
#define ARM64_X4 4U
#define ARM64_X5 5U
#define ARM64_X6 6U
#define ARM64_X7 7U
#define ARM64_X8 8U
#define ARM64_X9 9U
#define ARM64_X10 10U
#define ARM64_X11 11U
#define ARM64_X12 12U
#define ARM64_X13 13U
#define ARM64_X14 14U
#define ARM64_X15 15U
#define ARM64_X16 16U
#define ARM64_X17 17U
#define ARM64_X18 18U
#define ARM64_X19 19U
#define ARM64_X20 20U
#define ARM64_X21 21U
#define ARM64_X22 22U
#define ARM64_X23 23U
#define ARM64_X24 24U
#define ARM64_X25 25U
#define ARM64_X26 26U
#define ARM64_X27 27U
#define ARM64_X28 28U
#define ARM64_X29 29U
#define ARM64_X30 30U

#include "generated/arm64_reg_dispatch.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent binding: the dispatch cell index a general-purpose register
 * number names is the number itself. */
static unsigned model_cell(unsigned reg)
{
	return reg;
}

int main(void)
{
	unsigned reg;

	cases++;
	if (KPROG_ARM64_GPR_COUNT != 31U) {
		printf("MISMATCH count got=%u want=31\n",
		       (unsigned)KPROG_ARM64_GPR_COUNT);
		failures++;
	}

	/* The cell selector returns the register number it was handed, over the
	 * full byte range, against the independent binding. */
	for (reg = 0; reg <= 0xffU; reg++) {
		unsigned got = KPROG_ARM64_GPR_CELL((__u8)reg);
		unsigned want = model_cell(reg);

		cases++;
		if (got != want) {
			printf("MISMATCH cell reg=%u got=%u want=%u\n",
			       reg, got, want);
			failures++;
		}
	}

	if (failures != 0) {
		printf("arm64 reg dispatch host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 reg dispatch host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
