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
int tetragon_bpf_generic_rawtp_generic_rawtp_actions_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xd: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_15:
	/* 0x15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     462 <generic_rawtp_actions+0x462> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b, 0x462, x86_l_462);
x86_l_31:
	/* 0x31: mov    r12d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_38:
	/* 0x38: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3c:
	/* 0x3c: jl     462 <generic_rawtp_actions+0x462> */
	X86_SIM_X86_JCC(X86_CC_L, 0x3c, 0x462, x86_l_462);
x86_l_42:
	/* 0x42: add    rax,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_48:
	/* 0x48: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d:
	/* 0x4d: mov    rdi,QWORD PTR [rip+0x6227] */
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
	/* 0x5c: je     462 <generic_rawtp_actions+0x462> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x462, x86_l_462);
x86_l_62:
	/* 0x62: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_65:
	/* 0x65: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6b:
	/* 0x6b: add    r12d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6f:
	/* 0x6f: and    r12d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_76:
	/* 0x76: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_79:
	/* 0x79: mov    DWORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_81:
	/* 0x81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86:
	/* 0x86: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8d:
	/* 0x8d: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: je     be <generic_rawtp_actions+0xbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97, 0xbe, x86_l_be);
x86_l_99:
	/* 0x99: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c:
	/* 0x9c: je     be <generic_rawtp_actions+0xbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c, 0xbe, x86_l_be);
x86_l_9e:
	/* 0x9e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a3:
	/* 0xa3: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_a8:
	/* 0xa8: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_ad:
	/* 0xad: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_b2:
	/* 0xb2: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b7:
	/* 0xb7: ja     dd <generic_rawtp_actions+0xdd> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb7, 0xdd, x86_l_dd);
x86_l_b9:
	/* 0xb9: jmp    44c <generic_rawtp_actions+0x44c> */
	X86_SIM_X86_JMP(0xb9, 0x44c, x86_l_44c);
x86_l_be:
	/* 0xbe: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c3:
	/* 0xc3: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_c8:
	/* 0xc8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cd:
	/* 0xcd: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d2:
	/* 0xd2: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d7:
	/* 0xd7: jbe    44c <generic_rawtp_actions+0x44c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd7, 0x44c, x86_l_44c);
x86_l_dd:
	/* 0xdd: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e7:
	/* 0xe7: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ec:
	/* 0xec: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f1:
	/* 0xf1: movsxd r15,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_f6:
	/* 0xf6: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_fe:
	/* 0xfe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_103:
	/* 0x103: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_10a:
	/* 0x10a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10f:
	/* 0x10f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111:
	/* 0x111: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_114:
	/* 0x114: je     14d <generic_rawtp_actions+0x14d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x114, 0x14d, x86_l_14d);
x86_l_116:
	/* 0x116: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_119:
	/* 0x119: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11c:
	/* 0x11c: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_11f:
	/* 0x11f: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_123:
	/* 0x123: jg     158 <generic_rawtp_actions+0x158> */
	X86_SIM_X86_JCC(X86_CC_G, 0x123, 0x158, x86_l_158);
x86_l_125:
	/* 0x125: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_129:
	/* 0x129: jg     193 <generic_rawtp_actions+0x193> */
	X86_SIM_X86_JCC(X86_CC_G, 0x129, 0x193, x86_l_193);
x86_l_12b:
	/* 0x12b: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_12f:
	/* 0x12f: jg     220 <generic_rawtp_actions+0x220> */
	X86_SIM_X86_JCC(X86_CC_G, 0x12f, 0x220, x86_l_220);
x86_l_135:
	/* 0x135: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_138:
	/* 0x138: je     338 <generic_rawtp_actions+0x338> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138, 0x338, x86_l_338);
x86_l_13e:
	/* 0x13e: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_142:
	/* 0x142: je     234 <generic_rawtp_actions+0x234> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142, 0x234, x86_l_234);
x86_l_148:
	/* 0x148: jmp    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JMP(0x148, 0x3cb, x86_l_3cb);
x86_l_14d:
	/* 0x14d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150:
	/* 0x150: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_153:
	/* 0x153: jmp    3d2 <generic_rawtp_actions+0x3d2> */
	X86_SIM_X86_JMP(0x153, 0x3d2, x86_l_3d2);
x86_l_158:
	/* 0x158: cmp    r15d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 11ULL);
x86_l_15c:
	/* 0x15c: jg     1f2 <generic_rawtp_actions+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x15c, 0x1f2, x86_l_1f2);
x86_l_162:
	/* 0x162: lea    eax,[r15-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_166:
	/* 0x166: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_169:
	/* 0x169: jb     29b <generic_rawtp_actions+0x29b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x169, 0x29b, x86_l_29b);
x86_l_16f:
	/* 0x16f: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_173:
	/* 0x173: je     2a6 <generic_rawtp_actions+0x2a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x173, 0x2a6, x86_l_2a6);
x86_l_179:
	/* 0x179: cmp    r15d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 9ULL);
x86_l_17d:
	/* 0x17d: jne    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17d, 0x3cb, x86_l_3cb);
x86_l_183:
	/* 0x183: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_189:
	/* 0x189: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18e:
	/* 0x18e: jmp    3a3 <generic_rawtp_actions+0x3a3> */
	X86_SIM_X86_JMP(0x18e, 0x3a3, x86_l_3a3);
x86_l_193:
	/* 0x193: lea    eax,[r15-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_197:
	/* 0x197: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19a:
	/* 0x19a: jb     292 <generic_rawtp_actions+0x292> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19a, 0x292, x86_l_292);
x86_l_1a0:
	/* 0x1a0: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1a4:
	/* 0x1a4: je     2b0 <generic_rawtp_actions+0x2b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a4, 0x2b0, x86_l_2b0);
x86_l_1aa:
	/* 0x1aa: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_1ae:
	/* 0x1ae: jne    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ae, 0x3cb, x86_l_3cb);
x86_l_1b4:
	/* 0x1b4: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b9:
	/* 0x1b9: mov    r13d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c7:
	/* 0x1c7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d0:
	/* 0x1d0: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1d3:
	/* 0x1d3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d6:
	/* 0x1d6: ja     1e7 <generic_rawtp_actions+0x1e7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d6, 0x1e7, x86_l_1e7);
x86_l_1d8:
	/* 0x1d8: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1e1:
	/* 0x1e1: je     d8e <generic_rawtp_actions+0xd8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1, 0xd8e, x86_l_d8e);
x86_l_1e7:
	/* 0x1e7: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1ed:
	/* 0x1ed: jmp    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JMP(0x1ed, 0x3cb, x86_l_3cb);
x86_l_1f2:
	/* 0x1f2: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_1f6:
	/* 0x1f6: je     398 <generic_rawtp_actions+0x398> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f6, 0x398, x86_l_398);
x86_l_1fc:
	/* 0x1fc: cmp    r15d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 13ULL);
x86_l_200:
	/* 0x200: je     2c0 <generic_rawtp_actions+0x2c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x200, 0x2c0, x86_l_2c0);
x86_l_206:
	/* 0x206: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_20a:
	/* 0x20a: jne    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20a, 0x3cb, x86_l_3cb);
x86_l_210:
	/* 0x210: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_216:
	/* 0x216: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21b:
	/* 0x21b: jmp    3a3 <generic_rawtp_actions+0x3a3> */
	X86_SIM_X86_JMP(0x21b, 0x3a3, x86_l_3a3);
