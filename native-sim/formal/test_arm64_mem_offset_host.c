/*
 * Host cross-check for the generated AArch64 memory address-offset contract.
 *
 * Verifies KPROG_ARM64_MEM_OFFSET from generated/arm64_mem_offset.h against an
 * independent oracle that reconstructs the signed offset with a different
 * expression tree (an `__int128` signed accumulator, never the macro's
 * if-nesting):
 *   base = prepost ? 0 : imm
 *   offset = hasIndex ? base + index : base        (as signed 64-bit)
 * It sweeps boundary vectors over the four (prepost, hasIndex) forms, then a
 * fixed-seed random sweep across all four forms. Exits non-zero on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_mem_offset_host.c -o /tmp/t_mo && /tmp/t_mo
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#include "generated/arm64_mem_offset.h"

#include <stdio.h>
#include <stdlib.h>

/* Independent oracle: signed accumulation via __int128, then truncate to 64. */
static __u64 offset_oracle(int prepost, int has_index, __u64 imm, __u64 index)
{
	__int128 acc = 0;

	if (!prepost)
		acc += (__int128)(__s64)imm;
	if (has_index)
		acc += (__int128)(__s64)index;
	return (__u64)(__s64)(acc & 0xffffffffffffffffLL);
}

static int check_offset(int prepost, int has_index, __u64 imm, __u64 index)
{
	__u64 res = KPROG_ARM64_MEM_OFFSET(prepost, has_index, imm, index);
	__u64 want = offset_oracle(prepost, has_index, imm, index);

	if (res != want) {
		printf("MISMATCH prepost=%d has_index=%d imm=%#llx index=%#llx "
		       "res=%#llx want=%#llx\n",
		       prepost, has_index, imm, index, res, want);
		return 1;
	}
	return 0;
}

static const __u64 imms[] = { 0x0ULL, 1ULL, 8ULL, 64ULL, ~0ULL,
			      0xfffffffffffffff8ULL, 0x8000000000000000ULL };
static const __u64 indexes[] = { 0x0ULL, 1ULL, 0x10ULL, ~0ULL,
				 0x8000000000000000ULL, 0xfffffffffffffff8ULL };

int main(void)
{
	unsigned cases = 0, fails = 0;
	__u64 state = 0x2b9d4c77e1a05f38ULL;

	for (int p = 0; p < 2; p++)
		for (int h = 0; h < 2; h++)
			for (unsigned i = 0; i < sizeof(imms) / sizeof(imms[0]); i++)
				for (unsigned j = 0;
				     j < sizeof(indexes) / sizeof(indexes[0]);
				     j++) {
					fails += check_offset(p, h, imms[i],
							      indexes[j]);
					cases++;
				}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 imm, index;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		imm = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		index = state;
		fails += check_offset((int)(iter & 1), (int)((iter >> 1) & 1),
				      imm, index);
		cases++;
	}

	if (fails) {
		printf("arm64 mem offset host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 mem offset host cross-check: OK (%u cases)\n", cases);
	return 0;
}
