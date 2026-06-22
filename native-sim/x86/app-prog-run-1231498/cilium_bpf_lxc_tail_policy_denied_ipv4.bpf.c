extern char __config_endpoint_id;
extern char __config_security_label;
extern char cilium_calls;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_policy_denied_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: movabs r15,0x20a970200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 8767603200ULL);
x86_l_14:
	/* 0x14: movzx  r14d,BYTE PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_19:
	/* 0x19: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22:
	/* 0x22: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b:
	/* 0x2b: mov    r12d,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f:
	/* 0x2f: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_32:
	/* 0x32: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_35:
	/* 0x35: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_38:
	/* 0x38: jb     16e <tail_policy_denied_ipv4+0x16e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x38, 0x16e, x86_l_16e);
x86_l_3e:
	/* 0x3e: mov    rbp,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_45:
	/* 0x45: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4a:
	/* 0x4a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f:
	/* 0x4f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_52:
	/* 0x52: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_57:
	/* 0x57: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5c:
	/* 0x5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e:
	/* 0x5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60:
	/* 0x60: js     e8 <tail_policy_denied_ipv4+0xe8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x60, 0xe8, x86_l_e8);
x86_l_66:
	/* 0x66: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_6b:
	/* 0x6b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e:
	/* 0x6e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73:
	/* 0x73: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_78:
	/* 0x78: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7d:
	/* 0x7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f:
	/* 0x7f: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_83:
	/* 0x83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: js     16e <tail_policy_denied_ipv4+0x16e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x85, 0x16e, x86_l_16e);
x86_l_8b:
	/* 0x8b: mov    eax,DWORD PTR [rbp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_8e:
	/* 0x8e: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_92:
	/* 0x92: mov    eax,DWORD PTR [rbp+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_95:
	/* 0x95: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_99:
	/* 0x99: movzx  eax,BYTE PTR [rbp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_9d:
	/* 0x9d: mov    BYTE PTR [rsp+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_a1:
	/* 0xa1: cmp    r12d,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 64ULL);
x86_l_a5:
	/* 0xa5: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_aa:
	/* 0xaa: cmovl  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_L);
x86_l_ae:
	/* 0xae: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_b3:
	/* 0xb3: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b6:
	/* 0xb6: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_b8:
	/* 0xb8: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_bb:
	/* 0xbb: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_be:
	/* 0xbe: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_c1:
	/* 0xc1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c6:
	/* 0xc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8:
	/* 0xc8: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_cb:
	/* 0xcb: js     141 <tail_policy_denied_ipv4+0x141> */
	X86_SIM_X86_JCC(X86_CC_S, 0xcb, 0x141, x86_l_141);
x86_l_cd:
	/* 0xcd: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d4:
	/* 0xd4: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d7:
	/* 0xd7: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_da:
	/* 0xda: cmp    edx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 15ULL);
x86_l_dd:
	/* 0xdd: ja     f1 <tail_policy_denied_ipv4+0xf1> */
	X86_SIM_X86_JCC(X86_CC_A, 0xdd, 0xf1, x86_l_f1);
x86_l_df:
	/* 0xdf: jne    141 <tail_policy_denied_ipv4+0x141> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdf, 0x141, x86_l_141);
x86_l_e1:
	/* 0xe1: movzx  r13d,BYTE PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_e6:
	/* 0xe6: jmp    141 <tail_policy_denied_ipv4+0x141> */
	X86_SIM_X86_JMP(0xe6, 0x141, x86_l_141);
x86_l_e8:
	/* 0xe8: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ec:
	/* 0xec: jmp    16e <tail_policy_denied_ipv4+0x16e> */
	X86_SIM_X86_JMP(0xec, 0x16e, x86_l_16e);
x86_l_f1:
	/* 0xf1: movzx  r13d,WORD PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_f6:
	/* 0xf6: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_fa:
	/* 0xfa: jb     141 <tail_policy_denied_ipv4+0x141> */
	X86_SIM_X86_JCC(X86_CC_B, 0xfa, 0x141, x86_l_141);
x86_l_fc:
	/* 0xfc: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_ff:
	/* 0xff: ja     10f <tail_policy_denied_ipv4+0x10f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xff, 0x10f, x86_l_10f);
x86_l_101:
	/* 0x101: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_104:
	/* 0x104: je     141 <tail_policy_denied_ipv4+0x141> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104, 0x141, x86_l_141);
x86_l_106:
	/* 0x106: movzx  eax,BYTE PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_10a:
	/* 0x10a: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10d:
	/* 0x10d: jmp    141 <tail_policy_denied_ipv4+0x141> */
	X86_SIM_X86_JMP(0x10d, 0x141, x86_l_141);
