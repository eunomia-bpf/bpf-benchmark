extern char argfilter_maps;
extern char filter_map;
extern char kprobe_calls;
extern char process_call_heap;
extern char retprobe_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_kprobe_generic_kprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x12: mov    rdi,QWORD PTR [rip+0x52a7] */
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
	/* 0x28: je     550 <generic_kprobe_filter_arg+0x550> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x550, x86_l_550);
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
	/* 0x42: mov    rdi,QWORD PTR [rip+0x52a7] */
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
	/* 0x53: je     535 <generic_kprobe_filter_arg+0x535> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x535, x86_l_535);
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     535 <generic_kprobe_filter_arg+0x535> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0x535, x86_l_535);
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
	/* 0x76: je     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x4be, x86_l_4be);
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
	/* 0xea: jb     4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_B, 0xea, 0x4af, x86_l_4af);
x86_l_f0:
	/* 0xf0: mov    ecx,DWORD PTR [rax+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_f5:
	/* 0xf5: test   ecx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1023ULL);
x86_l_fb:
	/* 0xfb: je     4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb, 0x4af, x86_l_4af);
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
	/* 0x114: ja     20f <generic_kprobe_filter_arg+0x20f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114, 0x20f, x86_l_20f);
x86_l_11a:
	/* 0x11a: movabs rdx,0x1e10003c12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117469714ULL);
x86_l_124:
	/* 0x124: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_128:
	/* 0x128: jae    20f <generic_kprobe_filter_arg+0x20f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x128, 0x20f, x86_l_20f);
x86_l_12e:
	/* 0x12e: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_132:
	/* 0x132: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_136:
	/* 0x136: ja     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_A, 0x136, 0x4be, x86_l_4be);
x86_l_13c:
	/* 0x13c: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_145:
	/* 0x145: jne    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x145, 0x4be, x86_l_4be);
x86_l_14b:
	/* 0x14b: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_150:
	/* 0x150: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_154:
	/* 0x154: ja     4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_A, 0x154, 0x4af, x86_l_4af);
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
	/* 0x176: jae    243 <generic_kprobe_filter_arg+0x243> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x176, 0x243, x86_l_243);
x86_l_17c:
	/* 0x17c: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_181:
	/* 0x181: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_184:
	/* 0x184: ja     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_A, 0x184, 0x4be, x86_l_4be);
x86_l_18a:
	/* 0x18a: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_18f:
	/* 0x18f: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_192:
	/* 0x192: jae    2e5 <generic_kprobe_filter_arg+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x192, 0x2e5, x86_l_2e5);
x86_l_198:
	/* 0x198: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_19b:
	/* 0x19b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_19e:
	/* 0x19e: jb     364 <generic_kprobe_filter_arg+0x364> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19e, 0x364, x86_l_364);
x86_l_1a4:
	/* 0x1a4: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1a7:
	/* 0x1a7: je     4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a7, 0x4af, x86_l_4af);
x86_l_1ad:
	/* 0x1ad: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b0:
	/* 0x1b0: jne    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b0, 0x4be, x86_l_4be);
x86_l_1b6:
	/* 0x1b6: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_1be:
	/* 0x1be: test   QWORD PTR [rax+r13*1+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_1c3:
	/* 0x1c3: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c3, 0x4af, x86_l_4af);
x86_l_1c9:
	/* 0x1c9: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_1ce:
	/* 0x1ce: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d1:
	/* 0x1d1: jb     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d1, 0x4be, x86_l_4be);
x86_l_1d7:
	/* 0x1d7: test   QWORD PTR [rax+r13*1+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_1dc:
	/* 0x1dc: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1dc, 0x4af, x86_l_4af);
x86_l_1e2:
	/* 0x1e2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1e5:
	/* 0x1e5: jb     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e5, 0x4be, x86_l_4be);
x86_l_1eb:
	/* 0x1eb: test   QWORD PTR [rax+r13*1+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 32ULL);
x86_l_1f0:
	/* 0x1f0: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f0, 0x4af, x86_l_4af);
x86_l_1f6:
	/* 0x1f6: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f9:
	/* 0x1f9: jb     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1f9, 0x4be, x86_l_4be);
x86_l_1ff:
	/* 0x1ff: test   QWORD PTR [rax+r13*1+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 40ULL);
x86_l_204:
	/* 0x204: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x204, 0x4af, x86_l_4af);
x86_l_20a:
	/* 0x20a: jmp    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JMP(0x20a, 0x4be, x86_l_4be);
x86_l_20f:
	/* 0x20f: mov    rsi,QWORD PTR [rip+0x52a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_216:
	/* 0x216: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21b:
	/* 0x21b: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_21e:
	/* 0x21e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_223:
	/* 0x223: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_226:
	/* 0x226: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22b:
	/* 0x22b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d:
	/* 0x22d: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_230:
	/* 0x230: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_234:
	/* 0x234: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_238:
	/* 0x238: jbe    13c <generic_kprobe_filter_arg+0x13c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x238, 0x13c, x86_l_13c);
x86_l_23e:
	/* 0x23e: jmp    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JMP(0x23e, 0x4be, x86_l_4be);
x86_l_243:
	/* 0x243: mov    edx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12306ULL);
x86_l_248:
	/* 0x248: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_24c:
	/* 0x24c: jae    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x24c, 0x4af, x86_l_4af);
x86_l_252:
	/* 0x252: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_257:
	/* 0x257: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25a:
	/* 0x25a: ja     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_A, 0x25a, 0x4be, x86_l_4be);
x86_l_260:
	/* 0x260: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_265:
	/* 0x265: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_268:
	/* 0x268: jae    3bd <generic_kprobe_filter_arg+0x3bd> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x268, 0x3bd, x86_l_3bd);
x86_l_26e:
	/* 0x26e: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_271:
	/* 0x271: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_274:
	/* 0x274: jb     439 <generic_kprobe_filter_arg+0x439> */
	X86_SIM_X86_JCC(X86_CC_B, 0x274, 0x439, x86_l_439);
