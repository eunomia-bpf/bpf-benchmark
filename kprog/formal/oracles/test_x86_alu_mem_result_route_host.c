/*
 * Host cross-check for the x86 simulator's routing of the memory-source ALU
 * op-step result (STEP 0155).
 *
 * Drives the real body macros `X86_SIM_L_EXEC_ALU_MEM`,
 * `X86_SIM_L_EXEC_ALU_MEM_UNARY`, `X86_SIM_L_EXEC_ALU_MEM_IMM`, and
 * `X86_SIM_L_EXEC_ALU_MEM_REG` of `x86/x86_sim_local_bpf.h` -- the same
 * bodies the dispatcher's `X86_OP_ALU_MEM` (0x23), `X86_OP_ALU_MEM_UNARY`
 * (0x32), `X86_OP_ALU_MEM_IMM` (0x33), and `X86_OP_ALU_MEM_REG` (0x36) arms
 * forward to -- and compares their whole effect (the sixteen register
 * values, their tags, the four arithmetic flags, the heap image, and the
 * stack frame image) against an independent model restated from the raw
 * macros:
 *
 *   - the register-destination form reads its left operand from the
 *     destination register and its right operand from the addressed memory
 *     at the whole-immediate displacement, then writes the result back to
 *     the register;
 *   - the unary, store-immediate, and register-source forms read the left
 *     operand from the addressed memory (the store-immediate form at the
 *     store-half displacement), and write the result back through the same
 *     address: the stack body when the destination is `X86_RSP`, the
 *     little-endian store otherwise;
 *   - the SBB token consumes the live incoming borrow and the ADC token the
 *     live incoming carry from the planted flag file;
 *   - every other token routes its result through the generated 16-arm
 *     `KPROG_X86_ALU_RESULT` contract and its flags through the generated
 *     ten-arm `KPROG_X86_ALU_FLAG_ARM` body selection;
 *   - the unary form always runs the default (zero-borrow/zero-carry)
 *     ladder even at the SBB/ADC op bytes, and the increment/decrement flag
 *     arms restore the incoming carry.
 *
 * The full register file, tags, flags, heap, and stack frame are planted
 * before every case, so a misroute that reads, writes, or flags the wrong
 * cell is caught. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_alu_mem_result_route_host.c \
 *      -o build/test_x86_alu_mem_result_route_host \
 *      && ./build/test_x86_alu_mem_result_route_host
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

static __u64 mreg[16];
static __u8 mtag[16];
static __u8 mcf, mzf, msf, mof;

/* The heap the memory operands address: the sim's byte image and the
 * model's fold target, compared byte for byte after every step. */
#define HEAP_BYTES 16384U
#define HEAP_ORIGIN 4096U
#define HEAP_MODEL_OFFSET 4096
static __u8 heap[HEAP_BYTES];
static __u8 exp_heap[HEAP_BYTES];

/* The stack frame image the model folds its writes onto. */
static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* Every form addresses the same planted heap origin through the memory-operand
 * base register, so the plant forces that lane to the mapped heap address and
 * the scalar tag (an unmapped pattern value would fault the real body's load).
 */
#define MEM_BASE_REG X86_RCX
#define HEAP_REG_VALUE ((__u64)(long)(heap + HEAP_ORIGIN))

#define INDEX_REG X86_RDI
#define INDEX_VALUE 8ULL
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) +
	       0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

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

static __u64 width_sign(unsigned width)
{
	return width == X86_WIDTH_8 ? 0x80ULL :
	       width == X86_WIDTH_16 ? 0x8000ULL :
	       width == X86_WIDTH_32 ? 0x80000000ULL :
	       0x8000000000000000ULL;
}

/* The store-immediate value: the 32-bit mask, plus the sign-extension arm
 * at the 64-bit default width. Restated from the raw decode. */
static __u64 model_imm_value(__u64 imm, unsigned width)
{
	if (resolve_width(width) == X86_WIDTH_64 && (imm & 0x80000000ULL))
		return (imm & 0xffffffffULL) | 0xffffffff00000000ULL;
	return imm & 0xffffffffULL;
}

