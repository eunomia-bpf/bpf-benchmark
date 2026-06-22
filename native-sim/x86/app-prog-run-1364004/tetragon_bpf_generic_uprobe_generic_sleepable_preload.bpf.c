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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31, 0x10f, x86_l_10f);
x86_l_37:
	/* 0x37: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46:
	/* 0x46: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_52:
	/* 0x52: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b:
	/* 0x5b: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f:
	/* 0x5f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64:
	/* 0x64: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_68:
	/* 0x68: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6d:
	/* 0x6d: lea    rax,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_71:
	/* 0x71: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_76:
	/* 0x76: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7a:
	/* 0x7a: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_82:
	/* 0x82: lea    r13,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_86:
	/* 0x86: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_92:
	/* 0x92: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_96:
	/* 0x96: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9b:
	/* 0x9b: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9f:
	/* 0x9f: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a4:
	/* 0xa4: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a8:
	/* 0xa8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ad:
	/* 0xad: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1:
	/* 0xb1: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b6:
	/* 0xb6: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ba:
	/* 0xba: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bf:
	/* 0xbf: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c3:
	/* 0xc3: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c8:
	/* 0xc8: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc:
	/* 0xcc: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d1:
	/* 0xd1: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d4:
	/* 0xd4: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_d9:
	/* 0xd9: jne    120 <generic_sleepable_preload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd9, 0x120, x86_l_120);
x86_l_db:
	/* 0xdb: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_de:
	/* 0xde: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e3:
	/* 0xe3: jne    158 <generic_sleepable_preload+0x158> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe3, 0x158, x86_l_158);
x86_l_e5:
	/* 0xe5: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e8:
	/* 0xe8: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_ed:
	/* 0xed: jne    190 <generic_sleepable_preload+0x190> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xed, 0x190, x86_l_190);
x86_l_f3:
	/* 0xf3: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f6:
	/* 0xf6: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_fb:
	/* 0xfb: jne    1c8 <generic_sleepable_preload+0x1c8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb, 0x1c8, x86_l_1c8);
x86_l_101:
	/* 0x101: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_104:
	/* 0x104: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_109:
	/* 0x109: jne    200 <generic_sleepable_preload+0x200> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x109, 0x200, x86_l_200);
x86_l_10f:
	/* 0x10f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111:
	/* 0x111: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_118:
	/* 0x118: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11a:
	/* 0x11a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: jmp    1061 <generic_sleepable_preload+0x1061> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_120:
	/* 0x120: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_122:
	/* 0x122: js     238 <generic_sleepable_preload+0x238> */
	X86_SIM_X86_JCC(X86_CC_S, 0x122, 0x238, x86_l_238);
x86_l_128:
	/* 0x128: mov    eax,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12b:
	/* 0x12b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e:
	/* 0x12e: jle    4fe <generic_sleepable_preload+0x4fe> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x12e, 0x4fe, x86_l_4fe);
x86_l_134:
	/* 0x134: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_137:
	/* 0x137: je     72e <generic_sleepable_preload+0x72e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137, 0x72e, x86_l_72e);
x86_l_13d:
	/* 0x13d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_140:
	/* 0x140: je     75d <generic_sleepable_preload+0x75d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140, 0x75d, x86_l_75d);
x86_l_146:
	/* 0x146: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_149:
	/* 0x149: jne    798 <generic_sleepable_preload+0x798> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x149, 0x798, x86_l_798);
x86_l_14f:
	/* 0x14f: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153:
	/* 0x153: jmp    794 <generic_sleepable_preload+0x794> */
	X86_SIM_X86_JMP(0x153, 0x794, x86_l_794);
x86_l_158:
	/* 0x158: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_15a:
	/* 0x15a: js     298 <generic_sleepable_preload+0x298> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15a, 0x298, x86_l_298);
x86_l_160:
	/* 0x160: mov    eax,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_163:
	/* 0x163: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_166:
	/* 0x166: jle    519 <generic_sleepable_preload+0x519> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x166, 0x519, x86_l_519);
x86_l_16c:
	/* 0x16c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16f:
	/* 0x16f: je     735 <generic_sleepable_preload+0x735> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f, 0x735, x86_l_735);
x86_l_175:
	/* 0x175: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_178:
	/* 0x178: je     764 <generic_sleepable_preload+0x764> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178, 0x764, x86_l_764);
x86_l_17e:
	/* 0x17e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_181:
	/* 0x181: jne    842 <generic_sleepable_preload+0x842> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x181, 0x842, x86_l_842);
x86_l_187:
	/* 0x187: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b:
	/* 0x18b: jmp    83e <generic_sleepable_preload+0x83e> */
	X86_SIM_X86_JMP(0x18b, 0x83e, x86_l_83e);
x86_l_190:
	/* 0x190: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_192:
	/* 0x192: js     2f9 <generic_sleepable_preload+0x2f9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x192, 0x2f9, x86_l_2f9);
x86_l_198:
	/* 0x198: mov    eax,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b:
	/* 0x19b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19e:
	/* 0x19e: jle    534 <generic_sleepable_preload+0x534> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x19e, 0x534, x86_l_534);
x86_l_1a4:
	/* 0x1a4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a7:
	/* 0x1a7: je     73f <generic_sleepable_preload+0x73f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a7, 0x73f, x86_l_73f);
x86_l_1ad:
	/* 0x1ad: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1b0:
	/* 0x1b0: je     76e <generic_sleepable_preload+0x76e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b0, 0x76e, x86_l_76e);
x86_l_1b6:
	/* 0x1b6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b9:
	/* 0x1b9: jne    8ec <generic_sleepable_preload+0x8ec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b9, 0x8ec, x86_l_8ec);
x86_l_1bf:
	/* 0x1bf: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3:
	/* 0x1c3: jmp    8e8 <generic_sleepable_preload+0x8e8> */
	X86_SIM_X86_JMP(0x1c3, 0x8e8, x86_l_8e8);
x86_l_1c8:
	/* 0x1c8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1ca:
	/* 0x1ca: js     359 <generic_sleepable_preload+0x359> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1ca, 0x359, x86_l_359);
x86_l_1d0:
	/* 0x1d0: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1d3:
	/* 0x1d3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d6:
	/* 0x1d6: jle    54f <generic_sleepable_preload+0x54f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1d6, 0x54f, x86_l_54f);
x86_l_1dc:
	/* 0x1dc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1df:
	/* 0x1df: je     749 <generic_sleepable_preload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1df, 0x749, x86_l_749);
x86_l_1e5:
	/* 0x1e5: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e8:
	/* 0x1e8: je     778 <generic_sleepable_preload+0x778> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e8, 0x778, x86_l_778);
x86_l_1ee:
	/* 0x1ee: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1:
	/* 0x1f1: jne    976 <generic_sleepable_preload+0x976> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f1, 0x976, x86_l_976);
x86_l_1f7:
	/* 0x1f7: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb:
	/* 0x1fb: jmp    972 <generic_sleepable_preload+0x972> */
	X86_SIM_X86_JMP(0x1fb, 0x972, x86_l_972);
