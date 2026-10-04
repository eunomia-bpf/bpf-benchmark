/*
 * Host cross-check for the x86 simulator's routing of the operand-register
 * presence test through the generated `KPROG_X86_REG_*` contract (STEP 0104).
 *
 * The simulator's memory read/write paths and `MULX`/`MOVBE`/`XMM0`/`LEA`
 * handlers guarded the base/destination/operand register on a restated
 * `(REG) != X86_REG_NONE` test. They now route that decision through
 * `KPROG_X86_REG_PRESENT` / `KPROG_X86_REG_ABSENT`, so the bodies and the Lean
 * refinement (`X86RegPresence.lean`) share one presence selector. Unlike
 * AArch64 there is no zero register: the only absent number is the `0xff`
 * sentinel `X86_REG_NONE`.
 *
 * This oracle includes the *simulator* header (so the real routed macros are
 * under test), sweeps the full register-number range against an independent
 * `reg != 0xff` test, checks the generated constants against the simulator's
 * own decode, and drives the routed bodies:
 *   - `X86_SIM_L_READ_MEM_VALUE`: a present GPR uses the register's pointer, an
 *     absent number (or a present non-GPR number, whose value is null) uses the
 *     null base — the absolute/immediate path;
 *   - `X86_SIM_L_EXEC_MULX`: the second destination is written only when the
 *     AUX number is present;
 *   - `X86_SIM_L_EXEC_MOVBE_STORE`, `X86_SIM_L_EXEC_LEA`, and the three
 *     `X86_SIM_L_EXEC_ALU_MEM_*` writeback bodies: an absent number contributes
 *     the null base while a present GPR contributes its pointer.
 * Every scenario compares the whole resulting modeled memory and/or register
 * cells against an independent model. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_reg_presence_route_host.c -o /tmp/t_xrpr && /tmp/t_xrpr
 */
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* Backing storage for the register-base and absolute-base scenarios. The
 * absolute form names it through a full-width displacement, so one buffer keeps
 * both readings reachable. */
static __u8 heap[64];
static __u8 exp_heap[64];
static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* Independent width mask, restated from the width codes. */
static __u64 mask_of(__u8 width)
{
	switch (width) {
	case X86_WIDTH_8:
		return 0xffULL;
	case X86_WIDTH_16:
		return 0xffffULL;
	case X86_WIDTH_32:
		return 0xffffffffULL;
	default:
		return ~0ULL;
	}
}
/* Model a width-limited register write performed by the simulator's
 * `WRITE_REG*` contract: widths 8 and 16 byte-patch the low byte(s) of the
 * existing pointer cell, width 32 zero-extends the value, width 64 replaces
 * it outright. */
static void *model_reg_ptr(void *old, __u64 value, __u8 width)
{
	union {
		void *ptr;
		__u8 b[8];
	} u;

	if (width == X86_WIDTH_64)
		return (void *)(__u64)value;
	if (width == X86_WIDTH_32)
		return (void *)(__u64)(__u32)value;
	u.ptr = old;
	u.b[0] = (__u8)value;
	if (width == X86_WIDTH_16)
		u.b[1] = (__u8)(value >> 8);
	return u.ptr;
}


/* Independent little-endian width load/store, written as explicit byte loops so
 * they never lean on the simulator's memory macros. */
static __u64 le_load(const __u8 *b, __u8 width)
{
	__u64 v = 0;
	unsigned i;

	if (!width)
		width = X86_WIDTH_64;
	for (i = 0; i < width; i++)
		v |= (__u64)b[i] << (8 * i);
	return v;
}

static void le_store(__u8 *b, __u64 v, __u8 width)
{
	unsigned i;

	if (!width)
		width = X86_WIDTH_64;
	for (i = 0; i < width; i++)
		b[i] = (__u8)(v >> (8 * i));
}

/* Independent byte reversal over the resolved width. */
static __u64 bswap_model(__u64 v, __u8 width)
{
	__u64 out = 0;
	unsigned i;

	if (!width)
		width = X86_WIDTH_64;
	for (i = 0; i < width; i++)
		out |= (__u64)((__u8)(v >> (8 * i))) << (8 * (width - 1 - i));
	return out;
}

