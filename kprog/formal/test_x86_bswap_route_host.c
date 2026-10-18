/*
 * Host cross-check for the x86 simulator's dispatch routing of the BSWAP
 * singleton opcode (STEP 0161).
 *
 * The simulator's dispatcher must route `X86_OP_BSWAP` (0x17) into the sole
 * inline byte-swap arm body, the only `X86_SIM_L_EXEC` arm whose value
 * computation stays inline in the dispatcher itself:
 *
 *   - the arm reads its destination whole at the 64-bit raw width through
 *     `X86_SIM_L_READ_REG` and reverses its byte order at the
 *     FLAGS-resolved effective width, zero-filling (clearing) the bytes
 *     above it -- the width decode is the arm's only real selection, so a
 *     body that forces the byte code, the word code, or the dword code
 *     folds byte lanes the real body would keep or fill;
 *   - the arm writes the swapped value back through the width-local
 *     partial-register write (`X86_SIM_L_WRITE_REG_WIDTH`): byte writes
 *     the low byte lane, word the low half, dword zero-extends, qword
 *     replaces the whole cell, and every narrowed writeback scalarizes
 *     the provenance tag;
 *   - BSWAP defines no flags, touches no memory, and ignores SRC, the
 *     AUX word, and the immediate entirely.
 *
 * The case algebra: 4 destinations (including the stack pointer, whose
 * planted signed-offset value the model must track like any other cell)
 * x 5 FLAGS width codes (the absent code plus the four real codes) x 5
 * source values (a byte-lane-swapping showcase, a mapped-pointer base a
 * body must NOT dereference, a low-byte-only probe, a high-byte probe,
 * and the pattern scalar) x 2 AUX words (plain zero -- the word a real
 * dispatcher route hands the singleton -- and the meaningful
 * high-byte lane word the arm must ignore) = 200 routed cases; each
 * case compares 16 register values + 16 tags + the flag row + the
 * stack-arena image row = 34 rows, so 6,800 rows plus the two selector
 * rows (the opcode code and the byte-gate non-member pin) = 6,802 rows
 * in `make check`.
 *
 * Exit 1 on mismatch.
 *
 * Build (host, no BPF):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_bswap_route_host.c -o build/test_x86_bswap_route_host \
 *      && ./build/test_x86_bswap_route_host
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

#include <string.h>

static int failures;
static unsigned long cases;

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[16];
static __u8 mtag[16];
static __u8 mcf, mzf, msf, mof;

/* The stack arena image a case must leave untouched. */
static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* An arena base the pointer reads may name; the body must read the raw
 * register bits only, so a body that dereferences the mapped pointer lands
 * on different byte content than the model's raw-bit reversal. */
#define MAPPED_BASE 0x00005a0000000000ULL
#define MAPPED_BASE_TAG X86_SIM_TAG_MAP_VALUE

#define SRC_REG X86_RCX
#define RSP_PLANT ((void *)(long)-64LL)

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The destination width the body resolves from FLAGS, exactly as
 * `X86_SIM_L_EFFECTIVE_WIDTH` does: the absent code 0 falls back to 64. */
static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

/* The whole-cell read the arm performs: `X86_SIM_L_READ_REG` resolves at
 * the 64-bit width with no lane shift, so the model sees every planted
 * bit. */
static __u64 model_read_whole(__u64 v)
{
	return v;
}

/* The byte reversal the generated `kprog_x86_bswap_value` restates from
 * raw shifts, never from the macro's own helpers: reverse the low
 * `width` bytes in place and clear every byte above. */
static __u64 model_bswap(__u64 v, unsigned width)
{
	__u64 out = 0ULL;
	unsigned i;

	if (width == X86_WIDTH_64) {
		for (i = 0; i < 8U; i++)
			out |= ((v >> (8U * i)) & 0xffULL) <<
			       (8U * (7U - i));
		return out;
	}
	if (width == X86_WIDTH_32) {
		for (i = 0; i < 4U; i++)
			out |= ((v >> (8U * i)) & 0xffULL) <<
			       (8U * (3U - i));
		return out;
	}
	if (width == X86_WIDTH_16) {
		for (i = 0; i < 2U; i++)
			out |= ((v >> (8U * i)) & 0xffULL) <<
			       (8U * (1U - i));
		return out;
	}
	return v & 0xffULL;
}

