#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v61_filter_8ty_selector_val_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xc: ja     87 <filter_8ty_selector_val+0x87> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc, 0x87, x86_l_87);
x86_l_e:
	/* 0xe: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_18:
	/* 0x18: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1c:
	/* 0x1c: jae    23 <filter_8ty_selector_val+0x23> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1c, 0x23, x86_l_23);
x86_l_1e:
	/* 0x1e: jmp    226 <filter_8ty_selector_val+0x226> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_23:
	/* 0x23: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_28:
	/* 0x28: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2c:
	/* 0x2c: jae    47 <filter_8ty_selector_val+0x47> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2c, 0x47, x86_l_47);
x86_l_2e:
	/* 0x2e: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34:
	/* 0x34: jne    15d <filter_8ty_selector_val+0x15d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34, 0x15d, x86_l_15d);
x86_l_3a:
	/* 0x3a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c:
	/* 0x3c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3f:
	/* 0x3f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_42:
	/* 0x42: jmp    226 <filter_8ty_selector_val+0x226> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_47:
	/* 0x47: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_4b:
	/* 0x4b: jne    87 <filter_8ty_selector_val+0x87> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b, 0x87, x86_l_87);
x86_l_4d:
	/* 0x4d: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_50:
	/* 0x50: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53:
	/* 0x53: jne    1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x53, 0x1e, x86_l_1e);
x86_l_55:
	/* 0x55: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58:
	/* 0x58: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_5b:
	/* 0x5b: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5b, 0x21f, x86_l_21f);
x86_l_61:
	/* 0x61: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_64:
	/* 0x64: jne    1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x64, 0x1e, x86_l_1e);
x86_l_66:
	/* 0x66: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_69:
	/* 0x69: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x69, 0x21f, x86_l_21f);
x86_l_6f:
	/* 0x6f: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_72:
	/* 0x72: jne    1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x72, 0x1e, x86_l_1e);
x86_l_74:
	/* 0x74: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_77:
	/* 0x77: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x77, 0x21f, x86_l_21f);
x86_l_7d:
	/* 0x7d: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_80:
	/* 0x80: jne    1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x80, 0x1e, x86_l_1e);
x86_l_82:
	/* 0x82: jmp    21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JMP(0x82, 0x21f, x86_l_21f);
x86_l_87:
	/* 0x87: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8a:
	/* 0x8a: je     f9 <filter_8ty_selector_val+0xf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a, 0xf9, x86_l_f9);
x86_l_8c:
	/* 0x8c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8f:
	/* 0x8f: jne    21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8f, 0x21f, x86_l_21f);
x86_l_95:
	/* 0x95: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_98:
	/* 0x98: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_9b:
	/* 0x9b: ja     1e6 <filter_8ty_selector_val+0x1e6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9b, 0x1e6, x86_l_1e6);
x86_l_a1:
	/* 0xa1: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_a6:
	/* 0xa6: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a9:
	/* 0xa9: jae    1e6 <filter_8ty_selector_val+0x1e6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa9, 0x1e6, x86_l_1e6);
x86_l_af:
	/* 0xaf: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b2:
	/* 0xb2: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b5:
	/* 0xb5: jg     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb5, 0x1e, x86_l_1e);
x86_l_bb:
	/* 0xbb: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be:
	/* 0xbe: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_c1:
	/* 0xc1: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc1, 0x21f, x86_l_21f);
x86_l_c7:
	/* 0xc7: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ca:
	/* 0xca: jg     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xca, 0x1e, x86_l_1e);
x86_l_d0:
	/* 0xd0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_d3:
	/* 0xd3: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0xd3, 0x21f, x86_l_21f);
x86_l_d9:
	/* 0xd9: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dc:
	/* 0xdc: jg     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdc, 0x1e, x86_l_1e);
x86_l_e2:
	/* 0xe2: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_e5:
	/* 0xe5: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe5, 0x21f, x86_l_21f);
x86_l_eb:
	/* 0xeb: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_ee:
	/* 0xee: jg     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xee, 0x1e, x86_l_1e);
x86_l_f4:
	/* 0xf4: jmp    21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JMP(0xf4, 0x21f, x86_l_21f);
x86_l_f9:
	/* 0xf9: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fc:
	/* 0xfc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ff:
	/* 0xff: ja     1ab <filter_8ty_selector_val+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_A, 0xff, 0x1ab, x86_l_1ab);
x86_l_105:
	/* 0x105: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_10a:
	/* 0x10a: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_10d:
	/* 0x10d: jae    1ab <filter_8ty_selector_val+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x10d, 0x1ab, x86_l_1ab);
x86_l_113:
	/* 0x113: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_116:
	/* 0x116: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119:
	/* 0x119: jl     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_L, 0x119, 0x1e, x86_l_1e);
x86_l_11f:
	/* 0x11f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122:
	/* 0x122: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_125:
	/* 0x125: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x125, 0x21f, x86_l_21f);
x86_l_12b:
	/* 0x12b: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12e:
	/* 0x12e: jl     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_L, 0x12e, 0x1e, x86_l_1e);
x86_l_134:
	/* 0x134: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_137:
	/* 0x137: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x137, 0x21f, x86_l_21f);
x86_l_13d:
	/* 0x13d: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_140:
	/* 0x140: jl     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_L, 0x140, 0x1e, x86_l_1e);
x86_l_146:
	/* 0x146: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_149:
	/* 0x149: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x149, 0x21f, x86_l_21f);
x86_l_14f:
	/* 0x14f: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_152:
	/* 0x152: jl     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_L, 0x152, 0x1e, x86_l_1e);
x86_l_158:
	/* 0x158: jmp    21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JMP(0x158, 0x21f, x86_l_21f);
x86_l_15d:
	/* 0x15d: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_160:
	/* 0x160: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_163:
	/* 0x163: jb     18a <filter_8ty_selector_val+0x18a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x163, 0x18a, x86_l_18a);
x86_l_165:
	/* 0x165: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_168:
	/* 0x168: je     3a <filter_8ty_selector_val+0x3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x168, 0x3a, x86_l_3a);
x86_l_16e:
	/* 0x16e: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_171:
	/* 0x171: jb     18a <filter_8ty_selector_val+0x18a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x171, 0x18a, x86_l_18a);
x86_l_173:
	/* 0x173: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_176:
	/* 0x176: je     3a <filter_8ty_selector_val+0x3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x176, 0x3a, x86_l_3a);
x86_l_17c:
	/* 0x17c: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_17f:
	/* 0x17f: jb     18a <filter_8ty_selector_val+0x18a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x17f, 0x18a, x86_l_18a);
x86_l_181:
	/* 0x181: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_184:
	/* 0x184: je     3a <filter_8ty_selector_val+0x3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x184, 0x3a, x86_l_3a);
x86_l_18a:
	/* 0x18a: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_18d:
	/* 0x18d: ja     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x18d, 0x21f, x86_l_21f);
x86_l_193:
	/* 0x193: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_195:
	/* 0x195: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_19f:
	/* 0x19f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1a3:
	/* 0x1a3: jb     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a3, 0x1e, x86_l_1e);
x86_l_1a9:
	/* 0x1a9: jmp    21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JMP(0x1a9, 0x21f, x86_l_21f);
x86_l_1ab:
	/* 0x1ab: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ae:
	/* 0x1ae: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b1:
	/* 0x1b1: jb     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b1, 0x1e, x86_l_1e);
x86_l_1b7:
	/* 0x1b7: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba:
	/* 0x1ba: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1bd:
	/* 0x1bd: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1bd, 0x21f, x86_l_21f);
x86_l_1bf:
	/* 0x1bf: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1c2:
	/* 0x1c2: jb     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1c2, 0x1e, x86_l_1e);
x86_l_1c8:
	/* 0x1c8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1cb:
	/* 0x1cb: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1cb, 0x21f, x86_l_21f);
x86_l_1cd:
	/* 0x1cd: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d0:
	/* 0x1d0: jb     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d0, 0x1e, x86_l_1e);
x86_l_1d6:
	/* 0x1d6: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d9:
	/* 0x1d9: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d9, 0x21f, x86_l_21f);
x86_l_1db:
	/* 0x1db: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1de:
	/* 0x1de: jb     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1de, 0x1e, x86_l_1e);
x86_l_1e4:
	/* 0x1e4: jmp    21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JMP(0x1e4, 0x21f, x86_l_21f);
x86_l_1e6:
	/* 0x1e6: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e9:
	/* 0x1e9: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec:
	/* 0x1ec: ja     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ec, 0x1e, x86_l_1e);
x86_l_1f2:
	/* 0x1f2: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5:
	/* 0x1f5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1f8:
	/* 0x1f8: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1f8, 0x21f, x86_l_21f);
x86_l_1fa:
	/* 0x1fa: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fd:
	/* 0x1fd: ja     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1fd, 0x1e, x86_l_1e);
x86_l_203:
	/* 0x203: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_206:
	/* 0x206: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x206, 0x21f, x86_l_21f);
x86_l_208:
	/* 0x208: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b:
	/* 0x20b: ja     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x20b, 0x1e, x86_l_1e);
x86_l_211:
	/* 0x211: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_214:
	/* 0x214: jb     21f <filter_8ty_selector_val+0x21f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x214, 0x21f, x86_l_21f);
x86_l_216:
	/* 0x216: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_219:
	/* 0x219: ja     1e <filter_8ty_selector_val+0x1e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x219, 0x1e, x86_l_1e);
x86_l_21f:
	/* 0x21f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_221:
	/* 0x221: jmp    226 <filter_8ty_selector_val+0x226> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_226:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
