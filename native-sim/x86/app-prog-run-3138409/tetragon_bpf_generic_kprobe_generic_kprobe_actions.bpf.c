extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char kprobe_calls;
extern char override_tasks;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char stack_trace_map;
extern char tg_errmetrics_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_kprobe_generic_kprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     110d <generic_kprobe_actions+0x110d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31, 0x110d, x86_l_110d);
x86_l_37:
	/* 0x37: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r13d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_41:
	/* 0x41: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_45:
	/* 0x45: jl     110d <generic_kprobe_actions+0x110d> */
	X86_SIM_X86_JCC(X86_CC_L, 0x45, 0x110d, x86_l_110d);
x86_l_4b:
	/* 0x4b: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_52:
	/* 0x52: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_59:
	/* 0x59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63:
	/* 0x63: je     110d <generic_kprobe_actions+0x110d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0x110d, x86_l_110d);
x86_l_69:
	/* 0x69: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_6c:
	/* 0x6c: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_72:
	/* 0x72: add    r13d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_76:
	/* 0x76: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_81:
	/* 0x81: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_88:
	/* 0x88: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_90:
	/* 0x90: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_98:
	/* 0x98: and    r13d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9f:
	/* 0x9f: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a2:
	/* 0xa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4:
	/* 0xa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: je     cd <generic_kprobe_actions+0xcd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7, 0xcd, x86_l_cd);
x86_l_a9:
	/* 0xa9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac:
	/* 0xac: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af:
	/* 0xaf: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_b3:
	/* 0xb3: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_b6:
	/* 0xb6: xor    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_ba:
	/* 0xba: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: xor    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 3ULL);
x86_l_c1:
	/* 0xc1: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c6:
	/* 0xc6: ja     e5 <generic_kprobe_actions+0xe5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc6, 0xe5, x86_l_e5);
x86_l_c8:
	/* 0xc8: jmp    10f2 <generic_kprobe_actions+0x10f2> */
	X86_SIM_X86_JMP(0xc8, 0x10f2, x86_l_10f2);
x86_l_cd:
	/* 0xcd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d2:
	/* 0xd2: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_d5:
	/* 0xd5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_da:
	/* 0xda: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_df:
	/* 0xdf: jbe    10f2 <generic_kprobe_actions+0x10f2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xdf, 0x10f2, x86_l_10f2);
x86_l_e5:
	/* 0xe5: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ea:
	/* 0xea: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ef:
	/* 0xef: movsxd rbp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_f3:
	/* 0xf3: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_fb:
	/* 0xfb: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_102:
	/* 0x102: lea    rsi,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_107:
	/* 0x107: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c:
	/* 0x10c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e:
	/* 0x10e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111:
	/* 0x111: je     148 <generic_kprobe_actions+0x148> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111, 0x148, x86_l_148);
x86_l_113:
	/* 0x113: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_116:
	/* 0x116: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_119:
	/* 0x119: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_11c:
	/* 0x11c: jg     156 <generic_kprobe_actions+0x156> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11c, 0x156, x86_l_156);
x86_l_11e:
	/* 0x11e: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_121:
	/* 0x121: jg     198 <generic_kprobe_actions+0x198> */
	X86_SIM_X86_JCC(X86_CC_G, 0x121, 0x198, x86_l_198);
x86_l_123:
	/* 0x123: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_126:
	/* 0x126: jg     22e <generic_kprobe_actions+0x22e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x126, 0x22e, x86_l_22e);
x86_l_12c:
	/* 0x12c: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_12e:
	/* 0x12e: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_130:
	/* 0x130: je     3ca <generic_kprobe_actions+0x3ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130, 0x3ca, x86_l_3ca);
x86_l_136:
	/* 0x136: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_13a:
	/* 0x13a: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_13d:
	/* 0x13d: je     246 <generic_kprobe_actions+0x246> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13d, 0x246, x86_l_246);
x86_l_143:
	/* 0x143: jmp    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JMP(0x143, 0x80c, x86_l_80c);
x86_l_148:
	/* 0x148: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b:
	/* 0x14b: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_14d:
	/* 0x14d: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_151:
	/* 0x151: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x151, 0x813, x86_l_813);
x86_l_156:
	/* 0x156: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_159:
	/* 0x159: jg     1f8 <generic_kprobe_actions+0x1f8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x159, 0x1f8, x86_l_1f8);
x86_l_15f:
	/* 0x15f: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_161:
	/* 0x161: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_165:
	/* 0x165: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_168:
	/* 0x168: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16b:
	/* 0x16b: jb     2b6 <generic_kprobe_actions+0x2b6> */
	X86_SIM_X86_JCC(X86_CC_B, 0x16b, 0x2b6, x86_l_2b6);
x86_l_171:
	/* 0x171: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_174:
	/* 0x174: je     2c1 <generic_kprobe_actions+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x174, 0x2c1, x86_l_2c1);
x86_l_17a:
	/* 0x17a: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_17d:
	/* 0x17d: jne    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17d, 0x80c, x86_l_80c);
x86_l_183:
	/* 0x183: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_188:
	/* 0x188: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_18e:
	/* 0x18e: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_193:
	/* 0x193: jmp    7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JMP(0x193, 0x7e2, x86_l_7e2);
x86_l_198:
	/* 0x198: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_19a:
	/* 0x19a: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19e:
	/* 0x19e: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1a1:
	/* 0x1a1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a4:
	/* 0x1a4: jb     2ae <generic_kprobe_actions+0x2ae> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a4, 0x2ae, x86_l_2ae);
x86_l_1aa:
	/* 0x1aa: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1ad:
	/* 0x1ad: je     2d1 <generic_kprobe_actions+0x2d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x2d1, x86_l_2d1);
x86_l_1b3:
	/* 0x1b3: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1b6:
	/* 0x1b6: jne    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b6, 0x80c, x86_l_80c);
x86_l_1bc:
	/* 0x1bc: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0:
	/* 0x1c0: mov    r15d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c4:
	/* 0x1c4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cd:
	/* 0x1cd: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d6:
	/* 0x1d6: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1d9:
	/* 0x1d9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc:
	/* 0x1dc: ja     1ed <generic_kprobe_actions+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1dc, 0x1ed, x86_l_1ed);
x86_l_1de:
	/* 0x1de: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1e7:
	/* 0x1e7: je     696 <generic_kprobe_actions+0x696> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e7, 0x696, x86_l_696);
x86_l_1ed:
	/* 0x1ed: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1f3:
	/* 0x1f3: jmp    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JMP(0x1f3, 0x80c, x86_l_80c);
x86_l_1f8:
	/* 0x1f8: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_1fb:
	/* 0x1fb: je     448 <generic_kprobe_actions+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fb, 0x448, x86_l_448);
x86_l_201:
	/* 0x201: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_203:
	/* 0x203: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_207:
	/* 0x207: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_20a:
	/* 0x20a: je     352 <generic_kprobe_actions+0x352> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20a, 0x352, x86_l_352);
x86_l_210:
	/* 0x210: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_213:
	/* 0x213: jne    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x213, 0x80c, x86_l_80c);
x86_l_219:
	/* 0x219: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e:
	/* 0x21e: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_224:
	/* 0x224: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_229:
	/* 0x229: jmp    7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JMP(0x229, 0x7e2, x86_l_7e2);
x86_l_22e:
	/* 0x22e: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_231:
	/* 0x231: je     433 <generic_kprobe_actions+0x433> */
	X86_SIM_X86_JCC(X86_CC_E, 0x231, 0x433, x86_l_433);
x86_l_237:
	/* 0x237: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_239:
	/* 0x239: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_23d:
	/* 0x23d: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_240:
	/* 0x240: jne    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x240, 0x80c, x86_l_80c);
x86_l_246:
	/* 0x246: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24b:
	/* 0x24b: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24f:
	/* 0x24f: mov    r15d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_253:
	/* 0x253: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25c:
	/* 0x25c: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_265:
	/* 0x265: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_26d:
	/* 0x26d: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_274:
	/* 0x274: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_279:
	/* 0x279: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27e:
	/* 0x27e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_280:
	/* 0x280: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283:
	/* 0x283: je     2a3 <generic_kprobe_actions+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x283, 0x2a3, x86_l_2a3);
x86_l_285:
	/* 0x285: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_289:
	/* 0x289: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_28d:
	/* 0x28d: ja     2a3 <generic_kprobe_actions+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x28d, 0x2a3, x86_l_2a3);
x86_l_28f:
	/* 0x28f: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_294:
	/* 0x294: cmp    DWORD PTR [rcx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_29d:
	/* 0x29d: je     53c <generic_kprobe_actions+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29d, 0x53c, x86_l_53c);
x86_l_2a3:
	/* 0x2a3: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_2a9:
	/* 0x2a9: jmp    807 <generic_kprobe_actions+0x807> */
	X86_SIM_X86_JMP(0x2a9, 0x807, x86_l_807);
x86_l_2ae:
	/* 0x2ae: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b2:
	/* 0x2b2: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2b6:
	/* 0x2b6: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_2bc:
	/* 0x2bc: jmp    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JMP(0x2bc, 0x80c, x86_l_80c);
x86_l_2c1:
	/* 0x2c1: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2c9:
	/* 0x2c9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cc:
	/* 0x2cc: jmp    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JMP(0x2cc, 0x80c, x86_l_80c);
x86_l_2d1:
	/* 0x2d1: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d6:
	/* 0x2d6: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_2dc:
	/* 0x2dc: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_2e2:
	/* 0x2e2: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_2e5:
	/* 0x2e5: je     7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e5, 0x7e2, x86_l_7e2);
x86_l_2eb:
	/* 0x2eb: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef:
	/* 0x2ef: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f3:
	/* 0x2f3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2f8:
	/* 0x2f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa:
	/* 0x2fa: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff:
	/* 0x2ff: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_306:
	/* 0x306: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30b:
	/* 0x30b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_310:
	/* 0x310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312:
	/* 0x312: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_315:
	/* 0x315: je     66f <generic_kprobe_actions+0x66f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x315, 0x66f, x86_l_66f);
x86_l_31b:
	/* 0x31b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_326:
	/* 0x326: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_32f:
	/* 0x32f: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_336:
	/* 0x336: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33b:
	/* 0x33b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_340:
	/* 0x340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342:
	/* 0x342: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_345:
	/* 0x345: je     7b1 <generic_kprobe_actions+0x7b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x345, 0x7b1, x86_l_7b1);
x86_l_34b:
	/* 0x34b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_34d:
	/* 0x34d: jmp    7d5 <generic_kprobe_actions+0x7d5> */
	X86_SIM_X86_JMP(0x34d, 0x7d5, x86_l_7d5);
