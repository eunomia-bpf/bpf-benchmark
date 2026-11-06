/*
 * Host cross-check for the x86 simulator's routing of the two multiply
 * op-step results (STEP 0158).
 *
 * Drives the *inline* IMUL arm bodies of the routed dispatcher
 * `X86_SIM_L_EXEC` in `x86/x86_sim_local_bpf.h` -- the same bodies the
 * `X86_OP_IMUL_IMM` (0x38) and `X86_OP_IMUL_MEM_IMM` (0x41) arms execute --
 * and compares their whole effect (the sixteen register values, their tags,
 * the four flag bytes, and the heap image) against an independent model
 * restated from the raw macros and the generated contracts:
 *
 *   - the register form reads its left operand whole from the source
 *     register and takes its right operand from the sign-extension of the
 *     WHOLE immediate at the FLAGS-resolved width, so the immediate's upper
 *     half participates in the product exactly as the raw body computes it;
 *   - the memory form resolves the AUX memory-width lane (the absent code
 *     falling back to the FLAGS-resolved width), reads the left operand from
 *     the addressed bytes through the real addressed-read body (the
 *     effective displacement (s32)((u64)(s32)(IMM >> 32) >> 32) -- the
 *     routed body passes the store-half displacement through the whole-
 *     immediate slot of the addressed-read body, which extracts it again --
 *     offset), takes its right operand from the store-immediate value
 *     re-resolved through the `KPROG_X86_IMMEDIATE_VALUE` 32-bit shape, and
 *     multiplies it by the left operand SIGNED-EXTENDED AT THE MEMORY WIDTH;
 *   - the two multiply flag inputs differ: the product uses the
 *     memory-width-extended left operand, while `CF`/`OF` magnitude is taken
 *     from the RAW loaded bits narrowed to the FLAGS width, so the oracle
 *     restates that split exactly (w=32, memory width 1, the byte `0xff`,
 *     and a 2^30-shaped right operand is numerically 1 versus 0 between the
 *     two readings);
 *   - the width-domain funnel is the generated `KPROG_X86_SET_IMUL_FLAGS`
 *     division: `overflow` exactly when the left magnitude is nonzero and the
 *     right magnitude exceeds `limit / left magnitude`, with `limit` the
 *     width sign bit when the two signs differ and one below it otherwise;
 *     `CF` and `OF` both take that single bit and `ZF`/`SF` are preserved;
 *   - the writeback is the width-local partial-register write with the
 *     destination tag scalarized, and neither form writes memory, so the
 *     planted heap image must come back unchanged.
 *
 * The case algebra: the flagged form sweeps 5 width codes x 8 left operands
 * x 6 immediate artifacts x 2 incoming flag seeds = 480 cases; the memory
 * form sweeps 5 width codes x 5 AUX memory-width codes (the absent code plus
 * the four real codes) x 8 heap fill patterns x 6 immediate artifacts x 3
 * addressing modes (no index, index at scale 1, index at scale 8) x 2 flag
 * seeds = 7200 cases; 7680 cases in total, each comparing the 16 register
 * values, their 16 tags, the 4 flag bytes, and the heap image = 34 rows, so
 * 261,120 rows plus the one opcode-code selector row = 261,121 rows in
 * `make check`.
 *
 * Every case is driven through the real dispatcher arm `X86_SIM_L_EXEC` (the
 * bodies are inline in the dispatcher, so the dispatch route is the only body
 * route), with the register file, tags, flags, and heap planted before the run
 * and compared after it. Exit 1 on mismatch.
 *
 * Build (host, no BPF):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_imul_route_host.c \
 *      -o build/test_x86_imul_route_host \
 *      && ./build/test_x86_imul_route_host
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

static __u64 mreg[16];
static __u8 mtag[16];
static __u8 mcf, mzf, msf, mof;

/* The heap the memory operand addresses: the sim's byte image and the
 * model's read target, compared byte for byte after every step (the multiply
 * forms only ever read it). */
#define HEAP_BYTES 16384U
#define HEAP_ORIGIN 4096U
#define HEAP_MODEL_OFFSET 4096
static __u8 heap[HEAP_BYTES];
static __u8 exp_heap[HEAP_BYTES];

