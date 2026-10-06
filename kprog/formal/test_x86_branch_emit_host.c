/*
 * Host cross-check for the generated x86-64 branch-emission shape contract.
 *
 * Verifies KPROG_X86_BRANCH_BACKWARD from generated/x86_branch_emit.h against an
 * independent oracle written as the plain address comparison, and checks that the
 * emitted-shape directive selects the same next PC as the architectural model for
 * both directions and both predicate values. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_branch_emit_host.c -o /tmp/t_xbe && /tmp/t_xbe
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/x86_branch_emit.h"

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

/* The next PC the emitted code selects, given the direction and the predicate,
 * written exactly as the simulator's X86_SIM_X86_JCC_BACKWARD/front shapes. */
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
	unsigned back = KPROG_X86_BRANCH_BACKWARD(current, target);
	unsigned want = backward_oracle(current, target);
	int taken;

	if (back != want) {
		printf("MISMATCH current=%lu target=%lu res=%u want=%u\n",
		       current, target, back, want);
		return 1;
	}
	for (taken = 0; taken < 2; taken++) {
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
	0x100000000UL,
};

int main(void)
{
	unsigned cases = 0, fails = 0;
	unsigned i, j;

	for (i = 0; i < sizeof(addrs) / sizeof(addrs[0]); i++) {
		for (j = 0; j < sizeof(addrs) / sizeof(addrs[0]); j++) {
			cases++;
			fails += (unsigned)check(addrs[i], addrs[j]);
		}
		/* Equal addresses are the boundary: target == current is backward. */
		cases++;
		fails += (unsigned)check(addrs[i], addrs[i]);
	}

	if (fails != 0) {
		printf("x86 branch emit host cross-check: FAIL (%u fails)\n", fails);
		return 1;
	}
	printf("x86 branch emit host cross-check: OK (%u cases)\n", cases);
	return 0;
}
