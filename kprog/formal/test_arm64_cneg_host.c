/*
 * Host cross-check for the generated AArch64 CNEG condition-gated negation
 * value contract.
 *
 * Verifies KPROG_ARM64_CNEG_VALUE from generated/arm64_cneg.h against an
 * independent oracle that derives the destination width mask from a shift of
 * one (never the macro's width-mask ladder) and applies the raw operation
 * directly:
 *   taken:      (__u64)(0ULL - src)
 *   not taken:  src
 * both then narrowed to the destination width; and independently against the
 * invert-and-add-one two's-complement identity the Lean statement uses, so the
 * oracle pins the negation rather than restating the macro. It sweeps every
 * destination width over boundary vectors and a fixed-seed random sweep, and
 * checks that an opcode outside the family aborts with SIGABRT through the
 * generated unsupported arm. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_cneg_host.c -o /tmp/t_cn && /tmp/t_cn
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_CNEG 0x41U

#include "generated/arm64_cneg.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent width mask: one shifted left by the destination bit count. */
static __u64 width_mask(unsigned width)
{
	unsigned bits = width == ARM64_WIDTH_8 ? 8U :
			width == ARM64_WIDTH_16 ? 16U :
			width == ARM64_WIDTH_32 ? 32U : 64U;

	return bits >= 64U ? ~0ULL : (1ULL << bits) - 1ULL;
}

static __u64 cneg_oracle(unsigned op, int taken, __u64 value, unsigned width)
{
	__u64 raw = taken ? (__u64)(0ULL - value) : value;
	__u64 ident = taken ? ~value + 1ULL : value;

	if ((op != ARM64_OP_CNEG) || (raw != ident))
		abort();

	return raw & width_mask(width);
}

static int check_cneg(unsigned op, int taken, __u64 value, unsigned width)
{
	__u64 res = KPROG_ARM64_CNEG_VALUE(op, value, taken, width, abort());
	__u64 want = cneg_oracle(op, taken, value, width);

	if (res != want) {
		printf("MISMATCH op=%u taken=%d value=%#llx width=%u "
		       "res=%#llx want=%#llx\n",
		       op, taken, value, width, res, want);
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
		__u64 res = KPROG_ARM64_CNEG_VALUE(0U, 0, 1, ARM64_WIDTH_64,
						   abort());

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

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x1ULL, 0x8000000000000000ULL, 0x0123456789abcdefULL,
	0xffffffffULL, 0x00000000ffffffffULL, 0x80ULL, 0x8000ULL,
	0x80000000ULL, 0x7fffffffULL, 0x100000001ULL,
};
static const unsigned ops[] = { ARM64_OP_CNEG };
static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0, nops, nvals, nwidths;
	__u64 state = 0x2545f4914f6cdd1dULL;

	nops = sizeof(ops) / sizeof(ops[0]);
	nvals = sizeof(values) / sizeof(values[0]);
	nwidths = sizeof(widths) / sizeof(widths[0]);

	for (unsigned o = 0; o < nops; o++)
		for (int t = 0; t <= 1; t++)
			for (unsigned v = 0; v < nvals; v++)
				for (unsigned w = 0; w < nwidths; w++) {
					fails += check_cneg(ops[o], t, values[v],
							    widths[w]);
					cases++;
				}

	for (unsigned iter = 0; iter < 40000; iter++) {
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		fails += check_cneg(ops[iter % nops], (int)(iter & 1U), state,
				    widths[iter % nwidths]);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 cneg host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 cneg host cross-check: OK (%u cases)\n", cases);
	return 0;
}
