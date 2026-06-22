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
	/* 0x1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21:
	/* 0x21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_28:
	/* 0x28: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d:
	/* 0x2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f:
	/* 0x2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: je     28b <event_exit_acct_process+0x28b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32, 0x28b, x86_l_28b);
x86_l_38:
	/* 0x38: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_40:
	/* 0x40: je     216 <event_exit_acct_process+0x216> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40, 0x216, x86_l_216);
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
	/* 0x58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d:
	/* 0x5d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exit_heap_map)));
x86_l_64:
	/* 0x64: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_69:
	/* 0x69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b:
	/* 0x6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: je     28b <event_exit_acct_process+0x28b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0x28b, x86_l_28b);
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
	/* 0xbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c0:
	/* 0xc0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c5:
	/* 0xc5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c8:
	/* 0xc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca:
	/* 0xca: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d2:
	/* 0xd2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d7:
	/* 0xd7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_de:
	/* 0xde: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3:
	/* 0xe3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5:
	/* 0xe5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e8:
	/* 0xe8: je     164 <event_exit_acct_process+0x164> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe8, 0x164, x86_l_164);
x86_l_ea:
	/* 0xea: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ee:
	/* 0xee: je     164 <event_exit_acct_process+0x164> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee, 0x164, x86_l_164);
x86_l_f0:
	/* 0xf0: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_f5:
	/* 0xf5: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_fc:
	/* 0xfc: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_101:
	/* 0x101: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_107:
	/* 0x107: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10a:
	/* 0x10a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_10d:
	/* 0x10d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f:
	/* 0x10f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112:
	/* 0x112: jns    216 <event_exit_acct_process+0x216> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x112, 0x216, x86_l_216);
x86_l_118:
	/* 0x118: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_123:
	/* 0x123: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_128:
	/* 0x128: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_12f:
	/* 0x12f: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_134:
	/* 0x134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136:
	/* 0x136: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_139:
	/* 0x139: je     216 <event_exit_acct_process+0x216> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x216, x86_l_216);
x86_l_13f:
	/* 0x13f: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_143:
	/* 0x143: jg     1e2 <event_exit_acct_process+0x1e2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x143, 0x1e2, x86_l_1e2);
x86_l_149:
	/* 0x149: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_14d:
	/* 0x14d: je     1fc <event_exit_acct_process+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14d, 0x1fc, x86_l_1fc);
x86_l_153:
	/* 0x153: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_157:
	/* 0x157: jne    1ba <event_exit_acct_process+0x1ba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x157, 0x1ba, x86_l_1ba);
x86_l_159:
	/* 0x159: add    rax,0x1a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 424ULL);
x86_l_15f:
	/* 0x15f: jmp    212 <event_exit_acct_process+0x212> */
	X86_SIM_X86_JMP(0x15f, 0x212, x86_l_212);
x86_l_164:
	/* 0x164: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_169:
	/* 0x169: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_170:
	/* 0x170: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_175:
	/* 0x175: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_178:
	/* 0x178: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a:
	/* 0x17a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c:
	/* 0x17c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f:
	/* 0x17f: jns    216 <event_exit_acct_process+0x216> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x17f, 0x216, x86_l_216);
x86_l_185:
	/* 0x185: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_188:
	/* 0x188: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_190:
	/* 0x190: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_195:
	/* 0x195: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_19c:
	/* 0x19c: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a1:
	/* 0x1a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3:
	/* 0x1a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a6:
	/* 0x1a6: je     216 <event_exit_acct_process+0x216> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6, 0x216, x86_l_216);
x86_l_1a8:
	/* 0x1a8: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1ac:
	/* 0x1ac: jg     1c8 <event_exit_acct_process+0x1c8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1ac, 0x1c8, x86_l_1c8);
x86_l_1ae:
	/* 0x1ae: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1b2:
	/* 0x1b2: je     1fc <event_exit_acct_process+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b2, 0x1fc, x86_l_1fc);
x86_l_1b4:
	/* 0x1b4: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1b8:
	/* 0x1b8: je     159 <event_exit_acct_process+0x159> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b8, 0x159, x86_l_159);
x86_l_1ba:
	/* 0x1ba: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_1be:
	/* 0x1be: jne    1f4 <event_exit_acct_process+0x1f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1be, 0x1f4, x86_l_1f4);
x86_l_1c0:
	/* 0x1c0: add    rax,0x1a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 416ULL);
x86_l_1c6:
	/* 0x1c6: jmp    212 <event_exit_acct_process+0x212> */
	X86_SIM_X86_JMP(0x1c6, 0x212, x86_l_212);
