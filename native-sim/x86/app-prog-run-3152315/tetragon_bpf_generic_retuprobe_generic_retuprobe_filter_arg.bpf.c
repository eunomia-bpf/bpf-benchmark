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
	/* 0x12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
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
	/* 0x28: je     4ff <generic_retuprobe_filter_arg+0x4ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x4ff, x86_l_4ff);
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
	/* 0x42: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_49:
	/* 0x49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     4e4 <generic_retuprobe_filter_arg+0x4e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x4e4, x86_l_4e4);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     4e4 <generic_retuprobe_filter_arg+0x4e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x4e4, x86_l_4e4);
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
	/* 0x76: je     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x46d, x86_l_46d);
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
	/* 0x99: jb     45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x99, 0x45e, x86_l_45e);
x86_l_9f:
	/* 0x9f: mov    ecx,DWORD PTR [rax+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_a4:
	/* 0xa4: test   ecx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1023ULL);
x86_l_aa:
	/* 0xaa: je     45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa, 0x45e, x86_l_45e);
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
	/* 0xe5: ja     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe5, 0x46d, x86_l_46d);
x86_l_eb:
	/* 0xeb: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_f4:
	/* 0xf4: jne    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf4, 0x46d, x86_l_46d);
x86_l_fa:
	/* 0xfa: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_ff:
	/* 0xff: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_103:
	/* 0x103: ja     45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x103, 0x45e, x86_l_45e);
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
	/* 0x125: jae    1f2 <generic_retuprobe_filter_arg+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x125, 0x1f2, x86_l_1f2);
x86_l_12b:
	/* 0x12b: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_130:
	/* 0x130: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_133:
	/* 0x133: ja     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x133, 0x46d, x86_l_46d);
x86_l_139:
	/* 0x139: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_13e:
	/* 0x13e: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_141:
	/* 0x141: jae    294 <generic_retuprobe_filter_arg+0x294> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x141, 0x294, x86_l_294);
x86_l_147:
	/* 0x147: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_14a:
	/* 0x14a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_14d:
	/* 0x14d: jb     313 <generic_retuprobe_filter_arg+0x313> */
	X86_SIM_X86_JCC(X86_CC_B, 0x14d, 0x313, x86_l_313);
