extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_event_v61___do_str_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4:
	/* 0x4: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11:
	/* 0x11: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16:
	/* 0x16: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_1b:
	/* 0x1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d:
	/* 0x1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20:
	/* 0x20: js     19c <__do_str+0x19c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x20, 0x19c, x86_l_19c);
x86_l_26:
	/* 0x26: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_2c:
	/* 0x2c: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_30:
	/* 0x30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: je     144 <__do_str+0x144> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33, 0x144, x86_l_144);
x86_l_39:
	/* 0x39: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_40:
	/* 0x40: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_47:
	/* 0x47: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b:
	/* 0x4b: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_53:
	/* 0x53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58:
	/* 0x58: mov    rdi,QWORD PTR [rip+0x127] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_5f:
	/* 0x5f: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_64:
	/* 0x64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66:
	/* 0x66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_69:
	/* 0x69: je     e2 <__do_str+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0xe2, x86_l_e2);
x86_l_6b:
	/* 0x6b: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_6f:
	/* 0x6f: je     e2 <__do_str+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f, 0xe2, x86_l_e2);
x86_l_71:
	/* 0x71: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_76:
	/* 0x76: mov    rsi,QWORD PTR [rip+0x127] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_7d:
	/* 0x7d: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_82:
	/* 0x82: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_85:
	/* 0x85: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_88:
	/* 0x88: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_8b:
	/* 0x8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d:
	/* 0x8d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90:
	/* 0x90: jns    196 <__do_str+0x196> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x90, 0x196, x86_l_196);
x86_l_96:
	/* 0x96: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_a1:
	/* 0xa1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a6:
	/* 0xa6: mov    rdi,QWORD PTR [rip+0x127] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_ad:
	/* 0xad: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_b2:
	/* 0xb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4:
	/* 0xb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b7:
	/* 0xb7: je     196 <__do_str+0x196> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7, 0x196, x86_l_196);
x86_l_bd:
	/* 0xbd: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_c1:
	/* 0xc1: jg     162 <__do_str+0x162> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc1, 0x162, x86_l_162);
x86_l_c7:
	/* 0xc7: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_cb:
	/* 0xcb: je     17c <__do_str+0x17c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb, 0x17c, x86_l_17c);
x86_l_d1:
	/* 0xd1: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_d5:
	/* 0xd5: jne    136 <__do_str+0x136> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd5, 0x136, x86_l_136);
x86_l_d7:
	/* 0xd7: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_dd:
	/* 0xdd: jmp    192 <__do_str+0x192> */
	X86_SIM_X86_JMP(0xdd, 0x192, x86_l_192);
x86_l_e2:
	/* 0xe2: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_e7:
	/* 0xe7: mov    rdi,QWORD PTR [rip+0x127] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_ee:
	/* 0xee: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_f1:
	/* 0xf1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f4:
	/* 0xf4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f6:
	/* 0xf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8:
	/* 0xf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: jns    196 <__do_str+0x196> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xfb, 0x196, x86_l_196);
x86_l_101:
	/* 0x101: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10c:
	/* 0x10c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111:
	/* 0x111: mov    rdi,QWORD PTR [rip+0x127] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_118:
	/* 0x118: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d:
	/* 0x11d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f:
	/* 0x11f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_122:
	/* 0x122: je     196 <__do_str+0x196> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122, 0x196, x86_l_196);
x86_l_124:
	/* 0x124: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_128:
	/* 0x128: jg     148 <__do_str+0x148> */
	X86_SIM_X86_JCC(X86_CC_G, 0x128, 0x148, x86_l_148);
x86_l_12a:
	/* 0x12a: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_12e:
	/* 0x12e: je     17c <__do_str+0x17c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e, 0x17c, x86_l_17c);
x86_l_130:
	/* 0x130: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_134:
	/* 0x134: je     d7 <__do_str+0xd7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x134, 0xd7, x86_l_d7);
x86_l_136:
	/* 0x136: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_13a:
	/* 0x13a: jne    174 <__do_str+0x174> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13a, 0x174, x86_l_174);
x86_l_13c:
	/* 0x13c: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_142:
	/* 0x142: jmp    192 <__do_str+0x192> */
	X86_SIM_X86_JMP(0x142, 0x192, x86_l_192);
x86_l_144:
	/* 0x144: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_146:
	/* 0x146: jmp    19c <__do_str+0x19c> */
	X86_SIM_X86_JMP(0x146, 0x19c, x86_l_19c);
x86_l_148:
	/* 0x148: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_14c:
	/* 0x14c: je     184 <__do_str+0x184> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c, 0x184, x86_l_184);
x86_l_14e:
	/* 0x14e: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_152:
	/* 0x152: je     18c <__do_str+0x18c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152, 0x18c, x86_l_18c);
x86_l_154:
	/* 0x154: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_158:
	/* 0x158: jne    174 <__do_str+0x174> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x158, 0x174, x86_l_174);
x86_l_15a:
	/* 0x15a: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_160:
	/* 0x160: jmp    192 <__do_str+0x192> */
	X86_SIM_X86_JMP(0x160, 0x192, x86_l_192);
x86_l_162:
	/* 0x162: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_166:
	/* 0x166: je     184 <__do_str+0x184> */
	X86_SIM_X86_JCC(X86_CC_E, 0x166, 0x184, x86_l_184);
x86_l_168:
	/* 0x168: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_16c:
	/* 0x16c: je     18c <__do_str+0x18c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16c, 0x18c, x86_l_18c);
x86_l_16e:
	/* 0x16e: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_172:
	/* 0x172: je     15a <__do_str+0x15a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172, 0x15a, x86_l_15a);
x86_l_174:
	/* 0x174: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_17a:
	/* 0x17a: jmp    192 <__do_str+0x192> */
	X86_SIM_X86_JMP(0x17a, 0x192, x86_l_192);
x86_l_17c:
	/* 0x17c: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_182:
	/* 0x182: jmp    192 <__do_str+0x192> */
	X86_SIM_X86_JMP(0x182, 0x192, x86_l_192);
x86_l_184:
	/* 0x184: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_18a:
	/* 0x18a: jmp    192 <__do_str+0x192> */
	X86_SIM_X86_JMP(0x18a, 0x192, x86_l_192);
x86_l_18c:
	/* 0x18c: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_192:
	/* 0x192: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_196:
	/* 0x196: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_199:
	/* 0x199: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_19c:
	/* 0x19c: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1a0:
	/* 0x1a0: jmp    1a5 <__do_str+0x1a5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1a5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
