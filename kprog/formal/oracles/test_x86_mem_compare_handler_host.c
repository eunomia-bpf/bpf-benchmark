/* Independent host oracle for the x86 memory-source compare/test handlers
 * `CMP/TEST [mem], rhs` (`X86_SIM_L_EXEC_CMP_MEM`) and
 * `CMP reg, [mem]` (`X86_SIM_L_EXEC_CMP_REG_MEM`).
 *
 * The generated side calls the real generated macros in the exact order the C
 * handlers use them: `KPROG_X86_MEM_LOAD` for the memory operand,
 * `KPROG_X86_IMMEDIATE_VALUE` for an immediate right-hand side,
 * `KPROG_X86_SBB_RESULT` with a cleared borrow and `KPROG_X86_SET_SUB_FLAGS`
 * for a compare, and `KPROG_X86_SET_LOGIC_FLAGS` for a test. The oracle
 * re-derives borrow, zero, sign, and overflow from the width-masked operands
 * and result directly. Neither handler writes a register, so the destination
 * value must survive untouched. */

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
#include "generated/x86_sub_flags.h"
#include "generated/x86_logic_flags.h"
#include "generated/x86_sbb_result.h"

#include <stdio.h>

struct flags {
	__u8 cf, zf, sf, of;
};

static __u64 width_mask(unsigned width)
{
	return KPROG_X86_WIDTH_MASK(width);
}

static __u64 width_sign_mask(unsigned width)
{
	return KPROG_X86_WIDTH_SIGN_MASK(width);
}

static unsigned width_bits(unsigned width)
{
	return KPROG_X86_WIDTH_BITS(width);
}