/* The partial-register writeback the width arm performs: byte writes the
 * low byte lane, word the low half, dword zero-extends, qword replaces
 * whole. BSWAP carries no AUX lane, so no byte-lane shift applies. */
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

#define DECLARE_SIM_STATE()                                                \
	X86_SIM_L_DECLARE_STATE();                                        \
	struct x86_sim_xdp_abi __x86_sim_abi = {};                        \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;       \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                     \
	(void)__x86_sim_abi;                                              \
	(void)__x86_sim_skb_ctx;                                          \
	(void)__x86_sim_abi_kind;                                         \
	X86_SIM_L_DECLARE_STACK();                                        \
	(void)__x86_xmm0_lo;                                              \
	(void)__x86_xmm0_hi;                                              \
	(void)__x86_sim_ret_addr;

/* Plant the register file: pattern values and pattern tags everywhere, with
 * two lanes forced -- the mapped-pointer lane under its mapped tag and the
 * stack lane the signed offset under the scalar tag (the arena rebase treats
 * the raw pointer bits as the window offset). Expands inside a checker that
 * has declared the simulated register file. */
#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_value = pattern_reg(__pl_i);             \
			__u8 __pl_tag = pattern_tag(__pl_i);                \
			if (__pl_i == SRC_REG) {                      \
				__pl_value = MAPPED_BASE;               \
				__pl_tag = MAPPED_BASE_TAG;             \
			}                                                 \
			if (__pl_i == X86_RSP) {                          \
				__pl_value = (__u64)RSP_PLANT;            \
				__pl_tag = X86_SIM_TAG_SCALAR;            \
			}                                                 \
			X86_SIM_L_WRITE_REG_PTR_TAG(__pl_i,           \
				(void *)(long)__pl_value,             \
				__pl_tag);                            \
			mreg[__pl_i] = __pl_value;                    \
			mtag[__pl_i] = __pl_tag;                      \
		}                                                         \
	} while (0)

/* Replant one lane's value over the pattern plant (the value-pair probe):
 * a row variable keeps the model mirrors on loop-provable indices, which
 * keeps gcc's store-range warnings out of the giant dispatcher expansion. */
#define REPLANT_LANES(DST, DSTV)                                           \
	do {                                                               \
		unsigned __rl_i;                                          \
		for (__rl_i = 0; __rl_i < 16U; __rl_i++) {                \
			__u64 __rl_value = pattern_reg(__rl_i);             \
			__u8 __rl_tag = pattern_tag(__rl_i);                \
			if (__rl_i == (DST)) {                        \
				__rl_value = (DSTV);                  \
			}                                                 \
			X86_SIM_L_WRITE_REG_PTR_TAG(__rl_i,       \
				(void *)(long)__rl_value,             \
				__rl_tag);                            \
			mreg[__rl_i] = __rl_value;                    \
			mtag[__rl_i] = __rl_tag;                      \
		}                                                         \
	} while (0)

/* BSWAP defines no flags, so a nonzero mixed starting state must survive. */
#define STAGE_FLAGS()                                                      \
	do {                                                               \
		__x86_cf = 0U;                                        \
		__x86_zf = 1U;                                        \
		__x86_sf = 1U;                                        \
		__x86_of = 1U;                                        \
		mcf = 0U;                                              \
		mzf = 1U;                                              \
		msf = 1U;                                              \
		mof = 1U;                                              \
	} while (0)

static const char *route_ctx;

