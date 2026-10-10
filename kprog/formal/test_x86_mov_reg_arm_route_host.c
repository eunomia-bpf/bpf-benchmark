/*
 * Host cross-check for the x86 simulator's routing of the `MOV_REG` three-way
 * arm-selection contract (STEP 0119).
 *
 * The simulator's `X86_OP_MOV_REG` arm (and the shared
 * `X86_SIM_L_EXEC_MOV_REG_AUX` body) must now select *which body* moves the
 * source through the generated `KPROG_X86_MOV_REG_ARM` two-fact selector: at the
 * full 64-bit width code the source register being the stack pointer selects the
 * stack-base write (the abstract frame base plus the source value, tagged stack
 * provenance); any other source at the full width selects the
 * provenance-preserving pointer copy; at every narrower width the narrow
 * scalarizing write, whatever the source register.
 *
 * This oracle restates the whole routed effect independently — the stack-base
 * address computed from the modeled `__x86_stack_mem` array, the pointer copy,
 * and the partial-register writeback — and compares the entire register file
 * (value and tag) after driving the real `X86_SIM_L_EXEC` over five flag width
 * codes (including the absent-code fallback), register pairs including `rsp` as
 * source and destination, several AUX byte lanes, and source values. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_mov_reg_arm_route_host.c -o /tmp/t_mov_reg_arm_route
 *   /tmp/t_mov_reg_arm_route
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

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The destination width the arm resolves from FLAGS, exactly as
 * `X86_SIM_L_EFFECTIVE_WIDTH` does: the absent code 0 falls back to 64. */
static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

/* The lane-aux shifts the narrow arm decodes: the destination lane from bits
 * 8..15 and the source lane from bits 16..23 of the AUX word. */
static unsigned aux_dst_shift(unsigned aux)
{
	return (aux >> 8) & 0xffU;
}

static unsigned aux_src_shift(unsigned aux)
{
	return (aux >> 16) & 0xffU;
}

/* The partial-register source read at the resolved width and byte lane: the
 * low `width` bits of the selected byte lane. An 8-bit read is the only width
 * that a byte lane shifts (the sim's `KPROG_X86_READ_REG_AT`). */
static __u64 model_read_reg_at(__u64 v, unsigned width, unsigned src_shift)
{
	unsigned shift = width == X86_WIDTH_8 ? src_shift : 0U;
	__u64 shifted = shift ? (v >> shift) : v;

	return width == X86_WIDTH_8 ? (shifted & 0xffULL) :
	       width == X86_WIDTH_16 ? (shifted & 0xffffULL) :
	       width == X86_WIDTH_32 ? (shifted & 0xffffffffULL) : shifted;
}

/* The partial-register writeback the arm's `X86_SIM_L_WRITE_REG_WIDTH_SHIFT`
 * performs: 8-bit writes the selected byte lane, 16-bit the low half, 32-bit
 * zero-extends, 64-bit replaces whole. */
