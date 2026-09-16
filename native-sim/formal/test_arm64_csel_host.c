/*
 * Host cross-check for the generated AArch64 conditional-select contract.
 *
 * Verifies KPROG_ARM64_CSEL_VALUE from generated/arm64_csel.h against an
 * independent oracle that computes each arm's two candidate values with
 * architectural arithmetic and selects with a bit mask (never the macro's
 * ternary):
 *   - CSEL:  taken ? src : src2
 *   - CINC:  taken ? src + 1 : src
 *   - CSET:  taken ? 1 : 0
 *   - CSETM: taken ? ~0 : 0
 *   - CINV:  taken ? ~src : src
 *   - CSINV: taken ? src : ~src2
 *   - CSINC: taken ? src : src2 + 1
 *   - CSNEG: taken ? src : -src2
 * It sweeps explicit boundary vectors and both condition outcomes, then a
 * fixed-seed random sweep, and checks that an opcode outside the family aborts
 * with SIGABRT through the generated default arm. Exits non-zero on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_csel_host.c -o /tmp/t_csel && /tmp/t_csel
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

/* Op codes are the ARM64_OP_* architectural numbers the generated header pins,
 * kept local so the oracle is independent of the simulator header. */
#define ARM64_OP_CSEL 28U
#define ARM64_OP_CINC 29U
#define ARM64_OP_CSET 30U
#define ARM64_OP_CINV 52U
#define ARM64_OP_CSINV 61U
#define ARM64_OP_CSINC 62U
#define ARM64_OP_CSETM 68U
#define ARM64_OP_CSNEG 69U

#include "generated/arm64_csel.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Both candidate values per arm, then a bit-mask mux. */
static void csel_candidates(unsigned op, __u64 src, __u64 src2,
			    __u64 *first, __u64 *second)
{
	switch (op) {
	case ARM64_OP_CSEL:
		*first = src;
		*second = src2;
		break;
	case ARM64_OP_CINC:
		*first = src + 1;
		*second = src;
		break;
	case ARM64_OP_CSET:
		*first = 1;
		*second = 0;
		break;
	case ARM64_OP_CSETM:
		*first = ~0ULL;
		*second = 0;
		break;
	case ARM64_OP_CINV:
		*first = ~src;
		*second = src;
		break;
	case ARM64_OP_CSINV:
		*first = src;
		*second = ~src2;
		break;
	case ARM64_OP_CSINC:
		*first = src;
		*second = src2 + 1;
		break;
	case ARM64_OP_CSNEG:
		*first = src;
		*second = (__u64)(-src2);
		break;
	default:
		*first = 0;
		*second = 0;
		break;
	}
}

static __u64 csel_oracle(unsigned op, int taken, __u64 src, __u64 src2)
{
	__u64 first, second;
	__u64 m = taken ? ~0ULL : 0;

	csel_candidates(op, src, src2, &first, &second);
	return (first & m) | (second & ~m);
}

static int check_csel(unsigned op, int taken, __u64 src, __u64 src2)
{
	__u64 res = KPROG_ARM64_CSEL_VALUE(op, src, src2, taken, abort());
	__u64 want = csel_oracle(op, taken, src, src2);

	if (res != want) {
		printf("MISMATCH csel op=%u taken=%d src=%#llx src2=%#llx "
		       "res=%#llx want=%#llx\n",
		       op, taken, src, src2, res, want);
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
		__u64 res = KPROG_ARM64_CSEL_VALUE(9U, 0, 0, 1, abort());

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

static const unsigned ops[] = {
	ARM64_OP_CSEL, ARM64_OP_CINC, ARM64_OP_CSET, ARM64_OP_CSETM,
	ARM64_OP_CINV, ARM64_OP_CSINV, ARM64_OP_CSINC, ARM64_OP_CSNEG,
};

int main(void)
{
	static const __u64 vectors[][2] = {
		{0x0, 0x0},
		{0x1, 0x2},
		{~0ULL, ~0ULL},
		{0x0, ~0ULL},
		{~0ULL, 0x0},
		{0x7fffffffffffffffULL, 0x1},
		{0x8000000000000000ULL, 0x1},
		{0x80000000ULL, 0xffffffffULL},
		{0x1, 0x7fffffffffffffffULL},
		{0xdeadbeefULL, 0xcafebabeULL},
	};
	unsigned cases = 0, fails = 0;
	__u64 state = 0x0123456789abcdefULL;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned t = 0; t < 2; t++)
			for (unsigned k = 0; k < sizeof(ops) / sizeof(ops[0]);
			     k++) {
				fails += check_csel(ops[k], (int)t, vectors[i][0],
						    vectors[i][1]);
				cases++;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 src, src2;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src2 = state;
		for (unsigned k = 0; k < sizeof(ops) / sizeof(ops[0]); k++) {
			fails += check_csel(ops[k], (int)(iter % 2), src, src2);
			cases++;
		}
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 conditional-select host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 conditional-select host cross-check: OK (%u cases)\n",
	       cases);
	return 0;
}
