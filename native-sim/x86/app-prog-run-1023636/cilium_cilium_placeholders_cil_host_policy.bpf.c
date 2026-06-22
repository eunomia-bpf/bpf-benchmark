#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_cilium_placeholders_cil_host_policy_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2:
	/* 0x2: jmp    7 <cil_host_policy+0x7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
