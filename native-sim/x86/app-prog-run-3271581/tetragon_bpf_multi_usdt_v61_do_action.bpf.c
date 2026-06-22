extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char heap;
extern char heap_ro_zero;
extern char policy_stats;
extern char process_call_heap;
extern char ratelimit_heap;
extern char ratelimit_map;
extern char socktrack_map;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char write_offload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_usdt_v61_do_action_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xe: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16:
	/* 0x16: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_19:
	/* 0x19: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_1c:
	/* 0x1c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1f:
	/* 0x1f: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_21:
	/* 0x21: movsxd r12,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_26:
	/* 0x26: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_2e:
	/* 0x2e: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_35:
	/* 0x35: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_3a:
	/* 0x3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f:
	/* 0x3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41:
	/* 0x41: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_44:
	/* 0x44: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46:
	/* 0x46: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_49:
	/* 0x49: je     a13 <do_action+0xa13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49, 0xa13, x86_l_a13);
x86_l_4f:
	/* 0x4f: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_53:
	/* 0x53: jg     7d <do_action+0x7d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x53, 0x7d, x86_l_7d);
x86_l_55:
	/* 0x55: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_59:
	/* 0x59: jg     b9 <do_action+0xb9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x59, 0xb9, x86_l_b9);
x86_l_5b:
	/* 0x5b: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5f:
	/* 0x5f: jg     2ce <do_action+0x2ce> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5f, 0x2ce, x86_l_2ce);
x86_l_65:
	/* 0x65: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_68:
	/* 0x68: je     554 <do_action+0x554> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0x554, x86_l_554);
x86_l_6e:
	/* 0x6e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_72:
	/* 0x72: je     2e7 <do_action+0x2e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72, 0x2e7, x86_l_2e7);
x86_l_78:
	/* 0x78: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x78, 0xa09, x86_l_a09);
x86_l_7d:
	/* 0x7d: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_81:
	/* 0x81: jg     1be <do_action+0x1be> */
	X86_SIM_X86_JCC(X86_CC_G, 0x81, 0x1be, x86_l_1be);
x86_l_87:
	/* 0x87: lea    ecx,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_8c:
	/* 0x8c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8f:
	/* 0x8f: jb     3f2 <do_action+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8f, 0x3f2, x86_l_3f2);
x86_l_95:
	/* 0x95: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_99:
	/* 0x99: je     4bc <do_action+0x4bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99, 0x4bc, x86_l_4bc);
x86_l_9f:
	/* 0x9f: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_a3:
	/* 0xa3: jne    a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3, 0xa09, x86_l_a09);
x86_l_a9:
	/* 0xa9: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_ac:
	/* 0xac: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_af:
	/* 0xaf: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_b4:
	/* 0xb4: jmp    612 <do_action+0x612> */
	X86_SIM_X86_JMP(0xb4, 0x612, x86_l_612);
