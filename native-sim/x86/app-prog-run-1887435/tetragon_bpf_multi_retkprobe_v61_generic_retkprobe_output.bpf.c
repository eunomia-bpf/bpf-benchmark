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
int tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f:
	/* 0xf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14:
	/* 0x14: mov    rdi,QWORD PTR [rip+0x5b5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1b:
	/* 0x1b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0xe5, x86_l_e5);
x86_l_2b:
	/* 0x2b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2e:
	/* 0x2e: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_33:
	/* 0x33: add    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_37:
	/* 0x37: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3c:
	/* 0x3c: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_41:
	/* 0x41: mov    r15d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9000ULL);
x86_l_47:
	/* 0x47: cmovb  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_4b:
	/* 0x4b: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_53:
	/* 0x53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58:
	/* 0x58: mov    rdi,QWORD PTR [rip+0x5b5] */
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
	/* 0x69: je     a5 <generic_retkprobe_output+0xa5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0xa5, x86_l_a5);
x86_l_6b:
	/* 0x6b: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_6f:
	/* 0x6f: je     a5 <generic_retkprobe_output+0xa5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f, 0xa5, x86_l_a5);
x86_l_71:
	/* 0x71: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_76:
	/* 0x76: mov    rsi,QWORD PTR [rip+0x5b5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_7d:
	/* 0x7d: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_82:
	/* 0x82: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
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
	/* 0x90: js     13f <generic_retkprobe_output+0x13f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x90, 0x13f, x86_l_13f);
x86_l_96:
	/* 0x96: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_9e:
	/* 0x9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a3:
	/* 0xa3: jmp    cd <generic_retkprobe_output+0xcd> */
	X86_SIM_X86_JMP(0xa3, 0xcd, x86_l_cd);
x86_l_a5:
	/* 0xa5: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_aa:
	/* 0xaa: mov    rdi,QWORD PTR [rip+0x5b5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_b1:
	/* 0xb1: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_b4:
	/* 0xb4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b7:
	/* 0xb7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9:
	/* 0xb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb:
	/* 0xbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be:
	/* 0xbe: js     f0 <generic_retkprobe_output+0xf0> */
	X86_SIM_X86_JCC(X86_CC_S, 0xbe, 0xf0, x86_l_f0);
x86_l_c0:
	/* 0xc0: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_c8:
	/* 0xc8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd:
	/* 0xcd: mov    rdi,QWORD PTR [rip+0x5b5] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_d4:
	/* 0xd4: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d9:
	/* 0xd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db:
	/* 0xdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: je     e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde, 0xe5, x86_l_e5);
x86_l_e0:
	/* 0xe0: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_e5:
	/* 0xe5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7:
	/* 0xe7: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_eb:
	/* 0xeb: jmp    1f2 <generic_retkprobe_output+0x1f2> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_f0:
	/* 0xf0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_fb:
	/* 0xfb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_100:
	/* 0x100: mov    rdi,QWORD PTR [rip+0x5b6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_107:
	/* 0x107: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10c:
	/* 0x10c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e:
	/* 0x10e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111:
	/* 0x111: je     e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111, 0xe5, x86_l_e5);
x86_l_113:
	/* 0x113: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_117:
	/* 0x117: jg     183 <generic_retkprobe_output+0x183> */
	X86_SIM_X86_JCC(X86_CC_G, 0x117, 0x183, x86_l_183);
x86_l_119:
	/* 0x119: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_11d:
	/* 0x11d: je     1c5 <generic_retkprobe_output+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d, 0x1c5, x86_l_1c5);
x86_l_123:
	/* 0x123: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_127:
	/* 0x127: je     174 <generic_retkprobe_output+0x174> */
	X86_SIM_X86_JCC(X86_CC_E, 0x127, 0x174, x86_l_174);
x86_l_129:
	/* 0x129: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_12d:
	/* 0x12d: jne    1b6 <generic_retkprobe_output+0x1b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12d, 0x1b6, x86_l_1b6);
x86_l_133:
	/* 0x133: add    rax,0x2f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 752ULL);
x86_l_139:
	/* 0x139: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_13d:
	/* 0x13d: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x13d, 0xe5, x86_l_e5);
x86_l_13f:
	/* 0x13f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_142:
	/* 0x142: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_14a:
	/* 0x14a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f:
	/* 0x14f: mov    rdi,QWORD PTR [rip+0x5b6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_156:
	/* 0x156: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15b:
	/* 0x15b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d:
	/* 0x15d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_160:
	/* 0x160: je     e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x160, 0xe5, x86_l_e5);
x86_l_162:
	/* 0x162: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_166:
	/* 0x166: jg     1a4 <generic_retkprobe_output+0x1a4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x166, 0x1a4, x86_l_1a4);
x86_l_168:
	/* 0x168: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_16c:
	/* 0x16c: je     1c5 <generic_retkprobe_output+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16c, 0x1c5, x86_l_1c5);
x86_l_16e:
	/* 0x16e: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_172:
	/* 0x172: jne    129 <generic_retkprobe_output+0x129> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x172, 0x129, x86_l_129);
x86_l_174:
	/* 0x174: add    rax,0x2f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 760ULL);
x86_l_17a:
	/* 0x17a: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17e:
	/* 0x17e: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x17e, 0xe5, x86_l_e5);
x86_l_183:
	/* 0x183: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_187:
	/* 0x187: je     1d4 <generic_retkprobe_output+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x187, 0x1d4, x86_l_1d4);
x86_l_189:
	/* 0x189: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_18d:
	/* 0x18d: je     1e3 <generic_retkprobe_output+0x1e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18d, 0x1e3, x86_l_1e3);
x86_l_18f:
	/* 0x18f: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_193:
	/* 0x193: jne    1b6 <generic_retkprobe_output+0x1b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x193, 0x1b6, x86_l_1b6);
x86_l_195:
	/* 0x195: add    rax,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_19b:
	/* 0x19b: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_19f:
	/* 0x19f: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x19f, 0xe5, x86_l_e5);
x86_l_1a4:
	/* 0x1a4: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1a8:
	/* 0x1a8: je     1d4 <generic_retkprobe_output+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a8, 0x1d4, x86_l_1d4);
x86_l_1aa:
	/* 0x1aa: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1ae:
	/* 0x1ae: je     1e3 <generic_retkprobe_output+0x1e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ae, 0x1e3, x86_l_1e3);
x86_l_1b0:
	/* 0x1b0: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1b4:
	/* 0x1b4: je     195 <generic_retkprobe_output+0x195> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4, 0x195, x86_l_195);
x86_l_1b6:
	/* 0x1b6: add    rax,0x2d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 728ULL);
x86_l_1bc:
	/* 0x1bc: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c0:
	/* 0x1c0: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x1c0, 0xe5, x86_l_e5);
x86_l_1c5:
	/* 0x1c5: add    rax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 768ULL);
x86_l_1cb:
	/* 0x1cb: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1cf:
	/* 0x1cf: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x1cf, 0xe5, x86_l_e5);
x86_l_1d4:
	/* 0x1d4: add    rax,0x308 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 776ULL);
x86_l_1da:
	/* 0x1da: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1de:
	/* 0x1de: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x1de, 0xe5, x86_l_e5);
x86_l_1e3:
	/* 0x1e3: add    rax,0x2e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 744ULL);
x86_l_1e9:
	/* 0x1e9: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ed:
	/* 0x1ed: jmp    e5 <generic_retkprobe_output+0xe5> */
	X86_SIM_X86_JMP(0x1ed, 0xe5, x86_l_e5);
x86_l_1f2:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
