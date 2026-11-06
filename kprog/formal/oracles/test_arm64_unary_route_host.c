/*
 * Host cross-check for the AArch64 simulator's *unary* body (MVN, NEG),
 * driven through the real dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 measured that the generated dispatch model
 * names 25 of the 35 families the C chain branches on, and recorded which of
 * the twelve unmodelled ones are driven through the dispatcher. UNARY was one
 * of the seven that were not: `generated/arm64_unary.h` had a Lean refinement
 * and a model-side host, so the contract was checked and the *routing* was
 * not.
 *
 * That matters more here than for a value-only family, because MVN and NEG are
 * each other's plausible neighbour: both take one source, both write the
 * destination at the access width, and neither writes NZCV. A dispatcher that
 * sent NEG down the MVN arm would produce a full-width complement instead of a
 * negation -- a wrong value with no flag to give it away.
 *
 * What is checked: both opcodes, both widths, over operands chosen so that a
 * swap is observable (`~v` and `-v` differ for every v except a fixed point),
 * with the expected value computed from the architectural definition here
 * rather than from the generated macro.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_unary_route_host.c -o build/test_arm64_unary_route_host &&
 *   ./build/test_arm64_unary_route_host
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

static __u64 expected(unsigned op, __u64 value, unsigned width)
{
	__u64 mask = width == ARM64_WIDTH_32 ? 0xffffffffULL
					      : 0xffffffffffffffffULL;

	if (op == ARM64_OP_MVN)
		return ~value & mask;
	if (op == ARM64_OP_NEG)
		return (__u64)(0ULL - value) & mask;
	return 0;
}

int main(void)
{
	static const __u64 values[] = {
		0ULL, 1ULL, 2ULL, 7ULL, 0xffULL, 0x80ULL,
		0x7fffffffULL, 0x80000000ULL, 0xffffffffULL,
		0x100000000ULL, 0x123456789abcdefULL,
		0x8000000000000000ULL, 0xffffffffffffffffULL,
	};
	static const unsigned ops[] = { ARM64_OP_MVN, ARM64_OP_NEG };
	static const unsigned wids[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	static const unsigned nregs[] = { ARM64_X0, ARM64_X5, ARM64_X10,
					  ARM64_X17, ARM64_X29, ARM64_X1 };
	unsigned oi, vi, wi, ri;

	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (wi = 0; wi < sizeof(wids) / sizeof(wids[0]); wi++)
			for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++)
				for (ri = 0; ri < sizeof(nregs) / sizeof(nregs[0]);
				     ri++) {
					unsigned dst = nregs[ri];
					unsigned src = nregs[(ri + 2) % 6];
					unsigned width = wids[wi];
					__u64 want, got;
					__u64 seed_value = values[vi];

					DECL_STATE();
					SEED_STATE();

					/*
					 * The simulator masks the value to the access width and then
					 * writes it; the narrow and full bodies are observationally
					 * equal because of that masking (arm64_write_arm.h says so).
					 * So the expectation is the access-width result, without
					 * assuming the high half survives -- it does not.
					 */
					want = expected(ops[oi], seed_value, width);

					/* Put seed_value in the source through the
					 * simulator's own write path, then execute. */
					ARM64_SIM_L_WRITE_REG_WIDTH(src, seed_value,
								    ARM64_WIDTH_64);
					ARM64_SIM_L_EXEC(ops[oi], dst, src, src, src,
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
						       "v=%#llx: got %#llx want %#llx\n",
						       ops[oi], width,
						       (unsigned long long)seed_value,
						       (unsigned long long)got,
						       (unsigned long long)want);
						failures++;
					}
				}

	/* The two opcodes must not agree on a value where they differ, so a swap
	 * is detectable at all. */
	{
		cases++;
		if (expected(ARM64_OP_MVN, 1ULL, ARM64_WIDTH_64) ==
		    expected(ARM64_OP_NEG, 1ULL, ARM64_WIDTH_64)) {
			printf("MVN and NEG agree at 1, so a swap is invisible\n");
			failures++;
		}
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
		printf("arm64 unary route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 unary route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}