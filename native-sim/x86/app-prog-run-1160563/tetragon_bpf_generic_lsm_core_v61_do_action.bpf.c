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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 120ULL);
x86_l_7:
	/* 0x7: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f:
	/* 0xf: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_12:
	/* 0x12: mov    ebx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_32);
x86_l_14:
	/* 0x14: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_17:
	/* 0x17: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_19:
	/* 0x19: movsxd r12,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_1e:
	/* 0x1e: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_26:
	/* 0x26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b:
	/* 0x2b: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_32:
	/* 0x32: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_37:
	/* 0x37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39:
	/* 0x39: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e:
	/* 0x3e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_41:
	/* 0x41: je     8fc <do_action+0x8fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41, 0x8fc, x86_l_8fc);
x86_l_47:
	/* 0x47: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_4b:
	/* 0x4b: jg     75 <do_action+0x75> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b, 0x75, x86_l_75);
x86_l_4d:
	/* 0x4d: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_51:
	/* 0x51: jg     ad <do_action+0xad> */
	X86_SIM_X86_JCC(X86_CC_G, 0x51, 0xad, x86_l_ad);
x86_l_53:
	/* 0x53: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_57:
	/* 0x57: jg     1de <do_action+0x1de> */
	X86_SIM_X86_JCC(X86_CC_G, 0x57, 0x1de, x86_l_1de);
x86_l_5d:
	/* 0x5d: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_60:
	/* 0x60: je     4e7 <do_action+0x4e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60, 0x4e7, x86_l_4e7);
x86_l_66:
	/* 0x66: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6a:
	/* 0x6a: je     1f7 <do_action+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0x1f7, x86_l_1f7);
x86_l_70:
	/* 0x70: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x70, 0x8f4, x86_l_8f4);
x86_l_75:
	/* 0x75: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_79:
	/* 0x79: jg     1b0 <do_action+0x1b0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x79, 0x1b0, x86_l_1b0);
x86_l_7f:
	/* 0x7f: lea    ecx,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_84:
	/* 0x84: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_87:
	/* 0x87: jb     300 <do_action+0x300> */
	X86_SIM_X86_JCC(X86_CC_B, 0x87, 0x300, x86_l_300);
x86_l_8d:
	/* 0x8d: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_91:
	/* 0x91: je     3ea <do_action+0x3ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91, 0x3ea, x86_l_3ea);
x86_l_97:
	/* 0x97: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_9b:
	/* 0x9b: jne    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b, 0x8f4, x86_l_8f4);
x86_l_a1:
	/* 0xa1: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a3:
	/* 0xa3: mov    edi,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_a8:
	/* 0xa8: jmp    3b9 <do_action+0x3b9> */
	X86_SIM_X86_JMP(0xa8, 0x3b9, x86_l_3b9);
