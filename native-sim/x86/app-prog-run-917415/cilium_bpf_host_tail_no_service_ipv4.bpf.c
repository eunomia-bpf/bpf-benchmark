extern char __config_eth_header_length;
extern char cilium_calls;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_tail_no_service_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    r14d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e:
	/* 0xe: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17:
	/* 0x17: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_20:
	/* 0x20: mov    rax,QWORD PTR [rip+0x13c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_27:
	/* 0x27: movzx  r13d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b:
	/* 0x2b: mov    r12,QWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_32:
	/* 0x32: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_35:
	/* 0x35: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_38:
	/* 0x38: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b:
	/* 0x3b: lea    rcx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3f:
	/* 0x3f: add    rcx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_43:
	/* 0x43: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: ja     14b <tail_no_service_ipv4+0x14b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x46, 0x14b, x86_l_14b);
x86_l_4c:
	/* 0x4c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_51:
	/* 0x51: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_56:
	/* 0x56: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_5e:
	/* 0x5e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_63:
	/* 0x63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65:
	/* 0x65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_67:
	/* 0x67: js     14b <tail_no_service_ipv4+0x14b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x67, 0x14b, x86_l_14b);
x86_l_6d:
	/* 0x6d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_72:
	/* 0x72: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75:
	/* 0x75: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a:
	/* 0x7a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f:
	/* 0x7f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_84:
	/* 0x84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86:
	/* 0x86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_88:
	/* 0x88: js     14b <tail_no_service_ipv4+0x14b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x88, 0x14b, x86_l_14b);
x86_l_8e:
	/* 0x8e: add    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_91:
	/* 0x91: mov    r13d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_96:
	/* 0x96: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b:
	/* 0x9b: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_9f:
	/* 0x9f: movzx  eax,BYTE PTR [r12+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_a5:
	/* 0xa5: mov    BYTE PTR [rsp+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_a9:
	/* 0xa9: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ac:
	/* 0xac: cmp    ebp,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_af:
	/* 0xaf: mov    r12d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 64ULL);
x86_l_b5:
	/* 0xb5: cmovl  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_L);
x86_l_b9:
	/* 0xb9: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_be:
	/* 0xbe: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c1:
	/* 0xc1: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_c4:
	/* 0xc4: sub    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c6:
	/* 0xc6: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c9:
	/* 0xc9: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_cc:
	/* 0xcc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cf:
	/* 0xcf: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d1:
	/* 0xd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3:
	/* 0xd3: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_d5:
	/* 0xd5: js     122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd5, 0x122, x86_l_122);
x86_l_d7:
	/* 0xd7: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_de:
	/* 0xde: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e1:
	/* 0xe1: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_e4:
	/* 0xe4: cmp    edx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 15ULL);
x86_l_e7:
	/* 0xe7: ja     f2 <tail_no_service_ipv4+0xf2> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe7, 0xf2, x86_l_f2);
x86_l_e9:
	/* 0xe9: jne    122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe9, 0x122, x86_l_122);
x86_l_eb:
	/* 0xeb: movzx  r15d,BYTE PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_f0:
	/* 0xf0: jmp    122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JMP(0xf0, 0x122, x86_l_122);
x86_l_f2:
	/* 0xf2: movzx  r15d,WORD PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_f7:
	/* 0xf7: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_fa:
	/* 0xfa: jb     122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JCC(X86_CC_B, 0xfa, 0x122, x86_l_122);
x86_l_fc:
	/* 0xfc: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_ff:
	/* 0xff: ja     10f <tail_no_service_ipv4+0x10f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xff, 0x10f, x86_l_10f);
x86_l_101:
	/* 0x101: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_104:
	/* 0x104: je     122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104, 0x122, x86_l_122);
x86_l_106:
	/* 0x106: movzx  eax,BYTE PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_10a:
	/* 0x10a: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10d:
	/* 0x10d: jmp    122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JMP(0x10d, 0x122, x86_l_122);
x86_l_10f:
	/* 0x10f: movzx  eax,WORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_113:
	/* 0x113: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_116:
	/* 0x116: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_119:
	/* 0x119: jae    2fe <tail_no_service_ipv4+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x119, 0x2fe, x86_l_2fe);
x86_l_11f:
	/* 0x11f: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_122:
	/* 0x122: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_127:
	/* 0x127: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_12f:
	/* 0x12f: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_134:
	/* 0x134: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_136:
	/* 0x136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138:
	/* 0x138: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a:
	/* 0x13a: js     14b <tail_no_service_ipv4+0x14b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13a, 0x14b, x86_l_14b);
x86_l_13c:
	/* 0x13c: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13f:
	/* 0x13f: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_142:
	/* 0x142: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_145:
	/* 0x145: ja     1fd <tail_no_service_ipv4+0x1fd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x145, 0x1fd, x86_l_1fd);
x86_l_14b:
	/* 0x14b: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_150:
	/* 0x150: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_152:
	/* 0x152: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_154:
	/* 0x154: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_157:
	/* 0x157: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15a:
	/* 0x15a: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15e:
	/* 0x15e: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_165:
	/* 0x165: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_168:
	/* 0x168: movabs rcx,0x902690200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 649196753605623808ULL);
x86_l_172:
	/* 0x172: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_176:
	/* 0x176: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17a:
	/* 0x17a: movabs rcx,0x6909020100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 451122692352ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_189:
	/* 0x189: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d:
	/* 0x18d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_192:
	/* 0x192: mov    rdi,QWORD PTR [rip+0x13c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_199:
	/* 0x199: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e:
	/* 0x19e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0:
	/* 0x1a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3:
	/* 0x1a3: je     1ae <tail_no_service_ipv4+0x1ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3, 0x1ae, x86_l_1ae);
x86_l_1a5:
	/* 0x1a5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a8:
	/* 0x1a8: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ac:
	/* 0x1ac: jmp    1d6 <tail_no_service_ipv4+0x1d6> */
	X86_SIM_X86_JMP(0x1ac, 0x1d6, x86_l_1d6);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc:
	/* 0x1bc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c1:
	/* 0x1c1: mov    rdi,QWORD PTR [rip+0x13c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c8:
	/* 0x1c8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd:
	/* 0x1cd: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d2:
	/* 0x1d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d4:
	/* 0x1d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6:
	/* 0x1d6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1db:
	/* 0x1db: mov    rsi,QWORD PTR [rip+0x13c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1e2:
	/* 0x1e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f1:
	/* 0x1f1: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1f5:
	/* 0x1f5: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f7:
	/* 0x1f7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f8:
	/* 0x1f8: jmp    76a <tail_no_service_ipv4+0x76a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1fd:
	/* 0x1fd: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_200:
	/* 0x200: mov    r13,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_207:
	/* 0x207: movzx  eax,WORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_20c:
	/* 0x20c: mov    WORD PTR [r13+0x4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_211:
	/* 0x211: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_215:
	/* 0x215: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_219:
	/* 0x219: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_21e:
	/* 0x21e: mov    WORD PTR [r13+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_223:
	/* 0x223: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227:
	/* 0x227: mov    DWORD PTR [r13+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_22b:
	/* 0x22b: mov    WORD PTR [r13+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_232:
	/* 0x232: lea    rdi,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_236:
	/* 0x236: mov    BYTE PTR [r13+0xe],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542213ULL);
x86_l_23b:
	/* 0x23b: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_240:
	/* 0x240: mov    BYTE PTR [r13+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_244:
	/* 0x244: add    r12d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_248:
	/* 0x248: movbe  WORD PTR [r13+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_24f:
	/* 0x24f: movabs rax,0x14000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1374389534720ULL);
x86_l_259:
	/* 0x259: mov    QWORD PTR [r13+0x12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_25d:
	/* 0x25d: mov    DWORD PTR [r13+0x1e],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_261:
	/* 0x261: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_265:
	/* 0x265: mov    DWORD PTR [r13+0x1a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_269:
	/* 0x269: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_26e:
	/* 0x26e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_270:
	/* 0x270: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_272:
	/* 0x272: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_275:
	/* 0x275: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_27a:
	/* 0x27a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27d:
	/* 0x27d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f:
	/* 0x27f: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_282:
	/* 0x282: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_285:
	/* 0x285: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_287:
	/* 0x287: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_289:
	/* 0x289: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_28c:
	/* 0x28c: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28e:
	/* 0x28e: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_290:
	/* 0x290: mov    WORD PTR [r13+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_295:
	/* 0x295: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_299:
	/* 0x299: mov    QWORD PTR [r13+0x22],0x303 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 146028888835ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2a6:
	/* 0x2a6: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a8:
	/* 0x2a8: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b0:
	/* 0x2b0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b3:
	/* 0x2b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5:
	/* 0x2b5: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b8:
	/* 0x2b8: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2bb:
	/* 0x2bb: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2be:
	/* 0x2be: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c0:
	/* 0x2c0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2c2:
	/* 0x2c2: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2c5:
	/* 0x2c5: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c7:
	/* 0x2c7: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2c9:
	/* 0x2c9: mov    WORD PTR [r13+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2ce:
	/* 0x2ce: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2:
	/* 0x2d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d5:
	/* 0x2d5: je     2dd <tail_no_service_ipv4+0x2dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d5, 0x2dd, x86_l_2dd);
x86_l_2d7:
	/* 0x2d7: mov    ebp,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2dd:
	/* 0x2dd: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_2e2:
	/* 0x2e2: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_2e4:
	/* 0x2e4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e6:
	/* 0x2e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8:
	/* 0x2e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ea:
	/* 0x2ea: js     150 <tail_no_service_ipv4+0x150> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2ea, 0x150, x86_l_150);
x86_l_2f0:
	/* 0x2f0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f3:
	/* 0x2f3: jne    1f1 <tail_no_service_ipv4+0x1f1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f3, 0x1f1, x86_l_1f1);
x86_l_2f9:
	/* 0x2f9: jmp    150 <tail_no_service_ipv4+0x150> */
	X86_SIM_X86_JMP(0x2f9, 0x150, x86_l_150);
