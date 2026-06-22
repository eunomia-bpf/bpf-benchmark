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
int tetragon_bpf_generic_fentry_v61_filter_file_buf_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x18: jmp    6e1 <filter_char_buf_prefix+0xa0> ; native-link entry RET */
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
	/* 0x6b: call   16c <filter_char_buf_equal> */
	X86_SIM_X86_CALL(x86_l_16c, 0x70ULL);
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
	/* 0x81: call   4f9 <filter_char_buf_postfix> */
	X86_SIM_X86_CALL(x86_l_4f9, 0x86ULL);
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
	/* 0x97: call   641 <filter_char_buf_prefix> */
	X86_SIM_X86_CALL(x86_l_641, 0x9cULL);
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
	/* 0xc3: jmp    6e1 <filter_char_buf_prefix+0xa0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_6e1:
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
	/* 0xd4: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6:
	/* 0xd6: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_dc:
	/* 0xdc: ja     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0xdc, 0x164, x86_l_164);
x86_l_e2:
	/* 0xe2: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_e5:
	/* 0xe5: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e9:
	/* 0xe9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ed:
	/* 0xed: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_f2:
	/* 0xf2: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f7:
	/* 0xf7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fc:
	/* 0xfc: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe:
	/* 0xfe: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_102:
	/* 0x102: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_106:
	/* 0x106: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10b:
	/* 0x10b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d:
	/* 0x10d: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110:
	/* 0x110: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_112:
	/* 0x112: je     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x112, 0x164, x86_l_164);
x86_l_114:
	/* 0x114: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_119:
	/* 0x119: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_11f:
	/* 0x11f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_124:
	/* 0x124: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_126:
	/* 0x126: je     166 <filter_file_type+0x9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x126, 0x166, x86_l_166);
x86_l_128:
	/* 0x128: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b:
	/* 0x12b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_12e:
	/* 0x12e: jbe    164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x12e, 0x164, x86_l_164);
x86_l_130:
	/* 0x130: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_133:
	/* 0x133: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_135:
	/* 0x135: je     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x135, 0x164, x86_l_164);
x86_l_137:
	/* 0x137: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_139:
	/* 0x139: je     166 <filter_file_type+0x9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x139, 0x166, x86_l_166);
x86_l_13b:
	/* 0x13b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_13e:
	/* 0x13e: jb     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x13e, 0x164, x86_l_164);
x86_l_140:
	/* 0x140: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_143:
	/* 0x143: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_145:
	/* 0x145: je     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x145, 0x164, x86_l_164);
x86_l_147:
	/* 0x147: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_149:
	/* 0x149: je     166 <filter_file_type+0x9e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x149, 0x166, x86_l_166);
x86_l_14b:
	/* 0x14b: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_14e:
	/* 0x14e: jb     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x14e, 0x164, x86_l_164);
x86_l_150:
	/* 0x150: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_153:
	/* 0x153: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_155:
	/* 0x155: je     164 <filter_file_type+0x9c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x155, 0x164, x86_l_164);
x86_l_157:
	/* 0x157: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159:
	/* 0x159: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_15b:
	/* 0x15b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_15e:
	/* 0x15e: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_162:
	/* 0x162: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_163:
	/* 0x163: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_164:
	/* 0x164: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166:
	/* 0x166: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16a:
	/* 0x16a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_16c */
