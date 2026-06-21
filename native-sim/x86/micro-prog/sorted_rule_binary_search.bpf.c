#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int sorted_rule_binary_search_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rcx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rsi,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c:
	/* 0xc: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: jbe    16 <sorted_rule_binary_search_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    b7 <sorted_rule_binary_search_xdp+0xb7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <sorted_rule_binary_search_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x190] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <sorted_rule_binary_search_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    11 <sorted_rule_binary_search_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdx+0xc],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607568ULL);
x86_l_35:
	/* 0x35: jne    11 <sorted_rule_binary_search_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_38:
	/* 0x38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a:
	/* 0x3a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c:
	/* 0x3c: mov    rdi,QWORD PTR [rdx+rax*8+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 272ULL);
x86_l_44:
	/* 0x44: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47:
	/* 0x47: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a:
	/* 0x4a: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d:
	/* 0x4d: cmp    QWORD PTR [rdx+r9*8+0x10],rdi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 3), 16ULL);
x86_l_52:
	/* 0x52: sete   r11b */
	X86_SIM_L_EXEC_SETCC(X86_R11, X86_CC_E);
x86_l_56:
	/* 0x56: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_59:
	/* 0x59: cmove  rbx,r9 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_5d:
	/* 0x5d: or     r11b,r10b */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_8, X86_ALU_OR);
x86_l_60:
	/* 0x60: test   r10b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 1ULL);
x86_l_64:
	/* 0x64: cmovne rbx,r8 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R8, X86_WIDTH_64, X86_CC_NE);
x86_l_68:
	/* 0x68: lea    r8,[r9+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6c:
	/* 0x6c: cmp    QWORD PTR [rdx+r9*8+0x18],rdi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 3), 24ULL);
x86_l_71:
	/* 0x71: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_75:
	/* 0x75: cmovne r8,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_79:
	/* 0x79: or     r10b,r11b */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_8, X86_ALU_OR);
x86_l_7c:
	/* 0x7c: test   r11b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R11, X86_WIDTH_8, 1ULL);
x86_l_80:
	/* 0x80: cmovne r8,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_84:
	/* 0x84: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_88:
	/* 0x88: cmp    r9,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 32ULL);
x86_l_8c:
	/* 0x8c: jne    4d <sorted_rule_binary_search_xdp+0x4d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8c, 0x4d, x86_l_4d);
x86_l_8e:
	/* 0x8e: add    r8,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_91:
	/* 0x91: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_95:
	/* 0x95: xor    rsi,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_98:
	/* 0x98: test   r10b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 1ULL);
x86_l_9c:
	/* 0x9c: cmovne rsi,r8 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R8, X86_WIDTH_64, X86_CC_NE);
x86_l_a0:
	/* 0xa0: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_a3:
	/* 0xa3: cmp    rax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 16ULL);
x86_l_a7:
	/* 0xa7: jne    3c <sorted_rule_binary_search_xdp+0x3c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa7, 0x3c, x86_l_3c);
x86_l_a9:
	/* 0xa9: mov    QWORD PTR [rcx],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac:
	/* 0xac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b1:
	/* 0xb1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_b2:
	/* 0xb2: jmp    b7 <sorted_rule_binary_search_xdp+0xb7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
