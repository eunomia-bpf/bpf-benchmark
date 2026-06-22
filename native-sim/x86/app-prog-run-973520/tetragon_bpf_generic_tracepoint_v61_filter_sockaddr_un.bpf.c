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
int tetragon_bpf_generic_tracepoint_v61_filter_sockaddr_un_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x4d: jmp    50f <filter_32ty_map+0x85> ; native-link entry RET */
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
	/* 0x6e: call   3e8 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_3e8, 0x73ULL);
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
	/* 0x94: jmp    50f <filter_32ty_map+0x85> ; native-link entry RET */
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
	/* 0xa5: call   48a <filter_32ty_map> */
	X86_SIM_X86_CALL(x86_l_48a, 0xaaULL);
x86_l_aa:
	/* 0xaa: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ae:
	/* 0xae: jmp    50f <filter_32ty_map+0x85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_50f:
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
	/* 0xbd: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_c1:
	/* 0xc1: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c9:
	/* 0xc9: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_cf:
	/* 0xcf: ja     3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xcf, 0x3d7, x86_l_3d7);
x86_l_d5:
	/* 0xd5: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_d7:
	/* 0xd7: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_da:
	/* 0xda: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_df:
	/* 0xdf: ja     133 <filter_char_buf_equal+0x80> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xdf, 0x133, x86_l_133);
x86_l_e1:
	/* 0xe1: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e5:
	/* 0xe5: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_eb:
	/* 0xeb: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_ee:
	/* 0xee: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_f1:
	/* 0xf1: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_f4:
	/* 0xf4: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f6:
	/* 0xf6: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_f9:
	/* 0xf9: je     104 <filter_char_buf_equal+0x51> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xf9, 0x104, x86_l_104);
x86_l_fb:
	/* 0xfb: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_fd:
	/* 0xfd: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_100:
	/* 0x100: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_102:
	/* 0x102: je     11d <filter_char_buf_equal+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x102, 0x11d, x86_l_11d);
x86_l_104:
	/* 0x104: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_107:
	/* 0x107: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_109:
	/* 0x109: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_10b:
	/* 0x10b: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_10d:
	/* 0x10d: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_110:
	/* 0x110: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_114:
	/* 0x114: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_118:
	/* 0x118: ja     171 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x118, 0x171, x86_l_171);
x86_l_11a:
	/* 0x11a: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_11d:
	/* 0x11d: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_120:
	/* 0x120: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_127:
	/* 0x127: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_12b:
	/* 0x12b: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_12e:
	/* 0x12e: jmp    1bc <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x12e, 0x1bc, x86_l_1bc);
x86_l_133:
	/* 0x133: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_139:
	/* 0x139: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_13e:
	/* 0x13e: jb     171 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13e, 0x171, x86_l_171);
x86_l_140:
	/* 0x140: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_146:
	/* 0x146: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_14b:
	/* 0x14b: jb     171 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14b, 0x171, x86_l_171);
x86_l_14d:
	/* 0x14d: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_153:
	/* 0x153: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_158:
	/* 0x158: jb     171 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x158, 0x171, x86_l_171);
x86_l_15a:
	/* 0x15a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d:
	/* 0x15d: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_162:
	/* 0x162: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_166:
	/* 0x166: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_16a:
	/* 0x16a: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_171:
	/* 0x171: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_178:
	/* 0x178: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_17e:
	/* 0x17e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_181:
	/* 0x181: jg     194 <filter_char_buf_equal+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x181, 0x194, x86_l_194);
x86_l_183:
	/* 0x183: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_185:
	/* 0x185: je     1ae <filter_char_buf_equal+0xfb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x185, 0x1ae, x86_l_1ae);
x86_l_187:
	/* 0x187: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18a:
	/* 0x18a: jne    1a6 <filter_char_buf_equal+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x18a, 0x1a6, x86_l_1a6);
x86_l_18c:
	/* 0x18c: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_192:
	/* 0x192: jmp    1bc <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x192, 0x1bc, x86_l_1bc);
x86_l_194:
	/* 0x194: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_197:
	/* 0x197: je     1b6 <filter_char_buf_equal+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x197, 0x1b6, x86_l_1b6);
x86_l_199:
	/* 0x199: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_19c:
	/* 0x19c: jne    1a6 <filter_char_buf_equal+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x19c, 0x1a6, x86_l_1a6);
x86_l_19e:
	/* 0x19e: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1a4:
	/* 0x1a4: jmp    1bc <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x1a4, 0x1bc, x86_l_1bc);
x86_l_1a6:
	/* 0x1a6: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1ac:
	/* 0x1ac: jmp    1bc <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x1ac, 0x1bc, x86_l_1bc);
x86_l_1ae:
	/* 0x1ae: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1b4:
	/* 0x1b4: jmp    1bc <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x1b4, 0x1bc, x86_l_1bc);
x86_l_1b6:
	/* 0x1b6: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1bc:
	/* 0x1bc: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1bf:
	/* 0x1bf: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c2:
	/* 0x1c2: mov    ebx,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1c6:
	/* 0x1c6: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c9:
	/* 0x1c9: je     3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c9, 0x3d7, x86_l_3d7);
x86_l_1cf:
	/* 0x1cf: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d9:
	/* 0x1d9: mov    rdi,QWORD PTR [rip+0x1ac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1e0:
	/* 0x1e0: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5:
	/* 0x1e5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea:
	/* 0x1ea: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1ed:
	/* 0x1ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f2:
	/* 0x1f2: mov    rdi,QWORD PTR [rip+0x1ac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1f9:
	/* 0x1f9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1fc:
	/* 0x1fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe:
	/* 0x1fe: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_201:
	/* 0x201: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203:
	/* 0x203: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207:
	/* 0x207: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_20a:
	/* 0x20a: je     3d9 <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x20a, 0x3d9, x86_l_3d9);
x86_l_210:
	/* 0x210: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_213:
	/* 0x213: je     3d9 <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x213, 0x3d9, x86_l_3d9);
x86_l_219:
	/* 0x219: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_21d:
	/* 0x21d: jg     258 <filter_char_buf_equal+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x21d, 0x258, x86_l_258);
x86_l_21f:
	/* 0x21f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223:
	/* 0x223: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226:
	/* 0x226: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22a:
	/* 0x22a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f:
	/* 0x22f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_231:
	/* 0x231: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236:
	/* 0x236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238:
	/* 0x238: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23b:
	/* 0x23b: jbe    298 <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x23b, 0x298, x86_l_298);
x86_l_23d:
	/* 0x23d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_23f:
	/* 0x23f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243:
	/* 0x243: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_247:
	/* 0x247: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_24a:
	/* 0x24a: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_251:
	/* 0x251: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_256:
	/* 0x256: jmp    290 <filter_char_buf_equal+0x1dd> */
	X86_SIM_X86_SUB_JMP(0x256, 0x290, x86_l_290);
