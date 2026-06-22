extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v61_filter_inet_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x5b: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x5b, 0x2f5, x86_l_2f5);
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
	/* 0x6b: jne    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b, 0x2f5, x86_l_2f5);
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
	/* 0x98: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x98, 0x2f5, x86_l_2f5);
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
	/* 0xb8: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0xb8, 0x2f5, x86_l_2f5);
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
	/* 0x104: jne    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x104, 0x2f5, x86_l_2f5);
x86_l_10a:
	/* 0x10a: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_10e:
	/* 0x10e: jmp    2ea <filter_inet+0x2ea> */
	X86_SIM_X86_JMP(0x10e, 0x2ea, x86_l_2ea);
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
	/* 0x12a: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x12a, 0x2f5, x86_l_2f5);
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
	/* 0x137: jne    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x137, 0x2f5, x86_l_2f5);
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
	/* 0x16c: jb     246 <filter_inet+0x246> */
	X86_SIM_X86_JCC(X86_CC_B, 0x16c, 0x246, x86_l_246);
x86_l_172:
	/* 0x172: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_175:
	/* 0x175: je     2ed <filter_inet+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175, 0x2ed, x86_l_2ed);
x86_l_17b:
	/* 0x17b: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x17b, 0x2f5, x86_l_2f5);
x86_l_180:
	/* 0x180: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_183:
	/* 0x183: je     2e6 <filter_inet+0x2e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0x2e6, x86_l_2e6);
x86_l_189:
	/* 0x189: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_18c:
	/* 0x18c: jne    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18c, 0x2f5, x86_l_2f5);
x86_l_192:
	/* 0x192: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_195:
	/* 0x195: jne    315 <filter_inet+0x315> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x195, 0x315, x86_l_315);
x86_l_19b:
	/* 0x19b: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_19e:
	/* 0x19e: jne    31f <filter_inet+0x31f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19e, 0x31f, x86_l_31f);
x86_l_1a4:
	/* 0x1a4: jmp    2ed <filter_inet+0x2ed> */
	X86_SIM_X86_JMP(0x1a4, 0x2ed, x86_l_2ed);
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
	/* 0x1cd: ja     23a <filter_inet+0x23a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1cd, 0x23a, x86_l_23a);
x86_l_1cf:
	/* 0x1cf: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_1d5:
	/* 0x1d5: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1d9:
	/* 0x1d9: jb     250 <filter_inet+0x250> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d9, 0x250, x86_l_250);
x86_l_1db:
	/* 0x1db: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_1e1:
	/* 0x1e1: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_1e5:
	/* 0x1e5: jb     260 <filter_inet+0x260> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e5, 0x260, x86_l_260);
x86_l_1e7:
	/* 0x1e7: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_1ec:
	/* 0x1ec: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1ef:
	/* 0x1ef: jae    23a <filter_inet+0x23a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1ef, 0x23a, x86_l_23a);
x86_l_1f1:
	/* 0x1f1: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1f5:
	/* 0x1f5: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1f8:
	/* 0x1f8: je     270 <filter_inet+0x270> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f8, 0x270, x86_l_270);
x86_l_1fa:
	/* 0x1fa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1fd:
	/* 0x1fd: jne    2df <filter_inet+0x2df> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fd, 0x2df, x86_l_2df);
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
	/* 0x20d: mov    rdi,QWORD PTR [rip+0x1667] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_214:
	/* 0x214: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_219:
	/* 0x219: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21e:
	/* 0x21e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220:
	/* 0x220: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: je     2fe <filter_inet+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x2fe, x86_l_2fe);
x86_l_229:
	/* 0x229: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_234:
	/* 0x234: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_238:
	/* 0x238: jmp    2b4 <filter_inet+0x2b4> */
	X86_SIM_X86_JMP(0x238, 0x2b4, x86_l_2b4);
x86_l_23a:
	/* 0x23a: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_23d:
	/* 0x23d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_240:
	/* 0x240: jae    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x240, 0x2f5, x86_l_2f5);
x86_l_246:
	/* 0x246: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24b:
	/* 0x24b: jmp    2f0 <filter_inet+0x2f0> */
	X86_SIM_X86_JMP(0x24b, 0x2f0, x86_l_2f0);
