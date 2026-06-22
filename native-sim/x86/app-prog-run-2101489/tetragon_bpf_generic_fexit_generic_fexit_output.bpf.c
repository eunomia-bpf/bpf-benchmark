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
	/* 0xf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14:
	/* 0x14: mov    rdi,QWORD PTR [rip+0x49e1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1b:
	/* 0x1b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     d3 <generic_fexit_output+0xd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0xd3, x86_l_d3);
x86_l_2b:
	/* 0x2b: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_30:
	/* 0x30: add    ecx,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_33:
	/* 0x33: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_39:
	/* 0x39: cmp    ecx,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9000ULL);
x86_l_3f:
	/* 0x3f: mov    r8d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 9000ULL);
x86_l_45:
	/* 0x45: cmovb  r8d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_49:
	/* 0x49: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_4f:
	/* 0x4f: mov    rsi,QWORD PTR [rip+0x49e1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_56:
	/* 0x56: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_5b:
	/* 0x5b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e:
	/* 0x5e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_61:
	/* 0x61: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_64:
	/* 0x64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67:
	/* 0x67: js     90 <generic_fexit_output+0x90> */
	X86_SIM_X86_JCC(X86_CC_S, 0x67, 0x90, x86_l_90);
x86_l_69:
	/* 0x69: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_71:
	/* 0x71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_76:
	/* 0x76: mov    rdi,QWORD PTR [rip+0x49e1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_7d:
	/* 0x7d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82:
	/* 0x82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84:
	/* 0x84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_87:
	/* 0x87: je     d3 <generic_fexit_output+0xd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x87, 0xd3, x86_l_d3);
x86_l_89:
	/* 0x89: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_8e:
	/* 0x8e: jmp    d3 <generic_fexit_output+0xd3> */
	X86_SIM_X86_JMP(0x8e, 0xd3, x86_l_d3);
x86_l_90:
	/* 0x90: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_9b:
	/* 0x9b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a0:
	/* 0xa0: mov    rdi,QWORD PTR [rip+0x49e1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_a7:
	/* 0xa7: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ac:
	/* 0xac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae:
	/* 0xae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1:
	/* 0xb1: je     d3 <generic_fexit_output+0xd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1, 0xd3, x86_l_d3);
x86_l_b3:
	/* 0xb3: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_b7:
	/* 0xb7: jg     de <generic_fexit_output+0xde> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb7, 0xde, x86_l_de);
x86_l_b9:
	/* 0xb9: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_bd:
	/* 0xbd: je     f8 <generic_fexit_output+0xf8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd, 0xf8, x86_l_f8);
x86_l_bf:
	/* 0xbf: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_c3:
	/* 0xc3: je     110 <generic_fexit_output+0x110> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3, 0x110, x86_l_110);
x86_l_c5:
	/* 0xc5: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_c9:
	/* 0xc9: jne    108 <generic_fexit_output+0x108> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc9, 0x108, x86_l_108);
x86_l_cb:
	/* 0xcb: add    rax,0x2f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 752ULL);
x86_l_d1:
	/* 0xd1: jmp    11e <generic_fexit_output+0x11e> */
	X86_SIM_X86_JMP(0xd1, 0x11e, x86_l_11e);
x86_l_d3:
	/* 0xd3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d5:
	/* 0xd5: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d9:
	/* 0xd9: jmp    12d <generic_fexit_output+0x12d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_de:
	/* 0xde: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_e2:
	/* 0xe2: je     100 <generic_fexit_output+0x100> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe2, 0x100, x86_l_100);
x86_l_e4:
	/* 0xe4: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_e8:
	/* 0xe8: je     118 <generic_fexit_output+0x118> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe8, 0x118, x86_l_118);
x86_l_ea:
	/* 0xea: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_ee:
	/* 0xee: jne    108 <generic_fexit_output+0x108> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xee, 0x108, x86_l_108);
x86_l_f0:
	/* 0xf0: add    rax,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_f6:
	/* 0xf6: jmp    11e <generic_fexit_output+0x11e> */
	X86_SIM_X86_JMP(0xf6, 0x11e, x86_l_11e);
x86_l_f8:
	/* 0xf8: add    rax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 768ULL);
x86_l_fe:
	/* 0xfe: jmp    11e <generic_fexit_output+0x11e> */
	X86_SIM_X86_JMP(0xfe, 0x11e, x86_l_11e);
x86_l_100:
	/* 0x100: add    rax,0x308 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 776ULL);
x86_l_106:
	/* 0x106: jmp    11e <generic_fexit_output+0x11e> */
	X86_SIM_X86_JMP(0x106, 0x11e, x86_l_11e);
x86_l_108:
	/* 0x108: add    rax,0x2d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 728ULL);
x86_l_10e:
	/* 0x10e: jmp    11e <generic_fexit_output+0x11e> */
	X86_SIM_X86_JMP(0x10e, 0x11e, x86_l_11e);
x86_l_110:
	/* 0x110: add    rax,0x2f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 760ULL);
x86_l_116:
	/* 0x116: jmp    11e <generic_fexit_output+0x11e> */
	X86_SIM_X86_JMP(0x116, 0x11e, x86_l_11e);
x86_l_118:
	/* 0x118: add    rax,0x2e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 744ULL);
x86_l_11e:
	/* 0x11e: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_122:
	/* 0x122: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124:
	/* 0x124: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_128:
	/* 0x128: jmp    12d <generic_fexit_output+0x12d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_12d:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
