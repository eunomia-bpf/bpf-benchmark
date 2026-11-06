/*
 * Host cross-check for the x86 simulator's routing of the `CMOV` / `CMOV_MEM`
 * handler bodies through the machine-checked `generated/x86_cmov.h` contract
 * (STEP 0088). The bodies under test are the real simulator macros
 * `X86_SIM_L_EXEC_CMOV` and `X86_SIM_L_EXEC_CMOV_MEM`, driven both directly
 * and through the `X86_SIM_L_EXEC` dispatcher arms.
 *
 * The contract facts this oracle exercises, each planted so a wrong selection
 * is numerically distinguishable:
 *
 *   - The register form's condition is the *whole* AUX word
 *     (`KPROG_X86_CMOV_CONDITION`), promoted through C's usual conversions, so
 *     a word whose low byte names a condition but whose bits 8..31 are nonzero
 *     does *not* take it. The memory form's condition is the source-shift byte
 *     at bits 24..31 (`KPROG_X86_CMOV_MEM_CONDITION`); the AUX words carry a
 *     different low byte, so a low-byte or whole-word misroute flips the
 *     branch.
 *   - The write width is the opcode's FLAGS code with a 64-bit fallback
 *     (`KPROG_X86_CMOV_WIDTH`), and the memory form's access width has a
 *     second fallback to that write width (`KPROG_X86_CMOV_MEM_WIDTH`). A
 *     memory AUX whose width byte differs from the write width makes the two
 *     fallbacks and the two widths separately observable.
 *   - The displacement is the immediate's *high* half sign-extended
 *     (`KPROG_X86_CMOV_MEM_DISP`), not the whole-artifact slice.
 *     The artifact's low half is planted non-zero, so a body that used the
 *     whole-artifact slice differs from the routed high-half slice.
 *   - The 64-bit-vs-narrow writeback arm (`KPROG_X86_CMOV_WRITEBACK`): the
 *     register form preserves the source's provenance tag at 64 bits and
 *     scalarizes below; the memory form scalarizes at every width. The source
 *     registers carry non-scalar tags, so both the tag and the byte-level
 *     partial write are observable.
 *
 * The comparison is the whole register file (all 16 values and tags) plus all
 * four flags. The bodies write at most one register and never a flag, so a
 * misroute that selects the wrong arm, width, condition, displacement or value
 * source shows up as a differing register or tag, and a spurious flag write
 * shows up as a differing flag.
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

/* Backing store for the memory arm. The `heap` image is planted once; the
 * `exp_*` arrays below are the flat little-endian byte models the memory reads
 * assemble rather than leaning on the simulator's own memory macros. */
#define HEAP_BYTES 4096U
#define HEAP_BASE_OFF 1024U
static __u8 heap[HEAP_BYTES];

/* The stack arena image, indexed exactly as `X86_SIM_L_STACK_READ` indexes
 * `__x86_stack_mem.b`. */
static __u8 stack_img[X86_SIM_STACK_BYTES];

/* A deterministic register pattern: distinct per index, with high bits set so
 * a 64-bit-vs-narrow write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so a form that
 * scalarizes changes the destination tag. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static void fill_backing(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = (__u8)(0x30U + i);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		stack_img[i] = (__u8)(0xa0U + i);
}

/* The condition expression table, a restatement of `KPROG_X86_EVAL_CC`'s
 * boolean arms from the raw codes. `cc` is compared as the promoted word, so a
 * value whose bits 8..31 are nonzero matches no arm and yields the C default
 * `0`. */
static unsigned model_cc_true(unsigned cc, unsigned cf, unsigned zf,
			      unsigned sf, unsigned of)
{
	switch (cc) {
	case X86_CC_O:  return of;
	case X86_CC_NO: return !of;
	case X86_CC_B:  return cf;
	case X86_CC_AE: return !cf;
	case X86_CC_E:  return zf;
	case X86_CC_NE: return !zf;
	case X86_CC_BE: return cf || zf;
	case X86_CC_A:  return !cf && !zf;
	case X86_CC_S:  return sf;
	case X86_CC_NS: return !sf;
	case X86_CC_L:  return sf != of;
	case X86_CC_GE: return sf == of;
	case X86_CC_LE: return zf || (sf != of);
	case X86_CC_G:  return !zf && (sf == of);
	default:        return 0U;
	}
}

