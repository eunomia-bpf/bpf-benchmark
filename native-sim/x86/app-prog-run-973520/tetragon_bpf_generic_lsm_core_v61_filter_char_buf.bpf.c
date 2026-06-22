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
int tetragon_bpf_generic_lsm_core_v61_filter_char_buf_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x6a: call   28f <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_28f, 0x6fULL);
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
	/* 0x76: call   5c4 <filter_char_substring> */
	X86_SIM_X86_CALL(x86_l_5c4, 0x7bULL);
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
	/* 0xa0: jmp    7da <filter_char_substring+0x216> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7da:
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
	/* 0xbf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c4:
	/* 0xc4: mov    rdi,QWORD PTR [rip+0x22b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_cb:
	/* 0xcb: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
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
	/* 0xe8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed:
	/* 0xed: mov    rdi,QWORD PTR [rip+0x22b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f4:
	/* 0xf4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x104: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_107:
	/* 0x107: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_10c:
	/* 0x10c: cmovb  ecx,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_10f:
	/* 0x10f: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_112:
	/* 0x112: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114:
	/* 0x114: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_116:
	/* 0x116: lea    edx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_119:
	/* 0x119: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_11c:
	/* 0x11c: add    rsi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_120:
	/* 0x120: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_123:
	/* 0x123: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_127:
	/* 0x127: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_129:
	/* 0x129: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_130:
	/* 0x130: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_134:
	/* 0x134: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_138:
	/* 0x138: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13f:
	/* 0x13f: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_144:
	/* 0x144: mov    BYTE PTR [rsi-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_148:
	/* 0x148: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_14c:
	/* 0x14c: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_150:
	/* 0x150: je     1c7 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x150, 0x1c7, x86_l_1c7);
x86_l_152:
	/* 0x152: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_156:
	/* 0x156: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_15a:
	/* 0x15a: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_161:
	/* 0x161: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_166:
	/* 0x166: mov    BYTE PTR [rsi-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_16a:
	/* 0x16a: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_16e:
	/* 0x16e: je     1c7 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x16e, 0x1c7, x86_l_1c7);
x86_l_170:
	/* 0x170: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_174:
	/* 0x174: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_178:
	/* 0x178: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17f:
	/* 0x17f: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_184:
	/* 0x184: mov    BYTE PTR [rsi-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_188:
	/* 0x188: mov    r10,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RCX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18e:
	/* 0x18e: je     1c7 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18e, 0x1c7, x86_l_1c7);
x86_l_190:
	/* 0x190: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_194:
	/* 0x194: je     1c7 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x194, 0x1c7, x86_l_1c7);
x86_l_196:
	/* 0x196: lea    r10d,[rdx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_19a:
	/* 0x19a: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_19e:
	/* 0x19e: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a5:
	/* 0x1a5: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1aa:
	/* 0x1aa: mov    BYTE PTR [rsi],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad:
	/* 0x1ad: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b1:
	/* 0x1b1: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1b5:
	/* 0x1b5: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1b9:
	/* 0x1b9: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_1bd:
	/* 0x1bd: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1c1:
	/* 0x1c1: jne    130 <filter_char_buf_postfix+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1c1, 0x130, x86_l_130);
x86_l_1c7:
	/* 0x1c7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1cc:
	/* 0x1cc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1cf:
	/* 0x1cf: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1d2:
	/* 0x1d2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
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
	/* 0x1ee: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f0:
	/* 0x1f0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f1:
	/* 0x1f1: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_1f5:
	/* 0x1f5: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1f7:
	/* 0x1f7: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_1fa:
	/* 0x1fa: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fe:
	/* 0x1fe: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_206:
	/* 0x206: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b:
	/* 0x20b: mov    rdi,QWORD PTR [rip+0x2200] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_212:
	/* 0x212: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_217:
	/* 0x217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219:
	/* 0x219: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_21c:
	/* 0x21c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e:
	/* 0x21e: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_220:
	/* 0x220: je     286 <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x220, 0x286, x86_l_286);
x86_l_222:
	/* 0x222: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_225:
	/* 0x225: je     286 <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x225, 0x286, x86_l_286);
x86_l_227:
	/* 0x227: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22c:
	/* 0x22c: mov    rdi,QWORD PTR [rip+0x2200] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_233:
	/* 0x233: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_238:
	/* 0x238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a:
	/* 0x23a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d:
	/* 0x23d: je     284 <filter_char_buf_prefix+0x97> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x23d, 0x284, x86_l_284);
x86_l_23f:
	/* 0x23f: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_245:
	/* 0x245: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_24a:
	/* 0x24a: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_24d:
	/* 0x24d: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_254:
	/* 0x254: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_256:
	/* 0x256: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_259:
	/* 0x259: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_25d:
	/* 0x25d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_262:
	/* 0x262: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_265:
	/* 0x265: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_268:
	/* 0x268: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_26a:
	/* 0x26a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26f:
	/* 0x26f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_272:
	/* 0x272: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_275:
	/* 0x275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277:
	/* 0x277: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27c:
	/* 0x27c: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_27f:
	/* 0x27f: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_282:
	/* 0x282: jmp    286 <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JMP(0x282, 0x286, x86_l_286);
x86_l_284:
	/* 0x284: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_286:
	/* 0x286: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28a:
	/* 0x28a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_28d:
	/* 0x28d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_28f */
