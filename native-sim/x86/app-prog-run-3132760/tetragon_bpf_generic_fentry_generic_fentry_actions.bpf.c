extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char fdinstall_map;
extern char fentry_calls;
extern char filter_map;
extern char heap;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char stack_trace_map;
extern char tg_errmetrics_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_fentry_generic_fentry_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21:
	/* 0x21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     472 <generic_fentry_actions+0x472> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b, 0x472, x86_l_472);
x86_l_31:
	/* 0x31: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    r12d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_3b:
	/* 0x3b: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3f:
	/* 0x3f: jl     472 <generic_fentry_actions+0x472> */
	X86_SIM_X86_JCC(X86_CC_L, 0x3f, 0x472, x86_l_472);
x86_l_45:
	/* 0x45: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_4c:
	/* 0x4c: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_53:
	/* 0x53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58:
	/* 0x58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a:
	/* 0x5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d:
	/* 0x5d: je     472 <generic_fentry_actions+0x472> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d, 0x472, x86_l_472);
x86_l_63:
	/* 0x63: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_66:
	/* 0x66: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6c:
	/* 0x6c: add    r12d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_70:
	/* 0x70: mov    DWORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_78:
	/* 0x78: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_7f:
	/* 0x7f: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_84:
	/* 0x84: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_87:
	/* 0x87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8c:
	/* 0x8c: and    r12d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_93:
	/* 0x93: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_96:
	/* 0x96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98:
	/* 0x98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b:
	/* 0x9b: je     c2 <generic_fentry_actions+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b, 0xc2, x86_l_c2);
x86_l_9d:
	/* 0x9d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0:
	/* 0xa0: je     c2 <generic_fentry_actions+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xc2, x86_l_c2);
x86_l_a2:
	/* 0xa2: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a7:
	/* 0xa7: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_ac:
	/* 0xac: mov    ecx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_b1:
	/* 0xb1: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_b6:
	/* 0xb6: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bb:
	/* 0xbb: ja     e1 <generic_fentry_actions+0xe1> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbb, 0xe1, x86_l_e1);
x86_l_bd:
	/* 0xbd: jmp    457 <generic_fentry_actions+0x457> */
	X86_SIM_X86_JMP(0xbd, 0x457, x86_l_457);
x86_l_c2:
	/* 0xc2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c7:
	/* 0xc7: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_cc:
	/* 0xcc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d1:
	/* 0xd1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d6:
	/* 0xd6: cmp    DWORD PTR [r12],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_db:
	/* 0xdb: jbe    457 <generic_fentry_actions+0x457> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xdb, 0x457, x86_l_457);
x86_l_e1:
	/* 0xe1: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e6:
	/* 0xe6: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_eb:
	/* 0xeb: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f0:
	/* 0xf0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f5:
	/* 0xf5: movsxd r15,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_102:
	/* 0x102: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_109:
	/* 0x109: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x118: je     151 <generic_fentry_actions+0x151> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118, 0x151, x86_l_151);
x86_l_11a:
	/* 0x11a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_11d:
	/* 0x11d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120:
	/* 0x120: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_123:
	/* 0x123: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_127:
	/* 0x127: jg     15c <generic_fentry_actions+0x15c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x127, 0x15c, x86_l_15c);
x86_l_129:
	/* 0x129: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_12d:
	/* 0x12d: jg     197 <generic_fentry_actions+0x197> */
	X86_SIM_X86_JCC(X86_CC_G, 0x12d, 0x197, x86_l_197);
x86_l_12f:
	/* 0x12f: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_133:
	/* 0x133: jg     224 <generic_fentry_actions+0x224> */
	X86_SIM_X86_JCC(X86_CC_G, 0x133, 0x224, x86_l_224);
x86_l_139:
	/* 0x139: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_13c:
	/* 0x13c: je     33c <generic_fentry_actions+0x33c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c, 0x33c, x86_l_33c);
x86_l_142:
	/* 0x142: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_146:
	/* 0x146: je     238 <generic_fentry_actions+0x238> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146, 0x238, x86_l_238);
x86_l_14c:
	/* 0x14c: jmp    3d3 <generic_fentry_actions+0x3d3> */
	X86_SIM_X86_JMP(0x14c, 0x3d3, x86_l_3d3);
x86_l_151:
	/* 0x151: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154:
	/* 0x154: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_157:
	/* 0x157: jmp    3dd <generic_fentry_actions+0x3dd> */
	X86_SIM_X86_JMP(0x157, 0x3dd, x86_l_3dd);
x86_l_15c:
	/* 0x15c: cmp    r15d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 11ULL);
x86_l_160:
	/* 0x160: jg     1f6 <generic_fentry_actions+0x1f6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x160, 0x1f6, x86_l_1f6);
x86_l_166:
	/* 0x166: lea    eax,[r15-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_16a:
	/* 0x16a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16d:
	/* 0x16d: jb     29f <generic_fentry_actions+0x29f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x16d, 0x29f, x86_l_29f);
x86_l_173:
	/* 0x173: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_177:
	/* 0x177: je     2aa <generic_fentry_actions+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x177, 0x2aa, x86_l_2aa);
x86_l_17d:
	/* 0x17d: cmp    r15d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 9ULL);
x86_l_181:
	/* 0x181: jne    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x181, 0x3d6, x86_l_3d6);
x86_l_187:
	/* 0x187: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_18d:
	/* 0x18d: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_192:
	/* 0x192: jmp    3ae <generic_fentry_actions+0x3ae> */
	X86_SIM_X86_JMP(0x192, 0x3ae, x86_l_3ae);
