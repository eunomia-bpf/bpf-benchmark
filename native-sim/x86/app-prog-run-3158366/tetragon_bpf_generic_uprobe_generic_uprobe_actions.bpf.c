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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 120ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_12:
	/* 0x12: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     12d2 <generic_uprobe_actions+0x12d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x12d2, x86_l_12d2);
x86_l_2e:
	/* 0x2e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: mov    r12d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_38:
	/* 0x38: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3c:
	/* 0x3c: jl     12d2 <generic_uprobe_actions+0x12d2> */
	X86_SIM_X86_JCC(X86_CC_L, 0x3c, 0x12d2, x86_l_12d2);
x86_l_42:
	/* 0x42: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_49:
	/* 0x49: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_50:
	/* 0x50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55:
	/* 0x55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57:
	/* 0x57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a:
	/* 0x5a: je     12d2 <generic_uprobe_actions+0x12d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a, 0x12d2, x86_l_12d2);
x86_l_60:
	/* 0x60: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_63:
	/* 0x63: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_69:
	/* 0x69: add    r12d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6d:
	/* 0x6d: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_75:
	/* 0x75: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_7c:
	/* 0x7c: lea    rsi,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_81:
	/* 0x81: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89:
	/* 0x89: and    r12d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_90:
	/* 0x90: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_93:
	/* 0x93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95:
	/* 0x95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98:
	/* 0x98: je     bd <generic_uprobe_actions+0xbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x98, 0xbd, x86_l_bd);
x86_l_9a:
	/* 0x9a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d:
	/* 0x9d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a0:
	/* 0xa0: je     da <generic_uprobe_actions+0xda> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xda, x86_l_da);
x86_l_a2:
	/* 0xa2: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a7:
	/* 0xa7: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_ac:
	/* 0xac: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_b1:
	/* 0xb1: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b6:
	/* 0xb6: ja     f4 <generic_uprobe_actions+0xf4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb6, 0xf4, x86_l_f4);
x86_l_b8:
	/* 0xb8: jmp    12b7 <generic_uprobe_actions+0x12b7> */
	X86_SIM_X86_JMP(0xb8, 0x12b7, x86_l_12b7);
x86_l_bd:
	/* 0xbd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c2:
	/* 0xc2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c7:
	/* 0xc7: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_c9:
	/* 0xc9: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_ce:
	/* 0xce: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d3:
	/* 0xd3: ja     f4 <generic_uprobe_actions+0xf4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd3, 0xf4, x86_l_f4);
x86_l_d5:
	/* 0xd5: jmp    12b7 <generic_uprobe_actions+0x12b7> */
	X86_SIM_X86_JMP(0xd5, 0x12b7, x86_l_12b7);
x86_l_da:
	/* 0xda: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_df:
	/* 0xdf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e4:
	/* 0xe4: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_e9:
	/* 0xe9: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ee:
	/* 0xee: jbe    12b7 <generic_uprobe_actions+0x12b7> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xee, 0x12b7, x86_l_12b7);
x86_l_f4:
	/* 0xf4: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fe:
	/* 0xfe: mov    BYTE PTR [rsp+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_102:
	/* 0x102: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_107:
	/* 0x107: movsxd rbp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_10c:
	/* 0x10c: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_114:
	/* 0x114: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_11b:
	/* 0x11b: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_120:
	/* 0x120: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_125:
	/* 0x125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127:
	/* 0x127: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: je     15e <generic_uprobe_actions+0x15e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a, 0x15e, x86_l_15e);
x86_l_12c:
	/* 0x12c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132:
	/* 0x132: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_135:
	/* 0x135: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_138:
	/* 0x138: jg     169 <generic_uprobe_actions+0x169> */
	X86_SIM_X86_JCC(X86_CC_G, 0x138, 0x169, x86_l_169);
x86_l_13a:
	/* 0x13a: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_13d:
	/* 0x13d: jg     1a0 <generic_uprobe_actions+0x1a0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13d, 0x1a0, x86_l_1a0);
x86_l_13f:
	/* 0x13f: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_142:
	/* 0x142: jg     2c8 <generic_uprobe_actions+0x2c8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x142, 0x2c8, x86_l_2c8);
x86_l_148:
	/* 0x148: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_14a:
	/* 0x14a: je     46f <generic_uprobe_actions+0x46f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a, 0x46f, x86_l_46f);
x86_l_150:
	/* 0x150: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_153:
	/* 0x153: je     2da <generic_uprobe_actions+0x2da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x153, 0x2da, x86_l_2da);
x86_l_159:
	/* 0x159: jmp    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JMP(0x159, 0x68d, x86_l_68d);
x86_l_15e:
	/* 0x15e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161:
	/* 0x161: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_164:
	/* 0x164: jmp    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JMP(0x164, 0x694, x86_l_694);
x86_l_169:
	/* 0x169: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_16c:
	/* 0x16c: jg     29d <generic_uprobe_actions+0x29d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16c, 0x29d, x86_l_29d);
x86_l_172:
	/* 0x172: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_175:
	/* 0x175: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_178:
	/* 0x178: jb     342 <generic_uprobe_actions+0x342> */
	X86_SIM_X86_JCC(X86_CC_B, 0x178, 0x342, x86_l_342);
x86_l_17e:
	/* 0x17e: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_181:
	/* 0x181: je     34d <generic_uprobe_actions+0x34d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x34d, x86_l_34d);
x86_l_187:
	/* 0x187: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_18a:
	/* 0x18a: jne    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a, 0x68d, x86_l_68d);
x86_l_190:
	/* 0x190: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_196:
	/* 0x196: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19b:
	/* 0x19b: jmp    668 <generic_uprobe_actions+0x668> */
	X86_SIM_X86_JMP(0x19b, 0x668, x86_l_668);
x86_l_1a0:
	/* 0x1a0: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1a3:
	/* 0x1a3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a6:
	/* 0x1a6: jb     339 <generic_uprobe_actions+0x339> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a6, 0x339, x86_l_339);
x86_l_1ac:
	/* 0x1ac: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1af:
	/* 0x1af: je     358 <generic_uprobe_actions+0x358> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1af, 0x358, x86_l_358);
x86_l_1b5:
	/* 0x1b5: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1b8:
	/* 0x1b8: jne    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b8, 0x68d, x86_l_68d);
x86_l_1be:
	/* 0x1be: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c3:
	/* 0x1c3: mov    r15d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d1:
	/* 0x1d1: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9:
	/* 0x1d9: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1dc:
	/* 0x1dc: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1df:
	/* 0x1df: ja     32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1df, 0x32e, x86_l_32e);
x86_l_1e5:
	/* 0x1e5: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1ee:
	/* 0x1ee: jne    32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ee, 0x32e, x86_l_32e);
x86_l_1f4:
	/* 0x1f4: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1fc:
	/* 0x1fc: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_201:
	/* 0x201: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_209:
	/* 0x209: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d:
	/* 0x20d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_212:
	/* 0x212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214:
	/* 0x214: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_218:
	/* 0x218: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c:
	/* 0x21c: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_223:
	/* 0x223: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_226:
	/* 0x226: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22b:
	/* 0x22b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d:
	/* 0x22d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_230:
	/* 0x230: je     32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x230, 0x32e, x86_l_32e);
x86_l_236:
	/* 0x236: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_23a:
	/* 0x23a: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_23e:
	/* 0x23e: ja     32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x23e, 0x32e, x86_l_32e);
x86_l_244:
	/* 0x244: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_24d:
	/* 0x24d: jne    32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24d, 0x32e, x86_l_32e);
x86_l_253:
	/* 0x253: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_25b:
	/* 0x25b: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_263:
	/* 0x263: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_269:
	/* 0x269: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_271:
	/* 0x271: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_275:
	/* 0x275: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_278:
	/* 0x278: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_27d:
	/* 0x27d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f:
	/* 0x27f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_283:
	/* 0x283: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_287:
	/* 0x287: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_28e:
	/* 0x28e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_290:
	/* 0x290: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_293:
	/* 0x293: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_298:
	/* 0x298: jmp    599 <generic_uprobe_actions+0x599> */
	X86_SIM_X86_JMP(0x298, 0x599, x86_l_599);
