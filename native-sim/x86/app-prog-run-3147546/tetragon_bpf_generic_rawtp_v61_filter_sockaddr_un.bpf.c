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
int tetragon_bpf_generic_rawtp_v61_filter_sockaddr_un_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b:
	/* 0xb: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_f:
	/* 0xf: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13:
	/* 0x13: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15:
	/* 0x15: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_19:
	/* 0x19: jg     52 <filter_sockaddr_un+0x52> */
	X86_SIM_X86_JCC(X86_CC_G, 0x19, 0x52, x86_l_52);
x86_l_1b:
	/* 0x1b: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1f:
	/* 0x1f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22:
	/* 0x22: jae    60 <filter_sockaddr_un+0x60> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x22, 0x60, x86_l_60);
x86_l_24:
	/* 0x24: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_27:
	/* 0x27: call   b3 <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_b3, 0x2cULL);
x86_l_2c:
	/* 0x2c: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f:
	/* 0x2f: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_33:
	/* 0x33: ja     49 <filter_sockaddr_un+0x49> */
	X86_SIM_X86_JCC(X86_CC_A, 0x33, 0x49, x86_l_49);
x86_l_35:
	/* 0x35: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_3f:
	/* 0x3f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: jae    49 <filter_sockaddr_un+0x49> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x43, 0x49, x86_l_49);
x86_l_45:
	/* 0x45: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_49:
	/* 0x49: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d:
	/* 0x4d: jmp    565 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_52:
	/* 0x52: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_56:
	/* 0x56: je     99 <filter_sockaddr_un+0x99> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56, 0x99, x86_l_99);
x86_l_58:
	/* 0x58: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_5c:
	/* 0x5c: je     66 <filter_sockaddr_un+0x66> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x66, x86_l_66);
x86_l_5e:
	/* 0x5e: jmp    49 <filter_sockaddr_un+0x49> */
	X86_SIM_X86_JMP(0x5e, 0x49, x86_l_49);
x86_l_60:
	/* 0x60: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_64:
	/* 0x64: jne    49 <filter_sockaddr_un+0x49> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x64, 0x49, x86_l_49);
x86_l_66:
	/* 0x66: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69:
	/* 0x69: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_6e:
	/* 0x6e: call   440 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_440, 0x73ULL);
x86_l_73:
	/* 0x73: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_76:
	/* 0x76: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_7a:
	/* 0x7a: ja     49 <filter_sockaddr_un+0x49> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7a, 0x49, x86_l_49);
x86_l_7c:
	/* 0x7c: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_86:
	/* 0x86: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: jae    49 <filter_sockaddr_un+0x49> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x8a, 0x49, x86_l_49);
x86_l_8c:
	/* 0x8c: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_90:
	/* 0x90: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_94:
	/* 0x94: jmp    565 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_99:
	/* 0x99: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9c:
	/* 0x9c: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a0:
	/* 0xa0: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a5:
	/* 0xa5: call   4e0 <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_4e0, 0xaaULL);
x86_l_aa:
	/* 0xaa: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ae:
	/* 0xae: jmp    565 <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_565:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_b3 */
