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
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
extern char substring_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_kprobe_v61_filter_char_buf_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_3:
	/* 0x3: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_6:
	/* 0x6: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_9:
	/* 0x9: mov    edx,DWORD PTR [rsi+rcx*1-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 18446744073709551612ULL);
x86_l_d:
	/* 0xd: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_f:
	/* 0xf: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12:
	/* 0x12: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15:
	/* 0x15: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17:
	/* 0x17: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1a:
	/* 0x1a: jg     30 <filter_char_buf+0x30> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1a, 0x30, x86_l_30);
x86_l_1c:
	/* 0x1c: lea    edi,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1f:
	/* 0x1f: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_22:
	/* 0x22: jb     67 <filter_char_buf+0x67> */
	X86_SIM_X86_JCC(X86_CC_B, 0x22, 0x67, x86_l_67);
x86_l_24:
	/* 0x24: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27:
	/* 0x27: je     5d <filter_char_buf+0x5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27, 0x5d, x86_l_5d);
x86_l_29:
	/* 0x29: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2c:
	/* 0x2c: je     3f <filter_char_buf+0x3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c, 0x3f, x86_l_3f);
x86_l_2e:
	/* 0x2e: jmp    7e <filter_char_buf+0x7e> */
	X86_SIM_X86_JMP(0x2e, 0x7e, x86_l_7e);
x86_l_30:
	/* 0x30: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_33:
	/* 0x33: jg     49 <filter_char_buf+0x49> */
	X86_SIM_X86_JCC(X86_CC_G, 0x33, 0x49, x86_l_49);
x86_l_35:
	/* 0x35: cmp    ecx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 26ULL);
x86_l_38:
	/* 0x38: je     5d <filter_char_buf+0x5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0x5d, x86_l_5d);
x86_l_3a:
	/* 0x3a: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_3d:
	/* 0x3d: jne    7e <filter_char_buf+0x7e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3d, 0x7e, x86_l_7e);
x86_l_3f:
	/* 0x3f: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42:
	/* 0x42: call   a5 <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_a5, 0x47ULL);
x86_l_47:
	/* 0x47: jmp    7b <filter_char_buf+0x7b> */
	X86_SIM_X86_JMP(0x47, 0x7b, x86_l_7b);
x86_l_49:
	/* 0x49: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_4c:
	/* 0x4c: je     71 <filter_char_buf+0x71> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c, 0x71, x86_l_71);
x86_l_4e:
	/* 0x4e: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_51:
	/* 0x51: jne    7e <filter_char_buf+0x7e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x51, 0x7e, x86_l_7e);
x86_l_53:
	/* 0x53: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b:
	/* 0x5b: jmp    76 <filter_char_buf+0x76> */
	X86_SIM_X86_JMP(0x5b, 0x76, x86_l_76);
x86_l_5d:
	/* 0x5d: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60:
	/* 0x60: call   1ed <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_1ed, 0x65ULL);
x86_l_65:
	/* 0x65: jmp    7b <filter_char_buf+0x7b> */
	X86_SIM_X86_JMP(0x65, 0x7b, x86_l_7b);
x86_l_67:
	/* 0x67: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: call   28d <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_28d, 0x6fULL);
x86_l_6f:
	/* 0x6f: jmp    7b <filter_char_buf+0x7b> */
	X86_SIM_X86_JMP(0x6f, 0x7b, x86_l_7b);
x86_l_71:
	/* 0x71: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_76:
	/* 0x76: call   61a <filter_char_substring> */
	X86_SIM_X86_CALL(x86_l_61a, 0x7bULL);
x86_l_7b:
	/* 0x7b: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7e:
	/* 0x7e: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_81:
	/* 0x81: ja     a0 <filter_char_buf+0xa0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x81, 0xa0, x86_l_a0);
x86_l_83:
	/* 0x83: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_8f:
	/* 0x8f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: jae    a0 <filter_char_buf+0xa0> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x93, 0xa0, x86_l_a0);
x86_l_95:
	/* 0x95: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_97:
	/* 0x97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_9d:
	/* 0x9d: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: jmp    830 <filter_char_substring+0x216> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_830:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_a5 */
