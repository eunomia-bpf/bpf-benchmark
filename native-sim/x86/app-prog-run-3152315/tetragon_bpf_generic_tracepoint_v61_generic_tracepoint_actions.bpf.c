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
extern char socktrack_map;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f:
	/* 0xf: mov    rdi,QWORD PTR [rip+0x5d14] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_16:
	/* 0x16: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b:
	/* 0x1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     12f <generic_tracepoint_actions+0x12f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0x12f, x86_l_12f);
x86_l_2b:
	/* 0x2b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2e:
	/* 0x2e: mov    r14d,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_35:
	/* 0x35: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_39:
	/* 0x39: jl     12f <generic_tracepoint_actions+0x12f> */
	X86_SIM_X86_JCC(X86_CC_L, 0x39, 0x12f, x86_l_12f);
x86_l_3f:
	/* 0x3f: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_46:
	/* 0x46: mov    rdi,QWORD PTR [rip+0x5d14] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4d:
	/* 0x4d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52:
	/* 0x52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54:
	/* 0x54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_57:
	/* 0x57: je     12f <generic_tracepoint_actions+0x12f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x57, 0x12f, x86_l_12f);
x86_l_5d:
	/* 0x5d: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_60:
	/* 0x60: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_66:
	/* 0x66: add    r14d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6a:
	/* 0x6a: mov    BYTE PTR [rsp+0x7],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771073ULL);
x86_l_6f:
	/* 0x6f: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_77:
	/* 0x77: mov    rdi,QWORD PTR [rip+0x5d14] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_7e:
	/* 0x7e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_83:
	/* 0x83: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_86:
	/* 0x86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b:
	/* 0x8b: and    r14d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_92:
	/* 0x92: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_95:
	/* 0x95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97:
	/* 0x97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: je     aa <generic_tracepoint_actions+0xaa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a, 0xaa, x86_l_aa);
x86_l_9c:
	/* 0x9c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f:
	/* 0x9f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_a2:
	/* 0xa2: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_a6:
	/* 0xa6: jae    b2 <generic_tracepoint_actions+0xb2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa6, 0xb2, x86_l_b2);
x86_l_a8:
	/* 0xa8: jmp    10d <generic_tracepoint_actions+0x10d> */
	X86_SIM_X86_JMP(0xa8, 0x10d, x86_l_10d);
x86_l_aa:
	/* 0xaa: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_ac:
	/* 0xac: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_b0:
	/* 0xb0: jb     10d <generic_tracepoint_actions+0x10d> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb0, 0x10d, x86_l_10d);
x86_l_b2:
	/* 0xb2: movzx  r13d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b6:
	/* 0xb6: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_bb:
	/* 0xbb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_be:
	/* 0xbe: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0:
	/* 0xc0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_c6:
	/* 0xc6: call   0 <generic_tracepoint_actions> */
	X86_SIM_X86_CALL(x86_l_13a, 0xcbULL);
x86_l_cb:
	/* 0xcb: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_d2:
	/* 0xd2: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d5:
	/* 0xd5: jae    10d <generic_tracepoint_actions+0x10d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xd5, 0x10d, x86_l_10d);
x86_l_d7:
	/* 0xd7: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_dc:
	/* 0xdc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_df:
	/* 0xdf: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_e1:
	/* 0xe1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e4:
	/* 0xe4: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_e7:
	/* 0xe7: call   0 <generic_tracepoint_actions> */
	X86_SIM_X86_CALL(x86_l_13a, 0xecULL);
x86_l_ec:
	/* 0xec: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_f3:
	/* 0xf3: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_f6:
	/* 0xf6: jae    10d <generic_tracepoint_actions+0x10d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf6, 0x10d, x86_l_10d);
x86_l_f8:
	/* 0xf8: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_fd:
	/* 0xfd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_100:
	/* 0x100: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_102:
	/* 0x102: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_105:
	/* 0x105: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_108:
	/* 0x108: call   0 <generic_tracepoint_actions> */
	X86_SIM_X86_CALL(x86_l_13a, 0x10dULL);
x86_l_10d:
	/* 0x10d: cmp    BYTE PTR [rsp+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_112:
	/* 0x112: je     12f <generic_tracepoint_actions+0x12f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112, 0x12f, x86_l_12f);
x86_l_114:
	/* 0x114: mov    rsi,QWORD PTR [rip+0x5d13] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_11b:
	/* 0x11b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_120:
	/* 0x120: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_125:
	/* 0x125: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_128:
	/* 0x128: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12d:
	/* 0x12d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f:
	/* 0x12f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_131:
	/* 0x131: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_135:
	/* 0x135: jmp    c7f <do_action+0xb45> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_c7f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_13a */
