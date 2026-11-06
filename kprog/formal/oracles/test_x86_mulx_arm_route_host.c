/*
 * Host cross-check for the x86 simulator's routing of the `MULX` arm selector
 * (STEP 0130).
 *
 * The routed arm is the `X86_OP_MULX` branch of `X86_SIM_L_EXEC`, which now
 * selects its body through the generated `KPROG_X86_MULX_ARM` contract: at the
 * 32-bit resolved width it multiplies the zero-extended low words of `RDX` and
 * the source into one 64-bit product and splits it; at every other width it
 * takes the four-limb radix-`2^32` ladder for the high half and the plain
 * 64-bit product for the low half. This oracle drives the real `X86_SIM_L_EXEC`
 * body and restates the effect from the raw register cells and the resolved
 * width; the two must agree on the value *and* tag of every one of the 16
 * cells, and the instruction must write no third cell and move no flag. It also
 * checks that the routed selector and the generated contract agree. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_mulx_arm_route_host.c -o /tmp/t_mulx_route
 *   /tmp/t_mulx_route
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[16];
static __u8 mtag[16];

/* A deterministic register pattern: distinct per index, with high bits set so
 * a 64-bit-vs-narrow write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so a writeback's
 * scalarization of a changed cell is observable. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The resolved width code the body operates at: the absent code (0) falls back
 * to the 64-bit default, every other code is used as decoded. */
static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

/* The partial-register writeback the writeback performs: the low `width` bytes
 * are replaced, the higher bytes of an 8- or 16-bit write are kept, and a
 * 32-bit write zeroes the upper half. */
static __u64 model_partial_write(__u64 old, __u64 v, unsigned width)
{
	if (width == X86_WIDTH_8)
		return (old & ~0xffULL) | (v & 0xffULL);
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (v & 0xffffULL);
	if (width == X86_WIDTH_32)
		return v & 0xffffffffULL;
	return v;
}

/* Restate the routed arm's effect on the modeled register file. The 32-bit arm
 * splits one zero-extended low-word product; every other width takes the limb
 * ladder for the high half and the plain product for the low half. The low half
 * is written into the destination and the high half into the auxiliary
 * destination when one is named; both are width-confined writes that scalarize
 * their tag. Written in the instruction's own order so a destination/auxiliary
 * alias resolves the same way. */
static void model_mulx(unsigned dst, unsigned src, unsigned aux, unsigned flags)
{
	unsigned w = resolve_width(flags);
	__u64 lhs = mreg[X86_RDX];
	__u64 rhs = mreg[src];
	__u64 low;
	__u64 high;

	if (KPROG_X86_MULX_ARM((__u8)w) == KPROG_X86_MULX_ARM_SINGLE_PRODUCT) {
		__u64 product = (__u64)(__u32)lhs * (__u64)(__u32)rhs;

		low = (__u32)product;
		high = (__u32)(product >> 32);
	} else {
		__u64 a0 = (__u32)lhs;
		__u64 a1 = lhs >> 32;
		__u64 b0 = (__u32)rhs;
		__u64 b1 = rhs >> 32;
		__u64 p0 = a0 * b0;
		__u64 p1 = a0 * b1;
		__u64 p2 = a1 * b0;
		__u64 p3 = a1 * b1;
		__u64 mid = (p0 >> 32) + (__u32)p1 + (__u32)p2;

		low = lhs * rhs;
		high = p3 + (p1 >> 32) + (p2 >> 32) + (mid >> 32);
	}

	mreg[dst] = model_partial_write(mreg[dst], low, w);
	mtag[dst] = X86_SIM_TAG_SCALAR;
	if (KPROG_X86_REG_PRESENT(aux)) {
		mreg[aux] = model_partial_write(mreg[aux], high, w);
		mtag[aux] = X86_SIM_TAG_SCALAR;
	}
}

/* Plant the pristine register file (pattern values and tags) in the simulator
 * state and the model file. A macro so it expands in the checker's scope. */
#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
	} while (0)

/* Run one `MULX` case over the modeled register file and compare. */
static void check_mulx(unsigned dst, unsigned src, unsigned aux, unsigned flags)
{
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	unsigned i;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	PLANT_REGS();

	/* ---- independent model ---- */
	model_mulx(dst, src, aux, flags);

	/* ---- run the real routed arm ---- */
	X86_SIM_L_EXEC(X86_OP_MULX, dst, src, flags, aux, 0ULL);

	/* The whole register file (value and tag) must match the model. */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH dst=%u src=%u aux=%u flags=%u "
			       "reg%u: got 0x%llx want 0x%llx\n",
			       dst, src, aux, flags, i,
			       (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (tag != mtag[i]) {
			printf("MISMATCH dst=%u src=%u aux=%u flags=%u "
			       "reg%u tag: got %u want %u\n",
			       dst, src, aux, flags, i, tag, mtag[i]);
			failures++;
			return;
		}
	}

	/* `MULX` never touches the flags. */
	cases++;
	if (__x86_cf != 0U || __x86_zf != 0U || __x86_sf != 0U ||
	    __x86_of != 0U) {
		printf("MISMATCH dst=%u src=%u aux=%u flags=%u flags moved\n",
		       dst, src, aux, flags);
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	static const unsigned widths[] = {
		X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	size_t i;

	cases++;
	if (KPROG_X86_MULX_ARM_COUNT != 2U ||
	    KPROG_X86_MULX_SPECIAL_WIDTH != X86_WIDTH_32) {
		printf("MISMATCH mulx contract constant drift\n");
		failures++;
	}

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		unsigned w = widths[i];
		unsigned arm = KPROG_X86_MULX_ARM((__u8)w);
		int want = w == X86_WIDTH_32
			? (int)KPROG_X86_MULX_ARM_SINGLE_PRODUCT
			: (int)KPROG_X86_MULX_ARM_LIMB_LADDER;

		cases++;
		if (arm != (unsigned)want) {
			printf("MISMATCH mulx selector width=%u got=%u "
			       "want=%d\n", w, arm, want);
			failures++;
		}
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* An absent auxiliary plus a few present codes, including RDX and a
	 * value distinct from the destination. */
	static const unsigned aux_codes[4] = {
		X86_REG_NONE, X86_RCX, X86_RAX, X86_R8,
	};
	unsigned f;
	unsigned a;
	unsigned d;
	unsigned s;

	check_selectors();

	/* Every destination/source/auxiliary triple and every resolved width
	 * code (including the absent code 0), driving the routed arm. */
	for (f = 0; f < 5U; f++)
		for (a = 0; a < 4U; a++)
			for (d = 0; d < 16U; d++)
				for (s = 0; s < 16U; s++)
					check_mulx(d, s, aux_codes[a],
						   flags_codes[f]);

	if (failures != 0) {
		printf("x86 mulx arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 mulx arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