x86_l_ad:
	/* 0xad: lea    eax,[r12-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_b2:
	/* 0xb2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b5:
	/* 0xb5: jb     3da <do_action+0x3da> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb5, 0x3da, x86_l_3da);
x86_l_bb:
	/* 0xbb: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_bf:
	/* 0xbf: je     3f7 <do_action+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf, 0x3f7, x86_l_3f7);
x86_l_c5:
	/* 0xc5: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_c9:
	/* 0xc9: jne    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc9, 0x8f4, x86_l_8f4);
x86_l_cf:
	/* 0xcf: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_d2:
	/* 0xd2: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_d7:
	/* 0xd7: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_da:
	/* 0xda: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_dd:
	/* 0xdd: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e0:
	/* 0xe0: ja     8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe0, 0x8f4, x86_l_8f4);
x86_l_e6:
	/* 0xe6: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_ef:
	/* 0xef: jne    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef, 0x8f4, x86_l_8f4);
x86_l_f5:
	/* 0xf5: mov    r14d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_fa:
	/* 0xfa: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_102:
	/* 0x102: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_10a:
	/* 0x10a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_10f:
	/* 0x10f: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_117:
	/* 0x117: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b:
	/* 0x11b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_120:
	/* 0x120: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122:
	/* 0x122: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_126:
	/* 0x126: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a:
	/* 0x12a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f:
	/* 0x12f: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_136:
	/* 0x136: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_139:
	/* 0x139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b:
	/* 0x13b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e:
	/* 0x13e: je     8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13e, 0x8f4, x86_l_8f4);
x86_l_144:
	/* 0x144: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_148:
	/* 0x148: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_14c:
	/* 0x14c: ja     8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x14c, 0x8f4, x86_l_8f4);
x86_l_152:
	/* 0x152: cmp    DWORD PTR [r13+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_15b:
	/* 0x15b: jne    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15b, 0x8f4, x86_l_8f4);
x86_l_161:
	/* 0x161: mov    rcx,QWORD PTR [r13+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_169:
	/* 0x169: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_171:
	/* 0x171: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_177:
	/* 0x177: mov    ecx,DWORD PTR [r13+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_17f:
	/* 0x17f: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183:
	/* 0x183: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_188:
	/* 0x188: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18d:
	/* 0x18d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195:
	/* 0x195: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19a:
	/* 0x19a: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1a1:
	/* 0x1a1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a4:
	/* 0x1a4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a7:
	/* 0x1a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9:
	/* 0x1a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab:
	/* 0x1ab: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x1ab, 0x8f4, x86_l_8f4);
x86_l_1b0:
	/* 0x1b0: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_1b4:
	/* 0x1b4: je     5a5 <do_action+0x5a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4, 0x5a5, x86_l_5a5);
x86_l_1ba:
	/* 0x1ba: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_1be:
	/* 0x1be: je     46f <do_action+0x46f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1be, 0x46f, x86_l_46f);
x86_l_1c4:
	/* 0x1c4: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_1c8:
	/* 0x1c8: jne    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c8, 0x8f4, x86_l_8f4);
x86_l_1ce:
	/* 0x1ce: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1d1:
	/* 0x1d1: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d5:
	/* 0x1d5: xor    r14,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_1d9:
	/* 0x1d9: jmp    671 <do_action+0x671> */
	X86_SIM_X86_JMP(0x1d9, 0x671, x86_l_671);
x86_l_1de:
	/* 0x1de: mov    edi,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_1e3:
	/* 0x1e3: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1e7:
	/* 0x1e7: je     3b9 <do_action+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e7, 0x3b9, x86_l_3b9);
x86_l_1ed:
	/* 0x1ed: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1f1:
	/* 0x1f1: jne    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f1, 0x8f4, x86_l_8f4);
x86_l_1f7:
	/* 0x1f7: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1fa:
	/* 0x1fa: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1ff:
	/* 0x1ff: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_202:
	/* 0x202: mov    r14d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_207:
	/* 0x207: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_20f:
	/* 0x20f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_214:
	/* 0x214: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_21b:
	/* 0x21b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220:
	/* 0x220: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222:
	/* 0x222: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_225:
	/* 0x225: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_228:
	/* 0x228: je     6b2 <do_action+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x228, 0x6b2, x86_l_6b2);
x86_l_22e:
	/* 0x22e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_233:
	/* 0x233: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_236:
	/* 0x236: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_239:
	/* 0x239: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_23e:
	/* 0x23e: ja     6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x23e, 0x6b4, x86_l_6b4);
x86_l_244:
	/* 0x244: cmp    DWORD PTR [r13+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_24d:
	/* 0x24d: jne    6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24d, 0x6b4, x86_l_6b4);
x86_l_253:
	/* 0x253: mov    rax,QWORD PTR [r13+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_25b:
	/* 0x25b: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_263:
	/* 0x263: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_268:
	/* 0x268: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_270:
	/* 0x270: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_274:
	/* 0x274: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_279:
	/* 0x279: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b:
	/* 0x27b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_27f:
	/* 0x27f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283:
	/* 0x283: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_287:
	/* 0x287: jne    637 <do_action+0x637> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x287, 0x637, x86_l_637);
x86_l_28d:
	/* 0x28d: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_291:
	/* 0x291: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_295:
	/* 0x295: ja     6b2 <do_action+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x295, 0x6b2, x86_l_6b2);
x86_l_29b:
	/* 0x29b: cmp    DWORD PTR [r13+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_2a4:
	/* 0x2a4: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2a9:
	/* 0x2a9: jne    6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a9, 0x6b4, x86_l_6b4);
x86_l_2af:
	/* 0x2af: mov    rax,QWORD PTR [r13+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_2b7:
	/* 0x2b7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2bc:
	/* 0x2bc: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2c0:
	/* 0x2c0: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2c7:
	/* 0x2c7: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_2cc:
	/* 0x2cc: and    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R13, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_2d4:
	/* 0x2d4: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_2d7:
	/* 0x2d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dc:
	/* 0x2dc: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e1:
	/* 0x2e1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2e4:
	/* 0x2e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6:
	/* 0x2e6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2eb:
	/* 0x2eb: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2f2:
	/* 0x2f2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5:
	/* 0x2f5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2f8:
	/* 0x2f8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: jmp    3b0 <do_action+0x3b0> */
	X86_SIM_X86_JMP(0x2fb, 0x3b0, x86_l_3b0);
