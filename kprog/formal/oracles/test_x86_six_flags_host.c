/* Catch missing PF/AF writes, carry sampled after mutation, byte-lane mixups,
 * and CMP accidentally writing data in the production register/imm handlers. */
#define X86_SIM_USE_STATE_STRUCT
#include "../x86/x86_sim_local_bpf.h"
#include <stdio.h>
#include <stdlib.h>

enum operation { ADD, ADC, SUB, SBB, CMP, AND, OR, XOR, TEST, INC, DEC, NEG, NOT };
static unsigned long cases;

static unsigned parity(__u64 value)
{
	unsigned odd = 0;
	for (unsigned bit = 0; bit < 8; bit++)
		odd ^= (value >> bit) & 1;
	return !odd;
}

static void check(enum operation op, unsigned width, unsigned shift,
		  int immediate, __u64 left, __u64 right, unsigned carry)
{
	struct x86_sim_state state = {0};
	X86_SIM_L_BIND_COMMON_STATE(&state);
	state.rax.ptr = (void *)(unsigned long)left;
	state.rbx.ptr = (void *)(unsigned long)right;
	state.cf = carry;
	state.pf = state.af = 1;
	unsigned aux = KPROG_X86_REG_LANE_AUX(0, shift, shift);
	unsigned alu = op == ADD ? X86_ALU_ADD : op == ADC ? X86_ALU_ADC :
		       op == SUB ? X86_ALU_SUB : op == AND ? X86_ALU_AND :
		       op == OR ? X86_ALU_OR : op == XOR ? X86_ALU_XOR :
		       op == INC ? X86_ALU_INC : op == DEC ? X86_ALU_DEC :
		       op == NEG ? X86_ALU_NEG : op == NOT ? X86_ALU_NOT : X86_ALU_SBB;
	if (op == CMP || op == TEST) {
		if (immediate)
			X86_SIM_L_EXEC_CMP_IMM_OP_AUX(op == CMP ? X86_OP_CMP_IMM : X86_OP_TEST_IMM, X86_RAX, width, aux, right);
		else
			X86_SIM_L_EXEC_CMP_REG_OP_AUX(op == CMP ? X86_OP_CMP_REG : X86_OP_TEST_REG, X86_RAX, X86_RBX, width, aux);
	} else if (immediate) {
		X86_SIM_L_EXEC_ALU_IMM(X86_RAX, width, aux | alu, right);
	} else {
		X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, width, aux | alu);
	}
	unsigned bits = width * 8;
	__u64 mask = ~0ULL >> (64 - bits);
	__u64 a = (left >> shift) & mask;
	__u64 b = immediate ? (width == 8 ? (__u64)(__s64)(__s32)right : right) : right >> shift;
	b &= mask;
	__u64 source_a = a;
	if (op == INC || op == DEC) b = 1;
	if (op == NEG) { b = a; a = 0; }
	unsigned c = (op == ADC || op == SBB) ? carry : 0;
	int sub = op == SUB || op == SBB || op == CMP || op == DEC || op == NEG;
	int logical = op >= AND && op <= TEST;
	unsigned __int128 ub = (unsigned __int128)b + c;
	unsigned __int128 wide = sub ? (unsigned __int128)a - ub : (unsigned __int128)a + ub;
	__u64 r = (__u64)wide & mask;
	if (logical) r = op == AND || op == TEST ? a & b : op == OR ? a | b : a ^ b;
	if (op == NOT) r = ~source_a & mask;
	__int128 modulus = (__int128)1 << bits;
	__int128 sa = (a >> (bits - 1)) ? (__int128)a - modulus : a;
	__int128 sb = (b >> (bits - 1)) ? (__int128)b - modulus : b;
	__int128 signed_result = sub ? sa - sb - c : sa + sb + c;
	unsigned cf = sub ? (unsigned __int128)a < ub : wide >= (unsigned __int128)modulus;
	unsigned af = sub ? (a & 15) < (b & 15) + c : (a & 15) + (b & 15) + c >= 16;
	unsigned of = signed_result < -(modulus / 2) || signed_result >= modulus / 2;
	if (logical) { cf = of = 0; af = 1; }
	if (op == INC || op == DEC) cf = carry;
	if (op == NOT) { cf = carry; of = 0; af = 1; }
	__u64 expected = op == CMP || op == TEST ? left : width == 4 ? r :
		(left & ~(mask << shift)) | (r << shift);
	if ((__u64)(unsigned long)state.rax.ptr != expected ||
	    (__u64)(unsigned long)state.rbx.ptr != right ||
	    state.cf != cf || state.zf != (op == NOT ? 0 : (r == 0)) || state.sf != (op == NOT ? 0 : (r >> (bits - 1))) ||
	    state.of != of || state.pf != (op == NOT ? 1 : parity(r)) || state.af != af) {
		fprintf(stderr, "six flags mismatch op=%u width=%u lane=%u imm=%d a=%llx b=%llx carry=%u\n",
			op, width, shift, immediate, left, right, carry);
		exit(1);
	}
	cases++;
}

