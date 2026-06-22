extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_tracepoint_generic_tracepoint_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_15:
	/* 0x15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     4f3 <generic_tracepoint_actions+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b, 0x4f3, x86_l_4f3);
x86_l_31:
	/* 0x31: mov    r13d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_38:
	/* 0x38: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_3c:
	/* 0x3c: jl     4f3 <generic_tracepoint_actions+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_L, 0x3c, 0x4f3, x86_l_4f3);
x86_l_42:
	/* 0x42: add    rax,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_48:
	/* 0x48: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d:
	/* 0x4d: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_54:
	/* 0x54: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_57:
	/* 0x57: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_59:
	/* 0x59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: je     4f3 <generic_tracepoint_actions+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x4f3, x86_l_4f3);
x86_l_62:
	/* 0x62: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_65:
	/* 0x65: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6b:
	/* 0x6b: add    r13d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6f:
	/* 0x6f: and    r13d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_76:
	/* 0x76: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_79:
	/* 0x79: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_81:
	/* 0x81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86:
	/* 0x86: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8d:
	/* 0x8d: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: je     bc <generic_tracepoint_actions+0xbc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97, 0xbc, x86_l_bc);
x86_l_99:
	/* 0x99: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c:
	/* 0x9c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_9f:
	/* 0x9f: je     d9 <generic_tracepoint_actions+0xd9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f, 0xd9, x86_l_d9);
x86_l_a1:
	/* 0xa1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a6:
	/* 0xa6: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_ab:
	/* 0xab: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_b0:
	/* 0xb0: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b5:
	/* 0xb5: ja     f3 <generic_tracepoint_actions+0xf3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb5, 0xf3, x86_l_f3);
x86_l_b7:
	/* 0xb7: jmp    4dd <generic_tracepoint_actions+0x4dd> */
	X86_SIM_X86_JMP(0xb7, 0x4dd, x86_l_4dd);
x86_l_bc:
	/* 0xbc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c1:
	/* 0xc1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c6:
	/* 0xc6: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_c8:
	/* 0xc8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cd:
	/* 0xcd: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d2:
	/* 0xd2: ja     f3 <generic_tracepoint_actions+0xf3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd2, 0xf3, x86_l_f3);
x86_l_d4:
	/* 0xd4: jmp    4dd <generic_tracepoint_actions+0x4dd> */
	X86_SIM_X86_JMP(0xd4, 0x4dd, x86_l_4dd);
x86_l_d9:
	/* 0xd9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_de:
	/* 0xde: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e3:
	/* 0xe3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e8:
	/* 0xe8: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ed:
	/* 0xed: jbe    4dd <generic_tracepoint_actions+0x4dd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xed, 0x4dd, x86_l_4dd);
x86_l_f3:
	/* 0xf3: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f8:
	/* 0xf8: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fd:
	/* 0xfd: mov    BYTE PTR [rsp+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_101:
	/* 0x101: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_106:
	/* 0x106: movsxd r15,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_10a:
	/* 0x10a: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_112:
	/* 0x112: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_117:
	/* 0x117: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_11e:
	/* 0x11e: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_123:
	/* 0x123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125:
	/* 0x125: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_128:
	/* 0x128: je     161 <generic_tracepoint_actions+0x161> */
	X86_SIM_X86_JCC(X86_CC_E, 0x128, 0x161, x86_l_161);
x86_l_12a:
	/* 0x12a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_12d:
	/* 0x12d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130:
	/* 0x130: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_133:
	/* 0x133: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_137:
	/* 0x137: jg     17e <generic_tracepoint_actions+0x17e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x137, 0x17e, x86_l_17e);
x86_l_139:
	/* 0x139: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_13d:
	/* 0x13d: jg     1b9 <generic_tracepoint_actions+0x1b9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13d, 0x1b9, x86_l_1b9);
x86_l_13f:
	/* 0x13f: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_143:
	/* 0x143: jg     243 <generic_tracepoint_actions+0x243> */
	X86_SIM_X86_JCC(X86_CC_G, 0x143, 0x243, x86_l_243);
x86_l_149:
	/* 0x149: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_14c:
	/* 0x14c: je     357 <generic_tracepoint_actions+0x357> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c, 0x357, x86_l_357);
x86_l_152:
	/* 0x152: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_156:
	/* 0x156: je     257 <generic_tracepoint_actions+0x257> */
	X86_SIM_X86_JCC(X86_CC_E, 0x156, 0x257, x86_l_257);
x86_l_15c:
	/* 0x15c: jmp    4bc <generic_tracepoint_actions+0x4bc> */
	X86_SIM_X86_JMP(0x15c, 0x4bc, x86_l_4bc);
x86_l_161:
	/* 0x161: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164:
	/* 0x164: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_167:
	/* 0x167: lea    eax,[r12*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_16f:
	/* 0x16f: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_173:
	/* 0x173: jae    4d8 <generic_tracepoint_actions+0x4d8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x173, 0x4d8, x86_l_4d8);
x86_l_179:
	/* 0x179: jmp    759 <generic_tracepoint_actions+0x759> */
	X86_SIM_X86_JMP(0x179, 0x759, x86_l_759);
x86_l_17e:
	/* 0x17e: cmp    r15d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 11ULL);
x86_l_182:
	/* 0x182: jg     215 <generic_tracepoint_actions+0x215> */
	X86_SIM_X86_JCC(X86_CC_G, 0x182, 0x215, x86_l_215);
x86_l_188:
	/* 0x188: lea    eax,[r15-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_18c:
	/* 0x18c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18f:
	/* 0x18f: jb     2ba <generic_tracepoint_actions+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_B, 0x18f, 0x2ba, x86_l_2ba);
x86_l_195:
	/* 0x195: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_199:
	/* 0x199: je     2c5 <generic_tracepoint_actions+0x2c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x199, 0x2c5, x86_l_2c5);
x86_l_19f:
	/* 0x19f: cmp    r15d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 9ULL);
x86_l_1a3:
	/* 0x1a3: jne    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a3, 0x4bf, x86_l_4bf);
x86_l_1a9:
	/* 0x1a9: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1af:
	/* 0x1af: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b4:
	/* 0x1b4: jmp    49a <generic_tracepoint_actions+0x49a> */
	X86_SIM_X86_JMP(0x1b4, 0x49a, x86_l_49a);
x86_l_1b9:
	/* 0x1b9: lea    eax,[r15-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1bd:
	/* 0x1bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c0:
	/* 0x1c0: jb     2b2 <generic_tracepoint_actions+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1c0, 0x2b2, x86_l_2b2);
x86_l_1c6:
	/* 0x1c6: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1ca:
	/* 0x1ca: je     2cf <generic_tracepoint_actions+0x2cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ca, 0x2cf, x86_l_2cf);
x86_l_1d0:
	/* 0x1d0: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_1d4:
	/* 0x1d4: jne    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d4, 0x4bf, x86_l_4bf);
x86_l_1da:
	/* 0x1da: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de:
	/* 0x1de: mov    r12d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1eb:
	/* 0x1eb: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f3:
	/* 0x1f3: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1f6:
	/* 0x1f6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f9:
	/* 0x1f9: ja     20a <generic_tracepoint_actions+0x20a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1f9, 0x20a, x86_l_20a);
x86_l_1fb:
	/* 0x1fb: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_204:
	/* 0x204: je     61a <generic_tracepoint_actions+0x61a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x204, 0x61a, x86_l_61a);
x86_l_20a:
	/* 0x20a: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_210:
	/* 0x210: jmp    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JMP(0x210, 0x4bf, x86_l_4bf);
x86_l_215:
	/* 0x215: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_219:
	/* 0x219: je     3bf <generic_tracepoint_actions+0x3bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x219, 0x3bf, x86_l_3bf);
x86_l_21f:
	/* 0x21f: cmp    r15d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 13ULL);
x86_l_223:
	/* 0x223: je     2df <generic_tracepoint_actions+0x2df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x2df, x86_l_2df);
x86_l_229:
	/* 0x229: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_22d:
	/* 0x22d: jne    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22d, 0x4bf, x86_l_4bf);
x86_l_233:
	/* 0x233: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_239:
	/* 0x239: mov    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_23e:
	/* 0x23e: jmp    49a <generic_tracepoint_actions+0x49a> */
	X86_SIM_X86_JMP(0x23e, 0x49a, x86_l_49a);
