#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_v61_write_reg_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: rorx   eax,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_6:
	/* 0x6: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_9:
	/* 0x9: jle    62 <write_reg+0x62> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x9, 0x62, x86_l_62);
x86_l_b:
	/* 0xb: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_e:
	/* 0xe: jle    ac <write_reg+0xac> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xe, 0xac, x86_l_ac);
x86_l_14:
	/* 0x14: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_17:
	/* 0x17: jle    1d7 <write_reg+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x17, 0x1d7, x86_l_1d7);
x86_l_1d:
	/* 0x1d: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_20:
	/* 0x20: je     323 <write_reg+0x323> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20, 0x323, x86_l_323);
x86_l_26:
	/* 0x26: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_29:
	/* 0x29: je     25e <write_reg+0x25e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29, 0x25e, x86_l_25e);
x86_l_2f:
	/* 0x2f: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_32:
	/* 0x32: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x32, 0x5fb, x86_l_5fb);
x86_l_38:
	/* 0x38: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3b:
	/* 0x3b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3e:
	/* 0x3e: jg     49c <write_reg+0x49c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3e, 0x49c, x86_l_49c);
x86_l_44:
	/* 0x44: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47:
	/* 0x47: je     5f5 <write_reg+0x5f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47, 0x5f5, x86_l_5f5);
x86_l_4d:
	/* 0x4d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_50:
	/* 0x50: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50, 0x5fb, x86_l_5fb);
x86_l_56:
	/* 0x56: mov    WORD PTR [rdi+0x98],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5d:
	/* 0x5d: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_62:
	/* 0x62: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_65:
	/* 0x65: jg     ea <write_reg+0xea> */
	X86_SIM_X86_JCC(X86_CC_G, 0x65, 0xea, x86_l_ea);
x86_l_6b:
	/* 0x6b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e:
	/* 0x6e: jg     165 <write_reg+0x165> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e, 0x165, x86_l_165);
x86_l_74:
	/* 0x74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_76:
	/* 0x76: je     288 <write_reg+0x288> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x288, x86_l_288);
x86_l_7c:
	/* 0x7c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f:
	/* 0x7f: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7f, 0x5fb, x86_l_5fb);
x86_l_85:
	/* 0x85: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_88:
	/* 0x88: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8b:
	/* 0x8b: jg     4ba <write_reg+0x4ba> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8b, 0x4ba, x86_l_4ba);
x86_l_91:
	/* 0x91: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_94:
	/* 0x94: je     60b <write_reg+0x60b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94, 0x60b, x86_l_60b);
x86_l_9a:
	/* 0x9a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9d:
	/* 0x9d: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9d, 0x5fb, x86_l_5fb);
x86_l_a3:
	/* 0xa3: mov    WORD PTR [rdi+0x8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a7:
	/* 0xa7: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ac:
	/* 0xac: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_af:
	/* 0xaf: jg     12c <write_reg+0x12c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xaf, 0x12c, x86_l_12c);
x86_l_b1:
	/* 0xb1: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_b4:
	/* 0xb4: je     210 <write_reg+0x210> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb4, 0x210, x86_l_210);
x86_l_ba:
	/* 0xba: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_bd:
	/* 0xbd: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbd, 0x5fb, x86_l_5fb);
x86_l_c3:
	/* 0xc3: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c6:
	/* 0xc6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c9:
	/* 0xc9: jg     3a7 <write_reg+0x3a7> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc9, 0x3a7, x86_l_3a7);
x86_l_cf:
	/* 0xcf: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d2:
	/* 0xd2: je     561 <write_reg+0x561> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2, 0x561, x86_l_561);
x86_l_d8:
	/* 0xd8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_db:
	/* 0xdb: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdb, 0x5fb, x86_l_5fb);
x86_l_e1:
	/* 0xe1: mov    WORD PTR [rdi+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e5:
	/* 0xe5: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ea:
	/* 0xea: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_ed:
	/* 0xed: jg     19e <write_reg+0x19e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xed, 0x19e, x86_l_19e);
x86_l_f3:
	/* 0xf3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f6:
	/* 0xf6: je     2ae <write_reg+0x2ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6, 0x2ae, x86_l_2ae);
x86_l_fc:
	/* 0xfc: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_ff:
	/* 0xff: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff, 0x5fb, x86_l_5fb);
x86_l_105:
	/* 0x105: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_108:
	/* 0x108: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_10b:
	/* 0x10b: jg     4d5 <write_reg+0x4d5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x10b, 0x4d5, x86_l_4d5);
x86_l_111:
	/* 0x111: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114:
	/* 0x114: je     613 <write_reg+0x613> */
	X86_SIM_X86_JCC(X86_CC_E, 0x114, 0x613, x86_l_613);
