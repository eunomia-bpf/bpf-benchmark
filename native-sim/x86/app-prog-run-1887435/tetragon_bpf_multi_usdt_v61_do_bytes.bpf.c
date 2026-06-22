extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_usdt_v61_do_bytes_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_4:
	/* 0x4: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_10:
	/* 0x10: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x15ULL);
x86_l_15:
	/* 0x15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17:
	/* 0x17: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17, 0x1c0, x86_l_1c0);
x86_l_1d:
	/* 0x1d: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_20:
	/* 0x20: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_27:
	/* 0x27: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2a:
	/* 0x2a: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d:
	/* 0x2d: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d, 0x247, x86_l_247);
x86_l_33:
	/* 0x33: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37:
	/* 0x37: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x42ULL);
x86_l_42:
	/* 0x42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44:
	/* 0x44: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x44, 0x1c0, x86_l_1c0);
x86_l_4a:
	/* 0x4a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_4f:
	/* 0x4f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_52:
	/* 0x52: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_55:
	/* 0x55: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_58:
	/* 0x58: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5b:
	/* 0x5b: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b, 0x247, x86_l_247);
x86_l_61:
	/* 0x61: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_65:
	/* 0x65: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_68:
	/* 0x68: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x70ULL);
x86_l_70:
	/* 0x70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_72:
	/* 0x72: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x72, 0x1c0, x86_l_1c0);
x86_l_78:
	/* 0x78: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_7d:
	/* 0x7d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_80:
	/* 0x80: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_83:
	/* 0x83: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_86:
	/* 0x86: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_89:
	/* 0x89: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89, 0x247, x86_l_247);
x86_l_8f:
	/* 0x8f: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_93:
	/* 0x93: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_96:
	/* 0x96: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_99:
	/* 0x99: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x9eULL);
x86_l_9e:
	/* 0x9e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a0:
	/* 0xa0: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa0, 0x1c0, x86_l_1c0);
x86_l_a6:
	/* 0xa6: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_ab:
	/* 0xab: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ae:
	/* 0xae: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b1:
	/* 0xb1: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_b4:
	/* 0xb4: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b7:
	/* 0xb7: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7, 0x247, x86_l_247);
x86_l_bd:
	/* 0xbd: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c1:
	/* 0xc1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_c7:
	/* 0xc7: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0xccULL);
x86_l_cc:
	/* 0xcc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ce:
	/* 0xce: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0xce, 0x1c0, x86_l_1c0);
x86_l_d4:
	/* 0xd4: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_d9:
	/* 0xd9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_dc:
	/* 0xdc: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_df:
	/* 0xdf: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_e2:
	/* 0xe2: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_e5:
	/* 0xe5: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe5, 0x247, x86_l_247);
x86_l_eb:
	/* 0xeb: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_ef:
	/* 0xef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_f5:
	/* 0xf5: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0xfaULL);
x86_l_fa:
	/* 0xfa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc:
	/* 0xfc: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0xfc, 0x1c0, x86_l_1c0);
x86_l_102:
	/* 0x102: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_107:
	/* 0x107: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_10a:
	/* 0x10a: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10d:
	/* 0x10d: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_110:
	/* 0x110: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_113:
	/* 0x113: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x113, 0x247, x86_l_247);
x86_l_119:
	/* 0x119: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_11d:
	/* 0x11d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_120:
	/* 0x120: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_123:
	/* 0x123: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x128ULL);
x86_l_128:
	/* 0x128: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12a:
	/* 0x12a: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12a, 0x1c0, x86_l_1c0);
x86_l_130:
	/* 0x130: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_135:
	/* 0x135: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13b:
	/* 0x13b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_13e:
	/* 0x13e: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_141:
	/* 0x141: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x141, 0x247, x86_l_247);
x86_l_147:
	/* 0x147: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_14b:
	/* 0x14b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_151:
	/* 0x151: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x156ULL);
x86_l_156:
	/* 0x156: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_158:
	/* 0x158: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x158, 0x1c0, x86_l_1c0);
x86_l_15a:
	/* 0x15a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_15f:
	/* 0x15f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_162:
	/* 0x162: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_165:
	/* 0x165: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_168:
	/* 0x168: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_16b:
	/* 0x16b: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16b, 0x247, x86_l_247);
x86_l_171:
	/* 0x171: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_175:
	/* 0x175: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_178:
	/* 0x178: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_17b:
	/* 0x17b: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x180ULL);
x86_l_180:
	/* 0x180: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_182:
	/* 0x182: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x182, 0x1c0, x86_l_1c0);
x86_l_184:
	/* 0x184: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_189:
	/* 0x189: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18f:
	/* 0x18f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_195:
	/* 0x195: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x195, 0x247, x86_l_247);
x86_l_19b:
	/* 0x19b: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19e:
	/* 0x19e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a1:
	/* 0x1a1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1a4:
	/* 0x1a4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a7:
	/* 0x1a7: call   256 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_256, 0x1acULL);
x86_l_1ac:
	/* 0x1ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ae:
	/* 0x1ae: js     1c0 <do_bytes+0x1c0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1ae, 0x1c0, x86_l_1c0);
x86_l_1b0:
	/* 0x1b0: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1b5:
	/* 0x1b5: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b8:
	/* 0x1b8: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1bb:
	/* 0x1bb: jmp    247 <do_bytes+0x247> */
	X86_SIM_X86_JMP(0x1bb, 0x247, x86_l_247);
