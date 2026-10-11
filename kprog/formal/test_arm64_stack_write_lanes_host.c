/*
 * Host cross-check for the AArch64 stack byte-ladder per-lane activation
 * contract (STEP 0124).
 *
 * The module under test is `generated/arm64_stack_write_lanes.h`. It fixes the
 * lanes the simulator's `ARM64_SIM_L_STACK_WRITE_TAG` helper writes through its
 * little-endian byte ladder: an access of `n` bytes writes exactly the lanes
 * `0..n-1`, so the width's active-lane mask has its low `n` bits set (`1`, `3`,
 * `15`, `255`). The helper previously gated each lane by hand as `width >= 16`,
 * `width >= 32`, `width == 64`, and this oracle drives the contract's
 * `KPROG_ARM64_STACK_WRITE_MASK` / `.._LANE_COUNT` / `.._LANE_ACTIVE` and
 * restates the activation from the raw width code and lane number. The two must
 * agree; the generated `_Static_assert`s additionally pin the hand-written
 * `ARM64_WIDTH_*` decodes to the generated table at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stack_write_lanes_host.c -o /tmp/t_swl
 *   /tmp/t_swl
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to. */
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_stack_write_lanes.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent byte count of a width code: the low-bit set size the ladder
 * writes. Restated as literals so the model is independent of the generated
 * `.._LANE_COUNT` values. */
static unsigned model_count(unsigned width)
{
	if (width == ARM64_WIDTH_8)
		return 1;
	if (width == ARM64_WIDTH_16)
		return 2;
	if (width == ARM64_WIDTH_32)
		return 4;
	return 8;
}

/* The independent active-lane mask: the low `count` bits set. */
static unsigned model_mask(unsigned width)
{
	return (1U << model_count(width)) - 1U;
}

/* The independent activation: lane `k` is written exactly when its number is
 * below the width's byte count, the monotone bound the four hand-written gates
 * recomputed. */
static unsigned model_active(unsigned width, unsigned lane)
{
	return (lane < model_count(width)) ? 1U : 0U;
}

static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned wi, lane, width;

	cases++;
	if (KPROG_ARM64_STACK_WRITE_LANE_SLOTS != 8U) {
		printf("MISMATCH slot count got=%u want=8\n",
		       (unsigned)KPROG_ARM64_STACK_WRITE_LANE_SLOTS);
		failures++;
	}

	/* The lane-number defines name the eight distinct byte positions. */
	cases++;
	if (KPROG_ARM64_STACK_WRITE_LANE0 != 0U ||
	    KPROG_ARM64_STACK_WRITE_LANE1 != 1U ||
	    KPROG_ARM64_STACK_WRITE_LANE2 != 2U ||
	    KPROG_ARM64_STACK_WRITE_LANE3 != 3U ||
	    KPROG_ARM64_STACK_WRITE_LANE4 != 4U ||
	    KPROG_ARM64_STACK_WRITE_LANE5 != 5U ||
	    KPROG_ARM64_STACK_WRITE_LANE6 != 6U ||
	    KPROG_ARM64_STACK_WRITE_LANE7 != 7U) {
		printf("MISMATCH lane defines drift\n");
		failures++;
	}

	/* The full activation table: every width code crossed with every lane,
	 * against the independent bound. */
	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		width = widths[wi];
		for (lane = 0; lane < 8U; lane++) {
			unsigned got =
				KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(width, lane);
			unsigned want = model_active(width, lane);

			cases++;
			if (got != want) {
				printf("MISMATCH active width=%u lane=%u "
				       "got=%u want=%u\n", width, lane, got,
				       want);
				failures++;
			}
		}
	}

	/* The whole byte range of the width code, so a code outside the four
	 * ARM64_WIDTH_* values cannot silently disagree with the model: the mask
	 * chain's fall-through is the widest width, and the model treats every
	 * other code the same. */
	for (width = 0; width <= 0xffU; width++) {
		cases++;
		if (KPROG_ARM64_STACK_WRITE_MASK(width) != model_mask(width) ||
		    KPROG_ARM64_STACK_WRITE_LANE_COUNT(width) !=
		    model_count(width)) {
			printf("MISMATCH fall-through code=%u mask=%u count=%u\n",
			       width,
			       (unsigned)KPROG_ARM64_STACK_WRITE_MASK(width),
			       (unsigned)KPROG_ARM64_STACK_WRITE_LANE_COUNT(
				       width));
			failures++;
		}
	}

	/* Each width reaches its own activation at lane 0 and only the doubleword
	 * reaches the top lane, tying the mask to the lane defines. */
	cases++;
	if (KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_8, 0) != 1U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_16, 1) != 1U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_16, 2) != 0U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_32, 3) != 1U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_32, 4) != 0U ||
	    KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(ARM64_WIDTH_64, 7) != 1U) {
		printf("MISMATCH activation drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("arm64 stack write lanes host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 stack write lanes host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
