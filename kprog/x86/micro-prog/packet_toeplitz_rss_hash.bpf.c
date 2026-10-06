#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int packet_toeplitz_rss_hash_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <packet_toeplitz_rss_hash_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    2f7 <packet_toeplitz_rss_hash_xdp+0x2f7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_23:
	/* 0x23: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_26:
	/* 0x26: ja     11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26, 0x11, x86_l_11);
x86_l_28:
	/* 0x28: movbe  si,WORD PTR [rdx+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RSI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_2e:
	/* 0x2e: movzx  esi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_31:
	/* 0x31: cmp    esi,0x800 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2048ULL);
x86_l_37:
	/* 0x37: jne    11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37, 0x11, x86_l_11);
x86_l_39:
	/* 0x39: movzx  esi,BYTE PTR [rdx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_3d:
	/* 0x3d: and    sil,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_41:
	/* 0x41: cmp    sil,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 5ULL);
x86_l_45:
	/* 0x45: jne    11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45, 0x11, x86_l_11);
x86_l_47:
	/* 0x47: cmp    BYTE PTR [rdx+0x1f],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986182ULL);
x86_l_4b:
	/* 0x4b: jne    11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b, 0x11, x86_l_11);
x86_l_4d:
	/* 0x4d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4e:
	/* 0x4e: lea    rsi,[rdx+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_52:
	/* 0x52: mov    rdi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_55:
	/* 0x55: add    rdi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 34ULL);
x86_l_59:
	/* 0x59: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b:
	/* 0x5b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e:
	/* 0x5e: jmp    88 <packet_toeplitz_rss_hash_xdp+0x88> */
	X86_SIM_X86_JMP(0x5e, 0x88, x86_l_88);
