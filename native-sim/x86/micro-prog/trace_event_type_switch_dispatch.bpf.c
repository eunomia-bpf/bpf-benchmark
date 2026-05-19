#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int trace_event_type_switch_dispatch_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rcx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rsi,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rdx,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    0x16 */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    0x657 ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     0x11 */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0x20c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     0x11 */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x80 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_31:
	/* 0x31: jne    0x11 */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31, 0x11, x86_l_11);
x86_l_33:
	/* 0x33: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_34:
	/* 0x34: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_36:
	/* 0x36: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_38:
	/* 0x38: jmp    0x52 */
	X86_SIM_X86_JMP(0x38, 0x52, x86_l_52);
x86_l_3a:
	/* 0x3a: mov    ebx,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_3f:
	/* 0x3f: xor    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_42:
	/* 0x42: inc    rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_45:
	/* 0x45: cmp    rsi,0x80 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 128ULL);
x86_l_4c:
	/* 0x4c: je     0x614 */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c, 0x614, x86_l_614);
x86_l_52:
	/* 0x52: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_55:
	/* 0x55: mov    edi,DWORD PTR [rdx+rsi*4+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 12ULL);
x86_l_59:
	/* 0x59: cmp    edi,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_5c:
	/* 0x5c: jg     0x97 */
	X86_SIM_X86_JCC(X86_CC_G, 0x5c, 0x97, x86_l_97);
x86_l_5e:
	/* 0x5e: cmp    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_61:
	/* 0x61: jg     0xd3 */
	X86_SIM_X86_JCC(X86_CC_G, 0x61, 0xd3, x86_l_d3);
x86_l_63:
	/* 0x63: cmp    edi,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_66:
	/* 0x66: jg     0x13e */
	X86_SIM_X86_JCC(X86_CC_G, 0x66, 0x13e, x86_l_13e);
x86_l_6c:
	/* 0x6c: cmp    edi,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_6f:
	/* 0x6f: jg     0x1f6 */
	X86_SIM_X86_JCC(X86_CC_G, 0x6f, 0x1f6, x86_l_1f6);
x86_l_75:
	/* 0x75: cmp    edi,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_78:
	/* 0x78: jg     0x31e */
	X86_SIM_X86_JCC(X86_CC_G, 0x78, 0x31e, x86_l_31e);
x86_l_7e:
	/* 0x7e: mov    ebx,0x38 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_83:
	/* 0x83: test   edi,edi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_85:
	/* 0x85: je     0x3f */
	X86_SIM_X86_JCC(X86_CC_E, 0x85, 0x3f, x86_l_3f);
x86_l_87:
	/* 0x87: cmp    edi,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_8a:
	/* 0x8a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8a, 0x60a, x86_l_60a);
x86_l_90:
	/* 0x90: mov    ebx,0x2b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_95:
	/* 0x95: jmp    0x3f */
	X86_SIM_X86_JMP(0x95, 0x3f, x86_l_3f);
x86_l_97:
	/* 0x97: cmp    edi,0x2f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_9a:
	/* 0x9a: jg     0x10a */
	X86_SIM_X86_JCC(X86_CC_G, 0x9a, 0x10a, x86_l_10a);
x86_l_9c:
	/* 0x9c: cmp    edi,0x27 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_9f:
	/* 0x9f: jg     0x16c */
	X86_SIM_X86_JCC(X86_CC_G, 0x9f, 0x16c, x86_l_16c);
x86_l_a5:
	/* 0xa5: cmp    edi,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_a8:
	/* 0xa8: jg     0x21b */
	X86_SIM_X86_JCC(X86_CC_G, 0xa8, 0x21b, x86_l_21b);
x86_l_ae:
	/* 0xae: cmp    edi,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_b1:
	/* 0xb1: jg     0x33a */
	X86_SIM_X86_JCC(X86_CC_G, 0xb1, 0x33a, x86_l_33a);
x86_l_b7:
	/* 0xb7: cmp    edi,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_ba:
	/* 0xba: je     0x4de */
	X86_SIM_X86_JCC(X86_CC_E, 0xba, 0x4de, x86_l_4de);
x86_l_c0:
	/* 0xc0: cmp    edi,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_c3:
	/* 0xc3: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc3, 0x60a, x86_l_60a);
x86_l_c9:
	/* 0xc9: mov    ebx,0x27 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_ce:
	/* 0xce: jmp    0x3f */
	X86_SIM_X86_JMP(0xce, 0x3f, x86_l_3f);