x86_l_258:
	/* 0x258: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c:
	/* 0x25c: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f:
	/* 0x25f: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_263:
	/* 0x263: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_268:
	/* 0x268: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_26a:
	/* 0x26a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f:
	/* 0x26f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271:
	/* 0x271: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_274:
	/* 0x274: jbe    298 <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x274, 0x298, x86_l_298);
x86_l_276:
	/* 0x276: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_278:
	/* 0x278: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c:
	/* 0x27c: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_280:
	/* 0x280: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_284:
	/* 0x284: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28b:
	/* 0x28b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_290:
	/* 0x290: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_293:
	/* 0x293: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_296:
	/* 0x296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298:
	/* 0x298: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29c:
	/* 0x29c: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2a0:
	/* 0x2a0: jle    2d7 <filter_char_buf_equal+0x224> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2a0, 0x2d7, x86_l_2d7);
x86_l_2a2:
	/* 0x2a2: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_2a6:
	/* 0x2a6: jg     308 <filter_char_buf_equal+0x255> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2a6, 0x308, x86_l_308);
x86_l_2a8:
	/* 0x2a8: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_2ac:
	/* 0x2ac: je     396 <filter_char_buf_equal+0x2e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2ac, 0x396, x86_l_396);
x86_l_2b2:
	/* 0x2b2: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_2b6:
	/* 0x2b6: je     36c <filter_char_buf_equal+0x2b9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2b6, 0x36c, x86_l_36c);
x86_l_2bc:
	/* 0x2bc: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_2c0:
	/* 0x2c0: jne    3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2c0, 0x3d7, x86_l_3d7);
x86_l_2c6:
	/* 0x2c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb:
	/* 0x2cb: mov    rdi,QWORD PTR [rip+0x1ac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2d2:
	/* 0x2d2: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x2d2, 0x3b0, x86_l_3b0);
x86_l_2d7:
	/* 0x2d7: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2db:
	/* 0x2db: jle    333 <filter_char_buf_equal+0x280> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x2db, 0x333, x86_l_333);
x86_l_2dd:
	/* 0x2dd: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2e1:
	/* 0x2e1: je     388 <filter_char_buf_equal+0x2d5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2e1, 0x388, x86_l_388);
x86_l_2e7:
	/* 0x2e7: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2eb:
	/* 0x2eb: je     35e <filter_char_buf_equal+0x2ab> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2eb, 0x35e, x86_l_35e);
x86_l_2ed:
	/* 0x2ed: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2f1:
	/* 0x2f1: jne    3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2f1, 0x3d7, x86_l_3d7);
x86_l_2f7:
	/* 0x2f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fc:
	/* 0x2fc: mov    rdi,QWORD PTR [rip+0x1ac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_303:
	/* 0x303: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x303, 0x3b0, x86_l_3b0);
x86_l_308:
	/* 0x308: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_30c:
	/* 0x30c: je     3a4 <filter_char_buf_equal+0x2f1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x30c, 0x3a4, x86_l_3a4);
x86_l_312:
	/* 0x312: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_316:
	/* 0x316: je     37a <filter_char_buf_equal+0x2c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x316, 0x37a, x86_l_37a);
x86_l_318:
	/* 0x318: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_31c:
	/* 0x31c: jne    3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x31c, 0x3d7, x86_l_3d7);
x86_l_322:
	/* 0x322: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_327:
	/* 0x327: mov    rdi,QWORD PTR [rip+0x1ac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_32e:
	/* 0x32e: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x32e, 0x3b0, x86_l_3b0);
x86_l_333:
	/* 0x333: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_336:
	/* 0x336: je     350 <filter_char_buf_equal+0x29d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x336, 0x350, x86_l_350);
x86_l_338:
	/* 0x338: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_33c:
	/* 0x33c: jne    3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x33c, 0x3d7, x86_l_3d7);
x86_l_342:
	/* 0x342: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_347:
	/* 0x347: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_34e:
	/* 0x34e: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x34e, 0x3b0, x86_l_3b0);
x86_l_350:
	/* 0x350: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_355:
	/* 0x355: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_35c:
	/* 0x35c: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x35c, 0x3b0, x86_l_3b0);
x86_l_35e:
	/* 0x35e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_363:
	/* 0x363: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_36a:
	/* 0x36a: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x36a, 0x3b0, x86_l_3b0);
x86_l_36c:
	/* 0x36c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_371:
	/* 0x371: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_378:
	/* 0x378: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x378, 0x3b0, x86_l_3b0);
x86_l_37a:
	/* 0x37a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37f:
	/* 0x37f: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_386:
	/* 0x386: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x386, 0x3b0, x86_l_3b0);
x86_l_388:
	/* 0x388: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38d:
	/* 0x38d: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_394:
	/* 0x394: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x394, 0x3b0, x86_l_3b0);
x86_l_396:
	/* 0x396: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39b:
	/* 0x39b: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3a2:
	/* 0x3a2: jmp    3b0 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x3a2, 0x3b0, x86_l_3b0);
x86_l_3a4:
	/* 0x3a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a9:
	/* 0x3a9: mov    rdi,QWORD PTR [rip+0x1abd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_3b0:
	/* 0x3b0: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3b5:
	/* 0x3b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b7:
	/* 0x3b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ba:
	/* 0x3ba: je     3d7 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3ba, 0x3d7, x86_l_3d7);
x86_l_3bc:
	/* 0x3bc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3c1:
	/* 0x3c1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3c4:
	/* 0x3c4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c8:
	/* 0x3c8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3ca:
	/* 0x3ca: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3cd:
	/* 0x3cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cf:
	/* 0x3cf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3d2:
	/* 0x3d2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_3d5:
	/* 0x3d5: jmp    3d9 <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JMP(0x3d5, 0x3d9, x86_l_3d9);
x86_l_3d7:
	/* 0x3d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d9:
	/* 0x3d9: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3dd:
	/* 0x3dd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3de:
	/* 0x3de: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3e0:
	/* 0x3e0: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3e2:
	/* 0x3e2: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3e4:
	/* 0x3e4: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3e6:
	/* 0x3e6: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3e7:
	/* 0x3e7: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_3e8 */
