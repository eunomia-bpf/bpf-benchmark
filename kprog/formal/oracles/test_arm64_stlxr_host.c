/* Status encoding must retain both explicit outcomes at every width.
 * Unknown opcode bytes still abort; a constant-success implementation fails.
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
#include "test_core_dumps.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Fork a child that evaluates the macro and exits with the status; the parent
 * requires a known opcode to return the oracle status and an unknown opcode to
 * abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op, unsigned width, unsigned failure)
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
		__u64 res = KPROG_ARM64_STLXR_VALUE(op, width, failure, abort());

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
	    (__u64)WEXITSTATUS(status) != failure) {
		printf("MISMATCH op=%#x width=%u status=%d want=%u\n",
		       op, width, status, failure);
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

	/* Both environment outcomes must survive every destination width. */
	for (unsigned failure = 0; failure < 2; failure++)
	for (unsigned w = 0; w < nwidths; w++) {
		__u64 res = KPROG_ARM64_STLXR_VALUE(ARM64_OP_STLXR, widths[w], failure, abort());

		if (res != failure) {
			printf("MISMATCH op=STLXR width=%u res=%#llx\n",
			       widths[w], res);
			fails++;
		}
		cases++;
	}

	/* Exhaustive opcode-byte sweep across every destination width. */
	for (unsigned failure = 0; failure < 2; failure++)
	for (unsigned w = 0; w < nwidths; w++)
		for (unsigned op = 0; op < 256U; op++) {
			fails += check_case(op, widths[w], failure);
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
