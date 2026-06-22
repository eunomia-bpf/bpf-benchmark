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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 120ULL);
x86_l_7:
	/* 0x7: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f:
	/* 0xf: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_12:
	/* 0x12: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_15:
	/* 0x15: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_18:
	/* 0x18: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1a:
	/* 0x1a: movsxd r12,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_1f:
	/* 0x1f: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_33:
	/* 0x33: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f:
	/* 0x3f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_42:
	/* 0x42: je     9fa <do_action+0x9fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42, 0x9fa, x86_l_9fa);
x86_l_48:
	/* 0x48: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_4c:
	/* 0x4c: jg     76 <do_action+0x76> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4c, 0x76, x86_l_76);
x86_l_4e:
	/* 0x4e: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_52:
	/* 0x52: jg     b2 <do_action+0xb2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x52, 0xb2, x86_l_b2);
x86_l_54:
	/* 0x54: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_58:
	/* 0x58: jg     2c5 <do_action+0x2c5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x58, 0x2c5, x86_l_2c5);
x86_l_5e:
	/* 0x5e: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_61:
	/* 0x61: je     549 <do_action+0x549> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x549, x86_l_549);
x86_l_67:
	/* 0x67: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6b:
	/* 0x6b: je     2de <do_action+0x2de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b, 0x2de, x86_l_2de);
x86_l_71:
	/* 0x71: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x71, 0x9f0, x86_l_9f0);
x86_l_76:
	/* 0x76: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_7a:
	/* 0x7a: jg     1b5 <do_action+0x1b5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7a, 0x1b5, x86_l_1b5);
x86_l_80:
	/* 0x80: lea    ecx,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_85:
	/* 0x85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_88:
	/* 0x88: jb     3e7 <do_action+0x3e7> */
	X86_SIM_X86_JCC(X86_CC_B, 0x88, 0x3e7, x86_l_3e7);
x86_l_8e:
	/* 0x8e: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_92:
	/* 0x92: je     4b1 <do_action+0x4b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92, 0x4b1, x86_l_4b1);
x86_l_98:
	/* 0x98: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_9c:
	/* 0x9c: jne    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c, 0x9f0, x86_l_9f0);
x86_l_a2:
	/* 0xa2: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_a5:
	/* 0xa5: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a8:
	/* 0xa8: mov    edi,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_ad:
	/* 0xad: jmp    603 <do_action+0x603> */
	X86_SIM_X86_JMP(0xad, 0x603, x86_l_603);
x86_l_b2:
	/* 0xb2: lea    eax,[r12-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_b7:
	/* 0xb7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ba:
	/* 0xba: jb     4a0 <do_action+0x4a0> */
	X86_SIM_X86_JCC(X86_CC_B, 0xba, 0x4a0, x86_l_4a0);
