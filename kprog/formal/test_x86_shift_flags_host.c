/*
 * Host cross-check for the generated x86 shift-flag contract
 * (generated/x86_shift_flags.h) and the simulator wrapper that feeds it.
 *
 * The generated macro KPROG_X86_SET_SHIFT_FLAGS is what the simulator's
 * X86_SIM_L_SET_SHIFT_FLAGS calls for the four shift ALU operations. This
 * oracle includes x86_sim.h (defining `__always_inline` so the headers compile
 * off-target), reproduces the wrapper's input derivation (narrowing,
 * bit count, sign bit and masked shift count) independently, drives the *real*
 * generated macro, and compares the resulting CF/ZF/SF/OF against an
 * independent restatement of the x86 shift-flag semantics for shl/shr/sar/rol.
 * Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_shift_flags_host.c \
 *     -o /tmp/t_xsf && /tmp/t_xsf
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;
#define __always_inline inline
#include "../x86/x86_sim.h"
#include "generated/x86_shift_flags.h"


#include <stdio.h>

static unsigned cases = 0;
static unsigned failures = 0;

static void expect_eq(const char *what, __u64 got, __u64 want)
{
	cases++;
	if (got != want) {
		fprintf(stderr, "MISMATCH %s: got %llu want %llu\n", what,
			(unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

/* Independent statement of the x86 shift-flag semantics. `alu` is the
 * generated X86_ALU_* code; `old_*` are 0/1. Returns the four new flags via
 * out-pointers, derived from the architectural description rather than from
 * the macro's branch structure. */
struct flags {
	__u64 cf, zf, sf, of;
};

static struct flags reference_shift_flags(__u32 alu, __u64 value, __u64 rhs,
					  __u64 result, __u8 width,
					  struct flags old)
{
	struct flags out = old;
	unsigned bits = (unsigned)width * 8U;
	__u64 mask = bits == 64U ? ~0ULL : ((1ULL << bits) - 1ULL);
	unsigned count = (unsigned)(rhs & (bits == 64U ? 63U : 31U));
	__u64 a = value & mask;
	__u64 r = result & mask;
	__u64 sign = 1ULL << (bits - 1U);
	__u64 result_zero = (r == 0);
	__u64 result_sign = ((r & sign) != 0);

	if (count == 0)
		return out; /* masked count zero: all four flags preserved */

	if (alu == X86_ALU_ROL) {
		out.cf = r & 1U;
		/* ZF/SF preserved for rotate */
		if (count == 1U)
			out.of = (((r & sign) != 0) ^ (out.cf != 0)) ? 1U : 0U;
		return out;
	}

	out.zf = result_zero;
	out.sf = result_sign;
	if (alu == X86_ALU_SHL) {
		out.cf = count <= bits ? ((a >> (bits - count)) & 1U) : 0U;
		if (count == 1U)
			out.of = (out.sf != 0) ^ (out.cf != 0) ? 1U : 0U;
	} else if (alu == X86_ALU_SHR) {
		out.cf = count <= bits ? ((a >> (count - 1U)) & 1U) : 0U;
		if (count == 1U)
			out.of = ((a & sign) != 0);
	} else { /* SAR */
		out.cf = count <= bits ? ((a >> (count - 1U)) & 1U)
				       : ((a & sign) != 0);
		if (count == 1U)
			out.of = 0U;
	}
	return out;
}

/* Drive the real generated macro exactly as the simulator wrapper does. */
static struct flags drive_macro(__u32 alu, __u64 value, __u64 rhs,
				__u64 result, __u8 width, struct flags old)
{
	__u8 raw_width = width;
	__u8 w = raw_width ? raw_width : X86_WIDTH_64;
	__u32 bits = x86_width_bits(w);
	__u64 mask = x86_width_mask(w);
	__u64 a = value & mask;
	__u64 r = result & mask;
	__u8 count = x86_shift_count(rhs, w);
	__u64 sign = 1ULL << (bits - 1U);
	__u64 cf = old.cf, zf = old.zf, sf = old.sf, of = old.of;

	KPROG_X86_SET_SHIFT_FLAGS(cf, zf, sf, of, a, count, r, bits, sign, alu);

	return (struct flags){ cf != 0, zf != 0, sf != 0, of != 0 };
}

int main(void)
{
	static const __u64 VALUES[] = {
		0ULL, 1ULL, 0xffULL, 0x80ULL, 0xffffffffffffffffULL,
		0x8000000000000000ULL, 0x123456789abcdefULL, 0xdeadbeefULL,
	};
	static const __u64 RHS[] = {
		0ULL, 1ULL, 2ULL, 7ULL, 8ULL, 31ULL, 32ULL, 33ULL, 63ULL, 64ULL,
		0xffffffffULL,
	};
	static const __u8 WD[] = {X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32,
				  X86_WIDTH_64};
	static const __u32 OPS[] = {X86_ALU_SHL, X86_ALU_SHR, X86_ALU_SAR,
				    X86_ALU_ROL};
	static const char *OPN[] = {"shl", "shr", "sar", "rol"};
	unsigned o, i, r, w, fl;

	for (o = 0; o < sizeof OPS / sizeof OPS[0]; o++) {
		for (w = 0; w < sizeof WD / sizeof WD[0]; w++) {
			for (i = 0; i < sizeof VALUES / sizeof VALUES[0]; i++) {
				for (r = 0; r < sizeof RHS / sizeof RHS[0]; r++) {
					for (fl = 0; fl < 16; fl++) {
						struct flags old = {
							fl & 1U, (fl >> 1) & 1U,
							(fl >> 2) & 1U, (fl >> 3) & 1U,
						};
						/* Use the shift *result* the
						 * simulator would compute, so
						 * the oracle drives the same
						 * (value,root,result,width)
						 * tuple. */
						__u64 result = x86_alu_result(
							VALUES[i], RHS[r],
							OPS[o], WD[w]);
						struct flags got = drive_macro(
							OPS[o], VALUES[i], RHS[r],
							result, WD[w], old);
						struct flags want = reference_shift_flags(
							OPS[o], VALUES[i], RHS[r],
							result, WD[w], old);
						char what[96];

						snprintf(what, sizeof what,
							 "%s v=%llx rhs=%llu w=%u old=%u cf",
							 OPN[o],
							 (unsigned long long)VALUES[i],
							 (unsigned long long)RHS[r],
							 WD[w], fl);
						expect_eq(what, got.cf, want.cf);
						expect_eq("zf", got.zf, want.zf);
						expect_eq("sf", got.sf, want.sf);
						expect_eq("of", got.of, want.of);
					}
				}
			}
		}
	}

	if (failures == 0)
		printf("x86 shift flags host cross-check: OK (%u cases)\n",
		       cases);
	return failures == 0 ? 0 : 1;
}
