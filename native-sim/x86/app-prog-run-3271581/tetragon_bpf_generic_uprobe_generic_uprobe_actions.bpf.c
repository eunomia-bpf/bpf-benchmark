extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char sleepable_offload;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_generic_uprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 120ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25:
	/* 0x25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a:
	/* 0x2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c:
	/* 0x2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: je     12d9 <generic_uprobe_actions+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f, 0x12d9, x86_l_12d9);
x86_l_35:
	/* 0x35: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: mov    r12d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_3f:
	/* 0x3f: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_43:
	/* 0x43: jl     12d9 <generic_uprobe_actions+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_L, 0x43, 0x12d9, x86_l_12d9);
x86_l_49:
	/* 0x49: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_50:
	/* 0x50: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_57:
	/* 0x57: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c:
	/* 0x5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e:
	/* 0x5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61:
	/* 0x61: je     12d9 <generic_uprobe_actions+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x12d9, x86_l_12d9);
x86_l_67:
	/* 0x67: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_70:
	/* 0x70: add    r12d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_74:
	/* 0x74: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_7c:
	/* 0x7c: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_83:
	/* 0x83: lea    rsi,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_88:
	/* 0x88: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8b:
	/* 0x8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_90:
	/* 0x90: and    r12d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_97:
	/* 0x97: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9a:
	/* 0x9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c:
	/* 0x9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9f:
	/* 0x9f: je     c4 <generic_uprobe_actions+0xc4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f, 0xc4, x86_l_c4);
x86_l_a1:
	/* 0xa1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4:
	/* 0xa4: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a7:
	/* 0xa7: je     e1 <generic_uprobe_actions+0xe1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7, 0xe1, x86_l_e1);
x86_l_a9:
	/* 0xa9: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ae:
	/* 0xae: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b3:
	/* 0xb3: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_b8:
	/* 0xb8: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bd:
	/* 0xbd: ja     fb <generic_uprobe_actions+0xfb> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbd, 0xfb, x86_l_fb);
x86_l_bf:
	/* 0xbf: jmp    12be <generic_uprobe_actions+0x12be> */
	X86_SIM_X86_JMP(0xbf, 0x12be, x86_l_12be);
x86_l_c4:
	/* 0xc4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c9:
	/* 0xc9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ce:
	/* 0xce: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d0:
	/* 0xd0: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_d5:
	/* 0xd5: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_da:
	/* 0xda: ja     fb <generic_uprobe_actions+0xfb> */
	X86_SIM_X86_JCC(X86_CC_A, 0xda, 0xfb, x86_l_fb);
x86_l_dc:
	/* 0xdc: jmp    12be <generic_uprobe_actions+0x12be> */
	X86_SIM_X86_JMP(0xdc, 0x12be, x86_l_12be);
x86_l_e1:
	/* 0xe1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e6:
	/* 0xe6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_eb:
	/* 0xeb: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_f0:
	/* 0xf0: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f5:
	/* 0xf5: jbe    12be <generic_uprobe_actions+0x12be> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf5, 0x12be, x86_l_12be);
x86_l_fb:
	/* 0xfb: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_105:
	/* 0x105: mov    BYTE PTR [rsp+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10e:
	/* 0x10e: movsxd rbp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_113:
	/* 0x113: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_11b:
	/* 0x11b: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_122:
	/* 0x122: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_127:
	/* 0x127: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c:
	/* 0x12c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e:
	/* 0x12e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_131:
	/* 0x131: je     165 <generic_uprobe_actions+0x165> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131, 0x165, x86_l_165);
x86_l_133:
	/* 0x133: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_136:
	/* 0x136: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139:
	/* 0x139: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_13c:
	/* 0x13c: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_13f:
	/* 0x13f: jg     170 <generic_uprobe_actions+0x170> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13f, 0x170, x86_l_170);
x86_l_141:
	/* 0x141: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_144:
	/* 0x144: jg     1a7 <generic_uprobe_actions+0x1a7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x144, 0x1a7, x86_l_1a7);
x86_l_146:
	/* 0x146: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_149:
	/* 0x149: jg     2cf <generic_uprobe_actions+0x2cf> */
	X86_SIM_X86_JCC(X86_CC_G, 0x149, 0x2cf, x86_l_2cf);
x86_l_14f:
	/* 0x14f: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_151:
	/* 0x151: je     476 <generic_uprobe_actions+0x476> */
	X86_SIM_X86_JCC(X86_CC_E, 0x151, 0x476, x86_l_476);
x86_l_157:
	/* 0x157: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_15a:
	/* 0x15a: je     2e1 <generic_uprobe_actions+0x2e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15a, 0x2e1, x86_l_2e1);
x86_l_160:
	/* 0x160: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x160, 0x694, x86_l_694);
x86_l_165:
	/* 0x165: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168:
	/* 0x168: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_16b:
	/* 0x16b: jmp    69b <generic_uprobe_actions+0x69b> */
	X86_SIM_X86_JMP(0x16b, 0x69b, x86_l_69b);
x86_l_170:
	/* 0x170: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_173:
	/* 0x173: jg     2a4 <generic_uprobe_actions+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x173, 0x2a4, x86_l_2a4);
x86_l_179:
	/* 0x179: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_17c:
	/* 0x17c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17f:
	/* 0x17f: jb     349 <generic_uprobe_actions+0x349> */
	X86_SIM_X86_JCC(X86_CC_B, 0x17f, 0x349, x86_l_349);
x86_l_185:
	/* 0x185: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_188:
	/* 0x188: je     354 <generic_uprobe_actions+0x354> */
	X86_SIM_X86_JCC(X86_CC_E, 0x188, 0x354, x86_l_354);
x86_l_18e:
	/* 0x18e: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_191:
	/* 0x191: jne    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x191, 0x694, x86_l_694);
x86_l_197:
	/* 0x197: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_19d:
	/* 0x19d: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a2:
	/* 0x1a2: jmp    66f <generic_uprobe_actions+0x66f> */
	X86_SIM_X86_JMP(0x1a2, 0x66f, x86_l_66f);
x86_l_1a7:
	/* 0x1a7: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1aa:
	/* 0x1aa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ad:
	/* 0x1ad: jb     340 <generic_uprobe_actions+0x340> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ad, 0x340, x86_l_340);
x86_l_1b3:
	/* 0x1b3: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1b6:
	/* 0x1b6: je     35f <generic_uprobe_actions+0x35f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b6, 0x35f, x86_l_35f);
x86_l_1bc:
	/* 0x1bc: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1bf:
	/* 0x1bf: jne    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bf, 0x694, x86_l_694);
x86_l_1c5:
	/* 0x1c5: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca:
	/* 0x1ca: mov    r15d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cf:
	/* 0x1cf: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d8:
	/* 0x1d8: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0:
	/* 0x1e0: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1e3:
	/* 0x1e3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e6:
	/* 0x1e6: ja     335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1e6, 0x335, x86_l_335);
x86_l_1ec:
	/* 0x1ec: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1f5:
	/* 0x1f5: jne    335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f5, 0x335, x86_l_335);
x86_l_1fb:
	/* 0x1fb: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_203:
	/* 0x203: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_208:
	/* 0x208: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_210:
	/* 0x210: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214:
	/* 0x214: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_219:
	/* 0x219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b:
	/* 0x21b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_21f:
	/* 0x21f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223:
	/* 0x223: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_22a:
	/* 0x22a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_232:
	/* 0x232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234:
	/* 0x234: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_237:
	/* 0x237: je     335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x237, 0x335, x86_l_335);
x86_l_23d:
	/* 0x23d: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_241:
	/* 0x241: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_245:
	/* 0x245: ja     335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_A, 0x245, 0x335, x86_l_335);
x86_l_24b:
	/* 0x24b: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_254:
	/* 0x254: jne    335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x254, 0x335, x86_l_335);
x86_l_25a:
	/* 0x25a: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_262:
	/* 0x262: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_26a:
	/* 0x26a: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_270:
	/* 0x270: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_278:
	/* 0x278: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c:
	/* 0x27c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_27f:
	/* 0x27f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_284:
	/* 0x284: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286:
	/* 0x286: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_28a:
	/* 0x28a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e:
	/* 0x28e: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_295:
	/* 0x295: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_297:
	/* 0x297: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_29a:
	/* 0x29a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29f:
	/* 0x29f: jmp    5a0 <generic_uprobe_actions+0x5a0> */
	X86_SIM_X86_JMP(0x29f, 0x5a0, x86_l_5a0);