x86_l_29d:
	/* 0x29d: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_2a0:
	/* 0x2a0: je     4e0 <generic_uprobe_actions+0x4e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a0, 0x4e0, x86_l_4e0);
x86_l_2a6:
	/* 0x2a6: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_2a9:
	/* 0x2a9: je     3f7 <generic_uprobe_actions+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a9, 0x3f7, x86_l_3f7);
x86_l_2af:
	/* 0x2af: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_2b2:
	/* 0x2b2: jne    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b2, 0x68d, x86_l_68d);
x86_l_2b8:
	/* 0x2b8: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2be:
	/* 0x2be: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c3:
	/* 0x2c3: jmp    668 <generic_uprobe_actions+0x668> */
	X86_SIM_X86_JMP(0x2c3, 0x668, x86_l_668);
x86_l_2c8:
	/* 0x2c8: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2cb:
	/* 0x2cb: je     4d6 <generic_uprobe_actions+0x4d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2cb, 0x4d6, x86_l_4d6);
x86_l_2d1:
	/* 0x2d1: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2d4:
	/* 0x2d4: jne    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d4, 0x68d, x86_l_68d);
x86_l_2da:
	/* 0x2da: mov    r13d,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2df:
	/* 0x2df: mov    r15d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e4:
	/* 0x2e4: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ed:
	/* 0x2ed: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5:
	/* 0x2f5: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2fd:
	/* 0x2fd: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_304:
	/* 0x304: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_309:
	/* 0x309: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: je     32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x313, 0x32e, x86_l_32e);
x86_l_315:
	/* 0x315: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_319:
	/* 0x319: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_31d:
	/* 0x31d: ja     32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x31d, 0x32e, x86_l_32e);
x86_l_31f:
	/* 0x31f: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_328:
	/* 0x328: je     4f0 <generic_uprobe_actions+0x4f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x328, 0x4f0, x86_l_4f0);
x86_l_32e:
	/* 0x32e: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_334:
	/* 0x334: jmp    68a <generic_uprobe_actions+0x68a> */
	X86_SIM_X86_JMP(0x334, 0x68a, x86_l_68a);
x86_l_339:
	/* 0x339: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33e:
	/* 0x33e: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_342:
	/* 0x342: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_348:
	/* 0x348: jmp    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JMP(0x348, 0x68d, x86_l_68d);
x86_l_34d:
	/* 0x34d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_350:
	/* 0x350: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_353:
	/* 0x353: jmp    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JMP(0x353, 0x68d, x86_l_68d);
x86_l_358:
	/* 0x358: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_35e:
	/* 0x35e: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_364:
	/* 0x364: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_369:
	/* 0x369: je     668 <generic_uprobe_actions+0x668> */
	X86_SIM_X86_JCC(X86_CC_E, 0x369, 0x668, x86_l_668);
x86_l_36f:
	/* 0x36f: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_374:
	/* 0x374: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_378:
	/* 0x378: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_37d:
	/* 0x37d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f:
	/* 0x37f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_384:
	/* 0x384: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_38b:
	/* 0x38b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_390:
	/* 0x390: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_395:
	/* 0x395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397:
	/* 0x397: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39d:
	/* 0x39d: je     3ac <generic_uprobe_actions+0x3ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39d, 0x3ac, x86_l_3ac);
x86_l_39f:
	/* 0x39f: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_3a6:
	/* 0x3a6: jb     65b <generic_uprobe_actions+0x65b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3a6, 0x65b, x86_l_65b);
x86_l_3ac:
	/* 0x3ac: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_3af:
	/* 0x3af: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_3b1:
	/* 0x3b1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3b4:
	/* 0x3b4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3b9:
	/* 0x3b9: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_3bc:
	/* 0x3bc: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c0:
	/* 0x3c0: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_3c7:
	/* 0x3c7: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_3d1:
	/* 0x3d1: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d6:
	/* 0x3d6: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_3dd:
	/* 0x3dd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3e0:
	/* 0x3e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e5:
	/* 0x3e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e7:
	/* 0x3e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ea:
	/* 0x3ea: je     630 <generic_uprobe_actions+0x630> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ea, 0x630, x86_l_630);
x86_l_3f0:
	/* 0x3f0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3f2:
	/* 0x3f2: jmp    652 <generic_uprobe_actions+0x652> */
	X86_SIM_X86_JMP(0x3f2, 0x652, x86_l_652);
x86_l_3f7:
	/* 0x3f7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3fc:
	/* 0x3fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fe:
	/* 0x3fe: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_403:
	/* 0x403: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_40a:
	/* 0x40a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40f:
	/* 0x40f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_414:
	/* 0x414: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_416:
	/* 0x416: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_419:
	/* 0x419: je     68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x419, 0x68d, x86_l_68d);
x86_l_41f:
	/* 0x41f: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_428:
	/* 0x428: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_430:
	/* 0x430: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_437:
	/* 0x437: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43c:
	/* 0x43c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_441:
	/* 0x441: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_443:
	/* 0x443: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_44b:
	/* 0x44b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44e:
	/* 0x44e: je     5a5 <generic_uprobe_actions+0x5a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44e, 0x5a5, x86_l_5a5);
x86_l_454:
	/* 0x454: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_457:
	/* 0x457: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_45e:
	/* 0x45e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_463:
	/* 0x463: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_468:
	/* 0x468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46a:
	/* 0x46a: jmp    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JMP(0x46a, 0x68d, x86_l_68d);
x86_l_46f:
	/* 0x46f: cmp    DWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_475:
	/* 0x475: je     498 <generic_uprobe_actions+0x498> */
	X86_SIM_X86_JCC(X86_CC_E, 0x475, 0x498, x86_l_498);
x86_l_477:
	/* 0x477: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_47c:
	/* 0x47c: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_483:
	/* 0x483: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_485:
	/* 0x485: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_48a:
	/* 0x48a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_48d:
	/* 0x48d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48f:
	/* 0x48f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491:
	/* 0x491: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_498:
	/* 0x498: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_49e:
	/* 0x49e: cmp    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_4a4:
	/* 0x4a4: je     68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a4, 0x68d, x86_l_68d);
x86_l_4aa:
	/* 0x4aa: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_4af:
	/* 0x4af: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_4b6:
	/* 0x4b6: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_4bb:
	/* 0x4bb: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_4c0:
	/* 0x4c0: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_4c5:
	/* 0x4c5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4d1:
	/* 0x4d1: jmp    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JMP(0x4d1, 0x68d, x86_l_68d);
x86_l_4d6:
	/* 0x4d6: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4db:
	/* 0x4db: jmp    668 <generic_uprobe_actions+0x668> */
	X86_SIM_X86_JMP(0x4db, 0x668, x86_l_668);