x86_l_11a:
	/* 0x11a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11d:
	/* 0x11d: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d, 0x5fb, x86_l_5fb);
x86_l_123:
	/* 0x123: mov    WORD PTR [rdi+0x28],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_127:
	/* 0x127: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_12c:
	/* 0x12c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_12f:
	/* 0x12f: je     237 <write_reg+0x237> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f, 0x237, x86_l_237);
x86_l_135:
	/* 0x135: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_138:
	/* 0x138: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x138, 0x5fb, x86_l_5fb);
x86_l_13e:
	/* 0x13e: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_141:
	/* 0x141: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_144:
	/* 0x144: jg     3c2 <write_reg+0x3c2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x144, 0x3c2, x86_l_3c2);
x86_l_14a:
	/* 0x14a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d:
	/* 0x14d: je     569 <write_reg+0x569> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14d, 0x569, x86_l_569);
x86_l_153:
	/* 0x153: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_156:
	/* 0x156: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x156, 0x5fb, x86_l_5fb);
x86_l_15c:
	/* 0x15c: mov    WORD PTR [rdi+0x58],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_160:
	/* 0x160: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_165:
	/* 0x165: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_168:
	/* 0x168: je     2d5 <write_reg+0x2d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x168, 0x2d5, x86_l_2d5);
x86_l_16e:
	/* 0x16e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_171:
	/* 0x171: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x171, 0x5fb, x86_l_5fb);
x86_l_177:
	/* 0x177: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_17a:
	/* 0x17a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17d:
	/* 0x17d: jg     4f0 <write_reg+0x4f0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17d, 0x4f0, x86_l_4f0);
x86_l_183:
	/* 0x183: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_186:
	/* 0x186: je     61b <write_reg+0x61b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x186, 0x61b, x86_l_61b);
x86_l_18c:
	/* 0x18c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18f:
	/* 0x18f: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18f, 0x5fb, x86_l_5fb);
x86_l_195:
	/* 0x195: mov    WORD PTR [rdi+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_199:
	/* 0x199: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_19e:
	/* 0x19e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1a1:
	/* 0x1a1: je     2fc <write_reg+0x2fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a1, 0x2fc, x86_l_2fc);
x86_l_1a7:
	/* 0x1a7: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1aa:
	/* 0x1aa: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1aa, 0x5fb, x86_l_5fb);
x86_l_1b0:
	/* 0x1b0: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b3:
	/* 0x1b3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1b6:
	/* 0x1b6: jg     50b <write_reg+0x50b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1b6, 0x50b, x86_l_50b);
x86_l_1bc:
	/* 0x1bc: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bf:
	/* 0x1bf: je     623 <write_reg+0x623> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf, 0x623, x86_l_623);
x86_l_1c5:
	/* 0x1c5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c8:
	/* 0x1c8: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c8, 0x5fb, x86_l_5fb);
x86_l_1ce:
	/* 0x1ce: mov    WORD PTR [rdi+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d2:
	/* 0x1d2: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1d7:
	/* 0x1d7: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1da:
	/* 0x1da: je     34a <write_reg+0x34a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1da, 0x34a, x86_l_34a);
x86_l_1e0:
	/* 0x1e0: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1e3:
	/* 0x1e3: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e3, 0x5fb, x86_l_5fb);
x86_l_1e9:
	/* 0x1e9: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ec:
	/* 0x1ec: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1ef:
	/* 0x1ef: jg     526 <write_reg+0x526> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1ef, 0x526, x86_l_526);
x86_l_1f5:
	/* 0x1f5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f8:
	/* 0x1f8: je     64b <write_reg+0x64b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f8, 0x64b, x86_l_64b);
x86_l_1fe:
	/* 0x1fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_201:
	/* 0x201: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x201, 0x5fb, x86_l_5fb);
x86_l_207:
	/* 0x207: mov    WORD PTR [rdi+0x68],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20b:
	/* 0x20b: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_210:
	/* 0x210: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_213:
	/* 0x213: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_216:
	/* 0x216: jg     371 <write_reg+0x371> */
	X86_SIM_X86_JCC(X86_CC_G, 0x216, 0x371, x86_l_371);
