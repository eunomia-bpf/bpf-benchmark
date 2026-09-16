/*
 * Host cross-check for the generated AArch64 move-wide (MOVK) contract.
 *
 * Verifies KPROG_ARM64_MOVK_INSERT from generated/arm64_movk.h against an
 * independent oracle that builds the destination with a 16-bit field taken from
 * an immediate byte array (never the macro's shift/mask pair):
 *   result = (dst with the 16-bit column cleared) | (imm_low16 << column)
 * It sweeps explicit boundary vectors over all four architectural columns, then
 * a fixed-seed random sweep, and checks that a column outside {0,16,32,48}
 * aborts with SIGABRT through the generated unsupported arm. Exits non-zero on
 * any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_movk_host.c -o /tmp/t_movk && /tmp/t_movk
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/arm64_movk.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent oracle: write the destination into a byte array, overwrite the
 * two bytes of the target halfword with the low two immediate bytes, read back. */
static __u64 movk_oracle(__u64 dst, __u64 imm, unsigned column)
{
	unsigned char bytes[8];
	unsigned hi = column / 8;
	unsigned lo = hi + 1;

	for (unsigned i = 0; i < 8; i++)
		bytes[i] = (unsigned char)((dst >> (8 * i)) & 0xffU);
	bytes[hi] = (unsigned char)(imm & 0xffU);
	bytes[lo] = (unsigned char)((imm >> 8) & 0xffU);

	__u64 out = 0;

	for (unsigned i = 0; i < 8; i++)
		out |= (__u64)bytes[i] << (8 * i);
	return out;
}

static int check_movk(__u64 dst, __u64 imm, unsigned column)
{
	__u64 res = KPROG_ARM64_MOVK_INSERT(dst, imm, column, abort());
	__u64 want = movk_oracle(dst, imm, column);

	if (res != want) {
		printf("MISMATCH movk dst=%#llx imm=%#llx column=%u "
		       "res=%#llx want=%#llx\n", dst, imm, column, res, want);
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
		__u64 res = KPROG_ARM64_MOVK_INSERT(0, 0, 8U, abort());

		_exit(res == 0 ? 0 : 1);
	}

	if (waitpid(pid, &status, 0) != pid ||
	    !(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
		printf("MISMATCH unsupported column did not abort (status=%d)\n",
		       status);
		return 1;
	}
	return 0;
}

static const unsigned columns[] = { 0U, 16U, 32U, 48U };

int main(void)
{
	static const __u64 dsts[] = {
		0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0xffff0000ffff0000ULL,
		0x8000000000000000ULL, 0xffffULL,
	};
	static const __u64 imms[] = {
		0x0ULL, 0xffffULL, 0x1234ULL, ~0ULL, 0xffffffffffffabcdULL,
		0x1ULL,
	};
	unsigned cases = 0, fails = 0;
	__u64 state = 0x0f1e2d3c4b5a6978ULL;

	for (unsigned d = 0; d < sizeof(dsts) / sizeof(dsts[0]); d++)
		for (unsigned m = 0; m < sizeof(imms) / sizeof(imms[0]); m++)
			for (unsigned c = 0; c < sizeof(columns) / sizeof(columns[0]);
			     c++) {
				fails += check_movk(dsts[d], imms[m], columns[c]);
				cases++;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 dst, imm;
		unsigned c = (unsigned)(iter % 4);

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		dst = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		imm = state;
		fails += check_movk(dst, imm, columns[c]);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 movk host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 movk host cross-check: OK (%u cases)\n", cases);
	return 0;
}