x86_l_16c:
	/* 0x16c: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_16d:
	/* 0x16d: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_16f:
	/* 0x16f: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_171:
	/* 0x171: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_173:
	/* 0x173: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_175:
	/* 0x175: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_176:
	/* 0x176: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_17a:
	/* 0x17a: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_182:
	/* 0x182: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_188:
	/* 0x188: ja     4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x188, 0x4e8, x86_l_4e8);
x86_l_18e:
	/* 0x18e: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_191:
	/* 0x191: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_196:
	/* 0x196: ja     1e9 <filter_char_buf_equal+0x7d> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x196, 0x1e9, x86_l_1e9);
x86_l_198:
	/* 0x198: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_19b:
	/* 0x19b: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1a1:
	/* 0x1a1: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1a4:
	/* 0x1a4: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1a7:
	/* 0x1a7: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_1aa:
	/* 0x1aa: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1ac:
	/* 0x1ac: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1af:
	/* 0x1af: je     1ba <filter_char_buf_equal+0x4e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1af, 0x1ba, x86_l_1ba);
x86_l_1b1:
	/* 0x1b1: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1b3:
	/* 0x1b3: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_1b6:
	/* 0x1b6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b8:
	/* 0x1b8: je     1d3 <filter_char_buf_equal+0x67> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b8, 0x1d3, x86_l_1d3);
x86_l_1ba:
	/* 0x1ba: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bd:
	/* 0x1bd: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1bf:
	/* 0x1bf: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c1:
	/* 0x1c1: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1c3:
	/* 0x1c3: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1c6:
	/* 0x1c6: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ca:
	/* 0x1ca: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1ce:
	/* 0x1ce: ja     227 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x1ce, 0x227, x86_l_227);
x86_l_1d0:
	/* 0x1d0: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1d3:
	/* 0x1d3: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d6:
	/* 0x1d6: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1dd:
	/* 0x1dd: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1e1:
	/* 0x1e1: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1e4:
	/* 0x1e4: jmp    272 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x1e4, 0x272, x86_l_272);
x86_l_1e9:
	/* 0x1e9: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_1ef:
	/* 0x1ef: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1f4:
	/* 0x1f4: jb     227 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1f4, 0x227, x86_l_227);
x86_l_1f6:
	/* 0x1f6: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_1fc:
	/* 0x1fc: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_201:
	/* 0x201: jb     227 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x201, 0x227, x86_l_227);
x86_l_203:
	/* 0x203: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_209:
	/* 0x209: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_20e:
	/* 0x20e: jb     227 <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x20e, 0x227, x86_l_227);
x86_l_210:
	/* 0x210: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_213:
	/* 0x213: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_218:
	/* 0x218: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_21c:
	/* 0x21c: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_220:
	/* 0x220: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_227:
	/* 0x227: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_22e:
	/* 0x22e: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_234:
	/* 0x234: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_237:
	/* 0x237: jg     24a <filter_char_buf_equal+0xde> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x237, 0x24a, x86_l_24a);
x86_l_239:
	/* 0x239: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23b:
	/* 0x23b: je     264 <filter_char_buf_equal+0xf8> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x23b, 0x264, x86_l_264);
x86_l_23d:
	/* 0x23d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_240:
	/* 0x240: jne    25c <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x240, 0x25c, x86_l_25c);
x86_l_242:
	/* 0x242: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_248:
	/* 0x248: jmp    272 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x248, 0x272, x86_l_272);
x86_l_24a:
	/* 0x24a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_24d:
	/* 0x24d: je     26c <filter_char_buf_equal+0x100> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x24d, 0x26c, x86_l_26c);
x86_l_24f:
	/* 0x24f: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_252:
	/* 0x252: jne    25c <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x252, 0x25c, x86_l_25c);
x86_l_254:
	/* 0x254: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_25a:
	/* 0x25a: jmp    272 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x25a, 0x272, x86_l_272);
x86_l_25c:
	/* 0x25c: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_262:
	/* 0x262: jmp    272 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x262, 0x272, x86_l_272);
x86_l_264:
	/* 0x264: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_26a:
	/* 0x26a: jmp    272 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_SUB_JMP(0x26a, 0x272, x86_l_272);
x86_l_26c:
	/* 0x26c: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_272:
	/* 0x272: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_275:
	/* 0x275: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_278:
	/* 0x278: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_27d:
	/* 0x27d: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_281:
	/* 0x281: je     4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x281, 0x4e8, x86_l_4e8);
x86_l_287:
	/* 0x287: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28c:
	/* 0x28c: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_28e:
	/* 0x28e: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_295:
	/* 0x295: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29a:
	/* 0x29a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29f:
	/* 0x29f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ae:
	/* 0x2ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b3:
	/* 0x2b3: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2b6:
	/* 0x2b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b8:
	/* 0x2b8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2bb:
	/* 0x2bb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd:
	/* 0x2bd: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c2:
	/* 0x2c2: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2c5:
	/* 0x2c5: je     4ea <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c5, 0x4ea, x86_l_4ea);
x86_l_2cb:
	/* 0x2cb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2ce:
	/* 0x2ce: je     4ea <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2ce, 0x4ea, x86_l_4ea);
x86_l_2d4:
	/* 0x2d4: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d9:
	/* 0x2d9: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2dd:
	/* 0x2dd: jg     320 <filter_char_buf_equal+0x1b4> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2dd, 0x320, x86_l_320);
x86_l_2df:
	/* 0x2df: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4:
	/* 0x2e4: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7:
	/* 0x2e7: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2eb:
	/* 0x2eb: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_2ee:
	/* 0x2ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f3:
	/* 0x2f3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f8:
	/* 0x2f8: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2fa:
	/* 0x2fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc:
	/* 0x2fc: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ff:
	/* 0x2ff: jbe    365 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x2ff, 0x365, x86_l_365);
x86_l_301:
	/* 0x301: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_306:
	/* 0x306: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_30a:
	/* 0x30a: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_30d:
	/* 0x30d: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_314:
	/* 0x314: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_319:
	/* 0x319: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31e:
	/* 0x31e: jmp    360 <filter_char_buf_equal+0x1f4> */
	X86_SIM_X86_SUB_JMP(0x31e, 0x360, x86_l_360);
