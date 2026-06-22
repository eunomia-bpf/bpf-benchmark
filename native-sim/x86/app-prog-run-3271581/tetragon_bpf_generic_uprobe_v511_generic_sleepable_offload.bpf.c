extern char regs_map;
extern char sleepable_offload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_v511_generic_sleepable_offload_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_19:
	/* 0x19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b:
	/* 0x1b: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_23:
	/* 0x23: mov    rdi,QWORD PTR [rip+0x5e40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_2a:
	/* 0x2a: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_32:
	/* 0x32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37:
	/* 0x37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39:
	/* 0x39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: je     1bb4 <generic_sleepable_offload+0x1bb4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c, 0x1bb4, x86_l_1bb4);
x86_l_42:
	/* 0x42: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_45:
	/* 0x45: mov    rdi,QWORD PTR [rip+0x5e40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_4c:
	/* 0x4c: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_54:
	/* 0x54: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_59:
	/* 0x59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b:
	/* 0x5b: mov    rdi,QWORD PTR [rip+0x5e40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&regs_map)));
x86_l_62:
	/* 0x62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67:
	/* 0x67: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c:
	/* 0x6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: je     1bb4 <generic_sleepable_offload+0x1bb4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f, 0x1bb4, x86_l_1bb4);
x86_l_75:
	/* 0x75: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_78:
	/* 0x78: lea    rax,[rbx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83:
	/* 0x83: lea    rax,[rbx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8f:
	/* 0x8f: lea    rbp,[rbx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_93:
	/* 0x93: lea    rax,[rbx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_97:
	/* 0x97: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9c:
	/* 0x9c: lea    rax,[rbx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a0:
	/* 0xa0: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a5:
	/* 0xa5: lea    rax,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a9:
	/* 0xa9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ae:
	/* 0xae: lea    rax,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b2:
	/* 0xb2: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b7:
	/* 0xb7: lea    rax,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c0:
	/* 0xc0: lea    rax,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c4:
	/* 0xc4: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c9:
	/* 0xc9: lea    rax,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cd:
	/* 0xcd: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d2:
	/* 0xd2: lea    rax,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_db:
	/* 0xdb: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_df:
	/* 0xdf: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e4:
	/* 0xe4: lea    rax,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e8:
	/* 0xe8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ed:
	/* 0xed: lea    rax,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f1:
	/* 0xf1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f6:
	/* 0xf6: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_fd:
	/* 0xfd: lea    rax,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101:
	/* 0x101: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_106:
	/* 0x106: lea    rax,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a:
	/* 0x10a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f:
	/* 0x10f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112:
	/* 0x112: lea    r15,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_117:
	/* 0x117: jmp    131 <generic_sleepable_offload+0x131> */
	X86_SIM_X86_JMP(0x117, 0x131, x86_l_131);
x86_l_119:
	/* 0x119: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11e:
	/* 0x11e: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120:
	/* 0x120: inc    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_123:
	/* 0x123: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_127:
	/* 0x127: cmp    r12,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18ULL);
x86_l_12b:
	/* 0x12b: je     1bb4 <generic_sleepable_offload+0x1bb4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12b, 0x1bb4, x86_l_1bb4);
x86_l_131:
	/* 0x131: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_138:
	/* 0x138: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: jae    1bb4 <generic_sleepable_offload+0x1bb4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x13b, 0x1bb4, x86_l_1bb4);
x86_l_141:
	/* 0x141: movzx  eax,BYTE PTR [r14-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_146:
	/* 0x146: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_149:
	/* 0x149: jg     1b5 <generic_sleepable_offload+0x1b5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x149, 0x1b5, x86_l_1b5);
x86_l_14b:
	/* 0x14b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14e:
	/* 0x14e: je     223 <generic_sleepable_offload+0x223> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e, 0x223, x86_l_223);
x86_l_154:
	/* 0x154: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_157:
	/* 0x157: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x157, 0x120, x86_l_120);
x86_l_159:
	/* 0x159: movzx  eax,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_15e:
	/* 0x15e: movzx  ecx,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_163:
	/* 0x163: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_169:
	/* 0x169: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_16c:
	/* 0x16c: jle    2e8 <generic_sleepable_offload+0x2e8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x16c, 0x2e8, x86_l_2e8);
x86_l_172:
	/* 0x172: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_175:
	/* 0x175: jle    3c4 <generic_sleepable_offload+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x175, 0x3c4, x86_l_3c4);
x86_l_17b:
	/* 0x17b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_17e:
	/* 0x17e: jle    70d <generic_sleepable_offload+0x70d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x17e, 0x70d, x86_l_70d);
x86_l_184:
	/* 0x184: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_187:
	/* 0x187: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_18a:
	/* 0x18a: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18a, 0x726, x86_l_726);
x86_l_190:
	/* 0x190: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_195:
	/* 0x195: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_198:
	/* 0x198: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x198, 0x726, x86_l_726);
x86_l_19e:
	/* 0x19e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1a3:
	/* 0x1a3: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1a6:
	/* 0x1a6: jne    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a6, 0x739, x86_l_739);
x86_l_1ac:
	/* 0x1ac: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0:
	/* 0x1b0: jmp    726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JMP(0x1b0, 0x726, x86_l_726);
x86_l_1b5:
	/* 0x1b5: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1b8:
	/* 0x1b8: je     28c <generic_sleepable_offload+0x28c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b8, 0x28c, x86_l_28c);
x86_l_1be:
	/* 0x1be: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c1:
	/* 0x1c1: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c1, 0x120, x86_l_120);
x86_l_1c7:
	/* 0x1c7: movzx  ecx,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_1cc:
	/* 0x1cc: movzx  eax,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_1d1:
	/* 0x1d1: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1d7:
	/* 0x1d7: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1da:
	/* 0x1da: jle    31d <generic_sleepable_offload+0x31d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1da, 0x31d, x86_l_31d);
x86_l_1e0:
	/* 0x1e0: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1e3:
	/* 0x1e3: jle    3f3 <generic_sleepable_offload+0x3f3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1e3, 0x3f3, x86_l_3f3);
x86_l_1e9:
	/* 0x1e9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1ec:
	/* 0x1ec: jle    90e <generic_sleepable_offload+0x90e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1ec, 0x90e, x86_l_90e);
x86_l_1f2:
	/* 0x1f2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1f5:
	/* 0x1f5: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1f8:
	/* 0x1f8: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f8, 0x927, x86_l_927);
x86_l_1fe:
	/* 0x1fe: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_203:
	/* 0x203: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_206:
	/* 0x206: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x206, 0x927, x86_l_927);
x86_l_20c:
	/* 0x20c: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_211:
	/* 0x211: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_214:
	/* 0x214: jne    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x214, 0x93a, x86_l_93a);
x86_l_21a:
	/* 0x21a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e:
	/* 0x21e: jmp    927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JMP(0x21e, 0x927, x86_l_927);
x86_l_223:
	/* 0x223: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_228:
	/* 0x228: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_22d:
	/* 0x22d: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230:
	/* 0x230: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_236:
	/* 0x236: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_239:
	/* 0x239: jle    352 <generic_sleepable_offload+0x352> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x239, 0x352, x86_l_352);
x86_l_23f:
	/* 0x23f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_242:
	/* 0x242: jle    422 <generic_sleepable_offload+0x422> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x242, 0x422, x86_l_422);
x86_l_248:
	/* 0x248: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_24b:
	/* 0x24b: jle    a41 <generic_sleepable_offload+0xa41> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x24b, 0xa41, x86_l_a41);
x86_l_251:
	/* 0x251: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_254:
	/* 0x254: je     100b <generic_sleepable_offload+0x100b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x254, 0x100b, x86_l_100b);
x86_l_25a:
	/* 0x25a: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_25d:
	/* 0x25d: je     e73 <generic_sleepable_offload+0xe73> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25d, 0xe73, x86_l_e73);
x86_l_263:
	/* 0x263: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_266:
	/* 0x266: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x266, 0x120, x86_l_120);
x86_l_26c:
	/* 0x26c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_26f:
	/* 0x26f: jg     14fe <generic_sleepable_offload+0x14fe> */
	X86_SIM_X86_JCC(X86_CC_G, 0x26f, 0x14fe, x86_l_14fe);
x86_l_275:
	/* 0x275: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_278:
	/* 0x278: je     9bf <generic_sleepable_offload+0x9bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x278, 0x9bf, x86_l_9bf);
x86_l_27e:
	/* 0x27e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_281:
	/* 0x281: je     79b <generic_sleepable_offload+0x79b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x281, 0x79b, x86_l_79b);
x86_l_287:
	/* 0x287: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x287, 0x120, x86_l_120);
x86_l_28c:
	/* 0x28c: movzx  eax,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_291:
	/* 0x291: movzx  ecx,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_296:
	/* 0x296: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_29c:
	/* 0x29c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_29f:
	/* 0x29f: jle    38f <generic_sleepable_offload+0x38f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x29f, 0x38f, x86_l_38f);
x86_l_2a5:
	/* 0x2a5: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2a8:
	/* 0x2a8: jle    45d <generic_sleepable_offload+0x45d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2a8, 0x45d, x86_l_45d);
x86_l_2ae:
	/* 0x2ae: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2b1:
	/* 0x2b1: jle    a7b <generic_sleepable_offload+0xa7b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2b1, 0xa7b, x86_l_a7b);
x86_l_2b7:
	/* 0x2b7: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2bd:
	/* 0x2bd: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bd, 0xa94, x86_l_a94);
x86_l_2c3:
	/* 0x2c3: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c8:
	/* 0x2c8: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2cb:
	/* 0x2cb: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2cb, 0xa94, x86_l_a94);
x86_l_2d1:
	/* 0x2d1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2d6:
	/* 0x2d6: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2d9:
	/* 0x2d9: jne    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d9, 0xaa7, x86_l_aa7);
x86_l_2df:
	/* 0x2df: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e3:
	/* 0x2e3: jmp    a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JMP(0x2e3, 0xa94, x86_l_a94);
x86_l_2e8:
	/* 0x2e8: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2eb:
	/* 0x2eb: jg     48c <generic_sleepable_offload+0x48c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2eb, 0x48c, x86_l_48c);
x86_l_2f1:
	/* 0x2f1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2f4:
	/* 0x2f4: jg     5ef <generic_sleepable_offload+0x5ef> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2f4, 0x5ef, x86_l_5ef);
x86_l_2fa:
	/* 0x2fa: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2fd:
	/* 0x2fd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2ff:
	/* 0x2ff: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ff, 0x726, x86_l_726);
x86_l_305:
	/* 0x305: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30a:
	/* 0x30a: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_30f:
	/* 0x30f: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_312:
	/* 0x312: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x312, 0x726, x86_l_726);
x86_l_318:
	/* 0x318: jmp    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JMP(0x318, 0x739, x86_l_739);
x86_l_31d:
	/* 0x31d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_320:
	/* 0x320: jg     4bb <generic_sleepable_offload+0x4bb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x320, 0x4bb, x86_l_4bb);
x86_l_326:
	/* 0x326: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_329:
	/* 0x329: jg     615 <generic_sleepable_offload+0x615> */
	X86_SIM_X86_JCC(X86_CC_G, 0x329, 0x615, x86_l_615);
x86_l_32f:
	/* 0x32f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_332:
	/* 0x332: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_334:
	/* 0x334: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x334, 0x927, x86_l_927);
x86_l_33a:
	/* 0x33a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f:
	/* 0x33f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_344:
	/* 0x344: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_347:
	/* 0x347: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x347, 0x927, x86_l_927);
x86_l_34d:
	/* 0x34d: jmp    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JMP(0x34d, 0x93a, x86_l_93a);
x86_l_352:
	/* 0x352: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_355:
	/* 0x355: jg     4ea <generic_sleepable_offload+0x4ea> */
	X86_SIM_X86_JCC(X86_CC_G, 0x355, 0x4ea, x86_l_4ea);
x86_l_35b:
	/* 0x35b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_35e:
	/* 0x35e: jg     870 <generic_sleepable_offload+0x870> */
	X86_SIM_X86_JCC(X86_CC_G, 0x35e, 0x870, x86_l_870);
x86_l_364:
	/* 0x364: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_366:
	/* 0x366: jne    7c1 <generic_sleepable_offload+0x7c1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x366, 0x7c1, x86_l_7c1);
x86_l_36c:
	/* 0x36c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_36f:
	/* 0x36f: jg     13cc <generic_sleepable_offload+0x13cc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x36f, 0x13cc, x86_l_13cc);
x86_l_375:
	/* 0x375: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_378:
	/* 0x378: je     18ec <generic_sleepable_offload+0x18ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x378, 0x18ec, x86_l_18ec);
x86_l_37e:
	/* 0x37e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_381:
	/* 0x381: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x381, 0x120, x86_l_120);
x86_l_387:
	/* 0x387: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38a:
	/* 0x38a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x38a, 0x120, x86_l_120);
x86_l_38f:
	/* 0x38f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_392:
	/* 0x392: jg     51c <generic_sleepable_offload+0x51c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x392, 0x51c, x86_l_51c);
x86_l_398:
	/* 0x398: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_39b:
	/* 0x39b: jg     687 <generic_sleepable_offload+0x687> */
	X86_SIM_X86_JCC(X86_CC_G, 0x39b, 0x687, x86_l_687);
x86_l_3a1:
	/* 0x3a1: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3a6:
	/* 0x3a6: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a6, 0xa94, x86_l_a94);
x86_l_3ac:
	/* 0x3ac: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b1:
	/* 0x3b1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3b6:
	/* 0x3b6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3b9:
	/* 0x3b9: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b9, 0xa94, x86_l_a94);
x86_l_3bf:
	/* 0x3bf: jmp    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JMP(0x3bf, 0xaa7, x86_l_aa7);
x86_l_3c4:
	/* 0x3c4: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3c7:
	/* 0x3c7: jg     54b <generic_sleepable_offload+0x54b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3c7, 0x54b, x86_l_54b);
x86_l_3cd:
	/* 0x3cd: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d2:
	/* 0x3d2: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d5:
	/* 0x3d5: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d5, 0x726, x86_l_726);
x86_l_3db:
	/* 0x3db: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e0:
	/* 0x3e0: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3e5:
	/* 0x3e5: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3e8:
	/* 0x3e8: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e8, 0x726, x86_l_726);
x86_l_3ee:
	/* 0x3ee: jmp    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JMP(0x3ee, 0x739, x86_l_739);
x86_l_3f3:
	/* 0x3f3: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_3f6:
	/* 0x3f6: jg     571 <generic_sleepable_offload+0x571> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3f6, 0x571, x86_l_571);
x86_l_3fc:
	/* 0x3fc: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_401:
	/* 0x401: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_404:
	/* 0x404: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x404, 0x927, x86_l_927);
x86_l_40a:
	/* 0x40a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_40f:
	/* 0x40f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_414:
	/* 0x414: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_417:
	/* 0x417: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0x927, x86_l_927);
x86_l_41d:
	/* 0x41d: jmp    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JMP(0x41d, 0x93a, x86_l_93a);
x86_l_422:
	/* 0x422: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_425:
	/* 0x425: jg     597 <generic_sleepable_offload+0x597> */
	X86_SIM_X86_JCC(X86_CC_G, 0x425, 0x597, x86_l_597);
