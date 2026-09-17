/*
 * Host cross-check for the generated x86 ROR result contract.
 *
 * Verifies kprog_x86_ror_result from generated/x86_shift_result.h against an
 * independent oracle that rotates through an explicit bit-walk on the narrowed
 * operand (never the macro's shift pair):
 *   ror_w(value, k) = bits reversed-in-position by (k mod w)
 * implemented by reading each destination bit from the source bit (i + k) mod w.
 * It sweeps boundary operands and all four widths, then a fixed-seed random
 * sweep, and checks the defining identity ror(v,k) == rol(v, w-k) on the same
 * operand. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_ror_result_host.c -o /tmp/t_ror && /tmp/t_ror
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;

/* The generated shift-result header defines __always_inline functions for the
 * in-kernel build; provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif
typedef unsigned long long __u64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_width.h"
#include "generated/x86_shift_count.h"
#include "generated/x86_shift_result.h"

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

/* Independent oracle: build each destination bit from the source bit index. */
static __u64 ror_oracle(__u64 value, __u64 shift, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned k = (unsigned)(shift & (bits - 1));
	__u64 narrowed = value & width_mask(width);
	__u64 out = 0;

	for (unsigned i = 0; i < bits; i++) {
		unsigned src = (i + k) % bits;

		out |= ((narrowed >> src) & 1ULL) << i;
	}
	return out & width_mask(width);
}

static int check_ror(__u64 value, __u64 shift, unsigned width)
{
	__u64 res = kprog_x86_ror_result(value, shift, width);
	__u64 want = ror_oracle(value, shift, width);
	unsigned bits = width_bits(width);

	if (res != want) {
		printf("MISMATCH value=%#llx shift=%#llx width=%u res=%#llx "
		       "want=%#llx\n", value, shift, width, res, want);
		return 1;
	}
	/* Defining identity: ror by k is rol by (bits - k). */
	{
		__u64 k = shift & (bits - 1);
		__u64 via_rol = kprog_x86_rol_result(value, (bits - k) & (bits - 1),
						     width);

		if (res != via_rol) {
			printf("MISMATCH identity value=%#llx shift=%#llx "
			       "width=%u ror=%#llx rol=%#llx\n",
			       value, shift, width, res, via_rol);
			return 1;
		}
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0x81ULL, 0x8000000000000000ULL,
	0x01020304ULL, 0xff00ff00ff00ff00ULL, 0x1ULL,
};
static const __u64 shifts[] = { 0ULL, 1ULL, 7ULL, 8ULL, 15ULL, 31ULL, 32ULL,
				63ULL, 64ULL, 255ULL };
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x3f8c2ea97164b0d5ULL;

	for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
		for (unsigned s = 0; s < sizeof(shifts) / sizeof(shifts[0]); s++)
			for (unsigned w = 0;
			     w < sizeof(widths) / sizeof(widths[0]); w++) {
				fails += check_ror(values[v], shifts[s], widths[w]);
				cases++;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 value, shift;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		value = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		shift = state;
		fails += check_ror(value, shift, widths[iter % 4]);
		cases++;
	}

	if (fails) {
		printf("x86 ror result host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 ror result host cross-check: OK (%u cases)\n", cases);
	return 0;
}
