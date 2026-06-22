#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_v61_extract_arg_depth_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5:
	/* 0x5: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_8:
	/* 0x8: ja     82 <extract_arg_depth+0x82> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8, 0x82, x86_l_82);
x86_l_a:
	/* 0xa: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_c:
	/* 0xc: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_d:
	/* 0xd: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_e:
	/* 0xe: mov    r8,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11:
	/* 0x11: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_14:
	/* 0x14: cmp    WORD PTR [r8+r9*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 25769803776ULL);
x86_l_1b:
	/* 0x1b: je     7b <extract_arg_depth+0x7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b, 0x7b, x86_l_7b);
x86_l_1d:
	/* 0x1d: mov    rcx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21:
	/* 0x21: mov    edx,DWORD PTR [r8+r9*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 0ULL);
x86_l_25:
	/* 0x25: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28:
	/* 0x28: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b:
	/* 0x2b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d:
	/* 0x2d: cmp    WORD PTR [r8+r9*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 17179869184ULL);
x86_l_34:
	/* 0x34: je     7b <extract_arg_depth+0x7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34, 0x7b, x86_l_7b);
x86_l_36:
	/* 0x36: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_38:
	/* 0x38: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c:
	/* 0x3c: je     4a <extract_arg_depth+0x4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c, 0x4a, x86_l_4a);
x86_l_3e:
	/* 0x3e: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_43:
	/* 0x43: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48:
	/* 0x48: jmp    54 <extract_arg_depth+0x54> */
	X86_SIM_X86_JMP(0x48, 0x54, x86_l_54);
x86_l_4a:
	/* 0x4a: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_4f:
	/* 0x4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54:
	/* 0x54: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_57:
	/* 0x57: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b:
	/* 0x5b: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e:
	/* 0x5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63:
	/* 0x63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65:
	/* 0x65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_67:
	/* 0x67: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_6c:
	/* 0x6c: jns    7b <extract_arg_depth+0x7b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x6c, 0x7b, x86_l_7b);
x86_l_6e:
	/* 0x6e: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_70:
	/* 0x70: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_74:
	/* 0x74: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76:
	/* 0x76: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b:
	/* 0x7b: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7f:
	/* 0x7f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_80:
	/* 0x80: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_82:
	/* 0x82: jmp    87 <extract_arg_depth+0x87> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_87:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
