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
int tetragon_bpf_multi_retkprobe_v61_filter_file_buf_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_3:
	/* 0x3: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5:
	/* 0x5: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8:
	/* 0x8: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_a:
	/* 0xa: jne    1d <filter_file_buf+0x1d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa, 0x1d, x86_l_1d);
x86_l_c:
	/* 0xc: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_e:
	/* 0xe: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_11:
	/* 0x11: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_14:
	/* 0x14: je     1d <filter_file_buf+0x1d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14, 0x1d, x86_l_1d);
x86_l_16:
	/* 0x16: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18:
	/* 0x18: jmp    678 <filter_char_buf_prefix+0xa2> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1d:
	/* 0x1d: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_20:
	/* 0x20: ja     5c <filter_file_buf+0x5c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x20, 0x5c, x86_l_5c);
x86_l_22:
	/* 0x22: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_24:
	/* 0x24: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_29:
	/* 0x29: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d:
	/* 0x2d: jb     90 <filter_file_buf+0x90> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2d, 0x90, x86_l_90);
x86_l_2f:
	/* 0x2f: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_34:
	/* 0x34: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: jb     7a <filter_file_buf+0x7a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x38, 0x7a, x86_l_7a);
x86_l_3a:
	/* 0x3a: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_44:
	/* 0x44: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: jae    5c <filter_file_buf+0x5c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x48, 0x5c, x86_l_5c);
x86_l_4a:
	/* 0x4a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d:
	/* 0x4d: call   c8 <filter_file_type> */
	X86_SIM_X86_CALL(x86_l_c8, 0x52ULL);
x86_l_52:
	/* 0x52: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55:
	/* 0x55: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_58:
	/* 0x58: jbe    ad <filter_file_buf+0xad> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x58, 0xad, x86_l_ad);
x86_l_5a:
	/* 0x5a: jmp    c3 <filter_file_buf+0xc3> */
	X86_SIM_X86_JMP(0x5a, 0xc3, x86_l_c3);
x86_l_5c:
	/* 0x5c: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_5f:
	/* 0x5f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_62:
	/* 0x62: jae    a6 <filter_file_buf+0xa6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x62, 0xa6, x86_l_a6);
x86_l_64:
	/* 0x64: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_68:
	/* 0x68: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: call   159 <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_159, 0x70ULL);
x86_l_70:
	/* 0x70: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_73:
	/* 0x73: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_76:
	/* 0x76: jbe    ad <filter_file_buf+0xad> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x76, 0xad, x86_l_ad);
x86_l_78:
	/* 0x78: jmp    c3 <filter_file_buf+0xc3> */
	X86_SIM_X86_JMP(0x78, 0xc3, x86_l_c3);
x86_l_7a:
	/* 0x7a: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7e:
	/* 0x7e: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81:
	/* 0x81: call   48e <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_48e, 0x86ULL);
x86_l_86:
	/* 0x86: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_89:
	/* 0x89: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_8c:
	/* 0x8c: jbe    ad <filter_file_buf+0xad> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x8c, 0xad, x86_l_ad);
x86_l_8e:
	/* 0x8e: jmp    c3 <filter_file_buf+0xc3> */
	X86_SIM_X86_JMP(0x8e, 0xc3, x86_l_c3);
x86_l_90:
	/* 0x90: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_94:
	/* 0x94: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_97:
	/* 0x97: call   5d6 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_5d6, 0x9cULL);
x86_l_9c:
	/* 0x9c: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9f:
	/* 0x9f: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_a2:
	/* 0xa2: jbe    ad <filter_file_buf+0xad> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa2, 0xad, x86_l_ad);
x86_l_a4:
	/* 0xa4: jmp    c3 <filter_file_buf+0xc3> */
	X86_SIM_X86_JMP(0xa4, 0xc3, x86_l_c3);