x86_l_10f:
	/* 0x10f: movzx  eax,WORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_113:
	/* 0x113: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_116:
	/* 0x116: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_11a:
	/* 0x11a: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x11a, 0x13e, x86_l_13e);
x86_l_11c:
	/* 0x11c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_11f:
	/* 0x11f: ja     12e <tail_policy_denied_ipv4+0x12e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11f, 0x12e, x86_l_12e);
x86_l_121:
	/* 0x121: cmp    edx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 18ULL);
x86_l_124:
	/* 0x124: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x124, 0x13e, x86_l_13e);
x86_l_126:
	/* 0x126: movzx  ecx,BYTE PTR [rcx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18ULL);
x86_l_12a:
	/* 0x12a: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12c:
	/* 0x12c: jmp    13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JMP(0x12c, 0x13e, x86_l_13e);
x86_l_12e:
	/* 0x12e: movzx  esi,WORD PTR [rcx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_132:
	/* 0x132: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_134:
	/* 0x134: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_138:
	/* 0x138: jae    39a <tail_policy_denied_ipv4+0x39a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x138, 0x39a, x86_l_39a);
x86_l_13e:
	/* 0x13e: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_141:
	/* 0x141: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_146:
	/* 0x146: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_149:
	/* 0x149: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_14e:
	/* 0x14e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_153:
	/* 0x153: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155:
	/* 0x155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157:
	/* 0x157: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15b:
	/* 0x15b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15d:
	/* 0x15d: js     16e <tail_policy_denied_ipv4+0x16e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15d, 0x16e, x86_l_16e);
x86_l_15f:
	/* 0x15f: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_162:
	/* 0x162: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_165:
	/* 0x165: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_168:
	/* 0x168: ja     217 <tail_policy_denied_ipv4+0x217> */
	X86_SIM_X86_JCC(X86_CC_A, 0x168, 0x217, x86_l_217);
x86_l_16e:
	/* 0x16e: mov    rax,QWORD PTR [rip+0x11744] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_175:
	/* 0x175: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_177:
	/* 0x177: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17a:
	/* 0x17a: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_181:
	/* 0x181: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_185:
	/* 0x185: movabs rax,0xa9c020200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 764488244359331840ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_193:
	/* 0x193: mov    r12d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R12, X86_WIDTH_32);
x86_l_196:
	/* 0x196: add    r15,0x50000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 327680ULL);
x86_l_19d:
	/* 0x19d: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2:
	/* 0x1a2: mov    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7:
	/* 0x1a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ac:
	/* 0x1ac: mov    rdi,QWORD PTR [rip+0x11744] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b3:
	/* 0x1b3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8:
	/* 0x1b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba:
	/* 0x1ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bd:
	/* 0x1bd: je     1c8 <tail_policy_denied_ipv4+0x1c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bd, 0x1c8, x86_l_1c8);
x86_l_1bf:
	/* 0x1bf: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c2:
	/* 0x1c2: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c6:
	/* 0x1c6: jmp    1f0 <tail_policy_denied_ipv4+0x1f0> */
	X86_SIM_X86_JMP(0x1c6, 0x1f0, x86_l_1f0);
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1d1:
	/* 0x1d1: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1db:
	/* 0x1db: mov    rdi,QWORD PTR [rip+0x11744] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1e2:
	/* 0x1e2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e7:
	/* 0x1e7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec:
	/* 0x1ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee:
	/* 0x1ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0:
	/* 0x1f0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f5:
	/* 0x1f5: mov    rsi,QWORD PTR [rip+0x11744] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1fc:
	/* 0x1fc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_204:
	/* 0x204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206:
	/* 0x206: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_20b:
	/* 0x20b: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_20f:
	/* 0x20f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_211:
	/* 0x211: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_212:
	/* 0x212: jmp    825 <tail_policy_denied_ipv4+0x825> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_217:
	/* 0x217: mov    r12,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_21e:
	/* 0x21e: movzx  eax,WORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_223:
	/* 0x223: mov    WORD PTR [r12+0x4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_229:
	/* 0x229: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d:
	/* 0x22d: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231:
	/* 0x231: movzx  eax,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_236:
	/* 0x236: mov    WORD PTR [r12+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_23c:
	/* 0x23c: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_240:
	/* 0x240: mov    DWORD PTR [r12+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_245:
	/* 0x245: mov    WORD PTR [r12+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_24d:
	/* 0x24d: lea    rdi,[r12+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_252:
	/* 0x252: mov    BYTE PTR [r12+0xe],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542213ULL);
x86_l_258:
	/* 0x258: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25d:
	/* 0x25d: mov    BYTE PTR [r12+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_262:
	/* 0x262: add    ebp,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_265:
	/* 0x265: movbe  WORD PTR [r12+0x10],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R12, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_26d:
	/* 0x26d: movabs rax,0x14000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1374389534720ULL);
x86_l_277:
	/* 0x277: mov    QWORD PTR [r12+0x12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_27c:
	/* 0x27c: mov    eax,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_280:
	/* 0x280: mov    DWORD PTR [r12+0x1e],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_285:
	/* 0x285: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_289:
	/* 0x289: mov    DWORD PTR [r12+0x1a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_28e:
	/* 0x28e: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_293:
	/* 0x293: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_295:
	/* 0x295: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_297:
	/* 0x297: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_29a:
	/* 0x29a: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_29f:
	/* 0x29f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a7:
	/* 0x2a7: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2aa:
	/* 0x2aa: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ac:
	/* 0x2ac: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2ae:
	/* 0x2ae: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2b1:
	/* 0x2b1: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b3:
	/* 0x2b3: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2b5:
	/* 0x2b5: mov    WORD PTR [r12+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bb:
	/* 0x2bb: lea    rdi,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2c0:
	/* 0x2c0: mov    QWORD PTR [r12+0x22],0xd03 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 146028891395ULL);
x86_l_2c9:
	/* 0x2c9: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2ce:
	/* 0x2ce: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d0:
	/* 0x2d0: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2d3:
	/* 0x2d3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d8:
	/* 0x2d8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2db:
	/* 0x2db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd:
	/* 0x2dd: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e0:
	/* 0x2e0: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e3:
	/* 0x2e3: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2e6:
	/* 0x2e6: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e8:
	/* 0x2e8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2ea:
	/* 0x2ea: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2ed:
	/* 0x2ed: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ef:
	/* 0x2ef: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2f1:
	/* 0x2f1: mov    WORD PTR [r12+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f7:
	/* 0x2f7: mov    rax,QWORD PTR [rip+0x11747] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_2fe:
	/* 0x2fe: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_301:
	/* 0x301: mov    rax,QWORD PTR [rip+0x11747] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_308:
	/* 0x308: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a:
	/* 0x30a: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30e:
	/* 0x30e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_311:
	/* 0x311: je     319 <tail_policy_denied_ipv4+0x319> */
	X86_SIM_X86_JCC(X86_CC_E, 0x311, 0x319, x86_l_319);
