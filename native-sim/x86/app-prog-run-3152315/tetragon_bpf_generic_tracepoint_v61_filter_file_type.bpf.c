#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_tracepoint_v61_filter_file_type_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_b:
	/* 0xb: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d:
	/* 0xd: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_13:
	/* 0x13: ja     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13, 0x9e, x86_l_9e);
x86_l_19:
	/* 0x19: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1c:
	/* 0x1c: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20:
	/* 0x20: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24:
	/* 0x24: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_29:
	/* 0x29: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33:
	/* 0x33: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35:
	/* 0x35: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_39:
	/* 0x39: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d:
	/* 0x3d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_42:
	/* 0x42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44:
	/* 0x44: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47:
	/* 0x47: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_49:
	/* 0x49: je     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49, 0x9e, x86_l_9e);
x86_l_4b:
	/* 0x4b: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_50:
	/* 0x50: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_56:
	/* 0x56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b:
	/* 0x5b: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_5d:
	/* 0x5d: je     a0 <filter_file_type+0xa0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d, 0xa0, x86_l_a0);
x86_l_5f:
	/* 0x5f: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62:
	/* 0x62: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_65:
	/* 0x65: jbe    9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x65, 0x9e, x86_l_9e);
x86_l_67:
	/* 0x67: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6a:
	/* 0x6a: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_6c:
	/* 0x6c: je     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c, 0x9e, x86_l_9e);
x86_l_6e:
	/* 0x6e: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_70:
	/* 0x70: je     a0 <filter_file_type+0xa0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70, 0xa0, x86_l_a0);
x86_l_72:
	/* 0x72: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_75:
	/* 0x75: jb     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x75, 0x9e, x86_l_9e);
x86_l_77:
	/* 0x77: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a:
	/* 0x7a: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_7c:
	/* 0x7c: je     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c, 0x9e, x86_l_9e);
x86_l_7e:
	/* 0x7e: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_80:
	/* 0x80: je     a0 <filter_file_type+0xa0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80, 0xa0, x86_l_a0);
x86_l_82:
	/* 0x82: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_85:
	/* 0x85: jb     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x85, 0x9e, x86_l_9e);
x86_l_87:
	/* 0x87: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_8a:
	/* 0x8a: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8c:
	/* 0x8c: je     9e <filter_file_type+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c, 0x9e, x86_l_9e);
x86_l_8e:
	/* 0x8e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90:
	/* 0x90: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_92:
	/* 0x92: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_95:
	/* 0x95: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_99:
	/* 0x99: jmp    a9 <filter_file_type+0xa9> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_9e:
	/* 0x9e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0:
	/* 0xa0: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a4:
	/* 0xa4: jmp    a9 <filter_file_type+0xa9> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_a9:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
