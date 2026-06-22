#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retkprobe_v61_filter_file_type_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_b:
	/* 0xb: cmp    DWORD PTR [rsi],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_11:
	/* 0x11: ja     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11, 0x8b, x86_l_8b);
x86_l_13:
	/* 0x13: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_16:
	/* 0x16: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b:
	/* 0x1b: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d:
	/* 0x1d: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21:
	/* 0x21: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25:
	/* 0x25: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2a:
	/* 0x2a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f:
	/* 0x2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31:
	/* 0x31: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34:
	/* 0x34: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_36:
	/* 0x36: je     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36, 0x8b, x86_l_8b);
x86_l_38:
	/* 0x38: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3d:
	/* 0x3d: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_43:
	/* 0x43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_48:
	/* 0x48: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_4a:
	/* 0x4a: je     8d <filter_file_type+0x8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a, 0x8d, x86_l_8d);
x86_l_4c:
	/* 0x4c: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f:
	/* 0x4f: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_52:
	/* 0x52: jbe    8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x52, 0x8b, x86_l_8b);
x86_l_54:
	/* 0x54: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_57:
	/* 0x57: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_59:
	/* 0x59: je     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59, 0x8b, x86_l_8b);
x86_l_5b:
	/* 0x5b: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_5d:
	/* 0x5d: je     8d <filter_file_type+0x8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d, 0x8d, x86_l_8d);
x86_l_5f:
	/* 0x5f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_62:
	/* 0x62: jb     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x62, 0x8b, x86_l_8b);
x86_l_64:
	/* 0x64: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67:
	/* 0x67: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_69:
	/* 0x69: je     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x8b, x86_l_8b);
x86_l_6b:
	/* 0x6b: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_6d:
	/* 0x6d: je     8d <filter_file_type+0x8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d, 0x8d, x86_l_8d);
x86_l_6f:
	/* 0x6f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_72:
	/* 0x72: jb     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x72, 0x8b, x86_l_8b);
x86_l_74:
	/* 0x74: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_77:
	/* 0x77: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_79:
	/* 0x79: je     8b <filter_file_type+0x8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79, 0x8b, x86_l_8b);
x86_l_7b:
	/* 0x7b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d:
	/* 0x7d: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7f:
	/* 0x7f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_82:
	/* 0x82: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_86:
	/* 0x86: jmp    96 <filter_file_type+0x96> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_8b:
	/* 0x8b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d:
	/* 0x8d: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_91:
	/* 0x91: jmp    96 <filter_file_type+0x96> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_96:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