x86_l_313:
	/* 0x313: mov    ebp,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_319:
	/* 0x319: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_31e:
	/* 0x31e: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_320:
	/* 0x320: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_322:
	/* 0x322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324:
	/* 0x324: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_328:
	/* 0x328: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32a:
	/* 0x32a: js     16e <tail_policy_denied_ipv4+0x16e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x32a, 0x16e, x86_l_16e);
x86_l_330:
	/* 0x330: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_333:
	/* 0x333: je     16e <tail_policy_denied_ipv4+0x16e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x333, 0x16e, x86_l_16e);
x86_l_339:
	/* 0x339: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_33b:
	/* 0x33b: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_340:
	/* 0x340: mov    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_345:
	/* 0x345: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34a:
	/* 0x34a: mov    rdi,QWORD PTR [rip+0x11747] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_351:
	/* 0x351: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_356:
	/* 0x356: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358:
	/* 0x358: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35b:
	/* 0x35b: je     36b <tail_policy_denied_ipv4+0x36b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35b, 0x36b, x86_l_36b);
x86_l_35d:
	/* 0x35d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_360:
	/* 0x360: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_364:
	/* 0x364: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_366:
	/* 0x366: jmp    20b <tail_policy_denied_ipv4+0x20b> */
	X86_SIM_X86_JMP(0x366, 0x20b, x86_l_20b);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_374:
	/* 0x374: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_379:
	/* 0x379: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37e:
	/* 0x37e: mov    rdi,QWORD PTR [rip+0x11747] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_385:
	/* 0x385: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38a:
	/* 0x38a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38f:
	/* 0x38f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_391:
	/* 0x391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393:
	/* 0x393: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_395:
	/* 0x395: jmp    20b <tail_policy_denied_ipv4+0x20b> */
	X86_SIM_X86_JMP(0x395, 0x20b, x86_l_20b);
