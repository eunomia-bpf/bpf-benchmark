/*
 * Battery-local route oracle (Step 0445): drives the real
 * `X86_SIM_L_EXEC_CMOV_STEP`/`X86_SIM_L_EXEC_CMOV`/`X86_SIM_L_EXEC_CMOV_MEM`
 * bodies inside `../x86/x86_sim_local_bpf.h` — the same bodies the Makefile
 * route host reaches only through the two aliases — over a lane grid the two
 * watched aliases, the partial-register write bodies, the two flag bodies,
 * and the condition word cannot all survive. Untracked, like every battery
 * file; the Makefile owns nothing here.
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
#include "x86_no_helpers_host.h"

#include <stdio.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include "test_core_dumps.h"

static int failures;
static __u64 model_arena_top;
static unsigned long cases;

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
static __u64 mreg[16];
static __u8 mtag[16];

/* Backing store for the memory arms: a heap image and a stack arena image. */
#define HEAP_BYTES 4096U
static __u8 heap[HEAP_BYTES];

static __u8 stack_img[X86_SIM_STACK_BYTES];

/* A deterministic register pattern: distinct per index, with high bits set so
 * a singular 64-bit-vs-narrow write is observable. High bytes differ per
 * lane so a dropped sign-extension disagrees. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so a form that
 * scalarizes — and a body that drops the source's tag — change the
 * destination tag. */
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
 * boolean arms from the raw codes. `cc` is compared as the promoted word, so
 * a value whose bits 8..31 are nonzero matches no arm and yields the C
 * default `0`. */
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
	case 10U: return 0U; /* These retained route fixtures seed PF=0. */
	case 11U: return 1U;
	case X86_CC_L:  return sf != of;
	case X86_CC_GE: return sf == of;
	case X86_CC_LE: return zf || (sf != of);
	case X86_CC_G:  return !zf && (sf == of);
	default:        return 0U;
	}
}

/* The partial-register write `KPROG_X86_WRITE_REG{8,16,32}` performs on the
 * little-endian union: the low `width` bytes are replaced, an 8- or 16-bit
 * write keeps the higher bytes, and a 32-bit write zeroes the upper half
 * through the `(void *)(long)(__u32)` cast. */
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

/* The raw 64-bit register value the register form reads: the full pointer,
 * unmasked. */
static __u64 model_read_reg(unsigned reg)
{
	return mreg[reg];
}

/*
 * The memory read the memory form performs: resolve the offset through the
 * addressing facts (index byte at bits 0..7 scaled by the base-2 log at bits
 * 8..15, added to the sign-extended displacement), select the value source
 * through the same three-way classification the dispatch table states, then
 * assemble the value with an independent little-endian byte model.
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
		off += (__s64)(X86_HOST_NATIVE_REG(index_reg) << scale);
	addr = base_ptr + (__u64)off;

	if (src == X86_RSP) {
		__u64 idx = (__u64)((base_ptr + (__u64)off) +
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

/* Compare the whole register file after a case: every cell must match the
 * model in value and tag, so no third cell moved. */
