/*
 * Route cross-check for the whole-program control-flow trace contract.
 *
 * Drives the real simulator conditional-transfer macros -- x86 `X86_SIM_X86_JCC`
 * and AArch64 `ARM64_SIM_A64_JCC`, both of which route through the generated
 * direction macros `KPROG_X86_BRANCH_BACKWARD` / `KPROG_ARM64_BRANCH_BACKWARD` --
 * as one edge selector, then folds the emitted selector over multi-edge traces
 * and compares the walked program counter against an independent architectural
 * walk (`taken ? target : pc + 1`). The direction is recomputed per edge from the
 * running program counter, exactly as the generated `walkPolicy` models, so a
 * sim macro that ignores the direction, inverts the taken predicate on either
 * shape, or fails to thread the program counter between edges is caught. Exits
 * non-zero on any mismatch.
 *
 * Build/run (x86 and arm64 headers in one translation unit):
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_control_flow_trace_route_host.c -o /tmp/t_cftr && /tmp/t_cftr
 */

#define X86_SIM_ENABLE_STACK 1
#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"
#include "../arm64/arm64_sim_local_bpf.h"
#include "generated/control_flow_trace.h"

#include <stdio.h>

/* The simulator header expects this hook; the oracle drives only fully
 * supported arms, so the no-op stub is never the reason for a difference. */
static void arm64_sim_unsupported_opcode(void)
{
}

static int failures;
static unsigned long cases;

/* Independent statement of the x86 condition expression, restated from the raw
 * codes rather than the generated table. */
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

/* Independent statement of the AArch64 condition expression. */
static unsigned model_a64_cond(unsigned cond, unsigned n, unsigned z,
			       unsigned c, unsigned v)
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
	case ARM64_COND_AL: return 1U;
	default: return 0U;
	}
}

/* The architectural next PC at one edge: target when taken, the next program
 * counter otherwise. */
static unsigned long arch_edge(int taken, unsigned long pc, unsigned long target)
{
	return taken ? target : pc + 1UL;
}

/* The emitted next PC one real x86 conditional transfer selects. `pc` is the
 * running program counter, so the not-taken continuation is `pc + 1`; the
 * direction (forward fall-through vs backward inverted jump) is chosen by the
 * macro from `pc` and `target`. */
static unsigned long x86_edge_next(unsigned cc, unsigned long pc,
				   unsigned long target, unsigned cf,
				   unsigned zf, unsigned sf, unsigned of)
{
	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	unsigned long got;

	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	(void)__x86_sim_ret_addr;
	__x86_cf = (__u8)cf;
	__x86_zf = (__u8)zf;
	__x86_sf = (__u8)sf;
	__x86_of = (__u8)of;

	got = pc + 1UL; /* forward arm falls through to the next PC */
	goto probe_dispatch;
probe_dispatched:
	return got;

probe_dispatch:
	X86_SIM_X86_JCC(cc, pc, target, probe_target);
	goto probe_dispatched;
probe_target:
	got = target;
	goto probe_dispatched;
}

/* The emitted next PC one real AArch64 conditional transfer selects. */
static unsigned long a64_edge_next(unsigned cond, unsigned long pc,
				   unsigned long target, unsigned n,
				   unsigned z, unsigned c, unsigned v)
{
	ARM64_SIM_L_DECLARE_STATE();
	unsigned long got;

	(void)__a64_lr;
	(void)__a64_v0;
	(void)__a64_v0_hi;
	__a64_n = (__u8)n;
	__a64_z = (__u8)z;
	__a64_c = (__u8)c;
	__a64_v = (__u8)v;

	got = pc + 1UL; /* forward arm falls through to the next PC */
	goto probe_dispatch;
probe_dispatched:
	return got;

probe_dispatch:
	ARM64_SIM_A64_JCC(cond, pc, target, probe_target);
	goto probe_dispatched;
probe_target:
	got = target;
	goto probe_dispatched;
}

static const unsigned long addrs[] = {
	0UL, 1UL, 2UL, 0x100UL, 0x1000UL, 0x1001UL, 0xffffUL, 0x100000000UL,
};

static unsigned long lcg_state = 0x9e3779b9UL;

static unsigned long lcg(void)
{
	lcg_state = lcg_state * 1103515245UL + 12345UL;
	return lcg_state >> 8;
}

/* Fold one real x86 macro over a multi-edge trace and compare against the
 * independent architectural walk. Returns 1 on mismatch. */