x86_l_39a:
	/* 0x39a: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_39d:
	/* 0x39d: ja     3b1 <tail_policy_denied_ipv4+0x3b1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x39d, 0x3b1, x86_l_3b1);
x86_l_39f:
	/* 0x39f: cmp    edx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_3a2:
	/* 0x3a2: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a2, 0x13e, x86_l_13e);
x86_l_3a8:
	/* 0x3a8: movzx  ecx,BYTE PTR [rcx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_3ac:
	/* 0x3ac: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x3ac, 0x12a, x86_l_12a);
x86_l_3b1:
	/* 0x3b1: movzx  esi,WORD PTR [rcx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_3b5:
	/* 0x3b5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b7:
	/* 0x3b7: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_3bb:
	/* 0x3bb: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3bb, 0x13e, x86_l_13e);
x86_l_3c1:
	/* 0x3c1: cmp    edx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 23ULL);
x86_l_3c4:
	/* 0x3c4: ja     3d8 <tail_policy_denied_ipv4+0x3d8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c4, 0x3d8, x86_l_3d8);
x86_l_3c6:
	/* 0x3c6: cmp    edx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 22ULL);
x86_l_3c9:
	/* 0x3c9: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c9, 0x13e, x86_l_13e);
x86_l_3cf:
	/* 0x3cf: movzx  ecx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_3d3:
	/* 0x3d3: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x3d3, 0x12a, x86_l_12a);
x86_l_3d8:
	/* 0x3d8: movzx  esi,WORD PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 22ULL);
x86_l_3dc:
	/* 0x3dc: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3de:
	/* 0x3de: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_3e2:
	/* 0x3e2: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3e2, 0x13e, x86_l_13e);
x86_l_3e8:
	/* 0x3e8: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_3eb:
	/* 0x3eb: ja     3ff <tail_policy_denied_ipv4+0x3ff> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3eb, 0x3ff, x86_l_3ff);
x86_l_3ed:
	/* 0x3ed: cmp    edx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_3f0:
	/* 0x3f0: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f0, 0x13e, x86_l_13e);
x86_l_3f6:
	/* 0x3f6: movzx  ecx,BYTE PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_3fa:
	/* 0x3fa: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x3fa, 0x12a, x86_l_12a);
x86_l_3ff:
	/* 0x3ff: movzx  esi,WORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_403:
	/* 0x403: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_405:
	/* 0x405: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_409:
	/* 0x409: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x409, 0x13e, x86_l_13e);
x86_l_40f:
	/* 0x40f: cmp    edx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 27ULL);
x86_l_412:
	/* 0x412: ja     426 <tail_policy_denied_ipv4+0x426> */
	X86_SIM_X86_JCC(X86_CC_A, 0x412, 0x426, x86_l_426);
x86_l_414:
	/* 0x414: cmp    edx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 26ULL);
x86_l_417:
	/* 0x417: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x417, 0x13e, x86_l_13e);
x86_l_41d:
	/* 0x41d: movzx  ecx,BYTE PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_421:
	/* 0x421: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x421, 0x12a, x86_l_12a);
x86_l_426:
	/* 0x426: movzx  esi,WORD PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_42a:
	/* 0x42a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_42c:
	/* 0x42c: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_430:
	/* 0x430: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x430, 0x13e, x86_l_13e);
x86_l_436:
	/* 0x436: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_439:
	/* 0x439: ja     44d <tail_policy_denied_ipv4+0x44d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x439, 0x44d, x86_l_44d);
x86_l_43b:
	/* 0x43b: cmp    edx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_43e:
	/* 0x43e: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43e, 0x13e, x86_l_13e);
x86_l_444:
	/* 0x444: movzx  ecx,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_448:
	/* 0x448: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x448, 0x12a, x86_l_12a);
x86_l_44d:
	/* 0x44d: movzx  esi,WORD PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_451:
	/* 0x451: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_453:
	/* 0x453: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_457:
	/* 0x457: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x457, 0x13e, x86_l_13e);
x86_l_45d:
	/* 0x45d: cmp    edx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 31ULL);
x86_l_460:
	/* 0x460: ja     474 <tail_policy_denied_ipv4+0x474> */
	X86_SIM_X86_JCC(X86_CC_A, 0x460, 0x474, x86_l_474);
x86_l_462:
	/* 0x462: cmp    edx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 30ULL);
x86_l_465:
	/* 0x465: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x465, 0x13e, x86_l_13e);
x86_l_46b:
	/* 0x46b: movzx  ecx,BYTE PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_46f:
	/* 0x46f: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x46f, 0x12a, x86_l_12a);
x86_l_474:
	/* 0x474: movzx  esi,WORD PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 30ULL);
x86_l_478:
	/* 0x478: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_47a:
	/* 0x47a: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_47e:
	/* 0x47e: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x47e, 0x13e, x86_l_13e);
x86_l_484:
	/* 0x484: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_487:
	/* 0x487: ja     49b <tail_policy_denied_ipv4+0x49b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x487, 0x49b, x86_l_49b);
x86_l_489:
	/* 0x489: cmp    edx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32ULL);
x86_l_48c:
	/* 0x48c: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48c, 0x13e, x86_l_13e);
x86_l_492:
	/* 0x492: movzx  ecx,BYTE PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_496:
	/* 0x496: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x496, 0x12a, x86_l_12a);
x86_l_49b:
	/* 0x49b: movzx  esi,WORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_49f:
	/* 0x49f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4a1:
	/* 0x4a1: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_4a5:
	/* 0x4a5: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4a5, 0x13e, x86_l_13e);
x86_l_4ab:
	/* 0x4ab: cmp    edx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 35ULL);
x86_l_4ae:
	/* 0x4ae: ja     4c2 <tail_policy_denied_ipv4+0x4c2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4ae, 0x4c2, x86_l_4c2);
x86_l_4b0:
	/* 0x4b0: cmp    edx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 34ULL);
x86_l_4b3:
	/* 0x4b3: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b3, 0x13e, x86_l_13e);
x86_l_4b9:
	/* 0x4b9: movzx  ecx,BYTE PTR [rcx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4bd:
	/* 0x4bd: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x4bd, 0x12a, x86_l_12a);
x86_l_4c2:
	/* 0x4c2: movzx  esi,WORD PTR [rcx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_4c6:
	/* 0x4c6: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4c8:
	/* 0x4c8: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_4cc:
	/* 0x4cc: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4cc, 0x13e, x86_l_13e);
x86_l_4d2:
	/* 0x4d2: cmp    edx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_4d5:
	/* 0x4d5: ja     4e9 <tail_policy_denied_ipv4+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4d5, 0x4e9, x86_l_4e9);
x86_l_4d7:
	/* 0x4d7: cmp    edx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_4da:
	/* 0x4da: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4da, 0x13e, x86_l_13e);
x86_l_4e0:
	/* 0x4e0: movzx  ecx,BYTE PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_4e4:
	/* 0x4e4: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x4e4, 0x12a, x86_l_12a);
x86_l_4e9:
	/* 0x4e9: movzx  esi,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_4ed:
	/* 0x4ed: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4ef:
	/* 0x4ef: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_4f3:
	/* 0x4f3: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4f3, 0x13e, x86_l_13e);
x86_l_4f9:
	/* 0x4f9: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_4fc:
	/* 0x4fc: ja     510 <tail_policy_denied_ipv4+0x510> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4fc, 0x510, x86_l_510);
x86_l_4fe:
	/* 0x4fe: cmp    edx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 38ULL);
x86_l_501:
	/* 0x501: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x501, 0x13e, x86_l_13e);
x86_l_507:
	/* 0x507: movzx  ecx,BYTE PTR [rcx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 38ULL);
x86_l_50b:
	/* 0x50b: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x50b, 0x12a, x86_l_12a);
x86_l_510:
	/* 0x510: movzx  esi,WORD PTR [rcx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_514:
	/* 0x514: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_516:
	/* 0x516: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_51a:
	/* 0x51a: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x51a, 0x13e, x86_l_13e);
x86_l_520:
	/* 0x520: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_523:
	/* 0x523: ja     537 <tail_policy_denied_ipv4+0x537> */
	X86_SIM_X86_JCC(X86_CC_A, 0x523, 0x537, x86_l_537);
