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
	/* 0x11: mov    r14d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15:
	/* 0x15: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1e:
	/* 0x1e: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_27:
	/* 0x27: mov    rax,QWORD PTR [rip+0x13c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2e:
	/* 0x2e: movzx  r13d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_32:
	/* 0x32: mov    r12,QWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_39:
	/* 0x39: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3c:
	/* 0x3c: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_3f:
	/* 0x3f: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_42:
	/* 0x42: lea    rcx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_46:
	/* 0x46: add    rcx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_4a:
	/* 0x4a: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4d:
	/* 0x4d: ja     152 <tail_no_service_ipv4+0x152> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4d, 0x152, x86_l_152);
x86_l_53:
	/* 0x53: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_58:
	/* 0x58: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d:
	/* 0x5d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_60:
	/* 0x60: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_65:
	/* 0x65: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6a:
	/* 0x6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c:
	/* 0x6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6e:
	/* 0x6e: js     152 <tail_no_service_ipv4+0x152> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6e, 0x152, x86_l_152);
x86_l_74:
	/* 0x74: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_79:
	/* 0x79: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c:
	/* 0x7c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81:
	/* 0x81: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86:
	/* 0x86: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_8b:
	/* 0x8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d:
	/* 0x8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8f:
	/* 0x8f: js     152 <tail_no_service_ipv4+0x152> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8f, 0x152, x86_l_152);
x86_l_95:
	/* 0x95: add    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_98:
	/* 0x98: mov    r13d,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9d:
	/* 0x9d: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a6:
	/* 0xa6: movzx  eax,BYTE PTR [r12+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_ac:
	/* 0xac: mov    BYTE PTR [rsp+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_b0:
	/* 0xb0: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b3:
	/* 0xb3: cmp    ebp,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_b6:
	/* 0xb6: mov    r12d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 64ULL);
x86_l_bc:
	/* 0xbc: cmovl  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_L);
x86_l_c0:
	/* 0xc0: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_c5:
	/* 0xc5: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c8:
	/* 0xc8: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_cb:
	/* 0xcb: sub    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_cd:
	/* 0xcd: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_d0:
	/* 0xd0: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_d3:
	/* 0xd3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8:
	/* 0xd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da:
	/* 0xda: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_dc:
	/* 0xdc: js     129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdc, 0x129, x86_l_129);
x86_l_de:
	/* 0xde: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_e5:
	/* 0xe5: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e8:
	/* 0xe8: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_eb:
	/* 0xeb: cmp    edx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 15ULL);
x86_l_ee:
	/* 0xee: ja     f9 <tail_no_service_ipv4+0xf9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xee, 0xf9, x86_l_f9);
x86_l_f0:
	/* 0xf0: jne    129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf0, 0x129, x86_l_129);
x86_l_f2:
	/* 0xf2: movzx  r15d,BYTE PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_f7:
	/* 0xf7: jmp    129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JMP(0xf7, 0x129, x86_l_129);
x86_l_f9:
	/* 0xf9: movzx  r15d,WORD PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_fe:
	/* 0xfe: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_101:
	/* 0x101: jb     129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JCC(X86_CC_B, 0x101, 0x129, x86_l_129);
x86_l_103:
	/* 0x103: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_106:
	/* 0x106: ja     116 <tail_no_service_ipv4+0x116> */
	X86_SIM_X86_JCC(X86_CC_A, 0x106, 0x116, x86_l_116);
x86_l_108:
	/* 0x108: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_10b:
	/* 0x10b: je     129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b, 0x129, x86_l_129);
x86_l_10d:
	/* 0x10d: movzx  eax,BYTE PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_111:
	/* 0x111: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_114:
	/* 0x114: jmp    129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JMP(0x114, 0x129, x86_l_129);
x86_l_116:
	/* 0x116: movzx  eax,WORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_11a:
	/* 0x11a: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11d:
	/* 0x11d: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_120:
	/* 0x120: jae    30c <tail_no_service_ipv4+0x30c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x120, 0x30c, x86_l_30c);
x86_l_126:
	/* 0x126: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_129:
	/* 0x129: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_12e:
	/* 0x12e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_131:
	/* 0x131: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_136:
	/* 0x136: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_13b:
	/* 0x13b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d:
	/* 0x13d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f:
	/* 0x13f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_141:
	/* 0x141: js     152 <tail_no_service_ipv4+0x152> */
	X86_SIM_X86_JCC(X86_CC_S, 0x141, 0x152, x86_l_152);