x86_l_13a:
	/* 0x13a: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_13b:
	/* 0x13b: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_13d:
	/* 0x13d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_13f:
	/* 0x13f: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_141:
	/* 0x141: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_143:
	/* 0x143: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_144:
	/* 0x144: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_14b:
	/* 0x14b: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_14e:
	/* 0x14e: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_151:
	/* 0x151: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_154:
	/* 0x154: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_157:
	/* 0x157: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_15c:
	/* 0x15c: movsxd rbx,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_161:
	/* 0x161: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_169:
	/* 0x169: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_170:
	/* 0x170: lea    rsi,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_175:
	/* 0x175: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a:
	/* 0x17a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c:
	/* 0x17c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_17f:
	/* 0x17f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_181:
	/* 0x181: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: je     b7f <do_action+0xa45> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x184, 0xb7f, x86_l_b7f);
x86_l_18a:
	/* 0x18a: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_18d:
	/* 0x18d: jg     1b3 <do_action+0x79> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x18d, 0x1b3, x86_l_1b3);
x86_l_18f:
	/* 0x18f: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_192:
	/* 0x192: jg     1e7 <do_action+0xad> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x192, 0x1e7, x86_l_1e7);
x86_l_194:
	/* 0x194: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_197:
	/* 0x197: jg     31f <do_action+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x197, 0x31f, x86_l_31f);
x86_l_19d:
	/* 0x19d: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_19f:
	/* 0x19f: je     5df <do_action+0x4a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19f, 0x5df, x86_l_5df);
x86_l_1a5:
	/* 0x1a5: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1a8:
	/* 0x1a8: je     336 <do_action+0x1fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a8, 0x336, x86_l_336);
x86_l_1ae:
	/* 0x1ae: jmp    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JMP(0x1ae, 0xb75, x86_l_b75);
x86_l_1b3:
	/* 0x1b3: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_1b6:
	/* 0x1b6: jg     2ed <do_action+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1b6, 0x2ed, x86_l_2ed);
x86_l_1bc:
	/* 0x1bc: lea    ecx,[rbx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1bf:
	/* 0x1bf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c2:
	/* 0x1c2: jb     448 <do_action+0x30e> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1c2, 0x448, x86_l_448);
x86_l_1c8:
	/* 0x1c8: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1cb:
	/* 0x1cb: je     545 <do_action+0x40b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cb, 0x545, x86_l_545);
x86_l_1d1:
	/* 0x1d1: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_1d4:
	/* 0x1d4: jne    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1d4, 0xb75, x86_l_b75);
x86_l_1da:
	/* 0x1da: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1dd:
	/* 0x1dd: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_1e2:
	/* 0x1e2: jmp    50b <do_action+0x3d1> */
	X86_SIM_X86_SUB_JMP(0x1e2, 0x50b, x86_l_50b);
x86_l_1e7:
	/* 0x1e7: lea    eax,[rbx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1ea:
	/* 0x1ea: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ed:
	/* 0x1ed: jb     535 <do_action+0x3fb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1ed, 0x535, x86_l_535);
x86_l_1f3:
	/* 0x1f3: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1f6:
	/* 0x1f6: je     54f <do_action+0x415> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f6, 0x54f, x86_l_54f);
x86_l_1fc:
	/* 0x1fc: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1ff:
	/* 0x1ff: jne    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ff, 0xb75, x86_l_b75);
x86_l_205:
	/* 0x205: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_209:
	/* 0x209: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_20e:
	/* 0x20e: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_212:
	/* 0x212: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_215:
	/* 0x215: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_218:
	/* 0x218: ja     b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x218, 0xb75, x86_l_b75);
x86_l_21e:
	/* 0x21e: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_226:
	/* 0x226: jne    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x226, 0xb75, x86_l_b75);
x86_l_22c:
	/* 0x22c: mov    r15d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_231:
	/* 0x231: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_239:
	/* 0x239: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_241:
	/* 0x241: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_246:
	/* 0x246: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_24d:
	/* 0x24d: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_251:
	/* 0x251: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_256:
	/* 0x256: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_259:
	/* 0x259: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b:
	/* 0x25b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_25f:
	/* 0x25f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_263:
	/* 0x263: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_26a:
	/* 0x26a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_26d:
	/* 0x26d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_272:
	/* 0x272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274:
	/* 0x274: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_277:
	/* 0x277: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: je     b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x27a, 0xb75, x86_l_b75);
x86_l_280:
	/* 0x280: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_284:
	/* 0x284: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_288:
	/* 0x288: ja     b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x288, 0xb75, x86_l_b75);
x86_l_28e:
	/* 0x28e: cmp    DWORD PTR [rdx+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_297:
	/* 0x297: jne    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x297, 0xb75, x86_l_b75);
x86_l_29d:
	/* 0x29d: mov    rcx,QWORD PTR [rdx+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_2a5:
	/* 0x2a5: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2ad:
	/* 0x2ad: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2b3:
	/* 0x2b3: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_2ba:
	/* 0x2ba: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be:
	/* 0x2be: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c6:
	/* 0x2c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8:
	/* 0x2c8: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2cc:
	/* 0x2cc: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d0:
	/* 0x2d0: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2d7:
	/* 0x2d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d9:
	/* 0x2d9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2dc:
	/* 0x2dc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e1:
	/* 0x2e1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e4:
	/* 0x2e4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e6:
	/* 0x2e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8:
	/* 0x2e8: jmp    5d7 <do_action+0x49d> */
	X86_SIM_X86_SUB_JMP(0x2e8, 0x5d7, x86_l_5d7);
x86_l_2ed:
	/* 0x2ed: cmp    ebx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 12ULL);
x86_l_2f0:
	/* 0x2f0: je     6ab <do_action+0x571> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2f0, 0x6ab, x86_l_6ab);
x86_l_2f6:
	/* 0x2f6: cmp    ebx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 13ULL);
x86_l_2f9:
	/* 0x2f9: je     565 <do_action+0x42b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2f9, 0x565, x86_l_565);
x86_l_2ff:
	/* 0x2ff: cmp    ebx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_302:
	/* 0x302: jne    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x302, 0xb75, x86_l_b75);
x86_l_308:
	/* 0x308: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_30b:
	/* 0x30b: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_30f:
	/* 0x30f: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_313:
	/* 0x313: xor    r13,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_317:
	/* 0x317: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_31a:
	/* 0x31a: jmp    78a <do_action+0x650> */
	X86_SIM_X86_SUB_JMP(0x31a, 0x78a, x86_l_78a);
