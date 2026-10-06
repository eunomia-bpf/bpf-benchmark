#include "../x86_sim_local_bpf.h"

SEC("xdp")
int payload_prefix_memcmp_scan_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rcx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rsi,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c:
	/* 0xc: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: jbe    16 <payload_prefix_memcmp_scan_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    323 <payload_prefix_memcmp_scan_xdp+0x323> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <payload_prefix_memcmp_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <payload_prefix_memcmp_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_2e:
	/* 0x2e: jne    11 <payload_prefix_memcmp_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e, 0x11, x86_l_11);
x86_l_30:
	/* 0x30: mov    r8d,0x57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 87ULL);
x86_l_36:
	/* 0x36: mov    r9d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 12ULL);
x86_l_3c:
	/* 0x3c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e:
	/* 0x3e: movzx  esi,BYTE PTR [rdx+rax*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 12ULL);
x86_l_43:
	/* 0x43: lea    r10d,[r8-0x57] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551529ULL);
x86_l_47:
	/* 0x47: lea    edi,[r9-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_4b:
	/* 0x4b: xor    edi,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e:
	/* 0x4e: xor    edi,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_54:
	/* 0x54: add    edi,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_57:
	/* 0x57: cmp    sil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_8);
x86_l_5a:
	/* 0x5a: jne    d7 <payload_prefix_memcmp_scan_xdp+0xd7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a, 0xd7, x86_l_d7);
x86_l_5c:
	/* 0x5c: movzx  esi,BYTE PTR [rdx+rax*1+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 13ULL);
x86_l_61:
	/* 0x61: lea    r10d,[r8-0x3a] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551558ULL);
x86_l_65:
	/* 0x65: lea    edi,[r9-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_69:
	/* 0x69: xor    edi,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c:
	/* 0x6c: xor    edi,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_72:
	/* 0x72: add    edi,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_75:
	/* 0x75: cmp    sil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_8);
x86_l_78:
	/* 0x78: jne    dc <payload_prefix_memcmp_scan_xdp+0xdc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x78, 0xdc, x86_l_dc);
x86_l_7a:
	/* 0x7a: movzx  esi,BYTE PTR [rdx+rax*1+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 14ULL);
x86_l_7f:
	/* 0x7f: lea    r10d,[r8-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_83:
	/* 0x83: lea    edi,[r9-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_87:
	/* 0x87: xor    edi,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a:
	/* 0x8a: xor    edi,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_90:
	/* 0x90: add    edi,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_93:
	/* 0x93: cmp    sil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_8);
x86_l_96:
	/* 0x96: jne    e2 <payload_prefix_memcmp_scan_xdp+0xe2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x96, 0xe2, x86_l_e2);
x86_l_98:
	/* 0x98: movzx  esi,BYTE PTR [rdx+rax*1+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 15ULL);
x86_l_9d:
	/* 0x9d: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_a0:
	/* 0xa0: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3:
	/* 0xa3: xor    edi,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_a9:
	/* 0xa9: add    edi,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_ac:
	/* 0xac: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b0:
	/* 0xb0: cmp    sil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_8);
x86_l_b3:
	/* 0xb3: jne    e6 <payload_prefix_memcmp_scan_xdp+0xe6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb3, 0xe6, x86_l_e6);
x86_l_b5:
	/* 0xb5: add    r8d,0x74 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 116ULL);
x86_l_b9:
	/* 0xb9: add    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_bd:
	/* 0xbd: cmp    rax,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 64ULL);
x86_l_c1:
	/* 0xc1: jne    3e <payload_prefix_memcmp_scan_xdp+0x3e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc1, 0x3e, x86_l_3e);
x86_l_c7:
	/* 0xc7: movzx  esi,BYTE PTR [rdx+0x4b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 75ULL);
x86_l_cb:
	/* 0xcb: movabs rax,0xf43e9fde8cf6b51c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17599680172007011612ULL);
x86_l_d5:
	/* 0xd5: jmp    104 <payload_prefix_memcmp_scan_xdp+0x104> */
	X86_SIM_X86_JMP(0xd5, 0x104, x86_l_104);
x86_l_d7:
	/* 0xd7: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_da:
	/* 0xda: jmp    e6 <payload_prefix_memcmp_scan_xdp+0xe6> */
	X86_SIM_X86_JMP(0xda, 0xe6, x86_l_e6);
x86_l_dc:
	/* 0xdc: add    rax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_e0:
	/* 0xe0: jmp    e6 <payload_prefix_memcmp_scan_xdp+0xe6> */
	X86_SIM_X86_JMP(0xe0, 0xe6, x86_l_e6);
x86_l_e2:
	/* 0xe2: add    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_e6:
	/* 0xe6: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e8:
	/* 0xe8: lea    rax,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_ec:
	/* 0xec: movabs r8,0x6a09e667f3bcc909 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 7640891576956012809ULL);
x86_l_f6:
	/* 0xf6: add    r8,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f9:
	/* 0xf9: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fd:
	/* 0xfd: xor    rsi,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_XOR);
x86_l_100:
	/* 0x100: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_104:
	/* 0x104: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_107:
	/* 0x107: rorx   rax,rax,0x3b */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 59ULL);
