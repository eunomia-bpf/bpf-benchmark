extern char execve_map;
extern char execve_map_stats;
extern char exit_heap_map;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_parents_bin;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_exit_v511_event_exit_acct_process_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x17: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_23:
	/* 0x23: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
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
	/* 0x32: je     2a4 <event_exit_acct_process+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32, 0x2a4, x86_l_2a4);
x86_l_38:
	/* 0x38: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_40:
	/* 0x40: je     22f <event_exit_acct_process+0x22f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40, 0x22f, x86_l_22f);
x86_l_46:
	/* 0x46: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
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
	/* 0x6e: je     2a4 <event_exit_acct_process+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0x2a4, x86_l_2a4);
x86_l_74:
	/* 0x74: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_77:
	/* 0x77: movabs rax,0x2800000007 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 171798691847ULL);
x86_l_81:
	/* 0x81: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85:
	/* 0x85: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_8a:
	/* 0x8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_91:
	/* 0x91: mov    DWORD PTR [r12+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96:
	/* 0x96: mov    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_9f:
	/* 0x9f: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a8:
	/* 0xa8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ab:
	/* 0xab: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_af:
	/* 0xaf: mov    DWORD PTR [r12+0x24],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b4:
	/* 0xb4: add    r13,0xa6c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2668ULL);
x86_l_bb:
	/* 0xbb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c0:
	/* 0xc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c5:
	/* 0xc5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ca:
	/* 0xca: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_cd:
	/* 0xcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf:
	/* 0xcf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d7:
	/* 0xd7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_de:
	/* 0xde: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3:
	/* 0xe3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8:
	/* 0xe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea:
	/* 0xea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: je     17b <event_exit_acct_process+0x17b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed, 0x17b, x86_l_17b);
x86_l_f3:
	/* 0xf3: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_f7:
	/* 0xf7: je     17b <event_exit_acct_process+0x17b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf7, 0x17b, x86_l_17b);
x86_l_fd:
	/* 0xfd: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_104:
	/* 0x104: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_109:
	/* 0x109: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_10e:
	/* 0x10e: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_113:
	/* 0x113: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_118:
	/* 0x118: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_11e:
	/* 0x11e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_121:
	/* 0x121: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_124:
	/* 0x124: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126:
	/* 0x126: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129:
	/* 0x129: jns    22f <event_exit_acct_process+0x22f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x129, 0x22f, x86_l_22f);
x86_l_12f:
	/* 0x12f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_132:
	/* 0x132: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_13a:
	/* 0x13a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_141:
	/* 0x141: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_146:
	/* 0x146: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14b:
	/* 0x14b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d:
	/* 0x14d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     22f <event_exit_acct_process+0x22f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x150, 0x22f, x86_l_22f);
x86_l_156:
	/* 0x156: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_15a:
	/* 0x15a: jg     1fb <event_exit_acct_process+0x1fb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x15a, 0x1fb, x86_l_1fb);
x86_l_160:
	/* 0x160: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_164:
	/* 0x164: je     215 <event_exit_acct_process+0x215> */
	X86_SIM_X86_JCC(X86_CC_E, 0x164, 0x215, x86_l_215);
x86_l_16a:
	/* 0x16a: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_16e:
	/* 0x16e: jne    1d3 <event_exit_acct_process+0x1d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16e, 0x1d3, x86_l_1d3);
x86_l_170:
	/* 0x170: add    rax,0x1a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 424ULL);
x86_l_176:
	/* 0x176: jmp    22b <event_exit_acct_process+0x22b> */
	X86_SIM_X86_JMP(0x176, 0x22b, x86_l_22b);
x86_l_17b:
	/* 0x17b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_182:
	/* 0x182: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184:
	/* 0x184: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_189:
	/* 0x189: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_18e:
	/* 0x18e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_191:
	/* 0x191: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193:
	/* 0x193: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195:
	/* 0x195: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_198:
	/* 0x198: jns    22f <event_exit_acct_process+0x22f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x198, 0x22f, x86_l_22f);
x86_l_19e:
	/* 0x19e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1a1:
	/* 0x1a1: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1a9:
	/* 0x1a9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_1b0:
	/* 0x1b0: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b5:
	/* 0x1b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ba:
	/* 0x1ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc:
	/* 0x1bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf:
	/* 0x1bf: je     22f <event_exit_acct_process+0x22f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf, 0x22f, x86_l_22f);
x86_l_1c1:
	/* 0x1c1: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1c5:
	/* 0x1c5: jg     1e1 <event_exit_acct_process+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1c5, 0x1e1, x86_l_1e1);
x86_l_1c7:
	/* 0x1c7: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1cb:
	/* 0x1cb: je     215 <event_exit_acct_process+0x215> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cb, 0x215, x86_l_215);
x86_l_1cd:
	/* 0x1cd: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1d1:
	/* 0x1d1: je     170 <event_exit_acct_process+0x170> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d1, 0x170, x86_l_170);
x86_l_1d3:
	/* 0x1d3: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_1d7:
	/* 0x1d7: jne    20d <event_exit_acct_process+0x20d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d7, 0x20d, x86_l_20d);
x86_l_1d9:
	/* 0x1d9: add    rax,0x1a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 416ULL);
x86_l_1df:
	/* 0x1df: jmp    22b <event_exit_acct_process+0x22b> */
	X86_SIM_X86_JMP(0x1df, 0x22b, x86_l_22b);
