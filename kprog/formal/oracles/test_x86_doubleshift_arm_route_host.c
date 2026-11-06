/*
 * Host cross-check for the x86 simulator's routing of the `SHLD`/`SHRD`
 * immediate arm (STEP 0116).
 *
 * The routed arm is the `X86_OP_SHLD_IMM || X86_OP_SHRD_IMM` branch of
 * `X86_SIM_L_EXEC`, which now selects its body and its flag family through the
 * generated `KPROG_X86_DOUBLESHIFT_ARM` / `.._FLAGS` contract: the
 * `X86_OP_SHLD_IMM` opcode computes the left double shift `x86_shld` and
 * reports the `X86_ALU_SHL` family; the `X86_OP_SHRD_IMM` opcode computes the
 * right double shift `x86_shrd` and reports the `X86_ALU_SHR` family. Both sit
 * behind the count-zero step gate: when the hardware-masked count is zero the
 * arm computes no result, writes no register, and leaves every flag untouched.
 * This oracle drives the real `X86_SIM_L_EXEC` body and restates the double
 * shift bit by bit from the doubled word (never the macro's OR-of-two-shifts),
 * a second independent restatement of the shift flags, and the partial-register
 * writeback; the two must agree on the value *and* tag of every one of the 16
 * cells and on all four flags, including the count-zero no-op path. It also
 * checks that the routed selector and the generated contract agree. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf test_x86_doubleshift_arm_route_host.c -o /tmp/t_ds_arm_route
 *   /tmp/t_ds_arm_route
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
	return width == X86_WIDTH_8 ? 8U :
	       width == X86_WIDTH_16 ? 16U :
	       width == X86_WIDTH_32 ? 32U : 64U;
}

static __u64 width_mask(unsigned width)
{
	return width == X86_WIDTH_8 ? 0xffULL :
	       width == X86_WIDTH_16 ? 0xffffULL :
	       width == X86_WIDTH_32 ? 0xffffffffULL :
	       0xffffffffffffffffULL;
}

/* The hardware-masked count the step gate and the shift-flag contract share. */
static unsigned shift_count(__u64 imm, unsigned width)
{
	return (unsigned)(imm & (width == X86_WIDTH_64 ? 63ULL : 31ULL));
}

/* The partial-register writeback the arm's `X86_SIM_L_WRITE_REG_WIDTH`
 * performs. */
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

/* Independent SHLD: high b bits of (dst:src) shifted left by k. */
static __u64 shld_oracle(__u64 dst, __u64 src, unsigned k, unsigned bits)
{
	unsigned __int128 msk = bits == 64 ? ~(unsigned __int128)0
		: (((unsigned __int128)1 << bits) - 1);
	unsigned __int128 w = (((unsigned __int128)(dst & (__u64)msk)) << bits)
		| (src & (__u64)msk);

	if (k >= bits)
		return (__u64)(((unsigned __int128)(src & (__u64)msk) << (k - bits))
			& msk);
	return (__u64)((w << k) >> bits) & (__u64)msk;
}

/* Independent SHRD: low b bits of (src:dst) shifted right by k. */
static __u64 shrd_oracle(__u64 dst, __u64 src, unsigned k, unsigned bits)
{
	unsigned __int128 msk = bits == 64 ? ~(unsigned __int128)0
		: (((unsigned __int128)1 << bits) - 1);
	unsigned __int128 w = (((unsigned __int128)(src & (__u64)msk)) << bits)
		| (dst & (__u64)msk);

	return (__u64)(w >> k) & (__u64)msk;
}

/* Independent restatement of the shift-flag contract for the two families the
 * arm can report: the SHL family takes the left-count carry path, the SHR
 * family the right-count path. A count of zero leaves the flags as they were,
 * and the OF update exists only for a count of one, so OF is preserved
 * otherwise. */
static void model_shift_flags(unsigned alu, __u64 a, unsigned count, __u64 r,
			      unsigned bits, __u64 sign)
{
	if (count == 0)
		return;
	mzf = (r == 0);
	msf = (r & sign) != 0;
	if (alu == 5U) { /* X86_ALU_SHL */
		mcf = count <= bits ? (unsigned)((a >> (bits - count)) & 1U) : 0U;
		if (count == 1)
			mof = (__u8)(msf ^ mcf);
	} else if (alu == 6U) { /* X86_ALU_SHR */
		mcf = count <= bits ? (unsigned)((a >> (count - 1)) & 1U) : 0U;
		if (count == 1)
			mof = (__u8)((a & sign) != 0);
	}
}

