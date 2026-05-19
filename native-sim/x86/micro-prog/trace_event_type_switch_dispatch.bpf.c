#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_bpf.h"

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
	/* 0x11: jmp    0x65c ; native-link entry RET */
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
	/* 0x33: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_34:
	/* 0x34: mov    rbp,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_37:
	/* 0x37: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_38:
	/* 0x38: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3a:
	/* 0x3a: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_3c:
	/* 0x3c: jmp    0x56 */
	X86_SIM_X86_JMP(0x3c, 0x56, x86_l_56);
x86_l_3e:
	/* 0x3e: mov    ebx,0xc */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_43:
	/* 0x43: xor    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_46:
	/* 0x46: inc    rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_49:
	/* 0x49: cmp    rsi,0x80 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 128ULL);
x86_l_50:
	/* 0x50: je     0x618 */
	X86_SIM_X86_JCC(X86_CC_E, 0x50, 0x618, x86_l_618);
x86_l_56:
	/* 0x56: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_59:
	/* 0x59: mov    edi,DWORD PTR [rdx+rsi*4+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 12ULL);
x86_l_5d:
	/* 0x5d: cmp    edi,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_60:
	/* 0x60: jg     0x9b */
	X86_SIM_X86_JCC(X86_CC_G, 0x60, 0x9b, x86_l_9b);
x86_l_62:
	/* 0x62: cmp    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_65:
	/* 0x65: jg     0xd7 */
	X86_SIM_X86_JCC(X86_CC_G, 0x65, 0xd7, x86_l_d7);
x86_l_67:
	/* 0x67: cmp    edi,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_6a:
	/* 0x6a: jg     0x142 */
	X86_SIM_X86_JCC(X86_CC_G, 0x6a, 0x142, x86_l_142);
x86_l_70:
	/* 0x70: cmp    edi,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_73:
	/* 0x73: jg     0x1fa */
	X86_SIM_X86_JCC(X86_CC_G, 0x73, 0x1fa, x86_l_1fa);
x86_l_79:
	/* 0x79: cmp    edi,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_7c:
	/* 0x7c: jg     0x322 */
	X86_SIM_X86_JCC(X86_CC_G, 0x7c, 0x322, x86_l_322);
x86_l_82:
	/* 0x82: mov    ebx,0x38 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_87:
	/* 0x87: test   edi,edi */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_89:
	/* 0x89: je     0x43 */
	X86_SIM_X86_JCC(X86_CC_E, 0x89, 0x43, x86_l_43);
x86_l_8b:
	/* 0x8b: cmp    edi,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_8e:
	/* 0x8e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e, 0x60e, x86_l_60e);
x86_l_94:
	/* 0x94: mov    ebx,0x2b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_99:
	/* 0x99: jmp    0x43 */
	X86_SIM_X86_JMP(0x99, 0x43, x86_l_43);
x86_l_9b:
	/* 0x9b: cmp    edi,0x2f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_9e:
	/* 0x9e: jg     0x10e */
	X86_SIM_X86_JCC(X86_CC_G, 0x9e, 0x10e, x86_l_10e);
x86_l_a0:
	/* 0xa0: cmp    edi,0x27 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_a3:
	/* 0xa3: jg     0x170 */
	X86_SIM_X86_JCC(X86_CC_G, 0xa3, 0x170, x86_l_170);
x86_l_a9:
	/* 0xa9: cmp    edi,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_ac:
	/* 0xac: jg     0x21f */
	X86_SIM_X86_JCC(X86_CC_G, 0xac, 0x21f, x86_l_21f);
x86_l_b2:
	/* 0xb2: cmp    edi,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_b5:
	/* 0xb5: jg     0x33e */
	X86_SIM_X86_JCC(X86_CC_G, 0xb5, 0x33e, x86_l_33e);
x86_l_bb:
	/* 0xbb: cmp    edi,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_be:
	/* 0xbe: je     0x4e2 */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe, 0x4e2, x86_l_4e2);
x86_l_c4:
	/* 0xc4: cmp    edi,0x21 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_c7:
	/* 0xc7: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc7, 0x60e, x86_l_60e);
x86_l_cd:
	/* 0xcd: mov    ebx,0x27 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_d2:
	/* 0xd2: jmp    0x43 */
	X86_SIM_X86_JMP(0xd2, 0x43, x86_l_43);
x86_l_d7:
	/* 0xd7: cmp    edi,0x17 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_da:
	/* 0xda: jg     0x19e */
	X86_SIM_X86_JCC(X86_CC_G, 0xda, 0x19e, x86_l_19e);
