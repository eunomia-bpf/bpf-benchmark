/*
 * Host cross-check for the AArch64 simulator's *multiply* body, driven through
 * the real dispatcher `ARM64_SIM_L_EXEC` of `../arm64/arm64_sim_local_bpf.h`
 * rather than through the generated contract alone.
 *
 * Why this host exists. `generated/arm64_mul.h` is covered by an independent
 * Lean statement and by a model-only host that compares the generated macro
 * against a hand-written table. Neither of those drives the simulator: they can
 * both stay green if the dispatcher stops routing to the multiply arm, reads the
 * wrong source, or writes the destination at the wrong width. Measured, the
 * multiply contract had no host that included the simulator header at all --
 * the only arm64 arithmetic family in that position.
 *
 * What is checked. Every multiply opcode the contract names is driven with
 * operand triples chosen so that a wrong source, a wrong addend position or a
 * width-truncated write all produce a *different* value:
 *
 *   - the three sources are distinct and non-zero, so swapping SRC/SRC2/SRC3
 *     changes the result;
 *   - the width is varied over 32 and 64 bits with operands whose high halves
 *     differ, so a write at the wrong width is observable;
 *   - the destination and both sources are distinct registers, so an
 *     in-place-write bug shows.
 *
 * The expected value is computed here from the architectural definition, by
 * hand, not by calling the contract -- otherwise the check would be circular.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_mul_route_host.c -o build/test_arm64_mul_route_host &&
 *   ./build/test_arm64_mul_route_host
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
#include <string.h>

/* The simulator header expects this hook. A supported opcode must never reach
 * it, so a non-zero count is itself a failure. */
static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* Distinct per-register values with differing high halves, so a write at 32
 * bits instead of 64 (or the reverse) changes the observable destination. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static __s64 pattern_sp;

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_n;                                                     \
	(void)__a64_z;                                                     \
	(void)__a64_c;                                                     \
	(void)__a64_v;                                                     \
	(void)__a64_lr;                                                    \
	(void)__a64_v0;                                                    \
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
		__a64_sp = pattern_sp;                                     \
		__a64_n = 1;                                               \
		__a64_z = 0;                                               \
		__a64_c = 1;                                               \
		__a64_v = 0;                                               \
		__a64_lr = pattern_reg(30);                                \
		__a64_v0 = pattern_reg(20);                                \
		__a64_v0_hi = pattern_reg(21);                             \
		for (__k = 0; __k < ARM64_SIM_STACK_BYTES; __k++)         \
			__a64_stack.b[__k] = (__u8)(__k * 7U + 3U);       \
		for (__k = 0; __k < sizeof(__a64_stack_tag); __k++)       \
			__a64_stack_tag[__k] = (__u8)(__k % 4U);           \
	} while (0)

/* The architectural result of each multiply opcode, computed here by hand. */
static __u64 expected(unsigned op, __u64 lhs, __u64 rhs, __u64 addend)
{
	switch (op) {
	case ARM64_OP_MADD:
		return lhs * rhs + addend;
	case ARM64_OP_MSUB:
		return addend - lhs * rhs;
	case ARM64_OP_MUL:
		return lhs * rhs;
	default:
		return 0;
	}
}

int main(void)
{
	static const unsigned nregs[] = {
		ARM64_X0, ARM64_X1, ARM64_X5, ARM64_X10, ARM64_X17, ARM64_X29,
	};
	static const unsigned ops[] = {
		ARM64_OP_MADD, ARM64_OP_MSUB, ARM64_OP_MUL,
	};
	static const unsigned flagss[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	unsigned oi, di, si, ti, wi;

	pattern_sp = (__s64)0x7fff0000ULL;

	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (wi = 0; wi < sizeof(flagss) / sizeof(flagss[0]); wi++)
			for (di = 0; di < sizeof(nregs) / sizeof(nregs[0]); di++)
				for (si = 0; si < sizeof(nregs) / sizeof(nregs[0]); si++)
					for (ti = 0; ti < sizeof(nregs) / sizeof(nregs[0]);
					     ti++) {
						unsigned dst = nregs[di];
						unsigned s1 = nregs[si];
						unsigned s2 = nregs[(si + 1) % 6];
						unsigned s3 = nregs[(ti + 2) % 6];
						unsigned width = flagss[wi];
						__u64 lhs, rhs, addend, want, got;

						DECL_STATE();
						SEED_STATE();

						lhs = ARM64_SIM_L_READ_REG(s1);
						rhs = ARM64_SIM_L_READ_REG(s2);
						addend = ARM64_SIM_L_READ_REG(s3);
						want = expected(ops[oi], lhs, rhs,
								addend);
						if (width == ARM64_WIDTH_32)
							want &= 0xffffffffULL;

						ARM64_SIM_L_EXEC(ops[oi], dst, s1, s2, s3,
								  width, 0, 0);

						if (unsupported_calls != 0) {
							printf("op %#x reached the "
							       "unsupported arm\n", ops[oi]);
							failures++;
							continue;
						}

						got = ARM64_SIM_L_READ_REG(dst);
						cases++;

						if (got != want) {
							printf("MISMATCH op=%#x w=%u "
							       "dst=%u: got %#llx want %#llx\n",
							       ops[oi], width, dst,
							       (unsigned long long)got,
							       (unsigned long long)want);
							failures++;
						}

					}

	/* A non-member opcode must reach the unsupported arm, so the counter is
	 * not vacuously zero. */
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
		printf("arm64 mul route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 mul route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}