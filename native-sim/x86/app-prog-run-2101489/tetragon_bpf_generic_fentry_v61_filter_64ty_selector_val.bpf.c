#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_fentry_v61_filter_64ty_selector_val_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3:
	/* 0x3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8:
	/* 0x8: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_c:
	/* 0xc: ja     90 <filter_64ty_selector_val+0x90> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc, 0x90, x86_l_90);
x86_l_12:
	/* 0x12: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1c:
	/* 0x1c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_20:
	/* 0x20: jae    27 <filter_64ty_selector_val+0x27> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x20, 0x27, x86_l_27);
x86_l_22:
	/* 0x22: jmp    242 <filter_64ty_selector_val+0x242> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_27:
	/* 0x27: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_2c:
	/* 0x2c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_30:
	/* 0x30: jae    4c <filter_64ty_selector_val+0x4c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x30, 0x4c, x86_l_4c);
x86_l_32:
	/* 0x32: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35:
	/* 0x35: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_39:
	/* 0x39: jne    16e <filter_64ty_selector_val+0x16e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x39, 0x16e, x86_l_16e);
x86_l_3f:
	/* 0x3f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41:
	/* 0x41: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_44:
	/* 0x44: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_47:
	/* 0x47: jmp    242 <filter_64ty_selector_val+0x242> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4c:
	/* 0x4c: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_50:
	/* 0x50: jne    90 <filter_64ty_selector_val+0x90> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50, 0x90, x86_l_90);
x86_l_52:
	/* 0x52: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55:
	/* 0x55: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59:
	/* 0x59: jne    22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59, 0x22, x86_l_22);
x86_l_5b:
	/* 0x5b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e:
	/* 0x5e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_61:
	/* 0x61: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x61, 0x23b, x86_l_23b);
x86_l_67:
	/* 0x67: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b:
	/* 0x6b: jne    22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b, 0x22, x86_l_22);
x86_l_6d:
	/* 0x6d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_70:
	/* 0x70: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x70, 0x23b, x86_l_23b);
x86_l_76:
	/* 0x76: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a:
	/* 0x7a: jne    22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7a, 0x22, x86_l_22);
x86_l_7c:
	/* 0x7c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_7f:
	/* 0x7f: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7f, 0x23b, x86_l_23b);
x86_l_85:
	/* 0x85: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_89:
	/* 0x89: jne    22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x89, 0x22, x86_l_22);
x86_l_8b:
	/* 0x8b: jmp    23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JMP(0x8b, 0x23b, x86_l_23b);
x86_l_90:
	/* 0x90: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_93:
	/* 0x93: je     106 <filter_64ty_selector_val+0x106> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93, 0x106, x86_l_106);
x86_l_95:
	/* 0x95: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_98:
	/* 0x98: jne    23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x98, 0x23b, x86_l_23b);
x86_l_9e:
	/* 0x9e: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a1:
	/* 0xa1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_a4:
	/* 0xa4: ja     1fe <filter_64ty_selector_val+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa4, 0x1fe, x86_l_1fe);
x86_l_aa:
	/* 0xaa: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_af:
	/* 0xaf: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: jae    1fe <filter_64ty_selector_val+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xb2, 0x1fe, x86_l_1fe);
x86_l_b8:
	/* 0xb8: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb:
	/* 0xbb: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_bf:
	/* 0xbf: jl     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_L, 0xbf, 0x22, x86_l_22);
x86_l_c5:
	/* 0xc5: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8:
	/* 0xc8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_cb:
	/* 0xcb: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0xcb, 0x23b, x86_l_23b);
x86_l_d1:
	/* 0xd1: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d5:
	/* 0xd5: jl     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_L, 0xd5, 0x22, x86_l_22);
x86_l_db:
	/* 0xdb: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_de:
	/* 0xde: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0xde, 0x23b, x86_l_23b);
x86_l_e4:
	/* 0xe4: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_e8:
	/* 0xe8: jl     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_L, 0xe8, 0x22, x86_l_22);
x86_l_ee:
	/* 0xee: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_f1:
	/* 0xf1: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0xf1, 0x23b, x86_l_23b);
x86_l_f7:
	/* 0xf7: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_fb:
	/* 0xfb: jl     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_L, 0xfb, 0x22, x86_l_22);
x86_l_101:
	/* 0x101: jmp    23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JMP(0x101, 0x23b, x86_l_23b);
x86_l_106:
	/* 0x106: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_109:
	/* 0x109: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_10c:
	/* 0x10c: ja     1bf <filter_64ty_selector_val+0x1bf> */
	X86_SIM_X86_JCC(X86_CC_A, 0x10c, 0x1bf, x86_l_1bf);
