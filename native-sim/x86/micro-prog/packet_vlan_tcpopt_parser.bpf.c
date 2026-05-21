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
	/* 0xc: ja     148 <packet_vlan_tcpopt_parser_xdp+0x148> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc, 0x148, x86_l_148);
x86_l_12:
	/* 0x12: lea    rcx,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16:
	/* 0x16: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_19:
	/* 0x19: ja     148 <packet_vlan_tcpopt_parser_xdp+0x148> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19, 0x148, x86_l_148);
x86_l_1f:
	/* 0x1f: lea    r9,[rdx+0x16] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_23:
	/* 0x23: cmp    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_26:
	/* 0x26: ja     148 <packet_vlan_tcpopt_parser_xdp+0x148> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26, 0x148, x86_l_148);
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
	/* 0x45: je     e3 <packet_vlan_tcpopt_parser_xdp+0xe3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45, 0xe3, x86_l_e3);
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
	/* 0x59: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59, 0x142, x86_l_142);
x86_l_5f:
	/* 0x5f: lea    r9,[rdx+0x1a] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_63:
	/* 0x63: cmp    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_66:
	/* 0x66: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0x66, 0x142, x86_l_142);
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
	/* 0x85: je     14d <packet_vlan_tcpopt_parser_xdp+0x14d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85, 0x14d, x86_l_14d);
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
	/* 0x99: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x99, 0x142, x86_l_142);
x86_l_9f:
	/* 0x9f: lea    rcx,[rdx+0x1e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_a3:
	/* 0xa3: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_a6:
	/* 0xa6: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa6, 0x142, x86_l_142);
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
	/* 0xbd: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbd, 0x142, x86_l_142);
x86_l_c3:
	/* 0xc3: lea    rcx,[rdx+0x32] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_c7:
	/* 0xc7: cmp    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_ca:
	/* 0xca: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0xca, 0x142, x86_l_142);
x86_l_cc:
	/* 0xcc: lea    r9,[rdx+0x1e] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_d0:
	/* 0xd0: movzx  ecx,WORD PTR [rdx+0x1a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_d4:
	/* 0xd4: rol    cx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_d8:
	/* 0xd8: movzx  r8d,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_dc:
	/* 0xdc: mov    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_e1:
	/* 0xe1: jmp    f3 <packet_vlan_tcpopt_parser_xdp+0xf3> */
	X86_SIM_X86_JMP(0xe1, 0xf3, x86_l_f3);
x86_l_e3:
	/* 0xe3: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e5:
	/* 0xe5: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e7:
	/* 0xe7: lea    rdi,[r9+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_eb:
	/* 0xeb: cmp    rdi,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_ee:
	/* 0xee: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0xee, 0x142, x86_l_142);
x86_l_f0:
	/* 0xf0: xor    r8d,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f3:
	/* 0xf3: movzx  edi,BYTE PTR [r9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f7:
	/* 0xf7: mov    r11d,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_fa:
	/* 0xfa: and    r11b,0xf0 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 240ULL);
x86_l_fe:
	/* 0xfe: cmp    r11b,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 64ULL);
x86_l_102:
	/* 0x102: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x102, 0x142, x86_l_142);
x86_l_104:
	/* 0x104: and    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_107:
	/* 0x107: cmp    dil,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, 0, 5ULL);
x86_l_10b:
	/* 0x10b: jb     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10b, 0x142, x86_l_142);
x86_l_10d:
	/* 0x10d: lea    rbx,[r9+rdi*4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_111:
	/* 0x111: cmp    rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RBX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_114:
	/* 0x114: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114, 0x142, x86_l_142);
x86_l_116:
	/* 0x116: cmp    BYTE PTR [r9+0x9],0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705670ULL);
x86_l_11b:
	/* 0x11b: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b, 0x142, x86_l_142);
x86_l_11d:
	/* 0x11d: lea    r14,[rbx+0x14] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_121:
	/* 0x121: cmp    r14,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_124:
	/* 0x124: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0x124, 0x142, x86_l_142);
x86_l_126:
	/* 0x126: movzx  r11d,BYTE PTR [rbx+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_12b:
	/* 0x12b: cmp    r11,0x50 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 80ULL);
x86_l_12f:
	/* 0x12f: jb     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_B, 0x12f, 0x142, x86_l_142);
x86_l_131:
	/* 0x131: shr    r11d,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 2ULL);
x86_l_135:
	/* 0x135: and    r11d,0xfffffffc */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_139:
	/* 0x139: lea    r15,[rbx+r11*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_13d:
	/* 0x13d: cmp    r15,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_140:
	/* 0x140: jbe    154 <packet_vlan_tcpopt_parser_xdp+0x154> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x140, 0x154, x86_l_154);
x86_l_142:
	/* 0x142: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_143:
	/* 0x143: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_145:
	/* 0x145: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_147:
	/* 0x147: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_148:
	/* 0x148: jmp    270 <packet_vlan_tcpopt_parser_xdp+0x270> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_14d:
	/* 0x14d: mov    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_152:
	/* 0x152: jmp    e7 <packet_vlan_tcpopt_parser_xdp+0xe7> */
	X86_SIM_X86_JMP(0x152, 0xe7, x86_l_e7);
