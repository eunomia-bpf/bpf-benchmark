extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_lsm_core_v61_filter_inet_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2:
	/* 0x2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4:
	/* 0x4: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_6:
	/* 0x6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_7:
	/* 0x7: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_b:
	/* 0xb: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_14:
	/* 0x14: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1d:
	/* 0x1d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_26:
	/* 0x26: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2f:
	/* 0x2f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_38:
	/* 0x38: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f:
	/* 0x3f: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_47:
	/* 0x47: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4a:
	/* 0x4a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c:
	/* 0x4c: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_4f:
	/* 0x4f: jg     67 <filter_inet+0x67> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4f, 0x67, x86_l_67);
x86_l_51:
	/* 0x51: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_54:
	/* 0x54: je     ec <filter_inet+0xec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54, 0xec, x86_l_ec);
x86_l_5a:
	/* 0x5a: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_5d:
	/* 0x5d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_60:
	/* 0x60: je     78 <filter_inet+0x78> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60, 0x78, x86_l_78);
x86_l_62:
	/* 0x62: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x62, 0x2fd, x86_l_2fd);
x86_l_67:
	/* 0x67: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_6a:
	/* 0x6a: je     c4 <filter_inet+0xc4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0xc4, x86_l_c4);
x86_l_6c:
	/* 0x6c: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_72:
	/* 0x72: jne    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x72, 0x2fd, x86_l_2fd);
x86_l_78:
	/* 0x78: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7b:
	/* 0x7b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d:
	/* 0x7d: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_80:
	/* 0x80: jle    f9 <filter_inet+0xf9> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x80, 0xf9, x86_l_f9);
x86_l_82:
	/* 0x82: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_85:
	/* 0x85: jg     a4 <filter_inet+0xa4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x85, 0xa4, x86_l_a4);
x86_l_87:
	/* 0x87: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_8a:
	/* 0x8a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_8d:
	/* 0x8d: jb     14a <filter_inet+0x14a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8d, 0x14a, x86_l_14a);
x86_l_93:
	/* 0x93: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_96:
	/* 0x96: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_99:
	/* 0x99: jb     144 <filter_inet+0x144> */
	X86_SIM_X86_JCC(X86_CC_B, 0x99, 0x144, x86_l_144);
x86_l_9f:
	/* 0x9f: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x9f, 0x2fd, x86_l_2fd);
x86_l_a4:
	/* 0xa4: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a7:
	/* 0xa7: jg     187 <filter_inet+0x187> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa7, 0x187, x86_l_187);
x86_l_ad:
	/* 0xad: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_b0:
	/* 0xb0: je     1ba <filter_inet+0x1ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0, 0x1ba, x86_l_1ba);
x86_l_b6:
	/* 0xb6: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_b9:
	/* 0xb9: je     1b0 <filter_inet+0x1b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9, 0x1b0, x86_l_1b0);
x86_l_bf:
	/* 0xbf: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0xbf, 0x2fd, x86_l_2fd);
x86_l_c4:
	/* 0xc4: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c7:
	/* 0xc7: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_cc:
	/* 0xcc: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_d0:
	/* 0xd0: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d5:
	/* 0xd5: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de:
	/* 0xde: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e7:
	/* 0xe7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec:
	/* 0xec: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef:
	/* 0xef: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f2:
	/* 0xf2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f4:
	/* 0xf4: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_f7:
	/* 0xf7: jg     82 <filter_inet+0x82> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf7, 0x82, x86_l_82);
x86_l_f9:
	/* 0xf9: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_fc:
	/* 0xfc: jle    11a <filter_inet+0x11a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xfc, 0x11a, x86_l_11a);
x86_l_fe:
	/* 0xfe: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_101:
	/* 0x101: jg     136 <filter_inet+0x136> */
	X86_SIM_X86_JCC(X86_CC_G, 0x101, 0x136, x86_l_136);
x86_l_103:
	/* 0x103: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_106:
	/* 0x106: je     144 <filter_inet+0x144> */
	X86_SIM_X86_JCC(X86_CC_E, 0x106, 0x144, x86_l_144);
