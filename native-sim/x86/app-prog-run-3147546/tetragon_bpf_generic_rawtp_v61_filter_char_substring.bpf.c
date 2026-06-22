extern char substring_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_rawtp_v61_filter_char_substring_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_4:
	/* 0x4: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_c:
	/* 0xc: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e:
	/* 0xe: je     d6 <filter_char_substring+0xd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe, 0xd6, x86_l_d6);
x86_l_14:
	/* 0x14: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_16:
	/* 0x16: je     173 <filter_char_substring+0x173> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16, 0x173, x86_l_173);
x86_l_1c:
	/* 0x1c: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21:
	/* 0x21: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23:
	/* 0x23: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26:
	/* 0x26: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_2b:
	/* 0x2b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f:
	/* 0x2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34:
	/* 0x34: mov    rdi,QWORD PTR [rip+0x252a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_3b:
	/* 0x3b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: je     1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43, 0x1f7, x86_l_1f7);
x86_l_49:
	/* 0x49: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4c:
	/* 0x4c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e:
	/* 0x4e: jmp    5b <filter_char_substring+0x5b> */
	X86_SIM_X86_JMP(0x4e, 0x5b, x86_l_5b);
x86_l_50:
	/* 0x50: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_53:
	/* 0x53: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_56:
	/* 0x56: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     b1 <filter_char_substring+0xb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59, 0xb1, x86_l_b1);
x86_l_5b:
	/* 0x5b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d:
	/* 0x5d: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_61:
	/* 0x61: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_64:
	/* 0x64: jae    50 <filter_char_substring+0x50> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x64, 0x50, x86_l_50);
x86_l_66:
	/* 0x66: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_6a:
	/* 0x6a: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_6c:
	/* 0x6c: je     a9 <filter_char_substring+0xa9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c, 0xa9, x86_l_a9);
x86_l_6e:
	/* 0x6e: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_73:
	/* 0x73: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_77:
	/* 0x77: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_7a:
	/* 0x7a: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_7e:
	/* 0x7e: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_82:
	/* 0x82: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_86:
	/* 0x86: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_8a:
	/* 0x8a: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_8d:
	/* 0x8d: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_91:
	/* 0x91: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_95:
	/* 0x95: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_99:
	/* 0x99: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_9d:
	/* 0x9d: ja     50 <filter_char_substring+0x50> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9d, 0x50, x86_l_50);
x86_l_9f:
	/* 0x9f: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_a2:
	/* 0xa2: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_a5:
	/* 0xa5: je     5d <filter_char_substring+0x5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5, 0x5d, x86_l_5d);
x86_l_a7:
	/* 0xa7: jmp    50 <filter_char_substring+0x50> */
	X86_SIM_X86_JMP(0xa7, 0x50, x86_l_50);
x86_l_a9:
	/* 0xa9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_ab:
	/* 0xab: jns    205 <filter_char_substring+0x205> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xab, 0x205, x86_l_205);
x86_l_b1:
	/* 0xb1: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b6:
	/* 0xb6: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_ba:
	/* 0xba: jae    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xba, 0x1f7, x86_l_1f7);
x86_l_c0:
	/* 0xc0: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_c4:
	/* 0xc4: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_c7:
	/* 0xc7: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_cb:
	/* 0xcb: jne    26 <filter_char_substring+0x26> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcb, 0x26, x86_l_26);
x86_l_d1:
	/* 0xd1: jmp    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JMP(0xd1, 0x1f7, x86_l_1f7);
x86_l_d6:
	/* 0xd6: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_d8:
	/* 0xd8: je     1b6 <filter_char_substring+0x1b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd8, 0x1b6, x86_l_1b6);
x86_l_de:
	/* 0xde: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e3:
	/* 0xe3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5:
	/* 0xe5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8:
	/* 0xe8: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_ed:
	/* 0xed: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f1:
	/* 0xf1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f6:
	/* 0xf6: mov    rdi,QWORD PTR [rip+0x2538] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_fd:
	/* 0xfd: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_100:
	/* 0x100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102:
	/* 0x102: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105:
	/* 0x105: je     1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105, 0x1f7, x86_l_1f7);
x86_l_10b:
	/* 0x10b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10e:
	/* 0x10e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110:
	/* 0x110: jmp    11d <filter_char_substring+0x11d> */
	X86_SIM_X86_JMP(0x110, 0x11d, x86_l_11d);
