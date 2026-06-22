extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char sleepable_offload;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_generic_uprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_12:
	/* 0x12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     1287 <generic_uprobe_actions+0x1287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x1287, x86_l_1287);
x86_l_2e:
	/* 0x2e: mov    r12d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_35:
	/* 0x35: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_39:
	/* 0x39: jl     1287 <generic_uprobe_actions+0x1287> */
	X86_SIM_X86_JCC(X86_CC_L, 0x39, 0x1287, x86_l_1287);
x86_l_3f:
	/* 0x3f: add    rax,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_45:
	/* 0x45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4a:
	/* 0x4a: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_51:
	/* 0x51: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_54:
	/* 0x54: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_56:
	/* 0x56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     1287 <generic_uprobe_actions+0x1287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59, 0x1287, x86_l_1287);
x86_l_5f:
	/* 0x5f: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_62:
	/* 0x62: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_68:
	/* 0x68: add    r12d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6c:
	/* 0x6c: and    r12d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_73:
	/* 0x73: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_76:
	/* 0x76: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_7e:
	/* 0x7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83:
	/* 0x83: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8a:
	/* 0x8a: lea    rsi,[rsp+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_8f:
	/* 0x8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91:
	/* 0x91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94:
	/* 0x94: je     b9 <generic_uprobe_actions+0xb9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94, 0xb9, x86_l_b9);
x86_l_96:
	/* 0x96: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99:
	/* 0x99: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_9c:
	/* 0x9c: je     d6 <generic_uprobe_actions+0xd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c, 0xd6, x86_l_d6);
x86_l_9e:
	/* 0x9e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a3:
	/* 0xa3: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_a8:
	/* 0xa8: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_ad:
	/* 0xad: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b2:
	/* 0xb2: ja     f0 <generic_uprobe_actions+0xf0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb2, 0xf0, x86_l_f0);
x86_l_b4:
	/* 0xb4: jmp    1271 <generic_uprobe_actions+0x1271> */
	X86_SIM_X86_JMP(0xb4, 0x1271, x86_l_1271);
x86_l_b9:
	/* 0xb9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_be:
	/* 0xbe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c3:
	/* 0xc3: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_c5:
	/* 0xc5: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_ca:
	/* 0xca: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cf:
	/* 0xcf: ja     f0 <generic_uprobe_actions+0xf0> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcf, 0xf0, x86_l_f0);
x86_l_d1:
	/* 0xd1: jmp    1271 <generic_uprobe_actions+0x1271> */
	X86_SIM_X86_JMP(0xd1, 0x1271, x86_l_1271);
x86_l_d6:
	/* 0xd6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_db:
	/* 0xdb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e0:
	/* 0xe0: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_e5:
	/* 0xe5: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ea:
	/* 0xea: jbe    1271 <generic_uprobe_actions+0x1271> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xea, 0x1271, x86_l_1271);
x86_l_f0:
	/* 0xf0: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f5:
	/* 0xf5: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fa:
	/* 0xfa: mov    BYTE PTR [rsp+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_fe:
	/* 0xfe: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_103:
	/* 0x103: movsxd rbp,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_108:
	/* 0x108: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_110:
	/* 0x110: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_115:
	/* 0x115: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_11c:
	/* 0x11c: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_121:
	/* 0x121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123:
	/* 0x123: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_126:
	/* 0x126: je     15a <generic_uprobe_actions+0x15a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x126, 0x15a, x86_l_15a);
x86_l_128:
	/* 0x128: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e:
	/* 0x12e: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_131:
	/* 0x131: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_134:
	/* 0x134: jg     165 <generic_uprobe_actions+0x165> */
	X86_SIM_X86_JCC(X86_CC_G, 0x134, 0x165, x86_l_165);
x86_l_136:
	/* 0x136: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_139:
	/* 0x139: jg     19c <generic_uprobe_actions+0x19c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x139, 0x19c, x86_l_19c);
x86_l_13b:
	/* 0x13b: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_13e:
	/* 0x13e: jg     2b8 <generic_uprobe_actions+0x2b8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13e, 0x2b8, x86_l_2b8);
x86_l_144:
	/* 0x144: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_146:
	/* 0x146: je     45f <generic_uprobe_actions+0x45f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146, 0x45f, x86_l_45f);
x86_l_14c:
	/* 0x14c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_14f:
	/* 0x14f: je     2ca <generic_uprobe_actions+0x2ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f, 0x2ca, x86_l_2ca);
x86_l_155:
	/* 0x155: jmp    669 <generic_uprobe_actions+0x669> */
	X86_SIM_X86_JMP(0x155, 0x669, x86_l_669);
x86_l_15a:
	/* 0x15a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d:
	/* 0x15d: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_160:
	/* 0x160: jmp    673 <generic_uprobe_actions+0x673> */
	X86_SIM_X86_JMP(0x160, 0x673, x86_l_673);
x86_l_165:
	/* 0x165: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_168:
	/* 0x168: jg     28d <generic_uprobe_actions+0x28d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x168, 0x28d, x86_l_28d);
x86_l_16e:
	/* 0x16e: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_171:
	/* 0x171: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_174:
	/* 0x174: jb     332 <generic_uprobe_actions+0x332> */
	X86_SIM_X86_JCC(X86_CC_B, 0x174, 0x332, x86_l_332);
x86_l_17a:
	/* 0x17a: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_17d:
	/* 0x17d: je     33d <generic_uprobe_actions+0x33d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17d, 0x33d, x86_l_33d);
x86_l_183:
	/* 0x183: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_186:
	/* 0x186: jne    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x186, 0x66c, x86_l_66c);
x86_l_18c:
	/* 0x18c: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_192:
	/* 0x192: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_197:
	/* 0x197: jmp    647 <generic_uprobe_actions+0x647> */
	X86_SIM_X86_JMP(0x197, 0x647, x86_l_647);
x86_l_19c:
	/* 0x19c: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_19f:
	/* 0x19f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a2:
	/* 0x1a2: jb     329 <generic_uprobe_actions+0x329> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a2, 0x329, x86_l_329);
x86_l_1a8:
	/* 0x1a8: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1ab:
	/* 0x1ab: je     348 <generic_uprobe_actions+0x348> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ab, 0x348, x86_l_348);
x86_l_1b1:
	/* 0x1b1: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1b4:
	/* 0x1b4: jne    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b4, 0x66c, x86_l_66c);
x86_l_1ba:
	/* 0x1ba: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf:
	/* 0x1bf: mov    r15d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c4:
	/* 0x1c4: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1cd:
	/* 0x1cd: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5:
	/* 0x1d5: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1d8:
	/* 0x1d8: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db:
	/* 0x1db: ja     31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1db, 0x31e, x86_l_31e);
x86_l_1e1:
	/* 0x1e1: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1ea:
	/* 0x1ea: jne    31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ea, 0x31e, x86_l_31e);
x86_l_1f0:
	/* 0x1f0: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1f8:
	/* 0x1f8: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1fd:
	/* 0x1fd: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_205:
	/* 0x205: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209:
	/* 0x209: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_20e:
	/* 0x20e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210:
	/* 0x210: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_214:
	/* 0x214: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218:
	/* 0x218: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21d:
	/* 0x21d: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_224:
	/* 0x224: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_227:
	/* 0x227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_229:
	/* 0x229: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: je     31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22c, 0x31e, x86_l_31e);
x86_l_232:
	/* 0x232: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_236:
	/* 0x236: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_23a:
	/* 0x23a: ja     31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x23a, 0x31e, x86_l_31e);
x86_l_240:
	/* 0x240: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_249:
	/* 0x249: jne    31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x249, 0x31e, x86_l_31e);
x86_l_24f:
	/* 0x24f: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_257:
	/* 0x257: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_25f:
	/* 0x25f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_265:
	/* 0x265: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_26d:
	/* 0x26d: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_271:
	/* 0x271: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_276:
	/* 0x276: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_279:
	/* 0x279: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_27b:
	/* 0x27b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_27f:
	/* 0x27f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283:
	/* 0x283: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_288:
	/* 0x288: jmp    570 <generic_uprobe_actions+0x570> */
	X86_SIM_X86_JMP(0x288, 0x570, x86_l_570);
