#include "../x86_sim_local_bpf.h"

SEC("tc")
int tc_packet_checksum_fold_x86_sim_xdp(struct __sk_buff *ctx)
{
	X86_SIM_ENTRY_SKB(ctx);
x86_l_0:
	/* 0x0: mov    rsi,QWORD PTR [rdi+0x50] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4:
	/* 0x4: mov    rax,QWORD PTR [rdi+0xd0] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b:
	/* 0xb: cmp    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_e:
	/* 0xe: jbe    29 <tc_packet_checksum_fold_prog+0x29> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe, 0x29, x86_l_29);
x86_l_10:
	/* 0x10: mov    DWORD PTR [rdi+0x30],0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_17:
	/* 0x17: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1c:
	/* 0x1c: mov    ecx,0xffffffff */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_21:
	/* 0x21: mov    DWORD PTR [rdi+0x34],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_24:
	/* 0x24: jmp    115 <tc_packet_checksum_fold_prog+0x115> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_29:
	/* 0x29: lea    rcx,[rax+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d:
	/* 0x2d: cmp    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_30:
	/* 0x30: ja     10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x30, 0x10, x86_l_10);
x86_l_32:
	/* 0x32: lea    rdx,[rax+0x410] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_39:
	/* 0x39: cmp    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3c:
	/* 0x3c: ja     10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c, 0x10, x86_l_10);
x86_l_3e:
	/* 0x3e: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_41:
	/* 0x41: mov    r8,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_44:
	/* 0x44: cmp    rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_47:
	/* 0x47: ja     10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x47, 0x10, x86_l_10);
x86_l_49:
	/* 0x49: add    rsi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d:
	/* 0x4d: cmp    rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_50:
	/* 0x50: ja     10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x50, 0x10, x86_l_10);
x86_l_52:
	/* 0x52: cmp    DWORD PTR [rax+0x8],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_56:
	/* 0x56: jne    10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56, 0x10, x86_l_10);
x86_l_58:
	/* 0x58: cmp    DWORD PTR [rax+0xc],0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_5f:
	/* 0x5f: jne    10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f, 0x10, x86_l_10);
x86_l_61:
	/* 0x61: lea    rsi,[rcx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65:
	/* 0x65: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_68:
	/* 0x68: ja     10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x68, 0x10, x86_l_10);
x86_l_6a:
	/* 0x6a: add    rcx,0x408 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 1032ULL);
x86_l_71:
	/* 0x71: cmp    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_74:
	/* 0x74: ja     10 <tc_packet_checksum_fold_prog+0x10> */
	X86_SIM_X86_JCC(X86_CC_A, 0x74, 0x10, x86_l_10);
x86_l_76:
	/* 0x76: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_78:
	/* 0x78: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7a:
	/* 0x7a: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7c:
	/* 0x7c: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_7f:
	/* 0x7f: movzx  r9d,WORD PTR [rax+rsi*2+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 1, X86_WIDTH_16), 16ULL);
x86_l_85:
	/* 0x85: add    r9d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_88:
	/* 0x88: movzx  r8d,r9w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_8c:
	/* 0x8c: shr    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_90:
	/* 0x90: add    r9d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_93:
	/* 0x93: movzx  r8d,WORD PTR [rax+rsi*2+0x12] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 1, X86_WIDTH_16), 18ULL);
x86_l_99:
	/* 0x99: add    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_9c:
	/* 0x9c: movzx  r9d,r8w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_a0:
	/* 0xa0: shr    r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a4:
	/* 0xa4: add    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_a7:
	/* 0xa7: movzx  r9d,WORD PTR [rax+rsi*2+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 1, X86_WIDTH_16), 20ULL);
x86_l_ad:
	/* 0xad: add    r9d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_b0:
	/* 0xb0: movzx  r8d,r9w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_b4:
	/* 0xb4: shr    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b8:
	/* 0xb8: add    r9d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_bb:
	/* 0xbb: movzx  r8d,WORD PTR [rax+rsi*2+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 1, X86_WIDTH_16), 22ULL);
x86_l_c1:
	/* 0xc1: add    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_c4:
	/* 0xc4: movzx  r9d,r8w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_c8:
	/* 0xc8: shr    r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_cc:
	/* 0xcc: add    r8d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_cf:
	/* 0xcf: add    rsi,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d3:
	/* 0xd3: cmp    rsi,0x200 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 512ULL);
x86_l_da:
	/* 0xda: jne    7f <tc_packet_checksum_fold_prog+0x7f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xda, 0x7f, x86_l_7f);
x86_l_dc:
	/* 0xdc: mov    esi,r8d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_df:
	/* 0xdf: shr    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e2:
	/* 0xe2: add    esi,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_e5:
	/* 0xe5: not    esi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_e7:
	/* 0xe7: movzx  esi,si */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_ea:
	/* 0xea: mov    r8d,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_ed:
	/* 0xed: shl    r8d,0x4 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_f1:
	/* 0xf1: shlx   rsi,rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_R8, X86_ALU_SHL);
x86_l_f6:
	/* 0xf6: xor    rcx,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_f9:
	/* 0xf9: inc    edx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fb:
	/* 0xfb: cmp    edx,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_fe:
	/* 0xfe: jne    7a <tc_packet_checksum_fold_prog+0x7a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfe, 0x7a, x86_l_7a);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rdi+0x30],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_107:
	/* 0x107: shr    rcx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_10b:
	/* 0x10b: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_10d:
	/* 0x10d: mov    DWORD PTR [rdi+0x34],ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_110:
	/* 0x110: jmp    115 <tc_packet_checksum_fold_prog+0x115> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_115:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
