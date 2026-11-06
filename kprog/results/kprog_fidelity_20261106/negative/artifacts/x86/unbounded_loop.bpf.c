#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"

SEC("xdp")
int unbounded_loop_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: jmp    0 <entry> */
	X86_SIM_X86_JMP(0x0, 0x0, x86_l_0);
}

X86_SIM_LICENSE();
