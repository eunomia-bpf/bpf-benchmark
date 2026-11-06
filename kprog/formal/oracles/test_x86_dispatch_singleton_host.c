/*
 * Host cross-check for the generated x86-64 dispatch-singleton opcode-
 * membership contract (Step 0149): the generated
 * `generated/x86_dispatch_singleton.h`, whose forty-three one-member
 * membership macros replace the hand-rolled `(OP) == X86_OP_X` gates in the
 * simulator's `X86_SIM_L_EXEC` chain.
 *
 * The raw architectural opcode numbers are declared here, independently of
 * kprog/x86/x86_sim.h, from the X86_OP_* values the dispatcher carries. The
 * oracle decides membership from a local `switch` over the raw opcode, never
 * from the generated macro, so a generator that named the wrong opcode -- or
 * slipped an extra member into a one-member macro -- diverges.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. test_x86_dispatch_singleton_host.c \
 *      -o build/test_x86_dispatch_singleton_host &&
 *   ./build/test_x86_dispatch_singleton_host
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

/*
 * The raw architectural opcode numbers, declared independently of
 * kprog/x86/x86_sim.h so the drift check is real: the generated header
 * binds these numbers to the simulator's X86_OP_* decode.
 */
#define X86_OP_NOP 0x00U
#define X86_OP_CALL_MEMCPY 0x3fU
#define X86_OP_CALL_MEMSET 0x3cU
#define X86_OP_CALL_MEMCPY_REG 0x46U
#define X86_OP_CALL_MEMSET_REG 0x45U
#define X86_OP_CALL_REG 0x2fU
#define X86_OP_MOV_IMM 0x01U
#define X86_OP_MOV_REG 0x02U
#define X86_OP_MOVBE_LOAD 0x28U
#define X86_OP_MOVBE_STORE 0x29U
#define X86_OP_LOAD_XMM0 0x30U
#define X86_OP_STORE_XMM0 0x31U
#define X86_OP_LEA 0x09U
#define X86_OP_ALU_MEM 0x23U
#define X86_OP_ALU_MEM_UNARY 0x32U
#define X86_OP_ALU_MEM_IMM 0x33U
#define X86_OP_ALU_MEM_REG 0x36U
#define X86_OP_CMP_REG_MEM 0x24U
#define X86_OP_CMOV 0x15U
#define X86_OP_CMOV_MEM 0x40U
#define X86_OP_SETCC 0x16U
#define X86_OP_SETCC_MEM 0x3eU
#define X86_OP_BSWAP 0x17U
#define X86_OP_POPCNT 0x18U
#define X86_OP_SHIFTX 0x26U
#define X86_OP_SHIFTX_MEM 0x2aU
#define X86_OP_RORX 0x27U
#define X86_OP_RORX_MEM 0x2bU
#define X86_OP_BZHI 0x34U
#define X86_OP_BZHI_MEM 0x35U
#define X86_OP_BT 0x37U
#define X86_OP_BT_IMM 0x42U
#define X86_OP_BT_MEM_IMM 0x43U
#define X86_OP_IMUL_IMM 0x38U
#define X86_OP_IMUL_MEM_IMM 0x41U
#define X86_OP_MULX 0x39U
#define X86_OP_REP_MOVS 0x3aU
#define X86_OP_ANDN 0x3dU
#define X86_OP_ANDN_MEM 0x44U
#define X86_OP_XCHG 0x19U
#define X86_OP_DIV 0x1aU
#define X86_OP_PUSH 0x12U
#define X86_OP_POP 0x13U