x86_l_3e8:
	/* 0x3e8: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3e9:
	/* 0x3e9: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3eb:
	/* 0x3eb: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3ec:
	/* 0x3ec: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_3f0:
	/* 0x3f0: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_3f2:
	/* 0x3f2: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_3f5:
	/* 0x3f5: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f9:
	/* 0x3f9: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_401:
	/* 0x401: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_406:
	/* 0x406: mov    rdi,QWORD PTR [rip+0x1e00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_40d:
	/* 0x40d: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_412:
	/* 0x412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414:
	/* 0x414: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_417:
	/* 0x417: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_419:
	/* 0x419: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_41b:
	/* 0x41b: je     481 <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x41b, 0x481, x86_l_481);
x86_l_41d:
	/* 0x41d: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_420:
	/* 0x420: je     481 <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x420, 0x481, x86_l_481);
x86_l_422:
	/* 0x422: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_427:
	/* 0x427: mov    rdi,QWORD PTR [rip+0x1e00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_42e:
	/* 0x42e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_433:
	/* 0x433: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_435:
	/* 0x435: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_438:
	/* 0x438: je     47f <filter_char_buf_prefix+0x97> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x438, 0x47f, x86_l_47f);
x86_l_43a:
	/* 0x43a: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_440:
	/* 0x440: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_445:
	/* 0x445: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_448:
	/* 0x448: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_44f:
	/* 0x44f: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_451:
	/* 0x451: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_454:
	/* 0x454: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_458:
	/* 0x458: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_45d:
	/* 0x45d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_460:
	/* 0x460: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_463:
	/* 0x463: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_465:
	/* 0x465: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46a:
	/* 0x46a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_46d:
	/* 0x46d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_470:
	/* 0x470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_472:
	/* 0x472: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_475:
	/* 0x475: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_477:
	/* 0x477: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_47a:
	/* 0x47a: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_47d:
	/* 0x47d: jmp    481 <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JMP(0x47d, 0x481, x86_l_481);
x86_l_47f:
	/* 0x47f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_481:
	/* 0x481: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_485:
	/* 0x485: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_486:
	/* 0x486: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_488:
	/* 0x488: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_489:
	/* 0x489: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_48a */