x86_l_2a4:
	/* 0x2a4: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_2a7:
	/* 0x2a7: je     4e7 <generic_uprobe_actions+0x4e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a7, 0x4e7, x86_l_4e7);
x86_l_2ad:
	/* 0x2ad: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_2b0:
	/* 0x2b0: je     3fe <generic_uprobe_actions+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b0, 0x3fe, x86_l_3fe);
x86_l_2b6:
	/* 0x2b6: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_2b9:
	/* 0x2b9: jne    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b9, 0x694, x86_l_694);
x86_l_2bf:
	/* 0x2bf: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2c5:
	/* 0x2c5: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ca:
	/* 0x2ca: jmp    66f <generic_uprobe_actions+0x66f> */
	X86_SIM_X86_JMP(0x2ca, 0x66f, x86_l_66f);
x86_l_2cf:
	/* 0x2cf: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2d2:
	/* 0x2d2: je     4dd <generic_uprobe_actions+0x4dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d2, 0x4dd, x86_l_4dd);
x86_l_2d8:
	/* 0x2d8: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2db:
	/* 0x2db: jne    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2db, 0x694, x86_l_694);
x86_l_2e1:
	/* 0x2e1: mov    r13d,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6:
	/* 0x2e6: mov    r15d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2eb:
	/* 0x2eb: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f4:
	/* 0x2f4: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc:
	/* 0x2fc: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_304:
	/* 0x304: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_30b:
	/* 0x30b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_310:
	/* 0x310: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_315:
	/* 0x315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317:
	/* 0x317: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31a:
	/* 0x31a: je     335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31a, 0x335, x86_l_335);
x86_l_31c:
	/* 0x31c: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_320:
	/* 0x320: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_324:
	/* 0x324: ja     335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_A, 0x324, 0x335, x86_l_335);
x86_l_326:
	/* 0x326: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_32f:
	/* 0x32f: je     4f7 <generic_uprobe_actions+0x4f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32f, 0x4f7, x86_l_4f7);
x86_l_335:
	/* 0x335: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_33b:
	/* 0x33b: jmp    691 <generic_uprobe_actions+0x691> */
	X86_SIM_X86_JMP(0x33b, 0x691, x86_l_691);
x86_l_340:
	/* 0x340: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_345:
	/* 0x345: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_349:
	/* 0x349: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_34f:
	/* 0x34f: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x34f, 0x694, x86_l_694);
x86_l_354:
	/* 0x354: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_357:
	/* 0x357: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a:
	/* 0x35a: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x35a, 0x694, x86_l_694);
x86_l_35f:
	/* 0x35f: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_365:
	/* 0x365: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_36b:
	/* 0x36b: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_370:
	/* 0x370: je     66f <generic_uprobe_actions+0x66f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x370, 0x66f, x86_l_66f);
x86_l_376:
	/* 0x376: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37b:
	/* 0x37b: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_37f:
	/* 0x37f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_384:
	/* 0x384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_386:
	/* 0x386: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38b:
	/* 0x38b: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_392:
	/* 0x392: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_397:
	/* 0x397: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39c:
	/* 0x39c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39e:
	/* 0x39e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3a1:
	/* 0x3a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: je     3b3 <generic_uprobe_actions+0x3b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a4, 0x3b3, x86_l_3b3);
x86_l_3a6:
	/* 0x3a6: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_3ad:
	/* 0x3ad: jb     662 <generic_uprobe_actions+0x662> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3ad, 0x662, x86_l_662);
x86_l_3b3:
	/* 0x3b3: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_3b6:
	/* 0x3b6: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_3b8:
	/* 0x3b8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3bb:
	/* 0x3bb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3c0:
	/* 0x3c0: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_3c3:
	/* 0x3c3: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c7:
	/* 0x3c7: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_3ce:
	/* 0x3ce: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_3d8:
	/* 0x3d8: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3dd:
	/* 0x3dd: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_3e4:
	/* 0x3e4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3e7:
	/* 0x3e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ec:
	/* 0x3ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee:
	/* 0x3ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f1:
	/* 0x3f1: je     637 <generic_uprobe_actions+0x637> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f1, 0x637, x86_l_637);
x86_l_3f7:
	/* 0x3f7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3f9:
	/* 0x3f9: jmp    659 <generic_uprobe_actions+0x659> */
	X86_SIM_X86_JMP(0x3f9, 0x659, x86_l_659);
x86_l_3fe:
	/* 0x3fe: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_403:
	/* 0x403: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_405:
	/* 0x405: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40a:
	/* 0x40a: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_411:
	/* 0x411: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_416:
	/* 0x416: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41b:
	/* 0x41b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d:
	/* 0x41d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_420:
	/* 0x420: je     694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_E, 0x420, 0x694, x86_l_694);
x86_l_426:
	/* 0x426: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_42a:
	/* 0x42a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42f:
	/* 0x42f: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_437:
	/* 0x437: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_43e:
	/* 0x43e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_443:
	/* 0x443: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_448:
	/* 0x448: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a:
	/* 0x44a: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_452:
	/* 0x452: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_455:
	/* 0x455: je     5ac <generic_uprobe_actions+0x5ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x455, 0x5ac, x86_l_5ac);
x86_l_45b:
	/* 0x45b: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_45e:
	/* 0x45e: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_465:
	/* 0x465: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_46a:
	/* 0x46a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_46f:
	/* 0x46f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_471:
	/* 0x471: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x471, 0x694, x86_l_694);
x86_l_476:
	/* 0x476: cmp    DWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47c:
	/* 0x47c: je     49f <generic_uprobe_actions+0x49f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47c, 0x49f, x86_l_49f);
x86_l_47e:
	/* 0x47e: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_483:
	/* 0x483: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_48a:
	/* 0x48a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48c:
	/* 0x48c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_491:
	/* 0x491: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_496:
	/* 0x496: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_498:
	/* 0x498: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_49f:
	/* 0x49f: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_4a5:
	/* 0x4a5: cmp    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4ab:
	/* 0x4ab: je     694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ab, 0x694, x86_l_694);
x86_l_4b1:
	/* 0x4b1: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_4b6:
	/* 0x4b6: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_4bd:
	/* 0x4bd: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_4c2:
	/* 0x4c2: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_4c7:
	/* 0x4c7: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_4cc:
	/* 0x4cc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4cf:
	/* 0x4cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d1:
	/* 0x4d1: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4d8:
	/* 0x4d8: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x4d8, 0x694, x86_l_694);
x86_l_4dd:
	/* 0x4dd: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4e2:
	/* 0x4e2: jmp    66f <generic_uprobe_actions+0x66f> */
	X86_SIM_X86_JMP(0x4e2, 0x66f, x86_l_66f);