x86_l_112:
	/* 0x112: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_117:
	/* 0x117: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_11a:
	/* 0x11a: jae    1bf <filter_64ty_selector_val+0x1bf> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x11a, 0x1bf, x86_l_1bf);
x86_l_120:
	/* 0x120: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123:
	/* 0x123: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_127:
	/* 0x127: jg     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_G, 0x127, 0x22, x86_l_22);
x86_l_12d:
	/* 0x12d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130:
	/* 0x130: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_133:
	/* 0x133: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x133, 0x23b, x86_l_23b);
x86_l_139:
	/* 0x139: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_13d:
	/* 0x13d: jg     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13d, 0x22, x86_l_22);
x86_l_143:
	/* 0x143: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_146:
	/* 0x146: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x146, 0x23b, x86_l_23b);
x86_l_14c:
	/* 0x14c: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_150:
	/* 0x150: jg     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_G, 0x150, 0x22, x86_l_22);
x86_l_156:
	/* 0x156: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_159:
	/* 0x159: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x159, 0x23b, x86_l_23b);
x86_l_15f:
	/* 0x15f: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_163:
	/* 0x163: jg     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_G, 0x163, 0x22, x86_l_22);
x86_l_169:
	/* 0x169: jmp    23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JMP(0x169, 0x23b, x86_l_23b);
x86_l_16e:
	/* 0x16e: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_171:
	/* 0x171: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_174:
	/* 0x174: jb     19e <filter_64ty_selector_val+0x19e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x174, 0x19e, x86_l_19e);
x86_l_176:
	/* 0x176: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_17a:
	/* 0x17a: je     3f <filter_64ty_selector_val+0x3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17a, 0x3f, x86_l_3f);
x86_l_180:
	/* 0x180: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_183:
	/* 0x183: jb     19e <filter_64ty_selector_val+0x19e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x183, 0x19e, x86_l_19e);
x86_l_185:
	/* 0x185: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_189:
	/* 0x189: je     3f <filter_64ty_selector_val+0x3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x189, 0x3f, x86_l_3f);
x86_l_18f:
	/* 0x18f: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_192:
	/* 0x192: jb     19e <filter_64ty_selector_val+0x19e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x192, 0x19e, x86_l_19e);
x86_l_194:
	/* 0x194: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_198:
	/* 0x198: je     3f <filter_64ty_selector_val+0x3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x198, 0x3f, x86_l_3f);
x86_l_19e:
	/* 0x19e: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1a1:
	/* 0x1a1: ja     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a1, 0x23b, x86_l_23b);
x86_l_1a7:
	/* 0x1a7: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1a9:
	/* 0x1a9: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1b3:
	/* 0x1b3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b7:
	/* 0x1b7: jb     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b7, 0x22, x86_l_22);
x86_l_1bd:
	/* 0x1bd: jmp    23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JMP(0x1bd, 0x23b, x86_l_23b);
x86_l_1bf:
	/* 0x1bf: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2:
	/* 0x1c2: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1c6:
	/* 0x1c6: ja     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1c6, 0x22, x86_l_22);
x86_l_1cc:
	/* 0x1cc: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf:
	/* 0x1cf: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d2:
	/* 0x1d2: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d2, 0x23b, x86_l_23b);
x86_l_1d4:
	/* 0x1d4: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1d8:
	/* 0x1d8: ja     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d8, 0x22, x86_l_22);
x86_l_1de:
	/* 0x1de: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1e1:
	/* 0x1e1: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e1, 0x23b, x86_l_23b);
x86_l_1e3:
	/* 0x1e3: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1e7:
	/* 0x1e7: ja     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1e7, 0x22, x86_l_22);
x86_l_1ed:
	/* 0x1ed: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f0:
	/* 0x1f0: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1f0, 0x23b, x86_l_23b);
x86_l_1f2:
	/* 0x1f2: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1f6:
	/* 0x1f6: ja     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1f6, 0x22, x86_l_22);
x86_l_1fc:
	/* 0x1fc: jmp    23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JMP(0x1fc, 0x23b, x86_l_23b);
x86_l_1fe:
	/* 0x1fe: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_201:
	/* 0x201: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_205:
	/* 0x205: jb     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_B, 0x205, 0x22, x86_l_22);
x86_l_20b:
	/* 0x20b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e:
	/* 0x20e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_211:
	/* 0x211: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x211, 0x23b, x86_l_23b);
x86_l_213:
	/* 0x213: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_217:
	/* 0x217: jb     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_B, 0x217, 0x22, x86_l_22);
x86_l_21d:
	/* 0x21d: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_220:
	/* 0x220: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x220, 0x23b, x86_l_23b);
x86_l_222:
	/* 0x222: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_226:
	/* 0x226: jb     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_B, 0x226, 0x22, x86_l_22);
x86_l_22c:
	/* 0x22c: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_22f:
	/* 0x22f: jb     23b <filter_64ty_selector_val+0x23b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x22f, 0x23b, x86_l_23b);
x86_l_231:
	/* 0x231: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_235:
	/* 0x235: jb     22 <filter_64ty_selector_val+0x22> */
	X86_SIM_X86_JCC(X86_CC_B, 0x235, 0x22, x86_l_22);
x86_l_23b:
	/* 0x23b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23d:
	/* 0x23d: jmp    242 <filter_64ty_selector_val+0x242> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_242:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