/* Independent restatement of the width-aware immediate rule the ALU-memory
 * immediate form consumes. */
static __u64 imm_rule(__u64 v, __u8 width)
{
	if (width == X86_WIDTH_64 && (v & 0x80000000ULL))
		return (v & 0xffffffffULL) | 0xffffffff00000000ULL;
	return v & 0xffffffffULL;
}

/* Independent ALU result for the operations this oracle drives. */
static __u64 model_alu(__u8 alu, __u64 lhs, __u64 rhs)
{
	switch (alu) {
	case X86_ALU_NOT:
		return ~lhs;
	case X86_ALU_DEC:
		return lhs - 1;
	case X86_ALU_ADD:
		return lhs + rhs;
	case X86_ALU_XOR:
		return lhs ^ rhs;
	case X86_ALU_AND:
		return lhs & rhs;
	case X86_ALU_SUB:
		return lhs - rhs;
	default:
		return lhs;
	}
}

static void fill_patterns(void)
{
	unsigned i;

	for (i = 0; i < sizeof(heap); i++)
		heap[i] = (__u8)(0x30U + i);
}

static void fill_stack(__u8 *stack_bytes)
{
	unsigned i;

	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		stack_bytes[i] = (__u8)(0xa0U + i);
}

/* Capture every GPR pointer cell and tag cell; the `X86_SIM_L_FOR_EACH_GPR`
 * order is register numbers 0..15, so cell index == register number. */
#define SNAP_ONE(REG, NAME)                                                \
	do {                                                               \
		__p[__i] = __x86_##NAME.ptr;                               \
		__t[__i] = __x86_##NAME##_tag;                             \
		__i++;                                                     \
	} while (0);

#define SNAP_ALL(P, T)                                                     \
	do {                                                               \
		void **__p = (P);                                          \
		__u8 *__t = (T);                                           \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(SNAP_ONE)                           \
	} while (0)

/* The routed pointer resolution: a real GPR names its stored pointer, the
 * absent number and any present non-GPR number read null. */
static void check_pointer_resolution(void)
{
	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, heap, X86_SIM_TAG_MAP_PTR);

	cases++;
	if (X86_SIM_L_READ_REG_PTR(X86_RAX) != heap) {
		printf("MISMATCH reg_ptr rax got=%p want=%p\n",
		       X86_SIM_L_READ_REG_PTR(X86_RAX), (void *)heap);
		failures++;
	}
	cases++;
	if (X86_SIM_L_REG_TAG(X86_RAX) != X86_SIM_TAG_MAP_PTR) {
		printf("MISMATCH reg_tag rax got=%u want=%u\n",
		       X86_SIM_L_REG_TAG(X86_RAX), X86_SIM_TAG_MAP_PTR);
		failures++;
	}
	cases++;
	if (X86_SIM_L_READ_REG_PTR(X86_REG_NONE) != (void *)0) {
		printf("MISMATCH reg_ptr none not null\n");
		failures++;
	}
	/* A present number that names no GPR still reads null: presence is a
	 * decode test, not a pointer-availability test. */
	cases++;
	if (X86_SIM_L_READ_REG_PTR(0x10U) != (void *)0) {
		printf("MISMATCH reg_ptr non-gpr not null\n");
		failures++;
	}
	cases++;
	if (X86_SIM_L_REG_TAG(X86_REG_NONE) != X86_SIM_TAG_SCALAR) {
		printf("MISMATCH reg_tag none got=%u\n",
		       X86_SIM_L_REG_TAG(X86_REG_NONE));
		failures++;
	}
}

/*
 * Memory-read scenario. `src` selects the route: a real GPR other than RSP
 * contributes its pointer (seeded to `heap`), the absent number and any
 * present non-GPR number contribute the null base, and RSP takes the stack arm.
 * The read value is compared against an independent little-endian load.
 */
