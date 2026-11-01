/*
 * Cross-ISA differential cross-check: the same input through both simulators'
 * compiled contracts.
 *
 * `CrossIsaWidth.lean` and `CrossIsaStackArena.lean` prove the two generated
 * Lean contracts agree. Those theorems say nothing about the C the simulators
 * actually trade in: each ISA has its own generated header, and a generator
 * that rendered the Lean and the C from one spec could still emit C that
 * disagrees where the Lean does not -- or the hand-written C could drift from
 * its own Lean. This oracle includes both simulators in one translation unit
 * (they coexist, since every decode is ISA-prefixed) and compares the compiled
 * macros on shared inputs.
 *
 * Two families:
 *
 *   widths  the four width codes' masks and bit counts, over values that
 *           exercise each boundary (zero, all-ones, the sign bits, a pattern
 *           with every lane distinct).
 *
 *   stack   the access-window and pointer bounds over a capacity/index/width
 *           grid that includes both arenas' real sizes (64, 128, 160) and the
 *           one-past-end indices. The two ISAs have different arena geometry
 *           -- x86 biases by the capacity, arm64 by 96 -- but the *bound* is
 *           a function of capacity alone, so the two must agree.
 *
 * Exit 1 on any difference.
 *
 * Build/run (from kprog/formal):
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      cross_isa_differential_host.c -o /tmp/t_xdiff
 *   /tmp/t_xdiff
 */
#define ARM64_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK 1

#include "arm64_sim_local_bpf.h"
#include "x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static int cases;

static void cmp_u64(const char *what, unsigned long long a,
		    unsigned long long x)
{
	cases++;
	if (a != x) {
		printf("DIFF %s: arm64=%#llx x86=%#llx\n", what, a, x);
		failures++;
	}
}

static void cmp_int(const char *what, int a, int x)
{
	cases++;
	if (a != x) {
		printf("DIFF %s: arm64=%d x86=%d\n", what, a, x);
		failures++;
	}
}

/* The shared width codes and the values that exercise each boundary. */
static void check_widths(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 0xffULL, 0x123456789abcdefULL, ~0ULL,
		0x80000000ULL, 0x7fffffffULL, 0x80ULL, 0x8000ULL,
	};
	unsigned i;

	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
		cmp_u64("w8 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_8) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_8) & values[i]);
		cmp_u64("w16 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_16) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_16) & values[i]);
		cmp_u64("w32 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_32) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_32) & values[i]);
		cmp_u64("w64 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_64) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_64) & values[i]);
	}

	cmp_u64("bits w8", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_8),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_8));
	cmp_u64("bits w16", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_16),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_16));
	cmp_u64("bits w32", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_32),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_32));
	cmp_u64("bits w64", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_64),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_64));

	/* The sign masks are the one non-obvious pair: each ISA must place the
	 * sign bit at its own width, so a drift here is a signedness bug. */
	cmp_u64("sign w8", KPROG_ARM64_WIDTH_SIGN_MASK(ARM64_WIDTH_8),
		KPROG_X86_WIDTH_SIGN_MASK(X86_WIDTH_8));
	cmp_u64("sign w32", KPROG_ARM64_WIDTH_SIGN_MASK(ARM64_WIDTH_32),
		KPROG_X86_WIDTH_SIGN_MASK(X86_WIDTH_32));
	cmp_u64("sign w64", KPROG_ARM64_WIDTH_SIGN_MASK(ARM64_WIDTH_64),
		KPROG_X86_WIDTH_SIGN_MASK(X86_WIDTH_64));
}

