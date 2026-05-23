#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tracee_syscall_name_table_lookup_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <tracee_syscall_name_table_lookup_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    30a <tracee_syscall_name_table_lookup_xdp+0x30a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <tracee_syscall_name_table_lookup_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rsi+0x10c] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_26:
	/* 0x26: cmp    r8,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64, 0, 0);
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
	/* 0x3a: movabs r11,0x6a09e667f3bcc909 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 7640891576956012809ULL);
x86_l_44:
	/* 0x44: movabs rdi,0x65736f6c63 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 435728378979ULL);
x86_l_4e:
	/* 0x4e: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_51:
	/* 0x51: lea    r10,[rdi+0xfa0614] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R10, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16385556ULL);
x86_l_58:
	/* 0x58: movabs r14,0x74616e65706f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 127961812791407ULL);
x86_l_62:
	/* 0x62: movabs r15,0x74616b6e696c6e75 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 8386102103099862645ULL);
x86_l_6c:
	/* 0x6c: movabs r13,0x74613274617473 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 32757966627239027ULL);
x86_l_76:
	/* 0x76: movabs rbp,0x647466656e676973 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 7238523086921230707ULL);
x86_l_80:
	/* 0x80: movzx  r8d,BYTE PTR [rsi+r9*4+0xc] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 2, X86_WIDTH_8), 12ULL);
x86_l_86:
	/* 0x86: movzx  ecx,BYTE PTR [rsi+r9*4+0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 2, X86_WIDTH_8), 13ULL);
x86_l_8c:
	/* 0x8c: shl    ecx,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_8f:
	/* 0x8f: or     ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_92:
	/* 0x92: movzx  eax,WORD PTR [rsi+r9*4+0xe] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R9, 2, X86_WIDTH_16), 14ULL);
x86_l_98:
	/* 0x98: shl    eax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_9b:
	/* 0x9b: or     eax,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_9d:
	/* 0x9d: cmp    eax,0x4f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_a0:
	/* 0xa0: jg     d4 <tracee_syscall_name_table_lookup_xdp+0xd4> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa0, 0xd4, x86_l_d4);
x86_l_a2:
	/* 0xa2: cmp    eax,0x26 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_a5:
	/* 0xa5: jg     110 <tracee_syscall_name_table_lookup_xdp+0x110> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa5, 0x110, x86_l_110);
x86_l_a7:
	/* 0xa7: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_aa:
	/* 0xaa: jg     172 <tracee_syscall_name_table_lookup_xdp+0x172> */
	X86_SIM_X86_JCC(X86_CC_G, 0xaa, 0x172, x86_l_172);
x86_l_b0:
	/* 0xb0: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_b2:
	/* 0xb2: je     25a <tracee_syscall_name_table_lookup_xdp+0x25a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2, 0x25a, x86_l_25a);
x86_l_b8:
	/* 0xb8: cmp    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_bb:
	/* 0xbb: je     217 <tracee_syscall_name_table_lookup_xdp+0x217> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb, 0x217, x86_l_217);
x86_l_c1:
	/* 0xc1: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_c4:
	/* 0xc4: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc4, 0x2d3, x86_l_2d3);
x86_l_ca:
	/* 0xca: mov    ecx,0x6e65706f */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1852141679ULL);
