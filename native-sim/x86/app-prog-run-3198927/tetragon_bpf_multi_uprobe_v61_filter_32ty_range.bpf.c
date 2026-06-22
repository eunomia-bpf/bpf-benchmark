#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_uprobe_v61_filter_32ty_range_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x9: ja     ef <filter_32ty_range+0xef> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9, 0xef, x86_l_ef);
x86_l_f:
	/* 0xf: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_14:
	/* 0x14: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_17:
	/* 0x17: jae    ef <filter_32ty_range+0xef> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x17, 0xef, x86_l_ef);
x86_l_1d:
	/* 0x1d: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f:
	/* 0x1f: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_22:
	/* 0x22: jne    8a <filter_32ty_range+0x8a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22, 0x8a, x86_l_8a);
x86_l_24:
	/* 0x24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29:
	/* 0x29: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c:
	/* 0x2c: jg     37 <filter_32ty_range+0x37> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2c, 0x37, x86_l_37);
x86_l_2e:
	/* 0x2e: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_31:
	/* 0x31: jle    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x31, 0x105, x86_l_105);
x86_l_37:
	/* 0x37: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a:
	/* 0x3a: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_3d:
	/* 0x3d: jb     1a9 <filter_32ty_range+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3d, 0x1a9, x86_l_1a9);
x86_l_43:
	/* 0x43: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46:
	/* 0x46: jg     51 <filter_32ty_range+0x51> */
	X86_SIM_X86_JCC(X86_CC_G, 0x46, 0x51, x86_l_51);
x86_l_48:
	/* 0x48: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_4b:
	/* 0x4b: jle    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4b, 0x105, x86_l_105);
x86_l_51:
	/* 0x51: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_54:
	/* 0x54: jb     1a9 <filter_32ty_range+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x54, 0x1a9, x86_l_1a9);
x86_l_5a:
	/* 0x5a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d:
	/* 0x5d: jg     68 <filter_32ty_range+0x68> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5d, 0x68, x86_l_68);
x86_l_5f:
	/* 0x5f: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_62:
	/* 0x62: jle    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x62, 0x105, x86_l_105);
x86_l_68:
	/* 0x68: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_6b:
	/* 0x6b: jb     1a9 <filter_32ty_range+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6b, 0x1a9, x86_l_1a9);
x86_l_71:
	/* 0x71: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73:
	/* 0x73: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_76:
	/* 0x76: jg     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_G, 0x76, 0x1ab, x86_l_1ab);
x86_l_7c:
	/* 0x7c: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_7f:
	/* 0x7f: jle    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x7f, 0x105, x86_l_105);
x86_l_85:
	/* 0x85: jmp    1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JMP(0x85, 0x1ab, x86_l_1ab);
x86_l_8a:
	/* 0x8a: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d:
	/* 0x8d: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_90:
	/* 0x90: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_94:
	/* 0x94: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_97:
	/* 0x97: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_9a:
	/* 0x9a: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_9d:
	/* 0x9d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_a0:
	/* 0xa0: jb     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa0, 0x1ab, x86_l_1ab);
x86_l_a6:
	/* 0xa6: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a9:
	/* 0xa9: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_ad:
	/* 0xad: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_b0:
	/* 0xb0: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_b4:
	/* 0xb4: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_b7:
	/* 0xb7: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_ba:
	/* 0xba: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_bd:
	/* 0xbd: jb     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0xbd, 0x1ab, x86_l_1ab);
x86_l_c3:
	/* 0xc3: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c6:
	/* 0xc6: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_ca:
	/* 0xca: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_cd:
	/* 0xcd: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_d1:
	/* 0xd1: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_d4:
	/* 0xd4: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_d7:
	/* 0xd7: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_da:
	/* 0xda: jb     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0xda, 0x1ab, x86_l_1ab);
x86_l_e0:
	/* 0xe0: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e3:
	/* 0xe3: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_e6:
	/* 0xe6: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_e9:
	/* 0xe9: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_ed:
	/* 0xed: jmp    165 <filter_32ty_range+0x165> */
	X86_SIM_X86_JMP(0xed, 0x165, x86_l_165);