x86_l_d3:
	/* 0xd3: cmp    edi,0x17 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_d6:
	/* 0xd6: jg     0x19a */
	X86_SIM_X86_JCC(X86_CC_G, 0xd6, 0x19a, x86_l_19a);
x86_l_dc:
	/* 0xdc: cmp    edi,0x13 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_df:
	/* 0xdf: jg     0x240 */
	X86_SIM_X86_JCC(X86_CC_G, 0xdf, 0x240, x86_l_240);
x86_l_e5:
	/* 0xe5: cmp    edi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_e8:
	/* 0xe8: jg     0x356 */
	X86_SIM_X86_JCC(X86_CC_G, 0xe8, 0x356, x86_l_356);
x86_l_ee:
	/* 0xee: cmp    edi,0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_f1:
	/* 0xf1: je     0x4e8 */
	X86_SIM_X86_JCC(X86_CC_E, 0xf1, 0x4e8, x86_l_4e8);
x86_l_f7:
	/* 0xf7: cmp    edi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_fa:
	/* 0xfa: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfa, 0x60a, x86_l_60a);
x86_l_100:
	/* 0x100: mov    ebx,0x3e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 62ULL);
x86_l_105:
	/* 0x105: jmp    0x3f */
	X86_SIM_X86_JMP(0x105, 0x3f, x86_l_3f);
x86_l_10a:
	/* 0x10a: cmp    edi,0x37 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_10d:
	/* 0x10d: jg     0x1c8 */
	X86_SIM_X86_JCC(X86_CC_G, 0x10d, 0x1c8, x86_l_1c8);
x86_l_113:
	/* 0x113: cmp    edi,0x33 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_116:
	/* 0x116: jg     0x265 */
	X86_SIM_X86_JCC(X86_CC_G, 0x116, 0x265, x86_l_265);
x86_l_11c:
	/* 0x11c: cmp    edi,0x31 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_11f:
	/* 0x11f: jg     0x372 */
	X86_SIM_X86_JCC(X86_CC_G, 0x11f, 0x372, x86_l_372);
x86_l_125:
	/* 0x125: cmp    edi,0x30 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 48ULL);
x86_l_128:
	/* 0x128: je     0x4f2 */
	X86_SIM_X86_JCC(X86_CC_E, 0x128, 0x4f2, x86_l_4f2);
x86_l_12e:
	/* 0x12e: cmp    edi,0x31 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_131:
	/* 0x131: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x131, 0x60a, x86_l_60a);
x86_l_137:
	/* 0x137: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_139:
	/* 0x139: jmp    0x3f */
	X86_SIM_X86_JMP(0x139, 0x3f, x86_l_3f);
x86_l_13e:
	/* 0x13e: cmp    edi,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_141:
	/* 0x141: jg     0x28a */
	X86_SIM_X86_JCC(X86_CC_G, 0x141, 0x28a, x86_l_28a);
x86_l_147:
	/* 0x147: cmp    edi,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_14a:
	/* 0x14a: jg     0x38e */
	X86_SIM_X86_JCC(X86_CC_G, 0x14a, 0x38e, x86_l_38e);
x86_l_150:
	/* 0x150: cmp    edi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_153:
	/* 0x153: je     0x4fc */
	X86_SIM_X86_JCC(X86_CC_E, 0x153, 0x4fc, x86_l_4fc);
x86_l_159:
	/* 0x159: cmp    edi,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_15c:
	/* 0x15c: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15c, 0x60a, x86_l_60a);
x86_l_162:
	/* 0x162: mov    ebx,0x3f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_167:
	/* 0x167: jmp    0x3f */
	X86_SIM_X86_JMP(0x167, 0x3f, x86_l_3f);
x86_l_16c:
	/* 0x16c: cmp    edi,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_16f:
	/* 0x16f: jg     0x2af */
	X86_SIM_X86_JCC(X86_CC_G, 0x16f, 0x2af, x86_l_2af);
x86_l_175:
	/* 0x175: cmp    edi,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_178:
	/* 0x178: jg     0x3aa */
	X86_SIM_X86_JCC(X86_CC_G, 0x178, 0x3aa, x86_l_3aa);
x86_l_17e:
	/* 0x17e: cmp    edi,0x28 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 40ULL);
x86_l_181:
	/* 0x181: je     0x506 */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x506, x86_l_506);
x86_l_187:
	/* 0x187: cmp    edi,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_18a:
	/* 0x18a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a, 0x60a, x86_l_60a);
x86_l_190:
	/* 0x190: mov    ebx,0x32 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 50ULL);
x86_l_195:
	/* 0x195: jmp    0x3f */
	X86_SIM_X86_JMP(0x195, 0x3f, x86_l_3f);
