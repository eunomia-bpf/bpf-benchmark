extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char heap;
extern char heap_ro_zero;
extern char override_tasks;
extern char policy_stats;
extern char process_call_heap;
extern char ratelimit_heap;
extern char ratelimit_map;
extern char socktrack_map;
extern char stack_trace_map;
extern char tg_errmetrics_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_lsm_core_v61_do_action_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x11: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16:
	/* 0x16: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_19:
	/* 0x19: mov    ebx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_32);
x86_l_1b:
	/* 0x1b: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_20:
	/* 0x20: movsxd r14,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_25:
	/* 0x25: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_2d:
	/* 0x2d: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_34:
	/* 0x34: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_39:
	/* 0x39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45:
	/* 0x45: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_48:
	/* 0x48: je     915 <do_action+0x915> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48, 0x915, x86_l_915);
x86_l_4e:
	/* 0x4e: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_52:
	/* 0x52: jg     7c <do_action+0x7c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x52, 0x7c, x86_l_7c);
x86_l_54:
	/* 0x54: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_58:
	/* 0x58: jg     b3 <do_action+0xb3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x58, 0xb3, x86_l_b3);
x86_l_5a:
	/* 0x5a: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_5e:
	/* 0x5e: jg     1e5 <do_action+0x1e5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5e, 0x1e5, x86_l_1e5);
x86_l_64:
	/* 0x64: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_67:
	/* 0x67: je     4f3 <do_action+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67, 0x4f3, x86_l_4f3);
x86_l_6d:
	/* 0x6d: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_71:
	/* 0x71: je     1fe <do_action+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71, 0x1fe, x86_l_1fe);
x86_l_77:
	/* 0x77: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x77, 0x90d, x86_l_90d);
x86_l_7c:
	/* 0x7c: cmp    r14d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 11ULL);
x86_l_80:
	/* 0x80: jg     1b7 <do_action+0x1b7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x80, 0x1b7, x86_l_1b7);
x86_l_86:
	/* 0x86: lea    ecx,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_8a:
	/* 0x8a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8d:
	/* 0x8d: jb     309 <do_action+0x309> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8d, 0x309, x86_l_309);
x86_l_93:
	/* 0x93: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_97:
	/* 0x97: je     3f6 <do_action+0x3f6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97, 0x3f6, x86_l_3f6);
x86_l_9d:
	/* 0x9d: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_a1:
	/* 0xa1: jne    90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa1, 0x90d, x86_l_90d);
x86_l_a7:
	/* 0xa7: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a9:
	/* 0xa9: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_ae:
	/* 0xae: jmp    3c2 <do_action+0x3c2> */
	X86_SIM_X86_JMP(0xae, 0x3c2, x86_l_3c2);
x86_l_b3:
	/* 0xb3: lea    eax,[r14-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_b7:
	/* 0xb7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ba:
	/* 0xba: jb     3e6 <do_action+0x3e6> */
	X86_SIM_X86_JCC(X86_CC_B, 0xba, 0x3e6, x86_l_3e6);
