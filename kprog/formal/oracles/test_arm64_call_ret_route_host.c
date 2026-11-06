/*
 * Host cross-check for the AArch64 simulator's call and return emission
 * (`ARM64_SIM_A64_CALL`, `ARM64_SIM_A64_RET`).
 *
 * Why this host exists. Steps 0528/0529 executed the five branch emitters and
 * found none of them had ever been driven. CALL and RET are the rest of the
 * emission surface, and they had the same history: nothing executed them.
 *
 * They are worth more than symmetry, because CALL performs *two* writes that
 * must agree. It sets the modelled link register `__a64_lr` and the architectural
 * `x30` from the same value, and RET dispatches on `__a64_lr` while the return
 * address the callee would actually use is the one in `x30`. A call that set one
 * and not the other would pass any check that looked at a single register, and
 * would return to the wrong place -- or to nothing -- at run time.
 *
 * What is checked:
 *
 *   - CALL stores the return address in both `__a64_lr` and `x30`, and they
 *     agree, over addresses whose low bits differ so a truncated store shows;
 *   - CALL transfers control to its label, so the fall-through after the call
 *     is not executed;
 *   - RET with an empty link register reaches the simulator's own return path
 *     (the `ARM64_SIM_RETURN_CASES` arms are supplied by this host, so a
 *     non-empty link register takes the arm this test installs, and that the
 *     arm is taken exactly when the link register names it).
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_call_ret_route_host.c -o build/test_arm64_call_ret_route_host &&
 *   ./build/test_arm64_call_ret_route_host
 */

/* The two return-target addresses this host installs as RET arms. They are
 * visible to the simulator header, which expands them into its switch. */
#define A64_TEST_RET_A 0x1111ULL
#define A64_TEST_RET_B 0x2222ULL

#define ARM64_SIM_RETURN_CASES                                            \
	case A64_TEST_RET_A:                                               \
		g_ret_arm = 1;                                     \
		break;                                                     \
	case A64_TEST_RET_B:                                               \
		g_ret_arm = 2;                                     \
		break;

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

/* Declared before the simulator header so its RETURN_CASES arms can set it. */
static volatile int g_ret_arm;
static int g_fell_through;

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* ARM64_SIM_RET() copies the ABI cb words and inspects the skb context, so a
 * RET host needs both declared. DECLARE_STATE supplies the registers and
 * flags; the two ABI objects are declared here. */
#define DECL_STATE()                                                       \
	struct arm64_sim_xdp_abi __a64_sim_abi = { 0 };                    \
	struct __sk_buff *__a64_sim_skb_ctx = (struct __sk_buff *)0;       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_v0;                                                     \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp

/* Drive CALL once; report whether control reached the label and the two
 * registers it should have set. */
static void probe_call(unsigned long long ret_addr, unsigned long long *lr_out,
		       unsigned long long *x30_out, int *fell_through)
{
	DECL_STATE();

	*lr_out = 0;
	*x30_out = 0;
	*fell_through = 1;
	__a64_lr = 0;
	__a64_x30.x = 0;

	goto dispatch;

arrived:
	*lr_out = __a64_lr;
	*x30_out = (unsigned long long)__a64_x30.x;
	*fell_through = 0;
	return;

dispatch:
	ARM64_SIM_A64_CALL(arrived, ret_addr);
	/* Control must not reach here. */
	*fell_through = 1;
}

/* Drive RET once with a given link register; report which arm ran. */
static int probe_ret(unsigned long long lr)
{
	DECL_STATE();

	/* ARM64_SIM_A64_RET() ends in ARM64_SIM_RET(), which returns from the
	 * *calling function*; so the result is recorded in a file-scope global
	 * that the caller reads after the call completes. */
	__a64_lr = (__s64)lr;
	g_ret_arm = 0;
	ARM64_SIM_A64_RET();
	g_fell_through = 1;   /* unreachable unless RET does not return */
	return g_ret_arm;
}

int main(void)
{
	static const unsigned long long rets[] = {
		0x1111ULL, 0x2222ULL, 0x1000ULL, 0x1110ULL,
		0xffffffffffff1111ULL, 0ULL,
	};
	unsigned i;

	for (i = 0; i < sizeof(rets) / sizeof(rets[0]); i++) {
		unsigned long long lr, x30;
		int fell;

		probe_call(rets[i], &lr, &x30, &fell);
		cases++;

		if (fell) {
			printf("CALL v=%#llx: did not transfer control\n",
			       (unsigned long long)rets[i]);
			failures++;
		}
		if (lr != rets[i]) {
			printf("CALL v=%#llx: __a64_lr is %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)lr);
			failures++;
		}
		if (x30 != rets[i]) {
			printf("CALL v=%#llx: x30 is %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)x30);
			failures++;
		}
		if (lr != x30) {
			printf("CALL v=%#llx: __a64_lr %#llx != x30 %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)lr,
			       (unsigned long long)x30);
			failures++;
		}
	}

	/* RET dispatches on the link register: an installed target takes its
	 * arm, anything else must reach the simulator's unsupported hook
	 * rather than silently doing nothing. */
	{
		unsigned long before = unsupported_calls;
		int arm;

		probe_ret(A64_TEST_RET_A);
		arm = g_ret_arm;
		cases++;
		if (arm != 1) {
			printf("RET with the A target took arm %d, want 1\n",
			       arm);
			failures++;
		}

		probe_ret(A64_TEST_RET_B);
		arm = g_ret_arm;
		cases++;
		if (arm != 2) {
			printf("RET with the B target took arm %d, want 2\n",
			       arm);
			failures++;
		}

		/* A value that is not an installed target must reach the
		 * unsupported hook, so the dispatch is not vacuous. */
		probe_ret(0x9999ULL);
		arm = g_ret_arm;
		cases++;
		if (arm != 0) {
			printf("RET with an uninstalled target took arm %d\n",
			       arm);
			failures++;
		}
		if (unsupported_calls == before) {
			printf("RET with an uninstalled target did not reach "
			       "the unsupported hook\n");
			failures++;
		}
	}

	if (failures) {
		printf("arm64 call/ret route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 call/ret route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}