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
int tetragon_bpf_multi_retkprobe_v61_filter_char_buf_equal_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_f:
	/* 0xf: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_15:
	/* 0x15: ja     375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_A, 0x15, 0x375, x86_l_375);
x86_l_1b:
	/* 0x1b: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e:
	/* 0x1e: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_23:
	/* 0x23: ja     76 <filter_char_buf_equal+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x23, 0x76, x86_l_76);
x86_l_25:
	/* 0x25: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_28:
	/* 0x28: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2e:
	/* 0x2e: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_31:
	/* 0x31: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_34:
	/* 0x34: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_37:
	/* 0x37: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_39:
	/* 0x39: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_3c:
	/* 0x3c: je     47 <filter_char_buf_equal+0x47> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c, 0x47, x86_l_47);
x86_l_3e:
	/* 0x3e: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_40:
	/* 0x40: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_43:
	/* 0x43: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_45:
	/* 0x45: je     60 <filter_char_buf_equal+0x60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45, 0x60, x86_l_60);
x86_l_47:
	/* 0x47: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4a:
	/* 0x4a: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_4c:
	/* 0x4c: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e:
	/* 0x4e: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_50:
	/* 0x50: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_53:
	/* 0x53: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_57:
	/* 0x57: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_5b:
	/* 0x5b: ja     b4 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5b, 0xb4, x86_l_b4);
x86_l_5d:
	/* 0x5d: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_60:
	/* 0x60: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_63:
	/* 0x63: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_6a:
	/* 0x6a: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_6e:
	/* 0x6e: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_71:
	/* 0x71: jmp    ff <filter_char_buf_equal+0xff> */
	X86_SIM_X86_JMP(0x71, 0xff, x86_l_ff);
x86_l_76:
	/* 0x76: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_7c:
	/* 0x7c: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_81:
	/* 0x81: jb     b4 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x81, 0xb4, x86_l_b4);
x86_l_83:
	/* 0x83: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_89:
	/* 0x89: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_8e:
	/* 0x8e: jb     b4 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8e, 0xb4, x86_l_b4);
x86_l_90:
	/* 0x90: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_96:
	/* 0x96: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_9b:
	/* 0x9b: jb     b4 <filter_char_buf_equal+0xb4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9b, 0xb4, x86_l_b4);
x86_l_9d:
	/* 0x9d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0:
	/* 0xa0: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_a5:
	/* 0xa5: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_a9:
	/* 0xa9: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_ad:
	/* 0xad: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_b4:
	/* 0xb4: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_bb:
	/* 0xbb: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_c1:
	/* 0xc1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c4:
	/* 0xc4: jg     d7 <filter_char_buf_equal+0xd7> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc4, 0xd7, x86_l_d7);
x86_l_c6:
	/* 0xc6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c8:
	/* 0xc8: je     f1 <filter_char_buf_equal+0xf1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8, 0xf1, x86_l_f1);
x86_l_ca:
	/* 0xca: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd:
	/* 0xcd: jne    e9 <filter_char_buf_equal+0xe9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcd, 0xe9, x86_l_e9);
x86_l_cf:
	/* 0xcf: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_d5:
	/* 0xd5: jmp    ff <filter_char_buf_equal+0xff> */
	X86_SIM_X86_JMP(0xd5, 0xff, x86_l_ff);
x86_l_d7:
	/* 0xd7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_da:
	/* 0xda: je     f9 <filter_char_buf_equal+0xf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda, 0xf9, x86_l_f9);
x86_l_dc:
	/* 0xdc: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_df:
	/* 0xdf: jne    e9 <filter_char_buf_equal+0xe9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdf, 0xe9, x86_l_e9);
x86_l_e1:
	/* 0xe1: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_e7:
	/* 0xe7: jmp    ff <filter_char_buf_equal+0xff> */
	X86_SIM_X86_JMP(0xe7, 0xff, x86_l_ff);
x86_l_e9:
	/* 0xe9: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_ef:
	/* 0xef: jmp    ff <filter_char_buf_equal+0xff> */
	X86_SIM_X86_JMP(0xef, 0xff, x86_l_ff);
x86_l_f1:
	/* 0xf1: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_f7:
	/* 0xf7: jmp    ff <filter_char_buf_equal+0xff> */
	X86_SIM_X86_JMP(0xf7, 0xff, x86_l_ff);