/* The memory form's base-address lane must carry a mapped pointer under the
 * scalar tag (an unmapped pattern value would fault the real body's load,
 * and an ABI tag at width 64 would route the read through the pointer
 * dereference arm instead of the little-endian load), so the plant forces it.
 * `SRC_REG` is the flagged form's left-operand lane AND the memory form's
 * base lane: the routed dispatcher consumes the same slot for both operand
 * kinds, so one define serves both forms. */
#define DST_REG X86_R9
#define SRC_REG X86_RCX
#define HEAP_REG_VALUE ((__u64)(long)(heap + HEAP_ORIGIN))
#define INDEX_REG X86_RDI
#define INDEX_VALUE 8ULL

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static unsigned resolve_width(unsigned flags)
{
	return flags ? flags : X86_WIDTH_64;
}

static __u64 width_mask(unsigned width)
{
	return width == X86_WIDTH_8 ? 0xffULL :
	       width == X86_WIDTH_16 ? 0xffffULL :
	       width == X86_WIDTH_32 ? 0xffffffffULL :
	       0xffffffffffffffffULL;
}

static __u64 width_sign(unsigned width)
{
	return width == X86_WIDTH_8 ? 0x80ULL :
	       width == X86_WIDTH_16 ? 0x8000ULL :
	       width == X86_WIDTH_32 ? 0x80000000ULL :
	       0x8000000000000000ULL;
}

/* An independent little-endian load: a byte loop over the planted image. */
static __u64 load_le(const __u8 *bytes, __s64 at, unsigned w)
{
	__u64 value = 0ULL;
	unsigned k;

	for (k = 0; k < w; k++)
		value |= (__u64)bytes[at + (__s64)k] << (8U * k);
	return value;
}

/* The independent sign extension at a resolved width code: narrow to the
 * width, then fan its sign bit across the lane. At the full-width code the
 * mask is all-ones, so the value passes through unchanged -- the same shape
 * the generated `kprog_x86_sign_extend_value` cascade has. */
static __u64 model_sign_extend(__u64 value, unsigned width)
{
	__u64 narrowed = value & width_mask(width);

	if (narrowed & width_sign(width))
		return narrowed | ~width_mask(width);
	return narrowed;
}

/* The store-immediate value: the 32-bit mask, plus the sign-extension arm at
 * the 64-bit default width. Restated from `KPROG_X86_IMMEDIATE_VALUE`. */
static __u64 model_imm_value(__u64 imm, unsigned width)
{
	if (width == X86_WIDTH_64 && (imm & 0x80000000ULL))
		return (imm & 0xffffffffULL) | 0xffffffff00000000ULL;
	return imm & 0xffffffffULL;
}

/* The width-wrapped magnitude the multiply flag funnel takes. */
static __u64 modeled_abs(__u64 value, unsigned width)
{
	__u64 narrowed = value & width_mask(width);

	if (narrowed & width_sign(width))
		return ((~narrowed) + 1) & width_mask(width);
	return narrowed;
}

/* The independent width-local partial-register write the bodies'
 * `X86_SIM_L_WRITE_REG_WIDTH` writeback performs at destination shift zero:
 * the byte code writes one byte lane, the word code writes the low word
 * preserving the upper bytes, the dword code zero-extends, and the qword code
 * writes the lane. The write also scalarizes the destination tag. */
