/*
 * Cross-ISA differential cross-check: the same input through both simulators'
 * compiled contracts.
 *
 * `CrossIsaWidth.lean` and `CrossIsaStackArena.lean` prove the two generated
 * Lean contracts agree. Those theorems say nothing about the C the simulators
 * actually trade in: each ISA has its own generated header, and a generator
 * that rendered the Lean and the C from one spec could still emit C that
 * disagrees where the Lean does not -- or the hand-written C could drift from
 * its own Lean. This oracle includes both simulators in one translation unit
 * (they coexist, since every decode is ISA-prefixed) and compares the compiled
 * macros on shared inputs.
 *
 * Two families:
 *
 *   widths  the four width codes' masks and bit counts, over values that
 *           exercise each boundary (zero, all-ones, the sign bits, a pattern
 *           with every lane distinct).
 *
 *   stack   the access-window and pointer bounds over a capacity/index/width
 *           grid that includes both arenas' real sizes (64, 128, 160) and the
 *           one-past-end indices. The two ISAs have different arena geometry
 *           -- x86 biases by the capacity, arm64 by 96 -- but the *bound* is
 *           a function of capacity alone, so the two must agree.
 *
 * Exit 1 on any difference.
 *
 * Build/run (from kprog/formal):
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      cross_isa_differential_host.c -o /tmp/t_xdiff
 *   /tmp/t_xdiff
 */
#define ARM64_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK 1

#include "arm64_sim_local_bpf.h"
#include "x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static int cases;

static void cmp_u64(const char *what, unsigned long long a,
		    unsigned long long x)
{
	cases++;
	if (a != x) {
		printf("DIFF %s: arm64=%#llx x86=%#llx\n", what, a, x);
		failures++;
	}
}

static void cmp_int(const char *what, int a, int x)
{
	cases++;
	if (a != x) {
		printf("DIFF %s: arm64=%d x86=%d\n", what, a, x);
		failures++;
	}
}

/* The shared width codes and the values that exercise each boundary. */
static void check_widths(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 0xffULL, 0x123456789abcdefULL, ~0ULL,
		0x80000000ULL, 0x7fffffffULL, 0x80ULL, 0x8000ULL,
	};
	unsigned i;

	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
		cmp_u64("w8 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_8) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_8) & values[i]);
		cmp_u64("w16 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_16) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_16) & values[i]);
		cmp_u64("w32 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_32) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_32) & values[i]);
		cmp_u64("w64 mask",
			KPROG_ARM64_WIDTH_MASK(ARM64_WIDTH_64) & values[i],
			KPROG_X86_WIDTH_MASK(X86_WIDTH_64) & values[i]);
	}

	cmp_u64("bits w8", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_8),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_8));
	cmp_u64("bits w16", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_16),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_16));
	cmp_u64("bits w32", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_32),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_32));
	cmp_u64("bits w64", KPROG_ARM64_WIDTH_BITS(ARM64_WIDTH_64),
		KPROG_X86_WIDTH_BITS(X86_WIDTH_64));

	/* The sign masks are the one non-obvious pair: each ISA must place the
	 * sign bit at its own width, so a drift here is a signedness bug. */
	cmp_u64("sign w8", KPROG_ARM64_WIDTH_SIGN_MASK(ARM64_WIDTH_8),
		KPROG_X86_WIDTH_SIGN_MASK(X86_WIDTH_8));
	cmp_u64("sign w32", KPROG_ARM64_WIDTH_SIGN_MASK(ARM64_WIDTH_32),
		KPROG_X86_WIDTH_SIGN_MASK(X86_WIDTH_32));
	cmp_u64("sign w64", KPROG_ARM64_WIDTH_SIGN_MASK(ARM64_WIDTH_64),
		KPROG_X86_WIDTH_SIGN_MASK(X86_WIDTH_64));
}

