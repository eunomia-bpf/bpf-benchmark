extern char argfilter_maps;
extern char filter_map;
extern char process_call_heap;
extern char retprobe_map;
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_generic_usdt_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x19: mov    rdi,QWORD PTR [rip+0x6800] */
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
	/* 0x2f: je     557 <generic_usdt_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f, 0x557, x86_l_557);
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
	/* 0x49: mov    rdi,QWORD PTR [rip+0x6800] */
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
	/* 0x5a: je     53c <generic_usdt_filter_arg+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a, 0x53c, x86_l_53c);
x86_l_60:
	/* 0x60: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_68:
	/* 0x68: je     53c <generic_usdt_filter_arg+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0x53c, x86_l_53c);
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
	/* 0x7d: je     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d, 0x4c5, x86_l_4c5);
x86_l_83:
	/* 0x83: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_89:
	/* 0x89: lea    rsi,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8d:
	/* 0x8d: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_91:
	/* 0x91: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_95:
	/* 0x95: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_99:
	/* 0x99: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9f:
	/* 0x9f: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a2:
	/* 0xa2: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a5:
	/* 0xa5: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a9:
	/* 0xa9: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_ab:
	/* 0xab: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b1:
	/* 0xb1: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b4:
	/* 0xb4: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b7:
	/* 0xb7: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_b9:
	/* 0xb9: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_bf:
	/* 0xbf: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c2:
	/* 0xc2: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c5:
	/* 0xc5: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c7:
	/* 0xc7: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_cd:
	/* 0xcd: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d0:
	/* 0xd0: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d3:
	/* 0xd3: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_d5:
	/* 0xd5: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_db:
	/* 0xdb: mov    r13d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_df:
	/* 0xdf: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e2:
	/* 0xe2: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_e5:
	/* 0xe5: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ec:
	/* 0xec: cmp    DWORD PTR [rax+r12*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 25ULL);
x86_l_f1:
	/* 0xf1: jb     4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_B, 0xf1, 0x4b6, x86_l_4b6);
x86_l_f7:
	/* 0xf7: mov    ecx,DWORD PTR [rax+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_fc:
	/* 0xfc: test   ecx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1023ULL);
x86_l_102:
	/* 0x102: je     4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x102, 0x4b6, x86_l_4b6);
x86_l_108:
	/* 0x108: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10b:
	/* 0x10b: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_112:
	/* 0x112: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_117:
	/* 0x117: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_11b:
	/* 0x11b: ja     216 <generic_usdt_filter_arg+0x216> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11b, 0x216, x86_l_216);
x86_l_121:
	/* 0x121: movabs rdx,0x1e10003c12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117469714ULL);
x86_l_12b:
	/* 0x12b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: jae    216 <generic_usdt_filter_arg+0x216> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x12f, 0x216, x86_l_216);
x86_l_135:
	/* 0x135: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_139:
	/* 0x139: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_13d:
	/* 0x13d: ja     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13d, 0x4c5, x86_l_4c5);
x86_l_143:
	/* 0x143: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_14c:
	/* 0x14c: jne    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14c, 0x4c5, x86_l_4c5);
x86_l_152:
	/* 0x152: mov    ecx,DWORD PTR [rax+r13*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 12ULL);
x86_l_157:
	/* 0x157: cmp    rcx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 36ULL);
x86_l_15b:
	/* 0x15b: ja     4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x15b, 0x4b6, x86_l_4b6);
x86_l_161:
	/* 0x161: mov    rbp,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_169:
	/* 0x169: movabs rdx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 129117457408ULL);
x86_l_173:
	/* 0x173: and    ebp,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_179:
	/* 0x179: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_17d:
	/* 0x17d: jae    24a <generic_usdt_filter_arg+0x24a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x17d, 0x24a, x86_l_24a);
x86_l_183:
	/* 0x183: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_188:
	/* 0x188: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_18b:
	/* 0x18b: ja     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x18b, 0x4c5, x86_l_4c5);
x86_l_191:
	/* 0x191: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_196:
	/* 0x196: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_199:
	/* 0x199: jae    2ec <generic_usdt_filter_arg+0x2ec> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x199, 0x2ec, x86_l_2ec);
x86_l_19f:
	/* 0x19f: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1a2:
	/* 0x1a2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1a5:
	/* 0x1a5: jb     36b <generic_usdt_filter_arg+0x36b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a5, 0x36b, x86_l_36b);
x86_l_1ab:
	/* 0x1ab: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1ae:
	/* 0x1ae: je     4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ae, 0x4b6, x86_l_4b6);
x86_l_1b4:
	/* 0x1b4: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b7:
	/* 0x1b7: jne    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b7, 0x4c5, x86_l_4c5);
x86_l_1bd:
	/* 0x1bd: mov    rcx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_1c5:
	/* 0x1c5: test   QWORD PTR [rax+r13*1+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_1ca:
	/* 0x1ca: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ca, 0x4b6, x86_l_4b6);
x86_l_1d0:
	/* 0x1d0: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_1d5:
	/* 0x1d5: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d8:
	/* 0x1d8: jb     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d8, 0x4c5, x86_l_4c5);
x86_l_1de:
	/* 0x1de: test   QWORD PTR [rax+r13*1+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_1e3:
	/* 0x1e3: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e3, 0x4b6, x86_l_4b6);
x86_l_1e9:
	/* 0x1e9: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ec:
	/* 0x1ec: jb     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ec, 0x4c5, x86_l_4c5);
x86_l_1f2:
	/* 0x1f2: test   QWORD PTR [rax+r13*1+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 32ULL);
x86_l_1f7:
	/* 0x1f7: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f7, 0x4b6, x86_l_4b6);
x86_l_1fd:
	/* 0x1fd: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_200:
	/* 0x200: jb     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x200, 0x4c5, x86_l_4c5);
x86_l_206:
	/* 0x206: test   QWORD PTR [rax+r13*1+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 40ULL);
x86_l_20b:
	/* 0x20b: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20b, 0x4b6, x86_l_4b6);
x86_l_211:
	/* 0x211: jmp    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JMP(0x211, 0x4c5, x86_l_4c5);
x86_l_216:
	/* 0x216: mov    rsi,QWORD PTR [rip+0x6800] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_21d:
	/* 0x21d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_222:
	/* 0x222: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_225:
	/* 0x225: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_22a:
	/* 0x22a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_232:
	/* 0x232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234:
	/* 0x234: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_237:
	/* 0x237: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_23b:
	/* 0x23b: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_23f:
	/* 0x23f: jbe    143 <generic_usdt_filter_arg+0x143> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x23f, 0x143, x86_l_143);
x86_l_245:
	/* 0x245: jmp    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JMP(0x245, 0x4c5, x86_l_4c5);
x86_l_24a:
	/* 0x24a: mov    edx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12306ULL);
x86_l_24f:
	/* 0x24f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_253:
	/* 0x253: jae    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x253, 0x4b6, x86_l_4b6);
x86_l_259:
	/* 0x259: mov    ecx,DWORD PTR [rax+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_25e:
	/* 0x25e: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_261:
	/* 0x261: ja     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x261, 0x4c5, x86_l_4c5);
x86_l_267:
	/* 0x267: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_26c:
	/* 0x26c: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_26f:
	/* 0x26f: jae    3c4 <generic_usdt_filter_arg+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x26f, 0x3c4, x86_l_3c4);
x86_l_275:
	/* 0x275: lea    edx,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_278:
	/* 0x278: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_27b:
	/* 0x27b: jb     440 <generic_usdt_filter_arg+0x440> */
	X86_SIM_X86_JCC(X86_CC_B, 0x27b, 0x440, x86_l_440);
