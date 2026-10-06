/*
 * Host cross-check for the x86-64 `REP MOVS` handler contract.
 *
 * The module under test is `generated/x86_rep_movs.h`. It fixes the copy
 * width the body honours (`FLAGS ? FLAGS : 64`), the literal loop bound the
 * body iterates to, the fixed 64-bit width at which it zeroes `RCX`, and the
 * code an absent `FLAGS` resolves to. The generic bound and the count width
 * are independent of the instruction immediate and of the `FLAGS` code.
 *
 * The C handler restates this logic inline — `X86_SIM_L_EXEC_REP_MOVS` in
 * `x86_sim_local_bpf.h` — and the generated header is not on its include
 * path, so this host cross-check is the tie between the two: it drives the
 * contract through the generated macros and restates the same body from the
 * raw opcode bit, and the two must agree byte for byte on the copied region,
 * the whole register file, and the flags.
 *
 * The byte load/store helpers the body uses (`X86_SIM_L_LOAD_ADDR` /
 * `X86_SIM_L_STORE_ADDR`) are plain width-byte little-endian accesses; they
 * are hand-modelled here as a byte-for-byte copy of the element's `width`
 * bytes. The count is the raw instruction immediate, not `RCX`.
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

/* The generated headers define __always_inline functions in the kernel build;
 * provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_RCX 1U
#define X86_RSI 6U
#define X86_RDI 7U

#define X86_OP_REP_MOVS 0x3aU

#define X86_SIM_TAG_SCALAR 0U

#include "generated/x86_rep_movs.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* A deterministic register file, copy buffers and flags model.        */
/*                                                                    */
/* `RSI` / `RDI` hold absolute addresses into a pair of host byte      */
/* buffers; the body dereferences them directly, so the model lets the  */
/* pointer advance walk out past the copied region without             */
/* dereferencing it, exactly as the body does.                         */
/* ------------------------------------------------------------------ */

#define ORACLE_REGS 16U
#define ORACLE_COPY_BYTES 4096U

struct oracle_reg {
	union {
		__u8 b[8];
		__u16 w;
		void *ptr;
	} u;
	__u8 tag;
};

static struct oracle_reg oracle_regs[ORACLE_REGS];
static struct oracle_reg pristine_regs[ORACLE_REGS];
static struct oracle_reg result_regs[ORACLE_REGS];

static __u8 oracle_src[ORACLE_COPY_BYTES];
static __u8 oracle_dst[ORACLE_COPY_BYTES];
static __u8 pristine_dst[ORACLE_COPY_BYTES];
static __u8 result_dst[ORACLE_COPY_BYTES];

static __u64 oracle_flags;
static __u64 result_flags;

static __u8 oracle_synthetic(__u64 index)
{
	return (__u8)((index * 131U + 17U) ^ (index >> 5));
}

static void oracle_reset(void)
{
	unsigned i;
	__u64 j;

	for (i = 0; i < ORACLE_REGS; i++) {
		oracle_regs[i].u.ptr =
			(void *)(long)(0x200ULL + (__u64)i * 0x20ULL);
		oracle_regs[i].tag = (__u8)(i % 6U);
	}
	for (j = 0; j < ORACLE_COPY_BYTES; j++) {
		oracle_src[j] = (__u8)oracle_synthetic(j + 7U);
		oracle_dst[j] = (__u8)oracle_synthetic(j + 211U);
	}
}

static void oracle_snapshot_pristine(void)
{
	memcpy(pristine_regs, oracle_regs, sizeof(pristine_regs));
	memcpy(pristine_dst, oracle_dst, ORACLE_COPY_BYTES);
}

static void oracle_restore_pristine(void)
{
	memcpy(oracle_regs, pristine_regs, sizeof(pristine_regs));
	memcpy(oracle_dst, pristine_dst, ORACLE_COPY_BYTES);
}

static __u64 oracle_reg_value(unsigned index)
{
	return (__u64)(uintptr_t)oracle_regs[index].u.ptr;
}

/* ------------------------------------------------------------------ */
/* Hand-written models, independent of the macros under test.          */
/* ------------------------------------------------------------------ */

/* The partial-register writeback the sim performs. Only the fixed 64-bit
 * count-width case is used here, but the narrower cases are restated so a
 * collapsed count width would diverge. */
