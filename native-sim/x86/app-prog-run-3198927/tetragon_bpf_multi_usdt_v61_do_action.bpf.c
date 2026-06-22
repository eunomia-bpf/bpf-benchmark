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
	/* 0x27: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2e:
	/* 0x2e: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_33:
	/* 0x33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
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
	/* 0x42: je     a0c <do_action+0xa0c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42, 0xa0c, x86_l_a0c);
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
	/* 0x58: jg     2c7 <do_action+0x2c7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x58, 0x2c7, x86_l_2c7);
x86_l_5e:
	/* 0x5e: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_61:
	/* 0x61: je     54d <do_action+0x54d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x54d, x86_l_54d);
x86_l_67:
	/* 0x67: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6b:
	/* 0x6b: je     2e0 <do_action+0x2e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b, 0x2e0, x86_l_2e0);
x86_l_71:
	/* 0x71: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x71, 0xa02, x86_l_a02);
x86_l_76:
	/* 0x76: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_7a:
	/* 0x7a: jg     1b7 <do_action+0x1b7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7a, 0x1b7, x86_l_1b7);
x86_l_80:
	/* 0x80: lea    ecx,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_85:
	/* 0x85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_88:
	/* 0x88: jb     3eb <do_action+0x3eb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x88, 0x3eb, x86_l_3eb);
x86_l_8e:
	/* 0x8e: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_92:
	/* 0x92: je     4b5 <do_action+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92, 0x4b5, x86_l_4b5);
x86_l_98:
	/* 0x98: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_9c:
	/* 0x9c: jne    a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c, 0xa02, x86_l_a02);
x86_l_a2:
	/* 0xa2: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_a5:
	/* 0xa5: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a8:
	/* 0xa8: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_ad:
	/* 0xad: jmp    60b <do_action+0x60b> */
	X86_SIM_X86_JMP(0xad, 0x60b, x86_l_60b);
x86_l_b2:
	/* 0xb2: lea    eax,[r12-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_b7:
	/* 0xb7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ba:
	/* 0xba: jb     4a4 <do_action+0x4a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0xba, 0x4a4, x86_l_4a4);
x86_l_c0:
	/* 0xc0: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_c4:
	/* 0xc4: je     4c2 <do_action+0x4c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4, 0x4c2, x86_l_4c2);
x86_l_ca:
	/* 0xca: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_ce:
	/* 0xce: jne    a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce, 0xa02, x86_l_a02);
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
	/* 0xe7: ja     a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe7, 0xa02, x86_l_a02);
x86_l_ed:
	/* 0xed: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_f6:
	/* 0xf6: jne    a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6, 0xa02, x86_l_a02);
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
	/* 0x131: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_138:
	/* 0x138: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140:
	/* 0x140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142:
	/* 0x142: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145:
	/* 0x145: je     a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145, 0xa02, x86_l_a02);
x86_l_14b:
	/* 0x14b: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_14e:
	/* 0x14e: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_151:
	/* 0x151: ja     a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_A, 0x151, 0xa02, x86_l_a02);
x86_l_157:
	/* 0x157: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_160:
	/* 0x160: jne    a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x160, 0xa02, x86_l_a02);
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
	/* 0x188: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_190:
	/* 0x190: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192:
	/* 0x192: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a:
	/* 0x19a: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1a1:
	/* 0x1a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3:
	/* 0x1a3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a6:
	/* 0x1a6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ab:
	/* 0x1ab: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b0:
	/* 0x1b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2:
	/* 0x1b2: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x1b2, 0xa02, x86_l_a02);
x86_l_1b7:
	/* 0x1b7: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_1bb:
	/* 0x1bb: je     62f <do_action+0x62f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bb, 0x62f, x86_l_62f);
x86_l_1c1:
	/* 0x1c1: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_1c5:
	/* 0x1c5: je     4d5 <do_action+0x4d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c5, 0x4d5, x86_l_4d5);
x86_l_1cb:
	/* 0x1cb: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_1cf:
	/* 0x1cf: jne    a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cf, 0xa02, x86_l_a02);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1da:
	/* 0x1da: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1dd:
	/* 0x1dd: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1e1:
	/* 0x1e1: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1e7:
	/* 0x1e7: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1ea:
	/* 0x1ea: je     643 <do_action+0x643> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ea, 0x643, x86_l_643);
x86_l_1f0:
	/* 0x1f0: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f4:
	/* 0x1f4: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f6:
	/* 0x1f6: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1fb:
	/* 0x1fb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1fe:
	/* 0x1fe: mov    r14d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_203:
	/* 0x203: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_206:
	/* 0x206: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_20d:
	/* 0x20d: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_214:
	/* 0x214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_219:
	/* 0x219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b:
	/* 0x21b: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_221:
	/* 0x221: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_224:
	/* 0x224: je     9d8 <do_action+0x9d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x224, 0x9d8, x86_l_9d8);
x86_l_22a:
	/* 0x22a: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_22e:
	/* 0x22e: lea    r14,[r14+r14*2] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 0ULL);
x86_l_232:
	/* 0x232: cmp    BYTE PTR [rax+r14*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 3), 2272037699587ULL);
x86_l_23b:
	/* 0x23b: jne    6b1 <do_action+0x6b1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23b, 0x6b1, x86_l_6b1);
x86_l_241:
	/* 0x241: mov    esi,DWORD PTR [rax+r14*8+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 3), 520ULL);
x86_l_249:
	/* 0x249: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24e:
	/* 0x24e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_250:
	/* 0x250: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_253:
	/* 0x253: call   a18 <read_reg> */
	X86_SIM_X86_CALL(x86_l_a18, 0x258ULL);
