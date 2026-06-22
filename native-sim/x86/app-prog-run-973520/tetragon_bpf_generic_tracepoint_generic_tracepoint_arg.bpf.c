extern char argfilter_maps;
extern char filter_map;
extern char process_call_heap;
extern char retprobe_map;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_tracepoint_generic_tracepoint_arg_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x17: mov    rdi,QWORD PTR [rip+0x4717] */
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
	/* 0x28: je     53d <generic_tracepoint_arg+0x53d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x53d, x86_l_53d);
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
	/* 0x47: mov    rdi,QWORD PTR [rip+0x4717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     527 <generic_tracepoint_arg+0x527> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x527, x86_l_527);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     527 <generic_tracepoint_arg+0x527> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x527, x86_l_527);
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
	/* 0x76: je     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x4b5, x86_l_4b5);
x86_l_7c:
	/* 0x7c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    rsi,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8a:
	/* 0x8a: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8e:
	/* 0x8e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_92:
	/* 0x92: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_98:
	/* 0x98: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9b:
	/* 0x9b: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9e:
	/* 0x9e: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a2:
	/* 0xa2: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a4:
	/* 0xa4: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_aa:
	/* 0xaa: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ad:
	/* 0xad: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b0:
	/* 0xb0: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b8:
	/* 0xb8: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_bb:
	/* 0xbb: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_be:
	/* 0xbe: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c0:
	/* 0xc0: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c6:
	/* 0xc6: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c9:
	/* 0xc9: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cc:
	/* 0xcc: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_ce:
	/* 0xce: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d4:
	/* 0xd4: mov    r13d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d8:
	/* 0xd8: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_db:
	/* 0xdb: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_de:
	/* 0xde: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e5:
	/* 0xe5: cmp    DWORD PTR [rax+r12*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 25ULL);
x86_l_ea:
	/* 0xea: jb     4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_B, 0xea, 0x4aa, x86_l_4aa);
x86_l_f0:
	/* 0xf0: mov    ecx,DWORD PTR [rax+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_f5:
	/* 0xf5: test   ecx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1023ULL);
x86_l_fb:
	/* 0xfb: je     4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb, 0x4aa, x86_l_4aa);
x86_l_101:
	/* 0x101: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_104:
	/* 0x104: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_10b:
	/* 0x10b: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_110:
	/* 0x110: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_114:
	/* 0x114: ja     20f <generic_tracepoint_arg+0x20f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114, 0x20f, x86_l_20f);
x86_l_11a:
	/* 0x11a: movabs rdx,0x1e10003c12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117469714ULL);
x86_l_124:
	/* 0x124: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_128:
	/* 0x128: jae    20f <generic_tracepoint_arg+0x20f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x128, 0x20f, x86_l_20f);
x86_l_12e:
	/* 0x12e: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_132:
	/* 0x132: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_136:
	/* 0x136: ja     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x136, 0x4b5, x86_l_4b5);
x86_l_13c:
	/* 0x13c: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_145:
	/* 0x145: jne    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x145, 0x4b5, x86_l_4b5);
x86_l_14b:
	/* 0x14b: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_150:
	/* 0x150: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_154:
	/* 0x154: ja     4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x154, 0x4aa, x86_l_4aa);
x86_l_15a:
	/* 0x15a: mov    rbp,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_162:
	/* 0x162: movabs rdx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117457408ULL);
x86_l_16c:
	/* 0x16c: and    ebp,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_172:
	/* 0x172: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_176:
	/* 0x176: jae    23e <generic_tracepoint_arg+0x23e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x176, 0x23e, x86_l_23e);
x86_l_17c:
	/* 0x17c: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_181:
	/* 0x181: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_184:
	/* 0x184: ja     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x184, 0x4b5, x86_l_4b5);
x86_l_18a:
	/* 0x18a: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_18f:
	/* 0x18f: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_192:
	/* 0x192: jae    2e0 <generic_tracepoint_arg+0x2e0> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x192, 0x2e0, x86_l_2e0);
x86_l_198:
	/* 0x198: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_19b:
	/* 0x19b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_19e:
	/* 0x19e: jb     35f <generic_tracepoint_arg+0x35f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19e, 0x35f, x86_l_35f);
x86_l_1a4:
	/* 0x1a4: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1a7:
	/* 0x1a7: je     4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a7, 0x4aa, x86_l_4aa);
x86_l_1ad:
	/* 0x1ad: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b0:
	/* 0x1b0: jne    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b0, 0x4b5, x86_l_4b5);
x86_l_1b6:
	/* 0x1b6: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_1be:
	/* 0x1be: test   QWORD PTR [rax+r13*1+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_1c3:
	/* 0x1c3: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c3, 0x4aa, x86_l_4aa);
x86_l_1c9:
	/* 0x1c9: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_1ce:
	/* 0x1ce: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d1:
	/* 0x1d1: jb     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d1, 0x4b5, x86_l_4b5);
x86_l_1d7:
	/* 0x1d7: test   QWORD PTR [rax+r13*1+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_1dc:
	/* 0x1dc: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1dc, 0x4aa, x86_l_4aa);
x86_l_1e2:
	/* 0x1e2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1e5:
	/* 0x1e5: jb     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e5, 0x4b5, x86_l_4b5);
x86_l_1eb:
	/* 0x1eb: test   QWORD PTR [rax+r13*1+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 32ULL);
x86_l_1f0:
	/* 0x1f0: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f0, 0x4aa, x86_l_4aa);
x86_l_1f6:
	/* 0x1f6: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f9:
	/* 0x1f9: jb     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1f9, 0x4b5, x86_l_4b5);
x86_l_1ff:
	/* 0x1ff: test   QWORD PTR [rax+r13*1+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 40ULL);
x86_l_204:
	/* 0x204: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x204, 0x4aa, x86_l_4aa);
x86_l_20a:
	/* 0x20a: jmp    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JMP(0x20a, 0x4b5, x86_l_4b5);
x86_l_20f:
	/* 0x20f: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_214:
	/* 0x214: mov    rsi,QWORD PTR [rip+0x4717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_21b:
	/* 0x21b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21e:
	/* 0x21e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_223:
	/* 0x223: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_226:
	/* 0x226: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_228:
	/* 0x228: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_22b:
	/* 0x22b: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_22f:
	/* 0x22f: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_233:
	/* 0x233: jbe    13c <generic_tracepoint_arg+0x13c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x233, 0x13c, x86_l_13c);
x86_l_239:
	/* 0x239: jmp    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JMP(0x239, 0x4b5, x86_l_4b5);
x86_l_23e:
	/* 0x23e: mov    edx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12306ULL);
x86_l_243:
	/* 0x243: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_247:
	/* 0x247: jae    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x247, 0x4aa, x86_l_4aa);
x86_l_24d:
	/* 0x24d: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_252:
	/* 0x252: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_255:
	/* 0x255: ja     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x255, 0x4b5, x86_l_4b5);
x86_l_25b:
	/* 0x25b: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_260:
	/* 0x260: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_263:
	/* 0x263: jae    3b8 <generic_tracepoint_arg+0x3b8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x263, 0x3b8, x86_l_3b8);
x86_l_269:
	/* 0x269: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_26c:
	/* 0x26c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_26f:
	/* 0x26f: jb     434 <generic_tracepoint_arg+0x434> */
	X86_SIM_X86_JCC(X86_CC_B, 0x26f, 0x434, x86_l_434);
