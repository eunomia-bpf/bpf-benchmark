extern char cgroup_rate_map;
extern char cgroup_rate_options_map;
extern char execve_calls;
extern char execve_msg_heap_map;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
extern char throttle_heap_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_event_v511_execve_rate_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_12:
	/* 0x12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     393 <execve_rate+0x393> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x393, x86_l_393);
x86_l_2e:
	/* 0x2e: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32:
	/* 0x32: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_35:
	/* 0x35: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39:
	/* 0x39: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e:
	/* 0x3e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_46:
	/* 0x46: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_options_map)));
x86_l_4d:
	/* 0x4d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52:
	/* 0x52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57:
	/* 0x57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59:
	/* 0x59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: je     378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x378, x86_l_378);
x86_l_62:
	/* 0x62: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66:
	/* 0x66: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_69:
	/* 0x69: je     378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x378, x86_l_378);
x86_l_6f:
	/* 0x6f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_72:
	/* 0x72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_79:
	/* 0x79: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7e:
	/* 0x7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83:
	/* 0x83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85:
	/* 0x85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_88:
	/* 0x88: je     c2 <execve_rate+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88, 0xc2, x86_l_c2);
x86_l_8a:
	/* 0x8a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: mov    rsi,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91:
	/* 0x91: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_94:
	/* 0x94: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_97:
	/* 0x97: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: jbe    ea <execve_rate+0xea> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x9a, 0xea, x86_l_ea);
x86_l_9c:
	/* 0x9c: lea    rcx,[r12+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_a0:
	/* 0xa0: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a3:
	/* 0xa3: jbe    f3 <execve_rate+0xf3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa3, 0xf3, x86_l_f3);
x86_l_a5:
	/* 0xa5: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_a8:
	/* 0xa8: or     rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_ab:
	/* 0xab: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_af:
	/* 0xaf: je     13e <execve_rate+0x13e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf, 0x13e, x86_l_13e);
x86_l_b5:
	/* 0xb5: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_b8:
	/* 0xb8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba:
	/* 0xba: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_bd:
	/* 0xbd: jmp    146 <execve_rate+0x146> */
	X86_SIM_X86_JMP(0xbd, 0x146, x86_l_146);
x86_l_c2:
	/* 0xc2: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_cb:
	/* 0xcb: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d4:
	/* 0xd4: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_d7:
	/* 0xd7: or     rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_da:
	/* 0xda: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_de:
	/* 0xde: je     fb <execve_rate+0xfb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde, 0xfb, x86_l_fb);
x86_l_e0:
	/* 0xe0: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_e3:
	/* 0xe3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5:
	/* 0xe5: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_e8:
	/* 0xe8: jmp    103 <execve_rate+0x103> */
	X86_SIM_X86_JMP(0xe8, 0x103, x86_l_103);
x86_l_ea:
	/* 0xea: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed:
	/* 0xed: mov    rdx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1:
	/* 0xf1: jmp    158 <execve_rate+0x158> */
	X86_SIM_X86_JMP(0xf1, 0x158, x86_l_158);
x86_l_f3:
	/* 0xf3: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6:
	/* 0xf6: add    rsi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f9:
	/* 0xf9: jmp    14e <execve_rate+0x14e> */
	X86_SIM_X86_JMP(0xf9, 0x14e, x86_l_14e);
x86_l_fb:
	/* 0xfb: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_fe:
	/* 0xfe: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100:
	/* 0x100: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_103:
	/* 0x103: sub    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_106:
	/* 0x106: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10b:
	/* 0x10b: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_114:
	/* 0x114: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_11d:
	/* 0x11d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_124:
	/* 0x124: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_126:
	/* 0x126: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b:
	/* 0x12b: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130:
	/* 0x130: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_135:
	/* 0x135: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137:
	/* 0x137: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139:
	/* 0x139: jmp    378 <execve_rate+0x378> */
	X86_SIM_X86_JMP(0x139, 0x378, x86_l_378);