static __u64 model_partial_write(__u64 old, __u64 value, unsigned width)
{
	unsigned w = resolve_width(width);

	if (w == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (w == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (w == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value;
}

/* ---- The routed bodies' whole effect for one op -------------------------- */

/* `form` selects the routed arm:
 *   0 = X86_OP_IMUL_IMM      (register left, whole-immediate right)
 *   1 = X86_OP_IMUL_MEM_IMM  (addressed left, store-immediate right).
 * `mode` selects the addressing of the memory form: 0 names no index register
 * (the AUX sentinel byte), 1 an index at scale 1, and 2 an index at scale 8.
 * The flag funnel is restated independently of the macro's own helpers: the
 * magnitudes come from the RAW left operand narrowed to the FLAGS width, the
 * `limit` side selects on the two signs' polarity, and the single overflow bit
 * lands on both `CF` and `OF` while `ZF`/`SF` keep their planted value. */
static void model_imul_step(unsigned form, unsigned width_code,
			    unsigned aux_mem_width, unsigned mode,
			    __u64 lhs_reg, __u64 imm)
{
	unsigned w = resolve_width(width_code);
	__u64 lhs;
	__u64 rhs;
	__u64 product;

	if (form == 0U) {
		lhs = lhs_reg;
		rhs = model_sign_extend(imm, w);
		product = lhs * rhs;
	} else {
		unsigned mw = aux_mem_width ? aux_mem_width : w;
		/* The routed body passes its pre-extracted store-half
		 * displacement through the whole-immediate slot of
		 * `X86_SIM_L_READ_MEM_VALUE(..., STORE_DISP=1)`, whose
		 * `STORE_DISP` branch applies `x86_store_imm_disp` a second
		 * time: the effective displacement is
		 * `(s32)((u64)(s32)(imm >> 32) >> 32)`, not
		 * `(s32)(imm >> 32)`. Restate that exact two-step wrap. */
		__s64 disp = (__s64)(__s32)(((__u64)(__s64)(__s32)(imm >> 32)) >> 32);
		__u64 raw;

		if (mode != 0U)
			disp += (__s64)(INDEX_VALUE << (mode == 2U ? 3U : 0U));
		raw = load_le(exp_heap, (__s64)HEAP_MODEL_OFFSET + disp, mw);
		rhs = model_sign_extend(model_imm_value(imm, w), w);
		product = model_sign_extend(raw, mw) * rhs;
		lhs = raw;
	}

	{
		__u64 a_abs = modeled_abs(lhs, w);
		__u64 b_abs = modeled_abs(rhs, w);
		__u64 sign = width_sign(w);
		__u64 limit = ((lhs ^ rhs) & sign) ? sign : (sign - 1);
		__u8 overflow = (__u8)(a_abs != 0ULL && b_abs > limit / a_abs);

		mcf = overflow;
		mof = overflow;
	}

	mreg[DST_REG] = model_partial_write(mreg[DST_REG], product, w);
	mtag[DST_REG] = X86_SIM_TAG_SCALAR;
}

/* The heap fill pattern for one case: four uniform fills carrying the sign
 * and all-ones boundaries at every width, two uniform fills that make the
 * raw-versus-extended left-operand split numerically visible, and two
 * non-uniform fills that pin the little-endian byte order of the load (a
 * byte-reversed load cannot hide behind a uniform image). */
static void plant_heap_image(unsigned pattern)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++) {
		switch (pattern) {
		case 0U:
			heap[i] = 0x00U;
			break;
		case 1U:
			heap[i] = 0x01U;
			break;
		case 2U:
			heap[i] = 0x7fU;
			break;
		case 3U:
			heap[i] = 0x80U;
			break;
		case 4U:
			heap[i] = 0xfeU;
			break;
		case 5U:
			heap[i] = 0xffU;
			break;
		case 6U:
			heap[i] = (__u8)(0x30U + i);
			break;
		default:
			heap[i] = (__u8)(0xc3U + 7U * i);
			break;
		}
		exp_heap[i] = heap[i];
	}
}
/* Plant the register file: pattern values and pattern tags everywhere, with
 * the index lane forced to the small scalar index the AUX mode scales. The
 * source lane is form-conditional: the flagged form reads it whole as its
 * left operand, the memory form reads it as the base address of its load
 * (there it must hold the mapped heap pointer under the scalar tag). */
#define PLANT_REGS(FORM, LHS)                                              \
	do {                                                               \
		unsigned __pl_i;                                          \
                                                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_value = pattern_reg(__pl_i);             \
			__u8 __pl_tag = pattern_tag(__pl_i);                \
                                                                          \
			if (SRC_REG == __pl_i) {                            \
				if ((FORM) == 0U)                           \
					__pl_value = (LHS);                \
				else {                                      \
					__pl_value = HEAP_REG_VALUE;        \
					__pl_tag = X86_SIM_TAG_SCALAR;      \
				}                                           \
			}                                                   \
			if (INDEX_REG == __pl_i) {                          \
				__pl_value = INDEX_VALUE;                    \
				__pl_tag = X86_SIM_TAG_SCALAR;                \
			}                                                   \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)__pl_value,                 \
				__pl_tag);                                \
			mreg[__pl_i] = __pl_value;                           \
			mtag[__pl_i] = __pl_tag;                            \
		}                                                         \
	} while (0)

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
	(void)__x86_sim_ret_addr;                                         \
	(void)__x86_stack_mem;

