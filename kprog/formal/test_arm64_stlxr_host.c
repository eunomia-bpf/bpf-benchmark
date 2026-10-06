/*
 * Host cross-check for the generated AArch64 STLXR exclusive-store status
 * contract.
 *
 * Verifies KPROG_ARM64_STLXR_VALUE from generated/arm64_stlxr.h against an
 * independent oracle that derives the destination width mask from a shift of one
 * (never the macro's width-mask ladder) and forms the success code as that mask
 * with itself subtracted, requiring it to be zero at every width. It sweeps the
 * opcode over all 256 byte values and all four destination widths --- a known
 * opcode must return the zero status, an unknown byte must abort with SIGABRT
 * through the generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_stlxr_host.c -o /tmp/t_stlxr && /tmp/t_stlxr
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_STLXR 0x38U

#include "generated/arm64_width.h"
#include "generated/arm64_stlxr.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent width mask: one shifted left by the destination bit count. */
static __u64 width_mask(unsigned width)
{
	unsigned bits = width == ARM64_WIDTH_8 ? 8U :
			width == ARM64_WIDTH_16 ? 16U :
			width == ARM64_WIDTH_32 ? 32U : 64U;

	return bits >= 64U ? ~0ULL : (1ULL << bits) - 1ULL;
}

/* Independent store-exclusive success status: the width mask minus itself. */
static __u64 stlxr_oracle(unsigned width)
{
	__u64 mask = width_mask(width);

	return mask - mask;
}

/*
 * Fork a child that evaluates the macro and exits with the status; the parent
 * requires a known opcode to return the oracle status and an unknown opcode to
 * abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op, unsigned width)
{
	pid_t pid;
	int status;
	int known = (op == ARM64_OP_STLXR);

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 res = KPROG_ARM64_STLXR_VALUE(op, width, abort());

		_exit((int)(res & 0xffULL));
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for op=%#x width=%u\n", op, width);
		return 1;
	}

	if (!known) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH unknown op=%#x width=%u did not abort "
			       "(status=%d)\n", op, width, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) ||
	    (__u64)WEXITSTATUS(status) != stlxr_oracle(width)) {
		printf("MISMATCH op=%#x width=%u status=%d want=%llu\n",
		       op, width, status, stlxr_oracle(width));
		return 1;
	}
	return 0;
}

static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	unsigned nwidths = sizeof(widths) / sizeof(widths[0]);

	/* The success status must be the zero code at every width. */
	for (unsigned w = 0; w < nwidths; w++) {
		__u64 res = KPROG_ARM64_STLXR_VALUE(ARM64_OP_STLXR, widths[w],
						    abort());

		if (res != 0) {
			printf("MISMATCH op=STLXR width=%u res=%#llx\n",
			       widths[w], res);
			fails++;
		}
		cases++;
	}

	/* Exhaustive opcode-byte sweep across every destination width. */
	for (unsigned w = 0; w < nwidths; w++)
		for (unsigned op = 0; op < 256U; op++) {
			fails += check_case(op, widths[w]);
			cases++;
		}

	if (fails) {
		printf("arm64 stlxr host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 stlxr host cross-check: OK (%u cases)\n", cases);
	return 0;
}