x86_l_4e7:
	/* 0x4e7: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_4ed:
	/* 0x4ed: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4f2:
	/* 0x4f2: jmp    66f <generic_uprobe_actions+0x66f> */
	X86_SIM_X86_JMP(0x4f2, 0x66f, x86_l_66f);
x86_l_4f7:
	/* 0x4f7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fc:
	/* 0x4fc: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_504:
	/* 0x504: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_50c:
	/* 0x50c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_511:
	/* 0x511: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_519:
	/* 0x519: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d:
	/* 0x51d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_522:
	/* 0x522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_524:
	/* 0x524: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_528:
	/* 0x528: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c:
	/* 0x52c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_52f:
	/* 0x52f: jne    614 <generic_uprobe_actions+0x614> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x52f, 0x614, x86_l_614);
x86_l_535:
	/* 0x535: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_539:
	/* 0x539: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_53d:
	/* 0x53d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_542:
	/* 0x542: ja     335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_A, 0x542, 0x335, x86_l_335);
x86_l_548:
	/* 0x548: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_551:
	/* 0x551: jne    335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x551, 0x335, x86_l_335);
x86_l_557:
	/* 0x557: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_55f:
	/* 0x55f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_565:
	/* 0x565: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_569:
	/* 0x569: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_570:
	/* 0x570: mov    esi,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_578:
	/* 0x578: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_57e:
	/* 0x57e: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_582:
	/* 0x582: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_585:
	/* 0x585: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_58a:
	/* 0x58a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_58d:
	/* 0x58d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f:
	/* 0x58f: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_596:
	/* 0x596: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_598:
	/* 0x598: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_59b:
	/* 0x59b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5a0:
	/* 0x5a0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5a3:
	/* 0x5a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a5:
	/* 0x5a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a7:
	/* 0x5a7: jmp    335 <generic_uprobe_actions+0x335> */
	X86_SIM_X86_JMP(0x5a7, 0x335, x86_l_335);
x86_l_5ac:
	/* 0x5ac: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_5b3:
	/* 0x5b3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b8:
	/* 0x5b8: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5bd:
	/* 0x5bd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5c2:
	/* 0x5c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c7:
	/* 0x5c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c9:
	/* 0x5c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cc:
	/* 0x5cc: je     45e <generic_uprobe_actions+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5cc, 0x45e, x86_l_45e);
x86_l_5d2:
	/* 0x5d2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d7:
	/* 0x5d7: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5d9:
	/* 0x5d9: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dd:
	/* 0x5dd: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_5e4:
	/* 0x5e4: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_5ee:
	/* 0x5ee: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5f3:
	/* 0x5f3: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5fa:
	/* 0x5fa: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5fd:
	/* 0x5fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_602:
	/* 0x602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_604:
	/* 0x604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_607:
	/* 0x607: je     c3a <generic_uprobe_actions+0xc3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x607, 0xc3a, x86_l_c3a);
x86_l_60d:
	/* 0x60d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_60f:
	/* 0x60f: jmp    c5c <generic_uprobe_actions+0xc5c> */
	X86_SIM_X86_JMP(0x60f, 0xc5c, x86_l_c5c);
x86_l_614:
	/* 0x614: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_61b:
	/* 0x61b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_61e:
	/* 0x61e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_623:
	/* 0x623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_625:
	/* 0x625: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_628:
	/* 0x628: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_62b:
	/* 0x62b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62d:
	/* 0x62d: jne    69b <generic_uprobe_actions+0x69b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x62d, 0x69b, x86_l_69b);
x86_l_62f:
	/* 0x62f: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_635:
	/* 0x635: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x635, 0x694, x86_l_694);
x86_l_637:
	/* 0x637: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_63f:
	/* 0x63f: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_646:
	/* 0x646: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_648:
	/* 0x648: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_64b:
	/* 0x64b: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_650:
	/* 0x650: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_655:
	/* 0x655: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_657:
	/* 0x657: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659:
	/* 0x659: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_65c:
	/* 0x65c: je     bf6 <generic_uprobe_actions+0xbf6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x65c, 0xbf6, x86_l_bf6);
x86_l_662:
	/* 0x662: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_666:
	/* 0x666: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_669:
	/* 0x669: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_66f:
	/* 0x66f: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_676:
	/* 0x676: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_67d:
	/* 0x67d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_680:
	/* 0x680: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_685:
	/* 0x685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_687:
	/* 0x687: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68a:
	/* 0x68a: je     691 <generic_uprobe_actions+0x691> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68a, 0x691, x86_l_691);
x86_l_68c:
	/* 0x68c: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_691:
	/* 0x691: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_694:
	/* 0x694: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_698:
	/* 0x698: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_69b:
	/* 0x69b: lea    eax,[r13*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_6a3:
	/* 0x6a3: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_6a7:
	/* 0x6a7: jae    12b9 <generic_uprobe_actions+0x12b9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x6a7, 0x12b9, x86_l_12b9);
x86_l_6ad:
	/* 0x6ad: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b2:
	/* 0x6b2: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_6b5:
	/* 0x6b5: movsxd rbp,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_6ba:
	/* 0x6ba: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_6c2:
	/* 0x6c2: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_6c9:
	/* 0x6c9: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6ce:
	/* 0x6ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d3:
	/* 0x6d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d5:
	/* 0x6d5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d8:
	/* 0x6d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6db:
	/* 0x6db: je     cf6 <generic_uprobe_actions+0xcf6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6db, 0xcf6, x86_l_cf6);
x86_l_6e1:
	/* 0x6e1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6e4:
	/* 0x6e4: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_6e7:
	/* 0x6e7: jg     70d <generic_uprobe_actions+0x70d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e7, 0x70d, x86_l_70d);
x86_l_6e9:
	/* 0x6e9: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6ec:
	/* 0x6ec: jg     744 <generic_uprobe_actions+0x744> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6ec, 0x744, x86_l_744);
x86_l_6ee:
	/* 0x6ee: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6f1:
	/* 0x6f1: jg     87e <generic_uprobe_actions+0x87e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6f1, 0x87e, x86_l_87e);
x86_l_6f7:
	/* 0x6f7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6f9:
	/* 0x6f9: je     b03 <generic_uprobe_actions+0xb03> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f9, 0xb03, x86_l_b03);
x86_l_6ff:
	/* 0x6ff: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_702:
	/* 0x702: je     890 <generic_uprobe_actions+0x890> */
	X86_SIM_X86_JCC(X86_CC_E, 0x702, 0x890, x86_l_890);
x86_l_708:
	/* 0x708: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0x708, 0xcec, x86_l_cec);
x86_l_70d:
	/* 0x70d: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_710:
	/* 0x710: jg     852 <generic_uprobe_actions+0x852> */
	X86_SIM_X86_JCC(X86_CC_G, 0x710, 0x852, x86_l_852);
x86_l_716:
	/* 0x716: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_719:
	/* 0x719: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_71c:
	/* 0x71c: jb     9c2 <generic_uprobe_actions+0x9c2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x71c, 0x9c2, x86_l_9c2);
x86_l_722:
	/* 0x722: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_725:
	/* 0x725: je     9da <generic_uprobe_actions+0x9da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x725, 0x9da, x86_l_9da);
x86_l_72b:
	/* 0x72b: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_72e:
	/* 0x72e: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x72e, 0xcec, x86_l_cec);
x86_l_734:
	/* 0x734: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_737:
	/* 0x737: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_73a:
	/* 0x73a: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_73f:
	/* 0x73f: jmp    cc7 <generic_uprobe_actions+0xcc7> */
	X86_SIM_X86_JMP(0x73f, 0xcc7, x86_l_cc7);