x86_l_281:
	/* 0x281: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_284:
	/* 0x284: je     4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x284, 0x4b6, x86_l_4b6);
x86_l_28a:
	/* 0x28a: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_28d:
	/* 0x28d: jne    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x28d, 0x4c5, x86_l_4c5);
x86_l_293:
	/* 0x293: mov    ecx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_29b:
	/* 0x29b: test   DWORD PTR [rax+r13*1+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 16ULL);
x86_l_2a0:
	/* 0x2a0: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a0, 0x4b6, x86_l_4b6);
x86_l_2a6:
	/* 0x2a6: mov    edx,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_2ab:
	/* 0x2ab: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2ae:
	/* 0x2ae: jb     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2ae, 0x4c5, x86_l_4c5);
x86_l_2b4:
	/* 0x2b4: test   DWORD PTR [rax+r13*1+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 20ULL);
x86_l_2b9:
	/* 0x2b9: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b9, 0x4b6, x86_l_4b6);
x86_l_2bf:
	/* 0x2bf: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2c2:
	/* 0x2c2: jb     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2c2, 0x4c5, x86_l_4c5);
x86_l_2c8:
	/* 0x2c8: test   DWORD PTR [rax+r13*1+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 24ULL);
x86_l_2cd:
	/* 0x2cd: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2cd, 0x4b6, x86_l_4b6);
x86_l_2d3:
	/* 0x2d3: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2d6:
	/* 0x2d6: jb     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2d6, 0x4c5, x86_l_4c5);
x86_l_2dc:
	/* 0x2dc: test   DWORD PTR [rax+r13*1+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 28ULL);
x86_l_2e1:
	/* 0x2e1: jne    4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e1, 0x4b6, x86_l_4b6);
x86_l_2e7:
	/* 0x2e7: jmp    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JMP(0x2e7, 0x4c5, x86_l_4c5);
x86_l_2ec:
	/* 0x2ec: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_2f1:
	/* 0x2f1: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2f4:
	/* 0x2f4: jae    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2f4, 0x4c5, x86_l_4c5);
x86_l_2fa:
	/* 0x2fa: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ff:
	/* 0x2ff: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_305:
	/* 0x305: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_309:
	/* 0x309: mov    rdi,QWORD PTR [rip+0x6800] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_310:
	/* 0x310: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_315:
	/* 0x315: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31a:
	/* 0x31a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c:
	/* 0x31c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31f:
	/* 0x31f: je     43c <generic_usdt_filter_arg+0x43c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31f, 0x43c, x86_l_43c);
x86_l_325:
	/* 0x325: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_328:
	/* 0x328: mov    rax,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_330:
	/* 0x330: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_335:
	/* 0x335: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33a:
	/* 0x33a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33f:
	/* 0x33f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341:
	/* 0x341: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_346:
	/* 0x346: mov    ecx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_34b:
	/* 0x34b: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_34e:
	/* 0x34e: je     48c <generic_usdt_filter_arg+0x48c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34e, 0x48c, x86_l_48c);
x86_l_354:
	/* 0x354: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_357:
	/* 0x357: jne    497 <generic_usdt_filter_arg+0x497> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x357, 0x497, x86_l_497);
x86_l_35d:
	/* 0x35d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_360:
	/* 0x360: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_363:
	/* 0x363: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_366:
	/* 0x366: jmp    4b1 <generic_usdt_filter_arg+0x4b1> */
	X86_SIM_X86_JMP(0x366, 0x4b1, x86_l_4b1);
