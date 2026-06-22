extern char argfilter_maps;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_fentry_v61_filter_32ty_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: ja     4d <filter_32ty+0x4d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa, 0x4d, x86_l_4d);
x86_l_c:
	/* 0xc: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_11:
	/* 0x11: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_15:
	/* 0x15: jae    22 <filter_32ty+0x22> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x15, 0x22, x86_l_22);
x86_l_17:
	/* 0x17: call   53 <filter_32ty_selector_val> */
	X86_SIM_X86_CALL(x86_l_53, 0x1cULL);
x86_l_1c:
	/* 0x1c: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: jmp    4a2 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_22:
	/* 0x22: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_27:
	/* 0x27: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: jb     48 <filter_32ty+0x48> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2b, 0x48, x86_l_48);
x86_l_2d:
	/* 0x2d: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_37:
	/* 0x37: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: jae    4d <filter_32ty+0x4d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3b, 0x4d, x86_l_4d);
x86_l_3d:
	/* 0x3d: call   267 <filter_32ty_range> */
	X86_SIM_X86_CALL(x86_l_267, 0x42ULL);
x86_l_42:
	/* 0x42: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: jmp    4a2 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_48:
	/* 0x48: call   41d <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_41d, 0x4dULL);
x86_l_4d:
	/* 0x4d: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_4e:
	/* 0x4e: jmp    4a2 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4a2:
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
	/* 0x5f: ja     d0 <filter_32ty_selector_val+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x5f, 0xd0, x86_l_d0);
x86_l_61:
	/* 0x61: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_6b:
	/* 0x6b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: jae    72 <filter_32ty_selector_val+0x1f> */
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
	/* 0x7b: jae    91 <filter_32ty_selector_val+0x3e> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7b, 0x91, x86_l_91);
x86_l_7d:
	/* 0x7d: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f:
	/* 0x7f: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_82:
	/* 0x82: jne    1a4 <filter_32ty_selector_val+0x151> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x82, 0x1a4, x86_l_1a4);
x86_l_88:
	/* 0x88: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a:
	/* 0x8a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8d:
	/* 0x8d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_90:
	/* 0x90: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_91:
	/* 0x91: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_95:
	/* 0x95: jne    d0 <filter_32ty_selector_val+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x95, 0xd0, x86_l_d0);
x86_l_97:
	/* 0x97: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99:
	/* 0x99: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c:
	/* 0x9c: jne    71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x9c, 0x71, x86_l_71);
x86_l_9e:
	/* 0x9e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a1:
	/* 0xa1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a4:
	/* 0xa4: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa4, 0x264, x86_l_264);
x86_l_aa:
	/* 0xaa: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ad:
	/* 0xad: jne    71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xad, 0x71, x86_l_71);
x86_l_af:
	/* 0xaf: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b2:
	/* 0xb2: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xb2, 0x264, x86_l_264);
x86_l_b8:
	/* 0xb8: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bb:
	/* 0xbb: jne    71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xbb, 0x71, x86_l_71);
x86_l_bd:
	/* 0xbd: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_c0:
	/* 0xc0: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xc0, 0x264, x86_l_264);
x86_l_c6:
	/* 0xc6: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_c9:
	/* 0xc9: jne    71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xc9, 0x71, x86_l_71);
x86_l_cb:
	/* 0xcb: jmp    264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JMP(0xcb, 0x264, x86_l_264);
x86_l_d0:
	/* 0xd0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d3:
	/* 0xd3: je     141 <filter_32ty_selector_val+0xee> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd3, 0x141, x86_l_141);
x86_l_d5:
	/* 0xd5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d8:
	/* 0xd8: jne    264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd8, 0x264, x86_l_264);
x86_l_de:
	/* 0xde: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e1:
	/* 0xe1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e4:
	/* 0xe4: ja     22c <filter_32ty_selector_val+0x1d9> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xe4, 0x22c, x86_l_22c);
x86_l_ea:
	/* 0xea: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_ef:
	/* 0xef: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f2:
	/* 0xf2: jae    22c <filter_32ty_selector_val+0x1d9> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xf2, 0x22c, x86_l_22c);
x86_l_f8:
	/* 0xf8: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa:
	/* 0xfa: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_fd:
	/* 0xfd: jl     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0xfd, 0x71, x86_l_71);
x86_l_103:
	/* 0x103: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_106:
	/* 0x106: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_109:
	/* 0x109: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x109, 0x264, x86_l_264);
x86_l_10f:
	/* 0x10f: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_112:
	/* 0x112: jl     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x112, 0x71, x86_l_71);
x86_l_118:
	/* 0x118: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_11b:
	/* 0x11b: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x11b, 0x264, x86_l_264);
x86_l_121:
	/* 0x121: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_124:
	/* 0x124: jl     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x124, 0x71, x86_l_71);
x86_l_12a:
	/* 0x12a: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_12d:
	/* 0x12d: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x12d, 0x264, x86_l_264);
x86_l_133:
	/* 0x133: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_136:
	/* 0x136: jl     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x136, 0x71, x86_l_71);
x86_l_13c:
	/* 0x13c: jmp    264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JMP(0x13c, 0x264, x86_l_264);
x86_l_141:
	/* 0x141: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_144:
	/* 0x144: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_147:
	/* 0x147: ja     1f2 <filter_32ty_selector_val+0x19f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x147, 0x1f2, x86_l_1f2);
x86_l_14d:
	/* 0x14d: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_152:
	/* 0x152: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_155:
	/* 0x155: jae    1f2 <filter_32ty_selector_val+0x19f> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x155, 0x1f2, x86_l_1f2);
x86_l_15b:
	/* 0x15b: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d:
	/* 0x15d: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_160:
	/* 0x160: jg     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x160, 0x71, x86_l_71);
x86_l_166:
	/* 0x166: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_169:
	/* 0x169: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_16c:
	/* 0x16c: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x16c, 0x264, x86_l_264);
x86_l_172:
	/* 0x172: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_175:
	/* 0x175: jg     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x175, 0x71, x86_l_71);
x86_l_17b:
	/* 0x17b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_17e:
	/* 0x17e: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17e, 0x264, x86_l_264);
x86_l_184:
	/* 0x184: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_187:
	/* 0x187: jg     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x187, 0x71, x86_l_71);
x86_l_18d:
	/* 0x18d: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_190:
	/* 0x190: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x190, 0x264, x86_l_264);
x86_l_196:
	/* 0x196: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_199:
	/* 0x199: jg     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x199, 0x71, x86_l_71);
x86_l_19f:
	/* 0x19f: jmp    264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JMP(0x19f, 0x264, x86_l_264);
x86_l_1a4:
	/* 0x1a4: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7:
	/* 0x1a7: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1aa:
	/* 0x1aa: jb     1d1 <filter_32ty_selector_val+0x17e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1aa, 0x1d1, x86_l_1d1);
x86_l_1ac:
	/* 0x1ac: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1af:
	/* 0x1af: je     88 <filter_32ty_selector_val+0x35> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1af, 0x88, x86_l_88);
x86_l_1b5:
	/* 0x1b5: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1b8:
	/* 0x1b8: jb     1d1 <filter_32ty_selector_val+0x17e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b8, 0x1d1, x86_l_1d1);
x86_l_1ba:
	/* 0x1ba: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1bd:
	/* 0x1bd: je     88 <filter_32ty_selector_val+0x35> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1bd, 0x88, x86_l_88);
x86_l_1c3:
	/* 0x1c3: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1c6:
	/* 0x1c6: jb     1d1 <filter_32ty_selector_val+0x17e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c6, 0x1d1, x86_l_1d1);
x86_l_1c8:
	/* 0x1c8: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1cb:
	/* 0x1cb: je     88 <filter_32ty_selector_val+0x35> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cb, 0x88, x86_l_88);
x86_l_1d1:
	/* 0x1d1: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1d4:
	/* 0x1d4: ja     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1d4, 0x264, x86_l_264);
x86_l_1da:
	/* 0x1da: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1dc:
	/* 0x1dc: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1e6:
	/* 0x1e6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1ea:
	/* 0x1ea: jb     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ea, 0x71, x86_l_71);
x86_l_1f0:
	/* 0x1f0: jmp    264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JMP(0x1f0, 0x264, x86_l_264);
x86_l_1f2:
	/* 0x1f2: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4:
	/* 0x1f4: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1f7:
	/* 0x1f7: ja     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1f7, 0x71, x86_l_71);
x86_l_1fd:
	/* 0x1fd: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_200:
	/* 0x200: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_203:
	/* 0x203: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x203, 0x264, x86_l_264);
x86_l_205:
	/* 0x205: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_208:
	/* 0x208: ja     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x208, 0x71, x86_l_71);
x86_l_20e:
	/* 0x20e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_211:
	/* 0x211: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x211, 0x264, x86_l_264);
x86_l_213:
	/* 0x213: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_216:
	/* 0x216: ja     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x216, 0x71, x86_l_71);
x86_l_21c:
	/* 0x21c: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_21f:
	/* 0x21f: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x21f, 0x264, x86_l_264);
x86_l_221:
	/* 0x221: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_224:
	/* 0x224: ja     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x224, 0x71, x86_l_71);
x86_l_22a:
	/* 0x22a: jmp    264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JMP(0x22a, 0x264, x86_l_264);
x86_l_22c:
	/* 0x22c: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e:
	/* 0x22e: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_231:
	/* 0x231: jb     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x231, 0x71, x86_l_71);
x86_l_237:
	/* 0x237: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a:
	/* 0x23a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_23d:
	/* 0x23d: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x23d, 0x264, x86_l_264);
x86_l_23f:
	/* 0x23f: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_242:
	/* 0x242: jb     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x242, 0x71, x86_l_71);
x86_l_248:
	/* 0x248: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_24b:
	/* 0x24b: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x24b, 0x264, x86_l_264);
x86_l_24d:
	/* 0x24d: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_250:
	/* 0x250: jb     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x250, 0x71, x86_l_71);
x86_l_256:
	/* 0x256: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_259:
	/* 0x259: jb     264 <filter_32ty_selector_val+0x211> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x259, 0x264, x86_l_264);
x86_l_25b:
	/* 0x25b: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_25e:
	/* 0x25e: jb     71 <filter_32ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x25e, 0x71, x86_l_71);
x86_l_264:
	/* 0x264: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266:
	/* 0x266: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_267 */