static void check_read(const char *what, __u8 src, __u64 imm, __u8 width)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
	__u8 w = width ? width : X86_WIDTH_64;
	__u64 got, want;
	__u8 *base;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	fill_stack(__x86_stack_mem.b);

	if (src <= X86_R15 && src != X86_RSP)
		X86_SIM_L_WRITE_REG_PTR_TAG(src, heap, X86_SIM_TAG_SCALAR);

	if (src == X86_RSP) {
		/* RSP keeps a null base, so the effective address is just the
		 * displacement. */
		__u32 idx = (__u32)((__s64)imm +
				    (__s64)X86_SIM_STACK_BYTES);
		want = le_load(&__x86_stack_mem.b[idx], w);
	} else {
		base = (src != X86_REG_NONE && src <= X86_R15)
			       ? heap : (__u8 *)0;
		want = le_load(base + (__s64)imm, w);
	}

	got = X86_SIM_L_READ_MEM_VALUE(src, aux, imm, width, 0);

	cases++;
	if (got != want) {
		printf("MISMATCH %s src=%u width=%u got=0x%llx want=0x%llx\n",
		       what, src, width, (unsigned long long)got,
		       (unsigned long long)want);
		failures++;
	}
}

/*
 * MULX scenario. The low half always writes `dst`; the high half writes the
 * AUX register only when it is present. Whole register-file and tag state are
 * compared against an independent cross-product.
 */
static void check_mulx(const char *what, __u8 dst, __u8 src, __u8 aux,
		       __u8 flags, __u64 lhs, __u64 rhs)
{
	__u8 w = flags ? flags : X86_WIDTH_64;
	void *bp[16], *ap[16];
	__u8 bt[16], at[16];
	__u64 low, high;
	unsigned __int128 full;
	unsigned j;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	X86_SIM_L_WRITE_REG_WIDTH(X86_RDX, lhs, X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_WIDTH(src, rhs, X86_WIDTH_64);
	X86_SIM_L_WRITE_REG_WIDTH(dst, 0x5a5a5a5a5a5a5a5aULL, X86_WIDTH_64);
	if (aux != X86_REG_NONE)
		X86_SIM_L_WRITE_REG_WIDTH(aux, 0xa5a5a5a5a5a5a5a5ULL,
					  X86_WIDTH_64);

	SNAP_ALL(bp, bt);
	X86_SIM_L_EXEC_MULX(dst, src, aux, flags);
	SNAP_ALL(ap, at);

	if (w == X86_WIDTH_32) {
		__u64 product = (__u64)(__u32)lhs * (__u64)(__u32)rhs;
		low = (__u32)product;
		high = (__u32)(product >> 32);
	} else {
		full = (unsigned __int128)lhs * (unsigned __int128)rhs;
		low = (__u64)full;
		high = (__u64)(full >> 64);
	}

	for (j = 0; j < 16U; j++) {
		void *ep = bp[j];
		__u8 et = bt[j];

		if (aux != X86_REG_NONE && j == aux) {
			ep = model_reg_ptr(bp[j], high, w);
			et = X86_SIM_TAG_SCALAR;
		} else if (j == dst) {
			ep = model_reg_ptr(bp[j], low, w);
			et = X86_SIM_TAG_SCALAR;
		}
		if (ap[j] != ep || at[j] != et) {
			printf("MISMATCH %s cell=%u ptr=%p want=%p tag=%u "
			       "want=%u (dst=%u aux=%u width=%u)\n", what, j,
			       ap[j], ep, (unsigned)at[j], (unsigned)et, dst,
			       aux, w);
			failures++;
		}
	}
	cases++;
}

/*
 * MOVBE-store scenario. `dst` selects the route and arm: RSP -> stack, a real
 * GPR -> its pointer, the absent number/non-GPR -> null base. Whole modeled
 * memory and stack are compared against an independent byte model.
 */
static void check_movbe_store(const char *what, __u8 dst, __u8 src, __u8 flags,
			      __u64 imm, __u64 src_val)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U);
	__u8 w = flags ? flags : X86_WIDTH_64;
	__s64 disp = (__s64)imm;
	__u64 value = bswap_model(src_val, w);
	__u8 *base;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	fill_stack(__x86_stack_mem.b);

	X86_SIM_L_WRITE_REG_WIDTH(src, src_val, X86_WIDTH_64);
	base = (__u8 *)0;
	if (dst <= X86_R15 && dst != X86_RSP) {
		X86_SIM_L_WRITE_REG_PTR_TAG(dst, heap, X86_SIM_TAG_SCALAR);
		base = heap;
	}

	for (i = 0; i < sizeof(heap); i++)
		exp_heap[i] = heap[i];
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp_stack[i] = __x86_stack_mem.b[i];
	if (dst == X86_RSP) {
		__u32 idx = (__u32)((__s64)(long)base + disp +
				    (__s64)X86_SIM_STACK_BYTES);
		le_store(&exp_stack[idx], value, w);
	} else {
		le_store(&exp_heap[(base + disp) - heap], value, w);
	}

	X86_SIM_L_EXEC_MOVBE_STORE(dst, src, flags, aux, imm);

	cases++;
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s heap[%u]=0x%02x want=0x%02x "
			       "(dst=%u width=%u disp=%lld)\n", what, i,
			       heap[i], exp_heap[i], dst, w, (long long)disp);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp_stack[i]) {
			printf("MISMATCH %s stack[%u]=0x%02x want=0x%02x "
			       "(dst=%u width=%u disp=%lld)\n", what, i,
			       __x86_stack_mem.b[i], exp_stack[i], dst, w,
			       (long long)disp);
			failures++;
			return;
		}
	}
}

