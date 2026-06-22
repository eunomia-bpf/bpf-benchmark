#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_rawtp_v61_filter_64ty_range_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3:
	/* 0x3: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6:
	/* 0x6: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_9:
	/* 0x9: ja     103 <filter_64ty_range+0x103> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9, 0x103, x86_l_103);
x86_l_f:
	/* 0xf: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_14:
	/* 0x14: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_17:
	/* 0x17: jae    103 <filter_64ty_range+0x103> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x17, 0x103, x86_l_103);
x86_l_1d:
	/* 0x1d: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20:
	/* 0x20: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_23:
	/* 0x23: jne    93 <filter_64ty_range+0x93> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23, 0x93, x86_l_93);
x86_l_25:
	/* 0x25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a:
	/* 0x2a: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e:
	/* 0x2e: jg     3a <filter_64ty_range+0x3a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2e, 0x3a, x86_l_3a);
x86_l_30:
	/* 0x30: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_34:
	/* 0x34: jle    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x34, 0x11c, x86_l_11c);
x86_l_3a:
	/* 0x3a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d:
	/* 0x3d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_40:
	/* 0x40: jb     1d2 <filter_64ty_range+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x40, 0x1d2, x86_l_1d2);
x86_l_46:
	/* 0x46: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a:
	/* 0x4a: jg     56 <filter_64ty_range+0x56> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4a, 0x56, x86_l_56);
x86_l_4c:
	/* 0x4c: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_50:
	/* 0x50: jle    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x50, 0x11c, x86_l_11c);
x86_l_56:
	/* 0x56: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_59:
	/* 0x59: jb     1d2 <filter_64ty_range+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x59, 0x1d2, x86_l_1d2);
x86_l_5f:
	/* 0x5f: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_63:
	/* 0x63: jg     6f <filter_64ty_range+0x6f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x63, 0x6f, x86_l_6f);
x86_l_65:
	/* 0x65: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_69:
	/* 0x69: jle    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x69, 0x11c, x86_l_11c);
x86_l_6f:
	/* 0x6f: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_72:
	/* 0x72: jb     1d2 <filter_64ty_range+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x72, 0x1d2, x86_l_1d2);
x86_l_78:
	/* 0x78: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a:
	/* 0x7a: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7e:
	/* 0x7e: jg     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7e, 0x1d4, x86_l_1d4);
x86_l_84:
	/* 0x84: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_88:
	/* 0x88: jle    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x88, 0x11c, x86_l_11c);
x86_l_8e:
	/* 0x8e: jmp    1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JMP(0x8e, 0x1d4, x86_l_1d4);
x86_l_93:
	/* 0x93: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_96:
	/* 0x96: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a:
	/* 0x9a: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_9e:
	/* 0x9e: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_a2:
	/* 0xa2: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_a5:
	/* 0xa5: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_a8:
	/* 0xa8: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_ab:
	/* 0xab: jb     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0xab, 0x1d4, x86_l_1d4);
x86_l_b1:
	/* 0xb1: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5:
	/* 0xb5: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_b9:
	/* 0xb9: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_bd:
	/* 0xbd: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_c1:
	/* 0xc1: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_c4:
	/* 0xc4: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_c7:
	/* 0xc7: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_ca:
	/* 0xca: jb     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0xca, 0x1d4, x86_l_1d4);
x86_l_d0:
	/* 0xd0: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d4:
	/* 0xd4: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_d8:
	/* 0xd8: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_dc:
	/* 0xdc: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e0:
	/* 0xe0: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e3:
	/* 0xe3: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e6:
	/* 0xe6: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_e9:
	/* 0xe9: jb     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe9, 0x1d4, x86_l_1d4);
x86_l_ef:
	/* 0xef: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f3:
	/* 0xf3: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_f6:
	/* 0xf6: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_fa:
	/* 0xfa: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_fe:
	/* 0xfe: jmp    184 <filter_64ty_range+0x184> */
	X86_SIM_X86_JMP(0xfe, 0x184, x86_l_184);