x86_l_200:
	/* 0x200: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_202:
	/* 0x202: js     3b9 <generic_sleepable_preload+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x202, 0x3b9, x86_l_3b9);
x86_l_208:
	/* 0x208: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20b:
	/* 0x20b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20e:
	/* 0x20e: jle    56a <generic_sleepable_preload+0x56a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x20e, 0x56a, x86_l_56a);
x86_l_214:
	/* 0x214: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_217:
	/* 0x217: je     753 <generic_sleepable_preload+0x753> */
	X86_SIM_X86_JCC(X86_CC_E, 0x217, 0x753, x86_l_753);
x86_l_21d:
	/* 0x21d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_220:
	/* 0x220: je     782 <generic_sleepable_preload+0x782> */
	X86_SIM_X86_JCC(X86_CC_E, 0x220, 0x782, x86_l_782);
x86_l_226:
	/* 0x226: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_229:
	/* 0x229: jne    a00 <generic_sleepable_preload+0xa00> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x229, 0xa00, x86_l_a00);
x86_l_22f:
	/* 0x22f: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_233:
	/* 0x233: jmp    9fc <generic_sleepable_preload+0x9fc> */
	X86_SIM_X86_JMP(0x233, 0x9fc, x86_l_9fc);
x86_l_238:
	/* 0x238: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_23f:
	/* 0x23f: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_246:
	/* 0x246: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_24c:
	/* 0x24c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24e:
	/* 0x24e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_251:
	/* 0x251: jle    41a <generic_sleepable_preload+0x41a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x251, 0x41a, x86_l_41a);
x86_l_257:
	/* 0x257: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_25a:
	/* 0x25a: jle    585 <generic_sleepable_preload+0x585> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x25a, 0x585, x86_l_585);
x86_l_260:
	/* 0x260: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_263:
	/* 0x263: jle    c9a <generic_sleepable_preload+0xc9a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x263, 0xc9a, x86_l_c9a);
x86_l_269:
	/* 0x269: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26e:
	/* 0x26e: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_271:
	/* 0x271: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x271, 0xcae, x86_l_cae);
x86_l_277:
	/* 0x277: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27c:
	/* 0x27c: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27f:
	/* 0x27f: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27f, 0xcae, x86_l_cae);
x86_l_285:
	/* 0x285: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_288:
	/* 0x288: jne    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x288, 0xcc1, x86_l_cc1);
x86_l_28e:
	/* 0x28e: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_293:
	/* 0x293: jmp    cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JMP(0x293, 0xcae, x86_l_cae);
x86_l_298:
	/* 0x298: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_29f:
	/* 0x29f: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_2a6:
	/* 0x2a6: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2ac:
	/* 0x2ac: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2af:
	/* 0x2af: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2b2:
	/* 0x2b2: jle    44a <generic_sleepable_preload+0x44a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2b2, 0x44a, x86_l_44a);
x86_l_2b8:
	/* 0x2b8: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2bb:
	/* 0x2bb: jle    5b0 <generic_sleepable_preload+0x5b0> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2bb, 0x5b0, x86_l_5b0);
x86_l_2c1:
	/* 0x2c1: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2c4:
	/* 0x2c4: jle    d52 <generic_sleepable_preload+0xd52> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2c4, 0xd52, x86_l_d52);
x86_l_2ca:
	/* 0x2ca: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cf:
	/* 0x2cf: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_2d2:
	/* 0x2d2: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d2, 0xe6f, x86_l_e6f);
x86_l_2d8:
	/* 0x2d8: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2dd:
	/* 0x2dd: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_2e0:
	/* 0x2e0: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e0, 0xe6f, x86_l_e6f);
x86_l_2e6:
	/* 0x2e6: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2eb:
	/* 0x2eb: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2ee:
	/* 0x2ee: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ee, 0xe6f, x86_l_e6f);
x86_l_2f4:
	/* 0x2f4: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0x2f4, 0xe82, x86_l_e82);
x86_l_2f9:
	/* 0x2f9: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_300:
	/* 0x300: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_307:
	/* 0x307: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_30d:
	/* 0x30d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30f:
	/* 0x30f: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_312:
	/* 0x312: jle    477 <generic_sleepable_preload+0x477> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x312, 0x477, x86_l_477);
x86_l_318:
	/* 0x318: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_31b:
	/* 0x31b: jle    5db <generic_sleepable_preload+0x5db> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x31b, 0x5db, x86_l_5db);
x86_l_321:
	/* 0x321: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_324:
	/* 0x324: jle    d73 <generic_sleepable_preload+0xd73> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x324, 0xd73, x86_l_d73);
x86_l_32a:
	/* 0x32a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32f:
	/* 0x32f: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_332:
	/* 0x332: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x332, 0xf16, x86_l_f16);
x86_l_338:
	/* 0x338: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33d:
	/* 0x33d: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_340:
	/* 0x340: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x340, 0xf16, x86_l_f16);
x86_l_346:
	/* 0x346: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_34b:
	/* 0x34b: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_34e:
	/* 0x34e: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34e, 0xf16, x86_l_f16);
x86_l_354:
	/* 0x354: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0x354, 0xf29, x86_l_f29);
x86_l_359:
	/* 0x359: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_360:
	/* 0x360: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_367:
	/* 0x367: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_36d:
	/* 0x36d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36f:
	/* 0x36f: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_372:
	/* 0x372: jle    4a4 <generic_sleepable_preload+0x4a4> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x372, 0x4a4, x86_l_4a4);
x86_l_378:
	/* 0x378: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_37b:
	/* 0x37b: jle    606 <generic_sleepable_preload+0x606> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x37b, 0x606, x86_l_606);
x86_l_381:
	/* 0x381: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_384:
	/* 0x384: jle    d94 <generic_sleepable_preload+0xd94> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x384, 0xd94, x86_l_d94);
x86_l_38a:
	/* 0x38a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38f:
	/* 0x38f: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_392:
	/* 0x392: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x392, 0xfbd, x86_l_fbd);
x86_l_398:
	/* 0x398: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_39d:
	/* 0x39d: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_3a0:
	/* 0x3a0: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a0, 0xfbd, x86_l_fbd);
x86_l_3a6:
	/* 0x3a6: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3ab:
	/* 0x3ab: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3ae:
	/* 0x3ae: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ae, 0xfbd, x86_l_fbd);
x86_l_3b4:
	/* 0x3b4: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0x3b4, 0xfd0, x86_l_fd0);
x86_l_3b9:
	/* 0x3b9: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_3c0:
	/* 0x3c0: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_3c7:
	/* 0x3c7: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3cd:
	/* 0x3cd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d0:
	/* 0x3d0: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3d3:
	/* 0x3d3: jle    4d1 <generic_sleepable_preload+0x4d1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3d3, 0x4d1, x86_l_4d1);
x86_l_3d9:
	/* 0x3d9: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3dc:
	/* 0x3dc: jle    631 <generic_sleepable_preload+0x631> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3dc, 0x631, x86_l_631);
x86_l_3e2:
	/* 0x3e2: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3e5:
	/* 0x3e5: jle    db5 <generic_sleepable_preload+0xdb5> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3e5, 0xdb5, x86_l_db5);
x86_l_3eb:
	/* 0x3eb: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f0:
	/* 0x3f0: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_3f3:
	/* 0x3f3: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f3, 0xdc9, x86_l_dc9);
x86_l_3f9:
	/* 0x3f9: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3fe:
	/* 0x3fe: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_401:
	/* 0x401: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x401, 0xdc9, x86_l_dc9);
x86_l_407:
	/* 0x407: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40c:
	/* 0x40c: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_40f:
	/* 0x40f: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40f, 0xdc9, x86_l_dc9);
x86_l_415:
	/* 0x415: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0x415, 0xddc, x86_l_ddc);
x86_l_41a:
	/* 0x41a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_41d:
	/* 0x41d: jg     65c <generic_sleepable_preload+0x65c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x41d, 0x65c, x86_l_65c);
x86_l_423:
	/* 0x423: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_426:
	/* 0x426: jg     b50 <generic_sleepable_preload+0xb50> */
	X86_SIM_X86_JCC(X86_CC_G, 0x426, 0xb50, x86_l_b50);
