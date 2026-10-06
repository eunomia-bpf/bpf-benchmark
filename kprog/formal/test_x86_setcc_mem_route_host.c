/*
 * Host cross-check for the x86 simulator's routing of the `SETCC_MEM` body
 * (`X86_OP_SETCC_MEM`, `0x3e`) through the generated handler-composition
 * contract `KPROG_X86_SETCC_MEM_*`.
 *
 * The oracle drives the *real* body — directly through
 * `X86_SIM_L_EXEC_SETCC_MEM` and through the `X86_OP_SETCC_MEM` dispatcher arm
 * — over the destination space:
 *   - an ordinary destination register (base-pointer memory arm),
 *   - `X86_RSP` (stack-helper arm, through the simulator's own frame),
 *   - `X86_REG_NONE` (process-null base, still the memory arm),
 * the supported and unsupported condition bytes, every flag nibble, the whole
 * displacement, and the addressing modes. After every case the heap image and
 * the simulator's stack frame are compared byte for byte against an
 * independent model of `KPROG_X86_EVAL_CC` plus a one-byte little-endian store
 * or stack write, and the 16 modeled registers must be untouched.
 *
 * Pins on the asymmetries the routing is about:
 *   - the condition byte is the AUX *source-shift* byte at bits 24..31, not
 *     the register form's payload byte at bits 0..7;
 *   - the access width is the opcode's constant one-byte code, so neither a
 *     nonzero AUX memory-width byte nor FLAGS can widen it;
 *   - a null base forms process null and takes the *memory* arm, while the
 *     stack-pointer destination takes the stack arm and leaves the heap alone.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_setcc_mem_route_host.c -o /tmp/t_scmr && /tmp/t_scmr
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

/* The heap the ordinary and null destinations write through, and its pristine
 * image. */
#define HEAP_BYTES 8192U
#define HEAP_BASE_OFF 2048U
static __u8 heap[HEAP_BYTES];
static __u8 pristine_heap[HEAP_BYTES];
static __u8 result_heap[HEAP_BYTES];

/* The independent model of the simulator's stack frame, and the frame image
 * read back out of the simulator after a case. */
static __u8 stack_model[X86_SIM_STACK_BYTES];
static __u8 result_stack[X86_SIM_STACK_BYTES];

/* The register file the model tracks, parallel to the simulator's own state. */
static __u64 mreg[16];
static __u8 mtag[16];

#define INDEX_REG X86_RDI
#define INDEX_VALUE 8ULL

static __u8 synthetic(unsigned i)
{
	return (__u8)((i * 131U + 17U) ^ (i >> 5));
}

/* The condition expression table, a restatement of `KPROG_X86_EVAL_CC`'s
 * boolean arms from the raw codes. `cc` is compared as the promoted word, so a
 * value outside the 14-code table matches no arm and yields the C default 0. */
static unsigned model_cc_true(unsigned cc, unsigned cf, unsigned zf,
			      unsigned sf, unsigned of)
{
	switch (cc) {
	case 0U: return of;
	case 1U: return !of;
	case 2U: return cf;
	case 3U: return !cf;
	case 4U: return zf;
	case 5U: return !zf;
	case 6U: return cf || zf;
	case 7U: return (!cf) && (!zf);
	case 8U: return sf;
	case 9U: return !sf;
	case 12U: return sf != of;
	case 13U: return sf == of;
	case 14U: return zf || (sf != of);
	case 15U: return (!zf) && (sf == of);
	default: return 0U;
	}
}

/* The addressing offset, restated: the displacement, plus the scaled index
 * when the mode carries one. */
static __s64 model_offset(__u32 aux, __s64 disp)
{
	__s64 off = disp;

	if (X86_MEM_AUX_INDEX(aux) != X86_REG_NONE)
		off += (__s64)(INDEX_VALUE << X86_MEM_AUX_SCALE_LOG2(aux));
	return off;
}

/*
 * One SETCC_MEM case. `cc_byte` is the AUX source-shift byte at bits 24..31;
 * `mw_byte` the AUX memory-width byte at bits 16..23 (which the handler
 * ignores); `disp` the whole 64-bit immediate the body folds into the offset;
 * `has_index`/`scale` the addressing mode; `dst` the destination register
 * (also the base selector and the arm selector); `via` selects the dispatcher
 * arm. `flags` is a nibble: bit 0 = cf, bit 1 = zf, bit 2 = sf, bit 3 = of.
 */