x86_l_352:
	/* 0x352: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_357:
	/* 0x357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_359:
	/* 0x359: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35e:
	/* 0x35e: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_365:
	/* 0x365: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36a:
	/* 0x36a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36f:
	/* 0x36f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_371:
	/* 0x371: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_374:
	/* 0x374: je     80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x374, 0x80c, x86_l_80c);
x86_l_37a:
	/* 0x37a: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37e:
	/* 0x37e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_383:
	/* 0x383: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_38b:
	/* 0x38b: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_392:
	/* 0x392: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_397:
	/* 0x397: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39c:
	/* 0x39c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39e:
	/* 0x39e: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_3a6:
	/* 0x3a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a9:
	/* 0x3a9: je     604 <generic_kprobe_actions+0x604> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a9, 0x604, x86_l_604);
x86_l_3af:
	/* 0x3af: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3b2:
	/* 0x3b2: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_3b9:
	/* 0x3b9: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3be:
	/* 0x3be: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3c3:
	/* 0x3c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c5:
	/* 0x3c5: jmp    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JMP(0x3c5, 0x80c, x86_l_80c);
x86_l_3ca:
	/* 0x3ca: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3ce:
	/* 0x3ce: cmp    DWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d3:
	/* 0x3d3: je     3f6 <generic_kprobe_actions+0x3f6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d3, 0x3f6, x86_l_3f6);
x86_l_3d5:
	/* 0x3d5: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_3da:
	/* 0x3da: mov    rsi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_3e1:
	/* 0x3e1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e3:
	/* 0x3e3: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_3e8:
	/* 0x3e8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3eb:
	/* 0x3eb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ed:
	/* 0x3ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f6:
	/* 0x3f6: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3fc:
	/* 0x3fc: cmp    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_401:
	/* 0x401: je     80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x401, 0x80c, x86_l_80c);
x86_l_407:
	/* 0x407: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_40c:
	/* 0x40c: mov    rsi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_413:
	/* 0x413: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_418:
	/* 0x418: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_41d:
	/* 0x41d: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_422:
	/* 0x422: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_425:
	/* 0x425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_427:
	/* 0x427: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_42e:
	/* 0x42e: jmp    80c <generic_kprobe_actions+0x80c> */
	X86_SIM_X86_JMP(0x42e, 0x80c, x86_l_80c);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_438:
	/* 0x438: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_43a:
	/* 0x43a: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_43e:
	/* 0x43e: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_443:
	/* 0x443: jmp    7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JMP(0x443, 0x7e2, x86_l_7e2);
x86_l_448:
	/* 0x448: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_44d:
	/* 0x44d: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_44f:
	/* 0x44f: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_453:
	/* 0x453: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_459:
	/* 0x459: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_45f:
	/* 0x45f: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_462:
	/* 0x462: je     7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x462, 0x7e2, x86_l_7e2);
x86_l_468:
	/* 0x468: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46c:
	/* 0x46c: mov    esi,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_470:
	/* 0x470: mov    edx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_474:
	/* 0x474: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_478:
	/* 0x478: mov    DWORD PTR [rsp+0x50],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_47c:
	/* 0x47c: mov    DWORD PTR [rsp+0x68],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_480:
	/* 0x480: ja     495 <generic_kprobe_actions+0x495> */
	X86_SIM_X86_JCC(X86_CC_A, 0x480, 0x495, x86_l_495);
x86_l_482:
	/* 0x482: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_487:
	/* 0x487: cmp    DWORD PTR [rcx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_48f:
	/* 0x48f: je     f9d <generic_kprobe_actions+0xf9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48f, 0xf9d, x86_l_f9d);
x86_l_495:
	/* 0x495: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_498:
	/* 0x498: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49d:
	/* 0x49d: mov    eax,DWORD PTR [rax+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4a0:
	/* 0x4a0: shl    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_4a4:
	/* 0x4a4: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_4a7:
	/* 0x4a7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4ac:
	/* 0x4ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b3:
	/* 0x4b3: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4b7:
	/* 0x4b7: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4bc:
	/* 0x4bc: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c0:
	/* 0x4c0: mov    WORD PTR [rsp+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_4c5:
	/* 0x4c5: mov    QWORD PTR [rsp+0x24],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4ca:
	/* 0x4ca: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4d1:
	/* 0x4d1: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4d6:
	/* 0x4d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4db:
	/* 0x4db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dd:
	/* 0x4dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e0:
	/* 0x4e0: je     74c <generic_kprobe_actions+0x74c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e0, 0x74c, x86_l_74c);
x86_l_4e6:
	/* 0x4e6: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4e9:
	/* 0x4e9: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4f2:
	/* 0x4f2: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_4fa:
	/* 0x4fa: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_501:
	/* 0x501: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_506:
	/* 0x506: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50b:
	/* 0x50b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d:
	/* 0x50d: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_515:
	/* 0x515: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_518:
	/* 0x518: je     f11 <generic_kprobe_actions+0xf11> */
	X86_SIM_X86_JCC(X86_CC_E, 0x518, 0xf11, x86_l_f11);
x86_l_51e:
	/* 0x51e: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_521:
	/* 0x521: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_525:
	/* 0x525: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_529:
	/* 0x529: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52e:
	/* 0x52e: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_531:
	/* 0x531: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_537:
	/* 0x537: jmp    7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JMP(0x537, 0x7e2, x86_l_7e2);
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_541:
	/* 0x541: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_546:
	/* 0x546: mov    rax,QWORD PTR [rcx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_54e:
	/* 0x54e: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_551:
	/* 0x551: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_559:
	/* 0x559: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_55e:
	/* 0x55e: mov    eax,DWORD PTR [rcx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_565:
	/* 0x565: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_569:
	/* 0x569: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_56e:
	/* 0x56e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_570:
	/* 0x570: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_574:
	/* 0x574: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_579:
	/* 0x579: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_57c:
	/* 0x57c: jne    db4 <generic_kprobe_actions+0xdb4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57c, 0xdb4, x86_l_db4);
x86_l_582:
	/* 0x582: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_586:
	/* 0x586: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_58a:
	/* 0x58a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_58f:
	/* 0x58f: ja     2a3 <generic_kprobe_actions+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x58f, 0x2a3, x86_l_2a3);
x86_l_595:
	/* 0x595: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_59a:
	/* 0x59a: cmp    DWORD PTR [rcx+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_5a3:
	/* 0x5a3: jne    2a3 <generic_kprobe_actions+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a3, 0x2a3, x86_l_2a3);
x86_l_5a9:
	/* 0x5a9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5ae:
	/* 0x5ae: mov    rcx,QWORD PTR [rsi+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_5b6:
	/* 0x5b6: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_5bc:
	/* 0x5bc: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5c0:
	/* 0x5c0: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_5c7:
	/* 0x5c7: mov    esi,DWORD PTR [rsi+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_5ce:
	/* 0x5ce: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d4:
	/* 0x5d4: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d8:
	/* 0x5d8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5db:
	/* 0x5db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e0:
	/* 0x5e0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5e3:
	/* 0x5e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e5:
	/* 0x5e5: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_5ec:
	/* 0x5ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ee:
	/* 0x5ee: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f3:
	/* 0x5f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5f8:
	/* 0x5f8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5fb:
	/* 0x5fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fd:
	/* 0x5fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ff:
	/* 0x5ff: jmp    2a3 <generic_kprobe_actions+0x2a3> */
	X86_SIM_X86_JMP(0x5ff, 0x2a3, x86_l_2a3);
x86_l_604:
	/* 0x604: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_60b:
	/* 0x60b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_610:
	/* 0x610: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_615:
	/* 0x615: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_61a:
	/* 0x61a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_61f:
	/* 0x61f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_621:
	/* 0x621: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_624:
	/* 0x624: je     3b2 <generic_kprobe_actions+0x3b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x624, 0x3b2, x86_l_3b2);
x86_l_62a:
	/* 0x62a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_62f:
	/* 0x62f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_631:
	/* 0x631: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_636:
	/* 0x636: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_63d:
	/* 0x63d: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_647:
	/* 0x647: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_64c:
	/* 0x64c: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_653:
	/* 0x653: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_658:
	/* 0x658: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65d:
	/* 0x65d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65f:
	/* 0x65f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_662:
	/* 0x662: je     16b7 <generic_kprobe_actions+0x16b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x662, 0x16b7, x86_l_16b7);
x86_l_668:
	/* 0x668: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_66a:
	/* 0x66a: jmp    16db <generic_kprobe_actions+0x16db> */
	X86_SIM_X86_JMP(0x66a, 0x16db, x86_l_16db);
x86_l_66f:
	/* 0x66f: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_676:
	/* 0x676: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_678:
	/* 0x678: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67d:
	/* 0x67d: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_682:
	/* 0x682: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_687:
	/* 0x687: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_689:
	/* 0x689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68b:
	/* 0x68b: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_691:
	/* 0x691: jmp    7e2 <generic_kprobe_actions+0x7e2> */
	X86_SIM_X86_JMP(0x691, 0x7e2, x86_l_7e2);
