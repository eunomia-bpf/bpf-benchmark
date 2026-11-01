/*
 * Host cross-check for the AArch64 simulator's *complemented OR* body
 * (ORN_REG), driven through the real dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 recorded twelve families the C chain routes
 * but the generated dispatch model does not name; ORN was the last of them
 * left with only a model-side host. It is the one family whose *second source
 * is modified before use*: the dispatcher applies the AUX-encoded shift or
 * rotate-extend modifier to SRC2 and passes the modified value in. A model
 * oracle that feeds the contract an unmodified operand therefore exercises
 * only the modifier code 0 -- the identity -- and cannot see a fault in the
 * other four.
 *
 * What is checked, over every modifier kind, both widths and shift amounts
 * either side of the wrap point:
 *
 *   - the modifier itself, recomputed here from its definition, so a wrong
 *     second source is caught before the OR is considered;
 *   - `lhs | ~modifier(src2)` narrowed to the access width.
 *
 * Operands are chosen so that the complement matters: `~rhs` differs from
 * `rhs` in every bit, so dropping the complement changes the result for any
 * lhs that is not all-ones.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_orn_route_host.c -o build/test_arm64_orn_route_host &&
 *   ./build/test_arm64_orn_route_host
 */

#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_lr;                                                     \
	(void)__a64_v0;                                                     \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp

#define SEED_GPR_ONE(REG, NAME)                                            \
	do {                                                               \
		__a64_##NAME.x = pattern_reg((unsigned)(REG));              \
		__a64_##NAME##_tag = pattern_tag((unsigned)(REG));          \
	} while (0);

#define SEED_STATE()                                                       \
	do {                                                               \
		unsigned __k;                                              \
		ARM64_SIM_L_FOR_EACH_GPR(SEED_GPR_ONE)                    \
		__a64_sp = (__s64)0x7fff0000ULL;                           \
		__a64_lr = pattern_reg(30);                                \
		__a64_v0 = pattern_reg(20);                                \
		__a64_v0_hi = pattern_reg(21);                             \
		for (__k = 0; __k < ARM64_SIM_STACK_BYTES; __k++)         \
			__a64_stack.b[__k] = (__u8)(__k * 7U + 3U);       \
		for (__k = 0; __k < sizeof(__a64_stack_tag); __k++)       \
			__a64_stack_tag[__k] = (__u8)(__k % 4U);           \
	} while (0)

/* The modifier, written from its definition: 0 identity, 1 shift-left,
 * 2 logical shift-right, 3 arithmetic shift-right, 4 rotate-right. The amount
 * is masked to the access width. */
static __u64 want_mod(unsigned kind, __u64 v, unsigned amount, unsigned width)
{
	unsigned bits = width == ARM64_WIDTH_32 ? 32U : 64U;
	unsigned k = amount & (bits - 1U);
	__u64 mask = width == ARM64_WIDTH_32 ? 0xffffffffULL : ~0ULL;
	__u64 n = v & mask;

	switch (kind) {
	case 0:
		return v;
	case 1:
		return (n << k) & mask;
	case 2:
		return n >> k;
	case 3:
		if (width == ARM64_WIDTH_32)
			return (__u64)((__s64)(__s32)n >> k) & mask;
		return (__u64)((__s64)n >> k);
	case 4:
		if (bits == 32) {
			__u32 w = (__u32)n;
			__u32 r = k ? (__u32)((w >> k) | (w << (32U - k)))
				    : w;

			return (__u64)r & mask;
		} else {
			__u64 r = k ? ((n >> k) | (n << (64U - k))) : n;

			return r;
		}
	default:
		return 0;
	}
}

/* The packed AUX word the dispatcher decodes: byte 1 is the modifier, byte 2
 * the shift amount. */
/* Byte 1 is the modifier, byte 2 the shift amount (arm64_aux.h). */
#define AUX_PACK(mod, amount) \
	((__u32)(((__u32)(mod) << 8) | ((__u32)(amount) << 16)))

int main(void)
{
	static const __u64 values[] = {
		0ULL, 1ULL, 0xffULL, 0x80ULL, 0x7fffffffULL,
		0x80000000ULL, 0xffffffffULL, 0x123456789abcdefULL,
		0x8000000000000000ULL, 0xffffffffffffffffULL,
	};
	static const unsigned wids[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	static const unsigned mods[] = { 0, 1, 2, 3, 4 };
	static const unsigned amounts[] = { 0, 1, 7, 8, 31, 32, 63 };
	unsigned vi, wi, mi, ai;
	int seen_nonidentity = 0;

	for (wi = 0; wi < sizeof(wids) / sizeof(wids[0]); wi++)
		for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++)
			for (mi = 0; mi < sizeof(mods) / sizeof(mods[0]); mi++)
				for (ai = 0;
				     ai < sizeof(amounts) / sizeof(amounts[0]);
				     ai++) {
					unsigned width = wids[wi];
					unsigned mod = mods[mi];
					unsigned amount = amounts[ai];
					__u64 lhs = values[vi];
					__u64 rhs = values[(vi + 3) %
							   (sizeof(values) /
							    sizeof(values[0]))];
					__u64 mask = width == ARM64_WIDTH_32
							     ? 0xffffffffULL
							     : ~0ULL;
					__u64 modded, want, got;

					DECL_STATE();
					SEED_STATE();

					ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X5, lhs,
								    ARM64_WIDTH_64);
					ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X10, rhs,
								    ARM64_WIDTH_64);

					modded = want_mod(mod, rhs, amount, width);
					want = (lhs | ~modded) & mask;

					ARM64_SIM_L_EXEC(ARM64_OP_ORN_REG,
							  ARM64_X0, ARM64_X5,
							  ARM64_X10, ARM64_X1,
							  width,
							  AUX_PACK(mod, amount), 0);

					if (unsupported_calls != 0) {
						printf("reached the unsupported arm\n");
						failures++;
						continue;
					}

					got = ARM64_SIM_L_READ_REG(ARM64_X0);
					cases++;
					if (mod != 0)
						seen_nonidentity = 1;

					if (got != want) {
						printf("MISMATCH w=%u mod=%u amt=%u "
						       "lhs=%#llx rhs=%#llx: got %#llx "
						       "want %#llx\n",
						       width, mod, amount,
						       (unsigned long long)lhs,
						       (unsigned long long)rhs,
						       (unsigned long long)got,
						       (unsigned long long)want);
						failures++;
					}
				}

	/* The modifier must have been exercised in a non-identity form, or the
	 * run says nothing about the AUX decode. */
	cases++;
	if (!seen_nonidentity) {
		printf("no non-identity modifier was exercised\n");
		failures++;
	}

	/* A non-member opcode must reach the unsupported arm. */
	{
		DECL_STATE();
		SEED_STATE();
		ARM64_SIM_L_EXEC(0xfeU, ARM64_X0, ARM64_X1, ARM64_X2, ARM64_X3,
				  ARM64_WIDTH_64, 0, 0);
		if (unsupported_calls == 0) {
			printf("non-member opcode did not reach the unsupported arm\n");
			failures++;
		}
	}

	if (failures) {
		printf("arm64 orn route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 orn route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}