x86_l_300:
	/* 0x300: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_302:
	/* 0x302: mov    ecx,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_307:
	/* 0x307: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_30a:
	/* 0x30a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30d:
	/* 0x30d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_310:
	/* 0x310: ja     6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x310, 0x6b4, x86_l_6b4);
x86_l_316:
	/* 0x316: cmp    DWORD PTR [r13+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_31f:
	/* 0x31f: jne    6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31f, 0x6b4, x86_l_6b4);
x86_l_325:
	/* 0x325: mov    rcx,QWORD PTR [r13+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_32d:
	/* 0x32d: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_333:
	/* 0x333: mov    rcx,QWORD PTR [r13+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_33b:
	/* 0x33b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_340:
	/* 0x340: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_343:
	/* 0x343: je     6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x343, 0x6b4, x86_l_6b4);
x86_l_349:
	/* 0x349: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_34d:
	/* 0x34d: jne    69c <do_action+0x69c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34d, 0x69c, x86_l_69c);
x86_l_353:
	/* 0x353: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_358:
	/* 0x358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a:
	/* 0x35a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_361:
	/* 0x361: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_364:
	/* 0x364: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_369:
	/* 0x369: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_370:
	/* 0x370: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_373:
	/* 0x373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375:
	/* 0x375: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_378:
	/* 0x378: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37b:
	/* 0x37b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_380:
	/* 0x380: je     6b4 <do_action+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x380, 0x6b4, x86_l_6b4);
x86_l_386:
	/* 0x386: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_388:
	/* 0x388: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b:
	/* 0x38b: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_390:
	/* 0x390: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_394:
	/* 0x394: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_399:
	/* 0x399: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_39e:
	/* 0x39e: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_3a5:
	/* 0x3a5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a8:
	/* 0x3a8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ad:
	/* 0x3ad: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b2:
	/* 0x3b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4:
	/* 0x3b4: jmp    6b2 <do_action+0x6b2> */
	X86_SIM_X86_JMP(0x3b4, 0x6b2, x86_l_6b2);
x86_l_3b9:
	/* 0x3b9: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_3bf:
	/* 0x3bf: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_3c2:
	/* 0x3c2: je     671 <do_action+0x671> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c2, 0x671, x86_l_671);
x86_l_3c8:
	/* 0x3c8: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_3cd:
	/* 0x3cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cf:
	/* 0x3cf: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_3d5:
	/* 0x3d5: jmp    671 <do_action+0x671> */
	X86_SIM_X86_JMP(0x3d5, 0x671, x86_l_671);
x86_l_3da:
	/* 0x3da: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3dc:
	/* 0x3dc: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_3e1:
	/* 0x3e1: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3e5:
	/* 0x3e5: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x3e5, 0x8f4, x86_l_8f4);
x86_l_3ea:
	/* 0x3ea: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ef:
	/* 0x3ef: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f2:
	/* 0x3f2: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x3f2, 0x8f4, x86_l_8f4);
x86_l_3f7:
	/* 0x3f7: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f9:
	/* 0x3f9: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_3ff:
	/* 0x3ff: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_402:
	/* 0x402: je     671 <do_action+0x671> */
	X86_SIM_X86_JCC(X86_CC_E, 0x402, 0x671, x86_l_671);
