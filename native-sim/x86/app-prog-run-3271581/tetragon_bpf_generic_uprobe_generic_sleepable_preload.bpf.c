extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3:
	/* 0x3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5:
	/* 0x5: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_7:
	/* 0x7: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_9:
	/* 0x9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_a:
	/* 0xa: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_11:
	/* 0x11: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0x111, x86_l_111);
x86_l_3e:
	/* 0x3e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_48:
	/* 0x48: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4d:
	/* 0x4d: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_54:
	/* 0x54: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_59:
	/* 0x59: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_62:
	/* 0x62: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b:
	/* 0x6b: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6f:
	/* 0x6f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_74:
	/* 0x74: lea    r12,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_78:
	/* 0x78: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7c:
	/* 0x7c: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_84:
	/* 0x84: lea    r13,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_88:
	/* 0x88: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_94:
	/* 0x94: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_98:
	/* 0x98: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d:
	/* 0x9d: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a6:
	/* 0xa6: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_af:
	/* 0xaf: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b8:
	/* 0xb8: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bc:
	/* 0xbc: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c1:
	/* 0xc1: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5:
	/* 0xc5: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ca:
	/* 0xca: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d3:
	/* 0xd3: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6:
	/* 0xd6: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_db:
	/* 0xdb: jne    129 <generic_sleepable_preload+0x129> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdb, 0x129, x86_l_129);
x86_l_dd:
	/* 0xdd: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e0:
	/* 0xe0: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e5:
	/* 0xe5: jne    161 <generic_sleepable_preload+0x161> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe5, 0x161, x86_l_161);
x86_l_e7:
	/* 0xe7: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea:
	/* 0xea: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_ef:
	/* 0xef: jne    199 <generic_sleepable_preload+0x199> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef, 0x199, x86_l_199);
x86_l_f5:
	/* 0xf5: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f8:
	/* 0xf8: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_fd:
	/* 0xfd: jne    1d1 <generic_sleepable_preload+0x1d1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd, 0x1d1, x86_l_1d1);
x86_l_103:
	/* 0x103: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_106:
	/* 0x106: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_10b:
	/* 0x10b: jne    209 <generic_sleepable_preload+0x209> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10b, 0x209, x86_l_209);
x86_l_111:
	/* 0x111: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_113:
	/* 0x113: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_11a:
	/* 0x11a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11d:
	/* 0x11d: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_121:
	/* 0x121: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_123:
	/* 0x123: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_124:
	/* 0x124: jmp    1093 <generic_sleepable_preload+0x1093> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_129:
	/* 0x129: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_12b:
	/* 0x12b: js     241 <generic_sleepable_preload+0x241> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12b, 0x241, x86_l_241);
x86_l_131:
	/* 0x131: mov    eax,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_134:
	/* 0x134: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_137:
	/* 0x137: jle    506 <generic_sleepable_preload+0x506> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x137, 0x506, x86_l_506);
x86_l_13d:
	/* 0x13d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_140:
	/* 0x140: je     736 <generic_sleepable_preload+0x736> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140, 0x736, x86_l_736);
x86_l_146:
	/* 0x146: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_149:
	/* 0x149: je     765 <generic_sleepable_preload+0x765> */
	X86_SIM_X86_JCC(X86_CC_E, 0x149, 0x765, x86_l_765);
x86_l_14f:
	/* 0x14f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_152:
	/* 0x152: jne    79b <generic_sleepable_preload+0x79b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x152, 0x79b, x86_l_79b);
x86_l_158:
	/* 0x158: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c:
	/* 0x15c: jmp    797 <generic_sleepable_preload+0x797> */
	X86_SIM_X86_JMP(0x15c, 0x797, x86_l_797);
x86_l_161:
	/* 0x161: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_163:
	/* 0x163: js     2a1 <generic_sleepable_preload+0x2a1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x163, 0x2a1, x86_l_2a1);
x86_l_169:
	/* 0x169: mov    eax,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_16c:
	/* 0x16c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16f:
	/* 0x16f: jle    521 <generic_sleepable_preload+0x521> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x16f, 0x521, x86_l_521);
x86_l_175:
	/* 0x175: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_178:
	/* 0x178: je     73d <generic_sleepable_preload+0x73d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178, 0x73d, x86_l_73d);
x86_l_17e:
	/* 0x17e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_181:
	/* 0x181: je     76b <generic_sleepable_preload+0x76b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x76b, x86_l_76b);
x86_l_187:
	/* 0x187: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a:
	/* 0x18a: jne    832 <generic_sleepable_preload+0x832> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a, 0x832, x86_l_832);
x86_l_190:
	/* 0x190: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194:
	/* 0x194: jmp    82e <generic_sleepable_preload+0x82e> */
	X86_SIM_X86_JMP(0x194, 0x82e, x86_l_82e);
x86_l_199:
	/* 0x199: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_19b:
	/* 0x19b: js     301 <generic_sleepable_preload+0x301> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19b, 0x301, x86_l_301);
x86_l_1a1:
	/* 0x1a1: mov    eax,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a4:
	/* 0x1a4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a7:
	/* 0x1a7: jle    53c <generic_sleepable_preload+0x53c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1a7, 0x53c, x86_l_53c);
x86_l_1ad:
	/* 0x1ad: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b0:
	/* 0x1b0: je     747 <generic_sleepable_preload+0x747> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b0, 0x747, x86_l_747);
x86_l_1b6:
	/* 0x1b6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1b9:
	/* 0x1b9: je     774 <generic_sleepable_preload+0x774> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b9, 0x774, x86_l_774);
x86_l_1bf:
	/* 0x1bf: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c2:
	/* 0x1c2: jne    8c9 <generic_sleepable_preload+0x8c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c2, 0x8c9, x86_l_8c9);
x86_l_1c8:
	/* 0x1c8: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc:
	/* 0x1cc: jmp    8c5 <generic_sleepable_preload+0x8c5> */
	X86_SIM_X86_JMP(0x1cc, 0x8c5, x86_l_8c5);
x86_l_1d1:
	/* 0x1d1: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1d3:
	/* 0x1d3: js     361 <generic_sleepable_preload+0x361> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1d3, 0x361, x86_l_361);
x86_l_1d9:
	/* 0x1d9: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1dc:
	/* 0x1dc: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1df:
	/* 0x1df: jle    557 <generic_sleepable_preload+0x557> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1df, 0x557, x86_l_557);
x86_l_1e5:
	/* 0x1e5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e8:
	/* 0x1e8: je     751 <generic_sleepable_preload+0x751> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e8, 0x751, x86_l_751);
x86_l_1ee:
	/* 0x1ee: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f1:
	/* 0x1f1: je     77d <generic_sleepable_preload+0x77d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f1, 0x77d, x86_l_77d);
x86_l_1f7:
	/* 0x1f7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fa:
	/* 0x1fa: jne    960 <generic_sleepable_preload+0x960> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fa, 0x960, x86_l_960);
x86_l_200:
	/* 0x200: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_204:
	/* 0x204: jmp    95c <generic_sleepable_preload+0x95c> */
	X86_SIM_X86_JMP(0x204, 0x95c, x86_l_95c);