x86_l_b9:
	/* 0xb9: lea    eax,[r12-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_be:
	/* 0xbe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c1:
	/* 0xc1: jb     4ab <do_action+0x4ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc1, 0x4ab, x86_l_4ab);
x86_l_c7:
	/* 0xc7: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_cb:
	/* 0xcb: je     4c9 <do_action+0x4c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb, 0x4c9, x86_l_4c9);
x86_l_d1:
	/* 0xd1: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_d5:
	/* 0xd5: jne    a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd5, 0xa09, x86_l_a09);
x86_l_db:
	/* 0xdb: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_df:
	/* 0xdf: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_e4:
	/* 0xe4: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_e8:
	/* 0xe8: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_eb:
	/* 0xeb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ee:
	/* 0xee: ja     a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_A, 0xee, 0xa09, x86_l_a09);
x86_l_f4:
	/* 0xf4: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_fd:
	/* 0xfd: jne    a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd, 0xa09, x86_l_a09);
x86_l_103:
	/* 0x103: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_108:
	/* 0x108: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_110:
	/* 0x110: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_118:
	/* 0x118: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_11d:
	/* 0x11d: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_125:
	/* 0x125: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_129:
	/* 0x129: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_12e:
	/* 0x12e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130:
	/* 0x130: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_134:
	/* 0x134: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138:
	/* 0x138: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_13f:
	/* 0x13f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_142:
	/* 0x142: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147:
	/* 0x147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149:
	/* 0x149: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14c:
	/* 0x14c: je     a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c, 0xa09, x86_l_a09);
x86_l_152:
	/* 0x152: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_155:
	/* 0x155: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_158:
	/* 0x158: ja     a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_A, 0x158, 0xa09, x86_l_a09);
x86_l_15e:
	/* 0x15e: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_167:
	/* 0x167: jne    a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x167, 0xa09, x86_l_a09);
x86_l_16d:
	/* 0x16d: mov    rcx,QWORD PTR [r13+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_175:
	/* 0x175: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_17d:
	/* 0x17d: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_183:
	/* 0x183: mov    ecx,DWORD PTR [r13+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_18b:
	/* 0x18b: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f:
	/* 0x18f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_197:
	/* 0x197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199:
	/* 0x199: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_19d:
	/* 0x19d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1:
	/* 0x1a1: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1a8:
	/* 0x1a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa:
	/* 0x1aa: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b2:
	/* 0x1b2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b5:
	/* 0x1b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7:
	/* 0x1b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9:
	/* 0x1b9: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x1b9, 0xa09, x86_l_a09);
x86_l_1be:
	/* 0x1be: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_1c2:
	/* 0x1c2: je     636 <do_action+0x636> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c2, 0x636, x86_l_636);
x86_l_1c8:
	/* 0x1c8: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_1cc:
	/* 0x1cc: je     4dc <do_action+0x4dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cc, 0x4dc, x86_l_4dc);
x86_l_1d2:
	/* 0x1d2: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_1d6:
	/* 0x1d6: jne    a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d6, 0xa09, x86_l_a09);
x86_l_1dc:
	/* 0x1dc: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e1:
	/* 0x1e1: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1e4:
	/* 0x1e4: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1e8:
	/* 0x1e8: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1ee:
	/* 0x1ee: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1f1:
	/* 0x1f1: je     64a <do_action+0x64a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f1, 0x64a, x86_l_64a);
x86_l_1f7:
	/* 0x1f7: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fb:
	/* 0x1fb: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_202:
	/* 0x202: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_205:
	/* 0x205: mov    r14d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_20a:
	/* 0x20a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_20d:
	/* 0x20d: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_214:
	/* 0x214: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_21b:
	/* 0x21b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_220:
	/* 0x220: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222:
	/* 0x222: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_228:
	/* 0x228: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22b:
	/* 0x22b: je     9df <do_action+0x9df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22b, 0x9df, x86_l_9df);
x86_l_231:
	/* 0x231: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_235:
	/* 0x235: lea    r14,[r14+r14*2] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 0ULL);
x86_l_239:
	/* 0x239: cmp    BYTE PTR [rax+r14*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 3), 2272037699587ULL);
x86_l_242:
	/* 0x242: jne    6b8 <do_action+0x6b8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x242, 0x6b8, x86_l_6b8);
x86_l_248:
	/* 0x248: mov    esi,DWORD PTR [rax+r14*8+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 3), 520ULL);
x86_l_250:
	/* 0x250: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_255:
	/* 0x255: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257:
	/* 0x257: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_25a:
	/* 0x25a: call   a26 <read_reg> */
	X86_SIM_X86_CALL(x86_l_a26, 0x25fULL);
x86_l_25f:
	/* 0x25f: add    rax,QWORD PTR [r15+r14*8+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_267:
	/* 0x267: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b:
	/* 0x26b: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f:
	/* 0x26f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_274:
	/* 0x274: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276:
	/* 0x276: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27b:
	/* 0x27b: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_282:
	/* 0x282: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_287:
	/* 0x287: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28c:
	/* 0x28c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e:
	/* 0x28e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_291:
	/* 0x291: je     939 <do_action+0x939> */
	X86_SIM_X86_JCC(X86_CC_E, 0x291, 0x939, x86_l_939);
x86_l_297:
	/* 0x297: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_29a:
	/* 0x29a: mov    DWORD PTR [rsp+0x10],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68720394257ULL);
x86_l_2a2:
	/* 0x2a2: mov    QWORD PTR [rsp+0x14],0x37a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85899346810ULL);
x86_l_2ab:
	/* 0x2ab: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2b2:
	/* 0x2b2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b7:
	/* 0x2b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bc:
	/* 0x2bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be:
	/* 0x2be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: je     9ab <do_action+0x9ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c1, 0x9ab, x86_l_9ab);
x86_l_2c7:
	/* 0x2c7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2c9:
	/* 0x2c9: jmp    9cf <do_action+0x9cf> */
	X86_SIM_X86_JMP(0x2c9, 0x9cf, x86_l_9cf);