x86_l_320:
	/* 0x320: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_325:
	/* 0x325: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_328:
	/* 0x328: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_32c:
	/* 0x32c: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_32f:
	/* 0x32f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_334:
	/* 0x334: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_339:
	/* 0x339: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_33b:
	/* 0x33b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33d:
	/* 0x33d: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_340:
	/* 0x340: jbe    365 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0x340, 0x365, x86_l_365);
x86_l_342:
	/* 0x342: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_347:
	/* 0x347: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_34b:
	/* 0x34b: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_34f:
	/* 0x34f: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_356:
	/* 0x356: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35b:
	/* 0x35b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_360:
	/* 0x360: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_363:
	/* 0x363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_365:
	/* 0x365: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36a:
	/* 0x36a: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_36e:
	/* 0x36e: jle    3aa <filter_char_buf_equal+0x23e> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x36e, 0x3aa, x86_l_3aa);
x86_l_370:
	/* 0x370: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_374:
	/* 0x374: jg     3e4 <filter_char_buf_equal+0x278> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x374, 0x3e4, x86_l_3e4);
x86_l_376:
	/* 0x376: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_37a:
	/* 0x37a: je     49c <filter_char_buf_equal+0x330> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x37a, 0x49c, x86_l_49c);
x86_l_380:
	/* 0x380: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_384:
	/* 0x384: je     463 <filter_char_buf_equal+0x2f7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x384, 0x463, x86_l_463);
x86_l_38a:
	/* 0x38a: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_38e:
	/* 0x38e: jne    4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x38e, 0x4e8, x86_l_4e8);
x86_l_394:
	/* 0x394: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_39b:
	/* 0x39b: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a0:
	/* 0x3a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a5:
	/* 0x3a5: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3a5, 0x4c0, x86_l_4c0);
x86_l_3aa:
	/* 0x3aa: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3ae:
	/* 0x3ae: jle    418 <filter_char_buf_equal+0x2ac> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0x3ae, 0x418, x86_l_418);
x86_l_3b0:
	/* 0x3b0: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3b4:
	/* 0x3b4: je     489 <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3b4, 0x489, x86_l_489);
x86_l_3ba:
	/* 0x3ba: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3be:
	/* 0x3be: je     450 <filter_char_buf_equal+0x2e4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3be, 0x450, x86_l_450);
x86_l_3c4:
	/* 0x3c4: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3c8:
	/* 0x3c8: jne    4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3c8, 0x4e8, x86_l_4e8);
x86_l_3ce:
	/* 0x3ce: mov    rdi,QWORD PTR [rip+0x1ef0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3d5:
	/* 0x3d5: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3da:
	/* 0x3da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3df:
	/* 0x3df: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x3df, 0x4c0, x86_l_4c0);
x86_l_3e4:
	/* 0x3e4: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_3e8:
	/* 0x3e8: je     4af <filter_char_buf_equal+0x343> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3e8, 0x4af, x86_l_4af);
x86_l_3ee:
	/* 0x3ee: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_3f2:
	/* 0x3f2: je     476 <filter_char_buf_equal+0x30a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x3f2, 0x476, x86_l_476);
x86_l_3f8:
	/* 0x3f8: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_3fc:
	/* 0x3fc: jne    4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3fc, 0x4e8, x86_l_4e8);
x86_l_402:
	/* 0x402: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_409:
	/* 0x409: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40e:
	/* 0x40e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_413:
	/* 0x413: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x413, 0x4c0, x86_l_4c0);
x86_l_418:
	/* 0x418: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_41b:
	/* 0x41b: je     43d <filter_char_buf_equal+0x2d1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x41b, 0x43d, x86_l_43d);
x86_l_41d:
	/* 0x41d: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_421:
	/* 0x421: jne    4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x421, 0x4e8, x86_l_4e8);
x86_l_427:
	/* 0x427: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_42e:
	/* 0x42e: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_433:
	/* 0x433: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_438:
	/* 0x438: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x438, 0x4c0, x86_l_4c0);
x86_l_43d:
	/* 0x43d: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_444:
	/* 0x444: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_449:
	/* 0x449: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44e:
	/* 0x44e: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x44e, 0x4c0, x86_l_4c0);
x86_l_450:
	/* 0x450: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_457:
	/* 0x457: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45c:
	/* 0x45c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_461:
	/* 0x461: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x461, 0x4c0, x86_l_4c0);
x86_l_463:
	/* 0x463: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_46a:
	/* 0x46a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46f:
	/* 0x46f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_474:
	/* 0x474: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x474, 0x4c0, x86_l_4c0);
x86_l_476:
	/* 0x476: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_47d:
	/* 0x47d: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_482:
	/* 0x482: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_487:
	/* 0x487: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x487, 0x4c0, x86_l_4c0);
x86_l_489:
	/* 0x489: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_490:
	/* 0x490: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_495:
	/* 0x495: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49a:
	/* 0x49a: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x49a, 0x4c0, x86_l_4c0);
x86_l_49c:
	/* 0x49c: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_4a3:
	/* 0x4a3: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a8:
	/* 0x4a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ad:
	/* 0x4ad: jmp    4c0 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_SUB_JMP(0x4ad, 0x4c0, x86_l_4c0);
x86_l_4af:
	/* 0x4af: mov    rdi,QWORD PTR [rip+0x1eec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_4b6:
	/* 0x4b6: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4bb:
	/* 0x4bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c0:
	/* 0x4c0: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c5:
	/* 0x4c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c7:
	/* 0x4c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ca:
	/* 0x4ca: je     4e8 <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4ca, 0x4e8, x86_l_4e8);
x86_l_4cc:
	/* 0x4cc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4cf:
	/* 0x4cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d4:
	/* 0x4d4: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d9:
	/* 0x4d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db:
	/* 0x4db: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e0:
	/* 0x4e0: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4e3:
	/* 0x4e3: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_4e6:
	/* 0x4e6: jmp    4ea <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_SUB_JMP(0x4e6, 0x4ea, x86_l_4ea);
x86_l_4e8:
	/* 0x4e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ea:
	/* 0x4ea: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_4ee:
	/* 0x4ee: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4ef:
	/* 0x4ef: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_4f3:
	/* 0x4f3: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_4f7:
	/* 0x4f7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_4f9 */