x86_l_31f:
	/* 0x31f: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_324:
	/* 0x324: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_327:
	/* 0x327: je     50b <do_action+0x3d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x327, 0x50b, x86_l_50b);
x86_l_32d:
	/* 0x32d: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_330:
	/* 0x330: jne    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x330, 0xb75, x86_l_b75);
x86_l_336:
	/* 0x336: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_339:
	/* 0x339: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_33d:
	/* 0x33d: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_342:
	/* 0x342: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_346:
	/* 0x346: mov    r12d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_34b:
	/* 0x34b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_353:
	/* 0x353: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_35a:
	/* 0x35a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35f:
	/* 0x35f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_364:
	/* 0x364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366:
	/* 0x366: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_369:
	/* 0x369: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36c:
	/* 0x36c: je     8a9 <do_action+0x76f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x36c, 0x8a9, x86_l_8a9);
x86_l_372:
	/* 0x372: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_377:
	/* 0x377: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_37a:
	/* 0x37a: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_37d:
	/* 0x37d: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_382:
	/* 0x382: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_385:
	/* 0x385: ja     8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x385, 0x8ae, x86_l_8ae);
x86_l_38b:
	/* 0x38b: cmp    DWORD PTR [rdx+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_393:
	/* 0x393: jne    8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x393, 0x8ae, x86_l_8ae);
x86_l_399:
	/* 0x399: mov    rax,QWORD PTR [rdx+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_3a1:
	/* 0x3a1: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_3a9:
	/* 0x3a9: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3ae:
	/* 0x3ae: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_3b5:
	/* 0x3b5: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b9:
	/* 0x3b9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3be:
	/* 0x3be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c0:
	/* 0x3c0: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3c4:
	/* 0x3c4: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c8:
	/* 0x3c8: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3cb:
	/* 0x3cb: jne    882 <do_action+0x748> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3cb, 0x882, x86_l_882);
x86_l_3d1:
	/* 0x3d1: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3d5:
	/* 0x3d5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3d9:
	/* 0x3d9: ja     8a9 <do_action+0x76f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3d9, 0x8a9, x86_l_8a9);
x86_l_3df:
	/* 0x3df: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3e2:
	/* 0x3e2: cmp    DWORD PTR [r13+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_3eb:
	/* 0x3eb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3f0:
	/* 0x3f0: jne    8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3f0, 0x8ae, x86_l_8ae);
x86_l_3f6:
	/* 0x3f6: mov    rax,QWORD PTR [rdx+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_3fe:
	/* 0x3fe: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_403:
	/* 0x403: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_406:
	/* 0x406: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_40d:
	/* 0x40d: mov    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_415:
	/* 0x415: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41b:
	/* 0x41b: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_41f:
	/* 0x41f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_424:
	/* 0x424: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_429:
	/* 0x429: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_42c:
	/* 0x42c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e:
	/* 0x42e: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_435:
	/* 0x435: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_438:
	/* 0x438: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_43b:
	/* 0x43b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_440:
	/* 0x440: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_443:
	/* 0x443: jmp    4fd <do_action+0x3c3> */
	X86_SIM_X86_SUB_JMP(0x443, 0x4fd, x86_l_4fd);
x86_l_448:
	/* 0x448: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_44b:
	/* 0x44b: mov    ecx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_450:
	/* 0x450: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_453:
	/* 0x453: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_456:
	/* 0x456: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_459:
	/* 0x459: ja     8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x459, 0x8ae, x86_l_8ae);
x86_l_45f:
	/* 0x45f: cmp    DWORD PTR [rdx+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_467:
	/* 0x467: jne    8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x467, 0x8ae, x86_l_8ae);
x86_l_46d:
	/* 0x46d: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_475:
	/* 0x475: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_47b:
	/* 0x47b: mov    rcx,QWORD PTR [rdx+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_483:
	/* 0x483: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_488:
	/* 0x488: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: je     8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x48b, 0x8ae, x86_l_8ae);
x86_l_491:
	/* 0x491: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_497:
	/* 0x497: jne    893 <do_action+0x759> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x497, 0x893, x86_l_893);
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
	/* 0x4ae: mov    rdi,QWORD PTR [rip+0x2370] */
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
	/* 0x4ca: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: je     8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4cd, 0x8ae, x86_l_8ae);
x86_l_4d3:
	/* 0x4d3: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d5:
	/* 0x4d5: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d8:
	/* 0x4d8: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4dd:
	/* 0x4dd: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e1:
	/* 0x4e1: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e6:
	/* 0x4e6: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_4ed:
	/* 0x4ed: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f0:
	/* 0x4f0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f5:
	/* 0x4f5: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4fd:
	/* 0x4fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ff:
	/* 0x4ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_501:
	/* 0x501: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_504:
	/* 0x504: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_506:
	/* 0x506: jmp    8ae <do_action+0x774> */
	X86_SIM_X86_SUB_JMP(0x506, 0x8ae, x86_l_8ae);
