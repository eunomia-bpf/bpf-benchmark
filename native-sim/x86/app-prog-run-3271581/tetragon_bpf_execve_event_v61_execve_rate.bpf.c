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
	/* 0xa: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_19:
	/* 0x19: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_20:
	/* 0x20: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25:
	/* 0x25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a:
	/* 0x2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c:
	/* 0x2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: je     39a <execve_rate+0x39a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f, 0x39a, x86_l_39a);
x86_l_35:
	/* 0x35: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39:
	/* 0x39: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40:
	/* 0x40: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45:
	/* 0x45: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4d:
	/* 0x4d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_options_map)));
x86_l_54:
	/* 0x54: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59:
	/* 0x59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63:
	/* 0x63: je     37f <execve_rate+0x37f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0x37f, x86_l_37f);
x86_l_69:
	/* 0x69: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d:
	/* 0x6d: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_70:
	/* 0x70: je     37f <execve_rate+0x37f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70, 0x37f, x86_l_37f);
x86_l_76:
	/* 0x76: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_79:
	/* 0x79: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_rate_map)));
x86_l_80:
	/* 0x80: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_85:
	/* 0x85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a:
	/* 0x8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c:
	/* 0x8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f:
	/* 0x8f: je     c9 <execve_rate+0xc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f, 0xc9, x86_l_c9);
x86_l_91:
	/* 0x91: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_94:
	/* 0x94: mov    rsi,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_98:
	/* 0x98: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_9b:
	/* 0x9b: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9e:
	/* 0x9e: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_a1:
	/* 0xa1: jbe    f1 <execve_rate+0xf1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa1, 0xf1, x86_l_f1);
x86_l_a3:
	/* 0xa3: lea    rcx,[r12+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_a7:
	/* 0xa7: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: jbe    fa <execve_rate+0xfa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xaa, 0xfa, x86_l_fa);
x86_l_ac:
	/* 0xac: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_af:
	/* 0xaf: or     rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_b2:
	/* 0xb2: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_b6:
	/* 0xb6: je     145 <execve_rate+0x145> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6, 0x145, x86_l_145);
x86_l_bc:
	/* 0xbc: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c1:
	/* 0xc1: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_c4:
	/* 0xc4: jmp    14d <execve_rate+0x14d> */
	X86_SIM_X86_JMP(0xc4, 0x14d, x86_l_14d);
x86_l_c9:
	/* 0xc9: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_db:
	/* 0xdb: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_de:
	/* 0xde: or     rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_e1:
	/* 0xe1: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e5:
	/* 0xe5: je     102 <execve_rate+0x102> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe5, 0x102, x86_l_102);
x86_l_e7:
	/* 0xe7: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_ea:
	/* 0xea: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec:
	/* 0xec: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_ef:
	/* 0xef: jmp    10a <execve_rate+0x10a> */
	X86_SIM_X86_JMP(0xef, 0x10a, x86_l_10a);
x86_l_f1:
	/* 0xf1: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4:
	/* 0xf4: mov    rdx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8:
	/* 0xf8: jmp    15f <execve_rate+0x15f> */
	X86_SIM_X86_JMP(0xf8, 0x15f, x86_l_15f);
x86_l_fa:
	/* 0xfa: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: add    rsi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
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
	/* 0x107: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
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
	/* 0x140: jmp    37f <execve_rate+0x37f> */
	X86_SIM_X86_JMP(0x140, 0x37f, x86_l_37f);
x86_l_145:
	/* 0x145: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_148:
	/* 0x148: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a:
	/* 0x14a: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
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
	/* 0x15d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f:
	/* 0x15f: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_162:
	/* 0x162: mov    QWORD PTR [r14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165:
	/* 0x165: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
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
	/* 0x175: or     rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
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
	/* 0x180: div    r12 */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
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
	/* 0x18f: jne    39a <execve_rate+0x39a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18f, 0x39a, x86_l_39a);
x86_l_195:
	/* 0x195: jmp    1ae <execve_rate+0x1ae> */
	X86_SIM_X86_JMP(0x195, 0x1ae, x86_l_1ae);