x86_l_1c8:
	/* 0x1c8: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1cc:
	/* 0x1cc: je     204 <event_exit_acct_process+0x204> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cc, 0x204, x86_l_204);
x86_l_1ce:
	/* 0x1ce: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1d2:
	/* 0x1d2: je     20c <event_exit_acct_process+0x20c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d2, 0x20c, x86_l_20c);
x86_l_1d4:
	/* 0x1d4: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1d8:
	/* 0x1d8: jne    1f4 <event_exit_acct_process+0x1f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d8, 0x1f4, x86_l_1f4);
x86_l_1da:
	/* 0x1da: add    rax,0x190 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 400ULL);
x86_l_1e0:
	/* 0x1e0: jmp    212 <event_exit_acct_process+0x212> */
	X86_SIM_X86_JMP(0x1e0, 0x212, x86_l_212);
x86_l_1e2:
	/* 0x1e2: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1e6:
	/* 0x1e6: je     204 <event_exit_acct_process+0x204> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e6, 0x204, x86_l_204);
x86_l_1e8:
	/* 0x1e8: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1ec:
	/* 0x1ec: je     20c <event_exit_acct_process+0x20c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ec, 0x20c, x86_l_20c);
x86_l_1ee:
	/* 0x1ee: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1f2:
	/* 0x1f2: je     1da <event_exit_acct_process+0x1da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2, 0x1da, x86_l_1da);
x86_l_1f4:
	/* 0x1f4: add    rax,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_1fa:
	/* 0x1fa: jmp    212 <event_exit_acct_process+0x212> */
	X86_SIM_X86_JMP(0x1fa, 0x212, x86_l_212);
x86_l_1fc:
	/* 0x1fc: add    rax,0x1b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 432ULL);
x86_l_202:
	/* 0x202: jmp    212 <event_exit_acct_process+0x212> */
	X86_SIM_X86_JMP(0x202, 0x212, x86_l_212);
x86_l_204:
	/* 0x204: add    rax,0x1b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 440ULL);
x86_l_20a:
	/* 0x20a: jmp    212 <event_exit_acct_process+0x212> */
	X86_SIM_X86_JMP(0x20a, 0x212, x86_l_212);
x86_l_20c:
	/* 0x20c: add    rax,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_212:
	/* 0x212: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_216:
	/* 0x216: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b:
	/* 0x21b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_220:
	/* 0x220: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_227:
	/* 0x227: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c:
	/* 0x22c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e:
	/* 0x22e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_230:
	/* 0x230: je     257 <event_exit_acct_process+0x257> */
	X86_SIM_X86_JCC(X86_CC_E, 0x230, 0x257, x86_l_257);
x86_l_232:
	/* 0x232: mov    DWORD PTR [rsp+0x4],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_23a:
	/* 0x23a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23f:
	/* 0x23f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_246:
	/* 0x246: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24b:
	/* 0x24b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d:
	/* 0x24d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_250:
	/* 0x250: je     27a <event_exit_acct_process+0x27a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x250, 0x27a, x86_l_27a);
x86_l_252:
	/* 0x252: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_255:
	/* 0x255: jmp    27a <event_exit_acct_process+0x27a> */
	X86_SIM_X86_JMP(0x255, 0x27a, x86_l_27a);
x86_l_257:
	/* 0x257: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_25f:
	/* 0x25f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_264:
	/* 0x264: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_26b:
	/* 0x26b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_270:
	/* 0x270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272:
	/* 0x272: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_275:
	/* 0x275: je     27a <event_exit_acct_process+0x27a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x275, 0x27a, x86_l_27a);
x86_l_277:
	/* 0x277: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_27a:
	/* 0x27a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_27f:
	/* 0x27f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_286:
	/* 0x286: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_289:
	/* 0x289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b:
	/* 0x28b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28d:
	/* 0x28d: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_291:
	/* 0x291: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_293:
	/* 0x293: jmp    298 <event_exit_acct_process+0x298> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_298:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