x86_l_c0:
	/* 0xc0: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_c4:
	/* 0xc4: je     403 <do_action+0x403> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4, 0x403, x86_l_403);
x86_l_ca:
	/* 0xca: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_ce:
	/* 0xce: jne    90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce, 0x90d, x86_l_90d);
x86_l_d4:
	/* 0xd4: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_d7:
	/* 0xd7: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_dc:
	/* 0xdc: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_df:
	/* 0xdf: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e2:
	/* 0xe2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e5:
	/* 0xe5: ja     90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe5, 0x90d, x86_l_90d);
x86_l_eb:
	/* 0xeb: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_f4:
	/* 0xf4: jne    90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf4, 0x90d, x86_l_90d);
x86_l_fa:
	/* 0xfa: mov    r15d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_ff:
	/* 0xff: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_107:
	/* 0x107: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_10f:
	/* 0x10f: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_114:
	/* 0x114: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120:
	/* 0x120: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_125:
	/* 0x125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127:
	/* 0x127: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_12b:
	/* 0x12b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f:
	/* 0x12f: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_136:
	/* 0x136: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_139:
	/* 0x139: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e:
	/* 0x13e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140:
	/* 0x140: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_143:
	/* 0x143: je     90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x143, 0x90d, x86_l_90d);
x86_l_149:
	/* 0x149: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_14d:
	/* 0x14d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_151:
	/* 0x151: ja     90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x151, 0x90d, x86_l_90d);
x86_l_157:
	/* 0x157: cmp    DWORD PTR [r13+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_160:
	/* 0x160: jne    90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x160, 0x90d, x86_l_90d);
x86_l_166:
	/* 0x166: mov    rcx,QWORD PTR [r13+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
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
	/* 0x19a: mov    rdi,QWORD PTR [rip+0x2770] */
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
	/* 0x1b2: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x1b2, 0x90d, x86_l_90d);
x86_l_1b7:
	/* 0x1b7: cmp    r14d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 12ULL);
x86_l_1bb:
	/* 0x1bb: je     5af <do_action+0x5af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bb, 0x5af, x86_l_5af);
x86_l_1c1:
	/* 0x1c1: cmp    r14d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 13ULL);
x86_l_1c5:
	/* 0x1c5: je     47b <do_action+0x47b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c5, 0x47b, x86_l_47b);
x86_l_1cb:
	/* 0x1cb: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_1cf:
	/* 0x1cf: jne    90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cf, 0x90d, x86_l_90d);
x86_l_1d5:
	/* 0x1d5: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1d8:
	/* 0x1d8: movzx  r12d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1dc:
	/* 0x1dc: xor    r12,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_1e0:
	/* 0x1e0: jmp    67f <do_action+0x67f> */
	X86_SIM_X86_JMP(0x1e0, 0x67f, x86_l_67f);
x86_l_1e5:
	/* 0x1e5: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1ea:
	/* 0x1ea: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1ee:
	/* 0x1ee: je     3c2 <do_action+0x3c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ee, 0x3c2, x86_l_3c2);
x86_l_1f4:
	/* 0x1f4: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_1f8:
	/* 0x1f8: jne    90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f8, 0x90d, x86_l_90d);
x86_l_1fe:
	/* 0x1fe: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_201:
	/* 0x201: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_206:
	/* 0x206: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_209:
	/* 0x209: mov    r12d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_20e:
	/* 0x20e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_216:
	/* 0x216: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_21d:
	/* 0x21d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222:
	/* 0x222: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_227:
	/* 0x227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229:
	/* 0x229: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22c:
	/* 0x22c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f:
	/* 0x22f: je     6c0 <do_action+0x6c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22f, 0x6c0, x86_l_6c0);
x86_l_235:
	/* 0x235: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23a:
	/* 0x23a: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_23d:
	/* 0x23d: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_240:
	/* 0x240: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_245:
	/* 0x245: ja     6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x245, 0x6c2, x86_l_6c2);
x86_l_24b:
	/* 0x24b: cmp    DWORD PTR [r13+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_254:
	/* 0x254: jne    6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x254, 0x6c2, x86_l_6c2);
x86_l_25a:
	/* 0x25a: mov    rax,QWORD PTR [r13+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_262:
	/* 0x262: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_26a:
	/* 0x26a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_26f:
	/* 0x26f: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_277:
	/* 0x277: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b:
	/* 0x27b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_280:
	/* 0x280: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282:
	/* 0x282: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_286:
	/* 0x286: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a:
	/* 0x28a: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_28e:
	/* 0x28e: jne    643 <do_action+0x643> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x28e, 0x643, x86_l_643);
x86_l_294:
	/* 0x294: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_298:
	/* 0x298: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_29c:
	/* 0x29c: ja     6c0 <do_action+0x6c0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29c, 0x6c0, x86_l_6c0);
x86_l_2a2:
	/* 0x2a2: cmp    DWORD PTR [r13+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_2ab:
	/* 0x2ab: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2b0:
	/* 0x2b0: jne    6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b0, 0x6c2, x86_l_6c2);
x86_l_2b6:
	/* 0x2b6: mov    rax,QWORD PTR [r13+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_2be:
	/* 0x2be: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2c3:
	/* 0x2c3: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2c7:
	/* 0x2c7: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2ce:
	/* 0x2ce: mov    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_2d6:
	/* 0x2d6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2dc:
	/* 0x2dc: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e0:
	/* 0x2e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e5:
	/* 0x2e5: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ea:
	/* 0x2ea: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2ed:
	/* 0x2ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef:
	/* 0x2ef: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2f6:
	/* 0x2f6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f9:
	/* 0x2f9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2fc:
	/* 0x2fc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_301:
	/* 0x301: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_304:
	/* 0x304: jmp    3b9 <do_action+0x3b9> */
	X86_SIM_X86_JMP(0x304, 0x3b9, x86_l_3b9);
