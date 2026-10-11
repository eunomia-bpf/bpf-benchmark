/*
 * Host cross-check for the generated AArch64 dispatch-singleton opcode-
 * membership contract (STEP 0126): the generated
 * `generated/arm64_dispatch_singleton.h`, whose sixteen one-member membership
 * macros replace the last hand-rolled `(OP) == ARM64_OP_X` gates in the
 * simulator's `ARM64_SIM_L_EXEC` chain (NOP, MOVK, BITFIELD, CMN_IMM, CMN_REG,
 * TST_BIC_REG, BICS_REG, LOAD, STORE, LDP, STP, LOAD_D0, STORE_D0, LOAD_Q0,
 * STORE_Q0, FMOV).
 *
 * The raw architectural opcode numbers are declared here, independently of
 * kprog/arm64/arm64_sim.h, from the ARM64_OP_* values the dispatcher carries.
 * The oracle decides membership from a local `switch` over the raw opcode,
 * never from the generated macro, so a generator that named the wrong opcode —
 * or slipped an extra member into a one-member macro — diverges.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. test_arm64_dispatch_singleton_host.c \
 *      -o build/test_arm64_dispatch_singleton_host &&
 *   ./build/test_arm64_dispatch_singleton_host
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/*
 * The raw architectural opcode numbers, declared independently of
 * kprog/arm64/arm64_sim.h so the drift check is real: the generated header
 * binds these numbers to the simulator's ARM64_OP_* decode.
 */
#define ARM64_OP_NOP 0x00U
#define ARM64_OP_MOVK 0x05U
#define ARM64_OP_BITFIELD 0x12U
#define ARM64_OP_CMN_IMM 0x33U
#define ARM64_OP_CMN_REG 0x3aU
#define ARM64_OP_TST_BIC_REG 0x2cU
#define ARM64_OP_BICS_REG 0x43U
#define ARM64_OP_LOAD 0x1fU
#define ARM64_OP_STORE 0x20U
#define ARM64_OP_LDP 0x21U
#define ARM64_OP_STP 0x22U
#define ARM64_OP_LOAD_D0 0x28U
#define ARM64_OP_STORE_D0 0x29U
#define ARM64_OP_LOAD_Q0 0x2aU
#define ARM64_OP_STORE_Q0 0x2bU
#define ARM64_OP_FMOV 0x23U

#include "generated/arm64_dispatch_singleton.h"

#include <stdio.h>

/*
 * Independent membership oracle: exactly the one opcode named for a singleton
 * is a member; every other opcode is not. The decision is a `switch` over the
 * raw opcode, never the generated one-member membership macro.
 */
static int singleton_oracle(unsigned op, unsigned singleton)
{
	switch (singleton) {
	case 0: /* nop */
		return op == ARM64_OP_NOP;
	case 1: /* movk */
		return op == ARM64_OP_MOVK;
	case 2: /* bitfield */
		return op == ARM64_OP_BITFIELD;
	case 3: /* cmnImm */
		return op == ARM64_OP_CMN_IMM;
	case 4: /* cmnReg */
		return op == ARM64_OP_CMN_REG;
	case 5: /* tstBicReg */
		return op == ARM64_OP_TST_BIC_REG;
	case 6: /* bicsReg */
		return op == ARM64_OP_BICS_REG;
	case 7: /* load */
		return op == ARM64_OP_LOAD;
	case 8: /* store */
		return op == ARM64_OP_STORE;
	case 9: /* ldp */
		return op == ARM64_OP_LDP;
	case 10: /* stp */
		return op == ARM64_OP_STP;
	case 11: /* loadD0 */
		return op == ARM64_OP_LOAD_D0;
	case 12: /* storeD0 */
		return op == ARM64_OP_STORE_D0;
	case 13: /* loadQ0 */
		return op == ARM64_OP_LOAD_Q0;
	case 14: /* storeQ0 */
		return op == ARM64_OP_STORE_Q0;
	default: /* fmov */
		return op == ARM64_OP_FMOV;
	}
}

