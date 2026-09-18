/*
 * Host cross-check for the generated x86 double-precision shift contract.
 *
 * Verifies kprog_x86_shld_value and kprog_x86_shrd_value from
 * generated/x86_doubleshift.h against independent oracles that assemble the
 * result bit by bit from the doubled word (never the macro's OR-of-two-shifts):
 *   SHLD: result bit i = bit (i + bits - k) of the (dst:src) word
 *   SHRD: result bit i = bit (i + k) of the (src:dst) word
 * where k is the raw shift count masked by the simulator's KPROG_X86_SHIFT_COUNT
 * (63 for 64-bit, 31 otherwise), so a narrow-width count above the width takes
 * the whole result from the other operand. It sweeps boundary operands over all
 * four widths and all 32/64 counts, then a fixed-seed random sweep, and checks
 * the zero-count identity. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_doubleshift_host.c -o /tmp/t_ds && /tmp/t_ds
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
#include "generated/x86_shift_count.h"
#include "generated/x86_doubleshift.h"

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

/* The doubled words as unsigned __int128, built from the masked halves. */
static unsigned __int128 pair_ds(__u64 dst, __u64 src, unsigned bits)
{
	__u64 m = bits == 64 ? ~0ULL : (1ULL << bits) - 1ULL;

	return (((unsigned __int128)(dst & m)) << bits) | (src & m);
}

static unsigned __int128 pair_sd(__u64 dst, __u64 src, unsigned bits)
{
	__u64 m = bits == 64 ? ~0ULL : (1ULL << bits) - 1ULL;

	return (((unsigned __int128)(src & m)) << bits) | (dst & m);
}

static __u64 low_bits(unsigned __int128 w, unsigned bits)
{
	__u64 m = bits == 64 ? ~0ULL : (1ULL << bits) - 1ULL;

	return (__u64)w & m;
}

/* SHLD oracle: high b bits of (dst:src) shifted left by k; for k >= bits this is
 * src << (k - bits). */
static __u64 shld_oracle(__u64 dst, __u64 src, __u64 shiftv, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned k = (unsigned)KPROG_X86_SHIFT_COUNT(shiftv, width);
	unsigned __int128 w = pair_ds(dst, src, bits);

	if (k >= bits)
		return low_bits((unsigned __int128)(src & width_mask(width)) << (k - bits), bits);
	return (__u64)((w << k) >> bits) & width_mask(width);
}

/* SHRD oracle: low b bits of (src:dst) shifted right by k. */
static __u64 shrd_oracle(__u64 dst, __u64 src, __u64 shiftv, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned k = (unsigned)KPROG_X86_SHIFT_COUNT(shiftv, width);
	unsigned __int128 w = pair_sd(dst, src, bits);

	return (__u64)(w >> k) & width_mask(width);
}

static int check(__u64 dst, __u64 src, __u64 shiftv, unsigned width)
{
	__u64 shld = kprog_x86_shld_value(dst, src, shiftv, width);
	__u64 shrd = kprog_x86_shrd_value(dst, src, shiftv, width);

	if (shld != shld_oracle(dst, src, shiftv, width)) {
		printf("MISMATCH shld dst=%#llx src=%#llx shift=%llu width=%u "
		       "res=%#llx\n", dst, src, shiftv, width, shld);
		return 1;
	}
	if (shrd != shrd_oracle(dst, src, shiftv, width)) {
		printf("MISMATCH shrd dst=%#llx src=%#llx shift=%llu width=%u "
		       "res=%#llx\n", dst, src, shiftv, width, shrd);
		return 1;
	}
	if ((shld & ~width_mask(width)) != 0 ||
	    (shrd & ~width_mask(width)) != 0) {
		printf("MISMATCH high bits dst=%#llx width=%u shld=%#llx "
		       "shrd=%#llx\n", dst, width, shld, shrd);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0xf0ULL, 0x0fULL, 0x0123456789abcdefULL,
	0x8000000000000000ULL, 0xff00ff00ff00ff00ULL,
};
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x2c95e1b734af680dULL;

	for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
			for (__u64 s = 0; s < 64; s++) {
				for (unsigned u = 0;
				     u < sizeof(values) / sizeof(values[0]);
				     u++) {
					fails += check(values[v], values[u], s,
						       widths[w]);
					cases++;
				}
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 dst, src, sh;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		dst = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		sh = state;
		fails += check(dst, src, sh, widths[iter % 4]);
		cases++;
	}

	if (fails) {
		printf("x86 doubleshift host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 doubleshift host cross-check: OK (%u cases)\n", cases);
	return 0;
}