x86_l_19a:
	/* 0x19a: cmp    edi,0x1b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_19d:
	/* 0x19d: jg     0x2d4 */
	X86_SIM_X86_JCC(X86_CC_G, 0x19d, 0x2d4, x86_l_2d4);
x86_l_1a3:
	/* 0x1a3: cmp    edi,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1a6:
	/* 0x1a6: jg     0x3c6 */
	X86_SIM_X86_JCC(X86_CC_G, 0x1a6, 0x3c6, x86_l_3c6);
x86_l_1ac:
	/* 0x1ac: cmp    edi,0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_1af:
	/* 0x1af: je     0x510 */
	X86_SIM_X86_JCC(X86_CC_E, 0x1af, 0x510, x86_l_510);
x86_l_1b5:
	/* 0x1b5: cmp    edi,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1b8:
	/* 0x1b8: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b8, 0x60a, x86_l_60a);
x86_l_1be:
	/* 0x1be: mov    ebx,0x1a */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_1c3:
	/* 0x1c3: jmp    0x3f */
	X86_SIM_X86_JMP(0x1c3, 0x3f, x86_l_3f);
x86_l_1c8:
	/* 0x1c8: cmp    edi,0x3b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_1cb:
	/* 0x1cb: jg     0x2f9 */
	X86_SIM_X86_JCC(X86_CC_G, 0x1cb, 0x2f9, x86_l_2f9);
x86_l_1d1:
	/* 0x1d1: cmp    edi,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1d4:
	/* 0x1d4: jg     0x3e2 */
	X86_SIM_X86_JCC(X86_CC_G, 0x1d4, 0x3e2, x86_l_3e2);
x86_l_1da:
	/* 0x1da: cmp    edi,0x38 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_1dd:
	/* 0x1dd: je     0x51a */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dd, 0x51a, x86_l_51a);
x86_l_1e3:
	/* 0x1e3: cmp    edi,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1e6:
	/* 0x1e6: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e6, 0x60a, x86_l_60a);
x86_l_1ec:
	/* 0x1ec: mov    ebx,0x36 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 54ULL);
x86_l_1f1:
	/* 0x1f1: jmp    0x3f */
	X86_SIM_X86_JMP(0x1f1, 0x3f, x86_l_3f);
x86_l_1f6:
	/* 0x1f6: cmp    edi,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_1f9:
	/* 0x1f9: jg     0x3fe */
	X86_SIM_X86_JCC(X86_CC_G, 0x1f9, 0x3fe, x86_l_3fe);
x86_l_1ff:
	/* 0x1ff: cmp    edi,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_202:
	/* 0x202: je     0x524 */
	X86_SIM_X86_JCC(X86_CC_E, 0x202, 0x524, x86_l_524);
x86_l_208:
	/* 0x208: cmp    edi,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_20b:
	/* 0x20b: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20b, 0x60a, x86_l_60a);
x86_l_211:
	/* 0x211: mov    ebx,0x3d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_216:
	/* 0x216: jmp    0x3f */
	X86_SIM_X86_JMP(0x216, 0x3f, x86_l_3f);
x86_l_21b:
	/* 0x21b: cmp    edi,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_21e:
	/* 0x21e: jg     0x41a */
	X86_SIM_X86_JCC(X86_CC_G, 0x21e, 0x41a, x86_l_41a);
x86_l_224:
	/* 0x224: cmp    edi,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_227:
	/* 0x227: je     0x52e */
	X86_SIM_X86_JCC(X86_CC_E, 0x227, 0x52e, x86_l_52e);
x86_l_22d:
	/* 0x22d: cmp    edi,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_230:
	/* 0x230: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x230, 0x60a, x86_l_60a);
x86_l_236:
	/* 0x236: mov    ebx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_23b:
	/* 0x23b: jmp    0x3f */
	X86_SIM_X86_JMP(0x23b, 0x3f, x86_l_3f);
x86_l_240:
	/* 0x240: cmp    edi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_243:
	/* 0x243: jg     0x436 */
	X86_SIM_X86_JCC(X86_CC_G, 0x243, 0x436, x86_l_436);
x86_l_249:
	/* 0x249: cmp    edi,0x14 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 20ULL);
x86_l_24c:
	/* 0x24c: je     0x538 */
	X86_SIM_X86_JCC(X86_CC_E, 0x24c, 0x538, x86_l_538);