x86_l_197:
	/* 0x197: lea    eax,[r15-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_19b:
	/* 0x19b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19e:
	/* 0x19e: jb     296 <generic_fentry_actions+0x296> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19e, 0x296, x86_l_296);
x86_l_1a4:
	/* 0x1a4: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1a8:
	/* 0x1a8: je     2b4 <generic_fentry_actions+0x2b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a8, 0x2b4, x86_l_2b4);
x86_l_1ae:
	/* 0x1ae: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_1b2:
	/* 0x1b2: jne    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2, 0x3d6, x86_l_3d6);
x86_l_1b8:
	/* 0x1b8: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd:
	/* 0x1bd: mov    r13d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c2:
	/* 0x1c2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cb:
	/* 0x1cb: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d4:
	/* 0x1d4: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1d7:
	/* 0x1d7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da:
	/* 0x1da: ja     1eb <generic_fentry_actions+0x1eb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1da, 0x1eb, x86_l_1eb);
x86_l_1dc:
	/* 0x1dc: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1e5:
	/* 0x1e5: je     dcb <generic_fentry_actions+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e5, 0xdcb, x86_l_dcb);
x86_l_1eb:
	/* 0x1eb: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1f1:
	/* 0x1f1: jmp    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JMP(0x1f1, 0x3d6, x86_l_3d6);
x86_l_1f6:
	/* 0x1f6: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_1fa:
	/* 0x1fa: je     3a3 <generic_fentry_actions+0x3a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fa, 0x3a3, x86_l_3a3);
x86_l_200:
	/* 0x200: cmp    r15d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 13ULL);
x86_l_204:
	/* 0x204: je     2c4 <generic_fentry_actions+0x2c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x204, 0x2c4, x86_l_2c4);
x86_l_20a:
	/* 0x20a: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_20e:
	/* 0x20e: jne    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20e, 0x3d6, x86_l_3d6);
x86_l_214:
	/* 0x214: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_21a:
	/* 0x21a: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21f:
	/* 0x21f: jmp    3ae <generic_fentry_actions+0x3ae> */
	X86_SIM_X86_JMP(0x21f, 0x3ae, x86_l_3ae);
x86_l_224:
	/* 0x224: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_228:
	/* 0x228: je     39c <generic_fentry_actions+0x39c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x228, 0x39c, x86_l_39c);
x86_l_22e:
	/* 0x22e: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_232:
	/* 0x232: jne    3d3 <generic_fentry_actions+0x3d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x232, 0x3d3, x86_l_3d3);
x86_l_238:
	/* 0x238: mov    ebp,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d:
	/* 0x23d: mov    r13d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_242:
	/* 0x242: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24b:
	/* 0x24b: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_254:
	/* 0x254: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_25c:
	/* 0x25c: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_263:
	/* 0x263: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_268:
	/* 0x268: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d:
	/* 0x26d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f:
	/* 0x26f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_272:
	/* 0x272: je     28b <generic_fentry_actions+0x28b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x272, 0x28b, x86_l_28b);
x86_l_274:
	/* 0x274: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_277:
	/* 0x277: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_27a:
	/* 0x27a: ja     28b <generic_fentry_actions+0x28b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x27a, 0x28b, x86_l_28b);
x86_l_27c:
	/* 0x27c: cmp    DWORD PTR [r14+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_285:
	/* 0x285: je     ca7 <generic_fentry_actions+0xca7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x285, 0xca7, x86_l_ca7);
x86_l_28b:
	/* 0x28b: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_291:
	/* 0x291: jmp    3d3 <generic_fentry_actions+0x3d3> */
	X86_SIM_X86_JMP(0x291, 0x3d3, x86_l_3d3);
x86_l_296:
	/* 0x296: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b:
	/* 0x29b: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_29f:
	/* 0x29f: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2a5:
	/* 0x2a5: jmp    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JMP(0x2a5, 0x3d6, x86_l_3d6);
x86_l_2aa:
	/* 0x2aa: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ac:
	/* 0x2ac: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2af:
	/* 0x2af: jmp    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JMP(0x2af, 0x3d6, x86_l_3d6);
x86_l_2b4:
	/* 0x2b4: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2ba:
	/* 0x2ba: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bf:
	/* 0x2bf: jmp    3ae <generic_fentry_actions+0x3ae> */
	X86_SIM_X86_JMP(0x2bf, 0x3ae, x86_l_3ae);
x86_l_2c4:
	/* 0x2c4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c9:
	/* 0x2c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb:
	/* 0x2cb: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d0:
	/* 0x2d0: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_2d7:
	/* 0x2d7: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dc:
	/* 0x2dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e1:
	/* 0x2e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e3:
	/* 0x2e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e6:
	/* 0x2e6: je     3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e6, 0x3d6, x86_l_3d6);
x86_l_2ec:
	/* 0x2ec: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f0:
	/* 0x2f0: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f5:
	/* 0x2f5: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_2fd:
	/* 0x2fd: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_304:
	/* 0x304: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_309:
	/* 0x309: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: mov    DWORD PTR [rsp+0x1c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084289ULL);
x86_l_318:
	/* 0x318: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31b:
	/* 0x31b: je     d60 <generic_fentry_actions+0xd60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31b, 0xd60, x86_l_d60);
x86_l_321:
	/* 0x321: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_324:
	/* 0x324: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_32b:
	/* 0x32b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_330:
	/* 0x330: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_335:
	/* 0x335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337:
	/* 0x337: jmp    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JMP(0x337, 0x3d6, x86_l_3d6);
x86_l_33c:
	/* 0x33c: cmp    DWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_342:
	/* 0x342: je     365 <generic_fentry_actions+0x365> */
	X86_SIM_X86_JCC(X86_CC_E, 0x342, 0x365, x86_l_365);
x86_l_344:
	/* 0x344: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_349:
	/* 0x349: mov    rsi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_350:
	/* 0x350: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_352:
	/* 0x352: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_357:
	/* 0x357: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_35a:
	/* 0x35a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35c:
	/* 0x35c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e:
	/* 0x35e: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_365:
	/* 0x365: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_36b:
	/* 0x36b: cmp    DWORD PTR [r12+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_371:
	/* 0x371: je     3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x371, 0x3d6, x86_l_3d6);
x86_l_373:
	/* 0x373: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_378:
	/* 0x378: mov    rsi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_37f:
	/* 0x37f: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_384:
	/* 0x384: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_389:
	/* 0x389: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_38e:
	/* 0x38e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_391:
	/* 0x391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393:
	/* 0x393: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_39a:
	/* 0x39a: jmp    3d6 <generic_fentry_actions+0x3d6> */
	X86_SIM_X86_JMP(0x39a, 0x3d6, x86_l_3d6);
x86_l_39c:
	/* 0x39c: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a1:
	/* 0x3a1: jmp    3ae <generic_fentry_actions+0x3ae> */
	X86_SIM_X86_JMP(0x3a1, 0x3ae, x86_l_3ae);