x86_l_4e0:
	/* 0x4e0: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_4e6:
	/* 0x4e6: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4eb:
	/* 0x4eb: jmp    668 <generic_uprobe_actions+0x668> */
	X86_SIM_X86_JMP(0x4eb, 0x668, x86_l_668);
x86_l_4f0:
	/* 0x4f0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f5:
	/* 0x4f5: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_4fd:
	/* 0x4fd: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_505:
	/* 0x505: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_50a:
	/* 0x50a: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_512:
	/* 0x512: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_516:
	/* 0x516: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_51b:
	/* 0x51b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d:
	/* 0x51d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_521:
	/* 0x521: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_525:
	/* 0x525: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_528:
	/* 0x528: jne    60d <generic_uprobe_actions+0x60d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x528, 0x60d, x86_l_60d);
x86_l_52e:
	/* 0x52e: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_532:
	/* 0x532: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_536:
	/* 0x536: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53b:
	/* 0x53b: ja     32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x53b, 0x32e, x86_l_32e);
x86_l_541:
	/* 0x541: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_54a:
	/* 0x54a: jne    32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x54a, 0x32e, x86_l_32e);
x86_l_550:
	/* 0x550: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_558:
	/* 0x558: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_55e:
	/* 0x55e: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_562:
	/* 0x562: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_569:
	/* 0x569: mov    esi,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_571:
	/* 0x571: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_577:
	/* 0x577: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_57b:
	/* 0x57b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_57e:
	/* 0x57e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_583:
	/* 0x583: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_586:
	/* 0x586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_588:
	/* 0x588: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_58f:
	/* 0x58f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_591:
	/* 0x591: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_594:
	/* 0x594: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_599:
	/* 0x599: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59e:
	/* 0x59e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a0:
	/* 0x5a0: jmp    32e <generic_uprobe_actions+0x32e> */
	X86_SIM_X86_JMP(0x5a0, 0x32e, x86_l_32e);
x86_l_5a5:
	/* 0x5a5: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_5ac:
	/* 0x5ac: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b1:
	/* 0x5b1: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5b6:
	/* 0x5b6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5bb:
	/* 0x5bb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c0:
	/* 0x5c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2:
	/* 0x5c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c5:
	/* 0x5c5: je     457 <generic_uprobe_actions+0x457> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c5, 0x457, x86_l_457);
x86_l_5cb:
	/* 0x5cb: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d0:
	/* 0x5d0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5d2:
	/* 0x5d2: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d6:
	/* 0x5d6: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_5dd:
	/* 0x5dd: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5ec:
	/* 0x5ec: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5f3:
	/* 0x5f3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5f6:
	/* 0x5f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fb:
	/* 0x5fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fd:
	/* 0x5fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_600:
	/* 0x600: je     c33 <generic_uprobe_actions+0xc33> */
	X86_SIM_X86_JCC(X86_CC_E, 0x600, 0xc33, x86_l_c33);
x86_l_606:
	/* 0x606: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_608:
	/* 0x608: jmp    c55 <generic_uprobe_actions+0xc55> */
	X86_SIM_X86_JMP(0x608, 0xc55, x86_l_c55);
x86_l_60d:
	/* 0x60d: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_614:
	/* 0x614: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_617:
	/* 0x617: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_61c:
	/* 0x61c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61e:
	/* 0x61e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_621:
	/* 0x621: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_624:
	/* 0x624: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_626:
	/* 0x626: jne    694 <generic_uprobe_actions+0x694> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x626, 0x694, x86_l_694);
x86_l_628:
	/* 0x628: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_62e:
	/* 0x62e: jmp    68d <generic_uprobe_actions+0x68d> */
	X86_SIM_X86_JMP(0x62e, 0x68d, x86_l_68d);
x86_l_630:
	/* 0x630: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_638:
	/* 0x638: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_63f:
	/* 0x63f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_641:
	/* 0x641: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_644:
	/* 0x644: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_649:
	/* 0x649: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64e:
	/* 0x64e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_650:
	/* 0x650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652:
	/* 0x652: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_655:
	/* 0x655: je     bef <generic_uprobe_actions+0xbef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x655, 0xbef, x86_l_bef);
x86_l_65b:
	/* 0x65b: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_65f:
	/* 0x65f: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_662:
	/* 0x662: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_668:
	/* 0x668: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66f:
	/* 0x66f: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_676:
	/* 0x676: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_679:
	/* 0x679: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67e:
	/* 0x67e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_680:
	/* 0x680: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_683:
	/* 0x683: je     68a <generic_uprobe_actions+0x68a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x683, 0x68a, x86_l_68a);
x86_l_685:
	/* 0x685: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_68a:
	/* 0x68a: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_68d:
	/* 0x68d: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_691:
	/* 0x691: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_694:
	/* 0x694: lea    eax,[r13*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_69c:
	/* 0x69c: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_6a0:
	/* 0x6a0: jae    12b2 <generic_uprobe_actions+0x12b2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x6a0, 0x12b2, x86_l_12b2);
x86_l_6a6:
	/* 0x6a6: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ab:
	/* 0x6ab: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_6ae:
	/* 0x6ae: movsxd rbp,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_6b3:
	/* 0x6b3: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_6bb:
	/* 0x6bb: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_6c2:
	/* 0x6c2: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6c7:
	/* 0x6c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6cc:
	/* 0x6cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ce:
	/* 0x6ce: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d1:
	/* 0x6d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6d4:
	/* 0x6d4: je     cef <generic_uprobe_actions+0xcef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d4, 0xcef, x86_l_cef);
x86_l_6da:
	/* 0x6da: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6dd:
	/* 0x6dd: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_6e0:
	/* 0x6e0: jg     706 <generic_uprobe_actions+0x706> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e0, 0x706, x86_l_706);
x86_l_6e2:
	/* 0x6e2: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6e5:
	/* 0x6e5: jg     73d <generic_uprobe_actions+0x73d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e5, 0x73d, x86_l_73d);
x86_l_6e7:
	/* 0x6e7: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6ea:
	/* 0x6ea: jg     877 <generic_uprobe_actions+0x877> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6ea, 0x877, x86_l_877);
x86_l_6f0:
	/* 0x6f0: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6f2:
	/* 0x6f2: je     afc <generic_uprobe_actions+0xafc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f2, 0xafc, x86_l_afc);
x86_l_6f8:
	/* 0x6f8: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6fb:
	/* 0x6fb: je     889 <generic_uprobe_actions+0x889> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fb, 0x889, x86_l_889);
x86_l_701:
	/* 0x701: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0x701, 0xce5, x86_l_ce5);
x86_l_706:
	/* 0x706: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_709:
	/* 0x709: jg     84b <generic_uprobe_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x709, 0x84b, x86_l_84b);
x86_l_70f:
	/* 0x70f: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_712:
	/* 0x712: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_715:
	/* 0x715: jb     9bb <generic_uprobe_actions+0x9bb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x715, 0x9bb, x86_l_9bb);
x86_l_71b:
	/* 0x71b: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_71e:
	/* 0x71e: je     9d3 <generic_uprobe_actions+0x9d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71e, 0x9d3, x86_l_9d3);
x86_l_724:
	/* 0x724: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_727:
	/* 0x727: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x727, 0xce5, x86_l_ce5);
x86_l_72d:
	/* 0x72d: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_730:
	/* 0x730: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_733:
	/* 0x733: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_738:
	/* 0x738: jmp    cc0 <generic_uprobe_actions+0xcc0> */
	X86_SIM_X86_JMP(0x738, 0xcc0, x86_l_cc0);
