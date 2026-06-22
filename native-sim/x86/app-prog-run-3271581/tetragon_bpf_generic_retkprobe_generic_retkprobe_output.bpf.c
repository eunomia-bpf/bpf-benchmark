extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retkprobe_generic_retkprobe_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1:
	/* 0x1: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_5:
	/* 0x5: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8:
	/* 0x8: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_10:
	/* 0x10: mov    rdi,QWORD PTR [rip+0x16b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_17:
	/* 0x17: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c:
	/* 0x1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21:
	/* 0x21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23:
	/* 0x23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26:
	/* 0x26: je     d0 <generic_retkprobe_output+0xd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26, 0xd0, x86_l_d0);
x86_l_2c:
	/* 0x2c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_34:
	/* 0x34: add    eax,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_37:
	/* 0x37: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3c:
	/* 0x3c: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_41:
	/* 0x41: mov    r8d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 9000ULL);
x86_l_47:
	/* 0x47: cmovb  r8d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_4b:
	/* 0x4b: mov    rsi,QWORD PTR [rip+0x16b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_52:
	/* 0x52: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_57:
	/* 0x57: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61:
	/* 0x61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64:
	/* 0x64: js     8d <generic_retkprobe_output+0x8d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x64, 0x8d, x86_l_8d);
x86_l_66:
	/* 0x66: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6e:
	/* 0x6e: mov    rdi,QWORD PTR [rip+0x16b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_75:
	/* 0x75: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a:
	/* 0x7a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f:
	/* 0x7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81:
	/* 0x81: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: je     d0 <generic_retkprobe_output+0xd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84, 0xd0, x86_l_d0);
x86_l_86:
	/* 0x86: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_8b:
	/* 0x8b: jmp    d0 <generic_retkprobe_output+0xd0> */
	X86_SIM_X86_JMP(0x8b, 0xd0, x86_l_d0);
x86_l_8d:
	/* 0x8d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_90:
	/* 0x90: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_98:
	/* 0x98: mov    rdi,QWORD PTR [rip+0x16b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_9f:
	/* 0x9f: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a4:
	/* 0xa4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9:
	/* 0xa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab:
	/* 0xab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae:
	/* 0xae: je     d0 <generic_retkprobe_output+0xd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae, 0xd0, x86_l_d0);
x86_l_b0:
	/* 0xb0: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_b4:
	/* 0xb4: jg     dc <generic_retkprobe_output+0xdc> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb4, 0xdc, x86_l_dc);
x86_l_b6:
	/* 0xb6: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_ba:
	/* 0xba: je     f6 <generic_retkprobe_output+0xf6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba, 0xf6, x86_l_f6);
x86_l_bc:
	/* 0xbc: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_c0:
	/* 0xc0: je     10e <generic_retkprobe_output+0x10e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc0, 0x10e, x86_l_10e);
x86_l_c2:
	/* 0xc2: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_c6:
	/* 0xc6: jne    106 <generic_retkprobe_output+0x106> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc6, 0x106, x86_l_106);
x86_l_c8:
	/* 0xc8: add    rax,0x2f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 752ULL);
x86_l_ce:
	/* 0xce: jmp    11c <generic_retkprobe_output+0x11c> */
	X86_SIM_X86_JMP(0xce, 0x11c, x86_l_11c);
x86_l_d0:
	/* 0xd0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2:
	/* 0xd2: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d6:
	/* 0xd6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_d7:
	/* 0xd7: jmp    12c <generic_retkprobe_output+0x12c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_dc:
	/* 0xdc: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_e0:
	/* 0xe0: je     fe <generic_retkprobe_output+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0, 0xfe, x86_l_fe);
x86_l_e2:
	/* 0xe2: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_e6:
	/* 0xe6: je     116 <generic_retkprobe_output+0x116> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe6, 0x116, x86_l_116);
x86_l_e8:
	/* 0xe8: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_ec:
	/* 0xec: jne    106 <generic_retkprobe_output+0x106> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xec, 0x106, x86_l_106);
x86_l_ee:
	/* 0xee: add    rax,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_f4:
	/* 0xf4: jmp    11c <generic_retkprobe_output+0x11c> */
	X86_SIM_X86_JMP(0xf4, 0x11c, x86_l_11c);
x86_l_f6:
	/* 0xf6: add    rax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 768ULL);
x86_l_fc:
	/* 0xfc: jmp    11c <generic_retkprobe_output+0x11c> */
	X86_SIM_X86_JMP(0xfc, 0x11c, x86_l_11c);
x86_l_fe:
	/* 0xfe: add    rax,0x308 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 776ULL);
x86_l_104:
	/* 0x104: jmp    11c <generic_retkprobe_output+0x11c> */
	X86_SIM_X86_JMP(0x104, 0x11c, x86_l_11c);
x86_l_106:
	/* 0x106: add    rax,0x2d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 728ULL);
x86_l_10c:
	/* 0x10c: jmp    11c <generic_retkprobe_output+0x11c> */
	X86_SIM_X86_JMP(0x10c, 0x11c, x86_l_11c);
x86_l_10e:
	/* 0x10e: add    rax,0x2f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 760ULL);
x86_l_114:
	/* 0x114: jmp    11c <generic_retkprobe_output+0x11c> */
	X86_SIM_X86_JMP(0x114, 0x11c, x86_l_11c);
x86_l_116:
	/* 0x116: add    rax,0x2e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 744ULL);
x86_l_11c:
	/* 0x11c: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_120:
	/* 0x120: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_122:
	/* 0x122: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_126:
	/* 0x126: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_127:
	/* 0x127: jmp    12c <generic_retkprobe_output+0x12c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_12c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