x86_l_f9:
	/* 0xf9: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_ff:
	/* 0xff: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_102:
	/* 0x102: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_105:
	/* 0x105: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_10a:
	/* 0x10a: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_10e:
	/* 0x10e: je     375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e, 0x375, x86_l_375);
x86_l_114:
	/* 0x114: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_119:
	/* 0x119: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_11b:
	/* 0x11b: mov    rdi,QWORD PTR [rip+0x1a67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_122:
	/* 0x122: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_127:
	/* 0x127: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c:
	/* 0x12c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131:
	/* 0x131: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_134:
	/* 0x134: mov    rdi,QWORD PTR [rip+0x1a67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_13b:
	/* 0x13b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140:
	/* 0x140: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_143:
	/* 0x143: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145:
	/* 0x145: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_148:
	/* 0x148: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a:
	/* 0x14a: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14f:
	/* 0x14f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_152:
	/* 0x152: je     377 <filter_char_buf_equal+0x377> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152, 0x377, x86_l_377);
x86_l_158:
	/* 0x158: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15b:
	/* 0x15b: je     377 <filter_char_buf_equal+0x377> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15b, 0x377, x86_l_377);
x86_l_161:
	/* 0x161: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_166:
	/* 0x166: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_16a:
	/* 0x16a: jg     1ad <filter_char_buf_equal+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16a, 0x1ad, x86_l_1ad);
x86_l_16c:
	/* 0x16c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_171:
	/* 0x171: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174:
	/* 0x174: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_178:
	/* 0x178: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_17b:
	/* 0x17b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180:
	/* 0x180: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_185:
	/* 0x185: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_187:
	/* 0x187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189:
	/* 0x189: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_18c:
	/* 0x18c: jbe    1f2 <filter_char_buf_equal+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x18c, 0x1f2, x86_l_1f2);
x86_l_18e:
	/* 0x18e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193:
	/* 0x193: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_197:
	/* 0x197: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_19a:
	/* 0x19a: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a1:
	/* 0x1a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6:
	/* 0x1a6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ab:
	/* 0x1ab: jmp    1ed <filter_char_buf_equal+0x1ed> */
	X86_SIM_X86_JMP(0x1ab, 0x1ed, x86_l_1ed);
x86_l_1ad:
	/* 0x1ad: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2:
	/* 0x1b2: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5:
	/* 0x1b5: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1b9:
	/* 0x1b9: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1bc:
	/* 0x1bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c1:
	/* 0x1c1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c6:
	/* 0x1c6: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1cd:
	/* 0x1cd: jbe    1f2 <filter_char_buf_equal+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1cd, 0x1f2, x86_l_1f2);
x86_l_1cf:
	/* 0x1cf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d4:
	/* 0x1d4: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1d8:
	/* 0x1d8: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1dc:
	/* 0x1dc: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e3:
	/* 0x1e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e8:
	/* 0x1e8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ed:
	/* 0x1ed: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2:
	/* 0x1f2: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f7:
	/* 0x1f7: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1fb:
	/* 0x1fb: jle    237 <filter_char_buf_equal+0x237> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1fb, 0x237, x86_l_237);
x86_l_1fd:
	/* 0x1fd: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_201:
	/* 0x201: jg     271 <filter_char_buf_equal+0x271> */
	X86_SIM_X86_JCC(X86_CC_G, 0x201, 0x271, x86_l_271);
x86_l_203:
	/* 0x203: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_207:
	/* 0x207: je     329 <filter_char_buf_equal+0x329> */
	X86_SIM_X86_JCC(X86_CC_E, 0x207, 0x329, x86_l_329);
x86_l_20d:
	/* 0x20d: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_211:
	/* 0x211: je     2f0 <filter_char_buf_equal+0x2f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x211, 0x2f0, x86_l_2f0);
x86_l_217:
	/* 0x217: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_21b:
	/* 0x21b: jne    375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21b, 0x375, x86_l_375);
x86_l_221:
	/* 0x221: mov    rdi,QWORD PTR [rip+0x1a67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_228:
	/* 0x228: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22d:
	/* 0x22d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_232:
	/* 0x232: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x232, 0x34d, x86_l_34d);
x86_l_237:
	/* 0x237: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_23b:
	/* 0x23b: jle    2a5 <filter_char_buf_equal+0x2a5> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x23b, 0x2a5, x86_l_2a5);
x86_l_23d:
	/* 0x23d: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_241:
	/* 0x241: je     316 <filter_char_buf_equal+0x316> */
	X86_SIM_X86_JCC(X86_CC_E, 0x241, 0x316, x86_l_316);