x86_l_275:
	/* 0x275: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_278:
	/* 0x278: je     4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x278, 0x4aa, x86_l_4aa);
x86_l_27e:
	/* 0x27e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_281:
	/* 0x281: jne    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x281, 0x4b5, x86_l_4b5);
x86_l_287:
	/* 0x287: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_28f:
	/* 0x28f: test   DWORD PTR [rax+r13*1+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_294:
	/* 0x294: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x294, 0x4aa, x86_l_4aa);
x86_l_29a:
	/* 0x29a: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_29f:
	/* 0x29f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2a2:
	/* 0x2a2: jb     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2a2, 0x4b5, x86_l_4b5);
x86_l_2a8:
	/* 0x2a8: test   DWORD PTR [rax+r13*1+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 20ULL);
x86_l_2ad:
	/* 0x2ad: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ad, 0x4aa, x86_l_4aa);
x86_l_2b3:
	/* 0x2b3: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2b6:
	/* 0x2b6: jb     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2b6, 0x4b5, x86_l_4b5);
x86_l_2bc:
	/* 0x2bc: test   DWORD PTR [rax+r13*1+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_2c1:
	/* 0x2c1: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c1, 0x4aa, x86_l_4aa);
x86_l_2c7:
	/* 0x2c7: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2ca:
	/* 0x2ca: jb     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2ca, 0x4b5, x86_l_4b5);
x86_l_2d0:
	/* 0x2d0: test   DWORD PTR [rax+r13*1+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 28ULL);
x86_l_2d5:
	/* 0x2d5: jne    4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d5, 0x4aa, x86_l_4aa);
x86_l_2db:
	/* 0x2db: jmp    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JMP(0x2db, 0x4b5, x86_l_4b5);
x86_l_2e0:
	/* 0x2e0: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_2e5:
	/* 0x2e5: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2e8:
	/* 0x2e8: jae    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2e8, 0x4b5, x86_l_4b5);
x86_l_2ee:
	/* 0x2ee: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3:
	/* 0x2f3: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_2f9:
	/* 0x2f9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fd:
	/* 0x2fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_302:
	/* 0x302: mov    rdi,QWORD PTR [rip+0x4717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_309:
	/* 0x309: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: je     430 <generic_tracepoint_arg+0x430> */
	X86_SIM_X86_JCC(X86_CC_E, 0x313, 0x430, x86_l_430);