x86_l_e0:
	/* 0xe0: cmp    edi,0x13 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_e3:
	/* 0xe3: jg     0x244 */
	X86_SIM_X86_JCC(X86_CC_G, 0xe3, 0x244, x86_l_244);
x86_l_e9:
	/* 0xe9: cmp    edi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_ec:
	/* 0xec: jg     0x35a */
	X86_SIM_X86_JCC(X86_CC_G, 0xec, 0x35a, x86_l_35a);
x86_l_f2:
	/* 0xf2: cmp    edi,0x10 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_f5:
	/* 0xf5: je     0x4ec */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5, 0x4ec, x86_l_4ec);
x86_l_fb:
	/* 0xfb: cmp    edi,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_fe:
	/* 0xfe: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfe, 0x60e, x86_l_60e);
x86_l_104:
	/* 0x104: mov    ebx,0x3e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 62ULL);
x86_l_109:
	/* 0x109: jmp    0x43 */
	X86_SIM_X86_JMP(0x109, 0x43, x86_l_43);
x86_l_10e:
	/* 0x10e: cmp    edi,0x37 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_111:
	/* 0x111: jg     0x1cc */
	X86_SIM_X86_JCC(X86_CC_G, 0x111, 0x1cc, x86_l_1cc);
x86_l_117:
	/* 0x117: cmp    edi,0x33 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_11a:
	/* 0x11a: jg     0x269 */
	X86_SIM_X86_JCC(X86_CC_G, 0x11a, 0x269, x86_l_269);
x86_l_120:
	/* 0x120: cmp    edi,0x31 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_123:
	/* 0x123: jg     0x376 */
	X86_SIM_X86_JCC(X86_CC_G, 0x123, 0x376, x86_l_376);
x86_l_129:
	/* 0x129: cmp    edi,0x30 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 48ULL);
x86_l_12c:
	/* 0x12c: je     0x4f6 */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c, 0x4f6, x86_l_4f6);
x86_l_132:
	/* 0x132: cmp    edi,0x31 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_135:
	/* 0x135: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x135, 0x60e, x86_l_60e);
x86_l_13b:
	/* 0x13b: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_13d:
	/* 0x13d: jmp    0x43 */
	X86_SIM_X86_JMP(0x13d, 0x43, x86_l_43);
x86_l_142:
	/* 0x142: cmp    edi,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_145:
	/* 0x145: jg     0x28e */
	X86_SIM_X86_JCC(X86_CC_G, 0x145, 0x28e, x86_l_28e);
x86_l_14b:
	/* 0x14b: cmp    edi,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_14e:
	/* 0x14e: jg     0x392 */
	X86_SIM_X86_JCC(X86_CC_G, 0x14e, 0x392, x86_l_392);
x86_l_154:
	/* 0x154: cmp    edi,0x8 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_157:
	/* 0x157: je     0x500 */
	X86_SIM_X86_JCC(X86_CC_E, 0x157, 0x500, x86_l_500);
x86_l_15d:
	/* 0x15d: cmp    edi,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_160:
	/* 0x160: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x160, 0x60e, x86_l_60e);
x86_l_166:
	/* 0x166: mov    ebx,0x3f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_16b:
	/* 0x16b: jmp    0x43 */
	X86_SIM_X86_JMP(0x16b, 0x43, x86_l_43);
x86_l_170:
	/* 0x170: cmp    edi,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_173:
	/* 0x173: jg     0x2b3 */
	X86_SIM_X86_JCC(X86_CC_G, 0x173, 0x2b3, x86_l_2b3);
x86_l_179:
	/* 0x179: cmp    edi,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_17c:
	/* 0x17c: jg     0x3ae */
	X86_SIM_X86_JCC(X86_CC_G, 0x17c, 0x3ae, x86_l_3ae);
x86_l_182:
	/* 0x182: cmp    edi,0x28 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 40ULL);
x86_l_185:
	/* 0x185: je     0x50a */
	X86_SIM_X86_JCC(X86_CC_E, 0x185, 0x50a, x86_l_50a);
x86_l_18b:
	/* 0x18b: cmp    edi,0x29 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_18e:
	/* 0x18e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18e, 0x60e, x86_l_60e);
x86_l_194:
	/* 0x194: mov    ebx,0x32 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 50ULL);
x86_l_199:
	/* 0x199: jmp    0x43 */
	X86_SIM_X86_JMP(0x199, 0x43, x86_l_43);
x86_l_19e:
	/* 0x19e: cmp    edi,0x1b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_1a1:
	/* 0x1a1: jg     0x2d8 */
	X86_SIM_X86_JCC(X86_CC_G, 0x1a1, 0x2d8, x86_l_2d8);
