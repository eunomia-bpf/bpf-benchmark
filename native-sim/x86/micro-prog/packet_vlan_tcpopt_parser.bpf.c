#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int packet_vlan_tcpopt_parser_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    r10,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_9:
	/* 0x9: cmp    rdx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_c:
	/* 0xc: ja     2aa <packet_vlan_tcpopt_parser_xdp+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc, 0x2aa, x86_l_2aa);
x86_l_12:
	/* 0x12: lea    rcx,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16:
	/* 0x16: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_19:
	/* 0x19: ja     2aa <packet_vlan_tcpopt_parser_xdp+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19, 0x2aa, x86_l_2aa);
x86_l_1f:
	/* 0x1f: lea    r9,[rdx+0x16] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_23:
	/* 0x23: cmp    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_26:
	/* 0x26: ja     2aa <packet_vlan_tcpopt_parser_xdp+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26, 0x2aa, x86_l_2aa);
x86_l_2c:
	/* 0x2c: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_2d:
	/* 0x2d: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_2f:
	/* 0x2f: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_31:
	/* 0x31: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_32:
	/* 0x32: movbe  ax,WORD PTR [rdx+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_38:
	/* 0x38: movzx  ecx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_3b:
	/* 0x3b: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3d:
	/* 0x3d: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_43:
	/* 0x43: je     dd <packet_vlan_tcpopt_parser_xdp+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43, 0xdd, x86_l_dd);
x86_l_49:
	/* 0x49: cmp    ecx,0x88a8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34984ULL);
x86_l_4f:
	/* 0x4f: je     5d <packet_vlan_tcpopt_parser_xdp+0x5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f, 0x5d, x86_l_5d);
x86_l_51:
	/* 0x51: cmp    ecx,0x8100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33024ULL);
x86_l_57:
	/* 0x57: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57, 0x2a4, x86_l_2a4);
x86_l_5d:
	/* 0x5d: lea    r9,[rdx+0x1a] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_61:
	/* 0x61: cmp    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_64:
	/* 0x64: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x64, 0x2a4, x86_l_2a4);
x86_l_6a:
	/* 0x6a: movbe  si,WORD PTR [rdx+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RSI, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 22ULL);
x86_l_70:
	/* 0x70: movbe  cx,WORD PTR [rdx+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_76:
	/* 0x76: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_79:
	/* 0x79: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_7f:
	/* 0x7f: je     292 <packet_vlan_tcpopt_parser_xdp+0x292> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f, 0x292, x86_l_292);
x86_l_85:
	/* 0x85: cmp    ecx,0x88a8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34984ULL);
x86_l_8b:
	/* 0x8b: je     99 <packet_vlan_tcpopt_parser_xdp+0x99> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b, 0x99, x86_l_99);
x86_l_8d:
	/* 0x8d: cmp    ecx,0x8100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33024ULL);
x86_l_93:
	/* 0x93: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x93, 0x2a4, x86_l_2a4);
x86_l_99:
	/* 0x99: lea    rcx,[rdx+0x1e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_9d:
	/* 0x9d: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_a0:
	/* 0xa0: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa0, 0x2a4, x86_l_2a4);
x86_l_a6:
	/* 0xa6: movbe  cx,WORD PTR [rdx+0x1c] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_ac:
	/* 0xac: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_af:
	/* 0xaf: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_b5:
	/* 0xb5: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb5, 0x2a4, x86_l_2a4);
x86_l_bb:
	/* 0xbb: lea    rcx,[rdx+0x32] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_bf:
	/* 0xbf: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_c2:
	/* 0xc2: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc2, 0x2a4, x86_l_2a4);
x86_l_c8:
	/* 0xc8: lea    r9,[rdx+0x1e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_cc:
	/* 0xcc: movbe  cx,WORD PTR [rdx+0x1a] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_d2:
	/* 0xd2: movzx  r8d,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_d6:
	/* 0xd6: mov    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_db:
	/* 0xdb: jmp    f1 <packet_vlan_tcpopt_parser_xdp+0xf1> */
	X86_SIM_X86_JMP(0xdb, 0xf1, x86_l_f1);
