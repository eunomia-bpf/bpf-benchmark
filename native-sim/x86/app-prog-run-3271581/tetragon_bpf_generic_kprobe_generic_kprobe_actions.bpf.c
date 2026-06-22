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
	/* 0xa: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     1118 <generic_kprobe_actions+0x1118> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0x1118, x86_l_1118);
x86_l_3e:
	/* 0x3e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    r13d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_48:
	/* 0x48: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_4c:
	/* 0x4c: jl     1118 <generic_kprobe_actions+0x1118> */
	X86_SIM_X86_JCC(X86_CC_L, 0x4c, 0x1118, x86_l_1118);
x86_l_52:
	/* 0x52: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_59:
	/* 0x59: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_60:
	/* 0x60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65:
	/* 0x65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67:
	/* 0x67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: je     1118 <generic_kprobe_actions+0x1118> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0x1118, x86_l_1118);
x86_l_70:
	/* 0x70: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_73:
	/* 0x73: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_79:
	/* 0x79: add    r13d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7d:
	/* 0x7d: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_88:
	/* 0x88: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8f:
	/* 0x8f: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_97:
	/* 0x97: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f:
	/* 0x9f: and    r13d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a6:
	/* 0xa6: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a9:
	/* 0xa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab:
	/* 0xab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae:
	/* 0xae: je     d4 <generic_kprobe_actions+0xd4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae, 0xd4, x86_l_d4);
x86_l_b0:
	/* 0xb0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3:
	/* 0xb3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6:
	/* 0xb6: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_ba:
	/* 0xba: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: xor    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_c1:
	/* 0xc1: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: xor    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 3ULL);
x86_l_c8:
	/* 0xc8: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cd:
	/* 0xcd: ja     ec <generic_kprobe_actions+0xec> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcd, 0xec, x86_l_ec);
x86_l_cf:
	/* 0xcf: jmp    10fd <generic_kprobe_actions+0x10fd> */
	X86_SIM_X86_JMP(0xcf, 0x10fd, x86_l_10fd);
x86_l_d4:
	/* 0xd4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d9:
	/* 0xd9: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_dc:
	/* 0xdc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e1:
	/* 0xe1: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e6:
	/* 0xe6: jbe    10fd <generic_kprobe_actions+0x10fd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe6, 0x10fd, x86_l_10fd);
x86_l_ec:
	/* 0xec: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f1:
	/* 0xf1: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f6:
	/* 0xf6: movsxd rbp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_102:
	/* 0x102: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_109:
	/* 0x109: lea    rsi,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_10e:
	/* 0x10e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_113:
	/* 0x113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115:
	/* 0x115: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118:
	/* 0x118: je     14f <generic_kprobe_actions+0x14f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118, 0x14f, x86_l_14f);
x86_l_11a:
	/* 0x11a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_11d:
	/* 0x11d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120:
	/* 0x120: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_123:
	/* 0x123: jg     15d <generic_kprobe_actions+0x15d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x123, 0x15d, x86_l_15d);
x86_l_125:
	/* 0x125: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_128:
	/* 0x128: jg     19f <generic_kprobe_actions+0x19f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x128, 0x19f, x86_l_19f);
x86_l_12a:
	/* 0x12a: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_12d:
	/* 0x12d: jg     235 <generic_kprobe_actions+0x235> */
	X86_SIM_X86_JCC(X86_CC_G, 0x12d, 0x235, x86_l_235);
x86_l_133:
	/* 0x133: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_135:
	/* 0x135: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_137:
	/* 0x137: je     3d1 <generic_kprobe_actions+0x3d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137, 0x3d1, x86_l_3d1);
x86_l_13d:
	/* 0x13d: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_141:
	/* 0x141: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_144:
	/* 0x144: je     24d <generic_kprobe_actions+0x24d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x144, 0x24d, x86_l_24d);
x86_l_14a:
	/* 0x14a: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x14a, 0x813, x86_l_813);
x86_l_14f:
	/* 0x14f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_152:
	/* 0x152: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_154:
	/* 0x154: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_158:
	/* 0x158: jmp    81a <generic_kprobe_actions+0x81a> */
	X86_SIM_X86_JMP(0x158, 0x81a, x86_l_81a);
x86_l_15d:
	/* 0x15d: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_160:
	/* 0x160: jg     1ff <generic_kprobe_actions+0x1ff> */
	X86_SIM_X86_JCC(X86_CC_G, 0x160, 0x1ff, x86_l_1ff);
x86_l_166:
	/* 0x166: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_168:
	/* 0x168: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_16c:
	/* 0x16c: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_16f:
	/* 0x16f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_172:
	/* 0x172: jb     2bd <generic_kprobe_actions+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_B, 0x172, 0x2bd, x86_l_2bd);
x86_l_178:
	/* 0x178: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_17b:
	/* 0x17b: je     2c8 <generic_kprobe_actions+0x2c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b, 0x2c8, x86_l_2c8);
x86_l_181:
	/* 0x181: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_184:
	/* 0x184: jne    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x184, 0x813, x86_l_813);
x86_l_18a:
	/* 0x18a: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18f:
	/* 0x18f: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_195:
	/* 0x195: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19a:
	/* 0x19a: jmp    7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JMP(0x19a, 0x7e9, x86_l_7e9);
x86_l_19f:
	/* 0x19f: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1a1:
	/* 0x1a1: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a5:
	/* 0x1a5: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1a8:
	/* 0x1a8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ab:
	/* 0x1ab: jb     2b5 <generic_kprobe_actions+0x2b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ab, 0x2b5, x86_l_2b5);
x86_l_1b1:
	/* 0x1b1: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1b4:
	/* 0x1b4: je     2d8 <generic_kprobe_actions+0x2d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4, 0x2d8, x86_l_2d8);
x86_l_1ba:
	/* 0x1ba: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1bd:
	/* 0x1bd: jne    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bd, 0x813, x86_l_813);
x86_l_1c3:
	/* 0x1c3: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7:
	/* 0x1c7: mov    r15d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1cb:
	/* 0x1cb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d4:
	/* 0x1d4: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1dd:
	/* 0x1dd: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1e0:
	/* 0x1e0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e3:
	/* 0x1e3: ja     1f4 <generic_kprobe_actions+0x1f4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1e3, 0x1f4, x86_l_1f4);
x86_l_1e5:
	/* 0x1e5: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1ee:
	/* 0x1ee: je     69d <generic_kprobe_actions+0x69d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ee, 0x69d, x86_l_69d);
x86_l_1f4:
	/* 0x1f4: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1fa:
	/* 0x1fa: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x1fa, 0x813, x86_l_813);
x86_l_1ff:
	/* 0x1ff: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_202:
	/* 0x202: je     44f <generic_kprobe_actions+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x202, 0x44f, x86_l_44f);
x86_l_208:
	/* 0x208: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_20a:
	/* 0x20a: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20e:
	/* 0x20e: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_211:
	/* 0x211: je     359 <generic_kprobe_actions+0x359> */
	X86_SIM_X86_JCC(X86_CC_E, 0x211, 0x359, x86_l_359);
x86_l_217:
	/* 0x217: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_21a:
	/* 0x21a: jne    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21a, 0x813, x86_l_813);
x86_l_220:
	/* 0x220: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_225:
	/* 0x225: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_22b:
	/* 0x22b: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_230:
	/* 0x230: jmp    7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JMP(0x230, 0x7e9, x86_l_7e9);
x86_l_235:
	/* 0x235: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_238:
	/* 0x238: je     43a <generic_kprobe_actions+0x43a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x238, 0x43a, x86_l_43a);
x86_l_23e:
	/* 0x23e: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_240:
	/* 0x240: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_244:
	/* 0x244: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_247:
	/* 0x247: jne    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x247, 0x813, x86_l_813);
x86_l_24d:
	/* 0x24d: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_252:
	/* 0x252: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256:
	/* 0x256: mov    r15d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_25a:
	/* 0x25a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_263:
	/* 0x263: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_26c:
	/* 0x26c: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_274:
	/* 0x274: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_27b:
	/* 0x27b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x28a: je     2aa <generic_kprobe_actions+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28a, 0x2aa, x86_l_2aa);
x86_l_28c:
	/* 0x28c: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_290:
	/* 0x290: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_294:
	/* 0x294: ja     2aa <generic_kprobe_actions+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x294, 0x2aa, x86_l_2aa);
x86_l_296:
	/* 0x296: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29b:
	/* 0x29b: cmp    DWORD PTR [rcx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_2a4:
	/* 0x2a4: je     543 <generic_kprobe_actions+0x543> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a4, 0x543, x86_l_543);
x86_l_2aa:
	/* 0x2aa: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_2b0:
	/* 0x2b0: jmp    80e <generic_kprobe_actions+0x80e> */
	X86_SIM_X86_JMP(0x2b0, 0x80e, x86_l_80e);
x86_l_2b5:
	/* 0x2b5: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b9:
	/* 0x2b9: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2bd:
	/* 0x2bd: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_2c3:
	/* 0x2c3: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x2c3, 0x813, x86_l_813);
x86_l_2c8:
	/* 0x2c8: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2d0:
	/* 0x2d0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d3:
	/* 0x2d3: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x2d3, 0x813, x86_l_813);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dd:
	/* 0x2dd: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_2e3:
	/* 0x2e3: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_2e9:
	/* 0x2e9: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_2ec:
	/* 0x2ec: je     7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ec, 0x7e9, x86_l_7e9);
x86_l_2f2:
	/* 0x2f2: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f6:
	/* 0x2f6: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2fa:
	/* 0x2fa: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ff:
	/* 0x2ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_301:
	/* 0x301: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_306:
	/* 0x306: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_30d:
	/* 0x30d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_312:
	/* 0x312: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_317:
	/* 0x317: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319:
	/* 0x319: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31c:
	/* 0x31c: je     676 <generic_kprobe_actions+0x676> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31c, 0x676, x86_l_676);
x86_l_322:
	/* 0x322: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_325:
	/* 0x325: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_32d:
	/* 0x32d: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_336:
	/* 0x336: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_33d:
	/* 0x33d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_342:
	/* 0x342: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_347:
	/* 0x347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_349:
	/* 0x349: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34c:
	/* 0x34c: je     7b8 <generic_kprobe_actions+0x7b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34c, 0x7b8, x86_l_7b8);
x86_l_352:
	/* 0x352: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_354:
	/* 0x354: jmp    7dc <generic_kprobe_actions+0x7dc> */
	X86_SIM_X86_JMP(0x354, 0x7dc, x86_l_7dc);