x86_l_1a7:
	/* 0x1a7: cmp    edi,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1aa:
	/* 0x1aa: jg     0x3ca */
	X86_SIM_X86_JCC(X86_CC_G, 0x1aa, 0x3ca, x86_l_3ca);
x86_l_1b0:
	/* 0x1b0: cmp    edi,0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_1b3:
	/* 0x1b3: je     0x514 */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b3, 0x514, x86_l_514);
x86_l_1b9:
	/* 0x1b9: cmp    edi,0x19 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_1bc:
	/* 0x1bc: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bc, 0x60e, x86_l_60e);
x86_l_1c2:
	/* 0x1c2: mov    ebx,0x1a */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_1c7:
	/* 0x1c7: jmp    0x43 */
	X86_SIM_X86_JMP(0x1c7, 0x43, x86_l_43);
x86_l_1cc:
	/* 0x1cc: cmp    edi,0x3b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_1cf:
	/* 0x1cf: jg     0x2fd */
	X86_SIM_X86_JCC(X86_CC_G, 0x1cf, 0x2fd, x86_l_2fd);
x86_l_1d5:
	/* 0x1d5: cmp    edi,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1d8:
	/* 0x1d8: jg     0x3e6 */
	X86_SIM_X86_JCC(X86_CC_G, 0x1d8, 0x3e6, x86_l_3e6);
x86_l_1de:
	/* 0x1de: cmp    edi,0x38 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_1e1:
	/* 0x1e1: je     0x51e */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1, 0x51e, x86_l_51e);
x86_l_1e7:
	/* 0x1e7: cmp    edi,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_1ea:
	/* 0x1ea: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ea, 0x60e, x86_l_60e);
x86_l_1f0:
	/* 0x1f0: mov    ebx,0x36 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 54ULL);
x86_l_1f5:
	/* 0x1f5: jmp    0x43 */
	X86_SIM_X86_JMP(0x1f5, 0x43, x86_l_43);
x86_l_1fa:
	/* 0x1fa: cmp    edi,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_1fd:
	/* 0x1fd: jg     0x402 */
	X86_SIM_X86_JCC(X86_CC_G, 0x1fd, 0x402, x86_l_402);
x86_l_203:
	/* 0x203: cmp    edi,0x4 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_206:
	/* 0x206: je     0x528 */
	X86_SIM_X86_JCC(X86_CC_E, 0x206, 0x528, x86_l_528);
x86_l_20c:
	/* 0x20c: cmp    edi,0x5 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_20f:
	/* 0x20f: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20f, 0x60e, x86_l_60e);
x86_l_215:
	/* 0x215: mov    ebx,0x3d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_21a:
	/* 0x21a: jmp    0x43 */
	X86_SIM_X86_JMP(0x21a, 0x43, x86_l_43);
x86_l_21f:
	/* 0x21f: cmp    edi,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_222:
	/* 0x222: jg     0x41e */
	X86_SIM_X86_JCC(X86_CC_G, 0x222, 0x41e, x86_l_41e);
x86_l_228:
	/* 0x228: cmp    edi,0x24 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_22b:
	/* 0x22b: je     0x532 */
	X86_SIM_X86_JCC(X86_CC_E, 0x22b, 0x532, x86_l_532);
x86_l_231:
	/* 0x231: cmp    edi,0x25 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_234:
	/* 0x234: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x234, 0x60e, x86_l_60e);
x86_l_23a:
	/* 0x23a: mov    ebx,0x4 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 4ULL);
x86_l_23f:
	/* 0x23f: jmp    0x43 */
	X86_SIM_X86_JMP(0x23f, 0x43, x86_l_43);
x86_l_244:
	/* 0x244: cmp    edi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_247:
	/* 0x247: jg     0x43a */
	X86_SIM_X86_JCC(X86_CC_G, 0x247, 0x43a, x86_l_43a);
x86_l_24d:
	/* 0x24d: cmp    edi,0x14 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 20ULL);
x86_l_250:
	/* 0x250: je     0x53c */
	X86_SIM_X86_JCC(X86_CC_E, 0x250, 0x53c, x86_l_53c);
x86_l_256:
	/* 0x256: cmp    edi,0x15 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_259:
	/* 0x259: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x259, 0x60e, x86_l_60e);
x86_l_25f:
	/* 0x25f: mov    ebx,0x15 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 21ULL);
x86_l_264:
	/* 0x264: jmp    0x43 */
	X86_SIM_X86_JMP(0x264, 0x43, x86_l_43);
x86_l_269:
	/* 0x269: cmp    edi,0x35 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_26c:
	/* 0x26c: jg     0x456 */
	X86_SIM_X86_JCC(X86_CC_G, 0x26c, 0x456, x86_l_456);