x86_l_a6:
	/* 0xa6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8:
	/* 0xa8: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_ab:
	/* 0xab: ja     c3 <filter_file_buf+0xc3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xab, 0xc3, x86_l_c3);
x86_l_ad:
	/* 0xad: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_af:
	/* 0xaf: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_b9:
	/* 0xb9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: jae    c3 <filter_file_buf+0xc3> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xbd, 0xc3, x86_l_c3);
x86_l_bf:
	/* 0xbf: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_c3:
	/* 0xc3: jmp    678 <filter_char_buf_prefix+0xa2> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_678:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_c8 */
x86_l_c8:
	/* 0xc8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_c9:
	/* 0xc9: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_cd:
	/* 0xcd: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_d4:
	/* 0xd4: cmp    DWORD PTR [rsi],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_da:
	/* 0xda: ja     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xda, 0x151, x86_l_151);
x86_l_dc:
	/* 0xdc: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_df:
	/* 0xdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e4:
	/* 0xe4: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6:
	/* 0xe6: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_ea:
	/* 0xea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ee:
	/* 0xee: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_f3:
	/* 0xf3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f8:
	/* 0xf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa:
	/* 0xfa: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd:
	/* 0xfd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_ff:
	/* 0xff: je     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xff, 0x151, x86_l_151);
x86_l_101:
	/* 0x101: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_106:
	/* 0x106: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_10c:
	/* 0x10c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111:
	/* 0x111: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_113:
	/* 0x113: je     153 <filter_file_type+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x113, 0x153, x86_l_153);
x86_l_115:
	/* 0x115: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118:
	/* 0x118: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_11b:
	/* 0x11b: jbe    151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x11b, 0x151, x86_l_151);
x86_l_11d:
	/* 0x11d: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_120:
	/* 0x120: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_122:
	/* 0x122: je     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x122, 0x151, x86_l_151);
x86_l_124:
	/* 0x124: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_126:
	/* 0x126: je     153 <filter_file_type+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x126, 0x153, x86_l_153);
x86_l_128:
	/* 0x128: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_12b:
	/* 0x12b: jb     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x12b, 0x151, x86_l_151);
x86_l_12d:
	/* 0x12d: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_130:
	/* 0x130: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_132:
	/* 0x132: je     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x132, 0x151, x86_l_151);
x86_l_134:
	/* 0x134: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_136:
	/* 0x136: je     153 <filter_file_type+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x136, 0x153, x86_l_153);
x86_l_138:
	/* 0x138: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_13b:
	/* 0x13b: jb     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13b, 0x151, x86_l_151);
x86_l_13d:
	/* 0x13d: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_140:
	/* 0x140: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_142:
	/* 0x142: je     151 <filter_file_type+0x89> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x142, 0x151, x86_l_151);
x86_l_144:
	/* 0x144: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_146:
	/* 0x146: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_148:
	/* 0x148: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_14b:
	/* 0x14b: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14f:
	/* 0x14f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_151:
	/* 0x151: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153:
	/* 0x153: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_157:
	/* 0x157: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_158:
	/* 0x158: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_159 */