x86_l_744:
	/* 0x744: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_747:
	/* 0x747: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_74a:
	/* 0x74a: jb     9ca <generic_uprobe_actions+0x9ca> */
	X86_SIM_X86_JCC(X86_CC_B, 0x74a, 0x9ca, x86_l_9ca);
x86_l_750:
	/* 0x750: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_753:
	/* 0x753: je     9e7 <generic_uprobe_actions+0x9e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x753, 0x9e7, x86_l_9e7);
x86_l_759:
	/* 0x759: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_75c:
	/* 0x75c: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x75c, 0xcec, x86_l_cec);
x86_l_762:
	/* 0x762: mov    eax,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_767:
	/* 0x767: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_76b:
	/* 0x76b: mov    r15d,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_770:
	/* 0x770: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_779:
	/* 0x779: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_781:
	/* 0x781: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_784:
	/* 0x784: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_787:
	/* 0x787: ja     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x787, 0xcec, x86_l_cec);
x86_l_78d:
	/* 0x78d: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_795:
	/* 0x795: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x795, 0xcec, x86_l_cec);
x86_l_79b:
	/* 0x79b: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_7a3:
	/* 0x7a3: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7a8:
	/* 0x7a8: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_7af:
	/* 0x7af: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b3:
	/* 0x7b3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_7b8:
	/* 0x7b8: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_7bb:
	/* 0x7bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bd:
	/* 0x7bd: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_7c1:
	/* 0x7c1: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c5:
	/* 0x7c5: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_7cc:
	/* 0x7cc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_7cf:
	/* 0x7cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d4:
	/* 0x7d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d6:
	/* 0x7d6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_7d9:
	/* 0x7d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7dc:
	/* 0x7dc: je     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7dc, 0xcec, x86_l_cec);
x86_l_7e2:
	/* 0x7e2: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7e6:
	/* 0x7e6: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_7ea:
	/* 0x7ea: ja     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7ea, 0xcec, x86_l_cec);
x86_l_7f0:
	/* 0x7f0: cmp    DWORD PTR [rdx+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_7f9:
	/* 0x7f9: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7f9, 0xcec, x86_l_cec);
x86_l_7ff:
	/* 0x7ff: mov    rcx,QWORD PTR [rdx+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_807:
	/* 0x807: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_80f:
	/* 0x80f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_815:
	/* 0x815: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_81c:
	/* 0x81c: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_820:
	/* 0x820: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_823:
	/* 0x823: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_828:
	/* 0x828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82a:
	/* 0x82a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_82e:
	/* 0x82e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_832:
	/* 0x832: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_839:
	/* 0x839: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_83b:
	/* 0x83b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_83e:
	/* 0x83e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_843:
	/* 0x843: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_846:
	/* 0x846: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_848:
	/* 0x848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84a:
	/* 0x84a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_84d:
	/* 0x84d: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0x84d, 0xcec, x86_l_cec);
x86_l_852:
	/* 0x852: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_855:
	/* 0x855: je     b7f <generic_uprobe_actions+0xb7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x855, 0xb7f, x86_l_b7f);
x86_l_85b:
	/* 0x85b: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_85e:
	/* 0x85e: je     a89 <generic_uprobe_actions+0xa89> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85e, 0xa89, x86_l_a89);
x86_l_864:
	/* 0x864: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_867:
	/* 0x867: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x867, 0xcec, x86_l_cec);
x86_l_86d:
	/* 0x86d: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_870:
	/* 0x870: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_874:
	/* 0x874: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_879:
	/* 0x879: jmp    cc7 <generic_uprobe_actions+0xcc7> */
	X86_SIM_X86_JMP(0x879, 0xcc7, x86_l_cc7);
x86_l_87e:
	/* 0x87e: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_881:
	/* 0x881: je     b72 <generic_uprobe_actions+0xb72> */
	X86_SIM_X86_JCC(X86_CC_E, 0x881, 0xb72, x86_l_b72);
x86_l_887:
	/* 0x887: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_88a:
	/* 0x88a: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x88a, 0xcec, x86_l_cec);
x86_l_890:
	/* 0x890: mov    r14d,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_895:
	/* 0x895: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_899:
	/* 0x899: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_89e:
	/* 0x89e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8a3:
	/* 0x8a3: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8ac:
	/* 0x8ac: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b4:
	/* 0x8b4: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_8bc:
	/* 0x8bc: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_8c3:
	/* 0x8c3: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8c8:
	/* 0x8c8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8cd:
	/* 0x8cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8d2:
	/* 0x8d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d4:
	/* 0x8d4: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8d9:
	/* 0x8d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8dc:
	/* 0x8dc: je     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8dc, 0xcec, x86_l_cec);
x86_l_8e2:
	/* 0x8e2: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_8e6:
	/* 0x8e6: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_8ea:
	/* 0x8ea: ja     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8ea, 0xcec, x86_l_cec);
x86_l_8f0:
	/* 0x8f0: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_8f9:
	/* 0x8f9: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8f9, 0xcec, x86_l_cec);
x86_l_8ff:
	/* 0x8ff: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_904:
	/* 0x904: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_90c:
	/* 0x90c: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_914:
	/* 0x914: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_919:
	/* 0x919: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_920:
	/* 0x920: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_924:
	/* 0x924: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_929:
	/* 0x929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92b:
	/* 0x92b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_92f:
	/* 0x92f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_933:
	/* 0x933: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_936:
	/* 0x936: jne    c17 <generic_uprobe_actions+0xc17> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x936, 0xc17, x86_l_c17);
x86_l_93c:
	/* 0x93c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_941:
	/* 0x941: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_944:
	/* 0x944: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_947:
	/* 0x947: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_94c:
	/* 0x94c: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_951:
	/* 0x951: ja     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x951, 0xcec, x86_l_cec);
x86_l_957:
	/* 0x957: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_95a:
	/* 0x95a: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_962:
	/* 0x962: jne    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x962, 0xcec, x86_l_cec);
x86_l_968:
	/* 0x968: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_970:
	/* 0x970: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_976:
	/* 0x976: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_979:
	/* 0x979: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_980:
	/* 0x980: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_985:
	/* 0x985: mov    esi,DWORD PTR [rsi+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_98c:
	/* 0x98c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_992:
	/* 0x992: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_996:
	/* 0x996: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_99b:
	/* 0x99b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_99e:
	/* 0x99e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a0:
	/* 0x9a0: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9a7:
	/* 0x9a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a9:
	/* 0x9a9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9ac:
	/* 0x9ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9b1:
	/* 0x9b1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9b4:
	/* 0x9b4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b6:
	/* 0x9b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b8:
	/* 0x9b8: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9bd:
	/* 0x9bd: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0x9bd, 0xcec, x86_l_cec);
x86_l_9c2:
	/* 0x9c2: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9c5:
	/* 0x9c5: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0x9c5, 0xcec, x86_l_cec);
x86_l_9ca:
	/* 0x9ca: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9cd:
	/* 0x9cd: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_9d2:
	/* 0x9d2: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9d5:
	/* 0x9d5: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0x9d5, 0xcec, x86_l_cec);
x86_l_9da:
	/* 0x9da: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9e2:
	/* 0x9e2: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0x9e2, 0xcec, x86_l_cec);
x86_l_9e7:
	/* 0x9e7: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_9ea:
	/* 0x9ea: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9ed:
	/* 0x9ed: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_9f3:
	/* 0x9f3: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_9f8:
	/* 0x9f8: je     cc7 <generic_uprobe_actions+0xcc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f8, 0xcc7, x86_l_cc7);
x86_l_9fe:
	/* 0x9fe: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_a01:
	/* 0xa01: mov    eax,DWORD PTR [r12+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_a06:
	/* 0xa06: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a0a:
	/* 0xa0a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a0f:
	/* 0xa0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a11:
	/* 0xa11: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a16:
	/* 0xa16: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_a1d:
	/* 0xa1d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a22:
	/* 0xa22: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a27:
	/* 0xa27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a29:
	/* 0xa29: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a2c:
	/* 0xa2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a2f:
	/* 0xa2f: je     a3e <generic_uprobe_actions+0xa3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2f, 0xa3e, x86_l_a3e);
x86_l_a31:
	/* 0xa31: cmp    r14,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_a38:
	/* 0xa38: jb     cba <generic_uprobe_actions+0xcba> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa38, 0xcba, x86_l_cba);
x86_l_a3e:
	/* 0xa3e: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a41:
	/* 0xa41: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a43:
	/* 0xa43: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_a46:
	/* 0xa46: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a4b:
	/* 0xa4b: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_a4e:
	/* 0xa4e: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a52:
	/* 0xa52: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_a59:
	/* 0xa59: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_a63:
	/* 0xa63: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a68:
	/* 0xa68: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a6f:
	/* 0xa6f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a72:
	/* 0xa72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a77:
	/* 0xa77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a79:
	/* 0xa79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7c:
	/* 0xa7c: je     c8f <generic_uprobe_actions+0xc8f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7c, 0xc8f, x86_l_c8f);
x86_l_a82:
	/* 0xa82: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a84:
	/* 0xa84: jmp    cb1 <generic_uprobe_actions+0xcb1> */
	X86_SIM_X86_JMP(0xa84, 0xcb1, x86_l_cb1);