x86_l_408:
	/* 0x408: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_40a:
	/* 0x40a: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_40f:
	/* 0x40f: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_413:
	/* 0x413: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_418:
	/* 0x418: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a:
	/* 0x41a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41f:
	/* 0x41f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_424:
	/* 0x424: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_42b:
	/* 0x42b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_430:
	/* 0x430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_432:
	/* 0x432: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_435:
	/* 0x435: je     61b <do_action+0x61b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x435, 0x61b, x86_l_61b);
x86_l_43b:
	/* 0x43b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: mov    DWORD PTR [rsp],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 917521ULL);
x86_l_445:
	/* 0x445: mov    QWORD PTR [rsp+0x4],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179870047ULL);
x86_l_44e:
	/* 0x44e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_453:
	/* 0x453: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_45a:
	/* 0x45a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_45d:
	/* 0x45d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45f:
	/* 0x45f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_462:
	/* 0x462: je     648 <do_action+0x648> */
	X86_SIM_X86_JCC(X86_CC_E, 0x462, 0x648, x86_l_648);
x86_l_468:
	/* 0x468: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_46a:
	/* 0x46a: jmp    668 <do_action+0x668> */
	X86_SIM_X86_JMP(0x46a, 0x668, x86_l_668);
x86_l_46f:
	/* 0x46f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_474:
	/* 0x474: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47b:
	/* 0x47b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_480:
	/* 0x480: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_487:
	/* 0x487: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48c:
	/* 0x48c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e:
	/* 0x48e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_491:
	/* 0x491: je     8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x491, 0x8f4, x86_l_8f4);
x86_l_497:
	/* 0x497: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_49b:
	/* 0x49b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a0:
	/* 0x4a0: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_4a8:
	/* 0x4a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ad:
	/* 0x4ad: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_4b4:
	/* 0x4b4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b9:
	/* 0x4b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb:
	/* 0x4bb: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_4c3:
	/* 0x4c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: je     5b5 <do_action+0x5b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c6, 0x5b5, x86_l_5b5);
x86_l_4cc:
	/* 0x4cc: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4cf:
	/* 0x4cf: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4d4:
	/* 0x4d4: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4db:
	/* 0x4db: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e0:
	/* 0x4e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e2:
	/* 0x4e2: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x4e2, 0x8f4, x86_l_8f4);
x86_l_4e7:
	/* 0x4e7: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4ea:
	/* 0x4ea: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_4ef:
	/* 0x4ef: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_4f2:
	/* 0x4f2: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_4f7:
	/* 0x4f7: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4fb:
	/* 0x4fb: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_500:
	/* 0x500: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_507:
	/* 0x507: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50b:
	/* 0x50b: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_518:
	/* 0x518: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_51b:
	/* 0x51b: je     88d <do_action+0x88d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51b, 0x88d, x86_l_88d);
x86_l_521:
	/* 0x521: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_526:
	/* 0x526: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_52d:
	/* 0x52d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_532:
	/* 0x532: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_534:
	/* 0x534: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: je     88d <do_action+0x88d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x537, 0x88d, x86_l_88d);
x86_l_53d:
	/* 0x53d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_540:
	/* 0x540: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_545:
	/* 0x545: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_54a:
	/* 0x54a: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_551:
	/* 0x551: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_556:
	/* 0x556: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_558:
	/* 0x558: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_55d:
	/* 0x55d: mov    rcx,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_561:
	/* 0x561: mov    QWORD PTR [rbp+0x0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_565:
	/* 0x565: mov    rcx,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_569:
	/* 0x569: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_56e:
	/* 0x56e: mov    QWORD PTR [rbp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_572:
	/* 0x572: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_574:
	/* 0x574: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_579:
	/* 0x579: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_57e:
	/* 0x57e: mov    edx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_582:
	/* 0x582: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_585:
	/* 0x585: je     6c6 <do_action+0x6c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x585, 0x6c6, x86_l_6c6);
x86_l_58b:
	/* 0x58b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_58e:
	/* 0x58e: je     6c2 <do_action+0x6c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58e, 0x6c2, x86_l_6c2);
x86_l_594:
	/* 0x594: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_596:
	/* 0x596: jne    88d <do_action+0x88d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x596, 0x88d, x86_l_88d);
x86_l_59c:
	/* 0x59c: mov    ecx,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_5a0:
	/* 0x5a0: jmp    6c6 <do_action+0x6c6> */
	X86_SIM_X86_JMP(0x5a0, 0x6c6, x86_l_6c6);