x86_l_258:
	/* 0x258: add    rax,QWORD PTR [r15+r14*8+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_260:
	/* 0x260: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_264:
	/* 0x264: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268:
	/* 0x268: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_26d:
	/* 0x26d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f:
	/* 0x26f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_274:
	/* 0x274: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_27b:
	/* 0x27b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_280:
	/* 0x280: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_285:
	/* 0x285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287:
	/* 0x287: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28a:
	/* 0x28a: je     932 <do_action+0x932> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28a, 0x932, x86_l_932);
x86_l_290:
	/* 0x290: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: mov    DWORD PTR [rsp+0x10],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68720394257ULL);
x86_l_29b:
	/* 0x29b: mov    QWORD PTR [rsp+0x14],0x37a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85899346810ULL);
x86_l_2a4:
	/* 0x2a4: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2ab:
	/* 0x2ab: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b0:
	/* 0x2b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b5:
	/* 0x2b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7:
	/* 0x2b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: je     9a4 <do_action+0x9a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ba, 0x9a4, x86_l_9a4);
x86_l_2c0:
	/* 0x2c0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2c2:
	/* 0x2c2: jmp    9c8 <do_action+0x9c8> */
	X86_SIM_X86_JMP(0x2c2, 0x9c8, x86_l_9c8);
x86_l_2c7:
	/* 0x2c7: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2cc:
	/* 0x2cc: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2d0:
	/* 0x2d0: je     608 <do_action+0x608> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d0, 0x608, x86_l_608);
x86_l_2d6:
	/* 0x2d6: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2da:
	/* 0x2da: jne    a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2da, 0xa02, x86_l_a02);
x86_l_2e0:
	/* 0x2e0: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2e4:
	/* 0x2e4: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_2e9:
	/* 0x2e9: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2ed:
	/* 0x2ed: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_2f2:
	/* 0x2f2: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fa:
	/* 0x2fa: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_301:
	/* 0x301: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_306:
	/* 0x306: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30b:
	/* 0x30b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d:
	/* 0x30d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_310:
	/* 0x310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: je     6e1 <do_action+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x313, 0x6e1, x86_l_6e1);
x86_l_319:
	/* 0x319: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31e:
	/* 0x31e: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_321:
	/* 0x321: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_324:
	/* 0x324: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_329:
	/* 0x329: ja     6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x329, 0x6e3, x86_l_6e3);
x86_l_32f:
	/* 0x32f: cmp    DWORD PTR [r13+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_338:
	/* 0x338: jne    6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x338, 0x6e3, x86_l_6e3);
x86_l_33e:
	/* 0x33e: mov    rax,QWORD PTR [r13+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_346:
	/* 0x346: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_34e:
	/* 0x34e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_353:
	/* 0x353: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_35b:
	/* 0x35b: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35f:
	/* 0x35f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_364:
	/* 0x364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366:
	/* 0x366: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_36a:
	/* 0x36a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e:
	/* 0x36e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_372:
	/* 0x372: jne    6ba <do_action+0x6ba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x372, 0x6ba, x86_l_6ba);
x86_l_378:
	/* 0x378: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_37b:
	/* 0x37b: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_37e:
	/* 0x37e: ja     6e1 <do_action+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x37e, 0x6e1, x86_l_6e1);
x86_l_384:
	/* 0x384: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_38d:
	/* 0x38d: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_392:
	/* 0x392: jne    6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x392, 0x6e3, x86_l_6e3);
x86_l_398:
	/* 0x398: mov    rax,QWORD PTR [r13+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_3a0:
	/* 0x3a0: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3a5:
	/* 0x3a5: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3a9:
	/* 0x3a9: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3b0:
	/* 0x3b0: mov    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_3b8:
	/* 0x3b8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3be:
	/* 0x3be: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c2:
	/* 0x3c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c7:
	/* 0x3c7: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3cc:
	/* 0x3cc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3cf:
	/* 0x3cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d1:
	/* 0x3d1: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_3d8:
	/* 0x3d8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3db:
	/* 0x3db: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3de:
	/* 0x3de: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3e3:
	/* 0x3e3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3e6:
	/* 0x3e6: jmp    49b <do_action+0x49b> */
	X86_SIM_X86_JMP(0x3e6, 0x49b, x86_l_49b);