x86_l_3a3:
	/* 0x3a3: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_3a9:
	/* 0x3a9: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ae:
	/* 0x3ae: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3b6:
	/* 0x3b6: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_3bd:
	/* 0x3bd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c2:
	/* 0x3c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c7:
	/* 0x3c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9:
	/* 0x3c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cc:
	/* 0x3cc: je     3d3 <generic_fentry_actions+0x3d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cc, 0x3d3, x86_l_3d3);
x86_l_3ce:
	/* 0x3ce: inc QWORD PTR [rax+rbp*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBP, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3d3:
	/* 0x3d3: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_3d6:
	/* 0x3d6: mov    QWORD PTR [r14+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3da:
	/* 0x3da: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3dd:
	/* 0x3dd: lea    eax,[r13*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_3e5:
	/* 0x3e5: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_3e9:
	/* 0x3e9: jae    452 <generic_fentry_actions+0x452> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3e9, 0x452, x86_l_452);
x86_l_3eb:
	/* 0x3eb: mov    DWORD PTR [rsp+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ef:
	/* 0x3ef: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_3f2:
	/* 0x3f2: movsxd r15,DWORD PTR [r12+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_3f7:
	/* 0x3f7: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3ff:
	/* 0x3ff: mov    rdi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_406:
	/* 0x406: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_40b:
	/* 0x40b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_410:
	/* 0x410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412:
	/* 0x412: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_414:
	/* 0x414: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_417:
	/* 0x417: je     8b2 <generic_fentry_actions+0x8b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0x8b2, x86_l_8b2);
x86_l_41d:
	/* 0x41d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_420:
	/* 0x420: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_424:
	/* 0x424: jg     483 <generic_fentry_actions+0x483> */
	X86_SIM_X86_JCC(X86_CC_G, 0x424, 0x483, x86_l_483);
x86_l_426:
	/* 0x426: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_42a:
	/* 0x42a: jg     4be <generic_fentry_actions+0x4be> */
	X86_SIM_X86_JCC(X86_CC_G, 0x42a, 0x4be, x86_l_4be);
x86_l_430:
	/* 0x430: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_434:
	/* 0x434: jg     602 <generic_fentry_actions+0x602> */
	X86_SIM_X86_JCC(X86_CC_G, 0x434, 0x602, x86_l_602);
x86_l_43a:
	/* 0x43a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_43d:
	/* 0x43d: je     802 <generic_fentry_actions+0x802> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43d, 0x802, x86_l_802);
x86_l_443:
	/* 0x443: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_447:
	/* 0x447: je     616 <generic_fentry_actions+0x616> */
	X86_SIM_X86_JCC(X86_CC_E, 0x447, 0x616, x86_l_616);
x86_l_44d:
	/* 0x44d: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x44d, 0x8a8, x86_l_8a8);
x86_l_452:
	/* 0x452: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_455:
	/* 0x455: je     472 <generic_fentry_actions+0x472> */
	X86_SIM_X86_JCC(X86_CC_E, 0x455, 0x472, x86_l_472);
x86_l_457:
	/* 0x457: mov    rsi,QWORD PTR [rip+0x9d17] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fentry_calls)));
x86_l_45e:
	/* 0x45e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_463:
	/* 0x463: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_468:
	/* 0x468: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_46b:
	/* 0x46b: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_470:
	/* 0x470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_472:
	/* 0x472: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_474:
	/* 0x474: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_47b:
	/* 0x47b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_47d:
	/* 0x47d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_47e:
	/* 0x47e: jmp    10be <generic_fentry_actions+0x10be> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_483:
	/* 0x483: cmp    r15d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 11ULL);
x86_l_487:
	/* 0x487: jg     5d3 <generic_fentry_actions+0x5d3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x487, 0x5d3, x86_l_5d3);
x86_l_48d:
	/* 0x48d: lea    eax,[r15-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_491:
	/* 0x491: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_494:
	/* 0x494: jb     753 <generic_fentry_actions+0x753> */
	X86_SIM_X86_JCC(X86_CC_B, 0x494, 0x753, x86_l_753);
x86_l_49a:
	/* 0x49a: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_49e:
	/* 0x49e: je     76b <generic_fentry_actions+0x76b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49e, 0x76b, x86_l_76b);
x86_l_4a4:
	/* 0x4a4: cmp    r15d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 9ULL);
x86_l_4a8:
	/* 0x4a8: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a8, 0x8a8, x86_l_8a8);
x86_l_4ae:
	/* 0x4ae: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4b4:
	/* 0x4b4: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b9:
	/* 0x4b9: jmp    880 <generic_fentry_actions+0x880> */
	X86_SIM_X86_JMP(0x4b9, 0x880, x86_l_880);
x86_l_4be:
	/* 0x4be: lea    eax,[r15-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_4c2:
	/* 0x4c2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c5:
	/* 0x4c5: jb     75b <generic_fentry_actions+0x75b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4c5, 0x75b, x86_l_75b);
x86_l_4cb:
	/* 0x4cb: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4cf:
	/* 0x4cf: je     778 <generic_fentry_actions+0x778> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cf, 0x778, x86_l_778);
x86_l_4d5:
	/* 0x4d5: cmp    r15d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 5ULL);
x86_l_4d9:
	/* 0x4d9: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4d9, 0x8a8, x86_l_8a8);
x86_l_4df:
	/* 0x4df: mov    eax,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_4e4:
	/* 0x4e4: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4e8:
	/* 0x4e8: mov    ebp,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4f6:
	/* 0x4f6: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4ff:
	/* 0x4ff: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_502:
	/* 0x502: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_505:
	/* 0x505: ja     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x505, 0x8a8, x86_l_8a8);
x86_l_50b:
	/* 0x50b: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_513:
	/* 0x513: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x513, 0x8a8, x86_l_8a8);
x86_l_519:
	/* 0x519: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_521:
	/* 0x521: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_526:
	/* 0x526: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_52d:
	/* 0x52d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_531:
	/* 0x531: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_536:
	/* 0x536: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_539:
	/* 0x539: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53b:
	/* 0x53b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_53f:
	/* 0x53f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_544:
	/* 0x544: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_54b:
	/* 0x54b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_550:
	/* 0x550: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_555:
	/* 0x555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_557:
	/* 0x557: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_55a:
	/* 0x55a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55d:
	/* 0x55d: je     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x55d, 0x8a8, x86_l_8a8);
x86_l_563:
	/* 0x563: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_566:
	/* 0x566: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_569:
	/* 0x569: ja     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x569, 0x8a8, x86_l_8a8);
x86_l_56f:
	/* 0x56f: cmp    DWORD PTR [rdx+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_577:
	/* 0x577: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x577, 0x8a8, x86_l_8a8);
x86_l_57d:
	/* 0x57d: mov    rcx,QWORD PTR [rdx+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_585:
	/* 0x585: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_58d:
	/* 0x58d: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_593:
	/* 0x593: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_59a:
	/* 0x59a: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59e:
	/* 0x59e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5a1:
	/* 0x5a1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5a6:
	/* 0x5a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a8:
	/* 0x5a8: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b1:
	/* 0x5b1: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_5b8:
	/* 0x5b8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ba:
	/* 0x5ba: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bf:
	/* 0x5bf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c4:
	/* 0x5c4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5c7:
	/* 0x5c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c9:
	/* 0x5c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cb:
	/* 0x5cb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5ce:
	/* 0x5ce: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x5ce, 0x8a8, x86_l_8a8);
x86_l_5d3:
	/* 0x5d3: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_5d7:
	/* 0x5d7: je     874 <generic_fentry_actions+0x874> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d7, 0x874, x86_l_874);
x86_l_5dd:
	/* 0x5dd: cmp    r15d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 13ULL);
x86_l_5e1:
	/* 0x5e1: je     788 <generic_fentry_actions+0x788> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e1, 0x788, x86_l_788);
x86_l_5e7:
	/* 0x5e7: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_5eb:
	/* 0x5eb: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5eb, 0x8a8, x86_l_8a8);
x86_l_5f1:
	/* 0x5f1: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_5f4:
	/* 0x5f4: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_5f8:
	/* 0x5f8: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5fd:
	/* 0x5fd: jmp    880 <generic_fentry_actions+0x880> */
	X86_SIM_X86_JMP(0x5fd, 0x880, x86_l_880);
