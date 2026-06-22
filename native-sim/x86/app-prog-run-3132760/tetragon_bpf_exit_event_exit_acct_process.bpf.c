extern char execve_map;
extern char execve_map_stats;
extern char exit_heap_map;
extern char tcpmon_map;
extern char tg_parents_bin;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_exit_event_exit_acct_process_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2:
	/* 0x2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_6:
	/* 0x6: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_9:
	/* 0x9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e:
	/* 0xe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10:
	/* 0x10: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_13:
	/* 0x13: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_17:
	/* 0x17: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_23:
	/* 0x23: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28:
	/* 0x28: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d:
	/* 0x2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f:
	/* 0x2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: je     1f7 <event_exit_acct_process+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32, 0x1f7, x86_l_1f7);
x86_l_38:
	/* 0x38: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_40:
	/* 0x40: je     182 <event_exit_acct_process+0x182> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40, 0x182, x86_l_182);
x86_l_46:
	/* 0x46: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_58:
	/* 0x58: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exit_heap_map)));
x86_l_5f:
	/* 0x5f: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_64:
	/* 0x64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_69:
	/* 0x69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b:
	/* 0x6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: je     1f7 <event_exit_acct_process+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0x1f7, x86_l_1f7);
x86_l_74:
	/* 0x74: movabs rcx,0x2800000007 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 171798691847ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81:
	/* 0x81: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_89:
	/* 0x89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b:
	/* 0x8b: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f:
	/* 0x8f: mov    DWORD PTR [r13+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_93:
	/* 0x93: mov    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_9b:
	/* 0x9b: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f:
	/* 0x9f: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a3:
	/* 0xa3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_a6:
	/* 0xa6: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_aa:
	/* 0xaa: mov    DWORD PTR [r13+0x24],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ae:
	/* 0xae: add    r12,0xa6c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2668ULL);
x86_l_b5:
	/* 0xb5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ba:
	/* 0xba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bf:
	/* 0xbf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c4:
	/* 0xc4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c7:
	/* 0xc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9:
	/* 0xc9: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_d0:
	/* 0xd0: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_d5:
	/* 0xd5: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_da:
	/* 0xda: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_df:
	/* 0xdf: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_e4:
	/* 0xe4: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_ea:
	/* 0xea: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2:
	/* 0xf2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f5:
	/* 0xf5: jns    182 <event_exit_acct_process+0x182> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xf5, 0x182, x86_l_182);
x86_l_fb:
	/* 0xfb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_106:
	/* 0x106: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_10d:
	/* 0x10d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112:
	/* 0x112: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_117:
	/* 0x117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119:
	/* 0x119: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c:
	/* 0x11c: je     182 <event_exit_acct_process+0x182> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c, 0x182, x86_l_182);
x86_l_11e:
	/* 0x11e: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_122:
	/* 0x122: jg     13e <event_exit_acct_process+0x13e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x122, 0x13e, x86_l_13e);
x86_l_124:
	/* 0x124: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_128:
	/* 0x128: je     158 <event_exit_acct_process+0x158> */
	X86_SIM_X86_JCC(X86_CC_E, 0x128, 0x158, x86_l_158);
x86_l_12a:
	/* 0x12a: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_12e:
	/* 0x12e: je     170 <event_exit_acct_process+0x170> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e, 0x170, x86_l_170);
x86_l_130:
	/* 0x130: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_134:
	/* 0x134: jne    168 <event_exit_acct_process+0x168> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x134, 0x168, x86_l_168);
x86_l_136:
	/* 0x136: add    rax,0x1a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 416ULL);
x86_l_13c:
	/* 0x13c: jmp    17e <event_exit_acct_process+0x17e> */
	X86_SIM_X86_JMP(0x13c, 0x17e, x86_l_17e);
x86_l_13e:
	/* 0x13e: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_142:
	/* 0x142: je     160 <event_exit_acct_process+0x160> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142, 0x160, x86_l_160);
x86_l_144:
	/* 0x144: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_148:
	/* 0x148: je     178 <event_exit_acct_process+0x178> */
	X86_SIM_X86_JCC(X86_CC_E, 0x148, 0x178, x86_l_178);
x86_l_14a:
	/* 0x14a: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_14e:
	/* 0x14e: jne    168 <event_exit_acct_process+0x168> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14e, 0x168, x86_l_168);
x86_l_150:
	/* 0x150: add    rax,0x190 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 400ULL);
x86_l_156:
	/* 0x156: jmp    17e <event_exit_acct_process+0x17e> */
	X86_SIM_X86_JMP(0x156, 0x17e, x86_l_17e);
x86_l_158:
	/* 0x158: add    rax,0x1b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 432ULL);
x86_l_15e:
	/* 0x15e: jmp    17e <event_exit_acct_process+0x17e> */
	X86_SIM_X86_JMP(0x15e, 0x17e, x86_l_17e);
x86_l_160:
	/* 0x160: add    rax,0x1b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 440ULL);
x86_l_166:
	/* 0x166: jmp    17e <event_exit_acct_process+0x17e> */
	X86_SIM_X86_JMP(0x166, 0x17e, x86_l_17e);
x86_l_168:
	/* 0x168: add    rax,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_16e:
	/* 0x16e: jmp    17e <event_exit_acct_process+0x17e> */
	X86_SIM_X86_JMP(0x16e, 0x17e, x86_l_17e);
x86_l_170:
	/* 0x170: add    rax,0x1a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 424ULL);
x86_l_176:
	/* 0x176: jmp    17e <event_exit_acct_process+0x17e> */
	X86_SIM_X86_JMP(0x176, 0x17e, x86_l_17e);
x86_l_178:
	/* 0x178: add    rax,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_17e:
	/* 0x17e: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_182:
	/* 0x182: mov    DWORD PTR [rsp+0xc],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_187:
	/* 0x187: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_18e:
	/* 0x18e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_193:
	/* 0x193: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_198:
	/* 0x198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a:
	/* 0x19a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19c:
	/* 0x19c: je     1c3 <event_exit_acct_process+0x1c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19c, 0x1c3, x86_l_1c3);
x86_l_19e:
	/* 0x19e: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_1a6:
	/* 0x1a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_1ad:
	/* 0x1ad: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2:
	/* 0x1b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b7:
	/* 0x1b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9:
	/* 0x1b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bc:
	/* 0x1bc: je     1e6 <event_exit_acct_process+0x1e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bc, 0x1e6, x86_l_1e6);
x86_l_1be:
	/* 0x1be: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c1:
	/* 0x1c1: jmp    1e6 <event_exit_acct_process+0x1e6> */
	X86_SIM_X86_JMP(0x1c1, 0x1e6, x86_l_1e6);
x86_l_1c3:
	/* 0x1c3: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1cb:
	/* 0x1cb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_1d2:
	/* 0x1d2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d7:
	/* 0x1d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dc:
	/* 0x1dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de:
	/* 0x1de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e1:
	/* 0x1e1: je     1e6 <event_exit_acct_process+0x1e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1, 0x1e6, x86_l_1e6);
x86_l_1e3:
	/* 0x1e3: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_1e6:
	/* 0x1e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_1ed:
	/* 0x1ed: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1f2:
	/* 0x1f2: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1f5:
	/* 0x1f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f7:
	/* 0x1f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9:
	/* 0x1f9: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fd:
	/* 0x1fd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: jmp    204 <event_exit_acct_process+0x204> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_204:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
