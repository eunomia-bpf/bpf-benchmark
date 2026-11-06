/*
 * Cross-check the width-mask fallback for codes outside the four widths.
 *
 * The generated C width contract resolves a mask through a chained ternary
 * whose final arm is the 64-bit mask:
 *
 *   MASK(W) = W==8 ? 0xff : W==16 ? 0xffff : W==32 ? 0xffffffff : ~0
 *
 * so *every* code that is not one of the four width codes -- the absent code
 * 0, the opcodes that reuse the field (`X86_OP_XCHG` is 25, `X86_OP_BZHI` is
 * 30), and any future drift -- silently resolves to 64 bits. The Lean model
 * is a total function over the four constructors and has no notion of an
 * invalid code, so that fallback is outside the typed model.
 *
 * This oracle pins the C behaviour so the gap is a stated, tested fact rather
 * than an inference: the four valid codes resolve to their own mask and bit
 * count, and a representative set of invalid codes all resolve to 64.
 *
 * Exit 1 on any deviation.
 *
 * Build/run (from kprog/formal):
 *   cc -Wall -Wextra -O2 -I. width_fallback_host.c -o /tmp/t_wfb
 *   /tmp/t_wfb
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/* The generated header asserts against the simulator's X86_WIDTH_*
 * decode, so it is included after that decode rather than alone. */
#define X86_SIM_ENABLE_STACK 1
#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static int cases;

static void check(__u32 code, __u64 want_mask, __u32 want_bits)
{
	cases++;
	if (KPROG_X86_WIDTH_MASK(code) != want_mask) {
		printf("MISMATCH mask code=%u: got %#llx want %#llx\n",
		       (unsigned)code,
		       (unsigned long long)KPROG_X86_WIDTH_MASK(code),
		       (unsigned long long)want_mask);
		failures++;
	}
	cases++;
	if (KPROG_X86_WIDTH_BITS(code) != want_bits) {
		printf("MISMATCH bits code=%u: got %u want %u\n",
		       (unsigned)code, (unsigned)KPROG_X86_WIDTH_BITS(code),
		       (unsigned)want_bits);
		failures++;
	}
}

int main(void)
{
	/* The four width codes resolve to their own mask. */
	check(X86_WIDTH_8, 0xffULL, 8U);
	check(X86_WIDTH_16, 0xffffULL, 16U);
	check(X86_WIDTH_32, 0xffffffffULL, 32U);
	check(X86_WIDTH_64, ~0ULL, 64U);

	/* The absent code aliases 64: this is the documented compatibility
	 * convention, and it is the one invalid input the simulator relies on. */
	check(KPROG_X86_WIDTH_ABSENT_CODE, ~0ULL, 64U);

	/* Other codes reuse the field. They are not widths at all, so their
	 * falling back to 64 is a property of the ternary chain rather than a
	 * decision -- stated here so a change to the chain is visible. */
	check(3U, ~0ULL, 64U);
	check(5U, ~0ULL, 64U);
	check(7U, ~0ULL, 64U);
	check(25U, ~0ULL, 64U);  /* X86_OP_XCHG reuses the field */
	check(30U, ~0ULL, 64U);  /* X86_OP_BZHI reuses the field */
	check(99U, ~0ULL, 64U);
	check(255U, ~0ULL, 64U);

	if (failures) {
		printf("width fallback cross-check: FAIL (%d/%d)\n", failures,
		       cases);
		return 1;
	}
	printf("width fallback cross-check: OK (%d cases)\n", cases);
	return 0;
}