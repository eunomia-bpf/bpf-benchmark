/*
 * Host cross-check for the generated AArch64 sign-extending-load operand-source
 * contract (generated/arm64_ldrsx_op.h, STEP 0128).
 *
 * Verifies KPROG_ARM64_LDRSX_SXOP against an independent oracle that decides the
 * derived sign-extending opcode from the load opcode's numeric code (never the
 * macro's switch), and sweeps the opcode over all 256 byte values --- a known
 * load must return the oracle's sign opcode, an unknown opcode must abort with
 * SIGABRT through the generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_ldrsx_op_host.c -o /tmp/t_sxop && /tmp/t_sxop
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_OP_LDRSB 0x36U
#define ARM64_OP_LDRSW 0x39U
#define ARM64_OP_LDRSH 0x3fU
#define ARM64_OP_SXTB 0x3cU
#define ARM64_OP_SXTW 0x2fU
#define ARM64_OP_SXTH 0x15U

#include "generated/arm64_ldrsx_op.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent sign-extending-opcode oracle keyed on the numeric load code: a
 * byte load selects SXTB, a word load SXTW, a halfword load SXTH. Returns 0 for
 * an opcode outside the family.
 */
static unsigned ldrsx_sx_oracle(unsigned op)
{
	switch (op) {
	case ARM64_OP_LDRSB:
		return ARM64_OP_SXTB;
	case ARM64_OP_LDRSW:
		return ARM64_OP_SXTW;
	case ARM64_OP_LDRSH:
		return ARM64_OP_SXTH;
	default:
		return 0;
	}
}

/*
 * Fork a child that evaluates the macro and exits with the derived opcode; the
 * parent requires a known load to match the oracle opcode and an unknown opcode
 * to abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op)
{
	unsigned want = ldrsx_sx_oracle(op);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 sx = KPROG_ARM64_LDRSX_SXOP(op, abort());

		_exit((int)(sx & 0xffULL));
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
		printf("arm64 ldrsx op host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 ldrsx op host cross-check: OK (%u cases)\n", cases);
	return 0;
}