x86_l_1c0:
	/* 0x1c0: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1c3:
	/* 0x1c3: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1cb:
	/* 0x1cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d0:
	/* 0x1d0: mov    rdi,QWORD PTR [rip+0x307] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_1d7:
	/* 0x1d7: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dc:
	/* 0x1dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de:
	/* 0x1de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e1:
	/* 0x1e1: je     247 <do_bytes+0x247> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1, 0x247, x86_l_247);
x86_l_1e3:
	/* 0x1e3: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1e7:
	/* 0x1e7: jg     203 <do_bytes+0x203> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1e7, 0x203, x86_l_203);
x86_l_1e9:
	/* 0x1e9: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1ed:
	/* 0x1ed: je     21d <do_bytes+0x21d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ed, 0x21d, x86_l_21d);
x86_l_1ef:
	/* 0x1ef: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1f3:
	/* 0x1f3: je     235 <do_bytes+0x235> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f3, 0x235, x86_l_235);
x86_l_1f5:
	/* 0x1f5: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_1f9:
	/* 0x1f9: jne    22d <do_bytes+0x22d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f9, 0x22d, x86_l_22d);
x86_l_1fb:
	/* 0x1fb: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_201:
	/* 0x201: jmp    243 <do_bytes+0x243> */
	X86_SIM_X86_JMP(0x201, 0x243, x86_l_243);
x86_l_203:
	/* 0x203: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_207:
	/* 0x207: je     225 <do_bytes+0x225> */
	X86_SIM_X86_JCC(X86_CC_E, 0x207, 0x225, x86_l_225);
x86_l_209:
	/* 0x209: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_20d:
	/* 0x20d: je     23d <do_bytes+0x23d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20d, 0x23d, x86_l_23d);
x86_l_20f:
	/* 0x20f: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_213:
	/* 0x213: jne    22d <do_bytes+0x22d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x213, 0x22d, x86_l_22d);
x86_l_215:
	/* 0x215: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_21b:
	/* 0x21b: jmp    243 <do_bytes+0x243> */
	X86_SIM_X86_JMP(0x21b, 0x243, x86_l_243);
x86_l_21d:
	/* 0x21d: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_223:
	/* 0x223: jmp    243 <do_bytes+0x243> */
	X86_SIM_X86_JMP(0x223, 0x243, x86_l_243);
x86_l_225:
	/* 0x225: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_22b:
	/* 0x22b: jmp    243 <do_bytes+0x243> */
	X86_SIM_X86_JMP(0x22b, 0x243, x86_l_243);
x86_l_22d:
	/* 0x22d: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_233:
	/* 0x233: jmp    243 <do_bytes+0x243> */
	X86_SIM_X86_JMP(0x233, 0x243, x86_l_243);