x86_l_28d:
	/* 0x28d: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_290:
	/* 0x290: je     4c9 <generic_uprobe_actions+0x4c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x290, 0x4c9, x86_l_4c9);
x86_l_296:
	/* 0x296: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_299:
	/* 0x299: je     3e7 <generic_uprobe_actions+0x3e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x299, 0x3e7, x86_l_3e7);
x86_l_29f:
	/* 0x29f: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_2a2:
	/* 0x2a2: jne    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a2, 0x66c, x86_l_66c);
x86_l_2a8:
	/* 0x2a8: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2ae:
	/* 0x2ae: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b3:
	/* 0x2b3: jmp    647 <generic_uprobe_actions+0x647> */
	X86_SIM_X86_JMP(0x2b3, 0x647, x86_l_647);
x86_l_2b8:
	/* 0x2b8: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2bb:
	/* 0x2bb: je     4bf <generic_uprobe_actions+0x4bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bb, 0x4bf, x86_l_4bf);
x86_l_2c1:
	/* 0x2c1: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2c4:
	/* 0x2c4: jne    669 <generic_uprobe_actions+0x669> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c4, 0x669, x86_l_669);
x86_l_2ca:
	/* 0x2ca: mov    r13d,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf:
	/* 0x2cf: mov    r15d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2d4:
	/* 0x2d4: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2dd:
	/* 0x2dd: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e5:
	/* 0x2e5: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2ed:
	/* 0x2ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f2:
	/* 0x2f2: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_2f9:
	/* 0x2f9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fe:
	/* 0x2fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300:
	/* 0x300: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: je     31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x303, 0x31e, x86_l_31e);
x86_l_305:
	/* 0x305: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_309:
	/* 0x309: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_30d:
	/* 0x30d: ja     31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x30d, 0x31e, x86_l_31e);
x86_l_30f:
	/* 0x30f: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_318:
	/* 0x318: je     4d9 <generic_uprobe_actions+0x4d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x318, 0x4d9, x86_l_4d9);
x86_l_31e:
	/* 0x31e: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_324:
	/* 0x324: jmp    669 <generic_uprobe_actions+0x669> */
	X86_SIM_X86_JMP(0x324, 0x669, x86_l_669);
x86_l_329:
	/* 0x329: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32e:
	/* 0x32e: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_332:
	/* 0x332: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_338:
	/* 0x338: jmp    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JMP(0x338, 0x66c, x86_l_66c);
x86_l_33d:
	/* 0x33d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_340:
	/* 0x340: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_343:
	/* 0x343: jmp    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JMP(0x343, 0x66c, x86_l_66c);
x86_l_348:
	/* 0x348: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_34e:
	/* 0x34e: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_354:
	/* 0x354: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_359:
	/* 0x359: je     647 <generic_uprobe_actions+0x647> */
	X86_SIM_X86_JCC(X86_CC_E, 0x359, 0x647, x86_l_647);
x86_l_35f:
	/* 0x35f: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_364:
	/* 0x364: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_368:
	/* 0x368: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_36d:
	/* 0x36d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f:
	/* 0x36f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_374:
	/* 0x374: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_379:
	/* 0x379: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_380:
	/* 0x380: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_385:
	/* 0x385: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_387:
	/* 0x387: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_38a:
	/* 0x38a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: je     39c <generic_uprobe_actions+0x39c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38d, 0x39c, x86_l_39c);
x86_l_38f:
	/* 0x38f: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_396:
	/* 0x396: jb     63a <generic_uprobe_actions+0x63a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x396, 0x63a, x86_l_63a);
x86_l_39c:
	/* 0x39c: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_39f:
	/* 0x39f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_3a1:
	/* 0x3a1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3a9:
	/* 0x3a9: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_3ac:
	/* 0x3ac: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b0:
	/* 0x3b0: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_3b7:
	/* 0x3b7: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_3c1:
	/* 0x3c1: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c6:
	/* 0x3c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cb:
	/* 0x3cb: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_3d2:
	/* 0x3d2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3d5:
	/* 0x3d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d7:
	/* 0x3d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3da:
	/* 0x3da: je     611 <generic_uprobe_actions+0x611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3da, 0x611, x86_l_611);
x86_l_3e0:
	/* 0x3e0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3e2:
	/* 0x3e2: jmp    631 <generic_uprobe_actions+0x631> */
	X86_SIM_X86_JMP(0x3e2, 0x631, x86_l_631);
x86_l_3e7:
	/* 0x3e7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3ec:
	/* 0x3ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ee:
	/* 0x3ee: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f3:
	/* 0x3f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f8:
	/* 0x3f8: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_3ff:
	/* 0x3ff: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_404:
	/* 0x404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406:
	/* 0x406: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_409:
	/* 0x409: je     66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x409, 0x66c, x86_l_66c);
x86_l_40f:
	/* 0x40f: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_413:
	/* 0x413: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_418:
	/* 0x418: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_420:
	/* 0x420: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_425:
	/* 0x425: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_42c:
	/* 0x42c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_431:
	/* 0x431: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_433:
	/* 0x433: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_43b:
	/* 0x43b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: je     586 <generic_uprobe_actions+0x586> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43e, 0x586, x86_l_586);
x86_l_444:
	/* 0x444: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_447:
	/* 0x447: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_44c:
	/* 0x44c: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_453:
	/* 0x453: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_458:
	/* 0x458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a:
	/* 0x45a: jmp    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JMP(0x45a, 0x66c, x86_l_66c);
x86_l_45f:
	/* 0x45f: cmp    DWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_465:
	/* 0x465: je     486 <generic_uprobe_actions+0x486> */
	X86_SIM_X86_JCC(X86_CC_E, 0x465, 0x486, x86_l_486);
x86_l_467:
	/* 0x467: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_46c:
	/* 0x46c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_471:
	/* 0x471: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_478:
	/* 0x478: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_47b:
	/* 0x47b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47d:
	/* 0x47d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47f:
	/* 0x47f: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_486:
	/* 0x486: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_48c:
	/* 0x48c: cmp    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_492:
	/* 0x492: je     66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x492, 0x66c, x86_l_66c);
x86_l_498:
	/* 0x498: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_49d:
	/* 0x49d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_4a2:
	/* 0x4a2: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_4a9:
	/* 0x4a9: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_4ae:
	/* 0x4ae: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4ba:
	/* 0x4ba: jmp    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JMP(0x4ba, 0x66c, x86_l_66c);
x86_l_4bf:
	/* 0x4bf: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4c4:
	/* 0x4c4: jmp    647 <generic_uprobe_actions+0x647> */
	X86_SIM_X86_JMP(0x4c4, 0x647, x86_l_647);