x86_l_42b:
	/* 0x42b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42e:
	/* 0x42e: je     dcf <generic_sleepable_offload+0xdcf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42e, 0xdcf, x86_l_dcf);
x86_l_434:
	/* 0x434: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_437:
	/* 0x437: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x437, 0x120, x86_l_120);
x86_l_43d:
	/* 0x43d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_440:
	/* 0x440: jg     12fc <generic_sleepable_offload+0x12fc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x440, 0x12fc, x86_l_12fc);
x86_l_446:
	/* 0x446: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_449:
	/* 0x449: je     1883 <generic_sleepable_offload+0x1883> */
	X86_SIM_X86_JCC(X86_CC_E, 0x449, 0x1883, x86_l_1883);
x86_l_44f:
	/* 0x44f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_452:
	/* 0x452: je     b95 <generic_sleepable_offload+0xb95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x452, 0xb95, x86_l_b95);
x86_l_458:
	/* 0x458: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x458, 0x120, x86_l_120);
x86_l_45d:
	/* 0x45d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_460:
	/* 0x460: jg     5c9 <generic_sleepable_offload+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x460, 0x5c9, x86_l_5c9);
x86_l_466:
	/* 0x466: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_46b:
	/* 0x46b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46e:
	/* 0x46e: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46e, 0xa94, x86_l_a94);
x86_l_474:
	/* 0x474: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_479:
	/* 0x479: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_47e:
	/* 0x47e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_481:
	/* 0x481: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x481, 0xa94, x86_l_a94);
x86_l_487:
	/* 0x487: jmp    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JMP(0x487, 0xaa7, x86_l_aa7);
x86_l_48c:
	/* 0x48c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_48f:
	/* 0x48f: jg     63b <generic_sleepable_offload+0x63b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x48f, 0x63b, x86_l_63b);
x86_l_495:
	/* 0x495: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_49a:
	/* 0x49a: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_49d:
	/* 0x49d: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49d, 0x726, x86_l_726);
x86_l_4a3:
	/* 0x4a3: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a8:
	/* 0x4a8: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_4ad:
	/* 0x4ad: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4b0:
	/* 0x4b0: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b0, 0x726, x86_l_726);
x86_l_4b6:
	/* 0x4b6: jmp    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JMP(0x4b6, 0x739, x86_l_739);
x86_l_4bb:
	/* 0x4bb: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4be:
	/* 0x4be: jg     661 <generic_sleepable_offload+0x661> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4be, 0x661, x86_l_661);
x86_l_4c4:
	/* 0x4c4: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c9:
	/* 0x4c9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4cc:
	/* 0x4cc: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cc, 0x927, x86_l_927);
x86_l_4d2:
	/* 0x4d2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d7:
	/* 0x4d7: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_4dc:
	/* 0x4dc: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4df:
	/* 0x4df: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4df, 0x927, x86_l_927);
x86_l_4e5:
	/* 0x4e5: jmp    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JMP(0x4e5, 0x93a, x86_l_93a);
x86_l_4ea:
	/* 0x4ea: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4ed:
	/* 0x4ed: jg     6ad <generic_sleepable_offload+0x6ad> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4ed, 0x6ad, x86_l_6ad);
x86_l_4f3:
	/* 0x4f3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4f6:
	/* 0x4f6: je     cbd <generic_sleepable_offload+0xcbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f6, 0xcbd, x86_l_cbd);
x86_l_4fc:
	/* 0x4fc: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4ff:
	/* 0x4ff: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ff, 0x120, x86_l_120);
x86_l_505:
	/* 0x505: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_508:
	/* 0x508: jg     10da <generic_sleepable_offload+0x10da> */
	X86_SIM_X86_JCC(X86_CC_G, 0x508, 0x10da, x86_l_10da);
x86_l_50e:
	/* 0x50e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_511:
	/* 0x511: jne    85a <generic_sleepable_offload+0x85a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x511, 0x85a, x86_l_85a);
x86_l_517:
	/* 0x517: jmp    18c0 <generic_sleepable_offload+0x18c0> */
	X86_SIM_X86_JMP(0x517, 0x18c0, x86_l_18c0);
x86_l_51c:
	/* 0x51c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_51f:
	/* 0x51f: jg     6e7 <generic_sleepable_offload+0x6e7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x51f, 0x6e7, x86_l_6e7);
x86_l_525:
	/* 0x525: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_52a:
	/* 0x52a: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_52d:
	/* 0x52d: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52d, 0xa94, x86_l_a94);
x86_l_533:
	/* 0x533: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_538:
	/* 0x538: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_53d:
	/* 0x53d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_540:
	/* 0x540: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x540, 0xa94, x86_l_a94);
x86_l_546:
	/* 0x546: jmp    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JMP(0x546, 0xaa7, x86_l_aa7);
x86_l_54b:
	/* 0x54b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_550:
	/* 0x550: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_553:
	/* 0x553: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x553, 0x726, x86_l_726);
x86_l_559:
	/* 0x559: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55e:
	/* 0x55e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_563:
	/* 0x563: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_566:
	/* 0x566: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x566, 0x726, x86_l_726);
x86_l_56c:
	/* 0x56c: jmp    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JMP(0x56c, 0x739, x86_l_739);
x86_l_571:
	/* 0x571: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_576:
	/* 0x576: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_579:
	/* 0x579: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x579, 0x927, x86_l_927);
x86_l_57f:
	/* 0x57f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_584:
	/* 0x584: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_589:
	/* 0x589: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_58c:
	/* 0x58c: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58c, 0x927, x86_l_927);
x86_l_592:
	/* 0x592: jmp    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JMP(0x592, 0x93a, x86_l_93a);
x86_l_597:
	/* 0x597: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_59a:
	/* 0x59a: je     deb <generic_sleepable_offload+0xdeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59a, 0xdeb, x86_l_deb);
x86_l_5a0:
	/* 0x5a0: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_5a3:
	/* 0x5a3: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a3, 0x120, x86_l_120);
x86_l_5a9:
	/* 0x5a9: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5ac:
	/* 0x5ac: jg     130b <generic_sleepable_offload+0x130b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5ac, 0x130b, x86_l_130b);
x86_l_5b2:
	/* 0x5b2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b5:
	/* 0x5b5: je     188d <generic_sleepable_offload+0x188d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b5, 0x188d, x86_l_188d);
x86_l_5bb:
	/* 0x5bb: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5be:
	/* 0x5be: je     c0a <generic_sleepable_offload+0xc0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5be, 0xc0a, x86_l_c0a);
x86_l_5c4:
	/* 0x5c4: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x5c4, 0x120, x86_l_120);
x86_l_5c9:
	/* 0x5c9: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5ce:
	/* 0x5ce: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5d1:
	/* 0x5d1: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d1, 0xa94, x86_l_a94);
x86_l_5d7:
	/* 0x5d7: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5dc:
	/* 0x5dc: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5e1:
	/* 0x5e1: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_5e4:
	/* 0x5e4: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e4, 0xa94, x86_l_a94);
x86_l_5ea:
	/* 0x5ea: jmp    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JMP(0x5ea, 0xaa7, x86_l_aa7);
x86_l_5ef:
	/* 0x5ef: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5f4:
	/* 0x5f4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5f7:
	/* 0x5f7: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f7, 0x726, x86_l_726);
x86_l_5fd:
	/* 0x5fd: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_602:
	/* 0x602: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_607:
	/* 0x607: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_60a:
	/* 0x60a: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60a, 0x726, x86_l_726);
x86_l_610:
	/* 0x610: jmp    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JMP(0x610, 0x739, x86_l_739);
x86_l_615:
	/* 0x615: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_61a:
	/* 0x61a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_61d:
	/* 0x61d: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61d, 0x927, x86_l_927);
x86_l_623:
	/* 0x623: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_628:
	/* 0x628: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_62d:
	/* 0x62d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_630:
	/* 0x630: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x630, 0x927, x86_l_927);
x86_l_636:
	/* 0x636: jmp    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JMP(0x636, 0x93a, x86_l_93a);
x86_l_63b:
	/* 0x63b: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_640:
	/* 0x640: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_643:
	/* 0x643: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x643, 0x726, x86_l_726);
x86_l_649:
	/* 0x649: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64e:
	/* 0x64e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_653:
	/* 0x653: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_656:
	/* 0x656: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x656, 0x726, x86_l_726);
x86_l_65c:
	/* 0x65c: jmp    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JMP(0x65c, 0x739, x86_l_739);
x86_l_661:
	/* 0x661: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_666:
	/* 0x666: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_669:
	/* 0x669: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x669, 0x927, x86_l_927);
x86_l_66f:
	/* 0x66f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_674:
	/* 0x674: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_679:
	/* 0x679: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_67c:
	/* 0x67c: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67c, 0x927, x86_l_927);
x86_l_682:
	/* 0x682: jmp    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JMP(0x682, 0x93a, x86_l_93a);
x86_l_687:
	/* 0x687: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_68c:
	/* 0x68c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_68f:
	/* 0x68f: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68f, 0xa94, x86_l_a94);
x86_l_695:
	/* 0x695: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69a:
	/* 0x69a: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_69f:
	/* 0x69f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_6a2:
	/* 0x6a2: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a2, 0xa94, x86_l_a94);
x86_l_6a8:
	/* 0x6a8: jmp    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JMP(0x6a8, 0xaa7, x86_l_aa7);
x86_l_6ad:
	/* 0x6ad: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6b0:
	/* 0x6b0: je     f50 <generic_sleepable_offload+0xf50> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b0, 0xf50, x86_l_f50);
x86_l_6b6:
	/* 0x6b6: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_6b9:
	/* 0x6b9: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b9, 0x120, x86_l_120);
x86_l_6bf:
	/* 0x6bf: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6c2:
	/* 0x6c2: jg     1533 <generic_sleepable_offload+0x1533> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6c2, 0x1533, x86_l_1533);
x86_l_6c8:
	/* 0x6c8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6cb:
	/* 0x6cb: je     18ca <generic_sleepable_offload+0x18ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6cb, 0x18ca, x86_l_18ca);
x86_l_6d1:
	/* 0x6d1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6d4:
	/* 0x6d4: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6d4, 0x120, x86_l_120);
x86_l_6da:
	/* 0x6da: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6df:
	/* 0x6df: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e2:
	/* 0x6e2: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x6e2, 0x120, x86_l_120);
x86_l_6e7:
	/* 0x6e7: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ec:
	/* 0x6ec: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6ef:
	/* 0x6ef: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ef, 0xa94, x86_l_a94);
x86_l_6f5:
	/* 0x6f5: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fa:
	/* 0x6fa: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_6ff:
	/* 0x6ff: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_702:
	/* 0x702: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x702, 0xa94, x86_l_a94);
x86_l_708:
	/* 0x708: jmp    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JMP(0x708, 0xaa7, x86_l_aa7);
x86_l_70d:
	/* 0x70d: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_712:
	/* 0x712: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_715:
	/* 0x715: je     726 <generic_sleepable_offload+0x726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x715, 0x726, x86_l_726);
x86_l_717:
	/* 0x717: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_71c:
	/* 0x71c: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_721:
	/* 0x721: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_724:
	/* 0x724: jne    739 <generic_sleepable_offload+0x739> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x724, 0x739, x86_l_739);
x86_l_726:
	/* 0x726: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_729:
	/* 0x729: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_72b:
	/* 0x72b: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_72d:
	/* 0x72d: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_732:
	/* 0x732: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_734:
	/* 0x734: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_739:
	/* 0x739: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_73e:
	/* 0x73e: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_743:
	/* 0x743: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_748:
	/* 0x748: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_74e:
	/* 0x74e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_751:
	/* 0x751: jle    7a7 <generic_sleepable_offload+0x7a7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x751, 0x7a7, x86_l_7a7);
x86_l_753:
	/* 0x753: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_756:
	/* 0x756: jle    7f2 <generic_sleepable_offload+0x7f2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x756, 0x7f2, x86_l_7f2);
x86_l_75c:
	/* 0x75c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_75f:
	/* 0x75f: jle    a13 <generic_sleepable_offload+0xa13> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x75f, 0xa13, x86_l_a13);
x86_l_765:
	/* 0x765: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_768:
	/* 0x768: je     ef2 <generic_sleepable_offload+0xef2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x768, 0xef2, x86_l_ef2);
x86_l_76e:
	/* 0x76e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_771:
	/* 0x771: je     e57 <generic_sleepable_offload+0xe57> */
	X86_SIM_X86_JCC(X86_CC_E, 0x771, 0xe57, x86_l_e57);