x86_l_3eb:
	/* 0x3eb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3ee:
	/* 0x3ee: mov    ecx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_3f3:
	/* 0x3f3: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3f6:
	/* 0x3f6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f9:
	/* 0x3f9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3fc:
	/* 0x3fc: ja     6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3fc, 0x6e3, x86_l_6e3);
x86_l_402:
	/* 0x402: cmp    DWORD PTR [r13+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_40b:
	/* 0x40b: jne    6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40b, 0x6e3, x86_l_6e3);
x86_l_411:
	/* 0x411: mov    rcx,QWORD PTR [r13+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_419:
	/* 0x419: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_41f:
	/* 0x41f: mov    rcx,QWORD PTR [r13+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_427:
	/* 0x427: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42c:
	/* 0x42c: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_42f:
	/* 0x42f: je     6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42f, 0x6e3, x86_l_6e3);
x86_l_435:
	/* 0x435: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_439:
	/* 0x439: jne    6cb <do_action+0x6cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x439, 0x6cb, x86_l_6cb);
x86_l_43f:
	/* 0x43f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_444:
	/* 0x444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_446:
	/* 0x446: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_449:
	/* 0x449: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_44d:
	/* 0x44d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450:
	/* 0x450: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_457:
	/* 0x457: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_45a:
	/* 0x45a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45f:
	/* 0x45f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461:
	/* 0x461: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_464:
	/* 0x464: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_467:
	/* 0x467: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_46c:
	/* 0x46c: je     6e3 <do_action+0x6e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46c, 0x6e3, x86_l_6e3);
x86_l_472:
	/* 0x472: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_474:
	/* 0x474: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_477:
	/* 0x477: mov    DWORD PTR [rsp+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_47b:
	/* 0x47b: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47f:
	/* 0x47f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_484:
	/* 0x484: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_48b:
	/* 0x48b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48e:
	/* 0x48e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_493:
	/* 0x493: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_496:
	/* 0x496: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_49b:
	/* 0x49b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49d:
	/* 0x49d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f:
	/* 0x49f: jmp    6e1 <do_action+0x6e1> */
	X86_SIM_X86_JMP(0x49f, 0x6e1, x86_l_6e1);
x86_l_4a4:
	/* 0x4a4: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a7:
	/* 0x4a7: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_4ac:
	/* 0x4ac: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4b0:
	/* 0x4b0: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x4b0, 0xa02, x86_l_a02);
x86_l_4b5:
	/* 0x4b5: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ba:
	/* 0x4ba: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bd:
	/* 0x4bd: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x4bd, 0xa02, x86_l_a02);
x86_l_4c2:
	/* 0x4c2: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4c8:
	/* 0x4c8: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4cc:
	/* 0x4cc: xor    r13,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_4d0:
	/* 0x4d0: jmp    9dd <do_action+0x9dd> */
	X86_SIM_X86_JMP(0x4d0, 0x9dd, x86_l_9dd);
