extern char argfilter_maps;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_usdt_v61_filter_64ty_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: ja     4d <filter_64ty+0x4d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa, 0x4d, x86_l_4d);
x86_l_c:
	/* 0xc: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_11:
	/* 0x11: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_15:
	/* 0x15: jae    22 <filter_64ty+0x22> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x15, 0x22, x86_l_22);
x86_l_17:
	/* 0x17: call   53 <filter_64ty_selector_val> */
	X86_SIM_X86_CALL(x86_l_53, 0x1cULL);
x86_l_1c:
	/* 0x1c: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: jmp    4d8 <filter_64ty_map+0x78> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_22:
	/* 0x22: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_27:
	/* 0x27: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: jb     48 <filter_64ty+0x48> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2b, 0x48, x86_l_48);
x86_l_2d:
	/* 0x2d: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_37:
	/* 0x37: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: jae    4d <filter_64ty+0x4d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3b, 0x4d, x86_l_4d);
x86_l_3d:
	/* 0x3d: call   285 <filter_64ty_range> */
	X86_SIM_X86_CALL(x86_l_285, 0x42ULL);
x86_l_42:
	/* 0x42: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: jmp    4d8 <filter_64ty_map+0x78> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_48:
	/* 0x48: call   460 <filter_64ty_map> */
	X86_SIM_X86_CALL(x86_l_460, 0x4dULL);
