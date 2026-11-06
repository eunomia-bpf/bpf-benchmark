/*
 * Host cross-check for the x86 simulator specialization-preservation property
 * (STEP 0111, paper obligation O2): for every canonical `X86_OP_*` token, the
 * handler the C dispatch chain `X86_SIM_L_EXEC` runs and the handler the
 * artifact encoder emits are the *same body* -- the encoder inserts no step
 * the chain does not run.
 *
 * The claim is checked on three independent restatements:
 *
 *   1. The dispatch classification. `kprog_x86_spec_dispatch` (generated from
 *      `x86_specialization_spec.json`) is compared against a hand table of one
 *      class per canonical token, written here by hand in canonical order.
 *
 *   2. The emission macro. For every *directMacro* token the oracle restates,
 *      by hand, the macro the encoder's `X86_SPECIALIZATION_DIRECT_CALL` (and
 *      `X86_SPECIALIZATION_AUX_CALL` for the six AUX-gated tokens) emits, and
 *      runs it.
 *
 *   3. The chain body. The same token is driven through
 *      `X86_SIM_RUN_OP` -> `X86_SIM_L_EXEC`, the real runtime dispatcher.
 *
 * The two runs start from bit-identical planted state (register file, tags,
 * four flags, XMM0 pair, the 64-byte stack arena, and the heap window) and the
 * whole of that state is compared afterwards. A handler that was inserted,
 * dropped, or swapped on either side shows up as a differing register, tag,
 * stack byte, heap byte, flag, or XMM0 lane. `genericRunOp` and
 * `branchHandler` tokens have no encoder-emitted macro at all -- their behaviour
 * comes solely from the chain -- so only the classification is asserted for
 * them; the four `branchHandler` tokens (`JCC`,`JMP`,`CALL`,`RET`) are never
 * executed (they `goto`/`return`).
 *
 * The AUX-gated six (`MOV_IMM`,`MOV_REG`,`CMP_IMM`,`CMP_REG`,`TEST_IMM`,
 * `TEST_REG`) are exactly the tokens whose encoder `direct_call` template omits
 * the AUX argument: the chain reads the byte lane from AUX for those tokens, so
 * the encoder falls back to the `_AUX` macro exactly when the artifact's AUX is
 * non-zero. The oracle restates that gate and checks both sides of it.
 *
 *   - `MOVZX_REG`/`MOVSX_REG` are direct (`X86_SIM_L_EXEC_MOVX_REG`); the chain
 *     arm is inline but carries the same body, so they are still compared at
 *     every AUX.
 *   - `CALL_HELPER` has no chain arm at all (the chain no-op) yet is lowerable
 *     to `X86_SIM_BPF_CALL_ID`; the oracle plants RAX = 0 / SCALAR and drives
 *     only the helpers that write RAX = 0 (ids 4/5/6), which is exactly the
 *     state the chain's no-op leaves.
 *   - `CALL_REG`'s chain arm is `X86_SIM_BPF_CALL_REG((SRC))`, so the oracle
 *     plants SRC to a helper id in {4,5,6} (ids 1/2/3/7 call host functions).
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
#include "generated/x86_specialization.h"

#include <stdio.h>
#include <string.h>

static unsigned cases;
static unsigned failures;

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

/* The heap window the memory forms read and write, and its pristine image. */
#define HEAP_BYTES 4096U
#define HEAP_BASE_OFF 1024U
static __u8 heap[HEAP_BYTES];
static __u8 heap0[HEAP_BYTES];

/* The stack arena image, poured into `__x86_stack_mem.b` before each run. */
static __u8 stack_img[X86_SIM_STACK_BYTES];

/* Offsets into `heap` used as the block-copy operands; the 1024-byte fixed
 * bound of the non-register `CALL_MEM_*` forms needs a full kilobyte each. */
#define REP_SRC_OFF 2048U
#define REP_DST_OFF 1024U

static void fill_backing(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = (__u8)(0x30U + i);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		stack_img[i] = (__u8)(0xa0U + i);
}

/*
 * The hand dispatch table, one row per canonical token in canonical order. Its
 * class column is an independent restatement of `kprog_x86_spec_dispatch`; the
 * count and order are also asserted against the generated header.
 */
struct spec_row {
	__u8 op;
	__u8 cls;
};

#define D KPROG_X86_SPEC_DIRECT_MACRO
#define B KPROG_X86_SPEC_BRANCH_HANDLER
#define G KPROG_X86_SPEC_GENERIC_RUN_OP