x86_l_209:
	/* 0x209: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_20b:
	/* 0x20b: js     3c1 <generic_sleepable_preload+0x3c1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x20b, 0x3c1, x86_l_3c1);
x86_l_211:
	/* 0x211: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_214:
	/* 0x214: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_217:
	/* 0x217: jle    572 <generic_sleepable_preload+0x572> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x217, 0x572, x86_l_572);
x86_l_21d:
	/* 0x21d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_220:
	/* 0x220: je     75b <generic_sleepable_preload+0x75b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x220, 0x75b, x86_l_75b);
x86_l_226:
	/* 0x226: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_229:
	/* 0x229: je     786 <generic_sleepable_preload+0x786> */
	X86_SIM_X86_JCC(X86_CC_E, 0x229, 0x786, x86_l_786);
x86_l_22f:
	/* 0x22f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_232:
	/* 0x232: jne    9f7 <generic_sleepable_preload+0x9f7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x232, 0x9f7, x86_l_9f7);
x86_l_238:
	/* 0x238: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c:
	/* 0x23c: jmp    9f3 <generic_sleepable_preload+0x9f3> */
	X86_SIM_X86_JMP(0x23c, 0x9f3, x86_l_9f3);
x86_l_241:
	/* 0x241: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_248:
	/* 0x248: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_24f:
	/* 0x24f: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_255:
	/* 0x255: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257:
	/* 0x257: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_25a:
	/* 0x25a: jle    422 <generic_sleepable_preload+0x422> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x25a, 0x422, x86_l_422);
x86_l_260:
	/* 0x260: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_263:
	/* 0x263: jle    58d <generic_sleepable_preload+0x58d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x263, 0x58d, x86_l_58d);
x86_l_269:
	/* 0x269: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_26c:
	/* 0x26c: jle    c8c <generic_sleepable_preload+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x26c, 0xc8c, x86_l_c8c);
x86_l_272:
	/* 0x272: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_277:
	/* 0x277: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_27a:
	/* 0x27a: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27a, 0xca0, x86_l_ca0);
x86_l_280:
	/* 0x280: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_285:
	/* 0x285: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_288:
	/* 0x288: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x288, 0xca0, x86_l_ca0);
x86_l_28e:
	/* 0x28e: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_291:
	/* 0x291: jne    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x291, 0xcb3, x86_l_cb3);
x86_l_297:
	/* 0x297: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_29c:
	/* 0x29c: jmp    ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JMP(0x29c, 0xca0, x86_l_ca0);
x86_l_2a1:
	/* 0x2a1: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_2a8:
	/* 0x2a8: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_2af:
	/* 0x2af: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2b5:
	/* 0x2b5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b7:
	/* 0x2b7: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2ba:
	/* 0x2ba: jle    452 <generic_sleepable_preload+0x452> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2ba, 0x452, x86_l_452);
x86_l_2c0:
	/* 0x2c0: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2c3:
	/* 0x2c3: jle    5b8 <generic_sleepable_preload+0x5b8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2c3, 0x5b8, x86_l_5b8);
x86_l_2c9:
	/* 0x2c9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2cc:
	/* 0x2cc: jle    d54 <generic_sleepable_preload+0xd54> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2cc, 0xd54, x86_l_d54);
x86_l_2d2:
	/* 0x2d2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d7:
	/* 0x2d7: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_2da:
	/* 0x2da: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2da, 0xe71, x86_l_e71);
x86_l_2e0:
	/* 0x2e0: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e5:
	/* 0x2e5: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_2e8:
	/* 0x2e8: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e8, 0xe71, x86_l_e71);
x86_l_2ee:
	/* 0x2ee: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f3:
	/* 0x2f3: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2f6:
	/* 0x2f6: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f6, 0xe71, x86_l_e71);
x86_l_2fc:
	/* 0x2fc: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0x2fc, 0xe84, x86_l_e84);
x86_l_301:
	/* 0x301: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_308:
	/* 0x308: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_30f:
	/* 0x30f: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_315:
	/* 0x315: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_317:
	/* 0x317: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_31a:
	/* 0x31a: jle    47f <generic_sleepable_preload+0x47f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x31a, 0x47f, x86_l_47f);
x86_l_320:
	/* 0x320: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_323:
	/* 0x323: jle    5e3 <generic_sleepable_preload+0x5e3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x323, 0x5e3, x86_l_5e3);
x86_l_329:
	/* 0x329: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_32c:
	/* 0x32c: jle    d75 <generic_sleepable_preload+0xd75> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x32c, 0xd75, x86_l_d75);
x86_l_332:
	/* 0x332: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_337:
	/* 0x337: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_33a:
	/* 0x33a: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33a, 0xf28, x86_l_f28);
x86_l_340:
	/* 0x340: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_345:
	/* 0x345: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_348:
	/* 0x348: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x348, 0xf28, x86_l_f28);
x86_l_34e:
	/* 0x34e: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_353:
	/* 0x353: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_356:
	/* 0x356: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x356, 0xf28, x86_l_f28);
x86_l_35c:
	/* 0x35c: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0x35c, 0xf3b, x86_l_f3b);
x86_l_361:
	/* 0x361: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_368:
	/* 0x368: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_36f:
	/* 0x36f: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_375:
	/* 0x375: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377:
	/* 0x377: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_37a:
	/* 0x37a: jle    4ac <generic_sleepable_preload+0x4ac> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x37a, 0x4ac, x86_l_4ac);
x86_l_380:
	/* 0x380: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_383:
	/* 0x383: jle    60e <generic_sleepable_preload+0x60e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x383, 0x60e, x86_l_60e);
x86_l_389:
	/* 0x389: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_38c:
	/* 0x38c: jle    d96 <generic_sleepable_preload+0xd96> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x38c, 0xd96, x86_l_d96);
x86_l_392:
	/* 0x392: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_397:
	/* 0x397: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_39a:
	/* 0x39a: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39a, 0xfdf, x86_l_fdf);
x86_l_3a0:
	/* 0x3a0: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3a5:
	/* 0x3a5: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_3a8:
	/* 0x3a8: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a8, 0xfdf, x86_l_fdf);
x86_l_3ae:
	/* 0x3ae: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b3:
	/* 0x3b3: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3b6:
	/* 0x3b6: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b6, 0xfdf, x86_l_fdf);
x86_l_3bc:
	/* 0x3bc: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0x3bc, 0xff2, x86_l_ff2);
x86_l_3c1:
	/* 0x3c1: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_3c8:
	/* 0x3c8: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_3cf:
	/* 0x3cf: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3d5:
	/* 0x3d5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d8:
	/* 0x3d8: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3db:
	/* 0x3db: jle    4d9 <generic_sleepable_preload+0x4d9> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3db, 0x4d9, x86_l_4d9);
x86_l_3e1:
	/* 0x3e1: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3e4:
	/* 0x3e4: jle    639 <generic_sleepable_preload+0x639> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3e4, 0x639, x86_l_639);
x86_l_3ea:
	/* 0x3ea: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3ed:
	/* 0x3ed: jle    db7 <generic_sleepable_preload+0xdb7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3ed, 0xdb7, x86_l_db7);
x86_l_3f3:
	/* 0x3f3: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f8:
	/* 0x3f8: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_3fb:
	/* 0x3fb: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fb, 0xdcb, x86_l_dcb);
x86_l_401:
	/* 0x401: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_406:
	/* 0x406: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_409:
	/* 0x409: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x409, 0xdcb, x86_l_dcb);
x86_l_40f:
	/* 0x40f: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_414:
	/* 0x414: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_417:
	/* 0x417: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0xdcb, x86_l_dcb);
x86_l_41d:
	/* 0x41d: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0x41d, 0xdde, x86_l_dde);
x86_l_422:
	/* 0x422: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_425:
	/* 0x425: jg     664 <generic_sleepable_preload+0x664> */
	X86_SIM_X86_JCC(X86_CC_G, 0x425, 0x664, x86_l_664);
