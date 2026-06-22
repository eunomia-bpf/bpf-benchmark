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
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retuprobe_v61_filter_file_buf_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1:
	/* 0x1: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4:
	/* 0x4: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6:
	/* 0x6: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9:
	/* 0x9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b:
	/* 0xb: jne    1f <filter_file_buf+0x1f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb, 0x1f, x86_l_1f);
x86_l_d:
	/* 0xd: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_f:
	/* 0xf: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_12:
	/* 0x12: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_15:
	/* 0x15: je     1f <filter_file_buf+0x1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15, 0x1f, x86_l_1f);
x86_l_17:
	/* 0x17: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19:
	/* 0x19: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1a:
	/* 0x1a: jmp    6e4 <filter_char_buf_prefix+0xa0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1f:
	/* 0x1f: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_22:
	/* 0x22: ja     5e <filter_file_buf+0x5e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x22, 0x5e, x86_l_5e);
x86_l_24:
	/* 0x24: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_26:
	/* 0x26: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_2b:
	/* 0x2b: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: jb     92 <filter_file_buf+0x92> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2f, 0x92, x86_l_92);
x86_l_31:
	/* 0x31: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_36:
	/* 0x36: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: jb     7c <filter_file_buf+0x7c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3a, 0x7c, x86_l_7c);
x86_l_3c:
	/* 0x3c: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_46:
	/* 0x46: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: jae    5e <filter_file_buf+0x5e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x4a, 0x5e, x86_l_5e);
x86_l_4c:
	/* 0x4c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: call   cb <filter_file_type> */
	X86_SIM_X86_CALL(x86_l_cb, 0x54ULL);
x86_l_54:
	/* 0x54: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_57:
	/* 0x57: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_5a:
	/* 0x5a: jbe    af <filter_file_buf+0xaf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x5a, 0xaf, x86_l_af);
x86_l_5c:
	/* 0x5c: jmp    c5 <filter_file_buf+0xc5> */
	X86_SIM_X86_JMP(0x5c, 0xc5, x86_l_c5);
x86_l_5e:
	/* 0x5e: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_61:
	/* 0x61: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64:
	/* 0x64: jae    a8 <filter_file_buf+0xa8> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x64, 0xa8, x86_l_a8);
x86_l_66:
	/* 0x66: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6a:
	/* 0x6a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: call   16f <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_16f, 0x72ULL);
x86_l_72:
	/* 0x72: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_75:
	/* 0x75: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_78:
	/* 0x78: jbe    af <filter_file_buf+0xaf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x78, 0xaf, x86_l_af);
x86_l_7a:
	/* 0x7a: jmp    c5 <filter_file_buf+0xc5> */
	X86_SIM_X86_JMP(0x7a, 0xc5, x86_l_c5);
x86_l_7c:
	/* 0x7c: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_80:
	/* 0x80: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83:
	/* 0x83: call   4fc <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_4fc, 0x88ULL);
x86_l_88:
	/* 0x88: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8b:
	/* 0x8b: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_8e:
	/* 0x8e: jbe    af <filter_file_buf+0xaf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x8e, 0xaf, x86_l_af);
x86_l_90:
	/* 0x90: jmp    c5 <filter_file_buf+0xc5> */
	X86_SIM_X86_JMP(0x90, 0xc5, x86_l_c5);
x86_l_92:
	/* 0x92: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_96:
	/* 0x96: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_99:
	/* 0x99: call   644 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_644, 0x9eULL);
x86_l_9e:
	/* 0x9e: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a1:
	/* 0xa1: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_a4:
	/* 0xa4: jbe    af <filter_file_buf+0xaf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa4, 0xaf, x86_l_af);
x86_l_a6:
	/* 0xa6: jmp    c5 <filter_file_buf+0xc5> */
	X86_SIM_X86_JMP(0xa6, 0xc5, x86_l_c5);
x86_l_a8:
	/* 0xa8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa:
	/* 0xaa: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_ad:
	/* 0xad: ja     c5 <filter_file_buf+0xc5> */
	X86_SIM_X86_JCC(X86_CC_A, 0xad, 0xc5, x86_l_c5);
x86_l_af:
	/* 0xaf: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_b1:
	/* 0xb1: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_bb:
	/* 0xbb: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: jae    c5 <filter_file_buf+0xc5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xbf, 0xc5, x86_l_c5);
x86_l_c1:
	/* 0xc1: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_c5:
	/* 0xc5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_c6:
	/* 0xc6: jmp    6e4 <filter_char_buf_prefix+0xa0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_6e4:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_cb */