x86_l_309:
	/* 0x309: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30b:
	/* 0x30b: mov    ecx,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_310:
	/* 0x310: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_313:
	/* 0x313: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_316:
	/* 0x316: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_319:
	/* 0x319: ja     6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x319, 0x6c2, x86_l_6c2);
x86_l_31f:
	/* 0x31f: cmp    DWORD PTR [r13+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_328:
	/* 0x328: jne    6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x328, 0x6c2, x86_l_6c2);
x86_l_32e:
	/* 0x32e: mov    rcx,QWORD PTR [r13+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_336:
	/* 0x336: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_33c:
	/* 0x33c: mov    rcx,QWORD PTR [r13+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_349:
	/* 0x349: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_34c:
	/* 0x34c: je     6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34c, 0x6c2, x86_l_6c2);
x86_l_352:
	/* 0x352: cmp    r14d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 10ULL);
x86_l_356:
	/* 0x356: jne    6aa <do_action+0x6aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x356, 0x6aa, x86_l_6aa);
x86_l_35c:
	/* 0x35c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_361:
	/* 0x361: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363:
	/* 0x363: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_366:
	/* 0x366: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_36a:
	/* 0x36a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36d:
	/* 0x36d: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_374:
	/* 0x374: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_377:
	/* 0x377: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37c:
	/* 0x37c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37e:
	/* 0x37e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_381:
	/* 0x381: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_384:
	/* 0x384: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_389:
	/* 0x389: je     6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x389, 0x6c2, x86_l_6c2);
x86_l_38f:
	/* 0x38f: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_391:
	/* 0x391: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_394:
	/* 0x394: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_399:
	/* 0x399: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a2:
	/* 0x3a2: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_3a9:
	/* 0x3a9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ac:
	/* 0x3ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b1:
	/* 0x3b1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3b4:
	/* 0x3b4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3b9:
	/* 0x3b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bb:
	/* 0x3bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd:
	/* 0x3bd: jmp    6c0 <do_action+0x6c0> */
	X86_SIM_X86_JMP(0x3bd, 0x6c0, x86_l_6c0);
x86_l_3c2:
	/* 0x3c2: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3c8:
	/* 0x3c8: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_3cb:
	/* 0x3cb: je     67f <do_action+0x67f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cb, 0x67f, x86_l_67f);
x86_l_3d1:
	/* 0x3d1: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3d4:
	/* 0x3d4: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_3d9:
	/* 0x3d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db:
	/* 0x3db: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3e1:
	/* 0x3e1: jmp    67f <do_action+0x67f> */
	X86_SIM_X86_JMP(0x3e1, 0x67f, x86_l_67f);
x86_l_3e6:
	/* 0x3e6: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3e8:
	/* 0x3e8: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_3ed:
	/* 0x3ed: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3f1:
	/* 0x3f1: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x3f1, 0x90d, x86_l_90d);
x86_l_3f6:
	/* 0x3f6: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3fb:
	/* 0x3fb: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe:
	/* 0x3fe: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x3fe, 0x90d, x86_l_90d);
x86_l_403:
	/* 0x403: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_405:
	/* 0x405: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_40b:
	/* 0x40b: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_40e:
	/* 0x40e: je     67f <do_action+0x67f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40e, 0x67f, x86_l_67f);
x86_l_414:
	/* 0x414: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_416:
	/* 0x416: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_41b:
	/* 0x41b: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_41f:
	/* 0x41f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_424:
	/* 0x424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42b:
	/* 0x42b: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_432:
	/* 0x432: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_437:
	/* 0x437: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_43c:
	/* 0x43c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43e:
	/* 0x43e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_441:
	/* 0x441: je     625 <do_action+0x625> */
	X86_SIM_X86_JCC(X86_CC_E, 0x441, 0x625, x86_l_625);
