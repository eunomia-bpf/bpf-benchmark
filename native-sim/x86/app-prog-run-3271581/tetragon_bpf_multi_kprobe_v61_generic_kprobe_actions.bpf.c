extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char heap_ro_zero;
extern char kprobe_calls;
extern char override_tasks;
extern char policy_conf;
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
int tetragon_bpf_multi_kprobe_v61_generic_kprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x13: mov    rdi,QWORD PTR [rip+0x6170] */
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
	/* 0x29: je     132 <generic_kprobe_actions+0x132> */
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
	/* 0x3d: jl     132 <generic_kprobe_actions+0x132> */
	X86_SIM_X86_JCC(X86_CC_L, 0x3d, 0x132, x86_l_132);
x86_l_43:
	/* 0x43: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_4a:
	/* 0x4a: mov    rdi,QWORD PTR [rip+0x6170] */
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
	/* 0x5b: je     132 <generic_kprobe_actions+0x132> */
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
	/* 0x7b: mov    rdi,QWORD PTR [rip+0x6170] */
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
	/* 0x9e: je     ae <generic_kprobe_actions+0xae> */
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
	/* 0xaa: jae    b6 <generic_kprobe_actions+0xb6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xaa, 0xb6, x86_l_b6);
x86_l_ac:
	/* 0xac: jmp    110 <generic_kprobe_actions+0x110> */
	X86_SIM_X86_JMP(0xac, 0x110, x86_l_110);
x86_l_ae:
	/* 0xae: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_b0:
	/* 0xb0: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_b4:
	/* 0xb4: jb     110 <generic_kprobe_actions+0x110> */
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
	/* 0xc9: call   0 <generic_kprobe_actions> */
	X86_SIM_X86_CALL(x86_l_141, 0xceULL);
x86_l_ce:
	/* 0xce: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_d5:
	/* 0xd5: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d8:
	/* 0xd8: jae    110 <generic_kprobe_actions+0x110> */
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
	/* 0xea: call   0 <generic_kprobe_actions> */
	X86_SIM_X86_CALL(x86_l_141, 0xefULL);
x86_l_ef:
	/* 0xef: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_f6:
	/* 0xf6: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_f9:
	/* 0xf9: jae    110 <generic_kprobe_actions+0x110> */
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
	/* 0x10b: call   0 <generic_kprobe_actions> */
	X86_SIM_X86_CALL(x86_l_141, 0x110ULL);
x86_l_110:
	/* 0x110: cmp    BYTE PTR [rsp+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_115:
	/* 0x115: je     132 <generic_kprobe_actions+0x132> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115, 0x132, x86_l_132);
x86_l_117:
	/* 0x117: mov    rsi,QWORD PTR [rip+0x6170] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
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
	/* 0x13c: jmp    d59 <do_action+0xc18> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_d59:
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
	/* 0x14b: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_152:
	/* 0x152: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_155:
	/* 0x155: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15a:
	/* 0x15a: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_160:
	/* 0x160: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_163:
	/* 0x163: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_165:
	/* 0x165: movsxd rbx,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_16a:
	/* 0x16a: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_172:
	/* 0x172: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_179:
	/* 0x179: lea    rsi,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_17e:
	/* 0x17e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_183:
	/* 0x183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185:
	/* 0x185: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_188:
	/* 0x188: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a:
	/* 0x18a: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_18d:
	/* 0x18d: je     984 <do_action+0x843> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18d, 0x984, x86_l_984);
x86_l_193:
	/* 0x193: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_196:
	/* 0x196: jg     1bc <do_action+0x7b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x196, 0x1bc, x86_l_1bc);
x86_l_198:
	/* 0x198: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_19b:
	/* 0x19b: jg     1f8 <do_action+0xb7> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x19b, 0x1f8, x86_l_1f8);
x86_l_19d:
	/* 0x19d: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1a0:
	/* 0x1a0: jg     27f <do_action+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1a0, 0x27f, x86_l_27f);
x86_l_1a6:
	/* 0x1a6: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1a8:
	/* 0x1a8: je     585 <do_action+0x444> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a8, 0x585, x86_l_585);
x86_l_1ae:
	/* 0x1ae: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1b1:
	/* 0x1b1: je     296 <do_action+0x155> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b1, 0x296, x86_l_296);
x86_l_1b7:
	/* 0x1b7: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x1b7, 0x979, x86_l_979);
x86_l_1bc:
	/* 0x1bc: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_1bf:
	/* 0x1bf: jg     248 <do_action+0x107> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1bf, 0x248, x86_l_248);
x86_l_1c5:
	/* 0x1c5: lea    ecx,[rbx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1cb:
	/* 0x1cb: jb     3a9 <do_action+0x268> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1cb, 0x3a9, x86_l_3a9);
x86_l_1d1:
	/* 0x1d1: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1d4:
	/* 0x1d4: je     47f <do_action+0x33e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d4, 0x47f, x86_l_47f);
x86_l_1da:
	/* 0x1da: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_1dd:
	/* 0x1dd: jne    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1dd, 0x979, x86_l_979);
x86_l_1e3:
	/* 0x1e3: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1e6:
	/* 0x1e6: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb:
	/* 0x1eb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ee:
	/* 0x1ee: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_1f3:
	/* 0x1f3: jmp    64b <do_action+0x50a> */
	X86_SIM_X86_SUB_JMP(0x1f3, 0x64b, x86_l_64b);