x86_l_143:
	/* 0x143: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_146:
	/* 0x146: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_149:
	/* 0x149: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_14c:
	/* 0x14c: ja     20b <tail_no_service_ipv4+0x20b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x14c, 0x20b, x86_l_20b);
x86_l_152:
	/* 0x152: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_157:
	/* 0x157: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_159:
	/* 0x159: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15b:
	/* 0x15b: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_15e:
	/* 0x15e: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_161:
	/* 0x161: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_165:
	/* 0x165: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_16c:
	/* 0x16c: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f:
	/* 0x16f: movabs rcx,0x902690200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 649196753605623808ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_17d:
	/* 0x17d: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_181:
	/* 0x181: movabs rcx,0x6909020100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 451122692352ULL);
x86_l_18b:
	/* 0x18b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190:
	/* 0x190: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_194:
	/* 0x194: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_199:
	/* 0x199: mov    rdi,QWORD PTR [rip+0x13c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a0:
	/* 0x1a0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5:
	/* 0x1a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7:
	/* 0x1a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1aa:
	/* 0x1aa: je     1b5 <tail_no_service_ipv4+0x1b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa, 0x1b5, x86_l_1b5);
x86_l_1ac:
	/* 0x1ac: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1af:
	/* 0x1af: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b3:
	/* 0x1b3: jmp    1dd <tail_no_service_ipv4+0x1dd> */
	X86_SIM_X86_JMP(0x1b3, 0x1dd, x86_l_1dd);
x86_l_1b5:
	/* 0x1b5: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c3:
	/* 0x1c3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c8:
	/* 0x1c8: mov    rdi,QWORD PTR [rip+0x13c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1cf:
	/* 0x1cf: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d4:
	/* 0x1d4: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d9:
	/* 0x1d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1db:
	/* 0x1db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd:
	/* 0x1dd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e2:
	/* 0x1e2: mov    rsi,QWORD PTR [rip+0x13c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1e9:
	/* 0x1e9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ec:
	/* 0x1ec: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1f1:
	/* 0x1f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3:
	/* 0x1f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f8:
	/* 0x1f8: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1fc:
	/* 0x1fc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1fd:
	/* 0x1fd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_201:
	/* 0x201: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_203:
	/* 0x203: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_205:
	/* 0x205: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_206:
	/* 0x206: jmp    778 <tail_no_service_ipv4+0x778> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_20b:
	/* 0x20b: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_20e:
	/* 0x20e: mov    r13,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_215:
	/* 0x215: movzx  eax,WORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_21a:
	/* 0x21a: mov    WORD PTR [r13+0x4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21f:
	/* 0x21f: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_223:
	/* 0x223: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227:
	/* 0x227: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_22c:
	/* 0x22c: mov    WORD PTR [r13+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_231:
	/* 0x231: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235:
	/* 0x235: mov    DWORD PTR [r13+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_239:
	/* 0x239: mov    WORD PTR [r13+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_240:
	/* 0x240: lea    rdi,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_244:
	/* 0x244: mov    BYTE PTR [r13+0xe],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542213ULL);
x86_l_249:
	/* 0x249: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24e:
	/* 0x24e: mov    BYTE PTR [r13+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_252:
	/* 0x252: add    r12d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_256:
	/* 0x256: movbe  WORD PTR [r13+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_25d:
	/* 0x25d: movabs rax,0x14000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1374389534720ULL);
x86_l_267:
	/* 0x267: mov    QWORD PTR [r13+0x12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_26b:
	/* 0x26b: mov    DWORD PTR [r13+0x1e],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_26f:
	/* 0x26f: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_273:
	/* 0x273: mov    DWORD PTR [r13+0x1a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_277:
	/* 0x277: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_27c:
	/* 0x27c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27e:
	/* 0x27e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_280:
	/* 0x280: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_283:
	/* 0x283: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_288:
	/* 0x288: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b:
	/* 0x28b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d:
	/* 0x28d: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_290:
	/* 0x290: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_293:
	/* 0x293: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_295:
	/* 0x295: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_297:
	/* 0x297: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_29a:
	/* 0x29a: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_29c:
	/* 0x29c: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_29e:
	/* 0x29e: mov    WORD PTR [r13+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a3:
	/* 0x2a3: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2a7:
	/* 0x2a7: mov    QWORD PTR [r13+0x22],0x303 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 146028888835ULL);
x86_l_2af:
	/* 0x2af: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2b4:
	/* 0x2b4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b6:
	/* 0x2b6: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2be:
	/* 0x2be: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c1:
	/* 0x2c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3:
	/* 0x2c3: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c6:
	/* 0x2c6: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c9:
	/* 0x2c9: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2cc:
	/* 0x2cc: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ce:
	/* 0x2ce: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2d0:
	/* 0x2d0: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2d3:
	/* 0x2d3: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d5:
	/* 0x2d5: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2d7:
	/* 0x2d7: mov    WORD PTR [r13+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dc:
	/* 0x2dc: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e0:
	/* 0x2e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e3:
	/* 0x2e3: je     2eb <tail_no_service_ipv4+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e3, 0x2eb, x86_l_2eb);
x86_l_2e5:
	/* 0x2e5: mov    ebp,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2eb:
	/* 0x2eb: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_2f0:
	/* 0x2f0: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_2f2:
	/* 0x2f2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4:
	/* 0x2f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f6:
	/* 0x2f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f8:
	/* 0x2f8: js     157 <tail_no_service_ipv4+0x157> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2f8, 0x157, x86_l_157);
x86_l_2fe:
	/* 0x2fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_301:
	/* 0x301: jne    1f8 <tail_no_service_ipv4+0x1f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x301, 0x1f8, x86_l_1f8);
x86_l_307:
	/* 0x307: jmp    157 <tail_no_service_ipv4+0x157> */
	X86_SIM_X86_JMP(0x307, 0x157, x86_l_157);