x86_l_4c9:
	/* 0x4c9: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_4cf:
	/* 0x4cf: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4d4:
	/* 0x4d4: jmp    647 <generic_uprobe_actions+0x647> */
	X86_SIM_X86_JMP(0x4d4, 0x647, x86_l_647);
x86_l_4d9:
	/* 0x4d9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4de:
	/* 0x4de: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_4e6:
	/* 0x4e6: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_4ee:
	/* 0x4ee: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_4f3:
	/* 0x4f3: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_4fb:
	/* 0x4fb: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ff:
	/* 0x4ff: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_504:
	/* 0x504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_506:
	/* 0x506: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_50a:
	/* 0x50a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50e:
	/* 0x50e: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_511:
	/* 0x511: jne    5ee <generic_uprobe_actions+0x5ee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x511, 0x5ee, x86_l_5ee);
x86_l_517:
	/* 0x517: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_51b:
	/* 0x51b: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_51f:
	/* 0x51f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_524:
	/* 0x524: ja     31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x524, 0x31e, x86_l_31e);
x86_l_52a:
	/* 0x52a: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_533:
	/* 0x533: jne    31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x533, 0x31e, x86_l_31e);
x86_l_539:
	/* 0x539: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_541:
	/* 0x541: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_546:
	/* 0x546: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_54a:
	/* 0x54a: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_551:
	/* 0x551: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_556:
	/* 0x556: and    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_55e:
	/* 0x55e: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_561:
	/* 0x561: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_566:
	/* 0x566: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_569:
	/* 0x569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56b:
	/* 0x56b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_570:
	/* 0x570: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_577:
	/* 0x577: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_57a:
	/* 0x57a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_57d:
	/* 0x57d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57f:
	/* 0x57f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_581:
	/* 0x581: jmp    31e <generic_uprobe_actions+0x31e> */
	X86_SIM_X86_JMP(0x581, 0x31e, x86_l_31e);
x86_l_586:
	/* 0x586: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_58b:
	/* 0x58b: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_592:
	/* 0x592: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_597:
	/* 0x597: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_59c:
	/* 0x59c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5a1:
	/* 0x5a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a3:
	/* 0x5a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a6:
	/* 0x5a6: je     447 <generic_uprobe_actions+0x447> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a6, 0x447, x86_l_447);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b1:
	/* 0x5b1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5b3:
	/* 0x5b3: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b7:
	/* 0x5b7: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_5be:
	/* 0x5be: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5cd:
	/* 0x5cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d2:
	/* 0x5d2: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5d9:
	/* 0x5d9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5dc:
	/* 0x5dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de:
	/* 0x5de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e1:
	/* 0x5e1: je     c04 <generic_uprobe_actions+0xc04> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e1, 0xc04, x86_l_c04);
x86_l_5e7:
	/* 0x5e7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5e9:
	/* 0x5e9: jmp    c24 <generic_uprobe_actions+0xc24> */
	X86_SIM_X86_JMP(0x5e9, 0xc24, x86_l_c24);
x86_l_5ee:
	/* 0x5ee: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5f3:
	/* 0x5f3: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_5fa:
	/* 0x5fa: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5fd:
	/* 0x5fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ff:
	/* 0x5ff: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_602:
	/* 0x602: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_605:
	/* 0x605: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_607:
	/* 0x607: jne    673 <generic_uprobe_actions+0x673> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x607, 0x673, x86_l_673);
x86_l_609:
	/* 0x609: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_60f:
	/* 0x60f: jmp    66c <generic_uprobe_actions+0x66c> */
	X86_SIM_X86_JMP(0x60f, 0x66c, x86_l_66c);
x86_l_611:
	/* 0x611: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_619:
	/* 0x619: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_61e:
	/* 0x61e: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_625:
	/* 0x625: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_628:
	/* 0x628: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_62d:
	/* 0x62d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62f:
	/* 0x62f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_631:
	/* 0x631: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_634:
	/* 0x634: je     bc2 <generic_uprobe_actions+0xbc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x634, 0xbc2, x86_l_bc2);
x86_l_63a:
	/* 0x63a: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_63e:
	/* 0x63e: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_641:
	/* 0x641: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_647:
	/* 0x647: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64e:
	/* 0x64e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_653:
	/* 0x653: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_65a:
	/* 0x65a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_65d:
	/* 0x65d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65f:
	/* 0x65f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_662:
	/* 0x662: je     669 <generic_uprobe_actions+0x669> */
	X86_SIM_X86_JCC(X86_CC_E, 0x662, 0x669, x86_l_669);
x86_l_664:
	/* 0x664: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_669:
	/* 0x669: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_66c:
	/* 0x66c: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_670:
	/* 0x670: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_673:
	/* 0x673: lea    eax,[r13*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_67b:
	/* 0x67b: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_67f:
	/* 0x67f: jae    126c <generic_uprobe_actions+0x126c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x67f, 0x126c, x86_l_126c);
x86_l_685:
	/* 0x685: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68a:
	/* 0x68a: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_68d:
	/* 0x68d: movsxd rbp,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_692:
	/* 0x692: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_69a:
	/* 0x69a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_69f:
	/* 0x69f: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_6a6:
	/* 0x6a6: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6ab:
	/* 0x6ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ad:
	/* 0x6ad: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b0:
	/* 0x6b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b3:
	/* 0x6b3: je     cbc <generic_uprobe_actions+0xcbc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b3, 0xcbc, x86_l_cbc);
x86_l_6b9:
	/* 0x6b9: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_6bc:
	/* 0x6bc: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_6bf:
	/* 0x6bf: jg     6e5 <generic_uprobe_actions+0x6e5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6bf, 0x6e5, x86_l_6e5);
x86_l_6c1:
	/* 0x6c1: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6c4:
	/* 0x6c4: jg     71c <generic_uprobe_actions+0x71c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6c4, 0x71c, x86_l_71c);
x86_l_6c6:
	/* 0x6c6: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6c9:
	/* 0x6c9: jg     854 <generic_uprobe_actions+0x854> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6c9, 0x854, x86_l_854);
x86_l_6cf:
	/* 0x6cf: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6d1:
	/* 0x6d1: je     ad4 <generic_uprobe_actions+0xad4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d1, 0xad4, x86_l_ad4);
x86_l_6d7:
	/* 0x6d7: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6da:
	/* 0x6da: je     866 <generic_uprobe_actions+0x866> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6da, 0x866, x86_l_866);
x86_l_6e0:
	/* 0x6e0: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0x6e0, 0xcb2, x86_l_cb2);
x86_l_6e5:
	/* 0x6e5: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_6e8:
	/* 0x6e8: jg     828 <generic_uprobe_actions+0x828> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e8, 0x828, x86_l_828);
x86_l_6ee:
	/* 0x6ee: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_6f1:
	/* 0x6f1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6f4:
	/* 0x6f4: jb     992 <generic_uprobe_actions+0x992> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6f4, 0x992, x86_l_992);
x86_l_6fa:
	/* 0x6fa: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6fd:
	/* 0x6fd: je     9ab <generic_uprobe_actions+0x9ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fd, 0x9ab, x86_l_9ab);
x86_l_703:
	/* 0x703: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_706:
	/* 0x706: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x706, 0xcb2, x86_l_cb2);
x86_l_70c:
	/* 0x70c: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_70f:
	/* 0x70f: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_712:
	/* 0x712: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_717:
	/* 0x717: jmp    c8d <generic_uprobe_actions+0xc8d> */
	X86_SIM_X86_JMP(0x717, 0xc8d, x86_l_c8d);
