/*
 * Host cross-check for the x86 simulator's routing of the `MOVZX`/`MOVSX`
 * register-source opcode-keyed extension-shape contract (STEP 0118).
 *
 * The simulator's `X86_OP_MOVZX_REG || X86_OP_MOVSX_REG` arm (and the shared
 * `X86_SIM_L_EXEC_MOVX_REG` body) must now select *which extension function*
 * widens the raw 64-bit source register through the generated
 * `KPROG_X86_MOVX_SHAPE` opcode selector: the sign extension at the
 * `X86_OP_MOVSX_REG` opcode and the zero extension at every other opcode. The
 * source width the chosen function is applied at stays the inline
 * `(AUX) ? (AUX) : __x86_l_width` fallback, and the destination-width writeback
 * is the plain partial-register write.
 *
 * This oracle restates the whole routed effect independently — read the full
 * source register, apply the sign/zero extension at the resolved source width,
 * then the partial-register writeback at the destination width — and compares
 * the entire register file (value and tag) after driving the real
 * `X86_SIM_L_EXEC` over both opcodes, five flag codes, several AUX widths
 * (including the absent-code fallback), high-bit source values, and register
 * pairs. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_movx_shape_route_host.c -o /tmp/t_movx_shape_route
 *   /tmp/t_movx_shape_route
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

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
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

/* Restate the routed arm's whole effect. */
static void model_movx(unsigned op, unsigned dst, unsigned src, unsigned flags,
		       unsigned aux)
{
	unsigned w = resolve_width(flags);
	unsigned sw = aux ? aux : w;
	__u64 dstv = mreg[dst];
	__u64 value = mreg[src];

	if (op == X86_OP_MOVSX_REG)
		value = sign_extend_oracle(value, sw);
	else
		value = zero_extend_oracle(value, sw);

	mreg[dst] = model_partial_write(dstv, value, w);
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

static void check_movx(unsigned op, unsigned dst, unsigned src, unsigned flags,
		       unsigned aux, __u64 dstv, __u64 srcv)
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
	X86_SIM_L_WRITE_REG_PTR_TAG(dst, (void *)(long)dstv, pattern_tag(dst));
	mreg[dst] = dstv;
	X86_SIM_L_WRITE_REG_PTR_TAG(src, (void *)(long)srcv, pattern_tag(src));
	mreg[src] = srcv;

	/* MOVZX/MOVSX define no flags, so a nonzero starting state must survive. */
	__x86_cf = 0U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;

	/* ---- independent model ---- */
	model_movx(op, dst, src, flags, aux);

	/* ---- run the real routed arm ---- */
	X86_SIM_L_EXEC(op, dst, src, flags, aux, 0U);

	COMPARE_ALL();

	cases++;
	if (__x86_cf != 0U || __x86_zf != 1U || __x86_sf != 1U || __x86_of != 1U) {
		printf("MISMATCH flags op=%u: got %u/%u/%u/%u want 0/1/1/1\n",
		       op, __x86_cf, __x86_zf, __x86_sf, __x86_of);
		failures++;
	}
}

/* The routed selector must agree with the generated contract's table. */
static void check_selectors(void)
{
	cases++;
	if (KPROG_X86_MOVX_SHAPE_COUNT != 2U) {
		printf("MISMATCH movx shape contract constant drift\n");
		failures++;
	}

	cases++;
	if (KPROG_X86_MOVX_SHAPE(X86_OP_MOVZX_REG) !=
		    KPROG_X86_MOVX_SHAPE_ZERO_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(X86_OP_MOVSX_REG) !=
		    KPROG_X86_MOVX_SHAPE_SIGN_EXTEND) {
		printf("MISMATCH movx shape selector drift\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned opcodes[2] = { X86_OP_MOVZX_REG, X86_OP_MOVSX_REG };
	static const unsigned flags_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* AUX source widths: the absent-code fallback plus each real width, so the
	 * inline `(AUX) ? (AUX) : __x86_l_width` fallback is exercised. */
	static const unsigned aux_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	/* Source values with the high bits set so a zero extension and a sign
	 * extension are distinguishable. */
	static const __u64 src_values[6] = {
		0ULL, ~0ULL, 0x11223344556688ffULL, 0x0000000000000080ULL,
		0xffffffffffffaa88ULL, 0x000000007fffffffULL,
	};
	static const __u64 dst_values[4] = {
		0ULL, ~0ULL, 0xdeadbeefdeadbeefULL, 0x1122334455667788ULL,
	};
	static const unsigned pairs[3][2] = {
		{ X86_RAX, X86_RBX }, { X86_RCX, X86_RDX }, { X86_R8, X86_R9 },
	};
	unsigned o;
	unsigned f;
	unsigned a;
	unsigned sv;
	unsigned dv;
	unsigned p;

	check_selectors();

	for (o = 0; o < 2U; o++)
		for (f = 0; f < 5U; f++)
			for (a = 0; a < 5U; a++)
				for (sv = 0; sv < 6U; sv++)
					for (dv = 0; dv < 4U; dv++)
						for (p = 0; p < 3U; p++)
							check_movx(
								opcodes[o],
								pairs[p][0],
								pairs[p][1],
								flags_codes[f],
								aux_codes[a],
								dst_values[dv],
								src_values[sv]);

	if (failures != 0) {
		printf("x86 movx shape route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 movx shape route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