x86_l_30c:
	/* 0x30c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_30f:
	/* 0x30f: ja     328 <tail_no_service_ipv4+0x328> */
	X86_SIM_X86_JCC(X86_CC_A, 0x30f, 0x328, x86_l_328);
x86_l_311:
	/* 0x311: cmp    edx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 18ULL);
x86_l_314:
	/* 0x314: je     126 <tail_no_service_ipv4+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x314, 0x126, x86_l_126);
x86_l_31a:
	/* 0x31a: movzx  ecx,BYTE PTR [rcx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18ULL);
x86_l_31e:
	/* 0x31e: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_320:
	/* 0x320: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_323:
	/* 0x323: jmp    129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JMP(0x323, 0x129, x86_l_129);
x86_l_328:
	/* 0x328: movzx  esi,WORD PTR [rcx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_32c:
	/* 0x32c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_32e:
	/* 0x32e: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_331:
	/* 0x331: jb     126 <tail_no_service_ipv4+0x126> */
	X86_SIM_X86_JCC(X86_CC_B, 0x331, 0x126, x86_l_126);
x86_l_337:
	/* 0x337: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_33a:
	/* 0x33a: ja     34b <tail_no_service_ipv4+0x34b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x33a, 0x34b, x86_l_34b);
x86_l_33c:
	/* 0x33c: cmp    edx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_33f:
	/* 0x33f: je     126 <tail_no_service_ipv4+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33f, 0x126, x86_l_126);
x86_l_345:
	/* 0x345: movzx  ecx,BYTE PTR [rcx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_349:
	/* 0x349: jmp    31e <tail_no_service_ipv4+0x31e> */
	X86_SIM_X86_JMP(0x349, 0x31e, x86_l_31e);
x86_l_34b:
	/* 0x34b: movzx  esi,WORD PTR [rcx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_34f:
	/* 0x34f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_351:
	/* 0x351: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_354:
	/* 0x354: jb     126 <tail_no_service_ipv4+0x126> */
	X86_SIM_X86_JCC(X86_CC_B, 0x354, 0x126, x86_l_126);
x86_l_35a:
	/* 0x35a: cmp    edx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 23ULL);
x86_l_35d:
	/* 0x35d: ja     36e <tail_no_service_ipv4+0x36e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x35d, 0x36e, x86_l_36e);
x86_l_35f:
	/* 0x35f: cmp    edx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 22ULL);
x86_l_362:
	/* 0x362: je     126 <tail_no_service_ipv4+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x362, 0x126, x86_l_126);
x86_l_368:
	/* 0x368: movzx  ecx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_36c:
	/* 0x36c: jmp    31e <tail_no_service_ipv4+0x31e> */
	X86_SIM_X86_JMP(0x36c, 0x31e, x86_l_31e);
x86_l_36e:
	/* 0x36e: movzx  esi,WORD PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 22ULL);
x86_l_372:
	/* 0x372: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_374:
	/* 0x374: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_377:
	/* 0x377: jb     126 <tail_no_service_ipv4+0x126> */
	X86_SIM_X86_JCC(X86_CC_B, 0x377, 0x126, x86_l_126);
x86_l_37d:
	/* 0x37d: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_380:
	/* 0x380: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_383:
	/* 0x383: ja     392 <tail_no_service_ipv4+0x392> */
	X86_SIM_X86_JCC(X86_CC_A, 0x383, 0x392, x86_l_392);
x86_l_385:
	/* 0x385: cmp    edx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_388:
	/* 0x388: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x388, 0x39d, x86_l_39d);
x86_l_38a:
	/* 0x38a: movzx  ecx,BYTE PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_38e:
	/* 0x38e: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_390:
	/* 0x390: jmp    39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JMP(0x390, 0x39d, x86_l_39d);
x86_l_392:
	/* 0x392: movzx  esi,WORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_396:
	/* 0x396: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_398:
	/* 0x398: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_39b:
	/* 0x39b: jae    3a8 <tail_no_service_ipv4+0x3a8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x39b, 0x3a8, x86_l_3a8);
x86_l_39d:
	/* 0x39d: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_3a0:
	/* 0x3a0: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_3a3:
	/* 0x3a3: jmp    129 <tail_no_service_ipv4+0x129> */
	X86_SIM_X86_JMP(0x3a3, 0x129, x86_l_129);