x86_l_28f:
	/* 0x28f: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_290:
	/* 0x290: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_292:
	/* 0x292: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_294:
	/* 0x294: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_296:
	/* 0x296: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_298:
	/* 0x298: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_299:
	/* 0x299: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_29d:
	/* 0x29d: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a5:
	/* 0x2a5: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_2ab:
	/* 0x2ab: ja     5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2ab, 0x5b3, x86_l_5b3);
x86_l_2b1:
	/* 0x2b1: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_2b3:
	/* 0x2b3: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b6:
	/* 0x2b6: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_2bb:
	/* 0x2bb: ja     30f <filter_char_buf_equal+0x80> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2bb, 0x30f, x86_l_30f);
x86_l_2bd:
	/* 0x2bd: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c1:
	/* 0x2c1: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2c7:
	/* 0x2c7: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2ca:
	/* 0x2ca: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2cd:
	/* 0x2cd: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_2d0:
	/* 0x2d0: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2d2:
	/* 0x2d2: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_2d5:
	/* 0x2d5: je     2e0 <filter_char_buf_equal+0x51> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d5, 0x2e0, x86_l_2e0);
x86_l_2d7:
	/* 0x2d7: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2d9:
	/* 0x2d9: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_2dc:
	/* 0x2dc: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2de:
	/* 0x2de: je     2f9 <filter_char_buf_equal+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2de, 0x2f9, x86_l_2f9);
x86_l_2e0:
	/* 0x2e0: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e3:
	/* 0x2e3: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2e5:
	/* 0x2e5: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e7:
	/* 0x2e7: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2e9:
	/* 0x2e9: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2ec:
	/* 0x2ec: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f0:
	/* 0x2f0: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2f4:
	/* 0x2f4: ja     34d <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x2f4, 0x34d, x86_l_34d);
x86_l_2f6:
	/* 0x2f6: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_2f9:
	/* 0x2f9: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2fc:
	/* 0x2fc: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_303:
	/* 0x303: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_307:
	/* 0x307: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_30a:
	/* 0x30a: jmp    398 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x30a, 0x398, x86_l_398);
x86_l_30f:
	/* 0x30f: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_315:
	/* 0x315: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_31a:
	/* 0x31a: jb     34d <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x31a, 0x34d, x86_l_34d);
x86_l_31c:
	/* 0x31c: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_322:
	/* 0x322: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_327:
	/* 0x327: jb     34d <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x327, 0x34d, x86_l_34d);
x86_l_329:
	/* 0x329: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_32f:
	/* 0x32f: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_334:
	/* 0x334: jb     34d <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x334, 0x34d, x86_l_34d);
x86_l_336:
	/* 0x336: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_339:
	/* 0x339: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_33e:
	/* 0x33e: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_342:
	/* 0x342: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_346:
	/* 0x346: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_34d:
	/* 0x34d: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_354:
	/* 0x354: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_35a:
	/* 0x35a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35d:
	/* 0x35d: jg     370 <filter_char_buf_equal+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x35d, 0x370, x86_l_370);
x86_l_35f:
	/* 0x35f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_361:
	/* 0x361: je     38a <filter_char_buf_equal+0xfb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x361, 0x38a, x86_l_38a);
x86_l_363:
	/* 0x363: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_366:
	/* 0x366: jne    382 <filter_char_buf_equal+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x366, 0x382, x86_l_382);
x86_l_368:
	/* 0x368: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_36e:
	/* 0x36e: jmp    398 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x36e, 0x398, x86_l_398);
x86_l_370:
	/* 0x370: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_373:
	/* 0x373: je     392 <filter_char_buf_equal+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x373, 0x392, x86_l_392);
x86_l_375:
	/* 0x375: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_378:
	/* 0x378: jne    382 <filter_char_buf_equal+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x378, 0x382, x86_l_382);
x86_l_37a:
	/* 0x37a: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_380:
	/* 0x380: jmp    398 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x380, 0x398, x86_l_398);
x86_l_382:
	/* 0x382: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_388:
	/* 0x388: jmp    398 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x388, 0x398, x86_l_398);
x86_l_38a:
	/* 0x38a: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_390:
	/* 0x390: jmp    398 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x390, 0x398, x86_l_398);
x86_l_392:
	/* 0x392: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_398:
	/* 0x398: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_39b:
	/* 0x39b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_39e:
	/* 0x39e: mov    ebx,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_3a2:
	/* 0x3a2: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_3a5:
	/* 0x3a5: je     5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3a5, 0x5b3, x86_l_5b3);
x86_l_3ab:
	/* 0x3ab: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b0:
	/* 0x3b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b5:
	/* 0x3b5: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3bc:
	/* 0x3bc: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c1:
	/* 0x3c1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3c4:
	/* 0x3c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6:
	/* 0x3c6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3c9:
	/* 0x3c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ce:
	/* 0x3ce: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3d5:
	/* 0x3d5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3d8:
	/* 0x3d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da:
	/* 0x3da: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3dd:
	/* 0x3dd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3df:
	/* 0x3df: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e3:
	/* 0x3e3: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3e6:
	/* 0x3e6: je     5b5 <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3e6, 0x5b5, x86_l_5b5);
x86_l_3ec:
	/* 0x3ec: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3ef:
	/* 0x3ef: je     5b5 <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3ef, 0x5b5, x86_l_5b5);
x86_l_3f5:
	/* 0x3f5: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3f9:
	/* 0x3f9: jg     434 <filter_char_buf_equal+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x3f9, 0x434, x86_l_434);
x86_l_3fb:
	/* 0x3fb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff:
	/* 0x3ff: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_402:
	/* 0x402: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_406:
	/* 0x406: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40b:
	/* 0x40b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_40d:
	/* 0x40d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_412:
	/* 0x412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414:
	/* 0x414: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_417:
	/* 0x417: jbe    474 <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x417, 0x474, x86_l_474);
x86_l_419:
	/* 0x419: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_41b:
	/* 0x41b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41f:
	/* 0x41f: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_423:
	/* 0x423: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_426:
	/* 0x426: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_42d:
	/* 0x42d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_432:
	/* 0x432: jmp    46c <filter_char_buf_equal+0x1dd> */
	X86_SIM_X86_SUB_JMP(0x432, 0x46c, x86_l_46c);
