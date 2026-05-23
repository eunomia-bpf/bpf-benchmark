#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_socket_lb_service_select_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    r8,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdi,r8 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R8, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rdi,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: jbe    16 <cilium_socket_lb_service_select_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    16d <cilium_socket_lb_service_select_xdp+0x16d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdx,[rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1d:
	/* 0x1d: ja     11 <cilium_socket_lb_service_select_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    rdx,[rdi+0x610] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1552ULL);
x86_l_26:
	/* 0x26: cmp    rdx,rcx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_29:
	/* 0x29: ja     11 <cilium_socket_lb_service_select_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi+0x8],0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_2f:
	/* 0x2f: jne    11 <cilium_socket_lb_service_select_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f, 0x11, x86_l_11);
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rdi+0xc],0x18 */
	X86_SIM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607576ULL);
x86_l_35:
	/* 0x35: jne    11 <cilium_socket_lb_service_select_xdp+0x11> */
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
	/* 0x43: movabs r9,0x243f6a8885a308d3 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_64, 0, 2611923443488327891ULL);
x86_l_4d:
	/* 0x4d: xor    r10d,r10d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_50:
	/* 0x50: jmp    70 <cilium_socket_lb_service_select_xdp+0x70> */
	X86_SIM_X86_JMP(0x50, 0x70, x86_l_70);
x86_l_52:
	/* 0x52: shl    r11,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_56:
	/* 0x56: movzx  eax,bx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_59:
	/* 0x59: or     rax,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_5c:
	/* 0x5c: xor    r9,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_5f:
	/* 0x5f: inc    r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_62:
	/* 0x62: add    rdi,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_66:
	/* 0x66: cmp    r10,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_6a:
	/* 0x6a: je     158 <cilium_socket_lb_service_select_xdp+0x158> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0x158, x86_l_158);
x86_l_70:
	/* 0x70: mov    eax,DWORD PTR [rdi-0x13] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_73:
	/* 0x73: movzx  r11d,BYTE PTR [rdi-0xb] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551605ULL);
x86_l_78:
	/* 0x78: cmp    r11,0x11 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 17ULL);
x86_l_7c:
	/* 0x7c: setne  cl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_7f:
	/* 0x7f: cmp    r11,0x6 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_64, 0, 6ULL);
x86_l_83:
	/* 0x83: setne  dl */
	X86_SIM_RUN_OP(X86_OP_SETCC, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_CC_NE, 0);
x86_l_86:
	/* 0x86: movzx  ebx,WORD PTR [rdi-0xd] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551603ULL);
x86_l_8a:
	/* 0x8a: movzx  r15d,BYTE PTR [rdi-0xa] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551606ULL);
x86_l_8f:
	/* 0x8f: test   r15b,0x2 */
	X86_SIM_RUN_OP(X86_OP_TEST_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, 0, 2ULL);
x86_l_93:
	/* 0x93: mov    ebp,0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, 0, 0ULL);
x86_l_98:
	/* 0x98: cmove  ebp,eax */
	X86_SIM_RUN_OP(X86_OP_CMOV, X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E, 0);
x86_l_9b:
	/* 0x9b: test   dl,cl */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RDX, X86_RCX, X86_WIDTH_8, 0, 0);
x86_l_9d:
	/* 0x9d: jne    52 <cilium_socket_lb_service_select_xdp+0x52> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9d, 0x52, x86_l_52);
x86_l_9f:
	/* 0x9f: movzx  r12d,WORD PTR [rdi-0x9] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551607ULL);
x86_l_a4:
	/* 0xa4: test   r12w,r12w */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16, 0, 0);
x86_l_a8:
	/* 0xa8: je     52 <cilium_socket_lb_service_select_xdp+0x52> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8, 0x52, x86_l_52);
x86_l_aa:
	/* 0xaa: movzx  ecx,WORD PTR [rdi-0xf] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551601ULL);
x86_l_ae:
	/* 0xae: mov    edx,ecx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_b0:
	/* 0xb0: shl    edx,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_b3:
	/* 0xb3: xor    edx,DWORD PTR [rdi-0x17] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551593ULL);
x86_l_b6:
	/* 0xb6: mov    r14d,DWORD PTR [rdi-0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_ba:
	/* 0xba: xor    edx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_bc:
	/* 0xbc: xor    edx,DWORD PTR [rdi-0x7] */
	X86_SIM_RUN_OP(X86_OP_ALU_MEM, X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 18446744073709551609ULL);
