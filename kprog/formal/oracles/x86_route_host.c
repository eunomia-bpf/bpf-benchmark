/*
 * Route host cross-check for the x86-64 sim-local control-flow ladder and
 * entry/exit glue family in ../x86/x86_sim_local_bpf.h. STEP 0456 + STEP 0457.
 *
 * Family under test (unrowed substrate: the whole-trace 0273 host exercises
 * X86_SIM_X86_JCC edges without touching these body lines, and the generated
 * cond/branch-emit/pushpop contracts are separate batteries):
 *
 *   X86_SIM_X86_RET()                 skb cb writeback + (u32)rax exit
 *   X86_SIM_X86_JMP                   unconditional goto routing
 *   X86_SIM_X86_JCC_IMPL(+BACKWARD)   forward/backward conditional routing
 *   X86_SIM_X86_CALL / SUB_RET        linked call over the stack slot + read/
 *                                     pop + the ret-dispatch ladder
 *   X86_SIM_CONCAT fallthrough-label glue
 *   X86_SIM_RUN_OP forwarding into X86_SIM_L_EXEC (MOV_IMM + ADD_REG)
 *   X86_SIM_L_EVAL_CC                 CF/ZF/SF/OF threading into EVAL_CC
 *   X86_SIM_ENTRY_XDP/ENTRY_SKB       ABI-kind + skb-ctx + rdi ABI-lane glue
 *   DECLARE_REG/STATE/STACK + FOR_EACH_GPR substrate
 *   READ_REG/READ_REG_PTR/REG_TAG and WRITE_REG_PTR/PTR_TAG fan-out
 *   STACK_WRITE/STACK_READ + PUSH/POP bodies backing the slot and SP
 *
 *   X86_SIM_L_LOAD_PTR_ADDR          pointer-lane load (STEP 0457 scenes:
 *                                     the READ_MEM_VALUE ABI arm and the
 *                                     EXEC_MOV_LOAD ABI-ptr-carry arm)
 *   X86_SIM_L_BARRIER_VAR             asm compile barriers behind the load/
 *                                     store/lea/alu-mem/setcc-mem bodies
 *   X86_SIM_L_STATE_REG_FIELD         struct x86_sim_state member fan-out
 *   INCLUDE GUARD X86_SIM_LOCAL_BPF_H single- and double-include hygiene
 *
 * Every scene drives the real macros inside a real goto-ladder and compares
 * the whole observable state (16 register cells + provenance tags, CF/ZF/SF/
 * OF, exit value, taken-path marks) against an independent model recomputed
 * here. The battery build/mut_x86_route.py repaints one body line per row
 * and requires this host to catch it, or keep observing an equivalent. Tag
 * lanes are numeric literals (TAG_SCALAR 0..TAG_MAP_VALUE 6).
 */

#define __BPF_HELPERS__ 1
#define X86_SIM_ENABLE_STACK 1
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
#include "x86_helper_environment_host.h"
#include "../x86/x86_sim_local_bpf.h"
#include "x86_helper_failure_host.h"
#include <string.h>
#include <stdio.h>
#define last_val ora_arguments
#define last_n ora_argc
static void capture_reset(void)
{
    unsigned i;
    for (i = 0; i < 5; i++) last_val[i] = 0xabcdefabcdefabcdULL;
    last_n = 0;
}
static unsigned helper_failures;
#undef X86_SIM_L_UNSUPPORTED_HELPER
#define X86_SIM_L_UNSUPPORTED_HELPER() do { helper_failures++; } while (0)

static int failures_unused;
static unsigned long cases;

/* ---------------------------------------------------------------- model */
static __u64 mreg[16];
static __u8 mtag[16];
static __u8 mc, mz, ms, mo; /* CF ZF SF OF */

static int model_abi_live;

static void model_reset(void)
{
	unsigned i;
	for (i = 0; i < 16U; i++) {
		mreg[i] = 0;
		mtag[i] = 0U;             /* X86_SIM_TAG_SCALAR */
	}
	mc = mz = ms = mo = 0U;
	/* model_reset runs AFTER the entry glue in every scene; the glue leaves
	 * rdi = the actual XDP context with TAG_ABI. The model lane mirrors the tag but
	 * not the pointer (the sim's own ABI slot address is observable state
	 * the model can't replay as a constant): COMPARE_REGFILE check the
	 * tag lane matches and skips only rdi's value lane while the entry
	 * glue's stamp lives. */
	model_abi_live = 1;
	mtag[X86_RDI] = X86_SIM_TAG_ABI;
}

/* The host profile supplies zero for each unspecified helper word. */
static void model_helper_clobbers(void)
{
	static const unsigned callers[] = { X86_RCX, X86_RDX, X86_RSI, X86_RDI,
		X86_R8, X86_R9, X86_R10, X86_R11 };
	for (unsigned i = 0; i < sizeof(callers) / sizeof(callers[0]); i++) {
		mreg[callers[i]] = 0;
		mtag[callers[i]] = X86_SIM_TAG_SCALAR;
	}
	mc = mz = ms = mo = 0;
}

/* Independent model cond evaluator over the 14 accepted X86_CC_* codes. */
static int model_cc_take(unsigned cc, unsigned c, unsigned z, unsigned s,
			 unsigned o)
{
	switch (cc) {
	case X86_CC_O:  return o != 0;
	case X86_CC_NO: return o == 0;
	case X86_CC_B:  return c != 0;
	case X86_CC_AE: return c == 0;
	case X86_CC_E:  return z != 0;
	case X86_CC_NE: return z == 0;
	case X86_CC_BE: return (c != 0) || (z != 0);
	case X86_CC_A:  return (c == 0) && (z == 0);
	case X86_CC_S:  return s != 0;
	case X86_CC_NS: return s == 0;
	case X86_CC_L:  return (s != 0) != (o != 0);
	case X86_CC_GE: return (s != 0) == (o != 0);
	case X86_CC_LE: return (z != 0) || ((s != 0) != (o != 0));
	case X86_CC_G:  return (z == 0) && ((s != 0) == (o != 0));
	}
	return -1;
}

/* ---------------------------------------------------------------- marks */
static __u32 marks[4];
static unsigned nmarks;
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
 * (expanded INLINE inside every scene so the declared cells stay in scene
 * scope and reads settle -Wunused-* warnings under -Werror.) */

#define GOT_CELL(REG, NAME)                                                \
	case REG:                                                          \
		__c_got = (__u64)(long)__x86_##NAME.ptr;                   \
		__c_tag = __x86_##NAME##_tag;                              \
		break;