x86_l_434:
	/* 0x434: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_438:
	/* 0x438: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43b:
	/* 0x43b: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_43f:
	/* 0x43f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_444:
	/* 0x444: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_446:
	/* 0x446: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44b:
	/* 0x44b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d:
	/* 0x44d: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_450:
	/* 0x450: jbe    474 <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x450, 0x474, x86_l_474);
x86_l_452:
	/* 0x452: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_454:
	/* 0x454: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_458:
	/* 0x458: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45c:
	/* 0x45c: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_460:
	/* 0x460: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_467:
	/* 0x467: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46c:
	/* 0x46c: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_46f:
	/* 0x46f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_472:
	/* 0x472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_474:
	/* 0x474: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_478:
	/* 0x478: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_47c:
	/* 0x47c: jle    4b3 <filter_char_buf_equal+0x224> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x47c, 0x4b3, x86_l_4b3);
x86_l_47e:
	/* 0x47e: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_482:
	/* 0x482: jg     4e4 <filter_char_buf_equal+0x255> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x482, 0x4e4, x86_l_4e4);
x86_l_484:
	/* 0x484: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_488:
	/* 0x488: je     572 <filter_char_buf_equal+0x2e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x488, 0x572, x86_l_572);
x86_l_48e:
	/* 0x48e: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_492:
	/* 0x492: je     548 <filter_char_buf_equal+0x2b9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x492, 0x548, x86_l_548);
x86_l_498:
	/* 0x498: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_49c:
	/* 0x49c: jne    5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x49c, 0x5b3, x86_l_5b3);
x86_l_4a2:
	/* 0x4a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a7:
	/* 0x4a7: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_4ae:
	/* 0x4ae: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x4ae, 0x58c, x86_l_58c);
x86_l_4b3:
	/* 0x4b3: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_4b7:
	/* 0x4b7: jle    50f <filter_char_buf_equal+0x280> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x4b7, 0x50f, x86_l_50f);
x86_l_4b9:
	/* 0x4b9: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_4bd:
	/* 0x4bd: je     564 <filter_char_buf_equal+0x2d5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4bd, 0x564, x86_l_564);
x86_l_4c3:
	/* 0x4c3: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_4c7:
	/* 0x4c7: je     53a <filter_char_buf_equal+0x2ab> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4c7, 0x53a, x86_l_53a);
x86_l_4c9:
	/* 0x4c9: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_4cd:
	/* 0x4cd: jne    5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4cd, 0x5b3, x86_l_5b3);
x86_l_4d3:
	/* 0x4d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d8:
	/* 0x4d8: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_4df:
	/* 0x4df: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x4df, 0x58c, x86_l_58c);
x86_l_4e4:
	/* 0x4e4: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_4e8:
	/* 0x4e8: je     580 <filter_char_buf_equal+0x2f1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4e8, 0x580, x86_l_580);
x86_l_4ee:
	/* 0x4ee: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_4f2:
	/* 0x4f2: je     556 <filter_char_buf_equal+0x2c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4f2, 0x556, x86_l_556);
x86_l_4f4:
	/* 0x4f4: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_4f8:
	/* 0x4f8: jne    5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x4f8, 0x5b3, x86_l_5b3);
x86_l_4fe:
	/* 0x4fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_503:
	/* 0x503: mov    rdi,QWORD PTR [rip+0x1ec0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_50a:
	/* 0x50a: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x50a, 0x58c, x86_l_58c);
x86_l_50f:
	/* 0x50f: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_512:
	/* 0x512: je     52c <filter_char_buf_equal+0x29d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x512, 0x52c, x86_l_52c);
x86_l_514:
	/* 0x514: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_518:
	/* 0x518: jne    5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x518, 0x5b3, x86_l_5b3);
x86_l_51e:
	/* 0x51e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_523:
	/* 0x523: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_52a:
	/* 0x52a: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x52a, 0x58c, x86_l_58c);
x86_l_52c:
	/* 0x52c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_531:
	/* 0x531: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_538:
	/* 0x538: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x538, 0x58c, x86_l_58c);
x86_l_53a:
	/* 0x53a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_53f:
	/* 0x53f: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_546:
	/* 0x546: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x546, 0x58c, x86_l_58c);
x86_l_548:
	/* 0x548: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54d:
	/* 0x54d: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_554:
	/* 0x554: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x554, 0x58c, x86_l_58c);
x86_l_556:
	/* 0x556: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55b:
	/* 0x55b: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_562:
	/* 0x562: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x562, 0x58c, x86_l_58c);
x86_l_564:
	/* 0x564: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_569:
	/* 0x569: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_570:
	/* 0x570: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x570, 0x58c, x86_l_58c);
x86_l_572:
	/* 0x572: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_577:
	/* 0x577: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_57e:
	/* 0x57e: jmp    58c <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x57e, 0x58c, x86_l_58c);
x86_l_580:
	/* 0x580: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_585:
	/* 0x585: mov    rdi,QWORD PTR [rip+0x1ebd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_58c:
	/* 0x58c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_591:
	/* 0x591: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_593:
	/* 0x593: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_596:
	/* 0x596: je     5b3 <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x596, 0x5b3, x86_l_5b3);
x86_l_598:
	/* 0x598: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_59d:
	/* 0x59d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5a0:
	/* 0x5a0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a4:
	/* 0x5a4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5a6:
	/* 0x5a6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5a9:
	/* 0x5a9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ab:
	/* 0x5ab: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_5ae:
	/* 0x5ae: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_5b1:
	/* 0x5b1: jmp    5b5 <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JMP(0x5b1, 0x5b5, x86_l_5b5);
x86_l_5b3:
	/* 0x5b3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b5:
	/* 0x5b5: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_5b9:
	/* 0x5b9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_5ba:
	/* 0x5ba: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_5be:
	/* 0x5be: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_5c0:
	/* 0x5c0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_5c2:
	/* 0x5c2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_5c3:
	/* 0x5c3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_5c4 */
