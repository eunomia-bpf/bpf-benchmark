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
	/* 0xa: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a:
	/* 0x1a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1f:
	/* 0x1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21:
	/* 0x21: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26:
	/* 0x26: mov    rdi,QWORD PTR [rip+0xf0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_2d:
	/* 0x2d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x3c: je     1a6 <generic_sleepable_offload+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c, 0x1a6, x86_l_1a6);
x86_l_42:
	/* 0x42: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_45:
	/* 0x45: mov    rdi,QWORD PTR [rip+0xe3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_4c:
	/* 0x4c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51:
	/* 0x51: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: mov    rdi,QWORD PTR [rip+0xe3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&regs_map)));
x86_l_5f:
	/* 0x5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64:
	/* 0x64: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_67:
	/* 0x67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69:
	/* 0x69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: je     1a6 <generic_sleepable_offload+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c, 0x1a6, x86_l_1a6);
x86_l_72:
	/* 0x72: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_78:
	/* 0x78: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7c:
	/* 0x7c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f:
	/* 0x7f: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84:
	/* 0x84: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_89:
	/* 0x89: jmp    da <generic_sleepable_offload+0xda> */
	X86_SIM_X86_JMP(0x89, 0xda, x86_l_da);
x86_l_8b:
	/* 0x8b: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_91:
	/* 0x91: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_97:
	/* 0x97: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_9a:
	/* 0x9a: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_9c:
	/* 0x9c: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_9e:
	/* 0x9e: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a1:
	/* 0xa1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a4:
	/* 0xa4: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_1bb, 0xa9ULL);
x86_l_a9:
	/* 0xa9: add    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2:
	/* 0xb2: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_b8:
	/* 0xb8: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_be:
	/* 0xbe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c1:
	/* 0xc1: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_2d1, 0xc9ULL);
x86_l_c9:
	/* 0xc9: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_cc:
	/* 0xcc: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d0:
	/* 0xd0: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_d4:
	/* 0xd4: je     1a6 <generic_sleepable_offload+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4, 0x1a6, x86_l_1a6);
x86_l_da:
	/* 0xda: mov    eax,DWORD PTR [r14+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_e1:
	/* 0xe1: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e4:
	/* 0xe4: jae    1a6 <generic_sleepable_offload+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xe4, 0x1a6, x86_l_1a6);
x86_l_ea:
	/* 0xea: movzx  eax,BYTE PTR [r12-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_f0:
	/* 0xf0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f3:
	/* 0xf3: jg     123 <generic_sleepable_offload+0x123> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf3, 0x123, x86_l_123);
x86_l_f5:
	/* 0xf5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f8:
	/* 0xf8: je     18e <generic_sleepable_offload+0x18e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8, 0x18e, x86_l_18e);
x86_l_fe:
	/* 0xfe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_101:
	/* 0x101: jne    c9 <generic_sleepable_offload+0xc9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x101, 0xc9, x86_l_c9);
x86_l_103:
	/* 0x103: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_109:
	/* 0x109: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_10f:
	/* 0x10f: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_112:
	/* 0x112: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_114:
	/* 0x114: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_116:
	/* 0x116: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_119:
	/* 0x119: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11c:
	/* 0x11c: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_1bb, 0x121ULL);
x86_l_121:
	/* 0x121: jmp    ad <generic_sleepable_offload+0xad> */
	X86_SIM_X86_JMP(0x121, 0xad, x86_l_ad);
x86_l_123:
	/* 0x123: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_126:
	/* 0x126: je     8b <generic_sleepable_offload+0x8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x126, 0x8b, x86_l_8b);
x86_l_12c:
	/* 0x12c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f:
	/* 0x12f: jne    c9 <generic_sleepable_offload+0xc9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12f, 0xc9, x86_l_c9);
x86_l_131:
	/* 0x131: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_137:
	/* 0x137: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_13d:
	/* 0x13d: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_140:
	/* 0x140: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_142:
	/* 0x142: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_144:
	/* 0x144: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_147:
	/* 0x147: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14a:
	/* 0x14a: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_1bb, 0x14fULL);
x86_l_14f:
	/* 0x14f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_152:
	/* 0x152: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157:
	/* 0x157: add    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15b:
	/* 0x15b: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_160:
	/* 0x160: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165:
	/* 0x165: add    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_169:
	/* 0x169: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16c:
	/* 0x16c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_171:
	/* 0x171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173:
	/* 0x173: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_175:
	/* 0x175: jne    c9 <generic_sleepable_offload+0xc9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x175, 0xc9, x86_l_c9);
x86_l_17b:
	/* 0x17b: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_181:
	/* 0x181: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_187:
	/* 0x187: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18c:
	/* 0x18c: jmp    19e <generic_sleepable_offload+0x19e> */
	X86_SIM_X86_JMP(0x18c, 0x19e, x86_l_19e);
