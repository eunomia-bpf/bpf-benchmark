extern char substring_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_v61_filter_char_substring_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_b:
	/* 0xb: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_e:
	/* 0xe: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_13:
	/* 0x13: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_15:
	/* 0x15: je     dd <filter_char_substring+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15, 0xdd, x86_l_dd);
x86_l_1b:
	/* 0x1b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1d:
	/* 0x1d: je     17a <filter_char_substring+0x17a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d, 0x17a, x86_l_17a);
x86_l_23:
	/* 0x23: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28:
	/* 0x28: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a:
	/* 0x2a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d:
	/* 0x2d: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_32:
	/* 0x32: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36:
	/* 0x36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b:
	/* 0x3b: mov    rdi,QWORD PTR [rip+0x2243] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_42:
	/* 0x42: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_45:
	/* 0x45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47:
	/* 0x47: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: je     1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a, 0x1fe, x86_l_1fe);
x86_l_50:
	/* 0x50: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_53:
	/* 0x53: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55:
	/* 0x55: jmp    62 <filter_char_substring+0x62> */
	X86_SIM_X86_JMP(0x55, 0x62, x86_l_62);
x86_l_57:
	/* 0x57: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_5a:
	/* 0x5a: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_5d:
	/* 0x5d: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_60:
	/* 0x60: je     b8 <filter_char_substring+0xb8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60, 0xb8, x86_l_b8);
x86_l_62:
	/* 0x62: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64:
	/* 0x64: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_68:
	/* 0x68: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: jae    57 <filter_char_substring+0x57> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x6b, 0x57, x86_l_57);
x86_l_6d:
	/* 0x6d: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_71:
	/* 0x71: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_73:
	/* 0x73: je     b0 <filter_char_substring+0xb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73, 0xb0, x86_l_b0);
x86_l_75:
	/* 0x75: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_7a:
	/* 0x7a: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_7e:
	/* 0x7e: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_81:
	/* 0x81: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_85:
	/* 0x85: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_89:
	/* 0x89: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_8d:
	/* 0x8d: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_91:
	/* 0x91: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_94:
	/* 0x94: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_98:
	/* 0x98: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_9c:
	/* 0x9c: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_a0:
	/* 0xa0: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_a4:
	/* 0xa4: ja     57 <filter_char_substring+0x57> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa4, 0x57, x86_l_57);
x86_l_a6:
	/* 0xa6: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_a9:
	/* 0xa9: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_ac:
	/* 0xac: je     64 <filter_char_substring+0x64> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac, 0x64, x86_l_64);
x86_l_ae:
	/* 0xae: jmp    57 <filter_char_substring+0x57> */
	X86_SIM_X86_JMP(0xae, 0x57, x86_l_57);
x86_l_b0:
	/* 0xb0: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: jns    213 <filter_char_substring+0x213> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb2, 0x213, x86_l_213);
x86_l_b8:
	/* 0xb8: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bd:
	/* 0xbd: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_c1:
	/* 0xc1: jae    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xc1, 0x1fe, x86_l_1fe);
x86_l_c7:
	/* 0xc7: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_cb:
	/* 0xcb: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ce:
	/* 0xce: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_d2:
	/* 0xd2: jne    2d <filter_char_substring+0x2d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd2, 0x2d, x86_l_2d);
x86_l_d8:
	/* 0xd8: jmp    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JMP(0xd8, 0x1fe, x86_l_1fe);
x86_l_dd:
	/* 0xdd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_df:
	/* 0xdf: je     1bd <filter_char_substring+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf, 0x1bd, x86_l_1bd);
x86_l_e5:
	/* 0xe5: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ea:
	/* 0xea: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec:
	/* 0xec: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef:
	/* 0xef: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_f4:
	/* 0xf4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f8:
	/* 0xf8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd:
	/* 0xfd: mov    rdi,QWORD PTR [rip+0x2251] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_104:
	/* 0x104: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_107:
	/* 0x107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109:
	/* 0x109: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: je     1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10c, 0x1fe, x86_l_1fe);
x86_l_112:
	/* 0x112: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_115:
	/* 0x115: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_117:
	/* 0x117: jmp    124 <filter_char_substring+0x124> */
	X86_SIM_X86_JMP(0x117, 0x124, x86_l_124);
