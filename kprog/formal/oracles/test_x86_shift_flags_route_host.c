/*
 * Host cross-check for the x86 simulator's routing of the SHL/SHR/SAR/ROL
 * flag block (STEP 0151).
 *
 * Drives the real wrapper `X86_SIM_L_SET_SHIFT_FLAGS` of
 * `x86/x86_sim_local_bpf.h` -- the same routed body the dispatcher's shift
 * arm and the double-shift arms invoke -- and compares its whole effect --
 * the sixteen register values, their tags, and the four arithmetic flags --
 * against an independent model that restates the shift-flag semantics: a
 * masked count of zero preserves every flag, the rotate path takes CF from
 * the low result bit and keeps ZF/SF, the shift families set ZF/SF from the
 * narrowed result and derive CF from the shifted-out bit with OF defined at
 * count one. The wrapper's input derivation (width narrowing, bit count,
 * sign bit, masked shift count) is reproduced independently by the model.
 * Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_shift_flags_route_host.c -o build/test_x86_shift_flags_route_host \
 *      && ./build/test_x86_shift_flags_route_host
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

/* The shift body: the rotate path sets CF from the low result bit, the other
 * families set ZF/SF and derive CF/OF from the shifted-out bit. A count of
 * zero leaves every flag as it was. */
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

/* One route case: stage a nonzero pre-state, run the real wrapper for one
 * shift token, and compare register file and flags against the model. */
static void check_shift(unsigned alu, unsigned width_code, __u64 lhs,
			__u64 rhs, __u64 result)
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
	 * the rotate path keeps ZF/SF and a masked count of zero keeps all
	 * four. */
	__x86_cf = 0U;
	__x86_zf = 1U;
	__x86_sf = 1U;
	__x86_of = 1U;
	mcf = 0U;
	mzf = 1U;
	msf = 1U;
	mof = 1U;

	/* ---- independent model ---- */
	{
		unsigned w = resolve_width(width_code);

		model_shift(alu, lhs & width_mask(w), rhs,
			    result & width_mask(w), w, width_bits(w),
			    width_sign(w));
	}

	/* ---- run the real routed wrapper ---- */
	X86_SIM_L_SET_SHIFT_FLAGS(lhs, rhs, result, alu, width_code);

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

/* The four shift tokens must name the family the dispatcher's shift arm
 * routes: the generated decode table's codes, as pinned by the double-shift
 * contract, must not drift under the route oracle. */
static void check_selectors(void)
{
	cases++;
	if (X86_ALU_SHL != 5U || X86_ALU_SHR != 6U || X86_ALU_SAR != 7U ||
	    X86_ALU_ROL != 8U) {
		printf("MISMATCH x86 shift token codes drifted\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned tokens[4] = {
		X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR, X86_ALU_ROL,
	};
	static const unsigned width_codes[5] = {
		0U, X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64,
	};
	static const __u64 lhs_values[8] = {
		0ULL, 1ULL, 0xffULL, 0x80ULL, 0xffffffffffffffffULL,
		0x8000000000000000ULL, 0x0123456789abcdefULL, 0xdeadbeefULL,
	};
	static const __u64 rhs_values[11] = {
		0ULL, 1ULL, 2ULL, 7ULL, 8ULL, 31ULL, 32ULL, 33ULL, 63ULL,
		64ULL, 0xffffffffULL,
	};
	static const __u64 result_values[7] = {
		0ULL, ~0ULL, 0x0123456789abcdefULL, 0x80ULL,
		0x8000000000000000ULL, 0xffULL, 1ULL,
	};
	unsigned t;
	unsigned w;
	unsigned l;
	unsigned r;
	unsigned v;
	unsigned f;

	check_selectors();

	for (t = 0; t < 4U; t++)
		for (w = 0; w < 5U; w++)
			for (l = 0; l < 8U; l++)
				for (r = 0; r < 11U; r++)
					for (v = 0; v < 7U; v++)
						for (f = 0; f < 16U; f++) {
							check_shift(
								tokens[t],
								width_codes[w],
								lhs_values[l],
								rhs_values[r],
								result_values[v]);
						}

	if (failures != 0) {
		printf("x86 shift flags route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 shift flags route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
