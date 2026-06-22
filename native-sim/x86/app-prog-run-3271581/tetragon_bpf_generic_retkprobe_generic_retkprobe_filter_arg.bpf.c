extern char argfilter_maps;
extern char filter_map;
extern char process_call_heap;
extern char retkprobe_calls;
extern char retprobe_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_25:
	/* 0x25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a:
	/* 0x2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c:
	/* 0x2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: je     506 <generic_retkprobe_filter_arg+0x506> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f, 0x506, x86_l_506);
x86_l_35:
	/* 0x35: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: mov    r15d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3f:
	/* 0x3f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_42:
	/* 0x42: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_49:
	/* 0x49: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_50:
	/* 0x50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55:
	/* 0x55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57:
	/* 0x57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a:
	/* 0x5a: je     4eb <generic_retkprobe_filter_arg+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a, 0x4eb, x86_l_4eb);
x86_l_60:
	/* 0x60: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_68:
	/* 0x68: je     4eb <generic_retkprobe_filter_arg+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0x4eb, x86_l_4eb);
x86_l_6e:
	/* 0x6e: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_71:
	/* 0x71: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_74:
	/* 0x74: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_7d:
	/* 0x7d: je     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d, 0x474, x86_l_474);
x86_l_83:
	/* 0x83: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_89:
	/* 0x89: lea    r13,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8d:
	/* 0x8d: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_91:
	/* 0x91: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_94:
	/* 0x94: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9b:
	/* 0x9b: cmp    DWORD PTR [rax+r12*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 25ULL);
x86_l_a0:
	/* 0xa0: jb     465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa0, 0x465, x86_l_465);
x86_l_a6:
	/* 0xa6: mov    ecx,DWORD PTR [rax+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_ab:
	/* 0xab: test   ecx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1023ULL);
x86_l_b1:
	/* 0xb1: je     465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1, 0x465, x86_l_465);
x86_l_b7:
	/* 0xb7: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ba:
	/* 0xba: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c1:
	/* 0xc1: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_c6:
	/* 0xc6: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_ca:
	/* 0xca: ja     1c5 <generic_retkprobe_filter_arg+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xca, 0x1c5, x86_l_1c5);
x86_l_d0:
	/* 0xd0: movabs rdx,0x1e10003c12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117469714ULL);
x86_l_da:
	/* 0xda: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: jae    1c5 <generic_retkprobe_filter_arg+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xde, 0x1c5, x86_l_1c5);
x86_l_e4:
	/* 0xe4: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_e8:
	/* 0xe8: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_ec:
	/* 0xec: ja     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_A, 0xec, 0x474, x86_l_474);
x86_l_f2:
	/* 0xf2: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_fb:
	/* 0xfb: jne    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb, 0x474, x86_l_474);
x86_l_101:
	/* 0x101: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_106:
	/* 0x106: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_10a:
	/* 0x10a: ja     465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_A, 0x10a, 0x465, x86_l_465);
x86_l_110:
	/* 0x110: mov    rbp,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_118:
	/* 0x118: movabs rdx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117457408ULL);
x86_l_122:
	/* 0x122: and    ebp,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_128:
	/* 0x128: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: jae    1f9 <generic_retkprobe_filter_arg+0x1f9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x12c, 0x1f9, x86_l_1f9);
x86_l_132:
	/* 0x132: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_137:
	/* 0x137: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_13a:
	/* 0x13a: ja     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13a, 0x474, x86_l_474);
x86_l_140:
	/* 0x140: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_145:
	/* 0x145: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_148:
	/* 0x148: jae    29b <generic_retkprobe_filter_arg+0x29b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x148, 0x29b, x86_l_29b);
x86_l_14e:
	/* 0x14e: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_151:
	/* 0x151: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_154:
	/* 0x154: jb     31a <generic_retkprobe_filter_arg+0x31a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x154, 0x31a, x86_l_31a);
x86_l_15a:
	/* 0x15a: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_15d:
	/* 0x15d: je     465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d, 0x465, x86_l_465);
x86_l_163:
	/* 0x163: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_166:
	/* 0x166: jne    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x166, 0x474, x86_l_474);
x86_l_16c:
	/* 0x16c: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_174:
	/* 0x174: test   QWORD PTR [rax+r13*1+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_179:
	/* 0x179: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x179, 0x465, x86_l_465);
x86_l_17f:
	/* 0x17f: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_184:
	/* 0x184: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_187:
	/* 0x187: jb     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_B, 0x187, 0x474, x86_l_474);
x86_l_18d:
	/* 0x18d: test   QWORD PTR [rax+r13*1+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_192:
	/* 0x192: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x192, 0x465, x86_l_465);
x86_l_198:
	/* 0x198: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_19b:
	/* 0x19b: jb     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19b, 0x474, x86_l_474);
x86_l_1a1:
	/* 0x1a1: test   QWORD PTR [rax+r13*1+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 32ULL);
x86_l_1a6:
	/* 0x1a6: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a6, 0x465, x86_l_465);
x86_l_1ac:
	/* 0x1ac: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1af:
	/* 0x1af: jb     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1af, 0x474, x86_l_474);
x86_l_1b5:
	/* 0x1b5: test   QWORD PTR [rax+r13*1+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 40ULL);
x86_l_1ba:
	/* 0x1ba: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ba, 0x465, x86_l_465);
x86_l_1c0:
	/* 0x1c0: jmp    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JMP(0x1c0, 0x474, x86_l_474);
x86_l_1c5:
	/* 0x1c5: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_1cc:
	/* 0x1cc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d1:
	/* 0x1d1: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1d4:
	/* 0x1d4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d9:
	/* 0x1d9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dc:
	/* 0x1dc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e1:
	/* 0x1e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3:
	/* 0x1e3: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1e6:
	/* 0x1e6: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1ea:
	/* 0x1ea: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_1ee:
	/* 0x1ee: jbe    f2 <generic_retkprobe_filter_arg+0xf2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1ee, 0xf2, x86_l_f2);
x86_l_1f4:
	/* 0x1f4: jmp    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JMP(0x1f4, 0x474, x86_l_474);
x86_l_1f9:
	/* 0x1f9: mov    edx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12306ULL);
x86_l_1fe:
	/* 0x1fe: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_202:
	/* 0x202: jae    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x202, 0x465, x86_l_465);
x86_l_208:
	/* 0x208: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_20d:
	/* 0x20d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_210:
	/* 0x210: ja     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_A, 0x210, 0x474, x86_l_474);
x86_l_216:
	/* 0x216: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_21b:
	/* 0x21b: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_21e:
	/* 0x21e: jae    373 <generic_retkprobe_filter_arg+0x373> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x21e, 0x373, x86_l_373);
x86_l_224:
	/* 0x224: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_227:
	/* 0x227: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_22a:
	/* 0x22a: jb     3ef <generic_retkprobe_filter_arg+0x3ef> */
	X86_SIM_X86_JCC(X86_CC_B, 0x22a, 0x3ef, x86_l_3ef);