x86_l_220:
	/* 0x220: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_224:
	/* 0x224: je     391 <generic_rawtp_actions+0x391> */
	X86_SIM_X86_JCC(X86_CC_E, 0x224, 0x391, x86_l_391);
x86_l_22a:
	/* 0x22a: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_22e:
	/* 0x22e: jne    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22e, 0x3cb, x86_l_3cb);
x86_l_234:
	/* 0x234: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239:
	/* 0x239: mov    r13d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23e:
	/* 0x23e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_247:
	/* 0x247: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_250:
	/* 0x250: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_258:
	/* 0x258: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25d:
	/* 0x25d: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_264:
	/* 0x264: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_269:
	/* 0x269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b:
	/* 0x26b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e:
	/* 0x26e: je     287 <generic_rawtp_actions+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26e, 0x287, x86_l_287);
x86_l_270:
	/* 0x270: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_273:
	/* 0x273: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_276:
	/* 0x276: ja     287 <generic_rawtp_actions+0x287> */
	X86_SIM_X86_JCC(X86_CC_A, 0x276, 0x287, x86_l_287);
x86_l_278:
	/* 0x278: cmp    DWORD PTR [r14+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_281:
	/* 0x281: je     c72 <generic_rawtp_actions+0xc72> */
	X86_SIM_X86_JCC(X86_CC_E, 0x281, 0xc72, x86_l_c72);
x86_l_287:
	/* 0x287: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_28d:
	/* 0x28d: jmp    3c8 <generic_rawtp_actions+0x3c8> */
	X86_SIM_X86_JMP(0x28d, 0x3c8, x86_l_3c8);
x86_l_292:
	/* 0x292: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_297:
	/* 0x297: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_29b:
	/* 0x29b: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2a1:
	/* 0x2a1: jmp    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JMP(0x2a1, 0x3cb, x86_l_3cb);
x86_l_2a6:
	/* 0x2a6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a8:
	/* 0x2a8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ab:
	/* 0x2ab: jmp    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JMP(0x2ab, 0x3cb, x86_l_3cb);
x86_l_2b0:
	/* 0x2b0: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2b6:
	/* 0x2b6: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bb:
	/* 0x2bb: jmp    3a3 <generic_rawtp_actions+0x3a3> */
	X86_SIM_X86_JMP(0x2bb, 0x3a3, x86_l_3a3);
x86_l_2c0:
	/* 0x2c0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c5:
	/* 0x2c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7:
	/* 0x2c7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cc:
	/* 0x2cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d1:
	/* 0x2d1: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_2d8:
	/* 0x2d8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dd:
	/* 0x2dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df:
	/* 0x2df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e2:
	/* 0x2e2: je     3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e2, 0x3cb, x86_l_3cb);
x86_l_2e8:
	/* 0x2e8: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ec:
	/* 0x2ec: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f1:
	/* 0x2f1: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_2f9:
	/* 0x2f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fe:
	/* 0x2fe: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_305:
	/* 0x305: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30a:
	/* 0x30a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c:
	/* 0x30c: mov    DWORD PTR [rsp+0x1c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084289ULL);
x86_l_314:
	/* 0x314: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_317:
	/* 0x317: je     d23 <generic_rawtp_actions+0xd23> */
	X86_SIM_X86_JCC(X86_CC_E, 0x317, 0xd23, x86_l_d23);
x86_l_31d:
	/* 0x31d: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_320:
	/* 0x320: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_325:
	/* 0x325: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_32c:
	/* 0x32c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_331:
	/* 0x331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_333:
	/* 0x333: jmp    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JMP(0x333, 0x3cb, x86_l_3cb);
x86_l_338:
	/* 0x338: cmp    DWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_33e:
	/* 0x33e: je     35f <generic_rawtp_actions+0x35f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33e, 0x35f, x86_l_35f);
x86_l_340:
	/* 0x340: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_345:
	/* 0x345: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_34a:
	/* 0x34a: mov    rsi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_351:
	/* 0x351: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_354:
	/* 0x354: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_356:
	/* 0x356: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358:
	/* 0x358: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_35f:
	/* 0x35f: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_365:
	/* 0x365: cmp    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_36b:
	/* 0x36b: je     3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36b, 0x3cb, x86_l_3cb);
x86_l_36d:
	/* 0x36d: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_372:
	/* 0x372: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_377:
	/* 0x377: mov    rsi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_37e:
	/* 0x37e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_383:
	/* 0x383: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_386:
	/* 0x386: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_388:
	/* 0x388: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_38f:
	/* 0x38f: jmp    3cb <generic_rawtp_actions+0x3cb> */
	X86_SIM_X86_JMP(0x38f, 0x3cb, x86_l_3cb);
x86_l_391:
	/* 0x391: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_396:
	/* 0x396: jmp    3a3 <generic_rawtp_actions+0x3a3> */
	X86_SIM_X86_JMP(0x396, 0x3a3, x86_l_3a3);