x86_l_319:
	/* 0x319: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_321:
	/* 0x321: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_326:
	/* 0x326: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_32b:
	/* 0x32b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_330:
	/* 0x330: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_333:
	/* 0x333: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_335:
	/* 0x335: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33a:
	/* 0x33a: mov    ecx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_33f:
	/* 0x33f: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_342:
	/* 0x342: je     480 <generic_tracepoint_arg+0x480> */
	X86_SIM_X86_JCC(X86_CC_E, 0x342, 0x480, x86_l_480);
x86_l_348:
	/* 0x348: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_34b:
	/* 0x34b: jne    48b <generic_tracepoint_arg+0x48b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34b, 0x48b, x86_l_48b);
x86_l_351:
	/* 0x351: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_354:
	/* 0x354: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_357:
	/* 0x357: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_35a:
	/* 0x35a: jmp    4a5 <generic_tracepoint_arg+0x4a5> */
	X86_SIM_X86_JMP(0x35a, 0x4a5, x86_l_4a5);
x86_l_35f:
	/* 0x35f: mov    rdx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_367:
	/* 0x367: cmp    rdx,QWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 16ULL);
x86_l_36c:
	/* 0x36c: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36c, 0x443, x86_l_443);
x86_l_372:
	/* 0x372: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_377:
	/* 0x377: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_37a:
	/* 0x37a: jb     476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JCC(X86_CC_B, 0x37a, 0x476, x86_l_476);
x86_l_380:
	/* 0x380: cmp    rdx,QWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 24ULL);
x86_l_385:
	/* 0x385: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x385, 0x443, x86_l_443);
x86_l_38b:
	/* 0x38b: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_38e:
	/* 0x38e: jb     476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JCC(X86_CC_B, 0x38e, 0x476, x86_l_476);
x86_l_394:
	/* 0x394: cmp    rdx,QWORD PTR [rax+r13*1+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 32ULL);
x86_l_399:
	/* 0x399: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x399, 0x443, x86_l_443);
x86_l_39f:
	/* 0x39f: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_3a2:
	/* 0x3a2: jb     476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3a2, 0x476, x86_l_476);
x86_l_3a8:
	/* 0x3a8: cmp    rdx,QWORD PTR [rax+r13*1+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 40ULL);
x86_l_3ad:
	/* 0x3ad: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ad, 0x443, x86_l_443);
x86_l_3b3:
	/* 0x3b3: jmp    476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JMP(0x3b3, 0x476, x86_l_476);
x86_l_3b8:
	/* 0x3b8: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_3bd:
	/* 0x3bd: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3c0:
	/* 0x3c0: jae    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3c0, 0x4b5, x86_l_4b5);
x86_l_3c6:
	/* 0x3c6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cb:
	/* 0x3cb: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_3d1:
	/* 0x3d1: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d5:
	/* 0x3d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3da:
	/* 0x3da: mov    rdi,QWORD PTR [rip+0x4717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_3e1:
	/* 0x3e1: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e6:
	/* 0x3e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e8:
	/* 0x3e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3eb:
	/* 0x3eb: je     430 <generic_tracepoint_arg+0x430> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3eb, 0x430, x86_l_430);
x86_l_3ed:
	/* 0x3ed: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fa:
	/* 0x3fa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3ff:
	/* 0x3ff: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_404:
	/* 0x404: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_407:
	/* 0x407: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_409:
	/* 0x409: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e:
	/* 0x40e: mov    edx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_413:
	/* 0x413: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_415:
	/* 0x415: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_418:
	/* 0x418: ja     4a2 <generic_tracepoint_arg+0x4a2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x418, 0x4a2, x86_l_4a2);
x86_l_41e:
	/* 0x41e: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_423:
	/* 0x423: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_426:
	/* 0x426: jae    492 <generic_tracepoint_arg+0x492> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x426, 0x492, x86_l_492);
x86_l_428:
	/* 0x428: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42b:
	/* 0x42b: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_42e:
	/* 0x42e: jmp    4a2 <generic_tracepoint_arg+0x4a2> */
	X86_SIM_X86_JMP(0x42e, 0x4a2, x86_l_4a2);
