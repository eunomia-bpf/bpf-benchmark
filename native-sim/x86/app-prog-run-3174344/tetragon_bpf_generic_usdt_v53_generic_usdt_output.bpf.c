extern char execve_map;
extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_v53_generic_usdt_output_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_12:
	/* 0x12: mov    rdi,QWORD PTR [rip+0x22b47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     4fb <generic_usdt_output+0x4fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x4fb, x86_l_4fb);
x86_l_2e:
	/* 0x2e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: cmp    QWORD PTR [rax+0x5ee8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_39:
	/* 0x39: je     341 <generic_usdt_output+0x341> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39, 0x341, x86_l_341);
x86_l_3f:
	/* 0x3f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_44:
	/* 0x44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46:
	/* 0x46: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_49:
	/* 0x49: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4d:
	/* 0x4d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_52:
	/* 0x52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54:
	/* 0x54: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rsp+0x28],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x22b47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_63:
	/* 0x63: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68:
	/* 0x68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d:
	/* 0x6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f:
	/* 0x6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72:
	/* 0x72: je     341 <generic_usdt_output+0x341> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72, 0x341, x86_l_341);
x86_l_78:
	/* 0x78: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7b:
	/* 0x7b: lea    rdx,[r12+0xd48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_83:
	/* 0x83: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_88:
	/* 0x88: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8d:
	/* 0x8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_92:
	/* 0x92: lea    r13,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_96:
	/* 0x96: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_9b:
	/* 0x9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0:
	/* 0xa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2:
	/* 0xa2: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a7:
	/* 0xa7: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ac:
	/* 0xac: mov    edx,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_b1:
	/* 0xb1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6:
	/* 0xb6: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bb:
	/* 0xbb: mov    esi,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 72ULL);
x86_l_c0:
	/* 0xc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2:
	/* 0xc2: mov    edx,0x1a8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 424ULL);
x86_l_c7:
	/* 0xc7: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cc:
	/* 0xcc: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cf:
	/* 0xcf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d4:
	/* 0xd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d9:
	/* 0xd9: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_de:
	/* 0xde: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e1:
	/* 0xe1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e6:
	/* 0xe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8:
	/* 0xe8: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ec:
	/* 0xec: mov    edx,0x470 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1136ULL);
x86_l_f1:
	/* 0xf1: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f6:
	/* 0xf6: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f9:
	/* 0xf9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fe:
	/* 0xfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_103:
	/* 0x103: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_108:
	/* 0x108: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10d:
	/* 0x10d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f:
	/* 0x10f: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_113:
	/* 0x113: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_118:
	/* 0x118: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11c:
	/* 0x11c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_121:
	/* 0x121: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_126:
	/* 0x126: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12b:
	/* 0x12b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12f:
	/* 0x12f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_134:
	/* 0x134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136:
	/* 0x136: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13f:
	/* 0x13f: lea    rdx,[r12+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_147:
	/* 0x147: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c:
	/* 0x14c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_151:
	/* 0x151: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_156:
	/* 0x156: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15b:
	/* 0x15b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d:
	/* 0x15d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162:
	/* 0x162: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_165:
	/* 0x165: je     1fb <generic_usdt_output+0x1fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x165, 0x1fb, x86_l_1fb);
x86_l_16b:
	/* 0x16b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_173:
	/* 0x173: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_177:
	/* 0x177: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c:
	/* 0x17c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_181:
	/* 0x181: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186:
	/* 0x186: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18a:
	/* 0x18a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18f:
	/* 0x18f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191:
	/* 0x191: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_196:
	/* 0x196: movsxd rcx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_19b:
	/* 0x19b: shl    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_19f:
	/* 0x19f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a2:
	/* 0x1a2: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1a9:
	/* 0x1a9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ae:
	/* 0x1ae: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1b3:
	/* 0x1b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b8:
	/* 0x1b8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd:
	/* 0x1bd: movsxd rdx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c2:
	/* 0x1c2: shl    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1c6:
	/* 0x1c6: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c9:
	/* 0x1c9: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1d0:
	/* 0x1d0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d5:
	/* 0x1d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7:
	/* 0x1d7: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1db:
	/* 0x1db: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e0:
	/* 0x1e0: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1e4:
	/* 0x1e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e9:
	/* 0x1e9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee:
	/* 0x1ee: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_1f2:
	/* 0x1f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f7:
	/* 0x1f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9:
	/* 0x1f9: jmp    203 <generic_usdt_output+0x203> */
	X86_SIM_X86_JMP(0x1f9, 0x203, x86_l_203);