x86_l_230:
	/* 0x230: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_233:
	/* 0x233: je     465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_E, 0x233, 0x465, x86_l_465);
x86_l_239:
	/* 0x239: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_23c:
	/* 0x23c: jne    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23c, 0x474, x86_l_474);
x86_l_242:
	/* 0x242: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_24a:
	/* 0x24a: test   DWORD PTR [rax+r13*1+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_24f:
	/* 0x24f: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24f, 0x465, x86_l_465);
x86_l_255:
	/* 0x255: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_25a:
	/* 0x25a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_25d:
	/* 0x25d: jb     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_B, 0x25d, 0x474, x86_l_474);
x86_l_263:
	/* 0x263: test   DWORD PTR [rax+r13*1+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 20ULL);
x86_l_268:
	/* 0x268: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x268, 0x465, x86_l_465);
x86_l_26e:
	/* 0x26e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_271:
	/* 0x271: jb     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_B, 0x271, 0x474, x86_l_474);
x86_l_277:
	/* 0x277: test   DWORD PTR [rax+r13*1+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_27c:
	/* 0x27c: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x27c, 0x465, x86_l_465);
x86_l_282:
	/* 0x282: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_285:
	/* 0x285: jb     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_B, 0x285, 0x474, x86_l_474);
x86_l_28b:
	/* 0x28b: test   DWORD PTR [rax+r13*1+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 28ULL);
x86_l_290:
	/* 0x290: jne    465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x290, 0x465, x86_l_465);
x86_l_296:
	/* 0x296: jmp    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JMP(0x296, 0x474, x86_l_474);
x86_l_29b:
	/* 0x29b: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_2a0:
	/* 0x2a0: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2a3:
	/* 0x2a3: jae    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2a3, 0x474, x86_l_474);
x86_l_2a9:
	/* 0x2a9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae:
	/* 0x2ae: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_2b4:
	/* 0x2b4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b8:
	/* 0x2b8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2bf:
	/* 0x2bf: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c4:
	/* 0x2c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c9:
	/* 0x2c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb:
	/* 0x2cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce:
	/* 0x2ce: je     3eb <generic_retkprobe_filter_arg+0x3eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ce, 0x3eb, x86_l_3eb);
x86_l_2d4:
	/* 0x2d4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: mov    rax,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_2df:
	/* 0x2df: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e4:
	/* 0x2e4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9:
	/* 0x2e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ee:
	/* 0x2ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0:
	/* 0x2f0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f5:
	/* 0x2f5: mov    ecx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_2fa:
	/* 0x2fa: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2fd:
	/* 0x2fd: je     43b <generic_retkprobe_filter_arg+0x43b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2fd, 0x43b, x86_l_43b);
x86_l_303:
	/* 0x303: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_306:
	/* 0x306: jne    446 <generic_retkprobe_filter_arg+0x446> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x306, 0x446, x86_l_446);
x86_l_30c:
	/* 0x30c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30f:
	/* 0x30f: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_312:
	/* 0x312: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_315:
	/* 0x315: jmp    460 <generic_retkprobe_filter_arg+0x460> */
	X86_SIM_X86_JMP(0x315, 0x460, x86_l_460);