x86_l_42c:
	/* 0x42c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_42f:
	/* 0x42f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_431:
	/* 0x431: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x431, 0xcae, x86_l_cae);
x86_l_437:
	/* 0x437: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_43c:
	/* 0x43c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_43f:
	/* 0x43f: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43f, 0xcae, x86_l_cae);
x86_l_445:
	/* 0x445: jmp    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JMP(0x445, 0xcc1, x86_l_cc1);
x86_l_44a:
	/* 0x44a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_44d:
	/* 0x44d: jg     686 <generic_sleepable_preload+0x686> */
	X86_SIM_X86_JCC(X86_CC_G, 0x44d, 0x686, x86_l_686);
x86_l_453:
	/* 0x453: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_456:
	/* 0x456: jg     b71 <generic_sleepable_preload+0xb71> */
	X86_SIM_X86_JCC(X86_CC_G, 0x456, 0xb71, x86_l_b71);
x86_l_45c:
	/* 0x45c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_45e:
	/* 0x45e: je     e6c <generic_sleepable_preload+0xe6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45e, 0xe6c, x86_l_e6c);
x86_l_464:
	/* 0x464: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_469:
	/* 0x469: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_46c:
	/* 0x46c: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46c, 0xe6f, x86_l_e6f);
x86_l_472:
	/* 0x472: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0x472, 0xe82, x86_l_e82);
x86_l_477:
	/* 0x477: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_47a:
	/* 0x47a: jg     6b0 <generic_sleepable_preload+0x6b0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x47a, 0x6b0, x86_l_6b0);
x86_l_480:
	/* 0x480: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_483:
	/* 0x483: jg     b92 <generic_sleepable_preload+0xb92> */
	X86_SIM_X86_JCC(X86_CC_G, 0x483, 0xb92, x86_l_b92);
x86_l_489:
	/* 0x489: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_48b:
	/* 0x48b: je     f13 <generic_sleepable_preload+0xf13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48b, 0xf13, x86_l_f13);
x86_l_491:
	/* 0x491: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_496:
	/* 0x496: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_499:
	/* 0x499: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x499, 0xf16, x86_l_f16);
x86_l_49f:
	/* 0x49f: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0x49f, 0xf29, x86_l_f29);
x86_l_4a4:
	/* 0x4a4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4a7:
	/* 0x4a7: jg     6da <generic_sleepable_preload+0x6da> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4a7, 0x6da, x86_l_6da);
x86_l_4ad:
	/* 0x4ad: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4b0:
	/* 0x4b0: jg     bb3 <generic_sleepable_preload+0xbb3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b0, 0xbb3, x86_l_bb3);
x86_l_4b6:
	/* 0x4b6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4b8:
	/* 0x4b8: je     fba <generic_sleepable_preload+0xfba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b8, 0xfba, x86_l_fba);
x86_l_4be:
	/* 0x4be: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c3:
	/* 0x4c3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4c6:
	/* 0x4c6: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c6, 0xfbd, x86_l_fbd);
x86_l_4cc:
	/* 0x4cc: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0x4cc, 0xfd0, x86_l_fd0);
x86_l_4d1:
	/* 0x4d1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4d4:
	/* 0x4d4: jg     704 <generic_sleepable_preload+0x704> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4d4, 0x704, x86_l_704);
x86_l_4da:
	/* 0x4da: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4dd:
	/* 0x4dd: jg     bd4 <generic_sleepable_preload+0xbd4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4dd, 0xbd4, x86_l_bd4);
x86_l_4e3:
	/* 0x4e3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4e5:
	/* 0x4e5: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e5, 0xdc9, x86_l_dc9);
x86_l_4eb:
	/* 0x4eb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ee:
	/* 0x4ee: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4f3:
	/* 0x4f3: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f3, 0xdc9, x86_l_dc9);
x86_l_4f9:
	/* 0x4f9: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0x4f9, 0xddc, x86_l_ddc);
x86_l_4fe:
	/* 0x4fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_500:
	/* 0x500: je     78c <generic_sleepable_preload+0x78c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x500, 0x78c, x86_l_78c);
x86_l_506:
	/* 0x506: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_509:
	/* 0x509: jne    798 <generic_sleepable_preload+0x798> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x509, 0x798, x86_l_798);
x86_l_50f:
	/* 0x50f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_514:
	/* 0x514: jmp    791 <generic_sleepable_preload+0x791> */
	X86_SIM_X86_JMP(0x514, 0x791, x86_l_791);
x86_l_519:
	/* 0x519: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51b:
	/* 0x51b: je     836 <generic_sleepable_preload+0x836> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51b, 0x836, x86_l_836);
x86_l_521:
	/* 0x521: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_524:
	/* 0x524: jne    842 <generic_sleepable_preload+0x842> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x524, 0x842, x86_l_842);
x86_l_52a:
	/* 0x52a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52f:
	/* 0x52f: jmp    83b <generic_sleepable_preload+0x83b> */
	X86_SIM_X86_JMP(0x52f, 0x83b, x86_l_83b);
x86_l_534:
	/* 0x534: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_536:
	/* 0x536: je     8e0 <generic_sleepable_preload+0x8e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x536, 0x8e0, x86_l_8e0);
x86_l_53c:
	/* 0x53c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53f:
	/* 0x53f: jne    8ec <generic_sleepable_preload+0x8ec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x53f, 0x8ec, x86_l_8ec);
x86_l_545:
	/* 0x545: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_54a:
	/* 0x54a: jmp    8e5 <generic_sleepable_preload+0x8e5> */
	X86_SIM_X86_JMP(0x54a, 0x8e5, x86_l_8e5);
x86_l_54f:
	/* 0x54f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551:
	/* 0x551: je     96a <generic_sleepable_preload+0x96a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x551, 0x96a, x86_l_96a);
x86_l_557:
	/* 0x557: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55a:
	/* 0x55a: jne    976 <generic_sleepable_preload+0x976> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x55a, 0x976, x86_l_976);
x86_l_560:
	/* 0x560: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_565:
	/* 0x565: jmp    96f <generic_sleepable_preload+0x96f> */
	X86_SIM_X86_JMP(0x565, 0x96f, x86_l_96f);
x86_l_56a:
	/* 0x56a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56c:
	/* 0x56c: je     9f4 <generic_sleepable_preload+0x9f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56c, 0x9f4, x86_l_9f4);
x86_l_572:
	/* 0x572: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_575:
	/* 0x575: jne    a00 <generic_sleepable_preload+0xa00> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x575, 0xa00, x86_l_a00);
x86_l_57b:
	/* 0x57b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_580:
	/* 0x580: jmp    9f9 <generic_sleepable_preload+0x9f9> */
	X86_SIM_X86_JMP(0x580, 0x9f9, x86_l_9f9);