x86_l_b3:
	/* 0xb3: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_b4:
	/* 0xb4: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_b6:
	/* 0xb6: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_b8:
	/* 0xb8: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_ba:
	/* 0xba: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_bc:
	/* 0xbc: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_bd:
	/* 0xbd: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_c1:
	/* 0xc1: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_c9:
	/* 0xc9: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_cf:
	/* 0xcf: ja     42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xcf, 0x42f, x86_l_42f);
x86_l_d5:
	/* 0xd5: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d8:
	/* 0xd8: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_dd:
	/* 0xdd: ja     130 <filter_char_buf_equal+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xdd, 0x130, x86_l_130);
x86_l_df:
	/* 0xdf: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e2:
	/* 0xe2: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_e8:
	/* 0xe8: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_eb:
	/* 0xeb: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_ee:
	/* 0xee: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_f1:
	/* 0xf1: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f3:
	/* 0xf3: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_f6:
	/* 0xf6: je     101 <filter_char_buf_equal+0x4e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf6, 0x101, x86_l_101);
x86_l_f8:
	/* 0xf8: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_fa:
	/* 0xfa: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_fd:
	/* 0xfd: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_ff:
	/* 0xff: je     11a <filter_char_buf_equal+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xff, 0x11a, x86_l_11a);
x86_l_101:
	/* 0x101: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_104:
	/* 0x104: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_106:
	/* 0x106: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_108:
	/* 0x108: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_10a:
	/* 0x10a: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_10d:
	/* 0x10d: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_111:
	/* 0x111: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_115:
	/* 0x115: ja     16e <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x115, 0x16e, x86_l_16e);
x86_l_117:
	/* 0x117: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_11a:
	/* 0x11a: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11d:
	/* 0x11d: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_124:
	/* 0x124: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_128:
	/* 0x128: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_12b:
	/* 0x12b: jmp    1b9 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x12b, 0x1b9, x86_l_1b9);
x86_l_130:
	/* 0x130: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_136:
	/* 0x136: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_13b:
	/* 0x13b: jb     16e <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13b, 0x16e, x86_l_16e);
x86_l_13d:
	/* 0x13d: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_143:
	/* 0x143: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_148:
	/* 0x148: jb     16e <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x148, 0x16e, x86_l_16e);
x86_l_14a:
	/* 0x14a: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_150:
	/* 0x150: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_155:
	/* 0x155: jb     16e <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x155, 0x16e, x86_l_16e);
x86_l_157:
	/* 0x157: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a:
	/* 0x15a: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_15f:
	/* 0x15f: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_163:
	/* 0x163: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_167:
	/* 0x167: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_16e:
	/* 0x16e: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_175:
	/* 0x175: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_17b:
	/* 0x17b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17e:
	/* 0x17e: jg     191 <filter_char_buf_equal+0xde> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x17e, 0x191, x86_l_191);
x86_l_180:
	/* 0x180: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182:
	/* 0x182: je     1ab <filter_char_buf_equal+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x182, 0x1ab, x86_l_1ab);
x86_l_184:
	/* 0x184: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_187:
	/* 0x187: jne    1a3 <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x187, 0x1a3, x86_l_1a3);
x86_l_189:
	/* 0x189: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_18f:
	/* 0x18f: jmp    1b9 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x18f, 0x1b9, x86_l_1b9);
x86_l_191:
	/* 0x191: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_194:
	/* 0x194: je     1b3 <filter_char_buf_equal+0x100> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x194, 0x1b3, x86_l_1b3);
x86_l_196:
	/* 0x196: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_199:
	/* 0x199: jne    1a3 <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x199, 0x1a3, x86_l_1a3);
x86_l_19b:
	/* 0x19b: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1a1:
	/* 0x1a1: jmp    1b9 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1a1, 0x1b9, x86_l_1b9);
x86_l_1a3:
	/* 0x1a3: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1a9:
	/* 0x1a9: jmp    1b9 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1a9, 0x1b9, x86_l_1b9);
x86_l_1ab:
	/* 0x1ab: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1b1:
	/* 0x1b1: jmp    1b9 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1b1, 0x1b9, x86_l_1b9);
x86_l_1b3:
	/* 0x1b3: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1b9:
	/* 0x1b9: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1bc:
	/* 0x1bc: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1bf:
	/* 0x1bf: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1c4:
	/* 0x1c4: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_1c8:
	/* 0x1c8: je     42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c8, 0x42f, x86_l_42f);
x86_l_1ce:
	/* 0x1ce: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d3:
	/* 0x1d3: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1d5:
	/* 0x1d5: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1dc:
	/* 0x1dc: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e1:
	/* 0x1e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e6:
	/* 0x1e6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1e9:
	/* 0x1e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb:
	/* 0x1eb: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1ee:
	/* 0x1ee: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1f5:
	/* 0x1f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fa:
	/* 0x1fa: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1fd:
	/* 0x1fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff:
	/* 0x1ff: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_202:
	/* 0x202: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_204:
	/* 0x204: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209:
	/* 0x209: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_20c:
	/* 0x20c: je     431 <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x20c, 0x431, x86_l_431);
x86_l_212:
	/* 0x212: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_215:
	/* 0x215: je     431 <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x215, 0x431, x86_l_431);
x86_l_21b:
	/* 0x21b: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_220:
	/* 0x220: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_224:
	/* 0x224: jg     267 <filter_char_buf_equal+0x1b4> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x224, 0x267, x86_l_267);
x86_l_226:
	/* 0x226: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b:
	/* 0x22b: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e:
	/* 0x22e: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_232:
	/* 0x232: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_235:
	/* 0x235: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23a:
	/* 0x23a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23f:
	/* 0x23f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_241:
	/* 0x241: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243:
	/* 0x243: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_246:
	/* 0x246: jbe    2ac <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x246, 0x2ac, x86_l_2ac);
x86_l_248:
	/* 0x248: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d:
	/* 0x24d: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_251:
	/* 0x251: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_254:
	/* 0x254: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25b:
	/* 0x25b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_260:
	/* 0x260: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_265:
	/* 0x265: jmp    2a7 <filter_char_buf_equal+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x265, 0x2a7, x86_l_2a7);
x86_l_267:
	/* 0x267: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26c:
	/* 0x26c: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f:
	/* 0x26f: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_273:
	/* 0x273: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_276:
	/* 0x276: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27b:
	/* 0x27b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_280:
	/* 0x280: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_282:
	/* 0x282: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284:
	/* 0x284: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_287:
	/* 0x287: jbe    2ac <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x287, 0x2ac, x86_l_2ac);
x86_l_289:
	/* 0x289: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e:
	/* 0x28e: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_292:
	/* 0x292: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_296:
	/* 0x296: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29d:
	/* 0x29d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a2:
	/* 0x2a2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a7:
	/* 0x2a7: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_2aa:
	/* 0x2aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac:
	/* 0x2ac: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b1:
	/* 0x2b1: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_2b5:
	/* 0x2b5: jle    2f1 <filter_char_buf_equal+0x23e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2b5, 0x2f1, x86_l_2f1);
x86_l_2b7:
	/* 0x2b7: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2bb:
	/* 0x2bb: jg     32b <filter_char_buf_equal+0x278> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2bb, 0x32b, x86_l_32b);
x86_l_2bd:
	/* 0x2bd: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2c1:
	/* 0x2c1: je     3e3 <filter_char_buf_equal+0x330> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c1, 0x3e3, x86_l_3e3);
x86_l_2c7:
	/* 0x2c7: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2cb:
	/* 0x2cb: je     3aa <filter_char_buf_equal+0x2f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2cb, 0x3aa, x86_l_3aa);
x86_l_2d1:
	/* 0x2d1: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2d5:
	/* 0x2d5: jne    42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2d5, 0x42f, x86_l_42f);
x86_l_2db:
	/* 0x2db: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2e2:
	/* 0x2e2: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e7:
	/* 0x2e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ec:
	/* 0x2ec: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x2ec, 0x407, x86_l_407);
x86_l_2f1:
	/* 0x2f1: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2f5:
	/* 0x2f5: jle    35f <filter_char_buf_equal+0x2ac> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2f5, 0x35f, x86_l_35f);
x86_l_2f7:
	/* 0x2f7: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2fb:
	/* 0x2fb: je     3d0 <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2fb, 0x3d0, x86_l_3d0);
x86_l_301:
	/* 0x301: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_305:
	/* 0x305: je     397 <filter_char_buf_equal+0x2e4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x305, 0x397, x86_l_397);
x86_l_30b:
	/* 0x30b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_30f:
	/* 0x30f: jne    42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x30f, 0x42f, x86_l_42f);
x86_l_315:
	/* 0x315: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31c:
	/* 0x31c: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_321:
	/* 0x321: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_326:
	/* 0x326: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x326, 0x407, x86_l_407);
x86_l_32b:
	/* 0x32b: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_32f:
	/* 0x32f: je     3f6 <filter_char_buf_equal+0x343> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x32f, 0x3f6, x86_l_3f6);
x86_l_335:
	/* 0x335: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_339:
	/* 0x339: je     3bd <filter_char_buf_equal+0x30a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x339, 0x3bd, x86_l_3bd);
x86_l_33f:
	/* 0x33f: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_343:
	/* 0x343: jne    42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x343, 0x42f, x86_l_42f);
x86_l_349:
	/* 0x349: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_350:
	/* 0x350: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_355:
	/* 0x355: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35a:
	/* 0x35a: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x35a, 0x407, x86_l_407);
x86_l_35f:
	/* 0x35f: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_362:
	/* 0x362: je     384 <filter_char_buf_equal+0x2d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x362, 0x384, x86_l_384);
x86_l_364:
	/* 0x364: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_368:
	/* 0x368: jne    42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x368, 0x42f, x86_l_42f);
x86_l_36e:
	/* 0x36e: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_375:
	/* 0x375: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37a:
	/* 0x37a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37f:
	/* 0x37f: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x37f, 0x407, x86_l_407);
x86_l_384:
	/* 0x384: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_38b:
	/* 0x38b: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_390:
	/* 0x390: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_395:
	/* 0x395: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x395, 0x407, x86_l_407);
x86_l_397:
	/* 0x397: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_39e:
	/* 0x39e: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a3:
	/* 0x3a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a8:
	/* 0x3a8: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3a8, 0x407, x86_l_407);
x86_l_3aa:
	/* 0x3aa: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_3b1:
	/* 0x3b1: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b6:
	/* 0x3b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bb:
	/* 0x3bb: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3bb, 0x407, x86_l_407);
x86_l_3bd:
	/* 0x3bd: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_3c4:
	/* 0x3c4: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c9:
	/* 0x3c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ce:
	/* 0x3ce: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3ce, 0x407, x86_l_407);
x86_l_3d0:
	/* 0x3d0: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3d7:
	/* 0x3d7: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3dc:
	/* 0x3dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e1:
	/* 0x3e1: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3e1, 0x407, x86_l_407);
x86_l_3e3:
	/* 0x3e3: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3ea:
	/* 0x3ea: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ef:
	/* 0x3ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f4:
	/* 0x3f4: jmp    407 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3f4, 0x407, x86_l_407);
x86_l_3f6:
	/* 0x3f6: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3fd:
	/* 0x3fd: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_402:
	/* 0x402: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_407:
	/* 0x407: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40c:
	/* 0x40c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40e:
	/* 0x40e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_411:
	/* 0x411: je     42f <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x411, 0x42f, x86_l_42f);
x86_l_413:
	/* 0x413: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_416:
	/* 0x416: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41b:
	/* 0x41b: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_420:
	/* 0x420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_422:
	/* 0x422: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_425:
	/* 0x425: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_427:
	/* 0x427: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_42a:
	/* 0x42a: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_42d:
	/* 0x42d: jmp    431 <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JMP(0x42d, 0x431, x86_l_431);
x86_l_42f:
	/* 0x42f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_431:
	/* 0x431: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_435:
	/* 0x435: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_436:
	/* 0x436: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_438:
	/* 0x438: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_43a:
	/* 0x43a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_43c:
	/* 0x43c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_43f:
	/* 0x43f: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_440 */
