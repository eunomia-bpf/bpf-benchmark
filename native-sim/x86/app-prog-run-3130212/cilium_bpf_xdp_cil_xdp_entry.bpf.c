extern char __config_enable_xdp_prefilter;
extern char __config_tracing_ip_option_type;
extern char cilium_cidr_v4_dyn;
extern char cilium_cidr_v4_fix;
extern char cilium_percpu_trace_id;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_cil_xdp_entry_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_e:
	/* 0xe: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11:
	/* 0x11: je     51 <cil_xdp_entry+0x51> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11, 0x51, x86_l_51);
x86_l_13:
	/* 0x13: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16:
	/* 0x16: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19:
	/* 0x19: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d:
	/* 0x1d: lea    rdi,[rax+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_21:
	/* 0x21: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_24:
	/* 0x24: jbe    136 <cil_xdp_entry+0x136> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x24, 0x136, x86_l_136);
x86_l_2a:
	/* 0x2a: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_32:
	/* 0x32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37:
	/* 0x37: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_3e:
	/* 0x3e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43:
	/* 0x43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45:
	/* 0x45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: je     51 <cil_xdp_entry+0x51> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48, 0x51, x86_l_51);
x86_l_4a:
	/* 0x4a: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51:
	/* 0x51: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54:
	/* 0x54: lea    rdx,[rcx+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_58:
	/* 0x58: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5d:
	/* 0x5d: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_61:
	/* 0x61: ja     1d2 <cil_xdp_entry+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x61, 0x1d2, x86_l_1d2);
x86_l_67:
	/* 0x67: movzx  r13d,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_6c:
	/* 0x6c: cmp    r13w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_16, 6ULL);
x86_l_71:
	/* 0x71: jb     1d2 <cil_xdp_entry+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x71, 0x1d2, x86_l_1d2);
x86_l_77:
	/* 0x77: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_7f:
	/* 0x7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84:
	/* 0x84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_8b:
	/* 0x8b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_90:
	/* 0x90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92:
	/* 0x92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_95:
	/* 0x95: je     9e <cil_xdp_entry+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95, 0x9e, x86_l_9e);
x86_l_97:
	/* 0x97: mov    DWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9e:
	/* 0x9e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a6:
	/* 0xa6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ab:
	/* 0xab: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_b2:
	/* 0xb2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7:
	/* 0xb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9:
	/* 0xb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc:
	/* 0xbc: je     c5 <cil_xdp_entry+0xc5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc, 0xc5, x86_l_c5);
x86_l_be:
	/* 0xbe: mov    DWORD PTR [rax+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_c5:
	/* 0xc5: cmp    r13w,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_16, 8ULL);
x86_l_ca:
	/* 0xca: jne    18d <cil_xdp_entry+0x18d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca, 0x18d, x86_l_18d);
x86_l_d0:
	/* 0xd0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_xdp_prefilter)));
x86_l_d7:
	/* 0xd7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da:
	/* 0xda: je     18d <cil_xdp_entry+0x18d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda, 0x18d, x86_l_18d);
x86_l_e0:
	/* 0xe0: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3:
	/* 0xe3: lea    rcx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_e7:
	/* 0xe7: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_eb:
	/* 0xeb: ja     12c <cil_xdp_entry+0x12c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xeb, 0x12c, x86_l_12c);
x86_l_ed:
	/* 0xed: mov    eax,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_f0:
	/* 0xf0: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f4:
	/* 0xf4: mov    DWORD PTR [rsp+0x8],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_fc:
	/* 0xfc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_101:
	/* 0x101: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_cidr_v4_dyn)));
x86_l_108:
	/* 0x108: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d:
	/* 0x10d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f:
	/* 0x10f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112:
	/* 0x112: jne    12c <cil_xdp_entry+0x12c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x112, 0x12c, x86_l_12c);
x86_l_114:
	/* 0x114: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_119:
	/* 0x119: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_cidr_v4_fix)));
x86_l_120:
	/* 0x120: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125:
	/* 0x125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127:
	/* 0x127: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: je     18d <cil_xdp_entry+0x18d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a, 0x18d, x86_l_18d);
x86_l_12c:
	/* 0x12c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_131:
	/* 0x131: jmp    1d2 <cil_xdp_entry+0x1d2> */
	X86_SIM_X86_JMP(0x131, 0x1d2, x86_l_1d2);
x86_l_136:
	/* 0x136: cmp    WORD PTR [rax+0xc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_13b:
	/* 0x13b: jne    2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13b, 0x2a, x86_l_2a);
x86_l_141:
	/* 0x141: lea    rsi,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_145:
	/* 0x145: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_148:
	/* 0x148: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x148, 0x2a, x86_l_2a);
x86_l_14e:
	/* 0x14e: movzx  edi,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_151:
	/* 0x151: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_154:
	/* 0x154: cmp    dil,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 6ULL);
x86_l_158:
	/* 0x158: jae    1db <cil_xdp_entry+0x1db> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x158, 0x1db, x86_l_1db);
x86_l_15e:
	/* 0x15e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161:
	/* 0x161: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_169:
	/* 0x169: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e:
	/* 0x16e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_175:
	/* 0x175: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a:
	/* 0x17a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c:
	/* 0x17c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f:
	/* 0x17f: je     51 <cil_xdp_entry+0x51> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17f, 0x51, x86_l_51);
x86_l_185:
	/* 0x185: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188:
	/* 0x188: jmp    51 <cil_xdp_entry+0x51> */
	X86_SIM_X86_JMP(0x188, 0x51, x86_l_51);