/* The shared stack bounds, over both arenas' real sizes and the edges. */
static void check_stack_bounds(void)
{
	static const unsigned capacities[] = { 1U, 8U, 64U, 128U, 160U };
	static const unsigned indices[] = {
		0U, 1U, 7U, 8U, 56U, 63U, 64U, 120U, 152U, 159U, 160U, 161U
	};
	static const unsigned widths[] = { 1U, 2U, 4U, 8U };
	unsigned c, i, w;

	for (c = 0; c < sizeof(capacities) / sizeof(capacities[0]); c++)
		for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++)
			for (w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
				cmp_int("window fits",
					KPROG_ARM64_STACK_WINDOW_FITS(
						indices[i], widths[w],
						capacities[c]),
					KPROG_X86_STACK_WINDOW_FITS(
						indices[i], widths[w],
						capacities[c]));

	for (c = 0; c < sizeof(capacities) / sizeof(capacities[0]); c++)
		for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++)
			cmp_int("pointer fits",
				KPROG_ARM64_STACK_POINTER_FITS(
					(long)indices[i], capacities[c]),
				KPROG_X86_STACK_POINTER_FITS(
					(long)indices[i], capacities[c]));

	/* The word-slot and alignment arithmetic the fast path depends on. */
	for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
		cmp_u64("word index",
			KPROG_ARM64_STACK_WORD_INDEX(indices[i]),
			KPROG_X86_STACK_WORD_INDEX(indices[i]));
		cmp_int("word aligned",
			KPROG_ARM64_STACK_WORD_ALIGNED(indices[i]),
			KPROG_X86_STACK_WORD_ALIGNED(indices[i]));
	}
	for (c = 0; c < sizeof(capacities) / sizeof(capacities[0]); c++)
		cmp_u64("words",
			KPROG_ARM64_STACK_WORDS(capacities[c]),
			KPROG_X86_STACK_WORDS(capacities[c]));
}

/*
 * The one flag the two architectures define in opposite polarities.
 *
 * AArch64's subtract carry is not-borrow (`lhs >= rhs`), x86-64's is borrow
 * (`lhs < rhs`); `CrossIsaFlags.lean` proves the two complements. This pins
 * the same relation at the layer that compiles, and pins the three flags that
 * *should* agree (zero, sign, overflow) alongside it -- a drift in any of them
 * would be a real bug rather than an architectural difference.
 */
static void check_flags(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 2ULL, 0xffULL, 0x80ULL, 0x100ULL,
		0x7fffffffULL, 0x80000000ULL, 0xffffffffULL,
		0x123456789abcdefULL, ~0ULL, 0x8000000000000000ULL,
	};
	static const unsigned wids[] = { 1U, 2U, 4U, 8U };
	unsigned i, j, w;

	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
		for (j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
			for (w = 0; w < sizeof(wids) / sizeof(wids[0]); w++) {
				unsigned a_n, a_z, a_c, a_v;
				unsigned x_cf, x_zf, x_sf, x_of;
				unsigned long long a, b, sign;

				a = values[i];
				b = values[j];

				KPROG_ARM64_SET_SUB_FLAGS(a_n, a_z, a_c, a_v, a, b, wids[w]);
				sign = KPROG_X86_WIDTH_SIGN_MASK(wids[w]);
				KPROG_X86_SET_SUB_FLAGS(x_cf, x_zf, x_sf, x_of,
							a & KPROG_X86_WIDTH_MASK(wids[w]),
							b & KPROG_X86_WIDTH_MASK(wids[w]),
							(a - b) & KPROG_X86_WIDTH_MASK(wids[w]),
							sign);

				/* carry is deliberately opposite */
				cmp_int("carry complements", a_c, !x_cf);
				/* these three are not */
				cmp_int("zero agrees", !!a_z, !!x_zf);
				cmp_int("sign agrees", !!a_n, !!x_sf);
				cmp_int("overflow agrees", !!a_v, !!x_of);
			}
		}
	}
}

int main(void)
{
	check_widths();
	check_stack_bounds();
	check_flags();

	if (failures) {
		printf("cross-ISA differential cross-check: FAIL (%d/%d)\n",
		       failures, cases);
		return 1;
	}
	printf("cross-ISA differential cross-check: OK (%d cases)\n", cases);
	return 0;
}