x86_l_5c4:
	/* 0x5c4: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_5c5:
	/* 0x5c5: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_5c7:
	/* 0x5c7: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5c9:
	/* 0x5c9: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_5cb:
	/* 0x5cb: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_5cd:
	/* 0x5cd: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_5ce:
	/* 0x5ce: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_5cf:
	/* 0x5cf: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_5d7:
	/* 0x5d7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5d9:
	/* 0x5d9: je     6a1 <filter_char_substring+0xdd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5d9, 0x6a1, x86_l_6a1);
x86_l_5df:
	/* 0x5df: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_5e1:
	/* 0x5e1: je     73e <filter_char_substring+0x17a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5e1, 0x73e, x86_l_73e);
x86_l_5e7:
	/* 0x5e7: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5ec:
	/* 0x5ec: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ee:
	/* 0x5ee: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f1:
	/* 0x5f1: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_5f6:
	/* 0x5f6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ff:
	/* 0x5ff: mov    rdi,QWORD PTR [rip+0x24a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_606:
	/* 0x606: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_609:
	/* 0x609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60b:
	/* 0x60b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: je     7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x60e, 0x7c2, x86_l_7c2);
x86_l_614:
	/* 0x614: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_617:
	/* 0x617: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_619:
	/* 0x619: jmp    626 <filter_char_substring+0x62> */
	X86_SIM_X86_SUB_JMP(0x619, 0x626, x86_l_626);
