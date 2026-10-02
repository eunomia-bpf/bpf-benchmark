/*
 * Host cross-check for the generated AArch64 plain-load provenance-preservation
 * contract.
 *
 * Verifies KPROG_ARM64_LOAD_TAG_PRESERVE from generated/arm64_load_tag.h against
 * an independent oracle keyed on the access width and the tag class (never the
 * macro's switch), sweeping the opcode over all 256 byte values crossed with the
 * four widths and the two tag classes --- a known load must return the oracle
 * routing bit, an unknown opcode must abort with SIGABRT through the generated
 * unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_load_tag_host.c -o /tmp/t_lt && /tmp/t_lt
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_LOAD 0x1fU
#define ARM64_SIM_TAG_SCALAR 0U

#include "generated/arm64_width.h"
#include "generated/arm64_load_tag.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Independent preservation oracle keyed on the access width and the tag class: a
 * load preserves the memory-read tag exactly at doubleword width and when the tag
 * is not the bare scalar tag. Returns -1 for an opcode outside the family.
 */
static int load_tag_oracle(unsigned op, unsigned width, int tag_is_scalar)
{
	if (op != ARM64_OP_LOAD)
		return -1;
	return width == ARM64_WIDTH_64 && !tag_is_scalar;
}

/*
 * Fork a child that evaluates the macro and exits with the routing bit; the
 * parent requires a known load to match the oracle and an unknown opcode to abort
 * with SIGABRT through the generated unsupported arm.
 */
static int check_case(unsigned op, unsigned width, unsigned tag)
{
	int want = load_tag_oracle(op, width, tag == ARM64_SIM_TAG_SCALAR);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u64 preserve =
			KPROG_ARM64_LOAD_TAG_PRESERVE(op, tag, width, abort());

		_exit((int)(preserve & 0x1ULL));
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for op=%#x\n", op);
		return 1;
	}

	if (want < 0) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH unknown op=%#x did not abort "
			       "(status=%d)\n", op, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) || WEXITSTATUS(status) != want) {
		printf("MISMATCH op=%#x width=%u tag=%u status=%d want=%d\n",
		       op, width, tag, status, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	const unsigned widths[4] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				     ARM64_WIDTH_32, ARM64_WIDTH_64 };
	const unsigned tags[2] = { ARM64_SIM_TAG_SCALAR, 1U };
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 256U; op++) {
		for (unsigned wi = 0; wi < 4U; wi++) {
			for (unsigned ti = 0; ti < 2U; ti++) {
				fails += check_case(op, widths[wi], tags[ti]);
				cases++;
			}
		}
	}

	if (fails) {
		printf("arm64 load-tag host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 load-tag host cross-check: OK (%u cases)\n", cases);
	return 0;
}