x86_l_1f8:
	/* 0x1f8: lea    eax,[rbx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1fb:
	/* 0x1fb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fe:
	/* 0x1fe: jb     46d <do_action+0x32c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fe, 0x46d, x86_l_46d);
x86_l_204:
	/* 0x204: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_207:
	/* 0x207: je     48c <do_action+0x34b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x207, 0x48c, x86_l_48c);
x86_l_20d:
	/* 0x20d: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_210:
	/* 0x210: jne    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x210, 0x979, x86_l_979);
x86_l_216:
	/* 0x216: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_219:
	/* 0x219: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_21c:
	/* 0x21c: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_220:
	/* 0x220: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_225:
	/* 0x225: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_229:
	/* 0x229: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_22c:
	/* 0x22c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f:
	/* 0x22f: ja     240 <do_action+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x22f, 0x240, x86_l_240);
x86_l_231:
	/* 0x231: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_23a:
	/* 0x23a: je     7e2 <do_action+0x6a1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x23a, 0x7e2, x86_l_7e2);
x86_l_240:
	/* 0x240: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_243:
	/* 0x243: jmp    976 <do_action+0x835> */
	X86_SIM_X86_SUB_JMP(0x243, 0x976, x86_l_976);
x86_l_248:
	/* 0x248: cmp    ebx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 12ULL);
x86_l_24b:
	/* 0x24b: je     670 <do_action+0x52f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x24b, 0x670, x86_l_670);
x86_l_251:
	/* 0x251: cmp    ebx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 13ULL);
x86_l_254:
	/* 0x254: je     50d <do_action+0x3cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x254, 0x50d, x86_l_50d);
x86_l_25a:
	/* 0x25a: cmp    ebx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_25d:
	/* 0x25d: jne    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x25d, 0x979, x86_l_979);
x86_l_263:
	/* 0x263: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_266:
	/* 0x266: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26b:
	/* 0x26b: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_26f:
	/* 0x26f: movzx  ebx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_273:
	/* 0x273: xor    rbx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_277:
	/* 0x277: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_27a:
	/* 0x27a: jmp    94c <do_action+0x80b> */
	X86_SIM_X86_SUB_JMP(0x27a, 0x94c, x86_l_94c);
x86_l_27f:
	/* 0x27f: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_284:
	/* 0x284: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_287:
	/* 0x287: je     643 <do_action+0x502> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x287, 0x643, x86_l_643);
x86_l_28d:
	/* 0x28d: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_290:
	/* 0x290: jne    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x290, 0x979, x86_l_979);
x86_l_296:
	/* 0x296: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_299:
	/* 0x299: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_29d:
	/* 0x29d: mov    r13d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_2a2:
	/* 0x2a2: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2a6:
	/* 0x2a6: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_2ab:
	/* 0x2ab: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b3:
	/* 0x2b3: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_2ba:
	/* 0x2ba: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf:
	/* 0x2bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c4:
	/* 0x2c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6:
	/* 0x2c6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c9:
	/* 0x2c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: je     913 <do_action+0x7d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2cc, 0x913, x86_l_913);
x86_l_2d2:
	/* 0x2d2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d7:
	/* 0x2d7: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2db:
	/* 0x2db: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2df:
	/* 0x2df: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2e4:
	/* 0x2e4: ja     915 <do_action+0x7d4> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2e4, 0x915, x86_l_915);
x86_l_2ea:
	/* 0x2ea: cmp    DWORD PTR [r12+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_2f3:
	/* 0x2f3: jne    915 <do_action+0x7d4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2f3, 0x915, x86_l_915);
x86_l_2f9:
	/* 0x2f9: mov    rax,QWORD PTR [r12+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_301:
	/* 0x301: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_309:
	/* 0x309: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_30e:
	/* 0x30e: mov    eax,DWORD PTR [r12+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_316:
	/* 0x316: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a:
	/* 0x31a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_31f:
	/* 0x31f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321:
	/* 0x321: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_325:
	/* 0x325: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_329:
	/* 0x329: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_32c:
	/* 0x32c: jne    8ff <do_action+0x7be> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x32c, 0x8ff, x86_l_8ff);
x86_l_332:
	/* 0x332: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_335:
	/* 0x335: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_338:
	/* 0x338: ja     913 <do_action+0x7d2> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x338, 0x913, x86_l_913);
x86_l_33e:
	/* 0x33e: cmp    DWORD PTR [r12+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_347:
	/* 0x347: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_34c:
	/* 0x34c: jne    915 <do_action+0x7d4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x34c, 0x915, x86_l_915);
x86_l_352:
	/* 0x352: mov    rax,QWORD PTR [r12+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_35a:
	/* 0x35a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_35f:
	/* 0x35f: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_363:
	/* 0x363: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_36a:
	/* 0x36a: mov    esi,DWORD PTR [r12+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_372:
	/* 0x372: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_378:
	/* 0x378: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37c:
	/* 0x37c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_381:
	/* 0x381: mov    rbx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_386:
	/* 0x386: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_389:
	/* 0x389: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b:
	/* 0x38b: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_392:
	/* 0x392: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_395:
	/* 0x395: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_398:
	/* 0x398: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_39d:
	/* 0x39d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a2:
	/* 0x3a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a4:
	/* 0x3a4: jmp    913 <do_action+0x7d2> */
	X86_SIM_X86_SUB_JMP(0x3a4, 0x913, x86_l_913);