x86_l_2fe:
	/* 0x2fe: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_301:
	/* 0x301: ja     31a <tail_no_service_ipv4+0x31a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x301, 0x31a, x86_l_31a);
x86_l_303:
	/* 0x303: cmp    edx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 18ULL);
x86_l_306:
	/* 0x306: je     11f <tail_no_service_ipv4+0x11f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x306, 0x11f, x86_l_11f);
x86_l_30c:
	/* 0x30c: movzx  ecx,BYTE PTR [rcx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18ULL);
x86_l_310:
	/* 0x310: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_312:
	/* 0x312: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_315:
	/* 0x315: jmp    122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JMP(0x315, 0x122, x86_l_122);
x86_l_31a:
	/* 0x31a: movzx  esi,WORD PTR [rcx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_31e:
	/* 0x31e: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_320:
	/* 0x320: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_323:
	/* 0x323: jb     11f <tail_no_service_ipv4+0x11f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x323, 0x11f, x86_l_11f);
x86_l_329:
	/* 0x329: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_32c:
	/* 0x32c: ja     33d <tail_no_service_ipv4+0x33d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x32c, 0x33d, x86_l_33d);
x86_l_32e:
	/* 0x32e: cmp    edx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_331:
	/* 0x331: je     11f <tail_no_service_ipv4+0x11f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x331, 0x11f, x86_l_11f);
x86_l_337:
	/* 0x337: movzx  ecx,BYTE PTR [rcx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_33b:
	/* 0x33b: jmp    310 <tail_no_service_ipv4+0x310> */
	X86_SIM_X86_JMP(0x33b, 0x310, x86_l_310);