#define COMPARE_REGFILE(VIA, RETV)                                         \
	do {                                                               \
		unsigned __c_i;                                            \
		for (__c_i = 0; __c_i < 16U; __c_i++) {                     \
			__u64 __c_got = 0;                                 \
			__u8 __c_tag = 0U;                                 \
			switch (__c_i) {                                   \
			X86_SIM_L_FOR_EACH_GPR(GOT_CELL)                    \
			default: break;                                    \
			}                                                  \
			if (model_abi_live && __c_i == X86_RDI &&            \
			    __c_tag == X86_SIM_TAG_ABI)                       \
				__c_got = mreg[__c_i];                     \
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
		if ((__x86_cf != mc) || (__x86_zf != mz) ||                 \
		    (__x86_sf != ms) || (__x86_of != mo)) {                 \
			printf("MISMATCH %s czso state\n", (VIA));          \
			return (RETV);                                     \
		}                                                          \
	} while (0)

#define KEEP_LBL(L) do { void *keep = (void *)&&L; (void)keep; } while (0)

/* plant one register cell pointer+tag through the declared-name switch */
#define PLANT_CELL(REG, NAME)                                              \
	case REG:                                                          \
		__x86_##NAME.ptr = (void *)(long)__pr_val;                 \
		__x86_##NAME##_tag = __pr_tag;                             \
		break;
#define PLANT_REG(NUMBER, VAL, TAG)                                        \
	do {                                                               \
		__u64 __pr_val = (__u64)(VAL);                             \
		__u8 __pr_tag = (__u8)(TAG);                               \
		switch ((NUMBER)) {                                        \
		X86_SIM_L_FOR_EACH_GPR(PLANT_CELL)                          \
		default: break;                                            \
		}                                                          \
		mreg[(NUMBER)] = (__u64)(VAL);                             \
		mtag[(NUMBER)] = __pr_tag;                                 \
	} while (0)

/* store the exit value in rax (only the model + declared cell) */
#define RAX_SET(VAL)                                                       \
	do {                                                               \
		__x86_rax.ptr = (void *)(long)(__u64)(VAL);                 \
		mreg[X86_RAX] = (__u64)(VAL);                              \
	} while (0)

/* ------------------------------------------------------------ branch scenes
 * Program shape (a real goto-ladder; marks record the executed block):
 *   x86_l_0:  <branch macro>        current 0x0, target 0x10
 *   x86_l_4:  fallthrough block     mark 1, rax-exit paint 0x44
 *   x86_l_10: target block          mark 2, rax-exit paint 0x20
 * Exit value = (marks_word << 8) | exit byte; the compare runs before RET. */

static __u64 scene_jcc_fwd(unsigned cc, unsigned c, unsigned z, unsigned s,
			   unsigned o, int expect_taken)
{
	__u32 w;
	int take = model_cc_take(cc, c, z, s, o);

	model_reset();
	(void)take;
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	marks_reset();
	__x86_cf = (__u8)c;
	__x86_zf = (__u8)z;
	__x86_sf = (__u8)s;
	__x86_of = (__u8)o;
	mc = (__u8)c;
	mz = (__u8)z;
	ms = (__u8)s;
	mo = (__u8)o;
x86_l_0:
	X86_SIM_X86_JCC(cc, 0x0UL, 0x10UL, x86_l_10);
x86_l_4:
	mark(1);
	RAX_SET(0x44ULL);
	goto x86_l_done;
x86_l_10:
	mark(2);
	RAX_SET(0x20ULL);
x86_l_done:
	COMPARE_REGFILE("jcc_fwd", 0xDEAD0001ULL);
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH jcc_fwd cc=%u marks: got %u want %u\n", cc, w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(x86_l_0);
	KEEP_LBL(x86_l_4);
	KEEP_LBL(x86_l_10);
	KEEP_LBL(x86_l_done);
	X86_SIM_X86_RET();
}

static __u64 scene_jcc_back(unsigned cc, unsigned c, unsigned z, unsigned s,
			    unsigned o, int expect_taken)
{
	__u32 w;
	int take = model_cc_take(cc, c, z, s, o);

	model_reset();
	(void)take;
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	marks_reset();
	__x86_cf = (__u8)c;
	__x86_zf = (__u8)z;
	__x86_sf = (__u8)s;
	__x86_of = (__u8)o;
	mc = (__u8)c;
	mz = (__u8)z;
	ms = (__u8)s;
	mo = (__u8)o;
x86_l_20:
	X86_SIM_X86_JCC(cc, 0x20UL, 0x8UL, x86_l_28);
x86_l_24:
	mark(1);
	RAX_SET(0x44ULL);
	goto x86_l_done;
x86_l_28:
	mark(2);
	RAX_SET(0x20ULL);
x86_l_done:
	COMPARE_REGFILE("jcc_back", 0xDEAD0002ULL);
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH jcc_back cc=%u marks: got %u want %u\n", cc, w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(x86_l_20);
	KEEP_LBL(x86_l_24);
	KEEP_LBL(x86_l_28);
	KEEP_LBL(x86_l_done);
	X86_SIM_X86_RET();
}

/* Bare EVAL_CC routing against the same model: the direct
 * `if (X86_SIM_L_EVAL_CC(...))` shape the generator emits for return-target
 * jcc rewrites. */
static __u64 scene_eval_cc(unsigned cc, unsigned c, unsigned z, unsigned s,
			   unsigned o, int expect_taken)
{
	__u32 w;
	int take = model_cc_take(cc, c, z, s, o);

	model_reset();
	(void)take;
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	marks_reset();
	__x86_cf = (__u8)c;
	__x86_zf = (__u8)z;
	__x86_sf = (__u8)s;
	__x86_of = (__u8)o;
	mc = (__u8)c;
	mz = (__u8)z;
	ms = (__u8)s;
	mo = (__u8)o;
x86_l_30:
	if (X86_SIM_L_EVAL_CC(cc))
		goto x86_l_38;
x86_l_34:
	mark(1);
	RAX_SET(0x44ULL);
	goto x86_l_done;
x86_l_38:
	mark(2);
	RAX_SET(0x20ULL);
x86_l_done:
	COMPARE_REGFILE("eval_cc", 0xDEAD0003ULL);
	w = marks_word();
	cases = cases + 1U;
	if (w != (unsigned)(expect_taken ? 0x200U : 0x100U)) {
		printf("MISMATCH eval_cc cc=%u marks: got %u want %u\n", cc, w,
		       (unsigned)(expect_taken ? 2U : 1U));
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(x86_l_30);
	KEEP_LBL(x86_l_34);
	KEEP_LBL(x86_l_38);
	KEEP_LBL(x86_l_done);
	X86_SIM_X86_RET();
}

/* Linked call ladder: main ladder calls the leaf at 0x40 pushing return
 * 0x80; the leaf paints rax and returns through SUB_RET semantics; this
 * host's ladder mirrors the generator's `x86_sim_ret_dispatch: switch`
 * shape over the two return targets. The model mirrors the pushed slot. */
static __u64 scene_call(void)
{
	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	marks_reset();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	{
		unsigned __c_i;
		__u64 __c_got;
		__u8 __c_tag;
		for (__c_i = 0; __c_i < 16U; __c_i++) {
			switch (__c_i) {
			X86_SIM_L_FOR_EACH_GPR(GOT_CELL)
			default: break;
			}
			(void)__c_got;
			(void)__c_tag;
		}
	}
x86_l_c0:
	X86_SIM_X86_JMP(0xc0UL, 0xc4UL, x86_l_c4);
x86_l_c4:
	mark(3);
	/* call leaf at 0x40; return address 0xA80. The high byte keeps the
	 * SUB_RET slot read honest at width 64 (an 8-bit slot read would
	 * truncate to 0x80 and fall off the dispatch switch). The model
	 * mirrors rsp through the pre-decrement/post-increment steps. */
	X86_SIM_X86_CALL(x86_l_40, 0xA80ULL);
	mreg[X86_RSP] = (__u64)(long)-8LL;
	mtag[X86_RSP] = 0U;
x86_l_80:
	mark(1);
	RAX_SET(0x24ULL);
	cases = cases + 2U;
	if (marks[0] != 3U || marks[1] != 2U || marks[2] != 1U) {
		printf("MISMATCH call marks: got %u,%u,%u want 3,2,1\n",
		       marks[0], marks[1], marks[2]);
		return 0xDEAD0004ULL;
	}
	KEEP_LBL(x86_l_c0);
	KEEP_LBL(x86_l_c4);
	KEEP_LBL(x86_l_80);
	X86_SIM_X86_RET();
x86_l_40:
	mark(2);
	/* leaf body: paint rax and dispatch the pushed slot back */
	RAX_SET(0x40ULL);
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_sim_ret_dispatch:
	cases = cases + 2U;
	if (__x86_sim_ret_addr != 0xA80ULL) {
		printf("MISMATCH call ret_addr: got 0x%llx want 0xa80\n",
		       (unsigned long long)__x86_sim_ret_addr);
		return 0xDEAD0006ULL;
	}
	mreg[X86_RSP] = 0ULL;
	mtag[X86_RSP] = 0U;
	COMPARE_REGFILE("call", 0xDEADC001ULL);
	/* the generator's dispatch switch: two return targets */
	switch (__x86_sim_ret_addr) {
	case 0x40ULL:
		goto x86_l_40;
	case 0xA80ULL:
		goto x86_l_80;
	default:
		printf("MISMATCH call dispatch default\n");
		return 0xDEAD0007ULL;
	}
}

/* RET writeback scene: enter via ENTRY_SKB, paint the ABI cb lanes, assert
 * (u32)rax exit and that RET() copied cb[0]/cb[1] to the ctx. */
static __u64 scene_skb_ret(void)
{
	unsigned i;

	model_reset();
	marks_reset();
	skb_ctx.cb[0] = 0x11111111U;
	skb_ctx.cb[1] = 0x22222222U;
	skb_ctx.data = 0x3000U;
	skb_ctx.data_end = 0x4000U;
	X86_SIM_ENTRY_SKB(&skb_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	/* ABI lanes visible through rdi-tag: ENTRY_SKB stamps TAG_ABI */
	cases = cases + 1U;
	if (__x86_rdi_tag != X86_SIM_TAG_ABI) {
		printf("MISMATCH skb entry rdi tag: got %u want %u\n",
		       __x86_rdi_tag, X86_SIM_TAG_ABI);
		return 0xDEAD0005ULL;
	}
	/* entry lanes: kind + ABI field copies */
	cases = cases + 1U;
	if (__x86_sim_abi_kind != KPROG_ABI_KIND_SKB) {
		printf("MISMATCH skb entry abi kind: got %u want %u\n",
		       __x86_sim_abi_kind, KPROG_ABI_KIND_SKB);
		return 0xDEAD0009ULL;
	}
	cases = cases + 2U;
	if (__x86_sim_abi.data != (void *)(long)skb_ctx.data ||
	    __x86_sim_abi.data_end != (void *)(long)skb_ctx.data_end) {
		printf("MISMATCH skb entry abi fields\n");
		return 0xDEAD000AULL;
	}
	for (i = 0; i < 16U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		X86_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		cases = cases + 2U;
		if (!(i == X86_RDI &&
		      __c_tag == X86_SIM_TAG_ABI) &&
		    (__c_got != mreg[i] || __c_tag != mtag[i])) {
			printf("MISMATCH skb reg%u state\n", i);
			return 0xDEAD0001ULL;
		}
	}
	/* exit paint: rax mirrors ABI content bytes through rax.ptr */
	__x86_sim_abi.cb[0] = 0x0BADF00DU;
	__x86_sim_abi.cb[1] = 0x0FEEDFACU;
	RAX_SET(0x12ULL);
	/* assert the exit value pre-RET (RET writes the ctx lanes) */
	cases = cases + 1U;
	if ((__u64)(long)__x86_rax.ptr != 0x12ULL) {
		printf("MISMATCH skb exit rax: got 0x%llx want 0x12\n",
		       (unsigned long long)(__u64)(long)__x86_rax.ptr);
		return 0xDEAD000BU;
	}
	X86_SIM_X86_RET();
}

/* XDP entry leaves cb untouched: enter and confirm skb_ctx stays null. */
static __u64 scene_xdp_ret(void)
{
	model_reset();
	marks_reset();
	xdp_ctx.data = 0x5000U;
	xdp_ctx.data_end = 0x5100U;
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	cases = cases + 1U;
	if (__x86_sim_abi_kind != KPROG_ABI_KIND_XDP) {
		printf("MISMATCH xdp entry abi kind: got %u want %u\n",
		       __x86_sim_abi_kind, KPROG_ABI_KIND_XDP);
		return 0xDEAD0007ULL;
	}
	/* SKB ctx must stay null: the XDP ENTRY_SKB glue skips it */
	cases = cases + 1U;
	if ((void *)__x86_sim_skb_ctx != (void *)0) {
		printf("MISMATCH xdp entry skb ctx non-null\n");
		return 0xDEAD0008ULL;
	}
	/* Native writes must retain the actual context identity. Reads must
	 * observe current fields, including through an offset alias, rather
	 * than values copied before a helper could change the packet. */
	xdp_ctx.data += 0x100U;
	xdp_ctx.data_end += 0x200U;
	cases += 3U;
	if (__x86_rdi.ptr != (void *)&xdp_ctx ||
	    X86_SIM_L_XDP_READ(__x86_rdi.ptr, KPROG_ABI_XDP_DATA_OFF,
			       X86_WIDTH_64) != xdp_ctx.data ||
	    X86_SIM_L_XDP_READ(KPROG_PTR_ADD64_BITS(__x86_rdi.ptr,
				KPROG_ABI_XDP_DATA_END_OFF), 0,
			       X86_WIDTH_64) != xdp_ctx.data_end) {
		printf("MISMATCH xdp context identity or live fields\n");
		return 0xDEAD000BULL;
	}
	RAX_SET(0x34ULL);
	COMPARE_REGFILE("xdp_ret", 0xDEAD0006ULL);
	X86_SIM_X86_RET();
}

/* Regfile-glue scene: drive the pointer/tag readers and the pointer-tag
 * writers plus the SP-lane reads through the fan-out. */
static __u64 scene_reg_glue(void)
{
	unsigned i;
	void *pp;
	__u8 tg;

	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	marks_reset();
	/* SP lane: READ_REG_PTR == (void*)(long)rsp value 0 and REG_TAG ==
	 * SCALAR until a write repaints */
	pp = X86_SIM_L_READ_REG_PTR(X86_RSP);
	tg = X86_SIM_L_REG_TAG(X86_RSP);
	cases = cases + 2U;
	if (pp != (void *)0 || tg != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH regglue SP lanes\n");
		return 0xDEAD0009ULL;
	}
	/* WRITE_REG_PTR_TAG on R8: value 0x7000 tag MAP_PTR */
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_R8, 0x7000ULL, X86_SIM_TAG_MAP_PTR);
	mreg[X86_R8] = 0x7000ULL;
	mtag[X86_R8] = X86_SIM_TAG_MAP_PTR;
	/* WRITE_REG_PTR on R9 (scalar tag) */
	X86_SIM_L_WRITE_REG_PTR(X86_R9, 0x8000ULL);
	mreg[X86_R9] = 0x8000ULL;
	mtag[X86_R9] = X86_SIM_TAG_SCALAR;
	for (i = 0; i < 16U; i++) {
		__u64 __c_got = 0;
		__u8 __c_tag = 0U;
		switch (i) {
		X86_SIM_L_FOR_EACH_GPR(GOT_CELL)
		default: break;
		}
		if (model_abi_live && i == X86_RDI &&
		    mtag[X86_RDI] == X86_SIM_TAG_ABI)
			continue;
		cases = cases + 2U;
		if (__c_got != mreg[i] || __c_tag != mtag[i]) {
			printf("MISMATCH regglue reg%u state: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)__c_got, __c_tag,
			       (unsigned long long)mreg[i], mtag[i]);
			return 0xDEAD000AULL;
		}
	}
	/* re-read tags and pointers through the readers */
	cases = cases + 1U;
	if (X86_SIM_L_REG_TAG(X86_R8) != X86_SIM_TAG_MAP_PTR ||
	    X86_SIM_L_REG_TAG(X86_R9) != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH regglue tags\n");
		return 0xDEAD000BU;
	}
	cases = cases + 2U;
	if (X86_SIM_L_READ_REG(X86_R8) != 0x7000ULL ||
	    X86_SIM_L_READ_REG(X86_R9) != 0x8000ULL) {
		printf("MISMATCH regglue ptrs\n");
		return 0xDEAD000CU;
	}
	/* READ_REG_PTR mirrors the .ptr lane of the planted cells */
	cases = cases + 2U;
	if (X86_SIM_L_READ_REG_PTR(X86_R8) != (void *)(long)0x7000ULL ||
	    X86_SIM_L_READ_REG_PTR(X86_R9) != (void *)(long)0x8000ULL) {
		printf("MISMATCH regglue read-ptr lanes\n");
		return 0xDEAD000DU;
	}
	RAX_SET(0x5CULL);
	X86_SIM_X86_RET();
}

/* Run-op forward lanes: drive RUN_OP MOV-imm/Add-reg writes and compare the
 * regfile against the model (guards X86_SIM_RUN_OP forwarding). */
static __u64 scene_run_ops(void)
{
	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	marks_reset();
	/* MOV_IMM: r9 = 0x101  (op 0x01, dst R9, no flags, aux 0, imm 0x101) */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, 0U, 0U, 0x101ULL);
	mreg[X86_R9] = 0x101ULL;
	/* ADD_REG: r10 = r10 + r9 (op 0x04, dst R10, src R9, width 64; the
	 * aux packs the ALU op byte (ADD=0) into the payload lane and both
	 * shift lanes at 0) */
	X86_SIM_RUN_OP(X86_OP_ADD_REG, X86_R10, X86_R9, X86_WIDTH_64,
		       KPROG_X86_REG_LANE_AUX(X86_ALU_ADD, 0U, 0U), 0x7ULL);
	mreg[X86_R10] = mreg[X86_R10] + mreg[X86_R9];
	/* ALU_IMM: r10 = r10 + 7 at the absent-width default (op 0x0a) */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, 0U,
		       KPROG_X86_REG_LANE_AUX(X86_ALU_ADD, 0U, 0U), 0x7ULL);
	mreg[X86_R10] = mreg[X86_R10] + 0x7ULL;
	RAX_SET(0x5AULL);
	COMPARE_REGFILE("run_ops", 0xDEAD000EU);
	X86_SIM_X86_RET();
}

