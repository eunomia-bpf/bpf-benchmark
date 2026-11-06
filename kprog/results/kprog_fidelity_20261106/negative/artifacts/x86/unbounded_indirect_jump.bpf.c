#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"

SEC("xdp")
int unbounded_indirect_jump_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rax,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: jmp    rax */
	X86_SIM_X86_JMP(0x3, 0x0, x86_l_0);
}

X86_SIM_LICENSE();
