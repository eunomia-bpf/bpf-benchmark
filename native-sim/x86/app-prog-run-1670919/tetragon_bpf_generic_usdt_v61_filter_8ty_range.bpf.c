#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_v61_filter_8ty_range_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x9: ja     f0 <filter_8ty_range+0xf0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9, 0xf0, x86_l_f0);
x86_l_f:
	/* 0xf: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_14:
	/* 0x14: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_17:
	/* 0x17: jae    f0 <filter_8ty_range+0xf0> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x17, 0xf0, x86_l_f0);
x86_l_1d:
	/* 0x1d: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20:
	/* 0x20: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_23:
	/* 0x23: jne    8b <filter_8ty_range+0x8b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23, 0x8b, x86_l_8b);
x86_l_25:
	/* 0x25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a:
	/* 0x2a: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d:
	/* 0x2d: jg     38 <filter_8ty_range+0x38> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2d, 0x38, x86_l_38);
x86_l_2f:
	/* 0x2f: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_32:
	/* 0x32: jge    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x32, 0x107, x86_l_107);
x86_l_38:
	/* 0x38: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b:
	/* 0x3b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_3e:
	/* 0x3e: jb     1ab <filter_8ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3e, 0x1ab, x86_l_1ab);
x86_l_44:
	/* 0x44: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47:
	/* 0x47: jg     52 <filter_8ty_range+0x52> */
	X86_SIM_X86_JCC(X86_CC_G, 0x47, 0x52, x86_l_52);
x86_l_49:
	/* 0x49: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4c:
	/* 0x4c: jge    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x4c, 0x107, x86_l_107);
x86_l_52:
	/* 0x52: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_55:
	/* 0x55: jb     1ab <filter_8ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x55, 0x1ab, x86_l_1ab);
x86_l_5b:
	/* 0x5b: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e:
	/* 0x5e: jg     69 <filter_8ty_range+0x69> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5e, 0x69, x86_l_69);
x86_l_60:
	/* 0x60: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_63:
	/* 0x63: jge    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x63, 0x107, x86_l_107);
x86_l_69:
	/* 0x69: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_6c:
	/* 0x6c: jb     1ab <filter_8ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6c, 0x1ab, x86_l_1ab);
x86_l_72:
	/* 0x72: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_74:
	/* 0x74: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_77:
	/* 0x77: jg     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_G, 0x77, 0x1ad, x86_l_1ad);
x86_l_7d:
	/* 0x7d: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_80:
	/* 0x80: jge    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x80, 0x107, x86_l_107);
x86_l_86:
	/* 0x86: jmp    1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JMP(0x86, 0x1ad, x86_l_1ad);
x86_l_8b:
	/* 0x8b: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e:
	/* 0x8e: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91:
	/* 0x91: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_95:
	/* 0x95: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_98:
	/* 0x98: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_9b:
	/* 0x9b: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_9e:
	/* 0x9e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_a1:
	/* 0xa1: jb     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa1, 0x1ad, x86_l_1ad);
x86_l_a7:
	/* 0xa7: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aa:
	/* 0xaa: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_ae:
	/* 0xae: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_b1:
	/* 0xb1: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_b5:
	/* 0xb5: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_b8:
	/* 0xb8: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_bb:
	/* 0xbb: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_be:
	/* 0xbe: jb     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_B, 0xbe, 0x1ad, x86_l_1ad);
x86_l_c4:
	/* 0xc4: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c7:
	/* 0xc7: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_cb:
	/* 0xcb: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ce:
	/* 0xce: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_d2:
	/* 0xd2: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_d5:
	/* 0xd5: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_d8:
	/* 0xd8: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_db:
	/* 0xdb: jb     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_B, 0xdb, 0x1ad, x86_l_1ad);
x86_l_e1:
	/* 0xe1: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e4:
	/* 0xe4: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_e7:
	/* 0xe7: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ea:
	/* 0xea: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_ee:
	/* 0xee: jmp    167 <filter_8ty_range+0x167> */
	X86_SIM_X86_JMP(0xee, 0x167, x86_l_167);
