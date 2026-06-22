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
	/* 0x0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2:
	/* 0x2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_6:
	/* 0x6: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_9:
	/* 0x9: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11:
	/* 0x11: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_16:
	/* 0x16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18:
	/* 0x18: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d:
	/* 0x1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22:
	/* 0x22: mov    rdi,QWORD PTR [rip+0xe7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_29:
	/* 0x29: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e:
	/* 0x2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30:
	/* 0x30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: je     18b <generic_sleepable_offload+0x18b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33, 0x18b, x86_l_18b);
x86_l_39:
	/* 0x39: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_41:
	/* 0x41: mov    rdi,QWORD PTR [rip+0xe7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_48:
	/* 0x48: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d:
	/* 0x4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f:
	/* 0x4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54:
	/* 0x54: mov    rdi,QWORD PTR [rip+0xe7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&regs_map)));
x86_l_5b:
	/* 0x5b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63:
	/* 0x63: je     18b <generic_sleepable_offload+0x18b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0x18b, x86_l_18b);
x86_l_69:
	/* 0x69: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_73:
	/* 0x73: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_76:
	/* 0x76: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_79:
	/* 0x79: jmp    c9 <generic_sleepable_offload+0xc9> */
	X86_SIM_X86_JMP(0x79, 0xc9, x86_l_c9);
x86_l_7b:
	/* 0x7b: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_81:
	/* 0x81: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_87:
	/* 0x87: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_8a:
	/* 0x8a: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_8c:
	/* 0x8c: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_8e:
	/* 0x8e: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_91:
	/* 0x91: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_94:
	/* 0x94: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_198, 0x99ULL);
x86_l_99:
	/* 0x99: add    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1:
	/* 0xa1: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_a7:
	/* 0xa7: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_ad:
	/* 0xad: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b0:
	/* 0xb0: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_b3:
	/* 0xb3: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_2ae, 0xb8ULL);
x86_l_b8:
	/* 0xb8: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_bb:
	/* 0xbb: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_bf:
	/* 0xbf: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_c3:
	/* 0xc3: je     18b <generic_sleepable_offload+0x18b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3, 0x18b, x86_l_18b);
x86_l_c9:
	/* 0xc9: mov    eax,DWORD PTR [r14+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_d0:
	/* 0xd0: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: jae    18b <generic_sleepable_offload+0x18b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xd3, 0x18b, x86_l_18b);
x86_l_d9:
	/* 0xd9: movzx  eax,BYTE PTR [r12-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_df:
	/* 0xdf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e2:
	/* 0xe2: jg     112 <generic_sleepable_offload+0x112> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe2, 0x112, x86_l_112);
x86_l_e4:
	/* 0xe4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7:
	/* 0xe7: je     173 <generic_sleepable_offload+0x173> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7, 0x173, x86_l_173);
x86_l_ed:
	/* 0xed: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f0:
	/* 0xf0: jne    b8 <generic_sleepable_offload+0xb8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf0, 0xb8, x86_l_b8);
x86_l_f2:
	/* 0xf2: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_f8:
	/* 0xf8: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_fe:
	/* 0xfe: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_101:
	/* 0x101: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_103:
	/* 0x103: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_105:
	/* 0x105: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_108:
	/* 0x108: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_198, 0x110ULL);
x86_l_110:
	/* 0x110: jmp    9d <generic_sleepable_offload+0x9d> */
	X86_SIM_X86_JMP(0x110, 0x9d, x86_l_9d);
x86_l_112:
	/* 0x112: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_115:
	/* 0x115: je     7b <generic_sleepable_offload+0x7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115, 0x7b, x86_l_7b);
x86_l_11b:
	/* 0x11b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e:
	/* 0x11e: jne    b8 <generic_sleepable_offload+0xb8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11e, 0xb8, x86_l_b8);
x86_l_120:
	/* 0x120: movzx  esi,WORD PTR [r12-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_126:
	/* 0x126: movzx  eax,BYTE PTR [r12-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_12c:
	/* 0x12c: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_12f:
	/* 0x12f: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_131:
	/* 0x131: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_133:
	/* 0x133: movzx  edx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_136:
	/* 0x136: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_139:
	/* 0x139: call   0 <generic_sleepable_offload> */
	X86_SIM_X86_CALL(x86_l_198, 0x13eULL);
