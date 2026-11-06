/* Catch PF ignored in CMOV/SETcc/Jcc, and SETcc's old matched fold silently
 * turning valid parity codes into its unsupported sentinel. */
#define X86_SIM_USE_STATE_STRUCT
#include "../x86/x86_sim_local_bpf.h"
#include <stdio.h>

static unsigned branch(struct x86_sim_state *state, unsigned code, int backward)
{
	X86_SIM_L_BIND_COMMON_STATE(state);
	X86_SIM_X86_JCC(code, 1, backward ? 0 : 2, taken);
	return 0;
taken:
	return 1;
}

int main(void)
{
	unsigned cases = 0;
	for (unsigned bits = 0; bits < 64; bits++) {
		struct x86_sim_state state = {0};
		X86_SIM_L_BIND_COMMON_STATE(&state);
		state.cf = bits & 1;
		state.zf = (bits >> 1) & 1;
		state.sf = (bits >> 2) & 1;
		state.of = (bits >> 3) & 1;
		state.pf = (bits >> 4) & 1;
		state.af = (bits >> 5) & 1;
		/* The eight base predicates and their adjacent complements follow
		 * the native condition encoding, independently of generated tables. */
		unsigned predicates[] = {state.of, state.cf, state.zf, state.cf || state.zf,
			state.sf, state.pf, state.sf != state.of, state.zf || (state.sf != state.of)};
		for (unsigned code = 0; code < 16; code++) {
			unsigned expected = predicates[code / 2] ^ (code & 1);
			if (X86_SIM_L_EVAL_CC(code) != expected || branch(&state,code,0) != expected ||
			    branch(&state,code,1) != expected) return 1;
			state.rax.ptr = (void *)0xaabbccdd12345678UL;
			state.rbx.ptr = (void *)0x1122334487654321UL;
			X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, code);
			if ((__u64)(unsigned long)state.rax.ptr != (expected ? 0x87654321U : 0x12345678U)) return 1;
			for (unsigned shift = 0; shift <= 8; shift += 8) {
				state.rax.ptr = (void *)0xaabbccdd12345678UL;
				X86_SIM_L_EXEC_SETCC(X86_RAX, KPROG_X86_REG_LANE_AUX(code,shift,0));
				__u64 want = (0xaabbccdd12345678ULL & ~(255ULL << shift)) | ((__u64)expected << shift);
				if ((__u64)(unsigned long)state.rax.ptr != want) return 1;
			}
			if (state.cf != (bits & 1) || state.zf != ((bits >> 1) & 1) ||
			    state.sf != ((bits >> 2) & 1) || state.of != ((bits >> 3) & 1) ||
			    state.pf != ((bits >> 4) & 1) || state.af != ((bits >> 5) & 1)) return 1;
			cases++;
		}
		const unsigned invalid[] = {16, 17, 255, 256, 65535, 0x100000a, 0x100000b};
		for (unsigned i = 0; i < sizeof(invalid) / sizeof(invalid[0]); i++)
			if (X86_SIM_L_EVAL_CC(invalid[i]) || branch(&state,invalid[i],0) ||
			    branch(&state,invalid[i],1)) return 1;
	}
	printf("x86 full conditions: OK (%u six-flag states/codes, CMOV/SETcc/forward/backward Jcc)\n", cases);
	return 0;
}