x86_l_696:
	/* 0x696: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_69e:
	/* 0x69e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6a3:
	/* 0x6a3: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_6ab:
	/* 0x6ab: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6af:
	/* 0x6af: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6b4:
	/* 0x6b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b6:
	/* 0x6b6: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6ba:
	/* 0x6ba: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6bf:
	/* 0x6bf: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6c6:
	/* 0x6c6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6cb:
	/* 0x6cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d0:
	/* 0x6d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d2:
	/* 0x6d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6d5:
	/* 0x6d5: je     1ed <generic_kprobe_actions+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d5, 0x1ed, x86_l_1ed);
x86_l_6db:
	/* 0x6db: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6df:
	/* 0x6df: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_6e3:
	/* 0x6e3: ja     1ed <generic_kprobe_actions+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6e3, 0x1ed, x86_l_1ed);
x86_l_6e9:
	/* 0x6e9: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_6f2:
	/* 0x6f2: jne    1ed <generic_kprobe_actions+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6f2, 0x1ed, x86_l_1ed);
x86_l_6f8:
	/* 0x6f8: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_700:
	/* 0x700: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_708:
	/* 0x708: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_70e:
	/* 0x70e: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_716:
	/* 0x716: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71a:
	/* 0x71a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_71d:
	/* 0x71d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_722:
	/* 0x722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_724:
	/* 0x724: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_728:
	/* 0x728: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72d:
	/* 0x72d: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_734:
	/* 0x734: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_736:
	/* 0x736: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73b:
	/* 0x73b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_740:
	/* 0x740: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_743:
	/* 0x743: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_745:
	/* 0x745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_747:
	/* 0x747: jmp    1ed <generic_kprobe_actions+0x1ed> */
	X86_SIM_X86_JMP(0x747, 0x1ed, x86_l_1ed);
x86_l_74c:
	/* 0x74c: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_753:
	/* 0x753: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_755:
	/* 0x755: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_75a:
	/* 0x75a: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_75f:
	/* 0x75f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_764:
	/* 0x764: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_766:
	/* 0x766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_768:
	/* 0x768: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76b:
	/* 0x76b: je     531 <generic_kprobe_actions+0x531> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76b, 0x531, x86_l_531);
x86_l_771:
	/* 0x771: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_773:
	/* 0x773: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_778:
	/* 0x778: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_77f:
	/* 0x77f: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_789:
	/* 0x789: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_78e:
	/* 0x78e: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_795:
	/* 0x795: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_79a:
	/* 0x79a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_79f:
	/* 0x79f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a1:
	/* 0x7a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7a4:
	/* 0x7a4: je     17ae <generic_kprobe_actions+0x17ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a4, 0x17ae, x86_l_17ae);
x86_l_7aa:
	/* 0x7aa: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7ac:
	/* 0x7ac: jmp    531 <generic_kprobe_actions+0x531> */
	X86_SIM_X86_JMP(0x7ac, 0x531, x86_l_531);
x86_l_7b1:
	/* 0x7b1: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_7b9:
	/* 0x7b9: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7c0:
	/* 0x7c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c2:
	/* 0x7c2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c7:
	/* 0x7c7: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7cc:
	/* 0x7cc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7d1:
	/* 0x7d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d3:
	/* 0x7d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d5:
	/* 0x7d5: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7d9:
	/* 0x7d9: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7dc:
	/* 0x7dc: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_7e2:
	/* 0x7e2: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_7ea:
	/* 0x7ea: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_7f1:
	/* 0x7f1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7f6:
	/* 0x7f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7fb:
	/* 0x7fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fd:
	/* 0x7fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_800:
	/* 0x800: je     807 <generic_kprobe_actions+0x807> */
	X86_SIM_X86_JCC(X86_CC_E, 0x800, 0x807, x86_l_807);
x86_l_802:
	/* 0x802: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_807:
	/* 0x807: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_80c:
	/* 0x80c: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_810:
	/* 0x810: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_813:
	/* 0x813: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_81b:
	/* 0x81b: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_81f:
	/* 0x81f: jae    10ea <generic_kprobe_actions+0x10ea> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x81f, 0x10ea, x86_l_10ea);
x86_l_825:
	/* 0x825: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82a:
	/* 0x82a: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_82d:
	/* 0x82d: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_830:
	/* 0x830: mov    r14d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_32);
x86_l_833:
	/* 0x833: movsxd r15,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_838:
	/* 0x838: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_840:
	/* 0x840: mov    rdi,QWORD PTR [rip+0x58d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_847:
	/* 0x847: lea    rsi,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_84c:
	/* 0x84c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_851:
	/* 0x851: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_853:
	/* 0x853: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_855:
	/* 0x855: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_858:
	/* 0x858: je     899 <generic_kprobe_actions+0x899> */
	X86_SIM_X86_JCC(X86_CC_E, 0x858, 0x899, x86_l_899);
x86_l_85a:
	/* 0x85a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_861:
	/* 0x861: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_864:
	/* 0x864: jg     8a6 <generic_kprobe_actions+0x8a6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x864, 0x8a6, x86_l_8a6);
x86_l_866:
	/* 0x866: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_869:
	/* 0x869: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_86c:
	/* 0x86c: jg     8ef <generic_kprobe_actions+0x8ef> */
	X86_SIM_X86_JCC(X86_CC_G, 0x86c, 0x8ef, x86_l_8ef);
x86_l_872:
	/* 0x872: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_875:
	/* 0x875: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_878:
	/* 0x878: jg     a56 <generic_kprobe_actions+0xa56> */
	X86_SIM_X86_JCC(X86_CC_G, 0x878, 0xa56, x86_l_a56);
x86_l_87e:
	/* 0x87e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_880:
	/* 0x880: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_885:
	/* 0x885: je     c27 <generic_kprobe_actions+0xc27> */
	X86_SIM_X86_JCC(X86_CC_E, 0x885, 0xc27, x86_l_c27);
x86_l_88b:
	/* 0x88b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_88e:
	/* 0x88e: je     a6d <generic_kprobe_actions+0xa6d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88e, 0xa6d, x86_l_a6d);
x86_l_894:
	/* 0x894: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0x894, 0x107b, x86_l_107b);
x86_l_899:
	/* 0x899: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_89c:
	/* 0x89c: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a1:
	/* 0x8a1: jmp    1085 <generic_kprobe_actions+0x1085> */
	X86_SIM_X86_JMP(0x8a1, 0x1085, x86_l_1085);
x86_l_8a6:
	/* 0x8a6: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_8a9:
	/* 0x8a9: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_8ac:
	/* 0x8ac: jg     a1b <generic_kprobe_actions+0xa1b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8ac, 0xa1b, x86_l_a1b);
x86_l_8b2:
	/* 0x8b2: lea    eax,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_8b5:
	/* 0x8b5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8b8:
	/* 0x8b8: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_8bb:
	/* 0x8bb: jb     aed <generic_kprobe_actions+0xaed> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8bb, 0xaed, x86_l_aed);
x86_l_8c1:
	/* 0x8c1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8c4:
	/* 0x8c4: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8c9:
	/* 0x8c9: je     b0f <generic_kprobe_actions+0xb0f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c9, 0xb0f, x86_l_b0f);
x86_l_8cf:
	/* 0x8cf: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_8d2:
	/* 0x8d2: jne    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8d2, 0x107b, x86_l_107b);
x86_l_8d8:
	/* 0x8d8: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8dd:
	/* 0x8dd: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e2:
	/* 0x8e2: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_8e5:
	/* 0x8e5: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8ea:
	/* 0x8ea: jmp    104c <generic_kprobe_actions+0x104c> */
	X86_SIM_X86_JMP(0x8ea, 0x104c, x86_l_104c);
x86_l_8ef:
	/* 0x8ef: lea    eax,[rcx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_8f2:
	/* 0x8f2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8f5:
	/* 0x8f5: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_8f8:
	/* 0x8f8: jb     afa <generic_kprobe_actions+0xafa> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8f8, 0xafa, x86_l_afa);
x86_l_8fe:
	/* 0x8fe: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_901:
	/* 0x901: je     b1c <generic_kprobe_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x901, 0xb1c, x86_l_b1c);
x86_l_907:
	/* 0x907: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_90a:
	/* 0x90a: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_90f:
	/* 0x90f: jne    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x90f, 0x107b, x86_l_107b);
x86_l_915:
	/* 0x915: mov    eax,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_91a:
	/* 0x91a: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_91e:
	/* 0x91e: mov    r14d,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_923:
	/* 0x923: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_92c:
	/* 0x92c: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_935:
	/* 0x935: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_938:
	/* 0x938: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_93b:
	/* 0x93b: ja     107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x93b, 0x107b, x86_l_107b);
x86_l_941:
	/* 0x941: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_949:
	/* 0x949: jne    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x949, 0x107b, x86_l_107b);
x86_l_94f:
	/* 0x94f: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_957:
	/* 0x957: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_95c:
	/* 0x95c: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_963:
	/* 0x963: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_967:
	/* 0x967: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_96c:
	/* 0x96c: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_971:
	/* 0x971: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_974:
	/* 0x974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_976:
	/* 0x976: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_97a:
	/* 0x97a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_97f:
	/* 0x97f: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_986:
	/* 0x986: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_98b:
	/* 0x98b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_990:
	/* 0x990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_992:
	/* 0x992: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_995:
	/* 0x995: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_99a:
	/* 0x99a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99d:
	/* 0x99d: je     107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99d, 0x107b, x86_l_107b);
x86_l_9a3:
	/* 0x9a3: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_9a7:
	/* 0x9a7: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_9ab:
	/* 0x9ab: ja     107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9ab, 0x107b, x86_l_107b);
x86_l_9b1:
	/* 0x9b1: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_9ba:
	/* 0x9ba: jne    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9ba, 0x107b, x86_l_107b);
x86_l_9c0:
	/* 0x9c0: mov    rcx,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_9c8:
	/* 0x9c8: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_9d0:
	/* 0x9d0: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9d6:
	/* 0x9d6: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_9dd:
	/* 0x9dd: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e1:
	/* 0x9e1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_9e4:
	/* 0x9e4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9e9:
	/* 0x9e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9eb:
	/* 0x9eb: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_9ef:
	/* 0x9ef: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f4:
	/* 0x9f4: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9fb:
	/* 0x9fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9fd:
	/* 0x9fd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a02:
	/* 0xa02: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a07:
	/* 0xa07: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_a0a:
	/* 0xa0a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0c:
	/* 0xa0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0e:
	/* 0xa0e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a11:
	/* 0xa11: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a16:
	/* 0xa16: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xa16, 0x107b, x86_l_107b);
x86_l_a1b:
	/* 0xa1b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_a1e:
	/* 0xa1e: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_a21:
	/* 0xa21: je     cc2 <generic_kprobe_actions+0xcc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa21, 0xcc2, x86_l_cc2);
x86_l_a27:
	/* 0xa27: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_a2a:
	/* 0xa2a: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a2f:
	/* 0xa2f: je     ba7 <generic_kprobe_actions+0xba7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2f, 0xba7, x86_l_ba7);
x86_l_a35:
	/* 0xa35: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_a38:
	/* 0xa38: jne    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa38, 0x107b, x86_l_107b);
x86_l_a3e:
	/* 0xa3e: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a43:
	/* 0xa43: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a48:
	/* 0xa48: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_a4c:
	/* 0xa4c: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a51:
	/* 0xa51: jmp    104c <generic_kprobe_actions+0x104c> */
	X86_SIM_X86_JMP(0xa51, 0x104c, x86_l_104c);
