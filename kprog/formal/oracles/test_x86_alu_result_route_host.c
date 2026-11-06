/*
 * Host cross-check for the x86 simulator's routing of the register-source
 * ALU op-step result (STEP 0154).
 *
 * Drives the real body macros `X86_SIM_L_EXEC_ALU_IMM` and
 * `X86_SIM_L_EXEC_ALU_REG` of `x86/x86_sim_local_bpf.h` -- the same bodies
 * the dispatcher's `X86_OP_ALU_IMM`/`X86_OP_ALU_REG` carve-outs and arms
 * forward to -- and compares their whole effect (the sixteen register
 * values, their tags, and the four arithmetic flags) against an independent
 * model restated from the generated Lean semantics:
 *
 *   - the left operand is read at the FLAGS width and the AUX byte lane,
 *   - the right operand is the store-immediate constant, whose width decode
 *     (the 32-bit mask, plus the 64-bit extension when the sign bit of that
 *     mask is set and the width is the 64-bit default) is reproduced
 *     independently, or the source register lane read at the AUX source
 *     shift,
 *   - the SBB token consumes the live incoming borrow and the ADC token the
 *     live incoming carry from the planted flag file,
 *   - every other token routes its result through the generated 16-arm
 *     `KPROG_X86_ALU_RESULT` contract and its flags through the generated
 *     ten-arm `KPROG_X86_ALU_FLAG_ARM` body selection, both fed width-masked
 *     operands,
 *   - the destination lane is written back at the width and AUX byte lane
 *     with the unwrapped result the header computes, and the destination tag
 *     is scalarized.
 *
 * The full register file, tags, and flag state are planted before every
 * case, so a misroute that reads, writes, or flags the wrong cell is caught.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_alu_result_route_host.c -o build/test_x86_alu_result_route_host \
 *      && ./build/test_x86_alu_result_route_host
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

static int failures;
static unsigned long cases;

static __u64 mreg[16];
static __u8 mtag[16];
static __u8 mcf, mzf, msf, mof;

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
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

/* The one-step arabic literals, so the model restates the wrap-around
 * arithmetic: the carry/borrow contributes one bit, not the full byte. */
#define EXACT_BOOL(X) ((_Bool)(X) ? 1ULL : 0ULL)

/* The store-immediate value: the 32-bit mask, plus the sign-extension arm at
 * the 64-bit default width. */
static __u64 model_imm_value(__u64 imm, unsigned width)
{
	if (resolve_width(width) == X86_WIDTH_64 && (imm & 0x80000000ULL))
		return (imm & 0xffffffffULL) | 0xffffffff00000000ULL;
	return imm & 0xffffffffULL;
}

/* The raw 64-bit lane value a register read supplies at the width and byte
 * shift: the non-byte widths read the whole stored cell, the byte width
 * shifts the addressed byte down, and the cell is then width-masked. */
static __u64 model_read_lane(__u64 cell, unsigned width, unsigned byte_shift)
{
	__u64 shifted = cell;

	if (width == X86_WIDTH_8 && byte_shift == 8U)
		shifted >>= 8U;
	return shifted & width_mask(width);
}

/* The partial-register writeback: the byte width installs the addressed
 * byte of the value, the word width the low word, the double width
 * zero-extends the low word, the full width installs the value. The
 * destination tag becomes scalar in every arm. */
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

/* The width-wrapped absolute value the multiply flag body takes. */
static __u64 signed_abs(__u64 value, unsigned width)
{
	__u64 narrowed = value & width_mask(width);

	if (narrowed & width_sign(width))
		return ((~narrowed) + 1) & width_mask(width);
	return narrowed;
}

/* ---- Independent per-token result (64-bit header arithmetic) ------------ */