x86_l_3a9:
	/* 0x3a9: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3ac:
	/* 0x3ac: mov    ecx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_3b1:
	/* 0x3b1: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3b4:
	/* 0x3b4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b7:
	/* 0x3b7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3ba:
	/* 0x3ba: ja     918 <do_action+0x7d7> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3ba, 0x918, x86_l_918);
x86_l_3c0:
	/* 0x3c0: cmp    DWORD PTR [r12+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_3c9:
	/* 0x3c9: jne    918 <do_action+0x7d7> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3c9, 0x918, x86_l_918);
x86_l_3cf:
	/* 0x3cf: mov    rcx,QWORD PTR [r12+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_3d7:
	/* 0x3d7: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3dd:
	/* 0x3dd: mov    rcx,QWORD PTR [r12+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_3e5:
	/* 0x3e5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ea:
	/* 0x3ea: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3ed:
	/* 0x3ed: je     918 <do_action+0x7d7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3ed, 0x918, x86_l_918);
x86_l_3f3:
	/* 0x3f3: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3f6:
	/* 0x3f6: jne    996 <do_action+0x855> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3f6, 0x996, x86_l_996);
x86_l_3fc:
	/* 0x3fc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_401:
	/* 0x401: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_403:
	/* 0x403: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_406:
	/* 0x406: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_40a:
	/* 0x40a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40d:
	/* 0x40d: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_414:
	/* 0x414: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_417:
	/* 0x417: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41c:
	/* 0x41c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e:
	/* 0x41e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_421:
	/* 0x421: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_424:
	/* 0x424: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_429:
	/* 0x429: je     918 <do_action+0x7d7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x429, 0x918, x86_l_918);
x86_l_42f:
	/* 0x42f: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_431:
	/* 0x431: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_434:
	/* 0x434: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_439:
	/* 0x439: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d:
	/* 0x43d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442:
	/* 0x442: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_449:
	/* 0x449: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44c:
	/* 0x44c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_451:
	/* 0x451: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_454:
	/* 0x454: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_459:
	/* 0x459: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45b:
	/* 0x45b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d:
	/* 0x45d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45f:
	/* 0x45f: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_462:
	/* 0x462: jne    984 <do_action+0x843> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x462, 0x984, x86_l_984);
x86_l_468:
	/* 0x468: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x468, 0x979, x86_l_979);
x86_l_46d:
	/* 0x46d: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_470:
	/* 0x470: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_475:
	/* 0x475: mov    DWORD PTR [r12+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_47a:
	/* 0x47a: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x47a, 0x979, x86_l_979);
x86_l_47f:
	/* 0x47f: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_484:
	/* 0x484: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_487:
	/* 0x487: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x487, 0x979, x86_l_979);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_491:
	/* 0x491: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_494:
	/* 0x494: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_499:
	/* 0x499: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_49c:
	/* 0x49c: je     74d <do_action+0x60c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x49c, 0x74d, x86_l_74d);
x86_l_4a2:
	/* 0x4a2: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_4a5:
	/* 0x4a5: mov    ebx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_4aa:
	/* 0x4aa: mov    DWORD PTR [rsp+0x38],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4ae:
	/* 0x4ae: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4b3:
	/* 0x4b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5:
	/* 0x4b5: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba:
	/* 0x4ba: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_4c1:
	/* 0x4c1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c6:
	/* 0x4c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4cb:
	/* 0x4cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd:
	/* 0x4cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d0:
	/* 0x4d0: je     7be <do_action+0x67d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4d0, 0x7be, x86_l_7be);
x86_l_4d6:
	/* 0x4d6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4d9:
	/* 0x4d9: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_4dc:
	/* 0x4dc: mov    DWORD PTR [rsp],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 917521ULL);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rsp+0x4],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179870047ULL);
x86_l_4ec:
	/* 0x4ec: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_4f3:
	/* 0x4f3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4f6:
	/* 0x4f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4fb:
	/* 0x4fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fd:
	/* 0x4fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_500:
	/* 0x500: je     91f <do_action+0x7de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x500, 0x91f, x86_l_91f);
x86_l_506:
	/* 0x506: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_508:
	/* 0x508: jmp    941 <do_action+0x800> */
	X86_SIM_X86_SUB_JMP(0x508, 0x941, x86_l_941);
