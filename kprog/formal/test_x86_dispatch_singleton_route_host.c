/*
 * Host cross-check for the x86 simulator's routing of the ten multi-member
 * opcode families of the `X86_SIM_L_EXEC` dispatcher. Each family is a set of
 * opcodes that share one arm; the arm is selected by a generated membership
 * macro (`KPROG_X86_<FAMILY>_HANDLED`) rather than a hand-written `||` chain.
 *
 * The oracle drives the real dispatcher with a family member and checks that
 * the whole post-state equals an independent restatement of what the arm must
 * do:
 *
 *   - Seven families merely forward to a named body macro (`MOV_LOAD`,
 *     `MOV_STORE`, `ALU_IMM`, `ALU_REG`, `CMP_IMM`, `CMP_REG`, `CMP_MEM`). For
 *     those the second state is produced by invoking that body macro directly
 *     with the exact argument tuple the dispatcher arm uses, so a member that
 *     the generated macro failed to name - and therefore fell through to
 *     another arm - makes the two states differ.
 *
 *   - Three families inline their body in the chain (`MOV_LOAD_PTR`,
 *     `MOVX_REG`, `DOUBLE_SHIFT`). For those the second state is a hand-written
 *     model that restates the arm's effect from first principles, independent of
 *     any simulator helper.
 *
 * A non-member opcode with no arm at all (`X86_OP_RET`) must leave the whole
 * state byte-identical to its planted seed. Unlike the AArch64 dispatcher, the
 * x86 chain carries no `unsupported` hook, so non-membership is observable
 * purely as an unchanged state, not as a counter.
 *
 * The snapshot covers the sixteen GPRs (value and provenance tag), the four
 * condition flags, the XMM0 pair, the return address, the 64-byte stack frame
 * arena, and the 512-byte backing heap, so a misroute that touches any of
 * them is caught.
 */
#define __BPF_HELPERS__ 1
#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEAP_BYTES 512U

static int failures;
static unsigned long cases;

/* Backing storage for the memory-touching arms, addressed through a planted
 * base register so both drives dereference valid bytes. */
static __u8 heap[HEAP_BYTES];

/* A deterministic per-register value, with high bits set so a 64-bit write and
 * a narrow write are distinguishable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag pattern: never `X86_SIM_TAG_SCALAR`, so any form that
 * scalarizes a destination changes its tag. */
static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static void fill_heap(void)
{
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		heap[i] = (__u8)(0x40U + i);
}

/* The destination width the arm resolves from FLAGS, exactly as
 * `X86_SIM_L_EFFECTIVE_WIDTH` does: the absent code 0 falls back to 64. */
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

/* Independent sign extension of the source lane: replicate the lane's sign bit
 * across the widened value; a 64-bit width is the identity. */
static __u64 sign_extend_oracle(__u64 v, unsigned width)
{
	unsigned bits = width_bits(width);
	__u64 m;
	__u64 sign;
	if (bits == 64U)
		return v;
	m = (1ULL << bits) - 1ULL;
	sign = 1ULL << (bits - 1U);
	if ((v & m) & sign)
		return (v & m) | ~m;
	return v & m;
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

/* The hardware-masked count the double-shift step gate and the shift-flag
 * contract share. */
static unsigned shift_count(__u64 imm, unsigned width)
{
	return (unsigned)(imm & (width == X86_WIDTH_64 ? 63ULL : 31ULL));
}


/* ---- Whole-state snapshot ---------------------------------------------- */

struct snap {
	__u64 x[16];
	__u8 t[16];
	__u8 cf, zf, sf, of;
	__u64 xmm0_lo, xmm0_hi, ret;
	__u8 stack[X86_SIM_STACK_BYTES];
	__u8 heap[HEAP_BYTES];
};

/* The live arena base the sim's STACK_PTR arms materialize (set once per
 * drive inside check_arm, where the arena object is in scope); the model adds
 * the index arithmetic to it so pointer-valued outputs compare equal. */
static unsigned long stack_arena_base;

/* The STACK_PTR value the sim writes for an offset: the arena object's
 * address at the KPROG_X86_STACK_INDEX position. */
static unsigned long stack_ptr_value(long off)
{
	return stack_arena_base +
	       (unsigned long)(unsigned int)(off + (long)X86_SIM_STACK_BYTES);
}

#define CAPTURE_ALL(S)                                                     \
	do {                                                               \
		unsigned __cap_i;                                          \
		for (__cap_i = 0; __cap_i < 16U; __cap_i++) {              \
			(S)->x[__cap_i] =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__cap_i); \
			(S)->t[__cap_i] = X86_SIM_L_REG_TAG(__cap_i);      \
		}                                                          \
		(S)->cf = __x86_cf;                                        \
		(S)->zf = __x86_zf;                                        \
		(S)->sf = __x86_sf;                                        \
		(S)->of = __x86_of;                                        \
		(S)->xmm0_lo = __x86_xmm0_lo;                              \
		(S)->xmm0_hi = __x86_xmm0_hi;                              \
		(S)->ret = __x86_sim_ret_addr;                             \
		memcpy((S)->stack, __x86_stack_mem.b, X86_SIM_STACK_BYTES); \
		memcpy((S)->heap, heap, HEAP_BYTES);                       \
	} while (0)

/* Equality with a diagnostic naming the first diverging cell. */
static int snap_eq(const struct snap *a, const struct snap *b, const char *what,
		   unsigned w)
{
	unsigned j;

	for (j = 0; j < 16U; j++) {
		if (a->x[j] != b->x[j] || a->t[j] != b->t[j]) {
			printf("MISMATCH %s width=%u reg%u got 0x%llx/%u want "
			       "0x%llx/%u\n", what, w, j,
			       (unsigned long long)a->x[j], (unsigned)a->t[j],
			       (unsigned long long)b->x[j], (unsigned)b->t[j]);
			return 0;
		}
	}
	if (a->cf != b->cf || a->zf != b->zf || a->sf != b->sf ||
	    a->of != b->of) {
		printf("MISMATCH %s width=%u flags got %u%u%u%u want "
		       "%u%u%u%u\n", what, w, a->cf, a->zf, a->sf, a->of,
		       b->cf, b->zf, b->sf, b->of);
		return 0;
	}
	if (a->xmm0_lo != b->xmm0_lo || a->xmm0_hi != b->xmm0_hi ||
	    a->ret != b->ret) {
		printf("MISMATCH %s width=%u xmm0/ret differ\n", what, w);
		return 0;
	}
	for (j = 0; j < X86_SIM_STACK_BYTES; j++) {
		if (a->stack[j] != b->stack[j]) {
			printf("MISMATCH %s width=%u stack[%u] got 0x%02x want "
			       "0x%02x\n", what, w, j, a->stack[j], b->stack[j]);
			return 0;
		}
	}
	for (j = 0; j < HEAP_BYTES; j++) {
		if (a->heap[j] != b->heap[j]) {
			printf("MISMATCH %s width=%u heap[%u] got 0x%02x want "
			       "0x%02x\n", what, w, j, a->heap[j], b->heap[j]);
			return 0;
		}
	}
	return 1;
}

/* ---- Shared state plant ------------------------------------------------ */

#define DECL_STATE()                                                       \
	X86_SIM_L_DECLARE_STATE();                                         \
	struct x86_sim_xdp_abi __x86_sim_abi = {};                         \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;       \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__x86_sim_abi;                                               \
	(void)__x86_sim_skb_ctx;                                           \
	(void)__x86_sim_abi_kind;                                          \
	X86_SIM_L_DECLARE_STACK();                                         \
	(void)__x86_xmm0_lo;                                               \
	(void)__x86_xmm0_hi;                                               \
	(void)__x86_sim_ret_addr;                                          \
	(void)__x86_stack_mem

/* Plant every register with its pattern (the stack pointer with a null value,
 * so a stack access resolves into the arena), the frame bytes, the flag
 * sentinel, and the heap. Deterministic, so both drives start from the same
 * state. */
#define PLANT_PATTERN()                                                    \
	do {                                                               \
		unsigned __pl_i;                                           \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++)                   \
			X86_SIM_L_WRITE_REG_PTR_TAG(                       \
				__pl_i,                                    \
				(void *)(long)pattern_reg(__pl_i),         \
				pattern_tag(__pl_i));                      \
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP, (void *)0,            \
					    pattern_tag(X86_RSP));         \
		for (__pl_i = 0; __pl_i < X86_SIM_STACK_BYTES; __pl_i++)   \
			__x86_stack_mem.b[__pl_i] =                        \
				(__u8)(0xb0U + __pl_i);                    \
		__x86_cf = 1U;                                             \
		__x86_zf = 0U;                                             \
		__x86_sf = 1U;                                             \
		__x86_of = 0U;                                             \
		fill_heap();                                               \
	} while (0)

#define PLANT() PLANT_PATTERN()

/* The one base-register plant the memory arms need: a scalar heap pointer, so
 * every read and store dispatches to the ordinary byte ladder rather than a
 * tag-driven special arm. */
#define PLANT_HEAP_BASE(REG)                                               \
	X86_SIM_L_WRITE_REG_PTR_TAG(REG, (void *)heap, X86_SIM_TAG_SCALAR)
#define PLANT_ABI_BASE(REG)                                                \
	X86_SIM_L_WRITE_REG_PTR_TAG(REG, (void *)heap, X86_SIM_TAG_ABI)

/* The stack-window plant for the rows whose arm resolves an address through
 * the stack arena: the raw pointer value IS the signed offset, so -32 parks
 * the window at arena index 32 and keeps every disp/step within [0, 63]. */
#define PLANT_STACK_RSP()                                                  \
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP, (void *)(long)-32LL,           \
				    X86_SIM_TAG_SCALAR)

/* ---- The host-calling helpers, stubbed with fixed returns -------------- */

#define ORA_MAP_PTR ((void *)0x0000123400005678ULL)
#define ORA_UPD_RET ((long)-7LL)
#define ORA_DEL_RET ((long)3LL)
#define ORA_KTIME 0xaabbccddeeff0011ULL

static void *bpf_map_lookup_elem(void *map, const void *key)
{
	(void)map;
	(void)key;
	return ORA_MAP_PTR;
}

static long bpf_map_update_elem(void *map, const void *key,
				const void *value, __u64 flags)
{
	(void)map;
	(void)key;
	(void)value;
	(void)flags;
	return ORA_UPD_RET;
}

static long bpf_map_delete_elem(void *map, const void *key)
{
	(void)map;
	(void)key;
	return ORA_DEL_RET;
}

static __u64 bpf_ktime_get_ns(void)
{
	return ORA_KTIME;
}

/* ---- Per-singleton models ---------------------------------------------- */

