/*
 * Host cross-check for the generated x86-64 dispatch-family opcode-membership
 * contract (STEP 0148).
 *
 * The x86-64 simulator's `X86_SIM_L_EXEC` chain in `kprog/x86/x86_sim_local_bpf.h`
 * selected a handler for each *family* of opcodes through a hand-written
 * `(OP) == X86_OP_A || (OP) == X86_OP_B` disjunction. Each such gate now goes
 * through a generated membership macro `KPROG_X86_<FAMILY>_HANDLED(OP)` in
 * `generated/x86_dispatch_family.h`, the exact x86 twin of the AArch64
 * `KPROG_ARM64_<FAMILY>_HANDLED` contract: the map-pointer/helper-id load pair,
 * the MOVZX/MOVSX register pair, the MOV_LOAD triple, the MOV_STORE pair, the
 * ALU-immediate pair, the ALU-register triple, the CMP/TEST immediate pair, the
 * CMP/TEST register pair, the CMP/TEST memory quad, and the SHLD/SHRD immediate
 * pair.
 *
 * This oracle restates each family's membership independently of the generated
 * `||` chain (a `switch` over the raw opcode) and checks the generated macro
 * agrees over every byte value and over every named member. The raw opcode
 * numbers are declared independently of `x86_sim.h`, so a drift between the
 * spec's numbers and the architectural decode is caught here as well; the
 * generated `_Static_assert`s additionally pin them at compile time. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_dispatch_family_host.c -o /tmp/t_xdf_host
 *   /tmp/t_xdf_host
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/*
 * The raw architectural opcode numbers, declared independently of
 * `kprog/x86/x86_sim.h` so a drift in the spec's numbers is observable here:
 * each must equal the value the live header carries.
 */
#define X86_OP_ADD_IMM 0x03U
#define X86_OP_ADD_REG 0x04U
#define X86_OP_XOR_REG 0x05U
#define X86_OP_MOV_LOAD 0x06U
#define X86_OP_MOV_STORE_IMM 0x07U
#define X86_OP_MOV_STORE_REG 0x08U
#define X86_OP_ALU_IMM 0x0aU
#define X86_OP_ALU_REG 0x0bU
#define X86_OP_CMP_IMM 0x0cU
#define X86_OP_CMP_REG 0x0dU
#define X86_OP_TEST_IMM 0x0eU
#define X86_OP_TEST_REG 0x0fU
#define X86_OP_SHLD_IMM 0x1bU
#define X86_OP_SHRD_IMM 0x1cU
#define X86_OP_CMP_MEM_IMM 0x1dU
#define X86_OP_TEST_MEM_IMM 0x1eU
#define X86_OP_CMP_MEM_REG 0x1fU
#define X86_OP_MOVZX_REG 0x20U
#define X86_OP_MOVSX_REG 0x21U
#define X86_OP_MOVSX_LOAD 0x22U
#define X86_OP_MOV_LOAD_SCALAR 0x25U
#define X86_OP_MOV_LOAD_MAP_PTR 0x2cU
#define X86_OP_MOV_LOAD_HELPER_ID 0x2dU
#define X86_OP_TEST_MEM_REG 0x3bU

#include "generated/x86_dispatch_family.h"

#include <stdio.h>

/*
 * Independent membership oracle: exactly the opcodes named for a family are
 * members; every other opcode is not. The decision is a set of `switch` cases
 * over the raw opcode, never the generated `||` chain.
 */
static int family_oracle(unsigned op, unsigned family)
{
	switch (family) {
	case 0: /* movLoadPtr */
		return op == X86_OP_MOV_LOAD_MAP_PTR ||
		       op == X86_OP_MOV_LOAD_HELPER_ID;
	case 1: /* movxReg */
		return op == X86_OP_MOVZX_REG || op == X86_OP_MOVSX_REG;
	case 2: /* movLoad */
		return op == X86_OP_MOV_LOAD || op == X86_OP_MOV_LOAD_SCALAR ||
		       op == X86_OP_MOVSX_LOAD;
	case 3: /* movStore */
		return op == X86_OP_MOV_STORE_IMM || op == X86_OP_MOV_STORE_REG;
	case 4: /* aluImm */
		return op == X86_OP_ALU_IMM || op == X86_OP_ADD_IMM;
	case 5: /* aluReg */
		return op == X86_OP_ALU_REG || op == X86_OP_ADD_REG ||
		       op == X86_OP_XOR_REG;
	case 6: /* cmpImm */
		return op == X86_OP_CMP_IMM || op == X86_OP_TEST_IMM;
	case 7: /* cmpReg */
		return op == X86_OP_CMP_REG || op == X86_OP_TEST_REG;
	case 8: /* cmpMem */
		return op == X86_OP_CMP_MEM_IMM || op == X86_OP_TEST_MEM_IMM ||
		       op == X86_OP_CMP_MEM_REG || op == X86_OP_TEST_MEM_REG;
	default: /* doubleShift */
		return op == X86_OP_SHLD_IMM || op == X86_OP_SHRD_IMM;
	}
}