x86_l_73d:
	/* 0x73d: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_740:
	/* 0x740: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_743:
	/* 0x743: jb     9c3 <generic_uprobe_actions+0x9c3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x743, 0x9c3, x86_l_9c3);
x86_l_749:
	/* 0x749: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_74c:
	/* 0x74c: je     9e0 <generic_uprobe_actions+0x9e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74c, 0x9e0, x86_l_9e0);
x86_l_752:
	/* 0x752: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_755:
	/* 0x755: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x755, 0xce5, x86_l_ce5);
x86_l_75b:
	/* 0x75b: mov    eax,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_760:
	/* 0x760: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_764:
	/* 0x764: mov    r15d,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_769:
	/* 0x769: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_772:
	/* 0x772: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77a:
	/* 0x77a: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_77d:
	/* 0x77d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_780:
	/* 0x780: ja     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x780, 0xce5, x86_l_ce5);
x86_l_786:
	/* 0x786: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_78e:
	/* 0x78e: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x78e, 0xce5, x86_l_ce5);
x86_l_794:
	/* 0x794: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_79c:
	/* 0x79c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7a1:
	/* 0x7a1: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_7a8:
	/* 0x7a8: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ac:
	/* 0x7ac: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_7b1:
	/* 0x7b1: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_7b4:
	/* 0x7b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b6:
	/* 0x7b6: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_7ba:
	/* 0x7ba: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7be:
	/* 0x7be: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_7c5:
	/* 0x7c5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_7c8:
	/* 0x7c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7cd:
	/* 0x7cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cf:
	/* 0x7cf: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_7d2:
	/* 0x7d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d5:
	/* 0x7d5: je     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d5, 0xce5, x86_l_ce5);
x86_l_7db:
	/* 0x7db: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7df:
	/* 0x7df: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_7e3:
	/* 0x7e3: ja     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7e3, 0xce5, x86_l_ce5);
x86_l_7e9:
	/* 0x7e9: cmp    DWORD PTR [rdx+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_7f2:
	/* 0x7f2: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7f2, 0xce5, x86_l_ce5);
x86_l_7f8:
	/* 0x7f8: mov    rcx,QWORD PTR [rdx+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_800:
	/* 0x800: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_808:
	/* 0x808: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_80e:
	/* 0x80e: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_815:
	/* 0x815: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_819:
	/* 0x819: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_81c:
	/* 0x81c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_821:
	/* 0x821: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_823:
	/* 0x823: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_827:
	/* 0x827: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82b:
	/* 0x82b: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_832:
	/* 0x832: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_834:
	/* 0x834: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_837:
	/* 0x837: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_83c:
	/* 0x83c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_841:
	/* 0x841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_843:
	/* 0x843: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_846:
	/* 0x846: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0x846, 0xce5, x86_l_ce5);
x86_l_84b:
	/* 0x84b: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_84e:
	/* 0x84e: je     b78 <generic_uprobe_actions+0xb78> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84e, 0xb78, x86_l_b78);
x86_l_854:
	/* 0x854: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_857:
	/* 0x857: je     a82 <generic_uprobe_actions+0xa82> */
	X86_SIM_X86_JCC(X86_CC_E, 0x857, 0xa82, x86_l_a82);
x86_l_85d:
	/* 0x85d: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_860:
	/* 0x860: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x860, 0xce5, x86_l_ce5);
x86_l_866:
	/* 0x866: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_869:
	/* 0x869: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_86d:
	/* 0x86d: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_872:
	/* 0x872: jmp    cc0 <generic_uprobe_actions+0xcc0> */
	X86_SIM_X86_JMP(0x872, 0xcc0, x86_l_cc0);
x86_l_877:
	/* 0x877: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_87a:
	/* 0x87a: je     b6b <generic_uprobe_actions+0xb6b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x87a, 0xb6b, x86_l_b6b);
x86_l_880:
	/* 0x880: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_883:
	/* 0x883: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x883, 0xce5, x86_l_ce5);
x86_l_889:
	/* 0x889: mov    r14d,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_88e:
	/* 0x88e: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_892:
	/* 0x892: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_897:
	/* 0x897: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_89c:
	/* 0x89c: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8a5:
	/* 0x8a5: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ad:
	/* 0x8ad: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_8b5:
	/* 0x8b5: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_8bc:
	/* 0x8bc: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8c1:
	/* 0x8c1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c6:
	/* 0x8c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8cb:
	/* 0x8cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cd:
	/* 0x8cd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8d2:
	/* 0x8d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8d5:
	/* 0x8d5: je     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d5, 0xce5, x86_l_ce5);
x86_l_8db:
	/* 0x8db: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_8df:
	/* 0x8df: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_8e3:
	/* 0x8e3: ja     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8e3, 0xce5, x86_l_ce5);
x86_l_8e9:
	/* 0x8e9: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_8f2:
	/* 0x8f2: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8f2, 0xce5, x86_l_ce5);
x86_l_8f8:
	/* 0x8f8: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8fd:
	/* 0x8fd: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_905:
	/* 0x905: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_90d:
	/* 0x90d: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_912:
	/* 0x912: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_919:
	/* 0x919: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_91d:
	/* 0x91d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_922:
	/* 0x922: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_924:
	/* 0x924: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_928:
	/* 0x928: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92c:
	/* 0x92c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_92f:
	/* 0x92f: jne    c10 <generic_uprobe_actions+0xc10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x92f, 0xc10, x86_l_c10);
x86_l_935:
	/* 0x935: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_93a:
	/* 0x93a: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_93d:
	/* 0x93d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_940:
	/* 0x940: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_945:
	/* 0x945: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_94a:
	/* 0x94a: ja     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x94a, 0xce5, x86_l_ce5);
x86_l_950:
	/* 0x950: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_953:
	/* 0x953: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_95b:
	/* 0x95b: jne    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x95b, 0xce5, x86_l_ce5);
x86_l_961:
	/* 0x961: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_969:
	/* 0x969: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_96f:
	/* 0x96f: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_972:
	/* 0x972: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_979:
	/* 0x979: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_97e:
	/* 0x97e: mov    esi,DWORD PTR [rsi+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_985:
	/* 0x985: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_98b:
	/* 0x98b: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_98f:
	/* 0x98f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_994:
	/* 0x994: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_997:
	/* 0x997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_999:
	/* 0x999: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9a0:
	/* 0x9a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a2:
	/* 0x9a2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9a5:
	/* 0x9a5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9aa:
	/* 0x9aa: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9ad:
	/* 0x9ad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9af:
	/* 0x9af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b1:
	/* 0x9b1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9b6:
	/* 0x9b6: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0x9b6, 0xce5, x86_l_ce5);
x86_l_9bb:
	/* 0x9bb: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9be:
	/* 0x9be: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0x9be, 0xce5, x86_l_ce5);
x86_l_9c3:
	/* 0x9c3: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9c6:
	/* 0x9c6: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_9cb:
	/* 0x9cb: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9ce:
	/* 0x9ce: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0x9ce, 0xce5, x86_l_ce5);
x86_l_9d3:
	/* 0x9d3: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9db:
	/* 0x9db: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0x9db, 0xce5, x86_l_ce5);
x86_l_9e0:
	/* 0x9e0: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_9e3:
	/* 0x9e3: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9e6:
	/* 0x9e6: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_9ec:
	/* 0x9ec: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_9f1:
	/* 0x9f1: je     cc0 <generic_uprobe_actions+0xcc0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f1, 0xcc0, x86_l_cc0);
x86_l_9f7:
	/* 0x9f7: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_9fa:
	/* 0x9fa: mov    eax,DWORD PTR [r12+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_9ff:
	/* 0x9ff: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a03:
	/* 0xa03: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a08:
	/* 0xa08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0a:
	/* 0xa0a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a0f:
	/* 0xa0f: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_a16:
	/* 0xa16: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a1b:
	/* 0xa1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a20:
	/* 0xa20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a22:
	/* 0xa22: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a25:
	/* 0xa25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a28:
	/* 0xa28: je     a37 <generic_uprobe_actions+0xa37> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa28, 0xa37, x86_l_a37);
x86_l_a2a:
	/* 0xa2a: cmp    r14,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_a31:
	/* 0xa31: jb     cb3 <generic_uprobe_actions+0xcb3> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa31, 0xcb3, x86_l_cb3);
x86_l_a37:
	/* 0xa37: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a3a:
	/* 0xa3a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a3c:
	/* 0xa3c: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_a3f:
	/* 0xa3f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a44:
	/* 0xa44: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_a47:
	/* 0xa47: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4b:
	/* 0xa4b: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_a52:
	/* 0xa52: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_a5c:
	/* 0xa5c: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a61:
	/* 0xa61: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a68:
	/* 0xa68: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a6b:
	/* 0xa6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a70:
	/* 0xa70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a72:
	/* 0xa72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a75:
	/* 0xa75: je     c88 <generic_uprobe_actions+0xc88> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa75, 0xc88, x86_l_c88);
x86_l_a7b:
	/* 0xa7b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a7d:
	/* 0xa7d: jmp    caa <generic_uprobe_actions+0xcaa> */
	X86_SIM_X86_JMP(0xa7d, 0xcaa, x86_l_caa);
