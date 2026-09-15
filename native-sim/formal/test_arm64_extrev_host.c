/*
 * Host cross-check for the generated AArch64 extract/reverse/extend contract.
 *
 * Verifies KPROG_ARM64_EXTREV_VALUE from generated/arm64_extrev.h against an
 * independent oracle built on architectural primitives only (no arm64_sim.h and
 * no reuse of the generated header's byte ladders):
 *   - EXTR:   the low `bits` of the rotate-left of the `src : src2`
 *             concatenation, computed on an `unsigned __int128` concatenation;
 *   - REV:    byte reversal of the value over the destination width, computed
 *             by writing the value into a byte array and reversing it;
 *   - REV16:  swap of the two bytes within each 16-bit unit of the destination
 *             width, computed by a per-half byte swap;
 *   - SXTB/SXTH/SXTW: sign extension of the low 8/16/32 bits to 64 bits.
 *
 * The handler composes the generated macro with the width-narrowing register
 * write, and every operand register already holds a `bits`-wide value, so the
 * check masks both operands to the destination width, runs the macro, narrows
 * the result, and compares with the architectural oracle. It sweeps explicit
 * boundary vectors, then a fixed-seed random sweep, and checks that an opcode
 * outside the family aborts with SIGABRT through the generated default arm.
 * Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_extrev_host.c -o /tmp/t_extrev && /tmp/t_extrev
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

/* Op codes are the ARM64_OP_* architectural numbers the generated header pins,
 * kept local so the oracle is independent of the simulator header. */
#define ARM64_OP_EXTR 17U
#define ARM64_OP_REV 19U
#define ARM64_OP_REV16 20U
#define ARM64_OP_SXTH 21U
#define ARM64_OP_SXTW 47U
#define ARM64_OP_SXTB 60U
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U

#include "generated/arm64_width.h"
#include "generated/arm64_extrev.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static unsigned width_bits(unsigned width)
{
	return width == ARM64_WIDTH_8 ? 8U :
	       width == ARM64_WIDTH_16 ? 16U :
	       width == ARM64_WIDTH_32 ? 32U : 64U;
}

static __u64 width_mask(unsigned width)
{
	unsigned bits = width_bits(width);

	return bits == 64 ? ~0ULL : (((__u64)1 << bits) - 1);
}

/* EXTR: rotate the two-operand concatenation left by the masked shift and keep
 * the low `bits`. The concatenation is a real 128-bit value, so this never
 * restates the handler's shift pair. The operands are `bits`-wide. */
static __u64 extr_oracle(__u64 src, __u64 src2, __u64 shift, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned k = (unsigned)(shift & (bits - 1));
	unsigned __int128 concat = ((unsigned __int128)src << bits) | src2;
	__u64 low = (__u64)(concat >> k);

	return bits == 64 ? low : (low & (((__u64)1 << bits) - 1));
}

/* REV: reverse the bytes of the value over the destination width. */
static __u64 rev_oracle(__u64 value, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned nbytes = bits / 8;
	__u64 out = 0;
	unsigned i;

	for (i = 0; i < nbytes; i++)
		out = (out << 8) | ((value >> (8 * i)) & 0xffULL);
	return out;
}

/* REV16: swap the two bytes within each 16-bit unit of the destination width. */
static __u64 rev16_oracle(__u64 value, unsigned width)
{
	unsigned bits = width_bits(width);
	unsigned nhalf = bits / 16;
	__u64 out = 0;
	unsigned h;

	for (h = 0; h < nhalf; h++) {
		__u64 half = (value >> (16 * h)) & 0xffffULL;

		out |= ((((half & 0xffULL) << 8) | ((half >> 8) & 0xffULL))
			<< (16 * h));
	}
	return out;
}

/* SXTB/SXTH/SXTW: sign extend the low `nb` bits to 64 bits. */
static __u64 sxt_oracle(__u64 value, unsigned nb)
{
	__u64 mask = nb == 64 ? ~0ULL : ((__u64)1 << nb) - 1;
	__u64 sign = (__u64)1 << (nb - 1);
	__u64 v = value & mask;

	return (v ^ sign) - sign;
}