x86_l_154:
	/* 0x154: lea    r15,[rbx+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_158:
	/* 0x158: cmp    r15,r10 */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_15b:
	/* 0x15b: ja     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_A, 0x15b, 0x142, x86_l_142);
x86_l_15d:
	/* 0x15d: cmp    r11b,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 32ULL);
x86_l_161:
	/* 0x161: jb     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_B, 0x161, 0x142, x86_l_142);
x86_l_163:
	/* 0x163: cmp    BYTE PTR [r14],0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_167:
	/* 0x167: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x167, 0x142, x86_l_142);
x86_l_169:
	/* 0x169: cmp    BYTE PTR [rbx+0x15],0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313220ULL);
x86_l_16d:
	/* 0x16d: jb     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_B, 0x16d, 0x142, x86_l_142);
x86_l_16f:
	/* 0x16f: cmp    BYTE PTR [rbx+0x18],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_173:
	/* 0x173: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x173, 0x142, x86_l_142);
x86_l_175:
	/* 0x175: cmp    BYTE PTR [rbx+0x19],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182403ULL);
x86_l_179:
	/* 0x179: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x179, 0x142, x86_l_142);
x86_l_17b:
	/* 0x17b: cmp    BYTE PTR [rbx+0x1a],0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149699ULL);
x86_l_17f:
	/* 0x17f: jb     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_B, 0x17f, 0x142, x86_l_142);
x86_l_181:
	/* 0x181: cmp    BYTE PTR [rbx+0x1c],0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120259084292ULL);
x86_l_185:
	/* 0x185: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x185, 0x142, x86_l_142);
x86_l_187:
	/* 0x187: cmp    BYTE PTR [rbx+0x1d],0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_18b:
	/* 0x18b: jb     142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_B, 0x18b, 0x142, x86_l_142);
x86_l_18d:
	/* 0x18d: cmp    BYTE PTR [rbx+0x1e],0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849018881ULL);
x86_l_191:
	/* 0x191: jne    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x191, 0x142, x86_l_142);
x86_l_193:
	/* 0x193: shl    rdi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 2ULL);
x86_l_197:
	/* 0x197: movzx  eax,WORD PTR [r9+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_19c:
	/* 0x19c: rol    ax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1a0:
	/* 0x1a0: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1a3:
	/* 0x1a3: mov    r10d,DWORD PTR [r9+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a7:
	/* 0x1a7: bswap  r10d */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_1aa:
	/* 0x1aa: mov    r9d,DWORD PTR [r9+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae:
	/* 0x1ae: bswap  r9d */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_1b1:
	/* 0x1b1: movzx  ebp,WORD PTR [rbx] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b4:
	/* 0x1b4: movzx  r14d,WORD PTR [rbx+0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1b9:
	/* 0x1b9: rol    bp,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1bd:
	/* 0x1bd: movzx  r15d,bp */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1c1:
	/* 0x1c1: add    r15,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1c4:
	/* 0x1c4: rol    r14w,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1c9:
	/* 0x1c9: movzx  eax,r14w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1cd:
	/* 0x1cd: add    rax,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1d0:
	/* 0x1d0: xor    rax,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1d3:
	/* 0x1d3: add    rax,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1d6:
	/* 0x1d6: movzx  r9d,BYTE PTR [rbx+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1db:
	/* 0x1db: mov    r10d,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_1de:
	/* 0x1de: shl    r10d,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1e2:
	/* 0x1e2: movzx  r14d,BYTE PTR [rbx+0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_1e7:
	/* 0x1e7: or     r10d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1ea:
	/* 0x1ea: add    r10,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1ee:
	/* 0x1ee: shl    r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1f2:
	/* 0x1f2: xor    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1f5:
	/* 0x1f5: shl    r14d,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1f9:
	/* 0x1f9: add    r9,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R14, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1fc:
	/* 0x1fc: add    r9,0x30100 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 196864ULL);
x86_l_203:
	/* 0x203: movzx  r10d,BYTE PTR [rbx+0x1b] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_208:
	/* 0x208: mov    r14,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_20b:
	/* 0x20b: shl    r14,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_20f:
	/* 0x20f: shl    r10d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_213:
	/* 0x213: xor    r10,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R14, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_216:
	/* 0x216: xor    r10,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_219:
	/* 0x219: movzx  ebx,BYTE PTR [rbx+0x1f] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_21d:
	/* 0x21d: shl    rbx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_221:
	/* 0x221: or     rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_224:
	/* 0x224: movabs r9,0x144000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 5435817984ULL);
x86_l_22e:
	/* 0x22e: add    r9,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_231:
	/* 0x231: shl    esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_234:
	/* 0x234: or     rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_237:
	/* 0x237: xor    rsi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_23a:
	/* 0x23a: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_23d:
	/* 0x23d: shl    rax,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_241:
	/* 0x241: shl    edi,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_244:
	/* 0x244: or     rdi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_247:
	/* 0x247: or     rdi,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_24a:
	/* 0x24a: movabs rax,0x600000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 25769803776ULL);
x86_l_254:
	/* 0x254: add    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_257:
	/* 0x257: add    ecx,0x5 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_25a:
	/* 0x25a: rol    r9,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_25d:
	/* 0x25d: add    rax,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_260:
	/* 0x260: xor    r9,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_263:
	/* 0x263: mov    QWORD PTR [rdx],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_266:
	/* 0x266: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_26b:
	/* 0x26b: jmp    142 <packet_vlan_tcpopt_parser_xdp+0x142> */
	X86_SIM_X86_JMP(0x26b, 0x142, x86_l_142);
x86_l_270:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
