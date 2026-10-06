/* Independent host oracle for the x86 register-source IMUL-immediate handler
 * `IMUL reg, imm` (`X86_SIM_L_EXEC_IMUL_IMM`).
 *
 * The generated side calls the real generated macros in the exact order the C
 * handler uses them: `KPROG_X86_IMMEDIATE_VALUE` for the decoded immediate,
 * `KPROG_X86_WIDTH_SIGN_MASK`/`KPROG_X86_SET_IMUL_FLAGS` for the overflow rule,
 * and `KPROG_X86_WRITE_REG8/16/32/64` for the writeback. The left operand is
 * the source register's raw 64-bit value — the C arm reads it with
 * `X86_SIM_L_READ_REG(SRC)` and never sign-extends it — while the immediate is
 * sign-extended at the destination width. The oracle re-derives the signed
 * overflow from an exact mathematical product and states the writeback
 * independently. */

/* The generated headers define __always_inline functions for the in-kernel
 * build; provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_width.h"
#include "generated/x86_immediate.h"
#include "generated/x86_signed.h"
#include "generated/x86_imul_flags.h"
#include "generated/x86_reg_write.h"

#include <stdio.h>

struct flags {
	__u8 cf, zf, sf, of;
};

struct result {
	__u64 dst;
	__u8 tag;
	struct flags flags;
};

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

/* Sign extension stated from the width's own sign bit, not from a cast. */
static __u64 oracle_sign_extend(__u64 value, unsigned width)
{
	unsigned bits = width_bits(width);
	__u64 mask = width_mask(width);

	value &= mask;
	if (bits < 64 && (value & (1ULL << (bits - 1))))
		value |= ~mask;
	return value;
}

/* Arithmetic-immediate rule stated directly: only the low 32 bits are consumed
 * and a 64-bit destination sign-extends bit 31. */
static __u64 oracle_immediate(__u64 raw, unsigned width)
{
	__u64 value = raw & 0xffffffffULL;

	if (width == X86_WIDTH_64 && (value & 0x80000000ULL))
		value |= 0xffffffff00000000ULL;
	return value;
}

/* Width-confined register writeback. w8/w16 merge into the low bytes; an
 * architectural 32-bit write zero-extends into a 64-bit register. */
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

static __u64 generated_write(__u64 old, __u64 value, unsigned width,
			     __u8 *tag)
{
	union reg_storage storage = { .q = old };

	switch (width) {
	case X86_WIDTH_8:
		KPROG_X86_WRITE_REG8(storage, *tag, value, 0, 0);
		break;
	case X86_WIDTH_16:
		KPROG_X86_WRITE_REG16(storage, *tag, value, 0);
		break;
	case X86_WIDTH_32:
		KPROG_X86_WRITE_REG32(storage, *tag, value, 0);
		break;
	default:
		KPROG_X86_WRITE_REG64(storage, *tag, value, 0);
		break;
	}
	return storage.q;
}

/* The generated composition, exactly as `X86_SIM_L_EXEC_IMUL_IMM` orders it:
 * the source register is the raw left operand, the immediate is decoded and
 * sign-extended at the destination width. */
static struct result generated_imul_reg(__u64 old, __u8 tag, struct flags in,
					__u64 lhs, __u64 raw_imm,
					unsigned width)
{
	struct result out;
	__u8 out_tag = tag;
	__u64 rhs = kprog_x86_sign_extend_value(
		KPROG_X86_IMMEDIATE_VALUE(raw_imm, width), (__u8)width);
	__u64 result = lhs * rhs;
	__u64 a_abs = kprog_x86_abs_width_value(lhs, (__u8)width);
	__u64 b_abs = kprog_x86_abs_width_value(rhs, (__u8)width);
	__u64 sign = KPROG_X86_WIDTH_SIGN_MASK(width);
	__u64 limit = ((lhs ^ rhs) & sign) ? sign : sign - 1;
	__u8 cf = 0, of = 0;

	KPROG_X86_SET_IMUL_FLAGS(cf, of, a_abs, b_abs, limit);
	out.flags = in;
	out.flags.cf = cf;
	out.flags.of = of;
	out.dst = generated_write(old, result, width, &out_tag);
	out.tag = out_tag;
	return out;
}

