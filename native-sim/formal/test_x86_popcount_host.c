/*
 * Host cross-check for the generated x86 POPCNT contract.
 *
 * Verifies kprog_x86_popcount_value from generated/x86_popcount.h against an
 * independent oracle that counts set bits with a one-bit-at-a-time walk (never
 * the macro's SWAR reduction). It sweeps boundary words, then a fixed-seed random
 * sweep, and checks the count never exceeds 64 and is additively consistent
 * (popcount(a) + popcount(b) == popcount(a) + popcount(b) is trivial; instead it
 * checks popcount(x & ~y) + popcount(x & y) == popcount(x)). Exits non-zero on
 * any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_popcount_host.c -o /tmp/t_pop && /tmp/t_pop
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/* The generated header defines __always_inline functions for the in-kernel
 * build; provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#include "generated/x86_popcount.h"

#include <stdio.h>

/* Independent oracle: one-bit-at-a-time walk. */
static __u64 popcount_oracle(__u64 value)
{
	__u64 n = 0;

	for (unsigned i = 0; i < 64; i++)
		n += (value >> i) & 1ULL;
	return n;
}

static int check_popcount(__u64 value)
{
	__u64 res = kprog_x86_popcount_value(value);
	__u64 want = popcount_oracle(value);

	if (res != want) {
		printf("MISMATCH value=%#llx res=%llu want=%llu\n",
		       value, res, want);
		return 1;
	}
	if (res > 64) {
		printf("MISMATCH value=%#llx count exceeds 64: %llu\n",
		       value, res);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x1ULL, 0x8000000000000000ULL,
	0x5555555555555555ULL, 0xaaaaaaaaaaaaaaaaULL,
	0x0123456789abcdefULL, 0xffff0000ffff0000ULL, 0xf0f0f0f0f0f0f0f0ULL,
};

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x8e27c4a1f60d3b95ULL;

	for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++) {
		fails += check_popcount(values[v]);
		cases++;
	}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 value, other;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		value = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		other = state;
		fails += check_popcount(value);
		cases++;
		/* Additive consistency: counting the disjoint parts of `value` split
		 * by `other` sums to counting `value` itself. */
		if (kprog_x86_popcount_value(value & ~other) +
		    kprog_x86_popcount_value(value & other) !=
		    popcount_oracle(value)) {
			printf("MISMATCH split value=%#llx other=%#llx\n",
			       value, other);
			fails++;
		}
		cases++;
	}

	if (fails) {
		printf("x86 popcount host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 popcount host cross-check: OK (%u cases)\n", cases);
	return 0;
}