/* The shared stack bounds, over both arenas' real sizes and the edges. */
static void check_stack_bounds(void)
{
	static const unsigned capacities[] = { 1U, 8U, 64U, 128U, 160U };
	static const unsigned indices[] = {
		0U, 1U, 7U, 8U, 56U, 63U, 64U, 120U, 152U, 159U, 160U, 161U
	};
	static const unsigned widths[] = { 1U, 2U, 4U, 8U };
	unsigned c, i, w;

	for (c = 0; c < sizeof(capacities) / sizeof(capacities[0]); c++)
		for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++)
			for (w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
				cmp_int("window fits",
					KPROG_ARM64_STACK_WINDOW_FITS(
						indices[i], widths[w],
						capacities[c]),
					KPROG_X86_STACK_WINDOW_FITS(
						indices[i], widths[w],
						capacities[c]));

	for (c = 0; c < sizeof(capacities) / sizeof(capacities[0]); c++)
		for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++)
			cmp_int("pointer fits",
				KPROG_ARM64_STACK_POINTER_FITS(
					(long)indices[i], capacities[c]),
				KPROG_X86_STACK_POINTER_FITS(
					(long)indices[i], capacities[c]));

	/* The word-slot and alignment arithmetic the fast path depends on. */
	for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
		cmp_u64("word index",
			KPROG_ARM64_STACK_WORD_INDEX(indices[i]),
			KPROG_X86_STACK_WORD_INDEX(indices[i]));
		cmp_int("word aligned",
			KPROG_ARM64_STACK_WORD_ALIGNED(indices[i]),
			KPROG_X86_STACK_WORD_ALIGNED(indices[i]));
	}
	for (c = 0; c < sizeof(capacities) / sizeof(capacities[0]); c++)
		cmp_u64("words",
			KPROG_ARM64_STACK_WORDS(capacities[c]),
			KPROG_X86_STACK_WORDS(capacities[c]));
}

/*
 * The one flag the two architectures define in opposite polarities.
 *
 * AArch64's subtract carry is not-borrow (`lhs >= rhs`), x86-64's is borrow
 * (`lhs < rhs`); `CrossIsaFlags.lean` proves the two complements. This pins
 * the same relation at the layer that compiles, and pins the three flags that
 * *should* agree (zero, sign, overflow) alongside it -- a drift in any of them
 * would be a real bug rather than an architectural difference.
 */
static void check_flags(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 2ULL, 0xffULL, 0x80ULL, 0x100ULL,
		0x7fffffffULL, 0x80000000ULL, 0xffffffffULL,
		0x123456789abcdefULL, ~0ULL, 0x8000000000000000ULL,
	};
	static const unsigned wids[] = { 1U, 2U, 4U, 8U };
	unsigned i, j, w;

	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
		for (j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
			for (w = 0; w < sizeof(wids) / sizeof(wids[0]); w++) {
				unsigned a_n, a_z, a_c, a_v;
				unsigned x_cf, x_zf, x_sf, x_of;
				unsigned long long a, b, sign;

				a = values[i];
				b = values[j];

				KPROG_ARM64_SET_SUB_FLAGS(a_n, a_z, a_c, a_v, a, b, wids[w]);
				sign = KPROG_X86_WIDTH_SIGN_MASK(wids[w]);
				KPROG_X86_SET_SUB_FLAGS(x_cf, x_zf, x_sf, x_of,
							a & KPROG_X86_WIDTH_MASK(wids[w]),
							b & KPROG_X86_WIDTH_MASK(wids[w]),
							(a - b) & KPROG_X86_WIDTH_MASK(wids[w]),
							sign);

				/* carry is deliberately opposite */
				cmp_int("carry complements", a_c, !x_cf);
				/* these three are not */
				cmp_int("zero agrees", !!a_z, !!x_zf);
				cmp_int("sign agrees", !!a_n, !!x_sf);
				cmp_int("overflow agrees", !!a_v, !!x_of);
			}
		}
	}
}

/*
 * The branches, at the layer that compiles.
 *
 * `CrossIsaCond.lean` proves the two evaluators agree under the flag
 * correspondence (N Z C V) = (SF ZF (!CF) OF), with the mapping CS->AE,
 * CC->B, MI->S, HI->A, LS->BE. This pins the same table in the generated C,
 * which is where an inverted entry would actually miscompile.
 */
static int unreachable_cond(void)
{
	printf("condition evaluator fell through to its default arm\n");
	failures++;
	return 0;
}

