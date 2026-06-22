extern char argfilter_maps;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_retuprobe_v61_filter_16ty_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1:
	/* 0x1: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4:
	/* 0x4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6:
	/* 0x6: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_a:
	/* 0xa: ja     4d <filter_16ty+0x4d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa, 0x4d, x86_l_4d);
x86_l_c:
	/* 0xc: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_11:
	/* 0x11: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_15:
	/* 0x15: jae    22 <filter_16ty+0x22> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x15, 0x22, x86_l_22);
x86_l_17:
	/* 0x17: call   53 <filter_16ty_selector_val> */
	X86_SIM_X86_CALL(x86_l_53, 0x1cULL);
x86_l_1c:
	/* 0x1c: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: jmp    4ab <filter_16ty_map+0x86> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_22:
	/* 0x22: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_27:
	/* 0x27: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: jb     48 <filter_16ty+0x48> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2b, 0x48, x86_l_48);
x86_l_2d:
	/* 0x2d: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_37:
	/* 0x37: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: jae    4d <filter_16ty+0x4d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3b, 0x4d, x86_l_4d);
x86_l_3d:
	/* 0x3d: call   26d <filter_16ty_range> */
	X86_SIM_X86_CALL(x86_l_26d, 0x42ULL);
x86_l_42:
	/* 0x42: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: jmp    4ab <filter_16ty_map+0x86> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_48:
	/* 0x48: call   425 <filter_16ty_map> */
	X86_SIM_X86_CALL(x86_l_425, 0x4dULL);
x86_l_4d:
	/* 0x4d: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_4e:
	/* 0x4e: jmp    4ab <filter_16ty_map+0x86> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4ab:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_53 */