x86_l_a56:
	/* 0xa56: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a59:
	/* 0xa59: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a5e:
	/* 0xa5e: je     cae <generic_kprobe_actions+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5e, 0xcae, x86_l_cae);
x86_l_a64:
	/* 0xa64: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a67:
	/* 0xa67: jne    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa67, 0x107b, x86_l_107b);
x86_l_a6d:
	/* 0xa6d: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a72:
	/* 0xa72: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a77:
	/* 0xa77: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_a7c:
	/* 0xa7c: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_a80:
	/* 0xa80: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_a85:
	/* 0xa85: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a8d:
	/* 0xa8d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a96:
	/* 0xa96: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a9f:
	/* 0xa9f: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_aa7:
	/* 0xaa7: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_aae:
	/* 0xaae: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_ab1:
	/* 0xab1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ab6:
	/* 0xab6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_abb:
	/* 0xabb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abd:
	/* 0xabd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ac0:
	/* 0xac0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: je     ade <generic_kprobe_actions+0xade> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac3, 0xade, x86_l_ade);
x86_l_ac5:
	/* 0xac5: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ac9:
	/* 0xac9: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_acd:
	/* 0xacd: ja     ade <generic_kprobe_actions+0xade> */
	X86_SIM_X86_JCC(X86_CC_A, 0xacd, 0xade, x86_l_ade);
x86_l_acf:
	/* 0xacf: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_ad8:
	/* 0xad8: je     ddd <generic_kprobe_actions+0xddd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad8, 0xddd, x86_l_ddd);
x86_l_ade:
	/* 0xade: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ae3:
	/* 0xae3: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ae8:
	/* 0xae8: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xae8, 0x107b, x86_l_107b);
x86_l_aed:
	/* 0xaed: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_af0:
	/* 0xaf0: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_af5:
	/* 0xaf5: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xaf5, 0x107b, x86_l_107b);
x86_l_afa:
	/* 0xafa: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_afd:
	/* 0xafd: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_b02:
	/* 0xb02: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b05:
	/* 0xb05: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b0a:
	/* 0xb0a: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xb0a, 0x107b, x86_l_107b);
x86_l_b0f:
	/* 0xb0f: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_b17:
	/* 0xb17: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xb17, 0x107b, x86_l_107b);
x86_l_b1c:
	/* 0xb1c: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b21:
	/* 0xb21: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b26:
	/* 0xb26: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b29:
	/* 0xb29: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_b2e:
	/* 0xb2e: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_b31:
	/* 0xb31: je     daa <generic_kprobe_actions+0xdaa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb31, 0xdaa, x86_l_daa);
x86_l_b37:
	/* 0xb37: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_b3a:
	/* 0xb3a: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_b3f:
	/* 0xb3f: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b43:
	/* 0xb43: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_b48:
	/* 0xb48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4a:
	/* 0xb4a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b4f:
	/* 0xb4f: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_b56:
	/* 0xb56: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5b:
	/* 0xb5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b60:
	/* 0xb60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b62:
	/* 0xb62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b65:
	/* 0xb65: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b6a:
	/* 0xb6a: je     f7c <generic_kprobe_actions+0xf7c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6a, 0xf7c, x86_l_f7c);
x86_l_b70:
	/* 0xb70: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_b73:
	/* 0xb73: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_b7b:
	/* 0xb7b: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_b84:
	/* 0xb84: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b8b:
	/* 0xb8b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b90:
	/* 0xb90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b95:
	/* 0xb95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b97:
	/* 0xb97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9a:
	/* 0xb9a: je     101c <generic_kprobe_actions+0x101c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9a, 0x101c, x86_l_101c);
x86_l_ba0:
	/* 0xba0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ba2:
	/* 0xba2: jmp    1040 <generic_kprobe_actions+0x1040> */
	X86_SIM_X86_JMP(0xba2, 0x1040, x86_l_1040);
x86_l_ba7:
	/* 0xba7: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_baa:
	/* 0xbaa: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_bad:
	/* 0xbad: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_bb2:
	/* 0xbb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb4:
	/* 0xbb4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bb9:
	/* 0xbb9: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_bc0:
	/* 0xbc0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bc5:
	/* 0xbc5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bca:
	/* 0xbca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcc:
	/* 0xbcc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bcf:
	/* 0xbcf: je     c1c <generic_kprobe_actions+0xc1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbcf, 0xc1c, x86_l_c1c);
x86_l_bd1:
	/* 0xbd1: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bd5:
	/* 0xbd5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bda:
	/* 0xbda: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_be2:
	/* 0xbe2: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_be9:
	/* 0xbe9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bee:
	/* 0xbee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf3:
	/* 0xbf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf5:
	/* 0xbf5: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_bfd:
	/* 0xbfd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c00:
	/* 0xc00: je     ea6 <generic_kprobe_actions+0xea6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc00, 0xea6, x86_l_ea6);
x86_l_c06:
	/* 0xc06: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c09:
	/* 0xc09: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_c10:
	/* 0xc10: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c15:
	/* 0xc15: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c1a:
	/* 0xc1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1c:
	/* 0xc1c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_c1f:
	/* 0xc1f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_c22:
	/* 0xc22: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xc22, 0x107b, x86_l_107b);
x86_l_c27:
	/* 0xc27: cmp    DWORD PTR [r13+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_c2d:
	/* 0xc2d: je     c61 <generic_kprobe_actions+0xc61> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2d, 0xc61, x86_l_c61);
x86_l_c2f:
	/* 0xc2f: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_c33:
	/* 0xc33: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_c36:
	/* 0xc36: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c39:
	/* 0xc39: mov    rsi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c40:
	/* 0xc40: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c45:
	/* 0xc45: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c4a:
	/* 0xc4a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c4d:
	/* 0xc4d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4f:
	/* 0xc4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c51:
	/* 0xc51: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c54:
	/* 0xc54: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_c57:
	/* 0xc57: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_c5a:
	/* 0xc5a: mov    QWORD PTR [rdx+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c61:
	/* 0xc61: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_c65:
	/* 0xc65: cmp    DWORD PTR [r13+r15*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 17179869184ULL);
x86_l_c6b:
	/* 0xc6b: je     107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc6b, 0x107b, x86_l_107b);
x86_l_c71:
	/* 0xc71: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c75:
	/* 0xc75: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_c78:
	/* 0xc78: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c7b:
	/* 0xc7b: mov    rsi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c82:
	/* 0xc82: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_c85:
	/* 0xc85: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_c8a:
	/* 0xc8a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c8f:
	/* 0xc8f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c94:
	/* 0xc94: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c97:
	/* 0xc97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c99:
	/* 0xc99: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c9c:
	/* 0xc9c: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_c9f:
	/* 0xc9f: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rdx+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ca9:
	/* 0xca9: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0xca9, 0x107b, x86_l_107b);
x86_l_cae:
	/* 0xcae: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cb3:
	/* 0xcb3: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cb8:
	/* 0xcb8: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cbd:
	/* 0xcbd: jmp    104c <generic_kprobe_actions+0x104c> */
	X86_SIM_X86_JMP(0xcbd, 0x104c, x86_l_104c);
x86_l_cc2:
	/* 0xcc2: add    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_cc6:
	/* 0xcc6: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_ccb:
	/* 0xccb: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_cce:
	/* 0xcce: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cd3:
	/* 0xcd3: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cd8:
	/* 0xcd8: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cdd:
	/* 0xcdd: je     104c <generic_kprobe_actions+0x104c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcdd, 0x104c, x86_l_104c);
x86_l_ce3:
	/* 0xce3: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_ce6:
	/* 0xce6: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_ceb:
	/* 0xceb: mov    esi,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_cf0:
	/* 0xcf0: mov    ebp,DWORD PTR [r13+r14*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 12ULL);
x86_l_cf5:
	/* 0xcf5: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_cf9:
	/* 0xcf9: mov    DWORD PTR [rsp+0x70],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cfd:
	/* 0xcfd: ja     d0d <generic_kprobe_actions+0xd0d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcfd, 0xd0d, x86_l_d0d);
x86_l_cff:
	/* 0xcff: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_d07:
	/* 0xd07: je     1794 <generic_kprobe_actions+0x1794> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd07, 0x1794, x86_l_1794);
x86_l_d0d:
	/* 0xd0d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d10:
	/* 0xd10: mov    eax,DWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d13:
	/* 0xd13: shl    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_d17:
	/* 0xd17: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d1a:
	/* 0xd1a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d1f:
	/* 0xd1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d21:
	/* 0xd21: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d26:
	/* 0xd26: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d2a:
	/* 0xd2a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d2f:
	/* 0xd2f: mov    WORD PTR [rsp+0x22],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_d34:
	/* 0xd34: mov    QWORD PTR [rsp+0x24],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d39:
	/* 0xd39: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_d40:
	/* 0xd40: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d45:
	/* 0xd45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d4a:
	/* 0xd4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4c:
	/* 0xd4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4f:
	/* 0xd4f: je     fb7 <generic_kprobe_actions+0xfb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4f, 0xfb7, x86_l_fb7);
x86_l_d55:
	/* 0xd55: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d58:
	/* 0xd58: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d5c:
	/* 0xd5c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d61:
	/* 0xd61: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_d69:
	/* 0xd69: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d70:
	/* 0xd70: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d75:
	/* 0xd75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d7a:
	/* 0xd7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7c:
	/* 0xd7c: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_d84:
	/* 0xd84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d87:
	/* 0xd87: je     164e <generic_kprobe_actions+0x164e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd87, 0x164e, x86_l_164e);
x86_l_d8d:
	/* 0xd8d: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d90:
	/* 0xd90: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d94:
	/* 0xd94: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d98:
	/* 0xd98: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9d:
	/* 0xd9d: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da0:
	/* 0xda0: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_da5:
	/* 0xda5: jmp    104c <generic_kprobe_actions+0x104c> */
	X86_SIM_X86_JMP(0xda5, 0x104c, x86_l_104c);