x86_l_1e1:
	/* 0x1e1: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1e5:
	/* 0x1e5: je     21d <event_exit_acct_process+0x21d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e5, 0x21d, x86_l_21d);
x86_l_1e7:
	/* 0x1e7: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1eb:
	/* 0x1eb: je     225 <event_exit_acct_process+0x225> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1eb, 0x225, x86_l_225);
x86_l_1ed:
	/* 0x1ed: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1f1:
	/* 0x1f1: jne    20d <event_exit_acct_process+0x20d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f1, 0x20d, x86_l_20d);
x86_l_1f3:
	/* 0x1f3: add    rax,0x190 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 400ULL);
x86_l_1f9:
	/* 0x1f9: jmp    22b <event_exit_acct_process+0x22b> */
	X86_SIM_X86_JMP(0x1f9, 0x22b, x86_l_22b);
x86_l_1fb:
	/* 0x1fb: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1ff:
	/* 0x1ff: je     21d <event_exit_acct_process+0x21d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ff, 0x21d, x86_l_21d);
x86_l_201:
	/* 0x201: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_205:
	/* 0x205: je     225 <event_exit_acct_process+0x225> */
	X86_SIM_X86_JCC(X86_CC_E, 0x205, 0x225, x86_l_225);
x86_l_207:
	/* 0x207: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_20b:
	/* 0x20b: je     1f3 <event_exit_acct_process+0x1f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20b, 0x1f3, x86_l_1f3);
x86_l_20d:
	/* 0x20d: add    rax,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_213:
	/* 0x213: jmp    22b <event_exit_acct_process+0x22b> */
	X86_SIM_X86_JMP(0x213, 0x22b, x86_l_22b);
x86_l_215:
	/* 0x215: add    rax,0x1b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 432ULL);
x86_l_21b:
	/* 0x21b: jmp    22b <event_exit_acct_process+0x22b> */
	X86_SIM_X86_JMP(0x21b, 0x22b, x86_l_22b);
x86_l_21d:
	/* 0x21d: add    rax,0x1b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 440ULL);
x86_l_223:
	/* 0x223: jmp    22b <event_exit_acct_process+0x22b> */
	X86_SIM_X86_JMP(0x223, 0x22b, x86_l_22b);
x86_l_225:
	/* 0x225: add    rax,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_22b:
	/* 0x22b: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_22f:
	/* 0x22f: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_234:
	/* 0x234: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_23b:
	/* 0x23b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240:
	/* 0x240: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_249:
	/* 0x249: je     270 <event_exit_acct_process+0x270> */
	X86_SIM_X86_JCC(X86_CC_E, 0x249, 0x270, x86_l_270);
x86_l_24b:
	/* 0x24b: mov    DWORD PTR [rsp+0x4],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_253:
	/* 0x253: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_25a:
	/* 0x25a: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25f:
	/* 0x25f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_264:
	/* 0x264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266:
	/* 0x266: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_269:
	/* 0x269: je     293 <event_exit_acct_process+0x293> */
	X86_SIM_X86_JCC(X86_CC_E, 0x269, 0x293, x86_l_293);
x86_l_26b:
	/* 0x26b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_26e:
	/* 0x26e: jmp    293 <event_exit_acct_process+0x293> */
	X86_SIM_X86_JMP(0x26e, 0x293, x86_l_293);
x86_l_270:
	/* 0x270: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_278:
	/* 0x278: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_27f:
	/* 0x27f: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_284:
	/* 0x284: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_289:
	/* 0x289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b:
	/* 0x28b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: je     293 <event_exit_acct_process+0x293> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28e, 0x293, x86_l_293);
x86_l_290:
	/* 0x290: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_293:
	/* 0x293: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_29a:
	/* 0x29a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_29f:
	/* 0x29f: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a6:
	/* 0x2a6: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2aa:
	/* 0x2aa: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2ac:
	/* 0x2ac: jmp    2b1 <event_exit_acct_process+0x2b1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2b1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