static int handled(unsigned op, unsigned singleton)
{
	switch (singleton) {
	case 0:
		return KPROG_ARM64_DISP_NOP_HANDLED(op) ? 1 : 0;
	case 1:
		return KPROG_ARM64_DISP_MOVK_HANDLED(op) ? 1 : 0;
	case 2:
		return KPROG_ARM64_DISP_BITFIELD_HANDLED(op) ? 1 : 0;
	case 3:
		return KPROG_ARM64_DISP_CMN_IMM_HANDLED(op) ? 1 : 0;
	case 4:
		return KPROG_ARM64_DISP_CMN_REG_HANDLED(op) ? 1 : 0;
	case 5:
		return KPROG_ARM64_DISP_TST_BIC_REG_HANDLED(op) ? 1 : 0;
	case 6:
		return KPROG_ARM64_DISP_BICS_REG_HANDLED(op) ? 1 : 0;
	case 7:
		return KPROG_ARM64_DISP_LOAD_HANDLED(op) ? 1 : 0;
	case 8:
		return KPROG_ARM64_DISP_STORE_HANDLED(op) ? 1 : 0;
	case 9:
		return KPROG_ARM64_DISP_LDP_HANDLED(op) ? 1 : 0;
	case 10:
		return KPROG_ARM64_DISP_STP_HANDLED(op) ? 1 : 0;
	case 11:
		return KPROG_ARM64_DISP_LOAD_D0_HANDLED(op) ? 1 : 0;
	case 12:
		return KPROG_ARM64_DISP_STORE_D0_HANDLED(op) ? 1 : 0;
	case 13:
		return KPROG_ARM64_DISP_LOAD_Q0_HANDLED(op) ? 1 : 0;
	case 14:
		return KPROG_ARM64_DISP_STORE_Q0_HANDLED(op) ? 1 : 0;
	default:
		return KPROG_ARM64_DISP_FMOV_HANDLED(op) ? 1 : 0;
	}
}

static const char *const singleton_names[16] = {
	"nop", "movk", "bitfield", "cmnImm", "cmnReg", "tstBicReg",
	"bicsReg", "load", "store", "ldp", "stp", "loadD0",
	"storeD0", "loadQ0", "storeQ0", "fmov",
};

static const unsigned singleton_member[16] = {
	ARM64_OP_NOP, ARM64_OP_MOVK, ARM64_OP_BITFIELD, ARM64_OP_CMN_IMM,
	ARM64_OP_CMN_REG, ARM64_OP_TST_BIC_REG, ARM64_OP_BICS_REG,
	ARM64_OP_LOAD, ARM64_OP_STORE, ARM64_OP_LDP, ARM64_OP_STP,
	ARM64_OP_LOAD_D0, ARM64_OP_STORE_D0, ARM64_OP_LOAD_Q0,
	ARM64_OP_STORE_Q0, ARM64_OP_FMOV,
};

static unsigned cases;
static unsigned fails;

static void check_case(unsigned op, unsigned singleton)
{
	int got = handled(op, singleton);
	int want = singleton_oracle(op, singleton);

	cases++;
	if (got != want) {
		printf("MISMATCH singleton=%s op=%#x got=%d want=%d\n",
		       singleton_names[singleton], op, got, want);
		fails++;
	}
}

int main(void)
{
	unsigned op;
	unsigned s;
	unsigned t;

	/* Every byte value against every singleton: a member must be named and
	 * a non-member must not. */
	for (op = 0; op < 256U; op++)
		for (s = 0; s < 16U; s++)
			check_case(op, s);

	/* Every singleton member named explicitly, so a member whose number
	 * sits outside the swept range is still covered. */
	for (s = 0; s < 16U; s++)
		check_case(singleton_member[s], s);

	/* Each singleton's opcode is distinct from every other singleton's, so
	 * no opcode is gated by two singleton arms. */
	for (s = 0; s < 16U; s++) {
		cases++;
		for (t = 0; t < s; t++) {
			if (singleton_member[s] == singleton_member[t]) {
				printf("MISMATCH singleton=%s duplicate "
				       "opcode %#x (with %s)\n",
				       singleton_names[s], singleton_member[s],
				       singleton_names[t]);
				fails++;
			}
		}
	}

	if (fails) {
		printf("arm64 dispatch singleton host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("arm64 dispatch singleton host cross-check: OK (%u cases)\n",
	       cases);
	return 0;
}
