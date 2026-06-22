extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char heap_ro_zero;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char ratelimit_heap;
extern char ratelimit_map;
extern char socktrack_map;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_v511_generic_usdt_actions_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 280ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1e:
	/* 0x1e: mov    rdi,QWORD PTR [rip+0x22db0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_25:
	/* 0x25: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a:
	/* 0x2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f:
	/* 0x2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31:
	/* 0x31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: je     d62 <generic_usdt_actions+0xd62> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34, 0xd62, x86_l_d62);
x86_l_3a:
	/* 0x3a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: mov    ebx,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_43:
	/* 0x43: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_46:
	/* 0x46: jl     d62 <generic_usdt_actions+0xd62> */
	X86_SIM_X86_JCC(X86_CC_L, 0x46, 0xd62, x86_l_d62);
x86_l_4c:
	/* 0x4c: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_53:
	/* 0x53: mov    rdi,QWORD PTR [rip+0x22db0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_5a:
	/* 0x5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f:
	/* 0x5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61:
	/* 0x61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64:
	/* 0x64: je     d62 <generic_usdt_actions+0xd62> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64, 0xd62, x86_l_d62);
x86_l_6a:
	/* 0x6a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_6f:
	/* 0x6f: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_74:
	/* 0x74: add    ebx,DWORD PTR [r14+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_78:
	/* 0x78: mov    DWORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_80:
	/* 0x80: mov    rdi,QWORD PTR [rip+0x22db0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_87:
	/* 0x87: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_8c:
	/* 0x8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91:
	/* 0x91: and    ebx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_97:
	/* 0x97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99:
	/* 0x99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c:
	/* 0x9c: je     c8 <generic_usdt_actions+0xc8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c, 0xc8, x86_l_c8);
x86_l_9e:
	/* 0x9e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0:
	/* 0xa0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3:
	/* 0xa3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a6:
	/* 0xa6: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a9:
	/* 0xa9: xor    rax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ba:
	/* 0xba: xor    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_be:
	/* 0xbe: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c6:
	/* 0xc6: jmp    e9 <generic_usdt_actions+0xe9> */
	X86_SIM_X86_JMP(0xc6, 0xe9, x86_l_e9);
x86_l_c8:
	/* 0xc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd:
	/* 0xcd: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d5:
	/* 0xd5: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_dc:
	/* 0xdc: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_e1:
	/* 0xe1: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e9:
	/* 0xe9: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ec:
	/* 0xec: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f1:
	/* 0xf1: lea    rax,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f5:
	/* 0xf5: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_fd:
	/* 0xfd: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101:
	/* 0x101: mov    QWORD PTR [rsp+0x108],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_109:
	/* 0x109: lea    rax,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_115:
	/* 0x115: lea    rax,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_119:
	/* 0x119: mov    QWORD PTR [rsp+0x100],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_121:
	/* 0x121: lea    rax,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_125:
	/* 0x125: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_12d:
	/* 0x12d: lea    rax,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_131:
	/* 0x131: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_139:
	/* 0x139: lea    rax,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13d:
	/* 0x13d: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_145:
	/* 0x145: lea    rax,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_149:
	/* 0x149: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_151:
	/* 0x151: lea    rax,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_155:
	/* 0x155: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15d:
	/* 0x15d: lea    rax,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_161:
	/* 0x161: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_169:
	/* 0x169: lea    rax,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16d:
	/* 0x16d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_175:
	/* 0x175: lea    rax,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_181:
	/* 0x181: lea    rax,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_185:
	/* 0x185: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18d:
	/* 0x18d: lea    rax,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [rsp+0x110],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_199:
	/* 0x199: lea    rax,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a0:
	/* 0x1a0: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1a8:
	/* 0x1a8: lea    rax,[rcx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1af:
	/* 0x1af: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b7:
	/* 0x1b7: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1b9:
	/* 0x1b9: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1bd:
	/* 0x1bd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0:
	/* 0x1c0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2:
	/* 0x1c2: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c7:
	/* 0x1c7: jmp    1ed <generic_usdt_actions+0x1ed> */
	X86_SIM_X86_JMP(0x1c7, 0x1ed, x86_l_1ed);
x86_l_1c9:
	/* 0x1c9: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1cb:
	/* 0x1cb: mov    eax,DWORD PTR [r14+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_1d0:
	/* 0x1d0: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d4:
	/* 0x1d4: mov    QWORD PTR [r13+0x70],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d8:
	/* 0x1d8: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1da:
	/* 0x1da: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1dd:
	/* 0x1dd: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1e0:
	/* 0x1e0: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_1e3:
	/* 0x1e3: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_1e7:
	/* 0x1e7: je     d3e <generic_usdt_actions+0xd3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e7, 0xd3e, x86_l_d3e);
x86_l_1ed:
	/* 0x1ed: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_1f4:
	/* 0x1f4: cmp    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1f7:
	/* 0x1f7: jae    d3e <generic_usdt_actions+0xd3e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1f7, 0xd3e, x86_l_d3e);
x86_l_1fd:
	/* 0x1fd: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1ff:
	/* 0x1ff: movsxd rbx,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_204:
	/* 0x204: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_20c:
	/* 0x20c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_211:
	/* 0x211: mov    rdi,QWORD PTR [rip+0x22dbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_218:
	/* 0x218: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21d:
	/* 0x21d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f:
	/* 0x21f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222:
	/* 0x222: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_225:
	/* 0x225: je     1dd <generic_usdt_actions+0x1dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x225, 0x1dd, x86_l_1dd);
x86_l_227:
	/* 0x227: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_22d:
	/* 0x22d: jg     250 <generic_usdt_actions+0x250> */
	X86_SIM_X86_JCC(X86_CC_G, 0x22d, 0x250, x86_l_250);
