extern char args_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_trace_ret_do_splice_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x8: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a:
	/* 0xa: movabs rcx,0x2f300000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 3242700308480ULL);
x86_l_14:
	/* 0x14: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_17:
	/* 0x17: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b:
	/* 0x1b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_20:
	/* 0x20: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_27:
	/* 0x27: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2a:
	/* 0x2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c:
	/* 0x2c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e:
	/* 0x2e: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: jmp    34 <trace_ret_do_splice+0x34> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_34:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