x86_l_42b:
	/* 0x42b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_42e:
	/* 0x42e: jg     b42 <generic_sleepable_preload+0xb42> */
	X86_SIM_X86_JCC(X86_CC_G, 0x42e, 0xb42, x86_l_b42);
x86_l_434:
	/* 0x434: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_437:
	/* 0x437: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_439:
	/* 0x439: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x439, 0xca0, x86_l_ca0);
x86_l_43f:
	/* 0x43f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_444:
	/* 0x444: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_447:
	/* 0x447: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x447, 0xca0, x86_l_ca0);
x86_l_44d:
	/* 0x44d: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JMP(0x44d, 0xcb3, x86_l_cb3);
x86_l_452:
	/* 0x452: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_455:
	/* 0x455: jg     68e <generic_sleepable_preload+0x68e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x455, 0x68e, x86_l_68e);
x86_l_45b:
	/* 0x45b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_45e:
	/* 0x45e: jg     b63 <generic_sleepable_preload+0xb63> */
	X86_SIM_X86_JCC(X86_CC_G, 0x45e, 0xb63, x86_l_b63);
x86_l_464:
	/* 0x464: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_466:
	/* 0x466: je     e6e <generic_sleepable_preload+0xe6e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x466, 0xe6e, x86_l_e6e);
x86_l_46c:
	/* 0x46c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_471:
	/* 0x471: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_474:
	/* 0x474: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x474, 0xe71, x86_l_e71);
x86_l_47a:
	/* 0x47a: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0x47a, 0xe84, x86_l_e84);
x86_l_47f:
	/* 0x47f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_482:
	/* 0x482: jg     6b8 <generic_sleepable_preload+0x6b8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x482, 0x6b8, x86_l_6b8);
x86_l_488:
	/* 0x488: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_48b:
	/* 0x48b: jg     b84 <generic_sleepable_preload+0xb84> */
	X86_SIM_X86_JCC(X86_CC_G, 0x48b, 0xb84, x86_l_b84);
x86_l_491:
	/* 0x491: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_493:
	/* 0x493: je     f25 <generic_sleepable_preload+0xf25> */
	X86_SIM_X86_JCC(X86_CC_E, 0x493, 0xf25, x86_l_f25);
x86_l_499:
	/* 0x499: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_49e:
	/* 0x49e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4a1:
	/* 0x4a1: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a1, 0xf28, x86_l_f28);
x86_l_4a7:
	/* 0x4a7: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0x4a7, 0xf3b, x86_l_f3b);
x86_l_4ac:
	/* 0x4ac: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4af:
	/* 0x4af: jg     6e2 <generic_sleepable_preload+0x6e2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4af, 0x6e2, x86_l_6e2);
x86_l_4b5:
	/* 0x4b5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4b8:
	/* 0x4b8: jg     ba5 <generic_sleepable_preload+0xba5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b8, 0xba5, x86_l_ba5);
x86_l_4be:
	/* 0x4be: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4c0:
	/* 0x4c0: je     fdc <generic_sleepable_preload+0xfdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c0, 0xfdc, x86_l_fdc);
x86_l_4c6:
	/* 0x4c6: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4cb:
	/* 0x4cb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ce:
	/* 0x4ce: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ce, 0xfdf, x86_l_fdf);
x86_l_4d4:
	/* 0x4d4: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0x4d4, 0xff2, x86_l_ff2);
x86_l_4d9:
	/* 0x4d9: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4dc:
	/* 0x4dc: jg     70c <generic_sleepable_preload+0x70c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4dc, 0x70c, x86_l_70c);
x86_l_4e2:
	/* 0x4e2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4e5:
	/* 0x4e5: jg     bc6 <generic_sleepable_preload+0xbc6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4e5, 0xbc6, x86_l_bc6);
x86_l_4eb:
	/* 0x4eb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4ed:
	/* 0x4ed: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ed, 0xdcb, x86_l_dcb);
x86_l_4f3:
	/* 0x4f3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4f6:
	/* 0x4f6: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4fb:
	/* 0x4fb: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4fb, 0xdcb, x86_l_dcb);
x86_l_501:
	/* 0x501: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0x501, 0xdde, x86_l_dde);
x86_l_506:
	/* 0x506: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_508:
	/* 0x508: je     78f <generic_sleepable_preload+0x78f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x508, 0x78f, x86_l_78f);
x86_l_50e:
	/* 0x50e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_511:
	/* 0x511: jne    79b <generic_sleepable_preload+0x79b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x511, 0x79b, x86_l_79b);
x86_l_517:
	/* 0x517: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51c:
	/* 0x51c: jmp    794 <generic_sleepable_preload+0x794> */
	X86_SIM_X86_JMP(0x51c, 0x794, x86_l_794);
x86_l_521:
	/* 0x521: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_523:
	/* 0x523: je     826 <generic_sleepable_preload+0x826> */
	X86_SIM_X86_JCC(X86_CC_E, 0x523, 0x826, x86_l_826);
x86_l_529:
	/* 0x529: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52c:
	/* 0x52c: jne    832 <generic_sleepable_preload+0x832> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x52c, 0x832, x86_l_832);
x86_l_532:
	/* 0x532: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_537:
	/* 0x537: jmp    82b <generic_sleepable_preload+0x82b> */
	X86_SIM_X86_JMP(0x537, 0x82b, x86_l_82b);
x86_l_53c:
	/* 0x53c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53e:
	/* 0x53e: je     8bd <generic_sleepable_preload+0x8bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53e, 0x8bd, x86_l_8bd);
x86_l_544:
	/* 0x544: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_547:
	/* 0x547: jne    8c9 <generic_sleepable_preload+0x8c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x547, 0x8c9, x86_l_8c9);
x86_l_54d:
	/* 0x54d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_552:
	/* 0x552: jmp    8c2 <generic_sleepable_preload+0x8c2> */
	X86_SIM_X86_JMP(0x552, 0x8c2, x86_l_8c2);
x86_l_557:
	/* 0x557: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_559:
	/* 0x559: je     954 <generic_sleepable_preload+0x954> */
	X86_SIM_X86_JCC(X86_CC_E, 0x559, 0x954, x86_l_954);
x86_l_55f:
	/* 0x55f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_562:
	/* 0x562: jne    960 <generic_sleepable_preload+0x960> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x562, 0x960, x86_l_960);
x86_l_568:
	/* 0x568: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56d:
	/* 0x56d: jmp    959 <generic_sleepable_preload+0x959> */
	X86_SIM_X86_JMP(0x56d, 0x959, x86_l_959);
x86_l_572:
	/* 0x572: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_574:
	/* 0x574: je     9eb <generic_sleepable_preload+0x9eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x574, 0x9eb, x86_l_9eb);
x86_l_57a:
	/* 0x57a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57d:
	/* 0x57d: jne    9f7 <generic_sleepable_preload+0x9f7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57d, 0x9f7, x86_l_9f7);
x86_l_583:
	/* 0x583: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_588:
	/* 0x588: jmp    9f0 <generic_sleepable_preload+0x9f0> */
	X86_SIM_X86_JMP(0x588, 0x9f0, x86_l_9f0);
x86_l_58d:
	/* 0x58d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_590:
	/* 0x590: jg     a98 <generic_sleepable_preload+0xa98> */
	X86_SIM_X86_JCC(X86_CC_G, 0x590, 0xa98, x86_l_a98);
