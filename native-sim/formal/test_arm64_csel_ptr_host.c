/*
 * Host cross-check for the generated AArch64 conditional-select pointer-path
 * contract (generated/arm64_csel_ptr.h).
 *
 * Verifies KPROG_ARM64_CSEL_PTR_TAG_PATH against an independent oracle that
 * decides the pointer path from the opcode class and the access width (never the
 * macro's switch), sweeping the opcode over all 256 byte values and all four
 * widths --- a known family opcode must return the oracle path, an opcode outside
 * the family must abort with SIGABRT through the generated unsupported arm.
 * Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_csel_ptr_host.c -o /tmp/t_cp && /tmp/t_cp
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_CSEL 0x1cU
#define ARM64_OP_CINC 0x1dU
#define ARM64_OP_CSET 0x1eU
#define ARM64_OP_CINV 0x34U
#define ARM64_OP_CSINV 0x3dU
#define ARM64_OP_CSINC 0x3eU
#define ARM64_OP_CSETM 0x44U
#define ARM64_OP_CSNEG 0x45U

#include "generated/arm64_csel_ptr.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent pointer-path oracle: only the plain CSEL preserves provenance, and
 * only at doubleword width; every other family member drops the tag at any
 * width. Returns -1 for an opcode outside the eight-member family.
 */
static int csel_ptr_oracle(unsigned op, unsigned width)
{
	switch (op) {
	case ARM64_OP_CSEL:
		return width == ARM64_WIDTH_64 ? 1 : 0;
	case ARM64_OP_CINC:
	case ARM64_OP_CSET:
	case ARM64_OP_CINV:
	case ARM64_OP_CSINV:
	case ARM64_OP_CSINC:
	case ARM64_OP_CSETM:
	case ARM64_OP_CSNEG:
		return 0;
	default:
		return -1;
	}
}

/*
 * Fork a child that evaluates the macro and exits with the path decision; the
 * parent requires a family opcode to match the oracle and a non-family opcode to
 * abort with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op, unsigned width)
{
	int want = csel_ptr_oracle(op, width);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 path = KPROG_ARM64_CSEL_PTR_TAG_PATH(op, width, abort());

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
		printf("arm64 csel-ptr host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 csel-ptr host cross-check: OK (%u cases)\n", cases);
	return 0;
}
