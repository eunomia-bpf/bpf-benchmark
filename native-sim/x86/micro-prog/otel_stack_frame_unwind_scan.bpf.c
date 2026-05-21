#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int otel_stack_frame_unwind_scan_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rsi,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    16 <otel_stack_frame_unwind_scan_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    189 <otel_stack_frame_unwind_scan_xdp+0x189> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdx,[rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <otel_stack_frame_unwind_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdx,[rdi+0x250] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_26:
	/* 0x26: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <otel_stack_frame_unwind_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi+0x8],0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738392ULL);
x86_l_2f:
	/* 0x2f: jne    11 <otel_stack_frame_unwind_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdi+0xc],0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
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
	/* 0x3f: add    rdi,0x27 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_43:
	/* 0x43: movabs r8,0x100000000 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 4294967296ULL);
x86_l_4d:
	/* 0x4d: movabs r11,0x589965cc75374cc3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 6384245875588680899ULL);
x86_l_57:
	/* 0x57: xor    r9d,r9d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_5a:
	/* 0x5a: mov    r10d,0x8 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_32, 0, 8ULL);
x86_l_60:
	/* 0x60: jmp    7d <otel_stack_frame_unwind_scan_xdp+0x7d> */
	X86_SIM_X86_JMP(0x60, 0x7d, x86_l_7d);
x86_l_62:
	/* 0x62: shl    rax,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_66:
	/* 0x66: or     rax,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_69:
	/* 0x69: xor    r11,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_6c:
	/* 0x6c: inc    r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6f:
	/* 0x6f: add    rdi,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_73:
	/* 0x73: cmp    r9,0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 24ULL);
x86_l_77:
	/* 0x77: je     174 <otel_stack_frame_unwind_scan_xdp+0x174> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77, 0x174, x86_l_174);
x86_l_7d:
	/* 0x7d: mov    rdx,QWORD PTR [rdi-0x17] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551593ULL);
x86_l_81:
	/* 0x81: mov    r14d,DWORD PTR [rdi-0xf] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_85:
	/* 0x85: mov    r15d,DWORD PTR [rdi-0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_89:
	/* 0x89: movzx  ebp,WORD PTR [rdi-0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551609ULL);
x86_l_8d:
	/* 0x8d: movzx  eax,WORD PTR [rdi-0x5] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_91:
	/* 0x91: mov    ebx,DWORD PTR [rdi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_94:
	/* 0x94: cmp    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_97:
	/* 0x97: jg     b2 <otel_stack_frame_unwind_scan_xdp+0xb2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x97, 0xb2, x86_l_b2);
x86_l_99:
	/* 0x99: test   eax,eax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_9b:
	/* 0x9b: je     cc <otel_stack_frame_unwind_scan_xdp+0xcc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b, 0xcc, x86_l_cc);
x86_l_9d:
	/* 0x9d: cmp    eax,0x1 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_a0:
	/* 0xa0: jne    62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa0, 0x62, x86_l_62);
x86_l_a2:
	/* 0xa2: mov    ecx,0x35 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 53ULL);
x86_l_a7:
	/* 0xa7: cmp    r14d,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_ae:
	/* 0xae: jbe    ee <otel_stack_frame_unwind_scan_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xae, 0xee, x86_l_ee);
x86_l_b0:
	/* 0xb0: jmp    62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JMP(0xb0, 0x62, x86_l_62);
x86_l_b2:
	/* 0xb2: cmp    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_b5:
	/* 0xb5: je     dc <otel_stack_frame_unwind_scan_xdp+0xdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5, 0xdc, x86_l_dc);
x86_l_b7:
	/* 0xb7: cmp    eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_ba:
	/* 0xba: jne    62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba, 0x62, x86_l_62);
x86_l_bc:
	/* 0xbc: mov    ecx,0x89 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 137ULL);
x86_l_c1:
	/* 0xc1: cmp    r14d,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_c8:
	/* 0xc8: jbe    ee <otel_stack_frame_unwind_scan_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xc8, 0xee, x86_l_ee);
x86_l_ca:
	/* 0xca: jmp    62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JMP(0xca, 0x62, x86_l_62);
x86_l_cc:
	/* 0xcc: mov    ecx,0x21 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 33ULL);
x86_l_d1:
	/* 0xd1: cmp    r14d,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_d8:
	/* 0xd8: jbe    ee <otel_stack_frame_unwind_scan_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd8, 0xee, x86_l_ee);
x86_l_da:
	/* 0xda: jmp    62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JMP(0xda, 0x62, x86_l_62);
x86_l_dc:
	/* 0xdc: mov    ecx,0x55 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 85ULL);
x86_l_e1:
	/* 0xe1: cmp    r14d,0x1000 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, 0, 4096ULL);
x86_l_e8:
	/* 0xe8: ja     62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe8, 0x62, x86_l_62);
x86_l_ee:
	/* 0xee: cmp    r15d,0x2001 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 8193ULL);
x86_l_f5:
	/* 0xf5: jae    62 <otel_stack_frame_unwind_scan_xdp+0x62> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf5, 0x62, x86_l_62);
x86_l_fb:
	/* 0xfb: test   bpl,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_ff:
	/* 0xff: mov    r12d,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_102:
	/* 0x102: cmove  r12d,r10d */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_R12, X86_R10, X86_WIDTH_32, X86_CC_E, 0);