x86_l_50d:
	/* 0x50d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_512:
	/* 0x512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_514:
	/* 0x514: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_519:
	/* 0x519: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_520:
	/* 0x520: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_525:
	/* 0x525: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52a:
	/* 0x52a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52c:
	/* 0x52c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52f:
	/* 0x52f: je     979 <do_action+0x838> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x52f, 0x979, x86_l_979);
x86_l_535:
	/* 0x535: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_539:
	/* 0x539: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53e:
	/* 0x53e: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_546:
	/* 0x546: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_54d:
	/* 0x54d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_552:
	/* 0x552: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_561:
	/* 0x561: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_564:
	/* 0x564: je     758 <do_action+0x617> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x564, 0x758, x86_l_758);
x86_l_56a:
	/* 0x56a: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_56d:
	/* 0x56d: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_574:
	/* 0x574: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_579:
	/* 0x579: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_57e:
	/* 0x57e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_580:
	/* 0x580: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x580, 0x979, x86_l_979);
x86_l_585:
	/* 0x585: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_58a:
	/* 0x58a: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_58e:
	/* 0x58e: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_593:
	/* 0x593: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_597:
	/* 0x597: mov    ebx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_59c:
	/* 0x59c: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_5a1:
	/* 0x5a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a3:
	/* 0x5a3: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ac:
	/* 0x5ac: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5b4:
	/* 0x5b4: mov    QWORD PTR [rsp+0x78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5b9:
	/* 0x5b9: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: je     be7 <do_action+0xaa6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5bc, 0xbe7, x86_l_be7);
x86_l_5c2:
	/* 0x5c2: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_5c9:
	/* 0x5c9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ce:
	/* 0x5ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d3:
	/* 0x5d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d5:
	/* 0x5d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d8:
	/* 0x5d8: je     be7 <do_action+0xaa6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5d8, 0xbe7, x86_l_be7);
x86_l_5de:
	/* 0x5de: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5e3:
	/* 0x5e3: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5e6:
	/* 0x5e6: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5ed:
	/* 0x5ed: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f2:
	/* 0x5f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f7:
	/* 0x5f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f9:
	/* 0x5f9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5fc:
	/* 0x5fc: mov    rax,QWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_601:
	/* 0x601: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_605:
	/* 0x605: mov    rax,QWORD PTR [r12+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_60a:
	/* 0x60a: mov    QWORD PTR [rsp+0x50],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_60f:
	/* 0x60f: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_613:
	/* 0x613: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_615:
	/* 0x615: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_61a:
	/* 0x61a: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_61f:
	/* 0x61f: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_622:
	/* 0x622: je     a20 <do_action+0x8df> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x622, 0xa20, x86_l_a20);
x86_l_628:
	/* 0x628: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_62b:
	/* 0x62b: je     a1b <do_action+0x8da> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x62b, 0xa1b, x86_l_a1b);
x86_l_631:
	/* 0x631: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_633:
	/* 0x633: jne    be7 <do_action+0xaa6> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x633, 0xbe7, x86_l_be7);
x86_l_639:
	/* 0x639: mov    eax,DWORD PTR [r12+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_63e:
	/* 0x63e: jmp    a20 <do_action+0x8df> */
	X86_SIM_X86_SUB_JMP(0x63e, 0xa20, x86_l_a20);
x86_l_643:
	/* 0x643: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_646:
	/* 0x646: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64b:
	/* 0x64b: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_64e:
	/* 0x64e: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_653:
	/* 0x653: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_656:
	/* 0x656: je     94c <do_action+0x80b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x656, 0x94c, x86_l_94c);
x86_l_65c:
	/* 0x65c: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_65f:
	/* 0x65f: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_664:
	/* 0x664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_666:
	/* 0x666: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_66b:
	/* 0x66b: jmp    94c <do_action+0x80b> */
	X86_SIM_X86_SUB_JMP(0x66b, 0x94c, x86_l_94c);
x86_l_670:
	/* 0x670: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_673:
	/* 0x673: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_678:
	/* 0x678: lea    r12d,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_67c:
	/* 0x67c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_681:
	/* 0x681: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_684:
	/* 0x684: je     94c <do_action+0x80b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x684, 0x94c, x86_l_94c);
x86_l_68a:
	/* 0x68a: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_68d:
	/* 0x68d: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_692:
	/* 0x692: lea    ecx,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_696:
	/* 0x696: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_699:
	/* 0x699: mov    ebx,DWORD PTR [r15+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_69e:
	/* 0x69e: mov    ebp,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_6a3:
	/* 0x6a3: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_6a7:
	/* 0x6a7: ja     6b8 <do_action+0x577> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x6a7, 0x6b8, x86_l_6b8);
x86_l_6a9:
	/* 0x6a9: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_6b2:
	/* 0x6b2: je     c6b <do_action+0xb2a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6b2, 0xc6b, x86_l_c6b);
x86_l_6b8:
	/* 0x6b8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ba:
	/* 0x6ba: mov    r14d,DWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6be:
	/* 0x6be: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6c1:
	/* 0x6c1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6c6:
	/* 0x6c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c8:
	/* 0x6c8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6cd:
	/* 0x6cd: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d2:
	/* 0x6d2: mov    WORD PTR [rsp+0x12],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_6d7:
	/* 0x6d7: mov    QWORD PTR [rsp+0x14],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6dc:
	/* 0x6dc: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_6e3:
	/* 0x6e3: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ed:
	/* 0x6ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ef:
	/* 0x6ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f2:
	/* 0x6f2: je     89d <do_action+0x75c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6f2, 0x89d, x86_l_89d);
x86_l_6f8:
	/* 0x6f8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6fb:
	/* 0x6fb: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6ff:
	/* 0x6ff: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_704:
	/* 0x704: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_70c:
	/* 0x70c: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_713:
	/* 0x713: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_718:
	/* 0x718: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_71d:
	/* 0x71d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71f:
	/* 0x71f: mov    DWORD PTR [rsp+0x44],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776129ULL);
x86_l_727:
	/* 0x727: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72a:
	/* 0x72a: je     9b5 <do_action+0x874> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x72a, 0x9b5, x86_l_9b5);
x86_l_730:
	/* 0x730: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_733:
	/* 0x733: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_737:
	/* 0x737: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73b:
	/* 0x73b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_740:
	/* 0x740: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_743:
	/* 0x743: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_748:
	/* 0x748: jmp    94c <do_action+0x80b> */
	X86_SIM_X86_SUB_JMP(0x748, 0x94c, x86_l_94c);
x86_l_74d:
	/* 0x74d: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_750:
	/* 0x750: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_753:
	/* 0x753: jmp    94c <do_action+0x80b> */
	X86_SIM_X86_SUB_JMP(0x753, 0x94c, x86_l_94c);
