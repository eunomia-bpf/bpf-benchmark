#include "arm64_sim_local_bpf.h"

SEC("xdp")
int arm64_sim_hardcoded_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
	/* AArch64: mov w0, #2 */
	ARM64_SIM_RUN_OP(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_XZR,
			 ARM64_WIDTH_32, 0, 2ULL);
	/* AArch64: ret */
	ARM64_SIM_RET();
}

ARM64_SIM_LICENSE();