x86_l_430:
	/* 0x430: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_432:
	/* 0x432: jmp    4a5 <generic_tracepoint_arg+0x4a5> */
	X86_SIM_X86_JMP(0x432, 0x4a5, x86_l_4a5);
x86_l_434:
	/* 0x434: mov    edx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_43c:
	/* 0x43c: cmp    edx,DWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 16ULL);
x86_l_441:
	/* 0x441: jne    44d <generic_tracepoint_arg+0x44d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x441, 0x44d, x86_l_44d);
x86_l_443:
	/* 0x443: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_445:
	/* 0x445: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_448:
	/* 0x448: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_44b:
	/* 0x44b: jmp    4a5 <generic_tracepoint_arg+0x4a5> */
	X86_SIM_X86_JMP(0x44b, 0x4a5, x86_l_4a5);
x86_l_44d:
	/* 0x44d: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_452:
	/* 0x452: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_455:
	/* 0x455: jb     476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JCC(X86_CC_B, 0x455, 0x476, x86_l_476);
x86_l_457:
	/* 0x457: cmp    edx,DWORD PTR [rax+r13*1+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 20ULL);
x86_l_45c:
	/* 0x45c: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45c, 0x443, x86_l_443);
x86_l_45e:
	/* 0x45e: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_461:
	/* 0x461: jb     476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JCC(X86_CC_B, 0x461, 0x476, x86_l_476);
x86_l_463:
	/* 0x463: cmp    edx,DWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 24ULL);
x86_l_468:
	/* 0x468: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x468, 0x443, x86_l_443);
x86_l_46a:
	/* 0x46a: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_46d:
	/* 0x46d: jb     476 <generic_tracepoint_arg+0x476> */
	X86_SIM_X86_JCC(X86_CC_B, 0x46d, 0x476, x86_l_476);