x86_l_758:
	/* 0x758: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_75f:
	/* 0x75f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_764:
	/* 0x764: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_769:
	/* 0x769: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_76e:
	/* 0x76e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_773:
	/* 0x773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_775:
	/* 0x775: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_778:
	/* 0x778: je     56d <do_action+0x42c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x778, 0x56d, x86_l_56d);
x86_l_77e:
	/* 0x77e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_781:
	/* 0x781: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_783:
	/* 0x783: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_787:
	/* 0x787: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_78e:
	/* 0x78e: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_798:
	/* 0x798: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79d:
	/* 0x79d: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7a4:
	/* 0x7a4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_7a7:
	/* 0x7a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b1:
	/* 0x7b1: je     c8c <do_action+0xb4b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x7b1, 0xc8c, x86_l_c8c);
x86_l_7b7:
	/* 0x7b7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7b9:
	/* 0x7b9: jmp    cae <do_action+0xb6d> */
	X86_SIM_X86_SUB_JMP(0x7b9, 0xcae, x86_l_cae);
x86_l_7be:
	/* 0x7be: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_7c1:
	/* 0x7c1: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_7c8:
	/* 0x7c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ca:
	/* 0x7ca: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7cf:
	/* 0x7cf: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7d9:
	/* 0x7d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7db:
	/* 0x7db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dd:
	/* 0x7dd: jmp    944 <do_action+0x803> */
	X86_SIM_X86_SUB_JMP(0x7dd, 0x944, x86_l_944);
x86_l_7e2:
	/* 0x7e2: mov    ebx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_7e7:
	/* 0x7e7: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_7ef:
	/* 0x7ef: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_7f7:
	/* 0x7f7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7fc:
	/* 0x7fc: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_804:
	/* 0x804: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_808:
	/* 0x808: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_80d:
	/* 0x80d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80f:
	/* 0x80f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_813:
	/* 0x813: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_817:
	/* 0x817: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_81e:
	/* 0x81e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_821:
	/* 0x821: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_826:
	/* 0x826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_828:
	/* 0x828: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_82b:
	/* 0x82b: je     240 <do_action+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x82b, 0x240, x86_l_240);
x86_l_831:
	/* 0x831: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_834:
	/* 0x834: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_837:
	/* 0x837: ja     240 <do_action+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x837, 0x240, x86_l_240);
x86_l_83d:
	/* 0x83d: cmp    DWORD PTR [r13+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_846:
	/* 0x846: jne    240 <do_action+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x846, 0x240, x86_l_240);
x86_l_84c:
	/* 0x84c: mov    rcx,QWORD PTR [r13+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_854:
	/* 0x854: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_85c:
	/* 0x85c: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_862:
	/* 0x862: mov    ecx,DWORD PTR [r13+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_86a:
	/* 0x86a: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86e:
	/* 0x86e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_871:
	/* 0x871: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_876:
	/* 0x876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_878:
	/* 0x878: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_87c:
	/* 0x87c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_880:
	/* 0x880: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_887:
	/* 0x887: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_889:
	/* 0x889: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_88c:
	/* 0x88c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_891:
	/* 0x891: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_894:
	/* 0x894: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_896:
	/* 0x896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_898:
	/* 0x898: jmp    240 <do_action+0xff> */
	X86_SIM_X86_SUB_JMP(0x898, 0x240, x86_l_240);
x86_l_89d:
	/* 0x89d: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_8a4:
	/* 0x8a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a6:
	/* 0x8a6: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8ab:
	/* 0x8ab: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b0:
	/* 0x8b0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8b5:
	/* 0x8b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b7:
	/* 0x8b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b9:
	/* 0x8b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8bc:
	/* 0x8bc: je     743 <do_action+0x602> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8bc, 0x743, x86_l_743);
x86_l_8c2:
	/* 0x8c2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8c4:
	/* 0x8c4: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c8:
	/* 0x8c8: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_8cf:
	/* 0x8cf: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_8d9:
	/* 0x8d9: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8de:
	/* 0x8de: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8e5:
	/* 0x8e5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8e8:
	/* 0x8e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8ed:
	/* 0x8ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ef:
	/* 0x8ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f2:
	/* 0x8f2: je     cdf <do_action+0xb9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8f2, 0xcdf, x86_l_cdf);
x86_l_8f8:
	/* 0x8f8: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8fa:
	/* 0x8fa: jmp    743 <do_action+0x602> */
	X86_SIM_X86_SUB_JMP(0x8fa, 0x743, x86_l_743);