x86_l_252:
	/* 0x252: cmp    edi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_255:
	/* 0x255: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x255, 0x60a, x86_l_60a);
x86_l_25b:
	/* 0x25b: mov    ebx,0x15 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_260:
	/* 0x260: jmp    0x3f */
	X86_SIM_X86_JMP(0x260, 0x3f, x86_l_3f);
x86_l_265:
	/* 0x265: cmp    edi,0x35 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_268:
	/* 0x268: jg     0x452 */
	X86_SIM_X86_JCC(X86_CC_G, 0x268, 0x452, x86_l_452);
x86_l_26e:
	/* 0x26e: cmp    edi,0x34 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 52ULL);
x86_l_271:
	/* 0x271: je     0x542 */
	X86_SIM_X86_JCC(X86_CC_E, 0x271, 0x542, x86_l_542);
x86_l_277:
	/* 0x277: cmp    edi,0x35 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_27a:
	/* 0x27a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x27a, 0x60a, x86_l_60a);
x86_l_280:
	/* 0x280: mov    ebx,0x14 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 20ULL);
x86_l_285:
	/* 0x285: jmp    0x3f */
	X86_SIM_X86_JMP(0x285, 0x3f, x86_l_3f);
x86_l_28a:
	/* 0x28a: cmp    edi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_28d:
	/* 0x28d: jg     0x46e */
	X86_SIM_X86_JCC(X86_CC_G, 0x28d, 0x46e, x86_l_46e);
x86_l_293:
	/* 0x293: cmp    edi,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_296:
	/* 0x296: je     0x54c */
	X86_SIM_X86_JCC(X86_CC_E, 0x296, 0x54c, x86_l_54c);
x86_l_29c:
	/* 0x29c: cmp    edi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_29f:
	/* 0x29f: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29f, 0x60a, x86_l_60a);
x86_l_2a5:
	/* 0x2a5: mov    ebx,0x2a */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 42ULL);
x86_l_2aa:
	/* 0x2aa: jmp    0x3f */
	X86_SIM_X86_JMP(0x2aa, 0x3f, x86_l_3f);
x86_l_2af:
	/* 0x2af: cmp    edi,0x2d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_2b2:
	/* 0x2b2: jg     0x48a */
	X86_SIM_X86_JCC(X86_CC_G, 0x2b2, 0x48a, x86_l_48a);
x86_l_2b8:
	/* 0x2b8: cmp    edi,0x2c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_2bb:
	/* 0x2bb: je     0x556 */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bb, 0x556, x86_l_556);
x86_l_2c1:
	/* 0x2c1: cmp    edi,0x2d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_2c4:
	/* 0x2c4: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c4, 0x60a, x86_l_60a);
x86_l_2ca:
	/* 0x2ca: mov    ebx,0x2c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_2cf:
	/* 0x2cf: jmp    0x3f */
	X86_SIM_X86_JMP(0x2cf, 0x3f, x86_l_3f);
x86_l_2d4:
	/* 0x2d4: cmp    edi,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_2d7:
	/* 0x2d7: jg     0x4a6 */
	X86_SIM_X86_JCC(X86_CC_G, 0x2d7, 0x4a6, x86_l_4a6);
x86_l_2dd:
	/* 0x2dd: cmp    edi,0x1c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 28ULL);
x86_l_2e0:
	/* 0x2e0: je     0x560 */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e0, 0x560, x86_l_560);
x86_l_2e6:
	/* 0x2e6: cmp    edi,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_2e9:
	/* 0x2e9: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e9, 0x60a, x86_l_60a);
x86_l_2ef:
	/* 0x2ef: mov    ebx,0x1f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_2f4:
	/* 0x2f4: jmp    0x3f */
	X86_SIM_X86_JMP(0x2f4, 0x3f, x86_l_3f);
x86_l_2f9:
	/* 0x2f9: cmp    edi,0x3d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_2fc:
	/* 0x2fc: jg     0x4c2 */
	X86_SIM_X86_JCC(X86_CC_G, 0x2fc, 0x4c2, x86_l_4c2);
x86_l_302:
	/* 0x302: cmp    edi,0x3c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_305:
	/* 0x305: je     0x56a */
	X86_SIM_X86_JCC(X86_CC_E, 0x305, 0x56a, x86_l_56a);
x86_l_30b:
	/* 0x30b: cmp    edi,0x3d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_30e:
	/* 0x30e: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30e, 0x60a, x86_l_60a);
x86_l_314:
	/* 0x314: mov    ebx,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_319:
	/* 0x319: jmp    0x3f */
	X86_SIM_X86_JMP(0x319, 0x3f, x86_l_3f);
