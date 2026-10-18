/*
 * Host cross-check for the x86 simulator's dispatch routing of the two MOV
 * singleton opcodes (STEP 0160).
 *
 * The simulator's dispatcher must route `X86_OP_MOV_IMM` (0x01) into the
 * `X86_SIM_L_EXEC_MOV_IMM_AUX` immediate lane write and `X86_OP_MOV_REG` (0x02)
 * into the `X86_SIM_L_EXEC_MOV_REG_AUX` arm-selecting body:
 *
 *   - the immediate arm rewrites the destination through the width-local
 *     partial-register write at the RAW encoded immediate (no sign extension,
 *     no truncation, no flag byte) with the AUX destination lane; the
 *     narrower-width byte form selects the `KPROG_X86_REG_LANE_AUX_DST_SHIFT`
 *     byte lane (zero writes AL, eight writes AH), word writes the low half,
 *     dword zero-extends, qword replaces the lane; every NARROW writeback
 *     scalarizes the tag, and the narrower scalarize out of a pointer-tagged
 *     destination is the pin for the pointer-erase bug class;
 *   - the register arm selects one of three bodies through the generated
 *     `KPROG_X86_MOV_REG_ARM` selector: at the resolved 64-bit width the stack
 *     pointer as source rebinds the destination through the stack arena
 *     (`X86_SIM_L_STACK_PTR` over `KPROG_X86_STACK_INDEX`'s 32-bit window
 *     wrap) with the `X86_SIM_TAG_STACK` tag, any other present source is a
 *     whole-cell provenance copy (value and tag), and at every narrower
 *     resolved width the destination lane is written from the source's decoded
 *     lane cell (byte lanes shift only at the byte width; word reads the low
 *     half), scalarizing the tag;
 *   - MOV writes no flag byte and touches no memory in either opcode.
 *
 * The case algebra: the immediate arm drives 4 destinations x 5 FLAGS width
 * codes (the absent code plus the four real codes) x 4 raw immediate
 * artifacts x 2 AUX lane words (the plain zero word through the real
 * dispatcher arm, which carries the AUX word straight through, and the
 * high-byte lane word through the AUX entry) = 160 cases; the register arm
 * drives 6 source/destination pairs (including `rsp` as destination, as
 * source, and as both) x 5 width codes x 4 source values x 2 destination
 * values both through the AUX entry at the high-byte lane word and through
 * the real dispatcher arm at the plain zero word = 240 + 240 cases; each
 * case compares 16 register values + 16 tags + the flag row + the stack-
 * arena image row = 34 rows, so 21,760 rows plus the four selector rows
 * (the two opcode codes, the arm count, and the three-arm selector) =
 * 21,764 rows in `make check`.
 *
 * Exit 1 on mismatch.
 *
 * Build (host, no BPF):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_mov_route_host.c -o build/test_x86_mov_route_host \
 *      && ./build/test_x86_mov_route_host
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

/* An arena base the pointer reads may name; the stack rebind indexes the
 * modeled `__x86_stack_mem` array directly, so the model needs no copy. */
#define MAPPED_BASE 0x00005a0000000000ULL
#define MAPPED_BASE_TAG X86_SIM_TAG_MAP_VALUE

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

/* The lane-aux shifts the narrow arms decode: the destination lane from bits
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

/* The partial-register writeback the width arms perform: byte writes the
 * selected byte lane (so it preserves the other lane), word the low half,
 * dword zero-extends, qword replaces whole. */
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

/* Replant two lanes' values over the pattern plant (the value-pair probe):
 * a row variable keeps the model mirrors on loop-provable indices, which
 * keeps gcc's store-range warnings out of the giant dispatcher expansion. */