x86_l_3a8:
	/* 0x3a8: cmp    edx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 27ULL);
x86_l_3ab:
	/* 0x3ab: ja     3b8 <tail_no_service_ipv4+0x3b8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3ab, 0x3b8, x86_l_3b8);
x86_l_3ad:
	/* 0x3ad: cmp    edx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 26ULL);
x86_l_3b0:
	/* 0x3b0: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b0, 0x39d, x86_l_39d);
x86_l_3b2:
	/* 0x3b2: movzx  ecx,BYTE PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_3b6:
	/* 0x3b6: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x3b6, 0x38e, x86_l_38e);
x86_l_3b8:
	/* 0x3b8: movzx  esi,WORD PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_3bc:
	/* 0x3bc: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3be:
	/* 0x3be: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_3c1:
	/* 0x3c1: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3c1, 0x39d, x86_l_39d);
x86_l_3c3:
	/* 0x3c3: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3c6:
	/* 0x3c6: ja     3d3 <tail_no_service_ipv4+0x3d3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c6, 0x3d3, x86_l_3d3);
x86_l_3c8:
	/* 0x3c8: cmp    edx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_3cb:
	/* 0x3cb: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cb, 0x39d, x86_l_39d);
x86_l_3cd:
	/* 0x3cd: movzx  ecx,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3d1:
	/* 0x3d1: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x3d1, 0x38e, x86_l_38e);
x86_l_3d3:
	/* 0x3d3: movzx  esi,WORD PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_3d7:
	/* 0x3d7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d9:
	/* 0x3d9: cmp    ebp,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_3dc:
	/* 0x3dc: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3dc, 0x39d, x86_l_39d);
x86_l_3de:
	/* 0x3de: cmp    edx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 31ULL);
x86_l_3e1:
	/* 0x3e1: ja     3ee <tail_no_service_ipv4+0x3ee> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3e1, 0x3ee, x86_l_3ee);
x86_l_3e3:
	/* 0x3e3: cmp    edx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 30ULL);
x86_l_3e6:
	/* 0x3e6: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e6, 0x39d, x86_l_39d);
x86_l_3e8:
	/* 0x3e8: movzx  ecx,BYTE PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3ec:
	/* 0x3ec: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x3ec, 0x38e, x86_l_38e);
x86_l_3ee:
	/* 0x3ee: movzx  esi,WORD PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 30ULL);
x86_l_3f2:
	/* 0x3f2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f4:
	/* 0x3f4: cmp    ebp,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 18ULL);
x86_l_3f7:
	/* 0x3f7: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3f7, 0x39d, x86_l_39d);
x86_l_3f9:
	/* 0x3f9: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_3fc:
	/* 0x3fc: ja     409 <tail_no_service_ipv4+0x409> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3fc, 0x409, x86_l_409);
x86_l_3fe:
	/* 0x3fe: cmp    edx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32ULL);
x86_l_401:
	/* 0x401: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x401, 0x39d, x86_l_39d);
x86_l_403:
	/* 0x403: movzx  ecx,BYTE PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_407:
	/* 0x407: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x407, 0x38e, x86_l_38e);
x86_l_409:
	/* 0x409: movzx  esi,WORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_40d:
	/* 0x40d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40f:
	/* 0x40f: cmp    ebp,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 20ULL);
x86_l_412:
	/* 0x412: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x412, 0x39d, x86_l_39d);
x86_l_414:
	/* 0x414: cmp    edx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 35ULL);
x86_l_417:
	/* 0x417: ja     42b <tail_no_service_ipv4+0x42b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x417, 0x42b, x86_l_42b);
x86_l_419:
	/* 0x419: cmp    edx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 34ULL);
x86_l_41c:
	/* 0x41c: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41c, 0x39d, x86_l_39d);
x86_l_422:
	/* 0x422: movzx  ecx,BYTE PTR [rcx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_426:
	/* 0x426: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x426, 0x38e, x86_l_38e);
x86_l_42b:
	/* 0x42b: movzx  esi,WORD PTR [rcx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_42f:
	/* 0x42f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_431:
	/* 0x431: cmp    ebp,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 22ULL);
x86_l_434:
	/* 0x434: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x434, 0x39d, x86_l_39d);
x86_l_43a:
	/* 0x43a: cmp    edx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_43d:
	/* 0x43d: ja     451 <tail_no_service_ipv4+0x451> */
	X86_SIM_X86_JCC(X86_CC_A, 0x43d, 0x451, x86_l_451);