x86_l_2ce:
	/* 0x2ce: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2d3:
	/* 0x2d3: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2d7:
	/* 0x2d7: je     60f <do_action+0x60f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d7, 0x60f, x86_l_60f);
x86_l_2dd:
	/* 0x2dd: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2e1:
	/* 0x2e1: jne    a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e1, 0xa09, x86_l_a09);
x86_l_2e7:
	/* 0x2e7: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2eb:
	/* 0x2eb: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_2f0:
	/* 0x2f0: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2f4:
	/* 0x2f4: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_2f9:
	/* 0x2f9: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_301:
	/* 0x301: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_308:
	/* 0x308: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30d:
	/* 0x30d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_312:
	/* 0x312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314:
	/* 0x314: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_317:
	/* 0x317: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31a:
	/* 0x31a: je     6e8 <do_action+0x6e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31a, 0x6e8, x86_l_6e8);
x86_l_320:
	/* 0x320: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_325:
	/* 0x325: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_328:
	/* 0x328: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_32b:
	/* 0x32b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_330:
	/* 0x330: ja     6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_A, 0x330, 0x6ea, x86_l_6ea);
x86_l_336:
	/* 0x336: cmp    DWORD PTR [r13+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_33f:
	/* 0x33f: jne    6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33f, 0x6ea, x86_l_6ea);
x86_l_345:
	/* 0x345: mov    rax,QWORD PTR [r13+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_34d:
	/* 0x34d: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_355:
	/* 0x355: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_35a:
	/* 0x35a: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_362:
	/* 0x362: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_366:
	/* 0x366: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_36b:
	/* 0x36b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d:
	/* 0x36d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_371:
	/* 0x371: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_375:
	/* 0x375: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_379:
	/* 0x379: jne    6c1 <do_action+0x6c1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x379, 0x6c1, x86_l_6c1);
x86_l_37f:
	/* 0x37f: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_382:
	/* 0x382: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_385:
	/* 0x385: ja     6e8 <do_action+0x6e8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x385, 0x6e8, x86_l_6e8);
x86_l_38b:
	/* 0x38b: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_394:
	/* 0x394: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_399:
	/* 0x399: jne    6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x399, 0x6ea, x86_l_6ea);
x86_l_39f:
	/* 0x39f: mov    rax,QWORD PTR [r13+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_3a7:
	/* 0x3a7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3ac:
	/* 0x3ac: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3b0:
	/* 0x3b0: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3b7:
	/* 0x3b7: mov    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_3bf:
	/* 0x3bf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3c5:
	/* 0x3c5: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c9:
	/* 0x3c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ce:
	/* 0x3ce: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d3:
	/* 0x3d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3d6:
	/* 0x3d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d8:
	/* 0x3d8: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_3df:
	/* 0x3df: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e2:
	/* 0x3e2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3e5:
	/* 0x3e5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ea:
	/* 0x3ea: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3ed:
	/* 0x3ed: jmp    4a2 <do_action+0x4a2> */
	X86_SIM_X86_JMP(0x3ed, 0x4a2, x86_l_4a2);
x86_l_3f2:
	/* 0x3f2: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f5:
	/* 0x3f5: mov    ecx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_3fa:
	/* 0x3fa: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3fd:
	/* 0x3fd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_403:
	/* 0x403: ja     6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_A, 0x403, 0x6ea, x86_l_6ea);
x86_l_409:
	/* 0x409: cmp    DWORD PTR [r13+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_412:
	/* 0x412: jne    6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x412, 0x6ea, x86_l_6ea);
x86_l_418:
	/* 0x418: mov    rcx,QWORD PTR [r13+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_420:
	/* 0x420: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_426:
	/* 0x426: mov    rcx,QWORD PTR [r13+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_42e:
	/* 0x42e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_433:
	/* 0x433: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_436:
	/* 0x436: je     6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x436, 0x6ea, x86_l_6ea);
x86_l_43c:
	/* 0x43c: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_440:
	/* 0x440: jne    6d2 <do_action+0x6d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x440, 0x6d2, x86_l_6d2);
x86_l_446:
	/* 0x446: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_44b:
	/* 0x44b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d:
	/* 0x44d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_450:
	/* 0x450: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_454:
	/* 0x454: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_457:
	/* 0x457: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_45e:
	/* 0x45e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_461:
	/* 0x461: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_466:
	/* 0x466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_468:
	/* 0x468: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_46b:
	/* 0x46b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46e:
	/* 0x46e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_473:
	/* 0x473: je     6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x473, 0x6ea, x86_l_6ea);
x86_l_479:
	/* 0x479: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47b:
	/* 0x47b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47e:
	/* 0x47e: mov    DWORD PTR [rsp+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_482:
	/* 0x482: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_486:
	/* 0x486: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48b:
	/* 0x48b: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_492:
	/* 0x492: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_495:
	/* 0x495: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49a:
	/* 0x49a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_49d:
	/* 0x49d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a2:
	/* 0x4a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a4:
	/* 0x4a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a6:
	/* 0x4a6: jmp    6e8 <do_action+0x6e8> */
	X86_SIM_X86_JMP(0x4a6, 0x6e8, x86_l_6e8);
x86_l_4ab:
	/* 0x4ab: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4ae:
	/* 0x4ae: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_4b3:
	/* 0x4b3: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4b7:
	/* 0x4b7: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x4b7, 0xa09, x86_l_a09);
x86_l_4bc:
	/* 0x4bc: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c1:
	/* 0x4c1: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c4:
	/* 0x4c4: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x4c4, 0xa09, x86_l_a09);
x86_l_4c9:
	/* 0x4c9: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_4cc:
	/* 0x4cc: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4cf:
	/* 0x4cf: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4d3:
	/* 0x4d3: xor    r13,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_4d7:
	/* 0x4d7: jmp    9e4 <do_action+0x9e4> */
	X86_SIM_X86_JMP(0x4d7, 0x9e4, x86_l_9e4);