x86_l_447:
	/* 0x447: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_44a:
	/* 0x44a: mov    DWORD PTR [rsp],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 917521ULL);
x86_l_451:
	/* 0x451: mov    QWORD PTR [rsp+0x4],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179870047ULL);
x86_l_45a:
	/* 0x45a: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_461:
	/* 0x461: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_464:
	/* 0x464: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_469:
	/* 0x469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46b:
	/* 0x46b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46e:
	/* 0x46e: je     654 <do_action+0x654> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46e, 0x654, x86_l_654);
x86_l_474:
	/* 0x474: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_476:
	/* 0x476: jmp    676 <do_action+0x676> */
	X86_SIM_X86_JMP(0x476, 0x676, x86_l_676);
x86_l_47b:
	/* 0x47b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_480:
	/* 0x480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_482:
	/* 0x482: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_487:
	/* 0x487: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_48e:
	/* 0x48e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_493:
	/* 0x493: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_498:
	/* 0x498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49a:
	/* 0x49a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49d:
	/* 0x49d: je     90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49d, 0x90d, x86_l_90d);
x86_l_4a3:
	/* 0x4a3: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a7:
	/* 0x4a7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ac:
	/* 0x4ac: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_4b4:
	/* 0x4b4: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_4bb:
	/* 0x4bb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c0:
	/* 0x4c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c5:
	/* 0x4c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c7:
	/* 0x4c7: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_4cf:
	/* 0x4cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d2:
	/* 0x4d2: je     5bf <do_action+0x5bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d2, 0x5bf, x86_l_5bf);
x86_l_4d8:
	/* 0x4d8: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4db:
	/* 0x4db: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4e2:
	/* 0x4e2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e7:
	/* 0x4e7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4ec:
	/* 0x4ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ee:
	/* 0x4ee: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x4ee, 0x90d, x86_l_90d);
x86_l_4f3:
	/* 0x4f3: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4f6:
	/* 0x4f6: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_4fb:
	/* 0x4fb: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_4fe:
	/* 0x4fe: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_503:
	/* 0x503: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_507:
	/* 0x507: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_50c:
	/* 0x50c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e:
	/* 0x50e: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_517:
	/* 0x517: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_51f:
	/* 0x51f: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_524:
	/* 0x524: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_527:
	/* 0x527: je     89f <do_action+0x89f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x527, 0x89f, x86_l_89f);
x86_l_52d:
	/* 0x52d: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_534:
	/* 0x534: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_539:
	/* 0x539: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53e:
	/* 0x53e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_540:
	/* 0x540: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_543:
	/* 0x543: je     89f <do_action+0x89f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x543, 0x89f, x86_l_89f);
x86_l_549:
	/* 0x549: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_54e:
	/* 0x54e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_551:
	/* 0x551: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_558:
	/* 0x558: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55d:
	/* 0x55d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_562:
	/* 0x562: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564:
	/* 0x564: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_567:
	/* 0x567: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_56b:
	/* 0x56b: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56f:
	/* 0x56f: mov    rax,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_573:
	/* 0x573: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57c:
	/* 0x57c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57e:
	/* 0x57e: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_583:
	/* 0x583: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_588:
	/* 0x588: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_58c:
	/* 0x58c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_58f:
	/* 0x58f: je     6d4 <do_action+0x6d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58f, 0x6d4, x86_l_6d4);
x86_l_595:
	/* 0x595: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_598:
	/* 0x598: je     6d0 <do_action+0x6d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x598, 0x6d0, x86_l_6d0);
x86_l_59e:
	/* 0x59e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5a0:
	/* 0x5a0: jne    89f <do_action+0x89f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a0, 0x89f, x86_l_89f);
x86_l_5a6:
	/* 0x5a6: mov    eax,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_5aa:
	/* 0x5aa: jmp    6d4 <do_action+0x6d4> */
	X86_SIM_X86_JMP(0x5aa, 0x6d4, x86_l_6d4);