x86_l_272:
	/* 0x272: cmp    edi,0x34 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 52ULL);
x86_l_275:
	/* 0x275: je     0x546 */
	X86_SIM_X86_JCC(X86_CC_E, 0x275, 0x546, x86_l_546);
x86_l_27b:
	/* 0x27b: cmp    edi,0x35 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_27e:
	/* 0x27e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x27e, 0x60e, x86_l_60e);
x86_l_284:
	/* 0x284: mov    ebx,0x14 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 20ULL);
x86_l_289:
	/* 0x289: jmp    0x43 */
	X86_SIM_X86_JMP(0x289, 0x43, x86_l_43);
x86_l_28e:
	/* 0x28e: cmp    edi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_291:
	/* 0x291: jg     0x472 */
	X86_SIM_X86_JCC(X86_CC_G, 0x291, 0x472, x86_l_472);
x86_l_297:
	/* 0x297: cmp    edi,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_29a:
	/* 0x29a: je     0x550 */
	X86_SIM_X86_JCC(X86_CC_E, 0x29a, 0x550, x86_l_550);
x86_l_2a0:
	/* 0x2a0: cmp    edi,0xd */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_2a3:
	/* 0x2a3: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a3, 0x60e, x86_l_60e);
x86_l_2a9:
	/* 0x2a9: mov    ebx,0x2a */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 42ULL);
x86_l_2ae:
	/* 0x2ae: jmp    0x43 */
	X86_SIM_X86_JMP(0x2ae, 0x43, x86_l_43);
x86_l_2b3:
	/* 0x2b3: cmp    edi,0x2d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_2b6:
	/* 0x2b6: jg     0x48e */
	X86_SIM_X86_JCC(X86_CC_G, 0x2b6, 0x48e, x86_l_48e);
x86_l_2bc:
	/* 0x2bc: cmp    edi,0x2c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_2bf:
	/* 0x2bf: je     0x55a */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bf, 0x55a, x86_l_55a);
x86_l_2c5:
	/* 0x2c5: cmp    edi,0x2d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_2c8:
	/* 0x2c8: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c8, 0x60e, x86_l_60e);
x86_l_2ce:
	/* 0x2ce: mov    ebx,0x2c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 44ULL);
x86_l_2d3:
	/* 0x2d3: jmp    0x43 */
	X86_SIM_X86_JMP(0x2d3, 0x43, x86_l_43);
x86_l_2d8:
	/* 0x2d8: cmp    edi,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_2db:
	/* 0x2db: jg     0x4aa */
	X86_SIM_X86_JCC(X86_CC_G, 0x2db, 0x4aa, x86_l_4aa);
x86_l_2e1:
	/* 0x2e1: cmp    edi,0x1c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 28ULL);
x86_l_2e4:
	/* 0x2e4: je     0x564 */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e4, 0x564, x86_l_564);
x86_l_2ea:
	/* 0x2ea: cmp    edi,0x1d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_2ed:
	/* 0x2ed: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ed, 0x60e, x86_l_60e);
x86_l_2f3:
	/* 0x2f3: mov    ebx,0x1f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_2f8:
	/* 0x2f8: jmp    0x43 */
	X86_SIM_X86_JMP(0x2f8, 0x43, x86_l_43);
x86_l_2fd:
	/* 0x2fd: cmp    edi,0x3d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_300:
	/* 0x300: jg     0x4c6 */
	X86_SIM_X86_JCC(X86_CC_G, 0x300, 0x4c6, x86_l_4c6);
x86_l_306:
	/* 0x306: cmp    edi,0x3c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_309:
	/* 0x309: je     0x56e */
	X86_SIM_X86_JCC(X86_CC_E, 0x309, 0x56e, x86_l_56e);
x86_l_30f:
	/* 0x30f: cmp    edi,0x3d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_312:
	/* 0x312: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x312, 0x60e, x86_l_60e);
x86_l_318:
	/* 0x318: mov    ebx,0x5 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 5ULL);
x86_l_31d:
	/* 0x31d: jmp    0x43 */
	X86_SIM_X86_JMP(0x31d, 0x43, x86_l_43);
x86_l_322:
	/* 0x322: cmp    edi,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_325:
	/* 0x325: je     0x578 */
	X86_SIM_X86_JCC(X86_CC_E, 0x325, 0x578, x86_l_578);
x86_l_32b:
	/* 0x32b: cmp    edi,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_32e:
	/* 0x32e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x32e, 0x60e, x86_l_60e);
x86_l_334:
	/* 0x334: mov    ebx,0x1c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 28ULL);
x86_l_339:
	/* 0x339: jmp    0x43 */
	X86_SIM_X86_JMP(0x339, 0x43, x86_l_43);