x86_l_4d:
	/* 0x4d: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_4e:
	/* 0x4e: jmp    4d8 <filter_64ty_map+0x78> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4d8:
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
	/* 0x5f: ja     d7 <filter_64ty_selector_val+0x84> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x5f, 0xd7, x86_l_d7);
x86_l_61:
	/* 0x61: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_6b:
	/* 0x6b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: jae    72 <filter_64ty_selector_val+0x1f> */
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
	/* 0x7b: jae    93 <filter_64ty_selector_val+0x40> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7b, 0x93, x86_l_93);
x86_l_7d:
	/* 0x7d: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80:
	/* 0x80: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_84:
	/* 0x84: jne    1b5 <filter_64ty_selector_val+0x162> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x84, 0x1b5, x86_l_1b5);
x86_l_8a:
	/* 0x8a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c:
	/* 0x8c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8f:
	/* 0x8f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_92:
	/* 0x92: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_93:
	/* 0x93: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_97:
	/* 0x97: jne    d7 <filter_64ty_selector_val+0x84> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x97, 0xd7, x86_l_d7);
x86_l_99:
	/* 0x99: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c:
	/* 0x9c: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a0:
	/* 0xa0: jne    71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa0, 0x71, x86_l_71);
x86_l_a2:
	/* 0xa2: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a5:
	/* 0xa5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_a8:
	/* 0xa8: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xa8, 0x282, x86_l_282);
x86_l_ae:
	/* 0xae: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b2:
	/* 0xb2: jne    71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb2, 0x71, x86_l_71);
x86_l_b4:
	/* 0xb4: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b7:
	/* 0xb7: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xb7, 0x282, x86_l_282);
x86_l_bd:
	/* 0xbd: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c1:
	/* 0xc1: jne    71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xc1, 0x71, x86_l_71);
x86_l_c3:
	/* 0xc3: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c6:
	/* 0xc6: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0xc6, 0x282, x86_l_282);
x86_l_cc:
	/* 0xcc: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d0:
	/* 0xd0: jne    71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xd0, 0x71, x86_l_71);
x86_l_d2:
	/* 0xd2: jmp    282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JMP(0xd2, 0x282, x86_l_282);
x86_l_d7:
	/* 0xd7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_da:
	/* 0xda: je     14d <filter_64ty_selector_val+0xfa> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xda, 0x14d, x86_l_14d);
x86_l_dc:
	/* 0xdc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_df:
	/* 0xdf: jne    282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xdf, 0x282, x86_l_282);
x86_l_e5:
	/* 0xe5: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e8:
	/* 0xe8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_eb:
	/* 0xeb: ja     245 <filter_64ty_selector_val+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xeb, 0x245, x86_l_245);
x86_l_f1:
	/* 0xf1: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_f6:
	/* 0xf6: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f9:
	/* 0xf9: jae    245 <filter_64ty_selector_val+0x1f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0xf9, 0x245, x86_l_245);
x86_l_ff:
	/* 0xff: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102:
	/* 0x102: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_106:
	/* 0x106: jl     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x106, 0x71, x86_l_71);
x86_l_10c:
	/* 0x10c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f:
	/* 0x10f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_112:
	/* 0x112: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x112, 0x282, x86_l_282);
x86_l_118:
	/* 0x118: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_11c:
	/* 0x11c: jl     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x11c, 0x71, x86_l_71);
x86_l_122:
	/* 0x122: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_125:
	/* 0x125: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x125, 0x282, x86_l_282);
x86_l_12b:
	/* 0x12b: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_12f:
	/* 0x12f: jl     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x12f, 0x71, x86_l_71);
x86_l_135:
	/* 0x135: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_138:
	/* 0x138: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x138, 0x282, x86_l_282);
x86_l_13e:
	/* 0x13e: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_142:
	/* 0x142: jl     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_L, 0x142, 0x71, x86_l_71);
x86_l_148:
	/* 0x148: jmp    282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JMP(0x148, 0x282, x86_l_282);
x86_l_14d:
	/* 0x14d: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_150:
	/* 0x150: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_153:
	/* 0x153: ja     206 <filter_64ty_selector_val+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x153, 0x206, x86_l_206);
x86_l_159:
	/* 0x159: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_15e:
	/* 0x15e: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_161:
	/* 0x161: jae    206 <filter_64ty_selector_val+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x161, 0x206, x86_l_206);
x86_l_167:
	/* 0x167: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a:
	/* 0x16a: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_16e:
	/* 0x16e: jg     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x16e, 0x71, x86_l_71);
x86_l_174:
	/* 0x174: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177:
	/* 0x177: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_17a:
	/* 0x17a: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x17a, 0x282, x86_l_282);
x86_l_180:
	/* 0x180: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_184:
	/* 0x184: jg     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x184, 0x71, x86_l_71);
x86_l_18a:
	/* 0x18a: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_18d:
	/* 0x18d: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x18d, 0x282, x86_l_282);
x86_l_193:
	/* 0x193: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_197:
	/* 0x197: jg     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x197, 0x71, x86_l_71);
x86_l_19d:
	/* 0x19d: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1a0:
	/* 0x1a0: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1a0, 0x282, x86_l_282);
x86_l_1a6:
	/* 0x1a6: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1aa:
	/* 0x1aa: jg     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1aa, 0x71, x86_l_71);
x86_l_1b0:
	/* 0x1b0: jmp    282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JMP(0x1b0, 0x282, x86_l_282);
x86_l_1b5:
	/* 0x1b5: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8:
	/* 0x1b8: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1bb:
	/* 0x1bb: jb     1e5 <filter_64ty_selector_val+0x192> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1bb, 0x1e5, x86_l_1e5);
x86_l_1bd:
	/* 0x1bd: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1c1:
	/* 0x1c1: je     8a <filter_64ty_selector_val+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c1, 0x8a, x86_l_8a);
x86_l_1c7:
	/* 0x1c7: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1ca:
	/* 0x1ca: jb     1e5 <filter_64ty_selector_val+0x192> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ca, 0x1e5, x86_l_1e5);
x86_l_1cc:
	/* 0x1cc: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1d0:
	/* 0x1d0: je     8a <filter_64ty_selector_val+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d0, 0x8a, x86_l_8a);
x86_l_1d6:
	/* 0x1d6: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_1d9:
	/* 0x1d9: jb     1e5 <filter_64ty_selector_val+0x192> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1d9, 0x1e5, x86_l_1e5);
x86_l_1db:
	/* 0x1db: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1df:
	/* 0x1df: je     8a <filter_64ty_selector_val+0x37> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1df, 0x8a, x86_l_8a);
x86_l_1e5:
	/* 0x1e5: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1e8:
	/* 0x1e8: ja     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1e8, 0x282, x86_l_282);
x86_l_1ee:
	/* 0x1ee: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1fa:
	/* 0x1fa: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: jb     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fe, 0x71, x86_l_71);
x86_l_204:
	/* 0x204: jmp    282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JMP(0x204, 0x282, x86_l_282);
x86_l_206:
	/* 0x206: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209:
	/* 0x209: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_20d:
	/* 0x20d: ja     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x20d, 0x71, x86_l_71);
x86_l_213:
	/* 0x213: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_216:
	/* 0x216: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_219:
	/* 0x219: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x219, 0x282, x86_l_282);
x86_l_21b:
	/* 0x21b: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_21f:
	/* 0x21f: ja     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x21f, 0x71, x86_l_71);
x86_l_225:
	/* 0x225: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_228:
	/* 0x228: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x228, 0x282, x86_l_282);
x86_l_22a:
	/* 0x22a: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_22e:
	/* 0x22e: ja     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x22e, 0x71, x86_l_71);
x86_l_234:
	/* 0x234: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_237:
	/* 0x237: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x237, 0x282, x86_l_282);
x86_l_239:
	/* 0x239: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_23d:
	/* 0x23d: ja     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x23d, 0x71, x86_l_71);
x86_l_243:
	/* 0x243: jmp    282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JMP(0x243, 0x282, x86_l_282);
x86_l_245:
	/* 0x245: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248:
	/* 0x248: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_24c:
	/* 0x24c: jb     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x24c, 0x71, x86_l_71);
x86_l_252:
	/* 0x252: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255:
	/* 0x255: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_258:
	/* 0x258: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x258, 0x282, x86_l_282);
x86_l_25a:
	/* 0x25a: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_25e:
	/* 0x25e: jb     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x25e, 0x71, x86_l_71);
x86_l_264:
	/* 0x264: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_267:
	/* 0x267: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x267, 0x282, x86_l_282);
x86_l_269:
	/* 0x269: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_26d:
	/* 0x26d: jb     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x26d, 0x71, x86_l_71);
x86_l_273:
	/* 0x273: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_276:
	/* 0x276: jb     282 <filter_64ty_selector_val+0x22f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x276, 0x282, x86_l_282);
x86_l_278:
	/* 0x278: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_27c:
	/* 0x27c: jb     71 <filter_64ty_selector_val+0x1e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x27c, 0x71, x86_l_71);
x86_l_282:
	/* 0x282: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284:
	/* 0x284: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_285 */