x86_l_a89:
	/* 0xa89: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_a8c:
	/* 0xa8c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a91:
	/* 0xa91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a93:
	/* 0xa93: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a98:
	/* 0xa98: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_a9f:
	/* 0xa9f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aa4:
	/* 0xaa4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aa9:
	/* 0xaa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aab:
	/* 0xaab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aae:
	/* 0xaae: je     afb <generic_uprobe_actions+0xafb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaae, 0xafb, x86_l_afb);
x86_l_ab0:
	/* 0xab0: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ab4:
	/* 0xab4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ab9:
	/* 0xab9: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_ac1:
	/* 0xac1: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_ac8:
	/* 0xac8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_acd:
	/* 0xacd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad2:
	/* 0xad2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad4:
	/* 0xad4: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_adc:
	/* 0xadc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_adf:
	/* 0xadf: je     b90 <generic_uprobe_actions+0xb90> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadf, 0xb90, x86_l_b90);
x86_l_ae5:
	/* 0xae5: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ae8:
	/* 0xae8: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_aef:
	/* 0xaef: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_af4:
	/* 0xaf4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_af9:
	/* 0xaf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_afb:
	/* 0xafb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_afe:
	/* 0xafe: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0xafe, 0xcec, x86_l_cec);
x86_l_b03:
	/* 0xb03: cmp    DWORD PTR [r12+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_b09:
	/* 0xb09: je     b31 <generic_uprobe_actions+0xb31> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb09, 0xb31, x86_l_b31);
x86_l_b0b:
	/* 0xb0b: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_b0f:
	/* 0xb0f: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_b12:
	/* 0xb12: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b19:
	/* 0xb19: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b1b:
	/* 0xb1b: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b20:
	/* 0xb20: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b23:
	/* 0xb23: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b25:
	/* 0xb25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b27:
	/* 0xb27: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b2a:
	/* 0xb2a: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b31:
	/* 0xb31: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b35:
	/* 0xb35: cmp    DWORD PTR [r12+r13*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 17179869184ULL);
x86_l_b3b:
	/* 0xb3b: je     cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb3b, 0xcec, x86_l_cec);
x86_l_b41:
	/* 0xb41: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_b45:
	/* 0xb45: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_b48:
	/* 0xb48: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b4f:
	/* 0xb4f: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_b54:
	/* 0xb54: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b59:
	/* 0xb59: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_b5e:
	/* 0xb5e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b61:
	/* 0xb61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b63:
	/* 0xb63: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b66:
	/* 0xb66: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b6d:
	/* 0xb6d: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0xb6d, 0xcec, x86_l_cec);
x86_l_b72:
	/* 0xb72: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_b75:
	/* 0xb75: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b7a:
	/* 0xb7a: jmp    cc7 <generic_uprobe_actions+0xcc7> */
	X86_SIM_X86_JMP(0xb7a, 0xcc7, x86_l_cc7);
x86_l_b7f:
	/* 0xb7f: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_b82:
	/* 0xb82: add    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_b86:
	/* 0xb86: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b8b:
	/* 0xb8b: jmp    cc7 <generic_uprobe_actions+0xcc7> */
	X86_SIM_X86_JMP(0xb8b, 0xcc7, x86_l_cc7);
x86_l_b90:
	/* 0xb90: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_b97:
	/* 0xb97: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b9c:
	/* 0xb9c: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ba1:
	/* 0xba1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ba6:
	/* 0xba6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bab:
	/* 0xbab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bad:
	/* 0xbad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bb0:
	/* 0xbb0: je     ae8 <generic_uprobe_actions+0xae8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb0, 0xae8, x86_l_ae8);
x86_l_bb6:
	/* 0xbb6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_bb9:
	/* 0xbb9: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_bbb:
	/* 0xbbb: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bbf:
	/* 0xbbf: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_bc6:
	/* 0xbc6: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_bd0:
	/* 0xbd0: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bd5:
	/* 0xbd5: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_bdc:
	/* 0xbdc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_bdf:
	/* 0xbdf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be4:
	/* 0xbe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be6:
	/* 0xbe6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be9:
	/* 0xbe9: je     11fe <generic_uprobe_actions+0x11fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe9, 0x11fe, x86_l_11fe);
x86_l_bef:
	/* 0xbef: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bf1:
	/* 0xbf1: jmp    1220 <generic_uprobe_actions+0x1220> */
	X86_SIM_X86_JMP(0xbf1, 0x1220, x86_l_1220);
x86_l_bf6:
	/* 0xbf6: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_bfd:
	/* 0xbfd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bff:
	/* 0xbff: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c04:
	/* 0xc04: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c09:
	/* 0xc09: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c0e:
	/* 0xc0e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c10:
	/* 0xc10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c12:
	/* 0xc12: jmp    669 <generic_uprobe_actions+0x669> */
	X86_SIM_X86_JMP(0xc12, 0x669, x86_l_669);
x86_l_c17:
	/* 0xc17: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_c1e:
	/* 0xc1e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c21:
	/* 0xc21: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c26:
	/* 0xc26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c28:
	/* 0xc28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c2a:
	/* 0xc2a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c2f:
	/* 0xc2f: jne    cf6 <generic_uprobe_actions+0xcf6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc2f, 0xcf6, x86_l_cf6);
x86_l_c35:
	/* 0xc35: jmp    cec <generic_uprobe_actions+0xcec> */
	X86_SIM_X86_JMP(0xc35, 0xcec, x86_l_cec);
