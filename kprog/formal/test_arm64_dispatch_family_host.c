/*
 * Host cross-check for the generated AArch64 dispatch-family opcode-membership
 * contract (generated/arm64_dispatch_family.h, STEP 0125).
 *
 * Verifies all eight KPROG_ARM64_<F>_HANDLED(OP) membership macros against an
 * independent oracle that decides each family's membership from the opcode class
 * (never the macro's `||` chain), sweeping the opcode over all 256 byte values
 * plus each family member explicitly. The oracle restates the member sets with
 * its own raw ARM64_OP_* numbers, so a drifted member, a swapped pair, or a
 * membership macro that stopped naming one of its two opcodes shows up as a
 * disagreeing answer. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_dispatch_family_host.c -o /tmp/t_df &&
 *   /tmp/t_df
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/*
 * The raw architectural opcode numbers, declared independently of
 * kprog/arm64/arm64_sim.h so this oracle is the second, separate statement of
 * the family membership. The generated header is included afterwards; its own
 * _Static_asserts re-bind these numbers to the simulator's decode.
 */
#define ARM64_OP_ALU_IMM 0x06U
#define ARM64_OP_ALU_REG 0x07U
#define ARM64_OP_SHIFT_IMM 0x08U
#define ARM64_OP_SHIFT_REG 0x09U
#define ARM64_OP_SUBS_IMM 0x30U
#define ARM64_OP_SUBS_REG 0x32U
#define ARM64_OP_ADDS_IMM 0x31U
#define ARM64_OP_ADDS_REG 0x42U
#define ARM64_OP_CMP_IMM 0x16U
#define ARM64_OP_CMP_REG 0x17U
#define ARM64_OP_TST_IMM 0x18U
#define ARM64_OP_TST_REG 0x19U
#define ARM64_OP_ANDS_REG 0x2dU
#define ARM64_OP_ANDS_IMM 0x37U
#define ARM64_OP_CCMP_IMM 0x1aU
#define ARM64_OP_CCMP_REG 0x1bU

#include "generated/arm64_dispatch_family.h"

#include <stdio.h>

/*
 * Independent membership oracle: exactly the two opcodes named for a family are
 * members; every other opcode is not. The decision is a set of `switch` cases
 * over the raw opcode, never the generated `||` chain.
 */
static int family_oracle(unsigned op, unsigned family)
{
	switch (family) {
	case 0: /* alu */
		return op == ARM64_OP_ALU_IMM || op == ARM64_OP_ALU_REG;
	case 1: /* shiftOp */
		return op == ARM64_OP_SHIFT_IMM || op == ARM64_OP_SHIFT_REG;
	case 2: /* subs */
		return op == ARM64_OP_SUBS_IMM || op == ARM64_OP_SUBS_REG;
	case 3: /* adds */
		return op == ARM64_OP_ADDS_IMM || op == ARM64_OP_ADDS_REG;
	case 4: /* cmp */
		return op == ARM64_OP_CMP_IMM || op == ARM64_OP_CMP_REG;
	case 5: /* tst */
		return op == ARM64_OP_TST_IMM || op == ARM64_OP_TST_REG;
	case 6: /* ands */
		return op == ARM64_OP_ANDS_REG || op == ARM64_OP_ANDS_IMM;
	default: /* ccmp */
		return op == ARM64_OP_CCMP_IMM || op == ARM64_OP_CCMP_REG;
	}
}

static int handled(unsigned op, unsigned family)
{
	switch (family) {
	case 0:
		return KPROG_ARM64_ALU_HANDLED(op) ? 1 : 0;
	case 1:
		return KPROG_ARM64_SHIFT_OP_HANDLED(op) ? 1 : 0;
	case 2:
		return KPROG_ARM64_SUBS_HANDLED(op) ? 1 : 0;
	case 3:
		return KPROG_ARM64_ADDS_HANDLED(op) ? 1 : 0;
	case 4:
		return KPROG_ARM64_CMP_HANDLED(op) ? 1 : 0;
	case 5:
		return KPROG_ARM64_TST_HANDLED(op) ? 1 : 0;
	case 6:
		return KPROG_ARM64_ANDS_HANDLED(op) ? 1 : 0;
	default:
		return KPROG_ARM64_CCMP_HANDLED(op) ? 1 : 0;
	}
}

static const char *const family_names[8] = {
	"alu", "shiftOp", "subs", "adds", "cmp", "tst", "ands", "ccmp",
};

static const unsigned family_members[8][2] = {
	{ ARM64_OP_ALU_IMM, ARM64_OP_ALU_REG },
	{ ARM64_OP_SHIFT_IMM, ARM64_OP_SHIFT_REG },
	{ ARM64_OP_SUBS_IMM, ARM64_OP_SUBS_REG },
	{ ARM64_OP_ADDS_IMM, ARM64_OP_ADDS_REG },
	{ ARM64_OP_CMP_IMM, ARM64_OP_CMP_REG },
	{ ARM64_OP_TST_IMM, ARM64_OP_TST_REG },
	{ ARM64_OP_ANDS_REG, ARM64_OP_ANDS_IMM },
	{ ARM64_OP_CCMP_IMM, ARM64_OP_CCMP_REG },
};

static unsigned cases;
static unsigned fails;

static void check_case(unsigned op, unsigned family)
{
	int got = handled(op, family);
	int want = family_oracle(op, family);

	cases++;
	if (got != want) {
		printf("MISMATCH family=%s op=%#x got=%d want=%d\n",
		       family_names[family], op, got, want);
		fails++;
	}
}

int main(void)
{
	unsigned op;
	unsigned f;
	unsigned m;

	/* Every byte value against every family: a member must be named and a
	 * non-member must not. */
	for (op = 0; op < 256U; op++)
		for (f = 0; f < 8U; f++)
			check_case(op, f);

	/* Every family member named explicitly, so a member whose number sits
	 * outside the swept range is still covered. */
	for (f = 0; f < 8U; f++)
		for (m = 0; m < 2U; m++)
			check_case(family_members[f][m], f);

	/* Each family's two members are distinct opcodes, so no family is
	 * accidentally self-duplicated. */
	for (f = 0; f < 8U; f++) {
		cases++;
		if (family_members[f][0] == family_members[f][1]) {
			printf("MISMATCH family=%s duplicate member %#x\n",
			       family_names[f], family_members[f][0]);
			fails++;
		}
	}

	if (fails) {
		printf("arm64 dispatch family host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 dispatch family host cross-check: OK (%u cases)\n", cases);
	return 0;
}