/* Helper-dispatch scene: the sparse Linux-ID ladder, nonzero scalar
 * results, lookup/update/delete calls and the explicit failure arm.
 * The model mirrors rax + rdi/rdi-tag side-effects and the capture lanes. */
static const __u64 ORA_MAP = ORA_MAP_PTR;

static __u64 scene_helper_dispatch(void)
{
	unsigned i;

	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_sim_abi_kind;
	(void)__x86_sim_skb_ctx;
	marks_reset();

	/* id 1 lookup: lanes rdi(raw rax=0x1000, tag SCALAR), rsi */
	PLANT_REG(X86_RDI, 0x1000ULL, 0U);
	PLANT_REG(X86_RSI, 0x2000ULL, 0U);
	capture_reset();
	X86_SIM_BPF_CALL_ID(1ULL);
	mreg[X86_RDI] = 0x1000ULL;
	mreg[X86_RSI] = 0x2000ULL;
	mreg[X86_RAX] = ORA_MAP;
	mtag[X86_RAX] = X86_SIM_TAG_MAP_VALUE;
	cases = cases + 2U;
	if (last_n != 2U || last_val[0] != 0x1000ULL ||
	    last_val[1] != 0x2000ULL) {
		printf("MISMATCH helper id1 lookup lanes: n=%u v0=0x%llx v1=0x%llx\n",
		       last_n, (unsigned long long)last_val[0],
		       (unsigned long long)last_val[1]);
		return 0xDEAD0010ULL;
	}
	mreg[X86_RDI] = 0x1000ULL;
	mreg[X86_RSI] = 0x2000ULL;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_id1", 0xDEAD0011ULL);

	/* id 2 update: 4 lanes, scalar ret in rax */
	PLANT_REG(X86_RDI, 0x1000ULL, 0U);
	PLANT_REG(X86_RSI, 0x2000ULL, 0U);
	PLANT_REG(X86_RDX, 0x3000ULL, 0U);
	PLANT_REG(X86_RCX, 0x4000ULL, 0U);
	capture_reset();
	X86_SIM_BPF_CALL_ID(2ULL);
	mreg[X86_RDI] = 0x1000ULL;
	mreg[X86_RSI] = 0x2000ULL;
	mreg[X86_RDX] = 0x3000ULL;
	mreg[X86_RCX] = 0x4000ULL;
	mreg[X86_RAX] = (__u64)(long)ORA_UPD_RET;
	mtag[X86_RAX] = 0U;
	cases = cases + 2U;
	if (last_n != 4U || last_val[0] != 0x1000ULL ||
	    last_val[1] != 0x2000ULL || last_val[2] != 0x3000ULL ||
	    last_val[3] != 0x4000ULL) {
		printf("MISMATCH helper id2 update lanes\n");
		return 0xDEAD0012ULL;
	}
	mreg[X86_RDI] = 0x1000ULL;
	mreg[X86_RSI] = 0x2000ULL;
	mreg[X86_RDX] = 0x3000ULL;
	mreg[X86_RCX] = 0x4000ULL;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_id2", 0xDEAD0013ULL);

	/* id 3 delete: 2 lanes */
	PLANT_REG(X86_RDI, 0x1000ULL, 0U);
	PLANT_REG(X86_RSI, 0x2000ULL, 0U);
	capture_reset();
	X86_SIM_BPF_CALL_ID(3ULL);
	mreg[X86_RDI] = 0x1000ULL;
	mreg[X86_RSI] = 0x2000ULL;
	mreg[X86_RAX] = (__u64)ORA_DEL_RET;
	mtag[X86_RAX] = 0U;
	cases = cases + 2U;
	if (last_n != 2U || last_val[0] != 0x1000ULL ||
	    last_val[1] != 0x2000ULL) {
		printf("MISMATCH helper id3 delete lanes\n");
		return 0xDEAD0014ULL;
	}
	mreg[X86_RDI] = 0x1000ULL;
	mreg[X86_RSI] = 0x2000ULL;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_id3", 0xDEAD0015ULL);

	/* UID/PID use Linux IDs 15/14; CPU ID 8 returns a 32-bit value. */
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	X86_SIM_BPF_CALL_ID(15ULL);
	mreg[X86_RAX] = ora_expected_result(15);
	mtag[X86_RAX] = 0U;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_uid15", 0xDEAD0016ULL);
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	X86_SIM_BPF_CALL_ID(14ULL);
	mreg[X86_RAX] = ora_expected_result(14);
	mtag[X86_RAX] = 0U;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_pid14", 0xDEAD0017ULL);
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	X86_SIM_BPF_CALL_ID(8ULL);
	mreg[X86_RAX] = ora_expected_result(8);
	mtag[X86_RAX] = 0U;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_cpu8", 0xDEAD0018ULL);
	/* ID 5 ktime: native capture, 64-bit rax. */
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	capture_reset();
	X86_SIM_BPF_CALL_ID(5ULL);
	mreg[X86_RAX] = ORA_KTIME;
	mtag[X86_RAX] = 0U;
	cases = cases + 1U;
	if (last_n != 0U) {
		printf("MISMATCH helper id5 ktime capture\n");
		return 0xDEAD001CULL;
	}
	model_helper_clobbers();
	COMPARE_REGFILE("helper_ktime5", 0xDEAD001DULL);
	/* Gap ID 13 reaches the failure arm and preserves RAX. */
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	PLANT_REG(X86_RDI, 0x1000ULL, 0U);
	PLANT_REG(X86_RSI, 0x2000ULL, 0U);
	PLANT_REG(X86_RDX, 0x3000ULL, 0U);
	PLANT_REG(X86_RCX, 0x4000ULL, 0U);
	X86_SIM_BPF_CALL_ID(13ULL);
	mreg[X86_RAX] = 0x9000ULL;
	mtag[X86_RAX] = 0U;
	COMPARE_REGFILE("helper_id13_default", 0xDEAD0019ULL);
	/* id 0 reaches the default arm too */
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	PLANT_REG(X86_RDI, 0x1000ULL, 0U);
	PLANT_REG(X86_RSI, 0x2000ULL, 0U);
	PLANT_REG(X86_RDX, 0x3000ULL, 0U);
	PLANT_REG(X86_RCX, 0x4000ULL, 0U);
	X86_SIM_BPF_CALL_ID(0ULL);
	mreg[X86_RAX] = 0x9000ULL;
	mtag[X86_RAX] = 0U;
	COMPARE_REGFILE("helper_id0_default", 0xDEAD001AULL);
	if (helper_failures != 2U) return 0xDEAD001EULL;
	/* CALL_REG routes RSI through the same ladder: Linux CPU ID 8. */
	PLANT_REG(X86_RSI, 8ULL, 0U);
	PLANT_REG(X86_RAX, 0x9000ULL, 0U);
	X86_SIM_BPF_CALL_REG(X86_RSI);
	mreg[X86_RSI] = 8ULL;
	mreg[X86_RAX] = ora_expected_result(8);
	mtag[X86_RAX] = 0U;
	model_helper_clobbers();
	COMPARE_REGFILE("helper_call_reg", 0xDEAD001BULL);
	(void)i;
	RAX_SET(0x5EULL);
	X86_SIM_X86_RET();
}