x86_l_398:
	/* 0x398: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_39e:
	/* 0x39e: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a3:
	/* 0x3a3: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3ab:
	/* 0x3ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b0:
	/* 0x3b0: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_3b7:
	/* 0x3b7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bc:
	/* 0x3bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be:
	/* 0x3be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c1:
	/* 0x3c1: je     3c8 <generic_rawtp_actions+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c1, 0x3c8, x86_l_3c8);
x86_l_3c3:
	/* 0x3c3: inc QWORD PTR [rax+rbp*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBP, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3c8:
	/* 0x3c8: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_3cb:
	/* 0x3cb: mov    QWORD PTR [r14+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3cf:
	/* 0x3cf: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3d2:
	/* 0x3d2: lea    eax,[r13*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_3da:
	/* 0x3da: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_3de:
	/* 0x3de: jae    447 <generic_rawtp_actions+0x447> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3de, 0x447, x86_l_447);
x86_l_3e0:
	/* 0x3e0: mov    DWORD PTR [rsp+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e4:
	/* 0x3e4: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_3e7:
	/* 0x3e7: movsxd r15,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_3ec:
	/* 0x3ec: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3f4:
	/* 0x3f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f9:
	/* 0x3f9: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_400:
	/* 0x400: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_405:
	/* 0x405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_407:
	/* 0x407: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_409:
	/* 0x409: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40c:
	/* 0x40c: je     899 <generic_rawtp_actions+0x899> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40c, 0x899, x86_l_899);
x86_l_412:
	/* 0x412: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_415:
	/* 0x415: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_419:
	/* 0x419: jg     473 <generic_rawtp_actions+0x473> */
	X86_SIM_X86_JCC(X86_CC_G, 0x419, 0x473, x86_l_473);
x86_l_41b:
	/* 0x41b: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_41f:
	/* 0x41f: jg     4ae <generic_rawtp_actions+0x4ae> */
	X86_SIM_X86_JCC(X86_CC_G, 0x41f, 0x4ae, x86_l_4ae);
x86_l_425:
	/* 0x425: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_429:
	/* 0x429: jg     5f3 <generic_rawtp_actions+0x5f3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x429, 0x5f3, x86_l_5f3);
x86_l_42f:
	/* 0x42f: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_432:
	/* 0x432: je     7ee <generic_rawtp_actions+0x7ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x432, 0x7ee, x86_l_7ee);
x86_l_438:
	/* 0x438: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_43c:
	/* 0x43c: je     607 <generic_rawtp_actions+0x607> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43c, 0x607, x86_l_607);
x86_l_442:
	/* 0x442: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x442, 0x88f, x86_l_88f);
x86_l_447:
	/* 0x447: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_44a:
	/* 0x44a: je     462 <generic_rawtp_actions+0x462> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44a, 0x462, x86_l_462);
x86_l_44c:
	/* 0x44c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_451:
	/* 0x451: mov    rsi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_458:
	/* 0x458: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_45b:
	/* 0x45b: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_460:
	/* 0x460: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_462:
	/* 0x462: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_464:
	/* 0x464: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_46b:
	/* 0x46b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_46d:
	/* 0x46d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_46e:
	/* 0x46e: jmp    1079 <generic_rawtp_actions+0x1079> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_473:
	/* 0x473: cmp    r15d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 11ULL);
x86_l_477:
	/* 0x477: jg     5c4 <generic_rawtp_actions+0x5c4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x477, 0x5c4, x86_l_5c4);
x86_l_47d:
	/* 0x47d: lea    eax,[r15-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_481:
	/* 0x481: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_484:
	/* 0x484: jb     73e <generic_rawtp_actions+0x73e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x484, 0x73e, x86_l_73e);
x86_l_48a:
	/* 0x48a: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_48e:
	/* 0x48e: je     757 <generic_rawtp_actions+0x757> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48e, 0x757, x86_l_757);
x86_l_494:
	/* 0x494: cmp    r15d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 9ULL);
x86_l_498:
	/* 0x498: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x498, 0x88f, x86_l_88f);
x86_l_49e:
	/* 0x49e: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_4a1:
	/* 0x4a1: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a4:
	/* 0x4a4: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4a9:
	/* 0x4a9: jmp    867 <generic_rawtp_actions+0x867> */
	X86_SIM_X86_JMP(0x4a9, 0x867, x86_l_867);
x86_l_4ae:
	/* 0x4ae: lea    eax,[r15-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_4b2:
	/* 0x4b2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4b5:
	/* 0x4b5: jb     746 <generic_rawtp_actions+0x746> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4b5, 0x746, x86_l_746);
x86_l_4bb:
	/* 0x4bb: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4bf:
	/* 0x4bf: je     764 <generic_rawtp_actions+0x764> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bf, 0x764, x86_l_764);
x86_l_4c5:
	/* 0x4c5: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_4c9:
	/* 0x4c9: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4c9, 0x88f, x86_l_88f);
x86_l_4cf:
	/* 0x4cf: mov    eax,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_4d4:
	/* 0x4d4: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4d8:
	/* 0x4d8: mov    r14d,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_4dd:
	/* 0x4dd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e6:
	/* 0x4e6: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4ef:
	/* 0x4ef: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4f2:
	/* 0x4f2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f5:
	/* 0x4f5: ja     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4f5, 0x88f, x86_l_88f);
x86_l_4fb:
	/* 0x4fb: cmp    DWORD PTR [r8+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_504:
	/* 0x504: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x504, 0x88f, x86_l_88f);
x86_l_50a:
	/* 0x50a: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_512:
	/* 0x512: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_517:
	/* 0x517: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_51f:
	/* 0x51f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_523:
	/* 0x523: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_528:
	/* 0x528: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_52b:
	/* 0x52b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52d:
	/* 0x52d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_531:
	/* 0x531: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_536:
	/* 0x536: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53b:
	/* 0x53b: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_542:
	/* 0x542: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_547:
	/* 0x547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549:
	/* 0x549: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_54c:
	/* 0x54c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54f:
	/* 0x54f: je     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54f, 0x88f, x86_l_88f);
x86_l_555:
	/* 0x555: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_559:
	/* 0x559: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_55d:
	/* 0x55d: ja     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x55d, 0x88f, x86_l_88f);
x86_l_563:
	/* 0x563: cmp    DWORD PTR [r8+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_56c:
	/* 0x56c: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56c, 0x88f, x86_l_88f);
x86_l_572:
	/* 0x572: mov    rcx,QWORD PTR [r8+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_57a:
	/* 0x57a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_582:
	/* 0x582: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_588:
	/* 0x588: mov    ecx,DWORD PTR [r8+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_590:
	/* 0x590: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_594:
	/* 0x594: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_599:
	/* 0x599: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_59e:
	/* 0x59e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5a2:
	/* 0x5a2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a7:
	/* 0x5a7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ac:
	/* 0x5ac: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_5b3:
	/* 0x5b3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b8:
	/* 0x5b8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bd:
	/* 0x5bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bf:
	/* 0x5bf: jmp    88c <generic_rawtp_actions+0x88c> */
	X86_SIM_X86_JMP(0x5bf, 0x88c, x86_l_88c);