x86_l_27a:
	/* 0x27a: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_27d:
	/* 0x27d: je     4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27d, 0x4af, x86_l_4af);
x86_l_283:
	/* 0x283: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_286:
	/* 0x286: jne    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x286, 0x4be, x86_l_4be);
x86_l_28c:
	/* 0x28c: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_294:
	/* 0x294: test   DWORD PTR [rax+r13*1+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_299:
	/* 0x299: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x299, 0x4af, x86_l_4af);
x86_l_29f:
	/* 0x29f: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_2a4:
	/* 0x2a4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2a7:
	/* 0x2a7: jb     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2a7, 0x4be, x86_l_4be);
x86_l_2ad:
	/* 0x2ad: test   DWORD PTR [rax+r13*1+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 20ULL);
x86_l_2b2:
	/* 0x2b2: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b2, 0x4af, x86_l_4af);
x86_l_2b8:
	/* 0x2b8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2bb:
	/* 0x2bb: jb     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2bb, 0x4be, x86_l_4be);
x86_l_2c1:
	/* 0x2c1: test   DWORD PTR [rax+r13*1+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_2c6:
	/* 0x2c6: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c6, 0x4af, x86_l_4af);
x86_l_2cc:
	/* 0x2cc: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2cf:
	/* 0x2cf: jb     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2cf, 0x4be, x86_l_4be);
x86_l_2d5:
	/* 0x2d5: test   DWORD PTR [rax+r13*1+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 28ULL);
x86_l_2da:
	/* 0x2da: jne    4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2da, 0x4af, x86_l_4af);
x86_l_2e0:
	/* 0x2e0: jmp    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JMP(0x2e0, 0x4be, x86_l_4be);
x86_l_2e5:
	/* 0x2e5: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_2ea:
	/* 0x2ea: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2ed:
	/* 0x2ed: jae    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2ed, 0x4be, x86_l_4be);
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f8:
	/* 0x2f8: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_2fe:
	/* 0x2fe: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_302:
	/* 0x302: mov    rdi,QWORD PTR [rip+0x52a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_309:
	/* 0x309: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30e:
	/* 0x30e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_313:
	/* 0x313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315:
	/* 0x315: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_318:
	/* 0x318: je     435 <generic_kprobe_filter_arg+0x435> */
	X86_SIM_X86_JCC(X86_CC_E, 0x318, 0x435, x86_l_435);
x86_l_31e:
	/* 0x31e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_321:
	/* 0x321: mov    rax,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_329:
	/* 0x329: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e:
	/* 0x32e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_333:
	/* 0x333: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_338:
	/* 0x338: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a:
	/* 0x33a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f:
	/* 0x33f: mov    ecx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_344:
	/* 0x344: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_347:
	/* 0x347: je     485 <generic_kprobe_filter_arg+0x485> */
	X86_SIM_X86_JCC(X86_CC_E, 0x347, 0x485, x86_l_485);
