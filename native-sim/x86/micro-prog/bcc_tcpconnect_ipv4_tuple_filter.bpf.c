#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_tcpconnect_ipv4_tuple_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    16 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    1bf <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1bf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rsi+0x310] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rsi+0x8],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rsi+0xc],0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_35:
	/* 0x35: jne    11 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_38:
	/* 0x38: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_3a:
	/* 0x3a: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_3c:
	/* 0x3c: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3d:
	/* 0x3d: add    rsi,0x27 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_41:
	/* 0x41: movabs r8,0xa0761d6478bd642f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 11562461410679940143ULL);
x86_l_4b:
	/* 0x4b: xor    edi,edi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4d:
	/* 0x4d: jmp    6c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x6c> */
	X86_SIM_X86_JMP(0x4d, 0x6c, x86_l_6c);
x86_l_4f:
	/* 0x4f: shl    rcx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_53:
	/* 0x53: mov    eax,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_55:
	/* 0x55: or     rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_58:
	/* 0x58: xor    r8,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_5b:
	/* 0x5b: inc    rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_5e:
	/* 0x5e: add    rsi,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_62:
	/* 0x62: cmp    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_66:
	/* 0x66: je     1ac <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66, 0x1ac, x86_l_1ac);
x86_l_6c:
	/* 0x6c: movzx  eax,WORD PTR [rsi-0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_70:
	/* 0x70: cmp    eax,0x1f8f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8079ULL);
x86_l_75:
	/* 0x75: jg     97 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x97> */
	X86_SIM_X86_JCC(X86_CC_G, 0x75, 0x97, x86_l_97);
x86_l_77:
	/* 0x77: cmp    eax,0x50 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_7a:
	/* 0x7a: je     df <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a, 0xdf, x86_l_df);
x86_l_7c:
	/* 0x7c: cmp    eax,0x1bb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 443ULL);
x86_l_81:
	/* 0x81: jne    b9 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xb9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x81, 0xb9, x86_l_b9);
x86_l_83:
	/* 0x83: mov    r9d,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_89:
	/* 0x89: mov    ebx,DWORD PTR [rsi-0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_8c:
	/* 0x8c: movzx  ecx,BYTE PTR [rsi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_90:
	/* 0x90: cmp    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_93:
	/* 0x93: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x93, 0x4f, x86_l_4f);
x86_l_95:
	/* 0x95: jmp    f5 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf5> */
	X86_SIM_X86_JMP(0x95, 0xf5, x86_l_f5);
x86_l_97:
	/* 0x97: cmp    eax,0x1f90 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8080ULL);
x86_l_9c:
	/* 0x9c: je     a5 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c, 0xa5, x86_l_a5);
x86_l_9e:
	/* 0x9e: cmp    eax,0x20fb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 8443ULL);
x86_l_a3:
	/* 0xa3: jne    b9 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xb9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3, 0xb9, x86_l_b9);
x86_l_a5:
	/* 0xa5: mov    r9d,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_ab:
	/* 0xab: mov    ebx,DWORD PTR [rsi-0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_ae:
	/* 0xae: movzx  ecx,BYTE PTR [rsi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_b2:
	/* 0xb2: cmp    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_b5:
	/* 0xb5: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb5, 0x4f, x86_l_4f);
x86_l_b7:
	/* 0xb7: jmp    f5 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf5> */
	X86_SIM_X86_JMP(0xb7, 0xf5, x86_l_f5);
x86_l_b9:
	/* 0xb9: movsx  ecx,ax */
	X86_SIM_RUN_OP(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_bc:
	/* 0xbc: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_bf:
	/* 0xbf: cmp    ecx,0x7530 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 30000ULL);
x86_l_c5:
	/* 0xc5: setge  r9b */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_CC_GE, 0);
x86_l_c9:
	/* 0xc9: shl    r9d,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_cd:
	/* 0xcd: mov    ebx,DWORD PTR [rsi-0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_d0:
	/* 0xd0: movzx  ecx,BYTE PTR [rsi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_d4:
	/* 0xd4: cmp    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_d7:
	/* 0xd7: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd7, 0x4f, x86_l_4f);
x86_l_dd:
	/* 0xdd: jmp    f5 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf5> */
	X86_SIM_X86_JMP(0xdd, 0xf5, x86_l_f5);