x86_l_21c:
	/* 0x21c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21f:
	/* 0x21f: je     541 <write_reg+0x541> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21f, 0x541, x86_l_541);
x86_l_225:
	/* 0x225: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_228:
	/* 0x228: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x228, 0x5fb, x86_l_5fb);
x86_l_22e:
	/* 0x22e: mov    WORD PTR [rdi+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_232:
	/* 0x232: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_237:
	/* 0x237: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23a:
	/* 0x23a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_23d:
	/* 0x23d: jg     38c <write_reg+0x38c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x23d, 0x38c, x86_l_38c);
x86_l_243:
	/* 0x243: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_246:
	/* 0x246: je     549 <write_reg+0x549> */
	X86_SIM_X86_JCC(X86_CC_E, 0x246, 0x549, x86_l_549);
x86_l_24c:
	/* 0x24c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24f:
	/* 0x24f: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24f, 0x5fb, x86_l_5fb);
x86_l_255:
	/* 0x255: mov    WORD PTR [rdi+0x50],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_259:
	/* 0x259: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_25e:
	/* 0x25e: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_261:
	/* 0x261: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_264:
	/* 0x264: jg     3dd <write_reg+0x3dd> */
	X86_SIM_X86_JCC(X86_CC_G, 0x264, 0x3dd, x86_l_3dd);
x86_l_26a:
	/* 0x26a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d:
	/* 0x26d: je     581 <write_reg+0x581> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26d, 0x581, x86_l_581);
x86_l_273:
	/* 0x273: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_276:
	/* 0x276: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x276, 0x5fb, x86_l_5fb);
x86_l_27c:
	/* 0x27c: mov    WORD PTR [rdi+0x80],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_283:
	/* 0x283: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_288:
	/* 0x288: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_28b:
	/* 0x28b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28e:
	/* 0x28e: jg     3fb <write_reg+0x3fb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x28e, 0x3fb, x86_l_3fb);
x86_l_294:
	/* 0x294: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_297:
	/* 0x297: je     597 <write_reg+0x597> */
	X86_SIM_X86_JCC(X86_CC_E, 0x297, 0x597, x86_l_597);
x86_l_29d:
	/* 0x29d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a0:
	/* 0x2a0: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a0, 0x5fb, x86_l_5fb);
x86_l_2a6:
	/* 0x2a6: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9:
	/* 0x2a9: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2ae:
	/* 0x2ae: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b1:
	/* 0x2b1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2b4:
	/* 0x2b4: jg     415 <write_reg+0x415> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2b4, 0x415, x86_l_415);
x86_l_2ba:
	/* 0x2ba: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd:
	/* 0x2bd: je     59e <write_reg+0x59e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bd, 0x59e, x86_l_59e);
x86_l_2c3:
	/* 0x2c3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c6:
	/* 0x2c6: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c6, 0x5fb, x86_l_5fb);
x86_l_2cc:
	/* 0x2cc: mov    WORD PTR [rdi+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d0:
	/* 0x2d0: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2d5:
	/* 0x2d5: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d8:
	/* 0x2d8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2db:
	/* 0x2db: jg     430 <write_reg+0x430> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2db, 0x430, x86_l_430);
x86_l_2e1:
	/* 0x2e1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e4:
	/* 0x2e4: je     5a6 <write_reg+0x5a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e4, 0x5a6, x86_l_5a6);
x86_l_2ea:
	/* 0x2ea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ed:
	/* 0x2ed: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ed, 0x5fb, x86_l_5fb);
x86_l_2f3:
	/* 0x2f3: mov    WORD PTR [rdi+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7:
	/* 0x2f7: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2fc:
	/* 0x2fc: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ff:
	/* 0x2ff: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_302:
	/* 0x302: jg     44b <write_reg+0x44b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x302, 0x44b, x86_l_44b);
x86_l_308:
	/* 0x308: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30b:
	/* 0x30b: je     5ae <write_reg+0x5ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30b, 0x5ae, x86_l_5ae);
x86_l_311:
	/* 0x311: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_314:
	/* 0x314: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x314, 0x5fb, x86_l_5fb);
x86_l_31a:
	/* 0x31a: mov    WORD PTR [rdi+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31e:
	/* 0x31e: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_323:
	/* 0x323: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_326:
	/* 0x326: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_329:
	/* 0x329: jg     466 <write_reg+0x466> */
	X86_SIM_X86_JCC(X86_CC_G, 0x329, 0x466, x86_l_466);
