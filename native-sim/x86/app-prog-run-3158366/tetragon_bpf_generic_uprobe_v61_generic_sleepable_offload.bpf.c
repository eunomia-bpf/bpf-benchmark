extern char regs_map;
extern char sleepable_offload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_v61_generic_sleepable_offload_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13:
	/* 0x13: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_18:
	/* 0x18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a:
	/* 0x1a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0xf7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b:
	/* 0x2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30:
	/* 0x30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32:
	/* 0x32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35:
	/* 0x35: je     19f <generic_sleepable_offload+0x19f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35, 0x19f, x86_l_19f);
x86_l_3b:
	/* 0x3b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: mov    rdi,QWORD PTR [rip+0xe3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_45:
	/* 0x45: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a:
	/* 0x4a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4f:
	/* 0x4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51:
	/* 0x51: mov    rdi,QWORD PTR [rip+0xe3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&regs_map)));
x86_l_58:
	/* 0x58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d:
	/* 0x5d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_60:
	/* 0x60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62:
	/* 0x62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65:
	/* 0x65: je     19f <generic_sleepable_offload+0x19f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x65, 0x19f, x86_l_19f);
x86_l_6b:
	/* 0x6b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_71:
	/* 0x71: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_75:
	/* 0x75: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_78:
	/* 0x78: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d:
	/* 0x7d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_82:
	/* 0x82: jmp    d3 <generic_sleepable_offload+0xd3> */
	X86_SIM_X86_JMP(0x82, 0xd3, x86_l_d3);
x86_l_84:
	/* 0x84: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_8a:
	/* 0x8a: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_90:
	/* 0x90: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_93:
	/* 0x93: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_95:
	/* 0x95: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_97:
	/* 0x97: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_9a:
	/* 0x9a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_1ad, 0xa2ULL);
x86_l_a2:
	/* 0xa2: add    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab:
	/* 0xab: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_b1:
	/* 0xb1: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_b7:
	/* 0xb7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ba:
	/* 0xba: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_2c3, 0xc2ULL);
x86_l_c2:
	/* 0xc2: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_c5:
	/* 0xc5: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c9:
	/* 0xc9: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_cd:
	/* 0xcd: je     19f <generic_sleepable_offload+0x19f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcd, 0x19f, x86_l_19f);
x86_l_d3:
	/* 0xd3: mov    eax,DWORD PTR [r14+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_da:
	/* 0xda: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_dd:
	/* 0xdd: jae    19f <generic_sleepable_offload+0x19f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xdd, 0x19f, x86_l_19f);
x86_l_e3:
	/* 0xe3: movzx  eax,BYTE PTR [r12-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_e9:
	/* 0xe9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ec:
	/* 0xec: jg     11c <generic_sleepable_offload+0x11c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xec, 0x11c, x86_l_11c);
x86_l_ee:
	/* 0xee: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1:
	/* 0xf1: je     187 <generic_sleepable_offload+0x187> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf1, 0x187, x86_l_187);
x86_l_f7:
	/* 0xf7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fa:
	/* 0xfa: jne    c2 <generic_sleepable_offload+0xc2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfa, 0xc2, x86_l_c2);
x86_l_fc:
	/* 0xfc: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_102:
	/* 0x102: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_108:
	/* 0x108: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_10b:
	/* 0x10b: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_10d:
	/* 0x10d: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_10f:
	/* 0x10f: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_112:
	/* 0x112: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_115:
	/* 0x115: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_1ad, 0x11aULL);
x86_l_11a:
	/* 0x11a: jmp    a6 <generic_sleepable_offload+0xa6> */
	X86_SIM_X86_JMP(0x11a, 0xa6, x86_l_a6);
x86_l_11c:
	/* 0x11c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_11f:
	/* 0x11f: je     84 <generic_sleepable_offload+0x84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f, 0x84, x86_l_84);
x86_l_125:
	/* 0x125: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_128:
	/* 0x128: jne    c2 <generic_sleepable_offload+0xc2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x128, 0xc2, x86_l_c2);
x86_l_12a:
	/* 0x12a: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_130:
	/* 0x130: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_136:
	/* 0x136: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_139:
	/* 0x139: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_13b:
	/* 0x13b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_13d:
	/* 0x13d: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_140:
	/* 0x140: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_143:
	/* 0x143: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_1ad, 0x148ULL);
x86_l_148:
	/* 0x148: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14b:
	/* 0x14b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150:
	/* 0x150: add    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_154:
	/* 0x154: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_159:
	/* 0x159: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e:
	/* 0x15e: add    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_162:
	/* 0x162: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_165:
	/* 0x165: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a:
	/* 0x16a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c:
	/* 0x16c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16e:
	/* 0x16e: jne    c2 <generic_sleepable_offload+0xc2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16e, 0xc2, x86_l_c2);
x86_l_174:
	/* 0x174: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_17a:
	/* 0x17a: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_180:
	/* 0x180: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_185:
	/* 0x185: jmp    197 <generic_sleepable_offload+0x197> */
	X86_SIM_X86_JMP(0x185, 0x197, x86_l_197);
