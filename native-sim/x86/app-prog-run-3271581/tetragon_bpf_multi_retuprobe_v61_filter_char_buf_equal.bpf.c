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
int tetragon_bpf_multi_retuprobe_v61_filter_char_buf_equal_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3:
	/* 0x3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5:
	/* 0x5: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_7:
	/* 0x7: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_9:
	/* 0x9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_a:
	/* 0xa: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_e:
	/* 0xe: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_16:
	/* 0x16: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1c:
	/* 0x1c: ja     37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1c, 0x37c, x86_l_37c);
x86_l_22:
	/* 0x22: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_25:
	/* 0x25: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_2a:
	/* 0x2a: ja     7d <filter_char_buf_equal+0x7d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2a, 0x7d, x86_l_7d);
x86_l_2c:
	/* 0x2c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f:
	/* 0x2f: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_35:
	/* 0x35: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_38:
	/* 0x38: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_3b:
	/* 0x3b: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_3e:
	/* 0x3e: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_40:
	/* 0x40: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_43:
	/* 0x43: je     4e <filter_char_buf_equal+0x4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43, 0x4e, x86_l_4e);
x86_l_45:
	/* 0x45: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_47:
	/* 0x47: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_4a:
	/* 0x4a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c:
	/* 0x4c: je     67 <filter_char_buf_equal+0x67> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c, 0x67, x86_l_67);
x86_l_4e:
	/* 0x4e: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_51:
	/* 0x51: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_53:
	/* 0x53: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_55:
	/* 0x55: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_57:
	/* 0x57: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_5a:
	/* 0x5a: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5e:
	/* 0x5e: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_62:
	/* 0x62: ja     bb <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x62, 0xbb, x86_l_bb);
x86_l_64:
	/* 0x64: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_67:
	/* 0x67: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6a:
	/* 0x6a: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_71:
	/* 0x71: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_75:
	/* 0x75: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_78:
	/* 0x78: jmp    106 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_JMP(0x78, 0x106, x86_l_106);
x86_l_7d:
	/* 0x7d: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_83:
	/* 0x83: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_88:
	/* 0x88: jb     bb <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x88, 0xbb, x86_l_bb);
x86_l_8a:
	/* 0x8a: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_90:
	/* 0x90: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_95:
	/* 0x95: jb     bb <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x95, 0xbb, x86_l_bb);
x86_l_97:
	/* 0x97: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_9d:
	/* 0x9d: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_a2:
	/* 0xa2: jb     bb <filter_char_buf_equal+0xbb> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa2, 0xbb, x86_l_bb);
x86_l_a4:
	/* 0xa4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a7:
	/* 0xa7: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_ac:
	/* 0xac: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_b0:
	/* 0xb0: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_b4:
	/* 0xb4: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_bb:
	/* 0xbb: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_c2:
	/* 0xc2: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_c8:
	/* 0xc8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cb:
	/* 0xcb: jg     de <filter_char_buf_equal+0xde> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcb, 0xde, x86_l_de);
x86_l_cd:
	/* 0xcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf:
	/* 0xcf: je     f8 <filter_char_buf_equal+0xf8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf, 0xf8, x86_l_f8);
x86_l_d1:
	/* 0xd1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d4:
	/* 0xd4: jne    f0 <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd4, 0xf0, x86_l_f0);
x86_l_d6:
	/* 0xd6: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_dc:
	/* 0xdc: jmp    106 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_JMP(0xdc, 0x106, x86_l_106);
x86_l_de:
	/* 0xde: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_e1:
	/* 0xe1: je     100 <filter_char_buf_equal+0x100> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe1, 0x100, x86_l_100);
x86_l_e3:
	/* 0xe3: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_e6:
	/* 0xe6: jne    f0 <filter_char_buf_equal+0xf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe6, 0xf0, x86_l_f0);
x86_l_e8:
	/* 0xe8: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_ee:
	/* 0xee: jmp    106 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_JMP(0xee, 0x106, x86_l_106);
x86_l_f0:
	/* 0xf0: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_f6:
	/* 0xf6: jmp    106 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_JMP(0xf6, 0x106, x86_l_106);
x86_l_f8:
	/* 0xf8: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fe:
	/* 0xfe: jmp    106 <filter_char_buf_equal+0x106> */
	X86_SIM_X86_JMP(0xfe, 0x106, x86_l_106);