x86_l_4dc:
	/* 0x4dc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4e1:
	/* 0x4e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4e8:
	/* 0x4e8: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4ef:
	/* 0x4ef: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f4:
	/* 0x4f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f9:
	/* 0x4f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fb:
	/* 0x4fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4fe:
	/* 0x4fe: je     a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4fe, 0xa09, x86_l_a09);
x86_l_504:
	/* 0x504: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_508:
	/* 0x508: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50d:
	/* 0x50d: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_515:
	/* 0x515: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_51c:
	/* 0x51c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_521:
	/* 0x521: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_526:
	/* 0x526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_528:
	/* 0x528: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_530:
	/* 0x530: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_533:
	/* 0x533: je     652 <do_action+0x652> */
	X86_SIM_X86_JCC(X86_CC_E, 0x533, 0x652, x86_l_652);
x86_l_539:
	/* 0x539: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_53c:
	/* 0x53c: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_543:
	/* 0x543: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_548:
	/* 0x548: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_54d:
	/* 0x54d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54f:
	/* 0x54f: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x54f, 0xa09, x86_l_a09);
x86_l_554:
	/* 0x554: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_559:
	/* 0x559: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_55d:
	/* 0x55d: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_562:
	/* 0x562: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_566:
	/* 0x566: mov    ebx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_56b:
	/* 0x56b: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_570:
	/* 0x570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572:
	/* 0x572: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_577:
	/* 0x577: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57b:
	/* 0x57b: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_583:
	/* 0x583: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_588:
	/* 0x588: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_58b:
	/* 0x58b: je     8ba <do_action+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58b, 0x8ba, x86_l_8ba);
x86_l_591:
	/* 0x591: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_598:
	/* 0x598: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59d:
	/* 0x59d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a2:
	/* 0x5a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a4:
	/* 0x5a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a7:
	/* 0x5a7: je     8ba <do_action+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a7, 0x8ba, x86_l_8ba);
x86_l_5ad:
	/* 0x5ad: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5b2:
	/* 0x5b2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5b5:
	/* 0x5b5: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5bc:
	/* 0x5bc: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c1:
	/* 0x5c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c6:
	/* 0x5c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c8:
	/* 0x5c8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5cb:
	/* 0x5cb: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d3:
	/* 0x5d3: mov    rax,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d7:
	/* 0x5d7: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5dc:
	/* 0x5dc: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e0:
	/* 0x5e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e2:
	/* 0x5e2: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5e7:
	/* 0x5e7: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5ec:
	/* 0x5ec: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5ef:
	/* 0x5ef: je     6fc <do_action+0x6fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ef, 0x6fc, x86_l_6fc);
x86_l_5f5:
	/* 0x5f5: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_5f8:
	/* 0x5f8: je     6f8 <do_action+0x6f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f8, 0x6f8, x86_l_6f8);
x86_l_5fe:
	/* 0x5fe: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_600:
	/* 0x600: jne    8ba <do_action+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x600, 0x8ba, x86_l_8ba);
x86_l_606:
	/* 0x606: mov    eax,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_60a:
	/* 0x60a: jmp    6fc <do_action+0x6fc> */
	X86_SIM_X86_JMP(0x60a, 0x6fc, x86_l_6fc);
x86_l_60f:
	/* 0x60f: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_612:
	/* 0x612: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_618:
	/* 0x618: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_61b:
	/* 0x61b: je     9e4 <do_action+0x9e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61b, 0x9e4, x86_l_9e4);
x86_l_621:
	/* 0x621: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_624:
	/* 0x624: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_631:
	/* 0x631: jmp    9e4 <do_action+0x9e4> */
	X86_SIM_X86_JMP(0x631, 0x9e4, x86_l_9e4);
x86_l_636:
	/* 0x636: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_639:
	/* 0x639: add    r14d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_63d:
	/* 0x63d: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_641:
	/* 0x641: xor    r13,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_645:
	/* 0x645: jmp    9e4 <do_action+0x9e4> */
	X86_SIM_X86_JMP(0x645, 0x9e4, x86_l_9e4);
x86_l_64a:
	/* 0x64a: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_64d:
	/* 0x64d: jmp    9e4 <do_action+0x9e4> */
	X86_SIM_X86_JMP(0x64d, 0x9e4, x86_l_9e4);
x86_l_652:
	/* 0x652: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_659:
	/* 0x659: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65e:
	/* 0x65e: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_663:
	/* 0x663: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_668:
	/* 0x668: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_66d:
	/* 0x66d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66f:
	/* 0x66f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_672:
	/* 0x672: je     53c <do_action+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x672, 0x53c, x86_l_53c);
x86_l_678:
	/* 0x678: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_67b:
	/* 0x67b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_67d:
	/* 0x67d: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_681:
	/* 0x681: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_688:
	/* 0x688: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_692:
	/* 0x692: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_697:
	/* 0x697: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_69e:
	/* 0x69e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6a1:
	/* 0x6a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a6:
	/* 0x6a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a8:
	/* 0x6a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ab:
	/* 0x6ab: je     958 <do_action+0x958> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ab, 0x958, x86_l_958);
x86_l_6b1:
	/* 0x6b1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6b3:
	/* 0x6b3: jmp    97a <do_action+0x97a> */
	X86_SIM_X86_JMP(0x6b3, 0x97a, x86_l_97a);