x86_l_31e:
	/* 0x31e: cmp    edi,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_321:
	/* 0x321: je     0x574 */
	X86_SIM_X86_JCC(X86_CC_E, 0x321, 0x574, x86_l_574);
x86_l_327:
	/* 0x327: cmp    edi,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_32a:
	/* 0x32a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x32a, 0x60a, x86_l_60a);
x86_l_330:
	/* 0x330: mov    ebx,0x1c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 28ULL);
x86_l_335:
	/* 0x335: jmp    0x3f */
	X86_SIM_X86_JMP(0x335, 0x3f, x86_l_3f);
x86_l_33a:
	/* 0x33a: cmp    edi,0x22 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_33d:
	/* 0x33d: je     0x57e */
	X86_SIM_X86_JCC(X86_CC_E, 0x33d, 0x57e, x86_l_57e);
x86_l_343:
	/* 0x343: cmp    edi,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_346:
	/* 0x346: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x346, 0x60a, x86_l_60a);
x86_l_34c:
	/* 0x34c: mov    ebx,0x1b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_351:
	/* 0x351: jmp    0x3f */
	X86_SIM_X86_JMP(0x351, 0x3f, x86_l_3f);
x86_l_356:
	/* 0x356: cmp    edi,0x12 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 18ULL);
x86_l_359:
	/* 0x359: je     0x588 */
	X86_SIM_X86_JCC(X86_CC_E, 0x359, 0x588, x86_l_588);
x86_l_35f:
	/* 0x35f: cmp    edi,0x13 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_362:
	/* 0x362: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x362, 0x60a, x86_l_60a);
x86_l_368:
	/* 0x368: mov    ebx,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_36d:
	/* 0x36d: jmp    0x3f */
	X86_SIM_X86_JMP(0x36d, 0x3f, x86_l_3f);
x86_l_372:
	/* 0x372: cmp    edi,0x32 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 50ULL);
x86_l_375:
	/* 0x375: je     0x592 */
	X86_SIM_X86_JCC(X86_CC_E, 0x375, 0x592, x86_l_592);
x86_l_37b:
	/* 0x37b: cmp    edi,0x33 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_37e:
	/* 0x37e: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37e, 0x60a, x86_l_60a);
x86_l_384:
	/* 0x384: mov    ebx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_389:
	/* 0x389: jmp    0x3f */
	X86_SIM_X86_JMP(0x389, 0x3f, x86_l_3f);
x86_l_38e:
	/* 0x38e: cmp    edi,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_391:
	/* 0x391: je     0x59c */
	X86_SIM_X86_JCC(X86_CC_E, 0x391, 0x59c, x86_l_59c);
x86_l_397:
	/* 0x397: cmp    edi,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_39a:
	/* 0x39a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x39a, 0x60a, x86_l_60a);
x86_l_3a0:
	/* 0x3a0: mov    ebx,0x24 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_3a5:
	/* 0x3a5: jmp    0x3f */
	X86_SIM_X86_JMP(0x3a5, 0x3f, x86_l_3f);
x86_l_3aa:
	/* 0x3aa: cmp    edi,0x2a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 42ULL);
x86_l_3ad:
	/* 0x3ad: je     0x5a6 */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ad, 0x5a6, x86_l_5a6);
x86_l_3b3:
	/* 0x3b3: cmp    edi,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_3b6:
	/* 0x3b6: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b6, 0x60a, x86_l_60a);
x86_l_3bc:
	/* 0x3bc: mov    ebx,0x23 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_3c1:
	/* 0x3c1: jmp    0x3f */
	X86_SIM_X86_JMP(0x3c1, 0x3f, x86_l_3f);
x86_l_3c6:
	/* 0x3c6: cmp    edi,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_3c9:
	/* 0x3c9: je     0x5b0 */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c9, 0x5b0, x86_l_5b0);
x86_l_3cf:
	/* 0x3cf: cmp    edi,0x1b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_3d2:
	/* 0x3d2: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3d2, 0x60a, x86_l_60a);
x86_l_3d8:
	/* 0x3d8: mov    ebx,0x29 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_3dd:
	/* 0x3dd: jmp    0x3f */
	X86_SIM_X86_JMP(0x3dd, 0x3f, x86_l_3f);
x86_l_3e2:
	/* 0x3e2: cmp    edi,0x3a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_3e5:
	/* 0x3e5: je     0x5ba */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e5, 0x5ba, x86_l_5ba);
