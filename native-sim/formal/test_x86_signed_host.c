/*
 * Host cross-check for the generated x86 signed-value contract.
 *
 * Verifies kprog_x86_sign_extend_value and kprog_x86_abs_width_value from
 * generated/x86_signed.h against independent oracles:
 *   - sign extend: widen the narrowed operand through an explicit __int64 cast
 *     of the width's signed type (never the macro's complement form);
 *   - magnitude: take the width-domain absolute value through a signed cast and
 *     negate-then-mask, never the macro's complement.
 * It sweeps boundary operands over all four widths, then a fixed-seed random
 * sweep, and checks the two defining invariants: sign extension is idempotent,
 * and the magnitude is idempotent. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_signed_host.c -o /tmp/t_se && /tmp/t_se
 */
typedef unsigned char __u8;
typedef signed char __s8;
typedef unsigned short __u16;
typedef signed short __s16;
typedef unsigned int __u32;
typedef signed int __s32;
typedef unsigned long long __u64;
typedef signed long long __s64;

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
#include "generated/x86_signed.h"

#include <stdio.h>

static __u64 width_mask(unsigned width)
{
	return width == X86_WIDTH_8 ? 0xffULL :
	       width == X86_WIDTH_16 ? 0xffffULL :
	       width == X86_WIDTH_32 ? 0xffffffffULL :
	       0xffffffffffffffffULL;
}

/* Independent sign extension through the width's signed type. */
static __u64 se_oracle(__u64 value, unsigned width)
{
	if (width == X86_WIDTH_8)
		return (__u64)(__s64)(__s8)(value & 0xffULL);
	if (width == X86_WIDTH_16)
		return (__u64)(__s64)(__s16)(value & 0xffffULL);
	if (width == X86_WIDTH_32)
		return (__u64)(__s64)(__s32)(value & 0xffffffffULL);
	return value;
}

/* Independent magnitude through a signed reinterpretation and negation. */
static __u64 abs_oracle(__u64 value, unsigned width)
{
	__u64 mask = width_mask(width);
	__s64 sv;

	if (width == X86_WIDTH_8)
		sv = (__s64)(__s8)(value & 0xffULL);
	else if (width == X86_WIDTH_16)
		sv = (__s64)(__s16)(value & 0xffffULL);
	else if (width == X86_WIDTH_32)
		sv = (__s64)(__s32)(value & 0xffffffffULL);
	else
		sv = (__s64)value;
	return (__u64)(sv < 0 ? -(unsigned long long)sv : (unsigned long long)sv) &
	       mask;
}

static int check(__u64 value, unsigned width)
{
	__u64 se = kprog_x86_sign_extend_value(value, width);
	__u64 abs = kprog_x86_abs_width_value(value, width);

	if (se != se_oracle(value, width)) {
		printf("MISMATCH se value=%#llx width=%u res=%#llx\n",
		       value, width, se);
		return 1;
	}
	if (abs != abs_oracle(value, width)) {
		printf("MISMATCH abs value=%#llx width=%u res=%#llx\n",
		       value, width, abs);
		return 1;
	}
	if (kprog_x86_sign_extend_value(se, width) != se) {
		printf("MISMATCH se not idempotent value=%#llx width=%u\n",
		       value, width);
		return 1;
	}
	if (kprog_x86_abs_width_value(abs, width) != abs) {
		printf("MISMATCH abs not idempotent value=%#llx width=%u\n",
		       value, width);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x80ULL, 0x7fULL, 0x8000ULL, 0x80000000ULL,
	0x8000000000000000ULL, 0x0123456789abcdefULL, 0xfbULL,
};
static const unsigned widths[] = { X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				   X86_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x6d41b0e793f28ac5ULL;

	for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
			fails += check(values[v], widths[w]);
			cases++;
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check(state, widths[iter % 4]);
		cases++;
	}

	if (fails) {
		printf("x86 signed host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 signed host cross-check: OK (%u cases)\n", cases);
	return 0;
}