x86_l_243:
	/* 0x243: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_247:
	/* 0x247: je     3b5 <generic_tracepoint_actions+0x3b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x247, 0x3b5, x86_l_3b5);
x86_l_24d:
	/* 0x24d: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_251:
	/* 0x251: jne    4bc <generic_tracepoint_actions+0x4bc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x251, 0x4bc, x86_l_4bc);
x86_l_257:
	/* 0x257: mov    ebp,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b:
	/* 0x25b: mov    r12d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25f:
	/* 0x25f: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_268:
	/* 0x268: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_270:
	/* 0x270: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_278:
	/* 0x278: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27d:
	/* 0x27d: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_284:
	/* 0x284: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_289:
	/* 0x289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b:
	/* 0x28b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: je     2a7 <generic_tracepoint_actions+0x2a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28e, 0x2a7, x86_l_2a7);
x86_l_290:
	/* 0x290: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_293:
	/* 0x293: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_296:
	/* 0x296: ja     2a7 <generic_tracepoint_actions+0x2a7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x296, 0x2a7, x86_l_2a7);
x86_l_298:
	/* 0x298: cmp    DWORD PTR [r14+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_2a1:
	/* 0x2a1: je     504 <generic_tracepoint_actions+0x504> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a1, 0x504, x86_l_504);
x86_l_2a7:
	/* 0x2a7: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2ad:
	/* 0x2ad: jmp    4bc <generic_tracepoint_actions+0x4bc> */
	X86_SIM_X86_JMP(0x2ad, 0x4bc, x86_l_4bc);
x86_l_2b2:
	/* 0x2b2: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6:
	/* 0x2b6: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ba:
	/* 0x2ba: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2c0:
	/* 0x2c0: jmp    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JMP(0x2c0, 0x4bf, x86_l_4bf);
x86_l_2c5:
	/* 0x2c5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c7:
	/* 0x2c7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ca:
	/* 0x2ca: jmp    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JMP(0x2ca, 0x4bf, x86_l_4bf);
x86_l_2cf:
	/* 0x2cf: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2d5:
	/* 0x2d5: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2da:
	/* 0x2da: jmp    49a <generic_tracepoint_actions+0x49a> */
	X86_SIM_X86_JMP(0x2da, 0x49a, x86_l_49a);
x86_l_2df:
	/* 0x2df: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2e4:
	/* 0x2e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6:
	/* 0x2e6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eb:
	/* 0x2eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f0:
	/* 0x2f0: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_2f7:
	/* 0x2f7: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fc:
	/* 0x2fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe:
	/* 0x2fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_301:
	/* 0x301: je     4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x301, 0x4bf, x86_l_4bf);
x86_l_307:
	/* 0x307: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30b:
	/* 0x30b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_310:
	/* 0x310: mov    DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_318:
	/* 0x318: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31d:
	/* 0x31d: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_324:
	/* 0x324: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_329:
	/* 0x329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b:
	/* 0x32b: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_333:
	/* 0x333: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_336:
	/* 0x336: je     5b2 <generic_tracepoint_actions+0x5b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x336, 0x5b2, x86_l_5b2);
x86_l_33c:
	/* 0x33c: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_33f:
	/* 0x33f: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_344:
	/* 0x344: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_34b:
	/* 0x34b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_350:
	/* 0x350: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_352:
	/* 0x352: jmp    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JMP(0x352, 0x4bf, x86_l_4bf);
x86_l_357:
	/* 0x357: cmp    DWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35c:
	/* 0x35c: je     37d <generic_tracepoint_actions+0x37d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35c, 0x37d, x86_l_37d);
x86_l_35e:
	/* 0x35e: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_363:
	/* 0x363: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_368:
	/* 0x368: mov    rsi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_36f:
	/* 0x36f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_372:
	/* 0x372: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_374:
	/* 0x374: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376:
	/* 0x376: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_37d:
	/* 0x37d: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_383:
	/* 0x383: cmp    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_388:
	/* 0x388: je     4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x388, 0x4bf, x86_l_4bf);
x86_l_38e:
	/* 0x38e: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_393:
	/* 0x393: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_398:
	/* 0x398: mov    rsi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_39f:
	/* 0x39f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_3a4:
	/* 0x3a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3a7:
	/* 0x3a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a9:
	/* 0x3a9: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3b0:
	/* 0x3b0: jmp    4bf <generic_tracepoint_actions+0x4bf> */
	X86_SIM_X86_JMP(0x3b0, 0x4bf, x86_l_4bf);
x86_l_3b5:
	/* 0x3b5: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3ba:
	/* 0x3ba: jmp    49a <generic_tracepoint_actions+0x49a> */
	X86_SIM_X86_JMP(0x3ba, 0x49a, x86_l_49a);
x86_l_3bf:
	/* 0x3bf: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3c5:
	/* 0x3c5: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_3ca:
	/* 0x3ca: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_3cf:
	/* 0x3cf: je     49a <generic_tracepoint_actions+0x49a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cf, 0x49a, x86_l_49a);
x86_l_3d5:
	/* 0x3d5: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d9:
	/* 0x3d9: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd:
	/* 0x3dd: mov    ecx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e1:
	/* 0x3e1: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_3e5:
	/* 0x3e5: mov    DWORD PTR [rsp+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e9:
	/* 0x3e9: mov    DWORD PTR [rsp+0x40],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ed:
	/* 0x3ed: ja     3fe <generic_tracepoint_actions+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3ed, 0x3fe, x86_l_3fe);
x86_l_3ef:
	/* 0x3ef: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_3f8:
	/* 0x3f8: je     1230 <generic_tracepoint_actions+0x1230> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f8, 0x1230, x86_l_1230);
x86_l_3fe:
	/* 0x3fe: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: mov    eax,DWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_404:
	/* 0x404: shl    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_408:
	/* 0x408: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_40b:
	/* 0x40b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_410:
	/* 0x410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_417:
	/* 0x417: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_41b:
	/* 0x41b: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_420:
	/* 0x420: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_424:
	/* 0x424: mov    WORD PTR [rsp+0x1a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_429:
	/* 0x429: mov    QWORD PTR [rsp+0x1c],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_42e:
	/* 0x42e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_433:
	/* 0x433: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_43a:
	/* 0x43a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43f:
	/* 0x43f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_441:
	/* 0x441: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_444:
	/* 0x444: je     6c8 <generic_tracepoint_actions+0x6c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x444, 0x6c8, x86_l_6c8);
x86_l_44a:
	/* 0x44a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_44d:
	/* 0x44d: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_451:
	/* 0x451: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_456:
	/* 0x456: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_45e:
	/* 0x45e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_463:
	/* 0x463: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_46a:
	/* 0x46a: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_46f:
	/* 0x46f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_471:
	/* 0x471: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_479:
	/* 0x479: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47c:
	/* 0x47c: je     11c8 <generic_tracepoint_actions+0x11c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47c, 0x11c8, x86_l_11c8);
x86_l_482:
	/* 0x482: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_485:
	/* 0x485: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_489:
	/* 0x489: mov    DWORD PTR [rbp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48c:
	/* 0x48c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_491:
	/* 0x491: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_495:
	/* 0x495: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_49a:
	/* 0x49a: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a1:
	/* 0x4a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a6:
	/* 0x4a6: mov    rdi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_4ad:
	/* 0x4ad: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4b0:
	/* 0x4b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2:
	/* 0x4b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b5:
	/* 0x4b5: je     4bc <generic_tracepoint_actions+0x4bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b5, 0x4bc, x86_l_4bc);
x86_l_4b7:
	/* 0x4b7: inc QWORD PTR [rax+rbp*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBP, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4bc:
	/* 0x4bc: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4bf:
	/* 0x4bf: mov    QWORD PTR [r14+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4c3:
	/* 0x4c3: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4c6:
	/* 0x4c6: lea    eax,[r12*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_4ce:
	/* 0x4ce: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_4d2:
	/* 0x4d2: jb     759 <generic_tracepoint_actions+0x759> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4d2, 0x759, x86_l_759);
x86_l_4d8:
	/* 0x4d8: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_4db:
	/* 0x4db: je     4f3 <generic_tracepoint_actions+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4db, 0x4f3, x86_l_4f3);
x86_l_4dd:
	/* 0x4dd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4e2:
	/* 0x4e2: mov    rsi,QWORD PTR [rip+0x4d37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_4e9:
	/* 0x4e9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ec:
	/* 0x4ec: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4f1:
	/* 0x4f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f3:
	/* 0x4f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f5:
	/* 0x4f5: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_4fc:
	/* 0x4fc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4fe:
	/* 0x4fe: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4ff:
	/* 0x4ff: jmp    170c <generic_tracepoint_actions+0x170c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_504:
	/* 0x504: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_509:
	/* 0x509: mov    rax,QWORD PTR [r14+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_511:
	/* 0x511: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_519:
	/* 0x519: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_51e:
	/* 0x51e: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_526:
	/* 0x526: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a:
	/* 0x52a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_52f:
	/* 0x52f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_531:
	/* 0x531: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_535:
	/* 0x535: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_539:
	/* 0x539: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_53d:
	/* 0x53d: jne    728 <generic_tracepoint_actions+0x728> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x53d, 0x728, x86_l_728);
x86_l_543:
	/* 0x543: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_547:
	/* 0x547: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_54b:
	/* 0x54b: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_550:
	/* 0x550: ja     2a7 <generic_tracepoint_actions+0x2a7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x550, 0x2a7, x86_l_2a7);
x86_l_556:
	/* 0x556: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_55f:
	/* 0x55f: jne    2a7 <generic_tracepoint_actions+0x2a7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x55f, 0x2a7, x86_l_2a7);
x86_l_565:
	/* 0x565: mov    rax,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_56d:
	/* 0x56d: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_572:
	/* 0x572: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_576:
	/* 0x576: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_57d:
	/* 0x57d: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_582:
	/* 0x582: and    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_58a:
	/* 0x58a: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_58d:
	/* 0x58d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_592:
	/* 0x592: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_595:
	/* 0x595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597:
	/* 0x597: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_59c:
	/* 0x59c: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_5a3:
	/* 0x5a3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5a6:
	/* 0x5a6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5a9:
	/* 0x5a9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ab:
	/* 0x5ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ad:
	/* 0x5ad: jmp    2a7 <generic_tracepoint_actions+0x2a7> */
	X86_SIM_X86_JMP(0x5ad, 0x2a7, x86_l_2a7);
