/*
 * Host cross-check for the x86 simulator's routing of the ALU-token
 * flag-body selection (STEP 0147).
 *
 * The routed macro under test is `X86_SIM_L_SET_ALU_FLAGS(LHS, RHS, RESULT,
 * ALU, WIDTH)` in `kprog/x86/x86_sim_local_bpf.h`. It selects a flag-setting
 * body from an `X86_ALU_*` operation token through the generated contract
 * `KPROG_X86_ALU_FLAG_ARM`, replacing the hand-written `if ((ALU) == X86_ALU_*)`
 * ladder: the add body at ADD/ADC, the increment body at INC (the add body on
 * the `1` increment with the incoming carry restored), the decrement body at
 * DEC, the difference body at SUB, the borrow-difference body at SBB, the
 * negation body at NEG, the no-op body at NOT, the shift body at SHL/SHR/SAR/
 * ROL, the multiply body at IMUL (which touches only `CF`/`OF`), and the
 * bitwise body at every other token.
 *
 * This oracle drives the routed macro directly and restates the same effect in
 * an independent model built from the flag primitives' own arithmetic, over
 * every `X86_ALU_*` token, width code, and a spread of operands. The two must
 * agree on all four flags; because the macro touches no register, the whole
 * register file (value and tag) must also be unchanged, which the oracle
 * checks after every case. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_alu_flag_arm_route_host.c -o /tmp/t_afa_route
 *   /tmp/t_afa_route
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

/* The register file the model tracks, kept parallel to the simulator's own
 * state so the whole file (value and tag) can be compared after every case. */
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

/* The hardware-masked count the shift-flag contract applies. */
static unsigned shift_count(__u64 rhs, unsigned width)
{
	return (unsigned)(rhs & (width == X86_WIDTH_64 ? 63ULL : 31ULL));
}

/* The width-wrapped absolute value the multiply body takes. */
static __u64 signed_abs(__u64 value, unsigned width)
{
	__u64 mask = width_mask(width);
	__u64 narrowed = value & mask;

	if (narrowed & width_sign(width))
		return ((~narrowed) + 1) & mask;
	return narrowed;
}

/* The add body, restated from its own carry/zero/sign/overflow arithmetic. */
static void model_add(__u64 a, __u64 b, __u64 r, __u64 sign)
{
	mcf = (r < a);
	mzf = (r == 0);
	msf = (r & sign) != 0;
	mof = ((~(a ^ b)) & ((a ^ r) & sign)) != 0;
}

/* The difference body. */
static void model_sub(__u64 a, __u64 b, __u64 r, __u64 sign)
{
	mcf = (a < b);
	mzf = (a == b);
	msf = (r & sign) != 0;
	mof = ((a ^ b) & ((a ^ r) & sign)) != 0;
}

/* The borrow-difference body, with no incoming borrow in the routed arm. */
static void model_sbb(__u64 a, __u64 b, __u64 r, __u64 sign, __u8 borrow)
{
	mcf = (a < b) || ((!!borrow) && (a == b));
	mzf = (r == 0);
	msf = (r & sign) != 0;
	mof = ((a ^ b) & ((a ^ r) & sign)) != 0;
}

/* The bitwise body: CF/OF cleared, ZF the zero test, SF the result sign. */
static void model_logic(__u64 r, unsigned bits)
{
	mcf = 0;
	mzf = (r == 0);
	msf = (__u8)((r >> (bits - 1)) & 1);
	mof = 0;
}

/* The multiply body touches only CF/OF: the signed-overflow test on the two
 * width-wrapped magnitudes; ZF/SF are left as they were. */
static void model_imul(__u64 a, __u64 b, unsigned width, unsigned bits)
{
	__u64 a_abs = signed_abs(a, width);
	__u64 b_abs = signed_abs(b, width);
	__u64 sign = 1ULL << (bits - 1);
	__u64 limit = ((a ^ b) & sign) ? sign : sign - 1;
	__u8 ov = (a_abs != 0 && b_abs > limit / a_abs);

	mcf = ov;
	mof = ov;
}

/* The shift body: the rotate path sets CF from the low result bit, the other
 * families set ZF/SF and derive CF/OF from the shifted-out bit. A count of zero
 * leaves every flag as it was. */
