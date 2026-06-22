extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_event_v61_do_str_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_12:
	/* 0x12: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_17:
	/* 0x17: call   59 <__do_str> */
	X86_SIM_X86_CALL(x86_l_59, 0x1cULL);
x86_l_1c:
	/* 0x1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f:
	/* 0x1f: js     50 <do_str+0x50> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f, 0x50, x86_l_50);
x86_l_21:
	/* 0x21: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_26:
	/* 0x26: jne    50 <do_str+0x50> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x26, 0x50, x86_l_50);
x86_l_28:
	/* 0x28: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b:
	/* 0x2b: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_30:
	/* 0x30: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_33:
	/* 0x33: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_36:
	/* 0x36: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_39:
	/* 0x39: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: call   59 <__do_str> */
	X86_SIM_X86_CALL(x86_l_59, 0x41ULL);
x86_l_41:
	/* 0x41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43:
	/* 0x43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_4a:
	/* 0x4a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d:
	/* 0x4d: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_54:
	/* 0x54: jmp    208 <__do_str+0x1af> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_208:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_59 */
x86_l_59:
	/* 0x59: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_5b:
	/* 0x5b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5d:
	/* 0x5d: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_5f:
	/* 0x5f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_60:
	/* 0x60: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_64:
	/* 0x64: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_67:
	/* 0x67: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71:
	/* 0x71: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_76:
	/* 0x76: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_7b:
	/* 0x7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d:
	/* 0x7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80:
	/* 0x80: js     1fc <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x80, 0x1fc, x86_l_1fc);
x86_l_86:
	/* 0x86: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_8c:
	/* 0x8c: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_90:
	/* 0x90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: je     1a4 <__do_str+0x14b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x93, 0x1a4, x86_l_1a4);
x86_l_99:
	/* 0x99: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_9c:
	/* 0x9c: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_a0:
	/* 0xa0: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_a7:
	/* 0xa7: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ab:
	/* 0xab: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_b3:
	/* 0xb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b8:
	/* 0xb8: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_bf:
	/* 0xbf: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c4:
	/* 0xc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6:
	/* 0xc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c9:
	/* 0xc9: je     142 <__do_str+0xe9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc9, 0x142, x86_l_142);
x86_l_cb:
	/* 0xcb: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_cf:
	/* 0xcf: je     142 <__do_str+0xe9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xcf, 0x142, x86_l_142);
x86_l_d1:
	/* 0xd1: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_d6:
	/* 0xd6: mov    rsi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_dd:
	/* 0xdd: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_e2:
	/* 0xe2: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e5:
	/* 0xe5: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_e8:
	/* 0xe8: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_eb:
	/* 0xeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed:
	/* 0xed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: jns    1f6 <__do_str+0x19d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xf0, 0x1f6, x86_l_1f6);
x86_l_f6:
	/* 0xf6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_101:
	/* 0x101: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_106:
	/* 0x106: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_10d:
	/* 0x10d: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_112:
	/* 0x112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114:
	/* 0x114: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_117:
	/* 0x117: je     1f6 <__do_str+0x19d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x117, 0x1f6, x86_l_1f6);
x86_l_11d:
	/* 0x11d: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_121:
	/* 0x121: jg     1c2 <__do_str+0x169> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x121, 0x1c2, x86_l_1c2);
x86_l_127:
	/* 0x127: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_12b:
	/* 0x12b: je     1dc <__do_str+0x183> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x12b, 0x1dc, x86_l_1dc);
x86_l_131:
	/* 0x131: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_135:
	/* 0x135: jne    196 <__do_str+0x13d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x135, 0x196, x86_l_196);
x86_l_137:
	/* 0x137: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_13d:
	/* 0x13d: jmp    1f2 <__do_str+0x199> */
	X86_SIM_X86_SUB_JMP(0x13d, 0x1f2, x86_l_1f2);
