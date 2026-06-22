#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_uprobe_v61_read_reg_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_6:
	/* 0x6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8:
	/* 0x8: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_b:
	/* 0xb: jle    42 <read_reg+0x42> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb, 0x42, x86_l_42);
x86_l_d:
	/* 0xd: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_10:
	/* 0x10: jle    66 <read_reg+0x66> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x10, 0x66, x86_l_66);
x86_l_12:
	/* 0x12: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_15:
	/* 0x15: jle    cb <read_reg+0xcb> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x15, 0xcb, x86_l_cb);
x86_l_1b:
	/* 0x1b: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e:
	/* 0x1e: je     ff <read_reg+0xff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e, 0xff, x86_l_ff);
x86_l_24:
	/* 0x24: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27:
	/* 0x27: je     e7 <read_reg+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27, 0xe7, x86_l_e7);
x86_l_2d:
	/* 0x2d: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_30:
	/* 0x30: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30, 0x115, x86_l_115);
x86_l_36:
	/* 0x36: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_3d:
	/* 0x3d: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0x3d, 0x109, x86_l_109);
x86_l_42:
	/* 0x42: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_45:
	/* 0x45: jg     82 <read_reg+0x82> */
	X86_SIM_X86_JCC(X86_CC_G, 0x45, 0x82, x86_l_82);
x86_l_47:
	/* 0x47: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4a:
	/* 0x4a: jg     ab <read_reg+0xab> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4a, 0xab, x86_l_ab);
x86_l_4c:
	/* 0x4c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4e:
	/* 0x4e: je     109 <read_reg+0x109> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e, 0x109, x86_l_109);
x86_l_54:
	/* 0x54: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_57:
	/* 0x57: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57, 0x115, x86_l_115);
x86_l_5d:
	/* 0x5d: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_61:
	/* 0x61: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0x61, 0x109, x86_l_109);
x86_l_66:
	/* 0x66: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_69:
	/* 0x69: jg     9b <read_reg+0x9b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x69, 0x9b, x86_l_9b);
x86_l_6b:
	/* 0x6b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e:
	/* 0x6e: je     db <read_reg+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0xdb, x86_l_db);
x86_l_70:
	/* 0x70: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_73:
	/* 0x73: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x73, 0x115, x86_l_115);
x86_l_79:
	/* 0x79: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_7d:
	/* 0x7d: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0x7d, 0x109, x86_l_109);
x86_l_82:
	/* 0x82: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_85:
	/* 0x85: jg     bb <read_reg+0xbb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x85, 0xbb, x86_l_bb);
x86_l_87:
	/* 0x87: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8a:
	/* 0x8a: je     ed <read_reg+0xed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a, 0xed, x86_l_ed);
x86_l_8c:
	/* 0x8c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8f:
	/* 0x8f: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8f, 0x115, x86_l_115);
x86_l_95:
	/* 0x95: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_99:
	/* 0x99: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0x99, 0x109, x86_l_109);
x86_l_9b:
	/* 0x9b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_9e:
	/* 0x9e: je     e1 <read_reg+0xe1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e, 0xe1, x86_l_e1);
x86_l_a0:
	/* 0xa0: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_a3:
	/* 0xa3: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3, 0x115, x86_l_115);
x86_l_a5:
	/* 0xa5: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_a9:
	/* 0xa9: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xa9, 0x109, x86_l_109);
x86_l_ab:
	/* 0xab: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ae:
	/* 0xae: je     f3 <read_reg+0xf3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae, 0xf3, x86_l_f3);
x86_l_b0:
	/* 0xb0: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b3:
	/* 0xb3: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb3, 0x115, x86_l_115);
x86_l_b5:
	/* 0xb5: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_b9:
	/* 0xb9: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xb9, 0x109, x86_l_109);
x86_l_bb:
	/* 0xbb: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_be:
	/* 0xbe: je     f9 <read_reg+0xf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe, 0xf9, x86_l_f9);
x86_l_c0:
	/* 0xc0: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c3:
	/* 0xc3: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc3, 0x115, x86_l_115);
x86_l_c5:
	/* 0xc5: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_c9:
	/* 0xc9: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xc9, 0x109, x86_l_109);
x86_l_cb:
	/* 0xcb: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ce:
	/* 0xce: je     105 <read_reg+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce, 0x105, x86_l_105);
x86_l_d0:
	/* 0xd0: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d3:
	/* 0xd3: jne    115 <read_reg+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd3, 0x115, x86_l_115);
x86_l_d5:
	/* 0xd5: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_d9:
	/* 0xd9: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xd9, 0x109, x86_l_109);
x86_l_db:
	/* 0xdb: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_df:
	/* 0xdf: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xdf, 0x109, x86_l_109);
x86_l_e1:
	/* 0xe1: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_e5:
	/* 0xe5: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xe5, 0x109, x86_l_109);
x86_l_e7:
	/* 0xe7: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_eb:
	/* 0xeb: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xeb, 0x109, x86_l_109);
x86_l_ed:
	/* 0xed: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_f1:
	/* 0xf1: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xf1, 0x109, x86_l_109);
x86_l_f3:
	/* 0xf3: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f7:
	/* 0xf7: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xf7, 0x109, x86_l_109);
x86_l_f9:
	/* 0xf9: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_fd:
	/* 0xfd: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0xfd, 0x109, x86_l_109);
x86_l_ff:
	/* 0xff: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_103:
	/* 0x103: jmp    109 <read_reg+0x109> */
	X86_SIM_X86_JMP(0x103, 0x109, x86_l_109);
x86_l_105:
	/* 0x105: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_109:
	/* 0x109: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_10e:
	/* 0x10e: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_110:
	/* 0x110: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_115:
	/* 0x115: jmp    11a <read_reg+0x11a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_11a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