x86_l_359:
	/* 0x359: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_35e:
	/* 0x35e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_360:
	/* 0x360: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_365:
	/* 0x365: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_36c:
	/* 0x36c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_371:
	/* 0x371: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_376:
	/* 0x376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378:
	/* 0x378: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37b:
	/* 0x37b: je     813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37b, 0x813, x86_l_813);
x86_l_381:
	/* 0x381: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_385:
	/* 0x385: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38a:
	/* 0x38a: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_392:
	/* 0x392: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_399:
	/* 0x399: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39e:
	/* 0x39e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a3:
	/* 0x3a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a5:
	/* 0x3a5: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_3ad:
	/* 0x3ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: je     60b <generic_kprobe_actions+0x60b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b0, 0x60b, x86_l_60b);
x86_l_3b6:
	/* 0x3b6: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3b9:
	/* 0x3b9: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_3c0:
	/* 0x3c0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3c5:
	/* 0x3c5: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3ca:
	/* 0x3ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc:
	/* 0x3cc: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x3cc, 0x813, x86_l_813);
x86_l_3d1:
	/* 0x3d1: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3d5:
	/* 0x3d5: cmp    DWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3da:
	/* 0x3da: je     3fd <generic_kprobe_actions+0x3fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3da, 0x3fd, x86_l_3fd);
x86_l_3dc:
	/* 0x3dc: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_3e1:
	/* 0x3e1: mov    rsi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_3e8:
	/* 0x3e8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ea:
	/* 0x3ea: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_3ef:
	/* 0x3ef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3f2:
	/* 0x3f2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f4:
	/* 0x3f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f6:
	/* 0x3f6: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fd:
	/* 0x3fd: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_403:
	/* 0x403: cmp    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_408:
	/* 0x408: je     813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_E, 0x408, 0x813, x86_l_813);
x86_l_40e:
	/* 0x40e: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_413:
	/* 0x413: mov    rsi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_41a:
	/* 0x41a: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_41f:
	/* 0x41f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_424:
	/* 0x424: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_429:
	/* 0x429: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_42c:
	/* 0x42c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e:
	/* 0x42e: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_435:
	/* 0x435: jmp    813 <generic_kprobe_actions+0x813> */
	X86_SIM_X86_JMP(0x435, 0x813, x86_l_813);
x86_l_43a:
	/* 0x43a: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43f:
	/* 0x43f: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_441:
	/* 0x441: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_445:
	/* 0x445: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_44a:
	/* 0x44a: jmp    7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JMP(0x44a, 0x7e9, x86_l_7e9);
x86_l_44f:
	/* 0x44f: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_454:
	/* 0x454: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_456:
	/* 0x456: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_45a:
	/* 0x45a: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_460:
	/* 0x460: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_466:
	/* 0x466: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_469:
	/* 0x469: je     7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x469, 0x7e9, x86_l_7e9);
x86_l_46f:
	/* 0x46f: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_473:
	/* 0x473: mov    esi,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_477:
	/* 0x477: mov    edx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_47b:
	/* 0x47b: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_47f:
	/* 0x47f: mov    DWORD PTR [rsp+0x50],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_483:
	/* 0x483: mov    DWORD PTR [rsp+0x68],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_487:
	/* 0x487: ja     49c <generic_kprobe_actions+0x49c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x487, 0x49c, x86_l_49c);
x86_l_489:
	/* 0x489: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48e:
	/* 0x48e: cmp    DWORD PTR [rcx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_496:
	/* 0x496: je     fa4 <generic_kprobe_actions+0xfa4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x496, 0xfa4, x86_l_fa4);
x86_l_49c:
	/* 0x49c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49f:
	/* 0x49f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a4:
	/* 0x4a4: mov    eax,DWORD PTR [rax+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4a7:
	/* 0x4a7: shl    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_4ab:
	/* 0x4ab: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_4ae:
	/* 0x4ae: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4b3:
	/* 0x4b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5:
	/* 0x4b5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4ba:
	/* 0x4ba: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4be:
	/* 0x4be: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c3:
	/* 0x4c3: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c7:
	/* 0x4c7: mov    WORD PTR [rsp+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_4cc:
	/* 0x4cc: mov    QWORD PTR [rsp+0x24],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4d1:
	/* 0x4d1: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_4d8:
	/* 0x4d8: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4dd:
	/* 0x4dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e2:
	/* 0x4e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e4:
	/* 0x4e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e7:
	/* 0x4e7: je     753 <generic_kprobe_actions+0x753> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e7, 0x753, x86_l_753);
x86_l_4ed:
	/* 0x4ed: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4f0:
	/* 0x4f0: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f4:
	/* 0x4f4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4f9:
	/* 0x4f9: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_501:
	/* 0x501: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_508:
	/* 0x508: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_50d:
	/* 0x50d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_512:
	/* 0x512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_514:
	/* 0x514: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_51c:
	/* 0x51c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51f:
	/* 0x51f: je     f18 <generic_kprobe_actions+0xf18> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51f, 0xf18, x86_l_f18);
x86_l_525:
	/* 0x525: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_528:
	/* 0x528: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_52c:
	/* 0x52c: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530:
	/* 0x530: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_535:
	/* 0x535: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_538:
	/* 0x538: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_53e:
	/* 0x53e: jmp    7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JMP(0x53e, 0x7e9, x86_l_7e9);
x86_l_543:
	/* 0x543: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_548:
	/* 0x548: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_54d:
	/* 0x54d: mov    rax,QWORD PTR [rcx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_555:
	/* 0x555: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_558:
	/* 0x558: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_560:
	/* 0x560: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_565:
	/* 0x565: mov    eax,DWORD PTR [rcx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_56c:
	/* 0x56c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_570:
	/* 0x570: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_575:
	/* 0x575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_577:
	/* 0x577: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_580:
	/* 0x580: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_583:
	/* 0x583: jne    dbb <generic_kprobe_actions+0xdbb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x583, 0xdbb, x86_l_dbb);
x86_l_589:
	/* 0x589: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_58d:
	/* 0x58d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_591:
	/* 0x591: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_596:
	/* 0x596: ja     2aa <generic_kprobe_actions+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x596, 0x2aa, x86_l_2aa);
x86_l_59c:
	/* 0x59c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a1:
	/* 0x5a1: cmp    DWORD PTR [rcx+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_5aa:
	/* 0x5aa: jne    2aa <generic_kprobe_actions+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5aa, 0x2aa, x86_l_2aa);
x86_l_5b0:
	/* 0x5b0: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b5:
	/* 0x5b5: mov    rcx,QWORD PTR [rsi+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_5bd:
	/* 0x5bd: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_5c3:
	/* 0x5c3: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5c7:
	/* 0x5c7: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_5ce:
	/* 0x5ce: mov    esi,DWORD PTR [rsi+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_5d5:
	/* 0x5d5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5db:
	/* 0x5db: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5df:
	/* 0x5df: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5e2:
	/* 0x5e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e7:
	/* 0x5e7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5ea:
	/* 0x5ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ec:
	/* 0x5ec: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_5f3:
	/* 0x5f3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f5:
	/* 0x5f5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ff:
	/* 0x5ff: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_602:
	/* 0x602: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_604:
	/* 0x604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606:
	/* 0x606: jmp    2aa <generic_kprobe_actions+0x2aa> */
	X86_SIM_X86_JMP(0x606, 0x2aa, x86_l_2aa);
x86_l_60b:
	/* 0x60b: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_612:
	/* 0x612: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_617:
	/* 0x617: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_61c:
	/* 0x61c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_621:
	/* 0x621: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_626:
	/* 0x626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_628:
	/* 0x628: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: je     3b9 <generic_kprobe_actions+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x62b, 0x3b9, x86_l_3b9);
x86_l_631:
	/* 0x631: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_636:
	/* 0x636: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_638:
	/* 0x638: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63d:
	/* 0x63d: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_644:
	/* 0x644: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_64e:
	/* 0x64e: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_653:
	/* 0x653: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_65a:
	/* 0x65a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65f:
	/* 0x65f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_664:
	/* 0x664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_666:
	/* 0x666: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_669:
	/* 0x669: je     16c9 <generic_kprobe_actions+0x16c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x669, 0x16c9, x86_l_16c9);
x86_l_66f:
	/* 0x66f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_671:
	/* 0x671: jmp    16ed <generic_kprobe_actions+0x16ed> */
	X86_SIM_X86_JMP(0x671, 0x16ed, x86_l_16ed);
x86_l_676:
	/* 0x676: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_67d:
	/* 0x67d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67f:
	/* 0x67f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_684:
	/* 0x684: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_689:
	/* 0x689: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_68e:
	/* 0x68e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_690:
	/* 0x690: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_692:
	/* 0x692: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_698:
	/* 0x698: jmp    7e9 <generic_kprobe_actions+0x7e9> */
	X86_SIM_X86_JMP(0x698, 0x7e9, x86_l_7e9);
x86_l_69d:
	/* 0x69d: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_6a5:
	/* 0x6a5: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6aa:
	/* 0x6aa: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_6b2:
	/* 0x6b2: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b6:
	/* 0x6b6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6bb:
	/* 0x6bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bd:
	/* 0x6bd: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6c1:
	/* 0x6c1: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c6:
	/* 0x6c6: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6cd:
	/* 0x6cd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d2:
	/* 0x6d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d7:
	/* 0x6d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d9:
	/* 0x6d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6dc:
	/* 0x6dc: je     1f4 <generic_kprobe_actions+0x1f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6dc, 0x1f4, x86_l_1f4);
x86_l_6e2:
	/* 0x6e2: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6e6:
	/* 0x6e6: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_6ea:
	/* 0x6ea: ja     1f4 <generic_kprobe_actions+0x1f4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6ea, 0x1f4, x86_l_1f4);
x86_l_6f0:
	/* 0x6f0: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_6f9:
	/* 0x6f9: jne    1f4 <generic_kprobe_actions+0x1f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6f9, 0x1f4, x86_l_1f4);
x86_l_6ff:
	/* 0x6ff: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_707:
	/* 0x707: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_70f:
	/* 0x70f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_715:
	/* 0x715: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_71d:
	/* 0x71d: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_721:
	/* 0x721: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_724:
	/* 0x724: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_729:
	/* 0x729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72b:
	/* 0x72b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_72f:
	/* 0x72f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_734:
	/* 0x734: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_73b:
	/* 0x73b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73d:
	/* 0x73d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_742:
	/* 0x742: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_747:
	/* 0x747: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_74a:
	/* 0x74a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_74c:
	/* 0x74c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74e:
	/* 0x74e: jmp    1f4 <generic_kprobe_actions+0x1f4> */
	X86_SIM_X86_JMP(0x74e, 0x1f4, x86_l_1f4);
