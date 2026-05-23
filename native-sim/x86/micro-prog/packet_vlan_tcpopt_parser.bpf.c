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
	/* 0xc: ja     2bf <packet_vlan_tcpopt_parser_xdp+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc, 0x2bf, x86_l_2bf);
x86_l_12:
	/* 0x12: lea    rcx,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16:
	/* 0x16: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_19:
	/* 0x19: ja     2bf <packet_vlan_tcpopt_parser_xdp+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19, 0x2bf, x86_l_2bf);
x86_l_1f:
	/* 0x1f: lea    r9,[rdx+0x16] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_23:
	/* 0x23: cmp    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_26:
	/* 0x26: ja     2bf <packet_vlan_tcpopt_parser_xdp+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26, 0x2bf, x86_l_2bf);
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
	/* 0x32: movzx  eax,WORD PTR [rdx+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_36:
	/* 0x36: rol    ax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_3a:
	/* 0x3a: movzx  ecx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_3d:
	/* 0x3d: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3f:
	/* 0x3f: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_45:
	/* 0x45: je     e7 <packet_vlan_tcpopt_parser_xdp+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45, 0xe7, x86_l_e7);
x86_l_4b:
	/* 0x4b: cmp    ecx,0x88a8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34984ULL);
x86_l_51:
	/* 0x51: je     5f <packet_vlan_tcpopt_parser_xdp+0x5f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51, 0x5f, x86_l_5f);
x86_l_53:
	/* 0x53: cmp    ecx,0x8100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33024ULL);
x86_l_59:
	/* 0x59: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59, 0x2b9, x86_l_2b9);
x86_l_5f:
	/* 0x5f: lea    r9,[rdx+0x1a] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_63:
	/* 0x63: cmp    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_66:
	/* 0x66: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x66, 0x2b9, x86_l_2b9);
x86_l_6c:
	/* 0x6c: movzx  esi,WORD PTR [rdx+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 22ULL);
x86_l_70:
	/* 0x70: movzx  ecx,WORD PTR [rdx+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_74:
	/* 0x74: rol    si,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_78:
	/* 0x78: rol    cx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_7c:
	/* 0x7c: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_7f:
	/* 0x7f: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_85:
	/* 0x85: je     2a7 <packet_vlan_tcpopt_parser_xdp+0x2a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85, 0x2a7, x86_l_2a7);
x86_l_8b:
	/* 0x8b: cmp    ecx,0x88a8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 34984ULL);
x86_l_91:
	/* 0x91: je     9f <packet_vlan_tcpopt_parser_xdp+0x9f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91, 0x9f, x86_l_9f);
x86_l_93:
	/* 0x93: cmp    ecx,0x8100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33024ULL);
x86_l_99:
	/* 0x99: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x99, 0x2b9, x86_l_2b9);
x86_l_9f:
	/* 0x9f: lea    rcx,[rdx+0x1e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_a3:
	/* 0xa3: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_a6:
	/* 0xa6: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa6, 0x2b9, x86_l_2b9);
x86_l_ac:
	/* 0xac: movzx  ecx,WORD PTR [rdx+0x1c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_b0:
	/* 0xb0: rol    cx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_b4:
	/* 0xb4: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_b7:
	/* 0xb7: cmp    ecx,0x800 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2048ULL);
x86_l_bd:
	/* 0xbd: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbd, 0x2b9, x86_l_2b9);
x86_l_c3:
	/* 0xc3: lea    rcx,[rdx+0x32] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_c7:
	/* 0xc7: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_ca:
	/* 0xca: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xca, 0x2b9, x86_l_2b9);
x86_l_d0:
	/* 0xd0: lea    r9,[rdx+0x1e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_d4:
	/* 0xd4: movzx  ecx,WORD PTR [rdx+0x1a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_d8:
	/* 0xd8: rol    cx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_dc:
	/* 0xdc: movzx  r8d,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_e0:
	/* 0xe0: mov    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_e5:
	/* 0xe5: jmp    fb <packet_vlan_tcpopt_parser_xdp+0xfb> */
	X86_SIM_X86_JMP(0xe5, 0xfb, x86_l_fb);
