#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int flow_record_field_scan_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xf: jbe    16 <flow_record_field_scan_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    129 <flow_record_field_scan_xdp+0x129> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <flow_record_field_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0x410] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <flow_record_field_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e:
	/* 0x2e: jne    11 <flow_record_field_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e, 0x11, x86_l_11);
x86_l_30:
	/* 0x30: cmp    DWORD PTR [rdx+0xc],0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_34:
	/* 0x34: jne    11 <flow_record_field_scan_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34, 0x11, x86_l_11);
x86_l_36:
	/* 0x36: push   r14 */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_38:
	/* 0x38: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_39:
	/* 0x39: movabs r8,0x9e3779b97f4a7c15 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 11400714819323198485ULL);
x86_l_43:
	/* 0x43: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_45:
	/* 0x45: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_47:
	/* 0x47: jmp    8f <flow_record_field_scan_xdp+0x8f> */
	X86_SIM_X86_JMP(0x47, 0x8f, x86_l_8f);
x86_l_49:
	/* 0x49: mov    r8d,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4c:
	/* 0x4c: and    r8b,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_50:
	/* 0x50: shrx   r8,r10,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R8, X86_R10, X86_WIDTH_64, X86_R8, X86_ALU_SHR);
x86_l_55:
	/* 0x55: xor    r9,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_58:
	/* 0x58: add    r9,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_5b:
	/* 0x5b: mov    r8d,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R8, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_5e:
	/* 0x5e: and    r8b,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 24ULL);
x86_l_62:
	/* 0x62: shlx   r8,rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R8, X86_RDI, X86_WIDTH_64, X86_R8, X86_ALU_SHL);
x86_l_67:
	/* 0x67: xor    r8,r9 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_6a:
	/* 0x6a: and    dil,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_6e:
	/* 0x6e: lea    r9d,[rdi+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_72:
	/* 0x72: shlx   rbx,r8,r9 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RBX, X86_R8, X86_WIDTH_64, X86_R9, X86_ALU_SHL);
x86_l_77:
	/* 0x77: not    dil */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_7a:
	/* 0x7a: shrx   r8,r8,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R8, X86_R8, X86_WIDTH_64, X86_RDI, X86_ALU_SHR);
x86_l_7f:
	/* 0x7f: or     r8,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_RBX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_82:
	/* 0x82: inc    rsi */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_85:
	/* 0x85: add    rax,0x8 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_89:
	/* 0x89: cmp    rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 32ULL);
x86_l_8d:
	/* 0x8d: je     e1 <flow_record_field_scan_xdp+0xe1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d, 0xe1, x86_l_e1);
x86_l_8f:
	/* 0x8f: mov    r10,QWORD PTR [rdx+rax*4+0x20] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R10, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 32ULL);
x86_l_94:
	/* 0x94: mov    rbx,QWORD PTR [rdx+rax*4+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 24ULL);
x86_l_99:
	/* 0x99: add    rbx,r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_9c:
	/* 0x9c: mov    edi,DWORD PTR [rdx+rax*4+0x28] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 40ULL);
x86_l_a0:
	/* 0xa0: shl    rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_a4:
	/* 0xa4: mov    r9d,DWORD PTR [rdx+rax*4+0x2c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 44ULL);
x86_l_a9:
	/* 0xa9: or     r9,rdi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_ac:
	/* 0xac: mov    edi,DWORD PTR [rdx+rax*4+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_b0:
	/* 0xb0: mov    r11,rdi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_b3:
	/* 0xb3: shl    r11,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_b7:
	/* 0xb7: movzx  r14d,WORD PTR [rdx+rax*4+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_16), 20ULL);
x86_l_bd:
	/* 0xbd: or     r11,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_c0:
	/* 0xc0: xor    r11,rbx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_c3:
	/* 0xc3: add    r11,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_c6:
	/* 0xc6: test   r14b,0x1 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, 0, 1ULL);
x86_l_ca:
	/* 0xca: je     49 <flow_record_field_scan_xdp+0x49> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca, 0x49, x86_l_49);
x86_l_d0:
	/* 0xd0: movzx  r8d,WORD PTR [rdx+rax*4+0x16] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_16), 22ULL);
x86_l_d6:
	/* 0xd6: add    r9,r8 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_d9:
	/* 0xd9: xor    r9,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_dc:
	/* 0xdc: jmp    5b <flow_record_field_scan_xdp+0x5b> */
	X86_SIM_X86_JMP(0xdc, 0x5b, x86_l_5b);
x86_l_e1:
	/* 0xe1: mov    BYTE PTR [rcx],r8b */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4:
	/* 0xe4: mov    BYTE PTR [rcx+0x1],bh */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_e7:
	/* 0xe7: mov    eax,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_e9:
	/* 0xe9: shr    eax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ec:
	/* 0xec: mov    BYTE PTR [rcx+0x2],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_ef:
	/* 0xef: mov    eax,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_f1:
	/* 0xf1: shr    eax,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_f4:
	/* 0xf4: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_f7:
	/* 0xf7: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_fa:
	/* 0xfa: shr    rax,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_fe:
	/* 0xfe: mov    BYTE PTR [rcx+0x4],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_101:
	/* 0x101: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_104:
	/* 0x104: shr    rax,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_108:
	/* 0x108: mov    BYTE PTR [rcx+0x5],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_10b:
	/* 0x10b: mov    rax,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_10e:
	/* 0x10e: shr    rax,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_112:
	/* 0x112: mov    BYTE PTR [rcx+0x6],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_115:
	/* 0x115: shr    rbx,0x38 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_119:
	/* 0x119: mov    BYTE PTR [rcx+0x7],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_11c:
	/* 0x11c: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_121:
	/* 0x121: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_122:
	/* 0x122: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_124:
	/* 0x124: jmp    129 <flow_record_field_scan_xdp+0x129> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_129:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