x86_l_525:
	/* 0x525: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_528:
	/* 0x528: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x528, 0x13e, x86_l_13e);
x86_l_52e:
	/* 0x52e: movzx  ecx,BYTE PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_532:
	/* 0x532: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x532, 0x12a, x86_l_12a);
x86_l_537:
	/* 0x537: movzx  esi,WORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_53b:
	/* 0x53b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_53d:
	/* 0x53d: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_541:
	/* 0x541: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x541, 0x13e, x86_l_13e);
x86_l_547:
	/* 0x547: cmp    edx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 43ULL);
x86_l_54a:
	/* 0x54a: ja     55e <tail_policy_denied_ipv4+0x55e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x54a, 0x55e, x86_l_55e);
x86_l_54c:
	/* 0x54c: cmp    edx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 42ULL);
x86_l_54f:
	/* 0x54f: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54f, 0x13e, x86_l_13e);
x86_l_555:
	/* 0x555: movzx  ecx,BYTE PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_559:
	/* 0x559: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x559, 0x12a, x86_l_12a);
x86_l_55e:
	/* 0x55e: movzx  esi,WORD PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_562:
	/* 0x562: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_564:
	/* 0x564: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_568:
	/* 0x568: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x568, 0x13e, x86_l_13e);
x86_l_56e:
	/* 0x56e: cmp    edx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 45ULL);
x86_l_571:
	/* 0x571: ja     585 <tail_policy_denied_ipv4+0x585> */
	X86_SIM_X86_JCC(X86_CC_A, 0x571, 0x585, x86_l_585);
x86_l_573:
	/* 0x573: cmp    edx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 44ULL);
x86_l_576:
	/* 0x576: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x576, 0x13e, x86_l_13e);
x86_l_57c:
	/* 0x57c: movzx  ecx,BYTE PTR [rcx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_580:
	/* 0x580: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x580, 0x12a, x86_l_12a);
x86_l_585:
	/* 0x585: movzx  esi,WORD PTR [rcx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_589:
	/* 0x589: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_58b:
	/* 0x58b: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_58f:
	/* 0x58f: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x58f, 0x13e, x86_l_13e);
x86_l_595:
	/* 0x595: cmp    edx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 47ULL);
x86_l_598:
	/* 0x598: ja     5ac <tail_policy_denied_ipv4+0x5ac> */
	X86_SIM_X86_JCC(X86_CC_A, 0x598, 0x5ac, x86_l_5ac);
