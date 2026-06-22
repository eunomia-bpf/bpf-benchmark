extern char argfilter_maps;
extern char heap_ro_zero;
extern char string_maps_0;
extern char string_maps_1;
extern char string_maps_10;
extern char string_maps_2;
extern char string_maps_3;
extern char string_maps_4;
extern char string_maps_5;
extern char string_maps_6;
extern char string_maps_7;
extern char string_maps_8;
extern char string_maps_9;
extern char string_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_fentry_v61_filter_sockaddr_un_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1:
	/* 0x1: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_5:
	/* 0x5: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_8:
	/* 0x8: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c:
	/* 0xc: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_10:
	/* 0x10: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14:
	/* 0x14: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16:
	/* 0x16: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_1a:
	/* 0x1a: jg     54 <filter_sockaddr_un+0x54> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1a, 0x54, x86_l_54);
x86_l_1c:
	/* 0x1c: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_20:
	/* 0x20: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23:
	/* 0x23: jae    62 <filter_sockaddr_un+0x62> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x23, 0x62, x86_l_62);
x86_l_25:
	/* 0x25: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_28:
	/* 0x28: call   b7 <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_b7, 0x2dULL);
x86_l_2d:
	/* 0x2d: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30:
	/* 0x30: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_34:
	/* 0x34: ja     4a <filter_sockaddr_un+0x4a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x34, 0x4a, x86_l_4a);
x86_l_36:
	/* 0x36: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_40:
	/* 0x40: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_44:
	/* 0x44: jae    4a <filter_sockaddr_un+0x4a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x44, 0x4a, x86_l_4a);
x86_l_46:
	/* 0x46: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_4a:
	/* 0x4a: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e:
	/* 0x4e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: jmp    569 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_54:
	/* 0x54: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_58:
	/* 0x58: je     9c <filter_sockaddr_un+0x9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58, 0x9c, x86_l_9c);
x86_l_5a:
	/* 0x5a: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_5e:
	/* 0x5e: je     68 <filter_sockaddr_un+0x68> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e, 0x68, x86_l_68);
x86_l_60:
	/* 0x60: jmp    4a <filter_sockaddr_un+0x4a> */
	X86_SIM_X86_JMP(0x60, 0x4a, x86_l_4a);
x86_l_62:
	/* 0x62: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_66:
	/* 0x66: jne    4a <filter_sockaddr_un+0x4a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x66, 0x4a, x86_l_4a);
x86_l_68:
	/* 0x68: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b:
	/* 0x6b: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_70:
	/* 0x70: call   444 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_444, 0x75ULL);
x86_l_75:
	/* 0x75: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_78:
	/* 0x78: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_7c:
	/* 0x7c: ja     4a <filter_sockaddr_un+0x4a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7c, 0x4a, x86_l_4a);
x86_l_7e:
	/* 0x7e: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_88:
	/* 0x88: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: jae    4a <filter_sockaddr_un+0x4a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x8c, 0x4a, x86_l_4a);
x86_l_8e:
	/* 0x8e: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_92:
	/* 0x92: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_96:
	/* 0x96: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: jmp    569 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_9c:
	/* 0x9c: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9f:
	/* 0x9f: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a3:
	/* 0xa3: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a8:
	/* 0xa8: call   4e4 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_4e4, 0xadULL);
x86_l_ad:
	/* 0xad: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b1:
	/* 0xb1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_b2:
	/* 0xb2: jmp    569 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_569:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_b7 */
