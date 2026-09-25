/* Independent host oracle for x86 `AND/OR/XOR [mem], rhs`. */
typedef unsigned char __u8;
typedef unsigned long long __u64;
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_logic_flags.h"
#include <stdio.h>
#include <string.h>

enum op { OP_AND, OP_OR, OP_XOR };
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

static struct flags generated_run(enum op op, __u8 mem[16], __u64 rhs,
				  struct flags in, unsigned w)
{
	__u64 mask = KPROG_X86_WIDTH_MASK(w);
	__u64 lhs = KPROG_X86_MEM_LOAD(mem, w) & mask;
	__u64 result = op == OP_AND ? lhs & rhs :
		op == OP_OR ? lhs | rhs : lhs ^ rhs;
	__u64 r = result & mask;
	struct flags out = in;
	KPROG_X86_SET_LOGIC_FLAGS(out.cf, out.zf, out.sf, out.of,
		r == 0, !!(r & KPROG_X86_WIDTH_SIGN_MASK(w)));
	KPROG_X86_MEM_STORE(mem, w, result);
	return out;
}

static struct flags oracle_run(enum op op, __u8 mem[16], __u64 rhs,
			       unsigned w)
{
	unsigned n = bits(w);
	__uint128_t mod = ((__uint128_t)1) << n;
	__u64 mask = (__u64)(mod - 1);
	__u64 lhs = oracle_load(mem, w) & mask;
	__u64 r = (op == OP_AND ? lhs & rhs :
		op == OP_OR ? lhs | rhs : lhs ^ rhs) & mask;
	struct flags out = { 0, r == 0,
		!!(r & (1ULL << (n - 1))), 0 };
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
	struct flags want = oracle_run(op, want_mem, rhs, w);
	if (memcmp(got_mem, want_mem, sizeof(got_mem)) ||
	    got.cf != want.cf || got.zf != want.zf ||
	    got.sf != want.sf || got.of != want.of) {
		printf("MISMATCH op=%u w=%u lhs=%#llx rhs=%#llx\n",
		       op, w, lhs, rhs);
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
	for (unsigned op = 0; op < 3; op++)
		for (unsigned wi = 0; wi < 4; wi++)
			for (unsigned a = 0; a < 8; a++)
				for (unsigned f = 0; f < 16; f++) {
					struct flags in = { f & 1, (f >> 1) & 1,
						(f >> 2) & 1, (f >> 3) & 1 };
					fails += check((enum op)op, v[a], v[7 - a], in,
						w[wi]);
					cases++;
				}
	__u64 state = 0x9e3779b97f4a7c15ULL;
	for (unsigned i = 0; i < 20000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 lhs = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		struct flags in = { state & 1, (state >> 1) & 1,
			(state >> 2) & 1, (state >> 3) & 1 };
		fails += check((enum op)(i % 3), lhs, state, in, w[(i >> 2) & 3]);
		cases++;
	}
	if (fails) {
		printf("x86 memory-logic host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 memory-logic host cross-check: OK (%u cases)\n", cases);
	return 0;
}