x86_l_36b:
	/* 0x36b: mov    rdx,QWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_373:
	/* 0x373: cmp    rdx,QWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 16ULL);
x86_l_378:
	/* 0x378: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x378, 0x44f, x86_l_44f);
x86_l_37e:
	/* 0x37e: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_383:
	/* 0x383: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_386:
	/* 0x386: jb     482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JCC(X86_CC_B, 0x386, 0x482, x86_l_482);
x86_l_38c:
	/* 0x38c: cmp    rdx,QWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 24ULL);
x86_l_391:
	/* 0x391: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x391, 0x44f, x86_l_44f);
x86_l_397:
	/* 0x397: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_39a:
	/* 0x39a: jb     482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JCC(X86_CC_B, 0x39a, 0x482, x86_l_482);
x86_l_3a0:
	/* 0x3a0: cmp    rdx,QWORD PTR [rax+r13*1+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 32ULL);
x86_l_3a5:
	/* 0x3a5: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a5, 0x44f, x86_l_44f);
x86_l_3ab:
	/* 0x3ab: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_3ae:
	/* 0x3ae: jb     482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3ae, 0x482, x86_l_482);
x86_l_3b4:
	/* 0x3b4: cmp    rdx,QWORD PTR [rax+r13*1+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_64), 40ULL);
x86_l_3b9:
	/* 0x3b9: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b9, 0x44f, x86_l_44f);
x86_l_3bf:
	/* 0x3bf: jmp    482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JMP(0x3bf, 0x482, x86_l_482);
x86_l_3c4:
	/* 0x3c4: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_3c9:
	/* 0x3c9: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3cc:
	/* 0x3cc: jae    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3cc, 0x4c5, x86_l_4c5);
x86_l_3d2:
	/* 0x3d2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d7:
	/* 0x3d7: movzx  eax,BYTE PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 16ULL);
x86_l_3dd:
	/* 0x3dd: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e1:
	/* 0x3e1: mov    rdi,QWORD PTR [rip+0x6800] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_3e8:
	/* 0x3e8: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ed:
	/* 0x3ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f2:
	/* 0x3f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f4:
	/* 0x3f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f7:
	/* 0x3f7: je     43c <generic_usdt_filter_arg+0x43c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f7, 0x43c, x86_l_43c);
x86_l_3f9:
	/* 0x3f9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3fc:
	/* 0x3fc: mov    eax,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_404:
	/* 0x404: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_409:
	/* 0x409: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40e:
	/* 0x40e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_413:
	/* 0x413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_415:
	/* 0x415: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a:
	/* 0x41a: mov    edx,DWORD PTR [rcx+r13*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_41f:
	/* 0x41f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_421:
	/* 0x421: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_424:
	/* 0x424: ja     4ae <generic_usdt_filter_arg+0x4ae> */
	X86_SIM_X86_JCC(X86_CC_A, 0x424, 0x4ae, x86_l_4ae);