x86_l_100:
	/* 0x100: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_106:
	/* 0x106: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_109:
	/* 0x109: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_10c:
	/* 0x10c: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_111:
	/* 0x111: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_115:
	/* 0x115: je     37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115, 0x37c, x86_l_37c);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_120:
	/* 0x120: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_122:
	/* 0x122: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_129:
	/* 0x129: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12e:
	/* 0x12e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_133:
	/* 0x133: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_136:
	/* 0x136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138:
	/* 0x138: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_142:
	/* 0x142: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147:
	/* 0x147: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_14a:
	/* 0x14a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c:
	/* 0x14c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14f:
	/* 0x14f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_151:
	/* 0x151: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_156:
	/* 0x156: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: je     37e <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159, 0x37e, x86_l_37e);
x86_l_15f:
	/* 0x15f: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_162:
	/* 0x162: je     37e <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x162, 0x37e, x86_l_37e);
x86_l_168:
	/* 0x168: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16d:
	/* 0x16d: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_171:
	/* 0x171: jg     1b4 <filter_char_buf_equal+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x171, 0x1b4, x86_l_1b4);
x86_l_173:
	/* 0x173: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178:
	/* 0x178: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b:
	/* 0x17b: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_17f:
	/* 0x17f: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_182:
	/* 0x182: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_187:
	/* 0x187: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c:
	/* 0x18c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_18e:
	/* 0x18e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190:
	/* 0x190: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_193:
	/* 0x193: jbe    1f9 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x193, 0x1f9, x86_l_1f9);
x86_l_195:
	/* 0x195: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a:
	/* 0x19a: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_19e:
	/* 0x19e: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1a1:
	/* 0x1a1: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a8:
	/* 0x1a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ad:
	/* 0x1ad: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b2:
	/* 0x1b2: jmp    1f4 <filter_char_buf_equal+0x1f4> */
	X86_SIM_X86_JMP(0x1b2, 0x1f4, x86_l_1f4);
x86_l_1b4:
	/* 0x1b4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b9:
	/* 0x1b9: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc:
	/* 0x1bc: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1c0:
	/* 0x1c0: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1c3:
	/* 0x1c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8:
	/* 0x1c8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd:
	/* 0x1cd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1cf:
	/* 0x1cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1:
	/* 0x1d1: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1d4:
	/* 0x1d4: jbe    1f9 <filter_char_buf_equal+0x1f9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1d4, 0x1f9, x86_l_1f9);
x86_l_1d6:
	/* 0x1d6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db:
	/* 0x1db: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1df:
	/* 0x1df: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1e3:
	/* 0x1e3: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ea:
	/* 0x1ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef:
	/* 0x1ef: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f4:
	/* 0x1f4: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1f7:
	/* 0x1f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9:
	/* 0x1f9: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fe:
	/* 0x1fe: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_202:
	/* 0x202: jle    23e <filter_char_buf_equal+0x23e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x202, 0x23e, x86_l_23e);
x86_l_204:
	/* 0x204: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_208:
	/* 0x208: jg     278 <filter_char_buf_equal+0x278> */
	X86_SIM_X86_JCC(X86_CC_G, 0x208, 0x278, x86_l_278);