x86_l_112:
	/* 0x112: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_115:
	/* 0x115: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_118:
	/* 0x118: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: je     14e <filter_char_substring+0x14e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b, 0x14e, x86_l_14e);
x86_l_11d:
	/* 0x11d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f:
	/* 0x11f: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_123:
	/* 0x123: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_126:
	/* 0x126: jae    112 <filter_char_substring+0x112> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x126, 0x112, x86_l_112);
x86_l_128:
	/* 0x128: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_12c:
	/* 0x12c: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_12f:
	/* 0x12f: je     146 <filter_char_substring+0x146> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f, 0x146, x86_l_146);
x86_l_131:
	/* 0x131: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_135:
	/* 0x135: ja     112 <filter_char_substring+0x112> */
	X86_SIM_X86_JCC(X86_CC_A, 0x135, 0x112, x86_l_112);
x86_l_137:
	/* 0x137: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_13b:
	/* 0x13b: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_13f:
	/* 0x13f: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_142:
	/* 0x142: je     11f <filter_char_substring+0x11f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142, 0x11f, x86_l_11f);
x86_l_144:
	/* 0x144: jmp    112 <filter_char_substring+0x112> */
	X86_SIM_X86_JMP(0x144, 0x112, x86_l_112);
x86_l_146:
	/* 0x146: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_148:
	/* 0x148: jns    205 <filter_char_substring+0x205> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x148, 0x205, x86_l_205);
x86_l_14e:
	/* 0x14e: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_153:
	/* 0x153: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_157:
	/* 0x157: jae    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x157, 0x1f7, x86_l_1f7);
x86_l_15d:
	/* 0x15d: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_161:
	/* 0x161: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_164:
	/* 0x164: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_168:
	/* 0x168: jne    e8 <filter_char_substring+0xe8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x168, 0xe8, x86_l_e8);
x86_l_16e:
	/* 0x16e: jmp    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JMP(0x16e, 0x1f7, x86_l_1f7);
x86_l_173:
	/* 0x173: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_178:
	/* 0x178: mov    r15,QWORD PTR [rip+0x254a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_17f:
	/* 0x17f: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_184:
	/* 0x184: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_188:
	/* 0x188: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18c:
	/* 0x18c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_191:
	/* 0x191: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_194:
	/* 0x194: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_197:
	/* 0x197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199:
	/* 0x199: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c:
	/* 0x19c: je     1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19c, 0x1f7, x86_l_1f7);
x86_l_19e:
	/* 0x19e: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a2:
	/* 0x1a2: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1a5:
	/* 0x1a5: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1a9:
	/* 0x1a9: jae    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1a9, 0x1f7, x86_l_1f7);
x86_l_1ab:
	/* 0x1ab: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1b2:
	/* 0x1b2: jne    184 <filter_char_substring+0x184> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2, 0x184, x86_l_184);
x86_l_1b4:
	/* 0x1b4: jmp    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JMP(0x1b4, 0x1f7, x86_l_1f7);
x86_l_1b6:
	/* 0x1b6: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_1bb:
	/* 0x1bb: mov    r15,QWORD PTR [rip+0x254c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1c2:
	/* 0x1c2: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c7:
	/* 0x1c7: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1cb:
	/* 0x1cb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cf:
	/* 0x1cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d4:
	/* 0x1d4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d7:
	/* 0x1d7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1da:
	/* 0x1da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc:
	/* 0x1dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df:
	/* 0x1df: je     1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1df, 0x1f7, x86_l_1f7);
x86_l_1e1:
	/* 0x1e1: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1e5:
	/* 0x1e5: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1e8:
	/* 0x1e8: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1ec:
	/* 0x1ec: jae    1f7 <filter_char_substring+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1ec, 0x1f7, x86_l_1f7);
x86_l_1ee:
	/* 0x1ee: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1f5:
	/* 0x1f5: jne    1c7 <filter_char_substring+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f5, 0x1c7, x86_l_1c7);
x86_l_1f7:
	/* 0x1f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9:
	/* 0x1f9: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fd:
	/* 0x1fd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_200:
	/* 0x200: jmp    20c <filter_char_substring+0x20c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_205:
	/* 0x205: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20a:
	/* 0x20a: jmp    1f9 <filter_char_substring+0x1f9> */
	X86_SIM_X86_JMP(0x20a, 0x1f9, x86_l_1f9);
x86_l_20c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