x86_l_22f:
	/* 0x22f: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_232:
	/* 0x232: jg     283 <generic_usdt_actions+0x283> */
	X86_SIM_X86_JCC(X86_CC_G, 0x232, 0x283, x86_l_283);
x86_l_234:
	/* 0x234: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_237:
	/* 0x237: jg     3df <generic_usdt_actions+0x3df> */
	X86_SIM_X86_JCC(X86_CC_G, 0x237, 0x3df, x86_l_3df);
x86_l_23d:
	/* 0x23d: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_23f:
	/* 0x23f: je     6bd <generic_usdt_actions+0x6bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23f, 0x6bd, x86_l_6bd);
x86_l_245:
	/* 0x245: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_248:
	/* 0x248: je     3f6 <generic_usdt_actions+0x3f6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x248, 0x3f6, x86_l_3f6);
x86_l_24e:
	/* 0x24e: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x24e, 0x1d4, x86_l_1d4);
x86_l_250:
	/* 0x250: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_253:
	/* 0x253: jg     2e4 <generic_usdt_actions+0x2e4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x253, 0x2e4, x86_l_2e4);
x86_l_259:
	/* 0x259: lea    eax,[rbx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_25c:
	/* 0x25c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25f:
	/* 0x25f: jb     51e <generic_usdt_actions+0x51e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x25f, 0x51e, x86_l_51e);
x86_l_265:
	/* 0x265: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_268:
	/* 0x268: je     614 <generic_usdt_actions+0x614> */
	X86_SIM_X86_JCC(X86_CC_E, 0x268, 0x614, x86_l_614);
x86_l_26e:
	/* 0x26e: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_271:
	/* 0x271: jne    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x271, 0x1d4, x86_l_1d4);
x86_l_277:
	/* 0x277: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_279:
	/* 0x279: mov    eax,DWORD PTR [r14+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_27e:
	/* 0x27e: jmp    5e3 <generic_usdt_actions+0x5e3> */
	X86_SIM_X86_JMP(0x27e, 0x5e3, x86_l_5e3);
x86_l_283:
	/* 0x283: lea    eax,[rbx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_286:
	/* 0x286: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_289:
	/* 0x289: jb     1c9 <generic_usdt_actions+0x1c9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x289, 0x1c9, x86_l_1c9);
x86_l_28f:
	/* 0x28f: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_292:
	/* 0x292: je     621 <generic_usdt_actions+0x621> */
	X86_SIM_X86_JCC(X86_CC_E, 0x292, 0x621, x86_l_621);
