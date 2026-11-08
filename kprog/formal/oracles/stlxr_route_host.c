/* Full register, provenance, SP, heap/stack byte and slot-tag regression
 * for success and failure. All previous destination/source/base/width/aux
 * scenes remain; a failed store changes only its 32-bit status destination.
 */
#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include "stack_store_model_host.h"
#include <string.h>
#include <stdlib.h>

static unsigned failure;
unsigned long native_lab_exclusive_failure_choice(unsigned int site)
{
	if (site != 0) abort();
	return failure;
}

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

#define QUIET_GPR_ONE(REG, NAME) \
	(void)sizeof(__a64_##NAME); \
	(void)sizeof(__a64_##NAME##_tag);

#define DECL_STATE() \
	ARM64_SIM_L_DECLARE_STATE(); \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP; \
	(void)__a64_sim_abi_kind; \
	ARM64_SIM_L_DECLARE_STACK(); \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE); \
	(void)__a64_lr

/* ------------------------------------------------------------ */
/* Model state.                                                  */
/* ------------------------------------------------------------ */

static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static unsigned long model_unsupported_calls;

static void model_unsupported(void)
{
	model_unsupported_calls++;
}

#define HEAP_BYTES 4096U
#define SCALAR_BASE_OFF 1024U
#define MAP_BASE_OFF 2048U
static __u8 heap[HEAP_BYTES];
static __u8 heap_exp[HEAP_BYTES];
static __u8 heap_img[HEAP_BYTES];

#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_exp[STACK_BYTES];
static __u8 stk_tag_exp[STACK_SLOTS];
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

/* The stack base value the oracle plants: with the simulator's
 * `ARM64_SIM_STACK_BIAS` of 96 an access at offset 0 lands at arena index
 * 32, an unaligned variant at 37. */
#define STACK_BASE_VAL (-64LL)
#define STACK_BASE_OFF (-59LL)

/* A deterministic register pattern: distinct per index, with high bits set so
 * a 64-bit-vs-narrow write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `ARM64_SIM_TAG_SCALAR` and never the stack
 * tag, so a form that scalarizes changes the destination tag and no planted
 * base accidentally takes the stack body through its tag alone. */
static __u8 pattern_tag(unsigned i)
{
	static const __u8 tags[4] = {
		ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_ABI,
		ARM64_SIM_TAG_PACKET, ARM64_SIM_TAG_MAP_PTR,
	};

	return tags[i % 4U];
}

/* ------------------------------------------------------------------ */
/* The flat little-endian byte image and the model's own write.        */
/* ------------------------------------------------------------------ */

/* Scatter `APPLY_WIDTH(VALUE, WIDTH)` as `width` little-endian bytes: an
 * independent restatement of the store-bytes lane ladder for the four width
 * codes (whose numeric value is exactly the byte count). */
static void img_store(__u8 *base, unsigned width, __u64 value)
{
	__u64 v = KPROG_ARM64_APPLY_WIDTH(value, width);
	unsigned i;

	for (i = 0; i < width; i++)
		base[i] = (__u8)(v >> (8U * i));
}

static void heap_write(__u64 addr, unsigned width, __u64 value)
{
	img_store(&heap_exp[(unsigned long)
			    (addr - (__u64)(unsigned long)heap)],
		  width, value);
}

static void heap_read_state(const __u8 *src, unsigned n)
{
	unsigned i;

	for (i = 0; i < n; i++)
		printf("%02x", src[i]);
}

/* Stack bytes and whole-word provenance are checked independently. */
static void stack_write(__u32 idx, unsigned width, __u64 value, __u8 tag)
{
	img_store(&stk_exp[idx], width, value);
	host_stack_store_tags(stk_tag_exp, idx, width, tag);
}

/* The register file as the memory macros read it: the stack pointer's raw
 * slot, zero for the zero register and the no-register sentinel, the stored
 * value otherwise. */
static __u64 m_reg(unsigned reg)
{
	if (reg == ARM64_SP)
		return (__u64)msp;
	if (reg >= 31U)
		return 0;
	return mreg[reg];
}

static __u8 m_rtag(unsigned reg)
{
	if (reg == ARM64_SP)
		return ARM64_SIM_TAG_STACK;
	if (reg >= 31U)
		return ARM64_SIM_TAG_SCALAR;
	return mtag[reg];
}

/* The store body the arm's `ARM64_SIM_L_MEM_WRITE` reaches, restated: the
 * stack body exactly when the base register is the SP or its tag names the
 * stack (the value then reads as the pre-bias arena index the dispatcher
 * plants), the plain byte store otherwise at base+0. */
static void model_mem_write(unsigned base, unsigned width, __u64 value,
			    __u8 tag)
{
	if (base == ARM64_SP || m_rtag(base) == ARM64_SIM_TAG_STACK) {
		__s64 b = base == ARM64_SP ? msp : (__s64)mreg[base];

		stack_write((__u32)(ARM64_SIM_STACK_BIAS + b), width, value,
			    tag);
	} else {
		heap_write(mreg[base], width, value);
	}
}

/* `ARM64_SIM_L_WRITE_REG_WIDTH` at the fixed status width, restated. The
 * value is the generated macro's result and the width-narrowing body is the
 * 32-bit one, so the model stores the (already narrow) status value and
 * always scalarizes the tag. */
static void model_write_status(unsigned dst)
{
	if (dst == ARM64_SP) {
		msp = failure;
	} else if (dst != ARM64_XZR && dst != ARM64_REG_NONE) {
		mreg[dst] = failure;
		mtag[dst] = ARM64_SIM_TAG_SCALAR;
	}
}

/* The sim-local STLXR arm, restated. */
static void model_stlxr(unsigned op, unsigned dst, unsigned src,
			unsigned base, unsigned width, __u32 aux)
{
	if (op != ARM64_OP_STLXR) {
		model_unsupported();
		return;
	}
	/* Arm DATAOVERLAP, BASEOVERLAP and incoming SP alignment. */
	if (dst == src || (base != ARM64_SP && dst == base) ||
	    (base == ARM64_SP && ((__u64)msp & 15U))) {
		model_unsupported();
		return;
	}
	(void)aux;
	if (!failure)
		model_mem_write(base, width, m_reg(src), m_rtag(src));
	model_write_status(dst);
}

/* ------------------------------------------------------------ */
/* The checker.                                                  */
/* ------------------------------------------------------------ */

#define STACK_ARENA_INIT()                                                 \
	do {                                                               \
		unsigned __si_i;                                          \
		for (__si_i = 0; __si_i < STACK_BYTES; __si_i++) {         \
			__a64_stack.b[__si_i] = stk_img[__si_i];          \
			stk_exp[__si_i] = stk_img[__si_i];                \
		}                                                         \
		for (__si_i = 0; __si_i < STACK_SLOTS; __si_i++) {         \
			__a64_stack_tag[__si_i] = stk_tag_img[__si_i];    \
			stk_tag_exp[__si_i] = stk_tag_img[__si_i];        \
		}                                                         \
	} while (0)

/* Plant the simulator and model register files with the identical pattern and
 * anchor the payload source and the base the scene selected. Written as a
 * macro so it expands in the checker's own state scope. */
#define PLANT_STATE(SRC, BASE)                                             \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
		__a64_sp = STACK_BASE_VAL;                                \
		msp = STACK_BASE_VAL;                                     \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X1),                 \
			(void *)(long)0xfeedfacecafebeefULL,               \
			ARM64_SIM_TAG_SCALAR);                            \
		mreg[ARM64_X1] = 0xfeedfacecafebeefULL;                    \
		mtag[ARM64_X1] = ARM64_SIM_TAG_SCALAR;                    \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X2),                 \
			(void *)(long)(heap + SCALAR_BASE_OFF),            \
			ARM64_SIM_TAG_SCALAR);                            \
		mreg[ARM64_X2] = (__u64)(long)(heap + SCALAR_BASE_OFF);    \
		mtag[ARM64_X2] = ARM64_SIM_TAG_SCALAR;                    \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X5),                 \
			(void *)(long)(heap + MAP_BASE_OFF),               \
			ARM64_SIM_TAG_MAP_PTR);                           \
		mreg[ARM64_X5] = (__u64)(long)(heap + MAP_BASE_OFF);       \
		mtag[ARM64_X5] = ARM64_SIM_TAG_MAP_PTR;                   \
		ARM64_SIM_L_WRITE_REG_PTR_TAG((ARM64_X7),                 \
			(void *)(long)STACK_BASE_VAL,                      \
			ARM64_SIM_TAG_STACK);                             \
		mreg[ARM64_X7] = (__u64)STACK_BASE_VAL;                    \
		mtag[ARM64_X7] = ARM64_SIM_TAG_STACK;                     \
		if ((SRC) == ARM64_SP && (BASE) != ARM64_SP &&             \
		    (BASE) != ARM64_X7) {                                 \
			__a64_sp = (__s64)0x1122334455667788LL;           \
			msp = __a64_sp;                                   \
		}                                                         \
	} while (0)

