extern char sys_32_to_64_map;
extern char sys_exit_init_tail;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_tracepoint__raw_syscalls__sys_exit_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    rax,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a:
	/* 0xa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d:
	/* 0xd: je     14 <tracepoint__raw_syscalls__sys_exit+0x14> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd, 0x14, x86_l_14);
x86_l_f:
	/* 0xf: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_12:
	/* 0x12: jmp    14 <tracepoint__raw_syscalls__sys_exit+0x14> */
	X86_SIM_X86_JMP(0x12, 0x14, x86_l_14);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18:
	/* 0x18: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1d:
	/* 0x1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f:
	/* 0x1f: mov    ecx,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 113ULL);
x86_l_24:
	/* 0x24: lea    rdi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29:
	/* 0x29: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e:
	/* 0x2e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_33:
	/* 0x33: test   BYTE PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_38:
	/* 0x38: je     58 <tracepoint__raw_syscalls__sys_exit+0x58> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0x58, x86_l_58);
x86_l_3a:
	/* 0x3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f:
	/* 0x3f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_46:
	/* 0x46: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: je     6d <tracepoint__raw_syscalls__sys_exit+0x6d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x50, 0x6d, x86_l_6d);
x86_l_52:
	/* 0x52: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54:
	/* 0x54: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58:
	/* 0x58: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5d:
	/* 0x5d: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61:
	/* 0x61: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&sys_exit_init_tail)));
x86_l_68:
	/* 0x68: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d:
	/* 0x6d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f:
	/* 0x6f: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_73:
	/* 0x73: jmp    78 <tracepoint__raw_syscalls__sys_exit+0x78> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_78:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