/* The partial-register write `KPROG_X86_WRITE_REG{8,16,32}` performs on the
 * little-endian union: the low `width` bytes are replaced, the higher bytes of
 * an 8- or 16-bit write are left as they were, and a 32-bit write zeroes the
 * upper half through the `(void *)(long)(__u32)` cast. */
static __u64 model_partial_write(__u64 old, __u64 v, unsigned w)
{
	if (w == X86_WIDTH_8)
		return (old & ~0xffULL) | (v & 0xffULL);
	if (w == X86_WIDTH_16)
		return (old & ~0xffffULL) | (v & 0xffffULL);
	if (w == X86_WIDTH_32)
		return v & 0xffffffffULL;
	return v;
}

/* The raw 64-bit register value the `CMOV` register form reads: the full
 * pointer, unmasked. */
static __u64 model_read_reg(unsigned reg)
{
	return mreg[reg];
}

/*
 * The memory read the memory form performs: resolve the offset through the
 * generated addressing facts (index byte at bits 0..7 scaled by the base-2 log
 * at bits 8..15, added to the sign-extended displacement), select the value
 * source through the same three-way classification the dispatch table states,
 * then assemble the value with an independent little-endian byte model.
 */
static __u64 model_read_mem(unsigned src, unsigned aux, __s64 disp,
			    unsigned mem_width, unsigned base_tag)
{
	unsigned index_reg = aux & 0xffU;
	unsigned scale = (aux >> 8) & 0xffU;
	__s64 off = disp;
	__u64 base_ptr = (src != X86_REG_NONE) ? mreg[src] : 0ULL;
	__u64 addr;
	__u64 v = 0;
	unsigned i;

	if (index_reg != X86_REG_NONE)
		off += (__s64)(mreg[index_reg] << scale);
	addr = base_ptr + (__u64)off;

	if (src == X86_RSP) {
		__u32 idx = (__u32)((base_ptr + (__u64)off) +
				    X86_SIM_STACK_BYTES);

		for (i = 0; i < mem_width; i++)
			v |= (__u64)stack_img[idx + i] << (8U * i);
		return v;
	}
	if (base_tag == X86_SIM_TAG_ABI && mem_width == X86_WIDTH_64) {
		unsigned long base = (unsigned long)(addr - (__u64)(long)heap);

		for (i = 0; i < 8U; i++)
			v |= (__u64)heap[base + i] << (8U * i);
		return v;
	}
	{
		unsigned long base = (unsigned long)(addr - (__u64)(long)heap);

		for (i = 0; i < mem_width; i++)
			v |= (__u64)heap[base + i] << (8U * i);
	}
	return v;
}

/* A deterministic small index value: `1 << scale` stays inside both the stack
 * arena and the heap window for every scale the oracle drives. */
#define INDEX_VALUE 1ULL

/* Plant the shared pristine register file (pattern values and tags) in the
 * simulator state and the model file. A macro so it expands in the calling
 * checker's state scope. */
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

#define COMPARE_STATE(VIA, TAG)                                            \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 16U; __cs_i++) {                \
			__u64 __cs_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__cs_i); \
			__u8 __cs_tag = X86_SIM_L_REG_TAG(__cs_i);        \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH tag=%u via=%u reg%u: got " \
				       "0x%llx want 0x%llx\n", (TAG),     \
				       (VIA), (unsigned)__cs_i,           \
				       (unsigned long long)__cs_got,      \
				       (unsigned long long)mreg[__cs_i]); \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH tag=%u via=%u reg%u tag: " \
				       "got %u want %u\n", (TAG), (VIA),  \
				       (unsigned)__cs_i, __cs_tag,        \
				       mtag[__cs_i]);                     \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/*
 * Register form. `aux_word` is the whole condition word; `flags` the opcode's
 * FLAGS width code; `cf`/`zf`/`sf`/`of` the planted flag nibble.
 */