#include "generated/x86_dispatch_singleton.h"

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
		return op == X86_OP_NOP;
	case 1: /* callMemcpy */
		return op == X86_OP_CALL_MEMCPY;
	case 2: /* callMemset */
		return op == X86_OP_CALL_MEMSET;
	case 3: /* callMemcpyReg */
		return op == X86_OP_CALL_MEMCPY_REG;
	case 4: /* callMemsetReg */
		return op == X86_OP_CALL_MEMSET_REG;
	case 5: /* callReg */
		return op == X86_OP_CALL_REG;
	case 6: /* movImm */
		return op == X86_OP_MOV_IMM;
	case 7: /* movReg */
		return op == X86_OP_MOV_REG;
	case 8: /* movbeLoad */
		return op == X86_OP_MOVBE_LOAD;
	case 9: /* movbeStore */
		return op == X86_OP_MOVBE_STORE;
	case 10: /* loadXmm0 */
		return op == X86_OP_LOAD_XMM0;
	case 11: /* storeXmm0 */
		return op == X86_OP_STORE_XMM0;
	case 12: /* lea */
		return op == X86_OP_LEA;
	case 13: /* aluMem */
		return op == X86_OP_ALU_MEM;
	case 14: /* aluMemUnary */
		return op == X86_OP_ALU_MEM_UNARY;
	case 15: /* aluMemImm */
		return op == X86_OP_ALU_MEM_IMM;
	case 16: /* aluMemReg */
		return op == X86_OP_ALU_MEM_REG;
	case 17: /* cmpRegMem */
		return op == X86_OP_CMP_REG_MEM;
	case 18: /* cmov */
		return op == X86_OP_CMOV;
	case 19: /* cmovMem */
		return op == X86_OP_CMOV_MEM;
	case 20: /* setcc */
		return op == X86_OP_SETCC;
	case 21: /* setccMem */
		return op == X86_OP_SETCC_MEM;
	case 22: /* bswap */
		return op == X86_OP_BSWAP;
	case 23: /* popcnt */
		return op == X86_OP_POPCNT;
	case 24: /* shiftx */
		return op == X86_OP_SHIFTX;
	case 25: /* shiftxMem */
		return op == X86_OP_SHIFTX_MEM;
	case 26: /* rorx */
		return op == X86_OP_RORX;
	case 27: /* rorxMem */
		return op == X86_OP_RORX_MEM;
	case 28: /* bzhi */
		return op == X86_OP_BZHI;
	case 29: /* bzhiMem */
		return op == X86_OP_BZHI_MEM;
	case 30: /* bt */
		return op == X86_OP_BT;
	case 31: /* btImm */
		return op == X86_OP_BT_IMM;
	case 32: /* btMemImm */
		return op == X86_OP_BT_MEM_IMM;
	case 33: /* imulImm */
		return op == X86_OP_IMUL_IMM;
	case 34: /* imulMemImm */
		return op == X86_OP_IMUL_MEM_IMM;
	case 35: /* mulx */
		return op == X86_OP_MULX;
	case 36: /* repMovs */
		return op == X86_OP_REP_MOVS;
	case 37: /* andn */
		return op == X86_OP_ANDN;
	case 38: /* andnMem */
		return op == X86_OP_ANDN_MEM;
	case 39: /* xchg */
		return op == X86_OP_XCHG;
	case 40: /* div */
		return op == X86_OP_DIV;
	case 41: /* push */
		return op == X86_OP_PUSH;
	default: /* pop */
		return op == X86_OP_POP;
	}
}

static int handled(unsigned op, unsigned singleton)
{
	switch (singleton) {
	case 0:
		return KPROG_X86_DISP_NOP_HANDLED(op) ? 1 : 0;
	case 1:
		return KPROG_X86_DISP_CALL_MEMCPY_HANDLED(op) ? 1 : 0;
	case 2:
		return KPROG_X86_DISP_CALL_MEMSET_HANDLED(op) ? 1 : 0;
	case 3:
		return KPROG_X86_DISP_CALL_MEMCPY_REG_HANDLED(op) ? 1 : 0;
	case 4:
		return KPROG_X86_DISP_CALL_MEMSET_REG_HANDLED(op) ? 1 : 0;
	case 5:
		return KPROG_X86_DISP_CALL_REG_HANDLED(op) ? 1 : 0;
	case 6:
		return KPROG_X86_DISP_MOV_IMM_HANDLED(op) ? 1 : 0;
	case 7:
		return KPROG_X86_DISP_MOV_REG_HANDLED(op) ? 1 : 0;
	case 8:
		return KPROG_X86_DISP_MOVBE_LOAD_HANDLED(op) ? 1 : 0;
	case 9:
		return KPROG_X86_DISP_MOVBE_STORE_HANDLED(op) ? 1 : 0;
	case 10:
		return KPROG_X86_DISP_LOAD_XMM0_HANDLED(op) ? 1 : 0;
	case 11:
		return KPROG_X86_DISP_STORE_XMM0_HANDLED(op) ? 1 : 0;
	case 12:
		return KPROG_X86_DISP_LEA_HANDLED(op) ? 1 : 0;
	case 13:
		return KPROG_X86_DISP_ALU_MEM_HANDLED(op) ? 1 : 0;
	case 14:
		return KPROG_X86_DISP_ALU_MEM_UNARY_HANDLED(op) ? 1 : 0;
	case 15:
		return KPROG_X86_DISP_ALU_MEM_IMM_HANDLED(op) ? 1 : 0;
	case 16:
		return KPROG_X86_DISP_ALU_MEM_REG_HANDLED(op) ? 1 : 0;
	case 17:
		return KPROG_X86_DISP_CMP_REG_MEM_HANDLED(op) ? 1 : 0;
	case 18:
		return KPROG_X86_DISP_CMOV_HANDLED(op) ? 1 : 0;
	case 19:
		return KPROG_X86_DISP_CMOV_MEM_HANDLED(op) ? 1 : 0;
	case 20:
		return KPROG_X86_DISP_SETCC_HANDLED(op) ? 1 : 0;
	case 21:
		return KPROG_X86_DISP_SETCC_MEM_HANDLED(op) ? 1 : 0;
	case 22:
		return KPROG_X86_DISP_BSWAP_HANDLED(op) ? 1 : 0;
	case 23:
		return KPROG_X86_DISP_POPCNT_HANDLED(op) ? 1 : 0;
	case 24:
		return KPROG_X86_DISP_SHIFTX_HANDLED(op) ? 1 : 0;
	case 25:
		return KPROG_X86_DISP_SHIFTX_MEM_HANDLED(op) ? 1 : 0;
	case 26:
		return KPROG_X86_DISP_RORX_HANDLED(op) ? 1 : 0;
	case 27:
		return KPROG_X86_DISP_RORX_MEM_HANDLED(op) ? 1 : 0;
	case 28:
		return KPROG_X86_DISP_BZHI_HANDLED(op) ? 1 : 0;
	case 29:
		return KPROG_X86_DISP_BZHI_MEM_HANDLED(op) ? 1 : 0;
	case 30:
		return KPROG_X86_DISP_BT_HANDLED(op) ? 1 : 0;
	case 31:
		return KPROG_X86_DISP_BT_IMM_HANDLED(op) ? 1 : 0;
	case 32:
		return KPROG_X86_DISP_BT_MEM_IMM_HANDLED(op) ? 1 : 0;
	case 33:
		return KPROG_X86_DISP_IMUL_IMM_HANDLED(op) ? 1 : 0;
	case 34:
		return KPROG_X86_DISP_IMUL_MEM_IMM_HANDLED(op) ? 1 : 0;
	case 35:
		return KPROG_X86_DISP_MULX_HANDLED(op) ? 1 : 0;
	case 36:
		return KPROG_X86_DISP_REP_MOVS_HANDLED(op) ? 1 : 0;
	case 37:
		return KPROG_X86_DISP_ANDN_HANDLED(op) ? 1 : 0;
	case 38:
		return KPROG_X86_DISP_ANDN_MEM_HANDLED(op) ? 1 : 0;
	case 39:
		return KPROG_X86_DISP_XCHG_HANDLED(op) ? 1 : 0;
	case 40:
		return KPROG_X86_DISP_DIV_HANDLED(op) ? 1 : 0;
	case 41:
		return KPROG_X86_DISP_PUSH_HANDLED(op) ? 1 : 0;
	default:
		return KPROG_X86_DISP_POP_HANDLED(op) ? 1 : 0;
	}
}

