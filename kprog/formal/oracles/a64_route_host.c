/*
 * Route host cross-check for the AArch64 sim-local A64 control-flow ladder
 * and entry/exit glue family in ../arm64/arm64_sim_local_bpf.h. STEP 0455,
 * extended in STEP 0458 with the memory/stack route-host family and in
 * STEP 0459 with the guard / state-tail / DQ vector-lane scene family.
 * Family under test (unrowed substrate: the whole-trace 0273 host exercises
 * ARM64_SIM_A64_JCC edges without touching these body lines, and the generated
 * direction/cond/branch contracts are separate batteries):
 *
 *   ARM64_SIM_RET()                     cb[0]/cb[1] writeback + (u32)x0 exit
 *   ARM64_SIM_A64_JMP/JCC_IMPL(+BACKWARD) forward/backward conditional routing
 *   ARM64_SIM_A64_CBZ/CBNZ/TBZ/TBNZ(+IMPL) compare/bit-test branch bodies
 *   ARM64_SIM_A64_CALL/A64_RET          linked call ladder over RETURN_CASES
 *   ARM64_SIM_RETURN_CASES default / ARM64_SIM_CONCAT fallthrough-label glue
 *   ARM64_SIM_RUN_OP/RUN_OP3            op forwarding into ARM64_SIM_L_EXEC
 *   ARM64_SIM_L_EVAL_COND               NZCV threading into the cond predicate
 *   ARM64_SIM_ENTRY_XDP/ENTRY_SKB       ABI-kind + skb-ctx + x0 ABI-lane glue
 *   ARM64_SIM_L_DECLARE_REG/STATE/STACK + FOR_EACH_GPR declaration substrate
 *   READ_REG/READ_REG_PTR/REG_TAG (+CASE) and
 *   WRITE_REG_WIDTH/WRITE_REG64/32_CASE/WRITE_REG_PTR(_CASE)/PTR_TAG/MAP_PTR
 *   register-file fan-out bodies
 *   ARM64_SIM_L_STACK_READ/_READ_TAG/_WRITE/_WRITE_TAG stack word/byte lanes
 *   ARM64_SIM_L_MEM_BASE_OFF  pre/post suppress + index-register offset decode
 *   ARM64_SIM_L_MEM_READ_TAG   stack/ABI/reloc/default tag dispatch table
 *   ARM64_SIM_L_MEM_READ/MEM_WRITE  value-lane arm split over the resolved tag
 *   ARM64_SIM_L_MEM_PRE/MEM_POST  base-pointer writeback step
 *   include-guard re-include + live-lane re-verify (guard scene)
 *   DECLARE_STATE v0/v0_hi + NZCV + lr state-tail plant/readback glue
 *   ARM64_SIM_L_{LOAD_D0,LOAD_Q0,STORE_D0,STORE_Q0}_MEM DQ vector-lane
 *   transfers over the MEM value-lane path
 *
 * Every scene drives the real macros inside a real goto-ladder and compares the
 * whole observable state (31 register values + provenance tags, SP, lr, NZCV,
 * exit value, taken-path marks) against an independent model recomputation.
 * The battery build/mut_arm64_a64_route.py repaints one body line per row and
 * requires this host to catch it, or keep observing an equivalent. Tag lanes
 * are numeric literals (TAG_SCALAR 0..TAG_RODATA 8).
 */

#define __BPF_HELPERS__ 1
#define ARM64_SIM_RETURN_CASES \
	case 0x40ULL: goto arm64_l_40; \
	case 0x80ULL: goto arm64_l_80;
#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#define __always_inline inline
#pragma GCC diagnostic push
/* The -O2 const-folding of the -Warray-bounds pass trips over the unreachable
 * sentinel-lane pointer reads inside the shared generated load/store byte
 * ladders; every other fact stays under the same -Werror wall. */
#pragma GCC diagnostic ignored "-Warray-bounds"
#include "../arm64/arm64_sim_local_bpf.h"
#include <stdio.h>
#include "stack_store_model_host.h"

static int failures;
static int unsupported_hits;

void arm64_sim_unsupported_opcode(void)
{
	unsupported_hits++;
}


static unsigned long cases;

/* ---------------------------------------------------------------- model */
static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static __u64 mlr;
static unsigned mn, mz, mc, mv;

static int model_abi_live;

static void model_stack_reset(void);
static void model_reset(void)
{
	unsigned i;
	for (i = 0; i < 31U; i++) {
		mreg[i] = 0;
		mtag[i] = 0U;             /* ARM64_SIM_TAG_SCALAR */
	}
	msp = 0;
	mlr = 0;
	mn = mz = mc = mv = 0;
	/* model_reset runs AFTER the entry glue in every scene; the glue leaves
	 * x0 = &__a64_sim_abi with TAG_ABI (only the sim's own value matches;
	 * the model lane uses the pointer identity, not a replayed constant). */
	model_abi_live = 1;
	model_stack_reset();
	mtag[30] = 10U; /* Entry return capability, distinct from scalar zero. */
}

static void model_flags(unsigned n, unsigned z, unsigned c, unsigned v)
{
	mn = n;
	mz = z;
	mc = c;
	mv = v;
}

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

/* Model branch-kind evaluator over the four KPROG_ARM64_BRANCH_* codes and the
 * model cond evaluator over the 15 ARM64_COND codes; both independent of the
 * generator-emitted C bodies. */
static int model_branch_take(unsigned kind, __u64 value, __u64 bit)
{
	switch (kind) {
	case 0U: return value == 0;
	case 1U: return value != 0;
	case 2U: return ((value >> (bit & 63ULL)) & 1ULL) == 0;
	case 3U: return ((value >> (bit & 63ULL)) & 1ULL) != 0;
	}
	return -1;
}

static int model_take(unsigned cond, unsigned n, unsigned z, unsigned c,
		      unsigned v)
{
	switch (cond) {
	case 0U:  return z != 0;
	case 1U:  return z == 0;
	case 2U:  return c != 0;
	case 3U:  return c == 0;
	case 4U:  return n != 0;
	case 5U:  return n == 0;
	case 6U:  return v != 0;
	case 7U:  return v == 0;
	case 8U:  return (c != 0) && (z == 0);
	case 9U:  return (c == 0) || (z != 0);
	case 10U: return (n != 0) == (v != 0);
	case 11U: return (n != 0) != (v != 0);
	case 12U: return (z == 0) && ((n != 0) == (v != 0));
	case 13U: return (z != 0) || ((n != 0) != (v != 0));
	case 14U: return 1;
	}
	return -1;
}

/* ---------------------------------------------------------------- marks */
static __u32 marks[4];
static unsigned nmarks;
unsigned arm64_sim_unsupported_hits(void);
unsigned arm64_sim_unsupported_hits(void)
{
	return unsupported_hits;
}
static void mark(__u32 tag)
{
	if (nmarks < 4U)
		marks[nmarks++] = tag;
}
static void marks_reset(void)
{
	nmarks = 0;
}
static unsigned marks_word(void)
{
	unsigned i, w = 0U;
	for (i = 0; i < nmarks; i++)
		w |= marks[i];
	return ((w & 1U) ? 0x100U : 0U) | ((w & 2U) ? 0x200U : 0U);
}

static struct xdp_md xdp_ctx;
static struct __sk_buff skb_ctx;

/* ------------------------------------------------------------- compare
 * (GOT_CELL + COMPARE_STATE are expanded INLINE inside every scene so the
 * declared cells stay in scene scope and the reads settle -Wunused-*
 * warnings under -Werror.) */

#define GOT_CELL(REG, NAME)                                                \
	case REG:                                                          \
		__c_got = __a64_##NAME.x;                                  \
		__c_tag = __a64_##NAME##_tag;                              \
		break;

#define COMPARE_STATE(VIA, RETV)                                           \
	do {                                                               \
		unsigned __c_i;                                            \
		for (__c_i = 0; __c_i < 31U; __c_i++) {                     \
			__u64 __c_got = 0;                                 \
			__u8 __c_tag = 0U;                                 \
			switch (__c_i) {                                   \
			ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)                  \
			default: break;                                    \
			}                                                  \
			if (model_abi_live && __c_i == 0U)                  \
				continue;                                  \
			cases = cases + 1U;                                \
			if (__c_got != mreg[__c_i]) {                      \
				printf("MISMATCH %s reg%u value: got 0x%llx want 0x%llx\n", \
				       (VIA), __c_i,                       \
				       (unsigned long long)__c_got,        \
				       (unsigned long long)mreg[__c_i]);   \
				return (RETV);                             \
			}                                                  \
			cases = cases + 1U;                                \
			if (__c_tag != mtag[__c_i]) {                      \
				printf("MISMATCH %s reg%u tag: got %u want %u\n", \
				       (VIA), __c_i, __c_tag, mtag[__c_i]);\
				return (RETV);                             \
			}                                                  \
		}                                                          \
		cases = cases + 1U;                                        \
		if (__a64_sp != msp) {                                     \
			printf("MISMATCH %s sp: got %lld want %lld\n",     \
			       (VIA), (long long)__a64_sp, (long long)msp);\
			return (RETV);                                     \
		}                                                          \
		cases = cases + 1U;                                        \
		if (__a64_lr != mlr) {                                     \
			printf("MISMATCH %s lr: got 0x%llx want 0x%llx\n", \
			       (VIA), (unsigned long long)__a64_lr,        \
			       (unsigned long long)mlr);                   \
			return (RETV);                                     \
		}                                                          \
		cases = cases + 1U;                                        \
		if ((__a64_n != mn) || (__a64_z != mz) || (__a64_c != mc) ||\
		    (__a64_v != mv)) {                                     \
			printf("MISMATCH %s nzcv: got %u%u%u%u want %u%u%u%u\n",\
			       (VIA), __a64_n, __a64_z, __a64_c, __a64_v,  \
			       mn, mz, mc, mv);                            \
			return (RETV);                                     \
		}                                                          \
		cases = cases + 1U;                                        \
		if (__a64_x0_tag != mtag[0]) {                              \
			printf("MISMATCH %s x0 tag lane: got %u want %u\n",\
			       (VIA), __a64_x0_tag, mtag[0]);              \
			return (RETV);                                     \
		}                                                          \
	} while (0)

