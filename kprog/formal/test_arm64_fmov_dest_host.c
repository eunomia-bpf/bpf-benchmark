/*
 * Host cross-check for the generated AArch64 FMOV destination-routing contract.
 *
 * Verifies KPROG_ARM64_FMOV_DEST_VECTOR from generated/arm64_fmov_dest.h against
 * an independent oracle keyed on the direction code's parity and range (never the
 * macro's switch), sweeping the direction over all 256 byte values --- an
 * in-range code must return the oracle routing bit, an out-of-range code must
 * abort with SIGABRT through the generated unsupported arm. Exits non-zero on any
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_fmov_dest_host.c -o /tmp/t_fmd && /tmp/t_fmd
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_FMOV_D_FROM_X 0U
#define ARM64_FMOV_X_FROM_D 1U
#define ARM64_FMOV_S_FROM_W 2U
#define ARM64_FMOV_W_FROM_S 3U
#define ARM64_OP_FMOV 0x23U

#include "generated/arm64_fmov_dest.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent destination-routing oracle keyed on the direction code's parity and
 * range: a direction routes to the vector register exactly when it is one of the
 * four in-range codes with an even parity. Returns -1 for an out-of-range code.
 */
static int dest_oracle(unsigned dir)
{
	if (dir >= 4U)
		return -1;
	return dir % 2U == 0U;
}

/*
 * Fork a child that evaluates the routing macro and exits with the routing bit;
 * the parent requires an in-range code to match the oracle and an out-of-range
 * code to abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned dir)
{
	int want = dest_oracle(dir);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 vector = KPROG_ARM64_FMOV_DEST_VECTOR(dir, abort());

		_exit((int)(vector & 0x1ULL));
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for dir=%u\n", dir);
		return 1;
	}

	if (want < 0) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH out-of-range dir=%u did not abort "
			       "(status=%d)\n", dir, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) || WEXITSTATUS(status) != want) {
		printf("MISMATCH dir=%u status=%d want=%d\n",
		       dir, status, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	unsigned cases = 0, fails = 0;

	for (unsigned dir = 0; dir < 256U; dir++) {
		fails += check_case(dir);
		cases++;
	}

	if (fails) {
		printf("arm64 fmov-dest host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 fmov-dest host cross-check: OK (%u cases)\n", cases);
	return 0;
}