x86_l_c3a:
	/* 0xc3a: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_c42:
	/* 0xc42: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c49:
	/* 0xc49: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4b:
	/* 0xc4b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c4e:
	/* 0xc4e: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c53:
	/* 0xc53: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c58:
	/* 0xc58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5a:
	/* 0xc5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5c:
	/* 0xc5c: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c61:
	/* 0xc61: je     45e <generic_uprobe_actions+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc61, 0x45e, x86_l_45e);
x86_l_c67:
	/* 0xc67: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c6e:
	/* 0xc6e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c73:
	/* 0xc73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c78:
	/* 0xc78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7a:
	/* 0xc7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c7d:
	/* 0xc7d: je     45e <generic_uprobe_actions+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7d, 0x45e, x86_l_45e);
x86_l_c83:
	/* 0xc83: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c87:
	/* 0xc87: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c8a:
	/* 0xc8a: jmp    45e <generic_uprobe_actions+0x45e> */
	X86_SIM_X86_JMP(0xc8a, 0x45e, x86_l_45e);
x86_l_c8f:
	/* 0xc8f: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_c97:
	/* 0xc97: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c9e:
	/* 0xc9e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca0:
	/* 0xca0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ca3:
	/* 0xca3: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ca8:
	/* 0xca8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cad:
	/* 0xcad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_caf:
	/* 0xcaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb1:
	/* 0xcb1: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_cb4:
	/* 0xcb4: je     11ba <generic_uprobe_actions+0x11ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb4, 0x11ba, x86_l_11ba);
x86_l_cba:
	/* 0xcba: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_cbe:
	/* 0xcbe: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc1:
	/* 0xcc1: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_cc7:
	/* 0xcc7: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cce:
	/* 0xcce: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_cd5:
	/* 0xcd5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_cd8:
	/* 0xcd8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdd:
	/* 0xcdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdf:
	/* 0xcdf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce2:
	/* 0xce2: je     ce9 <generic_uprobe_actions+0xce9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce2, 0xce9, x86_l_ce9);
x86_l_ce4:
	/* 0xce4: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ce9:
	/* 0xce9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_cec:
	/* 0xcec: mov    QWORD PTR [rdx+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cf0:
	/* 0xcf0: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cf3:
	/* 0xcf3: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_cf6:
	/* 0xcf6: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_cfe:
	/* 0xcfe: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d02:
	/* 0xd02: jae    d5c <generic_uprobe_actions+0xd5c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xd02, 0xd5c, x86_l_d5c);
x86_l_d04:
	/* 0xd04: mov    r15d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R15, X86_WIDTH_32);
x86_l_d07:
	/* 0xd07: movsxd rbp,DWORD PTR [r12+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_d0c:
	/* 0xd0c: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_d14:
	/* 0xd14: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_d1b:
	/* 0xd1b: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d20:
	/* 0xd20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d25:
	/* 0xd25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d27:
	/* 0xd27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d2a:
	/* 0xd2a: je     d5c <generic_uprobe_actions+0xd5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2a, 0xd5c, x86_l_d5c);
x86_l_d2c:
	/* 0xd2c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d2f:
	/* 0xd2f: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d32:
	/* 0xd32: jle    d66 <generic_uprobe_actions+0xd66> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xd32, 0xd66, x86_l_d66);
x86_l_d34:
	/* 0xd34: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_d37:
	/* 0xd37: jg     d8a <generic_uprobe_actions+0xd8a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd37, 0xd8a, x86_l_d8a);
x86_l_d39:
	/* 0xd39: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_d3c:
	/* 0xd3c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d3f:
	/* 0xd3f: jb     ebf <generic_uprobe_actions+0xebf> */
	X86_SIM_X86_JCC(X86_CC_B, 0xd3f, 0xebf, x86_l_ebf);
x86_l_d45:
	/* 0xd45: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d48:
	/* 0xd48: je     fd6 <generic_uprobe_actions+0xfd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd48, 0xfd6, x86_l_fd6);
x86_l_d4e:
	/* 0xd4e: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_d51:
	/* 0xd51: je     1289 <generic_uprobe_actions+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd51, 0x1289, x86_l_1289);
x86_l_d57:
	/* 0xd57: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0xd57, 0x12b0, x86_l_12b0);
x86_l_d5c:
	/* 0xd5c: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d61:
	/* 0xd61: jmp    12b9 <generic_uprobe_actions+0x12b9> */
	X86_SIM_X86_JMP(0xd61, 0x12b9, x86_l_12b9);
