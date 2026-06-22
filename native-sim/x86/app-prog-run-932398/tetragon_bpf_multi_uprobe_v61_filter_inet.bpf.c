extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_uprobe_v61_filter_inet_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_4:
	/* 0x4: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d:
	/* 0xd: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_16:
	/* 0x16: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1f:
	/* 0x1f: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_28:
	/* 0x28: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_31:
	/* 0x31: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38:
	/* 0x38: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_40:
	/* 0x40: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_43:
	/* 0x43: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45:
	/* 0x45: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_48:
	/* 0x48: jg     60 <filter_inet+0x60> */
	X86_SIM_X86_JCC(X86_CC_G, 0x48, 0x60, x86_l_60);
x86_l_4a:
	/* 0x4a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4d:
	/* 0x4d: je     e5 <filter_inet+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d, 0xe5, x86_l_e5);
x86_l_53:
	/* 0x53: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_56:
	/* 0x56: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_59:
	/* 0x59: je     71 <filter_inet+0x71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59, 0x71, x86_l_71);
x86_l_5b:
	/* 0x5b: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x5b, 0x2f2, x86_l_2f2);
x86_l_60:
	/* 0x60: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_63:
	/* 0x63: je     bd <filter_inet+0xbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0xbd, x86_l_bd);
x86_l_65:
	/* 0x65: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_68:
	/* 0x68: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_6b:
	/* 0x6b: jne    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b, 0x2f2, x86_l_2f2);
x86_l_71:
	/* 0x71: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_74:
	/* 0x74: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_76:
	/* 0x76: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_79:
	/* 0x79: jle    f2 <filter_inet+0xf2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x79, 0xf2, x86_l_f2);
x86_l_7b:
	/* 0x7b: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_7e:
	/* 0x7e: jg     9d <filter_inet+0x9d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7e, 0x9d, x86_l_9d);
x86_l_80:
	/* 0x80: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_83:
	/* 0x83: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_86:
	/* 0x86: jb     143 <filter_inet+0x143> */
	X86_SIM_X86_JCC(X86_CC_B, 0x86, 0x143, x86_l_143);
x86_l_8c:
	/* 0x8c: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_8f:
	/* 0x8f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_92:
	/* 0x92: jb     13d <filter_inet+0x13d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x92, 0x13d, x86_l_13d);
x86_l_98:
	/* 0x98: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x98, 0x2f2, x86_l_2f2);
x86_l_9d:
	/* 0x9d: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a0:
	/* 0xa0: jg     180 <filter_inet+0x180> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa0, 0x180, x86_l_180);
x86_l_a6:
	/* 0xa6: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_a9:
	/* 0xa9: je     1b3 <filter_inet+0x1b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa9, 0x1b3, x86_l_1b3);
x86_l_af:
	/* 0xaf: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_b2:
	/* 0xb2: je     1a9 <filter_inet+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2, 0x1a9, x86_l_1a9);
x86_l_b8:
	/* 0xb8: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0xb8, 0x2f2, x86_l_2f2);
x86_l_bd:
	/* 0xbd: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c0:
	/* 0xc0: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_c5:
	/* 0xc5: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_c9:
	/* 0xc9: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ce:
	/* 0xce: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7:
	/* 0xd7: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db:
	/* 0xdb: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e0:
	/* 0xe0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e5:
	/* 0xe5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8:
	/* 0xe8: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_eb:
	/* 0xeb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed:
	/* 0xed: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_f0:
	/* 0xf0: jg     7b <filter_inet+0x7b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf0, 0x7b, x86_l_7b);
x86_l_f2:
	/* 0xf2: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_f5:
	/* 0xf5: jle    113 <filter_inet+0x113> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xf5, 0x113, x86_l_113);
x86_l_f7:
	/* 0xf7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_fa:
	/* 0xfa: jg     12f <filter_inet+0x12f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfa, 0x12f, x86_l_12f);
x86_l_fc:
	/* 0xfc: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ff:
	/* 0xff: je     13d <filter_inet+0x13d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff, 0x13d, x86_l_13d);
x86_l_101:
	/* 0x101: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_104:
	/* 0x104: jne    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x104, 0x2f2, x86_l_2f2);
x86_l_10a:
	/* 0x10a: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_10e:
	/* 0x10e: jmp    2e7 <filter_inet+0x2e7> */
	X86_SIM_X86_JMP(0x10e, 0x2e7, x86_l_2e7);
