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
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retkprobe_v61_filter_char_buf_equal_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f:
	/* 0xf: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_15:
	/* 0x15: ja     31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x15, 0x31d, x86_l_31d);
x86_l_1b:
	/* 0x1b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_1d:
	/* 0x1d: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20:
	/* 0x20: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_25:
	/* 0x25: ja     79 <filter_char_buf_equal+0x79> */
	X86_SIM_X86_JCC(X86_CC_A, 0x25, 0x79, x86_l_79);
x86_l_27:
	/* 0x27: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b:
	/* 0x2b: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_31:
	/* 0x31: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_34:
	/* 0x34: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_37:
	/* 0x37: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_3a:
	/* 0x3a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_3c:
	/* 0x3c: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_3f:
	/* 0x3f: je     4a <filter_char_buf_equal+0x4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f, 0x4a, x86_l_4a);
x86_l_41:
	/* 0x41: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_43:
	/* 0x43: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_46:
	/* 0x46: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_48:
	/* 0x48: je     63 <filter_char_buf_equal+0x63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48, 0x63, x86_l_63);
x86_l_4a:
	/* 0x4a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4d:
	/* 0x4d: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_4f:
	/* 0x4f: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_51:
	/* 0x51: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_53:
	/* 0x53: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_56:
	/* 0x56: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5a:
	/* 0x5a: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_5e:
	/* 0x5e: ja     b7 <filter_char_buf_equal+0xb7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5e, 0xb7, x86_l_b7);
x86_l_60:
	/* 0x60: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_63:
	/* 0x63: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_66:
	/* 0x66: imul   r13d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R13, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_6d:
	/* 0x6d: shr    r13d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_71:
	/* 0x71: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_74:
	/* 0x74: jmp    102 <filter_char_buf_equal+0x102> */
	X86_SIM_X86_JMP(0x74, 0x102, x86_l_102);
x86_l_79:
	/* 0x79: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_7f:
	/* 0x7f: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_84:
	/* 0x84: jb     b7 <filter_char_buf_equal+0xb7> */
	X86_SIM_X86_JCC(X86_CC_B, 0x84, 0xb7, x86_l_b7);
x86_l_86:
	/* 0x86: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_8c:
	/* 0x8c: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_91:
	/* 0x91: jb     b7 <filter_char_buf_equal+0xb7> */
	X86_SIM_X86_JCC(X86_CC_B, 0x91, 0xb7, x86_l_b7);
x86_l_93:
	/* 0x93: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_99:
	/* 0x99: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_9e:
	/* 0x9e: jb     b7 <filter_char_buf_equal+0xb7> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9e, 0xb7, x86_l_b7);
x86_l_a0:
	/* 0xa0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3:
	/* 0xa3: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_a8:
	/* 0xa8: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_ac:
	/* 0xac: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_b0:
	/* 0xb0: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_b7:
	/* 0xb7: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_be:
	/* 0xbe: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_c4:
	/* 0xc4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c7:
	/* 0xc7: jg     da <filter_char_buf_equal+0xda> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc7, 0xda, x86_l_da);
x86_l_c9:
	/* 0xc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb:
	/* 0xcb: je     f4 <filter_char_buf_equal+0xf4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb, 0xf4, x86_l_f4);
x86_l_cd:
	/* 0xcd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0:
	/* 0xd0: jne    ec <filter_char_buf_equal+0xec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd0, 0xec, x86_l_ec);
x86_l_d2:
	/* 0xd2: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_d8:
	/* 0xd8: jmp    102 <filter_char_buf_equal+0x102> */
	X86_SIM_X86_JMP(0xd8, 0x102, x86_l_102);
x86_l_da:
	/* 0xda: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_dd:
	/* 0xdd: je     fc <filter_char_buf_equal+0xfc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdd, 0xfc, x86_l_fc);
x86_l_df:
	/* 0xdf: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_e2:
	/* 0xe2: jne    ec <filter_char_buf_equal+0xec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe2, 0xec, x86_l_ec);
x86_l_e4:
	/* 0xe4: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_ea:
	/* 0xea: jmp    102 <filter_char_buf_equal+0x102> */
	X86_SIM_X86_JMP(0xea, 0x102, x86_l_102);
x86_l_ec:
	/* 0xec: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_f2:
	/* 0xf2: jmp    102 <filter_char_buf_equal+0x102> */
	X86_SIM_X86_JMP(0xf2, 0x102, x86_l_102);