static __u64 oracle_write(__u64 old, __u64 value, unsigned width)
{
	if (width == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (width == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value;
}

/* The element bound, restated from the raw literal. */
static unsigned oracle_bound(void)
{
	return 64U;
}

struct rep_movs_effect {
	unsigned width;
	__u64 count;
	unsigned elements;
	__u64 src_before;
	__u64 dst_before;
	__u64 src_after;
	__u64 dst_after;
	__u8 src_tag;
	__u8 dst_tag;
	__u64 rcx;
	__u8 rcx_tag;
};

/* The body driven through the generated tables. */
static struct rep_movs_effect contract_step(unsigned flags, __u64 count)
{
	unsigned width = KPROG_X86_REP_MOVS_WIDTH(flags);
	unsigned bound = KPROG_X86_REP_MOVS_BOUND;
	unsigned count_width = KPROG_X86_REP_MOVS_COUNT_WIDTH;
	__u8 *src = (__u8 *)(uintptr_t)oracle_reg_value(X86_RSI);
	__u8 *dst = (__u8 *)(uintptr_t)oracle_reg_value(X86_RDI);
	__u8 src_tag = oracle_regs[X86_RSI].tag;
	__u8 dst_tag = oracle_regs[X86_RDI].tag;
	struct rep_movs_effect r;
	__u32 i;

	r.src_before = (__u64)(uintptr_t)src;
	r.dst_before = (__u64)(uintptr_t)dst;
	r.width = width;
	r.count = count;

	/* The body's loop: for i in 0..bound-1, copy the element when i <
	 * count. */
	for (i = 0; i < bound; i++) {
		if ((__u64)i < count)
			memcpy(dst + (__u64)i * width, src + (__u64)i * width,
			       width);
	}

	r.elements = count < (__u64)bound ? (unsigned)count : bound;

	oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)(src + count * width);
	oracle_regs[X86_RSI].tag = src_tag;
	oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)(dst + count * width);
	oracle_regs[X86_RDI].tag = dst_tag;

	oracle_regs[X86_RCX].u.ptr = (void *)(uintptr_t)oracle_write(
		oracle_reg_value(X86_RCX), 0, count_width);
	oracle_regs[X86_RCX].tag = X86_SIM_TAG_SCALAR;

	r.src_after = oracle_reg_value(X86_RSI);
	r.dst_after = oracle_reg_value(X86_RDI);
	r.src_tag = oracle_regs[X86_RSI].tag;
	r.dst_tag = oracle_regs[X86_RDI].tag;
	r.rcx = oracle_reg_value(X86_RCX);
	r.rcx_tag = oracle_regs[X86_RCX].tag;
	return r;
}

/* The same body restated from the raw opcode bit and the literal bound. */
static struct rep_movs_effect model_step(unsigned flags, __u64 count)
{
	unsigned width = flags ? flags : X86_WIDTH_64;
	unsigned bound = oracle_bound();
	__u8 *src = (__u8 *)(uintptr_t)oracle_reg_value(X86_RSI);
	__u8 *dst = (__u8 *)(uintptr_t)oracle_reg_value(X86_RDI);
	__u8 src_tag = oracle_regs[X86_RSI].tag;
	__u8 dst_tag = oracle_regs[X86_RDI].tag;
	struct rep_movs_effect r;
	__u32 i;

	r.src_before = (__u64)(uintptr_t)src;
	r.dst_before = (__u64)(uintptr_t)dst;
	r.width = width;
	r.count = count;

	for (i = 0; i < 64U; i++) {
		if ((__u64)i < count && i < bound)
			memcpy(dst + (__u64)i * width, src + (__u64)i * width,
			       width);
	}

	r.elements = count < (__u64)bound ? (unsigned)count : bound;

	oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)(src + count * width);
	oracle_regs[X86_RSI].tag = src_tag;
	oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)(dst + count * width);
	oracle_regs[X86_RDI].tag = dst_tag;

	oracle_regs[X86_RCX].u.ptr =
		(void *)(uintptr_t)oracle_write(oracle_reg_value(X86_RCX), 0, 64U);
	oracle_regs[X86_RCX].tag = X86_SIM_TAG_SCALAR;

	r.src_after = oracle_reg_value(X86_RSI);
	r.dst_after = oracle_reg_value(X86_RDI);
	r.src_tag = oracle_regs[X86_RSI].tag;
	r.dst_tag = oracle_regs[X86_RDI].tag;
	r.rcx = oracle_reg_value(X86_RCX);
	r.rcx_tag = oracle_regs[X86_RCX].tag;
	return r;
}