x86_l_113:
	/* 0x113: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_116:
	/* 0x116: je     1b3 <filter_inet+0x1b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116, 0x1b3, x86_l_1b3);
x86_l_11c:
	/* 0x11c: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_11f:
	/* 0x11f: je     1a9 <filter_inet+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f, 0x1a9, x86_l_1a9);
x86_l_125:
	/* 0x125: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_128:
	/* 0x128: je     143 <filter_inet+0x143> */
	X86_SIM_X86_JCC(X86_CC_E, 0x128, 0x143, x86_l_143);
x86_l_12a:
	/* 0x12a: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x12a, 0x2f2, x86_l_2f2);
x86_l_12f:
	/* 0x12f: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_132:
	/* 0x132: je     143 <filter_inet+0x143> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132, 0x143, x86_l_143);
x86_l_134:
	/* 0x134: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_137:
	/* 0x137: jne    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x137, 0x2f2, x86_l_2f2);
x86_l_13d:
	/* 0x13d: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_141:
	/* 0x141: jmp    147 <filter_inet+0x147> */
	X86_SIM_X86_JMP(0x141, 0x147, x86_l_147);
x86_l_143:
	/* 0x143: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_147:
	/* 0x147: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14b:
	/* 0x14b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d:
	/* 0x14d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150:
	/* 0x150: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153:
	/* 0x153: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155:
	/* 0x155: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_158:
	/* 0x158: jg     1ca <filter_inet+0x1ca> */
	X86_SIM_X86_JCC(X86_CC_G, 0x158, 0x1ca, x86_l_1ca);
x86_l_15a:
	/* 0x15a: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_15d:
	/* 0x15d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_160:
	/* 0x160: jb     1f1 <filter_inet+0x1f1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x160, 0x1f1, x86_l_1f1);
x86_l_166:
	/* 0x166: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_169:
	/* 0x169: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_16c:
	/* 0x16c: jb     243 <filter_inet+0x243> */
	X86_SIM_X86_JCC(X86_CC_B, 0x16c, 0x243, x86_l_243);
x86_l_172:
	/* 0x172: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_175:
	/* 0x175: je     2ea <filter_inet+0x2ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175, 0x2ea, x86_l_2ea);
x86_l_17b:
	/* 0x17b: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x17b, 0x2f2, x86_l_2f2);
x86_l_180:
	/* 0x180: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_183:
	/* 0x183: je     2e3 <filter_inet+0x2e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0x2e3, x86_l_2e3);
x86_l_189:
	/* 0x189: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_18c:
	/* 0x18c: jne    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18c, 0x2f2, x86_l_2f2);
x86_l_192:
	/* 0x192: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_195:
	/* 0x195: jne    312 <filter_inet+0x312> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x195, 0x312, x86_l_312);
x86_l_19b:
	/* 0x19b: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_19e:
	/* 0x19e: jne    31c <filter_inet+0x31c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19e, 0x31c, x86_l_31c);
x86_l_1a4:
	/* 0x1a4: jmp    2ea <filter_inet+0x2ea> */
	X86_SIM_X86_JMP(0x1a4, 0x2ea, x86_l_2ea);
x86_l_1a9:
	/* 0x1a9: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad:
	/* 0x1ad: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b1:
	/* 0x1b1: jmp    1ba <filter_inet+0x1ba> */
	X86_SIM_X86_JMP(0x1b1, 0x1ba, x86_l_1ba);