x86_l_18e:
	/* 0x18e: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_194:
	/* 0x194: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_19a:
	/* 0x19a: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e:
	/* 0x19e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a1:
	/* 0x1a1: jmp    c4 <generic_sleepable_offload+0xc4> */
	X86_SIM_X86_JMP(0x1a1, 0xc4, x86_l_c4);
x86_l_1a6:
	/* 0x1a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8:
	/* 0x1a8: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1ac:
	/* 0x1ac: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1af:
	/* 0x1af: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1b1:
	/* 0x1b1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b3:
	/* 0x1b3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1b5:
	/* 0x1b5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1b6:
	/* 0x1b6: jmp    810 <write_reg+0x53f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_810:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_1bb */
x86_l_1bb:
	/* 0x1bb: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_1c1:
	/* 0x1c1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c3:
	/* 0x1c3: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c6:
	/* 0x1c6: jle    1fd <read_reg+0x42> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1c6, 0x1fd, x86_l_1fd);
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1cb:
	/* 0x1cb: jle    221 <read_reg+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1cb, 0x221, x86_l_221);
x86_l_1cd:
	/* 0x1cd: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1d0:
	/* 0x1d0: jle    286 <read_reg+0xcb> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1d0, 0x286, x86_l_286);
x86_l_1d6:
	/* 0x1d6: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1d9:
	/* 0x1d9: je     2ba <read_reg+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d9, 0x2ba, x86_l_2ba);
x86_l_1df:
	/* 0x1df: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e2:
	/* 0x1e2: je     2a2 <read_reg+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1e2, 0x2a2, x86_l_2a2);
x86_l_1e8:
	/* 0x1e8: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1eb:
	/* 0x1eb: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1eb, 0x2d0, x86_l_2d0);
x86_l_1f1:
	/* 0x1f1: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1f8:
	/* 0x1f8: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x1f8, 0x2c4, x86_l_2c4);
x86_l_1fd:
	/* 0x1fd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_200:
	/* 0x200: jg     23d <read_reg+0x82> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x200, 0x23d, x86_l_23d);
x86_l_202:
	/* 0x202: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_205:
	/* 0x205: jg     266 <read_reg+0xab> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x205, 0x266, x86_l_266);
x86_l_207:
	/* 0x207: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_209:
	/* 0x209: je     2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x209, 0x2c4, x86_l_2c4);
x86_l_20f:
	/* 0x20f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_212:
	/* 0x212: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x212, 0x2d0, x86_l_2d0);
x86_l_218:
	/* 0x218: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21c:
	/* 0x21c: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x21c, 0x2c4, x86_l_2c4);
x86_l_221:
	/* 0x221: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_224:
	/* 0x224: jg     256 <read_reg+0x9b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x224, 0x256, x86_l_256);
x86_l_226:
	/* 0x226: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_229:
	/* 0x229: je     296 <read_reg+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x229, 0x296, x86_l_296);
x86_l_22b:
	/* 0x22b: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_22e:
	/* 0x22e: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x22e, 0x2d0, x86_l_2d0);
x86_l_234:
	/* 0x234: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_238:
	/* 0x238: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x238, 0x2c4, x86_l_2c4);
x86_l_23d:
	/* 0x23d: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_240:
	/* 0x240: jg     276 <read_reg+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x240, 0x276, x86_l_276);
x86_l_242:
	/* 0x242: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_245:
	/* 0x245: je     2a8 <read_reg+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x245, 0x2a8, x86_l_2a8);
x86_l_247:
	/* 0x247: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_24a:
	/* 0x24a: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x24a, 0x2d0, x86_l_2d0);
x86_l_250:
	/* 0x250: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_254:
	/* 0x254: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x254, 0x2c4, x86_l_2c4);
x86_l_256:
	/* 0x256: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_259:
	/* 0x259: je     29c <read_reg+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x259, 0x29c, x86_l_29c);
x86_l_25b:
	/* 0x25b: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_25e:
	/* 0x25e: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x25e, 0x2d0, x86_l_2d0);
x86_l_260:
	/* 0x260: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_264:
	/* 0x264: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x264, 0x2c4, x86_l_2c4);
x86_l_266:
	/* 0x266: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_269:
	/* 0x269: je     2ae <read_reg+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x269, 0x2ae, x86_l_2ae);
x86_l_26b:
	/* 0x26b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_26e:
	/* 0x26e: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x26e, 0x2d0, x86_l_2d0);
x86_l_270:
	/* 0x270: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_274:
	/* 0x274: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x274, 0x2c4, x86_l_2c4);
x86_l_276:
	/* 0x276: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_279:
	/* 0x279: je     2b4 <read_reg+0xf9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x279, 0x2b4, x86_l_2b4);
x86_l_27b:
	/* 0x27b: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_27e:
	/* 0x27e: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x27e, 0x2d0, x86_l_2d0);
x86_l_280:
	/* 0x280: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_284:
	/* 0x284: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x284, 0x2c4, x86_l_2c4);
x86_l_286:
	/* 0x286: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_289:
	/* 0x289: je     2c0 <read_reg+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x289, 0x2c0, x86_l_2c0);
x86_l_28b:
	/* 0x28b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_28e:
	/* 0x28e: jne    2d0 <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x28e, 0x2d0, x86_l_2d0);
x86_l_290:
	/* 0x290: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_294:
	/* 0x294: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x294, 0x2c4, x86_l_2c4);
x86_l_296:
	/* 0x296: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_29a:
	/* 0x29a: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x29a, 0x2c4, x86_l_2c4);
x86_l_29c:
	/* 0x29c: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2a0:
	/* 0x2a0: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2a0, 0x2c4, x86_l_2c4);
x86_l_2a2:
	/* 0x2a2: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_2a6:
	/* 0x2a6: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2a6, 0x2c4, x86_l_2c4);
x86_l_2a8:
	/* 0x2a8: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2ac:
	/* 0x2ac: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2ac, 0x2c4, x86_l_2c4);
x86_l_2ae:
	/* 0x2ae: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b2:
	/* 0x2b2: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2b2, 0x2c4, x86_l_2c4);
x86_l_2b4:
	/* 0x2b4: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_2b8:
	/* 0x2b8: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2b8, 0x2c4, x86_l_2c4);
x86_l_2ba:
	/* 0x2ba: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_2be:
	/* 0x2be: jmp    2c4 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x2be, 0x2c4, x86_l_2c4);
x86_l_2c0:
	/* 0x2c0: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2c4:
	/* 0x2c4: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2c9:
	/* 0x2c9: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cb:
	/* 0x2cb: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2d0:
	/* 0x2d0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_2d1 */