x86_l_753:
	/* 0x753: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_75a:
	/* 0x75a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75c:
	/* 0x75c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_761:
	/* 0x761: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_766:
	/* 0x766: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_76b:
	/* 0x76b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_76d:
	/* 0x76d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76f:
	/* 0x76f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_772:
	/* 0x772: je     538 <generic_kprobe_actions+0x538> */
	X86_SIM_X86_JCC(X86_CC_E, 0x772, 0x538, x86_l_538);
x86_l_778:
	/* 0x778: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_77a:
	/* 0x77a: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_77f:
	/* 0x77f: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_786:
	/* 0x786: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_790:
	/* 0x790: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_795:
	/* 0x795: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_79c:
	/* 0x79c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a1:
	/* 0x7a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a6:
	/* 0x7a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a8:
	/* 0x7a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ab:
	/* 0x7ab: je     17c0 <generic_kprobe_actions+0x17c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ab, 0x17c0, x86_l_17c0);
x86_l_7b1:
	/* 0x7b1: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7b3:
	/* 0x7b3: jmp    538 <generic_kprobe_actions+0x538> */
	X86_SIM_X86_JMP(0x7b3, 0x538, x86_l_538);
x86_l_7b8:
	/* 0x7b8: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_7c0:
	/* 0x7c0: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7c7:
	/* 0x7c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c9:
	/* 0x7c9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ce:
	/* 0x7ce: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7d3:
	/* 0x7d3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7d8:
	/* 0x7d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7da:
	/* 0x7da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dc:
	/* 0x7dc: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7e0:
	/* 0x7e0: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e3:
	/* 0x7e3: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_7e9:
	/* 0x7e9: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_7f1:
	/* 0x7f1: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_7f8:
	/* 0x7f8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fd:
	/* 0x7fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_802:
	/* 0x802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_804:
	/* 0x804: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_807:
	/* 0x807: je     80e <generic_kprobe_actions+0x80e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x807, 0x80e, x86_l_80e);
x86_l_809:
	/* 0x809: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_80e:
	/* 0x80e: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_813:
	/* 0x813: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_817:
	/* 0x817: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_81a:
	/* 0x81a: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_822:
	/* 0x822: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_826:
	/* 0x826: jae    10f5 <generic_kprobe_actions+0x10f5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x826, 0x10f5, x86_l_10f5);
x86_l_82c:
	/* 0x82c: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_831:
	/* 0x831: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_834:
	/* 0x834: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_837:
	/* 0x837: mov    r14d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_32);
x86_l_83a:
	/* 0x83a: movsxd r15,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_83f:
	/* 0x83f: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_847:
	/* 0x847: mov    rdi,QWORD PTR [rip+0x58d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_84e:
	/* 0x84e: lea    rsi,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_853:
	/* 0x853: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_858:
	/* 0x858: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85a:
	/* 0x85a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85c:
	/* 0x85c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85f:
	/* 0x85f: je     8a0 <generic_kprobe_actions+0x8a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85f, 0x8a0, x86_l_8a0);
x86_l_861:
	/* 0x861: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_864:
	/* 0x864: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_868:
	/* 0x868: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_86b:
	/* 0x86b: jg     8ad <generic_kprobe_actions+0x8ad> */
	X86_SIM_X86_JCC(X86_CC_G, 0x86b, 0x8ad, x86_l_8ad);
x86_l_86d:
	/* 0x86d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_870:
	/* 0x870: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_873:
	/* 0x873: jg     8f6 <generic_kprobe_actions+0x8f6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x873, 0x8f6, x86_l_8f6);
x86_l_879:
	/* 0x879: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_87c:
	/* 0x87c: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_87f:
	/* 0x87f: jg     a5d <generic_kprobe_actions+0xa5d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x87f, 0xa5d, x86_l_a5d);
x86_l_885:
	/* 0x885: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_887:
	/* 0x887: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88c:
	/* 0x88c: je     c2e <generic_kprobe_actions+0xc2e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88c, 0xc2e, x86_l_c2e);
x86_l_892:
	/* 0x892: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_895:
	/* 0x895: je     a74 <generic_kprobe_actions+0xa74> */
	X86_SIM_X86_JCC(X86_CC_E, 0x895, 0xa74, x86_l_a74);
x86_l_89b:
	/* 0x89b: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0x89b, 0x1082, x86_l_1082);
x86_l_8a0:
	/* 0x8a0: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_8a3:
	/* 0x8a3: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a8:
	/* 0x8a8: jmp    108c <generic_kprobe_actions+0x108c> */
	X86_SIM_X86_JMP(0x8a8, 0x108c, x86_l_108c);
x86_l_8ad:
	/* 0x8ad: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_8b0:
	/* 0x8b0: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_8b3:
	/* 0x8b3: jg     a22 <generic_kprobe_actions+0xa22> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8b3, 0xa22, x86_l_a22);
x86_l_8b9:
	/* 0x8b9: lea    eax,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_8bc:
	/* 0x8bc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8bf:
	/* 0x8bf: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: jb     af4 <generic_kprobe_actions+0xaf4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8c2, 0xaf4, x86_l_af4);
x86_l_8c8:
	/* 0x8c8: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8cb:
	/* 0x8cb: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d0:
	/* 0x8d0: je     b16 <generic_kprobe_actions+0xb16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d0, 0xb16, x86_l_b16);
x86_l_8d6:
	/* 0x8d6: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_8d9:
	/* 0x8d9: jne    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8d9, 0x1082, x86_l_1082);
x86_l_8df:
	/* 0x8df: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8e4:
	/* 0x8e4: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e9:
	/* 0x8e9: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_8ec:
	/* 0x8ec: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8f1:
	/* 0x8f1: jmp    1053 <generic_kprobe_actions+0x1053> */
	X86_SIM_X86_JMP(0x8f1, 0x1053, x86_l_1053);
x86_l_8f6:
	/* 0x8f6: lea    eax,[rcx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_8f9:
	/* 0x8f9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8fc:
	/* 0x8fc: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_8ff:
	/* 0x8ff: jb     b01 <generic_kprobe_actions+0xb01> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8ff, 0xb01, x86_l_b01);
x86_l_905:
	/* 0x905: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_908:
	/* 0x908: je     b23 <generic_kprobe_actions+0xb23> */
	X86_SIM_X86_JCC(X86_CC_E, 0x908, 0xb23, x86_l_b23);
x86_l_90e:
	/* 0x90e: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_911:
	/* 0x911: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_916:
	/* 0x916: jne    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x916, 0x1082, x86_l_1082);
x86_l_91c:
	/* 0x91c: mov    eax,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_921:
	/* 0x921: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_925:
	/* 0x925: mov    r14d,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_92a:
	/* 0x92a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_933:
	/* 0x933: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_93c:
	/* 0x93c: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_93f:
	/* 0x93f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_942:
	/* 0x942: ja     1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_A, 0x942, 0x1082, x86_l_1082);
x86_l_948:
	/* 0x948: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_950:
	/* 0x950: jne    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x950, 0x1082, x86_l_1082);
x86_l_956:
	/* 0x956: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_95e:
	/* 0x95e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_963:
	/* 0x963: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_96a:
	/* 0x96a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96e:
	/* 0x96e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_973:
	/* 0x973: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_978:
	/* 0x978: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_97b:
	/* 0x97b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97d:
	/* 0x97d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_981:
	/* 0x981: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_986:
	/* 0x986: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_98d:
	/* 0x98d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_992:
	/* 0x992: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_997:
	/* 0x997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_999:
	/* 0x999: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_99c:
	/* 0x99c: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9a1:
	/* 0x9a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a4:
	/* 0x9a4: je     1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a4, 0x1082, x86_l_1082);
x86_l_9aa:
	/* 0x9aa: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_9ae:
	/* 0x9ae: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_9b2:
	/* 0x9b2: ja     1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9b2, 0x1082, x86_l_1082);
x86_l_9b8:
	/* 0x9b8: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_9c1:
	/* 0x9c1: jne    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c1, 0x1082, x86_l_1082);
x86_l_9c7:
	/* 0x9c7: mov    rcx,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_9cf:
	/* 0x9cf: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_9d7:
	/* 0x9d7: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9dd:
	/* 0x9dd: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_9e4:
	/* 0x9e4: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e8:
	/* 0x9e8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_9eb:
	/* 0x9eb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9f0:
	/* 0x9f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f2:
	/* 0x9f2: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_9f6:
	/* 0x9f6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9fb:
	/* 0x9fb: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_a02:
	/* 0xa02: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a04:
	/* 0xa04: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a09:
	/* 0xa09: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a0e:
	/* 0xa0e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_a11:
	/* 0xa11: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a13:
	/* 0xa13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a15:
	/* 0xa15: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a18:
	/* 0xa18: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a1d:
	/* 0xa1d: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xa1d, 0x1082, x86_l_1082);
x86_l_a22:
	/* 0xa22: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_a25:
	/* 0xa25: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_a28:
	/* 0xa28: je     cc9 <generic_kprobe_actions+0xcc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa28, 0xcc9, x86_l_cc9);
x86_l_a2e:
	/* 0xa2e: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_a31:
	/* 0xa31: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a36:
	/* 0xa36: je     bae <generic_kprobe_actions+0xbae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa36, 0xbae, x86_l_bae);
x86_l_a3c:
	/* 0xa3c: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_a3f:
	/* 0xa3f: jne    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3f, 0x1082, x86_l_1082);
x86_l_a45:
	/* 0xa45: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a4a:
	/* 0xa4a: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a4f:
	/* 0xa4f: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_a53:
	/* 0xa53: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a58:
	/* 0xa58: jmp    1053 <generic_kprobe_actions+0x1053> */
	X86_SIM_X86_JMP(0xa58, 0x1053, x86_l_1053);
