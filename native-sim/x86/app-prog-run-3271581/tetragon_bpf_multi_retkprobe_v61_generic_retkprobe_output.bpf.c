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
	/* 0x9: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_c:
	/* 0xc: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14:
	/* 0x14: mov    rdi,QWORD PTR [rip+0x5c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1b:
	/* 0x1b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20:
	/* 0x20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25:
	/* 0x25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27:
	/* 0x27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a:
	/* 0x2a: je     103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a, 0x103, x86_l_103);
x86_l_30:
	/* 0x30: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_38:
	/* 0x38: add    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_3b:
	/* 0x3b: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_40:
	/* 0x40: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_45:
	/* 0x45: mov    r15d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9000ULL);
x86_l_4b:
	/* 0x4b: cmovb  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_4f:
	/* 0x4f: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_57:
	/* 0x57: mov    rdi,QWORD PTR [rip+0x5c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_5e:
	/* 0x5e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_63:
	/* 0x63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68:
	/* 0x68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a:
	/* 0x6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: je     c1 <generic_retkprobe_output+0xc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d, 0xc1, x86_l_c1);
x86_l_6f:
	/* 0x6f: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_73:
	/* 0x73: je     c1 <generic_retkprobe_output+0xc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73, 0xc1, x86_l_c1);
x86_l_75:
	/* 0x75: mov    rsi,QWORD PTR [rip+0x5c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_7c:
	/* 0x7c: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_81:
	/* 0x81: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_86:
	/* 0x86: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_8b:
	/* 0x8b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_8e:
	/* 0x8e: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_91:
	/* 0x91: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_94:
	/* 0x94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96:
	/* 0x96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: js     162 <generic_retkprobe_output+0x162> */
	X86_SIM_X86_JCC(X86_CC_S, 0x99, 0x162, x86_l_162);
x86_l_9f:
	/* 0x9f: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a7:
	/* 0xa7: mov    rdi,QWORD PTR [rip+0x5c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_ae:
	/* 0xae: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b3:
	/* 0xb3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b8:
	/* 0xb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba:
	/* 0xba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: jne    fe <generic_retkprobe_output+0xfe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbd, 0xfe, x86_l_fe);
x86_l_bf:
	/* 0xbf: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0xbf, 0x103, x86_l_103);
x86_l_c1:
	/* 0xc1: mov    rdi,QWORD PTR [rip+0x5c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_c8:
	/* 0xc8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca:
	/* 0xca: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_cf:
	/* 0xcf: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_d2:
	/* 0xd2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7:
	/* 0xd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9:
	/* 0xd9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc:
	/* 0xdc: js     113 <generic_retkprobe_output+0x113> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdc, 0x113, x86_l_113);
x86_l_de:
	/* 0xde: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_e6:
	/* 0xe6: mov    rdi,QWORD PTR [rip+0x5c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_ed:
	/* 0xed: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f2:
	/* 0xf2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f7:
	/* 0xf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9:
	/* 0xf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: je     103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc, 0x103, x86_l_103);
x86_l_fe:
	/* 0xfe: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_103:
	/* 0x103: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_105:
	/* 0x105: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_109:
	/* 0x109: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_10a:
	/* 0x10a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_10e:
	/* 0x10e: jmp    219 <generic_retkprobe_output+0x219> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_113:
	/* 0x113: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_116:
	/* 0x116: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_11e:
	/* 0x11e: mov    rdi,QWORD PTR [rip+0x5bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_125:
	/* 0x125: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12a:
	/* 0x12a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f:
	/* 0x12f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131:
	/* 0x131: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_134:
	/* 0x134: je     103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0x134, 0x103, x86_l_103);
x86_l_136:
	/* 0x136: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_13a:
	/* 0x13a: jg     1aa <generic_retkprobe_output+0x1aa> */
	X86_SIM_X86_JCC(X86_CC_G, 0x13a, 0x1aa, x86_l_1aa);
