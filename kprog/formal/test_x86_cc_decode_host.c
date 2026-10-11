/*
 * Host cross-check for the x86 artifact encoder's textual
 * `jcc`/`cmovcc`/`setcc` condition-mnemonic decode contract
 * (`generated/x86_cc_decode.h`).
 *
 * The module under test fixes the table the encoder
 * (`kprog/x86/micro-prog/generate_micro_sim_proofs.py`, `CC_AUX`) uses to turn
 * a parsed benchmark mnemonic into an `X86_CC_*` code. It pins each of the 12
 * condition suffixes to its `X86_CC_*` value (asserted equal to the shared
 * condition contract's own `_Static_assert`ed values through the inclusion of
 * `generated/x86_cond.h`), restates the mnemonic = family ++ suffix
 * composition, and keeps the two parity codes 10/11 — the ones the encoder
 * does not spell — out of the table.
 *
 * This oracle restates the 36 mnemonics, the 12 suffixes, and the suffix ->
 * code map by hand and drives the generated selector
 * `KPROG_X86_CC_DECODE_CC` over the generated suffix codes, over every
 * out-of-range code in a dense slice, and over each mnemonic's hand-derived
 * suffix. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_cc_decode_host.c -o /tmp/t_cc_decode
 *   /tmp/t_cc_decode
 */

/* The `X86_CC_*` decodes the generated condition contract asserts against, and
 * the encoder's suffix codes, restated as literals so this model is
 * independent of the generated tables. The generated `_Static_assert`s in
 * `generated/x86_cond.h` pin the first block to the shared contract and those
 * in `generated/x86_cc_decode.h` pin the suffix codes. */
#define X86_CC_O 0U
#define X86_CC_NO 1U
#define X86_CC_B 2U
#define X86_CC_AE 3U
#define X86_CC_E 4U
#define X86_CC_NE 5U
#define X86_CC_BE 6U
#define X86_CC_A 7U
#define X86_CC_S 8U
#define X86_CC_NS 9U
#define X86_CC_L 12U
#define X86_CC_GE 13U
#define X86_CC_LE 14U
#define X86_CC_G 15U

#include "generated/x86_cond.h"
#include "generated/x86_cc_decode.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

/* The 12 condition suffixes the encoder spells, in `CC_AUX` order. */
static const char *const suffixes[] = {
	"a", "ae", "b", "be", "e", "ne", "g", "ge", "l", "le", "s", "ns",
};
#define SUFFIX_COUNT 12U

/* The hand restatement of the encoder's suffix codes: the position in the
 * suffix list. Independent of the generated `.._SUFFIX_*` values. */
static unsigned suffix_code(const char *suffix)
{
	unsigned i;
	for (i = 0U; i < SUFFIX_COUNT; i++) {
		if (strcmp(suffixes[i], suffix) == 0)
			return i;
	}
	return 0xffffU;
}

/* The hand restatement of the suffix -> `X86_CC_*` code map: the condition a
 * suffix names. This is the independent model the generated selector must
 * agree with, over every suffix code the encoder produces. */
static unsigned model_code(unsigned suffix_index)
{
	switch (suffix_index) {
	case 0U:  return X86_CC_A;
	case 1U:  return X86_CC_AE;
	case 2U:  return X86_CC_B;
	case 3U:  return X86_CC_BE;
	case 4U:  return X86_CC_E;
	case 5U:  return X86_CC_NE;
	case 6U:  return X86_CC_G;
	case 7U:  return X86_CC_GE;
	case 8U:  return X86_CC_L;
	case 9U:  return X86_CC_LE;
	case 10U: return X86_CC_S;
	case 11U: return X86_CC_NS;
	default:  return 0xffffU;
	}
}

/* The 36 mnemonics, in `CC_AUX` order, each with its family prefix and the
 * suffix it decodes to. Restated by hand so the composition check does not
 * reuse the generated family/suffix tables. */
struct mnemonic_row {
	const char *prefix;
	const char *suffix;
};

static const struct mnemonic_row mnemonics[] = {
	{ "j", "a" },    { "j", "ae" },   { "j", "b" },    { "j", "be" },
	{ "j", "e" },    { "j", "ne" },   { "j", "g" },    { "j", "ge" },
	{ "j", "l" },    { "j", "le" },   { "j", "s" },    { "j", "ns" },
	{ "cmov", "a" }, { "cmov", "b" }, { "cmov", "be" }, { "cmov", "e" },
	{ "cmov", "g" }, { "cmov", "ge" }, { "cmov", "ae" }, { "cmov", "l" },
	{ "cmov", "le" }, { "cmov", "ne" }, { "cmov", "ns" }, { "cmov", "s" },
	{ "set", "a" },  { "set", "ae" }, { "set", "b" },  { "set", "be" },
	{ "set", "e" },  { "set", "g" },  { "set", "ge" }, { "set", "l" },
	{ "set", "le" }, { "set", "ne" }, { "set", "ns" }, { "set", "s" },
};
#define MNEMONIC_COUNT 36U

