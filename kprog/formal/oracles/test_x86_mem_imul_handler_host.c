/* Independent host oracle for the x86 memory-source IMUL-immediate handler
 * `IMUL reg, [mem], imm` (`X86_SIM_L_EXEC_IMUL_MEM_IMM`).
 *
 * The generated side runs the real generated contracts: the little-endian
 * memory load (`KPROG_X86_MEM_LOAD`), the arithmetic-immediate rule
 * (`KPROG_X86_IMMEDIATE_VALUE`), the generated sign extension
 * (`kprog_x86_sign_extend_value`), the divide-based IMUL flag construction
 * (`KPROG_X86_SET_IMUL_FLAGS` with `kprog_x86_abs_width_value`), and the
 * width-confined register writeback (`KPROG_X86_WRITE_REG*`).
 *
 * The oracle side is stated independently of every one of those: it assembles
 * the memory operand with a byte loop, sign-extends with an explicit sign-bit
 * test, forms the product in 128-bit integer arithmetic and decides CF/OF from
 * whether that mathematical product fits the destination's signed width, rather
 * than from the abs-value division. It also models the architectural 32-bit
 * zero-extension of `KPROG_X86_WRITE_REG32`. */

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
#include "generated/x86_mem_access.h"
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

static __u64 oracle_load(const __u8 *p, unsigned width)
{
	__u64 value = 0;
	unsigned bytes = width_bits(width) / 8;

	for (unsigned i = 0; i < bytes; i++)
		value |= (__u64)p[i] << (8 * i);
	return value & width_mask(width);
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

/* Signed mathematical value of the width-narrowed operand. The extension is
 * taken through a 64-bit signed cast so a sign-filled word is negative in the
 * 128-bit domain as well. */
static __int128 oracle_signed(__u64 value, unsigned width)
{
	return (__int128)(__s64)oracle_sign_extend(value, width);
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

/* The generated composition, exactly as `X86_SIM_L_EXEC_IMUL_MEM_IMM` orders
 * it: memory operand at `mem_width`, immediate at `width`, both sign-extended,
 * flags from the raw loaded value and the extended immediate. */
static struct result generated_imul(const __u8 *mem, __u64 old, __u8 tag,
				    struct flags in, __u64 raw_imm,
				    unsigned width, unsigned mem_width)
{
	struct result out;
	__u8 out_tag = tag;
	__u64 lhs = KPROG_X86_MEM_LOAD(mem, mem_width);
	__u64 rhs = kprog_x86_sign_extend_value(
		KPROG_X86_IMMEDIATE_VALUE(raw_imm, width), (__u8)width);
	__u64 result = kprog_x86_sign_extend_value(lhs, (__u8)mem_width) * rhs;
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
static struct result oracle_imul(const __u8 *mem, __u64 old,
				 struct flags in, __u64 raw_imm,
				 unsigned width, unsigned mem_width)
{
	struct result out;
	__u64 lhs = oracle_load(mem, mem_width);
	__u64 rhs = oracle_sign_extend(oracle_immediate(raw_imm, width), width);
	__u64 result = oracle_sign_extend(lhs, mem_width) * rhs;
	__int128 product = oracle_signed(lhs, width) *
			   oracle_signed(rhs, width);
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
		       __u64 mem_seed, __u64 old, __u64 raw_imm,
		       unsigned width, unsigned mem_width)
{
	if (got.dst == want.dst && got.flags.cf == want.flags.cf &&
	    got.flags.zf == want.flags.zf && got.flags.sf == want.flags.sf &&
	    got.flags.of == want.flags.of)
		return 0;
	printf("MISMATCH %s w=%u mw=%u mem=%#llx old=%#llx imm=%#llx "
	       "dst=%#llx/%#llx cf=%u/%u zf=%u/%u sf=%u/%u of=%u/%u\n",
	       name, width, mem_width, mem_seed, old, raw_imm, got.dst,
	       want.dst, got.flags.cf, want.flags.cf, got.flags.zf,
	       want.flags.zf, got.flags.sf, want.flags.sf, got.flags.of,
	       want.flags.of);
	return 1;
}

static int check(__u64 mem_seed, __u64 old, __u64 raw_imm, unsigned width,
		 unsigned mem_width)
{
	__u8 got_mem[16], want_mem[16];
	struct flags in = { (__u8)(mem_seed & 1), (__u8)((mem_seed >> 1) & 1),
			    (__u8)((mem_seed >> 2) & 1),
			    (__u8)((mem_seed >> 3) & 1) };
	struct result got, want;

	for (unsigned i = 0; i < 16; i++)
		got_mem[i] = want_mem[i] = (__u8)(mem_seed >> (8 * (i % 8)));

	got = generated_imul(got_mem, old, 7, in, raw_imm, width, mem_width);
	want = oracle_imul(want_mem, old, in, raw_imm, width, mem_width);
	return same_result("imul-mem-imm", got, want, mem_seed, old, raw_imm,
			   width, mem_width);
}

int main(void)
{
	static const __u64 v[] = { 0, 1, 2, ~0ULL, 0x7f, 0x80, 0xff,
		0x7fff, 0x8000, 0xffff, 0x7fffffffULL, 0x80000000ULL,
		0xffffffffULL, 0x8000000000000000ULL };
	static const unsigned w[] = { 1, 2, 4, 8 };
	unsigned cases = 0, fails = 0;

	/* Boundary sweep: every destination width against every memory width,
	 * over sign-transition seeds and immediate values. */
	for (unsigned wi = 0; wi < 4; wi++)
		for (unsigned mi = 0; mi < 4; mi++)
			for (unsigned a = 0; a < 14; a++)
				for (unsigned c = 0; c < 14; c++) {
					fails += check(v[a], v[13 - a], v[c],
						       w[wi], w[mi]);
					cases++;
				}

	__u64 state = 0x9e3779b97f4a7c15ULL;
	for (unsigned i = 0; i < 40000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 mem_seed = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 old = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 raw_imm = state;
		fails += check(mem_seed, old, raw_imm, w[(i >> 1) & 3],
			       w[(i >> 3) & 3]);
		cases++;
	}

	if (fails) {
		printf("x86 memory-imul host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 memory-imul host cross-check: OK (%u cases)\n", cases);
	return 0;
}