x86_l_53:
	/* 0x53: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56:
	/* 0x56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b:
	/* 0x5b: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_5f:
	/* 0x5f: ja     d2 <filter_16ty_selector_val+0x7f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x5f, 0xd2, x86_l_d2);
x86_l_61:
	/* 0x61: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_6b:
	/* 0x6b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: jae    72 <filter_16ty_selector_val+0x1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6f, 0x72, x86_l_72);
x86_l_71:
	/* 0x71: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_72:
	/* 0x72: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_77:
	/* 0x77: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_7b:
	/* 0x7b: jae    92 <filter_16ty_selector_val+0x3f> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7b, 0x92, x86_l_92);
x86_l_7d:
	/* 0x7d: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_80:
	/* 0x80: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83:
	/* 0x83: jne    1a8 <filter_16ty_selector_val+0x155> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x83, 0x1a8, x86_l_1a8);
x86_l_89:
	/* 0x89: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b:
	/* 0x8b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8e:
	/* 0x8e: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_91:
	/* 0x91: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_92:
	/* 0x92: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_96:
	/* 0x96: jne    d2 <filter_16ty_selector_val+0x7f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x96, 0xd2, x86_l_d2);
x86_l_98:
	/* 0x98: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9b:
	/* 0x9b: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e:
	/* 0x9e: jne    71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x9e, 0x71, x86_l_71);
x86_l_a0:
	/* 0xa0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a3:
	/* 0xa3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a6:
	/* 0xa6: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa6, 0x26a, x86_l_26a);
x86_l_ac:
	/* 0xac: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_af:
	/* 0xaf: jne    71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xaf, 0x71, x86_l_71);
x86_l_b1:
	/* 0xb1: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b4:
	/* 0xb4: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xb4, 0x26a, x86_l_26a);
x86_l_ba:
	/* 0xba: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bd:
	/* 0xbd: jne    71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xbd, 0x71, x86_l_71);
x86_l_bf:
	/* 0xbf: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_c2:
	/* 0xc2: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xc2, 0x26a, x86_l_26a);
x86_l_c8:
	/* 0xc8: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_cb:
	/* 0xcb: jne    71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xcb, 0x71, x86_l_71);
x86_l_cd:
	/* 0xcd: jmp    26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JMP(0xcd, 0x26a, x86_l_26a);
x86_l_d2:
	/* 0xd2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d5:
	/* 0xd5: je     144 <filter_16ty_selector_val+0xf1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd5, 0x144, x86_l_144);
x86_l_d7:
	/* 0xd7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_da:
	/* 0xda: jne    26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xda, 0x26a, x86_l_26a);
x86_l_e0:
	/* 0xe0: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e3:
	/* 0xe3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e6:
	/* 0xe6: ja     231 <filter_16ty_selector_val+0x1de> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xe6, 0x231, x86_l_231);
x86_l_ec:
	/* 0xec: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_f1:
	/* 0xf1: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f4:
	/* 0xf4: jae    231 <filter_16ty_selector_val+0x1de> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xf4, 0x231, x86_l_231);
x86_l_fa:
	/* 0xfa: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_fd:
	/* 0xfd: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100:
	/* 0x100: jg     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x100, 0x71, x86_l_71);
x86_l_106:
	/* 0x106: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_109:
	/* 0x109: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_10c:
	/* 0x10c: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x10c, 0x26a, x86_l_26a);
x86_l_112:
	/* 0x112: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_115:
	/* 0x115: jg     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x115, 0x71, x86_l_71);
x86_l_11b:
	/* 0x11b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_11e:
	/* 0x11e: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11e, 0x26a, x86_l_26a);
x86_l_124:
	/* 0x124: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_127:
	/* 0x127: jg     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x127, 0x71, x86_l_71);
x86_l_12d:
	/* 0x12d: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_130:
	/* 0x130: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x130, 0x26a, x86_l_26a);
x86_l_136:
	/* 0x136: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_139:
	/* 0x139: jg     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x139, 0x71, x86_l_71);
x86_l_13f:
	/* 0x13f: jmp    26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JMP(0x13f, 0x26a, x86_l_26a);
x86_l_144:
	/* 0x144: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_147:
	/* 0x147: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_14a:
	/* 0x14a: ja     1f6 <filter_16ty_selector_val+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x14a, 0x1f6, x86_l_1f6);
x86_l_150:
	/* 0x150: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_155:
	/* 0x155: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_158:
	/* 0x158: jae    1f6 <filter_16ty_selector_val+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x158, 0x1f6, x86_l_1f6);
x86_l_15e:
	/* 0x15e: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_161:
	/* 0x161: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_164:
	/* 0x164: jl     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x164, 0x71, x86_l_71);
x86_l_16a:
	/* 0x16a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16d:
	/* 0x16d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_170:
	/* 0x170: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x170, 0x26a, x86_l_26a);
x86_l_176:
	/* 0x176: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_179:
	/* 0x179: jl     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x179, 0x71, x86_l_71);
x86_l_17f:
	/* 0x17f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_182:
	/* 0x182: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x182, 0x26a, x86_l_26a);
x86_l_188:
	/* 0x188: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b:
	/* 0x18b: jl     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x18b, 0x71, x86_l_71);
x86_l_191:
	/* 0x191: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_194:
	/* 0x194: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x194, 0x26a, x86_l_26a);
x86_l_19a:
	/* 0x19a: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19d:
	/* 0x19d: jl     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x19d, 0x71, x86_l_71);
x86_l_1a3:
	/* 0x1a3: jmp    26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JMP(0x1a3, 0x26a, x86_l_26a);
x86_l_1a8:
	/* 0x1a8: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab:
	/* 0x1ab: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1ae:
	/* 0x1ae: jb     1d5 <filter_16ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ae, 0x1d5, x86_l_1d5);
x86_l_1b0:
	/* 0x1b0: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b3:
	/* 0x1b3: je     89 <filter_16ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b3, 0x89, x86_l_89);
x86_l_1b9:
	/* 0x1b9: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1bc:
	/* 0x1bc: jb     1d5 <filter_16ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1bc, 0x1d5, x86_l_1d5);
x86_l_1be:
	/* 0x1be: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c1:
	/* 0x1c1: je     89 <filter_16ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c1, 0x89, x86_l_89);
x86_l_1c7:
	/* 0x1c7: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1ca:
	/* 0x1ca: jb     1d5 <filter_16ty_selector_val+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ca, 0x1d5, x86_l_1d5);
x86_l_1cc:
	/* 0x1cc: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1cf:
	/* 0x1cf: je     89 <filter_16ty_selector_val+0x36> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cf, 0x89, x86_l_89);
x86_l_1d5:
	/* 0x1d5: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1d8:
	/* 0x1d8: ja     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1d8, 0x26a, x86_l_26a);
x86_l_1de:
	/* 0x1de: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e0:
	/* 0x1e0: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1ea:
	/* 0x1ea: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1ee:
	/* 0x1ee: jb     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ee, 0x71, x86_l_71);
x86_l_1f4:
	/* 0x1f4: jmp    26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JMP(0x1f4, 0x26a, x86_l_26a);
x86_l_1f6:
	/* 0x1f6: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f9:
	/* 0x1f9: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc:
	/* 0x1fc: jb     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fc, 0x71, x86_l_71);
x86_l_202:
	/* 0x202: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_205:
	/* 0x205: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_208:
	/* 0x208: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x208, 0x26a, x86_l_26a);
x86_l_20a:
	/* 0x20a: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20d:
	/* 0x20d: jb     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20d, 0x71, x86_l_71);
x86_l_213:
	/* 0x213: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_216:
	/* 0x216: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x216, 0x26a, x86_l_26a);
x86_l_218:
	/* 0x218: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21b:
	/* 0x21b: jb     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x21b, 0x71, x86_l_71);
x86_l_221:
	/* 0x221: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_224:
	/* 0x224: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x224, 0x26a, x86_l_26a);
x86_l_226:
	/* 0x226: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_229:
	/* 0x229: jb     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x229, 0x71, x86_l_71);
x86_l_22f:
	/* 0x22f: jmp    26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JMP(0x22f, 0x26a, x86_l_26a);
x86_l_231:
	/* 0x231: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_234:
	/* 0x234: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_237:
	/* 0x237: ja     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x237, 0x71, x86_l_71);
x86_l_23d:
	/* 0x23d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240:
	/* 0x240: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_243:
	/* 0x243: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x243, 0x26a, x86_l_26a);
x86_l_245:
	/* 0x245: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_248:
	/* 0x248: ja     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x248, 0x71, x86_l_71);
x86_l_24e:
	/* 0x24e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_251:
	/* 0x251: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x251, 0x26a, x86_l_26a);
x86_l_253:
	/* 0x253: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_256:
	/* 0x256: ja     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x256, 0x71, x86_l_71);
x86_l_25c:
	/* 0x25c: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_25f:
	/* 0x25f: jb     26a <filter_16ty_selector_val+0x217> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x25f, 0x26a, x86_l_26a);
x86_l_261:
	/* 0x261: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_264:
	/* 0x264: ja     71 <filter_16ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x264, 0x71, x86_l_71);
x86_l_26a:
	/* 0x26a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26c:
	/* 0x26c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_26d */
