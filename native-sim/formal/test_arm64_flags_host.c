/*
 * Host cross-check for the generated AArch64 NZCV flag contract.
 *
 * Verifies KPROG_ARM64_SET_{ADD,SUB,LOGIC}_FLAGS from generated/arm64_flags.h
 * against an independent oracle using __int128:
 *   - ADD: C = unsigned carry-out, V = signed overflow, N/Z from the result
 *   - SUB: C = NOT borrow (= lhs >= rhs), V = signed overflow, N/Z
 *   - LOGIC: C = V = 0, N/Z from the width-narrowed value
 * Runs explicit AArch64 boundary vectors plus a fixed-seed random sweep over
 * all four widths. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_flags_host.c -o /tmp/t_a64 && /tmp/t_a64
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef __int128 i128;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_width.h"
#include "generated/arm64_flags.h"

#include <stdio.h>

static unsigned width_bits(unsigned width)
{
	return (unsigned)KPROG_ARM64_WIDTH_BITS(width);
}


/* Sign-extend the low `bits` of `v` to __int128 (independent of the macro). */
static i128 sign_extend(__u64 v, unsigned bits)
{
	__u64 m = (bits >= 64U) ? ~0ULL : ((1ULL << bits) - 1ULL);

	v &= m;
	if (v & (1ULL << (bits - 1U)))
		return (i128)v - ((i128)1 << bits);
	return (i128)v;
}
static __u64 sign_of(__u64 value, unsigned bits)
{
	return (value >> (bits - 1U)) & 1U;
}

static int check_add(__u64 lhs, __u64 rhs, unsigned width)
{
	unsigned bits = width_bits(width);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);
	__u64 l = lhs & mask, r = rhs & mask;
	__u64 res = (l + r) & mask;
	i128 sl = sign_extend(l, bits);
	i128 sr = sign_extend(r, bits);
	i128 sres = sl + sr;
	__u8 n, z, c, v;

	KPROG_ARM64_SET_ADD_FLAGS(n, z, c, v, lhs, rhs, width);
	if (n != (__u8)sign_of(res, bits) || z != (__u8)(res == 0) ||
	    c != (__u8)(((i128)l + (i128)r) >> bits != 0) ||
	    v != (__u8)(sres < -(i128)((i128)1 << (bits - 1)) ||
			sres > (i128)(((i128)1 << (bits - 1)) - 1))) {
		printf("MISMATCH add w=%u lhs=%#llx rhs=%#llx n=%u z=%u c=%u v=%u\n",
		       width, lhs, rhs, n, z, c, v);
		return 1;
	}
	return 0;
}

static int check_sub(__u64 lhs, __u64 rhs, unsigned width)
{
	unsigned bits = width_bits(width);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);
	__u64 l = lhs & mask, r = rhs & mask;
	__u64 res = (l - r) & mask;
	i128 sl = sign_extend(l, bits);
	i128 sr = sign_extend(r, bits);
	i128 sres = sl - sr;
	__u8 n, z, c, v;

	KPROG_ARM64_SET_SUB_FLAGS(n, z, c, v, lhs, rhs, width);
	if (n != (__u8)sign_of(res, bits) || z != (__u8)(res == 0) ||
	    c != (__u8)(l >= r) ||
	    v != (__u8)(sres < -(i128)((i128)1 << (bits - 1)) ||
			sres > (i128)(((i128)1 << (bits - 1)) - 1))) {
		printf("MISMATCH sub w=%u lhs=%#llx rhs=%#llx n=%u z=%u c=%u v=%u\n",
		       width, lhs, rhs, n, z, c, v);
		return 1;
	}
	return 0;
}

static int check_logic(__u64 value, unsigned width)
{
	unsigned bits = width_bits(width);
	__u64 res = value & KPROG_ARM64_WIDTH_MASK(width);
	__u8 n, z, c, v;

	KPROG_ARM64_SET_LOGIC_FLAGS(n, z, c, v, value, width);
	if (n != (__u8)sign_of(res, bits) || z != (__u8)(res == 0) ||
	    c != 0 || v != 0) {
		printf("MISMATCH logic w=%u value=%#llx n=%u z=%u c=%u v=%u\n",
		       width, value, n, z, c, v);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 vectors[][2] = {
		{0x0, 0x0},
		{0xffffffffffffffffULL, 0x1},
		{0x1, 0x2},
		{0x7fffffffffffffffULL, 0x1},
		{0x8000000000000000ULL, 0x1},
		{0x8000000000000000ULL, 0x8000000000000000ULL},
		{0x7fffffff, 0x1},
		{0x80000000, 0x1},
		{0xffffffff, 0x1},
		{0xff, 0x1},
		{0x80, 0x1},
		{0x7f, 0x1},
	};
	static const unsigned widths[4] = {ARM64_WIDTH_8, ARM64_WIDTH_16,
					   ARM64_WIDTH_32, ARM64_WIDTH_64};
	unsigned cases = 0, fails = 0;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned w = 0; w < 4; w++) {
			fails += check_add(vectors[i][0], vectors[i][1], widths[w]);
			fails += check_sub(vectors[i][0], vectors[i][1], widths[w]);
			fails += check_logic(vectors[i][0], widths[w]);
			cases += 3;
		}

	__u64 state = 0x12345678ULL;
	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 a, b;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		a = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		b = state;
		unsigned width = widths[iter & 3];
		fails += check_add(a, b, width);
		fails += check_sub(a, b, width);
		fails += check_logic(a, width);
		cases += 3;
	}

	if (fails) {
		printf("arm64 flag host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 flag host cross-check: OK (%u cases)\n", cases);
	return 0;
}