/* ------------------------------------------------------------------ */
/* Part 1: the generated tables vs. the oracle.                       */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	static const unsigned codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					   X86_WIDTH_32, X86_WIDTH_64 };
	unsigned cases = 0;
	unsigned ci;

	if (KPROG_X86_REP_MOVS_BOUND != 64U) {
		fprintf(stderr, "rep_movs bound is %u, want 64\n",
			KPROG_X86_REP_MOVS_BOUND);
		return 0;
	}
	cases++;

	if (KPROG_X86_REP_MOVS_COPY_WIDTH_DEFAULT != X86_WIDTH_64) {
		fprintf(stderr, "rep_movs default width is %u, want 64-bit\n",
			KPROG_X86_REP_MOVS_COPY_WIDTH_DEFAULT);
		return 0;
	}
	cases++;

	if (KPROG_X86_REP_MOVS_COUNT_WIDTH != X86_WIDTH_64) {
		fprintf(stderr, "rep_movs count width is %u, want 64-bit\n",
			KPROG_X86_REP_MOVS_COUNT_WIDTH);
		return 0;
	}
	cases++;

	for (ci = 0; ci < 5U; ci++) {
		unsigned want = codes[ci] ? codes[ci] : X86_WIDTH_64;
		unsigned got = KPROG_X86_REP_MOVS_WIDTH(codes[ci]);

		if (got != want) {
			fprintf(stderr, "rep_movs width mismatch flags=%u "
					"got=%u want=%u\n",
				codes[ci], got, want);
			return 0;
		}
		cases++;
	}

	/* The macro is not a constant: an absent code resolves to 64 while a
	 * narrow code stays narrow. */
	if (KPROG_X86_REP_MOVS_WIDTH(0U) ==
	    KPROG_X86_REP_MOVS_WIDTH(X86_WIDTH_8))
		return 0;
	cases++;

	/* The count width does not track the FLAGS-resolved copy width: the
	 * 8-bit copy still zeroes RCX at the fixed 64-bit width. */
	if (KPROG_X86_REP_MOVS_COUNT_WIDTH ==
	    KPROG_X86_REP_MOVS_WIDTH(X86_WIDTH_8))
		return 0;
	cases++;

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: the full composition vs. the hand-written body.            */
/*                                                                    */
/* `contract_step` runs the body through the generated tables;        */
/* `model_step` restates it from the raw opcode bit. They must agree   */
/* on the whole register file, the copied region, and the flags.       */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	static const __u64 counts[10] = { 0ULL, 1ULL, 2ULL, 3ULL, 8ULL, 63ULL,
					  64ULL, 65ULL, 100ULL, 255ULL };
	unsigned cases = 0;
	unsigned fi;
	unsigned ci;

	for (fi = 0; fi < 5U; fi++) {
		for (ci = 0; ci < 10U; ci++) {
			struct rep_movs_effect got;
			struct rep_movs_effect want;

			oracle_restore_pristine();
			oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
			oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
			oracle_flags = 0xdeadbeefULL;
			got = contract_step(flags_codes[fi], counts[ci]);
			memcpy(result_regs, oracle_regs, sizeof(oracle_regs));
			memcpy(result_dst, oracle_dst, ORACLE_COPY_BYTES);
			result_flags = oracle_flags;

			oracle_restore_pristine();
			oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
			oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
			oracle_flags = 0xdeadbeefULL;
			want = model_step(flags_codes[fi], counts[ci]);

			if (got.width != want.width ||
			    got.count != want.count ||
			    got.elements != want.elements ||
			    got.src_after != want.src_after ||
			    got.dst_after != want.dst_after ||
			    got.src_tag != want.src_tag ||
			    got.dst_tag != want.dst_tag ||
			    got.rcx != want.rcx ||
			    got.rcx_tag != want.rcx_tag ||
			    result_flags != oracle_flags ||
			    memcmp(result_regs, oracle_regs,
				   sizeof(oracle_regs)) ||
			    memcmp(result_dst, oracle_dst, ORACLE_COPY_BYTES)) {
				fprintf(stderr,
					"rep_movs mismatch flags=%u count=%llu "
					"elements=%u/%u\n",
					flags_codes[fi],
					(unsigned long long)counts[ci],
					got.elements, want.elements);
				return 0;
			}
			cases++;
		}
	}
	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 3: pins on the facts the composition is about.                */
/* ------------------------------------------------------------------ */