x86_l_a5d:
	/* 0xa5d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a60:
	/* 0xa60: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a65:
	/* 0xa65: je     cb5 <generic_kprobe_actions+0xcb5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa65, 0xcb5, x86_l_cb5);
x86_l_a6b:
	/* 0xa6b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a6e:
	/* 0xa6e: jne    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa6e, 0x1082, x86_l_1082);
x86_l_a74:
	/* 0xa74: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a79:
	/* 0xa79: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a7e:
	/* 0xa7e: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_a83:
	/* 0xa83: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_a87:
	/* 0xa87: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_a8c:
	/* 0xa8c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a94:
	/* 0xa94: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a9d:
	/* 0xa9d: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_aa6:
	/* 0xaa6: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_aae:
	/* 0xaae: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_ab5:
	/* 0xab5: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_ab8:
	/* 0xab8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_abd:
	/* 0xabd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac2:
	/* 0xac2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac4:
	/* 0xac4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ac7:
	/* 0xac7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: je     ae5 <generic_kprobe_actions+0xae5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaca, 0xae5, x86_l_ae5);
x86_l_acc:
	/* 0xacc: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ad0:
	/* 0xad0: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_ad4:
	/* 0xad4: ja     ae5 <generic_kprobe_actions+0xae5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xad4, 0xae5, x86_l_ae5);
x86_l_ad6:
	/* 0xad6: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_adf:
	/* 0xadf: je     de4 <generic_kprobe_actions+0xde4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadf, 0xde4, x86_l_de4);
x86_l_ae5:
	/* 0xae5: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aea:
	/* 0xaea: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aef:
	/* 0xaef: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xaef, 0x1082, x86_l_1082);
x86_l_af4:
	/* 0xaf4: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_af7:
	/* 0xaf7: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_afc:
	/* 0xafc: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xafc, 0x1082, x86_l_1082);
x86_l_b01:
	/* 0xb01: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b04:
	/* 0xb04: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_b09:
	/* 0xb09: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b0c:
	/* 0xb0c: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b11:
	/* 0xb11: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xb11, 0x1082, x86_l_1082);
x86_l_b16:
	/* 0xb16: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_b1e:
	/* 0xb1e: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xb1e, 0x1082, x86_l_1082);
x86_l_b23:
	/* 0xb23: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b28:
	/* 0xb28: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b2d:
	/* 0xb2d: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b30:
	/* 0xb30: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_b35:
	/* 0xb35: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_b38:
	/* 0xb38: je     db1 <generic_kprobe_actions+0xdb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb38, 0xdb1, x86_l_db1);
x86_l_b3e:
	/* 0xb3e: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_b41:
	/* 0xb41: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_b46:
	/* 0xb46: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b4a:
	/* 0xb4a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_b4f:
	/* 0xb4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b51:
	/* 0xb51: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b56:
	/* 0xb56: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_b5d:
	/* 0xb5d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b62:
	/* 0xb62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b67:
	/* 0xb67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b69:
	/* 0xb69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b6c:
	/* 0xb6c: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b71:
	/* 0xb71: je     f83 <generic_kprobe_actions+0xf83> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb71, 0xf83, x86_l_f83);
x86_l_b77:
	/* 0xb77: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_b7a:
	/* 0xb7a: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_b82:
	/* 0xb82: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_b8b:
	/* 0xb8b: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b92:
	/* 0xb92: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b97:
	/* 0xb97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b9c:
	/* 0xb9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9e:
	/* 0xb9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ba1:
	/* 0xba1: je     1023 <generic_kprobe_actions+0x1023> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba1, 0x1023, x86_l_1023);
x86_l_ba7:
	/* 0xba7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ba9:
	/* 0xba9: jmp    1047 <generic_kprobe_actions+0x1047> */
	X86_SIM_X86_JMP(0xba9, 0x1047, x86_l_1047);
x86_l_bae:
	/* 0xbae: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_bb1:
	/* 0xbb1: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_bb4:
	/* 0xbb4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_bb9:
	/* 0xbb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbb:
	/* 0xbbb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bc0:
	/* 0xbc0: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_bc7:
	/* 0xbc7: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bcc:
	/* 0xbcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bd1:
	/* 0xbd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd3:
	/* 0xbd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bd6:
	/* 0xbd6: je     c23 <generic_kprobe_actions+0xc23> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd6, 0xc23, x86_l_c23);
x86_l_bd8:
	/* 0xbd8: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bdc:
	/* 0xbdc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be1:
	/* 0xbe1: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_be9:
	/* 0xbe9: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_bf0:
	/* 0xbf0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bf5:
	/* 0xbf5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bfa:
	/* 0xbfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfc:
	/* 0xbfc: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_c04:
	/* 0xc04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c07:
	/* 0xc07: je     ead <generic_kprobe_actions+0xead> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc07, 0xead, x86_l_ead);
x86_l_c0d:
	/* 0xc0d: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c10:
	/* 0xc10: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_c17:
	/* 0xc17: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c1c:
	/* 0xc1c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c21:
	/* 0xc21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c23:
	/* 0xc23: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_c26:
	/* 0xc26: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_c29:
	/* 0xc29: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xc29, 0x1082, x86_l_1082);
x86_l_c2e:
	/* 0xc2e: cmp    DWORD PTR [r13+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_c34:
	/* 0xc34: je     c68 <generic_kprobe_actions+0xc68> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc34, 0xc68, x86_l_c68);
x86_l_c36:
	/* 0xc36: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_c3a:
	/* 0xc3a: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_c3d:
	/* 0xc3d: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c40:
	/* 0xc40: mov    rsi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c47:
	/* 0xc47: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_c4a:
	/* 0xc4a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4c:
	/* 0xc4c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c51:
	/* 0xc51: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c54:
	/* 0xc54: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c56:
	/* 0xc56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c58:
	/* 0xc58: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c5b:
	/* 0xc5b: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_c5e:
	/* 0xc5e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_c61:
	/* 0xc61: mov    QWORD PTR [rdx+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c68:
	/* 0xc68: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_c6c:
	/* 0xc6c: cmp    DWORD PTR [r13+r15*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 17179869184ULL);
x86_l_c72:
	/* 0xc72: je     1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc72, 0x1082, x86_l_1082);
x86_l_c78:
	/* 0xc78: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c7c:
	/* 0xc7c: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_c7f:
	/* 0xc7f: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c82:
	/* 0xc82: mov    rsi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c89:
	/* 0xc89: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_c8c:
	/* 0xc8c: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_c91:
	/* 0xc91: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c96:
	/* 0xc96: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c9b:
	/* 0xc9b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c9e:
	/* 0xc9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca0:
	/* 0xca0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ca3:
	/* 0xca3: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_ca6:
	/* 0xca6: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_ca9:
	/* 0xca9: mov    QWORD PTR [rdx+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cb0:
	/* 0xcb0: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0xcb0, 0x1082, x86_l_1082);
x86_l_cb5:
	/* 0xcb5: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cba:
	/* 0xcba: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cbf:
	/* 0xcbf: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cc4:
	/* 0xcc4: jmp    1053 <generic_kprobe_actions+0x1053> */
	X86_SIM_X86_JMP(0xcc4, 0x1053, x86_l_1053);
x86_l_cc9:
	/* 0xcc9: add    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_ccd:
	/* 0xccd: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_cd2:
	/* 0xcd2: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_cd5:
	/* 0xcd5: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cda:
	/* 0xcda: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cdf:
	/* 0xcdf: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ce4:
	/* 0xce4: je     1053 <generic_kprobe_actions+0x1053> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce4, 0x1053, x86_l_1053);
x86_l_cea:
	/* 0xcea: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_ced:
	/* 0xced: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_cf2:
	/* 0xcf2: mov    esi,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_cf7:
	/* 0xcf7: mov    ebp,DWORD PTR [r13+r14*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 12ULL);
x86_l_cfc:
	/* 0xcfc: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_d00:
	/* 0xd00: mov    DWORD PTR [rsp+0x70],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d04:
	/* 0xd04: ja     d14 <generic_kprobe_actions+0xd14> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd04, 0xd14, x86_l_d14);
x86_l_d06:
	/* 0xd06: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_d0e:
	/* 0xd0e: je     17a6 <generic_kprobe_actions+0x17a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd0e, 0x17a6, x86_l_17a6);
x86_l_d14:
	/* 0xd14: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d17:
	/* 0xd17: mov    eax,DWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d1a:
	/* 0xd1a: shl    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_d1e:
	/* 0xd1e: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d21:
	/* 0xd21: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d26:
	/* 0xd26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d28:
	/* 0xd28: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d2d:
	/* 0xd2d: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d31:
	/* 0xd31: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d36:
	/* 0xd36: mov    WORD PTR [rsp+0x22],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_d3b:
	/* 0xd3b: mov    QWORD PTR [rsp+0x24],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d40:
	/* 0xd40: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_d47:
	/* 0xd47: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d4c:
	/* 0xd4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d51:
	/* 0xd51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d53:
	/* 0xd53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d56:
	/* 0xd56: je     fbe <generic_kprobe_actions+0xfbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd56, 0xfbe, x86_l_fbe);
x86_l_d5c:
	/* 0xd5c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d5f:
	/* 0xd5f: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d63:
	/* 0xd63: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d68:
	/* 0xd68: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d77:
	/* 0xd77: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d7c:
	/* 0xd7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d81:
	/* 0xd81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d83:
	/* 0xd83: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_d8b:
	/* 0xd8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8e:
	/* 0xd8e: je     1660 <generic_kprobe_actions+0x1660> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd8e, 0x1660, x86_l_1660);
x86_l_d94:
	/* 0xd94: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d97:
	/* 0xd97: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d9b:
	/* 0xd9b: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9f:
	/* 0xd9f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da4:
	/* 0xda4: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da7:
	/* 0xda7: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_dac:
	/* 0xdac: jmp    1053 <generic_kprobe_actions+0x1053> */
	X86_SIM_X86_JMP(0xdac, 0x1053, x86_l_1053);