x86_l_585:
	/* 0x585: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_588:
	/* 0x588: jg     a9c <generic_sleepable_preload+0xa9c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x588, 0xa9c, x86_l_a9c);
x86_l_58e:
	/* 0x58e: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_596:
	/* 0x596: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_599:
	/* 0x599: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x599, 0xcae, x86_l_cae);
x86_l_59f:
	/* 0x59f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5a2:
	/* 0x5a2: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5a5:
	/* 0x5a5: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a5, 0xcae, x86_l_cae);
x86_l_5ab:
	/* 0x5ab: jmp    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JMP(0x5ab, 0xcc1, x86_l_cc1);
x86_l_5b0:
	/* 0x5b0: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5b3:
	/* 0x5b3: jg     ac0 <generic_sleepable_preload+0xac0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5b3, 0xac0, x86_l_ac0);
x86_l_5b9:
	/* 0x5b9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5c1:
	/* 0x5c1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c4:
	/* 0x5c4: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c4, 0xe6f, x86_l_e6f);
x86_l_5ca:
	/* 0x5ca: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5cd:
	/* 0x5cd: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5d0:
	/* 0x5d0: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d0, 0xe6f, x86_l_e6f);
x86_l_5d6:
	/* 0x5d6: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0x5d6, 0xe82, x86_l_e82);
x86_l_5db:
	/* 0x5db: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5de:
	/* 0x5de: jg     ae4 <generic_sleepable_preload+0xae4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5de, 0xae4, x86_l_ae4);
x86_l_5e4:
	/* 0x5e4: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5ec:
	/* 0x5ec: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5ef:
	/* 0x5ef: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ef, 0xf16, x86_l_f16);
x86_l_5f5:
	/* 0x5f5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5f8:
	/* 0x5f8: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5fb:
	/* 0x5fb: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5fb, 0xf16, x86_l_f16);
x86_l_601:
	/* 0x601: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0x601, 0xf29, x86_l_f29);
x86_l_606:
	/* 0x606: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_609:
	/* 0x609: jg     b08 <generic_sleepable_preload+0xb08> */
	X86_SIM_X86_JCC(X86_CC_G, 0x609, 0xb08, x86_l_b08);
x86_l_60f:
	/* 0x60f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_617:
	/* 0x617: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61a:
	/* 0x61a: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61a, 0xfbd, x86_l_fbd);
x86_l_620:
	/* 0x620: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_623:
	/* 0x623: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_626:
	/* 0x626: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x626, 0xfbd, x86_l_fbd);
x86_l_62c:
	/* 0x62c: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0x62c, 0xfd0, x86_l_fd0);
x86_l_631:
	/* 0x631: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_634:
	/* 0x634: jg     b2c <generic_sleepable_preload+0xb2c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x634, 0xb2c, x86_l_b2c);
x86_l_63a:
	/* 0x63a: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_642:
	/* 0x642: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_645:
	/* 0x645: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x645, 0xdc9, x86_l_dc9);
x86_l_64b:
	/* 0x64b: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_651:
	/* 0x651: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x651, 0xdc9, x86_l_dc9);
x86_l_657:
	/* 0x657: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0x657, 0xddc, x86_l_ddc);
x86_l_65c:
	/* 0x65c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_65f:
	/* 0x65f: jg     bf5 <generic_sleepable_preload+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x65f, 0xbf5, x86_l_bf5);
x86_l_665:
	/* 0x665: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_66a:
	/* 0x66a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_66d:
	/* 0x66d: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66d, 0xcae, x86_l_cae);
x86_l_673:
	/* 0x673: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_678:
	/* 0x678: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_67b:
	/* 0x67b: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67b, 0xcae, x86_l_cae);
x86_l_681:
	/* 0x681: jmp    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JMP(0x681, 0xcc1, x86_l_cc1);
x86_l_686:
	/* 0x686: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_689:
	/* 0x689: jg     c16 <generic_sleepable_preload+0xc16> */
	X86_SIM_X86_JCC(X86_CC_G, 0x689, 0xc16, x86_l_c16);
x86_l_68f:
	/* 0x68f: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_694:
	/* 0x694: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_697:
	/* 0x697: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x697, 0xe6f, x86_l_e6f);
x86_l_69d:
	/* 0x69d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6a2:
	/* 0x6a2: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6a5:
	/* 0x6a5: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a5, 0xe6f, x86_l_e6f);
x86_l_6ab:
	/* 0x6ab: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0x6ab, 0xe82, x86_l_e82);
x86_l_6b0:
	/* 0x6b0: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6b3:
	/* 0x6b3: jg     c37 <generic_sleepable_preload+0xc37> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6b3, 0xc37, x86_l_c37);
x86_l_6b9:
	/* 0x6b9: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6be:
	/* 0x6be: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6c1:
	/* 0x6c1: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c1, 0xf16, x86_l_f16);
x86_l_6c7:
	/* 0x6c7: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6cc:
	/* 0x6cc: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6cf:
	/* 0x6cf: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6cf, 0xf16, x86_l_f16);
x86_l_6d5:
	/* 0x6d5: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0x6d5, 0xf29, x86_l_f29);
x86_l_6da:
	/* 0x6da: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6dd:
	/* 0x6dd: jg     c58 <generic_sleepable_preload+0xc58> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6dd, 0xc58, x86_l_c58);
x86_l_6e3:
	/* 0x6e3: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e8:
	/* 0x6e8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6eb:
	/* 0x6eb: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6eb, 0xfbd, x86_l_fbd);
x86_l_6f1:
	/* 0x6f1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6f6:
	/* 0x6f6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6f9:
	/* 0x6f9: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f9, 0xfbd, x86_l_fbd);
x86_l_6ff:
	/* 0x6ff: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0x6ff, 0xfd0, x86_l_fd0);
x86_l_704:
	/* 0x704: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_707:
	/* 0x707: jg     c79 <generic_sleepable_preload+0xc79> */
	X86_SIM_X86_JCC(X86_CC_G, 0x707, 0xc79, x86_l_c79);
x86_l_70d:
	/* 0x70d: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_712:
	/* 0x712: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_715:
	/* 0x715: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x715, 0xdc9, x86_l_dc9);
x86_l_71b:
	/* 0x71b: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_720:
	/* 0x720: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_723:
	/* 0x723: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x723, 0xdc9, x86_l_dc9);
x86_l_729:
	/* 0x729: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0x729, 0xddc, x86_l_ddc);
x86_l_72e:
	/* 0x72e: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_733:
	/* 0x733: jmp    791 <generic_sleepable_preload+0x791> */
	X86_SIM_X86_JMP(0x733, 0x791, x86_l_791);
x86_l_735:
	/* 0x735: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_73a:
	/* 0x73a: jmp    83b <generic_sleepable_preload+0x83b> */
	X86_SIM_X86_JMP(0x73a, 0x83b, x86_l_83b);
x86_l_73f:
	/* 0x73f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_744:
	/* 0x744: jmp    8e5 <generic_sleepable_preload+0x8e5> */
	X86_SIM_X86_JMP(0x744, 0x8e5, x86_l_8e5);
x86_l_749:
	/* 0x749: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_74e:
	/* 0x74e: jmp    96f <generic_sleepable_preload+0x96f> */
	X86_SIM_X86_JMP(0x74e, 0x96f, x86_l_96f);