x86_l_c0:
	/* 0xc0: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_c4:
	/* 0xc4: je     4be <do_action+0x4be> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4, 0x4be, x86_l_4be);
x86_l_ca:
	/* 0xca: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_ce:
	/* 0xce: jne    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce, 0x9f0, x86_l_9f0);
x86_l_d4:
	/* 0xd4: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_d8:
	/* 0xd8: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_dd:
	/* 0xdd: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_e1:
	/* 0xe1: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e4:
	/* 0xe4: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e7:
	/* 0xe7: ja     9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe7, 0x9f0, x86_l_9f0);
x86_l_ed:
	/* 0xed: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_f6:
	/* 0xf6: jne    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6, 0x9f0, x86_l_9f0);
x86_l_fc:
	/* 0xfc: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_101:
	/* 0x101: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_109:
	/* 0x109: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_111:
	/* 0x111: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_116:
	/* 0x116: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_11e:
	/* 0x11e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122:
	/* 0x122: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_127:
	/* 0x127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129:
	/* 0x129: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_12d:
	/* 0x12d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131:
	/* 0x131: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_136:
	/* 0x136: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_13d:
	/* 0x13d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_140:
	/* 0x140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142:
	/* 0x142: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145:
	/* 0x145: je     9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145, 0x9f0, x86_l_9f0);
x86_l_14b:
	/* 0x14b: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_14e:
	/* 0x14e: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_151:
	/* 0x151: ja     9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x151, 0x9f0, x86_l_9f0);
x86_l_157:
	/* 0x157: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_160:
	/* 0x160: jne    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x160, 0x9f0, x86_l_9f0);
x86_l_166:
	/* 0x166: mov    rcx,QWORD PTR [r13+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_16e:
	/* 0x16e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_176:
	/* 0x176: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_17c:
	/* 0x17c: mov    ecx,DWORD PTR [r13+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_184:
	/* 0x184: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_188:
	/* 0x188: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_18d:
	/* 0x18d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_190:
	/* 0x190: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_192:
	/* 0x192: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a:
	/* 0x19a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19f:
	/* 0x19f: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1a6:
	/* 0x1a6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a9:
	/* 0x1a9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae:
	/* 0x1ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0:
	/* 0x1b0: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x1b0, 0x9f0, x86_l_9f0);
x86_l_1b5:
	/* 0x1b5: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_1b9:
	/* 0x1b9: je     624 <do_action+0x624> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b9, 0x624, x86_l_624);
x86_l_1bf:
	/* 0x1bf: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_1c3:
	/* 0x1c3: je     4d1 <do_action+0x4d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c3, 0x4d1, x86_l_4d1);
x86_l_1c9:
	/* 0x1c9: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_1cd:
	/* 0x1cd: jne    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cd, 0x9f0, x86_l_9f0);
x86_l_1d3:
	/* 0x1d3: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d8:
	/* 0x1d8: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1db:
	/* 0x1db: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1df:
	/* 0x1df: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1e5:
	/* 0x1e5: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1e8:
	/* 0x1e8: je     638 <do_action+0x638> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e8, 0x638, x86_l_638);
x86_l_1ee:
	/* 0x1ee: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f2:
	/* 0x1f2: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f4:
	/* 0x1f4: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1f9:
	/* 0x1f9: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1fc:
	/* 0x1fc: mov    r14d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_201:
	/* 0x201: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_204:
	/* 0x204: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_20b:
	/* 0x20b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_210:
	/* 0x210: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_217:
	/* 0x217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219:
	/* 0x219: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_21f:
	/* 0x21f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_222:
	/* 0x222: je     9c6 <do_action+0x9c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x222, 0x9c6, x86_l_9c6);
x86_l_228:
	/* 0x228: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_22c:
	/* 0x22c: lea    r14,[r14+r14*2] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 0ULL);
x86_l_230:
	/* 0x230: cmp    BYTE PTR [rax+r14*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 3), 2272037699587ULL);
x86_l_239:
	/* 0x239: jne    6a6 <do_action+0x6a6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x239, 0x6a6, x86_l_6a6);
x86_l_23f:
	/* 0x23f: mov    esi,DWORD PTR [rax+r14*8+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 3), 520ULL);
x86_l_247:
	/* 0x247: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24c:
	/* 0x24c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24e:
	/* 0x24e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_251:
	/* 0x251: call   a06 <read_reg> */
	X86_SIM_X86_CALL(x86_l_a06, 0x256ULL);
x86_l_256:
	/* 0x256: add    rax,QWORD PTR [r15+r14*8+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_25e:
	/* 0x25e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_262:
	/* 0x262: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266:
	/* 0x266: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_26b:
	/* 0x26b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d:
	/* 0x26d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_272:
	/* 0x272: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_277:
	/* 0x277: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_27e:
	/* 0x27e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_283:
	/* 0x283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285:
	/* 0x285: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_288:
	/* 0x288: je     926 <do_action+0x926> */
	X86_SIM_X86_JCC(X86_CC_E, 0x288, 0x926, x86_l_926);
x86_l_28e:
	/* 0x28e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_291:
	/* 0x291: mov    DWORD PTR [rsp+0x10],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68720394257ULL);
x86_l_299:
	/* 0x299: mov    QWORD PTR [rsp+0x14],0x37a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85899346810ULL);
x86_l_2a2:
	/* 0x2a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7:
	/* 0x2a7: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2ae:
	/* 0x2ae: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3:
	/* 0x2b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5:
	/* 0x2b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b8:
	/* 0x2b8: je     994 <do_action+0x994> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b8, 0x994, x86_l_994);
x86_l_2be:
	/* 0x2be: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2c0:
	/* 0x2c0: jmp    9b6 <do_action+0x9b6> */
	X86_SIM_X86_JMP(0x2c0, 0x9b6, x86_l_9b6);
