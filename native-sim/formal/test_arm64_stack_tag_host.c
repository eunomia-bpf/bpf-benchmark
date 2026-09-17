/*
 * Host cross-check for the generated AArch64 stack slot-tag selection contract.
 *
 * Verifies KPROG_ARM64_STACK_TAG from generated/arm64_stack_tag.h against an
 * independent oracle written as the plain conjunction (never the macro's
 * ternary): the slot tag applies iff the access is 64-bit and qword-aligned. It
 * sweeps all four (is_w64, is_aligned) combinations plus unaligned offsets, and
 * asserts the selection is exactly the conjunction. Exits non-zero on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stack_tag_host.c -o /tmp/t_st && /tmp/t_st
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/arm64_stack_tag.h"

#include <stdio.h>

static unsigned oracle(int is_w64, int is_aligned)
{
	return (is_w64 && is_aligned) ? 1U : 0U;
}

static int check(int is_w64, int is_aligned)
{
	unsigned res = KPROG_ARM64_STACK_TAG(is_w64, is_aligned);
	unsigned want = oracle(is_w64, is_aligned);

	if (res != want) {
		printf("MISMATCH is_w64=%d is_aligned=%d res=%u want=%u\n",
		       is_w64, is_aligned, res, want);
		return 1;
	}
	return 0;
}

static const unsigned widths[] = { 1U, 2U, 4U, 8U };
static const unsigned offsets[] = { 0U, 1U, 4U, 7U, 8U, 16U, 104U, 105U };

int main(void)
{
	unsigned cases = 0, fails = 0;

	for (unsigned wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++)
		for (unsigned oi = 0; oi < sizeof(offsets) / sizeof(offsets[0]);
		     oi++) {
			int is_w64 = widths[wi] == 8U;
			int is_aligned = (offsets[oi] % 8U) == 0;

			fails += check(is_w64, is_aligned);
			cases++;
		}

	for (int w = 0; w < 2; w++)
		for (int a = 0; a < 2; a++) {
			fails += check(w, a);
			cases++;
		}

	if (fails) {
		printf("arm64 stack tag host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 stack tag host cross-check: OK (%u cases)\n", cases);
	return 0;
}