x86_l_777:
	/* 0x777: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_77a:
	/* 0x77a: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x77a, 0x120, x86_l_120);
x86_l_780:
	/* 0x780: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_783:
	/* 0x783: jg     14eb <generic_sleepable_offload+0x14eb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x783, 0x14eb, x86_l_14eb);
x86_l_789:
	/* 0x789: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_78c:
	/* 0x78c: je     1936 <generic_sleepable_offload+0x1936> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78c, 0x1936, x86_l_1936);
x86_l_792:
	/* 0x792: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_795:
	/* 0x795: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x795, 0x120, x86_l_120);
x86_l_79b:
	/* 0x79b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79f:
	/* 0x79f: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a2:
	/* 0x7a2: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x7a2, 0x120, x86_l_120);
x86_l_7a7:
	/* 0x7a7: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7aa:
	/* 0x7aa: jg     82d <generic_sleepable_offload+0x82d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7aa, 0x82d, x86_l_82d);
x86_l_7b0:
	/* 0x7b0: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7b3:
	/* 0x7b3: jg     870 <generic_sleepable_offload+0x870> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7b3, 0x870, x86_l_870);
x86_l_7b9:
	/* 0x7b9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_7bb:
	/* 0x7bb: je     eb2 <generic_sleepable_offload+0xeb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bb, 0xeb2, x86_l_eb2);
x86_l_7c1:
	/* 0x7c1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7c4:
	/* 0x7c4: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7c4, 0x120, x86_l_120);
x86_l_7ca:
	/* 0x7ca: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7cd:
	/* 0x7cd: jg     10bb <generic_sleepable_offload+0x10bb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7cd, 0x10bb, x86_l_10bb);
x86_l_7d3:
	/* 0x7d3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7d6:
	/* 0x7d6: je     15f0 <generic_sleepable_offload+0x15f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d6, 0x15f0, x86_l_15f0);
x86_l_7dc:
	/* 0x7dc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7df:
	/* 0x7df: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7df, 0x120, x86_l_120);
x86_l_7e5:
	/* 0x7e5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ea:
	/* 0x7ea: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ed:
	/* 0x7ed: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x7ed, 0x120, x86_l_120);
x86_l_7f2:
	/* 0x7f2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_7f5:
	/* 0x7f5: jg     8aa <generic_sleepable_offload+0x8aa> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7f5, 0x8aa, x86_l_8aa);
x86_l_7fb:
	/* 0x7fb: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_7fe:
	/* 0x7fe: je     d93 <generic_sleepable_offload+0xd93> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7fe, 0xd93, x86_l_d93);
x86_l_804:
	/* 0x804: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_807:
	/* 0x807: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x807, 0x120, x86_l_120);
x86_l_80d:
	/* 0x80d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_810:
	/* 0x810: jg     12c3 <generic_sleepable_offload+0x12c3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x810, 0x12c3, x86_l_12c3);
x86_l_816:
	/* 0x816: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_819:
	/* 0x819: je     161c <generic_sleepable_offload+0x161c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x819, 0x161c, x86_l_161c);
x86_l_81f:
	/* 0x81f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_822:
	/* 0x822: je     b95 <generic_sleepable_offload+0xb95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x822, 0xb95, x86_l_b95);
x86_l_828:
	/* 0x828: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x828, 0x120, x86_l_120);
x86_l_82d:
	/* 0x82d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_830:
	/* 0x830: jg     8dc <generic_sleepable_offload+0x8dc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x830, 0x8dc, x86_l_8dc);
x86_l_836:
	/* 0x836: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_839:
	/* 0x839: je     cbd <generic_sleepable_offload+0xcbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x839, 0xcbd, x86_l_cbd);
x86_l_83f:
	/* 0x83f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_842:
	/* 0x842: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x842, 0x120, x86_l_120);
x86_l_848:
	/* 0x848: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_84b:
	/* 0x84b: jg     10da <generic_sleepable_offload+0x10da> */
	X86_SIM_X86_JCC(X86_CC_G, 0x84b, 0x10da, x86_l_10da);
x86_l_851:
	/* 0x851: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_854:
	/* 0x854: je     16a5 <generic_sleepable_offload+0x16a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x854, 0x16a5, x86_l_16a5);
x86_l_85a:
	/* 0x85a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_85d:
	/* 0x85d: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x85d, 0x120, x86_l_120);
x86_l_863:
	/* 0x863: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_868:
	/* 0x868: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_86b:
	/* 0x86b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x86b, 0x120, x86_l_120);
x86_l_870:
	/* 0x870: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_873:
	/* 0x873: je     ce5 <generic_sleepable_offload+0xce5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x873, 0xce5, x86_l_ce5);
x86_l_879:
	/* 0x879: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_87c:
	/* 0x87c: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x87c, 0x120, x86_l_120);
x86_l_882:
	/* 0x882: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_885:
	/* 0x885: jg     10f9 <generic_sleepable_offload+0x10f9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x885, 0x10f9, x86_l_10f9);
x86_l_88b:
	/* 0x88b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_88e:
	/* 0x88e: je     15fa <generic_sleepable_offload+0x15fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88e, 0x15fa, x86_l_15fa);
x86_l_894:
	/* 0x894: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_897:
	/* 0x897: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x897, 0x120, x86_l_120);
x86_l_89d:
	/* 0x89d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8a2:
	/* 0x8a2: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a5:
	/* 0x8a5: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x8a5, 0x120, x86_l_120);
x86_l_8aa:
	/* 0x8aa: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_8ad:
	/* 0x8ad: je     daf <generic_sleepable_offload+0xdaf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ad, 0xdaf, x86_l_daf);
x86_l_8b3:
	/* 0x8b3: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_8b6:
	/* 0x8b6: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b6, 0x120, x86_l_120);
x86_l_8bc:
	/* 0x8bc: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8bf:
	/* 0x8bf: jg     12d2 <generic_sleepable_offload+0x12d2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8bf, 0x12d2, x86_l_12d2);
x86_l_8c5:
	/* 0x8c5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8c8:
	/* 0x8c8: je     1628 <generic_sleepable_offload+0x1628> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c8, 0x1628, x86_l_1628);
x86_l_8ce:
	/* 0x8ce: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8d1:
	/* 0x8d1: je     c0a <generic_sleepable_offload+0xc0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d1, 0xc0a, x86_l_c0a);
x86_l_8d7:
	/* 0x8d7: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x8d7, 0x120, x86_l_120);
x86_l_8dc:
	/* 0x8dc: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_8df:
	/* 0x8df: je     ed2 <generic_sleepable_offload+0xed2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8df, 0xed2, x86_l_ed2);
x86_l_8e5:
	/* 0x8e5: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_8e8:
	/* 0x8e8: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e8, 0x120, x86_l_120);
x86_l_8ee:
	/* 0x8ee: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8f1:
	/* 0x8f1: jg     151c <generic_sleepable_offload+0x151c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8f1, 0x151c, x86_l_151c);
x86_l_8f7:
	/* 0x8f7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8fa:
	/* 0x8fa: je     16b1 <generic_sleepable_offload+0x16b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fa, 0x16b1, x86_l_16b1);
x86_l_900:
	/* 0x900: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_903:
	/* 0x903: je     c76 <generic_sleepable_offload+0xc76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x903, 0xc76, x86_l_c76);
x86_l_909:
	/* 0x909: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x909, 0x120, x86_l_120);
x86_l_90e:
	/* 0x90e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_913:
	/* 0x913: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_916:
	/* 0x916: je     927 <generic_sleepable_offload+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x916, 0x927, x86_l_927);
x86_l_918:
	/* 0x918: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_91d:
	/* 0x91d: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_922:
	/* 0x922: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_925:
	/* 0x925: jne    93a <generic_sleepable_offload+0x93a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x925, 0x93a, x86_l_93a);
x86_l_927:
	/* 0x927: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_92a:
	/* 0x92a: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_92c:
	/* 0x92c: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_92e:
	/* 0x92e: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_933:
	/* 0x933: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_935:
	/* 0x935: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_93a:
	/* 0x93a: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_93f:
	/* 0x93f: add    rsi,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_942:
	/* 0x942: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_947:
	/* 0x947: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_94c:
	/* 0x94c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_951:
	/* 0x951: add    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_954:
	/* 0x954: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_957:
	/* 0x957: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_95c:
	/* 0x95c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95e:
	/* 0x95e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_960:
	/* 0x960: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x960, 0x120, x86_l_120);
x86_l_966:
	/* 0x966: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_96b:
	/* 0x96b: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_970:
	/* 0x970: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_975:
	/* 0x975: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_97b:
	/* 0x97b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_97e:
	/* 0x97e: jle    9c8 <generic_sleepable_offload+0x9c8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x97e, 0x9c8, x86_l_9c8);
x86_l_980:
	/* 0x980: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_983:
	/* 0x983: jle    d0d <generic_sleepable_offload+0xd0d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x983, 0xd0d, x86_l_d0d);
x86_l_989:
	/* 0x989: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_98c:
	/* 0x98c: jle    11c6 <generic_sleepable_offload+0x11c6> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x98c, 0x11c6, x86_l_11c6);
x86_l_992:
	/* 0x992: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_995:
	/* 0x995: je     1833 <generic_sleepable_offload+0x1833> */
	X86_SIM_X86_JCC(X86_CC_E, 0x995, 0x1833, x86_l_1833);
x86_l_99b:
	/* 0x99b: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_99e:
	/* 0x99e: je     1749 <generic_sleepable_offload+0x1749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99e, 0x1749, x86_l_1749);
x86_l_9a4:
	/* 0x9a4: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_9a7:
	/* 0x9a7: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9a7, 0x120, x86_l_120);
x86_l_9ad:
	/* 0x9ad: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_9b0:
	/* 0x9b0: jg     11f0 <generic_sleepable_offload+0x11f0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9b0, 0x11f0, x86_l_11f0);
x86_l_9b6:
	/* 0x9b6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9b9:
	/* 0x9b9: jne    b03 <generic_sleepable_offload+0xb03> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b9, 0xb03, x86_l_b03);
x86_l_9bf:
	/* 0x9bf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c3:
	/* 0x9c3: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x9c3, 0x11e, x86_l_11e);
x86_l_9c8:
	/* 0x9c8: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_9cb:
	/* 0x9cb: jg     d50 <generic_sleepable_offload+0xd50> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9cb, 0xd50, x86_l_d50);
x86_l_9d1:
	/* 0x9d1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9d4:
	/* 0x9d4: jg     1152 <generic_sleepable_offload+0x1152> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9d4, 0x1152, x86_l_1152);
x86_l_9da:
	/* 0x9da: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9dc:
	/* 0x9dc: je     178c <generic_sleepable_offload+0x178c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9dc, 0x178c, x86_l_178c);
x86_l_9e2:
	/* 0x9e2: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9e5:
	/* 0x9e5: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e5, 0x120, x86_l_120);
x86_l_9eb:
	/* 0x9eb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_9ee:
	/* 0x9ee: jg     1abe <generic_sleepable_offload+0x1abe> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9ee, 0x1abe, x86_l_1abe);
x86_l_9f4:
	/* 0x9f4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9f7:
	/* 0x9f7: je     15f0 <generic_sleepable_offload+0x15f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f7, 0x15f0, x86_l_15f0);
x86_l_9fd:
	/* 0x9fd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a00:
	/* 0xa00: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa00, 0x120, x86_l_120);
x86_l_a06:
	/* 0xa06: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0b:
	/* 0xa0b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0e:
	/* 0xa0e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xa0e, 0x120, x86_l_120);
x86_l_a13:
	/* 0xa13: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a16:
	/* 0xa16: je     104f <generic_sleepable_offload+0x104f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa16, 0x104f, x86_l_104f);
x86_l_a1c:
	/* 0xa1c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a1f:
	/* 0xa1f: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa1f, 0x120, x86_l_120);
x86_l_a25:
	/* 0xa25: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a28:
	/* 0xa28: jg     15be <generic_sleepable_offload+0x15be> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa28, 0x15be, x86_l_15be);
x86_l_a2e:
	/* 0xa2e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a31:
	/* 0xa31: je     1971 <generic_sleepable_offload+0x1971> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa31, 0x1971, x86_l_1971);
x86_l_a37:
	/* 0xa37: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a3a:
	/* 0xa3a: je     a6e <generic_sleepable_offload+0xa6e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3a, 0xa6e, x86_l_a6e);
x86_l_a3c:
	/* 0xa3c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xa3c, 0x120, x86_l_120);
x86_l_a41:
	/* 0xa41: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a44:
	/* 0xa44: je     106b <generic_sleepable_offload+0x106b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa44, 0x106b, x86_l_106b);
x86_l_a4a:
	/* 0xa4a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a4d:
	/* 0xa4d: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa4d, 0x120, x86_l_120);
x86_l_a53:
	/* 0xa53: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a56:
	/* 0xa56: jg     15d1 <generic_sleepable_offload+0x15d1> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa56, 0x15d1, x86_l_15d1);
x86_l_a5c:
	/* 0xa5c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a5f:
	/* 0xa5f: je     11e6 <generic_sleepable_offload+0x11e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5f, 0x11e6, x86_l_11e6);
x86_l_a65:
	/* 0xa65: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a68:
	/* 0xa68: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa68, 0x120, x86_l_120);
x86_l_a6e:
	/* 0xa6e: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a73:
	/* 0xa73: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a76:
	/* 0xa76: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xa76, 0x120, x86_l_120);
x86_l_a7b:
	/* 0xa7b: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a80:
	/* 0xa80: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a83:
	/* 0xa83: je     a94 <generic_sleepable_offload+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa83, 0xa94, x86_l_a94);
x86_l_a85:
	/* 0xa85: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a8a:
	/* 0xa8a: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_a8f:
	/* 0xa8f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a92:
	/* 0xa92: jne    aa7 <generic_sleepable_offload+0xaa7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa92, 0xaa7, x86_l_aa7);
x86_l_a94:
	/* 0xa94: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_a97:
	/* 0xa97: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_a99:
	/* 0xa99: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_a9b:
	/* 0xa9b: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_aa0:
	/* 0xaa0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_aa2:
	/* 0xaa2: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_aa7:
	/* 0xaa7: add    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_aaa:
	/* 0xaaa: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_aaf:
	/* 0xaaf: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_ab4:
	/* 0xab4: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_ab9:
	/* 0xab9: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_abf:
	/* 0xabf: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_ac2:
	/* 0xac2: jle    b18 <generic_sleepable_offload+0xb18> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xac2, 0xb18, x86_l_b18);
x86_l_ac4:
	/* 0xac4: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_ac7:
	/* 0xac7: jle    b63 <generic_sleepable_offload+0xb63> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xac7, 0xb63, x86_l_b63);
x86_l_acd:
	/* 0xacd: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_ad0:
	/* 0xad0: jle    c83 <generic_sleepable_offload+0xc83> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xad0, 0xc83, x86_l_c83);
x86_l_ad6:
	/* 0xad6: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_ad9:
	/* 0xad9: je     102f <generic_sleepable_offload+0x102f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad9, 0x102f, x86_l_102f);
x86_l_adf:
	/* 0xadf: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_ae2:
	/* 0xae2: je     e9b <generic_sleepable_offload+0xe9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae2, 0xe9b, x86_l_e9b);
x86_l_ae8:
	/* 0xae8: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_aeb:
	/* 0xaeb: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaeb, 0x120, x86_l_120);
x86_l_af1:
	/* 0xaf1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_af4:
	/* 0xaf4: jg     11f0 <generic_sleepable_offload+0x11f0> */
	X86_SIM_X86_JCC(X86_CC_G, 0xaf4, 0x11f0, x86_l_11f0);
