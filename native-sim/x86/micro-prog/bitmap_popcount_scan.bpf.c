#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bitmap_popcount_scan_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
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
	/* 0xf: jbe    16 <bitmap_popcount_scan_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    71 <bitmap_popcount_scan_xdp+0x71> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <bitmap_popcount_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rsi+0x810] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2064ULL);
x86_l_26:
	/* 0x26: cmp    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <bitmap_popcount_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_31:
	/* 0x31: jne    11 <bitmap_popcount_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31, 0x11, x86_l_11);
x86_l_33:
	/* 0x33: mov    ecx,DWORD PTR [rsi+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_36:
	/* 0x36: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_38:
	/* 0x38: mov    rdi,QWORD PTR [rsi+rax*8+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 16ULL);
x86_l_3d:
	/* 0x3d: mov    r8,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_40:
	/* 0x40: xor    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_43:
	/* 0x43: popcnt r8,r8 */
	X86_SIM_RUN_OP(X86_OP_POPCNT, X86_R8, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_48:
	/* 0x48: add    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_4b:
	/* 0x4b: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_4d:
	/* 0x4d: and    cl,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_50:
	/* 0x50: shr    rdi,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_53:
	/* 0x53: mov    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_56:
	/* 0x56: xor    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_59:
	/* 0x59: inc    rax */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_5c:
	/* 0x5c: cmp    rax,0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 256ULL);
x86_l_62:
	/* 0x62: jne    38 <bitmap_popcount_scan_xdp+0x38> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x62, 0x38, x86_l_38);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rdx],rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67:
	/* 0x67: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_6c:
	/* 0x6c: jmp    71 <bitmap_popcount_scan_xdp+0x71> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_71:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
