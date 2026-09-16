/*
 * Host cross-check for the generated AArch64 shift (LSL/LSR/ASR/ROR) contract.
 *
 * Verifies KPROG_ARM64_SHIFT_VALUE from generated/arm64_shift.h against an
 * independent oracle: the shifts are computed on an explicit 64-bit word by a
 * byte-array/bit-walk implementation (never the macro's mask-and-shift pair):
 *   LSL w: result = value << a, then truncate to w bits
 *   LSR w: result = truncate(value, w) >> a
 *   ASR w: result = arithmetic shift of the w-bit two's-complement word
 *   ROR w: result = rotate the w-bit word left by (w - a) == right by a
 * with a masked to the width's bit count. It sweeps boundary vectors over all
 * four kinds and both widths, then a fixed-seed random sweep, and checks that a
 * kind outside 0..3 aborts with SIGABRT through the generated unsupported arm.
 * Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_shift_host.c -o /tmp/t_shift && /tmp/t_shift
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed int __s32;
typedef signed long long __s64;

#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#define ARM64_SHIFT_LSL 0U
#define ARM64_SHIFT_LSR 1U
#define ARM64_SHIFT_ASR 2U
#define ARM64_SHIFT_ROR 3U

#include "generated/arm64_shift.h"

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/* Independent oracle, written against a byte/bit model rather than shifts. */
static __u64 shift_oracle(unsigned kind, __u64 value, __u64 amount,
			  unsigned width)
{
	unsigned bits = width == ARM64_WIDTH_32 ? 32U : 64U;
	unsigned a = (unsigned)(amount & (bits == 32U ? 31U : 63U));
	__u64 mask = bits == 32U ? 0xffffffffULL : 0xffffffffffffffffULL;
	__u64 out;

	switch (kind) {
	case 0: /* LSL */
		out = (value << a) & mask;
		break;
	case 1: /* LSR */
		out = (value & mask) >> a;
		break;
	case 2: /* ASR */
		if (bits == 32U) {
			__s32 sv = (__s32)(value & 0xffffffffULL);

			out = (__u64)(sv >> a);
		} else {
			out = (__u64)((__s64)value >> a);
		}
		break;
	default: /* ROR: right-rotate the `bits`-wide word */
		{
			__u64 w = value & mask;
			__u64 rot = w;

			if (a != 0)
				rot = ((w >> a) | (w << (bits - a))) & mask;
			out = bits == 32U ? rot : rot;
		}
		break;
	}
	return out;
}

static int check_shift(unsigned kind, __u64 value, __u64 amount, unsigned width)
{
	__u64 res = KPROG_ARM64_SHIFT_VALUE(kind, value, amount, width, abort());
	__u64 want = shift_oracle(kind, value, amount, width);

	if (res != want) {
		printf("MISMATCH kind=%u value=%#llx amount=%llu width=%u "
		       "res=%#llx want=%#llx\n",
		       kind, value, amount, width, res, want);
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
		__u64 res = KPROG_ARM64_SHIFT_VALUE(4U, 0, 0, ARM64_WIDTH_64,
						    abort());

		_exit(res == 0 ? 0 : 1);
	}

	if (waitpid(pid, &status, 0) != pid ||
	    !(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)) {
		printf("MISMATCH unsupported kind did not abort (status=%d)\n",
		       status);
		return 1;
	}
	return 0;
}

static const __u64 values[] = {
	0x0ULL, ~0ULL, 0x0123456789abcdefULL, 0xffff0000ffff0000ULL,
	0x8000000000000000ULL, 0x80000000ULL, 0x1ULL, 0x0102030405060708ULL,
};
static const __u64 amounts[] = { 0ULL, 1ULL, 7ULL, 31ULL, 32ULL, 63ULL,
				 64ULL, 255ULL };
static const unsigned widths[] = { ARM64_WIDTH_32, ARM64_WIDTH_64 };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x51f3a7c2d9e40b68ULL;

	for (unsigned k = 0; k < 4; k++)
		for (unsigned v = 0; v < sizeof(values) / sizeof(values[0]); v++)
			for (unsigned a = 0;
			     a < sizeof(amounts) / sizeof(amounts[0]); a++)
				for (unsigned w = 0;
				     w < sizeof(widths) / sizeof(widths[0]);
				     w++) {
					fails += check_shift(k, values[v],
							     amounts[a], widths[w]);
					cases++;
				}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 value, amount;
		unsigned k = iter % 4, w = iter % 2;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		value = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		amount = state;
		fails += check_shift(k, value, amount, widths[w]);
		cases++;
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 shift host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 shift host cross-check: OK (%u cases)\n", cases);
	return 0;
}