x86_l_33e:
	/* 0x33e: cmp    edi,0x22 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_341:
	/* 0x341: je     0x582 */
	X86_SIM_X86_JCC(X86_CC_E, 0x341, 0x582, x86_l_582);
x86_l_347:
	/* 0x347: cmp    edi,0x23 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_34a:
	/* 0x34a: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34a, 0x60e, x86_l_60e);
x86_l_350:
	/* 0x350: mov    ebx,0x1b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_355:
	/* 0x355: jmp    0x43 */
	X86_SIM_X86_JMP(0x355, 0x43, x86_l_43);
x86_l_35a:
	/* 0x35a: cmp    edi,0x12 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 18ULL);
x86_l_35d:
	/* 0x35d: je     0x58c */
	X86_SIM_X86_JCC(X86_CC_E, 0x35d, 0x58c, x86_l_58c);
x86_l_363:
	/* 0x363: cmp    edi,0x13 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_366:
	/* 0x366: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x366, 0x60e, x86_l_60e);
x86_l_36c:
	/* 0x36c: mov    ebx,0x6 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_371:
	/* 0x371: jmp    0x43 */
	X86_SIM_X86_JMP(0x371, 0x43, x86_l_43);
x86_l_376:
	/* 0x376: cmp    edi,0x32 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 50ULL);
x86_l_379:
	/* 0x379: je     0x596 */
	X86_SIM_X86_JCC(X86_CC_E, 0x379, 0x596, x86_l_596);
x86_l_37f:
	/* 0x37f: cmp    edi,0x33 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_382:
	/* 0x382: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x382, 0x60e, x86_l_60e);
x86_l_388:
	/* 0x388: mov    ebx,0x3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_38d:
	/* 0x38d: jmp    0x43 */
	X86_SIM_X86_JMP(0x38d, 0x43, x86_l_43);
x86_l_392:
	/* 0x392: cmp    edi,0xa */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_395:
	/* 0x395: je     0x5a0 */
	X86_SIM_X86_JCC(X86_CC_E, 0x395, 0x5a0, x86_l_5a0);
x86_l_39b:
	/* 0x39b: cmp    edi,0xb */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_39e:
	/* 0x39e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x39e, 0x60e, x86_l_60e);
x86_l_3a4:
	/* 0x3a4: mov    ebx,0x24 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 36ULL);
x86_l_3a9:
	/* 0x3a9: jmp    0x43 */
	X86_SIM_X86_JMP(0x3a9, 0x43, x86_l_43);
x86_l_3ae:
	/* 0x3ae: cmp    edi,0x2a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 42ULL);
x86_l_3b1:
	/* 0x3b1: je     0x5aa */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b1, 0x5aa, x86_l_5aa);
x86_l_3b7:
	/* 0x3b7: cmp    edi,0x2b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 43ULL);
x86_l_3ba:
	/* 0x3ba: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ba, 0x60e, x86_l_60e);
x86_l_3c0:
	/* 0x3c0: mov    ebx,0x23 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 35ULL);
x86_l_3c5:
	/* 0x3c5: jmp    0x43 */
	X86_SIM_X86_JMP(0x3c5, 0x43, x86_l_43);
x86_l_3ca:
	/* 0x3ca: cmp    edi,0x1a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 26ULL);
x86_l_3cd:
	/* 0x3cd: je     0x5b4 */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cd, 0x5b4, x86_l_5b4);
x86_l_3d3:
	/* 0x3d3: cmp    edi,0x1b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 27ULL);
x86_l_3d6:
	/* 0x3d6: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3d6, 0x60e, x86_l_60e);
x86_l_3dc:
	/* 0x3dc: mov    ebx,0x29 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 41ULL);
x86_l_3e1:
	/* 0x3e1: jmp    0x43 */
	X86_SIM_X86_JMP(0x3e1, 0x43, x86_l_43);
x86_l_3e6:
	/* 0x3e6: cmp    edi,0x3a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_3e9:
	/* 0x3e9: je     0x5be */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e9, 0x5be, x86_l_5be);
x86_l_3ef:
	/* 0x3ef: cmp    edi,0x3b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_3f2:
	/* 0x3f2: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f2, 0x60e, x86_l_60e);
x86_l_3f8:
	/* 0x3f8: mov    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 16ULL);
x86_l_3fd:
	/* 0x3fd: jmp    0x43 */
	X86_SIM_X86_JMP(0x3fd, 0x43, x86_l_43);
