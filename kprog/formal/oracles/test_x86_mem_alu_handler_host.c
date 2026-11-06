/*
 * Independent host cross-check for the x86 memory-source arithmetic handler
 * composition. The implementation side composes the generated memory,
 * result, width, and flag contracts used by X86_SIM_L_EXEC_ALU_MEM. The
 * oracle assembles bytes with a loop and computes carry/borrow and signed
 * overflow in 128-bit arithmetic.
 */
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
#include "generated/x86_adc.h"
#include "generated/x86_add_flags.h"
#include "generated/x86_sub_flags.h"
#include "generated/x86_sbb_result.h"
#include "generated/x86_sbb_flags.h"
#include "generated/x86_reg_write.h"

#include <stdio.h>

enum op { OP_ADD, OP_ADC, OP_SUB, OP_SBB };

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

static __u64 write_low(__u64 old, __u64 value, unsigned width)
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

static __u64 generated_write_low(__u64 old, __u64 value, unsigned width,
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

static struct result generated_run(enum op op, __u64 dst,
				   __u8 tag, struct flags in, const __u8 mem[8],
				   unsigned width)
{
	__u64 mask = KPROG_X86_WIDTH_MASK(width);
	__u64 sign = KPROG_X86_WIDTH_SIGN_MASK(width);
	__u64 lhs = dst & mask;
	__u64 rhs = KPROG_X86_MEM_LOAD(mem, width) & mask;
	__u64 raw, narrowed;
	struct result out = { .dst = dst, .tag = tag, .flags = in };

	switch (op) {
	case OP_ADD:
		raw = KPROG_X86_ADC_RESULT(lhs, rhs, 0);
		narrowed = raw & mask;
		KPROG_X86_SET_ADD_FLAGS(out.flags.cf, out.flags.zf,
			out.flags.sf, out.flags.of, lhs, rhs, narrowed, sign);
		break;
	case OP_ADC:
		raw = KPROG_X86_ADC_RESULT(lhs, rhs, in.cf);
		narrowed = raw & mask;
		KPROG_X86_SET_ADC_FLAGS(out.flags.cf, out.flags.zf,
			out.flags.sf, out.flags.of, lhs, rhs, narrowed, sign,
			in.cf);
		break;
	case OP_SUB:
		raw = KPROG_X86_SBB_RESULT(lhs, rhs, 0);
		narrowed = raw & mask;
		KPROG_X86_SET_SUB_FLAGS(out.flags.cf, out.flags.zf,
			out.flags.sf, out.flags.of, lhs, rhs, narrowed, sign);
		break;
	default:
		raw = KPROG_X86_SBB_RESULT(lhs, rhs, in.cf);
		narrowed = raw & mask;
		KPROG_X86_SET_SBB_FLAGS(out.flags.cf, out.flags.zf,
			out.flags.sf, out.flags.of, lhs, rhs, narrowed,
			sign, in.cf);
		break;
	}
	out.dst = generated_write_low(dst, narrowed, width, &out.tag);
	return out;
}

static __u64 oracle_load(const __u8 mem[8], unsigned width)
{
	__u64 value = 0;
	unsigned bytes = width_bits(width) / 8;

	for (unsigned i = 0; i < bytes; i++)
		value += (__u64)mem[i] * (((__u64)1) << (8 * i));
	return value;
}

static __int128 signed_value(__u64 value, unsigned bits)
{
	__uint128_t modulus = ((__uint128_t)1) << bits;
	__uint128_t sign = ((__uint128_t)1) << (bits - 1);
	__uint128_t narrowed = (__uint128_t)value & (modulus - 1);

	return (narrowed & sign) ? (__int128)(narrowed - modulus) :
		(__int128)narrowed;
}

static struct result oracle_run(enum op op, __u64 dst, __u8 tag,
				struct flags in, const __u8 mem[8], unsigned width)
{
	unsigned bits = width_bits(width);
	__uint128_t modulus = ((__uint128_t)1) << bits;
	__u64 mask = width_mask(width);
	__u64 lhs = dst & mask;
	__u64 rhs = oracle_load(mem, width) & mask;
	__u8 carry = (op == OP_ADC || op == OP_SBB) ? !!in.cf : 0;
	__uint128_t wide;
	__int128 signed_result;
	__int128 signed_min = -((__int128)1 << (bits - 1));
	__int128 signed_max = (((__int128)1 << (bits - 1)) - 1);
	__u64 narrowed;
	struct result out;

	if (op == OP_ADD || op == OP_ADC) {
		wide = (__uint128_t)lhs + rhs + carry;
		narrowed = (__u64)(wide & (modulus - 1));
		out.flags.cf = wide >= modulus;
		signed_result = signed_value(lhs, bits) +
			signed_value(rhs, bits) + carry;
	} else {
		__uint128_t subtrahend = (__uint128_t)rhs + carry;
		narrowed = (__u64)(((__uint128_t)lhs - subtrahend) &
			(modulus - 1));
		out.flags.cf = (__uint128_t)lhs < subtrahend;
		signed_result = signed_value(lhs, bits) -
			signed_value(rhs, bits) - carry;
	}
	out.flags.zf = narrowed == 0;
	out.flags.sf = !!(narrowed & (((__u64)1) << (bits - 1)));
	out.flags.of = signed_result < signed_min || signed_result > signed_max;
	out.dst = write_low(dst, narrowed, width);
	out.tag = 0;
	(void)tag;
	return out;
}

static int check_case(enum op op, __u64 dst, __u8 tag, struct flags in,
			      const __u8 mem[8], unsigned width)
{
	struct result got = generated_run(op, dst, tag, in, mem, width);
	struct result want = oracle_run(op, dst, tag, in, mem, width);

	if (got.dst != want.dst || got.tag != want.tag ||
	    got.flags.cf != want.flags.cf ||
	    got.flags.zf != want.flags.zf || got.flags.sf != want.flags.sf ||
	    got.flags.of != want.flags.of) {
		printf("MISMATCH op=%u w=%u dst=%#llx got=%#llx/t%u/%u%u%u%u want=%#llx/t%u/%u%u%u%u\n",
		       op, width, dst, got.dst, got.tag, got.flags.cf,
		       got.flags.zf, got.flags.sf, got.flags.of, want.dst,
		       want.tag, want.flags.cf, want.flags.zf, want.flags.sf,
		       want.flags.of);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 dsts[] = {
		0, 1, ~0ULL, 0x7f, 0x80, 0x7fffffffULL,
		0x80000000ULL, 0x8000000000000000ULL,
	};
	static const __u64 words[] = {
		0, 1, ~0ULL, 0x7f, 0x80, 0x7fffffffULL,
		0x80000000ULL, 0x8000000000000000ULL,
	};
	static const unsigned widths[] = {
		X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 4; op++)
		for (unsigned w = 0; w < 4; w++)
			for (unsigned a = 0; a < sizeof(dsts) / sizeof(dsts[0]); a++)
				for (unsigned b = 0; b < sizeof(words) / sizeof(words[0]); b++)
					for (unsigned carry = 0; carry < 2; carry++) {
						__u8 mem[8];
						for (unsigned i = 0; i < 8; i++)
							mem[i] = (__u8)(words[b] >> (8 * i));
						struct flags in = { carry, 1, 1, 1 };
						fails += check_case((enum op)op, dsts[a], 7, in,
							mem, widths[w]);
						cases++;
					}

	__u64 state = 0xd1b54a32d192ed03ULL;
	for (unsigned i = 0; i < 20000; i++) {
		__u8 mem[8];
		for (unsigned j = 0; j < 8; j++) {
			state = state * 6364136223846793005ULL +
				1442695040888963407ULL;
			mem[j] = (__u8)(state >> 32);
		}
		struct flags in = {
			(__u8)(state & 1), (__u8)((state >> 1) & 1),
			(__u8)((state >> 2) & 1), (__u8)((state >> 3) & 1),
		};
		fails += check_case((enum op)(i & 3), state, (__u8)(state >> 8),
			in, mem,
			widths[(i >> 2) & 3]);
		cases++;
	}

	if (fails) {
		printf("x86 memory-ALU handler host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 memory-ALU handler host cross-check: OK (%u cases)\n", cases);
	return 0;
}
