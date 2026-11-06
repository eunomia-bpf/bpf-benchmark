/*
 * Host cross-check for the x86-64 register-number -> dispatch-cell contract
 * (STEP 0112).
 *
 * The module under test is `generated/x86_reg_dispatch.h`. It fixes the value
 * the simulator's hand-written `X86_SIM_L_FOR_EACH_GPR` dispatch binds to each
 * decoded x86-64 register number: cell `n` is register number `n`, for the 16
 * general-purpose registers `rax .. r15`. Unlike AArch64 there is no zero
 * register, so the only register number that is not a dispatch cell is the
 * no-register sentinel (`0xff`, `X86_REG_NONE`).
 *
 * The simulator binds a register number to a cell name by hand-written order
 * (`X86_SIM_L_FOR_EACH_GPR` and the `X86_SIM_L_REG_VALUE` ternary chain); there
 * is no generated header for that binding. This oracle drives the contract's
 * `KPROG_X86_GPR_CELL` / `KPROG_X86_GPR_COUNT` and restates the binding from
 * the raw register numbers, and the two must agree on every register number;
 * the generated `_Static_assert`s additionally pin the hand-written
 * `X86_R<n>` decode to the generated table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_reg_dispatch_host.c -o /tmp/t_xrd
 *   /tmp/t_xrd
 */
typedef unsigned char __u8;

/* The hand-written register decode the generated drift checks bind to. */
#define X86_RAX 0U
#define X86_RCX 1U
#define X86_RDX 2U
#define X86_RBX 3U
#define X86_RSP 4U
#define X86_RBP 5U
#define X86_RSI 6U
#define X86_RDI 7U
#define X86_R8 8U
#define X86_R9 9U
#define X86_R10 10U
#define X86_R11 11U
#define X86_R12 12U
#define X86_R13 13U
#define X86_R14 14U
#define X86_R15 15U
#define X86_REG_NONE 0xffU

#include "generated/x86_reg_dispatch.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent binding: a general-purpose register number names the
 * dispatch cell whose index is the number itself; every byte above the GPR
 * range (including the sentinel `0xff`) names no cell, reported as -1. */
static int model_cell(unsigned reg)
{
	return reg < 16U ? (int)reg : -1;
}

int main(void)
{
	unsigned reg;

	cases++;
	if (KPROG_X86_GPR_COUNT != 16U) {
		printf("MISMATCH count got=%u want=16\n",
		       (unsigned)KPROG_X86_GPR_COUNT);
		failures++;
	}

	/* The cell selector returns the register number it was handed, over the
	 * full byte range, against the independent binding. */
	for (reg = 0; reg <= 0xffU; reg++) {
		unsigned got = KPROG_X86_GPR_CELL((__u8)reg);
		int want = model_cell(reg);

		cases++;
		if (want < 0) {
			/* Not a GPR: the selector is only defined on the GPR
			 * range, but it must still be the identity byte. */
			if (got != reg) {
				printf("MISMATCH non-gpr cell reg=%u got=%u\n",
				       reg, got);
				failures++;
			}
			continue;
		}
		if (got != (unsigned)want) {
			printf("MISMATCH cell reg=%u got=%u want=%d\n",
			       reg, got, want);
			failures++;
		}
	}

	/* The hand-written decode the generated drift checks bind to must name
	 * the cell its own number is. */
	cases++;
	if (KPROG_X86_GPR_CELL(X86_RAX) != 0U ||
	    KPROG_X86_GPR_CELL(X86_RSP) != 4U ||
	    KPROG_X86_GPR_CELL(X86_R8) != 8U ||
	    KPROG_X86_GPR_CELL(X86_R15) != 15U) {
		printf("MISMATCH dispatch constant drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 reg dispatch host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 reg dispatch host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