x86_l_5b2:
	/* 0x5b2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b7:
	/* 0x5b7: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_5be:
	/* 0x5be: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c3:
	/* 0x5c3: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5c8:
	/* 0x5c8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5cd:
	/* 0x5cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf:
	/* 0x5cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: je     33f <generic_tracepoint_actions+0x33f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d2, 0x33f, x86_l_33f);
x86_l_5d8:
	/* 0x5d8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5dd:
	/* 0x5dd: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5df:
	/* 0x5df: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e3:
	/* 0x5e3: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_5ea:
	/* 0x5ea: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_5f4:
	/* 0x5f4: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5f9:
	/* 0x5f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fe:
	/* 0x5fe: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_605:
	/* 0x605: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_608:
	/* 0x608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60a:
	/* 0x60a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: je     1399 <generic_tracepoint_actions+0x1399> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60d, 0x1399, x86_l_1399);
x86_l_613:
	/* 0x613: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_615:
	/* 0x615: jmp    13b9 <generic_tracepoint_actions+0x13b9> */
	X86_SIM_X86_JMP(0x615, 0x13b9, x86_l_13b9);
x86_l_61a:
	/* 0x61a: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_622:
	/* 0x622: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_627:
	/* 0x627: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_62f:
	/* 0x62f: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_633:
	/* 0x633: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_638:
	/* 0x638: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63a:
	/* 0x63a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_63e:
	/* 0x63e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_642:
	/* 0x642: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_647:
	/* 0x647: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_64e:
	/* 0x64e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_651:
	/* 0x651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_653:
	/* 0x653: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_656:
	/* 0x656: je     20a <generic_tracepoint_actions+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x656, 0x20a, x86_l_20a);
x86_l_65c:
	/* 0x65c: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_660:
	/* 0x660: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_664:
	/* 0x664: ja     20a <generic_tracepoint_actions+0x20a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x664, 0x20a, x86_l_20a);
x86_l_66a:
	/* 0x66a: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_673:
	/* 0x673: jne    20a <generic_tracepoint_actions+0x20a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x673, 0x20a, x86_l_20a);
x86_l_679:
	/* 0x679: mov    rcx,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_681:
	/* 0x681: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_689:
	/* 0x689: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_68f:
	/* 0x68f: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_697:
	/* 0x697: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69b:
	/* 0x69b: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_6a0:
	/* 0x6a0: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6a3:
	/* 0x6a3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6a5:
	/* 0x6a5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6a9:
	/* 0x6a9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ad:
	/* 0x6ad: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6b2:
	/* 0x6b2: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6b9:
	/* 0x6b9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6bc:
	/* 0x6bc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6bf:
	/* 0x6bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c1:
	/* 0x6c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c3:
	/* 0x6c3: jmp    20a <generic_tracepoint_actions+0x20a> */
	X86_SIM_X86_JMP(0x6c3, 0x20a, x86_l_20a);
x86_l_6c8:
	/* 0x6c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6cd:
	/* 0x6cd: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_6d4:
	/* 0x6d4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d9:
	/* 0x6d9: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6de:
	/* 0x6de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e0:
	/* 0x6e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e2:
	/* 0x6e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e5:
	/* 0x6e5: je     495 <generic_tracepoint_actions+0x495> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e5, 0x495, x86_l_495);
x86_l_6eb:
	/* 0x6eb: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6ed:
	/* 0x6ed: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f1:
	/* 0x6f1: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_6f8:
	/* 0x6f8: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_702:
	/* 0x702: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_707:
	/* 0x707: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_70c:
	/* 0x70c: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_713:
	/* 0x713: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_716:
	/* 0x716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_718:
	/* 0x718: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_71b:
	/* 0x71b: je     1466 <generic_tracepoint_actions+0x1466> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71b, 0x1466, x86_l_1466);
x86_l_721:
	/* 0x721: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_723:
	/* 0x723: jmp    495 <generic_tracepoint_actions+0x495> */
	X86_SIM_X86_JMP(0x723, 0x495, x86_l_495);
x86_l_728:
	/* 0x728: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_72d:
	/* 0x72d: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_734:
	/* 0x734: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_737:
	/* 0x737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_739:
	/* 0x739: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73c:
	/* 0x73c: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_73f:
	/* 0x73f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_741:
	/* 0x741: je     20a <generic_tracepoint_actions+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x741, 0x20a, x86_l_20a);
x86_l_747:
	/* 0x747: lea    eax,[r12*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_74f:
	/* 0x74f: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_753:
	/* 0x753: jae    4d8 <generic_tracepoint_actions+0x4d8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x753, 0x4d8, x86_l_4d8);
x86_l_759:
	/* 0x759: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_75d:
	/* 0x75d: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_760:
	/* 0x760: movsxd r15,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_765:
	/* 0x765: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_76d:
	/* 0x76d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_772:
	/* 0x772: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_779:
	/* 0x779: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_77e:
	/* 0x77e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_780:
	/* 0x780: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_782:
	/* 0x782: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_785:
	/* 0x785: je     cb7 <generic_tracepoint_actions+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x785, 0xcb7, x86_l_cb7);
x86_l_78b:
	/* 0x78b: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_78e:
	/* 0x78e: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_792:
	/* 0x792: jg     7bc <generic_tracepoint_actions+0x7bc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x792, 0x7bc, x86_l_7bc);
x86_l_794:
	/* 0x794: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_798:
	/* 0x798: jg     7f9 <generic_tracepoint_actions+0x7f9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x798, 0x7f9, x86_l_7f9);
x86_l_79a:
	/* 0x79a: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_79e:
	/* 0x79e: jg     93c <generic_tracepoint_actions+0x93c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x79e, 0x93c, x86_l_93c);
x86_l_7a4:
	/* 0x7a4: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_7a7:
	/* 0x7a7: je     b30 <generic_tracepoint_actions+0xb30> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a7, 0xb30, x86_l_b30);
x86_l_7ad:
	/* 0x7ad: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_7b1:
	/* 0x7b1: je     950 <generic_tracepoint_actions+0x950> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b1, 0x950, x86_l_950);
x86_l_7b7:
	/* 0x7b7: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0x7b7, 0xcad, x86_l_cad);
x86_l_7bc:
	/* 0x7bc: cmp    r15d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 11ULL);
x86_l_7c0:
	/* 0x7c0: jg     90b <generic_tracepoint_actions+0x90b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7c0, 0x90b, x86_l_90b);
x86_l_7c6:
	/* 0x7c6: lea    eax,[r15-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_7ca:
	/* 0x7ca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7cd:
	/* 0x7cd: jb     a7e <generic_tracepoint_actions+0xa7e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7cd, 0xa7e, x86_l_a7e);
x86_l_7d3:
	/* 0x7d3: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_7d7:
	/* 0x7d7: je     a97 <generic_tracepoint_actions+0xa97> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d7, 0xa97, x86_l_a97);
x86_l_7dd:
	/* 0x7dd: cmp    r15d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 9ULL);
x86_l_7e1:
	/* 0x7e1: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7e1, 0xcad, x86_l_cad);
x86_l_7e7:
	/* 0x7e7: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7ec:
	/* 0x7ec: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_7ef:
	/* 0x7ef: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7f4:
	/* 0x7f4: jmp    c86 <generic_tracepoint_actions+0xc86> */
	X86_SIM_X86_JMP(0x7f4, 0xc86, x86_l_c86);
x86_l_7f9:
	/* 0x7f9: lea    eax,[r15-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_7fd:
	/* 0x7fd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_800:
	/* 0x800: jb     a86 <generic_tracepoint_actions+0xa86> */
	X86_SIM_X86_JCC(X86_CC_B, 0x800, 0xa86, x86_l_a86);