x86_l_cf:
	/* 0xcf: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0xcf, 0x294, x86_l_294);
x86_l_d4:
	/* 0xd4: cmp    eax,0x100 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 256ULL);
x86_l_d9:
	/* 0xd9: jg     13e <tracee_syscall_name_table_lookup_xdp+0x13e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd9, 0x13e, x86_l_13e);
x86_l_db:
	/* 0xdb: cmp    eax,0x9d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 157ULL);
x86_l_e0:
	/* 0xe0: jg     19a <tracee_syscall_name_table_lookup_xdp+0x19a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe0, 0x19a, x86_l_19a);
x86_l_e6:
	/* 0xe6: cmp    eax,0x50 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_e9:
	/* 0xe9: je     261 <tracee_syscall_name_table_lookup_xdp+0x261> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe9, 0x261, x86_l_261);
x86_l_ef:
	/* 0xef: cmp    eax,0x57 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 87ULL);
x86_l_f2:
	/* 0xf2: je     21c <tracee_syscall_name_table_lookup_xdp+0x21c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf2, 0x21c, x86_l_21c);
x86_l_f8:
	/* 0xf8: cmp    eax,0x59 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 89ULL);
x86_l_fb:
	/* 0xfb: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb, 0x2d3, x86_l_2d3);
x86_l_101:
	/* 0x101: movabs rcx,0x6b6e696c55 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 461413903445ULL);
x86_l_10b:
	/* 0x10b: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x10b, 0x294, x86_l_294);
x86_l_110:
	/* 0x110: cmp    eax,0x3a */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_113:
	/* 0x113: jg     1ca <tracee_syscall_name_table_lookup_xdp+0x1ca> */
	X86_SIM_X86_JCC(X86_CC_G, 0x113, 0x1ca, x86_l_1ca);
x86_l_119:
	/* 0x119: cmp    eax,0x27 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_11c:
	/* 0x11c: je     268 <tracee_syscall_name_table_lookup_xdp+0x268> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c, 0x268, x86_l_268);
x86_l_122:
	/* 0x122: cmp    eax,0x38 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_125:
	/* 0x125: je     228 <tracee_syscall_name_table_lookup_xdp+0x228> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125, 0x228, x86_l_228);
x86_l_12b:
	/* 0x12b: cmp    eax,0x39 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_12e:
	/* 0x12e: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e, 0x2d3, x86_l_2d3);
x86_l_134:
	/* 0x134: mov    ecx,0x6b726f66 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1802661734ULL);
x86_l_139:
	/* 0x139: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x139, 0x294, x86_l_294);
x86_l_13e:
	/* 0x13e: cmp    eax,0x122 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 290ULL);
x86_l_143:
	/* 0x143: jg     1f0 <tracee_syscall_name_table_lookup_xdp+0x1f0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x143, 0x1f0, x86_l_1f0);
x86_l_149:
	/* 0x149: cmp    eax,0x101 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 257ULL);
x86_l_14e:
	/* 0x14e: je     274 <tracee_syscall_name_table_lookup_xdp+0x274> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e, 0x274, x86_l_274);
x86_l_154:
	/* 0x154: cmp    eax,0x107 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 263ULL);
x86_l_159:
	/* 0x159: je     234 <tracee_syscall_name_table_lookup_xdp+0x234> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159, 0x234, x86_l_234);
x86_l_15f:
	/* 0x15f: cmp    eax,0x119 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 281ULL);
x86_l_164:
	/* 0x164: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x164, 0x2d3, x86_l_2d3);
x86_l_16a:
	/* 0x16a: mov    rcx,r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_16d:
	/* 0x16d: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x16d, 0x294, x86_l_294);
x86_l_172:
	/* 0x172: mov    rcx,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_175:
	/* 0x175: cmp    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_178:
	/* 0x178: je     294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178, 0x294, x86_l_294);
x86_l_17e:
	/* 0x17e: cmp    eax,0x9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_181:
	/* 0x181: je     239 <tracee_syscall_name_table_lookup_xdp+0x239> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x239, x86_l_239);
x86_l_187:
	/* 0x187: cmp    eax,0xc */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_18a:
	/* 0x18a: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a, 0x2d3, x86_l_2d3);
x86_l_190:
	/* 0x190: mov    ecx,0x6b72626b */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1802658411ULL);
x86_l_195:
	/* 0x195: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x195, 0x294, x86_l_294);
x86_l_19a:
	/* 0x19a: cmp    eax,0x9e */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 158ULL);
