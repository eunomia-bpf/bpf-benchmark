/*
 * Host cross-check for the x86-64 `MOVZX`/`MOVSX` register-source opcode-keyed
 * extension-shape selection contract (STEP 0118).
 *
 * The module under test is `generated/x86_movx_shape.h`. It fixes the extension
 * function the simulator's `X86_OP_MOVZX_REG || X86_OP_MOVSX_REG` arm (and the
 * shared `X86_SIM_L_EXEC_MOVX_REG` body) selects between on the opcode: the sign
 * extension (`x86_sign_extend`) at the `X86_OP_MOVSX_REG` opcode and the zero
 * extension (`x86_apply_width`) at every other opcode. The simulator writes that
 * choice by hand as an `(OP) == X86_OP_MOVSX_REG ?` select, and this oracle
 * drives the contract's `KPROG_X86_MOVX_SHAPE` / `.._COUNT` / `.._SHAPE_*` and
 * restates the selection from the raw opcodes. The two must agree; the generated
 * `_Static_assert`s additionally pin the hand-written `X86_OP_MOVZX_REG` /
 * `X86_OP_MOVSX_REG` decodes to the generated table at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_movx_shape_host.c -o /tmp/t_movx_shape
 *   /tmp/t_movx_shape
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. */
#define X86_OP_MOVZX_REG 0x20U
#define X86_OP_MOVSX_REG 0x21U

#include "generated/x86_movx_shape.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent selection: the sign-extension body exactly at the
 * `X86_OP_MOVSX_REG` opcode and the zero-extension body at every other opcode,
 * so the selector is total. The arm codes are restated as literals so the model
 * is independent of the generated `.._SHAPE_*` values. */
static int model_arm(unsigned op)
{
	return op == X86_OP_MOVSX_REG ? 0 : 1;
}

int main(void)
{
	unsigned op;

	cases++;
	if (KPROG_X86_MOVX_SHAPE_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_X86_MOVX_SHAPE_COUNT);
		failures++;
	}

	cases++;
	if (X86_OP_MOVZX_REG != 0x20U || X86_OP_MOVSX_REG != 0x21U) {
		printf("MISMATCH opcode got=%u/%u want=32/33\n",
		       (unsigned)X86_OP_MOVZX_REG, (unsigned)X86_OP_MOVSX_REG);
		failures++;
	}

	cases++;
	if (KPROG_X86_MOVX_SHAPE_SIGN_EXTEND ==
	    KPROG_X86_MOVX_SHAPE_ZERO_EXTEND) {
		printf("MISMATCH shape codes not distinct\n");
		failures++;
	}

	/* The selector returns the extension function the independent model
	 * names, over the whole byte range the opcode can take. */
	for (op = 0; op <= 0xffU; op++) {
		unsigned got = KPROG_X86_MOVX_SHAPE((__u8)op);
		int want = model_arm(op);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH shape op=%u got=%u want=%d\n",
			       op, got, want);
			failures++;
		}
	}

	/* Each MOVX opcode reaches its own body, and a code that is neither
	 * (here the absent code 0) reaches the zero-extension default. */
	cases++;
	if (KPROG_X86_MOVX_SHAPE(X86_OP_MOVZX_REG) !=
		    KPROG_X86_MOVX_SHAPE_ZERO_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(X86_OP_MOVSX_REG) !=
		    KPROG_X86_MOVX_SHAPE_SIGN_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(0U) != KPROG_X86_MOVX_SHAPE_ZERO_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(3U) != KPROG_X86_MOVX_SHAPE_ZERO_EXTEND) {
		printf("MISMATCH opcode shape drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 movx shape host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 movx shape host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
