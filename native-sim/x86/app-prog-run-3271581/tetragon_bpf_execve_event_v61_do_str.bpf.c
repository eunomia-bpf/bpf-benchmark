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
	/* 0x0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2:
	/* 0x2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4:
	/* 0x4: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_5:
	/* 0x5: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_9:
	/* 0x9: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_c:
	/* 0xc: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_12:
	/* 0x12: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_17:
	/* 0x17: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1c:
	/* 0x1c: call   63 <__do_str> */
	X86_SIM_X86_CALL(x86_l_63, 0x21ULL);
x86_l_21:
	/* 0x21: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24:
	/* 0x24: js     55 <do_str+0x55> */
	X86_SIM_X86_JCC(X86_CC_S, 0x24, 0x55, x86_l_55);
x86_l_26:
	/* 0x26: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_2b:
	/* 0x2b: jne    55 <do_str+0x55> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b, 0x55, x86_l_55);
x86_l_2d:
	/* 0x2d: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30:
	/* 0x30: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_35:
	/* 0x35: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_38:
	/* 0x38: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: call   63 <__do_str> */
	X86_SIM_X86_CALL(x86_l_63, 0x46ULL);
x86_l_46:
	/* 0x46: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48:
	/* 0x48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_4f:
	/* 0x4f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_52:
	/* 0x52: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_55:
	/* 0x55: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_59:
	/* 0x59: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_5a:
	/* 0x5a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_5e:
	/* 0x5e: jmp    222 <__do_str+0x1bf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_222:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_63 */