x86_l_26d:
	/* 0x26d: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_270:
	/* 0x270: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_273:
	/* 0x273: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_276:
	/* 0x276: ja     35d <filter_16ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x276, 0x35d, x86_l_35d);
x86_l_27c:
	/* 0x27c: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_281:
	/* 0x281: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_284:
	/* 0x284: jae    35d <filter_16ty_range+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x284, 0x35d, x86_l_35d);
x86_l_28a:
	/* 0x28a: movsx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28d:
	/* 0x28d: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_290:
	/* 0x290: jne    2f8 <filter_16ty_range+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x290, 0x2f8, x86_l_2f8);
x86_l_292:
	/* 0x292: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_297:
	/* 0x297: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29a:
	/* 0x29a: jg     2a5 <filter_16ty_range+0x38> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x29a, 0x2a5, x86_l_2a5);
x86_l_29c:
	/* 0x29c: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29f:
	/* 0x29f: jge    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x29f, 0x374, x86_l_374);
x86_l_2a5:
	/* 0x2a5: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a8:
	/* 0x2a8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2ab:
	/* 0x2ab: jb     414 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2ab, 0x414, x86_l_414);
x86_l_2b1:
	/* 0x2b1: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b4:
	/* 0x2b4: jg     2bf <filter_16ty_range+0x52> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2b4, 0x2bf, x86_l_2bf);
x86_l_2b6:
	/* 0x2b6: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2b9:
	/* 0x2b9: jge    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x2b9, 0x374, x86_l_374);
x86_l_2bf:
	/* 0x2bf: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2c2:
	/* 0x2c2: jb     414 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2c2, 0x414, x86_l_414);
x86_l_2c8:
	/* 0x2c8: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cb:
	/* 0x2cb: jg     2d6 <filter_16ty_range+0x69> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2cb, 0x2d6, x86_l_2d6);
x86_l_2cd:
	/* 0x2cd: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2d0:
	/* 0x2d0: jge    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x2d0, 0x374, x86_l_374);
x86_l_2d6:
	/* 0x2d6: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2d9:
	/* 0x2d9: jb     414 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2d9, 0x414, x86_l_414);
x86_l_2df:
	/* 0x2df: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e1:
	/* 0x2e1: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e4:
	/* 0x2e4: jg     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2e4, 0x416, x86_l_416);
x86_l_2ea:
	/* 0x2ea: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ed:
	/* 0x2ed: jge    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x2ed, 0x374, x86_l_374);
x86_l_2f3:
	/* 0x2f3: jmp    416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2f3, 0x416, x86_l_416);
x86_l_2f8:
	/* 0x2f8: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb:
	/* 0x2fb: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe:
	/* 0x2fe: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_302:
	/* 0x302: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_305:
	/* 0x305: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_308:
	/* 0x308: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_30b:
	/* 0x30b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_30e:
	/* 0x30e: jb     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x30e, 0x416, x86_l_416);
x86_l_314:
	/* 0x314: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_317:
	/* 0x317: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_31b:
	/* 0x31b: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_31e:
	/* 0x31e: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_322:
	/* 0x322: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_325:
	/* 0x325: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_328:
	/* 0x328: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_32b:
	/* 0x32b: jb     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x32b, 0x416, x86_l_416);
x86_l_331:
	/* 0x331: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_334:
	/* 0x334: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_338:
	/* 0x338: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_33b:
	/* 0x33b: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_33f:
	/* 0x33f: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_342:
	/* 0x342: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_345:
	/* 0x345: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_348:
	/* 0x348: jb     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x348, 0x416, x86_l_416);
x86_l_34e:
	/* 0x34e: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_351:
	/* 0x351: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_354:
	/* 0x354: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_357:
	/* 0x357: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_35b:
	/* 0x35b: jmp    3d0 <filter_16ty_range+0x163> */
	X86_SIM_X86_SUB_JMP(0x35b, 0x3d0, x86_l_3d0);
