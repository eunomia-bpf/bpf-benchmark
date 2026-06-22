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
int tetragon_bpf_execve_event_v61_execve_rate_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12:
	/* 0x12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     36b <execve_rate+0x36b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x36b, x86_l_36b);
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
	/* 0x3e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_46:
	/* 0x46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b:
	/* 0x4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_options_map)));
x86_l_52:
	/* 0x52: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_57:
	/* 0x57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59:
	/* 0x59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: je     355 <execve_rate+0x355> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x355, x86_l_355);
x86_l_62:
	/* 0x62: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66:
	/* 0x66: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_69:
	/* 0x69: je     355 <execve_rate+0x355> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x355, x86_l_355);
x86_l_6f:
	/* 0x6f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_72:
	/* 0x72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_77:
	/* 0x77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_7e:
	/* 0x7e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
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
	/* 0xaf: je     13c <execve_rate+0x13c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf, 0x13c, x86_l_13c);
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
	/* 0xbd: jmp    144 <execve_rate+0x144> */
	X86_SIM_X86_JMP(0xbd, 0x144, x86_l_144);
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
	/* 0xf1: jmp    156 <execve_rate+0x156> */
	X86_SIM_X86_JMP(0xf1, 0x156, x86_l_156);
x86_l_f3:
	/* 0xf3: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6:
	/* 0xf6: add    rsi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f9:
	/* 0xf9: jmp    14c <execve_rate+0x14c> */
	X86_SIM_X86_JMP(0xf9, 0x14c, x86_l_14c);
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
	/* 0x11d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_122:
	/* 0x122: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_129:
	/* 0x129: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12e:
	/* 0x12e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_133:
	/* 0x133: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_135:
	/* 0x135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137:
	/* 0x137: jmp    355 <execve_rate+0x355> */
	X86_SIM_X86_JMP(0x137, 0x355, x86_l_355);
x86_l_13c:
	/* 0x13c: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_13f:
	/* 0x13f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141:
	/* 0x141: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_144:
	/* 0x144: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_147:
	/* 0x147: sub    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_14a:
	/* 0x14a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c:
	/* 0x14c: mov    QWORD PTR [r14+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150:
	/* 0x150: mov    QWORD PTR [r14+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_154:
	/* 0x154: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_156:
	/* 0x156: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_159:
	/* 0x159: mov    QWORD PTR [r14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c:
	/* 0x15c: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_15f:
	/* 0x15f: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_162:
	/* 0x162: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_165:
	/* 0x165: imul   rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_169:
	/* 0x169: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_16c:
	/* 0x16c: or     rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_16f:
	/* 0x16f: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_173:
	/* 0x173: je     18e <execve_rate+0x18e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x173, 0x18e, x86_l_18e);
x86_l_175:
	/* 0x175: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_177:
	/* 0x177: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_17a:
	/* 0x17a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17d:
	/* 0x17d: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181:
	/* 0x181: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_186:
	/* 0x186: jne    36b <execve_rate+0x36b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x186, 0x36b, x86_l_36b);
x86_l_18c:
	/* 0x18c: jmp    1a5 <execve_rate+0x1a5> */
	X86_SIM_X86_JMP(0x18c, 0x1a5, x86_l_1a5);
x86_l_18e:
	/* 0x18e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_190:
	/* 0x190: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
x86_l_193:
	/* 0x193: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_196:
	/* 0x196: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19a:
	/* 0x19a: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_19f:
	/* 0x19f: jne    36b <execve_rate+0x36b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19f, 0x36b, x86_l_36b);
x86_l_1a5:
	/* 0x1a5: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1a9:
	/* 0x1a9: jb     355 <execve_rate+0x355> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a9, 0x355, x86_l_355);
x86_l_1af:
	/* 0x1af: mov    QWORD PTR [r14+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3:
	/* 0x1b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b8:
	/* 0x1b8: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c0:
	/* 0x1c0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&throttle_heap_map)));
x86_l_1c7:
	/* 0x1c7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc:
	/* 0x1cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce:
	/* 0x1ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d1:
	/* 0x1d1: je     34e <execve_rate+0x34e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d1, 0x34e, x86_l_34e);
x86_l_1d7:
	/* 0x1d7: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1da:
	/* 0x1da: mov    DWORD PTR [rax+0x4],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869344ULL);
x86_l_1e1:
	/* 0x1e1: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1e4:
	/* 0x1e4: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ec:
	/* 0x1ec: mov    WORD PTR [rax],0x1b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1f1:
	/* 0x1f1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f4:
	/* 0x1f4: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f8:
	/* 0x1f8: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1fd:
	/* 0x1fd: call   202 <execve_rate+0x202> */
	X86_SIM_L_EXEC_CALL_MEMCPY(144ULL);
x86_l_202:
	/* 0x202: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_20a:
	/* 0x20a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20f:
	/* 0x20f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_216:
	/* 0x216: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21b:
	/* 0x21b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d:
	/* 0x21d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_220:
	/* 0x220: je     29c <execve_rate+0x29c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x220, 0x29c, x86_l_29c);
x86_l_222:
	/* 0x222: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_226:
	/* 0x226: je     29c <execve_rate+0x29c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x226, 0x29c, x86_l_29c);
x86_l_228:
	/* 0x228: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22d:
	/* 0x22d: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_234:
	/* 0x234: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_239:
	/* 0x239: mov    r8d,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 160ULL);
x86_l_23f:
	/* 0x23f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_242:
	/* 0x242: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: jns    34e <execve_rate+0x34e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x24a, 0x34e, x86_l_34e);
x86_l_250:
	/* 0x250: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_253:
	/* 0x253: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_25b:
	/* 0x25b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_260:
	/* 0x260: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_267:
	/* 0x267: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26c:
	/* 0x26c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e:
	/* 0x26e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_271:
	/* 0x271: je     34e <execve_rate+0x34e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x271, 0x34e, x86_l_34e);
x86_l_277:
	/* 0x277: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_27b:
	/* 0x27b: jg     31a <execve_rate+0x31a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x27b, 0x31a, x86_l_31a);
x86_l_281:
	/* 0x281: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_285:
	/* 0x285: je     334 <execve_rate+0x334> */
	X86_SIM_X86_JCC(X86_CC_E, 0x285, 0x334, x86_l_334);