x86_l_4d5:
	/* 0x4d5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4da:
	/* 0x4da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4e1:
	/* 0x4e1: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4e8:
	/* 0x4e8: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ed:
	/* 0x4ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f2:
	/* 0x4f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4:
	/* 0x4f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f7:
	/* 0x4f7: je     a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f7, 0xa02, x86_l_a02);
x86_l_4fd:
	/* 0x4fd: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_501:
	/* 0x501: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_506:
	/* 0x506: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_50e:
	/* 0x50e: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_515:
	/* 0x515: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51a:
	/* 0x51a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51f:
	/* 0x51f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_521:
	/* 0x521: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_529:
	/* 0x529: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52c:
	/* 0x52c: je     64b <do_action+0x64b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52c, 0x64b, x86_l_64b);
x86_l_532:
	/* 0x532: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_535:
	/* 0x535: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_53c:
	/* 0x53c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_541:
	/* 0x541: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_546:
	/* 0x546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_548:
	/* 0x548: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x548, 0xa02, x86_l_a02);
x86_l_54d:
	/* 0x54d: mov    QWORD PTR [rsp+0x48],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_552:
	/* 0x552: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_556:
	/* 0x556: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_55b:
	/* 0x55b: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_55f:
	/* 0x55f: mov    ebx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_564:
	/* 0x564: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_569:
	/* 0x569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56b:
	/* 0x56b: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_574:
	/* 0x574: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_57c:
	/* 0x57c: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_581:
	/* 0x581: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_584:
	/* 0x584: je     8b3 <do_action+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x584, 0x8b3, x86_l_8b3);
x86_l_58a:
	/* 0x58a: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_591:
	/* 0x591: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_596:
	/* 0x596: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59b:
	/* 0x59b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59d:
	/* 0x59d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a0:
	/* 0x5a0: je     8b3 <do_action+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a0, 0x8b3, x86_l_8b3);
x86_l_5a6:
	/* 0x5a6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ab:
	/* 0x5ab: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5ae:
	/* 0x5ae: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5b5:
	/* 0x5b5: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5ba:
	/* 0x5ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5bf:
	/* 0x5bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c1:
	/* 0x5c1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5c4:
	/* 0x5c4: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cc:
	/* 0x5cc: mov    rax,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d9:
	/* 0x5d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5db:
	/* 0x5db: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5e0:
	/* 0x5e0: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5e5:
	/* 0x5e5: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5e8:
	/* 0x5e8: je     6f5 <do_action+0x6f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e8, 0x6f5, x86_l_6f5);
x86_l_5ee:
	/* 0x5ee: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_5f1:
	/* 0x5f1: je     6f1 <do_action+0x6f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f1, 0x6f1, x86_l_6f1);
x86_l_5f7:
	/* 0x5f7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_5f9:
	/* 0x5f9: jne    8b3 <do_action+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f9, 0x8b3, x86_l_8b3);
x86_l_5ff:
	/* 0x5ff: mov    eax,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_603:
	/* 0x603: jmp    6f5 <do_action+0x6f5> */
	X86_SIM_X86_JMP(0x603, 0x6f5, x86_l_6f5);
x86_l_608:
	/* 0x608: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_60b:
	/* 0x60b: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_611:
	/* 0x611: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_614:
	/* 0x614: je     9dd <do_action+0x9dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x614, 0x9dd, x86_l_9dd);
x86_l_61a:
	/* 0x61a: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_61d:
	/* 0x61d: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_622:
	/* 0x622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_624:
	/* 0x624: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_62a:
	/* 0x62a: jmp    9dd <do_action+0x9dd> */
	X86_SIM_X86_JMP(0x62a, 0x9dd, x86_l_9dd);
x86_l_62f:
	/* 0x62f: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_632:
	/* 0x632: add    r14d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_636:
	/* 0x636: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_63a:
	/* 0x63a: xor    r13,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_63e:
	/* 0x63e: jmp    9dd <do_action+0x9dd> */
	X86_SIM_X86_JMP(0x63e, 0x9dd, x86_l_9dd);
x86_l_643:
	/* 0x643: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_646:
	/* 0x646: jmp    9dd <do_action+0x9dd> */
	X86_SIM_X86_JMP(0x646, 0x9dd, x86_l_9dd);
x86_l_64b:
	/* 0x64b: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_652:
	/* 0x652: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_657:
	/* 0x657: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_65c:
	/* 0x65c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_661:
	/* 0x661: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_666:
	/* 0x666: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_668:
	/* 0x668: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66b:
	/* 0x66b: je     535 <do_action+0x535> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66b, 0x535, x86_l_535);
x86_l_671:
	/* 0x671: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_674:
	/* 0x674: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_676:
	/* 0x676: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67a:
	/* 0x67a: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_681:
	/* 0x681: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_68b:
	/* 0x68b: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_690:
	/* 0x690: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_697:
	/* 0x697: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_69a:
	/* 0x69a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_69f:
	/* 0x69f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a1:
	/* 0x6a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a4:
	/* 0x6a4: je     951 <do_action+0x951> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a4, 0x951, x86_l_951);
x86_l_6aa:
	/* 0x6aa: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6ac:
	/* 0x6ac: jmp    973 <do_action+0x973> */
	X86_SIM_X86_JMP(0x6ac, 0x973, x86_l_973);
x86_l_6b1:
	/* 0x6b1: or     BYTE PTR [rbx+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_6b5:
	/* 0x6b5: jmp    9d8 <do_action+0x9d8> */
	X86_SIM_X86_JMP(0x6b5, 0x9d8, x86_l_9d8);
x86_l_6ba:
	/* 0x6ba: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6c1:
	/* 0x6c1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6c4:
	/* 0x6c4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6c9:
	/* 0x6c9: jmp    6dc <do_action+0x6dc> */
	X86_SIM_X86_JMP(0x6c9, 0x6dc, x86_l_6dc);