x86_l_153:
	/* 0x153: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_156:
	/* 0x156: je     45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x156, 0x45e, x86_l_45e);
x86_l_15c:
	/* 0x15c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_15f:
	/* 0x15f: jne    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15f, 0x46d, x86_l_46d);
x86_l_165:
	/* 0x165: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_16d:
	/* 0x16d: test   QWORD PTR [rax+r13*1+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_172:
	/* 0x172: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x172, 0x45e, x86_l_45e);
x86_l_178:
	/* 0x178: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_17d:
	/* 0x17d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_180:
	/* 0x180: jb     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x180, 0x46d, x86_l_46d);
x86_l_186:
	/* 0x186: test   QWORD PTR [rax+r13*1+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_18b:
	/* 0x18b: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18b, 0x45e, x86_l_45e);
x86_l_191:
	/* 0x191: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_194:
	/* 0x194: jb     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x194, 0x46d, x86_l_46d);
x86_l_19a:
	/* 0x19a: test   QWORD PTR [rax+r13*1+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 32ULL);
x86_l_19f:
	/* 0x19f: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19f, 0x45e, x86_l_45e);
x86_l_1a5:
	/* 0x1a5: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1a8:
	/* 0x1a8: jb     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a8, 0x46d, x86_l_46d);
x86_l_1ae:
	/* 0x1ae: test   QWORD PTR [rax+r13*1+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 40ULL);
x86_l_1b3:
	/* 0x1b3: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b3, 0x45e, x86_l_45e);
x86_l_1b9:
	/* 0x1b9: jmp    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JMP(0x1b9, 0x46d, x86_l_46d);
x86_l_1be:
	/* 0x1be: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_1c5:
	/* 0x1c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ca:
	/* 0x1ca: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d2:
	/* 0x1d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d5:
	/* 0x1d5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1da:
	/* 0x1da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc:
	/* 0x1dc: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1df:
	/* 0x1df: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1e3:
	/* 0x1e3: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_1e7:
	/* 0x1e7: jbe    eb <generic_retuprobe_filter_arg+0xeb> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1e7, 0xeb, x86_l_eb);
x86_l_1ed:
	/* 0x1ed: jmp    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JMP(0x1ed, 0x46d, x86_l_46d);
x86_l_1f2:
	/* 0x1f2: mov    edx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12306ULL);
x86_l_1f7:
	/* 0x1f7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fb:
	/* 0x1fb: jae    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1fb, 0x45e, x86_l_45e);
x86_l_201:
	/* 0x201: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_206:
	/* 0x206: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_209:
	/* 0x209: ja     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x209, 0x46d, x86_l_46d);
x86_l_20f:
	/* 0x20f: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_214:
	/* 0x214: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_217:
	/* 0x217: jae    36c <generic_retuprobe_filter_arg+0x36c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x217, 0x36c, x86_l_36c);
x86_l_21d:
	/* 0x21d: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_220:
	/* 0x220: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_223:
	/* 0x223: jb     3e8 <generic_retuprobe_filter_arg+0x3e8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x223, 0x3e8, x86_l_3e8);
x86_l_229:
	/* 0x229: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_22c:
	/* 0x22c: je     45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22c, 0x45e, x86_l_45e);
x86_l_232:
	/* 0x232: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_235:
	/* 0x235: jne    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x235, 0x46d, x86_l_46d);
x86_l_23b:
	/* 0x23b: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_243:
	/* 0x243: test   DWORD PTR [rax+r13*1+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_248:
	/* 0x248: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x248, 0x45e, x86_l_45e);
x86_l_24e:
	/* 0x24e: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_253:
	/* 0x253: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_256:
	/* 0x256: jb     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x256, 0x46d, x86_l_46d);
x86_l_25c:
	/* 0x25c: test   DWORD PTR [rax+r13*1+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 20ULL);
x86_l_261:
	/* 0x261: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x261, 0x45e, x86_l_45e);
x86_l_267:
	/* 0x267: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_26a:
	/* 0x26a: jb     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x26a, 0x46d, x86_l_46d);
x86_l_270:
	/* 0x270: test   DWORD PTR [rax+r13*1+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_275:
	/* 0x275: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x275, 0x45e, x86_l_45e);
x86_l_27b:
	/* 0x27b: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_27e:
	/* 0x27e: jb     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x27e, 0x46d, x86_l_46d);
x86_l_284:
	/* 0x284: test   DWORD PTR [rax+r13*1+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 28ULL);
x86_l_289:
	/* 0x289: jne    45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x289, 0x45e, x86_l_45e);
x86_l_28f:
	/* 0x28f: jmp    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JMP(0x28f, 0x46d, x86_l_46d);
x86_l_294:
	/* 0x294: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_299:
	/* 0x299: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_29c:
	/* 0x29c: jae    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x29c, 0x46d, x86_l_46d);
x86_l_2a2:
	/* 0x2a2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7:
	/* 0x2a7: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_2ad:
	/* 0x2ad: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b1:
	/* 0x2b1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2b8:
	/* 0x2b8: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bd:
	/* 0x2bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c2:
	/* 0x2c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4:
	/* 0x2c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c7:
	/* 0x2c7: je     3e4 <generic_retuprobe_filter_arg+0x3e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c7, 0x3e4, x86_l_3e4);
x86_l_2cd:
	/* 0x2cd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d0:
	/* 0x2d0: mov    rax,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd:
	/* 0x2dd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e2:
	/* 0x2e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e7:
	/* 0x2e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9:
	/* 0x2e9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee:
	/* 0x2ee: mov    ecx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_2f3:
	/* 0x2f3: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2f6:
	/* 0x2f6: je     434 <generic_retuprobe_filter_arg+0x434> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f6, 0x434, x86_l_434);
x86_l_2fc:
	/* 0x2fc: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2ff:
	/* 0x2ff: jne    43f <generic_retuprobe_filter_arg+0x43f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ff, 0x43f, x86_l_43f);
x86_l_305:
	/* 0x305: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_308:
	/* 0x308: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_30b:
	/* 0x30b: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30e:
	/* 0x30e: jmp    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JMP(0x30e, 0x459, x86_l_459);
x86_l_313:
	/* 0x313: mov    rdx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_31b:
	/* 0x31b: cmp    rdx,QWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 16ULL);
x86_l_320:
	/* 0x320: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x320, 0x3f7, x86_l_3f7);
x86_l_326:
	/* 0x326: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_32b:
	/* 0x32b: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_32e:
	/* 0x32e: jb     42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x32e, 0x42a, x86_l_42a);
x86_l_334:
	/* 0x334: cmp    rdx,QWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 24ULL);
x86_l_339:
	/* 0x339: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x339, 0x3f7, x86_l_3f7);
x86_l_33f:
	/* 0x33f: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_342:
	/* 0x342: jb     42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x342, 0x42a, x86_l_42a);
x86_l_348:
	/* 0x348: cmp    rdx,QWORD PTR [rax+r13*1+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 32ULL);
x86_l_34d:
	/* 0x34d: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34d, 0x3f7, x86_l_3f7);
x86_l_353:
	/* 0x353: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_356:
	/* 0x356: jb     42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x356, 0x42a, x86_l_42a);
x86_l_35c:
	/* 0x35c: cmp    rdx,QWORD PTR [rax+r13*1+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 40ULL);
x86_l_361:
	/* 0x361: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x361, 0x3f7, x86_l_3f7);
x86_l_367:
	/* 0x367: jmp    42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JMP(0x367, 0x42a, x86_l_42a);
x86_l_36c:
	/* 0x36c: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_371:
	/* 0x371: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_374:
	/* 0x374: jae    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x374, 0x46d, x86_l_46d);
x86_l_37a:
	/* 0x37a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37f:
	/* 0x37f: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_385:
	/* 0x385: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_389:
	/* 0x389: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_390:
	/* 0x390: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_395:
	/* 0x395: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39a:
	/* 0x39a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c:
	/* 0x39c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39f:
	/* 0x39f: je     3e4 <generic_retuprobe_filter_arg+0x3e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39f, 0x3e4, x86_l_3e4);
x86_l_3a1:
	/* 0x3a1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: mov    eax,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3ac:
	/* 0x3ac: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b1:
	/* 0x3b1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b6:
	/* 0x3b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bb:
	/* 0x3bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd:
	/* 0x3bd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c2:
	/* 0x3c2: mov    edx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_3c7:
	/* 0x3c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c9:
	/* 0x3c9: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3cc:
	/* 0x3cc: ja     456 <generic_retuprobe_filter_arg+0x456> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3cc, 0x456, x86_l_456);
x86_l_3d2:
	/* 0x3d2: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_3d7:
	/* 0x3d7: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3da:
	/* 0x3da: jae    446 <generic_retuprobe_filter_arg+0x446> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3da, 0x446, x86_l_446);
x86_l_3dc:
	/* 0x3dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_3e2:
	/* 0x3e2: jmp    456 <generic_retuprobe_filter_arg+0x456> */
	X86_SIM_X86_JMP(0x3e2, 0x456, x86_l_456);
