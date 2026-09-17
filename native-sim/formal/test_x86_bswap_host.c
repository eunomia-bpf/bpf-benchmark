/*
 * Host cross-check for the generated x86 byte-reversal contract.
 *
 * Verifies kprog_x86_bswap_value from generated/x86_bswap.h against an
 * independent oracle that reverses the width's bytes through a byte array (never
 * the macro's mask/shift ladder). It sweeps boundary words over all four widths,
 * then a fixed-seed random sweep, and checks the width invariant (no byte above
 * the width survives) and the involution property (reversing twice restores the
 * width-masked value). Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_bswap_host.c -o /tmp/t_bswap && /tmp/t_bswap
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
#include "generated/x86_bswap.h"

#include <stdio.h>
#include <string.h>

static unsigned width_bytes(unsigned width)
{
	return width == X86_WIDTH_8 ? 1U :
	       width == X86_WIDTH_16 ? 2U :
	       width == X86_WIDTH_32 ? 4U : 8U;
}

static __u64 width_mask(unsigned width)
{
	return width == X86_WIDTH_8 ? 0xffULL :
	       width == X86_WIDTH_16 ? 0xffffULL :
	       width == X86_WIDTH_32 ? 0xffffffffULL :
	       0xffffffffffffffffULL;
}

/* Independent oracle: reverse the width's bytes through a byte array. */
static __u64 bswap_oracle(__u64 value, unsigned width)
{
	unsigned n = width_bytes(width);
	__u8 out[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	__u64 res = 0;

	for (unsigned i = 0; i < n; i++)
		out[i] = (__u8)((value >> (8 * (n - 1 - i))) & 0xffU);

	for (unsigned i = 0; i < n; i++)
		res |= (__u64)out[i] << (8 * i);
	return res;
}

static int check_bswap(__u64 value, unsigned width)
{
	__u64 res = kprog_x86_bswap_value(value, width);
	__u64 want = bswap_oracle(value, width);
	__u64 mask = width_mask(width);

	if (res != want) {
		printf("MISMATCH value=%#llx width=%u res=%#llx want=%#llx\n",
		       value, width, res, want);
		return 1;
	}
	if (width != X86_WIDTH_64 && (res & ~mask) != 0) {
		printf("MISMATCH value=%#llx width=%u high bytes survive: %#llx\n",
		       value, width, res);
		return 1;
	}
	if (kprog_x86_bswap_value(res, width) != (value & mask)) {
		printf("MISMATCH value=%#llx width=%u not involutive\n",
		       value, width);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0x0102030405060708ULL,
	0xff00ff00ff00ff00ULL, 0x00000000deadbeefULL, 0xefcdab8967452301ULL,
};
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x1a6f83c2d50947beULL;

	for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
			fails += check_bswap(values[v], widths[w]);
			cases++;
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check_bswap(state, widths[iter % 4]);
		cases++;
	}

	if (fails) {
		printf("x86 bswap host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 bswap host cross-check: OK (%u cases)\n", cases);
	return 0;
}
