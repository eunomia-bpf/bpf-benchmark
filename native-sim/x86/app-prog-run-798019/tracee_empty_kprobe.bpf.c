#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_empty_kprobe_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2:
	/* 0x2: jmp    7 <empty_kprobe+0x7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