x86_l_2c5:
	/* 0x2c5: mov    edi,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_2ca:
	/* 0x2ca: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2ce:
	/* 0x2ce: je     600 <do_action+0x600> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ce, 0x600, x86_l_600);
x86_l_2d4:
	/* 0x2d4: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2d8:
	/* 0x2d8: jne    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d8, 0x9f0, x86_l_9f0);
x86_l_2de:
	/* 0x2de: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2e2:
	/* 0x2e2: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_2e7:
	/* 0x2e7: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2eb:
	/* 0x2eb: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_2f0:
	/* 0x2f0: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f8:
	/* 0x2f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fd:
	/* 0x2fd: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_304:
	/* 0x304: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_309:
	/* 0x309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b:
	/* 0x30b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30e:
	/* 0x30e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_311:
	/* 0x311: je     6d6 <do_action+0x6d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x311, 0x6d6, x86_l_6d6);
x86_l_317:
	/* 0x317: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31c:
	/* 0x31c: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_31f:
	/* 0x31f: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_322:
	/* 0x322: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_327:
	/* 0x327: ja     6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x327, 0x6d8, x86_l_6d8);
x86_l_32d:
	/* 0x32d: cmp    DWORD PTR [r13+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_336:
	/* 0x336: jne    6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x336, 0x6d8, x86_l_6d8);
x86_l_33c:
	/* 0x33c: mov    rax,QWORD PTR [r13+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_344:
	/* 0x344: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_34c:
	/* 0x34c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_351:
	/* 0x351: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_359:
	/* 0x359: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35d:
	/* 0x35d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_362:
	/* 0x362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364:
	/* 0x364: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_368:
	/* 0x368: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c:
	/* 0x36c: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_370:
	/* 0x370: jne    6af <do_action+0x6af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x370, 0x6af, x86_l_6af);
x86_l_376:
	/* 0x376: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_379:
	/* 0x379: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_37c:
	/* 0x37c: ja     6d6 <do_action+0x6d6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x37c, 0x6d6, x86_l_6d6);
x86_l_382:
	/* 0x382: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_38b:
	/* 0x38b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_390:
	/* 0x390: jne    6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x390, 0x6d8, x86_l_6d8);
x86_l_396:
	/* 0x396: mov    rax,QWORD PTR [r13+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_39e:
	/* 0x39e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3a3:
	/* 0x3a3: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3a7:
	/* 0x3a7: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3ae:
	/* 0x3ae: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_3b3:
	/* 0x3b3: and    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R13, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_3bb:
	/* 0x3bb: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_3be:
	/* 0x3be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c3:
	/* 0x3c3: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c8:
	/* 0x3c8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd:
	/* 0x3cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d2:
	/* 0x3d2: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_3d9:
	/* 0x3d9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dc:
	/* 0x3dc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3e2:
	/* 0x3e2: jmp    497 <do_action+0x497> */
	X86_SIM_X86_JMP(0x3e2, 0x497, x86_l_497);
x86_l_3e7:
	/* 0x3e7: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3ea:
	/* 0x3ea: mov    ecx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_3ef:
	/* 0x3ef: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3f2:
	/* 0x3f2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f5:
	/* 0x3f5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3f8:
	/* 0x3f8: ja     6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3f8, 0x6d8, x86_l_6d8);
x86_l_3fe:
	/* 0x3fe: cmp    DWORD PTR [r13+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_407:
	/* 0x407: jne    6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x407, 0x6d8, x86_l_6d8);
x86_l_40d:
	/* 0x40d: mov    rcx,QWORD PTR [r13+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_415:
	/* 0x415: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_41b:
	/* 0x41b: mov    rcx,QWORD PTR [r13+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_428:
	/* 0x428: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_42b:
	/* 0x42b: je     6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42b, 0x6d8, x86_l_6d8);
x86_l_431:
	/* 0x431: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_435:
	/* 0x435: jne    6c0 <do_action+0x6c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x435, 0x6c0, x86_l_6c0);
x86_l_43b:
	/* 0x43b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_440:
	/* 0x440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_442:
	/* 0x442: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_445:
	/* 0x445: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_449:
	/* 0x449: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c:
	/* 0x44c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_451:
	/* 0x451: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_458:
	/* 0x458: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_45b:
	/* 0x45b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d:
	/* 0x45d: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_460:
	/* 0x460: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_463:
	/* 0x463: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_468:
	/* 0x468: je     6d8 <do_action+0x6d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x468, 0x6d8, x86_l_6d8);
x86_l_46e:
	/* 0x46e: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_470:
	/* 0x470: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_473:
	/* 0x473: mov    DWORD PTR [rsp+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_477:
	/* 0x477: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_480:
	/* 0x480: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_485:
	/* 0x485: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_48c:
	/* 0x48c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48f:
	/* 0x48f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_494:
	/* 0x494: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_497:
	/* 0x497: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_499:
	/* 0x499: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49b:
	/* 0x49b: jmp    6d6 <do_action+0x6d6> */
	X86_SIM_X86_JMP(0x49b, 0x6d6, x86_l_6d6);
x86_l_4a0:
	/* 0x4a0: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a3:
	/* 0x4a3: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_4a8:
	/* 0x4a8: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4ac:
	/* 0x4ac: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x4ac, 0x9f0, x86_l_9f0);
x86_l_4b1:
	/* 0x4b1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b6:
	/* 0x4b6: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b9:
	/* 0x4b9: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x4b9, 0x9f0, x86_l_9f0);
x86_l_4be:
	/* 0x4be: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_4c1:
	/* 0x4c1: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4c4:
	/* 0x4c4: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4c8:
	/* 0x4c8: xor    r13,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_4cc:
	/* 0x4cc: jmp    9cb <do_action+0x9cb> */
	X86_SIM_X86_JMP(0x4cc, 0x9cb, x86_l_9cb);
