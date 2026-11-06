#include "/workspaces/repository/kprog/arm64/arm64_sim_local_bpf.h"

SEC("xdp")
int past_data_end_read_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: ldr x1, [x0, #8] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X1, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 8ULL);
arm64_l_4:
	/* 0x4: ldrb w0, [x1] */
	ARM64_SIM_RUN_OP3(ARM64_OP_LOAD, ARM64_X0, ARM64_X1, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_8, ARM64_AUX_MEM(ARM64_REG_NONE, ARM64_MOD_NONE, 0, 0), 0ULL);
arm64_l_8:
	/* 0x8: ret */
	ARM64_SIM_A64_RET();
	return 0;
}

ARM64_SIM_LICENSE();