x86_l_267:
	/* 0x267: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26a:
	/* 0x26a: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_26d:
	/* 0x26d: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_270:
	/* 0x270: ja     356 <filter_32ty_range+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x270, 0x356, x86_l_356);
x86_l_276:
	/* 0x276: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_27b:
	/* 0x27b: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_27e:
	/* 0x27e: jae    356 <filter_32ty_range+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x27e, 0x356, x86_l_356);
x86_l_284:
	/* 0x284: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286:
	/* 0x286: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_289:
	/* 0x289: jne    2f1 <filter_32ty_range+0x8a> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x289, 0x2f1, x86_l_2f1);
x86_l_28b:
	/* 0x28b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_290:
	/* 0x290: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_293:
	/* 0x293: jg     29e <filter_32ty_range+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x293, 0x29e, x86_l_29e);
x86_l_295:
	/* 0x295: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_298:
	/* 0x298: jle    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x298, 0x36c, x86_l_36c);
x86_l_29e:
	/* 0x29e: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a1:
	/* 0x2a1: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2a4:
	/* 0x2a4: jb     40c <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2a4, 0x40c, x86_l_40c);
x86_l_2aa:
	/* 0x2aa: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ad:
	/* 0x2ad: jg     2b8 <filter_32ty_range+0x51> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2ad, 0x2b8, x86_l_2b8);
x86_l_2af:
	/* 0x2af: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_2b2:
	/* 0x2b2: jle    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2b2, 0x36c, x86_l_36c);
x86_l_2b8:
	/* 0x2b8: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2bb:
	/* 0x2bb: jb     40c <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2bb, 0x40c, x86_l_40c);
x86_l_2c1:
	/* 0x2c1: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c4:
	/* 0x2c4: jg     2cf <filter_32ty_range+0x68> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2c4, 0x2cf, x86_l_2cf);
x86_l_2c6:
	/* 0x2c6: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2c9:
	/* 0x2c9: jle    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2c9, 0x36c, x86_l_36c);
x86_l_2cf:
	/* 0x2cf: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2d2:
	/* 0x2d2: jb     40c <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2d2, 0x40c, x86_l_40c);
x86_l_2d8:
	/* 0x2d8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2da:
	/* 0x2da: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2dd:
	/* 0x2dd: jg     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2dd, 0x40e, x86_l_40e);
x86_l_2e3:
	/* 0x2e3: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_2e6:
	/* 0x2e6: jle    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2e6, 0x36c, x86_l_36c);
x86_l_2ec:
	/* 0x2ec: jmp    40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x2ec, 0x40e, x86_l_40e);
x86_l_2f1:
	/* 0x2f1: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4:
	/* 0x2f4: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7:
	/* 0x2f7: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2fb:
	/* 0x2fb: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_2fe:
	/* 0x2fe: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_301:
	/* 0x301: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_304:
	/* 0x304: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_307:
	/* 0x307: jb     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x307, 0x40e, x86_l_40e);
x86_l_30d:
	/* 0x30d: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_310:
	/* 0x310: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_314:
	/* 0x314: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_317:
	/* 0x317: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_31b:
	/* 0x31b: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_31e:
	/* 0x31e: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_321:
	/* 0x321: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_324:
	/* 0x324: jb     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x324, 0x40e, x86_l_40e);
x86_l_32a:
	/* 0x32a: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32d:
	/* 0x32d: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_331:
	/* 0x331: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_334:
	/* 0x334: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_338:
	/* 0x338: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_33b:
	/* 0x33b: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_33e:
	/* 0x33e: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_341:
	/* 0x341: jb     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x341, 0x40e, x86_l_40e);
x86_l_347:
	/* 0x347: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34a:
	/* 0x34a: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_34d:
	/* 0x34d: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_350:
	/* 0x350: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_354:
	/* 0x354: jmp    3c8 <filter_32ty_range+0x161> */
	X86_SIM_X86_SUB_JMP(0x354, 0x3c8, x86_l_3c8);
