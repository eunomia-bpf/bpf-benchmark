#define ARM64_SIM_ENABLE_STACK 1
#include "/workspaces/repository/kprog/arm64/arm64_sim_local_bpf.h"

SEC("xdp")
int uninitialized_stack_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: ldur x0, [sp, #-8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X0, ARM64_SP, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 18446744073709551608ULL);
arm64_l_4:
	/* 0x4: ret */
	ARM64_SIM_A64_RET();
	return 0;
}

ARM64_SIM_LICENSE();