x86_l_159:
	/* 0x159: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_15a:
	/* 0x15a: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_15c:
	/* 0x15c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_15e:
	/* 0x15e: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_160:
	/* 0x160: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_162:
	/* 0x162: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_163:
	/* 0x163: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_167:
	/* 0x167: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_16f:
	/* 0x16f: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_175:
	/* 0x175: ja     47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x175, 0x47d, x86_l_47d);
x86_l_17b:
	/* 0x17b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_17d:
	/* 0x17d: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_180:
	/* 0x180: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_185:
	/* 0x185: ja     1d9 <filter_char_buf_equal+0x80> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x185, 0x1d9, x86_l_1d9);
x86_l_187:
	/* 0x187: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18b:
	/* 0x18b: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_191:
	/* 0x191: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_194:
	/* 0x194: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_197:
	/* 0x197: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_19a:
	/* 0x19a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_19c:
	/* 0x19c: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_19f:
	/* 0x19f: je     1aa <filter_char_buf_equal+0x51> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19f, 0x1aa, x86_l_1aa);
x86_l_1a1:
	/* 0x1a1: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a3:
	/* 0x1a3: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_1a6:
	/* 0x1a6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1a8:
	/* 0x1a8: je     1c3 <filter_char_buf_equal+0x6a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a8, 0x1c3, x86_l_1c3);
x86_l_1aa:
	/* 0x1aa: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ad:
	/* 0x1ad: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1af:
	/* 0x1af: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b1:
	/* 0x1b1: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1b3:
	/* 0x1b3: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1b6:
	/* 0x1b6: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ba:
	/* 0x1ba: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1be:
	/* 0x1be: ja     217 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1be, 0x217, x86_l_217);
x86_l_1c0:
	/* 0x1c0: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1c3:
	/* 0x1c3: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1c6:
	/* 0x1c6: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1cd:
	/* 0x1cd: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1d1:
	/* 0x1d1: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1d4:
	/* 0x1d4: jmp    262 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x1d4, 0x262, x86_l_262);
x86_l_1d9:
	/* 0x1d9: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_1df:
	/* 0x1df: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1e4:
	/* 0x1e4: jb     217 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e4, 0x217, x86_l_217);
x86_l_1e6:
	/* 0x1e6: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_1ec:
	/* 0x1ec: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1f1:
	/* 0x1f1: jb     217 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f1, 0x217, x86_l_217);
x86_l_1f3:
	/* 0x1f3: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_1f9:
	/* 0x1f9: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_1fe:
	/* 0x1fe: jb     217 <filter_char_buf_equal+0xbe> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1fe, 0x217, x86_l_217);
x86_l_200:
	/* 0x200: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203:
	/* 0x203: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_208:
	/* 0x208: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_20c:
	/* 0x20c: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_210:
	/* 0x210: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_217:
	/* 0x217: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_21e:
	/* 0x21e: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_224:
	/* 0x224: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_227:
	/* 0x227: jg     23a <filter_char_buf_equal+0xe1> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x227, 0x23a, x86_l_23a);
x86_l_229:
	/* 0x229: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22b:
	/* 0x22b: je     254 <filter_char_buf_equal+0xfb> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x22b, 0x254, x86_l_254);
x86_l_22d:
	/* 0x22d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_230:
	/* 0x230: jne    24c <filter_char_buf_equal+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x230, 0x24c, x86_l_24c);
x86_l_232:
	/* 0x232: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_238:
	/* 0x238: jmp    262 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x238, 0x262, x86_l_262);
x86_l_23a:
	/* 0x23a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_23d:
	/* 0x23d: je     25c <filter_char_buf_equal+0x103> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x23d, 0x25c, x86_l_25c);
x86_l_23f:
	/* 0x23f: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_242:
	/* 0x242: jne    24c <filter_char_buf_equal+0xf3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x242, 0x24c, x86_l_24c);
x86_l_244:
	/* 0x244: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_24a:
	/* 0x24a: jmp    262 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x24a, 0x262, x86_l_262);
x86_l_24c:
	/* 0x24c: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_252:
	/* 0x252: jmp    262 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x252, 0x262, x86_l_262);
x86_l_254:
	/* 0x254: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_25a:
	/* 0x25a: jmp    262 <filter_char_buf_equal+0x109> */
	X86_SIM_X86_SUB_JMP(0x25a, 0x262, x86_l_262);