/* Subroutine-ladder scene: the generated subfunction twins in both
 * positions. SUB_JCC routes on the eval'ed cond with the fallthrough label,
 * SUB_JMP jumps unconditionally, RUN_OP_SUB forwards to RUN_OP. The marks
 * tape proves the route, the r9 paint proves the RUN_OP_SUB write lane, and
 * both edges of the SUB_JCC cond are observed. */
static __u64 scene_sub_ladder(void)
{
	int gate;
	__u64 acc = 0;
	__u32 w;

	for (gate = 0; gate < 2; gate++) {
		model_reset();
		marks_reset();
		X86_SIM_ENTRY_XDP(&xdp_ctx);
		(void)__x86_sim_ret_addr;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_abi_kind;
		(void)__x86_stack_mem.b[0];
		(void)__x86_rdi_tag;
		(void)__x86_sim_skb_ctx;
		mreg[X86_RSP] = 0;
		__x86_cf = (unsigned)(gate == 0) ? 0U : 1U;
		__x86_zf = 0U;
		__x86_sf = 0U;
		__x86_of = 0U;
		mc = (__u8)__x86_cf;
		mz = 0U;
		ms = 0U;
		mo = 0U;
x86_l_sub:
		/* sub_jcc AE: !CF => taken ============================
		 * gate 0 (cf=0): taken -> x86_l_32 => mark 2
		 * gate 1 (cf=1): fallthrough ==> mark 1 */
		X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x30UL, 0x32UL, x86_l_32);
		mark(1);
		goto x86_l_after;
x86_l_32:
		mark(2);
x86_l_after:
		/* RUN_OP_SUB forwards to RUN_OP: r9 = 0x77 */
		X86_SIM_RUN_OP_SUB(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, 0U,
				   0U, 0x77ULL);
		mreg[X86_R9] = 0x77ULL;
		/* sub_jmp: unconditional transfer to x86_l_3a */
		X86_SIM_X86_SUB_JMP(0x38UL, 0x3aUL, x86_l_3a);
		mark(3);
x86_l_3a:
		acc = acc + mreg[X86_R9];
		COMPARE_REGFILE("sub_ladder", 0xDEAD0010ULL);
		w = marks_word();
		cases = cases + 1U;
		if (w != (unsigned)(gate == 0 ? 0x200U : 0x100U)) {
			printf("MISMATCH sub_ladder gate=%d marks: got %u want %u\n",
			       gate, w, (unsigned)(gate == 0 ? 2U : 1U));
			return 0xDEAD0011ULL;
		}
		KEEP_LBL(x86_l_sub);
		KEEP_LBL(x86_l_32);
		KEEP_LBL(x86_l_after);
		KEEP_LBL(x86_l_3a);
	}
	return acc == 0xEEULL ? 0ULL : 0xDEAD0012ULL;
}

