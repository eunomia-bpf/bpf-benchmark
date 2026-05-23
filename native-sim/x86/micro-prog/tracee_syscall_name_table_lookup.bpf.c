#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_syscall_name_table_lookup_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
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
	/* 0xf: jbe    16 <tracee_syscall_name_table_lookup_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    336 <tracee_syscall_name_table_lookup_xdp+0x336> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <tracee_syscall_name_table_lookup_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0x10c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <tracee_syscall_name_table_lookup_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e:
	/* 0x2e: jne    11 <tracee_syscall_name_table_lookup_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e, 0x11, x86_l_11);
x86_l_30:
	/* 0x30: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_31:
	/* 0x31: push   r15 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_33:
	/* 0x33: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_35:
	/* 0x35: push   r13 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_37:
	/* 0x37: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_39:
	/* 0x39: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3a:
	/* 0x3a: movabs rdi,0x6a09e667f3bcc909 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 7640891576956012809ULL);
x86_l_44:
	/* 0x44: movabs r13,0x65736f6c63 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 435728378979ULL);
x86_l_4e:
	/* 0x4e: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_51:
	/* 0x51: lea    r8,[r13+0xfa0614] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16385556ULL);
x86_l_58:
	/* 0x58: movabs r14,0x74616e65706f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 127961812791407ULL);
x86_l_62:
	/* 0x62: movabs r10,0x74616b6e696c6e75 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 8386102103099862645ULL);
x86_l_6c:
	/* 0x6c: movabs r11,0x74613274617473 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 32757966627239027ULL);
x86_l_76:
	/* 0x76: movabs rbx,0x647466656e676973 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 7238523086921230707ULL);
x86_l_80:
	/* 0x80: movzx  r15d,BYTE PTR [rdx+r9*4+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 2, X86_WIDTH_8), 12ULL);
x86_l_86:
	/* 0x86: movzx  eax,BYTE PTR [rdx+r9*4+0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 2, X86_WIDTH_8), 13ULL);
x86_l_8c:
	/* 0x8c: shl    eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_8f:
	/* 0x8f: or     eax,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_92:
	/* 0x92: movzx  r12d,WORD PTR [rdx+r9*4+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 2, X86_WIDTH_16), 14ULL);
x86_l_98:
	/* 0x98: shl    r12d,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_9c:
	/* 0x9c: or     r12d,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_9f:
	/* 0x9f: cmp    r12d,0x4f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_a3:
	/* 0xa3: jg     dc <tracee_syscall_name_table_lookup_xdp+0xdc> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa3, 0xdc, x86_l_dc);
x86_l_a5:
	/* 0xa5: cmp    r12d,0x26 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_a9:
	/* 0xa9: jg     11f <tracee_syscall_name_table_lookup_xdp+0x11f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa9, 0x11f, x86_l_11f);
x86_l_ab:
	/* 0xab: cmp    r12d,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_af:
	/* 0xaf: jg     18d <tracee_syscall_name_table_lookup_xdp+0x18d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xaf, 0x18d, x86_l_18d);
x86_l_b5:
	/* 0xb5: test   r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_b8:
	/* 0xb8: je     287 <tracee_syscall_name_table_lookup_xdp+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb8, 0x287, x86_l_287);
x86_l_be:
	/* 0xbe: cmp    r12d,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_c2:
	/* 0xc2: je     244 <tracee_syscall_name_table_lookup_xdp+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2, 0x244, x86_l_244);
x86_l_c8:
	/* 0xc8: cmp    r12d,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_cc:
	/* 0xcc: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc, 0x2fe, x86_l_2fe);
x86_l_d2:
	/* 0xd2: mov    eax,0x6e65706f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1852141679ULL);
x86_l_d7:
	/* 0xd7: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0xd7, 0x2c1, x86_l_2c1);
x86_l_dc:
	/* 0xdc: cmp    r12d,0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 256ULL);
x86_l_e3:
	/* 0xe3: jg     151 <tracee_syscall_name_table_lookup_xdp+0x151> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe3, 0x151, x86_l_151);
x86_l_e5:
	/* 0xe5: cmp    r12d,0x9d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 157ULL);
x86_l_ec:
	/* 0xec: jg     1b8 <tracee_syscall_name_table_lookup_xdp+0x1b8> */
	X86_SIM_X86_JCC(X86_CC_G, 0xec, 0x1b8, x86_l_1b8);