static __u64 model_partial_write(__u64 old, __u64 v, unsigned width,
				 unsigned dst_shift)
{
	if (width == X86_WIDTH_8) {
		if (dst_shift == 8U)
			return (old & ~0xff00ULL) | ((v & 0xffULL) << 8);
		return (old & ~0xffULL) | (v & 0xffULL);
	}
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (v & 0xffffULL);
	if (width == X86_WIDTH_32)
		return v & 0xffffffffULL;
	return v;
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

static void check_mov_reg(unsigned dst, unsigned src, unsigned flags,
			  unsigned aux, __u64 dstv, __u64 srcv)
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
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = (__u8)(0xa0U + i);

	PLANT_REGS();
	X86_SIM_L_WRITE_REG_PTR_TAG(dst, (void *)(long)dstv, pattern_tag(dst));
	mreg[dst] = dstv;
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)srcv, pattern_tag(src));
	mreg[src] = srcv;

	/* MOV defines no flags, so a nonzero starting state must survive. */
	__x86_cf = 0U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;

	/* ---- independent model ---- */
	{
		unsigned w = resolve_width(flags);

		if (w == X86_WIDTH_64) {
			if (src == X86_RSP) {
				/* The stack-base write: the address of the
				 * modeled stack cell at the capacity-shifted
				 * source offset, tagged stack provenance. */
				__u32 idx = (__u32)((__s64)(long)srcv +
						    (__s64)X86_SIM_STACK_BYTES);
				mreg[dst] = (__u64)(unsigned long)
					&__x86_stack_mem.b[idx];
				mtag[dst] = X86_SIM_TAG_STACK;
			} else {
				mreg[dst] = srcv;
				mtag[dst] = pattern_tag(src);
			}
		} else {
			/* The narrow write reads the whole source first, then
			 * writes the partial destination, so when `dst` and
			 * `src` coincide the destination's prior value is
			 * whatever the source plant left in the model. */
			__u64 value = model_read_reg_at(
				srcv, w, aux_src_shift(aux));

			mreg[dst] = model_partial_write(
				mreg[dst], value, w, aux_dst_shift(aux));
			mtag[dst] = X86_SIM_TAG_SCALAR;
		}
	}

	/* ---- run the real routed arm ---- */
	X86_SIM_L_EXEC(X86_OP_MOV_REG, dst, src, flags, aux, 0U);

	COMPARE_ALL();

	cases++;
	if (__x86_cf != 0U || __x86_zf != 1U || __x86_sf != 1U || __x86_of != 1U) {
		printf("MISMATCH flags width=%u: got %u/%u/%u/%u want 0/1/1/1\n",
		       flags, __x86_cf, __x86_zf, __x86_sf, __x86_of);
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_MOV_REG_ARM_COUNT != 3U) {
		printf("MISMATCH mov_reg arm contract count drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_MOV_REG_ARM(X86_WIDTH_64, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_STACK_PTR ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_64, X86_RAX) !=
		    KPROG_X86_MOV_REG_ARM_POINTER ||
	    KPROG_X86_MOV_REG_ARM(X86_WIDTH_32, X86_RSP) !=
		    KPROG_X86_MOV_REG_ARM_NARROW) {
		printf("MISMATCH mov_reg arm selector drift\n");
		failures++;
	}
}

int main(void)
{
	/* FLAGS width codes: the absent-code fallback plus each real width. */
	static const unsigned flag_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* AUX byte-lane words: the low/low pair plus a non-trivial source lane
	 * and a high destination lane, so the lane decode is exercised. */
	static const unsigned aux_codes[4] = {
		0U,
		KPROG_X86_REG_LANE_AUX(0U, 0U, 0U),
		KPROG_X86_REG_LANE_AUX(0U, 8U, 8U),
		KPROG_X86_REG_LANE_AUX(0U, 0U, 8U),
	};
	/* Register pairs, including `rsp` as source and as destination. */
	static const unsigned pairs[6][2] = {
		{ X86_RAX, X86_RBX }, { X86_RCX, X86_RDX }, { X86_R8, X86_R9 },
		{ X86_RAX, X86_RSP }, { X86_RSP, X86_RBX }, { X86_RSP, X86_RSP },
	};
	static const __u64 src_values[5] = {
		0ULL, ~0ULL, 0x11223344556688ffULL, 0xffffffffffffaa88ULL,
		0x0000000000000080ULL,
	};
	static const __u64 dst_values[4] = {
		0ULL, ~0ULL, 0xdeadbeefdeadbeefULL, 0x1122334455667788ULL,
	};
	unsigned f;
	unsigned a;
	unsigned p;
	unsigned sv;
	unsigned dv;

	check_selectors();

	for (f = 0; f < 5U; f++)
		for (a = 0; a < 4U; a++)
			for (p = 0; p < 6U; p++)
				for (sv = 0; sv < 5U; sv++)
					for (dv = 0; dv < 4U; dv++)
						check_mov_reg(pairs[p][0],
							      pairs[p][1],
							      flag_codes[f],
							      aux_codes[a],
							      dst_values[dv],
							      src_values[sv]);

	if (failures != 0) {
		printf("x86 mov_reg arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 mov_reg arm route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