x86_l_a82:
	/* 0xa82: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_a85:
	/* 0xa85: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a8a:
	/* 0xa8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8c:
	/* 0xa8c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a91:
	/* 0xa91: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_a98:
	/* 0xa98: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a9d:
	/* 0xa9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aa2:
	/* 0xaa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa4:
	/* 0xaa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa7:
	/* 0xaa7: je     af4 <generic_uprobe_actions+0xaf4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa7, 0xaf4, x86_l_af4);
x86_l_aa9:
	/* 0xaa9: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aad:
	/* 0xaad: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ab2:
	/* 0xab2: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_aba:
	/* 0xaba: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_ac1:
	/* 0xac1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ac6:
	/* 0xac6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_acb:
	/* 0xacb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acd:
	/* 0xacd: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_ad5:
	/* 0xad5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: je     b89 <generic_uprobe_actions+0xb89> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad8, 0xb89, x86_l_b89);
x86_l_ade:
	/* 0xade: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ae1:
	/* 0xae1: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_ae8:
	/* 0xae8: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aed:
	/* 0xaed: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_af2:
	/* 0xaf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af4:
	/* 0xaf4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_af7:
	/* 0xaf7: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0xaf7, 0xce5, x86_l_ce5);
x86_l_afc:
	/* 0xafc: cmp    DWORD PTR [r12+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_b02:
	/* 0xb02: je     b2a <generic_uprobe_actions+0xb2a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb02, 0xb2a, x86_l_b2a);
x86_l_b04:
	/* 0xb04: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_b08:
	/* 0xb08: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_b0b:
	/* 0xb0b: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b12:
	/* 0xb12: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b14:
	/* 0xb14: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b19:
	/* 0xb19: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b1c:
	/* 0xb1c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b1e:
	/* 0xb1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b20:
	/* 0xb20: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b23:
	/* 0xb23: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b2a:
	/* 0xb2a: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b2e:
	/* 0xb2e: cmp    DWORD PTR [r12+r13*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 17179869184ULL);
x86_l_b34:
	/* 0xb34: je     ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb34, 0xce5, x86_l_ce5);
x86_l_b3a:
	/* 0xb3a: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_b3e:
	/* 0xb3e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_b41:
	/* 0xb41: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b48:
	/* 0xb48: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_b4d:
	/* 0xb4d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b52:
	/* 0xb52: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_b57:
	/* 0xb57: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b5a:
	/* 0xb5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5c:
	/* 0xb5c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b5f:
	/* 0xb5f: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b66:
	/* 0xb66: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0xb66, 0xce5, x86_l_ce5);
x86_l_b6b:
	/* 0xb6b: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_b6e:
	/* 0xb6e: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b73:
	/* 0xb73: jmp    cc0 <generic_uprobe_actions+0xcc0> */
	X86_SIM_X86_JMP(0xb73, 0xcc0, x86_l_cc0);
x86_l_b78:
	/* 0xb78: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_b7b:
	/* 0xb7b: add    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_b7f:
	/* 0xb7f: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b84:
	/* 0xb84: jmp    cc0 <generic_uprobe_actions+0xcc0> */
	X86_SIM_X86_JMP(0xb84, 0xcc0, x86_l_cc0);
x86_l_b89:
	/* 0xb89: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_b90:
	/* 0xb90: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b95:
	/* 0xb95: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_b9a:
	/* 0xb9a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b9f:
	/* 0xb9f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ba4:
	/* 0xba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba6:
	/* 0xba6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba9:
	/* 0xba9: je     ae1 <generic_uprobe_actions+0xae1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba9, 0xae1, x86_l_ae1);
x86_l_baf:
	/* 0xbaf: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_bb2:
	/* 0xbb2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_bb4:
	/* 0xbb4: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb8:
	/* 0xbb8: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_bbf:
	/* 0xbbf: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_bc9:
	/* 0xbc9: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bce:
	/* 0xbce: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_bd5:
	/* 0xbd5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_bd8:
	/* 0xbd8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bdd:
	/* 0xbdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdf:
	/* 0xbdf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be2:
	/* 0xbe2: je     11f7 <generic_uprobe_actions+0x11f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe2, 0x11f7, x86_l_11f7);
x86_l_be8:
	/* 0xbe8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bea:
	/* 0xbea: jmp    1219 <generic_uprobe_actions+0x1219> */
	X86_SIM_X86_JMP(0xbea, 0x1219, x86_l_1219);
x86_l_bef:
	/* 0xbef: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_bf6:
	/* 0xbf6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf8:
	/* 0xbf8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bfd:
	/* 0xbfd: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c02:
	/* 0xc02: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c07:
	/* 0xc07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c09:
	/* 0xc09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0b:
	/* 0xc0b: jmp    662 <generic_uprobe_actions+0x662> */
	X86_SIM_X86_JMP(0xc0b, 0x662, x86_l_662);
x86_l_c10:
	/* 0xc10: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_c17:
	/* 0xc17: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c1a:
	/* 0xc1a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c1f:
	/* 0xc1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c21:
	/* 0xc21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c23:
	/* 0xc23: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c28:
	/* 0xc28: jne    cef <generic_uprobe_actions+0xcef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc28, 0xcef, x86_l_cef);
x86_l_c2e:
	/* 0xc2e: jmp    ce5 <generic_uprobe_actions+0xce5> */
	X86_SIM_X86_JMP(0xc2e, 0xce5, x86_l_ce5);