x86_l_d66:
	/* 0xd66: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d69:
	/* 0xd69: jg     dbe <generic_uprobe_actions+0xdbe> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd69, 0xdbe, x86_l_dbe);
x86_l_d6b:
	/* 0xd6b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_d6d:
	/* 0xd6d: je     1056 <generic_uprobe_actions+0x1056> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6d, 0x1056, x86_l_1056);
x86_l_d73:
	/* 0xd73: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_d76:
	/* 0xd76: je     ecd <generic_uprobe_actions+0xecd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd76, 0xecd, x86_l_ecd);
x86_l_d7c:
	/* 0xd7c: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d7f:
	/* 0xd7f: je     1289 <generic_uprobe_actions+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7f, 0x1289, x86_l_1289);
x86_l_d85:
	/* 0xd85: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0xd85, 0x12b0, x86_l_12b0);
x86_l_d8a:
	/* 0xd8a: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d8f:
	/* 0xd8f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d94:
	/* 0xd94: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_d97:
	/* 0xd97: je     1289 <generic_uprobe_actions+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd97, 0x1289, x86_l_1289);
x86_l_d9d:
	/* 0xd9d: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_da0:
	/* 0xda0: je     fde <generic_uprobe_actions+0xfde> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda0, 0xfde, x86_l_fde);
x86_l_da6:
	/* 0xda6: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dab:
	/* 0xdab: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db0:
	/* 0xdb0: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_db3:
	/* 0xdb3: je     1289 <generic_uprobe_actions+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb3, 0x1289, x86_l_1289);
x86_l_db9:
	/* 0xdb9: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0xdb9, 0x12b0, x86_l_12b0);
x86_l_dbe:
	/* 0xdbe: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_dc1:
	/* 0xdc1: je     ecd <generic_uprobe_actions+0xecd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdc1, 0xecd, x86_l_ecd);
x86_l_dc7:
	/* 0xdc7: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_dca:
	/* 0xdca: je     10b7 <generic_uprobe_actions+0x10b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdca, 0x10b7, x86_l_10b7);
x86_l_dd0:
	/* 0xdd0: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_dd3:
	/* 0xdd3: jne    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdd3, 0x12b0, x86_l_12b0);
x86_l_dd9:
	/* 0xdd9: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_dde:
	/* 0xdde: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_de3:
	/* 0xde3: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_dec:
	/* 0xdec: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df4:
	/* 0xdf4: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_df7:
	/* 0xdf7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dfa:
	/* 0xdfa: ja     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xdfa, 0x12b0, x86_l_12b0);
x86_l_e00:
	/* 0xe00: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_e09:
	/* 0xe09: jne    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe09, 0x12b0, x86_l_12b0);
x86_l_e0f:
	/* 0xe0f: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_e17:
	/* 0xe17: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e1c:
	/* 0xe1c: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_e24:
	/* 0xe24: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e28:
	/* 0xe28: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e2d:
	/* 0xe2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2f:
	/* 0xe2f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e33:
	/* 0xe33: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e37:
	/* 0xe37: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e3e:
	/* 0xe3e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e41:
	/* 0xe41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e46:
	/* 0xe46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e48:
	/* 0xe48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4b:
	/* 0xe4b: je     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe4b, 0x12b0, x86_l_12b0);
x86_l_e51:
	/* 0xe51: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e55:
	/* 0xe55: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_e59:
	/* 0xe59: ja     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe59, 0x12b0, x86_l_12b0);
x86_l_e5f:
	/* 0xe5f: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_e68:
	/* 0xe68: jne    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe68, 0x12b0, x86_l_12b0);
x86_l_e6e:
	/* 0xe6e: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_e76:
	/* 0xe76: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_e7e:
	/* 0xe7e: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e84:
	/* 0xe84: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e8c:
	/* 0xe8c: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e90:
	/* 0xe90: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e93:
	/* 0xe93: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e98:
	/* 0xe98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9a:
	/* 0xe9a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e9e:
	/* 0xe9e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea2:
	/* 0xea2: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_ea9:
	/* 0xea9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eab:
	/* 0xeab: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_eae:
	/* 0xeae: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_eb3:
	/* 0xeb3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_eb6:
	/* 0xeb6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb8:
	/* 0xeb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eba:
	/* 0xeba: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0xeba, 0x12b0, x86_l_12b0);
x86_l_ebf:
	/* 0xebf: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_ec4:
	/* 0xec4: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ec8:
	/* 0xec8: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0xec8, 0x12b0, x86_l_12b0);
x86_l_ecd:
	/* 0xecd: mov    r13d,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_ed2:
	/* 0xed2: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_ed7:
	/* 0xed7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ee0:
	/* 0xee0: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee8:
	/* 0xee8: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ef0:
	/* 0xef0: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_ef7:
	/* 0xef7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_efc:
	/* 0xefc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f01:
	/* 0xf01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f03:
	/* 0xf03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f06:
	/* 0xf06: je     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf06, 0x12b0, x86_l_12b0);
x86_l_f0c:
	/* 0xf0c: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f10:
	/* 0xf10: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_f14:
	/* 0xf14: ja     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf14, 0x12b0, x86_l_12b0);
x86_l_f1a:
	/* 0xf1a: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_f23:
	/* 0xf23: jne    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf23, 0x12b0, x86_l_12b0);
x86_l_f29:
	/* 0xf29: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_f2c:
	/* 0xf2c: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_f34:
	/* 0xf34: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_f3c:
	/* 0xf3c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f41:
	/* 0xf41: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_f49:
	/* 0xf49: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4d:
	/* 0xf4d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f52:
	/* 0xf52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f54:
	/* 0xf54: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_f58:
	/* 0xf58: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5c:
	/* 0xf5c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_f5f:
	/* 0xf5f: jne    11db <generic_uprobe_actions+0x11db> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf5f, 0x11db, x86_l_11db);
x86_l_f65:
	/* 0xf65: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f69:
	/* 0xf69: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_f6d:
	/* 0xf6d: ja     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf6d, 0x12b0, x86_l_12b0);
x86_l_f73:
	/* 0xf73: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_f7c:
	/* 0xf7c: jne    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf7c, 0x12b0, x86_l_12b0);
x86_l_f82:
	/* 0xf82: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_f8a:
	/* 0xf8a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f8f:
	/* 0xf8f: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f93:
	/* 0xf93: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f9a:
	/* 0xf9a: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_fa2:
	/* 0xfa2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fa8:
	/* 0xfa8: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_fac:
	/* 0xfac: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_faf:
	/* 0xfaf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fb4:
	/* 0xfb4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_fb7:
	/* 0xfb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb9:
	/* 0xfb9: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_fc0:
	/* 0xfc0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc2:
	/* 0xfc2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fc5:
	/* 0xfc5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fca:
	/* 0xfca: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_fcd:
	/* 0xfcd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fcf:
	/* 0xfcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd1:
	/* 0xfd1: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0xfd1, 0x12b0, x86_l_12b0);
x86_l_fd6:
	/* 0xfd6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd9:
	/* 0xfd9: jmp    12b5 <generic_uprobe_actions+0x12b5> */
	X86_SIM_X86_JMP(0xfd9, 0x12b5, x86_l_12b5);
x86_l_fde:
	/* 0xfde: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fe3:
	/* 0xfe3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe5:
	/* 0xfe5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fea:
	/* 0xfea: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_ff1:
	/* 0xff1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ff6:
	/* 0xff6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ffb:
	/* 0xffb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffd:
	/* 0xffd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1000:
	/* 0x1000: je     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1000, 0x12b0, x86_l_12b0);
x86_l_1006:
	/* 0x1006: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_100a:
	/* 0x100a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_100f:
	/* 0x100f: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_1017:
	/* 0x1017: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_101e:
	/* 0x101e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1023:
	/* 0x1023: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1028:
	/* 0x1028: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102a:
	/* 0x102a: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_1032:
	/* 0x1032: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1035:
	/* 0x1035: je     1154 <generic_uprobe_actions+0x1154> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1035, 0x1154, x86_l_1154);
x86_l_103b:
	/* 0x103b: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_103e:
	/* 0x103e: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1045:
	/* 0x1045: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_104a:
	/* 0x104a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_104f:
	/* 0x104f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1051:
	/* 0x1051: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0x1051, 0x12b0, x86_l_12b0);
x86_l_1056:
	/* 0x1056: cmp    DWORD PTR [r12+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_105c:
	/* 0x105c: je     107f <generic_uprobe_actions+0x107f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105c, 0x107f, x86_l_107f);
x86_l_105e:
	/* 0x105e: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_1063:
	/* 0x1063: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_106a:
	/* 0x106a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_106c:
	/* 0x106c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1071:
	/* 0x1071: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1074:
	/* 0x1074: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1076:
	/* 0x1076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1078:
	/* 0x1078: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_107f:
	/* 0x107f: cmp    DWORD PTR [r12+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_1085:
	/* 0x1085: je     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1085, 0x12b0, x86_l_12b0);
x86_l_108b:
	/* 0x108b: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_1090:
	/* 0x1090: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1097:
	/* 0x1097: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_109c:
	/* 0x109c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_10a1:
	/* 0x10a1: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_10a6:
	/* 0x10a6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10a9:
	/* 0x10a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ab:
	/* 0x10ab: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_10b2:
	/* 0x10b2: jmp    12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JMP(0x10b2, 0x12b0, x86_l_12b0);
x86_l_10b7:
	/* 0x10b7: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_10bc:
	/* 0x10bc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10c1:
	/* 0x10c1: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_10c6:
	/* 0x10c6: je     1289 <generic_uprobe_actions+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10c6, 0x1289, x86_l_1289);
x86_l_10cc:
	/* 0x10cc: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_10d1:
	/* 0x10d1: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10d5:
	/* 0x10d5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10da:
	/* 0x10da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10dc:
	/* 0x10dc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10e1:
	/* 0x10e1: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_10e8:
	/* 0x10e8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ed:
	/* 0x10ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10f2:
	/* 0x10f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f4:
	/* 0x10f4: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_10f7:
	/* 0x10f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10fa:
	/* 0x10fa: je     1109 <generic_uprobe_actions+0x1109> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fa, 0x1109, x86_l_1109);
x86_l_10fc:
	/* 0x10fc: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_1103:
	/* 0x1103: jb     1278 <generic_uprobe_actions+0x1278> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1103, 0x1278, x86_l_1278);
x86_l_1109:
	/* 0x1109: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_110c:
	/* 0x110c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_110e:
	/* 0x110e: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1111:
	/* 0x1111: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1116:
	/* 0x1116: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1119:
	/* 0x1119: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111d:
	/* 0x111d: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_1124:
	/* 0x1124: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_112e:
	/* 0x112e: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1133:
	/* 0x1133: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_113a:
	/* 0x113a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_113d:
	/* 0x113d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1142:
	/* 0x1142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1144:
	/* 0x1144: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1147:
	/* 0x1147: je     1251 <generic_uprobe_actions+0x1251> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1147, 0x1251, x86_l_1251);
x86_l_114d:
	/* 0x114d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_114f:
	/* 0x114f: jmp    1273 <generic_uprobe_actions+0x1273> */
	X86_SIM_X86_JMP(0x114f, 0x1273, x86_l_1273);