x86_l_71c:
	/* 0x71c: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_71f:
	/* 0x71f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_722:
	/* 0x722: jb     99a <generic_uprobe_actions+0x99a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x722, 0x99a, x86_l_99a);
x86_l_728:
	/* 0x728: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_72b:
	/* 0x72b: je     9b8 <generic_uprobe_actions+0x9b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72b, 0x9b8, x86_l_9b8);
x86_l_731:
	/* 0x731: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_734:
	/* 0x734: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x734, 0xcb2, x86_l_cb2);
x86_l_73a:
	/* 0x73a: mov    eax,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_73f:
	/* 0x73f: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_743:
	/* 0x743: mov    r14d,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_748:
	/* 0x748: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_751:
	/* 0x751: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_759:
	/* 0x759: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_75c:
	/* 0x75c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_75f:
	/* 0x75f: ja     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x75f, 0xcb2, x86_l_cb2);
x86_l_765:
	/* 0x765: cmp    DWORD PTR [r8+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_76e:
	/* 0x76e: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x76e, 0xcb2, x86_l_cb2);
x86_l_774:
	/* 0x774: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_77c:
	/* 0x77c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_781:
	/* 0x781: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_789:
	/* 0x789: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_78d:
	/* 0x78d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_792:
	/* 0x792: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_795:
	/* 0x795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_797:
	/* 0x797: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_79b:
	/* 0x79b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79f:
	/* 0x79f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a4:
	/* 0x7a4: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_7ab:
	/* 0x7ab: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_7ae:
	/* 0x7ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b0:
	/* 0x7b0: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_7b3:
	/* 0x7b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b6:
	/* 0x7b6: je     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b6, 0xcb2, x86_l_cb2);
x86_l_7bc:
	/* 0x7bc: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7c0:
	/* 0x7c0: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_7c4:
	/* 0x7c4: ja     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7c4, 0xcb2, x86_l_cb2);
x86_l_7ca:
	/* 0x7ca: cmp    DWORD PTR [r8+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_7d3:
	/* 0x7d3: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7d3, 0xcb2, x86_l_cb2);
x86_l_7d9:
	/* 0x7d9: mov    rcx,QWORD PTR [r8+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_7e1:
	/* 0x7e1: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_7e9:
	/* 0x7e9: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7ef:
	/* 0x7ef: mov    ecx,DWORD PTR [r8+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_7f7:
	/* 0x7f7: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fb:
	/* 0x7fb: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_800:
	/* 0x800: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_803:
	/* 0x803: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_805:
	/* 0x805: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_809:
	/* 0x809: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80d:
	/* 0x80d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_812:
	/* 0x812: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_819:
	/* 0x819: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_81c:
	/* 0x81c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_81f:
	/* 0x81f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_821:
	/* 0x821: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_823:
	/* 0x823: jmp    caf <generic_uprobe_actions+0xcaf> */
	X86_SIM_X86_JMP(0x823, 0xcaf, x86_l_caf);
x86_l_828:
	/* 0x828: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_82b:
	/* 0x82b: je     b4b <generic_uprobe_actions+0xb4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82b, 0xb4b, x86_l_b4b);
x86_l_831:
	/* 0x831: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_834:
	/* 0x834: je     a5a <generic_uprobe_actions+0xa5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x834, 0xa5a, x86_l_a5a);
x86_l_83a:
	/* 0x83a: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_83d:
	/* 0x83d: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x83d, 0xcb2, x86_l_cb2);
x86_l_843:
	/* 0x843: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_846:
	/* 0x846: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_84a:
	/* 0x84a: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_84f:
	/* 0x84f: jmp    c8d <generic_uprobe_actions+0xc8d> */
	X86_SIM_X86_JMP(0x84f, 0xc8d, x86_l_c8d);
x86_l_854:
	/* 0x854: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_857:
	/* 0x857: je     b3e <generic_uprobe_actions+0xb3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x857, 0xb3e, x86_l_b3e);
x86_l_85d:
	/* 0x85d: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_860:
	/* 0x860: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x860, 0xcb2, x86_l_cb2);
x86_l_866:
	/* 0x866: mov    r14d,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_86b:
	/* 0x86b: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_86f:
	/* 0x86f: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_874:
	/* 0x874: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_879:
	/* 0x879: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_882:
	/* 0x882: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_88a:
	/* 0x88a: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_892:
	/* 0x892: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_897:
	/* 0x897: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_89e:
	/* 0x89e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8a3:
	/* 0x8a3: mov    QWORD PTR [rsp+0x48],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8a8:
	/* 0x8a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8aa:
	/* 0x8aa: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8af:
	/* 0x8af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: je     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b2, 0xcb2, x86_l_cb2);
x86_l_8b8:
	/* 0x8b8: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_8bc:
	/* 0x8bc: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_8c0:
	/* 0x8c0: ja     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8c0, 0xcb2, x86_l_cb2);
x86_l_8c6:
	/* 0x8c6: cmp    DWORD PTR [r8+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_8cf:
	/* 0x8cf: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8cf, 0xcb2, x86_l_cb2);
x86_l_8d5:
	/* 0x8d5: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8da:
	/* 0x8da: mov    rax,QWORD PTR [r8+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_8e2:
	/* 0x8e2: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_8ea:
	/* 0x8ea: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_8ef:
	/* 0x8ef: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_8f7:
	/* 0x8f7: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8fb:
	/* 0x8fb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_900:
	/* 0x900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_902:
	/* 0x902: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_906:
	/* 0x906: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90a:
	/* 0x90a: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_90d:
	/* 0x90d: jne    be1 <generic_uprobe_actions+0xbe1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x90d, 0xbe1, x86_l_be1);
x86_l_913:
	/* 0x913: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_918:
	/* 0x918: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_91b:
	/* 0x91b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_91e:
	/* 0x91e: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_923:
	/* 0x923: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_928:
	/* 0x928: ja     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x928, 0xcb2, x86_l_cb2);
x86_l_92e:
	/* 0x92e: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_931:
	/* 0x931: cmp    DWORD PTR [r8+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_93a:
	/* 0x93a: jne    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x93a, 0xcb2, x86_l_cb2);
x86_l_940:
	/* 0x940: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_948:
	/* 0x948: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_94d:
	/* 0x94d: lea    rdx,[r8+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_951:
	/* 0x951: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_958:
	/* 0x958: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_95d:
	/* 0x95d: and    esi,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R8, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_965:
	/* 0x965: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_968:
	/* 0x968: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_96d:
	/* 0x96d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_970:
	/* 0x970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_972:
	/* 0x972: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_977:
	/* 0x977: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_97e:
	/* 0x97e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_981:
	/* 0x981: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_984:
	/* 0x984: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_986:
	/* 0x986: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_988:
	/* 0x988: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_98d:
	/* 0x98d: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0x98d, 0xcb2, x86_l_cb2);
x86_l_992:
	/* 0x992: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_995:
	/* 0x995: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0x995, 0xcb2, x86_l_cb2);
x86_l_99a:
	/* 0x99a: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_99d:
	/* 0x99d: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_9a2:
	/* 0x9a2: mov    DWORD PTR [r8+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9a6:
	/* 0x9a6: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0x9a6, 0xcb2, x86_l_cb2);
x86_l_9ab:
	/* 0x9ab: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9b3:
	/* 0x9b3: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0x9b3, 0xcb2, x86_l_cb2);
x86_l_9b8:
	/* 0x9b8: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_9bb:
	/* 0x9bb: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9be:
	/* 0x9be: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_9c4:
	/* 0x9c4: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_9c9:
	/* 0x9c9: je     c8d <generic_uprobe_actions+0xc8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c9, 0xc8d, x86_l_c8d);
x86_l_9cf:
	/* 0x9cf: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_9d2:
	/* 0x9d2: mov    eax,DWORD PTR [r12+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_9d7:
	/* 0x9d7: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_9db:
	/* 0x9db: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9e0:
	/* 0x9e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e2:
	/* 0x9e2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9e7:
	/* 0x9e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9ec:
	/* 0x9ec: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_9f3:
	/* 0x9f3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f8:
	/* 0x9f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fa:
	/* 0x9fa: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_9fd:
	/* 0x9fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a00:
	/* 0xa00: je     a0f <generic_uprobe_actions+0xa0f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa00, 0xa0f, x86_l_a0f);
x86_l_a02:
	/* 0xa02: cmp    r14,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_a09:
	/* 0xa09: jb     c80 <generic_uprobe_actions+0xc80> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa09, 0xc80, x86_l_c80);
x86_l_a0f:
	/* 0xa0f: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a12:
	/* 0xa12: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a14:
	/* 0xa14: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_a17:
	/* 0xa17: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a1c:
	/* 0xa1c: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_a1f:
	/* 0xa1f: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a23:
	/* 0xa23: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_a2a:
	/* 0xa2a: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_a34:
	/* 0xa34: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a39:
	/* 0xa39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a3e:
	/* 0xa3e: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a45:
	/* 0xa45: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a48:
	/* 0xa48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4a:
	/* 0xa4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a4d:
	/* 0xa4d: je     c57 <generic_uprobe_actions+0xc57> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa4d, 0xc57, x86_l_c57);
x86_l_a53:
	/* 0xa53: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a55:
	/* 0xa55: jmp    c77 <generic_uprobe_actions+0xc77> */
	X86_SIM_X86_JMP(0xa55, 0xc77, x86_l_c77);
