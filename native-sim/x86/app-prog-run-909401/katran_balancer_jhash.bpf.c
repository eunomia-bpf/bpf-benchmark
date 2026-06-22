#include "../x86_sim_local_bpf.h"

SEC("xdp")
int katran_balancer_jhash_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2:
	/* 0x2: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5:
	/* 0x5: lea    edx,[rcx-0x21523f01] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073150513407ULL);
x86_l_b:
	/* 0xb: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e:
	/* 0xe: sub    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_10:
	/* 0x10: lea    r8d,[rsi-0x21523f01] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073150513407ULL);
x86_l_17:
	/* 0x17: rorx   r8d,r8d,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_R8, X86_WIDTH_32, 0, 28ULL);
x86_l_1d:
	/* 0x1d: xor    r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20:
	/* 0x20: sub    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23:
	/* 0x23: rorx   eax,r8d,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_R8, X86_WIDTH_32, 0, 26ULL);
x86_l_29:
	/* 0x29: xor    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b:
	/* 0x2b: add    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d:
	/* 0x2d: add    ecx,0xbd5b81fe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 3176890878ULL);
x86_l_33:
	/* 0x33: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36:
	/* 0x36: lea    esi,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3a:
	/* 0x3a: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3c:
	/* 0x3c: rorx   r9d,eax,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RAX, X86_WIDTH_32, 0, 24ULL);
x86_l_42:
	/* 0x42: xor    r9d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45:
	/* 0x45: sub    r8d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_48:
	/* 0x48: rorx   edx,r9d,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R9, X86_WIDTH_32, 0, 16ULL);
x86_l_4e:
	/* 0x4e: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51:
	/* 0x51: add    r9d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_54:
	/* 0x54: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56:
	/* 0x56: rorx   ecx,edx,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDX, X86_WIDTH_32, 0, 13ULL);
x86_l_5c:
	/* 0x5c: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e:
	/* 0x5e: add    edx,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_61:
	/* 0x61: lea    eax,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_64:
	/* 0x64: sub    r9d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_67:
	/* 0x67: rorx   ecx,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_6d:
	/* 0x6d: xor    ecx,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_70:
	/* 0x70: movzx  esi,BYTE PTR [rdi+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_74:
	/* 0x74: shl    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_77:
	/* 0x77: movzx  r8d,BYTE PTR [rdi+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_7c:
	/* 0x7c: shl    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_80:
	/* 0x80: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_83:
	/* 0x83: movzx  r9d,BYTE PTR [rdi+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_88:
	/* 0x88: shl    r9d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_8c:
	/* 0x8c: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8f:
	/* 0x8f: movzx  esi,BYTE PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_93:
	/* 0x93: add    esi,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_96:
	/* 0x96: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_98:
	/* 0x98: xor    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a:
	/* 0x9a: rorx   edx,eax,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 18ULL);
x86_l_a0:
	/* 0xa0: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a2:
	/* 0xa2: xor    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a4:
	/* 0xa4: rorx   edx,ecx,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 21ULL);
x86_l_aa:
	/* 0xaa: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ac:
	/* 0xac: xor    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae:
	/* 0xae: rorx   edx,esi,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 7ULL);
x86_l_b4:
	/* 0xb4: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b6:
	/* 0xb6: xor    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b8:
	/* 0xb8: rorx   edx,eax,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 16ULL);
x86_l_be:
	/* 0xbe: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c0:
	/* 0xc0: xor    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c2:
	/* 0xc2: rorx   edx,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_c8:
	/* 0xc8: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ca:
	/* 0xca: xor    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc:
	/* 0xcc: rorx   edx,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_d2:
	/* 0xd2: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_d4:
	/* 0xd4: rorx   edx,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_da:
	/* 0xda: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dc:
	/* 0xdc: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_de:
	/* 0xde: jmp    e3 <jhash+0xe3> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_e3:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
