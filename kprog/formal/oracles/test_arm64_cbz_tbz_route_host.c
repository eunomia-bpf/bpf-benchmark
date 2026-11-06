/*
 * Host cross-check for the AArch64 simulator's four remaining branch
 * *emitters*: CBZ, CBNZ, TBZ and TBNZ.
 *
 * Why this host exists. Step 0528 executed `ARM64_SIM_A64_JCC` and found it had
 * never been driven, while the x86 twin had. The same file defines three more
 * emitters -- `CBZ_IMPL`, `TBZ_IMPL` and the wrappers that select their kind
 * through `KPROG_ARM64_BRANCH_TEST` -- and *none* of them is executed by any
 * host. The x86 simulator has no counterpart at all, so there was not even a
 * sibling oracle to notice the absence.
 *
 * These differ from the condition-code emitters in where the predicate comes
 * from: not from NZCV but from the register itself -- zero-ness for CBZ/CBNZ,
 * a single bit for TBZ/TBNZ. That makes two independent things able to go
 * wrong, and both silent: the test could select the wrong predicate (branch on
 * bit 3 instead of bit 5), and the emitter could invert it or take the wrong
 * arm on the backward edge.
 *
 * What is checked, for each of the four kinds, both edge directions, and
 * operands chosen so that the tested bit and the zero-ness differ from each
 * other: the address the emitted code arrives at equals the architectural
 * model -- target when the test holds, fall-through otherwise.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_cbz_tbz_route_host.c -o build/test_arm64_cbz_tbz_route_host &&
 *   ./build/test_arm64_cbz_tbz_route_host
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

#define DECL_STATE()                                                       \
	ARM64_SIM_L_DECLARE_STATE();                                       \
	__u8 __a64_sim_abi_kind = KPROG_ABI_KIND_XDP;                      \
	(void)__a64_sim_abi_kind;                                          \
	ARM64_SIM_L_DECLARE_STACK();                                       \
	(void)__a64_lr;                                                     \
	(void)__a64_v0;                                                     \
	(void)__a64_v0_hi;                                                 \
	(void)__a64_sp

/* One drive of CBZ/CBNZ through the real macro; returns the arrival address. */
static unsigned long long probe_cb(unsigned kind, unsigned long long value,
				   unsigned long long current,
				   unsigned long long target)
{
	unsigned long long got;
	DECL_STATE();

	__a64_x5.x = value;
	__a64_x5_tag = ARM64_SIM_TAG_SCALAR;
	goto dispatch;

arrived:
	got = target;
	return got;

dispatch:
	if (kind == KPROG_ARM64_BRANCH_CBZ)
		ARM64_SIM_A64_CBZ(ARM64_X5, current, target, arrived);
	else
		ARM64_SIM_A64_CBNZ(ARM64_X5, current, target, arrived);
	got = 0xC0DEULL;
	return got;
}

/* One drive of TBZ/TBNZ. */
static unsigned long long probe_tb(unsigned kind, unsigned long long value,
				   unsigned bit, unsigned long long current,
				   unsigned long long target)
{
	unsigned long long got;
	DECL_STATE();

	__a64_x5.x = value;
	__a64_x5_tag = ARM64_SIM_TAG_SCALAR;
	goto dispatch;

arrived:
	got = target;
	return got;

dispatch:
	if (kind == KPROG_ARM64_BRANCH_TBZ)
		ARM64_SIM_A64_TBZ(ARM64_X5, bit, current, target, arrived);
	else
		ARM64_SIM_A64_TBNZ(ARM64_X5, bit, current, target, arrived);
	got = 0xBDEFULL;
	return got;
}

int main(void)
{
	static const unsigned long long values[] = {
		0ULL, 1ULL, 2ULL, 0x20ULL, 0x24ULL, 0xffULL,
		0x100000000ULL, 0x8000000000000000ULL,
		0x123456789abcdefULL, 0xffffffffffffffffULL,
	};
	static const unsigned bits[] = { 0, 1, 5, 63 };
	static const unsigned long long addrs[][2] = {
		{ 100, 200 },   /* forward */
		{ 100, 100 },   /* equal */
		{ 200, 100 },   /* backward */
	};
	unsigned vi, bi, ai, kind;
	int seen_forward = 0, seen_backward = 0;

	for (kind = 0; kind < 4U; kind++)
		for (vi = 0; vi < sizeof(values) / sizeof(values[0]); vi++)
			for (bi = 0; bi < sizeof(bits) / sizeof(bits[0]); bi++)
				for (ai = 0;
				     ai < sizeof(addrs) / sizeof(addrs[0]);
				     ai++) {
					unsigned long long v = values[vi];
					unsigned bit = bits[bi];
					unsigned long long current = addrs[ai][0];
					unsigned long long target = addrs[ai][1];
					unsigned long long fallthrough;
					int taken;
					unsigned long long want, got;

					/* The two shapes need distinct sentinels
					 * so a wrong fall-through shows. */
					fallthrough = kind < 2U ? 0xC0DEULL
								: 0xBDEFULL;

					switch (kind) {
					case KPROG_ARM64_BRANCH_CBZ:
						taken = (v == 0);
						break;
					case KPROG_ARM64_BRANCH_CBNZ:
						taken = (v != 0);
						break;
					case KPROG_ARM64_BRANCH_TBZ:
						taken = ((v >> (bit & 63U)) & 1ULL)
							== 0;
						break;
					default:
						taken = ((v >> (bit & 63U)) & 1ULL)
							== 1;
						break;
					}
					want = taken ? target : fallthrough;

					if (kind < 2U)
						got = probe_cb(kind, v, current,
							       target);
					else
						got = probe_tb(kind, v, bit, current,
							       target);

					cases++;
					if (target <= current)
						seen_backward = 1;
					else
						seen_forward = 1;

					if (got != want) {
						printf("MISMATCH kind=%u v=%#llx "
						       "bit=%u cur=%llu tgt=%llu: "
						       "arrived %#llx want %#llx\n",
						       kind,
						       (unsigned long long)v,
						       bit, current, target,
						       (unsigned long long)got,
						       (unsigned long long)want);
						failures++;
					}
				}

	/* Both edge shapes must have been exercised, and all four kinds. */
	cases++;
	if (!seen_forward || !seen_backward) {
		printf("one edge shape was never exercised\n");
		failures++;
	}

	if (failures) {
		printf("arm64 cbz/tbz route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 cbz/tbz route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}