x86_l_a5:
	/* 0xa5: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_a7:
	/* 0xa7: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_a9:
	/* 0xa9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_aa:
	/* 0xaa: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_ae:
	/* 0xae: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_b0:
	/* 0xb0: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_b3:
	/* 0xb3: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_bf:
	/* 0xbf: mov    rdi,QWORD PTR [rip+0x2440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_c6:
	/* 0xc6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_cb:
	/* 0xcb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0:
	/* 0xd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2:
	/* 0xd2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7:
	/* 0xd7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_d9:
	/* 0xd9: je     1e3 <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd9, 0x1e3, x86_l_1e3);
x86_l_df:
	/* 0xdf: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_e2:
	/* 0xe2: je     1e3 <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xe2, 0x1e3, x86_l_1e3);
x86_l_e8:
	/* 0xe8: mov    rdi,QWORD PTR [rip+0x2440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_ef:
	/* 0xef: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4:
	/* 0xf4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f9:
	/* 0xf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb:
	/* 0xfb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: je     1e1 <filter_char_buf_postfix+0x13c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xfe, 0x1e1, x86_l_1e1);
x86_l_104:
	/* 0x104: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_107:
	/* 0x107: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_10a:
	/* 0x10a: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_10f:
	/* 0x10f: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_112:
	/* 0x112: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_115:
	/* 0x115: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117:
	/* 0x117: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_119:
	/* 0x119: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_11c:
	/* 0x11c: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_123:
	/* 0x123: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_126:
	/* 0x126: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_12a:
	/* 0x12a: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_12c:
	/* 0x12c: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_133:
	/* 0x133: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_137:
	/* 0x137: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_13b:
	/* 0x13b: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_142:
	/* 0x142: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_147:
	/* 0x147: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_14b:
	/* 0x14b: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_14f:
	/* 0x14f: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_153:
	/* 0x153: je     1ca <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x153, 0x1ca, x86_l_1ca);
x86_l_155:
	/* 0x155: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_159:
	/* 0x159: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_15d:
	/* 0x15d: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_164:
	/* 0x164: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_169:
	/* 0x169: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_16d:
	/* 0x16d: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_171:
	/* 0x171: je     1ca <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x171, 0x1ca, x86_l_1ca);
x86_l_173:
	/* 0x173: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_177:
	/* 0x177: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_17b:
	/* 0x17b: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_182:
	/* 0x182: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_187:
	/* 0x187: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_18b:
	/* 0x18b: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_18e:
	/* 0x18e: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_191:
	/* 0x191: je     1ca <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x191, 0x1ca, x86_l_1ca);
x86_l_193:
	/* 0x193: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_197:
	/* 0x197: je     1ca <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x197, 0x1ca, x86_l_1ca);
x86_l_199:
	/* 0x199: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_19d:
	/* 0x19d: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_1a1:
	/* 0x1a1: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a8:
	/* 0x1a8: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1ad:
	/* 0x1ad: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0:
	/* 0x1b0: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b4:
	/* 0x1b4: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1b8:
	/* 0x1b8: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1bc:
	/* 0x1bc: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1c0:
	/* 0x1c0: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1c4:
	/* 0x1c4: jne    133 <filter_char_buf_postfix+0x8e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1c4, 0x133, x86_l_133);
x86_l_1ca:
	/* 0x1ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cf:
	/* 0x1cf: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d2:
	/* 0x1d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4:
	/* 0x1d4: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d7:
	/* 0x1d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9:
	/* 0x1d9: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1dc:
	/* 0x1dc: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1df:
	/* 0x1df: jmp    1e3 <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JMP(0x1df, 0x1e3, x86_l_1e3);
x86_l_1e1:
	/* 0x1e1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e3:
	/* 0x1e3: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e7:
	/* 0x1e7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1ea:
	/* 0x1ea: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1ec:
	/* 0x1ec: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_1ed */
