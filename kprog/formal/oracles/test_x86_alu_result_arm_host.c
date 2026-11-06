/*
 * Host cross-check for the generated x86 ALU op-step (result) contract
 * (STEP 0153).
 *
 * The generated `KPROG_X86_ALU_RESULT` macro restates, one switch arm per
 * `X86_ALU_*` operation code, the arm formulas the simulator's
 * `x86_alu_result` dispatcher applies (the delegate helpers under each arm are
 * the generated single-step contracts, and the shift arms pass the caller's
 * width through to the generated shift-result helpers). This oracle drives
 * the *real* generated macro through `x86_sim.h` and compares each arm
 * against an independent per-op restatement of the same arithmetic (the
 * delegate identity of each formula, never the macro's own helpers), over the
 * full operation grid. It also checks that the case-label table tracks the
 * `X86_ALU_*` constants part-for-part, that the labels stay distinct, that
 * the width argument reaches the shift arms, and that an operation byte
 * outside the sixteen labels keeps the left operand. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_alu_result_arm_host.c -o build/test_x86_alu_result_arm_host
 *   ./build/test_x86_alu_result_arm_host
 */

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;
#define __always_inline inline

#include "../x86/x86_sim.h"

#include <stdio.h>

static unsigned cases = 0;
static unsigned failures = 0;