x86_l_60:
	/* 0x60: mov    ebx,0xc2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 194ULL);
x86_l_65:
	/* 0x65: shlx   r10d,r11d,r9d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R10, X86_R11, X86_WIDTH_32, X86_R9, X86_ALU_SHL);
x86_l_6a:
	/* 0x6a: mov    r11b,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 8ULL);
x86_l_6d:
	/* 0x6d: sub    r11b,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R9, X86_WIDTH_8, X86_ALU_SUB);
x86_l_70:
	/* 0x70: shrx   r11d,ebx,r11d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R11, X86_RBX, X86_WIDTH_32, X86_R11, X86_ALU_SHR);
x86_l_75:
	/* 0x75: or     r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_78:
	/* 0x78: xor    eax,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b:
	/* 0x7b: inc    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_7e:
	/* 0x7e: cmp    r8d,0x68 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 104ULL);
x86_l_82:
	/* 0x82: je     28c <packet_toeplitz_rss_hash_xdp+0x28c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82, 0x28c, x86_l_28c);
x86_l_88:
	/* 0x88: mov    r10d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R8, X86_WIDTH_32);
x86_l_8b:
	/* 0x8b: shr    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_8f:
	/* 0x8f: cmp    r8d,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 31ULL);
x86_l_93:
	/* 0x93: jbe    aa <packet_toeplitz_rss_hash_xdp+0xaa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x93, 0xaa, x86_l_aa);
x86_l_95:
	/* 0x95: cmp    r8d,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 63ULL);
x86_l_99:
	/* 0x99: jbe    aa <packet_toeplitz_rss_hash_xdp+0xaa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x99, 0xaa, x86_l_aa);
x86_l_9b:
	/* 0x9b: cmp    r8d,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 79ULL);
x86_l_9f:
	/* 0x9f: jbe    aa <packet_toeplitz_rss_hash_xdp+0xaa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x9f, 0xaa, x86_l_aa);
x86_l_a1:
	/* 0xa1: mov    r9,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_64);
x86_l_a4:
	/* 0xa4: cmp    r8d,0x5f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 95ULL);
x86_l_a8:
	/* 0xa8: ja     b0 <packet_toeplitz_rss_hash_xdp+0xb0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa8, 0xb0, x86_l_b0);
x86_l_aa:
	/* 0xaa: mov    r9d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R10, X86_WIDTH_32);
x86_l_ad:
	/* 0xad: add    r9,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b0:
	/* 0xb0: movzx  r11d,BYTE PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b4:
	/* 0xb4: mov    r9d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R8, X86_WIDTH_32);
x86_l_b7:
	/* 0xb7: and    r9d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_bb:
	/* 0xbb: shlx   r11d,r11d,r9d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R11, X86_R11, X86_WIDTH_32, X86_R9, X86_ALU_SHL);
x86_l_c0:
	/* 0xc0: test   r11b,r11b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_8);
x86_l_c3:
	/* 0xc3: jns    7b <packet_toeplitz_rss_hash_xdp+0x7b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc3, 0x7b, x86_l_7b);
x86_l_c5:
	/* 0xc5: cmp    r10d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 5ULL);
x86_l_c9:
	/* 0xc9: jle    f1 <packet_toeplitz_rss_hash_xdp+0xf1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xc9, 0xf1, x86_l_f1);
x86_l_cb:
	/* 0xcb: cmp    r10d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 8ULL);
x86_l_cf:
	/* 0xcf: jle    116 <packet_toeplitz_rss_hash_xdp+0x116> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xcf, 0x116, x86_l_116);
x86_l_d1:
	/* 0xd1: cmp    r10d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 10ULL);
x86_l_d5:
	/* 0xd5: jg     14b <packet_toeplitz_rss_hash_xdp+0x14b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd5, 0x14b, x86_l_14b);
x86_l_d7:
	/* 0xd7: cmp    r10d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 9ULL);
x86_l_db:
	/* 0xdb: jne    192 <packet_toeplitz_rss_hash_xdp+0x192> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdb, 0x192, x86_l_192);
x86_l_e1:
	/* 0xe1: mov    ebx,0x43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 67ULL);
x86_l_e6:
	/* 0xe6: mov    r11d,0x67253d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1730493696ULL);
x86_l_ec:
	/* 0xec: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0xec, 0x1c4, x86_l_1c4);
x86_l_f1:
	/* 0xf1: cmp    r10d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 2ULL);
x86_l_f5:
	/* 0xf5: jg     132 <packet_toeplitz_rss_hash_xdp+0x132> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf5, 0x132, x86_l_132);
x86_l_f7:
	/* 0xf7: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_fa:
	/* 0xfa: je     16b <packet_toeplitz_rss_hash_xdp+0x16b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa, 0x16b, x86_l_16b);
x86_l_fc:
	/* 0xfc: cmp    r10d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 1ULL);
x86_l_100:
	/* 0x100: jne    1ac <packet_toeplitz_rss_hash_xdp+0x1ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x100, 0x1ac, x86_l_1ac);
x86_l_106:
	/* 0x106: mov    ebx,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 37ULL);
x86_l_10b:
	/* 0x10b: mov    r11d,0x5a56da00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1515641344ULL);
x86_l_111:
	/* 0x111: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x111, 0x1c4, x86_l_1c4);
x86_l_116:
	/* 0x116: cmp    r10d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 6ULL);
x86_l_11a:
	/* 0x11a: je     15e <packet_toeplitz_rss_hash_xdp+0x15e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a, 0x15e, x86_l_15e);
x86_l_11c:
	/* 0x11c: cmp    r10d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 7ULL);
x86_l_120:
	/* 0x120: jne    185 <packet_toeplitz_rss_hash_xdp+0x185> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x120, 0x185, x86_l_185);
x86_l_122:
	/* 0x122: mov    ebx,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 37ULL);
x86_l_127:
	/* 0x127: mov    r11d,0xc2416700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 3259066112ULL);
x86_l_12d:
	/* 0x12d: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x12d, 0x1c4, x86_l_1c4);
x86_l_132:
	/* 0x132: cmp    r10d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 3ULL);
x86_l_136:
	/* 0x136: je     178 <packet_toeplitz_rss_hash_xdp+0x178> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136, 0x178, x86_l_178);
x86_l_138:
	/* 0x138: cmp    r10d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 4ULL);
x86_l_13c:
	/* 0x13c: jne    1b9 <packet_toeplitz_rss_hash_xdp+0x1b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13c, 0x1b9, x86_l_1b9);
x86_l_13e:
	/* 0x13e: mov    ebx,0xc2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 194ULL);
x86_l_143:
	/* 0x143: mov    r11d,0x255b0e00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 626724352ULL);
x86_l_149:
	/* 0x149: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x149, 0x1c4, x86_l_1c4);
x86_l_14b:
	/* 0x14b: cmp    r10d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 11ULL);
x86_l_14f:
	/* 0x14f: jne    19f <packet_toeplitz_rss_hash_xdp+0x19f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14f, 0x19f, x86_l_19f);
x86_l_151:
	/* 0x151: mov    ebx,0x8f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 143ULL);
x86_l_156:
	/* 0x156: mov    r11d,0x3d43a300 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1027842816ULL);
x86_l_15c:
	/* 0x15c: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x15c, 0x1c4, x86_l_1c4);
x86_l_15e:
	/* 0x15e: mov    ebx,0x67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 103ULL);
x86_l_163:
	/* 0x163: mov    r11d,0xec24100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 247611648ULL);
x86_l_169:
	/* 0x169: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x169, 0x1c4, x86_l_1c4);
x86_l_16b:
	/* 0x16b: mov    ebx,0xda */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 218ULL);