x86_l_1b3:
	/* 0x1b3: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6:
	/* 0x1b6: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba:
	/* 0x1ba: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1bd:
	/* 0x1bd: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1c1:
	/* 0x1c1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c3:
	/* 0x1c3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c5:
	/* 0x1c5: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1c8:
	/* 0x1c8: jle    15a <filter_inet+0x15a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1c8, 0x15a, x86_l_15a);
x86_l_1ca:
	/* 0x1ca: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1cd:
	/* 0x1cd: ja     237 <filter_inet+0x237> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1cd, 0x237, x86_l_237);
x86_l_1cf:
	/* 0x1cf: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_1d5:
	/* 0x1d5: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1d9:
	/* 0x1d9: jb     24d <filter_inet+0x24d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d9, 0x24d, x86_l_24d);
x86_l_1db:
	/* 0x1db: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_1e1:
	/* 0x1e1: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1e5:
	/* 0x1e5: jb     25d <filter_inet+0x25d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e5, 0x25d, x86_l_25d);
x86_l_1e7:
	/* 0x1e7: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_1ec:
	/* 0x1ec: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1ef:
	/* 0x1ef: jae    237 <filter_inet+0x237> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1ef, 0x237, x86_l_237);
x86_l_1f1:
	/* 0x1f1: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1f5:
	/* 0x1f5: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1f8:
	/* 0x1f8: je     26d <filter_inet+0x26d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f8, 0x26d, x86_l_26d);
x86_l_1fa:
	/* 0x1fa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fd:
	/* 0x1fd: jne    2dc <filter_inet+0x2dc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fd, 0x2dc, x86_l_2dc);
x86_l_203:
	/* 0x203: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_206:
	/* 0x206: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_209:
	/* 0x209: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d:
	/* 0x20d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_212:
	/* 0x212: mov    rdi,QWORD PTR [rip+0x17f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_219:
	/* 0x219: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e:
	/* 0x21e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220:
	/* 0x220: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: je     2fb <filter_inet+0x2fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x2fb, x86_l_2fb);
x86_l_229:
	/* 0x229: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_231:
	/* 0x231: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_235:
	/* 0x235: jmp    2ae <filter_inet+0x2ae> */
	X86_SIM_X86_JMP(0x235, 0x2ae, x86_l_2ae);
x86_l_237:
	/* 0x237: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_23a:
	/* 0x23a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23d:
	/* 0x23d: jae    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x23d, 0x2f2, x86_l_2f2);
x86_l_243:
	/* 0x243: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_248:
	/* 0x248: jmp    2ed <filter_inet+0x2ed> */
	X86_SIM_X86_JMP(0x248, 0x2ed, x86_l_2ed);
x86_l_24d:
	/* 0x24d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24f:
	/* 0x24f: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_255:
	/* 0x255: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_258:
	/* 0x258: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x258, 0x2f2, x86_l_2f2);
x86_l_25d:
	/* 0x25d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25f:
	/* 0x25f: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_265:
	/* 0x265: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_268:
	/* 0x268: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x268, 0x2f2, x86_l_2f2);
x86_l_26d:
	/* 0x26d: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_270:
	/* 0x270: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_273:
	/* 0x273: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_277:
	/* 0x277: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c:
	/* 0x27c: mov    rdi,QWORD PTR [rip+0x17f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_283:
	/* 0x283: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288:
	/* 0x288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a:
	/* 0x28a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d:
	/* 0x28d: je     2fb <filter_inet+0x2fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28d, 0x2fb, x86_l_2fb);
x86_l_28f:
	/* 0x28f: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_297:
	/* 0x297: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b:
	/* 0x29b: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a0:
	/* 0x2a0: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a5:
	/* 0x2a5: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2a9:
	/* 0x2a9: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2ae:
	/* 0x2ae: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b3:
	/* 0x2b3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2b8:
	/* 0x2b8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2bb:
	/* 0x2bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2bd:
	/* 0x2bd: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c1:
	/* 0x2c1: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2c4:
	/* 0x2c4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2c7:
	/* 0x2c7: jb     307 <filter_inet+0x307> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2c7, 0x307, x86_l_307);
x86_l_2c9:
	/* 0x2c9: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2cc:
	/* 0x2cc: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2cf:
	/* 0x2cf: ja     2dc <filter_inet+0x2dc> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2cf, 0x2dc, x86_l_2dc);
x86_l_2d1:
	/* 0x2d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d4:
	/* 0x2d4: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2d7:
	/* 0x2d7: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2da:
	/* 0x2da: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x2da, 0x2f2, x86_l_2f2);
x86_l_2dc:
	/* 0x2dc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de:
	/* 0x2de: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e1:
	/* 0x2e1: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x2e1, 0x2f2, x86_l_2f2);
x86_l_2e3:
	/* 0x2e3: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2e7:
	/* 0x2e7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea:
	/* 0x2ea: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2ed:
	/* 0x2ed: call   332 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_332, 0x2f2ULL);
x86_l_2f2:
	/* 0x2f2: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_2f6:
	/* 0x2f6: jmp    3b7 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2fb:
	/* 0x2fb: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ff:
	/* 0x2ff: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_302:
	/* 0x302: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_305:
	/* 0x305: jmp    30a <filter_inet+0x30a> */
	X86_SIM_X86_JMP(0x305, 0x30a, x86_l_30a);