x86_l_48a:
	/* 0x48a: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_48c:
	/* 0x48c: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_48d:
	/* 0x48d: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_491:
	/* 0x491: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_494:
	/* 0x494: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_497:
	/* 0x497: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_49b:
	/* 0x49b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_49f:
	/* 0x49f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a4:
	/* 0x4a4: mov    rdi,QWORD PTR [rip+0xa20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_4ab:
	/* 0x4ab: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4b0:
	/* 0x4b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2:
	/* 0x4b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b5:
	/* 0x4b5: je     4ea <filter_32ty_map+0x60> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4b5, 0x4ea, x86_l_4ea);
x86_l_4b7:
	/* 0x4b7: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ba:
	/* 0x4ba: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bf:
	/* 0x4bf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4c4:
	/* 0x4c4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c9:
	/* 0x4c9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4cc:
	/* 0x4cc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4ce:
	/* 0x4ce: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d1:
	/* 0x4d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d3:
	/* 0x4d3: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_4d6:
	/* 0x4d6: ja     504 <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x4d6, 0x504, x86_l_504);
x86_l_4d8:
	/* 0x4d8: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_4dd:
	/* 0x4dd: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_4e0:
	/* 0x4e0: jae    4f4 <filter_32ty_map+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x4e0, 0x4f4, x86_l_4f4);
x86_l_4e2:
	/* 0x4e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e5:
	/* 0x4e5: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_4e8:
	/* 0x4e8: jmp    504 <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JMP(0x4e8, 0x504, x86_l_504);
x86_l_4ea:
	/* 0x4ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ec:
	/* 0x4ec: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_4f0:
	/* 0x4f0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4f3:
	/* 0x4f3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_4f4:
	/* 0x4f4: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_4f9:
	/* 0x4f9: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_4fc:
	/* 0x4fc: jae    504 <filter_32ty_map+0x7a> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x4fc, 0x504, x86_l_504);
x86_l_4fe:
	/* 0x4fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_501:
	/* 0x501: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_504:
	/* 0x504: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_507:
	/* 0x507: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_50b:
	/* 0x50b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_50c:
	/* 0x50c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_50e:
	/* 0x50e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x2cULL: goto x86_l_2c;
	case 0x73ULL: goto x86_l_73;
	case 0xaaULL: goto x86_l_aa;
	case 0x1eaULL: goto x86_l_1ea;
	case 0x1feULL: goto x86_l_1fe;
	case 0x238ULL: goto x86_l_238;
	case 0x271ULL: goto x86_l_271;
	case 0x298ULL: goto x86_l_298;
	case 0x3b7ULL: goto x86_l_3b7;
	case 0x3caULL: goto x86_l_3ca;
	case 0x414ULL: goto x86_l_414;
	case 0x435ULL: goto x86_l_435;
	case 0x465ULL: goto x86_l_465;
	case 0x472ULL: goto x86_l_472;
	case 0x4b2ULL: goto x86_l_4b2;
	case 0x4ceULL: goto x86_l_4ce;
	}

}

X86_SIM_LICENSE();