x86_l_cb:
	/* 0xcb: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_cc:
	/* 0xcc: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_d0:
	/* 0xd0: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_d7:
	/* 0xd7: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9:
	/* 0xd9: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_df:
	/* 0xdf: ja     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xdf, 0x167, x86_l_167);
x86_l_e5:
	/* 0xe5: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_e8:
	/* 0xe8: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ec:
	/* 0xec: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f0:
	/* 0xf0: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_f5:
	/* 0xf5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_fa:
	/* 0xfa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff:
	/* 0xff: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_101:
	/* 0x101: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_105:
	/* 0x105: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_109:
	/* 0x109: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10e:
	/* 0x10e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110:
	/* 0x110: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_113:
	/* 0x113: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_115:
	/* 0x115: je     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x115, 0x167, x86_l_167);
x86_l_117:
	/* 0x117: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_11c:
	/* 0x11c: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_122:
	/* 0x122: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_127:
	/* 0x127: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_129:
	/* 0x129: je     169 <filter_file_type+0x9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x129, 0x169, x86_l_169);
x86_l_12b:
	/* 0x12b: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e:
	/* 0x12e: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_131:
	/* 0x131: jbe    167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x131, 0x167, x86_l_167);
x86_l_133:
	/* 0x133: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_136:
	/* 0x136: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_138:
	/* 0x138: je     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x138, 0x167, x86_l_167);
x86_l_13a:
	/* 0x13a: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_13c:
	/* 0x13c: je     169 <filter_file_type+0x9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x13c, 0x169, x86_l_169);
x86_l_13e:
	/* 0x13e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_141:
	/* 0x141: jb     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x141, 0x167, x86_l_167);
x86_l_143:
	/* 0x143: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_146:
	/* 0x146: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_148:
	/* 0x148: je     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x148, 0x167, x86_l_167);
x86_l_14a:
	/* 0x14a: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_14c:
	/* 0x14c: je     169 <filter_file_type+0x9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x14c, 0x169, x86_l_169);
x86_l_14e:
	/* 0x14e: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_151:
	/* 0x151: jb     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x151, 0x167, x86_l_167);
x86_l_153:
	/* 0x153: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_156:
	/* 0x156: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_158:
	/* 0x158: je     167 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x158, 0x167, x86_l_167);
x86_l_15a:
	/* 0x15a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c:
	/* 0x15c: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_15e:
	/* 0x15e: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_161:
	/* 0x161: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_165:
	/* 0x165: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_166:
	/* 0x166: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_167:
	/* 0x167: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_169:
	/* 0x169: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16d:
	/* 0x16d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_16e:
	/* 0x16e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_16f */
