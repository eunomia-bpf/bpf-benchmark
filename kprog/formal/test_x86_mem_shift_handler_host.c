/* Independent host oracle for the x86 memory-source BMI2 shift/rotate
 * handlers `SHLX/SHRX/SARX dst, [mem], count` and `RORX dst, [mem], imm8`.
 * The generated side runs the real generated macros; the oracle recomputes the
 * load, the width-local shift, and the width-confined register writeback with
 * a byte loop and no shared helper. */

/* The generated shift-result header defines __always_inline functions for the
 * in-kernel build; provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
#include "generated/x86_width.h"
#include "generated/x86_mem_access.h"
#include "generated/x86_shift_count.h"
#include "generated/x86_shift_result.h"
#include "generated/x86_reg_write.h"
#include <stdio.h>
#include <string.h>

enum op { OP_SHL, OP_SHR, OP_SAR, OP_RORX };

union reg_storage {
	void *ptr;
	__u64 q;
	__u32 d;
	__u16 w;
	__u8 b[8];
};

static unsigned width_bits(unsigned width)
{
	return width == X86_WIDTH_8 ? 8 :
	       width == X86_WIDTH_16 ? 16 :
	       width == X86_WIDTH_32 ? 32 : 64;
}

static __u64 width_mask(unsigned width)
{
	unsigned bits = width_bits(width);
	return bits == 64 ? ~0ULL : (1ULL << bits) - 1;
}

static __u64 oracle_load(const __u8 *p, unsigned width)
{
	__u64 v = 0;
	for (unsigned i = 0; i < width_bits(width) / 8; i++)
		v += (__u64)p[i] * (1ULL << (8 * i));
	return v;
}

static __u64 oracle_rotate_right(__u64 narrowed, unsigned width,
				 unsigned count)
{
	unsigned n = width_bits(width);
	unsigned c = count % n;
	if (c == 0)
		return narrowed;
	return ((narrowed >> c) | (narrowed << (n - c))) & width_mask(width);
}

static __u64 oracle_shift(enum op op, __u64 lhs, __u64 rhs, unsigned width)
{
	unsigned n = width_bits(width);
	unsigned count = (unsigned)(rhs & (n == 64 ? 63U : 31U));
	__u64 mask = width_mask(width);
	__u64 narrowed = lhs & mask;

	if (op == OP_RORX)
		return oracle_rotate_right(narrowed, width, count);
	if (count == 0)
		return narrowed;
	if (op == OP_SHL)
		return (narrowed << count) & mask;
	if (op == OP_SHR)
		return narrowed >> count;
	if (narrowed & KPROG_X86_WIDTH_SIGN_MASK(width))
		return (narrowed >> count) | (mask ^ (mask >> count));
	return narrowed >> count;
}

/* Width-confined register writeback. w8/w16 merge into the low bytes; an
 * architectural 32-bit write zero-extends into a 64-bit register, so its upper
 * half is cleared rather than preserved. */
static __u64 oracle_write(__u64 old, __u64 value, unsigned width)
{
	switch (width) {
	case X86_WIDTH_8:
		return (old & ~0xffULL) | (value & 0xffULL);
	case X86_WIDTH_16:
		return (old & ~0xffffULL) | (value & 0xffffULL);
	case X86_WIDTH_32:
		return value & 0xffffffffULL;
	default:
		return value;
	}
}
static __u64 generated_write(__u64 old, __u64 value, unsigned width)
{
	union reg_storage storage = { .q = old };
	__u8 tag = 0;

	switch (width) {
	case X86_WIDTH_8:
		KPROG_X86_WRITE_REG8(storage, tag, value, 0, 0);
		break;
	case X86_WIDTH_16:
		KPROG_X86_WRITE_REG16(storage, tag, value, 0);
		break;
	case X86_WIDTH_32:
		KPROG_X86_WRITE_REG32(storage, tag, value, 0);
		break;
	default:
		KPROG_X86_WRITE_REG64(storage, tag, value, 0);
		break;
	}
	(void)tag;
	return storage.q;
}

static __u64 generated_run(enum op op, __u8 mem[16], __u64 old, __u64 count,
			   unsigned width)
{
	__u64 lhs = KPROG_X86_MEM_LOAD(mem, width);
	__u64 result = op == OP_SHL ? kprog_x86_shl_result(lhs, count, width) :
		op == OP_SHR ? kprog_x86_shr_result(lhs, count, width) :
		op == OP_SAR ? kprog_x86_sar_result(lhs, count, width) :
		kprog_x86_ror_result(lhs, count, width);
	return generated_write(old, result, width);
}

static int check(enum op op, __u64 mem_seed, __u64 old, __u64 count,
		 unsigned width)
{
	__u8 got_mem[16], want_mem[16];
	for (unsigned i = 0; i < 16; i++)
		got_mem[i] = want_mem[i] = (__u8)(mem_seed >> (8 * (i % 8)));
	__u64 got = generated_run(op, got_mem, old, count, width);
	__u64 want = oracle_write(old,
		oracle_shift(op, oracle_load(want_mem, width), count, width),
		width);
	if (got != want) {
		printf("MISMATCH op=%u w=%u mem=%#llx old=%#llx count=%#llx\n",
		       op, width, mem_seed, old, count);
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
				for (unsigned c = 0; c < 8; c++) {
					fails += check((enum op)op, v[a], v[7 - a],
						v[c], w[wi]);
					cases++;
				}
	__u64 state = 0x9e3779b97f4a7c15ULL;
	for (unsigned i = 0; i < 20000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 mem_seed = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 old = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check((enum op)(i % 4), mem_seed, old, state,
			w[(i >> 2) & 3]);
		cases++;
	}
	if (fails) {
		printf("x86 memory-shift host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 memory-shift host cross-check: OK (%u cases)\n", cases);
	return 0;
}
