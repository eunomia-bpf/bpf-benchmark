/*
 * Host cross-check for the x86 simulator's conditional-branch emission shape
 * (`X86_SIM_X86_JCC` -> `X86_SIM_X86_JCC_IMPL`/`X86_SIM_X86_JCC_BACKWARD`),
 * now routed through the generated `KPROG_X86_BRANCH_BACKWARD` contract.
 *
 * Part 1 pins the routed direction macro to an independent address-ordering
 * oracle: the backward shape is exactly `target <= current`, including the
 * equality boundary, and the macro is a truth/ordering test rather than an
 * inequality in the other direction.
 *
 * Part 2 drives the real `X86_SIM_X86_JCC` macro over every accepted
 * condition code, the unsupported codes, both index arms, and an address set
 * that exercises forward, equal, and backward edges simultaneously, and checks
 * that the selected next program counter equals the architectural `branchPc`
 * model (target when taken, fall-through otherwise) for the flags the code
 * actually wants---so a body that inverts the direction test, inverts the
 * taken predicate on the backward arm, or ignores the condition on either
 * direction is numerically distinguishable.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_branch_emit_route_host.c -o /tmp/t_xber && /tmp/t_xber
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* Independent statement of the condition expression, restated from the raw
 * codes rather than the generated table. `cc` is compared as the promoted
 * word, so a value whose bits 8..31 are nonzero matches no arm and yields the
 * C default `0`. */
static unsigned model_cc_true(unsigned cc, unsigned cf, unsigned zf,
			      unsigned sf, unsigned of)
{
	switch (cc) {
	case 0U: return of;
	case 1U: return !of;
	case 2U: return cf;
	case 3U: return !cf;
	case 4U: return zf;
	case 5U: return !zf;
	case 6U: return cf || zf;
	case 7U: return !cf && !zf;
	case 8U: return sf;
	case 9U: return !sf;
	case 12U: return sf != of;
	case 13U: return sf == of;
	case 14U: return zf || (sf != of);
	case 15U: return !zf && (sf == of);
	default: return 0U;
	}
}

/* The architectural next PC: target when taken, fall-through otherwise. */
static unsigned long branch_pc(int taken, unsigned long fallthrough,
			       unsigned long target)
{
	return taken ? target : fallthrough;
}

/*
 * One JCC case: the real macro selects a next PC; compare it to the model.
 * `current`/`target`/`fallthrough` are modelled in a shadow byte-space where
 * running off the end of a function is not needed---each label just records
 * which arm was reached and jumps to the shared epilogue.
 */
static void check_jcc(unsigned cc, unsigned long current, unsigned long target,
		      unsigned cf, unsigned zf, unsigned sf, unsigned of)
{
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	const unsigned long fallthrough = target + 1UL;
	unsigned taken = model_cc_true(cc, cf, zf, sf, of);
	unsigned long got;   /* the address the real macro jumped to */

	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	(void)__x86_sim_ret_addr;
	__x86_cf = (__u8)cf;
	__x86_zf = (__u8)zf;
	__x86_sf = (__u8)sf;
	__x86_of = (__u8)of;

	got = fallthrough; /* default: fall-through */
	goto probe_dispatch;
probe_dispatched:
	{
		unsigned long want = branch_pc((int)taken, fallthrough, target);

		cases++;
		if (got != want) {
			printf("MISMATCH jcc cc=%u cur=%lu tgt=%lu fb=%u "
			       "got=%lu want=%lu\n", cc, current, target,
			       taken, got, want);
			failures++;
		}
	}
	return;

probe_dispatch:
	X86_SIM_X86_JCC(cc, current, target, probe_target);
	goto probe_dispatched;          /* forward arm fell through */
probe_target:
	got = target;
	goto probe_dispatched;
}

/* The routed selector must agree with the ordering oracle at the boundary. */
static void check_direction(void)
{
	static const unsigned long addrs[] = {
		0UL, 1UL, 2UL, 0x100UL, 0x1000UL, 0x1001UL, 0xffffUL,
		0xffffffffUL, 0x100000000UL,
	};
	unsigned i, j;

	for (i = 0; i < sizeof(addrs) / sizeof(addrs[0]); i++) {
		for (j = 0; j < sizeof(addrs) / sizeof(addrs[0]); j++) {
			unsigned got = KPROG_X86_BRANCH_BACKWARD(
				addrs[i], addrs[j]);
			unsigned want = addrs[j] <= addrs[i] ? 1U : 0U;

			cases++;
			if (got != want) {
				printf("MISMATCH backward cur=%lu tgt=%lu "
				       "got=%u want=%u\n", addrs[i], addrs[j],
				       got, want);
				failures++;
			}
		}
		/* The equality boundary is the backward shape. */
		cases++;
		if (KPROG_X86_BRANCH_BACKWARD(addrs[i], addrs[i]) != 1U) {
			printf("MISMATCH backward equality cur=%lu\n",
			       addrs[i]);
			failures++;
		}
		/* A strictly greater target is forward. */
		cases++;
		if (KPROG_X86_BRANCH_BACKWARD(addrs[i], addrs[i] + 1UL) != 0U) {
			printf("MISMATCH forward cur=%lu\n", addrs[i]);
			failures++;
		}
	}
}

int main(void)
{
	static const unsigned cc_codes[] = {
		X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A, X86_CC_S, X86_CC_NS,
		X86_CC_L, X86_CC_GE, X86_CC_LE, X86_CC_G,
		10U, 11U, 16U, 0xffU,   /* unsupported / out-of-range */
	};
	/* Forward edges, equal edges, and backward edges in the same sweep. */
	static const unsigned long pairs[][2] = {
		{ 0x10UL, 0x40UL },   /* forward */
		{ 0x40UL, 0x10UL },   /* backward */
		{ 0x20UL, 0x20UL },   /* equal -> backward */
		{ 0x1000UL, 0x1001UL }, /* adjacent forward */
		{ 0x1001UL, 0x1000UL }, /* adjacent backward */
		{ 0xffffUL, 0UL },    /* wrap-around backward */
	};
	unsigned c;
	unsigned p;
	unsigned fb;

	for (c = 0; c < sizeof(cc_codes) / sizeof(cc_codes[0]); c++)
		for (p = 0; p < sizeof(pairs) / sizeof(pairs[0]); p++)
			for (fb = 0; fb < 16U; fb++)
				check_jcc(cc_codes[c], pairs[p][0], pairs[p][1],
					  fb & 1U, (fb >> 1) & 1U,
					  (fb >> 2) & 1U, (fb >> 3) & 1U);

	check_direction();

	if (failures != 0) {
		printf("x86 branch emit route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 branch emit route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
