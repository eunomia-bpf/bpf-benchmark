#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_ct_nat_tuple_rewrite_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <cilium_ct_nat_tuple_rewrite_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    171 <cilium_ct_nat_tuple_rewrite_xdp+0x171> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <cilium_ct_nat_tuple_rewrite_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x410] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <cilium_ct_nat_tuple_rewrite_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    11 <cilium_ct_nat_tuple_rewrite_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdx+0xc],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_35:
	/* 0x35: jne    11 <cilium_ct_nat_tuple_rewrite_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_38:
	/* 0x38: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3a:
	/* 0x3a: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3c:
	/* 0x3c: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3e:
	/* 0x3e: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3f:
	/* 0x3f: add    rdx,0x2f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 47ULL);
x86_l_43:
	/* 0x43: movabs rax,0x8ebc6af09c88c6e3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 10285213230658275043ULL);
x86_l_4d:
	/* 0x4d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f:
	/* 0x4f: jmp    d4 <cilium_ct_nat_tuple_rewrite_xdp+0xd4> */
	X86_SIM_X86_JMP(0x4f, 0xd4, x86_l_d4);
x86_l_54:
	/* 0x54: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_57:
	/* 0x57: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_5a:
	/* 0x5a: rorx   r15d,ebp,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R15, X86_RBP, X86_WIDTH_32, 0, 21ULL);
x86_l_60:
	/* 0x60: shl    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_64:
	/* 0x64: xor    r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67:
	/* 0x67: movzx  r15d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_6b:
	/* 0x6b: shl    r10d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_6f:
	/* 0x6f: or     r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_72:
	/* 0x72: xor    r9d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75:
	/* 0x75: xor    r9d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_78:
	/* 0x78: xor    r9d,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b:
	/* 0x7b: shl    r11d,0x1d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHL, 29ULL);
x86_l_7f:
	/* 0x7f: sar    r11d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_83:
	/* 0x83: shl    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_86:
	/* 0x86: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_89:
	/* 0x89: and    edi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_32, X86_ALU_AND);
x86_l_8c:
	/* 0x8c: add    edi,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8f:
	/* 0x8f: shl    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_93:
	/* 0x93: mov    r8d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R8, X86_WIDTH_32);
x86_l_96:
	/* 0x96: add    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_99:
	/* 0x99: add    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9c:
	/* 0x9c: shl    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_a0:
	/* 0xa0: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_a2:
	/* 0xa2: or     rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_a5:
	/* 0xa5: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_a8:
	/* 0xa8: and    r8d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ac:
	/* 0xac: lea    r9d,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_b0:
	/* 0xb0: shlx   r9,rdi,r9 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R9, X86_RDI, X86_WIDTH_64, X86_R9, X86_ALU_SHL);
x86_l_b5:
	/* 0xb5: not    r8b */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_b8:
	/* 0xb8: shrx   rdi,rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDI, X86_RDI, X86_WIDTH_64, X86_R8, X86_ALU_SHR);
x86_l_bd:
	/* 0xbd: or     rdi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_c0:
	/* 0xc0: xor    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_c3:
	/* 0xc3: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_c6:
	/* 0xc6: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_ca:
	/* 0xca: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_ce:
	/* 0xce: je     15c <cilium_ct_nat_tuple_rewrite_xdp+0x15c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce, 0x15c, x86_l_15c);
x86_l_d4:
	/* 0xd4: movzx  r10d,BYTE PTR [rdx-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551597ULL);
x86_l_d9:
	/* 0xd9: movzx  edi,WORD PTR [rdx-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551609ULL);
x86_l_dd:
	/* 0xdd: movzx  r9d,WORD PTR [rdx-0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551611ULL);
x86_l_e2:
	/* 0xe2: mov    r8d,DWORD PTR [rdx-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_e6:
	/* 0xe6: cmp    r10d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 6ULL);
x86_l_ea:
	/* 0xea: je     f2 <cilium_ct_nat_tuple_rewrite_xdp+0xf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea, 0xf2, x86_l_f2);
x86_l_ec:
	/* 0xec: cmp    r10d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 17ULL);
x86_l_f0:
	/* 0xf0: jne    14d <cilium_ct_nat_tuple_rewrite_xdp+0x14d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf0, 0x14d, x86_l_14d);
x86_l_f2:
	/* 0xf2: lea    rbx,[rdx-0xb] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_f6:
	/* 0xf6: lea    r14,[rdx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_fa:
	/* 0xfa: movzx  r11d,BYTE PTR [rdx-0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551599ULL);
x86_l_ff:
	/* 0xff: lea    r12,[rdx-0x1b] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551589ULL);
x86_l_103:
	/* 0x103: lea    r15,[rdx-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_107:
	/* 0x107: mov    ebp,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_32);
x86_l_10a:
	/* 0x10a: and    ebp,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_10d:
	/* 0x10d: cmovne ebp,edi */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_110:
	/* 0x110: cmovne r15,r14 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R14, X86_WIDTH_64, X86_CC_NE);
x86_l_114:
	/* 0x114: xor    bp,WORD PTR [rdx-0x17] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RDX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551593ULL);
x86_l_118:
	/* 0x118: mov    r15d,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b:
	/* 0x11b: mov    r14d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R11, X86_WIDTH_32);
x86_l_11e:
	/* 0x11e: and    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_122:
	/* 0x122: cmovne r14d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_126:
	/* 0x126: cmovne r12,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_12a:
	/* 0x12a: xor    r14w,WORD PTR [rdx-0x15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RDX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551595ULL);
x86_l_12f:
	/* 0x12f: mov    ebx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133:
	/* 0x133: test   BYTE PTR [rdx-0x12],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446743996400140289ULL);
x86_l_137:
	/* 0x137: jne    54 <cilium_ct_nat_tuple_rewrite_xdp+0x54> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x137, 0x54, x86_l_54);
x86_l_13d:
	/* 0x13d: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_140:
	/* 0x140: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_143:
	/* 0x143: mov    ebp,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_32);
x86_l_145:
	/* 0x145: mov    ebx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_32);
x86_l_148:
	/* 0x148: jmp    5a <cilium_ct_nat_tuple_rewrite_xdp+0x5a> */
	X86_SIM_X86_JMP(0x148, 0x5a, x86_l_5a);
x86_l_14d:
	/* 0x14d: shl    r10,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 56ULL);
x86_l_151:
	/* 0x151: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_154:
	/* 0x154: or     rdi,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_157:
	/* 0x157: jmp    c0 <cilium_ct_nat_tuple_rewrite_xdp+0xc0> */
	X86_SIM_X86_JMP(0x157, 0xc0, x86_l_c0);
x86_l_15c:
	/* 0x15c: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f:
	/* 0x15f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_164:
	/* 0x164: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_165:
	/* 0x165: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_167:
	/* 0x167: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_169:
	/* 0x169: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_16c:
	/* 0x16c: jmp    171 <cilium_ct_nat_tuple_rewrite_xdp+0x171> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_171:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