#define COMPARE_STATE(VIA, WIDTH, TAGVIA)                                  \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 16U; __cs_i++) {                \
			__u64 __cs_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__cs_i); \
			__u8 __cs_tag = X86_SIM_L_REG_TAG(__cs_i);        \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH via=%u w=%u tagvia=%u "  \
				       "reg%u: got 0x%llx want 0x%llx\n", \
				       (VIA), (WIDTH), (TAGVIA),          \
				       (unsigned)__cs_i,                  \
				       (unsigned long long)__cs_got,      \
				       (unsigned long long)mreg[__cs_i]); \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH via=%u w=%u tagvia=%u "  \
				       "reg%u tag: got %u want %u\n",     \
				       (VIA), (WIDTH), (TAGVIA),          \
				       (unsigned)__cs_i, __cs_tag,        \
				       mtag[__cs_i]);                     \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/*
 * The register form. `aux_word` is the whole condition word; `flags` the
 * FLAGS width code; `cf`/`zf`/`sf`/`of` the planted flag nibble. Driven
 * through all three gates: the two watched aliases and the dispatcher arm.
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
	model_arena_top = (__u64)(unsigned long)&__x86_stack_mem.b[sizeof(__x86_stack_mem.b)];
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
			if (dst == X86_RSP) {
				mreg[dst] = X86_HOST_NATIVE_REG(src);
				mtag[dst] = X86_SIM_TAG_SCALAR;
			} else if (src == X86_RSP) {
				mreg[dst] = model_arena_top + mreg[src];
				mtag[dst] = X86_SIM_TAG_STACK;
			} else {
				mreg[dst] = model_read_reg(src);
				mtag[dst] = mtag[src];
			}
		} else {
			mreg[dst] = model_partial_write(X86_HOST_NATIVE_REG(dst),
							X86_HOST_NATIVE_REG(src), w);
			mtag[dst] = X86_SIM_TAG_SCALAR;
		}
	}

	if (!taken && w == X86_WIDTH_32) {
		mreg[dst] = X86_HOST_NATIVE_REG(dst) & 0xffffffffULL;
		mtag[dst] = X86_SIM_TAG_SCALAR;
	}

	/* ---- run the real body through one of the three gates ---- */
	if (via == 0U)
		X86_SIM_L_EXEC_CMOV(dst, src, flags, aux_word);
	else if (via == 1U)
		X86_SIM_L_EXEC(X86_OP_CMOV, dst, src, flags, aux_word, 0ULL);
	else
		X86_SIM_L_EXEC_CMOV_STEP(0U, dst, src, flags, aux_word, 0ULL);

	COMPARE_STATE(via, w, 2U);

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
 * The memory form. `src`/`base_tag` select the value-source arm and the base
 * pointer; `cc_byte` is the condition code the AUX carries at bits 24..31;
 * `mw_code` the AUX memory-width byte at bits 16..23 (0 = fall back to the
 * write width); `disp` the sign-extended displacement; `has_index`/`scale`
 * the addressing mode. Driven through all three gates too.
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
	model_arena_top = (__u64)(unsigned long)&__x86_stack_mem.b[sizeof(__x86_stack_mem.b)];
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;

	PLANT_REGS();
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		__x86_stack_mem.b[i] = stack_img[i];
	/* The base register's pointer and tag, and the (small) index register.
	 * Tags are non-scalar so an unconditional scalarization of the base
	 * or the destination is observable. */
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)(heap + 1024U),
				    base_tag);
	mreg[src] = (__u64)(long)(heap + 1024U);
	mtag[src] = (__u8)base_tag;
	if (src == X86_RSP) {
		/* The stack read indexes this frame's bytes as
		 * `(base + off) + X86_SIM_STACK_BYTES`; `-64` makes that
		 * index the raw offset, which the driven displacements keep
		 * inside the arena for every width. */
		X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)(-64),
					    base_tag);
		mreg[src] = (__u64)(long)(-64);
	}
	if (has_index) {
		X86_SIM_L_WRITE_REG_WIDTH(X86_RDI, 1ULL, X86_WIDTH_64);
		mreg[X86_RDI] = 1ULL;
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
			mreg[dst] = model_partial_write(X86_HOST_NATIVE_REG(dst), value, w);
			mtag[dst] = X86_SIM_TAG_SCALAR;
		}
	}

	if (!taken && w == X86_WIDTH_32) {
		mreg[dst] = X86_HOST_NATIVE_REG(dst) & 0xffffffffULL;
		mtag[dst] = X86_SIM_TAG_SCALAR;
	}

	/* ---- run the real body through one of the three gates ---- */
	if (via == 0U)
		X86_SIM_L_EXEC_CMOV_MEM(dst, src, flags, aux, imm);
	else if (via == 1U)
		X86_SIM_L_EXEC(X86_OP_CMOV_MEM, dst, src, flags, aux, imm);
	else
		X86_SIM_L_EXEC_CMOV_STEP(1U, dst, src, flags, aux, imm);

	COMPARE_STATE(via, w, 3U);
}

/*
 * The writeback width route through the same STEP body the width ladder
 * covers: one lane per width code at the 64-bit and 32-bit write codes,
 * where the writeback pointer/arm selection and the partial-register write
 * disagree if the routed body inverted or widened them.
 */
static void check_width_lane(unsigned flags, unsigned cc, unsigned dst,
			     unsigned src, unsigned via)
{
	check_reg(cc, flags, dst, src, 1U, 0U, 0U, 0U, via);
}

/* Regression: clang must retain the source load even with a false condition.
 * A protected page makes a missing access observable without relying on the
 * value of an invalid C load. Widths 16/32/64 are all real CMOV encodings. */