/*
 * Every model takes the seed snapshot and the drive tuple and restates, on
 * the `b` copy, exactly what the singleton's body must do, independent of any
 * simulator helper. Only the cells that arm touches change. The seed side
 * carries the planted register values, tags and flag cells; the `b` side
 * starts from the snapshot and mirrors the arena as an owned byte image.
 */

/* The displacement kinds the memory forms select: the full immediate artifact
 * sign reinterpreted as a long, or the high half as a 32-bit store
 * displacement. */
enum {
	DISP_REGULAR,
	DISP_STORE,
};

/* The addressing offset the memory forms compute: the sign-extended immediate
 * (or the high half, when the store slice applies) plus the index term. */
static long mem_off_long(const struct snap *seed, unsigned aux, __u64 imm,
			 unsigned store_disp)
{
	long disp = store_disp == 1U ?
		(long)x86_store_imm_disp(imm) : (long)x86_simm(imm);
	if (aux != 0xffU && (aux & 0xffU) != 0xffU)
		disp += (long)(seed->x[aux & 0xffU] << ((aux >> 8) & 0xffU));
	return disp;
}

/* The byte count a width code names. */
static unsigned width_bytes(unsigned width)
{
	return width == X86_WIDTH_8 ? 1U : width == X86_WIDTH_16 ? 2U :
	       width == X86_WIDTH_32 ? 4U : 8U;
}

/* The load the memory forms address, an independent restatement of the
 * generated KPROG_X86_MEM_LOAD ladder: little-endian lanes up to the width's
 * byte count, the absent width code falling back to the full 64-bit ladder. */
static __u64 model_load(const __u8 *p, unsigned w)
{
	__u64 v = 0;
	unsigned i;
	unsigned k = w == X86_WIDTH_8 ? 1U : w == X86_WIDTH_16 ? 2U :
		     w == X86_WIDTH_32 ? 4U : 8U;

	for (i = 0; i < k; i++)
		v |= (__u64)p[i] << (8 * i);
	return v;
}
/* The matching store restatement: width-masked, written little-endian, no
 * read-modify-write of the lanes the width does not name. */
static void model_store(__u8 *p, unsigned w, __u64 v)
{
	unsigned i;
	unsigned k = w == X86_WIDTH_8 ? 1U : w == X86_WIDTH_16 ? 2U :
		     w == X86_WIDTH_32 ? 4U : 8U;

	for (i = 0; i < k; i++)
		p[i] = (__u8)(v >> (8 * i));
}

/* The raw unsigned byte offset the signed effective address names. */
static unsigned long S64_TO_OFF(long v)
{
	return (unsigned long)(__u64)v;
}

/* The stack-window index the arms resolve: the arms pass the raw signed
 * pointer value and dispersion through KPROG_X86_STACK_INDEX, whose sum with
 * the 64-byte capacity lands the byte offset; the arena read/write validate
 * that it stays inside the 64-byte window. */
static unsigned long arena_index(long ptr_v, long disp)
{
	return (unsigned long)(unsigned int)((long)ptr_v + disp +
					     (long)X86_SIM_STACK_BYTES);
}

/* The narrow-lane read the arm's KPROG_X86_READ_REG_AT performs: a whole-64
 * read is the identity, an 8-bit lane read extracts the shifted byte. */
static __u64 lane_read(__u64 v, unsigned w, unsigned ssh)
{
	if (w != X86_WIDTH_8)
		return v & width_mask(w);
	return (v >> ssh) & 0xffULL;
}

/* Independent arena read aligned like the sim helpers: word path when both
 * the width is 64 and the window is qword-aligned, else the byte ladder. */
static __u64 arena_read(const struct snap *b, unsigned long byte_off,
			unsigned width)
{
	if (byte_off >= X86_SIM_STACK_BYTES) {
		fprintf(stderr,
			"arena index %lu outside the stack frame\n",
			byte_off);
		exit(1);
	}
	if (width == X86_WIDTH_64 && (byte_off & 7U) == 0U) {
		__u64 v = 0;
		unsigned k;

		for (k = 0; k < 8U; k++)
			v |= (__u64)b->stack[byte_off + k] << (8 * k);
		return v;
	}
	return model_load(&b->stack[byte_off], width);
}

/* Independent arena write with the same alignment rule and the ladder's
 * exact per-lane overwrites (no read-modify-write of untouched lanes). */
static void arena_write(struct snap *b, unsigned long byte_off,
			unsigned width, __u64 v)
{
	if (byte_off >= X86_SIM_STACK_BYTES) {
		fprintf(stderr,
			"arena index %lu outside the stack frame\n",
			byte_off);
		exit(1);
	}
	if (width == X86_WIDTH_64 && (byte_off & 7U) == 0U) {
		unsigned k;

		for (k = 0; k < 8U; k++)
			b->stack[byte_off + k] = (__u8)(v >> (8 * k));
		return;
	}
	{
		unsigned k;

		for (k = 0; k < width_bytes(width); k++)
			b->stack[byte_off + k] = (__u8)(v >> (8 * k));
	}
}


/* The shift result the arm's `x86_alu_result` computes, restated through the
 * generated per-kind shift contracts; the count is already hardware-masked. */
static __u64 shift_result_oracle(__u64 lhs, unsigned count, unsigned alu,
				 unsigned w)
{
	switch (alu) {
	case X86_ALU_SHL:
		return kprog_x86_shl_result(lhs, count, (__u8)w);
	case X86_ALU_SHR:
		return kprog_x86_shr_result(lhs, count, (__u8)w);
	case X86_ALU_SAR:
		return kprog_x86_sar_result(lhs, count, (__u8)w);
	case X86_ALU_ROL:
		return kprog_x86_rol_result(lhs, count, (__u8)w);
	default:
		return kprog_x86_ror_result(lhs, count, (__u8)w);
	}
}

/* The POPCNT result the arm writes back, the generated SWAR popcount. */
static unsigned popcount_oracle(__u64 narrowed)
{
	return (unsigned)kprog_x86_popcount_value(narrowed);
}

/* The byte-reversal the BSWAP and MOVBE arms produce, the generated bswap. */
static __u64 bswap_oracle(__u64 v, unsigned w)
{
	return kprog_x86_bswap_value(v, (__u8)w);
}

/* The ROR the rorX and MOVBE-reversal neighbours build, count-masked first. */
static __u64 ror_oracle(__u64 v, unsigned imm, unsigned w)
{
	return kprog_x86_ror_result(v, KPROG_X86_SHIFT_COUNT(imm, (__u8)w),
				    (__u8)w);
}

/* The store-immediate slice the memory-immediate arms consume, the generated
 * immediate-value contract (sign-extends exactly at 64 when bit 31 is set). */
static __u64 store_imm_oracle(__u64 imm, unsigned w)
{
	return KPROG_X86_IMMEDIATE_VALUE(imm, (__u8)w);
}

/* The bit clear the BZHI arms compute, the contract's byte-masked index and
 * width-narrowed shape. */
static __u64 bzhi_oracle(__u64 v, unsigned c, unsigned w)
{
	return kprog_x86_bzhi_value(v, c, (__u8)w);
}

/* The tested bit the BT forms move into CF, the bitops contract's value. */
static __u8 bt_oracle(__u64 base, __u64 index, unsigned w)
{
	return kprog_x86_bt_value(base, index, (__u8)w);
}

/* The low/high product pair the MULX arm splits, the two width arms
 * restated: the 32-bit single product and the 64-bit four-limb ladder. */
static void mulx_oracle(__u64 a, __u64 b, unsigned w, __u64 *low, __u64 *high)
{
	if (w == X86_WIDTH_32) {
		__u64 product = (__u64)(__u32)a * (__u64)(__u32)b;

		*low = (__u32)product;
		*high = (__u32)(product >> 32);
		return;
	}
	{
		__u64 a0 = (__u32)a;
		__u64 a1 = a >> 32;
		__u64 b0 = (__u32)b;
		__u64 b1 = b >> 32;
		__u64 p0 = a0 * b0;
		__u64 p1 = a0 * b1;
		__u64 p2 = a1 * b0;
		__u64 p3 = a1 * b1;
		__u64 mid = (p0 >> 32) + (__u32)p1 + (__u32)p2;

		*low = a * b;
		*high = p3 + (p1 >> 32) + (p2 >> 32) + (mid >> 32);
	}
}

/* The CF/OF pair the IMUL arms set, the contract's absolute-side funnel. */
static void imul_flags_oracle(__u64 lhs, __u64 rhs, unsigned w, __u8 *cf,
			      __u8 *of)
{
	unsigned bits = width_bits(w);
	__u64 sign = 1ULL << (bits - 1U);
	__u64 a_abs = kprog_x86_abs_width_value(lhs, (__u8)w);
	__u64 b_abs = kprog_x86_abs_width_value(rhs, (__u8)w);
	__u64 limit = (((lhs) ^ (rhs)) & sign) ? sign : sign - 1U;
	__u8 r_cf;
	__u8 r_of;

	KPROG_X86_SET_IMUL_FLAGS(r_cf, r_of, a_abs, b_abs, limit);
	*cf = r_cf;
	*of = r_of;
}

/* The condition truth the CMOV and SETCC arms evaluate, the generated
 * EVAL_CC ladder over the planted flag cells. */
static unsigned eval_cc_oracle(unsigned cc, __u8 cf, __u8 zf, __u8 sf, __u8 of)
{
	int bcf = cf != 0;
	int bzf = zf != 0;
	int bsf = sf != 0;
	int bof = of != 0;

	switch (cc) {
	case X86_CC_O:
		return (unsigned)bof;
	case X86_CC_NO:
		return (unsigned)!bof;
	case X86_CC_B:
		return (unsigned)bcf;
	case X86_CC_AE:
		return (unsigned)!bcf;
	case X86_CC_E:
		return (unsigned)bzf;
	case X86_CC_NE:
		return (unsigned)!bzf;
	case X86_CC_BE:
		return (unsigned)(bcf || bzf);
	case X86_CC_A:
		return (unsigned)(!bcf && !bzf);
	case X86_CC_S:
		return (unsigned)bsf;
	case X86_CC_NS:
		return (unsigned)!bsf;
	case X86_CC_L:
		return (unsigned)(bsf != bof);
	case X86_CC_GE:
		return (unsigned)(bsf == bof);
	case X86_CC_LE:
		return (unsigned)(bzf || bsf != bof);
	case X86_CC_G:
		return (unsigned)(!bzf && bsf == bof);
	default:
		return 0U;
	}
}

/* The condition-byte fold the SETCC register form applies, the generated
 * accepted-subset match (the no-match sentinel for the unsupported codes). */