x86_l_59a:
	/* 0x59a: cmp    edx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 46ULL);
x86_l_59d:
	/* 0x59d: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59d, 0x13e, x86_l_13e);
x86_l_5a3:
	/* 0x5a3: movzx  ecx,BYTE PTR [rcx+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 46ULL);
x86_l_5a7:
	/* 0x5a7: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x5a7, 0x12a, x86_l_12a);
x86_l_5ac:
	/* 0x5ac: movzx  esi,WORD PTR [rcx+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 46ULL);
x86_l_5b0:
	/* 0x5b0: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b2:
	/* 0x5b2: cmp    r12d,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 34ULL);
x86_l_5b6:
	/* 0x5b6: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5b6, 0x13e, x86_l_13e);
x86_l_5bc:
	/* 0x5bc: cmp    edx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 49ULL);
x86_l_5bf:
	/* 0x5bf: ja     5d3 <tail_policy_denied_ipv4+0x5d3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5bf, 0x5d3, x86_l_5d3);
x86_l_5c1:
	/* 0x5c1: cmp    edx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 48ULL);
x86_l_5c4:
	/* 0x5c4: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c4, 0x13e, x86_l_13e);
x86_l_5ca:
	/* 0x5ca: movzx  ecx,BYTE PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 48ULL);
x86_l_5ce:
	/* 0x5ce: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x5ce, 0x12a, x86_l_12a);
x86_l_5d3:
	/* 0x5d3: movzx  esi,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_5d7:
	/* 0x5d7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d9:
	/* 0x5d9: cmp    r12d,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 36ULL);
x86_l_5dd:
	/* 0x5dd: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5dd, 0x13e, x86_l_13e);
x86_l_5e3:
	/* 0x5e3: cmp    edx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 51ULL);
x86_l_5e6:
	/* 0x5e6: ja     5fa <tail_policy_denied_ipv4+0x5fa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5e6, 0x5fa, x86_l_5fa);
x86_l_5e8:
	/* 0x5e8: cmp    edx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 50ULL);
x86_l_5eb:
	/* 0x5eb: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5eb, 0x13e, x86_l_13e);
x86_l_5f1:
	/* 0x5f1: movzx  ecx,BYTE PTR [rcx+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 50ULL);
x86_l_5f5:
	/* 0x5f5: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x5f5, 0x12a, x86_l_12a);
x86_l_5fa:
	/* 0x5fa: movzx  esi,WORD PTR [rcx+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_5fe:
	/* 0x5fe: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_600:
	/* 0x600: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_604:
	/* 0x604: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x604, 0x13e, x86_l_13e);
x86_l_60a:
	/* 0x60a: cmp    edx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 53ULL);
x86_l_60d:
	/* 0x60d: ja     621 <tail_policy_denied_ipv4+0x621> */
	X86_SIM_X86_JCC(X86_CC_A, 0x60d, 0x621, x86_l_621);
x86_l_60f:
	/* 0x60f: cmp    edx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 52ULL);
x86_l_612:
	/* 0x612: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x612, 0x13e, x86_l_13e);
x86_l_618:
	/* 0x618: movzx  ecx,BYTE PTR [rcx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_61c:
	/* 0x61c: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x61c, 0x12a, x86_l_12a);
x86_l_621:
	/* 0x621: movzx  esi,WORD PTR [rcx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_625:
	/* 0x625: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_627:
	/* 0x627: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_62b:
	/* 0x62b: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x62b, 0x13e, x86_l_13e);
x86_l_631:
	/* 0x631: cmp    edx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 55ULL);
x86_l_634:
	/* 0x634: ja     648 <tail_policy_denied_ipv4+0x648> */
	X86_SIM_X86_JCC(X86_CC_A, 0x634, 0x648, x86_l_648);
x86_l_636:
	/* 0x636: cmp    edx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 54ULL);
x86_l_639:
	/* 0x639: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x639, 0x13e, x86_l_13e);
x86_l_63f:
	/* 0x63f: movzx  ecx,BYTE PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 54ULL);
x86_l_643:
	/* 0x643: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x643, 0x12a, x86_l_12a);
x86_l_648:
	/* 0x648: movzx  esi,WORD PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 54ULL);
x86_l_64c:
	/* 0x64c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_64e:
	/* 0x64e: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_652:
	/* 0x652: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x652, 0x13e, x86_l_13e);
x86_l_658:
	/* 0x658: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_65b:
	/* 0x65b: ja     66f <tail_policy_denied_ipv4+0x66f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x65b, 0x66f, x86_l_66f);
x86_l_65d:
	/* 0x65d: cmp    edx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 56ULL);
x86_l_660:
	/* 0x660: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x660, 0x13e, x86_l_13e);
x86_l_666:
	/* 0x666: movzx  ecx,BYTE PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_66a:
	/* 0x66a: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x66a, 0x12a, x86_l_12a);
x86_l_66f:
	/* 0x66f: movzx  esi,WORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_673:
	/* 0x673: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_675:
	/* 0x675: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_679:
	/* 0x679: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x679, 0x13e, x86_l_13e);
x86_l_67f:
	/* 0x67f: cmp    edx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 59ULL);
x86_l_682:
	/* 0x682: ja     696 <tail_policy_denied_ipv4+0x696> */
	X86_SIM_X86_JCC(X86_CC_A, 0x682, 0x696, x86_l_696);