x86_l_596:
	/* 0x596: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_59e:
	/* 0x59e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a1:
	/* 0x5a1: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a1, 0xca0, x86_l_ca0);
x86_l_5a7:
	/* 0x5a7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5aa:
	/* 0x5aa: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5ad:
	/* 0x5ad: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ad, 0xca0, x86_l_ca0);
x86_l_5b3:
	/* 0x5b3: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JMP(0x5b3, 0xcb3, x86_l_cb3);
x86_l_5b8:
	/* 0x5b8: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5bb:
	/* 0x5bb: jg     aba <generic_sleepable_preload+0xaba> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5bb, 0xaba, x86_l_aba);
x86_l_5c1:
	/* 0x5c1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5c9:
	/* 0x5c9: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cc:
	/* 0x5cc: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5cc, 0xe71, x86_l_e71);
x86_l_5d2:
	/* 0x5d2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5d8:
	/* 0x5d8: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d8, 0xe71, x86_l_e71);
x86_l_5de:
	/* 0x5de: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0x5de, 0xe84, x86_l_e84);
x86_l_5e3:
	/* 0x5e3: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5e6:
	/* 0x5e6: jg     adc <generic_sleepable_preload+0xadc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5e6, 0xadc, x86_l_adc);
x86_l_5ec:
	/* 0x5ec: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5f4:
	/* 0x5f4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f7:
	/* 0x5f7: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f7, 0xf28, x86_l_f28);
x86_l_5fd:
	/* 0x5fd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_600:
	/* 0x600: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_603:
	/* 0x603: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x603, 0xf28, x86_l_f28);
x86_l_609:
	/* 0x609: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0x609, 0xf3b, x86_l_f3b);
x86_l_60e:
	/* 0x60e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_611:
	/* 0x611: jg     afe <generic_sleepable_preload+0xafe> */
	X86_SIM_X86_JCC(X86_CC_G, 0x611, 0xafe, x86_l_afe);
x86_l_617:
	/* 0x617: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_61f:
	/* 0x61f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_622:
	/* 0x622: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x622, 0xfdf, x86_l_fdf);
x86_l_628:
	/* 0x628: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_62e:
	/* 0x62e: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x62e, 0xfdf, x86_l_fdf);
x86_l_634:
	/* 0x634: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0x634, 0xff2, x86_l_ff2);
x86_l_639:
	/* 0x639: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_63c:
	/* 0x63c: jg     b20 <generic_sleepable_preload+0xb20> */
	X86_SIM_X86_JCC(X86_CC_G, 0x63c, 0xb20, x86_l_b20);
x86_l_642:
	/* 0x642: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_64a:
	/* 0x64a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64d:
	/* 0x64d: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64d, 0xdcb, x86_l_dcb);
x86_l_653:
	/* 0x653: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_656:
	/* 0x656: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_659:
	/* 0x659: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x659, 0xdcb, x86_l_dcb);
x86_l_65f:
	/* 0x65f: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0x65f, 0xdde, x86_l_dde);
x86_l_664:
	/* 0x664: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_667:
	/* 0x667: jg     be7 <generic_sleepable_preload+0xbe7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x667, 0xbe7, x86_l_be7);
x86_l_66d:
	/* 0x66d: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_672:
	/* 0x672: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_675:
	/* 0x675: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x675, 0xca0, x86_l_ca0);
x86_l_67b:
	/* 0x67b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_680:
	/* 0x680: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_683:
	/* 0x683: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x683, 0xca0, x86_l_ca0);
x86_l_689:
	/* 0x689: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JMP(0x689, 0xcb3, x86_l_cb3);
x86_l_68e:
	/* 0x68e: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_691:
	/* 0x691: jg     c08 <generic_sleepable_preload+0xc08> */
	X86_SIM_X86_JCC(X86_CC_G, 0x691, 0xc08, x86_l_c08);
x86_l_697:
	/* 0x697: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_69c:
	/* 0x69c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_69f:
	/* 0x69f: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69f, 0xe71, x86_l_e71);
x86_l_6a5:
	/* 0x6a5: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6aa:
	/* 0x6aa: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6ad:
	/* 0x6ad: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ad, 0xe71, x86_l_e71);
x86_l_6b3:
	/* 0x6b3: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0x6b3, 0xe84, x86_l_e84);
x86_l_6b8:
	/* 0x6b8: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6bb:
	/* 0x6bb: jg     c29 <generic_sleepable_preload+0xc29> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6bb, 0xc29, x86_l_c29);
x86_l_6c1:
	/* 0x6c1: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6c6:
	/* 0x6c6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6c9:
	/* 0x6c9: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c9, 0xf28, x86_l_f28);
x86_l_6cf:
	/* 0x6cf: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6d4:
	/* 0x6d4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6d7:
	/* 0x6d7: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d7, 0xf28, x86_l_f28);
x86_l_6dd:
	/* 0x6dd: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0x6dd, 0xf3b, x86_l_f3b);
x86_l_6e2:
	/* 0x6e2: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6e5:
	/* 0x6e5: jg     c4a <generic_sleepable_preload+0xc4a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e5, 0xc4a, x86_l_c4a);
x86_l_6eb:
	/* 0x6eb: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6f0:
	/* 0x6f0: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6f3:
	/* 0x6f3: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f3, 0xfdf, x86_l_fdf);
x86_l_6f9:
	/* 0x6f9: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6fe:
	/* 0x6fe: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_701:
	/* 0x701: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x701, 0xfdf, x86_l_fdf);
x86_l_707:
	/* 0x707: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0x707, 0xff2, x86_l_ff2);
x86_l_70c:
	/* 0x70c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_70f:
	/* 0x70f: jg     c6b <generic_sleepable_preload+0xc6b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x70f, 0xc6b, x86_l_c6b);
x86_l_715:
	/* 0x715: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_71a:
	/* 0x71a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_71d:
	/* 0x71d: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71d, 0xdcb, x86_l_dcb);
x86_l_723:
	/* 0x723: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_728:
	/* 0x728: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_72b:
	/* 0x72b: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72b, 0xdcb, x86_l_dcb);
x86_l_731:
	/* 0x731: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0x731, 0xdde, x86_l_dde);
x86_l_736:
	/* 0x736: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_73b:
	/* 0x73b: jmp    794 <generic_sleepable_preload+0x794> */
	X86_SIM_X86_JMP(0x73b, 0x794, x86_l_794);
x86_l_73d:
	/* 0x73d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_742:
	/* 0x742: jmp    82b <generic_sleepable_preload+0x82b> */
	X86_SIM_X86_JMP(0x742, 0x82b, x86_l_82b);
x86_l_747:
	/* 0x747: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_74c:
	/* 0x74c: jmp    8c2 <generic_sleepable_preload+0x8c2> */
	X86_SIM_X86_JMP(0x74c, 0x8c2, x86_l_8c2);
x86_l_751:
	/* 0x751: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_756:
	/* 0x756: jmp    959 <generic_sleepable_preload+0x959> */
	X86_SIM_X86_JMP(0x756, 0x959, x86_l_959);
x86_l_75b:
	/* 0x75b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_760:
	/* 0x760: jmp    9f0 <generic_sleepable_preload+0x9f0> */
	X86_SIM_X86_JMP(0x760, 0x9f0, x86_l_9f0);