#define COMPARE_MEM_STATE()                                                \
	do {                                                               \
		cases++;                                                  \
		if (memcmp(heap, heap_exp, HEAP_BYTES) != 0 ||            \
		    memcmp(__a64_stack.b, stk_exp, STACK_BYTES) != 0 ||    \
		    memcmp(__a64_stack_tag, stk_tag_exp,                  \
			   STACK_SLOTS) != 0) {                           \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

#define REPORT_MEM_STATE(OP, DST, SRC, BASE, WIDTH, AUX, VIA, MEM)          \
	do {                                                               \
		printf("MISMATCH op=%#x dst=%u src=%u base=%u width=%u "   \
		       "aux=%#x via=%u memory image\n", (OP), (DST),       \
		       (SRC), (BASE), (WIDTH), (unsigned)(AUX), (VIA));    \
		heap_read_state((MEM), 8);                                 \
		printf("\n");                                              \
	} while (0)

#define COMPARE_REG_STATE(OP, DST, SRC, BASE, WIDTH, AUX, VIA)              \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);      \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH op=%#x dst=%u src=%u "   \
				       "base=%u width=%u aux=%#x via=%u "  \
				       "reg%u: got 0x%llx want 0x%llx\n",  \
				       (OP), (DST), (SRC), (BASE),         \
				       (WIDTH), (unsigned)(AUX), (VIA),    \
				       (unsigned)__cs_i,                   \
				       (unsigned long long)__cs_got,       \
				       (unsigned long long)mreg[__cs_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH op=%#x via=%u reg%u "    \
				       "tag: got %u want %u\n",           \
				       (OP), (VIA), (unsigned)__cs_i,     \
				       __cs_tag, mtag[__cs_i]);           \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH op=%#x via=%u sp: got %lld "     \
			       "want %lld\n", (OP), (VIA),                \
			       (long long)__a64_sp, (long long)msp);      \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* FLAGS carries the raw width code the dispatcher resolves; zero falls back
 * to the 64-bit default inside the dispatcher. AUX is the packed memory
 * operand byte word; the arm keeps the zero immediate for every aux. */
/* Faults transfer directly to observation, preserving the complete frame
 * at the architectural fault point. Selector probes keep their counting hook. */
#undef ARM64_SIM_L_UNSUPPORTED_OPCODE
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() \
    ({ arm64_sim_unsupported_opcode(); goto observe_fault; })
static void check_case(unsigned op, unsigned dst, unsigned src,
		       unsigned base, unsigned flags, __u32 aux, unsigned via)
{
	unsigned width = ARM64_SIM_L_EFFECTIVE_WIDTH(flags);
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;
	unsigned i;

	DECL_STATE();
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;

	PLANT_STATE(src, base);

	for (i = 0; i < HEAP_BYTES; i++) {
		heap[i] = heap_img[i];
		heap_exp[i] = heap_img[i];
	}
	STACK_ARENA_INIT();

	model_stlxr(op, dst, src, base, width, aux);

	if (via)
		ARM64_SIM_L_EXEC(op, dst, src, base, ARM64_REG_NONE, flags,
				 aux, 0);
	else if (op == ARM64_OP_STLXR)
		/* The direct lane replays the arm's own two-statement body
		 * against the same planted state. */
		do {
			if (dst == src || (base != ARM64_SP && dst == base))
				ARM64_SIM_L_UNSUPPORTED_OPCODE();
			ARM64_SIM_L_SP_ALIGNMENT(base);
			if (!NATIVE_LAB_EXCLUSIVE_FAILURE(0))
			ARM64_SIM_L_MEM_WRITE(base, ARM64_REG_NONE, aux, 0, 0,
					      width,
					      ARM64_SIM_L_READ_REG(src),
					      ARM64_SIM_L_REG_TAG(src));
			ARM64_SIM_L_WRITE_REG_WIDTH(dst,
					ARM64_SIM_L_STLXR_VALUE(op, failure),
					ARM64_WIDTH_32);
		} while (0);
	else
		/* A non-member opcode routes to the dispatcher's unsupported
		 * arm once, like the exec lane. */
		ARM64_SIM_L_UNSUPPORTED_OPCODE();

observe_fault:
	cases++;
	if (unsupported_calls != u0 + (model_unsupported_calls - mu0)) {
		printf("MISMATCH op=%#x dst=%u src=%u base=%u width=%u "
		       "aux=%#x via=%u unsupported delta: got %lu want %lu\n",
		       op, dst, src, base, width, (unsigned)aux, via,
		       unsupported_calls - u0,
		       model_unsupported_calls - mu0);
		failures++;
		return;
	}

	cases++;
	if (memcmp(heap, heap_exp, HEAP_BYTES) != 0) {
		REPORT_MEM_STATE(op, dst, src, base, width, aux, via, heap);
		failures++;
		return;
	}

	cases++;
	if (memcmp(__a64_stack.b, stk_exp, STACK_BYTES) != 0) {
		REPORT_MEM_STATE(op, dst, src, base, width, aux, via,
				 __a64_stack.b);
		failures++;
		return;
	}

	cases++;
	if (memcmp(__a64_stack_tag, stk_tag_exp, STACK_SLOTS) != 0) {
		printf("MISMATCH op=%#x dst=%u src=%u base=%u width=%u "
		       "aux=%#x via=%u stack slot tag image\n", op, dst, src,
		       base, width, (unsigned)aux, via);
		failures++;
		return;
	}

	COMPARE_REG_STATE(op, dst, src, base, width, aux, via);
}

#undef ARM64_SIM_L_UNSUPPORTED_OPCODE
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() arm64_sim_unsupported_opcode()

/* The value selector: the generated status macro must return the painted
 * result for the known opcode and reach the caller hook exactly once for
 * every other byte, leaving the result at zero when the hook is silent. */
static void check_selectors(void)
{
	static const unsigned ops[3] = {
		ARM64_OP_STLXR, ARM64_OP_RET, ARM64_OP_LDRSB,
	};
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	unsigned o;
	unsigned w;

	for (o = 0; o < 3U; o++) {
		for (w = 0; w < 4U; w++) {
			unsigned long u0 = unsupported_calls;
			__u64 v;

			cases++;
			v = KPROG_ARM64_STLXR_VALUE(ops[o], widths[w], failure,
					arm64_sim_unsupported_opcode());
			if (v != (ops[o] == ARM64_OP_STLXR ? failure : 0)) {
				printf("MISMATCH selector op=%#x width=%u "
				       "value=%#llx\n", ops[o], widths[w],
				       (unsigned long long)v);
				failures++;
			}
			if ((ops[o] == ARM64_OP_STLXR) !=
			    (unsupported_calls == u0)) {
				printf("MISMATCH selector op=%#x width=%u "
				       "hook delta: got %lu\n", ops[o],
				       widths[w], unsupported_calls - u0);
				failures++;
			}
		}
	}

	/* The wrapper pins the 32-bit status width at every call. */
	for (o = 0; o < 3U; o++) {
		unsigned long u0 = unsupported_calls;
		__u64 v;

		cases++;
		v = ARM64_SIM_L_STLXR_VALUE(ops[o], failure);
		if (v != (ops[o] == ARM64_OP_STLXR ? failure : 0)) {
			printf("MISMATCH wrapper op=%#x value=%#llx\n",
			       ops[o], (unsigned long long)v);
			failures++;
		}
		if ((ops[o] == ARM64_OP_STLXR) !=
		    (unsupported_calls == u0)) {
			printf("MISMATCH wrapper op=%#x hook delta: got %lu\n",
			       ops[o], unsupported_calls - u0);
			failures++;
		}
	}
}

int main(void)
{
	static const unsigned ops[3] = { ARM64_OP_STLXR, ARM64_OP_RET,
		ARM64_OP_LDRSW };
	static const unsigned dsts[4] = {
		ARM64_X3, ARM64_XZR, ARM64_SP, ARM64_X2,
	};
	static const unsigned srcs[4] = {
		ARM64_X1, ARM64_X4, ARM64_XZR, ARM64_SP,
	};
	static const unsigned bases[4] = {
		ARM64_X2, ARM64_X5, ARM64_X7, ARM64_SP,
	};
	static const unsigned widths[4] = {
		ARM64_WIDTH_8, ARM64_WIDTH_16, ARM64_WIDTH_32, ARM64_WIDTH_64,
	};
	static const __u32 aux_classes[5] = {
		0x00000000U, 0x01000000U, 0x02000000U, 0x03000000U,
		0x12345678U,
	};
	unsigned via;
	unsigned o;
	unsigned d;
	unsigned s;
	unsigned b;
	unsigned w;
	unsigned a;
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap_img[i] = (__u8)(0x30U + i * 7U + (i >> 3));
	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	/* The exec lane: the real STLXR exec arm over the whole lattice, one
	 * full checker invocation per scene. */
	for (failure = 0; failure < 2U; failure++) {
	for (via = 0; via < 2U; via++)
		for (o = 0; o < 2U; o++)
			for (d = 0; d < 4U; d++)
				for (s = 0; s < 4U; s++)
					for (b = 0; b < 4U; b++)
						for (w = 0; w < 4U; w++)
							for (a = 0;
							     a < 5U; a++) {
				check_case(ops[o], dsts[d], srcs[s],
					   bases[b], widths[w],
					   aux_classes[a], via);
			}

	check_selectors();
	}


	if (failures != 0) {
		printf("arm64 stlxr route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 stlxr route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