x86_l_afa:
	/* 0xafa: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_afd:
	/* 0xafd: je     9bf <generic_sleepable_offload+0x9bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xafd, 0x9bf, x86_l_9bf);
x86_l_b03:
	/* 0xb03: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b06:
	/* 0xb06: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb06, 0x120, x86_l_120);
x86_l_b0c:
	/* 0xb0c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b10:
	/* 0xb10: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b13:
	/* 0xb13: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xb13, 0x120, x86_l_120);
x86_l_b18:
	/* 0xb18: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_b1b:
	/* 0xb1b: jg     ba2 <generic_sleepable_offload+0xba2> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb1b, 0xba2, x86_l_ba2);
x86_l_b21:
	/* 0xb21: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b24:
	/* 0xb24: jg     c17 <generic_sleepable_offload+0xc17> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb24, 0xc17, x86_l_c17);
x86_l_b2a:
	/* 0xb2a: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b2c:
	/* 0xb2c: je     f78 <generic_sleepable_offload+0xf78> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2c, 0xf78, x86_l_f78);
x86_l_b32:
	/* 0xb32: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b35:
	/* 0xb35: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb35, 0x120, x86_l_120);
x86_l_b3b:
	/* 0xb3b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b3e:
	/* 0xb3e: jg     1552 <generic_sleepable_offload+0x1552> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb3e, 0x1552, x86_l_1552);
x86_l_b44:
	/* 0xb44: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b47:
	/* 0xb47: je     1941 <generic_sleepable_offload+0x1941> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb47, 0x1941, x86_l_1941);
x86_l_b4d:
	/* 0xb4d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b50:
	/* 0xb50: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb50, 0x120, x86_l_120);
x86_l_b56:
	/* 0xb56: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b5b:
	/* 0xb5b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5e:
	/* 0xb5e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xb5e, 0x120, x86_l_120);
x86_l_b63:
	/* 0xb63: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b66:
	/* 0xb66: jg     bdd <generic_sleepable_offload+0xbdd> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb66, 0xbdd, x86_l_bdd);
x86_l_b68:
	/* 0xb68: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b6b:
	/* 0xb6b: je     e07 <generic_sleepable_offload+0xe07> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6b, 0xe07, x86_l_e07);
x86_l_b71:
	/* 0xb71: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b74:
	/* 0xb74: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb74, 0x120, x86_l_120);
x86_l_b7a:
	/* 0xb7a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b7d:
	/* 0xb7d: jg     131a <generic_sleepable_offload+0x131a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb7d, 0x131a, x86_l_131a);
x86_l_b83:
	/* 0xb83: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b86:
	/* 0xb86: je     161c <generic_sleepable_offload+0x161c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb86, 0x161c, x86_l_161c);
x86_l_b8c:
	/* 0xb8c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b8f:
	/* 0xb8f: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb8f, 0x120, x86_l_120);
x86_l_b95:
	/* 0xb95: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b9a:
	/* 0xb9a: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9d:
	/* 0xb9d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xb9d, 0x120, x86_l_120);
x86_l_ba2:
	/* 0xba2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_ba5:
	/* 0xba5: jg     c49 <generic_sleepable_offload+0xc49> */
	X86_SIM_X86_JCC(X86_CC_G, 0xba5, 0xc49, x86_l_c49);
x86_l_bab:
	/* 0xbab: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_bae:
	/* 0xbae: je     f9b <generic_sleepable_offload+0xf9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbae, 0xf9b, x86_l_f9b);
x86_l_bb4:
	/* 0xbb4: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_bb7:
	/* 0xbb7: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbb7, 0x120, x86_l_120);
x86_l_bbd:
	/* 0xbbd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bc0:
	/* 0xbc0: jg     1571 <generic_sleepable_offload+0x1571> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbc0, 0x1571, x86_l_1571);
x86_l_bc6:
	/* 0xbc6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bc9:
	/* 0xbc9: je     16a5 <generic_sleepable_offload+0x16a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc9, 0x16a5, x86_l_16a5);
x86_l_bcf:
	/* 0xbcf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bd2:
	/* 0xbd2: je     d86 <generic_sleepable_offload+0xd86> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd2, 0xd86, x86_l_d86);
x86_l_bd8:
	/* 0xbd8: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xbd8, 0x120, x86_l_120);
x86_l_bdd:
	/* 0xbdd: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_be0:
	/* 0xbe0: je     e2f <generic_sleepable_offload+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe0, 0xe2f, x86_l_e2f);
x86_l_be6:
	/* 0xbe6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_be9:
	/* 0xbe9: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbe9, 0x120, x86_l_120);
x86_l_bef:
	/* 0xbef: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bf2:
	/* 0xbf2: jg     1341 <generic_sleepable_offload+0x1341> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbf2, 0x1341, x86_l_1341);
x86_l_bf8:
	/* 0xbf8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bfb:
	/* 0xbfb: je     1628 <generic_sleepable_offload+0x1628> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbfb, 0x1628, x86_l_1628);
x86_l_c01:
	/* 0xc01: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c04:
	/* 0xc04: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc04, 0x120, x86_l_120);
x86_l_c0a:
	/* 0xc0a: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c0f:
	/* 0xc0f: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c12:
	/* 0xc12: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xc12, 0x120, x86_l_120);
x86_l_c17:
	/* 0xc17: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c1a:
	/* 0xc1a: je     fbb <generic_sleepable_offload+0xfbb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc1a, 0xfbb, x86_l_fbb);
x86_l_c20:
	/* 0xc20: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_c23:
	/* 0xc23: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc23, 0x120, x86_l_120);
x86_l_c29:
	/* 0xc29: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c2c:
	/* 0xc2c: jg     1588 <generic_sleepable_offload+0x1588> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc2c, 0x1588, x86_l_1588);
x86_l_c32:
	/* 0xc32: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c35:
	/* 0xc35: je     194d <generic_sleepable_offload+0x194d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc35, 0x194d, x86_l_194d);
x86_l_c3b:
	/* 0xc3b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c3e:
	/* 0xc3e: je     117f <generic_sleepable_offload+0x117f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3e, 0x117f, x86_l_117f);
x86_l_c44:
	/* 0xc44: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xc44, 0x120, x86_l_120);
x86_l_c49:
	/* 0xc49: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_c4c:
	/* 0xc4c: je     fe3 <generic_sleepable_offload+0xfe3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4c, 0xfe3, x86_l_fe3);
x86_l_c52:
	/* 0xc52: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_c55:
	/* 0xc55: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc55, 0x120, x86_l_120);
x86_l_c5b:
	/* 0xc5b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c5e:
	/* 0xc5e: jg     159f <generic_sleepable_offload+0x159f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc5e, 0x159f, x86_l_159f);
x86_l_c64:
	/* 0xc64: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c67:
	/* 0xc67: je     16b1 <generic_sleepable_offload+0x16b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc67, 0x16b1, x86_l_16b1);
x86_l_c6d:
	/* 0xc6d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c70:
	/* 0xc70: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc70, 0x120, x86_l_120);
x86_l_c76:
	/* 0xc76: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c7b:
	/* 0xc7b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7e:
	/* 0xc7e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xc7e, 0x120, x86_l_120);
x86_l_c83:
	/* 0xc83: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_c86:
	/* 0xc86: je     1093 <generic_sleepable_offload+0x1093> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc86, 0x1093, x86_l_1093);
x86_l_c8c:
	/* 0xc8c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_c8f:
	/* 0xc8f: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc8f, 0x120, x86_l_120);
x86_l_c95:
	/* 0xc95: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c98:
	/* 0xc98: jg     120e <generic_sleepable_offload+0x120e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc98, 0x120e, x86_l_120e);
x86_l_c9e:
	/* 0xc9e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ca1:
	/* 0xca1: je     11e6 <generic_sleepable_offload+0x11e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca1, 0x11e6, x86_l_11e6);
x86_l_ca7:
	/* 0xca7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_caa:
	/* 0xcaa: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcaa, 0x120, x86_l_120);
x86_l_cb0:
	/* 0xcb0: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cb5:
	/* 0xcb5: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb8:
	/* 0xcb8: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xcb8, 0x120, x86_l_120);
x86_l_cbd:
	/* 0xcbd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_cc0:
	/* 0xcc0: jg     f12 <generic_sleepable_offload+0xf12> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcc0, 0xf12, x86_l_f12);
x86_l_cc6:
	/* 0xcc6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cc9:
	/* 0xcc9: je     17d3 <generic_sleepable_offload+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc9, 0x17d3, x86_l_17d3);
x86_l_ccf:
	/* 0xccf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cd2:
	/* 0xcd2: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcd2, 0x120, x86_l_120);
x86_l_cd8:
	/* 0xcd8: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cdd:
	/* 0xcdd: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce0:
	/* 0xce0: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xce0, 0x120, x86_l_120);
x86_l_ce5:
	/* 0xce5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ce8:
	/* 0xce8: jg     f31 <generic_sleepable_offload+0xf31> */
	X86_SIM_X86_JCC(X86_CC_G, 0xce8, 0xf31, x86_l_f31);
x86_l_cee:
	/* 0xcee: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cf1:
	/* 0xcf1: je     1801 <generic_sleepable_offload+0x1801> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf1, 0x1801, x86_l_1801);
x86_l_cf7:
	/* 0xcf7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cfa:
	/* 0xcfa: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcfa, 0x120, x86_l_120);
x86_l_d00:
	/* 0xd00: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d05:
	/* 0xd05: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d08:
	/* 0xd08: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xd08, 0x120, x86_l_120);
x86_l_d0d:
	/* 0xd0d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_d10:
	/* 0xd10: jg     1118 <generic_sleepable_offload+0x1118> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd10, 0x1118, x86_l_1118);
x86_l_d16:
	/* 0xd16: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d19:
	/* 0xd19: je     16f9 <generic_sleepable_offload+0x16f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd19, 0x16f9, x86_l_16f9);
x86_l_d1f:
	/* 0xd1f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_d22:
	/* 0xd22: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd22, 0x120, x86_l_120);
x86_l_d28:
	/* 0xd28: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d2b:
	/* 0xd2b: jg     19bb <generic_sleepable_offload+0x19bb> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd2b, 0x19bb, x86_l_19bb);
x86_l_d31:
	/* 0xd31: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d34:
	/* 0xd34: je     1883 <generic_sleepable_offload+0x1883> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd34, 0x1883, x86_l_1883);
x86_l_d3a:
	/* 0xd3a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d3d:
	/* 0xd3d: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd3d, 0x120, x86_l_120);
x86_l_d43:
	/* 0xd43: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d48:
	/* 0xd48: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4b:
	/* 0xd4b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xd4b, 0x120, x86_l_120);
x86_l_d50:
	/* 0xd50: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d53:
	/* 0xd53: jg     118c <generic_sleepable_offload+0x118c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd53, 0x118c, x86_l_118c);
x86_l_d59:
	/* 0xd59: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d5c:
	/* 0xd5c: je     17af <generic_sleepable_offload+0x17af> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5c, 0x17af, x86_l_17af);
x86_l_d62:
	/* 0xd62: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d65:
	/* 0xd65: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd65, 0x120, x86_l_120);
x86_l_d6b:
	/* 0xd6b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d6e:
	/* 0xd6e: jg     1add <generic_sleepable_offload+0x1add> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd6e, 0x1add, x86_l_1add);
x86_l_d74:
	/* 0xd74: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d77:
	/* 0xd77: je     18c0 <generic_sleepable_offload+0x18c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd77, 0x18c0, x86_l_18c0);
x86_l_d7d:
	/* 0xd7d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d80:
	/* 0xd80: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd80, 0x120, x86_l_120);
x86_l_d86:
	/* 0xd86: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d8b:
	/* 0xd8b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8e:
	/* 0xd8e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xd8e, 0x120, x86_l_120);
x86_l_d93:
	/* 0xd93: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d96:
	/* 0xd96: jg     122d <generic_sleepable_offload+0x122d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd96, 0x122d, x86_l_122d);
x86_l_d9c:
	/* 0xd9c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d9f:
	/* 0xd9f: je     1604 <generic_sleepable_offload+0x1604> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9f, 0x1604, x86_l_1604);
x86_l_da5:
	/* 0xda5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_da8:
	/* 0xda8: je     e22 <generic_sleepable_offload+0xe22> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda8, 0xe22, x86_l_e22);
x86_l_daa:
	/* 0xdaa: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xdaa, 0x120, x86_l_120);
x86_l_daf:
	/* 0xdaf: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_db2:
	/* 0xdb2: jg     123c <generic_sleepable_offload+0x123c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdb2, 0x123c, x86_l_123c);
x86_l_db8:
	/* 0xdb8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dbb:
	/* 0xdbb: je     1610 <generic_sleepable_offload+0x1610> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdbb, 0x1610, x86_l_1610);
x86_l_dc1:
	/* 0xdc1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dc4:
	/* 0xdc4: je     e4a <generic_sleepable_offload+0xe4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdc4, 0xe4a, x86_l_e4a);
x86_l_dca:
	/* 0xdca: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xdca, 0x120, x86_l_120);
x86_l_dcf:
	/* 0xdcf: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dd2:
	/* 0xdd2: jg     124b <generic_sleepable_offload+0x124b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdd2, 0x124b, x86_l_124b);
x86_l_dd8:
	/* 0xdd8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ddb:
	/* 0xddb: je     186f <generic_sleepable_offload+0x186f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xddb, 0x186f, x86_l_186f);
x86_l_de1:
	/* 0xde1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_de4:
	/* 0xde4: je     e22 <generic_sleepable_offload+0xe22> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde4, 0xe22, x86_l_e22);
x86_l_de6:
	/* 0xde6: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xde6, 0x120, x86_l_120);
x86_l_deb:
	/* 0xdeb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dee:
	/* 0xdee: jg     1266 <generic_sleepable_offload+0x1266> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdee, 0x1266, x86_l_1266);
x86_l_df4:
	/* 0xdf4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_df7:
	/* 0xdf7: je     1879 <generic_sleepable_offload+0x1879> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf7, 0x1879, x86_l_1879);
x86_l_dfd:
	/* 0xdfd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e00:
	/* 0xe00: je     e4a <generic_sleepable_offload+0xe4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe00, 0xe4a, x86_l_e4a);
x86_l_e02:
	/* 0xe02: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xe02, 0x120, x86_l_120);
x86_l_e07:
	/* 0xe07: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e0a:
	/* 0xe0a: jg     1275 <generic_sleepable_offload+0x1275> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe0a, 0x1275, x86_l_1275);
x86_l_e10:
	/* 0xe10: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e13:
	/* 0xe13: je     1604 <generic_sleepable_offload+0x1604> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe13, 0x1604, x86_l_1604);
x86_l_e19:
	/* 0xe19: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e1c:
	/* 0xe1c: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1c, 0x120, x86_l_120);
x86_l_e22:
	/* 0xe22: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e27:
	/* 0xe27: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2a:
	/* 0xe2a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xe2a, 0x120, x86_l_120);
x86_l_e2f:
	/* 0xe2f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e32:
	/* 0xe32: jg     129c <generic_sleepable_offload+0x129c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe32, 0x129c, x86_l_129c);
x86_l_e38:
	/* 0xe38: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e3b:
	/* 0xe3b: je     1610 <generic_sleepable_offload+0x1610> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe3b, 0x1610, x86_l_1610);
x86_l_e41:
	/* 0xe41: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e44:
	/* 0xe44: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe44, 0x120, x86_l_120);
x86_l_e4a:
	/* 0xe4a: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e4f:
	/* 0xe4f: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e52:
	/* 0xe52: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xe52, 0x120, x86_l_120);
x86_l_e57:
	/* 0xe57: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e5a:
	/* 0xe5a: jg     12e5 <generic_sleepable_offload+0x12e5> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe5a, 0x12e5, x86_l_12e5);
x86_l_e60:
	/* 0xe60: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e63:
	/* 0xe63: je     18e0 <generic_sleepable_offload+0x18e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe63, 0x18e0, x86_l_18e0);
x86_l_e69:
	/* 0xe69: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e6c:
	/* 0xe6c: je     e8e <generic_sleepable_offload+0xe8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe6c, 0xe8e, x86_l_e8e);
x86_l_e6e:
	/* 0xe6e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xe6e, 0x120, x86_l_120);
x86_l_e73:
	/* 0xe73: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e76:
	/* 0xe76: jg     1368 <generic_sleepable_offload+0x1368> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe76, 0x1368, x86_l_1368);
x86_l_e7c:
	/* 0xe7c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e7f:
	/* 0xe7f: je     119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7f, 0x119, x86_l_119);
x86_l_e85:
	/* 0xe85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e88:
	/* 0xe88: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe88, 0x120, x86_l_120);
x86_l_e8e:
	/* 0xe8e: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e93:
	/* 0xe93: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e96:
	/* 0xe96: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xe96, 0x120, x86_l_120);
x86_l_e9b:
	/* 0xe9b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e9e:
	/* 0xe9e: jg     176d <generic_sleepable_offload+0x176d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe9e, 0x176d, x86_l_176d);
x86_l_ea4:
	/* 0xea4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea7:
	/* 0xea7: jne    1757 <generic_sleepable_offload+0x1757> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea7, 0x1757, x86_l_1757);
x86_l_ead:
	/* 0xead: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xead, 0x119, x86_l_119);
x86_l_eb2:
	/* 0xeb2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_eb5:
	/* 0xeb5: jg     1387 <generic_sleepable_offload+0x1387> */
	X86_SIM_X86_JCC(X86_CC_G, 0xeb5, 0x1387, x86_l_1387);
