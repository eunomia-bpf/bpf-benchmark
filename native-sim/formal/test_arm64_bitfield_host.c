/*
 * Host cross-check for the generated AArch64 bitfield-composition contract.
 *
 * Runs the generated KPROG_ARM64_BITFIELD_VALUE macro outside the simulator and
 * compares it against an independent oracle written as a pure bit-level model.
 * The oracle derives every result bit from the architectural field position
 * instead of restating the macro's shift/mask expression, so a wrong guard, a
 * wrong shift direction or a wrong mask in the generated header shows up as a
 * bit disagreement. It does not include arm64_sim.h and does not reuse
 * arm64_bits_mask/arm64_sign_extend.
 *
 * Both the modelled domain (1 <= bits <= 64, lsb + bits <= 64) and the
 * out-of-domain operands that reach the generated guards (bits == 0,
 * bits > 64, lsb >= 64) are swept, because the guards are part of the contract.
 *
 * Build and run:
 *   cd native-sim/formal &&
 *   cc -Wall -Wextra -O2 -I. test_arm64_bitfield_host.c -o /tmp/t_bf_host &&
 *   /tmp/t_bf_host
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

/* Bitfield codes are kept local so the oracle is independent of
 * generated/arm64_decode.h; the generated header asserts the same values. */
#define ARM64_BITFIELD_UBFX 0U
#define ARM64_BITFIELD_SBFX 1U
#define ARM64_BITFIELD_UBFIZ 2U
#define ARM64_BITFIELD_BFXIL 3U
#define ARM64_BITFIELD_BFI 4U

#define ARM64_SIM_L_UNSUPPORTED_OPCODE() \
	do {                             \
	} while (0)

#include "generated/arm64_bitfield.h"

#include <stdio.h>

/* Independent oracle: a pure bit-level model over architectural positions. */
static __u64 bf_bit(__u64 value, unsigned index)
{
	return index < 64U ? (value >> index) & 1ULL : 0ULL;
}

/* Field width actually held by the 64-bit result: a wider field saturates. */
static unsigned bf_width(unsigned bits)
{
	return bits >= 64U ? 64U : bits;
}

/*
 * The value of `src[lsb + i]` for result bit `i`, for a field of `w` bits
 * starting at `lsb`. Bits at or above 64 read as zero, which also makes every
 * position unreachable once `lsb` is at or above 64.
 */
static __u64 bf_extract(__u64 src, unsigned lsb, unsigned width)
{
	__u64 value = 0ULL;
	unsigned i;

	for (i = 0; i < width; i++) {
		if (bf_bit(src, lsb + i))
			value |= 1ULL << i;
	}
	return value;
}

/* The low `width` bits of `src`, placed at result bit `lsb`; bits shifted past
 * 64 are dropped and a position at or above 64 keeps the destination bits. */
static __u64 bf_insert(__u64 src, unsigned lsb, unsigned width)
{
	__u64 value = 0ULL;
	unsigned i;

	for (i = 0; i < width; i++) {
		if (lsb + i < 64U && bf_bit(src, i))
			value |= 1ULL << (lsb + i);
	}
	return value;
}

/* Sign extension of a `width`-bit field: the field is replicated above its
 * top bit when that bit is set. A zero-width field is zero. */
static __u64 bf_sign_extend(__u64 field, unsigned width)
{
	unsigned i;

	if (width == 0U)
		return 0ULL;
	if (bf_bit(field, width - 1U))
		for (i = width; i < 64U; i++)
			field |= 1ULL << i;
	return field;
}

static __u64 bf_oracle(unsigned kind, __u64 src, __u64 dst, unsigned lsb,
		       unsigned bits)
{
	unsigned width = bf_width(bits);
	__u64 field;

	if (kind == ARM64_BITFIELD_UBFX)
		return bf_extract(src, lsb, width);
	if (kind == ARM64_BITFIELD_SBFX)
		return bf_sign_extend(bf_extract(src, lsb, width), width);
	if (kind == ARM64_BITFIELD_UBFIZ)
		return bf_insert(src, lsb, width);
	if (kind == ARM64_BITFIELD_BFXIL) {
		/* Extract at `lsb`, insert at the low end of the destination. */
		field = bf_extract(src, lsb, width);
		return (dst & ~(width >= 64U ? ~0ULL
					    : (1ULL << width) - 1ULL)) |
		       field;
	}
	if (kind == ARM64_BITFIELD_BFI) {
		/* Insert the source's low bits at `lsb`, keeping the rest. */
		__u64 low = bf_insert(src, lsb, width);
		__u64 placed = bf_insert(~0ULL, lsb, width);

		return (dst & ~placed) | low;
	}
	return 0ULL;
}