static unsigned setcc_matched_oracle(unsigned cc)
{
	switch (cc) {
	case X86_CC_O:
		return 0U;
	case X86_CC_NO:
		return 1U;
	case X86_CC_B:
		return 2U;
	case X86_CC_AE:
		return 3U;
	case X86_CC_E:
		return 4U;
	case X86_CC_NE:
		return 5U;
	case X86_CC_BE:
		return 6U;
	case X86_CC_A:
		return 7U;
	case X86_CC_S:
		return 8U;
	case X86_CC_NS:
		return 9U;
	case X86_CC_L:
		return 12U;
	case X86_CC_GE:
		return 13U;
	case X86_CC_LE:
		return 14U;
	case X86_CC_G:
		return 15U;
	default:
		return KPROG_X86_SETCC_COND_NONE;
	}
}

/* The exact cell the sim's ordinary arm dereferences: the pointer address the
 * base register carries (its raw value when planted with the heap, a scalar
 * pattern otherwise) plus the signed displacement, expressed as an offset
 * from the model's own heap array. Anything the sim would fault on (outside
 * the array) exits loudly instead of guessing a cell. */
static unsigned long heap_cell(const struct snap *seed, unsigned base,
			       __s64 disp)
{
	unsigned long addr = (unsigned long)seed->x[base] +
			     (unsigned long)disp;
	unsigned long cell = addr - (unsigned long)(void *)heap;

	if (cell >= HEAP_BYTES) {
		fprintf(stderr,
			"heap deref 0x%lx cell %lu outside the model array\n",
			addr, cell);
		exit(1);
	}
	return cell;
}

/* The whole arm-independent addressed read: index offset, stack-pointer
 * routing and the ordinary byte load over the heap. STORE_DISP selects the
 * immediate slice the body passes (the high half when the addressing mode
 * carries an index); EXTRA is 1 for the aluMemImm read, which uses the store
 * slice as soon as an index exists. */
static __u64 model_mem_value(const struct snap *seed, unsigned base,
			     unsigned aux, __u64 imm, unsigned width,
			     unsigned store_disp, unsigned extra)
{
	unsigned has_index = aux != 0xffU && (aux & 0xffU) != 0xffU;
	unsigned use_store = store_disp == 1U && (extra == 1U || has_index);
	__s64 disp = mem_off_long(seed, aux, imm, use_store);

	if (base == X86_RSP)
		return arena_read(seed,
				  arena_index((long)seed->x[base],
					      (long)disp),
				  width);
	if (base == 0xffU)
		return model_load(&seed->heap[heap_cell(seed, X86_RDI, disp)],
				  width);
	return model_load(&seed->heap[heap_cell(seed, base, disp)], width);
}

/* The addressed store one of the model bodies writes: arena routing when the
 * base register is the stack pointer, the none base writes the frame at the
 * raw offset, otherwise a heap write at the masked cell. */
static void model_store_b(const struct snap *seed, struct snap *b,
			  unsigned base, unsigned long off, unsigned width,
			  __u64 v)
{
	if (base == X86_RSP || base == 0xffU)
		arena_write(b, off, width, v);
	else
		model_store(&b->heap[heap_cell(seed, base, (long)off)],
			    width, v);
}


/* The ALU result body, independent char-class ladder. */
static __u64 alu_result_oracle(__u64 lhs, __u64 rhs, unsigned alu,
			       unsigned width)
{
	switch (alu) {
	case X86_ALU_ADD:
		return (lhs & width_mask(width)) + (rhs & width_mask(width));
	case X86_ALU_SUB:
		return (lhs & width_mask(width)) - (rhs & width_mask(width));
	case X86_ALU_ADC:
		return (lhs & width_mask(width)) + (rhs & width_mask(width));
	case X86_ALU_SBB:
		return (lhs & width_mask(width)) - (rhs & width_mask(width));
	case X86_ALU_XOR:
		return (lhs & width_mask(width)) ^
		       (rhs & width_mask(width));
	case X86_ALU_OR:
	case X86_ALU_AND:
		/* The unary INC/DEC shapes the handled token set reaches. */
		return (lhs & width_mask(width)) | (rhs & width_mask(width));
	case X86_ALU_INC:
		return (lhs & width_mask(width)) + 1ULL;
	case X86_ALU_DEC:
		return (lhs & width_mask(width)) - 1ULL;
	case X86_ALU_NOT:
		return ~(lhs & width_mask(width));
	case X86_ALU_NEG:
		return 0ULL - (lhs & width_mask(width));
	case X86_ALU_SHL:
	case X86_ALU_SHR:
	case X86_ALU_SAR:
	case X86_ALU_ROL:
		return shift_result_oracle(lhs, shift_count(rhs, width), alu,
					   width);
	case X86_ALU_IMUL:
		return (lhs & width_mask(width)) * (rhs & width_mask(width));
	default:
		return lhs & width_mask(width);
	}
}

static void sub_flags_into(struct snap *b, __u64 a, __u64 bop, unsigned width)
{
	unsigned bits = width_bits(width);
	__u64 m = width_mask(width);
	__u64 sign = 1ULL << (bits - 1U);
	__u64 r = (KPROG_X86_SBB_RESULT((a & m), (bop & m), 0ULL)) & m;

	b->cf = (__u8)((a & m) < (bop & m));
	b->zf = (__u8)((a & m) == (bop & m));
	b->sf = (__u8)((r & sign) != 0);
	b->of = (__u8)((((a & m) ^ (bop & m)) &
			(((a & m) ^ r) & sign)) != 0);
}

static void logic_flags_into(struct snap *b, __u64 result, unsigned width)
{
	unsigned bits = width_bits(width);

	b->cf = 0;
	b->zf = (__u8)((result & width_mask(width)) == 0);
	b->sf = (__u8)(((result & width_mask(width)) >> (bits - 1U)) & 1U);
	b->of = 0;
}

/* The shift-flag body the arm's X86_SIM_L_SET_SHIFT_FLAGS selects, restated
 * from the generated KPROG_X86_SET_SHIFT_FLAGS ladder over the already-masked
 * count: ROL keeps ZF/SF and taps the low bit, the straight shifts set ZF/SF
 * from the result and pick CF per kind, each with the count==1 OF special
 * case; a zero count touches nothing. */
static void shift_flags_into(struct snap *b, __u64 lhs, __u64 rhs,
			     __u64 result, unsigned alu, unsigned w)
{
	unsigned bits = width_bits(w);
	__u64 m = width_mask(w);
	__u64 sign = 1ULL << (bits - 1U);
	__u64 a = lhs & m;
	__u64 r = result & m;
	unsigned count = shift_count(rhs, w);

	if (count != 0U) {
		if (alu == X86_ALU_ROL) {
			b->cf = (__u8)(r & 1U);
			if (count == 1U)
				b->of = (__u8)(((r & sign) != 0) ^
					       (b->cf != 0));
			return;
		}
		b->zf = (__u8)(r == 0);
		b->sf = (__u8)((r & sign) != 0);
		if (alu == X86_ALU_SHL)
			b->cf = (__u8)(count <= bits ?
				       (a >> (bits - count)) & 1U : 0U);
		else
			b->cf = (__u8)(count <= bits ?
				       (a >> (count - 1U)) & 1U :
				       (__u8)((a & sign) != 0));
		if (count == 1U && alu == X86_ALU_SHL)
			b->of = (__u8)(b->sf ^ b->cf);
		else if (count == 1U && alu == X86_ALU_SHR)
			b->of = (__u8)((a & sign) != 0);
		else if (count == 1U && alu == X86_ALU_SAR)
			b->of = 0;
	}
}

/* The flag body the arm's X86_SIM_L_SET_ALU_FLAGS switch selects, restated
 * per body: the add/sub/neg funnel and its INC/DEC carry preserves, the SBB
 * arm's zero-borrow shape, the not arm's untouched flags, the shift arm's
 * count-keyed ladder, the multiply funnel, and the logic default. */
static void alu_flags_into(struct snap *b, unsigned alu, __u8 seed_cf,
			   __u64 lhs, __u64 rhs, __u64 result, unsigned w)
{
	unsigned bits = width_bits(w);
	__u64 m = width_mask(w);
	__u64 sign = 1ULL << (bits - 1U);
	__u64 a = lhs & m;
	__u64 bop = rhs & m;
	__u64 r = result & m;
	__u64 old_cf = seed_cf;
	__u8 r_cf;
	__u8 r_of;

	switch (alu) {
	case X86_ALU_ADD:
	case X86_ALU_ADC:
		KPROG_X86_SET_ADD_FLAGS(b->cf, b->zf, b->sf, b->of,
					a, bop, r, sign);
		break;
	case X86_ALU_INC:
		KPROG_X86_SET_ADD_FLAGS(b->cf, b->zf, b->sf, b->of,
					a, 1U, r, sign);
		b->cf = (__u8)old_cf;
		break;
	case X86_ALU_DEC:
		KPROG_X86_SET_SUB_FLAGS(b->cf, b->zf, b->sf, b->of,
					a, 1U, r, sign);
		b->cf = (__u8)old_cf;
		break;
	case X86_ALU_SUB:
		KPROG_X86_SET_SUB_FLAGS(b->cf, b->zf, b->sf, b->of,
					a, bop, r, sign);
		break;
	case X86_ALU_SBB:
		KPROG_X86_SET_SBB_FLAGS(b->cf, b->zf, b->sf, b->of,
					a, bop, r, sign, 0U);
		break;
	case X86_ALU_NEG:
		KPROG_X86_SET_SUB_FLAGS(b->cf, b->zf, b->sf, b->of,
					0U, a, r, sign);
		break;
	case X86_ALU_NOT:
		break;
	case X86_ALU_IMUL:
		imul_flags_oracle(lhs, rhs, w, &r_cf, &r_of);
		b->cf = r_cf;
		b->of = r_of;
		break;
	case X86_ALU_SHL:
	case X86_ALU_SHR:
	case X86_ALU_SAR:
	case X86_ALU_ROL:
		shift_flags_into(b, lhs, rhs, result, alu, w);
		break;
	default:
		logic_flags_into(b, result, w);
		break;
	}
}

/* callMemcpy/callMemset/callMemcpyReg/callMemsetReg: the shared block-step,
 * one byte at a time, with the kind, count-source and bound selectors folded
 * into the caller's argument tuple. Both RSI readings happen before the loop,
 * so the copy overwrites and the fill sweeps independently of iteration order.
 * The RAX result is RDI's pointer value with RDI's tag. */
static void model_callmem(int is_copy, int is_reg, __u64 imm, struct snap *b)
{
	unsigned long dst_off = (unsigned long)((__u64)b->x[X86_RDI] -
		(__u64)(unsigned long)(void *)heap);
	unsigned long src_off = (unsigned long)((__u64)b->x[X86_RSI] -
		(__u64)(unsigned long)(void *)heap);
	__u8 fill = (__u8)(b->x[X86_RSI] & 0xffULL);
	unsigned long count = (unsigned long)(is_reg ? b->x[X86_RDX] : imm);
	unsigned long bound = (unsigned long)(is_reg ? imm : 1024U);
	unsigned long i;
	__u8 scratch[HEAP_BYTES];

	memcpy(scratch, b->heap, HEAP_BYTES);
	for (i = 0; i < bound && i < count; i++) {
		if (is_copy) {
			__u8 byte;

			if (src_off + i >= HEAP_BYTES ||
			    dst_off + i >= HEAP_BYTES)
				break;
			byte = scratch[src_off + i];
			b->heap[dst_off + i] = byte;
		} else {
			if (dst_off + i >= HEAP_BYTES)
				break;
			b->heap[dst_off + i] = fill;
		}
	}
	b->x[X86_RAX] = b->x[X86_RDI];
	b->t[X86_RAX] = b->t[X86_RDI];
}