x86_l_602:
	/* 0x602: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_606:
	/* 0x606: je     86a <generic_fentry_actions+0x86a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x606, 0x86a, x86_l_86a);
x86_l_60c:
	/* 0x60c: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_610:
	/* 0x610: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x610, 0x8a8, x86_l_8a8);
x86_l_616:
	/* 0x616: mov    r14d,DWORD PTR [r12+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_61b:
	/* 0x61b: add    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_61f:
	/* 0x61f: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_624:
	/* 0x624: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_62c:
	/* 0x62c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_635:
	/* 0x635: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_63e:
	/* 0x63e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_646:
	/* 0x646: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_64d:
	/* 0x64d: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_652:
	/* 0x652: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_657:
	/* 0x657: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65c:
	/* 0x65c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65e:
	/* 0x65e: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_663:
	/* 0x663: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_666:
	/* 0x666: je     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x666, 0x8a8, x86_l_8a8);
x86_l_66c:
	/* 0x66c: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_670:
	/* 0x670: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_674:
	/* 0x674: ja     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x674, 0x8a8, x86_l_8a8);
x86_l_67a:
	/* 0x67a: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_683:
	/* 0x683: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x683, 0x8a8, x86_l_8a8);
x86_l_689:
	/* 0x689: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_68e:
	/* 0x68e: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_696:
	/* 0x696: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_69e:
	/* 0x69e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_6a3:
	/* 0x6a3: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_6aa:
	/* 0x6aa: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ae:
	/* 0x6ae: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6b3:
	/* 0x6b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b5:
	/* 0x6b5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6b9:
	/* 0x6b9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6be:
	/* 0x6be: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_6c2:
	/* 0x6c2: jne    f79 <generic_fentry_actions+0xf79> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6c2, 0xf79, x86_l_f79);
x86_l_6c8:
	/* 0x6c8: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6d0:
	/* 0x6d0: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d3:
	/* 0x6d3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6d6:
	/* 0x6d6: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6db:
	/* 0x6db: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6e0:
	/* 0x6e0: ja     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6e0, 0x8a8, x86_l_8a8);
x86_l_6e6:
	/* 0x6e6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6e9:
	/* 0x6e9: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_6f1:
	/* 0x6f1: jne    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6f1, 0x8a8, x86_l_8a8);
x86_l_6f7:
	/* 0x6f7: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_6ff:
	/* 0x6ff: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_705:
	/* 0x705: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_708:
	/* 0x708: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_70f:
	/* 0x70f: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_714:
	/* 0x714: mov    esi,DWORD PTR [rsi+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_71b:
	/* 0x71b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_721:
	/* 0x721: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_725:
	/* 0x725: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_72a:
	/* 0x72a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_72d:
	/* 0x72d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72f:
	/* 0x72f: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_736:
	/* 0x736: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_738:
	/* 0x738: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73d:
	/* 0x73d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_742:
	/* 0x742: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_745:
	/* 0x745: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_74e:
	/* 0x74e: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x74e, 0x8a8, x86_l_8a8);
x86_l_753:
	/* 0x753: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_756:
	/* 0x756: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x756, 0x8a8, x86_l_8a8);
x86_l_75b:
	/* 0x75b: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_75e:
	/* 0x75e: mov    eax,DWORD PTR [r12+r13*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 4ULL);
x86_l_763:
	/* 0x763: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_766:
	/* 0x766: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x766, 0x8a8, x86_l_8a8);
x86_l_76b:
	/* 0x76b: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_773:
	/* 0x773: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x773, 0x8a8, x86_l_8a8);
x86_l_778:
	/* 0x778: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_77b:
	/* 0x77b: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_77e:
	/* 0x77e: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_783:
	/* 0x783: jmp    880 <generic_fentry_actions+0x880> */
	X86_SIM_X86_JMP(0x783, 0x880, x86_l_880);
x86_l_788:
	/* 0x788: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_78b:
	/* 0x78b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_790:
	/* 0x790: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_792:
	/* 0x792: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_797:
	/* 0x797: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_79e:
	/* 0x79e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7a3:
	/* 0x7a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a8:
	/* 0x7a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7aa:
	/* 0x7aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ad:
	/* 0x7ad: je     7fa <generic_fentry_actions+0x7fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ad, 0x7fa, x86_l_7fa);
x86_l_7af:
	/* 0x7af: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7b3:
	/* 0x7b3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b8:
	/* 0x7b8: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_7c0:
	/* 0x7c0: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7c7:
	/* 0x7c7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7cc:
	/* 0x7cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d1:
	/* 0x7d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d3:
	/* 0x7d3: mov    DWORD PTR [rsp+0x1c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084289ULL);
x86_l_7db:
	/* 0x7db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7de:
	/* 0x7de: je     ea7 <generic_fentry_actions+0xea7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7de, 0xea7, x86_l_ea7);
x86_l_7e4:
	/* 0x7e4: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7e7:
	/* 0x7e7: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_7ee:
	/* 0x7ee: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7f3:
	/* 0x7f3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_7f8:
	/* 0x7f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fa:
	/* 0x7fa: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_7fd:
	/* 0x7fd: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x7fd, 0x8a8, x86_l_8a8);
x86_l_802:
	/* 0x802: cmp    DWORD PTR [r12+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_808:
	/* 0x808: je     830 <generic_fentry_actions+0x830> */
	X86_SIM_X86_JCC(X86_CC_E, 0x808, 0x830, x86_l_830);