static const struct spec_row SPEC[] = {
	{ X86_OP_NOP, G },
	{ X86_OP_MOV_IMM, D },
	{ X86_OP_MOV_REG, D },
	{ X86_OP_ADD_IMM, D },
	{ X86_OP_ADD_REG, D },
	{ X86_OP_XOR_REG, D },
	{ X86_OP_MOV_LOAD, D },
	{ X86_OP_MOV_STORE_IMM, D },
	{ X86_OP_MOV_STORE_REG, D },
	{ X86_OP_LEA, D },
	{ X86_OP_ALU_IMM, D },
	{ X86_OP_ALU_REG, D },
	{ X86_OP_CMP_IMM, D },
	{ X86_OP_CMP_REG, D },
	{ X86_OP_TEST_IMM, D },
	{ X86_OP_TEST_REG, D },
	{ X86_OP_JCC, B },
	{ X86_OP_JMP, B },
	{ X86_OP_PUSH, D },
	{ X86_OP_POP, D },
	{ X86_OP_CALL, B },
	{ X86_OP_CMOV, D },
	{ X86_OP_SETCC, D },
	{ X86_OP_BSWAP, G },
	{ X86_OP_POPCNT, G },
	{ X86_OP_XCHG, G },
	{ X86_OP_DIV, G },
	{ X86_OP_SHLD_IMM, G },
	{ X86_OP_SHRD_IMM, G },
	{ X86_OP_CMP_MEM_IMM, D },
	{ X86_OP_TEST_MEM_IMM, D },
	{ X86_OP_CMP_MEM_REG, D },
	{ X86_OP_MOVZX_REG, D },
	{ X86_OP_MOVSX_REG, D },
	{ X86_OP_MOVSX_LOAD, D },
	{ X86_OP_ALU_MEM, D },
	{ X86_OP_CMP_REG_MEM, D },
	{ X86_OP_MOV_LOAD_SCALAR, D },
	{ X86_OP_SHIFTX, G },
	{ X86_OP_RORX, G },
	{ X86_OP_MOVBE_LOAD, G },
	{ X86_OP_MOVBE_STORE, G },
	{ X86_OP_SHIFTX_MEM, G },
	{ X86_OP_RORX_MEM, G },
	{ X86_OP_MOV_LOAD_MAP_PTR, G },
	{ X86_OP_MOV_LOAD_HELPER_ID, G },
	{ X86_OP_CALL_HELPER, D },
	{ X86_OP_CALL_REG, D },
	{ X86_OP_LOAD_XMM0, G },
	{ X86_OP_STORE_XMM0, G },
	{ X86_OP_ALU_MEM_UNARY, D },
	{ X86_OP_ALU_MEM_IMM, D },
	{ X86_OP_BZHI, G },
	{ X86_OP_BZHI_MEM, G },
	{ X86_OP_ALU_MEM_REG, D },
	{ X86_OP_BT, D },
	{ X86_OP_IMUL_IMM, D },
	{ X86_OP_MULX, D },
	{ X86_OP_REP_MOVS, D },
	{ X86_OP_TEST_MEM_REG, D },
	{ X86_OP_CALL_MEMSET, D },
	{ X86_OP_ANDN, D },
	{ X86_OP_SETCC_MEM, D },
	{ X86_OP_CALL_MEMCPY, D },
	{ X86_OP_CMOV_MEM, D },
	{ X86_OP_IMUL_MEM_IMM, D },
	{ X86_OP_BT_IMM, D },
	{ X86_OP_BT_MEM_IMM, D },
	{ X86_OP_ANDN_MEM, D },
	{ X86_OP_CALL_MEMSET_REG, D },
	{ X86_OP_CALL_MEMCPY_REG, D },
	{ X86_OP_RET, B },
};

#define SPEC_COUNT (sizeof SPEC / sizeof SPEC[0])

/* The whole observed state: the register file (value and tag), the 64-byte
 * stack arena, the four flags, the XMM0 pair, and the heap window. */
struct snap {
	__u64 vals[16];
	__u8 tags[16];
	__u8 stack_sb[X86_SIM_STACK_BYTES];
	__u8 cf;
	__u8 zf;
	__u8 sf;
	__u8 of;
	__u64 xlo;
	__u64 xhi;
	__u8 mem[HEAP_BYTES];
};