x86_l_3eb:
	/* 0x3eb: cmp    edi,0x3b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_3ee:
	/* 0x3ee: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ee, 0x60a, x86_l_60a);
x86_l_3f4:
	/* 0x3f4: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3f9:
	/* 0x3f9: jmp    0x3f */
	X86_SIM_X86_JMP(0x3f9, 0x3f, x86_l_3f);
x86_l_3fe:
	/* 0x3fe: cmp    edi,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_401:
	/* 0x401: je     0x5c4 */
	X86_SIM_X86_JCC(X86_CC_E, 0x401, 0x5c4, x86_l_5c4);
x86_l_407:
	/* 0x407: cmp    edi,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_40a:
	/* 0x40a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40a, 0x60a, x86_l_60a);
x86_l_410:
	/* 0x410: mov    ebx,0x3a */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_415:
	/* 0x415: jmp    0x3f */
	X86_SIM_X86_JMP(0x415, 0x3f, x86_l_3f);
x86_l_41a:
	/* 0x41a: cmp    edi,0x26 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_41d:
	/* 0x41d: je     0x5ce */
	X86_SIM_X86_JCC(X86_CC_E, 0x41d, 0x5ce, x86_l_5ce);
x86_l_423:
	/* 0x423: cmp    edi,0x27 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_426:
	/* 0x426: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x426, 0x60a, x86_l_60a);
x86_l_42c:
	/* 0x42c: mov    ebx,0x30 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 48ULL);
x86_l_431:
	/* 0x431: jmp    0x3f */
	X86_SIM_X86_JMP(0x431, 0x3f, x86_l_3f);
x86_l_436:
	/* 0x436: cmp    edi,0x16 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 22ULL);
x86_l_439:
	/* 0x439: je     0x5d8 */
	X86_SIM_X86_JCC(X86_CC_E, 0x439, 0x5d8, x86_l_5d8);
x86_l_43f:
	/* 0x43f: cmp    edi,0x17 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_442:
	/* 0x442: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x442, 0x60a, x86_l_60a);
x86_l_448:
	/* 0x448: mov    ebx,0x28 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 40ULL);
x86_l_44d:
	/* 0x44d: jmp    0x3f */
	X86_SIM_X86_JMP(0x44d, 0x3f, x86_l_3f);
x86_l_452:
	/* 0x452: cmp    edi,0x36 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 54ULL);
x86_l_455:
	/* 0x455: je     0x5e2 */
	X86_SIM_X86_JCC(X86_CC_E, 0x455, 0x5e2, x86_l_5e2);
x86_l_45b:
	/* 0x45b: cmp    edi,0x37 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_45e:
	/* 0x45e: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45e, 0x60a, x86_l_60a);
x86_l_464:
	/* 0x464: mov    ebx,0x12 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 18ULL);
x86_l_469:
	/* 0x469: jmp    0x3f */
	X86_SIM_X86_JMP(0x469, 0x3f, x86_l_3f);
x86_l_46e:
	/* 0x46e: cmp    edi,0xe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_471:
	/* 0x471: je     0x5ec */
	X86_SIM_X86_JCC(X86_CC_E, 0x471, 0x5ec, x86_l_5ec);
x86_l_477:
	/* 0x477: cmp    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_47a:
	/* 0x47a: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47a, 0x60a, x86_l_60a);
x86_l_480:
	/* 0x480: mov    ebx,0x2e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 46ULL);
x86_l_485:
	/* 0x485: jmp    0x3f */
	X86_SIM_X86_JMP(0x485, 0x3f, x86_l_3f);
x86_l_48a:
	/* 0x48a: cmp    edi,0x2e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 46ULL);
x86_l_48d:
	/* 0x48d: je     0x5f6 */
	X86_SIM_X86_JCC(X86_CC_E, 0x48d, 0x5f6, x86_l_5f6);
x86_l_493:
	/* 0x493: cmp    edi,0x2f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_496:
	/* 0x496: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x496, 0x60a, x86_l_60a);
x86_l_49c:
	/* 0x49c: mov    ebx,0x3b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_4a1:
	/* 0x4a1: jmp    0x3f */
	X86_SIM_X86_JMP(0x4a1, 0x3f, x86_l_3f);
x86_l_4a6:
	/* 0x4a6: cmp    edi,0x1e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_4a9:
	/* 0x4a9: je     0x600 */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a9, 0x600, x86_l_600);
x86_l_4af:
	/* 0x4af: cmp    edi,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_4b2:
	/* 0x4b2: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b2, 0x60a, x86_l_60a);
x86_l_4b8:
	/* 0x4b8: mov    ebx,0x34 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 52ULL);
x86_l_4bd:
	/* 0x4bd: jmp    0x3f */
	X86_SIM_X86_JMP(0x4bd, 0x3f, x86_l_3f);