x86_l_33d:
	/* 0x33d: movzx  esi,WORD PTR [rcx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_341:
	/* 0x341: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_343:
	/* 0x343: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_346:
	/* 0x346: jb     11f <tail_no_service_ipv4+0x11f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x346, 0x11f, x86_l_11f);
x86_l_34c:
	/* 0x34c: cmp    edx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 23ULL);
x86_l_34f:
	/* 0x34f: ja     360 <tail_no_service_ipv4+0x360> */
	X86_SIM_X86_JCC(X86_CC_A, 0x34f, 0x360, x86_l_360);
x86_l_351:
	/* 0x351: cmp    edx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 22ULL);
x86_l_354:
	/* 0x354: je     11f <tail_no_service_ipv4+0x11f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x354, 0x11f, x86_l_11f);
x86_l_35a:
	/* 0x35a: movzx  ecx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_35e:
	/* 0x35e: jmp    310 <tail_no_service_ipv4+0x310> */
	X86_SIM_X86_JMP(0x35e, 0x310, x86_l_310);
x86_l_360:
	/* 0x360: movzx  esi,WORD PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 22ULL);
x86_l_364:
	/* 0x364: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_366:
	/* 0x366: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_369:
	/* 0x369: jb     11f <tail_no_service_ipv4+0x11f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x369, 0x11f, x86_l_11f);
x86_l_36f:
	/* 0x36f: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_372:
	/* 0x372: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_375:
	/* 0x375: ja     384 <tail_no_service_ipv4+0x384> */
	X86_SIM_X86_JCC(X86_CC_A, 0x375, 0x384, x86_l_384);
x86_l_377:
	/* 0x377: cmp    edx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_37a:
	/* 0x37a: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37a, 0x38f, x86_l_38f);
x86_l_37c:
	/* 0x37c: movzx  ecx,BYTE PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_380:
	/* 0x380: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_382:
	/* 0x382: jmp    38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JMP(0x382, 0x38f, x86_l_38f);
x86_l_384:
	/* 0x384: movzx  esi,WORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_388:
	/* 0x388: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_38a:
	/* 0x38a: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_38d:
	/* 0x38d: jae    39a <tail_no_service_ipv4+0x39a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x38d, 0x39a, x86_l_39a);
x86_l_38f:
	/* 0x38f: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_392:
	/* 0x392: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_395:
	/* 0x395: jmp    122 <tail_no_service_ipv4+0x122> */
	X86_SIM_X86_JMP(0x395, 0x122, x86_l_122);
