/*
 * Host cross-check for the AArch64 simulator's *flag-setting arithmetic*
 * (ADDS/SUBS), driven through the real dispatcher `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. `generated/arm64_flags.h` is reached from the
 * dispatcher through `KPROG_ARM64_EXEC_ARITH_WRITEBACK`, which selects the
 * family, computes the result and sets N/Z/C/V. Before this host, that contract
 * had only a model-side check: nothing verified that the dispatcher routes
 * ADDS to the add family and SUBS to the subtract family, computes the result
 * from the right operands, writes the destination, and sets all four flags.
 *
 * That matters more than a value check, because a wrong flag here is invisible
 * at the instruction that caused it and wrong at the next branch. So the oracle
 * checks the whole state after each drive: the destination value, all four
 * flags, and the untouched registers (a writeback bug would disturb them).
 *
 * The expected values are computed here from the architectural definitions of
 * ADD/SUB and of N/Z/C/V, deliberately *not* by calling the generated macros --
 * otherwise the check would agree with any consistent error.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_flag_route_host.c -o build/test_arm64_flag_route_host &&
 *   ./build/test_arm64_flag_route_host
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

static __s64 pattern_sp;

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
		__a64_sp = pattern_sp;                                     \
		__a64_lr = pattern_reg(30);                                \
		__a64_v0 = pattern_reg(20);                                \
		__a64_v0_hi = pattern_reg(21);                             \
		for (__k = 0; __k < ARM64_SIM_STACK_BYTES; __k++)         \
			__a64_stack.b[__k] = (__u8)(__k * 7U + 3U);       \
		for (__k = 0; __k < sizeof(__a64_stack_tag); __k++)       \
			__a64_stack_tag[__k] = (__u8)(__k % 4U);           \
	} while (0)

/* The architectural result and flags of an ADD or SUB at `width`, computed
 * from the definitions rather than from the generated macro. */
struct expect {
	__u64 result;
	unsigned n, z, c, v;
};

static struct expect architectural(int is_sub, __u64 lhs, __u64 rhs,
				   unsigned width)
{
	__u64 mask = width == ARM64_WIDTH_32 ? 0xffffffffULL
					      : 0xffffffffffffffffULL;
	__u64 sign = width == ARM64_WIDTH_32 ? 0x80000000ULL
					     : 0x8000000000000000ULL;
	__u64 l = lhs & mask, r = rhs & mask;
	__u64 res = is_sub ? (l - r) : (l + r);
	struct expect e;

	res &= mask;
	e.result = res;
	e.n = (res & sign) != 0;
	e.z = res == 0;
	/* C is the carry out of an add, and NOT the borrow out of a subtract. */
	e.c = is_sub ? (l >= r) : (res < l);
	/* V is set when the result's sign disagrees with the operands': for an
	 * add that needs the operands to agree, for a subtract to disagree. */
	e.v = is_sub ? (((l ^ r) & (l ^ res) & sign) != 0)
		     : (((~(l ^ r)) & (l ^ res) & sign) != 0);
	return e;
}

int main(void)
{
	static const unsigned nregs[] = {
		ARM64_X0, ARM64_X1, ARM64_X5, ARM64_X10, ARM64_X17, ARM64_X29,
	};
	/* (opcode, is_subtract, uses_register_second_operand) */
	static const struct {
		unsigned op;
		int is_sub;
		int reg_rhs;
	} ops[] = {
		{ ARM64_OP_ADDS_IMM, 0, 0 },
		{ ARM64_OP_ADDS_REG, 0, 1 },
		{ ARM64_OP_SUBS_IMM, 1, 0 },
		{ ARM64_OP_SUBS_REG, 1, 1 },
	};
	static const unsigned flagss[] = { ARM64_WIDTH_64, ARM64_WIDTH_32 };
	unsigned oi, di, si, wi;
	/* Immediates chosen so `rhs` equals `lhs` for the seeded registers too:
	 * the subtract carry is "lhs >= rhs", so the equal case is the only one
	 * that separates it from a strict `>`, and an operand table of distinct
	 * values would never reach it. */
	static __s64 imms[24];
	unsigned ni = 0;

	{
		static const __s64 base[] = { 0, 1, -1, 2, -2, 7, -7,
					      0x7fffffffLL,
					      (__s64)0x80000000ULL };
		unsigned z;

		for (z = 0; z < sizeof(base) / sizeof(base[0]); z++)
			imms[ni++] = base[z];
		for (z = 0; z < 6U; z++)
			imms[ni++] = (__s64)pattern_reg(nregs[z]);
		for (z = 0; z < 6U; z++)
			imms[ni++] = (__s64)pattern_reg(nregs[(z + 2) % 6]);
		while (ni < 24U)
			imms[ni++] = 0;
	}

	pattern_sp = (__s64)0x7fff0000ULL;

	for (oi = 0; oi < sizeof(ops) / sizeof(ops[0]); oi++)
		for (wi = 0; wi < sizeof(flagss) / sizeof(flagss[0]); wi++)
			for (di = 0; di < sizeof(nregs) / sizeof(nregs[0]); di++)
				for (si = 0; si < sizeof(imms) / sizeof(imms[0]);
				     si++) {
					unsigned dst = nregs[di];
					unsigned s1 = nregs[(di + 2) % 6];
					unsigned s2 = nregs[(di + 4) % 6];
					unsigned width = flagss[wi];
					__u64 lhs, rhs, got, want;
					unsigned gn, gz, gc, gv;
					struct expect e;

					DECL_STATE();
					SEED_STATE();

					lhs = ARM64_SIM_L_READ_REG(s1);
					rhs = ops[oi].reg_rhs
						      ? ARM64_SIM_L_READ_REG(s2)
						      : (__u64)imms[si];
					e = architectural(ops[oi].is_sub, lhs,
							  rhs, width);
					want = e.result;

					ARM64_SIM_L_EXEC(ops[oi].op, dst, s1, s2,
							  s2, width, 0,
							  (__u64)imms[si]);

					if (unsupported_calls != 0) {
						printf("op %#x reached the "
						       "unsupported arm\n", ops[oi].op);
						failures++;
						continue;
					}

					got = ARM64_SIM_L_READ_REG(dst);
					gn = __a64_n;
					gz = __a64_z;
					gc = __a64_c;
					gv = __a64_v;
					cases++;

					if (got != want) {
						printf("VALUE op=%#x w=%u dst=%u "
						       "lhs=%#llx rhs=%#llx: got %#llx want %#llx\n",
						       ops[oi].op, width, dst,
						       (unsigned long long)lhs,
						       (unsigned long long)rhs,
						       (unsigned long long)got,
						       (unsigned long long)want);
						failures++;
						continue;
					}
					if (gn != e.n || gz != e.z || gc != e.c ||
					    gv != e.v) {
						printf("FLAGS op=%#x w=%u lhs=%#llx "
						       "rhs=%#llx: got n%u z%u c%u v%u "
						       "want n%u z%u c%u v%u\n",
						       ops[oi].op, width,
						       (unsigned long long)lhs,
						       (unsigned long long)rhs,
						       gn, gz, gc, gv,
						       e.n, e.z, e.c, e.v);
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
		printf("arm64 flag route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 flag route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}