x86_l_753:
	/* 0x753: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_758:
	/* 0x758: jmp    9f9 <generic_sleepable_preload+0x9f9> */
	X86_SIM_X86_JMP(0x758, 0x9f9, x86_l_9f9);
x86_l_75d:
	/* 0x75d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_762:
	/* 0x762: jmp    791 <generic_sleepable_preload+0x791> */
	X86_SIM_X86_JMP(0x762, 0x791, x86_l_791);
x86_l_764:
	/* 0x764: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_769:
	/* 0x769: jmp    83b <generic_sleepable_preload+0x83b> */
	X86_SIM_X86_JMP(0x769, 0x83b, x86_l_83b);
x86_l_76e:
	/* 0x76e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_773:
	/* 0x773: jmp    8e5 <generic_sleepable_preload+0x8e5> */
	X86_SIM_X86_JMP(0x773, 0x8e5, x86_l_8e5);
x86_l_778:
	/* 0x778: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_77d:
	/* 0x77d: jmp    96f <generic_sleepable_preload+0x96f> */
	X86_SIM_X86_JMP(0x77d, 0x96f, x86_l_96f);
x86_l_782:
	/* 0x782: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_787:
	/* 0x787: jmp    9f9 <generic_sleepable_preload+0x9f9> */
	X86_SIM_X86_JMP(0x787, 0x9f9, x86_l_9f9);
x86_l_78c:
	/* 0x78c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_791:
	/* 0x791: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_794:
	/* 0x794: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_798:
	/* 0x798: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79c:
	/* 0x79c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7a1:
	/* 0x7a1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7a4:
	/* 0x7a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a9:
	/* 0x7a9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_7b2:
	/* 0x7b2: jne    db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7b2, 0xdb, x86_l_db);
x86_l_7b8:
	/* 0x7b8: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bc:
	/* 0x7bc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_7c1:
	/* 0x7c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c3:
	/* 0x7c3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c8:
	/* 0x7c8: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_7d0:
	/* 0x7d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d5:
	/* 0x7d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_7dc:
	/* 0x7dc: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7e1:
	/* 0x7e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e3:
	/* 0x7e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e6:
	/* 0x7e6: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e6, 0xdb, x86_l_db);
x86_l_7ec:
	/* 0x7ec: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_7f2:
	/* 0x7f2: mov    rbp,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_7f9:
	/* 0x7f9: lea    r12,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fe:
	/* 0x7fe: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_801:
	/* 0x801: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_804:
	/* 0x804: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_807:
	/* 0x807: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_809:
	/* 0x809: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_80c:
	/* 0x80c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_811:
	/* 0x811: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_814:
	/* 0x814: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_817:
	/* 0x817: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_819:
	/* 0x819: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81c:
	/* 0x81c: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81c, 0xdb, x86_l_db);
x86_l_822:
	/* 0x822: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_825:
	/* 0x825: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_829:
	/* 0x829: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_82e:
	/* 0x82e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_831:
	/* 0x831: jmp    d3d <generic_sleepable_preload+0xd3d> */
	X86_SIM_X86_JMP(0x831, 0xd3d, x86_l_d3d);
x86_l_836:
	/* 0x836: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_83b:
	/* 0x83b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83e:
	/* 0x83e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_842:
	/* 0x842: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_846:
	/* 0x846: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84b:
	/* 0x84b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_84e:
	/* 0x84e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_853:
	/* 0x853: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_856:
	/* 0x856: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_858:
	/* 0x858: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_85c:
	/* 0x85c: jne    e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x85c, 0xe5, x86_l_e5);
x86_l_862:
	/* 0x862: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_866:
	/* 0x866: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_86b:
	/* 0x86b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86d:
	/* 0x86d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_872:
	/* 0x872: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_87a:
	/* 0x87a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_87f:
	/* 0x87f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_886:
	/* 0x886: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_88b:
	/* 0x88b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88d:
	/* 0x88d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_890:
	/* 0x890: je     e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x890, 0xe5, x86_l_e5);
x86_l_896:
	/* 0x896: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_89c:
	/* 0x89c: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_8a3:
	/* 0x8a3: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a8:
	/* 0x8a8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_8ae:
	/* 0x8ae: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_8b1:
	/* 0x8b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b3:
	/* 0x8b3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_8b6:
	/* 0x8b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8bb:
	/* 0x8bb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_8be:
	/* 0x8be: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_8c1:
	/* 0x8c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c3:
	/* 0x8c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c6:
	/* 0x8c6: je     e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c6, 0xe5, x86_l_e5);
x86_l_8cc:
	/* 0x8cc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_8cf:
	/* 0x8cf: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8d3:
	/* 0x8d3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_8d8:
	/* 0x8d8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: jmp    efe <generic_sleepable_preload+0xefe> */
	X86_SIM_X86_JMP(0x8db, 0xefe, x86_l_efe);
x86_l_8e0:
	/* 0x8e0: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8e5:
	/* 0x8e5: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e8:
	/* 0x8e8: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ec:
	/* 0x8ec: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_8f0:
	/* 0x8f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8f5:
	/* 0x8f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8f8:
	/* 0x8f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8fd:
	/* 0x8fd: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_900:
	/* 0x900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_902:
	/* 0x902: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_906:
	/* 0x906: jne    f3 <generic_sleepable_preload+0xf3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x906, 0xf3, x86_l_f3);
x86_l_90c:
	/* 0x90c: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_910:
	/* 0x910: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_915:
	/* 0x915: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_917:
	/* 0x917: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_91c:
	/* 0x91c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_924:
	/* 0x924: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_929:
	/* 0x929: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_930:
	/* 0x930: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_935:
	/* 0x935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_937:
	/* 0x937: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93a:
	/* 0x93a: je     f3 <generic_sleepable_preload+0xf3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93a, 0xf3, x86_l_f3);
x86_l_940:
	/* 0x940: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_946:
	/* 0x946: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_94d:
	/* 0x94d: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_952:
	/* 0x952: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_955:
	/* 0x955: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_958:
	/* 0x958: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_95b:
	/* 0x95b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_95d:
	/* 0x95d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_960:
	/* 0x960: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_965:
	/* 0x965: jmp    f85 <generic_sleepable_preload+0xf85> */
	X86_SIM_X86_JMP(0x965, 0xf85, x86_l_f85);
x86_l_96a:
	/* 0x96a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_96f:
	/* 0x96f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_972:
	/* 0x972: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_976:
	/* 0x976: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_97a:
	/* 0x97a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_97f:
	/* 0x97f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_982:
	/* 0x982: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_987:
	/* 0x987: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_98a:
	/* 0x98a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98c:
	/* 0x98c: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_990:
	/* 0x990: jne    101 <generic_sleepable_preload+0x101> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x990, 0x101, x86_l_101);
x86_l_996:
	/* 0x996: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99a:
	/* 0x99a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_99f:
	/* 0x99f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a1:
	/* 0x9a1: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a6:
	/* 0x9a6: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_9ae:
	/* 0x9ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9b3:
	/* 0x9b3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_9ba:
	/* 0x9ba: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_9bf:
	/* 0x9bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c1:
	/* 0x9c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c4:
	/* 0x9c4: je     101 <generic_sleepable_preload+0x101> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c4, 0x101, x86_l_101);
x86_l_9ca:
	/* 0x9ca: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_9d0:
	/* 0x9d0: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_9d7:
	/* 0x9d7: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9dc:
	/* 0x9dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9df:
	/* 0x9df: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_9e2:
	/* 0x9e2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9e5:
	/* 0x9e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9e7:
	/* 0x9e7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_9ea:
	/* 0x9ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9ef:
	/* 0x9ef: jmp    102c <generic_sleepable_preload+0x102c> */
	X86_SIM_X86_JMP(0x9ef, 0x102c, x86_l_102c);