x86_l_684:
	/* 0x684: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_687:
	/* 0x687: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x687, 0x13e, x86_l_13e);
x86_l_68d:
	/* 0x68d: movzx  ecx,BYTE PTR [rcx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_691:
	/* 0x691: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x691, 0x12a, x86_l_12a);
x86_l_696:
	/* 0x696: movzx  esi,WORD PTR [rcx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_69a:
	/* 0x69a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_69c:
	/* 0x69c: cmp    r12d,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 46ULL);
x86_l_6a0:
	/* 0x6a0: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6a0, 0x13e, x86_l_13e);
x86_l_6a6:
	/* 0x6a6: cmp    edx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 61ULL);
x86_l_6a9:
	/* 0x6a9: ja     6bd <tail_policy_denied_ipv4+0x6bd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6a9, 0x6bd, x86_l_6bd);
x86_l_6ab:
	/* 0x6ab: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_6ae:
	/* 0x6ae: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ae, 0x13e, x86_l_13e);
x86_l_6b4:
	/* 0x6b4: movzx  ecx,BYTE PTR [rcx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_6b8:
	/* 0x6b8: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x6b8, 0x12a, x86_l_12a);
x86_l_6bd:
	/* 0x6bd: movzx  esi,WORD PTR [rcx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_6c1:
	/* 0x6c1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6c3:
	/* 0x6c3: cmp    r12d,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 48ULL);
x86_l_6c7:
	/* 0x6c7: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6c7, 0x13e, x86_l_13e);
x86_l_6cd:
	/* 0x6cd: cmp    edx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_6d0:
	/* 0x6d0: ja     6e4 <tail_policy_denied_ipv4+0x6e4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6d0, 0x6e4, x86_l_6e4);
x86_l_6d2:
	/* 0x6d2: cmp    edx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 62ULL);
x86_l_6d5:
	/* 0x6d5: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d5, 0x13e, x86_l_13e);
x86_l_6db:
	/* 0x6db: movzx  ecx,BYTE PTR [rcx+0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 62ULL);
x86_l_6df:
	/* 0x6df: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x6df, 0x12a, x86_l_12a);
x86_l_6e4:
	/* 0x6e4: movzx  esi,WORD PTR [rcx+0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 62ULL);
x86_l_6e8:
	/* 0x6e8: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6ea:
	/* 0x6ea: cmp    r12d,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 50ULL);
x86_l_6ee:
	/* 0x6ee: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6ee, 0x13e, x86_l_13e);
x86_l_6f4:
	/* 0x6f4: cmp    edx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 65ULL);
x86_l_6f7:
	/* 0x6f7: ja     70b <tail_policy_denied_ipv4+0x70b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6f7, 0x70b, x86_l_70b);
x86_l_6f9:
	/* 0x6f9: cmp    edx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_6fc:
	/* 0x6fc: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fc, 0x13e, x86_l_13e);
x86_l_702:
	/* 0x702: movzx  ecx,BYTE PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_706:
	/* 0x706: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x706, 0x12a, x86_l_12a);
x86_l_70b:
	/* 0x70b: movzx  esi,WORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_70f:
	/* 0x70f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_711:
	/* 0x711: cmp    r12d,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 52ULL);
x86_l_715:
	/* 0x715: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x715, 0x13e, x86_l_13e);
x86_l_71b:
	/* 0x71b: cmp    edx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 67ULL);
x86_l_71e:
	/* 0x71e: ja     732 <tail_policy_denied_ipv4+0x732> */
	X86_SIM_X86_JCC(X86_CC_A, 0x71e, 0x732, x86_l_732);
x86_l_720:
	/* 0x720: cmp    edx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 66ULL);
x86_l_723:
	/* 0x723: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x723, 0x13e, x86_l_13e);
x86_l_729:
	/* 0x729: movzx  ecx,BYTE PTR [rcx+0x42] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 66ULL);
x86_l_72d:
	/* 0x72d: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x72d, 0x12a, x86_l_12a);
x86_l_732:
	/* 0x732: movzx  esi,WORD PTR [rcx+0x42] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 66ULL);
x86_l_736:
	/* 0x736: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_738:
	/* 0x738: cmp    r12d,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 54ULL);
x86_l_73c:
	/* 0x73c: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x73c, 0x13e, x86_l_13e);
x86_l_742:
	/* 0x742: cmp    edx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 69ULL);
x86_l_745:
	/* 0x745: ja     759 <tail_policy_denied_ipv4+0x759> */
	X86_SIM_X86_JCC(X86_CC_A, 0x745, 0x759, x86_l_759);
x86_l_747:
	/* 0x747: cmp    edx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 68ULL);
x86_l_74a:
	/* 0x74a: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74a, 0x13e, x86_l_13e);
x86_l_750:
	/* 0x750: movzx  ecx,BYTE PTR [rcx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 68ULL);
x86_l_754:
	/* 0x754: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x754, 0x12a, x86_l_12a);
x86_l_759:
	/* 0x759: movzx  esi,WORD PTR [rcx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 68ULL);
x86_l_75d:
	/* 0x75d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_75f:
	/* 0x75f: cmp    r12d,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 56ULL);
x86_l_763:
	/* 0x763: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x763, 0x13e, x86_l_13e);
x86_l_769:
	/* 0x769: cmp    edx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 71ULL);
x86_l_76c:
	/* 0x76c: ja     780 <tail_policy_denied_ipv4+0x780> */
	X86_SIM_X86_JCC(X86_CC_A, 0x76c, 0x780, x86_l_780);
