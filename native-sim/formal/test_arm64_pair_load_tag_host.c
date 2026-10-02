/*
 * Host cross-check for the generated AArch64 pair-load provenance-preservation
 * routing contract.
 *
 * Verifies KPROG_ARM64_PAIR_LOAD_TAG_ROUTE and its ROUTE_LOW/ROUTE_HIGH slot
 * accessors from generated/arm64_pair_load_tag.h against an independent oracle
 * deciding each slot from the access width and that slot's tag class (never the
 * macro's gate); sweeping the opcode over all 256 byte values crossed with the
 * four widths and the four tag-class pairs --- a known pair load must return a
 * mask whose two slot bits match the oracle, an unknown opcode must abort with
 * SIGABRT through the generated unsupported arm. Exits non-zero on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_pair_load_tag_host.c -o /tmp/t_plt && /tmp/t_plt
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_LDP 0x21U
#define ARM64_SIM_TAG_SCALAR 0U

#include "generated/arm64_width.h"
#include "generated/arm64_pair_load_tag.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent pair-load routing oracle keyed on the access width and each slot's
 * tag class: a slot's bit is set exactly at doubleword width and when that slot's
 * tag is not the bare scalar tag. Returns -1 for an opcode outside the family.
 */
static int route_oracle(unsigned op, unsigned width, int lo_scalar, int hi_scalar)
{
	int lo, hi;

	if (op != ARM64_OP_LDP)
		return -1;
	lo = width == ARM64_WIDTH_64 && !lo_scalar;
	hi = width == ARM64_WIDTH_64 && !hi_scalar;
	return lo | (hi << 1);
}

/*
 * Fork a child that evaluates the routing macro and both slot accessors, exiting
 * with the two slot bits; the parent requires a known pair load to match the
 * oracle and an unknown opcode to abort through the generated unsupported arm.
 */
static int check_case(unsigned op, unsigned width, int lo_scalar, int hi_scalar)
{
	unsigned lo_tag = lo_scalar ? ARM64_SIM_TAG_SCALAR : 2U;
	unsigned hi_tag = hi_scalar ? ARM64_SIM_TAG_SCALAR : 3U;
	int want = route_oracle(op, width, lo_scalar, hi_scalar);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 mask = KPROG_ARM64_PAIR_LOAD_TAG_ROUTE(op, lo_tag, hi_tag,
							     width, abort());
		__u64 bits = 0;

		if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_LOW(mask))
			bits |= 1ULL;
		if (KPROG_ARM64_PAIR_LOAD_TAG_ROUTE_HIGH(mask))
			bits |= 2ULL;
		_exit((int)bits);
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for op=%#x\n", op);
		return 1;
	}

	if (want < 0) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH unknown op=%#x did not abort "
			       "(status=%d)\n", op, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) || WEXITSTATUS(status) != want) {
		printf("MISMATCH op=%#x width=%u lo=%d hi=%d status=%d want=%d\n",
		       op, width, lo_scalar, hi_scalar, status, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	const unsigned widths[4] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				     ARM64_WIDTH_32, ARM64_WIDTH_64 };
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 256U; op++) {
		for (unsigned wi = 0; wi < 4U; wi++) {
			for (unsigned lo = 0; lo < 2U; lo++) {
				for (unsigned hi = 0; hi < 2U; hi++) {
					fails += check_case(op, widths[wi], lo, hi);
					cases++;
				}
			}
		}
	}

	if (fails) {
		printf("arm64 pair-load-tag host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 pair-load-tag host cross-check: OK (%u cases)\n", cases);
	return 0;
}