x86_l_6cb:
	/* 0x6cb: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_6d2:
	/* 0x6d2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d7:
	/* 0x6d7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6dc:
	/* 0x6dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6de:
	/* 0x6de: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6e1:
	/* 0x6e1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e3:
	/* 0x6e3: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: jne    a0c <do_action+0xa0c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6e6, 0xa0c, x86_l_a0c);
x86_l_6ec:
	/* 0x6ec: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x6ec, 0xa02, x86_l_a02);
x86_l_6f1:
	/* 0x6f1: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f5:
	/* 0x6f5: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6f7:
	/* 0x6f7: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6fc:
	/* 0x6fc: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_700:
	/* 0x700: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_705:
	/* 0x705: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_709:
	/* 0x709: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_70e:
	/* 0x70e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_713:
	/* 0x713: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_718:
	/* 0x718: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_71d:
	/* 0x71d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71f:
	/* 0x71f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_721:
	/* 0x721: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_726:
	/* 0x726: jmp    736 <do_action+0x736> */
	X86_SIM_X86_JMP(0x726, 0x736, x86_l_736);
x86_l_728:
	/* 0x728: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_72c:
	/* 0x72c: cmp    rbx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 20ULL);
x86_l_730:
	/* 0x730: je     861 <do_action+0x861> */
	X86_SIM_X86_JCC(X86_CC_E, 0x730, 0x861, x86_l_861);
x86_l_736:
	/* 0x736: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_73e:
	/* 0x73e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_743:
	/* 0x743: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_74a:
	/* 0x74a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_74f:
	/* 0x74f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_751:
	/* 0x751: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_754:
	/* 0x754: je     861 <do_action+0x861> */
	X86_SIM_X86_JCC(X86_CC_E, 0x754, 0x861, x86_l_861);
x86_l_75a:
	/* 0x75a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_75d:
	/* 0x75d: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_764:
	/* 0x764: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_769:
	/* 0x769: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_770:
	/* 0x770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_772:
	/* 0x772: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_775:
	/* 0x775: je     861 <do_action+0x861> */
	X86_SIM_X86_JCC(X86_CC_E, 0x775, 0x861, x86_l_861);
x86_l_77b:
	/* 0x77b: cmp    DWORD PTR [rax+rbx*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 279172874239ULL);
x86_l_780:
	/* 0x780: je     861 <do_action+0x861> */
	X86_SIM_X86_JCC(X86_CC_E, 0x780, 0x861, x86_l_861);
x86_l_786:
	/* 0x786: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_78e:
	/* 0x78e: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_792:
	/* 0x792: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_795:
	/* 0x795: jge    861 <do_action+0x861> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x795, 0x861, x86_l_861);
x86_l_79b:
	/* 0x79b: cmp    rbx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 16ULL);
x86_l_79f:
	/* 0x79f: je     801 <do_action+0x801> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79f, 0x801, x86_l_801);
x86_l_7a1:
	/* 0x7a1: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_7a9:
	/* 0x7a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ae:
	/* 0x7ae: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7b5:
	/* 0x7b5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ba:
	/* 0x7ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bc:
	/* 0x7bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7bf:
	/* 0x7bf: je     7f9 <do_action+0x7f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bf, 0x7f9, x86_l_7f9);
x86_l_7c1:
	/* 0x7c1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7c4:
	/* 0x7c4: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_7cb:
	/* 0x7cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d0:
	/* 0x7d0: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_7d7:
	/* 0x7d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d9:
	/* 0x7d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7dc:
	/* 0x7dc: je     7f9 <do_action+0x7f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7dc, 0x7f9, x86_l_7f9);
x86_l_7de:
	/* 0x7de: cmp    DWORD PTR [rax+rbx*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 296352743423ULL);
x86_l_7e3:
	/* 0x7e3: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_7eb:
	/* 0x7eb: je     801 <do_action+0x801> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7eb, 0x801, x86_l_801);
x86_l_7ed:
	/* 0x7ed: mov    ebp,DWORD PTR [r13+rbx*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 1), 24192ULL);
x86_l_7f5:
	/* 0x7f5: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7f7:
	/* 0x7f7: jmp    80a <do_action+0x80a> */
	X86_SIM_X86_JMP(0x7f7, 0x80a, x86_l_80a);
x86_l_7f9:
	/* 0x7f9: mov    rax,QWORD PTR [r13+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_801:
	/* 0x801: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_805:
	/* 0x805: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_807:
	/* 0x807: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_80a:
	/* 0x80a: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_80c:
	/* 0x80c: jle    728 <do_action+0x728> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x80c, 0x728, x86_l_728);
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
	/* 0x81f: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_824:
	/* 0x824: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_827:
	/* 0x827: movzx  r13d,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_82d:
	/* 0x82d: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_832:
	/* 0x832: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_836:
	/* 0x836: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_83b:
	/* 0x83b: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_83f:
	/* 0x83f: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_846:
	/* 0x846: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_84b:
	/* 0x84b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_84d:
	/* 0x84d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84f:
	/* 0x84f: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_852:
	/* 0x852: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_857:
	/* 0x857: mov    QWORD PTR [rsp+0x60],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_85c:
	/* 0x85c: jmp    728 <do_action+0x728> */
	X86_SIM_X86_JMP(0x85c, 0x728, x86_l_728);
