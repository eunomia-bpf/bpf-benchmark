extern char sys_32_to_64_map;
extern char sys_enter_init_tail;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_tracepoint__raw_syscalls__sys_enter_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_c:
	/* 0xc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e:
	/* 0xe: mov    ecx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15:
	/* 0x15: mov    ecx,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 113ULL);
x86_l_1a:
	/* 0x1a: lea    rdi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f:
	/* 0x1f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24:
	/* 0x24: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_27:
	/* 0x27: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_29:
	/* 0x29: test   BYTE PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_2e:
	/* 0x2e: je     4e <tracepoint__raw_syscalls__sys_enter+0x4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e, 0x4e, x86_l_4e);
x86_l_30:
	/* 0x30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35:
	/* 0x35: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_3c:
	/* 0x3c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41:
	/* 0x41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43:
	/* 0x43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: je     63 <tracepoint__raw_syscalls__sys_enter+0x63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46, 0x63, x86_l_63);
x86_l_48:
	/* 0x48: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a:
	/* 0x4a: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e:
	/* 0x4e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_53:
	/* 0x53: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57:
	/* 0x57: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&sys_enter_init_tail)));
x86_l_5e:
	/* 0x5e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_61:
	/* 0x61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63:
	/* 0x63: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65:
	/* 0x65: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_69:
	/* 0x69: jmp    6e <tracepoint__raw_syscalls__sys_enter+0x6e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_6e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