/* An independent little-endian load: a byte loop over the planted image. */
static __u64 load_le(const __u8 *bytes, __s64 at, unsigned w)
{
	__u64 value = 0ULL;
	unsigned k;

	for (k = 0; k < w; k++)
		value |= (__u64)bytes[at + (__s64)k] << (8U * k);
	return value;
}

/* The width-wrapped absolute value the multiply flag body takes. */
static __u64 modeled_abs(__u64 value, unsigned w)
{
	__u64 narrowed = value & width_mask(w);

	if (narrowed & width_sign(w))
		return ((~narrowed) + 1) & width_mask(w);
	return narrowed;
}

/* The one-step boolean lift, so carry/borrow contribute exactly one bit. */
#define EXACT_BOOL(X) ((_Bool)(X) ? 1ULL : 0ULL)

/* ---- Independent per-token result (all operands width-masked) ------------ */

static __u64 result_of(unsigned alu, __u64 lhs, __u64 rhs,
		       __u8 carry_in, unsigned width)
{
	unsigned w = resolve_width(width);
	__u64 mask = width_mask(w);
	__u64 a = lhs & width_mask(w);
	__u64 b = rhs & width_mask(w);
	__u64 count = rhs & (w == X86_WIDTH_64 ? 63ULL : 31ULL);

	switch (alu) {
	case X86_ALU_ADD:
		return a + b;
	case X86_ALU_ADC:
		return a + b + EXACT_BOOL(carry_in);
	case X86_ALU_SBB:
		return a - b - EXACT_BOOL(carry_in);
	case X86_ALU_SUB:
		return a - b;
	case X86_ALU_XOR:
		return a ^ b;
	case X86_ALU_OR:
		return a | b;
	case X86_ALU_AND:
		return a & b;
	case X86_ALU_IMUL:
		return a * b;
	case X86_ALU_INC:
		return a + 1;
	case X86_ALU_DEC:
		return a - 1;
	case X86_ALU_NOT:
		return ~lhs;
	case X86_ALU_NEG:
		return 0 - a;
	case X86_ALU_SHL:
		return (a << count) & mask;
	case X86_ALU_SHR:
		return (a >> count) & mask;
	case X86_ALU_SAR:
		if (count == 0)
			return a;
		{
			__u64 shifted = a >> count;

			if (a & width_sign(w))
				shifted |= mask ^ (mask >> count);
			return shifted;
		}
	case X86_ALU_ROL:
		{
			__u64 bits = (__u64)width_bits(w);
			__u64 c = count & (bits - 1);

			if (c == 0)
				return a;
			return ((a << c) | (a >> (bits - c))) & mask;
		}
	default:
		return lhs;
	}
}

/* ---- Independent flag production (all operands width-masked) ------------- */

static void model_add(__u64 a, __u64 b, __u64 r_narrow, __u64 sign)
{
	mcf = (r_narrow < a);
	mzf = (r_narrow == 0);
	msf = (r_narrow & sign) != 0;
	mof = ((~(a ^ b)) & ((a ^ r_narrow) & sign)) != 0;
}

static void model_adc(__u64 a, __u64 b, __u64 r_narrow, __u64 sign,
		      __u8 carry)
{
	mcf = (r_narrow < a) || (EXACT_BOOL(carry) && r_narrow == a);
	mzf = (r_narrow == 0);
	msf = (r_narrow & sign) != 0;
	mof = ((~(a ^ b)) & ((a ^ r_narrow) & sign)) != 0;
}

static void model_sub(__u64 a, __u64 b, __u64 r_narrow, __u64 sign)
{
	mcf = (a < b);
	mzf = (a == b);
	msf = (r_narrow & sign) != 0;
	mof = ((a ^ b) & ((a ^ r_narrow) & sign)) != 0;
}

static void model_sbb(__u64 a, __u64 b, __u64 r_narrow, __u64 sign,
		      __u8 borrow)
{
	mcf = (a < b) || (EXACT_BOOL(borrow) && a == b);
	mzf = (r_narrow == 0);
	msf = (r_narrow & sign) != 0;
	mof = ((a ^ b) & ((a ^ r_narrow) & sign)) != 0;
}