x86_l_4f9:
	/* 0x4f9: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_4fb:
	/* 0x4fb: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4fd:
	/* 0x4fd: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4fe:
	/* 0x4fe: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_502:
	/* 0x502: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_504:
	/* 0x504: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_507:
	/* 0x507: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_50b:
	/* 0x50b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_513:
	/* 0x513: mov    rdi,QWORD PTR [rip+0x2320] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_51a:
	/* 0x51a: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_51f:
	/* 0x51f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_524:
	/* 0x524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_526:
	/* 0x526: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_529:
	/* 0x529: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52b:
	/* 0x52b: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_52d:
	/* 0x52d: je     637 <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x52d, 0x637, x86_l_637);
x86_l_533:
	/* 0x533: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_536:
	/* 0x536: je     637 <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x536, 0x637, x86_l_637);
x86_l_53c:
	/* 0x53c: mov    rdi,QWORD PTR [rip+0x2320] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_543:
	/* 0x543: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_548:
	/* 0x548: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54d:
	/* 0x54d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54f:
	/* 0x54f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_552:
	/* 0x552: je     635 <filter_char_buf_postfix+0x13c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x552, 0x635, x86_l_635);
x86_l_558:
	/* 0x558: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_55b:
	/* 0x55b: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_55e:
	/* 0x55e: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_563:
	/* 0x563: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_566:
	/* 0x566: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_569:
	/* 0x569: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56b:
	/* 0x56b: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_56d:
	/* 0x56d: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_570:
	/* 0x570: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_573:
	/* 0x573: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_577:
	/* 0x577: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_57a:
	/* 0x57a: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_57e:
	/* 0x57e: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_580:
	/* 0x580: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_587:
	/* 0x587: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_58b:
	/* 0x58b: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_58f:
	/* 0x58f: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_596:
	/* 0x596: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_59b:
	/* 0x59b: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_59f:
	/* 0x59f: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5a3:
	/* 0x5a3: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_5a7:
	/* 0x5a7: je     61e <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5a7, 0x61e, x86_l_61e);
x86_l_5a9:
	/* 0x5a9: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5ad:
	/* 0x5ad: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5b1:
	/* 0x5b1: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b8:
	/* 0x5b8: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_5bd:
	/* 0x5bd: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_5c1:
	/* 0x5c1: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_5c5:
	/* 0x5c5: je     61e <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5c5, 0x61e, x86_l_61e);
x86_l_5c7:
	/* 0x5c7: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5cb:
	/* 0x5cb: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5cf:
	/* 0x5cf: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d6:
	/* 0x5d6: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_5db:
	/* 0x5db: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5df:
	/* 0x5df: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_5e2:
	/* 0x5e2: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e5:
	/* 0x5e5: je     61e <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5e5, 0x61e, x86_l_61e);
x86_l_5e7:
	/* 0x5e7: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_5eb:
	/* 0x5eb: je     61e <filter_char_buf_postfix+0x125> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5eb, 0x61e, x86_l_61e);
x86_l_5ed:
	/* 0x5ed: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_5f1:
	/* 0x5f1: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_5f5:
	/* 0x5f5: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5fc:
	/* 0x5fc: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_601:
	/* 0x601: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_604:
	/* 0x604: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_608:
	/* 0x608: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_60c:
	/* 0x60c: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_610:
	/* 0x610: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_614:
	/* 0x614: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_618:
	/* 0x618: jne    587 <filter_char_buf_postfix+0x8e> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x618, 0x587, x86_l_587);
x86_l_61e:
	/* 0x61e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_623:
	/* 0x623: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_626:
	/* 0x626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_628:
	/* 0x628: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62d:
	/* 0x62d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_630:
	/* 0x630: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_633:
	/* 0x633: jmp    637 <filter_char_buf_postfix+0x13e> */
	X86_SIM_X86_SUB_JMP(0x633, 0x637, x86_l_637);