x86_l_3e4:
	/* 0x3e4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e6:
	/* 0x3e6: jmp    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JMP(0x3e6, 0x459, x86_l_459);
x86_l_3e8:
	/* 0x3e8: mov    edx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3f0:
	/* 0x3f0: cmp    edx,DWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 16ULL);
x86_l_3f5:
	/* 0x3f5: jne    401 <generic_retuprobe_filter_arg+0x401> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f5, 0x401, x86_l_401);
x86_l_3f7:
	/* 0x3f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f9:
	/* 0x3f9: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3fc:
	/* 0x3fc: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3ff:
	/* 0x3ff: jmp    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JMP(0x3ff, 0x459, x86_l_459);
x86_l_401:
	/* 0x401: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_406:
	/* 0x406: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_409:
	/* 0x409: jb     42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x409, 0x42a, x86_l_42a);
x86_l_40b:
	/* 0x40b: cmp    edx,DWORD PTR [rax+r13*1+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 20ULL);
x86_l_410:
	/* 0x410: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x410, 0x3f7, x86_l_3f7);
x86_l_412:
	/* 0x412: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_415:
	/* 0x415: jb     42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x415, 0x42a, x86_l_42a);
x86_l_417:
	/* 0x417: cmp    edx,DWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 24ULL);
x86_l_41c:
	/* 0x41c: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41c, 0x3f7, x86_l_3f7);
x86_l_41e:
	/* 0x41e: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_421:
	/* 0x421: jb     42a <generic_retuprobe_filter_arg+0x42a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x421, 0x42a, x86_l_42a);
x86_l_423:
	/* 0x423: cmp    edx,DWORD PTR [rax+r13*1+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 28ULL);
x86_l_428:
	/* 0x428: je     3f7 <generic_retuprobe_filter_arg+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x428, 0x3f7, x86_l_3f7);
x86_l_42a:
	/* 0x42a: or     ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_42d:
	/* 0x42d: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_430:
	/* 0x430: je     45e <generic_retuprobe_filter_arg+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x430, 0x45e, x86_l_45e);
x86_l_432:
	/* 0x432: jmp    46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JMP(0x432, 0x46d, x86_l_46d);
x86_l_434:
	/* 0x434: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_437:
	/* 0x437: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_43a:
	/* 0x43a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_43d:
	/* 0x43d: jmp    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JMP(0x43d, 0x459, x86_l_459);
x86_l_43f:
	/* 0x43f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_441:
	/* 0x441: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_444:
	/* 0x444: jmp    459 <generic_retuprobe_filter_arg+0x459> */
	X86_SIM_X86_JMP(0x444, 0x459, x86_l_459);