x86_l_13e:
	/* 0x13e: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_141:
	/* 0x141: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143:
	/* 0x143: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_146:
	/* 0x146: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_149:
	/* 0x149: sub    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_14c:
	/* 0x14c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e:
	/* 0x14e: mov    QWORD PTR [r14+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_152:
	/* 0x152: mov    QWORD PTR [r14+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_156:
	/* 0x156: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_158:
	/* 0x158: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15b:
	/* 0x15b: mov    QWORD PTR [r14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e:
	/* 0x15e: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_161:
	/* 0x161: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_164:
	/* 0x164: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_167:
	/* 0x167: imul   rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_16b:
	/* 0x16b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_16e:
	/* 0x16e: or     rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_171:
	/* 0x171: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_175:
	/* 0x175: je     190 <execve_rate+0x190> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175, 0x190, x86_l_190);
x86_l_177:
	/* 0x177: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_179:
	/* 0x179: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_17c:
	/* 0x17c: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17f:
	/* 0x17f: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_183:
	/* 0x183: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_188:
	/* 0x188: jne    393 <execve_rate+0x393> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x188, 0x393, x86_l_393);
x86_l_18e:
	/* 0x18e: jmp    1a7 <execve_rate+0x1a7> */
	X86_SIM_X86_JMP(0x18e, 0x1a7, x86_l_1a7);
x86_l_190:
	/* 0x190: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_192:
	/* 0x192: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_195:
	/* 0x195: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_198:
	/* 0x198: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19c:
	/* 0x19c: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a1:
	/* 0x1a1: jne    393 <execve_rate+0x393> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a1, 0x393, x86_l_393);
x86_l_1a7:
	/* 0x1a7: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1ab:
	/* 0x1ab: jb     378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ab, 0x378, x86_l_378);
x86_l_1b1:
	/* 0x1b1: mov    QWORD PTR [r14+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b5:
	/* 0x1b5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bd:
	/* 0x1bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&throttle_heap_map)));
x86_l_1c4:
	/* 0x1c4: lea    rcx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c9:
	/* 0x1c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ce:
	/* 0x1ce: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1d6:
	/* 0x1d6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1db:
	/* 0x1db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd:
	/* 0x1dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: je     371 <execve_rate+0x371> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e0, 0x371, x86_l_371);
x86_l_1e6:
	/* 0x1e6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1e9:
	/* 0x1e9: mov    DWORD PTR [rax+0x4],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869344ULL);
x86_l_1f0:
	/* 0x1f0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f7:
	/* 0x1f7: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb:
	/* 0x1fb: mov    WORD PTR [rax],0x1b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_200:
	/* 0x200: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_207:
	/* 0x207: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_20c:
	/* 0x20c: call   211 <execve_rate+0x211> */
	X86_SIM_L_EXEC_CALL_MEMCPY(144ULL);
x86_l_211:
	/* 0x211: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_219:
	/* 0x219: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_225:
	/* 0x225: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22a:
	/* 0x22a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c:
	/* 0x22c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f:
	/* 0x22f: je     2bd <execve_rate+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22f, 0x2bd, x86_l_2bd);
x86_l_235:
	/* 0x235: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_239:
	/* 0x239: je     2bd <execve_rate+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x239, 0x2bd, x86_l_2bd);
x86_l_23f:
	/* 0x23f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_246:
	/* 0x246: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_24b:
	/* 0x24b: mov    edx,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 160ULL);
x86_l_250:
	/* 0x250: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_255:
	/* 0x255: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_25a:
	/* 0x25a: mov    r8d,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 160ULL);
x86_l_260:
	/* 0x260: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_263:
	/* 0x263: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_266:
	/* 0x266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268:
	/* 0x268: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b:
	/* 0x26b: jns    371 <execve_rate+0x371> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x26b, 0x371, x86_l_371);
x86_l_271:
	/* 0x271: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_274:
	/* 0x274: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_27c:
	/* 0x27c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_283:
	/* 0x283: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_288:
	/* 0x288: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28d:
	/* 0x28d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f:
	/* 0x28f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_292:
	/* 0x292: je     371 <execve_rate+0x371> */
	X86_SIM_X86_JCC(X86_CC_E, 0x292, 0x371, x86_l_371);
x86_l_298:
	/* 0x298: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_29c:
	/* 0x29c: jg     33d <execve_rate+0x33d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x29c, 0x33d, x86_l_33d);
x86_l_2a2:
	/* 0x2a2: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2a6:
	/* 0x2a6: je     357 <execve_rate+0x357> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a6, 0x357, x86_l_357);
x86_l_2ac:
	/* 0x2ac: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2b0:
	/* 0x2b0: jne    315 <execve_rate+0x315> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b0, 0x315, x86_l_315);
x86_l_2b2:
	/* 0x2b2: add    rax,0x608 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1544ULL);
x86_l_2b8:
	/* 0x2b8: jmp    36d <execve_rate+0x36d> */
	X86_SIM_X86_JMP(0x2b8, 0x36d, x86_l_36d);
