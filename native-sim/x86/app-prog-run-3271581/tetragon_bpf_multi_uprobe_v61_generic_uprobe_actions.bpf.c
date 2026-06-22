extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char heap_ro_zero;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char ratelimit_heap;
extern char ratelimit_map;
extern char sleepable_offload;
extern char socktrack_map;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_uprobe_v61_generic_uprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3:
	/* 0x3: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4:
	/* 0x4: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_8:
	/* 0x8: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_b:
	/* 0xb: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13:
	/* 0x13: mov    rdi,QWORD PTR [rip+0x5f20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1a:
	/* 0x1a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f:
	/* 0x1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24:
	/* 0x24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26:
	/* 0x26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29:
	/* 0x29: je     132 <generic_uprobe_actions+0x132> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29, 0x132, x86_l_132);
x86_l_2f:
	/* 0x2f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: mov    r14d,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_39:
	/* 0x39: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_3d:
	/* 0x3d: jl     132 <generic_uprobe_actions+0x132> */
	X86_SIM_X86_JCC(X86_CC_L, 0x3d, 0x132, x86_l_132);
x86_l_43:
	/* 0x43: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_4a:
	/* 0x4a: mov    rdi,QWORD PTR [rip+0x5f20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_51:
	/* 0x51: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b:
	/* 0x5b: je     132 <generic_uprobe_actions+0x132> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b, 0x132, x86_l_132);
x86_l_61:
	/* 0x61: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_64:
	/* 0x64: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6a:
	/* 0x6a: add    r14d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6e:
	/* 0x6e: mov    BYTE PTR [rsp+0x7],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771073ULL);
x86_l_73:
	/* 0x73: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_7b:
	/* 0x7b: mov    rdi,QWORD PTR [rip+0x5f20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_82:
	/* 0x82: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_87:
	/* 0x87: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f:
	/* 0x8f: and    r14d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_96:
	/* 0x96: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_99:
	/* 0x99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b:
	/* 0x9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: je     ae <generic_uprobe_actions+0xae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e, 0xae, x86_l_ae);
x86_l_a0:
	/* 0xa0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3:
	/* 0xa3: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_a6:
	/* 0xa6: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_aa:
	/* 0xaa: jae    b6 <generic_uprobe_actions+0xb6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xaa, 0xb6, x86_l_b6);
x86_l_ac:
	/* 0xac: jmp    110 <generic_uprobe_actions+0x110> */
	X86_SIM_X86_JMP(0xac, 0x110, x86_l_110);
x86_l_ae:
	/* 0xae: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_b0:
	/* 0xb0: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_b4:
	/* 0xb4: jb     110 <generic_uprobe_actions+0x110> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb4, 0x110, x86_l_110);
x86_l_b6:
	/* 0xb6: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b9:
	/* 0xb9: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_be:
	/* 0xbe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c1:
	/* 0xc1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c3:
	/* 0xc3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c6:
	/* 0xc6: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_c9:
	/* 0xc9: call   0 <generic_uprobe_actions> */
	X86_SIM_X86_CALL(x86_l_141, 0xceULL);
x86_l_ce:
	/* 0xce: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_d5:
	/* 0xd5: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d8:
	/* 0xd8: jae    110 <generic_uprobe_actions+0x110> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xd8, 0x110, x86_l_110);
x86_l_da:
	/* 0xda: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_df:
	/* 0xdf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e2:
	/* 0xe2: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_e4:
	/* 0xe4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e7:
	/* 0xe7: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_ea:
	/* 0xea: call   0 <generic_uprobe_actions> */
	X86_SIM_X86_CALL(x86_l_141, 0xefULL);
x86_l_ef:
	/* 0xef: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_f6:
	/* 0xf6: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_f9:
	/* 0xf9: jae    110 <generic_uprobe_actions+0x110> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf9, 0x110, x86_l_110);
x86_l_fb:
	/* 0xfb: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_100:
	/* 0x100: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_103:
	/* 0x103: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_105:
	/* 0x105: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_108:
	/* 0x108: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_10b:
	/* 0x10b: call   0 <generic_uprobe_actions> */
	X86_SIM_X86_CALL(x86_l_141, 0x110ULL);
x86_l_110:
	/* 0x110: cmp    BYTE PTR [rsp+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_115:
	/* 0x115: je     132 <generic_uprobe_actions+0x132> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115, 0x132, x86_l_132);
x86_l_117:
	/* 0x117: mov    rsi,QWORD PTR [rip+0x5f20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_11e:
	/* 0x11e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_123:
	/* 0x123: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_128:
	/* 0x128: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_130:
	/* 0x130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132:
	/* 0x132: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134:
	/* 0x134: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_138:
	/* 0x138: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_139:
	/* 0x139: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_13c:
	/* 0x13c: jmp    ad9 <do_action+0x998> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ad9:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_141 */