x86_l_50b:
	/* 0x50b: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_50e:
	/* 0x50e: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_511:
	/* 0x511: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_517:
	/* 0x517: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_51a:
	/* 0x51a: je     78a <do_action+0x650> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x51a, 0x78a, x86_l_78a);
x86_l_520:
	/* 0x520: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_523:
	/* 0x523: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_528:
	/* 0x528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a:
	/* 0x52a: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_530:
	/* 0x530: jmp    78a <do_action+0x650> */
	X86_SIM_X86_SUB_JMP(0x530, 0x78a, x86_l_78a);
x86_l_535:
	/* 0x535: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_538:
	/* 0x538: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_53d:
	/* 0x53d: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_540:
	/* 0x540: jmp    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JMP(0x540, 0xb75, x86_l_b75);
x86_l_545:
	/* 0x545: mov    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54a:
	/* 0x54a: jmp    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JMP(0x54a, 0xb75, x86_l_b75);
x86_l_54f:
	/* 0x54f: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_552:
	/* 0x552: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_555:
	/* 0x555: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_559:
	/* 0x559: xor    r13,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_55d:
	/* 0x55d: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_560:
	/* 0x560: jmp    78a <do_action+0x650> */
	X86_SIM_X86_SUB_JMP(0x560, 0x78a, x86_l_78a);
x86_l_565:
	/* 0x565: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_568:
	/* 0x568: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_56d:
	/* 0x56d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56f:
	/* 0x56f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_574:
	/* 0x574: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_57b:
	/* 0x57b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_580:
	/* 0x580: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_585:
	/* 0x585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_587:
	/* 0x587: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58a:
	/* 0x58a: je     5d7 <do_action+0x49d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x58a, 0x5d7, x86_l_5d7);
x86_l_58c:
	/* 0x58c: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_590:
	/* 0x590: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_595:
	/* 0x595: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_59d:
	/* 0x59d: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_5a4:
	/* 0x5a4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a9:
	/* 0x5a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ae:
	/* 0x5ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0:
	/* 0x5b0: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_5b8:
	/* 0x5b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: je     7b7 <do_action+0x67d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5bb, 0x7b7, x86_l_7b7);
x86_l_5c1:
	/* 0x5c1: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5c4:
	/* 0x5c4: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_5cb:
	/* 0x5cb: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d0:
	/* 0x5d0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5d5:
	/* 0x5d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d7:
	/* 0x5d7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5da:
	/* 0x5da: jmp    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JMP(0x5da, 0xb75, x86_l_b75);
x86_l_5df:
	/* 0x5df: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e4:
	/* 0x5e4: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5e8:
	/* 0x5e8: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_5ed:
	/* 0x5ed: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_5f1:
	/* 0x5f1: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_5f6:
	/* 0x5f6: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_5ff:
	/* 0x5ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_601:
	/* 0x601: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_606:
	/* 0x606: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60a:
	/* 0x60a: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [rsp+0x78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_617:
	/* 0x617: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_61a:
	/* 0x61a: je     af8 <do_action+0x9be> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x61a, 0xaf8, x86_l_af8);
x86_l_620:
	/* 0x620: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_627:
	/* 0x627: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_62c:
	/* 0x62c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_631:
	/* 0x631: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_633:
	/* 0x633: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_636:
	/* 0x636: je     af8 <do_action+0x9be> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x636, 0xaf8, x86_l_af8);
x86_l_63c:
	/* 0x63c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_641:
	/* 0x641: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_644:
	/* 0x644: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_64b:
	/* 0x64b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_650:
	/* 0x650: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_655:
	/* 0x655: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_657:
	/* 0x657: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_65a:
	/* 0x65a: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65f:
	/* 0x65f: mov    rax,QWORD PTR [rcx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_663:
	/* 0x663: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_667:
	/* 0x667: mov    rax,QWORD PTR [rcx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_66b:
	/* 0x66b: mov    QWORD PTR [rsp+0x50],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_670:
	/* 0x670: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_674:
	/* 0x674: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_676:
	/* 0x676: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_67b:
	/* 0x67b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_680:
	/* 0x680: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_684:
	/* 0x684: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_687:
	/* 0x687: je     925 <do_action+0x7eb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x687, 0x925, x86_l_925);
x86_l_68d:
	/* 0x68d: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_690:
	/* 0x690: je     922 <do_action+0x7e8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x690, 0x922, x86_l_922);
x86_l_696:
	/* 0x696: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_698:
	/* 0x698: jne    af8 <do_action+0x9be> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x698, 0xaf8, x86_l_af8);
x86_l_69e:
	/* 0x69e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a3:
	/* 0x6a3: mov    eax,DWORD PTR [rax+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_6a6:
	/* 0x6a6: jmp    925 <do_action+0x7eb> */
	X86_SIM_X86_SUB_JMP(0x6a6, 0x925, x86_l_925);