static void check_reg(__u32 aux_word, unsigned flags, unsigned dst,
		      unsigned src, unsigned cf, unsigned zf, unsigned sf,
		      unsigned of, unsigned via)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	unsigned taken;

	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	(void)__x86_sim_ret_addr;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;

	PLANT_REGS();
	__x86_cf = (__u8)cf;
	__x86_zf = (__u8)zf;
	__x86_sf = (__u8)sf;
	__x86_of = (__u8)of;

	/* ---- independent model ---- */
	taken = model_cc_true(aux_word, cf, zf, sf, of);
	if (taken) {
		if (w == X86_WIDTH_64) {
			mreg[dst] = model_read_reg(src);
			mtag[dst] = mtag[src];
		} else {
			mreg[dst] = model_partial_write(mreg[dst],
							model_read_reg(src), w);
			mtag[dst] = X86_SIM_TAG_SCALAR;
		}
	}

	/* ---- run the real body ---- */
	if (via)
		X86_SIM_L_EXEC(X86_OP_CMOV, dst, src, flags, aux_word, 0ULL);
	else
		X86_SIM_L_EXEC_CMOV(dst, src, flags, aux_word);

	COMPARE_STATE(via, X86_OP_CMOV);

	cases++;
	if (__x86_cf != cf || __x86_zf != zf || __x86_sf != sf ||
	    __x86_of != of) {
		printf("MISMATCH cmov via=%u flags: cf=%u zf=%u sf=%u of=%u "
		       "want cf=%u zf=%u sf=%u of=%u\n", via, __x86_cf,
		       __x86_zf, __x86_sf, __x86_of, cf, zf, sf, of);
		failures++;
	}
}

/*
 * Memory form. `src`/`base_tag` select the value-source arm and the base
 * pointer; `cc_byte` is the condition code the AUX carries at bits 24..31;
 * `mw_code` the AUX memory-width byte at bits 16..23 (0 = fall back to the
 * write width); `disp` the sign-extended displacement; `has_index`/`scale`
 * the addressing mode.
 */