x86_l_806:
	/* 0x806: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_80a:
	/* 0x80a: je     aa4 <generic_tracepoint_actions+0xaa4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80a, 0xaa4, x86_l_aa4);
x86_l_810:
	/* 0x810: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_814:
	/* 0x814: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x814, 0xcad, x86_l_cad);
x86_l_81a:
	/* 0x81a: mov    eax,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_81f:
	/* 0x81f: add    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_823:
	/* 0x823: mov    r14d,DWORD PTR [r13+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_828:
	/* 0x828: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_831:
	/* 0x831: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_839:
	/* 0x839: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_83c:
	/* 0x83c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_83f:
	/* 0x83f: ja     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_A, 0x83f, 0xcad, x86_l_cad);
x86_l_845:
	/* 0x845: cmp    DWORD PTR [r8+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_84e:
	/* 0x84e: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x84e, 0xcad, x86_l_cad);
x86_l_854:
	/* 0x854: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_85c:
	/* 0x85c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_861:
	/* 0x861: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_869:
	/* 0x869: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86d:
	/* 0x86d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_872:
	/* 0x872: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_875:
	/* 0x875: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_877:
	/* 0x877: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_87b:
	/* 0x87b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87f:
	/* 0x87f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_884:
	/* 0x884: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_88b:
	/* 0x88b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_88e:
	/* 0x88e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_890:
	/* 0x890: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_893:
	/* 0x893: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_896:
	/* 0x896: je     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x896, 0xcad, x86_l_cad);
x86_l_89c:
	/* 0x89c: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_8a0:
	/* 0x8a0: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_8a4:
	/* 0x8a4: ja     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8a4, 0xcad, x86_l_cad);
x86_l_8aa:
	/* 0x8aa: cmp    DWORD PTR [r8+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_8b3:
	/* 0x8b3: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b3, 0xcad, x86_l_cad);
x86_l_8b9:
	/* 0x8b9: mov    rcx,QWORD PTR [r8+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_8c1:
	/* 0x8c1: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_8c9:
	/* 0x8c9: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_8cf:
	/* 0x8cf: mov    ecx,DWORD PTR [r8+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_8d7:
	/* 0x8d7: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8db:
	/* 0x8db: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_8e0:
	/* 0x8e0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8e3:
	/* 0x8e3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_8e5:
	/* 0x8e5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_8e9:
	/* 0x8e9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ed:
	/* 0x8ed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8f2:
	/* 0x8f2: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_8f9:
	/* 0x8f9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8fc:
	/* 0x8fc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_8ff:
	/* 0x8ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_901:
	/* 0x901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_903:
	/* 0x903: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_906:
	/* 0x906: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0x906, 0xcad, x86_l_cad);
x86_l_90b:
	/* 0x90b: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_90f:
	/* 0x90f: je     ba9 <generic_tracepoint_actions+0xba9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90f, 0xba9, x86_l_ba9);
x86_l_915:
	/* 0x915: cmp    r15d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 13ULL);
x86_l_919:
	/* 0x919: je     ab6 <generic_tracepoint_actions+0xab6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x919, 0xab6, x86_l_ab6);
x86_l_91f:
	/* 0x91f: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_923:
	/* 0x923: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x923, 0xcad, x86_l_cad);
x86_l_929:
	/* 0x929: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_92e:
	/* 0x92e: add    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_932:
	/* 0x932: mov    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_937:
	/* 0x937: jmp    c86 <generic_tracepoint_actions+0xc86> */
	X86_SIM_X86_JMP(0x937, 0xc86, x86_l_c86);
x86_l_93c:
	/* 0x93c: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_940:
	/* 0x940: je     b9a <generic_tracepoint_actions+0xb9a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x940, 0xb9a, x86_l_b9a);
x86_l_946:
	/* 0x946: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_94a:
	/* 0x94a: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x94a, 0xcad, x86_l_cad);
x86_l_950:
	/* 0x950: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_955:
	/* 0x955: add    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_959:
	/* 0x959: mov    eax,DWORD PTR [r13+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_95e:
	/* 0x95e: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_963:
	/* 0x963: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_96c:
	/* 0x96c: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_974:
	/* 0x974: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_97c:
	/* 0x97c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_981:
	/* 0x981: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_988:
	/* 0x988: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_98d:
	/* 0x98d: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_992:
	/* 0x992: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_994:
	/* 0x994: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_999:
	/* 0x999: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99c:
	/* 0x99c: je     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99c, 0xcad, x86_l_cad);
x86_l_9a2:
	/* 0x9a2: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_9a6:
	/* 0x9a6: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_9aa:
	/* 0x9aa: ja     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9aa, 0xcad, x86_l_cad);
x86_l_9b0:
	/* 0x9b0: cmp    DWORD PTR [r8+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_9b9:
	/* 0x9b9: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b9, 0xcad, x86_l_cad);
x86_l_9bf:
	/* 0x9bf: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9c7:
	/* 0x9c7: mov    rax,QWORD PTR [r8+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_9cf:
	/* 0x9cf: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_9d7:
	/* 0x9d7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9dc:
	/* 0x9dc: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_9e4:
	/* 0x9e4: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e8:
	/* 0x9e8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9ed:
	/* 0x9ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ef:
	/* 0x9ef: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_9f3:
	/* 0x9f3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f7:
	/* 0x9f7: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_9fb:
	/* 0x9fb: jne    1310 <generic_tracepoint_actions+0x1310> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9fb, 0x1310, x86_l_1310);
x86_l_a01:
	/* 0xa01: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a06:
	/* 0xa06: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a09:
	/* 0xa09: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a0c:
	/* 0xa0c: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a14:
	/* 0xa14: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a19:
	/* 0xa19: ja     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa19, 0xcad, x86_l_cad);
x86_l_a1f:
	/* 0xa1f: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a22:
	/* 0xa22: cmp    DWORD PTR [r8+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_a2b:
	/* 0xa2b: jne    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa2b, 0xcad, x86_l_cad);
x86_l_a31:
	/* 0xa31: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_a39:
	/* 0xa39: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a3e:
	/* 0xa3e: lea    rdx,[r8+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a42:
	/* 0xa42: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a49:
	/* 0xa49: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_a4e:
	/* 0xa4e: and    esi,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R8, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_a56:
	/* 0xa56: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_a59:
	/* 0xa59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a5e:
	/* 0xa5e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a61:
	/* 0xa61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a63:
	/* 0xa63: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a68:
	/* 0xa68: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_a6f:
	/* 0xa6f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a72:
	/* 0xa72: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_a75:
	/* 0xa75: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a77:
	/* 0xa77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a79:
	/* 0xa79: jmp    ca8 <generic_tracepoint_actions+0xca8> */
	X86_SIM_X86_JMP(0xa79, 0xca8, x86_l_ca8);
x86_l_a7e:
	/* 0xa7e: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a81:
	/* 0xa81: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0xa81, 0xcad, x86_l_cad);
x86_l_a86:
	/* 0xa86: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a89:
	/* 0xa89: mov    eax,DWORD PTR [r13+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_a8e:
	/* 0xa8e: mov    DWORD PTR [r8+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a92:
	/* 0xa92: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0xa92, 0xcad, x86_l_cad);
x86_l_a97:
	/* 0xa97: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_a9f:
	/* 0xa9f: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0xa9f, 0xcad, x86_l_cad);
x86_l_aa4:
	/* 0xaa4: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa9:
	/* 0xaa9: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_aac:
	/* 0xaac: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ab1:
	/* 0xab1: jmp    c86 <generic_tracepoint_actions+0xc86> */
	X86_SIM_X86_JMP(0xab1, 0xc86, x86_l_c86);
x86_l_ab6:
	/* 0xab6: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_ab9:
	/* 0xab9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_abe:
	/* 0xabe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac0:
	/* 0xac0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ac5:
	/* 0xac5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aca:
	/* 0xaca: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_ad1:
	/* 0xad1: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad6:
	/* 0xad6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad8:
	/* 0xad8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_adb:
	/* 0xadb: je     b28 <generic_tracepoint_actions+0xb28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadb, 0xb28, x86_l_b28);
x86_l_add:
	/* 0xadd: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ae1:
	/* 0xae1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ae6:
	/* 0xae6: mov    DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_aee:
	/* 0xaee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af3:
	/* 0xaf3: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_afa:
	/* 0xafa: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aff:
	/* 0xaff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b01:
	/* 0xb01: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_b09:
	/* 0xb09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b0c:
	/* 0xb0c: je     1162 <generic_tracepoint_actions+0x1162> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0c, 0x1162, x86_l_1162);
x86_l_b12:
	/* 0xb12: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b15:
	/* 0xb15: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_b1a:
	/* 0xb1a: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_b21:
	/* 0xb21: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b26:
	/* 0xb26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b28:
	/* 0xb28: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_b2b:
	/* 0xb2b: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0xb2b, 0xcad, x86_l_cad);
x86_l_b30:
	/* 0xb30: cmp    DWORD PTR [r13+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_b36:
	/* 0xb36: je     b5d <generic_tracepoint_actions+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb36, 0xb5d, x86_l_b5d);
x86_l_b38:
	/* 0xb38: or     BYTE PTR [r8+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_b3d:
	/* 0xb3d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b42:
	/* 0xb42: mov    rsi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b49:
	/* 0xb49: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b4c:
	/* 0xb4c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4e:
	/* 0xb4e: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_b51:
	/* 0xb51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b53:
	/* 0xb53: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_b56:
	/* 0xb56: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b5d:
	/* 0xb5d: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b61:
	/* 0xb61: cmp    DWORD PTR [r13+r12*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 17179869184ULL);
x86_l_b67:
	/* 0xb67: je     cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb67, 0xcad, x86_l_cad);
x86_l_b6d:
	/* 0xb6d: or     BYTE PTR [r8+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_b72:
	/* 0xb72: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b77:
	/* 0xb77: mov    rsi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b7e:
	/* 0xb7e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_b83:
	/* 0xb83: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b86:
	/* 0xb86: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_b89:
	/* 0xb89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8b:
	/* 0xb8b: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_b8e:
	/* 0xb8e: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b95:
	/* 0xb95: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0xb95, 0xcad, x86_l_cad);
x86_l_b9a:
	/* 0xb9a: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b9f:
	/* 0xb9f: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ba4:
	/* 0xba4: jmp    c86 <generic_tracepoint_actions+0xc86> */
	X86_SIM_X86_JMP(0xba4, 0xc86, x86_l_c86);
