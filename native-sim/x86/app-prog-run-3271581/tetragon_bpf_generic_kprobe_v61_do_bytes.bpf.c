extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_kprobe_v61_do_bytes_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_b:
	/* 0xb: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_e:
	/* 0xe: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_17:
	/* 0x17: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x1cULL);
x86_l_1c:
	/* 0x1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e:
	/* 0x1e: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1e, 0x1c7, x86_l_1c7);
x86_l_24:
	/* 0x24: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_27:
	/* 0x27: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2e:
	/* 0x2e: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34:
	/* 0x34: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34, 0x24e, x86_l_24e);
x86_l_3a:
	/* 0x3a: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3e:
	/* 0x3e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_44:
	/* 0x44: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x49ULL);
x86_l_49:
	/* 0x49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b:
	/* 0x4b: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4b, 0x1c7, x86_l_1c7);
x86_l_51:
	/* 0x51: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_56:
	/* 0x56: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5c:
	/* 0x5c: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_62:
	/* 0x62: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x62, 0x24e, x86_l_24e);
x86_l_68:
	/* 0x68: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_6c:
	/* 0x6c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_72:
	/* 0x72: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x77ULL);
x86_l_77:
	/* 0x77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_79:
	/* 0x79: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x79, 0x1c7, x86_l_1c7);
x86_l_7f:
	/* 0x7f: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_84:
	/* 0x84: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_87:
	/* 0x87: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8a:
	/* 0x8a: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_90:
	/* 0x90: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90, 0x24e, x86_l_24e);
x86_l_96:
	/* 0x96: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_9a:
	/* 0x9a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0xa5ULL);
x86_l_a5:
	/* 0xa5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a7:
	/* 0xa7: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa7, 0x1c7, x86_l_1c7);
x86_l_ad:
	/* 0xad: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_b2:
	/* 0xb2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_b5:
	/* 0xb5: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b8:
	/* 0xb8: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_bb:
	/* 0xbb: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_be:
	/* 0xbe: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe, 0x24e, x86_l_24e);
x86_l_c4:
	/* 0xc4: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c8:
	/* 0xc8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cb:
	/* 0xcb: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0xd3ULL);
x86_l_d3:
	/* 0xd3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d5:
	/* 0xd5: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd5, 0x1c7, x86_l_1c7);
x86_l_db:
	/* 0xdb: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_e0:
	/* 0xe0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e3:
	/* 0xe3: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e6:
	/* 0xe6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_e9:
	/* 0xe9: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_ec:
	/* 0xec: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec, 0x24e, x86_l_24e);
x86_l_f2:
	/* 0xf2: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_f6:
	/* 0xf6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x101ULL);
x86_l_101:
	/* 0x101: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_103:
	/* 0x103: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x103, 0x1c7, x86_l_1c7);
x86_l_109:
	/* 0x109: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_10e:
	/* 0x10e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_111:
	/* 0x111: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_114:
	/* 0x114: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_117:
	/* 0x117: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_11a:
	/* 0x11a: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a, 0x24e, x86_l_24e);
x86_l_120:
	/* 0x120: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_124:
	/* 0x124: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_127:
	/* 0x127: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x12fULL);
x86_l_12f:
	/* 0x12f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_131:
	/* 0x131: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x131, 0x1c7, x86_l_1c7);
x86_l_137:
	/* 0x137: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_13c:
	/* 0x13c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_13f:
	/* 0x13f: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_142:
	/* 0x142: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_145:
	/* 0x145: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_148:
	/* 0x148: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x148, 0x24e, x86_l_24e);
x86_l_14e:
	/* 0x14e: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_152:
	/* 0x152: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_155:
	/* 0x155: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_158:
	/* 0x158: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x15dULL);
x86_l_15d:
	/* 0x15d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15f:
	/* 0x15f: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15f, 0x1c7, x86_l_1c7);
x86_l_161:
	/* 0x161: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_166:
	/* 0x166: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_169:
	/* 0x169: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16c:
	/* 0x16c: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_16f:
	/* 0x16f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_172:
	/* 0x172: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172, 0x24e, x86_l_24e);
x86_l_178:
	/* 0x178: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_17c:
	/* 0x17c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_17f:
	/* 0x17f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_182:
	/* 0x182: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x187ULL);
x86_l_187:
	/* 0x187: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_189:
	/* 0x189: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x189, 0x1c7, x86_l_1c7);
x86_l_18b:
	/* 0x18b: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_190:
	/* 0x190: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_193:
	/* 0x193: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_196:
	/* 0x196: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_199:
	/* 0x199: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_19c:
	/* 0x19c: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19c, 0x24e, x86_l_24e);
x86_l_1a2:
	/* 0x1a2: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a5:
	/* 0x1a5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a8:
	/* 0x1a8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1ab:
	/* 0x1ab: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: call   264 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_264, 0x1b3ULL);
x86_l_1b3:
	/* 0x1b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b5:
	/* 0x1b5: js     1c7 <do_bytes+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1b5, 0x1c7, x86_l_1c7);
x86_l_1b7:
	/* 0x1b7: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1bc:
	/* 0x1bc: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1bf:
	/* 0x1bf: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c2:
	/* 0x1c2: jmp    24e <do_bytes+0x24e> */
	X86_SIM_X86_JMP(0x1c2, 0x24e, x86_l_24e);
