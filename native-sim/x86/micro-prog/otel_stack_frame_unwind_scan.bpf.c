#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int otel_stack_frame_unwind_scan_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <otel_stack_frame_unwind_scan_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    187 <otel_stack_frame_unwind_scan_xdp+0x187> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <otel_stack_frame_unwind_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rsi+0x250] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <otel_stack_frame_unwind_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rsi+0x8],0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738392ULL);
x86_l_2f:
	/* 0x2f: jne    11 <otel_stack_frame_unwind_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rsi+0xc],0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_35:
	/* 0x35: jne    11 <otel_stack_frame_unwind_scan_xdp+0x11> */
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
	/* 0x3c: push   r12 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_3e:
	/* 0x3e: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_3f:
	/* 0x3f: add    rsi,0x27 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_43:
	/* 0x43: movabs rax,0x100000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 4294967296ULL);
x86_l_4d:
	/* 0x4d: movabs r9,0x589965cc75374cc3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 6384245875588680899ULL);
x86_l_57:
	/* 0x57: xor    edi,edi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_59:
	/* 0x59: mov    r8d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_5f:
	/* 0x5f: jmp    7c <otel_stack_frame_unwind_scan_xdp+0x7c> */
	X86_SIM_X86_JMP(0x5f, 0x7c, x86_l_7c);
x86_l_61:
	/* 0x61: shl    rcx,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_65:
	/* 0x65: or     rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_68:
	/* 0x68: xor    r9,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_6b:
	/* 0x6b: inc    rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6e:
	/* 0x6e: add    rsi,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_72:
	/* 0x72: cmp    rdi,0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, 0, 24ULL);
x86_l_76:
	/* 0x76: je     172 <otel_stack_frame_unwind_scan_xdp+0x172> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x172, x86_l_172);
x86_l_7c:
	/* 0x7c: mov    rbx,QWORD PTR [rsi-0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_80:
	/* 0x80: mov    ebp,DWORD PTR [rsi-0xf] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_83:
	/* 0x83: mov    r14d,DWORD PTR [rsi-0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_87:
	/* 0x87: movzx  r11d,WORD PTR [rsi-0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551609ULL);
x86_l_8c:
	/* 0x8c: movzx  ecx,WORD PTR [rsi-0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_90:
	/* 0x90: mov    r10d,DWORD PTR [rsi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_94:
	/* 0x94: cmp    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_97:
	/* 0x97: jg     b2 <otel_stack_frame_unwind_scan_xdp+0xb2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x97, 0xb2, x86_l_b2);
x86_l_99:
	/* 0x99: test   ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_9b:
	/* 0x9b: je     cc <otel_stack_frame_unwind_scan_xdp+0xcc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b, 0xcc, x86_l_cc);
x86_l_9d:
	/* 0x9d: cmp    ecx,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_a0:
	/* 0xa0: jne    61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa0, 0x61, x86_l_61);
x86_l_a2:
	/* 0xa2: mov    r15d,0x35 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_a8:
	/* 0xa8: cmp    ebp,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_ae:
	/* 0xae: jbe    ee <otel_stack_frame_unwind_scan_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xae, 0xee, x86_l_ee);
x86_l_b0:
	/* 0xb0: jmp    61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JMP(0xb0, 0x61, x86_l_61);
x86_l_b2:
	/* 0xb2: cmp    ecx,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_b5:
	/* 0xb5: je     dc <otel_stack_frame_unwind_scan_xdp+0xdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5, 0xdc, x86_l_dc);
x86_l_b7:
	/* 0xb7: cmp    ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_ba:
	/* 0xba: jne    61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba, 0x61, x86_l_61);
x86_l_bc:
	/* 0xbc: mov    r15d,0x89 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 137ULL);
x86_l_c2:
	/* 0xc2: cmp    ebp,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_c8:
	/* 0xc8: jbe    ee <otel_stack_frame_unwind_scan_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xc8, 0xee, x86_l_ee);
x86_l_ca:
	/* 0xca: jmp    61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JMP(0xca, 0x61, x86_l_61);
x86_l_cc:
	/* 0xcc: mov    r15d,0x21 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_d2:
	/* 0xd2: cmp    ebp,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_d8:
	/* 0xd8: jbe    ee <otel_stack_frame_unwind_scan_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd8, 0xee, x86_l_ee);
x86_l_da:
	/* 0xda: jmp    61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JMP(0xda, 0x61, x86_l_61);
x86_l_dc:
	/* 0xdc: mov    r15d,0x55 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 85ULL);
x86_l_e2:
	/* 0xe2: cmp    ebp,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_e8:
	/* 0xe8: ja     61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe8, 0x61, x86_l_61);
x86_l_ee:
	/* 0xee: cmp    r14d,0x2001 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 8193ULL);
x86_l_f5:
	/* 0xf5: jae    61 <otel_stack_frame_unwind_scan_xdp+0x61> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf5, 0x61, x86_l_61);
x86_l_fb:
	/* 0xfb: test   r11b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_ff:
	/* 0xff: mov    r12d,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_102:
	/* 0x102: cmove  r12d,r8d */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R8, X86_WIDTH_32, X86_CC_E, 0);