x86_l_298:
	/* 0x298: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_29b:
	/* 0x29b: jne    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29b, 0x1d4, x86_l_1d4);
x86_l_2a1:
	/* 0x2a1: lea    eax,[rbp+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2a4:
	/* 0x2a4: mov    eax,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_2a9:
	/* 0x2a9: add    ebp,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_2ac:
	/* 0x2ac: mov    r14d,DWORD PTR [r14+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_2b1:
	/* 0x2b1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ba:
	/* 0x2ba: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c3:
	/* 0x2c3: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2c6:
	/* 0x2c6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c9:
	/* 0x2c9: ja     2da <generic_usdt_actions+0x2da> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2c9, 0x2da, x86_l_2da);
x86_l_2cb:
	/* 0x2cb: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_2d4:
	/* 0x2d4: je     804 <generic_usdt_actions+0x804> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d4, 0x804, x86_l_804);
x86_l_2da:
	/* 0x2da: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2df:
	/* 0x2df: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x2df, 0x1d4, x86_l_1d4);
x86_l_2e4:
	/* 0x2e4: cmp    ebx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 12ULL);
x86_l_2e7:
	/* 0x2e7: je     77d <generic_usdt_actions+0x77d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e7, 0x77d, x86_l_77d);
x86_l_2ed:
	/* 0x2ed: cmp    ebx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 13ULL);
x86_l_2f0:
	/* 0x2f0: je     635 <generic_usdt_actions+0x635> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f0, 0x635, x86_l_635);
x86_l_2f6:
	/* 0x2f6: cmp    ebx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_2f9:
	/* 0x2f9: jne    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f9, 0x1d4, x86_l_1d4);
x86_l_2ff:
	/* 0x2ff: lea    eax,[rbp+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_302:
	/* 0x302: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_308:
	/* 0x308: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_30d:
	/* 0x30d: je     792 <generic_usdt_actions+0x792> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30d, 0x792, x86_l_792);
x86_l_313:
	/* 0x313: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_317:
	/* 0x317: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_319:
	/* 0x319: mov    eax,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_322:
	/* 0x322: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_324:
	/* 0x324: mov    r14d,DWORD PTR [r14+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_329:
	/* 0x329: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32c:
	/* 0x32c: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_333:
	/* 0x333: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_338:
	/* 0x338: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_33f:
	/* 0x33f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341:
	/* 0x341: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_347:
	/* 0x347: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34a:
	/* 0x34a: je     8ba <generic_usdt_actions+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34a, 0x8ba, x86_l_8ba);
x86_l_350:
	/* 0x350: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_354:
	/* 0x354: lea    rcx,[r14+r14*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 0ULL);
x86_l_358:
	/* 0x358: cmp    BYTE PTR [rax+rcx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 3), 2272037699587ULL);
x86_l_360:
	/* 0x360: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_365:
	/* 0x365: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36a:
	/* 0x36a: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36e:
	/* 0x36e: jne    d14 <generic_usdt_actions+0xd14> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x36e, 0xd14, x86_l_d14);
x86_l_374:
	/* 0x374: rorx   edx,DWORD PTR [rax+rcx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_37f:
	/* 0x37f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_382:
	/* 0x382: jle    b69 <generic_usdt_actions+0xb69> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x382, 0xb69, x86_l_b69);
x86_l_388:
	/* 0x388: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_38b:
	/* 0x38b: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_390:
	/* 0x390: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_393:
	/* 0x393: jle    bfc <generic_usdt_actions+0xbfc> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x393, 0xbfc, x86_l_bfc);
x86_l_399:
	/* 0x399: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_39c:
	/* 0x39c: jle    cc1 <generic_usdt_actions+0xcc1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x39c, 0xcc1, x86_l_cc1);
x86_l_3a2:
	/* 0x3a2: mov    rsi,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3aa:
	/* 0x3aa: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3ad:
	/* 0x3ad: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ad, 0xce0, x86_l_ce0);
x86_l_3b3:
	/* 0x3b3: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3bb:
	/* 0x3bb: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3be:
	/* 0x3be: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3be, 0xce0, x86_l_ce0);
x86_l_3c4:
	/* 0x3c4: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_3c9:
	/* 0x3c9: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3cc:
	/* 0x3cc: jne    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3cc, 0xce3, x86_l_ce3);
x86_l_3d2:
	/* 0x3d2: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3da:
	/* 0x3da: jmp    ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JMP(0x3da, 0xce0, x86_l_ce0);
x86_l_3df:
	/* 0x3df: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3e4:
	/* 0x3e4: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_3e7:
	/* 0x3e7: je     5e3 <generic_usdt_actions+0x5e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e7, 0x5e3, x86_l_5e3);
x86_l_3ed:
	/* 0x3ed: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_3f0:
	/* 0x3f0: jne    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f0, 0x1d4, x86_l_1d4);
x86_l_3f6:
	/* 0x3f6: lea    eax,[rbp+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f9:
	/* 0x3f9: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3fc:
	/* 0x3fc: mov    r14d,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_401:
	/* 0x401: add    ebp,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_404:
	/* 0x404: mov    eax,DWORD PTR [rcx+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_408:
	/* 0x408: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40d:
	/* 0x40d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_416:
	/* 0x416: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_41f:
	/* 0x41f: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_427:
	/* 0x427: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42c:
	/* 0x42c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_431:
	/* 0x431: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_438:
	/* 0x438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43a:
	/* 0x43a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43c:
	/* 0x43c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43f:
	/* 0x43f: je     8e3 <generic_usdt_actions+0x8e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43f, 0x8e3, x86_l_8e3);
x86_l_445:
	/* 0x445: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_449:
	/* 0x449: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_44d:
	/* 0x44d: ja     8e3 <generic_usdt_actions+0x8e3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x44d, 0x8e3, x86_l_8e3);
x86_l_453:
	/* 0x453: cmp    DWORD PTR [r13+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_45c:
	/* 0x45c: jne    8e3 <generic_usdt_actions+0x8e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45c, 0x8e3, x86_l_8e3);
x86_l_462:
	/* 0x462: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_467:
	/* 0x467: mov    rax,QWORD PTR [r13+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_46f:
	/* 0x46f: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_477:
	/* 0x477: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_47c:
	/* 0x47c: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_484:
	/* 0x484: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_488:
	/* 0x488: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_48d:
	/* 0x48d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f:
	/* 0x48f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_493:
	/* 0x493: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_498:
	/* 0x498: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_49b:
	/* 0x49b: jne    8cd <generic_usdt_actions+0x8cd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x49b, 0x8cd, x86_l_8cd);
x86_l_4a1:
	/* 0x4a1: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a6:
	/* 0x4a6: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4a9:
	/* 0x4a9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ac:
	/* 0x4ac: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4b1:
	/* 0x4b1: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_4b6:
	/* 0x4b6: ja     8e8 <generic_usdt_actions+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4b6, 0x8e8, x86_l_8e8);
x86_l_4bc:
	/* 0x4bc: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_4c5:
	/* 0x4c5: jne    8e8 <generic_usdt_actions+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4c5, 0x8e8, x86_l_8e8);
x86_l_4cb:
	/* 0x4cb: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_4d3:
	/* 0x4d3: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_4d8:
	/* 0x4d8: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_4dc:
	/* 0x4dc: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_4e3:
	/* 0x4e3: mov    esi,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_4eb:
	/* 0x4eb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f1:
	/* 0x4f1: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f5:
	/* 0x4f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fa:
	/* 0x4fa: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ff:
	/* 0x4ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_501:
	/* 0x501: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_503:
	/* 0x503: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_508:
	/* 0x508: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50d:
	/* 0x50d: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_514:
	/* 0x514: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_519:
	/* 0x519: jmp    5d0 <generic_usdt_actions+0x5d0> */
	X86_SIM_X86_JMP(0x519, 0x5d0, x86_l_5d0);
