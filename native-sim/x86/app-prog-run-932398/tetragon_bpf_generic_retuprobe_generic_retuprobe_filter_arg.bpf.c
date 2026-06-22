extern char argfilter_maps;
extern char filter_map;
extern char process_call_heap;
extern char retprobe_map;
extern char retuprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_12:
	/* 0x12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     4ec <generic_retuprobe_filter_arg+0x4ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x4ec, x86_l_4ec);
x86_l_2e:
	/* 0x2e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: mov    r15d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_38:
	/* 0x38: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_42:
	/* 0x42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47:
	/* 0x47: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     4d6 <generic_retuprobe_filter_arg+0x4d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x4d6, x86_l_4d6);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     4d6 <generic_retuprobe_filter_arg+0x4d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x4d6, x86_l_4d6);
x86_l_67:
	/* 0x67: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d:
	/* 0x6d: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_76:
	/* 0x76: je     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x464, x86_l_464);
x86_l_7c:
	/* 0x7c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    r13,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8a:
	/* 0x8a: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_8d:
	/* 0x8d: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_94:
	/* 0x94: cmp    DWORD PTR [rax+r12*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 25ULL);
x86_l_99:
	/* 0x99: jb     459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_B, 0x99, 0x459, x86_l_459);
x86_l_9f:
	/* 0x9f: mov    ecx,DWORD PTR [rax+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_a4:
	/* 0xa4: test   ecx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1023ULL);
x86_l_aa:
	/* 0xaa: je     459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa, 0x459, x86_l_459);
x86_l_b0:
	/* 0xb0: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b3:
	/* 0xb3: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ba:
	/* 0xba: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_bf:
	/* 0xbf: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_c3:
	/* 0xc3: ja     1be <generic_retuprobe_filter_arg+0x1be> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc3, 0x1be, x86_l_1be);
x86_l_c9:
	/* 0xc9: movabs rdx,0x1e10003c12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117469714ULL);
x86_l_d3:
	/* 0xd3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d7:
	/* 0xd7: jae    1be <generic_retuprobe_filter_arg+0x1be> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xd7, 0x1be, x86_l_1be);
x86_l_dd:
	/* 0xdd: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_e1:
	/* 0xe1: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_e5:
	/* 0xe5: ja     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe5, 0x464, x86_l_464);
x86_l_eb:
	/* 0xeb: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_f4:
	/* 0xf4: jne    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf4, 0x464, x86_l_464);
x86_l_fa:
	/* 0xfa: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_ff:
	/* 0xff: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_103:
	/* 0x103: ja     459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_A, 0x103, 0x459, x86_l_459);
x86_l_109:
	/* 0x109: mov    rbp,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_111:
	/* 0x111: movabs rdx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117457408ULL);
x86_l_11b:
	/* 0x11b: and    ebp,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_121:
	/* 0x121: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_125:
	/* 0x125: jae    1ed <generic_retuprobe_filter_arg+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x125, 0x1ed, x86_l_1ed);
x86_l_12b:
	/* 0x12b: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_130:
	/* 0x130: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_133:
	/* 0x133: ja     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_A, 0x133, 0x464, x86_l_464);
x86_l_139:
	/* 0x139: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_13e:
	/* 0x13e: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_141:
	/* 0x141: jae    28f <generic_retuprobe_filter_arg+0x28f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x141, 0x28f, x86_l_28f);
x86_l_147:
	/* 0x147: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_14a:
	/* 0x14a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_14d:
	/* 0x14d: jb     30e <generic_retuprobe_filter_arg+0x30e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x14d, 0x30e, x86_l_30e);
x86_l_153:
	/* 0x153: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_156:
	/* 0x156: je     459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_E, 0x156, 0x459, x86_l_459);
x86_l_15c:
	/* 0x15c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_15f:
	/* 0x15f: jne    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15f, 0x464, x86_l_464);
x86_l_165:
	/* 0x165: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_16d:
	/* 0x16d: test   QWORD PTR [rax+r13*1+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_172:
	/* 0x172: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x172, 0x459, x86_l_459);
x86_l_178:
	/* 0x178: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_17d:
	/* 0x17d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_180:
	/* 0x180: jb     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_B, 0x180, 0x464, x86_l_464);
x86_l_186:
	/* 0x186: test   QWORD PTR [rax+r13*1+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_18b:
	/* 0x18b: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18b, 0x459, x86_l_459);
x86_l_191:
	/* 0x191: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_194:
	/* 0x194: jb     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_B, 0x194, 0x464, x86_l_464);
x86_l_19a:
	/* 0x19a: test   QWORD PTR [rax+r13*1+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 32ULL);
x86_l_19f:
	/* 0x19f: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19f, 0x459, x86_l_459);
x86_l_1a5:
	/* 0x1a5: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1a8:
	/* 0x1a8: jb     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a8, 0x464, x86_l_464);
x86_l_1ae:
	/* 0x1ae: test   QWORD PTR [rax+r13*1+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 40ULL);
x86_l_1b3:
	/* 0x1b3: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b3, 0x459, x86_l_459);
x86_l_1b9:
	/* 0x1b9: jmp    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JMP(0x1b9, 0x464, x86_l_464);
x86_l_1be:
	/* 0x1be: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c3:
	/* 0x1c3: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_1ca:
	/* 0x1ca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d2:
	/* 0x1d2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1d5:
	/* 0x1d5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d7:
	/* 0x1d7: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1da:
	/* 0x1da: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1de:
	/* 0x1de: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_1e2:
	/* 0x1e2: jbe    eb <generic_retuprobe_filter_arg+0xeb> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1e2, 0xeb, x86_l_eb);
x86_l_1e8:
	/* 0x1e8: jmp    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JMP(0x1e8, 0x464, x86_l_464);
x86_l_1ed:
	/* 0x1ed: mov    edx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12306ULL);
x86_l_1f2:
	/* 0x1f2: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: jae    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1f6, 0x459, x86_l_459);
x86_l_1fc:
	/* 0x1fc: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_201:
	/* 0x201: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_204:
	/* 0x204: ja     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_A, 0x204, 0x464, x86_l_464);
x86_l_20a:
	/* 0x20a: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_20f:
	/* 0x20f: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_212:
	/* 0x212: jae    367 <generic_retuprobe_filter_arg+0x367> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x212, 0x367, x86_l_367);
x86_l_218:
	/* 0x218: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_21b:
	/* 0x21b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_21e:
	/* 0x21e: jb     3e3 <generic_retuprobe_filter_arg+0x3e3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x21e, 0x3e3, x86_l_3e3);
x86_l_224:
	/* 0x224: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_227:
	/* 0x227: je     459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_E, 0x227, 0x459, x86_l_459);
x86_l_22d:
	/* 0x22d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_230:
	/* 0x230: jne    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x230, 0x464, x86_l_464);
x86_l_236:
	/* 0x236: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_23e:
	/* 0x23e: test   DWORD PTR [rax+r13*1+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_243:
	/* 0x243: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x243, 0x459, x86_l_459);
x86_l_249:
	/* 0x249: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_24e:
	/* 0x24e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_251:
	/* 0x251: jb     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_B, 0x251, 0x464, x86_l_464);
x86_l_257:
	/* 0x257: test   DWORD PTR [rax+r13*1+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 20ULL);
x86_l_25c:
	/* 0x25c: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25c, 0x459, x86_l_459);
x86_l_262:
	/* 0x262: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_265:
	/* 0x265: jb     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_B, 0x265, 0x464, x86_l_464);
x86_l_26b:
	/* 0x26b: test   DWORD PTR [rax+r13*1+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_270:
	/* 0x270: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x270, 0x459, x86_l_459);
x86_l_276:
	/* 0x276: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_279:
	/* 0x279: jb     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_B, 0x279, 0x464, x86_l_464);
x86_l_27f:
	/* 0x27f: test   DWORD PTR [rax+r13*1+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 28ULL);
x86_l_284:
	/* 0x284: jne    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x284, 0x459, x86_l_459);
x86_l_28a:
	/* 0x28a: jmp    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JMP(0x28a, 0x464, x86_l_464);
x86_l_28f:
	/* 0x28f: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_294:
	/* 0x294: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_297:
	/* 0x297: jae    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x297, 0x464, x86_l_464);
x86_l_29d:
	/* 0x29d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a2:
	/* 0x2a2: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_2a8:
	/* 0x2a8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ac:
	/* 0x2ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b1:
	/* 0x2b1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2b8:
	/* 0x2b8: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bd:
	/* 0x2bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf:
	/* 0x2bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c2:
	/* 0x2c2: je     3df <generic_retuprobe_filter_arg+0x3df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c2, 0x3df, x86_l_3df);
x86_l_2c8:
	/* 0x2c8: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_2d0:
	/* 0x2d0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5:
	/* 0x2d5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2da:
	/* 0x2da: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df:
	/* 0x2df: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e2:
	/* 0x2e2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e4:
	/* 0x2e4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9:
	/* 0x2e9: mov    ecx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_2ee:
	/* 0x2ee: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2f1:
	/* 0x2f1: je     42f <generic_retuprobe_filter_arg+0x42f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f1, 0x42f, x86_l_42f);
x86_l_2f7:
	/* 0x2f7: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2fa:
	/* 0x2fa: jne    43a <generic_retuprobe_filter_arg+0x43a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2fa, 0x43a, x86_l_43a);
x86_l_300:
	/* 0x300: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_306:
	/* 0x306: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_309:
	/* 0x309: jmp    454 <generic_retuprobe_filter_arg+0x454> */
	X86_SIM_X86_JMP(0x309, 0x454, x86_l_454);
