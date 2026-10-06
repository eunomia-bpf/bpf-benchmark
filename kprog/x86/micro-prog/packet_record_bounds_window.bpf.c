#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int packet_record_bounds_window_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <packet_record_bounds_window_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    108 <packet_record_bounds_window_xdp+0x108> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <packet_record_bounds_window_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdi,[rdx+0x310] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_26:
	/* 0x26: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <packet_record_bounds_window_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_2f:
	/* 0x2f: jne    11 <packet_record_bounds_window_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdx+0xc],0x18 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_35:
	/* 0x35: jne    11 <packet_record_bounds_window_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35, 0x11, x86_l_11);
x86_l_37:
	/* 0x37: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_39:
	/* 0x39: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3a:
	/* 0x3a: add    rdx,0x27 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_3e:
	/* 0x3e: movabs r9,0xd6e8feb86659fd93 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 15485907386658061715ULL);
x86_l_48:
	/* 0x48: mov    eax,0x300 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 768ULL);
x86_l_4d:
	/* 0x4d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f:
	/* 0x4f: jmp    ac <packet_record_bounds_window_xdp+0xac> */
	X86_SIM_X86_JMP(0x4f, 0xac, x86_l_ac);
x86_l_51:
	/* 0x51: shl    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_55:
	/* 0x55: mov    r11d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R11, X86_WIDTH_32);
x86_l_58:
	/* 0x58: or     r11,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_5b:
	/* 0x5b: add    r10,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e:
	/* 0x5e: movzx  r11d,WORD PTR [rdx-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551615ULL);
x86_l_63:
	/* 0x63: lea    ebx,[rdi*4+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_6a:
	/* 0x6a: and    bl,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_8, X86_ALU_AND, 28ULL);
x86_l_6d:
	/* 0x6d: shlx   r9,r9,rbx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R9, X86_R9, X86_WIDTH_64, X86_RBX, X86_ALU_SHL);
x86_l_72:
	/* 0x72: xor    r9,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_XOR);
x86_l_75:
	/* 0x75: mov    r10d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RSI, X86_WIDTH_32);
x86_l_78:
	/* 0x78: and    r10b,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_8, X86_ALU_AND, 24ULL);
x86_l_7c:
	/* 0x7c: shlx   r10,r11,r10 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R10, X86_R11, X86_WIDTH_64, X86_R10, X86_ALU_SHL);
x86_l_81:
	/* 0x81: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_84:
	/* 0x84: and    edi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_87:
	/* 0x87: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a:
	/* 0x8a: lea    r8d,[rdi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_8e:
	/* 0x8e: shlx   r8,r10,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R8, X86_R10, X86_WIDTH_64, X86_R8, X86_ALU_SHL);
x86_l_93:
	/* 0x93: not    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_96:
	/* 0x96: shrx   r9,r10,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R9, X86_R10, X86_WIDTH_64, X86_RDI, X86_ALU_SHR);
x86_l_9b:
	/* 0x9b: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_9e:
	/* 0x9e: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a2:
	/* 0xa2: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a6:
	/* 0xa6: add    rax,0xffffffffffffffe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551592ULL);
x86_l_aa:
	/* 0xaa: je     f8 <packet_record_bounds_window_xdp+0xf8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa, 0xf8, x86_l_f8);
x86_l_ac:
	/* 0xac: movzx  r8d,BYTE PTR [rdx-0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551593ULL);
x86_l_b1:
	/* 0xb1: and    r8d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 3ULL);
x86_l_b5:
	/* 0xb5: lea    rdi,[r8+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b9:
	/* 0xb9: cmp    rax,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDI, X86_WIDTH_64);
x86_l_bc:
	/* 0xbc: jb     9e <packet_record_bounds_window_xdp+0x9e> */
	X86_SIM_X86_JCC(X86_CC_B, 0xbc, 0x9e, x86_l_9e);
x86_l_be:
	/* 0xbe: movzx  edi,BYTE PTR [rdx-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551594ULL);
x86_l_c2:
	/* 0xc2: mov    r14d,DWORD PTR [rdx-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_c6:
	/* 0xc6: mov    ebx,DWORD PTR [rdx-0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_c9:
	/* 0xc9: mov    r11d,DWORD PTR [rdx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_cd:
	/* 0xcd: movzx  r10d,WORD PTR [rdx-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551613ULL);
x86_l_d2:
	/* 0xd2: add    r14,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d5:
	/* 0xd5: add    r10,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d8:
	/* 0xd8: add    r10,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_db:
	/* 0xdb: mov    r9d,DWORD PTR [rdx-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551609ULL);
x86_l_df:
	/* 0xdf: test   dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_e3:
	/* 0xe3: je     51 <packet_record_bounds_window_xdp+0x51> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe3, 0x51, x86_l_51);
x86_l_e9:
	/* 0xe9: shl    r11,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_ed:
	/* 0xed: or     r11,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_f0:
	/* 0xf0: xor    r10,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_64, X86_ALU_XOR);
x86_l_f3:
	/* 0xf3: jmp    5e <packet_record_bounds_window_xdp+0x5e> */
	X86_SIM_X86_JMP(0xf3, 0x5e, x86_l_5e);
x86_l_f8:
	/* 0xf8: mov    QWORD PTR [rcx],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb:
	/* 0xfb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_100:
	/* 0x100: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_101:
	/* 0x101: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_103:
	/* 0x103: jmp    108 <packet_record_bounds_window_xdp+0x108> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_108:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