x86_l_10d:
	/* 0x10d: mov    r9d,0x57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 87ULL);
x86_l_113:
	/* 0x113: mov    r10d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 12ULL);
x86_l_119:
	/* 0x119: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b:
	/* 0x11b: movzx  edi,BYTE PTR [rdx+rsi*1+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 76ULL);
x86_l_120:
	/* 0x120: lea    r11d,[r9-0x57] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551529ULL);
x86_l_124:
	/* 0x124: lea    r8d,[r10-0xc] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_128:
	/* 0x128: xor    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b:
	/* 0x12b: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_132:
	/* 0x132: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_136:
	/* 0x136: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_139:
	/* 0x139: jne    1cc <payload_prefix_memcmp_scan_xdp+0x1cc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x139, 0x1cc, x86_l_1cc);
x86_l_13f:
	/* 0x13f: movzx  edi,BYTE PTR [rdx+rsi*1+0x4d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 77ULL);
x86_l_144:
	/* 0x144: lea    r11d,[r9-0x3a] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551558ULL);
x86_l_148:
	/* 0x148: lea    r8d,[r10-0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_14c:
	/* 0x14c: xor    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f:
	/* 0x14f: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_156:
	/* 0x156: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_15a:
	/* 0x15a: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_15d:
	/* 0x15d: jne    1d1 <payload_prefix_memcmp_scan_xdp+0x1d1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15d, 0x1d1, x86_l_1d1);
x86_l_15f:
	/* 0x15f: movzx  edi,BYTE PTR [rdx+rsi*1+0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 78ULL);
x86_l_164:
	/* 0x164: lea    r11d,[r9-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_168:
	/* 0x168: lea    r8d,[r10-0x4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_16c:
	/* 0x16c: xor    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f:
	/* 0x16f: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_176:
	/* 0x176: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_17a:
	/* 0x17a: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_17d:
	/* 0x17d: jne    1d7 <payload_prefix_memcmp_scan_xdp+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17d, 0x1d7, x86_l_1d7);
x86_l_17f:
	/* 0x17f: movzx  edi,BYTE PTR [rdx+rsi*1+0x4f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 79ULL);
x86_l_184:
	/* 0x184: mov    r8d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R10, X86_WIDTH_32);
x86_l_187:
	/* 0x187: xor    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a:
	/* 0x18a: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_191:
	/* 0x191: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_195:
	/* 0x195: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_199:
	/* 0x199: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_19c:
	/* 0x19c: jne    1db <payload_prefix_memcmp_scan_xdp+0x1db> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19c, 0x1db, x86_l_1db);
x86_l_19e:
	/* 0x19e: add    r9d,0x74 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_ADD, 116ULL);
x86_l_1a2:
	/* 0x1a2: add    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1a6:
	/* 0x1a6: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_1aa:
	/* 0x1aa: jne    11b <payload_prefix_memcmp_scan_xdp+0x11b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1aa, 0x11b, x86_l_11b);
x86_l_1b0:
	/* 0x1b0: movabs rsi,0x9e3779b97f4a7c16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 11400714819323198486ULL);
x86_l_1ba:
	/* 0x1ba: xor    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_1bd:
	/* 0x1bd: movzx  esi,BYTE PTR [rdx+0x8b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 139ULL);
x86_l_1c4:
	/* 0x1c4: shl    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1c7:
	/* 0x1c7: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ca:
	/* 0x1ca: jmp    1f6 <payload_prefix_memcmp_scan_xdp+0x1f6> */
	X86_SIM_X86_JMP(0x1ca, 0x1f6, x86_l_1f6);
x86_l_1cc:
	/* 0x1cc: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1cf:
	/* 0x1cf: jmp    1db <payload_prefix_memcmp_scan_xdp+0x1db> */
	X86_SIM_X86_JMP(0x1cf, 0x1db, x86_l_1db);
x86_l_1d1:
	/* 0x1d1: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1d5:
	/* 0x1d5: jmp    1db <payload_prefix_memcmp_scan_xdp+0x1db> */
	X86_SIM_X86_JMP(0x1d5, 0x1db, x86_l_1db);