x86_l_20a:
	/* 0x20a: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_20e:
	/* 0x20e: je     330 <filter_char_buf_equal+0x330> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20e, 0x330, x86_l_330);
x86_l_214:
	/* 0x214: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_218:
	/* 0x218: je     2f7 <filter_char_buf_equal+0x2f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x218, 0x2f7, x86_l_2f7);
x86_l_21e:
	/* 0x21e: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_222:
	/* 0x222: jne    37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x222, 0x37c, x86_l_37c);
x86_l_228:
	/* 0x228: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_22f:
	/* 0x22f: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_234:
	/* 0x234: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_239:
	/* 0x239: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x239, 0x354, x86_l_354);
x86_l_23e:
	/* 0x23e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_242:
	/* 0x242: jle    2ac <filter_char_buf_equal+0x2ac> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x242, 0x2ac, x86_l_2ac);
x86_l_244:
	/* 0x244: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_248:
	/* 0x248: je     31d <filter_char_buf_equal+0x31d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x248, 0x31d, x86_l_31d);
x86_l_24e:
	/* 0x24e: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_252:
	/* 0x252: je     2e4 <filter_char_buf_equal+0x2e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x252, 0x2e4, x86_l_2e4);
x86_l_258:
	/* 0x258: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_25c:
	/* 0x25c: jne    37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25c, 0x37c, x86_l_37c);
x86_l_262:
	/* 0x262: mov    rdi,QWORD PTR [rip+0x1a60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_269:
	/* 0x269: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26e:
	/* 0x26e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_273:
	/* 0x273: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x273, 0x354, x86_l_354);
x86_l_278:
	/* 0x278: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_27c:
	/* 0x27c: je     343 <filter_char_buf_equal+0x343> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27c, 0x343, x86_l_343);
x86_l_282:
	/* 0x282: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_286:
	/* 0x286: je     30a <filter_char_buf_equal+0x30a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x286, 0x30a, x86_l_30a);
x86_l_28c:
	/* 0x28c: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_290:
	/* 0x290: jne    37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x290, 0x37c, x86_l_37c);
x86_l_296:
	/* 0x296: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_29d:
	/* 0x29d: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a2:
	/* 0x2a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7:
	/* 0x2a7: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x2a7, 0x354, x86_l_354);
x86_l_2ac:
	/* 0x2ac: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_2af:
	/* 0x2af: je     2d1 <filter_char_buf_equal+0x2d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2af, 0x2d1, x86_l_2d1);
x86_l_2b1:
	/* 0x2b1: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2b5:
	/* 0x2b5: jne    37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b5, 0x37c, x86_l_37c);
x86_l_2bb:
	/* 0x2bb: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2c2:
	/* 0x2c2: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c7:
	/* 0x2c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cc:
	/* 0x2cc: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x2cc, 0x354, x86_l_354);
x86_l_2d1:
	/* 0x2d1: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2d8:
	/* 0x2d8: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2dd:
	/* 0x2dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e2:
	/* 0x2e2: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x2e2, 0x354, x86_l_354);
x86_l_2e4:
	/* 0x2e4: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2eb:
	/* 0x2eb: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f0:
	/* 0x2f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5:
	/* 0x2f5: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x2f5, 0x354, x86_l_354);
x86_l_2f7:
	/* 0x2f7: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2fe:
	/* 0x2fe: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_303:
	/* 0x303: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_308:
	/* 0x308: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x308, 0x354, x86_l_354);
x86_l_30a:
	/* 0x30a: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_311:
	/* 0x311: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_316:
	/* 0x316: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31b:
	/* 0x31b: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x31b, 0x354, x86_l_354);
x86_l_31d:
	/* 0x31d: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_324:
	/* 0x324: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_329:
	/* 0x329: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32e:
	/* 0x32e: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x32e, 0x354, x86_l_354);
x86_l_330:
	/* 0x330: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_337:
	/* 0x337: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33c:
	/* 0x33c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_341:
	/* 0x341: jmp    354 <filter_char_buf_equal+0x354> */
	X86_SIM_X86_JMP(0x341, 0x354, x86_l_354);
x86_l_343:
	/* 0x343: mov    rdi,QWORD PTR [rip+0x1a5c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_34a:
	/* 0x34a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34f:
	/* 0x34f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_354:
	/* 0x354: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_359:
	/* 0x359: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b:
	/* 0x35b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35e:
	/* 0x35e: je     37c <filter_char_buf_equal+0x37c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35e, 0x37c, x86_l_37c);
x86_l_360:
	/* 0x360: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_363:
	/* 0x363: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_368:
	/* 0x368: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36d:
	/* 0x36d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f:
	/* 0x36f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_372:
	/* 0x372: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_374:
	/* 0x374: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_377:
	/* 0x377: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_37a:
	/* 0x37a: jmp    37e <filter_char_buf_equal+0x37e> */
	X86_SIM_X86_JMP(0x37a, 0x37e, x86_l_37e);
x86_l_37c:
	/* 0x37c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37e:
	/* 0x37e: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_382:
	/* 0x382: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_383:
	/* 0x383: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_385:
	/* 0x385: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_387:
	/* 0x387: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_389:
	/* 0x389: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_38b:
	/* 0x38b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_38c:
	/* 0x38c: jmp    391 <filter_char_buf_equal+0x391> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_391:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