x86_l_247:
	/* 0x247: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_24b:
	/* 0x24b: je     2dd <filter_char_buf_equal+0x2dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24b, 0x2dd, x86_l_2dd);
x86_l_251:
	/* 0x251: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_255:
	/* 0x255: jne    375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x255, 0x375, x86_l_375);
x86_l_25b:
	/* 0x25b: mov    rdi,QWORD PTR [rip+0x1a67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_262:
	/* 0x262: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_267:
	/* 0x267: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26c:
	/* 0x26c: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x26c, 0x34d, x86_l_34d);
x86_l_271:
	/* 0x271: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_275:
	/* 0x275: je     33c <filter_char_buf_equal+0x33c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x275, 0x33c, x86_l_33c);
x86_l_27b:
	/* 0x27b: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_27f:
	/* 0x27f: je     303 <filter_char_buf_equal+0x303> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27f, 0x303, x86_l_303);
x86_l_285:
	/* 0x285: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_289:
	/* 0x289: jne    375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x289, 0x375, x86_l_375);
x86_l_28f:
	/* 0x28f: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_296:
	/* 0x296: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29b:
	/* 0x29b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a0:
	/* 0x2a0: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x2a0, 0x34d, x86_l_34d);
x86_l_2a5:
	/* 0x2a5: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_2a8:
	/* 0x2a8: je     2ca <filter_char_buf_equal+0x2ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a8, 0x2ca, x86_l_2ca);
x86_l_2aa:
	/* 0x2aa: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2ae:
	/* 0x2ae: jne    375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ae, 0x375, x86_l_375);
x86_l_2b4:
	/* 0x2b4: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2bb:
	/* 0x2bb: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c0:
	/* 0x2c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5:
	/* 0x2c5: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x2c5, 0x34d, x86_l_34d);
x86_l_2ca:
	/* 0x2ca: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2d1:
	/* 0x2d1: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d6:
	/* 0x2d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db:
	/* 0x2db: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x2db, 0x34d, x86_l_34d);
x86_l_2dd:
	/* 0x2dd: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2e4:
	/* 0x2e4: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e9:
	/* 0x2e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ee:
	/* 0x2ee: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x2ee, 0x34d, x86_l_34d);
x86_l_2f0:
	/* 0x2f0: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2f7:
	/* 0x2f7: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fc:
	/* 0x2fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_301:
	/* 0x301: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x301, 0x34d, x86_l_34d);
x86_l_303:
	/* 0x303: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_30a:
	/* 0x30a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_30f:
	/* 0x30f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314:
	/* 0x314: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x314, 0x34d, x86_l_34d);
x86_l_316:
	/* 0x316: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_31d:
	/* 0x31d: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_322:
	/* 0x322: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_327:
	/* 0x327: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x327, 0x34d, x86_l_34d);
x86_l_329:
	/* 0x329: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_330:
	/* 0x330: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_335:
	/* 0x335: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33a:
	/* 0x33a: jmp    34d <filter_char_buf_equal+0x34d> */
	X86_SIM_X86_JMP(0x33a, 0x34d, x86_l_34d);
x86_l_33c:
	/* 0x33c: mov    rdi,QWORD PTR [rip+0x1a63] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_343:
	/* 0x343: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_348:
	/* 0x348: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34d:
	/* 0x34d: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_352:
	/* 0x352: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354:
	/* 0x354: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_357:
	/* 0x357: je     375 <filter_char_buf_equal+0x375> */
	X86_SIM_X86_JCC(X86_CC_E, 0x357, 0x375, x86_l_375);
x86_l_359:
	/* 0x359: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_35c:
	/* 0x35c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_361:
	/* 0x361: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_366:
	/* 0x366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368:
	/* 0x368: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_36b:
	/* 0x36b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36d:
	/* 0x36d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_370:
	/* 0x370: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_373:
	/* 0x373: jmp    377 <filter_char_buf_equal+0x377> */
	X86_SIM_X86_JMP(0x373, 0x377, x86_l_377);
x86_l_375:
	/* 0x375: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377:
	/* 0x377: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_37b:
	/* 0x37b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_37d:
	/* 0x37d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_37e:
	/* 0x37e: jmp    383 <filter_char_buf_equal+0x383> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_383:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
