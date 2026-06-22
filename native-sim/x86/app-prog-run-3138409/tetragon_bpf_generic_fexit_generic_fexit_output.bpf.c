extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_fexit_generic_fexit_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_f:
	/* 0xf: mov    rdi,QWORD PTR [rip+0x49b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_16:
	/* 0x16: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b:
	/* 0x1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     cf <generic_fexit_output+0xcf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0xcf, x86_l_cf);
x86_l_2b:
	/* 0x2b: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2e:
	/* 0x2e: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_33:
	/* 0x33: add    eax,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_36:
	/* 0x36: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3b:
	/* 0x3b: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_40:
	/* 0x40: mov    r8d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 9000ULL);
x86_l_46:
	/* 0x46: cmovb  r8d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_4a:
	/* 0x4a: mov    rsi,QWORD PTR [rip+0x49b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_51:
	/* 0x51: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_56:
	/* 0x56: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_5b:
	/* 0x5b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63:
	/* 0x63: js     8c <generic_fexit_output+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x63, 0x8c, x86_l_8c);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6d:
	/* 0x6d: mov    rdi,QWORD PTR [rip+0x49b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_74:
	/* 0x74: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_79:
	/* 0x79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e:
	/* 0x7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80:
	/* 0x80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83:
	/* 0x83: je     cf <generic_fexit_output+0xcf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83, 0xcf, x86_l_cf);
x86_l_85:
	/* 0x85: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_8a:
	/* 0x8a: jmp    cf <generic_fexit_output+0xcf> */
	X86_SIM_X86_JMP(0x8a, 0xcf, x86_l_cf);
x86_l_8c:
	/* 0x8c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_8f:
	/* 0x8f: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_97:
	/* 0x97: mov    rdi,QWORD PTR [rip+0x49b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_9e:
	/* 0x9e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a3:
	/* 0xa3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a8:
	/* 0xa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa:
	/* 0xaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad:
	/* 0xad: je     cf <generic_fexit_output+0xcf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad, 0xcf, x86_l_cf);
x86_l_af:
	/* 0xaf: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_b3:
	/* 0xb3: jg     da <generic_fexit_output+0xda> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb3, 0xda, x86_l_da);
x86_l_b5:
	/* 0xb5: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_b9:
	/* 0xb9: je     f4 <generic_fexit_output+0xf4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9, 0xf4, x86_l_f4);
x86_l_bb:
	/* 0xbb: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_bf:
	/* 0xbf: je     10c <generic_fexit_output+0x10c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf, 0x10c, x86_l_10c);
x86_l_c1:
	/* 0xc1: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_c5:
	/* 0xc5: jne    104 <generic_fexit_output+0x104> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc5, 0x104, x86_l_104);
x86_l_c7:
	/* 0xc7: add    rax,0x2f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 752ULL);
x86_l_cd:
	/* 0xcd: jmp    11a <generic_fexit_output+0x11a> */
	X86_SIM_X86_JMP(0xcd, 0x11a, x86_l_11a);
x86_l_cf:
	/* 0xcf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d1:
	/* 0xd1: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d5:
	/* 0xd5: jmp    129 <generic_fexit_output+0x129> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_da:
	/* 0xda: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_de:
	/* 0xde: je     fc <generic_fexit_output+0xfc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde, 0xfc, x86_l_fc);
x86_l_e0:
	/* 0xe0: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_e4:
	/* 0xe4: je     114 <generic_fexit_output+0x114> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe4, 0x114, x86_l_114);
x86_l_e6:
	/* 0xe6: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_ea:
	/* 0xea: jne    104 <generic_fexit_output+0x104> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea, 0x104, x86_l_104);
x86_l_ec:
	/* 0xec: add    rax,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_f2:
	/* 0xf2: jmp    11a <generic_fexit_output+0x11a> */
	X86_SIM_X86_JMP(0xf2, 0x11a, x86_l_11a);
x86_l_f4:
	/* 0xf4: add    rax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 768ULL);
x86_l_fa:
	/* 0xfa: jmp    11a <generic_fexit_output+0x11a> */
	X86_SIM_X86_JMP(0xfa, 0x11a, x86_l_11a);
x86_l_fc:
	/* 0xfc: add    rax,0x308 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 776ULL);
x86_l_102:
	/* 0x102: jmp    11a <generic_fexit_output+0x11a> */
	X86_SIM_X86_JMP(0x102, 0x11a, x86_l_11a);
x86_l_104:
	/* 0x104: add    rax,0x2d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 728ULL);
x86_l_10a:
	/* 0x10a: jmp    11a <generic_fexit_output+0x11a> */
	X86_SIM_X86_JMP(0x10a, 0x11a, x86_l_11a);
x86_l_10c:
	/* 0x10c: add    rax,0x2f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 760ULL);
x86_l_112:
	/* 0x112: jmp    11a <generic_fexit_output+0x11a> */
	X86_SIM_X86_JMP(0x112, 0x11a, x86_l_11a);
x86_l_114:
	/* 0x114: add    rax,0x2e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 744ULL);
x86_l_11a:
	/* 0x11a: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_11e:
	/* 0x11e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120:
	/* 0x120: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_124:
	/* 0x124: jmp    129 <generic_fexit_output+0x129> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_129:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
