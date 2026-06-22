extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_retuprobe_v511_generic_retuprobe_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f:
	/* 0xf: mov    rdi,QWORD PTR [rip+0x4185] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_16:
	/* 0x16: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b:
	/* 0x1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0xfe, x86_l_fe);
x86_l_2b:
	/* 0x2b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2e:
	/* 0x2e: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_33:
	/* 0x33: add    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_36:
	/* 0x36: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3b:
	/* 0x3b: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_40:
	/* 0x40: mov    r15d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9000ULL);
x86_l_46:
	/* 0x46: cmovb  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_4a:
	/* 0x4a: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_52:
	/* 0x52: mov    rdi,QWORD PTR [rip+0x4185] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_59:
	/* 0x59: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5e:
	/* 0x5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63:
	/* 0x63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65:
	/* 0x65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68:
	/* 0x68: je     bc <generic_retuprobe_output+0xbc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0xbc, x86_l_bc);
x86_l_6a:
	/* 0x6a: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_6e:
	/* 0x6e: je     bc <generic_retuprobe_output+0xbc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0xbc, x86_l_bc);
x86_l_70:
	/* 0x70: mov    rsi,QWORD PTR [rip+0x4185] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_77:
	/* 0x77: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_7c:
	/* 0x7c: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_81:
	/* 0x81: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_86:
	/* 0x86: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_89:
	/* 0x89: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_8f:
	/* 0x8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91:
	/* 0x91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94:
	/* 0x94: js     158 <generic_retuprobe_output+0x158> */
	X86_SIM_X86_JCC(X86_CC_S, 0x94, 0x158, x86_l_158);