x86_l_440:
	/* 0x440: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_441:
	/* 0x441: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_443:
	/* 0x443: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_445:
	/* 0x445: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_446:
	/* 0x446: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_447:
	/* 0x447: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_449:
	/* 0x449: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_44c:
	/* 0x44c: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_450:
	/* 0x450: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_457:
	/* 0x457: mov    rdi,QWORD PTR [rip+0x2280] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_45e:
	/* 0x45e: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_463:
	/* 0x463: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_468:
	/* 0x468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46a:
	/* 0x46a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_46d:
	/* 0x46d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46f:
	/* 0x46f: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_471:
	/* 0x471: je     4d5 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x471, 0x4d5, x86_l_4d5);
x86_l_473:
	/* 0x473: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_476:
	/* 0x476: je     4d5 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x476, 0x4d5, x86_l_4d5);
x86_l_478:
	/* 0x478: mov    rdi,QWORD PTR [rip+0x2280] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_47f:
	/* 0x47f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_482:
	/* 0x482: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_487:
	/* 0x487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489:
	/* 0x489: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48c:
	/* 0x48c: je     4d3 <filter_char_buf_prefix+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x48c, 0x4d3, x86_l_4d3);
x86_l_48e:
	/* 0x48e: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_494:
	/* 0x494: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_499:
	/* 0x499: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_49c:
	/* 0x49c: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_4a3:
	/* 0x4a3: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a5:
	/* 0x4a5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4a8:
	/* 0x4a8: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4ac:
	/* 0x4ac: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4af:
	/* 0x4af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b4:
	/* 0x4b4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b9:
	/* 0x4b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4be:
	/* 0x4be: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_4c1:
	/* 0x4c1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4c4:
	/* 0x4c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c6:
	/* 0x4c6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4c9:
	/* 0x4c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cb:
	/* 0x4cb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_4d1:
	/* 0x4d1: jmp    4d5 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JMP(0x4d1, 0x4d5, x86_l_4d5);
x86_l_4d3:
	/* 0x4d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d5:
	/* 0x4d5: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d9:
	/* 0x4d9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4da:
	/* 0x4da: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4dc:
	/* 0x4dc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4df:
	/* 0x4df: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_4e0 */