x86_l_daa:
	/* 0xdaa: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_daf:
	/* 0xdaf: jmp    104c <generic_kprobe_actions+0x104c> */
	X86_SIM_X86_JMP(0xdaf, 0x104c, x86_l_104c);
x86_l_db4:
	/* 0xdb4: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_dbb:
	/* 0xdbb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc0:
	/* 0xdc0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_dc5:
	/* 0xdc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc7:
	/* 0xdc7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dca:
	/* 0xdca: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_dcc:
	/* 0xdcc: mov    DWORD PTR [rsp+0x1c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_dd0:
	/* 0xdd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd2:
	/* 0xdd2: jne    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdd2, 0x813, x86_l_813);
x86_l_dd8:
	/* 0xdd8: jmp    1ed <generic_kprobe_actions+0x1ed> */
	X86_SIM_X86_JMP(0xdd8, 0x1ed, x86_l_1ed);
x86_l_ddd:
	/* 0xddd: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_de5:
	/* 0xde5: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_ded:
	/* 0xded: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_df5:
	/* 0xdf5: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_dfa:
	/* 0xdfa: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_e01:
	/* 0xe01: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e05:
	/* 0xe05: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e0a:
	/* 0xe0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0c:
	/* 0xe0c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e10:
	/* 0xe10: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e15:
	/* 0xe15: cmp    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_e1a:
	/* 0xe1a: jne    1621 <generic_kprobe_actions+0x1621> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1a, 0x1621, x86_l_1621);
x86_l_e20:
	/* 0xe20: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e28:
	/* 0xe28: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e2b:
	/* 0xe2b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e2e:
	/* 0xe2e: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e36:
	/* 0xe36: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e39:
	/* 0xe39: ja     ade <generic_kprobe_actions+0xade> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe39, 0xade, x86_l_ade);
x86_l_e3f:
	/* 0xe3f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e42:
	/* 0xe42: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_e4a:
	/* 0xe4a: jne    ade <generic_kprobe_actions+0xade> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe4a, 0xade, x86_l_ade);
x86_l_e50:
	/* 0xe50: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_e58:
	/* 0xe58: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e5e:
	/* 0xe5e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e61:
	/* 0xe61: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_e68:
	/* 0xe68: mov    esi,DWORD PTR [r12+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e70:
	/* 0xe70: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e76:
	/* 0xe76: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e7a:
	/* 0xe7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e7f:
	/* 0xe7f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e82:
	/* 0xe82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e84:
	/* 0xe84: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e8b:
	/* 0xe8b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8d:
	/* 0xe8d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e92:
	/* 0xe92: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e97:
	/* 0xe97: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e9a:
	/* 0xe9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9c:
	/* 0xe9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9e:
	/* 0xe9e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ea1:
	/* 0xea1: jmp    ade <generic_kprobe_actions+0xade> */
	X86_SIM_X86_JMP(0xea1, 0xade, x86_l_ade);
x86_l_ea6:
	/* 0xea6: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_ead:
	/* 0xead: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eb2:
	/* 0xeb2: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_eb7:
	/* 0xeb7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ebc:
	/* 0xebc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ec1:
	/* 0xec1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec3:
	/* 0xec3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec6:
	/* 0xec6: je     c09 <generic_kprobe_actions+0xc09> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec6, 0xc09, x86_l_c09);
x86_l_ecc:
	/* 0xecc: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ed1:
	/* 0xed1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ed3:
	/* 0xed3: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed8:
	/* 0xed8: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_edf:
	/* 0xedf: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_ee9:
	/* 0xee9: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eee:
	/* 0xeee: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ef5:
	/* 0xef5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_efa:
	/* 0xefa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eff:
	/* 0xeff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f01:
	/* 0xf01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f04:
	/* 0xf04: je     18cd <generic_kprobe_actions+0x18cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf04, 0x18cd, x86_l_18cd);
x86_l_f0a:
	/* 0xf0a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f0c:
	/* 0xf0c: jmp    18f1 <generic_kprobe_actions+0x18f1> */
	X86_SIM_X86_JMP(0xf0c, 0x18f1, x86_l_18f1);
x86_l_f11:
	/* 0xf11: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_f18:
	/* 0xf18: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f1d:
	/* 0xf1d: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f22:
	/* 0xf22: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f27:
	/* 0xf27: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f2c:
	/* 0xf2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2e:
	/* 0xf2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f31:
	/* 0xf31: je     521 <generic_kprobe_actions+0x521> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf31, 0x521, x86_l_521);
x86_l_f37:
	/* 0xf37: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f3c:
	/* 0xf3c: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_f3e:
	/* 0xf3e: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f43:
	/* 0xf43: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_f4a:
	/* 0xf4a: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_f54:
	/* 0xf54: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f59:
	/* 0xf59: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f60:
	/* 0xf60: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f65:
	/* 0xf65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f6a:
	/* 0xf6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6c:
	/* 0xf6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f6f:
	/* 0xf6f: je     1924 <generic_kprobe_actions+0x1924> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6f, 0x1924, x86_l_1924);
x86_l_f75:
	/* 0xf75: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f77:
	/* 0xf77: jmp    1948 <generic_kprobe_actions+0x1948> */
	X86_SIM_X86_JMP(0xf77, 0x1948, x86_l_1948);
x86_l_f7c:
	/* 0xf7c: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_f83:
	/* 0xf83: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f85:
	/* 0xf85: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8a:
	/* 0xf8a: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f8f:
	/* 0xf8f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f94:
	/* 0xf94: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f96:
	/* 0xf96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f98:
	/* 0xf98: jmp    1047 <generic_kprobe_actions+0x1047> */
	X86_SIM_X86_JMP(0xf98, 0x1047, x86_l_1047);
x86_l_f9d:
	/* 0xf9d: mov    rax,QWORD PTR [rcx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_fa5:
	/* 0xfa5: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_faa:
	/* 0xfaa: mov    r14,QWORD PTR [rcx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_fb2:
	/* 0xfb2: jmp    498 <generic_kprobe_actions+0x498> */
	X86_SIM_X86_JMP(0xfb2, 0x498, x86_l_498);
x86_l_fb7:
	/* 0xfb7: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_fbe:
	/* 0xfbe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc0:
	/* 0xfc0: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fc5:
	/* 0xfc5: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fca:
	/* 0xfca: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fcf:
	/* 0xfcf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd1:
	/* 0xfd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd3:
	/* 0xfd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd6:
	/* 0xfd6: je     da0 <generic_kprobe_actions+0xda0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd6, 0xda0, x86_l_da0);
x86_l_fdc:
	/* 0xfdc: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_fde:
	/* 0xfde: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe3:
	/* 0xfe3: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_fea:
	/* 0xfea: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_ff4:
	/* 0xff4: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ff9:
	/* 0xff9: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1000:
	/* 0x1000: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1005:
	/* 0x1005: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_100a:
	/* 0x100a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100c:
	/* 0x100c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_100f:
	/* 0x100f: je     1999 <generic_kprobe_actions+0x1999> */
	X86_SIM_X86_JCC(X86_CC_E, 0x100f, 0x1999, x86_l_1999);
x86_l_1015:
	/* 0x1015: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1017:
	/* 0x1017: jmp    da0 <generic_kprobe_actions+0xda0> */
	X86_SIM_X86_JMP(0x1017, 0xda0, x86_l_da0);
x86_l_101c:
	/* 0x101c: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1024:
	/* 0x1024: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_102b:
	/* 0x102b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_102d:
	/* 0x102d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1032:
	/* 0x1032: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1037:
	/* 0x1037: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_103c:
	/* 0x103c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_103e:
	/* 0x103e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1040:
	/* 0x1040: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1044:
	/* 0x1044: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1047:
	/* 0x1047: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_104c:
	/* 0x104c: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1054:
	/* 0x1054: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_105b:
	/* 0x105b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1060:
	/* 0x1060: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1065:
	/* 0x1065: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1067:
	/* 0x1067: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_106a:
	/* 0x106a: je     1071 <generic_kprobe_actions+0x1071> */
	X86_SIM_X86_JCC(X86_CC_E, 0x106a, 0x1071, x86_l_1071);
x86_l_106c:
	/* 0x106c: inc QWORD PTR [rax+rbp*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBP, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1071:
	/* 0x1071: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1076:
	/* 0x1076: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_107b:
	/* 0x107b: mov    QWORD PTR [rdx+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_107f:
	/* 0x107f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1082:
	/* 0x1082: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_1085:
	/* 0x1085: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_108c:
	/* 0x108c: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1090:
	/* 0x1090: jae    10ea <generic_kprobe_actions+0x10ea> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1090, 0x10ea, x86_l_10ea);
x86_l_1092:
	/* 0x1092: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1095:
	/* 0x1095: movsxd rbp,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_109a:
	/* 0x109a: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_10a2:
	/* 0x10a2: mov    rdi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_10a9:
	/* 0x10a9: lea    rsi,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_10ae:
	/* 0x10ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10b3:
	/* 0x10b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b5:
	/* 0x10b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b8:
	/* 0x10b8: je     10ea <generic_kprobe_actions+0x10ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b8, 0x10ea, x86_l_10ea);
x86_l_10ba:
	/* 0x10ba: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10bd:
	/* 0x10bd: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_10c0:
	/* 0x10c0: jle    111e <generic_kprobe_actions+0x111e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x10c0, 0x111e, x86_l_111e);
x86_l_10c2:
	/* 0x10c2: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_10c5:
	/* 0x10c5: jg     1142 <generic_kprobe_actions+0x1142> */
	X86_SIM_X86_JCC(X86_CC_G, 0x10c5, 0x1142, x86_l_1142);
