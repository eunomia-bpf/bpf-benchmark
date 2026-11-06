#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"

SEC("xdp")
int invalid_helper_argument_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rdi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1ULL);
x86_l_7:
	/* 0x7: mov    rsi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 0ULL);
x86_l_e:
	/* 0xe: call   13 <entry+0x13> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_13:
	/* 0x13: ret */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