/*
 * LEA scenario. `src` selects the route: the absent number with the rodata AUX
 * takes the raw-immediate arm, RSP takes the stack arm, a real GPR contributes
 * its pointer, and the absent number with any other AUX contributes the null
 * base. Only `dst`'s cell and tag change.
 */
static void check_lea(const char *what, __u8 dst, __u8 src, __u8 flags,
		      __u32 aux, __u64 imm)
{
	__u8 w = flags ? flags : X86_WIDTH_64;
	__s64 off = (__s64)imm;
	void *bp[16], *ap[16];
	__u8 bt[16], at[16];
	void *dst_val;
	__u8 dst_tag;
	__u8 *src_ptr;
	unsigned j;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	if (src <= X86_R15 && src != X86_RSP)
		X86_SIM_L_WRITE_REG_PTR_TAG(src, heap, X86_SIM_TAG_SCALAR);
	/* Seed the destination so an unwritten cell is observable. */
	X86_SIM_L_WRITE_REG_PTR_TAG(dst, (void *)0x11U, X86_SIM_TAG_ABI);

	src_ptr = (src != X86_REG_NONE && src <= X86_R15 && src != X86_RSP)
			  ? heap : (__u8 *)0;

	if (w == X86_WIDTH_64 && src == X86_REG_NONE &&
	    aux == X86_LEA_AUX_RODATA) {
		dst_val = (void *)(long)imm;
		dst_tag = X86_SIM_TAG_SCALAR;
	} else if (w == X86_WIDTH_64) {
		if (src == X86_RSP) {
			dst_val = &__x86_stack_mem.b[(__u32)(
				off + (__s64)X86_SIM_STACK_BYTES)];
			dst_tag = X86_SIM_TAG_STACK;
		} else {
			dst_val = (void *)(src_ptr + off);
			dst_tag = X86_SIM_TAG_SCALAR;
		}
	} else {
		dst_val = model_reg_ptr(bp[dst], (__u64)(long)(src_ptr + off),
				       w);
		dst_tag = X86_SIM_TAG_SCALAR;
	}

	SNAP_ALL(bp, bt);
	X86_SIM_L_EXEC_LEA(dst, src, flags, aux, imm);
	SNAP_ALL(ap, at);

	for (j = 0; j < 16U; j++) {
		void *ep = bp[j];
		__u8 et = bt[j];

		if (j == dst) {
			ep = dst_val;
			et = dst_tag;
		}
		if (ap[j] != ep || at[j] != et) {
			printf("MISMATCH %s cell=%u ptr=%p want=%p tag=%u "
			       "want=%u (dst=%u src=%u width=%u)\n", what, j,
			       ap[j], ep, (unsigned)at[j], (unsigned)et, dst,
			       src, w);
			failures++;
		}
	}
	cases++;
}

