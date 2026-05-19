#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_bpf.h"

SEC("xdp")
int sorted_rule_binary_search_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rcx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rsi,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    0x16 */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    0xa2 ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     0x11 */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x190] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     0x11 */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    0x11 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdx+0xc],0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607568ULL);
x86_l_35:
	/* 0x35: jne    0x11 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_38:
	/* 0x38: mov    rbp,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_3b:
	/* 0x3b: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3c:
	/* 0x3c: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3e:
	/* 0x3e: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_40:
	/* 0x40: mov    rdi,QWORD PTR [rdx+rax*8+0x110] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 272ULL);
x86_l_48:
	/* 0x48: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4b:
	/* 0x4b: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4e:
	/* 0x4e: xor    r10d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_51:
	/* 0x51: mov    r11d,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_54:
	/* 0x54: mov    rbx,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_57:
	/* 0x57: cmp    QWORD PTR [rdx+r9*8+0x10],rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 3), 16ULL);
x86_l_5c:
	/* 0x5c: sete   r10b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R10, X86_REG_NONE, X86_WIDTH_8, X86_CC_E, 0);
x86_l_60:
	/* 0x60: cmove  r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R8, X86_R9, X86_WIDTH_64, X86_CC_E, 0);
x86_l_64:
	/* 0x64: or     r10b,r11b */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R11, X86_WIDTH_8, X86_ALU_OR, 0);
x86_l_67:
	/* 0x67: test   r11b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_6b:
	/* 0x6b: cmovne r8,rbx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R8, X86_RBX, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_6f:
	/* 0x6f: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_72:
	/* 0x72: cmp    r9,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_76:
	/* 0x76: jne    0x51 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x76, 0x51, x86_l_51);
x86_l_78:
	/* 0x78: add    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_7b:
	/* 0x7b: add    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7f:
	/* 0x7f: xor    rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_82:
	/* 0x82: test   r10b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_86:
	/* 0x86: cmovne rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RSI, X86_R8, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_8a:
	/* 0x8a: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_8d:
	/* 0x8d: cmp    rax,0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 16ULL);
x86_l_91:
	/* 0x91: jne    0x40 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x91, 0x40, x86_l_40);
x86_l_93:
	/* 0x93: mov    QWORD PTR [rcx],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96:
	/* 0x96: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_9b:
	/* 0x9b: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_9c:
	/* 0x9c: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_9d:
	/* 0x9d: jmp    0xa2 ; native-link entry RET */
	X86_SIM_X86_RET();
	__builtin_unreachable();
}

X86_SIM_LICENSE();