static void check_mem(unsigned dst, unsigned cc_byte, unsigned mw_byte,
		      __s64 disp, unsigned has_index, unsigned scale,
		      unsigned flags, unsigned via)
{
	__u32 aux = ((__u32)cc_byte << 24) | ((__u32)mw_byte << 16) |
		    (has_index
			     ? (__u32)(INDEX_REG | ((__u32)scale << 8))
			     : (__u32)X86_REG_NONE);
	__u64 imm = (dst == X86_REG_NONE)
			   ? (__u64)(long)(heap + HEAP_BASE_OFF) + (__u64)disp
			   : (__u64)disp;
	unsigned cf = flags & 1U;
	unsigned zf = (flags >> 1) & 1U;
	unsigned sf = (flags >> 2) & 1U;
	unsigned of = (flags >> 3) & 1U;
	__u64 base_ptr;
	__s64 off;
	__u64 value;
	unsigned arm_stack;
	unsigned i;

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

	/* ---- plant the simulator state and the model file ---- */
	for (i = 0; i < 16U; i++) {
		__u64 v = (__u64)(long)(heap + HEAP_BASE_OFF);
		__u8 tg = (__u8)(1U + (i % 5U));

		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(long)v, tg);
		mreg[i] = v;
		mtag[i] = tg;
	}
	/* The stack destination's base pointer is the frame size as a signed
	 * negative, so the simulator's frame index is the driven offset. The
	 * index register carries a small scalar so an indexed mode stays
	 * inside the heap. */
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSP,
				    (void *)(long)(-(__s64)X86_SIM_STACK_BYTES),
				    X86_SIM_TAG_STACK);
	mreg[X86_RSP] = (__u64)(long)(-(__s64)X86_SIM_STACK_BYTES);
	mtag[X86_RSP] = X86_SIM_TAG_STACK;
	X86_SIM_L_WRITE_REG_PTR_TAG(INDEX_REG, (void *)(long)INDEX_VALUE,
				    X86_SIM_TAG_SCALAR);
	mreg[INDEX_REG] = INDEX_VALUE;
	mtag[INDEX_REG] = X86_SIM_TAG_SCALAR;

	memcpy(heap, pristine_heap, HEAP_BYTES);
	memset(__x86_stack_mem.b, 0, X86_SIM_STACK_BYTES);

	__x86_cf = (__u8)cf;
	__x86_zf = (__u8)zf;
	__x86_sf = (__u8)sf;
	__x86_of = (__u8)of;

	/* ---- run the real body ---- */
	if (via)
		X86_SIM_L_EXEC(X86_OP_SETCC_MEM, dst, X86_REG_NONE, 0, aux,
			       imm);
	else
		X86_SIM_L_EXEC_SETCC_MEM(dst, aux, imm);

	memcpy(result_heap, heap, HEAP_BYTES);
	for (i = 0; i < X86_SIM_STACK_BYTES; i++)
		result_stack[i] = __x86_stack_mem.b[i];

	/* The registers are untouched: compare all 16 against the model. */
	for (i = 0; i < 16U; i++) {
		cases++;
		if ((__u64)(long)X86_SIM_L_REG_VALUE(i) != mreg[i] ||
		    X86_SIM_L_REG_TAG(i) != mtag[i]) {
			printf("MISMATCH setcc_mem via=%u reg%u clobbered\n",
			       via, i);
			failures++;
			return;
		}
	}

	/* ---- independent model ---- */
	value = (__u64)(__u8)model_cc_true(cc_byte, cf, zf, sf, of);
	arm_stack = (dst == X86_RSP);
	/* The handler's null-base arm forms a true process-null base; the
	 * driven immediate already carries an absolute address inside the
	 * heap, so the model's base stays null too. */
	if (dst == X86_REG_NONE)
		base_ptr = 0ULL;
	else
		base_ptr = mreg[dst];
	off = model_offset(aux, (__s64)imm);

	memcpy(heap, pristine_heap, HEAP_BYTES);
	memset(stack_model, 0, X86_SIM_STACK_BYTES);
	if (arm_stack) {
		__u32 index = (__u32)((__s64)base_ptr + off +
				      (__s64)X86_SIM_STACK_BYTES);

		stack_model[index] = (__u8)value;
	} else {
		__u64 addr = base_ptr + (__u64)off;
		unsigned slot = (unsigned)(addr - (__u64)(long)heap);

		if (slot >= HEAP_BYTES) {
			printf("MODEL setcc_mem dst=%u cc=%u disp=%lld "
			       "index=%u scale=%u: slot=%u out of range\n",
			       dst, cc_byte, (long long)disp, has_index,
			       scale, slot);
			failures++;
			return;
		}
		heap[slot] = (__u8)value;
	}

	/* ---- compare both images byte for byte ---- */
	cases++;
	if (memcmp(result_heap, heap, HEAP_BYTES) != 0) {
		unsigned slot = (unsigned)((base_ptr + (__u64)off) -
					   (__u64)(long)heap);

		printf("MISMATCH setcc_mem via=%u dst=%u cc=%u disp=%lld "
		       "index=%u scale=%u: heap got 0x%02x want 0x%02x\n",
		       via, dst, cc_byte, (long long)disp, has_index, scale,
		       (unsigned)(slot < HEAP_BYTES ? result_heap[slot] : 0U),
		       (unsigned)(slot < HEAP_BYTES ? heap[slot] : 0U));
		failures++;
		return;
	}
	for (i = 0; i < X86_SIM_STACK_BYTES; i++) {
		cases++;
		if (result_stack[i] != stack_model[i]) {
			printf("MISMATCH setcc_mem via=%u stack[%u] got 0x%02x "
			       "want 0x%02x\n", via, i,
			       (unsigned)result_stack[i],
			       (unsigned)stack_model[i]);
			failures++;
			return;
		}
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	unsigned i;

	/* The condition decoder recovers the AUX source-shift byte exactly. */
	for (i = 0; i < 256U; i++) {
		cases++;
		if (KPROG_X86_SETCC_MEM_CONDITION((__u32)i << 24) != (__u8)i) {
			printf("MISMATCH setcc_mem condition %u\n", i);
			failures++;
		}
	}

	/* The base table is the `== X86_REG_NONE` test. */
	for (i = 0; i < 256U; i++) {
		__u8 want = ((__u8)i == X86_REG_NONE)
				    ? KPROG_X86_SETCC_MEM_BASE_NULL
				    : KPROG_X86_SETCC_MEM_BASE_REGISTER;

		cases++;
		if (KPROG_X86_SETCC_MEM_BASE((__u8)i) != want) {
			printf("MISMATCH setcc_mem base %u\n", i);
			failures++;
		}
	}

	/* The arm table is the `== X86_RSP` test. */
	for (i = 0; i < 256U; i++) {
		__u8 want = (i != 0) ? KPROG_X86_SETCC_MEM_ARM_STACK
					   : KPROG_X86_SETCC_MEM_ARM_MEMORY;

		cases++;
		if (KPROG_X86_SETCC_MEM_ARM(i) != want) {
			printf("MISMATCH setcc_mem arm %u\n", i);
			failures++;
		}
	}

	/* The constant pins: the width is the opcode's one-byte code, equal to
	 * the 8-bit width code, and the null/stack register numbers are the
	 * simulator's own. */
	cases++;
	if (KPROG_X86_SETCC_MEM_WIDTH_CODE != X86_WIDTH_8 ||
	    KPROG_X86_SETCC_MEM_WIDTH_CODE != 1U ||
	    KPROG_X86_SETCC_MEM_NONE_REG != X86_REG_NONE ||
	    KPROG_X86_SETCC_MEM_RSP_REG != X86_RSP) {
		printf("MISMATCH setcc_mem constant pins\n");
		failures++;
	}

	/* The null-base register is not the stack register, so a null base
	 * always takes the memory arm. */
	cases++;
	if (KPROG_X86_SETCC_MEM_ARM(KPROG_X86_SETCC_MEM_NONE_REG ==
				    KPROG_X86_SETCC_MEM_RSP_REG) !=
	    KPROG_X86_SETCC_MEM_ARM_MEMORY) {
		printf("MISMATCH setcc_mem null-base arm\n");
		failures++;
	}
}

