/*
 * Host cross-check for the generated AArch64 ALU result contract.
 *
 * Verifies KPROG_ALU64_RESULT from generated/arm64_alu_result.h against an
 * independent oracle using plain unsigned __u64 expressions:
 *   - ADD: a + b
 *   - SUB: a - b
 *   - AND: a & b
 *   - BIC: a & ~b
 *   - EOR: a ^ b
 *   - ORR: a | b
 * (unsigned 64-bit wraparound is the architectural semantics). Runs explicit
 * boundary vectors plus a fixed-seed random sweep over all six ops, and
 * proves the macro's default branch invokes the UNSUPPORTED argument, i.e. an
 * unsupported op code must not silently yield 0. Exits non-zero on any
 * mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_alu_result_host.c -o /tmp/t_alu_host && /tmp/t_alu_host
 */
typedef unsigned long long __u64;

#include "generated/arm64_alu_result.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Op codes 0..5 track the ARM64_ALU_* table but are kept local so the oracle
 * is independent of generated/arm64_decode.h. */
#define ALU_ADD 0U
#define ALU_SUB 1U
#define ALU_AND 2U
#define ALU_BIC 3U
#define ALU_EOR 4U
#define ALU_ORR 5U

static __u64 alu_oracle(unsigned op, __u64 a, __u64 b)
{
	switch (op) {
	case ALU_ADD:
		return a + b;
	case ALU_SUB:
		return a - b;
	case ALU_AND:
		return a & b;
	case ALU_BIC:
		return a & ~b;
	case ALU_EOR:
		return a ^ b;
	case ALU_ORR:
		return a | b;
	}
	return 0;
}

static int check_alu(unsigned op, __u64 lhs, __u64 rhs)
{
	__u64 res = KPROG_ALU64_RESULT(op, lhs, rhs, abort());
	__u64 want = alu_oracle(op, lhs, rhs);

	if (res != want) {
		printf("MISMATCH alu op=%u lhs=%#llx rhs=%#llx res=%#llx want=%#llx\n",
		       op, lhs, rhs, res, want);
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
		__u64 res = KPROG_ALU64_RESULT(6U, 0, 0, abort());

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

int main(void)
{
	static const __u64 vectors[][2] = {
		{0x0, 0x0},
		{0x1, 0x2},
		{0x2, 0x1},
		{~0ULL, 0x1},
		{0x0, 0x1},
		{0x1, 0x0},
		{0x8000000000000000ULL, 0x8000000000000000ULL},
		{0x7fffffffffffffffULL, 0x8000000000000000ULL},
		{0x00000000ffffffffULL, 0x00000000ffffffffULL},
		{0xffffffffULL, 0x00000000ffffffffULL},
		{0x00000000ffffffffULL, 0xffffffffULL},
		{~0ULL, ~0ULL},
	};
	unsigned cases = 0, fails = 0;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned op = ALU_ADD; op <= ALU_ORR; op++) {
			fails += check_alu(op, vectors[i][0], vectors[i][1]);
			cases++;
		}

	__u64 state = 0x12345678ULL;
	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 a, b;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		a = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		b = state;
		for (unsigned op = ALU_ADD; op <= ALU_ORR; op++) {
			fails += check_alu(op, a, b);
			cases++;
		}
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 alu result host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 alu result host cross-check: OK (%u cases)\n", cases);
	return 0;
}
