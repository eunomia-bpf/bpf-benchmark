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
	/* 0x1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21:
	/* 0x21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_28:
	/* 0x28: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d:
	/* 0x2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f:
	/* 0x2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: je     1e8 <event_exit_acct_process+0x1e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32, 0x1e8, x86_l_1e8);
x86_l_38:
	/* 0x38: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_40:
	/* 0x40: je     173 <event_exit_acct_process+0x173> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40, 0x173, x86_l_173);
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
	/* 0x6e: je     1e8 <event_exit_acct_process+0x1e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0x1e8, x86_l_1e8);
x86_l_74:
	/* 0x74: movabs rcx,0x2800000007 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 171798691847ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81:
	/* 0x81: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_86:
	/* 0x86: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_89:
	/* 0x89: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
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
	/* 0xb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ba:
	/* 0xba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bf:
	/* 0xbf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c2:
	/* 0xc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4:
	/* 0xc4: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_c9:
	/* 0xc9: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_d0:
	/* 0xd0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_d5:
	/* 0xd5: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_db:
	/* 0xdb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_de:
	/* 0xde: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_e1:
	/* 0xe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3:
	/* 0xe3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e6:
	/* 0xe6: jns    173 <event_exit_acct_process+0x173> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe6, 0x173, x86_l_173);
x86_l_ec:
	/* 0xec: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_ef:
	/* 0xef: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f7:
	/* 0xf7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc:
	/* 0xfc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_103:
	/* 0x103: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_108:
	/* 0x108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a:
	/* 0x10a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d:
	/* 0x10d: je     173 <event_exit_acct_process+0x173> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d, 0x173, x86_l_173);
x86_l_10f:
	/* 0x10f: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_113:
	/* 0x113: jg     12f <event_exit_acct_process+0x12f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x113, 0x12f, x86_l_12f);
x86_l_115:
	/* 0x115: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_119:
	/* 0x119: je     149 <event_exit_acct_process+0x149> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119, 0x149, x86_l_149);
x86_l_11b:
	/* 0x11b: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_11f:
	/* 0x11f: je     161 <event_exit_acct_process+0x161> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f, 0x161, x86_l_161);
x86_l_121:
	/* 0x121: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_125:
	/* 0x125: jne    159 <event_exit_acct_process+0x159> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x125, 0x159, x86_l_159);
x86_l_127:
	/* 0x127: add    rax,0x1a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 416ULL);
x86_l_12d:
	/* 0x12d: jmp    16f <event_exit_acct_process+0x16f> */
	X86_SIM_X86_JMP(0x12d, 0x16f, x86_l_16f);
x86_l_12f:
	/* 0x12f: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_133:
	/* 0x133: je     151 <event_exit_acct_process+0x151> */
	X86_SIM_X86_JCC(X86_CC_E, 0x133, 0x151, x86_l_151);
x86_l_135:
	/* 0x135: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_139:
	/* 0x139: je     169 <event_exit_acct_process+0x169> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x169, x86_l_169);
x86_l_13b:
	/* 0x13b: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_13f:
	/* 0x13f: jne    159 <event_exit_acct_process+0x159> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13f, 0x159, x86_l_159);
x86_l_141:
	/* 0x141: add    rax,0x190 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 400ULL);
x86_l_147:
	/* 0x147: jmp    16f <event_exit_acct_process+0x16f> */
	X86_SIM_X86_JMP(0x147, 0x16f, x86_l_16f);
x86_l_149:
	/* 0x149: add    rax,0x1b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 432ULL);
x86_l_14f:
	/* 0x14f: jmp    16f <event_exit_acct_process+0x16f> */
	X86_SIM_X86_JMP(0x14f, 0x16f, x86_l_16f);
x86_l_151:
	/* 0x151: add    rax,0x1b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 440ULL);
x86_l_157:
	/* 0x157: jmp    16f <event_exit_acct_process+0x16f> */
	X86_SIM_X86_JMP(0x157, 0x16f, x86_l_16f);
x86_l_159:
	/* 0x159: add    rax,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_15f:
	/* 0x15f: jmp    16f <event_exit_acct_process+0x16f> */
	X86_SIM_X86_JMP(0x15f, 0x16f, x86_l_16f);
x86_l_161:
	/* 0x161: add    rax,0x1a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 424ULL);
x86_l_167:
	/* 0x167: jmp    16f <event_exit_acct_process+0x16f> */
	X86_SIM_X86_JMP(0x167, 0x16f, x86_l_16f);
x86_l_169:
	/* 0x169: add    rax,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_16f:
	/* 0x16f: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_173:
	/* 0x173: mov    DWORD PTR [rsp+0xc],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_178:
	/* 0x178: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17d:
	/* 0x17d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_184:
	/* 0x184: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_189:
	/* 0x189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b:
	/* 0x18b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18d:
	/* 0x18d: je     1b4 <event_exit_acct_process+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18d, 0x1b4, x86_l_1b4);
x86_l_18f:
	/* 0x18f: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_197:
	/* 0x197: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c:
	/* 0x19c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_1a3:
	/* 0x1a3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8:
	/* 0x1a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa:
	/* 0x1aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: je     1d7 <event_exit_acct_process+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x1d7, x86_l_1d7);
x86_l_1af:
	/* 0x1af: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b2:
	/* 0x1b2: jmp    1d7 <event_exit_acct_process+0x1d7> */
	X86_SIM_X86_JMP(0x1b2, 0x1d7, x86_l_1d7);
x86_l_1b4:
	/* 0x1b4: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1bc:
	/* 0x1bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c1:
	/* 0x1c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_1c8:
	/* 0x1c8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd:
	/* 0x1cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf:
	/* 0x1cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d2:
	/* 0x1d2: je     1d7 <event_exit_acct_process+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d2, 0x1d7, x86_l_1d7);
x86_l_1d4:
	/* 0x1d4: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_1d7:
	/* 0x1d7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1dc:
	/* 0x1dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_1e3:
	/* 0x1e3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1e6:
	/* 0x1e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8:
	/* 0x1e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea:
	/* 0x1ea: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ee:
	/* 0x1ee: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: jmp    1f5 <event_exit_acct_process+0x1f5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1f5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