x86_l_141:
	/* 0x141: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_142:
	/* 0x142: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_144:
	/* 0x144: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_146:
	/* 0x146: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_148:
	/* 0x148: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_14a:
	/* 0x14a: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_14b:
	/* 0x14b: sub    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 120ULL);
x86_l_14f:
	/* 0x14f: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_152:
	/* 0x152: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_157:
	/* 0x157: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: mov    ebx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_32);
x86_l_15c:
	/* 0x15c: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_15f:
	/* 0x15f: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_161:
	/* 0x161: movsxd r14,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_166:
	/* 0x166: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_16e:
	/* 0x16e: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_175:
	/* 0x175: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_17a:
	/* 0x17a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17f:
	/* 0x17f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181:
	/* 0x181: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_186:
	/* 0x186: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_189:
	/* 0x189: je     a59 <do_action+0x918> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x189, 0xa59, x86_l_a59);
x86_l_18f:
	/* 0x18f: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_193:
	/* 0x193: jg     1bd <do_action+0x7c> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x193, 0x1bd, x86_l_1bd);
x86_l_195:
	/* 0x195: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_199:
	/* 0x199: jg     1f4 <do_action+0xb3> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x199, 0x1f4, x86_l_1f4);
x86_l_19b:
	/* 0x19b: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_19f:
	/* 0x19f: jg     326 <do_action+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x19f, 0x326, x86_l_326);
x86_l_1a5:
	/* 0x1a5: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_1a8:
	/* 0x1a8: je     657 <do_action+0x516> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a8, 0x657, x86_l_657);
x86_l_1ae:
	/* 0x1ae: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1b2:
	/* 0x1b2: je     33f <do_action+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b2, 0x33f, x86_l_33f);
x86_l_1b8:
	/* 0x1b8: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x1b8, 0xa51, x86_l_a51);
x86_l_1bd:
	/* 0x1bd: cmp    r14d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 11ULL);
x86_l_1c1:
	/* 0x1c1: jg     2f8 <do_action+0x1b7> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1c1, 0x2f8, x86_l_2f8);
x86_l_1c7:
	/* 0x1c7: lea    ecx,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1cb:
	/* 0x1cb: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ce:
	/* 0x1ce: jb     44a <do_action+0x309> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ce, 0x44a, x86_l_44a);
x86_l_1d4:
	/* 0x1d4: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1d8:
	/* 0x1d8: je     537 <do_action+0x3f6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d8, 0x537, x86_l_537);
x86_l_1de:
	/* 0x1de: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_1e2:
	/* 0x1e2: jne    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1e2, 0xa51, x86_l_a51);
x86_l_1e8:
	/* 0x1e8: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ea:
	/* 0x1ea: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_1ef:
	/* 0x1ef: jmp    503 <do_action+0x3c2> */
	X86_SIM_X86_SUB_JMP(0x1ef, 0x503, x86_l_503);
