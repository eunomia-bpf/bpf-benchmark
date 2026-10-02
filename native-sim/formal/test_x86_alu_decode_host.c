/*
 * Host cross-check for the generated x86 ALU-decode contract
 * (generated/x86_alu_decode.h).
 *
 * The generated header binds the parsed-mnemonic ALU codes shared by the
 * simulator, the Lean model, and the artifact encoder. This oracle includes
 * x86_sim.h (defining `__always_inline` so the header compiles off-target) and
 * checks the generated constants against an independent mnemonic table, then
 * drives every generated code through the *real* x86_alu_result dispatcher and
 * compares the result against an independent recomputation of each operation
 * from its arithmetic identity. It also drives both generated handler-selector
 * macros and confirms the SBB/ADC selectors agree with the dispatcher's own
 * identity checks. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_alu_decode_host.c -o /tmp/t_xad \
 *     && /tmp/t_xad
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
		fprintf(stderr, "MISMATCH %s: got %llu want %llu\n", what,
			(unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

/* Independent mnemonic/code table, written here rather than derived from the
 * generated header. */
struct op {
	const char *mnemonic;
	__u32 code;
};

static const struct op OPS[] = {
	{"add", 0}, {"sub", 1}, {"xor", 2}, {"or", 3}, {"and", 4}, {"shl", 5},
	{"shr", 6}, {"sar", 7}, {"rol", 8}, {"imul", 9}, {"inc", 10}, {"not", 11},
	{"sbb", 12}, {"dec", 13}, {"neg", 14}, {"adc", 15},
};

/* The generated macro for each entry, in the same order as OPS. */
static const __u32 MACROS[] = {
	X86_ALU_ADD, X86_ALU_SUB, X86_ALU_XOR, X86_ALU_OR, X86_ALU_AND,
	X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR, X86_ALU_ROL, X86_ALU_IMUL,
	X86_ALU_INC, X86_ALU_NOT, X86_ALU_SBB, X86_ALU_DEC, X86_ALU_NEG,
	X86_ALU_ADC,
};

/* Independent recomputation of the dispatcher's result for `code`, from the
 * arithmetic identity of each operation (not a copy of x86_alu_result). */
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
		return ((narrow >> count) | (sign ? (mask ^ (mask >> count)) : 0)) & mask;
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

	/* 1. Generated constants equal the independent table, codes distinct. */
	for (i = 0; i < sizeof OPS / sizeof OPS[0]; i++) {
		expect_eq(OPS[i].mnemonic, MACROS[i], OPS[i].code);
	}
	for (i = 0; i < sizeof OPS / sizeof OPS[0]; i++) {
		unsigned j;

		for (j = i + 1; j < sizeof OPS / sizeof OPS[0]; j++) {
			cases++;
			if (OPS[i].code == OPS[j].code) {
				fprintf(stderr, "DUPLICATE code %u\n", OPS[i].code);
				failures++;
			}
		}
	}

	/* 2. Real dispatcher over every generated code and a spread of operands
	 *    and widths. */
	static const __u64 LH[] = {0ULL, 1ULL, 0xffffffffffffffffULL,
				   0x8000000000000000ULL, 0x123456789abcdefULL,
				   0xdeadbeefULL};
	static const __u64 RH[] = {0ULL, 1ULL, 8ULL, 31ULL, 32ULL, 63ULL, 64ULL,
				   0xffffffffffffffffULL};
	static const __u8 WD[] = {X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				  X86_WIDTH_64};
	unsigned a, b, d;

	for (i = 0; i < sizeof OPS / sizeof OPS[0]; i++) {
		for (a = 0; a < sizeof LH / sizeof LH[0]; a++) {
			for (b = 0; b < sizeof RH / sizeof RH[0]; b++) {
				for (d = 0; d < sizeof WD / sizeof WD[0]; d++) {
					char what[64];
					__u64 got = x86_alu_result(LH[a], RH[b],
								   MACROS[i], WD[d]);
					__u64 want = reference_result(MACROS[i], LH[a],
								      RH[b], WD[d]);

					snprintf(what, sizeof what,
						 "%s lhs=%llx rhs=%llx w=%u",
						 OPS[i].mnemonic,
						 (unsigned long long)LH[a],
						 (unsigned long long)RH[b], WD[d]);
					expect_eq(what, got, want);
				}
			}
		}
	}

	/* 3. Handler selectors bind to the real dispatcher's identity checks. */
	for (i = 0; i < sizeof OPS / sizeof OPS[0]; i++) {
		__u32 code = MACROS[i];

		expect_eq("sbb-handler", KPROG_X86_ALU_USES_SBB_HANDLER(code),
			  code == X86_ALU_SBB);
		expect_eq("adc-handler", KPROG_X86_ALU_USES_ADC_HANDLER(code),
			  code == X86_ALU_ADC);
	}
	/* The selectors are mutually exclusive and model exactly the two
	 * carry-sensitive operations. */
	for (i = 0; i < sizeof OPS / sizeof OPS[0]; i++) {
		__u32 code = MACROS[i];

		expect_eq("handler-exclusive",
			  KPROG_X86_ALU_USES_SBB_HANDLER(code) &&
				  KPROG_X86_ALU_USES_ADC_HANDLER(code),
			  0);
	}

	if (failures == 0)
		printf("x86 alu decode host cross-check: OK (%u cases)\n", cases);
	return failures == 0 ? 0 : 1;
}