x86_l_6b8:
	/* 0x6b8: or     BYTE PTR [rbx+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_6bc:
	/* 0x6bc: jmp    9df <do_action+0x9df> */
	X86_SIM_X86_JMP(0x6bc, 0x9df, x86_l_9df);
x86_l_6c1:
	/* 0x6c1: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6c8:
	/* 0x6c8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6d0:
	/* 0x6d0: jmp    6e3 <do_action+0x6e3> */
	X86_SIM_X86_JMP(0x6d0, 0x6e3, x86_l_6e3);
x86_l_6d2:
	/* 0x6d2: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_6d9:
	/* 0x6d9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6de:
	/* 0x6de: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6e3:
	/* 0x6e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e5:
	/* 0x6e5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6e8:
	/* 0x6e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ea:
	/* 0x6ea: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_6ed:
	/* 0x6ed: jne    a13 <do_action+0xa13> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6ed, 0xa13, x86_l_a13);
x86_l_6f3:
	/* 0x6f3: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x6f3, 0xa09, x86_l_a09);
x86_l_6f8:
	/* 0x6f8: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fc:
	/* 0x6fc: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6fe:
	/* 0x6fe: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_703:
	/* 0x703: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_707:
	/* 0x707: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_70c:
	/* 0x70c: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_710:
	/* 0x710: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_715:
	/* 0x715: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_71a:
	/* 0x71a: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_71f:
	/* 0x71f: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_724:
	/* 0x724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_726:
	/* 0x726: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_728:
	/* 0x728: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_72d:
	/* 0x72d: jmp    73d <do_action+0x73d> */
	X86_SIM_X86_JMP(0x72d, 0x73d, x86_l_73d);
x86_l_72f:
	/* 0x72f: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_733:
	/* 0x733: cmp    rbx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 20ULL);
x86_l_737:
	/* 0x737: je     868 <do_action+0x868> */
	X86_SIM_X86_JCC(X86_CC_E, 0x737, 0x868, x86_l_868);
x86_l_73d:
	/* 0x73d: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_745:
	/* 0x745: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_74a:
	/* 0x74a: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_751:
	/* 0x751: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_756:
	/* 0x756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_758:
	/* 0x758: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75b:
	/* 0x75b: je     868 <do_action+0x868> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75b, 0x868, x86_l_868);
x86_l_761:
	/* 0x761: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_764:
	/* 0x764: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_76b:
	/* 0x76b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_770:
	/* 0x770: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_777:
	/* 0x777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_779:
	/* 0x779: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_77c:
	/* 0x77c: je     868 <do_action+0x868> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77c, 0x868, x86_l_868);
x86_l_782:
	/* 0x782: cmp    DWORD PTR [rax+rbx*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 279172874239ULL);
x86_l_787:
	/* 0x787: je     868 <do_action+0x868> */
	X86_SIM_X86_JCC(X86_CC_E, 0x787, 0x868, x86_l_868);
x86_l_78d:
	/* 0x78d: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_795:
	/* 0x795: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_799:
	/* 0x799: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_79c:
	/* 0x79c: jge    868 <do_action+0x868> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x79c, 0x868, x86_l_868);
x86_l_7a2:
	/* 0x7a2: cmp    rbx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 16ULL);
x86_l_7a6:
	/* 0x7a6: je     808 <do_action+0x808> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a6, 0x808, x86_l_808);
x86_l_7a8:
	/* 0x7a8: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_7b0:
	/* 0x7b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b5:
	/* 0x7b5: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7bc:
	/* 0x7bc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c1:
	/* 0x7c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c3:
	/* 0x7c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: je     800 <do_action+0x800> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c6, 0x800, x86_l_800);
x86_l_7c8:
	/* 0x7c8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7cb:
	/* 0x7cb: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_7d2:
	/* 0x7d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d7:
	/* 0x7d7: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_7de:
	/* 0x7de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e0:
	/* 0x7e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e3:
	/* 0x7e3: je     800 <do_action+0x800> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e3, 0x800, x86_l_800);
x86_l_7e5:
	/* 0x7e5: cmp    DWORD PTR [rax+rbx*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 296352743423ULL);
x86_l_7ea:
	/* 0x7ea: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_7f2:
	/* 0x7f2: je     808 <do_action+0x808> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f2, 0x808, x86_l_808);
x86_l_7f4:
	/* 0x7f4: mov    ebp,DWORD PTR [r13+rbx*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 1), 24192ULL);
x86_l_7fc:
	/* 0x7fc: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7fe:
	/* 0x7fe: jmp    811 <do_action+0x811> */
	X86_SIM_X86_JMP(0x7fe, 0x811, x86_l_811);