#define REPLANT_LANES(DST, DSTV, SRC, SRCV)                                \
	do {                                                               \
		unsigned __rl_i;                                          \
		for (__rl_i = 0; __rl_i < 16U; __rl_i++) {                \
			__u64 __rl_value = pattern_reg(__rl_i);             \
			__u8 __rl_tag = pattern_tag(__rl_i);                \
			if (__rl_i == (DST)) {                        \
				__rl_value = (DSTV);                  \
			}                                                 \
			if (__rl_i == (SRC)) {                        \
				__rl_value = (SRCV);                  \
			}                                                 \
			X86_SIM_L_WRITE_REG_PTR_TAG(__rl_i,       \
				(void *)(long)__rl_value,             \
				__rl_tag);                            \
			mreg[__rl_i] = __rl_value;                    \
			mtag[__rl_i] = __rl_tag;                      \
		}                                                         \
	} while (0)

/* MOV defines no flags, so a nonzero mixed starting state must survive. */
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

/* No MOV arm writes memory: the stack-arena image must come back exactly as
 * planted. */
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

#define SRC_REG X86_RCX
#define RSP_PLANT ((void *)(long)-64LL)

/* The stack-base index the sim's `X86_SIM_L_STACK_PTR` materializes from a
 * planted pointer: the generated `KPROG_X86_STACK_INDEX` 32-bit window wrap
 * over the arena capacity. The model indexes the modeled stack object with
 * it, so a pointer-valued output compares equal to the run. Declared inside
 * each checker's scope through the macro so `__x86_stack_mem` is visible. */
#define MODEL_STACK_PTR(V)                                                 \
	(__u64)(unsigned long)&__x86_stack_mem.b[                          \
		(__u32)((__s64)(long)(V) + (__s64)X86_SIM_STACK_BYTES)]

/* One immediate-arm case: plant, drive the routed body (through the real
 * dispatcher when the AUX word is plain zero, because that is the only word
 * an encoder route may hand the singleton), and compare the whole state. */
static void check_mov_imm(unsigned dst, unsigned flags, unsigned aux,
			  __u64 imm)
{
	DECLARE_SIM_STATE();
	unsigned w;

	route_ctx = "mov imm";
	memcpy(exp_stack, __x86_stack_mem.b, sizeof(exp_stack));
	PLANT_REGS();
	STAGE_FLAGS();

	/* ---- independent model ---- */
	w = resolve_width(flags);
	/* The raw encoded immediate through the width-local writeback; the
	 * model reads its own planted file (MEM-free), so no snapshot dance
	 * is needed before the run. */
	mreg[dst] = model_partial_write(mreg[dst], imm, w,
					aux_dst_shift(aux));
	mtag[dst] = X86_SIM_TAG_SCALAR;

	/* ---- the real routed arm ---- */
	if (aux == 0U)
		X86_SIM_L_EXEC(X86_OP_MOV_IMM, dst, 0U, flags, aux, imm);
	else
		X86_SIM_L_EXEC_MOV_IMM_AUX(dst, flags, aux, imm);

	COMPARE_ALL();
	COMPARE_MEMORY();
}

/* One register-arm case. The routed selector must agree with the generated
 * contract at the driven widths; the model restates the three arms from the
 * raw values, not from the selector's own macros. */
static void check_mov_reg(unsigned dst, unsigned src, unsigned flags,
			  unsigned aux, __u64 srcv, __u64 dstv)
{
	DECLARE_SIM_STATE();
	unsigned w;

	route_ctx = "mov reg";
	memcpy(exp_stack, __x86_stack_mem.b, sizeof(exp_stack));
	PLANT_REGS();
	REPLANT_LANES(dst, dstv, src, srcv);
	STAGE_FLAGS();

	/* ---- independent model ---- */
	w = resolve_width(flags);
	if (w == X86_WIDTH_64) {
		if (src == X86_RSP) {
			/* The stack-base write: the arena address at the
			 * window-wrapped source offset, tagged stack
			 * provenance. */
			mreg[dst] = MODEL_STACK_PTR(srcv);
			mtag[dst] = X86_SIM_TAG_STACK;
		} else {
			/* The provenance copy: the whole cell (value and
			 * tag) moves. */
			mreg[dst] = srcv;
			mtag[dst] = X86_SIM_L_REG_TAG(src);
		}
	} else {
		/* The narrow write reads the whole source first, then writes
		 * the partial destination, so when `dst` and `src` coincide
		 * the destination's prior value is whatever the source plant
		 * left in the model. */
		__u64 value = model_read_reg_at(srcv, w, aux_src_shift(aux));

		mreg[dst] = model_partial_write(mreg[dst], value, w,
						aux_dst_shift(aux));
		mtag[dst] = X86_SIM_TAG_SCALAR;
	}

	/* ---- the real routed arm ---- */
	if (aux == 0U)
		X86_SIM_L_EXEC(X86_OP_MOV_REG, dst, src, flags, aux, 0U);
	else
		X86_SIM_L_EXEC_MOV_REG_AUX(dst, src, flags, aux);

	COMPARE_ALL();
	COMPARE_MEMORY();
}