static int handled(unsigned op, unsigned family)
{
	switch (family) {
	case 0:
		return KPROG_X86_MOV_LOAD_PTR_HANDLED(op) ? 1 : 0;
	case 1:
		return KPROG_X86_MOVX_REG_HANDLED(op) ? 1 : 0;
	case 2:
		return KPROG_X86_MOV_LOAD_HANDLED(op) ? 1 : 0;
	case 3:
		return KPROG_X86_MOV_STORE_HANDLED(op) ? 1 : 0;
	case 4:
		return KPROG_X86_ALU_IMM_HANDLED(op) ? 1 : 0;
	case 5:
		return KPROG_X86_ALU_REG_HANDLED(op) ? 1 : 0;
	case 6:
		return KPROG_X86_CMP_IMM_HANDLED(op) ? 1 : 0;
	case 7:
		return KPROG_X86_CMP_REG_HANDLED(op) ? 1 : 0;
	case 8:
		return KPROG_X86_CMP_MEM_HANDLED(op) ? 1 : 0;
	default:
		return KPROG_X86_DOUBLE_SHIFT_HANDLED(op) ? 1 : 0;
	}
}

#define NR_FAMILIES 10U

static const char *const family_names[NR_FAMILIES] = {
	"movLoadPtr", "movxReg", "movLoad", "movStore", "aluImm",
	"aluReg", "cmpImm", "cmpReg", "cmpMem", "doubleShift",
};

/* Each family's member opcode set (2, 3, or 4 members) and its member count,
 * stated independently of the generated tables. */
static const unsigned family_members[NR_FAMILIES][4] = {
	{ X86_OP_MOV_LOAD_MAP_PTR, X86_OP_MOV_LOAD_HELPER_ID, 0, 0 },
	{ X86_OP_MOVZX_REG, X86_OP_MOVSX_REG, 0, 0 },
	{ X86_OP_MOV_LOAD, X86_OP_MOV_LOAD_SCALAR, X86_OP_MOVSX_LOAD, 0 },
	{ X86_OP_MOV_STORE_IMM, X86_OP_MOV_STORE_REG, 0, 0 },
	{ X86_OP_ALU_IMM, X86_OP_ADD_IMM, 0, 0 },
	{ X86_OP_ALU_REG, X86_OP_ADD_REG, X86_OP_XOR_REG, 0 },
	{ X86_OP_CMP_IMM, X86_OP_TEST_IMM, 0, 0 },
	{ X86_OP_CMP_REG, X86_OP_TEST_REG, 0, 0 },
	{ X86_OP_CMP_MEM_IMM, X86_OP_TEST_MEM_IMM, X86_OP_CMP_MEM_REG,
	  X86_OP_TEST_MEM_REG },
	{ X86_OP_SHLD_IMM, X86_OP_SHRD_IMM, 0, 0 },
};

static const unsigned family_count[NR_FAMILIES] = {
	2U, 2U, 3U, 2U, 2U, 3U, 2U, 2U, 4U, 2U,
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
		for (f = 0; f < NR_FAMILIES; f++)
			check_case(op, f);

	/* Every family member named explicitly, so a member whose number sits
	 * outside the swept range is still covered. */
	for (f = 0; f < NR_FAMILIES; f++)
		for (m = 0; m < family_count[f]; m++)
			check_case(family_members[f][m], f);

	/* Each family's members are distinct opcodes, so no family is
	 * accidentally self-duplicated. */
	for (f = 0; f < NR_FAMILIES; f++) {
		unsigned i;
		unsigned j;
		for (i = 0; i < family_count[f]; i++) {
			for (j = i + 1U; j < family_count[f]; j++) {
				cases++;
				if (family_members[f][i] == family_members[f][j]) {
					printf("MISMATCH family=%s duplicate member %#x\n",
					       family_names[f],
					       family_members[f][i]);
					fails++;
				}
			}
		}
	}

	if (fails) {
		printf("x86 dispatch family host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 dispatch family host cross-check: OK (%u cases)\n", cases);
	return 0;
}