x86_l_356:
	/* 0x356: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_358:
	/* 0x358: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_35b:
	/* 0x35b: jne    36d <filter_32ty_range+0x106> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x35b, 0x36d, x86_l_36d);
x86_l_35d:
	/* 0x35d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_362:
	/* 0x362: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_365:
	/* 0x365: ja     3d0 <filter_32ty_range+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x365, 0x3d0, x86_l_3d0);
x86_l_367:
	/* 0x367: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_36a:
	/* 0x36a: ja     3d0 <filter_32ty_range+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x36a, 0x3d0, x86_l_3d0);
x86_l_36c:
	/* 0x36c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_36d:
	/* 0x36d: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_370:
	/* 0x370: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_373:
	/* 0x373: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_377:
	/* 0x377: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_37a:
	/* 0x37a: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_37d:
	/* 0x37d: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_380:
	/* 0x380: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_383:
	/* 0x383: jb     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x383, 0x40e, x86_l_40e);
x86_l_389:
	/* 0x389: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38c:
	/* 0x38c: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_390:
	/* 0x390: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_393:
	/* 0x393: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_397:
	/* 0x397: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_39a:
	/* 0x39a: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_39d:
	/* 0x39d: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3a0:
	/* 0x3a0: jb     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3a0, 0x40e, x86_l_40e);
x86_l_3a2:
	/* 0x3a2: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a5:
	/* 0x3a5: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_3a9:
	/* 0x3a9: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_3ac:
	/* 0x3ac: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_3b0:
	/* 0x3b0: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_3b3:
	/* 0x3b3: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_3b6:
	/* 0x3b6: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_3b9:
	/* 0x3b9: jb     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3b9, 0x40e, x86_l_40e);
x86_l_3bb:
	/* 0x3bb: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3be:
	/* 0x3be: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_3c1:
	/* 0x3c1: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_3c4:
	/* 0x3c4: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_3c8:
	/* 0x3c8: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_3cb:
	/* 0x3cb: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_3ce:
	/* 0x3ce: jmp    40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x3ce, 0x40e, x86_l_40e);
x86_l_3d0:
	/* 0x3d0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d3:
	/* 0x3d3: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_3d6:
	/* 0x3d6: jb     40c <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3d6, 0x40c, x86_l_40c);
x86_l_3d8:
	/* 0x3d8: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3db:
	/* 0x3db: ja     3e2 <filter_32ty_range+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3db, 0x3e2, x86_l_3e2);
x86_l_3dd:
	/* 0x3dd: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_3e0:
	/* 0x3e0: jbe    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x3e0, 0x36c, x86_l_36c);
x86_l_3e2:
	/* 0x3e2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_3e5:
	/* 0x3e5: jb     40c <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3e5, 0x40c, x86_l_40c);
x86_l_3e7:
	/* 0x3e7: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ea:
	/* 0x3ea: ja     3f5 <filter_32ty_range+0x18e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3ea, 0x3f5, x86_l_3f5);
x86_l_3ec:
	/* 0x3ec: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_3ef:
	/* 0x3ef: jbe    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x3ef, 0x36c, x86_l_36c);
x86_l_3f5:
	/* 0x3f5: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_3f8:
	/* 0x3f8: jb     40c <filter_32ty_range+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3f8, 0x40c, x86_l_40c);
x86_l_3fa:
	/* 0x3fa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc:
	/* 0x3fc: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ff:
	/* 0x3ff: ja     40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3ff, 0x40e, x86_l_40e);
x86_l_401:
	/* 0x401: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_404:
	/* 0x404: jbe    36c <filter_32ty_range+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x404, 0x36c, x86_l_36c);
x86_l_40a:
	/* 0x40a: jmp    40e <filter_32ty_range+0x1a7> */
	X86_SIM_X86_SUB_JMP(0x40a, 0x40e, x86_l_40e);