x86_l_108:
	/* 0x108: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_10b:
	/* 0x10b: jne    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10b, 0x2fd, x86_l_2fd);
x86_l_111:
	/* 0x111: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_115:
	/* 0x115: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x115, 0x2f2, x86_l_2f2);
x86_l_11a:
	/* 0x11a: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_11d:
	/* 0x11d: je     1ba <filter_inet+0x1ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d, 0x1ba, x86_l_1ba);
x86_l_123:
	/* 0x123: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_126:
	/* 0x126: je     1b0 <filter_inet+0x1b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x126, 0x1b0, x86_l_1b0);
x86_l_12c:
	/* 0x12c: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_12f:
	/* 0x12f: je     14a <filter_inet+0x14a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f, 0x14a, x86_l_14a);
x86_l_131:
	/* 0x131: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x131, 0x2fd, x86_l_2fd);
x86_l_136:
	/* 0x136: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_139:
	/* 0x139: je     14a <filter_inet+0x14a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x14a, x86_l_14a);
x86_l_13b:
	/* 0x13b: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_13e:
	/* 0x13e: jne    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13e, 0x2fd, x86_l_2fd);
x86_l_144:
	/* 0x144: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_148:
	/* 0x148: jmp    14e <filter_inet+0x14e> */
	X86_SIM_X86_JMP(0x148, 0x14e, x86_l_14e);
x86_l_14a:
	/* 0x14a: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_14e:
	/* 0x14e: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_152:
	/* 0x152: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154:
	/* 0x154: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157:
	/* 0x157: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a:
	/* 0x15a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c:
	/* 0x15c: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_15f:
	/* 0x15f: jg     1d1 <filter_inet+0x1d1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x15f, 0x1d1, x86_l_1d1);
x86_l_161:
	/* 0x161: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_164:
	/* 0x164: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_167:
	/* 0x167: jb     1f8 <filter_inet+0x1f8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x167, 0x1f8, x86_l_1f8);
x86_l_16d:
	/* 0x16d: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_170:
	/* 0x170: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_173:
	/* 0x173: jb     24d <filter_inet+0x24d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x173, 0x24d, x86_l_24d);
x86_l_179:
	/* 0x179: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_17c:
	/* 0x17c: je     2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17c, 0x2f5, x86_l_2f5);
x86_l_182:
	/* 0x182: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x182, 0x2fd, x86_l_2fd);
x86_l_187:
	/* 0x187: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_18a:
	/* 0x18a: je     2ee <filter_inet+0x2ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18a, 0x2ee, x86_l_2ee);
x86_l_190:
	/* 0x190: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_193:
	/* 0x193: jne    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x193, 0x2fd, x86_l_2fd);
x86_l_199:
	/* 0x199: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_19c:
	/* 0x19c: jne    325 <filter_inet+0x325> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19c, 0x325, x86_l_325);
x86_l_1a2:
	/* 0x1a2: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: jne    32f <filter_inet+0x32f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a5, 0x32f, x86_l_32f);
x86_l_1ab:
	/* 0x1ab: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x1ab, 0x2f5, x86_l_2f5);
x86_l_1b0:
	/* 0x1b0: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4:
	/* 0x1b4: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b8:
	/* 0x1b8: jmp    1c1 <filter_inet+0x1c1> */
	X86_SIM_X86_JMP(0x1b8, 0x1c1, x86_l_1c1);