x86_l_80a:
	/* 0x80a: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_80e:
	/* 0x80e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_811:
	/* 0x811: mov    rsi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_818:
	/* 0x818: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_81a:
	/* 0x81a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_81f:
	/* 0x81f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_822:
	/* 0x822: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_824:
	/* 0x824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_826:
	/* 0x826: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_829:
	/* 0x829: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_830:
	/* 0x830: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_834:
	/* 0x834: cmp    DWORD PTR [r12+r13*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 17179869184ULL);
x86_l_83a:
	/* 0x83a: je     8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83a, 0x8a8, x86_l_8a8);
x86_l_83c:
	/* 0x83c: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_840:
	/* 0x840: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_843:
	/* 0x843: mov    rsi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_84a:
	/* 0x84a: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_84f:
	/* 0x84f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_854:
	/* 0x854: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_859:
	/* 0x859: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_85c:
	/* 0x85c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85e:
	/* 0x85e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_861:
	/* 0x861: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_868:
	/* 0x868: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0x868, 0x8a8, x86_l_8a8);
x86_l_86a:
	/* 0x86a: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_86d:
	/* 0x86d: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_872:
	/* 0x872: jmp    880 <generic_fentry_actions+0x880> */
	X86_SIM_X86_JMP(0x872, 0x880, x86_l_880);
x86_l_874:
	/* 0x874: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_877:
	/* 0x877: add    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_87b:
	/* 0x87b: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_880:
	/* 0x880: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_888:
	/* 0x888: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_88f:
	/* 0x88f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_894:
	/* 0x894: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_899:
	/* 0x899: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89b:
	/* 0x89b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89e:
	/* 0x89e: je     8a5 <generic_fentry_actions+0x8a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89e, 0x8a5, x86_l_8a5);
x86_l_8a0:
	/* 0x8a0: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8a5:
	/* 0x8a5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8a8:
	/* 0x8a8: mov    QWORD PTR [rdx+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8ac:
	/* 0x8ac: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_8af:
	/* 0x8af: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_8b2:
	/* 0x8b2: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_8b9:
	/* 0x8b9: cmp    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_8bd:
	/* 0x8bd: jae    c95 <generic_fentry_actions+0xc95> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x8bd, 0xc95, x86_l_c95);
x86_l_8c3:
	/* 0x8c3: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_8c6:
	/* 0x8c6: movsxd rbp,DWORD PTR [r12+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_8cb:
	/* 0x8cb: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_8d3:
	/* 0x8d3: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_8da:
	/* 0x8da: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8df:
	/* 0x8df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8e4:
	/* 0x8e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e6:
	/* 0x8e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8e9:
	/* 0x8e9: je     c95 <generic_fentry_actions+0xc95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e9, 0xc95, x86_l_c95);
x86_l_8ef:
	/* 0x8ef: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8f2:
	/* 0x8f2: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_8f5:
	/* 0x8f5: jle    916 <generic_fentry_actions+0x916> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x8f5, 0x916, x86_l_916);
x86_l_8f7:
	/* 0x8f7: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_8fa:
	/* 0x8fa: jg     93f <generic_fentry_actions+0x93f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8fa, 0x93f, x86_l_93f);
x86_l_8fc:
	/* 0x8fc: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_8ff:
	/* 0x8ff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_902:
	/* 0x902: jb     a6d <generic_fentry_actions+0xa6d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x902, 0xa6d, x86_l_a6d);
x86_l_908:
	/* 0x908: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_90b:
	/* 0x90b: je     b88 <generic_fentry_actions+0xb88> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90b, 0xb88, x86_l_b88);
x86_l_911:
	/* 0x911: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_914:
	/* 0x914: jmp    92f <generic_fentry_actions+0x92f> */
	X86_SIM_X86_JMP(0x914, 0x92f, x86_l_92f);
x86_l_916:
	/* 0x916: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_919:
	/* 0x919: jg     969 <generic_fentry_actions+0x969> */
	X86_SIM_X86_JCC(X86_CC_G, 0x919, 0x969, x86_l_969);
x86_l_91b:
	/* 0x91b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_91d:
	/* 0x91d: je     c0d <generic_fentry_actions+0xc0d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91d, 0xc0d, x86_l_c0d);
x86_l_923:
	/* 0x923: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_926:
	/* 0x926: je     a7b <generic_fentry_actions+0xa7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x926, 0xa7b, x86_l_a7b);
x86_l_92c:
	/* 0x92c: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_92f:
	/* 0x92f: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_934:
	/* 0x934: je     c6c <generic_fentry_actions+0xc6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x934, 0xc6c, x86_l_c6c);
x86_l_93a:
	/* 0x93a: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0x93a, 0xc91, x86_l_c91);
x86_l_93f:
	/* 0x93f: mov    r15,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_944:
	/* 0x944: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_947:
	/* 0x947: je     c6c <generic_fentry_actions+0xc6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x947, 0xc6c, x86_l_c6c);
x86_l_94d:
	/* 0x94d: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_950:
	/* 0x950: je     b95 <generic_fentry_actions+0xb95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x950, 0xb95, x86_l_b95);
x86_l_956:
	/* 0x956: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_95b:
	/* 0x95b: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_95e:
	/* 0x95e: je     c6c <generic_fentry_actions+0xc6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95e, 0xc6c, x86_l_c6c);
x86_l_964:
	/* 0x964: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0x964, 0xc91, x86_l_c91);
x86_l_969:
	/* 0x969: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_96c:
	/* 0x96c: je     a7b <generic_fentry_actions+0xa7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96c, 0xa7b, x86_l_a7b);
x86_l_972:
	/* 0x972: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_975:
	/* 0x975: je     c67 <generic_fentry_actions+0xc67> */
	X86_SIM_X86_JCC(X86_CC_E, 0x975, 0xc67, x86_l_c67);