static __u64 result_of(unsigned alu, __u64 lhs, __u64 rhs,
		       __u8 carry_in, unsigned width_code)
{
	unsigned w = resolve_width(width_code);
	__u64 mask = width_mask(w);
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
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
		if (count == 0)
			return a;
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
	__u64 a_abs = signed_abs(lhs, w);
	__u64 b_abs = signed_abs(rhs, w);
	__u64 sign = width_sign(w);
	__u64 limit = ((lhs ^ rhs) & sign) ? sign : sign - 1;
	__u8 ov = (__u8)(a_abs != 0 && b_abs > limit / a_abs);

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

/* Restate the routed bodies' whole effect for one token. The model's
 * destination and source cells hold the same pre-state the body reads from,
 * so the partial writeback folds onto them. */
static void model_alu_step(unsigned alu, unsigned form_imm, __u64 lhs_cell,
			   __u64 rhs_cell_or_imm, unsigned dst_shift,
			   unsigned src_shift, unsigned width_code,
			   unsigned dst, __u8 carry_in)
{
	unsigned w = resolve_width(width_code);
	unsigned dt = (w == X86_WIDTH_8) ? dst_shift : 0U;
	unsigned st = (w == X86_WIDTH_8) ? src_shift : 0U;
	__u64 mask = width_mask(w);
	__u64 sign = width_sign(w);
	__u64 lhs_narrow = model_read_lane(lhs_cell, w, dt);
	__u64 rhs_raw = form_imm ? model_imm_value(rhs_cell_or_imm, w)
				 : model_read_lane(rhs_cell_or_imm, w, st);
	__u64 a = lhs_narrow;
	__u64 b = rhs_raw & mask;
	__u64 r_narrow;
	__u64 r;

	switch (alu) {
	case X86_ALU_SBB:
		r = a - b - EXACT_BOOL(carry_in);
		r_narrow = r & mask;
		model_sbb(a, b, r_narrow, sign, carry_in);
		break;
	case X86_ALU_ADC:
		r = a + b + EXACT_BOOL(carry_in);
		r_narrow = r & mask;
		model_adc(a, b, r_narrow, sign, carry_in);
		break;
	default:
		r = result_of(alu, lhs_narrow, rhs_raw, carry_in, w);
		r_narrow = r & mask;
		switch (alu) {
		case X86_ALU_ADD:
			model_add(a, b, r_narrow, sign);
			break;
		case X86_ALU_INC:
			/* The increment computes the ADD flags at rhs 1 but
			 * restores the incoming CF. */
			model_add(a, 1ULL, r_narrow, sign);
			mcf = carry_in;
			break;
		case X86_ALU_DEC:
			/* The decrement computes the SUB flags at rhs 1 but
			 * restores the incoming CF. */
			model_sub(a, 1ULL, r_narrow, sign);
			mcf = carry_in;
			break;
		case X86_ALU_SUB:
			model_sub(a, b, r_narrow, sign);
			break;
		case X86_ALU_NEG:
			model_sub(0ULL, a, r_narrow, sign);
			break;
		case X86_ALU_NOT:
			/* The no-op flag body preserves every flag. */
			break;
		case X86_ALU_SHL:
		case X86_ALU_SHR:
		case X86_ALU_SAR:
		case X86_ALU_ROL:
			model_shift(alu, a, rhs_raw, r_narrow, w);
			break;
		case X86_ALU_IMUL:
			model_imul(a, b, w);
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

	mreg[dst] = model_partial_write(mreg[dst], r, w, dst_shift);
	mtag[dst] = X86_SIM_TAG_SCALAR;
}

#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
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

/* The simulator state declarations the checker bodies stand up once per
 * case: the sixteen GPR lanes and the four flag locals, the ABI scratch, the
 * stack arena, and the xmm/return locals the includes reference. */
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

#define PRINT_FLAGS_MISMATCH(FORM, ALU, WIDTH, DST_SHIFT, SRC_SHIFT,        \
			     LHS, RHS, FV)                                 \
	do {                                                               \
		printf("MISMATCH %s %s alu=%u width=%u shifts=%u/%u "      \
		       "lhs=0x%llx rhs=0x%llx fv=%u: got %u/%u/%u/%u "     \
		       "want %u/%u/%u/%u\n", route_ctx, (FORM), (ALU),     \
		       (WIDTH), (DST_SHIFT), (SRC_SHIFT),                  \
		       (unsigned long long)(LHS),                          \
		       (unsigned long long)(RHS), (FV),                    \
		       __x86_cf, __x86_zf, __x86_sf, __x86_of,             \
		       mcf, mzf, msf, mof);                                \
		failures++;                                               \
	} while (0)

#define CHECK_FLAG_STATE(FORM, ALU, WIDTH, DST_SHIFT, SRC_SHIFT, LHS, RHS, \
			 FV)                                               \
	do {                                                               \
		cases++;                                                  \
		if (__x86_cf != mcf || __x86_zf != mzf ||                 \
		    __x86_sf != msf || __x86_of != mof) {                 \
			PRINT_FLAGS_MISMATCH(FORM, ALU, WIDTH,            \
					     DST_SHIFT, SRC_SHIFT, LHS,   \
					     RHS, FV);                    \
		}                                                         \
	} while (0)

/* One route case over the immediate form: stage the pre-state, run the real
 * body, and compare the register file and flags against the model. */
static void check_alu_imm(unsigned alu, unsigned width_code, unsigned dst_shift,
			  unsigned dst, __u64 lhs_value, __u64 imm,
			  unsigned fv)
{
	DECLARE_SIM_STATE()

	PLANT_REGS();
	STAGE_FLAGS(fv);

	/* Regenerate the destination cell to the case's left operand so the
	 * grid reaches read-lane and partial-writeback edges the pattern file
	 * cannot. */
	X86_SIM_L_WRITE_REG_PTR_TAG(dst, (void *)(long)lhs_value,
				    pattern_tag(dst));
	mreg[dst] = lhs_value;
	mtag[dst] = pattern_tag(dst);

	/* ---- independent model ---- */
	route_ctx = "aluImm";
	model_alu_step(alu, 1U, lhs_value, imm, dst_shift, 0U, width_code,
		       dst, pre_flag[fv]);

	/* ---- run the real routed body ---- */
	X86_SIM_L_EXEC_ALU_IMM(dst, width_code,
			       KPROG_X86_REG_LANE_AUX(alu, dst_shift, 0U),
			       imm);

	COMPARE_ALL();
	CHECK_FLAG_STATE("imm", alu, width_code, dst_shift, 0U, lhs_value,
			 imm, fv);
}

/* One route case over the register form. */
static void check_alu_reg(unsigned alu, unsigned width_code,
			  unsigned dst_shift, unsigned src_shift, unsigned dst,
			  unsigned src, __u64 lhs_value, __u64 rhs_value,
			  unsigned fv)
{
	DECLARE_SIM_STATE()

	PLANT_REGS();
	STAGE_FLAGS(fv);

	/* Regenerate both cells to the case's operands. */
	X86_SIM_L_WRITE_REG_PTR_TAG(dst, (void *)(long)lhs_value,
				    pattern_tag(dst));
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)rhs_value,
				    pattern_tag(src));
	mreg[dst] = lhs_value;
	mtag[dst] = pattern_tag(dst);
	mreg[src] = rhs_value;
	mtag[src] = pattern_tag(src);

	/* ---- independent model ---- */
	route_ctx = "aluReg";
	model_alu_step(alu, 0U, lhs_value, rhs_value, dst_shift, src_shift,
		       width_code, dst, pre_flag[fv]);

	/* ---- run the real routed body ---- */
	X86_SIM_L_EXEC_ALU_REG(dst, src, width_code,
			       KPROG_X86_REG_LANE_AUX(alu, dst_shift,
						      src_shift));

	COMPARE_ALL();
	CHECK_FLAG_STATE("reg", alu, width_code, dst_shift, src_shift,
			 lhs_value, rhs_value, fv);
}