x86_l_43f:
	/* 0x43f: cmp    edx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_442:
	/* 0x442: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x442, 0x39d, x86_l_39d);
x86_l_448:
	/* 0x448: movzx  ecx,BYTE PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_44c:
	/* 0x44c: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x44c, 0x38e, x86_l_38e);
x86_l_451:
	/* 0x451: movzx  esi,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_455:
	/* 0x455: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_457:
	/* 0x457: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_45a:
	/* 0x45a: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x45a, 0x39d, x86_l_39d);
x86_l_460:
	/* 0x460: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_463:
	/* 0x463: ja     477 <tail_no_service_ipv4+0x477> */
	X86_SIM_X86_JCC(X86_CC_A, 0x463, 0x477, x86_l_477);
x86_l_465:
	/* 0x465: cmp    edx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 38ULL);
x86_l_468:
	/* 0x468: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x468, 0x39d, x86_l_39d);
x86_l_46e:
	/* 0x46e: movzx  ecx,BYTE PTR [rcx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 38ULL);
x86_l_472:
	/* 0x472: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x472, 0x38e, x86_l_38e);
x86_l_477:
	/* 0x477: movzx  esi,WORD PTR [rcx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_47b:
	/* 0x47b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_47d:
	/* 0x47d: cmp    ebp,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 26ULL);
x86_l_480:
	/* 0x480: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x480, 0x39d, x86_l_39d);
x86_l_486:
	/* 0x486: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_489:
	/* 0x489: ja     49d <tail_no_service_ipv4+0x49d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x489, 0x49d, x86_l_49d);
x86_l_48b:
	/* 0x48b: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_48e:
	/* 0x48e: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48e, 0x39d, x86_l_39d);
x86_l_494:
	/* 0x494: movzx  ecx,BYTE PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_498:
	/* 0x498: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x498, 0x38e, x86_l_38e);
x86_l_49d:
	/* 0x49d: movzx  esi,WORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_4a1:
	/* 0x4a1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4a3:
	/* 0x4a3: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_4a6:
	/* 0x4a6: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4a6, 0x39d, x86_l_39d);
x86_l_4ac:
	/* 0x4ac: cmp    edx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 43ULL);
x86_l_4af:
	/* 0x4af: ja     4c3 <tail_no_service_ipv4+0x4c3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4af, 0x4c3, x86_l_4c3);
x86_l_4b1:
	/* 0x4b1: cmp    edx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 42ULL);
x86_l_4b4:
	/* 0x4b4: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b4, 0x39d, x86_l_39d);
x86_l_4ba:
	/* 0x4ba: movzx  ecx,BYTE PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_4be:
	/* 0x4be: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x4be, 0x38e, x86_l_38e);
x86_l_4c3:
	/* 0x4c3: movzx  esi,WORD PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_4c7:
	/* 0x4c7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4c9:
	/* 0x4c9: cmp    ebp,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 30ULL);
x86_l_4cc:
	/* 0x4cc: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4cc, 0x39d, x86_l_39d);
x86_l_4d2:
	/* 0x4d2: cmp    edx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 45ULL);
x86_l_4d5:
	/* 0x4d5: ja     4e9 <tail_no_service_ipv4+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4d5, 0x4e9, x86_l_4e9);
x86_l_4d7:
	/* 0x4d7: cmp    edx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 44ULL);
x86_l_4da:
	/* 0x4da: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4da, 0x39d, x86_l_39d);
x86_l_4e0:
	/* 0x4e0: movzx  ecx,BYTE PTR [rcx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_4e4:
	/* 0x4e4: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x4e4, 0x38e, x86_l_38e);
x86_l_4e9:
	/* 0x4e9: movzx  esi,WORD PTR [rcx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_4ed:
	/* 0x4ed: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4ef:
	/* 0x4ef: cmp    ebp,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_4f2:
	/* 0x4f2: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4f2, 0x39d, x86_l_39d);
x86_l_4f8:
	/* 0x4f8: cmp    edx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 47ULL);
x86_l_4fb:
	/* 0x4fb: ja     50f <tail_no_service_ipv4+0x50f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4fb, 0x50f, x86_l_50f);
x86_l_4fd:
	/* 0x4fd: cmp    edx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 46ULL);
x86_l_500:
	/* 0x500: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x500, 0x39d, x86_l_39d);
x86_l_506:
	/* 0x506: movzx  ecx,BYTE PTR [rcx+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 46ULL);
x86_l_50a:
	/* 0x50a: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x50a, 0x38e, x86_l_38e);
x86_l_50f:
	/* 0x50f: movzx  esi,WORD PTR [rcx+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 46ULL);
x86_l_513:
	/* 0x513: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_515:
	/* 0x515: cmp    ebp,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 34ULL);
x86_l_518:
	/* 0x518: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x518, 0x39d, x86_l_39d);
x86_l_51e:
	/* 0x51e: cmp    edx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 49ULL);
x86_l_521:
	/* 0x521: ja     535 <tail_no_service_ipv4+0x535> */
	X86_SIM_X86_JCC(X86_CC_A, 0x521, 0x535, x86_l_535);