x86_l_197:
	/* 0x197: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199:
	/* 0x199: div    r12d */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_R12, X86_WIDTH_32, 0, 0);
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
	/* 0x1a8: jne    39a <execve_rate+0x39a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a8, 0x39a, x86_l_39a);
x86_l_1ae:
	/* 0x1ae: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1b2:
	/* 0x1b2: jb     37f <execve_rate+0x37f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b2, 0x37f, x86_l_37f);
x86_l_1b8:
	/* 0x1b8: mov    QWORD PTR [r14+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc:
	/* 0x1bc: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c4:
	/* 0x1c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&throttle_heap_map)));
x86_l_1cb:
	/* 0x1cb: lea    rcx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0:
	/* 0x1d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d5:
	/* 0x1d5: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1dd:
	/* 0x1dd: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e2:
	/* 0x1e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4:
	/* 0x1e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e7:
	/* 0x1e7: je     378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e7, 0x378, x86_l_378);
x86_l_1ed:
	/* 0x1ed: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: mov    DWORD PTR [rax+0x4],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869344ULL);
x86_l_1f7:
	/* 0x1f7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1fa:
	/* 0x1fa: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fe:
	/* 0x1fe: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202:
	/* 0x202: mov    WORD PTR [rax],0x1b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_207:
	/* 0x207: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_20a:
	/* 0x20a: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20e:
	/* 0x20e: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_213:
	/* 0x213: call   218 <execve_rate+0x218> */
	X86_SIM_L_EXEC_CALL_MEMCPY(144ULL);
x86_l_218:
	/* 0x218: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_220:
	/* 0x220: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_227:
	/* 0x227: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22c:
	/* 0x22c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_231:
	/* 0x231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233:
	/* 0x233: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_236:
	/* 0x236: je     2c4 <execve_rate+0x2c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x236, 0x2c4, x86_l_2c4);
x86_l_23c:
	/* 0x23c: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_240:
	/* 0x240: je     2c4 <execve_rate+0x2c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x240, 0x2c4, x86_l_2c4);
x86_l_246:
	/* 0x246: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_24d:
	/* 0x24d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_252:
	/* 0x252: mov    edx,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 160ULL);
x86_l_257:
	/* 0x257: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_25c:
	/* 0x25c: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_261:
	/* 0x261: mov    r8d,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 160ULL);
x86_l_267:
	/* 0x267: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26a:
	/* 0x26a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_26d:
	/* 0x26d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f:
	/* 0x26f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_272:
	/* 0x272: jns    378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x272, 0x378, x86_l_378);
x86_l_278:
	/* 0x278: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_27b:
	/* 0x27b: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_283:
	/* 0x283: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_28a:
	/* 0x28a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f:
	/* 0x28f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_294:
	/* 0x294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296:
	/* 0x296: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299:
	/* 0x299: je     378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_E, 0x299, 0x378, x86_l_378);
x86_l_29f:
	/* 0x29f: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2a3:
	/* 0x2a3: jg     344 <execve_rate+0x344> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2a3, 0x344, x86_l_344);
x86_l_2a9:
	/* 0x2a9: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2ad:
	/* 0x2ad: je     35e <execve_rate+0x35e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ad, 0x35e, x86_l_35e);
x86_l_2b3:
	/* 0x2b3: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2b7:
	/* 0x2b7: jne    31c <execve_rate+0x31c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b7, 0x31c, x86_l_31c);
x86_l_2b9:
	/* 0x2b9: add    rax,0x608 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1544ULL);
x86_l_2bf:
	/* 0x2bf: jmp    374 <execve_rate+0x374> */
	X86_SIM_X86_JMP(0x2bf, 0x374, x86_l_374);
x86_l_2c4:
	/* 0x2c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2cb:
	/* 0x2cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd:
	/* 0x2cd: mov    edx,0xa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 160ULL);
x86_l_2d2:
	/* 0x2d2: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2d7:
	/* 0x2d7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2da:
	/* 0x2da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dc:
	/* 0x2dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de:
	/* 0x2de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e1:
	/* 0x2e1: jns    378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2e1, 0x378, x86_l_378);
x86_l_2e7:
	/* 0x2e7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ea:
	/* 0x2ea: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2f2:
	/* 0x2f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2f9:
	/* 0x2f9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fe:
	/* 0x2fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_303:
	/* 0x303: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305:
	/* 0x305: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_308:
	/* 0x308: je     378 <execve_rate+0x378> */
	X86_SIM_X86_JCC(X86_CC_E, 0x308, 0x378, x86_l_378);
