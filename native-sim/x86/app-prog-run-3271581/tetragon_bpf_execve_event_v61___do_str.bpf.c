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
	/* 0x0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2:
	/* 0x2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4:
	/* 0x4: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_6:
	/* 0x6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_7:
	/* 0x7: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_b:
	/* 0xb: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_e:
	/* 0xe: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18:
	/* 0x18: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_1d:
	/* 0x1d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_22:
	/* 0x22: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_27:
	/* 0x27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29:
	/* 0x29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c:
	/* 0x2c: js     1b3 <__do_str+0x1b3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2c, 0x1b3, x86_l_1b3);
x86_l_32:
	/* 0x32: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_38:
	/* 0x38: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     15b <__do_str+0x15b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f, 0x15b, x86_l_15b);
x86_l_45:
	/* 0x45: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_4c:
	/* 0x4c: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_53:
	/* 0x53: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_5f:
	/* 0x5f: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_66:
	/* 0x66: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6b:
	/* 0x6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: je     f7 <__do_str+0xf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75, 0xf7, x86_l_f7);
x86_l_7b:
	/* 0x7b: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_7f:
	/* 0x7f: je     f7 <__do_str+0xf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f, 0xf7, x86_l_f7);
x86_l_81:
	/* 0x81: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_88:
	/* 0x88: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_8d:
	/* 0x8d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_92:
	/* 0x92: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_97:
	/* 0x97: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2:
	/* 0xa2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a5:
	/* 0xa5: jns    1ad <__do_str+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa5, 0x1ad, x86_l_1ad);
x86_l_ab:
	/* 0xab: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_ae:
	/* 0xae: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_b6:
	/* 0xb6: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_bd:
	/* 0xbd: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c2:
	/* 0xc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c7:
	/* 0xc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9:
	/* 0xc9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cc:
	/* 0xcc: je     1ad <__do_str+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc, 0x1ad, x86_l_1ad);
x86_l_d2:
	/* 0xd2: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_d6:
	/* 0xd6: jg     179 <__do_str+0x179> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd6, 0x179, x86_l_179);
x86_l_dc:
	/* 0xdc: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_e0:
	/* 0xe0: je     193 <__do_str+0x193> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0, 0x193, x86_l_193);
x86_l_e6:
	/* 0xe6: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_ea:
	/* 0xea: jne    14d <__do_str+0x14d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea, 0x14d, x86_l_14d);
x86_l_ec:
	/* 0xec: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_f2:
	/* 0xf2: jmp    1a9 <__do_str+0x1a9> */
	X86_SIM_X86_JMP(0xf2, 0x1a9, x86_l_1a9);
x86_l_f7:
	/* 0xf7: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_fe:
	/* 0xfe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100:
	/* 0x100: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_105:
	/* 0x105: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_108:
	/* 0x108: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d:
	/* 0x10d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f:
	/* 0x10f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112:
	/* 0x112: jns    1ad <__do_str+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x112, 0x1ad, x86_l_1ad);
x86_l_118:
	/* 0x118: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_123:
	/* 0x123: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_12a:
	/* 0x12a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12f:
	/* 0x12f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134:
	/* 0x134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_136:
	/* 0x136: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_139:
	/* 0x139: je     1ad <__do_str+0x1ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x1ad, x86_l_1ad);
x86_l_13b:
	/* 0x13b: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_13f:
	/* 0x13f: jg     15f <__do_str+0x15f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13f, 0x15f, x86_l_15f);
x86_l_141:
	/* 0x141: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_145:
	/* 0x145: je     193 <__do_str+0x193> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145, 0x193, x86_l_193);
x86_l_147:
	/* 0x147: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_14b:
	/* 0x14b: je     ec <__do_str+0xec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14b, 0xec, x86_l_ec);
x86_l_14d:
	/* 0x14d: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_151:
	/* 0x151: jne    18b <__do_str+0x18b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x151, 0x18b, x86_l_18b);
x86_l_153:
	/* 0x153: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_159:
	/* 0x159: jmp    1a9 <__do_str+0x1a9> */
	X86_SIM_X86_JMP(0x159, 0x1a9, x86_l_1a9);
x86_l_15b:
	/* 0x15b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d:
	/* 0x15d: jmp    1b3 <__do_str+0x1b3> */
	X86_SIM_X86_JMP(0x15d, 0x1b3, x86_l_1b3);
x86_l_15f:
	/* 0x15f: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_163:
	/* 0x163: je     19b <__do_str+0x19b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x163, 0x19b, x86_l_19b);
x86_l_165:
	/* 0x165: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_169:
	/* 0x169: je     1a3 <__do_str+0x1a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x169, 0x1a3, x86_l_1a3);
x86_l_16b:
	/* 0x16b: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_16f:
	/* 0x16f: jne    18b <__do_str+0x18b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16f, 0x18b, x86_l_18b);
x86_l_171:
	/* 0x171: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_177:
	/* 0x177: jmp    1a9 <__do_str+0x1a9> */
	X86_SIM_X86_JMP(0x177, 0x1a9, x86_l_1a9);
x86_l_179:
	/* 0x179: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_17d:
	/* 0x17d: je     19b <__do_str+0x19b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17d, 0x19b, x86_l_19b);
x86_l_17f:
	/* 0x17f: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_183:
	/* 0x183: je     1a3 <__do_str+0x1a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0x1a3, x86_l_1a3);
x86_l_185:
	/* 0x185: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_189:
	/* 0x189: je     171 <__do_str+0x171> */
	X86_SIM_X86_JCC(X86_CC_E, 0x189, 0x171, x86_l_171);
x86_l_18b:
	/* 0x18b: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_191:
	/* 0x191: jmp    1a9 <__do_str+0x1a9> */
	X86_SIM_X86_JMP(0x191, 0x1a9, x86_l_1a9);
x86_l_193:
	/* 0x193: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_199:
	/* 0x199: jmp    1a9 <__do_str+0x1a9> */
	X86_SIM_X86_JMP(0x199, 0x1a9, x86_l_1a9);
x86_l_19b:
	/* 0x19b: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_1a1:
	/* 0x1a1: jmp    1a9 <__do_str+0x1a9> */
	X86_SIM_X86_JMP(0x1a1, 0x1a9, x86_l_1a9);
x86_l_1a3:
	/* 0x1a3: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_1a9:
	/* 0x1a9: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ad:
	/* 0x1ad: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1b0:
	/* 0x1b0: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1b3:
	/* 0x1b3: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b7:
	/* 0x1b7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b8:
	/* 0x1b8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ba:
	/* 0x1ba: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1bc:
	/* 0x1bc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1be:
	/* 0x1be: jmp    1c3 <__do_str+0x1c3> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1c3:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