enum { ALU_KIND_UNARY, ALU_KIND_IMM, ALU_KIND_REG };

/*
 * ALU-memory writeback scenario. `dst` selects the route and arm exactly as the
 * other bodies; the value read from the destination's effective address is
 * combined with a per-kind right operand and written back by the real body.
 * Whole modeled memory and stack are compared against an independent model.
 */
static void check_alu_mem(const char *what, int kind, __u8 dst, __u8 src,
			  __u8 flags, __u8 alu, __u64 imm, __u64 src_val)
{
	__u32 aux = KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, alu);
	__u8 w = flags ? flags : X86_WIDTH_64;
	__s64 off;
	__u8 *base = (__u8 *)0;
	__u64 lhs, rhs, result;
	unsigned i;

	X86_SIM_L_DECLARE_STATE();
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_cf;
	(void)__x86_zf;
	(void)__x86_sf;
	(void)__x86_of;
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	fill_patterns();
	fill_stack(__x86_stack_mem.b);

	/* Both the read and the writeback use the same displacement slice: the
	 * immediate form takes the sign-extended high half, the other two the
	 * whole field. */
	off = (kind == ALU_KIND_IMM) ? (__s64)(__s32)(imm >> 32)
				     : (__s64)imm;

	if (dst <= X86_R15 && dst != X86_RSP) {
		X86_SIM_L_WRITE_REG_PTR_TAG(dst, heap, X86_SIM_TAG_SCALAR);
		base = heap;
	}
	if (kind == ALU_KIND_REG)
		X86_SIM_L_WRITE_REG_WIDTH(src, src_val, X86_WIDTH_64);

	if (dst == X86_RSP) {
		__u32 ridx = (__u32)(off + (__s64)X86_SIM_STACK_BYTES);
		lhs = le_load(&__x86_stack_mem.b[ridx], w);
	} else {
		lhs = le_load(base + off, w);
	}
	if (kind == ALU_KIND_UNARY)
		rhs = 1;
	else if (kind == ALU_KIND_IMM)
		rhs = imm_rule(imm, w);
	else
		rhs = src_val;
	result = model_alu(alu, lhs, rhs) & mask_of(w);

	for (i = 0; i < sizeof(heap); i++)
		exp_heap[i] = heap[i];
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		exp_stack[i] = __x86_stack_mem.b[i];
	if (dst == X86_RSP) {
		__u32 idx = (__u32)((__s64)(long)base + off +
				    (__s64)X86_SIM_STACK_BYTES);
		le_store(&exp_stack[idx], result, w);
	} else {
		le_store(&exp_heap[(base + off) - heap], result, w);
	}

	if (kind == ALU_KIND_UNARY)
		X86_SIM_L_EXEC_ALU_MEM_UNARY(dst, flags, aux, imm);
	else if (kind == ALU_KIND_IMM)
		X86_SIM_L_EXEC_ALU_MEM_IMM(dst, flags, aux, imm);
	else
		X86_SIM_L_EXEC_ALU_MEM_REG(dst, src, flags, aux, imm);

	cases++;
	for (i = 0; i < sizeof(heap); i++) {
		if (heap[i] != exp_heap[i]) {
			printf("MISMATCH %s heap[%u]=0x%02x want=0x%02x "
			       "(dst=%u kind=%d width=%u alu=%u)\n", what, i,
			       heap[i], exp_heap[i], dst, kind, w, alu);
			failures++;
			return;
		}
	}
	cases++;
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		if (__x86_stack_mem.b[i] != exp_stack[i]) {
			printf("MISMATCH %s stack[%u]=0x%02x want=0x%02x "
			       "(dst=%u kind=%d width=%u alu=%u)\n", what, i,
			       __x86_stack_mem.b[i], exp_stack[i], dst, kind,
			       w, alu);
			failures++;
			return;
		}
	}
}