static void model_imul(__u64 lhs, __u64 rhs, unsigned w)
{
	__u64 a_abs = modeled_abs(lhs, w);
	__u64 b_abs = modeled_abs(rhs, w);
	__u64 sign = width_sign(w);
	__u64 limit = ((lhs ^ rhs) & sign) ? sign : (sign - 1);
	__u8 ov;

	if (a_abs == 0ULL)
		ov = 0;
	else
		ov = (__u8)(b_abs > limit / a_abs);

	mcf = ov;
	mof = ov;
}

static void model_shift(unsigned alu, __u64 a, __u64 rhs, __u64 r_narrow,
			unsigned w)
{
	unsigned bits = width_bits(w);
	__u64 sign = width_sign(w);
	__u64 count = rhs & (w == X86_WIDTH_64 ? 63ULL : 31ULL);

	if (count == 0)
		return;
	if (alu == X86_ALU_ROL) {
		mcf = (__u8)(r_narrow & 1);
		if (count == 1)
			mof = (__u8)(((r_narrow & sign) != 0) ^ (mcf & 1));
	} else {
		mzf = (r_narrow == 0);
		msf = (r_narrow & sign) != 0;
		if (alu == X86_ALU_SHL) {
			mcf = count <= bits
				      ? (__u8)((a >> (bits - count)) & 1) : 0;
			if (count == 1)
				mof = (__u8)(msf ^ (mcf & 1));
		} else if (alu == X86_ALU_SHR) {
			mcf = count <= bits
				      ? (__u8)((a >> (count - 1)) & 1) : 0;
			if (count == 1)
				mof = (a & sign) != 0;
		} else { /* X86_ALU_SAR */
			mcf = count <= bits
				      ? (__u8)((a >> (count - 1)) & 1)
				      : (__u8)((a & sign) != 0);
			if (count == 1)
				mof = 0;
		}
	}
}

/* The addressing offset: the displacement, plus the scaled raw index
 * register value when the AUX byte names an index register. Restated from
 * the raw AUX decode. */
static __s64 model_offset(__u32 aux, __s64 disp, __u64 index_value,
			  unsigned has_index)
{
	__s64 off = disp;

	if (has_index)
		off += (__s64)(index_value << X86_MEM_AUX_SCALE_LOG2(aux));
	return off;
}

/* The store-back half of the unary/imm/reg bodies: the stack body when the
 * destination register is the stack pointer, the little-endian byte ladder
 * otherwise, both folding onto the model's own images. The stack byte
 * ladder covers exactly the lane-active bytes; a 64-bit aligned write
 * covers the qword (which writes the same eight addressed bytes). */
/* The partial-register writeback the MEM register form installs: the byte
 * width installs the addressed byte of the value, the word width the low
 * word, the double width zero-extends the low word, the full width
 * installs the value. The destination tag becomes scalar in every arm. */
static __u64 model_partial_write(__u64 old, __u64 v, unsigned width,
				 unsigned dst_shift)
{
	if (width == X86_WIDTH_8) {
		unsigned lane = dst_shift == 8U ? 1U : 0U;

		return (old & ~(0xffULL << (8U * lane))) |
		       ((v & 0xffULL) << (8U * lane));
	}
	if (width == X86_WIDTH_16)
		return (old & ~0xffffULL) | (v & 0xffffULL);
	if (width == X86_WIDTH_32)
		return v & 0xffffffffULL;
	return v;
}

static void model_store(unsigned w, __u64 value, __u64 base_ptr, __s64 off,
			unsigned is_stack)
{
	unsigned lane;

	if (is_stack) {
		unsigned index =
			(unsigned)(((__s64)(long)base_ptr + off +
				    (__s64)X86_SIM_STACK_BYTES) & 0xffffffff);

		if ((w == X86_WIDTH_64) && ((index & 7U) == 0U))
			memcpy(&exp_stack[index], &value, 8);
		else
			for (lane = 0; lane < (w ? w : 8U); lane++)
				exp_stack[index + lane] =
					(__u8)(value >> (8U * lane));
	} else {
		unsigned slot = (unsigned)(((__u64)(long)base_ptr +
					    (__u64)off) -
					   (__u64)(long)heap);
		unsigned k;

		for (k = 0; k < (w ? w : 8U); k++)
			exp_heap[slot + k] = (__u8)(value >> (8U * k));
	}
}

