/*
 * Host cross-check for the generated AArch64 MOV provenance-path contract.
 *
 * Verifies KPROG_ARM64_MOV_PTR_TAG_PATH from generated/arm64_mov.h against an
 * independent oracle that decides tag preservation from the mnemonic class and
 * the access width (never the macro's switch), and sweeps the opcode over all
 * 256 byte values and all four widths --- a known move must return the oracle
 * path, an unknown opcode must abort with SIGABRT through the generated
 * unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mov_host.c -o /tmp/t_mov && /tmp/t_mov
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_MOV_IMM 0x01U
#define ARM64_OP_MOV_REG 0x02U

#include "generated/arm64_width.h"
#include "generated/arm64_mov.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent routing oracle: a register-source move preserves provenance only
 * when the access is doubleword; an immediate move never does. Returns -1 for an
 * opcode outside the family.
 */
static int mov_oracle(unsigned op, unsigned width)
{
	if (op == ARM64_OP_MOV_IMM)
		return 0;
	if (op == ARM64_OP_MOV_REG)
		return width == ARM64_WIDTH_64 ? 1 : 0;
	return -1;
}

/*
 * Fork a child that evaluates the macro and exits with the path decision; the
 * parent requires a known move to match the oracle and an unknown opcode to
 * abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op, unsigned width)
{
	int want = mov_oracle(op, width);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 path = KPROG_ARM64_MOV_PTR_TAG_PATH(op, width, abort());

		_exit((int)(path & 1ULL));
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for op=%#x width=%u\n", op, width);
		return 1;
	}

	if (want < 0) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH unknown op=%#x width=%u did not abort "
			       "(status=%d)\n", op, width, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) || WEXITSTATUS(status) != want) {
		printf("MISMATCH op=%#x width=%u status=%d want=%d\n",
		       op, width, status, want);
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

	for (unsigned w = 0; w < nwidths; w++)
		for (unsigned op = 0; op < 256U; op++) {
			fails += check_case(op, widths[w]);
			cases++;
		}

	if (fails) {
		printf("arm64 mov host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 mov host cross-check: OK (%u cases)\n", cases);
	return 0;
}