x86_l_13e:
	/* 0x13e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142:
	/* 0x142: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_147:
	/* 0x147: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b:
	/* 0x14b: add    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_14f:
	/* 0x14f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_152:
	/* 0x152: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_157:
	/* 0x157: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159:
	/* 0x159: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15b:
	/* 0x15b: jne    b8 <generic_sleepable_offload+0xb8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15b, 0xb8, x86_l_b8);
x86_l_161:
	/* 0x161: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_167:
	/* 0x167: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_16d:
	/* 0x16d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_171:
	/* 0x171: jmp    183 <generic_sleepable_offload+0x183> */
	X86_SIM_X86_JMP(0x171, 0x183, x86_l_183);
x86_l_173:
	/* 0x173: movzx  esi,WORD PTR [r12-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_179:
	/* 0x179: movzx  edx,BYTE PTR [r12-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_17f:
	/* 0x17f: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183:
	/* 0x183: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_186:
	/* 0x186: jmp    b3 <generic_sleepable_offload+0xb3> */
	X86_SIM_X86_JMP(0x186, 0xb3, x86_l_b3);
x86_l_18b:
	/* 0x18b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18d:
	/* 0x18d: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_191:
	/* 0x191: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_193:
	/* 0x193: jmp    7ed <write_reg+0x53f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7ed:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_198 */
x86_l_198:
	/* 0x198: rorx   ecx,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_19e:
	/* 0x19e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0:
	/* 0x1a0: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1a3:
	/* 0x1a3: jle    1da <read_reg+0x42> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1a3, 0x1da, x86_l_1da);
x86_l_1a5:
	/* 0x1a5: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1a8:
	/* 0x1a8: jle    1fe <read_reg+0x66> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1a8, 0x1fe, x86_l_1fe);
x86_l_1aa:
	/* 0x1aa: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1ad:
	/* 0x1ad: jle    263 <read_reg+0xcb> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x1ad, 0x263, x86_l_263);
x86_l_1b3:
	/* 0x1b3: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1b6:
	/* 0x1b6: je     297 <read_reg+0xff> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b6, 0x297, x86_l_297);
x86_l_1bc:
	/* 0x1bc: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1bf:
	/* 0x1bf: je     27f <read_reg+0xe7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1bf, 0x27f, x86_l_27f);
x86_l_1c5:
	/* 0x1c5: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1c8:
	/* 0x1c8: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1c8, 0x2ad, x86_l_2ad);
x86_l_1ce:
	/* 0x1ce: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1d5:
	/* 0x1d5: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x1d5, 0x2a1, x86_l_2a1);
x86_l_1da:
	/* 0x1da: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1dd:
	/* 0x1dd: jg     21a <read_reg+0x82> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1dd, 0x21a, x86_l_21a);
x86_l_1df:
	/* 0x1df: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1e2:
	/* 0x1e2: jg     243 <read_reg+0xab> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1e2, 0x243, x86_l_243);
x86_l_1e4:
	/* 0x1e4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1e6:
	/* 0x1e6: je     2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1e6, 0x2a1, x86_l_2a1);
x86_l_1ec:
	/* 0x1ec: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ef:
	/* 0x1ef: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1ef, 0x2ad, x86_l_2ad);
x86_l_1f5:
	/* 0x1f5: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f9:
	/* 0x1f9: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x1f9, 0x2a1, x86_l_2a1);
x86_l_1fe:
	/* 0x1fe: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_201:
	/* 0x201: jg     233 <read_reg+0x9b> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x201, 0x233, x86_l_233);
x86_l_203:
	/* 0x203: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_206:
	/* 0x206: je     273 <read_reg+0xdb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x206, 0x273, x86_l_273);
x86_l_208:
	/* 0x208: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_20b:
	/* 0x20b: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x20b, 0x2ad, x86_l_2ad);
x86_l_211:
	/* 0x211: add    rdi,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_215:
	/* 0x215: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x215, 0x2a1, x86_l_2a1);
x86_l_21a:
	/* 0x21a: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_21d:
	/* 0x21d: jg     253 <read_reg+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x21d, 0x253, x86_l_253);
x86_l_21f:
	/* 0x21f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_222:
	/* 0x222: je     285 <read_reg+0xed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x222, 0x285, x86_l_285);
x86_l_224:
	/* 0x224: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_227:
	/* 0x227: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x227, 0x2ad, x86_l_2ad);
x86_l_22d:
	/* 0x22d: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_231:
	/* 0x231: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x231, 0x2a1, x86_l_2a1);
x86_l_233:
	/* 0x233: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_236:
	/* 0x236: je     279 <read_reg+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x236, 0x279, x86_l_279);
x86_l_238:
	/* 0x238: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_23b:
	/* 0x23b: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x23b, 0x2ad, x86_l_2ad);
x86_l_23d:
	/* 0x23d: add    rdi,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_241:
	/* 0x241: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x241, 0x2a1, x86_l_2a1);
x86_l_243:
	/* 0x243: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_246:
	/* 0x246: je     28b <read_reg+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x246, 0x28b, x86_l_28b);
x86_l_248:
	/* 0x248: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_24b:
	/* 0x24b: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x24b, 0x2ad, x86_l_2ad);
x86_l_24d:
	/* 0x24d: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_251:
	/* 0x251: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x251, 0x2a1, x86_l_2a1);
x86_l_253:
	/* 0x253: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_256:
	/* 0x256: je     291 <read_reg+0xf9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x256, 0x291, x86_l_291);
x86_l_258:
	/* 0x258: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_25b:
	/* 0x25b: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x25b, 0x2ad, x86_l_2ad);
x86_l_25d:
	/* 0x25d: add    rdi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_261:
	/* 0x261: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x261, 0x2a1, x86_l_2a1);
x86_l_263:
	/* 0x263: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_266:
	/* 0x266: je     29d <read_reg+0x105> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x266, 0x29d, x86_l_29d);
x86_l_268:
	/* 0x268: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_26b:
	/* 0x26b: jne    2ad <read_reg+0x115> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x26b, 0x2ad, x86_l_2ad);
x86_l_26d:
	/* 0x26d: add    rdi,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_271:
	/* 0x271: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x271, 0x2a1, x86_l_2a1);
x86_l_273:
	/* 0x273: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_277:
	/* 0x277: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x277, 0x2a1, x86_l_2a1);
x86_l_279:
	/* 0x279: add    rdi,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_27d:
	/* 0x27d: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x27d, 0x2a1, x86_l_2a1);
x86_l_27f:
	/* 0x27f: sub    rdi,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_283:
	/* 0x283: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x283, 0x2a1, x86_l_2a1);
x86_l_285:
	/* 0x285: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_289:
	/* 0x289: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x289, 0x2a1, x86_l_2a1);
x86_l_28b:
	/* 0x28b: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28f:
	/* 0x28f: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x28f, 0x2a1, x86_l_2a1);
x86_l_291:
	/* 0x291: add    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_295:
	/* 0x295: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x295, 0x2a1, x86_l_2a1);
x86_l_297:
	/* 0x297: add    rdi,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_29b:
	/* 0x29b: jmp    2a1 <read_reg+0x109> */
	X86_SIM_X86_SUB_JMP(0x29b, 0x2a1, x86_l_2a1);
