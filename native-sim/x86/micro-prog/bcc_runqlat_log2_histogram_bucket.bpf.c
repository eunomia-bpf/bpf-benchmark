#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_runqlat_log2_histogram_bucket_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <bcc_runqlat_log2_histogram_bucket_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    153 <bcc_runqlat_log2_histogram_bucket_xdp+0x153> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <bcc_runqlat_log2_histogram_bucket_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0x410] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <bcc_runqlat_log2_histogram_bucket_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x80 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_31:
	/* 0x31: jne    11 <bcc_runqlat_log2_histogram_bucket_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31, 0x11, x86_l_11);
x86_l_33:
	/* 0x33: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_34:
	/* 0x34: mov    esi,DWORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_37:
	/* 0x37: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39:
	/* 0x39: jmp    5f <bcc_runqlat_log2_histogram_bucket_xdp+0x5f> */
	X86_SIM_X86_JMP(0x39, 0x5f, x86_l_5f);
x86_l_3b:
	/* 0x3b: shl    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_3f:
	/* 0x3f: mov    esi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R10, X86_WIDTH_32);
x86_l_42:
	/* 0x42: and    al,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 56ULL);
x86_l_44:
	/* 0x44: shlx   rax,rsi,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RSI, X86_WIDTH_64, X86_RAX, X86_ALU_SHL);
x86_l_49:
	/* 0x49: xor    r11,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_4c:
	/* 0x4c: mov    rsi,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_52:
	/* 0x52: cmp    r8,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 128ULL);
x86_l_59:
	/* 0x59: je     145 <bcc_runqlat_log2_histogram_bucket_xdp+0x145> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59, 0x145, x86_l_145);
x86_l_5f:
	/* 0x5f: movzx  edi,WORD PTR [rdx+rax*8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_16), 16ULL);
x86_l_64:
	/* 0x64: movzx  r8d,BYTE PTR [rdx+rax*8+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_8), 18ULL);
x86_l_6a:
	/* 0x6a: shl    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_6e:
	/* 0x6e: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_71:
	/* 0x71: mov    r9d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R8, X86_WIDTH_32);
x86_l_74:
	/* 0x74: shr    r9d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_78:
	/* 0x78: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_7d:
	/* 0x7d: and    r9d,0xfffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 1048575ULL);
x86_l_84:
	/* 0x84: je     a7 <bcc_runqlat_log2_histogram_bucket_xdp+0xa7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84, 0xa7, x86_l_a7);
x86_l_86:
	/* 0x86: inc    r9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_89:
	/* 0x89: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b:
	/* 0x8b: mov    r10d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RDI, X86_WIDTH_32);
x86_l_8e:
	/* 0x8e: lea    edi,[r10+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_92:
	/* 0x92: cmp    r10d,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 61ULL);
x86_l_96:
	/* 0x96: ja     a7 <bcc_runqlat_log2_histogram_bucket_xdp+0xa7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x96, 0xa7, x86_l_a7);
x86_l_98:
	/* 0x98: mov    r10,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_64);
x86_l_9b:
	/* 0x9b: shr    r10,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHR, 1ULL);
x86_l_9e:
	/* 0x9e: cmp    r9,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 3ULL);
x86_l_a2:
	/* 0xa2: mov    r9,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R10, X86_WIDTH_64);
x86_l_a5:
	/* 0xa5: ja     8b <bcc_runqlat_log2_histogram_bucket_xdp+0x8b> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa5, 0x8b, x86_l_8b);
x86_l_a7:
	/* 0xa7: movzx  r9d,BYTE PTR [rdx+rax*8+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_8), 19ULL);
x86_l_ad:
	/* 0xad: shl    r9d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_b1:
	/* 0xb1: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_b4:
	/* 0xb4: movzx  r8d,BYTE PTR [rdx+rax*8+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_8), 20ULL);
x86_l_ba:
	/* 0xba: shl    r8,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_be:
	/* 0xbe: movzx  r10d,BYTE PTR [rdx+rax*8+0x15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_8), 21ULL);
x86_l_c4:
	/* 0xc4: shl    r10,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_c8:
	/* 0xc8: or     r10,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_cb:
	/* 0xcb: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_ce:
	/* 0xce: movzx  r8d,BYTE PTR [rdx+rax*8+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_8), 22ULL);
x86_l_d4:
	/* 0xd4: shl    r8,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_d8:
	/* 0xd8: movzx  r9d,BYTE PTR [rdx+rax*8+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 3, X86_WIDTH_8), 23ULL);
x86_l_de:
	/* 0xde: shl    r9,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_e2:
	/* 0xe2: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_e5:
	/* 0xe5: or     r9,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_e8:
	/* 0xe8: cmp    edi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 25ULL);
x86_l_eb:
	/* 0xeb: mov    r10d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 25ULL);
x86_l_f1:
	/* 0xf1: cmovb  r10d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_f5:
	/* 0xf5: lea    r11d,[r10+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_f9:
	/* 0xf9: lea    r8,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_fd:
	/* 0xfd: imul   r11,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R8, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_101:
	/* 0x101: add    rsi,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R11, X86_WIDTH_64, X86_ALU_ADD);
x86_l_104:
	/* 0x104: mov    r11d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R10, X86_WIDTH_32);
x86_l_107:
	/* 0x107: and    r11b,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_10b:
	/* 0x10b: lea    ebx,[r11+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_10f:
	/* 0x10f: shlx   rbx,r9,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RBX, X86_R9, X86_WIDTH_64, X86_RBX, X86_ALU_SHL);
x86_l_114:
	/* 0x114: not    r11b */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_117:
	/* 0x117: shrx   r11,r9,r11 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R11, X86_R9, X86_WIDTH_64, X86_R11, X86_ALU_SHR);
x86_l_11c:
	/* 0x11c: or     r11,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11f:
	/* 0x11f: xor    r11,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RSI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_122:
	/* 0x122: cmp    edi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 25ULL);
x86_l_125:
	/* 0x125: jb     3b <bcc_runqlat_log2_histogram_bucket_xdp+0x3b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x125, 0x3b, x86_l_3b);
x86_l_12b:
	/* 0x12b: shr    r9,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_12f:
	/* 0x12f: add    r11,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_132:
	/* 0x132: mov    rsi,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_135:
	/* 0x135: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_138:
	/* 0x138: cmp    r8,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 128ULL);
x86_l_13f:
	/* 0x13f: jne    5f <bcc_runqlat_log2_histogram_bucket_xdp+0x5f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13f, 0x5f, x86_l_5f);
x86_l_145:
	/* 0x145: mov    QWORD PTR [rcx],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_148:
	/* 0x148: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14d:
	/* 0x14d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: jmp    153 <bcc_runqlat_log2_histogram_bucket_xdp+0x153> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_153:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