static const char *const singleton_names[43] = {
	"nop", "callMemcpy", "callMemset", "callMemcpyReg",
	"callMemsetReg", "callReg", "movImm", "movReg",
	"movbeLoad", "movbeStore", "loadXmm0", "storeXmm0",
	"lea", "aluMem", "aluMemUnary", "aluMemImm",
	"aluMemReg", "cmpRegMem", "cmov", "cmovMem",
	"setcc", "setccMem", "bswap", "popcnt",
	"shiftx", "shiftxMem", "rorx", "rorxMem",
	"bzhi", "bzhiMem", "bt", "btImm",
	"btMemImm", "imulImm", "imulMemImm", "mulx",
	"repMovs", "andn", "andnMem", "xchg",
	"div", "push", "pop",
};

static const unsigned singleton_member[43] = {
	X86_OP_NOP, X86_OP_CALL_MEMCPY, X86_OP_CALL_MEMSET, X86_OP_CALL_MEMCPY_REG,
	X86_OP_CALL_MEMSET_REG, X86_OP_CALL_REG, X86_OP_MOV_IMM, X86_OP_MOV_REG,
	X86_OP_MOVBE_LOAD, X86_OP_MOVBE_STORE, X86_OP_LOAD_XMM0, X86_OP_STORE_XMM0,
	X86_OP_LEA, X86_OP_ALU_MEM, X86_OP_ALU_MEM_UNARY, X86_OP_ALU_MEM_IMM,
	X86_OP_ALU_MEM_REG, X86_OP_CMP_REG_MEM, X86_OP_CMOV, X86_OP_CMOV_MEM,
	X86_OP_SETCC, X86_OP_SETCC_MEM, X86_OP_BSWAP, X86_OP_POPCNT,
	X86_OP_SHIFTX, X86_OP_SHIFTX_MEM, X86_OP_RORX, X86_OP_RORX_MEM,
	X86_OP_BZHI, X86_OP_BZHI_MEM, X86_OP_BT, X86_OP_BT_IMM,
	X86_OP_BT_MEM_IMM, X86_OP_IMUL_IMM, X86_OP_IMUL_MEM_IMM, X86_OP_MULX,
	X86_OP_REP_MOVS, X86_OP_ANDN, X86_OP_ANDN_MEM, X86_OP_XCHG,
	X86_OP_DIV, X86_OP_PUSH, X86_OP_POP,
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
		for (s = 0; s < 43U; s++)
			check_case(op, s);

	/* Every singleton member named explicitly, so a member whose number
	 * sits outside the swept range is still covered. */
	for (s = 0; s < 43U; s++)
		check_case(singleton_member[s], s);

	/* Each singleton's opcode is distinct from every other singleton's, so
	 * no opcode is gated by two singleton arms. */
	for (s = 0; s < 43U; s++) {
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
		printf("x86 dispatch singleton host cross-check: FAILED "
		       "(%u mismatches)\n", fails);
		return 1;
	}
	printf("x86 dispatch singleton host cross-check: OK (%u cases)\n",
	       cases);
	return 0;
}