x86_l_1c7:
	/* 0x1c7: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1ca:
	/* 0x1ca: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1d2:
	/* 0x1d2: mov    rdi,QWORD PTR [rip+0x440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_1d9:
	/* 0x1d9: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1de:
	/* 0x1de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e3:
	/* 0x1e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5:
	/* 0x1e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: je     24e <do_bytes+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e8, 0x24e, x86_l_24e);
x86_l_1ea:
	/* 0x1ea: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1ee:
	/* 0x1ee: jg     20a <do_bytes+0x20a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1ee, 0x20a, x86_l_20a);
x86_l_1f0:
	/* 0x1f0: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1f4:
	/* 0x1f4: je     224 <do_bytes+0x224> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f4, 0x224, x86_l_224);
x86_l_1f6:
	/* 0x1f6: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1fa:
	/* 0x1fa: je     23c <do_bytes+0x23c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fa, 0x23c, x86_l_23c);
x86_l_1fc:
	/* 0x1fc: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_200:
	/* 0x200: jne    234 <do_bytes+0x234> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x200, 0x234, x86_l_234);
x86_l_202:
	/* 0x202: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_208:
	/* 0x208: jmp    24a <do_bytes+0x24a> */
	X86_SIM_X86_JMP(0x208, 0x24a, x86_l_24a);
x86_l_20a:
	/* 0x20a: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_20e:
	/* 0x20e: je     22c <do_bytes+0x22c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20e, 0x22c, x86_l_22c);
x86_l_210:
	/* 0x210: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_214:
	/* 0x214: je     244 <do_bytes+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0x214, 0x244, x86_l_244);
x86_l_216:
	/* 0x216: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_21a:
	/* 0x21a: jne    234 <do_bytes+0x234> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21a, 0x234, x86_l_234);
x86_l_21c:
	/* 0x21c: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_222:
	/* 0x222: jmp    24a <do_bytes+0x24a> */
	X86_SIM_X86_JMP(0x222, 0x24a, x86_l_24a);
x86_l_224:
	/* 0x224: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_22a:
	/* 0x22a: jmp    24a <do_bytes+0x24a> */
	X86_SIM_X86_JMP(0x22a, 0x24a, x86_l_24a);
x86_l_22c:
	/* 0x22c: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_232:
	/* 0x232: jmp    24a <do_bytes+0x24a> */
	X86_SIM_X86_JMP(0x232, 0x24a, x86_l_24a);
x86_l_234:
	/* 0x234: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_23a:
	/* 0x23a: jmp    24a <do_bytes+0x24a> */
	X86_SIM_X86_JMP(0x23a, 0x24a, x86_l_24a);
x86_l_23c:
	/* 0x23c: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_242:
	/* 0x242: jmp    24a <do_bytes+0x24a> */
	X86_SIM_X86_JMP(0x242, 0x24a, x86_l_24a);
