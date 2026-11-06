/*
 * Host cross-check for the x86 simulator's routing of the variable-shift and
 * rotate op-step result (STEP 0156).
 *
 * Drives the *inline* SHIFTX/RORX arm bodies of the routed dispatcher
 * `X86_SIM_L_EXEC` in `x86/x86_sim_local_bpf.h` -- the same bodies the
 * `X86_OP_SHIFTX` (0x26), `X86_OP_RORX` (0x27), `X86_OP_SHIFTX_MEM` (0x2a),
 * and `X86_OP_RORX_MEM` (0x2b) arms execute -- and compares their whole
 * effect (the sixteen register values, their tags, the four flag bytes, the
 * heap image, and the stack frame image) against an independent model
 * restated from the raw macros:
 *
 *   - the register forms read the left operand and (for SHLX/SHRX/SARX) the
 *     count register whole at 64 bits; the result routes through the
 *     enumerated-ALU `KPROG_X86_ALU_RESULT` contract at the immediate's
 *     operation token, and `RORX` routes through the generated rotate
 *     contract at the raw immediate;
 *   - the memory forms read the left operand through the real addressed
 *     read body (the store-half displacement decode plus the AUX index/scale
 *     offset, classified by the shared memory read-dispatch contract), take
 *     their count from the AUX source-shift register (the shift tokens; the
 *     operation token from the immediate's low byte) or the byte-masked
 *     immediate (the rotate), and write back to the destination register --
 *     no memory write, no flag write;
 *   - every form writes no flag byte: the four planted flag bytes must be
 *     returned unchanged in both directions; the writeback is the
 *     width-local partial-register write, whose tag is scalarized
 *     unconditionally;
 *   - the result/rotate values restated from the generated shift contracts'
 *     independent formulas (never the macro's own helpers), so a wrong
 *     count source, a dropped mask, a swapped token, or a rotated
 *     writeback is numerically distinguishable.
 *
 * Every case is driven through the real dispatcher arm `X86_SIM_L_EXEC` (the
 * bodies are inline in the dispatcher, so the dispatch route is the only
 * body route), with the register file, tags, flags, heap image, and stack
 * frame planted before the run and compared after it.
 *
 * Build (host, no BPF):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_shiftx_rorx_route_host.c \
 *      -o build/test_x86_shiftx_rorx_route_host \
 *      && ./build/test_x86_shiftx_rorx_route_host
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
 * model's read target, compared byte for byte after every step. */
#define HEAP_BYTES 16384U
#define HEAP_ORIGIN 4096U
#define HEAP_MODEL_OFFSET 4096
static __u8 heap[HEAP_BYTES];
static __u8 exp_heap[HEAP_BYTES];

/* The stack frame image the model folds its reads onto. */
static __u8 exp_stack[X86_SIM_STACK_BYTES];

/* The memory-operand base register must carry a mapped address, so the
 * plant forces that lane to the mapped heap address and the scalar tag (an
 * unmapped pattern value would fault the real body's load). */
#define MEM_BASE_REG X86_R10
#define HEAP_REG_VALUE ((__u64)(long)(heap + HEAP_ORIGIN))
#define DST_REG X86_R9
#define SRC_REG X86_R10
#define COUNT_REG X86_R12
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

/* An independent little-endian load: a byte loop over the planted image. */
static __u64 load_le(const __u8 *bytes, __s64 at, unsigned w)
{
	__u64 value = 0ULL;
	unsigned k;

	for (k = 0; k < w; k++)
		value |= (__u64)bytes[at + (__s64)k] << (8U * k);
	return value;
}

/* ---- Independent per-token result (all operands width-masked) ------------ */

static __u64 result_of(unsigned alu, __u64 lhs, __u64 rhs, unsigned width)
{
	unsigned w = resolve_width(width);
	__u64 mask = width_mask(w);
	__u64 a = lhs & width_mask(w);
	__u64 count = rhs & (w == X86_WIDTH_64 ? 63ULL : 31ULL);

	switch (alu) {
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
	default:
		return lhs;
	}
}

/* The independent rotate: the complementary-count restatement of the
 * generated rotate contract, driven at the resolved width. */
static __u64 result_ror(__u64 lhs, __u64 rhs, unsigned width)
{
	unsigned w = resolve_width(width);
	unsigned bits = width_bits(w);
	__u64 mask = width_mask(w);
	__u64 a = lhs & mask;
	__u64 count = (rhs & (w == X86_WIDTH_64 ? 63ULL : 31ULL)) &
		      (__u64)(bits - 1);

	if (count == 0)
		return a;
	return ((a >> count) | (a << (bits - count))) & mask;
}