x86_l_61b:
	/* 0x61b: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_61e:
	/* 0x61e: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_621:
	/* 0x621: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_624:
	/* 0x624: je     67c <filter_char_substring+0xb8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x624, 0x67c, x86_l_67c);
x86_l_626:
	/* 0x626: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_628:
	/* 0x628: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_62c:
	/* 0x62c: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_62f:
	/* 0x62f: jae    61b <filter_char_substring+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x62f, 0x61b, x86_l_61b);
x86_l_631:
	/* 0x631: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_635:
	/* 0x635: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_637:
	/* 0x637: je     674 <filter_char_substring+0xb0> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x637, 0x674, x86_l_674);
x86_l_639:
	/* 0x639: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_63e:
	/* 0x63e: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_642:
	/* 0x642: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_645:
	/* 0x645: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_649:
	/* 0x649: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_64d:
	/* 0x64d: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_651:
	/* 0x651: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_655:
	/* 0x655: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_658:
	/* 0x658: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_65c:
	/* 0x65c: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_660:
	/* 0x660: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_664:
	/* 0x664: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_668:
	/* 0x668: ja     61b <filter_char_substring+0x57> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x668, 0x61b, x86_l_61b);
x86_l_66a:
	/* 0x66a: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_66d:
	/* 0x66d: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_670:
	/* 0x670: je     628 <filter_char_substring+0x64> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x670, 0x628, x86_l_628);
x86_l_672:
	/* 0x672: jmp    61b <filter_char_substring+0x57> */
	X86_SIM_X86_SUB_JMP(0x672, 0x61b, x86_l_61b);