x86_l_402:
	/* 0x402: cmp    edi,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 6ULL);
x86_l_405:
	/* 0x405: je     0x5c8 */
	X86_SIM_X86_JCC(X86_CC_E, 0x405, 0x5c8, x86_l_5c8);
x86_l_40b:
	/* 0x40b: cmp    edi,0x7 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_40e:
	/* 0x40e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40e, 0x60e, x86_l_60e);
x86_l_414:
	/* 0x414: mov    ebx,0x3a */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_419:
	/* 0x419: jmp    0x43 */
	X86_SIM_X86_JMP(0x419, 0x43, x86_l_43);
x86_l_41e:
	/* 0x41e: cmp    edi,0x26 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_421:
	/* 0x421: je     0x5d2 */
	X86_SIM_X86_JCC(X86_CC_E, 0x421, 0x5d2, x86_l_5d2);
x86_l_427:
	/* 0x427: cmp    edi,0x27 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_42a:
	/* 0x42a: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42a, 0x60e, x86_l_60e);
x86_l_430:
	/* 0x430: mov    ebx,0x30 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 48ULL);
x86_l_435:
	/* 0x435: jmp    0x43 */
	X86_SIM_X86_JMP(0x435, 0x43, x86_l_43);
x86_l_43a:
	/* 0x43a: cmp    edi,0x16 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 22ULL);
x86_l_43d:
	/* 0x43d: je     0x5dc */
	X86_SIM_X86_JCC(X86_CC_E, 0x43d, 0x5dc, x86_l_5dc);
x86_l_443:
	/* 0x443: cmp    edi,0x17 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_446:
	/* 0x446: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x446, 0x60e, x86_l_60e);
x86_l_44c:
	/* 0x44c: mov    ebx,0x28 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 40ULL);
x86_l_451:
	/* 0x451: jmp    0x43 */
	X86_SIM_X86_JMP(0x451, 0x43, x86_l_43);
x86_l_456:
	/* 0x456: cmp    edi,0x36 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 54ULL);
x86_l_459:
	/* 0x459: je     0x5e6 */
	X86_SIM_X86_JCC(X86_CC_E, 0x459, 0x5e6, x86_l_5e6);
x86_l_45f:
	/* 0x45f: cmp    edi,0x37 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_462:
	/* 0x462: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x462, 0x60e, x86_l_60e);
x86_l_468:
	/* 0x468: mov    ebx,0x12 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 18ULL);
x86_l_46d:
	/* 0x46d: jmp    0x43 */
	X86_SIM_X86_JMP(0x46d, 0x43, x86_l_43);
x86_l_472:
	/* 0x472: cmp    edi,0xe */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_475:
	/* 0x475: je     0x5f0 */
	X86_SIM_X86_JCC(X86_CC_E, 0x475, 0x5f0, x86_l_5f0);
x86_l_47b:
	/* 0x47b: cmp    edi,0xf */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_47e:
	/* 0x47e: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47e, 0x60e, x86_l_60e);
x86_l_484:
	/* 0x484: mov    ebx,0x2e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 46ULL);
x86_l_489:
	/* 0x489: jmp    0x43 */
	X86_SIM_X86_JMP(0x489, 0x43, x86_l_43);
x86_l_48e:
	/* 0x48e: cmp    edi,0x2e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 46ULL);
x86_l_491:
	/* 0x491: je     0x5fa */
	X86_SIM_X86_JCC(X86_CC_E, 0x491, 0x5fa, x86_l_5fa);
x86_l_497:
	/* 0x497: cmp    edi,0x2f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_49a:
	/* 0x49a: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x49a, 0x60e, x86_l_60e);
x86_l_4a0:
	/* 0x4a0: mov    ebx,0x3b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_4a5:
	/* 0x4a5: jmp    0x43 */
	X86_SIM_X86_JMP(0x4a5, 0x43, x86_l_43);
x86_l_4aa:
	/* 0x4aa: cmp    edi,0x1e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_4ad:
	/* 0x4ad: je     0x604 */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ad, 0x604, x86_l_604);
x86_l_4b3:
	/* 0x4b3: cmp    edi,0x1f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 31ULL);
x86_l_4b6:
	/* 0x4b6: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b6, 0x60e, x86_l_60e);
x86_l_4bc:
	/* 0x4bc: mov    ebx,0x34 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 52ULL);
x86_l_4c1:
	/* 0x4c1: jmp    0x43 */
	X86_SIM_X86_JMP(0x4c1, 0x43, x86_l_43);
x86_l_4c6:
	/* 0x4c6: cmp    edi,0x3e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 62ULL);
x86_l_4c9:
	/* 0x4c9: je     0x3e */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c9, 0x3e, x86_l_3e);