x86_l_39a:
	/* 0x39a: cmp    edx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 27ULL);
x86_l_39d:
	/* 0x39d: ja     3aa <tail_no_service_ipv4+0x3aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x39d, 0x3aa, x86_l_3aa);
x86_l_39f:
	/* 0x39f: cmp    edx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 26ULL);
x86_l_3a2:
	/* 0x3a2: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a2, 0x38f, x86_l_38f);
x86_l_3a4:
	/* 0x3a4: movzx  ecx,BYTE PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_3a8:
	/* 0x3a8: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x3a8, 0x380, x86_l_380);
x86_l_3aa:
	/* 0x3aa: movzx  esi,WORD PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_3ae:
	/* 0x3ae: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b0:
	/* 0x3b0: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_3b3:
	/* 0x3b3: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3b3, 0x38f, x86_l_38f);
x86_l_3b5:
	/* 0x3b5: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3b8:
	/* 0x3b8: ja     3c5 <tail_no_service_ipv4+0x3c5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3b8, 0x3c5, x86_l_3c5);
x86_l_3ba:
	/* 0x3ba: cmp    edx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_3bd:
	/* 0x3bd: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3bd, 0x38f, x86_l_38f);
x86_l_3bf:
	/* 0x3bf: movzx  ecx,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3c3:
	/* 0x3c3: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x3c3, 0x380, x86_l_380);
x86_l_3c5:
	/* 0x3c5: movzx  esi,WORD PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_3c9:
	/* 0x3c9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3cb:
	/* 0x3cb: cmp    ebp,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_3ce:
	/* 0x3ce: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3ce, 0x38f, x86_l_38f);
x86_l_3d0:
	/* 0x3d0: cmp    edx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 31ULL);
x86_l_3d3:
	/* 0x3d3: ja     3e0 <tail_no_service_ipv4+0x3e0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3d3, 0x3e0, x86_l_3e0);
x86_l_3d5:
	/* 0x3d5: cmp    edx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 30ULL);
x86_l_3d8:
	/* 0x3d8: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d8, 0x38f, x86_l_38f);
x86_l_3da:
	/* 0x3da: movzx  ecx,BYTE PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3de:
	/* 0x3de: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x3de, 0x380, x86_l_380);
x86_l_3e0:
	/* 0x3e0: movzx  esi,WORD PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 30ULL);
x86_l_3e4:
	/* 0x3e4: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e6:
	/* 0x3e6: cmp    ebp,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 18ULL);
x86_l_3e9:
	/* 0x3e9: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3e9, 0x38f, x86_l_38f);
x86_l_3eb:
	/* 0x3eb: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_3ee:
	/* 0x3ee: ja     3fb <tail_no_service_ipv4+0x3fb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3ee, 0x3fb, x86_l_3fb);
x86_l_3f0:
	/* 0x3f0: cmp    edx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32ULL);
x86_l_3f3:
	/* 0x3f3: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f3, 0x38f, x86_l_38f);
x86_l_3f5:
	/* 0x3f5: movzx  ecx,BYTE PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_3f9:
	/* 0x3f9: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x3f9, 0x380, x86_l_380);
x86_l_3fb:
	/* 0x3fb: movzx  esi,WORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3ff:
	/* 0x3ff: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_401:
	/* 0x401: cmp    ebp,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 20ULL);
x86_l_404:
	/* 0x404: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x404, 0x38f, x86_l_38f);
x86_l_406:
	/* 0x406: cmp    edx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 35ULL);
x86_l_409:
	/* 0x409: ja     41d <tail_no_service_ipv4+0x41d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x409, 0x41d, x86_l_41d);
x86_l_40b:
	/* 0x40b: cmp    edx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 34ULL);
x86_l_40e:
	/* 0x40e: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40e, 0x38f, x86_l_38f);
x86_l_414:
	/* 0x414: movzx  ecx,BYTE PTR [rcx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_418:
	/* 0x418: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x418, 0x380, x86_l_380);
x86_l_41d:
	/* 0x41d: movzx  esi,WORD PTR [rcx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_421:
	/* 0x421: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_423:
	/* 0x423: cmp    ebp,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 22ULL);
x86_l_426:
	/* 0x426: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x426, 0x38f, x86_l_38f);
x86_l_42c:
	/* 0x42c: cmp    edx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_42f:
	/* 0x42f: ja     443 <tail_no_service_ipv4+0x443> */
	X86_SIM_X86_JCC(X86_CC_A, 0x42f, 0x443, x86_l_443);