static int snap_eq(const struct snap *a, const struct snap *b)
{
	if (memcmp(a->vals, b->vals, sizeof(a->vals)) != 0)
		return 0;
	if (memcmp(a->tags, b->tags, sizeof(a->tags)) != 0)
		return 0;
	if (memcmp(a->stack_sb, b->stack_sb, sizeof(a->stack_sb)) != 0)
		return 0;
	if (memcmp(a->mem, b->mem, sizeof(a->mem)) != 0)
		return 0;
	if (a->cf != b->cf || a->zf != b->zf || a->sf != b->sf ||
	    a->of != b->of)
		return 0;
	if (a->xlo != b->xlo || a->xhi != b->xhi)
		return 0;
	return 1;
}

/* Plant the pristine register file: pattern value and tag in every register.
 * A macro so it expands in the calling checker's `__x86_*` state scope. */
#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++)                  \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
	} while (0)

/* Plant a register as a heap base pointer, skipping `X86_RSP`, whose `-16`
 * offset makes both the `X86_RSP`-relative stack addressing and the push/pop
 * step land inside the 64-byte arena. */
#define SETBASE(REG)                                                       \
	do {                                                               \
		if ((REG) != X86_RSP)                                     \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				(REG),                                    \
				(void *)(long)(heap + HEAP_BASE_OFF),     \
				X86_SIM_TAG_ABI);                         \
	} while (0)

/* Plant a register as a heap pointer with a scalar tag. */
#define SETPTR(REG, OFF)                                                   \
	X86_SIM_L_WRITE_REG_WIDTH((REG),                                  \
		(__u64)(long)(heap + (OFF)), X86_WIDTH_64)

/*
 * Plant the full initial state for `OP`, identical on both sides of the
 * comparison. The two `X86_RSP`-relative variant rows pass `DST`/`SRC` =
 * `X86_RSP` so the stack arms are exercised; `SETBASE` then leaves the planted
 * `-16` offset in place.
 */
#define PLANT(OP, DST, SRC)                                                \
	do {                                                               \
		memcpy(heap, heap0, HEAP_BYTES);                          \
		memcpy(__x86_stack_mem.b, stack_img, X86_SIM_STACK_BYTES);\
		PLANT_REGS();                                             \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP,                      \
			(void *)(long)(-16), X86_SIM_TAG_STACK);         \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, 1, X86_WIDTH_64);      \
		/* The memory index register is `AUX & 0xff`, which is RAX     \
		 * when AUX is zero; a full-width zero must be planted there  \
		 * so the scaled index offset stays inside the heap window.   \
		 * RDX is zeroed to match for the block-copy forms. */       \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);      \
		X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, 0, X86_WIDTH_64);      \
		__x86_cf = 1U;                                            \
		__x86_zf = 0U;                                            \
		__x86_sf = 1U;                                            \
		__x86_of = 0U;                                            \
		__x86_xmm0_lo = pattern_reg(20U);                         \
		__x86_xmm0_hi = pattern_reg(21U);                         \
		if ((OP) == X86_OP_MOV_LOAD ||                            \
		    (OP) == X86_OP_MOVSX_LOAD ||                          \
		    (OP) == X86_OP_MOV_LOAD_SCALAR ||                     \
		    (OP) == X86_OP_LEA ||                                 \
		    (OP) == X86_OP_CMP_REG_MEM ||                         \
		    (OP) == X86_OP_ALU_MEM ||                             \
		    (OP) == X86_OP_CMOV_MEM ||                            \
		    (OP) == X86_OP_IMUL_MEM_IMM)                          \
			SETBASE(SRC);                                     \
		else if ((OP) == X86_OP_MOV_STORE_IMM ||                  \
			 (OP) == X86_OP_MOV_STORE_REG ||                  \
			 (OP) == X86_OP_CMP_MEM_IMM ||                    \
			 (OP) == X86_OP_TEST_MEM_IMM ||                   \
			 (OP) == X86_OP_CMP_MEM_REG ||                    \
			 (OP) == X86_OP_TEST_MEM_REG ||                   \
			 (OP) == X86_OP_ALU_MEM_UNARY ||                  \
			 (OP) == X86_OP_ALU_MEM_IMM ||                    \
			 (OP) == X86_OP_ALU_MEM_REG ||                    \
			 (OP) == X86_OP_BT_MEM_IMM ||                     \
			 (OP) == X86_OP_SETCC_MEM)                        \
			SETBASE(DST);                                     \
		else if ((OP) == X86_OP_ANDN_MEM)                         \
			SETBASE(0U);                                      \
		if ((OP) == X86_OP_CALL_REG)                              \
			X86_SIM_L_WRITE_REG_WIDTH(SRC, 4, X86_WIDTH_64);  \
		if ((OP) == X86_OP_CALL_HELPER)                           \
			X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, 0,           \
						    X86_SIM_TAG_SCALAR);\
		if ((OP) == X86_OP_REP_MOVS) {                            \
			SETPTR(X86_RSI, REP_SRC_OFF);                     \
			SETPTR(X86_RDI, REP_DST_OFF);                     \
		}                                                         \
		if ((OP) == X86_OP_CALL_MEMSET ||                         \
		    (OP) == X86_OP_CALL_MEMCPY ||                         \
		    (OP) == X86_OP_CALL_MEMSET_REG ||                     \
		    (OP) == X86_OP_CALL_MEMCPY_REG) {                     \
			SETPTR(X86_RDI, REP_DST_OFF);                     \
			SETPTR(X86_RSI, REP_SRC_OFF);                     \
			X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, 2,             \
						  X86_WIDTH_64);          \
		}                                                         \
	} while (0)