x86_l_1ba:
	/* 0x1ba: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd:
	/* 0x1bd: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c1:
	/* 0x1c1: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1c4:
	/* 0x1c4: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1c8:
	/* 0x1c8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca:
	/* 0x1ca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc:
	/* 0x1cc: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1cf:
	/* 0x1cf: jle    161 <filter_inet+0x161> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1cf, 0x161, x86_l_161);
x86_l_1d1:
	/* 0x1d1: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1d4:
	/* 0x1d4: ja     241 <filter_inet+0x241> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d4, 0x241, x86_l_241);
x86_l_1d6:
	/* 0x1d6: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_1dc:
	/* 0x1dc: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1e0:
	/* 0x1e0: jb     257 <filter_inet+0x257> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e0, 0x257, x86_l_257);
x86_l_1e2:
	/* 0x1e2: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_1e8:
	/* 0x1e8: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1ec:
	/* 0x1ec: jb     267 <filter_inet+0x267> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ec, 0x267, x86_l_267);
x86_l_1ee:
	/* 0x1ee: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_1f3:
	/* 0x1f3: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1f6:
	/* 0x1f6: jae    241 <filter_inet+0x241> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1f6, 0x241, x86_l_241);
x86_l_1f8:
	/* 0x1f8: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1fc:
	/* 0x1fc: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1ff:
	/* 0x1ff: je     277 <filter_inet+0x277> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ff, 0x277, x86_l_277);
x86_l_201:
	/* 0x201: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_204:
	/* 0x204: jne    2e7 <filter_inet+0x2e7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x204, 0x2e7, x86_l_2e7);
x86_l_20a:
	/* 0x20a: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_20d:
	/* 0x20d: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_210:
	/* 0x210: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214:
	/* 0x214: mov    rdi,QWORD PTR [rip+0x1af0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_21b:
	/* 0x21b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220:
	/* 0x220: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_225:
	/* 0x225: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227:
	/* 0x227: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: je     30d <filter_inet+0x30d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22a, 0x30d, x86_l_30d);
x86_l_230:
	/* 0x230: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_233:
	/* 0x233: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_23b:
	/* 0x23b: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f:
	/* 0x23f: jmp    2bb <filter_inet+0x2bb> */
	X86_SIM_X86_JMP(0x23f, 0x2bb, x86_l_2bb);
x86_l_241:
	/* 0x241: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_244:
	/* 0x244: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_247:
	/* 0x247: jae    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x247, 0x2fd, x86_l_2fd);
x86_l_24d:
	/* 0x24d: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_252:
	/* 0x252: jmp    2f8 <filter_inet+0x2f8> */
	X86_SIM_X86_JMP(0x252, 0x2f8, x86_l_2f8);
x86_l_257:
	/* 0x257: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_259:
	/* 0x259: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_25f:
	/* 0x25f: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_262:
	/* 0x262: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x262, 0x2fd, x86_l_2fd);
x86_l_267:
	/* 0x267: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_269:
	/* 0x269: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_26f:
	/* 0x26f: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_272:
	/* 0x272: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x272, 0x2fd, x86_l_2fd);
x86_l_277:
	/* 0x277: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_27d:
	/* 0x27d: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_281:
	/* 0x281: mov    rdi,QWORD PTR [rip+0x1af0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_288:
	/* 0x288: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d:
	/* 0x28d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_292:
	/* 0x292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294:
	/* 0x294: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_297:
	/* 0x297: je     30d <filter_inet+0x30d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x297, 0x30d, x86_l_30d);
x86_l_299:
	/* 0x299: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_2a4:
	/* 0x2a4: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a8:
	/* 0x2a8: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2ad:
	/* 0x2ad: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b2:
	/* 0x2b2: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2b6:
	/* 0x2b6: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2bb:
	/* 0x2bb: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c0:
	/* 0x2c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5:
	/* 0x2c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7:
	/* 0x2c7: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cc:
	/* 0x2cc: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2cf:
	/* 0x2cf: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d2:
	/* 0x2d2: jb     31a <filter_inet+0x31a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2d2, 0x31a, x86_l_31a);
x86_l_2d4:
	/* 0x2d4: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2d7:
	/* 0x2d7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2da:
	/* 0x2da: ja     2e7 <filter_inet+0x2e7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2da, 0x2e7, x86_l_2e7);
x86_l_2dc:
	/* 0x2dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2df:
	/* 0x2df: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2e2:
	/* 0x2e2: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e5:
	/* 0x2e5: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x2e5, 0x2fd, x86_l_2fd);
x86_l_2e7:
	/* 0x2e7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e9:
	/* 0x2e9: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ec:
	/* 0x2ec: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x2ec, 0x2fd, x86_l_2fd);
x86_l_2ee:
	/* 0x2ee: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2f2:
	/* 0x2f2: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5:
	/* 0x2f5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2f8:
	/* 0x2f8: call   345 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_345, 0x2fdULL);
x86_l_2fd:
	/* 0x2fd: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_301:
	/* 0x301: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_302:
	/* 0x302: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_304:
	/* 0x304: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_306:
	/* 0x306: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_308:
	/* 0x308: jmp    3ca <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_30d:
	/* 0x30d: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_312:
	/* 0x312: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_315:
	/* 0x315: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_318:
	/* 0x318: jmp    31d <filter_inet+0x31d> */
	X86_SIM_X86_JMP(0x318, 0x31d, x86_l_31d);