x86_l_5c4:
	/* 0x5c4: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_5c8:
	/* 0x5c8: je     85b <generic_rawtp_actions+0x85b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c8, 0x85b, x86_l_85b);
x86_l_5ce:
	/* 0x5ce: cmp    r15d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 13ULL);
x86_l_5d2:
	/* 0x5d2: je     774 <generic_rawtp_actions+0x774> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d2, 0x774, x86_l_774);
x86_l_5d8:
	/* 0x5d8: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_5dc:
	/* 0x5dc: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5dc, 0x88f, x86_l_88f);
x86_l_5e2:
	/* 0x5e2: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_5e5:
	/* 0x5e5: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_5e9:
	/* 0x5e9: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5ee:
	/* 0x5ee: jmp    867 <generic_rawtp_actions+0x867> */
	X86_SIM_X86_JMP(0x5ee, 0x867, x86_l_867);
x86_l_5f3:
	/* 0x5f3: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_5f7:
	/* 0x5f7: je     851 <generic_rawtp_actions+0x851> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f7, 0x851, x86_l_851);
x86_l_5fd:
	/* 0x5fd: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_601:
	/* 0x601: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x601, 0x88f, x86_l_88f);
x86_l_607:
	/* 0x607: mov    r14d,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_60c:
	/* 0x60c: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_610:
	/* 0x610: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_615:
	/* 0x615: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_61d:
	/* 0x61d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_626:
	/* 0x626: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_62f:
	/* 0x62f: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_637:
	/* 0x637: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63c:
	/* 0x63c: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_643:
	/* 0x643: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_648:
	/* 0x648: mov    QWORD PTR [rsp+0x50],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_64d:
	/* 0x64d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64f:
	/* 0x64f: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_654:
	/* 0x654: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_657:
	/* 0x657: je     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x657, 0x88f, x86_l_88f);
x86_l_65d:
	/* 0x65d: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_661:
	/* 0x661: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_665:
	/* 0x665: ja     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x665, 0x88f, x86_l_88f);
x86_l_66b:
	/* 0x66b: cmp    DWORD PTR [r8+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_674:
	/* 0x674: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x674, 0x88f, x86_l_88f);
x86_l_67a:
	/* 0x67a: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_67f:
	/* 0x67f: mov    rax,QWORD PTR [r8+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_687:
	/* 0x687: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_68f:
	/* 0x68f: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_694:
	/* 0x694: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_69c:
	/* 0x69c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a0:
	/* 0x6a0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6a5:
	/* 0x6a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a7:
	/* 0x6a7: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6ab:
	/* 0x6ab: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b0:
	/* 0x6b0: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_6b4:
	/* 0x6b4: jne    f3a <generic_rawtp_actions+0xf3a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b4, 0xf3a, x86_l_f3a);
x86_l_6ba:
	/* 0x6ba: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6c2:
	/* 0x6c2: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6c5:
	/* 0x6c5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6c8:
	/* 0x6c8: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6cd:
	/* 0x6cd: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6d2:
	/* 0x6d2: ja     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6d2, 0x88f, x86_l_88f);
x86_l_6d8:
	/* 0x6d8: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6db:
	/* 0x6db: cmp    DWORD PTR [r8+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_6e4:
	/* 0x6e4: jne    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6e4, 0x88f, x86_l_88f);
x86_l_6ea:
	/* 0x6ea: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_6f2:
	/* 0x6f2: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6f7:
	/* 0x6f7: lea    rdx,[r8+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6fb:
	/* 0x6fb: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_702:
	/* 0x702: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_707:
	/* 0x707: and    esi,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R8, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_70f:
	/* 0x70f: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_712:
	/* 0x712: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_717:
	/* 0x717: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_71a:
	/* 0x71a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71c:
	/* 0x71c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_721:
	/* 0x721: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_728:
	/* 0x728: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72d:
	/* 0x72d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_730:
	/* 0x730: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_732:
	/* 0x732: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_734:
	/* 0x734: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_739:
	/* 0x739: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x739, 0x88f, x86_l_88f);
x86_l_73e:
	/* 0x73e: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_741:
	/* 0x741: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x741, 0x88f, x86_l_88f);
x86_l_746:
	/* 0x746: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_749:
	/* 0x749: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_74e:
	/* 0x74e: mov    DWORD PTR [r8+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_752:
	/* 0x752: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x752, 0x88f, x86_l_88f);
x86_l_757:
	/* 0x757: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_75f:
	/* 0x75f: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x75f, 0x88f, x86_l_88f);
x86_l_764:
	/* 0x764: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_767:
	/* 0x767: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_76a:
	/* 0x76a: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_76f:
	/* 0x76f: jmp    867 <generic_rawtp_actions+0x867> */
	X86_SIM_X86_JMP(0x76f, 0x867, x86_l_867);
x86_l_774:
	/* 0x774: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_777:
	/* 0x777: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_77c:
	/* 0x77c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77e:
	/* 0x77e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_783:
	/* 0x783: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_788:
	/* 0x788: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_78f:
	/* 0x78f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_794:
	/* 0x794: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_796:
	/* 0x796: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_799:
	/* 0x799: je     7e6 <generic_rawtp_actions+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x799, 0x7e6, x86_l_7e6);
x86_l_79b:
	/* 0x79b: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79f:
	/* 0x79f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a4:
	/* 0x7a4: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_7ac:
	/* 0x7ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b1:
	/* 0x7b1: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7b8:
	/* 0x7b8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7bd:
	/* 0x7bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bf:
	/* 0x7bf: mov    DWORD PTR [rsp+0x1c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084289ULL);
x86_l_7c7:
	/* 0x7c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ca:
	/* 0x7ca: je     e68 <generic_rawtp_actions+0xe68> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ca, 0xe68, x86_l_e68);
x86_l_7d0:
	/* 0x7d0: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7d3:
	/* 0x7d3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_7d8:
	/* 0x7d8: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_7df:
	/* 0x7df: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_7e9:
	/* 0x7e9: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x7e9, 0x88f, x86_l_88f);
x86_l_7ee:
	/* 0x7ee: cmp    DWORD PTR [r12+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_7f4:
	/* 0x7f4: je     81b <generic_rawtp_actions+0x81b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f4, 0x81b, x86_l_81b);
x86_l_7f6:
	/* 0x7f6: or     BYTE PTR [r8+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_7fb:
	/* 0x7fb: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_800:
	/* 0x800: mov    rsi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_807:
	/* 0x807: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_80a:
	/* 0x80a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80c:
	/* 0x80c: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_80f:
	/* 0x80f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_811:
	/* 0x811: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_814:
	/* 0x814: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_81b:
	/* 0x81b: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_81f:
	/* 0x81f: cmp    DWORD PTR [r12+r13*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 17179869184ULL);
x86_l_825:
	/* 0x825: je     88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x825, 0x88f, x86_l_88f);
x86_l_827:
	/* 0x827: or     BYTE PTR [r8+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_82c:
	/* 0x82c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_831:
	/* 0x831: mov    rsi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_838:
	/* 0x838: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_83d:
	/* 0x83d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_840:
	/* 0x840: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_843:
	/* 0x843: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_845:
	/* 0x845: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_848:
	/* 0x848: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_84f:
	/* 0x84f: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0x84f, 0x88f, x86_l_88f);
x86_l_851:
	/* 0x851: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_854:
	/* 0x854: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_859:
	/* 0x859: jmp    867 <generic_rawtp_actions+0x867> */
	X86_SIM_X86_JMP(0x859, 0x867, x86_l_867);