x86_l_ebb:
	/* 0xebb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ebe:
	/* 0xebe: je     1658 <generic_sleepable_offload+0x1658> */
	X86_SIM_X86_JCC(X86_CC_E, 0xebe, 0x1658, x86_l_1658);
x86_l_ec4:
	/* 0xec4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ec7:
	/* 0xec7: je     f93 <generic_sleepable_offload+0xf93> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec7, 0xf93, x86_l_f93);
x86_l_ecd:
	/* 0xecd: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xecd, 0x120, x86_l_120);
x86_l_ed2:
	/* 0xed2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ed5:
	/* 0xed5: jg     139e <generic_sleepable_offload+0x139e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xed5, 0x139e, x86_l_139e);
x86_l_edb:
	/* 0xedb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ede:
	/* 0xede: je     165f <generic_sleepable_offload+0x165f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xede, 0x165f, x86_l_165f);
x86_l_ee4:
	/* 0xee4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ee7:
	/* 0xee7: je     ffe <generic_sleepable_offload+0xffe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee7, 0xffe, x86_l_ffe);
x86_l_eed:
	/* 0xeed: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xeed, 0x120, x86_l_120);
x86_l_ef2:
	/* 0xef2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ef5:
	/* 0xef5: jg     13b5 <generic_sleepable_offload+0x13b5> */
	X86_SIM_X86_JCC(X86_CC_G, 0xef5, 0x13b5, x86_l_13b5);
x86_l_efb:
	/* 0xefb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_efe:
	/* 0xefe: je     167e <generic_sleepable_offload+0x167e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xefe, 0x167e, x86_l_167e);
x86_l_f04:
	/* 0xf04: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f07:
	/* 0xf07: je     1026 <generic_sleepable_offload+0x1026> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf07, 0x1026, x86_l_1026);
x86_l_f0d:
	/* 0xf0d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xf0d, 0x120, x86_l_120);
x86_l_f12:
	/* 0xf12: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f15:
	/* 0xf15: je     1640 <generic_sleepable_offload+0x1640> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf15, 0x1640, x86_l_1640);
x86_l_f1b:
	/* 0xf1b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f1e:
	/* 0xf1e: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf1e, 0x120, x86_l_120);
x86_l_f24:
	/* 0xf24: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f29:
	/* 0xf29: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2c:
	/* 0xf2c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xf2c, 0x120, x86_l_120);
x86_l_f31:
	/* 0xf31: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f34:
	/* 0xf34: je     164c <generic_sleepable_offload+0x164c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf34, 0x164c, x86_l_164c);
x86_l_f3a:
	/* 0xf3a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f3d:
	/* 0xf3d: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3d, 0x120, x86_l_120);
x86_l_f43:
	/* 0xf43: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f48:
	/* 0xf48: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4b:
	/* 0xf4b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xf4b, 0x120, x86_l_120);
x86_l_f50:
	/* 0xf50: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f53:
	/* 0xf53: jg     13e6 <generic_sleepable_offload+0x13e6> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf53, 0x13e6, x86_l_13e6);
x86_l_f59:
	/* 0xf59: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f5c:
	/* 0xf5c: je     18a3 <generic_sleepable_offload+0x18a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5c, 0x18a3, x86_l_18a3);
x86_l_f62:
	/* 0xf62: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f65:
	/* 0xf65: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf65, 0x120, x86_l_120);
x86_l_f6b:
	/* 0xf6b: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f70:
	/* 0xf70: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f73:
	/* 0xf73: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xf73, 0x120, x86_l_120);
x86_l_f78:
	/* 0xf78: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f7b:
	/* 0xf7b: jg     1405 <generic_sleepable_offload+0x1405> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf7b, 0x1405, x86_l_1405);
x86_l_f81:
	/* 0xf81: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f84:
	/* 0xf84: je     1658 <generic_sleepable_offload+0x1658> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf84, 0x1658, x86_l_1658);
x86_l_f8a:
	/* 0xf8a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f8d:
	/* 0xf8d: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf8d, 0x120, x86_l_120);
x86_l_f93:
	/* 0xf93: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f96:
	/* 0xf96: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xf96, 0x120, x86_l_120);
x86_l_f9b:
	/* 0xf9b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f9e:
	/* 0xf9e: jg     141f <generic_sleepable_offload+0x141f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf9e, 0x141f, x86_l_141f);
x86_l_fa4:
	/* 0xfa4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fa7:
	/* 0xfa7: je     18f3 <generic_sleepable_offload+0x18f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa7, 0x18f3, x86_l_18f3);
x86_l_fad:
	/* 0xfad: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fb0:
	/* 0xfb0: je     17c6 <generic_sleepable_offload+0x17c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb0, 0x17c6, x86_l_17c6);
x86_l_fb6:
	/* 0xfb6: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xfb6, 0x120, x86_l_120);
x86_l_fbb:
	/* 0xfbb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fbe:
	/* 0xfbe: jg     1436 <generic_sleepable_offload+0x1436> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfbe, 0x1436, x86_l_1436);
x86_l_fc4:
	/* 0xfc4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fc7:
	/* 0xfc7: je     18ff <generic_sleepable_offload+0x18ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc7, 0x18ff, x86_l_18ff);
x86_l_fcd:
	/* 0xfcd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fd0:
	/* 0xfd0: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd0, 0x120, x86_l_120);
x86_l_fd6:
	/* 0xfd6: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fdb:
	/* 0xfdb: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fde:
	/* 0xfde: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0xfde, 0x120, x86_l_120);
x86_l_fe3:
	/* 0xfe3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fe6:
	/* 0xfe6: jg     1455 <generic_sleepable_offload+0x1455> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfe6, 0x1455, x86_l_1455);
x86_l_fec:
	/* 0xfec: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fef:
	/* 0xfef: je     165f <generic_sleepable_offload+0x165f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfef, 0x165f, x86_l_165f);
x86_l_ff5:
	/* 0xff5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ff8:
	/* 0xff8: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff8, 0x120, x86_l_120);
x86_l_ffe:
	/* 0xffe: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1003:
	/* 0x1003: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1006:
	/* 0x1006: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1006, 0x120, x86_l_120);
x86_l_100b:
	/* 0x100b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_100e:
	/* 0x100e: jg     1474 <generic_sleepable_offload+0x1474> */
	X86_SIM_X86_JCC(X86_CC_G, 0x100e, 0x1474, x86_l_1474);
x86_l_1014:
	/* 0x1014: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1017:
	/* 0x1017: je     167e <generic_sleepable_offload+0x167e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1017, 0x167e, x86_l_167e);
x86_l_101d:
	/* 0x101d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1020:
	/* 0x1020: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1020, 0x120, x86_l_120);
x86_l_1026:
	/* 0x1026: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102a:
	/* 0x102a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x102a, 0x120, x86_l_120);
x86_l_102f:
	/* 0x102f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1032:
	/* 0x1032: jg     148f <generic_sleepable_offload+0x148f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1032, 0x148f, x86_l_148f);
x86_l_1038:
	/* 0x1038: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_103b:
	/* 0x103b: je     18ad <generic_sleepable_offload+0x18ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103b, 0x18ad, x86_l_18ad);
x86_l_1041:
	/* 0x1041: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1044:
	/* 0x1044: je     184a <generic_sleepable_offload+0x184a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1044, 0x184a, x86_l_184a);
x86_l_104a:
	/* 0x104a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x104a, 0x120, x86_l_120);
x86_l_104f:
	/* 0x104f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1052:
	/* 0x1052: jg     14a6 <generic_sleepable_offload+0x14a6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1052, 0x14a6, x86_l_14a6);
x86_l_1058:
	/* 0x1058: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_105b:
	/* 0x105b: je     192a <generic_sleepable_offload+0x192a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105b, 0x192a, x86_l_192a);
x86_l_1061:
	/* 0x1061: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1064:
	/* 0x1064: je     1086 <generic_sleepable_offload+0x1086> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1064, 0x1086, x86_l_1086);
x86_l_1066:
	/* 0x1066: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1066, 0x120, x86_l_120);
x86_l_106b:
	/* 0x106b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_106e:
	/* 0x106e: jg     14b9 <generic_sleepable_offload+0x14b9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x106e, 0x14b9, x86_l_14b9);
x86_l_1074:
	/* 0x1074: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1077:
	/* 0x1077: je     1865 <generic_sleepable_offload+0x1865> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1077, 0x1865, x86_l_1865);
x86_l_107d:
	/* 0x107d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1080:
	/* 0x1080: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1080, 0x120, x86_l_120);
x86_l_1086:
	/* 0x1086: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_108b:
	/* 0x108b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108e:
	/* 0x108e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x108e, 0x120, x86_l_120);
x86_l_1093:
	/* 0x1093: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1096:
	/* 0x1096: jg     14cc <generic_sleepable_offload+0x14cc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1096, 0x14cc, x86_l_14cc);
x86_l_109c:
	/* 0x109c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_109f:
	/* 0x109f: je     1865 <generic_sleepable_offload+0x1865> */
	X86_SIM_X86_JCC(X86_CC_E, 0x109f, 0x1865, x86_l_1865);
x86_l_10a5:
	/* 0x10a5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10a8:
	/* 0x10a8: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a8, 0x120, x86_l_120);
x86_l_10ae:
	/* 0x10ae: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10b3:
	/* 0x10b3: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b6:
	/* 0x10b6: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x10b6, 0x120, x86_l_120);
x86_l_10bb:
	/* 0x10bb: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10be:
	/* 0x10be: je     16bd <generic_sleepable_offload+0x16bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10be, 0x16bd, x86_l_16bd);
x86_l_10c4:
	/* 0x10c4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10c7:
	/* 0x10c7: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10c7, 0x120, x86_l_120);
x86_l_10cd:
	/* 0x10cd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d2:
	/* 0x10d2: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d5:
	/* 0x10d5: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x10d5, 0x120, x86_l_120);
x86_l_10da:
	/* 0x10da: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10dd:
	/* 0x10dd: je     16c9 <generic_sleepable_offload+0x16c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10dd, 0x16c9, x86_l_16c9);
x86_l_10e3:
	/* 0x10e3: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10e6:
	/* 0x10e6: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10e6, 0x120, x86_l_120);
x86_l_10ec:
	/* 0x10ec: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10f1:
	/* 0x10f1: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f4:
	/* 0x10f4: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x10f4, 0x120, x86_l_120);
x86_l_10f9:
	/* 0x10f9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10fc:
	/* 0x10fc: je     16d5 <generic_sleepable_offload+0x16d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fc, 0x16d5, x86_l_16d5);
x86_l_1102:
	/* 0x1102: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1105:
	/* 0x1105: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1105, 0x120, x86_l_120);
x86_l_110b:
	/* 0x110b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1110:
	/* 0x1110: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1113:
	/* 0x1113: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1113, 0x120, x86_l_120);
x86_l_1118:
	/* 0x1118: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_111b:
	/* 0x111b: je     1721 <generic_sleepable_offload+0x1721> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111b, 0x1721, x86_l_1721);
x86_l_1121:
	/* 0x1121: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1124:
	/* 0x1124: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1124, 0x120, x86_l_120);
x86_l_112a:
	/* 0x112a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_112d:
	/* 0x112d: jg     19da <generic_sleepable_offload+0x19da> */
	X86_SIM_X86_JCC(X86_CC_G, 0x112d, 0x19da, x86_l_19da);