x86_l_431:
	/* 0x431: cmp    edx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_434:
	/* 0x434: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x434, 0x38f, x86_l_38f);
x86_l_43a:
	/* 0x43a: movzx  ecx,BYTE PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_43e:
	/* 0x43e: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x43e, 0x380, x86_l_380);
x86_l_443:
	/* 0x443: movzx  esi,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_447:
	/* 0x447: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_449:
	/* 0x449: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_44c:
	/* 0x44c: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x44c, 0x38f, x86_l_38f);
x86_l_452:
	/* 0x452: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_455:
	/* 0x455: ja     469 <tail_no_service_ipv4+0x469> */
	X86_SIM_X86_JCC(X86_CC_A, 0x455, 0x469, x86_l_469);
x86_l_457:
	/* 0x457: cmp    edx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 38ULL);
x86_l_45a:
	/* 0x45a: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45a, 0x38f, x86_l_38f);
x86_l_460:
	/* 0x460: movzx  ecx,BYTE PTR [rcx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 38ULL);
x86_l_464:
	/* 0x464: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x464, 0x380, x86_l_380);
x86_l_469:
	/* 0x469: movzx  esi,WORD PTR [rcx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_46d:
	/* 0x46d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_46f:
	/* 0x46f: cmp    ebp,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 26ULL);
x86_l_472:
	/* 0x472: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x472, 0x38f, x86_l_38f);
x86_l_478:
	/* 0x478: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_47b:
	/* 0x47b: ja     48f <tail_no_service_ipv4+0x48f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x47b, 0x48f, x86_l_48f);
x86_l_47d:
	/* 0x47d: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_480:
	/* 0x480: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x480, 0x38f, x86_l_38f);
x86_l_486:
	/* 0x486: movzx  ecx,BYTE PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_48a:
	/* 0x48a: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x48a, 0x380, x86_l_380);
x86_l_48f:
	/* 0x48f: movzx  esi,WORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_493:
	/* 0x493: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_495:
	/* 0x495: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_498:
	/* 0x498: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x498, 0x38f, x86_l_38f);
x86_l_49e:
	/* 0x49e: cmp    edx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 43ULL);
x86_l_4a1:
	/* 0x4a1: ja     4b5 <tail_no_service_ipv4+0x4b5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a1, 0x4b5, x86_l_4b5);
x86_l_4a3:
	/* 0x4a3: cmp    edx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 42ULL);
x86_l_4a6:
	/* 0x4a6: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a6, 0x38f, x86_l_38f);
x86_l_4ac:
	/* 0x4ac: movzx  ecx,BYTE PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_4b0:
	/* 0x4b0: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x4b0, 0x380, x86_l_380);
x86_l_4b5:
	/* 0x4b5: movzx  esi,WORD PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_4b9:
	/* 0x4b9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4bb:
	/* 0x4bb: cmp    ebp,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 30ULL);
x86_l_4be:
	/* 0x4be: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4be, 0x38f, x86_l_38f);
x86_l_4c4:
	/* 0x4c4: cmp    edx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 45ULL);
x86_l_4c7:
	/* 0x4c7: ja     4db <tail_no_service_ipv4+0x4db> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4c7, 0x4db, x86_l_4db);
x86_l_4c9:
	/* 0x4c9: cmp    edx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 44ULL);
x86_l_4cc:
	/* 0x4cc: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cc, 0x38f, x86_l_38f);
x86_l_4d2:
	/* 0x4d2: movzx  ecx,BYTE PTR [rcx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_4d6:
	/* 0x4d6: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x4d6, 0x380, x86_l_380);
x86_l_4db:
	/* 0x4db: movzx  esi,WORD PTR [rcx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_4df:
	/* 0x4df: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4e1:
	/* 0x4e1: cmp    ebp,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_4e4:
	/* 0x4e4: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4e4, 0x38f, x86_l_38f);
x86_l_4ea:
	/* 0x4ea: cmp    edx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 47ULL);
x86_l_4ed:
	/* 0x4ed: ja     501 <tail_no_service_ipv4+0x501> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4ed, 0x501, x86_l_501);
x86_l_4ef:
	/* 0x4ef: cmp    edx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 46ULL);
x86_l_4f2:
	/* 0x4f2: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f2, 0x38f, x86_l_38f);
x86_l_4f8:
	/* 0x4f8: movzx  ecx,BYTE PTR [rcx+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 46ULL);
x86_l_4fc:
	/* 0x4fc: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x4fc, 0x380, x86_l_380);
x86_l_501:
	/* 0x501: movzx  esi,WORD PTR [rcx+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 46ULL);
x86_l_505:
	/* 0x505: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_507:
	/* 0x507: cmp    ebp,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 34ULL);
x86_l_50a:
	/* 0x50a: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x50a, 0x38f, x86_l_38f);
x86_l_510:
	/* 0x510: cmp    edx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 49ULL);
x86_l_513:
	/* 0x513: ja     527 <tail_no_service_ipv4+0x527> */
	X86_SIM_X86_JCC(X86_CC_A, 0x513, 0x527, x86_l_527);