x86_l_a5a:
	/* 0xa5a: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_a5d:
	/* 0xa5d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a62:
	/* 0xa62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a69:
	/* 0xa69: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a6e:
	/* 0xa6e: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_a75:
	/* 0xa75: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7a:
	/* 0xa7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7c:
	/* 0xa7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7f:
	/* 0xa7f: je     acc <generic_uprobe_actions+0xacc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7f, 0xacc, x86_l_acc);
x86_l_a81:
	/* 0xa81: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a85:
	/* 0xa85: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a8a:
	/* 0xa8a: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_a92:
	/* 0xa92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a97:
	/* 0xa97: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_a9e:
	/* 0xa9e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa3:
	/* 0xaa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa5:
	/* 0xaa5: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_aad:
	/* 0xaad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab0:
	/* 0xab0: je     b5c <generic_uprobe_actions+0xb5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab0, 0xb5c, x86_l_b5c);
x86_l_ab6:
	/* 0xab6: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ab9:
	/* 0xab9: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_abe:
	/* 0xabe: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_ac5:
	/* 0xac5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aca:
	/* 0xaca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acc:
	/* 0xacc: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_acf:
	/* 0xacf: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0xacf, 0xcb2, x86_l_cb2);
x86_l_ad4:
	/* 0xad4: cmp    DWORD PTR [r12+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_ada:
	/* 0xada: je     b01 <generic_uprobe_actions+0xb01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xada, 0xb01, x86_l_b01);
x86_l_adc:
	/* 0xadc: or     BYTE PTR [r8+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_ae1:
	/* 0xae1: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_ae6:
	/* 0xae6: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_aed:
	/* 0xaed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_af0:
	/* 0xaf0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af2:
	/* 0xaf2: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_af5:
	/* 0xaf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af7:
	/* 0xaf7: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_afa:
	/* 0xafa: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b01:
	/* 0xb01: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b05:
	/* 0xb05: cmp    DWORD PTR [r12+r13*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 17179869184ULL);
x86_l_b0b:
	/* 0xb0b: je     cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0b, 0xcb2, x86_l_cb2);
x86_l_b11:
	/* 0xb11: or     BYTE PTR [r8+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_b16:
	/* 0xb16: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b1b:
	/* 0xb1b: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b22:
	/* 0xb22: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_b27:
	/* 0xb27: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b2a:
	/* 0xb2a: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_b2d:
	/* 0xb2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2f:
	/* 0xb2f: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_b32:
	/* 0xb32: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b39:
	/* 0xb39: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0xb39, 0xcb2, x86_l_cb2);
x86_l_b3e:
	/* 0xb3e: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_b41:
	/* 0xb41: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b46:
	/* 0xb46: jmp    c8d <generic_uprobe_actions+0xc8d> */
	X86_SIM_X86_JMP(0xb46, 0xc8d, x86_l_c8d);
x86_l_b4b:
	/* 0xb4b: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_b4e:
	/* 0xb4e: add    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_b52:
	/* 0xb52: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b57:
	/* 0xb57: jmp    c8d <generic_uprobe_actions+0xc8d> */
	X86_SIM_X86_JMP(0xb57, 0xc8d, x86_l_c8d);
x86_l_b5c:
	/* 0xb5c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b61:
	/* 0xb61: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_b68:
	/* 0xb68: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b6d:
	/* 0xb6d: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_b72:
	/* 0xb72: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b77:
	/* 0xb77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b79:
	/* 0xb79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b7c:
	/* 0xb7c: je     ab9 <generic_uprobe_actions+0xab9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7c, 0xab9, x86_l_ab9);
x86_l_b82:
	/* 0xb82: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b85:
	/* 0xb85: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_b87:
	/* 0xb87: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b8b:
	/* 0xb8b: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_b92:
	/* 0xb92: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_b9c:
	/* 0xb9c: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ba1:
	/* 0xba1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba6:
	/* 0xba6: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_bad:
	/* 0xbad: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_bb0:
	/* 0xbb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb2:
	/* 0xbb2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bb5:
	/* 0xbb5: je     11b5 <generic_uprobe_actions+0x11b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb5, 0x11b5, x86_l_11b5);
x86_l_bbb:
	/* 0xbbb: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bbd:
	/* 0xbbd: jmp    11d5 <generic_uprobe_actions+0x11d5> */
	X86_SIM_X86_JMP(0xbbd, 0x11d5, x86_l_11d5);
x86_l_bc2:
	/* 0xbc2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bc7:
	/* 0xbc7: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_bce:
	/* 0xbce: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd3:
	/* 0xbd3: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_bd8:
	/* 0xbd8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bda:
	/* 0xbda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdc:
	/* 0xbdc: jmp    641 <generic_uprobe_actions+0x641> */
	X86_SIM_X86_JMP(0xbdc, 0x641, x86_l_641);
x86_l_be1:
	/* 0xbe1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_be6:
	/* 0xbe6: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_bed:
	/* 0xbed: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_bf0:
	/* 0xbf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf2:
	/* 0xbf2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf4:
	/* 0xbf4: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bf9:
	/* 0xbf9: jne    cbc <generic_uprobe_actions+0xcbc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbf9, 0xcbc, x86_l_cbc);
x86_l_bff:
	/* 0xbff: jmp    cb2 <generic_uprobe_actions+0xcb2> */
	X86_SIM_X86_JMP(0xbff, 0xcb2, x86_l_cb2);