x86_l_35d:
	/* 0x35d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_360:
	/* 0x360: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_363:
	/* 0x363: jne    375 <filter_16ty_range+0x108> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x363, 0x375, x86_l_375);
x86_l_365:
	/* 0x365: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36a:
	/* 0x36a: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36d:
	/* 0x36d: ja     3d8 <filter_16ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x36d, 0x3d8, x86_l_3d8);
x86_l_36f:
	/* 0x36f: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_372:
	/* 0x372: jb     3d8 <filter_16ty_range+0x16b> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x372, 0x3d8, x86_l_3d8);
x86_l_374:
	/* 0x374: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_375:
	/* 0x375: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_378:
	/* 0x378: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b:
	/* 0x37b: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_37f:
	/* 0x37f: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_382:
	/* 0x382: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_385:
	/* 0x385: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_388:
	/* 0x388: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_38b:
	/* 0x38b: jb     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x38b, 0x416, x86_l_416);
x86_l_391:
	/* 0x391: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_394:
	/* 0x394: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_398:
	/* 0x398: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_39b:
	/* 0x39b: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_39f:
	/* 0x39f: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_3a2:
	/* 0x3a2: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_3a5:
	/* 0x3a5: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3a8:
	/* 0x3a8: jb     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3a8, 0x416, x86_l_416);
x86_l_3aa:
	/* 0x3aa: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ad:
	/* 0x3ad: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_3b1:
	/* 0x3b1: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3b4:
	/* 0x3b4: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_3b8:
	/* 0x3b8: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_3bb:
	/* 0x3bb: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_3be:
	/* 0x3be: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_3c1:
	/* 0x3c1: jb     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3c1, 0x416, x86_l_416);
x86_l_3c3:
	/* 0x3c3: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c6:
	/* 0x3c6: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_3c9:
	/* 0x3c9: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3cc:
	/* 0x3cc: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_3d0:
	/* 0x3d0: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_3d3:
	/* 0x3d3: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_3d6:
	/* 0x3d6: jmp    416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x3d6, 0x416, x86_l_416);
x86_l_3d8:
	/* 0x3d8: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3db:
	/* 0x3db: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_3de:
	/* 0x3de: jb     414 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3de, 0x414, x86_l_414);
x86_l_3e0:
	/* 0x3e0: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e3:
	/* 0x3e3: ja     3ea <filter_16ty_range+0x17d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3e3, 0x3ea, x86_l_3ea);
x86_l_3e5:
	/* 0x3e5: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3e8:
	/* 0x3e8: jae    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3e8, 0x374, x86_l_374);
x86_l_3ea:
	/* 0x3ea: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_3ed:
	/* 0x3ed: jb     414 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3ed, 0x414, x86_l_414);
x86_l_3ef:
	/* 0x3ef: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f2:
	/* 0x3f2: ja     3fd <filter_16ty_range+0x190> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3f2, 0x3fd, x86_l_3fd);
x86_l_3f4:
	/* 0x3f4: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3f7:
	/* 0x3f7: jae    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3f7, 0x374, x86_l_374);
x86_l_3fd:
	/* 0x3fd: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_400:
	/* 0x400: jb     414 <filter_16ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x400, 0x414, x86_l_414);
x86_l_402:
	/* 0x402: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_404:
	/* 0x404: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_407:
	/* 0x407: ja     416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x407, 0x416, x86_l_416);
x86_l_409:
	/* 0x409: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_40c:
	/* 0x40c: jae    374 <filter_16ty_range+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x40c, 0x374, x86_l_374);
x86_l_412:
	/* 0x412: jmp    416 <filter_16ty_range+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x412, 0x416, x86_l_416);
x86_l_414:
	/* 0x414: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_416:
	/* 0x416: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_419:
	/* 0x419: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_41c:
	/* 0x41c: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_41f:
	/* 0x41f: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_421:
	/* 0x421: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_424:
	/* 0x424: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_425 */