x86_l_2bd:
	/* 0x2bd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2c4:
	/* 0x2c4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c6:
	/* 0x2c6: mov    edx,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 160ULL);
x86_l_2cb:
	/* 0x2cb: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2d0:
	/* 0x2d0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d3:
	/* 0x2d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d5:
	/* 0x2d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7:
	/* 0x2d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2da:
	/* 0x2da: jns    371 <execve_rate+0x371> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2da, 0x371, x86_l_371);
x86_l_2e0:
	/* 0x2e0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2e3:
	/* 0x2e3: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2eb:
	/* 0x2eb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2f2:
	/* 0x2f2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f7:
	/* 0x2f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fc:
	/* 0x2fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe:
	/* 0x2fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_301:
	/* 0x301: je     371 <execve_rate+0x371> */
	X86_SIM_X86_JCC(X86_CC_E, 0x301, 0x371, x86_l_371);
x86_l_303:
	/* 0x303: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_307:
	/* 0x307: jg     323 <execve_rate+0x323> */
	X86_SIM_X86_JCC(X86_CC_G, 0x307, 0x323, x86_l_323);
x86_l_309:
	/* 0x309: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_30d:
	/* 0x30d: je     357 <execve_rate+0x357> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30d, 0x357, x86_l_357);
x86_l_30f:
	/* 0x30f: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_313:
	/* 0x313: je     2b2 <execve_rate+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x313, 0x2b2, x86_l_2b2);
x86_l_315:
	/* 0x315: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_319:
	/* 0x319: jne    34f <execve_rate+0x34f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x319, 0x34f, x86_l_34f);
x86_l_31b:
	/* 0x31b: add    rax,0x600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1536ULL);
x86_l_321:
	/* 0x321: jmp    36d <execve_rate+0x36d> */
	X86_SIM_X86_JMP(0x321, 0x36d, x86_l_36d);
x86_l_323:
	/* 0x323: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_327:
	/* 0x327: je     35f <execve_rate+0x35f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x327, 0x35f, x86_l_35f);
x86_l_329:
	/* 0x329: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_32d:
	/* 0x32d: je     367 <execve_rate+0x367> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x367, x86_l_367);
x86_l_32f:
	/* 0x32f: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_333:
	/* 0x333: jne    34f <execve_rate+0x34f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x333, 0x34f, x86_l_34f);
x86_l_335:
	/* 0x335: add    rax,0x5f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1520ULL);
x86_l_33b:
	/* 0x33b: jmp    36d <execve_rate+0x36d> */
	X86_SIM_X86_JMP(0x33b, 0x36d, x86_l_36d);
x86_l_33d:
	/* 0x33d: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_341:
	/* 0x341: je     35f <execve_rate+0x35f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x341, 0x35f, x86_l_35f);
x86_l_343:
	/* 0x343: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_347:
	/* 0x347: je     367 <execve_rate+0x367> */
	X86_SIM_X86_JCC(X86_CC_E, 0x347, 0x367, x86_l_367);
x86_l_349:
	/* 0x349: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_34d:
	/* 0x34d: je     335 <execve_rate+0x335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34d, 0x335, x86_l_335);
x86_l_34f:
	/* 0x34f: add    rax,0x5e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1512ULL);
x86_l_355:
	/* 0x355: jmp    36d <execve_rate+0x36d> */
	X86_SIM_X86_JMP(0x355, 0x36d, x86_l_36d);
x86_l_357:
	/* 0x357: add    rax,0x610 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1552ULL);
x86_l_35d:
	/* 0x35d: jmp    36d <execve_rate+0x36d> */
	X86_SIM_X86_JMP(0x35d, 0x36d, x86_l_36d);
x86_l_35f:
	/* 0x35f: add    rax,0x618 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1560ULL);
x86_l_365:
	/* 0x365: jmp    36d <execve_rate+0x36d> */
	X86_SIM_X86_JMP(0x365, 0x36d, x86_l_36d);
x86_l_367:
	/* 0x367: add    rax,0x5f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1528ULL);
x86_l_36d:
	/* 0x36d: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_371:
	/* 0x371: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_376:
	/* 0x376: jne    393 <execve_rate+0x393> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x376, 0x393, x86_l_393);
x86_l_378:
	/* 0x378: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_37f:
	/* 0x37f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_384:
	/* 0x384: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_389:
	/* 0x389: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_38c:
	/* 0x38c: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_391:
	/* 0x391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393:
	/* 0x393: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_395:
	/* 0x395: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_399:
	/* 0x399: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_39b:
	/* 0x39b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_39c:
	/* 0x39c: jmp    3a1 <execve_rate+0x3a1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3a1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