x86_l_635:
	/* 0x635: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_637:
	/* 0x637: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_63b:
	/* 0x63b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_63c:
	/* 0x63c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_63e:
	/* 0x63e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_640:
	/* 0x640: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_641 */
x86_l_641:
	/* 0x641: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_642:
	/* 0x642: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_644:
	/* 0x644: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_646:
	/* 0x646: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_647:
	/* 0x647: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_648:
	/* 0x648: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_64a:
	/* 0x64a: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_64d:
	/* 0x64d: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_651:
	/* 0x651: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_658:
	/* 0x658: mov    rdi,QWORD PTR [rip+0x2280] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_65f:
	/* 0x65f: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_664:
	/* 0x664: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_669:
	/* 0x669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66b:
	/* 0x66b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_66e:
	/* 0x66e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_670:
	/* 0x670: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_672:
	/* 0x672: je     6d6 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x672, 0x6d6, x86_l_6d6);
x86_l_674:
	/* 0x674: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_677:
	/* 0x677: je     6d6 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x677, 0x6d6, x86_l_6d6);
x86_l_679:
	/* 0x679: mov    rdi,QWORD PTR [rip+0x2280] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_680:
	/* 0x680: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_683:
	/* 0x683: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68d:
	/* 0x68d: je     6d4 <filter_char_buf_prefix+0x93> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x68d, 0x6d4, x86_l_6d4);
x86_l_68f:
	/* 0x68f: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_695:
	/* 0x695: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_69a:
	/* 0x69a: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_69d:
	/* 0x69d: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_6a4:
	/* 0x6a4: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a6:
	/* 0x6a6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6a9:
	/* 0x6a9: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6ad:
	/* 0x6ad: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6b0:
	/* 0x6b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b5:
	/* 0x6b5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6b8:
	/* 0x6b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ba:
	/* 0x6ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6bf:
	/* 0x6bf: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6c2:
	/* 0x6c2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c7:
	/* 0x6c7: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6ca:
	/* 0x6ca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cc:
	/* 0x6cc: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_6cf:
	/* 0x6cf: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_6d2:
	/* 0x6d2: jmp    6d6 <filter_char_buf_prefix+0x95> */
	X86_SIM_X86_SUB_JMP(0x6d2, 0x6d6, x86_l_6d6);
