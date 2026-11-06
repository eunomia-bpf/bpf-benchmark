/*
 * Host cross-check for the AArch64 simulator's sim-local byte-lane reduction
 * arm `KPROG_ARM64_REDUCTION_HANDLED` of `ARM64_SIM_L_EXEC` in
 * `../arm64/arm64_sim_local_bpf.h` (STEP 0453, mutation battery 0453).
 * Unlike STEP 0165 the checker replays the arm through BOTH lanes: the real
 * dispatcher arm (via `ARM64_SIM_L_EXEC`, whose `__a64_v0` commitment the arm
 * writes back) and a direct replay of the arm's own statement sequence, so an
 * exec-routed drift is distinguishable from a wrapper-body drift.
 *
 * The model is an independent bit-walk over the vector register: CNT counts the
 * set bits of each of the eight byte lanes into that lane's result byte, and
 * UADDLV sums the eight byte lanes into the low result byte, with the cap
 * arithmetic (2040 for an all-set lane ceiling) visible in the sum values. The
 * model never uses `__builtin_popcountll`. The unsupported arm fires exactly
 * once per non-member opcode on both lanes.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -Werror -O2 -I. -I../arm64 \
 *      build/reduction_route_host.c -o build/mut_reductionroute &&
 *   ./build/mut_reductionroute
 */

#define ARM64_SIM_ENABLE_STACK 1

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define __always_inline inline

#pragma GCC diagnostic push
/* The -O2 const-folding of the -Warray-bounds pass trips over the
 * unreachable sentinel-lane pointer reads of the sibling dispatcher arms in
 * `ARM64_SIM_L_EXEC` (a `(void *)0 + offset` load through the register
 * sentinel none of the reachable arms dereferences). Every other
 * fact the exec macro exposes stays under the same -Werror wall. */
#pragma GCC diagnostic ignored "-Warray-bounds"
#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* ------------------------------------------------------------ */
/* Model state.                                                  */
/* ------------------------------------------------------------ */

static __u64 mreg[31];
static __u8 mtag[31];
static __s64 msp;
static __u64 m_v0;
static __u64 m_v0_hi;
static unsigned long model_unsupported_calls;

static void model_unsupported(void)
{
	model_unsupported_calls++;
}