x86_l_1ed:
	/* 0x1ed: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1ee:
	/* 0x1ee: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1f0:
	/* 0x1f0: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f2:
	/* 0x1f2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f3:
	/* 0x1f3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1f4:
	/* 0x1f4: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1f6:
	/* 0x1f6: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1f9:
	/* 0x1f9: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fd:
	/* 0x1fd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_204:
	/* 0x204: mov    rdi,QWORD PTR [rip+0x23a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_20b:
	/* 0x20b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_210:
	/* 0x210: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_215:
	/* 0x215: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217:
	/* 0x217: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_21a:
	/* 0x21a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c:
	/* 0x21c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_21e:
	/* 0x21e: je     282 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x21e, 0x282, x86_l_282);
x86_l_220:
	/* 0x220: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_223:
	/* 0x223: je     282 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x223, 0x282, x86_l_282);
x86_l_225:
	/* 0x225: mov    rdi,QWORD PTR [rip+0x23a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_22c:
	/* 0x22c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_22f:
	/* 0x22f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_234:
	/* 0x234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236:
	/* 0x236: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_239:
	/* 0x239: je     280 <filter_char_buf_prefix+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x239, 0x280, x86_l_280);
x86_l_23b:
	/* 0x23b: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_241:
	/* 0x241: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_246:
	/* 0x246: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_249:
	/* 0x249: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_250:
	/* 0x250: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252:
	/* 0x252: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_255:
	/* 0x255: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_259:
	/* 0x259: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_25c:
	/* 0x25c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_261:
	/* 0x261: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_264:
	/* 0x264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_266:
	/* 0x266: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26b:
	/* 0x26b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_26e:
	/* 0x26e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_271:
	/* 0x271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273:
	/* 0x273: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_276:
	/* 0x276: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_278:
	/* 0x278: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_27b:
	/* 0x27b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_27e:
	/* 0x27e: jmp    282 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JMP(0x27e, 0x282, x86_l_282);
x86_l_280:
	/* 0x280: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_282:
	/* 0x282: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_286:
	/* 0x286: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_287:
	/* 0x287: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_289:
	/* 0x289: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_28c:
	/* 0x28c: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_28d */
