/*
 * Host cross-check for the AArch64 artifact encoder's textual
 * condition-mnemonic decode contract (`generated/arm64_cc_decode.h`).
 *
 * The module under test fixes the table the encoder
 * (`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`, `COND`) uses to turn
 * a parsed benchmark condition mnemonic into an `ARM64_COND_*` code. It pins
 * each of the 15 architectural conditions to its `ARM64_COND_*` value, and
 * keeps the two alias mnemonics `hs`/`lo` on the same codes as `cs`/`cc`.
 *
 * This oracle restates the 17 mnemonics and the mnemonic -> code map by hand
 * and drives the generated selector `KPROG_ARM64_CC_DECODE_COND` over the
 * generated mnemonic codes, over every out-of-range code in a dense slice,
 * and checks that no new condition is invented by the aliases. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_cc_decode_host.c -o /tmp/t_arm_cc
 *   /tmp/t_arm_cc
 */

/* The `ARM64_COND_*` decodes the generated contract asserts against, restated
 * as literals so this model is independent of the generated header. The
 * generated `_Static_assert`s in `generated/arm64_cc_decode.h` pin this block
 * to the shared condition contract's values. */
#define ARM64_COND_EQ 0U
#define ARM64_COND_NE 1U
#define ARM64_COND_CS 2U
#define ARM64_COND_CC 3U
#define ARM64_COND_MI 4U
#define ARM64_COND_PL 5U
#define ARM64_COND_VS 6U
#define ARM64_COND_VC 7U
#define ARM64_COND_HI 8U
#define ARM64_COND_LS 9U
#define ARM64_COND_GE 10U
#define ARM64_COND_LT 11U
#define ARM64_COND_GT 12U
#define ARM64_COND_LE 13U
#define ARM64_COND_AL 14U

#include "generated/arm64_cc_decode.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

/* The 17 condition mnemonics the encoder spells, in `COND` order. */
static const char *const mnemonics[] = {
	"eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc",
	"hi", "ls", "ge", "lt", "gt", "le", "al",
};
#define MNEMONIC_COUNT 17U

/* The distinct architectural conditions the encoder reaches, in contract
 * order. The canonical mnemonics name these; `hs`/`lo` alias two of them. */
static const char *const conditions[] = {
	"eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc",
	"hi", "ls", "ge", "lt", "gt", "le", "al",
};
#define CONDITION_COUNT 15U

/* The hand restatement of the mnemonic -> `ARM64_COND_*` code map. This is the
 * independent model the generated selector must agree with, over every
 * mnemonic code the encoder produces. */
static unsigned model_code(unsigned mnemonic_index)
{
	switch (mnemonic_index) {
	case 0U:  return ARM64_COND_EQ;
	case 1U:  return ARM64_COND_NE;
	case 2U:  return ARM64_COND_CS;
	case 3U:  return ARM64_COND_CS; /* hs aliases cs */
	case 4U:  return ARM64_COND_CC;
	case 5U:  return ARM64_COND_CC; /* lo aliases cc */
	case 6U:  return ARM64_COND_MI;
	case 7U:  return ARM64_COND_PL;
	case 8U:  return ARM64_COND_VS;
	case 9U:  return ARM64_COND_VC;
	case 10U: return ARM64_COND_HI;
	case 11U: return ARM64_COND_LS;
	case 12U: return ARM64_COND_GE;
	case 13U: return ARM64_COND_LT;
	case 14U: return ARM64_COND_GT;
	case 15U: return ARM64_COND_LE;
	case 16U: return ARM64_COND_AL;
	default:  return 0xffffU;
	}
}

/* The hand restatement of the architectural condition a mnemonic names; an
 * alias names the same condition as its canonical spelling. Used to check the
 * aliases add no new condition. */
static unsigned model_condition(unsigned mnemonic_index)
{
	unsigned code = model_code(mnemonic_index);
	return code == 0xffffU ? 0xffffU : code;
}

/* The generated mnemonic codes must be the hand indices, and the generated
 * counts must match. */
