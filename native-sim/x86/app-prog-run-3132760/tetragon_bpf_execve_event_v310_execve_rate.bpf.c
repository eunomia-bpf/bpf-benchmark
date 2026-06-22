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
int tetragon_bpf_execve_event_v310_execve_rate_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x28: je     2f3 <execve_rate+0x2f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28, 0x2f3, x86_l_2f3);
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
	/* 0x3e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_46:
	/* 0x46: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_options_map)));
x86_l_4d:
	/* 0x4d: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
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
	/* 0x5c: je     2d8 <execve_rate+0x2d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c, 0x2d8, x86_l_2d8);
x86_l_62:
	/* 0x62: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66:
	/* 0x66: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_69:
	/* 0x69: je     2d8 <execve_rate+0x2d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x2d8, x86_l_2d8);
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
	/* 0xb3: je     145 <execve_rate+0x145> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb3, 0x145, x86_l_145);
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
	/* 0xc1: jmp    14d <execve_rate+0x14d> */
	X86_SIM_X86_JMP(0xc1, 0x14d, x86_l_14d);
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
	/* 0xf8: jmp    162 <execve_rate+0x162> */
	X86_SIM_X86_JMP(0xf8, 0x162, x86_l_162);
x86_l_fa:
	/* 0xfa: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: add    rsi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_100:
	/* 0x100: jmp    155 <execve_rate+0x155> */
	X86_SIM_X86_JMP(0x100, 0x155, x86_l_155);
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
	/* 0x124: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_12b:
	/* 0x12b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d:
	/* 0x12d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_132:
	/* 0x132: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137:
	/* 0x137: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13c:
	/* 0x13c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e:
	/* 0x13e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140:
	/* 0x140: jmp    2d8 <execve_rate+0x2d8> */
	X86_SIM_X86_JMP(0x140, 0x2d8, x86_l_2d8);
x86_l_145:
	/* 0x145: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_148:
	/* 0x148: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a:
	/* 0x14a: div    r13d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_14d:
	/* 0x14d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_150:
	/* 0x150: sub    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_153:
	/* 0x153: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155:
	/* 0x155: mov    QWORD PTR [r14+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_159:
	/* 0x159: mov    QWORD PTR [r14+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d:
	/* 0x15d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_162:
	/* 0x162: mov    QWORD PTR [r14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165:
	/* 0x165: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_168:
	/* 0x168: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_16b:
	/* 0x16b: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16e:
	/* 0x16e: imul   rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_172:
	/* 0x172: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_175:
	/* 0x175: or     rdx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_178:
	/* 0x178: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_17c:
	/* 0x17c: je     197 <execve_rate+0x197> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17c, 0x197, x86_l_197);
x86_l_17e:
	/* 0x17e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_180:
	/* 0x180: div    r13 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_183:
	/* 0x183: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_186:
	/* 0x186: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a:
	/* 0x18a: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18f:
	/* 0x18f: jne    2f3 <execve_rate+0x2f3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18f, 0x2f3, x86_l_2f3);
x86_l_195:
	/* 0x195: jmp    1ae <execve_rate+0x1ae> */
	X86_SIM_X86_JMP(0x195, 0x1ae, x86_l_1ae);
x86_l_197:
	/* 0x197: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199:
	/* 0x199: div    r13d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R13, X86_WIDTH_32, 0, 0);
x86_l_19c:
	/* 0x19c: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19f:
	/* 0x19f: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a3:
	/* 0x1a3: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a8:
	/* 0x1a8: jne    2f3 <execve_rate+0x2f3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a8, 0x2f3, x86_l_2f3);
x86_l_1ae:
	/* 0x1ae: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1b2:
	/* 0x1b2: jb     2d8 <execve_rate+0x2d8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b2, 0x2d8, x86_l_2d8);
x86_l_1b8:
	/* 0x1b8: mov    QWORD PTR [r14+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc:
	/* 0x1bc: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1c4:
	/* 0x1c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&throttle_heap_map)));
x86_l_1cb:
	/* 0x1cb: lea    rcx,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d0:
	/* 0x1d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d5:
	/* 0x1d5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1dd:
	/* 0x1dd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e2:
	/* 0x1e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4:
	/* 0x1e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e7:
	/* 0x1e7: je     2d1 <execve_rate+0x2d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e7, 0x2d1, x86_l_2d1);
x86_l_1ed:
	/* 0x1ed: mov    DWORD PTR [rax+0x4],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869344ULL);
x86_l_1f4:
	/* 0x1f4: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1f7:
	/* 0x1f7: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fb:
	/* 0x1fb: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff:
	/* 0x1ff: mov    WORD PTR [rax],0x1b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_204:
	/* 0x204: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_207:
	/* 0x207: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20b:
	/* 0x20b: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_210:
	/* 0x210: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_213:
	/* 0x213: call   218 <execve_rate+0x218> */
	X86_SIM_L_EXEC_CALL_MEMCPY(144ULL);
