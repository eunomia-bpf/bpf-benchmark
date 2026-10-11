/*
 * Host cross-check for the generated AArch64 immediate-operand-source contract
 * (generated/arm64_imm_operand.h, STEP 0127).
 *
 * Verifies KPROG_ARM64_IMM_RHS against an independent oracle that decides the
 * operand source from the opcode class (never the macro's switch), sweeping the
 * opcode over all 256 byte values with distinct immediate and register values:
 * an immediate-form opcode must return the immediate, every other opcode must
 * return the register expression. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_imm_operand_host.c -o /tmp/t_io && /tmp/t_io
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_OP_MOV_IMM 0x01U
#define ARM64_OP_MOV_REG 0x02U
#define ARM64_OP_SHIFT_IMM 0x08U
#define ARM64_OP_SHIFT_REG 0x09U

#include "generated/arm64_imm_operand.h"

#include <stdio.h>

/*
 * Independent operand-source oracle: exactly the two immediate-form opcodes
 * select the immediate; every other opcode selects the register expression.
 */
static __u64 imm_rhs_oracle(unsigned op, __u64 immediate, __u64 reg)
{
	switch (op) {
	case ARM64_OP_MOV_IMM:
	case ARM64_OP_SHIFT_IMM:
		return immediate;
	default:
		return reg;
	}
}

static int check_case(unsigned op, __u64 immediate, __u64 reg)
{
	__u64 want = imm_rhs_oracle(op, immediate, reg);
	__u64 result = KPROG_ARM64_IMM_RHS(op, immediate, reg);

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
	static const __u64 regs[] = { 0x1111, 0x2222, 0x5555555555555555ULL,
				      0xa5a5a5a5a5a5a5a5ULL };
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 256U; op++)
		for (unsigned i = 0; i < sizeof(immediates) / sizeof(immediates[0]); i++)
			for (unsigned r = 0; r < sizeof(regs) / sizeof(regs[0]); r++) {
				fails += check_case(op, immediates[i], regs[r]);
				cases++;
			}

	if (fails) {
		printf("arm64 imm operand host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 imm operand host cross-check: OK (%u cases)\n", cases);
	return 0;
}