x86_l_b7:
	/* 0xb7: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_b8:
	/* 0xb8: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_ba:
	/* 0xba: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_bc:
	/* 0xbc: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_be:
	/* 0xbe: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_c0:
	/* 0xc0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_c1:
	/* 0xc1: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_c5:
	/* 0xc5: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_cd:
	/* 0xcd: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_d3:
	/* 0xd3: ja     433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xd3, 0x433, x86_l_433);
x86_l_d9:
	/* 0xd9: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_dc:
	/* 0xdc: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_e1:
	/* 0xe1: ja     134 <filter_char_buf_equal+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xe1, 0x134, x86_l_134);
x86_l_e3:
	/* 0xe3: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e6:
	/* 0xe6: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_ec:
	/* 0xec: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_ef:
	/* 0xef: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_f2:
	/* 0xf2: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_f5:
	/* 0xf5: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f7:
	/* 0xf7: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_fa:
	/* 0xfa: je     105 <filter_char_buf_equal+0x4e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xfa, 0x105, x86_l_105);
x86_l_fc:
	/* 0xfc: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_fe:
	/* 0xfe: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_101:
	/* 0x101: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_103:
	/* 0x103: je     11e <filter_char_buf_equal+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x103, 0x11e, x86_l_11e);
x86_l_105:
	/* 0x105: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_108:
	/* 0x108: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_10a:
	/* 0x10a: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_10c:
	/* 0x10c: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_10e:
	/* 0x10e: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_111:
	/* 0x111: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_115:
	/* 0x115: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_119:
	/* 0x119: ja     172 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x119, 0x172, x86_l_172);
x86_l_11b:
	/* 0x11b: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_11e:
	/* 0x11e: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_121:
	/* 0x121: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_128:
	/* 0x128: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_12c:
	/* 0x12c: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_12f:
	/* 0x12f: jmp    1bd <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x12f, 0x1bd, x86_l_1bd);
x86_l_134:
	/* 0x134: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_13a:
	/* 0x13a: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_13f:
	/* 0x13f: jb     172 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13f, 0x172, x86_l_172);
x86_l_141:
	/* 0x141: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_147:
	/* 0x147: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_14c:
	/* 0x14c: jb     172 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14c, 0x172, x86_l_172);
x86_l_14e:
	/* 0x14e: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_154:
	/* 0x154: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_159:
	/* 0x159: jb     172 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x159, 0x172, x86_l_172);
x86_l_15b:
	/* 0x15b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15e:
	/* 0x15e: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_163:
	/* 0x163: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_167:
	/* 0x167: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_16b:
	/* 0x16b: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_172:
	/* 0x172: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_179:
	/* 0x179: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_17f:
	/* 0x17f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_182:
	/* 0x182: jg     195 <filter_char_buf_equal+0xde> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x182, 0x195, x86_l_195);
x86_l_184:
	/* 0x184: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_186:
	/* 0x186: je     1af <filter_char_buf_equal+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x186, 0x1af, x86_l_1af);
x86_l_188:
	/* 0x188: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18b:
	/* 0x18b: jne    1a7 <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x18b, 0x1a7, x86_l_1a7);
x86_l_18d:
	/* 0x18d: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_193:
	/* 0x193: jmp    1bd <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x193, 0x1bd, x86_l_1bd);
x86_l_195:
	/* 0x195: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_198:
	/* 0x198: je     1b7 <filter_char_buf_equal+0x100> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x198, 0x1b7, x86_l_1b7);
x86_l_19a:
	/* 0x19a: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_19d:
	/* 0x19d: jne    1a7 <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x19d, 0x1a7, x86_l_1a7);
x86_l_19f:
	/* 0x19f: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1a5:
	/* 0x1a5: jmp    1bd <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1a5, 0x1bd, x86_l_1bd);
x86_l_1a7:
	/* 0x1a7: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1ad:
	/* 0x1ad: jmp    1bd <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1ad, 0x1bd, x86_l_1bd);
x86_l_1af:
	/* 0x1af: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1b5:
	/* 0x1b5: jmp    1bd <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1b5, 0x1bd, x86_l_1bd);
x86_l_1b7:
	/* 0x1b7: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1bd:
	/* 0x1bd: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1c0:
	/* 0x1c0: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c3:
	/* 0x1c3: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1c8:
	/* 0x1c8: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_1cc:
	/* 0x1cc: je     433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cc, 0x433, x86_l_433);
x86_l_1d2:
	/* 0x1d2: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d7:
	/* 0x1d7: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1d9:
	/* 0x1d9: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1e0:
	/* 0x1e0: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e5:
	/* 0x1e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ea:
	/* 0x1ea: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1ed:
	/* 0x1ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef:
	/* 0x1ef: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1f2:
	/* 0x1f2: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1f9:
	/* 0x1f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fe:
	/* 0x1fe: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_201:
	/* 0x201: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_203:
	/* 0x203: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_206:
	/* 0x206: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_208:
	/* 0x208: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d:
	/* 0x20d: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_210:
	/* 0x210: je     435 <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x210, 0x435, x86_l_435);
x86_l_216:
	/* 0x216: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_219:
	/* 0x219: je     435 <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x219, 0x435, x86_l_435);
x86_l_21f:
	/* 0x21f: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_224:
	/* 0x224: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_228:
	/* 0x228: jg     26b <filter_char_buf_equal+0x1b4> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x228, 0x26b, x86_l_26b);
x86_l_22a:
	/* 0x22a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f:
	/* 0x22f: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232:
	/* 0x232: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_236:
	/* 0x236: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_239:
	/* 0x239: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23e:
	/* 0x23e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_243:
	/* 0x243: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24a:
	/* 0x24a: jbe    2b0 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x24a, 0x2b0, x86_l_2b0);
x86_l_24c:
	/* 0x24c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_251:
	/* 0x251: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_255:
	/* 0x255: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_258:
	/* 0x258: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25f:
	/* 0x25f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264:
	/* 0x264: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_269:
	/* 0x269: jmp    2ab <filter_char_buf_equal+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x269, 0x2ab, x86_l_2ab);
x86_l_26b:
	/* 0x26b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_270:
	/* 0x270: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273:
	/* 0x273: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_277:
	/* 0x277: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_27a:
	/* 0x27a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27f:
	/* 0x27f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_284:
	/* 0x284: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_286:
	/* 0x286: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288:
	/* 0x288: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28b:
	/* 0x28b: jbe    2b0 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x28b, 0x2b0, x86_l_2b0);
x86_l_28d:
	/* 0x28d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292:
	/* 0x292: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_296:
	/* 0x296: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_29a:
	/* 0x29a: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a6:
	/* 0x2a6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ab:
	/* 0x2ab: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_2ae:
	/* 0x2ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0:
	/* 0x2b0: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b5:
	/* 0x2b5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_2b9:
	/* 0x2b9: jle    2f5 <filter_char_buf_equal+0x23e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2b9, 0x2f5, x86_l_2f5);
x86_l_2bb:
	/* 0x2bb: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2bf:
	/* 0x2bf: jg     32f <filter_char_buf_equal+0x278> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2bf, 0x32f, x86_l_32f);
x86_l_2c1:
	/* 0x2c1: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2c5:
	/* 0x2c5: je     3e7 <filter_char_buf_equal+0x330> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c5, 0x3e7, x86_l_3e7);
x86_l_2cb:
	/* 0x2cb: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2cf:
	/* 0x2cf: je     3ae <filter_char_buf_equal+0x2f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2cf, 0x3ae, x86_l_3ae);
x86_l_2d5:
	/* 0x2d5: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2d9:
	/* 0x2d9: jne    433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2d9, 0x433, x86_l_433);
x86_l_2df:
	/* 0x2df: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2e6:
	/* 0x2e6: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2eb:
	/* 0x2eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f0:
	/* 0x2f0: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x2f0, 0x40b, x86_l_40b);
x86_l_2f5:
	/* 0x2f5: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2f9:
	/* 0x2f9: jle    363 <filter_char_buf_equal+0x2ac> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2f9, 0x363, x86_l_363);
x86_l_2fb:
	/* 0x2fb: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2ff:
	/* 0x2ff: je     3d4 <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2ff, 0x3d4, x86_l_3d4);
x86_l_305:
	/* 0x305: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_309:
	/* 0x309: je     39b <filter_char_buf_equal+0x2e4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x309, 0x39b, x86_l_39b);
x86_l_30f:
	/* 0x30f: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_313:
	/* 0x313: jne    433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x313, 0x433, x86_l_433);
x86_l_319:
	/* 0x319: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_320:
	/* 0x320: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_325:
	/* 0x325: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32a:
	/* 0x32a: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x32a, 0x40b, x86_l_40b);
x86_l_32f:
	/* 0x32f: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_333:
	/* 0x333: je     3fa <filter_char_buf_equal+0x343> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x333, 0x3fa, x86_l_3fa);
x86_l_339:
	/* 0x339: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_33d:
	/* 0x33d: je     3c1 <filter_char_buf_equal+0x30a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x33d, 0x3c1, x86_l_3c1);
x86_l_343:
	/* 0x343: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_347:
	/* 0x347: jne    433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x347, 0x433, x86_l_433);
x86_l_34d:
	/* 0x34d: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_354:
	/* 0x354: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_359:
	/* 0x359: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35e:
	/* 0x35e: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x35e, 0x40b, x86_l_40b);
x86_l_363:
	/* 0x363: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_366:
	/* 0x366: je     388 <filter_char_buf_equal+0x2d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x366, 0x388, x86_l_388);
x86_l_368:
	/* 0x368: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_36c:
	/* 0x36c: jne    433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x36c, 0x433, x86_l_433);
x86_l_372:
	/* 0x372: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_379:
	/* 0x379: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37e:
	/* 0x37e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_383:
	/* 0x383: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x383, 0x40b, x86_l_40b);
x86_l_388:
	/* 0x388: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_38f:
	/* 0x38f: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_394:
	/* 0x394: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_399:
	/* 0x399: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x399, 0x40b, x86_l_40b);
x86_l_39b:
	/* 0x39b: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3a2:
	/* 0x3a2: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a7:
	/* 0x3a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ac:
	/* 0x3ac: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3ac, 0x40b, x86_l_40b);
x86_l_3ae:
	/* 0x3ae: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3b5:
	/* 0x3b5: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ba:
	/* 0x3ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bf:
	/* 0x3bf: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3bf, 0x40b, x86_l_40b);
x86_l_3c1:
	/* 0x3c1: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3c8:
	/* 0x3c8: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3cd:
	/* 0x3cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d2:
	/* 0x3d2: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3d2, 0x40b, x86_l_40b);
x86_l_3d4:
	/* 0x3d4: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3db:
	/* 0x3db: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e0:
	/* 0x3e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e5:
	/* 0x3e5: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3e5, 0x40b, x86_l_40b);
x86_l_3e7:
	/* 0x3e7: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3ee:
	/* 0x3ee: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f3:
	/* 0x3f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f8:
	/* 0x3f8: jmp    40b <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3f8, 0x40b, x86_l_40b);
x86_l_3fa:
	/* 0x3fa: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_401:
	/* 0x401: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_406:
	/* 0x406: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40b:
	/* 0x40b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_410:
	/* 0x410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412:
	/* 0x412: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_415:
	/* 0x415: je     433 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x415, 0x433, x86_l_433);
x86_l_417:
	/* 0x417: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_41a:
	/* 0x41a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41f:
	/* 0x41f: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_424:
	/* 0x424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426:
	/* 0x426: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_429:
	/* 0x429: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_42b:
	/* 0x42b: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_431:
	/* 0x431: jmp    435 <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JMP(0x431, 0x435, x86_l_435);
x86_l_433:
	/* 0x433: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_435:
	/* 0x435: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_439:
	/* 0x439: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_43a:
	/* 0x43a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_43c:
	/* 0x43c: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_440:
	/* 0x440: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_442:
	/* 0x442: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_443:
	/* 0x443: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_444 */