x86_l_235:
	/* 0x235: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_23b:
	/* 0x23b: jmp    243 <do_bytes+0x243> */
	X86_SIM_X86_JMP(0x23b, 0x243, x86_l_243);
x86_l_23d:
	/* 0x23d: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_243:
	/* 0x243: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_247:
	/* 0x247: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24e:
	/* 0x24e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_250:
	/* 0x250: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_251:
	/* 0x251: jmp    30f <__do_bytes+0xb9> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_30f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_256 */
x86_l_256:
	/* 0x256: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_258:
	/* 0x258: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_25a:
	/* 0x25a: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_25c:
	/* 0x25c: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_25d:
	/* 0x25d: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_25e:
	/* 0x25e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_261:
	/* 0x261: js     2da <__do_bytes+0x84> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x261, 0x2da, x86_l_2da);
x86_l_263:
	/* 0x263: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_266:
	/* 0x266: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_269:
	/* 0x269: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_270:
	/* 0x270: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_275:
	/* 0x275: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_279:
	/* 0x279: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27d:
	/* 0x27d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_282:
	/* 0x282: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_284:
	/* 0x284: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286:
	/* 0x286: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_288:
	/* 0x288: js     2fd <__do_bytes+0xa7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x288, 0x2fd, x86_l_2fd);
x86_l_28a:
	/* 0x28a: lea    r12d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28e:
	/* 0x28e: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_292:
	/* 0x292: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_29a:
	/* 0x29a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29f:
	/* 0x29f: mov    rdi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_2a6:
	/* 0x2a6: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ab:
	/* 0x2ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad:
	/* 0x2ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: je     2e3 <__do_bytes+0x8d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2b0, 0x2e3, x86_l_2e3);
x86_l_2b2:
	/* 0x2b2: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2b6:
	/* 0x2b6: je     2e3 <__do_bytes+0x8d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2b6, 0x2e3, x86_l_2e3);
x86_l_2b8:
	/* 0x2b8: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2bd:
	/* 0x2bd: mov    rsi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_2c4:
	/* 0x2c4: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2c9:
	/* 0x2c9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_2d2:
	/* 0x2d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4:
	/* 0x2d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d6:
	/* 0x2d6: js     2fd <__do_bytes+0xa7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x2d6, 0x2fd, x86_l_2fd);
x86_l_2d8:
	/* 0x2d8: jmp    300 <__do_bytes+0xaa> */
	X86_SIM_X86_SUB_JMP(0x2d8, 0x300, x86_l_300);
x86_l_2da:
	/* 0x2da: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2e1:
	/* 0x2e1: jmp    300 <__do_bytes+0xaa> */
	X86_SIM_X86_SUB_JMP(0x2e1, 0x300, x86_l_300);
x86_l_2e3:
	/* 0x2e3: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2e8:
	/* 0x2e8: mov    rdi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2ef:
	/* 0x2ef: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2f2:
	/* 0x2f2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f5:
	/* 0x2f5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f7:
	/* 0x2f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9:
	/* 0x2f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fb:
	/* 0x2fb: jns    300 <__do_bytes+0xaa> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x2fb, 0x300, x86_l_300);
x86_l_2fd:
	/* 0x2fd: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_300:
	/* 0x300: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_307:
	/* 0x307: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_308:
	/* 0x308: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_30a:
	/* 0x30a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_30c:
	/* 0x30c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_30e:
	/* 0x30e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x15ULL: goto x86_l_15;
	case 0x42ULL: goto x86_l_42;
	case 0x70ULL: goto x86_l_70;
	case 0x9eULL: goto x86_l_9e;
	case 0xccULL: goto x86_l_cc;
	case 0xfaULL: goto x86_l_fa;
	case 0x128ULL: goto x86_l_128;
	case 0x156ULL: goto x86_l_156;
	case 0x180ULL: goto x86_l_180;
	case 0x1acULL: goto x86_l_1ac;
	case 0x1deULL: goto x86_l_1de;
	case 0x286ULL: goto x86_l_286;
	case 0x2adULL: goto x86_l_2ad;
	case 0x2d4ULL: goto x86_l_2d4;
	case 0x2f9ULL: goto x86_l_2f9;
	}

}

X86_SIM_LICENSE();