/* Independent statement of the same composition. */
static struct result oracle_imul_reg(__u64 old, struct flags in, __u64 lhs,
				     __u64 raw_imm, unsigned width)
{
	struct result out;
	__u64 rhs = oracle_sign_extend(oracle_immediate(raw_imm, width), width);
	__u64 result = lhs * rhs;
	__int128 product = (__int128)(__s64)oracle_sign_extend(lhs, width) *
			   (__int128)(__s64)rhs;
	unsigned bits = width_bits(width);
	__int128 lo = -((__int128)1 << (bits - 1));
	__int128 hi = ((__int128)1 << (bits - 1)) - 1;
	__u8 overflow = (product < lo || product > hi) ? 1U : 0U;

	out.flags = in;
	out.flags.cf = overflow;
	out.flags.of = overflow;
	out.dst = oracle_write(old, result, width);
	out.tag = 0;
	return out;
}

static int same_result(const char *name, struct result got, struct result want,
		       __u64 lhs, __u64 old, __u64 raw_imm, unsigned width)
{
	if (got.dst == want.dst && got.flags.cf == want.flags.cf &&
	    got.flags.zf == want.flags.zf && got.flags.sf == want.flags.sf &&
	    got.flags.of == want.flags.of)
		return 0;
	printf("MISMATCH %s w=%u lhs=%#llx old=%#llx imm=%#llx "
	       "dst=%#llx/%#llx cf=%u/%u zf=%u/%u sf=%u/%u of=%u/%u\n",
	       name, width, lhs, old, raw_imm, got.dst, want.dst,
	       got.flags.cf, want.flags.cf, got.flags.zf, want.flags.zf,
	       got.flags.sf, want.flags.sf, got.flags.of, want.flags.of);
	return 1;
}

static int check(__u64 seed, __u64 lhs, __u64 old, __u64 raw_imm,
		 unsigned width)
{
	struct flags in = { (__u8)(seed & 1), (__u8)((seed >> 1) & 1),
			    (__u8)((seed >> 2) & 1), (__u8)((seed >> 3) & 1) };

	return same_result("imul-reg-imm",
		generated_imul_reg(old, 7, in, lhs, raw_imm, width),
		oracle_imul_reg(old, in, lhs, raw_imm, width),
		lhs, old, raw_imm, width);
}

int main(void)
{
	static const __u64 v[] = { 0, 1, 2, ~0ULL, 0x7f, 0x80, 0xff,
		0x7fff, 0x8000, 0xffff, 0x7fffffffULL, 0x80000000ULL,
		0xffffffffULL, 0x8000000000000000ULL,
		0xffffffffffffff80ULL, 0xffffffffffffff81ULL,
		0x0000000080000001ULL, 0x7fffffffffffffffULL };
	static const unsigned w[] = { 1, 2, 4, 8 };
	unsigned cases = 0, fails = 0;

	/* Boundary sweep over sign-transition seeds at every operand width. */
	for (unsigned wi = 0; wi < 4; wi++)
		for (unsigned a = 0; a < 18; a++)
			for (unsigned c = 0; c < 18; c++) {
				fails += check(v[a], v[17 - a], v[c],
					       v[(a + c) % 18], w[wi]);
				cases++;
			}

	__u64 state = 0x452821e638d01377ULL;
	for (unsigned i = 0; i < 40000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 lhs = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 old = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 raw_imm = state;
		fails += check(state, lhs, old, raw_imm, w[i & 3]);
		cases++;
	}

	if (fails) {
		printf("x86 IMUL-immediate register-source host cross-check: "
		       "FAILED (%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 IMUL-immediate register-source host cross-check: "
	       "OK (%u cases)\n", cases);
	return 0;
}