/* ---- The routed bodies' whole effect for one token ----------------------- */

/* `form` selects the body composition:
 *   0 = ALU_MEM      (register lhs, memory rhs, register writeback)
 *   1 = ALU_MEM_UNARY (memory lhs, constant rhs 1, memory writeback)
 *   2 = ALU_MEM_IMM  (memory lhs at the store-half displacement, store
 *                     immediate rhs, memory writeback)
 *   3 = ALU_MEM_REG  (memory lhs, register rhs, memory writeback). */
static void model_alu_step(unsigned form, unsigned alu, unsigned dst,
			   unsigned src, unsigned width_code, __u32 aux,
			   __u64 imm, __u8 carry_in)
{
	unsigned w = resolve_width(width_code);
	__u64 mask = width_mask(w);
	__u64 sign = width_sign(w);
	unsigned has_index = ((aux & 0xffU) != X86_REG_NONE);
	__u64 index_value = has_index ? mreg[aux & 0xffU] : 0ULL;
	unsigned mem_reg = (form == 0U) ? src : dst;
	__u8 mem_tag = mtag[mem_reg];
	unsigned mem_base_is_rsp = (mem_reg == X86_RSP);
	unsigned mem_src = mem_base_is_rsp
				   ? KPROG_X86_MEM_SRC_STACK
				   : ((mem_tag == X86_SIM_TAG_ABI &&
				       w == X86_WIDTH_64)
					      ? KPROG_X86_MEM_SRC_ABI_PTR_LOAD
					      : KPROG_X86_MEM_SRC_NORMAL_LOAD);
	__s64 disp = (form == 2U) ? (__s64)(__s32)(imm >> 32)
				  : (__s64)imm;
	__s64 off = model_offset(aux, disp, index_value, has_index);
	__u64 lhs = mreg[dst];
	__u64 rhs = 1ULL;
	__u64 r;
	__u64 r_narrow;

	/* The register-destination form reads no memory cell here: its left
	 * operand is the destination register and its right operand the
	 * addressed word, so the model reads the image below; the
	 * memory-destination forms all read the left operand through the
	 * same classification the raw READ_MEM_VALUE body applies. */
	if (form != 0U) {
		switch (mem_src) {
		case KPROG_X86_MEM_SRC_STACK:
			{
				unsigned index =
					(unsigned)(((__s64)(long)
							    mreg[mem_reg] +
						    off +
						    (__s64)X86_SIM_STACK_BYTES) &
						   0xffffffff);

				lhs = load_le(exp_stack, (__s64)index, w);
				break;
			}
		case KPROG_X86_MEM_SRC_ABI_PTR_LOAD:
			lhs = load_le(exp_heap, HEAP_MODEL_OFFSET + off,
				      X86_WIDTH_64);
			break;
		default:
			lhs = load_le(exp_heap, HEAP_MODEL_OFFSET + off, w);
			break;
		}
	}

	switch (form) {
	case 0U:
		rhs = load_le(exp_heap, HEAP_MODEL_OFFSET + off, w);
		break;
	case 1U:
		break;
	case 2U:
		rhs = model_imm_value(imm, w);
		break;
	default: /* form 3 */
		rhs = mreg[src];
		break;
	}
	switch (alu) {
	case X86_ALU_SBB:
		if (form == 1U) {
			/* The unary body never runs the SBB handler; the
			 * else-side is the only reachable route. */
			r = result_of(alu, lhs, rhs, 0U, w);
			r_narrow = r & mask;
			model_sub(lhs & mask, rhs & mask, r_narrow, sign);
		} else {
			r = (unsigned long long)lhs -
			    (unsigned long long)rhs - EXACT_BOOL(carry_in);
			r_narrow = r & mask;
			model_sbb(lhs & mask, rhs & mask, r_narrow, sign,
				  carry_in);
		}
		break;
	case X86_ALU_ADC:
		if (form == 1U) {
			/* The unary body never runs the ADC handler; the
			 * else-side is the only reachable route. */
			r = (unsigned long long)lhs + (unsigned long long)rhs;
			r_narrow = r & mask;
			model_add(lhs & mask, rhs & mask, r_narrow, sign);
		} else {
			r = (unsigned long long)lhs +
			    (unsigned long long)rhs + EXACT_BOOL(carry_in);
			r_narrow = r & mask;
			model_adc(lhs & mask, rhs & mask, r_narrow, sign,
				  carry_in);
		}
		break;
	default:
		r = result_of(alu, lhs, rhs, carry_in, w);
		r_narrow = r & mask;
		switch (alu) {
		case X86_ALU_ADD:
			model_add(lhs & mask, rhs & mask, r_narrow, sign);
			break;
		case X86_ALU_INC:
			/* The increment computes the ADD flags at rhs 1 but
			 * restores the incoming CF. */
			model_add(lhs & mask, 1ULL, r_narrow, sign);
			mcf = carry_in;
			break;
		case X86_ALU_DEC:
			/* The decrement computes the SUB flags at rhs 1 but
			 * restores the incoming CF. */
			model_sub(lhs & mask, 1ULL, r_narrow, sign);
			mcf = carry_in;
			break;
		case X86_ALU_SUB:
			model_sub(lhs & mask, rhs & mask, r_narrow, sign);
			break;
		case X86_ALU_NEG:
			model_sub(0ULL, lhs & mask, r_narrow, sign);
			break;
		case X86_ALU_NOT:
			/* The no-op flag body preserves every flag. */
			break;
		case X86_ALU_SHL:
		case X86_ALU_SHR:
		case X86_ALU_SAR:
		case X86_ALU_ROL:
			model_shift(alu, lhs & mask, rhs, r_narrow, w);
			break;
		case X86_ALU_IMUL:
			model_imul(lhs, rhs, w);
			break;
		default:
			mcf = 0;
			mzf = (r_narrow == 0);
			msf = (r_narrow & sign) != 0;
			mof = 0;
			break;
		}
		break;
	}

	if (form == 0U) {
		mreg[dst] = model_partial_write(mreg[dst], r, w, 0U);
		mtag[dst] = X86_SIM_TAG_SCALAR;
	} else {
		unsigned is_stack = (dst == X86_RSP);
		__u64 base_ptr = mreg[dst];

		model_store(w, r, base_ptr, off, is_stack);
	}
}