x86_l_800:
	/* 0x800: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_808:
	/* 0x808: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_80c:
	/* 0x80c: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_80e:
	/* 0x80e: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_811:
	/* 0x811: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_813:
	/* 0x813: jle    72f <do_action+0x72f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x813, 0x72f, x86_l_72f);
x86_l_819:
	/* 0x819: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_81e:
	/* 0x81e: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_823:
	/* 0x823: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_826:
	/* 0x826: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_82b:
	/* 0x82b: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_82e:
	/* 0x82e: movzx  r13d,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_834:
	/* 0x834: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_839:
	/* 0x839: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_83d:
	/* 0x83d: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_842:
	/* 0x842: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_846:
	/* 0x846: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_84d:
	/* 0x84d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_852:
	/* 0x852: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_854:
	/* 0x854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_856:
	/* 0x856: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_859:
	/* 0x859: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_85e:
	/* 0x85e: mov    QWORD PTR [rsp+0x60],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_863:
	/* 0x863: jmp    72f <do_action+0x72f> */
	X86_SIM_X86_JMP(0x863, 0x72f, x86_l_72f);
x86_l_868:
	/* 0x868: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_86f:
	/* 0x86f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_874:
	/* 0x874: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_879:
	/* 0x879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87b:
	/* 0x87b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_87e:
	/* 0x87e: je     8a0 <do_action+0x8a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x87e, 0x8a0, x86_l_8a0);
x86_l_880:
	/* 0x880: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_889:
	/* 0x889: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_88e:
	/* 0x88e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_891:
	/* 0x891: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_894:
	/* 0x894: jbe    8a0 <do_action+0x8a0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x894, 0x8a0, x86_l_8a0);
x86_l_896:
	/* 0x896: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_89b:
	/* 0x89b: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89e:
	/* 0x89e: jmp    8ba <do_action+0x8ba> */
	X86_SIM_X86_JMP(0x89e, 0x8ba, x86_l_8ba);
x86_l_8a0:
	/* 0x8a0: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_8a7:
	/* 0x8a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a9:
	/* 0x8a9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_8ac:
	/* 0x8ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8b1:
	/* 0x8b1: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8b6:
	/* 0x8b6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b8:
	/* 0x8b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ba:
	/* 0x8ba: lea    eax,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_8be:
	/* 0x8be: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8c4:
	/* 0x8c4: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8c9:
	/* 0x8c9: je     8ec <do_action+0x8ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c9, 0x8ec, x86_l_8ec);
x86_l_8cb:
	/* 0x8cb: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_8d0:
	/* 0x8d0: mov    rsi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8d7:
	/* 0x8d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d9:
	/* 0x8d9: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8de:
	/* 0x8de: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8e1:
	/* 0x8e1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e3:
	/* 0x8e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e5:
	/* 0x8e5: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8ec:
	/* 0x8ec: lea    eax,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8f0:
	/* 0x8f0: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8f6:
	/* 0x8f6: je     91f <do_action+0x91f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f6, 0x91f, x86_l_91f);
x86_l_8f8:
	/* 0x8f8: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_8fd:
	/* 0x8fd: mov    rsi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_904:
	/* 0x904: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_909:
	/* 0x909: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_90e:
	/* 0x90e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_913:
	/* 0x913: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_916:
	/* 0x916: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_918:
	/* 0x918: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_91f:
	/* 0x91f: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_923:
	/* 0x923: cmp    DWORD PTR [r15+r14*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 17179869184ULL);
x86_l_929:
	/* 0x929: je     a09 <do_action+0xa09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x929, 0xa09, x86_l_a09);
x86_l_92f:
	/* 0x92f: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_934:
	/* 0x934: jmp    a09 <do_action+0xa09> */
	X86_SIM_X86_JMP(0x934, 0xa09, x86_l_a09);
x86_l_939:
	/* 0x939: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_940:
	/* 0x940: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_942:
	/* 0x942: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_947:
	/* 0x947: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_94a:
	/* 0x94a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_94f:
	/* 0x94f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_951:
	/* 0x951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_953:
	/* 0x953: jmp    9df <do_action+0x9df> */
	X86_SIM_X86_JMP(0x953, 0x9df, x86_l_9df);
x86_l_958:
	/* 0x958: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_960:
	/* 0x960: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_967:
	/* 0x967: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_969:
	/* 0x969: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_96c:
	/* 0x96c: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_971:
	/* 0x971: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_976:
	/* 0x976: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_978:
	/* 0x978: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97a:
	/* 0x97a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_97d:
	/* 0x97d: je     53c <do_action+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97d, 0x53c, x86_l_53c);
x86_l_983:
	/* 0x983: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_98a:
	/* 0x98a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_98f:
	/* 0x98f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_994:
	/* 0x994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_996:
	/* 0x996: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_999:
	/* 0x999: je     53c <do_action+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x999, 0x53c, x86_l_53c);
x86_l_99f:
	/* 0x99f: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9a3:
	/* 0x9a3: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9a6:
	/* 0x9a6: jmp    53c <do_action+0x53c> */
	X86_SIM_X86_JMP(0x9a6, 0x53c, x86_l_53c);