x86_l_4cf:
	/* 0x4cf: cmp    edi,0x3f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, 0, 63ULL);
x86_l_4d2:
	/* 0x4d2: jne    0x60e */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4d2, 0x60e, x86_l_60e);
x86_l_4d8:
	/* 0x4d8: mov    ebx,0x37 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 55ULL);
x86_l_4dd:
	/* 0x4dd: jmp    0x43 */
	X86_SIM_X86_JMP(0x4dd, 0x43, x86_l_43);
x86_l_4e2:
	/* 0x4e2: mov    ebx,0x19 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 25ULL);
x86_l_4e7:
	/* 0x4e7: jmp    0x43 */
	X86_SIM_X86_JMP(0x4e7, 0x43, x86_l_43);
x86_l_4ec:
	/* 0x4ec: mov    ebx,0x22 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 34ULL);
x86_l_4f1:
	/* 0x4f1: jmp    0x43 */
	X86_SIM_X86_JMP(0x4f1, 0x43, x86_l_43);
x86_l_4f6:
	/* 0x4f6: mov    ebx,0x2d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 45ULL);
x86_l_4fb:
	/* 0x4fb: jmp    0x43 */
	X86_SIM_X86_JMP(0x4fb, 0x43, x86_l_43);
x86_l_500:
	/* 0x500: mov    ebx,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_505:
	/* 0x505: jmp    0x43 */
	X86_SIM_X86_JMP(0x505, 0x43, x86_l_43);
x86_l_50a:
	/* 0x50a: mov    ebx,0x20 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_50f:
	/* 0x50f: jmp    0x43 */
	X86_SIM_X86_JMP(0x50f, 0x43, x86_l_43);
x86_l_514:
	/* 0x514: mov    ebx,0x26 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_519:
	/* 0x519: jmp    0x43 */
	X86_SIM_X86_JMP(0x519, 0x43, x86_l_43);
x86_l_51e:
	/* 0x51e: mov    ebx,0x1 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_523:
	/* 0x523: jmp    0x43 */
	X86_SIM_X86_JMP(0x523, 0x43, x86_l_43);
x86_l_528:
	/* 0x528: mov    ebx,0xe */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 14ULL);
x86_l_52d:
	/* 0x52d: jmp    0x43 */
	X86_SIM_X86_JMP(0x52d, 0x43, x86_l_43);
x86_l_532:
	/* 0x532: mov    ebx,0x35 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_537:
	/* 0x537: jmp    0x43 */
	X86_SIM_X86_JMP(0x537, 0x43, x86_l_43);
x86_l_53c:
	/* 0x53c: mov    ebx,0x1d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 29ULL);
x86_l_541:
	/* 0x541: jmp    0x43 */
	X86_SIM_X86_JMP(0x541, 0x43, x86_l_43);
x86_l_546:
	/* 0x546: mov    ebx,0xd */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 13ULL);
x86_l_54b:
	/* 0x54b: jmp    0x43 */
	X86_SIM_X86_JMP(0x54b, 0x43, x86_l_43);
x86_l_550:
	/* 0x550: mov    ebx,0x13 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_555:
	/* 0x555: jmp    0x43 */
	X86_SIM_X86_JMP(0x555, 0x43, x86_l_43);
x86_l_55a:
	/* 0x55a: mov    ebx,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_55f:
	/* 0x55f: jmp    0x43 */
	X86_SIM_X86_JMP(0x55f, 0x43, x86_l_43);
x86_l_564:
	/* 0x564: mov    ebx,0x21 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_569:
	/* 0x569: jmp    0x43 */
	X86_SIM_X86_JMP(0x569, 0x43, x86_l_43);
x86_l_56e:
	/* 0x56e: mov    ebx,0x3c */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_573:
	/* 0x573: jmp    0x43 */
	X86_SIM_X86_JMP(0x573, 0x43, x86_l_43);
x86_l_578:
	/* 0x578: mov    ebx,0x39 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_57d:
	/* 0x57d: jmp    0x43 */
	X86_SIM_X86_JMP(0x57d, 0x43, x86_l_43);
x86_l_582:
	/* 0x582: mov    ebx,0xb */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 11ULL);
x86_l_587:
	/* 0x587: jmp    0x43 */
	X86_SIM_X86_JMP(0x587, 0x43, x86_l_43);
x86_l_58c:
	/* 0x58c: mov    ebx,0x2f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 47ULL);
x86_l_591:
	/* 0x591: jmp    0x43 */
	X86_SIM_X86_JMP(0x591, 0x43, x86_l_43);