x86_l_19f:
	/* 0x19f: je     279 <tracee_syscall_name_table_lookup_xdp+0x279> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19f, 0x279, x86_l_279);
x86_l_1a5:
	/* 0x1a5: cmp    eax,0xca */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 202ULL);
x86_l_1aa:
	/* 0x1aa: je     240 <tracee_syscall_name_table_lookup_xdp+0x240> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa, 0x240, x86_l_240);
x86_l_1b0:
	/* 0x1b0: cmp    eax,0xd9 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 217ULL);
x86_l_1b5:
	/* 0x1b5: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b5, 0x2d3, x86_l_2d3);
x86_l_1bb:
	/* 0x1bb: movabs rcx,0x646461746567 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 110382294525287ULL);
x86_l_1c5:
	/* 0x1c5: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x1c5, 0x294, x86_l_294);
x86_l_1ca:
	/* 0x1ca: cmp    eax,0x3b */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_1cd:
	/* 0x1cd: je     285 <tracee_syscall_name_table_lookup_xdp+0x285> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x285, x86_l_285);
x86_l_1d3:
	/* 0x1d3: cmp    eax,0x3c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_1d6:
	/* 0x1d6: je     24c <tracee_syscall_name_table_lookup_xdp+0x24c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d6, 0x24c, x86_l_24c);
x86_l_1d8:
	/* 0x1d8: cmp    eax,0x3d */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_1db:
	/* 0x1db: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1db, 0x2d3, x86_l_2d3);
x86_l_1e1:
	/* 0x1e1: movabs rcx,0x347469617755 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 57674588845909ULL);
x86_l_1eb:
	/* 0x1eb: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x1eb, 0x294, x86_l_294);
x86_l_1f0:
	/* 0x1f0: cmp    eax,0x123 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 291ULL);
x86_l_1f5:
	/* 0x1f5: je     291 <tracee_syscall_name_table_lookup_xdp+0x291> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f5, 0x291, x86_l_291);
x86_l_1fb:
	/* 0x1fb: cmp    eax,0x141 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 321ULL);
x86_l_200:
	/* 0x200: je     253 <tracee_syscall_name_table_lookup_xdp+0x253> */
	X86_SIM_X86_JCC(X86_CC_E, 0x200, 0x253, x86_l_253);
x86_l_202:
	/* 0x202: cmp    eax,0x14c */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 332ULL);
x86_l_207:
	/* 0x207: jne    2d3 <tracee_syscall_name_table_lookup_xdp+0x2d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x207, 0x2d3, x86_l_2d3);
x86_l_20d:
	/* 0x20d: mov    ecx,0x78746173 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2020893043ULL);
x86_l_212:
	/* 0x212: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x212, 0x294, x86_l_294);
x86_l_217:
	/* 0x217: mov    rcx,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_21a:
	/* 0x21a: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x21a, 0x294, x86_l_294);
x86_l_21c:
	/* 0x21c: movabs rcx,0x6b6e696c6e75 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 118121959288437ULL);
x86_l_226:
	/* 0x226: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x226, 0x294, x86_l_294);
x86_l_228:
	/* 0x228: movabs rcx,0x656e6f6c6355 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 111524990182229ULL);
x86_l_232:
	/* 0x232: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x232, 0x294, x86_l_294);
x86_l_234:
	/* 0x234: mov    rcx,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_237:
	/* 0x237: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x237, 0x294, x86_l_294);
x86_l_239:
	/* 0x239: mov    ecx,0x70616d6d */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1885433197ULL);