/* The sixteen decode codes and the two handler selectors must still name
 * the dispatcher's ladder tokens, so the route oracle cannot silently rotate
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
	if (X86_ALU_ADD != 0U || X86_ALU_SUB != 1U || X86_ALU_XOR != 2U ||
	    X86_ALU_OR != 3U || X86_ALU_AND != 4U || X86_ALU_SHL != 5U ||
	    X86_ALU_SHR != 6U || X86_ALU_SAR != 7U || X86_ALU_ROL != 8U ||
	    X86_ALU_IMUL != 9U || X86_ALU_INC != 10U || X86_ALU_NOT != 11U ||
	    X86_ALU_SBB != 12U || X86_ALU_DEC != 13U || X86_ALU_NEG != 14U ||
	    X86_ALU_ADC != 15U) {
		printf("MISMATCH x86 alu decode code drift\n");
		failures++;
	}

	for (t = 0; t < 16U; t++) {
		__u8 sbb = KPROG_X86_ALU_USES_SBB_HANDLER(tokens[t]);
		__u8 adc = KPROG_X86_ALU_USES_ADC_HANDLER(tokens[t]);

		cases++;
		if (sbb != (__u8)(tokens[t] == X86_ALU_SBB) ||
		    adc != (__u8)(tokens[t] == X86_ALU_ADC)) {
			printf("MISMATCH x86 alu handler selector drift at "
			       "token %u\n", tokens[t]);
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
	/* Six left operands: zero, one, the byte boundary, the sign
	 * boundary, a mixed payload, and the alternating lane. */
	static const __u64 lhs_values[6] = {
		0ULL, 1ULL, 0xffULL, 0x8000000000000000ULL,
		0x0123456789abcdefULL, 0xf0f0f0f0f0f0f0f0ULL,
	};
	/* Six right operands and immediates: zero, one, a small count, the
	 * 63/64-mask count boundary, the 32-bit sign bit (the store
	 * immediate's sign-extension probe), and the all-ones lane. */
	static const __u64 rhs_values[6] = {
		0ULL, 1ULL, 7ULL, 63ULL, 0x80000000ULL,
		0xffffffffffffffffULL,
	};
	unsigned t;
	unsigned w;
	unsigned s;
	unsigned f;
	unsigned l;
	unsigned r;

	check_selectors();

	for (t = 0; t < 16U; t++)
		for (w = 0; w < 5U; w++)
			for (s = 0; s < 2U; s++)
				for (f = 0; f < 2U; f++)
					for (l = 0; l < 6U; l++)
						for (r = 0; r < 6U; r++) {
							/* The immediate
							 * form; the byte
							 * shift alternates
							 * the destination
							 * register too. */
							check_alu_imm(
								tokens[t],
								width_codes[w],
								s ? 8U : 0U,
								s ? X86_RCX
								  : X86_RDX,
								lhs_values[l],
								rhs_values[r],
								f);
							/* The register
							 * form. */
							check_alu_reg(
								tokens[t],
								width_codes[w],
								s ? 8U : 0U,
								s ? 8U : 0U,
								X86_RDX,
								X86_RCX,
								lhs_values[l],
								rhs_values[r],
								f);
						}

	if (failures != 0) {
		printf("x86 alu result route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 alu result route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
