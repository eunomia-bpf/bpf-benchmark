/* Independent host oracle for the x86 two-destination `MULX` handler
 * (`X86_SIM_L_EXEC_MULX`, opcode `X86_OP_MULX`).
 *
 * The generated side follows the C arm in its own order: the low half is either
 * the 32-bit zero-extended low-word product truncated at 32 bits (`width ==
 * X86_WIDTH_32`) or the plain 64-bit product, the high half is either that
 * single product's upper 32 bits or the four-limb `p0..p3`/`mid` ladder, and
 * each half reaches its register through `KPROG_X86_WRITE_REG8/16/32/64`.
 * The oracle re-derives both halves from an exact 128-bit product, so it shares
 * no arithmetic with the limb ladder. `MULX` produces no flags, so the incoming
 * flag word must survive untouched; the auxiliary register is written only when
 * the instruction carries an auxiliary destination. */

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
typedef unsigned __int128 __u128;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_width.h"
#include "generated/x86_reg_write.h"

#include <stdio.h>

struct flags {
	__u8 cf, zf, sf, of;
};

struct mulx_result {
	__u64 dst;
	__u8 dst_tag;
	__u64 aux;
	__u8 aux_tag;
	struct flags flags;
};

union reg_storage {
	void *ptr;
	__u64 q;
	__u32 d;
	__u16 w;
	__u8 b[8];
};

/* Width-confined register writeback, stated for the little-endian byte storage
 * the generated macros write: w8/w16 merge into the low bytes, a 32-bit write
 * zero-extends the register, and a 64-bit write replaces it. */
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

/* The generated composition, exactly as `X86_SIM_L_EXEC_MULX` orders it. */
static struct mulx_result generated_mulx(__u64 dst_old, __u8 dst_tag,
					 __u64 aux_old, __u8 aux_tag,
					 struct flags in, __u64 lhs, __u64 rhs,
					 unsigned width, int aux_present)
{
	struct mulx_result out;
	__u8 out_dst_tag = dst_tag;
	__u8 out_aux_tag = aux_tag;
	__u64 low, high;

	if (width == X86_WIDTH_32) {
		__u64 product = (__u64)(__u32)lhs * (__u64)(__u32)rhs;

		low = (__u32)product;
		high = (__u32)(product >> 32);
	} else {
		__u64 a0 = (__u32)lhs, a1 = lhs >> 32;
		__u64 b0 = (__u32)rhs, b1 = rhs >> 32;
		__u64 p0 = a0 * b0, p1 = a0 * b1, p2 = a1 * b0, p3 = a1 * b1;
		__u64 mid = (p0 >> 32) + (__u32)p1 + (__u32)p2;

		low = lhs * rhs;
		high = p3 + (p1 >> 32) + (p2 >> 32) + (mid >> 32);
	}

	out.flags = in;
	out.dst = generated_write(dst_old, low, width, &out_dst_tag);
	out.dst_tag = out_dst_tag;
	if (aux_present) {
		out.aux = generated_write(aux_old, high, width, &out_aux_tag);
		out.aux_tag = out_aux_tag;
	} else {
		out.aux = aux_old;
		out.aux_tag = aux_tag;
	}
	return out;
}

/* Independent statement of the same composition: both halves come from an
 * exact 128-bit product of the selected operand values. */
static struct mulx_result oracle_mulx(__u64 dst_old, __u64 aux_old,
				      struct flags in, __u64 lhs, __u64 rhs,
				      unsigned width, int aux_present)
{
	struct mulx_result out;
	__u128 product;
	__u64 low, high;

	if (width == X86_WIDTH_32) {
		product = (__u128)(lhs & 0xffffffffULL) *
			  (__u128)(rhs & 0xffffffffULL);
		low = (__u64)product & 0xffffffffULL;
		high = ((__u64)(product >> 32)) & 0xffffffffULL;
	} else {
		product = (__u128)lhs * (__u128)rhs;
		low = (__u64)product;
		high = (__u64)(product >> 64);
	}

	out.flags = in;
	out.dst = oracle_write(dst_old, low, width);
	out.dst_tag = 0;
	if (aux_present) {
		out.aux = oracle_write(aux_old, high, width);
		out.aux_tag = 0;
	} else {
		out.aux = aux_old;
		out.aux_tag = 5; /* the incoming auxiliary provenance, unread */
	}
	return out;
}

static int same_mulx(const char *name, struct mulx_result got,
		     struct mulx_result want, __u64 lhs, __u64 rhs,
		     unsigned width)
{
	if (got.dst == want.dst && got.aux == want.aux &&
	    got.flags.cf == want.flags.cf && got.flags.zf == want.flags.zf &&
	    got.flags.sf == want.flags.sf && got.flags.of == want.flags.of)
		return 0;
	printf("MISMATCH %s w=%u lhs=%#llx rhs=%#llx "
	       "dst=%#llx/%#llx aux=%#llx/%#llx cf=%u/%u zf=%u/%u "
	       "sf=%u/%u of=%u/%u\n",
	       name, width, lhs, rhs, got.dst, want.dst, got.aux, want.aux,
	       got.flags.cf, want.flags.cf, got.flags.zf, want.flags.zf,
	       got.flags.sf, want.flags.sf, got.flags.of, want.flags.of);
	return 1;
}

static int check(__u64 seed, __u64 lhs, __u64 rhs, unsigned width)
{
	struct flags in = { (__u8)(seed & 1), (__u8)((seed >> 1) & 1),
			    (__u8)((seed >> 2) & 1), (__u8)((seed >> 3) & 1) };
	__u64 dst_old = seed * 0x9e3779b97f4a7c15ULL + 0x123456789abcdefULL;
	__u64 aux_old = seed * 0xc2b2ae3d27d4eb4fULL + 0x0fedcba987654321ULL;
	int fails = 0;

	for (int aux_present = 0; aux_present < 2; aux_present++)
		fails += same_mulx("mulx",
			generated_mulx(dst_old, 7, aux_old, 5, in, lhs, rhs,
				       width, aux_present),
			oracle_mulx(dst_old, aux_old, in, lhs, rhs, width,
				    aux_present),
			lhs, rhs, width);
	return fails;
}

int main(void)
{
	static const __u64 v[] = { 0, 1, 2, ~0ULL, 0x7f, 0x80, 0xff,
		0x7fff, 0x8000, 0xffff, 0x7fffffffULL, 0x80000000ULL,
		0xffffffffULL, 0x8000000000000000ULL,
		0x00000000ffffffffULL, 0xffffffff00000000ULL,
		0x0123456789abcdefULL, 0xfedcba9876543210ULL };
	static const unsigned w[] = { 1, 2, 4, 8 };
	unsigned cases = 0, fails = 0;

	/* Boundary sweep over operand-limb transitions at every width. */
	for (unsigned wi = 0; wi < 4; wi++)
		for (unsigned a = 0; a < 18; a++)
			for (unsigned c = 0; c < 18; c++) {
				fails += check(v[a], v[17 - a], v[c], w[wi]);
				cases++;
			}

	__u64 state = 0x243f6a8885a308d3ULL;
	for (unsigned i = 0; i < 40000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 lhs = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 rhs = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check(state, lhs, rhs, w[i & 3]);
		cases++;
	}

	if (fails) {
		printf("x86 MULX host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 MULX host cross-check: OK (%u cases)\n", cases);
	return 0;
}
