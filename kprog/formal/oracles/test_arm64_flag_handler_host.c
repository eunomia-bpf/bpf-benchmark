/* Cross-check family dispatch and writeback/compare composition. */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef __int128 i128;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_ALU_ADD 0U
#define ARM64_ALU_SUB 1U

#include "generated/arm64_width.h"
#include "generated/arm64_alu_result.h"
#include "generated/arm64_flags.h"
#include "generated/arm64_flag_handler.h"

#include <stdio.h>
#include <stdlib.h>

static i128 signed_value(__u64 value, unsigned bits)
{
	__u64 mask = bits == 64 ? ~0ULL : (1ULL << bits) - 1;

	value &= mask;
	if (value & (1ULL << (bits - 1)))
		return (i128)value - ((i128)1 << bits);
	return value;
}

static int check(unsigned family, __u64 lhs, __u64 rhs, unsigned width)
{
	unsigned bits = KPROG_ARM64_WIDTH_BITS(width);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);
	__u64 l = lhs & mask, r = rhs & mask;
	__u64 want = family == KPROG_ARM64_ARITH_FAMILY_ADD ?
		lhs + rhs : lhs - rhs;
	__u64 narrowed = want & mask;
	i128 signed_result = family == KPROG_ARM64_ARITH_FAMILY_ADD ?
		signed_value(l, bits) + signed_value(r, bits) :
		signed_value(l, bits) - signed_value(r, bits);
	i128 signed_min = -((i128)1 << (bits - 1));
	i128 signed_max = ((i128)1 << (bits - 1)) - 1;
	__u8 want_n = (narrowed >> (bits - 1)) & 1;
	__u8 want_z = narrowed == 0;
	__u8 want_c = family == KPROG_ARM64_ARITH_FAMILY_ADD ?
		(__u8)(((i128)l + (i128)r) >> bits != 0) : (__u8)(l >= r);
	__u8 want_v = signed_result < signed_min || signed_result > signed_max;
	__u64 write_result = 0xdeadbeef;
	__u8 wn = 9, wz = 9, wc = 9, wv = 9;
	__u8 cn = 9, cz = 9, cc = 9, cv = 9;

	KPROG_ARM64_EXEC_ARITH_WRITEBACK(family, write_result,
		wn, wz, wc, wv, lhs, rhs, width, abort());
	KPROG_ARM64_EXEC_ARITH_COMPARE(family,
		cn, cz, cc, cv, lhs, rhs, width, abort());
	if (write_result != want || wn != want_n || wz != want_z ||
	    wc != want_c || wv != want_v || cn != want_n ||
	    cz != want_z || cc != want_c || cv != want_v) {
		fprintf(stderr,
			"MISMATCH family=%u width=%u lhs=%#llx rhs=%#llx result=%#llx want=%#llx write=%u%u%u%u compare=%u%u%u%u expected=%u%u%u%u\n",
			family, width, lhs, rhs, write_result, want,
			wn, wz, wc, wv, cn, cz, cc, cv,
			want_n, want_z, want_c, want_v);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 vectors[][2] = {
		{0, 0}, {1, 2}, {~0ULL, 1},
		{0x7fffffffffffffffULL, 1},
		{0x8000000000000000ULL, 1},
		{0x7fffffff, 1}, {0x80000000, 1}, {0xff, 1},
	};
	static const unsigned widths[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	unsigned cases = 0;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
			for (unsigned family = 0; family < 2; family++) {
				if (check(family, vectors[i][0], vectors[i][1], widths[w]))
					return 1;
				cases++;
			}

	printf("arm64 flag handler host cross-check: OK (%u cases)\n", cases);
	return 0;
}