x86_l_51e:
	/* 0x51e: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_520:
	/* 0x520: mov    eax,DWORD PTR [r14+rbp*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_525:
	/* 0x525: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_528:
	/* 0x528: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52a:
	/* 0x52a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52d:
	/* 0x52d: ja     8e8 <generic_usdt_actions+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x52d, 0x8e8, x86_l_8e8);
x86_l_533:
	/* 0x533: cmp    DWORD PTR [r13+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_53c:
	/* 0x53c: jne    8e8 <generic_usdt_actions+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x53c, 0x8e8, x86_l_8e8);
x86_l_542:
	/* 0x542: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_54a:
	/* 0x54a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_54f:
	/* 0x54f: mov    rax,QWORD PTR [r13+rax*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 184ULL);
x86_l_557:
	/* 0x557: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55c:
	/* 0x55c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55f:
	/* 0x55f: je     8e8 <generic_usdt_actions+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x55f, 0x8e8, x86_l_8e8);
x86_l_565:
	/* 0x565: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_568:
	/* 0x568: jne    8f5 <generic_usdt_actions+0x8f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x568, 0x8f5, x86_l_8f5);
x86_l_56e:
	/* 0x56e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_573:
	/* 0x573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_575:
	/* 0x575: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57a:
	/* 0x57a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_57e:
	/* 0x57e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_582:
	/* 0x582: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_587:
	/* 0x587: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58c:
	/* 0x58c: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_593:
	/* 0x593: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_595:
	/* 0x595: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_597:
	/* 0x597: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59a:
	/* 0x59a: je     8e8 <generic_usdt_actions+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59a, 0x8e8, x86_l_8e8);
x86_l_5a0:
	/* 0x5a0: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a2:
	/* 0x5a2: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6:
	/* 0x5a6: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ab:
	/* 0x5ab: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5af:
	/* 0x5af: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b3:
	/* 0x5b3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b8:
	/* 0x5b8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ba:
	/* 0x5ba: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5bf:
	/* 0x5bf: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c4:
	/* 0x5c4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c9:
	/* 0x5c9: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_5d0:
	/* 0x5d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d2:
	/* 0x5d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d4:
	/* 0x5d4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d6:
	/* 0x5d6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5d8:
	/* 0x5d8: jne    1dd <generic_usdt_actions+0x1dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5d8, 0x1dd, x86_l_1dd);
x86_l_5de:
	/* 0x5de: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x5de, 0x1d4, x86_l_1d4);
x86_l_5e3:
	/* 0x5e3: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_5e9:
	/* 0x5e9: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5ee:
	/* 0x5ee: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f3:
	/* 0x5f3: je     d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f3, 0xd19, x86_l_d19);
x86_l_5f9:
	/* 0x5f9: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_5fc:
	/* 0x5fc: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_601:
	/* 0x601: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_604:
	/* 0x604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606:
	/* 0x606: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_609:
	/* 0x609: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_60f:
	/* 0x60f: jmp    d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JMP(0x60f, 0xd19, x86_l_d19);
x86_l_614:
	/* 0x614: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_61c:
	/* 0x61c: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x61c, 0x1d4, x86_l_1d4);
x86_l_621:
	/* 0x621: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_623:
	/* 0x623: mov    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_62b:
	/* 0x62b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_630:
	/* 0x630: jmp    d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JMP(0x630, 0xd19, x86_l_d19);
x86_l_635:
	/* 0x635: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_63a:
	/* 0x63a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c:
	/* 0x63c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_641:
	/* 0x641: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_646:
	/* 0x646: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_64b:
	/* 0x64b: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_652:
	/* 0x652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_654:
	/* 0x654: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_657:
	/* 0x657: je     1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x657, 0x1d4, x86_l_1d4);
x86_l_65d:
	/* 0x65d: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_662:
	/* 0x662: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_666:
	/* 0x666: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_66b:
	/* 0x66b: mov    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_673:
	/* 0x673: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_678:
	/* 0x678: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_67d:
	/* 0x67d: mov    r13,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_684:
	/* 0x684: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_687:
	/* 0x687: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_68a:
	/* 0x68a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68c:
	/* 0x68c: mov    DWORD PTR [rsp+0x54],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252865ULL);
x86_l_694:
	/* 0x694: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_697:
	/* 0x697: je     79e <generic_usdt_actions+0x79e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x697, 0x79e, x86_l_79e);
x86_l_69d:
	/* 0x69d: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6a0:
	/* 0x6a0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6a5:
	/* 0x6a5: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6aa:
	/* 0x6aa: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_6b1:
	/* 0x6b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b3:
	/* 0x6b3: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6b8:
	/* 0x6b8: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x6b8, 0x1d4, x86_l_1d4);
x86_l_6bd:
	/* 0x6bd: lea    eax,[rbp+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6c0:
	/* 0x6c0: mov    r12d,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6c5:
	/* 0x6c5: lea    eax,[rbp+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_6c8:
	/* 0x6c8: mov    r14d,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6cd:
	/* 0x6cd: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_6d2:
	/* 0x6d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d4:
	/* 0x6d4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d9:
	/* 0x6d9: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_6e1:
	/* 0x6e1: mov    QWORD PTR [rsp+0x90],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6e9:
	/* 0x6e9: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f1:
	/* 0x6f1: je     ae9 <generic_usdt_actions+0xae9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f1, 0xae9, x86_l_ae9);
x86_l_6f7:
	/* 0x6f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6fc:
	/* 0x6fc: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_703:
	/* 0x703: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_708:
	/* 0x708: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70a:
	/* 0x70a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_70d:
	/* 0x70d: je     ae9 <generic_usdt_actions+0xae9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70d, 0xae9, x86_l_ae9);
x86_l_713:
	/* 0x713: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_718:
	/* 0x718: mov    DWORD PTR [rsp+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71d:
	/* 0x71d: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_722:
	/* 0x722: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_727:
	/* 0x727: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_72c:
	/* 0x72c: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_733:
	/* 0x733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_735:
	/* 0x735: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_738:
	/* 0x738: mov    rax,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_73c:
	/* 0x73c: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73f:
	/* 0x73f: mov    rax,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_743:
	/* 0x743: mov    QWORD PTR [rsp+0x60],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_748:
	/* 0x748: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74c:
	/* 0x74c: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_750:
	/* 0x750: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_755:
	/* 0x755: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_75a:
	/* 0x75a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_75d:
	/* 0x75d: je     91c <generic_usdt_actions+0x91c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75d, 0x91c, x86_l_91c);
x86_l_763:
	/* 0x763: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_766:
	/* 0x766: je     918 <generic_usdt_actions+0x918> */
	X86_SIM_X86_JCC(X86_CC_E, 0x766, 0x918, x86_l_918);