x86_l_c33:
	/* 0xc33: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_c3b:
	/* 0xc3b: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c42:
	/* 0xc42: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c44:
	/* 0xc44: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c47:
	/* 0xc47: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c4c:
	/* 0xc4c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c51:
	/* 0xc51: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c53:
	/* 0xc53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c55:
	/* 0xc55: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c5a:
	/* 0xc5a: je     457 <generic_uprobe_actions+0x457> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5a, 0x457, x86_l_457);
x86_l_c60:
	/* 0xc60: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c67:
	/* 0xc67: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c6c:
	/* 0xc6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c71:
	/* 0xc71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c73:
	/* 0xc73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c76:
	/* 0xc76: je     457 <generic_uprobe_actions+0x457> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc76, 0x457, x86_l_457);
x86_l_c7c:
	/* 0xc7c: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c80:
	/* 0xc80: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c83:
	/* 0xc83: jmp    457 <generic_uprobe_actions+0x457> */
	X86_SIM_X86_JMP(0xc83, 0x457, x86_l_457);
x86_l_c88:
	/* 0xc88: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_c90:
	/* 0xc90: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c97:
	/* 0xc97: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c99:
	/* 0xc99: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c9c:
	/* 0xc9c: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ca1:
	/* 0xca1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ca6:
	/* 0xca6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca8:
	/* 0xca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_caa:
	/* 0xcaa: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_cad:
	/* 0xcad: je     11b3 <generic_uprobe_actions+0x11b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcad, 0x11b3, x86_l_11b3);
x86_l_cb3:
	/* 0xcb3: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_cb7:
	/* 0xcb7: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cba:
	/* 0xcba: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_cc0:
	/* 0xcc0: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc7:
	/* 0xcc7: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_cce:
	/* 0xcce: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_cd1:
	/* 0xcd1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd6:
	/* 0xcd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd8:
	/* 0xcd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cdb:
	/* 0xcdb: je     ce2 <generic_uprobe_actions+0xce2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcdb, 0xce2, x86_l_ce2);
x86_l_cdd:
	/* 0xcdd: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ce2:
	/* 0xce2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ce5:
	/* 0xce5: mov    QWORD PTR [rdx+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ce9:
	/* 0xce9: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cec:
	/* 0xcec: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_cef:
	/* 0xcef: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_cf7:
	/* 0xcf7: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_cfb:
	/* 0xcfb: jae    d55 <generic_uprobe_actions+0xd55> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xcfb, 0xd55, x86_l_d55);
x86_l_cfd:
	/* 0xcfd: mov    r15d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R15, X86_WIDTH_32);
x86_l_d00:
	/* 0xd00: movsxd rbp,DWORD PTR [r12+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_d05:
	/* 0xd05: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_d0d:
	/* 0xd0d: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_d14:
	/* 0xd14: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d19:
	/* 0xd19: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d1e:
	/* 0xd1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d20:
	/* 0xd20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d23:
	/* 0xd23: je     d55 <generic_uprobe_actions+0xd55> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd23, 0xd55, x86_l_d55);
x86_l_d25:
	/* 0xd25: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d28:
	/* 0xd28: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d2b:
	/* 0xd2b: jle    d5f <generic_uprobe_actions+0xd5f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xd2b, 0xd5f, x86_l_d5f);
x86_l_d2d:
	/* 0xd2d: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_d30:
	/* 0xd30: jg     d83 <generic_uprobe_actions+0xd83> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd30, 0xd83, x86_l_d83);
x86_l_d32:
	/* 0xd32: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_d35:
	/* 0xd35: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d38:
	/* 0xd38: jb     eb8 <generic_uprobe_actions+0xeb8> */
	X86_SIM_X86_JCC(X86_CC_B, 0xd38, 0xeb8, x86_l_eb8);
x86_l_d3e:
	/* 0xd3e: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d41:
	/* 0xd41: je     fcf <generic_uprobe_actions+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd41, 0xfcf, x86_l_fcf);
x86_l_d47:
	/* 0xd47: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_d4a:
	/* 0xd4a: je     1282 <generic_uprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4a, 0x1282, x86_l_1282);
x86_l_d50:
	/* 0xd50: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0xd50, 0x12a9, x86_l_12a9);
x86_l_d55:
	/* 0xd55: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d5a:
	/* 0xd5a: jmp    12b2 <generic_uprobe_actions+0x12b2> */
	X86_SIM_X86_JMP(0xd5a, 0x12b2, x86_l_12b2);