x86_l_30e:
	/* 0x30e: mov    rdx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_316:
	/* 0x316: cmp    rdx,QWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 16ULL);
x86_l_31b:
	/* 0x31b: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31b, 0x3f2, x86_l_3f2);
x86_l_321:
	/* 0x321: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_326:
	/* 0x326: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_329:
	/* 0x329: jb     425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JCC(X86_CC_B, 0x329, 0x425, x86_l_425);
x86_l_32f:
	/* 0x32f: cmp    rdx,QWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 24ULL);
x86_l_334:
	/* 0x334: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x334, 0x3f2, x86_l_3f2);
x86_l_33a:
	/* 0x33a: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_33d:
	/* 0x33d: jb     425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JCC(X86_CC_B, 0x33d, 0x425, x86_l_425);
x86_l_343:
	/* 0x343: cmp    rdx,QWORD PTR [rax+r13*1+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 32ULL);
x86_l_348:
	/* 0x348: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x348, 0x3f2, x86_l_3f2);
x86_l_34e:
	/* 0x34e: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_351:
	/* 0x351: jb     425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JCC(X86_CC_B, 0x351, 0x425, x86_l_425);
x86_l_357:
	/* 0x357: cmp    rdx,QWORD PTR [rax+r13*1+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 40ULL);
x86_l_35c:
	/* 0x35c: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35c, 0x3f2, x86_l_3f2);
x86_l_362:
	/* 0x362: jmp    425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JMP(0x362, 0x425, x86_l_425);
x86_l_367:
	/* 0x367: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_36c:
	/* 0x36c: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_36f:
	/* 0x36f: jae    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x36f, 0x464, x86_l_464);
x86_l_375:
	/* 0x375: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37a:
	/* 0x37a: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_380:
	/* 0x380: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_384:
	/* 0x384: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_389:
	/* 0x389: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_390:
	/* 0x390: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_395:
	/* 0x395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397:
	/* 0x397: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: je     3df <generic_retuprobe_filter_arg+0x3df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39a, 0x3df, x86_l_3df);
x86_l_39c:
	/* 0x39c: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a9:
	/* 0x3a9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3ae:
	/* 0x3ae: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3:
	/* 0x3b3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3b6:
	/* 0x3b6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3b8:
	/* 0x3b8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bd:
	/* 0x3bd: mov    edx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_3c2:
	/* 0x3c2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c4:
	/* 0x3c4: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3c7:
	/* 0x3c7: ja     451 <generic_retuprobe_filter_arg+0x451> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c7, 0x451, x86_l_451);
x86_l_3cd:
	/* 0x3cd: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_3d2:
	/* 0x3d2: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3d5:
	/* 0x3d5: jae    441 <generic_retuprobe_filter_arg+0x441> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3d5, 0x441, x86_l_441);
x86_l_3d7:
	/* 0x3d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3da:
	/* 0x3da: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_3dd:
	/* 0x3dd: jmp    451 <generic_retuprobe_filter_arg+0x451> */
	X86_SIM_X86_JMP(0x3dd, 0x451, x86_l_451);
