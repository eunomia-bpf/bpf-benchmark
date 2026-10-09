/*
 * Host cross-check for the x86 simulator's routing of the `POPCNT` flag block
 * (STEP 0117).
 *
 * Drives the real routed `X86_OP_POPCNT` arm of `X86_SIM_L_EXEC` (via
 * `x86/x86_sim_local_bpf.h`) and compares its whole effect -- the destination
 * window, the register tag, and the four arithmetic flags -- against an
 * independent model that: narrows the source to the effective width, counts its
 * bits with a one-bit-at-a-time walk, clears `CF`/`SF`/`OF`, sets `ZF` from the
 * narrowed source being zero, and partial-writes the destination. The flag block
 * is the only thing STEP 0117 changes; the value contract is proved separately.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../.. \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_popcnt_flags_route_host.c -o /tmp/t_pc_route && /tmp/t_pc_route
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
static __u8 mcf, mzf, msf, mof;

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

static unsigned width_bits(unsigned width)
{
	switch (width) {
	case X86_WIDTH_8: return 8U;
	case X86_WIDTH_16: return 16U;
	case X86_WIDTH_32: return 32U;
	default: return 64U;
	}
}

static __u64 width_mask(unsigned width)
{
	switch (width) {
	case X86_WIDTH_8: return 0xffULL;
	case X86_WIDTH_16: return 0xffffULL;
	case X86_WIDTH_32: return 0xffffffffULL;
	default: return ~0ULL;
	}
}

/* Independent one-bit-at-a-time population count. */
static __u64 popcount_oracle(__u64 value)
{
	__u64 n = 0U;
	unsigned i;

	for (i = 0U; i < 64U; i++)
		n += (value >> i) & 1ULL;
	return n;
}

/* The partial-register writeback the arm's `X86_SIM_L_WRITE_REG_WIDTH`
 * performs: sub-64-bit writes merge into the low bits, except the 32-bit
 * write, which zero-extends and therefore clears the upper 32 bits. */
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

/* Restate the routed `POPCNT` arm's whole effect. */
static void model_popcnt(unsigned dst, unsigned src, unsigned flags)
{
	unsigned w = resolve_width(flags);
	__u64 srcv = mreg[src];
	__u64 narrowed = srcv & width_mask(w);
	__u64 result = popcount_oracle(narrowed);

	/* CF/SF/OF cleared; ZF from the narrowed source being zero. */
	mcf = 0U;
	mzf = narrowed == 0U ? 1U : 0U;
	msf = 0U;
	mof = 0U;

	mreg[dst] = model_partial_write(mreg[dst], result, w);
	mtag[dst] = X86_SIM_TAG_SCALAR;
}

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

#define COMPARE_ALL()                                                      \
	do {                                                               \
		unsigned __ca_i;                                          \
		for (__ca_i = 0; __ca_i < 16U; __ca_i++) {                \
			__u64 __ca_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__ca_i); \
			__u8 __ca_tag = X86_SIM_L_REG_TAG(__ca_i);        \
			cases++;                                          \
			if (__ca_got != mreg[__ca_i]) {                   \
				printf("MISMATCH reg%u: got 0x%llx want "  \
				       "0x%llx\n", (unsigned)__ca_i,       \
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH reg%u tag: got %u want "  \
				       "%u\n", (unsigned)__ca_i, __ca_tag, \
				       mtag[__ca_i]);                     \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

static void check_popcnt(unsigned dst, unsigned src, unsigned flags,
			 __u64 srcv)
{
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	PLANT_REGS();
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)srcv, pattern_tag(src));
	mreg[src] = srcv;

	/* A nonzero starting flag state, so a cleared flag is a real transition
	 * and not a coincidence of the initial state. */
	__x86_cf = 1U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;
	mcf = 1U;
	mzf = 1U;
	msf = 1U;
	mof = 1U;

	/* ---- independent model ---- */
	model_popcnt(dst, src, flags);

	/* ---- run the real routed arm ---- */
	X86_SIM_L_EXEC(X86_OP_POPCNT, dst, src, flags, 0U, 0U);

	COMPARE_ALL();

	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH flags flags=%u src=%u srcv=0x%llx: "
		       "got %u/%u/%u/%u want %u/%u/%u/%u\n",
		       flags, src, (unsigned long long)srcv,
		       __x86_cf, __x86_zf, __x86_sf, __x86_of,
		       mcf, mzf, msf, mof);
		failures++;
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Sources spanning zero, all-ones, single-bit, byte/word boundaries,
	 * and values whose low byte is zero but upper bytes are set. */
	static const __u64 src_values[12] = {
		0ULL, ~0ULL, 1ULL, 0x2ULL, 0xf0ULL, 0x8000000000000000ULL,
		0x00000000ffffffffULL, 0xffffff0000000000ULL,
		0x0000000000000100ULL, 0x0000000000000101ULL,
		0x5555555555555555ULL, 0x0123456789abcdefULL,
	};
	static const unsigned pairs[3][2] = {
		{ X86_RCX, X86_RBX }, { X86_RDX, X86_RSI },
		{ X86_R8, X86_R9 },
	};
	unsigned f;
	unsigned sv;
	unsigned p;

	for (f = 0; f < 5U; f++)
		for (sv = 0; sv < 12U; sv++)
			for (p = 0; p < 3U; p++)
				check_popcnt(pairs[p][0], pairs[p][1],
					     flags_codes[f], src_values[sv]);

	if (failures != 0) {
		printf("x86 popcnt flags route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 popcnt flags route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