static void check_conditions(void)
{
	/* one arm64 condition, its x86 counterpart, and a name for the pair */
	static const struct {
		unsigned a64;
		unsigned x86;
		const char *name;
	} pairs[] = {
		{ ARM64_COND_EQ, X86_CC_E,   "eq/e" },
		{ ARM64_COND_NE, X86_CC_NE,  "ne/ne" },
		{ ARM64_COND_CS, X86_CC_AE,  "cs/ae" },
		{ ARM64_COND_CC, X86_CC_B,   "cc/b" },
		{ ARM64_COND_MI, X86_CC_S,   "mi/s" },
		{ ARM64_COND_PL, X86_CC_NS,  "pl/ns" },
		{ ARM64_COND_VS, X86_CC_O,   "vs/o" },
		{ ARM64_COND_VC, X86_CC_NO,  "vc/no" },
		{ ARM64_COND_HI, X86_CC_A,   "hi/a" },
		{ ARM64_COND_LS, X86_CC_BE,  "ls/be" },
		{ ARM64_COND_GE, X86_CC_GE,  "ge/ge" },
		{ ARM64_COND_LT, X86_CC_L,   "lt/l" },
		{ ARM64_COND_GT, X86_CC_G,   "gt/g" },
		{ ARM64_COND_LE, X86_CC_LE,  "le/le" },
	};
	unsigned mask, i, cf, zf, sf, of, a_n, a_z, a_c, a_v;

	/* The evaluator's default arm is a statement expression that calls
	 * UNSUPPORTED; pass a real function so it is not a no-op statement. */

	/* every combination of the four flags */
	for (mask = 0; mask < 16U; mask++) {
		cf = (mask >> 0) & 1U;
		zf = (mask >> 1) & 1U;
		sf = (mask >> 2) & 1U;
		of = (mask >> 3) & 1U;
		a_n = sf;
		a_z = zf;
		a_c = !cf;	/* the polarity relation 0490 proved */
		a_v = of;

		for (i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++) {
			cmp_int(pairs[i].name,
				!!KPROG_ARM64_EVAL_COND(pairs[i].a64, a_n, a_z,
							 a_c, a_v,
							 unreachable_cond()),
				!!KPROG_X86_EVAL_CC(pairs[i].x86, cf, zf, sf, of));
		}
	}
}

/*
 * The shifts, at the two widths AArch64 actually encodes.
 *
 * Both ISAs mask the shift amount, but by different rules: AArch64 takes it
 * modulo 32 at 32-bit width and modulo 64 at 64-bit width, while x86-64 takes
 * it modulo 64 at 64 bits and modulo 32 otherwise (it has no 8- or 16-bit
 * shift). At W and X the rules coincide, so the same value shifted the same
 * way gives the same result. `CrossIsaShift.lean` proves the correspondence
 * and that it holds exactly on the encoded widths; this pins it in the C.
 *
 * The narrower widths are deliberately excluded: there the contracts really
 * do differ (an amount of 32 shifts by 0 on AArch64 and by 32 on x86-64), and
 * AArch64 never encodes them, so including them would report a difference
 * that no program can reach.
 */
static void check_shifts(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 0xffULL, 0x80ULL, 0x80000000ULL, 0xffffffffULL,
		0x100000001ULL, 0x123456789abcdefULL, ~0ULL,
		0x8000000000000000ULL, 0xdeadbeefcafeULL,
	};
	static const unsigned long long amounts[] = {
		0ULL, 1ULL, 7ULL, 8ULL, 15ULL, 16ULL, 31ULL, 32ULL, 33ULL,
		63ULL, 64ULL, 65ULL, 127ULL,
	};
	static const struct { unsigned a64; unsigned x86; const char *name; } wids[] = {
		{ ARM64_WIDTH_32, X86_WIDTH_32, "shift w32" },
		{ ARM64_WIDTH_64, X86_WIDTH_64, "shift w64" },
	};
	unsigned vi, ai, wi;

	for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++)
		for (ai = 0; ai < sizeof(amounts) / sizeof(amounts[0]); ai++)
			for (wi = 0; wi < sizeof(wids) / sizeof(wids[0]); wi++) {
				unsigned long long v = values[vi];
				unsigned long long m = amounts[ai];
				unsigned long long mask;
				mask = KPROG_ARM64_WIDTH_MASK(wids[wi].a64);
				cmp_u64("lsl", KPROG_ARM64_SHIFT_VALUE(ARM64_SHIFT_LSL, v, m,
						wids[wi].a64, unreachable_cond()) & mask,
					kprog_x86_shl_result(v, m, wids[wi].x86) & mask);
				cmp_u64("lsr", KPROG_ARM64_SHIFT_VALUE(ARM64_SHIFT_LSR, v, m,
						wids[wi].a64, unreachable_cond()) & mask,
					kprog_x86_shr_result(v, m, wids[wi].x86) & mask);
				cmp_u64("asr", KPROG_ARM64_SHIFT_VALUE(ARM64_SHIFT_ASR, v, m,
						wids[wi].a64, unreachable_cond()) & mask,
					kprog_x86_sar_result(v, m, wids[wi].x86) & mask);
				cmp_u64("ror", KPROG_ARM64_SHIFT_VALUE(ARM64_SHIFT_ROR, v, m,
						wids[wi].a64, unreachable_cond()) & mask,
					kprog_x86_ror_result(v, m, wids[wi].x86) & mask);
			}
}