x86_l_674:
	/* 0x674: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_676:
	/* 0x676: jns    7d3 <filter_char_substring+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x676, 0x7d3, x86_l_7d3);
x86_l_67c:
	/* 0x67c: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_681:
	/* 0x681: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_685:
	/* 0x685: jae    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x685, 0x7c2, x86_l_7c2);
x86_l_68b:
	/* 0x68b: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_68f:
	/* 0x68f: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_692:
	/* 0x692: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_696:
	/* 0x696: jne    5f1 <filter_char_substring+0x2d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x696, 0x5f1, x86_l_5f1);
x86_l_69c:
	/* 0x69c: jmp    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JMP(0x69c, 0x7c2, x86_l_7c2);
x86_l_6a1:
	/* 0x6a1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_6a3:
	/* 0x6a3: je     781 <filter_char_substring+0x1bd> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6a3, 0x781, x86_l_781);
x86_l_6a9:
	/* 0x6a9: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6ae:
	/* 0x6ae: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b0:
	/* 0x6b0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b3:
	/* 0x6b3: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_6b8:
	/* 0x6b8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6bc:
	/* 0x6bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c1:
	/* 0x6c1: mov    rdi,QWORD PTR [rip+0x24b1] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_6c8:
	/* 0x6c8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cd:
	/* 0x6cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6d0:
	/* 0x6d0: je     7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6d0, 0x7c2, x86_l_7c2);
x86_l_6d6:
	/* 0x6d6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6d9:
	/* 0x6d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6db:
	/* 0x6db: jmp    6e8 <filter_char_substring+0x124> */
	X86_SIM_X86_SUB_JMP(0x6db, 0x6e8, x86_l_6e8);
x86_l_6dd:
	/* 0x6dd: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6e0:
	/* 0x6e0: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6e3:
	/* 0x6e3: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_6e6:
	/* 0x6e6: je     719 <filter_char_substring+0x155> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6e6, 0x719, x86_l_719);
x86_l_6e8:
	/* 0x6e8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ea:
	/* 0x6ea: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_6ee:
	/* 0x6ee: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6f1:
	/* 0x6f1: jae    6dd <filter_char_substring+0x119> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x6f1, 0x6dd, x86_l_6dd);
x86_l_6f3:
	/* 0x6f3: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_6f7:
	/* 0x6f7: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_6fa:
	/* 0x6fa: je     711 <filter_char_substring+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6fa, 0x711, x86_l_711);
x86_l_6fc:
	/* 0x6fc: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_700:
	/* 0x700: ja     6dd <filter_char_substring+0x119> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x700, 0x6dd, x86_l_6dd);
x86_l_702:
	/* 0x702: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_706:
	/* 0x706: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_70a:
	/* 0x70a: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_70d:
	/* 0x70d: je     6ea <filter_char_substring+0x126> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x70d, 0x6ea, x86_l_6ea);
x86_l_70f:
	/* 0x70f: jmp    6dd <filter_char_substring+0x119> */
	X86_SIM_X86_SUB_JMP(0x70f, 0x6dd, x86_l_6dd);