x86_l_523:
	/* 0x523: cmp    edx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 48ULL);
x86_l_526:
	/* 0x526: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x526, 0x39d, x86_l_39d);
x86_l_52c:
	/* 0x52c: movzx  ecx,BYTE PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 48ULL);
x86_l_530:
	/* 0x530: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x530, 0x38e, x86_l_38e);
x86_l_535:
	/* 0x535: movzx  esi,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_539:
	/* 0x539: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_53b:
	/* 0x53b: cmp    ebp,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 36ULL);
x86_l_53e:
	/* 0x53e: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x53e, 0x39d, x86_l_39d);
x86_l_544:
	/* 0x544: cmp    edx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 51ULL);
x86_l_547:
	/* 0x547: ja     55b <tail_no_service_ipv4+0x55b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x547, 0x55b, x86_l_55b);
x86_l_549:
	/* 0x549: cmp    edx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 50ULL);
x86_l_54c:
	/* 0x54c: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54c, 0x39d, x86_l_39d);
x86_l_552:
	/* 0x552: movzx  ecx,BYTE PTR [rcx+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 50ULL);
x86_l_556:
	/* 0x556: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x556, 0x38e, x86_l_38e);
x86_l_55b:
	/* 0x55b: movzx  esi,WORD PTR [rcx+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_55f:
	/* 0x55f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_561:
	/* 0x561: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_564:
	/* 0x564: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x564, 0x39d, x86_l_39d);
x86_l_56a:
	/* 0x56a: cmp    edx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 53ULL);
x86_l_56d:
	/* 0x56d: ja     581 <tail_no_service_ipv4+0x581> */
	X86_SIM_X86_JCC(X86_CC_A, 0x56d, 0x581, x86_l_581);
x86_l_56f:
	/* 0x56f: cmp    edx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 52ULL);
x86_l_572:
	/* 0x572: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x572, 0x39d, x86_l_39d);
x86_l_578:
	/* 0x578: movzx  ecx,BYTE PTR [rcx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_57c:
	/* 0x57c: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x57c, 0x38e, x86_l_38e);
x86_l_581:
	/* 0x581: movzx  esi,WORD PTR [rcx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_585:
	/* 0x585: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_587:
	/* 0x587: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_58a:
	/* 0x58a: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x58a, 0x39d, x86_l_39d);
x86_l_590:
	/* 0x590: cmp    edx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 55ULL);
x86_l_593:
	/* 0x593: ja     5a7 <tail_no_service_ipv4+0x5a7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x593, 0x5a7, x86_l_5a7);
x86_l_595:
	/* 0x595: cmp    edx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 54ULL);
x86_l_598:
	/* 0x598: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x598, 0x39d, x86_l_39d);
x86_l_59e:
	/* 0x59e: movzx  ecx,BYTE PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 54ULL);
x86_l_5a2:
	/* 0x5a2: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x5a2, 0x38e, x86_l_38e);
x86_l_5a7:
	/* 0x5a7: movzx  esi,WORD PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 54ULL);
x86_l_5ab:
	/* 0x5ab: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ad:
	/* 0x5ad: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_5b0:
	/* 0x5b0: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5b0, 0x39d, x86_l_39d);
x86_l_5b6:
	/* 0x5b6: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_5b9:
	/* 0x5b9: ja     5cd <tail_no_service_ipv4+0x5cd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5b9, 0x5cd, x86_l_5cd);
x86_l_5bb:
	/* 0x5bb: cmp    edx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 56ULL);
x86_l_5be:
	/* 0x5be: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5be, 0x39d, x86_l_39d);
x86_l_5c4:
	/* 0x5c4: movzx  ecx,BYTE PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_5c8:
	/* 0x5c8: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x5c8, 0x38e, x86_l_38e);
x86_l_5cd:
	/* 0x5cd: movzx  esi,WORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_5d1:
	/* 0x5d1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d3:
	/* 0x5d3: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_5d6:
	/* 0x5d6: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5d6, 0x39d, x86_l_39d);
x86_l_5dc:
	/* 0x5dc: cmp    edx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 59ULL);
x86_l_5df:
	/* 0x5df: ja     5f3 <tail_no_service_ipv4+0x5f3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5df, 0x5f3, x86_l_5f3);
x86_l_5e1:
	/* 0x5e1: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_5e4:
	/* 0x5e4: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e4, 0x39d, x86_l_39d);
x86_l_5ea:
	/* 0x5ea: movzx  ecx,BYTE PTR [rcx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_5ee:
	/* 0x5ee: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x5ee, 0x38e, x86_l_38e);
x86_l_5f3:
	/* 0x5f3: movzx  esi,WORD PTR [rcx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_5f7:
	/* 0x5f7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5f9:
	/* 0x5f9: cmp    ebp,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 46ULL);
x86_l_5fc:
	/* 0x5fc: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5fc, 0x39d, x86_l_39d);
x86_l_602:
	/* 0x602: cmp    edx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 61ULL);
x86_l_605:
	/* 0x605: ja     619 <tail_no_service_ipv4+0x619> */
	X86_SIM_X86_JCC(X86_CC_A, 0x605, 0x619, x86_l_619);