static void check_untaken_memory_fault(unsigned width)
{
	pid_t child = fork();
	int status;
	if (child < 0) { perror("fork"); failures++; return; }
	if (child == 0) {
		void *page = mmap(NULL, 4096, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (page == MAP_FAILED) { perror("mmap"); _exit(2); }
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
	model_arena_top = (__u64)(unsigned long)&__x86_stack_mem.b[sizeof(__x86_stack_mem.b)];
		struct x86_sim_xdp_abi __x86_sim_abi = {};
		struct __sk_buff *__x86_sim_skb_ctx = NULL;
		__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
		__x86_zf = 0;
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDX, page, X86_SIM_TAG_SCALAR);
		X86_SIM_L_EXEC_CMOV_MEM(X86_RAX, X86_RDX, width,
			X86_MEM_AUX_FULL(X86_REG_NONE, 0, width) |
			X86_REG_AUX_SRC_SHIFT(X86_CC_E), 0);
		_exit(0);
	}
	if (waitpid(child, &status, 0) != child) { perror("waitpid"); failures++; return; }
	if (!WIFSIGNALED(status) || WTERMSIG(status) != SIGSEGV) {
		printf("untaken CMOV source access missing width=%u status=%d\n", width, status);
		failures++;
	}
	cases++;
}

int main(void)
{
	static const __u32 cc_words[] = {
		0x00000000U, X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE,
		X86_CC_E, X86_CC_NE, X86_CC_BE, X86_CC_A, X86_CC_S,
		X86_CC_NS, X86_CC_L, X86_CC_GE, X86_CC_LE, X86_CC_G,
		0x00000105U,   /* low byte `ne`, bits 8..31 set */
		0x05000004U,   /* byte3 `ne`, low byte `e` */
		0x80000000U | X86_CC_E,
	};
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8,
						 X86_WIDTH_16, X86_WIDTH_32,
						 X86_WIDTH_64 };
	/* Two flag nibbles: one takes every plain and signed condition, one
	 * takes the inverse-complement lanes, so neither polarity of the
	 * condition ladder can drift silently. */
	static const unsigned nib[2] = { 0U, 15U };
	static const __u8 mem_cc[6] = { 0U, X86_CC_E, X86_CC_NE,
					X86_CC_L, X86_CC_GE, X86_CC_LE };
	static const unsigned mw_codes[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					      X86_WIDTH_32, X86_WIDTH_64 };
	static const __s64 disps[3] = { 0, 8, -8 };
	static const unsigned scales[2] = { 0U, 2U };
	unsigned via;
	unsigned a;
	unsigned f;
	unsigned d;
	unsigned s;
	unsigned nb;
	unsigned fb;
	unsigned mw;
	unsigned di;
	unsigned ii;
	unsigned sc;
	unsigned c;

	fill_backing();

	/* ---- register form: every dst/src pair, condition word, WIDTH and
	 * flag nibble, through each gate ---- */
	for (via = 0; via < 3U; via++)
		for (a = 0; a < sizeof(cc_words) / sizeof(cc_words[0]); a++)
			for (f = 0; f < 5U; f++)
				for (d = 0; d < 16U; d++)
					for (s = 0; s < 16U; s++)
						for (nb = 0; nb < 2U; nb++)
							for (fb = 0;
							     fb < 2U;
							     fb++)
								check_reg(cc_words[a],
									  flags_codes[f],
									  d, s,
									  nib[fb],
									  (nb >> 1) & 1U,
									  (nb >> 2) & 1U,
									  (nb >> 3) & 1U,
									  via);

	/* ---- memory form: the three value-source arms, both fallbacks, the
	 * displacement slice, the addressing mode and the condition byte,
	 * through each gate ---- */
	for (via = 0; via < 3U; via++) {
		for (mw = 0; mw < 5U; mw++) {
			for (f = 0; f < 5U; f++) {
				for (di = 0; di < 3U; di++) {
					for (ii = 0; ii < 2U; ii++) {
						for (sc = 0; sc < 2U; sc++) {
							for (c = 0; c < 6U;
							     c++) {
								check_mem(X86_RAX,
									  X86_SIM_TAG_SCALAR,
									  mem_cc[c],
									  mw_codes[mw],
									  flags_codes[f],
									  disps[di],
									  ii,
									  scales[sc],
									  via);
								check_mem(X86_RBX,
									  X86_SIM_TAG_ABI,
									  mem_cc[c],
									  mw_codes[mw],
									  flags_codes[f],
									  disps[di],
									  ii,
									  scales[sc],
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

	/* ---- the width grid at one fixed lane, where the routed STEP
	 * writeback arm and the width ladder disagree if inverted ---- */
	for (via = 0; via < 3U; via++)
		for (f = 0; f < 5U; f++)
			check_width_lane(flags_codes[f], X86_CC_S, 9U, 4U,
					 via);

	check_untaken_memory_fault(X86_WIDTH_16);
	check_untaken_memory_fault(X86_WIDTH_32);
	check_untaken_memory_fault(X86_WIDTH_64);

	if (failures) {
		printf("x86 cmov step route cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 cmov step route cross-check: OK (%lu cases)\n", cases);
	return 0;
}