/*
 * Sign extension, exhaustively.
 *
 * AArch64 states its extension generically (extend the low nb bits) and its C
 * inlines the mask-flip-subtract idiom; x86-64 states each width as its own
 * arm with the constants written out. Two spellings of one function, and the
 * fault mode is a signedness slip that still round-trips for positive inputs,
 * which is exactly what sampling misses. Both paths are small enough to run
 * every input: all 65,536 sixteen-bit patterns through the byte and halfword
 * extensions, and a stride across the 32-bit space.
 */
static void check_sign_extend(void)
{
	unsigned long long v;

	for (v = 0; v < 0x10000ULL; v++) {
		cmp_u64("sxtb",
			KPROG_ARM64_EXTREV_VALUE(ARM64_OP_SXTB, v, 0, 0,
						 ARM64_WIDTH_64,
						 unreachable_cond()),
			kprog_x86_sign_extend_value(v, X86_WIDTH_8));
		cmp_u64("sxth",
			KPROG_ARM64_EXTREV_VALUE(ARM64_OP_SXTH, v, 0, 0,
						 ARM64_WIDTH_64,
						 unreachable_cond()),
			kprog_x86_sign_extend_value(v, X86_WIDTH_16));
	}
	for (v = 0; v < 0x100000000ULL; v += 0x10001ULL)
		cmp_u64("sxtw",
			KPROG_ARM64_EXTREV_VALUE(ARM64_OP_SXTW, v, 0, 0,
						 ARM64_WIDTH_64,
						 unreachable_cond()),
			kprog_x86_sign_extend_value(v, X86_WIDTH_32));
}

/*
 * Byte reversal, where both sides do the same thing by different means.
 *
 * AArch64's REV is a shift-and-mask disjunction over the destination width;
 * x86-64's BSWAP picks the width and then reverses over it, clearing above.
 * A byte-reversal fault is quiet -- swap two of the eight terms and most
 * inputs still change plausibly -- so this runs a pseudo-random stream rather
 * than round numbers, and checks the involution as well as the agreement: an
 * order-two permutation is what distinguishes a correct reversal from one that
 * merely produces some permutation.
 */
static void check_byte_reversal(void)
{
	unsigned long long x = 0x243f6a8885a308d3ULL;
	unsigned long long i, v, a, b;

	for (i = 0; i < 200000ULL; i++) {
		x = x * 6364136223846793005ULL + 1442695040888963407ULL;
		v = x;

		a = KPROG_ARM64_EXTREV_VALUE(ARM64_OP_REV, v, 0, 0,
					     ARM64_WIDTH_64, unreachable_cond());
		b = kprog_x86_bswap_value(v, X86_WIDTH_64);
		cmp_u64("rev w64", a, b);
		/* the involution, on the AArch64 contract directly */
		cmp_u64("rev tw64", KPROG_ARM64_EXTREV_VALUE(ARM64_OP_REV, a, 0, 0,
							      ARM64_WIDTH_64,
							      unreachable_cond()),
			v);

		a = KPROG_ARM64_EXTREV_VALUE(ARM64_OP_REV, v, 0, 0,
					     ARM64_WIDTH_32, unreachable_cond());
		b = kprog_x86_bswap_value(v, X86_WIDTH_32);
		cmp_u64("rev w32", a, b);
		cmp_u64("rev tw32", KPROG_ARM64_EXTREV_VALUE(ARM64_OP_REV, a, 0, 0,
							      ARM64_WIDTH_32,
							      unreachable_cond()),
			v & 0xffffffffULL);
	}
}

/*
 * The memory-offset core, which is the part both ISAs compute.
 *
 * AArch64 has no scale and x86-64 has no pre/post-indexing, so the contracts
 * differ in what they parameterise -- but the shared term is
 * base + (index <<< scale), and at unit scale with writeback off AArch64's
 * offset reduces to x86-64's. This checks that reduction in C over values
 * chosen to exercise the wrap, since both accumulate with 64-bit two's
 * complement and a signed/unsigned slip there would agree on small inputs.
 */