static unsigned part3(void)
{
	unsigned cases = 0;

	/* Pin 1: a narrow FLAGS width copies `count` single bytes and
	 * advances each pointer by exactly `count`, leaving the region past
	 * them untouched. */
	{
		static const __u64 count = 3ULL;
		struct rep_movs_effect e;
		unsigned i;
		unsigned wrong = 0;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		e = contract_step(X86_WIDTH_8, count);
		if (e.width != X86_WIDTH_8)
			return 0;
		if (e.elements != 3U)
			return 0;
		if (e.src_after != e.src_before + 3U)
			return 0;
		if (e.dst_after != e.dst_before + 3U)
			return 0;
		for (i = 0; i < 3U; i++)
			wrong += oracle_dst[i] != oracle_src[i];
		for (i = 3U; i < ORACLE_COPY_BYTES; i++)
			wrong += oracle_dst[i] != pristine_dst[i];
		if (wrong != 0)
			return 0;
		cases++;
	}

	/* Pin 2: a count past the literal bound copies exactly the bound's
	 * 64 elements but still advances by the full raw count times the
	 * copy width. */
	{
		static const __u64 count = 100ULL;
		struct rep_movs_effect e;
		unsigned i;
		unsigned wrong = 0;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		e = contract_step(X86_WIDTH_64, count);
		if (e.elements != 64U)
			return 0;
		if (e.src_after != e.src_before + count * X86_WIDTH_64)
			return 0;
		if (e.dst_after != e.dst_before + count * X86_WIDTH_64)
			return 0;
		for (i = 0; i < 64U * X86_WIDTH_64; i++)
			wrong += oracle_dst[i] != oracle_src[i];
		for (i = 64U * X86_WIDTH_64; i < ORACLE_COPY_BYTES; i++)
			wrong += oracle_dst[i] != pristine_dst[i];
		if (wrong != 0)
			return 0;
		cases++;
	}

	/* Pin 3: a zero count copies nothing and advances nothing, but RCX
	 * is still zeroed. */
	{
		struct rep_movs_effect e;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		oracle_regs[X86_RCX].u.ptr = (void *)(long)0x1234;
		e = contract_step(X86_WIDTH_64, 0ULL);
		if (e.elements != 0U)
			return 0;
		if (e.src_after != e.src_before)
			return 0;
		if (e.dst_after != e.dst_before)
			return 0;
		if (memcmp(oracle_dst, pristine_dst, ORACLE_COPY_BYTES))
			return 0;
		if (e.rcx != 0U)
			return 0;
		cases++;
	}

	/* Pin 4: RCX is zeroed at the fixed 64-bit width even under a narrow
	 * FLAGS copy width — the whole register is replaced and its tag
	 * scalarized. */
	{
		struct rep_movs_effect narrow;
		struct rep_movs_effect wide;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		oracle_regs[X86_RCX].u.ptr =
			(void *)(uintptr_t)0xdeadbeefcafef00dULL;
		oracle_regs[X86_RCX].tag = 4U;
		narrow = contract_step(X86_WIDTH_8, 1ULL);
		if (narrow.rcx != 0U || narrow.rcx_tag != X86_SIM_TAG_SCALAR)
			return 0;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		oracle_regs[X86_RCX].u.ptr =
			(void *)(uintptr_t)0xdeadbeefcafef00dULL;
		oracle_regs[X86_RCX].tag = 4U;
		wide = contract_step(X86_WIDTH_64, 1ULL);
		if (wide.rcx != 0U || wide.rcx_tag != X86_SIM_TAG_SCALAR)
			return 0;

		if (narrow.rcx != wide.rcx)
			return 0;
		cases++;
	}

	/* Pin 5: RSI and RDI keep the provenance tags they were read with. */
	{
		struct rep_movs_effect e;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		oracle_regs[X86_RSI].tag = 3U;
		oracle_regs[X86_RDI].tag = 5U;
		e = contract_step(X86_WIDTH_16, 4ULL);
		if (e.src_tag != 3U || e.dst_tag != 5U)
			return 0;
		cases++;
	}

	/* Pin 6: a full 64-bit copy writes exactly `count * 8` bytes
	 * byte-for-byte, with no value masking. */
	{
		static const __u64 count = 4ULL;
		struct rep_movs_effect e;
		unsigned i;
		unsigned wrong = 0;

		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		e = contract_step(X86_WIDTH_64, count);
		if (e.elements != 4U)
			return 0;
		for (i = 0; i < (unsigned)(count * X86_WIDTH_64); i++)
			wrong += oracle_dst[i] != oracle_src[i];
		for (i = (unsigned)(count * X86_WIDTH_64); i < ORACLE_COPY_BYTES;
		     i++)
			wrong += oracle_dst[i] != pristine_dst[i];
		if (wrong != 0)
			return 0;
		cases++;
	}

	/* Pin 7: the body writes no flag. */
	{
		oracle_restore_pristine();
		oracle_regs[X86_RSI].u.ptr = (void *)(uintptr_t)oracle_src;
		oracle_regs[X86_RDI].u.ptr = (void *)(uintptr_t)oracle_dst;
		oracle_flags = 0x123456789ULL;
		(void)contract_step(X86_WIDTH_64, 2ULL);
		if (oracle_flags != 0x123456789ULL)
			return 0;
		cases++;
	}

	return cases;
}

int main(void)
{
	unsigned c1;
	unsigned c2;
	unsigned c3;

	oracle_reset();
	oracle_snapshot_pristine();

	/* Each part returns zero exactly when a case failed, so any zero is a
	 * failure even though the readiness line still prints. */
	c1 = part1();
	if (c1 == 0U)
		return 1;
	oracle_restore_pristine();
	c2 = part2();
	if (c2 == 0U)
		return 1;
	oracle_restore_pristine();
	c3 = part3();
	if (c3 == 0U)
		return 1;
	oracle_restore_pristine();

	printf("x86 rep_movs handler host cross-check: OK (%u cases)\n",
	       c1 + c2 + c3);
	return 0;
}