x86_l_187:
	/* 0x187: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_18d:
	/* 0x18d: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_193:
	/* 0x193: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197:
	/* 0x197: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19a:
	/* 0x19a: jmp    bd <generic_sleepable_offload+0xbd> */
	X86_SIM_X86_JMP(0x19a, 0xbd, x86_l_bd);
x86_l_19f:
	/* 0x19f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a1:
	/* 0x1a1: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1a5:
	/* 0x1a5: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1a7:
	/* 0x1a7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1a8:
	/* 0x1a8: jmp    802 <write_reg+0x53f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_802:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_1ad */
x86_l_1ad:
	/* 0x1ad: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_1b3:
	/* 0x1b3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5:
	/* 0x1b5: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1b8:
	/* 0x1b8: jle    1ef <read_reg+0x42> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1b8, 0x1ef, x86_l_1ef);
x86_l_1ba:
	/* 0x1ba: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1bd:
	/* 0x1bd: jle    213 <read_reg+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1bd, 0x213, x86_l_213);
x86_l_1bf:
	/* 0x1bf: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1c2:
	/* 0x1c2: jle    278 <read_reg+0xcb> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1c2, 0x278, x86_l_278);
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1cb:
	/* 0x1cb: je     2ac <read_reg+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cb, 0x2ac, x86_l_2ac);
x86_l_1d1:
	/* 0x1d1: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d4:
	/* 0x1d4: je     294 <read_reg+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d4, 0x294, x86_l_294);
x86_l_1da:
	/* 0x1da: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1dd:
	/* 0x1dd: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1dd, 0x2c2, x86_l_2c2);
x86_l_1e3:
	/* 0x1e3: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1ea:
	/* 0x1ea: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x1ea, 0x2b6, x86_l_2b6);
x86_l_1ef:
	/* 0x1ef: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1f2:
	/* 0x1f2: jg     22f <read_reg+0x82> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f2, 0x22f, x86_l_22f);
x86_l_1f4:
	/* 0x1f4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f7:
	/* 0x1f7: jg     258 <read_reg+0xab> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f7, 0x258, x86_l_258);
x86_l_1f9:
	/* 0x1f9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1fb:
	/* 0x1fb: je     2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1fb, 0x2b6, x86_l_2b6);
x86_l_201:
	/* 0x201: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_204:
	/* 0x204: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x204, 0x2c2, x86_l_2c2);
x86_l_20a:
	/* 0x20a: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_20e:
	/* 0x20e: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x20e, 0x2b6, x86_l_2b6);
x86_l_213:
	/* 0x213: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_216:
	/* 0x216: jg     248 <read_reg+0x9b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x216, 0x248, x86_l_248);
x86_l_218:
	/* 0x218: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21b:
	/* 0x21b: je     288 <read_reg+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x21b, 0x288, x86_l_288);
x86_l_21d:
	/* 0x21d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_220:
	/* 0x220: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x220, 0x2c2, x86_l_2c2);
x86_l_226:
	/* 0x226: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_22a:
	/* 0x22a: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x22a, 0x2b6, x86_l_2b6);
x86_l_22f:
	/* 0x22f: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_232:
	/* 0x232: jg     268 <read_reg+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x232, 0x268, x86_l_268);
x86_l_234:
	/* 0x234: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_237:
	/* 0x237: je     29a <read_reg+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x237, 0x29a, x86_l_29a);
x86_l_239:
	/* 0x239: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_23c:
	/* 0x23c: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x23c, 0x2c2, x86_l_2c2);
x86_l_242:
	/* 0x242: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_246:
	/* 0x246: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x246, 0x2b6, x86_l_2b6);
x86_l_248:
	/* 0x248: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_24b:
	/* 0x24b: je     28e <read_reg+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x24b, 0x28e, x86_l_28e);
x86_l_24d:
	/* 0x24d: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_250:
	/* 0x250: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x250, 0x2c2, x86_l_2c2);
x86_l_252:
	/* 0x252: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_256:
	/* 0x256: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x256, 0x2b6, x86_l_2b6);
x86_l_258:
	/* 0x258: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_25b:
	/* 0x25b: je     2a0 <read_reg+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x25b, 0x2a0, x86_l_2a0);
x86_l_25d:
	/* 0x25d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_260:
	/* 0x260: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x260, 0x2c2, x86_l_2c2);
x86_l_262:
	/* 0x262: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_266:
	/* 0x266: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x266, 0x2b6, x86_l_2b6);
x86_l_268:
	/* 0x268: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_26b:
	/* 0x26b: je     2a6 <read_reg+0xf9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x26b, 0x2a6, x86_l_2a6);
x86_l_26d:
	/* 0x26d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_270:
	/* 0x270: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x270, 0x2c2, x86_l_2c2);
x86_l_272:
	/* 0x272: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_276:
	/* 0x276: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x276, 0x2b6, x86_l_2b6);
x86_l_278:
	/* 0x278: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_27b:
	/* 0x27b: je     2b2 <read_reg+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x27b, 0x2b2, x86_l_2b2);
x86_l_27d:
	/* 0x27d: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_280:
	/* 0x280: jne    2c2 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x280, 0x2c2, x86_l_2c2);
x86_l_282:
	/* 0x282: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_286:
	/* 0x286: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x286, 0x2b6, x86_l_2b6);
x86_l_288:
	/* 0x288: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_28c:
	/* 0x28c: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x28c, 0x2b6, x86_l_2b6);
x86_l_28e:
	/* 0x28e: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_292:
	/* 0x292: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x292, 0x2b6, x86_l_2b6);
x86_l_294:
	/* 0x294: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_298:
	/* 0x298: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x298, 0x2b6, x86_l_2b6);
x86_l_29a:
	/* 0x29a: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_29e:
	/* 0x29e: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x29e, 0x2b6, x86_l_2b6);
x86_l_2a0:
	/* 0x2a0: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a4:
	/* 0x2a4: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2a4, 0x2b6, x86_l_2b6);
x86_l_2a6:
	/* 0x2a6: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_2aa:
	/* 0x2aa: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2aa, 0x2b6, x86_l_2b6);
x86_l_2ac:
	/* 0x2ac: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_2b0:
	/* 0x2b0: jmp    2b6 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2b0, 0x2b6, x86_l_2b6);
x86_l_2b2:
	/* 0x2b2: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2b6:
	/* 0x2b6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2bb:
	/* 0x2bb: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bd:
	/* 0x2bd: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2c2:
	/* 0x2c2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_2c3 */