x86_l_103:
	/* 0x103: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106:
	/* 0x106: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_109:
	/* 0x109: jne    121 <filter_64ty_range+0x121> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x109, 0x121, x86_l_121);
x86_l_10b:
	/* 0x10b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_110:
	/* 0x110: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_114:
	/* 0x114: ja     18c <filter_64ty_range+0x18c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114, 0x18c, x86_l_18c);
x86_l_116:
	/* 0x116: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_11a:
	/* 0x11a: ja     18c <filter_64ty_range+0x18c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11a, 0x18c, x86_l_18c);
x86_l_11c:
	/* 0x11c: jmp    1e7 <filter_64ty_range+0x1e7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_121:
	/* 0x121: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_124:
	/* 0x124: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_128:
	/* 0x128: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_12c:
	/* 0x12c: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_130:
	/* 0x130: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_133:
	/* 0x133: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_136:
	/* 0x136: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_139:
	/* 0x139: jb     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x139, 0x1d4, x86_l_1d4);
x86_l_13f:
	/* 0x13f: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_143:
	/* 0x143: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_147:
	/* 0x147: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_14b:
	/* 0x14b: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_14f:
	/* 0x14f: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_152:
	/* 0x152: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_155:
	/* 0x155: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_158:
	/* 0x158: jb     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x158, 0x1d4, x86_l_1d4);
x86_l_15a:
	/* 0x15a: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15e:
	/* 0x15e: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_162:
	/* 0x162: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_166:
	/* 0x166: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_16a:
	/* 0x16a: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_16d:
	/* 0x16d: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_170:
	/* 0x170: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_173:
	/* 0x173: jb     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x173, 0x1d4, x86_l_1d4);
x86_l_175:
	/* 0x175: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_179:
	/* 0x179: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_17c:
	/* 0x17c: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_180:
	/* 0x180: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_184:
	/* 0x184: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_187:
	/* 0x187: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_18a:
	/* 0x18a: jmp    1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JMP(0x18a, 0x1d4, x86_l_1d4);
x86_l_18c:
	/* 0x18c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f:
	/* 0x18f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_192:
	/* 0x192: jb     1d2 <filter_64ty_range+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x192, 0x1d2, x86_l_1d2);
x86_l_194:
	/* 0x194: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_198:
	/* 0x198: ja     1a4 <filter_64ty_range+0x1a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x198, 0x1a4, x86_l_1a4);
x86_l_19a:
	/* 0x19a: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_19e:
	/* 0x19e: jbe    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x19e, 0x11c, x86_l_11c);
x86_l_1a4:
	/* 0x1a4: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_1a7:
	/* 0x1a7: jb     1d2 <filter_64ty_range+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a7, 0x1d2, x86_l_1d2);
x86_l_1a9:
	/* 0x1a9: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ad:
	/* 0x1ad: ja     1b9 <filter_64ty_range+0x1b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ad, 0x1b9, x86_l_1b9);
x86_l_1af:
	/* 0x1af: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1b3:
	/* 0x1b3: jbe    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1b3, 0x11c, x86_l_11c);
x86_l_1b9:
	/* 0x1b9: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_1bc:
	/* 0x1bc: jb     1d2 <filter_64ty_range+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1bc, 0x1d2, x86_l_1d2);
x86_l_1be:
	/* 0x1be: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0:
	/* 0x1c0: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c4:
	/* 0x1c4: ja     1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1c4, 0x1d4, x86_l_1d4);
x86_l_1c6:
	/* 0x1c6: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_1ca:
	/* 0x1ca: jbe    11c <filter_64ty_range+0x11c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1ca, 0x11c, x86_l_11c);
x86_l_1d0:
	/* 0x1d0: jmp    1d4 <filter_64ty_range+0x1d4> */
	X86_SIM_X86_JMP(0x1d0, 0x1d4, x86_l_1d4);
x86_l_1d2:
	/* 0x1d2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d4:
	/* 0x1d4: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1d7:
	/* 0x1d7: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1da:
	/* 0x1da: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1dd:
	/* 0x1dd: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1df:
	/* 0x1df: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e2:
	/* 0x1e2: jmp    1e7 <filter_64ty_range+0x1e7> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1e7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
