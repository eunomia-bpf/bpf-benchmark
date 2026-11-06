/* Independent host oracle for the x86 memory-source bit-test handler
 * `BT [mem], imm8` and the BMI2 memory-source handler
 * `BZHI dst, [mem], count`.
 *
 * The generated side runs the real generated macros (`KPROG_X86_MEM_LOAD`,
 * `kprog_x86_bt_value`/`kprog_x86_bzhi_value`, `KPROG_X86_WRITE_REG*`); the
 * oracle recomputes the little-endian load with a byte loop and re-derives the
 * bit test, the kept-bit mask, and the width-confined register writeback with no
 * shared helper. `BT [mem], imm8` writes no register and only CF, while `BZHI`
 * writes the destination and defines CF/ZF/SF/OF. */

/* The generated headers define __always_inline functions for the in-kernel
 * build; provide the attribute for the host build. */
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
#include "generated/x86_bitops.h"
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
	for (unsigned i = 0; i < width; i++)
		value |= (__u64)p[i] << (8 * i);
	return value & width_mask(width);
}

/* BT oracle: test the indexed bit through a shifted one-bit mask. The index is
 * masked to 63 for a 64-bit base and to 31 otherwise, matching the simulator's
 * X86_SIM_L_EXEC_BT* (`width == X86_WIDTH_64 ? 63 : 31`); this is *not* the
 * width's bit count for the narrow widths, so an 8-bit `bt` at index 8 tests a
 * bit the byte does not have and is always clear. */
static __u8 bt_oracle(__u64 base, __u64 index, unsigned width)
{
	unsigned bit = (unsigned)(index & (width == X86_WIDTH_64 ? 63U : 31U));

	return (__u8)(((base & width_mask(width)) & (1ULL << bit)) ? 1U : 0U);
}

/* BZHI oracle: count is a byte, and the kept mask covers the low count bits or
 * the whole narrowed base once the count reaches the width. */
static __u64 bzhi_oracle(__u64 src, __u64 count, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned c = (unsigned)(count & 0xff);
	__u64 kept;

	if (c >= bits)
		kept = width_mask(width);
	else
		kept = (1ULL << c) - 1ULL;
	return src & kept & width_mask(width);
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

static struct result generated_bt(const __u8 *mem, __u64 old, __u8 tag,
				  struct flags in, __u64 index,
				  unsigned width)
{
	struct result out = { .dst = old, .tag = tag, .flags = in };
	__u64 base = KPROG_X86_MEM_LOAD(mem, width);

	out.flags.cf = kprog_x86_bt_value(base, index & 0xffffffffULL, width);
	return out;
}

static struct result generated_bzhi(const __u8 *mem, __u64 old, __u8 tag,
				    __u64 index, unsigned width)
{
	struct result out;
	__u64 count = index & 0xffULL;
	__u64 base = KPROG_X86_MEM_LOAD(mem, width);
	__u64 result = kprog_x86_bzhi_value(base, count, width);
	unsigned bits = KPROG_X86_WIDTH_BITS(width);

	out.flags.cf = (__u8)(count >= bits);
	out.flags.zf = (__u8)(result == 0);
	out.flags.sf = 0;
	out.flags.of = 0;
	out.dst = generated_write(old, result, width, &tag);
	out.tag = tag;
	return out;
}

/* BT [mem], imm8: no register is written and only CF changes. The immediate's
 * low 32 bits supply the bit index. */
static struct result oracle_bt(const __u8 *mem, __u64 old, __u8 tag,
			       struct flags in, __u64 index, unsigned width)
{
	struct result out = { .dst = old, .tag = tag, .flags = in };
	__u64 base = oracle_load(mem, width);

	out.flags.cf = bt_oracle(base, index & 0xffffffffULL, width);
	return out;
}

static struct result oracle_bzhi(const __u8 *mem, __u64 old, __u64 index,
				 unsigned width)
{
	struct result out;
	__u64 count = index & 0xffULL;
	__u64 result = bzhi_oracle(oracle_load(mem, width), count, width);

	out.flags.cf = (__u8)(count >= width_bits(width));
	out.flags.zf = (__u8)(result == 0);
	out.flags.sf = 0;
	out.flags.of = 0;
	out.dst = oracle_write(old, result, width);
	out.tag = 0;
	return out;
}

static int same_result(const char *name, struct result got, struct result want,
		       __u64 mem_seed, __u64 old, __u64 index, unsigned width)
{
	if (got.dst == want.dst && got.flags.cf == want.flags.cf &&
	    got.flags.zf == want.flags.zf && got.flags.sf == want.flags.sf &&
	    got.flags.of == want.flags.of)
		return 0;
	printf("MISMATCH %s w=%u mem=%#llx old=%#llx index=%#llx "
	       "dst=%#llx/%#llx cf=%u/%u zf=%u/%u sf=%u/%u of=%u/%u\n",
	       name, width, mem_seed, old, index, got.dst, want.dst,
	       got.flags.cf, want.flags.cf, got.flags.zf, want.flags.zf,
	       got.flags.sf, want.flags.sf, got.flags.of, want.flags.of);
	return 1;
}

static int check(int is_bt, __u64 mem_seed, __u64 old, __u64 index,
		 unsigned width)
{
	__u8 got_mem[16], want_mem[16];
	struct flags in = { (__u8)(mem_seed & 1), (__u8)((mem_seed >> 1) & 1),
			    (__u8)((mem_seed >> 2) & 1),
			    (__u8)((mem_seed >> 3) & 1) };

	for (unsigned i = 0; i < 16; i++)
		got_mem[i] = want_mem[i] = (__u8)(mem_seed >> (8 * (i % 8)));

	if (is_bt) {
		struct result got = generated_bt(got_mem, old, 7, in, index,
						 width);
		struct result want = oracle_bt(want_mem, old, 7, in, index,
					       width);

		return same_result("bt", got, want, mem_seed, old, index,
				   width);
	} else {
		struct result got = generated_bzhi(got_mem, old, 7, index,
						   width);
		struct result want =
			oracle_bzhi(want_mem, old, index, width);

		return same_result("bzhi", got, want, mem_seed, old, index,
				   width);
	}
}

int main(void)
{
	static const __u64 v[] = { 0, 1, ~0ULL, 0x7f, 0x80,
		0x7fffffffULL, 0x80000000ULL, 0x8000000000000000ULL };
	static const unsigned w[] = { 1, 2, 4, 8 };
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 2; op++)
		for (unsigned wi = 0; wi < 4; wi++)
			for (unsigned a = 0; a < 8; a++)
				for (unsigned c = 0; c < 8; c++) {
					fails += check((int)op, v[a], v[7 - a],
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
		fails += check((int)(i % 2), mem_seed, old, state,
			       w[(i >> 2) & 3]);
		cases++;
	}

	if (fails) {
		printf("x86 memory-bit host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("x86 memory-bit host cross-check: OK (%u cases)\n", cases);
	return 0;
}