x86_l_3df:
	/* 0x3df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e1:
	/* 0x3e1: jmp    454 <generic_retuprobe_filter_arg+0x454> */
	X86_SIM_X86_JMP(0x3e1, 0x454, x86_l_454);
x86_l_3e3:
	/* 0x3e3: mov    edx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3eb:
	/* 0x3eb: cmp    edx,DWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 16ULL);
x86_l_3f0:
	/* 0x3f0: jne    3fc <generic_retuprobe_filter_arg+0x3fc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f0, 0x3fc, x86_l_3fc);
x86_l_3f2:
	/* 0x3f2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f4:
	/* 0x3f4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3f7:
	/* 0x3f7: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3fa:
	/* 0x3fa: jmp    454 <generic_retuprobe_filter_arg+0x454> */
	X86_SIM_X86_JMP(0x3fa, 0x454, x86_l_454);
x86_l_3fc:
	/* 0x3fc: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_401:
	/* 0x401: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_404:
	/* 0x404: jb     425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JCC(X86_CC_B, 0x404, 0x425, x86_l_425);
x86_l_406:
	/* 0x406: cmp    edx,DWORD PTR [rax+r13*1+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 20ULL);
x86_l_40b:
	/* 0x40b: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40b, 0x3f2, x86_l_3f2);
x86_l_40d:
	/* 0x40d: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_410:
	/* 0x410: jb     425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JCC(X86_CC_B, 0x410, 0x425, x86_l_425);
x86_l_412:
	/* 0x412: cmp    edx,DWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 24ULL);
x86_l_417:
	/* 0x417: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0x3f2, x86_l_3f2);
x86_l_419:
	/* 0x419: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_41c:
	/* 0x41c: jb     425 <generic_retuprobe_filter_arg+0x425> */
	X86_SIM_X86_JCC(X86_CC_B, 0x41c, 0x425, x86_l_425);
