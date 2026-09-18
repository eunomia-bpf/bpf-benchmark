/*
 * Host cross-check for the generated x86 bit-manipulation contract (BT, BZHI).
 *
 * Verifies kprog_x86_bt_value and kprog_x86_bzhi_value from
 * generated/x86_bitops.h against independent oracles that never reuse the macro
 * expressions:
 *   - bt:   read the indexed bit through an explicit shifted mask test;
 *   - bzhi: build the kept mask byte by byte from the index.
 * It sweeps boundary operands over all four widths, then a fixed-seed random
 * sweep, and checks the defining invariants (bzhi never sets a bit above the
 * width; bzhi with the maximum index keeps the whole narrowed base). Exits
 * non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_bitops_host.c -o /tmp/t_bo && /tmp/t_bo
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

/* The generated header defines __always_inline functions for the in-kernel
 * build; provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#include "generated/x86_width.h"
#include "generated/x86_bitops.h"

#include <stdio.h>

static unsigned width_bits(unsigned width)
{
	return width == X86_WIDTH_8 ? 8U :
	       width == X86_WIDTH_16 ? 16U :
	       width == X86_WIDTH_32 ? 32U : 64U;
}

static __u64 width_mask(unsigned width)
{
	return width == X86_WIDTH_8 ? 0xffULL :
	       width == X86_WIDTH_16 ? 0xffffULL :
	       width == X86_WIDTH_32 ? 0xffffffffULL :
	       0xffffffffffffffffULL;
}

/* BT oracle: test the indexed bit through a shifted one-bit mask. The index is
 * masked to 63 for a 64-bit base and to 31 otherwise, matching the simulator's
 * X86_SIM_L_EXEC_BT* (`width == X86_WIDTH_64 ? 63 : 31`); this is *not* the
 * width's bit count for the narrow widths. */
static __u8 bt_oracle(__u64 base, __u64 index, unsigned width)
{
	unsigned bit = (unsigned)(index & (width == X86_WIDTH_64 ? 63U : 31U));

	return (__u8)(((base & width_mask(width)) & (1ULL << bit)) ? 1U : 0U);
}

/* BZHI oracle: build the kept mask from the index, byte by byte. */
static __u64 bzhi_oracle(__u64 src, __u64 count, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned c = (unsigned)(count & 0xff);
	__u64 kept;

	if (c >= bits)
		kept = width_mask(width);
	else
		kept = (1ULL << c) - 1ULL;
	return src & kept;
}

static int check(__u64 src, __u64 index, unsigned width)
{
	__u8 bt = kprog_x86_bt_value(src, index, width);
	__u8 bt_want = bt_oracle(src, index, width);
	__u64 bz = kprog_x86_bzhi_value(src, index, width);
	__u64 bz_want = bzhi_oracle(src, index, width);

	if (bt != bt_want) {
		printf("MISMATCH bt src=%#llx index=%llu width=%u res=%u want=%u\n",
		       src, index, width, bt, bt_want);
		return 1;
	}
	if (bz != bz_want) {
		printf("MISMATCH bzhi src=%#llx count=%llu width=%u res=%#llx "
		       "want=%#llx\n", src, index, width, bz, bz_want);
		return 1;
	}
	if ((bz & ~width_mask(width)) != 0) {
		printf("MISMATCH bzhi high bits src=%#llx width=%u res=%#llx\n",
		       src, width, bz);
		return 1;
	}
	if (kprog_x86_bzhi_value(src, 0xff, width) !=
	    (src & width_mask(width))) {
		printf("MISMATCH bzhi max index src=%#llx width=%u\n",
		       src, width);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x8000000000000000ULL, 0x5555555555555555ULL,
	0x0123456789abcdefULL, 0xf0f0f0f0f0f0f0f0ULL, 0x8ULL, 0xffffULL,
};
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x5b13f8a2e64c07d9ULL;

	for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
			for (unsigned i = 0; i < 64; i++) {
				fails += check(values[v], i, widths[w]);
				cases++;
			}
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 src, idx;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		idx = state;
		fails += check(src, idx, widths[iter % 4]);
		cases++;
	}

	if (fails) {
		printf("x86 bitops host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 bitops host cross-check: OK (%u cases)\n", cases);
	return 0;
}