x86_l_765:
	/* 0x765: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_769:
	/* 0x769: jmp    797 <generic_sleepable_preload+0x797> */
	X86_SIM_X86_JMP(0x769, 0x797, x86_l_797);
x86_l_76b:
	/* 0x76b: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76f:
	/* 0x76f: jmp    82e <generic_sleepable_preload+0x82e> */
	X86_SIM_X86_JMP(0x76f, 0x82e, x86_l_82e);
x86_l_774:
	/* 0x774: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_778:
	/* 0x778: jmp    8c5 <generic_sleepable_preload+0x8c5> */
	X86_SIM_X86_JMP(0x778, 0x8c5, x86_l_8c5);
x86_l_77d:
	/* 0x77d: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_781:
	/* 0x781: jmp    95c <generic_sleepable_preload+0x95c> */
	X86_SIM_X86_JMP(0x781, 0x95c, x86_l_95c);
x86_l_786:
	/* 0x786: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78a:
	/* 0x78a: jmp    9f3 <generic_sleepable_preload+0x9f3> */
	X86_SIM_X86_JMP(0x78a, 0x9f3, x86_l_9f3);
x86_l_78f:
	/* 0x78f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_794:
	/* 0x794: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_797:
	/* 0x797: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79b:
	/* 0x79b: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79f:
	/* 0x79f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7a2:
	/* 0x7a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7a7:
	/* 0x7a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7ac:
	/* 0x7ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b1:
	/* 0x7b1: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_7b4:
	/* 0x7b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b6:
	/* 0x7b6: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_7ba:
	/* 0x7ba: jne    dd <generic_sleepable_preload+0xdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ba, 0xdd, x86_l_dd);
x86_l_7c0:
	/* 0x7c0: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c4:
	/* 0x7c4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_7c9:
	/* 0x7c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cb:
	/* 0x7cb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d0:
	/* 0x7d0: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_7d8:
	/* 0x7d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_7df:
	/* 0x7df: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7e4:
	/* 0x7e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e9:
	/* 0x7e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7eb:
	/* 0x7eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ee:
	/* 0x7ee: je     dd <generic_sleepable_preload+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ee, 0xdd, x86_l_dd);
x86_l_7f4:
	/* 0x7f4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_7f7:
	/* 0x7f7: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7fc:
	/* 0x7fc: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_803:
	/* 0x803: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_805:
	/* 0x805: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_808:
	/* 0x808: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_80d:
	/* 0x80d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_812:
	/* 0x812: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_815:
	/* 0x815: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_818:
	/* 0x818: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_81a:
	/* 0x81a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81c:
	/* 0x81c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_821:
	/* 0x821: jmp    d17 <generic_sleepable_preload+0xd17> */
	X86_SIM_X86_JMP(0x821, 0xd17, x86_l_d17);
x86_l_826:
	/* 0x826: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82b:
	/* 0x82b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82e:
	/* 0x82e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_832:
	/* 0x832: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_836:
	/* 0x836: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_839:
	/* 0x839: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_83e:
	/* 0x83e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_843:
	/* 0x843: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_848:
	/* 0x848: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_84b:
	/* 0x84b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84d:
	/* 0x84d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_851:
	/* 0x851: jne    e7 <generic_sleepable_preload+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x851, 0xe7, x86_l_e7);
x86_l_857:
	/* 0x857: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85b:
	/* 0x85b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_860:
	/* 0x860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_862:
	/* 0x862: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_867:
	/* 0x867: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_86f:
	/* 0x86f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_876:
	/* 0x876: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_87b:
	/* 0x87b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_880:
	/* 0x880: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_882:
	/* 0x882: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_885:
	/* 0x885: je     e7 <generic_sleepable_preload+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x885, 0xe7, x86_l_e7);
x86_l_88b:
	/* 0x88b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_88e:
	/* 0x88e: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_893:
	/* 0x893: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_89a:
	/* 0x89a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_89c:
	/* 0x89c: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_89f:
	/* 0x89f: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a4:
	/* 0x8a4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8a9:
	/* 0x8a9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_8ac:
	/* 0x8ac: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_8af:
	/* 0x8af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b1:
	/* 0x8b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b3:
	/* 0x8b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b8:
	/* 0x8b8: jmp    ee8 <generic_sleepable_preload+0xee8> */
	X86_SIM_X86_JMP(0x8b8, 0xee8, x86_l_ee8);
x86_l_8bd:
	/* 0x8bd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8c2:
	/* 0x8c2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c5:
	/* 0x8c5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c9:
	/* 0x8c9: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_8cd:
	/* 0x8cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8d0:
	/* 0x8d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8d5:
	/* 0x8d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8da:
	/* 0x8da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8df:
	/* 0x8df: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_8e2:
	/* 0x8e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e4:
	/* 0x8e4: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_8e8:
	/* 0x8e8: jne    f5 <generic_sleepable_preload+0xf5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e8, 0xf5, x86_l_f5);
x86_l_8ee:
	/* 0x8ee: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f2:
	/* 0x8f2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_8f7:
	/* 0x8f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f9:
	/* 0x8f9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8fe:
	/* 0x8fe: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_906:
	/* 0x906: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_90d:
	/* 0x90d: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_912:
	/* 0x912: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_917:
	/* 0x917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_919:
	/* 0x919: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_91c:
	/* 0x91c: je     f5 <generic_sleepable_preload+0xf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91c, 0xf5, x86_l_f5);
x86_l_922:
	/* 0x922: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_925:
	/* 0x925: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_92a:
	/* 0x92a: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_931:
	/* 0x931: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_933:
	/* 0x933: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_936:
	/* 0x936: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93b:
	/* 0x93b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_940:
	/* 0x940: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_943:
	/* 0x943: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_946:
	/* 0x946: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_948:
	/* 0x948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94a:
	/* 0x94a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_94f:
	/* 0x94f: jmp    f9f <generic_sleepable_preload+0xf9f> */
	X86_SIM_X86_JMP(0x94f, 0xf9f, x86_l_f9f);
x86_l_954:
	/* 0x954: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_959:
	/* 0x959: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95c:
	/* 0x95c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_960:
	/* 0x960: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_964:
	/* 0x964: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_967:
	/* 0x967: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_96c:
	/* 0x96c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_971:
	/* 0x971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_976:
	/* 0x976: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_979:
	/* 0x979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97b:
	/* 0x97b: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_97f:
	/* 0x97f: jne    103 <generic_sleepable_preload+0x103> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x97f, 0x103, x86_l_103);
x86_l_985:
	/* 0x985: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_989:
	/* 0x989: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_98e:
	/* 0x98e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_990:
	/* 0x990: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_995:
	/* 0x995: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_99d:
	/* 0x99d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_9a4:
	/* 0x9a4: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_9a9:
	/* 0x9a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9ae:
	/* 0x9ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b0:
	/* 0x9b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b3:
	/* 0x9b3: je     103 <generic_sleepable_preload+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b3, 0x103, x86_l_103);
x86_l_9b9:
	/* 0x9b9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9bc:
	/* 0x9bc: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9c1:
	/* 0x9c1: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_9c8:
	/* 0x9c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ca:
	/* 0x9ca: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_9cd:
	/* 0x9cd: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d2:
	/* 0x9d2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9d7:
	/* 0x9d7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9da:
	/* 0x9da: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_9dd:
	/* 0x9dd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9df:
	/* 0x9df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e1:
	/* 0x9e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e6:
	/* 0x9e6: jmp    1056 <generic_sleepable_preload+0x1056> */
	X86_SIM_X86_JMP(0x9e6, 0x1056, x86_l_1056);