x86_l_142:
	/* 0x142: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_147:
	/* 0x147: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_14e:
	/* 0x14e: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_151:
	/* 0x151: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_154:
	/* 0x154: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_156:
	/* 0x156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158:
	/* 0x158: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b:
	/* 0x15b: jns    1f6 <__do_str+0x19d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x15b, 0x1f6, x86_l_1f6);
x86_l_161:
	/* 0x161: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_164:
	/* 0x164: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_16c:
	/* 0x16c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_171:
	/* 0x171: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_178:
	/* 0x178: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d:
	/* 0x17d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f:
	/* 0x17f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_182:
	/* 0x182: je     1f6 <__do_str+0x19d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x182, 0x1f6, x86_l_1f6);
x86_l_184:
	/* 0x184: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_188:
	/* 0x188: jg     1a8 <__do_str+0x14f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x188, 0x1a8, x86_l_1a8);
x86_l_18a:
	/* 0x18a: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_18e:
	/* 0x18e: je     1dc <__do_str+0x183> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x18e, 0x1dc, x86_l_1dc);
x86_l_190:
	/* 0x190: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_194:
	/* 0x194: je     137 <__do_str+0xde> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x194, 0x137, x86_l_137);
x86_l_196:
	/* 0x196: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_19a:
	/* 0x19a: jne    1d4 <__do_str+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x19a, 0x1d4, x86_l_1d4);
x86_l_19c:
	/* 0x19c: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_1a2:
	/* 0x1a2: jmp    1f2 <__do_str+0x199> */
	X86_SIM_X86_SUB_JMP(0x1a2, 0x1f2, x86_l_1f2);
x86_l_1a4:
	/* 0x1a4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6:
	/* 0x1a6: jmp    1fc <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JMP(0x1a6, 0x1fc, x86_l_1fc);
x86_l_1a8:
	/* 0x1a8: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1ac:
	/* 0x1ac: je     1e4 <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ac, 0x1e4, x86_l_1e4);
x86_l_1ae:
	/* 0x1ae: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1b2:
	/* 0x1b2: je     1ec <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b2, 0x1ec, x86_l_1ec);
x86_l_1b4:
	/* 0x1b4: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1b8:
	/* 0x1b8: jne    1d4 <__do_str+0x17b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b8, 0x1d4, x86_l_1d4);
x86_l_1ba:
	/* 0x1ba: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_1c0:
	/* 0x1c0: jmp    1f2 <__do_str+0x199> */
	X86_SIM_X86_SUB_JMP(0x1c0, 0x1f2, x86_l_1f2);
x86_l_1c2:
	/* 0x1c2: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1c6:
	/* 0x1c6: je     1e4 <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c6, 0x1e4, x86_l_1e4);
x86_l_1c8:
	/* 0x1c8: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1cc:
	/* 0x1cc: je     1ec <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cc, 0x1ec, x86_l_1ec);
x86_l_1ce:
	/* 0x1ce: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1d2:
	/* 0x1d2: je     1ba <__do_str+0x161> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d2, 0x1ba, x86_l_1ba);
x86_l_1d4:
	/* 0x1d4: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_1da:
	/* 0x1da: jmp    1f2 <__do_str+0x199> */
	X86_SIM_X86_SUB_JMP(0x1da, 0x1f2, x86_l_1f2);
x86_l_1dc:
	/* 0x1dc: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_1e2:
	/* 0x1e2: jmp    1f2 <__do_str+0x199> */
	X86_SIM_X86_SUB_JMP(0x1e2, 0x1f2, x86_l_1f2);
x86_l_1e4:
	/* 0x1e4: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_1ea:
	/* 0x1ea: jmp    1f2 <__do_str+0x199> */
	X86_SIM_X86_SUB_JMP(0x1ea, 0x1f2, x86_l_1f2);
x86_l_1ec:
	/* 0x1ec: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_1f2:
	/* 0x1f2: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1f6:
	/* 0x1f6: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1f9:
	/* 0x1f9: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1fc:
	/* 0x1fc: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_200:
	/* 0x200: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_201:
	/* 0x201: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_203:
	/* 0x203: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_205:
	/* 0x205: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_207:
	/* 0x207: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1cULL: goto x86_l_1c;
	case 0x41ULL: goto x86_l_41;
	case 0x7dULL: goto x86_l_7d;
	case 0xc6ULL: goto x86_l_c6;
	case 0xedULL: goto x86_l_ed;
	case 0x114ULL: goto x86_l_114;
	case 0x158ULL: goto x86_l_158;
	case 0x17fULL: goto x86_l_17f;
	}

}

X86_SIM_LICENSE();