x86_l_f2:
	/* 0xf2: cmp    r12d,0x50 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_f6:
	/* 0xf6: je     28e <tracee_syscall_name_table_lookup_xdp+0x28e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6, 0x28e, x86_l_28e);
x86_l_fc:
	/* 0xfc: cmp    r12d,0x57 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 87ULL);
x86_l_100:
	/* 0x100: je     249 <tracee_syscall_name_table_lookup_xdp+0x249> */
	X86_SIM_X86_JCC(X86_CC_E, 0x100, 0x249, x86_l_249);
x86_l_106:
	/* 0x106: cmp    r12d,0x59 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 89ULL);
x86_l_10a:
	/* 0x10a: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a, 0x2fe, x86_l_2fe);
x86_l_110:
	/* 0x110: movabs rax,0x6b6e696c55 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 461413903445ULL);
x86_l_11a:
	/* 0x11a: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x11a, 0x2c1, x86_l_2c1);
x86_l_11f:
	/* 0x11f: cmp    r12d,0x3a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_123:
	/* 0x123: jg     1ee <tracee_syscall_name_table_lookup_xdp+0x1ee> */
	X86_SIM_X86_JCC(X86_CC_G, 0x123, 0x1ee, x86_l_1ee);
x86_l_129:
	/* 0x129: cmp    r12d,0x27 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_12d:
	/* 0x12d: je     295 <tracee_syscall_name_table_lookup_xdp+0x295> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d, 0x295, x86_l_295);
x86_l_133:
	/* 0x133: cmp    r12d,0x38 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_137:
	/* 0x137: je     255 <tracee_syscall_name_table_lookup_xdp+0x255> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137, 0x255, x86_l_255);
x86_l_13d:
	/* 0x13d: cmp    r12d,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_141:
	/* 0x141: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x141, 0x2fe, x86_l_2fe);
x86_l_147:
	/* 0x147: mov    eax,0x6b726f66 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1802661734ULL);
x86_l_14c:
	/* 0x14c: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x14c, 0x2c1, x86_l_2c1);
x86_l_151:
	/* 0x151: cmp    r12d,0x122 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 290ULL);
x86_l_158:
	/* 0x158: jg     217 <tracee_syscall_name_table_lookup_xdp+0x217> */
	X86_SIM_X86_JCC(X86_CC_G, 0x158, 0x217, x86_l_217);
x86_l_15e:
	/* 0x15e: cmp    r12d,0x101 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 257ULL);
x86_l_165:
	/* 0x165: je     2a1 <tracee_syscall_name_table_lookup_xdp+0x2a1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x165, 0x2a1, x86_l_2a1);
x86_l_16b:
	/* 0x16b: cmp    r12d,0x107 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 263ULL);
x86_l_172:
	/* 0x172: je     261 <tracee_syscall_name_table_lookup_xdp+0x261> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172, 0x261, x86_l_261);
x86_l_178:
	/* 0x178: cmp    r12d,0x119 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 281ULL);
x86_l_17f:
	/* 0x17f: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17f, 0x2fe, x86_l_2fe);
x86_l_185:
	/* 0x185: mov    rax,r11 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R11, X86_WIDTH_64, 0, 0);
x86_l_188:
	/* 0x188: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x188, 0x2c1, x86_l_2c1);
x86_l_18d:
	/* 0x18d: mov    rax,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_190:
	/* 0x190: cmp    r12d,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_194:
	/* 0x194: je     2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x194, 0x2c1, x86_l_2c1);
x86_l_19a:
	/* 0x19a: cmp    r12d,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_19e:
	/* 0x19e: je     266 <tracee_syscall_name_table_lookup_xdp+0x266> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19e, 0x266, x86_l_266);
x86_l_1a4:
	/* 0x1a4: cmp    r12d,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_1a8:
	/* 0x1a8: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a8, 0x2fe, x86_l_2fe);
x86_l_1ae:
	/* 0x1ae: mov    eax,0x6b72626b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1802658411ULL);
x86_l_1b3:
	/* 0x1b3: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x1b3, 0x2c1, x86_l_2c1);
x86_l_1b8:
	/* 0x1b8: cmp    r12d,0x9e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 158ULL);
x86_l_1bf:
	/* 0x1bf: je     2a6 <tracee_syscall_name_table_lookup_xdp+0x2a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf, 0x2a6, x86_l_2a6);
x86_l_1c5:
	/* 0x1c5: cmp    r12d,0xca */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 202ULL);
