extern char cgroup_rate_map;
extern char cgroup_rate_options_map;
extern char execve_calls;
extern char execve_msg_heap_map;
extern char tcpmon_map;
extern char tg_stats_map;
extern char throttle_heap_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_event_execve_rate_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_12:
	/* 0x12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     2d5 <execve_rate+0x2d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x2d5, x86_l_2d5);
x86_l_2e:
	/* 0x2e: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32:
	/* 0x32: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_35:
	/* 0x35: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39:
	/* 0x39: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e:
	/* 0x3e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46:
	/* 0x46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b:
	/* 0x4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_options_map)));
x86_l_52:
	/* 0x52: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57:
	/* 0x57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59:
	/* 0x59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: je     2bf <execve_rate+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x2bf, x86_l_2bf);
x86_l_62:
	/* 0x62: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66:
	/* 0x66: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_69:
	/* 0x69: je     2bf <execve_rate+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x2bf, x86_l_2bf);
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
	/* 0x88: je     c6 <execve_rate+0xc6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88, 0xc6, x86_l_c6);
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
	/* 0x97: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: jbe    ee <execve_rate+0xee> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x9a, 0xee, x86_l_ee);
x86_l_9c:
	/* 0x9c: lea    rcx,[r13*2+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 1), 0ULL);
x86_l_a4:
	/* 0xa4: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: jbe    fa <execve_rate+0xfa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa7, 0xfa, x86_l_fa);
x86_l_a9:
	/* 0xa9: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_ac:
	/* 0xac: or     rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_af:
	/* 0xaf: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_b3:
	/* 0xb3: je     143 <execve_rate+0x143> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb3, 0x143, x86_l_143);
x86_l_b9:
	/* 0xb9: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_bc:
	/* 0xbc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be:
	/* 0xbe: div    r13 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_c1:
	/* 0xc1: jmp    14b <execve_rate+0x14b> */
	X86_SIM_X86_JMP(0xc1, 0x14b, x86_l_14b);
x86_l_c6:
	/* 0xc6: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_cf:
	/* 0xcf: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d8:
	/* 0xd8: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: or     rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_de:
	/* 0xde: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e2:
	/* 0xe2: je     102 <execve_rate+0x102> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe2, 0x102, x86_l_102);
x86_l_e4:
	/* 0xe4: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_e7:
	/* 0xe7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9:
	/* 0xe9: div    r13 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_ec:
	/* 0xec: jmp    10a <execve_rate+0x10a> */
	X86_SIM_X86_JMP(0xec, 0x10a, x86_l_10a);
x86_l_ee:
	/* 0xee: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1:
	/* 0xf1: mov    rdx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f5:
	/* 0xf5: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f8:
	/* 0xf8: jmp    160 <execve_rate+0x160> */
	X86_SIM_X86_JMP(0xf8, 0x160, x86_l_160);
x86_l_fa:
	/* 0xfa: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: add    rsi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_100:
	/* 0x100: jmp    153 <execve_rate+0x153> */
	X86_SIM_X86_JMP(0x100, 0x153, x86_l_153);
x86_l_102:
	/* 0x102: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_105:
	/* 0x105: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107:
	/* 0x107: div    r13d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_10a:
	/* 0x10a: sub    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_112:
	/* 0x112: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_124:
	/* 0x124: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_129:
	/* 0x129: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_130:
	/* 0x130: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_135:
	/* 0x135: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13a:
	/* 0x13a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c:
	/* 0x13c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e:
	/* 0x13e: jmp    2bf <execve_rate+0x2bf> */
	X86_SIM_X86_JMP(0x13e, 0x2bf, x86_l_2bf);
x86_l_143:
	/* 0x143: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_146:
	/* 0x146: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_148:
	/* 0x148: div    r13d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_14b:
	/* 0x14b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: sub    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_151:
	/* 0x151: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153:
	/* 0x153: mov    QWORD PTR [r14+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157:
	/* 0x157: mov    QWORD PTR [r14+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b:
	/* 0x15b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_160:
	/* 0x160: mov    QWORD PTR [r14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163:
	/* 0x163: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_166:
	/* 0x166: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_169:
	/* 0x169: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16c:
	/* 0x16c: imul   rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_170:
	/* 0x170: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_173:
	/* 0x173: or     rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_176:
	/* 0x176: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_17a:
	/* 0x17a: je     195 <execve_rate+0x195> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17a, 0x195, x86_l_195);
x86_l_17c:
	/* 0x17c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e:
	/* 0x17e: div    r13 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_181:
	/* 0x181: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_184:
	/* 0x184: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188:
	/* 0x188: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18d:
	/* 0x18d: jne    2d5 <execve_rate+0x2d5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18d, 0x2d5, x86_l_2d5);
x86_l_193:
	/* 0x193: jmp    1ac <execve_rate+0x1ac> */
	X86_SIM_X86_JMP(0x193, 0x1ac, x86_l_1ac);
