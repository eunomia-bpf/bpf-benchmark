#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bitmap_popcount_scan_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
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
	/* 0xf: jbe    16 <bitmap_popcount_scan_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    91 <bitmap_popcount_scan_xdp+0x91> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <bitmap_popcount_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0x810] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2064ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
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
	/* 0x33: mov    esi,DWORD PTR [rdx+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_36:
	/* 0x36: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_38:
	/* 0x38: mov    rdi,QWORD PTR [rdx+rax*8+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 16ULL);
x86_l_3d:
	/* 0x3d: mov    r8,QWORD PTR [rdx+rax*8+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24ULL);
x86_l_42:
	/* 0x42: mov    r9d,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_45:
	/* 0x45: and    r9b,0x6 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 6ULL);
x86_l_49:
	/* 0x49: shrx   r9,rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R9, X86_RDI, X86_WIDTH_64, X86_R9, X86_ALU_SHR);
x86_l_4e:
	/* 0x4e: xor    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_51:
	/* 0x51: popcnt rdi,rdi */
	X86_SIM_RUN_OP(X86_OP_POPCNT, X86_RDI, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_56:
	/* 0x56: add    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_59:
	/* 0x59: xor    r9,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_5c:
	/* 0x5c: lea    esi,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5f:
	/* 0x5f: and    sil,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_63:
	/* 0x63: shrx   rsi,r8,rsi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_R8, X86_WIDTH_64, X86_RSI, X86_ALU_SHR);
x86_l_68:
	/* 0x68: xor    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_6b:
	/* 0x6b: xor    edi,edi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6d:
	/* 0x6d: popcnt rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_POPCNT, X86_RDI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_72:
	/* 0x72: add    rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_75:
	/* 0x75: xor    rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_78:
	/* 0x78: add    rax,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_7c:
	/* 0x7c: cmp    rax,0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 256ULL);
x86_l_82:
	/* 0x82: jne    38 <bitmap_popcount_scan_xdp+0x38> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x82, 0x38, x86_l_38);
x86_l_84:
	/* 0x84: mov    QWORD PTR [rcx],rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87:
	/* 0x87: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_8c:
	/* 0x8c: jmp    91 <bitmap_popcount_scan_xdp+0x91> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_91:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
