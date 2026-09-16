/*
 * Host cross-check for the generated AArch64 FMOV direction contract.
 *
 * Verifies KPROG_ARM64_FMOV_VALUE from generated/arm64_fmov.h against an
 * independent oracle that keys the selection off a separate direction table
 * (never the macro's switch): the D_FROM_X / S_FROM_W directions select the
 * source register, the X_FROM_D / W_FROM_S directions keep v0. It sweeps the
 * four directions over a value table, then a fixed-seed random sweep, and checks
 * that a direction outside 0..3 aborts with SIGABRT through the generated
 * unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_fmov_host.c -o /tmp/t_fmov && /tmp/t_fmov
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_FMOV_D_FROM_X 0U
#define ARM64_FMOV_X_FROM_D 1U
#define ARM64_FMOV_S_FROM_W 2U
#define ARM64_FMOV_W_FROM_S 3U

#include "generated/arm64_fmov.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent direction table: 1 = vector destination (select src),
 * 0 = register destination (keep v0). */
static const int vector_destination[4] = { 1, 0, 1, 0 };

static __u64 fmov_oracle(unsigned dir, __u64 v0, __u64 src)
{
	return vector_destination[dir] ? src : v0;
}

static int check_fmov(unsigned dir, __u64 v0, __u64 src)
{
	__u64 res = KPROG_ARM64_FMOV_VALUE(dir, v0, src, abort());
	__u64 want = fmov_oracle(dir, v0, src);

	if (res != want) {
		printf("MISMATCH dir=%u v0=%#llx src=%#llx res=%#llx want=%#llx\n",
		       dir, v0, src, res, want);
		return 1;
	}
	return 0;
}

static int check_unsupported_aborts(void)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 res = KPROG_ARM64_FMOV_VALUE(4U, 0, 0, abort());

		_exit(res == 0 ? 0 : 1);
	}

	if (waitpid(pid, &status, 0) != pid ||
	    !(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
		printf("MISMATCH unsupported direction did not abort (status=%d)\n",
		       status);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0xffffffff00000000ULL,
	0x8000000000000000ULL, 0x123456789abcdef0ULL,
};

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x4e8b1d63f2079ac5ULL;

	for (unsigned d = 0; d < 4; d++)
		for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
			for (unsigned s = 0;
			     s < sizeof(values) / sizeof(values[0]); s++) {
				fails += check_fmov(d, values[v], values[s]);
				cases++;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 v0, src;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		v0 = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src = state;
		fails += check_fmov(iter % 4, v0, src);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 fmov host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 fmov host cross-check: OK (%u cases)\n", cases);
	return 0;
}
