extern char stats;
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_vfsstat_fentry_vfs_open_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&stats)));
x86_l_7:
	/* 0x7: inc QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 24ULL);
x86_l_c:
	/* 0xc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e:
	/* 0xe: jmp    13 <fentry_vfs_open+0x13> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_13:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