x86_l_97b:
	/* 0x97b: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_97e:
	/* 0x97e: jne    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x97e, 0xc91, x86_l_c91);
x86_l_984:
	/* 0x984: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_989:
	/* 0x989: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_98e:
	/* 0x98e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_997:
	/* 0x997: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_9a0:
	/* 0x9a0: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_9a3:
	/* 0x9a3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9a6:
	/* 0x9a6: ja     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9a6, 0xc91, x86_l_c91);
x86_l_9ac:
	/* 0x9ac: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_9b5:
	/* 0x9b5: jne    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b5, 0xc91, x86_l_c91);
x86_l_9bb:
	/* 0x9bb: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_9c3:
	/* 0x9c3: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9c8:
	/* 0x9c8: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_9d0:
	/* 0x9d0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d4:
	/* 0x9d4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9d9:
	/* 0x9d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9db:
	/* 0x9db: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_9df:
	/* 0x9df: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e4:
	/* 0x9e4: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9eb:
	/* 0x9eb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f0:
	/* 0x9f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f5:
	/* 0x9f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f7:
	/* 0x9f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9fa:
	/* 0x9fa: je     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9fa, 0xc91, x86_l_c91);
x86_l_a00:
	/* 0xa00: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a04:
	/* 0xa04: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_a08:
	/* 0xa08: ja     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa08, 0xc91, x86_l_c91);
x86_l_a0e:
	/* 0xa0e: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_a17:
	/* 0xa17: jne    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa17, 0xc91, x86_l_c91);
x86_l_a1d:
	/* 0xa1d: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_a25:
	/* 0xa25: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_a2d:
	/* 0xa2d: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a33:
	/* 0xa33: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_a3b:
	/* 0xa3b: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a3f:
	/* 0xa3f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_a42:
	/* 0xa42: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a47:
	/* 0xa47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a49:
	/* 0xa49: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a52:
	/* 0xa52: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_a59:
	/* 0xa59: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5b:
	/* 0xa5b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a60:
	/* 0xa60: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a65:
	/* 0xa65: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a68:
	/* 0xa68: jmp    b7f <generic_fentry_actions+0xb7f> */
	X86_SIM_X86_JMP(0xa68, 0xb7f, x86_l_b7f);
x86_l_a6d:
	/* 0xa6d: mov    eax,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_a72:
	/* 0xa72: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a76:
	/* 0xa76: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0xa76, 0xc91, x86_l_c91);
x86_l_a7b:
	/* 0xa7b: mov    r13d,DWORD PTR [r12+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_a80:
	/* 0xa80: mov    r15d,DWORD PTR [r12+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_a85:
	/* 0xa85: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a8e:
	/* 0xa8e: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a97:
	/* 0xa97: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_a9f:
	/* 0xa9f: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_aa6:
	/* 0xaa6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aab:
	/* 0xaab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab0:
	/* 0xab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab2:
	/* 0xab2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab5:
	/* 0xab5: je     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab5, 0xc91, x86_l_c91);
x86_l_abb:
	/* 0xabb: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_abf:
	/* 0xabf: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_ac3:
	/* 0xac3: ja     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_A, 0xac3, 0xc91, x86_l_c91);
x86_l_ac9:
	/* 0xac9: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_ad2:
	/* 0xad2: jne    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xad2, 0xc91, x86_l_c91);
x86_l_ad8:
	/* 0xad8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_adb:
	/* 0xadb: mov    rax,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_ae3:
	/* 0xae3: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_aeb:
	/* 0xaeb: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_af0:
	/* 0xaf0: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_af8:
	/* 0xaf8: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_afc:
	/* 0xafc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_b01:
	/* 0xb01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b03:
	/* 0xb03: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_b07:
	/* 0xb07: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0c:
	/* 0xb0c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_b0f:
	/* 0xb0f: jne    ff5 <generic_fentry_actions+0xff5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb0f, 0xff5, x86_l_ff5);
x86_l_b15:
	/* 0xb15: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b19:
	/* 0xb19: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b1d:
	/* 0xb1d: ja     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb1d, 0xc91, x86_l_c91);
x86_l_b23:
	/* 0xb23: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_b2c:
	/* 0xb2c: jne    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb2c, 0xc91, x86_l_c91);
x86_l_b32:
	/* 0xb32: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_b3a:
	/* 0xb3a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_b3f:
	/* 0xb3f: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b43:
	/* 0xb43: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_b4a:
	/* 0xb4a: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_b52:
	/* 0xb52: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b58:
	/* 0xb58: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b5c:
	/* 0xb5c: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_b5f:
	/* 0xb5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b64:
	/* 0xb64: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b67:
	/* 0xb67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b69:
	/* 0xb69: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_b70:
	/* 0xb70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b72:
	/* 0xb72: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b77:
	/* 0xb77: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b7c:
	/* 0xb7c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b7f:
	/* 0xb7f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b81:
	/* 0xb81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b83:
	/* 0xb83: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0xb83, 0xc91, x86_l_c91);
x86_l_b88:
	/* 0xb88: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_b90:
	/* 0xb90: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0xb90, 0xc91, x86_l_c91);
x86_l_b95:
	/* 0xb95: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_b9a:
	/* 0xb9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9c:
	/* 0xb9c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ba1:
	/* 0xba1: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_ba8:
	/* 0xba8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bad:
	/* 0xbad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bb2:
	/* 0xbb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb4:
	/* 0xbb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bb7:
	/* 0xbb7: je     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb7, 0xc91, x86_l_c91);
x86_l_bbd:
	/* 0xbbd: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bc1:
	/* 0xbc1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bc6:
	/* 0xbc6: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_bce:
	/* 0xbce: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_bd5:
	/* 0xbd5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bda:
	/* 0xbda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bdf:
	/* 0xbdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be1:
	/* 0xbe1: mov    DWORD PTR [rsp+0x1c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084289ULL);
x86_l_be9:
	/* 0xbe9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bec:
	/* 0xbec: je     f10 <generic_fentry_actions+0xf10> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbec, 0xf10, x86_l_f10);
x86_l_bf2:
	/* 0xbf2: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bf5:
	/* 0xbf5: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_bfc:
	/* 0xbfc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c01:
	/* 0xc01: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c06:
	/* 0xc06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c08:
	/* 0xc08: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0xc08, 0xc91, x86_l_c91);
x86_l_c0d:
	/* 0xc0d: cmp    DWORD PTR [r12+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_c13:
	/* 0xc13: je     c36 <generic_fentry_actions+0xc36> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc13, 0xc36, x86_l_c36);
x86_l_c15:
	/* 0xc15: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_c1a:
	/* 0xc1a: mov    rsi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c21:
	/* 0xc21: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c23:
	/* 0xc23: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c28:
	/* 0xc28: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c2b:
	/* 0xc2b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c2d:
	/* 0xc2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2f:
	/* 0xc2f: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c36:
	/* 0xc36: cmp    DWORD PTR [r12+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_c3c:
	/* 0xc3c: je     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3c, 0xc91, x86_l_c91);
x86_l_c3e:
	/* 0xc3e: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c43:
	/* 0xc43: mov    rsi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c4a:
	/* 0xc4a: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_c4f:
	/* 0xc4f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c54:
	/* 0xc54: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c59:
	/* 0xc59: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c5c:
	/* 0xc5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5e:
	/* 0xc5e: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c65:
	/* 0xc65: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0xc65, 0xc91, x86_l_c91);
x86_l_c67:
	/* 0xc67: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c6c:
	/* 0xc6c: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c74:
	/* 0xc74: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_c7b:
	/* 0xc7b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c80:
	/* 0xc80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c85:
	/* 0xc85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c87:
	/* 0xc87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c8a:
	/* 0xc8a: je     c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8a, 0xc91, x86_l_c91);
x86_l_c8c:
	/* 0xc8c: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c91:
	/* 0xc91: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c95:
	/* 0xc95: mov    ebp,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c99:
	/* 0xc99: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_c9c:
	/* 0xc9c: jne    457 <generic_fentry_actions+0x457> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc9c, 0x457, x86_l_457);
x86_l_ca2:
	/* 0xca2: jmp    472 <generic_fentry_actions+0x472> */
	X86_SIM_X86_JMP(0xca2, 0x472, x86_l_472);