x86_l_10c7:
	/* 0x10c7: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_10ca:
	/* 0x10ca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10cd:
	/* 0x10cd: jb     1274 <generic_kprobe_actions+0x1274> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10cd, 0x1274, x86_l_1274);
x86_l_10d3:
	/* 0x10d3: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_10d6:
	/* 0x10d6: je     138f <generic_kprobe_actions+0x138f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d6, 0x138f, x86_l_138f);
x86_l_10dc:
	/* 0x10dc: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_10df:
	/* 0x10df: je     1896 <generic_kprobe_actions+0x1896> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10df, 0x1896, x86_l_1896);
x86_l_10e5:
	/* 0x10e5: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x10e5, 0x18c0, x86_l_18c0);
x86_l_10ea:
	/* 0x10ea: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10ee:
	/* 0x10ee: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_10f0:
	/* 0x10f0: je     110d <generic_kprobe_actions+0x110d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f0, 0x110d, x86_l_110d);
x86_l_10f2:
	/* 0x10f2: mov    rsi,QWORD PTR [rip+0x58d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_10f9:
	/* 0x10f9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_10fe:
	/* 0x10fe: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1103:
	/* 0x1103: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1106:
	/* 0x1106: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_110b:
	/* 0x110b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110d:
	/* 0x110d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110f:
	/* 0x110f: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1116:
	/* 0x1116: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1118:
	/* 0x1118: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1119:
	/* 0x1119: jmp    1aee <generic_kprobe_actions+0x1aee> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_111e:
	/* 0x111e: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1121:
	/* 0x1121: jg     116c <generic_kprobe_actions+0x116c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1121, 0x116c, x86_l_116c);
x86_l_1123:
	/* 0x1123: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1125:
	/* 0x1125: je     14dc <generic_kprobe_actions+0x14dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1125, 0x14dc, x86_l_14dc);
x86_l_112b:
	/* 0x112b: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_112e:
	/* 0x112e: je     1282 <generic_kprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112e, 0x1282, x86_l_1282);
x86_l_1134:
	/* 0x1134: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1137:
	/* 0x1137: je     1896 <generic_kprobe_actions+0x1896> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1137, 0x1896, x86_l_1896);
x86_l_113d:
	/* 0x113d: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x113d, 0x18c0, x86_l_18c0);
x86_l_1142:
	/* 0x1142: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_1145:
	/* 0x1145: je     1396 <generic_kprobe_actions+0x1396> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1145, 0x1396, x86_l_1396);
x86_l_114b:
	/* 0x114b: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_114e:
	/* 0x114e: je     1464 <generic_kprobe_actions+0x1464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x114e, 0x1464, x86_l_1464);
x86_l_1154:
	/* 0x1154: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1159:
	/* 0x1159: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_115e:
	/* 0x115e: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_1161:
	/* 0x1161: je     1896 <generic_kprobe_actions+0x1896> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1161, 0x1896, x86_l_1896);
x86_l_1167:
	/* 0x1167: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x1167, 0x18c0, x86_l_18c0);
x86_l_116c:
	/* 0x116c: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_116f:
	/* 0x116f: je     1282 <generic_kprobe_actions+0x1282> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116f, 0x1282, x86_l_1282);
x86_l_1175:
	/* 0x1175: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1178:
	/* 0x1178: je     153d <generic_kprobe_actions+0x153d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1178, 0x153d, x86_l_153d);
x86_l_117e:
	/* 0x117e: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1181:
	/* 0x1181: jne    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1181, 0x18c0, x86_l_18c0);
x86_l_1187:
	/* 0x1187: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_118c:
	/* 0x118c: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_1191:
	/* 0x1191: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_119a:
	/* 0x119a: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_11a3:
	/* 0x11a3: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11a6:
	/* 0x11a6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a9:
	/* 0x11a9: ja     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11a9, 0x18c0, x86_l_18c0);
x86_l_11af:
	/* 0x11af: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_11b8:
	/* 0x11b8: jne    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b8, 0x18c0, x86_l_18c0);
x86_l_11be:
	/* 0x11be: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_11c6:
	/* 0x11c6: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_11cb:
	/* 0x11cb: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_11d3:
	/* 0x11d3: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d7:
	/* 0x11d7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_11dc:
	/* 0x11dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11de:
	/* 0x11de: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11e2:
	/* 0x11e2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e7:
	/* 0x11e7: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_11ee:
	/* 0x11ee: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f3:
	/* 0x11f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11f8:
	/* 0x11f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fa:
	/* 0x11fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11fd:
	/* 0x11fd: je     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11fd, 0x18c0, x86_l_18c0);
x86_l_1203:
	/* 0x1203: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1207:
	/* 0x1207: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_120b:
	/* 0x120b: ja     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x120b, 0x18c0, x86_l_18c0);
x86_l_1211:
	/* 0x1211: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_121a:
	/* 0x121a: jne    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x121a, 0x18c0, x86_l_18c0);
x86_l_1220:
	/* 0x1220: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_1228:
	/* 0x1228: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1230:
	/* 0x1230: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1236:
	/* 0x1236: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_123e:
	/* 0x123e: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1242:
	/* 0x1242: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1245:
	/* 0x1245: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_124a:
	/* 0x124a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124c:
	/* 0x124c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1250:
	/* 0x1250: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1255:
	/* 0x1255: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_125c:
	/* 0x125c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125e:
	/* 0x125e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1263:
	/* 0x1263: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1268:
	/* 0x1268: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_126b:
	/* 0x126b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_126d:
	/* 0x126d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126f:
	/* 0x126f: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x126f, 0x18c0, x86_l_18c0);
x86_l_1274:
	/* 0x1274: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_1279:
	/* 0x1279: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_127d:
	/* 0x127d: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x127d, 0x18c0, x86_l_18c0);
x86_l_1282:
	/* 0x1282: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_1287:
	/* 0x1287: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_128c:
	/* 0x128c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1295:
	/* 0x1295: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_129e:
	/* 0x129e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_12a6:
	/* 0x12a6: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_12ad:
	/* 0x12ad: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b2:
	/* 0x12b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12b7:
	/* 0x12b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b9:
	/* 0x12b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12bc:
	/* 0x12bc: je     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12bc, 0x18c0, x86_l_18c0);
x86_l_12c2:
	/* 0x12c2: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_12c6:
	/* 0x12c6: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_12ca:
	/* 0x12ca: ja     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x12ca, 0x18c0, x86_l_18c0);
x86_l_12d0:
	/* 0x12d0: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_12d9:
	/* 0x12d9: jne    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12d9, 0x18c0, x86_l_18c0);
x86_l_12df:
	/* 0x12df: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_12e2:
	/* 0x12e2: mov    rax,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_12ea:
	/* 0x12ea: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_12f2:
	/* 0x12f2: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_12f7:
	/* 0x12f7: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_12ff:
	/* 0x12ff: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1303:
	/* 0x1303: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1308:
	/* 0x1308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130a:
	/* 0x130a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_130e:
	/* 0x130e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1313:
	/* 0x1313: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1316:
	/* 0x1316: jne    1840 <generic_kprobe_actions+0x1840> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1316, 0x1840, x86_l_1840);
x86_l_131c:
	/* 0x131c: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1320:
	/* 0x1320: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1324:
	/* 0x1324: ja     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1324, 0x18c0, x86_l_18c0);
x86_l_132a:
	/* 0x132a: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_1333:
	/* 0x1333: jne    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1333, 0x18c0, x86_l_18c0);
x86_l_1339:
	/* 0x1339: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_1341:
	/* 0x1341: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1346:
	/* 0x1346: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_134a:
	/* 0x134a: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1351:
	/* 0x1351: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1359:
	/* 0x1359: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_135f:
	/* 0x135f: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1363:
	/* 0x1363: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_1366:
	/* 0x1366: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_136b:
	/* 0x136b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_136e:
	/* 0x136e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1370:
	/* 0x1370: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1377:
	/* 0x1377: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1379:
	/* 0x1379: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_137e:
	/* 0x137e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1383:
	/* 0x1383: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1386:
	/* 0x1386: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1388:
	/* 0x1388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138a:
	/* 0x138a: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x138a, 0x18c0, x86_l_18c0);
x86_l_138f:
	/* 0x138f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1391:
	/* 0x1391: jmp    18c4 <generic_kprobe_actions+0x18c4> */
	X86_SIM_X86_JMP(0x1391, 0x18c4, x86_l_18c4);
x86_l_1396:
	/* 0x1396: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_139b:
	/* 0x139b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13a0:
	/* 0x13a0: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_13a3:
	/* 0x13a3: je     1896 <generic_kprobe_actions+0x1896> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a3, 0x1896, x86_l_1896);
x86_l_13a9:
	/* 0x13a9: mov    eax,DWORD PTR [r13+r15*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 16ULL);
x86_l_13ae:
	/* 0x13ae: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_13b3:
	/* 0x13b3: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_13b8:
	/* 0x13b8: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_13bc:
	/* 0x13bc: ja     13cd <generic_kprobe_actions+0x13cd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13bc, 0x13cd, x86_l_13cd);
x86_l_13be:
	/* 0x13be: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_13c7:
	/* 0x13c7: je     197b <generic_kprobe_actions+0x197b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c7, 0x197b, x86_l_197b);
x86_l_13cd:
	/* 0x13cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13cf:
	/* 0x13cf: mov    r13d,DWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13d3:
	/* 0x13d3: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13d6:
	/* 0x13d6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13e2:
	/* 0x13e2: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13e8:
	/* 0x13e8: mov    WORD PTR [rsp+0x22],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_13ee:
	/* 0x13ee: mov    QWORD PTR [rsp+0x24],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13f3:
	/* 0x13f3: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_13fa:
	/* 0x13fa: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13ff:
	/* 0x13ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1404:
	/* 0x1404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1406:
	/* 0x1406: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1409:
	/* 0x1409: je     170e <generic_kprobe_actions+0x170e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1409, 0x170e, x86_l_170e);
x86_l_140f:
	/* 0x140f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1412:
	/* 0x1412: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1416:
	/* 0x1416: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_141b:
	/* 0x141b: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_1423:
	/* 0x1423: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_142a:
	/* 0x142a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1434:
	/* 0x1434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1436:
	/* 0x1436: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_143e:
	/* 0x143e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1441:
	/* 0x1441: je     17d7 <generic_kprobe_actions+0x17d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1441, 0x17d7, x86_l_17d7);
x86_l_1447:
	/* 0x1447: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_144a:
	/* 0x144a: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_144e:
	/* 0x144e: mov    DWORD PTR [r15+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1452:
	/* 0x1452: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1457:
	/* 0x1457: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_145a:
	/* 0x145a: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_145f:
	/* 0x145f: jmp    1891 <generic_kprobe_actions+0x1891> */
	X86_SIM_X86_JMP(0x145f, 0x1891, x86_l_1891);