x86_l_31a:
	/* 0x31a: mov    rdx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_322:
	/* 0x322: cmp    rdx,QWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 16ULL);
x86_l_327:
	/* 0x327: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x327, 0x3fe, x86_l_3fe);
x86_l_32d:
	/* 0x32d: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_332:
	/* 0x332: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_335:
	/* 0x335: jb     431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JCC(X86_CC_B, 0x335, 0x431, x86_l_431);
x86_l_33b:
	/* 0x33b: cmp    rdx,QWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 24ULL);
x86_l_340:
	/* 0x340: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x340, 0x3fe, x86_l_3fe);
x86_l_346:
	/* 0x346: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_349:
	/* 0x349: jb     431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JCC(X86_CC_B, 0x349, 0x431, x86_l_431);
x86_l_34f:
	/* 0x34f: cmp    rdx,QWORD PTR [rax+r13*1+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 32ULL);
x86_l_354:
	/* 0x354: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x354, 0x3fe, x86_l_3fe);
x86_l_35a:
	/* 0x35a: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_35d:
	/* 0x35d: jb     431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JCC(X86_CC_B, 0x35d, 0x431, x86_l_431);
x86_l_363:
	/* 0x363: cmp    rdx,QWORD PTR [rax+r13*1+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 40ULL);
x86_l_368:
	/* 0x368: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x368, 0x3fe, x86_l_3fe);
x86_l_36e:
	/* 0x36e: jmp    431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JMP(0x36e, 0x431, x86_l_431);
x86_l_373:
	/* 0x373: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_378:
	/* 0x378: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_37b:
	/* 0x37b: jae    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x37b, 0x474, x86_l_474);
x86_l_381:
	/* 0x381: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_386:
	/* 0x386: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_38c:
	/* 0x38c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_390:
	/* 0x390: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_397:
	/* 0x397: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_39c:
	/* 0x39c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a1:
	/* 0x3a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a3:
	/* 0x3a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a6:
	/* 0x3a6: je     3eb <generic_retkprobe_filter_arg+0x3eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a6, 0x3eb, x86_l_3eb);
x86_l_3a8:
	/* 0x3a8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3ab:
	/* 0x3ab: mov    eax,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3b3:
	/* 0x3b3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b8:
	/* 0x3b8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd:
	/* 0x3bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c2:
	/* 0x3c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c4:
	/* 0x3c4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c9:
	/* 0x3c9: mov    edx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_3ce:
	/* 0x3ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d0:
	/* 0x3d0: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3d3:
	/* 0x3d3: ja     45d <generic_retkprobe_filter_arg+0x45d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3d3, 0x45d, x86_l_45d);
x86_l_3d9:
	/* 0x3d9: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_3de:
	/* 0x3de: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3e1:
	/* 0x3e1: jae    44d <generic_retkprobe_filter_arg+0x44d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3e1, 0x44d, x86_l_44d);
x86_l_3e3:
	/* 0x3e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e6:
	/* 0x3e6: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_3e9:
	/* 0x3e9: jmp    45d <generic_retkprobe_filter_arg+0x45d> */
	X86_SIM_X86_JMP(0x3e9, 0x45d, x86_l_45d);
x86_l_3eb:
	/* 0x3eb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ed:
	/* 0x3ed: jmp    460 <generic_retkprobe_filter_arg+0x460> */
	X86_SIM_X86_JMP(0x3ed, 0x460, x86_l_460);