x86_l_5af:
	/* 0x5af: add    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5b2:
	/* 0x5b2: movzx  r12d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b6:
	/* 0x5b6: xor    r12,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_5ba:
	/* 0x5ba: jmp    67f <do_action+0x67f> */
	X86_SIM_X86_JMP(0x5ba, 0x67f, x86_l_67f);
x86_l_5bf:
	/* 0x5bf: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_5c6:
	/* 0x5c6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cb:
	/* 0x5cb: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5d0:
	/* 0x5d0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5d5:
	/* 0x5d5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5da:
	/* 0x5da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dc:
	/* 0x5dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5df:
	/* 0x5df: je     4db <do_action+0x4db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5df, 0x4db, x86_l_4db);
x86_l_5e5:
	/* 0x5e5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5e8:
	/* 0x5e8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5ea:
	/* 0x5ea: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ee:
	/* 0x5ee: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_5f5:
	/* 0x5f5: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_5ff:
	/* 0x5ff: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_604:
	/* 0x604: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_60b:
	/* 0x60b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_613:
	/* 0x613: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_615:
	/* 0x615: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_618:
	/* 0x618: je     928 <do_action+0x928> */
	X86_SIM_X86_JCC(X86_CC_E, 0x618, 0x928, x86_l_928);
x86_l_61e:
	/* 0x61e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_620:
	/* 0x620: jmp    94a <do_action+0x94a> */
	X86_SIM_X86_JMP(0x620, 0x94a, x86_l_94a);
x86_l_625:
	/* 0x625: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_62c:
	/* 0x62c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62e:
	/* 0x62e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_633:
	/* 0x633: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_638:
	/* 0x638: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_63d:
	/* 0x63d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63f:
	/* 0x63f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_641:
	/* 0x641: jmp    679 <do_action+0x679> */
	X86_SIM_X86_JMP(0x641, 0x679, x86_l_679);
x86_l_643:
	/* 0x643: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_64a:
	/* 0x64a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_64d:
	/* 0x64d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_652:
	/* 0x652: jmp    6bb <do_action+0x6bb> */
	X86_SIM_X86_JMP(0x652, 0x6bb, x86_l_6bb);
x86_l_654:
	/* 0x654: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_65c:
	/* 0x65c: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_663:
	/* 0x663: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_665:
	/* 0x665: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_668:
	/* 0x668: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66d:
	/* 0x66d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_672:
	/* 0x672: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: mov    DWORD PTR [r15],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_679:
	/* 0x679: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_67f:
	/* 0x67f: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_686:
	/* 0x686: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_68d:
	/* 0x68d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_690:
	/* 0x690: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_695:
	/* 0x695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_697:
	/* 0x697: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_69a:
	/* 0x69a: je     90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69a, 0x90d, x86_l_90d);
x86_l_6a0:
	/* 0x6a0: inc QWORD PTR [rax+r12*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R12, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6a5:
	/* 0x6a5: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x6a5, 0x90d, x86_l_90d);
x86_l_6aa:
	/* 0x6aa: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_6b1:
	/* 0x6b1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b6:
	/* 0x6b6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6bb:
	/* 0x6bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bd:
	/* 0x6bd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6c0:
	/* 0x6c0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c2:
	/* 0x6c2: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_6c5:
	/* 0x6c5: jne    915 <do_action+0x915> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6c5, 0x915, x86_l_915);
x86_l_6cb:
	/* 0x6cb: jmp    90d <do_action+0x90d> */
	X86_SIM_X86_JMP(0x6cb, 0x90d, x86_l_90d);
x86_l_6d0:
	/* 0x6d0: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d4:
	/* 0x6d4: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d9:
	/* 0x6d9: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6db:
	/* 0x6db: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6e0:
	/* 0x6e0: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e4:
	/* 0x6e4: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e9:
	/* 0x6e9: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_6ed:
	/* 0x6ed: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_6f2:
	/* 0x6f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f7:
	/* 0x6f7: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6fc:
	/* 0x6fc: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_701:
	/* 0x701: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_703:
	/* 0x703: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_706:
	/* 0x706: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_70b:
	/* 0x70b: jmp    71b <do_action+0x71b> */
	X86_SIM_X86_JMP(0x70b, 0x71b, x86_l_71b);