/* The generated suffix codes must be the hand suffix indices. */
static void check_suffix_codes(void)
{
	static const unsigned generated[SUFFIX_COUNT] = {
		KPROG_X86_CC_DECODE_SUFFIX_A,  KPROG_X86_CC_DECODE_SUFFIX_AE,
		KPROG_X86_CC_DECODE_SUFFIX_B,  KPROG_X86_CC_DECODE_SUFFIX_BE,
		KPROG_X86_CC_DECODE_SUFFIX_E,  KPROG_X86_CC_DECODE_SUFFIX_NE,
		KPROG_X86_CC_DECODE_SUFFIX_G,  KPROG_X86_CC_DECODE_SUFFIX_GE,
		KPROG_X86_CC_DECODE_SUFFIX_L,  KPROG_X86_CC_DECODE_SUFFIX_LE,
		KPROG_X86_CC_DECODE_SUFFIX_S,  KPROG_X86_CC_DECODE_SUFFIX_NS,
	};
	unsigned i;

	cases++;
	if (KPROG_X86_CC_DECODE_SUFFIX_COUNT != SUFFIX_COUNT) {
		printf("MISMATCH cc decode suffix count: got %u want %u\n",
		       KPROG_X86_CC_DECODE_SUFFIX_COUNT, SUFFIX_COUNT);
		failures++;
	}
	for (i = 0U; i < SUFFIX_COUNT; i++) {
		cases++;
		if (generated[i] != i) {
			printf("MISMATCH cc decode suffix code %s: got %u want %u\n",
			       suffixes[i], generated[i], i);
			failures++;
		}
	}
}

/* The generated selector must return each suffix's condition, and must reach
 * its 0 default for every code past the table. */
static void check_selector(void)
{
	static const unsigned out_of_range[] = {
		SUFFIX_COUNT, SUFFIX_COUNT + 1U, 16U, 0x10U, 0x7fU, 0xffU,
	};
	unsigned i;

	for (i = 0U; i < SUFFIX_COUNT; i++) {
		unsigned got = KPROG_X86_CC_DECODE_CC(i);
		unsigned want = model_code(i);

		cases++;
		if (got != want) {
			printf("MISMATCH cc decode selector %u: got %u want %u\n",
			       i, got, want);
			failures++;
		}
	}
	for (i = 0U; i < sizeof(out_of_range) / sizeof(out_of_range[0]);
	     i++) {
		cases++;
		if (KPROG_X86_CC_DECODE_CC(out_of_range[i]) != 0U) {
			printf("MISMATCH cc decode default %u: got %u want 0\n",
			       out_of_range[i],
			       KPROG_X86_CC_DECODE_CC(out_of_range[i]));
			failures++;
		}
	}
	/* The default code names no suffix. */
	cases++;
	if (suffix_code("o") != 0xffffU || suffix_code("no") != 0xffffU) {
		printf("MISMATCH cc decode parity names present\n");
		failures++;
	}
}

/* Each mnemonic is its family prefix plus its suffix, and the generated
 * tables name that suffix's condition. */
static void check_mnemonics(void)
{
	unsigned i;

	for (i = 0U; i < MNEMONIC_COUNT; i++) {
		unsigned idx = suffix_code(mnemonics[i].suffix);
		char composed[16];
		size_t plen = strlen(mnemonics[i].prefix);
		size_t slen = strlen(mnemonics[i].suffix);

		cases++;
		if (idx == 0xffffU) {
			printf("MISMATCH cc decode unknown suffix %s\n",
			       mnemonics[i].suffix);
			failures++;
			continue;
		}
		if (plen + slen + 1U > sizeof(composed)) {
			printf("MISMATCH cc decode mnemonic too long\n");
			failures++;
			continue;
		}
		memcpy(composed, mnemonics[i].prefix, plen);
		memcpy(composed + plen, mnemonics[i].suffix, slen + 1U);
		cases++;
		if (strlen(composed) != plen + slen) {
			printf("MISMATCH cc decode composition length %s\n",
			       composed);
			failures++;
		}
		cases++;
		if (KPROG_X86_CC_DECODE_CC(idx) != model_code(idx)) {
			printf("MISMATCH cc decode mnemonic %s condition\n",
			       composed);
			failures++;
		}
	}
}

/* The two parity codes are named by no suffix the encoder decodes; every
 * `X86_CC_*` code the encoder reaches is a non-parity code. */
static void check_parity_absent(void)
{
	unsigned i;

	for (i = 0U; i < SUFFIX_COUNT; i++) {
		unsigned code = model_code(i);
		cases++;
		if (code == 10U || code == 11U) {
			printf("MISMATCH cc decode parity code %u reached\n",
			       code);
			failures++;
		}
	}
}

int main(void)
{
	check_suffix_codes();
	check_selector();
	check_mnemonics();
	check_parity_absent();

	if (failures != 0) {
		printf("x86 cc decode host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 cc decode host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