/* Restate the routed arm's whole effect. */
static void model_doubleshift(unsigned op, unsigned dst, unsigned src,
			      unsigned flags, __u64 imm)
{
	unsigned w = resolve_width(flags);
	unsigned bits = width_bits(w);
	__u64 mask = width_mask(w);
	__u64 sign = 1ULL << (bits - 1U);
	unsigned count = shift_count(imm, w);
	__u64 dstv = mreg[dst];
	__u64 srcv = mreg[src];
	__u64 result;

	if (count == 0)
		return;

	if (op == X86_OP_SHLD_IMM)
		result = shld_oracle(dstv, srcv, count, bits);
	else
		result = shrd_oracle(dstv, srcv, count, bits);

	model_shift_flags(op == X86_OP_SHLD_IMM ? 5U : 6U, dstv & mask, count,
			  result & mask, bits, sign);

	mreg[dst] = model_partial_write(dstv, result, w);
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

static void check_doubleshift(unsigned op, unsigned dst, unsigned src,
			      unsigned flags, __u64 imm, __u64 dstv, __u64 srcv)
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
	X86_SIM_L_WRITE_REG_PTR_TAG(dst, (void *)(long)dstv, pattern_tag(dst));
	mreg[dst] = dstv;
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)srcv, pattern_tag(src));
	mreg[src] = srcv;

	/* A nonzero starting flag state, so a preserved flag is observable. */
	__x86_cf = 0U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;
	mcf = 0U;
	mzf = 1U;
	msf = 1U;
	mof = 1U;

	/* ---- independent model ---- */
	model_doubleshift(op, dst, src, flags, imm);

	/* ---- run the real routed arm ---- */
	X86_SIM_L_EXEC(op, dst, src, flags, 0U, imm);

	COMPARE_ALL();

	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH flags op=%u flags=%u imm=%llu dst=%u src=%u: "
		       "got %u/%u/%u/%u want %u/%u/%u/%u\n",
		       op, flags, (unsigned long long)imm, dst, src,
		       __x86_cf, __x86_zf, __x86_sf, __x86_of,
		       mcf, mzf, msf, mof);
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_DOUBLESHIFT_ARM_COUNT != 2U) {
		printf("MISMATCH doubleshift arm contract constant drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_DOUBLESHIFT_ARM(X86_OP_SHLD_IMM) !=
		    KPROG_X86_DOUBLESHIFT_ARM_SHLD ||
	    KPROG_X86_DOUBLESHIFT_ARM(X86_OP_SHRD_IMM) !=
		    KPROG_X86_DOUBLESHIFT_ARM_SHRD) {
		printf("MISMATCH doubleshift arm selector drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_DOUBLESHIFT_ARM_FLAGS(X86_OP_SHLD_IMM) != X86_ALU_SHL ||
	    KPROG_X86_DOUBLESHIFT_ARM_FLAGS(X86_OP_SHRD_IMM) != X86_ALU_SHR) {
		printf("MISMATCH doubleshift flag selector drift\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned opcodes[2] = { X86_OP_SHLD_IMM, X86_OP_SHRD_IMM };
	static const unsigned flags_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Immediates spanning the zero count, the count-of-one flag update, the
	 * width boundary, and counts that mask to zero for a narrow width. */
	static const __u64 immediates[11] = {
		0ULL, 1ULL, 2ULL, 7ULL, 8ULL, 15ULL, 16ULL, 31ULL, 32ULL,
		63ULL, 0xffULL,
	};
	static const __u64 dst_values[6] = {
		0ULL, ~0ULL, 0x0123456789abcdefULL, 0xf0ULL, 0x0fULL,
		0x8000000000000000ULL,
	};
	static const __u64 src_values[5] = {
		0ULL, ~0ULL, 0xf0f0f0f0f0f0f0f0ULL, 0x0f0f0f0f0f0f0f0fULL,
		0xff00ff00ff00ff00ULL,
	};
	static const unsigned pairs[3][2] = {
		{ X86_RCX, X86_RBX }, { X86_RDX, X86_RSI },
		{ X86_R8, X86_R9 },
	};
	unsigned o;
	unsigned f;
	unsigned i;
	unsigned dv;
	unsigned sv;
	unsigned p;

	check_selectors();

	for (o = 0; o < 2U; o++)
		for (f = 0; f < 5U; f++)
			for (i = 0; i < 11U; i++)
				for (dv = 0; dv < 6U; dv++)
					for (sv = 0; sv < 5U; sv++)
						for (p = 0; p < 3U; p++)
							check_doubleshift(
								opcodes[o],
								pairs[p][0],
								pairs[p][1],
								flags_codes[f],
								immediates[i],
								dst_values[dv],
								src_values[sv]);

	if (failures != 0) {
		printf("x86 doubleshift arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 doubleshift arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