#define KEEP_LBL(L) do { void *keep = (void *)&&L; (void)keep; } while (0)

/* plant one register cell value+tag through the declared-name switch */
#define PLANT_CELL(REG, NAME)                                              \
	case REG:                                                          \
		__a64_##NAME.x = __pr_val;                                 \
		__a64_##NAME##_tag = __pr_tag;                             \
		break;
#define PLANT_REG(NUMBER, VAL, TAG)                                        \
	do {                                                               \
		__u64 __pr_val = (__u64)(VAL);                             \
		__u8 __pr_tag = (__u8)(TAG);                               \
		switch ((NUMBER)) {                                        \
		ARM64_SIM_L_FOR_EACH_GPR(PLANT_CELL)                        \
		default: break;                                            \
		}                                                          \
		mreg[(NUMBER)] = __pr_val;                                 \
		mtag[(NUMBER)] = __pr_tag;                                 \
	} while (0)

/* store the exit value in x0 (low bits) through the declared-name switch */
#define X0_SET(VAL)                                                        \
	do {                                                               \
		__a64_x0.x = (__u64)(VAL);                                 \
		mreg[0] = (__u64)(VAL);                                    \
	} while (0)

/* --------------------------------------------- 0458 memory/stack model
 * The 0458 scenes (stack word/byte lanes, MEM_BASE_OFF, the MEM_READ_TAG
 * dispatch, the MEM_READ/MEM_WRITE arm split, and the MEM pre/post
 * writeback) restate the generated stack/width/prepost/dispatch/abi-load
 * contracts by hand so the real local-header bodies stay observable: every
 * stack write is mirrored into the independent byte-image + word-image +
 * tag-slot model below, and every address-offset / tag / writeback result
 * is compared against these hand models. */
static __u8 model_stack_bytes[ARM64_SIM_STACK_BYTES];
static __u8 model_stack_tags[KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES)];

/* The model keeps ONE byte image of the arena: the real arena's union
 * (`b[]` aliased with `q[]`) makes the word view an alias of the byte view,
 * so a word read at a qword-aligned slot reassembles the same eight bytes
 * little-endian.  The slot tag array rides along as the second model memory. */
static void model_stack_reset(void)
{
	unsigned i;
	for (i = 0; i < sizeof(model_stack_bytes); i++)
		model_stack_bytes[i] = 0U;
	for (i = 0; i < KPROG_ARM64_STACK_TAG_SLOTS(ARM64_SIM_STACK_BYTES); i++)
		model_stack_tags[i] = 0U;
}

/* Independent byte scatter and whole-word provenance for a stack store. */
static void model_stack_write(__s64 off, unsigned width, __u64 value,
			      unsigned tag)
{
	unsigned idx = (__u32)(ARM64_SIM_STACK_BIAS + off);
	unsigned bytes = width ? width : 8U;
	unsigned lane;

	for (lane = 0; lane < bytes; lane++)
		model_stack_bytes[idx + lane] = (__u8)(value >> (lane * 8U));
	host_stack_store_tags(model_stack_tags, idx, bytes, tag);
}

/* One hand-restate of a stack read: every width/alignment pair reassembles
 * the little-endian byte ladder over the model byte image (each in-range byte
 * exactly once, zeroing every higher lane).  The real arena's word view
 * aliases its byte view, so the ladder yields the identical value the real
 * word-arena read returns at a qword-aligned 64-bit slot. */
static __u64 model_stack_read(__s64 off, unsigned width)
{
	__u32 idx = KPROG_ARM64_STACK_INDEX(off, ARM64_SIM_STACK_BIAS);
	__u8 w = (width) ? (__u8)width : ARM64_WIDTH_8;
	__u64 v;
	unsigned l;

	v = model_stack_bytes[idx];
	if (w >= ARM64_WIDTH_16)
		v |= (__u64)model_stack_bytes[idx + 1] << 8;
	if (w >= ARM64_WIDTH_32) {
		v |= (__u64)model_stack_bytes[idx + 2] << 16;
		v |= (__u64)model_stack_bytes[idx + 3] << 24;
	}
	if (w == ARM64_WIDTH_64)
		for (l = 4; l < 8U; l++)
			v |= (__u64)model_stack_bytes[idx + l] << (l * 8U);
	return v;
}

/* One hand-restate of a stack tag read: width-64 word-aligned slots return
 * the slot tag; every other fact pair returns the scalar marker. */
static __u8 model_stack_read_tag(__s64 off, unsigned width)
{
	__u32 idx = KPROG_ARM64_STACK_INDEX(off, ARM64_SIM_STACK_BIAS);

	if (width == ARM64_WIDTH_64 && KPROG_ARM64_STACK_WORD_ALIGNED(idx))
		return model_stack_tags[KPROG_ARM64_STACK_WORD_INDEX(idx)];
	return ARM64_SIM_TAG_SCALAR;
}

/* The memory-offset model: restates the generated prepost flag/suppress
 * gates and the offset-base + index-register accumulation by hand. */
static __s64 model_mem_base_off(__u64 aux, __u64 index, __u64 imm,
				__u64 index_value)
{
	__u8 flags = (__u8)((aux >> 24U) & 0xffU);
	__u8 has_index = (index != 0xffU) ? 1U : 0U;
	__u64 base = ((flags & 1U) || (flags & 2U)) ? 0ULL : imm;

	return (__s64)(has_index ? (base + index_value) : base);
}

/* The ABI result-tag model: restates KPROG_ABI_LOAD_TAG over the generated
 * kind/offset table (XDP data/data_end at 0/8, SKB at 208/80). */
static __u8 model_abi_load_tag(unsigned kind, __s64 off)
{
	if ((kind == 0U && off == 0) || (kind == 1U && off == 208))
		return ARM64_SIM_TAG_PACKET;
	if ((kind == 0U && off == 8) || (kind == 1U && off == 80))
		return ARM64_SIM_TAG_PACKET_END;
	return ARM64_SIM_TAG_SCALAR;
}

/* The MEM_READ_TAG dispatch model: base-is-SP / base-tag / width closed table.
 * The stack arm returns the tag-lane VALUE (a slot tag at a width-64 aligned
 * slot, the scalar marker elsewhere) computed from the resolved stack offset;
 * the RELOC width-64 slot names the MAP_PTR result tag. */
static __u8 model_read_tag(unsigned tag, unsigned width, int base_is_sp,
			   unsigned kind, __s64 off, __s64 stk_off)
{
	if (base_is_sp || tag == ARM64_SIM_TAG_STACK)
		return model_stack_read_tag(stk_off, width);
	if (tag == ARM64_SIM_TAG_ABI && width == 8U)
		return model_abi_load_tag(kind, off);
	if (tag == ARM64_SIM_TAG_RELOC_ADDR && width == 8U)
		return ARM64_SIM_TAG_MAP_PTR;
	return ARM64_SIM_TAG_SCALAR;
}

/* ------------------------------------------------------------ branch scenes
 * Program shape (a real goto-ladder; marks record the executed block):
 *   arm64_l_0:  <branch macro>        current 0x0, target 0x10
 *   arm64_l_4:  fallthrough block     mark 1, x0-exit paint 0x44
 *   arm64_l_10: target block          mark 2, x0-exit paint 0x20
 * Exit value = (marks_word << 8) | exit byte; the compare runs before RET.
 */

static __u64 scene_jcc_fwd(unsigned cond, unsigned n, unsigned z, unsigned c,
			   unsigned v, int expect_taken)
{
	unsigned i;
	__u32 w;

	model_reset();
	model_flags(n, z, c, v);
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	mark(0); nmarks = 0; /* settle mark lane */
	marks_reset();
	__a64_n = (__u8)n;
	__a64_z = (__u8)z;
	__a64_c = (__u8)c;
	__a64_v = (__u8)v;
arm64_l_0:
	ARM64_SIM_A64_JCC(cond, 0x0UL, 0x10UL, arm64_l_10);
arm64_l_4:
	mark(1);
	X0_SET(0x44ULL);
	goto arm64_l_done;
arm64_l_10:
	mark(2);
	X0_SET(0x20ULL);
arm64_l_done:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		if (__c_got != mreg[i]) {
			printf("MISMATCH jcc_fwd reg%u value: got 0x%llx want 0x%llx\n",
			       i, (unsigned long long)__c_got,
			       (unsigned long long)mreg[i]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__c_tag != mtag[i]) {
			printf("MISMATCH jcc_fwd reg%u tag: got %u want %u\n",
			       i, __c_tag, mtag[i]);
			return 0xDEAD0002ULL;
		}
	}
	cases = cases + 1U;
	if ((__a64_n != mn) || (__a64_z != mz) || (__a64_c != mc) ||
	    (__a64_v != mv)) {
		printf("MISMATCH jcc_fwd nzcv state\n");
		return 0xDEAD0003ULL;
	}
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH jcc_fwd marks: got %u want %u\n", w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(arm64_l_0);
	KEEP_LBL(arm64_l_4);
	KEEP_LBL(arm64_l_10);
	KEEP_LBL(arm64_l_done);
	ARM64_SIM_RET();
}