x86_l_285:
	/* 0x285: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_288:
	/* 0x288: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_28b:
	/* 0x28b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_28e:
	/* 0x28e: ja     388 <filter_64ty_range+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x28e, 0x388, x86_l_388);
x86_l_294:
	/* 0x294: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_299:
	/* 0x299: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_29c:
	/* 0x29c: jae    388 <filter_64ty_range+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x29c, 0x388, x86_l_388);
x86_l_2a2:
	/* 0x2a2: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5:
	/* 0x2a5: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_2a8:
	/* 0x2a8: jne    318 <filter_64ty_range+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2a8, 0x318, x86_l_318);
x86_l_2aa:
	/* 0x2aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2af:
	/* 0x2af: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3:
	/* 0x2b3: jg     2bf <filter_64ty_range+0x3a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2b3, 0x2bf, x86_l_2bf);
x86_l_2b5:
	/* 0x2b5: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2b9:
	/* 0x2b9: jle    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2b9, 0x3a1, x86_l_3a1);
x86_l_2bf:
	/* 0x2bf: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c2:
	/* 0x2c2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2c5:
	/* 0x2c5: jb     44f <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2c5, 0x44f, x86_l_44f);
x86_l_2cb:
	/* 0x2cb: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cf:
	/* 0x2cf: jg     2db <filter_64ty_range+0x56> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2cf, 0x2db, x86_l_2db);
x86_l_2d1:
	/* 0x2d1: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2d5:
	/* 0x2d5: jle    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2d5, 0x3a1, x86_l_3a1);
x86_l_2db:
	/* 0x2db: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_2de:
	/* 0x2de: jb     44f <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2de, 0x44f, x86_l_44f);
x86_l_2e4:
	/* 0x2e4: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e8:
	/* 0x2e8: jg     2f4 <filter_64ty_range+0x6f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2e8, 0x2f4, x86_l_2f4);
x86_l_2ea:
	/* 0x2ea: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2ee:
	/* 0x2ee: jle    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2ee, 0x3a1, x86_l_3a1);
x86_l_2f4:
	/* 0x2f4: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_2f7:
	/* 0x2f7: jb     44f <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x2f7, 0x44f, x86_l_44f);
x86_l_2fd:
	/* 0x2fd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ff:
	/* 0x2ff: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_303:
	/* 0x303: jg     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x303, 0x451, x86_l_451);
x86_l_309:
	/* 0x309: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_30d:
	/* 0x30d: jle    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x30d, 0x3a1, x86_l_3a1);
x86_l_313:
	/* 0x313: jmp    451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x313, 0x451, x86_l_451);
x86_l_318:
	/* 0x318: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31b:
	/* 0x31b: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31f:
	/* 0x31f: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_323:
	/* 0x323: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_327:
	/* 0x327: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_32a:
	/* 0x32a: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_32d:
	/* 0x32d: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_330:
	/* 0x330: jb     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x330, 0x451, x86_l_451);
x86_l_336:
	/* 0x336: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33a:
	/* 0x33a: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_33e:
	/* 0x33e: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_342:
	/* 0x342: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_346:
	/* 0x346: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_349:
	/* 0x349: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_34c:
	/* 0x34c: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_34f:
	/* 0x34f: jb     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x34f, 0x451, x86_l_451);
x86_l_355:
	/* 0x355: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_359:
	/* 0x359: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_35d:
	/* 0x35d: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_361:
	/* 0x361: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_365:
	/* 0x365: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_368:
	/* 0x368: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_36b:
	/* 0x36b: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_36e:
	/* 0x36e: jb     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x36e, 0x451, x86_l_451);
x86_l_374:
	/* 0x374: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_378:
	/* 0x378: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_37b:
	/* 0x37b: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_37f:
	/* 0x37f: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_383:
	/* 0x383: jmp    405 <filter_64ty_range+0x180> */
	X86_SIM_X86_SUB_JMP(0x383, 0x405, x86_l_405);