x86_l_85b:
	/* 0x85b: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_85e:
	/* 0x85e: add    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_862:
	/* 0x862: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_867:
	/* 0x867: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_86f:
	/* 0x86f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_874:
	/* 0x874: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_87b:
	/* 0x87b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_880:
	/* 0x880: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_882:
	/* 0x882: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_885:
	/* 0x885: je     88c <generic_rawtp_actions+0x88c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x885, 0x88c, x86_l_88c);
x86_l_887:
	/* 0x887: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_88c:
	/* 0x88c: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_88f:
	/* 0x88f: mov    QWORD PTR [r8+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_893:
	/* 0x893: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_896:
	/* 0x896: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_899:
	/* 0x899: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_8a0:
	/* 0x8a0: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_8a4:
	/* 0x8a4: jae    c60 <generic_rawtp_actions+0xc60> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x8a4, 0xc60, x86_l_c60);
x86_l_8aa:
	/* 0x8aa: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_8ad:
	/* 0x8ad: movsxd rbp,DWORD PTR [r12+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_8b2:
	/* 0x8b2: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_8ba:
	/* 0x8ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8bf:
	/* 0x8bf: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_8c6:
	/* 0x8c6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8cb:
	/* 0x8cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cd:
	/* 0x8cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8d0:
	/* 0x8d0: je     c60 <generic_rawtp_actions+0xc60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d0, 0xc60, x86_l_c60);
x86_l_8d6:
	/* 0x8d6: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8d9:
	/* 0x8d9: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_8dc:
	/* 0x8dc: jle    8fd <generic_rawtp_actions+0x8fd> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x8dc, 0x8fd, x86_l_8fd);
x86_l_8de:
	/* 0x8de: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_8e1:
	/* 0x8e1: jg     926 <generic_rawtp_actions+0x926> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8e1, 0x926, x86_l_926);
x86_l_8e3:
	/* 0x8e3: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_8e6:
	/* 0x8e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8e9:
	/* 0x8e9: jb     a43 <generic_rawtp_actions+0xa43> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8e9, 0xa43, x86_l_a43);
x86_l_8ef:
	/* 0x8ef: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_8f2:
	/* 0x8f2: je     b5a <generic_rawtp_actions+0xb5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f2, 0xb5a, x86_l_b5a);
x86_l_8f8:
	/* 0x8f8: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_8fb:
	/* 0x8fb: jmp    916 <generic_rawtp_actions+0x916> */
	X86_SIM_X86_JMP(0x8fb, 0x916, x86_l_916);
x86_l_8fd:
	/* 0x8fd: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_900:
	/* 0x900: jg     950 <generic_rawtp_actions+0x950> */
	X86_SIM_X86_JCC(X86_CC_G, 0x900, 0x950, x86_l_950);
x86_l_902:
	/* 0x902: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_904:
	/* 0x904: je     bdf <generic_rawtp_actions+0xbdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x904, 0xbdf, x86_l_bdf);
x86_l_90a:
	/* 0x90a: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_90d:
	/* 0x90d: je     a51 <generic_rawtp_actions+0xa51> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90d, 0xa51, x86_l_a51);
x86_l_913:
	/* 0x913: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_916:
	/* 0x916: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_91b:
	/* 0x91b: je     c37 <generic_rawtp_actions+0xc37> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91b, 0xc37, x86_l_c37);
x86_l_921:
	/* 0x921: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0x921, 0xc5c, x86_l_c5c);
x86_l_926:
	/* 0x926: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_92b:
	/* 0x92b: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_92e:
	/* 0x92e: je     c37 <generic_rawtp_actions+0xc37> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92e, 0xc37, x86_l_c37);
x86_l_934:
	/* 0x934: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_937:
	/* 0x937: je     b67 <generic_rawtp_actions+0xb67> */
	X86_SIM_X86_JCC(X86_CC_E, 0x937, 0xb67, x86_l_b67);
x86_l_93d:
	/* 0x93d: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_942:
	/* 0x942: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_945:
	/* 0x945: je     c37 <generic_rawtp_actions+0xc37> */
	X86_SIM_X86_JCC(X86_CC_E, 0x945, 0xc37, x86_l_c37);
x86_l_94b:
	/* 0x94b: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0x94b, 0xc5c, x86_l_c5c);
x86_l_950:
	/* 0x950: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_953:
	/* 0x953: je     a51 <generic_rawtp_actions+0xa51> */
	X86_SIM_X86_JCC(X86_CC_E, 0x953, 0xa51, x86_l_a51);