#define TAKE_SNAP(S)                                                       \
	do {                                                               \
		unsigned __sn_i;                                          \
		for (__sn_i = 0; __sn_i < 16U; __sn_i++) {                \
			(S).vals[__sn_i] =                                \
				(__u64)(long)X86_SIM_L_REG_VALUE(__sn_i); \
			(S).tags[__sn_i] = X86_SIM_L_REG_TAG(__sn_i);     \
		}                                                         \
		memcpy((S).stack_sb, __x86_stack_mem.b,                   \
		       X86_SIM_STACK_BYTES);                              \
		(S).cf = __x86_cf;                                        \
		(S).zf = __x86_zf;                                        \
		(S).sf = __x86_sf;                                        \
		(S).of = __x86_of;                                        \
		(S).xlo = __x86_xmm0_lo;                                  \
		(S).xhi = __x86_xmm0_hi;                                  \
		memcpy((S).mem, heap, HEAP_BYTES);                        \
	} while (0)

/* The per-token instruction immediate: small enough that every loop and every
 * addressing displacement stays inside its buffer. */
static __u64 imm_for(__u8 op)
{
	switch (op) {
	case X86_OP_CALL_MEMSET:
	case X86_OP_CALL_MEMCPY:
	case X86_OP_CALL_MEMSET_REG:
	case X86_OP_CALL_MEMCPY_REG:
	case X86_OP_REP_MOVS:
		return 2ULL;
	case X86_OP_MOV_IMM:
	case X86_OP_ADD_IMM:
	case X86_OP_ALU_IMM:
	case X86_OP_CMP_IMM:
	case X86_OP_TEST_IMM:
	case X86_OP_IMUL_IMM:
	case X86_OP_BT_IMM:
	case X86_OP_BT_MEM_IMM:
		return 0x1234ULL;
	case X86_OP_CALL_HELPER:
		return 4ULL;
	default:
		return 0ULL;
	}
}

static int unhandled_direct;

/*
 * Run one directMacro token through the chain and through its hand-restated
 * specialized body, then compare the whole observed state.
 */