x86_l_df:
	/* 0xdf: mov    r9d,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_e5:
	/* 0xe5: mov    ebx,DWORD PTR [rsi-0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_e8:
	/* 0xe8: movzx  ecx,BYTE PTR [rsi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_ec:
	/* 0xec: cmp    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_ef:
	/* 0xef: jne    4f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef, 0x4f, x86_l_4f);
x86_l_f5:
	/* 0xf5: mov    r10d,DWORD PTR [rsi-0x13] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_f9:
	/* 0xf9: movzx  ebp,BYTE PTR [rsi-0x2] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_fd:
	/* 0xfd: test   bpl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_101:
	/* 0x101: je     19d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x19d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x101, 0x19d, x86_l_19d);
x86_l_107:
	/* 0x107: test   r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_10a:
	/* 0x10a: je     19d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x19d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a, 0x19d, x86_l_19d);
x86_l_110:
	/* 0x110: mov    ecx,DWORD PTR [rsi-0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_113:
	/* 0x113: movzx  r14d,BYTE PTR [rsi-0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551609ULL);
x86_l_118:
	/* 0x118: movzx  r15d,BYTE PTR [rsi-0x6] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_11d:
	/* 0x11d: rol    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_ROL, 7ULL);
x86_l_120:
	/* 0x120: xor    ecx,DWORD PTR [rsi-0xf] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RCX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551601ULL);
x86_l_123:
	/* 0x123: movzx  r11d,WORD PTR [rsi-0x1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551615ULL);
x86_l_128:
	/* 0x128: shl    r15d,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_12c:
	/* 0x12c: shl    r14d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_130:
	/* 0x130: or     r14d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_133:
	/* 0x133: movzx  eax,ax */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_136:
	/* 0x136: xor    eax,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_139:
	/* 0x139: xor    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13b:
	/* 0x13b: mov    ecx,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_13d:
	/* 0x13d: shl    ecx,0x1e */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 30ULL);
x86_l_140:
	/* 0x140: sar    ecx,0x1f */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_143:
	/* 0x143: lea    r14d,[r10+rbx*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_147:
	/* 0x147: and    r14d,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_AND, 0);
x86_l_14a:
	/* 0x14a: xor    r14d,r11d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R11, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_14d:
	/* 0x14d: xor    r14d,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_150:
	/* 0x150: lea    ecx,[r9+0x3] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_154:
	/* 0x154: mov    eax,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_157:
	/* 0x157: rol    eax,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ROL, 0);
x86_l_159:
	/* 0x159: test   bpl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_15d:
	/* 0x15d: cmove  eax,r14d */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RAX, X86_R14, X86_WIDTH_32, X86_CC_E, 0);
x86_l_161:
	/* 0x161: shl    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_165:
	/* 0x165: mov    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_167:
	/* 0x167: or     rbx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_16a:
	/* 0x16a: mov    eax,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_16c:
	/* 0x16c: and    al,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_16e:
	/* 0x16e: lea    ecx,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_171:
	/* 0x171: mov    r14,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_174:
	/* 0x174: shl    r14,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_177:
	/* 0x177: not    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_179:
	/* 0x179: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_17b:
	/* 0x17b: shr    rbx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_17e:
	/* 0x17e: or     rbx,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_181:
	/* 0x181: xor    rbx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_184:
	/* 0x184: shl    r9,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_188:
	/* 0x188: shl    r11d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_18c:
	/* 0x18c: or     r11,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_18f:
	/* 0x18f: mov    r8d,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_192:
	/* 0x192: xor    r8,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_195:
	/* 0x195: add    r8,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_198:
	/* 0x198: jmp    5b <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5b> */
	X86_SIM_X86_JMP(0x198, 0x5b, x86_l_5b);
x86_l_19d:
	/* 0x19d: shl    r10,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1a1:
	/* 0x1a1: or     r10,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_1a4:
	/* 0x1a4: add    r8,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_1a7:
	/* 0x1a7: jmp    5b <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5b> */
	X86_SIM_X86_JMP(0x1a7, 0x5b, x86_l_5b);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [rdx],r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af:
	/* 0x1af: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1b4:
	/* 0x1b4: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1b5:
	/* 0x1b5: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1b7:
	/* 0x1b7: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1b9:
	/* 0x1b9: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1ba:
	/* 0x1ba: jmp    1bf <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1bf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1bf:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