x86_l_34d:
	/* 0x34d: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_350:
	/* 0x350: jne    490 <generic_kprobe_filter_arg+0x490> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x350, 0x490, x86_l_490);
x86_l_356:
	/* 0x356: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_359:
	/* 0x359: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_35c:
	/* 0x35c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_35f:
	/* 0x35f: jmp    4aa <generic_kprobe_filter_arg+0x4aa> */
	X86_SIM_X86_JMP(0x35f, 0x4aa, x86_l_4aa);
x86_l_364:
	/* 0x364: mov    rdx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_36c:
	/* 0x36c: cmp    rdx,QWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 16ULL);
x86_l_371:
	/* 0x371: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x371, 0x448, x86_l_448);
x86_l_377:
	/* 0x377: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_37c:
	/* 0x37c: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_37f:
	/* 0x37f: jb     47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x37f, 0x47b, x86_l_47b);
x86_l_385:
	/* 0x385: cmp    rdx,QWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 24ULL);
x86_l_38a:
	/* 0x38a: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38a, 0x448, x86_l_448);
x86_l_390:
	/* 0x390: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_393:
	/* 0x393: jb     47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x393, 0x47b, x86_l_47b);
x86_l_399:
	/* 0x399: cmp    rdx,QWORD PTR [rax+r13*1+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 32ULL);
x86_l_39e:
	/* 0x39e: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39e, 0x448, x86_l_448);
x86_l_3a4:
	/* 0x3a4: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_3a7:
	/* 0x3a7: jb     47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3a7, 0x47b, x86_l_47b);
x86_l_3ad:
	/* 0x3ad: cmp    rdx,QWORD PTR [rax+r13*1+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 40ULL);
x86_l_3b2:
	/* 0x3b2: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b2, 0x448, x86_l_448);
x86_l_3b8:
	/* 0x3b8: jmp    47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JMP(0x3b8, 0x47b, x86_l_47b);
x86_l_3bd:
	/* 0x3bd: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_3c2:
	/* 0x3c2: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3c5:
	/* 0x3c5: jae    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3c5, 0x4be, x86_l_4be);
x86_l_3cb:
	/* 0x3cb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0:
	/* 0x3d0: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_3d6:
	/* 0x3d6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3da:
	/* 0x3da: mov    rdi,QWORD PTR [rip+0x52a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_3e1:
	/* 0x3e1: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e6:
	/* 0x3e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3eb:
	/* 0x3eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed:
	/* 0x3ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f0:
	/* 0x3f0: je     435 <generic_kprobe_filter_arg+0x435> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f0, 0x435, x86_l_435);
x86_l_3f2:
	/* 0x3f2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3f5:
	/* 0x3f5: mov    eax,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_3fd:
	/* 0x3fd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_402:
	/* 0x402: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_407:
	/* 0x407: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40c:
	/* 0x40c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40e:
	/* 0x40e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_413:
	/* 0x413: mov    edx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_418:
	/* 0x418: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41a:
	/* 0x41a: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_41d:
	/* 0x41d: ja     4a7 <generic_kprobe_filter_arg+0x4a7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x41d, 0x4a7, x86_l_4a7);
x86_l_423:
	/* 0x423: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_428:
	/* 0x428: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_42b:
	/* 0x42b: jae    497 <generic_kprobe_filter_arg+0x497> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x42b, 0x497, x86_l_497);
x86_l_42d:
	/* 0x42d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_430:
	/* 0x430: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_433:
	/* 0x433: jmp    4a7 <generic_kprobe_filter_arg+0x4a7> */
	X86_SIM_X86_JMP(0x433, 0x4a7, x86_l_4a7);
x86_l_435:
	/* 0x435: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_437:
	/* 0x437: jmp    4aa <generic_kprobe_filter_arg+0x4aa> */
	X86_SIM_X86_JMP(0x437, 0x4aa, x86_l_4aa);
x86_l_439:
	/* 0x439: mov    edx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_441:
	/* 0x441: cmp    edx,DWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 16ULL);
x86_l_446:
	/* 0x446: jne    452 <generic_kprobe_filter_arg+0x452> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x446, 0x452, x86_l_452);
x86_l_448:
	/* 0x448: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44a:
	/* 0x44a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_44d:
	/* 0x44d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_450:
	/* 0x450: jmp    4aa <generic_kprobe_filter_arg+0x4aa> */
	X86_SIM_X86_JMP(0x450, 0x4aa, x86_l_4aa);
