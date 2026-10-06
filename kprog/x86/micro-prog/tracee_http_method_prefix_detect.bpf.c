#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_http_method_prefix_detect_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <tracee_http_method_prefix_detect_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    26f <tracee_http_method_prefix_detect_xdp+0x26f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <tracee_http_method_prefix_detect_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <tracee_http_method_prefix_detect_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdx+0x8],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738376ULL);
x86_l_2f:
	/* 0x2f: jne    11 <tracee_http_method_prefix_detect_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdx+0xc],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607568ULL);
x86_l_35:
	/* 0x35: jne    11 <tracee_http_method_prefix_detect_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_39:
	/* 0x39: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3a:
	/* 0x3a: add    rdx,0x16 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 22ULL);
x86_l_3e:
	/* 0x3e: movabs rbx,0xa0761d6478bd642f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 11562461410679940143ULL);
x86_l_48:
	/* 0x48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d:
	/* 0x4d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: movzx  edi,BYTE PTR [rdx-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551610ULL);
x86_l_54:
	/* 0x54: movzx  r8d,BYTE PTR [rdx-0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551611ULL);
x86_l_59:
	/* 0x59: cmp    edi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 71ULL);
x86_l_5c:
	/* 0x5c: jg     9f <tracee_http_method_prefix_detect_xdp+0x9f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5c, 0x9f, x86_l_9f);
x86_l_5e:
	/* 0x5e: cmp    edi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 68ULL);
x86_l_61:
	/* 0x61: je     fe <tracee_http_method_prefix_detect_xdp+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61, 0xfe, x86_l_fe);
x86_l_67:
	/* 0x67: cmp    edi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 71ULL);
x86_l_6a:
	/* 0x6a: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6a, 0x1c5, x86_l_1c5);
x86_l_70:
	/* 0x70: cmp    r8b,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 69ULL);
x86_l_74:
	/* 0x74: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x74, 0x1c5, x86_l_1c5);
x86_l_7a:
	/* 0x7a: mov    r8b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 69ULL);
x86_l_7d:
	/* 0x7d: cmp    BYTE PTR [rdx-0x4],0x54 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_81:
	/* 0x81: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x81, 0x1c5, x86_l_1c5);
x86_l_87:
	/* 0x87: mov    r10b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_8, 69ULL);
x86_l_8a:
	/* 0x8a: cmp    BYTE PTR [rdx-0x3],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649760ULL);
x86_l_8e:
	/* 0x8e: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e, 0x1c5, x86_l_1c5);
x86_l_94:
	/* 0x94: mov    r9d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 1ULL);
x86_l_9a:
	/* 0x9a: jmp    19a <tracee_http_method_prefix_detect_xdp+0x19a> */
	X86_SIM_X86_JMP(0x9a, 0x19a, x86_l_19a);
x86_l_9f:
	/* 0x9f: movzx  r9d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a3:
	/* 0xa3: cmp    edi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 72ULL);
x86_l_a6:
	/* 0xa6: je     150 <tracee_http_method_prefix_detect_xdp+0x150> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa6, 0x150, x86_l_150);
x86_l_ac:
	/* 0xac: cmp    edi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 80ULL);
x86_l_af:
	/* 0xaf: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaf, 0x1c5, x86_l_1c5);
x86_l_b5:
	/* 0xb5: cmp    r9d,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 85ULL);
x86_l_b9:
	/* 0xb9: je     182 <tracee_http_method_prefix_detect_xdp+0x182> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9, 0x182, x86_l_182);
x86_l_bf:
	/* 0xbf: cmp    r9d,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 79ULL);
x86_l_c3:
	/* 0xc3: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc3, 0x1c5, x86_l_1c5);
x86_l_c9:
	/* 0xc9: mov    r8b,0x4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 79ULL);
x86_l_cc:
	/* 0xcc: cmp    BYTE PTR [rdx-0x4],0x53 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682515ULL);
x86_l_d0:
	/* 0xd0: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd0, 0x1c5, x86_l_1c5);
x86_l_d6:
	/* 0xd6: cmp    BYTE PTR [rdx-0x3],0x54 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649812ULL);
x86_l_da:
	/* 0xda: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xda, 0x1c5, x86_l_1c5);
x86_l_e0:
	/* 0xe0: mov    r10b,0x4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_8, 79ULL);
x86_l_e3:
	/* 0xe3: cmp    BYTE PTR [rdx-0x2],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617056ULL);
x86_l_e7:
	/* 0xe7: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7, 0x1c5, x86_l_1c5);
x86_l_ed:
	/* 0xed: mov    r9d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 2ULL);
x86_l_f3:
	/* 0xf3: mov    r8b,0x53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 83ULL);
x86_l_f6:
	/* 0xf6: mov    r11b,0x54 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 84ULL);
x86_l_f9:
	/* 0xf9: jmp    1d5 <tracee_http_method_prefix_detect_xdp+0x1d5> */
	X86_SIM_X86_JMP(0xf9, 0x1d5, x86_l_1d5);