x86_l_607:
	/* 0x607: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_60a:
	/* 0x60a: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60a, 0x39d, x86_l_39d);
x86_l_610:
	/* 0x610: movzx  ecx,BYTE PTR [rcx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_614:
	/* 0x614: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x614, 0x38e, x86_l_38e);
x86_l_619:
	/* 0x619: movzx  esi,WORD PTR [rcx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_61d:
	/* 0x61d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_61f:
	/* 0x61f: cmp    ebp,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 48ULL);
x86_l_622:
	/* 0x622: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x622, 0x39d, x86_l_39d);
x86_l_628:
	/* 0x628: cmp    edx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_62b:
	/* 0x62b: ja     63f <tail_no_service_ipv4+0x63f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x62b, 0x63f, x86_l_63f);
x86_l_62d:
	/* 0x62d: cmp    edx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 62ULL);
x86_l_630:
	/* 0x630: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x630, 0x39d, x86_l_39d);
x86_l_636:
	/* 0x636: movzx  ecx,BYTE PTR [rcx+0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 62ULL);
x86_l_63a:
	/* 0x63a: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x63a, 0x38e, x86_l_38e);
x86_l_63f:
	/* 0x63f: movzx  esi,WORD PTR [rcx+0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 62ULL);
x86_l_643:
	/* 0x643: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_645:
	/* 0x645: cmp    ebp,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 50ULL);
x86_l_648:
	/* 0x648: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x648, 0x39d, x86_l_39d);
x86_l_64e:
	/* 0x64e: cmp    edx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 65ULL);
x86_l_651:
	/* 0x651: ja     665 <tail_no_service_ipv4+0x665> */
	X86_SIM_X86_JCC(X86_CC_A, 0x651, 0x665, x86_l_665);
x86_l_653:
	/* 0x653: cmp    edx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_656:
	/* 0x656: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x656, 0x39d, x86_l_39d);
x86_l_65c:
	/* 0x65c: movzx  ecx,BYTE PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_660:
	/* 0x660: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x660, 0x38e, x86_l_38e);
x86_l_665:
	/* 0x665: movzx  esi,WORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_669:
	/* 0x669: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_66b:
	/* 0x66b: cmp    ebp,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 52ULL);
x86_l_66e:
	/* 0x66e: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x66e, 0x39d, x86_l_39d);
x86_l_674:
	/* 0x674: cmp    edx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 67ULL);
x86_l_677:
	/* 0x677: ja     68b <tail_no_service_ipv4+0x68b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x677, 0x68b, x86_l_68b);
x86_l_679:
	/* 0x679: cmp    edx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 66ULL);
x86_l_67c:
	/* 0x67c: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67c, 0x39d, x86_l_39d);
x86_l_682:
	/* 0x682: movzx  ecx,BYTE PTR [rcx+0x42] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 66ULL);
x86_l_686:
	/* 0x686: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x686, 0x38e, x86_l_38e);
x86_l_68b:
	/* 0x68b: movzx  esi,WORD PTR [rcx+0x42] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 66ULL);
x86_l_68f:
	/* 0x68f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_691:
	/* 0x691: cmp    ebp,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 54ULL);
x86_l_694:
	/* 0x694: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x694, 0x39d, x86_l_39d);
x86_l_69a:
	/* 0x69a: cmp    edx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 69ULL);
x86_l_69d:
	/* 0x69d: ja     6b1 <tail_no_service_ipv4+0x6b1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x69d, 0x6b1, x86_l_6b1);
x86_l_69f:
	/* 0x69f: cmp    edx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 68ULL);
x86_l_6a2:
	/* 0x6a2: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a2, 0x39d, x86_l_39d);
x86_l_6a8:
	/* 0x6a8: movzx  ecx,BYTE PTR [rcx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 68ULL);
x86_l_6ac:
	/* 0x6ac: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x6ac, 0x38e, x86_l_38e);
x86_l_6b1:
	/* 0x6b1: movzx  esi,WORD PTR [rcx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 68ULL);
x86_l_6b5:
	/* 0x6b5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6b7:
	/* 0x6b7: cmp    ebp,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 56ULL);
x86_l_6ba:
	/* 0x6ba: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6ba, 0x39d, x86_l_39d);
x86_l_6c0:
	/* 0x6c0: cmp    edx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_6c3:
	/* 0x6c3: ja     6d7 <tail_no_service_ipv4+0x6d7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6c3, 0x6d7, x86_l_6d7);
x86_l_6c5:
	/* 0x6c5: cmp    edx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 70ULL);
x86_l_6c8:
	/* 0x6c8: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c8, 0x39d, x86_l_39d);
x86_l_6ce:
	/* 0x6ce: movzx  ecx,BYTE PTR [rcx+0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 70ULL);
x86_l_6d2:
	/* 0x6d2: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x6d2, 0x38e, x86_l_38e);
x86_l_6d7:
	/* 0x6d7: movzx  esi,WORD PTR [rcx+0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 70ULL);
x86_l_6db:
	/* 0x6db: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6dd:
	/* 0x6dd: cmp    ebp,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 58ULL);
x86_l_6e0:
	/* 0x6e0: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6e0, 0x39d, x86_l_39d);
x86_l_6e6:
	/* 0x6e6: cmp    edx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 73ULL);
x86_l_6e9:
	/* 0x6e9: ja     6fd <tail_no_service_ipv4+0x6fd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6e9, 0x6fd, x86_l_6fd);
x86_l_6eb:
	/* 0x6eb: cmp    edx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_6ee:
	/* 0x6ee: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ee, 0x39d, x86_l_39d);
x86_l_6f4:
	/* 0x6f4: movzx  ecx,BYTE PTR [rcx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_6f8:
	/* 0x6f8: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x6f8, 0x38e, x86_l_38e);
x86_l_6fd:
	/* 0x6fd: movzx  esi,WORD PTR [rcx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 72ULL);
x86_l_701:
	/* 0x701: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_703:
	/* 0x703: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_706:
	/* 0x706: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x706, 0x39d, x86_l_39d);
x86_l_70c:
	/* 0x70c: cmp    edx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 75ULL);
x86_l_70f:
	/* 0x70f: ja     723 <tail_no_service_ipv4+0x723> */
	X86_SIM_X86_JCC(X86_CC_A, 0x70f, 0x723, x86_l_723);