x86_l_1464:
	/* 0x1464: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1469:
	/* 0x1469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146b:
	/* 0x146b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1470:
	/* 0x1470: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1477:
	/* 0x1477: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_147c:
	/* 0x147c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1481:
	/* 0x1481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1483:
	/* 0x1483: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1486:
	/* 0x1486: je     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1486, 0x18c0, x86_l_18c0);
x86_l_148c:
	/* 0x148c: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1490:
	/* 0x1490: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1495:
	/* 0x1495: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_149d:
	/* 0x149d: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_14a4:
	/* 0x14a4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14a9:
	/* 0x14a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ae:
	/* 0x14ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b0:
	/* 0x14b0: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_14b8:
	/* 0x14b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: je     15b8 <generic_kprobe_actions+0x15b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14bb, 0x15b8, x86_l_15b8);
x86_l_14c1:
	/* 0x14c1: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14c4:
	/* 0x14c4: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_14cb:
	/* 0x14cb: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14d0:
	/* 0x14d0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14d5:
	/* 0x14d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d7:
	/* 0x14d7: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x14d7, 0x18c0, x86_l_18c0);
x86_l_14dc:
	/* 0x14dc: cmp    DWORD PTR [r13+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_14e2:
	/* 0x14e2: je     1505 <generic_kprobe_actions+0x1505> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e2, 0x1505, x86_l_1505);
x86_l_14e4:
	/* 0x14e4: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_14e9:
	/* 0x14e9: mov    rsi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_14f0:
	/* 0x14f0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f2:
	/* 0x14f2: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_14f7:
	/* 0x14f7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14fa:
	/* 0x14fa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14fc:
	/* 0x14fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fe:
	/* 0x14fe: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1505:
	/* 0x1505: cmp    DWORD PTR [r13+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_150b:
	/* 0x150b: je     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x150b, 0x18c0, x86_l_18c0);
x86_l_1511:
	/* 0x1511: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_1516:
	/* 0x1516: mov    rsi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_151d:
	/* 0x151d: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1522:
	/* 0x1522: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1527:
	/* 0x1527: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_152c:
	/* 0x152c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_152f:
	/* 0x152f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1531:
	/* 0x1531: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1538:
	/* 0x1538: jmp    18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JMP(0x1538, 0x18c0, x86_l_18c0);
x86_l_153d:
	/* 0x153d: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1542:
	/* 0x1542: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1547:
	/* 0x1547: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_154a:
	/* 0x154a: je     1896 <generic_kprobe_actions+0x1896> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154a, 0x1896, x86_l_1896);
x86_l_1550:
	/* 0x1550: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_1555:
	/* 0x1555: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1559:
	/* 0x1559: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_155e:
	/* 0x155e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1560:
	/* 0x1560: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1565:
	/* 0x1565: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_156c:
	/* 0x156c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1571:
	/* 0x1571: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1576:
	/* 0x1576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1578:
	/* 0x1578: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_157b:
	/* 0x157b: je     1773 <generic_kprobe_actions+0x1773> */
	X86_SIM_X86_JCC(X86_CC_E, 0x157b, 0x1773, x86_l_1773);
x86_l_1581:
	/* 0x1581: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1584:
	/* 0x1584: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_158c:
	/* 0x158c: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_1595:
	/* 0x1595: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_159c:
	/* 0x159c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a1:
	/* 0x15a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a6:
	/* 0x15a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a8:
	/* 0x15a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15ab:
	/* 0x15ab: je     1861 <generic_kprobe_actions+0x1861> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ab, 0x1861, x86_l_1861);
x86_l_15b1:
	/* 0x15b1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_15b3:
	/* 0x15b3: jmp    1885 <generic_kprobe_actions+0x1885> */
	X86_SIM_X86_JMP(0x15b3, 0x1885, x86_l_1885);
x86_l_15b8:
	/* 0x15b8: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_15bf:
	/* 0x15bf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c4:
	/* 0x15c4: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15c9:
	/* 0x15c9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15ce:
	/* 0x15ce: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15d3:
	/* 0x15d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d5:
	/* 0x15d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d8:
	/* 0x15d8: je     14c4 <generic_kprobe_actions+0x14c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d8, 0x14c4, x86_l_14c4);
x86_l_15de:
	/* 0x15de: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15e1:
	/* 0x15e1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15e3:
	/* 0x15e3: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e8:
	/* 0x15e8: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_15ef:
	/* 0x15ef: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_15f9:
	/* 0x15f9: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15fe:
	/* 0x15fe: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1605:
	/* 0x1605: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_160a:
	/* 0x160a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_160f:
	/* 0x160f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1611:
	/* 0x1611: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1614:
	/* 0x1614: je     19c2 <generic_kprobe_actions+0x19c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1614, 0x19c2, x86_l_19c2);
x86_l_161a:
	/* 0x161a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_161c:
	/* 0x161c: jmp    19e6 <generic_kprobe_actions+0x19e6> */
	X86_SIM_X86_JMP(0x161c, 0x19e6, x86_l_19e6);
x86_l_1621:
	/* 0x1621: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1628:
	/* 0x1628: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162d:
	/* 0x162d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1632:
	/* 0x1632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1634:
	/* 0x1634: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1636:
	/* 0x1636: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_163b:
	/* 0x163b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_163e:
	/* 0x163e: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1643:
	/* 0x1643: jne    1085 <generic_kprobe_actions+0x1085> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1643, 0x1085, x86_l_1085);
x86_l_1649:
	/* 0x1649: jmp    107b <generic_kprobe_actions+0x107b> */
	X86_SIM_X86_JMP(0x1649, 0x107b, x86_l_107b);
x86_l_164e:
	/* 0x164e: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1655:
	/* 0x1655: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_165a:
	/* 0x165a: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_165f:
	/* 0x165f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1664:
	/* 0x1664: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1669:
	/* 0x1669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166b:
	/* 0x166b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166e:
	/* 0x166e: je     d90 <generic_kprobe_actions+0xd90> */
	X86_SIM_X86_JCC(X86_CC_E, 0x166e, 0xd90, x86_l_d90);
x86_l_1674:
	/* 0x1674: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1677:
	/* 0x1677: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1679:
	/* 0x1679: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_167e:
	/* 0x167e: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_1685:
	/* 0x1685: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_168f:
	/* 0x168f: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1694:
	/* 0x1694: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_169b:
	/* 0x169b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a0:
	/* 0x16a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16a5:
	/* 0x16a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a7:
	/* 0x16a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16aa:
	/* 0x16aa: je     1a17 <generic_kprobe_actions+0x1a17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16aa, 0x1a17, x86_l_1a17);
x86_l_16b0:
	/* 0x16b0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16b2:
	/* 0x16b2: jmp    1a3b <generic_kprobe_actions+0x1a3b> */
	X86_SIM_X86_JMP(0x16b2, 0x1a3b, x86_l_1a3b);
x86_l_16b7:
	/* 0x16b7: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_16bf:
	/* 0x16bf: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16c6:
	/* 0x16c6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c8:
	/* 0x16c8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cd:
	/* 0x16cd: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16d2:
	/* 0x16d2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16d7:
	/* 0x16d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16d9:
	/* 0x16d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16db:
	/* 0x16db: cmp    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_16e0:
	/* 0x16e0: je     3b2 <generic_kprobe_actions+0x3b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e0, 0x3b2, x86_l_3b2);
x86_l_16e6:
	/* 0x16e6: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_16ed:
	/* 0x16ed: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16f2:
	/* 0x16f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16f7:
	/* 0x16f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f9:
	/* 0x16f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16fc:
	/* 0x16fc: je     3b2 <generic_kprobe_actions+0x3b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fc, 0x3b2, x86_l_3b2);
x86_l_1702:
	/* 0x1702: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1706:
	/* 0x1706: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1709:
	/* 0x1709: jmp    3b2 <generic_kprobe_actions+0x3b2> */
	X86_SIM_X86_JMP(0x1709, 0x3b2, x86_l_3b2);
x86_l_170e:
	/* 0x170e: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1715:
	/* 0x1715: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1717:
	/* 0x1717: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_171c:
	/* 0x171c: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1721:
	/* 0x1721: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1726:
	/* 0x1726: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1728:
	/* 0x1728: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172a:
	/* 0x172a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_172d:
	/* 0x172d: je     145a <generic_kprobe_actions+0x145a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172d, 0x145a, x86_l_145a);
x86_l_1733:
	/* 0x1733: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1735:
	/* 0x1735: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_173a:
	/* 0x173a: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_1741:
	/* 0x1741: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_174b:
	/* 0x174b: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1750:
	/* 0x1750: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1757:
	/* 0x1757: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_175c:
	/* 0x175c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1761:
	/* 0x1761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1763:
	/* 0x1763: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1766:
	/* 0x1766: je     1a6b <generic_kprobe_actions+0x1a6b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1766, 0x1a6b, x86_l_1a6b);
x86_l_176c:
	/* 0x176c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_176e:
	/* 0x176e: jmp    145a <generic_kprobe_actions+0x145a> */
	X86_SIM_X86_JMP(0x176e, 0x145a, x86_l_145a);
x86_l_1773:
	/* 0x1773: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_177a:
	/* 0x177a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_177c:
	/* 0x177c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1781:
	/* 0x1781: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1786:
	/* 0x1786: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_178b:
	/* 0x178b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178d:
	/* 0x178d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178f:
	/* 0x178f: jmp    188c <generic_kprobe_actions+0x188c> */
	X86_SIM_X86_JMP(0x178f, 0x188c, x86_l_188c);
x86_l_1794:
	/* 0x1794: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_179c:
	/* 0x179c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_17a1:
	/* 0x17a1: mov    r14,QWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_17a9:
	/* 0x17a9: jmp    d10 <generic_kprobe_actions+0xd10> */
	X86_SIM_X86_JMP(0x17a9, 0xd10, x86_l_d10);
