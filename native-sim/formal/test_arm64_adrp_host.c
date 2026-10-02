/*
 * Host cross-check for the generated AArch64 ADRP relocation-tag selection
 * contract.
 *
 * Verifies KPROG_ARM64_ADRP_TAG from generated/arm64_adrp.h against an
 * independent oracle that classifies the opcode as GOT/RODATA (never the macro's
 * tag ladder), requires the two kinds to be distinct and inside the
 * ARM64_SIM_TAG_* range, and exhaustively drives all 256 opcode bytes: a known
 * kind must return the oracle's tag and an unknown byte must abort with SIGABRT
 * through the generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_adrp_host.c -o /tmp/t_adrp && /tmp/t_adrp
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_OP_ADRP_GOT 0x26U
#define ARM64_OP_ADRP_RODATA 0x27U
#define ARM64_SIM_TAG_RELOC_ADDR 7U
#define ARM64_SIM_TAG_RODATA_ADDR 8U

#include "generated/arm64_adrp.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent classification: the GOT form is the relocation-address tag and
 * the RODATA form is one higher, inside the ARM64_SIM_TAG_* table. */
static int is_got_op(unsigned op)
{
	if (op == ARM64_OP_ADRP_GOT)
		return 1;
	if (op == ARM64_OP_ADRP_RODATA)
		return 0;
	return -1;
}

static __u8 adrp_tag_oracle(unsigned op)
{
	int got = is_got_op(op);

	if (got < 0)
		abort();

	return (__u8)(got ? ARM64_SIM_TAG_RELOC_ADDR : ARM64_SIM_TAG_RODATA_ADDR);
}

/*
 * Exhaustive opcode-byte sweep. For each of the 256 opcode values, fork a child
 * that evaluates the macro and exits with the selected tag; the parent requires
 * a known kind to equal the independent oracle and an unknown kind to abort with
 * SIGABRT through the generated unsupported arm.
 */
static int check_opcode_byte(unsigned op)
{
	int want_got = is_got_op(op);
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0) {
		printf("MISMATCH fork failed\n");
		return 1;
	}
	if (pid == 0) {
		__u8 tag = KPROG_ARM64_ADRP_TAG(op, abort());

		_exit(tag);
	}

	if (waitpid(pid, &status, 0) != pid) {
		printf("MISMATCH waitpid failed for op=%#x\n", op);
		return 1;
	}

	if (want_got < 0) {
		if (!(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
			printf("MISMATCH unknown op=%#x did not abort "
			       "(status=%d)\n", op, status);
			return 1;
		}
		return 0;
	}

	if (!WIFEXITED(status) || WEXITSTATUS(status) != adrp_tag_oracle(op)) {
		printf("MISMATCH known op=%#x status=%d\n", op, status);
		return 1;
	}
	return 0;
}

int main(void)
{
	unsigned cases = 0, fails = 0;

	if (KPROG_ARM64_ADRP_TAG(ARM64_OP_ADRP_GOT, abort()) ==
	    KPROG_ARM64_ADRP_TAG(ARM64_OP_ADRP_RODATA, abort())) {
		printf("MISMATCH GOT and RODATA tags collide\n");
		fails++;
	}
	cases++;

	for (unsigned op = 0; op < 256U; op++) {
		fails += check_opcode_byte(op);
		cases++;
	}

	if (fails) {
		printf("arm64 adrp host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 adrp host cross-check: OK (%u cases)\n", cases);
	return 0;
}