x86_l_1133:
	/* 0x1133: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1136:
	/* 0x1136: je     188d <generic_sleepable_offload+0x188d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1136, 0x188d, x86_l_188d);
x86_l_113c:
	/* 0x113c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_113f:
	/* 0x113f: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x113f, 0x120, x86_l_120);
x86_l_1145:
	/* 0x1145: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_114a:
	/* 0x114a: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114d:
	/* 0x114d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x114d, 0x120, x86_l_120);
x86_l_1152:
	/* 0x1152: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1155:
	/* 0x1155: je     17dd <generic_sleepable_offload+0x17dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1155, 0x17dd, x86_l_17dd);
x86_l_115b:
	/* 0x115b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_115e:
	/* 0x115e: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x115e, 0x120, x86_l_120);
x86_l_1164:
	/* 0x1164: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1167:
	/* 0x1167: jg     1b04 <generic_sleepable_offload+0x1b04> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1167, 0x1b04, x86_l_1b04);
x86_l_116d:
	/* 0x116d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1170:
	/* 0x1170: je     15fa <generic_sleepable_offload+0x15fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1170, 0x15fa, x86_l_15fa);
x86_l_1176:
	/* 0x1176: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1179:
	/* 0x1179: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1179, 0x120, x86_l_120);
x86_l_117f:
	/* 0x117f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1184:
	/* 0x1184: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1187:
	/* 0x1187: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1187, 0x120, x86_l_120);
x86_l_118c:
	/* 0x118c: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_118f:
	/* 0x118f: je     180b <generic_sleepable_offload+0x180b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118f, 0x180b, x86_l_180b);
x86_l_1195:
	/* 0x1195: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1198:
	/* 0x1198: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1198, 0x120, x86_l_120);
x86_l_119e:
	/* 0x119e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11a1:
	/* 0x11a1: jg     1b2b <generic_sleepable_offload+0x1b2b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11a1, 0x1b2b, x86_l_1b2b);
x86_l_11a7:
	/* 0x11a7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11aa:
	/* 0x11aa: je     18ca <generic_sleepable_offload+0x18ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11aa, 0x18ca, x86_l_18ca);
x86_l_11b0:
	/* 0x11b0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11b3:
	/* 0x11b3: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b3, 0x120, x86_l_120);
x86_l_11b9:
	/* 0x11b9: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11be:
	/* 0x11be: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c1:
	/* 0x11c1: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x11c1, 0x120, x86_l_120);
x86_l_11c6:
	/* 0x11c6: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_11c9:
	/* 0x11c9: je     1853 <generic_sleepable_offload+0x1853> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c9, 0x1853, x86_l_1853);
x86_l_11cf:
	/* 0x11cf: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_11d2:
	/* 0x11d2: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d2, 0x120, x86_l_120);
x86_l_11d8:
	/* 0x11d8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11db:
	/* 0x11db: jg     120e <generic_sleepable_offload+0x120e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11db, 0x120e, x86_l_120e);
x86_l_11dd:
	/* 0x11dd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e0:
	/* 0x11e0: jne    ca7 <generic_sleepable_offload+0xca7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11e0, 0xca7, x86_l_ca7);
x86_l_11e6:
	/* 0x11e6: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11eb:
	/* 0x11eb: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x11eb, 0x11e, x86_l_11e);
x86_l_11f0:
	/* 0x11f0: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11f3:
	/* 0x11f3: je     18b5 <generic_sleepable_offload+0x18b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f3, 0x18b5, x86_l_18b5);
x86_l_11f9:
	/* 0x11f9: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11fc:
	/* 0x11fc: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11fc, 0x120, x86_l_120);
x86_l_1202:
	/* 0x1202: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1206:
	/* 0x1206: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1209:
	/* 0x1209: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1209, 0x120, x86_l_120);
x86_l_120e:
	/* 0x120e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1211:
	/* 0x1211: je     18d4 <generic_sleepable_offload+0x18d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1211, 0x18d4, x86_l_18d4);
x86_l_1217:
	/* 0x1217: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_121a:
	/* 0x121a: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x121a, 0x120, x86_l_120);
x86_l_1220:
	/* 0x1220: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1225:
	/* 0x1225: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1228:
	/* 0x1228: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1228, 0x120, x86_l_120);
x86_l_122d:
	/* 0x122d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1230:
	/* 0x1230: je     1290 <generic_sleepable_offload+0x1290> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1230, 0x1290, x86_l_1290);
x86_l_1232:
	/* 0x1232: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1235:
	/* 0x1235: je     1283 <generic_sleepable_offload+0x1283> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1235, 0x1283, x86_l_1283);
x86_l_1237:
	/* 0x1237: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1237, 0x120, x86_l_120);
x86_l_123c:
	/* 0x123c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_123f:
	/* 0x123f: je     12b7 <generic_sleepable_offload+0x12b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x123f, 0x12b7, x86_l_12b7);
x86_l_1241:
	/* 0x1241: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1244:
	/* 0x1244: je     12aa <generic_sleepable_offload+0x12aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1244, 0x12aa, x86_l_12aa);
x86_l_1246:
	/* 0x1246: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1246, 0x120, x86_l_120);
x86_l_124b:
	/* 0x124b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_124e:
	/* 0x124e: je     1290 <generic_sleepable_offload+0x1290> */
	X86_SIM_X86_JCC(X86_CC_E, 0x124e, 0x1290, x86_l_1290);