x86_l_959:
	/* 0x959: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_95c:
	/* 0x95c: je     c32 <generic_rawtp_actions+0xc32> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95c, 0xc32, x86_l_c32);
x86_l_962:
	/* 0x962: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_965:
	/* 0x965: jne    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x965, 0xc5c, x86_l_c5c);
x86_l_96b:
	/* 0x96b: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_970:
	/* 0x970: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_975:
	/* 0x975: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_97e:
	/* 0x97e: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_987:
	/* 0x987: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_98a:
	/* 0x98a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_98d:
	/* 0x98d: ja     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x98d, 0xc5c, x86_l_c5c);
x86_l_993:
	/* 0x993: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_99c:
	/* 0x99c: jne    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x99c, 0xc5c, x86_l_c5c);
x86_l_9a2:
	/* 0x9a2: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_9aa:
	/* 0x9aa: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9af:
	/* 0x9af: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_9b7:
	/* 0x9b7: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9bb:
	/* 0x9bb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9c0:
	/* 0x9c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c2:
	/* 0x9c2: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_9c6:
	/* 0x9c6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9cb:
	/* 0x9cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9d0:
	/* 0x9d0: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9d7:
	/* 0x9d7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9dc:
	/* 0x9dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9de:
	/* 0x9de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e1:
	/* 0x9e1: je     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e1, 0xc5c, x86_l_c5c);
x86_l_9e7:
	/* 0x9e7: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_9eb:
	/* 0x9eb: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_9ef:
	/* 0x9ef: ja     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9ef, 0xc5c, x86_l_c5c);
x86_l_9f5:
	/* 0x9f5: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_9fe:
	/* 0x9fe: jne    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9fe, 0xc5c, x86_l_c5c);
x86_l_a04:
	/* 0xa04: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_a0c:
	/* 0xa0c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_a14:
	/* 0xa14: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a1a:
	/* 0xa1a: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_a22:
	/* 0xa22: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a26:
	/* 0xa26: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_a2b:
	/* 0xa2b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_a2e:
	/* 0xa2e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a30:
	/* 0xa30: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_a34:
	/* 0xa34: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a39:
	/* 0xa39: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a3e:
	/* 0xa3e: jmp    b42 <generic_rawtp_actions+0xb42> */
	X86_SIM_X86_JMP(0xa3e, 0xb42, x86_l_b42);
x86_l_a43:
	/* 0xa43: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_a48:
	/* 0xa48: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a4c:
	/* 0xa4c: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0xa4c, 0xc5c, x86_l_c5c);
x86_l_a51:
	/* 0xa51: mov    r13d,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_a56:
	/* 0xa56: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_a5b:
	/* 0xa5b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a6d:
	/* 0xa6d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_a75:
	/* 0xa75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a7a:
	/* 0xa7a: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_a81:
	/* 0xa81: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a86:
	/* 0xa86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a88:
	/* 0xa88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8b:
	/* 0xa8b: je     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8b, 0xc5c, x86_l_c5c);
x86_l_a91:
	/* 0xa91: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a95:
	/* 0xa95: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_a99:
	/* 0xa99: ja     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa99, 0xc5c, x86_l_c5c);
x86_l_a9f:
	/* 0xa9f: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_aa8:
	/* 0xaa8: jne    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaa8, 0xc5c, x86_l_c5c);
x86_l_aae:
	/* 0xaae: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ab1:
	/* 0xab1: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_ab9:
	/* 0xab9: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_ac1:
	/* 0xac1: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ac6:
	/* 0xac6: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_ace:
	/* 0xace: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad2:
	/* 0xad2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ad7:
	/* 0xad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad9:
	/* 0xad9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_add:
	/* 0xadd: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae2:
	/* 0xae2: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_ae5:
	/* 0xae5: jne    fb4 <generic_rawtp_actions+0xfb4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xae5, 0xfb4, x86_l_fb4);
x86_l_aeb:
	/* 0xaeb: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_aef:
	/* 0xaef: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_af3:
	/* 0xaf3: ja     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xaf3, 0xc5c, x86_l_c5c);
x86_l_af9:
	/* 0xaf9: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_b02:
	/* 0xb02: jne    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb02, 0xc5c, x86_l_c5c);
x86_l_b08:
	/* 0xb08: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b0b:
	/* 0xb0b: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_b13:
	/* 0xb13: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_b18:
	/* 0xb18: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b1c:
	/* 0xb1c: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_b23:
	/* 0xb23: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_b28:
	/* 0xb28: and    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_b30:
	/* 0xb30: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_b33:
	/* 0xb33: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b38:
	/* 0xb38: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_b3b:
	/* 0xb3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3d:
	/* 0xb3d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b42:
	/* 0xb42: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_b49:
	/* 0xb49: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4e:
	/* 0xb4e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b51:
	/* 0xb51: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b53:
	/* 0xb53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b55:
	/* 0xb55: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0xb55, 0xc5c, x86_l_c5c);
x86_l_b5a:
	/* 0xb5a: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_b62:
	/* 0xb62: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0xb62, 0xc5c, x86_l_c5c);
x86_l_b67:
	/* 0xb67: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_b6c:
	/* 0xb6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6e:
	/* 0xb6e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b73:
	/* 0xb73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b78:
	/* 0xb78: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_b7f:
	/* 0xb7f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b84:
	/* 0xb84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b86:
	/* 0xb86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b89:
	/* 0xb89: je     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb89, 0xc5c, x86_l_c5c);
x86_l_b8f:
	/* 0xb8f: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b93:
	/* 0xb93: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b98:
	/* 0xb98: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_ba0:
	/* 0xba0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba5:
	/* 0xba5: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_bac:
	/* 0xbac: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb1:
	/* 0xbb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb3:
	/* 0xbb3: mov    DWORD PTR [rsp+0x1c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084289ULL);
x86_l_bbb:
	/* 0xbbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bbe:
	/* 0xbbe: je     ed1 <generic_rawtp_actions+0xed1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbe, 0xed1, x86_l_ed1);
x86_l_bc4:
	/* 0xbc4: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bc7:
	/* 0xbc7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_bcc:
	/* 0xbcc: mov    rdi,QWORD PTR [rip+0x622a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_bd3:
	/* 0xbd3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bd8:
	/* 0xbd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bda:
	/* 0xbda: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0xbda, 0xc5c, x86_l_c5c);
x86_l_bdf:
	/* 0xbdf: cmp    DWORD PTR [r12+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_be5:
	/* 0xbe5: je     c06 <generic_rawtp_actions+0xc06> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe5, 0xc06, x86_l_c06);
x86_l_be7:
	/* 0xbe7: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_bec:
	/* 0xbec: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_bf1:
	/* 0xbf1: mov    rsi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_bf8:
	/* 0xbf8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bfb:
	/* 0xbfb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bfd:
	/* 0xbfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bff:
	/* 0xbff: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c06:
	/* 0xc06: cmp    DWORD PTR [r12+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_c0c:
	/* 0xc0c: je     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc0c, 0xc5c, x86_l_c5c);
x86_l_c0e:
	/* 0xc0e: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c18:
	/* 0xc18: mov    rsi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c1f:
	/* 0xc1f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c24:
	/* 0xc24: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c27:
	/* 0xc27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c29:
	/* 0xc29: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c30:
	/* 0xc30: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0xc30, 0xc5c, x86_l_c5c);
x86_l_c32:
	/* 0xc32: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c37:
	/* 0xc37: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c3f:
	/* 0xc3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c44:
	/* 0xc44: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_c4b:
	/* 0xc4b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c50:
	/* 0xc50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c52:
	/* 0xc52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c55:
	/* 0xc55: je     c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc55, 0xc5c, x86_l_c5c);
x86_l_c57:
	/* 0xc57: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c5c:
	/* 0xc5c: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c60:
	/* 0xc60: mov    ebp,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c64:
	/* 0xc64: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_c67:
	/* 0xc67: jne    44c <generic_rawtp_actions+0x44c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc67, 0x44c, x86_l_44c);
x86_l_c6d:
	/* 0xc6d: jmp    462 <generic_rawtp_actions+0x462> */
	X86_SIM_X86_JMP(0xc6d, 0x462, x86_l_462);
