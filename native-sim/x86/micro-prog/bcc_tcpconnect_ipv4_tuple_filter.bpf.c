#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_tcpconnect_ipv4_tuple_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c:
	/* 0xc: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_f:
	/* 0xf: jbe    16 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    1d6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1d6> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rsi+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rsi+0x310] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rsi+0x8],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rsi+0xc],0x18 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_35:
	/* 0x35: jne    11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_38:
	/* 0x38: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3a:
	/* 0x3a: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3c:
	/* 0x3c: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3d:
	/* 0x3d: add    rsi,0x27 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_41:
	/* 0x41: movabs rdi,0xa0761d6478bd642f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 11562461410679940143ULL);
x86_l_4b:
	/* 0x4b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d:
	/* 0x4d: jmp    6d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x6d> */
	X86_SIM_X86_JMP(0x4d, 0x6d, x86_l_6d);
x86_l_4f:
	/* 0x4f: shl    r9,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_53:
	/* 0x53: mov    ecx,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R11, X86_WIDTH_32);
x86_l_56:
	/* 0x56: or     rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_59:
	/* 0x59: xor    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_5c:
	/* 0x5c: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_5f:
	/* 0x5f: add    rsi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_63:
	/* 0x63: cmp    rax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32ULL);
x86_l_67:
	/* 0x67: je     1c3 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67, 0x1c3, x86_l_1c3);
x86_l_6d:
	/* 0x6d: movzx  ecx,WORD PTR [rsi-0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_71:
	/* 0x71: cmp    ecx,0x1f8f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8079ULL);
x86_l_77:
	/* 0x77: jg     9d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x9d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x77, 0x9d, x86_l_9d);
x86_l_79:
	/* 0x79: cmp    ecx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 80ULL);
x86_l_7c:
	/* 0x7c: je     ef <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c, 0xef, x86_l_ef);
x86_l_7e:
	/* 0x7e: cmp    ecx,0x1bb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 443ULL);
x86_l_84:
	/* 0x84: jne    c4 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xc4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x84, 0xc4, x86_l_c4);
x86_l_86:
	/* 0x86: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8c:
	/* 0x8c: mov    r11d,DWORD PTR [rsi-0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_90:
	/* 0x90: movzx  r9d,BYTE PTR [rsi-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_95:
	/* 0x95: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_99:
	/* 0x99: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x99, 0x4f, x86_l_4f);
x86_l_9b:
	/* 0x9b: jmp    108 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x108> */
	X86_SIM_X86_JMP(0x9b, 0x108, x86_l_108);
x86_l_9d:
	/* 0x9d: cmp    ecx,0x1f90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8080ULL);
x86_l_a3:
	/* 0xa3: je     ad <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xad> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3, 0xad, x86_l_ad);
x86_l_a5:
	/* 0xa5: cmp    ecx,0x20fb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8443ULL);
x86_l_ab:
	/* 0xab: jne    c4 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xc4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xab, 0xc4, x86_l_c4);
x86_l_ad:
	/* 0xad: mov    r8d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 3ULL);
x86_l_b3:
	/* 0xb3: mov    r11d,DWORD PTR [rsi-0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_b7:
	/* 0xb7: movzx  r9d,BYTE PTR [rsi-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_bc:
	/* 0xbc: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_c0:
	/* 0xc0: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc0, 0x4f, x86_l_4f);
x86_l_c2:
	/* 0xc2: jmp    108 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x108> */
	X86_SIM_X86_JMP(0xc2, 0x108, x86_l_108);
x86_l_c4:
	/* 0xc4: movsx  r9d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R9, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c8:
	/* 0xc8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb:
	/* 0xcb: cmp    r9d,0x7530 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 30000ULL);
x86_l_d2:
	/* 0xd2: setge  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_GE);
x86_l_d6:
	/* 0xd6: shl    r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_da:
	/* 0xda: mov    r11d,DWORD PTR [rsi-0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_de:
	/* 0xde: movzx  r9d,BYTE PTR [rsi-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_e3:
	/* 0xe3: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_e7:
	/* 0xe7: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7, 0x4f, x86_l_4f);
x86_l_ed:
	/* 0xed: jmp    108 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x108> */
	X86_SIM_X86_JMP(0xed, 0x108, x86_l_108);