x86_l_28d:
	/* 0x28d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_28e:
	/* 0x28e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_290:
	/* 0x290: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_292:
	/* 0x292: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_294:
	/* 0x294: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_296:
	/* 0x296: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_297:
	/* 0x297: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_29b:
	/* 0x29b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2a3:
	/* 0x2a3: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_2a9:
	/* 0x2a9: ja     609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2a9, 0x609, x86_l_609);
x86_l_2af:
	/* 0x2af: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b2:
	/* 0x2b2: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_2b7:
	/* 0x2b7: ja     30a <filter_char_buf_equal+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2b7, 0x30a, x86_l_30a);
x86_l_2b9:
	/* 0x2b9: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bc:
	/* 0x2bc: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2c2:
	/* 0x2c2: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2c5:
	/* 0x2c5: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2c8:
	/* 0x2c8: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_2cb:
	/* 0x2cb: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2cd:
	/* 0x2cd: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2d0:
	/* 0x2d0: je     2db <filter_char_buf_equal+0x4e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d0, 0x2db, x86_l_2db);
x86_l_2d2:
	/* 0x2d2: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2d4:
	/* 0x2d4: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_2d7:
	/* 0x2d7: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2d9:
	/* 0x2d9: je     2f4 <filter_char_buf_equal+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d9, 0x2f4, x86_l_2f4);
x86_l_2db:
	/* 0x2db: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2de:
	/* 0x2de: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e0:
	/* 0x2e0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e2:
	/* 0x2e2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2e4:
	/* 0x2e4: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2e7:
	/* 0x2e7: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2eb:
	/* 0x2eb: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2ef:
	/* 0x2ef: ja     348 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2ef, 0x348, x86_l_348);
x86_l_2f1:
	/* 0x2f1: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_2f4:
	/* 0x2f4: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f7:
	/* 0x2f7: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2fe:
	/* 0x2fe: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_302:
	/* 0x302: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_305:
	/* 0x305: jmp    393 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x305, 0x393, x86_l_393);
x86_l_30a:
	/* 0x30a: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_310:
	/* 0x310: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_315:
	/* 0x315: jb     348 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x315, 0x348, x86_l_348);
x86_l_317:
	/* 0x317: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_31d:
	/* 0x31d: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_322:
	/* 0x322: jb     348 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x322, 0x348, x86_l_348);
x86_l_324:
	/* 0x324: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_32a:
	/* 0x32a: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_32f:
	/* 0x32f: jb     348 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x32f, 0x348, x86_l_348);
x86_l_331:
	/* 0x331: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_334:
	/* 0x334: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_339:
	/* 0x339: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_33d:
	/* 0x33d: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_341:
	/* 0x341: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_348:
	/* 0x348: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_34f:
	/* 0x34f: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_355:
	/* 0x355: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_358:
	/* 0x358: jg     36b <filter_char_buf_equal+0xde> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x358, 0x36b, x86_l_36b);
x86_l_35a:
	/* 0x35a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35c:
	/* 0x35c: je     385 <filter_char_buf_equal+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x35c, 0x385, x86_l_385);
x86_l_35e:
	/* 0x35e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_361:
	/* 0x361: jne    37d <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x361, 0x37d, x86_l_37d);
x86_l_363:
	/* 0x363: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_369:
	/* 0x369: jmp    393 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x369, 0x393, x86_l_393);
x86_l_36b:
	/* 0x36b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_36e:
	/* 0x36e: je     38d <filter_char_buf_equal+0x100> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x36e, 0x38d, x86_l_38d);
x86_l_370:
	/* 0x370: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_373:
	/* 0x373: jne    37d <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x373, 0x37d, x86_l_37d);
x86_l_375:
	/* 0x375: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_37b:
	/* 0x37b: jmp    393 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x37b, 0x393, x86_l_393);
x86_l_37d:
	/* 0x37d: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_383:
	/* 0x383: jmp    393 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x383, 0x393, x86_l_393);
x86_l_385:
	/* 0x385: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_38b:
	/* 0x38b: jmp    393 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x38b, 0x393, x86_l_393);
x86_l_38d:
	/* 0x38d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_393:
	/* 0x393: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_396:
	/* 0x396: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_399:
	/* 0x399: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_39e:
	/* 0x39e: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_3a2:
	/* 0x3a2: je     609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3a2, 0x609, x86_l_609);
x86_l_3a8:
	/* 0x3a8: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ad:
	/* 0x3ad: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_3af:
	/* 0x3af: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3b6:
	/* 0x3b6: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3bb:
	/* 0x3bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c0:
	/* 0x3c0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3c3:
	/* 0x3c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c5:
	/* 0x3c5: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3c8:
	/* 0x3c8: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3cf:
	/* 0x3cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d4:
	/* 0x3d4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3d7:
	/* 0x3d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d9:
	/* 0x3d9: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3dc:
	/* 0x3dc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3de:
	/* 0x3de: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e3:
	/* 0x3e3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_3e6:
	/* 0x3e6: je     60b <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3e6, 0x60b, x86_l_60b);
x86_l_3ec:
	/* 0x3ec: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3ef:
	/* 0x3ef: je     60b <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3ef, 0x60b, x86_l_60b);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3fa:
	/* 0x3fa: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3fe:
	/* 0x3fe: jg     441 <filter_char_buf_equal+0x1b4> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3fe, 0x441, x86_l_441);
x86_l_400:
	/* 0x400: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_405:
	/* 0x405: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_408:
	/* 0x408: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_40c:
	/* 0x40c: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_40f:
	/* 0x40f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_414:
	/* 0x414: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_419:
	/* 0x419: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_41b:
	/* 0x41b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d:
	/* 0x41d: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_420:
	/* 0x420: jbe    486 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x420, 0x486, x86_l_486);
x86_l_422:
	/* 0x422: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_427:
	/* 0x427: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_42b:
	/* 0x42b: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_42e:
	/* 0x42e: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_435:
	/* 0x435: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43a:
	/* 0x43a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43f:
	/* 0x43f: jmp    481 <filter_char_buf_equal+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x43f, 0x481, x86_l_481);
x86_l_441:
	/* 0x441: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_446:
	/* 0x446: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_449:
	/* 0x449: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_44d:
	/* 0x44d: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_450:
	/* 0x450: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_455:
	/* 0x455: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45a:
	/* 0x45a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_45c:
	/* 0x45c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45e:
	/* 0x45e: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_461:
	/* 0x461: jbe    486 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x461, 0x486, x86_l_486);
x86_l_463:
	/* 0x463: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_468:
	/* 0x468: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_46c:
	/* 0x46c: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_470:
	/* 0x470: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_477:
	/* 0x477: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47c:
	/* 0x47c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_481:
	/* 0x481: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_484:
	/* 0x484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_486:
	/* 0x486: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_48b:
	/* 0x48b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_48f:
	/* 0x48f: jle    4cb <filter_char_buf_equal+0x23e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x48f, 0x4cb, x86_l_4cb);
x86_l_491:
	/* 0x491: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_495:
	/* 0x495: jg     505 <filter_char_buf_equal+0x278> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x495, 0x505, x86_l_505);
x86_l_497:
	/* 0x497: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_49b:
	/* 0x49b: je     5bd <filter_char_buf_equal+0x330> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x49b, 0x5bd, x86_l_5bd);
x86_l_4a1:
	/* 0x4a1: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_4a5:
	/* 0x4a5: je     584 <filter_char_buf_equal+0x2f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4a5, 0x584, x86_l_584);
x86_l_4ab:
	/* 0x4ab: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_4af:
	/* 0x4af: jne    609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4af, 0x609, x86_l_609);
x86_l_4b5:
	/* 0x4b5: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_4bc:
	/* 0x4bc: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c1:
	/* 0x4c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c6:
	/* 0x4c6: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x4c6, 0x5e1, x86_l_5e1);
x86_l_4cb:
	/* 0x4cb: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_4cf:
	/* 0x4cf: jle    539 <filter_char_buf_equal+0x2ac> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x4cf, 0x539, x86_l_539);
x86_l_4d1:
	/* 0x4d1: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_4d5:
	/* 0x4d5: je     5aa <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4d5, 0x5aa, x86_l_5aa);
x86_l_4db:
	/* 0x4db: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_4df:
	/* 0x4df: je     571 <filter_char_buf_equal+0x2e4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4df, 0x571, x86_l_571);
x86_l_4e5:
	/* 0x4e5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_4e9:
	/* 0x4e9: jne    609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4e9, 0x609, x86_l_609);
x86_l_4ef:
	/* 0x4ef: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_4f6:
	/* 0x4f6: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4fb:
	/* 0x4fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_500:
	/* 0x500: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x500, 0x5e1, x86_l_5e1);
x86_l_505:
	/* 0x505: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_509:
	/* 0x509: je     5d0 <filter_char_buf_equal+0x343> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x509, 0x5d0, x86_l_5d0);
x86_l_50f:
	/* 0x50f: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_513:
	/* 0x513: je     597 <filter_char_buf_equal+0x30a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x513, 0x597, x86_l_597);
x86_l_519:
	/* 0x519: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_51d:
	/* 0x51d: jne    609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x51d, 0x609, x86_l_609);
x86_l_523:
	/* 0x523: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_52a:
	/* 0x52a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_52f:
	/* 0x52f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_534:
	/* 0x534: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x534, 0x5e1, x86_l_5e1);
x86_l_539:
	/* 0x539: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_53c:
	/* 0x53c: je     55e <filter_char_buf_equal+0x2d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x53c, 0x55e, x86_l_55e);
x86_l_53e:
	/* 0x53e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_542:
	/* 0x542: jne    609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x542, 0x609, x86_l_609);
x86_l_548:
	/* 0x548: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_54f:
	/* 0x54f: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_554:
	/* 0x554: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_559:
	/* 0x559: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x559, 0x5e1, x86_l_5e1);
x86_l_55e:
	/* 0x55e: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_565:
	/* 0x565: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56a:
	/* 0x56a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_56f:
	/* 0x56f: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x56f, 0x5e1, x86_l_5e1);
x86_l_571:
	/* 0x571: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_578:
	/* 0x578: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_57d:
	/* 0x57d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_582:
	/* 0x582: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x582, 0x5e1, x86_l_5e1);
x86_l_584:
	/* 0x584: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_58b:
	/* 0x58b: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_590:
	/* 0x590: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_595:
	/* 0x595: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x595, 0x5e1, x86_l_5e1);
x86_l_597:
	/* 0x597: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_59e:
	/* 0x59e: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5a3:
	/* 0x5a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a8:
	/* 0x5a8: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x5a8, 0x5e1, x86_l_5e1);
x86_l_5aa:
	/* 0x5aa: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_5b1:
	/* 0x5b1: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5b6:
	/* 0x5b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5bb:
	/* 0x5bb: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x5bb, 0x5e1, x86_l_5e1);
x86_l_5bd:
	/* 0x5bd: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_5c4:
	/* 0x5c4: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5c9:
	/* 0x5c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ce:
	/* 0x5ce: jmp    5e1 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x5ce, 0x5e1, x86_l_5e1);
x86_l_5d0:
	/* 0x5d0: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_5d7:
	/* 0x5d7: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5dc:
	/* 0x5dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e1:
	/* 0x5e1: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5e6:
	/* 0x5e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e8:
	/* 0x5e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5eb:
	/* 0x5eb: je     609 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5eb, 0x609, x86_l_609);
x86_l_5ed:
	/* 0x5ed: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5f0:
	/* 0x5f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f5:
	/* 0x5f5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fa:
	/* 0x5fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc:
	/* 0x5fc: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5ff:
	/* 0x5ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_601:
	/* 0x601: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_604:
	/* 0x604: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_607:
	/* 0x607: jmp    60b <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JMP(0x607, 0x60b, x86_l_60b);
x86_l_609:
	/* 0x609: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60b:
	/* 0x60b: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_60f:
	/* 0x60f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_610:
	/* 0x610: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_612:
	/* 0x612: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_614:
	/* 0x614: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_616:
	/* 0x616: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_618:
	/* 0x618: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_619:
	/* 0x619: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_61a */
