/*
 * Host cross-check for the x86-64 `MOV_REG` three-way arm-selection contract
 * (STEP 0119).
 *
 * The module under test is `generated/x86_mov_reg_arm.h`. It fixes the body the
 * simulator's `X86_OP_MOV_REG` arm (and the shared `X86_SIM_L_EXEC_MOV_REG_AUX`
 * body) selects between from two facts about the operands: whether the resolved
 * operand width is the full 64-bit code and whether the encoded source register
 * is the stack pointer. At the full width the stack pointer selects the
 * stack-base pointer write, any other source the provenance-preserving pointer
 * write; at every narrower width the narrow scalarizing write, whatever the
 * source. The simulator writes that choice by hand as a
 * `width == 64 && src == rsp` / `width == 64` / else ladder, and this oracle
 * drives the contract's `KPROG_X86_MOV_REG_ARM` / `.._COUNT` / `.._ARM_*` and
 * restates the selection from the raw width code and register number. The two
 * must agree; the generated `_Static_assert`s additionally pin the hand-written
 * `X86_OP_MOV_REG` / `X86_WIDTH_*` / `X86_RSP` decodes to the generated table
 * at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_mov_reg_arm_host.c -o /tmp/t_mov_reg_arm
 *   /tmp/t_mov_reg_arm
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. */
#define X86_OP_MOV_REG 0x02U
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
#define X86_RAX 0U
#define X86_RSP 4U

#include "generated/x86_mov_reg_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent selection: the stack-base body exactly at the full 64-bit
 * width code with the stack pointer as source, the provenance pointer body at
 * the full width code with any other source, and the narrow body at every other
 * width code, whatever the source. The arm codes are restated as literals so
 * the model is independent of the generated `.._ARM_*` values. */
static unsigned model_arm(unsigned width, unsigned rsp)
{
	if (width != X86_WIDTH_64)
		return 2;      /* narrow */
	if (rsp == X86_RSP)
		return 0;      /* stack pointer */
	return 1;              /* pointer */
}

int main(void)
{
	unsigned width;
	unsigned rsp;

	cases++;
	if (KPROG_X86_MOV_REG_ARM_COUNT != 3U) {
		printf("MISMATCH count got=%u want=3\n",
		       (unsigned)KPROG_X86_MOV_REG_ARM_COUNT);
		failures++;
	}

	cases++;
	if (X86_OP_MOV_REG != 0x02U || X86_WIDTH_64 != 8U || X86_RSP != 4U) {
		printf("MISMATCH decode opcode=%u width64=%u rsp=%u\n",
		       (unsigned)X86_OP_MOV_REG, (unsigned)X86_WIDTH_64,
		       (unsigned)X86_RSP);
		failures++;
	}

	cases++;
	if (KPROG_X86_MOV_REG_ARM_STACK_PTR == KPROG_X86_MOV_REG_ARM_POINTER ||
	    KPROG_X86_MOV_REG_ARM_POINTER == KPROG_X86_MOV_REG_ARM_NARROW ||
	    KPROG_X86_MOV_REG_ARM_STACK_PTR == KPROG_X86_MOV_REG_ARM_NARROW) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	/* The selector returns the body the independent model names, over the
	 * whole byte range of both the width code and the register number. */
	for (width = 0; width <= 0xffU; width++) {
		for (rsp = 0; rsp <= 0xffU; rsp++) {
			unsigned got = KPROG_X86_MOV_REG_ARM((__u8)width,
							     (__u8)rsp);
			unsigned want = model_arm(width, rsp);

			cases++;
			if (got != want) {
				printf("MISMATCH arm width=%u rsp=%u got=%u "
				       "want=%u\n", width, rsp, got, want);
				failures++;
			}
		}
	}

	/* Each width/register pair reaches its own body, and the narrow widths
	 * ignore the source register entirely. */
	cases++;
	if (KPROG_X86_MOV_REG_ARM(X86_WIDTH_64, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_STACK_PTR ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_64, X86_RAX) !=
		    KPROG_X86_MOV_REG_ARM_POINTER ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_32, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_NARROW ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_8, X86_RAX) !=
		    KPROG_X86_MOV_REG_ARM_NARROW ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_8, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_NARROW ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_16, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_NARROW ||
	    KPROG_X86_MOV_REG_ARM(0U, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_NARROW) {
		printf("MISMATCH arm selection drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 mov_reg arm host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 mov_reg arm host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