x86_l_170:
	/* 0x170: mov    r11d,0x6d5a5600 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1834636800ULL);
x86_l_176:
	/* 0x176: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x176, 0x1c4, x86_l_1c4);
x86_l_178:
	/* 0x178: mov    ebx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_17d:
	/* 0x17d: mov    r11d,0xda255b00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 3659881216ULL);
x86_l_183:
	/* 0x183: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x183, 0x1c4, x86_l_1c4);
x86_l_185:
	/* 0x185: mov    ebx,0x3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 61ULL);
x86_l_18a:
	/* 0x18a: mov    r11d,0x41672500 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1097278720ULL);
x86_l_190:
	/* 0x190: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x190, 0x1c4, x86_l_1c4);
x86_l_192:
	/* 0x192: mov    ebx,0xa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 163ULL);
x86_l_197:
	/* 0x197: mov    r11d,0x253d4300 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 624771840ULL);
x86_l_19d:
	/* 0x19d: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x19d, 0x1c4, x86_l_1c4);
x86_l_19f:
	/* 0x19f: mov    ebx,0xb0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 176ULL);
x86_l_1a4:
	/* 0x1a4: mov    r11d,0x43a38f00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1134792448ULL);
x86_l_1aa:
	/* 0x1aa: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x1aa, 0x1c4, x86_l_1c4);
x86_l_1ac:
	/* 0x1ac: mov    ebx,0x5b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 91ULL);
x86_l_1b1:
	/* 0x1b1: mov    r11d,0x56da2500 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1457136896ULL);
x86_l_1b7:
	/* 0x1b7: jmp    1c4 <packet_toeplitz_rss_hash_xdp+0x1c4> */
	X86_SIM_X86_JMP(0x1b7, 0x1c4, x86_l_1c4);