x86_l_61a:
	/* 0x61a: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_61b:
	/* 0x61b: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_61d:
	/* 0x61d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_61f:
	/* 0x61f: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_621:
	/* 0x621: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_623:
	/* 0x623: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_624:
	/* 0x624: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_625:
	/* 0x625: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_628:
	/* 0x628: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_62d:
	/* 0x62d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_62f:
	/* 0x62f: je     6f7 <filter_char_substring+0xdd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x62f, 0x6f7, x86_l_6f7);
x86_l_635:
	/* 0x635: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_637:
	/* 0x637: je     794 <filter_char_substring+0x17a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x637, 0x794, x86_l_794);
x86_l_63d:
	/* 0x63d: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_642:
	/* 0x642: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_644:
	/* 0x644: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_647:
	/* 0x647: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_64c:
	/* 0x64c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_650:
	/* 0x650: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_655:
	/* 0x655: mov    rdi,QWORD PTR [rip+0x2643] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_65c:
	/* 0x65c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_65f:
	/* 0x65f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_661:
	/* 0x661: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_664:
	/* 0x664: je     818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x664, 0x818, x86_l_818);
x86_l_66a:
	/* 0x66a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_66d:
	/* 0x66d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66f:
	/* 0x66f: jmp    67c <filter_char_substring+0x62> */
	X86_SIM_X86_SUB_JMP(0x66f, 0x67c, x86_l_67c);