x86_l_9ab:
	/* 0x9ab: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_9b3:
	/* 0x9b3: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9ba:
	/* 0x9ba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bc:
	/* 0x9bc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c1:
	/* 0x9c1: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c6:
	/* 0x9c6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9cb:
	/* 0x9cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9cd:
	/* 0x9cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cf:
	/* 0x9cf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d3:
	/* 0x9d3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d8:
	/* 0x9d8: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9dc:
	/* 0x9dc: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9df:
	/* 0x9df: mov    r14d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9e4:
	/* 0x9e4: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9eb:
	/* 0x9eb: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_9f2:
	/* 0x9f2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9f5:
	/* 0x9f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9fa:
	/* 0x9fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fc:
	/* 0x9fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ff:
	/* 0x9ff: je     a06 <do_action+0xa06> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ff, 0xa06, x86_l_a06);
x86_l_a01:
	/* 0xa01: inc QWORD PTR [rax+r13*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R13, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a06:
	/* 0xa06: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_a09:
	/* 0xa09: mov    QWORD PTR [r13+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a0d:
	/* 0xa0d: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a10:
	/* 0xa10: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a13:
	/* 0xa13: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_a17:
	/* 0xa17: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_a18:
	/* 0xa18: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_a1a:
	/* 0xa1a: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_a1c:
	/* 0xa1c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_a1e:
	/* 0xa1e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_a20:
	/* 0xa20: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_a21:
	/* 0xa21: jmp    b3c <read_reg+0x116> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b3c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_a26 */