x86_l_30a:
	/* 0x30a: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_30e:
	/* 0x30e: jg     32a <execve_rate+0x32a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x30e, 0x32a, x86_l_32a);
x86_l_310:
	/* 0x310: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_314:
	/* 0x314: je     35e <execve_rate+0x35e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x314, 0x35e, x86_l_35e);
x86_l_316:
	/* 0x316: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_31a:
	/* 0x31a: je     2b9 <execve_rate+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31a, 0x2b9, x86_l_2b9);
x86_l_31c:
	/* 0x31c: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_320:
	/* 0x320: jne    356 <execve_rate+0x356> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x320, 0x356, x86_l_356);
x86_l_322:
	/* 0x322: add    rax,0x600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1536ULL);
x86_l_328:
	/* 0x328: jmp    374 <execve_rate+0x374> */
	X86_SIM_X86_JMP(0x328, 0x374, x86_l_374);
x86_l_32a:
	/* 0x32a: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_32e:
	/* 0x32e: je     366 <execve_rate+0x366> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32e, 0x366, x86_l_366);
x86_l_330:
	/* 0x330: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_334:
	/* 0x334: je     36e <execve_rate+0x36e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x334, 0x36e, x86_l_36e);
x86_l_336:
	/* 0x336: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_33a:
	/* 0x33a: jne    356 <execve_rate+0x356> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33a, 0x356, x86_l_356);
x86_l_33c:
	/* 0x33c: add    rax,0x5f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1520ULL);
x86_l_342:
	/* 0x342: jmp    374 <execve_rate+0x374> */
	X86_SIM_X86_JMP(0x342, 0x374, x86_l_374);
x86_l_344:
	/* 0x344: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_348:
	/* 0x348: je     366 <execve_rate+0x366> */
	X86_SIM_X86_JCC(X86_CC_E, 0x348, 0x366, x86_l_366);
x86_l_34a:
	/* 0x34a: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_34e:
	/* 0x34e: je     36e <execve_rate+0x36e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34e, 0x36e, x86_l_36e);
x86_l_350:
	/* 0x350: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_354:
	/* 0x354: je     33c <execve_rate+0x33c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x354, 0x33c, x86_l_33c);
x86_l_356:
	/* 0x356: add    rax,0x5e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1512ULL);
x86_l_35c:
	/* 0x35c: jmp    374 <execve_rate+0x374> */
	X86_SIM_X86_JMP(0x35c, 0x374, x86_l_374);
x86_l_35e:
	/* 0x35e: add    rax,0x610 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1552ULL);
x86_l_364:
	/* 0x364: jmp    374 <execve_rate+0x374> */
	X86_SIM_X86_JMP(0x364, 0x374, x86_l_374);
x86_l_366:
	/* 0x366: add    rax,0x618 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1560ULL);
x86_l_36c:
	/* 0x36c: jmp    374 <execve_rate+0x374> */
	X86_SIM_X86_JMP(0x36c, 0x374, x86_l_374);
x86_l_36e:
	/* 0x36e: add    rax,0x5f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1528ULL);
x86_l_374:
	/* 0x374: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_378:
	/* 0x378: cmp    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_37d:
	/* 0x37d: jne    39a <execve_rate+0x39a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37d, 0x39a, x86_l_39a);
x86_l_37f:
	/* 0x37f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_386:
	/* 0x386: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_38b:
	/* 0x38b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_390:
	/* 0x390: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_393:
	/* 0x393: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_398:
	/* 0x398: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39a:
	/* 0x39a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39c:
	/* 0x39c: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_3a0:
	/* 0x3a0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3a1:
	/* 0x3a1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3a3:
	/* 0x3a3: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3a5:
	/* 0x3a5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3a7:
	/* 0x3a7: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3a9:
	/* 0x3a9: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3aa:
	/* 0x3aa: jmp    3af <execve_rate+0x3af> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3af:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