x86_l_ef:
	/* 0xef: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_f5:
	/* 0xf5: mov    r11d,DWORD PTR [rsi-0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_f9:
	/* 0xf9: movzx  r9d,BYTE PTR [rsi-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_fe:
	/* 0xfe: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_102:
	/* 0x102: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x102, 0x4f, x86_l_4f);
x86_l_108:
	/* 0x108: mov    r9d,DWORD PTR [rsi-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_10c:
	/* 0x10c: movzx  ebx,BYTE PTR [rsi-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_110:
	/* 0x110: test   bl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_113:
	/* 0x113: je     1b4 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x113, 0x1b4, x86_l_1b4);
x86_l_119:
	/* 0x119: test   r8d,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_32);
x86_l_11c:
	/* 0x11c: je     1b4 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c, 0x1b4, x86_l_1b4);
x86_l_122:
	/* 0x122: movzx  ebp,BYTE PTR [rsi-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_126:
	/* 0x126: movzx  r14d,BYTE PTR [rsi-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_12b:
	/* 0x12b: rorx   r15d,DWORD PTR [rsi-0xb],0x19 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 18446744026464911385ULL);
x86_l_132:
	/* 0x132: movzx  r10d,WORD PTR [rsi-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551615ULL);
x86_l_137:
	/* 0x137: xor    r15d,DWORD PTR [rsi-0xf] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551601ULL);
x86_l_13b:
	/* 0x13b: shl    r14d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_13f:
	/* 0x13f: shl    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_142:
	/* 0x142: or     ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_145:
	/* 0x145: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_148:
	/* 0x148: xor    ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a:
	/* 0x14a: xor    ecx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d:
	/* 0x14d: mov    ebp,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_32);
x86_l_14f:
	/* 0x14f: shl    ebp,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_152:
	/* 0x152: sar    ebp,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_155:
	/* 0x155: lea    r14d,[r9+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_159:
	/* 0x159: and    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_AND);
x86_l_15c:
	/* 0x15c: xor    r14d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f:
	/* 0x15f: xor    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_162:
	/* 0x162: lea    ecx,[r8+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_166:
	/* 0x166: mov    r15d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_32);
x86_l_169:
	/* 0x169: rol    r15d,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ROL);
x86_l_16c:
	/* 0x16c: test   bl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBX, X86_WIDTH_8, 4ULL);
x86_l_16f:
	/* 0x16f: cmove  r15d,r14d */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R14, X86_WIDTH_32, X86_CC_E);
x86_l_173:
	/* 0x173: shl    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_177:
	/* 0x177: mov    ecx,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R11, X86_WIDTH_32);
x86_l_17a:
	/* 0x17a: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_17d:
	/* 0x17d: mov    r11d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RAX, X86_WIDTH_32);
x86_l_180:
	/* 0x180: and    r11b,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_184:
	/* 0x184: lea    ebx,[r11+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_188:
	/* 0x188: shlx   rbx,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RBX, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SHL);
x86_l_18d:
	/* 0x18d: not    r11b */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_190:
	/* 0x190: shrx   rcx,rcx,r11 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_R11, X86_ALU_SHR);
x86_l_195:
	/* 0x195: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_198:
	/* 0x198: xor    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_19b:
	/* 0x19b: shl    r8,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_19f:
	/* 0x19f: shl    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1a3:
	/* 0x1a3: or     r10,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a6:
	/* 0x1a6: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_1a9:
	/* 0x1a9: xor    rdi,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_XOR);
x86_l_1ac:
	/* 0x1ac: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1af:
	/* 0x1af: jmp    5c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c> */
	X86_SIM_X86_JMP(0x1af, 0x5c, x86_l_5c);
x86_l_1b4:
	/* 0x1b4: shl    r9,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1b8:
	/* 0x1b8: or     r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1bb:
	/* 0x1bb: add    rdi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1be:
	/* 0x1be: jmp    5c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c> */
	X86_SIM_X86_JMP(0x1be, 0x5c, x86_l_5c);
x86_l_1c3:
	/* 0x1c3: mov    QWORD PTR [rdx],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c6:
	/* 0x1c6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cb:
	/* 0x1cb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1cc:
	/* 0x1cc: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1ce:
	/* 0x1ce: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1d0:
	/* 0x1d0: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1d1:
	/* 0x1d1: jmp    1d6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1d6> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1d6:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