x86_l_4d1:
	/* 0x4d1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4d6:
	/* 0x4d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d8:
	/* 0x4d8: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4dd:
	/* 0x4dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e2:
	/* 0x4e2: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4e9:
	/* 0x4e9: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ee:
	/* 0x4ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0:
	/* 0x4f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f3:
	/* 0x4f3: je     9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f3, 0x9f0, x86_l_9f0);
x86_l_4f9:
	/* 0x4f9: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4fd:
	/* 0x4fd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_502:
	/* 0x502: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_50a:
	/* 0x50a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50f:
	/* 0x50f: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_516:
	/* 0x516: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51b:
	/* 0x51b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d:
	/* 0x51d: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_525:
	/* 0x525: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_528:
	/* 0x528: je     640 <do_action+0x640> */
	X86_SIM_X86_JCC(X86_CC_E, 0x528, 0x640, x86_l_640);
x86_l_52e:
	/* 0x52e: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_531:
	/* 0x531: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_536:
	/* 0x536: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_53d:
	/* 0x53d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_542:
	/* 0x542: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_544:
	/* 0x544: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x544, 0x9f0, x86_l_9f0);
x86_l_549:
	/* 0x549: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_54e:
	/* 0x54e: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_552:
	/* 0x552: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_557:
	/* 0x557: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_55b:
	/* 0x55b: mov    ebx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_560:
	/* 0x560: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_565:
	/* 0x565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_570:
	/* 0x570: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_57d:
	/* 0x57d: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_580:
	/* 0x580: je     8ae <do_action+0x8ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x580, 0x8ae, x86_l_8ae);
x86_l_586:
	/* 0x586: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58b:
	/* 0x58b: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_592:
	/* 0x592: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_597:
	/* 0x597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_599:
	/* 0x599: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: je     8ae <do_action+0x8ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59c, 0x8ae, x86_l_8ae);
x86_l_5a2:
	/* 0x5a2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5a5:
	/* 0x5a5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5aa:
	/* 0x5aa: mov    DWORD PTR [rsp+0x38],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5ae:
	/* 0x5ae: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5b1:
	/* 0x5b1: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5b8:
	/* 0x5b8: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5bd:
	/* 0x5bd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5bf:
	/* 0x5bf: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5c3:
	/* 0x5c3: mov    rcx,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5c7:
	/* 0x5c7: mov    QWORD PTR [rbp+0x0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cb:
	/* 0x5cb: mov    rcx,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d4:
	/* 0x5d4: mov    QWORD PTR [rbp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d8:
	/* 0x5d8: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_5dd:
	/* 0x5dd: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5e0:
	/* 0x5e0: je     6ea <do_action+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e0, 0x6ea, x86_l_6ea);
x86_l_5e6:
	/* 0x5e6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_5e9:
	/* 0x5e9: je     6e6 <do_action+0x6e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e9, 0x6e6, x86_l_6e6);
x86_l_5ef:
	/* 0x5ef: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_5f1:
	/* 0x5f1: jne    8ae <do_action+0x8ae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f1, 0x8ae, x86_l_8ae);
x86_l_5f7:
	/* 0x5f7: mov    ecx,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_5fb:
	/* 0x5fb: jmp    6ea <do_action+0x6ea> */
	X86_SIM_X86_JMP(0x5fb, 0x6ea, x86_l_6ea);
x86_l_600:
	/* 0x600: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_603:
	/* 0x603: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_609:
	/* 0x609: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_60c:
	/* 0x60c: je     9cb <do_action+0x9cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60c, 0x9cb, x86_l_9cb);
x86_l_612:
	/* 0x612: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_617:
	/* 0x617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_619:
	/* 0x619: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_61f:
	/* 0x61f: jmp    9cb <do_action+0x9cb> */
	X86_SIM_X86_JMP(0x61f, 0x9cb, x86_l_9cb);
x86_l_624:
	/* 0x624: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_627:
	/* 0x627: add    r14d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_62b:
	/* 0x62b: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_62f:
	/* 0x62f: xor    r13,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_633:
	/* 0x633: jmp    9cb <do_action+0x9cb> */
	X86_SIM_X86_JMP(0x633, 0x9cb, x86_l_9cb);
x86_l_638:
	/* 0x638: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_63b:
	/* 0x63b: jmp    9cb <do_action+0x9cb> */
	X86_SIM_X86_JMP(0x63b, 0x9cb, x86_l_9cb);
x86_l_640:
	/* 0x640: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_645:
	/* 0x645: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_64c:
	/* 0x64c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_651:
	/* 0x651: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_656:
	/* 0x656: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_65b:
	/* 0x65b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65d:
	/* 0x65d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_660:
	/* 0x660: je     531 <do_action+0x531> */
	X86_SIM_X86_JCC(X86_CC_E, 0x660, 0x531, x86_l_531);
x86_l_666:
	/* 0x666: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_669:
	/* 0x669: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_66b:
	/* 0x66b: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66f:
	/* 0x66f: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_676:
	/* 0x676: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_680:
	/* 0x680: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_685:
	/* 0x685: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68a:
	/* 0x68a: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_691:
	/* 0x691: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_694:
	/* 0x694: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696:
	/* 0x696: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_699:
	/* 0x699: je     943 <do_action+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x699, 0x943, x86_l_943);
x86_l_69f:
	/* 0x69f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6a1:
	/* 0x6a1: jmp    963 <do_action+0x963> */
	X86_SIM_X86_JMP(0x6a1, 0x963, x86_l_963);