x86_l_16f:
	/* 0x16f: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_170:
	/* 0x170: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_172:
	/* 0x172: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_174:
	/* 0x174: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_176:
	/* 0x176: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_178:
	/* 0x178: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_179:
	/* 0x179: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_17d:
	/* 0x17d: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_185:
	/* 0x185: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_18b:
	/* 0x18b: ja     4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x18b, 0x4eb, x86_l_4eb);
x86_l_191:
	/* 0x191: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_194:
	/* 0x194: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_199:
	/* 0x199: ja     1ec <filter_char_buf_equal+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x199, 0x1ec, x86_l_1ec);
x86_l_19b:
	/* 0x19b: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_19e:
	/* 0x19e: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1a4:
	/* 0x1a4: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1a7:
	/* 0x1a7: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1aa:
	/* 0x1aa: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1ad:
	/* 0x1ad: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1af:
	/* 0x1af: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1b2:
	/* 0x1b2: je     1bd <filter_char_buf_equal+0x4e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b2, 0x1bd, x86_l_1bd);
x86_l_1b4:
	/* 0x1b4: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1b6:
	/* 0x1b6: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_1b9:
	/* 0x1b9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1bb:
	/* 0x1bb: je     1d6 <filter_char_buf_equal+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1bb, 0x1d6, x86_l_1d6);
x86_l_1bd:
	/* 0x1bd: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1c0:
	/* 0x1c0: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1c2:
	/* 0x1c2: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c4:
	/* 0x1c4: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1c6:
	/* 0x1c6: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1c9:
	/* 0x1c9: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1cd:
	/* 0x1cd: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1d1:
	/* 0x1d1: ja     22a <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1d1, 0x22a, x86_l_22a);
x86_l_1d3:
	/* 0x1d3: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1d6:
	/* 0x1d6: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d9:
	/* 0x1d9: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1e0:
	/* 0x1e0: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1e4:
	/* 0x1e4: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1e7:
	/* 0x1e7: jmp    275 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1e7, 0x275, x86_l_275);
x86_l_1ec:
	/* 0x1ec: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_1f2:
	/* 0x1f2: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1f7:
	/* 0x1f7: jb     22a <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f7, 0x22a, x86_l_22a);
x86_l_1f9:
	/* 0x1f9: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_1ff:
	/* 0x1ff: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_204:
	/* 0x204: jb     22a <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x204, 0x22a, x86_l_22a);
x86_l_206:
	/* 0x206: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_20c:
	/* 0x20c: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_211:
	/* 0x211: jb     22a <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x211, 0x22a, x86_l_22a);
x86_l_213:
	/* 0x213: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_216:
	/* 0x216: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_21b:
	/* 0x21b: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_21f:
	/* 0x21f: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_223:
	/* 0x223: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_22a:
	/* 0x22a: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_231:
	/* 0x231: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_237:
	/* 0x237: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23a:
	/* 0x23a: jg     24d <filter_char_buf_equal+0xde> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x23a, 0x24d, x86_l_24d);
x86_l_23c:
	/* 0x23c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23e:
	/* 0x23e: je     267 <filter_char_buf_equal+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x23e, 0x267, x86_l_267);
x86_l_240:
	/* 0x240: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_243:
	/* 0x243: jne    25f <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x243, 0x25f, x86_l_25f);
x86_l_245:
	/* 0x245: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_24b:
	/* 0x24b: jmp    275 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x24b, 0x275, x86_l_275);
x86_l_24d:
	/* 0x24d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_250:
	/* 0x250: je     26f <filter_char_buf_equal+0x100> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x250, 0x26f, x86_l_26f);
x86_l_252:
	/* 0x252: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_255:
	/* 0x255: jne    25f <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x255, 0x25f, x86_l_25f);
x86_l_257:
	/* 0x257: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_25d:
	/* 0x25d: jmp    275 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x25d, 0x275, x86_l_275);
x86_l_25f:
	/* 0x25f: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_265:
	/* 0x265: jmp    275 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x265, 0x275, x86_l_275);
x86_l_267:
	/* 0x267: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_26d:
	/* 0x26d: jmp    275 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x26d, 0x275, x86_l_275);
x86_l_26f:
	/* 0x26f: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_275:
	/* 0x275: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_278:
	/* 0x278: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_27b:
	/* 0x27b: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_280:
	/* 0x280: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_284:
	/* 0x284: je     4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x284, 0x4eb, x86_l_4eb);
x86_l_28a:
	/* 0x28a: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f:
	/* 0x28f: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_291:
	/* 0x291: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_298:
	/* 0x298: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29d:
	/* 0x29d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a2:
	/* 0x2a2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2a5:
	/* 0x2a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7:
	/* 0x2a7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2aa:
	/* 0x2aa: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2b1:
	/* 0x2b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b6:
	/* 0x2b6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb:
	/* 0x2bb: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c0:
	/* 0x2c0: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c5:
	/* 0x2c5: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2c8:
	/* 0x2c8: je     4ed <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c8, 0x4ed, x86_l_4ed);
x86_l_2ce:
	/* 0x2ce: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2d1:
	/* 0x2d1: je     4ed <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d1, 0x4ed, x86_l_4ed);
x86_l_2d7:
	/* 0x2d7: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dc:
	/* 0x2dc: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2e0:
	/* 0x2e0: jg     323 <filter_char_buf_equal+0x1b4> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2e0, 0x323, x86_l_323);
x86_l_2e2:
	/* 0x2e2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e7:
	/* 0x2e7: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea:
	/* 0x2ea: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ee:
	/* 0x2ee: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_2f1:
	/* 0x2f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f6:
	/* 0x2f6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb:
	/* 0x2fb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2fd:
	/* 0x2fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff:
	/* 0x2ff: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_302:
	/* 0x302: jbe    368 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x302, 0x368, x86_l_368);
x86_l_304:
	/* 0x304: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_309:
	/* 0x309: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_30d:
	/* 0x30d: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_310:
	/* 0x310: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_317:
	/* 0x317: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31c:
	/* 0x31c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_321:
	/* 0x321: jmp    363 <filter_char_buf_equal+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x321, 0x363, x86_l_363);
x86_l_323:
	/* 0x323: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_328:
	/* 0x328: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b:
	/* 0x32b: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_32f:
	/* 0x32f: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_332:
	/* 0x332: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_337:
	/* 0x337: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33c:
	/* 0x33c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_33e:
	/* 0x33e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340:
	/* 0x340: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_343:
	/* 0x343: jbe    368 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x343, 0x368, x86_l_368);
x86_l_345:
	/* 0x345: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34a:
	/* 0x34a: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_34e:
	/* 0x34e: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_352:
	/* 0x352: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_359:
	/* 0x359: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35e:
	/* 0x35e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_363:
	/* 0x363: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_366:
	/* 0x366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368:
	/* 0x368: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36d:
	/* 0x36d: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_371:
	/* 0x371: jle    3ad <filter_char_buf_equal+0x23e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x371, 0x3ad, x86_l_3ad);
x86_l_373:
	/* 0x373: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_377:
	/* 0x377: jg     3e7 <filter_char_buf_equal+0x278> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x377, 0x3e7, x86_l_3e7);
x86_l_379:
	/* 0x379: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_37d:
	/* 0x37d: je     49f <filter_char_buf_equal+0x330> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x37d, 0x49f, x86_l_49f);
x86_l_383:
	/* 0x383: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_387:
	/* 0x387: je     466 <filter_char_buf_equal+0x2f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x387, 0x466, x86_l_466);
x86_l_38d:
	/* 0x38d: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_391:
	/* 0x391: jne    4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x391, 0x4eb, x86_l_4eb);
x86_l_397:
	/* 0x397: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_39e:
	/* 0x39e: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a3:
	/* 0x3a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a8:
	/* 0x3a8: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3a8, 0x4c3, x86_l_4c3);
x86_l_3ad:
	/* 0x3ad: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3b1:
	/* 0x3b1: jle    41b <filter_char_buf_equal+0x2ac> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x3b1, 0x41b, x86_l_41b);
x86_l_3b3:
	/* 0x3b3: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3b7:
	/* 0x3b7: je     48c <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3b7, 0x48c, x86_l_48c);
x86_l_3bd:
	/* 0x3bd: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3c1:
	/* 0x3c1: je     453 <filter_char_buf_equal+0x2e4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3c1, 0x453, x86_l_453);
x86_l_3c7:
	/* 0x3c7: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3cb:
	/* 0x3cb: jne    4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3cb, 0x4eb, x86_l_4eb);
x86_l_3d1:
	/* 0x3d1: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3d8:
	/* 0x3d8: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3dd:
	/* 0x3dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e2:
	/* 0x3e2: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3e2, 0x4c3, x86_l_4c3);
x86_l_3e7:
	/* 0x3e7: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_3eb:
	/* 0x3eb: je     4b2 <filter_char_buf_equal+0x343> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3eb, 0x4b2, x86_l_4b2);
x86_l_3f1:
	/* 0x3f1: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_3f5:
	/* 0x3f5: je     479 <filter_char_buf_equal+0x30a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3f5, 0x479, x86_l_479);
x86_l_3fb:
	/* 0x3fb: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_3ff:
	/* 0x3ff: jne    4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3ff, 0x4eb, x86_l_4eb);
x86_l_405:
	/* 0x405: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_40c:
	/* 0x40c: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_411:
	/* 0x411: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_416:
	/* 0x416: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x416, 0x4c3, x86_l_4c3);
x86_l_41b:
	/* 0x41b: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_41e:
	/* 0x41e: je     440 <filter_char_buf_equal+0x2d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x41e, 0x440, x86_l_440);
x86_l_420:
	/* 0x420: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_424:
	/* 0x424: jne    4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x424, 0x4eb, x86_l_4eb);
x86_l_42a:
	/* 0x42a: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_431:
	/* 0x431: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_436:
	/* 0x436: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_43b:
	/* 0x43b: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x43b, 0x4c3, x86_l_4c3);
x86_l_440:
	/* 0x440: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_447:
	/* 0x447: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44c:
	/* 0x44c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_451:
	/* 0x451: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x451, 0x4c3, x86_l_4c3);
x86_l_453:
	/* 0x453: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_45a:
	/* 0x45a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45f:
	/* 0x45f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_464:
	/* 0x464: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x464, 0x4c3, x86_l_4c3);
x86_l_466:
	/* 0x466: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_46d:
	/* 0x46d: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_472:
	/* 0x472: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_477:
	/* 0x477: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x477, 0x4c3, x86_l_4c3);
x86_l_479:
	/* 0x479: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_480:
	/* 0x480: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_485:
	/* 0x485: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_48a:
	/* 0x48a: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x48a, 0x4c3, x86_l_4c3);
x86_l_48c:
	/* 0x48c: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_493:
	/* 0x493: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_498:
	/* 0x498: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49d:
	/* 0x49d: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x49d, 0x4c3, x86_l_4c3);
x86_l_49f:
	/* 0x49f: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_4a6:
	/* 0x4a6: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ab:
	/* 0x4ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b0:
	/* 0x4b0: jmp    4c3 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x4b0, 0x4c3, x86_l_4c3);
x86_l_4b2:
	/* 0x4b2: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_4b9:
	/* 0x4b9: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4be:
	/* 0x4be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c3:
	/* 0x4c3: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: je     4eb <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4cd, 0x4eb, x86_l_4eb);
x86_l_4cf:
	/* 0x4cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4d2:
	/* 0x4d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d7:
	/* 0x4d7: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dc:
	/* 0x4dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4de:
	/* 0x4de: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4e1:
	/* 0x4e1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e3:
	/* 0x4e3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4e6:
	/* 0x4e6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_4e9:
	/* 0x4e9: jmp    4ed <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JMP(0x4e9, 0x4ed, x86_l_4ed);
x86_l_4eb:
	/* 0x4eb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ed:
	/* 0x4ed: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_4f1:
	/* 0x4f1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4f2:
	/* 0x4f2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4f4:
	/* 0x4f4: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_4f6:
	/* 0x4f6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4fa:
	/* 0x4fa: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4fb:
	/* 0x4fb: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_4fc */