#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_value = pattern_reg(__pl_i);             \
			__u8 __pl_tag = pattern_tag(__pl_i);                \
                                                                      \
			/* The memory-operand base register must carry a    \
			 * mapped address: every form addresses the heap    \
			 * pattern through RCX, so its lane holds the heap  \
			 * the model reads. */                             \
			if (MEM_BASE_REG == __pl_i) {                       \
				__pl_value = HEAP_REG_VALUE;                 \
				__pl_tag = X86_SIM_TAG_SCALAR;                \
			}                                                   \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)__pl_value,                 \
				__pl_tag);                                \
			mreg[__pl_i] = __pl_value;                           \
			mtag[__pl_i] = __pl_tag;                            \
		}                                                         \
	} while (0)

#define DECLARE_SIM_STATE()                                                \
	X86_SIM_L_DECLARE_STATE();                                        \
	struct x86_sim_xdp_abi __x86_sim_abi = {};                        \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;       \
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;                     \
	(void)__x86_sim_abi;                                              \
	(void)__x86_sim_skb_ctx;                                          \
	(void)__x86_sim_abi_kind;                                         \
	X86_SIM_L_DECLARE_STACK();                                        \
	(void)__x86_xmm0_lo;                                              \
	(void)__x86_xmm0_hi;                                              \
	(void)__x86_sim_ret_addr;                                         \
	(void)__x86_stack_mem;

/* An all-zero flag file and an all-one one, so a body that reads, restores,
 * or preserves a flag rather than recomputing it is distinguishable in both
 * directions. */
static const __u8 pre_flag[2] = { 0U, 1U };

#define STAGE_FLAGS(FV)                                                    \
	do {                                                               \
		__x86_cf = pre_flag[fv];                                  \
		__x86_zf = pre_flag[fv];                                  \
		__x86_sf = pre_flag[fv];                                  \
		__x86_of = pre_flag[fv];                                  \
		mcf = pre_flag[fv];                                       \
		mzf = pre_flag[fv];                                       \
		msf = pre_flag[fv];                                       \
		mof = pre_flag[fv];                                       \
	} while (0)