x86_l_596:
	/* 0x596: mov    ebx,0x9 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_59b:
	/* 0x59b: jmp    0x43 */
	X86_SIM_X86_JMP(0x59b, 0x43, x86_l_43);
x86_l_5a0:
	/* 0x5a0: mov    ebx,0x31 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 49ULL);
x86_l_5a5:
	/* 0x5a5: jmp    0x43 */
	X86_SIM_X86_JMP(0x5a5, 0x43, x86_l_43);
x86_l_5aa:
	/* 0x5aa: mov    ebx,0x7 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 7ULL);
x86_l_5af:
	/* 0x5af: jmp    0x43 */
	X86_SIM_X86_JMP(0x5af, 0x43, x86_l_43);
x86_l_5b4:
	/* 0x5b4: mov    ebx,0x11 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 17ULL);
x86_l_5b9:
	/* 0x5b9: jmp    0x43 */
	X86_SIM_X86_JMP(0x5b9, 0x43, x86_l_43);
x86_l_5be:
	/* 0x5be: mov    ebx,0x16 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 22ULL);
x86_l_5c3:
	/* 0x5c3: jmp    0x43 */
	X86_SIM_X86_JMP(0x5c3, 0x43, x86_l_43);
x86_l_5c8:
	/* 0x5c8: mov    ebx,0xa */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 10ULL);
x86_l_5cd:
	/* 0x5cd: jmp    0x43 */
	X86_SIM_X86_JMP(0x5cd, 0x43, x86_l_43);
x86_l_5d2:
	/* 0x5d2: mov    ebx,0x18 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 24ULL);
x86_l_5d7:
	/* 0x5d7: jmp    0x43 */
	X86_SIM_X86_JMP(0x5d7, 0x43, x86_l_43);
x86_l_5dc:
	/* 0x5dc: mov    ebx,0xf */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 15ULL);
x86_l_5e1:
	/* 0x5e1: jmp    0x43 */
	X86_SIM_X86_JMP(0x5e1, 0x43, x86_l_43);
x86_l_5e6:
	/* 0x5e6: mov    ebx,0x1e */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 30ULL);
x86_l_5eb:
	/* 0x5eb: jmp    0x43 */
	X86_SIM_X86_JMP(0x5eb, 0x43, x86_l_43);
x86_l_5f0:
	/* 0x5f0: mov    ebx,0x25 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 37ULL);
x86_l_5f5:
	/* 0x5f5: jmp    0x43 */
	X86_SIM_X86_JMP(0x5f5, 0x43, x86_l_43);
x86_l_5fa:
	/* 0x5fa: mov    ebx,0x33 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 51ULL);
x86_l_5ff:
	/* 0x5ff: jmp    0x43 */
	X86_SIM_X86_JMP(0x5ff, 0x43, x86_l_43);
x86_l_604:
	/* 0x604: mov    ebx,0x17 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 23ULL);
x86_l_609:
	/* 0x609: jmp    0x43 */
	X86_SIM_X86_JMP(0x609, 0x43, x86_l_43);
x86_l_60e:
	/* 0x60e: mov    ebx,0x1bf52 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, 0, 114514ULL);
x86_l_613:
	/* 0x613: jmp    0x43 */
	X86_SIM_X86_JMP(0x613, 0x43, x86_l_43);
x86_l_618:
	/* 0x618: mov    BYTE PTR [rcx],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61a:
	/* 0x61a: mov    BYTE PTR [rcx+0x1],bh */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_61d:
	/* 0x61d: shr    ebx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_620:
	/* 0x620: mov    BYTE PTR [rcx+0x2],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_623:
	/* 0x623: mov    edx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_625:
	/* 0x625: shr    edx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_628:
	/* 0x628: mov    BYTE PTR [rcx+0x3],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_62b:
	/* 0x62b: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_62e:
	/* 0x62e: shr    rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_632:
	/* 0x632: mov    BYTE PTR [rcx+0x4],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_635:
	/* 0x635: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_638:
	/* 0x638: shr    rdx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_63c:
	/* 0x63c: mov    BYTE PTR [rcx+0x5],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_63f:
	/* 0x63f: mov    rdx,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_642:
	/* 0x642: shr    rdx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_646:
	/* 0x646: mov    BYTE PTR [rcx+0x6],dl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_649:
	/* 0x649: shr    rax,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_64d:
	/* 0x64d: mov    BYTE PTR [rcx+0x7],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_650:
	/* 0x650: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_655:
	/* 0x655: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_656:
	/* 0x656: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_657:
	/* 0x657: jmp    0x65c ; native-link entry RET */
	X86_SIM_X86_RET();
	__builtin_unreachable();
}

X86_SIM_LICENSE();