x86_l_25c:
	/* 0x25c: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_262:
	/* 0x262: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_265:
	/* 0x265: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_268:
	/* 0x268: mov    ebx,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_26c:
	/* 0x26c: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_26f:
	/* 0x26f: je     47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x26f, 0x47d, x86_l_47d);
x86_l_275:
	/* 0x275: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a:
	/* 0x27a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27f:
	/* 0x27f: mov    rdi,QWORD PTR [rip+0x1a40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_286:
	/* 0x286: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b:
	/* 0x28b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290:
	/* 0x290: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_298:
	/* 0x298: mov    rdi,QWORD PTR [rip+0x1a40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_29f:
	/* 0x29f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a9:
	/* 0x2a9: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad:
	/* 0x2ad: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: je     47f <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2b0, 0x47f, x86_l_47f);
x86_l_2b6:
	/* 0x2b6: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: je     47f <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2b9, 0x47f, x86_l_47f);
x86_l_2bf:
	/* 0x2bf: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_2c3:
	/* 0x2c3: jg     2fe <filter_char_buf_equal+0x1a5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2c3, 0x2fe, x86_l_2fe);
x86_l_2c5:
	/* 0x2c5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c9:
	/* 0x2c9: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc:
	/* 0x2cc: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d0:
	/* 0x2d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d5:
	/* 0x2d5: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2d7:
	/* 0x2d7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc:
	/* 0x2dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de:
	/* 0x2de: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e1:
	/* 0x2e1: jbe    33e <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x2e1, 0x33e, x86_l_33e);
x86_l_2e3:
	/* 0x2e3: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2e5:
	/* 0x2e5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e9:
	/* 0x2e9: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ed:
	/* 0x2ed: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f0:
	/* 0x2f0: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f7:
	/* 0x2f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fc:
	/* 0x2fc: jmp    336 <filter_char_buf_equal+0x1dd> */
	X86_SIM_X86_SUB_JMP(0x2fc, 0x336, x86_l_336);