x86_l_8ff:
	/* 0x8ff: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_906:
	/* 0x906: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_909:
	/* 0x909: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_90e:
	/* 0x90e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_910:
	/* 0x910: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_913:
	/* 0x913: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_915:
	/* 0x915: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_918:
	/* 0x918: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_91b:
	/* 0x91b: jne    984 <do_action+0x843> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x91b, 0x984, x86_l_984);
x86_l_91d:
	/* 0x91d: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x91d, 0x979, x86_l_979);
x86_l_91f:
	/* 0x91f: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_927:
	/* 0x927: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_92e:
	/* 0x92e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_930:
	/* 0x930: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_933:
	/* 0x933: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_938:
	/* 0x938: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_93d:
	/* 0x93d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93f:
	/* 0x93f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_941:
	/* 0x941: mov    DWORD PTR [r15],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_944:
	/* 0x944: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_949:
	/* 0x949: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_94c:
	/* 0x94c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_953:
	/* 0x953: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_95a:
	/* 0x95a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_95d:
	/* 0x95d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_962:
	/* 0x962: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_964:
	/* 0x964: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_967:
	/* 0x967: je     96e <do_action+0x82d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x967, 0x96e, x86_l_96e);
x86_l_969:
	/* 0x969: inc QWORD PTR [rax+rbx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_96e:
	/* 0x96e: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_971:
	/* 0x971: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_976:
	/* 0x976: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_979:
	/* 0x979: mov    QWORD PTR [r12+0x70],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_97e:
	/* 0x97e: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_981:
	/* 0x981: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_984:
	/* 0x984: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_98b:
	/* 0x98b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_98e:
	/* 0x98e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_990:
	/* 0x990: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_992:
	/* 0x992: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_994:
	/* 0x994: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_995:
	/* 0x995: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_996:
	/* 0x996: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_99d:
	/* 0x99d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a2:
	/* 0x9a2: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_9a7:
	/* 0x9a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a9:
	/* 0x9a9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_9ac:
	/* 0x9ac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ae:
	/* 0x9ae: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_9b1:
	/* 0x9b1: jne    984 <do_action+0x843> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x9b1, 0x984, x86_l_984);
x86_l_9b3:
	/* 0x9b3: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0x9b3, 0x979, x86_l_979);
x86_l_9b5:
	/* 0x9b5: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_9bc:
	/* 0x9bc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c1:
	/* 0x9c1: lea    rdx,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_9c6:
	/* 0x9c6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9cb:
	/* 0x9cb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9d0:
	/* 0x9d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d2:
	/* 0x9d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9d5:
	/* 0x9d5: je     733 <do_action+0x5f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9d5, 0x733, x86_l_733);
x86_l_9db:
	/* 0x9db: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_9de:
	/* 0x9de: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_9e0:
	/* 0x9e0: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e4:
	/* 0x9e4: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_9eb:
	/* 0x9eb: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_9f5:
	/* 0x9f5: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9fa:
	/* 0x9fa: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a01:
	/* 0xa01: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a04:
	/* 0xa04: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a09:
	/* 0xa09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0b:
	/* 0xa0b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0e:
	/* 0xa0e: je     d06 <do_action+0xbc5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa0e, 0xd06, x86_l_d06);
x86_l_a14:
	/* 0xa14: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a16:
	/* 0xa16: jmp    d28 <do_action+0xbe7> */
	X86_SIM_X86_SUB_JMP(0xa16, 0xd28, x86_l_d28);
x86_l_a1b:
	/* 0xa1b: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a20:
	/* 0xa20: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a22:
	/* 0xa22: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a27:
	/* 0xa27: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a2b:
	/* 0xa2b: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a30:
	/* 0xa30: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a34:
	/* 0xa34: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_a39:
	/* 0xa39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a3e:
	/* 0xa3e: mov    QWORD PTR [rsp+0x58],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a43:
	/* 0xa43: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_a48:
	/* 0xa48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4a:
	/* 0xa4a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a4c:
	/* 0xa4c: mov    QWORD PTR [rsp+0x80],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a54:
	/* 0xa54: jmp    a64 <do_action+0x923> */
	X86_SIM_X86_SUB_JMP(0xa54, 0xa64, x86_l_a64);
x86_l_a56:
	/* 0xa56: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a5a:
	/* 0xa5a: cmp    rbx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 20ULL);
x86_l_a5e:
	/* 0xa5e: je     b95 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa5e, 0xb95, x86_l_b95);
x86_l_a64:
	/* 0xa64: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a6c:
	/* 0xa6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a71:
	/* 0xa71: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a78:
	/* 0xa78: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7d:
	/* 0xa7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7f:
	/* 0xa7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a82:
	/* 0xa82: je     b95 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa82, 0xb95, x86_l_b95);
x86_l_a88:
	/* 0xa88: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a8b:
	/* 0xa8b: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_a92:
	/* 0xa92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a97:
	/* 0xa97: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_a9e:
	/* 0xa9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa0:
	/* 0xaa0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa3:
	/* 0xaa3: je     b95 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaa3, 0xb95, x86_l_b95);
x86_l_aa9:
	/* 0xaa9: cmp    DWORD PTR [rax+rbx*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 279172874239ULL);
x86_l_aae:
	/* 0xaae: je     b95 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaae, 0xb95, x86_l_b95);
x86_l_ab4:
	/* 0xab4: mov    rax,QWORD PTR [r12+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_abc:
	/* 0xabc: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ac1:
	/* 0xac1: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_ac4:
	/* 0xac4: jge    b95 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0xac4, 0xb95, x86_l_b95);
x86_l_aca:
	/* 0xaca: cmp    rbx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 16ULL);
x86_l_ace:
	/* 0xace: je     b30 <do_action+0x9ef> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xace, 0xb30, x86_l_b30);
x86_l_ad0:
	/* 0xad0: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ad8:
	/* 0xad8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_add:
	/* 0xadd: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ae4:
	/* 0xae4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae9:
	/* 0xae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aeb:
	/* 0xaeb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: je     b28 <do_action+0x9e7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaee, 0xb28, x86_l_b28);
x86_l_af0:
	/* 0xaf0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_af3:
	/* 0xaf3: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_afa:
	/* 0xafa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aff:
	/* 0xaff: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_b06:
	/* 0xb06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b08:
	/* 0xb08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b0b:
	/* 0xb0b: je     b28 <do_action+0x9e7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb0b, 0xb28, x86_l_b28);
x86_l_b0d:
	/* 0xb0d: cmp    DWORD PTR [rax+rbx*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 296352743423ULL);
x86_l_b12:
	/* 0xb12: mov    rax,QWORD PTR [r12+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_b1a:
	/* 0xb1a: je     b30 <do_action+0x9ef> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb1a, 0xb30, x86_l_b30);
x86_l_b1c:
	/* 0xb1c: mov    ebp,DWORD PTR [r12+rbx*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 1), 24192ULL);
x86_l_b24:
	/* 0xb24: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b26:
	/* 0xb26: jmp    b3a <do_action+0x9f9> */
	X86_SIM_X86_SUB_JMP(0xb26, 0xb3a, x86_l_b3a);