x86_l_861:
	/* 0x861: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_868:
	/* 0x868: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86d:
	/* 0x86d: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_872:
	/* 0x872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_874:
	/* 0x874: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_877:
	/* 0x877: je     899 <do_action+0x899> */
	X86_SIM_X86_JCC(X86_CC_E, 0x877, 0x899, x86_l_899);
x86_l_879:
	/* 0x879: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_882:
	/* 0x882: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_887:
	/* 0x887: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_88a:
	/* 0x88a: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_88d:
	/* 0x88d: jbe    899 <do_action+0x899> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x88d, 0x899, x86_l_899);
x86_l_88f:
	/* 0x88f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_894:
	/* 0x894: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_897:
	/* 0x897: jmp    8b3 <do_action+0x8b3> */
	X86_SIM_X86_JMP(0x897, 0x8b3, x86_l_8b3);
x86_l_899:
	/* 0x899: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_8a0:
	/* 0x8a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a2:
	/* 0x8a2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_8a5:
	/* 0x8a5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8aa:
	/* 0x8aa: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8af:
	/* 0x8af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b1:
	/* 0x8b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b3:
	/* 0x8b3: lea    eax,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_8b7:
	/* 0x8b7: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8bd:
	/* 0x8bd: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8c2:
	/* 0x8c2: je     8e5 <do_action+0x8e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c2, 0x8e5, x86_l_8e5);
x86_l_8c4:
	/* 0x8c4: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_8c9:
	/* 0x8c9: mov    rsi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8d0:
	/* 0x8d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d2:
	/* 0x8d2: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8d7:
	/* 0x8d7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8da:
	/* 0x8da: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8dc:
	/* 0x8dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8de:
	/* 0x8de: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8e5:
	/* 0x8e5: lea    eax,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8e9:
	/* 0x8e9: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8ef:
	/* 0x8ef: je     918 <do_action+0x918> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ef, 0x918, x86_l_918);
x86_l_8f1:
	/* 0x8f1: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_8f6:
	/* 0x8f6: mov    rsi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8fd:
	/* 0x8fd: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_902:
	/* 0x902: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_907:
	/* 0x907: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_90c:
	/* 0x90c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_90f:
	/* 0x90f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_911:
	/* 0x911: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_918:
	/* 0x918: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_91c:
	/* 0x91c: cmp    DWORD PTR [r15+r14*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 17179869184ULL);
x86_l_922:
	/* 0x922: je     a02 <do_action+0xa02> */
	X86_SIM_X86_JCC(X86_CC_E, 0x922, 0xa02, x86_l_a02);
x86_l_928:
	/* 0x928: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_92d:
	/* 0x92d: jmp    a02 <do_action+0xa02> */
	X86_SIM_X86_JMP(0x92d, 0xa02, x86_l_a02);
x86_l_932:
	/* 0x932: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_939:
	/* 0x939: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93b:
	/* 0x93b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_940:
	/* 0x940: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_943:
	/* 0x943: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_948:
	/* 0x948: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94a:
	/* 0x94a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94c:
	/* 0x94c: jmp    9d8 <do_action+0x9d8> */
	X86_SIM_X86_JMP(0x94c, 0x9d8, x86_l_9d8);
x86_l_951:
	/* 0x951: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_959:
	/* 0x959: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_960:
	/* 0x960: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_962:
	/* 0x962: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_965:
	/* 0x965: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_96a:
	/* 0x96a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_96f:
	/* 0x96f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_971:
	/* 0x971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_973:
	/* 0x973: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_976:
	/* 0x976: je     535 <do_action+0x535> */
	X86_SIM_X86_JCC(X86_CC_E, 0x976, 0x535, x86_l_535);
x86_l_97c:
	/* 0x97c: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_983:
	/* 0x983: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_988:
	/* 0x988: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_98d:
	/* 0x98d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98f:
	/* 0x98f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_992:
	/* 0x992: je     535 <do_action+0x535> */
	X86_SIM_X86_JCC(X86_CC_E, 0x992, 0x535, x86_l_535);
x86_l_998:
	/* 0x998: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_99c:
	/* 0x99c: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_99f:
	/* 0x99f: jmp    535 <do_action+0x535> */
	X86_SIM_X86_JMP(0x99f, 0x535, x86_l_535);