x86_l_1b9:
	/* 0x1b9: mov    ebx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 65ULL);
x86_l_1be:
	/* 0x1be: mov    r11d,0x5b0ec200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 1527693824ULL);
x86_l_1c4:
	/* 0x1c4: or     r11d,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c7:
	/* 0x1c7: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_1ca:
	/* 0x1ca: je     78 <packet_toeplitz_rss_hash_xdp+0x78> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ca, 0x78, x86_l_78);
x86_l_1d0:
	/* 0x1d0: mov    ebx,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 37ULL);
x86_l_1d5:
	/* 0x1d5: cmp    r10d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 5ULL);
x86_l_1d9:
	/* 0x1d9: jle    1f7 <packet_toeplitz_rss_hash_xdp+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1d9, 0x1f7, x86_l_1f7);
x86_l_1db:
	/* 0x1db: cmp    r10d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 8ULL);
x86_l_1df:
	/* 0x1df: jle    216 <packet_toeplitz_rss_hash_xdp+0x216> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1df, 0x216, x86_l_216);
x86_l_1e1:
	/* 0x1e1: cmp    r10d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 10ULL);
x86_l_1e5:
	/* 0x1e5: jg     24a <packet_toeplitz_rss_hash_xdp+0x24a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1e5, 0x24a, x86_l_24a);
x86_l_1e7:
	/* 0x1e7: cmp    r10d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 9ULL);
x86_l_1eb:
	/* 0x1eb: jne    264 <packet_toeplitz_rss_hash_xdp+0x264> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1eb, 0x264, x86_l_264);
x86_l_1ed:
	/* 0x1ed: mov    ebx,0xa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 163ULL);
x86_l_1f2:
	/* 0x1f2: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x1f2, 0x65, x86_l_65);
x86_l_1f7:
	/* 0x1f7: cmp    r10d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 2ULL);
x86_l_1fb:
	/* 0x1fb: jg     230 <packet_toeplitz_rss_hash_xdp+0x230> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1fb, 0x230, x86_l_230);
x86_l_1fd:
	/* 0x1fd: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_200:
	/* 0x200: je     65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JCC(X86_CC_E, 0x200, 0x65, x86_l_65);
x86_l_206:
	/* 0x206: cmp    r10d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 1ULL);
x86_l_20a:
	/* 0x20a: jne    278 <packet_toeplitz_rss_hash_xdp+0x278> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20a, 0x278, x86_l_278);
x86_l_20c:
	/* 0x20c: mov    ebx,0x5b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 91ULL);
x86_l_211:
	/* 0x211: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x211, 0x65, x86_l_65);
x86_l_216:
	/* 0x216: cmp    r10d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 6ULL);
x86_l_21a:
	/* 0x21a: je     65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21a, 0x65, x86_l_65);
x86_l_220:
	/* 0x220: cmp    r10d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 7ULL);
x86_l_224:
	/* 0x224: jne    25a <packet_toeplitz_rss_hash_xdp+0x25a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x224, 0x25a, x86_l_25a);
x86_l_226:
	/* 0x226: mov    ebx,0x3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 61ULL);
x86_l_22b:
	/* 0x22b: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x22b, 0x65, x86_l_65);
x86_l_230:
	/* 0x230: cmp    r10d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 3ULL);
x86_l_234:
	/* 0x234: je     60 <packet_toeplitz_rss_hash_xdp+0x60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x234, 0x60, x86_l_60);
x86_l_23a:
	/* 0x23a: cmp    r10d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 4ULL);
x86_l_23e:
	/* 0x23e: jne    282 <packet_toeplitz_rss_hash_xdp+0x282> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23e, 0x282, x86_l_282);
x86_l_240:
	/* 0x240: mov    ebx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 65ULL);
x86_l_245:
	/* 0x245: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x245, 0x65, x86_l_65);
x86_l_24a:
	/* 0x24a: cmp    r10d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 11ULL);
x86_l_24e:
	/* 0x24e: jne    26e <packet_toeplitz_rss_hash_xdp+0x26e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24e, 0x26e, x86_l_26e);
x86_l_250:
	/* 0x250: mov    ebx,0xb0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 176ULL);
x86_l_255:
	/* 0x255: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x255, 0x65, x86_l_65);
x86_l_25a:
	/* 0x25a: mov    ebx,0x43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 67ULL);
x86_l_25f:
	/* 0x25f: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x25f, 0x65, x86_l_65);
x86_l_264:
	/* 0x264: mov    ebx,0x8f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 143ULL);
x86_l_269:
	/* 0x269: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x269, 0x65, x86_l_65);
x86_l_26e:
	/* 0x26e: mov    ebx,0xd0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 208ULL);
x86_l_273:
	/* 0x273: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x273, 0x65, x86_l_65);
x86_l_278:
	/* 0x278: mov    ebx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_27d:
	/* 0x27d: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x27d, 0x65, x86_l_65);
x86_l_282:
	/* 0x282: mov    ebx,0x67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 103ULL);
x86_l_287:
	/* 0x287: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x287, 0x65, x86_l_65);
x86_l_28c:
	/* 0x28c: mov    esi,DWORD PTR [rdx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_28f:
	/* 0x28f: movzx  edi,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_293:
	/* 0x293: movzx  r8d,BYTE PTR [rdx+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_298:
	/* 0x298: movzx  r9d,BYTE PTR [rdx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_29d:
	/* 0x29d: movzx  r10d,BYTE PTR [rdx+0x2d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_2a2:
	/* 0x2a2: mov    r11,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RAX, X86_WIDTH_64);
x86_l_2a5:
	/* 0x2a5: shl    r11,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2a9:
	/* 0x2a9: xor    esi,DWORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RDX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 34ULL);
x86_l_2ac:
	/* 0x2ac: bswap  esi */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_2ae:
	/* 0x2ae: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2b0:
	/* 0x2b0: xor    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b2:
	/* 0x2b2: or     rdx,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R11, X86_WIDTH_64, X86_ALU_OR);
x86_l_2b5:
	/* 0x2b5: shl    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_2b9:
	/* 0x2b9: shl    r8,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_2bd:
	/* 0x2bd: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c0:
	/* 0x2c0: shl    r9,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_2c4:
	/* 0x2c4: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c7:
	/* 0x2c7: shl    r10,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2cb:
	/* 0x2cb: or     rsi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_2ce:
	/* 0x2ce: or     rsi,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d1:
	/* 0x2d1: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2d4:
	/* 0x2d4: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d7:
	/* 0x2d7: shlx   rdi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_2dc:
	/* 0x2dc: not    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_2de:
	/* 0x2de: shrx   rax,rsi,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RSI, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_2e3:
	/* 0x2e3: or     rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2e6:
	/* 0x2e6: xor    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_2e9:
	/* 0x2e9: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec:
	/* 0x2ec: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f1:
	/* 0x2f1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2f2:
	/* 0x2f2: jmp    2f7 <packet_toeplitz_rss_hash_xdp+0x2f7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2f7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