x86_l_e7:
	/* 0xe7: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e9:
	/* 0xe9: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_eb:
	/* 0xeb: lea    rdi,[r9+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ef:
	/* 0xef: cmp    rdi,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_f2:
	/* 0xf2: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf2, 0x2b9, x86_l_2b9);
x86_l_f8:
	/* 0xf8: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_fb:
	/* 0xfb: movzx  edi,BYTE PTR [r9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ff:
	/* 0xff: mov    r11d,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_102:
	/* 0x102: and    r11b,0xf0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 240ULL);
x86_l_106:
	/* 0x106: cmp    r11b,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 64ULL);
x86_l_10a:
	/* 0x10a: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a, 0x2b9, x86_l_2b9);
x86_l_110:
	/* 0x110: and    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_113:
	/* 0x113: cmp    dil,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_117:
	/* 0x117: jb     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x117, 0x2b9, x86_l_2b9);
x86_l_11d:
	/* 0x11d: lea    rbx,[r9+rdi*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_121:
	/* 0x121: cmp    rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_124:
	/* 0x124: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x124, 0x2b9, x86_l_2b9);
x86_l_12a:
	/* 0x12a: cmp    BYTE PTR [r9+0x9],0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705670ULL);
x86_l_12f:
	/* 0x12f: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12f, 0x2b9, x86_l_2b9);
x86_l_135:
	/* 0x135: lea    r14,[rbx+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_139:
	/* 0x139: cmp    r14,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_13c:
	/* 0x13c: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13c, 0x2b9, x86_l_2b9);
x86_l_142:
	/* 0x142: movzx  r11d,BYTE PTR [rbx+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_147:
	/* 0x147: cmp    r11,0x50 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 80ULL);
x86_l_14b:
	/* 0x14b: jb     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x14b, 0x2b9, x86_l_2b9);
x86_l_151:
	/* 0x151: shr    r11d,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 2ULL);
x86_l_155:
	/* 0x155: and    r11d,0xfffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_159:
	/* 0x159: lea    r15,[rbx+r11*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_15d:
	/* 0x15d: cmp    r15,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_160:
	/* 0x160: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x160, 0x2b9, x86_l_2b9);
x86_l_166:
	/* 0x166: lea    r15,[rbx+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16a:
	/* 0x16a: cmp    r15,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_16d:
	/* 0x16d: ja     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x16d, 0x2b9, x86_l_2b9);
x86_l_173:
	/* 0x173: cmp    r11b,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_177:
	/* 0x177: jb     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x177, 0x2b9, x86_l_2b9);
x86_l_17d:
	/* 0x17d: cmp    BYTE PTR [r14],0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_181:
	/* 0x181: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x181, 0x2b9, x86_l_2b9);
x86_l_187:
	/* 0x187: cmp    BYTE PTR [rbx+0x15],0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313220ULL);
x86_l_18b:
	/* 0x18b: jb     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x18b, 0x2b9, x86_l_2b9);
x86_l_191:
	/* 0x191: cmp    BYTE PTR [rbx+0x18],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_195:
	/* 0x195: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x195, 0x2b9, x86_l_2b9);
x86_l_19b:
	/* 0x19b: cmp    BYTE PTR [rbx+0x19],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182403ULL);
x86_l_19f:
	/* 0x19f: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19f, 0x2b9, x86_l_2b9);
x86_l_1a5:
	/* 0x1a5: cmp    BYTE PTR [rbx+0x1a],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149699ULL);
x86_l_1a9:
	/* 0x1a9: jb     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a9, 0x2b9, x86_l_2b9);
x86_l_1af:
	/* 0x1af: cmp    BYTE PTR [rbx+0x1c],0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120259084292ULL);
x86_l_1b3:
	/* 0x1b3: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b3, 0x2b9, x86_l_2b9);
x86_l_1b9:
	/* 0x1b9: cmp    BYTE PTR [rbx+0x1d],0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_1bd:
	/* 0x1bd: jb     2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1bd, 0x2b9, x86_l_2b9);
x86_l_1c3:
	/* 0x1c3: cmp    BYTE PTR [rbx+0x1e],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849018881ULL);
x86_l_1c7:
	/* 0x1c7: jne    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c7, 0x2b9, x86_l_2b9);
x86_l_1cd:
	/* 0x1cd: shl    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 2ULL);
x86_l_1d1:
	/* 0x1d1: movzx  eax,WORD PTR [r9+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1d6:
	/* 0x1d6: rol    ax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1da:
	/* 0x1da: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1dd:
	/* 0x1dd: mov    r10d,DWORD PTR [r9+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e1:
	/* 0x1e1: bswap  r10d */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_1e4:
	/* 0x1e4: mov    r9d,DWORD PTR [r9+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e8:
	/* 0x1e8: bswap  r9d */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_1eb:
	/* 0x1eb: movzx  ebp,WORD PTR [rbx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ee:
	/* 0x1ee: movzx  r14d,WORD PTR [rbx+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1f3:
	/* 0x1f3: rol    bp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1f7:
	/* 0x1f7: movzx  r15d,bp */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1fb:
	/* 0x1fb: add    r15,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1fe:
	/* 0x1fe: rol    r14w,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_203:
	/* 0x203: movzx  eax,r14w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_207:
	/* 0x207: add    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_20a:
	/* 0x20a: xor    rax,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_20d:
	/* 0x20d: add    rax,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_210:
	/* 0x210: movzx  r9d,BYTE PTR [rbx+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_215:
	/* 0x215: mov    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_218:
	/* 0x218: shl    r10d,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_21c:
	/* 0x21c: movzx  r14d,BYTE PTR [rbx+0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_221:
	/* 0x221: or     r10d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_224:
	/* 0x224: add    r10,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_228:
	/* 0x228: shl    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_22c:
	/* 0x22c: xor    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_22f:
	/* 0x22f: shl    r14d,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_233:
	/* 0x233: add    r9,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_236:
	/* 0x236: add    r9,0x30100 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 196864ULL);
x86_l_23d:
	/* 0x23d: movzx  r10d,BYTE PTR [rbx+0x1b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_242:
	/* 0x242: mov    r14,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_245:
	/* 0x245: shl    r14,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_249:
	/* 0x249: shl    r10d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_24d:
	/* 0x24d: xor    r10,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_250:
	/* 0x250: xor    r10,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_253:
	/* 0x253: movzx  ebx,BYTE PTR [rbx+0x1f] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_257:
	/* 0x257: shl    rbx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_25b:
	/* 0x25b: or     rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_25e:
	/* 0x25e: movabs r9,0x144000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 5435817984ULL);
x86_l_268:
	/* 0x268: add    r9,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_26b:
	/* 0x26b: shl    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_26e:
	/* 0x26e: or     rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_271:
	/* 0x271: xor    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_274:
	/* 0x274: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_277:
	/* 0x277: shl    rax,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_27b:
	/* 0x27b: shl    edi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_27e:
	/* 0x27e: or     rdi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_281:
	/* 0x281: or     rdi,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_284:
	/* 0x284: movabs rax,0x600000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 25769803776ULL);
x86_l_28e:
	/* 0x28e: add    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_291:
	/* 0x291: add    ecx,0x5 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_294:
	/* 0x294: rol    r9,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_297:
	/* 0x297: add    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_29a:
	/* 0x29a: xor    r9,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_29d:
	/* 0x29d: mov    QWORD PTR [rdx],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a0:
	/* 0x2a0: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2a5:
	/* 0x2a5: jmp    2b9 <packet_vlan_tcpopt_parser_xdp+0x2b9> */
	X86_SIM_X86_JMP(0x2a5, 0x2b9, x86_l_2b9);
x86_l_2a7:
	/* 0x2a7: mov    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_2ac:
	/* 0x2ac: lea    rdi,[r9+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2b0:
	/* 0x2b0: cmp    rdi,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_2b3:
	/* 0x2b3: jbe    f8 <packet_vlan_tcpopt_parser_xdp+0xf8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x2b3, 0xf8, x86_l_f8);
x86_l_2b9:
	/* 0x2b9: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2ba:
	/* 0x2ba: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2bc:
	/* 0x2bc: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2be:
	/* 0x2be: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2bf:
	/* 0x2bf: jmp    2c4 <packet_vlan_tcpopt_parser_xdp+0x2c4> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2c4:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
