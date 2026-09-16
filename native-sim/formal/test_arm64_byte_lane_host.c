/*
 * Host cross-check for the generated AArch64 byte-lane extraction contract.
 *
 * Verifies KPROG_ARM64_BYTE_AT from generated/arm64_byte_lane.h against an
 * independent oracle that recovers each lane through a byte pointer into the
 * value (never the macro's shift): lane i is `((const __u8 *)&value)[i]` on a
 * little-endian host. It sweeps boundary words over all eight lanes, then a
 * fixed-seed random sweep, and checks that a lane outside 0..7 aborts with
 * SIGABRT through the generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_byte_lane_host.c -o /tmp/t_bl && /tmp/t_bl
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/arm64_byte_lane.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent oracle: read the lane through the value's byte view. */
static __u8 lane_oracle(__u64 value, unsigned lane)
{
	const __u8 *bytes = (const __u8 *)&value;

	return bytes[lane];
}

static int check_lane(unsigned lane, __u64 value)
{
	__u8 res = KPROG_ARM64_BYTE_AT(lane, value, abort());
	__u8 want = lane_oracle(value, lane);

	if (res != want) {
		printf("MISMATCH lane=%u value=%#llx res=%#x want=%#x\n",
		       lane, value, res, want);
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
		__u8 res = KPROG_ARM64_BYTE_AT(8U, 0, abort());

		_exit(res == 0 ? 0 : 1);
	}

	if (waitpid(pid, &status, 0) != pid ||
	    !(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
		printf("MISMATCH unsupported lane did not abort (status=%d)\n",
		       status);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0xff00ff00ff00ff00ULL,
	0x8040201008040201ULL, 0x00000000000000ffULL, 0xff00000000000000ULL,
};

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0xc4a1f70e95d3826bULL;

	for (unsigned lane = 0; lane < 8; lane++)
		for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++) {
			fails += check_lane(lane, values[v]);
			cases++;
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check_lane(iter % 8, state);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 byte lane host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 byte lane host cross-check: OK (%u cases)\n", cases);
	return 0;
}
