#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int packet_toeplitz_rss_hash_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rsi,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    16 <packet_toeplitz_rss_hash_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    2d5 <packet_toeplitz_rss_hash_xdp+0x2d5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdx,[rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdx,[rdi+0x3e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_23:
	/* 0x23: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_26:
	/* 0x26: ja     11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26, 0x11, x86_l_11);
x86_l_28:
	/* 0x28: movzx  ecx,WORD PTR [rdi+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_2c:
	/* 0x2c: rol    cx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_30:
	/* 0x30: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_33:
	/* 0x33: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_39:
	/* 0x39: jne    11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x39, 0x11, x86_l_11);
x86_l_3b:
	/* 0x3b: movzx  ecx,BYTE PTR [rdi+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_3f:
	/* 0x3f: and    cl,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_42:
	/* 0x42: cmp    cl,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_45:
	/* 0x45: jne    11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45, 0x11, x86_l_11);
x86_l_47:
	/* 0x47: cmp    BYTE PTR [rdi+0x1f],0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986182ULL);
x86_l_4b:
	/* 0x4b: jne    11 <packet_toeplitz_rss_hash_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b, 0x11, x86_l_11);
x86_l_4d:
	/* 0x4d: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_4e:
	/* 0x4e: lea    r8,[rdi+0x1f] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_52:
	/* 0x52: mov    r9,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_55:
	/* 0x55: add    r9,0x22 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 34ULL);
x86_l_59:
	/* 0x59: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5b:
	/* 0x5b: xor    r10d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5e:
	/* 0x5e: jmp    80 <packet_toeplitz_rss_hash_xdp+0x80> */
	X86_SIM_X86_JMP(0x5e, 0x80, x86_l_80);
x86_l_60:
	/* 0x60: mov    ebx,0xc2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 194ULL);
x86_l_65:
	/* 0x65: mov    dl,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, 0, 8ULL);
x86_l_67:
	/* 0x67: sub    dl,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB, 0);
x86_l_69:
	/* 0x69: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_6b:
	/* 0x6b: shr    ebx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 0);
x86_l_6d:
	/* 0x6d: or     r11d,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_70:
	/* 0x70: xor    eax,r11d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_73:
	/* 0x73: inc    r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_76:
	/* 0x76: cmp    r10d,0x68 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 104ULL);
x86_l_7a:
	/* 0x7a: je     269 <packet_toeplitz_rss_hash_xdp+0x269> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a, 0x269, x86_l_269);
x86_l_80:
	/* 0x80: mov    edx,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_83:
	/* 0x83: shr    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_86:
	/* 0x86: cmp    r10d,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_8a:
	/* 0x8a: jbe    a1 <packet_toeplitz_rss_hash_xdp+0xa1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x8a, 0xa1, x86_l_a1);
x86_l_8c:
	/* 0x8c: cmp    r10d,0x3f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_90:
	/* 0x90: jbe    a1 <packet_toeplitz_rss_hash_xdp+0xa1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x90, 0xa1, x86_l_a1);
x86_l_92:
	/* 0x92: cmp    r10d,0x4f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_96:
	/* 0x96: jbe    a1 <packet_toeplitz_rss_hash_xdp+0xa1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x96, 0xa1, x86_l_a1);
x86_l_98:
	/* 0x98: mov    rcx,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_9b:
	/* 0x9b: cmp    r10d,0x5f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 95ULL);
x86_l_9f:
	/* 0x9f: ja     a6 <packet_toeplitz_rss_hash_xdp+0xa6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9f, 0xa6, x86_l_a6);
x86_l_a1:
	/* 0xa1: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_a3:
	/* 0xa3: add    rcx,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_a6:
	/* 0xa6: movzx  r11d,BYTE PTR [rcx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_aa:
	/* 0xaa: mov    ecx,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_ad:
	/* 0xad: and    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b0:
	/* 0xb0: shl    r11d,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_b3:
	/* 0xb3: test   r11b,r11b */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_8, 0, 0);
