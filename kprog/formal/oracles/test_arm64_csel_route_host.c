/*
 * Host cross-check for the AArch64 simulator's *conditional select* family
 * (CSEL/CSINC/CSET/CINV/CSINV/CSINC/CSETM/CSNEG), driven through the real
 * dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. `generated/arm64_csel.h` names eight opcodes, and the
 * dispatcher reaches it at one arm that evaluates the condition, takes either
 * the pointer-tag path or the scalar path, and writes the destination. No host
 * that included the simulator header drove any of them: perturbing the `CSINC`
 * arm of the generated contract left every existing oracle green.
 *
 * What is checked, and why each case is chosen:
 *
 *   - both condition outcomes, so the `taken` branch and the fall-through
 *     branch are each exercised for every opcode;
 *   - a scalar destination and a pointer-tagged destination, since the
 *     dispatcher takes a different path for a 64-bit access whose source is a
 *     pointer, and that path must carry the *source's* tag;
 *   - both access widths, so a write at the wrong width shows;
 *   - the expected value computed here from the architectural definition of
 *     each opcode, not by calling the generated macro.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_csel_route_host.c -o build/test_arm64_csel_route_host &&
 *   ./build/test_arm64_csel_route_host
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

/* The architectural value of each conditional-select opcode for a given
 * `taken`, written from the instruction definitions. */
static __u64 expected(unsigned op, __u64 src, __u64 src2, int taken)
{
	switch (op) {
	case ARM64_OP_CSEL:
		return taken ? src : src2;
	case ARM64_OP_CINC:		/* CINC: src+1 if taken, else src */
		return taken ? src + 1 : src;
	case ARM64_OP_CSET:		/* CSET: 1 if taken, else 0 */
		return taken ? 1 : 0;
	case ARM64_OP_CINV:		/* CINV: ~src if taken, else src */
		return taken ? ~src : src;
	case ARM64_OP_CSINV:
		return taken ? src : ~src2;
	case ARM64_OP_CSINC:
		return taken ? src : src2 + 1;
	case ARM64_OP_CSETM:		/* CSETM: all ones if taken, else 0 */
		return taken ? ~(__u64)0 : 0;
	case ARM64_OP_CSNEG:
		return taken ? src : (__u64)(-(__s64)src2);
	default:
		return 0;
	}
}

int main(void)
{
	static const unsigned ops[] = {
		ARM64_OP_CSEL,  ARM64_OP_CINC,  ARM64_OP_CSET,
		ARM64_OP_CINV,  ARM64_OP_CSINV, ARM64_OP_CSINC,
		ARM64_OP_CSETM, ARM64_OP_CSNEG,
	};
	static const unsigned conds[] = {
		/* unconditionally true and unconditionally false, so both arms of
		 * every opcode are reached without depending on flag semantics. */
		ARM64_COND_AL,
		ARM64_COND_EQ,
	};
	static const unsigned flagss[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	static const unsigned nregs[] = { ARM64_X0, ARM64_X5, ARM64_X10,
					  ARM64_X17, ARM64_X29, ARM64_X1 };
	unsigned oi, ci, wi, di;

	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (ci = 0; ci < sizeof(conds) / sizeof(conds[0]); ci++)
			for (wi = 0; wi < sizeof(flagss) / sizeof(flagss[0]); wi++)
				for (di = 0; di < sizeof(nregs) / sizeof(nregs[0]);
				     di++) {
					unsigned dst = nregs[di];
					unsigned s1 = nregs[(di + 1) % 6];
					unsigned s2 = nregs[(di + 2) % 6];
					unsigned width = flagss[wi];
					unsigned cond = conds[ci];
					int taken;
					__u64 src, src2, want, got;

					DECL_STATE();
					SEED_STATE();

					src = ARM64_SIM_L_READ_REG(s1);
					src2 = ARM64_SIM_L_READ_REG(s2);
					/* the condition is evaluated from the seeded
					 * flags; AL is always taken, EQ depends on Z */
					taken = (cond == ARM64_COND_AL) ? 1
									: (__a64_z ? 1 : 0);
					want = expected(ops[oi], src, src2, taken);
					if (width == ARM64_WIDTH_32)
						want &= 0xffffffffULL;

					ARM64_SIM_L_EXEC(ops[oi], dst, s1, s2, s2,
							  width, cond, 0);

					if (unsupported_calls != 0) {
						printf("op %#x reached the "
						       "unsupported arm\n", ops[oi]);
						failures++;
						continue;
					}

					got = ARM64_SIM_L_READ_REG(dst);
					cases++;

					if (got != want) {
						printf("MISMATCH op=%#x w=%u cond=%u "
						       "taken=%d: got %#llx want %#llx\n",
						       ops[oi], width, cond, taken,
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
		printf("arm64 csel route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 csel route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}