x86_l_6a6:
	/* 0x6a6: or     BYTE PTR [rbx+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_6aa:
	/* 0x6aa: jmp    9c6 <do_action+0x9c6> */
	X86_SIM_X86_JMP(0x6aa, 0x9c6, x86_l_9c6);
x86_l_6af:
	/* 0x6af: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6b4:
	/* 0x6b4: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6bb:
	/* 0x6bb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6be:
	/* 0x6be: jmp    6d1 <do_action+0x6d1> */
	X86_SIM_X86_JMP(0x6be, 0x6d1, x86_l_6d1);
x86_l_6c0:
	/* 0x6c0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6c5:
	/* 0x6c5: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_6cc:
	/* 0x6cc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d1:
	/* 0x6d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d3:
	/* 0x6d3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6d6:
	/* 0x6d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d8:
	/* 0x6d8: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_6db:
	/* 0x6db: jne    9fa <do_action+0x9fa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6db, 0x9fa, x86_l_9fa);
x86_l_6e1:
	/* 0x6e1: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x6e1, 0x9f0, x86_l_9f0);
x86_l_6e6:
	/* 0x6e6: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ea:
	/* 0x6ea: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ec:
	/* 0x6ec: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6f1:
	/* 0x6f1: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6f3:
	/* 0x6f3: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6f8:
	/* 0x6f8: mov    QWORD PTR [rdx+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fc:
	/* 0x6fc: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_700:
	/* 0x700: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_705:
	/* 0x705: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_70a:
	/* 0x70a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_70d:
	/* 0x70d: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_712:
	/* 0x712: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_715:
	/* 0x715: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_717:
	/* 0x717: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_719:
	/* 0x719: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_71e:
	/* 0x71e: jmp    72e <do_action+0x72e> */
	X86_SIM_X86_JMP(0x71e, 0x72e, x86_l_72e);
x86_l_720:
	/* 0x720: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_724:
	/* 0x724: cmp    rbx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 20ULL);
x86_l_728:
	/* 0x728: je     85e <do_action+0x85e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x728, 0x85e, x86_l_85e);
x86_l_72e:
	/* 0x72e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_736:
	/* 0x736: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_73b:
	/* 0x73b: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_742:
	/* 0x742: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74c:
	/* 0x74c: je     85e <do_action+0x85e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74c, 0x85e, x86_l_85e);
x86_l_752:
	/* 0x752: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_758:
	/* 0x758: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_75d:
	/* 0x75d: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_764:
	/* 0x764: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_767:
	/* 0x767: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_769:
	/* 0x769: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76c:
	/* 0x76c: je     85e <do_action+0x85e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76c, 0x85e, x86_l_85e);
x86_l_772:
	/* 0x772: cmp    DWORD PTR [rax+rbx*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 279172874239ULL);
x86_l_777:
	/* 0x777: je     85e <do_action+0x85e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x777, 0x85e, x86_l_85e);
x86_l_77d:
	/* 0x77d: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_785:
	/* 0x785: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_789:
	/* 0x789: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_78c:
	/* 0x78c: jge    85e <do_action+0x85e> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x78c, 0x85e, x86_l_85e);
x86_l_792:
	/* 0x792: cmp    rbx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 16ULL);
x86_l_796:
	/* 0x796: je     7fc <do_action+0x7fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x796, 0x7fc, x86_l_7fc);
x86_l_798:
	/* 0x798: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_7a0:
	/* 0x7a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a5:
	/* 0x7a5: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7ac:
	/* 0x7ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b1:
	/* 0x7b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b3:
	/* 0x7b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b6:
	/* 0x7b6: je     7f4 <do_action+0x7f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b6, 0x7f4, x86_l_7f4);
x86_l_7b8:
	/* 0x7b8: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_7be:
	/* 0x7be: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7c3:
	/* 0x7c3: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_7ca:
	/* 0x7ca: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7cd:
	/* 0x7cd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7cf:
	/* 0x7cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d2:
	/* 0x7d2: je     7f4 <do_action+0x7f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d2, 0x7f4, x86_l_7f4);
x86_l_7d4:
	/* 0x7d4: cmp    DWORD PTR [rax+rbx*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 296352743423ULL);
x86_l_7d9:
	/* 0x7d9: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_7e1:
	/* 0x7e1: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7e6:
	/* 0x7e6: je     7fc <do_action+0x7fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e6, 0x7fc, x86_l_7fc);
x86_l_7e8:
	/* 0x7e8: mov    ebp,DWORD PTR [r13+rbx*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 1), 24192ULL);
x86_l_7f0:
	/* 0x7f0: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7f2:
	/* 0x7f2: jmp    80a <do_action+0x80a> */
	X86_SIM_X86_JMP(0x7f2, 0x80a, x86_l_80a);