x86_l_711:
	/* 0x711: cmp    edx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 74ULL);
x86_l_714:
	/* 0x714: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x714, 0x39d, x86_l_39d);
x86_l_71a:
	/* 0x71a: movzx  ecx,BYTE PTR [rcx+0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 74ULL);
x86_l_71e:
	/* 0x71e: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x71e, 0x38e, x86_l_38e);
x86_l_723:
	/* 0x723: movzx  esi,WORD PTR [rcx+0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 74ULL);
x86_l_727:
	/* 0x727: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_729:
	/* 0x729: cmp    ebp,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 62ULL);
x86_l_72c:
	/* 0x72c: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x72c, 0x39d, x86_l_39d);
x86_l_732:
	/* 0x732: cmp    edx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 77ULL);
x86_l_735:
	/* 0x735: ja     749 <tail_no_service_ipv4+0x749> */
	X86_SIM_X86_JCC(X86_CC_A, 0x735, 0x749, x86_l_749);
x86_l_737:
	/* 0x737: cmp    edx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 76ULL);
x86_l_73a:
	/* 0x73a: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73a, 0x39d, x86_l_39d);
x86_l_740:
	/* 0x740: movzx  ecx,BYTE PTR [rcx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 76ULL);
x86_l_744:
	/* 0x744: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x744, 0x38e, x86_l_38e);
x86_l_749:
	/* 0x749: movzx  esi,WORD PTR [rcx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_74d:
	/* 0x74d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_74f:
	/* 0x74f: cmp    ebp,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_752:
	/* 0x752: jb     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x752, 0x39d, x86_l_39d);
x86_l_758:
	/* 0x758: cmp    edx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 79ULL);
x86_l_75b:
	/* 0x75b: ja     76f <tail_no_service_ipv4+0x76f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x75b, 0x76f, x86_l_76f);
x86_l_75d:
	/* 0x75d: cmp    edx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 78ULL);
x86_l_760:
	/* 0x760: je     39d <tail_no_service_ipv4+0x39d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x760, 0x39d, x86_l_39d);
x86_l_766:
	/* 0x766: movzx  ecx,BYTE PTR [rcx+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 78ULL);
x86_l_76a:
	/* 0x76a: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x76a, 0x38e, x86_l_38e);
x86_l_76f:
	/* 0x76f: movzx  ecx,WORD PTR [rcx+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 78ULL);
x86_l_773:
	/* 0x773: jmp    38e <tail_no_service_ipv4+0x38e> */
	X86_SIM_X86_JMP(0x773, 0x38e, x86_l_38e);
x86_l_778:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
