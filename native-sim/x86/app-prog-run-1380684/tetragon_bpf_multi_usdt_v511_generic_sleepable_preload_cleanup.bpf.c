extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_cleanup_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1:
	/* 0x1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6:
	/* 0x6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8:
	/* 0x8: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c:
	/* 0xc: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_11:
	/* 0x11: mov    rdi,QWORD PTR [rip+0x6150] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_18:
	/* 0x18: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1b:
	/* 0x1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d:
	/* 0x1d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f:
	/* 0x1f: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_20:
	/* 0x20: jmp    25 <generic_sleepable_preload_cleanup+0x25> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_25:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