x86_l_db1:
	/* 0xdb1: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_db6:
	/* 0xdb6: jmp    1053 <generic_kprobe_actions+0x1053> */
	X86_SIM_X86_JMP(0xdb6, 0x1053, x86_l_1053);
x86_l_dbb:
	/* 0xdbb: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_dc2:
	/* 0xdc2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc7:
	/* 0xdc7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_dcc:
	/* 0xdcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dce:
	/* 0xdce: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dd1:
	/* 0xdd1: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_dd3:
	/* 0xdd3: mov    DWORD PTR [rsp+0x1c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_dd7:
	/* 0xdd7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd9:
	/* 0xdd9: jne    81a <generic_kprobe_actions+0x81a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdd9, 0x81a, x86_l_81a);
x86_l_ddf:
	/* 0xddf: jmp    1f4 <generic_kprobe_actions+0x1f4> */
	X86_SIM_X86_JMP(0xddf, 0x1f4, x86_l_1f4);
x86_l_de4:
	/* 0xde4: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_dec:
	/* 0xdec: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_df4:
	/* 0xdf4: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_dfc:
	/* 0xdfc: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e01:
	/* 0xe01: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_e08:
	/* 0xe08: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e0c:
	/* 0xe0c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e11:
	/* 0xe11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e13:
	/* 0xe13: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e17:
	/* 0xe17: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e1c:
	/* 0xe1c: cmp    DWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_e21:
	/* 0xe21: jne    1633 <generic_kprobe_actions+0x1633> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe21, 0x1633, x86_l_1633);
x86_l_e27:
	/* 0xe27: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e2f:
	/* 0xe2f: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e32:
	/* 0xe32: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e35:
	/* 0xe35: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e3d:
	/* 0xe3d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e40:
	/* 0xe40: ja     ae5 <generic_kprobe_actions+0xae5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe40, 0xae5, x86_l_ae5);
x86_l_e46:
	/* 0xe46: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e49:
	/* 0xe49: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_e51:
	/* 0xe51: jne    ae5 <generic_kprobe_actions+0xae5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe51, 0xae5, x86_l_ae5);
x86_l_e57:
	/* 0xe57: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_e5f:
	/* 0xe5f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e65:
	/* 0xe65: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e68:
	/* 0xe68: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_e6f:
	/* 0xe6f: mov    esi,DWORD PTR [r12+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e77:
	/* 0xe77: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e7d:
	/* 0xe7d: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e81:
	/* 0xe81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e86:
	/* 0xe86: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e89:
	/* 0xe89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8b:
	/* 0xe8b: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e92:
	/* 0xe92: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e94:
	/* 0xe94: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e99:
	/* 0xe99: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e9e:
	/* 0xe9e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ea1:
	/* 0xea1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea3:
	/* 0xea3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea5:
	/* 0xea5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ea8:
	/* 0xea8: jmp    ae5 <generic_kprobe_actions+0xae5> */
	X86_SIM_X86_JMP(0xea8, 0xae5, x86_l_ae5);
x86_l_ead:
	/* 0xead: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_eb4:
	/* 0xeb4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eb9:
	/* 0xeb9: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ebe:
	/* 0xebe: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ec3:
	/* 0xec3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ec8:
	/* 0xec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eca:
	/* 0xeca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ecd:
	/* 0xecd: je     c10 <generic_kprobe_actions+0xc10> */
	X86_SIM_X86_JCC(X86_CC_E, 0xecd, 0xc10, x86_l_c10);
x86_l_ed3:
	/* 0xed3: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ed8:
	/* 0xed8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_eda:
	/* 0xeda: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_edf:
	/* 0xedf: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_ee6:
	/* 0xee6: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_ef0:
	/* 0xef0: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ef5:
	/* 0xef5: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_efc:
	/* 0xefc: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f01:
	/* 0xf01: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f06:
	/* 0xf06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f08:
	/* 0xf08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0b:
	/* 0xf0b: je     18df <generic_kprobe_actions+0x18df> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf0b, 0x18df, x86_l_18df);
x86_l_f11:
	/* 0xf11: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f13:
	/* 0xf13: jmp    1903 <generic_kprobe_actions+0x1903> */
	X86_SIM_X86_JMP(0xf13, 0x1903, x86_l_1903);
x86_l_f18:
	/* 0xf18: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_f1f:
	/* 0xf1f: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f24:
	/* 0xf24: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f29:
	/* 0xf29: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f2e:
	/* 0xf2e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f33:
	/* 0xf33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f35:
	/* 0xf35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f38:
	/* 0xf38: je     528 <generic_kprobe_actions+0x528> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf38, 0x528, x86_l_528);
x86_l_f3e:
	/* 0xf3e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f43:
	/* 0xf43: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_f45:
	/* 0xf45: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4a:
	/* 0xf4a: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_f51:
	/* 0xf51: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_f5b:
	/* 0xf5b: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f60:
	/* 0xf60: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f67:
	/* 0xf67: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6c:
	/* 0xf6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f71:
	/* 0xf71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f73:
	/* 0xf73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f76:
	/* 0xf76: je     1936 <generic_kprobe_actions+0x1936> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf76, 0x1936, x86_l_1936);
x86_l_f7c:
	/* 0xf7c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f7e:
	/* 0xf7e: jmp    195a <generic_kprobe_actions+0x195a> */
	X86_SIM_X86_JMP(0xf7e, 0x195a, x86_l_195a);
x86_l_f83:
	/* 0xf83: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_f8a:
	/* 0xf8a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8c:
	/* 0xf8c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f91:
	/* 0xf91: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f96:
	/* 0xf96: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f9b:
	/* 0xf9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9d:
	/* 0xf9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9f:
	/* 0xf9f: jmp    104e <generic_kprobe_actions+0x104e> */
	X86_SIM_X86_JMP(0xf9f, 0x104e, x86_l_104e);
x86_l_fa4:
	/* 0xfa4: mov    rax,QWORD PTR [rcx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_fac:
	/* 0xfac: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_fb1:
	/* 0xfb1: mov    r14,QWORD PTR [rcx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_fb9:
	/* 0xfb9: jmp    49f <generic_kprobe_actions+0x49f> */
	X86_SIM_X86_JMP(0xfb9, 0x49f, x86_l_49f);
x86_l_fbe:
	/* 0xfbe: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_fc5:
	/* 0xfc5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc7:
	/* 0xfc7: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fcc:
	/* 0xfcc: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd1:
	/* 0xfd1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fd6:
	/* 0xfd6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd8:
	/* 0xfd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fda:
	/* 0xfda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fdd:
	/* 0xfdd: je     da7 <generic_kprobe_actions+0xda7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfdd, 0xda7, x86_l_da7);
x86_l_fe3:
	/* 0xfe3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_fe5:
	/* 0xfe5: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fea:
	/* 0xfea: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_ff1:
	/* 0xff1: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_ffb:
	/* 0xffb: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1000:
	/* 0x1000: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1007:
	/* 0x1007: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_100c:
	/* 0x100c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1011:
	/* 0x1011: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1013:
	/* 0x1013: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1016:
	/* 0x1016: je     19ab <generic_kprobe_actions+0x19ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1016, 0x19ab, x86_l_19ab);
x86_l_101c:
	/* 0x101c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_101e:
	/* 0x101e: jmp    da7 <generic_kprobe_actions+0xda7> */
	X86_SIM_X86_JMP(0x101e, 0xda7, x86_l_da7);
x86_l_1023:
	/* 0x1023: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_102b:
	/* 0x102b: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1032:
	/* 0x1032: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1034:
	/* 0x1034: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1039:
	/* 0x1039: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_103e:
	/* 0x103e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1043:
	/* 0x1043: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1045:
	/* 0x1045: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1047:
	/* 0x1047: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_104b:
	/* 0x104b: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104e:
	/* 0x104e: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1053:
	/* 0x1053: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_105b:
	/* 0x105b: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_1062:
	/* 0x1062: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1067:
	/* 0x1067: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_106c:
	/* 0x106c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106e:
	/* 0x106e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1071:
	/* 0x1071: je     1078 <generic_kprobe_actions+0x1078> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1071, 0x1078, x86_l_1078);
x86_l_1073:
	/* 0x1073: inc QWORD PTR [rax+rbp*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBP, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1078:
	/* 0x1078: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_107d:
	/* 0x107d: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1082:
	/* 0x1082: mov    QWORD PTR [rdx+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1086:
	/* 0x1086: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1089:
	/* 0x1089: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_108c:
	/* 0x108c: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_1093:
	/* 0x1093: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1097:
	/* 0x1097: jae    10f5 <generic_kprobe_actions+0x10f5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1097, 0x10f5, x86_l_10f5);
x86_l_1099:
	/* 0x1099: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_109c:
	/* 0x109c: movsxd rbp,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_10a1:
	/* 0x10a1: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_10a9:
	/* 0x10a9: mov    rdi,QWORD PTR [rip+0x58cc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_10b0:
	/* 0x10b0: lea    rsi,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_10b5:
	/* 0x10b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10ba:
	/* 0x10ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bc:
	/* 0x10bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10bf:
	/* 0x10bf: je     10f5 <generic_kprobe_actions+0x10f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10bf, 0x10f5, x86_l_10f5);
x86_l_10c1:
	/* 0x10c1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10c4:
	/* 0x10c4: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_10c7:
	/* 0x10c7: jle    1130 <generic_kprobe_actions+0x1130> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x10c7, 0x1130, x86_l_1130);
x86_l_10c9:
	/* 0x10c9: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_10cc:
	/* 0x10cc: jg     1154 <generic_kprobe_actions+0x1154> */
	X86_SIM_X86_JCC(X86_CC_G, 0x10cc, 0x1154, x86_l_1154);