x86_l_1f4:
	/* 0x1f4: lea    eax,[r14-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1f8:
	/* 0x1f8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fb:
	/* 0x1fb: jb     527 <do_action+0x3e6> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fb, 0x527, x86_l_527);
x86_l_201:
	/* 0x201: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_205:
	/* 0x205: je     544 <do_action+0x403> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x205, 0x544, x86_l_544);
x86_l_20b:
	/* 0x20b: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_20f:
	/* 0x20f: jne    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x20f, 0xa51, x86_l_a51);
x86_l_215:
	/* 0x215: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_218:
	/* 0x218: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_21d:
	/* 0x21d: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_220:
	/* 0x220: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_223:
	/* 0x223: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_226:
	/* 0x226: ja     a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x226, 0xa51, x86_l_a51);
x86_l_22c:
	/* 0x22c: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_235:
	/* 0x235: jne    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x235, 0xa51, x86_l_a51);
x86_l_23b:
	/* 0x23b: mov    r15d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_240:
	/* 0x240: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_248:
	/* 0x248: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_250:
	/* 0x250: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_255:
	/* 0x255: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_25d:
	/* 0x25d: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_261:
	/* 0x261: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_266:
	/* 0x266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268:
	/* 0x268: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_26c:
	/* 0x26c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_270:
	/* 0x270: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_277:
	/* 0x277: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27f:
	/* 0x27f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281:
	/* 0x281: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_284:
	/* 0x284: je     a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x284, 0xa51, x86_l_a51);
x86_l_28a:
	/* 0x28a: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_28e:
	/* 0x28e: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_292:
	/* 0x292: ja     a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x292, 0xa51, x86_l_a51);
x86_l_298:
	/* 0x298: cmp    DWORD PTR [r13+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_2a1:
	/* 0x2a1: jne    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2a1, 0xa51, x86_l_a51);
x86_l_2a7:
	/* 0x2a7: mov    rcx,QWORD PTR [r13+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_2af:
	/* 0x2af: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2b7:
	/* 0x2b7: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2bd:
	/* 0x2bd: mov    ecx,DWORD PTR [r13+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_2c5:
	/* 0x2c5: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c9:
	/* 0x2c9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2d1:
	/* 0x2d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3:
	/* 0x2d3: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2d7:
	/* 0x2d7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db:
	/* 0x2db: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2e2:
	/* 0x2e2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e4:
	/* 0x2e4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2e7:
	/* 0x2e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ec:
	/* 0x2ec: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ef:
	/* 0x2ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f1:
	/* 0x2f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3:
	/* 0x2f3: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x2f3, 0xa51, x86_l_a51);
x86_l_2f8:
	/* 0x2f8: cmp    r14d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 12ULL);
x86_l_2fc:
	/* 0x2fc: je     713 <do_action+0x5d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2fc, 0x713, x86_l_713);
x86_l_302:
	/* 0x302: cmp    r14d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 13ULL);
x86_l_306:
	/* 0x306: je     5df <do_action+0x49e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x306, 0x5df, x86_l_5df);
x86_l_30c:
	/* 0x30c: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_310:
	/* 0x310: jne    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x310, 0xa51, x86_l_a51);
x86_l_316:
	/* 0x316: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_319:
	/* 0x319: movzx  r12d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31d:
	/* 0x31d: xor    r12,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_321:
	/* 0x321: jmp    a2f <do_action+0x8ee> */
	X86_SIM_X86_SUB_JMP(0x321, 0xa2f, x86_l_a2f);
x86_l_326:
	/* 0x326: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_32b:
	/* 0x32b: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_32f:
	/* 0x32f: je     503 <do_action+0x3c2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x32f, 0x503, x86_l_503);
x86_l_335:
	/* 0x335: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_339:
	/* 0x339: jne    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x339, 0xa51, x86_l_a51);
x86_l_33f:
	/* 0x33f: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_342:
	/* 0x342: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_347:
	/* 0x347: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_34a:
	/* 0x34a: mov    r12d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_34f:
	/* 0x34f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_357:
	/* 0x357: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_35e:
	/* 0x35e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_363:
	/* 0x363: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_368:
	/* 0x368: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a:
	/* 0x36a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36d:
	/* 0x36d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_370:
	/* 0x370: je     7b0 <do_action+0x66f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x370, 0x7b0, x86_l_7b0);
x86_l_376:
	/* 0x376: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_37b:
	/* 0x37b: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_37e:
	/* 0x37e: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_381:
	/* 0x381: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_386:
	/* 0x386: ja     7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x386, 0x7b2, x86_l_7b2);
x86_l_38c:
	/* 0x38c: cmp    DWORD PTR [r13+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_395:
	/* 0x395: jne    7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x395, 0x7b2, x86_l_7b2);
x86_l_39b:
	/* 0x39b: mov    rax,QWORD PTR [r13+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_3a3:
	/* 0x3a3: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_3ab:
	/* 0x3ab: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3b0:
	/* 0x3b0: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_3b8:
	/* 0x3b8: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bc:
	/* 0x3bc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c1:
	/* 0x3c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3:
	/* 0x3c3: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3c7:
	/* 0x3c7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cb:
	/* 0x3cb: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_3cf:
	/* 0x3cf: jne    789 <do_action+0x648> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3cf, 0x789, x86_l_789);
x86_l_3d5:
	/* 0x3d5: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3d9:
	/* 0x3d9: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3dd:
	/* 0x3dd: ja     7b0 <do_action+0x66f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3dd, 0x7b0, x86_l_7b0);
x86_l_3e3:
	/* 0x3e3: cmp    DWORD PTR [r13+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_3ec:
	/* 0x3ec: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3f1:
	/* 0x3f1: jne    7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3f1, 0x7b2, x86_l_7b2);
x86_l_3f7:
	/* 0x3f7: mov    rax,QWORD PTR [r13+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_3ff:
	/* 0x3ff: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_404:
	/* 0x404: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_408:
	/* 0x408: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_40f:
	/* 0x40f: mov    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_417:
	/* 0x417: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41d:
	/* 0x41d: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_421:
	/* 0x421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_426:
	/* 0x426: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_42b:
	/* 0x42b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_430:
	/* 0x430: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_437:
	/* 0x437: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43a:
	/* 0x43a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_43d:
	/* 0x43d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_442:
	/* 0x442: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_445:
	/* 0x445: jmp    4fa <do_action+0x3b9> */
	X86_SIM_X86_SUB_JMP(0x445, 0x4fa, x86_l_4fa);