int main(void)
{
	static const __u8 widths[] = { X86_WIDTH_8, X86_WIDTH_16,
				       X86_WIDTH_32, X86_WIDTH_64 };
	__u32 byte;
	unsigned i;

	/* Full register-number sweep against the independent literal test. */
	for (byte = 0; byte <= 0xffU; byte++) {
		__u8 reg = (__u8)byte;
		__u8 want = reg != 0xffU ? 1U : 0U;
		__u8 want_arm = reg == 0xffU ? KPROG_X86_REG_ARM_ABSENT
					     : KPROG_X86_REG_ARM_PRESENT;

		cases++;
		if (KPROG_X86_REG_PRESENT(reg) != want) {
			printf("MISMATCH present reg=%u got=%u want=%u\n", byte,
			       KPROG_X86_REG_PRESENT(reg), want);
			failures++;
		}
		cases++;
		if (KPROG_X86_REG_ABSENT(reg) != (1U - want)) {
			printf("MISMATCH absent reg=%u\n", byte);
			failures++;
		}
		cases++;
		if (KPROG_X86_REG_ARM(reg) != want_arm) {
			printf("MISMATCH arm reg=%u\n", byte);
			failures++;
		}
	}

	/* The generated constants must line up with the simulator's decode. */
	cases++;
	if (KPROG_X86_REG_SENTINEL != X86_REG_NONE ||
	    KPROG_X86_REG_SENTINEL != KPROG_X86_MEM_INDEX_SENTINEL) {
		printf("MISMATCH sentinel %u vs none %u vs index %u\n",
		       (unsigned)KPROG_X86_REG_SENTINEL,
		       (unsigned)X86_REG_NONE,
		       (unsigned)KPROG_X86_MEM_INDEX_SENTINEL);
		failures++;
	}
	cases++;
	if (KPROG_X86_REG_ARM_PRESENT != KPROG_X86_MEM_INDEX_ARM_PRESENT ||
	    KPROG_X86_REG_ARM_ABSENT != KPROG_X86_MEM_INDEX_ARM_ABSENT) {
		printf("MISMATCH arm codes disagree with the index contract\n");
		failures++;
	}
	cases++;
	if (KPROG_X86_REG_PRESENT(X86_REG_NONE) != 0U ||
	    KPROG_X86_REG_ABSENT(X86_REG_NONE) != 1U) {
		printf("MISMATCH sentinel classification\n");
		failures++;
	}

	check_pointer_resolution();

	/* ---- memory read: present GPR vs. absent/non-GPR vs. stack ---- */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		check_read("read/reg", X86_RAX, 0, widths[i]);
		check_read("read/reg/disp", X86_RBX, 8, widths[i]);
		check_read("read/none",
			   X86_REG_NONE, (__u64)(unsigned long)heap + 8,
			   widths[i]);
		check_read("read/non-gpr",
			   0x10U, (__u64)(unsigned long)heap + 16, widths[i]);
	}
	check_read("read/r15", X86_R15, 32, X86_WIDTH_64);
	check_read("read/stack", X86_RSP, (__u64)-8, X86_WIDTH_64);
	check_read("read/stack/w32", X86_RSP, (__u64)-8, X86_WIDTH_32);

	/* ---- MULX: second destination gated on AUX presence ---- */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		check_mulx("mulx/aux", X86_R8, X86_R9, X86_R10, widths[i],
			   0x0123456789abcdefULL, 0xfedcba9876543210ULL);
		check_mulx("mulx/aux-wide", X86_R8, X86_R11, X86_R12,
			   widths[i], 0xffffffffffffffffULL,
			   0xffffffffffffffffULL);
	}
	check_mulx("mulx/aux-none", X86_R8, X86_R9, X86_REG_NONE,
		   X86_WIDTH_64, 0x1122334455667788ULL,
		   0x99aabbccddeeff00ULL);
	check_mulx("mulx/aux-non-gpr", X86_R8, X86_R9, 0x20U, X86_WIDTH_64,
		   0xdeadbeefcafef00dULL, 0x123456789abcdef0ULL);
	check_mulx("mulx/width-default", X86_R13, X86_R14, X86_R15, 0,
		   0x00000000ffffffffULL, 0x0000000100000001ULL);

	/* ---- MOVBE store: pointer base vs. null base vs. stack ---- */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		check_movbe_store("movbe/reg", X86_RAX, X86_RCX, widths[i],
				  8, 0x0123456789abcdefULL);
		check_movbe_store("movbe/none", X86_REG_NONE, X86_RCX,
				  widths[i],
				  (__u64)(unsigned long)heap + 24,
				  0xf0f1f2f3f4f5f6f7ULL);
	}
	check_movbe_store("movbe/stack", X86_RSP, X86_RCX, X86_WIDTH_32,
			  (__u64)-8, 0x8899aabbccddeeffULL);
	check_movbe_store("movbe/width-default", X86_RAX, X86_RCX, 0, 0,
			  0x0011223344556677ULL);

	/* ---- LEA: raw immediate vs. pointer vs. null base vs. stack ---- */
	check_lea("lea/rodata-none", X86_RAX, X86_REG_NONE, X86_WIDTH_64,
		  X86_LEA_AUX_RODATA, 0x12345678UL);
	check_lea("lea/reg", X86_RAX, X86_RBX, X86_WIDTH_64,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 8);
	check_lea("lea/none", X86_RAX, X86_REG_NONE, X86_WIDTH_64,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U),
		  (__u64)(unsigned long)heap + 40);
	check_lea("lea/rsp", X86_RAX, X86_RSP, X86_WIDTH_64,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), (__u64)-8);
	check_lea("lea/w32", X86_RAX, X86_RBX, X86_WIDTH_32,
		  KPROG_X86_MEM_AUX(X86_REG_NONE, 0U, 0U, 0U), 4);

	/* ---- ALU memory: unary / immediate / register writeback ---- */
	for (i = 0; i < sizeof(widths) / sizeof(widths[0]); i++) {
		check_alu_mem("alu/unary-not", ALU_KIND_UNARY, X86_RAX, 0,
			      widths[i], X86_ALU_NOT, 0, 0);
		check_alu_mem("alu/unary-dec", ALU_KIND_UNARY, X86_RBX, 0,
			      widths[i], X86_ALU_DEC, 8, 0);
		check_alu_mem("alu/unary-none", ALU_KIND_UNARY, X86_REG_NONE, 0,
			      widths[i], X86_ALU_NOT,
			      (__u64)(unsigned long)heap + 8, 0);
		check_alu_mem("alu/imm-add", ALU_KIND_IMM, X86_RAX, 0,
			      widths[i], X86_ALU_ADD,
			      0x0000000000000f0fULL, 0);
		check_alu_mem("alu/imm-xor", ALU_KIND_IMM, X86_RCX, 0,
			      widths[i], X86_ALU_XOR,
			      0x0000000800001234ULL, 0);
		check_alu_mem("alu/reg-and", ALU_KIND_REG, X86_RAX, X86_RDX,
			      widths[i], X86_ALU_AND, 0, 0x0f0f0f0f0f0f0f0fULL);
		check_alu_mem("alu/reg-sub-none", ALU_KIND_REG, X86_REG_NONE,
			      X86_RDX, widths[i], X86_ALU_SUB,
			      (__u64)(unsigned long)heap + 8,
			      0x0000000000000001ULL);
	}
	check_alu_mem("alu/unary-stack", ALU_KIND_UNARY, X86_RSP, 0,
		      X86_WIDTH_64, X86_ALU_NOT, (__u64)-8, 0);
	check_alu_mem("alu/imm-stack", ALU_KIND_IMM, X86_RSP, 0, X86_WIDTH_32,
		      X86_ALU_ADD, 0xfffffff800000004ULL, 0);

	if (failures != 0) {
		printf("x86 reg presence route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 reg presence route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