/* SP lanes: PUSH/POP over the frame step routes rsp through the stack
 * helpers; the SUB_RET slot lives there in a real call. */
static __u64 scene_sp_lanes(void)
{
	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_abi_kind;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	marks_reset();
	/* PUSH R9 (pre-decrement push of the planted cell) */
	PLANT_REG(X86_R9, 0xEBULL, 0U);
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R9, 0U, 0U, 0ULL);
	mreg[X86_RSP] = (__u64)(long)-8LL;
	/* then POP R10 back (post-increment pop) */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R10, X86_REG_NONE, 0U, 0U, 0ULL);
	mreg[X86_R10] = 0xEBULL;
	mtag[X86_R10] = 0U;
	mreg[X86_RSP] = 0;
	RAX_SET(0x5BULL);
	COMPARE_REGFILE("sp_lanes", 0xDEAD000FU);
	X86_SIM_X86_RET();
}

/* -------------------------------------------------- STEP 0457 scenes ----
 * Pointer-load, index-offset, barrier, and state-struct glue. The
 * pointer-load scene drives the two real X86_SIM_L_LOAD_PTR_ADDR arms (the
 * READ_MEM_VALUE ABI lane and the EXEC_MOV_LOAD ABI-ptr-carry arm with the
 * KPROG_ABI_LOAD_TAG packet-tag refinement); the offset lane goes through
 * the public X86_SIM_L_MEM_OFFSET bridge with present/absent index bytes;
 * the barrier scene walks real bodies that place X86_SIM_L_BARRIER_VAR
 * between offset formation and address use; the state scene materializes
 * struct x86_sim_state and drives the member + tag fan-out. */

/* Backing heap for the pointer-load scene: 16 pointer slots seeded with
 * distinct bit patterns; the model mirrors slot contents separately so a
 * mis-routed load arm always lands on a distinguishable value. */
static void *ptr_slab[64];

static void slab_fill(unsigned seed)
{
	unsigned i;
	for (i = 0; i < sizeof(ptr_slab) / sizeof(ptr_slab[0]); i++)
		ptr_slab[i] = (void *)(long)(0x1000000000000000ULL |
					     ((unsigned long long)seed
					      << 32) |
					     ((unsigned long long)i << 8) |
					     0xC0ULL);
}

static __u8 model_abi_load_tag(unsigned kind, __s64 off)
{
	if (kind == KPROG_ABI_KIND_XDP) {
		if (off == KPROG_ABI_XDP_DATA_OFF)
			return X86_SIM_TAG_PACKET;
		if (off == KPROG_ABI_XDP_DATA_END_OFF)
			return X86_SIM_TAG_PACKET_END;
	}
	if (kind == KPROG_ABI_KIND_SKB) {
		if (off == KPROG_ABI_SKB_DATA_OFF)
			return X86_SIM_TAG_PACKET;
		if (off == KPROG_ABI_SKB_DATA_END_OFF)
			return X86_SIM_TAG_PACKET_END;
	}
	return X86_SIM_TAG_SCALAR;
}

/* Pointer-load scene. Case A reads through the shared read-helper
 * X86_SIM_L_READ_MEM_VALUE with an ABI-tagged base at width 64 (the ABI
 * pointer-load lane); case B drives the real EXEC_MOV_LOAD ABI-ptr-carry
 * arm and checks the loaded value AND the refined packet tag. Both compare
 * the untouched ABI regfile shape against the model. */
static __u64 scene_ptr_load(unsigned kind, __s64 off, unsigned sel)
{
	static const __s64 OFFS[7] = { 0, 8, 80, 208, 16, 24, 32 };
	unsigned oi;
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, X86_WIDTH_64, 0U);
	__u64 want_bits;
	__u8 want_tag;
	unsigned i;

	for (oi = 0; oi < 7U; oi++)
		if (OFFS[oi] == off)
			break;
	if (oi == 7U)
		return 0xDEAD006FULL;

	model_reset();
	/* This scene tests the generic ABI slab, not an XDP context. */
	X86_SIM_ENTRY_RAW(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_sim_abi_kind;
	marks_reset();
	slab_fill((unsigned)off);
	mreg[X86_RDI] = 0;
	mtag[X86_RDI] = X86_SIM_TAG_ABI;
	__x86_sim_abi_kind = (__u8)kind;
	/* rsi holds the slab BASE (tagged ABI, NOT the ABI rdi); every
	 * dispatched load dereferences *(void **)(slab + off), so the
	 * wanted bits live in the cell at byte-offset off. */
	PLANT_REG(X86_RSI, (__u64)(unsigned long)(void *)ptr_slab,
		  X86_SIM_TAG_ABI);
	ptr_slab[(unsigned)(off / 8)] =
		(void *)(long)(0x2000000000000000ULL |
			       (__u64)(unsigned long)off);
	want_bits = 0x2000000000000000ULL | (__u64)(unsigned long)off;
	want_tag = model_abi_load_tag(kind, off);
	if (sel < 2U) {
		/* Case A: the shared read-helper ABI lane (no tag write).
		 * The read dereferences *(void **)(base + disp), so the
		 * expected bits are the slab cell at byte-offset off. */
		__u64 got = X86_SIM_L_READ_MEM_VALUE(X86_RSI, aux,
						     (__u64)(unsigned long)off,
						     X86_WIDTH_64, 0U);
		cases = cases + 2U;
		if (got != want_bits) {
			printf("MISMATCH ptrload read-helper kind=%u off=%lld\n",
			       kind, (long long)off);
			return 0xDEAD0060ULL;
		}
	} else {
		/* Case B: the EXEC_MOV_LOAD ABI-ptr-carry arm; the load
		 * writes r11 value+tag. */
		X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSI,
					X86_WIDTH_64, aux, 0ULL);
		cases = cases + 2U;
		if (X86_SIM_L_READ_REG(X86_R11) != want_bits ||
		    X86_SIM_L_REG_TAG(X86_R11) != want_tag) {
			printf("MISMATCH ptrload mov arm kind=%u off=%lld got=0x%llx/%u want=0x%llx/%u\n",
			       kind, (long long)off,
			       (unsigned long long)X86_SIM_L_READ_REG(X86_R11),
			       X86_SIM_L_REG_TAG(X86_R11),
			       (unsigned long long)want_bits, want_tag);
			return 0xDEAD0061ULL;
		}
	}
	/* the untouched cells keep their ABI-rdi + planted-rsi shape */
	for (i = 0; i < 16U; i++) {
		__u64 want = 0;
		__u8 want_t = 0U;
		if (i == X86_RDI) {
			want = (__u64)(unsigned long)(void *)&xdp_ctx;
			want_t = X86_SIM_TAG_ABI;
		} else if (i == X86_RSI) {
			want = (__u64)(unsigned long)(void *)ptr_slab;
			want_t = X86_SIM_TAG_ABI;
		} else if (i == X86_R11 && sel >= 2U) {
			want = want_bits;
			want_t = want_tag;
		}
		if (i == X86_RAX)
			continue; /* rax carries the entry stamp */
		cases = cases + 2U;
		if (X86_SIM_L_READ_REG(i) != want) {
			printf("MISMATCH ptrload reg%u state: got 0x%llx want 0x%llx\n",
			       i, (unsigned long long)X86_SIM_L_READ_REG(i),
			       (unsigned long long)want);
			return 0xDEAD0062ULL;
		}
		if (X86_SIM_L_REG_TAG(i) != want_t) {
			printf("MISMATCH ptrload reg%u tag: got %u want %u\n",
			       i, X86_SIM_L_REG_TAG(i), want_t);
			return 0xDEAD0063ULL;
		}
	}
	RAX_SET(0x57ULL);
	X86_SIM_X86_RET();
}

