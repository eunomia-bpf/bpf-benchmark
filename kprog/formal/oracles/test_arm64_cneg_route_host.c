/*
 * Host cross-check for the AArch64 simulator's *condition-gated negation*
 * body (CNEG), driven through the real dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 recorded twelve families the C chain routes
 * but the generated dispatch model does not name, and CNEG was one of the six
 * with only a model-side host. It matters more than most of them, because the
 * dispatcher does not take a boolean: it evaluates the *condition code* in
 * `AUX` against the live NZCV flags (`ARM64_SIM_L_EVAL_COND(AUX)`) and passes
 * the result in. So this arm is where the flag-to-condition chain that Steps
 * 0490 and 0493 proved meets the arithmetic.
 *
 * A wrong route here is silent in two ways at once: neq and negate are the
 * same cost, and nothing writes a flag, so a CNEG that negates when it should
 * not looks exactly like a correct one on any input where the condition's
 * truth value happened to be the other one.
 *
 * What is checked, over every condition code the simulator names and both
 * flag states that make it true or false:
 *
 *   - the dispatcher's condition evaluation matches an independent
 *     evaluation of the same condition over the same flags;
 *   - the destination is `-src` when the condition holds and `src` when it
 *     does not, at both access widths.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_cneg_route_host.c -o build/test_arm64_cneg_route_host &&
 *   ./build/test_arm64_cneg_route_host
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

/* An independent reading of each condition over the four flags, written from
 * the architecture rather than from the generated table. */
static int cond_holds(unsigned cond, int n, int z, int c, int v)
{
	switch (cond) {
	case ARM64_COND_EQ: return z;
	case ARM64_COND_NE: return !z;
	case ARM64_COND_CS: return c;
	case ARM64_COND_CC: return !c;
	case ARM64_COND_MI: return n;
	case ARM64_COND_PL: return !n;
	case ARM64_COND_VS: return v;
	case ARM64_COND_VC: return !v;
	case ARM64_COND_HI: return c && !z;
	case ARM64_COND_LS: return !c || z;
	case ARM64_COND_GE: return n == v;
	case ARM64_COND_LT: return n != v;
	case ARM64_COND_GT: return !z && (n == v);
	case ARM64_COND_LE: return z || (n != v);
	case ARM64_COND_AL: return 1;
	default: return -1;
	}
}

int main(void)
{
	static const __u64 values[] = {
		0ULL, 1ULL, 2ULL, 0xffULL, 0x80ULL, 0x7fffffffULL,
		0x80000000ULL, 0xffffffffULL, 0x123456789abcdefULL,
		0x8000000000000000ULL, 0xffffffffffffffffULL,
	};
	static const unsigned wids[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	static const unsigned nregs[] = { ARM64_X0, ARM64_X5, ARM64_X10,
					  ARM64_X29, ARM64_X1 };
	unsigned fi, ci, wi, vi, ri;

	/* Every combination of the four flags, so each condition is exercised
	 * both true and false rather than only in whichever state the seed
	 * happens to give. */
	for (fi = 0; fi < 16U; fi++)
		for (ci = 0; ci <= ARM64_COND_AL; ci++)
			for (wi = 0; wi < sizeof(wids) / sizeof(wids[0]); wi++)
				for (vi = 0; vi < sizeof(values) / sizeof(values[0]);
				     vi++)
					for (ri = 0;
					     ri < sizeof(nregs) / sizeof(nregs[0]);
					     ri++) {
						unsigned dst = nregs[ri];
						unsigned src =
							nregs[(ri + 2) % 5];
						unsigned width = wids[wi];
						unsigned cond = ci;
						int n = (fi >> 0) & 1;
						int z = (fi >> 1) & 1;
						int c = (fi >> 2) & 1;
						int v = (fi >> 3) & 1;
						int taken = cond_holds(cond, n, z, c, v);
						__u64 seed_value = values[vi];
						__u64 mask = width == ARM64_WIDTH_32
								   ? 0xffffffffULL
								   : ~0ULL;
						__u64 want, got;

						if (taken < 0) {
							printf("unknown condition %u\n",
							       cond);
							failures++;
							continue;
						}

						DECL_STATE();
						SEED_STATE();

						__a64_n = (__u8)n;
						__a64_z = (__u8)z;
						__a64_c = (__u8)c;
						__a64_v = (__u8)v;

						ARM64_SIM_L_WRITE_REG_WIDTH(src,
									    seed_value,
									    ARM64_WIDTH_64);

						/* Independent expectation: negate
						 * exactly when the condition holds,
						 * then narrow to the access width. */
						want = (taken
								? (__u64)(0ULL - seed_value)
								: seed_value) & mask;

						ARM64_SIM_L_EXEC(ARM64_OP_CNEG, dst, src,
								  src, src, width,
								  cond, 0);

						if (unsupported_calls != 0) {
							printf("reached the unsupported "
							       "arm\n");
							failures++;
							continue;
						}

						got = ARM64_SIM_L_READ_REG(dst);
						cases++;

						if (got != want) {
							printf("MISMATCH w=%u cond=%u "
							       "nzcv=%d%d%d%d v=%#llx: "
							       "got %#llx want %#llx\n",
							       width, cond, n, z, c, v,
							       (unsigned long long)
								       seed_value,
							       (unsigned long long)got,
							       (unsigned long long)want);
							failures++;
						}
					}

	/* A non-member opcode must reach the unsupported arm. */
	{
		DECL_STATE();
		SEED_STATE();
		ARM64_SIM_L_EXEC(0xfeU, ARM64_X0, ARM64_X1, ARM64_X2, ARM64_X3,
				  ARM64_WIDTH_64, ARM64_COND_AL, 0);
		if (unsupported_calls == 0) {
			printf("non-member opcode did not reach the unsupported arm\n");
			failures++;
		}
	}

	if (failures) {
		printf("arm64 cneg route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 cneg route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}