x86_l_4fc:
	/* 0x4fc: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_4fe:
	/* 0x4fe: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_500:
	/* 0x500: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_501:
	/* 0x501: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_505:
	/* 0x505: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_507:
	/* 0x507: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_50a:
	/* 0x50a: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_50e:
	/* 0x50e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_516:
	/* 0x516: mov    rdi,QWORD PTR [rip+0x1e90] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_51d:
	/* 0x51d: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_522:
	/* 0x522: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_527:
	/* 0x527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529:
	/* 0x529: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_52c:
	/* 0x52c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52e:
	/* 0x52e: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_530:
	/* 0x530: je     63a <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x530, 0x63a, x86_l_63a);
x86_l_536:
	/* 0x536: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_539:
	/* 0x539: je     63a <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x539, 0x63a, x86_l_63a);
x86_l_53f:
	/* 0x53f: mov    rdi,QWORD PTR [rip+0x1e90] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_546:
	/* 0x546: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b:
	/* 0x54b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_550:
	/* 0x550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552:
	/* 0x552: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_555:
	/* 0x555: je     638 <filter_char_buf_postfix+0x13c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x555, 0x638, x86_l_638);
x86_l_55b:
	/* 0x55b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_561:
	/* 0x561: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_566:
	/* 0x566: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_569:
	/* 0x569: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_56c:
	/* 0x56c: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56e:
	/* 0x56e: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_570:
	/* 0x570: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_573:
	/* 0x573: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_576:
	/* 0x576: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_57a:
	/* 0x57a: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_57d:
	/* 0x57d: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_581:
	/* 0x581: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_583:
	/* 0x583: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_58a:
	/* 0x58a: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_58e:
	/* 0x58e: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_592:
	/* 0x592: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_599:
	/* 0x599: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_59e:
	/* 0x59e: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_5a2:
	/* 0x5a2: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5a6:
	/* 0x5a6: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_5aa:
	/* 0x5aa: je     621 <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5aa, 0x621, x86_l_621);
x86_l_5ac:
	/* 0x5ac: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5b0:
	/* 0x5b0: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5b4:
	/* 0x5b4: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5bb:
	/* 0x5bb: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_5c0:
	/* 0x5c0: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_5c4:
	/* 0x5c4: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_5c8:
	/* 0x5c8: je     621 <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5c8, 0x621, x86_l_621);
x86_l_5ca:
	/* 0x5ca: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5ce:
	/* 0x5ce: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5d2:
	/* 0x5d2: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d9:
	/* 0x5d9: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_5de:
	/* 0x5de: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5e2:
	/* 0x5e2: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_5e5:
	/* 0x5e5: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e8:
	/* 0x5e8: je     621 <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5e8, 0x621, x86_l_621);
x86_l_5ea:
	/* 0x5ea: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_5ee:
	/* 0x5ee: je     621 <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5ee, 0x621, x86_l_621);
x86_l_5f0:
	/* 0x5f0: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5f4:
	/* 0x5f4: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5f8:
	/* 0x5f8: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ff:
	/* 0x5ff: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_604:
	/* 0x604: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_607:
	/* 0x607: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_60b:
	/* 0x60b: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_60f:
	/* 0x60f: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_613:
	/* 0x613: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_617:
	/* 0x617: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_61b:
	/* 0x61b: jne    58a <filter_char_buf_postfix+0x8e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x61b, 0x58a, x86_l_58a);
x86_l_621:
	/* 0x621: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_626:
	/* 0x626: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_62e:
	/* 0x62e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_630:
	/* 0x630: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_633:
	/* 0x633: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_636:
	/* 0x636: jmp    63a <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JMP(0x636, 0x63a, x86_l_63a);
x86_l_638:
	/* 0x638: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63a:
	/* 0x63a: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_63e:
	/* 0x63e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_63f:
	/* 0x63f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_641:
	/* 0x641: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_643:
	/* 0x643: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_644 */