x86_l_388:
	/* 0x388: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b:
	/* 0x38b: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_38e:
	/* 0x38e: jne    3a2 <filter_64ty_range+0x11d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x38e, 0x3a2, x86_l_3a2);
x86_l_390:
	/* 0x390: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_395:
	/* 0x395: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_399:
	/* 0x399: ja     40d <filter_64ty_range+0x188> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x399, 0x40d, x86_l_40d);
x86_l_39b:
	/* 0x39b: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_39f:
	/* 0x39f: ja     40d <filter_64ty_range+0x188> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x39f, 0x40d, x86_l_40d);
x86_l_3a1:
	/* 0x3a1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3a2:
	/* 0x3a2: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a5:
	/* 0x3a5: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a9:
	/* 0x3a9: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_3ad:
	/* 0x3ad: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3b1:
	/* 0x3b1: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_3b4:
	/* 0x3b4: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_3b7:
	/* 0x3b7: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3ba:
	/* 0x3ba: jb     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3ba, 0x451, x86_l_451);
x86_l_3c0:
	/* 0x3c0: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c4:
	/* 0x3c4: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_3c8:
	/* 0x3c8: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3cc:
	/* 0x3cc: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_3d0:
	/* 0x3d0: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_3d3:
	/* 0x3d3: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_3d6:
	/* 0x3d6: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_3d9:
	/* 0x3d9: jb     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3d9, 0x451, x86_l_451);
x86_l_3db:
	/* 0x3db: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3df:
	/* 0x3df: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_3e3:
	/* 0x3e3: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_3e7:
	/* 0x3e7: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_3eb:
	/* 0x3eb: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_3ee:
	/* 0x3ee: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_3f1:
	/* 0x3f1: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_3f4:
	/* 0x3f4: jb     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x3f4, 0x451, x86_l_451);
x86_l_3f6:
	/* 0x3f6: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3fa:
	/* 0x3fa: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_3fd:
	/* 0x3fd: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_401:
	/* 0x401: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_405:
	/* 0x405: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_408:
	/* 0x408: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_40b:
	/* 0x40b: jmp    451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x40b, 0x451, x86_l_451);
x86_l_40d:
	/* 0x40d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_410:
	/* 0x410: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_413:
	/* 0x413: jb     44f <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x413, 0x44f, x86_l_44f);
x86_l_415:
	/* 0x415: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_419:
	/* 0x419: ja     421 <filter_64ty_range+0x19c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x419, 0x421, x86_l_421);
x86_l_41b:
	/* 0x41b: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_41f:
	/* 0x41f: jbe    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x41f, 0x3a1, x86_l_3a1);
x86_l_421:
	/* 0x421: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_424:
	/* 0x424: jb     44f <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x424, 0x44f, x86_l_44f);
x86_l_426:
	/* 0x426: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_42a:
	/* 0x42a: ja     436 <filter_64ty_range+0x1b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x42a, 0x436, x86_l_436);
x86_l_42c:
	/* 0x42c: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_430:
	/* 0x430: jbe    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x430, 0x3a1, x86_l_3a1);
x86_l_436:
	/* 0x436: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_439:
	/* 0x439: jb     44f <filter_64ty_range+0x1ca> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x439, 0x44f, x86_l_44f);
x86_l_43b:
	/* 0x43b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43d:
	/* 0x43d: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_441:
	/* 0x441: ja     451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x441, 0x451, x86_l_451);
x86_l_443:
	/* 0x443: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_447:
	/* 0x447: jbe    3a1 <filter_64ty_range+0x11c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x447, 0x3a1, x86_l_3a1);
x86_l_44d:
	/* 0x44d: jmp    451 <filter_64ty_range+0x1cc> */
	X86_SIM_X86_SUB_JMP(0x44d, 0x451, x86_l_451);