x86_l_195:
	/* 0x195: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_197:
	/* 0x197: div    r13d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_19a:
	/* 0x19a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19d:
	/* 0x19d: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a1:
	/* 0x1a1: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a6:
	/* 0x1a6: jne    2d5 <execve_rate+0x2d5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a6, 0x2d5, x86_l_2d5);
x86_l_1ac:
	/* 0x1ac: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1b0:
	/* 0x1b0: jb     2bf <execve_rate+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b0, 0x2bf, x86_l_2bf);
x86_l_1b6:
	/* 0x1b6: mov    QWORD PTR [r14+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ba:
	/* 0x1ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bf:
	/* 0x1bf: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1c7:
	/* 0x1c7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&throttle_heap_map)));
x86_l_1ce:
	/* 0x1ce: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d3:
	/* 0x1d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5:
	/* 0x1d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d8:
	/* 0x1d8: je     2b8 <execve_rate+0x2b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d8, 0x2b8, x86_l_2b8);
x86_l_1de:
	/* 0x1de: mov    DWORD PTR [rax+0x4],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869344ULL);
x86_l_1e5:
	/* 0x1e5: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ec:
	/* 0x1ec: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f0:
	/* 0x1f0: mov    WORD PTR [rax],0x1b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1f5:
	/* 0x1f5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f8:
	/* 0x1f8: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fc:
	/* 0x1fc: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_201:
	/* 0x201: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_204:
	/* 0x204: call   209 <execve_rate+0x209> */
	X86_SIM_L_EXEC_CALL_MEMCPY(144ULL);
x86_l_209:
	/* 0x209: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_20e:
	/* 0x20e: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_215:
	/* 0x215: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_21a:
	/* 0x21a: mov    r8d,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 160ULL);
x86_l_220:
	/* 0x220: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_226:
	/* 0x226: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228:
	/* 0x228: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22b:
	/* 0x22b: jns    2b8 <execve_rate+0x2b8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x22b, 0x2b8, x86_l_2b8);
x86_l_231:
	/* 0x231: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_234:
	/* 0x234: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_23c:
	/* 0x23c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_241:
	/* 0x241: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_248:
	/* 0x248: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24d:
	/* 0x24d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f:
	/* 0x24f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_252:
	/* 0x252: je     2b8 <execve_rate+0x2b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x252, 0x2b8, x86_l_2b8);
x86_l_254:
	/* 0x254: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_258:
	/* 0x258: jg     274 <execve_rate+0x274> */
	X86_SIM_X86_JCC(X86_CC_G, 0x258, 0x274, x86_l_274);
x86_l_25a:
	/* 0x25a: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_25e:
	/* 0x25e: je     28e <execve_rate+0x28e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25e, 0x28e, x86_l_28e);
x86_l_260:
	/* 0x260: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_264:
	/* 0x264: je     2a6 <execve_rate+0x2a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x264, 0x2a6, x86_l_2a6);
x86_l_266:
	/* 0x266: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_26a:
	/* 0x26a: jne    29e <execve_rate+0x29e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x26a, 0x29e, x86_l_29e);
x86_l_26c:
	/* 0x26c: add    rax,0x600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1536ULL);
x86_l_272:
	/* 0x272: jmp    2b4 <execve_rate+0x2b4> */
	X86_SIM_X86_JMP(0x272, 0x2b4, x86_l_2b4);
x86_l_274:
	/* 0x274: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_278:
	/* 0x278: je     296 <execve_rate+0x296> */
	X86_SIM_X86_JCC(X86_CC_E, 0x278, 0x296, x86_l_296);
x86_l_27a:
	/* 0x27a: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_27e:
	/* 0x27e: je     2ae <execve_rate+0x2ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27e, 0x2ae, x86_l_2ae);
x86_l_280:
	/* 0x280: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_284:
	/* 0x284: jne    29e <execve_rate+0x29e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x284, 0x29e, x86_l_29e);
x86_l_286:
	/* 0x286: add    rax,0x5f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1520ULL);
x86_l_28c:
	/* 0x28c: jmp    2b4 <execve_rate+0x2b4> */
	X86_SIM_X86_JMP(0x28c, 0x2b4, x86_l_2b4);
x86_l_28e:
	/* 0x28e: add    rax,0x610 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1552ULL);
x86_l_294:
	/* 0x294: jmp    2b4 <execve_rate+0x2b4> */
	X86_SIM_X86_JMP(0x294, 0x2b4, x86_l_2b4);
x86_l_296:
	/* 0x296: add    rax,0x618 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1560ULL);
x86_l_29c:
	/* 0x29c: jmp    2b4 <execve_rate+0x2b4> */
	X86_SIM_X86_JMP(0x29c, 0x2b4, x86_l_2b4);
x86_l_29e:
	/* 0x29e: add    rax,0x5e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1512ULL);
x86_l_2a4:
	/* 0x2a4: jmp    2b4 <execve_rate+0x2b4> */
	X86_SIM_X86_JMP(0x2a4, 0x2b4, x86_l_2b4);
x86_l_2a6:
	/* 0x2a6: add    rax,0x608 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1544ULL);
x86_l_2ac:
	/* 0x2ac: jmp    2b4 <execve_rate+0x2b4> */
	X86_SIM_X86_JMP(0x2ac, 0x2b4, x86_l_2b4);
x86_l_2ae:
	/* 0x2ae: add    rax,0x5f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1528ULL);
x86_l_2b4:
	/* 0x2b4: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2b8:
	/* 0x2b8: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2bd:
	/* 0x2bd: jne    2d5 <execve_rate+0x2d5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2bd, 0x2d5, x86_l_2d5);
x86_l_2bf:
	/* 0x2bf: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c4:
	/* 0x2c4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_2cb:
	/* 0x2cb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ce:
	/* 0x2ce: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2d3:
	/* 0x2d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5:
	/* 0x2d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7:
	/* 0x2d7: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_2db:
	/* 0x2db: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2dd:
	/* 0x2dd: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2de:
	/* 0x2de: jmp    2e3 <execve_rate+0x2e3> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2e3:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