x86_l_41e:
	/* 0x41e: cmp    edx,DWORD PTR [rax+r13*1+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 28ULL);
x86_l_423:
	/* 0x423: je     3f2 <generic_retuprobe_filter_arg+0x3f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x423, 0x3f2, x86_l_3f2);
x86_l_425:
	/* 0x425: or     ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_428:
	/* 0x428: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_42b:
	/* 0x42b: je     459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42b, 0x459, x86_l_459);
x86_l_42d:
	/* 0x42d: jmp    464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JMP(0x42d, 0x464, x86_l_464);
x86_l_42f:
	/* 0x42f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_432:
	/* 0x432: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_435:
	/* 0x435: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_438:
	/* 0x438: jmp    454 <generic_retuprobe_filter_arg+0x454> */
	X86_SIM_X86_JMP(0x438, 0x454, x86_l_454);
x86_l_43a:
	/* 0x43a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43c:
	/* 0x43c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_43f:
	/* 0x43f: jmp    454 <generic_retuprobe_filter_arg+0x454> */
	X86_SIM_X86_JMP(0x43f, 0x454, x86_l_454);
x86_l_441:
	/* 0x441: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_446:
	/* 0x446: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_449:
	/* 0x449: jae    451 <generic_retuprobe_filter_arg+0x451> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x449, 0x451, x86_l_451);
x86_l_44b:
	/* 0x44b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44e:
	/* 0x44e: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_451:
	/* 0x451: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_454:
	/* 0x454: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_457:
	/* 0x457: je     464 <generic_retuprobe_filter_arg+0x464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x457, 0x464, x86_l_464);
x86_l_459:
	/* 0x459: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_45d:
	/* 0x45d: je     4d6 <generic_retuprobe_filter_arg+0x4d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45d, 0x4d6, x86_l_4d6);
x86_l_45f:
	/* 0x45f: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_462:
	/* 0x462: jne    4b9 <generic_retuprobe_filter_arg+0x4b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x462, 0x4b9, x86_l_4b9);
x86_l_464:
	/* 0x464: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_468:
	/* 0x468: jg     489 <generic_retuprobe_filter_arg+0x489> */
	X86_SIM_X86_JCC(X86_CC_G, 0x468, 0x489, x86_l_489);
x86_l_46a:
	/* 0x46a: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_46e:
	/* 0x46e: je     4fa <generic_retuprobe_filter_arg+0x4fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46e, 0x4fa, x86_l_4fa);
x86_l_474:
	/* 0x474: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_477:
	/* 0x477: je     507 <generic_retuprobe_filter_arg+0x507> */
	X86_SIM_X86_JCC(X86_CC_E, 0x477, 0x507, x86_l_507);
x86_l_47d:
	/* 0x47d: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_481:
	/* 0x481: je     517 <generic_retuprobe_filter_arg+0x517> */
	X86_SIM_X86_JCC(X86_CC_E, 0x481, 0x517, x86_l_517);
