#include "x86_sim_local_bpf.h"

SEC("xdp")
int x86_sim_hardcoded_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
	/* 0x0: mov rax, 12345678 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0, 12345678ULL);
	/* 0x5: ret */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
