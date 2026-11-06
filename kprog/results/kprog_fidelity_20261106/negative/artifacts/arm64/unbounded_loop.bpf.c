#include "/workspaces/repository/kprog/arm64/arm64_sim_local_bpf.h"

SEC("xdp")
int unbounded_loop_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: b 0 <entry> */
	ARM64_SIM_A64_JMP(0x0, 0x0, arm64_l_0);
	return 0;
}

ARM64_SIM_LICENSE();
