/*
 * Host cross-check for the generated AArch64 branch-predicate contract.
 *
 * Verifies KPROG_ARM64_BRANCH_TEST from generated/arm64_branch.h against an
 * independent oracle that tests the register directly (never the macro's shift
 * and mask):
 *   - CBZ:  taken when the value is zero
 *   - CBNZ: taken when it is not zero
 *   - TBZ:  taken when bit (index % 64) is zero
 *   - TBNZ: taken when it is one
 * It sweeps explicit boundary vectors and bit indices, then a fixed-seed random
 * sweep, and checks that the macro is total over the four contiguous kinds (no
 * unsupported arm). Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_branch_host.c -o /tmp/t_branch && /tmp/t_branch
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "generated/arm64_branch.h"

#include <stdio.h>

static int branch_oracle(unsigned kind, __u64 value, __u64 bit)
{
	unsigned b = (unsigned)(bit & 63);

	switch (kind) {
	case KPROG_ARM64_BRANCH_CBZ:
		return value == 0;
	case KPROG_ARM64_BRANCH_CBNZ:
		return value != 0;
	case KPROG_ARM64_BRANCH_TBZ:
		return ((value >> b) & 1ULL) == 0;
	case KPROG_ARM64_BRANCH_TBNZ:
		return ((value >> b) & 1ULL) == 1;
	}
	return 0;
}

static int check_branch(unsigned kind, __u64 value, __u64 bit)
{
	int res = KPROG_ARM64_BRANCH_TEST(kind, value, bit);
	int want = branch_oracle(kind, value, bit);

	if ((res != 0) != (want != 0)) {
		printf("MISMATCH branch kind=%u value=%#llx bit=%llu "
		       "res=%d want=%d\n", kind, value, bit, res, want);
		return 1;
	}
	return 0;
}

static const unsigned kinds[] = {
	KPROG_ARM64_BRANCH_CBZ, KPROG_ARM64_BRANCH_CBNZ,
	KPROG_ARM64_BRANCH_TBZ, KPROG_ARM64_BRANCH_TBNZ,
};

int main(void)
{
	static const __u64 values[] = {
		0x0ULL, 0x1ULL, ~0ULL, 0x8000000000000000ULL,
		0x80000000ULL, 0x4ULL, 0x2ULL, 0xdeadbeefcafebabeULL,
	};
	static const __u64 bits[] = { 0ULL, 1ULL, 2ULL, 7ULL, 31ULL, 63ULL, 64ULL, 127ULL };
	unsigned cases = 0, fails = 0;
	__u64 state = 0xfedcba9876543210ULL;

	for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); i++)
		for (unsigned b = 0; b < sizeof(bits) / sizeof(bits[0]); b++)
			for (unsigned k = 0; k < sizeof(kinds) / sizeof(kinds[0]);
			     k++) {
				fails += check_branch(kinds[k], values[i], bits[b]);
				cases++;
			}

	for (unsigned iter = 0; iter < 20000; iter++) {
		__u64 value, bit;

		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		value = state;
		state = state * 6364136223846793005ULL + 1442695040888963407ULL;
		bit = state;
		for (unsigned k = 0; k < sizeof(kinds) / sizeof(kinds[0]); k++) {
			fails += check_branch(kinds[k], value, bit);
			cases++;
		}
	}

	if (fails) {
		printf("arm64 branch host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 branch host cross-check: OK (%u cases)\n", cases);
	return 0;
}
