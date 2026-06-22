extern char execve_map;
extern char execve_map_update_data;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_map_update_v53_execve_map_update_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2:
	/* 0x2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_6:
	/* 0x6: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e:
	/* 0xe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_update_data)));
x86_l_15:
	/* 0x15: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f:
	/* 0x1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21:
	/* 0x21: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24:
	/* 0x24: je     83 <execve_map_update+0x83> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24, 0x83, x86_l_83);
x86_l_26:
	/* 0x26: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_29:
	/* 0x29: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b:
	/* 0x2b: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_32:
	/* 0x32: lea    r12,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_37:
	/* 0x37: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a:
	/* 0x3a: jmp    48 <execve_map_update+0x48> */
	X86_SIM_X86_JMP(0x3a, 0x48, x86_l_48);
x86_l_3c:
	/* 0x3c: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3f:
	/* 0x3f: cmp    r13,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1024ULL);
x86_l_46:
	/* 0x46: je     88 <execve_map_update+0x88> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46, 0x88, x86_l_88);
x86_l_48:
	/* 0x48: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c:
	/* 0x4c: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: je     88 <execve_map_update+0x88> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f, 0x88, x86_l_88);
x86_l_51:
	/* 0x51: mov    eax,DWORD PTR [r14+r13*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 8ULL);
x86_l_56:
	/* 0x56: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5a:
	/* 0x5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f:
	/* 0x5f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_62:
	/* 0x62: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_65:
	/* 0x65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67:
	/* 0x67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: je     3c <execve_map_update+0x3c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0x3c, x86_l_3c);
x86_l_6c:
	/* 0x6c: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_70:
	/* 0x70: mov    edx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967294ULL);
x86_l_75:
	/* 0x75: rol    edx,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ROL);
x86_l_77:
	/* 0x77: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_7a:
	/* 0x7a: and    QWORD PTR [rax+0x370],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 880ULL);
x86_l_81:
	/* 0x81: jmp    3c <execve_map_update+0x3c> */
	X86_SIM_X86_JMP(0x81, 0x3c, x86_l_3c);
x86_l_83:
	/* 0x83: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_88:
	/* 0x88: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_8a:
	/* 0x8a: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8e:
	/* 0x8e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_90:
	/* 0x90: jmp    95 <execve_map_update+0x95> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_95:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