x86_l_487:
	/* 0x487: jmp    4a7 <generic_retuprobe_filter_arg+0x4a7> */
	X86_SIM_X86_JMP(0x487, 0x4a7, x86_l_4a7);
x86_l_489:
	/* 0x489: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_48d:
	/* 0x48d: je     527 <generic_retuprobe_filter_arg+0x527> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48d, 0x527, x86_l_527);
x86_l_493:
	/* 0x493: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_497:
	/* 0x497: je     537 <generic_retuprobe_filter_arg+0x537> */
	X86_SIM_X86_JCC(X86_CC_E, 0x497, 0x537, x86_l_537);
x86_l_49d:
	/* 0x49d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4a1:
	/* 0x4a1: je     547 <generic_retuprobe_filter_arg+0x547> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a1, 0x547, x86_l_547);
x86_l_4a7:
	/* 0x4a7: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4ab:
	/* 0x4ab: jg     574 <generic_retuprobe_filter_arg+0x574> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4ab, 0x574, x86_l_574);
x86_l_4b1:
	/* 0x4b1: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4b4:
	/* 0x4b4: jmp    557 <generic_retuprobe_filter_arg+0x557> */
	X86_SIM_X86_JMP(0x4b4, 0x557, x86_l_557);
x86_l_4b9:
	/* 0x4b9: mov    DWORD PTR [r14+0x5ef4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_4c0:
	/* 0x4c0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4c5:
	/* 0x4c5: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_4cc:
	/* 0x4cc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4cf:
	/* 0x4cf: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4d4:
	/* 0x4d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d6:
	/* 0x4d6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4db:
	/* 0x4db: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_4e2:
	/* 0x4e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4e5:
	/* 0x4e5: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4ea:
	/* 0x4ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ec:
	/* 0x4ec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ee:
	/* 0x4ee: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_4f2:
	/* 0x4f2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4f4:
	/* 0x4f4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: jmp    5bd <generic_retuprobe_filter_arg+0x5bd> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4fa:
	/* 0x4fa: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fd:
	/* 0x4fd: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_505:
	/* 0x505: jne    557 <generic_retuprobe_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x505, 0x557, x86_l_557);
x86_l_507:
	/* 0x507: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_50d:
	/* 0x50d: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_515:
	/* 0x515: jne    557 <generic_retuprobe_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x515, 0x557, x86_l_557);
x86_l_517:
	/* 0x517: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_51d:
	/* 0x51d: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_525:
	/* 0x525: jne    557 <generic_retuprobe_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x525, 0x557, x86_l_557);
x86_l_527:
	/* 0x527: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_52d:
	/* 0x52d: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_535:
	/* 0x535: jne    557 <generic_retuprobe_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x535, 0x557, x86_l_557);
x86_l_537:
	/* 0x537: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_53d:
	/* 0x53d: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_545:
	/* 0x545: jne    557 <generic_retuprobe_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x545, 0x557, x86_l_557);
x86_l_547:
	/* 0x547: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_54d:
	/* 0x54d: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_555:
	/* 0x555: je     574 <generic_retuprobe_filter_arg+0x574> */
	X86_SIM_X86_JCC(X86_CC_E, 0x555, 0x574, x86_l_574);
x86_l_557:
	/* 0x557: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_55e:
	/* 0x55e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_563:
	/* 0x563: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_56a:
	/* 0x56a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_56d:
	/* 0x56d: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_572:
	/* 0x572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_574:
	/* 0x574: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_578:
	/* 0x578: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_57d:
	/* 0x57d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57f:
	/* 0x57f: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_584:
	/* 0x584: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_589:
	/* 0x589: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58e:
	/* 0x58e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_595:
	/* 0x595: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59a:
	/* 0x59a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59c:
	/* 0x59c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59f:
	/* 0x59f: je     4ec <generic_retuprobe_filter_arg+0x4ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59f, 0x4ec, x86_l_4ec);
x86_l_5a5:
	/* 0x5a5: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5aa:
	/* 0x5aa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5b1:
	/* 0x5b1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b6:
	/* 0x5b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b8:
	/* 0x5b8: jmp    4ec <generic_retuprobe_filter_arg+0x4ec> */
	X86_SIM_X86_JMP(0x5b8, 0x4ec, x86_l_4ec);
x86_l_5bd:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