x86_l_31a:
	/* 0x31a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31d:
	/* 0x31d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_320:
	/* 0x320: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_323:
	/* 0x323: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x323, 0x2fd, x86_l_2fd);
x86_l_325:
	/* 0x325: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_328:
	/* 0x328: jne    337 <filter_inet+0x337> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x328, 0x337, x86_l_337);
x86_l_32a:
	/* 0x32a: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_32d:
	/* 0x32d: je     337 <filter_inet+0x337> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x337, x86_l_337);
x86_l_32f:
	/* 0x32f: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_334:
	/* 0x334: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337:
	/* 0x337: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_33a:
	/* 0x33a: je     2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33a, 0x2f5, x86_l_2f5);
x86_l_33c:
	/* 0x33c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_33f:
	/* 0x33f: je     2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33f, 0x2f5, x86_l_2f5);
x86_l_341:
	/* 0x341: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_343:
	/* 0x343: jmp    2fd <filter_inet+0x2fd> */
	X86_SIM_X86_JMP(0x343, 0x2fd, x86_l_2fd);
x86_l_3ca:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_345 */
x86_l_345:
	/* 0x345: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_347:
	/* 0x347: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_348:
	/* 0x348: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_34c:
	/* 0x34c: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_34f:
	/* 0x34f: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_352:
	/* 0x352: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_356:
	/* 0x356: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35a:
	/* 0x35a: mov    rdi,QWORD PTR [rip+0xe40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_361:
	/* 0x361: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_366:
	/* 0x366: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36b:
	/* 0x36b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d:
	/* 0x36d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_370:
	/* 0x370: je     3a5 <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x370, 0x3a5, x86_l_3a5);
x86_l_372:
	/* 0x372: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_375:
	/* 0x375: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_378:
	/* 0x378: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37d:
	/* 0x37d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_382:
	/* 0x382: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_387:
	/* 0x387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389:
	/* 0x389: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38c:
	/* 0x38c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38e:
	/* 0x38e: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_391:
	/* 0x391: ja     3bf <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x391, 0x3bf, x86_l_3bf);
x86_l_393:
	/* 0x393: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_398:
	/* 0x398: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_39b:
	/* 0x39b: jae    3af <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x39b, 0x3af, x86_l_3af);
x86_l_39d:
	/* 0x39d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_3a3:
	/* 0x3a3: jmp    3bf <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x3a3, 0x3bf, x86_l_3bf);
x86_l_3a5:
	/* 0x3a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a7:
	/* 0x3a7: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3ab:
	/* 0x3ab: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3ac:
	/* 0x3ac: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3ae:
	/* 0x3ae: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_3af:
	/* 0x3af: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_3b4:
	/* 0x3b4: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3b7:
	/* 0x3b7: jae    3bf <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3b7, 0x3bf, x86_l_3bf);
x86_l_3b9:
	/* 0x3b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3bc:
	/* 0x3bc: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3bf:
	/* 0x3bf: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3c2:
	/* 0x3c2: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3c6:
	/* 0x3c6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3c7:
	/* 0x3c7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3c9:
	/* 0x3c9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x227ULL: goto x86_l_227;
	case 0x294ULL: goto x86_l_294;
	case 0x2c7ULL: goto x86_l_2c7;
	case 0x2fdULL: goto x86_l_2fd;
	case 0x36dULL: goto x86_l_36d;
	case 0x389ULL: goto x86_l_389;
	}

}

X86_SIM_LICENSE();