x86_l_fe:
	/* 0xfe: cmp    r8b,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 69ULL);
x86_l_102:
	/* 0x102: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x102, 0x1c5, x86_l_1c5);
x86_l_108:
	/* 0x108: mov    r8b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 69ULL);
x86_l_10b:
	/* 0x10b: cmp    BYTE PTR [rdx-0x4],0x4c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682508ULL);
x86_l_10f:
	/* 0x10f: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10f, 0x1c5, x86_l_1c5);
x86_l_115:
	/* 0x115: cmp    BYTE PTR [rdx-0x3],0x45 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649797ULL);
x86_l_119:
	/* 0x119: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x119, 0x1c5, x86_l_1c5);
x86_l_11f:
	/* 0x11f: cmp    BYTE PTR [rdx-0x2],0x54 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617108ULL);
x86_l_123:
	/* 0x123: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x123, 0x1c5, x86_l_1c5);
x86_l_129:
	/* 0x129: cmp    BYTE PTR [rdx-0x1],0x45 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744069414584389ULL);
x86_l_12d:
	/* 0x12d: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12d, 0x1c5, x86_l_1c5);
x86_l_133:
	/* 0x133: mov    r11b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 69ULL);
x86_l_136:
	/* 0x136: cmp    BYTE PTR [rdx],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_139:
	/* 0x139: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x139, 0x1c5, x86_l_1c5);
x86_l_13f:
	/* 0x13f: mov    r9d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4ULL);
x86_l_145:
	/* 0x145: mov    r8b,0x4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 76ULL);
x86_l_148:
	/* 0x148: mov    r10b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_8, 69ULL);
x86_l_14b:
	/* 0x14b: jmp    1d5 <tracee_http_method_prefix_detect_xdp+0x1d5> */
	X86_SIM_X86_JMP(0x14b, 0x1d5, x86_l_1d5);
x86_l_150:
	/* 0x150: cmp    r9d,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 84ULL);
x86_l_154:
	/* 0x154: je     1a2 <tracee_http_method_prefix_detect_xdp+0x1a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154, 0x1a2, x86_l_1a2);
x86_l_156:
	/* 0x156: cmp    r9d,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 69ULL);
x86_l_15a:
	/* 0x15a: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15a, 0x1c5, x86_l_1c5);
x86_l_15c:
	/* 0x15c: mov    r8b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 69ULL);
x86_l_15f:
	/* 0x15f: cmp    BYTE PTR [rdx-0x4],0x41 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682497ULL);
x86_l_163:
	/* 0x163: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x163, 0x1c5, x86_l_1c5);
x86_l_165:
	/* 0x165: cmp    BYTE PTR [rdx-0x3],0x44 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649796ULL);
x86_l_169:
	/* 0x169: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x169, 0x1c5, x86_l_1c5);
x86_l_16b:
	/* 0x16b: mov    r10b,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_8, 69ULL);
x86_l_16e:
	/* 0x16e: cmp    BYTE PTR [rdx-0x2],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617056ULL);
x86_l_172:
	/* 0x172: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x172, 0x1c5, x86_l_1c5);
x86_l_174:
	/* 0x174: mov    r9d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 5ULL);
x86_l_17a:
	/* 0x17a: mov    r8b,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 65ULL);
x86_l_17d:
	/* 0x17d: mov    r11b,0x44 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 68ULL);
x86_l_180:
	/* 0x180: jmp    1d5 <tracee_http_method_prefix_detect_xdp+0x1d5> */
	X86_SIM_X86_JMP(0x180, 0x1d5, x86_l_1d5);
x86_l_182:
	/* 0x182: mov    r8b,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 85ULL);
x86_l_185:
	/* 0x185: cmp    BYTE PTR [rdx-0x4],0x54 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_189:
	/* 0x189: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x189, 0x1c5, x86_l_1c5);
x86_l_18b:
	/* 0x18b: mov    r10b,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_8, 85ULL);
x86_l_18e:
	/* 0x18e: cmp    BYTE PTR [rdx-0x3],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649760ULL);
x86_l_192:
	/* 0x192: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x192, 0x1c5, x86_l_1c5);
x86_l_194:
	/* 0x194: mov    r9d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 3ULL);
x86_l_19a:
	/* 0x19a: mov    r8b,0x54 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 84ULL);
x86_l_19d:
	/* 0x19d: mov    r11b,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 32ULL);
x86_l_1a0:
	/* 0x1a0: jmp    1d5 <tracee_http_method_prefix_detect_xdp+0x1d5> */
	X86_SIM_X86_JMP(0x1a0, 0x1d5, x86_l_1d5);