x86_l_23e:
	/* 0x23e: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x23e, 0x294, x86_l_294);
x86_l_240:
	/* 0x240: movabs rcx,0x786574756655 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 132377140880981ULL);
x86_l_24a:
	/* 0x24a: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x24a, 0x294, x86_l_294);
x86_l_24c:
	/* 0x24c: mov    ecx,0x74697865 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1953069157ULL);
x86_l_251:
	/* 0x251: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x251, 0x294, x86_l_294);
x86_l_253:
	/* 0x253: mov    ecx,0x706662 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7366242ULL);
x86_l_258:
	/* 0x258: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x258, 0x294, x86_l_294);
x86_l_25a:
	/* 0x25a: mov    ecx,0x72656164 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1919246692ULL);
x86_l_25f:
	/* 0x25f: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x25f, 0x294, x86_l_294);
x86_l_261:
	/* 0x261: mov    ecx,0x69646863 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1768188003ULL);
x86_l_266:
	/* 0x266: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x266, 0x294, x86_l_294);
x86_l_268:
	/* 0x268: movabs rcx,0x6469707467 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 431265707111ULL);
x86_l_272:
	/* 0x272: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x272, 0x294, x86_l_294);
x86_l_274:
	/* 0x274: mov    rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_277:
	/* 0x277: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x277, 0x294, x86_l_294);
x86_l_279:
	/* 0x279: movabs rcx,0x6c74635f68637261 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 7814980514819043937ULL);
x86_l_283:
	/* 0x283: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x283, 0x294, x86_l_294);
x86_l_285:
	/* 0x285: movabs rcx,0x657663657865 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 111559148140645ULL);
x86_l_28f:
	/* 0x28f: jmp    294 <tracee_syscall_name_table_lookup_xdp+0x294> */
	X86_SIM_X86_JMP(0x28f, 0x294, x86_l_294);
x86_l_291:
	/* 0x291: mov    rcx,rbp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_294:
	/* 0x294: mov    r12d,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_297:
	/* 0x297: xor    r12,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_29a:
	/* 0x29a: mov    eax,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_29d:
	/* 0x29d: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2a0:
	/* 0x2a0: lea    ecx,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2a3:
	/* 0x2a3: mov    rbx,r12 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_2a6:
	/* 0x2a6: shl    rbx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_2a9:
	/* 0x2a9: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2ab:
	/* 0x2ab: not    cl */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_2ad:
	/* 0x2ad: shr    r12,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_2b0:
	/* 0x2b0: shl    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2b3:
	/* 0x2b3: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2b5:
	/* 0x2b5: shl    r8,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_2b8:
	/* 0x2b8: or     r12,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_2bb:
	/* 0x2bb: add    r12,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_2be:
	/* 0x2be: xor    r8,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R12, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_2c1:
	/* 0x2c1: mov    r11,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_2c4:
	/* 0x2c4: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2c7:
	/* 0x2c7: cmp    r9,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_2cb:
	/* 0x2cb: jne    80 <tracee_syscall_name_table_lookup_xdp+0x80> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2cb, 0x80, x86_l_80);
x86_l_2d1:
	/* 0x2d1: jmp    2f3 <tracee_syscall_name_table_lookup_xdp+0x2f3> */
	X86_SIM_X86_JMP(0x2d1, 0x2f3, x86_l_2f3);
x86_l_2d3:
	/* 0x2d3: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_2d5:
	/* 0x2d5: movabs rcx,0x9e3779b185ebca87 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714785074694791ULL);
x86_l_2df:
	/* 0x2df: imul   rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_2e3:
	/* 0x2e3: xor    r11,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_2e6:
	/* 0x2e6: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e9:
	/* 0x2e9: cmp    r9,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_2ed:
	/* 0x2ed: jne    80 <tracee_syscall_name_table_lookup_xdp+0x80> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ed, 0x80, x86_l_80);
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rdx],r11 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f6:
	/* 0x2f6: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_2fb:
	/* 0x2fb: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2fc:
	/* 0x2fc: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2fe:
	/* 0x2fe: pop    r13 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_300:
	/* 0x300: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_302:
	/* 0x302: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_304:
	/* 0x304: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_305:
	/* 0x305: jmp    30a <tracee_syscall_name_table_lookup_xdp+0x30a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_30a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