static int check_bf(unsigned kind, __u64 src, __u64 dst, unsigned lsb,
		    unsigned bits)
{
	__u64 res = KPROG_ARM64_BITFIELD_VALUE(kind, src, dst, lsb, bits,
					       ARM64_SIM_L_UNSUPPORTED_OPCODE());
	__u64 want = bf_oracle(kind, src, dst, lsb, bits);

	if (res != want) {
		printf("MISMATCH kind=%u src=%#llx dst=%#llx lsb=%u bits=%u "
		       "res=%#llx want=%#llx\n",
		       kind, src, dst, lsb, bits, res, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 srcs[] = {
		0x0ULL,
		0x1ULL,
		0xffULL,
		0x100ULL,
		0x1ffULL,
		0x80ULL,
		0x7fULL,
		0x8000ULL,
		0xffffffffULL,
		0x80000000ULL,
		0x7fffffffULL,
		0x0102030405060708ULL,
		0xfedcba9876543210ULL,
		0xffffffffffffffffULL,
		0x8000000000000000ULL,
		0x7fffffffffffffffULL,
	};
	static const __u64 dsts[] = {
		0x0ULL,
		0x1ULL,
		0xaaULL,
		0xffULL,
		0x5555555555555555ULL,
		0xaaaaaaaaaaaaaaaaULL,
		0xffffffffffff0000ULL,
		0xffffffffffffffffULL,
	};
	/* (lsb, bits) pairs inside the modelled domain lsb + bits <= 64. */
	static const unsigned fields[][2] = {
		{0U, 1U},   {0U, 4U},	{0U, 8U},   {0U, 16U},  {0U, 32U},
		{0U, 63U},  {0U, 64U},	{1U, 1U},   {1U, 63U},  {7U, 8U},
		{8U, 16U},  {8U, 32U},	{16U, 8U},  {31U, 1U},  {32U, 32U},
		{48U, 16U}, {56U, 8U},	{60U, 4U},  {63U, 1U},  {4U, 4U},
	};
	/* Operands that reach the generated guards instead of the model domain:
	 * zero width, widths past 64 and field positions at or past 64. */
	static const unsigned guards[][2] = {
		{0U, 0U},   {1U, 0U},	{7U, 0U},   {64U, 0U},  {0U, 65U},
		{1U, 65U},  {8U, 65U},	{0U, 100U}, {1U, 128U}, {31U, 200U},
		{32U, 65U}, {63U, 65U}, {64U, 64U}, {63U, 64U}, {64U, 1U},
		{64U, 8U},  {100U, 8U}, {255U, 1U}, {255U, 64U}, {255U, 255U},
		{65U, 255U},
	};
	unsigned cases = 0, fails = 0;

	for (unsigned i = 0; i < sizeof(srcs) / sizeof(srcs[0]); i++)
		for (unsigned d = 0; d < sizeof(dsts) / sizeof(dsts[0]); d++) {
			for (unsigned f = 0;
			     f < sizeof(fields) / sizeof(fields[0]); f++)
				for (unsigned kind = ARM64_BITFIELD_UBFX;
				     kind <= ARM64_BITFIELD_BFI; kind++) {
					fails += check_bf(kind, srcs[i], dsts[d],
							  fields[f][0], fields[f][1]);
					cases++;
				}
			for (unsigned g = 0;
			     g < sizeof(guards) / sizeof(guards[0]); g++)
				for (unsigned kind = ARM64_BITFIELD_UBFX;
				     kind <= ARM64_BITFIELD_BFI; kind++) {
					fails += check_bf(kind, srcs[i], dsts[d],
							  guards[g][0], guards[g][1]);
					cases++;
				}
		}

	__u64 state = 0x243f6a8885a308d3ULL;
	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 src, dst;
		unsigned lsb, bits;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		dst = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		lsb = (unsigned)(state & 0x7fU);
		bits = (unsigned)(state >> 8 & 0x7fU);
		for (unsigned kind = ARM64_BITFIELD_UBFX;
		     kind <= ARM64_BITFIELD_BFI; kind++) {
			fails += check_bf(kind, src, dst, lsb, bits);
			cases++;
		}
	}

	for (unsigned kind = ARM64_BITFIELD_UBFX; kind <= ARM64_BITFIELD_BFI;
	     kind++) {
		if (!KPROG_ARM64_BITFIELD_HANDLED(kind)) {
			printf("MISMATCH bitfield code %u not handled\n", kind);
			fails++;
		}
		cases++;
	}
	if (KPROG_ARM64_BITFIELD_HANDLED(ARM64_BITFIELD_BFI + 1U)) {
		printf("MISMATCH unhandled bitfield code reported as handled\n");
		fails++;
	}
	cases++;

	if (fails) {
		printf("arm64 bitfield host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 bitfield host cross-check: OK (%u cases)\n", cases);
	return 0;
}