x86_l_42a:
	/* 0x42a: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_42f:
	/* 0x42f: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_432:
	/* 0x432: jae    49e <generic_usdt_filter_arg+0x49e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x432, 0x49e, x86_l_49e);
x86_l_434:
	/* 0x434: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_437:
	/* 0x437: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_43a:
	/* 0x43a: jmp    4ae <generic_usdt_filter_arg+0x4ae> */
	X86_SIM_X86_JMP(0x43a, 0x4ae, x86_l_4ae);
x86_l_43c:
	/* 0x43c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43e:
	/* 0x43e: jmp    4b1 <generic_usdt_filter_arg+0x4b1> */
	X86_SIM_X86_JMP(0x43e, 0x4b1, x86_l_4b1);
x86_l_440:
	/* 0x440: mov    edx,DWORD PTR [r14+rbp*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_448:
	/* 0x448: cmp    edx,DWORD PTR [rax+r13*1+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 16ULL);
x86_l_44d:
	/* 0x44d: jne    459 <generic_usdt_filter_arg+0x459> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x44d, 0x459, x86_l_459);
x86_l_44f:
	/* 0x44f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_451:
	/* 0x451: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_454:
	/* 0x454: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_457:
	/* 0x457: jmp    4b1 <generic_usdt_filter_arg+0x4b1> */
	X86_SIM_X86_JMP(0x457, 0x4b1, x86_l_4b1);
x86_l_459:
	/* 0x459: mov    esi,DWORD PTR [rax+r13*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_45e:
	/* 0x45e: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_461:
	/* 0x461: jb     482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JCC(X86_CC_B, 0x461, 0x482, x86_l_482);
x86_l_463:
	/* 0x463: cmp    edx,DWORD PTR [rax+r13*1+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 20ULL);
x86_l_468:
	/* 0x468: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x468, 0x44f, x86_l_44f);
x86_l_46a:
	/* 0x46a: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_46d:
	/* 0x46d: jb     482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JCC(X86_CC_B, 0x46d, 0x482, x86_l_482);
x86_l_46f:
	/* 0x46f: cmp    edx,DWORD PTR [rax+r13*1+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 24ULL);
x86_l_474:
	/* 0x474: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x474, 0x44f, x86_l_44f);
x86_l_476:
	/* 0x476: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_479:
	/* 0x479: jb     482 <generic_usdt_filter_arg+0x482> */
	X86_SIM_X86_JCC(X86_CC_B, 0x479, 0x482, x86_l_482);