static unsigned long x86_walk(const unsigned *cc, unsigned long start,
			      const unsigned char *flags, const unsigned long *target,
			      unsigned len)
{
	unsigned long emitted = start;
	unsigned long arch = start;
	unsigned i;

	for (i = 0; i < len; i++) {
		unsigned cf = flags[4 * i + 0], zf = flags[4 * i + 1];
		unsigned sf = flags[4 * i + 2], of = flags[4 * i + 3];
		int taken = (int)model_cc_true(cc[i], cf, zf, sf, of);

		emitted = x86_edge_next(cc[i], emitted, target[i], cf, zf, sf, of);
		arch = arch_edge(taken, arch, target[i]);
		cases++;
		if (emitted != arch) {
			printf("MISMATCH x86 walk edge=%u cc=%u pc=%lu tgt=%lu "
			       "emitted=%lu arch=%lu\n", i, cc[i], emitted,
			       target[i], emitted, arch);
			return 1;
		}
	}
	return 0;
}

/* Fold one real AArch64 macro over a multi-edge trace and compare against the
 * independent architectural walk. */
static unsigned long a64_walk(const unsigned *cond, unsigned long start,
			      const unsigned char *flags, const unsigned long *target,
			      unsigned len)
{
	unsigned long emitted = start;
	unsigned long arch = start;
	unsigned i;

	for (i = 0; i < len; i++) {
		unsigned n = flags[i], z = flags[len + i];
		unsigned c = flags[2 * len + i], v = flags[3 * len + i];
		int taken = (int)model_a64_cond(cond[i], n, z, c, v);

		emitted = a64_edge_next(cond[i], emitted, target[i], n, z, c, v);
		arch = arch_edge(taken, arch, target[i]);
		cases++;
		if (emitted != arch) {
			printf("MISMATCH a64 walk edge=%u cond=%u pc=%lu tgt=%lu "
			       "emitted=%lu arch=%lu\n", i, cond[i], emitted,
			       target[i], emitted, arch);
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	static const unsigned x86_cc[] = {
		X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A, X86_CC_S, X86_CC_NS,
		X86_CC_L, X86_CC_GE, X86_CC_LE, X86_CC_G, 10U, 16U,
	};
	static const unsigned a64_conds[] = {
		ARM64_COND_EQ, ARM64_COND_NE, ARM64_COND_CS, ARM64_COND_CC,
		ARM64_COND_MI, ARM64_COND_PL, ARM64_COND_VS, ARM64_COND_VC,
		ARM64_COND_HI, ARM64_COND_LS, ARM64_COND_GE, ARM64_COND_LT,
		ARM64_COND_GT, ARM64_COND_LE, ARM64_COND_AL, 15U,
	};
	unsigned x86_ccs[64], a64_conds_use[64];
	unsigned char x86_flags[256], a64_flags[256];
	unsigned long target[64];
	unsigned len, t, trial;

	/* The generated sequential step is the architectural one. */
	if (KPROG_CONTROL_FLOW_SEQUENTIAL_STEP != 1U) {
		printf("MISMATCH sequential step = %u\n",
		       (unsigned)KPROG_CONTROL_FLOW_SEQUENTIAL_STEP);
		failures++;
	}

	for (trial = 0; trial < 256; trial++) {
		len = 1U + (unsigned)(lcg() % 12U);
		for (t = 0; t < len; t++) {
			x86_ccs[t] = x86_cc[lcg() % 16U];
			for (unsigned k = 0; k < 4U; k++)
				x86_flags[4 * t + k] = (unsigned char)(lcg() & 1U);
			a64_conds_use[t] = a64_conds[lcg() % 16U];
			a64_flags[t] = (unsigned char)(lcg() & 1U);
			a64_flags[len + t] = (unsigned char)(lcg() & 1U);
			a64_flags[2 * len + t] = (unsigned char)(lcg() & 1U);
			a64_flags[3 * len + t] = (unsigned char)(lcg() & 1U);
			target[t] = addrs[lcg() % 8U];
		}
		failures += (int)x86_walk(x86_ccs, addrs[trial % 8U], x86_flags,
					  target, len);
		failures += (int)a64_walk(a64_conds_use, addrs[trial % 8U],
					  a64_flags, target, len);
	}

	if (failures != 0) {
		printf("control flow trace route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("control flow trace route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
}