x86_l_b28:
	/* 0xb28: mov    rax,QWORD PTR [r12+rbx*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 1), 24184ULL);
x86_l_b30:
	/* 0xb30: mov    ebp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b35:
	/* 0xb35: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b37:
	/* 0xb37: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b3a:
	/* 0xb3a: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_b3c:
	/* 0xb3c: jle    a56 <do_action+0x915> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xb3c, 0xa56, x86_l_a56);
x86_l_b42:
	/* 0xb42: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_b47:
	/* 0xb47: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_b4c:
	/* 0xb4c: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_b4f:
	/* 0xb4f: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_b54:
	/* 0xb54: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_b57:
	/* 0xb57: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_b5a:
	/* 0xb5a: movzx  r12d,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_b60:
	/* 0xb60: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b65:
	/* 0xb65: lea    rdi,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_b69:
	/* 0xb69: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_b6d:
	/* 0xb6d: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_b74:
	/* 0xb74: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b79:
	/* 0xb79: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b7b:
	/* 0xb7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7d:
	/* 0xb7d: add    ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b80:
	/* 0xb80: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_b83:
	/* 0xb83: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b8b:
	/* 0xb8b: mov    QWORD PTR [rsp+0x68],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b90:
	/* 0xb90: jmp    a56 <do_action+0x915> */
	X86_SIM_X86_SUB_JMP(0xb90, 0xa56, x86_l_a56);
x86_l_b95:
	/* 0xb95: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_b9c:
	/* 0xb9c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba1:
	/* 0xba1: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ba6:
	/* 0xba6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba8:
	/* 0xba8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bab:
	/* 0xbab: je     bcd <do_action+0xa8c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbab, 0xbcd, x86_l_bcd);
x86_l_bad:
	/* 0xbad: imul   rcx,QWORD PTR [rsp+0x78],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 515395075520ULL);
x86_l_bb6:
	/* 0xbb6: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bbb:
	/* 0xbbb: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bbe:
	/* 0xbbe: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc1:
	/* 0xbc1: jbe    bcd <do_action+0xa8c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xbc1, 0xbcd, x86_l_bcd);
x86_l_bc3:
	/* 0xbc3: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bc8:
	/* 0xbc8: mov    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bcb:
	/* 0xbcb: jmp    be7 <do_action+0xaa6> */
	X86_SIM_X86_SUB_JMP(0xbcb, 0xbe7, x86_l_be7);
x86_l_bcd:
	/* 0xbcd: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_bd4:
	/* 0xbd4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd6:
	/* 0xbd6: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_bd9:
	/* 0xbd9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bde:
	/* 0xbde: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_be3:
	/* 0xbe3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be5:
	/* 0xbe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be7:
	/* 0xbe7: lea    eax,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_beb:
	/* 0xbeb: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_bf1:
	/* 0xbf1: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bf6:
	/* 0xbf6: je     c1b <do_action+0xada> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbf6, 0xc1b, x86_l_c1b);
x86_l_bf8:
	/* 0xbf8: or     BYTE PTR [r12+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_bfe:
	/* 0xbfe: mov    rsi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c05:
	/* 0xc05: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c07:
	/* 0xc07: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c0c:
	/* 0xc0c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_c0f:
	/* 0xc0f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c11:
	/* 0xc11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c13:
	/* 0xc13: mov    QWORD PTR [r12+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c1b:
	/* 0xc1b: lea    eax,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c1f:
	/* 0xc1f: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_c25:
	/* 0xc25: je     c50 <do_action+0xb0f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc25, 0xc50, x86_l_c50);
x86_l_c27:
	/* 0xc27: or     BYTE PTR [r12+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c2d:
	/* 0xc2d: mov    rsi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c34:
	/* 0xc34: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_c39:
	/* 0xc39: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c3e:
	/* 0xc3e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c43:
	/* 0xc43: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_c46:
	/* 0xc46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c48:
	/* 0xc48: mov    QWORD PTR [r12+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c50:
	/* 0xc50: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_c54:
	/* 0xc54: cmp    DWORD PTR [r15+r14*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 17179869184ULL);
x86_l_c5a:
	/* 0xc5a: je     979 <do_action+0x838> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc5a, 0x979, x86_l_979);
x86_l_c60:
	/* 0xc60: or     BYTE PTR [r12+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_c66:
	/* 0xc66: jmp    979 <do_action+0x838> */
	X86_SIM_X86_SUB_JMP(0xc66, 0x979, x86_l_979);
x86_l_c6b:
	/* 0xc6b: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_c6e:
	/* 0xc6e: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_c76:
	/* 0xc76: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_c7b:
	/* 0xc7b: mov    rax,QWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_c83:
	/* 0xc83: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_c87:
	/* 0xc87: jmp    6ba <do_action+0x579> */
	X86_SIM_X86_SUB_JMP(0xc87, 0x6ba, x86_l_6ba);