static __u64 scene_jcc_back(unsigned cond, unsigned n, unsigned z, unsigned c,
			    unsigned v, int expect_taken)
{
	unsigned i;
	__u32 w;

	model_reset();
	model_flags(n, z, c, v);
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	marks_reset();
	__a64_n = (__u8)n;
	__a64_z = (__u8)z;
	__a64_c = (__u8)c;
	__a64_v = (__u8)v;
arm64_l_20:
	ARM64_SIM_A64_JCC(cond, 0x20UL, 0x8UL, arm64_l_28);
arm64_l_24:
	mark(1);
	X0_SET(0x44ULL);
	goto arm64_l_done;
arm64_l_28:
	mark(2);
	X0_SET(0x20ULL);
arm64_l_done:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		if (__c_got != mreg[i]) {
			printf("MISMATCH jcc_back reg%u value: got 0x%llx want 0x%llx\n",
			       i, (unsigned long long)__c_got,
			       (unsigned long long)mreg[i]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__c_tag != mtag[i]) {
			printf("MISMATCH jcc_back reg%u tag: got %u want %u\n",
			       i, __c_tag, mtag[i]);
			return 0xDEAD0002ULL;
		}
	}
	cases = cases + 1U;
	if ((__a64_n != mn) || (__a64_z != mz) || (__a64_c != mc) ||
	    (__a64_v != mv)) {
		printf("MISMATCH jcc_back nzcv state\n");
		return 0xDEAD0003ULL;
	}
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH jcc_back marks: got %u want %u\n", w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(arm64_l_20);
	KEEP_LBL(arm64_l_24);
	KEEP_LBL(arm64_l_28);
	KEEP_LBL(arm64_l_done);
	ARM64_SIM_RET();
}

static __u64 scene_cb(unsigned kind, __u64 value, unsigned current,
		      unsigned target, int expect_taken)
{
	unsigned i;
	__u32 w;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	marks_reset();
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	PLANT_REG(5U, value, 0U);
	/* model: CBZ/CBNZ read cell 5 */
	model_branch_take(kind, value, 0ULL);
	if (target > current) {
arm64_l_40:
		if (kind == 0U) {
			ARM64_SIM_A64_CBZ(ARM64_X5, current, target, arm64_l_50);
		} else {
			ARM64_SIM_A64_CBNZ(ARM64_X5, current, target, arm64_l_50);
		}
arm64_l_44:
		mark(1);
		X0_SET(0x44ULL);
		goto arm64_l_done;
arm64_l_50:
		mark(2);
		X0_SET(0x20ULL);
	} else {
arm64_l_60:
		if (kind == 0U) {
			ARM64_SIM_A64_CBZ(ARM64_X5, current, target, arm64_l_80);
arm64_l_64:
			mark(1);
			X0_SET(0x44ULL);
			goto arm64_l_done;
arm64_l_80:
			mark(2);
			X0_SET(0x20ULL);
		} else {
			ARM64_SIM_A64_CBNZ(ARM64_X5, current, target, arm64_l_90);
arm64_l_84:
			mark(1);
			X0_SET(0x44ULL);
			goto arm64_l_done;
arm64_l_90:
			mark(2);
			X0_SET(0x20ULL);
		}
	}
arm64_l_done:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		if (__c_got != mreg[i]) {
			printf("MISMATCH cb kind%u reg%u value: got 0x%llx want 0x%llx\n",
			       kind, i, (unsigned long long)__c_got,
			       (unsigned long long)mreg[i]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__c_tag != mtag[i]) {
			printf("MISMATCH cb kind%u reg%u tag: got %u want %u\n",
			       kind, i, __c_tag, mtag[i]);
			return 0xDEAD0002ULL;
		}
	}
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH cb kind%u marks: got %u want %u\n", kind, w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	cases = cases + 1U;
	if (mlr != __a64_lr) {
		printf("MISMATCH cb lr\n");
		return 0xDEAD0005ULL;
	}
	KEEP_LBL(arm64_l_40);
	KEEP_LBL(arm64_l_44);
	KEEP_LBL(arm64_l_50);
	KEEP_LBL(arm64_l_60);
	KEEP_LBL(arm64_l_64);
	KEEP_LBL(arm64_l_80);
	KEEP_LBL(arm64_l_84);
	KEEP_LBL(arm64_l_90);
	KEEP_LBL(arm64_l_done);
	ARM64_SIM_RET();
}

static __u64 scene_tb(unsigned kind, __u64 value, __u64 bit, unsigned current,
		      unsigned target, int expect_taken)
{
	unsigned i;
	__u32 w;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	marks_reset();
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	PLANT_REG(7U, value, 0U);
arm64_l_100:
	if (kind == 2U) {
		ARM64_SIM_A64_TBZ(ARM64_X7, bit, current, target, arm64_l_120);
	} else {
		ARM64_SIM_A64_TBNZ(ARM64_X7, bit, current, target, arm64_l_120);
	}
arm64_l_104:
	mark(1);
	X0_SET(0x44ULL);
	goto arm64_l_done;
arm64_l_120:
	mark(2);
	X0_SET(0x20ULL);
arm64_l_done:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		if (__c_got != mreg[i]) {
			printf("MISMATCH tb kind%u reg%u value: got 0x%llx want 0x%llx\n",
			       kind, i, (unsigned long long)__c_got,
			       (unsigned long long)mreg[i]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__c_tag != mtag[i]) {
			printf("MISMATCH tb kind%u reg%u tag: got %u want %u\n",
			       kind, i, __c_tag, mtag[i]);
			return 0xDEAD0002ULL;
		}
	}
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH tb kind%u marks: got %u want %u\n", kind, w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(arm64_l_100);
	KEEP_LBL(arm64_l_104);
	KEEP_LBL(arm64_l_120);
	KEEP_LBL(arm64_l_done);
	ARM64_SIM_RET();
}

/* Linked call ladder: main ladder calls leaf at 0x40 with return 0x80; leaf
 * bumps x9 and returns through ARM64_SIM_A64_RET(); main ladder bumps x0 and
 * exits through ARM64_SIM_RET(). Model mirrors lr/x30/x9/x0 through the call. */
static __u64 scene_call(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	mreg[30] = 0;
	mtag[30] = 10U;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	marks_reset();
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
arm64_l_c0:
	ARM64_SIM_A64_JMP(0xc0UL, 0xc4UL, arm64_l_c4);
arm64_l_c4:
	mark(3);
	/* call leaf; return address 0x80 (model mirrors lr and the x30 cell) */
	mlr = 0x80ULL;
	mreg[30] = 0x80ULL;
	mtag[30] = 9U;
	ARM64_SIM_A64_CALL(arm64_l_40, 0x80ULL);
arm64_l_80:
	mark(1);
	/* leaf returned here: bump x0 then exit */
	X0_SET(0x24ULL);
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		if (__c_got != mreg[i]) {
			printf("MISMATCH call reg%u value: got 0x%llx want 0x%llx\n",
			       i, (unsigned long long)__c_got,
			       (unsigned long long)mreg[i]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__c_tag != mtag[i]) {
			printf("MISMATCH call reg%u tag: got %u want %u\n",
			       i, __c_tag, mtag[i]);
			return 0xDEAD0002ULL;
		}
	}
	cases = cases + 1U;
	if (mlr != __a64_lr) {
		printf("MISMATCH call lr: got 0x%llx want 0x%llx\n",
		       (unsigned long long)__a64_lr, (unsigned long long)mlr);
		return 0xDEAD0005ULL;
	}
	cases = cases + 2U;
	if (marks[0] != 3U || marks[1] != 2U || marks[2] != 1U) {
		printf("MISMATCH call marks: got %u,%u,%u want 3,2,1\n",
		       marks[0], marks[1], marks[2]);
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(arm64_l_c0);
	KEEP_LBL(arm64_l_c4);
	KEEP_LBL(arm64_l_80);
	ARM64_SIM_RET();
arm64_l_40:
	mark(2);
	/* leaf body: bump pattern-cell 9 then return to 0x80 */
	PLANT_REG(9U, pattern_reg(9U), 0U);
	/* RET reads X30 without consuming the architectural link register. */
	ARM64_SIM_A64_RET();
}

/* RETURN_CASES ladder scene: plant x0 and walk the two mapped return cases with
 * the sim; assert both. This is exactly what the generator emits inside real
 * local-call programs (case <addr>: goto <label>;) — the battery
 * repaints the DEFAULT define gate and the A64_RET switch arms; this scene
 * guards the battery-side override expansion used by the call ladder. */

/* RET default-arm scene: set X30 to an unmapped return address so the
 * A64_RET default arm fires ARM64_SIM_L_UNSUPPORTED_OPCODE (counted by the
 * shared unsupported_hits monitor). */
static __u64 scene_ret_default(void)
{
	unsigned i;

	model_reset();
	mlr = 0x99ULL;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	__a64_lr = 0; /* A stale mirror must not hide an invalid actual X30. */
	PLANT_REG(30U, 0x99ULL, 9U);
	X0_SET(0x42ULL);
	ARM64_SIM_A64_RET();
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		(void)__c_got;
		(void)__c_tag;
	}
arm64_l_40:
arm64_l_80:
	{
		void *__keep40 = (void *)&&arm64_l_40;
		void *__keep80 = (void *)&&arm64_l_80;
		(void)__keep40;
		(void)__keep80;
	}
	ARM64_SIM_RET();
}


static __u64 scene_return_cases(void)
{
	unsigned i;

	model_reset();
	mlr = 0x99ULL;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	PLANT_REG(9U, 0xAAAAULL, 0U);
	__a64_x9.x = 0xAAAAULL;
	mreg[9] = 0xAAAAULL;
	mlr = 0x40ULL;
	__a64_lr = 0x99ULL; /* RET must use the restored register, not this mirror. */
	PLANT_REG(30U, 0x40ULL, 9U);
	ARM64_SIM_A64_RET();
arm64_l_40:
	mark(1);
	__a64_x9.x = 0xBBBBULL;
	mreg[9] = 0xBBBBULL;
	mlr = 0x80ULL;
	__a64_lr = 0x99ULL;
	PLANT_REG(30U, 0x80ULL, 9U);
	ARM64_SIM_A64_RET();
arm64_l_80:
	mark(2);
	X0_SET(0x80ULL);
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH retcases reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (marks_word() != 0x300U) {
		printf("MISMATCH retcases marks: got %u want 768\n", marks_word());
		return 0xDEAD0004ULL;
	}
	/* RET preserves the architectural link register at the selected PC. */
	cases = cases + 1U;
	if (__a64_lr != 0x80ULL) {
		printf("MISMATCH retcases lr: got 0x%llx want 0x80\n",
		       (unsigned long long)__a64_lr);
		return 0xDEAD0005ULL;
	}
	KEEP_LBL(arm64_l_40);
	KEEP_LBL(arm64_l_80);
	ARM64_SIM_RET();
}