x86_l_44a:
	/* 0x44a: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_44c:
	/* 0x44c: mov    ecx,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_451:
	/* 0x451: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_454:
	/* 0x454: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_457:
	/* 0x457: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_45a:
	/* 0x45a: ja     7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x45a, 0x7b2, x86_l_7b2);
x86_l_460:
	/* 0x460: cmp    DWORD PTR [r13+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_469:
	/* 0x469: jne    7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x469, 0x7b2, x86_l_7b2);
x86_l_46f:
	/* 0x46f: mov    rcx,QWORD PTR [r13+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_477:
	/* 0x477: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_47d:
	/* 0x47d: mov    rcx,QWORD PTR [r13+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_485:
	/* 0x485: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48a:
	/* 0x48a: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_48d:
	/* 0x48d: je     7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x48d, 0x7b2, x86_l_7b2);
x86_l_493:
	/* 0x493: cmp    r14d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 10ULL);
x86_l_497:
	/* 0x497: jne    79a <do_action+0x659> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x497, 0x79a, x86_l_79a);
x86_l_49d:
	/* 0x49d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4a2:
	/* 0x4a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a4:
	/* 0x4a4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4ab:
	/* 0x4ab: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae:
	/* 0x4ae: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_4b5:
	/* 0x4b5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4b8:
	/* 0x4b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bd:
	/* 0x4bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf:
	/* 0x4bf: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4c2:
	/* 0x4c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_4ca:
	/* 0x4ca: je     7b2 <do_action+0x671> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ca, 0x7b2, x86_l_7b2);
x86_l_4d0:
	/* 0x4d0: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d2:
	/* 0x4d2: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d5:
	/* 0x4d5: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4da:
	/* 0x4da: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4de:
	/* 0x4de: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3:
	/* 0x4e3: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_4ea:
	/* 0x4ea: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ed:
	/* 0x4ed: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f2:
	/* 0x4f2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4fa:
	/* 0x4fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fc:
	/* 0x4fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fe:
	/* 0x4fe: jmp    7b0 <do_action+0x66f> */
	X86_SIM_X86_SUB_JMP(0x4fe, 0x7b0, x86_l_7b0);
x86_l_503:
	/* 0x503: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_509:
	/* 0x509: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_50c:
	/* 0x50c: je     a2f <do_action+0x8ee> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x50c, 0xa2f, x86_l_a2f);
x86_l_512:
	/* 0x512: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_515:
	/* 0x515: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_51a:
	/* 0x51a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51c:
	/* 0x51c: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_522:
	/* 0x522: jmp    a2f <do_action+0x8ee> */
	X86_SIM_X86_SUB_JMP(0x522, 0xa2f, x86_l_a2f);
x86_l_527:
	/* 0x527: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_529:
	/* 0x529: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_52e:
	/* 0x52e: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_532:
	/* 0x532: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x532, 0xa51, x86_l_a51);
x86_l_537:
	/* 0x537: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53c:
	/* 0x53c: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53f:
	/* 0x53f: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x53f, 0xa51, x86_l_a51);
x86_l_544:
	/* 0x544: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_546:
	/* 0x546: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_54c:
	/* 0x54c: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_54f:
	/* 0x54f: je     a2f <do_action+0x8ee> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x54f, 0xa2f, x86_l_a2f);
x86_l_555:
	/* 0x555: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_557:
	/* 0x557: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_55c:
	/* 0x55c: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_560:
	/* 0x560: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_565:
	/* 0x565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56c:
	/* 0x56c: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_573:
	/* 0x573: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_578:
	/* 0x578: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57d:
	/* 0x57d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57f:
	/* 0x57f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_582:
	/* 0x582: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_585:
	/* 0x585: je     594 <do_action+0x453> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x585, 0x594, x86_l_594);
x86_l_587:
	/* 0x587: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_58e:
	/* 0x58e: jb     a26 <do_action+0x8e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x58e, 0xa26, x86_l_a26);
x86_l_594:
	/* 0x594: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_597:
	/* 0x597: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_599:
	/* 0x599: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5a1:
	/* 0x5a1: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_5a4:
	/* 0x5a4: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a8:
	/* 0x5a8: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_5af:
	/* 0x5af: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_5b9:
	/* 0x5b9: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5be:
	/* 0x5be: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5c5:
	/* 0x5c5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5c8:
	/* 0x5c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cd:
	/* 0x5cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf:
	/* 0x5cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: je     9ff <do_action+0x8be> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5d2, 0x9ff, x86_l_9ff);
x86_l_5d8:
	/* 0x5d8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5da:
	/* 0x5da: jmp    a21 <do_action+0x8e0> */
	X86_SIM_X86_SUB_JMP(0x5da, 0xa21, x86_l_a21);
