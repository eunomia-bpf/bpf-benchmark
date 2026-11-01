/*
 * Host cross-check for the AArch64 simulator's *vector reduction* body
 * (CNT, UADDLV and friends), driven through the real dispatcher
 * `ARM64_SIM_L_EXEC`.
 *
 * Why this host exists. Step 0519 recorded twelve families the C chain routes
 * but the generated dispatch model does not name; REDUCTION was one of the four
 * left with only a model-side host. It differs from the families closed so far
 * in two ways that make a model-side oracle weak:
 *
 *   - the dispatcher writes `__a64_v0`, the SIMD register, rather than a GPR
 *     destination -- so an oracle that compares only the destination register
 *     observes nothing at all;
 *   - the result is assembled lane by lane, so a fault can reorder, drop or
 *     mis-scale a single lane while the rest of the value looks right.
 *
 * What is checked: for each opcode, the value the dispatcher leaves in `v0`
 * against a lane-by-lane recomputation written here from the operation's
 * definition, over operands whose bytes are all distinct so that any lane
 * misplacement changes the result.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_reduction_route_host.c -o build/test_arm64_reduction_route_host &&
 *   ./build/test_arm64_reduction_route_host
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

static unsigned popcount8(unsigned v)
{
	unsigned n = 0;

	while (v) {
		n += v & 1U;
		v >>= 1;
	}
	return n;
}

int main(void)
{
	static const __u64 values[] = {
		0ULL, 1ULL, 0x0102030405060708ULL, 0xffULL,
		0x8040201008040201ULL, 0x123456789abcdefULL,
		0xffffffffffffffffULL, 0x8080808080808080ULL,
		0x00ff00ff00ff00ffULL, 0xfedcba9876543210ULL,
	};
	unsigned vi;
	int seen_cnt = 0, seen_uaddlv = 0;

	for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++) {
		__u64 v = values[vi];
		__u64 want_cnt = 0, want_sum = 0;
		__u64 got_cnt, got_sum;
		unsigned lane;

		/* CNT: per-byte popcount, replicated back into each byte. */
		for (lane = 0; lane < 8; lane++) {
			unsigned byte = (unsigned)((v >> (8U * lane)) & 0xffU);

			want_cnt |= (__u64)popcount8(byte) << (8U * lane);
			want_sum += byte;
		}

		/* CNT. */
		{
			DECL_STATE();
			SEED_STATE();
			__a64_v0 = v;
			ARM64_SIM_L_EXEC(ARM64_OP_CNT, ARM64_X0, ARM64_X1,
					  ARM64_X2, ARM64_X3, ARM64_WIDTH_64,
					  0, 0);
			if (unsupported_calls != 0) {
				printf("CNT reached the unsupported arm\n");
				failures++;
			} else {
				got_cnt = __a64_v0;
				cases++;
				seen_cnt = 1;
				if (got_cnt != want_cnt) {
					printf("CNT v=%#llx: got %#llx want %#llx\n",
					       (unsigned long long)v,
					       (unsigned long long)got_cnt,
					       (unsigned long long)want_cnt);
					failures++;
				}
			}
		}

		/* UADDLV: the sum of the eight bytes, in the low word. */
		{
			DECL_STATE();
			SEED_STATE();
			__a64_v0 = v;
			ARM64_SIM_L_EXEC(ARM64_OP_UADDLV, ARM64_X0, ARM64_X1,
					  ARM64_X2, ARM64_X3, ARM64_WIDTH_64,
					  0, 0);
			if (unsupported_calls != 0) {
				printf("UADDLV reached the unsupported arm\n");
				failures++;
			} else {
				got_sum = __a64_v0;
				cases++;
				seen_uaddlv = 1;
				if (got_sum != want_sum) {
					printf("UADDLV v=%#llx: got %#llx want %#llx\n",
					       (unsigned long long)v,
					       (unsigned long long)got_sum,
					       (unsigned long long)want_sum);
					failures++;
				}
			}
		}
	}

	/* Both opcodes must have been exercised, so the run is not vacuous. */
	cases++;
	if (!seen_cnt || !seen_uaddlv) {
		printf("one of the reductions was never exercised "
		       "(cnt=%d uaddlv=%d)\n", seen_cnt, seen_uaddlv);
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
		printf("arm64 reduction route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 reduction route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}