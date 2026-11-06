/*
 * Host cross-check for the AArch64 write-register width body-selection contract
 * (STEP 0144).
 *
 * The module under test is `generated/arm64_write_arm.h`. It fixes the writeback
 * body the simulator's `ARM64_SIM_L_WRITE_REG_WIDTH` helper selects between from
 * a single closed fact: whether the access width code is the 32-bit code. The
 * helper first masks its value to the width (`KPROG_ARM64_APPLY_WIDTH`, owned by
 * `generated/arm64_width.h`), then either writes the full masked value back or
 * truncates it to 32 bits. Because the value is masked before the choice, the
 * two bodies are observationally equal for every width the simulator reaches,
 * so only the selector code and the body assignment matter. This oracle drives
 * the contract's `KPROG_ARM64_WRITE_ARM` / `.._COUNT` / `.._ARM_*` and restates
 * the 2-way body selection from the raw width fact with no reference to the
 * generated selector. The two must agree; the generated `_Static_assert`s
 * additionally pin the hand-written `ARM64_WIDTH_32` decode to the generated
 * table at compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_write_arm_host.c -o /tmp/t_awrite_arm
 *   /tmp/t_awrite_arm
 */
typedef unsigned char __u8;

/* The hand-written decode the generated drift check binds to. */
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_write_arm.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 2-way writeback-body selection: the 32-bit truncating body
 * exactly when the access width code is the 32-bit code, the full-value body
 * otherwise. The arm codes are restated as literals so the model is independent
 * of the generated `.._ARM_*` values. */
static unsigned model_arm(unsigned is_w32)
{
	if (is_w32)
		return 1;      /* narrow */
	return 0;              /* full */
}

int main(void)
{
	unsigned is_w32;

	cases++;
	if (KPROG_ARM64_WRITE_ARM_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_ARM64_WRITE_ARM_COUNT);
		failures++;
	}

	cases++;
	if (ARM64_WIDTH_32 != KPROG_ARM64_WRITE_ARM_W32 ||
	    KPROG_ARM64_WRITE_ARM_W32 != 4U) {
		printf("MISMATCH decode width32=%u arm_width32=%u\n",
		       (unsigned)ARM64_WIDTH_32,
		       (unsigned)KPROG_ARM64_WRITE_ARM_W32);
		failures++;
	}

	cases++;
	if (KPROG_ARM64_WRITE_ARM_FULL == KPROG_ARM64_WRITE_ARM_NARROW) {
		printf("MISMATCH arm codes not distinct\n");
		failures++;
	}

	/* The selector returns the body the independent model names, over the
	 * whole byte range of the width fact. */
	for (is_w32 = 0; is_w32 <= 0xffU; is_w32++) {
		unsigned got = KPROG_ARM64_WRITE_ARM((__u8)is_w32);
		unsigned want = model_arm(is_w32);

		cases++;
		if (got != want) {
			printf("MISMATCH arm is_w32=%u got=%u want=%u\n",
			       is_w32, got, want);
			failures++;
		}
	}

	/* Each fact reaches its own body: the width code equal to the 32-bit code
	 * reaches the narrow truncating body, and every other width code — the
	 * 8/16-bit codes, the 64-bit code and the absent code — reaches the
	 * full-value body. Both inputs are the closed fact the helper passes — a
	 * comparison of the resolved width code against the 32-bit code — not the
	 * raw width code. */
	cases++;
	if (KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_32 == ARM64_WIDTH_32) !=
		    KPROG_ARM64_WRITE_ARM_NARROW ||
	    KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_8 == ARM64_WIDTH_32) !=
		    KPROG_ARM64_WRITE_ARM_FULL ||
	    KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_16 == ARM64_WIDTH_32) !=
		    KPROG_ARM64_WRITE_ARM_FULL ||
	    KPROG_ARM64_WRITE_ARM(ARM64_WIDTH_64 == ARM64_WIDTH_32) !=
		    KPROG_ARM64_WRITE_ARM_FULL ||
	    KPROG_ARM64_WRITE_ARM(0U == ARM64_WIDTH_32) !=
		    KPROG_ARM64_WRITE_ARM_FULL) {
		printf("MISMATCH arm selection drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("arm64 write arm host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 write arm host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