x86_l_17ae:
	/* 0x17ae: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_17b6:
	/* 0x17b6: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_17bd:
	/* 0x17bd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17bf:
	/* 0x17bf: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c4:
	/* 0x17c4: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17c9:
	/* 0x17c9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17ce:
	/* 0x17ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d0:
	/* 0x17d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d2:
	/* 0x17d2: jmp    531 <generic_kprobe_actions+0x531> */
	X86_SIM_X86_JMP(0x17d2, 0x531, x86_l_531);
x86_l_17d7:
	/* 0x17d7: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_17de:
	/* 0x17de: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17e3:
	/* 0x17e3: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17e8:
	/* 0x17e8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17ed:
	/* 0x17ed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17f2:
	/* 0x17f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f4:
	/* 0x17f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f7:
	/* 0x17f7: je     144a <generic_kprobe_actions+0x144a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17f7, 0x144a, x86_l_144a);
x86_l_17fd:
	/* 0x17fd: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1800:
	/* 0x1800: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1802:
	/* 0x1802: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1807:
	/* 0x1807: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_180e:
	/* 0x180e: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_1818:
	/* 0x1818: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_181d:
	/* 0x181d: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1824:
	/* 0x1824: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1829:
	/* 0x1829: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_182e:
	/* 0x182e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1830:
	/* 0x1830: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1833:
	/* 0x1833: je     1a94 <generic_kprobe_actions+0x1a94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1833, 0x1a94, x86_l_1a94);
x86_l_1839:
	/* 0x1839: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_183b:
	/* 0x183b: jmp    1ab8 <generic_kprobe_actions+0x1ab8> */
	X86_SIM_X86_JMP(0x183b, 0x1ab8, x86_l_1ab8);
x86_l_1840:
	/* 0x1840: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1847:
	/* 0x1847: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_184c:
	/* 0x184c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1851:
	/* 0x1851: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1853:
	/* 0x1853: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1855:
	/* 0x1855: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1859:
	/* 0x1859: jne    10ee <generic_kprobe_actions+0x10ee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1859, 0x10ee, x86_l_10ee);
x86_l_185f:
	/* 0x185f: jmp    18c4 <generic_kprobe_actions+0x18c4> */
	X86_SIM_X86_JMP(0x185f, 0x18c4, x86_l_18c4);
x86_l_1861:
	/* 0x1861: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1869:
	/* 0x1869: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1870:
	/* 0x1870: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1872:
	/* 0x1872: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1877:
	/* 0x1877: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_187c:
	/* 0x187c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1881:
	/* 0x1881: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1883:
	/* 0x1883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1885:
	/* 0x1885: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1889:
	/* 0x1889: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188c:
	/* 0x188c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1891:
	/* 0x1891: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1896:
	/* 0x1896: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_189e:
	/* 0x189e: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_18a5:
	/* 0x18a5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18aa:
	/* 0x18aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18af:
	/* 0x18af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b1:
	/* 0x18b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b4:
	/* 0x18b4: je     18c0 <generic_kprobe_actions+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18b4, 0x18c0, x86_l_18c0);
x86_l_18b6:
	/* 0x18b6: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18bb:
	/* 0x18bb: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_18c0:
	/* 0x18c0: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18c4:
	/* 0x18c4: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18c8:
	/* 0x18c8: jmp    10ee <generic_kprobe_actions+0x10ee> */
	X86_SIM_X86_JMP(0x18c8, 0x10ee, x86_l_10ee);
x86_l_18cd:
	/* 0x18cd: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_18d5:
	/* 0x18d5: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_18dc:
	/* 0x18dc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18de:
	/* 0x18de: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e3:
	/* 0x18e3: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18e8:
	/* 0x18e8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18ed:
	/* 0x18ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ef:
	/* 0x18ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f1:
	/* 0x18f1: cmp    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_18f6:
	/* 0x18f6: je     c09 <generic_kprobe_actions+0xc09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18f6, 0xc09, x86_l_c09);
x86_l_18fc:
	/* 0x18fc: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1903:
	/* 0x1903: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1908:
	/* 0x1908: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_190d:
	/* 0x190d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190f:
	/* 0x190f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1912:
	/* 0x1912: je     c09 <generic_kprobe_actions+0xc09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1912, 0xc09, x86_l_c09);
x86_l_1918:
	/* 0x1918: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_191c:
	/* 0x191c: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_191f:
	/* 0x191f: jmp    c09 <generic_kprobe_actions+0xc09> */
	X86_SIM_X86_JMP(0x191f, 0xc09, x86_l_c09);
x86_l_1924:
	/* 0x1924: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_192c:
	/* 0x192c: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1933:
	/* 0x1933: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1935:
	/* 0x1935: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193a:
	/* 0x193a: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_193f:
	/* 0x193f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1944:
	/* 0x1944: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1946:
	/* 0x1946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1948:
	/* 0x1948: cmp    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_194d:
	/* 0x194d: je     521 <generic_kprobe_actions+0x521> */
	X86_SIM_X86_JCC(X86_CC_E, 0x194d, 0x521, x86_l_521);
x86_l_1953:
	/* 0x1953: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_195a:
	/* 0x195a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_195f:
	/* 0x195f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1964:
	/* 0x1964: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1966:
	/* 0x1966: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1969:
	/* 0x1969: je     521 <generic_kprobe_actions+0x521> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1969, 0x521, x86_l_521);
x86_l_196f:
	/* 0x196f: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1973:
	/* 0x1973: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1976:
	/* 0x1976: jmp    521 <generic_kprobe_actions+0x521> */
	X86_SIM_X86_JMP(0x1976, 0x521, x86_l_521);
x86_l_197b:
	/* 0x197b: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1983:
	/* 0x1983: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1988:
	/* 0x1988: mov    rax,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1990:
	/* 0x1990: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1994:
	/* 0x1994: jmp    13cf <generic_kprobe_actions+0x13cf> */
	X86_SIM_X86_JMP(0x1994, 0x13cf, x86_l_13cf);
x86_l_1999:
	/* 0x1999: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_19a1:
	/* 0x19a1: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19a8:
	/* 0x19a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19aa:
	/* 0x19aa: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19af:
	/* 0x19af: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19b4:
	/* 0x19b4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19b9:
	/* 0x19b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19bb:
	/* 0x19bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bd:
	/* 0x19bd: jmp    da0 <generic_kprobe_actions+0xda0> */
	X86_SIM_X86_JMP(0x19bd, 0xda0, x86_l_da0);
x86_l_19c2:
	/* 0x19c2: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_19ca:
	/* 0x19ca: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19d1:
	/* 0x19d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d3:
	/* 0x19d3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d8:
	/* 0x19d8: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19dd:
	/* 0x19dd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19e2:
	/* 0x19e2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e4:
	/* 0x19e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e6:
	/* 0x19e6: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_19e9:
	/* 0x19e9: je     14c4 <generic_kprobe_actions+0x14c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19e9, 0x14c4, x86_l_14c4);
x86_l_19ef:
	/* 0x19ef: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_19f6:
	/* 0x19f6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19fb:
	/* 0x19fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a00:
	/* 0x1a00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a02:
	/* 0x1a02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a05:
	/* 0x1a05: je     14c4 <generic_kprobe_actions+0x14c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a05, 0x14c4, x86_l_14c4);
x86_l_1a0b:
	/* 0x1a0b: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a0f:
	/* 0x1a0f: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a12:
	/* 0x1a12: jmp    14c4 <generic_kprobe_actions+0x14c4> */
	X86_SIM_X86_JMP(0x1a12, 0x14c4, x86_l_14c4);
x86_l_1a17:
	/* 0x1a17: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a26:
	/* 0x1a26: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a28:
	/* 0x1a28: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2d:
	/* 0x1a2d: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a37:
	/* 0x1a37: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a39:
	/* 0x1a39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3b:
	/* 0x1a3b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1a3d:
	/* 0x1a3d: je     d90 <generic_kprobe_actions+0xd90> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3d, 0xd90, x86_l_d90);
x86_l_1a43:
	/* 0x1a43: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1a4a:
	/* 0x1a4a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a54:
	/* 0x1a54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a56:
	/* 0x1a56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a59:
	/* 0x1a59: je     d90 <generic_kprobe_actions+0xd90> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a59, 0xd90, x86_l_d90);
x86_l_1a5f:
	/* 0x1a5f: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a63:
	/* 0x1a63: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a66:
	/* 0x1a66: jmp    d90 <generic_kprobe_actions+0xd90> */
	X86_SIM_X86_JMP(0x1a66, 0xd90, x86_l_d90);
x86_l_1a6b:
	/* 0x1a6b: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1a73:
	/* 0x1a73: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a7a:
	/* 0x1a7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a7c:
	/* 0x1a7c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a81:
	/* 0x1a81: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a86:
	/* 0x1a86: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a8b:
	/* 0x1a8b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8d:
	/* 0x1a8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8f:
	/* 0x1a8f: jmp    145a <generic_kprobe_actions+0x145a> */
	X86_SIM_X86_JMP(0x1a8f, 0x145a, x86_l_145a);
x86_l_1a94:
	/* 0x1a94: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1aa3:
	/* 0x1aa3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa5:
	/* 0x1aa5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aaa:
	/* 0x1aaa: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ab4:
	/* 0x1ab4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab6:
	/* 0x1ab6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab8:
	/* 0x1ab8: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1abb:
	/* 0x1abb: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac0:
	/* 0x1ac0: je     144a <generic_kprobe_actions+0x144a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ac0, 0x144a, x86_l_144a);
x86_l_1ac6:
	/* 0x1ac6: mov    rdi,QWORD PTR [rip+0x58d6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1acd:
	/* 0x1acd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ad7:
	/* 0x1ad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad9:
	/* 0x1ad9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1adc:
	/* 0x1adc: je     144a <generic_kprobe_actions+0x144a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1adc, 0x144a, x86_l_144a);
x86_l_1ae2:
	/* 0x1ae2: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ae6:
	/* 0x1ae6: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1ae9:
	/* 0x1ae9: jmp    144a <generic_kprobe_actions+0x144a> */
	X86_SIM_X86_JMP(0x1ae9, 0x144a, x86_l_144a);
x86_l_1aee:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
