/* Independent host oracle for x86 `ALU [mem], rhs` composition. */
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
#include "generated/x86_sbb_flags.h"

#include <stdio.h>
#include <string.h>

enum op { OP_ADD, OP_ADC, OP_SUB, OP_SBB };
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

static struct flags generated_run(enum op op, __u8 mem[16], __u64 rhs,
				  struct flags in, unsigned w)
{
	__u64 m = KPROG_X86_WIDTH_MASK(w);
	__u64 sign = KPROG_X86_WIDTH_SIGN_MASK(w);
	__u64 a = KPROG_X86_MEM_LOAD(mem, w) & m;
	__u64 b = rhs & m;
	__u64 raw, r;
	struct flags out = in;

	switch (op) {
	case OP_ADD:
		raw = KPROG_X86_ADC_RESULT(a, b, 0); r = raw & m;
		KPROG_X86_SET_ADD_FLAGS(out.cf, out.zf, out.sf, out.of,
			a, b, r, sign);
		break;
	case OP_ADC:
		raw = KPROG_X86_ADC_RESULT(a, b, in.cf); r = raw & m;
		KPROG_X86_SET_ADC_FLAGS(out.cf, out.zf, out.sf, out.of,
			a, b, r, sign, in.cf);
		break;
	case OP_SUB:
		raw = KPROG_X86_SBB_RESULT(a, b, 0); r = raw & m;
		KPROG_X86_SET_SUB_FLAGS(out.cf, out.zf, out.sf, out.of,
			a, b, r, sign);
		break;
	default:
		raw = KPROG_X86_SBB_RESULT(a, b, in.cf); r = raw & m;
		KPROG_X86_SET_SBB_FLAGS(out.cf, out.zf, out.sf, out.of,
			a, b, r, sign, in.cf);
		break;
	}
	KPROG_X86_MEM_STORE(mem, w, r);
	return out;
}

static struct flags oracle_run(enum op op, __u8 mem[16], __u64 rhs,
			       struct flags in, unsigned w)
{
	unsigned n = bits(w);
	__uint128_t mod = ((__uint128_t)1) << n;
	__u64 a = oracle_load(mem, w) & (mod - 1);
	__u64 b = rhs & (mod - 1);
	__u8 carry = (op == OP_ADC || op == OP_SBB) ? !!in.cf : 0;
	__int128 lo = -((__int128)1 << (n - 1));
	__int128 hi = ((__int128)1 << (n - 1)) - 1;
	__int128 sr;
	__u64 r;
	struct flags out;

	if (op == OP_ADD || op == OP_ADC) {
		__uint128_t wide = (__uint128_t)a + b + carry;
		r = (__u64)(wide & (mod - 1));
		out.cf = wide >= mod;
		sr = signed_value(a, n) + signed_value(b, n) + carry;
	} else {
		__uint128_t sub = (__uint128_t)b + carry;
		r = (__u64)(((__uint128_t)a - sub) & (mod - 1));
		out.cf = (__uint128_t)a < sub;
		sr = signed_value(a, n) - signed_value(b, n) - carry;
	}
	out.zf = r == 0;
	out.sf = !!(r & (1ULL << (n - 1)));
	out.of = sr < lo || sr > hi;
	for (unsigned i = 0; i < n / 8; i++)
		mem[i] = (__u8)(r >> (8 * i));
	return out;
}

static int check(enum op op, __u64 lhs, __u64 rhs, struct flags in,
		 unsigned w)
{
	__u8 got_mem[16], want_mem[16];
	for (unsigned i = 0; i < 16; i++)
		got_mem[i] = want_mem[i] = i < 8 ? (__u8)(lhs >> (8 * i)) :
			(__u8)(0xa0 + i);
	struct flags got = generated_run(op, got_mem, rhs, in, w);
	struct flags want = oracle_run(op, want_mem, rhs, in, w);

	if (memcmp(got_mem, want_mem, sizeof(got_mem)) ||
	    got.cf != want.cf || got.zf != want.zf ||
	    got.sf != want.sf || got.of != want.of) {
		printf("MISMATCH op=%u w=%u lhs=%#llx rhs=%#llx got=%u%u%u%u want=%u%u%u%u\n",
		       op, w, lhs, rhs, got.cf, got.zf, got.sf, got.of,
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
				for (unsigned b = 0; b < 8; b++)
					for (unsigned c = 0; c < 2; c++) {
						struct flags f = { c, 1, 1, 1 };
						fails += check((enum op)op, v[a], v[b], f, w[wi]);
						cases++;
					}
	__u64 state = 0x94d049bb133111ebULL;
	for (unsigned i = 0; i < 20000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 lhs = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		struct flags f = { state & 1, (state >> 1) & 1,
			(state >> 2) & 1, (state >> 3) & 1 };
		fails += check((enum op)(i & 3), lhs, state, f, w[(i >> 2) & 3]);
		cases++;
	}
	if (fails) {
		printf("x86 memory-store ALU host cross-check: FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 memory-store ALU host cross-check: OK (%u cases)\n", cases);
	return 0;
}