x86_l_46f:
	/* 0x46f: cmp    edx,DWORD PTR [rax+r13*1+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 28ULL);
x86_l_474:
	/* 0x474: je     443 <generic_tracepoint_arg+0x443> */
	X86_SIM_X86_JCC(X86_CC_E, 0x474, 0x443, x86_l_443);
x86_l_476:
	/* 0x476: or     ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_479:
	/* 0x479: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_47c:
	/* 0x47c: je     4aa <generic_tracepoint_arg+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47c, 0x4aa, x86_l_4aa);
x86_l_47e:
	/* 0x47e: jmp    4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JMP(0x47e, 0x4b5, x86_l_4b5);
x86_l_480:
	/* 0x480: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_483:
	/* 0x483: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_486:
	/* 0x486: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_489:
	/* 0x489: jmp    4a5 <generic_tracepoint_arg+0x4a5> */
	X86_SIM_X86_JMP(0x489, 0x4a5, x86_l_4a5);
x86_l_48b:
	/* 0x48b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48d:
	/* 0x48d: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_490:
	/* 0x490: jmp    4a5 <generic_tracepoint_arg+0x4a5> */
	X86_SIM_X86_JMP(0x490, 0x4a5, x86_l_4a5);
x86_l_492:
	/* 0x492: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_497:
	/* 0x497: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_49a:
	/* 0x49a: jae    4a2 <generic_tracepoint_arg+0x4a2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x49a, 0x4a2, x86_l_4a2);
x86_l_49c:
	/* 0x49c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49f:
	/* 0x49f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_4a2:
	/* 0x4a2: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4a5:
	/* 0x4a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a8:
	/* 0x4a8: je     4b5 <generic_tracepoint_arg+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a8, 0x4b5, x86_l_4b5);
x86_l_4aa:
	/* 0x4aa: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_4ae:
	/* 0x4ae: je     527 <generic_tracepoint_arg+0x527> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ae, 0x527, x86_l_527);
x86_l_4b0:
	/* 0x4b0: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_4b3:
	/* 0x4b3: jne    50a <generic_tracepoint_arg+0x50a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b3, 0x50a, x86_l_50a);
x86_l_4b5:
	/* 0x4b5: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4b9:
	/* 0x4b9: jg     4da <generic_tracepoint_arg+0x4da> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b9, 0x4da, x86_l_4da);
x86_l_4bb:
	/* 0x4bb: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_4bf:
	/* 0x4bf: je     54b <generic_tracepoint_arg+0x54b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bf, 0x54b, x86_l_54b);
x86_l_4c5:
	/* 0x4c5: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_4c8:
	/* 0x4c8: je     558 <generic_tracepoint_arg+0x558> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c8, 0x558, x86_l_558);
x86_l_4ce:
	/* 0x4ce: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4d2:
	/* 0x4d2: je     568 <generic_tracepoint_arg+0x568> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d2, 0x568, x86_l_568);
x86_l_4d8:
	/* 0x4d8: jmp    4f8 <generic_tracepoint_arg+0x4f8> */
	X86_SIM_X86_JMP(0x4d8, 0x4f8, x86_l_4f8);