x86_l_c72:
	/* 0xc72: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c77:
	/* 0xc77: mov    rax,QWORD PTR [r14+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_c7f:
	/* 0xc7f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_c87:
	/* 0xc87: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_c8c:
	/* 0xc8c: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_c94:
	/* 0xc94: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c98:
	/* 0xc98: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_c9d:
	/* 0xc9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9f:
	/* 0xc9f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ca3:
	/* 0xca3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca8:
	/* 0xca8: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_cac:
	/* 0xcac: jne    e42 <generic_rawtp_actions+0xe42> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcac, 0xe42, x86_l_e42);
x86_l_cb2:
	/* 0xcb2: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_cb6:
	/* 0xcb6: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_cba:
	/* 0xcba: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cbf:
	/* 0xcbf: ja     287 <generic_rawtp_actions+0x287> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcbf, 0x287, x86_l_287);
x86_l_cc5:
	/* 0xcc5: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_cce:
	/* 0xcce: jne    287 <generic_rawtp_actions+0x287> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcce, 0x287, x86_l_287);
x86_l_cd4:
	/* 0xcd4: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_cdc:
	/* 0xcdc: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ce1:
	/* 0xce1: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ce5:
	/* 0xce5: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_cec:
	/* 0xcec: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_cf1:
	/* 0xcf1: and    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_cf9:
	/* 0xcf9: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_cfc:
	/* 0xcfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d01:
	/* 0xd01: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_d04:
	/* 0xd04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d06:
	/* 0xd06: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d0b:
	/* 0xd0b: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_d12:
	/* 0xd12: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d17:
	/* 0xd17: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d1a:
	/* 0xd1a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d1c:
	/* 0xd1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1e:
	/* 0xd1e: jmp    287 <generic_rawtp_actions+0x287> */
	X86_SIM_X86_JMP(0xd1e, 0x287, x86_l_287);
x86_l_d23:
	/* 0xd23: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d28:
	/* 0xd28: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d2f:
	/* 0xd2f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d34:
	/* 0xd34: lea    rdx,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d39:
	/* 0xd39: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d3e:
	/* 0xd3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d40:
	/* 0xd40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d43:
	/* 0xd43: je     320 <generic_rawtp_actions+0x320> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd43, 0x320, x86_l_320);
x86_l_d49:
	/* 0xd49: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d4e:
	/* 0xd4e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d50:
	/* 0xd50: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d55:
	/* 0xd55: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_d5c:
	/* 0xd5c: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_d66:
	/* 0xd66: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d6b:
	/* 0xd6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d77:
	/* 0xd77: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7c:
	/* 0xd7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7e:
	/* 0xd7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d81:
	/* 0xd81: je     f5f <generic_rawtp_actions+0xf5f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd81, 0xf5f, x86_l_f5f);
x86_l_d87:
	/* 0xd87: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d89:
	/* 0xd89: jmp    f81 <generic_rawtp_actions+0xf81> */
	X86_SIM_X86_JMP(0xd89, 0xf81, x86_l_f81);
x86_l_d8e:
	/* 0xd8e: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_d96:
	/* 0xd96: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_d9b:
	/* 0xd9b: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_da3:
	/* 0xda3: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da7:
	/* 0xda7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_dac:
	/* 0xdac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dae:
	/* 0xdae: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_db2:
	/* 0xdb2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db7:
	/* 0xdb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dbc:
	/* 0xdbc: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_dc3:
	/* 0xdc3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc8:
	/* 0xdc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dca:
	/* 0xdca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dcd:
	/* 0xdcd: je     1e7 <generic_rawtp_actions+0x1e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdcd, 0x1e7, x86_l_1e7);
x86_l_dd3:
	/* 0xdd3: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_dd7:
	/* 0xdd7: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_ddb:
	/* 0xddb: ja     1e7 <generic_rawtp_actions+0x1e7> */
	X86_SIM_X86_JCC(X86_CC_A, 0xddb, 0x1e7, x86_l_1e7);
x86_l_de1:
	/* 0xde1: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_dea:
	/* 0xdea: jne    1e7 <generic_rawtp_actions+0x1e7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdea, 0x1e7, x86_l_1e7);
x86_l_df0:
	/* 0xdf0: mov    rcx,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_df8:
	/* 0xdf8: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_e00:
	/* 0xe00: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e06:
	/* 0xe06: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e0e:
	/* 0xe0e: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e12:
	/* 0xe12: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_e17:
	/* 0xe17: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e1a:
	/* 0xe1a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e1c:
	/* 0xe1c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e25:
	/* 0xe25: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e2a:
	/* 0xe2a: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e31:
	/* 0xe31: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e36:
	/* 0xe36: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e39:
	/* 0xe39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e3b:
	/* 0xe3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3d:
	/* 0xe3d: jmp    1e7 <generic_rawtp_actions+0x1e7> */
	X86_SIM_X86_JMP(0xe3d, 0x1e7, x86_l_1e7);
x86_l_e42:
	/* 0xe42: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_e47:
	/* 0xe47: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e4e:
	/* 0xe4e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e53:
	/* 0xe53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e55:
	/* 0xe55: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e58:
	/* 0xe58: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_e5b:
	/* 0xe5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e5d:
	/* 0xe5d: jne    3d2 <generic_rawtp_actions+0x3d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe5d, 0x3d2, x86_l_3d2);
x86_l_e63:
	/* 0xe63: jmp    1e7 <generic_rawtp_actions+0x1e7> */
	X86_SIM_X86_JMP(0xe63, 0x1e7, x86_l_1e7);