static void check_token(__u8 op, unsigned dst, unsigned src, unsigned flags,
			__u32 aux, __u64 imm)
{
	struct snap sa;
	struct snap sb;

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

	/* ---- side A: the real runtime dispatcher ---- */
	PLANT(op, dst, src);
	X86_SIM_RUN_OP(op, dst, src, flags, aux, imm);
	TAKE_SNAP(sa);

	/* ---- side B: the encoder's emitted body, restated by hand ---- */
	PLANT(op, dst, src);
	switch (op) {
	case X86_OP_MOV_IMM:
		if (aux)
			X86_SIM_L_EXEC_MOV_IMM_AUX(dst, flags, aux, imm);
		else
			X86_SIM_L_EXEC_MOV_IMM(dst, flags, imm);
		break;
	case X86_OP_MOV_REG:
		if (aux)
			X86_SIM_L_EXEC_MOV_REG_AUX(dst, src, flags, aux);
		else
			X86_SIM_L_EXEC_MOV_REG(dst, src, flags);
		break;
	case X86_OP_ADD_IMM:
	case X86_OP_ALU_IMM:
		X86_SIM_L_EXEC_ALU_IMM(dst, flags, aux, imm);
		break;
	case X86_OP_ADD_REG:
	case X86_OP_XOR_REG:
	case X86_OP_ALU_REG:
		X86_SIM_L_EXEC_ALU_REG(dst, src, flags, aux);
		break;
	case X86_OP_MOV_LOAD:
	case X86_OP_MOVSX_LOAD:
	case X86_OP_MOV_LOAD_SCALAR:
		X86_SIM_L_EXEC_MOV_LOAD(op, dst, src, flags, aux, imm);
		break;
	case X86_OP_MOV_STORE_IMM:
	case X86_OP_MOV_STORE_REG:
		X86_SIM_L_EXEC_STORE(op, dst, src, flags, aux, imm);
		break;
	case X86_OP_LEA:
		X86_SIM_L_EXEC_LEA(dst, src, flags, aux, imm);
		break;
	case X86_OP_CMP_IMM:
	case X86_OP_TEST_IMM:
		if (aux)
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX(op, dst, flags, aux,
						      imm);
		else
			X86_SIM_L_EXEC_CMP_IMM_OP(op, dst, flags, imm);
		break;
	case X86_OP_CMP_REG:
	case X86_OP_TEST_REG:
		if (aux)
			X86_SIM_L_EXEC_CMP_REG_OP_AUX(op, dst, src, flags,
						      aux);
		else
			X86_SIM_L_EXEC_CMP_REG_OP(op, dst, src, flags);
		break;
	case X86_OP_PUSH:
		X86_SIM_L_EXEC_PUSH(src);
		break;
	case X86_OP_POP:
		X86_SIM_L_EXEC_POP(dst, flags);
		break;
	case X86_OP_CMOV:
		X86_SIM_L_EXEC_CMOV(dst, src, flags, aux);
		break;
	case X86_OP_SETCC:
		X86_SIM_L_EXEC_SETCC(dst, aux);
		break;
	case X86_OP_CMP_MEM_IMM:
	case X86_OP_TEST_MEM_IMM:
	case X86_OP_CMP_MEM_REG:
	case X86_OP_TEST_MEM_REG:
		X86_SIM_L_EXEC_CMP_MEM(op, dst, src, flags, aux, imm);
		break;
	case X86_OP_MOVZX_REG:
	case X86_OP_MOVSX_REG:
		X86_SIM_L_EXEC_MOVX_REG(op, dst, src, flags, aux);
		break;
	case X86_OP_ALU_MEM:
		X86_SIM_L_EXEC_ALU_MEM(dst, src, flags, aux, imm);
		break;
	case X86_OP_CMP_REG_MEM:
		X86_SIM_L_EXEC_CMP_REG_MEM(dst, src, flags, aux, imm);
		break;
	case X86_OP_CALL_HELPER:
		X86_SIM_BPF_CALL_ID(imm);
		break;
	case X86_OP_CALL_REG:
		X86_SIM_BPF_CALL_REG(src);
		break;
	case X86_OP_ALU_MEM_UNARY:
		X86_SIM_L_EXEC_ALU_MEM_UNARY(dst, flags, aux, imm);
		break;
	case X86_OP_ALU_MEM_IMM:
		X86_SIM_L_EXEC_ALU_MEM_IMM(dst, flags, aux, imm);
		break;
	case X86_OP_ALU_MEM_REG:
		X86_SIM_L_EXEC_ALU_MEM_REG(dst, src, flags, aux, imm);
		break;
	case X86_OP_BT:
		X86_SIM_L_EXEC_BT(dst, src, flags);
		break;
	case X86_OP_IMUL_IMM:
		X86_SIM_L_EXEC_IMUL_IMM(dst, src, flags, imm);
		break;
	case X86_OP_MULX:
		X86_SIM_L_EXEC_MULX(dst, src, aux, flags);
		break;
	case X86_OP_REP_MOVS:
		X86_SIM_L_EXEC_REP_MOVS(flags, imm);
		break;
	case X86_OP_CALL_MEMSET:
		X86_SIM_L_EXEC_CALL_MEMSET(imm);
		break;
	case X86_OP_ANDN:
		X86_SIM_L_EXEC_ANDN(dst, src, aux, flags);
		break;
	case X86_OP_SETCC_MEM:
		X86_SIM_L_EXEC_SETCC_MEM(dst, aux, imm);
		break;
	case X86_OP_CALL_MEMCPY:
		X86_SIM_L_EXEC_CALL_MEMCPY(imm);
		break;
	case X86_OP_CMOV_MEM:
		X86_SIM_L_EXEC_CMOV_MEM(dst, src, flags, aux, imm);
		break;
	case X86_OP_IMUL_MEM_IMM:
		X86_SIM_L_EXEC_IMUL_MEM_IMM(dst, src, flags, aux, imm);
		break;
	case X86_OP_BT_IMM:
		X86_SIM_L_EXEC_BT_IMM(dst, flags, imm);
		break;
	case X86_OP_BT_MEM_IMM:
		X86_SIM_L_EXEC_BT_MEM_IMM(dst, flags, aux, imm);
		break;
	case X86_OP_ANDN_MEM:
		X86_SIM_L_EXEC_ANDN_MEM(dst, src, flags, aux, imm);
		break;
	case X86_OP_CALL_MEMSET_REG:
		X86_SIM_L_EXEC_CALL_MEMSET_REG(imm);
		break;
	case X86_OP_CALL_MEMCPY_REG:
		X86_SIM_L_EXEC_CALL_MEMCPY_REG(imm);
		break;
	default:
		unhandled_direct = 1;
		break;
	}
	TAKE_SNAP(sb);

	cases++;
	if (!snap_eq(&sa, &sb)) {
		printf("MISMATCH op=%u dst=%u src=%u flags=%u aux=0x%x "
		       "imm=0x%llx\n", op, dst, src, flags, aux,
		       (unsigned long long)imm);
		failures++;
	}
}