x86_l_1250:
	/* 0x1250: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1253:
	/* 0x1253: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1253, 0x120, x86_l_120);
x86_l_1259:
	/* 0x1259: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_125e:
	/* 0x125e: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1261:
	/* 0x1261: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1261, 0x120, x86_l_120);
x86_l_1266:
	/* 0x1266: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1269:
	/* 0x1269: je     12b7 <generic_sleepable_offload+0x12b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1269, 0x12b7, x86_l_12b7);
x86_l_126b:
	/* 0x126b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_126e:
	/* 0x126e: je     12aa <generic_sleepable_offload+0x12aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x126e, 0x12aa, x86_l_12aa);
x86_l_1270:
	/* 0x1270: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1270, 0x120, x86_l_120);
x86_l_1275:
	/* 0x1275: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1278:
	/* 0x1278: je     1290 <generic_sleepable_offload+0x1290> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1278, 0x1290, x86_l_1290);
x86_l_127a:
	/* 0x127a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_127d:
	/* 0x127d: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x127d, 0x120, x86_l_120);
x86_l_1283:
	/* 0x1283: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1288:
	/* 0x1288: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128b:
	/* 0x128b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x128b, 0x120, x86_l_120);
x86_l_1290:
	/* 0x1290: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1295:
	/* 0x1295: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1297:
	/* 0x1297: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1297, 0x120, x86_l_120);
x86_l_129c:
	/* 0x129c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_129f:
	/* 0x129f: je     12b7 <generic_sleepable_offload+0x12b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129f, 0x12b7, x86_l_12b7);
x86_l_12a1:
	/* 0x12a1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12a4:
	/* 0x12a4: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12a4, 0x120, x86_l_120);
x86_l_12aa:
	/* 0x12aa: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12af:
	/* 0x12af: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b2:
	/* 0x12b2: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x12b2, 0x120, x86_l_120);
x86_l_12b7:
	/* 0x12b7: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12bc:
	/* 0x12bc: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12be:
	/* 0x12be: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x12be, 0x120, x86_l_120);
x86_l_12c3:
	/* 0x12c3: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12c6:
	/* 0x12c6: je     1335 <generic_sleepable_offload+0x1335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c6, 0x1335, x86_l_1335);
x86_l_12c8:
	/* 0x12c8: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12cb:
	/* 0x12cb: je     1328 <generic_sleepable_offload+0x1328> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12cb, 0x1328, x86_l_1328);
x86_l_12cd:
	/* 0x12cd: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x12cd, 0x120, x86_l_120);
x86_l_12d2:
	/* 0x12d2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12d5:
	/* 0x12d5: je     135c <generic_sleepable_offload+0x135c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d5, 0x135c, x86_l_135c);
x86_l_12db:
	/* 0x12db: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12de:
	/* 0x12de: je     134f <generic_sleepable_offload+0x134f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12de, 0x134f, x86_l_134f);
x86_l_12e0:
	/* 0x12e0: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x12e0, 0x120, x86_l_120);
x86_l_12e5:
	/* 0x12e5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12e8:
	/* 0x12e8: je     1634 <generic_sleepable_offload+0x1634> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e8, 0x1634, x86_l_1634);
x86_l_12ee:
	/* 0x12ee: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12f1:
	/* 0x12f1: je     137a <generic_sleepable_offload+0x137a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f1, 0x137a, x86_l_137a);
x86_l_12f7:
	/* 0x12f7: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x12f7, 0x120, x86_l_120);
x86_l_12fc:
	/* 0x12fc: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12ff:
	/* 0x12ff: je     1335 <generic_sleepable_offload+0x1335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ff, 0x1335, x86_l_1335);
x86_l_1301:
	/* 0x1301: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1304:
	/* 0x1304: je     1328 <generic_sleepable_offload+0x1328> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1304, 0x1328, x86_l_1328);
x86_l_1306:
	/* 0x1306: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1306, 0x120, x86_l_120);
x86_l_130b:
	/* 0x130b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_130e:
	/* 0x130e: je     135c <generic_sleepable_offload+0x135c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130e, 0x135c, x86_l_135c);
x86_l_1310:
	/* 0x1310: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1313:
	/* 0x1313: je     134f <generic_sleepable_offload+0x134f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1313, 0x134f, x86_l_134f);
x86_l_1315:
	/* 0x1315: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1315, 0x120, x86_l_120);
x86_l_131a:
	/* 0x131a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_131d:
	/* 0x131d: je     1335 <generic_sleepable_offload+0x1335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131d, 0x1335, x86_l_1335);
x86_l_131f:
	/* 0x131f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1322:
	/* 0x1322: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1322, 0x120, x86_l_120);
x86_l_1328:
	/* 0x1328: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_132d:
	/* 0x132d: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1330:
	/* 0x1330: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1330, 0x120, x86_l_120);
x86_l_1335:
	/* 0x1335: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_133a:
	/* 0x133a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133c:
	/* 0x133c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x133c, 0x120, x86_l_120);
x86_l_1341:
	/* 0x1341: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1344:
	/* 0x1344: je     135c <generic_sleepable_offload+0x135c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1344, 0x135c, x86_l_135c);
x86_l_1346:
	/* 0x1346: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1349:
	/* 0x1349: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1349, 0x120, x86_l_120);
x86_l_134f:
	/* 0x134f: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1354:
	/* 0x1354: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1357:
	/* 0x1357: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1357, 0x120, x86_l_120);
x86_l_135c:
	/* 0x135c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1361:
	/* 0x1361: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1363:
	/* 0x1363: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1363, 0x120, x86_l_120);
x86_l_1368:
	/* 0x1368: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_136b:
	/* 0x136b: je     1634 <generic_sleepable_offload+0x1634> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136b, 0x1634, x86_l_1634);
x86_l_1371:
	/* 0x1371: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1374:
	/* 0x1374: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1374, 0x120, x86_l_120);
x86_l_137a:
	/* 0x137a: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_137f:
	/* 0x137f: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1382:
	/* 0x1382: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1382, 0x120, x86_l_120);
x86_l_1387:
	/* 0x1387: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_138a:
	/* 0x138a: je     166b <generic_sleepable_offload+0x166b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138a, 0x166b, x86_l_166b);
x86_l_1390:
	/* 0x1390: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1393:
	/* 0x1393: je     1417 <generic_sleepable_offload+0x1417> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1393, 0x1417, x86_l_1417);
x86_l_1399:
	/* 0x1399: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1399, 0x120, x86_l_120);
x86_l_139e:
	/* 0x139e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13a1:
	/* 0x13a1: je     1672 <generic_sleepable_offload+0x1672> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a1, 0x1672, x86_l_1672);
x86_l_13a7:
	/* 0x13a7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13aa:
	/* 0x13aa: je     1467 <generic_sleepable_offload+0x1467> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13aa, 0x1467, x86_l_1467);
x86_l_13b0:
	/* 0x13b0: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x13b0, 0x120, x86_l_120);
x86_l_13b5:
	/* 0x13b5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13b8:
	/* 0x13b8: je     1686 <generic_sleepable_offload+0x1686> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b8, 0x1686, x86_l_1686);
x86_l_13be:
	/* 0x13be: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13c1:
	/* 0x13c1: je     1486 <generic_sleepable_offload+0x1486> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c1, 0x1486, x86_l_1486);
x86_l_13c7:
	/* 0x13c7: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x13c7, 0x120, x86_l_120);
x86_l_13cc:
	/* 0x13cc: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13cf:
	/* 0x13cf: je     190b <generic_sleepable_offload+0x190b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13cf, 0x190b, x86_l_190b);
x86_l_13d5:
	/* 0x13d5: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13d8:
	/* 0x13d8: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13d8, 0x120, x86_l_120);
x86_l_13de:
	/* 0x13de: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e1:
	/* 0x13e1: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x13e1, 0x120, x86_l_120);
x86_l_13e6:
	/* 0x13e6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13e9:
	/* 0x13e9: je     1912 <generic_sleepable_offload+0x1912> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13e9, 0x1912, x86_l_1912);
x86_l_13ef:
	/* 0x13ef: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13f2:
	/* 0x13f2: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13f2, 0x120, x86_l_120);
x86_l_13f8:
	/* 0x13f8: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13fd:
	/* 0x13fd: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1400:
	/* 0x1400: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1400, 0x120, x86_l_120);
x86_l_1405:
	/* 0x1405: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1408:
	/* 0x1408: je     166b <generic_sleepable_offload+0x166b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1408, 0x166b, x86_l_166b);
x86_l_140e:
	/* 0x140e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1411:
	/* 0x1411: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1411, 0x120, x86_l_120);
x86_l_1417:
	/* 0x1417: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141a:
	/* 0x141a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x141a, 0x120, x86_l_120);
x86_l_141f:
	/* 0x141f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1422:
	/* 0x1422: je     1a2e <generic_sleepable_offload+0x1a2e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1422, 0x1a2e, x86_l_1a2e);
x86_l_1428:
	/* 0x1428: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_142b:
	/* 0x142b: je     1a21 <generic_sleepable_offload+0x1a21> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142b, 0x1a21, x86_l_1a21);
x86_l_1431:
	/* 0x1431: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1431, 0x120, x86_l_120);
x86_l_1436:
	/* 0x1436: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1439:
	/* 0x1439: je     191e <generic_sleepable_offload+0x191e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1439, 0x191e, x86_l_191e);
x86_l_143f:
	/* 0x143f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1442:
	/* 0x1442: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1442, 0x120, x86_l_120);
x86_l_1448:
	/* 0x1448: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_144d:
	/* 0x144d: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1450:
	/* 0x1450: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1450, 0x120, x86_l_120);
x86_l_1455:
	/* 0x1455: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1458:
	/* 0x1458: je     1672 <generic_sleepable_offload+0x1672> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1458, 0x1672, x86_l_1672);
x86_l_145e:
	/* 0x145e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1461:
	/* 0x1461: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1461, 0x120, x86_l_120);
x86_l_1467:
	/* 0x1467: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_146c:
	/* 0x146c: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146f:
	/* 0x146f: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x146f, 0x120, x86_l_120);
x86_l_1474:
	/* 0x1474: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1477:
	/* 0x1477: je     1686 <generic_sleepable_offload+0x1686> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1477, 0x1686, x86_l_1686);
x86_l_147d:
	/* 0x147d: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1480:
	/* 0x1480: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1480, 0x120, x86_l_120);
x86_l_1486:
	/* 0x1486: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_148a:
	/* 0x148a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x148a, 0x120, x86_l_120);
x86_l_148f:
	/* 0x148f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1492:
	/* 0x1492: je     1a8f <generic_sleepable_offload+0x1a8f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1492, 0x1a8f, x86_l_1a8f);
x86_l_1498:
	/* 0x1498: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_149b:
	/* 0x149b: je     1a86 <generic_sleepable_offload+0x1a86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x149b, 0x1a86, x86_l_1a86);
x86_l_14a1:
	/* 0x14a1: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x14a1, 0x120, x86_l_120);
x86_l_14a6:
	/* 0x14a6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14a9:
	/* 0x14a9: je     168e <generic_sleepable_offload+0x168e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a9, 0x168e, x86_l_168e);
x86_l_14af:
	/* 0x14af: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14b2:
	/* 0x14b2: je     14de <generic_sleepable_offload+0x14de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14b2, 0x14de, x86_l_14de);
x86_l_14b4:
	/* 0x14b4: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x14b4, 0x120, x86_l_120);
x86_l_14b9:
	/* 0x14b9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14bc:
	/* 0x14bc: je     168e <generic_sleepable_offload+0x168e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14bc, 0x168e, x86_l_168e);
x86_l_14c2:
	/* 0x14c2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14c5:
	/* 0x14c5: je     14de <generic_sleepable_offload+0x14de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c5, 0x14de, x86_l_14de);
x86_l_14c7:
	/* 0x14c7: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x14c7, 0x120, x86_l_120);
x86_l_14cc:
	/* 0x14cc: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14cf:
	/* 0x14cf: je     1ab2 <generic_sleepable_offload+0x1ab2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14cf, 0x1ab2, x86_l_1ab2);
x86_l_14d5:
	/* 0x14d5: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14d8:
	/* 0x14d8: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14d8, 0x120, x86_l_120);
x86_l_14de:
	/* 0x14de: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14e3:
	/* 0x14e3: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e6:
	/* 0x14e6: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x14e6, 0x120, x86_l_120);
x86_l_14eb:
	/* 0x14eb: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14ee:
	/* 0x14ee: je     169a <generic_sleepable_offload+0x169a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ee, 0x169a, x86_l_169a);
x86_l_14f4:
	/* 0x14f4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14f7:
	/* 0x14f7: je     1510 <generic_sleepable_offload+0x1510> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f7, 0x1510, x86_l_1510);
x86_l_14f9:
	/* 0x14f9: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x14f9, 0x120, x86_l_120);
x86_l_14fe:
	/* 0x14fe: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1501:
	/* 0x1501: je     169a <generic_sleepable_offload+0x169a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1501, 0x169a, x86_l_169a);
x86_l_1507:
	/* 0x1507: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_150a:
	/* 0x150a: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x150a, 0x120, x86_l_120);
x86_l_1510:
	/* 0x1510: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1514:
	/* 0x1514: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1517:
	/* 0x1517: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1517, 0x120, x86_l_120);
x86_l_151c:
	/* 0x151c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_151f:
	/* 0x151f: je     16e1 <generic_sleepable_offload+0x16e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x151f, 0x16e1, x86_l_16e1);
x86_l_1525:
	/* 0x1525: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1528:
	/* 0x1528: je     15b1 <generic_sleepable_offload+0x15b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1528, 0x15b1, x86_l_15b1);
x86_l_152e:
	/* 0x152e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x152e, 0x120, x86_l_120);
x86_l_1533:
	/* 0x1533: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1536:
	/* 0x1536: je     1959 <generic_sleepable_offload+0x1959> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1536, 0x1959, x86_l_1959);
x86_l_153c:
	/* 0x153c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_153f:
	/* 0x153f: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x153f, 0x120, x86_l_120);
x86_l_1545:
	/* 0x1545: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_154a:
	/* 0x154a: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154d:
	/* 0x154d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x154d, 0x120, x86_l_120);
x86_l_1552:
	/* 0x1552: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1555:
	/* 0x1555: je     1965 <generic_sleepable_offload+0x1965> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1555, 0x1965, x86_l_1965);
x86_l_155b:
	/* 0x155b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_155e:
	/* 0x155e: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x155e, 0x120, x86_l_120);
x86_l_1564:
	/* 0x1564: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1569:
	/* 0x1569: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156c:
	/* 0x156c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x156c, 0x120, x86_l_120);
x86_l_1571:
	/* 0x1571: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1574:
	/* 0x1574: je     1af8 <generic_sleepable_offload+0x1af8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1574, 0x1af8, x86_l_1af8);
x86_l_157a:
	/* 0x157a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_157d:
	/* 0x157d: je     1aeb <generic_sleepable_offload+0x1aeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x157d, 0x1aeb, x86_l_1aeb);
x86_l_1583:
	/* 0x1583: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1583, 0x120, x86_l_120);
x86_l_1588:
	/* 0x1588: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_158b:
	/* 0x158b: je     1b1f <generic_sleepable_offload+0x1b1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158b, 0x1b1f, x86_l_1b1f);
x86_l_1591:
	/* 0x1591: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1594:
	/* 0x1594: je     1b12 <generic_sleepable_offload+0x1b12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1594, 0x1b12, x86_l_1b12);
x86_l_159a:
	/* 0x159a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x159a, 0x120, x86_l_120);
x86_l_159f:
	/* 0x159f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15a2:
	/* 0x15a2: je     16e1 <generic_sleepable_offload+0x16e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15a2, 0x16e1, x86_l_16e1);
x86_l_15a8:
	/* 0x15a8: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15ab:
	/* 0x15ab: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15ab, 0x120, x86_l_120);
x86_l_15b1:
	/* 0x15b1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15b6:
	/* 0x15b6: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b9:
	/* 0x15b9: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x15b9, 0x120, x86_l_120);
x86_l_15be:
	/* 0x15be: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15c1:
	/* 0x15c1: je     16ed <generic_sleepable_offload+0x16ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c1, 0x16ed, x86_l_16ed);
x86_l_15c7:
	/* 0x15c7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15ca:
	/* 0x15ca: je     15e3 <generic_sleepable_offload+0x15e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ca, 0x15e3, x86_l_15e3);
x86_l_15cc:
	/* 0x15cc: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x15cc, 0x120, x86_l_120);
x86_l_15d1:
	/* 0x15d1: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15d4:
	/* 0x15d4: je     16ed <generic_sleepable_offload+0x16ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d4, 0x16ed, x86_l_16ed);
x86_l_15da:
	/* 0x15da: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15dd:
	/* 0x15dd: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15dd, 0x120, x86_l_120);
x86_l_15e3:
	/* 0x15e3: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15e8:
	/* 0x15e8: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15eb:
	/* 0x15eb: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x15eb, 0x120, x86_l_120);
x86_l_15f0:
	/* 0x15f0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f5:
	/* 0x15f5: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x15f5, 0x11e, x86_l_11e);
x86_l_15fa:
	/* 0x15fa: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ff:
	/* 0x15ff: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x15ff, 0x11e, x86_l_11e);
x86_l_1604:
	/* 0x1604: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1609:
	/* 0x1609: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_160b:
	/* 0x160b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x160b, 0x120, x86_l_120);
x86_l_1610:
	/* 0x1610: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1615:
	/* 0x1615: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1617:
	/* 0x1617: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1617, 0x120, x86_l_120);
x86_l_161c:
	/* 0x161c: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1621:
	/* 0x1621: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1623:
	/* 0x1623: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1623, 0x120, x86_l_120);
x86_l_1628:
	/* 0x1628: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_162d:
	/* 0x162d: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_162f:
	/* 0x162f: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x162f, 0x120, x86_l_120);
x86_l_1634:
	/* 0x1634: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1639:
	/* 0x1639: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163b:
	/* 0x163b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x163b, 0x120, x86_l_120);
x86_l_1640:
	/* 0x1640: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1645:
	/* 0x1645: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1647:
	/* 0x1647: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1647, 0x120, x86_l_120);
x86_l_164c:
	/* 0x164c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1651:
	/* 0x1651: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1653:
	/* 0x1653: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1653, 0x120, x86_l_120);
x86_l_1658:
	/* 0x1658: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165a:
	/* 0x165a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x165a, 0x120, x86_l_120);
x86_l_165f:
	/* 0x165f: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1664:
	/* 0x1664: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1666:
	/* 0x1666: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1666, 0x120, x86_l_120);
x86_l_166b:
	/* 0x166b: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166d:
	/* 0x166d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x166d, 0x120, x86_l_120);
x86_l_1672:
	/* 0x1672: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1677:
	/* 0x1677: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1679:
	/* 0x1679: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1679, 0x120, x86_l_120);
x86_l_167e:
	/* 0x167e: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1681:
	/* 0x1681: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1681, 0x120, x86_l_120);
x86_l_1686:
	/* 0x1686: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1689:
	/* 0x1689: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1689, 0x120, x86_l_120);
x86_l_168e:
	/* 0x168e: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1693:
	/* 0x1693: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1695:
	/* 0x1695: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1695, 0x120, x86_l_120);
x86_l_169a:
	/* 0x169a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_169e:
	/* 0x169e: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a0:
	/* 0x16a0: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16a0, 0x120, x86_l_120);
x86_l_16a5:
	/* 0x16a5: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16aa:
	/* 0x16aa: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ac:
	/* 0x16ac: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16ac, 0x120, x86_l_120);
x86_l_16b1:
	/* 0x16b1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16b6:
	/* 0x16b6: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b8:
	/* 0x16b8: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16b8, 0x120, x86_l_120);
x86_l_16bd:
	/* 0x16bd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16c2:
	/* 0x16c2: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16c4:
	/* 0x16c4: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16c4, 0x120, x86_l_120);
x86_l_16c9:
	/* 0x16c9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16ce:
	/* 0x16ce: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d0:
	/* 0x16d0: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16d0, 0x120, x86_l_120);
x86_l_16d5:
	/* 0x16d5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16da:
	/* 0x16da: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16dc:
	/* 0x16dc: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16dc, 0x120, x86_l_120);
x86_l_16e1:
	/* 0x16e1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e6:
	/* 0x16e6: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e8:
	/* 0x16e8: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16e8, 0x120, x86_l_120);
x86_l_16ed:
	/* 0x16ed: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16f2:
	/* 0x16f2: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f4:
	/* 0x16f4: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x16f4, 0x120, x86_l_120);
x86_l_16f9:
	/* 0x16f9: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_16fc:
	/* 0x16fc: jg     197d <generic_sleepable_offload+0x197d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16fc, 0x197d, x86_l_197d);
x86_l_1702:
	/* 0x1702: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1705:
	/* 0x1705: je     186f <generic_sleepable_offload+0x186f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1705, 0x186f, x86_l_186f);
x86_l_170b:
	/* 0x170b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_170e:
	/* 0x170e: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x170e, 0x120, x86_l_120);
x86_l_1714:
	/* 0x1714: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1719:
	/* 0x1719: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_171c:
	/* 0x171c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x171c, 0x120, x86_l_120);
x86_l_1721:
	/* 0x1721: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1724:
	/* 0x1724: jg     199c <generic_sleepable_offload+0x199c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1724, 0x199c, x86_l_199c);
x86_l_172a:
	/* 0x172a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_172d:
	/* 0x172d: je     1879 <generic_sleepable_offload+0x1879> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172d, 0x1879, x86_l_1879);
x86_l_1733:
	/* 0x1733: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1736:
	/* 0x1736: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1736, 0x120, x86_l_120);
x86_l_173c:
	/* 0x173c: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1741:
	/* 0x1741: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1744:
	/* 0x1744: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1744, 0x120, x86_l_120);
x86_l_1749:
	/* 0x1749: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_174c:
	/* 0x174c: jg     176d <generic_sleepable_offload+0x176d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x174c, 0x176d, x86_l_176d);
x86_l_174e:
	/* 0x174e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1751:
	/* 0x1751: je     119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1751, 0x119, x86_l_119);
x86_l_1757:
	/* 0x1757: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_175a:
	/* 0x175a: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x175a, 0x120, x86_l_120);
x86_l_1760:
	/* 0x1760: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1765:
	/* 0x1765: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1768:
	/* 0x1768: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1768, 0x120, x86_l_120);
x86_l_176d:
	/* 0x176d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1770:
	/* 0x1770: je     1897 <generic_sleepable_offload+0x1897> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1770, 0x1897, x86_l_1897);
x86_l_1776:
	/* 0x1776: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1779:
	/* 0x1779: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1779, 0x120, x86_l_120);
x86_l_177f:
	/* 0x177f: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1784:
	/* 0x1784: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1787:
	/* 0x1787: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1787, 0x120, x86_l_120);
x86_l_178c:
	/* 0x178c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_178f:
	/* 0x178f: jg     19f9 <generic_sleepable_offload+0x19f9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x178f, 0x19f9, x86_l_19f9);
x86_l_1795:
	/* 0x1795: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1798:
	/* 0x1798: je     1b76 <generic_sleepable_offload+0x1b76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1798, 0x1b76, x86_l_1b76);
x86_l_179e:
	/* 0x179e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17a1:
	/* 0x17a1: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17a1, 0x120, x86_l_120);
x86_l_17a7:
	/* 0x17a7: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17aa:
	/* 0x17aa: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x17aa, 0x120, x86_l_120);
x86_l_17af:
	/* 0x17af: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17b2:
	/* 0x17b2: jg     1a13 <generic_sleepable_offload+0x1a13> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17b2, 0x1a13, x86_l_1a13);
x86_l_17b8:
	/* 0x17b8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17bb:
	/* 0x17bb: je     17d3 <generic_sleepable_offload+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17bb, 0x17d3, x86_l_17d3);
x86_l_17bd:
	/* 0x17bd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17c0:
	/* 0x17c0: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17c0, 0x120, x86_l_120);
x86_l_17c6:
	/* 0x17c6: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17cb:
	/* 0x17cb: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17ce:
	/* 0x17ce: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x17ce, 0x120, x86_l_120);
x86_l_17d3:
	/* 0x17d3: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17d8:
	/* 0x17d8: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x17d8, 0x11e, x86_l_11e);
x86_l_17dd:
	/* 0x17dd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17e0:
	/* 0x17e0: jg     1a3a <generic_sleepable_offload+0x1a3a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17e0, 0x1a3a, x86_l_1a3a);
x86_l_17e6:
	/* 0x17e6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17e9:
	/* 0x17e9: je     1801 <generic_sleepable_offload+0x1801> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17e9, 0x1801, x86_l_1801);
x86_l_17eb:
	/* 0x17eb: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17ee:
	/* 0x17ee: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17ee, 0x120, x86_l_120);
x86_l_17f4:
	/* 0x17f4: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17f9:
	/* 0x17f9: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17fc:
	/* 0x17fc: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x17fc, 0x120, x86_l_120);
x86_l_1801:
	/* 0x1801: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1806:
	/* 0x1806: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x1806, 0x11e, x86_l_11e);
x86_l_180b:
	/* 0x180b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_180e:
	/* 0x180e: jg     1a59 <generic_sleepable_offload+0x1a59> */
	X86_SIM_X86_JCC(X86_CC_G, 0x180e, 0x1a59, x86_l_1a59);