static void check_mem_offset(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 7ULL, 0x1000ULL, 0x7fffffffffffffffULL,
		0x8000000000000000ULL, 0xffffffffffffffffULL,
		0xfffffffffffffffeULL, 0xdeadbeefcafeULL,
	};
	unsigned i, j;

	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++)
		for (j = 0; j < sizeof(values) / sizeof(values[0]); j++) {
			unsigned long long imm = values[i];
			unsigned long long idx = values[j];
			unsigned long long a64, x86;

			/* has_index = true, unit scale, no writeback */
			a64 = KPROG_ARM64_MEM_OFFSET(0, 1, imm, idx);
			x86 = KPROG_X86_MEM_OFFSET(0 /* scale log2 */, imm, idx, 1);
			cmp_u64("offset indexed", a64, x86);

			/* has_index = false: the displacement alone */
			a64 = KPROG_ARM64_MEM_OFFSET(0, 0, imm, idx);
			x86 = KPROG_X86_MEM_OFFSET(0, imm, idx, 0);
			cmp_u64("offset plain", a64, x86);

			/* and the wrap itself, stated on both sides */
			cmp_u64("offset wraps",
				KPROG_X86_MEM_OFFSET(0, imm, idx, 1),
				imm + idx);
		}
}

/*
 * The shared ALU vocabulary, in the compiled tables.
 *
 * Both ISAs dispatch arithmetic-logic through one generated table, but they are
 * numbered differently and cover different sets, so the shared vocabulary has
 * to be recovered by a mapping rather than by matching codes. Five operations
 * map one-to-one (add, sub, and, orr/or, eor/xor); AArch64's BIC complements
 * the right operand while x86-64's ANDN complements the left, so that pair
 * corresponds only on exchanged arguments.
 */
static void check_alu_tables(void)
{
	static const unsigned long long vals[] = {
		0ULL, 1ULL, 3ULL, 5ULL, 0xffULL, 0x0fULL, 0x80ULL,
		0x7fffffffffffffffULL, 0x8000000000000000ULL,
		0xffffffffffffffffULL, 0x123456789abcdefULL, 0xdeadbeefcafeULL,
	};
	unsigned i, j;

	for (i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
		for (j = 0; j < sizeof(vals) / sizeof(vals[0]); j++) {
			unsigned long long a = vals[i], b = vals[j];

			cmp_u64("alu add",
				KPROG_ALU64_RESULT(ARM64_ALU_ADD, a, b, unreachable_cond()),
				KPROG_X86_ALU_RESULT(a, b, X86_ALU_ADD, X86_WIDTH_64,
						     unreachable_cond()));
			cmp_u64("alu sub",
				KPROG_ALU64_RESULT(ARM64_ALU_SUB, a, b, unreachable_cond()),
				KPROG_X86_ALU_RESULT(a, b, X86_ALU_SUB, X86_WIDTH_64,
						     unreachable_cond()));
			cmp_u64("alu and",
				KPROG_ALU64_RESULT(ARM64_ALU_AND, a, b, unreachable_cond()),
				KPROG_X86_ALU_RESULT(a, b, X86_ALU_AND, X86_WIDTH_64,
						     unreachable_cond()));
			cmp_u64("alu orr/or",
				KPROG_ALU64_RESULT(ARM64_ALU_ORR, a, b, unreachable_cond()),
				KPROG_X86_ALU_RESULT(a, b, X86_ALU_OR, X86_WIDTH_64,
						     unreachable_cond()));
			cmp_u64("alu eor/xor",
				KPROG_ALU64_RESULT(ARM64_ALU_EOR, a, b, unreachable_cond()),
				KPROG_X86_ALU_RESULT(a, b, X86_ALU_XOR, X86_WIDTH_64,
						     unreachable_cond()));

			/* BIC complements the right operand, ANDN the left. The
			 * correspondence therefore pairs BIC(a,b) with ANDN(b,a) --
			 * x86's formula `(~src1) & src2` at src1=b, src2=a. */
			cmp_u64("alu bic/andn exchanged",
				KPROG_ALU64_RESULT(ARM64_ALU_BIC, a, b, unreachable_cond()),
				((~(unsigned long long)b) & (unsigned long long)a));
			cmp_u64("alu bic shape",
				KPROG_ALU64_RESULT(ARM64_ALU_BIC, a, b, unreachable_cond()),
				a & (~~~b));
		}
}

int main(void)
{
	check_widths();
	check_stack_bounds();
	check_flags();
	check_conditions();
	check_shifts();
	check_sign_extend();
	check_byte_reversal();
	check_mem_offset();
	check_alu_tables();

	if (failures) {
		printf("cross-ISA differential cross-check: FAIL (%d/%d)\n",
		       failures, cases);
		return 1;
	}
	printf("cross-ISA differential cross-check: OK (%d cases)\n", cases);
	return 0;
}