x86_l_6ab:
	/* 0x6ab: lea    r12d,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_6af:
	/* 0x6af: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_6b5:
	/* 0x6b5: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_6b8:
	/* 0x6b8: je     787 <do_action+0x64d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6b8, 0x787, x86_l_787);
x86_l_6be:
	/* 0x6be: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_6c1:
	/* 0x6c1: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6c6:
	/* 0x6c6: lea    ecx,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_6ca:
	/* 0x6ca: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6cd:
	/* 0x6cd: mov    ebp,DWORD PTR [r15+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_6d2:
	/* 0x6d2: mov    r14d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_6d7:
	/* 0x6d7: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_6db:
	/* 0x6db: ja     6eb <do_action+0x5b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x6db, 0x6eb, x86_l_6eb);
x86_l_6dd:
	/* 0x6dd: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_6e5:
	/* 0x6e5: je     b91 <do_action+0xa57> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6e5, 0xb91, x86_l_b91);
x86_l_6eb:
	/* 0x6eb: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_6ee:
	/* 0x6ee: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f0:
	/* 0x6f0: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_6f3:
	/* 0x6f3: mov    ebx,DWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6f6:
	/* 0x6f6: or     rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6f9:
	/* 0x6f9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6fe:
	/* 0x6fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_700:
	/* 0x700: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_705:
	/* 0x705: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70b:
	/* 0x70b: mov    WORD PTR [rsp+0x12],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_710:
	/* 0x710: mov    QWORD PTR [rsp+0x14],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_715:
	/* 0x715: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_71c:
	/* 0x71c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_721:
	/* 0x721: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_726:
	/* 0x726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_728:
	/* 0x728: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72b:
	/* 0x72b: je     81d <do_action+0x6e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x72b, 0x81d, x86_l_81d);
x86_l_731:
	/* 0x731: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_734:
	/* 0x734: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_738:
	/* 0x738: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_73d:
	/* 0x73d: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_745:
	/* 0x745: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_74c:
	/* 0x74c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_751:
	/* 0x751: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_756:
	/* 0x756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_758:
	/* 0x758: mov    DWORD PTR [rsp+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_760:
	/* 0x760: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_763:
	/* 0x763: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_766:
	/* 0x766: je     8bc <do_action+0x782> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x766, 0x8bc, x86_l_8bc);
x86_l_76c:
	/* 0x76c: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_76f:
	/* 0x76f: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_773:
	/* 0x773: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_777:
	/* 0x777: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_77c:
	/* 0x77c: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77f:
	/* 0x77f: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_785:
	/* 0x785: jmp    78a <do_action+0x650> */
	X86_SIM_X86_SUB_JMP(0x785, 0x78a, x86_l_78a);
x86_l_787:
	/* 0x787: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_78a:
	/* 0x78a: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_791:
	/* 0x791: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_798:
	/* 0x798: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_79b:
	/* 0x79b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a0:
	/* 0x7a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a2:
	/* 0x7a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: je     7ac <do_action+0x672> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x7a5, 0x7ac, x86_l_7ac);
x86_l_7a7:
	/* 0x7a7: inc QWORD PTR [rax+r13*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R13, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7ac:
	/* 0x7ac: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_7af:
	/* 0x7af: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7b2:
	/* 0x7b2: jmp    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JMP(0x7b2, 0xb75, x86_l_b75);
x86_l_7b7:
	/* 0x7b7: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7be:
	/* 0x7be: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c3:
	/* 0x7c3: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_7c8:
	/* 0x7c8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7cd:
	/* 0x7cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7d2:
	/* 0x7d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d4:
	/* 0x7d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: je     5c4 <do_action+0x48a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x7d7, 0x5c4, x86_l_5c4);
x86_l_7dd:
	/* 0x7dd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7e0:
	/* 0x7e0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_7e2:
	/* 0x7e2: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e6:
	/* 0x7e6: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_7ed:
	/* 0x7ed: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_7f7:
	/* 0x7f7: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7fc:
	/* 0x7fc: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_803:
	/* 0x803: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_806:
	/* 0x806: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_80b:
	/* 0x80b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80d:
	/* 0x80d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_810:
	/* 0x810: je     bb2 <do_action+0xa78> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x810, 0xbb2, x86_l_bb2);
x86_l_816:
	/* 0x816: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_818:
	/* 0x818: jmp    bd4 <do_action+0xa9a> */
	X86_SIM_X86_SUB_JMP(0x818, 0xbd4, x86_l_bd4);
x86_l_81d:
	/* 0x81d: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_824:
	/* 0x824: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_826:
	/* 0x826: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_82b:
	/* 0x82b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_830:
	/* 0x830: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_835:
	/* 0x835: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_837:
	/* 0x837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_839:
	/* 0x839: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83c:
	/* 0x83c: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: je     77f <do_action+0x645> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x83f, 0x77f, x86_l_77f);
x86_l_845:
	/* 0x845: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_847:
	/* 0x847: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84b:
	/* 0x84b: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_852:
	/* 0x852: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_85c:
	/* 0x85c: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_861:
	/* 0x861: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_868:
	/* 0x868: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_86b:
	/* 0x86b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_870:
	/* 0x870: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_872:
	/* 0x872: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_875:
	/* 0x875: je     c05 <do_action+0xacb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x875, 0xc05, x86_l_c05);
x86_l_87b:
	/* 0x87b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_87d:
	/* 0x87d: jmp    77f <do_action+0x645> */
	X86_SIM_X86_SUB_JMP(0x87d, 0x77f, x86_l_77f);
x86_l_882:
	/* 0x882: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_889:
	/* 0x889: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_88c:
	/* 0x88c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_891:
	/* 0x891: jmp    8a4 <do_action+0x76a> */
	X86_SIM_X86_SUB_JMP(0x891, 0x8a4, x86_l_8a4);