x86_l_76c:
	/* 0x76c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_76e:
	/* 0x76e: jne    ae9 <generic_usdt_actions+0xae9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x76e, 0xae9, x86_l_ae9);
x86_l_774:
	/* 0x774: mov    eax,DWORD PTR [r13+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_778:
	/* 0x778: jmp    91c <generic_usdt_actions+0x91c> */
	X86_SIM_X86_JMP(0x778, 0x91c, x86_l_91c);
x86_l_77d:
	/* 0x77d: add    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_780:
	/* 0x780: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_788:
	/* 0x788: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_78d:
	/* 0x78d: jmp    d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JMP(0x78d, 0xd19, x86_l_d19);
x86_l_792:
	/* 0x792: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_797:
	/* 0x797: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_799:
	/* 0x799: jmp    d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JMP(0x799, 0xd19, x86_l_d19);
x86_l_79e:
	/* 0x79e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7a3:
	/* 0x7a3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7a8:
	/* 0x7a8: lea    rdx,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_7ad:
	/* 0x7ad: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_7b0:
	/* 0x7b0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_7b3:
	/* 0x7b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b5:
	/* 0x7b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b8:
	/* 0x7b8: mov    r13,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7bf:
	/* 0x7bf: je     6a0 <generic_usdt_actions+0x6a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bf, 0x6a0, x86_l_6a0);
x86_l_7c5:
	/* 0x7c5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_7c8:
	/* 0x7c8: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_7ca:
	/* 0x7ca: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7cf:
	/* 0x7cf: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_7d6:
	/* 0x7d6: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_7e0:
	/* 0x7e0: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_7e5:
	/* 0x7e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ea:
	/* 0x7ea: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ef:
	/* 0x7ef: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_7f2:
	/* 0x7f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f4:
	/* 0x7f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f7:
	/* 0x7f7: je     bab <generic_usdt_actions+0xbab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f7, 0xbab, x86_l_bab);
x86_l_7fd:
	/* 0x7fd: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7ff:
	/* 0x7ff: jmp    bcb <generic_usdt_actions+0xbcb> */
	X86_SIM_X86_JMP(0x7ff, 0xbcb, x86_l_bcb);
x86_l_804:
	/* 0x804: mov    rax,QWORD PTR [r13+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_80c:
	/* 0x80c: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_811:
	/* 0x811: mov    eax,DWORD PTR [r13+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_819:
	/* 0x819: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81d:
	/* 0x81d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_822:
	/* 0x822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_824:
	/* 0x824: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_828:
	/* 0x828: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82d:
	/* 0x82d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_832:
	/* 0x832: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_837:
	/* 0x837: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_83e:
	/* 0x83e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_840:
	/* 0x840: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_843:
	/* 0x843: je     2da <generic_usdt_actions+0x2da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x843, 0x2da, x86_l_2da);
x86_l_849:
	/* 0x849: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_84d:
	/* 0x84d: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_851:
	/* 0x851: ja     2da <generic_usdt_actions+0x2da> */
	X86_SIM_X86_JCC(X86_CC_A, 0x851, 0x2da, x86_l_2da);
x86_l_857:
	/* 0x857: cmp    DWORD PTR [r13+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_860:
	/* 0x860: jne    2da <generic_usdt_actions+0x2da> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x860, 0x2da, x86_l_2da);
x86_l_866:
	/* 0x866: mov    rcx,QWORD PTR [r13+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_86e:
	/* 0x86e: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_876:
	/* 0x876: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_87c:
	/* 0x87c: mov    ecx,DWORD PTR [r13+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_884:
	/* 0x884: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_888:
	/* 0x888: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_88b:
	/* 0x88b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_890:
	/* 0x890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_892:
	/* 0x892: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_896:
	/* 0x896: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89b:
	/* 0x89b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8a0:
	/* 0x8a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a2:
	/* 0x8a2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a7:
	/* 0x8a7: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_8ae:
	/* 0x8ae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_8b1:
	/* 0x8b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b3:
	/* 0x8b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b5:
	/* 0x8b5: jmp    2da <generic_usdt_actions+0x2da> */
	X86_SIM_X86_JMP(0x8b5, 0x2da, x86_l_2da);