x86_l_1cc:
	/* 0x1cc: je     26d <tracee_syscall_name_table_lookup_xdp+0x26d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cc, 0x26d, x86_l_26d);
x86_l_1d2:
	/* 0x1d2: cmp    r12d,0xd9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 217ULL);
x86_l_1d9:
	/* 0x1d9: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d9, 0x2fe, x86_l_2fe);
x86_l_1df:
	/* 0x1df: movabs rax,0x646461746567 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 110382294525287ULL);
x86_l_1e9:
	/* 0x1e9: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x1e9, 0x2c1, x86_l_2c1);
x86_l_1ee:
	/* 0x1ee: cmp    r12d,0x3b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_1f2:
	/* 0x1f2: je     2b2 <tracee_syscall_name_table_lookup_xdp+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2, 0x2b2, x86_l_2b2);
x86_l_1f8:
	/* 0x1f8: cmp    r12d,0x3c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_1fc:
	/* 0x1fc: je     279 <tracee_syscall_name_table_lookup_xdp+0x279> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fc, 0x279, x86_l_279);
x86_l_1fe:
	/* 0x1fe: cmp    r12d,0x3d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_202:
	/* 0x202: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x202, 0x2fe, x86_l_2fe);
x86_l_208:
	/* 0x208: movabs rax,0x347469617755 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 57674588845909ULL);
x86_l_212:
	/* 0x212: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x212, 0x2c1, x86_l_2c1);
x86_l_217:
	/* 0x217: cmp    r12d,0x123 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 291ULL);
x86_l_21e:
	/* 0x21e: je     2be <tracee_syscall_name_table_lookup_xdp+0x2be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21e, 0x2be, x86_l_2be);
x86_l_224:
	/* 0x224: cmp    r12d,0x141 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 321ULL);
x86_l_22b:
	/* 0x22b: je     280 <tracee_syscall_name_table_lookup_xdp+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22b, 0x280, x86_l_280);
x86_l_22d:
	/* 0x22d: cmp    r12d,0x14c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, 0, 332ULL);
x86_l_234:
	/* 0x234: jne    2fe <tracee_syscall_name_table_lookup_xdp+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x234, 0x2fe, x86_l_2fe);
x86_l_23a:
	/* 0x23a: mov    eax,0x78746173 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2020893043ULL);
x86_l_23f:
	/* 0x23f: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x23f, 0x2c1, x86_l_2c1);
x86_l_244:
	/* 0x244: mov    rax,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_247:
	/* 0x247: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x247, 0x2c1, x86_l_2c1);
x86_l_249:
	/* 0x249: movabs rax,0x6b6e696c6e75 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 118121959288437ULL);
x86_l_253:
	/* 0x253: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x253, 0x2c1, x86_l_2c1);
x86_l_255:
	/* 0x255: movabs rax,0x656e6f6c6355 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 111524990182229ULL);
x86_l_25f:
	/* 0x25f: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x25f, 0x2c1, x86_l_2c1);
x86_l_261:
	/* 0x261: mov    rax,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_264:
	/* 0x264: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x264, 0x2c1, x86_l_2c1);
x86_l_266:
	/* 0x266: mov    eax,0x70616d6d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1885433197ULL);
x86_l_26b:
	/* 0x26b: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x26b, 0x2c1, x86_l_2c1);
x86_l_26d:
	/* 0x26d: movabs rax,0x786574756655 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 132377140880981ULL);
x86_l_277:
	/* 0x277: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x277, 0x2c1, x86_l_2c1);
x86_l_279:
	/* 0x279: mov    eax,0x74697865 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1953069157ULL);
x86_l_27e:
	/* 0x27e: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x27e, 0x2c1, x86_l_2c1);
x86_l_280:
	/* 0x280: mov    eax,0x706662 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 7366242ULL);
x86_l_285:
	/* 0x285: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x285, 0x2c1, x86_l_2c1);
x86_l_287:
	/* 0x287: mov    eax,0x72656164 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1919246692ULL);
x86_l_28c:
	/* 0x28c: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x28c, 0x2c1, x86_l_2c1);
x86_l_28e:
	/* 0x28e: mov    eax,0x69646863 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1768188003ULL);
x86_l_293:
	/* 0x293: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x293, 0x2c1, x86_l_2c1);
x86_l_295:
	/* 0x295: movabs rax,0x6469707467 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 431265707111ULL);
x86_l_29f:
	/* 0x29f: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x29f, 0x2c1, x86_l_2c1);
x86_l_2a1:
	/* 0x2a1: mov    rax,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_2a4:
	/* 0x2a4: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x2a4, 0x2c1, x86_l_2c1);
x86_l_2a6:
	/* 0x2a6: movabs rax,0x6c74635f68637261 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 7814980514819043937ULL);
x86_l_2b0:
	/* 0x2b0: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x2b0, 0x2c1, x86_l_2c1);
x86_l_2b2:
	/* 0x2b2: movabs rax,0x657663657865 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 111559148140645ULL);
x86_l_2bc:
	/* 0x2bc: jmp    2c1 <tracee_syscall_name_table_lookup_xdp+0x2c1> */
	X86_SIM_X86_JMP(0x2bc, 0x2c1, x86_l_2c1);