x86_l_b6:
	/* 0xb6: jns    73 <packet_toeplitz_rss_hash_xdp+0x73> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb6, 0x73, x86_l_73);
x86_l_b8:
	/* 0xb8: cmp    edx,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_bb:
	/* 0xbb: jle    e0 <packet_toeplitz_rss_hash_xdp+0xe0> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xbb, 0xe0, x86_l_e0);
x86_l_bd:
	/* 0xbd: cmp    edx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_c0:
	/* 0xc0: jle    102 <packet_toeplitz_rss_hash_xdp+0x102> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xc0, 0x102, x86_l_102);
x86_l_c2:
	/* 0xc2: cmp    edx,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_c5:
	/* 0xc5: jg     133 <packet_toeplitz_rss_hash_xdp+0x133> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc5, 0x133, x86_l_133);
x86_l_c7:
	/* 0xc7: cmp    edx,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_ca:
	/* 0xca: jne    179 <packet_toeplitz_rss_hash_xdp+0x179> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca, 0x179, x86_l_179);
x86_l_d0:
	/* 0xd0: mov    ebx,0x43 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 67ULL);
x86_l_d5:
	/* 0xd5: mov    r11d,0x67253d00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1730493696ULL);
x86_l_db:
	/* 0xdb: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0xdb, 0x1ab, x86_l_1ab);
x86_l_e0:
	/* 0xe0: cmp    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_e3:
	/* 0xe3: jg     11c <packet_toeplitz_rss_hash_xdp+0x11c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe3, 0x11c, x86_l_11c);
x86_l_e5:
	/* 0xe5: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_e7:
	/* 0xe7: je     152 <packet_toeplitz_rss_hash_xdp+0x152> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7, 0x152, x86_l_152);
x86_l_e9:
	/* 0xe9: cmp    edx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_ec:
	/* 0xec: jne    193 <packet_toeplitz_rss_hash_xdp+0x193> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xec, 0x193, x86_l_193);
x86_l_f2:
	/* 0xf2: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_f7:
	/* 0xf7: mov    r11d,0x5a56da00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1515641344ULL);
x86_l_fd:
	/* 0xfd: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0xfd, 0x1ab, x86_l_1ab);
x86_l_102:
	/* 0x102: cmp    edx,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_105:
	/* 0x105: je     145 <packet_toeplitz_rss_hash_xdp+0x145> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105, 0x145, x86_l_145);
x86_l_107:
	/* 0x107: cmp    edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_10a:
	/* 0x10a: jne    16c <packet_toeplitz_rss_hash_xdp+0x16c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a, 0x16c, x86_l_16c);
x86_l_10c:
	/* 0x10c: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_111:
	/* 0x111: mov    r11d,0xc2416700 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 3259066112ULL);
x86_l_117:
	/* 0x117: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x117, 0x1ab, x86_l_1ab);
x86_l_11c:
	/* 0x11c: cmp    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_11f:
	/* 0x11f: je     15f <packet_toeplitz_rss_hash_xdp+0x15f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f, 0x15f, x86_l_15f);
x86_l_121:
	/* 0x121: cmp    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_124:
	/* 0x124: jne    1a0 <packet_toeplitz_rss_hash_xdp+0x1a0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x124, 0x1a0, x86_l_1a0);
x86_l_126:
	/* 0x126: mov    ebx,0xc2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 194ULL);
x86_l_12b:
	/* 0x12b: mov    r11d,0x255b0e00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 626724352ULL);
x86_l_131:
	/* 0x131: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x131, 0x1ab, x86_l_1ab);
x86_l_133:
	/* 0x133: cmp    edx,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_136:
	/* 0x136: jne    186 <packet_toeplitz_rss_hash_xdp+0x186> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x136, 0x186, x86_l_186);
x86_l_138:
	/* 0x138: mov    ebx,0x8f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 143ULL);
x86_l_13d:
	/* 0x13d: mov    r11d,0x3d43a300 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1027842816ULL);
x86_l_143:
	/* 0x143: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x143, 0x1ab, x86_l_1ab);
x86_l_145:
	/* 0x145: mov    ebx,0x67 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 103ULL);
x86_l_14a:
	/* 0x14a: mov    r11d,0xec24100 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 247611648ULL);
x86_l_150:
	/* 0x150: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x150, 0x1ab, x86_l_1ab);
x86_l_152:
	/* 0x152: mov    ebx,0xda */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 218ULL);