x86_l_4c2:
	/* 0x4c2: cmp    edi,0x3e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 62ULL);
x86_l_4c5:
	/* 0x4c5: je     0x3a */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c5, 0x3a, x86_l_3a);
x86_l_4cb:
	/* 0x4cb: cmp    edi,0x3f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_4ce:
	/* 0x4ce: jne    0x60a */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ce, 0x60a, x86_l_60a);
x86_l_4d4:
	/* 0x4d4: mov    ebx,0x37 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_4d9:
	/* 0x4d9: jmp    0x3f */
	X86_SIM_X86_JMP(0x4d9, 0x3f, x86_l_3f);
x86_l_4de:
	/* 0x4de: mov    ebx,0x19 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_4e3:
	/* 0x4e3: jmp    0x3f */
	X86_SIM_X86_JMP(0x4e3, 0x3f, x86_l_3f);
x86_l_4e8:
	/* 0x4e8: mov    ebx,0x22 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_4ed:
	/* 0x4ed: jmp    0x3f */
	X86_SIM_X86_JMP(0x4ed, 0x3f, x86_l_3f);
x86_l_4f2:
	/* 0x4f2: mov    ebx,0x2d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_4f7:
	/* 0x4f7: jmp    0x3f */
	X86_SIM_X86_JMP(0x4f7, 0x3f, x86_l_3f);
x86_l_4fc:
	/* 0x4fc: mov    ebx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_501:
	/* 0x501: jmp    0x3f */
	X86_SIM_X86_JMP(0x501, 0x3f, x86_l_3f);
x86_l_506:
	/* 0x506: mov    ebx,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_50b:
	/* 0x50b: jmp    0x3f */
	X86_SIM_X86_JMP(0x50b, 0x3f, x86_l_3f);
x86_l_510:
	/* 0x510: mov    ebx,0x26 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_515:
	/* 0x515: jmp    0x3f */
	X86_SIM_X86_JMP(0x515, 0x3f, x86_l_3f);
x86_l_51a:
	/* 0x51a: mov    ebx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_51f:
	/* 0x51f: jmp    0x3f */
	X86_SIM_X86_JMP(0x51f, 0x3f, x86_l_3f);
x86_l_524:
	/* 0x524: mov    ebx,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_529:
	/* 0x529: jmp    0x3f */
	X86_SIM_X86_JMP(0x529, 0x3f, x86_l_3f);
x86_l_52e:
	/* 0x52e: mov    ebx,0x35 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_533:
	/* 0x533: jmp    0x3f */
	X86_SIM_X86_JMP(0x533, 0x3f, x86_l_3f);
x86_l_538:
	/* 0x538: mov    ebx,0x1d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_53d:
	/* 0x53d: jmp    0x3f */
	X86_SIM_X86_JMP(0x53d, 0x3f, x86_l_3f);
x86_l_542:
	/* 0x542: mov    ebx,0xd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_547:
	/* 0x547: jmp    0x3f */
	X86_SIM_X86_JMP(0x547, 0x3f, x86_l_3f);
x86_l_54c:
	/* 0x54c: mov    ebx,0x13 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_551:
	/* 0x551: jmp    0x3f */
	X86_SIM_X86_JMP(0x551, 0x3f, x86_l_3f);
x86_l_556:
	/* 0x556: mov    ebx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_55b:
	/* 0x55b: jmp    0x3f */
	X86_SIM_X86_JMP(0x55b, 0x3f, x86_l_3f);
x86_l_560:
	/* 0x560: mov    ebx,0x21 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_565:
	/* 0x565: jmp    0x3f */
	X86_SIM_X86_JMP(0x565, 0x3f, x86_l_3f);
x86_l_56a:
	/* 0x56a: mov    ebx,0x3c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_56f:
	/* 0x56f: jmp    0x3f */
	X86_SIM_X86_JMP(0x56f, 0x3f, x86_l_3f);
x86_l_574:
	/* 0x574: mov    ebx,0x39 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_579:
	/* 0x579: jmp    0x3f */
	X86_SIM_X86_JMP(0x579, 0x3f, x86_l_3f);
x86_l_57e:
	/* 0x57e: mov    ebx,0xb */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_583:
	/* 0x583: jmp    0x3f */
	X86_SIM_X86_JMP(0x583, 0x3f, x86_l_3f);
