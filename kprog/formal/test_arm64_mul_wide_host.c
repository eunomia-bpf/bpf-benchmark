/*
 * Host cross-check for the AArch64 multiply contract, against 128-bit
 * arithmetic.
 *
 * Why this host exists. `generated/arm64_mul.h` and
 * `GeneratedArm64Mul.lean` are rendered from one specification in one pass, so
 * they cannot drift from each other -- but they *can* both be wrong in the same
 * way, and no proof in the tree relates either to the architectural definition.
 * The family also has a shape that makes a shared error easy: UMULH computes
 * the high half of a 128-bit product with a shift-and-add decomposition, and a
 * term placed in the wrong position still yields a plausible number.
 *
 * The independent oracle is C's own 128-bit integer type, which the simulator
 * cannot use (it compiles for a BPF target) but an x86 host can. Every opcode
 * is checked against it over operands chosen to exercise the boundaries:
 * zero, one, all-ones, the 32-bit boundary, and values whose halves differ.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_mul_wide_host.c -o build/test_arm64_mul_wide_host &&
 *   ./build/test_arm64_mul_wide_host
 */

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

#include "../arm64/arm64_sim.h"
#include "generated/arm64_mul.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

static int unsupported(void)
{
	return 0;
}

static void check(const char *what, unsigned op, __u64 lhs, __u64 rhs,
		  __u64 addend, __u64 want)
{
	__u64 got = KPROG_ARM64_MUL_VALUE(op, lhs, rhs, addend, unsupported());

	cases++;
	if (got != want) {
		printf("MISMATCH %s lhs=%#llx rhs=%#llx addend=%#llx: "
		       "got %#llx want %#llx\n",
		       what, (unsigned long long)lhs, (unsigned long long)rhs,
		       (unsigned long long)addend, (unsigned long long)got,
		       (unsigned long long)want);
		failures++;
	}
}

int main(void)
{
	static const __u64 vals[] = {
		0ULL, 1ULL, 2ULL, 7ULL,
		0x7fffffffULL, 0x80000000ULL, 0xffffffffULL,
		0x100000000ULL, 0x123456789abcdefULL,
		0x8000000000000000ULL, 0xfffffffffffffffeULL,
		0xffffffffffffffffULL,
	};
	unsigned i, j, k;

	for (i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
		for (j = 0; j < sizeof(vals) / sizeof(vals[0]); j++)
			for (k = 0; k < sizeof(vals) / sizeof(vals[0]); k++)
				for (unsigned ai = 0; ai < 2; ai++) {
					__u64 a = vals[i], b = vals[j];
					__u64 c = ai ? vals[k] : 0ULL;
					unsigned __int128 wide;
					unsigned __int128 wide_signed;

					/* MADD: a*b + c, wrapping. */
					wide = (unsigned __int128)a * b + c;
					check("madd", ARM64_OP_MADD, a, b, c,
					      (__u64)wide);

					/* MSUB: c - a*b, wrapping. */
					wide = (unsigned __int128)c -
					       (unsigned __int128)a * b;
					check("msub", ARM64_OP_MSUB, a, b, c,
					      (__u64)wide);

					/* MUL: a*b. */
					wide = (unsigned __int128)a * b;
					check("mul", ARM64_OP_MUL, a, b, c,
					      (__u64)wide);

					/* UMULL: low half * low half. */
					check("umull", ARM64_OP_UMULL, a, b, c,
					      (__u64)(__u32)a * (__u64)(__u32)b);

					/* UDIV: unsigned, zero divisor -> 0. */
					check("udiv", ARM64_OP_UDIV, a, b, c,
					      b ? a / b : 0ULL);

					/* UMULH: high half of the product. */
					wide = (unsigned __int128)a * b;
					check("umulh", ARM64_OP_UMULH, a, b, c,
					      (__u64)(wide >> 64));

					/* UMADDL: low*low + c. */
					wide = (unsigned __int128)(__u32)a *
					       (__u32)b + c;
					check("umaddl", ARM64_OP_UMADDL, a, b, c,
					      (__u64)wide);

					/* SMADDL: signed low*low + c. */
					wide_signed =
						(unsigned __int128)
						((__s64)(__s32)a * (__s64)(__s32)b)
						+ c;
					check("smaddl", ARM64_OP_SMADDL, a, b, c,
					      (__u64)wide_signed);
				}

	if (failures) {
		printf("arm64 mul wide host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 mul wide host cross-check: OK (%lu cases)\n", cases);
	return 0;
}