x86_l_893:
	/* 0x893: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_89a:
	/* 0x89a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89f:
	/* 0x89f: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8a4:
	/* 0x8a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a6:
	/* 0x8a6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_8a9:
	/* 0x8a9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ab:
	/* 0x8ab: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8ae:
	/* 0x8ae: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_8b1:
	/* 0x8b1: jne    b7f <do_action+0xa45> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x8b1, 0xb7f, x86_l_b7f);
x86_l_8b7:
	/* 0x8b7: jmp    b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JMP(0x8b7, 0xb75, x86_l_b75);
x86_l_8bc:
	/* 0x8bc: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_8c3:
	/* 0x8c3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8c8:
	/* 0x8c8: lea    rdx,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8cd:
	/* 0x8cd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8d2:
	/* 0x8d2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8d7:
	/* 0x8d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d9:
	/* 0x8d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8dc:
	/* 0x8dc: je     76f <do_action+0x635> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8dc, 0x76f, x86_l_76f);
x86_l_8e2:
	/* 0x8e2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_8e5:
	/* 0x8e5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8e7:
	/* 0x8e7: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8eb:
	/* 0x8eb: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_8f2:
	/* 0x8f2: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_8fc:
	/* 0x8fc: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_901:
	/* 0x901: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_908:
	/* 0x908: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_90b:
	/* 0x90b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_910:
	/* 0x910: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_912:
	/* 0x912: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_915:
	/* 0x915: je     c2c <do_action+0xaf2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x915, 0xc2c, x86_l_c2c);
x86_l_91b:
	/* 0x91b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_91d:
	/* 0x91d: jmp    c4e <do_action+0xb14> */
	X86_SIM_X86_SUB_JMP(0x91d, 0xc4e, x86_l_c4e);
x86_l_922:
	/* 0x922: mov    eax,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_925:
	/* 0x925: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_92a:
	/* 0x92a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92c:
	/* 0x92c: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_931:
	/* 0x931: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_935:
	/* 0x935: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_93a:
	/* 0x93a: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_93e:
	/* 0x93e: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_943:
	/* 0x943: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_948:
	/* 0x948: mov    QWORD PTR [rsp+0x58],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_94d:
	/* 0x94d: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_952:
	/* 0x952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_954:
	/* 0x954: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_957:
	/* 0x957: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_95f:
	/* 0x95f: jmp    96f <do_action+0x835> */
	X86_SIM_X86_SUB_JMP(0x95f, 0x96f, x86_l_96f);
x86_l_961:
	/* 0x961: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_965:
	/* 0x965: cmp    r12,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 20ULL);
x86_l_969:
	/* 0x969: je     aa4 <do_action+0x96a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x969, 0xaa4, x86_l_aa4);
x86_l_96f:
	/* 0x96f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_977:
	/* 0x977: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_97c:
	/* 0x97c: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_983:
	/* 0x983: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_988:
	/* 0x988: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98a:
	/* 0x98a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98d:
	/* 0x98d: je     aa4 <do_action+0x96a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x98d, 0xaa4, x86_l_aa4);
x86_l_993:
	/* 0x993: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_996:
	/* 0x996: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_99d:
	/* 0x99d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9a2:
	/* 0x9a2: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_9a9:
	/* 0x9a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ab:
	/* 0x9ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ae:
	/* 0x9ae: je     aa4 <do_action+0x96a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9ae, 0xaa4, x86_l_aa4);
x86_l_9b4:
	/* 0x9b4: cmp    DWORD PTR [rax+r12*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 279172874239ULL);
x86_l_9ba:
	/* 0x9ba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9bf:
	/* 0x9bf: je     aa4 <do_action+0x96a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9bf, 0xaa4, x86_l_aa4);
x86_l_9c5:
	/* 0x9c5: mov    rax,QWORD PTR [rdx+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_9cd:
	/* 0x9cd: mov    ecx,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9d0:
	/* 0x9d0: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_9d3:
	/* 0x9d3: jge    aa4 <do_action+0x96a> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0x9d3, 0xaa4, x86_l_aa4);
x86_l_9d9:
	/* 0x9d9: cmp    r12,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 16ULL);
x86_l_9dd:
	/* 0x9dd: je     a4a <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9dd, 0xa4a, x86_l_a4a);
x86_l_9df:
	/* 0x9df: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_9e7:
	/* 0x9e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9ec:
	/* 0x9ec: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9f3:
	/* 0x9f3: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9f8:
	/* 0x9f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fa:
	/* 0x9fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9fd:
	/* 0x9fd: je     a3d <do_action+0x903> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9fd, 0xa3d, x86_l_a3d);
x86_l_9ff:
	/* 0x9ff: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a02:
	/* 0xa02: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_a09:
	/* 0xa09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a0e:
	/* 0xa0e: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_a15:
	/* 0xa15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a17:
	/* 0xa17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a1a:
	/* 0xa1a: je     a3d <do_action+0x903> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa1a, 0xa3d, x86_l_a3d);
x86_l_a1c:
	/* 0xa1c: cmp    DWORD PTR [rax+r12*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 296352743423ULL);
x86_l_a22:
	/* 0xa22: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a27:
	/* 0xa27: mov    rax,QWORD PTR [rdx+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_a2f:
	/* 0xa2f: je     a4a <do_action+0x910> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa2f, 0xa4a, x86_l_a4a);
x86_l_a31:
	/* 0xa31: mov    ebp,DWORD PTR [rdx+r12*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 1), 24192ULL);
x86_l_a39:
	/* 0xa39: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a3b:
	/* 0xa3b: jmp    a52 <do_action+0x918> */
	X86_SIM_X86_SUB_JMP(0xa3b, 0xa52, x86_l_a52);