x86_l_515:
	/* 0x515: cmp    edx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 48ULL);
x86_l_518:
	/* 0x518: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x518, 0x38f, x86_l_38f);
x86_l_51e:
	/* 0x51e: movzx  ecx,BYTE PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 48ULL);
x86_l_522:
	/* 0x522: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x522, 0x380, x86_l_380);
x86_l_527:
	/* 0x527: movzx  esi,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_52b:
	/* 0x52b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_52d:
	/* 0x52d: cmp    ebp,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 36ULL);
x86_l_530:
	/* 0x530: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x530, 0x38f, x86_l_38f);
x86_l_536:
	/* 0x536: cmp    edx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 51ULL);
x86_l_539:
	/* 0x539: ja     54d <tail_no_service_ipv4+0x54d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x539, 0x54d, x86_l_54d);
x86_l_53b:
	/* 0x53b: cmp    edx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 50ULL);
x86_l_53e:
	/* 0x53e: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53e, 0x38f, x86_l_38f);
x86_l_544:
	/* 0x544: movzx  ecx,BYTE PTR [rcx+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 50ULL);
x86_l_548:
	/* 0x548: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x548, 0x380, x86_l_380);
x86_l_54d:
	/* 0x54d: movzx  esi,WORD PTR [rcx+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_551:
	/* 0x551: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_553:
	/* 0x553: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_556:
	/* 0x556: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x556, 0x38f, x86_l_38f);
x86_l_55c:
	/* 0x55c: cmp    edx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 53ULL);
x86_l_55f:
	/* 0x55f: ja     573 <tail_no_service_ipv4+0x573> */
	X86_SIM_X86_JCC(X86_CC_A, 0x55f, 0x573, x86_l_573);
x86_l_561:
	/* 0x561: cmp    edx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 52ULL);
x86_l_564:
	/* 0x564: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x564, 0x38f, x86_l_38f);
x86_l_56a:
	/* 0x56a: movzx  ecx,BYTE PTR [rcx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_56e:
	/* 0x56e: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x56e, 0x380, x86_l_380);
x86_l_573:
	/* 0x573: movzx  esi,WORD PTR [rcx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_577:
	/* 0x577: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_579:
	/* 0x579: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_57c:
	/* 0x57c: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x57c, 0x38f, x86_l_38f);
x86_l_582:
	/* 0x582: cmp    edx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 55ULL);
x86_l_585:
	/* 0x585: ja     599 <tail_no_service_ipv4+0x599> */
	X86_SIM_X86_JCC(X86_CC_A, 0x585, 0x599, x86_l_599);
x86_l_587:
	/* 0x587: cmp    edx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 54ULL);
x86_l_58a:
	/* 0x58a: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58a, 0x38f, x86_l_38f);
x86_l_590:
	/* 0x590: movzx  ecx,BYTE PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 54ULL);
x86_l_594:
	/* 0x594: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x594, 0x380, x86_l_380);
x86_l_599:
	/* 0x599: movzx  esi,WORD PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 54ULL);
x86_l_59d:
	/* 0x59d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_59f:
	/* 0x59f: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_5a2:
	/* 0x5a2: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5a2, 0x38f, x86_l_38f);
x86_l_5a8:
	/* 0x5a8: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_5ab:
	/* 0x5ab: ja     5bf <tail_no_service_ipv4+0x5bf> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5ab, 0x5bf, x86_l_5bf);
x86_l_5ad:
	/* 0x5ad: cmp    edx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 56ULL);
x86_l_5b0:
	/* 0x5b0: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b0, 0x38f, x86_l_38f);
x86_l_5b6:
	/* 0x5b6: movzx  ecx,BYTE PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_5ba:
	/* 0x5ba: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x5ba, 0x380, x86_l_380);
x86_l_5bf:
	/* 0x5bf: movzx  esi,WORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_5c3:
	/* 0x5c3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5c5:
	/* 0x5c5: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_5c8:
	/* 0x5c8: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5c8, 0x38f, x86_l_38f);
x86_l_5ce:
	/* 0x5ce: cmp    edx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 59ULL);
x86_l_5d1:
	/* 0x5d1: ja     5e5 <tail_no_service_ipv4+0x5e5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5d1, 0x5e5, x86_l_5e5);
x86_l_5d3:
	/* 0x5d3: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_5d6:
	/* 0x5d6: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d6, 0x38f, x86_l_38f);
x86_l_5dc:
	/* 0x5dc: movzx  ecx,BYTE PTR [rcx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_5e0:
	/* 0x5e0: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x5e0, 0x380, x86_l_380);
x86_l_5e5:
	/* 0x5e5: movzx  esi,WORD PTR [rcx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_5e9:
	/* 0x5e9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5eb:
	/* 0x5eb: cmp    ebp,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 46ULL);
x86_l_5ee:
	/* 0x5ee: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5ee, 0x38f, x86_l_38f);
x86_l_5f4:
	/* 0x5f4: cmp    edx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 61ULL);
x86_l_5f7:
	/* 0x5f7: ja     60b <tail_no_service_ipv4+0x60b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5f7, 0x60b, x86_l_60b);
x86_l_5f9:
	/* 0x5f9: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_5fc:
	/* 0x5fc: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5fc, 0x38f, x86_l_38f);
x86_l_602:
	/* 0x602: movzx  ecx,BYTE PTR [rcx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_606:
	/* 0x606: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x606, 0x380, x86_l_380);
x86_l_60b:
	/* 0x60b: movzx  esi,WORD PTR [rcx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_60f:
	/* 0x60f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_611:
	/* 0x611: cmp    ebp,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 48ULL);
x86_l_614:
	/* 0x614: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x614, 0x38f, x86_l_38f);
x86_l_61a:
	/* 0x61a: cmp    edx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_61d:
	/* 0x61d: ja     631 <tail_no_service_ipv4+0x631> */
	X86_SIM_X86_JCC(X86_CC_A, 0x61d, 0x631, x86_l_631);