x86_l_2c3:
	/* 0x2c3: rorx   eax,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_2c9:
	/* 0x2c9: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2cc:
	/* 0x2cc: jle    321 <write_reg+0x5e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2cc, 0x321, x86_l_321);
x86_l_2ce:
	/* 0x2ce: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2d1:
	/* 0x2d1: jle    363 <write_reg+0xa0> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2d1, 0x363, x86_l_363);
x86_l_2d7:
	/* 0x2d7: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_2da:
	/* 0x2da: jle    47a <write_reg+0x1b7> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2da, 0x47a, x86_l_47a);
x86_l_2e0:
	/* 0x2e0: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2e3:
	/* 0x2e3: je     5a6 <write_reg+0x2e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2e3, 0x5a6, x86_l_5a6);
x86_l_2e9:
	/* 0x2e9: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2ec:
	/* 0x2ec: je     4f5 <write_reg+0x232> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2ec, 0x4f5, x86_l_4f5);
x86_l_2f2:
	/* 0x2f2: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_2f5:
	/* 0x2f5: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2f5, 0x7d2, x86_l_7d2);
x86_l_2fb:
	/* 0x2fb: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2fe:
	/* 0x2fe: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_301:
	/* 0x301: jg     6eb <write_reg+0x428> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x301, 0x6eb, x86_l_6eb);
x86_l_307:
	/* 0x307: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a:
	/* 0x30a: je     7cc <write_reg+0x509> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x30a, 0x7cc, x86_l_7cc);
x86_l_310:
	/* 0x310: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_313:
	/* 0x313: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x313, 0x7d2, x86_l_7d2);
x86_l_319:
	/* 0x319: mov    WORD PTR [rdi+0x98],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_320:
	/* 0x320: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_321:
	/* 0x321: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_324:
	/* 0x324: jg     39d <write_reg+0xda> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x324, 0x39d, x86_l_39d);
x86_l_326:
	/* 0x326: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_329:
	/* 0x329: jg     410 <write_reg+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x329, 0x410, x86_l_410);
x86_l_32f:
	/* 0x32f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_331:
	/* 0x331: je     51b <write_reg+0x258> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x331, 0x51b, x86_l_51b);
x86_l_337:
	/* 0x337: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33a:
	/* 0x33a: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x33a, 0x7d2, x86_l_7d2);
x86_l_340:
	/* 0x340: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_343:
	/* 0x343: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_346:
	/* 0x346: jg     705 <write_reg+0x442> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x346, 0x705, x86_l_705);
x86_l_34c:
	/* 0x34c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34f:
	/* 0x34f: je     7da <write_reg+0x517> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x34f, 0x7da, x86_l_7da);
x86_l_355:
	/* 0x355: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_358:
	/* 0x358: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x358, 0x7d2, x86_l_7d2);
x86_l_35e:
	/* 0x35e: mov    WORD PTR [rdi+0x8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_362:
	/* 0x362: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_363:
	/* 0x363: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_366:
	/* 0x366: jg     3db <write_reg+0x118> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x366, 0x3db, x86_l_3db);
x86_l_368:
	/* 0x368: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_36b:
	/* 0x36b: je     4af <write_reg+0x1ec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x36b, 0x4af, x86_l_4af);
x86_l_371:
	/* 0x371: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_374:
	/* 0x374: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x374, 0x7d2, x86_l_7d2);
x86_l_37a:
	/* 0x37a: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_37d:
	/* 0x37d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_380:
	/* 0x380: jg     61a <write_reg+0x357> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x380, 0x61a, x86_l_61a);
x86_l_386:
	/* 0x386: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_389:
	/* 0x389: je     780 <write_reg+0x4bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x389, 0x780, x86_l_780);
x86_l_38f:
	/* 0x38f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_392:
	/* 0x392: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x392, 0x7d2, x86_l_7d2);
x86_l_398:
	/* 0x398: mov    WORD PTR [rdi+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_39c:
	/* 0x39c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_39d:
	/* 0x39d: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3a0:
	/* 0x3a0: jg     445 <write_reg+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3a0, 0x445, x86_l_445);
x86_l_3a6:
	/* 0x3a6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a9:
	/* 0x3a9: je     53d <write_reg+0x27a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3a9, 0x53d, x86_l_53d);
x86_l_3af:
	/* 0x3af: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3b2:
	/* 0x3b2: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3b2, 0x7d2, x86_l_7d2);
x86_l_3b8:
	/* 0x3b8: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3bb:
	/* 0x3bb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3be:
	/* 0x3be: jg     71c <write_reg+0x459> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3be, 0x71c, x86_l_71c);
x86_l_3c4:
	/* 0x3c4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c7:
	/* 0x3c7: je     7de <write_reg+0x51b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3c7, 0x7de, x86_l_7de);
x86_l_3cd:
	/* 0x3cd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d0:
	/* 0x3d0: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3d0, 0x7d2, x86_l_7d2);
x86_l_3d6:
	/* 0x3d6: mov    WORD PTR [rdi+0x28],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3da:
	/* 0x3da: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3db:
	/* 0x3db: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_3de:
	/* 0x3de: je     4d2 <write_reg+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3de, 0x4d2, x86_l_4d2);
x86_l_3e4:
	/* 0x3e4: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3e7:
	/* 0x3e7: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3e7, 0x7d2, x86_l_7d2);
x86_l_3ed:
	/* 0x3ed: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3f0:
	/* 0x3f0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3f3:
	/* 0x3f3: jg     631 <write_reg+0x36e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3f3, 0x631, x86_l_631);
x86_l_3f9:
	/* 0x3f9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fc:
	/* 0x3fc: je     784 <write_reg+0x4c1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3fc, 0x784, x86_l_784);
x86_l_402:
	/* 0x402: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_405:
	/* 0x405: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x405, 0x7d2, x86_l_7d2);
x86_l_40b:
	/* 0x40b: mov    WORD PTR [rdi+0x58],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40f:
	/* 0x40f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_410:
	/* 0x410: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_413:
	/* 0x413: je     560 <write_reg+0x29d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x413, 0x560, x86_l_560);
x86_l_419:
	/* 0x419: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_41c:
	/* 0x41c: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x41c, 0x7d2, x86_l_7d2);
x86_l_422:
	/* 0x422: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_425:
	/* 0x425: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_428:
	/* 0x428: jg     733 <write_reg+0x470> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x428, 0x733, x86_l_733);
x86_l_42e:
	/* 0x42e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_431:
	/* 0x431: je     7e2 <write_reg+0x51f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x431, 0x7e2, x86_l_7e2);
x86_l_437:
	/* 0x437: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43a:
	/* 0x43a: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x43a, 0x7d2, x86_l_7d2);
x86_l_440:
	/* 0x440: mov    WORD PTR [rdi+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_444:
	/* 0x444: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_445:
	/* 0x445: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_448:
	/* 0x448: je     583 <write_reg+0x2c0> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x448, 0x583, x86_l_583);
x86_l_44e:
	/* 0x44e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_451:
	/* 0x451: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x451, 0x7d2, x86_l_7d2);
x86_l_457:
	/* 0x457: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_45a:
	/* 0x45a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_45d:
	/* 0x45d: jg     74a <write_reg+0x487> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x45d, 0x74a, x86_l_74a);
x86_l_463:
	/* 0x463: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_466:
	/* 0x466: je     7e6 <write_reg+0x523> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x466, 0x7e6, x86_l_7e6);
x86_l_46c:
	/* 0x46c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_46f:
	/* 0x46f: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x46f, 0x7d2, x86_l_7d2);
x86_l_475:
	/* 0x475: mov    WORD PTR [rdi+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_479:
	/* 0x479: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_47a:
	/* 0x47a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_47d:
	/* 0x47d: je     5c9 <write_reg+0x306> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x47d, 0x5c9, x86_l_5c9);
x86_l_483:
	/* 0x483: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_486:
	/* 0x486: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x486, 0x7d2, x86_l_7d2);
x86_l_48c:
	/* 0x48c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_48f:
	/* 0x48f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_492:
	/* 0x492: jg     75d <write_reg+0x49a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x492, 0x75d, x86_l_75d);
x86_l_498:
	/* 0x498: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49b:
	/* 0x49b: je     7fa <write_reg+0x537> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x49b, 0x7fa, x86_l_7fa);
x86_l_4a1:
	/* 0x4a1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4a4:
	/* 0x4a4: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4a4, 0x7d2, x86_l_7d2);
x86_l_4aa:
	/* 0x4aa: mov    WORD PTR [rdi+0x68],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4ae:
	/* 0x4ae: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4af:
	/* 0x4af: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4b2:
	/* 0x4b2: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4b5:
	/* 0x4b5: jg     5ec <write_reg+0x329> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4b5, 0x5ec, x86_l_5ec);
x86_l_4bb:
	/* 0x4bb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4be:
	/* 0x4be: je     770 <write_reg+0x4ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4be, 0x770, x86_l_770);
x86_l_4c4:
	/* 0x4c4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c7:
	/* 0x4c7: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4c7, 0x7d2, x86_l_7d2);
x86_l_4cd:
	/* 0x4cd: mov    WORD PTR [rdi+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4d1:
	/* 0x4d1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4d2:
	/* 0x4d2: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4d5:
	/* 0x4d5: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4d8:
	/* 0x4d8: jg     603 <write_reg+0x340> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4d8, 0x603, x86_l_603);
x86_l_4de:
	/* 0x4de: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e1:
	/* 0x4e1: je     774 <write_reg+0x4b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4e1, 0x774, x86_l_774);
x86_l_4e7:
	/* 0x4e7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4ea:
	/* 0x4ea: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4ea, 0x7d2, x86_l_7d2);
x86_l_4f0:
	/* 0x4f0: mov    WORD PTR [rdi+0x50],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4f4:
	/* 0x4f4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4f5:
	/* 0x4f5: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4f8:
	/* 0x4f8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4fb:
	/* 0x4fb: jg     648 <write_reg+0x385> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4fb, 0x648, x86_l_648);
x86_l_501:
	/* 0x501: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_504:
	/* 0x504: je     790 <write_reg+0x4cd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x504, 0x790, x86_l_790);
x86_l_50a:
	/* 0x50a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_50d:
	/* 0x50d: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x50d, 0x7d2, x86_l_7d2);
x86_l_513:
	/* 0x513: mov    WORD PTR [rdi+0x80],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_51a:
	/* 0x51a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_51b:
	/* 0x51b: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_51e:
	/* 0x51e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_521:
	/* 0x521: jg     662 <write_reg+0x39f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x521, 0x662, x86_l_662);
x86_l_527:
	/* 0x527: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52a:
	/* 0x52a: je     79e <write_reg+0x4db> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x52a, 0x79e, x86_l_79e);
x86_l_530:
	/* 0x530: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_533:
	/* 0x533: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x533, 0x7d2, x86_l_7d2);
x86_l_539:
	/* 0x539: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53c:
	/* 0x53c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_53d:
	/* 0x53d: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_540:
	/* 0x540: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_543:
	/* 0x543: jg     678 <write_reg+0x3b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x543, 0x678, x86_l_678);
x86_l_549:
	/* 0x549: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54c:
	/* 0x54c: je     7a1 <write_reg+0x4de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x54c, 0x7a1, x86_l_7a1);
x86_l_552:
	/* 0x552: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_555:
	/* 0x555: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x555, 0x7d2, x86_l_7d2);
x86_l_55b:
	/* 0x55b: mov    WORD PTR [rdi+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55f:
	/* 0x55f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_560:
	/* 0x560: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_563:
	/* 0x563: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_566:
	/* 0x566: jg     68f <write_reg+0x3cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x566, 0x68f, x86_l_68f);
x86_l_56c:
	/* 0x56c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_56f:
	/* 0x56f: je     7a5 <write_reg+0x4e2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x56f, 0x7a5, x86_l_7a5);
x86_l_575:
	/* 0x575: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_578:
	/* 0x578: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x578, 0x7d2, x86_l_7d2);
x86_l_57e:
	/* 0x57e: mov    WORD PTR [rdi+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_582:
	/* 0x582: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_583:
	/* 0x583: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_586:
	/* 0x586: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_589:
	/* 0x589: jg     6a6 <write_reg+0x3e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x589, 0x6a6, x86_l_6a6);
x86_l_58f:
	/* 0x58f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_592:
	/* 0x592: je     7a9 <write_reg+0x4e6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x592, 0x7a9, x86_l_7a9);
x86_l_598:
	/* 0x598: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_59b:
	/* 0x59b: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x59b, 0x7d2, x86_l_7d2);
x86_l_5a1:
	/* 0x5a1: mov    WORD PTR [rdi+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a5:
	/* 0x5a5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5a6:
	/* 0x5a6: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5a9:
	/* 0x5a9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5ac:
	/* 0x5ac: jg     6bd <write_reg+0x3fa> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x5ac, 0x6bd, x86_l_6bd);
x86_l_5b2:
	/* 0x5b2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b5:
	/* 0x5b5: je     7bc <write_reg+0x4f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5b5, 0x7bc, x86_l_7bc);
x86_l_5bb:
	/* 0x5bb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5be:
	/* 0x5be: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5be, 0x7d2, x86_l_7d2);
x86_l_5c4:
	/* 0x5c4: mov    WORD PTR [rdi+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5c8:
	/* 0x5c8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5c9:
	/* 0x5c9: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5cc:
	/* 0x5cc: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5cf:
	/* 0x5cf: jg     6d4 <write_reg+0x411> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x5cf, 0x6d4, x86_l_6d4);
x86_l_5d5:
	/* 0x5d5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d8:
	/* 0x5d8: je     7c4 <write_reg+0x501> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5d8, 0x7c4, x86_l_7c4);
x86_l_5de:
	/* 0x5de: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e1:
	/* 0x5e1: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5e1, 0x7d2, x86_l_7d2);
x86_l_5e7:
	/* 0x5e7: mov    WORD PTR [rdi+0x60],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5eb:
	/* 0x5eb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5ec:
	/* 0x5ec: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5ef:
	/* 0x5ef: je     778 <write_reg+0x4b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5ef, 0x778, x86_l_778);
x86_l_5f5:
	/* 0x5f5: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5f8:
	/* 0x5f8: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5f8, 0x7d2, x86_l_7d2);
x86_l_5fe:
	/* 0x5fe: mov    QWORD PTR [rdi+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_602:
	/* 0x602: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_603:
	/* 0x603: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_606:
	/* 0x606: je     77c <write_reg+0x4b9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x606, 0x77c, x86_l_77c);
x86_l_60c:
	/* 0x60c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_60f:
	/* 0x60f: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x60f, 0x7d2, x86_l_7d2);
x86_l_615:
	/* 0x615: mov    QWORD PTR [rdi+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_619:
	/* 0x619: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_61a:
	/* 0x61a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_61d:
	/* 0x61d: je     788 <write_reg+0x4c5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x61d, 0x788, x86_l_788);
x86_l_623:
	/* 0x623: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_626:
	/* 0x626: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x626, 0x7d2, x86_l_7d2);
x86_l_62c:
	/* 0x62c: mov    QWORD PTR [rdi+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_630:
	/* 0x630: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_631:
	/* 0x631: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_634:
	/* 0x634: je     78c <write_reg+0x4c9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x634, 0x78c, x86_l_78c);
x86_l_63a:
	/* 0x63a: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_63d:
	/* 0x63d: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x63d, 0x7d2, x86_l_7d2);
x86_l_643:
	/* 0x643: mov    QWORD PTR [rdi+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_647:
	/* 0x647: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_648:
	/* 0x648: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64b:
	/* 0x64b: je     797 <write_reg+0x4d4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x64b, 0x797, x86_l_797);
x86_l_651:
	/* 0x651: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_654:
	/* 0x654: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x654, 0x7d2, x86_l_7d2);
x86_l_65a:
	/* 0x65a: mov    QWORD PTR [rdi+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_661:
	/* 0x661: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_662:
	/* 0x662: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_665:
	/* 0x665: je     7ad <write_reg+0x4ea> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x665, 0x7ad, x86_l_7ad);
x86_l_66b:
	/* 0x66b: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_66e:
	/* 0x66e: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x66e, 0x7d2, x86_l_7d2);
x86_l_674:
	/* 0x674: mov    QWORD PTR [rdi],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_677:
	/* 0x677: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_678:
	/* 0x678: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_67b:
	/* 0x67b: je     7b0 <write_reg+0x4ed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x67b, 0x7b0, x86_l_7b0);
x86_l_681:
	/* 0x681: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_684:
	/* 0x684: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x684, 0x7d2, x86_l_7d2);
x86_l_68a:
	/* 0x68a: mov    QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_68e:
	/* 0x68e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_68f:
	/* 0x68f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_692:
	/* 0x692: je     7b4 <write_reg+0x4f1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x692, 0x7b4, x86_l_7b4);
x86_l_698:
	/* 0x698: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_69b:
	/* 0x69b: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x69b, 0x7d2, x86_l_7d2);
x86_l_6a1:
	/* 0x6a1: mov    QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a5:
	/* 0x6a5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6a6:
	/* 0x6a6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6a9:
	/* 0x6a9: je     7b8 <write_reg+0x4f5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6a9, 0x7b8, x86_l_7b8);
x86_l_6af:
	/* 0x6af: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6b2:
	/* 0x6b2: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6b2, 0x7d2, x86_l_7d2);
x86_l_6b8:
	/* 0x6b8: mov    QWORD PTR [rdi+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6bc:
	/* 0x6bc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6bd:
	/* 0x6bd: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6c0:
	/* 0x6c0: je     7c0 <write_reg+0x4fd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6c0, 0x7c0, x86_l_7c0);
x86_l_6c6:
	/* 0x6c6: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6c9:
	/* 0x6c9: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6c9, 0x7d2, x86_l_7d2);
x86_l_6cf:
	/* 0x6cf: mov    QWORD PTR [rdi+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6d3:
	/* 0x6d3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6d4:
	/* 0x6d4: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6d7:
	/* 0x6d7: je     7c8 <write_reg+0x505> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6d7, 0x7c8, x86_l_7c8);
x86_l_6dd:
	/* 0x6dd: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6e0:
	/* 0x6e0: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6e0, 0x7d2, x86_l_7d2);
x86_l_6e6:
	/* 0x6e6: mov    QWORD PTR [rdi+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6ea:
	/* 0x6ea: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6eb:
	/* 0x6eb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ee:
	/* 0x6ee: je     7d3 <write_reg+0x510> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6ee, 0x7d3, x86_l_7d3);
x86_l_6f4:
	/* 0x6f4: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6f7:
	/* 0x6f7: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6f7, 0x7d2, x86_l_7d2);
x86_l_6fd:
	/* 0x6fd: mov    QWORD PTR [rdi+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_704:
	/* 0x704: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_705:
	/* 0x705: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_708:
	/* 0x708: je     7ea <write_reg+0x527> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x708, 0x7ea, x86_l_7ea);
x86_l_70e:
	/* 0x70e: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_711:
	/* 0x711: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x711, 0x7d2, x86_l_7d2);
x86_l_717:
	/* 0x717: mov    QWORD PTR [rdi+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71b:
	/* 0x71b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_71c:
	/* 0x71c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_71f:
	/* 0x71f: je     7ee <write_reg+0x52b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x71f, 0x7ee, x86_l_7ee);
x86_l_725:
	/* 0x725: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_728:
	/* 0x728: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x728, 0x7d2, x86_l_7d2);
x86_l_72e:
	/* 0x72e: mov    QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_732:
	/* 0x732: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_733:
	/* 0x733: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_736:
	/* 0x736: je     7f2 <write_reg+0x52f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x736, 0x7f2, x86_l_7f2);
x86_l_73c:
	/* 0x73c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_73f:
	/* 0x73f: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x73f, 0x7d2, x86_l_7d2);
x86_l_745:
	/* 0x745: mov    QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_749:
	/* 0x749: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_74a:
	/* 0x74a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_74d:
	/* 0x74d: je     7f6 <write_reg+0x533> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x74d, 0x7f6, x86_l_7f6);
x86_l_753:
	/* 0x753: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_756:
	/* 0x756: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x756, 0x7d2, x86_l_7d2);
x86_l_758:
	/* 0x758: mov    QWORD PTR [rdi+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_75c:
	/* 0x75c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_75d:
	/* 0x75d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_760:
	/* 0x760: je     7fe <write_reg+0x53b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x760, 0x7fe, x86_l_7fe);
x86_l_766:
	/* 0x766: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_769:
	/* 0x769: jne    7d2 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x769, 0x7d2, x86_l_7d2);
x86_l_76b:
	/* 0x76b: mov    QWORD PTR [rdi+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_76f:
	/* 0x76f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_770:
	/* 0x770: mov    BYTE PTR [rdi+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_773:
	/* 0x773: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_774:
	/* 0x774: mov    BYTE PTR [rdi+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_777:
	/* 0x777: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_778:
	/* 0x778: mov    DWORD PTR [rdi+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_77b:
	/* 0x77b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_77c:
	/* 0x77c: mov    DWORD PTR [rdi+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_77f:
	/* 0x77f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_780:
	/* 0x780: mov    BYTE PTR [rdi+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_783:
	/* 0x783: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_784:
	/* 0x784: mov    BYTE PTR [rdi+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_787:
	/* 0x787: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_788:
	/* 0x788: mov    DWORD PTR [rdi+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_78b:
	/* 0x78b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_78c:
	/* 0x78c: mov    DWORD PTR [rdi+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_78f:
	/* 0x78f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_790:
	/* 0x790: mov    BYTE PTR [rdi+0x80],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_796:
	/* 0x796: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_797:
	/* 0x797: mov    DWORD PTR [rdi+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_79d:
	/* 0x79d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_79e:
	/* 0x79e: mov    BYTE PTR [rdi],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a0:
	/* 0x7a0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7a1:
	/* 0x7a1: mov    BYTE PTR [rdi+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a4:
	/* 0x7a4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7a5:
	/* 0x7a5: mov    BYTE PTR [rdi+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a8:
	/* 0x7a8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7a9:
	/* 0x7a9: mov    BYTE PTR [rdi+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ac:
	/* 0x7ac: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ad:
	/* 0x7ad: mov    DWORD PTR [rdi],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7af:
	/* 0x7af: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b0:
	/* 0x7b0: mov    DWORD PTR [rdi+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b3:
	/* 0x7b3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b4:
	/* 0x7b4: mov    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b7:
	/* 0x7b7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b8:
	/* 0x7b8: mov    DWORD PTR [rdi+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7bb:
	/* 0x7bb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7bc:
	/* 0x7bc: mov    BYTE PTR [rdi+0x70],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7bf:
	/* 0x7bf: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c0:
	/* 0x7c0: mov    DWORD PTR [rdi+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7c3:
	/* 0x7c3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c4:
	/* 0x7c4: mov    BYTE PTR [rdi+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c7:
	/* 0x7c7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c8:
	/* 0x7c8: mov    DWORD PTR [rdi+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7cb:
	/* 0x7cb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7cc:
	/* 0x7cc: mov    BYTE PTR [rdi+0x98],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7d2:
	/* 0x7d2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d3:
	/* 0x7d3: mov    DWORD PTR [rdi+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7d9:
	/* 0x7d9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7da:
	/* 0x7da: mov    BYTE PTR [rdi+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7dd:
	/* 0x7dd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7de:
	/* 0x7de: mov    BYTE PTR [rdi+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7e1:
	/* 0x7e1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e2:
	/* 0x7e2: mov    BYTE PTR [rdi+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7e5:
	/* 0x7e5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e6:
	/* 0x7e6: mov    BYTE PTR [rdi+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e9:
	/* 0x7e9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ea:
	/* 0x7ea: mov    DWORD PTR [rdi+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ed:
	/* 0x7ed: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ee:
	/* 0x7ee: mov    DWORD PTR [rdi+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7f1:
	/* 0x7f1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7f2:
	/* 0x7f2: mov    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7f5:
	/* 0x7f5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7f6:
	/* 0x7f6: mov    DWORD PTR [rdi+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7f9:
	/* 0x7f9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7fa:
	/* 0x7fa: mov    BYTE PTR [rdi+0x68],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7fd:
	/* 0x7fd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7fe:
	/* 0x7fe: mov    DWORD PTR [rdi+0x68],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_801:
	/* 0x801: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1aULL: goto x86_l_1a;
	case 0x32ULL: goto x86_l_32;
	case 0x51ULL: goto x86_l_51;
	case 0x62ULL: goto x86_l_62;
	case 0xa2ULL: goto x86_l_a2;
	case 0xc2ULL: goto x86_l_c2;
	case 0x11aULL: goto x86_l_11a;
	case 0x148ULL: goto x86_l_148;
	case 0x16cULL: goto x86_l_16c;
	}

}

X86_SIM_LICENSE();
