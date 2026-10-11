/*
 * Host cross-check for the generated AArch64 ALU-arm operand-source-selection
 * contract (generated/arm64_alu_operand_select.h).
 *
 * Verifies KPROG_ARM64_ALU_OPERAND_SELECT against an independent oracle that
 * decides from the opcode class (never the macro's switch), sweeping the opcode
 * over all 256 byte values: the ALU immediate opcode must select the immediate
 * form (1), every other opcode must select the register form (0). The default is
 * the register form, so the sweep never aborts. Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_arm64_alu_operand_select_host.c -o /tmp/t_as && /tmp/t_as
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#define ARM64_OP_ALU_IMM 0x06U
#define ARM64_OP_ALU_REG 0x07U

#include "generated/arm64_alu_operand_select.h"

#include <stdio.h>

/*
 * Independent operand-source oracle: exactly the ALU immediate opcode selects
 * the immediate form; every other opcode selects the register form. Returns 1
 * for the immediate and 0 for the register form.
 */
static int select_oracle(unsigned op)
{
	switch (op) {
	case ARM64_OP_ALU_IMM:
		return 1;
	default:
		return 0;
	}
}

static int check_case(unsigned op)
{
	int want = select_oracle(op);
	int result = KPROG_ARM64_ALU_OPERAND_SELECT(op);

	if (result != want) {
		printf("MISMATCH op=%#x result=%d want=%d\n", op, result, want);
		return 1;
	}
	return 0;
}

int main(void)
{
	unsigned cases = 0, fails = 0;

	for (unsigned op = 0; op < 256U; op++) {
		fails += check_case(op);
		cases++;
	}

	if (fails) {
		printf("arm64 alu operand select host cross-check: FAILED (%u mismatches)\n",
		       fails);
		return 1;
	}
	printf("arm64 alu operand select host cross-check: OK (%u cases)\n", cases);
	return 0;
}