x86_l_5df:
	/* 0x5df: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5e4:
	/* 0x5e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e6:
	/* 0x5e6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5eb:
	/* 0x5eb: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_5f2:
	/* 0x5f2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f7:
	/* 0x5f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fc:
	/* 0x5fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe:
	/* 0x5fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_601:
	/* 0x601: je     a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x601, 0xa51, x86_l_a51);
x86_l_607:
	/* 0x607: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_60b:
	/* 0x60b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_610:
	/* 0x610: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_618:
	/* 0x618: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_61f:
	/* 0x61f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_624:
	/* 0x624: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_633:
	/* 0x633: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_636:
	/* 0x636: je     723 <do_action+0x5e2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x636, 0x723, x86_l_723);
x86_l_63c:
	/* 0x63c: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_63f:
	/* 0x63f: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_646:
	/* 0x646: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64b:
	/* 0x64b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_650:
	/* 0x650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652:
	/* 0x652: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x652, 0xa51, x86_l_a51);
x86_l_657:
	/* 0x657: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_65a:
	/* 0x65a: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_65f:
	/* 0x65f: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_662:
	/* 0x662: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_667:
	/* 0x667: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_66b:
	/* 0x66b: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_670:
	/* 0x670: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_672:
	/* 0x672: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_677:
	/* 0x677: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67b:
	/* 0x67b: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_683:
	/* 0x683: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_688:
	/* 0x688: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_68b:
	/* 0x68b: je     98f <do_action+0x84e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x68b, 0x98f, x86_l_98f);
x86_l_691:
	/* 0x691: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_698:
	/* 0x698: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69d:
	/* 0x69d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a2:
	/* 0x6a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a4:
	/* 0x6a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a7:
	/* 0x6a7: je     98f <do_action+0x84e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6a7, 0x98f, x86_l_98f);
x86_l_6ad:
	/* 0x6ad: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6b2:
	/* 0x6b2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_6b5:
	/* 0x6b5: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6bc:
	/* 0x6bc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c1:
	/* 0x6c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c6:
	/* 0x6c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c8:
	/* 0x6c8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6cf:
	/* 0x6cf: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d3:
	/* 0x6d3: mov    rax,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6d7:
	/* 0x6d7: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6dc:
	/* 0x6dc: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e0:
	/* 0x6e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e2:
	/* 0x6e2: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e7:
	/* 0x6e7: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_6ec:
	/* 0x6ec: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f0:
	/* 0x6f0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6f3:
	/* 0x6f3: je     7c4 <do_action+0x683> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6f3, 0x7c4, x86_l_7c4);
x86_l_6f9:
	/* 0x6f9: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6fc:
	/* 0x6fc: je     7c0 <do_action+0x67f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6fc, 0x7c0, x86_l_7c0);
x86_l_702:
	/* 0x702: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_704:
	/* 0x704: jne    98f <do_action+0x84e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x704, 0x98f, x86_l_98f);
x86_l_70a:
	/* 0x70a: mov    eax,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_70e:
	/* 0x70e: jmp    7c4 <do_action+0x683> */
	X86_SIM_X86_SUB_JMP(0x70e, 0x7c4, x86_l_7c4);
x86_l_713:
	/* 0x713: add    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_716:
	/* 0x716: movzx  r12d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_71a:
	/* 0x71a: xor    r12,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_71e:
	/* 0x71e: jmp    a2f <do_action+0x8ee> */
	X86_SIM_X86_SUB_JMP(0x71e, 0xa2f, x86_l_a2f);
x86_l_723:
	/* 0x723: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_72a:
	/* 0x72a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72f:
	/* 0x72f: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_734:
	/* 0x734: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_739:
	/* 0x739: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_73e:
	/* 0x73e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_740:
	/* 0x740: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_743:
	/* 0x743: je     63f <do_action+0x4fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x743, 0x63f, x86_l_63f);
x86_l_749:
	/* 0x749: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_74c:
	/* 0x74c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_74e:
	/* 0x74e: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_752:
	/* 0x752: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_759:
	/* 0x759: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_763:
	/* 0x763: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_768:
	/* 0x768: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_76f:
	/* 0x76f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_772:
	/* 0x772: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_777:
	/* 0x777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_779:
	/* 0x779: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_77c:
	/* 0x77c: je     a86 <do_action+0x945> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x77c, 0xa86, x86_l_a86);
x86_l_782:
	/* 0x782: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_784:
	/* 0x784: jmp    aa8 <do_action+0x967> */
	X86_SIM_X86_SUB_JMP(0x784, 0xaa8, x86_l_aa8);