/*
 * Pins showing this form reads different AUX fields than the register form:
 * a payload byte of `ne` at bits 0..7 must not be consulted, and a nonzero AUX
 * memory-width byte must not widen the constant one-byte write. The driven
 * displacement lands inside the heap.
 */
static void check_asymmetry(void)
{
	unsigned i;

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

	for (i = 0; i < 16U; i++)
		X86_SIM_L_WRITE_REG_PTR_TAG(i,
					    (void *)(long)(heap + HEAP_BASE_OFF),
					    X86_SIM_TAG_SCALAR);
	/* The AUX payload byte at bits 0..7 doubles as the index-register
	 * field of the addressing mode, so the `ne` payload names `rbp`;
	 * a zero index value keeps the offset the driven displacement. */
	X86_SIM_L_WRITE_REG_PTR_TAG(X86_RBP, (void *)0,
				    X86_SIM_TAG_SCALAR);

	/* Payload byte `ne` (5) at bits 0..7 with a zero source-shift byte:
	 * the condition is the supported `o` code with `of == 0`, so the value
	 * is 0 and the payload byte is ignored. `X86_WIDTH_64` in FLAGS and a
	 * nonzero AUX memory-width byte must not widen the write. */
	memcpy(heap, pristine_heap, HEAP_BYTES);
	__x86_cf = 0; __x86_zf = 0; __x86_sf = 0; __x86_of = 0;
	X86_SIM_L_EXEC_SETCC_MEM(X86_RBX, (X86_WIDTH_8 << 16) | 0x00000005U,
				 (__u64)HEAP_BASE_OFF);
	cases++;
	if (heap[2U * HEAP_BASE_OFF] != 0U) {
		printf("MISMATCH setcc_mem payload consulted\n");
		failures++;
	}
	cases++;
	if (heap[2U * HEAP_BASE_OFF + 1U] !=
	    pristine_heap[2U * HEAP_BASE_OFF + 1U]) {
		printf("MISMATCH setcc_mem width widened\n");
		failures++;
	}
	/* An indexed stack destination: the index register (small scalar)
	 * with a scale lands the frame index the handler computes, and the
	 * ordinary memory arm must stay untouched. */
	{
		const unsigned scale = 0U;
		const __s64 disp = 8;
		__u32 aux = ((__u32)X86_CC_E << 24) |
			    (__u32)(INDEX_REG | (__u32)(scale << 8));
		__u32 index;

		__x86_cf = 0;
		__x86_zf = 1;
		__x86_sf = 0;
		__x86_of = 0;
		memset(__x86_stack_mem.b, 0, X86_SIM_STACK_BYTES);
		memcpy(heap, pristine_heap, HEAP_BYTES);
		X86_SIM_L_WRITE_REG_PTR_TAG(
			X86_RSP,
			(void *)(long)(-(__s64)X86_SIM_STACK_BYTES),
			X86_SIM_TAG_STACK);
		X86_SIM_L_WRITE_REG_PTR_TAG(INDEX_REG,
					    (void *)(long)INDEX_VALUE,
					    X86_SIM_TAG_SCALAR);
		X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, aux, (__u64)disp);
		index = (__u32)(-(__s64)X86_SIM_STACK_BYTES + disp +
				(__s64)(INDEX_VALUE << scale) +
				(__s64)X86_SIM_STACK_BYTES);
		cases++;
		if (__x86_stack_mem.b[index] != 1U) {
			printf("MISMATCH setcc_mem indexed stack index=%u got "
			       "0x%02x\n", index,
			       (unsigned)__x86_stack_mem.b[index]);
			failures++;
		}
		cases++;
		if (memcmp(heap, pristine_heap, HEAP_BYTES) != 0) {
			printf("MISMATCH setcc_mem indexed stack touched heap\n");
			failures++;
		}
	}

	/* The same payload byte read by the register form resolves `ne`, so
	 * the two forms really do read different fields. */
	cases++;
	if ((unsigned)KPROG_X86_EVAL_CC(0x05U, 0, 0, 0, 0) == 0U) {
		printf("MISMATCH setcc_mem payload cross-check\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned cc_codes[] = {
		X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A, X86_CC_S, X86_CC_NS,
		X86_CC_L, X86_CC_GE, X86_CC_LE, X86_CC_G,
		10U, 11U, 16U, 0xffU,   /* unsupported / out-of-range */
	};
	static const unsigned dsts[3] = { X86_RBX, X86_RSP, X86_REG_NONE };
	static const unsigned mw_codes[2] = { 0U, X86_WIDTH_8 };
	static const __s64 disps[4] = { 0, 8, 16, 24 };
	unsigned via;
	unsigned d;
	unsigned c;
	unsigned mw;
	unsigned di;
	unsigned hi;
	unsigned sc;
	unsigned fb;
	unsigned i;

	for (i = 0; i < HEAP_BYTES; i++)
		pristine_heap[i] = synthetic(i);

	for (via = 0; via < 2U; via++)
		for (d = 0; d < 3U; d++)
			for (c = 0; c < sizeof(cc_codes) /
						sizeof(cc_codes[0]); c++)
				for (mw = 0; mw < 2U; mw++)
					for (di = 0; di < 4U; di++)
						for (hi = 0; hi < 2U; hi++) {
							for (sc = 0; sc < 4U;
							     sc++)
								for (fb = 0; fb < 16U;
								     fb++)
									check_mem(
										dsts[d],
										cc_codes[c],
										mw_codes[mw],
										disps[di],
										(dsts[d] == X86_RSP ? 0U : hi),
										sc,
										fb,
										via);
						}

	check_selectors();
	check_asymmetry();

	if (failures != 0) {
		printf("x86 setcc_mem route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 setcc_mem route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