x86_l_2fe:
	/* 0x2fe: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_302:
	/* 0x302: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_305:
	/* 0x305: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_309:
	/* 0x309: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30e:
	/* 0x30e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_310:
	/* 0x310: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_315:
	/* 0x315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317:
	/* 0x317: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31a:
	/* 0x31a: jbe    33e <filter_char_buf_equal+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x31a, 0x33e, x86_l_33e);
x86_l_31c:
	/* 0x31c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_31e:
	/* 0x31e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322:
	/* 0x322: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_326:
	/* 0x326: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_32a:
	/* 0x32a: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_331:
	/* 0x331: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_336:
	/* 0x336: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_339:
	/* 0x339: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_33c:
	/* 0x33c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e:
	/* 0x33e: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_342:
	/* 0x342: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_346:
	/* 0x346: jle    37d <filter_char_buf_equal+0x224> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x346, 0x37d, x86_l_37d);
x86_l_348:
	/* 0x348: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_34c:
	/* 0x34c: jg     3ae <filter_char_buf_equal+0x255> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x34c, 0x3ae, x86_l_3ae);
x86_l_34e:
	/* 0x34e: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_352:
	/* 0x352: je     43c <filter_char_buf_equal+0x2e3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x352, 0x43c, x86_l_43c);
x86_l_358:
	/* 0x358: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_35c:
	/* 0x35c: je     412 <filter_char_buf_equal+0x2b9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x35c, 0x412, x86_l_412);
x86_l_362:
	/* 0x362: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_366:
	/* 0x366: jne    47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x366, 0x47d, x86_l_47d);
x86_l_36c:
	/* 0x36c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_371:
	/* 0x371: mov    rdi,QWORD PTR [rip+0x1a40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_378:
	/* 0x378: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x378, 0x456, x86_l_456);
x86_l_37d:
	/* 0x37d: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_381:
	/* 0x381: jle    3d9 <filter_char_buf_equal+0x280> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x381, 0x3d9, x86_l_3d9);
x86_l_383:
	/* 0x383: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_387:
	/* 0x387: je     42e <filter_char_buf_equal+0x2d5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x387, 0x42e, x86_l_42e);
x86_l_38d:
	/* 0x38d: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_391:
	/* 0x391: je     404 <filter_char_buf_equal+0x2ab> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x391, 0x404, x86_l_404);
x86_l_393:
	/* 0x393: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_397:
	/* 0x397: jne    47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x397, 0x47d, x86_l_47d);
x86_l_39d:
	/* 0x39d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a2:
	/* 0x3a2: mov    rdi,QWORD PTR [rip+0x1a40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3a9:
	/* 0x3a9: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x3a9, 0x456, x86_l_456);
x86_l_3ae:
	/* 0x3ae: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3b2:
	/* 0x3b2: je     44a <filter_char_buf_equal+0x2f1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3b2, 0x44a, x86_l_44a);
x86_l_3b8:
	/* 0x3b8: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3bc:
	/* 0x3bc: je     420 <filter_char_buf_equal+0x2c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3bc, 0x420, x86_l_420);
x86_l_3be:
	/* 0x3be: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_3c2:
	/* 0x3c2: jne    47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3c2, 0x47d, x86_l_47d);
x86_l_3c8:
	/* 0x3c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cd:
	/* 0x3cd: mov    rdi,QWORD PTR [rip+0x1a40] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_3d4:
	/* 0x3d4: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x3d4, 0x456, x86_l_456);
x86_l_3d9:
	/* 0x3d9: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_3dc:
	/* 0x3dc: je     3f6 <filter_char_buf_equal+0x29d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3dc, 0x3f6, x86_l_3f6);
x86_l_3de:
	/* 0x3de: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_3e2:
	/* 0x3e2: jne    47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3e2, 0x47d, x86_l_47d);
x86_l_3e8:
	/* 0x3e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ed:
	/* 0x3ed: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3f4:
	/* 0x3f4: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x3f4, 0x456, x86_l_456);
x86_l_3f6:
	/* 0x3f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fb:
	/* 0x3fb: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_402:
	/* 0x402: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x402, 0x456, x86_l_456);
x86_l_404:
	/* 0x404: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_409:
	/* 0x409: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_410:
	/* 0x410: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x410, 0x456, x86_l_456);
x86_l_412:
	/* 0x412: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_417:
	/* 0x417: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_41e:
	/* 0x41e: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x41e, 0x456, x86_l_456);
x86_l_420:
	/* 0x420: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_425:
	/* 0x425: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_42c:
	/* 0x42c: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x42c, 0x456, x86_l_456);
x86_l_42e:
	/* 0x42e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_433:
	/* 0x433: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_43a:
	/* 0x43a: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x43a, 0x456, x86_l_456);
x86_l_43c:
	/* 0x43c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_441:
	/* 0x441: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_448:
	/* 0x448: jmp    456 <filter_char_buf_equal+0x2fd> */
	X86_SIM_X86_SUB_JMP(0x448, 0x456, x86_l_456);
x86_l_44a:
	/* 0x44a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44f:
	/* 0x44f: mov    rdi,QWORD PTR [rip+0x1a3d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_456:
	/* 0x456: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_45b:
	/* 0x45b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d:
	/* 0x45d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_460:
	/* 0x460: je     47d <filter_char_buf_equal+0x324> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x460, 0x47d, x86_l_47d);
x86_l_462:
	/* 0x462: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_467:
	/* 0x467: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_46a:
	/* 0x46a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e:
	/* 0x46e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_470:
	/* 0x470: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_473:
	/* 0x473: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_475:
	/* 0x475: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_478:
	/* 0x478: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_47b:
	/* 0x47b: jmp    47f <filter_char_buf_equal+0x326> */
	X86_SIM_X86_SUB_JMP(0x47b, 0x47f, x86_l_47f);
x86_l_47d:
	/* 0x47d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47f:
	/* 0x47f: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_483:
	/* 0x483: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_486:
	/* 0x486: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_488:
	/* 0x488: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_48a:
	/* 0x48a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_48c:
	/* 0x48c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_48d:
	/* 0x48d: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_48e */