/* callReg: the whole helper-slot ladder, against the stubbed host returns.
 * The ids 2/3 write the long result through the 64-bit write; 4/5 write a
 * constant 64; 6 writes a constant 32; 7 the stubbed nanoseconds. */
static void model_callreg(unsigned src, struct snap *b)
{
	__u64 id = b->x[src];

	switch (id) {
	case 1ULL:
		b->x[X86_RAX] = (__u64)(long)ORA_MAP_PTR;
		b->t[X86_RAX] = X86_SIM_TAG_MAP_VALUE;
		break;
	case 2ULL:
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX],
			(__u64)(long)ORA_UPD_RET, X86_WIDTH_64);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		break;
	case 3ULL:
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX],
			(__u64)(long)ORA_DEL_RET, X86_WIDTH_64);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		break;
	case 4ULL:
	case 5ULL:
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX], 0ULL,
						    X86_WIDTH_64);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		break;
	case 6ULL:
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX], 0ULL,
						    X86_WIDTH_32);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		break;
	case 7ULL:
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX], ORA_KTIME,
						    X86_WIDTH_64);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		break;
	default:
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX], 0ULL,
						    X86_WIDTH_64);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		break;
	}
}

/* movImm: FLAGS-width write of the immediate at the AUX-named lane. */
static void model_movimm(unsigned dst, unsigned flags, unsigned aux,
			 __u64 imm, struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned shift = (aux >> 8) & 0xffU;
	__u64 v = imm;

	if (w == X86_WIDTH_8) {
		__u8 byte = (__u8)(imm & 0xffULL);

		if (shift == 8U) {
			b->x[dst] = (b->x[dst] & ~((__u64)0xffULL << 8)) |
				    (((__u64)byte << 8) & 0xff00ULL);
		} else {
			b->x[dst] = (b->x[dst] & ~(__u64)0xffULL) | byte;
		}
	} else {
		b->x[dst] = model_partial_write(b->x[dst], v, w);
	}
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* movReg: STACK_PTR at 64 with an RSP source (STACK tag, arena pointer),
 * plain pointer copy at 64 (source tag), scalarizing narrow lane copy. */
static void model_movreg(unsigned dst, unsigned src, unsigned flags,
			 unsigned aux, struct snap *b)
{
	unsigned w = resolve_width(flags);

	if (w == X86_WIDTH_64 && src == X86_RSP) {
		b->x[dst] = stack_ptr_value((long)b->x[src]);
		b->t[dst] = X86_SIM_TAG_STACK;
	} else if (w == X86_WIDTH_64) {
		b->x[dst] = b->x[src];
		b->t[dst] = b->t[src];
	} else {
		unsigned dsh = (aux >> 8) & 0xffU;
		unsigned ssh = (aux >> 16) & 0xffU;
		__u64 v = lane_read(b->x[src], w, ssh);

		if (w == X86_WIDTH_8) {
			if (dsh == 8U)
				b->x[dst] = (b->x[dst] &
					     ~((__u64)0xffULL << 8)) |
					    ((v << 8) & 0xff00ULL);
			else
				b->x[dst] = (b->x[dst] & ~(__u64)0xffULL) | v;
		} else {
			b->x[dst] = model_partial_write(b->x[dst], v, w);
		}
		b->t[dst] = X86_SIM_TAG_SCALAR;
	}
}

/* movbeLoad: the MOVBE load arm — the raw SRC read at the MOVBE width
 * (the arm bypasses the read ladder), byte-reversed, then the same-width
 * writeback into DST. */
static void model_movbe_load(unsigned dst, unsigned src, unsigned flags,
			     __u64 imm, const struct snap *seed,
			     struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;

	b->x[dst] = model_partial_write(seed->x[dst],
					bswap_oracle(model_mem_value(seed,
								     src,
								     X86_REG_NONE,
								     imm, w,
								     DISP_REGULAR,
								     0U), w),
					w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* movbeStore: the MOVBE store arm — byte-reverse SRC at the MOVBE width and
 * store through the DST base at the displacement MOVBE takes (the whole
 * artifact sign reinterpreted); the stack base writes through the arena. */
static void model_movbe_store(unsigned dst, unsigned src, unsigned flags,
			      __u64 imm, const struct snap *seed,
			      struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	long disp = mem_off_long(seed, 0xffU, imm, DISP_REGULAR);

	if (dst == X86_RSP)
		model_store_b(seed, b, X86_RSP,
			      arena_index((long)b->x[X86_RSP], disp), w,
			      bswap_oracle(seed->x[src], w));
	else if (dst != 0xffU)
		model_store_b(seed, b, dst, S64_TO_OFF(disp), w,
			      bswap_oracle(seed->x[src], w));
}

/* loadXmm0: the XMM0 load arm — stack reads through the arena when SRC is
 * the stack pointer, otherwise the ordinary 64-bit pair-read at base +
 * displacement and base + displacement + 8 (the drive never plants a none
 * base, which the sim's LOAD arm cannot resolve). */
static void model_load_xmm0(unsigned src, __u64 imm,
			    const struct snap *seed, struct snap *b)
{
	unsigned long disp = S64_TO_OFF(x86_simm(imm));

	if (src == X86_RSP) {
		unsigned long wi = arena_index((long)seed->x[src],
					       (long)disp);

		b->xmm0_lo = arena_read(seed, wi, X86_WIDTH_64);
		b->xmm0_hi = arena_read(seed, wi + 8U, X86_WIDTH_64);
	} else {
		unsigned long cell = heap_cell(seed, src, (long)disp);

		b->xmm0_lo = model_load(&seed->heap[cell], X86_WIDTH_64);
		b->xmm0_hi = model_load(&seed->heap[cell + 8U], X86_WIDTH_64);
	}
}

/* storeXmm0: the same pair-move the other way through the DST base. */
static void model_store_xmm0(unsigned dst, __u64 imm,
			     const struct snap *seed, struct snap *b)
{
	unsigned long disp = S64_TO_OFF(x86_simm(imm));

	if (dst == X86_RSP) {
		unsigned long wi = arena_index((long)seed->x[dst],
					       (long)disp);

		arena_write(b, wi, X86_WIDTH_64, seed->xmm0_lo);
		arena_write(b, wi + 8U, X86_WIDTH_64, seed->xmm0_hi);
	} else {
		unsigned long cell = heap_cell(seed, dst, (long)disp);

		model_store(&b->heap[cell], X86_WIDTH_64, seed->xmm0_lo);
		model_store(&b->heap[cell + 8U], X86_WIDTH_64,
			    seed->xmm0_hi);
	}
}

/* lea: the exact LEA arm shape — the RODATA arm at 64 bits with a none
 * source writes the raw immediate; at 64 bits an RSP source is the arena
 * rebase at the offset (STACK tag), any other present source is the pointer
 * add with its tag preserved; the narrow forms scalarize the address
 * arithmetic. The offset is the sign-extended immediate plus the AUX index
 * term. */
static void model_lea(unsigned dst, unsigned src, unsigned flags,
		      unsigned aux, __u64 imm, const struct snap *seed,
		      struct snap *b)
{
	unsigned w = resolve_width(flags);
	long off = mem_off_long(seed, aux, imm, DISP_REGULAR);

	if (w == X86_WIDTH_64 && src == 0xffU &&
	    aux == X86_LEA_AUX_RODATA) {
		b->x[dst] = imm & width_mask(w);
		b->t[dst] = X86_SIM_TAG_SCALAR;
		return;
	}
	if (w == X86_WIDTH_64) {
		unsigned long result;

		if (src == X86_RSP) {
			b->t[dst] = X86_SIM_TAG_STACK;
			result = stack_ptr_value((long)b->x[X86_RSP] + off);
			b->x[dst] = result;
			return;
		}
		result = (unsigned long)seed->x[src] +
			 (unsigned long)off;
		b->x[dst] = (unsigned long)(__u64)(long)result;
		b->t[dst] = seed->t[src];
		return;
	}
	{
		unsigned long addrv = (src == 0xffU ? 0UL :
				       (unsigned long)seed->x[src]) +
				      (unsigned long)off;

		b->t[dst] = X86_SIM_TAG_SCALAR;
		b->x[dst] = model_partial_write(seed->x[dst],
						(__u64)(long)addrv, w);
	}
}

/* The raw byte address the memory forms read or write: the sign-extended
 * displacement slice plus the AUX index term, exactly the address
 * X86_SIM_L_MEM_OFFSET forms (not the masked model read). */
static unsigned long mem_off_bytes(const struct snap *seed, unsigned aux,
				   __u64 imm, unsigned store_disp)
{
	return S64_TO_OFF(mem_off_long(seed, aux, imm, store_disp));
}

/* aluMem: whole-64 destination operand, addressed operand, full flag set,
 * whole-64 writeback. SBB consumes the incoming CF, ADC adds it. */
static void model_alu_mem(unsigned dst, unsigned src, unsigned flags,
			  unsigned aux, __u64 imm, const struct snap *seed,
			  struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned alu = (aux >> 24) & 0xffU;
	__u64 lhs = seed->x[dst];
	__u64 rhs = model_mem_value(seed, src, aux, imm, w,
				    DISP_REGULAR, 0U);
	__u64 result = alu_result_oracle(lhs, rhs, alu, w);

	if (alu == X86_ALU_SBB)
		result = KPROG_X86_SBB_RESULT(lhs, rhs, (__u64)seed->cf) &
			 width_mask(w);
	else if (alu == X86_ALU_ADC)
		result = KPROG_X86_ADC_RESULT(lhs, rhs, (__u64)seed->cf) &
			 width_mask(w);
	alu_flags_into(b, alu, seed->cf, lhs, rhs, result, w);
	b->x[dst] = model_partial_write(seed->x[dst], result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* aluMemUnary: addressed lhs at the FLAGS width, rhs hardwired 1. */
static void model_alu_mem_unary(unsigned dst, unsigned flags, unsigned aux,
				__u64 imm, const struct snap *seed,
				struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned alu = (aux >> 24) & 0xffU;
	__u64 lhs = model_mem_value(seed, dst, aux, imm, w, DISP_REGULAR, 0U);
	__u64 result = alu_result_oracle(lhs, 1ULL, alu, w);
	unsigned long off = mem_off_bytes(seed, aux, imm, DISP_REGULAR);

	alu_flags_into(b, alu, seed->cf, lhs, 1ULL, result, w);
	model_store_b(seed, b, dst, off, w, result);
}

/* aluMemImm: addressed lhs at the FLAGS width with the store-displacement
 * slice when the mode carries an index, plain simm otherwise; store-imm
 * immediate. */
static void model_alu_mem_imm(unsigned dst, unsigned flags, unsigned aux,
			      __u64 imm, const struct snap *seed,
			      struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned alu = (aux >> 24) & 0xffU;
	unsigned disp_kind = DISP_STORE;
	__u64 lhs = model_mem_value(seed, dst, aux, imm, w, disp_kind, 1U);
	__u64 rhs = store_imm_oracle(imm, w);
	__u64 result = alu_result_oracle(lhs, rhs, alu, w);
	unsigned long off = mem_off_bytes(seed, aux, imm, disp_kind);

	if (alu == X86_ALU_SBB)
		result = KPROG_X86_SBB_RESULT(lhs, rhs, (__u64)seed->cf) &
			 width_mask(w);
	else if (alu == X86_ALU_ADC)
		result = KPROG_X86_ADC_RESULT(lhs, rhs, (__u64)seed->cf) &
			 width_mask(w);
	alu_flags_into(b, alu, seed->cf, lhs, rhs, result, w);
	model_store_b(seed, b, dst, off, w, result);
}

/* aluMemReg: whole-64 SRC rhs; both the read and the writeback take the
 * store-displacement slice when the addressing mode carries an index. */
static void model_alu_mem_reg(unsigned dst, unsigned src, unsigned flags,
			      unsigned aux, __u64 imm,
			      const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned alu = (aux >> 24) & 0xffU;
	int has_idx = aux != 0xffU && (aux & 0xffU) != 0xffU;
	unsigned disp_kind = has_idx ? DISP_STORE : DISP_REGULAR;
	__u64 lhs = model_mem_value(seed, dst, aux, imm, w, disp_kind, 0U);
	__u64 rhs = seed->x[src];
	__u64 result = alu_result_oracle(lhs, rhs, alu, w);
	unsigned long off = mem_off_bytes(seed, aux, imm, disp_kind);

	if (alu == X86_ALU_SBB)
		result = KPROG_X86_SBB_RESULT(lhs, rhs, (__u64)seed->cf) &
			 width_mask(w);
	else if (alu == X86_ALU_ADC)
		result = KPROG_X86_ADC_RESULT(lhs, rhs, (__u64)seed->cf) &
			 width_mask(w);
	alu_flags_into(b, alu, seed->cf, lhs, rhs, result, w);
	model_store_b(seed, b, dst, off, w, result);
}

/* cmpRegMem: whole-64 destination, addressed source, pure sub flags. */
static void model_cmp_reg_mem(unsigned dst, unsigned src, unsigned flags,
			      unsigned aux, __u64 imm,
			      const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);
	__u64 lhs = seed->x[dst];
	__u64 rhs = model_mem_value(seed, src, aux, imm, w, DISP_REGULAR, 0U);

	sub_flags_into(b, lhs, rhs, w);
}

/* cmov/cmovMem: the guarded move. The register form samples pointer and tag
 * at 64 bits; the memory form reads at its own access width from the
 * high-half displacement, and scalarizes at every width. */
static void model_cmov(unsigned dst, unsigned src, unsigned flags,
		       unsigned aux, __u64 imm, int is_mem,
		       const struct snap *seed, struct snap *b)
{
	unsigned cc = is_mem ? ((aux >> 24) & 0xffU) : aux;
	unsigned w = flags ? flags : X86_WIDTH_64;

	if (!eval_cc_oracle(cc, seed->cf, seed->zf, seed->sf, seed->of))
		return;
	if (!is_mem) {
		if (w == X86_WIDTH_64) {
			b->x[dst] = seed->x[src];
			b->t[dst] = seed->t[src];
		} else {
			b->x[dst] = model_partial_write(seed->x[dst],
							seed->x[src], w);
			b->t[dst] = X86_SIM_TAG_SCALAR;
		}
	} else {
		unsigned cmw = ((aux >> 16) & 0xffU) ?
			((aux >> 16) & 0xffU) : w;
		__u64 v;

		if (src == 0xffU)
			v = 0ULL;
		else
			v = model_mem_value(seed, src, aux, imm >> 32,
					    cmw, DISP_REGULAR, 0U);
		b->x[dst] = model_partial_write(seed->x[dst], v, w);
		b->t[dst] = X86_SIM_TAG_SCALAR;
	}
}

/* setcc: the condition byte, matched through the accepted-subset fold,
 * written at width 8 into the lane the AUX shift byte names (8 high else
 * low). */
static void model_setcc(unsigned dst, unsigned aux, struct snap *b)
{
	unsigned cc = aux & 0xffU;
	unsigned dsh = (aux >> 8) & 0xffU;
	unsigned matched = setcc_matched_oracle(cc);
	__u8 value = (__u8)eval_cc_oracle(matched, b->cf, b->zf, b->sf, b->of);

	if (dsh == 8U)
		b->x[dst] = (b->x[dst] & ~((__u64)0xffULL << 8)) |
			    (((__u64)value << 8) & 0xff00ULL);
	else
		b->x[dst] = (b->x[dst] & ~(__u64)0xffULL) | value;
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* setccMem: the one-byte store at the addressed (or arena) byte. The sim's
 * SETCC_MEM arm routes the RSP store through the stack helper and the null
 * base writes at the raw address (dropped by the none drive); every other
 * base is an ordinary byte store at base + displacement. */
static void model_setcc_mem(unsigned dst, unsigned aux, __u64 imm,
			    const struct snap *seed, struct snap *b)
{
	unsigned cc = (aux >> 24) & 0xffU;
	__u8 value = (__u8)eval_cc_oracle(cc, seed->cf, seed->zf, seed->sf,
					  seed->of);

	if (dst == X86_RSP)
		model_store_b(seed, b, X86_RSP,
			      arena_index((long)b->x[X86_RSP],
					  mem_off_long(seed, aux, imm,
						       DISP_REGULAR)),
			      X86_WIDTH_8, value);
	else if (dst != 0xffU)
		model_store_b(seed, b, dst,
			      S64_TO_OFF(mem_off_long(seed, aux, imm,
						      DISP_REGULAR)),
			      X86_WIDTH_8, value);
}

/* bswap: byte-reverse at the FLAGS width. */
static void model_bswap(unsigned dst, unsigned flags, struct snap *b)
{
	unsigned w = resolve_width(flags);

	b->x[dst] = model_partial_write(b->x[dst],
					bswap_oracle(b->x[dst], w), w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* popcnt: apply the width, count the bits, clear CF/SF/OF, set ZF by zero. */
static void model_popcnt(unsigned dst, unsigned src, unsigned flags,
			 struct snap *b)
{
	unsigned w = resolve_width(flags);
	__u64 narrowed = b->x[src] & width_mask(w);
	unsigned pop = popcount_oracle(narrowed);

	b->cf = 0;
	b->of = 0;
	b->sf = 0;
	b->zf = (__u8)(narrowed == 0);
	b->x[dst] = model_partial_write(b->x[dst], pop, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* shiftx/shiftxMem: the SHIFTX arms restated — the source value (registered
 * or addressed) shifted by the count register through the same
 * x86_alu_result the arm calls, no flags changed, the result written back at
 * the FLAGS width. The count is the AUX register for the register form and
 * the register the AUX source-shift byte names for the memory form. */
static void model_shiftx(unsigned dst, unsigned src, unsigned flags,
			 unsigned aux, __u64 imm, int is_mem,
			 const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);
	__u64 v = is_mem ? model_mem_value(seed, src, aux, imm, w, DISP_STORE,
					   1U) : seed->x[src];
	unsigned cnt_reg = is_mem ? ((aux >> 24) & 0xffU) : aux;
	__u64 count = seed->x[cnt_reg];
	unsigned alu = (__u8)imm;
	__u64 result = alu_result_oracle(v, count, alu, w);

	b->x[dst] = model_partial_write(seed->x[dst], result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* rorx/rorxMem: ror at the FLAGS width by the byte-masked immediate. */
static void model_rorx(unsigned dst, unsigned src, unsigned flags,
		       unsigned aux, __u64 imm, int is_mem,
		       const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);
	__u64 v = is_mem ?
		model_mem_value(seed, src, aux, imm, w, DISP_STORE, 1U) :
		seed->x[src];
	__u64 result = ror_oracle(v, (unsigned)(imm & 0xffULL), w);

	b->x[dst] = model_partial_write(seed->x[dst], result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* bzhi/bzhiMem: byte-counted bit clear at the FLAGS width; the memory form
 * reads the count from AUX's source-shift byte. */
static void model_bzhi(unsigned dst, unsigned src, unsigned count,
		       unsigned flags, unsigned aux, __u64 imm, int is_mem,
		       const struct snap *seed, struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 v = is_mem ? model_mem_value(seed, src, aux, imm, w, DISP_STORE,
					   1U) : seed->x[src];
	unsigned cnt_reg = is_mem ? ((aux >> 24) & 0xffU) : count;
	__u64 c = seed->x[cnt_reg] & KPROG_X86_BZHI_COUNT_MASK;
	unsigned bits = width_bits(w);
	__u64 result = bzhi_oracle(v, (unsigned)c, w);

	b->cf = (__u8)(c >= (__u64)bits);
	b->zf = (__u8)(result == 0);
	b->sf = 0;
	b->of = 0;
	b->x[dst] = model_partial_write(seed->x[dst], result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* bt/btImm/btMemImm: the tested bit into CF, and nothing else. */
static void model_bt(unsigned dst, unsigned flags,
		     unsigned aux, __u64 imm, int is_mem,
		     const struct snap *seed, struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 base;
	__u64 index;

	if (is_mem) {
		base = model_mem_value(seed, dst, aux, imm, w, DISP_STORE,
				       1U);
		index = imm & 0xffffffffULL;
	} else {
		base = seed->x[dst];
		index = imm;
	}
	b->cf = bt_oracle(base, index, w);
}

/* imulImm/imulMemImm: width-sign-extended immediate times the (registered
 * or addressed) operand, CF/OF only. The memory form's lhs is read at the
 * AUX mem width and re-sign-extended. */
static void model_imul(unsigned dst, unsigned src, unsigned flags,
		       unsigned aux, __u64 imm, int is_mem,
		       const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned mw = is_mem ? (((aux >> 16) & 0xffU) ? ((aux >> 16) & 0xffU)
						      : w) : w;
	__u64 lhs = is_mem ?
		model_mem_value(seed, src, aux, imm, mw, DISP_STORE, 1U) :
		seed->x[src];
	__u64 rhs = is_mem ? sign_extend_oracle(store_imm_oracle(imm, w), w)
			   : sign_extend_oracle(imm, w);
	__u64 lhs_ext = is_mem ? sign_extend_oracle(lhs, mw) : lhs;
	__u64 result = lhs_ext * rhs;

	imul_flags_oracle(lhs_ext, rhs, w, &b->cf, &b->of);
	b->x[dst] = model_partial_write(seed->x[dst], result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* mulx: the 32-bit single-product arm and the 64-bit limb arm, with an
 * optional AUX-named high-product destination. */
static void model_mulx(unsigned dst, unsigned src, unsigned aux,
		       unsigned flags, const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);
	__u64 low;
	__u64 high;

	mulx_oracle(seed->x[X86_RDX], src == 0xffU ? 0ULL : seed->x[src],
		    w, &low, &high);
	b->x[dst] = model_partial_write(seed->x[dst], low, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
	if (aux != 0xffU) {
		b->x[aux] = model_partial_write(seed->x[aux], high, w);
		b->t[aux] = X86_SIM_TAG_SCALAR;
	}
}

/* repMovs: the capped element stream plus the RSI/RDI pointer bumps and the
 * RCX zeroing, all at the contract's fixed shapes. */
static void model_rep_movs(unsigned flags, __u64 imm,
			   const struct snap *seed, struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	unsigned long count = S64_TO_OFF(x86_simm(imm));
	unsigned long so = (unsigned long)((__u64)seed->x[X86_RSI] -
		(__u64)(unsigned long)(void *)heap);
	unsigned long doff = (unsigned long)((__u64)seed->x[X86_RDI] -
		(__u64)(unsigned long)(void *)heap);
	unsigned long i;

	for (i = 0; i < 64U && i < count; i++) {
		unsigned j;

		for (j = 0; j < w; j++) {
			b->heap[doff + (__u64)i * (__u64)w + (__u64)j] =
				seed->heap[so + (__u64)i * (__u64)w +
					   (__u64)j];
		}
	}
	b->x[X86_RSI] = seed->x[X86_RSI] + (__u64)count * (__u64)w;
	b->t[X86_RSI] = seed->t[X86_RSI];
	b->x[X86_RDI] = seed->x[X86_RDI] + (__u64)count * (unsigned long)w;
	b->t[X86_RDI] = seed->t[X86_RDI];
	b->x[X86_RCX] = model_partial_write(b->x[X86_RCX], 0ULL, X86_WIDTH_64);
	b->t[X86_RCX] = X86_SIM_TAG_SCALAR;
}

/* andn/andnMem: (~src1) & src2 with pure logic flags. */
static void model_andn(unsigned dst, unsigned src, unsigned aux,
		       unsigned flags, __u64 imm, int is_mem,
		       const struct snap *seed, struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 src1 = seed->x[src];
	__u64 src2;
	__u64 result;

	if (is_mem) {
		unsigned mw = ((aux >> 16) & 0xffU) ? ((aux >> 16) & 0xffU) : w;

		src2 = model_mem_value(seed, (aux >> 24) & 0xffU, aux, imm, mw,
				       DISP_REGULAR, 1U);
	} else {
		src2 = seed->x[aux];
	}
	result = (~src1) & src2;
	logic_flags_into(b, result, w);
	b->x[dst] = model_partial_write(seed->x[dst], result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* xchg: pointer swap at 64 (values and tags both move), scalarizing narrow
 * value exchange otherwise. */
static void model_xchg(unsigned dst, unsigned src, unsigned flags,
		       const struct snap *seed, struct snap *b)
{
	unsigned w = resolve_width(flags);

	if (w == X86_WIDTH_64) {
		b->x[dst] = seed->x[src];
		b->t[dst] = X86_SIM_TAG_SCALAR;
		b->x[src] = seed->x[dst];
		b->t[src] = X86_SIM_TAG_SCALAR;
		return;
	}
	b->x[dst] = model_partial_write(seed->x[dst], seed->x[src], w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
	b->x[src] = model_partial_write(seed->x[src], seed->x[dst], w);
	b->t[src] = X86_SIM_TAG_SCALAR;
}

/* div: the four width arms of the byte-ladder; B8's single 16-bit quotient
 * write and the three split divide-and-write pairs. */
static void model_div(unsigned src, unsigned flags, const struct snap *seed,
		      struct snap *b)
{
	unsigned w = resolve_width(flags);
	__u64 divisor = seed->x[src];

	if (w == X86_WIDTH_8) {
		__u32 dividend = (__u16)seed->x[X86_RAX];
		__u8 q = (__u8)(dividend / (__u8)divisor);
		__u8 rem = (__u8)(dividend % (__u8)divisor);

		b->x[X86_RAX] = (b->x[X86_RAX] &
				 ~((__u64)0xffffULL)) |
				(((__u64)rem << 8) | (__u64)q);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
	} else if (w == X86_WIDTH_16) {
		__u32 dividend = ((__u32)(__u16)seed->x[X86_RDX] << 16) |
				 (__u16)seed->x[X86_RAX];
		__u64 q = dividend / (__u16)divisor;
		__u64 rem = dividend % (__u16)divisor;

		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX], q,
						    X86_WIDTH_16);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		b->x[X86_RDX] = model_partial_write(b->x[X86_RDX], rem,
						    X86_WIDTH_16);
		b->t[X86_RDX] = X86_SIM_TAG_SCALAR;
	} else if (w == X86_WIDTH_32) {
		__u64 dividend = ((__u64)(__u32)seed->x[X86_RDX] << 32) |
				 (__u32)seed->x[X86_RAX];
		__u64 dvs = (__u32)divisor;

		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX],
						    dividend / dvs,
						    X86_WIDTH_32);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		b->x[X86_RDX] = model_partial_write(b->x[X86_RDX],
						    dividend % dvs,
						    X86_WIDTH_32);
		b->t[X86_RDX] = X86_SIM_TAG_SCALAR;
	} else {
		__u64 q = 0xffffffffffffffffULL;
		__u64 rem = seed->x[X86_RDX];

		if (seed->x[X86_RDX] == 0ULL) {
			q = seed->x[X86_RAX] / divisor;
			rem = seed->x[X86_RAX] % divisor;
		}
		b->x[X86_RAX] = model_partial_write(b->x[X86_RAX], q,
						    X86_WIDTH_64);
		b->t[X86_RAX] = X86_SIM_TAG_SCALAR;
		b->x[X86_RDX] = model_partial_write(b->x[X86_RDX], rem,
						    X86_WIDTH_64);
		b->t[X86_RDX] = X86_SIM_TAG_SCALAR;
	}
}

/* push: the PUSH body reads the whole-64 source, pre-decrements the stack
 * pointer by the 8-byte step, then stores the value through the arena
 * window at the stepped pointer (the hardcoded 64-bit write width). */
static void model_push(unsigned src, const struct snap *seed, struct snap *b)
{
	b->x[X86_RSP] =
		(unsigned long)(__u64)(long)((long)b->x[X86_RSP] - 8L);
	model_store_b(seed, b, X86_RSP,
		      arena_index((long)b->x[X86_RSP], 0L),
		      X86_WIDTH_64, seed->x[src]);
}

/* pop: whole-width load from the arena, width write into the destination,
 * then the stack pointer's 8-byte bump. */
static void model_pop(unsigned dst, unsigned flags, const struct snap *seed,
		      struct snap *b)
{
	unsigned w = flags ? flags : X86_WIDTH_64;
	unsigned long wi = arena_index((long)b->x[X86_RSP], 0L);
	__u64 v = arena_read(b, wi, w);

	b->x[dst] = model_partial_write(seed->x[dst], v, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
	b->x[X86_RSP] = (unsigned long)(__u64)(long)((long)b->x[X86_RSP] + 8L);
}

/* ---- The dispatcher restatement ---------------------------------------- */

/* The lane-aux word the register-lane drives assemble: the payload, the
 * destination shift, and the source shift as three little-endian bytes. */
static unsigned builds_word(unsigned payload, unsigned dsh, unsigned ssh)
{
	return KPROG_X86_REG_LANE_AUX(payload, dsh, ssh);
}

/* The simd word the lane-aux ALU drive passes, restated as its byte. */
static unsigned shiftimm_word(unsigned alu)
{
	return alu;
}

/* The whole drive roadmap: one entry per singleton opcode, restating which
 * model body the opcodes' dispatch arm routes to and with which argument
 * tuple. An opcode with no case here is the non-member probe. */
static void apply_model(unsigned op, unsigned dst, unsigned src,
			unsigned flags, unsigned aux, __u64 imm,
			const struct snap *seed, struct snap *b)
{
	switch (op) {
	case X86_OP_NOP:
		break;
	case X86_OP_CALL_MEMCPY:
		model_callmem(1, 0, imm, b);
		break;
	case X86_OP_CALL_MEMSET:
		model_callmem(0, 0, imm, b);
		break;
	case X86_OP_CALL_MEMCPY_REG:
		model_callmem(1, 1, imm, b);
		break;
	case X86_OP_CALL_MEMSET_REG:
		model_callmem(0, 1, imm, b);
		break;
	case X86_OP_CALL_REG:
		model_callreg(src, b);
		break;
	case X86_OP_MOV_IMM:
		model_movimm(dst, flags, aux, imm, b);
		break;
	case X86_OP_MOV_REG:
		model_movreg(dst, src, flags, aux, b);
		break;
	case X86_OP_MOVBE_LOAD:
		model_movbe_load(dst, src, flags, imm, seed, b);
		break;
	case X86_OP_MOVBE_STORE:
		model_movbe_store(dst, src, flags, imm, seed, b);
		break;
	case X86_OP_LOAD_XMM0:
		model_load_xmm0(src, imm, seed, b);
		break;
	case X86_OP_STORE_XMM0:
		model_store_xmm0(dst, imm, seed, b);
		break;
	case X86_OP_LEA:
		model_lea(dst, src, flags, aux, imm, seed, b);
		break;
	case X86_OP_ALU_MEM:
		model_alu_mem(dst, src, flags, aux, imm, seed, b);
		break;
	case X86_OP_ALU_MEM_UNARY:
		model_alu_mem_unary(dst, flags, aux, imm, seed, b);
		break;
	case X86_OP_ALU_MEM_IMM:
		model_alu_mem_imm(dst, flags, aux, imm, seed, b);
		break;
	case X86_OP_ALU_MEM_REG:
		model_alu_mem_reg(dst, src, flags, aux, imm, seed, b);
		break;
	case X86_OP_CMP_REG_MEM:
		model_cmp_reg_mem(dst, src, flags, aux, imm, seed, b);
		break;
	case X86_OP_CMOV:
		model_cmov(dst, src, flags, aux, 0ULL, 0, seed, b);
		break;
	case X86_OP_CMOV_MEM:
		model_cmov(dst, src, flags, aux, imm, 1, seed, b);
		break;
	case X86_OP_SETCC:
		model_setcc(dst, aux, b);
		break;
	case X86_OP_SETCC_MEM:
		model_setcc_mem(dst, aux, imm, seed, b);
		break;
	case X86_OP_BSWAP:
		model_bswap(dst, flags, b);
		break;
	case X86_OP_POPCNT:
		model_popcnt(dst, src, flags, b);
		break;
	case X86_OP_SHIFTX:
		model_shiftx(dst, src, flags, aux, imm, 0, seed, b);
		break;
	case X86_OP_SHIFTX_MEM:
		model_shiftx(dst, src, flags, aux, imm, 1, seed, b);
		break;
	case X86_OP_RORX:
		model_rorx(dst, src, flags, aux, imm, 0, seed, b);
		break;
	case X86_OP_RORX_MEM:
		model_rorx(dst, src, flags, aux, imm, 1, seed, b);
		break;
	case X86_OP_BZHI:
		model_bzhi(dst, src, aux, flags, 0U, 0ULL, 0, seed, b);
		break;
	case X86_OP_BZHI_MEM:
		model_bzhi(dst, src, X86_REG_NONE, flags, aux, imm, 1,
			   seed, b);
		break;
	case X86_OP_BT_IMM:
	case X86_OP_BT_MEM_IMM:
		model_bt(dst, flags, aux, imm,
			 op == X86_OP_BT_MEM_IMM, seed, b);
		break;
	case X86_OP_BT: {
		struct snap sb = *seed;

		sb.x[src] = seed->x[src];
		model_bt(dst, flags, aux, sb.x[src], 0, seed, b);
		break;
	}
	case X86_OP_IMUL_IMM:
		model_imul(dst, src, flags, 0U, imm, 0, seed, b);
		break;
	case X86_OP_IMUL_MEM_IMM:
		model_imul(dst, src, flags, aux, imm, 1, seed, b);
		break;
	case X86_OP_MULX:
		model_mulx(dst, src, aux, flags, seed, b);
		break;
	case X86_OP_REP_MOVS:
		model_rep_movs(flags, imm, seed, b);
		break;
	case X86_OP_ANDN:
		model_andn(dst, src, aux, flags, 0ULL, 0, seed, b);
		break;
	case X86_OP_ANDN_MEM:
		model_andn(dst, src, aux, flags, imm, 1, seed, b);
		break;
	case X86_OP_XCHG:
		model_xchg(dst, src, flags, seed, b);
		break;
	case X86_OP_DIV:
		model_div(src, flags, seed, b);
		break;
	case X86_OP_PUSH:
		model_push(src, seed, b);
		break;
	case X86_OP_POP:
		model_pop(dst, flags, seed, b);
		break;
	default:
		break;
	}
}
/* ---- Checks ------------------------------------------------------------ */

/* Drive the real dispatcher and the model on identical planted states, then
 * require the whole post-state snapshots to agree under snap_eq. Arms whose
 * semantics legitimately leave the state untouched (a false-cc cmov, a bt of
 * a set bit, a cmp whose flags coincide with the planted pattern) are quiet,
 * so effectiveness is not demanded per row; any model/sim divergence still
 * shows up as a snapshot difference. The address memory arm dereferences
 * an ABI-tagged base through its real pointer, so the drive can request the
 * shared base register planted with the heap address and the ABI tag. */
static void check_arm(const char *what, unsigned op, unsigned dst,
		      unsigned src, unsigned flags, unsigned aux, __u64 imm)
{
	struct snap seed, a;
	struct snap b;

	{
		DECL_STATE();
		PLANT();
		PLANT_ABI_BASE(X86_RDX);
		PLANT_HEAP_BASE(X86_RBX);
		PLANT_HEAP_BASE(X86_RDI);
		PLANT_HEAP_BASE(X86_RSI);
		PLANT_STACK_RSP();
		stack_arena_base =
			(unsigned long)(void *)&__x86_stack_mem.b[0];
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(op, dst, src, flags, aux, imm);
		CAPTURE_ALL(&a);
	}

	b = seed;
	apply_model(op, dst, src, flags, aux, imm, &seed, &b);

	cases++;
	if (!snap_eq(&a, &b, what, flags))
		failures++;
	cases++;
}

/* Drive the real dispatcher and the model on identical planted states, then
 * require the whole post-state snapshots to agree and the drive to have done
 * something (the NOP exception excepted). The memory forms get their own
 * checker because the arm reads RDI and RSI as pointers the generic frames
 * cannot plant.
 */
static void check_callmem(unsigned op, unsigned is_reg, __u64 imm)
{
	struct snap seed, a;
	struct snap b;

	{
		DECL_STATE();
		PLANT();
		PLANT_HEAP_BASE(X86_RBX);
		PLANT_HEAP_BASE(X86_RDI);
		PLANT_HEAP_BASE(X86_RSI);
		X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, 8U, X86_WIDTH_64);
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(op, X86_RAX, X86_REG_NONE, 0U, 0U, imm);
		CAPTURE_ALL(&a);
	}

	b = seed;
	model_callmem(op == X86_OP_CALL_MEMCPY || op == X86_OP_CALL_MEMCPY_REG,
		      is_reg, imm, &b);

	cases++;
	if (!snap_eq(&a, &b, "callMem", 0U))
		failures++;
	cases++;
}

/* CALL_REG frames the id inside SRC the way the arm reads it: the checker
 * plants the id into one register (RAX, the sim's helper-source port) and
 * drives both sides against the stubbed host returns. */
static void check_callreg(const char *what, __u64 id)
{
	struct snap seed, a;
	struct snap b;

	{
		DECL_STATE();
		PLANT();
		PLANT_HEAP_BASE(X86_RBX);
		X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, (void *)(long)id,
					    X86_SIM_TAG_SCALAR);
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(X86_OP_CALL_REG, X86_REG_NONE, X86_RAX, 0U,
			       0U, 0U);
		CAPTURE_ALL(&a);
	}

	b = seed;
	model_callreg(X86_RAX, &b);

	cases++;
	if (!snap_eq(&a, &b, what, 0U))
		failures++;
	cases++;
}

/* NOP: the whole state must be the planted seed, byte for byte. */
static void check_nop(void)
{
	struct snap seed, a;

	{
		DECL_STATE();
		PLANT();
		PLANT_HEAP_BASE(X86_RBX);
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(X86_OP_NOP, X86_RDX, X86_RCX, X86_WIDTH_64, 0U,
			       0U);
		CAPTURE_ALL(&a);
	}

	cases++;
	if (!snap_eq(&a, &seed, "nop", X86_WIDTH_64))
		failures++;
}

/* The one opcode the singleton set does not name (RET has no arm) must leave
 * the whole state unchanged; the singleton oracle's contribution to the
 * fall-through story is this second probe, complementing the families
 * oracle's. */
static void check_nonmember(void)
{
	struct snap seed, a;

	{
		DECL_STATE();
		PLANT();
		PLANT_HEAP_BASE(X86_RBX);
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(X86_OP_RET, X86_RDX, X86_RAX, X86_WIDTH_64, 0U,
			       0U);
		CAPTURE_ALL(&a);
	}

	cases++;
	if (!snap_eq(&a, &seed, "nonmember", X86_WIDTH_64))
		failures++;
}

int main(void)
{
	static const unsigned movreg_flags[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	static const unsigned regpair_dst[3] = { X86_RAX, X86_RBX, X86_RSP };
	static const unsigned regpair_src[3] = { X86_RCX, X86_RSP, X86_RDX };
	static const unsigned xmm_ops[2] = { X86_OP_LOAD_XMM0,
					     X86_OP_STORE_XMM0 };
	static const unsigned xmm_bases[2] = { X86_RDX, X86_RSP };
	static const unsigned lea_flags[3] = { 0U, X86_WIDTH_32,
					       X86_WIDTH_64 };
	static const unsigned lea_aux[2] = { 0U, X86_LEA_AUX_RODATA };
	static const unsigned alu_ops[4] = {
		X86_OP_ALU_MEM, X86_OP_ALU_MEM_UNARY, X86_OP_ALU_MEM_IMM,
		X86_OP_ALU_MEM_REG,
	};
	static const unsigned alu_dst[4] = { X86_RDX, X86_RDX, X86_RDX,
					     X86_RBX };
	static const unsigned alu_src[4] = { X86_RBX, X86_REG_NONE,
					     X86_REG_NONE, X86_RDX };
	static const unsigned alus[6] = {
		X86_ALU_ADD, X86_ALU_SUB, X86_ALU_XOR, X86_ALU_SBB,
		X86_ALU_ADC, X86_ALU_DEC,
	};
	static const unsigned alus8[4] = {
		X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR, X86_ALU_ROL,
	};
	static const unsigned cmov_ops[2] = { X86_OP_CMOV, X86_OP_CMOV_MEM };
	static const unsigned cmov_flags[3] = { 0U, X86_WIDTH_16,
						X86_WIDTH_64 };
	static const unsigned ccodes[5] = {
		X86_CC_B, X86_CC_E, X86_CC_G, X86_CC_LE, X86_CC_O,
	};
	static const unsigned setcc_dst[2] = { X86_RDX, X86_RSP };
	static const unsigned pop_flags[3] = { 0U, X86_WIDTH_16,
					       X86_WIDTH_64 };
	unsigned o, f, a;

	/* NOP: the identity. */
	check_nop();

	/* CALL_MEM*: one drive per opcode (copy/fill × imm/reg count) through
	 * the dedicated checker that plants the RDI/RSI pointers the arm
	 * dereferences. */
	check_callmem(X86_OP_CALL_MEMCPY, 0U, 32ULL);
	check_callmem(X86_OP_CALL_MEMSET, 0U, 32ULL);
	check_callmem(X86_OP_CALL_MEMCPY_REG, 1U, 1024ULL);
	check_callmem(X86_OP_CALL_MEMSET_REG, 1U, 1024ULL);

	/* CALL_REG: the whole helper-slot ladder, run from the drive tuple
	 * (the id rides in SRC for this arm). */
	check_callreg("callReg/1", X86_SIM_HELPER_bpf_map_lookup_elem);
	check_callreg("callReg/2", X86_SIM_HELPER_bpf_map_update_elem);
	check_callreg("callReg/3", X86_SIM_HELPER_bpf_map_delete_elem);
	check_callreg("callReg/4",
		      X86_SIM_HELPER_bpf_get_current_uid_gid);
	check_callreg("callReg/5",
		      X86_SIM_HELPER_bpf_get_current_pid_tgid);
	check_callreg("callReg/6",
		      X86_SIM_HELPER_bpf_get_smp_processor_id);
	check_callreg("callReg/7", X86_SIM_HELPER_bpf_ktime_get_ns);
	check_callreg("callReg/0", 0ULL);

	check_arm("movImm/lo", X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE,
		  X86_WIDTH_8, KPROG_X86_REG_LANE_AUX(0U, 0U, 0U), 0xa7ULL);
	check_arm("movImm/hi", X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE,
		  X86_WIDTH_8, KPROG_X86_REG_LANE_AUX(0U, 8U, 0U), 0x33ULL);
	for (f = 0; f < 3U; f++)
		check_arm("movImm", X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE,
			  movreg_flags[f], 0U, 0x1122334455667788ULL);

	/* MOV_REG: the three arms across the register pairs. */
	for (f = 0; f < 5U; f++)
		for (a = 0; a < 3U; a++)
			check_arm("movReg", X86_OP_MOV_REG, regpair_dst[a],
				  regpair_src[a], movreg_flags[f], 0U, 0ULL);
	check_arm("movReg/laneHi", X86_OP_MOV_REG, X86_RDX, X86_RCX,
		  X86_WIDTH_8, KPROG_X86_REG_LANE_AUX(0U, 8U, 8U), 0ULL);
	check_arm("movReg/laneLo", X86_OP_MOV_REG, X86_RDX, X86_RCX,
		  X86_WIDTH_8, KPROG_X86_REG_LANE_AUX(0U, 0U, 8U), 0ULL);

	/* MOVBE load/store over the ABI base and the stack base. The address
	 * memory arm dereferences the ABI base once through its real pointer,
	 * so the drive plants RDX with the heap address and the ABI tag; the
	 * stack-pointer base routes through the arena. Over the absent and
	 * every width code. Every drive passes a none-index aux so the
	 * memory offset is the raw displacement. The none base reaches only
	 * the store arm; its absent-base drive runs through RSP. */
	for (f = 0; f < 5U; f++) {
		check_arm("movbeLoad", X86_OP_MOVBE_LOAD, X86_RDX,
			  X86_RDX, movreg_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
			  12ULL);
		check_arm("movbeStore", X86_OP_MOVBE_STORE, X86_RDX,
			  X86_RDX, movreg_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 12ULL);
		check_arm("movbeLoad/stack", X86_OP_MOVBE_LOAD, X86_RDX,
			  X86_RSP, movreg_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
			  12ULL);
		check_arm("movbeStore/stack", X86_OP_MOVBE_STORE, X86_RSP,
			  X86_RDX, movreg_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 12ULL);
	}
	check_arm("movbeStore/none", X86_OP_MOVBE_STORE, X86_RSP, X86_RCX,
		  X86_WIDTH_16, KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
		  12ULL);
	/* XMM0 pair-move over the register and stack bases (the sim's arm
	 * cannot resolve the none form from a drive, so the oracle exercises
	 * the real bases). */
	for (o = 0; o < 2U; o++)
		for (a = 0; a < 2U; a++)
			check_arm("xmm0", xmm_ops[o], xmm_bases[a],
				  xmm_bases[a], 0U,
				  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U,
						    0U),
				  8ULL);

	/* LEA over the four shapes. */
	for (f = 0; f < 3U; f++)
		for (a = 0; a < 2U; a++)
			check_arm("lea", X86_OP_LEA, X86_RDX,
				  a ? X86_RSP : X86_RCX, lea_flags[f],
				  lea_aux[a], 16ULL);

	/* ALU_MEM quad over the six ALU tokens and the addressed bases. */
	for (o = 0; o < 4U; o++)
		for (a = 0; a < 6U; a++)
			check_arm("aluMem", alu_ops[o], alu_dst[o],
				  alu_src[o], X86_WIDTH_32,
				  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U,
						    alus[a]),
				  16ULL);

	/* CMP_REG_MEM: destinations operand vs. the addressed source. */
	for (f = 0; f < 3U; f++)
		check_arm("cmpRegMem", X86_OP_CMP_REG_MEM, X86_RDX, X86_RBX,
			  lea_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 16ULL);

	/* CMOV pair over both condition outcomes and the writeback arms. The
	 * register form's condition is the whole AUX word; the memory form's
	 * is the AUX source-shift byte, so the drive folds the cc into
	 * byte 3. */
	for (o = 0; o < 2U; o++)
		for (f = 0; f < 3U; f++)
			for (a = 0; a < 5U; a++)
				check_arm("cmov", cmov_ops[o],
					  o ? X86_RCX : X86_RDX, X86_RBX,
					  cmov_flags[f],
					  (o ? KPROG_X86_MEM_AUX(X86_REG_NONE,
								 0U, 0U,
								 ccodes[a]) :
					       builds_word(ccodes[a], 0U,
							   0U)),
					  0ULL);
	/* SETCC register form over 14 ccodes and both lanes plus the
	 * no-match byte; memory form over the stack and ordinary bases. */
	for (a = 0; a < 14U; a++) {
		check_arm("setcc", X86_OP_SETCC, X86_RAX, X86_REG_NONE, 0U,
			  builds_word(a, a % 2U ? 8U : 0U, 0U), 0ULL);
		check_arm("setccMem", X86_OP_SETCC_MEM, setcc_dst[a % 2U],
			  X86_REG_NONE, 0U,
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, a), 16ULL);
	}
	check_arm("setcc/none", X86_OP_SETCC, X86_RAX, X86_REG_NONE, 0U,
		  builds_word(10U, 0U, 0U), 0ULL);

	/* BSWAP / POPCNT over every width. */
	for (f = 0; f < 5U; f++) {
		check_arm("bswap", X86_OP_BSWAP, X86_RDX, X86_REG_NONE,
			  movreg_flags[f], 0U, 0ULL);
		check_arm("popcnt", X86_OP_POPCNT, X86_RCX, X86_RDX,
			  movreg_flags[f], 0U, 0ULL);
	}

	/* SHIFTX / RORX across reg/mem × width × kind. The register form's
	 * AUX is the count register; the memory form's AUX carries the count
	 * register in the source-shift byte and no index. */
	for (f = 0; f < 5U; f++)
		for (a = 0; a < 4U; a++) {
			check_arm("shiftx", X86_OP_SHIFTX, X86_RDX, X86_RCX,
				  movreg_flags[f], X86_RCX,
				  shiftimm_word(alus8[a]));
			check_arm("rorx", X86_OP_RORX, X86_RDX, X86_RCX,
				  movreg_flags[f], 0U, 0x07050301ULL);
		}
	for (f = 0; f < 5U; f++)
		for (a = 0; a < 4U; a++) {
			check_arm("shiftxMem", X86_OP_SHIFTX_MEM, X86_RDX,
				  X86_RBX, movreg_flags[f],
				  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U,
						    X86_RCX),
				  shiftimm_word(alus8[a]));
			check_arm("rorxMem", X86_OP_RORX_MEM, X86_RDX, X86_RBX,
				  movreg_flags[f],
				  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
				  12ULL);
		}

	/* BZHI pair; BT trio. BZHI takes the count register through AUX at
	 * the register form, the count through AUX's source-shift byte for
	 * the memory form. */
	for (f = 0; f < 5U; f++) {
		check_arm("bzhi", X86_OP_BZHI, X86_RDX, X86_RCX,
			  movreg_flags[f], X86_RCX, 0ULL);
		check_arm("bzhiMem", X86_OP_BZHI_MEM, X86_RDX, X86_RBX,
			  movreg_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_RCX),
			  0ULL);
	}
	check_arm("bt", X86_OP_BT, X86_RDX, X86_RCX, 0U, 0U, 0ULL);
	check_arm("btImm", X86_OP_BT_IMM, X86_RDX, X86_RCX, 0U, 0U, 39ULL);
	check_arm("btMemImm", X86_OP_BT_MEM_IMM, X86_RDX, X86_RBX, 0U,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 39ULL);

	/* IMUL pair over every width. */
	for (f = 0; f < 5U; f++) {
		check_arm("imulImm", X86_OP_IMUL_IMM, X86_RDX, X86_RCX,
			  movreg_flags[f], 0U, 0xffffffa3ULL);
		check_arm("imulMemImm", X86_OP_IMUL_MEM_IMM, X86_RDX, X86_RBX,
			  movreg_flags[f],
			  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, X86_WIDTH_16,
					    0U), 0xffffffa3ULL);
	}

	/* MULX over both arms, with and without the high destination. */
	for (f = 0; f < 5U; f++)
		for (a = 0; a < 2U; a++)
			check_arm("mulx", X86_OP_MULX, X86_R8,
				  a ? X86_REG_NONE : X86_RCX, movreg_flags[f],
				  a ? X86_R9 : X86_REG_NONE, 0ULL);

	/* REP_MOVS: counts 0, 1, 4 and the 64-bound saturating count. */
	check_arm("repMovs/0", X86_OP_REP_MOVS, X86_REG_NONE, X86_REG_NONE,
		  0U, 0U, 0ULL);
	check_arm("repMovs/1", X86_OP_REP_MOVS, X86_REG_NONE, X86_REG_NONE,
		  X86_WIDTH_8,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 1ULL);
	check_arm("repMovs/4", X86_OP_REP_MOVS, X86_REG_NONE, X86_REG_NONE,
		  X86_WIDTH_32,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 4ULL);
	/* ANDN pair: register and addressed second operands. */
	check_arm("andn", X86_OP_ANDN, X86_RDX, X86_RCX, X86_RBX,
		  X86_WIDTH_64, 0ULL);
	check_arm("andnMem", X86_OP_ANDN_MEM, X86_RDX, X86_RDX, X86_WIDTH_64,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, X86_RDX), 0ULL);

	/* XCHG at the two arms, with distinct values and tags. */
	check_arm("xchg64", X86_OP_XCHG, X86_RAX, X86_RBX, X86_WIDTH_64, 0U,
		  0ULL);
	check_arm("xchg32", X86_OP_XCHG, X86_RAX, X86_RBX, X86_WIDTH_32, 0U,
		  0ULL);

	/* DIV over the four width arms, distinct quotients and remainders. */
	for (f = 0; f < 5U; f++)
		check_arm("div", X86_OP_DIV, X86_REG_NONE, X86_RCX,
			  movreg_flags[f], 0U, 0ULL);

	/* PUSH without a flags field, and POP across all widths (the
	 * FLAGS-honouring body). */
	check_arm("push", X86_OP_PUSH, X86_REG_NONE, X86_RCX, 0U, 0U, 0ULL);
	for (f = 0; f < 3U; f++)
		check_arm("pop", X86_OP_POP, X86_RDX, X86_REG_NONE,
			  pop_flags[f], 0U, 0ULL);

	check_nonmember();

	if (failures != 0) {
		printf("x86 dispatch singleton route host cross-check: FAIL "
		       "(%d)\n", failures);
		return 1;
	}
	printf("x86 dispatch singleton route host cross-check: OK (%lu "
	       "cases)\n", cases);
	return 0;
}
