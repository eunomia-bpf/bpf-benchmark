/*
 * Host cross-check for the generated AArch64 source-modifier contract.
 *
 * Verifies KPROG_ARM64_MOD_VALUE from generated/arm64_mod.h against an
 * independent oracle built from plain C integer arithmetic:
 *   - LSL: (v << amount) & mask(width)
 *   - LSR: (v & mask(width)) >> amount
 *   - ASR: (width == 32) ? (__u64)((__s32)v >> amount)
 *                         : (__u64)((__s64)v >> amount)
 *   - ROR: 32-bit rotate of the low word when width == 32, else 64-bit rotate,
 *          both with the architectural amount == 0 identity
 *   - extends: truncate then shift left by the raw shift field
 * where amount = shift & (width == 32 ? 31 : 63).
 *
 * Runs explicit boundary vectors over all eleven modifiers and all four widths
 * plus a fixed-seed random sweep; the extend arms are swept only over the
 * architectural shift domain (shift < 64) because C `<<` is undefined above
 * that and the hardware ignores those bits. Also checks that
 * KPROG_ARM64_MOD_HANDLED accepts exactly the eleven modifier codes.
 * Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mod_host.c -o /tmp/t_mod_host && /tmp/t_mod_host
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

/* Modifier and width codes are kept local so the oracle is independent of
 * generated/arm64_decode.h; the generated headers assert the same values. */
#define ARM64_MOD_NONE 0U
#define ARM64_MOD_LSL 1U
#define ARM64_MOD_LSR 2U
#define ARM64_MOD_ASR 3U
#define ARM64_MOD_ROR 4U
#define ARM64_MOD_UXTW 5U
#define ARM64_MOD_SXTW 6U
#define ARM64_MOD_UXTH 7U
#define ARM64_MOD_SXTH 8U
#define ARM64_MOD_UXTB 9U
#define ARM64_MOD_SXTB 10U

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_width.h"
#include "generated/arm64_mod.h"

#include <stdio.h>

static __u64 mod_oracle(unsigned mod, __u64 v, unsigned shift, unsigned width)
{
	unsigned amount = shift & (width == ARM64_WIDTH_32 ? 31U : 63U);
	__u64 mask = KPROG_ARM64_WIDTH_MASK(width);

	switch (mod) {
	case ARM64_MOD_NONE:
		return v;
	case ARM64_MOD_LSL:
		return (v << amount) & mask;
	case ARM64_MOD_LSR:
		return (v & mask) >> amount;
	case ARM64_MOD_ASR:
		return width == ARM64_WIDTH_32 ? (__u64)((__s32)v >> amount)
					       : (__u64)((__s64)v >> amount);
	case ARM64_MOD_ROR:
		if (width == ARM64_WIDTH_32) {
			__u32 w = (__u32)v;

			return amount ? (__u64)((w >> amount) |
						(w << (32U - amount)))
				      : (__u64)w;
		}
		return amount ? (v >> amount) | (v << (64U - amount)) : v;
	case ARM64_MOD_UXTW:
		return ((__u64)(__u32)v) << shift;
	case ARM64_MOD_SXTW:
		return ((__u64)(__s64)(__s32)v) << shift;
	case ARM64_MOD_UXTH:
		return ((__u64)(__u16)v) << shift;
	case ARM64_MOD_SXTH:
		return ((__u64)(__s64)(__s16)v) << shift;
	case ARM64_MOD_UXTB:
		return ((__u64)(__u8)v) << shift;
	case ARM64_MOD_SXTB:
		return ((__u64)(__s64)(__s8)v) << shift;
	}
	return 0;
}

static int shifts_by_register(unsigned mod)
{
	return mod >= ARM64_MOD_UXTW;
}

static int check_mod(unsigned mod, __u64 v, unsigned shift, unsigned width)
{
	__u64 res = KPROG_ARM64_MOD_VALUE(mod, v, shift, width);
	__u64 want = mod_oracle(mod, v, shift, width);

	if (res != want) {
		printf("MISMATCH mod=%u value=%#llx shift=%u width=%u "
		       "res=%#llx want=%#llx\n",
		       mod, v, shift, width, res, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 vectors[] = {
		0x0ULL,
		0x1ULL,
		0xffULL,
		0x100ULL,
		0x1ffULL,
		0x80ULL,
		0x7fULL,
		0x8000ULL,
		0xffffffffULL,
		0x80000000ULL,
		0x7fffffffULL,
		0x0102030405060708ULL,
		0xffffffffffffffffULL,
		0x8000000000000000ULL,
		0x7fffffffffffffffULL,
	};
	static const unsigned shifts[] = {0U, 1U, 7U, 8U, 16U, 31U, 32U, 63U};
	static const unsigned widths[] = {ARM64_WIDTH_8, ARM64_WIDTH_16,
					  ARM64_WIDTH_32, ARM64_WIDTH_64};
	unsigned cases = 0, fails = 0;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned mod = ARM64_MOD_NONE; mod <= ARM64_MOD_SXTB; mod++)
			for (unsigned s = 0; s < sizeof(shifts) / sizeof(shifts[0]); s++)
				for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++) {
					fails += check_mod(mod, vectors[i], shifts[s],
							   widths[w]);
					cases++;
				}

	__u64 state = 0x9e3779b97f4a7c15ULL;
	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 v;
		unsigned shift, width;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		v = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		shift = (unsigned)(state & 0xffU);
		width = widths[state >> 8 & 3U];
		for (unsigned mod = ARM64_MOD_NONE; mod <= ARM64_MOD_SXTB; mod++) {
			unsigned s = shifts_by_register(mod) ? shift % 64U : shift;

			fails += check_mod(mod, v, s, width);
			cases++;
		}
	}

	for (unsigned mod = ARM64_MOD_NONE; mod <= ARM64_MOD_SXTB; mod++) {
		if (!KPROG_ARM64_MOD_HANDLED(mod)) {
			printf("MISMATCH modifier code %u not handled\n", mod);
			fails++;
		}
		cases++;
	}
	if (KPROG_ARM64_MOD_HANDLED(ARM64_MOD_SXTB + 1U)) {
		printf("MISMATCH unhandled modifier code reported as handled\n");
		fails++;
	}
	cases++;

	if (fails) {
		printf("arm64 mod host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 mod host cross-check: OK (%u cases)\n", cases);
	return 0;
}