x86_l_307:
	/* 0x307: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30a:
	/* 0x30a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_30d:
	/* 0x30d: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_310:
	/* 0x310: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x310, 0x2f2, x86_l_2f2);
x86_l_312:
	/* 0x312: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_315:
	/* 0x315: jne    324 <filter_inet+0x324> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x315, 0x324, x86_l_324);
x86_l_317:
	/* 0x317: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_31a:
	/* 0x31a: je     324 <filter_inet+0x324> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31a, 0x324, x86_l_324);
x86_l_31c:
	/* 0x31c: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_321:
	/* 0x321: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_324:
	/* 0x324: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_327:
	/* 0x327: je     2ea <filter_inet+0x2ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x327, 0x2ea, x86_l_2ea);
x86_l_329:
	/* 0x329: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_32c:
	/* 0x32c: je     2ea <filter_inet+0x2ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32c, 0x2ea, x86_l_2ea);
x86_l_32e:
	/* 0x32e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_330:
	/* 0x330: jmp    2f2 <filter_inet+0x2f2> */
	X86_SIM_X86_JMP(0x330, 0x2f2, x86_l_2f2);
x86_l_3b7:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_332 */
x86_l_332:
	/* 0x332: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_334:
	/* 0x334: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_335:
	/* 0x335: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_339:
	/* 0x339: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_33c:
	/* 0x33c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_33f:
	/* 0x33f: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_343:
	/* 0x343: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_347:
	/* 0x347: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34c:
	/* 0x34c: mov    rdi,QWORD PTR [rip+0xb40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_353:
	/* 0x353: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_358:
	/* 0x358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a:
	/* 0x35a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: je     392 <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x35d, 0x392, x86_l_392);
x86_l_35f:
	/* 0x35f: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_362:
	/* 0x362: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_367:
	/* 0x367: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_36c:
	/* 0x36c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_371:
	/* 0x371: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_374:
	/* 0x374: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_376:
	/* 0x376: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_379:
	/* 0x379: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37b:
	/* 0x37b: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_37e:
	/* 0x37e: ja     3ac <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x37e, 0x3ac, x86_l_3ac);
x86_l_380:
	/* 0x380: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_385:
	/* 0x385: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_388:
	/* 0x388: jae    39c <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x388, 0x39c, x86_l_39c);
x86_l_38a:
	/* 0x38a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_390:
	/* 0x390: jmp    3ac <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x390, 0x3ac, x86_l_3ac);
x86_l_392:
	/* 0x392: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_394:
	/* 0x394: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_398:
	/* 0x398: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_399:
	/* 0x399: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_39b:
	/* 0x39b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_39c:
	/* 0x39c: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_3a1:
	/* 0x3a1: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3a4:
	/* 0x3a4: jae    3ac <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3a4, 0x3ac, x86_l_3ac);
x86_l_3a6:
	/* 0x3a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a9:
	/* 0x3a9: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3ac:
	/* 0x3ac: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3af:
	/* 0x3af: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3b3:
	/* 0x3b3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3b4:
	/* 0x3b4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3b6:
	/* 0x3b6: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x220ULL: goto x86_l_220;
	case 0x28aULL: goto x86_l_28a;
	case 0x2bdULL: goto x86_l_2bd;
	case 0x2f2ULL: goto x86_l_2f2;
	case 0x35aULL: goto x86_l_35a;
	case 0x376ULL: goto x86_l_376;
	}

}

X86_SIM_LICENSE();