x86_l_a26:
	/* 0xa26: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_a2c:
	/* 0xa2c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a2e:
	/* 0xa2e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_a31:
	/* 0xa31: jle    a68 <read_reg+0x42> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa31, 0xa68, x86_l_a68);
x86_l_a33:
	/* 0xa33: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_a36:
	/* 0xa36: jle    a8c <read_reg+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa36, 0xa8c, x86_l_a8c);
x86_l_a38:
	/* 0xa38: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_a3b:
	/* 0xa3b: jle    af1 <read_reg+0xcb> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa3b, 0xaf1, x86_l_af1);
x86_l_a41:
	/* 0xa41: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_a44:
	/* 0xa44: je     b25 <read_reg+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa44, 0xb25, x86_l_b25);
x86_l_a4a:
	/* 0xa4a: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a4d:
	/* 0xa4d: je     b0d <read_reg+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa4d, 0xb0d, x86_l_b0d);
x86_l_a53:
	/* 0xa53: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_a56:
	/* 0xa56: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa56, 0xb3b, x86_l_b3b);
x86_l_a5c:
	/* 0xa5c: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_a63:
	/* 0xa63: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa63, 0xb2f, x86_l_b2f);
x86_l_a68:
	/* 0xa68: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a6b:
	/* 0xa6b: jg     aa8 <read_reg+0x82> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa6b, 0xaa8, x86_l_aa8);
x86_l_a6d:
	/* 0xa6d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a70:
	/* 0xa70: jg     ad1 <read_reg+0xab> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa70, 0xad1, x86_l_ad1);
x86_l_a72:
	/* 0xa72: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_a74:
	/* 0xa74: je     b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa74, 0xb2f, x86_l_b2f);
x86_l_a7a:
	/* 0xa7a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a7d:
	/* 0xa7d: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa7d, 0xb3b, x86_l_b3b);
x86_l_a83:
	/* 0xa83: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a87:
	/* 0xa87: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa87, 0xb2f, x86_l_b2f);
x86_l_a8c:
	/* 0xa8c: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a8f:
	/* 0xa8f: jg     ac1 <read_reg+0x9b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa8f, 0xac1, x86_l_ac1);
x86_l_a91:
	/* 0xa91: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a94:
	/* 0xa94: je     b01 <read_reg+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa94, 0xb01, x86_l_b01);
x86_l_a96:
	/* 0xa96: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a99:
	/* 0xa99: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa99, 0xb3b, x86_l_b3b);
x86_l_a9f:
	/* 0xa9f: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_aa3:
	/* 0xaa3: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaa3, 0xb2f, x86_l_b2f);
x86_l_aa8:
	/* 0xaa8: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_aab:
	/* 0xaab: jg     ae1 <read_reg+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xaab, 0xae1, x86_l_ae1);
x86_l_aad:
	/* 0xaad: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ab0:
	/* 0xab0: je     b13 <read_reg+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xab0, 0xb13, x86_l_b13);
x86_l_ab2:
	/* 0xab2: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_ab5:
	/* 0xab5: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xab5, 0xb3b, x86_l_b3b);
x86_l_abb:
	/* 0xabb: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_abf:
	/* 0xabf: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xabf, 0xb2f, x86_l_b2f);
x86_l_ac1:
	/* 0xac1: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ac4:
	/* 0xac4: je     b07 <read_reg+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xac4, 0xb07, x86_l_b07);
x86_l_ac6:
	/* 0xac6: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ac9:
	/* 0xac9: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xac9, 0xb3b, x86_l_b3b);
x86_l_acb:
	/* 0xacb: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_acf:
	/* 0xacf: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xacf, 0xb2f, x86_l_b2f);
x86_l_ad1:
	/* 0xad1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ad4:
	/* 0xad4: je     b19 <read_reg+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xad4, 0xb19, x86_l_b19);
x86_l_ad6:
	/* 0xad6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ad9:
	/* 0xad9: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xad9, 0xb3b, x86_l_b3b);
x86_l_adb:
	/* 0xadb: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_adf:
	/* 0xadf: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xadf, 0xb2f, x86_l_b2f);
x86_l_ae1:
	/* 0xae1: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ae4:
	/* 0xae4: je     b1f <read_reg+0xf9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xae4, 0xb1f, x86_l_b1f);
x86_l_ae6:
	/* 0xae6: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ae9:
	/* 0xae9: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xae9, 0xb3b, x86_l_b3b);
x86_l_aeb:
	/* 0xaeb: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_aef:
	/* 0xaef: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaef, 0xb2f, x86_l_b2f);
x86_l_af1:
	/* 0xaf1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_af4:
	/* 0xaf4: je     b2b <read_reg+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaf4, 0xb2b, x86_l_b2b);
x86_l_af6:
	/* 0xaf6: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_af9:
	/* 0xaf9: jne    b3b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xaf9, 0xb3b, x86_l_b3b);
x86_l_afb:
	/* 0xafb: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_aff:
	/* 0xaff: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaff, 0xb2f, x86_l_b2f);
x86_l_b01:
	/* 0xb01: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_b05:
	/* 0xb05: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb05, 0xb2f, x86_l_b2f);
x86_l_b07:
	/* 0xb07: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_b0b:
	/* 0xb0b: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb0b, 0xb2f, x86_l_b2f);
x86_l_b0d:
	/* 0xb0d: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_b11:
	/* 0xb11: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb11, 0xb2f, x86_l_b2f);
x86_l_b13:
	/* 0xb13: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b17:
	/* 0xb17: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb17, 0xb2f, x86_l_b2f);
x86_l_b19:
	/* 0xb19: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b1d:
	/* 0xb1d: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb1d, 0xb2f, x86_l_b2f);
x86_l_b1f:
	/* 0xb1f: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b23:
	/* 0xb23: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb23, 0xb2f, x86_l_b2f);
x86_l_b25:
	/* 0xb25: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_b29:
	/* 0xb29: jmp    b2f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb29, 0xb2f, x86_l_b2f);
x86_l_b2b:
	/* 0xb2b: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_b2f:
	/* 0xb2f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_b34:
	/* 0xb34: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b36:
	/* 0xb36: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_b3b:
	/* 0xb3b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x41ULL: goto x86_l_41;
	case 0x130ULL: goto x86_l_130;
	case 0x149ULL: goto x86_l_149;
	case 0x199ULL: goto x86_l_199;
	case 0x1b9ULL: goto x86_l_1b9;
	case 0x222ULL: goto x86_l_222;
	case 0x25fULL: goto x86_l_25f;
	case 0x276ULL: goto x86_l_276;
	case 0x28eULL: goto x86_l_28e;
	case 0x2beULL: goto x86_l_2be;
	case 0x314ULL: goto x86_l_314;
	case 0x36dULL: goto x86_l_36d;
	case 0x3d8ULL: goto x86_l_3d8;
	case 0x44dULL: goto x86_l_44d;
	case 0x468ULL: goto x86_l_468;
	case 0x4a6ULL: goto x86_l_4a6;
	case 0x4e3ULL: goto x86_l_4e3;
	case 0x4fbULL: goto x86_l_4fb;
	case 0x528ULL: goto x86_l_528;
	case 0x54fULL: goto x86_l_54f;
	case 0x572ULL: goto x86_l_572;
	case 0x5a4ULL: goto x86_l_5a4;
	case 0x5c8ULL: goto x86_l_5c8;
	case 0x62bULL: goto x86_l_62b;
	case 0x66fULL: goto x86_l_66f;
	case 0x6a8ULL: goto x86_l_6a8;
	case 0x6e5ULL: goto x86_l_6e5;
	case 0x726ULL: goto x86_l_726;
	case 0x758ULL: goto x86_l_758;
	case 0x779ULL: goto x86_l_779;
	case 0x7c3ULL: goto x86_l_7c3;
	case 0x7e0ULL: goto x86_l_7e0;
	case 0x856ULL: goto x86_l_856;
	case 0x87bULL: goto x86_l_87b;
	case 0x8baULL: goto x86_l_8ba;
	case 0x8e5ULL: goto x86_l_8e5;
	case 0x918ULL: goto x86_l_918;
	case 0x953ULL: goto x86_l_953;
	case 0x97aULL: goto x86_l_97a;
	case 0x996ULL: goto x86_l_996;
	case 0x9cfULL: goto x86_l_9cf;
	case 0x9fcULL: goto x86_l_9fc;
	}

}

X86_SIM_LICENSE();
