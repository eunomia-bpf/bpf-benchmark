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
	/* 0x54: jmp    218 <__do_str+0x1bf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_218:
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
	/* 0x71: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_76:
	/* 0x76: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_7b:
	/* 0x7b: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_80:
	/* 0x80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82:
	/* 0x82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: js     20c <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x85, 0x20c, x86_l_20c);
x86_l_8b:
	/* 0x8b: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_91:
	/* 0x91: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_95:
	/* 0x95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98:
	/* 0x98: je     1b4 <__do_str+0x15b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x98, 0x1b4, x86_l_1b4);
x86_l_9e:
	/* 0x9e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_a1:
	/* 0xa1: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_a5:
	/* 0xa5: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_ac:
	/* 0xac: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b0:
	/* 0xb0: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_b8:
	/* 0xb8: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_bf:
	/* 0xbf: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c4:
	/* 0xc4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c9:
	/* 0xc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb:
	/* 0xcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: je     150 <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xce, 0x150, x86_l_150);
x86_l_d4:
	/* 0xd4: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d8:
	/* 0xd8: je     150 <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd8, 0x150, x86_l_150);
x86_l_da:
	/* 0xda: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_e1:
	/* 0xe1: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_e6:
	/* 0xe6: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_eb:
	/* 0xeb: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_f0:
	/* 0xf0: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_f6:
	/* 0xf6: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb:
	/* 0xfb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: jns    206 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0xfe, 0x206, x86_l_206);
x86_l_104:
	/* 0x104: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_107:
	/* 0x107: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_10f:
	/* 0x10f: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_116:
	/* 0x116: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11b:
	/* 0x11b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_120:
	/* 0x120: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122:
	/* 0x122: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_125:
	/* 0x125: je     206 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x125, 0x206, x86_l_206);
x86_l_12b:
	/* 0x12b: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_12f:
	/* 0x12f: jg     1d2 <__do_str+0x179> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x12f, 0x1d2, x86_l_1d2);
x86_l_135:
	/* 0x135: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_139:
	/* 0x139: je     1ec <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x139, 0x1ec, x86_l_1ec);
x86_l_13f:
	/* 0x13f: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_143:
	/* 0x143: jne    1a6 <__do_str+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x143, 0x1a6, x86_l_1a6);
x86_l_145:
	/* 0x145: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_14b:
	/* 0x14b: jmp    202 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x14b, 0x202, x86_l_202);
x86_l_150:
	/* 0x150: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_157:
	/* 0x157: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159:
	/* 0x159: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_15e:
	/* 0x15e: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_161:
	/* 0x161: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_164:
	/* 0x164: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166:
	/* 0x166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168:
	/* 0x168: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: jns    206 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x16b, 0x206, x86_l_206);
x86_l_171:
	/* 0x171: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_174:
	/* 0x174: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17c:
	/* 0x17c: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_183:
	/* 0x183: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188:
	/* 0x188: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18d:
	/* 0x18d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f:
	/* 0x18f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: je     206 <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x192, 0x206, x86_l_206);
x86_l_194:
	/* 0x194: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_198:
	/* 0x198: jg     1b8 <__do_str+0x15f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x198, 0x1b8, x86_l_1b8);
x86_l_19a:
	/* 0x19a: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_19e:
	/* 0x19e: je     1ec <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19e, 0x1ec, x86_l_1ec);
x86_l_1a0:
	/* 0x1a0: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1a4:
	/* 0x1a4: je     145 <__do_str+0xec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1a4, 0x145, x86_l_145);
x86_l_1a6:
	/* 0x1a6: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_1aa:
	/* 0x1aa: jne    1e4 <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1aa, 0x1e4, x86_l_1e4);
x86_l_1ac:
	/* 0x1ac: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_1b2:
	/* 0x1b2: jmp    202 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1b2, 0x202, x86_l_202);
x86_l_1b4:
	/* 0x1b4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6:
	/* 0x1b6: jmp    20c <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JMP(0x1b6, 0x20c, x86_l_20c);
x86_l_1b8:
	/* 0x1b8: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1bc:
	/* 0x1bc: je     1f4 <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1bc, 0x1f4, x86_l_1f4);
x86_l_1be:
	/* 0x1be: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1c2:
	/* 0x1c2: je     1fc <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c2, 0x1fc, x86_l_1fc);
x86_l_1c4:
	/* 0x1c4: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1c8:
	/* 0x1c8: jne    1e4 <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1c8, 0x1e4, x86_l_1e4);
x86_l_1ca:
	/* 0x1ca: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_1d0:
	/* 0x1d0: jmp    202 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1d0, 0x202, x86_l_202);
x86_l_1d2:
	/* 0x1d2: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1d6:
	/* 0x1d6: je     1f4 <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1d6, 0x1f4, x86_l_1f4);
x86_l_1d8:
	/* 0x1d8: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1dc:
	/* 0x1dc: je     1fc <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1dc, 0x1fc, x86_l_1fc);
x86_l_1de:
	/* 0x1de: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1e2:
	/* 0x1e2: je     1ca <__do_str+0x171> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1e2, 0x1ca, x86_l_1ca);
x86_l_1e4:
	/* 0x1e4: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_1ea:
	/* 0x1ea: jmp    202 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1ea, 0x202, x86_l_202);
x86_l_1ec:
	/* 0x1ec: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_1f2:
	/* 0x1f2: jmp    202 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1f2, 0x202, x86_l_202);
x86_l_1f4:
	/* 0x1f4: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_1fa:
	/* 0x1fa: jmp    202 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x1fa, 0x202, x86_l_202);
x86_l_1fc:
	/* 0x1fc: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_202:
	/* 0x202: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_206:
	/* 0x206: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_209:
	/* 0x209: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_20c:
	/* 0x20c: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_210:
	/* 0x210: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_211:
	/* 0x211: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_213:
	/* 0x213: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_215:
	/* 0x215: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_217:
	/* 0x217: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1cULL: goto x86_l_1c;
	case 0x41ULL: goto x86_l_41;
	case 0x82ULL: goto x86_l_82;
	case 0xcbULL: goto x86_l_cb;
	case 0xfbULL: goto x86_l_fb;
	case 0x122ULL: goto x86_l_122;
	case 0x168ULL: goto x86_l_168;
	case 0x18fULL: goto x86_l_18f;
	}

}

X86_SIM_LICENSE();