x86_l_9eb:
	/* 0x9eb: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9f0:
	/* 0x9f0: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f3:
	/* 0x9f3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f7:
	/* 0x9f7: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_9fa:
	/* 0x9fa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9fd:
	/* 0x9fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a02:
	/* 0xa02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a07:
	/* 0xa07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0c:
	/* 0xa0c: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_a0f:
	/* 0xa0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a11:
	/* 0xa11: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_a14:
	/* 0xa14: jne    111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa14, 0x111, x86_l_111);
x86_l_a1a:
	/* 0xa1a: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1e:
	/* 0xa1e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a23:
	/* 0xa23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a25:
	/* 0xa25: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2a:
	/* 0xa2a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_a32:
	/* 0xa32: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_a39:
	/* 0xa39: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a3e:
	/* 0xa3e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a43:
	/* 0xa43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a45:
	/* 0xa45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a48:
	/* 0xa48: je     111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa48, 0x111, x86_l_111);
x86_l_a4e:
	/* 0xa4e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a51:
	/* 0xa51: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_a58:
	/* 0xa58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5a:
	/* 0xa5a: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a5f:
	/* 0xa5f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a64:
	/* 0xa64: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a6a:
	/* 0xa6a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a6c:
	/* 0xa6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6e:
	/* 0xa6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a73:
	/* 0xa73: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a76:
	/* 0xa76: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a79:
	/* 0xa79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7b:
	/* 0xa7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7e:
	/* 0xa7e: je     111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7e, 0x111, x86_l_111);
x86_l_a84:
	/* 0xa84: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a87:
	/* 0xa87: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a8b:
	/* 0xa8b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a90:
	/* 0xa90: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a93:
	/* 0xa93: jmp    e5a <generic_sleepable_preload+0xe5a> */
	X86_SIM_X86_JMP(0xa93, 0xe5a, x86_l_e5a);
x86_l_a98:
	/* 0xa98: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_aa0:
	/* 0xaa0: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_aa3:
	/* 0xaa3: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa3, 0xca0, x86_l_ca0);
x86_l_aa9:
	/* 0xaa9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_aac:
	/* 0xaac: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_aaf:
	/* 0xaaf: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaaf, 0xca0, x86_l_ca0);
x86_l_ab5:
	/* 0xab5: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JMP(0xab5, 0xcb3, x86_l_cb3);
x86_l_aba:
	/* 0xaba: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ac2:
	/* 0xac2: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ac5:
	/* 0xac5: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac5, 0xe71, x86_l_e71);
x86_l_acb:
	/* 0xacb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ace:
	/* 0xace: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ad1:
	/* 0xad1: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad1, 0xe71, x86_l_e71);
x86_l_ad7:
	/* 0xad7: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0xad7, 0xe84, x86_l_e84);
x86_l_adc:
	/* 0xadc: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ae4:
	/* 0xae4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ae7:
	/* 0xae7: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae7, 0xf28, x86_l_f28);
x86_l_aed:
	/* 0xaed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_af0:
	/* 0xaf0: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_af3:
	/* 0xaf3: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf3, 0xf28, x86_l_f28);
x86_l_af9:
	/* 0xaf9: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0xaf9, 0xf3b, x86_l_f3b);
x86_l_afe:
	/* 0xafe: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b06:
	/* 0xb06: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_b09:
	/* 0xb09: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb09, 0xfdf, x86_l_fdf);
x86_l_b0f:
	/* 0xb0f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b12:
	/* 0xb12: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b15:
	/* 0xb15: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb15, 0xfdf, x86_l_fdf);
x86_l_b1b:
	/* 0xb1b: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0xb1b, 0xff2, x86_l_ff2);
x86_l_b20:
	/* 0xb20: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b28:
	/* 0xb28: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_b2b:
	/* 0xb2b: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2b, 0xdcb, x86_l_dcb);
x86_l_b31:
	/* 0xb31: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_b34:
	/* 0xb34: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b37:
	/* 0xb37: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb37, 0xdcb, x86_l_dcb);
x86_l_b3d:
	/* 0xb3d: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0xb3d, 0xdde, x86_l_dde);
x86_l_b42:
	/* 0xb42: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b47:
	/* 0xb47: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b4a:
	/* 0xb4a: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb4a, 0xca0, x86_l_ca0);
x86_l_b50:
	/* 0xb50: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b55:
	/* 0xb55: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b58:
	/* 0xb58: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb58, 0xca0, x86_l_ca0);
x86_l_b5e:
	/* 0xb5e: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JMP(0xb5e, 0xcb3, x86_l_cb3);
x86_l_b63:
	/* 0xb63: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b68:
	/* 0xb68: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b6b:
	/* 0xb6b: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6b, 0xe71, x86_l_e71);
x86_l_b71:
	/* 0xb71: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b76:
	/* 0xb76: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b79:
	/* 0xb79: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb79, 0xe71, x86_l_e71);
x86_l_b7f:
	/* 0xb7f: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0xb7f, 0xe84, x86_l_e84);
x86_l_b84:
	/* 0xb84: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b89:
	/* 0xb89: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b8c:
	/* 0xb8c: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb8c, 0xf28, x86_l_f28);
x86_l_b92:
	/* 0xb92: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b97:
	/* 0xb97: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b9a:
	/* 0xb9a: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9a, 0xf28, x86_l_f28);
x86_l_ba0:
	/* 0xba0: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0xba0, 0xf3b, x86_l_f3b);
x86_l_ba5:
	/* 0xba5: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_baa:
	/* 0xbaa: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bad:
	/* 0xbad: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbad, 0xfdf, x86_l_fdf);
x86_l_bb3:
	/* 0xbb3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bb8:
	/* 0xbb8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bbb:
	/* 0xbbb: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbb, 0xfdf, x86_l_fdf);
x86_l_bc1:
	/* 0xbc1: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0xbc1, 0xff2, x86_l_ff2);
x86_l_bc6:
	/* 0xbc6: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bcb:
	/* 0xbcb: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bce:
	/* 0xbce: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbce, 0xdcb, x86_l_dcb);
x86_l_bd4:
	/* 0xbd4: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bd9:
	/* 0xbd9: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bdc:
	/* 0xbdc: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbdc, 0xdcb, x86_l_dcb);
x86_l_be2:
	/* 0xbe2: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0xbe2, 0xdde, x86_l_dde);
x86_l_be7:
	/* 0xbe7: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bec:
	/* 0xbec: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_bef:
	/* 0xbef: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbef, 0xca0, x86_l_ca0);
x86_l_bf5:
	/* 0xbf5: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bfa:
	/* 0xbfa: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_bfd:
	/* 0xbfd: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbfd, 0xca0, x86_l_ca0);
x86_l_c03:
	/* 0xc03: jmp    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JMP(0xc03, 0xcb3, x86_l_cb3);
x86_l_c08:
	/* 0xc08: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c0d:
	/* 0xc0d: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c10:
	/* 0xc10: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc10, 0xe71, x86_l_e71);
x86_l_c16:
	/* 0xc16: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c1b:
	/* 0xc1b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c1e:
	/* 0xc1e: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc1e, 0xe71, x86_l_e71);
x86_l_c24:
	/* 0xc24: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0xc24, 0xe84, x86_l_e84);
x86_l_c29:
	/* 0xc29: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c2e:
	/* 0xc2e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c31:
	/* 0xc31: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc31, 0xf28, x86_l_f28);
x86_l_c37:
	/* 0xc37: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c3c:
	/* 0xc3c: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c3f:
	/* 0xc3f: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3f, 0xf28, x86_l_f28);
x86_l_c45:
	/* 0xc45: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0xc45, 0xf3b, x86_l_f3b);
x86_l_c4a:
	/* 0xc4a: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c4f:
	/* 0xc4f: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c52:
	/* 0xc52: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc52, 0xfdf, x86_l_fdf);
x86_l_c58:
	/* 0xc58: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c5d:
	/* 0xc5d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c60:
	/* 0xc60: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc60, 0xfdf, x86_l_fdf);
x86_l_c66:
	/* 0xc66: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0xc66, 0xff2, x86_l_ff2);
x86_l_c6b:
	/* 0xc6b: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c70:
	/* 0xc70: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c73:
	/* 0xc73: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc73, 0xdcb, x86_l_dcb);
x86_l_c79:
	/* 0xc79: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c7e:
	/* 0xc7e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c81:
	/* 0xc81: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc81, 0xdcb, x86_l_dcb);
x86_l_c87:
	/* 0xc87: jmp    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JMP(0xc87, 0xdde, x86_l_dde);
x86_l_c8c:
	/* 0xc8c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c91:
	/* 0xc91: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c94:
	/* 0xc94: je     ca0 <generic_sleepable_preload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc94, 0xca0, x86_l_ca0);
x86_l_c96:
	/* 0xc96: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c9b:
	/* 0xc9b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_c9e:
	/* 0xc9e: jne    cb3 <generic_sleepable_preload+0xcb3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc9e, 0xcb3, x86_l_cb3);
x86_l_ca0:
	/* 0xca0: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_ca3:
	/* 0xca3: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_ca5:
	/* 0xca5: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_ca7:
	/* 0xca7: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_cac:
	/* 0xcac: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_cae:
	/* 0xcae: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_cb3:
	/* 0xcb3: cmp    DWORD PTR [rbx+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_cb7:
	/* 0xcb7: jne    dd <generic_sleepable_preload+0xdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcb7, 0xdd, x86_l_dd);
x86_l_cbd:
	/* 0xcbd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cc2:
	/* 0xcc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc4:
	/* 0xcc4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc9:
	/* 0xcc9: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd0:
	/* 0xcd0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_cd7:
	/* 0xcd7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_cda:
	/* 0xcda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdf:
	/* 0xcdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce1:
	/* 0xce1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce4:
	/* 0xce4: je     dd <generic_sleepable_preload+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce4, 0xdd, x86_l_dd);
x86_l_cea:
	/* 0xcea: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ced:
	/* 0xced: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cf2:
	/* 0xcf2: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_cf9:
	/* 0xcf9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cfb:
	/* 0xcfb: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_cfe:
	/* 0xcfe: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d03:
	/* 0xd03: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d08:
	/* 0xd08: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d0b:
	/* 0xd0b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_d0e:
	/* 0xd0e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d10:
	/* 0xd10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d12:
	/* 0xd12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d17:
	/* 0xd17: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d1a:
	/* 0xd1a: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d1f:
	/* 0xd1f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_d22:
	/* 0xd22: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_d25:
	/* 0xd25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d27:
	/* 0xd27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d2a:
	/* 0xd2a: je     dd <generic_sleepable_preload+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2a, 0xdd, x86_l_dd);
x86_l_d30:
	/* 0xd30: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d33:
	/* 0xd33: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d37:
	/* 0xd37: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d41:
	/* 0xd41: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_d44:
	/* 0xd44: call   d49 <generic_sleepable_preload+0xd49> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_d49:
	/* 0xd49: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_d4c:
	/* 0xd4c: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4f:
	/* 0xd4f: jmp    dd <generic_sleepable_preload+0xdd> */
	X86_SIM_X86_JMP(0xd4f, 0xdd, x86_l_dd);