x86_l_1814:
	/* 0x1814: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1817:
	/* 0x1817: je     18a3 <generic_sleepable_offload+0x18a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1817, 0x18a3, x86_l_18a3);
x86_l_181d:
	/* 0x181d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1820:
	/* 0x1820: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1820, 0x120, x86_l_120);
x86_l_1826:
	/* 0x1826: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_182b:
	/* 0x182b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_182e:
	/* 0x182e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x182e, 0x120, x86_l_120);
x86_l_1833:
	/* 0x1833: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1836:
	/* 0x1836: jg     1a78 <generic_sleepable_offload+0x1a78> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1836, 0x1a78, x86_l_1a78);
x86_l_183c:
	/* 0x183c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_183f:
	/* 0x183f: je     18ad <generic_sleepable_offload+0x18ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183f, 0x18ad, x86_l_18ad);
x86_l_1841:
	/* 0x1841: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1844:
	/* 0x1844: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1844, 0x120, x86_l_120);
x86_l_184a:
	/* 0x184a: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_184e:
	/* 0x184e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x184e, 0x120, x86_l_120);
x86_l_1853:
	/* 0x1853: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1856:
	/* 0x1856: jg     1a97 <generic_sleepable_offload+0x1a97> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1856, 0x1a97, x86_l_1a97);
x86_l_185c:
	/* 0x185c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_185f:
	/* 0x185f: jne    10a5 <generic_sleepable_offload+0x10a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x185f, 0x10a5, x86_l_10a5);
x86_l_1865:
	/* 0x1865: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_186a:
	/* 0x186a: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x186a, 0x11e, x86_l_11e);
x86_l_186f:
	/* 0x186f: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1874:
	/* 0x1874: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x1874, 0x11e, x86_l_11e);
x86_l_1879:
	/* 0x1879: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_187e:
	/* 0x187e: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x187e, 0x11e, x86_l_11e);
x86_l_1883:
	/* 0x1883: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1888:
	/* 0x1888: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x1888, 0x11e, x86_l_11e);
x86_l_188d:
	/* 0x188d: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1892:
	/* 0x1892: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x1892, 0x11e, x86_l_11e);
x86_l_1897:
	/* 0x1897: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_189c:
	/* 0x189c: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189e:
	/* 0x189e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x189e, 0x120, x86_l_120);
x86_l_18a3:
	/* 0x18a3: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18a8:
	/* 0x18a8: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x18a8, 0x11e, x86_l_11e);
x86_l_18ad:
	/* 0x18ad: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b0:
	/* 0x18b0: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x18b0, 0x120, x86_l_120);
x86_l_18b5:
	/* 0x18b5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b9:
	/* 0x18b9: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18bb:
	/* 0x18bb: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x18bb, 0x120, x86_l_120);
x86_l_18c0:
	/* 0x18c0: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18c5:
	/* 0x18c5: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x18c5, 0x11e, x86_l_11e);
x86_l_18ca:
	/* 0x18ca: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18cf:
	/* 0x18cf: jmp    11e <generic_sleepable_offload+0x11e> */
	X86_SIM_X86_JMP(0x18cf, 0x11e, x86_l_11e);
x86_l_18d4:
	/* 0x18d4: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18d9:
	/* 0x18d9: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18db:
	/* 0x18db: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x18db, 0x120, x86_l_120);
x86_l_18e0:
	/* 0x18e0: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18e5:
	/* 0x18e5: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e7:
	/* 0x18e7: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x18e7, 0x120, x86_l_120);
x86_l_18ec:
	/* 0x18ec: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ee:
	/* 0x18ee: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x18ee, 0x120, x86_l_120);
x86_l_18f3:
	/* 0x18f3: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18f8:
	/* 0x18f8: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18fa:
	/* 0x18fa: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x18fa, 0x120, x86_l_120);
x86_l_18ff:
	/* 0x18ff: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1904:
	/* 0x1904: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1906:
	/* 0x1906: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1906, 0x120, x86_l_120);
x86_l_190b:
	/* 0x190b: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190d:
	/* 0x190d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x190d, 0x120, x86_l_120);
x86_l_1912:
	/* 0x1912: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1917:
	/* 0x1917: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1919:
	/* 0x1919: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1919, 0x120, x86_l_120);
x86_l_191e:
	/* 0x191e: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1923:
	/* 0x1923: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1925:
	/* 0x1925: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1925, 0x120, x86_l_120);
x86_l_192a:
	/* 0x192a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_192f:
	/* 0x192f: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1931:
	/* 0x1931: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1931, 0x120, x86_l_120);
x86_l_1936:
	/* 0x1936: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193a:
	/* 0x193a: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193c:
	/* 0x193c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x193c, 0x120, x86_l_120);
x86_l_1941:
	/* 0x1941: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1946:
	/* 0x1946: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1948:
	/* 0x1948: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1948, 0x120, x86_l_120);
x86_l_194d:
	/* 0x194d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1952:
	/* 0x1952: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1954:
	/* 0x1954: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1954, 0x120, x86_l_120);
x86_l_1959:
	/* 0x1959: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_195e:
	/* 0x195e: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1960:
	/* 0x1960: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1960, 0x120, x86_l_120);
x86_l_1965:
	/* 0x1965: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_196a:
	/* 0x196a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196c:
	/* 0x196c: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x196c, 0x120, x86_l_120);
x86_l_1971:
	/* 0x1971: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1976:
	/* 0x1976: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1978:
	/* 0x1978: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1978, 0x120, x86_l_120);
x86_l_197d:
	/* 0x197d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1980:
	/* 0x1980: je     1b46 <generic_sleepable_offload+0x1b46> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1980, 0x1b46, x86_l_1b46);
x86_l_1986:
	/* 0x1986: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1989:
	/* 0x1989: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1989, 0x120, x86_l_120);
x86_l_198f:
	/* 0x198f: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1994:
	/* 0x1994: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1997:
	/* 0x1997: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1997, 0x120, x86_l_120);
x86_l_199c:
	/* 0x199c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_199f:
	/* 0x199f: je     1b52 <generic_sleepable_offload+0x1b52> */
	X86_SIM_X86_JCC(X86_CC_E, 0x199f, 0x1b52, x86_l_1b52);
x86_l_19a5:
	/* 0x19a5: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19a8:
	/* 0x19a8: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19a8, 0x120, x86_l_120);
x86_l_19ae:
	/* 0x19ae: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19b3:
	/* 0x19b3: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b6:
	/* 0x19b6: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x19b6, 0x120, x86_l_120);
x86_l_19bb:
	/* 0x19bb: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19be:
	/* 0x19be: je     1b5e <generic_sleepable_offload+0x1b5e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19be, 0x1b5e, x86_l_1b5e);
x86_l_19c4:
	/* 0x19c4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19c7:
	/* 0x19c7: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19c7, 0x120, x86_l_120);
x86_l_19cd:
	/* 0x19cd: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19d2:
	/* 0x19d2: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d5:
	/* 0x19d5: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x19d5, 0x120, x86_l_120);
x86_l_19da:
	/* 0x19da: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19dd:
	/* 0x19dd: je     1b6a <generic_sleepable_offload+0x1b6a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19dd, 0x1b6a, x86_l_1b6a);
x86_l_19e3:
	/* 0x19e3: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19e6:
	/* 0x19e6: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19e6, 0x120, x86_l_120);
x86_l_19ec:
	/* 0x19ec: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19f1:
	/* 0x19f1: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f4:
	/* 0x19f4: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x19f4, 0x120, x86_l_120);
x86_l_19f9:
	/* 0x19f9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19fc:
	/* 0x19fc: je     1b7d <generic_sleepable_offload+0x1b7d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19fc, 0x1b7d, x86_l_1b7d);
x86_l_1a02:
	/* 0x1a02: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a05:
	/* 0x1a05: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a05, 0x120, x86_l_120);
x86_l_1a0b:
	/* 0x1a0b: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0e:
	/* 0x1a0e: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a0e, 0x120, x86_l_120);
x86_l_1a13:
	/* 0x1a13: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a16:
	/* 0x1a16: je     1a2e <generic_sleepable_offload+0x1a2e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a16, 0x1a2e, x86_l_1a2e);
x86_l_1a18:
	/* 0x1a18: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a1b:
	/* 0x1a1b: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a1b, 0x120, x86_l_120);
x86_l_1a21:
	/* 0x1a21: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a26:
	/* 0x1a26: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a29:
	/* 0x1a29: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a29, 0x120, x86_l_120);
x86_l_1a2e:
	/* 0x1a2e: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a33:
	/* 0x1a33: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a35:
	/* 0x1a35: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a35, 0x120, x86_l_120);
x86_l_1a3a:
	/* 0x1a3a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a3d:
	/* 0x1a3d: je     1b84 <generic_sleepable_offload+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3d, 0x1b84, x86_l_1b84);
x86_l_1a43:
	/* 0x1a43: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a46:
	/* 0x1a46: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a46, 0x120, x86_l_120);
x86_l_1a4c:
	/* 0x1a4c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a51:
	/* 0x1a51: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a54:
	/* 0x1a54: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a54, 0x120, x86_l_120);
x86_l_1a59:
	/* 0x1a59: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a5c:
	/* 0x1a5c: je     1b90 <generic_sleepable_offload+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a5c, 0x1b90, x86_l_1b90);
x86_l_1a62:
	/* 0x1a62: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a65:
	/* 0x1a65: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a65, 0x120, x86_l_120);
x86_l_1a6b:
	/* 0x1a6b: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a70:
	/* 0x1a70: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a73:
	/* 0x1a73: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a73, 0x120, x86_l_120);
x86_l_1a78:
	/* 0x1a78: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a7b:
	/* 0x1a7b: je     1a8f <generic_sleepable_offload+0x1a8f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a7b, 0x1a8f, x86_l_1a8f);
x86_l_1a7d:
	/* 0x1a7d: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a80:
	/* 0x1a80: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a80, 0x120, x86_l_120);
x86_l_1a86:
	/* 0x1a86: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8a:
	/* 0x1a8a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a8a, 0x120, x86_l_120);
x86_l_1a8f:
	/* 0x1a8f: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a92:
	/* 0x1a92: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1a92, 0x120, x86_l_120);
x86_l_1a97:
	/* 0x1a97: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a9a:
	/* 0x1a9a: je     1ab2 <generic_sleepable_offload+0x1ab2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9a, 0x1ab2, x86_l_1ab2);
x86_l_1a9c:
	/* 0x1a9c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a9f:
	/* 0x1a9f: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a9f, 0x120, x86_l_120);
x86_l_1aa5:
	/* 0x1aa5: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aad:
	/* 0x1aad: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1aad, 0x120, x86_l_120);
x86_l_1ab2:
	/* 0x1ab2: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab9:
	/* 0x1ab9: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1ab9, 0x120, x86_l_120);
x86_l_1abe:
	/* 0x1abe: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ac1:
	/* 0x1ac1: je     1b9c <generic_sleepable_offload+0x1b9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ac1, 0x1b9c, x86_l_1b9c);
x86_l_1ac7:
	/* 0x1ac7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aca:
	/* 0x1aca: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1aca, 0x120, x86_l_120);
x86_l_1ad0:
	/* 0x1ad0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad8:
	/* 0x1ad8: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1ad8, 0x120, x86_l_120);
x86_l_1add:
	/* 0x1add: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ae0:
	/* 0x1ae0: je     1af8 <generic_sleepable_offload+0x1af8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ae0, 0x1af8, x86_l_1af8);
x86_l_1ae2:
	/* 0x1ae2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ae5:
	/* 0x1ae5: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ae5, 0x120, x86_l_120);
x86_l_1aeb:
	/* 0x1aeb: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af0:
	/* 0x1af0: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af3:
	/* 0x1af3: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1af3, 0x120, x86_l_120);
x86_l_1af8:
	/* 0x1af8: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1afd:
	/* 0x1afd: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aff:
	/* 0x1aff: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1aff, 0x120, x86_l_120);
x86_l_1b04:
	/* 0x1b04: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b07:
	/* 0x1b07: je     1b1f <generic_sleepable_offload+0x1b1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b07, 0x1b1f, x86_l_1b1f);
x86_l_1b09:
	/* 0x1b09: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b0c:
	/* 0x1b0c: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b0c, 0x120, x86_l_120);
x86_l_1b12:
	/* 0x1b12: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b17:
	/* 0x1b17: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1a:
	/* 0x1b1a: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b1a, 0x120, x86_l_120);
x86_l_1b1f:
	/* 0x1b1f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b24:
	/* 0x1b24: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b26:
	/* 0x1b26: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b26, 0x120, x86_l_120);
x86_l_1b2b:
	/* 0x1b2b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b2e:
	/* 0x1b2e: je     1ba8 <generic_sleepable_offload+0x1ba8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b2e, 0x1ba8, x86_l_1ba8);
x86_l_1b30:
	/* 0x1b30: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b33:
	/* 0x1b33: jne    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b33, 0x120, x86_l_120);
x86_l_1b39:
	/* 0x1b39: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b41:
	/* 0x1b41: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b41, 0x120, x86_l_120);
x86_l_1b46:
	/* 0x1b46: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4d:
	/* 0x1b4d: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b4d, 0x120, x86_l_120);
x86_l_1b52:
	/* 0x1b52: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b57:
	/* 0x1b57: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b59:
	/* 0x1b59: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b59, 0x120, x86_l_120);
x86_l_1b5e:
	/* 0x1b5e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b63:
	/* 0x1b63: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b65:
	/* 0x1b65: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b65, 0x120, x86_l_120);
x86_l_1b6a:
	/* 0x1b6a: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b6f:
	/* 0x1b6f: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b71:
	/* 0x1b71: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b71, 0x120, x86_l_120);
x86_l_1b76:
	/* 0x1b76: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b78:
	/* 0x1b78: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b78, 0x120, x86_l_120);
x86_l_1b7d:
	/* 0x1b7d: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7f:
	/* 0x1b7f: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b7f, 0x120, x86_l_120);
x86_l_1b84:
	/* 0x1b84: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b89:
	/* 0x1b89: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b8b:
	/* 0x1b8b: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b8b, 0x120, x86_l_120);
x86_l_1b90:
	/* 0x1b90: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b95:
	/* 0x1b95: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b97:
	/* 0x1b97: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1b97, 0x120, x86_l_120);
x86_l_1b9c:
	/* 0x1b9c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba3:
	/* 0x1ba3: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1ba3, 0x120, x86_l_120);
x86_l_1ba8:
	/* 0x1ba8: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bad:
	/* 0x1bad: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1baf:
	/* 0x1baf: jmp    120 <generic_sleepable_offload+0x120> */
	X86_SIM_X86_JMP(0x1baf, 0x120, x86_l_120);
x86_l_1bb4:
	/* 0x1bb4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bb6:
	/* 0x1bb6: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1bbd:
	/* 0x1bbd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1bbe:
	/* 0x1bbe: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1bc0:
	/* 0x1bc0: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1bc2:
	/* 0x1bc2: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1bc4:
	/* 0x1bc4: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1bc6:
	/* 0x1bc6: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1bc7:
	/* 0x1bc7: jmp    1bcc <generic_sleepable_offload+0x1bcc> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1bcc:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