x86_l_446:
	/* 0x446: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_44b:
	/* 0x44b: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_44e:
	/* 0x44e: jae    456 <generic_retuprobe_filter_arg+0x456> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x44e, 0x456, x86_l_456);
x86_l_450:
	/* 0x450: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_453:
	/* 0x453: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_456:
	/* 0x456: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_459:
	/* 0x459: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_45c:
	/* 0x45c: je     46d <generic_retuprobe_filter_arg+0x46d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45c, 0x46d, x86_l_46d);
x86_l_45e:
	/* 0x45e: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_462:
	/* 0x462: je     4e4 <generic_retuprobe_filter_arg+0x4e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x462, 0x4e4, x86_l_4e4);
x86_l_468:
	/* 0x468: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_46b:
	/* 0x46b: jne    4c2 <generic_retuprobe_filter_arg+0x4c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46b, 0x4c2, x86_l_4c2);
x86_l_46d:
	/* 0x46d: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_471:
	/* 0x471: jg     492 <generic_retuprobe_filter_arg+0x492> */
	X86_SIM_X86_JCC(X86_CC_G, 0x471, 0x492, x86_l_492);
x86_l_473:
	/* 0x473: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_477:
	/* 0x477: je     50d <generic_retuprobe_filter_arg+0x50d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x477, 0x50d, x86_l_50d);
x86_l_47d:
	/* 0x47d: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_480:
	/* 0x480: je     51a <generic_retuprobe_filter_arg+0x51a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x480, 0x51a, x86_l_51a);
x86_l_486:
	/* 0x486: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_48a:
	/* 0x48a: je     52a <generic_retuprobe_filter_arg+0x52a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48a, 0x52a, x86_l_52a);
x86_l_490:
	/* 0x490: jmp    4b0 <generic_retuprobe_filter_arg+0x4b0> */
	X86_SIM_X86_JMP(0x490, 0x4b0, x86_l_4b0);