x86_l_250:
	/* 0x250: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_252:
	/* 0x252: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_258:
	/* 0x258: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_25b:
	/* 0x25b: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x25b, 0x2f5, x86_l_2f5);
x86_l_260:
	/* 0x260: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_262:
	/* 0x262: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_268:
	/* 0x268: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_26b:
	/* 0x26b: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x26b, 0x2f5, x86_l_2f5);
x86_l_270:
	/* 0x270: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_273:
	/* 0x273: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_276:
	/* 0x276: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a:
	/* 0x27a: mov    rdi,QWORD PTR [rip+0x1667] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_281:
	/* 0x281: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_286:
	/* 0x286: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28b:
	/* 0x28b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d:
	/* 0x28d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_290:
	/* 0x290: je     2fe <filter_inet+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x290, 0x2fe, x86_l_2fe);
x86_l_292:
	/* 0x292: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_295:
	/* 0x295: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_29d:
	/* 0x29d: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a1:
	/* 0x2a1: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a6:
	/* 0x2a6: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ab:
	/* 0x2ab: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2af:
	/* 0x2af: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2b4:
	/* 0x2b4: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2b9:
	/* 0x2b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2be:
	/* 0x2be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0:
	/* 0x2c0: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c4:
	/* 0x2c4: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2c7:
	/* 0x2c7: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ca:
	/* 0x2ca: jb     30a <filter_inet+0x30a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2ca, 0x30a, x86_l_30a);
x86_l_2cc:
	/* 0x2cc: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2cf:
	/* 0x2cf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d2:
	/* 0x2d2: ja     2df <filter_inet+0x2df> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2d2, 0x2df, x86_l_2df);
x86_l_2d4:
	/* 0x2d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2da:
	/* 0x2da: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2dd:
	/* 0x2dd: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x2dd, 0x2f5, x86_l_2f5);
x86_l_2df:
	/* 0x2df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e1:
	/* 0x2e1: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e4:
	/* 0x2e4: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x2e4, 0x2f5, x86_l_2f5);
x86_l_2e6:
	/* 0x2e6: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2ea:
	/* 0x2ea: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed:
	/* 0x2ed: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2f0:
	/* 0x2f0: call   335 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_335, 0x2f5ULL);
x86_l_2f5:
	/* 0x2f5: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_2f9:
	/* 0x2f9: jmp    3ba <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2fe:
	/* 0x2fe: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_302:
	/* 0x302: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_305:
	/* 0x305: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_308:
	/* 0x308: jmp    30d <filter_inet+0x30d> */
	X86_SIM_X86_JMP(0x308, 0x30d, x86_l_30d);
x86_l_30a:
	/* 0x30a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_310:
	/* 0x310: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_313:
	/* 0x313: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x313, 0x2f5, x86_l_2f5);
x86_l_315:
	/* 0x315: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_318:
	/* 0x318: jne    327 <filter_inet+0x327> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x318, 0x327, x86_l_327);
x86_l_31a:
	/* 0x31a: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_31d:
	/* 0x31d: je     327 <filter_inet+0x327> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31d, 0x327, x86_l_327);
x86_l_31f:
	/* 0x31f: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_324:
	/* 0x324: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_327:
	/* 0x327: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_32a:
	/* 0x32a: je     2ed <filter_inet+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32a, 0x2ed, x86_l_2ed);
x86_l_32c:
	/* 0x32c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_32f:
	/* 0x32f: je     2ed <filter_inet+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32f, 0x2ed, x86_l_2ed);
x86_l_331:
	/* 0x331: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_333:
	/* 0x333: jmp    2f5 <filter_inet+0x2f5> */
	X86_SIM_X86_JMP(0x333, 0x2f5, x86_l_2f5);
x86_l_3ba:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_335 */
x86_l_335:
	/* 0x335: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_337:
	/* 0x337: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_338:
	/* 0x338: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_33c:
	/* 0x33c: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_33f:
	/* 0x33f: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_342:
	/* 0x342: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_346:
	/* 0x346: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_34a:
	/* 0x34a: mov    rdi,QWORD PTR [rip+0x9b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_351:
	/* 0x351: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_356:
	/* 0x356: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35b:
	/* 0x35b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d:
	/* 0x35d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_360:
	/* 0x360: je     395 <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x360, 0x395, x86_l_395);
x86_l_362:
	/* 0x362: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_365:
	/* 0x365: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368:
	/* 0x368: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36d:
	/* 0x36d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_372:
	/* 0x372: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_377:
	/* 0x377: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_379:
	/* 0x379: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37c:
	/* 0x37c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37e:
	/* 0x37e: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_381:
	/* 0x381: ja     3af <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x381, 0x3af, x86_l_3af);
x86_l_383:
	/* 0x383: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_388:
	/* 0x388: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_38b:
	/* 0x38b: jae    39f <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x38b, 0x39f, x86_l_39f);
x86_l_38d:
	/* 0x38d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_390:
	/* 0x390: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_393:
	/* 0x393: jmp    3af <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x393, 0x3af, x86_l_3af);
x86_l_395:
	/* 0x395: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_397:
	/* 0x397: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_39b:
	/* 0x39b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_39c:
	/* 0x39c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_39e:
	/* 0x39e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_39f:
	/* 0x39f: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_3a4:
	/* 0x3a4: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3a7:
	/* 0x3a7: jae    3af <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x3a7, 0x3af, x86_l_3af);
x86_l_3a9:
	/* 0x3a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ac:
	/* 0x3ac: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3af:
	/* 0x3af: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3b2:
	/* 0x3b2: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3b6:
	/* 0x3b6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3b7:
	/* 0x3b7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3b9:
	/* 0x3b9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x220ULL: goto x86_l_220;
	case 0x28dULL: goto x86_l_28d;
	case 0x2c0ULL: goto x86_l_2c0;
	case 0x2f5ULL: goto x86_l_2f5;
	case 0x35dULL: goto x86_l_35d;
	case 0x379ULL: goto x86_l_379;
	}

}

X86_SIM_LICENSE();