x86_l_3ef:
	/* 0x3ef: mov    edx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3f7:
	/* 0x3f7: cmp    edx,DWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 16ULL);
x86_l_3fc:
	/* 0x3fc: jne    408 <generic_retkprobe_filter_arg+0x408> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3fc, 0x408, x86_l_408);
x86_l_3fe:
	/* 0x3fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_403:
	/* 0x403: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_406:
	/* 0x406: jmp    460 <generic_retkprobe_filter_arg+0x460> */
	X86_SIM_X86_JMP(0x406, 0x460, x86_l_460);
x86_l_408:
	/* 0x408: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_40d:
	/* 0x40d: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_410:
	/* 0x410: jb     431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JCC(X86_CC_B, 0x410, 0x431, x86_l_431);
x86_l_412:
	/* 0x412: cmp    edx,DWORD PTR [rax+r13*1+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 20ULL);
x86_l_417:
	/* 0x417: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0x3fe, x86_l_3fe);
x86_l_419:
	/* 0x419: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_41c:
	/* 0x41c: jb     431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JCC(X86_CC_B, 0x41c, 0x431, x86_l_431);
x86_l_41e:
	/* 0x41e: cmp    edx,DWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 24ULL);
x86_l_423:
	/* 0x423: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x423, 0x3fe, x86_l_3fe);
x86_l_425:
	/* 0x425: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_428:
	/* 0x428: jb     431 <generic_retkprobe_filter_arg+0x431> */
	X86_SIM_X86_JCC(X86_CC_B, 0x428, 0x431, x86_l_431);
x86_l_42a:
	/* 0x42a: cmp    edx,DWORD PTR [rax+r13*1+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 28ULL);
x86_l_42f:
	/* 0x42f: je     3fe <generic_retkprobe_filter_arg+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42f, 0x3fe, x86_l_3fe);
x86_l_431:
	/* 0x431: or     ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_434:
	/* 0x434: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_437:
	/* 0x437: je     465 <generic_retkprobe_filter_arg+0x465> */
	X86_SIM_X86_JCC(X86_CC_E, 0x437, 0x465, x86_l_465);
x86_l_439:
	/* 0x439: jmp    474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JMP(0x439, 0x474, x86_l_474);
x86_l_43b:
	/* 0x43b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_441:
	/* 0x441: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_444:
	/* 0x444: jmp    460 <generic_retkprobe_filter_arg+0x460> */
	X86_SIM_X86_JMP(0x444, 0x460, x86_l_460);
x86_l_446:
	/* 0x446: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_448:
	/* 0x448: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_44b:
	/* 0x44b: jmp    460 <generic_retkprobe_filter_arg+0x460> */
	X86_SIM_X86_JMP(0x44b, 0x460, x86_l_460);
x86_l_44d:
	/* 0x44d: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_452:
	/* 0x452: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_455:
	/* 0x455: jae    45d <generic_retkprobe_filter_arg+0x45d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x455, 0x45d, x86_l_45d);
x86_l_457:
	/* 0x457: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_45a:
	/* 0x45a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_45d:
	/* 0x45d: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_460:
	/* 0x460: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_463:
	/* 0x463: je     474 <generic_retkprobe_filter_arg+0x474> */
	X86_SIM_X86_JCC(X86_CC_E, 0x463, 0x474, x86_l_474);
x86_l_465:
	/* 0x465: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_469:
	/* 0x469: je     4eb <generic_retkprobe_filter_arg+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x469, 0x4eb, x86_l_4eb);
x86_l_46f:
	/* 0x46f: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_472:
	/* 0x472: jne    4c9 <generic_retkprobe_filter_arg+0x4c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x472, 0x4c9, x86_l_4c9);
x86_l_474:
	/* 0x474: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_478:
	/* 0x478: jg     499 <generic_retkprobe_filter_arg+0x499> */
	X86_SIM_X86_JCC(X86_CC_G, 0x478, 0x499, x86_l_499);
x86_l_47a:
	/* 0x47a: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_47e:
	/* 0x47e: je     51b <generic_retkprobe_filter_arg+0x51b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47e, 0x51b, x86_l_51b);
x86_l_484:
	/* 0x484: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_487:
	/* 0x487: je     528 <generic_retkprobe_filter_arg+0x528> */
	X86_SIM_X86_JCC(X86_CC_E, 0x487, 0x528, x86_l_528);
x86_l_48d:
	/* 0x48d: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_491:
	/* 0x491: je     538 <generic_retkprobe_filter_arg+0x538> */
	X86_SIM_X86_JCC(X86_CC_E, 0x491, 0x538, x86_l_538);