/* The routing pins: the two opcode codes name the dispatcher's two MOV
 * singleton arms, and the register arm's generated selector resolves to the
 * three generated bodies at the driven width/source pairs. */
static void check_selectors(void)
{
	cases++;
	if (X86_OP_MOV_IMM != 0x01U) {
		printf("MISMATCH x86 mov imm opcode code drift\n");
		failures++;
	}

	cases++;
	if (X86_OP_MOV_REG != 0x02U) {
		printf("MISMATCH x86 mov reg opcode code drift\n");
		failures++;
	}

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

static unsigned lane_aux[2];
static void init_lane_aux(void)
{
	lane_aux[0] = 0U;
	lane_aux[1] = KPROG_X86_REG_LANE_AUX(0U, 8U, 8U);
}

int main(void)
{
	static const unsigned dst_regs[4] = {
		X86_RAX, X86_R15, X86_RSP, X86_RDI,
	};
	/* FLAGS width codes: the absent-code fallback plus each real width. */
	static const unsigned flag_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Raw encoded immediates: zero, the negative displacement, a mixed
	 * word, and a byte artifact with a high set bit. */
	static const __u64 imm_artifacts[4] = {
		0x0000000000000000ULL, 0xffffffffffffffe8ULL,
		0x1122334455667788ULL, 0x0000000000000080ULL,
	};
	/* Register pairs, including `rsp` as source, as destination, and as
	 * both. */
	static const unsigned pairs[6][2] = {
		{ X86_RAX, X86_RBX }, { X86_RCX, X86_RDX }, { X86_R8, X86_R9 },
		{ X86_RAX, X86_RSP }, { X86_RSP, X86_RBX }, { X86_RSP, X86_RSP },
	};
	/* Sources: the zero, the mapped pointer pattern, a value whose byte
	 * lanes differ, and a value whose byte 1 is set (the high-lane probe).
	 */
	static const __u64 src_values[4] = {
		0x0000000000000007ULL, MAPPED_BASE,
		0x000000000000aa00ULL, 0x00007f00000000ffULL,
	};
	static const __u64 dst_values[2] = {
		0xdeadbeefdeadbeefULL, 0x1122334455667788ULL,
	};
	unsigned d;
	unsigned f;
	unsigned a;
	unsigned p;
	unsigned sv;
	unsigned dv;

	check_selectors();
	init_lane_aux();

	for (d = 0; d < 4U; d++)
		for (f = 0; f < 5U; f++)
			for (a = 0; a < 2U; a++)
				for (sv = 0; sv < 4U; sv++)
					check_mov_imm(dst_regs[d],
						      flag_codes[f],
						      lane_aux[a],
						      imm_artifacts[sv]);

	for (p = 0; p < 6U; p++)
		for (f = 0; f < 5U; f++)
			for (a = 0; a < 2U; a++)
				for (sv = 0; sv < 4U; sv++)
					for (dv = 0; dv < 2U; dv++)
						check_mov_reg(
							pairs[p][0],
							pairs[p][1],
							flag_codes[f],
							lane_aux[a],
							src_values[sv],
							dst_values[dv]);

	if (failures != 0) {
		printf("x86 mov route host cross-check: FAIL "
		       "(%d failures)\n", failures);
		return 1;
	}
	printf("x86 mov route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