x86_l_8ba:
	/* 0x8ba: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8bf:
	/* 0x8bf: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c4:
	/* 0x8c4: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8c8:
	/* 0x8c8: jmp    d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JMP(0x8c8, 0xd19, x86_l_d19);
x86_l_8cd:
	/* 0x8cd: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8d2:
	/* 0x8d2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d7:
	/* 0x8d7: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_8de:
	/* 0x8de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e0:
	/* 0x8e0: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8e3:
	/* 0x8e3: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8e8:
	/* 0x8e8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_8ea:
	/* 0x8ea: jne    1dd <generic_usdt_actions+0x1dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8ea, 0x1dd, x86_l_1dd);
x86_l_8f0:
	/* 0x8f0: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x8f0, 0x1d4, x86_l_1d4);
x86_l_8f5:
	/* 0x8f5: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8fa:
	/* 0x8fa: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ff:
	/* 0x8ff: mov    rdi,QWORD PTR [rip+0x22dc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_906:
	/* 0x906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_908:
	/* 0x908: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_90b:
	/* 0x90b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_90d:
	/* 0x90d: jne    1dd <generic_usdt_actions+0x1dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x90d, 0x1dd, x86_l_1dd);
x86_l_913:
	/* 0x913: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0x913, 0x1d4, x86_l_1d4);
x86_l_918:
	/* 0x918: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91c:
	/* 0x91c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_91e:
	/* 0x91e: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_923:
	/* 0x923: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_925:
	/* 0x925: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_92a:
	/* 0x92a: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92e:
	/* 0x92e: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_932:
	/* 0x932: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_937:
	/* 0x937: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_93c:
	/* 0x93c: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_941:
	/* 0x941: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_946:
	/* 0x946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_948:
	/* 0x948: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94b:
	/* 0x94b: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_950:
	/* 0x950: jmp    965 <generic_usdt_actions+0x965> */
	X86_SIM_X86_JMP(0x950, 0x965, x86_l_965);
x86_l_952:
	/* 0x952: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_957:
	/* 0x957: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_95b:
	/* 0x95b: cmp    r14,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 20ULL);
x86_l_95f:
	/* 0x95f: je     a95 <generic_usdt_actions+0xa95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95f, 0xa95, x86_l_a95);
x86_l_965:
	/* 0x965: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_96d:
	/* 0x96d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_972:
	/* 0x972: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_979:
	/* 0x979: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97e:
	/* 0x97e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_981:
	/* 0x981: je     a95 <generic_usdt_actions+0xa95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x981, 0xa95, x86_l_a95);
x86_l_987:
	/* 0x987: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_98a:
	/* 0x98a: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_991:
	/* 0x991: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_996:
	/* 0x996: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_99d:
	/* 0x99d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99f:
	/* 0x99f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a2:
	/* 0x9a2: je     a95 <generic_usdt_actions+0xa95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a2, 0xa95, x86_l_a95);
x86_l_9a8:
	/* 0x9a8: cmp    DWORD PTR [rax+r14*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 279172874239ULL);
x86_l_9ae:
	/* 0x9ae: je     a95 <generic_usdt_actions+0xa95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ae, 0xa95, x86_l_a95);
x86_l_9b4:
	/* 0x9b4: mov    rax,QWORD PTR [r13+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_9bc:
	/* 0x9bc: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9c0:
	/* 0x9c0: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_9c3:
	/* 0x9c3: jge    a95 <generic_usdt_actions+0xa95> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x9c3, 0xa95, x86_l_a95);
x86_l_9c9:
	/* 0x9c9: cmp    r14,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 16ULL);
x86_l_9cd:
	/* 0x9cd: je     a2f <generic_usdt_actions+0xa2f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9cd, 0xa2f, x86_l_a2f);
x86_l_9cf:
	/* 0x9cf: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_9d7:
	/* 0x9d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9dc:
	/* 0x9dc: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9e3:
	/* 0x9e3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_9e6:
	/* 0x9e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e8:
	/* 0x9e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9eb:
	/* 0x9eb: je     a27 <generic_usdt_actions+0xa27> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9eb, 0xa27, x86_l_a27);
x86_l_9ed:
	/* 0x9ed: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9f0:
	/* 0x9f0: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_9f7:
	/* 0x9f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9fc:
	/* 0x9fc: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_a03:
	/* 0xa03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a05:
	/* 0xa05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a08:
	/* 0xa08: je     a27 <generic_usdt_actions+0xa27> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa08, 0xa27, x86_l_a27);
x86_l_a0a:
	/* 0xa0a: cmp    DWORD PTR [rax+r14*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 296352743423ULL);
x86_l_a10:
	/* 0xa10: mov    rax,QWORD PTR [r13+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_a18:
	/* 0xa18: je     a2f <generic_usdt_actions+0xa2f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa18, 0xa2f, x86_l_a2f);
x86_l_a1a:
	/* 0xa1a: mov    r12d,DWORD PTR [r13+r14*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 1), 24192ULL);
x86_l_a22:
	/* 0xa22: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a25:
	/* 0xa25: jmp    a3a <generic_usdt_actions+0xa3a> */
	X86_SIM_X86_JMP(0xa25, 0xa3a, x86_l_a3a);
x86_l_a27:
	/* 0xa27: mov    rax,QWORD PTR [r13+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_a2f:
	/* 0xa2f: mov    r12d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a33:
	/* 0xa33: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a36:
	/* 0xa36: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_a3a:
	/* 0xa3a: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_a3d:
	/* 0xa3d: jle    952 <generic_usdt_actions+0x952> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xa3d, 0x952, x86_l_952);
x86_l_a43:
	/* 0xa43: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_a48:
	/* 0xa48: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_a4d:
	/* 0xa4d: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_a51:
	/* 0xa51: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_a56:
	/* 0xa56: cmovge r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_a5a:
	/* 0xa5a: movzx  r13d,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_a60:
	/* 0xa60: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a65:
	/* 0xa65: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_a69:
	/* 0xa69: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a6e:
	/* 0xa6e: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a72:
	/* 0xa72: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a79:
	/* 0xa79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a7e:
	/* 0xa7e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_a81:
	/* 0xa81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a83:
	/* 0xa83: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a86:
	/* 0xa86: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a8b:
	/* 0xa8b: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a90:
	/* 0xa90: jmp    952 <generic_usdt_actions+0x952> */
	X86_SIM_X86_JMP(0xa90, 0x952, x86_l_952);
