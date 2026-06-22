extern char CONFIG_ITER_NUM;
extern char execve_map;
extern char execve_map_update_data;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_map_update_v61_execve_map_update_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2:
	/* 0x2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_6:
	/* 0x6: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_e:
	/* 0xe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_update_data)));
x86_l_15:
	/* 0x15: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
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
	/* 0x24: je     90 <execve_map_update+0x90> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24, 0x90, x86_l_90);
x86_l_26:
	/* 0x26: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_29:
	/* 0x29: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_30:
	/* 0x30: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33:
	/* 0x33: je     a2 <execve_map_update+0xa2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33, 0xa2, x86_l_a2);
x86_l_35:
	/* 0x35: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37:
	/* 0x37: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3e:
	/* 0x3e: lea    r12,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43:
	/* 0x43: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46:
	/* 0x46: jmp    54 <execve_map_update+0x54> */
	X86_SIM_X86_JMP(0x46, 0x54, x86_l_54);
x86_l_48:
	/* 0x48: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_4b:
	/* 0x4b: cmp    r13,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32768ULL);
x86_l_52:
	/* 0x52: je     95 <execve_map_update+0x95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52, 0x95, x86_l_95);
x86_l_54:
	/* 0x54: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_58:
	/* 0x58: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5b:
	/* 0x5b: je     95 <execve_map_update+0x95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b, 0x95, x86_l_95);
x86_l_5d:
	/* 0x5d: mov    eax,DWORD PTR [r14+r13*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 8ULL);
x86_l_62:
	/* 0x62: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66:
	/* 0x66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6b:
	/* 0x6b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_71:
	/* 0x71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73:
	/* 0x73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: je     48 <execve_map_update+0x48> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x48, x86_l_48);
x86_l_78:
	/* 0x78: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7c:
	/* 0x7c: mov    edx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967294ULL);
x86_l_81:
	/* 0x81: rol    edx,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ROL);
x86_l_83:
	/* 0x83: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_86:
	/* 0x86: and QWORD PTR [rax+0x370],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 880ULL);
x86_l_8e:
	/* 0x8e: jmp    48 <execve_map_update+0x48> */
	X86_SIM_X86_JMP(0x8e, 0x48, x86_l_48);
x86_l_90:
	/* 0x90: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_95:
	/* 0x95: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_97:
	/* 0x97: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9b:
	/* 0x9b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: jmp    fd <execve_map_update+0xfd> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_a2:
	/* 0xa2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a4:
	/* 0xa4: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ab:
	/* 0xab: lea    r12,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b0:
	/* 0xb0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3:
	/* 0xb3: jmp    c1 <execve_map_update+0xc1> */
	X86_SIM_X86_JMP(0xb3, 0xc1, x86_l_c1);
x86_l_b5:
	/* 0xb5: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_b8:
	/* 0xb8: cmp    r13,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1024ULL);
x86_l_bf:
	/* 0xbf: je     95 <execve_map_update+0x95> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf, 0x95, x86_l_95);
x86_l_c1:
	/* 0xc1: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c5:
	/* 0xc5: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_c8:
	/* 0xc8: je     95 <execve_map_update+0x95> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8, 0x95, x86_l_95);
x86_l_ca:
	/* 0xca: mov    eax,DWORD PTR [r14+r13*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 8ULL);
x86_l_cf:
	/* 0xcf: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d3:
	/* 0xd3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d8:
	/* 0xd8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_de:
	/* 0xde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0:
	/* 0xe0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3:
	/* 0xe3: je     b5 <execve_map_update+0xb5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe3, 0xb5, x86_l_b5);
x86_l_e5:
	/* 0xe5: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e9:
	/* 0xe9: mov    edx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967294ULL);
x86_l_ee:
	/* 0xee: rol    edx,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ROL);
x86_l_f0:
	/* 0xf0: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_f3:
	/* 0xf3: and QWORD PTR [rax+0x370],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 880ULL);
x86_l_fb:
	/* 0xfb: jmp    b5 <execve_map_update+0xb5> */
	X86_SIM_X86_JMP(0xfb, 0xb5, x86_l_b5);
x86_l_fd:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