x86_l_2be:
	/* 0x2be: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_2c1:
	/* 0x2c1: mov    r12d,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_2c4:
	/* 0x2c4: xor    r12,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_2c7:
	/* 0x2c7: mov    esi,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_2ca:
	/* 0x2ca: and    esi,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2cd:
	/* 0x2cd: lea    ebp,[rsi+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d0:
	/* 0x2d0: shlx   rbp,r12,rbp */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RBP, X86_R12, X86_WIDTH_64, X86_RBP, X86_ALU_SHL);
x86_l_2d5:
	/* 0x2d5: mov    eax,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2d7:
	/* 0x2d7: not    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_2d9:
	/* 0x2d9: shrx   rax,r12,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_R12, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_2de:
	/* 0x2de: or     rax,rbp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_2e1:
	/* 0x2e1: add    rax,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_2e4:
	/* 0x2e4: shl    esi,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2e7:
	/* 0x2e7: shlx   rdi,r15,rsi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDI, X86_R15, X86_WIDTH_64, X86_RSI, X86_ALU_SHL);
x86_l_2ec:
	/* 0x2ec: xor    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_2ef:
	/* 0x2ef: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f2:
	/* 0x2f2: cmp    r9,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_2f6:
	/* 0x2f6: jne    80 <tracee_syscall_name_table_lookup_xdp+0x80> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f6, 0x80, x86_l_80);
x86_l_2fc:
	/* 0x2fc: jmp    31f <tracee_syscall_name_table_lookup_xdp+0x31f> */
	X86_SIM_X86_JMP(0x2fc, 0x31f, x86_l_31f);
x86_l_2fe:
	/* 0x2fe: mov    eax,r12d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_301:
	/* 0x301: movabs rsi,0x9e3779b185ebca87 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 11400714785074694791ULL);
x86_l_30b:
	/* 0x30b: imul   rax,rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_30f:
	/* 0x30f: xor    rdi,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_312:
	/* 0x312: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_315:
	/* 0x315: cmp    r9,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_319:
	/* 0x319: jne    80 <tracee_syscall_name_table_lookup_xdp+0x80> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x319, 0x80, x86_l_80);
x86_l_31f:
	/* 0x31f: mov    QWORD PTR [rcx],rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322:
	/* 0x322: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_327:
	/* 0x327: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_328:
	/* 0x328: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_32a:
	/* 0x32a: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_32c:
	/* 0x32c: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_32e:
	/* 0x32e: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_330:
	/* 0x330: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_331:
	/* 0x331: jmp    336 <tracee_syscall_name_table_lookup_xdp+0x336> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_336:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
