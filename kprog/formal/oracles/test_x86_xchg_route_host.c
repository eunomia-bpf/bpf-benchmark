/*
 * Host cross-check for the x86 simulator's routing of the `XCHG` arm (STEP
 * 0114).
 *
 * The routed arm is the `X86_OP_XCHG` branch of `X86_SIM_L_EXEC`, which now
 * selects its body through the generated `KPROG_X86_XCHG_ARM` contract: at the
 * full 64-bit width it swaps the two register cells as raw pointer cells
 * (`X86_SIM_L_READ_REG_PTR` / `X86_SIM_L_WRITE_REG_PTR`), at every narrower
 * width it reads both cells as 64-bit values and writes each with
 * `X86_SIM_L_WRITE_REG_WIDTH`. This oracle drives the real `X86_SIM_L_EXEC`
 * body and restates the effect from the raw register cells and the resolved
 * width; the two must agree on the value *and* tag of every one of the 16
 * cells, and the swap must leave no third cell moved. It also checks that the
 * routed selector and the generated contract agree. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_xchg_route_host.c -o /tmp/t_xchg_route
 *   /tmp/t_xchg_route
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

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so the swap's
 * scalarization of both cells is observable. */
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

/* The partial-register writeback the narrow arm performs: the low `width`
 * bytes are replaced, the higher bytes of an 8- or 16-bit write are kept, and
 * a 32-bit write zeroes the upper half. */
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

/* Restate the routed arm's effect on the modeled register file. The pointer
 * arm exchanges whole 64-bit cells; the subword arm exchanges the low-lane
 * windows at the resolved width. Both scalarize both tags. */
static void model_xchg(unsigned dst, unsigned src, unsigned flags)
{
	unsigned w = resolve_width(flags);
	__u64 dv = mreg[dst];
	__u64 sv = mreg[src];

	if (w == X86_WIDTH_64) {
		mreg[dst] = sv;
		mreg[src] = dv;
	} else {
		mreg[dst] = model_partial_write(dv, sv, w);
		mreg[src] = model_partial_write(sv, dv, w);
	}
	mtag[dst] = X86_SIM_TAG_SCALAR;
	mtag[src] = X86_SIM_TAG_SCALAR;
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

/* Compare the whole register file after a case: the two operands must match
 * the model (value and tag), and no other cell may move. */
#define COMPARE_STATE(DST, SRC, FLAGS)                                     \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 16U; __cs_i++) {                \
			__u64 __cs_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__cs_i); \
			__u8 __cs_tag = X86_SIM_L_REG_TAG(__cs_i);        \
			cases++;                                          \
			if ((__cs_i == (DST) || __cs_i == (SRC)) &&       \
			    __cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH dst=%u src=%u flags=%u "  \
				       "reg%u: got 0x%llx want 0x%llx\n", \
				       (DST), (SRC), (FLAGS),             \
				       (unsigned)__cs_i,                  \
				       (unsigned long long)__cs_got,      \
				       (unsigned long long)mreg[__cs_i]); \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if ((__cs_i == (DST) || __cs_i == (SRC)) &&       \
			    __cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH dst=%u src=%u flags=%u "  \
				       "reg%u tag: got %u want %u\n",     \
				       (DST), (SRC), (FLAGS),             \
				       (unsigned)__cs_i, __cs_tag,        \
				       mtag[__cs_i]);                     \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_i != (DST) && __cs_i != (SRC) &&         \
			    (__cs_got != mreg[__cs_i] ||                  \
			     __cs_tag != mtag[__cs_i])) {                 \
				printf("MISMATCH dst=%u src=%u flags=%u "  \
				       "third cell reg%u moved\n",        \
				       (DST), (SRC), (FLAGS),             \
				       (unsigned)__cs_i);                 \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/* Run one `XCHG` case over the modeled register file and compare. */
static void check_xchg(unsigned dst, unsigned src, unsigned flags)
{
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
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
	model_xchg(dst, src, flags);

	/* ---- run the real routed arm ---- */
	X86_SIM_L_EXEC(X86_OP_XCHG, dst, src, flags, 0U, 0ULL);

	COMPARE_STATE(dst, src, flags);

	/* The swap never touches the flags. */
	cases++;
	if (__x86_cf != 0U || __x86_zf != 0U || __x86_sf != 0U ||
	    __x86_of != 0U) {
		printf("MISMATCH dst=%u src=%u flags=%u flags moved\n",
		       dst, src, flags);
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
	if (KPROG_X86_XCHG_ARM_COUNT != 2U ||
	    KPROG_X86_XCHG_FULL_WIDTH != X86_WIDTH_64) {
		printf("MISMATCH xchg contract constant drift\n");
		failures++;
	}

	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		unsigned w = widths[i];
		unsigned arm = KPROG_X86_XCHG_ARM((__u8)w);
		int want = w == X86_WIDTH_64
			? (int)KPROG_X86_XCHG_ARM_POINTER_SWAP
			: (int)KPROG_X86_XCHG_ARM_SUBWORD_SWAP;

		cases++;
		if (arm != (unsigned)want) {
			printf("MISMATCH xchg selector width=%u got=%u "
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
	unsigned f;
	unsigned d;
	unsigned s;

	check_selectors();

	/* Every operand pair and every resolved width code (including the
	 * absent code 0), driving the routed arm. */
	for (f = 0; f < 5U; f++)
		for (d = 0; d < 16U; d++)
			for (s = 0; s < 16U; s++)
				check_xchg(d, s, flags_codes[f]);

	if (failures != 0) {
		printf("x86 xchg route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 xchg route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