/* Offset scene: the public X86_SIM_L_MEM_OFFSET bridge with the index byte
 * present (displacement plus index<<scale, read through the sim register
 * reader) and absent (sentinel byte: pure displacement even with a poisoned
 * register file). Both the regfile lane and the result lane are compared
 * against an independent model. */
static __u64 scene_off_indexed(void)
{
	static const __u64 REGVALS[3] = { 0x1111ULL, 0x8000000000000000ULL,
					  0xffffffffffffff00ULL };
	static const __u8 SCALES[4] = { 0U, 1U, 2U, 3U };
	static const __s64 DISPS[3] = { 0, -16, 0x1234 };
	unsigned ri, si, di;

	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rax_tag;
	(void)__x86_rcx_tag;
	(void)__x86_rdx_tag;
	(void)__x86_rbx_tag;
	(void)__x86_rsp_tag;
	(void)__x86_rbp_tag;
	(void)__x86_rsi_tag;
	(void)__x86_rdi_tag;
	(void)__x86_r8_tag;
	(void)__x86_r9_tag;
	(void)__x86_r10_tag;
	(void)__x86_r11_tag;
	(void)__x86_r12_tag;
	(void)__x86_r13_tag;
	(void)__x86_r14_tag;
	(void)__x86_r15_tag;
	(void)__x86_sim_abi_kind;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	for (si = 0; si < 4U; si++) {
		for (ri = 0; ri < 3U; ri++) {
			for (di = 0; di < 3U; di++) {
				__u64 iv = REGVALS[ri];
				__s64 disp = DISPS[di];
				__u32 aux =
					KPROG_X86_MEM_AUX(X86_R9, SCALES[si],
							  0U, 0U);
				__s64 want = (__s64)((__u64)disp +
					     (iv << SCALES[si]));
				__s64 got;
				PLANT_REG(X86_R9, iv, 0U);
				got = X86_SIM_L_MEM_OFFSET(aux, disp);
				cases = cases + 2U;
				if (got != want ||
				    X86_SIM_L_READ_REG(X86_R9) != iv) {
					printf("MISMATCH offidx scale=%u iv=0x%llx disp=%lld got=%lld want=%lld\n",
					       SCALES[si],
					       (unsigned long long)iv,
					       (long long)disp,
					       (long long)got,
					       (long long)want);
					return 0xDEAD0064ULL;
				}
			}
		}
		/* the absent index byte must ignore the poisoned register */
		{
			__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, SCALES[si],
						      0U, 0U);
			__s64 disp = -123;
			PLANT_REG(X86_R9, 0xdeadbeefcafef00dULL, 0U);
			cases = cases + 2U;
			if (X86_SIM_L_MEM_OFFSET(aux, disp) != disp ||
			    X86_SIM_L_READ_REG(X86_R9) !=
				    0xdeadbeefcafef00dULL) {
				printf("MISMATCH offidx sentinel scale=%u\n",
				       SCALES[si]);
				return 0xDEAD0065ULL;
			}
		}
	}
	mreg[X86_R9] = 0;
	RAX_SET(0x58ULL);
	X86_SIM_X86_RET();
}

/* Barrier scene: the real bodies that place X86_SIM_L_BARRIER_VAR between
 * offset formation and address use. Two lanes run per body family:
 * heap-anchored (base register holds a scalar pointer) and stack-anchored
 * (base RSP, frame slot). The full heap/stack/regfile state is compared,
 * so the barrier's argument (the computed displacement) staying live is
 * what the scenes observe; a repaint that breaks the body fails compile. */
static __u8 heap0[64];

static void heap0_fill(void)
{
	unsigned i;
	for (i = 0; i < sizeof(heap0); i++)
		heap0[i] = (__u8)(0x70U + i);
}

static void heap0_expect(unsigned i, unsigned char *dst)
{
	unsigned k;
	for (k = 0; k < sizeof(heap0); k++)
		dst[k] = (__u8)(0x70U + k);
	dst[i] = 0xa5U;
}

static __u64 scene_barrier_lanes(unsigned sel)
{
	__u8 exp[64];
	unsigned i;

	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	heap0_fill();
	heap0_expect(0U, exp);
	PLANT_REG(X86_RAX, (__u64)(unsigned long)heap0, 0U);
	mreg[X86_RSP] = 0;
	switch (sel) {
	case 0U: {
		/* EXEC_STORE heap arm: m[0] = 0xa5 (MOV_STORE_IMM op). AUX
		 * carries the packed absent-index word (index byte X86_REG_NONE)
		 * so MEM_OFFSET takes the pure-displacement arm instead of
		 * reading the planted RAX as an index value. */
		X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX,
				     X86_REG_NONE, 0U,
				     KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
				     0ULL);
		heap0_expect(0U, exp);
		break;
	}
	case 1U: {
		/* EXEC_MOV_LOAD heap arm at width 64: r11 = m[8]. The AUX
		 * carries the packed absent-index word (index byte
		 * X86_REG_NONE, width byte 64) so MEM_OFFSET takes the
		 * pure-displacement arm instead of reading the planted RAX as
		 * an index value. The loaded 64-bit value is the LE bytes
		 * 0x78..0x7f of the heap0 fill. */
		X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX,
					X86_WIDTH_64,
					KPROG_X86_MEM_AUX(X86_REG_NONE, 0U,
							  X86_WIDTH_64, 0U),
					8ULL);
		for (i = 0; i < 16U; i++) {
			__u64 want = 0;
			__u8 want_t = 0U;
			if (i == X86_RAX)
				want = (__u64)(unsigned long)heap0;
			else if (i == X86_R11)
				want = 0x7F7E7D7C7B7A7978ULL;
			else if (i == X86_RDI) {
				want = (__u64)(unsigned long)(void *)&xdp_ctx;
				want_t = X86_SIM_TAG_ABI;
			}
			if (i == X86_RAX)
				continue;
			cases = cases + 2U;
			if (X86_SIM_L_READ_REG(i) != want ||
			    X86_SIM_L_REG_TAG(i) != want_t) {
				printf("MISMATCH bar mov reg%u\n", i);
				return 0xDEAD0066ULL;
			}
		}
		RAX_SET(0x59ULL);
		X86_SIM_X86_RET();
	}
	case 2U: {
		/* EXEC_ALU_MEM_IMM heap arm: m[2] += 0x1000 (ADD). The packed
		 * IMM carries the displacement in its high 32 bits
		 * (x86_store_imm_disp) and the addend in its low 32 bits
		 * (x86_store_imm_value), so disp=2 + addend 0x1000 packs as
		 * 0x0000000200001000ULL; the 64-bit read/store land at
		 * &heap0 + 2, in bounds. */
		__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, X86_WIDTH_64,
					      X86_ALU_ADD);
		X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_64, aux,
					   0x0000000200001000ULL);
		heap0_expect(2U, exp);
		memcpy(exp + 2U, "\x10\x00", 2U);
		break;
	}
	default: {
		/* EXEC_LEA stack arm: rbp = rsp + (-16) at width 64. RSP is
		 * unplanted (value 0, tag SCALAR), so the 64-bit stack arm
		 * resolves rbp to the stack-arena slot at STACK_PTR(-16) with
		 * tag STACK, not the raw displacement. AUX carries the packed
		 * absent-index word (width byte 64) for the pure-displacement
		 * MEM_OFFSET arm. */
		X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64,
				   KPROG_X86_MEM_AUX(X86_REG_NONE, 0U,
						     X86_WIDTH_64, 0U),
				   (__u64)(unsigned long)-16LL);
		mreg[X86_RBP] = (__u64)(unsigned long)X86_SIM_L_STACK_PTR(-16);
		mtag[X86_RBP] = X86_SIM_TAG_STACK;
		RAX_SET(0x59ULL);
		COMPARE_REGFILE("bar_lea", 0xDEAD0068ULL);
		X86_SIM_X86_RET();
	}
	}
	for (i = 0; i < 16U; i++) {
		/* regfile must be untouched at the exit byte compare */
		if (i == X86_RAX || i == X86_RDI)
			continue;
		cases = cases + 1U;
		if (X86_SIM_L_READ_REG(i) != 0 ||
		    X86_SIM_L_REG_TAG(i) != 0U) {
			printf("MISMATCH bar reg%u clobbered\n", i);
			return 0xDEAD0069ULL;
		}
	}
	RAX_SET(0x59ULL);
	X86_SIM_X86_RET();
}