x86_l_644:
	/* 0x644: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_645:
	/* 0x645: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_647:
	/* 0x647: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_649:
	/* 0x649: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_64a:
	/* 0x64a: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_64b:
	/* 0x64b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_64d:
	/* 0x64d: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_650:
	/* 0x650: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_654:
	/* 0x654: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65b:
	/* 0x65b: mov    rdi,QWORD PTR [rip+0x1df0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_662:
	/* 0x662: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_667:
	/* 0x667: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66c:
	/* 0x66c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66e:
	/* 0x66e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_671:
	/* 0x671: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_673:
	/* 0x673: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_675:
	/* 0x675: je     6d9 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x675, 0x6d9, x86_l_6d9);
x86_l_677:
	/* 0x677: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_67a:
	/* 0x67a: je     6d9 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x67a, 0x6d9, x86_l_6d9);
x86_l_67c:
	/* 0x67c: mov    rdi,QWORD PTR [rip+0x1df0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_683:
	/* 0x683: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_686:
	/* 0x686: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68b:
	/* 0x68b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68d:
	/* 0x68d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_690:
	/* 0x690: je     6d7 <filter_char_buf_prefix+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x690, 0x6d7, x86_l_6d7);
x86_l_692:
	/* 0x692: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_698:
	/* 0x698: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_69d:
	/* 0x69d: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_6a0:
	/* 0x6a0: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_6a7:
	/* 0x6a7: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a9:
	/* 0x6a9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6ac:
	/* 0x6ac: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6b0:
	/* 0x6b0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6b3:
	/* 0x6b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b8:
	/* 0x6b8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6bb:
	/* 0x6bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bd:
	/* 0x6bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c2:
	/* 0x6c2: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6c8:
	/* 0x6c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ca:
	/* 0x6ca: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6cd:
	/* 0x6cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cf:
	/* 0x6cf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_6d2:
	/* 0x6d2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_6d5:
	/* 0x6d5: jmp    6d9 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JMP(0x6d5, 0x6d9, x86_l_6d9);
x86_l_6d7:
	/* 0x6d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d9:
	/* 0x6d9: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6dd:
	/* 0x6dd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_6de:
	/* 0x6de: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_6e0:
	/* 0x6e0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_6e2:
	/* 0x6e2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_6e3:
	/* 0x6e3: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x54ULL: goto x86_l_54;
	case 0x72ULL: goto x86_l_72;
	case 0x88ULL: goto x86_l_88;
	case 0x9eULL: goto x86_l_9e;
	case 0x110ULL: goto x86_l_110;
	case 0x2a7ULL: goto x86_l_2a7;
	case 0x2bbULL: goto x86_l_2bb;
	case 0x2ffULL: goto x86_l_2ff;
	case 0x340ULL: goto x86_l_340;
	case 0x368ULL: goto x86_l_368;
	case 0x4caULL: goto x86_l_4ca;
	case 0x4deULL: goto x86_l_4de;
	case 0x529ULL: goto x86_l_529;
	case 0x552ULL: goto x86_l_552;
	case 0x62bULL: goto x86_l_62b;
	case 0x66eULL: goto x86_l_66e;
	case 0x68dULL: goto x86_l_68d;
	case 0x6bdULL: goto x86_l_6bd;
	case 0x6caULL: goto x86_l_6ca;
	}

}

X86_SIM_LICENSE();