x86_l_a95:
	/* 0xa95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9a:
	/* 0xa9a: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_aa1:
	/* 0xaa1: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_aa6:
	/* 0xaa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa8:
	/* 0xaa8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aab:
	/* 0xaab: je     acd <generic_usdt_actions+0xacd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaab, 0xacd, x86_l_acd);
x86_l_aad:
	/* 0xaad: imul   rcx,QWORD PTR [rsp+0x90],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 618474290624ULL);
x86_l_ab9:
	/* 0xab9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_abe:
	/* 0xabe: cmp    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac1:
	/* 0xac1: jbe    acd <generic_usdt_actions+0xacd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xac1, 0xacd, x86_l_acd);
x86_l_ac3:
	/* 0xac3: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_acb:
	/* 0xacb: jmp    ae9 <generic_usdt_actions+0xae9> */
	X86_SIM_X86_JMP(0xacb, 0xae9, x86_l_ae9);
x86_l_acd:
	/* 0xacd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ad2:
	/* 0xad2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad4:
	/* 0xad4: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_adb:
	/* 0xadb: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae0:
	/* 0xae0: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ae5:
	/* 0xae5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae7:
	/* 0xae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae9:
	/* 0xae9: lea    eax,[rbp+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_aec:
	/* 0xaec: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_af1:
	/* 0xaf1: cmp    DWORD PTR [r14+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_af7:
	/* 0xaf7: je     b1c <generic_usdt_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf7, 0xb1c, x86_l_b1c);
x86_l_af9:
	/* 0xaf9: or     BYTE PTR [r13+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_afe:
	/* 0xafe: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b03:
	/* 0xb03: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b05:
	/* 0xb05: mov    rsi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b0c:
	/* 0xb0c: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b11:
	/* 0xb11: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b13:
	/* 0xb13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b15:
	/* 0xb15: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b1c:
	/* 0xb1c: lea    eax,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b1f:
	/* 0xb1f: cmp    DWORD PTR [r14+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_b25:
	/* 0xb25: je     b50 <generic_usdt_actions+0xb50> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb25, 0xb50, x86_l_b50);
x86_l_b27:
	/* 0xb27: or     BYTE PTR [r13+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_b2c:
	/* 0xb2c: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b31:
	/* 0xb31: mov    rsi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b38:
	/* 0xb38: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_b3d:
	/* 0xb3d: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b42:
	/* 0xb42: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_b47:
	/* 0xb47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b49:
	/* 0xb49: mov    QWORD PTR [r13+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b50:
	/* 0xb50: add    ebp,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_b53:
	/* 0xb53: cmp    DWORD PTR [r14+rbp*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 17179869184ULL);
x86_l_b59:
	/* 0xb59: je     1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb59, 0x1d4, x86_l_1d4);
x86_l_b5f:
	/* 0xb5f: or     BYTE PTR [r13+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_b64:
	/* 0xb64: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0xb64, 0x1d4, x86_l_1d4);
x86_l_b69:
	/* 0xb69: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_b6c:
	/* 0xb6c: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b71:
	/* 0xb71: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_b74:
	/* 0xb74: jg     c2d <generic_usdt_actions+0xc2d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb74, 0xc2d, x86_l_c2d);
x86_l_b7a:
	/* 0xb7a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b7d:
	/* 0xb7d: jg     c7f <generic_usdt_actions+0xc7f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb7d, 0xc7f, x86_l_c7f);
x86_l_b83:
	/* 0xb83: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b88:
	/* 0xb88: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b8a:
	/* 0xb8a: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb8a, 0xce0, x86_l_ce0);
x86_l_b90:
	/* 0xb90: mov    rsi,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b98:
	/* 0xb98: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_b9d:
	/* 0xb9d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_ba0:
	/* 0xba0: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba0, 0xce0, x86_l_ce0);
x86_l_ba6:
	/* 0xba6: jmp    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JMP(0xba6, 0xce3, x86_l_ce3);
x86_l_bab:
	/* 0xbab: mov    DWORD PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_bb3:
	/* 0xbb3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bb8:
	/* 0xbb8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bba:
	/* 0xbba: lea    rdx,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_bbf:
	/* 0xbbf: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc4:
	/* 0xbc4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_bc7:
	/* 0xbc7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc9:
	/* 0xbc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcb:
	/* 0xbcb: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_bce:
	/* 0xbce: je     6a0 <generic_usdt_actions+0x6a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbce, 0x6a0, x86_l_6a0);
x86_l_bd4:
	/* 0xbd4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bd9:
	/* 0xbd9: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bde:
	/* 0xbde: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_be5:
	/* 0xbe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be7:
	/* 0xbe7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bea:
	/* 0xbea: je     6a0 <generic_usdt_actions+0x6a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbea, 0x6a0, x86_l_6a0);
x86_l_bf0:
	/* 0xbf0: mov    ecx,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_bf4:
	/* 0xbf4: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_bf7:
	/* 0xbf7: jmp    6a0 <generic_usdt_actions+0x6a0> */
	X86_SIM_X86_JMP(0xbf7, 0x6a0, x86_l_6a0);