x86_l_1154:
	/* 0x1154: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_115b:
	/* 0x115b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1160:
	/* 0x1160: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1165:
	/* 0x1165: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_116a:
	/* 0x116a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_116f:
	/* 0x116f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1171:
	/* 0x1171: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1174:
	/* 0x1174: je     103e <generic_uprobe_actions+0x103e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1174, 0x103e, x86_l_103e);
x86_l_117a:
	/* 0x117a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_117d:
	/* 0x117d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_117f:
	/* 0x117f: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1183:
	/* 0x1183: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_118a:
	/* 0x118a: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_1194:
	/* 0x1194: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1199:
	/* 0x1199: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11a0:
	/* 0x11a0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11a3:
	/* 0x11a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a8:
	/* 0x11a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11aa:
	/* 0x11aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11ad:
	/* 0x11ad: je     130f <generic_uprobe_actions+0x130f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ad, 0x130f, x86_l_130f);
x86_l_11b3:
	/* 0x11b3: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_11b5:
	/* 0x11b5: jmp    1331 <generic_uprobe_actions+0x1331> */
	X86_SIM_X86_JMP(0x11b5, 0x1331, x86_l_1331);
x86_l_11ba:
	/* 0x11ba: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_11c1:
	/* 0x11c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11c3:
	/* 0x11c3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c8:
	/* 0x11c8: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11cd:
	/* 0x11cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11d2:
	/* 0x11d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d4:
	/* 0x11d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d6:
	/* 0x11d6: jmp    cc1 <generic_uprobe_actions+0xcc1> */
	X86_SIM_X86_JMP(0x11d6, 0xcc1, x86_l_cc1);
x86_l_11db:
	/* 0x11db: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_11e2:
	/* 0x11e2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11e5:
	/* 0x11e5: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_11ea:
	/* 0x11ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ec:
	/* 0x11ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11ee:
	/* 0x11ee: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f3:
	/* 0x11f3: jne    12b9 <generic_uprobe_actions+0x12b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11f3, 0x12b9, x86_l_12b9);
x86_l_11f9:
	/* 0x11f9: jmp    12b5 <generic_uprobe_actions+0x12b5> */
	X86_SIM_X86_JMP(0x11f9, 0x12b5, x86_l_12b5);
x86_l_11fe:
	/* 0x11fe: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_1206:
	/* 0x1206: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_120d:
	/* 0x120d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120f:
	/* 0x120f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1212:
	/* 0x1212: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1217:
	/* 0x1217: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_121c:
	/* 0x121c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1223:
	/* 0x1223: je     ae8 <generic_uprobe_actions+0xae8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1223, 0xae8, x86_l_ae8);
x86_l_1229:
	/* 0x1229: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1230:
	/* 0x1230: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1235:
	/* 0x1235: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_123a:
	/* 0x123a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123c:
	/* 0x123c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_123f:
	/* 0x123f: je     ae8 <generic_uprobe_actions+0xae8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x123f, 0xae8, x86_l_ae8);
x86_l_1245:
	/* 0x1245: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1249:
	/* 0x1249: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_124c:
	/* 0x124c: jmp    ae8 <generic_uprobe_actions+0xae8> */
	X86_SIM_X86_JMP(0x124c, 0xae8, x86_l_ae8);
x86_l_1251:
	/* 0x1251: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1259:
	/* 0x1259: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1260:
	/* 0x1260: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1262:
	/* 0x1262: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1265:
	/* 0x1265: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_126a:
	/* 0x126a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_126f:
	/* 0x126f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1271:
	/* 0x1271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1273:
	/* 0x1273: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1276:
	/* 0x1276: je     12ee <generic_uprobe_actions+0x12ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1276, 0x12ee, x86_l_12ee);
x86_l_1278:
	/* 0x1278: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_127c:
	/* 0x127c: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127f:
	/* 0x127f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1284:
	/* 0x1284: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1289:
	/* 0x1289: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1290:
	/* 0x1290: mov    rdi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_1297:
	/* 0x1297: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_129a:
	/* 0x129a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_129f:
	/* 0x129f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a1:
	/* 0x12a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a4:
	/* 0x12a4: je     12b0 <generic_uprobe_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a4, 0x12b0, x86_l_12b0);
x86_l_12a6:
	/* 0x12a6: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12ab:
	/* 0x12ab: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_12b0:
	/* 0x12b0: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b5:
	/* 0x12b5: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12b9:
	/* 0x12b9: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_12bc:
	/* 0x12bc: je     12d9 <generic_uprobe_actions+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12bc, 0x12d9, x86_l_12d9);
x86_l_12be:
	/* 0x12be: mov    rsi,QWORD PTR [rip+0x5970] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_12c5:
	/* 0x12c5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_12ca:
	/* 0x12ca: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_12cf:
	/* 0x12cf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12d2:
	/* 0x12d2: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12d7:
	/* 0x12d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d9:
	/* 0x12d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12db:
	/* 0x12db: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_12df:
	/* 0x12df: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_12e0:
	/* 0x12e0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_12e2:
	/* 0x12e2: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_12e4:
	/* 0x12e4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_12e6:
	/* 0x12e6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_12e8:
	/* 0x12e8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_12e9:
	/* 0x12e9: jmp    1362 <generic_uprobe_actions+0x1362> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_12ee:
	/* 0x12ee: mov    rdi,QWORD PTR [rip+0x596c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_12f5:
	/* 0x12f5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f7:
	/* 0x12f7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12fc:
	/* 0x12fc: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1301:
	/* 0x1301: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1306:
	/* 0x1306: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1308:
	/* 0x1308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130a:
	/* 0x130a: jmp    127f <generic_uprobe_actions+0x127f> */
	X86_SIM_X86_JMP(0x130a, 0x127f, x86_l_127f);
x86_l_130f:
	/* 0x130f: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_1317:
	/* 0x1317: mov    rdi,QWORD PTR [rip+0x596c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_131e:
	/* 0x131e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1320:
	/* 0x1320: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1323:
	/* 0x1323: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1328:
	/* 0x1328: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_132d:
	/* 0x132d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132f:
	/* 0x132f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1331:
	/* 0x1331: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1334:
	/* 0x1334: je     103e <generic_uprobe_actions+0x103e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1334, 0x103e, x86_l_103e);
x86_l_133a:
	/* 0x133a: mov    rdi,QWORD PTR [rip+0x596c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1341:
	/* 0x1341: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1346:
	/* 0x1346: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134b:
	/* 0x134b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134d:
	/* 0x134d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1350:
	/* 0x1350: je     103e <generic_uprobe_actions+0x103e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1350, 0x103e, x86_l_103e);
x86_l_1356:
	/* 0x1356: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_135a:
	/* 0x135a: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_135d:
	/* 0x135d: jmp    103e <generic_uprobe_actions+0x103e> */
	X86_SIM_X86_JMP(0x135d, 0x103e, x86_l_103e);
x86_l_1362:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