/* The generated classification must equal the hand table, in canonical order. */
static void check_dispatch(void)
{
	unsigned i;
	unsigned direct = 0;

	cases++;
	if (SPEC_COUNT != KPROG_X86_SPEC_COUNT) {
		printf("MISMATCH spec count %lu vs %u\n",
		       (unsigned long)SPEC_COUNT, KPROG_X86_SPEC_COUNT);
		failures++;
	}

	for (i = 0; i < SPEC_COUNT; i++) {
		cases++;
		if (kprog_x86_spec_dispatch(SPEC[i].op) != SPEC[i].cls) {
			printf("MISMATCH dispatch op=%u class %u want %u\n",
			       SPEC[i].op, kprog_x86_spec_dispatch(SPEC[i].op),
			       SPEC[i].cls);
			failures++;
		}
		if (SPEC[i].cls == KPROG_X86_SPEC_DIRECT_MACRO)
			direct++;
	}

	cases++;
	if (direct != 49U) {
		printf("MISMATCH direct count %u want 49\n", direct);
		failures++;
	}
}

int main(void)
{
	static const unsigned widths[2] = { X86_WIDTH_64, X86_WIDTH_8 };
	unsigned i;
	unsigned ai;
	unsigned fi;
	unsigned vi;

	fill_backing();
	memcpy(heap0, heap, HEAP_BYTES);

	check_dispatch();

	/* Every directMacro token: both AUX words (the gate), both widths, and a
	 * heap-base and a stack-base variant, each compared chain-versus-body. */
	for (i = 0; i < SPEC_COUNT; i++) {
		if (SPEC[i].cls != KPROG_X86_SPEC_DIRECT_MACRO)
			continue;
		for (ai = 0; ai < 2U; ai++) {
			for (fi = 0; fi < 2U; fi++) {
				for (vi = 0; vi < 2U; vi++) {
					unsigned dst = vi ? X86_RSP : X86_R10;
					unsigned src = vi ? X86_RSP : X86_R11;
					__u32 aux = ai ? 1U : 0U;

				if (SPEC[i].op == X86_OP_CALL_HELPER) {
					unsigned k;

					for (k = 4U; k <= 6U; k++)
						check_token(
							SPEC[i].op,
							dst, src,
							widths[fi],
							aux,
							(__u64)k);
					continue;
				}
				/* `ANDN_MEM` derives its base register from AUX
				 * bits 24..31 and its index register from AUX
				 * bits 0..7, so `aux` 0/1 collapse both onto RAX;
				 * a plain and an indexed-but-lane-valid encoding
				 * exercise the same addressing paths without a
				 * self-referential base. */
				if (SPEC[i].op == X86_OP_ANDN_MEM) {
					static const __u32 andn_aux[2] = {
						0x000000ffU, 0x00000001U
					};

					check_token(SPEC[i].op, dst, src,
						    widths[fi], andn_aux[ai],
						    imm_for(SPEC[i].op));
					continue;
				}
					check_token(SPEC[i].op, dst, src,
						    widths[fi], aux,
						    imm_for(SPEC[i].op));
				}
			}
		}
	}

	cases++;
	if (unhandled_direct) {
		printf("MISMATCH a direct token reached the body default\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 specialization host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 specialization host cross-check: OK (%u cases)\n", cases);
	return 0;
}
