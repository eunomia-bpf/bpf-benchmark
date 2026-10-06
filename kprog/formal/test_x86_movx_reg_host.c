/*
 * Host cross-check for the x86 register-source MOVZX/MOVSX handler
 * (`X86_SIM_L_EXEC_MOVX_REG`, the shared body of `X86_OP_MOVZX_REG` and
 * `X86_OP_MOVSX_REG`, and therefore of `cdqe` and `movsxd`).
 *
 * The generated contracts under `generated/` are the artifact under test; the
 * `oracle_*` functions are independent restatements of the same architecture
 * (sign bit arithmetic rather than the generated complement/subtract form).
 * Built with `-Wall -Wextra -O2` and swept with a fixed-seed LCG so the run is
 * deterministic.
 */
typedef unsigned char __u8;

/* The generated headers define __always_inline functions for the in-kernel
 * build; provide the attribute for the host build. */
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef signed long long __s64;

#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#define X86_OP_MOVZX_REG 0x20U
#define X86_OP_MOVSX_REG 0x21U

#include "generated/x86_reg_write.h"
#include "generated/x86_width.h"
#include "generated/x86_signed.h"

#include <stdio.h>

union reg_storage {
	void *ptr;
	__u64 q;
	__u16 w;
	__u8 b[8];
};

struct movx_result {
	__u64 dst;
	__u8 tag;
};

static const unsigned raw_width_codes[] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
					    X86_WIDTH_32, X86_WIDTH_64 };

/* ---------------------------------------------------------------- */
/* The generated composition, exactly as `X86_SIM_L_EXEC_MOVX_REG`   */
/* orders it: `FLAGS` resolves with a 64-bit fallback and supplies    */
/* both the writeback width and, when `AUX` is zero, the source width.*/

static struct movx_result generated_movx_reg(__u64 old, __u8 old_tag,
					     __u64 src_raw, unsigned op,
					     unsigned flags, unsigned aux)
{
	union reg_storage storage = { .q = old };
	struct movx_result out;
	__u8 tag = old_tag;
	unsigned width = flags ? flags : X86_WIDTH_64;
	unsigned src_width = aux ? aux : width;
	__u64 value = src_raw;

	if (op == X86_OP_MOVSX_REG)
		value = kprog_x86_sign_extend_value(value, src_width);
	else
		value = KPROG_X86_APPLY_WIDTH(value, src_width);

	switch (width) {
	case X86_WIDTH_8:
		KPROG_X86_WRITE_REG8(storage, tag, value, 0U, 0U);
		break;
	case X86_WIDTH_16:
		KPROG_X86_WRITE_REG16(storage, tag, value, 0U);
		break;
	case X86_WIDTH_32:
		KPROG_X86_WRITE_REG32(storage, tag, value, 0U);
		break;
	default:
		KPROG_X86_WRITE_REG64(storage, tag, value, 0U);
		break;
	}
	out.dst = storage.q;
	out.tag = tag;
	return out;
}

/* Independent statement of the source widening: narrow the source lane, then
 * extend it from the lane's own sign bit when the opcode is sign-extending. */
static __u64 oracle_widen(__u64 value, unsigned src_width, int sign_extend)
{
	__u64 narrow;
	__u64 sign;

	switch (src_width) {
	case X86_WIDTH_8:
		narrow = value & 0xffULL;
		sign = 0x80ULL;
		break;
	case X86_WIDTH_16:
		narrow = value & 0xffffULL;
		sign = 0x8000ULL;
		break;
	case X86_WIDTH_32:
		narrow = value & 0xffffffffULL;
		sign = 0x80000000ULL;
		break;
	default:
		return value;
	}
	if (!sign_extend)
		return narrow;
	if (narrow & sign)
		return narrow | ~(sign - 1);
	return narrow;
}

/* Independent statement of the partial-register writeback at the resolved
 * destination width; the handler always uses the low byte lane. */
static __u64 oracle_write(__u64 old, __u64 value, unsigned width)
{
	switch (width) {
	case X86_WIDTH_8:
		return (old & ~0xffULL) | (value & 0xffULL);
	case X86_WIDTH_16:
		return (old & ~0xffffULL) | (value & 0xffffULL);
	case X86_WIDTH_32:
		return value & 0xffffffffULL;
	default:
		return value;
	}
}

static struct movx_result oracle_movx_reg(__u64 old, __u8 old_tag,
					  __u64 src_raw, unsigned op,
					  unsigned flags, unsigned aux)
{
	struct movx_result out;
	unsigned width = flags ? flags : X86_WIDTH_64;
	unsigned src_width = aux ? aux : width;

	(void)old_tag;
	out.dst = oracle_write(old,
			       oracle_widen(src_raw, src_width,
					    op == X86_OP_MOVSX_REG),
			       width);
	out.tag = 0U;
	return out;
}