x86_l_497:
	/* 0x497: jmp    4b7 <generic_retkprobe_filter_arg+0x4b7> */
	X86_SIM_X86_JMP(0x497, 0x4b7, x86_l_4b7);
x86_l_499:
	/* 0x499: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_49d:
	/* 0x49d: je     548 <generic_retkprobe_filter_arg+0x548> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49d, 0x548, x86_l_548);
x86_l_4a3:
	/* 0x4a3: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_4a7:
	/* 0x4a7: je     558 <generic_retkprobe_filter_arg+0x558> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a7, 0x558, x86_l_558);
x86_l_4ad:
	/* 0x4ad: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4b1:
	/* 0x4b1: je     568 <generic_retkprobe_filter_arg+0x568> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b1, 0x568, x86_l_568);
x86_l_4b7:
	/* 0x4b7: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4bb:
	/* 0x4bb: jg     59a <generic_retkprobe_filter_arg+0x59a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4bb, 0x59a, x86_l_59a);
x86_l_4c1:
	/* 0x4c1: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4c4:
	/* 0x4c4: jmp    578 <generic_retkprobe_filter_arg+0x578> */
	X86_SIM_X86_JMP(0x4c4, 0x578, x86_l_578);
x86_l_4c9:
	/* 0x4c9: mov    DWORD PTR [r14+0x5ef4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_4d0:
	/* 0x4d0: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_4d7:
	/* 0x4d7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4dc:
	/* 0x4dc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4e1:
	/* 0x4e1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4e4:
	/* 0x4e4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4e9:
	/* 0x4e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eb:
	/* 0x4eb: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_4f2:
	/* 0x4f2: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4f7:
	/* 0x4f7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4fc:
	/* 0x4fc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ff:
	/* 0x4ff: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_504:
	/* 0x504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_506:
	/* 0x506: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_508:
	/* 0x508: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_50c:
	/* 0x50c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_50d:
	/* 0x50d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_50f:
	/* 0x50f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_511:
	/* 0x511: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_513:
	/* 0x513: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_515:
	/* 0x515: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_516:
	/* 0x516: jmp    5e3 <generic_retkprobe_filter_arg+0x5e3> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_51b:
	/* 0x51b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51e:
	/* 0x51e: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_526:
	/* 0x526: jne    578 <generic_retkprobe_filter_arg+0x578> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x526, 0x578, x86_l_578);
x86_l_528:
	/* 0x528: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_52e:
	/* 0x52e: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_536:
	/* 0x536: jne    578 <generic_retkprobe_filter_arg+0x578> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x536, 0x578, x86_l_578);
x86_l_538:
	/* 0x538: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_53e:
	/* 0x53e: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_546:
	/* 0x546: jne    578 <generic_retkprobe_filter_arg+0x578> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x546, 0x578, x86_l_578);
x86_l_548:
	/* 0x548: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_54e:
	/* 0x54e: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_556:
	/* 0x556: jne    578 <generic_retkprobe_filter_arg+0x578> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x556, 0x578, x86_l_578);
x86_l_558:
	/* 0x558: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_55e:
	/* 0x55e: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_566:
	/* 0x566: jne    578 <generic_retkprobe_filter_arg+0x578> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x566, 0x578, x86_l_578);
x86_l_568:
	/* 0x568: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_56e:
	/* 0x56e: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_576:
	/* 0x576: je     59a <generic_retkprobe_filter_arg+0x59a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x576, 0x59a, x86_l_59a);
x86_l_578:
	/* 0x578: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_57f:
	/* 0x57f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_586:
	/* 0x586: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_58b:
	/* 0x58b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_590:
	/* 0x590: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_593:
	/* 0x593: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_598:
	/* 0x598: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59a:
	/* 0x59a: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_59e:
	/* 0x59e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5a3:
	/* 0x5a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a5:
	/* 0x5a5: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5aa:
	/* 0x5aa: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5af:
	/* 0x5af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5b6:
	/* 0x5b6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bb:
	/* 0x5bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c0:
	/* 0x5c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2:
	/* 0x5c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c5:
	/* 0x5c5: je     506 <generic_retkprobe_filter_arg+0x506> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c5, 0x506, x86_l_506);
x86_l_5cb:
	/* 0x5cb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5d2:
	/* 0x5d2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d7:
	/* 0x5d7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5dc:
	/* 0x5dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de:
	/* 0x5de: jmp    506 <generic_retkprobe_filter_arg+0x506> */
	X86_SIM_X86_JMP(0x5de, 0x506, x86_l_506);
x86_l_5e3:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