x86_l_70d:
	/* 0x70d: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_711:
	/* 0x711: cmp    r12,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 20ULL);
x86_l_715:
	/* 0x715: je     848 <do_action+0x848> */
	X86_SIM_X86_JCC(X86_CC_E, 0x715, 0x848, x86_l_848);
x86_l_71b:
	/* 0x71b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_723:
	/* 0x723: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_728:
	/* 0x728: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_72f:
	/* 0x72f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_734:
	/* 0x734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_736:
	/* 0x736: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_739:
	/* 0x739: je     848 <do_action+0x848> */
	X86_SIM_X86_JCC(X86_CC_E, 0x739, 0x848, x86_l_848);
x86_l_73f:
	/* 0x73f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_742:
	/* 0x742: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_749:
	/* 0x749: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_74e:
	/* 0x74e: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_755:
	/* 0x755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_757:
	/* 0x757: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75a:
	/* 0x75a: je     848 <do_action+0x848> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75a, 0x848, x86_l_848);
x86_l_760:
	/* 0x760: cmp    DWORD PTR [rax+r12*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 279172874239ULL);
x86_l_766:
	/* 0x766: je     848 <do_action+0x848> */
	X86_SIM_X86_JCC(X86_CC_E, 0x766, 0x848, x86_l_848);
x86_l_76c:
	/* 0x76c: mov    rax,QWORD PTR [r13+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_774:
	/* 0x774: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_778:
	/* 0x778: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_77b:
	/* 0x77b: jge    848 <do_action+0x848> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x77b, 0x848, x86_l_848);
x86_l_781:
	/* 0x781: cmp    r12,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 16ULL);
x86_l_785:
	/* 0x785: je     7e8 <do_action+0x7e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x785, 0x7e8, x86_l_7e8);
x86_l_787:
	/* 0x787: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_78f:
	/* 0x78f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_794:
	/* 0x794: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_79b:
	/* 0x79b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a0:
	/* 0x7a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a2:
	/* 0x7a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: je     7e0 <do_action+0x7e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a5, 0x7e0, x86_l_7e0);
x86_l_7a7:
	/* 0x7a7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_7b1:
	/* 0x7b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_7bd:
	/* 0x7bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bf:
	/* 0x7bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c2:
	/* 0x7c2: je     7e0 <do_action+0x7e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c2, 0x7e0, x86_l_7e0);
x86_l_7c4:
	/* 0x7c4: cmp    DWORD PTR [rax+r12*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 296352743423ULL);
x86_l_7ca:
	/* 0x7ca: mov    rax,QWORD PTR [r13+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_7d2:
	/* 0x7d2: je     7e8 <do_action+0x7e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d2, 0x7e8, x86_l_7e8);
x86_l_7d4:
	/* 0x7d4: mov    ebp,DWORD PTR [r13+r12*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 1), 24192ULL);
x86_l_7dc:
	/* 0x7dc: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7de:
	/* 0x7de: jmp    7f1 <do_action+0x7f1> */
	X86_SIM_X86_JMP(0x7de, 0x7f1, x86_l_7f1);
x86_l_7e0:
	/* 0x7e0: mov    rax,QWORD PTR [r13+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_7e8:
	/* 0x7e8: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7ec:
	/* 0x7ec: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7ee:
	/* 0x7ee: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_7f1:
	/* 0x7f1: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_7f3:
	/* 0x7f3: jle    70d <do_action+0x70d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x7f3, 0x70d, x86_l_70d);
x86_l_7f9:
	/* 0x7f9: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_7fe:
	/* 0x7fe: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_803:
	/* 0x803: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_806:
	/* 0x806: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_80b:
	/* 0x80b: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_80e:
	/* 0x80e: movzx  r13d,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_814:
	/* 0x814: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_819:
	/* 0x819: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_81d:
	/* 0x81d: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_822:
	/* 0x822: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_826:
	/* 0x826: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_82d:
	/* 0x82d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_832:
	/* 0x832: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_834:
	/* 0x834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_836:
	/* 0x836: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_839:
	/* 0x839: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_83e:
	/* 0x83e: mov    QWORD PTR [rsp+0x60],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_843:
	/* 0x843: jmp    70d <do_action+0x70d> */
	X86_SIM_X86_JMP(0x843, 0x70d, x86_l_70d);