#define QUIET_GPR_ONE(REG, NAME) \
	(void)sizeof(__a64_##NAME); \
	(void)sizeof(__a64_##NAME##_tag);

#define DECL_STATE() \
	ARM64_SIM_L_DECLARE_STATE(); \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP; \
	(void)__a64_sim_abi_kind; \
	ARM64_SIM_L_DECLARE_STACK(); \
	ARM64_SIM_L_FOR_EACH_GPR(QUIET_GPR_ONE); \
	(void)__a64_lr

static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	static const __u8 tags[4] = {
		ARM64_SIM_TAG_SCALAR, ARM64_SIM_TAG_ABI,
		ARM64_SIM_TAG_PACKET, ARM64_SIM_TAG_MAP_PTR,
	};

	return tags[i % 4U];
}

#define STACK_BYTES 160U
#define STACK_SLOTS 20U
static __u8 stk_img[STACK_BYTES];
static __u8 stk_tag_img[STACK_SLOTS];

/* Independent bit walk: count the set bits of the byte lane `lane`. */
static unsigned model_lane_popcount(__u64 value, unsigned lane)
{
	unsigned n = 0;
	unsigned b;

	for (b = 0; b < 8; b++)
		n += (unsigned)((value >> (8 * lane + b)) & 1ULL);
	return n;
}

/* The sim-local reduction arm of `ARM64_SIM_L_EXEC`, restated: CNT reduces
 * each byte lane's popcount into the same lane of the result; UADDLV sums
 * the eight byte lanes into the low lane. NZCV is untouched on both arms,
 * and an opcode outside the two reaches the unsupported hook once. */
static void model_exec(unsigned op, __u64 v0)
{
	unsigned lane;

	if (op != ARM64_OP_CNT && op != ARM64_OP_UADDLV) {
		model_unsupported();
		return;
	}

	if (op == ARM64_OP_CNT) {
		__u64 out = 0;

		for (lane = 0; lane < 8; lane++)
			out |= (__u64)model_lane_popcount(v0, lane)
			       << (8 * lane);
		m_v0 = out;
		return;
	}

	m_v0 = 0;
	for (lane = 0; lane < 8; lane++)
		m_v0 += (v0 >> (8 * lane)) & 0xffULL;
}

/* ------------------------------------------------------------ */
/* The checker.                                                  */
/* ------------------------------------------------------------ */

#define STACK_ARENA_INIT()                                                 \
	do {                                                               \
		unsigned __si_i;                                          \
		for (__si_i = 0; __si_i < STACK_BYTES; __si_i++) {         \
			__a64_stack.b[__si_i] = stk_img[__si_i];          \
		}                                                         \
		for (__si_i = 0; __si_i < STACK_SLOTS; __si_i++)           \
			__a64_stack_tag[__si_i] = stk_tag_img[__si_i];    \
	} while (0)

/* Plant the simulator and model register files with the identical pattern.
 * Written as a macro so it expands in the checker's own state scope. The
 * reduction arm reads no register, so no lane pin is needed. */
#define PLANT_STATE()                                                      \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 31U; __pl_i++) {                 \
			ARM64_SIM_L_WRITE_REG_PTR_TAG(                    \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
		__a64_sp = -64LL;                                         \
		msp = -64LL;                                              \
	} while (0)

#define COMPARE_REG_STATE(OP, VIA)                                         \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 31U; __cs_i++) {                 \
			__u64 __cs_got = ARM64_SIM_L_READ_REG(__cs_i);    \
			__u8 __cs_tag = ARM64_SIM_L_REG_TAG(__cs_i);       \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH op=%#x via=%u reg%u: "     \
				       "got 0x%llx want 0x%llx\n",         \
				       (OP), (VIA), (unsigned)__cs_i,      \
				       (unsigned long long)__cs_got,       \
				       (unsigned long long)mreg[__cs_i]);  \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH op=%#x via=%u reg%u tag: " \
				       "got %u want %u\n", (OP), (VIA),    \
				       (unsigned)__cs_i, __cs_tag,         \
				       mtag[__cs_i]);                      \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
		cases++;                                                  \
		if (__a64_sp != msp) {                                    \
			printf("MISMATCH op=%#x via=%u sp: got %lld "       \
			       "want %lld\n", (OP), (VIA),                 \
			       (long long)__a64_sp, (long long)msp);       \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_v0 != m_v0) {                                   \
			printf("MISMATCH op=%#x via=%u v0: got 0x%llx "     \
			       "want 0x%llx\n", (OP), (VIA),               \
			       (unsigned long long)__a64_v0,               \
			       (unsigned long long)m_v0);                  \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_v0_hi != m_v0_hi) {                             \
			printf("MISMATCH op=%#x via=%u v0_hi: got 0x%llx "  \
			       "want 0x%llx\n", (OP), (VIA),               \
			       (unsigned long long)__a64_v0_hi,            \
			       (unsigned long long)m_v0_hi);               \
			failures++;                                       \
			return;                                           \
		}                                                         \
		cases++;                                                  \
		if (__a64_n != 0U || __a64_z != 0U || __a64_c != 0U ||     \
		    __a64_v != 0U) {                                       \
			printf("MISMATCH op=%#x via=%u nzcv drifted\n",     \
			       (OP), (VIA));                               \
			failures++;                                       \
			return;                                           \
		}                                                         \
	} while (0)

static void check_case(unsigned op, __u64 v0, unsigned via)
{
	unsigned long u0 = unsupported_calls;
	unsigned long mu0 = model_unsupported_calls;
	unsigned long u_want;
	unsigned long mu_want;
	unsigned member = op == ARM64_OP_CNT || op == ARM64_OP_UADDLV;

	DECL_STATE();
	(void)__a64_n;
	(void)__a64_z;
	(void)__a64_c;
	(void)__a64_v;

	PLANT_STATE();

	__a64_v0 = v0;
	m_v0 = v0;
	m_v0_hi = 0;

	STACK_ARENA_INIT();

	model_exec(op, v0);

	if (via) {
		/* The real dispatcher write through the reduction arm. The
		 * register slots stay runtime locals so the compiler cannot
		 * const-fold the sentinel-lane pointer reads of the other
		 * arms into a `void[0]` dereference. */
		unsigned dst = ARM64_X1;
		unsigned src = ARM64_X2;

		ARM64_SIM_L_EXEC(op, dst, src, ARM64_REG_NONE,
				 ARM64_REG_NONE, 0U, 0U, 0);
		u_want = u0 + (member ? 0 : 1);
		mu_want = mu0 + (member ? 0 : 1);
	} else if (member) {
		/* Direct replay of the arm's own commitment statement. */
		__a64_v0 = ARM64_SIM_L_REDUCTION_VALUE(op, __a64_v0);
		u_want = u0;
		mu_want = mu0;
	} else {
		/* Direct replay of the non-member fallthrough. */
		ARM64_SIM_L_UNSUPPORTED_OPCODE();
		u_want = u0 + 1;
		mu_want = mu0 + 1;
	}

	COMPARE_REG_STATE(op, via);

	cases++;
	if (unsupported_calls != u_want) {
		printf("MISMATCH op=%#x via=%u unsupported calls: got %lu "
		       "want %lu\n", op, via, unsupported_calls, u_want);
		failures++;
		return;
	}
	cases++;
	if (model_unsupported_calls != mu_want) {
		printf("MISMATCH op=%#x via=%u model unsupported calls: "
		       "got %lu want %lu\n", op, via,
		       model_unsupported_calls, mu_want);
		failures++;
		return;
	}
}