x86_l_63:
	/* 0x63: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_65:
	/* 0x65: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_67:
	/* 0x67: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_69:
	/* 0x69: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_6a:
	/* 0x6a: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_6e:
	/* 0x6e: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_71:
	/* 0x71: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_74:
	/* 0x74: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_77:
	/* 0x77: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b:
	/* 0x7b: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_80:
	/* 0x80: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_85:
	/* 0x85: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_8a:
	/* 0x8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c:
	/* 0x8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f:
	/* 0x8f: js     216 <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x8f, 0x216, x86_l_216);
x86_l_95:
	/* 0x95: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_9b:
	/* 0x9b: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_9f:
	/* 0x9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a2:
	/* 0xa2: je     1be <__do_str+0x15b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa2, 0x1be, x86_l_1be);
x86_l_a8:
	/* 0xa8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ab:
	/* 0xab: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_af:
	/* 0xaf: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_b6:
	/* 0xb6: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ba:
	/* 0xba: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_c2:
	/* 0xc2: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_c9:
	/* 0xc9: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ce:
	/* 0xce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3:
	/* 0xd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5:
	/* 0xd5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8:
	/* 0xd8: je     15a <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd8, 0x15a, x86_l_15a);
x86_l_de:
	/* 0xde: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e2:
	/* 0xe2: je     15a <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xe2, 0x15a, x86_l_15a);
x86_l_e4:
	/* 0xe4: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_eb:
	/* 0xeb: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_f0:
	/* 0xf0: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_f5:
	/* 0xf5: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_fa:
	/* 0xfa: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_fd:
	/* 0xfd: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_100:
	/* 0x100: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_103:
	/* 0x103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105:
	/* 0x105: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_108:
	/* 0x108: jns    210 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x108, 0x210, x86_l_210);
x86_l_10e:
	/* 0x10e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_111:
	/* 0x111: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_119:
	/* 0x119: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_120:
	/* 0x120: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_125:
	/* 0x125: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a:
	/* 0x12a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c:
	/* 0x12c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: je     210 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x12f, 0x210, x86_l_210);
x86_l_135:
	/* 0x135: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_139:
	/* 0x139: jg     1dc <__do_str+0x179> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x139, 0x1dc, x86_l_1dc);
x86_l_13f:
	/* 0x13f: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_143:
	/* 0x143: je     1f6 <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x143, 0x1f6, x86_l_1f6);
x86_l_149:
	/* 0x149: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_14d:
	/* 0x14d: jne    1b0 <__do_str+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x14d, 0x1b0, x86_l_1b0);
x86_l_14f:
	/* 0x14f: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_155:
	/* 0x155: jmp    20c <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x155, 0x20c, x86_l_20c);
x86_l_15a:
	/* 0x15a: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_161:
	/* 0x161: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_163:
	/* 0x163: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_168:
	/* 0x168: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16e:
	/* 0x16e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_170:
	/* 0x170: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172:
	/* 0x172: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_175:
	/* 0x175: jns    210 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x175, 0x210, x86_l_210);
x86_l_17b:
	/* 0x17b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_17e:
	/* 0x17e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_186:
	/* 0x186: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_18d:
	/* 0x18d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192:
	/* 0x192: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_197:
	/* 0x197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199:
	/* 0x199: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c:
	/* 0x19c: je     210 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19c, 0x210, x86_l_210);
x86_l_19e:
	/* 0x19e: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1a2:
	/* 0x1a2: jg     1c2 <__do_str+0x15f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1a2, 0x1c2, x86_l_1c2);
x86_l_1a4:
	/* 0x1a4: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1a8:
	/* 0x1a8: je     1f6 <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a8, 0x1f6, x86_l_1f6);
x86_l_1aa:
	/* 0x1aa: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1ae:
	/* 0x1ae: je     14f <__do_str+0xec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ae, 0x14f, x86_l_14f);
x86_l_1b0:
	/* 0x1b0: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_1b4:
	/* 0x1b4: jne    1ee <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1b4, 0x1ee, x86_l_1ee);
x86_l_1b6:
	/* 0x1b6: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_1bc:
	/* 0x1bc: jmp    20c <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1bc, 0x20c, x86_l_20c);
x86_l_1be:
	/* 0x1be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0:
	/* 0x1c0: jmp    216 <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JMP(0x1c0, 0x216, x86_l_216);
x86_l_1c2:
	/* 0x1c2: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1c6:
	/* 0x1c6: je     1fe <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c6, 0x1fe, x86_l_1fe);
x86_l_1c8:
	/* 0x1c8: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1cc:
	/* 0x1cc: je     206 <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1cc, 0x206, x86_l_206);
x86_l_1ce:
	/* 0x1ce: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1d2:
	/* 0x1d2: jne    1ee <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1d2, 0x1ee, x86_l_1ee);
x86_l_1d4:
	/* 0x1d4: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_1da:
	/* 0x1da: jmp    20c <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1da, 0x20c, x86_l_20c);
x86_l_1dc:
	/* 0x1dc: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1e0:
	/* 0x1e0: je     1fe <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1e0, 0x1fe, x86_l_1fe);
x86_l_1e2:
	/* 0x1e2: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1e6:
	/* 0x1e6: je     206 <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1e6, 0x206, x86_l_206);
x86_l_1e8:
	/* 0x1e8: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1ec:
	/* 0x1ec: je     1d4 <__do_str+0x171> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ec, 0x1d4, x86_l_1d4);
x86_l_1ee:
	/* 0x1ee: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_1f4:
	/* 0x1f4: jmp    20c <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1f4, 0x20c, x86_l_20c);
x86_l_1f6:
	/* 0x1f6: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_1fc:
	/* 0x1fc: jmp    20c <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1fc, 0x20c, x86_l_20c);
x86_l_1fe:
	/* 0x1fe: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_204:
	/* 0x204: jmp    20c <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x204, 0x20c, x86_l_20c);
x86_l_206:
	/* 0x206: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_20c:
	/* 0x20c: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_210:
	/* 0x210: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_213:
	/* 0x213: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_216:
	/* 0x216: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_21a:
	/* 0x21a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_21b:
	/* 0x21b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_21f:
	/* 0x21f: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_221:
	/* 0x221: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x21ULL: goto x86_l_21;
	case 0x46ULL: goto x86_l_46;
	case 0x8cULL: goto x86_l_8c;
	case 0xd5ULL: goto x86_l_d5;
	case 0x105ULL: goto x86_l_105;
	case 0x12cULL: goto x86_l_12c;
	case 0x172ULL: goto x86_l_172;
	case 0x199ULL: goto x86_l_199;
	}

}

X86_SIM_LICENSE();