#define COMPARE_ALL()                                                      \
	do {                                                               \
		unsigned __ca_i;                                          \
		for (__ca_i = 0; __ca_i < 16U; __ca_i++) {                \
			__u64 __ca_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__ca_i); \
			__u8 __ca_tag = X86_SIM_L_REG_TAG(__ca_i);        \
			cases++;                                          \
			if (__ca_got != mreg[__ca_i]) {                   \
				printf("MISMATCH %s: reg%u: got 0x%llx "   \
				       "want 0x%llx\n", route_ctx,         \
				       (unsigned)__ca_i,                   \
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH %s: reg%u tag: got %u "   \
				       "want %u\n", route_ctx,             \
				       (unsigned)__ca_i, __ca_tag,         \
				       mtag[__ca_i]);                      \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			printf("MISMATCH %s: flags written\n",            \
			       route_ctx);                                \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* No BSWAP arm writes memory: the stack-arena image must come back exactly
 * as planted. */
#define COMPARE_MEMORY()                                                   \
	do {                                                               \
		unsigned __cm_i;                                          \
		int __cm_bad = 0;                                         \
		for (__cm_i = 0;                                          \
		     !__cm_bad && __cm_i < X86_SIM_STACK_BYTES;           \
		     __cm_i++)                                            \
			if (__x86_stack_mem.b[__cm_i] !=                   \
			    exp_stack[__cm_i]) {                           \
				__cm_bad = 1;                              \
				break;                                     \
			}                                                 \
		cases++;                                                  \
		if (__cm_bad) {                                           \
			printf("MISMATCH %s: memory image written\n",      \
			       route_ctx);                                 \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* One BSWAP case: plant, drive the routed body through the real
 * dispatcher (AUX words are handed straight through; the arm must ignore
 * them), and compare the whole state. */
static void check_bswap(unsigned dst, unsigned flags, unsigned aux,
			__u64 dstv)
{
	DECLARE_SIM_STATE();
	unsigned w;

	route_ctx = "bswap";
	memcpy(exp_stack, __x86_stack_mem.b, sizeof(exp_stack));
	PLANT_REGS();
	REPLANT_LANES(dst, dstv);
	STAGE_FLAGS();

	/* ---- independent model ---- */
	w = resolve_width(flags);
	/* The whole-cell read, the byte reversal at the resolved width, the
	 * width-local writeback, and the tag the narrowed writeback
	 * scalarizes (a qword write keeps the planted tag cell intact only
	 * by replacing the whole value under the same tagged scalar-cast --
	 * the generated write stamps the scalar tag in every arm). */
	mreg[dst] = model_partial_write(mreg[dst],
					model_bswap(model_read_whole(mreg[dst]),
						    w),
					w);
	mtag[dst] = X86_SIM_TAG_SCALAR;

	/* ---- the real routed arm ---- */
	X86_SIM_L_EXEC(X86_OP_BSWAP, dst, 0U, flags, aux, 0U);

	COMPARE_ALL();
	COMPARE_MEMORY();
}

/* The routing pins: the opcode code names the dispatcher's BSWAP singleton
 * arm and the gate accepts the BSWAP code while rejecting an unrelated
 * opcode byte. */
static void check_selectors(void)
{
	cases++;
	if (X86_OP_BSWAP != 0x17U) {
		printf("MISMATCH x86 bswap opcode code drift\n");
		failures++;
	}

	cases++;
	if (!KPROG_X86_DISP_BSWAP_HANDLED(X86_OP_BSWAP) ||
	    KPROG_X86_DISP_BSWAP_HANDLED(X86_OP_RET)) {
		printf("MISMATCH x86 bswap gate drift\n");
		failures++;
	}
}

int main(void)
{
	/* Destinations: the ABI-touching lanes plus the stack pointer,
	 * whose signed-offset cell the model tracks like any other. */
	static const unsigned dst_regs[4] = {
		X86_RAX, X86_R15, X86_RSP, X86_RDI,
	};
	/* FLAGS width codes: the absent-code fallback plus each real width. */
	static const unsigned flag_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Destination values: a byte-lane-swapping showcase, the mapped
	 * pointer (a body must read the raw bits, not dereference), a
	 * low-byte-only probe, a high-byte probe, and the pattern scalar. */
	static const __u64 dst_values[5] = {
		0x0123456789abcdefULL, MAPPED_BASE, 0x0000000000000077ULL,
		0x00007f00000000ffULL, 0x9e3779b97f4a7c15ULL,
	};
	/* AUX words: the plain zero word a real dispatcher route hands the
	 * singleton, and the meaningful high-byte lane word the arm must
	 * ignore. */
	static const unsigned aux_words[2] = { 0U,
		KPROG_X86_REG_LANE_AUX(0U, 8U, 8U) };
	unsigned d;
	unsigned f;
	unsigned v;
	unsigned a;

	check_selectors();

	for (d = 0; d < 4U; d++)
		for (f = 0; f < 5U; f++)
			for (v = 0; v < 5U; v++)
				for (a = 0; a < 2U; a++)
					check_bswap(dst_regs[d],
						    flag_codes[f], aux_words[a],
						    dst_values[v]);

	if (failures != 0) {
		printf("x86 bswap route host cross-check: FAIL "
		       "(%d failures)\n", failures);
		return 1;
	}
	printf("x86 bswap route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}