x86_l_444:
	/* 0x444: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_445:
	/* 0x445: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_447:
	/* 0x447: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_449:
	/* 0x449: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_44a:
	/* 0x44a: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_44b:
	/* 0x44b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_44d:
	/* 0x44d: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_450:
	/* 0x450: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_454:
	/* 0x454: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45b:
	/* 0x45b: mov    rdi,QWORD PTR [rip+0x2280] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_462:
	/* 0x462: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_467:
	/* 0x467: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46c:
	/* 0x46c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e:
	/* 0x46e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_471:
	/* 0x471: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_473:
	/* 0x473: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_475:
	/* 0x475: je     4d9 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x475, 0x4d9, x86_l_4d9);
x86_l_477:
	/* 0x477: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_47a:
	/* 0x47a: je     4d9 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x47a, 0x4d9, x86_l_4d9);
x86_l_47c:
	/* 0x47c: mov    rdi,QWORD PTR [rip+0x2280] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_483:
	/* 0x483: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_486:
	/* 0x486: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_48b:
	/* 0x48b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d:
	/* 0x48d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_490:
	/* 0x490: je     4d7 <filter_char_buf_prefix+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x490, 0x4d7, x86_l_4d7);
x86_l_492:
	/* 0x492: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_498:
	/* 0x498: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_49d:
	/* 0x49d: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_4a0:
	/* 0x4a0: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_4a7:
	/* 0x4a7: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9:
	/* 0x4a9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4ac:
	/* 0x4ac: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4b0:
	/* 0x4b0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4bb:
	/* 0x4bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd:
	/* 0x4bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c2:
	/* 0x4c2: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cf:
	/* 0x4cf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4d2:
	/* 0x4d2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_4d5:
	/* 0x4d5: jmp    4d9 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JMP(0x4d5, 0x4d9, x86_l_4d9);
x86_l_4d7:
	/* 0x4d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d9:
	/* 0x4d9: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4dd:
	/* 0x4dd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4e0:
	/* 0x4e0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4e2:
	/* 0x4e2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4e3:
	/* 0x4e3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_4e4 */
