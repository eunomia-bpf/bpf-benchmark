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
int tetragon_bpf_exit_event_exit_disassociate_ctty_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: cmp    DWORD PTR [rdi+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4:
	/* 0x4: je     215 <event_exit_disassociate_ctty+0x215> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4, 0x215, x86_l_215);
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
	/* 0x28: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d:
	/* 0x2d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_34:
	/* 0x34: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39:
	/* 0x39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: je     208 <event_exit_disassociate_ctty+0x208> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43, 0x208, x86_l_208);
x86_l_49:
	/* 0x49: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4c:
	/* 0x4c: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_51:
	/* 0x51: je     193 <event_exit_disassociate_ctty+0x193> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51, 0x193, x86_l_193);
x86_l_57:
	/* 0x57: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_5c:
	/* 0x5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e:
	/* 0x5e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_61:
	/* 0x61: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_69:
	/* 0x69: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exit_heap_map)));
x86_l_70:
	/* 0x70: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_75:
	/* 0x75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a:
	/* 0x7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c:
	/* 0x7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: je     208 <event_exit_disassociate_ctty+0x208> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f, 0x208, x86_l_208);
x86_l_85:
	/* 0x85: movabs rcx,0x2800000007 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 171798691847ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92:
	/* 0x92: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_95:
	/* 0x95: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_9a:
	/* 0x9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c:
	/* 0x9c: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0:
	/* 0xa0: mov    DWORD PTR [r13+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a4:
	/* 0xa4: mov    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_ac:
	/* 0xac: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0:
	/* 0xb0: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b4:
	/* 0xb4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_b7:
	/* 0xb7: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_bb:
	/* 0xbb: mov    DWORD PTR [r13+0x24],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bf:
	/* 0xbf: add    r12,0xa6c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2668ULL);
x86_l_c6:
	/* 0xc6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cb:
	/* 0xcb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d0:
	/* 0xd0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d5:
	/* 0xd5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d8:
	/* 0xd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da:
	/* 0xda: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_e1:
	/* 0xe1: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_e6:
	/* 0xe6: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_eb:
	/* 0xeb: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_f0:
	/* 0xf0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_f5:
	/* 0xf5: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_fb:
	/* 0xfb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_101:
	/* 0x101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103:
	/* 0x103: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106:
	/* 0x106: jns    193 <event_exit_disassociate_ctty+0x193> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x106, 0x193, x86_l_193);
x86_l_10c:
	/* 0x10c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_10f:
	/* 0x10f: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_117:
	/* 0x117: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_11e:
	/* 0x11e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_123:
	/* 0x123: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_128:
	/* 0x128: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a:
	/* 0x12a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12d:
	/* 0x12d: je     193 <event_exit_disassociate_ctty+0x193> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d, 0x193, x86_l_193);
x86_l_12f:
	/* 0x12f: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_133:
	/* 0x133: jg     14f <event_exit_disassociate_ctty+0x14f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x133, 0x14f, x86_l_14f);
x86_l_135:
	/* 0x135: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_139:
	/* 0x139: je     169 <event_exit_disassociate_ctty+0x169> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x169, x86_l_169);
x86_l_13b:
	/* 0x13b: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_13f:
	/* 0x13f: je     181 <event_exit_disassociate_ctty+0x181> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f, 0x181, x86_l_181);
x86_l_141:
	/* 0x141: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_145:
	/* 0x145: jne    179 <event_exit_disassociate_ctty+0x179> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x145, 0x179, x86_l_179);
x86_l_147:
	/* 0x147: add    rax,0x1a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 416ULL);
x86_l_14d:
	/* 0x14d: jmp    18f <event_exit_disassociate_ctty+0x18f> */
	X86_SIM_X86_JMP(0x14d, 0x18f, x86_l_18f);
x86_l_14f:
	/* 0x14f: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_153:
	/* 0x153: je     171 <event_exit_disassociate_ctty+0x171> */
	X86_SIM_X86_JCC(X86_CC_E, 0x153, 0x171, x86_l_171);
x86_l_155:
	/* 0x155: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_159:
	/* 0x159: je     189 <event_exit_disassociate_ctty+0x189> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159, 0x189, x86_l_189);
x86_l_15b:
	/* 0x15b: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_15f:
	/* 0x15f: jne    179 <event_exit_disassociate_ctty+0x179> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15f, 0x179, x86_l_179);
x86_l_161:
	/* 0x161: add    rax,0x190 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 400ULL);
x86_l_167:
	/* 0x167: jmp    18f <event_exit_disassociate_ctty+0x18f> */
	X86_SIM_X86_JMP(0x167, 0x18f, x86_l_18f);
x86_l_169:
	/* 0x169: add    rax,0x1b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 432ULL);
x86_l_16f:
	/* 0x16f: jmp    18f <event_exit_disassociate_ctty+0x18f> */
	X86_SIM_X86_JMP(0x16f, 0x18f, x86_l_18f);
x86_l_171:
	/* 0x171: add    rax,0x1b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 440ULL);
x86_l_177:
	/* 0x177: jmp    18f <event_exit_disassociate_ctty+0x18f> */
	X86_SIM_X86_JMP(0x177, 0x18f, x86_l_18f);
x86_l_179:
	/* 0x179: add    rax,0x188 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 392ULL);
x86_l_17f:
	/* 0x17f: jmp    18f <event_exit_disassociate_ctty+0x18f> */
	X86_SIM_X86_JMP(0x17f, 0x18f, x86_l_18f);
x86_l_181:
	/* 0x181: add    rax,0x1a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 424ULL);
x86_l_187:
	/* 0x187: jmp    18f <event_exit_disassociate_ctty+0x18f> */
	X86_SIM_X86_JMP(0x187, 0x18f, x86_l_18f);
x86_l_189:
	/* 0x189: add    rax,0x198 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 408ULL);
x86_l_18f:
	/* 0x18f: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_193:
	/* 0x193: mov    DWORD PTR [rsp+0xc],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_198:
	/* 0x198: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_19f:
	/* 0x19f: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a4:
	/* 0x1a4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1a9:
	/* 0x1a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab:
	/* 0x1ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ad:
	/* 0x1ad: je     1d4 <event_exit_disassociate_ctty+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x1d4, x86_l_1d4);
x86_l_1af:
	/* 0x1af: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_1b7:
	/* 0x1b7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_1be:
	/* 0x1be: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c3:
	/* 0x1c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: je     1f7 <event_exit_disassociate_ctty+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x1f7, x86_l_1f7);
x86_l_1cf:
	/* 0x1cf: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1d2:
	/* 0x1d2: jmp    1f7 <event_exit_disassociate_ctty+0x1f7> */
	X86_SIM_X86_JMP(0x1d2, 0x1f7, x86_l_1f7);
x86_l_1d4:
	/* 0x1d4: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1dc:
	/* 0x1dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map_stats)));
x86_l_1e3:
	/* 0x1e3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8:
	/* 0x1e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ed:
	/* 0x1ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef:
	/* 0x1ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f2:
	/* 0x1f2: je     1f7 <event_exit_disassociate_ctty+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2, 0x1f7, x86_l_1f7);
x86_l_1f4:
	/* 0x1f4: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_1f7:
	/* 0x1f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_parents_bin)));
x86_l_1fe:
	/* 0x1fe: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_203:
	/* 0x203: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_206:
	/* 0x206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208:
	/* 0x208: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20c:
	/* 0x20c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_20d:
	/* 0x20d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_20f:
	/* 0x20f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_211:
	/* 0x211: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_213:
	/* 0x213: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_215:
	/* 0x215: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_217:
	/* 0x217: jmp    21c <event_exit_disassociate_ctty+0x21c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_21c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