x86_l_13c:
	/* 0x13c: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_140:
	/* 0x140: je     1ec <generic_retkprobe_output+0x1ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140, 0x1ec, x86_l_1ec);
x86_l_146:
	/* 0x146: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_14a:
	/* 0x14a: je     19b <generic_retkprobe_output+0x19b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a, 0x19b, x86_l_19b);
x86_l_14c:
	/* 0x14c: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_150:
	/* 0x150: jne    1dd <generic_retkprobe_output+0x1dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x150, 0x1dd, x86_l_1dd);
x86_l_156:
	/* 0x156: add    rax,0x2f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 752ULL);
x86_l_15c:
	/* 0x15c: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_160:
	/* 0x160: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x160, 0x103, x86_l_103);
x86_l_162:
	/* 0x162: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_165:
	/* 0x165: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_16d:
	/* 0x16d: mov    rdi,QWORD PTR [rip+0x5bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_174:
	/* 0x174: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_179:
	/* 0x179: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17e:
	/* 0x17e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180:
	/* 0x180: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_183:
	/* 0x183: je     103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0x103, x86_l_103);
x86_l_189:
	/* 0x189: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_18d:
	/* 0x18d: jg     1cb <generic_retkprobe_output+0x1cb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x18d, 0x1cb, x86_l_1cb);
x86_l_18f:
	/* 0x18f: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_193:
	/* 0x193: je     1ec <generic_retkprobe_output+0x1ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x193, 0x1ec, x86_l_1ec);
x86_l_195:
	/* 0x195: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_199:
	/* 0x199: jne    14c <generic_retkprobe_output+0x14c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x199, 0x14c, x86_l_14c);
x86_l_19b:
	/* 0x19b: add    rax,0x2f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 760ULL);
x86_l_1a1:
	/* 0x1a1: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a5:
	/* 0x1a5: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x1a5, 0x103, x86_l_103);
x86_l_1aa:
	/* 0x1aa: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1ae:
	/* 0x1ae: je     1fb <generic_retkprobe_output+0x1fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ae, 0x1fb, x86_l_1fb);
x86_l_1b0:
	/* 0x1b0: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1b4:
	/* 0x1b4: je     20a <generic_retkprobe_output+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4, 0x20a, x86_l_20a);
x86_l_1b6:
	/* 0x1b6: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1ba:
	/* 0x1ba: jne    1dd <generic_retkprobe_output+0x1dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ba, 0x1dd, x86_l_1dd);
x86_l_1bc:
	/* 0x1bc: add    rax,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_1c2:
	/* 0x1c2: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c6:
	/* 0x1c6: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x1c6, 0x103, x86_l_103);
x86_l_1cb:
	/* 0x1cb: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_1cf:
	/* 0x1cf: je     1fb <generic_retkprobe_output+0x1fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cf, 0x1fb, x86_l_1fb);
x86_l_1d1:
	/* 0x1d1: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1d5:
	/* 0x1d5: je     20a <generic_retkprobe_output+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d5, 0x20a, x86_l_20a);
x86_l_1d7:
	/* 0x1d7: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1db:
	/* 0x1db: je     1bc <generic_retkprobe_output+0x1bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1db, 0x1bc, x86_l_1bc);
x86_l_1dd:
	/* 0x1dd: add    rax,0x2d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 728ULL);
x86_l_1e3:
	/* 0x1e3: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e7:
	/* 0x1e7: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x1e7, 0x103, x86_l_103);
x86_l_1ec:
	/* 0x1ec: add    rax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 768ULL);
x86_l_1f2:
	/* 0x1f2: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1f6:
	/* 0x1f6: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x1f6, 0x103, x86_l_103);
x86_l_1fb:
	/* 0x1fb: add    rax,0x308 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 776ULL);
x86_l_201:
	/* 0x201: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_205:
	/* 0x205: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x205, 0x103, x86_l_103);
x86_l_20a:
	/* 0x20a: add    rax,0x2e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 744ULL);
x86_l_210:
	/* 0x210: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_214:
	/* 0x214: jmp    103 <generic_retkprobe_output+0x103> */
	X86_SIM_X86_JMP(0x214, 0x103, x86_l_103);
x86_l_219:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
