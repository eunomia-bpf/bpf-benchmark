/*
 * Host cross-check for the AArch64 vector lane extra-offset contract
 * (STEP 0141).
 *
 * The module under test is `generated/arm64_dq_mem_extra.h`. It fixes the
 * per-lane extra byte offset the vector memory step `ARM64_SIM_L_DQ_MEM_STEP`
 * adds to each moved lane's address, selected from a single closed pair of
 * facts: whether the lane is the first plan position and whether the transfer
 * has a high lane at all. The first-lane offset is zero, the high-lane offset
 * is one 64-bit lane stride above the low lane (the `.Q0` second position), and
 * the single-lane offset is zero when the transfer plans only one position.
 * This oracle drives the contract's `KPROG_ARM64_DQ_MEM_EXTRA` and restates the
 * 3-way selection from the raw fact pair with no reference to the generated
 * selector. The two must agree; the generated `_Static_assert`s additionally
 * pin the outcome codes, the offset bytes and each of the four selector arms at
 * compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_dq_mem_extra_host.c \
 *       -o /tmp/t_dq_extra
 *   /tmp/t_dq_extra
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

/* The extra-offset contract composes the DQ lane stride, so the DQ contract's
 * opcode/lane/stride defines must be in scope first. */
#define ARM64_WIDTH_64 8U
#define ARM64_OP_LOAD_D0 0x28U
#define ARM64_OP_STORE_D0 0x29U
#define ARM64_OP_LOAD_Q0 0x2aU
#define ARM64_OP_STORE_Q0 0x2bU

#include "generated/arm64_dq_mem.h"
#include "generated/arm64_dq_mem_extra.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent 3-way extra-offset selection: the first-lane offset exactly
 * when the lane is the first plan position, the high-lane offset at every later
 * position of a transfer that has a high lane, and the single-lane offset when
 * the transfer has only one position. Restated from the raw fact pair. */
static __s64 model_extra(unsigned is_first_lane, unsigned has_high_lane)
{
	if (is_first_lane)
		return 0;
	if (has_high_lane)
		return (__s64)KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE;
	return 0;
}

int main(void)
{
	unsigned is_first_lane;
	unsigned has_high_lane;

	cases++;
	if (KPROG_ARM64_DQ_MEM_EXTRA_COUNT != 3U) {
		printf("MISMATCH outcome count got=%u want=3\n",
		       (unsigned)KPROG_ARM64_DQ_MEM_EXTRA_COUNT);
		failures++;
	}

	/* The outcome-code defines name the three distinct codes. */
	cases++;
	if (KPROG_ARM64_DQ_MEM_EXTRA_FIRST_LANE_BYTES != 0U ||
	    KPROG_ARM64_DQ_MEM_EXTRA_HIGH_LANE_BYTES != 1U ||
	    KPROG_ARM64_DQ_MEM_EXTRA_SINGLE_LANE_BYTES != 2U) {
		printf("MISMATCH outcome code defines drift\n");
		failures++;
	}

	/* The offset defines name the two base offsets and the one lane-stride
	 * offset. */
	cases++;
	if (KPROG_ARM64_DQ_MEM_EXTRA_FIRST_LANE_BYTES_OFFSET != 0U ||
	    KPROG_ARM64_DQ_MEM_EXTRA_HIGH_LANE_BYTES_OFFSET !=
		KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE ||
	    KPROG_ARM64_DQ_MEM_EXTRA_SINGLE_LANE_BYTES_OFFSET != 0U) {
		printf("MISMATCH offset defines drift\n");
		failures++;
	}

	/* The full selection table: the closed fact pair crossed against the
	 * independent 3-way statement. */
	for (is_first_lane = 0; is_first_lane <= 1U; is_first_lane++) {
		for (has_high_lane = 0; has_high_lane <= 1U; has_high_lane++) {
			__s64 got = KPROG_ARM64_DQ_MEM_EXTRA(is_first_lane,
							     has_high_lane);
			__s64 want = model_extra(is_first_lane,
						 has_high_lane);

			cases++;
			if (got != want) {
				printf("MISMATCH extra first=%u high=%u "
				       "got=%lld want=%lld\n", is_first_lane,
				       has_high_lane, (long long)got,
				       (long long)want);
				failures++;
			}
		}
	}

	/* The selector is a plain expression in its inputs: feeding the facts
	 * the step actually computes (the lane position test and the lane-count
	 * test) at each lane count must reach the same offsets. */
	{
		static const unsigned lane_counts[] = { 1U, 2U, 3U, 0U };

		unsigned li;

		for (li = 0; li < sizeof(lane_counts) / sizeof(lane_counts[0]);
		     li++) {
			unsigned p;

			for (p = 0; p < 3U; p++) {
				unsigned first = (p == 0U);
				unsigned high = (lane_counts[li] > 1U);

				cases++;
				if (KPROG_ARM64_DQ_MEM_EXTRA(first, high) !=
				    model_extra(first, high)) {
					printf("MISMATCH lane pos=%u "
					       "count=%u\n", p,
					       lane_counts[li]);
					failures++;
				}
			}
		}
	}

	/* The high-lane offset is exactly the DQ contract's high lane stride. */
	cases++;
	if (KPROG_ARM64_DQ_MEM_EXTRA(0, 1) !=
	    (__s64)KPROG_ARM64_DQ_MEM_HIGH_LANE_STRIDE) {
		printf("MISMATCH high lane not the DQ lane stride\n");
		failures++;
	}

	/* The first-lane and single-lane offsets are the base offset, so a
	 * dropped or added lane plan never shifts the first lane. */
	cases++;
	if (KPROG_ARM64_DQ_MEM_EXTRA(1, 1) != 0 ||
	    KPROG_ARM64_DQ_MEM_EXTRA(1, 0) != 0 ||
	    KPROG_ARM64_DQ_MEM_EXTRA(0, 0) != 0) {
		printf("MISMATCH base offset not zero\n");
		failures++;
	}

	if (failures != 0) {
		printf("arm64 dq mem extra host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 dq mem extra host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
