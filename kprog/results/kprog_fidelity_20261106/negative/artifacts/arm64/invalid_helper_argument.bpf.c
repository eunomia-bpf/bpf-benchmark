#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_RETURN_CASES \
	case 0xcULL: __a64_lr = 0; goto arm64_l_c;
#include "/workspaces/repository/kprog/arm64/arm64_sim_local_bpf.h"

SEC("xdp")
int invalid_helper_argument_arm64_sim_xdp(struct xdp_md *ctx)
{
	ARM64_SIM_ENTRY_XDP(ctx);
arm64_l_0:
	/* 0x0: mov x0, #0x1 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X0, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 1ULL);
arm64_l_4:
	/* 0x4: mov x1, #0x0 */
	ARM64_SIM_RUN_OP3(ARM64_OP_MOV_IMM, ARM64_X1, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_REG_NONE, ARM64_WIDTH_64, 0, 0ULL);
arm64_l_8:
	/* 0x8: bl 0 <bpf_map_lookup_elem> */
	ARM64_SIM_BPF_CALL_bpf_map_lookup_elem();
arm64_l_c:
	/* 0xc: ret */
	ARM64_SIM_A64_RET();
	return 0;
}

ARM64_SIM_LICENSE();
