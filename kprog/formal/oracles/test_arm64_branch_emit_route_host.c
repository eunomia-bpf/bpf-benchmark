/*
 * Host cross-check for the AArch64 simulator's conditional-branch *emission*
 * (`ARM64_SIM_A64_JCC` -> `ARM64_SIM_A64_JCC_IMPL` / `_BACKWARD`).
 *
 * Why this host exists. Step 0519 measured which dispatch families the C chain
 * routes; this is a different surface. Step 0499 proved the two architectures'
 * branch-emission *shapes* compose to the same next PC, and
 * `test_arm64_branch_emit_host.c` checks the generated shape contract against
 * an independent oracle -- but neither executes the emitter. The x86 side has
 * had a route host for its `X86_SIM_X86_JCC` since before this sequence; the
 * AArch64 twin, `ARM64_SIM_A64_JCC`, was driven by nothing.
 *
 * That asymmetry matters because the two arms are not symmetric code. The
 * forward shape is a conditional jump; the backward shape is an *inverted*
 * conditional jump to a local fall-through label followed by an unconditional
 * jump. A body that failed to invert, or that jumped to the fall-through on
 * the wrong predicate, would still compile and still terminate -- it would just
 * take the wrong edge.
 *
 * What is checked: for every condition code, every flag state and a set of
 * addresses covering forward, equal and backward edges, the program counter
 * the emitted code arrives at equals the architectural `branchPc` model --
 * target when the predicate holds, fall-through otherwise. The oracle is
 * driven through the real macro using `goto` labels to observe which arm fired.
 *
 * One thing this oracle deliberately does *not* catch, and the reason is a
 * proved property rather than a gap: changing the backward-edge test from
 * `target <= current` to `target < current` leaves every case passing, because
 * at equality both shapes select the same next PC -- the forward form jumps
 * straight to the target, the backward form jumps over its fall-through and
 * then to the target. `Arm64BranchEmit.lean` proves exactly that as
 * `arm64_branch_emit_shape_irrelevant`, so the only observable difference at
 * the boundary is which arm fired, not where control ends up. The direction
 * contract is checked against its own ordering oracle by the model-side host.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_branch_emit_route_host.c -o build/test_arm64_branch_emit_route_host &&
 *   ./build/test_arm64_branch_emit_route_host
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

/* An independent reading of each condition over the four flags. */
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

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_lr;                                                     \
	(void)__a64_v0;                                                     \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp

#define SEED(nv, zv, cv, vv)                                               \
	do {                                                               \
		__a64_n = (__u8)(nv);                                      \
		__a64_z = (__u8)(zv);                                      \
		__a64_c = (__u8)(cv);                                      \
		__a64_v = (__u8)(vv);                                      \
	} while (0)

/* Drive the real emitter once and report which address the emitted code
 * arrives at. The macro contains `goto`s to a caller-supplied label plus a
 * local fall-through label it creates from `__LINE__`, so it must be used
 * inside a function whose labels are unique per call site -- hence one case
 * per invocation below. */
static unsigned long long probe(unsigned cond, unsigned long long current,
				unsigned long long target,
				unsigned long long fallthrough, int n, int z,
				int c, int v)
{
	unsigned long long got = 0;
	DECL_STATE();
	(void)0;

	SEED(n, z, c, v);
	goto dispatch;

arrived:
	got = target;
	return got;

dispatch:
	ARM64_SIM_A64_JCC(cond, current, target, arrived);
	got = fallthrough;
	return got;
}

int main(void)
{
	static const unsigned long long addrs[][2] = {
		/* current, target */
		{ 100, 200 },   /* forward */
		{ 100, 100 },   /* equal -- the boundary */
		{ 200, 100 },   /* backward */
		{ 0, 0 },
		{ 4096, 8 },
	};
	unsigned fi, ci, ai;
	int seen_forward = 0, seen_backward = 0;

	for (fi = 0; fi < 16U; fi++)
		for (ci = 0; ci <= ARM64_COND_AL; ci++)
			for (ai = 0;
			     ai < sizeof(addrs) / sizeof(addrs[0]); ai++) {
				unsigned cond = ci;
				int n = (fi >> 0) & 1;
				int z = (fi >> 1) & 1;
				int c = (fi >> 2) & 1;
				int v = (fi >> 3) & 1;
				int taken = cond_holds(cond, n, z, c, v);
				unsigned long long current = addrs[ai][0];
				unsigned long long target = addrs[ai][1];
				unsigned long long fallthrough = 0xDEADULL;
				unsigned long long want, got;
				unsigned long long before = unsupported_calls;

				if (taken < 0) {
					printf("unknown condition %u\n", cond);
					failures++;
					continue;
				}

				want = taken ? target : fallthrough;
				got = probe(cond, current, target, fallthrough,
					    n, z, c, v);

				if (unsupported_calls != before) {
					printf("cond %u reached the unsupported "
					       "arm\n", cond);
					failures++;
					continue;
				}

				cases++;
				if (target <= current)
					seen_backward = 1;
				else
					seen_forward = 1;

				if (got != want) {
					printf("MISMATCH cond=%u nzcv=%d%d%d%d "
					       "cur=%llu tgt=%llu: arrived at %#llx "
					       "want %#llx\n", cond, n, z, c, v,
					       current, target,
					       (unsigned long long)got,
					       (unsigned long long)want);
					failures++;
				}
			}

	/* Both emission shapes must have been exercised, or the run says
	 * nothing about the backward one -- which is the arm with the
	 * inversion. */
	cases++;
	if (!seen_forward || !seen_backward) {
		printf("one emission shape was never exercised "
		       "(forward=%d backward=%d)\n", seen_forward,
		       seen_backward);
		failures++;
	}

	if (failures) {
		printf("arm64 branch emit route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 branch emit route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}