x86_l_671:
	/* 0x671: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_674:
	/* 0x674: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_677:
	/* 0x677: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_67a:
	/* 0x67a: je     6d2 <filter_char_substring+0xb8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x67a, 0x6d2, x86_l_6d2);
x86_l_67c:
	/* 0x67c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67e:
	/* 0x67e: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_682:
	/* 0x682: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_685:
	/* 0x685: jae    671 <filter_char_substring+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x685, 0x671, x86_l_671);
x86_l_687:
	/* 0x687: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_68b:
	/* 0x68b: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_68d:
	/* 0x68d: je     6ca <filter_char_substring+0xb0> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x68d, 0x6ca, x86_l_6ca);
x86_l_68f:
	/* 0x68f: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_694:
	/* 0x694: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_698:
	/* 0x698: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_69b:
	/* 0x69b: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_69f:
	/* 0x69f: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_6a3:
	/* 0x6a3: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_6a7:
	/* 0x6a7: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_6ab:
	/* 0x6ab: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_6ae:
	/* 0x6ae: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_6b2:
	/* 0x6b2: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_6b6:
	/* 0x6b6: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_6ba:
	/* 0x6ba: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_6be:
	/* 0x6be: ja     671 <filter_char_substring+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x6be, 0x671, x86_l_671);
x86_l_6c0:
	/* 0x6c0: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6c3:
	/* 0x6c3: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_6c6:
	/* 0x6c6: je     67e <filter_char_substring+0x64> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6c6, 0x67e, x86_l_67e);
x86_l_6c8:
	/* 0x6c8: jmp    671 <filter_char_substring+0x57> */
	X86_SIM_X86_SUB_JMP(0x6c8, 0x671, x86_l_671);