static void check_selectors(void)
{
	static const unsigned sel_ops[2] = { ARM64_OP_CNT, ARM64_OP_UADDLV };
	static const __u64 boundary_vectors[] = {
		0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0x8040201008040201ULL,
		0xffULL, 0xff00ff00ff00ff00ULL, 0x1ULL, 0x8080808080808080ULL,
	};
	unsigned i;
	__u64 sx[2];

	/* The two member opcodes reduce those exact boundary vectors. */
	for (i = 0; i < 2U; i++) {
		unsigned v;

		for (v = 0;
		     v < (unsigned)(sizeof(boundary_vectors) /
				    sizeof(boundary_vectors[0])); v++) {
			check_case(sel_ops[i], boundary_vectors[v], 1U);
			check_case(sel_ops[i], boundary_vectors[v], 0U);
		}
	}

	/* The generated wrapper maps each member opcode to its own arm, and
	 * the two arms are numerically distinct on an asymmetric vector. */
	for (i = 0; i < 2U; i++)
		sx[i] = KPROG_ARM64_REDUCTION_VALUE(sel_ops[i],
						    0x0101010101010101ULL,
						    model_unsupported());

	cases++;
	if (sx[0] != 0x0101010101010101ULL) {
		printf("MISMATCH CNT vector reduction: got 0x%llx\n",
		       (unsigned long long)sx[0]);
		failures++;
	}
	cases++;
	if (sx[1] != 8ULL) {
		printf("MISMATCH UADDLV vector reduction: got 0x%llx want 8\n",
		       (unsigned long long)sx[1]);
		failures++;
	}

	/* The dispatcher arm sits last: an opcode with no dispatcher arm
	 * anywhere in the chain reaches the unsupported arm on the exec
	 * lane. `ARM64_OP_RET` is the reserved non-member sentinel. */
	check_case(ARM64_OP_RET, 0xdeadbeefcafebabeULL, 1U);

	/* Direct-lane drive of the wrapper's own generated switch: the
	 * default hit must abort-free and count one unsupported call. */
	{
		unsigned long mu0 = model_unsupported_calls;

		(void)KPROG_ARM64_REDUCTION_VALUE(ARM64_OP_RET, 0,
						 model_unsupported());
		cases++;
		if (model_unsupported_calls != mu0 + 1) {
			printf("MISMATCH selector default hook: got %lu\n",
			       model_unsupported_calls - mu0);
			failures++;
		}
	}
}

int main(void)
{
	static const unsigned ops[2] = { ARM64_OP_CNT, ARM64_OP_UADDLV };
	static const unsigned non_members[1] = { ARM64_OP_RET };
	__u64 state = 0x7c3e9d15a2b8064fULL;
	unsigned i;
	unsigned o;

	for (i = 0; i < STACK_BYTES; i++)
		stk_img[i] = (__u8)(0xa0U + i * 3U);
	for (i = 0; i < STACK_SLOTS; i++)
		stk_tag_img[i] = (__u8)(i % 3U);

	/* The member lattice over both replay lanes. */
	for (o = 0; o < 2U; o++)
		for (i = 0; i < 64U; i++) {
			state = state * 6364136223846793005ULL +
				1442695040888963407ULL;
			check_case(ops[o], state, i & 1U);
		}

	check_selectors();
	for (i = 0; i < 4U; i++)
		check_case(non_members[0], state + (__u64)i, i & 1U);

	if (failures != 0) {
		printf("arm64 reduction route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("arm64 reduction route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}

#pragma GCC diagnostic pop