/* Little-endian load stated with its own byte loop, narrowed to the width. */
static __u64 oracle_load(const __u8 *p, unsigned width)
{
	__u64 value = 0;
	unsigned bytes = width_bits(width) / 8;

	for (unsigned i = 0; i < bytes; i++)
		value |= (__u64)p[i] << (8 * i);
	return value & width_mask(width);
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

/* Subtraction flags stated from the width-masked operands and result: borrow,
 * equality of the masked operands, the result's sign bit, and signed overflow
 * from differing operand signs with a result sign differing from the left. */
static struct flags oracle_sub_flags(__u64 lhs, __u64 rhs, unsigned width)
{
	__u64 mask = width_mask(width);
	__u64 sign = width_sign_mask(width);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = (lhs - rhs) & mask;
	struct flags out;

	out.cf = a < b;
	out.zf = a == b;
	out.sf = (r & sign) != 0;
	out.of = ((a ^ b) & ((a ^ r) & sign)) != 0;
	return out;
}

/* Logical flags stated from the width-applied conjunction: CF=OF=0, ZF is the
 * masked value's zero-ness, and SF is its top width bit. */
static struct flags oracle_logic_flags(__u64 value, unsigned width)
{
	__u64 masked = value & width_mask(width);
	struct flags out;

	out.cf = 0;
	out.zf = masked == 0;
	out.sf = (masked >> (width_bits(width) - 1)) & 1;
	out.of = 0;
	return out;
}

/* Mirrors `X86_SIM_L_SET_LOGIC_FLAGS`: apply the width mask to the result,
 * then take ZF from zero-ness and SF from the top width bit. */
static struct flags generated_logic_flags(__u64 result, unsigned width)
{
	__u64 value = result & width_mask(width);
	__u8 cf, zf, sf, of;
	struct flags out;

	KPROG_X86_SET_LOGIC_FLAGS(cf, zf, sf, of, value == 0,
		(value >> (width_bits(width) - 1)) & 1);
	out.cf = cf;
	out.zf = zf;
	out.sf = sf;
	out.of = of;
	return out;
}

/* Mirrors `X86_SIM_L_SET_SUB_FLAGS`: mask both operands and the result to the
 * width, then hand the generated rule those masked values and the width's sign
 * mask. The generated macro itself takes the sign *mask*, not the width. */
static struct flags generated_sub_flags(__u64 lhs, __u64 rhs, unsigned width)
{
	__u64 mask = width_mask(width);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = (lhs - rhs) & mask;
	__u8 cf, zf, sf, of;
	struct flags out;

	KPROG_X86_SET_SUB_FLAGS(cf, zf, sf, of, a, b, r,
		width_sign_mask(width));
	out.cf = cf;
	out.zf = zf;
	out.sf = sf;
	out.of = of;
	return out;
}

/* The generated `X86_SIM_L_EXEC_CMP_MEM` composition, in its own order. */
static struct flags generated_cmp_mem(const __u8 *mem, unsigned op,
				      __u64 reg_value, __u64 raw_imm,
				      unsigned width)
{
	__u64 lhs = KPROG_X86_MEM_LOAD(mem, width);
	int is_reg = (op == 2 || op == 3);
	int is_test = (op == 1 || op == 3);
	__u64 rhs = is_reg ? reg_value :
		KPROG_X86_IMMEDIATE_VALUE(raw_imm, width);

	if (is_test)
		return generated_logic_flags(lhs & rhs, width);
	return generated_sub_flags(lhs, rhs, width);
}

/* Independent statement of the same composition. */
static struct flags oracle_cmp_mem(const __u8 *mem, unsigned op,
				   __u64 reg_value, __u64 raw_imm,
				   unsigned width)
{
	__u64 lhs = oracle_load(mem, width);
	int is_reg = (op == 2 || op == 3);
	int is_test = (op == 1 || op == 3);
	__u64 rhs = is_reg ? (reg_value & width_mask(width)) :
		oracle_immediate(raw_imm, width);

	if (is_test)
		return oracle_logic_flags(lhs & rhs, width);
	return oracle_sub_flags(lhs, rhs, width);
}

/* The generated `X86_SIM_L_EXEC_CMP_REG_MEM` composition: register left,
 * memory right, always the zero-borrow subtraction flags. */
static struct flags generated_cmp_reg_mem(const __u8 *mem, __u64 reg_value,
					  unsigned width)
{
	return generated_sub_flags(reg_value, KPROG_X86_MEM_LOAD(mem, width),
				   width);
}

static struct flags oracle_cmp_reg_mem(const __u8 *mem, __u64 reg_value,
				       unsigned width)
{
	return oracle_sub_flags(reg_value & width_mask(width),
		oracle_load(mem, width), width);
}

static int same_flags(const char *name, struct flags got, struct flags want,
		      __u64 mem_seed, __u64 reg_value, __u64 raw_imm,
		      unsigned width)
{
	if (got.cf == want.cf && got.zf == want.zf && got.sf == want.sf &&
	    got.of == want.of)
		return 0;
	printf("MISMATCH %s w=%u mem=%#llx reg=%#llx imm=%#llx "
	       "cf=%u/%u zf=%u/%u sf=%u/%u of=%u/%u\n",
	       name, width, mem_seed, reg_value, raw_imm, got.cf, want.cf,
	       got.zf, want.zf, got.sf, want.sf, got.of, want.of);
	return 1;
}

static int check_mem(__u64 mem_seed, __u64 reg_value, __u64 raw_imm,
		     unsigned width)
{
	__u8 got_mem[16], want_mem[16];

	for (unsigned i = 0; i < 16; i++)
		got_mem[i] = want_mem[i] = (__u8)(mem_seed >> (8 * (i % 8)));

	for (unsigned op = 0; op < 4; op++)
		if (same_flags("cmp/test-mem",
			       generated_cmp_mem(got_mem, op, reg_value,
						 raw_imm, width),
			       oracle_cmp_mem(want_mem, op, reg_value,
					      raw_imm, width),
			       mem_seed, reg_value, raw_imm, width))
			return 1;

	return same_flags("cmp-reg-mem",
			  generated_cmp_reg_mem(got_mem, reg_value, width),
			  oracle_cmp_reg_mem(want_mem, reg_value, width),
			  mem_seed, reg_value, raw_imm, width);
}

int main(void)
{
	static const __u64 v[] = { 0, 1, 2, ~0ULL, 0x7f, 0x80, 0xff,
		0x7fff, 0x8000, 0xffff, 0x7fffffffULL, 0x80000000ULL,
		0xffffffffULL, 0x8000000000000000ULL };
	static const unsigned w[] = { 1, 2, 4, 8 };
	unsigned cases = 0, fails = 0;

	/* Boundary sweep over sign-transition seeds at every operand width. */
	for (unsigned wi = 0; wi < 4; wi++)
		for (unsigned a = 0; a < 14; a++)
			for (unsigned c = 0; c < 14; c++) {
				fails += check_mem(v[a], v[13 - a], v[c],
						   w[wi]);
				cases++;
			}

	__u64 state = 0x9e3779b97f4a7c15ULL;
	for (unsigned i = 0; i < 40000; i++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 mem_seed = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 reg_value = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		__u64 raw_imm = state;
		fails += check_mem(mem_seed, reg_value, raw_imm, w[i & 3]);
		cases++;
	}

	if (fails) {
		printf("x86 memory-compare host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 memory-compare host cross-check: OK (%u cases)\n", cases);
	return 0;
}