x86_l_157:
	/* 0x157: mov    r11d,0x6d5a5600 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1834636800ULL);
x86_l_15d:
	/* 0x15d: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x15d, 0x1ab, x86_l_1ab);
x86_l_15f:
	/* 0x15f: mov    ebx,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_164:
	/* 0x164: mov    r11d,0xda255b00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 3659881216ULL);
x86_l_16a:
	/* 0x16a: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x16a, 0x1ab, x86_l_1ab);
x86_l_16c:
	/* 0x16c: mov    ebx,0x3d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_171:
	/* 0x171: mov    r11d,0x41672500 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1097278720ULL);
x86_l_177:
	/* 0x177: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x177, 0x1ab, x86_l_1ab);
x86_l_179:
	/* 0x179: mov    ebx,0xa3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 163ULL);
x86_l_17e:
	/* 0x17e: mov    r11d,0x253d4300 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 624771840ULL);
x86_l_184:
	/* 0x184: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x184, 0x1ab, x86_l_1ab);
x86_l_186:
	/* 0x186: mov    ebx,0xb0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 176ULL);
x86_l_18b:
	/* 0x18b: mov    r11d,0x43a38f00 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1134792448ULL);
x86_l_191:
	/* 0x191: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x191, 0x1ab, x86_l_1ab);
x86_l_193:
	/* 0x193: mov    ebx,0x5b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 91ULL);
x86_l_198:
	/* 0x198: mov    r11d,0x56da2500 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1457136896ULL);
x86_l_19e:
	/* 0x19e: jmp    1ab <packet_toeplitz_rss_hash_xdp+0x1ab> */
	X86_SIM_X86_JMP(0x19e, 0x1ab, x86_l_1ab);
x86_l_1a0:
	/* 0x1a0: mov    ebx,0x41 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 65ULL);
x86_l_1a5:
	/* 0x1a5: mov    r11d,0x5b0ec200 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, 0, 1527693824ULL);
x86_l_1ab:
	/* 0x1ab: or     r11d,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1ae:
	/* 0x1ae: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1b0:
	/* 0x1b0: je     70 <packet_toeplitz_rss_hash_xdp+0x70> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b0, 0x70, x86_l_70);
x86_l_1b6:
	/* 0x1b6: shl    r11d,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 0);
x86_l_1b9:
	/* 0x1b9: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_1be:
	/* 0x1be: cmp    edx,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_1c1:
	/* 0x1c1: jle    1dc <packet_toeplitz_rss_hash_xdp+0x1dc> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1c1, 0x1dc, x86_l_1dc);
x86_l_1c3:
	/* 0x1c3: cmp    edx,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_1c6:
	/* 0x1c6: jle    1f8 <packet_toeplitz_rss_hash_xdp+0x1f8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1c6, 0x1f8, x86_l_1f8);
x86_l_1c8:
	/* 0x1c8: cmp    edx,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_1cb:
	/* 0x1cb: jg     228 <packet_toeplitz_rss_hash_xdp+0x228> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1cb, 0x228, x86_l_228);
x86_l_1cd:
	/* 0x1cd: cmp    edx,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_1d0:
	/* 0x1d0: jne    241 <packet_toeplitz_rss_hash_xdp+0x241> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d0, 0x241, x86_l_241);
x86_l_1d2:
	/* 0x1d2: mov    ebx,0xa3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 163ULL);
x86_l_1d7:
	/* 0x1d7: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x1d7, 0x65, x86_l_65);
x86_l_1dc:
	/* 0x1dc: cmp    edx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1df:
	/* 0x1df: jg     210 <packet_toeplitz_rss_hash_xdp+0x210> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1df, 0x210, x86_l_210);
x86_l_1e1:
	/* 0x1e1: test   edx,edx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_1e3:
	/* 0x1e3: je     65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e3, 0x65, x86_l_65);
x86_l_1e9:
	/* 0x1e9: cmp    edx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_1ec:
	/* 0x1ec: jne    255 <packet_toeplitz_rss_hash_xdp+0x255> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ec, 0x255, x86_l_255);
x86_l_1ee:
	/* 0x1ee: mov    ebx,0x5b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 91ULL);
x86_l_1f3:
	/* 0x1f3: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x1f3, 0x65, x86_l_65);
x86_l_1f8:
	/* 0x1f8: cmp    edx,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_1fb:
	/* 0x1fb: je     65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fb, 0x65, x86_l_65);
x86_l_201:
	/* 0x201: cmp    edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_204:
	/* 0x204: jne    237 <packet_toeplitz_rss_hash_xdp+0x237> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x204, 0x237, x86_l_237);
x86_l_206:
	/* 0x206: mov    ebx,0x3d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_20b:
	/* 0x20b: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x20b, 0x65, x86_l_65);
x86_l_210:
	/* 0x210: cmp    edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_213:
	/* 0x213: je     60 <packet_toeplitz_rss_hash_xdp+0x60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x213, 0x60, x86_l_60);
x86_l_219:
	/* 0x219: cmp    edx,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_21c:
	/* 0x21c: jne    25f <packet_toeplitz_rss_hash_xdp+0x25f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21c, 0x25f, x86_l_25f);
x86_l_21e:
	/* 0x21e: mov    ebx,0x41 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 65ULL);
x86_l_223:
	/* 0x223: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x223, 0x65, x86_l_65);
x86_l_228:
	/* 0x228: cmp    edx,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_22b:
	/* 0x22b: jne    24b <packet_toeplitz_rss_hash_xdp+0x24b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22b, 0x24b, x86_l_24b);
x86_l_22d:
	/* 0x22d: mov    ebx,0xb0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 176ULL);
x86_l_232:
	/* 0x232: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x232, 0x65, x86_l_65);
x86_l_237:
	/* 0x237: mov    ebx,0x43 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 67ULL);
x86_l_23c:
	/* 0x23c: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x23c, 0x65, x86_l_65);
x86_l_241:
	/* 0x241: mov    ebx,0x8f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 143ULL);
x86_l_246:
	/* 0x246: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x246, 0x65, x86_l_65);
x86_l_24b:
	/* 0x24b: mov    ebx,0xd0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 208ULL);
x86_l_250:
	/* 0x250: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x250, 0x65, x86_l_65);
x86_l_255:
	/* 0x255: mov    ebx,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_25a:
	/* 0x25a: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x25a, 0x65, x86_l_65);
x86_l_25f:
	/* 0x25f: mov    ebx,0x67 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 103ULL);
x86_l_264:
	/* 0x264: jmp    65 <packet_toeplitz_rss_hash_xdp+0x65> */
	X86_SIM_X86_JMP(0x264, 0x65, x86_l_65);