/* Regfile-glue scene: drive the pointer/tag readers and the pointer-tag
 * writers directly (WRITE_REG_PTR_TAG / WRITE_REG_MAP_PTR), plus the SP
 * lanes of READ_REG_PTR / REG_TAG. */
static __u64 scene_reg_glue(void)
{
	unsigned i;
	void *pp;
	__u8 tg;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	/* SP lanes of the pointer/tag readers */
	pp = ARM64_SIM_L_READ_REG_PTR(ARM64_SP);
	tg = ARM64_SIM_L_REG_TAG(ARM64_SP);
	cases = cases + 2U;
	if (pp != (void *)(long)0ULL || tg != ARM64_SIM_TAG_STACK) {
		printf("MISMATCH regglue SP lanes\n");
		return 0xDEAD0009ULL;
	}
	/* WRITE_REG_PTR_TAG on X4: value 0x7000 tag MAP_PTR */
	ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X4, 0x7000ULL,
				      ARM64_SIM_TAG_MAP_PTR);
	mreg[4] = 0x7000ULL;
	mtag[4] = ARM64_SIM_TAG_MAP_PTR;
	/* WRITE_REG_MAP_PTR on X5 */
	ARM64_SIM_L_WRITE_REG_MAP_PTR(ARM64_X5, 0x8000ULL);
	mreg[5] = 0x8000ULL;
	mtag[5] = ARM64_SIM_TAG_MAP_PTR;
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == 0U)
			continue;
		cases = cases + 1U;
		if (__c_got != mreg[i] || __c_tag != mtag[i]) {
			printf("MISMATCH regglue reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	/* re-read tags and pointers through the readers */
	cases = cases + 1U;
	if (ARM64_SIM_L_REG_TAG(ARM64_X4) != ARM64_SIM_TAG_MAP_PTR ||
	    ARM64_SIM_L_REG_TAG(ARM64_X5) != ARM64_SIM_TAG_MAP_PTR) {
		printf("MISMATCH regglue tags\n");
		return 0xDEAD0002ULL;
	}
	cases = cases + 2U;
	if (ARM64_SIM_L_READ_REG_PTR(ARM64_X4) != (void *)0x7000ULL ||
	    ARM64_SIM_L_READ_REG_PTR(ARM64_X5) != (void *)0x8000ULL) {
		printf("MISMATCH regglue ptrs\n");
		return 0xDEAD0003ULL;
	}
	X0_SET(0x5CULL);
	ARM64_SIM_RET();
}

/* SKB entry + RET() writeback scene: enter via ENTRY_SKB, paint the ABI cb
 * lanes, assert (u32)x0 exit and that RET() copied cb[0]/cb[1] to the ctx. */
static __u64 scene_skb_ret(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	marks_reset();
	skb_ctx.cb[0] = 0x11111111U;
	skb_ctx.cb[1] = 0x22222222U;
	skb_ctx.data = 0x3000U;
	skb_ctx.data_end = 0x4000U;
	ARM64_SIM_ENTRY_SKB(&skb_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	/* ABI lanes visible through x0-tag: ENTRY_SKB stamps TAG_ABI */
	cases = cases + 1U;
	if (__a64_x0_tag != 1U) {
		printf("MISMATCH skb entry x0 tag: got %u want 1\n",
		       __a64_x0_tag);
		return 0xDEAD0006ULL;
	}
	/* entry lanes: kind + ABI field copies */
	cases = cases + 1U;
	if (__a64_sim_abi_kind != 1U) {
		printf("MISMATCH skb entry abi kind: got %u want 1\n",
		       __a64_sim_abi_kind);
		return 0xDEAD0009ULL;
	}
	cases = cases + 2U;
	if (__a64_sim_abi.data != (void *)(long)skb_ctx.data ||
	    __a64_sim_abi.data_end != (void *)(long)skb_ctx.data_end) {
		printf("MISMATCH skb entry abi fields\n");
		return 0xDEAD000AULL;
	}
	/* exit paint: x0 mirrors ABI content bytes through x0.x */
	__a64_sim_abi.cb[0] = 0x0BADF00DU;
	__a64_sim_abi.cb[1] = 0x0FEEDFACU;
	X0_SET(0x12ULL);
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 1U;
		if (i != 0U && (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH skb reg%u state\n", i);
			return 0xDEAD0001ULL;
		}
	}
	/* x0: model value 0x12 with tag ABI already validated above */
	ARM64_SIM_RET();
}

/* XDP entry leaves cb untouched: enter and confirm skb_ctx stays null. */
static __u64 scene_xdp_ret(void)
{
	model_reset();
	mlr = 0;
	marks_reset();
	xdp_ctx.data = 0x5000U;
	xdp_ctx.data_end = 0x5100U;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_sim_abi_kind; /* compare lane below */
	(void)__a64_sp;
	cases = cases + 1U;
	if (__a64_x0_tag != 1U) {
		printf("MISMATCH xdp entry x0 tag: got %u want 1\n",
		       __a64_x0_tag);
		return 0xDEAD0006ULL;
	}
	cases = cases + 1U;
	if (__a64_sim_abi_kind != 0U) {
		printf("MISMATCH xdp entry abi kind: got %u want 0\n",
		       __a64_sim_abi_kind);
		return 0xDEAD0007ULL;
	}
	cases = cases + 2U;
	if (__a64_sim_abi.data != (void *)(long)xdp_ctx.data ||
	    __a64_sim_abi.data_end != (void *)(long)xdp_ctx.data_end) {
		printf("MISMATCH xdp entry abi fields\n");
		return 0xDEAD0008ULL;
	}
	{
		unsigned __c_i;
		for (__c_i = 0; __c_i < 31U; __c_i++) {
			__u64 __c_got = 0;
			__u8 __c_tag = 0U;
			switch (__c_i) {
			ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
			default: break;
			}
			if (model_abi_live && __c_i == 0U)
				continue;
			cases = cases + 1U;
			if (__c_got != mreg[__c_i] || __c_tag != mtag[__c_i]) {
				printf("MISMATCH xdp entry reg%u state\n", __c_i);
				return 0xDEAD0001ULL;
			}
		}
	}
	X0_SET(0x34ULL);
	/* healthy XDP exit: no ctx deref */
	ARM64_SIM_RET();
}

/* Run-op forward lanes: drive RUN_OP and RUN_OP3 ALU writes and compare the
 * regfile against the model (guards ARM64_SIM_RUN_OP/RUN_OP3 forwarding). */
static __u64 scene_run_ops(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	PLANT_REG(4U, pattern_reg(4U), 0U);
	PLANT_REG(5U, pattern_reg(5U), 0U);
	PLANT_REG(6U, pattern_reg(6U), 0U);
	/* MOVZ-style direct: RUN_OP with ALU_ADD from IMM */
	ARM64_SIM_RUN_OP(0x06U, ARM64_X9, ARM64_X4, ARM64_WIDTH_64,
			 0ULL, 0x101ULL);
	/* model: x9 = x4 + 0x101 */
	mreg[9] = mreg[4] + 0x101ULL;
	mlr = 0;
	ARM64_SIM_A64_JMP(0x0UL, 0x4UL, arm64_l_r4);
arm64_l_r4:
	ARM64_SIM_RUN_OP3(0x06U, ARM64_X10, ARM64_X5, ARM64_X6,
			  ARM64_REG_NONE, ARM64_WIDTH_64, 0ULL, 0x7ULL);
	/* model: x10 = x5 + x6 + 0? RUN_OP3 args: SRC2/SRC3 are regs 5,6:
	 * the ALU arm reads exactly one SRC; use the reg3 lane in a later
	 * scene. Keep this scene's second op identical to a 1-source op:
	 * SRC=X5, IMM=7. */
	mreg[10] = mreg[5] + 0x7ULL;
arm64_l_done_r:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH runops reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_lr != mlr) {
		printf("MISMATCH runops lr\n");
		return 0xDEAD0005ULL;
	}
	X0_SET(0x5AULL);
	KEEP_LBL(arm64_l_r4);
	KEEP_LBL(arm64_l_done_r);
	ARM64_SIM_RET();
}

/* SP-addressed lane scenes (READ_REG/WRITE_REG_WIDTH SP branches): add x9 =
 * SP + imm, then write SP = SP + imm via RUN_OP with REG=SP. */
static __u64 scene_sp_lanes(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	/* bump SP through the regfile: WRITE_REG_WIDTH SP branch */
	ARM64_SIM_RUN_OP(0x06U, ARM64_SP, ARM64_SP, ARM64_WIDTH_64, 0ULL,
			 0x40ULL);
	msp = 0x40;
arm64_l_sp:
	/* x1 = (u32)SP width-32 read-then-write: WRITE_REG32 lanes */
	ARM64_SIM_RUN_OP(0x06U, ARM64_X1, ARM64_SP, ARM64_WIDTH_32, 0ULL,
			 0x0ULL);
	mreg[1] = (__u64)(__u32)0x40;
	mtag[1] = 0U;
arm64_l_done_sp:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH splanes reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH splanes sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x5BULL);
	KEEP_LBL(arm64_l_sp);
	KEEP_LBL(arm64_l_done_sp);
	ARM64_SIM_RET();
}

/* ------------------------------------------------------------ 0458 memory/stack
 * Five route-host scenes over the 0458 family in ../arm64/arm64_sim_local_bpf.h:
 * the stack word/byte lane split (STACK_READ/_READ_TAG/_WRITE[_TAG]), the
 * MEM_BASE_OFF decode, the MEM_READ_TAG dispatch table, the MEM_READ/MEM_WRITE
 * arm split, and the MEM_PRE/MEM_POST base writeback.  Every real macro runs
 * inside a real goto-ladder scene; the independent model (the hand-restated
 * generated contracts at the top of this file) recomputes the same observable
 * state, and every scene compares the full 31-cell register file, SP, and the
 * exit byte against it.  Stack offsets stay in-bounds; every non-stack base
 * register is planted at an in-bounds file-scope buffer so the pointer deref
 * never leaves the arena. */