static __u64 extrev_oracle(unsigned op, __u64 src, __u64 src2, __u64 shift,
			   unsigned width)
{
	switch (op) {
	case ARM64_OP_EXTR:
		return extr_oracle(src, src2, shift, width);
	case ARM64_OP_REV:
		return rev_oracle(src, width);
	case ARM64_OP_REV16:
		return rev16_oracle(src, width);
	case ARM64_OP_SXTH:
		return sxt_oracle(src, 16);
	case ARM64_OP_SXTW:
		return sxt_oracle(src, 32);
	case ARM64_OP_SXTB:
		return sxt_oracle(src, 8);
	}
	return 0;
}

static int check_extrev(unsigned op, __u64 src, __u64 src2, __u64 shift,
			unsigned width)
{
	__u64 mask = width_mask(width);
	__u64 res = KPROG_ARM64_EXTREV_VALUE(op, src & mask, src2 & mask, shift,
					     width, abort()) & mask;
	__u64 want = extrev_oracle(op, src & mask, src2 & mask, shift, width)
		     & mask;

	if (res != want) {
		printf("MISMATCH extrev op=%u src=%#llx src2=%#llx shift=%#llx "
		       "width=%u res=%#llx want=%#llx\n",
		       op, src, src2, shift, width, res, want);
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
		__u64 res = KPROG_ARM64_EXTREV_VALUE(9U, 0, 0, 0, ARM64_WIDTH_64,
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

/* The architectural destination widths. EXTR, REV and REV16 are word or
 * doubleword instructions; the sign extends are width-independent. */
static const unsigned widths[] = { ARM64_WIDTH_32, ARM64_WIDTH_64 };

static const unsigned ops[] = {
	ARM64_OP_EXTR, ARM64_OP_REV, ARM64_OP_REV16,
	ARM64_OP_SXTH, ARM64_OP_SXTW, ARM64_OP_SXTB,
};

int main(void)
{
	static const __u64 vectors[][3] = {
		{0x0, 0x0, 0x0},
		{0x1, 0x2, 0x3},
		{~0ULL, ~0ULL, ~0ULL},
		{0x0102030405060708ULL, 0x1122334455667788ULL, 0x8},
		{0x0000000011223344ULL, 0x0000000055667788ULL, 0x4},
		{0xff, 0xff, 0x1},
		{0x80, 0x8000, 0x0},
		{0x80000000ULL, 0x8000000000000000ULL, 0x1},
		{0xffffffffULL, 0xffffffffffffffffULL, 0x3f},
		{0xaaaaaaaaaaaaaaaaULL, 0x5555555555555555ULL, 0x20},
		{0x1, 0x0, 0x1},
		{0x0, 0x1, 0x0},
	};
	unsigned cases = 0, fails = 0;
	__u64 state = 0x9e3779b97f4a7c15ULL;

	for (unsigned i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
		for (unsigned w = 0; w < sizeof(widths) / sizeof(widths[0]); w++)
			for (unsigned k = 0; k < sizeof(ops) / sizeof(ops[0]);
			     k++) {
				fails += check_extrev(ops[k], vectors[i][0],
						      vectors[i][1], vectors[i][2],
						      widths[w]);
				cases++;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 src, src2, shift;
		unsigned w = (unsigned)(iter % (sizeof(widths) /
						 sizeof(widths[0])));

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src2 = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		shift = state;
		for (unsigned k = 0; k < sizeof(ops) / sizeof(ops[0]); k++) {
			fails += check_extrev(ops[k], src, src2, shift,
					      widths[w]);
			cases++;
		}
	}

	fails += check_unsupported_aborts();
	cases++;

	if (fails) {
		printf("arm64 extract/reverse/extend host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 extract/reverse/extend host cross-check: OK (%u cases)\n",
	       cases);
	return 0;
}