x86_l_9a:
	/* 0x9a: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a2:
	/* 0xa2: mov    rdi,QWORD PTR [rip+0x4185] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_a9:
	/* 0xa9: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ae:
	/* 0xae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b3:
	/* 0xb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5:
	/* 0xb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b8:
	/* 0xb8: jne    f9 <generic_retuprobe_output+0xf9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb8, 0xf9, x86_l_f9);
x86_l_ba:
	/* 0xba: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0xba, 0xfe, x86_l_fe);
x86_l_bc:
	/* 0xbc: mov    rdi,QWORD PTR [rip+0x4185] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_c3:
	/* 0xc3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5:
	/* 0xc5: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_ca:
	/* 0xca: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_cd:
	/* 0xcd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d0:
	/* 0xd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2:
	/* 0xd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4:
	/* 0xd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d7:
	/* 0xd7: js     109 <generic_retuprobe_output+0x109> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd7, 0x109, x86_l_109);
x86_l_d9:
	/* 0xd9: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_e1:
	/* 0xe1: mov    rdi,QWORD PTR [rip+0x4185] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_e8:
	/* 0xe8: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ed:
	/* 0xed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2:
	/* 0xf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4:
	/* 0xf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7:
	/* 0xf7: je     fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf7, 0xfe, x86_l_fe);
x86_l_f9:
	/* 0xf9: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_fe:
	/* 0xfe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100:
	/* 0x100: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_104:
	/* 0x104: jmp    20b <generic_retuprobe_output+0x20b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_109:
	/* 0x109: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_114:
	/* 0x114: mov    rdi,QWORD PTR [rip+0x4186] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_11b:
	/* 0x11b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_120:
	/* 0x120: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_125:
	/* 0x125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127:
	/* 0x127: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: je     fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a, 0xfe, x86_l_fe);
x86_l_12c:
	/* 0x12c: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_130:
	/* 0x130: jg     19c <generic_retuprobe_output+0x19c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x130, 0x19c, x86_l_19c);
x86_l_132:
	/* 0x132: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_136:
	/* 0x136: je     1de <generic_retuprobe_output+0x1de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136, 0x1de, x86_l_1de);
x86_l_13c:
	/* 0x13c: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_140:
	/* 0x140: je     18d <generic_retuprobe_output+0x18d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140, 0x18d, x86_l_18d);
x86_l_142:
	/* 0x142: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_146:
	/* 0x146: jne    1cf <generic_retuprobe_output+0x1cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x146, 0x1cf, x86_l_1cf);
x86_l_14c:
	/* 0x14c: add    rax,0x360 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 864ULL);
x86_l_152:
	/* 0x152: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_156:
	/* 0x156: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x156, 0xfe, x86_l_fe);
x86_l_158:
	/* 0x158: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_15b:
	/* 0x15b: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_163:
	/* 0x163: mov    rdi,QWORD PTR [rip+0x4186] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_16a:
	/* 0x16a: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16f:
	/* 0x16f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_174:
	/* 0x174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176:
	/* 0x176: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_179:
	/* 0x179: je     fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x179, 0xfe, x86_l_fe);
x86_l_17b:
	/* 0x17b: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_17f:
	/* 0x17f: jg     1bd <generic_retuprobe_output+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17f, 0x1bd, x86_l_1bd);
x86_l_181:
	/* 0x181: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_185:
	/* 0x185: je     1de <generic_retuprobe_output+0x1de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x185, 0x1de, x86_l_1de);
x86_l_187:
	/* 0x187: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_18b:
	/* 0x18b: jne    142 <generic_retuprobe_output+0x142> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18b, 0x142, x86_l_142);
x86_l_18d:
	/* 0x18d: add    rax,0x368 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 872ULL);
x86_l_193:
	/* 0x193: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_197:
	/* 0x197: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x197, 0xfe, x86_l_fe);
x86_l_19c:
	/* 0x19c: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1a0:
	/* 0x1a0: je     1ed <generic_retuprobe_output+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0x1ed, x86_l_1ed);
x86_l_1a2:
	/* 0x1a2: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1a6:
	/* 0x1a6: je     1fc <generic_retuprobe_output+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6, 0x1fc, x86_l_1fc);
x86_l_1a8:
	/* 0x1a8: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1ac:
	/* 0x1ac: jne    1cf <generic_retuprobe_output+0x1cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ac, 0x1cf, x86_l_1cf);
x86_l_1ae:
	/* 0x1ae: add    rax,0x350 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 848ULL);
x86_l_1b4:
	/* 0x1b4: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b8:
	/* 0x1b8: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x1b8, 0xfe, x86_l_fe);
x86_l_1bd:
	/* 0x1bd: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1c1:
	/* 0x1c1: je     1ed <generic_retuprobe_output+0x1ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c1, 0x1ed, x86_l_1ed);
x86_l_1c3:
	/* 0x1c3: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1c7:
	/* 0x1c7: je     1fc <generic_retuprobe_output+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c7, 0x1fc, x86_l_1fc);
x86_l_1c9:
	/* 0x1c9: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1cd:
	/* 0x1cd: je     1ae <generic_retuprobe_output+0x1ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x1ae, x86_l_1ae);
x86_l_1cf:
	/* 0x1cf: add    rax,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_1d5:
	/* 0x1d5: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1d9:
	/* 0x1d9: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x1d9, 0xfe, x86_l_fe);
x86_l_1de:
	/* 0x1de: add    rax,0x370 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 880ULL);
x86_l_1e4:
	/* 0x1e4: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e8:
	/* 0x1e8: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x1e8, 0xfe, x86_l_fe);
x86_l_1ed:
	/* 0x1ed: add    rax,0x378 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 888ULL);
x86_l_1f3:
	/* 0x1f3: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1f7:
	/* 0x1f7: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x1f7, 0xfe, x86_l_fe);
x86_l_1fc:
	/* 0x1fc: add    rax,0x358 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 856ULL);
x86_l_202:
	/* 0x202: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_206:
	/* 0x206: jmp    fe <generic_retuprobe_output+0xfe> */
	X86_SIM_X86_JMP(0x206, 0xfe, x86_l_fe);
x86_l_20b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