static void check_mem(unsigned src, unsigned base_tag, __u8 cc_byte,
		      unsigned mw_code, unsigned flags, __s64 slice,
		      unsigned has_index, unsigned scale, unsigned via)
{
	__u32 aux = ((__u32)cc_byte << 24) | ((__u32)mw_code << 16) |
		    (has_index ? (__u32)X86_RDI : (__u32)X86_REG_NONE) |
		    ((__u32)scale << 8);
	/* The instruction artifact: the displacement slice in its high half
	 * and a distinct, non-zero low half, so a body that took the
	 * whole-artifact slice (`x86_simm`) instead of the routed
	 * `KPROG_X86_CMOV_MEM_DISP` reads a different displacement. */
	__u64 imm = ((__u64)(__u32)slice << 32) | 0xa5a5a5a5ULL;
	unsigned w = flags ? flags : X86_WIDTH_64;
	unsigned mem_width = mw_code ? mw_code : w;
	unsigned taken;
	__u64 value;
	unsigned dst = 5U;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;

	PLANT_REGS();
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = stack_img[i];
	/* The base register's pointer and tag, and the (small) index register. */
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)(heap + HEAP_BASE_OFF),
				    base_tag);
	mreg[src] = (__u64)(long)(heap + HEAP_BASE_OFF);
	mtag[src] = (__u8)base_tag;
	if (src == X86_RSP) {
		/* The stack read indexes this frame's bytes as
		 * `(base + off) + X86_SIM_STACK_BYTES`; `-64` makes that index
		 * the raw offset, which the driven displacements keep inside
		 * the arena for every width. */
		X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)(-64), base_tag);
		mreg[src] = (__u64)(long)(-64);
	}
	if (has_index) {
		X86_SIM_L_WRITE_REG_WIDTH(X86_RDI, INDEX_VALUE, X86_WIDTH_64);
		mreg[X86_RDI] = INDEX_VALUE;
		mtag[X86_RDI] = X86_SIM_TAG_SCALAR;
	}
	__x86_cf = 1U;
	__x86_zf = 1U;
	__x86_sf = 0U;
	__x86_of = 0U;

	/* ---- independent model ---- */
	taken = model_cc_true(cc_byte, 1U, 1U, 0U, 0U);
	if (taken) {
		value = model_read_mem(src, aux, slice, mem_width, base_tag);
		if (w == X86_WIDTH_64) {
			mreg[dst] = value;
			mtag[dst] = X86_SIM_TAG_SCALAR;
		} else {
			mreg[dst] = model_partial_write(mreg[dst], value, w);
			mtag[dst] = X86_SIM_TAG_SCALAR;
		}
	}

	/* ---- run the real body ---- */
	if (via)
		X86_SIM_L_EXEC(X86_OP_CMOV_MEM, dst, src, flags, aux, imm);
	else
		X86_SIM_L_EXEC_CMOV_MEM(dst, src, flags, aux, imm);

	COMPARE_STATE(via, X86_OP_CMOV_MEM);
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	static const __u32 words[] = { 0U, 0x00000105U, 0x05000004U,
				       0xffffffffU };
	unsigned i;

	for (i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
		cases++;
		if (KPROG_X86_CMOV_CONDITION(words[i]) != words[i]) {
			printf("MISMATCH cmov condition word 0x%x\n", words[i]);
			failures++;
		}
	}
	cases++;
	if (KPROG_X86_CMOV_CONDITION_BYTE(0x00000105U) != 5U) {
		printf("MISMATCH cmov condition byte\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMOV_MEM_CONDITION(0x05000004U) != 5U ||
	    KPROG_X86_CMOV_MEM_CONDITION(0x00000004U) != 0U) {
		printf("MISMATCH cmov mem condition\n");
		failures++;
	}

	/* The write width: FLAGS, or 64 when absent. */
	{
		static const unsigned fl[] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					       X86_WIDTH_32, X86_WIDTH_64 };
		unsigned f;

		for (f = 0; f < sizeof(fl) / sizeof(fl[0]); f++) {
			unsigned want = fl[f] ? fl[f] : X86_WIDTH_64;

			cases++;
			if (KPROG_X86_CMOV_WIDTH(fl[f]) != want) {
				printf("MISMATCH cmov width flags=%u\n", fl[f]);
				failures++;
			}
		}
	}

	/* The memory access width: the AUX width byte, or the write width. */
	{
		__u32 aux_zero = ((__u32)0U << 16) | 0xffU;
		__u32 aux_eight = ((__u32)X86_WIDTH_8 << 16) | 0xffU;

		cases++;
		if (KPROG_X86_CMOV_MEM_WIDTH(aux_zero, X86_WIDTH_32) !=
				X86_WIDTH_32 ||
		    KPROG_X86_CMOV_MEM_WIDTH(aux_eight, X86_WIDTH_32) !=
				X86_WIDTH_8) {
			printf("MISMATCH cmov mem width\n");
			failures++;
		}
	}

	/* The displacement is the immediate's high half sign-extended. */
	cases++;
	if (KPROG_X86_CMOV_MEM_DISP(0x1234001000000008ULL) !=
		    (__s64)(__s32)0x12340010 ||
	    KPROG_X86_CMOV_MEM_DISP(0xffffffff00000008ULL) != (__s64)-1) {
		printf("MISMATCH cmov mem disp\n");
		failures++;
	}

	/* The writeback arm: pointer-preserving at 64 bits, scalarizing below. */
	cases++;
	if (KPROG_X86_CMOV_WRITEBACK(1) !=
		    KPROG_X86_CMOV_WRITEBACK_POINTER_TAG ||
	    KPROG_X86_CMOV_WRITEBACK(0) !=
		    KPROG_X86_CMOV_WRITEBACK_SCALARIZE) {
		printf("MISMATCH cmov writeback\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_CMOV_WRITEBACK(X86_WIDTH_64 == X86_WIDTH_64) !=
		    KPROG_X86_CMOV_WRITEBACK_POINTER_TAG ||
	    KPROG_X86_CMOV_WRITEBACK(X86_WIDTH_32 == X86_WIDTH_64) !=
		    KPROG_X86_CMOV_WRITEBACK_SCALARIZE) {
		printf("MISMATCH cmov writeback width test\n");
		failures++;
	}
}