x86_l_9a4:
	/* 0x9a4: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_9ac:
	/* 0x9ac: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9b3:
	/* 0x9b3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b5:
	/* 0x9b5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ba:
	/* 0x9ba: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9bf:
	/* 0x9bf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9c4:
	/* 0x9c4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c6:
	/* 0x9c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c8:
	/* 0x9c8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9cc:
	/* 0x9cc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d1:
	/* 0x9d1: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d5:
	/* 0x9d5: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d8:
	/* 0x9d8: mov    r14d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9dd:
	/* 0x9dd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e4:
	/* 0x9e4: mov    rdi,QWORD PTR [rip+0x2777] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_9eb:
	/* 0x9eb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9ee:
	/* 0x9ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f3:
	/* 0x9f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f5:
	/* 0x9f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9f8:
	/* 0x9f8: je     9ff <do_action+0x9ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f8, 0x9ff, x86_l_9ff);
x86_l_9fa:
	/* 0x9fa: inc QWORD PTR [rax+r13*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R13, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9ff:
	/* 0x9ff: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_a02:
	/* 0xa02: mov    QWORD PTR [r13+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a06:
	/* 0xa06: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a09:
	/* 0xa09: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a0c:
	/* 0xa0c: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_a10:
	/* 0xa10: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_a12:
	/* 0xa12: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_a13:
	/* 0xa13: jmp    b2e <read_reg+0x116> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b2e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_a18 */
