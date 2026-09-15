/*
 * Host cross-check for the generated AArch64 multiply-family value contract.
 *
 * Verifies KPROG_ARM64_MUL_VALUE from generated/arm64_mul.h against an
 * independent oracle:
 *   - MADD:   c + a * b                (unsigned 64-bit wraparound)
 *   - MSUB:   c - a * b
 *   - MUL:    a * b
 *   - UMULL:  (__u64)(__u32)a * (__u64)(__u32)b
 *   - UDIV:   b ? a / b : 0            (architectural divide-by-zero result)
 *   - UMULH:  the high word of the exact 128-bit product a * b
 *   - UMADDL: (__u64)(__u32)a * (__u64)(__u32)b + c
 *   - SMADDL: (__u64)((__s64)(__s32)a * (__s64)(__s32)b + (__s64)c)
 * (unsigned 64-bit wraparound is the architectural semantics). The UMULH oracle
 * is architectural: it reads the high word of an `unsigned __int128` product,
 * never a partial-product ladder. Runs explicit boundary vectors plus a
 * fixed-seed random sweep over all eight ops, and proves the macro's default
 * branch invokes the UNSUPPORTED argument, i.e. an unsupported op code must not
 * silently yield 0. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mul_host.c -o /tmp/t_mul_host && /tmp/t_mul_host
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
#define ARM64_OP_MADD 10U
#define ARM64_OP_MSUB 11U
#define ARM64_OP_MUL 12U
#define ARM64_OP_UMULL 13U
#define ARM64_OP_UDIV 14U
#define ARM64_OP_UMULH 46U
#define ARM64_OP_UMADDL 59U
#define ARM64_OP_SMADDL 64U

#include "generated/arm64_mul.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static __u64 mul_oracle(unsigned op, __u64 a, __u64 b, __u64 c)
{
	switch (op) {
	case ARM64_OP_MADD:
		return c + a * b;
	case ARM64_OP_MSUB:
		return c - a * b;
	case ARM64_OP_MUL:
		return a * b;
	case ARM64_OP_UMULL:
		return (__u64)(__u32)a * (__u64)(__u32)b;
	case ARM64_OP_UDIV:
		return b ? a / b : 0;
	case ARM64_OP_UMULH:
		return (__u64)(((unsigned __int128)a * (unsigned __int128)b) >> 64);
	case ARM64_OP_UMADDL:
		return (__u64)(__u32)a * (__u64)(__u32)b + c;
	case ARM64_OP_SMADDL:
		return (__u64)((__s64)(__s32)a * (__s64)(__s32)b + (__s64)c);
	}
	return 0;
}

static int check_mul(unsigned op, __u64 lhs, __u64 rhs, __u64 addend)
{
	__u64 res = KPROG_ARM64_MUL_VALUE(op, lhs, rhs, addend, abort());
	__u64 want = mul_oracle(op, lhs, rhs, addend);

	if (res != want) {
		printf("MISMATCH mul op=%u lhs=%#llx rhs=%#llx addend=%#llx "
		       "res=%#llx want=%#llx\n",
		       op, lhs, rhs, addend, res, want);
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
		__u64 res = KPROG_ARM64_MUL_VALUE(9U, 0, 0, 0, abort());

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

static const unsigned mul_ops[] = {
	ARM64_OP_MADD, ARM64_OP_MSUB, ARM64_OP_MUL, ARM64_OP_UMULL,
	ARM64_OP_UDIV, ARM64_OP_UMULH, ARM64_OP_UMADDL, ARM64_OP_SMADDL,
};

int main(void)
{
	static const __u64 vectors[][3] = {
		{0x0, 0x0, 0x0},
		{0x1, 0x2, 0x3},
		{0x2, 0x1, 0x0},
		{~0ULL, ~0ULL, ~0ULL},
		{~0ULL, 0x1, 0x0},
		{0x1, ~0ULL, 0x1},
		{0x7fffffffffffffffULL, 0x7fffffffffffffffULL, 0x0},
		{0x8000000000000000ULL, 0x8000000000000000ULL, 0x0},
		{0x8000000000000000ULL, 0x2, 0x0},
		{0x100000000ULL, 0x100000000ULL, 0x0},
		{0x00000000ffffffffULL, 0x00000000ffffffffULL, 0x1},
		{0x00000000ffffffffULL, 0x00000000ffffffffULL, ~0ULL},
		{0xffffffffffffffffULL, 0xffffffffULL, 0x0},
		{0xffffffffULL, 0xffffffffffffffffULL, 0x1},
		{0xffffffffULL, 0x2, 0x0},
		{0x7fffffffULL, 0x7fffffffULL, 0x0},
		{0x80000000ULL, 0x80000000ULL, 0x0},
		{0x80000000ULL, 0xffffffffULL, 0x0},
		{0x0, 0x1, ~0ULL},
		{0x1, 0x0, 0x1},
	};
	unsigned cases = 0, fails = 0;
	__u64 state = 0x9e3779b97f4a7c15ULL;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned k = 0; k < sizeof(mul_ops) / sizeof(mul_ops[0]); k++) {
			fails += check_mul(mul_ops[k], vectors[i][0],
					   vectors[i][1], vectors[i][2]);
			cases++;
		}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 a, b, c;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		a = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		b = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		c = state;
		for (unsigned k = 0; k < sizeof(mul_ops) / sizeof(mul_ops[0]); k++) {
			fails += check_mul(mul_ops[k], a, b, c);
			cases++;
		}
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 mul host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 mul host cross-check: OK (%u cases)\n", cases);
	return 0;
}