int main(void)
{
	static const __u32 cc_words[] = {
		0x00000000U, X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE,
		X86_CC_E, X86_CC_NE, X86_CC_BE, X86_CC_A, X86_CC_S,
		X86_CC_NS, X86_CC_L, X86_CC_GE, X86_CC_LE, X86_CC_G,
		0x00000105U,   /* low byte `ne`, bits 8..31 set */
		0x00000104U,   /* low byte `e`, bits 8..31 set */
		0x05000004U,   /* byte3 `ne`, low byte `e` */
		0x80000000U | X86_CC_E,
	};
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						 X86_WIDTH_32, X86_WIDTH_64 };
	static const __u8 mem_cc[6] = { 0U, X86_CC_E, X86_CC_NE,
					X86_CC_L, X86_CC_GE, X86_CC_LE };
	static const unsigned mw_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					      X86_WIDTH_32, X86_WIDTH_64 };
	static const __s64 disps[4] = { 0, 8, 16, -1 };
	static const unsigned scales[4] = { 0U, 1U, 2U, 3U };
	unsigned via;
	unsigned a;
	unsigned f;
	unsigned d;
	unsigned s;
	unsigned fb;
	unsigned mw;
	unsigned di;
	unsigned ii;
	unsigned sc;

	fill_backing();

	/* ---- register form: every dst/src pair, condition word, width and
	 * flag nibble, directly and through the dispatcher ---- */
	for (via = 0; via < 2U; via++)
		for (a = 0; a < sizeof(cc_words) / sizeof(cc_words[0]); a++)
			for (f = 0; f < 5U; f++)
				for (d = 0; d < 16U; d++)
					for (s = 0; s < 16U; s++)
						for (fb = 0; fb < 16U; fb++)
							check_reg(cc_words[a],
								  flags_codes[f],
								  d, s,
								  fb & 1U,
								  (fb >> 1) & 1U,
								  (fb >> 2) & 1U,
								  (fb >> 3) & 1U,
								  via);

	/* ---- memory form: the three value-source arms, both fallbacks, the
	 * displacement slice, the addressing mode and the condition byte ---- */
	for (via = 0; via < 2U; via++) {
		for (mw = 0; mw < 5U; mw++) {
			for (f = 0; f < 5U; f++) {
				for (di = 0; di < 4U; di++) {
					for (ii = 0; ii < 2U; ii++) {
						for (sc = 0; sc < 4U; sc++) {
							unsigned c;

							for (c = 0; c < 6U;
							     c++) {
								check_mem(X86_RAX,
									  X86_SIM_TAG_SCALAR,
									  mem_cc[c],
									  mw_codes[mw],
									  flags_codes[f],
									  disps[di],
									  ii, scales[sc],
									  via);
								check_mem(X86_RBX,
									  X86_SIM_TAG_ABI,
									  mem_cc[c],
									  mw_codes[mw],
									  flags_codes[f],
									  disps[di],
									  ii, scales[sc],
									  via);
								if (disps[di] >= 0)
									check_mem(X86_RSP,
										  X86_SIM_TAG_STACK,
										  mem_cc[c],
										  mw_codes[mw],
										  flags_codes[f],
										  disps[di],
										  ii,
										  scales[sc],
										  via);
							}
						}
					}
				}
			}
		}
	}

	check_selectors();

	if (failures != 0) {
		printf("x86 cmov route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 cmov route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