x86_l_119:
	/* 0x119: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11c:
	/* 0x11c: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11f:
	/* 0x11f: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_122:
	/* 0x122: je     155 <filter_char_substring+0x155> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122, 0x155, x86_l_155);
x86_l_124:
	/* 0x124: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_126:
	/* 0x126: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_12a:
	/* 0x12a: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_12d:
	/* 0x12d: jae    119 <filter_char_substring+0x119> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x12d, 0x119, x86_l_119);
x86_l_12f:
	/* 0x12f: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_133:
	/* 0x133: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_136:
	/* 0x136: je     14d <filter_char_substring+0x14d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136, 0x14d, x86_l_14d);
x86_l_138:
	/* 0x138: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_13c:
	/* 0x13c: ja     119 <filter_char_substring+0x119> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13c, 0x119, x86_l_119);
x86_l_13e:
	/* 0x13e: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_142:
	/* 0x142: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_146:
	/* 0x146: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_149:
	/* 0x149: je     126 <filter_char_substring+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x149, 0x126, x86_l_126);
x86_l_14b:
	/* 0x14b: jmp    119 <filter_char_substring+0x119> */
	X86_SIM_X86_JMP(0x14b, 0x119, x86_l_119);
x86_l_14d:
	/* 0x14d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14f:
	/* 0x14f: jns    213 <filter_char_substring+0x213> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x14f, 0x213, x86_l_213);
x86_l_155:
	/* 0x155: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15a:
	/* 0x15a: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_15e:
	/* 0x15e: jae    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x15e, 0x1fe, x86_l_1fe);
x86_l_164:
	/* 0x164: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_168:
	/* 0x168: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_16b:
	/* 0x16b: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_16f:
	/* 0x16f: jne    ef <filter_char_substring+0xef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16f, 0xef, x86_l_ef);
x86_l_175:
	/* 0x175: jmp    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JMP(0x175, 0x1fe, x86_l_1fe);
x86_l_17a:
	/* 0x17a: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_17f:
	/* 0x17f: mov    r15,QWORD PTR [rip+0x2263] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_186:
	/* 0x186: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18b:
	/* 0x18b: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_18f:
	/* 0x18f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_193:
	/* 0x193: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_198:
	/* 0x198: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19b:
	/* 0x19b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_19e:
	/* 0x19e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0:
	/* 0x1a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3:
	/* 0x1a3: je     1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3, 0x1fe, x86_l_1fe);
x86_l_1a5:
	/* 0x1a5: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a9:
	/* 0x1a9: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1ac:
	/* 0x1ac: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1b0:
	/* 0x1b0: jae    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1b0, 0x1fe, x86_l_1fe);
x86_l_1b2:
	/* 0x1b2: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1b9:
	/* 0x1b9: jne    18b <filter_char_substring+0x18b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b9, 0x18b, x86_l_18b);
x86_l_1bb:
	/* 0x1bb: jmp    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JMP(0x1bb, 0x1fe, x86_l_1fe);
x86_l_1bd:
	/* 0x1bd: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_1c2:
	/* 0x1c2: mov    r15,QWORD PTR [rip+0x2265] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1c9:
	/* 0x1c9: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ce:
	/* 0x1ce: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1d2:
	/* 0x1d2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db:
	/* 0x1db: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1de:
	/* 0x1de: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1e1:
	/* 0x1e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3:
	/* 0x1e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e6:
	/* 0x1e6: je     1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e6, 0x1fe, x86_l_1fe);
x86_l_1e8:
	/* 0x1e8: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ec:
	/* 0x1ec: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1ef:
	/* 0x1ef: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1f3:
	/* 0x1f3: jae    1fe <filter_char_substring+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1f3, 0x1fe, x86_l_1fe);
x86_l_1f5:
	/* 0x1f5: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1fc:
	/* 0x1fc: jne    1ce <filter_char_substring+0x1ce> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fc, 0x1ce, x86_l_1ce);
x86_l_1fe:
	/* 0x1fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_200:
	/* 0x200: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_204:
	/* 0x204: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_205:
	/* 0x205: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_207:
	/* 0x207: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_209:
	/* 0x209: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_20b:
	/* 0x20b: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_20d:
	/* 0x20d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_20e:
	/* 0x20e: jmp    21a <filter_char_substring+0x21a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_213:
	/* 0x213: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_218:
	/* 0x218: jmp    200 <filter_char_substring+0x200> */
	X86_SIM_X86_JMP(0x218, 0x200, x86_l_200);
x86_l_21a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
