#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_bpf.h"

SEC("xdp")
int bitmap_popcount_scan_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    0x16 */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    0x76 ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     0x11 */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rsi+0x810] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2064ULL);
x86_l_26:
	/* 0x26: cmp    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     0x11 */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_31:
	/* 0x31: jne    0x11 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31, 0x11, x86_l_11);
x86_l_33:
	/* 0x33: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_34:
	/* 0x34: mov    rbp,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_37:
	/* 0x37: mov    ecx,DWORD PTR [rsi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3a:
	/* 0x3a: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3c:
	/* 0x3c: mov    rdi,QWORD PTR [rsi+rax*8+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 16ULL);
x86_l_41:
	/* 0x41: mov    r8,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_44:
	/* 0x44: xor    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_47:
	/* 0x47: popcnt r8,r8 */
	X86_SIM_RUN_OP(X86_OP_POPCNT, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_4c:
	/* 0x4c: add    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4f:
	/* 0x4f: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_51:
	/* 0x51: and    cl,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_54:
	/* 0x54: shr    rdi,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_57:
	/* 0x57: mov    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_5a:
	/* 0x5a: xor    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_5d:
	/* 0x5d: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_60:
	/* 0x60: cmp    rax,0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 256ULL);
x86_l_66:
	/* 0x66: jne    0x3c */
	X86_SIM_X86_JCC(X86_CC_NE, 0x66, 0x3c, x86_l_3c);
x86_l_68:
	/* 0x68: mov    QWORD PTR [rdx],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b:
	/* 0x6b: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_70:
	/* 0x70: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_71:
	/* 0x71: jmp    0x76 ; native-link entry RET */
	X86_SIM_X86_RET();
	__builtin_unreachable();
}

X86_SIM_LICENSE();