x86_l_c04:
	/* 0xc04: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_c0c:
	/* 0xc0c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c11:
	/* 0xc11: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c18:
	/* 0xc18: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c1b:
	/* 0xc1b: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c20:
	/* 0xc20: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c22:
	/* 0xc22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c24:
	/* 0xc24: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c29:
	/* 0xc29: je     447 <generic_uprobe_actions+0x447> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc29, 0x447, x86_l_447);
x86_l_c2f:
	/* 0xc2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c34:
	/* 0xc34: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c3b:
	/* 0xc3b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c40:
	/* 0xc40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c42:
	/* 0xc42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c45:
	/* 0xc45: je     447 <generic_uprobe_actions+0x447> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc45, 0x447, x86_l_447);
x86_l_c4b:
	/* 0xc4b: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c4f:
	/* 0xc4f: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c52:
	/* 0xc52: jmp    447 <generic_uprobe_actions+0x447> */
	X86_SIM_X86_JMP(0xc52, 0x447, x86_l_447);
x86_l_c57:
	/* 0xc57: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_c5f:
	/* 0xc5f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c64:
	/* 0xc64: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c6b:
	/* 0xc6b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c6e:
	/* 0xc6e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c73:
	/* 0xc73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c75:
	/* 0xc75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c77:
	/* 0xc77: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_c7a:
	/* 0xc7a: je     1173 <generic_uprobe_actions+0x1173> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7a, 0x1173, x86_l_1173);
x86_l_c80:
	/* 0xc80: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c84:
	/* 0xc84: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c87:
	/* 0xc87: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_c8d:
	/* 0xc8d: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c94:
	/* 0xc94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c99:
	/* 0xc99: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_ca0:
	/* 0xca0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ca3:
	/* 0xca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca5:
	/* 0xca5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca8:
	/* 0xca8: je     caf <generic_uprobe_actions+0xcaf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca8, 0xcaf, x86_l_caf);
x86_l_caa:
	/* 0xcaa: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_caf:
	/* 0xcaf: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_cb2:
	/* 0xcb2: mov    QWORD PTR [r8+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cb6:
	/* 0xcb6: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cb9:
	/* 0xcb9: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_cbc:
	/* 0xcbc: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_cc4:
	/* 0xcc4: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_cc8:
	/* 0xcc8: jae    d22 <generic_uprobe_actions+0xd22> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xcc8, 0xd22, x86_l_d22);
x86_l_cca:
	/* 0xcca: mov    r15d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R15, X86_WIDTH_32);
x86_l_ccd:
	/* 0xccd: movsxd rbp,DWORD PTR [r12+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_cd2:
	/* 0xcd2: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_cda:
	/* 0xcda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdf:
	/* 0xcdf: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ce6:
	/* 0xce6: lea    rsi,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_ceb:
	/* 0xceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ced:
	/* 0xced: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf0:
	/* 0xcf0: je     d22 <generic_uprobe_actions+0xd22> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf0, 0xd22, x86_l_d22);
x86_l_cf2:
	/* 0xcf2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_cf5:
	/* 0xcf5: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_cf8:
	/* 0xcf8: jle    d2c <generic_uprobe_actions+0xd2c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xcf8, 0xd2c, x86_l_d2c);
x86_l_cfa:
	/* 0xcfa: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_cfd:
	/* 0xcfd: jg     d50 <generic_uprobe_actions+0xd50> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcfd, 0xd50, x86_l_d50);
x86_l_cff:
	/* 0xcff: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_d02:
	/* 0xd02: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d05:
	/* 0xd05: jb     e83 <generic_uprobe_actions+0xe83> */
	X86_SIM_X86_JCC(X86_CC_B, 0xd05, 0xe83, x86_l_e83);
x86_l_d0b:
	/* 0xd0b: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d0e:
	/* 0xd0e: je     f96 <generic_uprobe_actions+0xf96> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd0e, 0xf96, x86_l_f96);
x86_l_d14:
	/* 0xd14: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_d17:
	/* 0xd17: je     123c <generic_uprobe_actions+0x123c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd17, 0x123c, x86_l_123c);
x86_l_d1d:
	/* 0xd1d: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0xd1d, 0x1263, x86_l_1263);
x86_l_d22:
	/* 0xd22: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d27:
	/* 0xd27: jmp    126c <generic_uprobe_actions+0x126c> */
	X86_SIM_X86_JMP(0xd27, 0x126c, x86_l_126c);