x86_l_452:
	/* 0x452: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_457:
	/* 0x457: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_45a:
	/* 0x45a: jb     47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x45a, 0x47b, x86_l_47b);
x86_l_45c:
	/* 0x45c: cmp    edx,DWORD PTR [rax+r13*1+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 20ULL);
x86_l_461:
	/* 0x461: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x461, 0x448, x86_l_448);
x86_l_463:
	/* 0x463: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_466:
	/* 0x466: jb     47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x466, 0x47b, x86_l_47b);
x86_l_468:
	/* 0x468: cmp    edx,DWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 24ULL);
x86_l_46d:
	/* 0x46d: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46d, 0x448, x86_l_448);
x86_l_46f:
	/* 0x46f: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_472:
	/* 0x472: jb     47b <generic_kprobe_filter_arg+0x47b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x472, 0x47b, x86_l_47b);
x86_l_474:
	/* 0x474: cmp    edx,DWORD PTR [rax+r13*1+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 28ULL);
x86_l_479:
	/* 0x479: je     448 <generic_kprobe_filter_arg+0x448> */
	X86_SIM_X86_JCC(X86_CC_E, 0x479, 0x448, x86_l_448);
x86_l_47b:
	/* 0x47b: or     ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_47e:
	/* 0x47e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_481:
	/* 0x481: je     4af <generic_kprobe_filter_arg+0x4af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x481, 0x4af, x86_l_4af);
x86_l_483:
	/* 0x483: jmp    4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JMP(0x483, 0x4be, x86_l_4be);
x86_l_485:
	/* 0x485: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_488:
	/* 0x488: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_48b:
	/* 0x48b: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_48e:
	/* 0x48e: jmp    4aa <generic_kprobe_filter_arg+0x4aa> */
	X86_SIM_X86_JMP(0x48e, 0x4aa, x86_l_4aa);
x86_l_490:
	/* 0x490: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_492:
	/* 0x492: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_495:
	/* 0x495: jmp    4aa <generic_kprobe_filter_arg+0x4aa> */
	X86_SIM_X86_JMP(0x495, 0x4aa, x86_l_4aa);
x86_l_497:
	/* 0x497: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_49c:
	/* 0x49c: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_49f:
	/* 0x49f: jae    4a7 <generic_kprobe_filter_arg+0x4a7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x49f, 0x4a7, x86_l_4a7);
x86_l_4a1:
	/* 0x4a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a4:
	/* 0x4a4: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_4a7:
	/* 0x4a7: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4aa:
	/* 0x4aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ad:
	/* 0x4ad: je     4be <generic_kprobe_filter_arg+0x4be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ad, 0x4be, x86_l_4be);
x86_l_4af:
	/* 0x4af: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_4b3:
	/* 0x4b3: je     535 <generic_kprobe_filter_arg+0x535> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b3, 0x535, x86_l_535);
x86_l_4b9:
	/* 0x4b9: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_4bc:
	/* 0x4bc: jne    513 <generic_kprobe_filter_arg+0x513> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4bc, 0x513, x86_l_513);
x86_l_4be:
	/* 0x4be: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4c2:
	/* 0x4c2: jg     4e3 <generic_kprobe_filter_arg+0x4e3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4c2, 0x4e3, x86_l_4e3);
x86_l_4c4:
	/* 0x4c4: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_4c8:
	/* 0x4c8: je     55e <generic_kprobe_filter_arg+0x55e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c8, 0x55e, x86_l_55e);
x86_l_4ce:
	/* 0x4ce: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_4d1:
	/* 0x4d1: je     56b <generic_kprobe_filter_arg+0x56b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d1, 0x56b, x86_l_56b);
x86_l_4d7:
	/* 0x4d7: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4db:
	/* 0x4db: je     57b <generic_kprobe_filter_arg+0x57b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4db, 0x57b, x86_l_57b);
x86_l_4e1:
	/* 0x4e1: jmp    501 <generic_kprobe_filter_arg+0x501> */
	X86_SIM_X86_JMP(0x4e1, 0x501, x86_l_501);