x86_l_9f4:
	/* 0x9f4: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9f9:
	/* 0x9f9: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9fc:
	/* 0x9fc: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a00:
	/* 0xa00: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a03:
	/* 0xa03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a08:
	/* 0xa08: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a0b:
	/* 0xa0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a10:
	/* 0xa10: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_a13:
	/* 0xa13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a15:
	/* 0xa15: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_a18:
	/* 0xa18: jne    10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa18, 0x10f, x86_l_10f);
x86_l_a1e:
	/* 0xa1e: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a22:
	/* 0xa22: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a27:
	/* 0xa27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a29:
	/* 0xa29: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2e:
	/* 0xa2e: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_a36:
	/* 0xa36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a3b:
	/* 0xa3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_a42:
	/* 0xa42: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a47:
	/* 0xa47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a49:
	/* 0xa49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a4c:
	/* 0xa4c: je     10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa4c, 0x10f, x86_l_10f);
x86_l_a52:
	/* 0xa52: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_a58:
	/* 0xa58: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_a5f:
	/* 0xa5f: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a64:
	/* 0xa64: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a6a:
	/* 0xa6a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a6d:
	/* 0xa6d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a6f:
	/* 0xa6f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a72:
	/* 0xa72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a77:
	/* 0xa77: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a7d:
	/* 0xa7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7f:
	/* 0xa7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a82:
	/* 0xa82: je     10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa82, 0x10f, x86_l_10f);
x86_l_a88:
	/* 0xa88: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a8b:
	/* 0xa8b: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a8f:
	/* 0xa8f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a94:
	/* 0xa94: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a97:
	/* 0xa97: jmp    e58 <generic_sleepable_preload+0xe58> */
	X86_SIM_X86_JMP(0xa97, 0xe58, x86_l_e58);
x86_l_a9c:
	/* 0xa9c: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_aa4:
	/* 0xaa4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_aa7:
	/* 0xaa7: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa7, 0xcae, x86_l_cae);
x86_l_aad:
	/* 0xaad: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ab2:
	/* 0xab2: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ab5:
	/* 0xab5: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab5, 0xcae, x86_l_cae);
x86_l_abb:
	/* 0xabb: jmp    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JMP(0xabb, 0xcc1, x86_l_cc1);
x86_l_ac0:
	/* 0xac0: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ac8:
	/* 0xac8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_acb:
	/* 0xacb: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xacb, 0xe6f, x86_l_e6f);
x86_l_ad1:
	/* 0xad1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad6:
	/* 0xad6: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ad9:
	/* 0xad9: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad9, 0xe6f, x86_l_e6f);
x86_l_adf:
	/* 0xadf: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0xadf, 0xe82, x86_l_e82);
x86_l_ae4:
	/* 0xae4: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_aec:
	/* 0xaec: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_aef:
	/* 0xaef: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaef, 0xf16, x86_l_f16);
x86_l_af5:
	/* 0xaf5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_afa:
	/* 0xafa: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_afd:
	/* 0xafd: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xafd, 0xf16, x86_l_f16);
x86_l_b03:
	/* 0xb03: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0xb03, 0xf29, x86_l_f29);
x86_l_b08:
	/* 0xb08: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b10:
	/* 0xb10: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_b13:
	/* 0xb13: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb13, 0xfbd, x86_l_fbd);
x86_l_b19:
	/* 0xb19: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b1e:
	/* 0xb1e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b21:
	/* 0xb21: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb21, 0xfbd, x86_l_fbd);
x86_l_b27:
	/* 0xb27: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0xb27, 0xfd0, x86_l_fd0);
x86_l_b2c:
	/* 0xb2c: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b34:
	/* 0xb34: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_b37:
	/* 0xb37: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb37, 0xdc9, x86_l_dc9);
x86_l_b3d:
	/* 0xb3d: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b42:
	/* 0xb42: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b45:
	/* 0xb45: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb45, 0xdc9, x86_l_dc9);
x86_l_b4b:
	/* 0xb4b: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0xb4b, 0xddc, x86_l_ddc);
x86_l_b50:
	/* 0xb50: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b55:
	/* 0xb55: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b58:
	/* 0xb58: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb58, 0xcae, x86_l_cae);
x86_l_b5e:
	/* 0xb5e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b63:
	/* 0xb63: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b66:
	/* 0xb66: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb66, 0xcae, x86_l_cae);
x86_l_b6c:
	/* 0xb6c: jmp    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JMP(0xb6c, 0xcc1, x86_l_cc1);
x86_l_b71:
	/* 0xb71: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b76:
	/* 0xb76: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b79:
	/* 0xb79: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb79, 0xe6f, x86_l_e6f);
x86_l_b7f:
	/* 0xb7f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b84:
	/* 0xb84: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b87:
	/* 0xb87: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb87, 0xe6f, x86_l_e6f);
x86_l_b8d:
	/* 0xb8d: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0xb8d, 0xe82, x86_l_e82);
x86_l_b92:
	/* 0xb92: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b97:
	/* 0xb97: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b9a:
	/* 0xb9a: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9a, 0xf16, x86_l_f16);
x86_l_ba0:
	/* 0xba0: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ba5:
	/* 0xba5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ba8:
	/* 0xba8: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba8, 0xf16, x86_l_f16);
x86_l_bae:
	/* 0xbae: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0xbae, 0xf29, x86_l_f29);
x86_l_bb3:
	/* 0xbb3: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bb8:
	/* 0xbb8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bbb:
	/* 0xbbb: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbb, 0xfbd, x86_l_fbd);
x86_l_bc1:
	/* 0xbc1: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bc6:
	/* 0xbc6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bc9:
	/* 0xbc9: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc9, 0xfbd, x86_l_fbd);
x86_l_bcf:
	/* 0xbcf: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0xbcf, 0xfd0, x86_l_fd0);
x86_l_bd4:
	/* 0xbd4: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bd9:
	/* 0xbd9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bdc:
	/* 0xbdc: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbdc, 0xdc9, x86_l_dc9);
x86_l_be2:
	/* 0xbe2: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_be7:
	/* 0xbe7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bea:
	/* 0xbea: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbea, 0xdc9, x86_l_dc9);
x86_l_bf0:
	/* 0xbf0: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0xbf0, 0xddc, x86_l_ddc);
x86_l_bf5:
	/* 0xbf5: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bfa:
	/* 0xbfa: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_bfd:
	/* 0xbfd: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbfd, 0xcae, x86_l_cae);
x86_l_c03:
	/* 0xc03: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c08:
	/* 0xc08: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c0b:
	/* 0xc0b: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc0b, 0xcae, x86_l_cae);
x86_l_c11:
	/* 0xc11: jmp    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JMP(0xc11, 0xcc1, x86_l_cc1);
x86_l_c16:
	/* 0xc16: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c1b:
	/* 0xc1b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c1e:
	/* 0xc1e: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc1e, 0xe6f, x86_l_e6f);
x86_l_c24:
	/* 0xc24: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c29:
	/* 0xc29: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c2c:
	/* 0xc2c: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2c, 0xe6f, x86_l_e6f);
x86_l_c32:
	/* 0xc32: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0xc32, 0xe82, x86_l_e82);
x86_l_c37:
	/* 0xc37: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c3c:
	/* 0xc3c: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c3f:
	/* 0xc3f: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3f, 0xf16, x86_l_f16);
x86_l_c45:
	/* 0xc45: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c4a:
	/* 0xc4a: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c4d:
	/* 0xc4d: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4d, 0xf16, x86_l_f16);
x86_l_c53:
	/* 0xc53: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0xc53, 0xf29, x86_l_f29);
x86_l_c58:
	/* 0xc58: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c5d:
	/* 0xc5d: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c60:
	/* 0xc60: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc60, 0xfbd, x86_l_fbd);
x86_l_c66:
	/* 0xc66: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c6b:
	/* 0xc6b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c6e:
	/* 0xc6e: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc6e, 0xfbd, x86_l_fbd);
x86_l_c74:
	/* 0xc74: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0xc74, 0xfd0, x86_l_fd0);
x86_l_c79:
	/* 0xc79: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c7e:
	/* 0xc7e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c81:
	/* 0xc81: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc81, 0xdc9, x86_l_dc9);
x86_l_c87:
	/* 0xc87: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c8c:
	/* 0xc8c: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c8f:
	/* 0xc8f: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8f, 0xdc9, x86_l_dc9);
x86_l_c95:
	/* 0xc95: jmp    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JMP(0xc95, 0xddc, x86_l_ddc);
x86_l_c9a:
	/* 0xc9a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c9f:
	/* 0xc9f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ca2:
	/* 0xca2: je     cae <generic_sleepable_preload+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca2, 0xcae, x86_l_cae);
x86_l_ca4:
	/* 0xca4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca9:
	/* 0xca9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_cac:
	/* 0xcac: jne    cc1 <generic_sleepable_preload+0xcc1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcac, 0xcc1, x86_l_cc1);
x86_l_cae:
	/* 0xcae: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_cb1:
	/* 0xcb1: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_cb3:
	/* 0xcb3: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_cb5:
	/* 0xcb5: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_cba:
	/* 0xcba: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_cbc:
	/* 0xcbc: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_cc1:
	/* 0xcc1: cmp    DWORD PTR [rbx+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_cc5:
	/* 0xcc5: jne    db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc5, 0xdb, x86_l_db);
x86_l_ccb:
	/* 0xccb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cd0:
	/* 0xcd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd2:
	/* 0xcd2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd7:
	/* 0xcd7: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cde:
	/* 0xcde: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce3:
	/* 0xce3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_cea:
	/* 0xcea: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ced:
	/* 0xced: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cef:
	/* 0xcef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf2:
	/* 0xcf2: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf2, 0xdb, x86_l_db);
x86_l_cf8:
	/* 0xcf8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_cfe:
	/* 0xcfe: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_d05:
	/* 0xd05: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0a:
	/* 0xd0a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d0d:
	/* 0xd0d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d10:
	/* 0xd10: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d13:
	/* 0xd13: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d15:
	/* 0xd15: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d18:
	/* 0xd18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d1d:
	/* 0xd1d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d20:
	/* 0xd20: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d23:
	/* 0xd23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d25:
	/* 0xd25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d28:
	/* 0xd28: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd28, 0xdb, x86_l_db);
x86_l_d2e:
	/* 0xd2e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d31:
	/* 0xd31: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d35:
	/* 0xd35: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_d3a:
	/* 0xd3a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_d3d:
	/* 0xd3d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d3f:
	/* 0xd3f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_d42:
	/* 0xd42: call   d47 <generic_sleepable_preload+0xd47> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_d47:
	/* 0xd47: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_d4a:
	/* 0xd4a: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4d:
	/* 0xd4d: jmp    db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JMP(0xd4d, 0xdb, x86_l_db);
x86_l_d52:
	/* 0xd52: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d57:
	/* 0xd57: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d5a:
	/* 0xd5a: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5a, 0xe6f, x86_l_e6f);
x86_l_d60:
	/* 0xd60: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d65:
	/* 0xd65: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d68:
	/* 0xd68: je     e6f <generic_sleepable_preload+0xe6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd68, 0xe6f, x86_l_e6f);
x86_l_d6e:
	/* 0xd6e: jmp    e82 <generic_sleepable_preload+0xe82> */
	X86_SIM_X86_JMP(0xd6e, 0xe82, x86_l_e82);
