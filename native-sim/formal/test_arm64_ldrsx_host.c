/*
 * Host cross-check for the generated AArch64 sign-extending-load width contract.
 *
 * Verifies KPROG_ARM64_LDRSX_LOAD_WIDTH from generated/arm64_ldrsx.h against an
 * independent oracle keyed on the opcode's numeric code (never the macro's
 * switch), and sweeps the opcode over all 256 byte values --- a known load must
 * return the oracle width, an unknown opcode must abort with SIGABRT through the
 * generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_ldrsx_host.c -o /tmp/t_ldrsx && /tmp/t_ldrsx
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_LDRSB 0x36U
#define ARM64_OP_LDRSW 0x39U
#define ARM64_OP_LDRSH 0x3fU

#include "generated/arm64_width.h"
#include "generated/arm64_ldrsx.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent load-width oracle keyed on the numeric opcode code: a byte load
 * reads a byte, a halfword load a halfword, a word load a word. Returns 0 for an
 * opcode outside the family.
 */
static unsigned ldrsx_oracle(unsigned op)
{
	switch (op) {
	case ARM64_OP_LDRSB:
		return ARM64_WIDTH_8;
	case ARM64_OP_LDRSW:
		return ARM64_WIDTH_32;
	case ARM64_OP_LDRSH:
		return ARM64_WIDTH_16;
	default:
		return 0;
	}
}

/*
 * Fork a child that evaluates the macro and exits with the load width; the
 * parent requires a known load to match the oracle width and an unknown opcode
 * to abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op)
{
	unsigned want = ldrsx_oracle(op);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 width = KPROG_ARM64_LDRSX_LOAD_WIDTH(op, abort());

		_exit((int)(width & 0xffULL));
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for op=%#x\n", op);
		return 1;
	}

	if (want == 0) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH unknown op=%#x did not abort "
			       "(status=%d)\n", op, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) || (unsigned)WEXITSTATUS(status) != want) {
		printf("MISMATCH op=%#x status=%d want=%u\n",
		       op, status, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 256U; op++) {
		fails += check_case(op);
		cases++;
	}

	if (fails) {
		printf("arm64 ldrsx host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 ldrsx host cross-check: OK (%u cases)\n", cases);
	return 0;
}