x86_l_a3d:
	/* 0xa3d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a42:
	/* 0xa42: mov    rax,QWORD PTR [rdx+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_a4a:
	/* 0xa4a: mov    ebp,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a4d:
	/* 0xa4d: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a4f:
	/* 0xa4f: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_a52:
	/* 0xa52: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_a54:
	/* 0xa54: jle    961 <do_action+0x827> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xa54, 0x961, x86_l_961);
x86_l_a5a:
	/* 0xa5a: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_a5f:
	/* 0xa5f: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_a64:
	/* 0xa64: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_a67:
	/* 0xa67: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_a6c:
	/* 0xa6c: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_a6f:
	/* 0xa6f: movzx  ebx,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_a74:
	/* 0xa74: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a79:
	/* 0xa79: lea    rdi,[rcx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_a7d:
	/* 0xa7d: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a80:
	/* 0xa80: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a87:
	/* 0xa87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a8c:
	/* 0xa8c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_a8e:
	/* 0xa8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a90:
	/* 0xa90: add    ebp,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a92:
	/* 0xa92: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a9a:
	/* 0xa9a: mov    QWORD PTR [rsp+0x68],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a9f:
	/* 0xa9f: jmp    961 <do_action+0x827> */
	X86_SIM_X86_SUB_JMP(0xa9f, 0x961, x86_l_961);
x86_l_aa4:
	/* 0xaa4: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_aab:
	/* 0xaab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab0:
	/* 0xab0: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ab5:
	/* 0xab5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab7:
	/* 0xab7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aba:
	/* 0xaba: je     ad9 <do_action+0x99f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaba, 0xad9, x86_l_ad9);
x86_l_abc:
	/* 0xabc: imul   rcx,QWORD PTR [rsp+0x78],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 515395075520ULL);
x86_l_ac5:
	/* 0xac5: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aca:
	/* 0xaca: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_acd:
	/* 0xacd: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad0:
	/* 0xad0: jbe    ad9 <do_action+0x99f> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xad0, 0xad9, x86_l_ad9);
x86_l_ad2:
	/* 0xad2: mov    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad7:
	/* 0xad7: jmp    af3 <do_action+0x9b9> */
	X86_SIM_X86_SUB_JMP(0xad7, 0xaf3, x86_l_af3);
x86_l_ad9:
	/* 0xad9: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_ae0:
	/* 0xae0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae2:
	/* 0xae2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_ae5:
	/* 0xae5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_aea:
	/* 0xaea: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aef:
	/* 0xaef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af1:
	/* 0xaf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af3:
	/* 0xaf3: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_af8:
	/* 0xaf8: lea    eax,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_afc:
	/* 0xafc: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_b02:
	/* 0xb02: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b07:
	/* 0xb07: je     b2e <do_action+0x9f4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb07, 0xb2e, x86_l_b2e);
x86_l_b09:
	/* 0xb09: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_b0d:
	/* 0xb0d: mov    rsi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b14:
	/* 0xb14: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b16:
	/* 0xb16: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b1b:
	/* 0xb1b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b20:
	/* 0xb20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b22:
	/* 0xb22: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b27:
	/* 0xb27: mov    QWORD PTR [rdx+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b2e:
	/* 0xb2e: lea    eax,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b32:
	/* 0xb32: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_b38:
	/* 0xb38: je     b65 <do_action+0xa2b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb38, 0xb65, x86_l_b65);
x86_l_b3a:
	/* 0xb3a: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_b3e:
	/* 0xb3e: mov    rsi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b45:
	/* 0xb45: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_b4a:
	/* 0xb4a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b4f:
	/* 0xb4f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_b54:
	/* 0xb54: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b57:
	/* 0xb57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b59:
	/* 0xb59: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5e:
	/* 0xb5e: mov    QWORD PTR [rdx+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b65:
	/* 0xb65: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_b69:
	/* 0xb69: cmp    DWORD PTR [r15+r14*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 17179869184ULL);
x86_l_b6f:
	/* 0xb6f: je     b75 <do_action+0xa3b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb6f, 0xb75, x86_l_b75);
x86_l_b71:
	/* 0xb71: or     BYTE PTR [rdx+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_b75:
	/* 0xb75: mov    QWORD PTR [rdx+0x70],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b79:
	/* 0xb79: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b7c:
	/* 0xb7c: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_b7f:
	/* 0xb7f: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_b86:
	/* 0xb86: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_b87:
	/* 0xb87: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_b89:
	/* 0xb89: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_b8b:
	/* 0xb8b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_b8d:
	/* 0xb8d: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_b8f:
	/* 0xb8f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_b90:
	/* 0xb90: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_b91:
	/* 0xb91: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_b94:
	/* 0xb94: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_b9c:
	/* 0xb9c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ba1:
	/* 0xba1: mov    rax,QWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_ba9:
	/* 0xba9: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_bad:
	/* 0xbad: jmp    6f0 <do_action+0x5b6> */
	X86_SIM_X86_SUB_JMP(0xbad, 0x6f0, x86_l_6f0);