x86_l_7f4:
	/* 0x7f4: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_7fc:
	/* 0x7fc: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_800:
	/* 0x800: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_802:
	/* 0x802: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_805:
	/* 0x805: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_80a:
	/* 0x80a: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_80c:
	/* 0x80c: jle    720 <do_action+0x720> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x80c, 0x720, x86_l_720);
x86_l_812:
	/* 0x812: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_817:
	/* 0x817: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_81c:
	/* 0x81c: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_81f:
	/* 0x81f: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_824:
	/* 0x824: cmovge ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_GE);
x86_l_827:
	/* 0x827: movzx  r13d,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_82d:
	/* 0x82d: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_831:
	/* 0x831: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_836:
	/* 0x836: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_83a:
	/* 0x83a: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_841:
	/* 0x841: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_846:
	/* 0x846: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_848:
	/* 0x848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84a:
	/* 0x84a: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_84d:
	/* 0x84d: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_852:
	/* 0x852: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_854:
	/* 0x854: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_859:
	/* 0x859: jmp    720 <do_action+0x720> */
	X86_SIM_X86_JMP(0x859, 0x720, x86_l_720);
x86_l_85e:
	/* 0x85e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_863:
	/* 0x863: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_86a:
	/* 0x86a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_86f:
	/* 0x86f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_871:
	/* 0x871: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_874:
	/* 0x874: je     896 <do_action+0x896> */
	X86_SIM_X86_JCC(X86_CC_E, 0x874, 0x896, x86_l_896);
x86_l_876:
	/* 0x876: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_87f:
	/* 0x87f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_884:
	/* 0x884: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_887:
	/* 0x887: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_88a:
	/* 0x88a: jbe    896 <do_action+0x896> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x88a, 0x896, x86_l_896);
x86_l_88c:
	/* 0x88c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_891:
	/* 0x891: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_894:
	/* 0x894: jmp    8ae <do_action+0x8ae> */
	X86_SIM_X86_JMP(0x894, 0x8ae, x86_l_8ae);
x86_l_896:
	/* 0x896: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_89b:
	/* 0x89b: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_8a2:
	/* 0x8a2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_8a5:
	/* 0x8a5: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8aa:
	/* 0x8aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ac:
	/* 0x8ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ae:
	/* 0x8ae: lea    eax,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_8b2:
	/* 0x8b2: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8b8:
	/* 0x8b8: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8bd:
	/* 0x8bd: je     8de <do_action+0x8de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8bd, 0x8de, x86_l_8de);
x86_l_8bf:
	/* 0x8bf: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_8c4:
	/* 0x8c4: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8c9:
	/* 0x8c9: mov    rsi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8d0:
	/* 0x8d0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8d3:
	/* 0x8d3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d5:
	/* 0x8d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d7:
	/* 0x8d7: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8de:
	/* 0x8de: lea    eax,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8e2:
	/* 0x8e2: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8e8:
	/* 0x8e8: je     90c <do_action+0x90c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e8, 0x90c, x86_l_90c);
x86_l_8ea:
	/* 0x8ea: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_8ef:
	/* 0x8ef: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8f4:
	/* 0x8f4: mov    rsi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8fb:
	/* 0x8fb: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_900:
	/* 0x900: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_903:
	/* 0x903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_905:
	/* 0x905: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_90c:
	/* 0x90c: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_910:
	/* 0x910: cmp    DWORD PTR [r15+r14*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 17179869184ULL);
x86_l_916:
	/* 0x916: je     9f0 <do_action+0x9f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x916, 0x9f0, x86_l_9f0);
x86_l_91c:
	/* 0x91c: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_921:
	/* 0x921: jmp    9f0 <do_action+0x9f0> */
	X86_SIM_X86_JMP(0x921, 0x9f0, x86_l_9f0);
x86_l_926:
	/* 0x926: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_92b:
	/* 0x92b: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_932:
	/* 0x932: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_937:
	/* 0x937: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_93a:
	/* 0x93a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93c:
	/* 0x93c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93e:
	/* 0x93e: jmp    9c6 <do_action+0x9c6> */
	X86_SIM_X86_JMP(0x93e, 0x9c6, x86_l_9c6);
x86_l_943:
	/* 0x943: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_94b:
	/* 0x94b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_950:
	/* 0x950: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_957:
	/* 0x957: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_95a:
	/* 0x95a: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95f:
	/* 0x95f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_961:
	/* 0x961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_963:
	/* 0x963: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_966:
	/* 0x966: je     531 <do_action+0x531> */
	X86_SIM_X86_JCC(X86_CC_E, 0x966, 0x531, x86_l_531);
x86_l_96c:
	/* 0x96c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_971:
	/* 0x971: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_978:
	/* 0x978: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_97d:
	/* 0x97d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97f:
	/* 0x97f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_982:
	/* 0x982: je     531 <do_action+0x531> */
	X86_SIM_X86_JCC(X86_CC_E, 0x982, 0x531, x86_l_531);
x86_l_988:
	/* 0x988: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_98c:
	/* 0x98c: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_98f:
	/* 0x98f: jmp    531 <do_action+0x531> */
	X86_SIM_X86_JMP(0x98f, 0x531, x86_l_531);