x86_l_32f:
	/* 0x32f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_332:
	/* 0x332: je     5d5 <write_reg+0x5d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x332, 0x5d5, x86_l_5d5);
x86_l_338:
	/* 0x338: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33b:
	/* 0x33b: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33b, 0x5fb, x86_l_5fb);
x86_l_341:
	/* 0x341: mov    WORD PTR [rdi+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_345:
	/* 0x345: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_34a:
	/* 0x34a: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34d:
	/* 0x34d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_350:
	/* 0x350: jg     481 <write_reg+0x481> */
	X86_SIM_X86_JCC(X86_CC_G, 0x350, 0x481, x86_l_481);
x86_l_356:
	/* 0x356: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_359:
	/* 0x359: je     5e5 <write_reg+0x5e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x359, 0x5e5, x86_l_5e5);
x86_l_35f:
	/* 0x35f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_362:
	/* 0x362: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x362, 0x5fb, x86_l_5fb);
x86_l_368:
	/* 0x368: mov    WORD PTR [rdi+0x60],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_36c:
	/* 0x36c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_371:
	/* 0x371: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_374:
	/* 0x374: je     551 <write_reg+0x551> */
	X86_SIM_X86_JCC(X86_CC_E, 0x374, 0x551, x86_l_551);
x86_l_37a:
	/* 0x37a: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_37d:
	/* 0x37d: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37d, 0x5fb, x86_l_5fb);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rdi+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_387:
	/* 0x387: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_38c:
	/* 0x38c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38f:
	/* 0x38f: je     559 <write_reg+0x559> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38f, 0x559, x86_l_559);
x86_l_395:
	/* 0x395: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_398:
	/* 0x398: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x398, 0x5fb, x86_l_5fb);
x86_l_39e:
	/* 0x39e: mov    QWORD PTR [rdi+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3a2:
	/* 0x3a2: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3a7:
	/* 0x3a7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3aa:
	/* 0x3aa: je     571 <write_reg+0x571> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3aa, 0x571, x86_l_571);
x86_l_3b0:
	/* 0x3b0: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3b3:
	/* 0x3b3: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b3, 0x5fb, x86_l_5fb);
x86_l_3b9:
	/* 0x3b9: mov    QWORD PTR [rdi+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3bd:
	/* 0x3bd: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3c2:
	/* 0x3c2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c5:
	/* 0x3c5: je     579 <write_reg+0x579> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c5, 0x579, x86_l_579);
x86_l_3cb:
	/* 0x3cb: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3ce:
	/* 0x3ce: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ce, 0x5fb, x86_l_5fb);
x86_l_3d4:
	/* 0x3d4: mov    QWORD PTR [rdi+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d8:
	/* 0x3d8: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3dd:
	/* 0x3dd: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e0:
	/* 0x3e0: je     58c <write_reg+0x58c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e0, 0x58c, x86_l_58c);
x86_l_3e6:
	/* 0x3e6: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3e9:
	/* 0x3e9: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3e9, 0x5fb, x86_l_5fb);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [rdi+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f6:
	/* 0x3f6: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3fb:
	/* 0x3fb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fe:
	/* 0x3fe: je     5b6 <write_reg+0x5b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fe, 0x5b6, x86_l_5b6);
x86_l_404:
	/* 0x404: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_407:
	/* 0x407: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x407, 0x5fb, x86_l_5fb);
x86_l_40d:
	/* 0x40d: mov    QWORD PTR [rdi],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_410:
	/* 0x410: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_415:
	/* 0x415: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_418:
	/* 0x418: je     5bd <write_reg+0x5bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x418, 0x5bd, x86_l_5bd);
x86_l_41e:
	/* 0x41e: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_421:
	/* 0x421: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x421, 0x5fb, x86_l_5fb);
x86_l_427:
	/* 0x427: mov    QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42b:
	/* 0x42b: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_430:
	/* 0x430: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_433:
	/* 0x433: je     5c5 <write_reg+0x5c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x433, 0x5c5, x86_l_5c5);
x86_l_439:
	/* 0x439: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_43c:
	/* 0x43c: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43c, 0x5fb, x86_l_5fb);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_446:
	/* 0x446: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_44b:
	/* 0x44b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44e:
	/* 0x44e: je     5cd <write_reg+0x5cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44e, 0x5cd, x86_l_5cd);
x86_l_454:
	/* 0x454: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_457:
	/* 0x457: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x457, 0x5fb, x86_l_5fb);
x86_l_45d:
	/* 0x45d: mov    QWORD PTR [rdi+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_461:
	/* 0x461: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_466:
	/* 0x466: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_469:
	/* 0x469: je     5dd <write_reg+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x469, 0x5dd, x86_l_5dd);
x86_l_46f:
	/* 0x46f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_472:
	/* 0x472: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x472, 0x5fb, x86_l_5fb);
x86_l_478:
	/* 0x478: mov    QWORD PTR [rdi+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_47c:
	/* 0x47c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_481:
	/* 0x481: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_484:
	/* 0x484: je     5ed <write_reg+0x5ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x484, 0x5ed, x86_l_5ed);
x86_l_48a:
	/* 0x48a: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_48d:
	/* 0x48d: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48d, 0x5fb, x86_l_5fb);
x86_l_493:
	/* 0x493: mov    QWORD PTR [rdi+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_497:
	/* 0x497: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_49c:
	/* 0x49c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49f:
	/* 0x49f: je     600 <write_reg+0x600> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49f, 0x600, x86_l_600);
x86_l_4a5:
	/* 0x4a5: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4a8:
	/* 0x4a8: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a8, 0x5fb, x86_l_5fb);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rdi+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4b5:
	/* 0x4b5: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4ba:
	/* 0x4ba: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4bd:
	/* 0x4bd: je     62b <write_reg+0x62b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bd, 0x62b, x86_l_62b);
x86_l_4c3:
	/* 0x4c3: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4c6:
	/* 0x4c6: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4c6, 0x5fb, x86_l_5fb);
x86_l_4cc:
	/* 0x4cc: mov    QWORD PTR [rdi+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d0:
	/* 0x4d0: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4d5:
	/* 0x4d5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d8:
	/* 0x4d8: je     633 <write_reg+0x633> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d8, 0x633, x86_l_633);
x86_l_4de:
	/* 0x4de: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4e1:
	/* 0x4e1: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e1, 0x5fb, x86_l_5fb);
x86_l_4e7:
	/* 0x4e7: mov    QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4eb:
	/* 0x4eb: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4f0:
	/* 0x4f0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f3:
	/* 0x4f3: je     63b <write_reg+0x63b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f3, 0x63b, x86_l_63b);
x86_l_4f9:
	/* 0x4f9: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4fc:
	/* 0x4fc: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4fc, 0x5fb, x86_l_5fb);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_506:
	/* 0x506: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_50b:
	/* 0x50b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50e:
	/* 0x50e: je     643 <write_reg+0x643> */
	X86_SIM_X86_JCC(X86_CC_E, 0x50e, 0x643, x86_l_643);