x86_l_789:
	/* 0x789: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_790:
	/* 0x790: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_793:
	/* 0x793: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_798:
	/* 0x798: jmp    7ab <do_action+0x66a> */
	X86_SIM_X86_SUB_JMP(0x798, 0x7ab, x86_l_7ab);
x86_l_79a:
	/* 0x79a: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_7a1:
	/* 0x7a1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a6:
	/* 0x7a6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_7ab:
	/* 0x7ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ad:
	/* 0x7ad: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7b0:
	/* 0x7b0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b2:
	/* 0x7b2: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_7b5:
	/* 0x7b5: jne    a59 <do_action+0x918> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x7b5, 0xa59, x86_l_a59);
x86_l_7bb:
	/* 0x7bb: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x7bb, 0xa51, x86_l_a51);
x86_l_7c0:
	/* 0x7c0: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c4:
	/* 0x7c4: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c9:
	/* 0x7c9: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7cb:
	/* 0x7cb: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7d0:
	/* 0x7d0: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d4:
	/* 0x7d4: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7d9:
	/* 0x7d9: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_7dd:
	/* 0x7dd: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_7e2:
	/* 0x7e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7e7:
	/* 0x7e7: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7ec:
	/* 0x7ec: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_7f1:
	/* 0x7f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f3:
	/* 0x7f3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f6:
	/* 0x7f6: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7fb:
	/* 0x7fb: jmp    80b <do_action+0x6ca> */
	X86_SIM_X86_SUB_JMP(0x7fb, 0x80b, x86_l_80b);
x86_l_7fd:
	/* 0x7fd: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_801:
	/* 0x801: cmp    r12,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 20ULL);
x86_l_805:
	/* 0x805: je     938 <do_action+0x7f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x805, 0x938, x86_l_938);
x86_l_80b:
	/* 0x80b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_813:
	/* 0x813: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_818:
	/* 0x818: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_81f:
	/* 0x81f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_824:
	/* 0x824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_826:
	/* 0x826: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_829:
	/* 0x829: je     938 <do_action+0x7f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x829, 0x938, x86_l_938);
x86_l_82f:
	/* 0x82f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_832:
	/* 0x832: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_839:
	/* 0x839: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83e:
	/* 0x83e: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_845:
	/* 0x845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_847:
	/* 0x847: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84a:
	/* 0x84a: je     938 <do_action+0x7f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x84a, 0x938, x86_l_938);
x86_l_850:
	/* 0x850: cmp    DWORD PTR [rax+r12*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 279172874239ULL);
x86_l_856:
	/* 0x856: je     938 <do_action+0x7f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x856, 0x938, x86_l_938);
x86_l_85c:
	/* 0x85c: mov    rax,QWORD PTR [r13+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_864:
	/* 0x864: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_868:
	/* 0x868: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_86b:
	/* 0x86b: jge    938 <do_action+0x7f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x86b, 0x938, x86_l_938);
x86_l_871:
	/* 0x871: cmp    r12,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 16ULL);
x86_l_875:
	/* 0x875: je     8d8 <do_action+0x797> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x875, 0x8d8, x86_l_8d8);
x86_l_877:
	/* 0x877: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_87f:
	/* 0x87f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_884:
	/* 0x884: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_88b:
	/* 0x88b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_890:
	/* 0x890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_892:
	/* 0x892: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_895:
	/* 0x895: je     8d0 <do_action+0x78f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x895, 0x8d0, x86_l_8d0);
x86_l_897:
	/* 0x897: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_89a:
	/* 0x89a: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_8a1:
	/* 0x8a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a6:
	/* 0x8a6: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_8ad:
	/* 0x8ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8af:
	/* 0x8af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: je     8d0 <do_action+0x78f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8b2, 0x8d0, x86_l_8d0);
x86_l_8b4:
	/* 0x8b4: cmp    DWORD PTR [rax+r12*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 296352743423ULL);
x86_l_8ba:
	/* 0x8ba: mov    rax,QWORD PTR [r13+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_8c2:
	/* 0x8c2: je     8d8 <do_action+0x797> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8c2, 0x8d8, x86_l_8d8);
x86_l_8c4:
	/* 0x8c4: mov    ebp,DWORD PTR [r13+r12*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 1), 24192ULL);
x86_l_8cc:
	/* 0x8cc: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8ce:
	/* 0x8ce: jmp    8e1 <do_action+0x7a0> */
	X86_SIM_X86_SUB_JMP(0x8ce, 0x8e1, x86_l_8e1);
