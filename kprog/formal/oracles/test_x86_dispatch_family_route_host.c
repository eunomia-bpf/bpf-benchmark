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
 * arena, and the 512-byte backing heap, so a misroute that touches any of them
 * is caught.
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

/* Independent zero extension of the source lane: keep only the low bits. */
static __u64 zero_extend_oracle(__u64 v, unsigned width)
{
	return v & width_mask(width);
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

/* Independent SHLD: high b bits of (dst:src) shifted left by k. */
static __u64 shld_oracle(__u64 dst, __u64 src, unsigned k, unsigned bits)
{
	unsigned __int128 msk = bits == 64 ? ~(unsigned __int128)0
		: (((unsigned __int128)1 << bits) - 1);
	unsigned __int128 w = (((unsigned __int128)(dst & (__u64)msk)) << bits)
		| (src & (__u64)msk);

	if (k >= bits)
		return (__u64)(((unsigned __int128)(src & (__u64)msk) << (k - bits))
			& msk);
	return (__u64)((w << k) >> bits) & (__u64)msk;
}

/* Independent SHRD: low b bits of (src:dst) shifted right by k. */
static __u64 shrd_oracle(__u64 dst, __u64 src, unsigned k, unsigned bits)
{
	unsigned __int128 msk = bits == 64 ? ~(unsigned __int128)0
		: (((unsigned __int128)1 << bits) - 1);
	unsigned __int128 w = (((unsigned __int128)(src & (__u64)msk)) << bits)
		| (dst & (__u64)msk);

	return (__u64)(w >> k) & (__u64)msk;
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

/* Byte-for-byte equality of every modeled cell, without any output. */
static int snap_cmp(const struct snap *a, const struct snap *b)
{
	unsigned j;

	for (j = 0; j < 16U; j++)
		if (a->x[j] != b->x[j] || a->t[j] != b->t[j])
			return 0;
	if (a->cf != b->cf || a->zf != b->zf || a->sf != b->sf ||
	    a->of != b->of)
		return 0;
	if (a->xmm0_lo != b->xmm0_lo || a->xmm0_hi != b->xmm0_hi ||
	    a->ret != b->ret)
		return 0;
	for (j = 0; j < X86_SIM_STACK_BYTES; j++)
		if (a->stack[j] != b->stack[j])
			return 0;
	for (j = 0; j < HEAP_BYTES; j++)
		if (a->heap[j] != b->heap[j])
			return 0;
	return 1;
}

/* Equality with a diagnostic naming the first diverging cell. */
static int snap_eq(const struct snap *a, const struct snap *b, const char *what,
		   unsigned w)
{
	unsigned j;

	for (j = 0; j < 16U; j++) {
		if (a->x[j] != b->x[j] || a->t[j] != b->t[j]) {
			printf("MISMATCH %s width=%u reg%u=0x%llx/%u vs "
			       "0x%llx/%u\n", what, w, j,
			       (unsigned long long)a->x[j], (unsigned)a->t[j],
			       (unsigned long long)b->x[j], (unsigned)b->t[j]);
			return 0;
		}
	}
	if (a->cf != b->cf || a->zf != b->zf || a->sf != b->sf ||
	    a->of != b->of) {
		printf("MISMATCH %s width=%u flags %u%u%u%u vs %u%u%u%u\n", what,
		       w, a->cf, a->zf, a->sf, a->of, b->cf, b->zf, b->sf,
		       b->of);
		return 0;
	}
	if (a->xmm0_lo != b->xmm0_lo || a->xmm0_hi != b->xmm0_hi ||
	    a->ret != b->ret) {
		printf("MISMATCH %s width=%u xmm0/ret differ\n", what, w);
		return 0;
	}
	for (j = 0; j < X86_SIM_STACK_BYTES; j++) {
		if (a->stack[j] != b->stack[j]) {
			printf("MISMATCH %s width=%u stack[%u]=0x%02x/0x%02x\n",
			       what, w, j, a->stack[j], b->stack[j]);
			return 0;
		}
	}
	for (j = 0; j < HEAP_BYTES; j++) {
		if (a->heap[j] != b->heap[j]) {
			printf("MISMATCH %s width=%u heap[%u]=0x%02x/0x%02x\n",
			       what, w, j, a->heap[j], b->heap[j]);
			return 0;
		}
	}
	return 1;
}

/* ---- Independent models for the three inline-bodied families ----------- */

/* MOV_LOAD_MAP_PTR writes the map-pointer tag; MOV_LOAD_HELPER_ID first does a
 * width-64 scalar lane write of the immediate (which the pointer write then
 * replaces bit for bit) and installs the helper-id tag. Both write the same
 * destination value, so only the tag distinguishes them; neither writes a
 * flag. */
static void model_mov_load_ptr(unsigned op, unsigned dst, __u64 imm,
			       struct snap *b)
{
	b->x[dst] = imm;
	b->t[dst] = (op == X86_OP_MOV_LOAD_MAP_PTR) ? X86_SIM_TAG_MAP_PTR
						    : X86_SIM_TAG_HELPER_ID;
}

/* MOVZX_REG zero-extends and MOVSX_REG sign-extends the source lane, resolved
 * from AUX (absent code falls back to the destination width), then writes at
 * the FLAGS width. No flags are written. */
static void model_movx(unsigned op, unsigned dst, unsigned src, unsigned flags,
		       unsigned aux, struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned sw = aux ? aux : w;
	__u64 dstv = b->x[dst];
	__u64 value = b->x[src];

	if (op == X86_OP_MOVSX_REG)
		value = sign_extend_oracle(value, sw);
	else
		value = zero_extend_oracle(value, sw);

	b->x[dst] = model_partial_write(dstv, value, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
}

/* The shift-flag contract for the two families the double-shift arm reports:
 * the SHL family takes the left-count carry path, the SHR family the
 * right-count path. A count of zero leaves the flags as they were, and the OF
 * update exists only for a count of one. */
static void model_shift_flags(unsigned alu, __u64 a, unsigned count, __u64 r,
			      unsigned bits, __u64 sign, struct snap *b)
{
	if (count == 0)
		return;
	b->zf = (r == 0);
	b->sf = (r & sign) != 0;
	if (alu == 5U) { /* X86_ALU_SHL */
		b->cf = count <= bits ? (unsigned)((a >> (bits - count)) & 1U)
				      : 0U;
		if (count == 1)
			b->of = (__u8)(b->sf ^ b->cf);
	} else if (alu == 6U) { /* X86_ALU_SHR */
		b->cf = count <= bits ? (unsigned)((a >> (count - 1)) & 1U)
				      : 0U;
		if (count == 1)
			b->of = (__u8)((a & sign) != 0);
	}
}

/* Restate the inlined double-shift arm: select the SHLD/SHRD arm from the
 * opcode, compute the result, update the shift flags, and write the
 * destination at the FLAGS width. A zero count performs nothing. */
static void model_doubleshift(unsigned op, unsigned dst, unsigned src,
			      unsigned flags, __u64 imm, struct snap *b)
{
	unsigned w = resolve_width(flags);
	unsigned bits = width_bits(w);
	__u64 mask = width_mask(w);
	__u64 sign = 1ULL << (bits - 1U);
	unsigned count = shift_count(imm, w);
	__u64 dstv = b->x[dst];
	__u64 srcv = b->x[src];
	__u64 result;
	unsigned alu;

	if (count == 0)
		return;

	if (op == X86_OP_SHLD_IMM) {
		result = shld_oracle(dstv, srcv, count, bits);
		alu = 5U;
	} else {
		result = shrd_oracle(dstv, srcv, count, bits);
		alu = 6U;
	}

	model_shift_flags(alu, dstv & mask, count, result & mask, bits, sign, b);

	b->x[dst] = model_partial_write(dstv, result, w);
	b->t[dst] = X86_SIM_TAG_SCALAR;
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
 * so a stack-frame access resolves into the arena), the frame arena bytes, the
 * flags sentinel, and the heap. Deterministic, so both drives start from the
 * same state. */
#define PLANT()                                                            \
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
		__x86_cf = 0U;                                             \
		__x86_zf = 1U;                                             \
		__x86_sf = 1U;                                             \
		__x86_of = 1U;                                             \
		fill_heap();                                               \
	} while (0)

/* ---- Drive the family's body macro with the dispatcher arm's tuple ----- */

enum {
	FAM_MOV_LOAD,
	FAM_MOV_STORE,
	FAM_ALU_IMM,
	FAM_ALU_REG,
	FAM_CMP_IMM,
	FAM_CMP_REG,
	FAM_CMP_MEM,
};

/* Invoke the family's body macro with the exact tuple the dispatcher arm
 * forwards, in the caller's state scope. */
#define DRIVE_BODY(FAM, OP, DST, SRC, FLAGS, AUX, IMM)                     \
	do {                                                               \
		switch (FAM) {                                             \
		case FAM_MOV_LOAD:                                         \
			X86_SIM_L_EXEC_MOV_LOAD((OP), (DST), (SRC), (FLAGS),\
						(AUX), (IMM));             \
			break;                                             \
		case FAM_MOV_STORE:                                        \
			X86_SIM_L_EXEC_STORE((OP), (DST), (SRC), (FLAGS),  \
					     (AUX), (IMM));                \
			break;                                             \
		case FAM_ALU_IMM:                                          \
			X86_SIM_L_EXEC_ALU_IMM((DST), (FLAGS), (AUX), (IMM));\
			break;                                             \
		case FAM_ALU_REG:                                          \
			X86_SIM_L_EXEC_ALU_REG((DST), (SRC), (FLAGS), (AUX));\
			break;                                             \
		case FAM_CMP_IMM:                                          \
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX((OP), (DST), (FLAGS),\
				(AUX), (IMM));                                 \
			break;                                             \
		case FAM_CMP_REG:                                          \
			X86_SIM_L_EXEC_CMP_REG_OP_AUX((OP), (DST), (SRC),  \
				(FLAGS), (AUX));                               \
			break;                                             \
		case FAM_CMP_MEM:                                          \
			X86_SIM_L_EXEC_CMP_MEM((OP), (DST), (SRC), (FLAGS),\
					       (AUX), (IMM));              \
			break;                                             \
		default:                                                   \
			break;                                             \
		}                                                          \
	} while (0)

/* ---- Checks ------------------------------------------------------------ */

/* A forwarding family: the dispatcher member must leave the same whole state
 * as the body macro invoked directly with the arm's tuple. `mem_base` names the
 * register that must hold a valid heap pointer for the memory-touching
 * families (or X86_REG_NONE), so both drives dereference real bytes. The state
 * must also differ from its seed, so a member that fell through to a no-op arm
 * cannot pass vacuously. */
static void check_macro_family(int fam, const char *what, unsigned op,
			       unsigned dst, unsigned src, unsigned flags,
			       unsigned aux, __u64 imm, unsigned mem_base)
{
	struct snap seed, a, b;

	{
		DECL_STATE();
		PLANT();
		if (mem_base != X86_REG_NONE && mem_base != X86_RSP)
			X86_SIM_L_WRITE_REG_PTR_TAG(mem_base, (void *)heap,
						    X86_SIM_TAG_SCALAR);
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(op, dst, src, flags, aux, imm);
		CAPTURE_ALL(&a);
	}
	{
		DECL_STATE();
		PLANT();
		if (mem_base != X86_REG_NONE && mem_base != X86_RSP)
			X86_SIM_L_WRITE_REG_PTR_TAG(mem_base, (void *)heap,
						    X86_SIM_TAG_SCALAR);
		DRIVE_BODY(fam, op, dst, src, flags, aux, imm);
		CAPTURE_ALL(&b);
	}

	cases++;
	if (!snap_eq(&a, &b, what, flags))
		failures++;
	cases++;
	if (snap_cmp(&a, &seed)) {
		printf("MISMATCH %s width=%u op=%u did nothing\n", what, flags,
		       op);
		failures++;
	}
}
/* MOV_LOAD_PTR family: the inline arm against an independent model. */
static void check_inline_ptr(unsigned op, unsigned dst, unsigned flags,
			     __u64 imm)
{
	struct snap seed, a, b;

	{
		DECL_STATE();
		PLANT();
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(op, dst, X86_RCX, flags, 0U, imm);
		CAPTURE_ALL(&a);
	}

	b = seed;
	model_mov_load_ptr(op, dst, imm, &b);

	cases++;
	if (!snap_eq(&a, &b, "movLoadPtr", flags))
		failures++;
	cases++;
	if (snap_cmp(&a, &seed)) {
		printf("MISMATCH movLoadPtr width=%u op=%u did nothing\n", flags,
		       op);
		failures++;
	}
}

/* MOVX_REG family: the inline arm against an independent model. */
static void check_inline_movx(unsigned op, unsigned dst, unsigned src,
			      unsigned flags, unsigned aux)
{
	struct snap seed, a, b;

	{
		DECL_STATE();
		PLANT();
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(op, dst, src, flags, aux, 0ULL);
		CAPTURE_ALL(&a);
	}

	b = seed;
	model_movx(op, dst, src, flags, aux, &b);

	cases++;
	if (!snap_eq(&a, &b, "movxReg", flags))
		failures++;
	cases++;
	if (snap_cmp(&a, &seed)) {
		printf("MISMATCH movxReg width=%u op=%u did nothing\n", flags,
		       op);
		failures++;
	}
}

/* DOUBLE_SHIFT family: the inline arm against an independent model. */
static void check_inline_doubleshift(unsigned op, unsigned dst, unsigned src,
				     unsigned flags, __u64 imm)
{
	struct snap seed, a, b;

	{
		DECL_STATE();
		PLANT();
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(op, dst, src, flags, 0U, imm);
		CAPTURE_ALL(&a);
	}

	b = seed;
	model_doubleshift(op, dst, src, flags, imm, &b);

	cases++;
	if (!snap_eq(&a, &b, "doubleShift", flags))
		failures++;
	cases++;
	if (snap_cmp(&a, &seed)) {
		printf("MISMATCH doubleShift width=%u op=%u did nothing\n",
		       flags, op);
		failures++;
	}
}

/* A non-member opcode reaches no arm, so the whole state must be unchanged.
 * The x86 chain has no `unsupported` hook, so this is the only observable. */
static void check_nonmember(void)
{
	struct snap seed, a;

	{
		DECL_STATE();
		PLANT();
		CAPTURE_ALL(&seed);
		X86_SIM_L_EXEC(X86_OP_RET, X86_RDX, X86_RAX, X86_WIDTH_64, 0U,
			       0ULL);
		CAPTURE_ALL(&a);
	}

	cases++;
	if (!snap_eq(&a, &seed, "nonmember", X86_WIDTH_64))
		failures++;
}

int main(void)
{
	static const unsigned widths[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	static const unsigned widths_aux[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	static const unsigned mem_widths[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	static const unsigned load_ops[3] = {
		X86_OP_MOV_LOAD, X86_OP_MOV_LOAD_SCALAR, X86_OP_MOVSX_LOAD,
	};
	static const unsigned alu_ops[2] = { X86_OP_ALU_IMM, X86_OP_ADD_IMM };
	static const unsigned alu_reg_ops[3] = {
		X86_OP_ALU_REG, X86_OP_ADD_REG, X86_OP_XOR_REG,
	};
	static const unsigned cmp_imm_ops[2] = {
		X86_OP_CMP_IMM, X86_OP_TEST_IMM,
	};
	static const unsigned cmp_reg_ops[2] = {
		X86_OP_CMP_REG, X86_OP_TEST_REG,
	};
	static const unsigned cmp_mem_ops[4] = {
		X86_OP_CMP_MEM_IMM, X86_OP_TEST_MEM_IMM, X86_OP_CMP_MEM_REG,
		X86_OP_TEST_MEM_REG,
	};
	static const unsigned alus[9] = {
		X86_ALU_ADD, X86_ALU_SUB, X86_ALU_XOR, X86_ALU_AND,
		X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR, X86_ALU_SBB,
		X86_ALU_ADC,
	};
	unsigned fi, o, a, mi;

	/* Inline family: MOV_LOAD_PTR. */
	for (o = 0; o < 2U; o++) {
		static const unsigned ptr_ops[2] = {
			X86_OP_MOV_LOAD_MAP_PTR, X86_OP_MOV_LOAD_HELPER_ID,
		};

		for (fi = 0; fi < 5U; fi++)
			check_inline_ptr(ptr_ops[o], X86_RDX, widths[fi],
					 0x1122334455667788ULL);
	}

	/* Inline family: MOVX_REG, over every source-width AUX code. */
	for (o = 0; o < 2U; o++) {
		static const unsigned movx_ops[2] = {
			X86_OP_MOVZX_REG, X86_OP_MOVSX_REG,
		};

		for (fi = 0; fi < 5U; fi++)
			for (a = 0; a < 5U; a++)
				check_inline_movx(movx_ops[o], X86_RAX, X86_RBX,
						  widths[fi], widths_aux[a]);
	}

	/* Inline family: DOUBLE_SHIFT, over nonzero counts only, so the arm's
	 * destination write is always observable. */
	for (o = 0; o < 2U; o++) {
		static const unsigned shift_ops[2] = {
			X86_OP_SHLD_IMM, X86_OP_SHRD_IMM,
		};
		static const __u64 imms[7] = {
			1ULL, 2ULL, 7ULL, 8ULL, 15ULL, 31ULL, 63ULL,
		};

		for (fi = 0; fi < 5U; fi++)
			for (mi = 0; mi < 7U; mi++)
				check_inline_doubleshift(shift_ops[o], X86_RCX,
							 X86_RBX, widths[fi],
							 imms[mi]);
	}

	for (fi = 0; fi < 5U; fi++) {
		unsigned flags = widths[fi];

		/* MOV_LOAD family, ordinary (heap-backed) and stack arms. */
		for (o = 0; o < 3U; o++)
			for (mi = 0; mi < 5U; mi++)
				check_macro_family(
					FAM_MOV_LOAD, "movLoad", load_ops[o],
					X86_RDX, X86_RAX, flags,
					KPROG_X86_MEM_AUX(X86_REG_NONE, 0U,
							  mem_widths[mi], 0U),
					0ULL, X86_RAX);
		check_macro_family(
			FAM_MOV_LOAD, "movLoad/stack", X86_OP_MOV_LOAD, X86_RDX,
			X86_RSP, flags,
			KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, flags, 0U),
			(__u64)-8, X86_RSP);

		/* MOV_STORE family, heap-backed immediate and register forms,
		 * plus the stack-backed register form. */
		check_macro_family(
			FAM_MOV_STORE, "movStore/imm", X86_OP_MOV_STORE_IMM,
			X86_RAX, X86_RDX, flags,
			KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 0ULL,
			X86_RAX);
		check_macro_family(
			FAM_MOV_STORE, "movStore/reg", X86_OP_MOV_STORE_REG,
			X86_RAX, X86_RDX, flags,
			KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 0ULL,
			X86_RAX);
		check_macro_family(
			FAM_MOV_STORE, "movStore/stack", X86_OP_MOV_STORE_REG,
			X86_RSP, X86_RDX, flags,
			KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
			(__u64)-8, X86_RSP);

		/* ALU_IMM family: every simulator ALU opcode in the payload
		 * byte, so the whole arm ladder (SBB/ADC/plain) is exercised. */
		for (o = 0; o < 2U; o++)
			for (a = 0; a < 9U; a++)
				check_macro_family(
					FAM_ALU_IMM, "aluImm", alu_ops[o],
					X86_RDX, X86_RCX, flags,
					KPROG_X86_REG_LANE_AUX(alus[a], 0U, 0U),
					0x1234ULL, X86_REG_NONE);

		/* ALU_REG family. */
		for (o = 0; o < 3U; o++)
			for (a = 0; a < 9U; a++)
				check_macro_family(
					FAM_ALU_REG, "aluReg", alu_reg_ops[o],
					X86_RDX, X86_RCX, flags,
					KPROG_X86_REG_LANE_AUX(alus[a], 0U, 0U),
					0ULL, X86_REG_NONE);

		/* CMP_IMM family: the immediate differs from the destination,
		 * and TEST clears OF, so the flag write is observable. */
		for (o = 0; o < 2U; o++)
			check_macro_family(
				FAM_CMP_IMM, "cmpImm", cmp_imm_ops[o], X86_RDX,
				X86_REG_NONE, flags,
				KPROG_X86_REG_LANE_AUX(0U, 0U, 0U), 0x1234ULL,
				X86_REG_NONE);

		/* CMP_REG family: distinct source and destination registers. */
		for (o = 0; o < 2U; o++)
			check_macro_family(
				FAM_CMP_REG, "cmpReg", cmp_reg_ops[o], X86_RDX,
				X86_R15, flags,
				KPROG_X86_REG_LANE_AUX(0U, 0U, 0U), 0ULL,
				X86_REG_NONE);

		/* CMP_MEM family: the memory operand is addressed from the
		 * heap-backed destination across every memory width. */
		for (o = 0; o < 4U; o++)
			for (mi = 0; mi < 5U; mi++)
				check_macro_family(
					FAM_CMP_MEM, "cmpMem", cmp_mem_ops[o],
					X86_RAX, X86_RDX, flags,
					KPROG_X86_MEM_AUX(X86_REG_NONE, 0U,
							  mem_widths[mi], 0U),
					0ULL, X86_RAX);
	}

	check_nonmember();

	if (failures != 0) {
		printf("x86 dispatch family route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 dispatch family route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
