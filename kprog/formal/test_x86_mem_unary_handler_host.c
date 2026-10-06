/* Independent host oracle for x86 `INC/DEC/NEG/NOT [mem]` composition. */
typedef unsigned char __u8;
typedef unsigned long long __u64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_adc.h"
#include "generated/x86_add_flags.h"
#include "generated/x86_sub_flags.h"
#include "generated/x86_sbb_result.h"
#include "generated/x86_not.h"

#include <stdio.h>
#include <string.h>

enum op { OP_INC, OP_DEC, OP_NEG, OP_NOT };
struct flags { __u8 cf, zf, sf, of; };

static unsigned bits(unsigned w)
{
	return w == 1 ? 8 : w == 2 ? 16 : w == 4 ? 32 : 64;
}

static __u64 oracle_load(const __u8 *p, unsigned w)
{
	__u64 v = 0;
	for (unsigned i = 0; i < bits(w) / 8; i++)
		v += (__u64)p[i] * (1ULL << (8 * i));
	return v;
}

static __int128 signed_value(__u64 v, unsigned n)
{
	__uint128_t mod = ((__uint128_t)1) << n;
	__uint128_t sign = ((__uint128_t)1) << (n - 1);
	__uint128_t x = (__uint128_t)v & (mod - 1);
	return x & sign ? (__int128)(x - mod) : (__int128)x;
}

static struct flags generated_run(enum op op, __u8 mem[16], struct flags in,
				  unsigned w)
{
	__u64 m = KPROG_X86_WIDTH_MASK(w);
	__u64 sign = KPROG_X86_WIDTH_SIGN_MASK(w);
	__u64 a = KPROG_X86_MEM_LOAD(mem, w) & m;
	__u64 raw, r;
	struct flags out = in;

	switch (op) {
	case OP_INC: {
		__u8 old_cf = out.cf;
		raw = KPROG_X86_ADC_RESULT(a, 1, 0); r = raw & m;
		KPROG_X86_SET_ADD_FLAGS(out.cf, out.zf, out.sf, out.of,
			a, 1, r, sign);
		out.cf = old_cf;
		break;
	}
	case OP_DEC: {
		__u8 old_cf = out.cf;
		raw = KPROG_X86_SBB_RESULT(a, 1, 0); r = raw & m;
		KPROG_X86_SET_SUB_FLAGS(out.cf, out.zf, out.sf, out.of,
			a, 1, r, sign);
		out.cf = old_cf;
		break;
	}
	case OP_NEG:
		raw = KPROG_X86_SBB_RESULT(0, a, 0); r = raw & m;
		KPROG_X86_SET_SUB_FLAGS(out.cf, out.zf, out.sf, out.of,
			0, a, r, sign);
		break;
	default:
		raw = KPROG_X86_NOT_RESULT(a); r = raw & m;
		KPROG_X86_PRESERVE_FLAGS();
		break;
	}
	KPROG_X86_MEM_STORE(mem, w, r);
	return out;
}

static struct flags oracle_run(enum op op, __u8 mem[16], struct flags in,
			       unsigned w)
{
	unsigned n = bits(w);
	__uint128_t mod = ((__uint128_t)1) << n;
	__u64 a = oracle_load(mem, w) & (mod - 1);
	__int128 lo = -((__int128)1 << (n - 1));
	__int128 hi = ((__int128)1 << (n - 1)) - 1;
	__int128 sr;
	__u64 r;
	struct flags out = in;

	switch (op) {
	case OP_INC:
		r = (__u64)(((__uint128_t)a + 1) & (mod - 1));
		sr = signed_value(a, n) + 1;
		out.zf = r == 0;
		out.sf = !!(r & (1ULL << (n - 1)));
		out.of = sr < lo || sr > hi;
		break;
	case OP_DEC:
		r = (__u64)(((__uint128_t)a - 1) & (mod - 1));
		sr = signed_value(a, n) - 1;
		out.zf = r == 0;
		out.sf = !!(r & (1ULL << (n - 1)));
		out.of = sr < lo || sr > hi;
		break;
	case OP_NEG:
		r = (__u64)((0 - (__uint128_t)a) & (mod - 1));
		sr = -signed_value(a, n);
		out.cf = a != 0;
		out.zf = r == 0;
		out.sf = !!(r & (1ULL << (n - 1)));
		out.of = sr < lo || sr > hi;
		break;
	default:
		r = (~a) & (mod - 1);
		break;
	}
	for (unsigned i = 0; i < n / 8; i++)
		mem[i] = (__u8)(r >> (8 * i));
	return out;
}

static int check(enum op op, __u64 lhs, struct flags in, unsigned w)
{
	__u8 got_mem[16], want_mem[16];
	for (unsigned i = 0; i < 16; i++)
		got_mem[i] = want_mem[i] = i < 8 ? (__u8)(lhs >> (8 * i)) :
			(__u8)(0xa0 + i);
	struct flags got = generated_run(op, got_mem, in, w);
	struct flags want = oracle_run(op, want_mem, in, w);

	if (memcmp(got_mem, want_mem, sizeof(got_mem)) ||
	    got.cf != want.cf || got.zf != want.zf ||
	    got.sf != want.sf || got.of != want.of) {
		printf("MISMATCH op=%u w=%u lhs=%#llx in=%u%u%u%u got=%u%u%u%u want=%u%u%u%u\n",
		       op, w, lhs, in.cf, in.zf, in.sf, in.of,
		       got.cf, got.zf, got.sf, got.of,
		       want.cf, want.zf, want.sf, want.of);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 v[] = { 0, 1, ~0ULL, 0x7f, 0x80,
		0x7fffffffULL, 0x80000000ULL, 0x8000000000000000ULL };
	static const unsigned w[] = { 1, 2, 4, 8 };
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 4; op++)
		for (unsigned wi = 0; wi < 4; wi++)
			for (unsigned a = 0; a < 8; a++)
				for (unsigned f = 0; f < 16; f++) {
					struct flags in = { f & 1, (f >> 1) & 1,
						(f >> 2) & 1, (f >> 3) & 1 };
					fails += check((enum op)op, v[a], in, w[wi]);
					cases++;
				}
	__u64 state = 0xda942042e4dd58b5ULL;
	for (unsigned i = 0; i < 20000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 lhs = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		struct flags in = { state & 1, (state >> 1) & 1,
			(state >> 2) & 1, (state >> 3) & 1 };
		fails += check((enum op)(i & 3), lhs, in, w[(i >> 2) & 3]);
		cases++;
	}
	if (fails) {
		printf("x86 memory-unary host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 memory-unary host cross-check: OK (%u cases)\n", cases);
	return 0;
}