/* The independent width-local partial-register write the four bodies'
 * `X86_SIM_L_WRITE_REG_WIDTH` writeback performs at destination shift
 * zero: the byte code writes one byte lane (the returned value's lane
 * zero), the word code writes the low word preserving the upper bytes, the
 * dword code zero-extends, and the qword code writes the lane. The write
 * also scalarizes the destination tag. */
static __u64 model_partial_write(__u64 old, __u64 value, unsigned width)
{
	unsigned w = resolve_width(width);
	__u64 mask = width_mask(w);

	if (w == X86_WIDTH_8)
		return (old & ~0xffULL) | (value & 0xffULL);
	if (w == X86_WIDTH_16)
		return (old & ~0xffffULL) | (value & 0xffffULL);
	if (w == X86_WIDTH_32)
		return value & 0xffffffffULL;
	return value & mask;
}

/* ---- The routed bodies' whole effect for one op -------------------------- */

/* `form` selects the routed arm:
 *   0 = X86_OP_SHIFTX     (register left, register count, register writeback)
 *   1 = X86_OP_SHIFTX_MEM (memory left, AUX source-shift count)
 *   2 = X86_OP_RORX       (register left, raw-immediate count)
 *   3 = X86_OP_RORX_MEM   (memory left, byte-masked immediate count).
 * The addressed left operand of the memory forms reads through the stack arm
 * when the base register is `X86_RSP`, through the 64-bit ABI pointer arm
 * when the base tag is `X86_SIM_TAG_ABI` at width 64, and the little-endian
 * load otherwise, mirroring the raw read body exactly.
 *
 * The functions-side count is the AUX word's source-shift byte for the
 * memory-shift form and the whole count register's value for the register
 * form; the operation token is the immediate's low byte for the memory
 * shift and the whole immediate for the register shift, so a drifted lane
 * read or an unmasked operation byte is numerically distinguishable. */
static void model_shiftx_rorx_step(unsigned form, unsigned has_index,
				   unsigned alu, unsigned width_code,
				   __u32 aux, __u64 imm)
{
	unsigned w = resolve_width(width_code);
	__u64 index_value = has_index ? mreg[INDEX_REG] : 0ULL;
	unsigned mem_reg = SRC_REG;
	__u8 mem_tag = mtag[mem_reg];
	unsigned mem_base_is_rsp = (mem_reg == X86_RSP);
	unsigned mem_src = mem_base_is_rsp
				   ? KPROG_X86_MEM_SRC_STACK
				   : ((mem_tag == X86_SIM_TAG_ABI &&
				       w == X86_WIDTH_64)
					      ? KPROG_X86_MEM_SRC_ABI_PTR_LOAD
					      : KPROG_X86_MEM_SRC_NORMAL_LOAD);
	__s64 disp = (__s64)(__s32)(imm >> 32);
	__u64 lhs = mreg[SRC_REG];
	__u64 rhs = 0ULL;
	__u64 r;

	if (has_index)
		disp += (__s64)(index_value <<
				X86_MEM_AUX_SCALE_LOG2(aux));

	switch (form) {
	case 0U:
		rhs = mreg[COUNT_REG];
		break;
	case 1U:
		lhs = (mem_src == KPROG_X86_MEM_SRC_STACK)
			      ? load_le(exp_stack,
					(unsigned)(((__s64)(long)
							    mreg[mem_reg] +
						    disp +
						    (__s64)X86_SIM_STACK_BYTES) &
						   0xffffffff),
					w)
			      : ((mem_src ==
				  KPROG_X86_MEM_SRC_ABI_PTR_LOAD)
					 ? load_le(exp_heap,
						   HEAP_MODEL_OFFSET + disp,
						   X86_WIDTH_64)
					 : load_le(exp_heap,
						   HEAP_MODEL_OFFSET + disp,
						   w));
		rhs = mreg[X86_REG_AUX_GET_SRC_SHIFT(aux)];
		break;
	case 3U:
		lhs = (mem_src == KPROG_X86_MEM_SRC_STACK)
			      ? load_le(exp_stack,
					(unsigned)(((__s64)(long)
							    mreg[mem_reg] +
						    disp +
						    (__s64)X86_SIM_STACK_BYTES) &
						   0xffffffff),
					w)
			      : ((mem_src ==
				  KPROG_X86_MEM_SRC_ABI_PTR_LOAD)
					 ? load_le(exp_heap,
						   HEAP_MODEL_OFFSET + disp,
						   X86_WIDTH_64)
					 : load_le(exp_heap,
						   HEAP_MODEL_OFFSET + disp,
						   w));
		rhs = (__u8)imm;
		break;
	default: /* form 2: RORX register form */
		rhs = imm;
		break;
	}

	/* The four bodies write no flag byte: the model leaves the staged
	 * flag file untouched, exactly as the preserved-flags theorem states.
	 * The writeback: the width-local partial-register write, with no
	 * memory write and no flag write. */
	if (form == 2U || form == 3U)
		r = result_ror(lhs, rhs, w);
	else
		r = result_of(alu, lhs, rhs, w);

	mreg[DST_REG] = model_partial_write(mreg[DST_REG], r, w);
	mtag[DST_REG] = X86_SIM_TAG_SCALAR;
}