x86_l_ca7:
	/* 0xca7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cac:
	/* 0xcac: mov    rax,QWORD PTR [r14+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_cb4:
	/* 0xcb4: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_cbc:
	/* 0xcbc: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_cc1:
	/* 0xcc1: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_cc9:
	/* 0xcc9: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccd:
	/* 0xccd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cd2:
	/* 0xcd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd4:
	/* 0xcd4: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_cd8:
	/* 0xcd8: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cdd:
	/* 0xcdd: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_ce1:
	/* 0xce1: jne    e81 <generic_fentry_actions+0xe81> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce1, 0xe81, x86_l_e81);
x86_l_ce7:
	/* 0xce7: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ceb:
	/* 0xceb: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_cef:
	/* 0xcef: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cf4:
	/* 0xcf4: ja     28b <generic_fentry_actions+0x28b> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcf4, 0x28b, x86_l_28b);
x86_l_cfa:
	/* 0xcfa: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_d03:
	/* 0xd03: jne    28b <generic_fentry_actions+0x28b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd03, 0x28b, x86_l_28b);
x86_l_d09:
	/* 0xd09: mov    rcx,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_d11:
	/* 0xd11: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_d17:
	/* 0xd17: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_d1b:
	/* 0xd1b: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_d22:
	/* 0xd22: mov    esi,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_d2a:
	/* 0xd2a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d30:
	/* 0xd30: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d34:
	/* 0xd34: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d37:
	/* 0xd37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d41:
	/* 0xd41: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_d48:
	/* 0xd48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d4a:
	/* 0xd4a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4f:
	/* 0xd4f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d54:
	/* 0xd54: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d57:
	/* 0xd57: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d59:
	/* 0xd59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5b:
	/* 0xd5b: jmp    28b <generic_fentry_actions+0x28b> */
	X86_SIM_X86_JMP(0xd5b, 0x28b, x86_l_28b);
x86_l_d60:
	/* 0xd60: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d67:
	/* 0xd67: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d6c:
	/* 0xd6c: lea    rdx,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d71:
	/* 0xd71: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d76:
	/* 0xd76: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d7b:
	/* 0xd7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7d:
	/* 0xd7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d80:
	/* 0xd80: je     324 <generic_fentry_actions+0x324> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd80, 0x324, x86_l_324);
x86_l_d86:
	/* 0xd86: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d8b:
	/* 0xd8b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d8d:
	/* 0xd8d: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d92:
	/* 0xd92: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_d99:
	/* 0xd99: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_da3:
	/* 0xda3: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_da8:
	/* 0xda8: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_daf:
	/* 0xdaf: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db4:
	/* 0xdb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db9:
	/* 0xdb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbb:
	/* 0xdbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dbe:
	/* 0xdbe: je     f9e <generic_fentry_actions+0xf9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdbe, 0xf9e, x86_l_f9e);
x86_l_dc4:
	/* 0xdc4: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_dc6:
	/* 0xdc6: jmp    fc2 <generic_fentry_actions+0xfc2> */
	X86_SIM_X86_JMP(0xdc6, 0xfc2, x86_l_fc2);
x86_l_dcb:
	/* 0xdcb: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_dd3:
	/* 0xdd3: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_dd8:
	/* 0xdd8: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_de0:
	/* 0xde0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de4:
	/* 0xde4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_de9:
	/* 0xde9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_deb:
	/* 0xdeb: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_def:
	/* 0xdef: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df4:
	/* 0xdf4: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_dfb:
	/* 0xdfb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e00:
	/* 0xe00: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e05:
	/* 0xe05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e07:
	/* 0xe07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e0a:
	/* 0xe0a: je     1eb <generic_fentry_actions+0x1eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0a, 0x1eb, x86_l_1eb);
x86_l_e10:
	/* 0xe10: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e14:
	/* 0xe14: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_e18:
	/* 0xe18: ja     1eb <generic_fentry_actions+0x1eb> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe18, 0x1eb, x86_l_1eb);
x86_l_e1e:
	/* 0xe1e: cmp    DWORD PTR [r14+r13*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 104041287778304ULL);
x86_l_e27:
	/* 0xe27: jne    1eb <generic_fentry_actions+0x1eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe27, 0x1eb, x86_l_1eb);
x86_l_e2d:
	/* 0xe2d: mov    rcx,QWORD PTR [r14+r13*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 24184ULL);
x86_l_e35:
	/* 0xe35: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_e3d:
	/* 0xe3d: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e43:
	/* 0xe43: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e4b:
	/* 0xe4b: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4f:
	/* 0xe4f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e52:
	/* 0xe52: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e57:
	/* 0xe57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e59:
	/* 0xe59: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e5d:
	/* 0xe5d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e62:
	/* 0xe62: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e69:
	/* 0xe69: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e6b:
	/* 0xe6b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e70:
	/* 0xe70: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e75:
	/* 0xe75: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e78:
	/* 0xe78: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7a:
	/* 0xe7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7c:
	/* 0xe7c: jmp    1eb <generic_fentry_actions+0x1eb> */
	X86_SIM_X86_JMP(0xe7c, 0x1eb, x86_l_1eb);
x86_l_e81:
	/* 0xe81: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e88:
	/* 0xe88: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8d:
	/* 0xe8d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_e92:
	/* 0xe92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e94:
	/* 0xe94: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e97:
	/* 0xe97: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_e9a:
	/* 0xe9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e9c:
	/* 0xe9c: jne    3dd <generic_fentry_actions+0x3dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe9c, 0x3dd, x86_l_3dd);
x86_l_ea2:
	/* 0xea2: jmp    1eb <generic_fentry_actions+0x1eb> */
	X86_SIM_X86_JMP(0xea2, 0x1eb, x86_l_1eb);