x86_l_e68:
	/* 0xe68: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e6d:
	/* 0xe6d: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_e74:
	/* 0xe74: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e79:
	/* 0xe79: lea    rdx,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e7e:
	/* 0xe7e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e83:
	/* 0xe83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e85:
	/* 0xe85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e88:
	/* 0xe88: je     7d3 <generic_rawtp_actions+0x7d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe88, 0x7d3, x86_l_7d3);
x86_l_e8e:
	/* 0xe8e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e91:
	/* 0xe91: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_e93:
	/* 0xe93: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e98:
	/* 0xe98: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_e9f:
	/* 0xe9f: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_ea9:
	/* 0xea9: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eae:
	/* 0xeae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb3:
	/* 0xeb3: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_eba:
	/* 0xeba: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ebf:
	/* 0xebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec1:
	/* 0xec1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec4:
	/* 0xec4: je     fd4 <generic_rawtp_actions+0xfd4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec4, 0xfd4, x86_l_fd4);
x86_l_eca:
	/* 0xeca: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ecc:
	/* 0xecc: jmp    ff6 <generic_rawtp_actions+0xff6> */
	X86_SIM_X86_JMP(0xecc, 0xff6, x86_l_ff6);
x86_l_ed1:
	/* 0xed1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ed6:
	/* 0xed6: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_edd:
	/* 0xedd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee2:
	/* 0xee2: lea    rdx,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_ee7:
	/* 0xee7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_eec:
	/* 0xeec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eee:
	/* 0xeee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef1:
	/* 0xef1: je     bc7 <generic_rawtp_actions+0xbc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xef1, 0xbc7, x86_l_bc7);
x86_l_ef7:
	/* 0xef7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_efa:
	/* 0xefa: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_efc:
	/* 0xefc: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f01:
	/* 0xf01: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_f08:
	/* 0xf08: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_f12:
	/* 0xf12: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f17:
	/* 0xf17: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1c:
	/* 0xf1c: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f23:
	/* 0xf23: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f28:
	/* 0xf28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2a:
	/* 0xf2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2d:
	/* 0xf2d: je     1026 <generic_rawtp_actions+0x1026> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf2d, 0x1026, x86_l_1026);
x86_l_f33:
	/* 0xf33: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f35:
	/* 0xf35: jmp    1048 <generic_rawtp_actions+0x1048> */
	X86_SIM_X86_JMP(0xf35, 0x1048, x86_l_1048);
x86_l_f3a:
	/* 0xf3a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f3f:
	/* 0xf3f: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_f46:
	/* 0xf46: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f4f:
	/* 0xf4f: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f54:
	/* 0xf54: jne    899 <generic_rawtp_actions+0x899> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf54, 0x899, x86_l_899);
x86_l_f5a:
	/* 0xf5a: jmp    88f <generic_rawtp_actions+0x88f> */
	X86_SIM_X86_JMP(0xf5a, 0x88f, x86_l_88f);
x86_l_f5f:
	/* 0xf5f: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_f67:
	/* 0xf67: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f6c:
	/* 0xf6c: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f73:
	/* 0xf73: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f78:
	/* 0xf78: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f7d:
	/* 0xf7d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7f:
	/* 0xf7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f81:
	/* 0xf81: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_f86:
	/* 0xf86: je     320 <generic_rawtp_actions+0x320> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf86, 0x320, x86_l_320);
x86_l_f8c:
	/* 0xf8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f91:
	/* 0xf91: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_f98:
	/* 0xf98: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f9d:
	/* 0xf9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9f:
	/* 0xf9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa2:
	/* 0xfa2: je     320 <generic_rawtp_actions+0x320> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa2, 0x320, x86_l_320);
x86_l_fa8:
	/* 0xfa8: mov    ecx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_fac:
	/* 0xfac: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_faf:
	/* 0xfaf: jmp    320 <generic_rawtp_actions+0x320> */
	X86_SIM_X86_JMP(0xfaf, 0x320, x86_l_320);
x86_l_fb4:
	/* 0xfb4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_fb9:
	/* 0xfb9: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_fc0:
	/* 0xfc0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc5:
	/* 0xfc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc7:
	/* 0xfc7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc9:
	/* 0xfc9: jne    c60 <generic_rawtp_actions+0xc60> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfc9, 0xc60, x86_l_c60);
x86_l_fcf:
	/* 0xfcf: jmp    c5c <generic_rawtp_actions+0xc5c> */
	X86_SIM_X86_JMP(0xfcf, 0xc5c, x86_l_c5c);
x86_l_fd4:
	/* 0xfd4: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_fdc:
	/* 0xfdc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fe1:
	/* 0xfe1: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_fe8:
	/* 0xfe8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fed:
	/* 0xfed: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ff2:
	/* 0xff2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ff4:
	/* 0xff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff6:
	/* 0xff6: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_ff8:
	/* 0xff8: je     7d3 <generic_rawtp_actions+0x7d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff8, 0x7d3, x86_l_7d3);
x86_l_ffe:
	/* 0xffe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1003:
	/* 0x1003: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_100a:
	/* 0x100a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_100f:
	/* 0x100f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1011:
	/* 0x1011: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1014:
	/* 0x1014: je     7d3 <generic_rawtp_actions+0x7d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1014, 0x7d3, x86_l_7d3);
x86_l_101a:
	/* 0x101a: mov    ecx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_101e:
	/* 0x101e: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1021:
	/* 0x1021: jmp    7d3 <generic_rawtp_actions+0x7d3> */
	X86_SIM_X86_JMP(0x1021, 0x7d3, x86_l_7d3);
x86_l_1026:
	/* 0x1026: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_102e:
	/* 0x102e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1033:
	/* 0x1033: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_103a:
	/* 0x103a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103f:
	/* 0x103f: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1044:
	/* 0x1044: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1046:
	/* 0x1046: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1048:
	/* 0x1048: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_104b:
	/* 0x104b: je     bc7 <generic_rawtp_actions+0xbc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104b, 0xbc7, x86_l_bc7);
x86_l_1051:
	/* 0x1051: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1056:
	/* 0x1056: mov    rdi,QWORD PTR [rip+0x6227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_105d:
	/* 0x105d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1062:
	/* 0x1062: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1064:
	/* 0x1064: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1067:
	/* 0x1067: je     bc7 <generic_rawtp_actions+0xbc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1067, 0xbc7, x86_l_bc7);
x86_l_106d:
	/* 0x106d: mov    ecx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1071:
	/* 0x1071: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1074:
	/* 0x1074: jmp    bc7 <generic_rawtp_actions+0xbc7> */
	X86_SIM_X86_JMP(0x1074, 0xbc7, x86_l_bc7);
x86_l_1079:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