static void expect_eq(const char *what, __u64 got, __u64 want)
{
	cases++;
	if (got != want) {
		fprintf(stderr, "MISMATCH %s: got %llx want %llx\n", what,
			(unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

/* The generated macro for each token, in the ALU-decode table's order. */
static const __u32 MACROS[] = {
	X86_ALU_ADD, X86_ALU_SUB, X86_ALU_XOR, X86_ALU_OR, X86_ALU_AND,
	X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR, X86_ALU_ROL, X86_ALU_IMUL,
	X86_ALU_INC, X86_ALU_NOT, X86_ALU_SBB, X86_ALU_DEC, X86_ALU_NEG,
	X86_ALU_ADC,
};

static const char *MNEMONIC[] = {
	"add", "sub", "xor", "or", "and", "shl", "shr", "sar", "rol", "imul",
	"inc", "not", "sbb", "dec", "neg", "adc",
};

static const __u32 CODES[] = {
	0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U,
};

/* Independent recomputation of the dispatcher's result for `code`, from the
 * arithmetic identity of each operation (not a copy of x86_alu_result or the
 * generated macro). */
static __u64 reference_result(__u32 code, __u64 lhs, __u64 rhs, __u8 width)
{
	__u64 mask = KPROG_X86_WIDTH_MASK(width);

	switch (code) {
	case 0: return lhs + rhs;                            /* add == adc(0) */
	case 1: return lhs - rhs;                            /* sub == sbb(0) */
	case 2: return lhs ^ rhs;
	case 3: return lhs | rhs;
	case 4: return lhs & rhs;
	case 5: return (lhs << KPROG_X86_SHIFT_COUNT(rhs, width)) & mask;
	case 6: return ((lhs & mask) >> KPROG_X86_SHIFT_COUNT(rhs, width)) & mask;
	case 7: {
		unsigned count = KPROG_X86_SHIFT_COUNT(rhs, width);
		__u64 narrow = lhs & mask;
		__u64 sign = narrow & KPROG_X86_WIDTH_SIGN_MASK(width);

		/* Arithmetic shift = floor(narrow / 2^count), kept in width. */
		if (count == 0)
			return narrow;
		return ((narrow >> count) |
			(sign ? (mask ^ (mask >> count)) : 0)) & mask;
	}
	case 8: {
		unsigned bits = KPROG_X86_WIDTH_BITS(width);
		unsigned count = KPROG_X86_SHIFT_COUNT(rhs, width) & (bits - 1);
		__u64 narrow = lhs & mask;

		if (count == 0)
			return narrow;
		return ((narrow << count) | (narrow >> (bits - count))) & mask;
	}
	case 9: return lhs * rhs;                            /* imul (low half) */
	case 10: return lhs + 1;                             /* inc == add 1 */
	case 11: return ~lhs;                                /* not */
	case 12: return lhs - rhs;                           /* sbb, no borrow in */
	case 13: return lhs - 1;                             /* dec == sub 1 */
	case 14: return 0 - lhs;                             /* neg == 0 - lhs */
	case 15: return lhs + rhs;                           /* adc, no carry in */
	default: return 0;
	}
}

int main(void)
{
	unsigned i;

	/* 1. The case-label table tracks the X86_ALU_* constants part-for-part,
	 *    and the labels are distinct. */
	for (i = 0; i < sizeof MACROS / sizeof MACROS[0]; i++) {
		expect_eq(MNEMONIC[i], MACROS[i], CODES[i]);
	}
	for (i = 0; i < sizeof MACROS / sizeof MACROS[0]; i++) {
		unsigned j;

		for (j = i + 1; j < sizeof MACROS / sizeof MACROS[0]; j++) {
			cases++;
			if (MACROS[i] == MACROS[j]) {
				fprintf(stderr, "DUPLICATE code %u\n",
					MACROS[i]);
				failures++;
			}
		}
	}

	/* 2. The real generated macro over every token, a spread of operands,
	 *    and every width. */
	static const __u64 LH[] = {0ULL, 1ULL, 0xffffffffffffffffULL,
				   0x8000000000000000ULL,
				   0x123456789abcdefULL, 0xdeadbeefULL};
	static const __u64 RH[] = {0ULL, 1ULL, 8ULL, 31ULL, 32ULL, 63ULL, 64ULL,
				   0xffffffffffffffffULL};
	static const __u8 WD[] = {X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				  X86_WIDTH_64};
	unsigned a, b, d;

	for (i = 0; i < sizeof MACROS / sizeof MACROS[0]; i++) {
		for (a = 0; a < sizeof LH / sizeof LH[0]; a++) {
			for (b = 0; b < sizeof RH / sizeof RH[0]; b++) {
				for (d = 0; d < sizeof WD / sizeof WD[0]; d++) {
					char what[64];
					__u64 got = KPROG_X86_ALU_RESULT(
						LH[a], RH[b], MACROS[i], WD[d],
						(void)0);
					__u64 want = reference_result(
						MACROS[i], LH[a], RH[b],
						WD[d]);

					snprintf(what, sizeof what,
						 "%s lhs=%llx rhs=%llx w=%u",
						 MNEMONIC[i],
						 (unsigned long long)LH[a],
						 (unsigned long long)RH[b],
						 WD[d]);
					expect_eq(what, got, want);
				}
			}
		}
	}

	/* 3. The same grid through the real dispatcher, so the routed wrapper
	 *    and the generated macro agree everywhere the oracle walks. */
	for (i = 0; i < sizeof MACROS / sizeof MACROS[0]; i++) {
		for (a = 0; a < sizeof LH / sizeof LH[0]; a++) {
			for (b = 0; b < sizeof RH / sizeof RH[0]; b++) {
				for (d = 0; d < sizeof WD / sizeof WD[0]; d++) {
					char what[64];
					__u64 got = x86_alu_result(
						LH[a], RH[b], MACROS[i],
						WD[d]);
					__u64 want = reference_result(
						MACROS[i], LH[a], RH[b],
						WD[d]);

					snprintf(what, sizeof what,
						 "routed %s lhs=%llx rhs=%llx "
						 "w=%u", MNEMONIC[i],
						 (unsigned long long)LH[a],
						 (unsigned long long)RH[b],
						 WD[d]);
					expect_eq(what, got, want);
				}
			}
		}
	}

	/* 4. An operation byte outside the sixteen labels keeps the left
	 *    operand: the result variable starts at (LHS) and the default arm
	 *    leaves it there. */
	{
		unsigned a, d;

		for (a = 0; a < sizeof LH / sizeof LH[0]; a++) {
			for (d = 0; d < sizeof WD / sizeof WD[0]; d++) {
				char what[64];
				__u32 op = 16U + (__u32)CODES[a % 16];

				snprintf(what, sizeof what,
					 "default op=%u lhs=%llx w=%u", op,
					 (unsigned long long)LH[a], WD[d]);
				expect_eq(what,
					  KPROG_X86_ALU_RESULT(
						  LH[a], ~LH[a], op, WD[d],
						  (void)0),
					  LH[a]);
			}
		}
	}

	if (failures == 0)
		printf("x86 alu result arm host cross-check: OK (%u cases)\n",
		       cases);
	return failures == 0 ? 0 : 1;
}
