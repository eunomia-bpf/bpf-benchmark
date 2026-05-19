#include "../x86_sim_local_bpf.h"

SEC("tc")
int tc_packet_checksum_fold_x86_sim_xdp(struct __sk_buff *ctx)
{
	X86_SIM_ENTRY_SKB(ctx);
x86_l_0:
	/* 0x0: mov    rdx,QWORD PTR [rdi+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7:
	/* 0x7: mov    esi,DWORD PTR [rdi+0x70] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a:
	/* 0xa: add    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_d:
	/* 0xd: mov    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_10:
	/* 0x10: mov    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_13:
	/* 0x13: cmp    rax,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_16:
	/* 0x16: jbe    0x20 */
	X86_SIM_X86_JCC(X86_CC_BE, 0x16, 0x20, x86_l_20);
x86_l_18:
	/* 0x18: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1b:
	/* 0x1b: jmp    0x106 */
	X86_SIM_X86_JMP(0x1b, 0x106, x86_l_106);
x86_l_20:
	/* 0x20: lea    rcx,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24:
	/* 0x24: cmp    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_27:
	/* 0x27: ja     0x18 */
	X86_SIM_X86_JCC(X86_CC_A, 0x27, 0x18, x86_l_18);
x86_l_29:
	/* 0x29: lea    rdi,[rax+0x410] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_30:
	/* 0x30: cmp    rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_33:
	/* 0x33: ja     0x18 */
	X86_SIM_X86_JCC(X86_CC_A, 0x33, 0x18, x86_l_18);
x86_l_35:
	/* 0x35: mov    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_38:
	/* 0x38: mov    r9,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_3b:
	/* 0x3b: cmp    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_3e:
	/* 0x3e: ja     0x103 */
	X86_SIM_X86_JCC(X86_CC_A, 0x3e, 0x103, x86_l_103);
x86_l_44:
	/* 0x44: add    r8,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_48:
	/* 0x48: cmp    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_4b:
	/* 0x4b: ja     0x103 */
	X86_SIM_X86_JCC(X86_CC_A, 0x4b, 0x103, x86_l_103);
x86_l_51:
	/* 0x51: cmp    DWORD PTR [rax+0x8],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_55:
	/* 0x55: jne    0x103 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x55, 0x103, x86_l_103);
x86_l_5b:
	/* 0x5b: cmp    DWORD PTR [rax+0xc],0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_62:
	/* 0x62: jne    0x103 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x62, 0x103, x86_l_103);
x86_l_68:
	/* 0x68: lea    r8,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c:
	/* 0x6c: cmp    r8,rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_6f:
	/* 0x6f: ja     0x103 */
	X86_SIM_X86_JCC(X86_CC_A, 0x6f, 0x103, x86_l_103);
x86_l_75:
	/* 0x75: add    rcx,0x408 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1032ULL);
x86_l_7c:
	/* 0x7c: cmp    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_7f:
	/* 0x7f: ja     0x103 */
	X86_SIM_X86_JCC(X86_CC_A, 0x7f, 0x103, x86_l_103);
x86_l_85:
	/* 0x85: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_88:
	/* 0x88: xor    edi,edi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8a:
	/* 0x8a: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8c:
	/* 0x8c: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_8f:
	/* 0x8f: movzx  r10d,WORD PTR [rax+rcx*2+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 16ULL);
x86_l_95:
	/* 0x95: add    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_98:
	/* 0x98: movzx  r9d,r10w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_9c:
	/* 0x9c: shr    r10d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a0:
	/* 0xa0: add    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_a3:
	/* 0xa3: movzx  r9d,WORD PTR [rax+rcx*2+0x12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 18ULL);
x86_l_a9:
	/* 0xa9: add    r9d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_ac:
	/* 0xac: movzx  r10d,r9w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_b0:
	/* 0xb0: shr    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b4:
	/* 0xb4: add    r9d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_b7:
	/* 0xb7: add    rcx,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_bb:
	/* 0xbb: cmp    rcx,0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 512ULL);
x86_l_c2:
	/* 0xc2: jne    0x8f */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc2, 0x8f, x86_l_8f);
x86_l_c4:
	/* 0xc4: mov    ecx,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_c7:
	/* 0xc7: shr    ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ca:
	/* 0xca: add    ecx,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_cd:
	/* 0xcd: not    ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_cf:
	/* 0xcf: movzx  r9d,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_d3:
	/* 0xd3: mov    ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_d6:
	/* 0xd6: shl    ecx,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_d9:
	/* 0xd9: shl    r9,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_dc:
	/* 0xdc: xor    rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_df:
	/* 0xdf: inc    r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e2:
	/* 0xe2: cmp    r8d,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_e6:
	/* 0xe6: jne    0x8a */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe6, 0x8a, x86_l_8a);
x86_l_e8:
	/* 0xe8: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_eb:
	/* 0xeb: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_ed:
	/* 0xed: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_f0:
	/* 0xf0: ja     0x120 */
	X86_SIM_X86_JCC(X86_CC_A, 0xf0, 0x120, x86_l_120);
x86_l_f2:
	/* 0xf2: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f6:
	/* 0xf6: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_f9:
	/* 0xf9: ja     0x120 */
	X86_SIM_X86_JCC(X86_CC_A, 0xf9, 0x120, x86_l_120);
x86_l_fb:
	/* 0xfb: mov    QWORD PTR [rdx],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe:
	/* 0xfe: jmp    0x125 ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_103:
	/* 0x103: mov    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_106:
	/* 0x106: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_10b:
	/* 0x10b: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_10e:
	/* 0x10e: ja     0x120 */
	X86_SIM_X86_JCC(X86_CC_A, 0x10e, 0x120, x86_l_120);
x86_l_110:
	/* 0x110: add    rcx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_114:
	/* 0x114: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_117:
	/* 0x117: ja     0x120 */
	X86_SIM_X86_JCC(X86_CC_A, 0x117, 0x120, x86_l_120);
x86_l_119:
	/* 0x119: mov    QWORD PTR [rdx],0xffffffffffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_120:
	/* 0x120: jmp    0x125 ; native-link entry RET */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