x86_l_18d:
	/* 0x18d: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_195:
	/* 0x195: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19a:
	/* 0x19a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1a1:
	/* 0x1a1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a6:
	/* 0x1a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8:
	/* 0x1a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ab:
	/* 0x1ab: je     1cd <cil_xdp_entry+0x1cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ab, 0x1cd, x86_l_1cd);
x86_l_1ad:
	/* 0x1ad: mov    r13d,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b1:
	/* 0x1b1: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1b4:
	/* 0x1b4: je     1cd <cil_xdp_entry+0x1cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4, 0x1cd, x86_l_1cd);
x86_l_1b6:
	/* 0x1b6: mov    eax,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 54ULL);
x86_l_1bb:
	/* 0x1bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1be:
	/* 0x1be: mov    esi,0xfffffffc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967292ULL);
x86_l_1c3:
	/* 0x1c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c5:
	/* 0x1c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c7:
	/* 0x1c7: je     294 <cil_xdp_entry+0x294> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c7, 0x294, x86_l_294);
x86_l_1cd:
	/* 0x1cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d2:
	/* 0x1d2: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d6:
	/* 0x1d6: jmp    39e <cil_xdp_entry+0x39e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1db:
	/* 0x1db: lea    r8,[rax+0x23] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1df:
	/* 0x1df: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_1e2:
	/* 0x1e2: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1e2, 0x2a, x86_l_2a);
x86_l_1e8:
	/* 0x1e8: movzx  r14d,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ec:
	/* 0x1ec: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_1ef:
	/* 0x1ef: je     161 <cil_xdp_entry+0x161> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ef, 0x161, x86_l_161);
x86_l_1f5:
	/* 0x1f5: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_1fa:
	/* 0x1fa: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1fe:
	/* 0x1fe: jne    2b2 <cil_xdp_entry+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fe, 0x2b2, x86_l_2b2);
x86_l_204:
	/* 0x204: lea    edi,[rdi*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 34ULL);
x86_l_20b:
	/* 0x20b: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_20d:
	/* 0x20d: jae    15e <cil_xdp_entry+0x15e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x20d, 0x15e, x86_l_15e);
x86_l_213:
	/* 0x213: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_216:
	/* 0x216: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_21a:
	/* 0x21a: inc    r9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_21d:
	/* 0x21d: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_220:
	/* 0x220: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x220, 0x2a, x86_l_2a);
x86_l_226:
	/* 0x226: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_22a:
	/* 0x22a: movzx  r14d,BYTE PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22e:
	/* 0x22e: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_231:
	/* 0x231: je     161 <cil_xdp_entry+0x161> */
	X86_SIM_X86_JCC(X86_CC_E, 0x231, 0x161, x86_l_161);
x86_l_237:
	/* 0x237: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_23b:
	/* 0x23b: jne    32a <cil_xdp_entry+0x32a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23b, 0x32a, x86_l_32a);
x86_l_241:
	/* 0x241: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_244:
	/* 0x244: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_246:
	/* 0x246: jae    15e <cil_xdp_entry+0x15e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x246, 0x15e, x86_l_15e);
x86_l_24c:
	/* 0x24c: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_24e:
	/* 0x24e: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_252:
	/* 0x252: inc    r8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_255:
	/* 0x255: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_258:
	/* 0x258: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x258, 0x2a, x86_l_2a);
x86_l_25e:
	/* 0x25e: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_262:
	/* 0x262: movzx  r8d,BYTE PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_266:
	/* 0x266: cmp    r8b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 2ULL);
x86_l_26a:
	/* 0x26a: jb     15e <cil_xdp_entry+0x15e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x26a, 0x15e, x86_l_15e);
x86_l_270:
	/* 0x270: lea    r9,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_274:
	/* 0x274: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_278:
	/* 0x278: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_27b:
	/* 0x27b: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x27b, 0x2a, x86_l_2a);
x86_l_281:
	/* 0x281: cmp    r8b,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_8);
x86_l_284:
	/* 0x284: jne    15e <cil_xdp_entry+0x15e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x284, 0x15e, x86_l_15e);
x86_l_28a:
	/* 0x28a: add    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28d:
	/* 0x28d: movzx  r8d,BYTE PTR [rdi+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_292:
	/* 0x292: jmp    2ce <cil_xdp_entry+0x2ce> */
	X86_SIM_X86_JMP(0x292, 0x2ce, x86_l_2ce);