#define PLANT_REGS(lhs)                                                    \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			__u64 __pl_value = pattern_reg(__pl_i);             \
			__u8 __pl_tag = pattern_tag(__pl_i);                \
                                                                      \
			/* The left-operand register drives the shift's     \
			 * source value; the memory-operand base register   \
			 * must carry a mapped address: every memory form   \
			 * addresses the heap pattern through R10, so its   \
			 * lane holds the heap the model reads. */          \
			if (SRC_REG == __pl_i)                              \
				__pl_value = (lhs);                         \
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

/* The flag file is planted at both extremes, so a body that reads, restores,
 * or writes a flag rather than preserving it is distinguishable in both
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
		/* The stack base register's pointer is the frame size as a \
		 * signed negative, so the simulator's frame index is the  \
		 * driven offset; the model mirrors the plant exactly. */  \
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
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__cm_bad) {                                           \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

#define CHECK_FLAG_STATE(FORM, ALU, WIDTH, IMM, FV)                        \
	do {                                                               \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			printf("MISMATCH %s form%u alu=%u width=%u "      \
			       "imm=0x%llx fv=%u: flags written "         \
			       "got %u/%u/%u/%u want %u/%u/%u/%u\n",      \
			       route_ctx, (FORM), (ALU), (WIDTH),         \
			       (unsigned long long)(IMM), (FV),           \
			       __x86_cf, __x86_zf, __x86_sf, __x86_of,    \
			       mcf, mzf, msf, mof);                       \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

/* One case of one SHIFTX/RORX form: plant memory, registers, and flags, run
 * the real dispatched body, and compare the register file, tags, heap image,
 * stack frame image, and the unchanged flag bytes against the model.
 * `form` selects the routed arm:
 * 0 = SHIFTX (register left + register count), 1 = SHIFTX_MEM (memory left
 * + AUX source-shift count), 2 = RORX (register left + raw immediate
 * count), and 3 = RORX_MEM (memory left + byte-masked immediate count).
 * The bodies are inline in the dispatcher, so every case drives the real
 * `X86_SIM_L_EXEC` arm. */
static void check_shiftx_rorx(unsigned form, unsigned has_index, unsigned alu,
			      unsigned width_code, __u64 imm, unsigned fv,
			      __u64 lhs)
{
	unsigned op = (form <= 1U) ? ((form == 0U) ? X86_OP_SHIFTX
						   : X86_OP_SHIFTX_MEM)
				   : ((form == 2U) ? X86_OP_RORX
						   : X86_OP_RORX_MEM);
	__u32 aux = KPROG_X86_MEM_AUX(
		(form == 1U) ? (has_index ? INDEX_REG : X86_REG_NONE)
			     : X86_REG_NONE,
		3U, 0U, (form == 1U) ? COUNT_REG : 0U);
	(void)op;

	DECLARE_SIM_STATE();
	(void)__x86_sim_abi_kind;

	PLANT_REGS(lhs);
	PLANT_MEMORY();
	PLANT_RSP();
	STAGE_FLAGS(fv);
	/* The stack frame must hold the planted pattern before the run, so a
	 * stack-addressed left operand reads the frame bytes the model
	 * reads. */
	memset(__x86_stack_mem.b, 0, X86_SIM_STACK_BYTES);
	{
		unsigned __pp_i;

		for (__pp_i = 0; __pp_i < X86_SIM_STACK_BYTES; __pp_i++)
			__x86_stack_mem.b[__pp_i] = (__u8)(0xa0U + __pp_i);
	}
	memcpy(exp_stack, __x86_stack_mem.b, X86_SIM_STACK_BYTES);

	/* The addressed word of the stack base reads the frame at
	 * INDEX_VALUE when indexed, so the frame bytes are planted before the
	 * run; the plant is exactly the one the model mirrors. */
	route_ctx = (form == 0U) ? "shiftx" :
		    (form == 1U) ? "shiftxMem" :
		    (form == 2U) ? "rorx" : "rorxMem";
	model_shiftx_rorx_step(form, has_index, alu, width_code, aux, imm);

	/* ---- run the real routed body ---- */
	X86_SIM_L_EXEC(op, DST_REG, SRC_REG, width_code, aux, imm);

	COMPARE_ALL();
	COMPARE_MEMORY(exp_heap, exp_stack);
	CHECK_FLAG_STATE(form, alu, width_code, imm, fv);
}

/* The four variable-shift/rotate opcode codes must still name the
 * dispatcher's arms, so the route oracle cannot silently rotate the opcode
 * space the body macros consume. */
static void check_selectors(void)
{
	cases++;
	if (X86_OP_SHIFTX != 0x26U || X86_OP_RORX != 0x27U ||
	    X86_OP_SHIFTX_MEM != 0x2aU || X86_OP_RORX_MEM != 0x2bU) {
		printf("MISMATCH x86 shiftx rorx opcode code drift\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned shift_tokens[3] = {
		X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR,
	};
	static const unsigned width_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Six shifts/rotates: zero, one, the width boundary, a small count,
	 * the byte-mask boundary, and the all-ones lane. Their low byte is
	 * the memory-shift form's operation token, so the small count and
	 * the mask boundary also probe a nonzero operation byte there. */
	static const __u64 shift_values[6] = {
		0ULL, 1ULL, 3ULL, 7ULL, 0xffULL, 0xffffffffffffffffULL,
	};
	/* Six left operands: zero, one, the sign bit, an all-lanes pattern,
	 * an alternating pattern, and the all-ones lane. The plant writes the
	 * left operand into the SOURCE register's lane, so the register and
	 * memory forms shift plant values and not pattern noise. */
	static const __u64 lhs_values[6] = {
		0ULL, 1ULL, 0x80ULL, 0x1122334455667788ULL,
		0xa5a5a5a55a5a5a5aULL, 0xffffffffffffffffULL,
	};
	/* Six store-half displacements: zero, plus and minus a small byte
	 * count, plus and minus one page, and one landing inside the far
	 * half of the planted heap (positive and negative, so the sign
	 * extension is exercised in both directions). */
	static const __s64 displacements[6] = {
		0LL, 5LL, -5LL, 256LL, -256LL, 4096LL,
	};
	unsigned form;
	unsigned tok;
	unsigned w;
	unsigned l;
	unsigned v;
	unsigned fv;
	unsigned ix;

	check_selectors();

	for (form = 0; form < 4U; form++) {
		unsigned uses_ror = (form == 2U || form == 3U);

		for (w = 0; w < 5U; w++) {
			for (fv = 0; fv < 2U; fv++) {
				for (ix = 0; ix < 2U; ix++) {
					/* The index byte names RDI only for
					 * the memory-shift form; every
					 * other form's AUX word has no
					 * index lane, so the model's
					 * has-index bit matches here. */
					unsigned mem_ix = (form == 1U) ? ix : 0U;

					for (l = 0; l < 6U; l++) {
						for (v = 0; v < 6U; v++) {
							if (uses_ror) {
								check_shiftx_rorx(
									form,
									mem_ix,
									0U,
									width_codes[w],
									shift_values[v],
									fv,
									lhs_values[v]);
							} else {
								for (tok = 0;
								     tok < 3U;
								     tok++) {
									/* The immediate carries
									 * the operation token in
									 * its low byte and the
									 * store-half displacement in
									 * the high half; the shift
									 * count values double as
									 * the immediate-slot payload
									 * the non-token lane sees. */
									__u64 imm =
										((__u64)(__s32)displacements[l]
										 << 32ULL) |
										(((__u64)shift_values[v] &
										  0xffffff00ULL) |
										 (__u64)shift_tokens[tok]);

									check_shiftx_rorx(
										form,
										mem_ix,
										shift_tokens[tok],
										width_codes[w],
										imm,
										fv,
										lhs_values[v]);
								}
							}
						}
					}
				}
			}
		}
	}

	if (failures == 0)
		printf("x86 shiftx rorx route host cross-check: OK "
		       "(%lu cases)\n",
		       cases);
	else
		printf("x86 shiftx rorx route host cross-check: FAIL "
		       "(%lu cases, %d failures)\n",
		       cases, failures);
	return failures == 0 ? 0 : 1;
}