x86_l_1d7:
	/* 0x1d7: add    rsi,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1db:
	/* 0x1db: mov    esi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_1dd:
	/* 0x1dd: lea    rsi,[rsi+rsi*2] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 1), 0ULL);
x86_l_1e1:
	/* 0x1e1: lea    rax,[rax+rsi*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 1), 0ULL);
x86_l_1e5:
	/* 0x1e5: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e9:
	/* 0x1e9: shl    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1ec:
	/* 0x1ec: xor    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_1ef:
	/* 0x1ef: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f3:
	/* 0x1f3: add    rsi,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f6:
	/* 0x1f6: rorx   rax,rsi,0x3a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RSI, X86_WIDTH_64, 0, 58ULL);
x86_l_1fc:
	/* 0x1fc: mov    r9d,0x57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 87ULL);
x86_l_202:
	/* 0x202: mov    r10d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 12ULL);
x86_l_208:
	/* 0x208: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a:
	/* 0x20a: movzx  edi,BYTE PTR [rdx+rsi*1+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 140ULL);
x86_l_212:
	/* 0x212: lea    r11d,[r9-0x57] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551529ULL);
x86_l_216:
	/* 0x216: lea    r8d,[r10-0xc] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_21a:
	/* 0x21a: xor    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21d:
	/* 0x21d: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_224:
	/* 0x224: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_228:
	/* 0x228: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_22b:
	/* 0x22b: jne    2e0 <payload_prefix_memcmp_scan_xdp+0x2e0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22b, 0x2e0, x86_l_2e0);
x86_l_231:
	/* 0x231: movzx  edi,BYTE PTR [rdx+rsi*1+0x8d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 141ULL);
x86_l_239:
	/* 0x239: lea    r11d,[r9-0x3a] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551558ULL);
x86_l_23d:
	/* 0x23d: lea    r8d,[r10-0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_241:
	/* 0x241: xor    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_244:
	/* 0x244: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_24b:
	/* 0x24b: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_24f:
	/* 0x24f: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_252:
	/* 0x252: jne    2e5 <payload_prefix_memcmp_scan_xdp+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x252, 0x2e5, x86_l_2e5);
x86_l_258:
	/* 0x258: movzx  edi,BYTE PTR [rdx+rsi*1+0x8e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 142ULL);
x86_l_260:
	/* 0x260: lea    r11d,[r9-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_264:
	/* 0x264: lea    r8d,[r10-0x4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_268:
	/* 0x268: xor    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26b:
	/* 0x26b: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_272:
	/* 0x272: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_276:
	/* 0x276: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_279:
	/* 0x279: jne    2eb <payload_prefix_memcmp_scan_xdp+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x279, 0x2eb, x86_l_2eb);
x86_l_27b:
	/* 0x27b: movzx  edi,BYTE PTR [rdx+rsi*1+0x8f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 143ULL);
x86_l_283:
	/* 0x283: mov    r8d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R10, X86_WIDTH_32);
x86_l_286:
	/* 0x286: xor    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_289:
	/* 0x289: xor    r8d,0xa5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 165ULL);
x86_l_290:
	/* 0x290: add    r8d,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 17ULL);
x86_l_294:
	/* 0x294: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_298:
	/* 0x298: cmp    dil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_8);
x86_l_29b:
	/* 0x29b: jne    2ef <payload_prefix_memcmp_scan_xdp+0x2ef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29b, 0x2ef, x86_l_2ef);
x86_l_29d:
	/* 0x29d: add    r9d,0x74 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_ADD, 116ULL);
x86_l_2a1:
	/* 0x2a1: add    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_2a5:
	/* 0x2a5: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_2a9:
	/* 0x2a9: jne    20a <payload_prefix_memcmp_scan_xdp+0x20a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a9, 0x20a, x86_l_20a);
x86_l_2af:
	/* 0x2af: movabs rsi,0x9e3779b97f4a7c16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 11400714819323198486ULL);
x86_l_2b9:
	/* 0x2b9: or     rsi,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_OR, 1ULL);
x86_l_2bd:
	/* 0x2bd: xor    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_2c0:
	/* 0x2c0: movzx  edx,BYTE PTR [rdx+0xcb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 203ULL);
x86_l_2c7:
	/* 0x2c7: shl    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_2ca:
	/* 0x2ca: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cd:
	/* 0x2cd: rorx   rax,rdx,0x39 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 57ULL);
x86_l_2d3:
	/* 0x2d3: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6:
	/* 0x2d6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2db:
	/* 0x2db: jmp    323 <payload_prefix_memcmp_scan_xdp+0x323> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2e0:
	/* 0x2e0: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e3:
	/* 0x2e3: jmp    2ef <payload_prefix_memcmp_scan_xdp+0x2ef> */
	X86_SIM_X86_JMP(0x2e3, 0x2ef, x86_l_2ef);
x86_l_2e5:
	/* 0x2e5: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2e9:
	/* 0x2e9: jmp    2ef <payload_prefix_memcmp_scan_xdp+0x2ef> */
	X86_SIM_X86_JMP(0x2e9, 0x2ef, x86_l_2ef);
x86_l_2eb:
	/* 0x2eb: add    rsi,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2ef:
	/* 0x2ef: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f1:
	/* 0x2f1: lea    rsi,[rdx*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_2f9:
	/* 0x2f9: sub    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2fc:
	/* 0x2fc: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ff:
	/* 0x2ff: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_303:
	/* 0x303: shl    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_306:
	/* 0x306: xor    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR);
x86_l_309:
	/* 0x309: movzx  edx,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30d:
	/* 0x30d: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_310:
	/* 0x310: rorx   rax,rdx,0x39 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RDX, X86_WIDTH_64, 0, 57ULL);
x86_l_316:
	/* 0x316: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319:
	/* 0x319: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31e:
	/* 0x31e: jmp    323 <payload_prefix_memcmp_scan_xdp+0x323> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_323:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