x86_l_28b:
	/* 0x28b: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_28f:
	/* 0x28f: jne    2f2 <execve_rate+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x28f, 0x2f2, x86_l_2f2);
x86_l_291:
	/* 0x291: add    rax,0x608 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1544ULL);
x86_l_297:
	/* 0x297: jmp    34a <execve_rate+0x34a> */
	X86_SIM_X86_JMP(0x297, 0x34a, x86_l_34a);
x86_l_29c:
	/* 0x29c: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2a1:
	/* 0x2a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2a8:
	/* 0x2a8: mov    edx,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 160ULL);
x86_l_2ad:
	/* 0x2ad: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b2:
	/* 0x2b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4:
	/* 0x2b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7:
	/* 0x2b7: jns    34e <execve_rate+0x34e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2b7, 0x34e, x86_l_34e);
x86_l_2bd:
	/* 0x2bd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c0:
	/* 0x2c0: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c8:
	/* 0x2c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cd:
	/* 0x2cd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2d4:
	/* 0x2d4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9:
	/* 0x2d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db:
	/* 0x2db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2de:
	/* 0x2de: je     34e <execve_rate+0x34e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2de, 0x34e, x86_l_34e);
x86_l_2e0:
	/* 0x2e0: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2e4:
	/* 0x2e4: jg     300 <execve_rate+0x300> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2e4, 0x300, x86_l_300);
x86_l_2e6:
	/* 0x2e6: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2ea:
	/* 0x2ea: je     334 <execve_rate+0x334> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ea, 0x334, x86_l_334);
x86_l_2ec:
	/* 0x2ec: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2f0:
	/* 0x2f0: je     291 <execve_rate+0x291> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f0, 0x291, x86_l_291);
x86_l_2f2:
	/* 0x2f2: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2f6:
	/* 0x2f6: jne    32c <execve_rate+0x32c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f6, 0x32c, x86_l_32c);
x86_l_2f8:
	/* 0x2f8: add    rax,0x600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1536ULL);
x86_l_2fe:
	/* 0x2fe: jmp    34a <execve_rate+0x34a> */
	X86_SIM_X86_JMP(0x2fe, 0x34a, x86_l_34a);
x86_l_300:
	/* 0x300: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_304:
	/* 0x304: je     33c <execve_rate+0x33c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x304, 0x33c, x86_l_33c);
x86_l_306:
	/* 0x306: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_30a:
	/* 0x30a: je     344 <execve_rate+0x344> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30a, 0x344, x86_l_344);
x86_l_30c:
	/* 0x30c: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_310:
	/* 0x310: jne    32c <execve_rate+0x32c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x310, 0x32c, x86_l_32c);
x86_l_312:
	/* 0x312: add    rax,0x5f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1520ULL);
x86_l_318:
	/* 0x318: jmp    34a <execve_rate+0x34a> */
	X86_SIM_X86_JMP(0x318, 0x34a, x86_l_34a);
x86_l_31a:
	/* 0x31a: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_31e:
	/* 0x31e: je     33c <execve_rate+0x33c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31e, 0x33c, x86_l_33c);
x86_l_320:
	/* 0x320: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_324:
	/* 0x324: je     344 <execve_rate+0x344> */
	X86_SIM_X86_JCC(X86_CC_E, 0x324, 0x344, x86_l_344);
x86_l_326:
	/* 0x326: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_32a:
	/* 0x32a: je     312 <execve_rate+0x312> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32a, 0x312, x86_l_312);
x86_l_32c:
	/* 0x32c: add    rax,0x5e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1512ULL);
x86_l_332:
	/* 0x332: jmp    34a <execve_rate+0x34a> */
	X86_SIM_X86_JMP(0x332, 0x34a, x86_l_34a);
x86_l_334:
	/* 0x334: add    rax,0x610 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1552ULL);
x86_l_33a:
	/* 0x33a: jmp    34a <execve_rate+0x34a> */
	X86_SIM_X86_JMP(0x33a, 0x34a, x86_l_34a);
x86_l_33c:
	/* 0x33c: add    rax,0x618 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1560ULL);
x86_l_342:
	/* 0x342: jmp    34a <execve_rate+0x34a> */
	X86_SIM_X86_JMP(0x342, 0x34a, x86_l_34a);
x86_l_344:
	/* 0x344: add    rax,0x5f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1528ULL);
x86_l_34a:
	/* 0x34a: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_34e:
	/* 0x34e: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_353:
	/* 0x353: jne    36b <execve_rate+0x36b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x353, 0x36b, x86_l_36b);
x86_l_355:
	/* 0x355: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_35a:
	/* 0x35a: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_361:
	/* 0x361: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_364:
	/* 0x364: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_369:
	/* 0x369: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b:
	/* 0x36b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36d:
	/* 0x36d: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_371:
	/* 0x371: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_373:
	/* 0x373: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_374:
	/* 0x374: jmp    379 <execve_rate+0x379> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_379:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