x86_l_48e:
	/* 0x48e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_490:
	/* 0x490: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_492:
	/* 0x492: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_493:
	/* 0x493: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_497:
	/* 0x497: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_499:
	/* 0x499: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_49c:
	/* 0x49c: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4a0:
	/* 0x4a0: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4a8:
	/* 0x4a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ad:
	/* 0x4ad: mov    rdi,QWORD PTR [rip+0x1e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_4b4:
	/* 0x4b4: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4b9:
	/* 0x4b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb:
	/* 0x4bb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4be:
	/* 0x4be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c0:
	/* 0x4c0: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_4c2:
	/* 0x4c2: je     5cc <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4c2, 0x5cc, x86_l_5cc);
x86_l_4c8:
	/* 0x4c8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_4cb:
	/* 0x4cb: je     5cc <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4cb, 0x5cc, x86_l_5cc);
x86_l_4d1:
	/* 0x4d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d6:
	/* 0x4d6: mov    rdi,QWORD PTR [rip+0x1e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_4dd:
	/* 0x4dd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e2:
	/* 0x4e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e4:
	/* 0x4e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e7:
	/* 0x4e7: je     5ca <filter_char_buf_postfix+0x13c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4e7, 0x5ca, x86_l_5ca);
x86_l_4ed:
	/* 0x4ed: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_4f0:
	/* 0x4f0: mov    ecx,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_4f5:
	/* 0x4f5: cmovb  ecx,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_4f8:
	/* 0x4f8: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_4fb:
	/* 0x4fb: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd:
	/* 0x4fd: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_4ff:
	/* 0x4ff: lea    edx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_502:
	/* 0x502: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_505:
	/* 0x505: add    rsi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_509:
	/* 0x509: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_50c:
	/* 0x50c: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_510:
	/* 0x510: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_512:
	/* 0x512: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_519:
	/* 0x519: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_51d:
	/* 0x51d: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_521:
	/* 0x521: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_528:
	/* 0x528: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_52d:
	/* 0x52d: mov    BYTE PTR [rsi-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_531:
	/* 0x531: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_535:
	/* 0x535: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_539:
	/* 0x539: je     5b0 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x539, 0x5b0, x86_l_5b0);
x86_l_53b:
	/* 0x53b: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_53f:
	/* 0x53f: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_543:
	/* 0x543: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_54a:
	/* 0x54a: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_54f:
	/* 0x54f: mov    BYTE PTR [rsi-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_553:
	/* 0x553: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_557:
	/* 0x557: je     5b0 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x557, 0x5b0, x86_l_5b0);
x86_l_559:
	/* 0x559: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_55d:
	/* 0x55d: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_561:
	/* 0x561: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_568:
	/* 0x568: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_56d:
	/* 0x56d: mov    BYTE PTR [rsi-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_571:
	/* 0x571: mov    r10,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RCX, X86_WIDTH_64);
x86_l_574:
	/* 0x574: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_577:
	/* 0x577: je     5b0 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x577, 0x5b0, x86_l_5b0);
x86_l_579:
	/* 0x579: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_57d:
	/* 0x57d: je     5b0 <filter_char_buf_postfix+0x122> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x57d, 0x5b0, x86_l_5b0);
x86_l_57f:
	/* 0x57f: lea    r10d,[rdx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_583:
	/* 0x583: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_587:
	/* 0x587: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_58e:
	/* 0x58e: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_593:
	/* 0x593: mov    BYTE PTR [rsi],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_596:
	/* 0x596: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_59a:
	/* 0x59a: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_59e:
	/* 0x59e: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_5a2:
	/* 0x5a2: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_5a6:
	/* 0x5a6: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_5aa:
	/* 0x5aa: jne    519 <filter_char_buf_postfix+0x8b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x5aa, 0x519, x86_l_519);
x86_l_5b0:
	/* 0x5b0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b5:
	/* 0x5b5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5b8:
	/* 0x5b8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5bd:
	/* 0x5bd: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5c0:
	/* 0x5c0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c2:
	/* 0x5c2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_5c5:
	/* 0x5c5: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_5c8:
	/* 0x5c8: jmp    5cc <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JMP(0x5c8, 0x5cc, x86_l_5cc);
x86_l_5ca:
	/* 0x5ca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cc:
	/* 0x5cc: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d0:
	/* 0x5d0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_5d1:
	/* 0x5d1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_5d3:
	/* 0x5d3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_5d6 */
