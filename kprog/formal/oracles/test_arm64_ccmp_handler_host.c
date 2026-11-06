/* Cross-check CCMP condition, subtraction, and fallback-NZCV composition. */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef __int128 i128;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_COND_EQ 0U
#define ARM64_COND_NE 1U
#define ARM64_COND_CS 2U
#define ARM64_COND_CC 3U
#define ARM64_COND_MI 4U
#define ARM64_COND_PL 5U
#define ARM64_COND_VS 6U
#define ARM64_COND_VC 7U
#define ARM64_COND_HI 8U
#define ARM64_COND_LS 9U
#define ARM64_COND_GE 10U
#define ARM64_COND_LT 11U
#define ARM64_COND_GT 12U
#define ARM64_COND_LE 13U
#define ARM64_COND_AL 14U

#include "generated/arm64_width.h"
#include "generated/arm64_flags.h"
#include "generated/arm64_cond.h"
#include "generated/arm64_ccmp_handler.h"

#include <stdio.h>
#include <stdlib.h>

static int eval_cond(unsigned cond, __u8 n, __u8 z, __u8 c, __u8 v)
{
	switch (cond) {
	case ARM64_COND_EQ: return z;
	case ARM64_COND_NE: return !z;
	case ARM64_COND_CS: return c;
	case ARM64_COND_CC: return !c;
	case ARM64_COND_MI: return n;
	case ARM64_COND_PL: return !n;
	case ARM64_COND_VS: return v;
	case ARM64_COND_VC: return !v;
	case ARM64_COND_HI: return c && !z;
	case ARM64_COND_LS: return !c || z;
	case ARM64_COND_GE: return n == v;
	case ARM64_COND_LT: return n != v;
	case ARM64_COND_GT: return !z && n == v;
	case ARM64_COND_LE: return z || n != v;
	case ARM64_COND_AL: return 1;
	default: abort();
	}
}

static i128 signed_value(__u64 value, unsigned bits)
{
	__u64 mask = bits == 64 ? ~0ULL : (1ULL << bits) - 1;

	value &= mask;
	if (value & (1ULL << (bits - 1)))
		return (i128)value - ((i128)1 << bits);
	return value;
}

static int check(unsigned incoming, unsigned cond, __u64 lhs, __u64 rhs,
	unsigned width, unsigned fallback)
{
	unsigned bits = KPROG_ARM64_WIDTH_BITS(width);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);
	__u64 l = lhs & mask, r = rhs & mask;
	__u64 result = (l - r) & mask;
	i128 signed_result = signed_value(l, bits) - signed_value(r, bits);
	i128 signed_min = -((i128)1 << (bits - 1));
	i128 signed_max = ((i128)1 << (bits - 1)) - 1;
	__u8 n = (incoming >> 3) & 1;
	__u8 z = (incoming >> 2) & 1;
	__u8 c = (incoming >> 1) & 1;
	__u8 v = incoming & 1;
	__u8 take = eval_cond(cond, n, z, c, v);
	__u8 want_n = take ? (result >> (bits - 1)) & 1 : (fallback >> 3) & 1;
	__u8 want_z = take ? result == 0 : (fallback >> 2) & 1;
	__u8 want_c = take ? l >= r : (fallback >> 1) & 1;
	__u8 want_v = take ? signed_result < signed_min || signed_result > signed_max :
		fallback & 1;

	KPROG_ARM64_EXEC_CCMP(cond, fallback, n, z, c, v,
		lhs, rhs, width, abort());
	if (n != want_n || z != want_z || c != want_c || v != want_v) {
		fprintf(stderr,
			"MISMATCH incoming=%x cond=%u width=%u lhs=%#llx rhs=%#llx fallback=%x flags=%u%u%u%u expected=%u%u%u%u\n",
			incoming, cond, width, lhs, rhs, fallback,
			n, z, c, v, want_n, want_z, want_c, want_v);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 vectors[][2] = {
		{0, 0}, {1, 2}, {~0ULL, 1},
		{0x7fffffffffffffffULL, 1}, {0x8000000000000000ULL, 1},
		{0x7fffffff, 1}, {0x80000000, 1}, {0xff, 1},
	};
	static const unsigned widths[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	unsigned cases = 0;

	for (unsigned incoming = 0; incoming < 16; incoming++)
		for (unsigned cond = 0; cond < 15; cond++)
			for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
				for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
					for (unsigned fallback = 0; fallback < 16; fallback++) {
						if (check(incoming, cond, vectors[i][0],
							vectors[i][1], widths[w], fallback))
							return 1;
						cases++;
					}

	printf("arm64 CCMP handler host cross-check: OK (%u cases)\n", cases);
	return 0;
}