x86_l_514:
	/* 0x514: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_517:
	/* 0x517: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x517, 0x5fb, x86_l_5fb);
x86_l_51d:
	/* 0x51d: mov    QWORD PTR [rdi+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_521:
	/* 0x521: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_526:
	/* 0x526: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_529:
	/* 0x529: je     653 <write_reg+0x653> */
	X86_SIM_X86_JCC(X86_CC_E, 0x529, 0x653, x86_l_653);
x86_l_52f:
	/* 0x52f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_532:
	/* 0x532: jne    5fb <write_reg+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x532, 0x5fb, x86_l_5fb);
x86_l_538:
	/* 0x538: mov    QWORD PTR [rdi+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_53c:
	/* 0x53c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_541:
	/* 0x541: mov    BYTE PTR [rdi+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_544:
	/* 0x544: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_549:
	/* 0x549: mov    BYTE PTR [rdi+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_54c:
	/* 0x54c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_551:
	/* 0x551: mov    DWORD PTR [rdi+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_554:
	/* 0x554: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_559:
	/* 0x559: mov    DWORD PTR [rdi+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_55c:
	/* 0x55c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_561:
	/* 0x561: mov    BYTE PTR [rdi+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_564:
	/* 0x564: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_569:
	/* 0x569: mov    BYTE PTR [rdi+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_56c:
	/* 0x56c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_571:
	/* 0x571: mov    DWORD PTR [rdi+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_574:
	/* 0x574: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_579:
	/* 0x579: mov    DWORD PTR [rdi+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_57c:
	/* 0x57c: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_581:
	/* 0x581: mov    BYTE PTR [rdi+0x80],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_587:
	/* 0x587: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_58c:
	/* 0x58c: mov    DWORD PTR [rdi+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_592:
	/* 0x592: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_597:
	/* 0x597: mov    BYTE PTR [rdi],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_599:
	/* 0x599: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_59e:
	/* 0x59e: mov    BYTE PTR [rdi+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a1:
	/* 0x5a1: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5a6:
	/* 0x5a6: mov    BYTE PTR [rdi+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a9:
	/* 0x5a9: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5ae:
	/* 0x5ae: mov    BYTE PTR [rdi+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b1:
	/* 0x5b1: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5b6:
	/* 0x5b6: mov    DWORD PTR [rdi],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b8:
	/* 0x5b8: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5bd:
	/* 0x5bd: mov    DWORD PTR [rdi+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c0:
	/* 0x5c0: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5c5:
	/* 0x5c5: mov    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c8:
	/* 0x5c8: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5cd:
	/* 0x5cd: mov    DWORD PTR [rdi+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d0:
	/* 0x5d0: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5d5:
	/* 0x5d5: mov    BYTE PTR [rdi+0x70],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d8:
	/* 0x5d8: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5dd:
	/* 0x5dd: mov    DWORD PTR [rdi+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5e0:
	/* 0x5e0: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5e5:
	/* 0x5e5: mov    BYTE PTR [rdi+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5e8:
	/* 0x5e8: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5ed:
	/* 0x5ed: mov    DWORD PTR [rdi+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5f0:
	/* 0x5f0: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5f5:
	/* 0x5f5: mov    BYTE PTR [rdi+0x98],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5fb:
	/* 0x5fb: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_600:
	/* 0x600: mov    DWORD PTR [rdi+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_606:
	/* 0x606: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_60b:
	/* 0x60b: mov    BYTE PTR [rdi+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60e:
	/* 0x60e: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_613:
	/* 0x613: mov    BYTE PTR [rdi+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_616:
	/* 0x616: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_61b:
	/* 0x61b: mov    BYTE PTR [rdi+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61e:
	/* 0x61e: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_623:
	/* 0x623: mov    BYTE PTR [rdi+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_626:
	/* 0x626: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_62b:
	/* 0x62b: mov    DWORD PTR [rdi+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62e:
	/* 0x62e: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_633:
	/* 0x633: mov    DWORD PTR [rdi+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_636:
	/* 0x636: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_63b:
	/* 0x63b: mov    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63e:
	/* 0x63e: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_643:
	/* 0x643: mov    DWORD PTR [rdi+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_646:
	/* 0x646: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_64b:
	/* 0x64b: mov    BYTE PTR [rdi+0x68],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_64e:
	/* 0x64e: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_653:
	/* 0x653: mov    DWORD PTR [rdi+0x68],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_656:
	/* 0x656: jmp    65b <write_reg+0x65b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_65b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