x86_l_8d0:
	/* 0x8d0: mov    rax,QWORD PTR [r13+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_8d8:
	/* 0x8d8: mov    ebp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8dc:
	/* 0x8dc: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8de:
	/* 0x8de: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_8e1:
	/* 0x8e1: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_8e3:
	/* 0x8e3: jle    7fd <do_action+0x6bc> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x8e3, 0x7fd, x86_l_7fd);
x86_l_8e9:
	/* 0x8e9: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_8ee:
	/* 0x8ee: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_8f3:
	/* 0x8f3: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_8f6:
	/* 0x8f6: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_8fb:
	/* 0x8fb: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_8fe:
	/* 0x8fe: movzx  r13d,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_904:
	/* 0x904: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_909:
	/* 0x909: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_90d:
	/* 0x90d: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_912:
	/* 0x912: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_916:
	/* 0x916: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_91d:
	/* 0x91d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_922:
	/* 0x922: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_924:
	/* 0x924: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_926:
	/* 0x926: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_929:
	/* 0x929: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_92e:
	/* 0x92e: mov    QWORD PTR [rsp+0x60],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_933:
	/* 0x933: jmp    7fd <do_action+0x6bc> */
	X86_SIM_X86_SUB_JMP(0x933, 0x7fd, x86_l_7fd);
x86_l_938:
	/* 0x938: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_93f:
	/* 0x93f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_944:
	/* 0x944: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_949:
	/* 0x949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94b:
	/* 0x94b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94e:
	/* 0x94e: je     970 <do_action+0x82f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x94e, 0x970, x86_l_970);
x86_l_950:
	/* 0x950: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_959:
	/* 0x959: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_95e:
	/* 0x95e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_961:
	/* 0x961: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_964:
	/* 0x964: jbe    970 <do_action+0x82f> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x964, 0x970, x86_l_970);
x86_l_966:
	/* 0x966: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_96b:
	/* 0x96b: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96e:
	/* 0x96e: jmp    98a <do_action+0x849> */
	X86_SIM_X86_SUB_JMP(0x96e, 0x98a, x86_l_98a);
x86_l_970:
	/* 0x970: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_977:
	/* 0x977: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_979:
	/* 0x979: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_981:
	/* 0x981: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_986:
	/* 0x986: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_988:
	/* 0x988: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98a:
	/* 0x98a: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98f:
	/* 0x98f: lea    eax,[rbx+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_992:
	/* 0x992: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_998:
	/* 0x998: je     9bb <do_action+0x87a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x998, 0x9bb, x86_l_9bb);
x86_l_99a:
	/* 0x99a: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_99f:
	/* 0x99f: mov    rsi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_9a6:
	/* 0x9a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a8:
	/* 0x9a8: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_9ad:
	/* 0x9ad: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9b0:
	/* 0x9b0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b2:
	/* 0x9b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b4:
	/* 0x9b4: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9bb:
	/* 0x9bb: lea    eax,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9be:
	/* 0x9be: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_9c4:
	/* 0x9c4: je     9ed <do_action+0x8ac> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9c4, 0x9ed, x86_l_9ed);
x86_l_9c6:
	/* 0x9c6: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_9cb:
	/* 0x9cb: mov    rsi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_9d2:
	/* 0x9d2: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_9d7:
	/* 0x9d7: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_9dc:
	/* 0x9dc: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_9e1:
	/* 0x9e1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9e4:
	/* 0x9e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e6:
	/* 0x9e6: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9ed:
	/* 0x9ed: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_9f0:
	/* 0x9f0: cmp    DWORD PTR [r15+rbx*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 17179869184ULL);
x86_l_9f6:
	/* 0x9f6: je     a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9f6, 0xa51, x86_l_a51);
x86_l_9f8:
	/* 0x9f8: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_9fd:
	/* 0x9fd: jmp    a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JMP(0x9fd, 0xa51, x86_l_a51);
x86_l_9ff:
	/* 0x9ff: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_a07:
	/* 0xa07: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a0e:
	/* 0xa0e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a10:
	/* 0xa10: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a13:
	/* 0xa13: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a18:
	/* 0xa18: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a1d:
	/* 0xa1d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a1f:
	/* 0xa1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a21:
	/* 0xa21: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: je     a68 <do_action+0x927> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa24, 0xa68, x86_l_a68);
x86_l_a26:
	/* 0xa26: mov    DWORD PTR [r15],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a29:
	/* 0xa29: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_a2f:
	/* 0xa2f: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a36:
	/* 0xa36: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_a3d:
	/* 0xa3d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a40:
	/* 0xa40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a45:
	/* 0xa45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a47:
	/* 0xa47: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a4a:
	/* 0xa4a: je     a51 <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa4a, 0xa51, x86_l_a51);
x86_l_a4c:
	/* 0xa4c: inc QWORD PTR [rax+r12*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R12, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a51:
	/* 0xa51: mov    QWORD PTR [r13+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a55:
	/* 0xa55: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a57:
	/* 0xa57: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_a59:
	/* 0xa59: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_a5d:
	/* 0xa5d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_a5e:
	/* 0xa5e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_a60:
	/* 0xa60: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_a62:
	/* 0xa62: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_a64:
	/* 0xa64: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_a66:
	/* 0xa66: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_a68:
	/* 0xa68: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_a6f:
	/* 0xa6f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a71:
	/* 0xa71: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a76:
	/* 0xa76: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a7b:
	/* 0xa7b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a80:
	/* 0xa80: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a82:
	/* 0xa82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a84:
	/* 0xa84: jmp    a29 <do_action+0x8e8> */
	X86_SIM_X86_SUB_JMP(0xa84, 0xa29, x86_l_a29);
