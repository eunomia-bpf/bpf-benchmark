/*
 * Host cross-check for the generated AArch64 condition-code contract.
 *
 * Verifies KPROG_ARM64_EVAL_COND from generated/arm64_cond.h against an
 * independent switch oracle over a separate enumeration of the condition
 * semantics:
 *   - every NZCV combination (all 16) is crossed with all 15 condition codes,
 *     so each condition's truth table is checked in full;
 *   - the macro's per-condition return must equal the oracle bit;
 *   - a condition code outside the 0..14 table (swept over all byte values in
 *     forked children) must abort through the generated unsupported arm.
 * The oracle is written as an explicit switch rather than the macro's nested
 * ternary, so agreement relates two structurally different formulations.
 * Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_cond_host.c -o /tmp/t_a64c && /tmp/t_a64c
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/* Condition codes are the ARM64_COND_* architectural numbers the generated
 * header pins; the numeric values are reasserted by that header below. */
#define ARM64_COND_EQ 0U
#define ARM64_COND_NE 1U
#define ARM64_COND_CS 2U
#define ARM64_COND_CC 3U
#define ARM64_COND_MI 4U
#define ARM64_COND_PL 5U
#define ARM64_COND_VS 6U
#define ARM64_COND_VC 7U
#define ARM64_COND_HI 8U
#define ARM64_COND_LS 9U
#define ARM64_COND_GE 10U
#define ARM64_COND_LT 11U
#define ARM64_COND_GT 12U
#define ARM64_COND_LE 13U
#define ARM64_COND_AL 14U

#include "generated/arm64_cond.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent architectural condition semantics: an explicit switch keyed on
 * the named codes, distinct from the macro's chained ternary. */
static int cond_oracle(unsigned cond, unsigned n, unsigned z, unsigned c,
	unsigned v)
{
	switch (cond) {
	case ARM64_COND_EQ: return z;
	case ARM64_COND_NE: return !z;
	case ARM64_COND_CS: return c;
	case ARM64_COND_CC: return !c;
	case ARM64_COND_MI: return n;
	case ARM64_COND_PL: return !n;
	case ARM64_COND_VS: return v;
	case ARM64_COND_VC: return !v;
	case ARM64_COND_HI: return c && !z;
	case ARM64_COND_LS: return !c || z;
	case ARM64_COND_GE: return n == v;
	case ARM64_COND_LT: return n != v;
	case ARM64_COND_GT: return !z && n == v;
	case ARM64_COND_LE: return z || n != v;
	case ARM64_COND_AL: return 1;
	default: abort();
	}
}

static int check(unsigned cond, unsigned n, unsigned z, unsigned c, unsigned v)
{
	int want = cond_oracle(cond, n, z, c, v);
	int got = KPROG_ARM64_EVAL_COND(cond, n, z, c, v, abort());

	if (got != want) {
		fprintf(stderr,
			"MISMATCH cond=%u nzcv=%u%u%u%u expected=%d got=%d\n",
			cond, n, z, c, v, want, got);
		return 1;
	}
	return 0;
}

/* A code outside the 0..14 table must reach the unsupported arm and abort. */
static int check_unsupported_aborts(void)
{
	for (unsigned cond = 15; cond < 256; cond++) {
		pid_t pid = fork();

		if (pid < 0)
			return 1;
		if (pid == 0) {
			(void)KPROG_ARM64_EVAL_COND(cond, 0, 1, 1, 0, abort());
			_exit(0); /* reached only if the unsupported arm did not run */
		}
		int status = 0;

		if (waitpid(pid, &status, 0) != pid)
			return 1;
		if (!WIFSIGNALED(status) || WTERMSIG(status) != SIGABRT) {
			fprintf(stderr,
				"unsupported cond=%u did not abort: status=%#x\n",
				cond, status);
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	unsigned cases = 0;

	for (unsigned nzcv = 0; nzcv < 16; nzcv++) {
		unsigned n = (nzcv >> 3) & 1U;
		unsigned z = (nzcv >> 2) & 1U;
		unsigned c = (nzcv >> 1) & 1U;
		unsigned v = nzcv & 1U;

		for (unsigned cond = 0; cond < 15; cond++) {
			if (check(cond, n, z, c, v))
				return 1;
			cases++;
		}
	}

	if (check_unsupported_aborts())
		return 1;

	printf("arm64 condition host cross-check: OK (%u cases)\n",
		cases);
	return 0;
}