x86_l_2d1:
	/* 0x2d1: rorx   eax,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_2d7:
	/* 0x2d7: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2da:
	/* 0x2da: jle    32f <write_reg+0x5e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2da, 0x32f, x86_l_32f);
x86_l_2dc:
	/* 0x2dc: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2df:
	/* 0x2df: jle    371 <write_reg+0xa0> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2df, 0x371, x86_l_371);
x86_l_2e5:
	/* 0x2e5: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_2e8:
	/* 0x2e8: jle    488 <write_reg+0x1b7> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2e8, 0x488, x86_l_488);
x86_l_2ee:
	/* 0x2ee: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2f1:
	/* 0x2f1: je     5b4 <write_reg+0x2e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2f1, 0x5b4, x86_l_5b4);
x86_l_2f7:
	/* 0x2f7: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2fa:
	/* 0x2fa: je     503 <write_reg+0x232> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2fa, 0x503, x86_l_503);
x86_l_300:
	/* 0x300: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_303:
	/* 0x303: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x303, 0x7e0, x86_l_7e0);
x86_l_309:
	/* 0x309: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30c:
	/* 0x30c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_30f:
	/* 0x30f: jg     6f9 <write_reg+0x428> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x30f, 0x6f9, x86_l_6f9);
x86_l_315:
	/* 0x315: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_318:
	/* 0x318: je     7da <write_reg+0x509> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x318, 0x7da, x86_l_7da);
x86_l_31e:
	/* 0x31e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_321:
	/* 0x321: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x321, 0x7e0, x86_l_7e0);
x86_l_327:
	/* 0x327: mov    WORD PTR [rdi+0x98],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_32e:
	/* 0x32e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_32f:
	/* 0x32f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_332:
	/* 0x332: jg     3ab <write_reg+0xda> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x332, 0x3ab, x86_l_3ab);
x86_l_334:
	/* 0x334: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_337:
	/* 0x337: jg     41e <write_reg+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x337, 0x41e, x86_l_41e);
x86_l_33d:
	/* 0x33d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33f:
	/* 0x33f: je     529 <write_reg+0x258> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x33f, 0x529, x86_l_529);
x86_l_345:
	/* 0x345: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_348:
	/* 0x348: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x348, 0x7e0, x86_l_7e0);
x86_l_34e:
	/* 0x34e: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_351:
	/* 0x351: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_354:
	/* 0x354: jg     713 <write_reg+0x442> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x354, 0x713, x86_l_713);
x86_l_35a:
	/* 0x35a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35d:
	/* 0x35d: je     7e8 <write_reg+0x517> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x35d, 0x7e8, x86_l_7e8);
x86_l_363:
	/* 0x363: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_366:
	/* 0x366: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x366, 0x7e0, x86_l_7e0);
x86_l_36c:
	/* 0x36c: mov    WORD PTR [rdi+0x8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_370:
	/* 0x370: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_371:
	/* 0x371: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_374:
	/* 0x374: jg     3e9 <write_reg+0x118> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x374, 0x3e9, x86_l_3e9);
x86_l_376:
	/* 0x376: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_379:
	/* 0x379: je     4bd <write_reg+0x1ec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x379, 0x4bd, x86_l_4bd);
x86_l_37f:
	/* 0x37f: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_382:
	/* 0x382: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x382, 0x7e0, x86_l_7e0);
x86_l_388:
	/* 0x388: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_38b:
	/* 0x38b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_38e:
	/* 0x38e: jg     628 <write_reg+0x357> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x38e, 0x628, x86_l_628);
x86_l_394:
	/* 0x394: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_397:
	/* 0x397: je     78e <write_reg+0x4bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x397, 0x78e, x86_l_78e);
x86_l_39d:
	/* 0x39d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a0:
	/* 0x3a0: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3a0, 0x7e0, x86_l_7e0);
x86_l_3a6:
	/* 0x3a6: mov    WORD PTR [rdi+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3aa:
	/* 0x3aa: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3ab:
	/* 0x3ab: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3ae:
	/* 0x3ae: jg     453 <write_reg+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3ae, 0x453, x86_l_453);
x86_l_3b4:
	/* 0x3b4: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b7:
	/* 0x3b7: je     54b <write_reg+0x27a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3b7, 0x54b, x86_l_54b);
x86_l_3bd:
	/* 0x3bd: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3c0:
	/* 0x3c0: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3c0, 0x7e0, x86_l_7e0);
x86_l_3c6:
	/* 0x3c6: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3c9:
	/* 0x3c9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3cc:
	/* 0x3cc: jg     72a <write_reg+0x459> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3cc, 0x72a, x86_l_72a);
x86_l_3d2:
	/* 0x3d2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d5:
	/* 0x3d5: je     7ec <write_reg+0x51b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3d5, 0x7ec, x86_l_7ec);
x86_l_3db:
	/* 0x3db: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3de:
	/* 0x3de: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3de, 0x7e0, x86_l_7e0);
x86_l_3e4:
	/* 0x3e4: mov    WORD PTR [rdi+0x28],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e8:
	/* 0x3e8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3e9:
	/* 0x3e9: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_3ec:
	/* 0x3ec: je     4e0 <write_reg+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3ec, 0x4e0, x86_l_4e0);
x86_l_3f2:
	/* 0x3f2: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3f5:
	/* 0x3f5: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3f5, 0x7e0, x86_l_7e0);
x86_l_3fb:
	/* 0x3fb: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3fe:
	/* 0x3fe: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_401:
	/* 0x401: jg     63f <write_reg+0x36e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x401, 0x63f, x86_l_63f);
x86_l_407:
	/* 0x407: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40a:
	/* 0x40a: je     792 <write_reg+0x4c1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x40a, 0x792, x86_l_792);
x86_l_410:
	/* 0x410: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_413:
	/* 0x413: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x413, 0x7e0, x86_l_7e0);
x86_l_419:
	/* 0x419: mov    WORD PTR [rdi+0x58],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41d:
	/* 0x41d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_41e:
	/* 0x41e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_421:
	/* 0x421: je     56e <write_reg+0x29d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x421, 0x56e, x86_l_56e);
x86_l_427:
	/* 0x427: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_42a:
	/* 0x42a: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x42a, 0x7e0, x86_l_7e0);
x86_l_430:
	/* 0x430: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_433:
	/* 0x433: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_436:
	/* 0x436: jg     741 <write_reg+0x470> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x436, 0x741, x86_l_741);
x86_l_43c:
	/* 0x43c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_43f:
	/* 0x43f: je     7f0 <write_reg+0x51f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x43f, 0x7f0, x86_l_7f0);
x86_l_445:
	/* 0x445: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_448:
	/* 0x448: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x448, 0x7e0, x86_l_7e0);
x86_l_44e:
	/* 0x44e: mov    WORD PTR [rdi+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_452:
	/* 0x452: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_453:
	/* 0x453: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_456:
	/* 0x456: je     591 <write_reg+0x2c0> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x456, 0x591, x86_l_591);
x86_l_45c:
	/* 0x45c: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_45f:
	/* 0x45f: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x45f, 0x7e0, x86_l_7e0);
x86_l_465:
	/* 0x465: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_468:
	/* 0x468: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_46b:
	/* 0x46b: jg     758 <write_reg+0x487> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x46b, 0x758, x86_l_758);
x86_l_471:
	/* 0x471: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_474:
	/* 0x474: je     7f4 <write_reg+0x523> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x474, 0x7f4, x86_l_7f4);
x86_l_47a:
	/* 0x47a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_47d:
	/* 0x47d: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x47d, 0x7e0, x86_l_7e0);
x86_l_483:
	/* 0x483: mov    WORD PTR [rdi+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_487:
	/* 0x487: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_488:
	/* 0x488: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_48b:
	/* 0x48b: je     5d7 <write_reg+0x306> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x48b, 0x5d7, x86_l_5d7);
x86_l_491:
	/* 0x491: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_494:
	/* 0x494: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x494, 0x7e0, x86_l_7e0);
x86_l_49a:
	/* 0x49a: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_49d:
	/* 0x49d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4a0:
	/* 0x4a0: jg     76b <write_reg+0x49a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4a0, 0x76b, x86_l_76b);
x86_l_4a6:
	/* 0x4a6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a9:
	/* 0x4a9: je     808 <write_reg+0x537> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4a9, 0x808, x86_l_808);
x86_l_4af:
	/* 0x4af: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4b2:
	/* 0x4b2: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4b2, 0x7e0, x86_l_7e0);
x86_l_4b8:
	/* 0x4b8: mov    WORD PTR [rdi+0x68],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4bc:
	/* 0x4bc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4bd:
	/* 0x4bd: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4c0:
	/* 0x4c0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4c3:
	/* 0x4c3: jg     5fa <write_reg+0x329> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4c3, 0x5fa, x86_l_5fa);
x86_l_4c9:
	/* 0x4c9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4cc:
	/* 0x4cc: je     77e <write_reg+0x4ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4cc, 0x77e, x86_l_77e);
x86_l_4d2:
	/* 0x4d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4d5:
	/* 0x4d5: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4d5, 0x7e0, x86_l_7e0);
x86_l_4db:
	/* 0x4db: mov    WORD PTR [rdi+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4df:
	/* 0x4df: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4e0:
	/* 0x4e0: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4e3:
	/* 0x4e3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4e6:
	/* 0x4e6: jg     611 <write_reg+0x340> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4e6, 0x611, x86_l_611);
x86_l_4ec:
	/* 0x4ec: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ef:
	/* 0x4ef: je     782 <write_reg+0x4b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ef, 0x782, x86_l_782);
x86_l_4f5:
	/* 0x4f5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4f8:
	/* 0x4f8: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4f8, 0x7e0, x86_l_7e0);
x86_l_4fe:
	/* 0x4fe: mov    WORD PTR [rdi+0x50],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_502:
	/* 0x502: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_503:
	/* 0x503: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_506:
	/* 0x506: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_509:
	/* 0x509: jg     656 <write_reg+0x385> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x509, 0x656, x86_l_656);
x86_l_50f:
	/* 0x50f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_512:
	/* 0x512: je     79e <write_reg+0x4cd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x512, 0x79e, x86_l_79e);
x86_l_518:
	/* 0x518: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_51b:
	/* 0x51b: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x51b, 0x7e0, x86_l_7e0);
x86_l_521:
	/* 0x521: mov    WORD PTR [rdi+0x80],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_528:
	/* 0x528: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_529:
	/* 0x529: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_52c:
	/* 0x52c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_52f:
	/* 0x52f: jg     670 <write_reg+0x39f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x52f, 0x670, x86_l_670);
x86_l_535:
	/* 0x535: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_538:
	/* 0x538: je     7ac <write_reg+0x4db> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x538, 0x7ac, x86_l_7ac);
x86_l_53e:
	/* 0x53e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_541:
	/* 0x541: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x541, 0x7e0, x86_l_7e0);
x86_l_547:
	/* 0x547: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54a:
	/* 0x54a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_54b:
	/* 0x54b: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_54e:
	/* 0x54e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_551:
	/* 0x551: jg     686 <write_reg+0x3b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x551, 0x686, x86_l_686);
x86_l_557:
	/* 0x557: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55a:
	/* 0x55a: je     7af <write_reg+0x4de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x55a, 0x7af, x86_l_7af);
x86_l_560:
	/* 0x560: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_563:
	/* 0x563: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x563, 0x7e0, x86_l_7e0);
x86_l_569:
	/* 0x569: mov    WORD PTR [rdi+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56d:
	/* 0x56d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_56e:
	/* 0x56e: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_571:
	/* 0x571: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_574:
	/* 0x574: jg     69d <write_reg+0x3cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x574, 0x69d, x86_l_69d);
x86_l_57a:
	/* 0x57a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57d:
	/* 0x57d: je     7b3 <write_reg+0x4e2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x57d, 0x7b3, x86_l_7b3);
x86_l_583:
	/* 0x583: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_586:
	/* 0x586: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x586, 0x7e0, x86_l_7e0);
x86_l_58c:
	/* 0x58c: mov    WORD PTR [rdi+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_590:
	/* 0x590: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_591:
	/* 0x591: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_594:
	/* 0x594: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_597:
	/* 0x597: jg     6b4 <write_reg+0x3e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x597, 0x6b4, x86_l_6b4);
x86_l_59d:
	/* 0x59d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a0:
	/* 0x5a0: je     7b7 <write_reg+0x4e6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5a0, 0x7b7, x86_l_7b7);
x86_l_5a6:
	/* 0x5a6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5a9:
	/* 0x5a9: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5a9, 0x7e0, x86_l_7e0);
x86_l_5af:
	/* 0x5af: mov    WORD PTR [rdi+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b3:
	/* 0x5b3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5b4:
	/* 0x5b4: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b7:
	/* 0x5b7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5ba:
	/* 0x5ba: jg     6cb <write_reg+0x3fa> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x5ba, 0x6cb, x86_l_6cb);
x86_l_5c0:
	/* 0x5c0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c3:
	/* 0x5c3: je     7ca <write_reg+0x4f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5c3, 0x7ca, x86_l_7ca);
x86_l_5c9:
	/* 0x5c9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5cc:
	/* 0x5cc: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5cc, 0x7e0, x86_l_7e0);
x86_l_5d2:
	/* 0x5d2: mov    WORD PTR [rdi+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d6:
	/* 0x5d6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5d7:
	/* 0x5d7: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5da:
	/* 0x5da: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5dd:
	/* 0x5dd: jg     6e2 <write_reg+0x411> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x5dd, 0x6e2, x86_l_6e2);
x86_l_5e3:
	/* 0x5e3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e6:
	/* 0x5e6: je     7d2 <write_reg+0x501> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5e6, 0x7d2, x86_l_7d2);
x86_l_5ec:
	/* 0x5ec: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ef:
	/* 0x5ef: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5ef, 0x7e0, x86_l_7e0);
x86_l_5f5:
	/* 0x5f5: mov    WORD PTR [rdi+0x60],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5f9:
	/* 0x5f9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5fa:
	/* 0x5fa: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5fd:
	/* 0x5fd: je     786 <write_reg+0x4b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5fd, 0x786, x86_l_786);
x86_l_603:
	/* 0x603: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_606:
	/* 0x606: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x606, 0x7e0, x86_l_7e0);
x86_l_60c:
	/* 0x60c: mov    QWORD PTR [rdi+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_610:
	/* 0x610: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_611:
	/* 0x611: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_614:
	/* 0x614: je     78a <write_reg+0x4b9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x614, 0x78a, x86_l_78a);
x86_l_61a:
	/* 0x61a: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_61d:
	/* 0x61d: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x61d, 0x7e0, x86_l_7e0);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rdi+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_627:
	/* 0x627: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_628:
	/* 0x628: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62b:
	/* 0x62b: je     796 <write_reg+0x4c5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x62b, 0x796, x86_l_796);
x86_l_631:
	/* 0x631: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_634:
	/* 0x634: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x634, 0x7e0, x86_l_7e0);
x86_l_63a:
	/* 0x63a: mov    QWORD PTR [rdi+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_63e:
	/* 0x63e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_63f:
	/* 0x63f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_642:
	/* 0x642: je     79a <write_reg+0x4c9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x642, 0x79a, x86_l_79a);
x86_l_648:
	/* 0x648: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_64b:
	/* 0x64b: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x64b, 0x7e0, x86_l_7e0);
x86_l_651:
	/* 0x651: mov    QWORD PTR [rdi+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_655:
	/* 0x655: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_656:
	/* 0x656: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_659:
	/* 0x659: je     7a5 <write_reg+0x4d4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x659, 0x7a5, x86_l_7a5);
x86_l_65f:
	/* 0x65f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_662:
	/* 0x662: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x662, 0x7e0, x86_l_7e0);
x86_l_668:
	/* 0x668: mov    QWORD PTR [rdi+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_66f:
	/* 0x66f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_670:
	/* 0x670: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_673:
	/* 0x673: je     7bb <write_reg+0x4ea> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x673, 0x7bb, x86_l_7bb);
x86_l_679:
	/* 0x679: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_67c:
	/* 0x67c: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x67c, 0x7e0, x86_l_7e0);
x86_l_682:
	/* 0x682: mov    QWORD PTR [rdi],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_685:
	/* 0x685: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_686:
	/* 0x686: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_689:
	/* 0x689: je     7be <write_reg+0x4ed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x689, 0x7be, x86_l_7be);
x86_l_68f:
	/* 0x68f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_692:
	/* 0x692: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x692, 0x7e0, x86_l_7e0);
x86_l_698:
	/* 0x698: mov    QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69c:
	/* 0x69c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_69d:
	/* 0x69d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6a0:
	/* 0x6a0: je     7c2 <write_reg+0x4f1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6a0, 0x7c2, x86_l_7c2);
x86_l_6a6:
	/* 0x6a6: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6a9:
	/* 0x6a9: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6a9, 0x7e0, x86_l_7e0);
x86_l_6af:
	/* 0x6af: mov    QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b3:
	/* 0x6b3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6b4:
	/* 0x6b4: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b7:
	/* 0x6b7: je     7c6 <write_reg+0x4f5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6b7, 0x7c6, x86_l_7c6);
x86_l_6bd:
	/* 0x6bd: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6c0:
	/* 0x6c0: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6c0, 0x7e0, x86_l_7e0);
x86_l_6c6:
	/* 0x6c6: mov    QWORD PTR [rdi+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ca:
	/* 0x6ca: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6cb:
	/* 0x6cb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ce:
	/* 0x6ce: je     7ce <write_reg+0x4fd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6ce, 0x7ce, x86_l_7ce);
x86_l_6d4:
	/* 0x6d4: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6d7:
	/* 0x6d7: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6d7, 0x7e0, x86_l_7e0);
x86_l_6dd:
	/* 0x6dd: mov    QWORD PTR [rdi+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e1:
	/* 0x6e1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6e2:
	/* 0x6e2: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e5:
	/* 0x6e5: je     7d6 <write_reg+0x505> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6e5, 0x7d6, x86_l_7d6);
x86_l_6eb:
	/* 0x6eb: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6ee:
	/* 0x6ee: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6ee, 0x7e0, x86_l_7e0);
x86_l_6f4:
	/* 0x6f4: mov    QWORD PTR [rdi+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6f8:
	/* 0x6f8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6f9:
	/* 0x6f9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6fc:
	/* 0x6fc: je     7e1 <write_reg+0x510> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6fc, 0x7e1, x86_l_7e1);
x86_l_702:
	/* 0x702: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_705:
	/* 0x705: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x705, 0x7e0, x86_l_7e0);
x86_l_70b:
	/* 0x70b: mov    QWORD PTR [rdi+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_712:
	/* 0x712: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_713:
	/* 0x713: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_716:
	/* 0x716: je     7f8 <write_reg+0x527> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x716, 0x7f8, x86_l_7f8);
x86_l_71c:
	/* 0x71c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_71f:
	/* 0x71f: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x71f, 0x7e0, x86_l_7e0);
x86_l_725:
	/* 0x725: mov    QWORD PTR [rdi+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_729:
	/* 0x729: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_72a:
	/* 0x72a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_72d:
	/* 0x72d: je     7fc <write_reg+0x52b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x72d, 0x7fc, x86_l_7fc);
x86_l_733:
	/* 0x733: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_736:
	/* 0x736: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x736, 0x7e0, x86_l_7e0);
x86_l_73c:
	/* 0x73c: mov    QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_740:
	/* 0x740: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_741:
	/* 0x741: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_744:
	/* 0x744: je     800 <write_reg+0x52f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x744, 0x800, x86_l_800);
x86_l_74a:
	/* 0x74a: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_74d:
	/* 0x74d: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x74d, 0x7e0, x86_l_7e0);
x86_l_753:
	/* 0x753: mov    QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_757:
	/* 0x757: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_758:
	/* 0x758: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_75b:
	/* 0x75b: je     804 <write_reg+0x533> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x75b, 0x804, x86_l_804);
x86_l_761:
	/* 0x761: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_764:
	/* 0x764: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x764, 0x7e0, x86_l_7e0);
x86_l_766:
	/* 0x766: mov    QWORD PTR [rdi+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_76a:
	/* 0x76a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_76b:
	/* 0x76b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_76e:
	/* 0x76e: je     80c <write_reg+0x53b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x76e, 0x80c, x86_l_80c);
x86_l_774:
	/* 0x774: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_777:
	/* 0x777: jne    7e0 <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x777, 0x7e0, x86_l_7e0);
x86_l_779:
	/* 0x779: mov    QWORD PTR [rdi+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_77d:
	/* 0x77d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_77e:
	/* 0x77e: mov    BYTE PTR [rdi+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_781:
	/* 0x781: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_782:
	/* 0x782: mov    BYTE PTR [rdi+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_785:
	/* 0x785: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_786:
	/* 0x786: mov    DWORD PTR [rdi+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_789:
	/* 0x789: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_78a:
	/* 0x78a: mov    DWORD PTR [rdi+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_78d:
	/* 0x78d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_78e:
	/* 0x78e: mov    BYTE PTR [rdi+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_791:
	/* 0x791: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_792:
	/* 0x792: mov    BYTE PTR [rdi+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_795:
	/* 0x795: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_796:
	/* 0x796: mov    DWORD PTR [rdi+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_799:
	/* 0x799: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_79a:
	/* 0x79a: mov    DWORD PTR [rdi+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_79d:
	/* 0x79d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_79e:
	/* 0x79e: mov    BYTE PTR [rdi+0x80],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7a4:
	/* 0x7a4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7a5:
	/* 0x7a5: mov    DWORD PTR [rdi+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7ab:
	/* 0x7ab: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ac:
	/* 0x7ac: mov    BYTE PTR [rdi],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ae:
	/* 0x7ae: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7af:
	/* 0x7af: mov    BYTE PTR [rdi+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b2:
	/* 0x7b2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b3:
	/* 0x7b3: mov    BYTE PTR [rdi+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b6:
	/* 0x7b6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b7:
	/* 0x7b7: mov    BYTE PTR [rdi+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ba:
	/* 0x7ba: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7bb:
	/* 0x7bb: mov    DWORD PTR [rdi],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bd:
	/* 0x7bd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7be:
	/* 0x7be: mov    DWORD PTR [rdi+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c1:
	/* 0x7c1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c2:
	/* 0x7c2: mov    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c5:
	/* 0x7c5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c6:
	/* 0x7c6: mov    DWORD PTR [rdi+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c9:
	/* 0x7c9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ca:
	/* 0x7ca: mov    BYTE PTR [rdi+0x70],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7cd:
	/* 0x7cd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ce:
	/* 0x7ce: mov    DWORD PTR [rdi+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7d1:
	/* 0x7d1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d2:
	/* 0x7d2: mov    BYTE PTR [rdi+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7d5:
	/* 0x7d5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d6:
	/* 0x7d6: mov    DWORD PTR [rdi+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7d9:
	/* 0x7d9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7da:
	/* 0x7da: mov    BYTE PTR [rdi+0x98],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7e0:
	/* 0x7e0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e1:
	/* 0x7e1: mov    DWORD PTR [rdi+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7e7:
	/* 0x7e7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e8:
	/* 0x7e8: mov    BYTE PTR [rdi+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7eb:
	/* 0x7eb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ec:
	/* 0x7ec: mov    BYTE PTR [rdi+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7ef:
	/* 0x7ef: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7f0:
	/* 0x7f0: mov    BYTE PTR [rdi+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7f3:
	/* 0x7f3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7f4:
	/* 0x7f4: mov    BYTE PTR [rdi+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7f7:
	/* 0x7f7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7f8:
	/* 0x7f8: mov    DWORD PTR [rdi+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7fb:
	/* 0x7fb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7fc:
	/* 0x7fc: mov    DWORD PTR [rdi+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7ff:
	/* 0x7ff: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_800:
	/* 0x800: mov    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_803:
	/* 0x803: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_804:
	/* 0x804: mov    DWORD PTR [rdi+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_807:
	/* 0x807: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_808:
	/* 0x808: mov    BYTE PTR [rdi+0x68],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_80b:
	/* 0x80b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_80c:
	/* 0x80c: mov    DWORD PTR [rdi+0x68],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_80f:
	/* 0x80f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x21ULL: goto x86_l_21;
	case 0x39ULL: goto x86_l_39;
	case 0x58ULL: goto x86_l_58;
	case 0x69ULL: goto x86_l_69;
	case 0xa9ULL: goto x86_l_a9;
	case 0xc9ULL: goto x86_l_c9;
	case 0x121ULL: goto x86_l_121;
	case 0x14fULL: goto x86_l_14f;
	case 0x173ULL: goto x86_l_173;
	}

}

X86_SIM_LICENSE();
