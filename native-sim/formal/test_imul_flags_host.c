/*
 * Host cross-check of the generated KPROG_X86_SET_IMUL_FLAGS macro against an
 * independent __int128 reference.
 *
 * Build + run (from native-sim/formal):
 *   cc -Wall -Wextra -O2 -I. test_imul_flags_host.c -o /tmp/t_imul && /tmp/t_imul
 *
 * The generated header defines KPROG_X86_SET_IMUL_FLAGS but relies on __u8/__u64
 * being in scope (exactly as the BPF program supplies them), so we typedef them
 * here before including it.
 */
typedef unsigned char __u8;
typedef unsigned long long __u64;

#include "generated/x86_imul_flags.h"

#include <stdio.h>
#include <stdlib.h>

/* --- width helpers, mirroring KPROG_X86_WIDTH_* (codes: 1=8,2=16,4=32,8=64) --- */

static unsigned int bits(unsigned char width)
{
	switch (width) {
	case 1: return 8;
	case 2: return 16;
	case 4: return 32;
	default: return 64;
	}
}

static unsigned long long mask(unsigned char width)
{
	switch (width) {
	case 1: return 0xffULL;
	case 2: return 0xffffULL;
	case 4: return 0xffffffffULL;
	default: return 0xffffffffffffffffULL;
	}
}

/* Magnitude of the width-narrowed signed value (two's complement masked),
 * mirroring x86_signed_abs_width in x86_sim.h. */
static __u64 signed_abs(unsigned long long value, unsigned char width)
{
	__u64 m = mask(width);
	__u64 narrowed = value & m;
	__u64 sign = 1ULL << (bits(width) - 1);

	if (!(narrowed & sign))
		return narrowed;
	return ((~narrowed) + 1) & m;
}

/* Overflow limit, mirroring the simulator's __x86_imul_limit: the register's raw
 * (LHS)^(RHS) is tested against the width's sign bit to pick max magnitude
 * (opposite signs) vs max-1 (same sign). */
static __u64 limit(unsigned char width, unsigned long long lhs, unsigned long long rhs)
{
	__u64 sign = 1ULL << (bits(width) - 1);

	return (((lhs ^ rhs) & sign) ? sign : sign - 1);
}

/* Independent oracle: sign-extend lhs/rhs to the width, multiply in __int128,
 * and report overflow when the product leaves the signed width range. */
static unsigned int oracle_overflow(unsigned long long lhs, unsigned long long rhs,
				    unsigned char width)
{
	unsigned int b = bits(width);
	__u64 m = mask(width);

	__int128 sl = (__int128)(lhs & m);
	__int128 sr = (__int128)(rhs & m);
	__int128 h = (__int128)1 << (b - 1); /* 1<<7 .. 1<<63, well-defined */
	__int128 two_h = h + h;

	if (sl >= h)
		sl -= two_h;
	if (sr >= h)
		sr -= two_h;

	__int128 prod = sl * sr;
	__int128 maxv = h - 1;
	__int128 minv = -h;

	return (prod > maxv || prod < minv) ? 1 : 0;
}

static __u8 gen_overflow(unsigned long long lhs, unsigned long long rhs,
			 unsigned char width)
{
	__u8 cf = 0, of = 0;
	__u64 a_abs = signed_abs(lhs, width);
	__u64 b_abs = signed_abs(rhs, width);
	__u64 lim = limit(width, lhs, rhs);

	KPROG_X86_SET_IMUL_FLAGS(cf, of, a_abs, b_abs, lim);
	(void)of;
	return cf;
}

/* --- fixed-seed LCG: lhs/rhs as deterministic 64-bit draws --- */
static unsigned long long lcg_state = 0x12345678ULL;

static unsigned long long next_rand(void)
{
	lcg_state = lcg_state * 6364136223846793005ULL + 1442695040888963407ULL;
	return lcg_state;
}

struct vec {
	unsigned long long lhs;
	unsigned long long rhs;
	unsigned char width;
	unsigned int expect; /* 1 = overflow (T), 0 = no overflow (F) */
};

int main(void)
{
	/*
	 * Test vectors: lhs/rhs in 64-bit artifact form, width code, expected overflow.
	 * (0x0164,0xfe3c,w16)=T is the discriminator for the old spurious-conjunct bug:
	 * 356 * -452 = -160912, outside 16-bit range, so the old wrong formula (which
	 * mis-picked the limit) would have reported no overflow.
	 */
	const struct vec vecs[] = {
		/* w8 */
		{0x7f, 0x7f, 1, 1},
		{0x7f, 0x02, 1, 1},
		{0x80, 0x01, 1, 0},
		{0x80, 0xff, 1, 1},
		{0x00, 0x80, 1, 0},
		/* w16 */
		{0x7fff, 0x0002, 2, 1},
		{0x8000, 0xffff, 2, 1},
		{0xfe3c, 0x012c, 2, 1},
		{0x0164, 0xfe3c, 2, 1},
		{0x8000, 0x0001, 2, 0},
		/* w32 */
		{0x7fffffff, 0x2, 4, 1},
		{0x80000000, 0xffffffff, 4, 1},
		{0x80000000, 0x1, 4, 0},
		/* w64 */
		{0xffffffffffffffffULL, 0x2, 8, 0},
		{0x8000000000000000ULL, 0xffffffffffffffffULL, 8, 1},
	};
	const size_t nvecs = sizeof(vecs) / sizeof(vecs[0]);
	unsigned long cases = 0;

	for (size_t i = 0; i < nvecs; i++) {
		unsigned int got = gen_overflow(vecs[i].lhs, vecs[i].rhs, vecs[i].width);
		unsigned int ref = oracle_overflow(vecs[i].lhs, vecs[i].rhs, vecs[i].width);
		if (got != vecs[i].expect || ref != vecs[i].expect) {
			fprintf(stderr,
				"MISMATCH vec[%zu] lhs=%#llx rhs=%#llx w=%u expect=%d gen=%u oracle=%u\n",
				i, (unsigned long long)vecs[i].lhs,
				(unsigned long long)vecs[i].rhs, vecs[i].width,
				vecs[i].expect, got, ref);
			return 1;
		}
		cases++;
	}

	/* Fixed-seed LCG sweep: 20000 iterations, width round-robins over the codes. */
	static const unsigned char widths[] = {1, 2, 4, 8};
	const unsigned long nsweep = 20000;

	for (unsigned long it = 0; it < nsweep; it++) {
		unsigned long long lhs = next_rand();
		unsigned long long rhs = next_rand();
		unsigned char width = widths[it & 3];

		unsigned int got = gen_overflow(lhs, rhs, width);
		unsigned int ref = oracle_overflow(lhs, rhs, width);
		if (got != ref) {
			fprintf(stderr,
				"MISMATCH sweep[%lu] lhs=%#llx rhs=%#llx w=%u gen=%u oracle=%u\n",
				it, lhs, rhs, width, got, ref);
			return 1;
		}
		cases++;
	}

	printf("imul flags host cross-check: OK (%lu vectors + %lu sweep cases)\n",
	       nvecs, nsweep);
	(void)cases;
	return 0;
}