x86_l_106:
	/* 0x106: add    r12d,r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_109:
	/* 0x109: add    r8,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R12, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_10c:
	/* 0x10c: mov    r12,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R12, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_10f:
	/* 0x10f: shl    r12,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_113:
	/* 0x113: or     rcx,r12 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_116:
	/* 0x116: xor    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_119:
	/* 0x119: xor    rdx,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11c:
	/* 0x11c: test   bpl,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_120:
	/* 0x120: je     129 <otel_stack_frame_unwind_scan_xdp+0x129> */
	X86_SIM_X86_JCC(X86_CC_E, 0x120, 0x129, x86_l_129);
x86_l_122:
	/* 0x122: inc    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_124:
	/* 0x124: mov    ecx,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_126:
	/* 0x126: rol    rdx,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ROL, 0);
x86_l_129:
	/* 0x129: mov    eax,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_12c:
	/* 0x12c: shl    rax,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 24ULL);
x86_l_130:
	/* 0x130: mov    ecx,r14d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_32, 0, 0);
x86_l_133:
	/* 0x133: xor    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_136:
	/* 0x136: test   bpl,0x4 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, 0, 4ULL);
x86_l_13a:
	/* 0x13a: mov    eax,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_13f:
	/* 0x13f: cmovne rax,rcx */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RAX, X86_RCX, X86_WIDTH_64, X86_CC_NE, 0);
x86_l_143:
	/* 0x143: add    rax,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_146:
	/* 0x146: mov    edx,r9d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_R9, X86_WIDTH_32, 0, 0);
x86_l_149:
	/* 0x149: and    dl,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_14c:
	/* 0x14c: lea    ecx,[rdx+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_14f:
	/* 0x14f: mov    r14,rax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R14, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_152:
	/* 0x152: shl    r14,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_155:
	/* 0x155: not    dl */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_157:
	/* 0x157: mov    ecx,edx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 0);
x86_l_159:
	/* 0x159: shr    rax,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_15c:
	/* 0x15c: or     rax,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_15f:
	/* 0x15f: add    rax,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_162:
	/* 0x162: movzx  ecx,bp */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_165:
	/* 0x165: shl    rcx,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_169:
	/* 0x169: or     rbx,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_16c:
	/* 0x16c: mov    r11,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_16f:
	/* 0x16f: jmp    69 <otel_stack_frame_unwind_scan_xdp+0x69> */
	X86_SIM_X86_JMP(0x16f, 0x69, x86_l_69);
x86_l_174:
	/* 0x174: mov    QWORD PTR [rsi],r11 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSI, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_177:
	/* 0x177: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_17c:
	/* 0x17c: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_17d:
	/* 0x17d: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_17f:
	/* 0x17f: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_181:
	/* 0x181: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_183:
	/* 0x183: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_184:
	/* 0x184: jmp    189 <otel_stack_frame_unwind_scan_xdp+0x189> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_189:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
