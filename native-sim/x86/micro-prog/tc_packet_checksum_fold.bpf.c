#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_bpf.h"

SEC("xdp")
int tc_packet_checksum_fold_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: mov    rbp,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_4:
	/* 0x4: mov    rdx,QWORD PTR [rdi+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b:
	/* 0xb: mov    esi,DWORD PTR [rdi+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e:
	/* 0xe: add    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_11:
	/* 0x11: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_14:
	/* 0x14: mov    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_17:
	/* 0x17: cmp    rax,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_1a:
	/* 0x1a: jbe    0x24 */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1a, 0x24, x86_l_24);
x86_l_1c:
	/* 0x1c: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1f:
	/* 0x1f: jmp    0x10b */
	X86_SIM_X86_JMP(0x1f, 0x10b, x86_l_10b);
x86_l_24:
	/* 0x24: lea    rcx,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28:
	/* 0x28: cmp    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_2b:
	/* 0x2b: ja     0x1c */
	X86_SIM_X86_JCC(X86_CC_A, 0x2b, 0x1c, x86_l_1c);
x86_l_2d:
	/* 0x2d: lea    rdi,[rax+0x410] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_34:
	/* 0x34: cmp    rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_37:
	/* 0x37: ja     0x1c */
	X86_SIM_X86_JCC(X86_CC_A, 0x37, 0x1c, x86_l_1c);
x86_l_39:
	/* 0x39: mov    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_3c:
	/* 0x3c: mov    r9,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_3f:
	/* 0x3f: cmp    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_42:
	/* 0x42: ja     0x108 */
	X86_SIM_X86_JCC(X86_CC_A, 0x42, 0x108, x86_l_108);
x86_l_48:
	/* 0x48: add    r8,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c:
	/* 0x4c: cmp    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_4f:
	/* 0x4f: ja     0x108 */
	X86_SIM_X86_JCC(X86_CC_A, 0x4f, 0x108, x86_l_108);
x86_l_55:
	/* 0x55: cmp    DWORD PTR [rax+0x8],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_59:
	/* 0x59: jne    0x108 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59, 0x108, x86_l_108);
x86_l_5f:
	/* 0x5f: cmp    DWORD PTR [rax+0xc],0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_66:
	/* 0x66: jne    0x108 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x66, 0x108, x86_l_108);
x86_l_6c:
	/* 0x6c: lea    r8,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70:
	/* 0x70: cmp    r8,rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_73:
	/* 0x73: ja     0x108 */
	X86_SIM_X86_JCC(X86_CC_A, 0x73, 0x108, x86_l_108);
x86_l_79:
	/* 0x79: add    rcx,0x408 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1032ULL);
x86_l_80:
	/* 0x80: cmp    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_83:
	/* 0x83: ja     0x108 */
	X86_SIM_X86_JCC(X86_CC_A, 0x83, 0x108, x86_l_108);
x86_l_89:
	/* 0x89: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8c:
	/* 0x8c: xor    edi,edi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8e:
	/* 0x8e: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_90:
	/* 0x90: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_93:
	/* 0x93: movzx  r10d,WORD PTR [rax+rcx*2+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 16ULL);
x86_l_99:
	/* 0x99: add    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_9c:
	/* 0x9c: movzx  r9d,r10w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_a0:
	/* 0xa0: shr    r10d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a4:
	/* 0xa4: add    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_a7:
	/* 0xa7: movzx  r9d,WORD PTR [rax+rcx*2+0x12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 18ULL);
x86_l_ad:
	/* 0xad: add    r9d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_b0:
	/* 0xb0: movzx  r10d,r9w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_b4:
	/* 0xb4: shr    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b8:
	/* 0xb8: add    r9d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_bb:
	/* 0xbb: add    rcx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_bf:
	/* 0xbf: cmp    rcx,0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 512ULL);
x86_l_c6:
	/* 0xc6: jne    0x93 */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc6, 0x93, x86_l_93);
x86_l_c8:
	/* 0xc8: mov    ecx,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_cb:
	/* 0xcb: shr    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ce:
	/* 0xce: add    ecx,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_d1:
	/* 0xd1: not    ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d3:
	/* 0xd3: movzx  r9d,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_d7:
	/* 0xd7: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_da:
	/* 0xda: shl    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_dd:
	/* 0xdd: shl    r9,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_e0:
	/* 0xe0: xor    rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_e3:
	/* 0xe3: inc    r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e6:
	/* 0xe6: cmp    r8d,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_ea:
	/* 0xea: jne    0x8e */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea, 0x8e, x86_l_8e);
x86_l_ec:
	/* 0xec: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_ef:
	/* 0xef: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f1:
	/* 0xf1: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_f4:
	/* 0xf4: ja     0x125 */
	X86_SIM_X86_JCC(X86_CC_A, 0xf4, 0x125, x86_l_125);
x86_l_f6:
	/* 0xf6: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_fa:
	/* 0xfa: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_fd:
	/* 0xfd: ja     0x125 */
	X86_SIM_X86_JCC(X86_CC_A, 0xfd, 0x125, x86_l_125);
x86_l_ff:
	/* 0xff: mov    QWORD PTR [rdx],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102:
	/* 0x102: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_103:
	/* 0x103: jmp    0x12b ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_108:
	/* 0x108: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_10b:
	/* 0x10b: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_110:
	/* 0x110: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_113:
	/* 0x113: ja     0x125 */
	X86_SIM_X86_JCC(X86_CC_A, 0x113, 0x125, x86_l_125);
x86_l_115:
	/* 0x115: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_119:
	/* 0x119: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_11c:
	/* 0x11c: ja     0x125 */
	X86_SIM_X86_JCC(X86_CC_A, 0x11c, 0x125, x86_l_125);
x86_l_11e:
	/* 0x11e: mov    QWORD PTR [rdx],0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_125:
	/* 0x125: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_126:
	/* 0x126: jmp    0x12b ; native-link entry RET */
	X86_SIM_X86_RET();
	__builtin_unreachable();
}

X86_SIM_LICENSE();