x86_l_294:
	/* 0x294: mov    rcx,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_298:
	/* 0x298: lea    rax,[rcx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29c:
	/* 0x29c: cmp    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_29f:
	/* 0x29f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a4:
	/* 0x2a4: ja     1d2 <cil_xdp_entry+0x1d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2a4, 0x1d2, x86_l_1d2);
x86_l_2aa:
	/* 0x2aa: mov    DWORD PTR [rcx],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad:
	/* 0x2ad: jmp    1d2 <cil_xdp_entry+0x1d2> */
	X86_SIM_X86_JMP(0x2ad, 0x1d2, x86_l_1d2);
x86_l_2b2:
	/* 0x2b2: lea    rsi,[rax+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b6:
	/* 0x2b6: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2b9, 0x2a, x86_l_2a);
x86_l_2bf:
	/* 0x2bf: movzx  r8d,BYTE PTR [rax+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_2c4:
	/* 0x2c4: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_2c9:
	/* 0x2c9: cmp    r14b,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RDX, X86_WIDTH_8);
x86_l_2cc:
	/* 0x2cc: jne    30f <cil_xdp_entry+0x30f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2cc, 0x30f, x86_l_30f);
x86_l_2ce:
	/* 0x2ce: cmp    r8b,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 10ULL);
x86_l_2d2:
	/* 0x2d2: je     37d <cil_xdp_entry+0x37d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d2, 0x37d, x86_l_37d);
x86_l_2d8:
	/* 0x2d8: movzx  edx,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2dc:
	/* 0x2dc: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2df:
	/* 0x2df: je     35c <cil_xdp_entry+0x35c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2df, 0x35c, x86_l_35c);
x86_l_2e1:
	/* 0x2e1: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2e4:
	/* 0x2e4: jne    2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e4, 0x2a, x86_l_2a);
x86_l_2ea:
	/* 0x2ea: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ec:
	/* 0x2ec: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2f0:
	/* 0x2f0: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2f4:
	/* 0x2f4: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_2f7:
	/* 0x2f7: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2f7, 0x2a, x86_l_2a);
x86_l_2fd:
	/* 0x2fd: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_300:
	/* 0x300: movbe  ax,WORD PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_306:
	/* 0x306: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_30a:
	/* 0x30a: jmp    161 <cil_xdp_entry+0x161> */
	X86_SIM_X86_JMP(0x30a, 0x161, x86_l_161);
x86_l_30f:
	/* 0x30f: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_313:
	/* 0x313: add    esi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 34ULL);
x86_l_316:
	/* 0x316: lea    edi,[rdi*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 34ULL);
x86_l_31d:
	/* 0x31d: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_31f:
	/* 0x31f: jae    15e <cil_xdp_entry+0x15e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x31f, 0x15e, x86_l_15e);
x86_l_325:
	/* 0x325: jmp    213 <cil_xdp_entry+0x213> */
	X86_SIM_X86_JMP(0x325, 0x213, x86_l_213);
x86_l_32a:
	/* 0x32a: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_32e:
	/* 0x32e: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_332:
	/* 0x332: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_335:
	/* 0x335: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x335, 0x2a, x86_l_2a);
x86_l_33b:
	/* 0x33b: add    r8,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33e:
	/* 0x33e: movzx  r8d,BYTE PTR [r8+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_343:
	/* 0x343: cmp    r14b,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RDX, X86_WIDTH_8);
x86_l_346:
	/* 0x346: je     2ce <cil_xdp_entry+0x2ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x346, 0x2ce, x86_l_2ce);
x86_l_348:
	/* 0x348: movzx  r14d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34c:
	/* 0x34c: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34f:
	/* 0x34f: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_351:
	/* 0x351: jae    15e <cil_xdp_entry+0x15e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x351, 0x15e, x86_l_15e);
x86_l_357:
	/* 0x357: jmp    24c <cil_xdp_entry+0x24c> */
	X86_SIM_X86_JMP(0x357, 0x24c, x86_l_24c);
x86_l_35c:
	/* 0x35c: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_35e:
	/* 0x35e: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_362:
	/* 0x362: add    rsi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_366:
	/* 0x366: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_369:
	/* 0x369: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x369, 0x2a, x86_l_2a);
x86_l_36f:
	/* 0x36f: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_372:
	/* 0x372: movbe  r14d,DWORD PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 2ULL);
x86_l_378:
	/* 0x378: jmp    161 <cil_xdp_entry+0x161> */
	X86_SIM_X86_JMP(0x378, 0x161, x86_l_161);
x86_l_37d:
	/* 0x37d: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_37f:
	/* 0x37f: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_383:
	/* 0x383: add    rsi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 10ULL);
x86_l_387:
	/* 0x387: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_38a:
	/* 0x38a: ja     2a <cil_xdp_entry+0x2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x38a, 0x2a, x86_l_2a);
x86_l_390:
	/* 0x390: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_393:
	/* 0x393: movbe  r14,QWORD PTR [rax+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 2ULL);
x86_l_399:
	/* 0x399: jmp    161 <cil_xdp_entry+0x161> */
	X86_SIM_X86_JMP(0x399, 0x161, x86_l_161);
x86_l_39e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