x86_l_ba9:
	/* 0xba9: add    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_bad:
	/* 0xbad: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_bb2:
	/* 0xbb2: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_bb7:
	/* 0xbb7: mov    QWORD PTR [rsp+0x40],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bbc:
	/* 0xbbc: je     c86 <generic_tracepoint_actions+0xc86> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbc, 0xc86, x86_l_c86);
x86_l_bc2:
	/* 0xbc2: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_bc5:
	/* 0xbc5: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_bca:
	/* 0xbca: mov    ecx,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_bcf:
	/* 0xbcf: mov    ebp,DWORD PTR [r13+r14*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 12ULL);
x86_l_bd4:
	/* 0xbd4: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_bd8:
	/* 0xbd8: mov    DWORD PTR [rsp+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bdc:
	/* 0xbdc: ja     bed <generic_tracepoint_actions+0xbed> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbdc, 0xbed, x86_l_bed);
x86_l_bde:
	/* 0xbde: cmp    DWORD PTR [r8+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_be7:
	/* 0xbe7: je     144c <generic_tracepoint_actions+0x144c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe7, 0x144c, x86_l_144c);
x86_l_bed:
	/* 0xbed: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf0:
	/* 0xbf0: mov    eax,DWORD PTR [r8+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bf4:
	/* 0xbf4: shl    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_bf8:
	/* 0xbf8: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bfb:
	/* 0xbfb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_c00:
	/* 0xc00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c02:
	/* 0xc02: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c07:
	/* 0xc07: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c0b:
	/* 0xc0b: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c10:
	/* 0xc10: mov    WORD PTR [rsp+0x1a],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_c15:
	/* 0xc15: mov    QWORD PTR [rsp+0x1c],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_c1a:
	/* 0xc1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c1f:
	/* 0xc1f: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_c26:
	/* 0xc26: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c2b:
	/* 0xc2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2d:
	/* 0xc2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c30:
	/* 0xc30: je     124a <generic_tracepoint_actions+0x124a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc30, 0x124a, x86_l_124a);
x86_l_c36:
	/* 0xc36: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_c39:
	/* 0xc39: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c3d:
	/* 0xc3d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c42:
	/* 0xc42: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_c4a:
	/* 0xc4a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c4f:
	/* 0xc4f: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c56:
	/* 0xc56: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c5b:
	/* 0xc5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5d:
	/* 0xc5d: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_c65:
	/* 0xc65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c68:
	/* 0xc68: je     1333 <generic_tracepoint_actions+0x1333> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc68, 0x1333, x86_l_1333);
x86_l_c6e:
	/* 0xc6e: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c71:
	/* 0xc71: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c75:
	/* 0xc75: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c79:
	/* 0xc79: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c7e:
	/* 0xc7e: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c81:
	/* 0xc81: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_c86:
	/* 0xc86: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8d:
	/* 0xc8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c92:
	/* 0xc92: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_c99:
	/* 0xc99: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c9c:
	/* 0xc9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9e:
	/* 0xc9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca1:
	/* 0xca1: je     ca8 <generic_tracepoint_actions+0xca8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca1, 0xca8, x86_l_ca8);
x86_l_ca3:
	/* 0xca3: inc QWORD PTR [rax+rbp*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBP, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ca8:
	/* 0xca8: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cad:
	/* 0xcad: mov    QWORD PTR [r8+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cb1:
	/* 0xcb1: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cb4:
	/* 0xcb4: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_cb7:
	/* 0xcb7: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_cbe:
	/* 0xcbe: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_cc2:
	/* 0xcc2: jae    1150 <generic_tracepoint_actions+0x1150> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xcc2, 0x1150, x86_l_1150);
x86_l_cc8:
	/* 0xcc8: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_ccb:
	/* 0xccb: movsxd rbp,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_cd0:
	/* 0xcd0: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_cd8:
	/* 0xcd8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdd:
	/* 0xcdd: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ce4:
	/* 0xce4: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_ce9:
	/* 0xce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ceb:
	/* 0xceb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cee:
	/* 0xcee: je     1150 <generic_tracepoint_actions+0x1150> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcee, 0x1150, x86_l_1150);
x86_l_cf4:
	/* 0xcf4: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_cf7:
	/* 0xcf7: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_cfa:
	/* 0xcfa: jle    d24 <generic_tracepoint_actions+0xd24> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xcfa, 0xd24, x86_l_d24);
x86_l_cfc:
	/* 0xcfc: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_cff:
	/* 0xcff: jg     d48 <generic_tracepoint_actions+0xd48> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcff, 0xd48, x86_l_d48);
x86_l_d01:
	/* 0xd01: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_d04:
	/* 0xd04: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d07:
	/* 0xd07: jb     e60 <generic_tracepoint_actions+0xe60> */
	X86_SIM_X86_JCC(X86_CC_B, 0xd07, 0xe60, x86_l_e60);
x86_l_d0d:
	/* 0xd0d: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d10:
	/* 0xd10: je     f73 <generic_tracepoint_actions+0xf73> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd10, 0xf73, x86_l_f73);
x86_l_d16:
	/* 0xd16: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_d19:
	/* 0xd19: je     1125 <generic_tracepoint_actions+0x1125> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd19, 0x1125, x86_l_1125);
x86_l_d1f:
	/* 0xd1f: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0xd1f, 0x114c, x86_l_114c);
x86_l_d24:
	/* 0xd24: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d27:
	/* 0xd27: jg     d72 <generic_tracepoint_actions+0xd72> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd27, 0xd72, x86_l_d72);
x86_l_d29:
	/* 0xd29: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_d2b:
	/* 0xd2b: je     10c8 <generic_tracepoint_actions+0x10c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2b, 0x10c8, x86_l_10c8);
x86_l_d31:
	/* 0xd31: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_d34:
	/* 0xd34: je     e6e <generic_tracepoint_actions+0xe6e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd34, 0xe6e, x86_l_e6e);
x86_l_d3a:
	/* 0xd3a: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d3d:
	/* 0xd3d: je     1125 <generic_tracepoint_actions+0x1125> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd3d, 0x1125, x86_l_1125);
x86_l_d43:
	/* 0xd43: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0xd43, 0x114c, x86_l_114c);
x86_l_d48:
	/* 0xd48: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_d4b:
	/* 0xd4b: je     f80 <generic_tracepoint_actions+0xf80> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4b, 0xf80, x86_l_f80);
x86_l_d51:
	/* 0xd51: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_d54:
	/* 0xd54: je     1050 <generic_tracepoint_actions+0x1050> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd54, 0x1050, x86_l_1050);
x86_l_d5a:
	/* 0xd5a: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d5f:
	/* 0xd5f: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d64:
	/* 0xd64: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_d67:
	/* 0xd67: je     1125 <generic_tracepoint_actions+0x1125> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd67, 0x1125, x86_l_1125);
x86_l_d6d:
	/* 0xd6d: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0xd6d, 0x114c, x86_l_114c);
x86_l_d72:
	/* 0xd72: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_d75:
	/* 0xd75: je     e6e <generic_tracepoint_actions+0xe6e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd75, 0xe6e, x86_l_e6e);
x86_l_d7b:
	/* 0xd7b: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_d7e:
	/* 0xd7e: je     111b <generic_tracepoint_actions+0x111b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7e, 0x111b, x86_l_111b);
x86_l_d84:
	/* 0xd84: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d87:
	/* 0xd87: jne    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd87, 0x114c, x86_l_114c);
x86_l_d8d:
	/* 0xd8d: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_d92:
	/* 0xd92: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_d97:
	/* 0xd97: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_da0:
	/* 0xda0: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da8:
	/* 0xda8: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_dab:
	/* 0xdab: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dae:
	/* 0xdae: ja     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xdae, 0x114c, x86_l_114c);
x86_l_db4:
	/* 0xdb4: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_dbd:
	/* 0xdbd: jne    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdbd, 0x114c, x86_l_114c);
x86_l_dc3:
	/* 0xdc3: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_dcb:
	/* 0xdcb: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_dd0:
	/* 0xdd0: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_dd8:
	/* 0xdd8: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ddc:
	/* 0xddc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_de1:
	/* 0xde1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de3:
	/* 0xde3: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_de7:
	/* 0xde7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_deb:
	/* 0xdeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_df0:
	/* 0xdf0: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_df7:
	/* 0xdf7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_dfa:
	/* 0xdfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dfc:
	/* 0xdfc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dff:
	/* 0xdff: je     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdff, 0x114c, x86_l_114c);
x86_l_e05:
	/* 0xe05: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e09:
	/* 0xe09: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_e0d:
	/* 0xe0d: ja     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe0d, 0x114c, x86_l_114c);
x86_l_e13:
	/* 0xe13: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_e1c:
	/* 0xe1c: jne    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1c, 0x114c, x86_l_114c);
x86_l_e22:
	/* 0xe22: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_e2a:
	/* 0xe2a: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_e32:
	/* 0xe32: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e38:
	/* 0xe38: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e40:
	/* 0xe40: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e44:
	/* 0xe44: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_e49:
	/* 0xe49: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e4e:
	/* 0xe4e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e52:
	/* 0xe52: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e56:
	/* 0xe56: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e5b:
	/* 0xe5b: jmp    f5d <generic_tracepoint_actions+0xf5d> */
	X86_SIM_X86_JMP(0xe5b, 0xf5d, x86_l_f5d);