x86_l_5a5:
	/* 0x5a5: add    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5a8:
	/* 0x5a8: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5ac:
	/* 0x5ac: xor    r14,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_5b0:
	/* 0x5b0: jmp    671 <do_action+0x671> */
	X86_SIM_X86_JMP(0x5b0, 0x671, x86_l_671);
x86_l_5b5:
	/* 0x5b5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ba:
	/* 0x5ba: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_5c1:
	/* 0x5c1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c6:
	/* 0x5c6: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5cb:
	/* 0x5cb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5d0:
	/* 0x5d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d2:
	/* 0x5d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: je     4cf <do_action+0x4cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d5, 0x4cf, x86_l_4cf);
x86_l_5db:
	/* 0x5db: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5de:
	/* 0x5de: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5e0:
	/* 0x5e0: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e4:
	/* 0x5e4: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_5eb:
	/* 0x5eb: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ff:
	/* 0x5ff: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_606:
	/* 0x606: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_609:
	/* 0x609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60b:
	/* 0x60b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: je     908 <do_action+0x908> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60e, 0x908, x86_l_908);
x86_l_614:
	/* 0x614: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_616:
	/* 0x616: jmp    928 <do_action+0x928> */
	X86_SIM_X86_JMP(0x616, 0x928, x86_l_928);
x86_l_61b:
	/* 0x61b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_620:
	/* 0x620: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_627:
	/* 0x627: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62c:
	/* 0x62c: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_631:
	/* 0x631: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_633:
	/* 0x633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_635:
	/* 0x635: jmp    66b <do_action+0x66b> */
	X86_SIM_X86_JMP(0x635, 0x66b, x86_l_66b);
x86_l_637:
	/* 0x637: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_63c:
	/* 0x63c: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_643:
	/* 0x643: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_646:
	/* 0x646: jmp    6ad <do_action+0x6ad> */
	X86_SIM_X86_JMP(0x646, 0x6ad, x86_l_6ad);
x86_l_648:
	/* 0x648: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_650:
	/* 0x650: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_655:
	/* 0x655: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_65c:
	/* 0x65c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_65f:
	/* 0x65f: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_664:
	/* 0x664: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_666:
	/* 0x666: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_668:
	/* 0x668: mov    DWORD PTR [r15],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66b:
	/* 0x66b: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_671:
	/* 0x671: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_678:
	/* 0x678: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67d:
	/* 0x67d: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_684:
	/* 0x684: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_687:
	/* 0x687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_689:
	/* 0x689: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68c:
	/* 0x68c: je     8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68c, 0x8f4, x86_l_8f4);
x86_l_692:
	/* 0x692: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_697:
	/* 0x697: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x697, 0x8f4, x86_l_8f4);
x86_l_69c:
	/* 0x69c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6a1:
	/* 0x6a1: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_6a8:
	/* 0x6a8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ad:
	/* 0x6ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6af:
	/* 0x6af: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b4:
	/* 0x6b4: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_6b7:
	/* 0x6b7: jne    8fc <do_action+0x8fc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b7, 0x8fc, x86_l_8fc);
x86_l_6bd:
	/* 0x6bd: jmp    8f4 <do_action+0x8f4> */
	X86_SIM_X86_JMP(0x6bd, 0x8f4, x86_l_8f4);
x86_l_6c2:
	/* 0x6c2: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6c6:
	/* 0x6c6: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6cb:
	/* 0x6cb: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6cd:
	/* 0x6cd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6d2:
	/* 0x6d2: mov    QWORD PTR [rdx+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d6:
	/* 0x6d6: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_6da:
	/* 0x6da: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6df:
	/* 0x6df: mov    QWORD PTR [rsp+0x38],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e4:
	/* 0x6e4: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_6e9:
	/* 0x6e9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6ee:
	/* 0x6ee: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f1:
	/* 0x6f1: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6f6:
	/* 0x6f6: jmp    706 <do_action+0x706> */
	X86_SIM_X86_JMP(0x6f6, 0x706, x86_l_706);