x86_l_6ca:
	/* 0x6ca: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6cc:
	/* 0x6cc: jns    829 <filter_char_substring+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x6cc, 0x829, x86_l_829);
x86_l_6d2:
	/* 0x6d2: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6d7:
	/* 0x6d7: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_6db:
	/* 0x6db: jae    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6db, 0x818, x86_l_818);
x86_l_6e1:
	/* 0x6e1: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_6e5:
	/* 0x6e5: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6e8:
	/* 0x6e8: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_6ec:
	/* 0x6ec: jne    647 <filter_char_substring+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6ec, 0x647, x86_l_647);
x86_l_6f2:
	/* 0x6f2: jmp    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JMP(0x6f2, 0x818, x86_l_818);
x86_l_6f7:
	/* 0x6f7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6f9:
	/* 0x6f9: je     7d7 <filter_char_substring+0x1bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6f9, 0x7d7, x86_l_7d7);
x86_l_6ff:
	/* 0x6ff: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_704:
	/* 0x704: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_706:
	/* 0x706: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_709:
	/* 0x709: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_70e:
	/* 0x70e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_712:
	/* 0x712: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_717:
	/* 0x717: mov    rdi,QWORD PTR [rip+0x2651] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_71e:
	/* 0x71e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_721:
	/* 0x721: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_723:
	/* 0x723: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_726:
	/* 0x726: je     818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x726, 0x818, x86_l_818);
x86_l_72c:
	/* 0x72c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_72f:
	/* 0x72f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_731:
	/* 0x731: jmp    73e <filter_char_substring+0x124> */
	X86_SIM_X86_SUB_JMP(0x731, 0x73e, x86_l_73e);
x86_l_733:
	/* 0x733: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_736:
	/* 0x736: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_739:
	/* 0x739: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_73c:
	/* 0x73c: je     76f <filter_char_substring+0x155> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x73c, 0x76f, x86_l_76f);
x86_l_73e:
	/* 0x73e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_740:
	/* 0x740: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_744:
	/* 0x744: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_747:
	/* 0x747: jae    733 <filter_char_substring+0x119> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x747, 0x733, x86_l_733);
x86_l_749:
	/* 0x749: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_74d:
	/* 0x74d: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_750:
	/* 0x750: je     767 <filter_char_substring+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x750, 0x767, x86_l_767);
x86_l_752:
	/* 0x752: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_756:
	/* 0x756: ja     733 <filter_char_substring+0x119> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x756, 0x733, x86_l_733);
x86_l_758:
	/* 0x758: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_75c:
	/* 0x75c: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_760:
	/* 0x760: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_763:
	/* 0x763: je     740 <filter_char_substring+0x126> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x763, 0x740, x86_l_740);
x86_l_765:
	/* 0x765: jmp    733 <filter_char_substring+0x119> */
	X86_SIM_X86_SUB_JMP(0x765, 0x733, x86_l_733);