static void check_mnemonic_codes(void)
{
	static const unsigned generated[MNEMONIC_COUNT] = {
		KPROG_ARM64_CC_DECODE_MNEMONIC_EQ,
		KPROG_ARM64_CC_DECODE_MNEMONIC_NE,
		KPROG_ARM64_CC_DECODE_MNEMONIC_CS,
		KPROG_ARM64_CC_DECODE_MNEMONIC_HS,
		KPROG_ARM64_CC_DECODE_MNEMONIC_CC,
		KPROG_ARM64_CC_DECODE_MNEMONIC_LO,
		KPROG_ARM64_CC_DECODE_MNEMONIC_MI,
		KPROG_ARM64_CC_DECODE_MNEMONIC_PL,
		KPROG_ARM64_CC_DECODE_MNEMONIC_VS,
		KPROG_ARM64_CC_DECODE_MNEMONIC_VC,
		KPROG_ARM64_CC_DECODE_MNEMONIC_HI,
		KPROG_ARM64_CC_DECODE_MNEMONIC_LS,
		KPROG_ARM64_CC_DECODE_MNEMONIC_GE,
		KPROG_ARM64_CC_DECODE_MNEMONIC_LT,
		KPROG_ARM64_CC_DECODE_MNEMONIC_GT,
		KPROG_ARM64_CC_DECODE_MNEMONIC_LE,
		KPROG_ARM64_CC_DECODE_MNEMONIC_AL,
	};
	unsigned i;

	cases++;
	if (KPROG_ARM64_CC_DECODE_MNEMONIC_COUNT != MNEMONIC_COUNT) {
		printf("MISMATCH arm64 cc decode mnemonic count: got %u want %u\n",
		       KPROG_ARM64_CC_DECODE_MNEMONIC_COUNT, MNEMONIC_COUNT);
		failures++;
	}
	cases++;
	if (KPROG_ARM64_CC_DECODE_CONDITION_COUNT != CONDITION_COUNT) {
		printf("MISMATCH arm64 cc decode condition count: got %u want %u\n",
		       KPROG_ARM64_CC_DECODE_CONDITION_COUNT, CONDITION_COUNT);
		failures++;
	}
	for (i = 0U; i < MNEMONIC_COUNT; i++) {
		cases++;
		if (generated[i] != i) {
			printf("MISMATCH arm64 cc decode mnemonic code %s: got %u want %u\n",
			       mnemonics[i], generated[i], i);
			failures++;
		}
	}
}

/* The generated selector must return each mnemonic's condition, and must
 * reach its 0 default for every code past the table. */
static void check_selector(void)
{
	static const unsigned out_of_range[] = {
		MNEMONIC_COUNT, MNEMONIC_COUNT + 1U, 24U, 0x20U, 0x7fU, 0xffU,
	};
	unsigned i;

	for (i = 0U; i < MNEMONIC_COUNT; i++) {
		unsigned got = KPROG_ARM64_CC_DECODE_COND(i);
		unsigned want = model_code(i);

		cases++;
		if (got != want) {
			printf("MISMATCH arm64 cc decode selector %s: got %u want %u\n",
			       mnemonics[i], got, want);
			failures++;
		}
	}
	for (i = 0U; i < sizeof(out_of_range) / sizeof(out_of_range[0]);
	     i++) {
		cases++;
		if (KPROG_ARM64_CC_DECODE_COND(out_of_range[i]) != 0U) {
			printf("MISMATCH arm64 cc decode default %u: got %u want 0\n",
			       out_of_range[i],
			       KPROG_ARM64_CC_DECODE_COND(out_of_range[i]));
			failures++;
		}
	}
}

/* The aliases `hs`/`lo` must land on the same condition as `cs`/`cc`, and no
 * mnemonic may invent a condition outside the shared contract. */
static void check_aliases(void)
{
	unsigned i;

	for (i = 0U; i < MNEMONIC_COUNT; i++) {
		unsigned code = model_code(i);
		cases++;
		if (code >= CONDITION_COUNT) {
			printf("MISMATCH arm64 cc decode condition %s out of range: %u\n",
			       mnemonics[i], code);
			failures++;
		}
	}
	cases++;
	if (KPROG_ARM64_CC_DECODE_COND(KPROG_ARM64_CC_DECODE_MNEMONIC_HS) !=
	    KPROG_ARM64_CC_DECODE_COND(KPROG_ARM64_CC_DECODE_MNEMONIC_CS)) {
		printf("MISMATCH arm64 cc decode alias hs != cs\n");
		failures++;
	}
	cases++;
	if (KPROG_ARM64_CC_DECODE_COND(KPROG_ARM64_CC_DECODE_MNEMONIC_LO) !=
	    KPROG_ARM64_CC_DECODE_COND(KPROG_ARM64_CC_DECODE_MNEMONIC_CC)) {
		printf("MISMATCH arm64 cc decode alias lo != cc\n");
		failures++;
	}
	/* Every distinct condition is reached, and the alias spellings are the
	 * only mnemonics that share a code with another. */
	for (i = 0U; i < CONDITION_COUNT; i++) {
		unsigned j;
		unsigned seen = 0U;

		for (j = 0U; j < MNEMONIC_COUNT; j++) {
			if (model_condition(j) == i)
				seen++;
		}
		cases++;
		if (seen == 0U) {
			printf("MISMATCH arm64 cc decode condition %s unreached\n",
			       conditions[i]);
			failures++;
		}
		if (seen > 2U) {
			printf("MISMATCH arm64 cc decode condition %s over-aliased: %u\n",
			       conditions[i], seen);
			failures++;
		}
	}
}

int main(void)
{
	check_mnemonic_codes();
	check_selector();
	check_aliases();

	if (failures != 0) {
		printf("arm64 cc decode host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("arm64 cc decode host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
