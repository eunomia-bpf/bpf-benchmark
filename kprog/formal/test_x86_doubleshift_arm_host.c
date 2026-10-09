/*
 * Host cross-check for the x86-64 `SHLD`/`SHRD` immediate opcode-keyed arm
 * selection contract (STEP 0116).
 *
 * The module under test is `generated/x86_doubleshift_arm.h`. It fixes the
 * bodies the simulator's `X86_OP_SHLD_IMM || X86_OP_SHRD_IMM` arm selects
 * between: the left double-shift body at the `X86_OP_SHLD_IMM` opcode (result
 * `x86_shld`, flag family `X86_ALU_SHL`) and the right double-shift body at
 * every other opcode (result `x86_shrd`, flag family `X86_ALU_SHR`). The
 * simulator writes that choice by hand as an `if ((OP) == X86_OP_SHLD_IMM)`
 * chain, and this oracle drives the contract's `KPROG_X86_DOUBLESHIFT_ARM` /
 * `.._FLAGS` / `.._COUNT` / `.._ARM_*` and restates the selection from the raw
 * opcodes. The two must agree on both the body and the flag family; the
 * generated `_Static_assert`s additionally pin the hand-written
 * `X86_OP_SHLD_IMM` / `X86_OP_SHRD_IMM` / `X86_ALU_SHL` / `X86_ALU_SHR`
 * decodes to the generated table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_doubleshift_arm_host.c -o /tmp/t_ds_arm
 *   /tmp/t_ds_arm
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. The opcodes and
 * ALU codes have the same values the simulator decodes. */
#define X86_OP_SHLD_IMM 0x1bU
#define X86_OP_SHRD_IMM 0x1cU
#define X86_ALU_SHL 5U
#define X86_ALU_SHR 6U

#include "generated/x86_doubleshift_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent selection: the left double-shift body and the SHL flag family
 * exactly at the `X86_OP_SHLD_IMM` opcode, the right double-shift body and the
 * SHR family at every other opcode, so both selectors are total. */
static int model_arm(unsigned op)
{
	/* The arm codes are restated as literals so the model is independent of
	 * the generated `.._ARM_SHLD` / `.._ARM_SHRD` values. */
	return op == X86_OP_SHLD_IMM ? 0 : 1;
}

static unsigned model_flags(unsigned op)
{
	return op == X86_OP_SHLD_IMM ? X86_ALU_SHL : X86_ALU_SHR;
}

int main(void)
{
	unsigned op;

	cases++;
	if (KPROG_X86_DOUBLESHIFT_ARM_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_X86_DOUBLESHIFT_ARM_COUNT);
		failures++;
	}

	cases++;
	if (X86_OP_SHLD_IMM != 0x1bU || X86_OP_SHRD_IMM != 0x1cU) {
		printf("MISMATCH opcode got=%u/%u want=27/28\n",
		       (unsigned)X86_OP_SHLD_IMM, (unsigned)X86_OP_SHRD_IMM);
		failures++;
	}

	cases++;
	if (KPROG_X86_DOUBLESHIFT_ARM_SHLD ==
	    KPROG_X86_DOUBLESHIFT_ARM_SHRD) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	cases++;
	if (X86_ALU_SHL == X86_ALU_SHR) {
		printf("MISMATCH flag families not distinct\n");
		failures++;
	}

	/* The selector returns the body and the flag family the independent model
	 * names, over the whole byte range the opcode can take. */
	for (op = 0; op <= 0xffU; op++) {
		unsigned got = KPROG_X86_DOUBLESHIFT_ARM((__u8)op);
		unsigned got_flags = KPROG_X86_DOUBLESHIFT_ARM_FLAGS((__u8)op);
		int want = model_arm(op);
		unsigned want_flags = model_flags(op);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH arm op=%u got=%u want=%d\n",
			       op, got, want);
			failures++;
		}
		cases++;
		if (got_flags != want_flags) {
			printf("MISMATCH flags op=%u got=%u want=%u\n",
			       op, got_flags, want_flags);
			failures++;
		}
	}

	/* Each double-shift opcode reaches its own body and family, and a code
	 * that is neither (here the absent code 0) reaches the default body. */
	cases++;
	if (KPROG_X86_DOUBLESHIFT_ARM(X86_OP_SHLD_IMM) !=
		    KPROG_X86_DOUBLESHIFT_ARM_SHLD ||
	    KPROG_X86_DOUBLESHIFT_ARM(X86_OP_SHRD_IMM) !=
		    KPROG_X86_DOUBLESHIFT_ARM_SHRD ||
	    KPROG_X86_DOUBLESHIFT_ARM(0U) != KPROG_X86_DOUBLESHIFT_ARM_SHRD ||
	    KPROG_X86_DOUBLESHIFT_ARM(3U) != KPROG_X86_DOUBLESHIFT_ARM_SHRD ||
	    KPROG_X86_DOUBLESHIFT_ARM_FLAGS(X86_OP_SHLD_IMM) != X86_ALU_SHL ||
	    KPROG_X86_DOUBLESHIFT_ARM_FLAGS(X86_OP_SHRD_IMM) != X86_ALU_SHR ||
	    KPROG_X86_DOUBLESHIFT_ARM_FLAGS(0U) != X86_ALU_SHR) {
		printf("MISMATCH opcode arm drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 doubleshift arm host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 doubleshift arm host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