x86_l_d5f:
	/* 0xd5f: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d62:
	/* 0xd62: jg     db7 <generic_uprobe_actions+0xdb7> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd62, 0xdb7, x86_l_db7);
x86_l_d64:
	/* 0xd64: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_d66:
	/* 0xd66: je     104f <generic_uprobe_actions+0x104f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd66, 0x104f, x86_l_104f);
x86_l_d6c:
	/* 0xd6c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_d6f:
	/* 0xd6f: je     ec6 <generic_uprobe_actions+0xec6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6f, 0xec6, x86_l_ec6);
x86_l_d75:
	/* 0xd75: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d78:
	/* 0xd78: je     1282 <generic_uprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd78, 0x1282, x86_l_1282);
x86_l_d7e:
	/* 0xd7e: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0xd7e, 0x12a9, x86_l_12a9);
x86_l_d83:
	/* 0xd83: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d88:
	/* 0xd88: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d8d:
	/* 0xd8d: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_d90:
	/* 0xd90: je     1282 <generic_uprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd90, 0x1282, x86_l_1282);
x86_l_d96:
	/* 0xd96: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_d99:
	/* 0xd99: je     fd7 <generic_uprobe_actions+0xfd7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd99, 0xfd7, x86_l_fd7);
x86_l_d9f:
	/* 0xd9f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_da4:
	/* 0xda4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_da9:
	/* 0xda9: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_dac:
	/* 0xdac: je     1282 <generic_uprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdac, 0x1282, x86_l_1282);
x86_l_db2:
	/* 0xdb2: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0xdb2, 0x12a9, x86_l_12a9);
x86_l_db7:
	/* 0xdb7: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_dba:
	/* 0xdba: je     ec6 <generic_uprobe_actions+0xec6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdba, 0xec6, x86_l_ec6);
x86_l_dc0:
	/* 0xdc0: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_dc3:
	/* 0xdc3: je     10b0 <generic_uprobe_actions+0x10b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdc3, 0x10b0, x86_l_10b0);
x86_l_dc9:
	/* 0xdc9: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_dcc:
	/* 0xdcc: jne    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdcc, 0x12a9, x86_l_12a9);
x86_l_dd2:
	/* 0xdd2: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_dd7:
	/* 0xdd7: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_ddc:
	/* 0xddc: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_de5:
	/* 0xde5: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ded:
	/* 0xded: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_df0:
	/* 0xdf0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df3:
	/* 0xdf3: ja     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xdf3, 0x12a9, x86_l_12a9);
x86_l_df9:
	/* 0xdf9: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_e02:
	/* 0xe02: jne    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe02, 0x12a9, x86_l_12a9);
x86_l_e08:
	/* 0xe08: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_e10:
	/* 0xe10: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e15:
	/* 0xe15: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_e1d:
	/* 0xe1d: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e21:
	/* 0xe21: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e26:
	/* 0xe26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e28:
	/* 0xe28: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e2c:
	/* 0xe2c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e30:
	/* 0xe30: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e37:
	/* 0xe37: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e3a:
	/* 0xe3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3f:
	/* 0xe3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e41:
	/* 0xe41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e44:
	/* 0xe44: je     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe44, 0x12a9, x86_l_12a9);
x86_l_e4a:
	/* 0xe4a: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e4e:
	/* 0xe4e: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_e52:
	/* 0xe52: ja     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe52, 0x12a9, x86_l_12a9);
x86_l_e58:
	/* 0xe58: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_e61:
	/* 0xe61: jne    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe61, 0x12a9, x86_l_12a9);
x86_l_e67:
	/* 0xe67: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_e6f:
	/* 0xe6f: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_e77:
	/* 0xe77: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e7d:
	/* 0xe7d: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e85:
	/* 0xe85: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e89:
	/* 0xe89: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e8c:
	/* 0xe8c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e91:
	/* 0xe91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e93:
	/* 0xe93: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e97:
	/* 0xe97: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9b:
	/* 0xe9b: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_ea2:
	/* 0xea2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea4:
	/* 0xea4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ea7:
	/* 0xea7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_eac:
	/* 0xeac: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb1:
	/* 0xeb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb3:
	/* 0xeb3: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0xeb3, 0x12a9, x86_l_12a9);
x86_l_eb8:
	/* 0xeb8: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_ebd:
	/* 0xebd: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ec1:
	/* 0xec1: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0xec1, 0x12a9, x86_l_12a9);
x86_l_ec6:
	/* 0xec6: mov    r13d,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_ecb:
	/* 0xecb: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_ed0:
	/* 0xed0: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ed9:
	/* 0xed9: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee1:
	/* 0xee1: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ee9:
	/* 0xee9: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_ef0:
	/* 0xef0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ef5:
	/* 0xef5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_efa:
	/* 0xefa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efc:
	/* 0xefc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eff:
	/* 0xeff: je     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeff, 0x12a9, x86_l_12a9);
x86_l_f05:
	/* 0xf05: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f09:
	/* 0xf09: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_f0d:
	/* 0xf0d: ja     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf0d, 0x12a9, x86_l_12a9);
x86_l_f13:
	/* 0xf13: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_f1c:
	/* 0xf1c: jne    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf1c, 0x12a9, x86_l_12a9);
x86_l_f22:
	/* 0xf22: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_f2d:
	/* 0xf2d: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_f35:
	/* 0xf35: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f3a:
	/* 0xf3a: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_f42:
	/* 0xf42: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f46:
	/* 0xf46: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_f51:
	/* 0xf51: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f55:
	/* 0xf55: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_f58:
	/* 0xf58: jne    11d4 <generic_uprobe_actions+0x11d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf58, 0x11d4, x86_l_11d4);
x86_l_f5e:
	/* 0xf5e: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f62:
	/* 0xf62: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_f66:
	/* 0xf66: ja     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf66, 0x12a9, x86_l_12a9);
x86_l_f6c:
	/* 0xf6c: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_f75:
	/* 0xf75: jne    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf75, 0x12a9, x86_l_12a9);
x86_l_f7b:
	/* 0xf7b: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_f83:
	/* 0xf83: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f88:
	/* 0xf88: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f8c:
	/* 0xf8c: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f93:
	/* 0xf93: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_f9b:
	/* 0xf9b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fa1:
	/* 0xfa1: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_fa5:
	/* 0xfa5: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_fa8:
	/* 0xfa8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fad:
	/* 0xfad: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb2:
	/* 0xfb2: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_fb9:
	/* 0xfb9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbb:
	/* 0xfbb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fbe:
	/* 0xfbe: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fc3:
	/* 0xfc3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_fc6:
	/* 0xfc6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc8:
	/* 0xfc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fca:
	/* 0xfca: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0xfca, 0x12a9, x86_l_12a9);
x86_l_fcf:
	/* 0xfcf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd2:
	/* 0xfd2: jmp    12ae <generic_uprobe_actions+0x12ae> */
	X86_SIM_X86_JMP(0xfd2, 0x12ae, x86_l_12ae);
x86_l_fd7:
	/* 0xfd7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fdc:
	/* 0xfdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fde:
	/* 0xfde: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fe3:
	/* 0xfe3: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_fea:
	/* 0xfea: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fef:
	/* 0xfef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff4:
	/* 0xff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff6:
	/* 0xff6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ff9:
	/* 0xff9: je     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff9, 0x12a9, x86_l_12a9);
x86_l_fff:
	/* 0xfff: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1003:
	/* 0x1003: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1008:
	/* 0x1008: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_1010:
	/* 0x1010: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1017:
	/* 0x1017: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_101c:
	/* 0x101c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1021:
	/* 0x1021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1023:
	/* 0x1023: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_102b:
	/* 0x102b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_102e:
	/* 0x102e: je     114d <generic_uprobe_actions+0x114d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x102e, 0x114d, x86_l_114d);
x86_l_1034:
	/* 0x1034: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1037:
	/* 0x1037: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_103e:
	/* 0x103e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1043:
	/* 0x1043: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1048:
	/* 0x1048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104a:
	/* 0x104a: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0x104a, 0x12a9, x86_l_12a9);
x86_l_104f:
	/* 0x104f: cmp    DWORD PTR [r12+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_1055:
	/* 0x1055: je     1078 <generic_uprobe_actions+0x1078> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1055, 0x1078, x86_l_1078);
x86_l_1057:
	/* 0x1057: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_105c:
	/* 0x105c: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1063:
	/* 0x1063: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1065:
	/* 0x1065: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_106a:
	/* 0x106a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_106d:
	/* 0x106d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_106f:
	/* 0x106f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1071:
	/* 0x1071: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1078:
	/* 0x1078: cmp    DWORD PTR [r12+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_107e:
	/* 0x107e: je     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107e, 0x12a9, x86_l_12a9);
x86_l_1084:
	/* 0x1084: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_1089:
	/* 0x1089: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1090:
	/* 0x1090: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1095:
	/* 0x1095: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_109a:
	/* 0x109a: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_109f:
	/* 0x109f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10a2:
	/* 0x10a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a4:
	/* 0x10a4: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_10ab:
	/* 0x10ab: jmp    12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JMP(0x10ab, 0x12a9, x86_l_12a9);
x86_l_10b0:
	/* 0x10b0: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_10b5:
	/* 0x10b5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10ba:
	/* 0x10ba: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_10bf:
	/* 0x10bf: je     1282 <generic_uprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10bf, 0x1282, x86_l_1282);
x86_l_10c5:
	/* 0x10c5: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_10ca:
	/* 0x10ca: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10ce:
	/* 0x10ce: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10d3:
	/* 0x10d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d5:
	/* 0x10d5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10da:
	/* 0x10da: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_10e1:
	/* 0x10e1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10e6:
	/* 0x10e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10eb:
	/* 0x10eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ed:
	/* 0x10ed: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_10f0:
	/* 0x10f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f3:
	/* 0x10f3: je     1102 <generic_uprobe_actions+0x1102> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f3, 0x1102, x86_l_1102);
x86_l_10f5:
	/* 0x10f5: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_10fc:
	/* 0x10fc: jb     1271 <generic_uprobe_actions+0x1271> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10fc, 0x1271, x86_l_1271);
x86_l_1102:
	/* 0x1102: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_1105:
	/* 0x1105: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1107:
	/* 0x1107: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_110a:
	/* 0x110a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_110f:
	/* 0x110f: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1112:
	/* 0x1112: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1116:
	/* 0x1116: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_111d:
	/* 0x111d: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_1127:
	/* 0x1127: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_112c:
	/* 0x112c: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1133:
	/* 0x1133: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1136:
	/* 0x1136: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_113b:
	/* 0x113b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_113d:
	/* 0x113d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1140:
	/* 0x1140: je     124a <generic_uprobe_actions+0x124a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1140, 0x124a, x86_l_124a);
x86_l_1146:
	/* 0x1146: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1148:
	/* 0x1148: jmp    126c <generic_uprobe_actions+0x126c> */
	X86_SIM_X86_JMP(0x1148, 0x126c, x86_l_126c);