x86_l_4e4:
	/* 0x4e4: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4e6:
	/* 0x4e6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4e7:
	/* 0x4e7: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4eb:
	/* 0x4eb: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_4ee:
	/* 0x4ee: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_4f5:
	/* 0x4f5: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4f9:
	/* 0x4f9: mov    rdi,QWORD PTR [rip+0xe40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_500:
	/* 0x500: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_505:
	/* 0x505: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50a:
	/* 0x50a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c:
	/* 0x50c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50f:
	/* 0x50f: je     544 <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x50f, 0x544, x86_l_544);
x86_l_511:
	/* 0x511: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_514:
	/* 0x514: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_517:
	/* 0x517: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51c:
	/* 0x51c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_521:
	/* 0x521: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_526:
	/* 0x526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_528:
	/* 0x528: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52b:
	/* 0x52b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52d:
	/* 0x52d: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_530:
	/* 0x530: ja     55e <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x530, 0x55e, x86_l_55e);
x86_l_532:
	/* 0x532: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_537:
	/* 0x537: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_53a:
	/* 0x53a: jae    54e <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x53a, 0x54e, x86_l_54e);
x86_l_53c:
	/* 0x53c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53f:
	/* 0x53f: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_542:
	/* 0x542: jmp    55e <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x542, 0x55e, x86_l_55e);
x86_l_544:
	/* 0x544: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_546:
	/* 0x546: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_54a:
	/* 0x54a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_54b:
	/* 0x54b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_54d:
	/* 0x54d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_54e:
	/* 0x54e: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_553:
	/* 0x553: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_556:
	/* 0x556: jae    55e <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x556, 0x55e, x86_l_55e);
x86_l_558:
	/* 0x558: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55b:
	/* 0x55b: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_55e:
	/* 0x55e: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_561:
	/* 0x561: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_565:
	/* 0x565: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_566:
	/* 0x566: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_568:
	/* 0x568: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x2dULL: goto x86_l_2d;
	case 0x75ULL: goto x86_l_75;
	case 0xadULL: goto x86_l_ad;
	case 0x1efULL: goto x86_l_1ef;
	case 0x203ULL: goto x86_l_203;
	case 0x247ULL: goto x86_l_247;
	case 0x288ULL: goto x86_l_288;
	case 0x2b0ULL: goto x86_l_2b0;
	case 0x412ULL: goto x86_l_412;
	case 0x426ULL: goto x86_l_426;
	case 0x46eULL: goto x86_l_46e;
	case 0x48dULL: goto x86_l_48d;
	case 0x4bdULL: goto x86_l_4bd;
	case 0x4caULL: goto x86_l_4ca;
	case 0x50cULL: goto x86_l_50c;
	case 0x528ULL: goto x86_l_528;
	}

}

X86_SIM_LICENSE();