x86_l_47b:
	/* 0x47b: cmp    edx,DWORD PTR [rax+r13*1+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_32), 28ULL);
x86_l_480:
	/* 0x480: je     44f <generic_usdt_filter_arg+0x44f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x480, 0x44f, x86_l_44f);
x86_l_482:
	/* 0x482: or     ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_485:
	/* 0x485: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_488:
	/* 0x488: je     4b6 <generic_usdt_filter_arg+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x488, 0x4b6, x86_l_4b6);
x86_l_48a:
	/* 0x48a: jmp    4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JMP(0x48a, 0x4c5, x86_l_4c5);
x86_l_48c:
	/* 0x48c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48f:
	/* 0x48f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_492:
	/* 0x492: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_495:
	/* 0x495: jmp    4b1 <generic_usdt_filter_arg+0x4b1> */
	X86_SIM_X86_JMP(0x495, 0x4b1, x86_l_4b1);
x86_l_497:
	/* 0x497: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_499:
	/* 0x499: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_49c:
	/* 0x49c: jmp    4b1 <generic_usdt_filter_arg+0x4b1> */
	X86_SIM_X86_JMP(0x49c, 0x4b1, x86_l_4b1);
x86_l_49e:
	/* 0x49e: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_4a3:
	/* 0x4a3: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_4a6:
	/* 0x4a6: jae    4ae <generic_usdt_filter_arg+0x4ae> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x4a6, 0x4ae, x86_l_4ae);
x86_l_4a8:
	/* 0x4a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ab:
	/* 0x4ab: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_4ae:
	/* 0x4ae: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4b1:
	/* 0x4b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b4:
	/* 0x4b4: je     4c5 <generic_usdt_filter_arg+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b4, 0x4c5, x86_l_4c5);
x86_l_4b6:
	/* 0x4b6: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_4ba:
	/* 0x4ba: je     53c <generic_usdt_filter_arg+0x53c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ba, 0x53c, x86_l_53c);
x86_l_4c0:
	/* 0x4c0: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_4c3:
	/* 0x4c3: jne    51a <generic_usdt_filter_arg+0x51a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4c3, 0x51a, x86_l_51a);
x86_l_4c5:
	/* 0x4c5: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4c9:
	/* 0x4c9: jg     4ea <generic_usdt_filter_arg+0x4ea> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4c9, 0x4ea, x86_l_4ea);
x86_l_4cb:
	/* 0x4cb: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_4cf:
	/* 0x4cf: je     56c <generic_usdt_filter_arg+0x56c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cf, 0x56c, x86_l_56c);
x86_l_4d5:
	/* 0x4d5: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_4d8:
	/* 0x4d8: je     579 <generic_usdt_filter_arg+0x579> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d8, 0x579, x86_l_579);
x86_l_4de:
	/* 0x4de: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4e2:
	/* 0x4e2: je     589 <generic_usdt_filter_arg+0x589> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e2, 0x589, x86_l_589);
x86_l_4e8:
	/* 0x4e8: jmp    508 <generic_usdt_filter_arg+0x508> */
	X86_SIM_X86_JMP(0x4e8, 0x508, x86_l_508);
x86_l_4ea:
	/* 0x4ea: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_4ee:
	/* 0x4ee: je     599 <generic_usdt_filter_arg+0x599> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ee, 0x599, x86_l_599);
x86_l_4f4:
	/* 0x4f4: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_4f8:
	/* 0x4f8: je     5a9 <generic_usdt_filter_arg+0x5a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f8, 0x5a9, x86_l_5a9);
x86_l_4fe:
	/* 0x4fe: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_502:
	/* 0x502: je     5b9 <generic_usdt_filter_arg+0x5b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x502, 0x5b9, x86_l_5b9);
x86_l_508:
	/* 0x508: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_50c:
	/* 0x50c: jg     5eb <generic_usdt_filter_arg+0x5eb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x50c, 0x5eb, x86_l_5eb);
x86_l_512:
	/* 0x512: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_515:
	/* 0x515: jmp    5c9 <generic_usdt_filter_arg+0x5c9> */
	X86_SIM_X86_JMP(0x515, 0x5c9, x86_l_5c9);