x86_l_425:
	/* 0x425: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_427:
	/* 0x427: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_428:
	/* 0x428: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_42c:
	/* 0x42c: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_42f:
	/* 0x42f: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_432:
	/* 0x432: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_436:
	/* 0x436: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_43a:
	/* 0x43a: mov    rdi,QWORD PTR [rip+0xe20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_441:
	/* 0x441: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_446:
	/* 0x446: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44b:
	/* 0x44b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d:
	/* 0x44d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_450:
	/* 0x450: je     486 <filter_16ty_map+0x61> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x450, 0x486, x86_l_486);
x86_l_452:
	/* 0x452: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_455:
	/* 0x455: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_459:
	/* 0x459: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45e:
	/* 0x45e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_463:
	/* 0x463: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_468:
	/* 0x468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46a:
	/* 0x46a: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46d:
	/* 0x46d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46f:
	/* 0x46f: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_472:
	/* 0x472: ja     4a0 <filter_16ty_map+0x7b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x472, 0x4a0, x86_l_4a0);
x86_l_474:
	/* 0x474: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_479:
	/* 0x479: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_47c:
	/* 0x47c: jae    490 <filter_16ty_map+0x6b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x47c, 0x490, x86_l_490);
x86_l_47e:
	/* 0x47e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_481:
	/* 0x481: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_484:
	/* 0x484: jmp    4a0 <filter_16ty_map+0x7b> */
	X86_SIM_X86_SUB_JMP(0x484, 0x4a0, x86_l_4a0);
x86_l_486:
	/* 0x486: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_488:
	/* 0x488: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_48c:
	/* 0x48c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_48d:
	/* 0x48d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_48f:
	/* 0x48f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_490:
	/* 0x490: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_495:
	/* 0x495: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_498:
	/* 0x498: jae    4a0 <filter_16ty_map+0x7b> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x498, 0x4a0, x86_l_4a0);
x86_l_49a:
	/* 0x49a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49d:
	/* 0x49d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_4a0:
	/* 0x4a0: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4a3:
	/* 0x4a3: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_4a7:
	/* 0x4a7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4a8:
	/* 0x4a8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1cULL: goto x86_l_1c;
	case 0x42ULL: goto x86_l_42;
	case 0x4dULL: goto x86_l_4d;
	case 0x44dULL: goto x86_l_44d;
	case 0x46aULL: goto x86_l_46a;
	}

}

X86_SIM_LICENSE();