x86_l_4e0:
	/* 0x4e0: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4e2:
	/* 0x4e2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4e3:
	/* 0x4e3: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4e7:
	/* 0x4e7: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_4ea:
	/* 0x4ea: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4ed:
	/* 0x4ed: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_4f1:
	/* 0x4f1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4f5:
	/* 0x4f5: mov    rdi,QWORD PTR [rip+0xe40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_4fc:
	/* 0x4fc: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_501:
	/* 0x501: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_506:
	/* 0x506: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_508:
	/* 0x508: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50b:
	/* 0x50b: je     540 <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x50b, 0x540, x86_l_540);
x86_l_50d:
	/* 0x50d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_510:
	/* 0x510: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_518:
	/* 0x518: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51d:
	/* 0x51d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_522:
	/* 0x522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_524:
	/* 0x524: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_527:
	/* 0x527: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_529:
	/* 0x529: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_52c:
	/* 0x52c: ja     55a <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x52c, 0x55a, x86_l_55a);
x86_l_52e:
	/* 0x52e: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_533:
	/* 0x533: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_536:
	/* 0x536: jae    54a <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x536, 0x54a, x86_l_54a);
x86_l_538:
	/* 0x538: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53b:
	/* 0x53b: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_53e:
	/* 0x53e: jmp    55a <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x53e, 0x55a, x86_l_55a);
x86_l_540:
	/* 0x540: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_542:
	/* 0x542: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_546:
	/* 0x546: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_547:
	/* 0x547: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_549:
	/* 0x549: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_54a:
	/* 0x54a: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_54f:
	/* 0x54f: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_552:
	/* 0x552: jae    55a <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x552, 0x55a, x86_l_55a);
x86_l_554:
	/* 0x554: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_557:
	/* 0x557: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_55a:
	/* 0x55a: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_55d:
	/* 0x55d: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_561:
	/* 0x561: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_562:
	/* 0x562: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_564:
	/* 0x564: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x2cULL: goto x86_l_2c;
	case 0x73ULL: goto x86_l_73;
	case 0xaaULL: goto x86_l_aa;
	case 0x1ebULL: goto x86_l_1eb;
	case 0x1ffULL: goto x86_l_1ff;
	case 0x243ULL: goto x86_l_243;
	case 0x284ULL: goto x86_l_284;
	case 0x2acULL: goto x86_l_2ac;
	case 0x40eULL: goto x86_l_40e;
	case 0x422ULL: goto x86_l_422;
	case 0x46aULL: goto x86_l_46a;
	case 0x489ULL: goto x86_l_489;
	case 0x4b9ULL: goto x86_l_4b9;
	case 0x4c6ULL: goto x86_l_4c6;
	case 0x508ULL: goto x86_l_508;
	case 0x524ULL: goto x86_l_524;
	}

}

X86_SIM_LICENSE();
