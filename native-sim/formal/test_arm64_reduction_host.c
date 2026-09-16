/*
 * Host cross-check for the generated AArch64 byte-lane reduction (CNT/UADDLV)
 * contract.
 *
 * Verifies KPROG_ARM64_REDUCTION_VALUE from generated/arm64_reduction.h against
 * an independent oracle that walks the eight bits of each byte lane directly
 * (never the macro's builtin popcount):
 *   CNT:    byte i of the result = number of set bits among bits 8i..8i+7
 *   UADDLV: result = sum over bytes of the byte value
 * It sweeps boundary vectors over both reductions, then a fixed-seed random
 * sweep, and checks that an opcode outside the two aborts with SIGABRT through
 * the generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_reduction_host.c -o /tmp/t_red && /tmp/t_red
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_OP_CNT 0x24U
#define ARM64_OP_UADDLV 0x25U

#include "generated/arm64_reduction.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent bit walk: count the set bits of the byte lane `lane`. */
static unsigned lane_popcount(__u64 value, unsigned lane)
{
	unsigned n = 0;

	for (unsigned b = 0; b < 8; b++)
		n += (unsigned)((value >> (8 * lane + b)) & 1ULL);
	return n;
}

static __u64 reduction_oracle(unsigned op, __u64 value)
{
	__u64 out = 0;

	if (op == ARM64_OP_CNT) {
		for (unsigned lane = 0; lane < 8; lane++)
			out |= (__u64)lane_popcount(value, lane) << (8 * lane);
		return out;
	}
	for (unsigned lane = 0; lane < 8; lane++)
		out += (value >> (8 * lane)) & 0xffULL;
	return out;
}

static int check_reduction(unsigned op, __u64 value)
{
	__u64 res = KPROG_ARM64_REDUCTION_VALUE(op, value, abort());
	__u64 want = reduction_oracle(op, value);

	if (res != want) {
		printf("MISMATCH op=%u value=%#llx res=%#llx want=%#llx\n",
		       op, value, res, want);
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
		__u64 res = KPROG_ARM64_REDUCTION_VALUE(0U, 0, abort());

		_exit(res == 0 ? 0 : 1);
	}

	if (waitpid(pid, &status, 0) != pid ||
	    !(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
		printf("MISMATCH unsupported op did not abort (status=%d)\n",
		       status);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0x8040201008040201ULL,
	0xffULL, 0xff00ff00ff00ff00ULL, 0x1ULL, 0x8080808080808080ULL,
};
static const unsigned ops[] = { ARM64_OP_CNT, ARM64_OP_UADDLV };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x7c3e9d15a2b8064fULL;

	for (unsigned o = 0; o < sizeof(ops) / sizeof(ops[0]); o++)
		for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++) {
			fails += check_reduction(ops[o], values[v]);
			cases++;
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check_reduction(ops[iter % 2], state);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 reduction host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 reduction host cross-check: OK (%u cases)\n", cases);
	return 0;
}