x86_l_848:
	/* 0x848: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_84f:
	/* 0x84f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_854:
	/* 0x854: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_859:
	/* 0x859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85b:
	/* 0x85b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85e:
	/* 0x85e: je     880 <do_action+0x880> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85e, 0x880, x86_l_880);
x86_l_860:
	/* 0x860: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_869:
	/* 0x869: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_86e:
	/* 0x86e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_871:
	/* 0x871: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_874:
	/* 0x874: jbe    880 <do_action+0x880> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x874, 0x880, x86_l_880);
x86_l_876:
	/* 0x876: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_87b:
	/* 0x87b: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87e:
	/* 0x87e: jmp    89a <do_action+0x89a> */
	X86_SIM_X86_JMP(0x87e, 0x89a, x86_l_89a);
x86_l_880:
	/* 0x880: mov    rdi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_887:
	/* 0x887: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_889:
	/* 0x889: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_88c:
	/* 0x88c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_891:
	/* 0x891: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_896:
	/* 0x896: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_898:
	/* 0x898: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89a:
	/* 0x89a: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_89f:
	/* 0x89f: lea    eax,[rbx+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_8a2:
	/* 0x8a2: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8a8:
	/* 0x8a8: je     8cb <do_action+0x8cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a8, 0x8cb, x86_l_8cb);
x86_l_8aa:
	/* 0x8aa: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_8af:
	/* 0x8af: mov    rsi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8b6:
	/* 0x8b6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b8:
	/* 0x8b8: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8bd:
	/* 0x8bd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_8c0:
	/* 0x8c0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c2:
	/* 0x8c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c4:
	/* 0x8c4: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8cb:
	/* 0x8cb: lea    eax,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8ce:
	/* 0x8ce: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8d4:
	/* 0x8d4: je     8fd <do_action+0x8fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d4, 0x8fd, x86_l_8fd);
x86_l_8d6:
	/* 0x8d6: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_8db:
	/* 0x8db: mov    rsi,QWORD PTR [rip+0x2770] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8e2:
	/* 0x8e2: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_8e7:
	/* 0x8e7: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8ec:
	/* 0x8ec: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_8f1:
	/* 0x8f1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8fd:
	/* 0x8fd: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_900:
	/* 0x900: cmp    DWORD PTR [r15+rbx*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 17179869184ULL);
x86_l_906:
	/* 0x906: je     90d <do_action+0x90d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x906, 0x90d, x86_l_90d);
x86_l_908:
	/* 0x908: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_90d:
	/* 0x90d: mov    QWORD PTR [r13+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_911:
	/* 0x911: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_913:
	/* 0x913: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_915:
	/* 0x915: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_919:
	/* 0x919: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_91c:
	/* 0x91c: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_91e:
	/* 0x91e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_920:
	/* 0x920: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_922:
	/* 0x922: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_923:
	/* 0x923: jmp    97b <do_action+0x97b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_928:
	/* 0x928: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_930:
	/* 0x930: mov    rdi,QWORD PTR [rip+0x276c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_937:
	/* 0x937: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_939:
	/* 0x939: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_93c:
	/* 0x93c: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_941:
	/* 0x941: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_946:
	/* 0x946: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_948:
	/* 0x948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94a:
	/* 0x94a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_94d:
	/* 0x94d: je     4db <do_action+0x4db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94d, 0x4db, x86_l_4db);
x86_l_953:
	/* 0x953: mov    rdi,QWORD PTR [rip+0x276c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_95a:
	/* 0x95a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_95f:
	/* 0x95f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_964:
	/* 0x964: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_966:
	/* 0x966: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_969:
	/* 0x969: je     4db <do_action+0x4db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x969, 0x4db, x86_l_4db);
x86_l_96f:
	/* 0x96f: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_973:
	/* 0x973: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_976:
	/* 0x976: jmp    4db <do_action+0x4db> */
	X86_SIM_X86_JMP(0x976, 0x4db, x86_l_4db);
x86_l_97b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