x86_l_244:
	/* 0x244: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_24a:
	/* 0x24a: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24e:
	/* 0x24e: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_251:
	/* 0x251: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_255:
	/* 0x255: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_256:
	/* 0x256: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_258:
	/* 0x258: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_25a:
	/* 0x25a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_25c:
	/* 0x25c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: jmp    328 <__do_bytes+0xc4> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_328:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_264 */
x86_l_264:
	/* 0x264: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_266:
	/* 0x266: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_268:
	/* 0x268: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_26a:
	/* 0x26a: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_26b:
	/* 0x26b: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_26c:
	/* 0x26c: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_26f:
	/* 0x26f: js     2f1 <__do_bytes+0x8d> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x26f, 0x2f1, x86_l_2f1);
x86_l_275:
	/* 0x275: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_278:
	/* 0x278: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_27b:
	/* 0x27b: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_282:
	/* 0x282: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_287:
	/* 0x287: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_28b:
	/* 0x28b: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f:
	/* 0x28f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_294:
	/* 0x294: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_296:
	/* 0x296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298:
	/* 0x298: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29a:
	/* 0x29a: js     316 <__do_bytes+0xb2> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x29a, 0x316, x86_l_316);
x86_l_29c:
	/* 0x29c: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a0:
	/* 0x2a0: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a4:
	/* 0x2a4: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2ac:
	/* 0x2ac: mov    rdi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_2b3:
	/* 0x2b3: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b8:
	/* 0x2b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd:
	/* 0x2bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf:
	/* 0x2bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c2:
	/* 0x2c2: je     2fa <__do_bytes+0x96> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c2, 0x2fa, x86_l_2fa);
x86_l_2c4:
	/* 0x2c4: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2c8:
	/* 0x2c8: je     2fa <__do_bytes+0x96> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c8, 0x2fa, x86_l_2fa);
x86_l_2ca:
	/* 0x2ca: mov    rsi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_2d1:
	/* 0x2d1: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d6:
	/* 0x2d6: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2db:
	/* 0x2db: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2de:
	/* 0x2de: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e3:
	/* 0x2e3: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2e6:
	/* 0x2e6: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_2e9:
	/* 0x2e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb:
	/* 0x2eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ed:
	/* 0x2ed: js     316 <__do_bytes+0xb2> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x2ed, 0x316, x86_l_316);
x86_l_2ef:
	/* 0x2ef: jmp    319 <__do_bytes+0xb5> */
	X86_SIM_X86_SUB_JMP(0x2ef, 0x319, x86_l_319);
x86_l_2f1:
	/* 0x2f1: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2f8:
	/* 0x2f8: jmp    319 <__do_bytes+0xb5> */
	X86_SIM_X86_SUB_JMP(0x2f8, 0x319, x86_l_319);
x86_l_2fa:
	/* 0x2fa: mov    rdi,QWORD PTR [rip+0x69c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_301:
	/* 0x301: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_303:
	/* 0x303: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_308:
	/* 0x308: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_30b:
	/* 0x30b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30e:
	/* 0x30e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_310:
	/* 0x310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312:
	/* 0x312: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_314:
	/* 0x314: jns    319 <__do_bytes+0xb5> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x314, 0x319, x86_l_319);
x86_l_316:
	/* 0x316: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_319:
	/* 0x319: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_31c:
	/* 0x31c: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_320:
	/* 0x320: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_321:
	/* 0x321: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_323:
	/* 0x323: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_325:
	/* 0x325: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_327:
	/* 0x327: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x1cULL: goto x86_l_1c;
	case 0x49ULL: goto x86_l_49;
	case 0x77ULL: goto x86_l_77;
	case 0xa5ULL: goto x86_l_a5;
	case 0xd3ULL: goto x86_l_d3;
	case 0x101ULL: goto x86_l_101;
	case 0x12fULL: goto x86_l_12f;
	case 0x15dULL: goto x86_l_15d;
	case 0x187ULL: goto x86_l_187;
	case 0x1b3ULL: goto x86_l_1b3;
	case 0x1e5ULL: goto x86_l_1e5;
	case 0x298ULL: goto x86_l_298;
	case 0x2bfULL: goto x86_l_2bf;
	case 0x2ebULL: goto x86_l_2eb;
	case 0x312ULL: goto x86_l_312;
	}

}

X86_SIM_LICENSE();
