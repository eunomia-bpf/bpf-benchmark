#include "../x86_sim_local_bpf.h"

SEC("xdp")
int packet_checksum_fold_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <packet_checksum_fold_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    d5 <packet_checksum_fold_xdp+0xd5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <packet_checksum_fold_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x410] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <packet_checksum_fold_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    11 <packet_checksum_fold_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdx+0xc],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_38:
	/* 0x38: jne    11 <packet_checksum_fold_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38, 0x11, x86_l_11);
x86_l_3a:
	/* 0x3a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c:
	/* 0x3c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e:
	/* 0x3e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40:
	/* 0x40: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43:
	/* 0x43: movzx  r9d,WORD PTR [rdx+rdi*2+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 1, X86_WIDTH_16), 16ULL);
x86_l_49:
	/* 0x49: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4c:
	/* 0x4c: movzx  r8d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_50:
	/* 0x50: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_54:
	/* 0x54: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_57:
	/* 0x57: movzx  r8d,WORD PTR [rdx+rdi*2+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 1, X86_WIDTH_16), 18ULL);
x86_l_5d:
	/* 0x5d: add    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_60:
	/* 0x60: movzx  r9d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_64:
	/* 0x64: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_68:
	/* 0x68: add    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6b:
	/* 0x6b: movzx  r9d,WORD PTR [rdx+rdi*2+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 1, X86_WIDTH_16), 20ULL);
x86_l_71:
	/* 0x71: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_74:
	/* 0x74: movzx  r8d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_78:
	/* 0x78: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_7c:
	/* 0x7c: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7f:
	/* 0x7f: movzx  r8d,WORD PTR [rdx+rdi*2+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 1, X86_WIDTH_16), 22ULL);
x86_l_85:
	/* 0x85: add    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_88:
	/* 0x88: movzx  r9d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_8c:
	/* 0x8c: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_90:
	/* 0x90: add    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_93:
	/* 0x93: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_97:
	/* 0x97: cmp    rdi,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 512ULL);
x86_l_9e:
	/* 0x9e: jne    43 <packet_checksum_fold_xdp+0x43> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e, 0x43, x86_l_43);
x86_l_a0:
	/* 0xa0: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_a3:
	/* 0xa3: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a6:
	/* 0xa6: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a9:
	/* 0xa9: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ab:
	/* 0xab: movzx  edi,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ae:
	/* 0xae: mov    r8d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_b1:
	/* 0xb1: shl    r8d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_b5:
	/* 0xb5: shlx   rdi,rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDI, X86_RDI, X86_WIDTH_64, X86_R8, X86_ALU_SHL);
x86_l_ba:
	/* 0xba: xor    rsi,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_bd:
	/* 0xbd: inc    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_bf:
	/* 0xbf: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_c2:
	/* 0xc2: jne    3e <packet_checksum_fold_xdp+0x3e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc2, 0x3e, x86_l_3e);
x86_l_c8:
	/* 0xc8: mov    QWORD PTR [rcx],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb:
	/* 0xcb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d0:
	/* 0xd0: jmp    d5 <packet_checksum_fold_xdp+0xd5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_d5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