x86_l_4e3:
	/* 0x4e3: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_4e7:
	/* 0x4e7: je     58b <generic_kprobe_filter_arg+0x58b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e7, 0x58b, x86_l_58b);
x86_l_4ed:
	/* 0x4ed: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_4f1:
	/* 0x4f1: je     59b <generic_kprobe_filter_arg+0x59b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f1, 0x59b, x86_l_59b);
x86_l_4f7:
	/* 0x4f7: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4fb:
	/* 0x4fb: je     5ab <generic_kprobe_filter_arg+0x5ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4fb, 0x5ab, x86_l_5ab);
x86_l_501:
	/* 0x501: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_505:
	/* 0x505: jg     5dd <generic_kprobe_filter_arg+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_G, 0x505, 0x5dd, x86_l_5dd);
x86_l_50b:
	/* 0x50b: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_50e:
	/* 0x50e: jmp    5bb <generic_kprobe_filter_arg+0x5bb> */
	X86_SIM_X86_JMP(0x50e, 0x5bb, x86_l_5bb);
x86_l_513:
	/* 0x513: mov    DWORD PTR [r14+0x5ef4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_51a:
	/* 0x51a: mov    rsi,QWORD PTR [rip+0x52a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_521:
	/* 0x521: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_526:
	/* 0x526: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_52b:
	/* 0x52b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_533:
	/* 0x533: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_535:
	/* 0x535: mov    rsi,QWORD PTR [rip+0x52a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_53c:
	/* 0x53c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_541:
	/* 0x541: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_546:
	/* 0x546: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_549:
	/* 0x549: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_54e:
	/* 0x54e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_550:
	/* 0x550: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_552:
	/* 0x552: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_556:
	/* 0x556: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_558:
	/* 0x558: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_559:
	/* 0x559: jmp    626 <generic_kprobe_filter_arg+0x626> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_55e:
	/* 0x55e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_561:
	/* 0x561: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_569:
	/* 0x569: jne    5bb <generic_kprobe_filter_arg+0x5bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x569, 0x5bb, x86_l_5bb);
x86_l_56b:
	/* 0x56b: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_571:
	/* 0x571: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_579:
	/* 0x579: jne    5bb <generic_kprobe_filter_arg+0x5bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x579, 0x5bb, x86_l_5bb);
x86_l_57b:
	/* 0x57b: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_581:
	/* 0x581: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_589:
	/* 0x589: jne    5bb <generic_kprobe_filter_arg+0x5bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x589, 0x5bb, x86_l_5bb);
x86_l_58b:
	/* 0x58b: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_591:
	/* 0x591: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_599:
	/* 0x599: jne    5bb <generic_kprobe_filter_arg+0x5bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x599, 0x5bb, x86_l_5bb);
x86_l_59b:
	/* 0x59b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_5a1:
	/* 0x5a1: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_5a9:
	/* 0x5a9: jne    5bb <generic_kprobe_filter_arg+0x5bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a9, 0x5bb, x86_l_5bb);
x86_l_5ab:
	/* 0x5ab: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_5b1:
	/* 0x5b1: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_5b9:
	/* 0x5b9: je     5dd <generic_kprobe_filter_arg+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b9, 0x5dd, x86_l_5dd);
x86_l_5bb:
	/* 0x5bb: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_5c2:
	/* 0x5c2: mov    rsi,QWORD PTR [rip+0x52a6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_5c9:
	/* 0x5c9: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5ce:
	/* 0x5ce: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5d3:
	/* 0x5d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5d6:
	/* 0x5d6: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_5db:
	/* 0x5db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dd:
	/* 0x5dd: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5e1:
	/* 0x5e1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5e6:
	/* 0x5e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e8:
	/* 0x5e8: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ed:
	/* 0x5ed: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f2:
	/* 0x5f2: mov    rdi,QWORD PTR [rip+0x52a6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_5f9:
	/* 0x5f9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fe:
	/* 0x5fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_603:
	/* 0x603: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_605:
	/* 0x605: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_608:
	/* 0x608: je     550 <generic_kprobe_filter_arg+0x550> */
	X86_SIM_X86_JCC(X86_CC_E, 0x608, 0x550, x86_l_550);
x86_l_60e:
	/* 0x60e: mov    rdi,QWORD PTR [rip+0x52a6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_615:
	/* 0x615: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61a:
	/* 0x61a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_61f:
	/* 0x61f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_621:
	/* 0x621: jmp    550 <generic_kprobe_filter_arg+0x550> */
	X86_SIM_X86_JMP(0x621, 0x550, x86_l_550);
x86_l_626:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