x86_l_6f8:
	/* 0x6f8: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6fc:
	/* 0x6fc: cmp    r14,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 20ULL);
x86_l_700:
	/* 0x700: je     838 <do_action+0x838> */
	X86_SIM_X86_JCC(X86_CC_E, 0x700, 0x838, x86_l_838);
x86_l_706:
	/* 0x706: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_70e:
	/* 0x70e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_713:
	/* 0x713: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_71a:
	/* 0x71a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71f:
	/* 0x71f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_721:
	/* 0x721: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_724:
	/* 0x724: je     838 <do_action+0x838> */
	X86_SIM_X86_JCC(X86_CC_E, 0x724, 0x838, x86_l_838);
x86_l_72a:
	/* 0x72a: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_730:
	/* 0x730: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_735:
	/* 0x735: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_73c:
	/* 0x73c: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_73f:
	/* 0x73f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_741:
	/* 0x741: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_744:
	/* 0x744: je     838 <do_action+0x838> */
	X86_SIM_X86_JCC(X86_CC_E, 0x744, 0x838, x86_l_838);
x86_l_74a:
	/* 0x74a: cmp    DWORD PTR [rax+r14*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 279172874239ULL);
x86_l_750:
	/* 0x750: je     838 <do_action+0x838> */
	X86_SIM_X86_JCC(X86_CC_E, 0x750, 0x838, x86_l_838);
x86_l_756:
	/* 0x756: mov    rax,QWORD PTR [r13+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_75e:
	/* 0x75e: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_762:
	/* 0x762: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_765:
	/* 0x765: jge    838 <do_action+0x838> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x765, 0x838, x86_l_838);
x86_l_76b:
	/* 0x76b: cmp    r14,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 16ULL);
x86_l_76f:
	/* 0x76f: je     7d6 <do_action+0x7d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76f, 0x7d6, x86_l_7d6);
x86_l_771:
	/* 0x771: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_779:
	/* 0x779: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_77e:
	/* 0x77e: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_785:
	/* 0x785: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_78a:
	/* 0x78a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78c:
	/* 0x78c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78f:
	/* 0x78f: je     7ce <do_action+0x7ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78f, 0x7ce, x86_l_7ce);
x86_l_791:
	/* 0x791: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_797:
	/* 0x797: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_79c:
	/* 0x79c: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_7a3:
	/* 0x7a3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7a6:
	/* 0x7a6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7a8:
	/* 0x7a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ab:
	/* 0x7ab: je     7ce <do_action+0x7ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ab, 0x7ce, x86_l_7ce);
x86_l_7ad:
	/* 0x7ad: cmp    DWORD PTR [rax+r14*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 296352743423ULL);
x86_l_7b3:
	/* 0x7b3: mov    rax,QWORD PTR [r13+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_7bb:
	/* 0x7bb: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7c0:
	/* 0x7c0: je     7d6 <do_action+0x7d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c0, 0x7d6, x86_l_7d6);
x86_l_7c2:
	/* 0x7c2: mov    ebp,DWORD PTR [r13+r14*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 1), 24192ULL);
x86_l_7ca:
	/* 0x7ca: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7cc:
	/* 0x7cc: jmp    7e4 <do_action+0x7e4> */
	X86_SIM_X86_JMP(0x7cc, 0x7e4, x86_l_7e4);
x86_l_7ce:
	/* 0x7ce: mov    rax,QWORD PTR [r13+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_7d6:
	/* 0x7d6: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7da:
	/* 0x7da: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7dc:
	/* 0x7dc: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_7df:
	/* 0x7df: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e4:
	/* 0x7e4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_7e6:
	/* 0x7e6: jle    6f8 <do_action+0x6f8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x7e6, 0x6f8, x86_l_6f8);
x86_l_7ec:
	/* 0x7ec: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_7f1:
	/* 0x7f1: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_7f6:
	/* 0x7f6: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_7f9:
	/* 0x7f9: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_7fe:
	/* 0x7fe: cmovge ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_GE);
x86_l_801:
	/* 0x801: movzx  r13d,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_807:
	/* 0x807: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_80b:
	/* 0x80b: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_810:
	/* 0x810: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_814:
	/* 0x814: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_81b:
	/* 0x81b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_820:
	/* 0x820: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_822:
	/* 0x822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_824:
	/* 0x824: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_827:
	/* 0x827: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_82c:
	/* 0x82c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_82e:
	/* 0x82e: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_833:
	/* 0x833: jmp    6f8 <do_action+0x6f8> */
	X86_SIM_X86_JMP(0x833, 0x6f8, x86_l_6f8);