int main(void)
{
	/* Exhaustive byte arithmetic catches parity and nibble carry independently
	 * of the wider carry/overflow. High bytes have asymmetric preserved lanes. */
	for (unsigned a = 0; a < 256; a++)
		for (unsigned b = 0; b < 256; b++)
			for (unsigned c = 0; c < 2; c++)
				for (enum operation op = ADD; op <= NOT; op++) {
					check(op, 1, 0, 0, 0xa567890123450000ULL | a, 0x123456789abc0000ULL | b, c);
					check(op, 1, 8, 0, 0xa56789012300005aULL | (a << 8), 0x123456789a0000c3ULL | (b << 8), c);
					check(op, 1, 0, 1, 0xa567890123450000ULL | a, b, c);
				}
	const __u64 values[] = {0, 1, 15, 16, 127, 128, 255, 256, 0x7fff, 0x8000,
		0xffff, 0x10000, 0x7fffffff, 0x80000000, 0xffffffff, 0x100000000,
		0x7fffffffffffffff, 0x8000000000000000ULL, ~0ULL};
	for (unsigned width = 2; width <= 8; width *= 2)
		for (unsigned a = 0; a < sizeof(values) / sizeof(values[0]); a++)
			for (unsigned b = 0; b < sizeof(values) / sizeof(values[0]); b++)
				for (unsigned c = 0; c < 2; c++)
					for (enum operation op = ADD; op <= NOT; op++)
						for (int imm = 0; imm < 2; imm++)
							check(op, width, 0, imm, values[a], values[b], c);
	/* Non-arithmetic users of the new state must preserve or define PF/AF as
	 * the ISA requires: zero shifts/rotates preserve, logic defines PF only. */
	struct x86_sim_state state = {0};
	X86_SIM_L_BIND_COMMON_STATE(&state);
	for (unsigned old = 0; old < 4; old++) {
		state.pf = old & 1;
		state.af = old >> 1;
		X86_SIM_L_SET_SHIFT_FLAGS(0x80, 0, 0x80, X86_ALU_SHL, 1);
		if (state.pf != (old & 1) || state.af != (old >> 1)) return 1;
		X86_SIM_L_SET_SHIFT_FLAGS(0x80, 1, 1, X86_ALU_ROL, 1);
		if (state.pf != (old & 1) || state.af != (old >> 1)) return 1;
		X86_SIM_L_SET_LOGIC_FLAGS(3, 1);
		if (state.pf != 1 || state.af != (old >> 1)) return 1;
		X86_SIM_L_SET_POPCNT_FLAGS(3, 1);
		if (state.pf || state.af) return 1;
	}
	printf("x86 production six flags: OK (%lu arithmetic cases, preservation checks)\n", cases);
	return 0;
}