x86_l_10d2:
	/* 0x10d2: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_10d5:
	/* 0x10d5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10d8:
	/* 0x10d8: jb     1286 <generic_kprobe_actions+0x1286> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10d8, 0x1286, x86_l_1286);
x86_l_10de:
	/* 0x10de: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_10e1:
	/* 0x10e1: je     13a1 <generic_kprobe_actions+0x13a1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e1, 0x13a1, x86_l_13a1);
x86_l_10e7:
	/* 0x10e7: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_10ea:
	/* 0x10ea: je     18a8 <generic_kprobe_actions+0x18a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ea, 0x18a8, x86_l_18a8);
x86_l_10f0:
	/* 0x10f0: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x10f0, 0x18d2, x86_l_18d2);
x86_l_10f5:
	/* 0x10f5: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10f9:
	/* 0x10f9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_10fb:
	/* 0x10fb: je     1118 <generic_kprobe_actions+0x1118> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fb, 0x1118, x86_l_1118);
x86_l_10fd:
	/* 0x10fd: mov    rsi,QWORD PTR [rip+0x58c8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_1104:
	/* 0x1104: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1109:
	/* 0x1109: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_110e:
	/* 0x110e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1111:
	/* 0x1111: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1116:
	/* 0x1116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1118:
	/* 0x1118: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111a:
	/* 0x111a: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1121:
	/* 0x1121: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1122:
	/* 0x1122: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1124:
	/* 0x1124: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1126:
	/* 0x1126: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1128:
	/* 0x1128: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_112a:
	/* 0x112a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_112b:
	/* 0x112b: jmp    1b00 <generic_kprobe_actions+0x1b00> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1130:
	/* 0x1130: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1133:
	/* 0x1133: jg     117e <generic_kprobe_actions+0x117e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1133, 0x117e, x86_l_117e);
x86_l_1135:
	/* 0x1135: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1137:
	/* 0x1137: je     14ee <generic_kprobe_actions+0x14ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1137, 0x14ee, x86_l_14ee);
x86_l_113d:
	/* 0x113d: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1140:
	/* 0x1140: je     1294 <generic_kprobe_actions+0x1294> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1140, 0x1294, x86_l_1294);
x86_l_1146:
	/* 0x1146: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1149:
	/* 0x1149: je     18a8 <generic_kprobe_actions+0x18a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1149, 0x18a8, x86_l_18a8);
x86_l_114f:
	/* 0x114f: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x114f, 0x18d2, x86_l_18d2);
x86_l_1154:
	/* 0x1154: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_1157:
	/* 0x1157: je     13a8 <generic_kprobe_actions+0x13a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1157, 0x13a8, x86_l_13a8);
x86_l_115d:
	/* 0x115d: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_1160:
	/* 0x1160: je     1476 <generic_kprobe_actions+0x1476> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1160, 0x1476, x86_l_1476);
x86_l_1166:
	/* 0x1166: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_116b:
	/* 0x116b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1170:
	/* 0x1170: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_1173:
	/* 0x1173: je     18a8 <generic_kprobe_actions+0x18a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1173, 0x18a8, x86_l_18a8);
x86_l_1179:
	/* 0x1179: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x1179, 0x18d2, x86_l_18d2);
x86_l_117e:
	/* 0x117e: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1181:
	/* 0x1181: je     1294 <generic_kprobe_actions+0x1294> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1181, 0x1294, x86_l_1294);
x86_l_1187:
	/* 0x1187: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_118a:
	/* 0x118a: je     154f <generic_kprobe_actions+0x154f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118a, 0x154f, x86_l_154f);
x86_l_1190:
	/* 0x1190: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1193:
	/* 0x1193: jne    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1193, 0x18d2, x86_l_18d2);
x86_l_1199:
	/* 0x1199: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_119e:
	/* 0x119e: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_11a3:
	/* 0x11a3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11ac:
	/* 0x11ac: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_11b5:
	/* 0x11b5: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_11b8:
	/* 0x11b8: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11bb:
	/* 0x11bb: ja     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11bb, 0x18d2, x86_l_18d2);
x86_l_11c1:
	/* 0x11c1: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_11ca:
	/* 0x11ca: jne    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11ca, 0x18d2, x86_l_18d2);
x86_l_11d0:
	/* 0x11d0: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_11d8:
	/* 0x11d8: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_11dd:
	/* 0x11dd: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_11e5:
	/* 0x11e5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11e9:
	/* 0x11e9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_11ee:
	/* 0x11ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f0:
	/* 0x11f0: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11f4:
	/* 0x11f4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f9:
	/* 0x11f9: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1200:
	/* 0x1200: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1205:
	/* 0x1205: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_120a:
	/* 0x120a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120c:
	/* 0x120c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_120f:
	/* 0x120f: je     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x120f, 0x18d2, x86_l_18d2);
x86_l_1215:
	/* 0x1215: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1219:
	/* 0x1219: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_121d:
	/* 0x121d: ja     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x121d, 0x18d2, x86_l_18d2);
x86_l_1223:
	/* 0x1223: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_122c:
	/* 0x122c: jne    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x122c, 0x18d2, x86_l_18d2);
x86_l_1232:
	/* 0x1232: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_123a:
	/* 0x123a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1242:
	/* 0x1242: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1248:
	/* 0x1248: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_1250:
	/* 0x1250: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1254:
	/* 0x1254: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1257:
	/* 0x1257: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_125c:
	/* 0x125c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125e:
	/* 0x125e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1262:
	/* 0x1262: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1267:
	/* 0x1267: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_126e:
	/* 0x126e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1270:
	/* 0x1270: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1275:
	/* 0x1275: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_127a:
	/* 0x127a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_127d:
	/* 0x127d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_127f:
	/* 0x127f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1281:
	/* 0x1281: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x1281, 0x18d2, x86_l_18d2);
x86_l_1286:
	/* 0x1286: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_128b:
	/* 0x128b: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_128f:
	/* 0x128f: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x128f, 0x18d2, x86_l_18d2);
x86_l_1294:
	/* 0x1294: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_1299:
	/* 0x1299: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_129e:
	/* 0x129e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12a7:
	/* 0x12a7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12b0:
	/* 0x12b0: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_12b8:
	/* 0x12b8: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_12bf:
	/* 0x12bf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12c4:
	/* 0x12c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c9:
	/* 0x12c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cb:
	/* 0x12cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ce:
	/* 0x12ce: je     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ce, 0x18d2, x86_l_18d2);
x86_l_12d4:
	/* 0x12d4: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_12d8:
	/* 0x12d8: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_12dc:
	/* 0x12dc: ja     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x12dc, 0x18d2, x86_l_18d2);
x86_l_12e2:
	/* 0x12e2: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_12eb:
	/* 0x12eb: jne    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12eb, 0x18d2, x86_l_18d2);
x86_l_12f1:
	/* 0x12f1: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_12f4:
	/* 0x12f4: mov    rax,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_12fc:
	/* 0x12fc: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1304:
	/* 0x1304: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1309:
	/* 0x1309: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1311:
	/* 0x1311: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1315:
	/* 0x1315: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_131a:
	/* 0x131a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131c:
	/* 0x131c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1320:
	/* 0x1320: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1325:
	/* 0x1325: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1328:
	/* 0x1328: jne    1852 <generic_kprobe_actions+0x1852> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1328, 0x1852, x86_l_1852);
x86_l_132e:
	/* 0x132e: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1332:
	/* 0x1332: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1336:
	/* 0x1336: ja     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1336, 0x18d2, x86_l_18d2);
x86_l_133c:
	/* 0x133c: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_1345:
	/* 0x1345: jne    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1345, 0x18d2, x86_l_18d2);
x86_l_134b:
	/* 0x134b: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_1353:
	/* 0x1353: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1358:
	/* 0x1358: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_135c:
	/* 0x135c: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1363:
	/* 0x1363: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_136b:
	/* 0x136b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1371:
	/* 0x1371: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1375:
	/* 0x1375: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_1378:
	/* 0x1378: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_137d:
	/* 0x137d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1380:
	/* 0x1380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1382:
	/* 0x1382: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1389:
	/* 0x1389: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_138b:
	/* 0x138b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1390:
	/* 0x1390: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1395:
	/* 0x1395: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1398:
	/* 0x1398: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139a:
	/* 0x139a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139c:
	/* 0x139c: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x139c, 0x18d2, x86_l_18d2);
x86_l_13a1:
	/* 0x13a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a3:
	/* 0x13a3: jmp    18d6 <generic_kprobe_actions+0x18d6> */
	X86_SIM_X86_JMP(0x13a3, 0x18d6, x86_l_18d6);
x86_l_13a8:
	/* 0x13a8: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_13ad:
	/* 0x13ad: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13b2:
	/* 0x13b2: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_13b5:
	/* 0x13b5: je     18a8 <generic_kprobe_actions+0x18a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b5, 0x18a8, x86_l_18a8);
x86_l_13bb:
	/* 0x13bb: mov    eax,DWORD PTR [r13+r15*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 16ULL);
x86_l_13c0:
	/* 0x13c0: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_13c5:
	/* 0x13c5: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_13ca:
	/* 0x13ca: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_13ce:
	/* 0x13ce: ja     13df <generic_kprobe_actions+0x13df> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13ce, 0x13df, x86_l_13df);
x86_l_13d0:
	/* 0x13d0: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_13d9:
	/* 0x13d9: je     198d <generic_kprobe_actions+0x198d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13d9, 0x198d, x86_l_198d);
x86_l_13df:
	/* 0x13df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e1:
	/* 0x13e1: mov    r13d,DWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13e5:
	/* 0x13e5: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13e8:
	/* 0x13e8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_13ed:
	/* 0x13ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ef:
	/* 0x13ef: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13f4:
	/* 0x13f4: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13fa:
	/* 0x13fa: mov    WORD PTR [rsp+0x22],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1400:
	/* 0x1400: mov    QWORD PTR [rsp+0x24],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1405:
	/* 0x1405: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_140c:
	/* 0x140c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1411:
	/* 0x1411: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1416:
	/* 0x1416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1418:
	/* 0x1418: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_141b:
	/* 0x141b: je     1720 <generic_kprobe_actions+0x1720> */
	X86_SIM_X86_JCC(X86_CC_E, 0x141b, 0x1720, x86_l_1720);
x86_l_1421:
	/* 0x1421: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1424:
	/* 0x1424: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1428:
	/* 0x1428: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_142d:
	/* 0x142d: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_1435:
	/* 0x1435: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_143c:
	/* 0x143c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1441:
	/* 0x1441: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1446:
	/* 0x1446: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1448:
	/* 0x1448: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_1450:
	/* 0x1450: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1453:
	/* 0x1453: je     17e9 <generic_kprobe_actions+0x17e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1453, 0x17e9, x86_l_17e9);
x86_l_1459:
	/* 0x1459: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_145c:
	/* 0x145c: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1460:
	/* 0x1460: mov    DWORD PTR [r15+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1464:
	/* 0x1464: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1469:
	/* 0x1469: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146c:
	/* 0x146c: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1471:
	/* 0x1471: jmp    18a3 <generic_kprobe_actions+0x18a3> */
	X86_SIM_X86_JMP(0x1471, 0x18a3, x86_l_18a3);