x86_l_588:
	/* 0x588: mov    ebx,0x2f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_58d:
	/* 0x58d: jmp    0x3f */
	X86_SIM_X86_JMP(0x58d, 0x3f, x86_l_3f);
x86_l_592:
	/* 0x592: mov    ebx,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_597:
	/* 0x597: jmp    0x3f */
	X86_SIM_X86_JMP(0x597, 0x3f, x86_l_3f);
x86_l_59c:
	/* 0x59c: mov    ebx,0x31 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_5a1:
	/* 0x5a1: jmp    0x3f */
	X86_SIM_X86_JMP(0x5a1, 0x3f, x86_l_3f);
x86_l_5a6:
	/* 0x5a6: mov    ebx,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_5ab:
	/* 0x5ab: jmp    0x3f */
	X86_SIM_X86_JMP(0x5ab, 0x3f, x86_l_3f);
x86_l_5b0:
	/* 0x5b0: mov    ebx,0x11 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_5b5:
	/* 0x5b5: jmp    0x3f */
	X86_SIM_X86_JMP(0x5b5, 0x3f, x86_l_3f);
x86_l_5ba:
	/* 0x5ba: mov    ebx,0x16 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 22ULL);
x86_l_5bf:
	/* 0x5bf: jmp    0x3f */
	X86_SIM_X86_JMP(0x5bf, 0x3f, x86_l_3f);
x86_l_5c4:
	/* 0x5c4: mov    ebx,0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_5c9:
	/* 0x5c9: jmp    0x3f */
	X86_SIM_X86_JMP(0x5c9, 0x3f, x86_l_3f);
x86_l_5ce:
	/* 0x5ce: mov    ebx,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_5d3:
	/* 0x5d3: jmp    0x3f */
	X86_SIM_X86_JMP(0x5d3, 0x3f, x86_l_3f);
x86_l_5d8:
	/* 0x5d8: mov    ebx,0xf */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_5dd:
	/* 0x5dd: jmp    0x3f */
	X86_SIM_X86_JMP(0x5dd, 0x3f, x86_l_3f);
x86_l_5e2:
	/* 0x5e2: mov    ebx,0x1e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_5e7:
	/* 0x5e7: jmp    0x3f */
	X86_SIM_X86_JMP(0x5e7, 0x3f, x86_l_3f);
x86_l_5ec:
	/* 0x5ec: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_5f1:
	/* 0x5f1: jmp    0x3f */
	X86_SIM_X86_JMP(0x5f1, 0x3f, x86_l_3f);
x86_l_5f6:
	/* 0x5f6: mov    ebx,0x33 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_5fb:
	/* 0x5fb: jmp    0x3f */
	X86_SIM_X86_JMP(0x5fb, 0x3f, x86_l_3f);
x86_l_600:
	/* 0x600: mov    ebx,0x17 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_605:
	/* 0x605: jmp    0x3f */
	X86_SIM_X86_JMP(0x605, 0x3f, x86_l_3f);
x86_l_60a:
	/* 0x60a: mov    ebx,0x1bf52 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 114514ULL);
x86_l_60f:
	/* 0x60f: jmp    0x3f */
	X86_SIM_X86_JMP(0x60f, 0x3f, x86_l_3f);
x86_l_614:
	/* 0x614: mov    BYTE PTR [rcx],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_616:
	/* 0x616: mov    BYTE PTR [rcx+0x1],bh */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_619:
	/* 0x619: shr    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_61c:
	/* 0x61c: mov    BYTE PTR [rcx+0x2],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_61f:
	/* 0x61f: mov    edx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_621:
	/* 0x621: shr    edx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_624:
	/* 0x624: mov    BYTE PTR [rcx+0x3],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_627:
	/* 0x627: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_62a:
	/* 0x62a: shr    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_62e:
	/* 0x62e: mov    BYTE PTR [rcx+0x4],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_631:
	/* 0x631: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_634:
	/* 0x634: shr    rdx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_638:
	/* 0x638: mov    BYTE PTR [rcx+0x5],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_63b:
	/* 0x63b: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_63e:
	/* 0x63e: shr    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_642:
	/* 0x642: mov    BYTE PTR [rcx+0x6],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_645:
	/* 0x645: shr    rax,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_649:
	/* 0x649: mov    BYTE PTR [rcx+0x7],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_64c:
	/* 0x64c: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_651:
	/* 0x651: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_652:
	/* 0x652: jmp    0x657 ; native-link entry RET */
	X86_SIM_X86_RET();
	__builtin_unreachable();
}

X86_SIM_LICENSE();