/* Struct-member accessors the state-glue scene uses; the raw member names
 * come from the X86_SIM_L_STATE_REG_FIELD fan-out, so a member-name repaint
 * breaks compile here exactly as it does in the header. */
static union x86_sim_gpr *state_cell(struct x86_sim_state *sp, unsigned reg)
{
	switch (reg) {
	case X86_RAX: return &sp->rax;
	case X86_RCX: return &sp->rcx;
	case X86_RDX: return &sp->rdx;
	case X86_RBX: return &sp->rbx;
	case X86_RSP: return &sp->rsp;
	case X86_RBP: return &sp->rbp;
	case X86_RSI: return &sp->rsi;
	case X86_RDI: return &sp->rdi;
	case X86_R8: return &sp->r8;
	case X86_R9: return &sp->r9;
	case X86_R10: return &sp->r10;
	case X86_R11: return &sp->r11;
	case X86_R12: return &sp->r12;
	case X86_R13: return &sp->r13;
	case X86_R14: return &sp->r14;
	case X86_R15: return &sp->r15;
	}
	return &sp->rax;
}

static __u8 *state_tag(struct x86_sim_state *sp, unsigned reg)
{
	switch (reg) {
	case X86_RAX: return &sp->rax_tag;
	case X86_RCX: return &sp->rcx_tag;
	case X86_RDX: return &sp->rdx_tag;
	case X86_RBX: return &sp->rbx_tag;
	case X86_RSP: return &sp->rsp_tag;
	case X86_RBP: return &sp->rbp_tag;
	case X86_RSI: return &sp->rsi_tag;
	case X86_RDI: return &sp->rdi_tag;
	case X86_R8: return &sp->r8_tag;
	case X86_R9: return &sp->r9_tag;
	case X86_R10: return &sp->r10_tag;
	case X86_R11: return &sp->r11_tag;
	case X86_R12: return &sp->r12_tag;
	case X86_R13: return &sp->r13_tag;
	case X86_R14: return &sp->r14_tag;
	case X86_R15: return &sp->r15_tag;
	}
	return &sp->rax_tag;
}

static void write_state_cell(unsigned reg, union x86_sim_gpr *cell,
			     __u8 *tag)
{
	cell->ptr = (void *)(long)(0xE000ULL +
				   ((unsigned long long)reg << 8));
	*tag = (__u8)(reg & 7U);
}