x86_l_838:
	/* 0x838: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83d:
	/* 0x83d: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_844:
	/* 0x844: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_849:
	/* 0x849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84b:
	/* 0x84b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84e:
	/* 0x84e: je     870 <do_action+0x870> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84e, 0x870, x86_l_870);
x86_l_850:
	/* 0x850: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_859:
	/* 0x859: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_85e:
	/* 0x85e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_861:
	/* 0x861: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_864:
	/* 0x864: jbe    870 <do_action+0x870> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x864, 0x870, x86_l_870);
x86_l_866:
	/* 0x866: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_86b:
	/* 0x86b: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_86e:
	/* 0x86e: jmp    888 <do_action+0x888> */
	X86_SIM_X86_JMP(0x86e, 0x888, x86_l_888);
x86_l_870:
	/* 0x870: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_875:
	/* 0x875: mov    rdi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_87c:
	/* 0x87c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_87f:
	/* 0x87f: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_884:
	/* 0x884: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_886:
	/* 0x886: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_888:
	/* 0x888: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88d:
	/* 0x88d: lea    eax,[rbx+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_890:
	/* 0x890: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_896:
	/* 0x896: je     8b7 <do_action+0x8b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x896, 0x8b7, x86_l_8b7);
x86_l_898:
	/* 0x898: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_89d:
	/* 0x89d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8a2:
	/* 0x8a2: mov    rsi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8a9:
	/* 0x8a9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_8ac:
	/* 0x8ac: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ae:
	/* 0x8ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b0:
	/* 0x8b0: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8b7:
	/* 0x8b7: lea    eax,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8ba:
	/* 0x8ba: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_8c0:
	/* 0x8c0: je     8e4 <do_action+0x8e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c0, 0x8e4, x86_l_8e4);
x86_l_8c2:
	/* 0x8c2: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_8c7:
	/* 0x8c7: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_8cc:
	/* 0x8cc: mov    rsi,QWORD PTR [rip+0x26f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_8d3:
	/* 0x8d3: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_8d8:
	/* 0x8d8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8dd:
	/* 0x8dd: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8e4:
	/* 0x8e4: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_8e7:
	/* 0x8e7: cmp    DWORD PTR [r15+rbx*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 17179869184ULL);
x86_l_8ed:
	/* 0x8ed: je     8f4 <do_action+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ed, 0x8f4, x86_l_8f4);
x86_l_8ef:
	/* 0x8ef: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_8f4:
	/* 0x8f4: mov    QWORD PTR [r13+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8f8:
	/* 0x8f8: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_8fa:
	/* 0x8fa: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_8fc:
	/* 0x8fc: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_900:
	/* 0x900: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_902:
	/* 0x902: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_903:
	/* 0x903: jmp    959 <do_action+0x959> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_908:
	/* 0x908: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_910:
	/* 0x910: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_915:
	/* 0x915: mov    rdi,QWORD PTR [rip+0x26fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_91c:
	/* 0x91c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_924:
	/* 0x924: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_926:
	/* 0x926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_928:
	/* 0x928: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_92b:
	/* 0x92b: je     4cf <do_action+0x4cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92b, 0x4cf, x86_l_4cf);
x86_l_931:
	/* 0x931: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_936:
	/* 0x936: mov    rdi,QWORD PTR [rip+0x26fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_93d:
	/* 0x93d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_942:
	/* 0x942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_944:
	/* 0x944: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_947:
	/* 0x947: je     4cf <do_action+0x4cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x947, 0x4cf, x86_l_4cf);
x86_l_94d:
	/* 0x94d: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_951:
	/* 0x951: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_954:
	/* 0x954: jmp    4cf <do_action+0x4cf> */
	X86_SIM_X86_JMP(0x954, 0x4cf, x86_l_4cf);
x86_l_959:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