x86_l_d73:
	/* 0xd73: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d78:
	/* 0xd78: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d7b:
	/* 0xd7b: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7b, 0xf16, x86_l_f16);
x86_l_d81:
	/* 0xd81: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d86:
	/* 0xd86: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d89:
	/* 0xd89: je     f16 <generic_sleepable_preload+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd89, 0xf16, x86_l_f16);
x86_l_d8f:
	/* 0xd8f: jmp    f29 <generic_sleepable_preload+0xf29> */
	X86_SIM_X86_JMP(0xd8f, 0xf29, x86_l_f29);
x86_l_d94:
	/* 0xd94: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d99:
	/* 0xd99: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d9c:
	/* 0xd9c: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9c, 0xfbd, x86_l_fbd);
x86_l_da2:
	/* 0xda2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da7:
	/* 0xda7: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_daa:
	/* 0xdaa: je     fbd <generic_sleepable_preload+0xfbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdaa, 0xfbd, x86_l_fbd);
x86_l_db0:
	/* 0xdb0: jmp    fd0 <generic_sleepable_preload+0xfd0> */
	X86_SIM_X86_JMP(0xdb0, 0xfd0, x86_l_fd0);
x86_l_db5:
	/* 0xdb5: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dba:
	/* 0xdba: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_dbd:
	/* 0xdbd: je     dc9 <generic_sleepable_preload+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdbd, 0xdc9, x86_l_dc9);
x86_l_dbf:
	/* 0xdbf: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dc4:
	/* 0xdc4: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_dc7:
	/* 0xdc7: jne    ddc <generic_sleepable_preload+0xddc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdc7, 0xddc, x86_l_ddc);
x86_l_dc9:
	/* 0xdc9: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_dcc:
	/* 0xdcc: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_dce:
	/* 0xdce: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_dd0:
	/* 0xdd0: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_dd5:
	/* 0xdd5: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_dd7:
	/* 0xdd7: bzhi   r15,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_ddc:
	/* 0xddc: cmp    DWORD PTR [rbx+0x14],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_de0:
	/* 0xde0: jne    10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xde0, 0x10f, x86_l_10f);
x86_l_de6:
	/* 0xde6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_deb:
	/* 0xdeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ded:
	/* 0xded: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df2:
	/* 0xdf2: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df9:
	/* 0xdf9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dfe:
	/* 0xdfe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e05:
	/* 0xe05: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e08:
	/* 0xe08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0a:
	/* 0xe0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e0d:
	/* 0xe0d: je     10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0d, 0x10f, x86_l_10f);
x86_l_e13:
	/* 0xe13: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_e19:
	/* 0xe19: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e20:
	/* 0xe20: lea    r14,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e25:
	/* 0xe25: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e28:
	/* 0xe28: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e2b:
	/* 0xe2b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e2e:
	/* 0xe2e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e30:
	/* 0xe30: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_e33:
	/* 0xe33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e38:
	/* 0xe38: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e3b:
	/* 0xe3b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e3e:
	/* 0xe3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e40:
	/* 0xe40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e43:
	/* 0xe43: je     10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe43, 0x10f, x86_l_10f);
x86_l_e49:
	/* 0xe49: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_e50:
	/* 0xe50: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_e55:
	/* 0xe55: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e58:
	/* 0xe58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5a:
	/* 0xe5a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e5d:
	/* 0xe5d: call   e62 <generic_sleepable_preload+0xe62> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_e62:
	/* 0xe62: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_e65:
	/* 0xe65: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e67:
	/* 0xe67: jmp    10f <generic_sleepable_preload+0x10f> */
	X86_SIM_X86_JMP(0xe67, 0x10f, x86_l_10f);