static const char *route_ctx;

/* Refresh the model's images and the real heap/stack from the pattern,
 * so every case starts from the same known state. */
#define PLANT_MEMORY()                                                     \
	do {                                                               \
		unsigned __pm_i;                                          \
		for (__pm_i = 0; __pm_i < HEAP_BYTES; __pm_i++) {          \
			heap[__pm_i] = (__u8)(0x30U + __pm_i);            \
			exp_heap[__pm_i] = heap[__pm_i];                  \
		}                                                         \
		for (__pm_i = 0; __pm_i < X86_SIM_STACK_BYTES; __pm_i++)  \
			exp_stack[__pm_i] = (__u8)(0xa0U + __pm_i);        \
	} while (0)

#define PLANT_RSP()                                                        \
	do {                                                               \
		/* The stack destination's base pointer is the frame size as
		 * a signed negative, so the simulator's frame index is the
		 * driven offset; the model mirrors the plant exactly. */ \
		X86_SIM_L_WRITE_REG_PTR_TAG(                              \
			X86_RSP,                                          \
			(void *)(long)(-(__s64)X86_SIM_STACK_BYTES),       \
			X86_SIM_TAG_STACK);                                \
		mreg[X86_RSP] =                                           \
			(__u64)(long)(-(__s64)X86_SIM_STACK_BYTES);         \
		mtag[X86_RSP] = X86_SIM_TAG_STACK;                        \
		X86_SIM_L_WRITE_REG_PTR_TAG(INDEX_REG,                    \
					    (void *)(long)INDEX_VALUE,     \
					    X86_SIM_TAG_SCALAR);           \
		mreg[INDEX_REG] = INDEX_VALUE;                            \
		mtag[INDEX_REG] = X86_SIM_TAG_SCALAR;                     \
	} while (0)