x86_l_d54:
	/* 0xd54: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d59:
	/* 0xd59: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d5c:
	/* 0xd5c: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5c, 0xe71, x86_l_e71);
x86_l_d62:
	/* 0xd62: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d67:
	/* 0xd67: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d6a:
	/* 0xd6a: je     e71 <generic_sleepable_preload+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6a, 0xe71, x86_l_e71);
x86_l_d70:
	/* 0xd70: jmp    e84 <generic_sleepable_preload+0xe84> */
	X86_SIM_X86_JMP(0xd70, 0xe84, x86_l_e84);
x86_l_d75:
	/* 0xd75: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d7a:
	/* 0xd7a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d7d:
	/* 0xd7d: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7d, 0xf28, x86_l_f28);
x86_l_d83:
	/* 0xd83: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d88:
	/* 0xd88: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d8b:
	/* 0xd8b: je     f28 <generic_sleepable_preload+0xf28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd8b, 0xf28, x86_l_f28);
x86_l_d91:
	/* 0xd91: jmp    f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JMP(0xd91, 0xf3b, x86_l_f3b);
x86_l_d96:
	/* 0xd96: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d9b:
	/* 0xd9b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d9e:
	/* 0xd9e: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9e, 0xfdf, x86_l_fdf);
x86_l_da4:
	/* 0xda4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da9:
	/* 0xda9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_dac:
	/* 0xdac: je     fdf <generic_sleepable_preload+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdac, 0xfdf, x86_l_fdf);
x86_l_db2:
	/* 0xdb2: jmp    ff2 <generic_sleepable_preload+0xff2> */
	X86_SIM_X86_JMP(0xdb2, 0xff2, x86_l_ff2);
x86_l_db7:
	/* 0xdb7: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dbc:
	/* 0xdbc: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_dbf:
	/* 0xdbf: je     dcb <generic_sleepable_preload+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdbf, 0xdcb, x86_l_dcb);
x86_l_dc1:
	/* 0xdc1: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dc6:
	/* 0xdc6: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_dc9:
	/* 0xdc9: jne    dde <generic_sleepable_preload+0xdde> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdc9, 0xdde, x86_l_dde);
x86_l_dcb:
	/* 0xdcb: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_dce:
	/* 0xdce: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_dd0:
	/* 0xdd0: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_dd2:
	/* 0xdd2: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_dd7:
	/* 0xdd7: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_dd9:
	/* 0xdd9: bzhi   r15,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_dde:
	/* 0xdde: cmp    DWORD PTR [rbx+0x14],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_de2:
	/* 0xde2: jne    111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xde2, 0x111, x86_l_111);
x86_l_de8:
	/* 0xde8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ded:
	/* 0xded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_def:
	/* 0xdef: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df4:
	/* 0xdf4: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfb:
	/* 0xdfb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e02:
	/* 0xe02: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e05:
	/* 0xe05: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e0a:
	/* 0xe0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0c:
	/* 0xe0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e0f:
	/* 0xe0f: je     111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0f, 0x111, x86_l_111);
x86_l_e15:
	/* 0xe15: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e18:
	/* 0xe18: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e1f:
	/* 0xe1f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e21:
	/* 0xe21: lea    r14,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e26:
	/* 0xe26: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e2b:
	/* 0xe2b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e2e:
	/* 0xe2e: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e31:
	/* 0xe31: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e33:
	/* 0xe33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e35:
	/* 0xe35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3a:
	/* 0xe3a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e3d:
	/* 0xe3d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e40:
	/* 0xe40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e42:
	/* 0xe42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e45:
	/* 0xe45: je     111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe45, 0x111, x86_l_111);
x86_l_e4b:
	/* 0xe4b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_e52:
	/* 0xe52: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_e57:
	/* 0xe57: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e5a:
	/* 0xe5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5c:
	/* 0xe5c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e5f:
	/* 0xe5f: call   e64 <generic_sleepable_preload+0xe64> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_e64:
	/* 0xe64: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_e67:
	/* 0xe67: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e69:
	/* 0xe69: jmp    111 <generic_sleepable_preload+0x111> */
	X86_SIM_X86_JMP(0xe69, 0x111, x86_l_111);
