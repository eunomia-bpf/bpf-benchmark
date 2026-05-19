#include "x86_sim_bpf.h"

SEC("xdp")
int x86_sim_hardcoded_xdp(struct xdp_md *ctx)
{
	return X86_SIM_BEGIN_XDP(ctx)
	/* 0x0: mov rax, 12345678 */
	X86_SIM_STEP_OP(X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0, 12345678ULL)
	/* 0x5: ret */
	X86_SIM_STEP_OP(X86_OP_RET, 0, 0, 0, 0, 0)
	X86_SIM_END_XDP();
}

X86_SIM_LICENSE();