x86_l_ea7:
	/* 0xea7: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_eae:
	/* 0xeae: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eb3:
	/* 0xeb3: lea    rdx,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_eb8:
	/* 0xeb8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ebd:
	/* 0xebd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ec2:
	/* 0xec2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec4:
	/* 0xec4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec7:
	/* 0xec7: je     7e7 <generic_fentry_actions+0x7e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec7, 0x7e7, x86_l_7e7);
x86_l_ecd:
	/* 0xecd: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ed0:
	/* 0xed0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ed2:
	/* 0xed2: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed7:
	/* 0xed7: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_ede:
	/* 0xede: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_ee8:
	/* 0xee8: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eed:
	/* 0xeed: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ef4:
	/* 0xef4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef9:
	/* 0xef9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_efe:
	/* 0xefe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f00:
	/* 0xf00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f03:
	/* 0xf03: je     1015 <generic_fentry_actions+0x1015> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf03, 0x1015, x86_l_1015);
x86_l_f09:
	/* 0xf09: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f0b:
	/* 0xf0b: jmp    1039 <generic_fentry_actions+0x1039> */
	X86_SIM_X86_JMP(0xf0b, 0x1039, x86_l_1039);
x86_l_f10:
	/* 0xf10: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_f17:
	/* 0xf17: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f1c:
	/* 0xf1c: lea    rdx,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_f21:
	/* 0xf21: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f26:
	/* 0xf26: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f2b:
	/* 0xf2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2d:
	/* 0xf2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f30:
	/* 0xf30: je     bf5 <generic_fentry_actions+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf30, 0xbf5, x86_l_bf5);
x86_l_f36:
	/* 0xf36: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f39:
	/* 0xf39: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_f3b:
	/* 0xf3b: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f40:
	/* 0xf40: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_f47:
	/* 0xf47: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_f51:
	/* 0xf51: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f56:
	/* 0xf56: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f5d:
	/* 0xf5d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f62:
	/* 0xf62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f67:
	/* 0xf67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f69:
	/* 0xf69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f6c:
	/* 0xf6c: je     1069 <generic_fentry_actions+0x1069> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6c, 0x1069, x86_l_1069);
x86_l_f72:
	/* 0xf72: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f74:
	/* 0xf74: jmp    108d <generic_fentry_actions+0x108d> */
	X86_SIM_X86_JMP(0xf74, 0x108d, x86_l_108d);
x86_l_f79:
	/* 0xf79: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_f80:
	/* 0xf80: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f85:
	/* 0xf85: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f8a:
	/* 0xf8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8c:
	/* 0xf8c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f8e:
	/* 0xf8e: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f93:
	/* 0xf93: jne    8b2 <generic_fentry_actions+0x8b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf93, 0x8b2, x86_l_8b2);
x86_l_f99:
	/* 0xf99: jmp    8a8 <generic_fentry_actions+0x8a8> */
	X86_SIM_X86_JMP(0xf99, 0x8a8, x86_l_8a8);
x86_l_f9e:
	/* 0xf9e: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_fa6:
	/* 0xfa6: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_fad:
	/* 0xfad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_faf:
	/* 0xfaf: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb4:
	/* 0xfb4: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_fb9:
	/* 0xfb9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fbe:
	/* 0xfbe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc0:
	/* 0xfc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc2:
	/* 0xfc2: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_fc7:
	/* 0xfc7: je     324 <generic_fentry_actions+0x324> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc7, 0x324, x86_l_324);
x86_l_fcd:
	/* 0xfcd: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_fd4:
	/* 0xfd4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd9:
	/* 0xfd9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fde:
	/* 0xfde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe0:
	/* 0xfe0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe3:
	/* 0xfe3: je     324 <generic_fentry_actions+0x324> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe3, 0x324, x86_l_324);
x86_l_fe9:
	/* 0xfe9: mov    ecx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_fed:
	/* 0xfed: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ff0:
	/* 0xff0: jmp    324 <generic_fentry_actions+0x324> */
	X86_SIM_X86_JMP(0xff0, 0x324, x86_l_324);
x86_l_ff5:
	/* 0xff5: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_ffc:
	/* 0xffc: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1001:
	/* 0x1001: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1006:
	/* 0x1006: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1008:
	/* 0x1008: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_100a:
	/* 0x100a: jne    c95 <generic_fentry_actions+0xc95> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x100a, 0xc95, x86_l_c95);
x86_l_1010:
	/* 0x1010: jmp    c91 <generic_fentry_actions+0xc91> */
	X86_SIM_X86_JMP(0x1010, 0xc91, x86_l_c91);
x86_l_1015:
	/* 0x1015: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_101d:
	/* 0x101d: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1024:
	/* 0x1024: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1026:
	/* 0x1026: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102b:
	/* 0x102b: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1030:
	/* 0x1030: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1035:
	/* 0x1035: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1037:
	/* 0x1037: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1039:
	/* 0x1039: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_103b:
	/* 0x103b: je     7e7 <generic_fentry_actions+0x7e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103b, 0x7e7, x86_l_7e7);
x86_l_1041:
	/* 0x1041: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_1048:
	/* 0x1048: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_104d:
	/* 0x104d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1052:
	/* 0x1052: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1054:
	/* 0x1054: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1057:
	/* 0x1057: je     7e7 <generic_fentry_actions+0x7e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1057, 0x7e7, x86_l_7e7);
x86_l_105d:
	/* 0x105d: mov    ecx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1061:
	/* 0x1061: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1064:
	/* 0x1064: jmp    7e7 <generic_fentry_actions+0x7e7> */
	X86_SIM_X86_JMP(0x1064, 0x7e7, x86_l_7e7);
x86_l_1069:
	/* 0x1069: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_1071:
	/* 0x1071: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1078:
	/* 0x1078: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107a:
	/* 0x107a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107f:
	/* 0x107f: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1084:
	/* 0x1084: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1089:
	/* 0x1089: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108b:
	/* 0x108b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108d:
	/* 0x108d: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1090:
	/* 0x1090: je     bf5 <generic_fentry_actions+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1090, 0xbf5, x86_l_bf5);
x86_l_1096:
	/* 0x1096: mov    rdi,QWORD PTR [rip+0x9d1a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_109d:
	/* 0x109d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10a2:
	/* 0x10a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a7:
	/* 0x10a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a9:
	/* 0x10a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10ac:
	/* 0x10ac: je     bf5 <generic_fentry_actions+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ac, 0xbf5, x86_l_bf5);
x86_l_10b2:
	/* 0x10b2: mov    ecx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10b6:
	/* 0x10b6: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_10b9:
	/* 0x10b9: jmp    bf5 <generic_fentry_actions+0xbf5> */
	X86_SIM_X86_JMP(0x10b9, 0xbf5, x86_l_bf5);
x86_l_10be:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
