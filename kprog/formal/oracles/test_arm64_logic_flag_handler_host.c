/* Cross-check shared AND/BIC result-plus-NZCV handler steps. */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_ALU_AND 2U
#define ARM64_ALU_BIC 3U

#include "generated/arm64_width.h"
#include "generated/arm64_alu_result.h"
#include "generated/arm64_flags.h"
#include "generated/arm64_logic_flag_handler.h"

#include <stdio.h>
#include <stdlib.h>

static int check(unsigned family, __u64 lhs, __u64 rhs, unsigned width)
{
	unsigned bits = KPROG_ARM64_WIDTH_BITS(width);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);
	__u64 want = family == KPROG_ARM64_LOGIC_FAMILY_AND ?
		lhs & rhs : lhs & ~rhs;
	__u64 narrowed = want & mask;
	__u8 want_n = (narrowed >> (bits - 1)) & 1;
	__u8 want_z = narrowed == 0;
	__u64 result = 0xdeadbeef;
	__u8 n = 9, z = 9, c = 9, v = 9;

	KPROG_ARM64_EXEC_LOGIC_FLAGS(family, result, n, z, c, v,
		lhs, rhs, width, abort());
	if (result != want || n != want_n || z != want_z || c != 0 || v != 0) {
		fprintf(stderr,
			"MISMATCH family=%u width=%u lhs=%#llx rhs=%#llx result=%#llx want=%#llx flags=%u%u%u%u expected=%u%u00\n",
			family, width, lhs, rhs, result, want,
			n, z, c, v, want_n, want_z);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 vectors[][2] = {
		{0, 0}, {1, 2}, {~0ULL, 0}, {~0ULL, ~0ULL},
		{0x8000000000000000ULL, 0}, {0x80000000, 0},
		{0xff, 0x0f}, {0x55aa55aa55aa55aaULL, 0xaa55aa55aa55aa55ULL},
	};
	static const unsigned widths[] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const unsigned families[] = {
		KPROG_ARM64_LOGIC_FAMILY_AND, KPROG_ARM64_LOGIC_FAMILY_BIC,
	};
	unsigned cases = 0;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
			for (unsigned f = 0; f < sizeof(families) / sizeof(families[0]); f++) {
				if (check(families[f], vectors[i][0], vectors[i][1], widths[w]))
					return 1;
				cases++;
			}

	printf("arm64 logic flag handler host cross-check: OK (%u cases)\n", cases);
	return 0;
}