x86_l_1476:
	/* 0x1476: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_147b:
	/* 0x147b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147d:
	/* 0x147d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1482:
	/* 0x1482: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1489:
	/* 0x1489: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_148e:
	/* 0x148e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1493:
	/* 0x1493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1495:
	/* 0x1495: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1498:
	/* 0x1498: je     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1498, 0x18d2, x86_l_18d2);
x86_l_149e:
	/* 0x149e: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14a2:
	/* 0x14a2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14a7:
	/* 0x14a7: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_14af:
	/* 0x14af: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_14b6:
	/* 0x14b6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14bb:
	/* 0x14bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c0:
	/* 0x14c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c2:
	/* 0x14c2: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_14ca:
	/* 0x14ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14cd:
	/* 0x14cd: je     15ca <generic_kprobe_actions+0x15ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14cd, 0x15ca, x86_l_15ca);
x86_l_14d3:
	/* 0x14d3: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14d6:
	/* 0x14d6: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_14dd:
	/* 0x14dd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14e2:
	/* 0x14e2: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14e7:
	/* 0x14e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e9:
	/* 0x14e9: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x14e9, 0x18d2, x86_l_18d2);
x86_l_14ee:
	/* 0x14ee: cmp    DWORD PTR [r13+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_14f4:
	/* 0x14f4: je     1517 <generic_kprobe_actions+0x1517> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f4, 0x1517, x86_l_1517);
x86_l_14f6:
	/* 0x14f6: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_14fb:
	/* 0x14fb: mov    rsi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1502:
	/* 0x1502: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1504:
	/* 0x1504: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1509:
	/* 0x1509: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150e:
	/* 0x150e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1510:
	/* 0x1510: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1517:
	/* 0x1517: cmp    DWORD PTR [r13+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_151d:
	/* 0x151d: je     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x151d, 0x18d2, x86_l_18d2);
x86_l_1523:
	/* 0x1523: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_1528:
	/* 0x1528: mov    rsi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_152f:
	/* 0x152f: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1534:
	/* 0x1534: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1539:
	/* 0x1539: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_153e:
	/* 0x153e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1541:
	/* 0x1541: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1543:
	/* 0x1543: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_154a:
	/* 0x154a: jmp    18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JMP(0x154a, 0x18d2, x86_l_18d2);
x86_l_154f:
	/* 0x154f: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1554:
	/* 0x1554: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1559:
	/* 0x1559: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_155c:
	/* 0x155c: je     18a8 <generic_kprobe_actions+0x18a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x155c, 0x18a8, x86_l_18a8);
x86_l_1562:
	/* 0x1562: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_1567:
	/* 0x1567: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_156b:
	/* 0x156b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1570:
	/* 0x1570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1572:
	/* 0x1572: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1577:
	/* 0x1577: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_157e:
	/* 0x157e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1583:
	/* 0x1583: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1588:
	/* 0x1588: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158a:
	/* 0x158a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_158d:
	/* 0x158d: je     1785 <generic_kprobe_actions+0x1785> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158d, 0x1785, x86_l_1785);
x86_l_1593:
	/* 0x1593: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1596:
	/* 0x1596: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_159e:
	/* 0x159e: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_15a7:
	/* 0x15a7: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_15ae:
	/* 0x15ae: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15b3:
	/* 0x15b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b8:
	/* 0x15b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ba:
	/* 0x15ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15bd:
	/* 0x15bd: je     1873 <generic_kprobe_actions+0x1873> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15bd, 0x1873, x86_l_1873);
x86_l_15c3:
	/* 0x15c3: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_15c5:
	/* 0x15c5: jmp    1897 <generic_kprobe_actions+0x1897> */
	X86_SIM_X86_JMP(0x15c5, 0x1897, x86_l_1897);
x86_l_15ca:
	/* 0x15ca: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_15d1:
	/* 0x15d1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15d6:
	/* 0x15d6: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15db:
	/* 0x15db: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15e0:
	/* 0x15e0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15e5:
	/* 0x15e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e7:
	/* 0x15e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15ea:
	/* 0x15ea: je     14d6 <generic_kprobe_actions+0x14d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ea, 0x14d6, x86_l_14d6);
x86_l_15f0:
	/* 0x15f0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15f3:
	/* 0x15f3: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15f5:
	/* 0x15f5: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15fa:
	/* 0x15fa: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_1601:
	/* 0x1601: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_160b:
	/* 0x160b: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1610:
	/* 0x1610: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1617:
	/* 0x1617: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_161c:
	/* 0x161c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1621:
	/* 0x1621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1623:
	/* 0x1623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1626:
	/* 0x1626: je     19d4 <generic_kprobe_actions+0x19d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1626, 0x19d4, x86_l_19d4);
x86_l_162c:
	/* 0x162c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_162e:
	/* 0x162e: jmp    19f8 <generic_kprobe_actions+0x19f8> */
	X86_SIM_X86_JMP(0x162e, 0x19f8, x86_l_19f8);
x86_l_1633:
	/* 0x1633: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_163a:
	/* 0x163a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_163f:
	/* 0x163f: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1644:
	/* 0x1644: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1646:
	/* 0x1646: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1648:
	/* 0x1648: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_164d:
	/* 0x164d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1650:
	/* 0x1650: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1655:
	/* 0x1655: jne    108c <generic_kprobe_actions+0x108c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1655, 0x108c, x86_l_108c);
x86_l_165b:
	/* 0x165b: jmp    1082 <generic_kprobe_actions+0x1082> */
	X86_SIM_X86_JMP(0x165b, 0x1082, x86_l_1082);
x86_l_1660:
	/* 0x1660: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1667:
	/* 0x1667: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_166c:
	/* 0x166c: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1671:
	/* 0x1671: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1676:
	/* 0x1676: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_167b:
	/* 0x167b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167d:
	/* 0x167d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1680:
	/* 0x1680: je     d97 <generic_kprobe_actions+0xd97> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1680, 0xd97, x86_l_d97);
x86_l_1686:
	/* 0x1686: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1689:
	/* 0x1689: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_168b:
	/* 0x168b: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1690:
	/* 0x1690: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_1697:
	/* 0x1697: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_16a1:
	/* 0x16a1: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_16a6:
	/* 0x16a6: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16ad:
	/* 0x16ad: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b2:
	/* 0x16b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16b7:
	/* 0x16b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b9:
	/* 0x16b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16bc:
	/* 0x16bc: je     1a29 <generic_kprobe_actions+0x1a29> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16bc, 0x1a29, x86_l_1a29);
x86_l_16c2:
	/* 0x16c2: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16c4:
	/* 0x16c4: jmp    1a4d <generic_kprobe_actions+0x1a4d> */
	X86_SIM_X86_JMP(0x16c4, 0x1a4d, x86_l_1a4d);
x86_l_16c9:
	/* 0x16c9: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_16d1:
	/* 0x16d1: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_16d8:
	/* 0x16d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16da:
	/* 0x16da: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16df:
	/* 0x16df: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16e4:
	/* 0x16e4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16e9:
	/* 0x16e9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16eb:
	/* 0x16eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ed:
	/* 0x16ed: cmp    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_16f2:
	/* 0x16f2: je     3b9 <generic_kprobe_actions+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f2, 0x3b9, x86_l_3b9);
x86_l_16f8:
	/* 0x16f8: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_16ff:
	/* 0x16ff: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1704:
	/* 0x1704: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1709:
	/* 0x1709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170b:
	/* 0x170b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170e:
	/* 0x170e: je     3b9 <generic_kprobe_actions+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170e, 0x3b9, x86_l_3b9);
x86_l_1714:
	/* 0x1714: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1718:
	/* 0x1718: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_171b:
	/* 0x171b: jmp    3b9 <generic_kprobe_actions+0x3b9> */
	X86_SIM_X86_JMP(0x171b, 0x3b9, x86_l_3b9);
x86_l_1720:
	/* 0x1720: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1727:
	/* 0x1727: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1729:
	/* 0x1729: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_172e:
	/* 0x172e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1733:
	/* 0x1733: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1738:
	/* 0x1738: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_173a:
	/* 0x173a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173c:
	/* 0x173c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173f:
	/* 0x173f: je     146c <generic_kprobe_actions+0x146c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x173f, 0x146c, x86_l_146c);
x86_l_1745:
	/* 0x1745: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1747:
	/* 0x1747: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_174c:
	/* 0x174c: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_1753:
	/* 0x1753: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_175d:
	/* 0x175d: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1762:
	/* 0x1762: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1769:
	/* 0x1769: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176e:
	/* 0x176e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1773:
	/* 0x1773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1775:
	/* 0x1775: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1778:
	/* 0x1778: je     1a7d <generic_kprobe_actions+0x1a7d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1778, 0x1a7d, x86_l_1a7d);
x86_l_177e:
	/* 0x177e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1780:
	/* 0x1780: jmp    146c <generic_kprobe_actions+0x146c> */
	X86_SIM_X86_JMP(0x1780, 0x146c, x86_l_146c);
x86_l_1785:
	/* 0x1785: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_178c:
	/* 0x178c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178e:
	/* 0x178e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1793:
	/* 0x1793: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1798:
	/* 0x1798: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_179d:
	/* 0x179d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_179f:
	/* 0x179f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a1:
	/* 0x17a1: jmp    189e <generic_kprobe_actions+0x189e> */
	X86_SIM_X86_JMP(0x17a1, 0x189e, x86_l_189e);
x86_l_17a6:
	/* 0x17a6: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_17ae:
	/* 0x17ae: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_17b3:
	/* 0x17b3: mov    r14,QWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_17bb:
	/* 0x17bb: jmp    d17 <generic_kprobe_actions+0xd17> */
	X86_SIM_X86_JMP(0x17bb, 0xd17, x86_l_d17);