x86_l_994:
	/* 0x994: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_99c:
	/* 0x99c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9a1:
	/* 0x9a1: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9a8:
	/* 0x9a8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ad:
	/* 0x9ad: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b2:
	/* 0x9b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b4:
	/* 0x9b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b6:
	/* 0x9b6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ba:
	/* 0x9ba: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9bf:
	/* 0x9bf: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c3:
	/* 0x9c3: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c6:
	/* 0x9c6: mov    r14d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9cb:
	/* 0x9cb: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d2:
	/* 0x9d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9d7:
	/* 0x9d7: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_9de:
	/* 0x9de: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9e1:
	/* 0x9e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e3:
	/* 0x9e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e6:
	/* 0x9e6: je     9ed <do_action+0x9ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e6, 0x9ed, x86_l_9ed);
x86_l_9e8:
	/* 0x9e8: inc QWORD PTR [rax+r13*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R13, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9ed:
	/* 0x9ed: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_9f0:
	/* 0x9f0: mov    QWORD PTR [r13+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9f4:
	/* 0x9f4: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9f7:
	/* 0x9f7: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_9fa:
	/* 0x9fa: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_9fe:
	/* 0x9fe: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_a00:
	/* 0xa00: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: jmp    b1c <read_reg+0x116> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b1c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_a06 */