x86_l_1a2:
	/* 0x1a2: mov    r8b,0x54 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 84ULL);
x86_l_1a5:
	/* 0x1a5: cmp    BYTE PTR [rdx-0x4],0x54 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744056529682516ULL);
x86_l_1a9:
	/* 0x1a9: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a9, 0x1c5, x86_l_1c5);
x86_l_1ab:
	/* 0x1ab: cmp    BYTE PTR [rdx-0x3],0x50 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744060824649808ULL);
x86_l_1af:
	/* 0x1af: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1af, 0x1c5, x86_l_1c5);
x86_l_1b1:
	/* 0x1b1: cmp    BYTE PTR [rdx-0x2],0x2f */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744065119617071ULL);
x86_l_1b5:
	/* 0x1b5: jne    1c5 <tracee_http_method_prefix_detect_xdp+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b5, 0x1c5, x86_l_1c5);
x86_l_1b7:
	/* 0x1b7: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1bd:
	/* 0x1bd: mov    r11b,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 80ULL);
x86_l_1c0:
	/* 0x1c0: mov    r10b,0x54 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_8, 84ULL);
x86_l_1c3:
	/* 0x1c3: jmp    1d5 <tracee_http_method_prefix_detect_xdp+0x1d5> */
	X86_SIM_X86_JMP(0x1c3, 0x1d5, x86_l_1d5);
x86_l_1c5:
	/* 0x1c5: mov    r10d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R8, X86_WIDTH_32);
x86_l_1c8:
	/* 0x1c8: movzx  r8d,BYTE PTR [rdx-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551612ULL);
x86_l_1cd:
	/* 0x1cd: movzx  r11d,BYTE PTR [rdx-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_1d2:
	/* 0x1d2: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5:
	/* 0x1d5: movzx  r11d,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d9:
	/* 0x1d9: lea    ebx,[r9+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1dd:
	/* 0x1dd: lea    r14,[rax+0xa] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1e1:
	/* 0x1e1: imul   rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_1e5:
	/* 0x1e5: add    rsi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e8:
	/* 0x1e8: shl    r11,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1ec:
	/* 0x1ec: movzx  r8d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f0:
	/* 0x1f0: shl    r8d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1f4:
	/* 0x1f4: movzx  r10d,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f8:
	/* 0x1f8: shl    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1fc:
	/* 0x1fc: shl    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1ff:
	/* 0x1ff: or     edi,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_202:
	/* 0x202: or     edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_205:
	/* 0x205: or     rdi,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_64, X86_ALU_OR);
x86_l_208:
	/* 0x208: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_20b:
	/* 0x20b: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_20e:
	/* 0x20e: shlx   rbx,r8,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RBX, X86_R8, X86_WIDTH_64, X86_RAX, X86_ALU_SHL);
x86_l_213:
	/* 0x213: xor    rbx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RSI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_216:
	/* 0x216: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_21a:
	/* 0x21a: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_21d:
	/* 0x21d: cmp    rax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 9ULL);
x86_l_221:
	/* 0x221: jne    4d <tracee_http_method_prefix_detect_xdp+0x4d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x221, 0x4d, x86_l_4d);
x86_l_227:
	/* 0x227: mov    BYTE PTR [rcx],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a:
	/* 0x22a: mov    BYTE PTR [rcx+0x1],bh */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_22d:
	/* 0x22d: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_22f:
	/* 0x22f: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_232:
	/* 0x232: mov    BYTE PTR [rcx+0x2],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_235:
	/* 0x235: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_237:
	/* 0x237: shr    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_23a:
	/* 0x23a: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_23d:
	/* 0x23d: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_244:
	/* 0x244: mov    BYTE PTR [rcx+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_247:
	/* 0x247: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: shr    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_24e:
	/* 0x24e: mov    BYTE PTR [rcx+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_251:
	/* 0x251: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_254:
	/* 0x254: shr    rax,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_258:
	/* 0x258: mov    BYTE PTR [rcx+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_25b:
	/* 0x25b: shr    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_25f:
	/* 0x25f: mov    BYTE PTR [rcx+0x7],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_262:
	/* 0x262: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_267:
	/* 0x267: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_268:
	/* 0x268: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_26a:
	/* 0x26a: jmp    26f <tracee_http_method_prefix_detect_xdp+0x26f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_26f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
