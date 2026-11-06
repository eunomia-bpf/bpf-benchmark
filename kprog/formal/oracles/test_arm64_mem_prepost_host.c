/*
 * Host cross-check for the AArch64 pre/post-indexed address-writeback contract.
 *
 * The contract is a decode of the packed memory-flag byte of an `ARM64_AUX_MEM`
 * operand into the address-writeback form: which of the two writeback bits is
 * set, whether the address offset therefore suppresses the immediate, and the
 * immediate each writeback would apply. There is no memory or register effect in
 * this contract, so the oracle compares the generated macros with an independent
 * model that never looks at the generated code:
 *
 *   Part 1 checks the generated constants against independent literals and the
 *   named bits against kprog/arm64/arm64_sim.h's ARM64_MEM_PRE/MEM_POST.
 *
 *   Part 2 drives the generated decode/select macros against the independent
 *   model over every flag byte, low-byte noise that must not leak into the flag
 *   byte, and a spread of immediates.
 *
 * Exit convention: each part returns 0 on failure and the number of cases on
 * success; main returns 1 if any part returned 0.
 */
#include <stdio.h>
#include <string.h>

typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define ARM64_MEM_PRE 1U
#define ARM64_MEM_POST 2U

#include "generated/arm64_mem_prepost.h"

/* ------------------------------------------------------------------ */
/* Independent model: the top byte of the packed AUX word, and the two */
/* writeback gates over it.                                            */
/* ------------------------------------------------------------------ */

static __u32 model_flags(__u32 aux)
{
	return (__u32)((aux >> 24) & 0xffU);
}

static int model_pre(__u32 aux)
{
	return (model_flags(aux) & ARM64_MEM_PRE) != 0U;
}

static int model_post(__u32 aux)
{
	return (model_flags(aux) & ARM64_MEM_POST) != 0U;
}

static int model_suppress(__u32 aux)
{
	return model_pre(aux) || model_post(aux);
}

static __u64 model_pre_delta(__u32 aux, __u64 imm)
{
	return model_pre(aux) ? imm : 0ULL;
}

static __u64 model_post_delta(__u32 aux, __u64 imm)
{
	return model_post(aux) ? imm : 0ULL;
}

/* ------------------------------------------------------------------ */
/* Part 1: generated tables and constants.                             */
/* ------------------------------------------------------------------ */

static unsigned part1(void)
{
	unsigned cases = 0;

	if (KPROG_ARM64_MEM_PRE_BIT != ARM64_MEM_PRE) {
		fprintf(stderr, "pre/post pre-bit drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_MEM_POST_BIT != ARM64_MEM_POST) {
		fprintf(stderr, "pre/post post-bit drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_MEM_FLAGS_SHIFT != 24U ||
	    KPROG_ARM64_MEM_FLAGS_MASK != 0xffU) {
		fprintf(stderr, "pre/post flag-decode drift\n");
		return 0;
	}
	cases++;

	if (KPROG_ARM64_MEM_PRE_BIT == KPROG_ARM64_MEM_POST_BIT) {
		fprintf(stderr, "pre/post bits collide\n");
		return 0;
	}
	cases++;

	return cases;
}

/* ------------------------------------------------------------------ */
/* Part 2: full decode/select vs. the independent model.               */
/* ------------------------------------------------------------------ */

static unsigned part2(void)
{
	static const __u64 imms[] = { 0ULL, 1ULL, 0x40ULL, 0x1000ULL,
				      0xffffffffffffffffULL, 0x8000000000000000ULL };
	unsigned cases = 0, fails = 0;
	unsigned f, ni, xi;

	for (f = 0U; f < 256U; f++)
		for (ni = 0U; ni < 3U; ni++)
			for (xi = 0U; xi < 6U; xi++) {
				unsigned low = ni == 0U ? 0U
					     : ni == 1U ? 0xffU : 0x5aU;
				__u32 aux = ((__u32)f << 24) | low;
				__u64 imm = imms[xi];
				unsigned got_flags =
					KPROG_ARM64_MEM_PREPOST_FLAGS(aux);
				int got_suppress =
					KPROG_ARM64_MEM_PREPOST_SUPPRESS(aux) != 0;
				__u64 got_pre =
					KPROG_ARM64_MEM_PREPOST_PRE_DELTA(aux, imm);
				__u64 got_post =
					KPROG_ARM64_MEM_PREPOST_POST_DELTA(aux, imm);

				if (got_flags != model_flags(aux)) {
					fprintf(stderr, "flags mismatch f=%u low=%#x "
							"got=%u want=%u\n",
						f, low, got_flags,
						model_flags(aux));
					fails++;
				}
				if (got_suppress != model_suppress(aux)) {
					fprintf(stderr, "suppress mismatch f=%u "
							"got=%d want=%d\n",
						f, got_suppress,
						model_suppress(aux));
					fails++;
				}
				if (got_pre != model_pre_delta(aux, imm)) {
					fprintf(stderr, "pre delta mismatch f=%u imm=%#llx "
							"got=%#llx want=%#llx\n",
						f, (unsigned long long)imm,
						(unsigned long long)got_pre,
						(unsigned long long)model_pre_delta(aux, imm));
					fails++;
				}
				if (got_post != model_post_delta(aux, imm)) {
					fprintf(stderr, "post delta mismatch f=%u imm=%#llx "
							"got=%#llx want=%#llx\n",
						f, (unsigned long long)imm,
						(unsigned long long)got_post,
						(unsigned long long)model_post_delta(aux, imm));
					fails++;
				}
				cases++;
			}

	if (fails) {
		printf("arm64 pre/post host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 0;
	}
	printf("arm64 pre/post host cross-check: OK (%u cases)\n", cases);
	return cases;
}

int main(void)
{
	unsigned p1, p2;

	p1 = part1();
	p2 = part2();

	if (p1 == 0 || p2 == 0)
		return 1;
	return 0;
}