x86_l_bb2:
	/* 0xbb2: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_bba:
	/* 0xbba: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_bc1:
	/* 0xbc1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc3:
	/* 0xbc3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_bc6:
	/* 0xbc6: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bcb:
	/* 0xbcb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bd0:
	/* 0xbd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd2:
	/* 0xbd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd4:
	/* 0xbd4: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_bd7:
	/* 0xbd7: je     5c4 <do_action+0x48a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbd7, 0x5c4, x86_l_5c4);
x86_l_bdd:
	/* 0xbdd: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_be4:
	/* 0xbe4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be9:
	/* 0xbe9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bee:
	/* 0xbee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf0:
	/* 0xbf0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf3:
	/* 0xbf3: je     5c4 <do_action+0x48a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbf3, 0x5c4, x86_l_5c4);
x86_l_bf9:
	/* 0xbf9: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_bfd:
	/* 0xbfd: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c00:
	/* 0xc00: jmp    5c4 <do_action+0x48a> */
	X86_SIM_X86_SUB_JMP(0xc00, 0x5c4, x86_l_5c4);
x86_l_c05:
	/* 0xc05: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_c0d:
	/* 0xc0d: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c14:
	/* 0xc14: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c16:
	/* 0xc16: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c19:
	/* 0xc19: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c1e:
	/* 0xc1e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c23:
	/* 0xc23: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c25:
	/* 0xc25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c27:
	/* 0xc27: jmp    77f <do_action+0x645> */
	X86_SIM_X86_SUB_JMP(0xc27, 0x77f, x86_l_77f);
x86_l_c2c:
	/* 0xc2c: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_c34:
	/* 0xc34: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c3b:
	/* 0xc3b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c3d:
	/* 0xc3d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c40:
	/* 0xc40: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c45:
	/* 0xc45: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c4a:
	/* 0xc4a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4c:
	/* 0xc4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4e:
	/* 0xc4e: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_c51:
	/* 0xc51: je     76f <do_action+0x635> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc51, 0x76f, x86_l_76f);
x86_l_c57:
	/* 0xc57: mov    rdi,QWORD PTR [rip+0x2370] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c5e:
	/* 0xc5e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c63:
	/* 0xc63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c68:
	/* 0xc68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6a:
	/* 0xc6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c6d:
	/* 0xc6d: je     76f <do_action+0x635> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc6d, 0x76f, x86_l_76f);
x86_l_c73:
	/* 0xc73: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_c77:
	/* 0xc77: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c7a:
	/* 0xc7a: jmp    76f <do_action+0x635> */
	X86_SIM_X86_SUB_JMP(0xc7a, 0x76f, x86_l_76f);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x22ULL: goto x86_l_22;
	case 0x54ULL: goto x86_l_54;
	case 0x97ULL: goto x86_l_97;
	case 0xcbULL: goto x86_l_cb;
	case 0xecULL: goto x86_l_ec;
	case 0x10dULL: goto x86_l_10d;
	case 0x12fULL: goto x86_l_12f;
	case 0x17cULL: goto x86_l_17c;
	case 0x25bULL: goto x86_l_25b;
	case 0x274ULL: goto x86_l_274;
	case 0x2c8ULL: goto x86_l_2c8;
	case 0x2e8ULL: goto x86_l_2e8;
	case 0x366ULL: goto x86_l_366;
	case 0x3c0ULL: goto x86_l_3c0;
	case 0x42eULL: goto x86_l_42e;
	case 0x4a4ULL: goto x86_l_4a4;
	case 0x4bfULL: goto x86_l_4bf;
	case 0x501ULL: goto x86_l_501;
	case 0x52aULL: goto x86_l_52a;
	case 0x56fULL: goto x86_l_56f;
	case 0x587ULL: goto x86_l_587;
	case 0x5b0ULL: goto x86_l_5b0;
	case 0x5d7ULL: goto x86_l_5d7;
	case 0x601ULL: goto x86_l_601;
	case 0x633ULL: goto x86_l_633;
	case 0x657ULL: goto x86_l_657;
	case 0x700ULL: goto x86_l_700;
	case 0x728ULL: goto x86_l_728;
	case 0x758ULL: goto x86_l_758;
	case 0x7a2ULL: goto x86_l_7a2;
	case 0x7d4ULL: goto x86_l_7d4;
	case 0x80dULL: goto x86_l_80d;
	case 0x839ULL: goto x86_l_839;
	case 0x872ULL: goto x86_l_872;
	case 0x8a6ULL: goto x86_l_8a6;
	case 0x8d9ULL: goto x86_l_8d9;
	case 0x912ULL: goto x86_l_912;
	case 0x954ULL: goto x86_l_954;
	case 0x98aULL: goto x86_l_98a;
	case 0x9abULL: goto x86_l_9ab;
	case 0x9faULL: goto x86_l_9fa;
	case 0xa17ULL: goto x86_l_a17;
	case 0xa90ULL: goto x86_l_a90;
	case 0xab7ULL: goto x86_l_ab7;
	case 0xaf3ULL: goto x86_l_af3;
	case 0xb22ULL: goto x86_l_b22;
	case 0xb59ULL: goto x86_l_b59;
	case 0xbd4ULL: goto x86_l_bd4;
	case 0xbf0ULL: goto x86_l_bf0;
	case 0xc27ULL: goto x86_l_c27;
	case 0xc4eULL: goto x86_l_c4e;
	case 0xc6aULL: goto x86_l_c6a;
	}

}

X86_SIM_LICENSE();