#define COMPARE_ALL()                                                      \
	do {                                                               \
		unsigned __ca_i;                                          \
		for (__ca_i = 0; __ca_i < 16U; __ca_i++) {                \
			__u64 __ca_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__ca_i); \
			__u8 __ca_tag = X86_SIM_L_REG_TAG(__ca_i);        \
			cases++;                                          \
			if (__ca_got != mreg[__ca_i]) {                   \
				printf("MISMATCH %s: reg%u: got 0x%llx "   \
				       "want 0x%llx\n", route_ctx,         \
				       (unsigned)__ca_i,                   \
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH %s: reg%u tag: got %u "   \
				       "want %u\n", route_ctx,             \
				       (unsigned)__ca_i, __ca_tag,         \
				       mtag[__ca_i]);                      \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/* The heap and stack images must match byte for byte. */
#define COMPARE_MEMORY(WANT_HEAP_P, WANT_STACK_P)                          \
	do {                                                               \
		unsigned __cm_i;                                          \
		int __cm_bad = 0;                                         \
		for (__cm_i = 0; __cm_i < HEAP_BYTES; __cm_i++) {          \
			if (WANT_HEAP_P[__cm_i] != heap[__cm_i]) {         \
				printf("MISMATCH %s heap[%u] got 0x%02x "  \
				       "want 0x%02x\n", route_ctx,         \
				       (unsigned)__cm_i,                   \
				       (unsigned)heap[__cm_i],             \
				       (unsigned)WANT_HEAP_P[__cm_i]);     \
				__cm_bad = 1;                              \
				break;                                     \
			}                                                 \
		}                                                         \
		for (__cm_i = 0; __cm_i < X86_SIM_STACK_BYTES; __cm_i++) { \
			if (WANT_STACK_P[__cm_i] !=                        \
			    __x86_stack_mem.b[__cm_i]) {                   \
				printf("MISMATCH %s stack[%u] got 0x%02x " \
				       "want 0x%02x\n", route_ctx,         \
				       (unsigned)__cm_i,                   \
				       (unsigned)__x86_stack_mem.b[__cm_i],\
				       (unsigned)WANT_STACK_P[__cm_i]);    \
				__cm_bad = 1;                              \
				break;                                     \
		}                                                         \
		}                                                         \
		cases++;                                                  \
		if (__cm_bad) {                                           \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

#define PRINT_FLAGS_MISMATCH(FORM, ALU, WIDTH, DST, SRC, IMM, FV)          \
	do {                                                               \
		printf("MISMATCH %s form%u alu=%u width=%u dst=%u src=%u " \
		       "imm=0x%llx fv=%u: got %u/%u/%u/%u want "           \
		       "%u/%u/%u/%u\n", route_ctx, (FORM), (ALU), (WIDTH), \
		       (DST), (SRC), (unsigned long long)(IMM), (FV),      \
		       __x86_cf, __x86_zf, __x86_sf, __x86_of,             \
		       mcf, mzf, msf, mof);                                \
		failures++;                                               \
	} while (0)

#define CHECK_FLAG_STATE(FORM, ALU, WIDTH, DST, SRC, IMM, FV)              \
	do {                                                               \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			PRINT_FLAGS_MISMATCH(FORM, ALU, WIDTH, DST, SRC,  \
					     IMM, FV);                    \
			return;                                           \
		}                                                         \
	} while (0)

/* One case of one MEM form: plant memory and registers, run the real body,
 * and compare the register file, tags, heap image, stack frame image, and
 * flags against the model. `form` selects the routed body composition:
 * 0 = ALU_MEM (register rhs, register writeback), 1 = ALU_MEM_UNARY,
 * 2 = ALU_MEM_IMM (store-immediate rhs at the store-half displacement), and
 * 3 = ALU_MEM_REG (register rhs). The dispatch route and the direct body share
 * the same composition, so `via_dispatch` drives the same case through the
 * dispatcher's opcode arm as well. */
static void check_alu_mem(unsigned form, unsigned alu, unsigned width_code,
			  unsigned dst, unsigned src, __u64 imm,
			  unsigned via_dispatch, unsigned has_index,
			  unsigned fv)
{
	__u32 aux = KPROG_X86_MEM_AUX(has_index ? INDEX_REG : X86_REG_NONE,
	                                 3U, 0U, alu);
	DECLARE_SIM_STATE()

	PLANT_MEMORY();
	PLANT_REGS();
	PLANT_RSP();
	STAGE_FLAGS(fv);

	/* The addressed word of the stack destination reads the frame at
	 * INDEX_VALUE, so the frame bytes must be planted before the run. */
	memset(__x86_stack_mem.b, 0, X86_SIM_STACK_BYTES);
	{
		unsigned __pp_i;

		for (__pp_i = 0; __pp_i < X86_SIM_STACK_BYTES; __pp_i++)
			__x86_stack_mem.b[__pp_i] = (__u8)(0xa0U + __pp_i);
	}
	memcpy(exp_stack, __x86_stack_mem.b, X86_SIM_STACK_BYTES);

	/* ---- independent model ---- */
	route_ctx = via_dispatch ? "aluMemDispatch" : "aluMem";
	model_alu_step(form, alu, dst, src, width_code, aux, imm,
		       pre_flag[fv]);

	/* ---- run the real routed body ---- */
	if (via_dispatch)
		X86_SIM_L_EXEC(form == 0U ? X86_OP_ALU_MEM :
			       form == 1U ? X86_OP_ALU_MEM_UNARY :
			       form == 2U ? X86_OP_ALU_MEM_IMM :
					    X86_OP_ALU_MEM_REG,
			       dst, src, width_code, aux, imm);
	else if (form == 0U)
		X86_SIM_L_EXEC_ALU_MEM(dst, src, width_code, aux, imm);
	else if (form == 1U)
		X86_SIM_L_EXEC_ALU_MEM_UNARY(dst, width_code, aux, imm);
	else if (form == 2U)
		X86_SIM_L_EXEC_ALU_MEM_IMM(dst, width_code, aux, imm);
	else
		X86_SIM_L_EXEC_ALU_MEM_REG(dst, src, width_code, aux, imm);

	COMPARE_ALL();
	COMPARE_MEMORY(exp_heap, exp_stack);
	CHECK_FLAG_STATE(form, alu, width_code, dst, src, imm, fv);
}

/* The four memory-opcode codes and the two handler selectors must still
 * name the dispatcher's arms, so the route oracle cannot silently rotate
 * the opcode space the body macros consume. */
static void check_selectors(void)
{
	static const unsigned tokens[16] = {
		X86_ALU_ADD, X86_ALU_SUB, X86_ALU_XOR, X86_ALU_OR,
		X86_ALU_AND, X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR,
		X86_ALU_ROL, X86_ALU_IMUL, X86_ALU_INC, X86_ALU_NOT,
		X86_ALU_SBB, X86_ALU_DEC, X86_ALU_NEG, X86_ALU_ADC,
	};
	unsigned t;

	cases++;
	if (X86_OP_ALU_MEM != 0x23U || X86_OP_ALU_MEM_UNARY != 0x32U ||
	    X86_OP_ALU_MEM_IMM != 0x33U || X86_OP_ALU_MEM_REG != 0x36U) {
		printf("MISMATCH x86 alu mem opcode code drift\n");
		failures++;
	}

	for (t = 0; t < 16U; t++) {
		__u8 sbb = KPROG_X86_ALU_USES_SBB_HANDLER(tokens[t]);
		__u8 adc = KPROG_X86_ALU_USES_ADC_HANDLER(tokens[t]);

		cases++;
		if (sbb != (__u8)(tokens[t] == X86_ALU_SBB) ||
		    adc != (__u8)(tokens[t] == X86_ALU_ADC)) {
			printf("MISMATCH x86 alu mem handler selector drift "
			       "at token %u\n", tokens[t]);
			failures++;
		}
	}
}

int main(void)
{
	static const unsigned tokens[16] = {
		X86_ALU_ADD, X86_ALU_SUB, X86_ALU_XOR, X86_ALU_OR,
		X86_ALU_AND, X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR,
		X86_ALU_ROL, X86_ALU_IMUL, X86_ALU_INC, X86_ALU_NOT,
		X86_ALU_SBB, X86_ALU_DEC, X86_ALU_NEG, X86_ALU_ADC,
	};
	static const unsigned width_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Six immediate operands: zero, one, a small count, the 63/64-mask
	 * count boundary, the 32-bit sign bit (the store immediate's
	 * sign-extension probe), and the all-ones lane. The store-immediate
	 * form reads its displacement from the upper half, so every value's
	 * `(s32)(imm >> 32)` stays inside the mapped frame (that upper half
	 * is 0 for the sign-bit value and -1 for the all-ones lane). */
	static const __u64 imm_values[6] = {
		0ULL, 1ULL, 7ULL, 63ULL, 0x80000000ULL,
		0xffffffffffffffffULL,
	};
	/* The other three forms take the WHOLE immediate as the addressing
	 * displacement, so the 32-bit sign-bit lane (a +2^31 displacement)
	 * would walk the real load off the mapped heap; swap that lane for
	 * the positive in-image end (4095) and keep the sign boundary in the
	 * negative direction (-1). */
	static const __u64 disp_values[6] = {
		0ULL, 1ULL, 7ULL, 63ULL, 4095ULL,
		0xffffffffffffffffULL,
	};
	unsigned t;
	unsigned w;
	unsigned s;
	unsigned f;
	unsigned l;

	/* All four routed MEM bodies over the full grid: the sixteen tokens
	 * times the five width codes times the two flag seeds times the six
	 * immediates, with the index mode and the dispatch route alternating
	 * with the flag seed (the flag seed drives both, so every composition
	 * visits each direction). */
	unsigned form;

	check_selectors();

	for (form = 0U; form < 4U; form++)
		for (t = 0; t < 16U; t++)
			for (w = 0; w < 5U; w++)
				for (s = 0; s < 2U; s++)
					for (f = 0; f < 2U; f++)
						for (l = 0; l < 6U; l++)
							check_alu_mem(
								form,
								tokens[t],
								width_codes[w] ?
									width_codes[w] : 1,
								X86_RCX,
								X86_RCX,
								form == 2U ?
									imm_values[l] :
									disp_values[l],
								s, f, f);
	if (failures != 0) {
		printf("x86 alu mem result route host cross-check: FAIL "
		       "(%d)\n", failures);
		return 1;
	}
	printf("x86 alu mem result route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