x86_l_17c0:
	/* 0x17c0: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_17c8:
	/* 0x17c8: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_17cf:
	/* 0x17cf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d1:
	/* 0x17d1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d6:
	/* 0x17d6: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17db:
	/* 0x17db: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17e0:
	/* 0x17e0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e2:
	/* 0x17e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e4:
	/* 0x17e4: jmp    538 <generic_kprobe_actions+0x538> */
	X86_SIM_X86_JMP(0x17e4, 0x538, x86_l_538);
x86_l_17e9:
	/* 0x17e9: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_17f0:
	/* 0x17f0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17f5:
	/* 0x17f5: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17fa:
	/* 0x17fa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17ff:
	/* 0x17ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1804:
	/* 0x1804: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1806:
	/* 0x1806: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1809:
	/* 0x1809: je     145c <generic_kprobe_actions+0x145c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1809, 0x145c, x86_l_145c);
x86_l_180f:
	/* 0x180f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1812:
	/* 0x1812: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1814:
	/* 0x1814: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1819:
	/* 0x1819: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_1820:
	/* 0x1820: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_182a:
	/* 0x182a: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_182f:
	/* 0x182f: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1836:
	/* 0x1836: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183b:
	/* 0x183b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1840:
	/* 0x1840: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1842:
	/* 0x1842: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1845:
	/* 0x1845: je     1aa6 <generic_kprobe_actions+0x1aa6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1845, 0x1aa6, x86_l_1aa6);
x86_l_184b:
	/* 0x184b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_184d:
	/* 0x184d: jmp    1aca <generic_kprobe_actions+0x1aca> */
	X86_SIM_X86_JMP(0x184d, 0x1aca, x86_l_1aca);
x86_l_1852:
	/* 0x1852: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1859:
	/* 0x1859: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_185e:
	/* 0x185e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1863:
	/* 0x1863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1865:
	/* 0x1865: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1867:
	/* 0x1867: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_186b:
	/* 0x186b: jne    10f9 <generic_kprobe_actions+0x10f9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x186b, 0x10f9, x86_l_10f9);
x86_l_1871:
	/* 0x1871: jmp    18d6 <generic_kprobe_actions+0x18d6> */
	X86_SIM_X86_JMP(0x1871, 0x18d6, x86_l_18d6);
x86_l_1873:
	/* 0x1873: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_187b:
	/* 0x187b: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1882:
	/* 0x1882: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1884:
	/* 0x1884: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1889:
	/* 0x1889: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_188e:
	/* 0x188e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1893:
	/* 0x1893: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1895:
	/* 0x1895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1897:
	/* 0x1897: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_189b:
	/* 0x189b: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189e:
	/* 0x189e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a3:
	/* 0x18a3: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18a8:
	/* 0x18a8: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18b0:
	/* 0x18b0: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_18b7:
	/* 0x18b7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18bc:
	/* 0x18bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c1:
	/* 0x18c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c3:
	/* 0x18c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18c6:
	/* 0x18c6: je     18d2 <generic_kprobe_actions+0x18d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18c6, 0x18d2, x86_l_18d2);
x86_l_18c8:
	/* 0x18c8: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18cd:
	/* 0x18cd: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_18d2:
	/* 0x18d2: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18d6:
	/* 0x18d6: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18da:
	/* 0x18da: jmp    10f9 <generic_kprobe_actions+0x10f9> */
	X86_SIM_X86_JMP(0x18da, 0x10f9, x86_l_10f9);
x86_l_18df:
	/* 0x18df: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_18e7:
	/* 0x18e7: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_18ee:
	/* 0x18ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f0:
	/* 0x18f0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f5:
	/* 0x18f5: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18fa:
	/* 0x18fa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18ff:
	/* 0x18ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1901:
	/* 0x1901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1903:
	/* 0x1903: cmp    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1908:
	/* 0x1908: je     c10 <generic_kprobe_actions+0xc10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1908, 0xc10, x86_l_c10);
x86_l_190e:
	/* 0x190e: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1915:
	/* 0x1915: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_191a:
	/* 0x191a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_191f:
	/* 0x191f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1921:
	/* 0x1921: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1924:
	/* 0x1924: je     c10 <generic_kprobe_actions+0xc10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1924, 0xc10, x86_l_c10);
x86_l_192a:
	/* 0x192a: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_192e:
	/* 0x192e: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1931:
	/* 0x1931: jmp    c10 <generic_kprobe_actions+0xc10> */
	X86_SIM_X86_JMP(0x1931, 0xc10, x86_l_c10);
x86_l_1936:
	/* 0x1936: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_193e:
	/* 0x193e: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1945:
	/* 0x1945: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1947:
	/* 0x1947: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_194c:
	/* 0x194c: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1951:
	/* 0x1951: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1956:
	/* 0x1956: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1958:
	/* 0x1958: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195a:
	/* 0x195a: cmp    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_195f:
	/* 0x195f: je     528 <generic_kprobe_actions+0x528> */
	X86_SIM_X86_JCC(X86_CC_E, 0x195f, 0x528, x86_l_528);
x86_l_1965:
	/* 0x1965: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_196c:
	/* 0x196c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1971:
	/* 0x1971: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1976:
	/* 0x1976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1978:
	/* 0x1978: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_197b:
	/* 0x197b: je     528 <generic_kprobe_actions+0x528> */
	X86_SIM_X86_JCC(X86_CC_E, 0x197b, 0x528, x86_l_528);
x86_l_1981:
	/* 0x1981: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1985:
	/* 0x1985: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1988:
	/* 0x1988: jmp    528 <generic_kprobe_actions+0x528> */
	X86_SIM_X86_JMP(0x1988, 0x528, x86_l_528);
x86_l_198d:
	/* 0x198d: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1995:
	/* 0x1995: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_199a:
	/* 0x199a: mov    rax,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_19a2:
	/* 0x19a2: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_19a6:
	/* 0x19a6: jmp    13e1 <generic_kprobe_actions+0x13e1> */
	X86_SIM_X86_JMP(0x19a6, 0x13e1, x86_l_13e1);
x86_l_19ab:
	/* 0x19ab: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_19b3:
	/* 0x19b3: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19ba:
	/* 0x19ba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19bc:
	/* 0x19bc: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c1:
	/* 0x19c1: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19c6:
	/* 0x19c6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19cb:
	/* 0x19cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19cd:
	/* 0x19cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cf:
	/* 0x19cf: jmp    da7 <generic_kprobe_actions+0xda7> */
	X86_SIM_X86_JMP(0x19cf, 0xda7, x86_l_da7);
x86_l_19d4:
	/* 0x19d4: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_19dc:
	/* 0x19dc: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_19e3:
	/* 0x19e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e5:
	/* 0x19e5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ea:
	/* 0x19ea: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19ef:
	/* 0x19ef: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19f4:
	/* 0x19f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f6:
	/* 0x19f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f8:
	/* 0x19f8: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_19fb:
	/* 0x19fb: je     14d6 <generic_kprobe_actions+0x14d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19fb, 0x14d6, x86_l_14d6);
x86_l_1a01:
	/* 0x1a01: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1a08:
	/* 0x1a08: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a12:
	/* 0x1a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a14:
	/* 0x1a14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a17:
	/* 0x1a17: je     14d6 <generic_kprobe_actions+0x14d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a17, 0x14d6, x86_l_14d6);
x86_l_1a1d:
	/* 0x1a1d: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a21:
	/* 0x1a21: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a24:
	/* 0x1a24: jmp    14d6 <generic_kprobe_actions+0x14d6> */
	X86_SIM_X86_JMP(0x1a24, 0x14d6, x86_l_14d6);
x86_l_1a29:
	/* 0x1a29: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_1a31:
	/* 0x1a31: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a38:
	/* 0x1a38: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3a:
	/* 0x1a3a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a3f:
	/* 0x1a3f: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a44:
	/* 0x1a44: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a49:
	/* 0x1a49: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a4b:
	/* 0x1a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4d:
	/* 0x1a4d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1a4f:
	/* 0x1a4f: je     d97 <generic_kprobe_actions+0xd97> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a4f, 0xd97, x86_l_d97);
x86_l_1a55:
	/* 0x1a55: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1a5c:
	/* 0x1a5c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a61:
	/* 0x1a61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a66:
	/* 0x1a66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a68:
	/* 0x1a68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a6b:
	/* 0x1a6b: je     d97 <generic_kprobe_actions+0xd97> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6b, 0xd97, x86_l_d97);
x86_l_1a71:
	/* 0x1a71: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a75:
	/* 0x1a75: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a78:
	/* 0x1a78: jmp    d97 <generic_kprobe_actions+0xd97> */
	X86_SIM_X86_JMP(0x1a78, 0xd97, x86_l_d97);
x86_l_1a7d:
	/* 0x1a7d: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1a85:
	/* 0x1a85: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a8c:
	/* 0x1a8c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8e:
	/* 0x1a8e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a93:
	/* 0x1a93: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a98:
	/* 0x1a98: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a9d:
	/* 0x1a9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9f:
	/* 0x1a9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa1:
	/* 0x1aa1: jmp    146c <generic_kprobe_actions+0x146c> */
	X86_SIM_X86_JMP(0x1aa1, 0x146c, x86_l_146c);
x86_l_1aa6:
	/* 0x1aa6: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_1aae:
	/* 0x1aae: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1ab5:
	/* 0x1ab5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab7:
	/* 0x1ab7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1abc:
	/* 0x1abc: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ac6:
	/* 0x1ac6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ac8:
	/* 0x1ac8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aca:
	/* 0x1aca: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1acd:
	/* 0x1acd: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ad2:
	/* 0x1ad2: je     145c <generic_kprobe_actions+0x145c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad2, 0x145c, x86_l_145c);
x86_l_1ad8:
	/* 0x1ad8: mov    rdi,QWORD PTR [rip+0x58c4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1adf:
	/* 0x1adf: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ae9:
	/* 0x1ae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aeb:
	/* 0x1aeb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1aee:
	/* 0x1aee: je     145c <generic_kprobe_actions+0x145c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aee, 0x145c, x86_l_145c);
x86_l_1af4:
	/* 0x1af4: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1af8:
	/* 0x1af8: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1afb:
	/* 0x1afb: jmp    145c <generic_kprobe_actions+0x145c> */
	X86_SIM_X86_JMP(0x1afb, 0x145c, x86_l_145c);
x86_l_1b00:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