#define WRITE_STATE_CELL(REG, NAME)                                        \
	write_state_cell((REG), &(st).NAME, &(st).NAME##_tag);

/* State-struct scene: instantiate struct x86_sim_state directly (its
 * members come from the X86_SIM_L_STATE_REG_FIELD fan-out), write every
 * member through the fan-out-provided names, and read them back through the
 * same struct so a member-name or layout repaint fails to compile or
 * misroutes a lane. */
static __u64 scene_state_glue(void)
{
	struct x86_sim_state st;
	unsigned i;

	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_sim_skb_ctx;
	(void)__x86_rax;
	(void)__x86_rcx;
	(void)__x86_rdx;
	(void)__x86_rbx;
	(void)__x86_rsp;
	(void)__x86_rbp;
	(void)__x86_rsi;
	(void)__x86_rdi;
	(void)__x86_r8;
	(void)__x86_r9;
	(void)__x86_r10;
	(void)__x86_r11;
	(void)__x86_r12;
	(void)__x86_r13;
	(void)__x86_r14;
	(void)__x86_r15;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_rax_tag;
	(void)__x86_rcx_tag;
	(void)__x86_rdx_tag;
	(void)__x86_rbx_tag;
	(void)__x86_rsp_tag;
	(void)__x86_rbp_tag;
	(void)__x86_rsi_tag;
	(void)__x86_rdi_tag;
	(void)__x86_r8_tag;
	(void)__x86_r9_tag;
	(void)__x86_r10_tag;
	(void)__x86_r11_tag;
	(void)__x86_r12_tag;
	(void)__x86_r13_tag;
	(void)__x86_r14_tag;
	(void)__x86_r15_tag;
	(void)__x86_sim_abi_kind;
	marks_reset();
	/* the fanout-derived member list drives both the write and the
	 * read-back; a member-name repaint breaks compile right here. */
	X86_SIM_L_FOR_EACH_GPR(WRITE_STATE_CELL)
	for (i = 0; i < 16U; i++) {
		__u64 want = 0xE000ULL + ((unsigned long long)i << 8);
		__u8 want_tag = (__u8)(i & 7U);
		union x86_sim_gpr *cell = state_cell(&st, i);
		__u8 *tag = state_tag(&st, i);
		cases = cases + 2U;
		if (cell->ptr != (void *)(long)want || *tag != want_tag) {
			printf("MISMATCH state member reg%u: got 0x%llx/%u want 0x%llx/%u\n",
			       i, (unsigned long long)cell->ptr, *tag,
			       (unsigned long long)want, want_tag);
			return 0xDEAD006AULL;
		}
	}
	st.cf = 1U;
	st.zf = 0U;
	st.sf = 1U;
	st.of = 0U;
	st.xmm0_lo = 0x5AA55AA55AA55AA5ULL;
	st.xmm0_hi = 0xA55AA55AA55AA55AULL;
	st.ret_addr = 0xC3C3C3C3C3C3C3C3ULL;
	st.call_depth = 7U;
	cases = cases + 2U;
	if (st.cf != 1U || st.zf != 0U || st.sf != 1U || st.of != 0U ||
	    st.xmm0_lo != 0x5AA55AA55AA55AA5ULL ||
	    st.xmm0_hi != 0xA55AA55AA55AA55AULL ||
	    st.ret_addr != 0xC3C3C3C3C3C3C3C3ULL) {
		printf("MISMATCH state scalar tails\n");
		return 0xDEAD006BULL;
	}
	cases = cases + 1U;
	if (st.call_depth != 7U) {
		printf("MISMATCH state call depth\n");
		return 0xDEAD006CULL;
	}
	RAX_SET(0x5FULL);
	X86_SIM_X86_RET();
}

/* Guard scene: include the whole header a second time (statement-level
 * objects none); only the include-guard pair lets this compile. */
static int guard_probe_marker;

static __u64 scene_guard(void)
{
	model_reset();
	X86_SIM_ENTRY_XDP(&xdp_ctx);
	(void)__x86_sim_ret_addr;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_stack_mem.b[0];
	(void)__x86_rdi_tag;
	(void)__x86_sim_abi_kind;
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	marks_reset();
	{
#include "../x86/x86_sim_local_bpf.h"
	}
	(void)guard_probe_marker;
	/* a second include only re-runs the guard: re-verify a live lane so
	 * a broke-guard TU still fails here */
	cases = cases + 2U;
	if (X86_SIM_L_REG_TAG(X86_RDI) != X86_SIM_TAG_ABI ||
	    X86_SIM_L_READ_REG(X86_RSP) != 0) {
		printf("MISMATCH guard reinclude lanes\n");
		return 0xDEAD006DULL;
	}
	RAX_SET(0x61ULL);
	X86_SIM_X86_RET();
}

/* Main: drive every scene, then summarize. Body scenes return 0 on success. */
int main(void)
{
	int rc = 0;

	/* JCC forward/back + bare EVAL_CC: driven by the model cond evaluator
	 * over all 14 accepted codes x 4 flag nibbles = both edges observed. */
	{
		static const unsigned CCS[] = {
			X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE,
			X86_CC_E, X86_CC_NE, X86_CC_BE, X86_CC_A,
			X86_CC_S, X86_CC_NS, X86_CC_L, X86_CC_GE,
			X86_CC_LE, X86_CC_G,
		};
		static const unsigned FLAGSETS[4][4] = {
			{ 0U, 0U, 0U, 0U },
			{ 1U, 0U, 0U, 0U },
			{ 0U, 1U, 0U, 0U },
			{ 1U, 1U, 1U, 1U },
		};
		unsigned ci, fi;
		for (ci = 0; ci < 14U; ci++) {
			for (fi = 0; fi < 4U; fi++) {
				int take = model_cc_take(
					CCS[ci], FLAGSETS[fi][0],
					FLAGSETS[fi][1], FLAGSETS[fi][2],
					FLAGSETS[fi][3]);
				__u64 r = scene_jcc_fwd(CCS[ci],
							FLAGSETS[fi][0],
							FLAGSETS[fi][1],
							FLAGSETS[fi][2],
							FLAGSETS[fi][3],
							take);
				cases = cases + 1U;
				if (r != (__u64)(take ? 0x20U : 0x44U)) {
					printf("FAIL jcc fwd cc=%u flags=%u/%u/%u/%u rc=%llx vs %llx\n",
					       CCS[ci], FLAGSETS[fi][0],
					       FLAGSETS[fi][1],
					       FLAGSETS[fi][2],
					       FLAGSETS[fi][3],
					       (unsigned long long)r,
					       (unsigned long long)(take ?
								    0x20ULL :
								    0x44ULL));
					rc = 1;
				}
			}
		}
		for (ci = 0; ci < 14U; ci++) {
			for (fi = 0; fi < 4U; fi++) {
				int take = model_cc_take(
					CCS[ci], FLAGSETS[fi][0],
					FLAGSETS[fi][1], FLAGSETS[fi][2],
					FLAGSETS[fi][3]);
				__u64 r = scene_jcc_back(CCS[ci],
							 FLAGSETS[fi][0],
							 FLAGSETS[fi][1],
							 FLAGSETS[fi][2],
							 FLAGSETS[fi][3],
							 take);
				cases = cases + 1U;
				if (r != (__u64)(take ? 0x20U : 0x44U)) {
					printf("FAIL jcc back cc=%u flags=%u/%u/%u/%u rc=%llx vs %llx\n",
					       CCS[ci], FLAGSETS[fi][0],
					       FLAGSETS[fi][1],
					       FLAGSETS[fi][2],
					       FLAGSETS[fi][3],
					       (unsigned long long)r,
					       (unsigned long long)(take ?
								    0x20ULL :
								    0x44ULL));
					rc = 1;
				}
			}
		}
		/* bare EVAL_CC routing */
		for (ci = 0; ci < 14U; ci++) {
			for (fi = 0; fi < 4U; fi++) {
				int take = model_cc_take(
					CCS[ci], FLAGSETS[fi][0],
					FLAGSETS[fi][1], FLAGSETS[fi][2],
					FLAGSETS[fi][3]);
				__u64 r = scene_eval_cc(CCS[ci],
							FLAGSETS[fi][0],
							FLAGSETS[fi][1],
							FLAGSETS[fi][2],
							FLAGSETS[fi][3],
							take);
				cases = cases + 1U;
				if (r != (__u64)(take ? 0x20U : 0x44U)) {
					printf("FAIL eval_cc cc=%u rc=%llx\n",
					       CCS[ci],
					       (unsigned long long)r);
					rc = 1;
				}
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
	/* skb ret-writeback */
	{
		unsigned save_fail = failures_unused;
		__u32 exit;

		failures_unused = 0;
		skb_ctx.cb[0] = 0U;
		skb_ctx.cb[1] = 0U;
		exit = (__u32)(unsigned long)scene_skb_ret();
		cases = cases + 1U;
		if (skb_ctx.cb[0] != 0x0BADF00DU) {
			printf("FAIL skb cb0 writeback: got %u\n",
			       skb_ctx.cb[0]);
			rc = 1;
		}
		cases = cases + 1U;
		if (skb_ctx.cb[1] != 0x0FEEDFACU) {
			printf("FAIL skb cb1 writeback: got %u\n",
			       skb_ctx.cb[1]);
			rc = 1;
		}
		cases = cases + 1U;
		if (exit != 0x12U) {
			printf("FAIL skb exit: got %u want 18\n", exit);
			rc = 1;
		}
		failures_unused = save_fail;
	}
	/* xdp ret lanes */
	{
		__u32 exit = (__u32)(unsigned long)scene_xdp_ret();
		cases = cases + 1U;
		if (exit != 0x34U) {
			printf("FAIL xdp exit: got %u want 52\n", exit);
			rc = 1;
		}
	}
	/* Regfile glue: pointer/tag reader and writer lanes */
	{
		__u64 r = scene_reg_glue();
		cases = cases + 1U;
		if (r != 0x5CULL) {
			printf("FAIL reg glue rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* run-op forwarding lanes */
	{
		__u64 r = scene_run_ops();
		cases = cases + 1U;
		if (r != 0x5AULL) {
			printf("FAIL run ops rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* subroutine twin ladder */
	{
		__u64 r = scene_sub_ladder();
		cases = cases + 1U;
		if (r != 0ULL) {
			printf("FAIL sub ladder rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* helper dispatch slots */
	{
		__u64 r = scene_helper_dispatch();
		cases = cases + 1U;
		if (r != 0x5EULL) {
			printf("FAIL helper dispatch rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* SP lanes */
	{
		__u64 r = scene_sp_lanes();
		cases = cases + 1U;
		if (r != 0x5BULL) {
			printf("FAIL sp lanes rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}

	/* 0457 scene: ABI-packet pointer loads through LOAD_PTR_ADDR */
	{
		static const __s64 OFFS[2][3] = {
			{ 0, 8, 80 },
			{ 208, 80, 0x1234 },
		};
		unsigned ki, oi, sel;

		for (ki = 0; ki < 2U; ki++) {
			for (oi = 0; oi < 3U; oi++) {
				__u64 expect = (OFFS[ki][oi] == 0x1234)
					? 0xDEAD006FULL : 0x57ULL;
				for (sel = 0; sel < 2U; sel++) {
					__u64 r = scene_ptr_load(
						ki, OFFS[ki][oi], sel);
					cases = cases + 1U;
					if (r != expect) {
						printf("FAIL ptr_load kind=%u off=%lld sel=%u rc=%llx\n",
						       ki,
						       (long long)OFFS[ki][oi],
						       sel,
						       (unsigned long long)r);
						rc = 1;
					}
				}
			}
		}
	}
	/* 0457 scene: MEM_OFFSET indexed-lane bridge (public). */
	{
		__u64 r = scene_off_indexed();
		cases = cases + 1U;
		if (r != 0x58ULL) {
			printf("FAIL off indexed rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* 0457 scene: barrier-var placement across exec bodies. */
	{
		unsigned sel;

		for (sel = 0; sel < 4U; sel++) {
			__u64 r = scene_barrier_lanes(sel);
			cases = cases + 1U;
			if (r != 0x59ULL) {
				printf("FAIL barrier lanes sel=%u rc=%llx\n",
				       sel, (unsigned long long)r);
				rc = 1;
			}
		}
	}
	/* 0457 scene: state-struct member fanout glue. */
	{
		__u64 r = scene_state_glue();
		cases = cases + 1U;
		if (r != 0x5FULL) {
			printf("FAIL state glue rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}
	/* 0457 scene: header include guard lifecycle. */
	{
		__u64 r = scene_guard();
		cases = cases + 1U;
		if (r != 0x61ULL) {
			printf("FAIL guard scene rc=%llx\n",
			       (unsigned long long)r);
			rc = 1;
		}
	}

	if (rc == 0)
		printf("x86 route host cross-check: OK (%lu cases)\n", cases);
	return rc;
}