x86_l_a18:
	/* 0xa18: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_a1e:
	/* 0xa1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a20:
	/* 0xa20: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_a23:
	/* 0xa23: jle    a5a <read_reg+0x42> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa23, 0xa5a, x86_l_a5a);
x86_l_a25:
	/* 0xa25: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_a28:
	/* 0xa28: jle    a7e <read_reg+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa28, 0xa7e, x86_l_a7e);
x86_l_a2a:
	/* 0xa2a: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_a2d:
	/* 0xa2d: jle    ae3 <read_reg+0xcb> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa2d, 0xae3, x86_l_ae3);
x86_l_a33:
	/* 0xa33: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_a36:
	/* 0xa36: je     b17 <read_reg+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa36, 0xb17, x86_l_b17);
x86_l_a3c:
	/* 0xa3c: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a3f:
	/* 0xa3f: je     aff <read_reg+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa3f, 0xaff, x86_l_aff);
x86_l_a45:
	/* 0xa45: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_a48:
	/* 0xa48: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa48, 0xb2d, x86_l_b2d);
x86_l_a4e:
	/* 0xa4e: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_a55:
	/* 0xa55: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa55, 0xb21, x86_l_b21);
x86_l_a5a:
	/* 0xa5a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a5d:
	/* 0xa5d: jg     a9a <read_reg+0x82> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa5d, 0xa9a, x86_l_a9a);
x86_l_a5f:
	/* 0xa5f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a62:
	/* 0xa62: jg     ac3 <read_reg+0xab> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa62, 0xac3, x86_l_ac3);
x86_l_a64:
	/* 0xa64: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_a66:
	/* 0xa66: je     b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa66, 0xb21, x86_l_b21);
x86_l_a6c:
	/* 0xa6c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a6f:
	/* 0xa6f: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa6f, 0xb2d, x86_l_b2d);
x86_l_a75:
	/* 0xa75: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a79:
	/* 0xa79: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa79, 0xb21, x86_l_b21);
x86_l_a7e:
	/* 0xa7e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a81:
	/* 0xa81: jg     ab3 <read_reg+0x9b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa81, 0xab3, x86_l_ab3);
x86_l_a83:
	/* 0xa83: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a86:
	/* 0xa86: je     af3 <read_reg+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa86, 0xaf3, x86_l_af3);
x86_l_a88:
	/* 0xa88: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a8b:
	/* 0xa8b: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xa8b, 0xb2d, x86_l_b2d);
x86_l_a91:
	/* 0xa91: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_a95:
	/* 0xa95: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xa95, 0xb21, x86_l_b21);
x86_l_a9a:
	/* 0xa9a: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a9d:
	/* 0xa9d: jg     ad3 <read_reg+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0xa9d, 0xad3, x86_l_ad3);
x86_l_a9f:
	/* 0xa9f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_aa2:
	/* 0xaa2: je     b05 <read_reg+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaa2, 0xb05, x86_l_b05);
x86_l_aa4:
	/* 0xaa4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_aa7:
	/* 0xaa7: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xaa7, 0xb2d, x86_l_b2d);
x86_l_aad:
	/* 0xaad: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_ab1:
	/* 0xab1: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xab1, 0xb21, x86_l_b21);
x86_l_ab3:
	/* 0xab3: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ab6:
	/* 0xab6: je     af9 <read_reg+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xab6, 0xaf9, x86_l_af9);
x86_l_ab8:
	/* 0xab8: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_abb:
	/* 0xabb: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xabb, 0xb2d, x86_l_b2d);
x86_l_abd:
	/* 0xabd: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_ac1:
	/* 0xac1: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xac1, 0xb21, x86_l_b21);
x86_l_ac3:
	/* 0xac3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ac6:
	/* 0xac6: je     b0b <read_reg+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xac6, 0xb0b, x86_l_b0b);
x86_l_ac8:
	/* 0xac8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_acb:
	/* 0xacb: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xacb, 0xb2d, x86_l_b2d);
x86_l_acd:
	/* 0xacd: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_ad1:
	/* 0xad1: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xad1, 0xb21, x86_l_b21);
x86_l_ad3:
	/* 0xad3: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ad6:
	/* 0xad6: je     b11 <read_reg+0xf9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xad6, 0xb11, x86_l_b11);
x86_l_ad8:
	/* 0xad8: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_adb:
	/* 0xadb: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xadb, 0xb2d, x86_l_b2d);
x86_l_add:
	/* 0xadd: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_ae1:
	/* 0xae1: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xae1, 0xb21, x86_l_b21);
x86_l_ae3:
	/* 0xae3: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_ae6:
	/* 0xae6: je     b1d <read_reg+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xae6, 0xb1d, x86_l_b1d);
x86_l_ae8:
	/* 0xae8: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_aeb:
	/* 0xaeb: jne    b2d <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xaeb, 0xb2d, x86_l_b2d);
x86_l_aed:
	/* 0xaed: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_af1:
	/* 0xaf1: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaf1, 0xb21, x86_l_b21);
x86_l_af3:
	/* 0xaf3: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_af7:
	/* 0xaf7: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xaf7, 0xb21, x86_l_b21);
x86_l_af9:
	/* 0xaf9: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_afd:
	/* 0xafd: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xafd, 0xb21, x86_l_b21);
x86_l_aff:
	/* 0xaff: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_b03:
	/* 0xb03: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb03, 0xb21, x86_l_b21);
x86_l_b05:
	/* 0xb05: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b09:
	/* 0xb09: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb09, 0xb21, x86_l_b21);
x86_l_b0b:
	/* 0xb0b: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b0f:
	/* 0xb0f: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb0f, 0xb21, x86_l_b21);
x86_l_b11:
	/* 0xb11: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b15:
	/* 0xb15: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb15, 0xb21, x86_l_b21);
x86_l_b17:
	/* 0xb17: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_b1b:
	/* 0xb1b: jmp    b21 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0xb1b, 0xb21, x86_l_b21);
x86_l_b1d:
	/* 0xb1d: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_b21:
	/* 0xb21: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_b26:
	/* 0xb26: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b28:
	/* 0xb28: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_b2d:
	/* 0xb2d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x3aULL: goto x86_l_3a;
	case 0x129ULL: goto x86_l_129;
	case 0x142ULL: goto x86_l_142;
	case 0x192ULL: goto x86_l_192;
	case 0x1b2ULL: goto x86_l_1b2;
	case 0x21bULL: goto x86_l_21b;
	case 0x258ULL: goto x86_l_258;
	case 0x26fULL: goto x86_l_26f;
	case 0x287ULL: goto x86_l_287;
	case 0x2b7ULL: goto x86_l_2b7;
	case 0x30dULL: goto x86_l_30d;
	case 0x366ULL: goto x86_l_366;
	case 0x3d1ULL: goto x86_l_3d1;
	case 0x446ULL: goto x86_l_446;
	case 0x461ULL: goto x86_l_461;
	case 0x49fULL: goto x86_l_49f;
	case 0x4dcULL: goto x86_l_4dc;
	case 0x4f4ULL: goto x86_l_4f4;
	case 0x521ULL: goto x86_l_521;
	case 0x548ULL: goto x86_l_548;
	case 0x56bULL: goto x86_l_56b;
	case 0x59dULL: goto x86_l_59d;
	case 0x5c1ULL: goto x86_l_5c1;
	case 0x624ULL: goto x86_l_624;
	case 0x668ULL: goto x86_l_668;
	case 0x6a1ULL: goto x86_l_6a1;
	case 0x6deULL: goto x86_l_6de;
	case 0x71fULL: goto x86_l_71f;
	case 0x751ULL: goto x86_l_751;
	case 0x772ULL: goto x86_l_772;
	case 0x7bcULL: goto x86_l_7bc;
	case 0x7d9ULL: goto x86_l_7d9;
	case 0x84fULL: goto x86_l_84f;
	case 0x874ULL: goto x86_l_874;
	case 0x8b3ULL: goto x86_l_8b3;
	case 0x8deULL: goto x86_l_8de;
	case 0x911ULL: goto x86_l_911;
	case 0x94cULL: goto x86_l_94c;
	case 0x973ULL: goto x86_l_973;
	case 0x98fULL: goto x86_l_98f;
	case 0x9c8ULL: goto x86_l_9c8;
	case 0x9f5ULL: goto x86_l_9f5;
	}

}

X86_SIM_LICENSE();