x86_l_51a:
	/* 0x51a: mov    DWORD PTR [r14+0x5ef4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_521:
	/* 0x521: mov    rsi,QWORD PTR [rip+0x67fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_528:
	/* 0x528: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_52d:
	/* 0x52d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_532:
	/* 0x532: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_535:
	/* 0x535: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_53a:
	/* 0x53a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53c:
	/* 0x53c: mov    rsi,QWORD PTR [rip+0x67fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_543:
	/* 0x543: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_548:
	/* 0x548: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_54d:
	/* 0x54d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_550:
	/* 0x550: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_555:
	/* 0x555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_557:
	/* 0x557: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_559:
	/* 0x559: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_55d:
	/* 0x55d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_560:
	/* 0x560: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_562:
	/* 0x562: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_564:
	/* 0x564: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_566:
	/* 0x566: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_567:
	/* 0x567: jmp    634 <generic_usdt_filter_arg+0x634> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_56c:
	/* 0x56c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56f:
	/* 0x56f: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_577:
	/* 0x577: jne    5c9 <generic_usdt_filter_arg+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x577, 0x5c9, x86_l_5c9);
x86_l_579:
	/* 0x579: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_57f:
	/* 0x57f: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_587:
	/* 0x587: jne    5c9 <generic_usdt_filter_arg+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x587, 0x5c9, x86_l_5c9);
x86_l_589:
	/* 0x589: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_58f:
	/* 0x58f: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_597:
	/* 0x597: jne    5c9 <generic_usdt_filter_arg+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x597, 0x5c9, x86_l_5c9);
x86_l_599:
	/* 0x599: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_59f:
	/* 0x59f: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_5a7:
	/* 0x5a7: jne    5c9 <generic_usdt_filter_arg+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a7, 0x5c9, x86_l_5c9);
x86_l_5a9:
	/* 0x5a9: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_5af:
	/* 0x5af: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_5b7:
	/* 0x5b7: jne    5c9 <generic_usdt_filter_arg+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b7, 0x5c9, x86_l_5c9);
x86_l_5b9:
	/* 0x5b9: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_5bf:
	/* 0x5bf: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_5c7:
	/* 0x5c7: je     5eb <generic_usdt_filter_arg+0x5eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c7, 0x5eb, x86_l_5eb);
x86_l_5c9:
	/* 0x5c9: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_5d0:
	/* 0x5d0: mov    rsi,QWORD PTR [rip+0x67f8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_5d7:
	/* 0x5d7: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5dc:
	/* 0x5dc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5e1:
	/* 0x5e1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e4:
	/* 0x5e4: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_5e9:
	/* 0x5e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5eb:
	/* 0x5eb: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5ef:
	/* 0x5ef: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5f4:
	/* 0x5f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f6:
	/* 0x5f6: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fb:
	/* 0x5fb: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_600:
	/* 0x600: mov    rdi,QWORD PTR [rip+0x67f8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_607:
	/* 0x607: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60c:
	/* 0x60c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_611:
	/* 0x611: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_613:
	/* 0x613: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_616:
	/* 0x616: je     557 <generic_usdt_filter_arg+0x557> */
	X86_SIM_X86_JCC(X86_CC_E, 0x616, 0x557, x86_l_557);
x86_l_61c:
	/* 0x61c: mov    rdi,QWORD PTR [rip+0x67f8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_623:
	/* 0x623: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_628:
	/* 0x628: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_62d:
	/* 0x62d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62f:
	/* 0x62f: jmp    557 <generic_usdt_filter_arg+0x557> */
	X86_SIM_X86_JMP(0x62f, 0x557, x86_l_557);
x86_l_634:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