x86_l_218:
	/* 0x218: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_21f:
	/* 0x21f: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_224:
	/* 0x224: mov    edx,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 160ULL);
x86_l_229:
	/* 0x229: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22e:
	/* 0x22e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_233:
	/* 0x233: mov    r8d,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 160ULL);
x86_l_239:
	/* 0x239: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23c:
	/* 0x23c: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_23f:
	/* 0x23f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241:
	/* 0x241: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_244:
	/* 0x244: jns    2d1 <execve_rate+0x2d1> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x244, 0x2d1, x86_l_2d1);
x86_l_24a:
	/* 0x24a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_255:
	/* 0x255: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_25c:
	/* 0x25c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_261:
	/* 0x261: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_266:
	/* 0x266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268:
	/* 0x268: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b:
	/* 0x26b: je     2d1 <execve_rate+0x2d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26b, 0x2d1, x86_l_2d1);
x86_l_26d:
	/* 0x26d: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_271:
	/* 0x271: jg     28d <execve_rate+0x28d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x271, 0x28d, x86_l_28d);
x86_l_273:
	/* 0x273: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_277:
	/* 0x277: je     2a7 <execve_rate+0x2a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x277, 0x2a7, x86_l_2a7);
x86_l_279:
	/* 0x279: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_27d:
	/* 0x27d: je     2bf <execve_rate+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27d, 0x2bf, x86_l_2bf);
x86_l_27f:
	/* 0x27f: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_283:
	/* 0x283: jne    2b7 <execve_rate+0x2b7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x283, 0x2b7, x86_l_2b7);
x86_l_285:
	/* 0x285: add    rax,0x600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1536ULL);
x86_l_28b:
	/* 0x28b: jmp    2cd <execve_rate+0x2cd> */
	X86_SIM_X86_JMP(0x28b, 0x2cd, x86_l_2cd);
x86_l_28d:
	/* 0x28d: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_291:
	/* 0x291: je     2af <execve_rate+0x2af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x291, 0x2af, x86_l_2af);
x86_l_293:
	/* 0x293: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_297:
	/* 0x297: je     2c7 <execve_rate+0x2c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x297, 0x2c7, x86_l_2c7);
x86_l_299:
	/* 0x299: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_29d:
	/* 0x29d: jne    2b7 <execve_rate+0x2b7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29d, 0x2b7, x86_l_2b7);
x86_l_29f:
	/* 0x29f: add    rax,0x5f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1520ULL);
x86_l_2a5:
	/* 0x2a5: jmp    2cd <execve_rate+0x2cd> */
	X86_SIM_X86_JMP(0x2a5, 0x2cd, x86_l_2cd);
x86_l_2a7:
	/* 0x2a7: add    rax,0x610 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1552ULL);
x86_l_2ad:
	/* 0x2ad: jmp    2cd <execve_rate+0x2cd> */
	X86_SIM_X86_JMP(0x2ad, 0x2cd, x86_l_2cd);
x86_l_2af:
	/* 0x2af: add    rax,0x618 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1560ULL);
x86_l_2b5:
	/* 0x2b5: jmp    2cd <execve_rate+0x2cd> */
	X86_SIM_X86_JMP(0x2b5, 0x2cd, x86_l_2cd);
x86_l_2b7:
	/* 0x2b7: add    rax,0x5e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1512ULL);
x86_l_2bd:
	/* 0x2bd: jmp    2cd <execve_rate+0x2cd> */
	X86_SIM_X86_JMP(0x2bd, 0x2cd, x86_l_2cd);
x86_l_2bf:
	/* 0x2bf: add    rax,0x608 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1544ULL);
x86_l_2c5:
	/* 0x2c5: jmp    2cd <execve_rate+0x2cd> */
	X86_SIM_X86_JMP(0x2c5, 0x2cd, x86_l_2cd);
x86_l_2c7:
	/* 0x2c7: add    rax,0x5f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1528ULL);
x86_l_2cd:
	/* 0x2cd: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2d1:
	/* 0x2d1: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2d6:
	/* 0x2d6: jne    2f3 <execve_rate+0x2f3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d6, 0x2f3, x86_l_2f3);
x86_l_2d8:
	/* 0x2d8: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_2df:
	/* 0x2df: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e4:
	/* 0x2e4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e9:
	/* 0x2e9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ec:
	/* 0x2ec: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2f1:
	/* 0x2f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3:
	/* 0x2f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5:
	/* 0x2f5: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_2f9:
	/* 0x2f9: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2fc:
	/* 0x2fc: jmp    301 <execve_rate+0x301> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_301:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