x86_l_44f:
	/* 0x44f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_451:
	/* 0x451: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_454:
	/* 0x454: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_457:
	/* 0x457: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_45a:
	/* 0x45a: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_45c:
	/* 0x45c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_45f:
	/* 0x45f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_460 */
x86_l_460:
	/* 0x460: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_462:
	/* 0x462: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_463:
	/* 0x463: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_467:
	/* 0x467: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_46a:
	/* 0x46a: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_46d:
	/* 0x46d: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_471:
	/* 0x471: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_475:
	/* 0x475: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47a:
	/* 0x47a: mov    rdi,QWORD PTR [rip+0x9a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_481:
	/* 0x481: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_486:
	/* 0x486: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_488:
	/* 0x488: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: je     4b9 <filter_64ty_map+0x59> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x48b, 0x4b9, x86_l_4b9);
x86_l_48d:
	/* 0x48d: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_490:
	/* 0x490: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_495:
	/* 0x495: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_49a:
	/* 0x49a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49f:
	/* 0x49f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4a4:
	/* 0x4a4: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a7:
	/* 0x4a7: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_4aa:
	/* 0x4aa: je     4c3 <filter_64ty_map+0x63> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4aa, 0x4c3, x86_l_4c3);
x86_l_4ac:
	/* 0x4ac: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_4af:
	/* 0x4af: jne    4cb <filter_64ty_map+0x6b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4af, 0x4cb, x86_l_4cb);
x86_l_4b1:
	/* 0x4b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b4:
	/* 0x4b4: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_4b7:
	/* 0x4b7: jmp    4cd <filter_64ty_map+0x6d> */
	X86_SIM_X86_SUB_JMP(0x4b7, 0x4cd, x86_l_4cd);
x86_l_4b9:
	/* 0x4b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bb:
	/* 0x4bb: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_4bf:
	/* 0x4bf: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4c0:
	/* 0x4c0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4c2:
	/* 0x4c2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4c3:
	/* 0x4c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_4c9:
	/* 0x4c9: jmp    4cd <filter_64ty_map+0x6d> */
	X86_SIM_X86_SUB_JMP(0x4c9, 0x4cd, x86_l_4cd);
x86_l_4cb:
	/* 0x4cb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cd:
	/* 0x4cd: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4d0:
	/* 0x4d0: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_4d4:
	/* 0x4d4: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4d5:
	/* 0x4d5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4d7:
	/* 0x4d7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1cULL: goto x86_l_1c;
	case 0x42ULL: goto x86_l_42;
	case 0x4dULL: goto x86_l_4d;
	case 0x488ULL: goto x86_l_488;
	case 0x4a4ULL: goto x86_l_4a4;
	}

}

X86_SIM_LICENSE();