x86_l_711:
	/* 0x711: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_713:
	/* 0x713: jns    7d3 <filter_char_substring+0x20f> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x713, 0x7d3, x86_l_7d3);
x86_l_719:
	/* 0x719: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_71e:
	/* 0x71e: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_722:
	/* 0x722: jae    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x722, 0x7c2, x86_l_7c2);
x86_l_728:
	/* 0x728: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_72c:
	/* 0x72c: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_72f:
	/* 0x72f: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_733:
	/* 0x733: jne    6b3 <filter_char_substring+0xef> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x733, 0x6b3, x86_l_6b3);
x86_l_739:
	/* 0x739: jmp    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JMP(0x739, 0x7c2, x86_l_7c2);
x86_l_73e:
	/* 0x73e: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_743:
	/* 0x743: mov    r15,QWORD PTR [rip+0x24c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_74a:
	/* 0x74a: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_74f:
	/* 0x74f: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_753:
	/* 0x753: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_757:
	/* 0x757: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_75c:
	/* 0x75c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_75f:
	/* 0x75f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_762:
	/* 0x762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_764:
	/* 0x764: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_767:
	/* 0x767: je     7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x767, 0x7c2, x86_l_7c2);
x86_l_769:
	/* 0x769: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_76d:
	/* 0x76d: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_770:
	/* 0x770: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_774:
	/* 0x774: jae    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x774, 0x7c2, x86_l_7c2);
x86_l_776:
	/* 0x776: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_77d:
	/* 0x77d: jne    74f <filter_char_substring+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x77d, 0x74f, x86_l_74f);
x86_l_77f:
	/* 0x77f: jmp    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JMP(0x77f, 0x7c2, x86_l_7c2);
x86_l_781:
	/* 0x781: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_786:
	/* 0x786: mov    r15,QWORD PTR [rip+0x24c5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_78d:
	/* 0x78d: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_792:
	/* 0x792: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_796:
	/* 0x796: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79a:
	/* 0x79a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_79f:
	/* 0x79f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7a2:
	/* 0x7a2: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: je     7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x7aa, 0x7c2, x86_l_7c2);
x86_l_7ac:
	/* 0x7ac: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7b0:
	/* 0x7b0: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_7b3:
	/* 0x7b3: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_7b7:
	/* 0x7b7: jae    7c2 <filter_char_substring+0x1fe> */
	X86_SIM_X86_SUB_JCC(X86_CC_AE, 0x7b7, 0x7c2, x86_l_7c2);
x86_l_7b9:
	/* 0x7b9: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_7c0:
	/* 0x7c0: jne    792 <filter_char_substring+0x1ce> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x7c0, 0x792, x86_l_792);
x86_l_7c2:
	/* 0x7c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c4:
	/* 0x7c4: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7c8:
	/* 0x7c8: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_7c9:
	/* 0x7c9: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_7cb:
	/* 0x7cb: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_7cd:
	/* 0x7cd: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_7cf:
	/* 0x7cf: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_7d1:
	/* 0x7d1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_7d2:
	/* 0x7d2: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_7d3:
	/* 0x7d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d8:
	/* 0x7d8: jmp    7c4 <filter_char_substring+0x200> */
	X86_SIM_X86_SUB_JMP(0x7d8, 0x7c4, x86_l_7c4);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x47ULL: goto x86_l_47;
	case 0x65ULL: goto x86_l_65;
	case 0x6fULL: goto x86_l_6f;
	case 0x7bULL: goto x86_l_7b;
	case 0xd2ULL: goto x86_l_d2;
	case 0xfbULL: goto x86_l_fb;
	case 0x1d4ULL: goto x86_l_1d4;
	case 0x219ULL: goto x86_l_219;
	case 0x23aULL: goto x86_l_23a;
	case 0x26aULL: goto x86_l_26a;
	case 0x277ULL: goto x86_l_277;
	case 0x3c6ULL: goto x86_l_3c6;
	case 0x3daULL: goto x86_l_3da;
	case 0x414ULL: goto x86_l_414;
	case 0x44dULL: goto x86_l_44d;
	case 0x474ULL: goto x86_l_474;
	case 0x593ULL: goto x86_l_593;
	case 0x5a6ULL: goto x86_l_5a6;
	case 0x60bULL: goto x86_l_60b;
	case 0x6cdULL: goto x86_l_6cd;
	case 0x764ULL: goto x86_l_764;
	case 0x7a7ULL: goto x86_l_7a7;
	}

}

X86_SIM_LICENSE();