x86_l_dd:
	/* 0xdd: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_df:
	/* 0xdf: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e1:
	/* 0xe1: lea    rdi,[r9+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e5:
	/* 0xe5: cmp    rdi,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_e8:
	/* 0xe8: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe8, 0x2a4, x86_l_2a4);
x86_l_ee:
	/* 0xee: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f1:
	/* 0xf1: movzx  edi,BYTE PTR [r9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f5:
	/* 0xf5: mov    r11d,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_f8:
	/* 0xf8: and    r11b,0xf0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 240ULL);
x86_l_fc:
	/* 0xfc: cmp    r11b,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 64ULL);
x86_l_100:
	/* 0x100: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x100, 0x2a4, x86_l_2a4);
x86_l_106:
	/* 0x106: and    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_109:
	/* 0x109: cmp    dil,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_10d:
	/* 0x10d: jb     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10d, 0x2a4, x86_l_2a4);
x86_l_113:
	/* 0x113: lea    rbx,[r9+rdi*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_117:
	/* 0x117: cmp    rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_11a:
	/* 0x11a: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11a, 0x2a4, x86_l_2a4);
x86_l_120:
	/* 0x120: cmp    BYTE PTR [r9+0x9],0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705670ULL);
x86_l_125:
	/* 0x125: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x125, 0x2a4, x86_l_2a4);
x86_l_12b:
	/* 0x12b: lea    r14,[rbx+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12f:
	/* 0x12f: cmp    r14,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_132:
	/* 0x132: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x132, 0x2a4, x86_l_2a4);
x86_l_138:
	/* 0x138: movzx  r11d,BYTE PTR [rbx+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_13d:
	/* 0x13d: cmp    r11,0x50 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 80ULL);
x86_l_141:
	/* 0x141: jb     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x141, 0x2a4, x86_l_2a4);
x86_l_147:
	/* 0x147: shr    r11d,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 2ULL);
x86_l_14b:
	/* 0x14b: and    r11d,0xfffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_14f:
	/* 0x14f: lea    r15,[rbx+r11*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_153:
	/* 0x153: cmp    r15,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_156:
	/* 0x156: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x156, 0x2a4, x86_l_2a4);
x86_l_15c:
	/* 0x15c: lea    r15,[rbx+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_160:
	/* 0x160: cmp    r15,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_163:
	/* 0x163: ja     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x163, 0x2a4, x86_l_2a4);
x86_l_169:
	/* 0x169: cmp    r11b,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_16d:
	/* 0x16d: jb     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x16d, 0x2a4, x86_l_2a4);
x86_l_173:
	/* 0x173: cmp    BYTE PTR [r14],0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_177:
	/* 0x177: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x177, 0x2a4, x86_l_2a4);
x86_l_17d:
	/* 0x17d: cmp    BYTE PTR [rbx+0x15],0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313220ULL);
x86_l_181:
	/* 0x181: jb     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x181, 0x2a4, x86_l_2a4);
x86_l_187:
	/* 0x187: cmp    BYTE PTR [rbx+0x18],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_18b:
	/* 0x18b: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18b, 0x2a4, x86_l_2a4);
x86_l_191:
	/* 0x191: cmp    BYTE PTR [rbx+0x19],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182403ULL);
x86_l_195:
	/* 0x195: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x195, 0x2a4, x86_l_2a4);
x86_l_19b:
	/* 0x19b: cmp    BYTE PTR [rbx+0x1a],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149699ULL);
x86_l_19f:
	/* 0x19f: jb     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19f, 0x2a4, x86_l_2a4);
x86_l_1a5:
	/* 0x1a5: cmp    BYTE PTR [rbx+0x1c],0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120259084292ULL);
x86_l_1a9:
	/* 0x1a9: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a9, 0x2a4, x86_l_2a4);
x86_l_1af:
	/* 0x1af: cmp    BYTE PTR [rbx+0x1d],0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_1b3:
	/* 0x1b3: jb     2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b3, 0x2a4, x86_l_2a4);
x86_l_1b9:
	/* 0x1b9: cmp    BYTE PTR [rbx+0x1e],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849018881ULL);
x86_l_1bd:
	/* 0x1bd: jne    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bd, 0x2a4, x86_l_2a4);
x86_l_1c3:
	/* 0x1c3: movbe  ax,WORD PTR [r9+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_R9, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1ca:
	/* 0x1ca: shl    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 2ULL);
x86_l_1ce:
	/* 0x1ce: movbe  r10d,DWORD PTR [r9+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 12ULL);
x86_l_1d4:
	/* 0x1d4: movbe  bp,WORD PTR [rbx] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RBP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d9:
	/* 0x1d9: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1dc:
	/* 0x1dc: movzx  r14d,bp */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1e0:
	/* 0x1e0: add    r14,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1e3:
	/* 0x1e3: movbe  ax,WORD PTR [rbx+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1e9:
	/* 0x1e9: movbe  r9d,DWORD PTR [r9+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1ef:
	/* 0x1ef: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1f2:
	/* 0x1f2: add    rax,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1f5:
	/* 0x1f5: xor    rax,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1f8:
	/* 0x1f8: add    rax,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1fb:
	/* 0x1fb: movzx  r9d,BYTE PTR [rbx+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_200:
	/* 0x200: mov    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_203:
	/* 0x203: shl    r10d,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_207:
	/* 0x207: movzx  r14d,BYTE PTR [rbx+0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_20c:
	/* 0x20c: or     r10d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_20f:
	/* 0x20f: add    r10,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_213:
	/* 0x213: shl    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_217:
	/* 0x217: xor    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_21a:
	/* 0x21a: shl    r14d,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_21e:
	/* 0x21e: add    r9,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_221:
	/* 0x221: add    r9,0x30100 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 196864ULL);
x86_l_228:
	/* 0x228: movzx  r10d,BYTE PTR [rbx+0x1b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_22d:
	/* 0x22d: mov    r14,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_230:
	/* 0x230: shl    r14,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_234:
	/* 0x234: shl    r10d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_238:
	/* 0x238: xor    r10,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_23b:
	/* 0x23b: xor    r10,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_23e:
	/* 0x23e: movzx  ebx,BYTE PTR [rbx+0x1f] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_242:
	/* 0x242: shl    rbx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_246:
	/* 0x246: or     rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_249:
	/* 0x249: movabs r9,0x144000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 5435817984ULL);
x86_l_253:
	/* 0x253: add    r9,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_256:
	/* 0x256: shl    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_259:
	/* 0x259: or     rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_25c:
	/* 0x25c: xor    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_25f:
	/* 0x25f: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_262:
	/* 0x262: shl    rax,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_266:
	/* 0x266: shl    edi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_269:
	/* 0x269: or     rdi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_26c:
	/* 0x26c: or     rdi,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_26f:
	/* 0x26f: movabs rax,0x600000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 25769803776ULL);
x86_l_279:
	/* 0x279: add    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_27c:
	/* 0x27c: add    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_27f:
	/* 0x27f: add    ecx,0x5 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_282:
	/* 0x282: rol    r9,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_285:
	/* 0x285: xor    r9,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_288:
	/* 0x288: mov    QWORD PTR [rdx],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b:
	/* 0x28b: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_290:
	/* 0x290: jmp    2a4 <packet_vlan_tcpopt_parser_xdp+0x2a4> */
	X86_SIM_X86_JMP(0x290, 0x2a4, x86_l_2a4);
x86_l_292:
	/* 0x292: mov    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_297:
	/* 0x297: lea    rdi,[r9+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29b:
	/* 0x29b: cmp    rdi,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_29e:
	/* 0x29e: jbe    ee <packet_vlan_tcpopt_parser_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x29e, 0xee, x86_l_ee);
x86_l_2a4:
	/* 0x2a4: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2a5:
	/* 0x2a5: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2a7:
	/* 0x2a7: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2a9:
	/* 0x2a9: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2aa:
	/* 0x2aa: jmp    2af <packet_vlan_tcpopt_parser_xdp+0x2af> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2af:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