x86_l_e6e:
	/* 0xe6e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e71:
	/* 0xe71: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_e74:
	/* 0xe74: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_e76:
	/* 0xe76: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_e78:
	/* 0xe78: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_e7d:
	/* 0xe7d: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_e7f:
	/* 0xe7f: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_e84:
	/* 0xe84: cmp    DWORD PTR [rbx+0x8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738374ULL);
x86_l_e88:
	/* 0xe88: jne    e7 <generic_sleepable_preload+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe88, 0xe7, x86_l_e7);
x86_l_e8e:
	/* 0xe8e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e93:
	/* 0xe93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e95:
	/* 0xe95: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9a:
	/* 0xe9a: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea1:
	/* 0xea1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_ea8:
	/* 0xea8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_eab:
	/* 0xeab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb0:
	/* 0xeb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb2:
	/* 0xeb2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eb5:
	/* 0xeb5: je     e7 <generic_sleepable_preload+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeb5, 0xe7, x86_l_e7);
x86_l_ebb:
	/* 0xebb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ebe:
	/* 0xebe: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ec3:
	/* 0xec3: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_eca:
	/* 0xeca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ecc:
	/* 0xecc: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_ecf:
	/* 0xecf: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed4:
	/* 0xed4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ed9:
	/* 0xed9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_edc:
	/* 0xedc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_edf:
	/* 0xedf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ee1:
	/* 0xee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee3:
	/* 0xee3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ee8:
	/* 0xee8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_eeb:
	/* 0xeeb: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ef0:
	/* 0xef0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_ef3:
	/* 0xef3: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_ef6:
	/* 0xef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef8:
	/* 0xef8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_efb:
	/* 0xefb: je     e7 <generic_sleepable_preload+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xefb, 0xe7, x86_l_e7);
x86_l_f01:
	/* 0xf01: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f04:
	/* 0xf04: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f08:
	/* 0xf08: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_f0d:
	/* 0xf0d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_f10:
	/* 0xf10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f12:
	/* 0xf12: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f15:
	/* 0xf15: call   f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_f1a:
	/* 0xf1a: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_f1d:
	/* 0xf1d: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f20:
	/* 0xf20: jmp    e7 <generic_sleepable_preload+0xe7> */
	X86_SIM_X86_JMP(0xf20, 0xe7, x86_l_e7);
x86_l_f25:
	/* 0xf25: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f28:
	/* 0xf28: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_f2b:
	/* 0xf2b: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_f2d:
	/* 0xf2d: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f2f:
	/* 0xf2f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_f34:
	/* 0xf34: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f36:
	/* 0xf36: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_f3b:
	/* 0xf3b: cmp    DWORD PTR [rbx+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_f3f:
	/* 0xf3f: jne    f5 <generic_sleepable_preload+0xf5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3f, 0xf5, x86_l_f5);
x86_l_f45:
	/* 0xf45: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f4a:
	/* 0xf4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4c:
	/* 0xf4c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f51:
	/* 0xf51: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f58:
	/* 0xf58: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_f5f:
	/* 0xf5f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f62:
	/* 0xf62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f67:
	/* 0xf67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f69:
	/* 0xf69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f6c:
	/* 0xf6c: je     f5 <generic_sleepable_preload+0xf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6c, 0xf5, x86_l_f5);
x86_l_f72:
	/* 0xf72: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f75:
	/* 0xf75: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f7a:
	/* 0xf7a: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_f81:
	/* 0xf81: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f83:
	/* 0xf83: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_f86:
	/* 0xf86: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8b:
	/* 0xf8b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f90:
	/* 0xf90: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f93:
	/* 0xf93: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_f96:
	/* 0xf96: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f98:
	/* 0xf98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9a:
	/* 0xf9a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f9f:
	/* 0xf9f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_fa2:
	/* 0xfa2: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fa7:
	/* 0xfa7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_faa:
	/* 0xfaa: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_fad:
	/* 0xfad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_faf:
	/* 0xfaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb2:
	/* 0xfb2: je     f5 <generic_sleepable_preload+0xf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb2, 0xf5, x86_l_f5);
x86_l_fb8:
	/* 0xfb8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fbb:
	/* 0xfbb: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fbf:
	/* 0xfbf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_fc4:
	/* 0xfc4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_fc7:
	/* 0xfc7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc9:
	/* 0xfc9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: call   fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_fd1:
	/* 0xfd1: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_fd4:
	/* 0xfd4: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd7:
	/* 0xfd7: jmp    f5 <generic_sleepable_preload+0xf5> */
	X86_SIM_X86_JMP(0xfd7, 0xf5, x86_l_f5);
x86_l_fdc:
	/* 0xfdc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_fdf:
	/* 0xfdf: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_fe2:
	/* 0xfe2: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_fe4:
	/* 0xfe4: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_fe6:
	/* 0xfe6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_feb:
	/* 0xfeb: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fed:
	/* 0xfed: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_ff2:
	/* 0xff2: cmp    DWORD PTR [rbx+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_ff6:
	/* 0xff6: jne    103 <generic_sleepable_preload+0x103> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff6, 0x103, x86_l_103);
x86_l_ffc:
	/* 0xffc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1001:
	/* 0x1001: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1003:
	/* 0x1003: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1008:
	/* 0x1008: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100f:
	/* 0x100f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1016:
	/* 0x1016: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1019:
	/* 0x1019: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_101e:
	/* 0x101e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1020:
	/* 0x1020: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1023:
	/* 0x1023: je     103 <generic_sleepable_preload+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1023, 0x103, x86_l_103);
x86_l_1029:
	/* 0x1029: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_102c:
	/* 0x102c: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1031:
	/* 0x1031: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1038:
	/* 0x1038: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_103a:
	/* 0x103a: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_103d:
	/* 0x103d: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1042:
	/* 0x1042: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1047:
	/* 0x1047: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_104a:
	/* 0x104a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_104d:
	/* 0x104d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104f:
	/* 0x104f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1051:
	/* 0x1051: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1056:
	/* 0x1056: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1059:
	/* 0x1059: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_105e:
	/* 0x105e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1061:
	/* 0x1061: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_1064:
	/* 0x1064: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1066:
	/* 0x1066: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1069:
	/* 0x1069: je     103 <generic_sleepable_preload+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1069, 0x103, x86_l_103);
x86_l_106f:
	/* 0x106f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1072:
	/* 0x1072: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1076:
	/* 0x1076: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_107b:
	/* 0x107b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_107e:
	/* 0x107e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1080:
	/* 0x1080: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1083:
	/* 0x1083: call   1088 <generic_sleepable_preload+0x1088> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1088:
	/* 0x1088: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_108b:
	/* 0x108b: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108e:
	/* 0x108e: jmp    103 <generic_sleepable_preload+0x103> */
	X86_SIM_X86_JMP(0x108e, 0x103, x86_l_103);
x86_l_1093:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