x86_l_c8c:
	/* 0xc8c: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_c94:
	/* 0xc94: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c9b:
	/* 0xc9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c9d:
	/* 0xc9d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ca0:
	/* 0xca0: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ca5:
	/* 0xca5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_caa:
	/* 0xcaa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cac:
	/* 0xcac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cae:
	/* 0xcae: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_cb1:
	/* 0xcb1: je     56d <do_action+0x42c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xcb1, 0x56d, x86_l_56d);
x86_l_cb7:
	/* 0xcb7: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_cbe:
	/* 0xcbe: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc3:
	/* 0xcc3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc8:
	/* 0xcc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cca:
	/* 0xcca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ccd:
	/* 0xccd: je     56d <do_action+0x42c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xccd, 0x56d, x86_l_56d);
x86_l_cd3:
	/* 0xcd3: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_cd7:
	/* 0xcd7: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_cda:
	/* 0xcda: jmp    56d <do_action+0x42c> */
	X86_SIM_X86_SUB_JMP(0xcda, 0x56d, x86_l_56d);
x86_l_cdf:
	/* 0xcdf: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_ce7:
	/* 0xce7: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_cee:
	/* 0xcee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf0:
	/* 0xcf0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_cf3:
	/* 0xcf3: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cf8:
	/* 0xcf8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cfd:
	/* 0xcfd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cff:
	/* 0xcff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d01:
	/* 0xd01: jmp    743 <do_action+0x602> */
	X86_SIM_X86_SUB_JMP(0xd01, 0x743, x86_l_743);
x86_l_d06:
	/* 0xd06: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_d0e:
	/* 0xd0e: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d15:
	/* 0xd15: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d17:
	/* 0xd17: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d1a:
	/* 0xd1a: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d1f:
	/* 0xd1f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d24:
	/* 0xd24: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d26:
	/* 0xd26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d28:
	/* 0xd28: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_d2b:
	/* 0xd2b: je     733 <do_action+0x5f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd2b, 0x733, x86_l_733);
x86_l_d31:
	/* 0xd31: mov    rdi,QWORD PTR [rip+0x2890] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d38:
	/* 0xd38: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d3d:
	/* 0xd3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d42:
	/* 0xd42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d44:
	/* 0xd44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d47:
	/* 0xd47: je     733 <do_action+0x5f2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd47, 0x733, x86_l_733);
x86_l_d4d:
	/* 0xd4d: mov    ecx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_d51:
	/* 0xd51: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d54:
	/* 0xd54: jmp    733 <do_action+0x5f2> */
	X86_SIM_X86_SUB_JMP(0xd54, 0x733, x86_l_733);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x26ULL: goto x86_l_26;
	case 0x58ULL: goto x86_l_58;
	case 0x9bULL: goto x86_l_9b;
	case 0xceULL: goto x86_l_ce;
	case 0xefULL: goto x86_l_ef;
	case 0x110ULL: goto x86_l_110;
	case 0x132ULL: goto x86_l_132;
	case 0x185ULL: goto x86_l_185;
	case 0x2c6ULL: goto x86_l_2c6;
	case 0x321ULL: goto x86_l_321;
	case 0x38bULL: goto x86_l_38b;
	case 0x3a4ULL: goto x86_l_3a4;
	case 0x403ULL: goto x86_l_403;
	case 0x41eULL: goto x86_l_41e;
	case 0x45dULL: goto x86_l_45d;
	case 0x4b5ULL: goto x86_l_4b5;
	case 0x4cdULL: goto x86_l_4cd;
	case 0x4fdULL: goto x86_l_4fd;
	case 0x514ULL: goto x86_l_514;
	case 0x52cULL: goto x86_l_52c;
	case 0x559ULL: goto x86_l_559;
	case 0x580ULL: goto x86_l_580;
	case 0x5a3ULL: goto x86_l_5a3;
	case 0x5d5ULL: goto x86_l_5d5;
	case 0x5f9ULL: goto x86_l_5f9;
	case 0x666ULL: goto x86_l_666;
	case 0x6c8ULL: goto x86_l_6c8;
	case 0x6efULL: goto x86_l_6ef;
	case 0x71fULL: goto x86_l_71f;
	case 0x775ULL: goto x86_l_775;
	case 0x7aeULL: goto x86_l_7ae;
	case 0x7ddULL: goto x86_l_7dd;
	case 0x80fULL: goto x86_l_80f;
	case 0x828ULL: goto x86_l_828;
	case 0x878ULL: goto x86_l_878;
	case 0x898ULL: goto x86_l_898;
	case 0x8b9ULL: goto x86_l_8b9;
	case 0x8efULL: goto x86_l_8ef;
	case 0x910ULL: goto x86_l_910;
	case 0x941ULL: goto x86_l_941;
	case 0x964ULL: goto x86_l_964;
	case 0x9a9ULL: goto x86_l_9a9;
	case 0x9d2ULL: goto x86_l_9d2;
	case 0xa0bULL: goto x86_l_a0b;
	case 0xa4aULL: goto x86_l_a4a;
	case 0xa7fULL: goto x86_l_a7f;
	case 0xaa0ULL: goto x86_l_aa0;
	case 0xaebULL: goto x86_l_aeb;
	case 0xb08ULL: goto x86_l_b08;
	case 0xb7dULL: goto x86_l_b7d;
	case 0xba8ULL: goto x86_l_ba8;
	case 0xbe7ULL: goto x86_l_be7;
	case 0xc13ULL: goto x86_l_c13;
	case 0xc48ULL: goto x86_l_c48;
	case 0xcaeULL: goto x86_l_cae;
	case 0xccaULL: goto x86_l_cca;
	case 0xd01ULL: goto x86_l_d01;
	case 0xd28ULL: goto x86_l_d28;
	case 0xd44ULL: goto x86_l_d44;
	}

}

X86_SIM_LICENSE();