static void model_shift(unsigned alu, __u64 a, __u64 rhs, __u64 r, unsigned width,
			unsigned bits, __u64 sign)
{
	unsigned count = shift_count(rhs, width);

	if (count == 0)
		return;
	if (alu == X86_ALU_ROL) {
		mcf = (__u8)(r & 1);
		if (count == 1)
			mof = (__u8)(((r & sign) != 0) ^ (mcf & 1));
	} else {
		mzf = (r == 0);
		msf = (r & sign) != 0;
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

/* Restate the routed macro's whole effect for an `X86_ALU_*` token. */
static void model_alu_flags(unsigned alu, __u64 lhs, __u64 rhs, __u64 result,
			    unsigned width_code)
{
	unsigned w = resolve_width(width_code);
	__u64 mask = width_mask(w);
	__u64 sign = width_sign(w);
	unsigned bits = width_bits(w);
	__u8 old_cf = mcf;
	__u64 a = lhs & mask;
	__u64 b = rhs & mask;
	__u64 r = result & mask;

	if (alu == X86_ALU_ADD || alu == X86_ALU_ADC) {
		model_add(a, b, r, sign);
	} else if (alu == X86_ALU_INC) {
		model_add(a, 1ULL & mask, r, sign);
		mcf = old_cf;
	} else if (alu == X86_ALU_DEC) {
		model_sub(a, 1ULL & mask, r, sign);
		mcf = old_cf;
	} else if (alu == X86_ALU_SUB) {
		model_sub(a, b, r, sign);
	} else if (alu == X86_ALU_SBB) {
		model_sbb(a, b, r, sign, 0U);
	} else if (alu == X86_ALU_NEG) {
		model_sub(0ULL, a, r, sign);
	} else if (alu == X86_ALU_NOT) {
		/* The no-op body leaves every flag as it was. */
	} else if (alu == X86_ALU_SHL || alu == X86_ALU_SHR ||
		   alu == X86_ALU_SAR || alu == X86_ALU_ROL) {
		model_shift(alu, a, rhs, r, w, bits, sign);
	} else if (alu == X86_ALU_IMUL) {
		model_imul(a, b, w, bits);
	} else {
		model_logic(r, bits); /* XOR/OR/AND default */
	}
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
				printf("MISMATCH reg%u: got 0x%llx want "  \
				       "0x%llx\n", (unsigned)__ca_i,       \
				       (unsigned long long)__ca_got,       \
				       (unsigned long long)mreg[__ca_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__ca_tag != mtag[__ca_i]) {                   \
				printf("MISMATCH reg%u tag: got %u want "  \
				       "%u\n", (unsigned)__ca_i, __ca_tag, \
				       mtag[__ca_i]);                     \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

static void check_alu(unsigned alu, unsigned width_code, __u64 lhs, __u64 rhs,
		      __u64 result)
{
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;
	(void)__x86_stack_mem;

	PLANT_REGS();

	/* A nonzero starting flag state, so a preserved flag is observable:
	 * the no-op body keeps all four, the multiply body keeps ZF/SF, and the
	 * increment/decrement bodies restore the initial CF. */
	__x86_cf = 0U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;
	mcf = 0U;
	mzf = 1U;
	msf = 1U;
	mof = 1U;

	/* ---- independent model ---- */
	model_alu_flags(alu, lhs, rhs, result, width_code);

	/* ---- run the real routed macro ---- */
	X86_SIM_L_SET_ALU_FLAGS(lhs, rhs, result, alu, width_code);

	COMPARE_ALL();

	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH flags alu=%u width=%u lhs=0x%llx rhs=0x%llx "
		       "result=0x%llx: got %u/%u/%u/%u want %u/%u/%u/%u\n",
		       alu, width_code, (unsigned long long)lhs,
		       (unsigned long long)rhs, (unsigned long long)result,
		       __x86_cf, __x86_zf, __x86_sf, __x86_of,
		       mcf, mzf, msf, mof);
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table: each
 * token names its own body and the bitwise body is what the codes no earlier
 * body claims reach. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_ALU_FLAG_ARM_COUNT != 10U) {
		printf("MISMATCH alu flag arm contract constant drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_ALU_FLAG_ARM(X86_ALU_ADD) != KPROG_X86_ALU_FLAG_ARM_ADD ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_ADC) != KPROG_X86_ALU_FLAG_ARM_ADD ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_INC) != KPROG_X86_ALU_FLAG_ARM_INC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_DEC) != KPROG_X86_ALU_FLAG_ARM_DEC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SUB) != KPROG_X86_ALU_FLAG_ARM_SUB ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SBB) != KPROG_X86_ALU_FLAG_ARM_SBB ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_NEG) != KPROG_X86_ALU_FLAG_ARM_NEG ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_NOT) != KPROG_X86_ALU_FLAG_ARM_NOT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SHL) != KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SHR) != KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_SAR) != KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_ROL) != KPROG_X86_ALU_FLAG_ARM_SHIFT ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_IMUL) != KPROG_X86_ALU_FLAG_ARM_IMUL ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_XOR) != KPROG_X86_ALU_FLAG_ARM_LOGIC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_OR) != KPROG_X86_ALU_FLAG_ARM_LOGIC ||
	    KPROG_X86_ALU_FLAG_ARM(X86_ALU_AND) != KPROG_X86_ALU_FLAG_ARM_LOGIC) {
		printf("MISMATCH alu flag arm selector drift\n");
		failures++;
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
	static const __u64 lhs_values[7] = {
		0ULL, ~0ULL, 0x0123456789abcdefULL, 0x8000000000000000ULL,
		0xf0f0f0f0f0f0f0f0ULL, 0xffULL, 1ULL,
	};
	static const __u64 rhs_values[7] = {
		0ULL, 1ULL, 2ULL, 31ULL, 63ULL, ~0ULL, 0x7fffffffffffffffULL,
	};
	static const __u64 result_values[6] = {
		0ULL, ~0ULL, 0x0123456789abcdefULL, 0x80ULL, 0xffffffffffffffffULL,
		0xf0f0f0f0f0f0f0f0ULL,
	};
	unsigned t;
	unsigned w;
	unsigned l;
	unsigned r;
	unsigned v;

	check_selectors();

	for (t = 0; t < 16U; t++)
		for (w = 0; w < 5U; w++)
			for (l = 0; l < 7U; l++)
				for (r = 0; r < 7U; r++)
					for (v = 0; v < 6U; v++)
						check_alu(tokens[t], width_codes[w],
							  lhs_values[l], rhs_values[r],
							  result_values[v]);

	if (failures != 0) {
		printf("x86 alu flag arm route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 alu flag arm route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