x86_l_a86:
	/* 0xa86: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_a8e:
	/* 0xa8e: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a95:
	/* 0xa95: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a97:
	/* 0xa97: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a9a:
	/* 0xa9a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a9f:
	/* 0xa9f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_aa4:
	/* 0xaa4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa6:
	/* 0xaa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa8:
	/* 0xaa8: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_aab:
	/* 0xaab: je     63f <do_action+0x4fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaab, 0x63f, x86_l_63f);
x86_l_ab1:
	/* 0xab1: mov    rdi,QWORD PTR [rip+0x2490] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_ab8:
	/* 0xab8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_abd:
	/* 0xabd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac2:
	/* 0xac2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac4:
	/* 0xac4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac7:
	/* 0xac7: je     63f <do_action+0x4fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xac7, 0x63f, x86_l_63f);
x86_l_acd:
	/* 0xacd: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ad1:
	/* 0xad1: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ad4:
	/* 0xad4: jmp    63f <do_action+0x4fe> */
	X86_SIM_X86_SUB_JMP(0xad4, 0x63f, x86_l_63f);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x26ULL: goto x86_l_26;
	case 0x58ULL: goto x86_l_58;
	case 0x9bULL: goto x86_l_9b;
	case 0xceULL: goto x86_l_ce;
	case 0xefULL: goto x86_l_ef;
	case 0x110ULL: goto x86_l_110;
	case 0x132ULL: goto x86_l_132;
	case 0x181ULL: goto x86_l_181;
	case 0x268ULL: goto x86_l_268;
	case 0x281ULL: goto x86_l_281;
	case 0x2d3ULL: goto x86_l_2d3;
	case 0x2f3ULL: goto x86_l_2f3;
	case 0x36aULL: goto x86_l_36a;
	case 0x3c3ULL: goto x86_l_3c3;
	case 0x430ULL: goto x86_l_430;
	case 0x4a4ULL: goto x86_l_4a4;
	case 0x4bfULL: goto x86_l_4bf;
	case 0x4feULL: goto x86_l_4fe;
	case 0x51cULL: goto x86_l_51c;
	case 0x567ULL: goto x86_l_567;
	case 0x57fULL: goto x86_l_57f;
	case 0x5cfULL: goto x86_l_5cf;
	case 0x5e6ULL: goto x86_l_5e6;
	case 0x5feULL: goto x86_l_5fe;
	case 0x62bULL: goto x86_l_62b;
	case 0x652ULL: goto x86_l_652;
	case 0x672ULL: goto x86_l_672;
	case 0x6a4ULL: goto x86_l_6a4;
	case 0x6c8ULL: goto x86_l_6c8;
	case 0x740ULL: goto x86_l_740;
	case 0x779ULL: goto x86_l_779;
	case 0x7adULL: goto x86_l_7ad;
	case 0x7f3ULL: goto x86_l_7f3;
	case 0x826ULL: goto x86_l_826;
	case 0x847ULL: goto x86_l_847;
	case 0x892ULL: goto x86_l_892;
	case 0x8afULL: goto x86_l_8af;
	case 0x926ULL: goto x86_l_926;
	case 0x94bULL: goto x86_l_94b;
	case 0x98aULL: goto x86_l_98a;
	case 0x9b4ULL: goto x86_l_9b4;
	case 0x9e6ULL: goto x86_l_9e6;
	case 0xa21ULL: goto x86_l_a21;
	case 0xa47ULL: goto x86_l_a47;
	case 0xa84ULL: goto x86_l_a84;
	case 0xaa8ULL: goto x86_l_aa8;
	case 0xac4ULL: goto x86_l_ac4;
	}

}

X86_SIM_LICENSE();