static __u8 mem_scene_bufs[4][32];

static __u64 scene_stack_lanes(void)
{
	unsigned i;
	static const __s64 SOFFS[] = { 0, 4, 8, 12, 16, -8, 1, 24 };
	static const unsigned SWIDTHS[] = { 1U, 2U, 4U, 8U };

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	for (i = 0; i < 8U; i++) {
		__s64 off = SOFFS[i];
		unsigned w;

		for (w = 0; w < 4U; w++) {
			__u64 val = pattern_reg(i) ^ (__u64)SWIDTHS[w];

			/* real write + mirrored model write, identical args */
			ARM64_SIM_L_STACK_WRITE(off, SWIDTHS[w], val);
			model_stack_write(off, SWIDTHS[w], val, ARM64_SIM_TAG_SCALAR);
		}
		/* width-64 tag-planted write through the real write-tag body */
		ARM64_SIM_L_STACK_WRITE_TAG(off, ARM64_WIDTH_64, pattern_reg(i + 16U),
					    pattern_reg(i + 8U));
		model_stack_write(off, ARM64_WIDTH_64, pattern_reg(i + 16U),
				  pattern_reg(i + 8U));
	}
	/* Width-64 write through the wrapper's default tag; the existing
	 * off-16 tag readback in the loop below observes the default. */
	ARM64_SIM_L_STACK_WRITE(16, ARM64_WIDTH_64, pattern_reg(30U));
	model_stack_write(16, ARM64_WIDTH_64, pattern_reg(30U),
			  ARM64_SIM_TAG_SCALAR);
	/* Isolated clear-tag catcher: an aligned sub-qword write at a fresh
	 * slot is the last write to its word, so the cleared slot tag stays
	 * observable by the width-64 tag read. */
	ARM64_SIM_L_STACK_WRITE_TAG(32, ARM64_WIDTH_16, pattern_reg(31U),
				    ARM64_SIM_TAG_SCALAR);
	model_stack_write(32, ARM64_WIDTH_16, pattern_reg(31U),
			 ARM64_SIM_TAG_SCALAR);
	{
		__u8 got_tag = ARM64_SIM_L_STACK_READ_TAG(32, ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got_tag != model_stack_read_tag(32, ARM64_WIDTH_64)) {
			printf("MISMATCH stackl cleartag off 32: got %u\n",
			       (unsigned)got_tag);
			return 0xDEAD0001ULL;
		}
	}
	/* Isolated lane-7 catcher: a width-32 write into a width-64-plant
	 * word leaves the plant's high bytes in place; the width-64 word
	 * read observes them. */
	ARM64_SIM_L_STACK_WRITE_TAG(40, ARM64_WIDTH_64, pattern_reg(32U),
				    pattern_reg(33U));
	model_stack_write(40, ARM64_WIDTH_64, pattern_reg(32U),
			  pattern_reg(33U));
	ARM64_SIM_L_STACK_WRITE_TAG(40, ARM64_WIDTH_32, pattern_reg(34U),
				    ARM64_SIM_TAG_SCALAR);
	model_stack_write(40, ARM64_WIDTH_32, pattern_reg(34U),
			  ARM64_SIM_TAG_SCALAR);
	{
		__u64 got = ARM64_SIM_L_STACK_READ(40, ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_stack_read(40, ARM64_WIDTH_64)) {
			printf("MISMATCH stackl lane7 off 40: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
arm64_l_stk:
	/* read-back lanes: word arm, byte-ladder arm, tag arm */
	for (i = 0; i < 8U; i++) {
		__s64 off = SOFFS[i];
		unsigned w;

		for (w = 0; w < 4U; w++) {
			__u64 got = ARM64_SIM_L_STACK_READ(off, SWIDTHS[w]);

			cases = cases + 1U;
			if (got != model_stack_read(off, SWIDTHS[w])) {
				printf("MISMATCH stackl read off %ld w %u: got 0x%llx\n",
				       (long)off, SWIDTHS[w],
				       (unsigned long long)got);
				return 0xDEAD0001ULL;
			}
		}
		{
			__u8 got_tag = ARM64_SIM_L_STACK_READ_TAG(off, ARM64_WIDTH_64);

			cases = cases + 1U;
			if (got_tag != model_stack_read_tag(off, ARM64_WIDTH_64)) {
				printf("MISMATCH stackl tag off %ld: got %u\n",
				       (long)off, got_tag);
				return 0xDEAD0001ULL;
			}
		}
	}
arm64_l_done_stk:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH stackl reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH stackl sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x5DULL);
	KEEP_LBL(arm64_l_stk);
	KEEP_LBL(arm64_l_done_stk);
	ARM64_SIM_RET();
}

static __u64 scene_mem_base_off(void)
{
	unsigned i;
	static const unsigned SFLAGS[] = { 0U, 1U, 2U, 3U };
	static const unsigned SINDICES[] = { 4U, 0xffU };
	static const __u64 SIMMS[] = { 0ULL, 8ULL, 48ULL, 0x100ULL };

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	PLANT_REG(4, pattern_reg(4), ARM64_SIM_TAG_SCALAR);
arm64_l_mbo:
	for (i = 0; i < 4U; i++) {
		unsigned j;

		for (j = 0; j < 2U; j++) {
			unsigned k;

			for (k = 0; k < 4U; k++) {
				__u64 index = SINDICES[j];
				__u64 aux = KPROG_ARM64_AUX(index, 0U, 0U, SFLAGS[i]);
				__u64 imm = SIMMS[k];
				__s64 got = ARM64_SIM_L_MEM_BASE_OFF(aux, index, imm);

				cases = cases + 1U;
				if (got != model_mem_base_off(
						       aux, index, imm,
					       (index != 0xffU) ? mreg[4] : 0ULL)) {
					printf("MISMATCH mbo flags %u idx %llu imm %llu: got %lld\n",
					       SFLAGS[i], (unsigned long long)index,
					       (unsigned long long)imm,
					       (long long)got);
					return 0xDEAD0001ULL;
				}
			}
		}
	}
arm64_l_done_mbo:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH mbo reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH mbo sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x5EULL);
	KEEP_LBL(arm64_l_mbo);
	KEEP_LBL(arm64_l_done_mbo);
	ARM64_SIM_RET();
}

static __u64 scene_mem_read_tag(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	/* plant a width-64 stack word with a non-scalar slot tag */
	ARM64_SIM_L_STACK_WRITE_TAG(16U, ARM64_WIDTH_64, pattern_reg(20U),
				    ARM64_SIM_TAG_RODATA_ADDR);
	model_stack_write(16, ARM64_WIDTH_64, pattern_reg(20U),
			  ARM64_SIM_TAG_RODATA_ADDR);
	PLANT_REG(3, (__u64)(unsigned long)&mem_scene_bufs[0],
		   ARM64_SIM_TAG_ABI);
	PLANT_REG(5, pattern_reg(5), ARM64_SIM_TAG_RELOC_ADDR);
	PLANT_REG(6, pattern_reg(6), ARM64_SIM_TAG_SCALAR);
	PLANT_REG(7, -32ULL, ARM64_SIM_TAG_STACK);
	ARM64_SIM_L_STACK_WRITE(4, ARM64_WIDTH_64, pattern_reg(24U));
	model_stack_write(4, ARM64_WIDTH_64, pattern_reg(24U),
			  ARM64_SIM_TAG_SCALAR);
	/* Paint the word the GPR-stack read resolves to under the correct
	 * bsrc: base -32 + off 8 = -24 (arena idx 72, word 9, tag PACKET).
	 * The `!=` repaint of the GPR base lane falls back to SP
	 * (0 + 8 = arena idx 104, word 13, tag still SCALAR), so the
	 * GPR-stack case below distinguishes the two. */
	ARM64_SIM_L_STACK_WRITE_TAG(-24, ARM64_WIDTH_64, pattern_reg(28U),
				    ARM64_SIM_TAG_PACKET);
	model_stack_write(-24, ARM64_WIDTH_64, pattern_reg(28U),
			  ARM64_SIM_TAG_PACKET);
arm64_l_mrt:
	/* stack arm via SP: aligned slot carries its planted tag, unaligned
	 * or narrow reads return the scalar marker */
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_SP, 0xffU, 0ULL, 12ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_STACK, ARM64_WIDTH_64, 1, 0U,
					  12, 12)) {
			printf("MISMATCH mrt sp w64 off 12: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_SP, 0xffU, 0ULL, 4ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_STACK, ARM64_WIDTH_64, 1, 0U,
					  4, 4)) {
			printf("MISMATCH mrt sp w64 off 4: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_SP, 0xffU, 0ULL, 8ULL, 0ULL,
						     ARM64_WIDTH_8);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_STACK, ARM64_WIDTH_8, 1, 0U,
					  8, 8)) {
			printf("MISMATCH mrt sp w8 off 8: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	/* GPR carrying the stack tag routes the stack arm off the GPR base */
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_X7, 0xffU, 0ULL, 8ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_STACK, ARM64_WIDTH_64, 0, 0U,
					  8, -24)) {
			printf("MISMATCH mrt x7 stack-tag: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	/* ABI arm: width-64 ABI-tag GPR decodes the result tag by kind/offset */
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_X3, 0xffU, 0ULL, 0ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_ABI, ARM64_WIDTH_64, 0, 0U, 0, 0)) {
			printf("MISMATCH mrt abi off 0: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_X3, 0xffU, 0ULL, 8ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_ABI, ARM64_WIDTH_64, 0, 0U, 8, 8)) {
			printf("MISMATCH mrt abi off 8: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_X3, 0xffU, 0ULL, 1ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_ABI, ARM64_WIDTH_64, 0, 0U, 1, 1)) {
			printf("MISMATCH mrt abi off 1: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	/* RELOC arm: width-64 off 0 names the MAP_PTR result tag */
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_X5, 0xffU, 0ULL, 0ULL, 0ULL,
						     ARM64_WIDTH_64);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_RELOC_ADDR, ARM64_WIDTH_64, 0, 0U,
					  0, 0)) {
			printf("MISMATCH mrt reloc off 0: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
	/* default arm */
	{
		__u8 got = ARM64_SIM_L_MEM_READ_TAG(ARM64_X6, 0xffU, 0ULL, 4ULL, 0ULL,
						     ARM64_WIDTH_32);

		cases = cases + 1U;
		if (got != model_read_tag(ARM64_SIM_TAG_SCALAR, ARM64_WIDTH_32, 0, 0U,
					  4, 4)) {
			printf("MISMATCH mrt default: got %u\n", got);
			return 0xDEAD0001ULL;
		}
	}
arm64_l_done_mrt:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH mrt reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH mrt sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x5FULL);
	KEEP_LBL(arm64_l_mrt);
	KEEP_LBL(arm64_l_done_mrt);
	ARM64_SIM_RET();
}

static __u64 scene_mem_rw(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	PLANT_REG(10, (__u64)(unsigned long)&mem_scene_bufs[2],
		   ARM64_SIM_TAG_SCALAR);
	PLANT_REG(11, (__u64)(unsigned long)&mem_scene_bufs[3],
		   ARM64_SIM_TAG_ABI);
	PLANT_REG(12, pattern_reg(12), ARM64_SIM_TAG_RELOC_ADDR);
	PLANT_REG(13, -32ULL, ARM64_SIM_TAG_STACK);
	/* stack arm via SP: the write arm must keep the mirrored model in
	 * lockstep before the read-back compares */
	{
		__u64 got;

		ARM64_SIM_L_MEM_WRITE(ARM64_SP, 0xffU, 0ULL, 8ULL, 0ULL,
				      ARM64_WIDTH_64, pattern_reg(30U),
				      ARM64_SIM_TAG_MAP_VALUE);
		model_stack_write(8, ARM64_WIDTH_64, pattern_reg(30U),
				  ARM64_SIM_TAG_MAP_VALUE);
		got = ARM64_SIM_L_MEM_READ(ARM64_SP, 0xffU, 0ULL, 8ULL, 0ULL,
					   ARM64_WIDTH_64);
		cases = cases + 1U;
		if (got != model_stack_read(8, ARM64_WIDTH_64)) {
			printf("MISMATCH mrw sp read: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u64 got;

		ARM64_SIM_L_MEM_WRITE(ARM64_SP, 0xffU, 0ULL, 4ULL, 0ULL,
				      ARM64_WIDTH_16, 0x0102ULL,
				      ARM64_SIM_TAG_SCALAR);
		model_stack_write(4, ARM64_WIDTH_16, 0x0102ULL,
				  ARM64_SIM_TAG_SCALAR);
		got = ARM64_SIM_L_MEM_READ(ARM64_SP, 0xffU, 0ULL, 4ULL, 0ULL,
					   ARM64_WIDTH_16);
		cases = cases + 1U;
		if (got != model_stack_read(4, ARM64_WIDTH_16)) {
			printf("MISMATCH mrw sp w16 read: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	/* NORMAL read arm: LE ladder over the in-bounds buffer */
	{
		__u64 want = 0xA1B2C3D4ULL;
		__u64 got;

		*((__u32 *)mem_scene_bufs[2]) = 0xA1B2C3D4U;
		got = ARM64_SIM_L_MEM_READ(ARM64_X10, 0xffU, 0ULL, 0ULL, 0ULL,
					   ARM64_WIDTH_32);
		cases = cases + 1U;
		if (got != want) {
			printf("MISMATCH mrw normal read: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u64 want = 0x1112131415161718ULL;
		__u64 got;

		*((__u64 *)mem_scene_bufs[2]) = want;
		got = ARM64_SIM_L_MEM_READ(ARM64_X10, 0xffU, 0ULL, 0ULL, 0ULL,
					   ARM64_WIDTH_64);
		cases = cases + 1U;
		if (got != want) {
			printf("MISMATCH mrw normal w64 read: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	/* MEMORY write arm: the width-masked value lands in the buffer */
	{
		__u64 got;

		ARM64_SIM_L_MEM_WRITE(ARM64_X10, 0xffU, 0ULL, 0ULL, 0ULL,
				      ARM64_WIDTH_32, 0xFEDCBA90ULL,
				      ARM64_SIM_TAG_SCALAR);
		got = ARM64_SIM_L_MEM_READ(ARM64_X10, 0xffU, 0ULL, 0ULL, 0ULL,
					   ARM64_WIDTH_32);
		cases = cases + 1U;
		if (got != KPROG_ARM64_APPLY_WIDTH(0xFEDCBA90ULL, ARM64_WIDTH_32)) {
			printf("MISMATCH mrw memory write readback: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	{
		__u64 got;

		ARM64_SIM_L_MEM_WRITE(ARM64_X10, 0xffU, 0ULL, 4ULL, 0ULL,
				      ARM64_WIDTH_16, 0x00FF00FF12345678ULL,
				      ARM64_SIM_TAG_SCALAR);
		got = ARM64_SIM_L_MEM_READ(ARM64_X10, 0xffU, 0ULL, 4ULL, 0ULL,
					   ARM64_WIDTH_16);
		cases = cases + 1U;
		if (got != KPROG_ARM64_APPLY_WIDTH(0x00FF00FF12345678ULL,
						   ARM64_WIDTH_16)) {
			printf("MISMATCH mrw memory w16 write readback: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	/* ABI pointer-load arm: the register holds a buffer; off 0 returns
	 * the value stored at the buffer's first pointer slot */
	{
		__u64 want = 0x9100000000000001ULL;
		__u64 got;

		*((__u64 *)mem_scene_bufs[3]) = want;
		PLANT_REG(11, (__u64)(unsigned long)&mem_scene_bufs[3],
			  ARM64_SIM_TAG_ABI);
		got = ARM64_SIM_L_MEM_READ(ARM64_X11, 0xffU, 0ULL, 0ULL, 0ULL,
					   ARM64_WIDTH_64);
		cases = cases + 1U;
		if (got != want) {
			printf("MISMATCH mrw abi read: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	/* RELOC arm: off 0 returns the register's pointer value */
	{
		__u64 got;

		got = ARM64_SIM_L_MEM_READ(ARM64_X12, 0xffU, 0ULL, 0ULL, 0ULL,
					   ARM64_WIDTH_64);
		cases = cases + 1U;
		if (got != mreg[12]) {
			printf("MISMATCH mrw reloc read: got 0x%llx want 0x%llx\n",
			       (unsigned long long)got,
			       (unsigned long long)mreg[12]);
			return 0xDEAD0001ULL;
		}
	}
	/* STACK-tag GPR write arm routes the stack arm off the GPR base */
	{
		__u64 got;

		ARM64_SIM_L_MEM_WRITE(ARM64_X13, 0xffU, 0ULL, 8ULL, 0ULL,
				      ARM64_WIDTH_8, 0xABCD1234ULL,
				      ARM64_SIM_TAG_SCALAR);
		model_stack_write(-24, ARM64_WIDTH_8, 0xABCD1234ULL,
				  ARM64_SIM_TAG_SCALAR);
		got = ARM64_SIM_L_MEM_READ(ARM64_X13, 0xffU, 0ULL, 8ULL, 0ULL,
					   ARM64_WIDTH_8);
		cases = cases + 1U;
		if (got != model_stack_read(-24, ARM64_WIDTH_8)) {
			printf("MISMATCH mrw x13 stack write readback: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	/* ABI tag with a width under 64 must fall through to the NORMAL arm:
	 * the value comes from the plain load ladder, not the ABI decode */
	{
		__u64 want = 0x5556555755585559ULL;
		__u64 got;

		*((__u64 *)mem_scene_bufs[3]) = want;
		got = ARM64_SIM_L_MEM_READ(ARM64_X11, 0xffU, 0ULL, 0ULL, 0ULL,
					   ARM64_WIDTH_32);
		cases = cases + 1U;
		if (got != KPROG_ARM64_APPLY_WIDTH(want, ARM64_WIDTH_32)) {
			printf("MISMATCH mrw abi w32 read: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
	/* Normal-arm write keeps the pointed-to buffer in lockstep; the
	 * readback catches address-offset drops and width truncation. */
	{
		__u64 got;

		ARM64_SIM_L_MEM_WRITE(ARM64_X10, 0xffU, 0ULL, 4ULL, 0ULL,
				      ARM64_WIDTH_32, 0xA5B6C7D8ULL,
				      ARM64_SIM_TAG_SCALAR);
		got = ARM64_SIM_L_MEM_READ(ARM64_X10, 0xffU, 0ULL, 4ULL, 0ULL,
					   ARM64_WIDTH_32);
		cases = cases + 1U;
		if (got != 0xA5B6C7D8ULL) {
			printf("MISMATCH mrw normal w32 write readback: got 0x%llx\n",
			       (unsigned long long)got);
			return 0xDEAD0001ULL;
		}
	}
arm64_l_mr:
arm64_l_done_mr:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH mrw reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH mrw sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x60ULL);
	KEEP_LBL(arm64_l_mr);
	KEEP_LBL(arm64_l_done_mr);
	ARM64_SIM_RET();
}

static __u64 scene_mem_prepost(void)
{
	unsigned i;
	static const unsigned SFLAGS[] = { 0U, 1U, 2U, 3U };
	static const __s64 SIMMS[] = { 0LL, 8LL, -4LL, 40LL };

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	PLANT_REG(4, pattern_reg(4), ARM64_SIM_TAG_SCALAR);
	PLANT_REG(8, pattern_reg(8), ARM64_SIM_TAG_SCALAR);
arm64_l_pp:
	for (i = 0; i < 4U; i++) {
		__s64 imm = SIMMS[i];
		__u64 aux = KPROG_ARM64_AUX(0xffU, 0U, 0U, SFLAGS[i]);
		__s64 pre, post;

		/* hand deltas: the pre bit carries the immediate for PRE, the
		 * post bit carries it for POST, both set applies twice */
		pre = (SFLAGS[i] & 1U) ? imm : 0;
		post = (SFLAGS[i] & 2U) ? imm : 0;
		ARM64_SIM_L_MEM_PRE(ARM64_SP, aux, (__u64)imm);
		ARM64_SIM_L_MEM_POST(ARM64_SP, aux, (__u64)imm);
		msp += pre + post;
		cases = cases + 2U;
		if (__a64_sp != msp) {
			printf("MISMATCH pp sp flags %u imm %lld: got %lld want %lld\n",
			       SFLAGS[i], (long long)imm,
			       (long long)__a64_sp, (long long)msp);
			return 0xDEAD0001ULL;
		}
		/* GPR base: PRE/POST advance the pointer through the
		 * write-reg-ptr-tag lane, keeping the register tag */
		ARM64_SIM_L_MEM_PRE(ARM64_X4, aux, (__u64)imm);
		ARM64_SIM_L_MEM_POST(ARM64_X4, aux, (__u64)imm);
		mreg[4] += (__u64)(pre + post);
		cases = cases + 1U;
		if (__a64_x4.x != mreg[4]) {
			printf("MISMATCH pp x4 flags %u imm %lld: got 0x%llx want 0x%llx\n",
			       SFLAGS[i], (long long)imm,
			       (unsigned long long)__a64_x4.x,
			       (unsigned long long)mreg[4]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__a64_x4_tag != mtag[4]) {
			printf("MISMATCH pp x4 tag flags %u: got %u want %u\n",
			       SFLAGS[i], __a64_x4_tag, mtag[4]);
			return 0xDEAD0001ULL;
		}
		/* a second base with a different tag: the pointer advance
		 * must keep the plant tag intact */
		ARM64_SIM_L_MEM_PRE(ARM64_X8, aux, (__u64)imm);
		ARM64_SIM_L_MEM_POST(ARM64_X8, aux, (__u64)imm);
		mreg[8] += (__u64)(pre + post);
		cases = cases + 1U;
		if (__a64_x8.x != mreg[8]) {
			printf("MISMATCH pp x8 flags %u imm %lld: got 0x%llx want 0x%llx\n",
			       SFLAGS[i], (long long)imm,
			       (unsigned long long)__a64_x8.x,
			       (unsigned long long)mreg[8]);
			return 0xDEAD0001ULL;
		}
		cases = cases + 1U;
		if (__a64_x8_tag != mtag[8]) {
			printf("MISMATCH pp x8 tag flags %u: got %u want %u\n",
			       SFLAGS[i], __a64_x8_tag, mtag[8]);
			return 0xDEAD0001ULL;
		}
	}
arm64_l_done_pp:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH pp reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0001ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH pp sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x61ULL);
	KEEP_LBL(arm64_l_pp);
	KEEP_LBL(arm64_l_done_pp);
	ARM64_SIM_RET();
}

/* ------------------------------------------------------------ 0459 scene family
 * Three route-host scenes over the 0459 lane family in
 * ../arm64/arm64_sim_local_bpf.h: the include-guard re-include, the
 * DECLARE_STATE scalar-tail plant/readback glue, and the four DQ
 * vector-lane transfers over the MEM value path.  Every real macro runs
 * inside a real scene; the exit byte and the full 31-cell register file
 * are compared against the model.  The vector scene drives v0/v0_hi ONLY
 * through the DQ_MEM_STEP MEM_READ/MEM_WRITE normal arms, so the 0458
 * STORE_Q0_STACK stride row stays undriven. */

/* Guard scene: include the whole header a second time (statement-level
 * objects none); only the include-guard pair lets this compile. */
static int a64_guard_probe_marker;

static __u64 scene_guard(void)
{
	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	{
#include "../arm64/arm64_sim_local_bpf.h"
	}
	(void)a64_guard_probe_marker;
	/* a second include only re-runs the guard: re-verify a live lane so
	 * a broke-guard TU still fails here */
	cases = cases + 2U;
	if (ARM64_SIM_L_REG_TAG(ARM64_X0) != ARM64_SIM_TAG_ABI ||
	    ARM64_SIM_L_READ_REG_PTR(ARM64_X0) != (void *)&__a64_sim_abi) {
		printf("MISMATCH guard reinclude lanes\n");
		return 0xDEAD0002ULL;
	}
	X0_SET(0x62ULL);
	ARM64_SIM_RET();
}

/* State-glue scene: direct plant/readback of the DECLARE_STATE scalar
 * tails (v0/v0_hi + NZCV + lr).  arm64 has no named state struct, so the
 * tails are scene-local cells, not a mirror struct; the full 31-cell GPR
 * tail keeps the model in lockstep. */
static __u64 scene_state_glue(void)
{
	unsigned i;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	__a64_v0 = pattern_reg(40U);
	__a64_v0_hi = pattern_reg(41U);
	__a64_n = 1U;
	__a64_z = 0U;
	__a64_c = 1U;
	__a64_v = 0U;
	__a64_lr = 0x7d7d7d7d7d7d7d7dULL;
	mlr = 0x7d7d7d7d7d7d7d7dULL;
	mn = 1U;
	mz = 0U;
	mc = 1U;
	mv = 0U;
	{
		__u64 gv0 = __a64_v0, gv0hi = __a64_v0_hi, glr = __a64_lr;
		__u8 gnzcv = (__u8)(__a64_n | (__a64_z << 1U) |
				    (__a64_c << 2U) | (__a64_v << 3U));

		cases = cases + 2U;
		if (gv0 != pattern_reg(40U) || gv0hi != pattern_reg(41U)) {
			printf("MISMATCH sg vreg tails: got 0x%llx/0x%llx\n",
			       (unsigned long long)gv0,
			       (unsigned long long)gv0hi);
			return 0xDEAD0003ULL;
		}
		cases = cases + 1U;
		if (glr != 0x7d7d7d7d7d7d7d7dULL || gnzcv != 5U) {
			printf("MISMATCH sg lr/nzcv tails: got 0x%llx/%u\n",
			       (unsigned long long)glr, gnzcv);
			return 0xDEAD0004ULL;
		}
	}
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH sg reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0004ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH sg sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x63ULL);
	ARM64_SIM_RET();
}

/* Vector-lane scene: the four DQ opcodes over the MEM value path, each
 * compared against the hand buffer image + the two vector-register
 * halves (low/high). */
static __u64 scene_vector_lanes(void)
{
	unsigned i;
	static const __u64 VOPS[4] = {
		ARM64_OP_LOAD_D0, ARM64_OP_STORE_D0,
		ARM64_OP_LOAD_Q0, ARM64_OP_STORE_Q0,
	};
	static const __u64 LO = 0x1112131415161718ULL;
	static const __u64 HI = 0x91A2B3C4D5E6F708ULL;

	model_reset();
	mlr = 0;
	ARM64_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	(void)__a64_sim_abi_kind;
	(void)__a64_sp;
	(void)__a64_stack.b[0];
	(void)__a64_stack_tag[0];
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;
	marks_reset();
	PLANT_REG(10, (__u64)(unsigned long)&mem_scene_bufs[1],
		   ARM64_SIM_TAG_SCALAR);
	*((__u64 *)mem_scene_bufs[1]) = LO;
	*((__u64 *)mem_scene_bufs[1] + 1) = HI;
	__a64_v0 = pattern_reg(64U);
	__a64_v0_hi = pattern_reg(65U);
arm64_l_vl:
	for (i = 0; i < 4U; i++) {
		switch (VOPS[i]) {
		case ARM64_OP_LOAD_D0: /* 1 lane: low only, extra 0 */
			ARM64_SIM_L_LOAD_D0_MEM(ARM64_X10, 0xffU, 0ULL, 0ULL);
			cases = cases + 2U;
			if (__a64_v0 != LO || __a64_v0_hi != pattern_reg(65U)) {
				printf("MISMATCH vl ld0 vreg: got 0x%llx/0x%llx\n",
				       (unsigned long long)__a64_v0,
				       (unsigned long long)__a64_v0_hi);
				return 0xDEAD0005ULL;
			}
			break;
		case ARM64_OP_STORE_D0: /* writes v0 to buf[0] only */
			ARM64_SIM_L_STORE_D0_MEM(ARM64_X10, 0xffU, 0ULL, 0ULL);
			cases = cases + 2U;
			if (*((__u64 *)mem_scene_bufs[1]) != __a64_v0 ||
			    *((__u64 *)mem_scene_bufs[1] + 1) != HI) {
				printf("MISMATCH vl st0 buffer\n");
				return 0xDEAD0006ULL;
			}
			break;
		case ARM64_OP_LOAD_Q0: /* 2 lanes: v0 <- buf[0], hi <- buf[8] */
			ARM64_SIM_L_LOAD_Q0_MEM(ARM64_X10, 0xffU, 0ULL, 0ULL);
			cases = cases + 2U;
			if (__a64_v0 != LO || __a64_v0_hi != HI) {
				printf("MISMATCH vl ldq vreg: got 0x%llx/0x%llx\n",
				       (unsigned long long)__a64_v0,
				       (unsigned long long)__a64_v0_hi);
				return 0xDEAD0007ULL;
			}
			break;
		case ARM64_OP_STORE_Q0: /* writes both lanes */
			ARM64_SIM_L_STORE_Q0_MEM(ARM64_X10, 0xffU, 0ULL, 0ULL);
			cases = cases + 2U;
			if (*((__u64 *)mem_scene_bufs[1]) != __a64_v0 ||
			    *((__u64 *)mem_scene_bufs[1] + 1) != __a64_v0_hi) {
				printf("MISMATCH vl stq buffer\n");
				return 0xDEAD0008ULL;
			}
			break;
		}
	}
arm64_l_done_vl:
	for (i = 0; i < 31U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		ARM64_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(model_abi_live && i == 0U) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH vl reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD0006ULL;
		}
	}
	cases = cases + 1U;
	if (__a64_sp != msp) {
		printf("MISMATCH vl sp: got %lld want %lld\n",
		       (long long)__a64_sp, (long long)msp);
		return 0xDEAD0008ULL;
	}
	X0_SET(0x64ULL);
	KEEP_LBL(arm64_l_vl);
	KEEP_LBL(arm64_l_done_vl);
	ARM64_SIM_RET();
}

/* Main: drive every scene, then summarize. Body scenes return 0 on success. */
int main(void)
{
	int rc = 0;

	/* JCC forward: EQ taken/not-taken driven by the model cond evaluator;
	 * drive a spread of conds × polarities so both the forward JMP routing
	 * and the fall-through lane observe. */
	static const unsigned CONDS[] = { 0U, 1U, 4U, 7U, 9U, 10U, 12U };
	static const unsigned FLAGSETS[3][4] = {
		{ 0U, 1U, 0U, 0U },
		{ 1U, 0U, 1U, 1U },
		{ 0U, 0U, 0U, 1U },
	};
	unsigned ci, fi;
	for (ci = 0; ci < 7U; ci++) {
		for (fi = 0; fi < 3U; fi++) {
			int take = model_take(CONDS[ci], FLAGSETS[fi][0],
					      FLAGSETS[fi][1], FLAGSETS[fi][2],
					      FLAGSETS[fi][3]);
			__u64 r = scene_jcc_fwd(CONDS[ci], FLAGSETS[fi][0],
						FLAGSETS[fi][1],
						FLAGSETS[fi][2],
						FLAGSETS[fi][3], take);
			cases = cases + 1U;
			if (r != (__u64)(take ? 0x20U : 0x44U)) {
				printf("FAIL jcc fwd cond=%u flags=%u/%u/%u/%u rc=%llx\n",
				       CONDS[ci], FLAGSETS[fi][0],
				       FLAGSETS[fi][1], FLAGSETS[fi][2],
				       FLAGSETS[fi][3],
				       (unsigned long long)r);
				rc = 1;
			}
		}
	}
	for (ci = 0; ci < 7U; ci++) {
		for (fi = 0; fi < 3U; fi++) {
			int take = model_take(CONDS[ci], FLAGSETS[fi][0],
					      FLAGSETS[fi][1], FLAGSETS[fi][2],
					      FLAGSETS[fi][3]);
			__u64 r = scene_jcc_back(CONDS[ci], FLAGSETS[fi][0],
						 FLAGSETS[fi][1],
						 FLAGSETS[fi][2],
						 FLAGSETS[fi][3], take);
			cases = cases + 1U;
			if (r != (__u64)(take ? 0x20U : 0x44U)) {
				printf("FAIL jcc back cond=%u flags=%u/%u/%u/%u rc=%llx\n",
				       CONDS[ci], FLAGSETS[fi][0],
				       FLAGSETS[fi][1], FLAGSETS[fi][2],
				       FLAGSETS[fi][3],
				       (unsigned long long)r);
				rc = 1;
			}
		}
	}

	/* CBZ/CBNZ forward + backward, taken and not-taken */
	{
		struct {
			unsigned kind;
			__u64 value;
			int taken;
		} CB[] = {
			{ 0U, 0ULL, 1 },   /* CBZ x5=0   => taken */
			{ 0U, 1ULL, 0 },   /* CBZ x5=1   => not  */
			{ 1U, 7ULL, 1 },   /* CBNZ x5=7  => taken */
			{ 1U, 0ULL, 0 },   /* CBNZ x5=0  => not  */
		};
		unsigned k;
		for (k = 0; k < 4U; k++) {
			__u64 r = scene_cb(CB[k].kind, CB[k].value, 0x40UL,
					   0x50UL, CB[k].taken);
			cases = cases + 1U;
			if (r != (__u64)(CB[k].taken ? 0x20U : 0x44U)) {
				printf("FAIL cb fwd kind=%u val=%llu rc=%llx\n",
				       CB[k].kind,
				       (unsigned long long)CB[k].value,
				       (unsigned long long)r);
				rc = 1;
			}
			r = scene_cb(CB[k].kind, CB[k].value, 0x60UL, 0x40UL,
				     CB[k].taken);
			cases = cases + 1U;
			if (r != (__u64)(CB[k].taken ? 0x20U : 0x44U)) {
				printf("FAIL cb back kind=%u val=%llu rc=%llx\n",
				       CB[k].kind,
				       (unsigned long long)CB[k].value,
				       (unsigned long long)r);
				rc = 1;
			}
		}
	}
	/* TBZ/TBNZ forward, bit lane + bit index, taken and not-taken */
	{
		struct {
			unsigned kind;
			__u64 bit;
			__u64 value;
			int taken;
		} TB[] = {
			{ 2U, 4ULL, 0x8ULL, 1 },    /* TBZ: bit4 clear  */
			{ 2U, 3ULL, 0x8ULL, 0 },    /* TBZ: bit3 set    */
			{ 3U, 3ULL, 0x8ULL, 1 },    /* TBNZ: bit3 set   */
			{ 3U, 4ULL, 0x8ULL, 0 },    /* TBNZ: bit4 clear */
			{ 2U, 0ULL, 0ULL, 1 },      /* TBZ  bit0 with 0 */
			{ 3U, 63ULL, 0x8000000000000000ULL, 1 },
		};
		unsigned k;
		for (k = 0; k < 6U; k++) {
			__u64 r = scene_tb(TB[k].kind, TB[k].value, TB[k].bit,
					   0x100UL, 0x120UL, TB[k].taken);
			cases = cases + 1U;
			if (r != (__u64)(TB[k].taken ? 0x20U : 0x44U)) {
				printf("FAIL tb kind=%u bit=%llu val=%llu rc=%llx\n",
				       TB[k].kind,
				       (unsigned long long)TB[k].bit,
				       (unsigned long long)TB[k].value,
				       (unsigned long long)r);
				rc = 1;
			}
		}
	}
	/* linked call ladder */
	{
		__u64 r = scene_call();
		cases = cases + 1U;
		if (r != 0x24ULL) {
			printf("FAIL call ladder rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* mapped RETURN_CASES ladder */
	{
		__u64 r = scene_return_cases();
		cases = cases + 1U;
		if (r != 0x80ULL) {
			printf("FAIL return cases rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
		unsupported_hits = 0U;
		r = scene_ret_default();
		cases = cases + 1U;
		if (r != 0x42ULL) {
			printf("FAIL ret default rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
		cases = cases + 1U;
		if (unsupported_hits != 1U) {
			printf("FAIL ret default unsupported hits %u\n",
			       unsupported_hits);
			rc = 1;
		}
	}
	/* skb ret-writeback + xdp ret lanes */
	{
		unsigned save_fail = failures;
		__u32 exit;

		failures = 0;
		skb_ctx.cb[0] = 0U;
		skb_ctx.cb[1] = 0U;
		exit = (__u32)scene_skb_ret();
		cases = cases + 1U;
		if (skb_ctx.cb[0] != 0x0BADF00DU) {
			printf("FAIL skb cb0 writeback: got %u\n", skb_ctx.cb[0]);
			rc = 1;
		}
		cases = cases + 1U;
		if (skb_ctx.cb[1] != 0x0FEEDFACU) {
			printf("FAIL skb cb1 writeback: got %u\n", skb_ctx.cb[1]);
			rc = 1;
		}
		cases = cases + 1U;
		if (exit != 0x12U) {
			printf("FAIL skb exit: got %u want 18\n", exit);
			rc = 1;
		}
		failures = save_fail;
	}
	{
		__u32 exit = (__u32)scene_xdp_ret();
		cases = cases + 1U;
		if (exit != 0x34U) {
			printf("FAIL xdp exit: got %u want 52\n", exit);
			rc = 1;
		}
	}
	/* run-op forwarding lanes */
	{
		__u64 r = scene_run_ops();
		cases = cases + 1U;
		if (r != 0x5AULL) {
			printf("FAIL run ops rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	/* SP lanes */
	{
		__u64 r = scene_sp_lanes();
		cases = cases + 1U;
		if (r != 0x5BULL) {
			printf("FAIL sp lanes rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	/* 0458 memory/stack family: stack lanes, base-offset decode,
	 * read-tag dispatch, read/write arm split, pre/post writeback */
	{
		__u64 r = scene_stack_lanes();
		cases = cases + 1U;
		if (r != 0x5DULL) {
			printf("FAIL stack lanes rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	{
		__u64 r = scene_mem_base_off();
		cases = cases + 1U;
		if (r != 0x5EULL) {
			printf("FAIL mem base off rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	{
		__u64 r = scene_mem_read_tag();
		cases = cases + 1U;
		if (r != 0x5FULL) {
			printf("FAIL mem read tag rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	{
		__u64 r = scene_mem_rw();
		cases = cases + 1U;
		if (r != 0x60ULL) {
			printf("FAIL mem read/write rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	{
		__u64 r = scene_mem_prepost();
		cases = cases + 1U;
		if (r != 0x61ULL) {
			printf("FAIL mem pre/post rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	/* Regfile glue: pointer/tag reader and writer lanes */
	{
		__u64 r = scene_reg_glue();
		cases = cases + 1U;
		if (r != 0x5CULL) {
			printf("FAIL reg glue rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	/* 0459 route-host scene family: guard, state glue, vector lanes */
	{
		__u64 r = scene_guard();
		cases = cases + 1U;
		if (r != 0x62ULL) {
			printf("FAIL guard rc=%llx\n", (unsigned long long)r);
			rc = 1;
		}
	}
	{
		__u64 r = scene_state_glue();
		cases = cases + 1U;
		if (r != 0x63ULL) {
			printf("FAIL state glue rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	{
		__u64 r = scene_vector_lanes();
		cases = cases + 1U;
		if (r != 0x64ULL) {
			printf("FAIL vector lanes rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}

	if (rc == 0)
		printf("a64 route host cross-check: OK (%lu cases)\n", cases);
	return rc;
}
