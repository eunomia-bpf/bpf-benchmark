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
int tetragon_bpf_exit_v511_event_exit_disassociate_ctty_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: cmp    DWORD PTR [rdi+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4:
	/* 0x4: je     2a9 <event_exit_disassociate_ctty+0x2a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4, 0x2a9, x86_l_2a9);
x86_l_a:
	/* 0xa: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_c:
	/* 0xc: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_e:
	/* 0xe: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_10:
	/* 0x10: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_12:
	/* 0x12: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_13:
	/* 0x13: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_17:
	/* 0x17: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1a:
	/* 0x1a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1f:
	/* 0x1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21:
	/* 0x21: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_24:
	/* 0x24: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_28:
	/* 0x28: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d:
	/* 0x2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32:
	/* 0x32: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_39:
	/* 0x39: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: je     29c <event_exit_disassociate_ctty+0x29c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43, 0x29c, x86_l_29c);
x86_l_49:
	/* 0x49: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4c:
	/* 0x4c: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_51:
	/* 0x51: je     227 <event_exit_disassociate_ctty+0x227> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51, 0x227, x86_l_227);
x86_l_57:
	/* 0x57: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_5c:
	/* 0x5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e:
	/* 0x5e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_61:
	/* 0x61: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_69:
	/* 0x69: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e:
	/* 0x6e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exit_heap_map)));
x86_l_75:
	/* 0x75: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_7a:
	/* 0x7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c:
	/* 0x7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: je     29c <event_exit_disassociate_ctty+0x29c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f, 0x29c, x86_l_29c);
x86_l_85:
	/* 0x85: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_88:
	/* 0x88: movabs rax,0x2800000007 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 171798691847ULL);
x86_l_92:
	/* 0x92: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96:
	/* 0x96: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_9b:
	/* 0x9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [r12+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7:
	/* 0xa7: mov    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_b0:
	/* 0xb0: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4:
	/* 0xb4: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b9:
	/* 0xb9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bc:
	/* 0xbc: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c0:
	/* 0xc0: mov    DWORD PTR [r12+0x24],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c5:
	/* 0xc5: add    r13,0xa6c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2668ULL);
x86_l_cc:
	/* 0xcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d1:
	/* 0xd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d6:
	/* 0xd6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d9:
	/* 0xd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db:
	/* 0xdb: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e3:
	/* 0xe3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8:
	/* 0xe8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_ef:
	/* 0xef: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4:
	/* 0xf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6:
	/* 0xf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: je     175 <event_exit_disassociate_ctty+0x175> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9, 0x175, x86_l_175);
x86_l_fb:
	/* 0xfb: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ff:
	/* 0xff: je     175 <event_exit_disassociate_ctty+0x175> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff, 0x175, x86_l_175);
x86_l_101:
	/* 0x101: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_106:
	/* 0x106: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_10d:
	/* 0x10d: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_112:
	/* 0x112: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_118:
	/* 0x118: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120:
	/* 0x120: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_123:
	/* 0x123: jns    227 <event_exit_disassociate_ctty+0x227> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x123, 0x227, x86_l_227);
x86_l_129:
	/* 0x129: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_134:
	/* 0x134: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_139:
	/* 0x139: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_140:
	/* 0x140: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_145:
	/* 0x145: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147:
	/* 0x147: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a:
	/* 0x14a: je     227 <event_exit_disassociate_ctty+0x227> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a, 0x227, x86_l_227);
x86_l_150:
	/* 0x150: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_154:
	/* 0x154: jg     1f3 <event_exit_disassociate_ctty+0x1f3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x154, 0x1f3, x86_l_1f3);
x86_l_15a:
	/* 0x15a: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_15e:
	/* 0x15e: je     20d <event_exit_disassociate_ctty+0x20d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15e, 0x20d, x86_l_20d);
x86_l_164:
	/* 0x164: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_168:
	/* 0x168: jne    1cb <event_exit_disassociate_ctty+0x1cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x168, 0x1cb, x86_l_1cb);
x86_l_16a:
	/* 0x16a: add    rax,0x1a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 424ULL);
x86_l_170:
	/* 0x170: jmp    223 <event_exit_disassociate_ctty+0x223> */
	X86_SIM_X86_JMP(0x170, 0x223, x86_l_223);
x86_l_175:
	/* 0x175: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_17a:
	/* 0x17a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_181:
	/* 0x181: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_186:
	/* 0x186: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_189:
	/* 0x189: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b:
	/* 0x18b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d:
	/* 0x18d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_190:
	/* 0x190: jns    227 <event_exit_disassociate_ctty+0x227> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x190, 0x227, x86_l_227);
x86_l_196:
	/* 0x196: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_199:
	/* 0x199: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1a1:
	/* 0x1a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a6:
	/* 0x1a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_1ad:
	/* 0x1ad: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b2:
	/* 0x1b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4:
	/* 0x1b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b7:
	/* 0x1b7: je     227 <event_exit_disassociate_ctty+0x227> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b7, 0x227, x86_l_227);
x86_l_1b9:
	/* 0x1b9: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1bd:
	/* 0x1bd: jg     1d9 <event_exit_disassociate_ctty+0x1d9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1bd, 0x1d9, x86_l_1d9);
x86_l_1bf:
	/* 0x1bf: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1c3:
	/* 0x1c3: je     20d <event_exit_disassociate_ctty+0x20d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c3, 0x20d, x86_l_20d);
x86_l_1c5:
	/* 0x1c5: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1c9:
	/* 0x1c9: je     16a <event_exit_disassociate_ctty+0x16a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c9, 0x16a, x86_l_16a);
x86_l_1cb:
	/* 0x1cb: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_1cf:
	/* 0x1cf: jne    205 <event_exit_disassociate_ctty+0x205> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cf, 0x205, x86_l_205);
x86_l_1d1:
	/* 0x1d1: add    rax,0x1a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 416ULL);
x86_l_1d7:
	/* 0x1d7: jmp    223 <event_exit_disassociate_ctty+0x223> */
	X86_SIM_X86_JMP(0x1d7, 0x223, x86_l_223);
x86_l_1d9:
	/* 0x1d9: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1dd:
	/* 0x1dd: je     215 <event_exit_disassociate_ctty+0x215> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dd, 0x215, x86_l_215);
x86_l_1df:
	/* 0x1df: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1e3:
	/* 0x1e3: je     21d <event_exit_disassociate_ctty+0x21d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e3, 0x21d, x86_l_21d);
x86_l_1e5:
	/* 0x1e5: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1e9:
	/* 0x1e9: jne    205 <event_exit_disassociate_ctty+0x205> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e9, 0x205, x86_l_205);
x86_l_1eb:
	/* 0x1eb: add    rax,0x190 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 400ULL);
x86_l_1f1:
	/* 0x1f1: jmp    223 <event_exit_disassociate_ctty+0x223> */
	X86_SIM_X86_JMP(0x1f1, 0x223, x86_l_223);
x86_l_1f3:
	/* 0x1f3: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1f7:
	/* 0x1f7: je     215 <event_exit_disassociate_ctty+0x215> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f7, 0x215, x86_l_215);
x86_l_1f9:
	/* 0x1f9: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1fd:
	/* 0x1fd: je     21d <event_exit_disassociate_ctty+0x21d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fd, 0x21d, x86_l_21d);
x86_l_1ff:
	/* 0x1ff: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_203:
	/* 0x203: je     1eb <event_exit_disassociate_ctty+0x1eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x203, 0x1eb, x86_l_1eb);
x86_l_205:
	/* 0x205: add    rax,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_20b:
	/* 0x20b: jmp    223 <event_exit_disassociate_ctty+0x223> */
	X86_SIM_X86_JMP(0x20b, 0x223, x86_l_223);
x86_l_20d:
	/* 0x20d: add    rax,0x1b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 432ULL);
x86_l_213:
	/* 0x213: jmp    223 <event_exit_disassociate_ctty+0x223> */
	X86_SIM_X86_JMP(0x213, 0x223, x86_l_223);
x86_l_215:
	/* 0x215: add    rax,0x1b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 440ULL);
x86_l_21b:
	/* 0x21b: jmp    223 <event_exit_disassociate_ctty+0x223> */
	X86_SIM_X86_JMP(0x21b, 0x223, x86_l_223);
x86_l_21d:
	/* 0x21d: add    rax,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_223:
	/* 0x223: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_227:
	/* 0x227: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c:
	/* 0x22c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_231:
	/* 0x231: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_238:
	/* 0x238: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d:
	/* 0x23d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f:
	/* 0x23f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241:
	/* 0x241: je     268 <event_exit_disassociate_ctty+0x268> */
	X86_SIM_X86_JCC(X86_CC_E, 0x241, 0x268, x86_l_268);
x86_l_243:
	/* 0x243: mov    DWORD PTR [rsp+0x4],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_24b:
	/* 0x24b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_250:
	/* 0x250: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_257:
	/* 0x257: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25c:
	/* 0x25c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e:
	/* 0x25e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_261:
	/* 0x261: je     28b <event_exit_disassociate_ctty+0x28b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x261, 0x28b, x86_l_28b);
x86_l_263:
	/* 0x263: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_266:
	/* 0x266: jmp    28b <event_exit_disassociate_ctty+0x28b> */
	X86_SIM_X86_JMP(0x266, 0x28b, x86_l_28b);
x86_l_268:
	/* 0x268: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_270:
	/* 0x270: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_275:
	/* 0x275: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_27c:
	/* 0x27c: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_281:
	/* 0x281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283:
	/* 0x283: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_286:
	/* 0x286: je     28b <event_exit_disassociate_ctty+0x28b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x286, 0x28b, x86_l_28b);
x86_l_288:
	/* 0x288: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_28b:
	/* 0x28b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_290:
	/* 0x290: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_297:
	/* 0x297: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_29a:
	/* 0x29a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c:
	/* 0x29c: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a0:
	/* 0x2a0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2a1:
	/* 0x2a1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2a3:
	/* 0x2a3: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2a5:
	/* 0x2a5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2a9:
	/* 0x2a9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ab:
	/* 0x2ab: jmp    2b0 <event_exit_disassociate_ctty+0x2b0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2b0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