x86_l_40c:
	/* 0x40c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40e:
	/* 0x40e: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_411:
	/* 0x411: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_414:
	/* 0x414: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_417:
	/* 0x417: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_419:
	/* 0x419: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_41c:
	/* 0x41c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_41d */
x86_l_41d:
	/* 0x41d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_41f:
	/* 0x41f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_420:
	/* 0x420: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_424:
	/* 0x424: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_427:
	/* 0x427: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_42a:
	/* 0x42a: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_42e:
	/* 0x42e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_432:
	/* 0x432: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_437:
	/* 0x437: mov    rdi,QWORD PTR [rip+0xe20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_43e:
	/* 0x43e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_443:
	/* 0x443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_445:
	/* 0x445: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_448:
	/* 0x448: je     47d <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x448, 0x47d, x86_l_47d);
x86_l_44a:
	/* 0x44a: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_452:
	/* 0x452: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_457:
	/* 0x457: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45c:
	/* 0x45c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_45f:
	/* 0x45f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_461:
	/* 0x461: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_464:
	/* 0x464: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_466:
	/* 0x466: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_469:
	/* 0x469: ja     497 <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x469, 0x497, x86_l_497);
x86_l_46b:
	/* 0x46b: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_470:
	/* 0x470: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_473:
	/* 0x473: jae    487 <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x473, 0x487, x86_l_487);
x86_l_475:
	/* 0x475: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_478:
	/* 0x478: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_47b:
	/* 0x47b: jmp    497 <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x47b, 0x497, x86_l_497);
x86_l_47d:
	/* 0x47d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47f:
	/* 0x47f: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_483:
	/* 0x483: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_486:
	/* 0x486: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_487:
	/* 0x487: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_48c:
	/* 0x48c: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_48f:
	/* 0x48f: jae    497 <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x48f, 0x497, x86_l_497);
x86_l_491:
	/* 0x491: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_497:
	/* 0x497: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_49a:
	/* 0x49a: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_49e:
	/* 0x49e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_49f:
	/* 0x49f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4a1:
	/* 0x4a1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1cULL: goto x86_l_1c;
	case 0x42ULL: goto x86_l_42;
	case 0x4dULL: goto x86_l_4d;
	case 0x445ULL: goto x86_l_445;
	case 0x461ULL: goto x86_l_461;
	}

}

X86_SIM_LICENSE();