x86_l_492:
	/* 0x492: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_496:
	/* 0x496: je     53a <generic_retuprobe_filter_arg+0x53a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x496, 0x53a, x86_l_53a);
x86_l_49c:
	/* 0x49c: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_4a0:
	/* 0x4a0: je     54a <generic_retuprobe_filter_arg+0x54a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a0, 0x54a, x86_l_54a);
x86_l_4a6:
	/* 0x4a6: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4aa:
	/* 0x4aa: je     55a <generic_retuprobe_filter_arg+0x55a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4aa, 0x55a, x86_l_55a);
x86_l_4b0:
	/* 0x4b0: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4b4:
	/* 0x4b4: jg     58c <generic_retuprobe_filter_arg+0x58c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b4, 0x58c, x86_l_58c);
x86_l_4ba:
	/* 0x4ba: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4bd:
	/* 0x4bd: jmp    56a <generic_retuprobe_filter_arg+0x56a> */
	X86_SIM_X86_JMP(0x4bd, 0x56a, x86_l_56a);
x86_l_4c2:
	/* 0x4c2: mov    DWORD PTR [r14+0x5ef4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_4c9:
	/* 0x4c9: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_4d0:
	/* 0x4d0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4d5:
	/* 0x4d5: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4da:
	/* 0x4da: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4dd:
	/* 0x4dd: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4e2:
	/* 0x4e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e4:
	/* 0x4e4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_4eb:
	/* 0x4eb: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4f0:
	/* 0x4f0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4f5:
	/* 0x4f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4fd:
	/* 0x4fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ff:
	/* 0x4ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_501:
	/* 0x501: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_505:
	/* 0x505: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_507:
	/* 0x507: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_508:
	/* 0x508: jmp    5d5 <generic_retuprobe_filter_arg+0x5d5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_50d:
	/* 0x50d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_510:
	/* 0x510: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_518:
	/* 0x518: jne    56a <generic_retuprobe_filter_arg+0x56a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x518, 0x56a, x86_l_56a);
x86_l_51a:
	/* 0x51a: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_520:
	/* 0x520: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_528:
	/* 0x528: jne    56a <generic_retuprobe_filter_arg+0x56a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x528, 0x56a, x86_l_56a);
x86_l_52a:
	/* 0x52a: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_530:
	/* 0x530: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_538:
	/* 0x538: jne    56a <generic_retuprobe_filter_arg+0x56a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x538, 0x56a, x86_l_56a);
x86_l_53a:
	/* 0x53a: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_540:
	/* 0x540: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_548:
	/* 0x548: jne    56a <generic_retuprobe_filter_arg+0x56a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x548, 0x56a, x86_l_56a);
x86_l_54a:
	/* 0x54a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_550:
	/* 0x550: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_558:
	/* 0x558: jne    56a <generic_retuprobe_filter_arg+0x56a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x558, 0x56a, x86_l_56a);
x86_l_55a:
	/* 0x55a: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_560:
	/* 0x560: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_568:
	/* 0x568: je     58c <generic_retuprobe_filter_arg+0x58c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x568, 0x58c, x86_l_58c);
x86_l_56a:
	/* 0x56a: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_571:
	/* 0x571: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_578:
	/* 0x578: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_57d:
	/* 0x57d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_582:
	/* 0x582: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_585:
	/* 0x585: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_58a:
	/* 0x58a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58c:
	/* 0x58c: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_590:
	/* 0x590: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_595:
	/* 0x595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597:
	/* 0x597: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a1:
	/* 0x5a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5a8:
	/* 0x5a8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ad:
	/* 0x5ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b2:
	/* 0x5b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b4:
	/* 0x5b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b7:
	/* 0x5b7: je     4ff <generic_retuprobe_filter_arg+0x4ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b7, 0x4ff, x86_l_4ff);
x86_l_5bd:
	/* 0x5bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5c4:
	/* 0x5c4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c9:
	/* 0x5c9: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5ce:
	/* 0x5ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d0:
	/* 0x5d0: jmp    4ff <generic_retuprobe_filter_arg+0x4ff> */
	X86_SIM_X86_JMP(0x5d0, 0x4ff, x86_l_4ff);
x86_l_5d5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