x86_l_6d4:
	/* 0x6d4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d6:
	/* 0x6d6: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6da:
	/* 0x6da: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_6db:
	/* 0x6db: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_6dd:
	/* 0x6dd: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_6df:
	/* 0x6df: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_6e0:
	/* 0x6e0: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x52ULL: goto x86_l_52;
	case 0x70ULL: goto x86_l_70;
	case 0x86ULL: goto x86_l_86;
	case 0x9cULL: goto x86_l_9c;
	case 0x10dULL: goto x86_l_10d;
	case 0x2a4ULL: goto x86_l_2a4;
	case 0x2b8ULL: goto x86_l_2b8;
	case 0x2fcULL: goto x86_l_2fc;
	case 0x33dULL: goto x86_l_33d;
	case 0x365ULL: goto x86_l_365;
	case 0x4c7ULL: goto x86_l_4c7;
	case 0x4dbULL: goto x86_l_4db;
	case 0x526ULL: goto x86_l_526;
	case 0x54fULL: goto x86_l_54f;
	case 0x628ULL: goto x86_l_628;
	case 0x66bULL: goto x86_l_66b;
	case 0x68aULL: goto x86_l_68a;
	case 0x6baULL: goto x86_l_6ba;
	case 0x6c7ULL: goto x86_l_6c7;
	}

}

X86_SIM_LICENSE();