x86_l_1fb:
	/* 0x1fb: mov    DWORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_203:
	/* 0x203: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_207:
	/* 0x207: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20c:
	/* 0x20c: sub    rcx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_210:
	/* 0x210: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_215:
	/* 0x215: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21a:
	/* 0x21a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21f:
	/* 0x21f: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_223:
	/* 0x223: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_228:
	/* 0x228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a:
	/* 0x22a: lea    rdi,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_22e:
	/* 0x22e: mov    edx,0xa8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 168ULL);
x86_l_233:
	/* 0x233: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_238:
	/* 0x238: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23b:
	/* 0x23b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_240:
	/* 0x240: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_245:
	/* 0x245: add    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_24a:
	/* 0x24a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24f:
	/* 0x24f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251:
	/* 0x251: lea    rdi,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_255:
	/* 0x255: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25a:
	/* 0x25a: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_25e:
	/* 0x25e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_263:
	/* 0x263: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_268:
	/* 0x268: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26d:
	/* 0x26d: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_271:
	/* 0x271: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_276:
	/* 0x276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278:
	/* 0x278: lea    rdi,[r15+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_27c:
	/* 0x27c: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_281:
	/* 0x281: add    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_285:
	/* 0x285: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_28a:
	/* 0x28a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28f:
	/* 0x28f: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_294:
	/* 0x294: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_298:
	/* 0x298: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29d:
	/* 0x29d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f:
	/* 0x29f: lea    rdi,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a3:
	/* 0x2a3: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2a8:
	/* 0x2a8: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ac:
	/* 0x2ac: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2b1:
	/* 0x2b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b6:
	/* 0x2b6: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2bb:
	/* 0x2bb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2bf:
	/* 0x2bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c4:
	/* 0x2c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6:
	/* 0x2c6: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2cf:
	/* 0x2cf: add    r12,0xa50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2640ULL);
x86_l_2d6:
	/* 0x2d6: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2db:
	/* 0x2db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e0:
	/* 0x2e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e5:
	/* 0x2e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea:
	/* 0x2ea: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ed:
	/* 0x2ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef:
	/* 0x2ef: mov    edx,0x4a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1184ULL);
x86_l_2f4:
	/* 0x2f4: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f9:
	/* 0x2f9: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fc:
	/* 0x2fc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_301:
	/* 0x301: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_306:
	/* 0x306: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30b:
	/* 0x30b: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_310:
	/* 0x310: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_315:
	/* 0x315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317:
	/* 0x317: add    r15,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_31b:
	/* 0x31b: mov    edx,0xe8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 232ULL);
x86_l_320:
	/* 0x320: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_325:
	/* 0x325: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_328:
	/* 0x328: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32d:
	/* 0x32d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_332:
	/* 0x332: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_337:
	/* 0x337: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_33a:
	/* 0x33a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33f:
	/* 0x33f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341:
	/* 0x341: cmp    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_349:
	/* 0x349: je     406 <generic_usdt_output+0x406> */
	X86_SIM_X86_JCC(X86_CC_E, 0x349, 0x406, x86_l_406);
x86_l_34f:
	/* 0x34f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_354:
	/* 0x354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_356:
	/* 0x356: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_359:
	/* 0x359: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_35d:
	/* 0x35d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_362:
	/* 0x362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364:
	/* 0x364: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_367:
	/* 0x367: mov    DWORD PTR [rsp+0x28],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36c:
	/* 0x36c: mov    rdi,QWORD PTR [rip+0x22b47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_373:
	/* 0x373: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_378:
	/* 0x378: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37d:
	/* 0x37d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f:
	/* 0x37f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_382:
	/* 0x382: je     406 <generic_usdt_output+0x406> */
	X86_SIM_X86_JCC(X86_CC_E, 0x382, 0x406, x86_l_406);
x86_l_388:
	/* 0x388: lea    r15,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_38c:
	/* 0x38c: add    r12,0xce0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3296ULL);
x86_l_393:
	/* 0x393: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_398:
	/* 0x398: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39d:
	/* 0x39d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a5:
	/* 0x3a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa:
	/* 0x3aa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3ad:
	/* 0x3ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3af:
	/* 0x3af: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b4:
	/* 0x3b4: lea    rdi,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b8:
	/* 0x3b8: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3bd:
	/* 0x3bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c2:
	/* 0x3c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c7:
	/* 0x3c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cc:
	/* 0x3cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ce:
	/* 0x3ce: add    r13,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_3d2:
	/* 0x3d2: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d7:
	/* 0x3d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3dc:
	/* 0x3dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e1:
	/* 0x3e1: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_3e4:
	/* 0x3e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e9:
	/* 0x3e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eb:
	/* 0x3eb: add    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3ef:
	/* 0x3ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f4:
	/* 0x3f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f9:
	/* 0x3f9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3fc:
	/* 0x3fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_401:
	/* 0x401: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_404:
	/* 0x404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_406:
	/* 0x406: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_40b:
	/* 0x40b: add    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_40f:
	/* 0x40f: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_414:
	/* 0x414: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_419:
	/* 0x419: mov    r8d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 9000ULL);
x86_l_41f:
	/* 0x41f: cmovb  r8d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_423:
	/* 0x423: mov    rsi,QWORD PTR [rip+0x22b43] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_42a:
	/* 0x42a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_42f:
	/* 0x42f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_434:
	/* 0x434: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_439:
	/* 0x439: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_43c:
	/* 0x43c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_43f:
	/* 0x43f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_441:
	/* 0x441: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_444:
	/* 0x444: js     474 <generic_usdt_output+0x474> */
	X86_SIM_X86_JCC(X86_CC_S, 0x444, 0x474, x86_l_474);