x86_l_e6c:
	/* 0xe6c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e6f:
	/* 0xe6f: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_e72:
	/* 0xe72: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_e74:
	/* 0xe74: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_e76:
	/* 0xe76: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_e7b:
	/* 0xe7b: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_e7d:
	/* 0xe7d: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_e82:
	/* 0xe82: cmp    DWORD PTR [rbx+0x8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738374ULL);
x86_l_e86:
	/* 0xe86: jne    e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe86, 0xe5, x86_l_e5);
x86_l_e8c:
	/* 0xe8c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e91:
	/* 0xe91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e93:
	/* 0xe93: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e98:
	/* 0xe98: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9f:
	/* 0xe9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea4:
	/* 0xea4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_eab:
	/* 0xeab: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_eae:
	/* 0xeae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb0:
	/* 0xeb0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eb3:
	/* 0xeb3: je     e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeb3, 0xe5, x86_l_e5);
x86_l_eb9:
	/* 0xeb9: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_ebf:
	/* 0xebf: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_ec6:
	/* 0xec6: lea    rbp,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecb:
	/* 0xecb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ece:
	/* 0xece: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_ed1:
	/* 0xed1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ed4:
	/* 0xed4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed6:
	/* 0xed6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_ed9:
	/* 0xed9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ede:
	/* 0xede: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ee1:
	/* 0xee1: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_ee4:
	/* 0xee4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee6:
	/* 0xee6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee9:
	/* 0xee9: je     e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee9, 0xe5, x86_l_e5);
x86_l_eef:
	/* 0xeef: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ef2:
	/* 0xef2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ef6:
	/* 0xef6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_efb:
	/* 0xefb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_efe:
	/* 0xefe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f00:
	/* 0xf00: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f03:
	/* 0xf03: call   f08 <generic_sleepable_preload+0xf08> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_f08:
	/* 0xf08: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_f0b:
	/* 0xf0b: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0e:
	/* 0xf0e: jmp    e5 <generic_sleepable_preload+0xe5> */
	X86_SIM_X86_JMP(0xf0e, 0xe5, x86_l_e5);
x86_l_f13:
	/* 0xf13: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f16:
	/* 0xf16: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_f19:
	/* 0xf19: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_f1b:
	/* 0xf1b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f1d:
	/* 0xf1d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_f22:
	/* 0xf22: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f24:
	/* 0xf24: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_f29:
	/* 0xf29: cmp    DWORD PTR [rbx+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_f2d:
	/* 0xf2d: jne    f3 <generic_sleepable_preload+0xf3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf2d, 0xf3, x86_l_f3);
x86_l_f33:
	/* 0xf33: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f38:
	/* 0xf38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3a:
	/* 0xf3a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3f:
	/* 0xf3f: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f46:
	/* 0xf46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f4b:
	/* 0xf4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_f52:
	/* 0xf52: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f55:
	/* 0xf55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f57:
	/* 0xf57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f5a:
	/* 0xf5a: je     f3 <generic_sleepable_preload+0xf3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5a, 0xf3, x86_l_f3);
x86_l_f60:
	/* 0xf60: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_f66:
	/* 0xf66: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_f6d:
	/* 0xf6d: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f72:
	/* 0xf72: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f75:
	/* 0xf75: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_f78:
	/* 0xf78: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7d:
	/* 0xf7d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_f80:
	/* 0xf80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f85:
	/* 0xf85: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f88:
	/* 0xf88: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_f8b:
	/* 0xf8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8d:
	/* 0xf8d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f90:
	/* 0xf90: je     f3 <generic_sleepable_preload+0xf3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf90, 0xf3, x86_l_f3);
x86_l_f96:
	/* 0xf96: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f99:
	/* 0xf99: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_f9d:
	/* 0xf9d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_fa2:
	/* 0xfa2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_fa5:
	/* 0xfa5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa7:
	/* 0xfa7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_faa:
	/* 0xfaa: call   faf <generic_sleepable_preload+0xfaf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_faf:
	/* 0xfaf: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_fb2:
	/* 0xfb2: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb5:
	/* 0xfb5: jmp    f3 <generic_sleepable_preload+0xf3> */
	X86_SIM_X86_JMP(0xfb5, 0xf3, x86_l_f3);
x86_l_fba:
	/* 0xfba: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_fbd:
	/* 0xfbd: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_fc0:
	/* 0xfc0: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_fc2:
	/* 0xfc2: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_fc4:
	/* 0xfc4: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_fc9:
	/* 0xfc9: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fcb:
	/* 0xfcb: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_fd0:
	/* 0xfd0: cmp    DWORD PTR [rbx+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_fd4:
	/* 0xfd4: jne    101 <generic_sleepable_preload+0x101> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd4, 0x101, x86_l_101);
x86_l_fda:
	/* 0xfda: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fdf:
	/* 0xfdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe1:
	/* 0xfe1: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe6:
	/* 0xfe6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fed:
	/* 0xfed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff2:
	/* 0xff2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_ff9:
	/* 0xff9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1001:
	/* 0x1001: je     101 <generic_sleepable_preload+0x101> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1001, 0x101, x86_l_101);
x86_l_1007:
	/* 0x1007: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_100d:
	/* 0x100d: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1014:
	/* 0x1014: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1019:
	/* 0x1019: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_101c:
	/* 0x101c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_101f:
	/* 0x101f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1022:
	/* 0x1022: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1024:
	/* 0x1024: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1027:
	/* 0x1027: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_102c:
	/* 0x102c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1034:
	/* 0x1034: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1037:
	/* 0x1037: je     101 <generic_sleepable_preload+0x101> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1037, 0x101, x86_l_101);
x86_l_103d:
	/* 0x103d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1040:
	/* 0x1040: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1044:
	/* 0x1044: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1049:
	/* 0x1049: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_104c:
	/* 0x104c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104e:
	/* 0x104e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1051:
	/* 0x1051: call   1056 <generic_sleepable_preload+0x1056> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1056:
	/* 0x1056: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1059:
	/* 0x1059: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105c:
	/* 0x105c: jmp    101 <generic_sleepable_preload+0x101> */
	X86_SIM_X86_JMP(0x105c, 0x101, x86_l_101);
x86_l_1061:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