x86_l_bf:
	/* 0xbf: movsx  esi,bx */
	X86_SIM_RUN_OP(X86_OP_MOVSX_REG, X86_RSI, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_c2:
	/* 0xc2: cmp    esi,0x752f */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 29999ULL);
x86_l_c8:
	/* 0xc8: jg     f0 <cilium_socket_lb_service_select_xdp+0xf0> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc8, 0xf0, x86_l_f0);
x86_l_ca:
	/* 0xca: mov    esi,r15d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R15, X86_WIDTH_32, 0, 0);
x86_l_cd:
	/* 0xcd: and    esi,0x2 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_d0:
	/* 0xd0: jne    f0 <cilium_socket_lb_service_select_xdp+0xf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd0, 0xf0, x86_l_f0);
x86_l_d2:
	/* 0xd2: mov    eax,eax */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_d4:
	/* 0xd4: shl    rax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_d8:
	/* 0xd8: movzx  ecx,cx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_db:
	/* 0xdb: or     rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_de:
	/* 0xde: add    r9,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_e1:
	/* 0xe1: inc    r10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_e4:
	/* 0xe4: add    rdi,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_e8:
	/* 0xe8: cmp    r10,0x40 */
	X86_SIM_RUN_OP(X86_OP_CMP_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_ec:
	/* 0xec: jne    70 <cilium_socket_lb_service_select_xdp+0x70> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xec, 0x70, x86_l_70);
x86_l_ee:
	/* 0xee: jmp    158 <cilium_socket_lb_service_select_xdp+0x158> */
	X86_SIM_X86_JMP(0xee, 0x158, x86_l_158);
x86_l_f0:
	/* 0xf0: xor    edx,ebp */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_f2:
	/* 0xf2: lea    esi,[r14+r15*1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_f6:
	/* 0xf6: add    esi,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_f8:
	/* 0xf8: mov    ecx,r11d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R11, X86_WIDTH_32, 0, 0);
x86_l_fb:
	/* 0xfb: and    ecx,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_fe:
	/* 0xfe: inc    ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_100:
	/* 0x100: rol    esi,cl */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ROL, 0);
x86_l_102:
	/* 0x102: xor    esi,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_104:
	/* 0x104: mov    eax,esi */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_106:
	/* 0x106: xor    edx,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_108:
	/* 0x108: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_10b:
	/* 0x10b: inc    edx */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10d:
	/* 0x10d: shl    r15d,0x1d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 29ULL);
x86_l_111:
	/* 0x111: sar    r15d,0x1f */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_115:
	/* 0x115: inc    r14d */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_118:
	/* 0x118: and    r14d,r15d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_AND, 0);
x86_l_11b:
	/* 0x11b: xor    r14d,edx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11e:
	/* 0x11e: mov    eax,ebp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBP, X86_WIDTH_32, 0, 0);
x86_l_120:
	/* 0x120: shl    rax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 16ULL);
x86_l_124:
	/* 0x124: movzx  ecx,bx */
	X86_SIM_RUN_OP(X86_OP_MOVZX_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_127:
	/* 0x127: shl    rcx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_12b:
	/* 0x12b: xor    rcx,rax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_12e:
	/* 0x12e: add    r9,r11 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_131:
	/* 0x131: add    r9,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_134:
	/* 0x134: shl    r14,0x30 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_138:
	/* 0x138: or     rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_R14, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13b:
	/* 0x13b: mov    eax,r10d */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R10, X86_WIDTH_32, 0, 0);
x86_l_13e:
	/* 0x13e: and    eax,0x7 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_141:
	/* 0x141: lea    ecx,[rax+0x1] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_144:
	/* 0x144: shlx   rcx,rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RSI, X86_WIDTH_64, X86_RCX, X86_ALU_SHL);
x86_l_149:
	/* 0x149: not    al */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_14b:
	/* 0x14b: shrx   rax,rsi,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RSI, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_150:
	/* 0x150: or     rax,rcx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_153:
	/* 0x153: jmp    5c <cilium_socket_lb_service_select_xdp+0x5c> */
	X86_SIM_X86_JMP(0x153, 0x5c, x86_l_5c);
x86_l_158:
	/* 0x158: mov    QWORD PTR [r8],r9 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R8, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b:
	/* 0x15b: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_160:
	/* 0x160: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_161:
	/* 0x161: pop    r12 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_163:
	/* 0x163: pop    r14 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_165:
	/* 0x165: pop    r15 */
	X86_SIM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_167:
	/* 0x167: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_168:
	/* 0x168: jmp    16d <cilium_socket_lb_service_select_xdp+0x16d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16d:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