x86_l_f0:
	/* 0xf0: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f3:
	/* 0xf3: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_f6:
	/* 0xf6: jne    10c <filter_8ty_range+0x10c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6, 0x10c, x86_l_10c);
x86_l_f8:
	/* 0xf8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd:
	/* 0xfd: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100:
	/* 0x100: ja     16f <filter_8ty_range+0x16f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x100, 0x16f, x86_l_16f);
x86_l_102:
	/* 0x102: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_105:
	/* 0x105: jb     16f <filter_8ty_range+0x16f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x105, 0x16f, x86_l_16f);
x86_l_107:
	/* 0x107: jmp    1c0 <filter_8ty_range+0x1c0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_10c:
	/* 0x10c: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f:
	/* 0x10f: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112:
	/* 0x112: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_116:
	/* 0x116: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_119:
	/* 0x119: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_11c:
	/* 0x11c: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_11f:
	/* 0x11f: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_122:
	/* 0x122: jb     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_B, 0x122, 0x1ad, x86_l_1ad);
x86_l_128:
	/* 0x128: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b:
	/* 0x12b: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_12f:
	/* 0x12f: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_132:
	/* 0x132: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_136:
	/* 0x136: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_139:
	/* 0x139: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_13c:
	/* 0x13c: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_13f:
	/* 0x13f: jb     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_B, 0x13f, 0x1ad, x86_l_1ad);
x86_l_141:
	/* 0x141: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_144:
	/* 0x144: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_148:
	/* 0x148: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14b:
	/* 0x14b: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_14f:
	/* 0x14f: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_152:
	/* 0x152: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_155:
	/* 0x155: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_158:
	/* 0x158: jb     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_B, 0x158, 0x1ad, x86_l_1ad);
x86_l_15a:
	/* 0x15a: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15d:
	/* 0x15d: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_160:
	/* 0x160: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_163:
	/* 0x163: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_167:
	/* 0x167: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_16a:
	/* 0x16a: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_16d:
	/* 0x16d: jmp    1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JMP(0x16d, 0x1ad, x86_l_1ad);
x86_l_16f:
	/* 0x16f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172:
	/* 0x172: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_175:
	/* 0x175: jb     1ab <filter_8ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x175, 0x1ab, x86_l_1ab);
x86_l_177:
	/* 0x177: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a:
	/* 0x17a: ja     181 <filter_8ty_range+0x181> */
	X86_SIM_X86_JCC(X86_CC_A, 0x17a, 0x181, x86_l_181);
x86_l_17c:
	/* 0x17c: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17f:
	/* 0x17f: jae    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x17f, 0x107, x86_l_107);
x86_l_181:
	/* 0x181: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_184:
	/* 0x184: jb     1ab <filter_8ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x184, 0x1ab, x86_l_1ab);
x86_l_186:
	/* 0x186: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_189:
	/* 0x189: ja     194 <filter_8ty_range+0x194> */
	X86_SIM_X86_JCC(X86_CC_A, 0x189, 0x194, x86_l_194);
x86_l_18b:
	/* 0x18b: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18e:
	/* 0x18e: jae    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x18e, 0x107, x86_l_107);
x86_l_194:
	/* 0x194: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_197:
	/* 0x197: jb     1ab <filter_8ty_range+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x197, 0x1ab, x86_l_1ab);
x86_l_199:
	/* 0x199: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b:
	/* 0x19b: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19e:
	/* 0x19e: ja     1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19e, 0x1ad, x86_l_1ad);
x86_l_1a0:
	/* 0x1a0: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a3:
	/* 0x1a3: jae    107 <filter_8ty_range+0x107> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1a3, 0x107, x86_l_107);
x86_l_1a9:
	/* 0x1a9: jmp    1ad <filter_8ty_range+0x1ad> */
	X86_SIM_X86_JMP(0x1a9, 0x1ad, x86_l_1ad);
x86_l_1ab:
	/* 0x1ab: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad:
	/* 0x1ad: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1b0:
	/* 0x1b0: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1b3:
	/* 0x1b3: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1b6:
	/* 0x1b6: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1b8:
	/* 0x1b8: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bb:
	/* 0x1bb: jmp    1c0 <filter_8ty_range+0x1c0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1c0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