x86_l_d2c:
	/* 0xd2c: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d2f:
	/* 0xd2f: jg     d84 <generic_uprobe_actions+0xd84> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd2f, 0xd84, x86_l_d84);
x86_l_d31:
	/* 0xd31: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_d33:
	/* 0xd33: je     1016 <generic_uprobe_actions+0x1016> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd33, 0x1016, x86_l_1016);
x86_l_d39:
	/* 0xd39: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_d3c:
	/* 0xd3c: je     e91 <generic_uprobe_actions+0xe91> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd3c, 0xe91, x86_l_e91);
x86_l_d42:
	/* 0xd42: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_d45:
	/* 0xd45: je     123c <generic_uprobe_actions+0x123c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd45, 0x123c, x86_l_123c);
x86_l_d4b:
	/* 0xd4b: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0xd4b, 0x1263, x86_l_1263);
x86_l_d50:
	/* 0xd50: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d55:
	/* 0xd55: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d5a:
	/* 0xd5a: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_d5d:
	/* 0xd5d: je     123c <generic_uprobe_actions+0x123c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5d, 0x123c, x86_l_123c);
x86_l_d63:
	/* 0xd63: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_d66:
	/* 0xd66: je     f9e <generic_uprobe_actions+0xf9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd66, 0xf9e, x86_l_f9e);
x86_l_d6c:
	/* 0xd6c: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d71:
	/* 0xd71: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d76:
	/* 0xd76: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_d79:
	/* 0xd79: je     123c <generic_uprobe_actions+0x123c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd79, 0x123c, x86_l_123c);
x86_l_d7f:
	/* 0xd7f: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0xd7f, 0x1263, x86_l_1263);
x86_l_d84:
	/* 0xd84: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_d87:
	/* 0xd87: je     e91 <generic_uprobe_actions+0xe91> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd87, 0xe91, x86_l_e91);
x86_l_d8d:
	/* 0xd8d: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_d90:
	/* 0xd90: je     1070 <generic_uprobe_actions+0x1070> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd90, 0x1070, x86_l_1070);
x86_l_d96:
	/* 0xd96: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_d99:
	/* 0xd99: jne    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd99, 0x1263, x86_l_1263);
x86_l_d9f:
	/* 0xd9f: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_da4:
	/* 0xda4: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_da9:
	/* 0xda9: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_db2:
	/* 0xdb2: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dba:
	/* 0xdba: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_dbd:
	/* 0xdbd: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dc0:
	/* 0xdc0: ja     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_A, 0xdc0, 0x1263, x86_l_1263);
x86_l_dc6:
	/* 0xdc6: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_dcf:
	/* 0xdcf: jne    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdcf, 0x1263, x86_l_1263);
x86_l_dd5:
	/* 0xdd5: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_ddd:
	/* 0xddd: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_de2:
	/* 0xde2: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_dea:
	/* 0xdea: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dee:
	/* 0xdee: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_df3:
	/* 0xdf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df5:
	/* 0xdf5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_df9:
	/* 0xdf9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfd:
	/* 0xdfd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e02:
	/* 0xe02: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e09:
	/* 0xe09: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e0c:
	/* 0xe0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0e:
	/* 0xe0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e11:
	/* 0xe11: je     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe11, 0x1263, x86_l_1263);
x86_l_e17:
	/* 0xe17: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e1b:
	/* 0xe1b: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_e1f:
	/* 0xe1f: ja     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe1f, 0x1263, x86_l_1263);
x86_l_e25:
	/* 0xe25: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_e2e:
	/* 0xe2e: jne    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe2e, 0x1263, x86_l_1263);
x86_l_e34:
	/* 0xe34: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_e3c:
	/* 0xe3c: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_e44:
	/* 0xe44: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e4a:
	/* 0xe4a: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e52:
	/* 0xe52: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e56:
	/* 0xe56: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_e5b:
	/* 0xe5b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_e5e:
	/* 0xe5e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e60:
	/* 0xe60: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e64:
	/* 0xe64: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e68:
	/* 0xe68: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e6d:
	/* 0xe6d: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e74:
	/* 0xe74: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e77:
	/* 0xe77: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e7a:
	/* 0xe7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7c:
	/* 0xe7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7e:
	/* 0xe7e: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0xe7e, 0x1263, x86_l_1263);
x86_l_e83:
	/* 0xe83: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_e88:
	/* 0xe88: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e8c:
	/* 0xe8c: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0xe8c, 0x1263, x86_l_1263);
x86_l_e91:
	/* 0xe91: mov    r13d,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_e96:
	/* 0xe96: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_e9b:
	/* 0xe9b: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ea4:
	/* 0xea4: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eac:
	/* 0xeac: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_eb4:
	/* 0xeb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb9:
	/* 0xeb9: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_ec0:
	/* 0xec0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec5:
	/* 0xec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec7:
	/* 0xec7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eca:
	/* 0xeca: je     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeca, 0x1263, x86_l_1263);
x86_l_ed0:
	/* 0xed0: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ed4:
	/* 0xed4: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_ed8:
	/* 0xed8: ja     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_A, 0xed8, 0x1263, x86_l_1263);
x86_l_ede:
	/* 0xede: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_ee7:
	/* 0xee7: jne    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xee7, 0x1263, x86_l_1263);
x86_l_eed:
	/* 0xeed: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ef0:
	/* 0xef0: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_ef8:
	/* 0xef8: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_f00:
	/* 0xf00: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f05:
	/* 0xf05: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_f0d:
	/* 0xf0d: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f11:
	/* 0xf11: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f16:
	/* 0xf16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f18:
	/* 0xf18: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_f1c:
	/* 0xf1c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f20:
	/* 0xf20: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_f23:
	/* 0xf23: jne    1192 <generic_uprobe_actions+0x1192> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf23, 0x1192, x86_l_1192);
x86_l_f29:
	/* 0xf29: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_f2d:
	/* 0xf2d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_f31:
	/* 0xf31: ja     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf31, 0x1263, x86_l_1263);
x86_l_f37:
	/* 0xf37: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_f40:
	/* 0xf40: jne    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf40, 0x1263, x86_l_1263);
x86_l_f46:
	/* 0xf46: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f49:
	/* 0xf49: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_f51:
	/* 0xf51: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_f56:
	/* 0xf56: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f5a:
	/* 0xf5a: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f61:
	/* 0xf61: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_f66:
	/* 0xf66: and    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_f6e:
	/* 0xf6e: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_f71:
	/* 0xf71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f76:
	/* 0xf76: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_f79:
	/* 0xf79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7b:
	/* 0xf7b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f80:
	/* 0xf80: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_f87:
	/* 0xf87: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f8a:
	/* 0xf8a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f8d:
	/* 0xf8d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8f:
	/* 0xf8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f91:
	/* 0xf91: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0xf91, 0x1263, x86_l_1263);
x86_l_f96:
	/* 0xf96: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f99:
	/* 0xf99: jmp    1268 <generic_uprobe_actions+0x1268> */
	X86_SIM_X86_JMP(0xf99, 0x1268, x86_l_1268);
x86_l_f9e:
	/* 0xf9e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_fa3:
	/* 0xfa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa5:
	/* 0xfa5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_faa:
	/* 0xfaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_faf:
	/* 0xfaf: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_fb6:
	/* 0xfb6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fbb:
	/* 0xfbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbd:
	/* 0xfbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc0:
	/* 0xfc0: je     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc0, 0x1263, x86_l_1263);
x86_l_fc6:
	/* 0xfc6: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fca:
	/* 0xfca: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fcf:
	/* 0xfcf: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_fd7:
	/* 0xfd7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fdc:
	/* 0xfdc: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_fe3:
	/* 0xfe3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fe8:
	/* 0xfe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fea:
	/* 0xfea: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_ff2:
	/* 0xff2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ff5:
	/* 0xff5: je     110d <generic_uprobe_actions+0x110d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff5, 0x110d, x86_l_110d);
x86_l_ffb:
	/* 0xffb: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ffe:
	/* 0xffe: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1003:
	/* 0x1003: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_100a:
	/* 0x100a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_100f:
	/* 0x100f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1011:
	/* 0x1011: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0x1011, 0x1263, x86_l_1263);
x86_l_1016:
	/* 0x1016: cmp    DWORD PTR [r12+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_101c:
	/* 0x101c: je     103d <generic_uprobe_actions+0x103d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x101c, 0x103d, x86_l_103d);
x86_l_101e:
	/* 0x101e: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_1023:
	/* 0x1023: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1028:
	/* 0x1028: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_102f:
	/* 0x102f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1034:
	/* 0x1034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1036:
	/* 0x1036: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_103d:
	/* 0x103d: cmp    DWORD PTR [r12+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_1043:
	/* 0x1043: je     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1043, 0x1263, x86_l_1263);
x86_l_1049:
	/* 0x1049: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_104e:
	/* 0x104e: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1053:
	/* 0x1053: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_105a:
	/* 0x105a: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_105f:
	/* 0x105f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1062:
	/* 0x1062: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1064:
	/* 0x1064: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_106b:
	/* 0x106b: jmp    1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JMP(0x106b, 0x1263, x86_l_1263);
x86_l_1070:
	/* 0x1070: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1075:
	/* 0x1075: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_107a:
	/* 0x107a: cmp    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_107f:
	/* 0x107f: je     123c <generic_uprobe_actions+0x123c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107f, 0x123c, x86_l_123c);
x86_l_1085:
	/* 0x1085: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_108a:
	/* 0x108a: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_108e:
	/* 0x108e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1093:
	/* 0x1093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1095:
	/* 0x1095: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_109a:
	/* 0x109a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_109f:
	/* 0x109f: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_10a6:
	/* 0x10a6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ab:
	/* 0x10ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ad:
	/* 0x10ad: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_10b0:
	/* 0x10b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b3:
	/* 0x10b3: je     10c2 <generic_uprobe_actions+0x10c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b3, 0x10c2, x86_l_10c2);
x86_l_10b5:
	/* 0x10b5: cmp    r15,0xfffffffffffff001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709547521ULL);
x86_l_10bc:
	/* 0x10bc: jb     122b <generic_uprobe_actions+0x122b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10bc, 0x122b, x86_l_122b);
x86_l_10c2:
	/* 0x10c2: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_10c5:
	/* 0x10c5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_10c7:
	/* 0x10c7: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_10ca:
	/* 0x10ca: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10cf:
	/* 0x10cf: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_10d2:
	/* 0x10d2: mov    WORD PTR [rsp],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d6:
	/* 0x10d6: mov    WORD PTR [rsp+0x2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934602ULL);
x86_l_10dd:
	/* 0x10dd: movabs rax,0x10000003a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967354ULL);
x86_l_10e7:
	/* 0x10e7: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10ec:
	/* 0x10ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10f1:
	/* 0x10f1: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_10f8:
	/* 0x10f8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_10fb:
	/* 0x10fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fd:
	/* 0x10fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1100:
	/* 0x1100: je     1206 <generic_uprobe_actions+0x1206> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1100, 0x1206, x86_l_1206);
x86_l_1106:
	/* 0x1106: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1108:
	/* 0x1108: jmp    1226 <generic_uprobe_actions+0x1226> */
	X86_SIM_X86_JMP(0x1108, 0x1226, x86_l_1226);