x86_l_f4:
	/* 0xf4: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_fa:
	/* 0xfa: jmp    102 <filter_char_buf_equal+0x102> */
	X86_SIM_X86_JMP(0xfa, 0x102, x86_l_102);
x86_l_fc:
	/* 0xfc: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_102:
	/* 0x102: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_105:
	/* 0x105: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_108:
	/* 0x108: mov    ebx,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_10c:
	/* 0x10c: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_10f:
	/* 0x10f: je     31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f, 0x31d, x86_l_31d);
x86_l_115:
	/* 0x115: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a:
	/* 0x11a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11f:
	/* 0x11f: mov    rdi,QWORD PTR [rip+0x1a47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_126:
	/* 0x126: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b:
	/* 0x12b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12e:
	/* 0x12e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130:
	/* 0x130: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_133:
	/* 0x133: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138:
	/* 0x138: mov    rdi,QWORD PTR [rip+0x1a47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_13f:
	/* 0x13f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_142:
	/* 0x142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144:
	/* 0x144: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_147:
	/* 0x147: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149:
	/* 0x149: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d:
	/* 0x14d: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     31f <filter_char_buf_equal+0x31f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x150, 0x31f, x86_l_31f);
x86_l_156:
	/* 0x156: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_159:
	/* 0x159: je     31f <filter_char_buf_equal+0x31f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159, 0x31f, x86_l_31f);
x86_l_15f:
	/* 0x15f: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_163:
	/* 0x163: jg     19e <filter_char_buf_equal+0x19e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x163, 0x19e, x86_l_19e);
x86_l_165:
	/* 0x165: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_169:
	/* 0x169: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16c:
	/* 0x16c: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_170:
	/* 0x170: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_175:
	/* 0x175: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_177:
	/* 0x177: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c:
	/* 0x17c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e:
	/* 0x17e: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_181:
	/* 0x181: jbe    1de <filter_char_buf_equal+0x1de> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x181, 0x1de, x86_l_1de);
x86_l_183:
	/* 0x183: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_185:
	/* 0x185: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189:
	/* 0x189: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_18d:
	/* 0x18d: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_190:
	/* 0x190: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_197:
	/* 0x197: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c:
	/* 0x19c: jmp    1d6 <filter_char_buf_equal+0x1d6> */
	X86_SIM_X86_JMP(0x19c, 0x1d6, x86_l_1d6);