x86_l_5d6:
	/* 0x5d6: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_5d7:
	/* 0x5d7: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5d9:
	/* 0x5d9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_5da:
	/* 0x5da: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_5de:
	/* 0x5de: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_5e0:
	/* 0x5e0: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_5e3:
	/* 0x5e3: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5e7:
	/* 0x5e7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5ef:
	/* 0x5ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f4:
	/* 0x5f4: mov    rdi,QWORD PTR [rip+0x1d80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_5fb:
	/* 0x5fb: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_600:
	/* 0x600: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_602:
	/* 0x602: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_605:
	/* 0x605: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_607:
	/* 0x607: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_609:
	/* 0x609: je     66f <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x609, 0x66f, x86_l_66f);
x86_l_60b:
	/* 0x60b: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: je     66f <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x60e, 0x66f, x86_l_66f);
x86_l_610:
	/* 0x610: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_615:
	/* 0x615: mov    rdi,QWORD PTR [rip+0x1d80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_61c:
	/* 0x61c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_621:
	/* 0x621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_623:
	/* 0x623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_626:
	/* 0x626: je     66d <filter_char_buf_prefix+0x97> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x626, 0x66d, x86_l_66d);
x86_l_628:
	/* 0x628: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_62e:
	/* 0x62e: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_633:
	/* 0x633: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_636:
	/* 0x636: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_63d:
	/* 0x63d: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63f:
	/* 0x63f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_642:
	/* 0x642: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_646:
	/* 0x646: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_64b:
	/* 0x64b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_651:
	/* 0x651: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_653:
	/* 0x653: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_658:
	/* 0x658: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_65b:
	/* 0x65b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_65e:
	/* 0x65e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_660:
	/* 0x660: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_663:
	/* 0x663: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_665:
	/* 0x665: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_668:
	/* 0x668: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_66b:
	/* 0x66b: jmp    66f <filter_char_buf_prefix+0x99> */
	X86_SIM_X86_SUB_JMP(0x66b, 0x66f, x86_l_66f);
x86_l_66d:
	/* 0x66d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66f:
	/* 0x66f: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_673:
	/* 0x673: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_674:
	/* 0x674: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_676:
	/* 0x676: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_677:
	/* 0x677: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x52ULL: goto x86_l_52;
	case 0x70ULL: goto x86_l_70;
	case 0x86ULL: goto x86_l_86;
	case 0x9cULL: goto x86_l_9c;
	case 0xfaULL: goto x86_l_fa;
	case 0x290ULL: goto x86_l_290;
	case 0x2a4ULL: goto x86_l_2a4;
	case 0x2deULL: goto x86_l_2de;
	case 0x317ULL: goto x86_l_317;
	case 0x33eULL: goto x86_l_33e;
	case 0x45dULL: goto x86_l_45d;
	case 0x470ULL: goto x86_l_470;
	case 0x4bbULL: goto x86_l_4bb;
	case 0x4e4ULL: goto x86_l_4e4;
	case 0x5bdULL: goto x86_l_5bd;
	case 0x602ULL: goto x86_l_602;
	case 0x623ULL: goto x86_l_623;
	case 0x653ULL: goto x86_l_653;
	case 0x660ULL: goto x86_l_660;
	}

}

X86_SIM_LICENSE();