x86_l_110d:
	/* 0x110d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1112:
	/* 0x1112: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1119:
	/* 0x1119: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_111e:
	/* 0x111e: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1123:
	/* 0x1123: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1128:
	/* 0x1128: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112a:
	/* 0x112a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112d:
	/* 0x112d: je     ffe <generic_uprobe_actions+0xffe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112d, 0xffe, x86_l_ffe);
x86_l_1133:
	/* 0x1133: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1136:
	/* 0x1136: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1138:
	/* 0x1138: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113c:
	/* 0x113c: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_1143:
	/* 0x1143: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_114d:
	/* 0x114d: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1152:
	/* 0x1152: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1157:
	/* 0x1157: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_115e:
	/* 0x115e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1161:
	/* 0x1161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1163:
	/* 0x1163: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1166:
	/* 0x1166: je     12b1 <generic_uprobe_actions+0x12b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1166, 0x12b1, x86_l_12b1);
x86_l_116c:
	/* 0x116c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_116e:
	/* 0x116e: jmp    12d1 <generic_uprobe_actions+0x12d1> */
	X86_SIM_X86_JMP(0x116e, 0x12d1, x86_l_12d1);
x86_l_1173:
	/* 0x1173: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1178:
	/* 0x1178: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_117f:
	/* 0x117f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1184:
	/* 0x1184: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1189:
	/* 0x1189: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118b:
	/* 0x118b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118d:
	/* 0x118d: jmp    c87 <generic_uprobe_actions+0xc87> */
	X86_SIM_X86_JMP(0x118d, 0xc87, x86_l_c87);
x86_l_1192:
	/* 0x1192: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1197:
	/* 0x1197: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_119e:
	/* 0x119e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11a1:
	/* 0x11a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a3:
	/* 0x11a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a5:
	/* 0x11a5: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11aa:
	/* 0x11aa: jne    126c <generic_uprobe_actions+0x126c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11aa, 0x126c, x86_l_126c);
x86_l_11b0:
	/* 0x11b0: jmp    1268 <generic_uprobe_actions+0x1268> */
	X86_SIM_X86_JMP(0x11b0, 0x1268, x86_l_1268);
x86_l_11b5:
	/* 0x11b5: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_11bd:
	/* 0x11bd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11c2:
	/* 0x11c2: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_11c9:
	/* 0x11c9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11cc:
	/* 0x11cc: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11d1:
	/* 0x11d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d3:
	/* 0x11d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d5:
	/* 0x11d5: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_11d8:
	/* 0x11d8: je     ab9 <generic_uprobe_actions+0xab9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d8, 0xab9, x86_l_ab9);
x86_l_11de:
	/* 0x11de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e3:
	/* 0x11e3: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_11ea:
	/* 0x11ea: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ef:
	/* 0x11ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f1:
	/* 0x11f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f4:
	/* 0x11f4: je     ab9 <generic_uprobe_actions+0xab9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f4, 0xab9, x86_l_ab9);
x86_l_11fa:
	/* 0x11fa: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_11fe:
	/* 0x11fe: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1201:
	/* 0x1201: jmp    ab9 <generic_uprobe_actions+0xab9> */
	X86_SIM_X86_JMP(0x1201, 0xab9, x86_l_ab9);
x86_l_1206:
	/* 0x1206: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_120e:
	/* 0x120e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1213:
	/* 0x1213: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_121a:
	/* 0x121a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_121d:
	/* 0x121d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1222:
	/* 0x1222: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1224:
	/* 0x1224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1226:
	/* 0x1226: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1229:
	/* 0x1229: je     1295 <generic_uprobe_actions+0x1295> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1229, 0x1295, x86_l_1295);
x86_l_122b:
	/* 0x122b: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_122f:
	/* 0x122f: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1232:
	/* 0x1232: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1237:
	/* 0x1237: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_123c:
	/* 0x123c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1243:
	/* 0x1243: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1248:
	/* 0x1248: mov    rdi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_124f:
	/* 0x124f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1252:
	/* 0x1252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1254:
	/* 0x1254: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1257:
	/* 0x1257: je     1263 <generic_uprobe_actions+0x1263> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1257, 0x1263, x86_l_1263);
x86_l_1259:
	/* 0x1259: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_125e:
	/* 0x125e: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1263:
	/* 0x1263: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1268:
	/* 0x1268: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_126c:
	/* 0x126c: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_126f:
	/* 0x126f: je     1287 <generic_uprobe_actions+0x1287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x126f, 0x1287, x86_l_1287);
x86_l_1271:
	/* 0x1271: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1276:
	/* 0x1276: mov    rsi,QWORD PTR [rip+0x55b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_127d:
	/* 0x127d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1280:
	/* 0x1280: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1285:
	/* 0x1285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1287:
	/* 0x1287: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1289:
	/* 0x1289: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_128d:
	/* 0x128d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_128f:
	/* 0x128f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1290:
	/* 0x1290: jmp    1302 <generic_uprobe_actions+0x1302> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1295:
	/* 0x1295: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_129a:
	/* 0x129a: mov    rdi,QWORD PTR [rip+0x55ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_12a1:
	/* 0x12a1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12a6:
	/* 0x12a6: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12ab:
	/* 0x12ab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ad:
	/* 0x12ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12af:
	/* 0x12af: jmp    1232 <generic_uprobe_actions+0x1232> */
	X86_SIM_X86_JMP(0x12af, 0x1232, x86_l_1232);
x86_l_12b1:
	/* 0x12b1: mov    DWORD PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_12b9:
	/* 0x12b9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12be:
	/* 0x12be: mov    rdi,QWORD PTR [rip+0x55bd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_12c5:
	/* 0x12c5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12c8:
	/* 0x12c8: lea    rdx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12cd:
	/* 0x12cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12cf:
	/* 0x12cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d1:
	/* 0x12d1: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_12d4:
	/* 0x12d4: je     ffe <generic_uprobe_actions+0xffe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d4, 0xffe, x86_l_ffe);
x86_l_12da:
	/* 0x12da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12df:
	/* 0x12df: mov    rdi,QWORD PTR [rip+0x55bd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_12e6:
	/* 0x12e6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12eb:
	/* 0x12eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ed:
	/* 0x12ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f0:
	/* 0x12f0: je     ffe <generic_uprobe_actions+0xffe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f0, 0xffe, x86_l_ffe);
x86_l_12f6:
	/* 0x12f6: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_12fa:
	/* 0x12fa: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12fd:
	/* 0x12fd: jmp    ffe <generic_uprobe_actions+0xffe> */
	X86_SIM_X86_JMP(0x12fd, 0xffe, x86_l_ffe);
x86_l_1302:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
