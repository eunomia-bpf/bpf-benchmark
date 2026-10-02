/*
 * Host cross-check for the generated AArch64 ORN complemented-logical-OR value
 * contract.
 *
 * Verifies KPROG_ARM64_ORN_VALUE from generated/arm64_orn.h against an
 * independent oracle that derives the destination width mask from a shift of
 * one (never the macro's width-mask ladder), applies the De Morgan complement
 * form `~(~lhs & rhs)` rather than the OR-with-complement the macro uses, and
 * cross-checks it equals the direct `lhs | ~rhs` form. The right-hand source
 * modification is applied through the existing KPROG_ARM64_MOD_VALUE contract,
 * so the oracle composes the same modifier the sim's ORN_REG body applies. It
 * sweeps both operands over boundary vectors, every modifier code, and a
 * fixed-seed random sweep, and checks that an opcode outside the family aborts
 * with SIGABRT through the generated unsupported arm. Exits non-zero on any
 * mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_orn_host.c -o /tmp/t_orn && /tmp/t_orn
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

#define ARM64_MOD_NONE 0U
#define ARM64_MOD_LSL 1U
#define ARM64_MOD_LSR 2U
#define ARM64_MOD_ASR 3U
#define ARM64_MOD_ROR 4U
#define ARM64_MOD_UXTW 5U
#define ARM64_MOD_SXTW 6U
#define ARM64_MOD_UXTH 7U
#define ARM64_MOD_SXTH 8U
#define ARM64_MOD_UXTB 9U
#define ARM64_MOD_SXTB 10U
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_OP_ORN_REG 0x35U

#include "generated/arm64_width.h"
#include "generated/arm64_mod.h"
#include "generated/arm64_orn.h"

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

static __u64 orn_oracle(unsigned op, __u64 lhs, __u64 rhs, unsigned width)
{
	__u64 direct = lhs | ~rhs;
	__u64 demorgan = ~(~lhs & rhs);

	if ((op != ARM64_OP_ORN_REG) || (direct != demorgan))
		abort();

	return demorgan & width_mask(width);
}

static int check_orn(unsigned op, __u64 lhs, __u64 mod_rhs, unsigned width)
{
	__u64 res = KPROG_ARM64_ORN_VALUE(op, lhs, mod_rhs, width, abort());
	__u64 want = orn_oracle(op, lhs, mod_rhs, width);

	if (res != want) {
		printf("MISMATCH op=%u lhs=%#llx rhs=%#llx width=%u "
		       "res=%#llx want=%#llx\n",
		       op, lhs, mod_rhs, width, res, want);
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
		__u64 res = KPROG_ARM64_ORN_VALUE(0U, 0, 0, ARM64_WIDTH_64,
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
	0xf0ULL, 0x0fULL, 0xffffffffULL, 0x80000000ULL, 0x100000001ULL,
};
static const unsigned ops[] = { ARM64_OP_ORN_REG };
static const unsigned mods[] = {
	ARM64_MOD_NONE, ARM64_MOD_LSL, ARM64_MOD_LSR, ARM64_MOD_ASR,
	ARM64_MOD_ROR, ARM64_MOD_UXTW, ARM64_MOD_SXTW, ARM64_MOD_UXTH,
	ARM64_MOD_SXTH, ARM64_MOD_UXTB, ARM64_MOD_SXTB,
};
static const unsigned widths[] = { ARM64_WIDTH_8, ARM64_WIDTH_16,
				   ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0, nops, nvals, nmods, nwidths;
	__u64 state = 0x2545f4914f6cdd1dULL;

	nops = sizeof(ops) / sizeof(ops[0]);
	nvals = sizeof(values) / sizeof(values[0]);
	nmods = sizeof(mods) / sizeof(mods[0]);
	nwidths = sizeof(widths) / sizeof(widths[0]);

	for (unsigned o = 0; o < nops; o++)
		for (unsigned l = 0; l < nvals; l++)
			for (unsigned r = 0; r < nvals; r++)
				for (unsigned w = 0; w < nwidths; w++) {
					__u64 mod_rhs = KPROG_ARM64_MOD_VALUE(
						mods[(l + r) % nmods],
						values[r], (unsigned)(l & 63U),
						widths[w]);

					fails += check_orn(ops[o], values[l],
							   mod_rhs, widths[w]);
					cases++;
				}

	for (unsigned iter = 0; iter < 40000; iter++) {
		__u64 mod_rhs;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		mod_rhs = KPROG_ARM64_MOD_VALUE(mods[iter % nmods], state,
						(unsigned)(state & 63U),
						widths[iter % nwidths]);
		fails += check_orn(ops[iter % nops], state, mod_rhs,
				   widths[iter % nwidths]);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 orn host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 orn host cross-check: OK (%u cases)\n", cases);
	return 0;
}