x86_l_19e:
	/* 0x19e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2:
	/* 0x1a2: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a5:
	/* 0x1a5: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1a9:
	/* 0x1a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae:
	/* 0x1ae: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1b0:
	/* 0x1b0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b5:
	/* 0x1b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7:
	/* 0x1b7: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ba:
	/* 0x1ba: jbe    1de <filter_char_buf_equal+0x1de> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1ba, 0x1de, x86_l_1de);
x86_l_1bc:
	/* 0x1bc: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1be:
	/* 0x1be: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2:
	/* 0x1c2: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c6:
	/* 0x1c6: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1ca:
	/* 0x1ca: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d1:
	/* 0x1d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d6:
	/* 0x1d6: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1d9:
	/* 0x1d9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1dc:
	/* 0x1dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de:
	/* 0x1de: mov    DWORD PTR [rsp+0xc],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e2:
	/* 0x1e2: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1e6:
	/* 0x1e6: jle    21d <filter_char_buf_equal+0x21d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1e6, 0x21d, x86_l_21d);
x86_l_1e8:
	/* 0x1e8: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_1ec:
	/* 0x1ec: jg     24e <filter_char_buf_equal+0x24e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1ec, 0x24e, x86_l_24e);
x86_l_1ee:
	/* 0x1ee: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1f2:
	/* 0x1f2: je     2dc <filter_char_buf_equal+0x2dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2, 0x2dc, x86_l_2dc);
x86_l_1f8:
	/* 0x1f8: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_1fc:
	/* 0x1fc: je     2b2 <filter_char_buf_equal+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fc, 0x2b2, x86_l_2b2);
x86_l_202:
	/* 0x202: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_206:
	/* 0x206: jne    31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x206, 0x31d, x86_l_31d);
x86_l_20c:
	/* 0x20c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_211:
	/* 0x211: mov    rdi,QWORD PTR [rip+0x1a47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_218:
	/* 0x218: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x218, 0x2f6, x86_l_2f6);
x86_l_21d:
	/* 0x21d: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_221:
	/* 0x221: jle    279 <filter_char_buf_equal+0x279> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x221, 0x279, x86_l_279);
x86_l_223:
	/* 0x223: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_227:
	/* 0x227: je     2ce <filter_char_buf_equal+0x2ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x227, 0x2ce, x86_l_2ce);
x86_l_22d:
	/* 0x22d: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_231:
	/* 0x231: je     2a4 <filter_char_buf_equal+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x231, 0x2a4, x86_l_2a4);
x86_l_233:
	/* 0x233: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_237:
	/* 0x237: jne    31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x237, 0x31d, x86_l_31d);
x86_l_23d:
	/* 0x23d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_242:
	/* 0x242: mov    rdi,QWORD PTR [rip+0x1a47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_249:
	/* 0x249: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x249, 0x2f6, x86_l_2f6);
x86_l_24e:
	/* 0x24e: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_252:
	/* 0x252: je     2ea <filter_char_buf_equal+0x2ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x252, 0x2ea, x86_l_2ea);
x86_l_258:
	/* 0x258: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_25c:
	/* 0x25c: je     2c0 <filter_char_buf_equal+0x2c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25c, 0x2c0, x86_l_2c0);
x86_l_25e:
	/* 0x25e: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_262:
	/* 0x262: jne    31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x262, 0x31d, x86_l_31d);
x86_l_268:
	/* 0x268: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d:
	/* 0x26d: mov    rdi,QWORD PTR [rip+0x1a47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_274:
	/* 0x274: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x274, 0x2f6, x86_l_2f6);
x86_l_279:
	/* 0x279: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_27c:
	/* 0x27c: je     296 <filter_char_buf_equal+0x296> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27c, 0x296, x86_l_296);
x86_l_27e:
	/* 0x27e: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_282:
	/* 0x282: jne    31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x282, 0x31d, x86_l_31d);
x86_l_288:
	/* 0x288: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28d:
	/* 0x28d: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_294:
	/* 0x294: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x294, 0x2f6, x86_l_2f6);
x86_l_296:
	/* 0x296: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29b:
	/* 0x29b: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2a2:
	/* 0x2a2: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x2a2, 0x2f6, x86_l_2f6);
x86_l_2a4:
	/* 0x2a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a9:
	/* 0x2a9: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2b0:
	/* 0x2b0: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x2b0, 0x2f6, x86_l_2f6);
x86_l_2b2:
	/* 0x2b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b7:
	/* 0x2b7: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2be:
	/* 0x2be: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x2be, 0x2f6, x86_l_2f6);
x86_l_2c0:
	/* 0x2c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5:
	/* 0x2c5: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_2cc:
	/* 0x2cc: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x2cc, 0x2f6, x86_l_2f6);
x86_l_2ce:
	/* 0x2ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d3:
	/* 0x2d3: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2da:
	/* 0x2da: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x2da, 0x2f6, x86_l_2f6);
x86_l_2dc:
	/* 0x2dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e1:
	/* 0x2e1: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2e8:
	/* 0x2e8: jmp    2f6 <filter_char_buf_equal+0x2f6> */
	X86_SIM_X86_JMP(0x2e8, 0x2f6, x86_l_2f6);
x86_l_2ea:
	/* 0x2ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ef:
	/* 0x2ef: mov    rdi,QWORD PTR [rip+0x1a44] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_2f6:
	/* 0x2f6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2fb:
	/* 0x2fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd:
	/* 0x2fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_300:
	/* 0x300: je     31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x300, 0x31d, x86_l_31d);
x86_l_302:
	/* 0x302: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_307:
	/* 0x307: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30a:
	/* 0x30a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e:
	/* 0x30e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_310:
	/* 0x310: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_315:
	/* 0x315: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_318:
	/* 0x318: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_31b:
	/* 0x31b: jmp    31f <filter_char_buf_equal+0x31f> */
	X86_SIM_X86_JMP(0x31b, 0x31f, x86_l_31f);
x86_l_31d:
	/* 0x31d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31f:
	/* 0x31f: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_323:
	/* 0x323: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_325:
	/* 0x325: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_326:
	/* 0x326: jmp    32b <filter_char_buf_equal+0x32b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_32b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
