/*
 * Host cross-check for the generated AArch64 flag-family operand-source
 * contract (generated/arm64_flag_operand.h).
 *
 * Verifies KPROG_ARM64_FLAG_RHS against an independent oracle that decides the
 * right-hand operand from the opcode class (never the macro's switch), sweeping
 * the opcode over all 256 byte values with distinct immediate and register
 * values: an immediate-form opcode must return the immediate, every other opcode
 * must return the register expression. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_flag_operand_host.c -o /tmp/t_fo && /tmp/t_fo
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_OP_SUBS_IMM 0x30U
#define ARM64_OP_SUBS_REG 0x32U
#define ARM64_OP_ADDS_IMM 0x31U
#define ARM64_OP_ADDS_REG 0x42U
#define ARM64_OP_CMP_IMM 0x16U
#define ARM64_OP_CMP_REG 0x17U
#define ARM64_OP_TST_IMM 0x18U
#define ARM64_OP_TST_REG 0x19U
#define ARM64_OP_ANDS_IMM 0x37U
#define ARM64_OP_ANDS_REG 0x2dU
#define ARM64_OP_CCMP_IMM 0x1aU
#define ARM64_OP_CCMP_REG 0x1bU

#include "generated/arm64_flag_operand.h"

#include <stdio.h>

/*
 * Independent operand-source oracle: exactly the six immediate-form opcodes
 * select the immediate; every other opcode selects the register expression.
 * Returns 1 for the immediate and 0 for the register expression.
 */
static int flag_rhs_oracle(unsigned op, __u64 immediate, __u64 reg, __u64 *want)
{
	switch (op) {
	case ARM64_OP_SUBS_IMM:
	case ARM64_OP_ADDS_IMM:
	case ARM64_OP_CMP_IMM:
	case ARM64_OP_TST_IMM:
	case ARM64_OP_ANDS_IMM:
	case ARM64_OP_CCMP_IMM:
		*want = immediate;
		return 1;
	default:
		*want = reg;
		return 0;
	}
}

static int check_case(unsigned op, __u64 immediate, __u64 reg)
{
	__u64 want;
	__u64 result = KPROG_ARM64_FLAG_RHS(op, immediate, reg);

	flag_rhs_oracle(op, immediate, reg, &want);
	if (result != want) {
		printf("MISMATCH op=%#x imm=%#llx reg=%#llx result=%#llx want=%#llx\n",
		       op, immediate, reg, result, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	static const __u64 immediates[] = { 0, 1, 0x80, 0xdeadbeefcafef00dULL, ~0ULL };
	static const __u64 regs[] = { 0x1111, 0x2222, 0x5555555555555555ULL, 0xa5a5a5a5a5a5a5a5ULL };
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 256U; op++)
		for (unsigned i = 0; i < sizeof(immediates) / sizeof(immediates[0]); i++)
			for (unsigned r = 0; r < sizeof(regs) / sizeof(regs[0]); r++) {
				fails += check_case(op, immediates[i], regs[r]);
				cases++;
			}

	if (fails) {
		printf("arm64 flag operand host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 flag operand host cross-check: OK (%u cases)\n", cases);
	return 0;
}