x86_l_114d:
	/* 0x114d: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1154:
	/* 0x1154: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1159:
	/* 0x1159: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_115e:
	/* 0x115e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1163:
	/* 0x1163: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1168:
	/* 0x1168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116a:
	/* 0x116a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_116d:
	/* 0x116d: je     1037 <generic_uprobe_actions+0x1037> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116d, 0x1037, x86_l_1037);
x86_l_1173:
	/* 0x1173: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1176:
	/* 0x1176: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1178:
	/* 0x1178: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117c:
	/* 0x117c: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_1183:
	/* 0x1183: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_118d:
	/* 0x118d: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1192:
	/* 0x1192: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1199:
	/* 0x1199: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_119c:
	/* 0x119c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a1:
	/* 0x11a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a3:
	/* 0x11a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a6:
	/* 0x11a6: je     1301 <generic_uprobe_actions+0x1301> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a6, 0x1301, x86_l_1301);
x86_l_11ac:
	/* 0x11ac: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_11ae:
	/* 0x11ae: jmp    1323 <generic_uprobe_actions+0x1323> */
	X86_SIM_X86_JMP(0x11ae, 0x1323, x86_l_1323);
x86_l_11b3:
	/* 0x11b3: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_11ba:
	/* 0x11ba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11bc:
	/* 0x11bc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c1:
	/* 0x11c1: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11c6:
	/* 0x11c6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11cb:
	/* 0x11cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11cd:
	/* 0x11cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11cf:
	/* 0x11cf: jmp    cba <generic_uprobe_actions+0xcba> */
	X86_SIM_X86_JMP(0x11cf, 0xcba, x86_l_cba);
x86_l_11d4:
	/* 0x11d4: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_11db:
	/* 0x11db: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11de:
	/* 0x11de: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_11e3:
	/* 0x11e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e5:
	/* 0x11e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11e7:
	/* 0x11e7: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ec:
	/* 0x11ec: jne    12b2 <generic_uprobe_actions+0x12b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11ec, 0x12b2, x86_l_12b2);
x86_l_11f2:
	/* 0x11f2: jmp    12ae <generic_uprobe_actions+0x12ae> */
	X86_SIM_X86_JMP(0x11f2, 0x12ae, x86_l_12ae);
x86_l_11f7:
	/* 0x11f7: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_11ff:
	/* 0x11ff: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1206:
	/* 0x1206: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1208:
	/* 0x1208: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_120b:
	/* 0x120b: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1210:
	/* 0x1210: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1215:
	/* 0x1215: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1217:
	/* 0x1217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1219:
	/* 0x1219: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_121c:
	/* 0x121c: je     ae1 <generic_uprobe_actions+0xae1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121c, 0xae1, x86_l_ae1);
x86_l_1222:
	/* 0x1222: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1229:
	/* 0x1229: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_122e:
	/* 0x122e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1233:
	/* 0x1233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1235:
	/* 0x1235: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1238:
	/* 0x1238: je     ae1 <generic_uprobe_actions+0xae1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1238, 0xae1, x86_l_ae1);
x86_l_123e:
	/* 0x123e: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1242:
	/* 0x1242: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1245:
	/* 0x1245: jmp    ae1 <generic_uprobe_actions+0xae1> */
	X86_SIM_X86_JMP(0x1245, 0xae1, x86_l_ae1);
x86_l_124a:
	/* 0x124a: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1252:
	/* 0x1252: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1259:
	/* 0x1259: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125b:
	/* 0x125b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_125e:
	/* 0x125e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1263:
	/* 0x1263: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1268:
	/* 0x1268: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_126a:
	/* 0x126a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126c:
	/* 0x126c: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_126f:
	/* 0x126f: je     12e0 <generic_uprobe_actions+0x12e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x126f, 0x12e0, x86_l_12e0);
x86_l_1271:
	/* 0x1271: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1275:
	/* 0x1275: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1278:
	/* 0x1278: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_127d:
	/* 0x127d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1282:
	/* 0x1282: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1289:
	/* 0x1289: mov    rdi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_1290:
	/* 0x1290: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1298:
	/* 0x1298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129a:
	/* 0x129a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129d:
	/* 0x129d: je     12a9 <generic_uprobe_actions+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129d, 0x12a9, x86_l_12a9);
x86_l_129f:
	/* 0x129f: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12a4:
	/* 0x12a4: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_12a9:
	/* 0x12a9: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12ae:
	/* 0x12ae: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12b2:
	/* 0x12b2: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_12b5:
	/* 0x12b5: je     12d2 <generic_uprobe_actions+0x12d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12b5, 0x12d2, x86_l_12d2);
x86_l_12b7:
	/* 0x12b7: mov    rsi,QWORD PTR [rip+0x5977] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_12be:
	/* 0x12be: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_12c3:
	/* 0x12c3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_12c8:
	/* 0x12c8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12cb:
	/* 0x12cb: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12d0:
	/* 0x12d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d2:
	/* 0x12d2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d4:
	/* 0x12d4: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_12d8:
	/* 0x12d8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_12da:
	/* 0x12da: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_12db:
	/* 0x12db: jmp    1354 <generic_uprobe_actions+0x1354> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_12e0:
	/* 0x12e0: mov    rdi,QWORD PTR [rip+0x597a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_12e7:
	/* 0x12e7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e9:
	/* 0x12e9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12ee:
	/* 0x12ee: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12f3:
	/* 0x12f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12f8:
	/* 0x12f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12fa:
	/* 0x12fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fc:
	/* 0x12fc: jmp    1278 <generic_uprobe_actions+0x1278> */
	X86_SIM_X86_JMP(0x12fc, 0x1278, x86_l_1278);
x86_l_1301:
	/* 0x1301: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_1309:
	/* 0x1309: mov    rdi,QWORD PTR [rip+0x597a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1310:
	/* 0x1310: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1312:
	/* 0x1312: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1315:
	/* 0x1315: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_131a:
	/* 0x131a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_131f:
	/* 0x131f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1321:
	/* 0x1321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1323:
	/* 0x1323: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1326:
	/* 0x1326: je     1037 <generic_uprobe_actions+0x1037> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1326, 0x1037, x86_l_1037);
x86_l_132c:
	/* 0x132c: mov    rdi,QWORD PTR [rip+0x597a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1333:
	/* 0x1333: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1338:
	/* 0x1338: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_133d:
	/* 0x133d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133f:
	/* 0x133f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1342:
	/* 0x1342: je     1037 <generic_uprobe_actions+0x1037> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1342, 0x1037, x86_l_1037);
x86_l_1348:
	/* 0x1348: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_134c:
	/* 0x134c: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_134f:
	/* 0x134f: jmp    1037 <generic_uprobe_actions+0x1037> */
	X86_SIM_X86_JMP(0x134f, 0x1037, x86_l_1037);
x86_l_1354:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