x86_l_e60:
	/* 0xe60: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_e65:
	/* 0xe65: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e69:
	/* 0xe69: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0xe69, 0x114c, x86_l_114c);
x86_l_e6e:
	/* 0xe6e: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_e73:
	/* 0xe73: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_e78:
	/* 0xe78: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e81:
	/* 0xe81: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e89:
	/* 0xe89: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e91:
	/* 0xe91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e96:
	/* 0xe96: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_e9d:
	/* 0xe9d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ea2:
	/* 0xea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea4:
	/* 0xea4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea7:
	/* 0xea7: je     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea7, 0x114c, x86_l_114c);
x86_l_ead:
	/* 0xead: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_eb1:
	/* 0xeb1: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_eb5:
	/* 0xeb5: ja     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xeb5, 0x114c, x86_l_114c);
x86_l_ebb:
	/* 0xebb: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_ec4:
	/* 0xec4: jne    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xec4, 0x114c, x86_l_114c);
x86_l_eca:
	/* 0xeca: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_ecd:
	/* 0xecd: mov    rax,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_ed5:
	/* 0xed5: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_edd:
	/* 0xedd: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ee2:
	/* 0xee2: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_eea:
	/* 0xeea: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eee:
	/* 0xeee: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ef3:
	/* 0xef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef5:
	/* 0xef5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ef9:
	/* 0xef9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_efd:
	/* 0xefd: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_f00:
	/* 0xf00: jne    14f1 <generic_tracepoint_actions+0x14f1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf00, 0x14f1, x86_l_14f1);
x86_l_f06:
	/* 0xf06: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f0a:
	/* 0xf0a: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_f0e:
	/* 0xf0e: ja     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf0e, 0x114c, x86_l_114c);
x86_l_f14:
	/* 0xf14: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_f1d:
	/* 0xf1d: jne    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf1d, 0x114c, x86_l_114c);
x86_l_f23:
	/* 0xf23: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_f26:
	/* 0xf26: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_f2e:
	/* 0xf2e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f33:
	/* 0xf33: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f37:
	/* 0xf37: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f3e:
	/* 0xf3e: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_f43:
	/* 0xf43: and    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_f4b:
	/* 0xf4b: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_f4e:
	/* 0xf4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f53:
	/* 0xf53: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f58:
	/* 0xf58: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f5d:
	/* 0xf5d: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_f64:
	/* 0xf64: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f67:
	/* 0xf67: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f6a:
	/* 0xf6a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f6c:
	/* 0xf6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6e:
	/* 0xf6e: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0xf6e, 0x114c, x86_l_114c);
x86_l_f73:
	/* 0xf73: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f7b:
	/* 0xf7b: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0xf7b, 0x114c, x86_l_114c);
x86_l_f80:
	/* 0xf80: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_f85:
	/* 0xf85: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f8a:
	/* 0xf8a: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_f8f:
	/* 0xf8f: je     1125 <generic_tracepoint_actions+0x1125> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8f, 0x1125, x86_l_1125);
x86_l_f95:
	/* 0xf95: mov    eax,DWORD PTR [r13+r15*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 16ULL);
x86_l_f9a:
	/* 0xf9a: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_f9f:
	/* 0xf9f: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_fa4:
	/* 0xfa4: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_fa8:
	/* 0xfa8: ja     fb9 <generic_tracepoint_actions+0xfb9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xfa8, 0xfb9, x86_l_fb9);
x86_l_faa:
	/* 0xfaa: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_fb3:
	/* 0xfb3: je     15b2 <generic_tracepoint_actions+0x15b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb3, 0x15b2, x86_l_15b2);
x86_l_fb9:
	/* 0xfb9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbb:
	/* 0xfbb: mov    r13d,DWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fbf:
	/* 0xfbf: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_fc2:
	/* 0xfc2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fc7:
	/* 0xfc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc9:
	/* 0xfc9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fce:
	/* 0xfce: mov    WORD PTR [rsp+0x18],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fd4:
	/* 0xfd4: mov    WORD PTR [rsp+0x1a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_fda:
	/* 0xfda: mov    QWORD PTR [rsp+0x1c],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_fdf:
	/* 0xfdf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fe4:
	/* 0xfe4: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_feb:
	/* 0xfeb: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ff0:
	/* 0xff0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff2:
	/* 0xff2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ff5:
	/* 0xff5: je     13ec <generic_tracepoint_actions+0x13ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff5, 0x13ec, x86_l_13ec);
x86_l_ffb:
	/* 0xffb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_ffe:
	/* 0xffe: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1002:
	/* 0x1002: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1007:
	/* 0x1007: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_100f:
	/* 0x100f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1014:
	/* 0x1014: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_101b:
	/* 0x101b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1020:
	/* 0x1020: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1022:
	/* 0x1022: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_102a:
	/* 0x102a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: je     148b <generic_tracepoint_actions+0x148b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x102d, 0x148b, x86_l_148b);
x86_l_1033:
	/* 0x1033: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1036:
	/* 0x1036: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103a:
	/* 0x103a: mov    DWORD PTR [r15+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103e:
	/* 0x103e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1043:
	/* 0x1043: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1046:
	/* 0x1046: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_104b:
	/* 0x104b: jmp    1120 <generic_tracepoint_actions+0x1120> */
	X86_SIM_X86_JMP(0x104b, 0x1120, x86_l_1120);
x86_l_1050:
	/* 0x1050: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1055:
	/* 0x1055: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1057:
	/* 0x1057: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_105c:
	/* 0x105c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1061:
	/* 0x1061: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1068:
	/* 0x1068: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_106d:
	/* 0x106d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106f:
	/* 0x106f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1072:
	/* 0x1072: je     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1072, 0x114c, x86_l_114c);
x86_l_1078:
	/* 0x1078: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_107c:
	/* 0x107c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1081:
	/* 0x1081: mov    DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_1089:
	/* 0x1089: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_108e:
	/* 0x108e: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1095:
	/* 0x1095: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_109a:
	/* 0x109a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109c:
	/* 0x109c: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_10a4:
	/* 0x10a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a7:
	/* 0x10a7: je     12aa <generic_tracepoint_actions+0x12aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a7, 0x12aa, x86_l_12aa);
x86_l_10ad:
	/* 0x10ad: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10b0:
	/* 0x10b0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_10b5:
	/* 0x10b5: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_10bc:
	/* 0x10bc: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10c1:
	/* 0x10c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c3:
	/* 0x10c3: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0x10c3, 0x114c, x86_l_114c);
x86_l_10c8:
	/* 0x10c8: cmp    DWORD PTR [r13+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_10ce:
	/* 0x10ce: je     10ef <generic_tracepoint_actions+0x10ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ce, 0x10ef, x86_l_10ef);
x86_l_10d0:
	/* 0x10d0: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_10d5:
	/* 0x10d5: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_10da:
	/* 0x10da: mov    rsi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_10e1:
	/* 0x10e1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10e4:
	/* 0x10e4: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e6:
	/* 0x10e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e8:
	/* 0x10e8: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10ef:
	/* 0x10ef: cmp    DWORD PTR [r13+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_10f5:
	/* 0x10f5: je     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f5, 0x114c, x86_l_114c);
x86_l_10f7:
	/* 0x10f7: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_10fc:
	/* 0x10fc: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1101:
	/* 0x1101: mov    rsi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1108:
	/* 0x1108: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_110d:
	/* 0x110d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1110:
	/* 0x1110: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1112:
	/* 0x1112: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1119:
	/* 0x1119: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0x1119, 0x114c, x86_l_114c);
x86_l_111b:
	/* 0x111b: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1120:
	/* 0x1120: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1125:
	/* 0x1125: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112c:
	/* 0x112c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1131:
	/* 0x1131: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_1138:
	/* 0x1138: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_113b:
	/* 0x113b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_113d:
	/* 0x113d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1140:
	/* 0x1140: je     114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1140, 0x114c, x86_l_114c);
x86_l_1142:
	/* 0x1142: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1147:
	/* 0x1147: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_114c:
	/* 0x114c: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1150:
	/* 0x1150: mov    ebp,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1154:
	/* 0x1154: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1157:
	/* 0x1157: jne    4dd <generic_tracepoint_actions+0x4dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1157, 0x4dd, x86_l_4dd);
x86_l_115d:
	/* 0x115d: jmp    4f3 <generic_tracepoint_actions+0x4f3> */
	X86_SIM_X86_JMP(0x115d, 0x4f3, x86_l_4f3);
