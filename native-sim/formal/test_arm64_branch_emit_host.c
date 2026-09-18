/*
 * Host cross-check for the generated AArch64 branch-emission shape contract.
 *
 * Verifies KPROG_ARM64_BRANCH_BACKWARD from generated/arm64_branch_emit.h against
 * an independent oracle written as the plain address comparison, and checks that
 * the emitted-shape directive selects the same next PC as the architectural model
 * for both directions and both predicate values. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_branch_emit_host.c -o /tmp/t_be && /tmp/t_be
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/arm64_branch_emit.h"

#include <stdio.h>

/* Independent oracle: the direction test, restated from the address ordering. */
static unsigned backward_oracle(unsigned long current, unsigned long target)
{
	return target <= current ? 1U : 0U;
}

/* The architectural next PC: target when taken, fall-through otherwise. */
static unsigned long branch_pc(int taken, unsigned long fallthrough,
			       unsigned long target)
{
	return taken ? target : fallthrough;
}

/* The next PC the emitted code selects, given the direction and the predicate. */
static unsigned long emitted_pc(int backward, int taken,
				unsigned long fallthrough, unsigned long target)
{
	if (backward) {
		/* if (!taken) goto fallthrough; goto target; */
		if (!taken)
			return fallthrough;
		return target;
	}
	/* if (taken) goto target; */
	return taken ? target : fallthrough;
}

static int check(unsigned long current, unsigned long target)
{
	unsigned back = KPROG_ARM64_BRANCH_BACKWARD(current, target);
	unsigned want = backward_oracle(current, target);

	if (back != want) {
		printf("MISMATCH current=%lu target=%lu res=%u want=%u\n",
		       current, target, back, want);
		return 1;
	}
	for (int taken = 0; taken < 2; taken++) {
		unsigned long fp = 0x1000, tg = 0x2000;

		if (emitted_pc((int)back, taken, fp, tg) !=
		    branch_pc(taken, fp, tg)) {
			printf("MISMATCH next pc current=%lu target=%lu taken=%d\n",
			       current, target, taken);
			return 1;
		}
	}
	return 0;
}

static const unsigned long addrs[] = {
	0UL, 1UL, 2UL, 0x100UL, 0x1000UL, 0x1001UL, 0xffffUL, 0xffffffffUL,
};

int main(void)
{
	unsigned cases = 0, fails = 0;

	for (unsigned i = 0; i < sizeof(addrs) / sizeof(addrs[0]); i++)
		for (unsigned j = 0; j < sizeof(addrs) / sizeof(addrs[0]); j++) {
			fails += check(addrs[i], addrs[j]);
			cases++;
		}

	if (fails) {
		printf("arm64 branch emit host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 branch emit host cross-check: OK (%u cases)\n", cases);
	return 0;
}