x86_l_ef:
	/* 0xef: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1:
	/* 0xf1: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_f4:
	/* 0xf4: jne    10a <filter_32ty_range+0x10a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf4, 0x10a, x86_l_10a);
x86_l_f6:
	/* 0xf6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fb:
	/* 0xfb: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe:
	/* 0xfe: ja     16d <filter_32ty_range+0x16d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xfe, 0x16d, x86_l_16d);
x86_l_100:
	/* 0x100: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_103:
	/* 0x103: ja     16d <filter_32ty_range+0x16d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x103, 0x16d, x86_l_16d);
x86_l_105:
	/* 0x105: jmp    1be <filter_32ty_range+0x1be> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_10a:
	/* 0x10a: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d:
	/* 0x10d: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110:
	/* 0x110: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_114:
	/* 0x114: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_117:
	/* 0x117: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_11a:
	/* 0x11a: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_11d:
	/* 0x11d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_120:
	/* 0x120: jb     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x120, 0x1ab, x86_l_1ab);
x86_l_126:
	/* 0x126: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_129:
	/* 0x129: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_12d:
	/* 0x12d: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_130:
	/* 0x130: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_134:
	/* 0x134: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_137:
	/* 0x137: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_13a:
	/* 0x13a: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_13d:
	/* 0x13d: jb     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x13d, 0x1ab, x86_l_1ab);
x86_l_13f:
	/* 0x13f: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_142:
	/* 0x142: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_146:
	/* 0x146: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_149:
	/* 0x149: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_14d:
	/* 0x14d: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_150:
	/* 0x150: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_153:
	/* 0x153: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_156:
	/* 0x156: jb     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x156, 0x1ab, x86_l_1ab);
x86_l_158:
	/* 0x158: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15b:
	/* 0x15b: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_15e:
	/* 0x15e: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_161:
	/* 0x161: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_165:
	/* 0x165: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_168:
	/* 0x168: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_16b:
	/* 0x16b: jmp    1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JMP(0x16b, 0x1ab, x86_l_1ab);
x86_l_16d:
	/* 0x16d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_170:
	/* 0x170: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_173:
	/* 0x173: jb     1a9 <filter_32ty_range+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x173, 0x1a9, x86_l_1a9);
x86_l_175:
	/* 0x175: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_178:
	/* 0x178: ja     17f <filter_32ty_range+0x17f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x178, 0x17f, x86_l_17f);
x86_l_17a:
	/* 0x17a: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_17d:
	/* 0x17d: jbe    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x17d, 0x105, x86_l_105);
x86_l_17f:
	/* 0x17f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_182:
	/* 0x182: jb     1a9 <filter_32ty_range+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x182, 0x1a9, x86_l_1a9);
x86_l_184:
	/* 0x184: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_187:
	/* 0x187: ja     192 <filter_32ty_range+0x192> */
	X86_SIM_X86_JCC(X86_CC_A, 0x187, 0x192, x86_l_192);
x86_l_189:
	/* 0x189: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_18c:
	/* 0x18c: jbe    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x18c, 0x105, x86_l_105);
x86_l_192:
	/* 0x192: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_195:
	/* 0x195: jb     1a9 <filter_32ty_range+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x195, 0x1a9, x86_l_1a9);
x86_l_197:
	/* 0x197: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199:
	/* 0x199: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19c:
	/* 0x19c: ja     1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19c, 0x1ab, x86_l_1ab);
x86_l_19e:
	/* 0x19e: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1a1:
	/* 0x1a1: jbe    105 <filter_32ty_range+0x105> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1a1, 0x105, x86_l_105);
x86_l_1a7:
	/* 0x1a7: jmp    1ab <filter_32ty_range+0x1ab> */
	X86_SIM_X86_JMP(0x1a7, 0x1ab, x86_l_1ab);
x86_l_1a9:
	/* 0x1a9: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab:
	/* 0x1ab: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1ae:
	/* 0x1ae: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1b1:
	/* 0x1b1: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1b4:
	/* 0x1b4: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1b6:
	/* 0x1b6: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b9:
	/* 0x1b9: jmp    1be <filter_32ty_range+0x1be> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1be:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