x86_l_76e:
	/* 0x76e: cmp    edx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 70ULL);
x86_l_771:
	/* 0x771: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x771, 0x13e, x86_l_13e);
x86_l_777:
	/* 0x777: movzx  ecx,BYTE PTR [rcx+0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 70ULL);
x86_l_77b:
	/* 0x77b: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x77b, 0x12a, x86_l_12a);
x86_l_780:
	/* 0x780: movzx  esi,WORD PTR [rcx+0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 70ULL);
x86_l_784:
	/* 0x784: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_786:
	/* 0x786: cmp    r12d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 58ULL);
x86_l_78a:
	/* 0x78a: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x78a, 0x13e, x86_l_13e);
x86_l_790:
	/* 0x790: cmp    edx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 73ULL);
x86_l_793:
	/* 0x793: ja     7a7 <tail_policy_denied_ipv4+0x7a7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x793, 0x7a7, x86_l_7a7);
x86_l_795:
	/* 0x795: cmp    edx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 72ULL);
x86_l_798:
	/* 0x798: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x798, 0x13e, x86_l_13e);
x86_l_79e:
	/* 0x79e: movzx  ecx,BYTE PTR [rcx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_7a2:
	/* 0x7a2: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x7a2, 0x12a, x86_l_12a);
x86_l_7a7:
	/* 0x7a7: movzx  esi,WORD PTR [rcx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 72ULL);
x86_l_7ab:
	/* 0x7ab: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7ad:
	/* 0x7ad: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_7b1:
	/* 0x7b1: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7b1, 0x13e, x86_l_13e);
x86_l_7b7:
	/* 0x7b7: cmp    edx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 75ULL);
x86_l_7ba:
	/* 0x7ba: ja     7ce <tail_policy_denied_ipv4+0x7ce> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7ba, 0x7ce, x86_l_7ce);
x86_l_7bc:
	/* 0x7bc: cmp    edx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 74ULL);
x86_l_7bf:
	/* 0x7bf: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bf, 0x13e, x86_l_13e);
x86_l_7c5:
	/* 0x7c5: movzx  ecx,BYTE PTR [rcx+0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 74ULL);
x86_l_7c9:
	/* 0x7c9: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x7c9, 0x12a, x86_l_12a);
x86_l_7ce:
	/* 0x7ce: movzx  esi,WORD PTR [rcx+0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 74ULL);
x86_l_7d2:
	/* 0x7d2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7d4:
	/* 0x7d4: cmp    r12d,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 62ULL);
x86_l_7d8:
	/* 0x7d8: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7d8, 0x13e, x86_l_13e);
x86_l_7de:
	/* 0x7de: cmp    edx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 77ULL);
x86_l_7e1:
	/* 0x7e1: ja     7f5 <tail_policy_denied_ipv4+0x7f5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7e1, 0x7f5, x86_l_7f5);
x86_l_7e3:
	/* 0x7e3: cmp    edx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 76ULL);
x86_l_7e6:
	/* 0x7e6: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e6, 0x13e, x86_l_13e);
x86_l_7ec:
	/* 0x7ec: movzx  ecx,BYTE PTR [rcx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 76ULL);
x86_l_7f0:
	/* 0x7f0: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x7f0, 0x12a, x86_l_12a);
x86_l_7f5:
	/* 0x7f5: movzx  esi,WORD PTR [rcx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_7f9:
	/* 0x7f9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7fb:
	/* 0x7fb: cmp    r12d,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 64ULL);
x86_l_7ff:
	/* 0x7ff: jb     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7ff, 0x13e, x86_l_13e);
x86_l_805:
	/* 0x805: cmp    edx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 79ULL);
x86_l_808:
	/* 0x808: ja     81c <tail_policy_denied_ipv4+0x81c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x808, 0x81c, x86_l_81c);
x86_l_80a:
	/* 0x80a: cmp    edx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 78ULL);
x86_l_80d:
	/* 0x80d: je     13e <tail_policy_denied_ipv4+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80d, 0x13e, x86_l_13e);
x86_l_813:
	/* 0x813: movzx  ecx,BYTE PTR [rcx+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 78ULL);
x86_l_817:
	/* 0x817: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x817, 0x12a, x86_l_12a);
x86_l_81c:
	/* 0x81c: movzx  ecx,WORD PTR [rcx+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 78ULL);
x86_l_820:
	/* 0x820: jmp    12a <tail_policy_denied_ipv4+0x12a> */
	X86_SIM_X86_JMP(0x820, 0x12a, x86_l_12a);
x86_l_825:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
