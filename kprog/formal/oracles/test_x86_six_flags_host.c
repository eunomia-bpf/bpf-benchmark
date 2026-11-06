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

/* Exercise the complete routed POPCNT, including all old flag combinations
 * and destination/source aliasing. The expected count uses a bit walk. */
static void check_popcount(unsigned width, __u64 source, unsigned flags, int alias)
{
	struct x86_sim_state state = {0};
	X86_SIM_L_BIND_COMMON_STATE(&state);
	__u64 old = alias ? source : 0xa5678901234589abULL;
	state.rax.ptr = (void *)(unsigned long)old;
	state.rbx.ptr = (void *)(unsigned long)source;
	state.cf = flags & 1;
	state.pf = (flags >> 1) & 1;
	state.af = (flags >> 2) & 1;
	state.zf = (flags >> 3) & 1;
	state.sf = (flags >> 4) & 1;
	state.of = (flags >> 5) & 1;
	X86_SIM_L_EXEC(X86_OP_POPCNT, X86_RAX, alias ? X86_RAX : X86_RBX, width, 0xdeadbeefU, 0);
	__u64 narrowed = source & (~0ULL >> (64 - width * 8));
	__u64 count = 0;
	for (unsigned bit = 0; bit < width * 8; bit++) count += (narrowed >> bit) & 1;
	__u64 expected = width == 2 ? (old & ~0xffffULL) | count : count;
	if ((__u64)(unsigned long)state.rax.ptr != expected ||
	    (__u64)(unsigned long)state.rbx.ptr != source || state.rax_tag != X86_SIM_TAG_SCALAR ||
	    state.cf || state.pf || state.af || state.sf || state.of || state.zf != (narrowed == 0)) {
		fprintf(stderr, "POPCNT mismatch width=%u source=%llx flags=%u alias=%d\n", width, source, flags, alias);
		exit(1);
	}
	cases++;
}

/* Widening moves preserve every status flag and read the source before
 * aliasing writeback. Absolute-address loads must not add an offset to NULL. */
static void check_movx(unsigned source_width, unsigned target_width, int sign,
		       __u64 source, unsigned flags, int alias, unsigned memory, unsigned lane)
{
	struct x86_sim_state state = {0};
	X86_SIM_L_BIND_COMMON_STATE(&state);
	__u8 data[16];
	for (unsigned i = 0; i < sizeof(data); i++) data[i] = 0xa5;
	for (unsigned i = 0; i < source_width; i++) data[3+i] = source >> (8*i);
	state.rax.ptr = (void *)(unsigned long)(alias && !memory ? source : 0xa5678901234589abULL);
	state.rbx.ptr = (void *)(unsigned long)source;
	state.rdi.ptr = data + 3;
	state.cf = flags & 1;
	state.pf = (flags >> 1) & 1;
	state.af = (flags >> 2) & 1;
	state.zf = (flags >> 3) & 1;
	state.sf = (flags >> 4) & 1;
	state.of = (flags >> 5) & 1;
	struct x86_sim_state expected = state;
	__u64 mask = (1ULL << (8*source_width)) - 1;
	__u64 value = (source >> lane) & mask;
	if (sign && (value & (1ULL << (8*source_width-1)))) value |= ~mask;
	if (target_width == 4) value &= 0xffffffffULL;
	__u64 old = (unsigned long)(alias && memory ? state.rdi.ptr : state.rax.ptr);
	if (target_width == 2) value = (old & ~0xffffULL) | (value & 0xffffULL);
	if (alias && memory) { expected.rdi.ptr = (void *)(unsigned long)value; expected.rdi_tag = X86_SIM_TAG_SCALAR; }
	else { expected.rax.ptr = (void *)(unsigned long)value; expected.rax_tag = X86_SIM_TAG_SCALAR; }
	if (memory) {
		X86_SIM_L_EXEC_MOV_LOAD(sign ? X86_OP_MOVSX_LOAD : X86_OP_MOV_LOAD,
			alias ? X86_RDI : X86_RAX, memory == 2 ? X86_REG_NONE : X86_RDI,
			target_width, X86_MEM_AUX_FULL(X86_REG_NONE, 0, source_width),
			memory == 2 ? (__u64)(unsigned long)(data + 3) : 0);
	} else {
		X86_SIM_L_EXEC_MOVX_REG(sign ? X86_OP_MOVSX_REG : X86_OP_MOVZX_REG,
			X86_RAX, lane ? KPROG_X86_MOVX_HIGH_SOURCE(alias ? X86_RAX : X86_RBX) : (alias ? X86_RAX : X86_RBX), target_width, source_width);
	}
	int mismatch = state.cf != expected.cf || state.pf != expected.pf || state.af != expected.af ||
		state.zf != expected.zf || state.sf != expected.sf || state.of != expected.of;
#define CHECK_MOVX_GPR(_REG, NAME) mismatch |= state.NAME.ptr != expected.NAME.ptr || state.NAME##_tag != expected.NAME##_tag;
	X86_SIM_L_FOR_EACH_GPR(CHECK_MOVX_GPR)
#undef CHECK_MOVX_GPR
	if (mismatch) {
		fprintf(stderr, "MOVX mismatch source_width=%u target_width=%u sign=%d source=%llx flags=%u alias=%d memory=%u\n",
			source_width, target_width, sign, source, flags, alias, memory);
		exit(1);
	}
	for (unsigned i = 0; i < sizeof(data); i++) {
		unsigned char want = i >= 3 && i < 3+source_width ? source >> (8*(i-3)) : 0xa5;
		if (data[i] != want) exit(1);
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
	for (unsigned width = 2; width <= 8; width *= 2)
		for (unsigned flags = 0; flags < 64; flags++)
			for (int alias = 0; alias < 2; alias++) {
				for (unsigned bit = 0; bit < 64; bit++)
					check_popcount(width, 1ULL << bit, flags, alias);
				check_popcount(width, 0, flags, alias);
				check_popcount(width, ~0ULL, flags, alias);
			}
	for (unsigned target = 2; target <= 8; target *= 2)
		for (unsigned source = 1; source <= 4; source *= 2)
			for (int sign = 0; sign < 2; sign++) {
				if (source > target || (source == target && !sign)) continue;
				for (unsigned flags = 0; flags < 64; flags++)
					for (int alias = 0; alias < 2; alias++)
						for (unsigned memory = 0; memory < 3; memory++)
							for (unsigned a = 0; a < sizeof(values)/sizeof(values[0]); a++)
								check_movx(source, target, sign, values[a], flags, alias, memory, 0);
			}
	for (unsigned target = 2; target <= 4; target *= 2)
		for (int sign = 0; sign < 2; sign++)
			for (unsigned flags = 0; flags < 64; flags++)
				for (int alias = 0; alias < 2; alias++)
					for (unsigned a = 0; a < sizeof(values)/sizeof(values[0]); a++)
						check_movx(1, target, sign, values[a], flags, alias, 0, 8);
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