x86_l_269:
	/* 0x269: mov    edx,DWORD PTR [rdi+0x26] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_26c:
	/* 0x26c: movzx  ecx,BYTE PTR [rdi+0x2a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_270:
	/* 0x270: movzx  r8d,BYTE PTR [rdi+0x2b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_275:
	/* 0x275: movzx  r9d,BYTE PTR [rdi+0x2c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_27a:
	/* 0x27a: movzx  r10d,BYTE PTR [rdi+0x2d] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_27f:
	/* 0x27f: mov    r11,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_282:
	/* 0x282: shl    r11,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_286:
	/* 0x286: xor    edx,DWORD PTR [rdi+0x22] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 34ULL);
x86_l_289:
	/* 0x289: bswap  edx */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_28b:
	/* 0x28b: mov    edi,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_28d:
	/* 0x28d: xor    edi,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_28f:
	/* 0x28f: or     rdi,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_292:
	/* 0x292: shl    rcx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_296:
	/* 0x296: shl    r8,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_29a:
	/* 0x29a: or     r8,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_29d:
	/* 0x29d: shl    r9,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_2a1:
	/* 0x2a1: or     r9,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_2a4:
	/* 0x2a4: shl    r10,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2a8:
	/* 0x2a8: or     rdx,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_2ab:
	/* 0x2ab: or     rdx,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_2ae:
	/* 0x2ae: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2b1:
	/* 0x2b1: lea    ecx,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2b4:
	/* 0x2b4: mov    r8,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_2b7:
	/* 0x2b7: shl    r8,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_2ba:
	/* 0x2ba: not    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_2bc:
	/* 0x2bc: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2be:
	/* 0x2be: shr    rdx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_2c1:
	/* 0x2c1: or     rdx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_2c4:
	/* 0x2c4: xor    rdx,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_2c7:
	/* 0x2c7: mov    QWORD PTR [rsi],rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca:
	/* 0x2ca: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2cf:
	/* 0x2cf: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2d0:
	/* 0x2d0: jmp    2d5 <packet_toeplitz_rss_hash_xdp+0x2d5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2d5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