x86_l_bfc:
	/* 0xbfc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_bff:
	/* 0xbff: jg     c5e <generic_usdt_actions+0xc5e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbff, 0xc5e, x86_l_c5e);
x86_l_c01:
	/* 0xc01: mov    rsi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_c09:
	/* 0xc09: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c0c:
	/* 0xc0c: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc0c, 0xce0, x86_l_ce0);
x86_l_c12:
	/* 0xc12: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c1a:
	/* 0xc1a: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_c1f:
	/* 0xc1f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_c22:
	/* 0xc22: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc22, 0xce0, x86_l_ce0);
x86_l_c28:
	/* 0xc28: jmp    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JMP(0xc28, 0xce3, x86_l_ce3);
x86_l_c2d:
	/* 0xc2d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_c30:
	/* 0xc30: jg     ca0 <generic_usdt_actions+0xca0> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc30, 0xca0, x86_l_ca0);
x86_l_c32:
	/* 0xc32: mov    rsi,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_c3a:
	/* 0xc3a: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_c3d:
	/* 0xc3d: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3d, 0xce0, x86_l_ce0);
x86_l_c43:
	/* 0xc43: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c4b:
	/* 0xc4b: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_c50:
	/* 0xc50: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_c53:
	/* 0xc53: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc53, 0xce0, x86_l_ce0);
x86_l_c59:
	/* 0xc59: jmp    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JMP(0xc59, 0xce3, x86_l_ce3);
x86_l_c5e:
	/* 0xc5e: mov    rsi,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_c66:
	/* 0xc66: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_c69:
	/* 0xc69: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc69, 0xce0, x86_l_ce0);
x86_l_c6b:
	/* 0xc6b: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c73:
	/* 0xc73: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_c78:
	/* 0xc78: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_c7b:
	/* 0xc7b: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7b, 0xce0, x86_l_ce0);
x86_l_c7d:
	/* 0xc7d: jmp    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JMP(0xc7d, 0xce3, x86_l_ce3);
x86_l_c7f:
	/* 0xc7f: mov    rsi,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_c87:
	/* 0xc87: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c8a:
	/* 0xc8a: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8a, 0xce0, x86_l_ce0);
x86_l_c8c:
	/* 0xc8c: mov    rsi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_c94:
	/* 0xc94: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_c99:
	/* 0xc99: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_c9c:
	/* 0xc9c: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9c, 0xce0, x86_l_ce0);
x86_l_c9e:
	/* 0xc9e: jmp    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JMP(0xc9e, 0xce3, x86_l_ce3);
x86_l_ca0:
	/* 0xca0: mov    rsi,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_ca8:
	/* 0xca8: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_cab:
	/* 0xcab: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcab, 0xce0, x86_l_ce0);
x86_l_cad:
	/* 0xcad: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_cb5:
	/* 0xcb5: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_cba:
	/* 0xcba: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_cbd:
	/* 0xcbd: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcbd, 0xce0, x86_l_ce0);
x86_l_cbf:
	/* 0xcbf: jmp    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JMP(0xcbf, 0xce3, x86_l_ce3);
x86_l_cc1:
	/* 0xcc1: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_cc9:
	/* 0xcc9: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_ccc:
	/* 0xccc: je     ce0 <generic_usdt_actions+0xce0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xccc, 0xce0, x86_l_ce0);
x86_l_cce:
	/* 0xcce: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_cd6:
	/* 0xcd6: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_cdb:
	/* 0xcdb: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_cde:
	/* 0xcde: jne    ce3 <generic_usdt_actions+0xce3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcde, 0xce3, x86_l_ce3);
x86_l_ce0:
	/* 0xce0: mov    rdi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce3:
	/* 0xce3: lea    rax,[rax+rcx*8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 0ULL);
x86_l_ce7:
	/* 0xce7: add    rax,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_ced:
	/* 0xced: add    rdi,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_cf0:
	/* 0xcf0: mov    DWORD PTR [rsp+0x8],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf5:
	/* 0xcf5: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_cfa:
	/* 0xcfa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cff:
	/* 0xcff: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_d02:
	/* 0xd02: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d07:
	/* 0xd07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d09:
	/* 0xd09: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_d0c:
	/* 0xd0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d0e:
	/* 0xd0e: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d12:
	/* 0xd12: je     d19 <generic_usdt_actions+0xd19> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd12, 0xd19, x86_l_d19);
x86_l_d14:
	/* 0xd14: or     BYTE PTR [r13+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_d19:
	/* 0xd19: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d21:
	/* 0xd21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d26:
	/* 0xd26: mov    rdi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_d2d:
	/* 0xd2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2f:
	/* 0xd2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d32:
	/* 0xd32: je     d39 <generic_usdt_actions+0xd39> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd32, 0xd39, x86_l_d39);
x86_l_d34:
	/* 0xd34: inc QWORD PTR [rax+r12*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R12, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d39:
	/* 0xd39: jmp    1d4 <generic_usdt_actions+0x1d4> */
	X86_SIM_X86_JMP(0xd39, 0x1d4, x86_l_1d4);
x86_l_d3e:
	/* 0xd3e: cmp    BYTE PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_d43:
	/* 0xd43: je     d62 <generic_usdt_actions+0xd62> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd43, 0xd62, x86_l_d62);
x86_l_d45:
	/* 0xd45: mov    rsi,QWORD PTR [rip+0x22dce] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_d4c:
	/* 0xd4c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d51:
	/* 0xd51: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d56:
	/* 0xd56: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d5b:
	/* 0xd5b: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d60:
	/* 0xd60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d62:
	/* 0xd62: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d64:
	/* 0xd64: add    rsp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_d6b:
	/* 0xd6b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_d6c:
	/* 0xd6c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_d6e:
	/* 0xd6e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_d70:
	/* 0xd70: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_d72:
	/* 0xd72: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_d74:
	/* 0xd74: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_d75:
	/* 0xd75: jmp    d7a <generic_usdt_actions+0xd7a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_d7a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
