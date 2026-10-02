/*
 * Host cross-check for the generated AArch64 width/narrowing contract.
 *
 * Verifies KPROG_ARM64_WIDTH_MASK / _SIGN_MASK / _BITS / KPROG_ARM64_APPLY_WIDTH
 * from generated/arm64_width.h against an independent oracle built only from
 * the width bit count:
 *   - mask      == low `bits` set
 *   - sign_mask == bit (`bits` - 1) set
 *   - bits      == the width's bit count
 *   - apply     == value masked, and its sign-mask test equals the shift test
 * Runs explicit boundary vectors plus a fixed-seed random sweep over all four
 * widths. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_width_host.c -o /tmp/t_a64w && /tmp/t_a64w
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_width.h"

#include <stdio.h>

static unsigned expected_bits(unsigned width)
{
	switch (width) {
	case ARM64_WIDTH_8:
		return 8U;
	case ARM64_WIDTH_16:
		return 16U;
	case ARM64_WIDTH_32:
		return 32U;
	case ARM64_WIDTH_64:
		return 64U;
	default:
		printf("unknown width code %#x\n", width);
		return 0U;
	}
}

static __u64 low_mask(unsigned bits)
{
	return (bits >= 64U) ? ~0ULL : ((1ULL << bits) - 1ULL);
}

static int check_width(unsigned width)
{
	unsigned bits = expected_bits(width);
	__u64 mask = low_mask(bits);
	__u64 sign = 1ULL << (bits - 1U);
	static const __u64 values[] = {
		0x0ULL,
		0x1ULL,
		0x7fULL,
		0x80ULL,
		0xffULL,
		0x100ULL,
		0x7fffULL,
		0x8000ULL,
		0xffffULL,
		0x10000ULL,
		0x7fffffffULL,
		0x80000000ULL,
		0xffffffffULL,
		0x100000000ULL,
		0x0123456789abcdefULL,
		0x7fffffffffffffffULL,
		0x8000000000000000ULL,
		0xffffffffffffffffULL,
	};

	if ((unsigned)KPROG_ARM64_WIDTH_BITS(width) != bits) {
		printf("MISMATCH bits w=%u bits=%u\n", width,
		       (unsigned)KPROG_ARM64_WIDTH_BITS(width));
		return 1;
	}
	if (KPROG_ARM64_WIDTH_MASK(width) != mask) {
		printf("MISMATCH mask w=%u mask=%#llx want=%#llx\n", width,
		       KPROG_ARM64_WIDTH_MASK(width), mask);
		return 1;
	}
	if (KPROG_ARM64_WIDTH_SIGN_MASK(width) != sign) {
		printf("MISMATCH sign_mask w=%u sign=%#llx want=%#llx\n", width,
		       KPROG_ARM64_WIDTH_SIGN_MASK(width), sign);
		return 1;
	}
	for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
		__u64 v = values[i];
		__u64 narrowed = KPROG_ARM64_APPLY_WIDTH(v, width);
		__u64 applied = v & mask;

		if (narrowed != applied) {
			printf("MISMATCH apply w=%u v=%#llx got=%#llx want=%#llx\n",
			       width, v, narrowed, applied);
			return 1;
		}
		if (((narrowed & KPROG_ARM64_WIDTH_SIGN_MASK(width)) != 0) !=
		    (((applied >> (bits - 1U)) & 1U) != 0)) {
			printf("MISMATCH sign_observe w=%u v=%#llx\n", width, v);
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	static const unsigned widths[4] = {ARM64_WIDTH_8, ARM64_WIDTH_16,
					   ARM64_WIDTH_32, ARM64_WIDTH_64};
	unsigned cases = 0, fails = 0;

	for (unsigned w = 0; w < 4; w++) {
		fails += check_width(widths[w]);
		cases += 20;
	}

	__u64 state = 0x9e3779b97f4a7c15ULL;
	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 v;
		unsigned bits, width;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		v = state;
		width = widths[iter & 3];
		bits = expected_bits(width);
		if (KPROG_ARM64_APPLY_WIDTH(v, width) != (v & low_mask(bits))) {
			printf("MISMATCH apply w=%u v=%#llx\n", width, v);
			fails++;
		}
		if (((KPROG_ARM64_APPLY_WIDTH(v, width) &
		      KPROG_ARM64_WIDTH_SIGN_MASK(width)) != 0) !=
		    ((((v & low_mask(bits)) >> (bits - 1U)) & 1U) != 0)) {
			printf("MISMATCH sign w=%u v=%#llx\n", width, v);
			fails++;
		}
		cases += 2;
	}

	if (fails) {
		printf("arm64 width host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 width host cross-check: OK (%u cases)\n", cases);
	return 0;
}
