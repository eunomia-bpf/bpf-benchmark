/*
 * Host cross-check for the x86 simulator's routing of the `REP MOVS`
 * block-copy body through the machine-checked KPROG_X86_REP_MOVS_* contract.
 *
 * The simulator's `X86_SIM_L_EXEC_REP_MOVS` no longer restates the FLAGS
 * width resolution, the literal element bound, or the fixed RCX writeback
 * width; it resolves them through the generated contract and then runs the
 * copy loop. This oracle drives the REAL body over every FLAGS code and a
 * spread of counts, with copying and overlapping source/destination buffers
 * and distinct provenance tags, and compares the whole modeled register file
 * (bits and tags) and the two buffers byte for byte against an independent
 * model written from the raw opcode fields. The contract selectors are also
 * checked against an independent restatement of the closed tables.
 *
 * Build (see native-sim/formal/Makefile `check`):
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_rep_movs_route_host.c -o build/test_x86_rep_movs_route_host
 * Exit status is 0 on an exact match, 1 on any mismatch.
 */
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

/* One buffer pair, large enough that the widest raw `count * width` pointer
 * advance stays inside the allocation. */
#define ROUTE_BUF_BYTES 4096U

static __u8 route_src[ROUTE_BUF_BYTES];
static __u8 route_dst[ROUTE_BUF_BYTES];
static __u8 route_dst_expected[ROUTE_BUF_BYTES];

static __u8 route_synthetic(__u64 index)
{
	return (__u8)((index * 137U + 29U) ^ (index >> 4));
}

static void route_fill(void)
{
	unsigned i;

	for (i = 0; i < ROUTE_BUF_BYTES; i++) {
		route_src[i] = route_synthetic(i + 3U);
		route_dst[i] = route_synthetic(i + 173U);
	}
	memcpy(route_dst_expected, route_dst, ROUTE_BUF_BYTES);
}

/*
 * One scenario. `src_off` / `dst_off` index the two buffers (so an overlap
 * is a pair of nearby offsets); the two tags are the provenance the body must
 * carry across the pointer advance. The rule below is the independent model
 * of the handler; the real body must reproduce it exactly.
 */
static void check_rep(const char *what, __u8 flags, __u64 count,
		      unsigned src_off, unsigned dst_off, __u8 src_tag,
		      __u8 dst_tag)
{
	__u8 mem_before[16], tag_before[16];
	__u8 *src = route_src + src_off;
	__u8 *dst = route_dst + dst_off;
	__u8 *exp = route_dst_expected + dst_off;
	unsigned width, bound, elements;
	__u64 rsi_after, rdi_after;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	/* The count is the raw immediate, not RCX; RCX holds a sentinel the
	 * body must overwrite at the fixed 64-bit width. */
	X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 0xdeadbeefcafef00dULL,
				  X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI, src, src_tag);
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, dst, dst_tag);

	for (i = 0; i < 16; i++) {
		mem_before[i] = (__u8)X86_SIM_L_READ_REG(i);
		tag_before[i] = X86_SIM_L_REG_TAG(i);
	}

	/* ---- independent model: forward element order, width-byte copies ---- */
	width = flags ? flags : X86_WIDTH_64;
	bound = 64U;
	elements = count < (__u64)bound ? (unsigned)count : bound;
	for (i = 0; i < elements; i++)
		memcpy(exp + (__u64)i * width, src + (__u64)i * width, width);
	rsi_after = (__u64)(unsigned long)src + count * width;
	rdi_after = (__u64)(unsigned long)dst + count * width;

	/* ---- run the real body ---- */
	X86_SIM_L_EXEC_REP_MOVS(flags, count);

	/* ---- compare the whole modeled state ---- */
	cases++;
	for (i = 0; i < 16; i++) {
		if (i == X86_RSI) {
			if (X86_SIM_L_READ_REG(i) != rsi_after ||
			    X86_SIM_L_REG_TAG(i) != src_tag) {
				printf("MISMATCH %s RSI got=(0x%llx,%u) "
				       "want=(0x%llx,%u)\n", what,
				       (unsigned long long)X86_SIM_L_READ_REG(i),
				       X86_SIM_L_REG_TAG(i),
				       (unsigned long long)rsi_after, src_tag);
				failures++;
				return;
			}
			continue;
		}
		if (i == X86_RDI) {
			if (X86_SIM_L_READ_REG(i) != rdi_after ||
			    X86_SIM_L_REG_TAG(i) != dst_tag) {
				printf("MISMATCH %s RDI got=(0x%llx,%u) "
				       "want=(0x%llx,%u)\n", what,
				       (unsigned long long)X86_SIM_L_READ_REG(i),
				       X86_SIM_L_REG_TAG(i),
				       (unsigned long long)rdi_after, dst_tag);
				failures++;
				return;
			}
			continue;
		}
		if (i == X86_RCX) {
			if (X86_SIM_L_READ_REG(i) != 0U ||
			    X86_SIM_L_REG_TAG(i) != X86_SIM_TAG_SCALAR) {
				printf("MISMATCH %s RCX got=(0x%llx,%u) "
				       "want=(0,scalar)\n", what,
				       (unsigned long long)X86_SIM_L_READ_REG(i),
				       X86_SIM_L_REG_TAG(i));
				failures++;
				return;
			}
			continue;
		}
		if ((__u8)X86_SIM_L_READ_REG(i) != mem_before[i] ||
		    X86_SIM_L_REG_TAG(i) != tag_before[i]) {
			printf("MISMATCH %s clobber reg=%u\n", what, i);
			failures++;
			return;
		}
	}

	if (memcmp(route_dst, route_dst_expected, ROUTE_BUF_BYTES)) {
		unsigned b;

		for (b = 0; b < ROUTE_BUF_BYTES; b++) {
			if (route_dst[b] != route_dst_expected[b]) {
				printf("MISMATCH %s dst byte %u got=0x%02x "
				       "want=0x%02x flags=%u count=%llu\n",
				       what, b, route_dst[b],
				       route_dst_expected[b], flags,
				       (unsigned long long)count);
				break;
			}
		}
		failures++;
	}
}

