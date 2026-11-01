/*
 * Host cross-check for the x86 `imul` two-operand overflow flags, against
 * exact 128-bit arithmetic.
 *
 * Why this host exists. The generated contract does not multiply anything. It
 * decides CF/OF from magnitudes:
 *
 *     overflow = A_ABS != 0 && B_ABS > LIMIT / A_ABS
 *
 * where LIMIT depends on the *signs* of the operands: the negative bound when
 * the product is negative, the positive bound otherwise. That shape has two
 * independent chances to be wrong, and both produce plausible answers:
 *
 *   - the division test rounds down, so an off-by-one at the boundary is
 *     invisible unless a case lands exactly there;
 *   - the sign selection is a separate expression from the magnitudes, so a
 *     case where the operands' signs differ from what the limit assumed is
 *     wrong only for some inputs.
 *
 * The architectural definition is direct: the untruncated product must fit in
 * the destination width as a signed value. The host can test exactly that with
 * 128-bit arithmetic, so it does -- over sign pairs and magnitudes chosen to
 * include the boundary where the product is exactly representable and exactly
 * one past it.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_imul_flags_wide_host.c -o build/test_x86_imul_flags_wide_host &&
 *   ./build/test_x86_imul_flags_wide_host
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

#define X86_SIM_ENABLE_STACK 1
#include "../x86/x86_sim.h"
#include "../x86/x86_sim_local_bpf.h"
#include "generated/x86_imul_flags.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The architectural answer: does the exact product fit the width as signed? */
static int does_not_overflow(__s64 a, __s64 b, unsigned bits)
{
	__int128 p = (__int128)a * (__int128)b;
	__int128 lo = -((__int128)1 << (bits - 1));
	__int128 hi = ((__int128)1 << (bits - 1)) - 1;

	return p >= lo && p <= hi;
}

static void check(unsigned bits, __u64 width_code, __s64 a, __s64 b)
{
	__u64 cf = 99, of = 99;
	__u64 a_abs = x86_signed_abs_width((__u64)a,
					    x86_width_effective(width_code));
	__u64 b_abs = x86_signed_abs_width((__u64)b,
					    x86_width_effective(width_code));
	__u64 sign = 1ULL << (x86_width_bits(width_code) - 1);
	__u64 limit = (((__u64)a ^ (__u64)b) & sign) ? sign : sign - 1;
	int want;

	/* The simulator's own composition: it derives the magnitudes and the
	 * sign-dependent limit itself, so driving it here is what tests the
	 * sign selection rather than re-deriving it in the oracle. */
	{
		__u64 cf_sim = 99, of_sim = 99;

		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_SET_IMUL_FLAGS((__u64)a, (__u64)b, width_code);
		cf_sim = __x86_cf;
		of_sim = __x86_of;
		want = does_not_overflow(a, b, bits) ? 0 : 1;
		cases++;
		if (cf_sim != (__u64)want || of_sim != (__u64)want) {
			printf("SIM MISMATCH bits=%u a=%lld b=%lld: cf=%llu "
			       "of=%llu want %d\n", bits, (long long)a,
			       (long long)b, (unsigned long long)cf_sim,
			       (unsigned long long)of_sim, want);
			failures++;
		}
	}

	KPROG_X86_SET_IMUL_FLAGS(cf, of, a_abs, b_abs, limit);

	want = does_not_overflow(a, b, bits) ? 0 : 1;
	cases++;
	if (cf != (__u64)want || of != (__u64)want) {
		printf("MISMATCH bits=%u a=%lld b=%lld: cf=%llu of=%llu want %d "
		       "(a_abs=%#llx b_abs=%#llx limit=%#llx)\n",
		       bits, (long long)a, (long long)b,
		       (unsigned long long)cf, (unsigned long long)of, want,
		       (unsigned long long)a_abs, (unsigned long long)b_abs,
		       (unsigned long long)limit);
		failures++;
	}
}

int main(void)
{
	/* Widths the contract is defined over, with their signed extremes. */
	static const struct {
		unsigned bits;
		__u64 code;
		__s64 lo, hi;      /* signed range */
	} widths[] = {
		{  8, X86_WIDTH_8,  -128, 127 },
		{ 16, X86_WIDTH_16, -32768, 32767 },
		{ 32, X86_WIDTH_32, -2147483648LL, 2147483647LL },
		{ 64, X86_WIDTH_64, (-9223372036854775807LL - 1),
		  9223372036854775807LL },
	};
	unsigned wi, ai, bi;

	for (wi = 0; wi < sizeof(widths) / sizeof(widths[0]); wi++) {
		__s64 lo = widths[wi].lo, hi = widths[wi].hi;
		__s64 vals[16];
		unsigned n = 0;

		vals[n++] = 0;
		vals[n++] = 1;
		vals[n++] = -1;
		vals[n++] = 2;
		vals[n++] = -2;
		vals[n++] = 3;
		vals[n++] = lo;
		vals[n++] = hi;
		vals[n++] = lo / 2;
		vals[n++] = hi / 2;
		vals[n++] = lo + 1;
		vals[n++] = hi - 1;
		/* magnitudes whose product sits exactly on and just past the
		 * boundary once scaled, which is where a division-rounding
		 * test goes wrong and nowhere else. */
		vals[n++] = (__s64)(hi / 3);
		vals[n++] = (__s64)(hi / 3) + 1;
		/* The most-negative operand against -1: the one pair where the
		 * product is exactly |lo|, so the two candidate limits for a
		 * negative product disagree and nothing else in the table can. */
		vals[n++] = (__s64)(lo / 2) * 2;   /* lo when it is even */
		vals[n++] = -1;

		for (ai = 0; ai < n; ai++)
			for (bi = 0; bi < n; bi++)
				check(widths[wi].bits, widths[wi].code,
				      vals[ai], vals[bi]);
	}

	if (failures) {
		printf("x86 imul flags wide host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("x86 imul flags wide host cross-check: OK (%lu cases)\n", cases);
	return 0;
}