x86_l_4da:
	/* 0x4da: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_4de:
	/* 0x4de: je     578 <generic_tracepoint_arg+0x578> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4de, 0x578, x86_l_578);
x86_l_4e4:
	/* 0x4e4: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_4e8:
	/* 0x4e8: je     588 <generic_tracepoint_arg+0x588> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e8, 0x588, x86_l_588);
x86_l_4ee:
	/* 0x4ee: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4f2:
	/* 0x4f2: je     598 <generic_tracepoint_arg+0x598> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f2, 0x598, x86_l_598);
x86_l_4f8:
	/* 0x4f8: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4fc:
	/* 0x4fc: jg     5c5 <generic_tracepoint_arg+0x5c5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4fc, 0x5c5, x86_l_5c5);
x86_l_502:
	/* 0x502: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_505:
	/* 0x505: jmp    5a8 <generic_tracepoint_arg+0x5a8> */
	X86_SIM_X86_JMP(0x505, 0x5a8, x86_l_5a8);
x86_l_50a:
	/* 0x50a: mov    DWORD PTR [r14+0x5ef4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_511:
	/* 0x511: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_516:
	/* 0x516: mov    rsi,QWORD PTR [rip+0x4717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_51d:
	/* 0x51d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_520:
	/* 0x520: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_525:
	/* 0x525: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_527:
	/* 0x527: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_52c:
	/* 0x52c: mov    rsi,QWORD PTR [rip+0x4717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_533:
	/* 0x533: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_536:
	/* 0x536: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_53b:
	/* 0x53b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d:
	/* 0x53d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53f:
	/* 0x53f: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_543:
	/* 0x543: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_545:
	/* 0x545: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_546:
	/* 0x546: jmp    60e <generic_tracepoint_arg+0x60e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_54b:
	/* 0x54b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54e:
	/* 0x54e: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_556:
	/* 0x556: jne    5a8 <generic_tracepoint_arg+0x5a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x556, 0x5a8, x86_l_5a8);
x86_l_558:
	/* 0x558: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_55e:
	/* 0x55e: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_566:
	/* 0x566: jne    5a8 <generic_tracepoint_arg+0x5a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x566, 0x5a8, x86_l_5a8);
x86_l_568:
	/* 0x568: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_56e:
	/* 0x56e: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_576:
	/* 0x576: jne    5a8 <generic_tracepoint_arg+0x5a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x576, 0x5a8, x86_l_5a8);
x86_l_578:
	/* 0x578: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_57e:
	/* 0x57e: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_586:
	/* 0x586: jne    5a8 <generic_tracepoint_arg+0x5a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x586, 0x5a8, x86_l_5a8);
x86_l_588:
	/* 0x588: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_58e:
	/* 0x58e: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_596:
	/* 0x596: jne    5a8 <generic_tracepoint_arg+0x5a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x596, 0x5a8, x86_l_5a8);
x86_l_598:
	/* 0x598: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_59e:
	/* 0x59e: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_5a6:
	/* 0x5a6: je     5c5 <generic_tracepoint_arg+0x5c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a6, 0x5c5, x86_l_5c5);
x86_l_5a8:
	/* 0x5a8: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_5af:
	/* 0x5af: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5b4:
	/* 0x5b4: mov    rsi,QWORD PTR [rip+0x471a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_5bb:
	/* 0x5bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5be:
	/* 0x5be: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_5c3:
	/* 0x5c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c5:
	/* 0x5c5: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5c9:
	/* 0x5c9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5ce:
	/* 0x5ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5da:
	/* 0x5da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5df:
	/* 0x5df: mov    rdi,QWORD PTR [rip+0x471a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5e6:
	/* 0x5e6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5eb:
	/* 0x5eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ed:
	/* 0x5ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f0:
	/* 0x5f0: je     53d <generic_tracepoint_arg+0x53d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f0, 0x53d, x86_l_53d);
x86_l_5f6:
	/* 0x5f6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5fb:
	/* 0x5fb: mov    rdi,QWORD PTR [rip+0x471a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_602:
	/* 0x602: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_607:
	/* 0x607: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_609:
	/* 0x609: jmp    53d <generic_tracepoint_arg+0x53d> */
	X86_SIM_X86_JMP(0x609, 0x53d, x86_l_53d);
x86_l_60e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