x86_l_446:
	/* 0x446: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_44e:
	/* 0x44e: mov    rdi,QWORD PTR [rip+0x22b43] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_455:
	/* 0x455: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_45a:
	/* 0x45a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45f:
	/* 0x45f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461:
	/* 0x461: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_464:
	/* 0x464: je     4fb <generic_usdt_output+0x4fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x464, 0x4fb, x86_l_4fb);
x86_l_46a:
	/* 0x46a: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_46f:
	/* 0x46f: jmp    4fb <generic_usdt_output+0x4fb> */
	X86_SIM_X86_JMP(0x46f, 0x4fb, x86_l_4fb);
x86_l_474:
	/* 0x474: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_477:
	/* 0x477: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_47f:
	/* 0x47f: mov    rdi,QWORD PTR [rip+0x22b43] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_486:
	/* 0x486: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_48b:
	/* 0x48b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_490:
	/* 0x490: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_492:
	/* 0x492: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_495:
	/* 0x495: je     4fb <generic_usdt_output+0x4fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x495, 0x4fb, x86_l_4fb);
x86_l_497:
	/* 0x497: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_49b:
	/* 0x49b: jg     4b7 <generic_usdt_output+0x4b7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x49b, 0x4b7, x86_l_4b7);
x86_l_49d:
	/* 0x49d: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_4a1:
	/* 0x4a1: je     4d1 <generic_usdt_output+0x4d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a1, 0x4d1, x86_l_4d1);
x86_l_4a3:
	/* 0x4a3: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_4a7:
	/* 0x4a7: je     4e9 <generic_usdt_output+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a7, 0x4e9, x86_l_4e9);
x86_l_4a9:
	/* 0x4a9: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_4ad:
	/* 0x4ad: jne    4e1 <generic_usdt_output+0x4e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ad, 0x4e1, x86_l_4e1);
x86_l_4af:
	/* 0x4af: add    rax,0x638 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1592ULL);
x86_l_4b5:
	/* 0x4b5: jmp    4f7 <generic_usdt_output+0x4f7> */
	X86_SIM_X86_JMP(0x4b5, 0x4f7, x86_l_4f7);
x86_l_4b7:
	/* 0x4b7: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_4bb:
	/* 0x4bb: je     4d9 <generic_usdt_output+0x4d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bb, 0x4d9, x86_l_4d9);
x86_l_4bd:
	/* 0x4bd: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_4c1:
	/* 0x4c1: je     4f1 <generic_usdt_output+0x4f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c1, 0x4f1, x86_l_4f1);
x86_l_4c3:
	/* 0x4c3: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_4c7:
	/* 0x4c7: jne    4e1 <generic_usdt_output+0x4e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4c7, 0x4e1, x86_l_4e1);
x86_l_4c9:
	/* 0x4c9: add    rax,0x628 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1576ULL);
x86_l_4cf:
	/* 0x4cf: jmp    4f7 <generic_usdt_output+0x4f7> */
	X86_SIM_X86_JMP(0x4cf, 0x4f7, x86_l_4f7);
x86_l_4d1:
	/* 0x4d1: add    rax,0x648 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1608ULL);
x86_l_4d7:
	/* 0x4d7: jmp    4f7 <generic_usdt_output+0x4f7> */
	X86_SIM_X86_JMP(0x4d7, 0x4f7, x86_l_4f7);
x86_l_4d9:
	/* 0x4d9: add    rax,0x650 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1616ULL);
x86_l_4df:
	/* 0x4df: jmp    4f7 <generic_usdt_output+0x4f7> */
	X86_SIM_X86_JMP(0x4df, 0x4f7, x86_l_4f7);
x86_l_4e1:
	/* 0x4e1: add    rax,0x620 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1568ULL);
x86_l_4e7:
	/* 0x4e7: jmp    4f7 <generic_usdt_output+0x4f7> */
	X86_SIM_X86_JMP(0x4e7, 0x4f7, x86_l_4f7);
x86_l_4e9:
	/* 0x4e9: add    rax,0x640 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1600ULL);
x86_l_4ef:
	/* 0x4ef: jmp    4f7 <generic_usdt_output+0x4f7> */
	X86_SIM_X86_JMP(0x4ef, 0x4f7, x86_l_4f7);
x86_l_4f1:
	/* 0x4f1: add    rax,0x630 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1584ULL);
x86_l_4f7:
	/* 0x4f7: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4fb:
	/* 0x4fb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fd:
	/* 0x4fd: add    rsp,0x78 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 120ULL);
x86_l_501:
	/* 0x501: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_503:
	/* 0x503: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_504:
	/* 0x504: jmp    509 <generic_usdt_output+0x509> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_509:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