x86_l_61f:
	/* 0x61f: cmp    edx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 62ULL);
x86_l_622:
	/* 0x622: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x622, 0x38f, x86_l_38f);
x86_l_628:
	/* 0x628: movzx  ecx,BYTE PTR [rcx+0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 62ULL);
x86_l_62c:
	/* 0x62c: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x62c, 0x380, x86_l_380);
x86_l_631:
	/* 0x631: movzx  esi,WORD PTR [rcx+0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 62ULL);
x86_l_635:
	/* 0x635: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_637:
	/* 0x637: cmp    ebp,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 50ULL);
x86_l_63a:
	/* 0x63a: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x63a, 0x38f, x86_l_38f);
x86_l_640:
	/* 0x640: cmp    edx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 65ULL);
x86_l_643:
	/* 0x643: ja     657 <tail_no_service_ipv4+0x657> */
	X86_SIM_X86_JCC(X86_CC_A, 0x643, 0x657, x86_l_657);
x86_l_645:
	/* 0x645: cmp    edx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_648:
	/* 0x648: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x648, 0x38f, x86_l_38f);
x86_l_64e:
	/* 0x64e: movzx  ecx,BYTE PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_652:
	/* 0x652: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x652, 0x380, x86_l_380);
x86_l_657:
	/* 0x657: movzx  esi,WORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_65b:
	/* 0x65b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_65d:
	/* 0x65d: cmp    ebp,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 52ULL);
x86_l_660:
	/* 0x660: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x660, 0x38f, x86_l_38f);
x86_l_666:
	/* 0x666: cmp    edx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 67ULL);
x86_l_669:
	/* 0x669: ja     67d <tail_no_service_ipv4+0x67d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x669, 0x67d, x86_l_67d);
x86_l_66b:
	/* 0x66b: cmp    edx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 66ULL);
x86_l_66e:
	/* 0x66e: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66e, 0x38f, x86_l_38f);
x86_l_674:
	/* 0x674: movzx  ecx,BYTE PTR [rcx+0x42] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 66ULL);
x86_l_678:
	/* 0x678: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x678, 0x380, x86_l_380);
x86_l_67d:
	/* 0x67d: movzx  esi,WORD PTR [rcx+0x42] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 66ULL);
x86_l_681:
	/* 0x681: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_683:
	/* 0x683: cmp    ebp,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 54ULL);
x86_l_686:
	/* 0x686: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x686, 0x38f, x86_l_38f);
x86_l_68c:
	/* 0x68c: cmp    edx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 69ULL);
x86_l_68f:
	/* 0x68f: ja     6a3 <tail_no_service_ipv4+0x6a3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x68f, 0x6a3, x86_l_6a3);
x86_l_691:
	/* 0x691: cmp    edx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 68ULL);
x86_l_694:
	/* 0x694: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x694, 0x38f, x86_l_38f);
x86_l_69a:
	/* 0x69a: movzx  ecx,BYTE PTR [rcx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 68ULL);
x86_l_69e:
	/* 0x69e: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x69e, 0x380, x86_l_380);
x86_l_6a3:
	/* 0x6a3: movzx  esi,WORD PTR [rcx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 68ULL);
x86_l_6a7:
	/* 0x6a7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6a9:
	/* 0x6a9: cmp    ebp,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 56ULL);
x86_l_6ac:
	/* 0x6ac: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6ac, 0x38f, x86_l_38f);
x86_l_6b2:
	/* 0x6b2: cmp    edx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_6b5:
	/* 0x6b5: ja     6c9 <tail_no_service_ipv4+0x6c9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6b5, 0x6c9, x86_l_6c9);
x86_l_6b7:
	/* 0x6b7: cmp    edx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 70ULL);
x86_l_6ba:
	/* 0x6ba: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ba, 0x38f, x86_l_38f);
x86_l_6c0:
	/* 0x6c0: movzx  ecx,BYTE PTR [rcx+0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 70ULL);
x86_l_6c4:
	/* 0x6c4: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x6c4, 0x380, x86_l_380);
x86_l_6c9:
	/* 0x6c9: movzx  esi,WORD PTR [rcx+0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 70ULL);
x86_l_6cd:
	/* 0x6cd: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6cf:
	/* 0x6cf: cmp    ebp,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 58ULL);
x86_l_6d2:
	/* 0x6d2: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6d2, 0x38f, x86_l_38f);
x86_l_6d8:
	/* 0x6d8: cmp    edx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 73ULL);
x86_l_6db:
	/* 0x6db: ja     6ef <tail_no_service_ipv4+0x6ef> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6db, 0x6ef, x86_l_6ef);
x86_l_6dd:
	/* 0x6dd: cmp    edx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_6e0:
	/* 0x6e0: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e0, 0x38f, x86_l_38f);
x86_l_6e6:
	/* 0x6e6: movzx  ecx,BYTE PTR [rcx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_6ea:
	/* 0x6ea: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x6ea, 0x380, x86_l_380);
x86_l_6ef:
	/* 0x6ef: movzx  esi,WORD PTR [rcx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 72ULL);
x86_l_6f3:
	/* 0x6f3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6f5:
	/* 0x6f5: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_6f8:
	/* 0x6f8: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6f8, 0x38f, x86_l_38f);
x86_l_6fe:
	/* 0x6fe: cmp    edx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 75ULL);
x86_l_701:
	/* 0x701: ja     715 <tail_no_service_ipv4+0x715> */
	X86_SIM_X86_JCC(X86_CC_A, 0x701, 0x715, x86_l_715);