x86_l_a06:
	/* 0xa06: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_a0c:
	/* 0xa0c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0e:
	/* 0xa0e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_a11:
	/* 0xa11: jle    a48 <read_reg+0x42> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa11, 0xa48, x86_l_a48);
x86_l_a13:
	/* 0xa13: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_a16:
	/* 0xa16: jle    a6c <read_reg+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa16, 0xa6c, x86_l_a6c);
x86_l_a18:
	/* 0xa18: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_a1b:
	/* 0xa1b: jle    ad1 <read_reg+0xcb> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa1b, 0xad1, x86_l_ad1);
x86_l_a21:
	/* 0xa21: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_a24:
	/* 0xa24: je     b05 <read_reg+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa24, 0xb05, x86_l_b05);
x86_l_a2a:
	/* 0xa2a: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a2d:
	/* 0xa2d: je     aed <read_reg+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa2d, 0xaed, x86_l_aed);
x86_l_a33:
	/* 0xa33: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_a36:
	/* 0xa36: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa36, 0xb1b, x86_l_b1b);
x86_l_a3c:
	/* 0xa3c: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_a43:
	/* 0xa43: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa43, 0xb0f, x86_l_b0f);
x86_l_a48:
	/* 0xa48: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a4b:
	/* 0xa4b: jg     a88 <read_reg+0x82> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa4b, 0xa88, x86_l_a88);
x86_l_a4d:
	/* 0xa4d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a50:
	/* 0xa50: jg     ab1 <read_reg+0xab> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa50, 0xab1, x86_l_ab1);
x86_l_a52:
	/* 0xa52: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_a54:
	/* 0xa54: je     b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa54, 0xb0f, x86_l_b0f);
x86_l_a5a:
	/* 0xa5a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a5d:
	/* 0xa5d: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa5d, 0xb1b, x86_l_b1b);
x86_l_a63:
	/* 0xa63: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a67:
	/* 0xa67: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa67, 0xb0f, x86_l_b0f);
x86_l_a6c:
	/* 0xa6c: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a6f:
	/* 0xa6f: jg     aa1 <read_reg+0x9b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa6f, 0xaa1, x86_l_aa1);
x86_l_a71:
	/* 0xa71: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a74:
	/* 0xa74: je     ae1 <read_reg+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa74, 0xae1, x86_l_ae1);
x86_l_a76:
	/* 0xa76: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a79:
	/* 0xa79: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa79, 0xb1b, x86_l_b1b);
x86_l_a7f:
	/* 0xa7f: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_a83:
	/* 0xa83: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa83, 0xb0f, x86_l_b0f);
x86_l_a88:
	/* 0xa88: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a8b:
	/* 0xa8b: jg     ac1 <read_reg+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa8b, 0xac1, x86_l_ac1);
x86_l_a8d:
	/* 0xa8d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a90:
	/* 0xa90: je     af3 <read_reg+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa90, 0xaf3, x86_l_af3);
x86_l_a92:
	/* 0xa92: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a95:
	/* 0xa95: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa95, 0xb1b, x86_l_b1b);
x86_l_a9b:
	/* 0xa9b: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_a9f:
	/* 0xa9f: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa9f, 0xb0f, x86_l_b0f);
x86_l_aa1:
	/* 0xaa1: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_aa4:
	/* 0xaa4: je     ae7 <read_reg+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaa4, 0xae7, x86_l_ae7);
x86_l_aa6:
	/* 0xaa6: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_aa9:
	/* 0xaa9: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xaa9, 0xb1b, x86_l_b1b);
x86_l_aab:
	/* 0xaab: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_aaf:
	/* 0xaaf: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaaf, 0xb0f, x86_l_b0f);
x86_l_ab1:
	/* 0xab1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ab4:
	/* 0xab4: je     af9 <read_reg+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xab4, 0xaf9, x86_l_af9);
x86_l_ab6:
	/* 0xab6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ab9:
	/* 0xab9: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xab9, 0xb1b, x86_l_b1b);
x86_l_abb:
	/* 0xabb: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_abf:
	/* 0xabf: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xabf, 0xb0f, x86_l_b0f);
x86_l_ac1:
	/* 0xac1: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ac4:
	/* 0xac4: je     aff <read_reg+0xf9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xac4, 0xaff, x86_l_aff);
x86_l_ac6:
	/* 0xac6: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ac9:
	/* 0xac9: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xac9, 0xb1b, x86_l_b1b);
x86_l_acb:
	/* 0xacb: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_acf:
	/* 0xacf: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xacf, 0xb0f, x86_l_b0f);
x86_l_ad1:
	/* 0xad1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ad4:
	/* 0xad4: je     b0b <read_reg+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xad4, 0xb0b, x86_l_b0b);
x86_l_ad6:
	/* 0xad6: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_ad9:
	/* 0xad9: jne    b1b <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xad9, 0xb1b, x86_l_b1b);
x86_l_adb:
	/* 0xadb: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_adf:
	/* 0xadf: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xadf, 0xb0f, x86_l_b0f);
x86_l_ae1:
	/* 0xae1: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_ae5:
	/* 0xae5: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xae5, 0xb0f, x86_l_b0f);
x86_l_ae7:
	/* 0xae7: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_aeb:
	/* 0xaeb: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaeb, 0xb0f, x86_l_b0f);
x86_l_aed:
	/* 0xaed: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_af1:
	/* 0xaf1: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaf1, 0xb0f, x86_l_b0f);
x86_l_af3:
	/* 0xaf3: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_af7:
	/* 0xaf7: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaf7, 0xb0f, x86_l_b0f);
x86_l_af9:
	/* 0xaf9: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_afd:
	/* 0xafd: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xafd, 0xb0f, x86_l_b0f);
x86_l_aff:
	/* 0xaff: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b03:
	/* 0xb03: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb03, 0xb0f, x86_l_b0f);
x86_l_b05:
	/* 0xb05: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_b09:
	/* 0xb09: jmp    b0f <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb09, 0xb0f, x86_l_b0f);
x86_l_b0b:
	/* 0xb0b: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_b0f:
	/* 0xb0f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_b14:
	/* 0xb14: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b16:
	/* 0xb16: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_b1b:
	/* 0xb1b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x3aULL: goto x86_l_3a;
	case 0x129ULL: goto x86_l_129;
	case 0x142ULL: goto x86_l_142;
	case 0x192ULL: goto x86_l_192;
	case 0x1b0ULL: goto x86_l_1b0;
	case 0x219ULL: goto x86_l_219;
	case 0x256ULL: goto x86_l_256;
	case 0x26dULL: goto x86_l_26d;
	case 0x285ULL: goto x86_l_285;
	case 0x2b5ULL: goto x86_l_2b5;
	case 0x30bULL: goto x86_l_30b;
	case 0x364ULL: goto x86_l_364;
	case 0x3cdULL: goto x86_l_3cd;
	case 0x442ULL: goto x86_l_442;
	case 0x45dULL: goto x86_l_45d;
	case 0x49bULL: goto x86_l_49b;
	case 0x4d8ULL: goto x86_l_4d8;
	case 0x4f0ULL: goto x86_l_4f0;
	case 0x51dULL: goto x86_l_51d;
	case 0x544ULL: goto x86_l_544;
	case 0x567ULL: goto x86_l_567;
	case 0x599ULL: goto x86_l_599;
	case 0x5bfULL: goto x86_l_5bf;
	case 0x619ULL: goto x86_l_619;
	case 0x65dULL: goto x86_l_65d;
	case 0x696ULL: goto x86_l_696;
	case 0x6d3ULL: goto x86_l_6d3;
	case 0x717ULL: goto x86_l_717;
	case 0x749ULL: goto x86_l_749;
	case 0x769ULL: goto x86_l_769;
	case 0x7b3ULL: goto x86_l_7b3;
	case 0x7cfULL: goto x86_l_7cf;
	case 0x84aULL: goto x86_l_84a;
	case 0x871ULL: goto x86_l_871;
	case 0x8aeULL: goto x86_l_8ae;
	case 0x8d7ULL: goto x86_l_8d7;
	case 0x905ULL: goto x86_l_905;
	case 0x93eULL: goto x86_l_93e;
	case 0x963ULL: goto x86_l_963;
	case 0x97fULL: goto x86_l_97f;
	case 0x9b6ULL: goto x86_l_9b6;
	case 0x9e3ULL: goto x86_l_9e3;
	}

}

X86_SIM_LICENSE();