x86_l_1162:
	/* 0x1162: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1167:
	/* 0x1167: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_116e:
	/* 0x116e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1173:
	/* 0x1173: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1178:
	/* 0x1178: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_117d:
	/* 0x117d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117f:
	/* 0x117f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1182:
	/* 0x1182: je     b15 <generic_tracepoint_actions+0xb15> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1182, 0xb15, x86_l_b15);
x86_l_1188:
	/* 0x1188: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_118b:
	/* 0x118b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_118d:
	/* 0x118d: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1191:
	/* 0x1191: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_1198:
	/* 0x1198: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_11a2:
	/* 0x11a2: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11a7:
	/* 0x11a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11ac:
	/* 0x11ac: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11b3:
	/* 0x11b3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11b6:
	/* 0x11b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b8:
	/* 0x11b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11bb:
	/* 0x11bb: je     150f <generic_tracepoint_actions+0x150f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11bb, 0x150f, x86_l_150f);
x86_l_11c1:
	/* 0x11c1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_11c3:
	/* 0x11c3: jmp    152f <generic_tracepoint_actions+0x152f> */
	X86_SIM_X86_JMP(0x11c3, 0x152f, x86_l_152f);
x86_l_11c8:
	/* 0x11c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11cd:
	/* 0x11cd: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_11d4:
	/* 0x11d4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11d9:
	/* 0x11d9: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11de:
	/* 0x11de: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e3:
	/* 0x11e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e5:
	/* 0x11e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11e8:
	/* 0x11e8: je     485 <generic_tracepoint_actions+0x485> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e8, 0x485, x86_l_485);
x86_l_11ee:
	/* 0x11ee: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11f3:
	/* 0x11f3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_11f5:
	/* 0x11f5: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f9:
	/* 0x11f9: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_1200:
	/* 0x1200: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_120a:
	/* 0x120a: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_120f:
	/* 0x120f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1214:
	/* 0x1214: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_121b:
	/* 0x121b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1223:
	/* 0x1223: je     155f <generic_tracepoint_actions+0x155f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1223, 0x155f, x86_l_155f);
x86_l_1229:
	/* 0x1229: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_122b:
	/* 0x122b: jmp    157f <generic_tracepoint_actions+0x157f> */
	X86_SIM_X86_JMP(0x122b, 0x157f, x86_l_157f);
x86_l_1230:
	/* 0x1230: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1238:
	/* 0x1238: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_123d:
	/* 0x123d: mov    rbp,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1245:
	/* 0x1245: jmp    400 <generic_tracepoint_actions+0x400> */
	X86_SIM_X86_JMP(0x1245, 0x400, x86_l_400);
x86_l_124a:
	/* 0x124a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_124f:
	/* 0x124f: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1256:
	/* 0x1256: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_125b:
	/* 0x125b: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1260:
	/* 0x1260: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1262:
	/* 0x1262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1264:
	/* 0x1264: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1267:
	/* 0x1267: je     c81 <generic_tracepoint_actions+0xc81> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1267, 0xc81, x86_l_c81);
x86_l_126d:
	/* 0x126d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_126f:
	/* 0x126f: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1273:
	/* 0x1273: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_127a:
	/* 0x127a: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_1284:
	/* 0x1284: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1289:
	/* 0x1289: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_128e:
	/* 0x128e: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1295:
	/* 0x1295: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1298:
	/* 0x1298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129a:
	/* 0x129a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129d:
	/* 0x129d: je     15d0 <generic_tracepoint_actions+0x15d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129d, 0x15d0, x86_l_15d0);
x86_l_12a3:
	/* 0x12a3: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_12a5:
	/* 0x12a5: jmp    c81 <generic_tracepoint_actions+0xc81> */
	X86_SIM_X86_JMP(0x12a5, 0xc81, x86_l_c81);
x86_l_12aa:
	/* 0x12aa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12af:
	/* 0x12af: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_12b6:
	/* 0x12b6: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12bb:
	/* 0x12bb: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12c0:
	/* 0x12c0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12c5:
	/* 0x12c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c7:
	/* 0x12c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ca:
	/* 0x12ca: je     10b0 <generic_tracepoint_actions+0x10b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ca, 0x10b0, x86_l_10b0);
x86_l_12d0:
	/* 0x12d0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12d3:
	/* 0x12d3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_12d5:
	/* 0x12d5: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d9:
	/* 0x12d9: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_12e0:
	/* 0x12e0: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_12ea:
	/* 0x12ea: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12ef:
	/* 0x12ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f4:
	/* 0x12f4: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_12fb:
	/* 0x12fb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12fe:
	/* 0x12fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1300:
	/* 0x1300: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1303:
	/* 0x1303: je     15f5 <generic_tracepoint_actions+0x15f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1303, 0x15f5, x86_l_15f5);
x86_l_1309:
	/* 0x1309: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_130b:
	/* 0x130b: jmp    1615 <generic_tracepoint_actions+0x1615> */
	X86_SIM_X86_JMP(0x130b, 0x1615, x86_l_1615);
x86_l_1310:
	/* 0x1310: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1315:
	/* 0x1315: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_131c:
	/* 0x131c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_131f:
	/* 0x131f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1321:
	/* 0x1321: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1323:
	/* 0x1323: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1328:
	/* 0x1328: jne    cb7 <generic_tracepoint_actions+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1328, 0xcb7, x86_l_cb7);
x86_l_132e:
	/* 0x132e: jmp    cad <generic_tracepoint_actions+0xcad> */
	X86_SIM_X86_JMP(0x132e, 0xcad, x86_l_cad);
x86_l_1333:
	/* 0x1333: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1338:
	/* 0x1338: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_133f:
	/* 0x133f: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1344:
	/* 0x1344: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1349:
	/* 0x1349: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_134e:
	/* 0x134e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1350:
	/* 0x1350: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1353:
	/* 0x1353: je     c71 <generic_tracepoint_actions+0xc71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1353, 0xc71, x86_l_c71);
x86_l_1359:
	/* 0x1359: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_135e:
	/* 0x135e: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1362:
	/* 0x1362: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_1369:
	/* 0x1369: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_1373:
	/* 0x1373: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1378:
	/* 0x1378: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_137d:
	/* 0x137d: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1384:
	/* 0x1384: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1387:
	/* 0x1387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1389:
	/* 0x1389: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138c:
	/* 0x138c: je     1646 <generic_tracepoint_actions+0x1646> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138c, 0x1646, x86_l_1646);
x86_l_1392:
	/* 0x1392: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1394:
	/* 0x1394: jmp    1666 <generic_tracepoint_actions+0x1666> */
	X86_SIM_X86_JMP(0x1394, 0x1666, x86_l_1666);
x86_l_1399:
	/* 0x1399: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_13a1:
	/* 0x13a1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13a6:
	/* 0x13a6: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_13ad:
	/* 0x13ad: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_13b0:
	/* 0x13b0: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13b5:
	/* 0x13b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b7:
	/* 0x13b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b9:
	/* 0x13b9: cmp    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_13be:
	/* 0x13be: je     33f <generic_tracepoint_actions+0x33f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13be, 0x33f, x86_l_33f);
x86_l_13c4:
	/* 0x13c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c9:
	/* 0x13c9: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_13d0:
	/* 0x13d0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13d5:
	/* 0x13d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d7:
	/* 0x13d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13da:
	/* 0x13da: je     33f <generic_tracepoint_actions+0x33f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13da, 0x33f, x86_l_33f);
x86_l_13e0:
	/* 0x13e0: mov    ecx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13e4:
	/* 0x13e4: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_13e7:
	/* 0x13e7: jmp    33f <generic_tracepoint_actions+0x33f> */
	X86_SIM_X86_JMP(0x13e7, 0x33f, x86_l_33f);
x86_l_13ec:
	/* 0x13ec: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13f1:
	/* 0x13f1: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_13f8:
	/* 0x13f8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13fd:
	/* 0x13fd: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1402:
	/* 0x1402: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1404:
	/* 0x1404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1406:
	/* 0x1406: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1409:
	/* 0x1409: je     1046 <generic_tracepoint_actions+0x1046> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1409, 0x1046, x86_l_1046);
x86_l_140f:
	/* 0x140f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1411:
	/* 0x1411: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1415:
	/* 0x1415: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_141c:
	/* 0x141c: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_1426:
	/* 0x1426: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_142b:
	/* 0x142b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1430:
	/* 0x1430: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1437:
	/* 0x1437: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_143a:
	/* 0x143a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143c:
	/* 0x143c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_143f:
	/* 0x143f: je     1696 <generic_tracepoint_actions+0x1696> */
	X86_SIM_X86_JCC(X86_CC_E, 0x143f, 0x1696, x86_l_1696);
x86_l_1445:
	/* 0x1445: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1447:
	/* 0x1447: jmp    1046 <generic_tracepoint_actions+0x1046> */
	X86_SIM_X86_JMP(0x1447, 0x1046, x86_l_1046);