x86_l_703:
	/* 0x703: cmp    edx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 74ULL);
x86_l_706:
	/* 0x706: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x706, 0x38f, x86_l_38f);
x86_l_70c:
	/* 0x70c: movzx  ecx,BYTE PTR [rcx+0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 74ULL);
x86_l_710:
	/* 0x710: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x710, 0x380, x86_l_380);
x86_l_715:
	/* 0x715: movzx  esi,WORD PTR [rcx+0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 74ULL);
x86_l_719:
	/* 0x719: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_71b:
	/* 0x71b: cmp    ebp,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 62ULL);
x86_l_71e:
	/* 0x71e: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x71e, 0x38f, x86_l_38f);
x86_l_724:
	/* 0x724: cmp    edx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 77ULL);
x86_l_727:
	/* 0x727: ja     73b <tail_no_service_ipv4+0x73b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x727, 0x73b, x86_l_73b);
x86_l_729:
	/* 0x729: cmp    edx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 76ULL);
x86_l_72c:
	/* 0x72c: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72c, 0x38f, x86_l_38f);
x86_l_732:
	/* 0x732: movzx  ecx,BYTE PTR [rcx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 76ULL);
x86_l_736:
	/* 0x736: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x736, 0x380, x86_l_380);
x86_l_73b:
	/* 0x73b: movzx  esi,WORD PTR [rcx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_73f:
	/* 0x73f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_741:
	/* 0x741: cmp    ebp,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_744:
	/* 0x744: jb     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x744, 0x38f, x86_l_38f);
x86_l_74a:
	/* 0x74a: cmp    edx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 79ULL);
x86_l_74d:
	/* 0x74d: ja     761 <tail_no_service_ipv4+0x761> */
	X86_SIM_X86_JCC(X86_CC_A, 0x74d, 0x761, x86_l_761);
x86_l_74f:
	/* 0x74f: cmp    edx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 78ULL);
x86_l_752:
	/* 0x752: je     38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x752, 0x38f, x86_l_38f);
x86_l_758:
	/* 0x758: movzx  ecx,BYTE PTR [rcx+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 78ULL);
x86_l_75c:
	/* 0x75c: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x75c, 0x380, x86_l_380);
x86_l_761:
	/* 0x761: movzx  ecx,WORD PTR [rcx+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 78ULL);
x86_l_765:
	/* 0x765: jmp    380 <tail_no_service_ipv4+0x380> */
	X86_SIM_X86_JMP(0x765, 0x380, x86_l_380);
x86_l_76a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