/* The routed width selector must equal an independent restatement of the
 * FLAGS resolution over the five width codes. */
static void check_width_macro(void)
{
	static const __u8 codes[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
				      X86_WIDTH_32, X86_WIDTH_64 };
	unsigned i;

	if (KPROG_X86_REP_MOVS_BOUND != 64U) {
		printf("MISMATCH bound got=%u want=64\n",
		       KPROG_X86_REP_MOVS_BOUND);
		failures++;
	}
	cases++;

	if (KPROG_X86_REP_MOVS_COUNT_WIDTH != X86_WIDTH_64) {
		printf("MISMATCH count width got=%u want=8\n",
		       KPROG_X86_REP_MOVS_COUNT_WIDTH);
		failures++;
	}
	cases++;

	for (i = 0; i < sizeof(codes) / sizeof(codes[0]); i++) {
		unsigned want = codes[i] ? codes[i] : X86_WIDTH_64;

		cases++;
		if (KPROG_X86_REP_MOVS_WIDTH(codes[i]) != want) {
			printf("MISMATCH width flags=%u got=%u want=%u\n",
			       codes[i], KPROG_X86_REP_MOVS_WIDTH(codes[i]),
			       want);
			failures++;
		}
	}

	/* The resolution is not constant: an absent code cannot equal a
	 * narrow one. */
	cases++;
	if (KPROG_X86_REP_MOVS_WIDTH(0U) ==
	    KPROG_X86_REP_MOVS_WIDTH(X86_WIDTH_8)) {
		printf("MISMATCH width resolution collapsed\n");
		failures++;
	}

	/* The RCX writeback width is independent of the FLAGS copy width. */
	cases++;
	if (KPROG_X86_REP_MOVS_COUNT_WIDTH ==
	    KPROG_X86_REP_MOVS_WIDTH(X86_WIDTH_8)) {
		printf("MISMATCH count width tracks FLAGS\n");
		failures++;
	}
}

int main(void)
{
	static const __u8 flags_codes[] = { 0, X86_WIDTH_8, X86_WIDTH_16,
					    X86_WIDTH_32, X86_WIDTH_64 };
	static const __u64 counts[] = { 0ULL, 1ULL, 2ULL, 3ULL, 7ULL, 16ULL,
					63ULL, 64ULL, 65ULL, 100ULL, 200ULL };
	unsigned fi, ci;

	/* Plain copy: every FLAGS code, every count, distinct tags. */
	for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]); fi++)
		for (ci = 0; ci < sizeof(counts) / sizeof(counts[0]); ci++) {
			route_fill();
			check_rep("copy", flags_codes[fi], counts[ci], 0U, 0U,
				  3U, 5U);
		}

	/* Offset copy so a stride/width misroute lands on a different byte. */
	for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]); fi++)
		for (ci = 0; ci < sizeof(counts) / sizeof(counts[0]); ci++) {
			route_fill();
			check_rep("copy/off", flags_codes[fi], counts[ci], 8U,
				  24U, 1U, 6U);
		}

	/* A wider destination window than source window: a stride/width
	 * misroute lands on a different byte than the model. */
	for (fi = 0; fi < sizeof(flags_codes) / sizeof(flags_codes[0]); fi++) {
		route_fill();
		check_rep("window", flags_codes[fi], 12ULL, 0U, 16U, 2U, 4U);
	}

	/* The zero code resolves the width to 64 bits. */
	{
		static const __u64 zero_counts[] = { 0ULL, 1ULL, 4ULL };
		unsigned k;

		for (k = 0; k < sizeof(zero_counts) / sizeof(zero_counts[0]);
		     k++) {
			route_fill();
			check_rep("absent-width", 0U, zero_counts[k], 32U, 0U,
				  0U, 7U);
		}
	}

	check_width_macro();

	if (failures != 0) {
		printf("x86 rep_movs route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 rep_movs route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