/* The flag file is planted at both extremes, so a body that overwrites a flag
 * it must preserve, or preserves one it must write, is distinguishable in both
 * directions. */
static const __u8 pre_flag[2] = { 0U, 1U };

#define STAGE_FLAGS(FV)                                                    \
	do {                                                               \
		__x86_cf = pre_flag[fv];                                  \
		__x86_zf = pre_flag[fv];                                  \
		__x86_sf = pre_flag[fv];                                  \
		__x86_of = pre_flag[fv];                                  \
		mcf = pre_flag[fv];                                       \
		mzf = pre_flag[fv];                                       \
		msf = pre_flag[fv];                                       \
		mof = pre_flag[fv];                                       \
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
	} while (0)

/* Neither multiply form writes memory: the heap image must come back exactly
 * as planted. */
#define COMPARE_HEAP()                                                     \
	do {                                                               \
		unsigned __ch_i;                                          \
		int __ch_bad = 0;                                         \
		for (__ch_i = 0; __ch_i < HEAP_BYTES; __ch_i++) {          \
			if (exp_heap[__ch_i] != heap[__ch_i]) {            \
				printf("MISMATCH %s heap[%u] got 0x%02x "  \
				       "want 0x%02x\n", route_ctx,         \
				       (unsigned)__ch_i,                   \
				       (unsigned)heap[__ch_i],             \
				       (unsigned)exp_heap[__ch_i]);         \
				__ch_bad = 1;                              \
				break;                                     \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__ch_bad) {                                           \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

#define CHECK_FLAG_STATE(OP, WIDTH, AUXW, MODE, FV)                        \
	do {                                                               \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			printf("MISMATCH %s op=0x%02x width=%u "          \
			       "auxw=%u mode=%u fv=%u: flags written "     \
			       "got %u/%u/%u/%u want %u/%u/%u/%u\n",      \
			       route_ctx, (OP), (WIDTH), (AUXW), (MODE),  \
			       (FV), __x86_cf, __x86_zf, __x86_sf,        \
			       __x86_of, mcf, mzf, msf, mof);             \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* One case of one multiply form: plant the heap, registers, and flags, run
 * the real dispatched body, and compare the register file, tags, heap image,
 * and flags against the model. The bodies are inline in the dispatcher, so
 * every case drives the real `X86_SIM_L_EXEC` arm. The flagged form reads
 * `lhs` whole from the source lane; the memory form ignores it and reads its
 * left operand from the heap fill `pattern`, which the model must see
 * unchanged. */
static void check_imul(unsigned form, unsigned width_code,
		       unsigned aux_mem_width, unsigned mode, unsigned pattern,
		       __u64 lhs, __u64 imm, unsigned fv)
{
	unsigned op = (form == 0U) ? X86_OP_IMUL_IMM : X86_OP_IMUL_MEM_IMM;
	__u32 aux = KPROG_X86_MEM_AUX(
		(form != 0U && mode != 0U) ? INDEX_REG : X86_REG_NONE,
		(form != 0U && mode == 2U) ? 3U : 0U,
		(__u8)aux_mem_width, 0U);
	/* The whole immediate artifact field carries the store-half
	 * displacement in its upper half and the multiplier in its low half;
	 * it must be a 64-bit lvalue, since the dispatcher chain expands it
	 * in the shared store/CMOV arms and a literal would raise a
	 * shift-count-overflow warning there. */
	__u64 imm_artifact = imm;
	plant_heap_image(pattern);
	DECLARE_SIM_STATE();
	(void)__x86_sim_abi_kind;

	PLANT_REGS(form, lhs);
	STAGE_FLAGS(fv);

	route_ctx = (form == 0U) ? "imulImm" : "imulMemImm";
	model_imul_step(form, width_code, aux_mem_width, mode, lhs,
			imm_artifact);

	/* ---- run the real routed body ---- */
	X86_SIM_L_EXEC(op, DST_REG, SRC_REG, width_code, aux,
		       imm_artifact);

	COMPARE_ALL();
	COMPARE_HEAP();
	CHECK_FLAG_STATE(op, width_code, aux_mem_width, mode, fv);
}

/* The two multiply opcode codes must still name the dispatcher's arms, so the
 * route oracle cannot silently rotate the opcode space the body macros
 * consume. */
static void check_selectors(void)
{
	cases++;
	if (X86_OP_IMUL_IMM != 0x38U || X86_OP_IMUL_MEM_IMM != 0x41U) {
		printf("MISMATCH x86 imul opcode code drift\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned width_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Five AUX memory-width codes: the absent code (whose absence must
	 * fall back to the FLAGS-resolved width) and the four real codes. An
	 * out-of-domain byte is deliberately not swept: the load body seeds its
	 * accumulator with the addressed byte unconditionally and ORs only a
	 * matched width, so such a byte narrows to one byte rather than
	 * faulting, and that width set is closed by the machine-checked
	 * `x86_width.h` contract the grid already pins. */
	static const unsigned aux_mem_widths[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Eight register left operands: zero, one, the four width sign bits
	 * (each paired with the multiplier 1 below it is the overflow-boundary
	 * probe the sign-magnitude funnel's `limit` side decides), the all-ones
	 * lane, and a mixed pattern. */
	static const __u64 lhs_values[8] = {
		0ULL, 1ULL, 0x80ULL, 0x8000ULL, 0x80000000ULL,
		0x8000000000000000ULL, 0xffffffffffffffffULL,
		0x0123456789abcdefULL,
	};
	/* Eight heap fill patterns; see `plant_heap_image`. */
	static const unsigned heap_patterns[8] = {
		0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U,
	};
	/* Six immediate artifacts, each a (displacement << 32) | multiplier
	 * pair: the memory form reads its displacement from the store half and
	 * its multiplier from the low half, and the register form takes the
	 * whole artifact as its right operand. Every displacement keeps the
	 * effective address inside the mapped heap under both index modes. */
	static const __u64 imm_artifacts[6] = {
		0x0000000000000000ULL, 0x0000000000000001ULL,
		0x0000002800000003ULL, 0xfffffff040000000ULL,
		0x0000000480000000ULL, 0x00000040ffffffffULL,
	};
	unsigned w;
	unsigned a;
	unsigned l;
	unsigned p;
	unsigned m;
	unsigned md;
	unsigned fv;

	check_selectors();

	/* The flagged form: no AUX memory-width lane, no addressing mode, and
	 * the flat zero-fill heap it never reads. */
	for (w = 0; w < 5U; w++)
		for (l = 0; l < 8U; l++)
			for (m = 0; m < 6U; m++)
				for (fv = 0; fv < 2U; fv++)
					check_imul(0U, width_codes[w], 0U,
						   0U, heap_patterns[0],
						   lhs_values[l],
						   imm_artifacts[m], fv);

	/* The memory form: the AUX memory-width lane, the heap fill pattern
	 * (which supplies the left operand), and the three addressing modes.
	 * The `lhs_values[l]` slot is unused by this form. */
	for (w = 0; w < 5U; w++)
		for (a = 0; a < 5U; a++)
			for (p = 0; p < 8U; p++)
				for (m = 0; m < 6U; m++)
					for (md = 0; md < 3U; md++)
						for (fv = 0; fv < 2U; fv++)
							check_imul(1U,
								width_codes[w],
								aux_mem_widths[a],
								md,
								heap_patterns[p],
								lhs_values[0],
								imm_artifacts[m],
								fv);

	if (cases != 261121UL) {
		printf("x86 imul route host cross-check: case-count drift "
		       "(got %lu want %lu)\n", cases, 261121UL);
		return 1;
	}
	if (failures == 0)
		printf("x86 imul route host cross-check: OK (%lu cases)\n",
		       cases);
	else
		printf("x86 imul route host cross-check: FAIL "
		       "(%lu cases, %d failures)\n", cases, failures);
	return failures == 0 ? 0 : 1;
}