x86_l_144c:
	/* 0x144c: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1454:
	/* 0x1454: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1459:
	/* 0x1459: mov    r14,QWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1461:
	/* 0x1461: jmp    bf0 <generic_tracepoint_actions+0xbf0> */
	X86_SIM_X86_JMP(0x1461, 0xbf0, x86_l_bf0);
x86_l_1466:
	/* 0x1466: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_146e:
	/* 0x146e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1473:
	/* 0x1473: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_147a:
	/* 0x147a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_147d:
	/* 0x147d: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1482:
	/* 0x1482: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1484:
	/* 0x1484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1486:
	/* 0x1486: jmp    495 <generic_tracepoint_actions+0x495> */
	X86_SIM_X86_JMP(0x1486, 0x495, x86_l_495);
x86_l_148b:
	/* 0x148b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1490:
	/* 0x1490: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1497:
	/* 0x1497: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_149c:
	/* 0x149c: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_14a1:
	/* 0x14a1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14a6:
	/* 0x14a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a8:
	/* 0x14a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14ab:
	/* 0x14ab: je     1036 <generic_tracepoint_actions+0x1036> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ab, 0x1036, x86_l_1036);
x86_l_14b1:
	/* 0x14b1: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_14b4:
	/* 0x14b4: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_14b6:
	/* 0x14b6: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ba:
	/* 0x14ba: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_14c1:
	/* 0x14c1: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_14cb:
	/* 0x14cb: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14d0:
	/* 0x14d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d5:
	/* 0x14d5: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_14dc:
	/* 0x14dc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_14df:
	/* 0x14df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e1:
	/* 0x14e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e4:
	/* 0x14e4: je     16bb <generic_tracepoint_actions+0x16bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e4, 0x16bb, x86_l_16bb);
x86_l_14ea:
	/* 0x14ea: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14ec:
	/* 0x14ec: jmp    16db <generic_tracepoint_actions+0x16db> */
	X86_SIM_X86_JMP(0x14ec, 0x16db, x86_l_16db);
x86_l_14f1:
	/* 0x14f1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14f6:
	/* 0x14f6: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_14fd:
	/* 0x14fd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1500:
	/* 0x1500: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1502:
	/* 0x1502: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1504:
	/* 0x1504: jne    1150 <generic_tracepoint_actions+0x1150> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1504, 0x1150, x86_l_1150);
x86_l_150a:
	/* 0x150a: jmp    114c <generic_tracepoint_actions+0x114c> */
	X86_SIM_X86_JMP(0x150a, 0x114c, x86_l_114c);
x86_l_150f:
	/* 0x150f: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1517:
	/* 0x1517: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_151c:
	/* 0x151c: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1523:
	/* 0x1523: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1526:
	/* 0x1526: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_152b:
	/* 0x152b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_152d:
	/* 0x152d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152f:
	/* 0x152f: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1531:
	/* 0x1531: je     b15 <generic_tracepoint_actions+0xb15> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1531, 0xb15, x86_l_b15);
x86_l_1537:
	/* 0x1537: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153c:
	/* 0x153c: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1543:
	/* 0x1543: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1548:
	/* 0x1548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154a:
	/* 0x154a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154d:
	/* 0x154d: je     b15 <generic_tracepoint_actions+0xb15> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154d, 0xb15, x86_l_b15);
x86_l_1553:
	/* 0x1553: mov    ecx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1557:
	/* 0x1557: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_155a:
	/* 0x155a: jmp    b15 <generic_tracepoint_actions+0xb15> */
	X86_SIM_X86_JMP(0x155a, 0xb15, x86_l_b15);
x86_l_155f:
	/* 0x155f: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_1567:
	/* 0x1567: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_156c:
	/* 0x156c: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1573:
	/* 0x1573: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1576:
	/* 0x1576: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_157b:
	/* 0x157b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157d:
	/* 0x157d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157f:
	/* 0x157f: cmp    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1584:
	/* 0x1584: je     485 <generic_tracepoint_actions+0x485> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1584, 0x485, x86_l_485);
x86_l_158a:
	/* 0x158a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_158f:
	/* 0x158f: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1596:
	/* 0x1596: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_159b:
	/* 0x159b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159d:
	/* 0x159d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a0:
	/* 0x15a0: je     485 <generic_tracepoint_actions+0x485> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15a0, 0x485, x86_l_485);
x86_l_15a6:
	/* 0x15a6: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15aa:
	/* 0x15aa: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15ad:
	/* 0x15ad: jmp    485 <generic_tracepoint_actions+0x485> */
	X86_SIM_X86_JMP(0x15ad, 0x485, x86_l_485);
x86_l_15b2:
	/* 0x15b2: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_15ba:
	/* 0x15ba: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_15bf:
	/* 0x15bf: mov    rax,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_15c7:
	/* 0x15c7: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_15cb:
	/* 0x15cb: jmp    fbb <generic_tracepoint_actions+0xfbb> */
	X86_SIM_X86_JMP(0x15cb, 0xfbb, x86_l_fbb);
x86_l_15d0:
	/* 0x15d0: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_15d8:
	/* 0x15d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15dd:
	/* 0x15dd: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_15e4:
	/* 0x15e4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_15e7:
	/* 0x15e7: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15ec:
	/* 0x15ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ee:
	/* 0x15ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f0:
	/* 0x15f0: jmp    c81 <generic_tracepoint_actions+0xc81> */
	X86_SIM_X86_JMP(0x15f0, 0xc81, x86_l_c81);
x86_l_15f5:
	/* 0x15f5: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_15fd:
	/* 0x15fd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1602:
	/* 0x1602: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1609:
	/* 0x1609: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1611:
	/* 0x1611: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1613:
	/* 0x1613: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1615:
	/* 0x1615: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1618:
	/* 0x1618: je     10b0 <generic_tracepoint_actions+0x10b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1618, 0x10b0, x86_l_10b0);
x86_l_161e:
	/* 0x161e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1623:
	/* 0x1623: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_162a:
	/* 0x162a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162f:
	/* 0x162f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1631:
	/* 0x1631: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1634:
	/* 0x1634: je     10b0 <generic_tracepoint_actions+0x10b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1634, 0x10b0, x86_l_10b0);
x86_l_163a:
	/* 0x163a: mov    ecx,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_163e:
	/* 0x163e: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1641:
	/* 0x1641: jmp    10b0 <generic_tracepoint_actions+0x10b0> */
	X86_SIM_X86_JMP(0x1641, 0x10b0, x86_l_10b0);
x86_l_1646:
	/* 0x1646: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_164e:
	/* 0x164e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1653:
	/* 0x1653: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_165a:
	/* 0x165a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_165d:
	/* 0x165d: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1662:
	/* 0x1662: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1664:
	/* 0x1664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1666:
	/* 0x1666: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1668:
	/* 0x1668: je     c71 <generic_tracepoint_actions+0xc71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1668, 0xc71, x86_l_c71);
x86_l_166e:
	/* 0x166e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1673:
	/* 0x1673: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_167a:
	/* 0x167a: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_167f:
	/* 0x167f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1681:
	/* 0x1681: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1684:
	/* 0x1684: je     c71 <generic_tracepoint_actions+0xc71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1684, 0xc71, x86_l_c71);
x86_l_168a:
	/* 0x168a: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_168e:
	/* 0x168e: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1691:
	/* 0x1691: jmp    c71 <generic_tracepoint_actions+0xc71> */
	X86_SIM_X86_JMP(0x1691, 0xc71, x86_l_c71);
x86_l_1696:
	/* 0x1696: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_169e:
	/* 0x169e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16a3:
	/* 0x16a3: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16aa:
	/* 0x16aa: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_16ad:
	/* 0x16ad: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16b2:
	/* 0x16b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b4:
	/* 0x16b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b6:
	/* 0x16b6: jmp    1046 <generic_tracepoint_actions+0x1046> */
	X86_SIM_X86_JMP(0x16b6, 0x1046, x86_l_1046);
x86_l_16bb:
	/* 0x16bb: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_16c3:
	/* 0x16c3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16c8:
	/* 0x16c8: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16cf:
	/* 0x16cf: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_16d2:
	/* 0x16d2: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_16d7:
	/* 0x16d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16d9:
	/* 0x16d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16db:
	/* 0x16db: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_16de:
	/* 0x16de: je     1036 <generic_tracepoint_actions+0x1036> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16de, 0x1036, x86_l_1036);
x86_l_16e4:
	/* 0x16e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e9:
	/* 0x16e9: mov    rdi,QWORD PTR [rip+0x4d3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_16f0:
	/* 0x16f0: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16f5:
	/* 0x16f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f7:
	/* 0x16f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16fa:
	/* 0x16fa: je     1036 <generic_tracepoint_actions+0x1036> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fa, 0x1036, x86_l_1036);
x86_l_1700:
	/* 0x1700: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1704:
	/* 0x1704: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1707:
	/* 0x1707: jmp    1036 <generic_tracepoint_actions+0x1036> */
	X86_SIM_X86_JMP(0x1707, 0x1036, x86_l_1036);
x86_l_170c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