x86_l_29d:
	/* 0x29d: add    rdi,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2a6:
	/* 0x2a6: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a8:
	/* 0x2a8: bzhi   rax,QWORD PTR [rdi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2ad:
	/* 0x2ad: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_2ae */
x86_l_2ae:
	/* 0x2ae: rorx   eax,esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 3ULL);
x86_l_2b4:
	/* 0x2b4: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2b7:
	/* 0x2b7: jle    30c <write_reg+0x5e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2b7, 0x30c, x86_l_30c);
x86_l_2b9:
	/* 0x2b9: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2bc:
	/* 0x2bc: jle    34e <write_reg+0xa0> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2bc, 0x34e, x86_l_34e);
x86_l_2c2:
	/* 0x2c2: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_2c5:
	/* 0x2c5: jle    465 <write_reg+0x1b7> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2c5, 0x465, x86_l_465);
x86_l_2cb:
	/* 0x2cb: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ce:
	/* 0x2ce: je     591 <write_reg+0x2e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2ce, 0x591, x86_l_591);
x86_l_2d4:
	/* 0x2d4: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2d7:
	/* 0x2d7: je     4e0 <write_reg+0x232> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d7, 0x4e0, x86_l_4e0);
x86_l_2dd:
	/* 0x2dd: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_2e0:
	/* 0x2e0: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2e0, 0x7bd, x86_l_7bd);
x86_l_2e6:
	/* 0x2e6: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e9:
	/* 0x2e9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ec:
	/* 0x2ec: jg     6d6 <write_reg+0x428> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2ec, 0x6d6, x86_l_6d6);
x86_l_2f2:
	/* 0x2f2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5:
	/* 0x2f5: je     7b7 <write_reg+0x509> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2f5, 0x7b7, x86_l_7b7);
x86_l_2fb:
	/* 0x2fb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fe:
	/* 0x2fe: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2fe, 0x7bd, x86_l_7bd);
x86_l_304:
	/* 0x304: mov    WORD PTR [rdi+0x98],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_30b:
	/* 0x30b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_30c:
	/* 0x30c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_30f:
	/* 0x30f: jg     388 <write_reg+0xda> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x30f, 0x388, x86_l_388);
x86_l_311:
	/* 0x311: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314:
	/* 0x314: jg     3fb <write_reg+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x314, 0x3fb, x86_l_3fb);
x86_l_31a:
	/* 0x31a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31c:
	/* 0x31c: je     506 <write_reg+0x258> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x31c, 0x506, x86_l_506);
x86_l_322:
	/* 0x322: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_325:
	/* 0x325: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x325, 0x7bd, x86_l_7bd);
x86_l_32b:
	/* 0x32b: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32e:
	/* 0x32e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_331:
	/* 0x331: jg     6f0 <write_reg+0x442> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x331, 0x6f0, x86_l_6f0);
x86_l_337:
	/* 0x337: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33a:
	/* 0x33a: je     7c5 <write_reg+0x517> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x33a, 0x7c5, x86_l_7c5);
x86_l_340:
	/* 0x340: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_343:
	/* 0x343: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x343, 0x7bd, x86_l_7bd);
x86_l_349:
	/* 0x349: mov    WORD PTR [rdi+0x8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d:
	/* 0x34d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_34e:
	/* 0x34e: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_351:
	/* 0x351: jg     3c6 <write_reg+0x118> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x351, 0x3c6, x86_l_3c6);
x86_l_353:
	/* 0x353: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_356:
	/* 0x356: je     49a <write_reg+0x1ec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x356, 0x49a, x86_l_49a);
x86_l_35c:
	/* 0x35c: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_35f:
	/* 0x35f: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x35f, 0x7bd, x86_l_7bd);
x86_l_365:
	/* 0x365: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_368:
	/* 0x368: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_36b:
	/* 0x36b: jg     605 <write_reg+0x357> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x36b, 0x605, x86_l_605);
x86_l_371:
	/* 0x371: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_374:
	/* 0x374: je     76b <write_reg+0x4bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x374, 0x76b, x86_l_76b);
x86_l_37a:
	/* 0x37a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37d:
	/* 0x37d: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x37d, 0x7bd, x86_l_7bd);
x86_l_383:
	/* 0x383: mov    WORD PTR [rdi+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_387:
	/* 0x387: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_388:
	/* 0x388: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_38b:
	/* 0x38b: jg     430 <write_reg+0x182> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x38b, 0x430, x86_l_430);
x86_l_391:
	/* 0x391: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_394:
	/* 0x394: je     528 <write_reg+0x27a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x394, 0x528, x86_l_528);
x86_l_39a:
	/* 0x39a: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_39d:
	/* 0x39d: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x39d, 0x7bd, x86_l_7bd);
x86_l_3a3:
	/* 0x3a3: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3a6:
	/* 0x3a6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3a9:
	/* 0x3a9: jg     707 <write_reg+0x459> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3a9, 0x707, x86_l_707);
x86_l_3af:
	/* 0x3af: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b2:
	/* 0x3b2: je     7c9 <write_reg+0x51b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3b2, 0x7c9, x86_l_7c9);
x86_l_3b8:
	/* 0x3b8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3bb:
	/* 0x3bb: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3bb, 0x7bd, x86_l_7bd);
x86_l_3c1:
	/* 0x3c1: mov    WORD PTR [rdi+0x28],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c5:
	/* 0x3c5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3c6:
	/* 0x3c6: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_3c9:
	/* 0x3c9: je     4bd <write_reg+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3c9, 0x4bd, x86_l_4bd);
x86_l_3cf:
	/* 0x3cf: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3d2:
	/* 0x3d2: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3d2, 0x7bd, x86_l_7bd);
x86_l_3d8:
	/* 0x3d8: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3db:
	/* 0x3db: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3de:
	/* 0x3de: jg     61c <write_reg+0x36e> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3de, 0x61c, x86_l_61c);
x86_l_3e4:
	/* 0x3e4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e7:
	/* 0x3e7: je     76f <write_reg+0x4c1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3e7, 0x76f, x86_l_76f);
x86_l_3ed:
	/* 0x3ed: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3f0:
	/* 0x3f0: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3f0, 0x7bd, x86_l_7bd);
x86_l_3f6:
	/* 0x3f6: mov    WORD PTR [rdi+0x58],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3fa:
	/* 0x3fa: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3fb:
	/* 0x3fb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3fe:
	/* 0x3fe: je     54b <write_reg+0x29d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3fe, 0x54b, x86_l_54b);
x86_l_404:
	/* 0x404: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_407:
	/* 0x407: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x407, 0x7bd, x86_l_7bd);
x86_l_40d:
	/* 0x40d: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_410:
	/* 0x410: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_413:
	/* 0x413: jg     71e <write_reg+0x470> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x413, 0x71e, x86_l_71e);
x86_l_419:
	/* 0x419: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41c:
	/* 0x41c: je     7cd <write_reg+0x51f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x41c, 0x7cd, x86_l_7cd);
x86_l_422:
	/* 0x422: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_425:
	/* 0x425: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x425, 0x7bd, x86_l_7bd);
x86_l_42b:
	/* 0x42b: mov    WORD PTR [rdi+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42f:
	/* 0x42f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_430:
	/* 0x430: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_433:
	/* 0x433: je     56e <write_reg+0x2c0> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x433, 0x56e, x86_l_56e);
x86_l_439:
	/* 0x439: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_43c:
	/* 0x43c: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x43c, 0x7bd, x86_l_7bd);
x86_l_442:
	/* 0x442: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_445:
	/* 0x445: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_448:
	/* 0x448: jg     735 <write_reg+0x487> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x448, 0x735, x86_l_735);
x86_l_44e:
	/* 0x44e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_451:
	/* 0x451: je     7d1 <write_reg+0x523> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x451, 0x7d1, x86_l_7d1);
x86_l_457:
	/* 0x457: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_45a:
	/* 0x45a: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x45a, 0x7bd, x86_l_7bd);
x86_l_460:
	/* 0x460: mov    WORD PTR [rdi+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_464:
	/* 0x464: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_465:
	/* 0x465: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_468:
	/* 0x468: je     5b4 <write_reg+0x306> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x468, 0x5b4, x86_l_5b4);
x86_l_46e:
	/* 0x46e: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_471:
	/* 0x471: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x471, 0x7bd, x86_l_7bd);
x86_l_477:
	/* 0x477: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_47a:
	/* 0x47a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_47d:
	/* 0x47d: jg     748 <write_reg+0x49a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x47d, 0x748, x86_l_748);
x86_l_483:
	/* 0x483: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_486:
	/* 0x486: je     7e5 <write_reg+0x537> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x486, 0x7e5, x86_l_7e5);
x86_l_48c:
	/* 0x48c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_48f:
	/* 0x48f: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x48f, 0x7bd, x86_l_7bd);
x86_l_495:
	/* 0x495: mov    WORD PTR [rdi+0x68],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_499:
	/* 0x499: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_49a:
	/* 0x49a: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_49d:
	/* 0x49d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4a0:
	/* 0x4a0: jg     5d7 <write_reg+0x329> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4a0, 0x5d7, x86_l_5d7);
x86_l_4a6:
	/* 0x4a6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a9:
	/* 0x4a9: je     75b <write_reg+0x4ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4a9, 0x75b, x86_l_75b);
x86_l_4af:
	/* 0x4af: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4b2:
	/* 0x4b2: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4b2, 0x7bd, x86_l_7bd);
x86_l_4b8:
	/* 0x4b8: mov    WORD PTR [rdi+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
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
	/* 0x4c3: jg     5ee <write_reg+0x340> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4c3, 0x5ee, x86_l_5ee);
x86_l_4c9:
	/* 0x4c9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4cc:
	/* 0x4cc: je     75f <write_reg+0x4b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4cc, 0x75f, x86_l_75f);
x86_l_4d2:
	/* 0x4d2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4d5:
	/* 0x4d5: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4d5, 0x7bd, x86_l_7bd);
x86_l_4db:
	/* 0x4db: mov    WORD PTR [rdi+0x50],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
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
	/* 0x4e6: jg     633 <write_reg+0x385> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x4e6, 0x633, x86_l_633);
x86_l_4ec:
	/* 0x4ec: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ef:
	/* 0x4ef: je     77b <write_reg+0x4cd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ef, 0x77b, x86_l_77b);
x86_l_4f5:
	/* 0x4f5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4f8:
	/* 0x4f8: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4f8, 0x7bd, x86_l_7bd);
x86_l_4fe:
	/* 0x4fe: mov    WORD PTR [rdi+0x80],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_505:
	/* 0x505: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_506:
	/* 0x506: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_509:
	/* 0x509: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_50c:
	/* 0x50c: jg     64d <write_reg+0x39f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x50c, 0x64d, x86_l_64d);
x86_l_512:
	/* 0x512: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_515:
	/* 0x515: je     789 <write_reg+0x4db> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x515, 0x789, x86_l_789);
x86_l_51b:
	/* 0x51b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_51e:
	/* 0x51e: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x51e, 0x7bd, x86_l_7bd);
x86_l_524:
	/* 0x524: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_527:
	/* 0x527: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_528:
	/* 0x528: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_52b:
	/* 0x52b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_52e:
	/* 0x52e: jg     663 <write_reg+0x3b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x52e, 0x663, x86_l_663);
x86_l_534:
	/* 0x534: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_537:
	/* 0x537: je     78c <write_reg+0x4de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x537, 0x78c, x86_l_78c);
x86_l_53d:
	/* 0x53d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_540:
	/* 0x540: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x540, 0x7bd, x86_l_7bd);
x86_l_546:
	/* 0x546: mov    WORD PTR [rdi+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x551: jg     67a <write_reg+0x3cc> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x551, 0x67a, x86_l_67a);
x86_l_557:
	/* 0x557: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55a:
	/* 0x55a: je     790 <write_reg+0x4e2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x55a, 0x790, x86_l_790);
x86_l_560:
	/* 0x560: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_563:
	/* 0x563: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x563, 0x7bd, x86_l_7bd);
x86_l_569:
	/* 0x569: mov    WORD PTR [rdi+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x574: jg     691 <write_reg+0x3e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x574, 0x691, x86_l_691);
x86_l_57a:
	/* 0x57a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57d:
	/* 0x57d: je     794 <write_reg+0x4e6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x57d, 0x794, x86_l_794);
x86_l_583:
	/* 0x583: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_586:
	/* 0x586: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x586, 0x7bd, x86_l_7bd);
x86_l_58c:
	/* 0x58c: mov    WORD PTR [rdi+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x597: jg     6a8 <write_reg+0x3fa> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x597, 0x6a8, x86_l_6a8);
x86_l_59d:
	/* 0x59d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a0:
	/* 0x5a0: je     7a7 <write_reg+0x4f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5a0, 0x7a7, x86_l_7a7);
x86_l_5a6:
	/* 0x5a6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5a9:
	/* 0x5a9: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5a9, 0x7bd, x86_l_7bd);
x86_l_5af:
	/* 0x5af: mov    WORD PTR [rdi+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
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
	/* 0x5ba: jg     6bf <write_reg+0x411> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x5ba, 0x6bf, x86_l_6bf);
x86_l_5c0:
	/* 0x5c0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c3:
	/* 0x5c3: je     7af <write_reg+0x501> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5c3, 0x7af, x86_l_7af);
x86_l_5c9:
	/* 0x5c9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5cc:
	/* 0x5cc: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5cc, 0x7bd, x86_l_7bd);
x86_l_5d2:
	/* 0x5d2: mov    WORD PTR [rdi+0x60],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5d6:
	/* 0x5d6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5d7:
	/* 0x5d7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5da:
	/* 0x5da: je     763 <write_reg+0x4b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5da, 0x763, x86_l_763);
x86_l_5e0:
	/* 0x5e0: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5e3:
	/* 0x5e3: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5e3, 0x7bd, x86_l_7bd);
x86_l_5e9:
	/* 0x5e9: mov    QWORD PTR [rdi+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ed:
	/* 0x5ed: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_5ee:
	/* 0x5ee: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5f1:
	/* 0x5f1: je     767 <write_reg+0x4b9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5f1, 0x767, x86_l_767);
x86_l_5f7:
	/* 0x5f7: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5fa:
	/* 0x5fa: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5fa, 0x7bd, x86_l_7bd);
x86_l_600:
	/* 0x600: mov    QWORD PTR [rdi+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_604:
	/* 0x604: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_605:
	/* 0x605: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_608:
	/* 0x608: je     773 <write_reg+0x4c5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x608, 0x773, x86_l_773);
x86_l_60e:
	/* 0x60e: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_611:
	/* 0x611: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x611, 0x7bd, x86_l_7bd);
x86_l_617:
	/* 0x617: mov    QWORD PTR [rdi+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_61b:
	/* 0x61b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_61c:
	/* 0x61c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_61f:
	/* 0x61f: je     777 <write_reg+0x4c9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x61f, 0x777, x86_l_777);
x86_l_625:
	/* 0x625: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_628:
	/* 0x628: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x628, 0x7bd, x86_l_7bd);
x86_l_62e:
	/* 0x62e: mov    QWORD PTR [rdi+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_632:
	/* 0x632: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_633:
	/* 0x633: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_636:
	/* 0x636: je     782 <write_reg+0x4d4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x636, 0x782, x86_l_782);
x86_l_63c:
	/* 0x63c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_63f:
	/* 0x63f: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x63f, 0x7bd, x86_l_7bd);
x86_l_645:
	/* 0x645: mov    QWORD PTR [rdi+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_64c:
	/* 0x64c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_64d:
	/* 0x64d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_650:
	/* 0x650: je     798 <write_reg+0x4ea> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x650, 0x798, x86_l_798);
x86_l_656:
	/* 0x656: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_659:
	/* 0x659: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x659, 0x7bd, x86_l_7bd);
x86_l_65f:
	/* 0x65f: mov    QWORD PTR [rdi],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_662:
	/* 0x662: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_663:
	/* 0x663: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_666:
	/* 0x666: je     79b <write_reg+0x4ed> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x666, 0x79b, x86_l_79b);
x86_l_66c:
	/* 0x66c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_66f:
	/* 0x66f: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x66f, 0x7bd, x86_l_7bd);
x86_l_675:
	/* 0x675: mov    QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_679:
	/* 0x679: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_67a:
	/* 0x67a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_67d:
	/* 0x67d: je     79f <write_reg+0x4f1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x67d, 0x79f, x86_l_79f);
x86_l_683:
	/* 0x683: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_686:
	/* 0x686: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x686, 0x7bd, x86_l_7bd);
x86_l_68c:
	/* 0x68c: mov    QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_690:
	/* 0x690: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_691:
	/* 0x691: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_694:
	/* 0x694: je     7a3 <write_reg+0x4f5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x694, 0x7a3, x86_l_7a3);
x86_l_69a:
	/* 0x69a: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_69d:
	/* 0x69d: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x69d, 0x7bd, x86_l_7bd);
x86_l_6a3:
	/* 0x6a3: mov    QWORD PTR [rdi+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a7:
	/* 0x6a7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6a8:
	/* 0x6a8: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ab:
	/* 0x6ab: je     7ab <write_reg+0x4fd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6ab, 0x7ab, x86_l_7ab);
x86_l_6b1:
	/* 0x6b1: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6b4:
	/* 0x6b4: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6b4, 0x7bd, x86_l_7bd);
x86_l_6ba:
	/* 0x6ba: mov    QWORD PTR [rdi+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6be:
	/* 0x6be: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6bf:
	/* 0x6bf: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6c2:
	/* 0x6c2: je     7b3 <write_reg+0x505> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6c2, 0x7b3, x86_l_7b3);
x86_l_6c8:
	/* 0x6c8: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6cb:
	/* 0x6cb: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6cb, 0x7bd, x86_l_7bd);
x86_l_6d1:
	/* 0x6d1: mov    QWORD PTR [rdi+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6d5:
	/* 0x6d5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6d6:
	/* 0x6d6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6d9:
	/* 0x6d9: je     7be <write_reg+0x510> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6d9, 0x7be, x86_l_7be);
x86_l_6df:
	/* 0x6df: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6e2:
	/* 0x6e2: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6e2, 0x7bd, x86_l_7bd);
x86_l_6e8:
	/* 0x6e8: mov    QWORD PTR [rdi+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6ef:
	/* 0x6ef: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_6f0:
	/* 0x6f0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f3:
	/* 0x6f3: je     7d5 <write_reg+0x527> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6f3, 0x7d5, x86_l_7d5);
x86_l_6f9:
	/* 0x6f9: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6fc:
	/* 0x6fc: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6fc, 0x7bd, x86_l_7bd);
x86_l_702:
	/* 0x702: mov    QWORD PTR [rdi+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_706:
	/* 0x706: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_707:
	/* 0x707: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_70a:
	/* 0x70a: je     7d9 <write_reg+0x52b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x70a, 0x7d9, x86_l_7d9);
x86_l_710:
	/* 0x710: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_713:
	/* 0x713: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x713, 0x7bd, x86_l_7bd);
x86_l_719:
	/* 0x719: mov    QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_71d:
	/* 0x71d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_71e:
	/* 0x71e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_721:
	/* 0x721: je     7dd <write_reg+0x52f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x721, 0x7dd, x86_l_7dd);
x86_l_727:
	/* 0x727: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_72a:
	/* 0x72a: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x72a, 0x7bd, x86_l_7bd);
x86_l_730:
	/* 0x730: mov    QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_734:
	/* 0x734: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_735:
	/* 0x735: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_738:
	/* 0x738: je     7e1 <write_reg+0x533> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x738, 0x7e1, x86_l_7e1);
x86_l_73e:
	/* 0x73e: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_741:
	/* 0x741: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x741, 0x7bd, x86_l_7bd);
x86_l_743:
	/* 0x743: mov    QWORD PTR [rdi+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_747:
	/* 0x747: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_748:
	/* 0x748: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_74b:
	/* 0x74b: je     7e9 <write_reg+0x53b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x74b, 0x7e9, x86_l_7e9);
x86_l_751:
	/* 0x751: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_754:
	/* 0x754: jne    7bd <write_reg+0x50f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x754, 0x7bd, x86_l_7bd);
x86_l_756:
	/* 0x756: mov    QWORD PTR [rdi+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_75a:
	/* 0x75a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_75b:
	/* 0x75b: mov    BYTE PTR [rdi+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_75e:
	/* 0x75e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_75f:
	/* 0x75f: mov    BYTE PTR [rdi+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_762:
	/* 0x762: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_763:
	/* 0x763: mov    DWORD PTR [rdi+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_766:
	/* 0x766: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_767:
	/* 0x767: mov    DWORD PTR [rdi+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_76a:
	/* 0x76a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_76b:
	/* 0x76b: mov    BYTE PTR [rdi+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_76e:
	/* 0x76e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_76f:
	/* 0x76f: mov    BYTE PTR [rdi+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_772:
	/* 0x772: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_773:
	/* 0x773: mov    DWORD PTR [rdi+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_776:
	/* 0x776: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_777:
	/* 0x777: mov    DWORD PTR [rdi+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_77a:
	/* 0x77a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_77b:
	/* 0x77b: mov    BYTE PTR [rdi+0x80],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_781:
	/* 0x781: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_782:
	/* 0x782: mov    DWORD PTR [rdi+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_788:
	/* 0x788: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_789:
	/* 0x789: mov    BYTE PTR [rdi],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78b:
	/* 0x78b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_78c:
	/* 0x78c: mov    BYTE PTR [rdi+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_78f:
	/* 0x78f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_790:
	/* 0x790: mov    BYTE PTR [rdi+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_793:
	/* 0x793: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_794:
	/* 0x794: mov    BYTE PTR [rdi+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_797:
	/* 0x797: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_798:
	/* 0x798: mov    DWORD PTR [rdi],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79a:
	/* 0x79a: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_79b:
	/* 0x79b: mov    DWORD PTR [rdi+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_79e:
	/* 0x79e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_79f:
	/* 0x79f: mov    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a2:
	/* 0x7a2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7a3:
	/* 0x7a3: mov    DWORD PTR [rdi+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a6:
	/* 0x7a6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7a7:
	/* 0x7a7: mov    BYTE PTR [rdi+0x70],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7aa:
	/* 0x7aa: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7ab:
	/* 0x7ab: mov    DWORD PTR [rdi+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7ae:
	/* 0x7ae: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7af:
	/* 0x7af: mov    BYTE PTR [rdi+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7b2:
	/* 0x7b2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b3:
	/* 0x7b3: mov    DWORD PTR [rdi+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7b6:
	/* 0x7b6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7b7:
	/* 0x7b7: mov    BYTE PTR [rdi+0x98],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7bd:
	/* 0x7bd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7be:
	/* 0x7be: mov    DWORD PTR [rdi+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7c4:
	/* 0x7c4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c5:
	/* 0x7c5: mov    BYTE PTR [rdi+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c8:
	/* 0x7c8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7c9:
	/* 0x7c9: mov    BYTE PTR [rdi+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7cc:
	/* 0x7cc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7cd:
	/* 0x7cd: mov    BYTE PTR [rdi+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7d0:
	/* 0x7d0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d1:
	/* 0x7d1: mov    BYTE PTR [rdi+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7d4:
	/* 0x7d4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d5:
	/* 0x7d5: mov    DWORD PTR [rdi+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d8:
	/* 0x7d8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d9:
	/* 0x7d9: mov    DWORD PTR [rdi+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7dc:
	/* 0x7dc: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7dd:
	/* 0x7dd: mov    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7e0:
	/* 0x7e0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e1:
	/* 0x7e1: mov    DWORD PTR [rdi+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e4:
	/* 0x7e4: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e5:
	/* 0x7e5: mov    BYTE PTR [rdi+0x68],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7e8:
	/* 0x7e8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7e9:
	/* 0x7e9: mov    DWORD PTR [rdi+0x68],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7ec:
	/* 0x7ec: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x18ULL: goto x86_l_18;
	case 0x30ULL: goto x86_l_30;
	case 0x4fULL: goto x86_l_4f;
	case 0x60ULL: goto x86_l_60;
	case 0x99ULL: goto x86_l_99;
	case 0xb8ULL: goto x86_l_b8;
	case 0x110ULL: goto x86_l_110;
	case 0x13eULL: goto x86_l_13e;
	case 0x159ULL: goto x86_l_159;
	}

}

X86_SIM_LICENSE();