x86_l_106:
	/* 0x106: add    r12d,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_109:
	/* 0x109: add    rax,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_10c:
	/* 0x10c: mov    r12,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_10f:
	/* 0x10f: shl    r12,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_113:
	/* 0x113: or     r15,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_116:
	/* 0x116: xor    rbx,r15 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_119:
	/* 0x119: xor    rbx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c:
	/* 0x11c: test   r11b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_120:
	/* 0x120: je     127 <otel_stack_frame_unwind_scan_xdp+0x127> */
	X86_SIM_X86_JCC(X86_CC_E, 0x120, 0x127, x86_l_127);
x86_l_122:
	/* 0x122: inc    cl */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_124:
	/* 0x124: rol    rbx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_127:
	/* 0x127: mov    ecx,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_12a:
	/* 0x12a: shl    rcx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 24ULL);
x86_l_12e:
	/* 0x12e: mov    r14d,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_131:
	/* 0x131: xor    r14,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_134:
	/* 0x134: test   r11b,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_138:
	/* 0x138: mov    ecx,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_13d:
	/* 0x13d: cmovne rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RCX, X86_R14, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_141:
	/* 0x141: add    rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_144:
	/* 0x144: mov    ebx,edi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RBX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_146:
	/* 0x146: and    bl,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_149:
	/* 0x149: lea    r14d,[rbx+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_14d:
	/* 0x14d: shlx   r14,rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RCX, X86_WIDTH_64, X86_R14, X86_ALU_SHL);
x86_l_152:
	/* 0x152: not    bl */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_154:
	/* 0x154: shrx   rcx,rcx,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RBX, X86_ALU_SHR);
x86_l_159:
	/* 0x159: or     rcx,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_15c:
	/* 0x15c: add    rcx,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_15f:
	/* 0x15f: movzx  r9d,r11w */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_R9, X86_R11, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_163:
	/* 0x163: shl    r9,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_167:
	/* 0x167: or     r10,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_16a:
	/* 0x16a: mov    r9,r10 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R9, X86_R10, X86_WIDTH_64, 0, 0);
x86_l_16d:
	/* 0x16d: jmp    68 <otel_stack_frame_unwind_scan_xdp+0x68> */
	X86_SIM_X86_JMP(0x16d, 0x68, x86_l_68);
x86_l_172:
	/* 0x172: mov    QWORD PTR [rdx],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_175:
	/* 0x175: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_17a:
	/* 0x17a: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_17b:
	/* 0x17b: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_17d:
	/* 0x17d: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_17f:
	/* 0x17f: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_181:
	/* 0x181: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_182:
	/* 0x182: jmp    187 <otel_stack_frame_unwind_scan_xdp+0x187> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_187:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