static int same_movx(const char *name, struct movx_result got,
		     struct movx_result want, unsigned op, unsigned flags,
		     unsigned aux, __u64 src_raw, __u64 old)
{
	if (got.dst == want.dst && got.tag == want.tag)
		return 0;
	printf("MOVX MISMATCH %s op=%#x flags=%u aux=%u src=%#llx old=%#llx "
	       "dst=%#llx/%#llx tag=%u/%u\n",
	       name, op, flags, aux, src_raw, old, got.dst, want.dst, got.tag,
	       want.tag);
	return 1;
}

static int check_movx(unsigned op, unsigned flags, unsigned aux,
		      __u64 src_raw, __u64 old, __u8 old_tag)
{
	struct movx_result got =
		generated_movx_reg(old, old_tag, src_raw, op, flags, aux);
	struct movx_result want =
		oracle_movx_reg(old, old_tag, src_raw, op, flags, aux);

	return same_movx("reg", got, want, op, flags, aux, src_raw, old);
}

static const __u64 srcs[] = { 0x0ULL,
			      1ULL,
			      0x7fULL,
			      0x80ULL,
			      0xffULL,
			      0xffffULL,
			      0x8000ULL,
			      0x7fffffffULL,
			      0xffffffffULL,
			      0x80000000ULL,
			      0xffffffffffffffffULL,
			      0x112233445566aa88ULL };
static const __u64 olds[] = { 0x0ULL, 0xffffffffffffffffULL,
			      0x1122334455667788ULL, 0xffffffffffff0000ULL };
static const unsigned ops[] = { X86_OP_MOVZX_REG, X86_OP_MOVSX_REG };

/* 4-byte and 8-byte sign extension agree by construction for every source */
/* whose high 32 bits are already the sign extension of bit 31: a `movsxd`  */
/* must be the identity on such a value.                                  */
static int check_movsxd_identity(__u64 value)
{
	struct movx_result got = generated_movx_reg(value, 0U, value,
						    X86_OP_MOVSX_REG,
						    X86_WIDTH_64, X86_WIDTH_32);

	if (got.dst == value)
		return 0;
	printf("MOVSXD IDENTITY MISMATCH value=%#llx dst=%#llx\n", value,
	       got.dst);
	return 1;
}

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x9e3779b97f4a7c15ULL;
	const unsigned n_widths =
		sizeof(raw_width_codes) / sizeof(raw_width_codes[0]);

	/* Structured grid: every (source width, destination width) code pair,
	 * including the zero fallbacks, crossed with every boundary source. */
	for (unsigned c = 0; c < sizeof(ops) / sizeof(ops[0]); c++)
		for (unsigned i = 0; i < n_widths; i++)
			for (unsigned j = 0; j < n_widths; j++)
				for (unsigned k = 0;
				     k < sizeof(srcs) / sizeof(srcs[0]); k++)
					for (unsigned l = 0; l < 4; l++) {
						fails += check_movx(
							ops[c],
							raw_width_codes[i],
							raw_width_codes[j],
							srcs[k], olds[l],
							(__u8)(l + 2));
						cases++;
					}

	/* `cdqe`/`movsxd` decoding: 32-bit source, 64-bit destination. */
	for (unsigned l = 0; l < 4; l++) {
		fails += check_movx(X86_OP_MOVSX_REG, X86_WIDTH_64,
				    X86_WIDTH_32, 0x0000000080000001ULL,
				    olds[l], 4U);
		cases++;
	}

	for (unsigned iter = 0; iter < 60000; iter++) {
		__u64 src_raw, old;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		src_raw = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		old = state;
		fails += check_movx(ops[state & 1U], raw_width_codes[state % 5],
				    raw_width_codes[(state >> 8) % 5], src_raw,
				    old, (__u8)((state >> 16) & 7U));
		cases++;
	}

	/* A `movsxd`-shaped sign extension is the identity on values that are
	 * already a sign-extended 32-bit quantity. */
	{
		const __u64 sext32[] = { 0x0ULL, 0x7fffffffULL,
					 0xffffffff80000000ULL,
					 0xffffffffffffffffULL,
					 0xffffffffffffff80ULL };
		for (unsigned i = 0;
		     i < sizeof(sext32) / sizeof(sext32[0]); i++) {
			fails += check_movsxd_identity(sext32[i]);
			cases++;
		}
	}

	printf("x86 movx reg host cross-check: OK (%u cases)\n", cases);
	if (fails) {
		printf("x86 movx reg host cross-check: %u FAILURES\n", fails);
		return 1;
	}
	return 0;
}
