#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"

SEC("xdp")
int stack_oob_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rax,QWORD PTR [rsp-0x400] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709550592ULL);
x86_l_8:
	/* 0x8: ret */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
