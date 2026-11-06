/*
 * Host cross-check for the generated whole-program control-flow trace contract.
 *
 * Verifies the generated fold `KPROG_CONTROL_FLOW_EDGE_NEXT` over a path of
 * conditional edges against an independent architectural walk written as the
 * plain `taken ? target : pc + 1` arithmetic -- the C counterpart of the Lean
 * `archWalk`. At every edge the walk also recomputes the direction from the
 * running program counter (exactly as the simulator calls
 * `KPROG_X86_BRANCH_BACKWARD` per conditional transfer) and checks it against
 * the independent address-ordering oracle, then selects the next PC through both
 * emitted goto/fall-through shapes and through the generated macro, so a body
 * that inverts the direction test, applies a wrong fall-through advance, inverts
 * the taken predicate on either shape, or fails to thread the program counter
 * between edges is numerically distinguishable. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_control_flow_trace_host.c -o /tmp/t_cft && /tmp/t_cft
 */

typedef unsigned char __u8;

#include "generated/control_flow_trace.h"

#include <stdio.h>

/* This oracle exercises the generated edge fold through the X86 direction macro
 * (declared locally so the file builds with -I. only, without the full sim). */
#define KPROG_X86_BRANCH_BACKWARD(CURRENT, TARGET)		\
	((__u8)(((TARGET) <= (CURRENT)) ? 1 : 0))

static unsigned long fails;

/* Independent architectural next PC at one edge: target when taken, the next
 * program counter otherwise. */
static unsigned long arch_edge(int taken, unsigned long pc, unsigned long target)
{
	return taken ? target : pc + 1UL;
}

/* Independent architectural walk of a whole trace. */
static unsigned long arch_walk(unsigned long pc, const unsigned char *taken,
			       const unsigned long *target, unsigned n)
{
	unsigned i;

	for (i = 0; i < n; i++)
		pc = arch_edge(taken[i], pc, target[i]);
	return pc;
}

/* The next PC the emitted backward edge selects: `if (!taken) goto fallthrough;
 * goto target;` -- the fall-through resume is the generated sequential step. */
static unsigned long backward_pc(int taken, unsigned long pc, unsigned long target)
{
	unsigned long fallthrough = pc + KPROG_CONTROL_FLOW_SEQUENTIAL_STEP;

	if (!taken)
		return fallthrough;
	return target;
}

/* The next PC the emitted forward edge selects: `if (taken) goto target;` with a
 * fall-through. */
static unsigned long forward_pc(int taken, unsigned long pc, unsigned long target)
{
	unsigned long fallthrough = pc + KPROG_CONTROL_FLOW_SEQUENTIAL_STEP;

	return taken ? target : fallthrough;
}

/* The emitted walk: fold the generated edge macro, recomputing the direction
 * from the running program counter at every edge and cross-checking the two
 * emitted shapes and the independent ordering oracle. */
static unsigned long emitted_walk(unsigned long pc, const unsigned char *taken,
				  const unsigned long *target, unsigned n)
{
	unsigned i;

	for (i = 0; i < n; i++) {
		unsigned back = KPROG_X86_BRANCH_BACKWARD(pc, target[i]);
		unsigned want_back = target[i] <= pc ? 1U : 0U;
		unsigned long next = KPROG_CONTROL_FLOW_EDGE_NEXT(
			taken[i], pc, target[i]);

		if (back != want_back) {
			printf("MISMATCH direction pc=%lu target=%lu got=%u "
			       "want=%u\n", pc, target[i], back, want_back);
			fails++;
		}
		if (next != backward_pc(taken[i], pc, target[i]) ||
		    next != forward_pc(taken[i], pc, target[i])) {
			printf("MISMATCH shape pc=%lu target=%lu taken=%u "
			       "next=%lu\n", pc, target[i], taken[i], next);
			fails++;
		}
		pc = next;
	}
	return pc;
}

static const unsigned long addrs[] = {
	0UL, 1UL, 2UL, 3UL, 0x100UL, 0x1000UL, 0x100000000UL, 0xffffffffffffffffUL,
};

static unsigned long lcg_state = 0x2545f491UL;

static unsigned long lcg(void)
{
	lcg_state = lcg_state * 1103515245UL + 12345UL;
	return lcg_state >> 8;
}

int main(void)
{
	unsigned char taken[64];
	unsigned long target[64];
	unsigned cases = 0;
	unsigned len, t, trial;

	/* The fall-through advance must be the architectural one (one PC). */
	if (KPROG_CONTROL_FLOW_SEQUENTIAL_STEP != 1U) {
		printf("MISMATCH sequential step = %u\n",
		       (unsigned)KPROG_CONTROL_FLOW_SEQUENTIAL_STEP);
		fails++;
	}

	for (len = 0; len <= 12; len++) {
		for (trial = 0; trial < 64; trial++) {
			unsigned long start = addrs[trial % 8];
			unsigned long got, want;

			for (t = 0; t < len; t++) {
				taken[t] = (unsigned char)(lcg() & 1U);
				target[t] = addrs[lcg() % 8];
				if ((lcg() & 3U) == 0U)
					target[t] = start; /* equality edge */
			}
			got = emitted_walk(start, taken, target, len);
			want = arch_walk(start, taken, target, len);
			cases++;
			if (got != want) {
				printf("MISMATCH len=%u start=%lu got=%lu "
				       "want=%lu\n", len, start, got, want);
				fails++;
			}
		}
	}

	/* All-fall-through: the walk advances by exactly the trace length. */
	{
		unsigned long got, want;

		for (len = 0; len <= 12; len++) {
			for (t = 0; t < len; t++) {
				taken[t] = 0U;
				target[t] = 0xdeadUL; /* ignored on fall-through */
			}
			got = emitted_walk(0x1000UL, taken, target, len);
			want = 0x1000UL + len;
			cases++;
			if (got != want) {
				printf("MISMATCH fallthrough len=%u got=%lu "
				       "want=%lu\n", len, got, want);
				fails++;
			}
		}
	}

	if (fails != 0) {
		printf("control flow trace host cross-check: FAIL (%lu)\n",
		       fails);
		return 1;
	}
	printf("control flow trace host cross-check: OK (%u cases)\n", cases);
	return 0;
}