x86_l_767:
	/* 0x767: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_769:
	/* 0x769: jns    829 <filter_char_substring+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x769, 0x829, x86_l_829);
x86_l_76f:
	/* 0x76f: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_774:
	/* 0x774: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_778:
	/* 0x778: jae    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x778, 0x818, x86_l_818);
x86_l_77e:
	/* 0x77e: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_782:
	/* 0x782: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_785:
	/* 0x785: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_789:
	/* 0x789: jne    709 <filter_char_substring+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x789, 0x709, x86_l_709);
x86_l_78f:
	/* 0x78f: jmp    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JMP(0x78f, 0x818, x86_l_818);
x86_l_794:
	/* 0x794: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_799:
	/* 0x799: mov    r15,QWORD PTR [rip+0x2663] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_7a0:
	/* 0x7a0: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7a5:
	/* 0x7a5: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_7a9:
	/* 0x7a9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7ad:
	/* 0x7ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b2:
	/* 0x7b2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7b5:
	/* 0x7b5: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_7b8:
	/* 0x7b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ba:
	/* 0x7ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7bd:
	/* 0x7bd: je     818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x7bd, 0x818, x86_l_818);
x86_l_7bf:
	/* 0x7bf: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7c3:
	/* 0x7c3: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_7c6:
	/* 0x7c6: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_7ca:
	/* 0x7ca: jae    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7ca, 0x818, x86_l_818);
x86_l_7cc:
	/* 0x7cc: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_7d3:
	/* 0x7d3: jne    7a5 <filter_char_substring+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x7d3, 0x7a5, x86_l_7a5);
x86_l_7d5:
	/* 0x7d5: jmp    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JMP(0x7d5, 0x818, x86_l_818);
x86_l_7d7:
	/* 0x7d7: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_7dc:
	/* 0x7dc: mov    r15,QWORD PTR [rip+0x2665] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_7e3:
	/* 0x7e3: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7e8:
	/* 0x7e8: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_7ec:
	/* 0x7ec: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7f0:
	/* 0x7f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f5:
	/* 0x7f5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f8:
	/* 0x7f8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_7fb:
	/* 0x7fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fd:
	/* 0x7fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_800:
	/* 0x800: je     818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x800, 0x818, x86_l_818);
x86_l_802:
	/* 0x802: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_806:
	/* 0x806: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_809:
	/* 0x809: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_80d:
	/* 0x80d: jae    818 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x80d, 0x818, x86_l_818);
x86_l_80f:
	/* 0x80f: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_816:
	/* 0x816: jne    7e8 <filter_char_substring+0x1ce> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x816, 0x7e8, x86_l_7e8);
x86_l_818:
	/* 0x818: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_81a:
	/* 0x81a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_81e:
	/* 0x81e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_81f:
	/* 0x81f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_821:
	/* 0x821: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_823:
	/* 0x823: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_825:
	/* 0x825: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_827:
	/* 0x827: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_828:
	/* 0x828: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_829:
	/* 0x829: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_82e:
	/* 0x82e: jmp    81a <filter_char_substring+0x200> */
	X86_SIM_X86_SUB_JMP(0x82e, 0x81a, x86_l_81a);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x47ULL: goto x86_l_47;
	case 0x65ULL: goto x86_l_65;
	case 0x6fULL: goto x86_l_6f;
	case 0x7bULL: goto x86_l_7b;
	case 0xd2ULL: goto x86_l_d2;
	case 0xfbULL: goto x86_l_fb;
	case 0x1d4ULL: goto x86_l_1d4;
	case 0x217ULL: goto x86_l_217;
	case 0x236ULL: goto x86_l_236;
	case 0x266ULL: goto x86_l_266;
	case 0x273ULL: goto x86_l_273;
	case 0x3c5ULL: goto x86_l_3c5;
	case 0x3d9ULL: goto x86_l_3d9;
	case 0x41dULL: goto x86_l_41d;
	case 0x45eULL: goto x86_l_45e;
	case 0x486ULL: goto x86_l_486;
	case 0x5e8ULL: goto x86_l_5e8;
	case 0x5fcULL: goto x86_l_5fc;
	case 0x661ULL: goto x86_l_661;
	case 0x723ULL: goto x86_l_723;
	case 0x7baULL: goto x86_l_7ba;
	case 0x7fdULL: goto x86_l_7fd;
	}

}

X86_SIM_LICENSE();
