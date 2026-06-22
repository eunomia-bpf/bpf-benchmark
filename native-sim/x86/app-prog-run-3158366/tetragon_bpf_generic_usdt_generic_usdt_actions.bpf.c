extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char stack_trace_map;
extern char tg_errmetrics_map;
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_generic_usdt_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     1178 <generic_usdt_actions+0x1178> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31, 0x1178, x86_l_1178);
x86_l_37:
	/* 0x37: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r13d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_41:
	/* 0x41: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_45:
	/* 0x45: jl     1178 <generic_usdt_actions+0x1178> */
	X86_SIM_X86_JCC(X86_CC_L, 0x45, 0x1178, x86_l_1178);
x86_l_4b:
	/* 0x4b: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_52:
	/* 0x52: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
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
	/* 0x63: je     1178 <generic_usdt_actions+0x1178> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0x1178, x86_l_1178);
x86_l_69:
	/* 0x69: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_6c:
	/* 0x6c: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_72:
	/* 0x72: add    r13d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_76:
	/* 0x76: mov    DWORD PTR [rsp+0x104],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_81:
	/* 0x81: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_88:
	/* 0x88: lea    rsi,[rsp+0x104] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 260ULL);
x86_l_90:
	/* 0x90: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_98:
	/* 0x98: and    r13d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_9f:
	/* 0x9f: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a2:
	/* 0xa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4:
	/* 0xa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: je     d4 <generic_usdt_actions+0xd4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7, 0xd4, x86_l_d4);
x86_l_a9:
	/* 0xa9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac:
	/* 0xac: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af:
	/* 0xaf: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_b3:
	/* 0xb3: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_b6:
	/* 0xb6: xor    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 3ULL);
x86_l_ba:
	/* 0xba: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: xor    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_c1:
	/* 0xc1: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: xor    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_c8:
	/* 0xc8: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cd:
	/* 0xcd: ja     f1 <generic_usdt_actions+0xf1> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcd, 0xf1, x86_l_f1);
x86_l_cf:
	/* 0xcf: jmp    115d <generic_usdt_actions+0x115d> */
	X86_SIM_X86_JMP(0xcf, 0x115d, x86_l_115d);
x86_l_d4:
	/* 0xd4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d9:
	/* 0xd9: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_de:
	/* 0xde: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_e1:
	/* 0xe1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e6:
	/* 0xe6: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_eb:
	/* 0xeb: jbe    115d <generic_usdt_actions+0x115d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xeb, 0x115d, x86_l_115d);
x86_l_f1:
	/* 0xf1: mov    QWORD PTR [rsp+0xf8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_101:
	/* 0x101: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_106:
	/* 0x106: lea    rax,[rbx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_115:
	/* 0x115: lea    rax,[rbx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11c:
	/* 0x11c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_124:
	/* 0x124: lea    rax,[rbx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_130:
	/* 0x130: lea    rax,[rbx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_134:
	/* 0x134: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13c:
	/* 0x13c: lea    rax,[rbx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_140:
	/* 0x140: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_148:
	/* 0x148: lea    rax,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14c:
	/* 0x14c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_154:
	/* 0x154: lea    rax,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_158:
	/* 0x158: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_160:
	/* 0x160: lea    rax,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_164:
	/* 0x164: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16c:
	/* 0x16c: lea    rax,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_178:
	/* 0x178: lea    rax,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17c:
	/* 0x17c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_184:
	/* 0x184: lea    rax,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_190:
	/* 0x190: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_194:
	/* 0x194: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_199:
	/* 0x199: lea    rax,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19d:
	/* 0x19d: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1a5:
	/* 0x1a5: movsxd rbp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_1a9:
	/* 0x1a9: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b1:
	/* 0x1b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b6:
	/* 0x1b6: lea    rcx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ba:
	/* 0x1ba: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1bf:
	/* 0x1bf: lea    rcx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c3:
	/* 0x1c3: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1cb:
	/* 0x1cb: lea    rcx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf:
	/* 0x1cf: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d7:
	/* 0x1d7: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1de:
	/* 0x1de: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e3:
	/* 0x1e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5:
	/* 0x1e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: je     21f <generic_usdt_actions+0x21f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e8, 0x21f, x86_l_21f);
x86_l_1ea:
	/* 0x1ea: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1ed:
	/* 0x1ed: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f0:
	/* 0x1f0: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1f2:
	/* 0x1f2: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f6:
	/* 0x1f6: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_1f9:
	/* 0x1f9: jg     22d <generic_usdt_actions+0x22d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1f9, 0x22d, x86_l_22d);
x86_l_1fb:
	/* 0x1fb: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1fe:
	/* 0x1fe: jg     25f <generic_usdt_actions+0x25f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1fe, 0x25f, x86_l_25f);
x86_l_200:
	/* 0x200: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_203:
	/* 0x203: jg     450 <generic_usdt_actions+0x450> */
	X86_SIM_X86_JCC(X86_CC_G, 0x203, 0x450, x86_l_450);
x86_l_209:
	/* 0x209: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_20b:
	/* 0x20b: je     583 <generic_usdt_actions+0x583> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20b, 0x583, x86_l_583);
x86_l_211:
	/* 0x211: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_214:
	/* 0x214: je     45e <generic_usdt_actions+0x45e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x214, 0x45e, x86_l_45e);
x86_l_21a:
	/* 0x21a: jmp    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JMP(0x21a, 0x8ff, x86_l_8ff);
x86_l_21f:
	/* 0x21f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222:
	/* 0x222: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_224:
	/* 0x224: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_228:
	/* 0x228: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x228, 0x906, x86_l_906);
x86_l_22d:
	/* 0x22d: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_230:
	/* 0x230: jg     361 <generic_usdt_actions+0x361> */
	X86_SIM_X86_JCC(X86_CC_G, 0x230, 0x361, x86_l_361);
x86_l_236:
	/* 0x236: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_239:
	/* 0x239: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23c:
	/* 0x23c: jb     4d8 <generic_usdt_actions+0x4d8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x23c, 0x4d8, x86_l_4d8);
x86_l_242:
	/* 0x242: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_245:
	/* 0x245: je     4e3 <generic_usdt_actions+0x4e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x245, 0x4e3, x86_l_4e3);
x86_l_24b:
	/* 0x24b: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_24e:
	/* 0x24e: jne    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24e, 0x8ff, x86_l_8ff);
x86_l_254:
	/* 0x254: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_25a:
	/* 0x25a: jmp    4c1 <generic_usdt_actions+0x4c1> */
	X86_SIM_X86_JMP(0x25a, 0x4c1, x86_l_4c1);
x86_l_25f:
	/* 0x25f: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_262:
	/* 0x262: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_265:
	/* 0x265: jb     4d0 <generic_usdt_actions+0x4d0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x265, 0x4d0, x86_l_4d0);
x86_l_26b:
	/* 0x26b: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_26e:
	/* 0x26e: je     4f3 <generic_usdt_actions+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26e, 0x4f3, x86_l_4f3);
x86_l_274:
	/* 0x274: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_277:
	/* 0x277: jne    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x277, 0x8ff, x86_l_8ff);
x86_l_27d:
	/* 0x27d: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_281:
	/* 0x281: mov    r15d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_285:
	/* 0x285: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_28e:
	/* 0x28e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_297:
	/* 0x297: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_29a:
	/* 0x29a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d:
	/* 0x29d: ja     4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29d, 0x4b6, x86_l_4b6);
x86_l_2a3:
	/* 0x2a3: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_2ac:
	/* 0x2ac: jne    4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ac, 0x4b6, x86_l_4b6);
x86_l_2b2:
	/* 0x2b2: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_2ba:
	/* 0x2ba: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2bf:
	/* 0x2bf: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_2c7:
	/* 0x2c7: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cb:
	/* 0x2cb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2d0:
	/* 0x2d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2:
	/* 0x2d2: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2d6:
	/* 0x2d6: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db:
	/* 0x2db: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2e2:
	/* 0x2e2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e7:
	/* 0x2e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ec:
	/* 0x2ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee:
	/* 0x2ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f1:
	/* 0x2f1: je     4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f1, 0x4b6, x86_l_4b6);
x86_l_2f7:
	/* 0x2f7: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2fb:
	/* 0x2fb: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2ff:
	/* 0x2ff: ja     4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2ff, 0x4b6, x86_l_4b6);
x86_l_305:
	/* 0x305: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_30e:
	/* 0x30e: jne    4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30e, 0x4b6, x86_l_4b6);
x86_l_314:
	/* 0x314: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_31c:
	/* 0x31c: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_324:
	/* 0x324: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_32a:
	/* 0x32a: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_332:
	/* 0x332: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_336:
	/* 0x336: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_339:
	/* 0x339: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_33e:
	/* 0x33e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340:
	/* 0x340: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_349:
	/* 0x349: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_350:
	/* 0x350: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_352:
	/* 0x352: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_357:
	/* 0x357: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35c:
	/* 0x35c: jmp    6be <generic_usdt_actions+0x6be> */
	X86_SIM_X86_JMP(0x35c, 0x6be, x86_l_6be);
x86_l_361:
	/* 0x361: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_364:
	/* 0x364: je     5e8 <generic_usdt_actions+0x5e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x364, 0x5e8, x86_l_5e8);
x86_l_36a:
	/* 0x36a: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_36d:
	/* 0x36d: je     50b <generic_usdt_actions+0x50b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36d, 0x50b, x86_l_50b);
x86_l_373:
	/* 0x373: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_376:
	/* 0x376: jne    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x376, 0x8ff, x86_l_8ff);
x86_l_37c:
	/* 0x37c: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_382:
	/* 0x382: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_385:
	/* 0x385: je     600 <generic_usdt_actions+0x600> */
	X86_SIM_X86_JCC(X86_CC_E, 0x385, 0x600, x86_l_600);
x86_l_38b:
	/* 0x38b: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38f:
	/* 0x38f: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_394:
	/* 0x394: mov    eax,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_398:
	/* 0x398: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_39c:
	/* 0x39c: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_39f:
	/* 0x39f: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_3a6:
	/* 0x3a6: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_3ad:
	/* 0x3ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b2:
	/* 0x3b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4:
	/* 0x3b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b7:
	/* 0x3b7: je     731 <generic_usdt_actions+0x731> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b7, 0x731, x86_l_731);
x86_l_3bd:
	/* 0x3bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c2:
	/* 0x3c2: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c7:
	/* 0x3c7: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3cc:
	/* 0x3cc: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3cf:
	/* 0x3cf: lea    rdx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_3d3:
	/* 0x3d3: cmp    BYTE PTR [rax+rdx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 3), 2272037699587ULL);
x86_l_3db:
	/* 0x3db: jne    8d0 <generic_usdt_actions+0x8d0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3db, 0x8d0, x86_l_8d0);
x86_l_3e1:
	/* 0x3e1: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_3e5:
	/* 0x3e5: add    rcx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_3ec:
	/* 0x3ec: rorx   eax,DWORD PTR [rax+rdx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_3f7:
	/* 0x3f7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f9:
	/* 0x3f9: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_3fc:
	/* 0x3fc: jle    769 <generic_usdt_actions+0x769> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3fc, 0x769, x86_l_769);
x86_l_402:
	/* 0x402: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_405:
	/* 0x405: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_409:
	/* 0x409: jle    7f7 <generic_usdt_actions+0x7f7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x409, 0x7f7, x86_l_7f7);
x86_l_40f:
	/* 0x40f: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_412:
	/* 0x412: jle    892 <generic_usdt_actions+0x892> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x412, 0x892, x86_l_892);
x86_l_418:
	/* 0x418: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_420:
	/* 0x420: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_423:
	/* 0x423: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x423, 0x8ac, x86_l_8ac);
x86_l_429:
	/* 0x429: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_431:
	/* 0x431: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_434:
	/* 0x434: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x434, 0x8ac, x86_l_8ac);
x86_l_43a:
	/* 0x43a: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_43d:
	/* 0x43d: jne    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43d, 0x8af, x86_l_8af);
x86_l_443:
	/* 0x443: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_44b:
	/* 0x44b: jmp    8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JMP(0x44b, 0x8ac, x86_l_8ac);
x86_l_450:
	/* 0x450: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_453:
	/* 0x453: je     4c1 <generic_usdt_actions+0x4c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x453, 0x4c1, x86_l_4c1);
x86_l_455:
	/* 0x455: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_458:
	/* 0x458: jne    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x458, 0x8ff, x86_l_8ff);
x86_l_45e:
	/* 0x45e: mov    r15d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_462:
	/* 0x462: mov    eax,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_466:
	/* 0x466: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47d:
	/* 0x47d: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_485:
	/* 0x485: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_48c:
	/* 0x48c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_491:
	/* 0x491: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_496:
	/* 0x496: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_498:
	/* 0x498: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49b:
	/* 0x49b: je     4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49b, 0x4b6, x86_l_4b6);
x86_l_49d:
	/* 0x49d: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4a1:
	/* 0x4a1: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4a5:
	/* 0x4a5: ja     4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a5, 0x4b6, x86_l_4b6);
x86_l_4a7:
	/* 0x4a7: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_4b0:
	/* 0x4b0: je     60f <generic_usdt_actions+0x60f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b0, 0x60f, x86_l_60f);
x86_l_4b6:
	/* 0x4b6: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_4bc:
	/* 0x4bc: jmp    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JMP(0x4bc, 0x8ff, x86_l_8ff);
x86_l_4c1:
	/* 0x4c1: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c6:
	/* 0x4c6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4cb:
	/* 0x4cb: jmp    8d5 <generic_usdt_actions+0x8d5> */
	X86_SIM_X86_JMP(0x4cb, 0x8d5, x86_l_8d5);
x86_l_4d0:
	/* 0x4d0: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d4:
	/* 0x4d4: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4d8:
	/* 0x4d8: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4de:
	/* 0x4de: jmp    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JMP(0x4de, 0x8ff, x86_l_8ff);
x86_l_4e3:
	/* 0x4e3: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_4eb:
	/* 0x4eb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ee:
	/* 0x4ee: jmp    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JMP(0x4ee, 0x8ff, x86_l_8ff);
x86_l_4f3:
	/* 0x4f3: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4f9:
	/* 0x4f9: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_501:
	/* 0x501: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_506:
	/* 0x506: jmp    8d5 <generic_usdt_actions+0x8d5> */
	X86_SIM_X86_JMP(0x506, 0x8d5, x86_l_8d5);
x86_l_50b:
	/* 0x50b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_510:
	/* 0x510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512:
	/* 0x512: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_517:
	/* 0x517: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_51e:
	/* 0x51e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_523:
	/* 0x523: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_528:
	/* 0x528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a:
	/* 0x52a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52d:
	/* 0x52d: je     8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52d, 0x8ff, x86_l_8ff);
x86_l_533:
	/* 0x533: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_537:
	/* 0x537: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_53c:
	/* 0x53c: mov    DWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_544:
	/* 0x544: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_54b:
	/* 0x54b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_550:
	/* 0x550: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_555:
	/* 0x555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_557:
	/* 0x557: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_55f:
	/* 0x55f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_562:
	/* 0x562: je     6ca <generic_usdt_actions+0x6ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x562, 0x6ca, x86_l_6ca);
x86_l_568:
	/* 0x568: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_56b:
	/* 0x56b: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_572:
	/* 0x572: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_577:
	/* 0x577: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_57c:
	/* 0x57c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e:
	/* 0x57e: jmp    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JMP(0x57e, 0x8ff, x86_l_8ff);
x86_l_583:
	/* 0x583: cmp    DWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_588:
	/* 0x588: je     5ab <generic_usdt_actions+0x5ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x588, 0x5ab, x86_l_5ab);
x86_l_58a:
	/* 0x58a: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_58f:
	/* 0x58f: mov    rsi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_596:
	/* 0x596: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_598:
	/* 0x598: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_59d:
	/* 0x59d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5a0:
	/* 0x5a0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a2:
	/* 0x5a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a4:
	/* 0x5a4: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5ab:
	/* 0x5ab: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_5b1:
	/* 0x5b1: cmp    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5b6:
	/* 0x5b6: je     8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b6, 0x8ff, x86_l_8ff);
x86_l_5bc:
	/* 0x5bc: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_5c1:
	/* 0x5c1: mov    rsi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_5c8:
	/* 0x5c8: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_5cd:
	/* 0x5cd: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_5d2:
	/* 0x5d2: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_5d7:
	/* 0x5d7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5da:
	/* 0x5da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dc:
	/* 0x5dc: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_5e3:
	/* 0x5e3: jmp    8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JMP(0x5e3, 0x8ff, x86_l_8ff);
x86_l_5e8:
	/* 0x5e8: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_5ee:
	/* 0x5ee: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_5f6:
	/* 0x5f6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fb:
	/* 0x5fb: jmp    8d5 <generic_usdt_actions+0x8d5> */
	X86_SIM_X86_JMP(0x5fb, 0x8d5, x86_l_8d5);
x86_l_600:
	/* 0x600: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_605:
	/* 0x605: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60a:
	/* 0x60a: jmp    8d5 <generic_usdt_actions+0x8d5> */
	X86_SIM_X86_JMP(0x60a, 0x8d5, x86_l_8d5);
x86_l_60f:
	/* 0x60f: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_614:
	/* 0x614: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_61c:
	/* 0x61c: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_624:
	/* 0x624: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_629:
	/* 0x629: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_631:
	/* 0x631: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_635:
	/* 0x635: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_63a:
	/* 0x63a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c:
	/* 0x63c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_640:
	/* 0x640: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_645:
	/* 0x645: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_648:
	/* 0x648: jne    740 <generic_usdt_actions+0x740> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x648, 0x740, x86_l_740);
x86_l_64e:
	/* 0x64e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_653:
	/* 0x653: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_656:
	/* 0x656: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_659:
	/* 0x659: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_65e:
	/* 0x65e: ja     4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x65e, 0x4b6, x86_l_4b6);
x86_l_664:
	/* 0x664: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_667:
	/* 0x667: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_670:
	/* 0x670: jne    4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x670, 0x4b6, x86_l_4b6);
x86_l_676:
	/* 0x676: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_67e:
	/* 0x67e: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_684:
	/* 0x684: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_688:
	/* 0x688: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_68f:
	/* 0x68f: mov    esi,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_697:
	/* 0x697: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_69d:
	/* 0x69d: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6a6:
	/* 0x6a6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6a9:
	/* 0x6a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ab:
	/* 0x6ab: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6b2:
	/* 0x6b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b4:
	/* 0x6b4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b9:
	/* 0x6b9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6be:
	/* 0x6be: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6c1:
	/* 0x6c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c3:
	/* 0x6c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c5:
	/* 0x6c5: jmp    4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JMP(0x6c5, 0x4b6, x86_l_4b6);
x86_l_6ca:
	/* 0x6ca: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_6d1:
	/* 0x6d1: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d6:
	/* 0x6d6: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6db:
	/* 0x6db: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6e0:
	/* 0x6e0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6e5:
	/* 0x6e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e7:
	/* 0x6e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ea:
	/* 0x6ea: je     56b <generic_usdt_actions+0x56b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ea, 0x56b, x86_l_56b);
x86_l_6f0:
	/* 0x6f0: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f5:
	/* 0x6f5: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6f7:
	/* 0x6f7: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fc:
	/* 0x6fc: mov    WORD PTR [rsp+0x12],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411331ULL);
x86_l_703:
	/* 0x703: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_70d:
	/* 0x70d: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_712:
	/* 0x712: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_719:
	/* 0x719: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71e:
	/* 0x71e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_723:
	/* 0x723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_725:
	/* 0x725: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_728:
	/* 0x728: je     7a0 <generic_usdt_actions+0x7a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x728, 0x7a0, x86_l_7a0);
x86_l_72a:
	/* 0x72a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_72c:
	/* 0x72c: jmp    7c4 <generic_usdt_actions+0x7c4> */
	X86_SIM_X86_JMP(0x72c, 0x7c4, x86_l_7c4);
x86_l_731:
	/* 0x731: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_736:
	/* 0x736: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_73b:
	/* 0x73b: jmp    8d5 <generic_usdt_actions+0x8d5> */
	X86_SIM_X86_JMP(0x73b, 0x8d5, x86_l_8d5);
x86_l_740:
	/* 0x740: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_747:
	/* 0x747: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_74c:
	/* 0x74c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_751:
	/* 0x751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_753:
	/* 0x753: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_756:
	/* 0x756: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_758:
	/* 0x758: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_75c:
	/* 0x75c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_75e:
	/* 0x75e: jne    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x75e, 0x906, x86_l_906);
x86_l_764:
	/* 0x764: jmp    4b6 <generic_usdt_actions+0x4b6> */
	X86_SIM_X86_JMP(0x764, 0x4b6, x86_l_4b6);
x86_l_769:
	/* 0x769: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_76c:
	/* 0x76c: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_770:
	/* 0x770: jg     823 <generic_usdt_actions+0x823> */
	X86_SIM_X86_JCC(X86_CC_G, 0x770, 0x823, x86_l_823);
x86_l_776:
	/* 0x776: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_779:
	/* 0x779: jg     85d <generic_usdt_actions+0x85d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x779, 0x85d, x86_l_85d);
x86_l_77f:
	/* 0x77f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_782:
	/* 0x782: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_784:
	/* 0x784: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x784, 0x8ac, x86_l_8ac);
x86_l_78a:
	/* 0x78a: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_792:
	/* 0x792: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_795:
	/* 0x795: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x795, 0x8ac, x86_l_8ac);
x86_l_79b:
	/* 0x79b: jmp    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JMP(0x79b, 0x8af, x86_l_8af);
x86_l_7a0:
	/* 0x7a0: mov    DWORD PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_7a8:
	/* 0x7a8: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7af:
	/* 0x7af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b1:
	/* 0x7b1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b6:
	/* 0x7b6: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_7bb:
	/* 0x7bb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7c0:
	/* 0x7c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c2:
	/* 0x7c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c4:
	/* 0x7c4: cmp    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_7c9:
	/* 0x7c9: je     56b <generic_usdt_actions+0x56b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c9, 0x56b, x86_l_56b);
x86_l_7cf:
	/* 0x7cf: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7d6:
	/* 0x7d6: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7db:
	/* 0x7db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e0:
	/* 0x7e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e2:
	/* 0x7e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e5:
	/* 0x7e5: je     56b <generic_usdt_actions+0x56b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e5, 0x56b, x86_l_56b);
x86_l_7eb:
	/* 0x7eb: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_7ef:
	/* 0x7ef: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7f2:
	/* 0x7f2: jmp    56b <generic_usdt_actions+0x56b> */
	X86_SIM_X86_JMP(0x7f2, 0x56b, x86_l_56b);
x86_l_7f7:
	/* 0x7f7: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_7fa:
	/* 0x7fa: jg     841 <generic_usdt_actions+0x841> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7fa, 0x841, x86_l_841);
x86_l_7fc:
	/* 0x7fc: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_804:
	/* 0x804: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_807:
	/* 0x807: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x807, 0x8ac, x86_l_8ac);
x86_l_80d:
	/* 0x80d: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_815:
	/* 0x815: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_818:
	/* 0x818: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x818, 0x8ac, x86_l_8ac);
x86_l_81e:
	/* 0x81e: jmp    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JMP(0x81e, 0x8af, x86_l_8af);
x86_l_823:
	/* 0x823: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_826:
	/* 0x826: jg     876 <generic_usdt_actions+0x876> */
	X86_SIM_X86_JCC(X86_CC_G, 0x826, 0x876, x86_l_876);
x86_l_828:
	/* 0x828: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_830:
	/* 0x830: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_833:
	/* 0x833: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x833, 0x8ac, x86_l_8ac);
x86_l_835:
	/* 0x835: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_83a:
	/* 0x83a: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_83d:
	/* 0x83d: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83d, 0x8ac, x86_l_8ac);
x86_l_83f:
	/* 0x83f: jmp    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JMP(0x83f, 0x8af, x86_l_8af);
x86_l_841:
	/* 0x841: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_849:
	/* 0x849: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_84c:
	/* 0x84c: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84c, 0x8ac, x86_l_8ac);
x86_l_84e:
	/* 0x84e: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_856:
	/* 0x856: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_859:
	/* 0x859: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x859, 0x8ac, x86_l_8ac);
x86_l_85b:
	/* 0x85b: jmp    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JMP(0x85b, 0x8af, x86_l_8af);
x86_l_85d:
	/* 0x85d: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_865:
	/* 0x865: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_868:
	/* 0x868: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x868, 0x8ac, x86_l_8ac);
x86_l_86a:
	/* 0x86a: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_86f:
	/* 0x86f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_872:
	/* 0x872: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x872, 0x8ac, x86_l_8ac);
x86_l_874:
	/* 0x874: jmp    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JMP(0x874, 0x8af, x86_l_8af);
x86_l_876:
	/* 0x876: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_87e:
	/* 0x87e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_881:
	/* 0x881: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x881, 0x8ac, x86_l_8ac);
x86_l_883:
	/* 0x883: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_88b:
	/* 0x88b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_88e:
	/* 0x88e: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88e, 0x8ac, x86_l_8ac);
x86_l_890:
	/* 0x890: jmp    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JMP(0x890, 0x8af, x86_l_8af);
x86_l_892:
	/* 0x892: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_89a:
	/* 0x89a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_89d:
	/* 0x89d: je     8ac <generic_usdt_actions+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89d, 0x8ac, x86_l_8ac);
x86_l_89f:
	/* 0x89f: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8a7:
	/* 0x8a7: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_8aa:
	/* 0x8aa: jne    8af <generic_usdt_actions+0x8af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8aa, 0x8af, x86_l_8af);
x86_l_8ac:
	/* 0x8ac: mov    rdi,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8af:
	/* 0x8af: add    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8b2:
	/* 0x8b2: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b6:
	/* 0x8b6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8bb:
	/* 0x8bb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8c0:
	/* 0x8c0: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_8c5:
	/* 0x8c5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_8ca:
	/* 0x8ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cc:
	/* 0x8cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8ce:
	/* 0x8ce: je     8d5 <generic_usdt_actions+0x8d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ce, 0x8d5, x86_l_8d5);
x86_l_8d0:
	/* 0x8d0: or     BYTE PTR [r14+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_8d5:
	/* 0x8d5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_8dd:
	/* 0x8dd: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_8e4:
	/* 0x8e4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8e9:
	/* 0x8e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8ee:
	/* 0x8ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f0:
	/* 0x8f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: je     8ff <generic_usdt_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f3, 0x8ff, x86_l_8ff);
x86_l_8f5:
	/* 0x8f5: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8fa:
	/* 0x8fa: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8ff:
	/* 0x8ff: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_903:
	/* 0x903: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_906:
	/* 0x906: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_90e:
	/* 0x90e: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_912:
	/* 0x912: jae    1155 <generic_usdt_actions+0x1155> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x912, 0x1155, x86_l_1155);
x86_l_918:
	/* 0x918: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_91d:
	/* 0x91d: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_920:
	/* 0x920: mov    r14d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_32);
x86_l_923:
	/* 0x923: movsxd r15,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_928:
	/* 0x928: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_930:
	/* 0x930: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_937:
	/* 0x937: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_93c:
	/* 0x93c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_941:
	/* 0x941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_943:
	/* 0x943: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_945:
	/* 0x945: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_948:
	/* 0x948: je     980 <generic_usdt_actions+0x980> */
	X86_SIM_X86_JCC(X86_CC_E, 0x948, 0x980, x86_l_980);
x86_l_94a:
	/* 0x94a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_94d:
	/* 0x94d: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_951:
	/* 0x951: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_954:
	/* 0x954: jg     98a <generic_usdt_actions+0x98a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x954, 0x98a, x86_l_98a);
x86_l_956:
	/* 0x956: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_959:
	/* 0x959: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_95c:
	/* 0x95c: jg     9cc <generic_usdt_actions+0x9cc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x95c, 0x9cc, x86_l_9cc);
x86_l_95e:
	/* 0x95e: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_961:
	/* 0x961: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_964:
	/* 0x964: jg     be5 <generic_usdt_actions+0xbe5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x964, 0xbe5, x86_l_be5);
x86_l_96a:
	/* 0x96a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_96c:
	/* 0x96c: je     d1c <generic_usdt_actions+0xd1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96c, 0xd1c, x86_l_d1c);
x86_l_972:
	/* 0x972: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_975:
	/* 0x975: je     bf7 <generic_usdt_actions+0xbf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x975, 0xbf7, x86_l_bf7);
x86_l_97b:
	/* 0x97b: jmp    10da <generic_usdt_actions+0x10da> */
	X86_SIM_X86_JMP(0x97b, 0x10da, x86_l_10da);
x86_l_980:
	/* 0x980: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_985:
	/* 0x985: jmp    10ec <generic_usdt_actions+0x10ec> */
	X86_SIM_X86_JMP(0x985, 0x10ec, x86_l_10ec);
x86_l_98a:
	/* 0x98a: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_98d:
	/* 0x98d: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_990:
	/* 0x990: jg     af5 <generic_usdt_actions+0xaf5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x990, 0xaf5, x86_l_af5);
x86_l_996:
	/* 0x996: lea    eax,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_999:
	/* 0x999: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_99c:
	/* 0x99c: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a1:
	/* 0x9a1: jb     c67 <generic_usdt_actions+0xc67> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9a1, 0xc67, x86_l_c67);
x86_l_9a7:
	/* 0x9a7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9aa:
	/* 0x9aa: je     c7f <generic_usdt_actions+0xc7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9aa, 0xc7f, x86_l_c7f);
x86_l_9b0:
	/* 0x9b0: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_9b3:
	/* 0x9b3: jne    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b3, 0x10e2, x86_l_10e2);
x86_l_9b9:
	/* 0x9b9: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_9bc:
	/* 0x9bc: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_9bf:
	/* 0x9bf: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9c2:
	/* 0x9c2: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9c7:
	/* 0x9c7: jmp    10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JMP(0x9c7, 0x10b2, x86_l_10b2);
x86_l_9cc:
	/* 0x9cc: lea    eax,[rcx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_9cf:
	/* 0x9cf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9d2:
	/* 0x9d2: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d7:
	/* 0x9d7: jb     c6f <generic_usdt_actions+0xc6f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9d7, 0xc6f, x86_l_c6f);
x86_l_9dd:
	/* 0x9dd: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9e0:
	/* 0x9e0: je     c8c <generic_usdt_actions+0xc8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e0, 0xc8c, x86_l_c8c);
x86_l_9e6:
	/* 0x9e6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9e9:
	/* 0x9e9: jne    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e9, 0x10e2, x86_l_10e2);
x86_l_9ef:
	/* 0x9ef: mov    eax,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_9f4:
	/* 0x9f4: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_9f8:
	/* 0x9f8: mov    r14d,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_9fd:
	/* 0x9fd: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a06:
	/* 0xa06: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a0f:
	/* 0xa0f: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a12:
	/* 0xa12: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a15:
	/* 0xa15: ja     10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa15, 0x10e2, x86_l_10e2);
x86_l_a1b:
	/* 0xa1b: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_a23:
	/* 0xa23: jne    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa23, 0x10e2, x86_l_10e2);
x86_l_a29:
	/* 0xa29: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_a31:
	/* 0xa31: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a36:
	/* 0xa36: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_a3d:
	/* 0xa3d: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a41:
	/* 0xa41: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a46:
	/* 0xa46: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a4b:
	/* 0xa4b: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_a4e:
	/* 0xa4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a50:
	/* 0xa50: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_a54:
	/* 0xa54: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a59:
	/* 0xa59: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_a60:
	/* 0xa60: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a65:
	/* 0xa65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a6a:
	/* 0xa6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6c:
	/* 0xa6c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a6f:
	/* 0xa6f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a74:
	/* 0xa74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a77:
	/* 0xa77: je     10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa77, 0x10e2, x86_l_10e2);
x86_l_a7d:
	/* 0xa7d: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a81:
	/* 0xa81: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_a85:
	/* 0xa85: ja     10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa85, 0x10e2, x86_l_10e2);
x86_l_a8b:
	/* 0xa8b: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_a94:
	/* 0xa94: jne    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa94, 0x10e2, x86_l_10e2);
x86_l_a9a:
	/* 0xa9a: mov    rcx,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_aa2:
	/* 0xaa2: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_aaa:
	/* 0xaaa: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ab0:
	/* 0xab0: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_ab7:
	/* 0xab7: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_abb:
	/* 0xabb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_abe:
	/* 0xabe: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ac3:
	/* 0xac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac5:
	/* 0xac5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ac9:
	/* 0xac9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ace:
	/* 0xace: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_ad5:
	/* 0xad5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad7:
	/* 0xad7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_adc:
	/* 0xadc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ae1:
	/* 0xae1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ae4:
	/* 0xae4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae6:
	/* 0xae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae8:
	/* 0xae8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_aeb:
	/* 0xaeb: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_af0:
	/* 0xaf0: jmp    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JMP(0xaf0, 0x10e2, x86_l_10e2);
x86_l_af5:
	/* 0xaf5: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_af8:
	/* 0xaf8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_afb:
	/* 0xafb: je     da3 <generic_usdt_actions+0xda3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xafb, 0xda3, x86_l_da3);
x86_l_b01:
	/* 0xb01: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_b04:
	/* 0xb04: je     ca2 <generic_usdt_actions+0xca2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb04, 0xca2, x86_l_ca2);
x86_l_b0a:
	/* 0xb0a: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_b0d:
	/* 0xb0d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b10:
	/* 0xb10: jne    10dd <generic_usdt_actions+0x10dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb10, 0x10dd, x86_l_10dd);
x86_l_b16:
	/* 0xb16: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_b19:
	/* 0xb19: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_b1d:
	/* 0xb1d: cmp    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b22:
	/* 0xb22: je     db7 <generic_usdt_actions+0xdb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb22, 0xdb7, x86_l_db7);
x86_l_b28:
	/* 0xb28: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_b2b:
	/* 0xb2b: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_b30:
	/* 0xb30: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b34:
	/* 0xb34: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_b39:
	/* 0xb39: add    rdx,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_b40:
	/* 0xb40: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_b47:
	/* 0xb47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b4c:
	/* 0xb4c: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b4f:
	/* 0xb4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b51:
	/* 0xb51: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b54:
	/* 0xb54: je     ee7 <generic_usdt_actions+0xee7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb54, 0xee7, x86_l_ee7);
x86_l_b5a:
	/* 0xb5a: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b5e:
	/* 0xb5e: lea    rdx,[r14+r14*2] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 0ULL);
x86_l_b62:
	/* 0xb62: cmp    BYTE PTR [rax+rdx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 3), 2272037699587ULL);
x86_l_b6a:
	/* 0xb6a: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_b70:
	/* 0xb70: jne    10ac <generic_usdt_actions+0x10ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb70, 0x10ac, x86_l_10ac);
x86_l_b76:
	/* 0xb76: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_b7a:
	/* 0xb7a: add    rcx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_b81:
	/* 0xb81: rorx   eax,DWORD PTR [rax+rdx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_b8c:
	/* 0xb8c: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b8e:
	/* 0xb8e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_b91:
	/* 0xb91: jle    f1f <generic_usdt_actions+0xf1f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb91, 0xf1f, x86_l_f1f);
x86_l_b97:
	/* 0xb97: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_b9a:
	/* 0xb9a: jle    fa7 <generic_usdt_actions+0xfa7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb9a, 0xfa7, x86_l_fa7);
x86_l_ba0:
	/* 0xba0: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_ba3:
	/* 0xba3: jle    1061 <generic_usdt_actions+0x1061> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xba3, 0x1061, x86_l_1061);
x86_l_ba9:
	/* 0xba9: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_bb1:
	/* 0xbb1: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_bb4:
	/* 0xbb4: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb8:
	/* 0xbb8: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb8, 0x1088, x86_l_1088);
x86_l_bbe:
	/* 0xbbe: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bc6:
	/* 0xbc6: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_bc9:
	/* 0xbc9: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc9, 0x1088, x86_l_1088);
x86_l_bcf:
	/* 0xbcf: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bd7:
	/* 0xbd7: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_bda:
	/* 0xbda: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbda, 0x1088, x86_l_1088);
x86_l_be0:
	/* 0xbe0: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0xbe0, 0x108b, x86_l_108b);
x86_l_be5:
	/* 0xbe5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_be8:
	/* 0xbe8: je     d96 <generic_usdt_actions+0xd96> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe8, 0xd96, x86_l_d96);
x86_l_bee:
	/* 0xbee: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bf1:
	/* 0xbf1: jne    10da <generic_usdt_actions+0x10da> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbf1, 0x10da, x86_l_10da);
x86_l_bf7:
	/* 0xbf7: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bfc:
	/* 0xbfc: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_c01:
	/* 0xc01: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c05:
	/* 0xc05: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_c0a:
	/* 0xc0a: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c0f:
	/* 0xc0f: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c18:
	/* 0xc18: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c21:
	/* 0xc21: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_c29:
	/* 0xc29: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_c30:
	/* 0xc30: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c35:
	/* 0xc35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c3a:
	/* 0xc3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3c:
	/* 0xc3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3f:
	/* 0xc3f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c42:
	/* 0xc42: je     c5d <generic_usdt_actions+0xc5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc42, 0xc5d, x86_l_c5d);
x86_l_c44:
	/* 0xc44: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_c48:
	/* 0xc48: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_c4c:
	/* 0xc4c: ja     c5d <generic_usdt_actions+0xc5d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc4c, 0xc5d, x86_l_c5d);
x86_l_c4e:
	/* 0xc4e: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_c57:
	/* 0xc57: je     dc2 <generic_usdt_actions+0xdc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc57, 0xdc2, x86_l_dc2);
x86_l_c5d:
	/* 0xc5d: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c62:
	/* 0xc62: jmp    10dd <generic_usdt_actions+0x10dd> */
	X86_SIM_X86_JMP(0xc62, 0x10dd, x86_l_10dd);
x86_l_c67:
	/* 0xc67: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c6a:
	/* 0xc6a: jmp    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JMP(0xc6a, 0x10e2, x86_l_10e2);
x86_l_c6f:
	/* 0xc6f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c72:
	/* 0xc72: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_c77:
	/* 0xc77: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c7a:
	/* 0xc7a: jmp    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JMP(0xc7a, 0x10e2, x86_l_10e2);
x86_l_c7f:
	/* 0xc7f: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_c87:
	/* 0xc87: jmp    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JMP(0xc87, 0x10e2, x86_l_10e2);
x86_l_c8c:
	/* 0xc8c: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c8f:
	/* 0xc8f: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_c92:
	/* 0xc92: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c95:
	/* 0xc95: mov    r14,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_c9d:
	/* 0xc9d: jmp    10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JMP(0xc9d, 0x10b2, x86_l_10b2);
x86_l_ca2:
	/* 0xca2: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_ca5:
	/* 0xca5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_caa:
	/* 0xcaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cac:
	/* 0xcac: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cb1:
	/* 0xcb1: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_cb8:
	/* 0xcb8: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cbd:
	/* 0xcbd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc2:
	/* 0xcc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc4:
	/* 0xcc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cc7:
	/* 0xcc7: je     d14 <generic_usdt_actions+0xd14> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc7, 0xd14, x86_l_d14);
x86_l_cc9:
	/* 0xcc9: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ccd:
	/* 0xccd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cd2:
	/* 0xcd2: mov    DWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_cda:
	/* 0xcda: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_ce1:
	/* 0xce1: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ce6:
	/* 0xce6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ceb:
	/* 0xceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ced:
	/* 0xced: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_cf5:
	/* 0xcf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf8:
	/* 0xcf8: je     e82 <generic_usdt_actions+0xe82> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf8, 0xe82, x86_l_e82);
x86_l_cfe:
	/* 0xcfe: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d01:
	/* 0xd01: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_d08:
	/* 0xd08: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d0d:
	/* 0xd0d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_d12:
	/* 0xd12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d14:
	/* 0xd14: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d17:
	/* 0xd17: jmp    10da <generic_usdt_actions+0x10da> */
	X86_SIM_X86_JMP(0xd17, 0x10da, x86_l_10da);
x86_l_d1c:
	/* 0xd1c: cmp    DWORD PTR [r13+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_d22:
	/* 0xd22: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d25:
	/* 0xd25: je     d51 <generic_usdt_actions+0xd51> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd25, 0xd51, x86_l_d51);
x86_l_d27:
	/* 0xd27: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_d2b:
	/* 0xd2b: mov    rsi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_d32:
	/* 0xd32: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_d35:
	/* 0xd35: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d37:
	/* 0xd37: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d41:
	/* 0xd41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d43:
	/* 0xd43: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d46:
	/* 0xd46: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d49:
	/* 0xd49: mov    QWORD PTR [r12+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d51:
	/* 0xd51: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_d55:
	/* 0xd55: cmp    DWORD PTR [r13+r15*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 17179869184ULL);
x86_l_d5b:
	/* 0xd5b: je     10dd <generic_usdt_actions+0x10dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5b, 0x10dd, x86_l_10dd);
x86_l_d61:
	/* 0xd61: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_d65:
	/* 0xd65: mov    rsi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_d6c:
	/* 0xd6c: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_d6f:
	/* 0xd6f: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_d74:
	/* 0xd74: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d79:
	/* 0xd79: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_d7e:
	/* 0xd7e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d81:
	/* 0xd81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d83:
	/* 0xd83: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d86:
	/* 0xd86: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d89:
	/* 0xd89: mov    QWORD PTR [r12+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d91:
	/* 0xd91: jmp    10dd <generic_usdt_actions+0x10dd> */
	X86_SIM_X86_JMP(0xd91, 0x10dd, x86_l_10dd);
x86_l_d96:
	/* 0xd96: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_d99:
	/* 0xd99: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d9e:
	/* 0xd9e: jmp    10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JMP(0xd9e, 0x10b2, x86_l_10b2);
x86_l_da3:
	/* 0xda3: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_da6:
	/* 0xda6: add    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_daa:
	/* 0xdaa: mov    r14,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_db2:
	/* 0xdb2: jmp    10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JMP(0xdb2, 0x10b2, x86_l_10b2);
x86_l_db7:
	/* 0xdb7: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_dbd:
	/* 0xdbd: jmp    10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JMP(0xdbd, 0x10b2, x86_l_10b2);
x86_l_dc2:
	/* 0xdc2: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_dc7:
	/* 0xdc7: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_dcf:
	/* 0xdcf: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_dd7:
	/* 0xdd7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ddc:
	/* 0xddc: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_de3:
	/* 0xde3: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_de7:
	/* 0xde7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_dec:
	/* 0xdec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dee:
	/* 0xdee: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_df2:
	/* 0xdf2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df7:
	/* 0xdf7: cmp    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_dfc:
	/* 0xdfc: jne    ef2 <generic_usdt_actions+0xef2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdfc, 0xef2, x86_l_ef2);
x86_l_e02:
	/* 0xe02: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e07:
	/* 0xe07: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e0a:
	/* 0xe0a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e0d:
	/* 0xe0d: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e12:
	/* 0xe12: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e15:
	/* 0xe15: ja     c5d <generic_usdt_actions+0xc5d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe15, 0xc5d, x86_l_c5d);
x86_l_e1b:
	/* 0xe1b: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e1e:
	/* 0xe1e: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_e26:
	/* 0xe26: jne    c5d <generic_usdt_actions+0xc5d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe26, 0xc5d, x86_l_c5d);
x86_l_e2c:
	/* 0xe2c: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_e34:
	/* 0xe34: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e3a:
	/* 0xe3a: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e3d:
	/* 0xe3d: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_e44:
	/* 0xe44: mov    esi,DWORD PTR [r12+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e4c:
	/* 0xe4c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e52:
	/* 0xe52: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e56:
	/* 0xe56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e5b:
	/* 0xe5b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e5e:
	/* 0xe5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e60:
	/* 0xe60: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e67:
	/* 0xe67: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e69:
	/* 0xe69: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6e:
	/* 0xe6e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e73:
	/* 0xe73: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e76:
	/* 0xe76: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e78:
	/* 0xe78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7a:
	/* 0xe7a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: jmp    c5d <generic_usdt_actions+0xc5d> */
	X86_SIM_X86_JMP(0xe7d, 0xc5d, x86_l_c5d);
x86_l_e82:
	/* 0xe82: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_e89:
	/* 0xe89: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e8e:
	/* 0xe8e: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_e93:
	/* 0xe93: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e98:
	/* 0xe98: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e9d:
	/* 0xe9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9f:
	/* 0xe9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea2:
	/* 0xea2: je     d01 <generic_usdt_actions+0xd01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea2, 0xd01, x86_l_d01);
x86_l_ea8:
	/* 0xea8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_eab:
	/* 0xeab: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ead:
	/* 0xead: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb2:
	/* 0xeb2: mov    WORD PTR [rsp+0x12],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411331ULL);
x86_l_eb9:
	/* 0xeb9: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_ec3:
	/* 0xec3: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ec8:
	/* 0xec8: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ecf:
	/* 0xecf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed4:
	/* 0xed4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed9:
	/* 0xed9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_edb:
	/* 0xedb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ede:
	/* 0xede: je     f53 <generic_usdt_actions+0xf53> */
	X86_SIM_X86_JCC(X86_CC_E, 0xede, 0xf53, x86_l_f53);
x86_l_ee0:
	/* 0xee0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ee2:
	/* 0xee2: jmp    f77 <generic_usdt_actions+0xf77> */
	X86_SIM_X86_JMP(0xee2, 0xf77, x86_l_f77);
x86_l_ee7:
	/* 0xee7: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_eed:
	/* 0xeed: jmp    10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JMP(0xeed, 0x10b2, x86_l_10b2);
x86_l_ef2:
	/* 0xef2: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_ef9:
	/* 0xef9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efe:
	/* 0xefe: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f03:
	/* 0xf03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f05:
	/* 0xf05: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f07:
	/* 0xf07: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f0c:
	/* 0xf0c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f0f:
	/* 0xf0f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f14:
	/* 0xf14: jne    10ec <generic_usdt_actions+0x10ec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf14, 0x10ec, x86_l_10ec);
x86_l_f1a:
	/* 0xf1a: jmp    10e2 <generic_usdt_actions+0x10e2> */
	X86_SIM_X86_JMP(0xf1a, 0x10e2, x86_l_10e2);
x86_l_f1f:
	/* 0xf1f: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f22:
	/* 0xf22: jg     fd7 <generic_usdt_actions+0xfd7> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf22, 0xfd7, x86_l_fd7);
x86_l_f28:
	/* 0xf28: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2b:
	/* 0xf2b: jg     1024 <generic_usdt_actions+0x1024> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf2b, 0x1024, x86_l_1024);
x86_l_f31:
	/* 0xf31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f33:
	/* 0xf33: je     1081 <generic_usdt_actions+0x1081> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf33, 0x1081, x86_l_1081);
x86_l_f39:
	/* 0xf39: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f41:
	/* 0xf41: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f44:
	/* 0xf44: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f48:
	/* 0xf48: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf48, 0x1088, x86_l_1088);
x86_l_f4e:
	/* 0xf4e: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0xf4e, 0x108b, x86_l_108b);
x86_l_f53:
	/* 0xf53: mov    DWORD PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_f5b:
	/* 0xf5b: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f62:
	/* 0xf62: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f64:
	/* 0xf64: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f69:
	/* 0xf69: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_f6e:
	/* 0xf6e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f73:
	/* 0xf73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f75:
	/* 0xf75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f77:
	/* 0xf77: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_f79:
	/* 0xf79: je     d01 <generic_usdt_actions+0xd01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf79, 0xd01, x86_l_d01);
x86_l_f7f:
	/* 0xf7f: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_f86:
	/* 0xf86: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f8b:
	/* 0xf8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f90:
	/* 0xf90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f92:
	/* 0xf92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f95:
	/* 0xf95: je     d01 <generic_usdt_actions+0xd01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf95, 0xd01, x86_l_d01);
x86_l_f9b:
	/* 0xf9b: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_f9f:
	/* 0xf9f: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fa2:
	/* 0xfa2: jmp    d01 <generic_usdt_actions+0xd01> */
	X86_SIM_X86_JMP(0xfa2, 0xd01, x86_l_d01);
x86_l_fa7:
	/* 0xfa7: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_faa:
	/* 0xfaa: jg     1004 <generic_usdt_actions+0x1004> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfaa, 0x1004, x86_l_1004);
x86_l_fac:
	/* 0xfac: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_fb4:
	/* 0xfb4: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_fb7:
	/* 0xfb7: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fbb:
	/* 0xfbb: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfbb, 0x1088, x86_l_1088);
x86_l_fc1:
	/* 0xfc1: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fc9:
	/* 0xfc9: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_fcc:
	/* 0xfcc: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfcc, 0x1088, x86_l_1088);
x86_l_fd2:
	/* 0xfd2: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0xfd2, 0x108b, x86_l_108b);
x86_l_fd7:
	/* 0xfd7: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_fda:
	/* 0xfda: jg     1041 <generic_usdt_actions+0x1041> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfda, 0x1041, x86_l_1041);
x86_l_fdc:
	/* 0xfdc: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_fe4:
	/* 0xfe4: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fe7:
	/* 0xfe7: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_feb:
	/* 0xfeb: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfeb, 0x1088, x86_l_1088);
x86_l_ff1:
	/* 0xff1: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ff6:
	/* 0xff6: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_ff9:
	/* 0xff9: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff9, 0x1088, x86_l_1088);
x86_l_fff:
	/* 0xfff: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0xfff, 0x108b, x86_l_108b);
x86_l_1004:
	/* 0x1004: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_100c:
	/* 0x100c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_100f:
	/* 0x100f: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1013:
	/* 0x1013: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1013, 0x1088, x86_l_1088);
x86_l_1015:
	/* 0x1015: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_101d:
	/* 0x101d: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1020:
	/* 0x1020: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1020, 0x1088, x86_l_1088);
x86_l_1022:
	/* 0x1022: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0x1022, 0x108b, x86_l_108b);
x86_l_1024:
	/* 0x1024: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_102c:
	/* 0x102c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_102f:
	/* 0x102f: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1033:
	/* 0x1033: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1033, 0x1088, x86_l_1088);
x86_l_1035:
	/* 0x1035: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_103a:
	/* 0x103a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_103d:
	/* 0x103d: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103d, 0x1088, x86_l_1088);
x86_l_103f:
	/* 0x103f: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0x103f, 0x108b, x86_l_108b);
x86_l_1041:
	/* 0x1041: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1049:
	/* 0x1049: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_104c:
	/* 0x104c: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1050:
	/* 0x1050: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1050, 0x1088, x86_l_1088);
x86_l_1052:
	/* 0x1052: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_105a:
	/* 0x105a: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_105d:
	/* 0x105d: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105d, 0x1088, x86_l_1088);
x86_l_105f:
	/* 0x105f: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0x105f, 0x108b, x86_l_108b);
x86_l_1061:
	/* 0x1061: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1069:
	/* 0x1069: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_106c:
	/* 0x106c: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1070:
	/* 0x1070: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1070, 0x1088, x86_l_1088);
x86_l_1072:
	/* 0x1072: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_107a:
	/* 0x107a: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_107d:
	/* 0x107d: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107d, 0x1088, x86_l_1088);
x86_l_107f:
	/* 0x107f: jmp    108b <generic_usdt_actions+0x108b> */
	X86_SIM_X86_JMP(0x107f, 0x108b, x86_l_108b);
x86_l_1081:
	/* 0x1081: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1084:
	/* 0x1084: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1088:
	/* 0x1088: mov    rdi,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108b:
	/* 0x108b: add    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_108e:
	/* 0x108e: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1092:
	/* 0x1092: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1097:
	/* 0x1097: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_109c:
	/* 0x109c: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_10a1:
	/* 0x10a1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_10a6:
	/* 0x10a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a8:
	/* 0x10a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10aa:
	/* 0x10aa: je     10b2 <generic_usdt_actions+0x10b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10aa, 0x10b2, x86_l_10b2);
x86_l_10ac:
	/* 0x10ac: or     BYTE PTR [r12+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_10b2:
	/* 0x10b2: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10ba:
	/* 0x10ba: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_10c1:
	/* 0x10c1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c6:
	/* 0x10c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10cb:
	/* 0x10cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cd:
	/* 0x10cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d0:
	/* 0x10d0: je     10d7 <generic_usdt_actions+0x10d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d0, 0x10d7, x86_l_10d7);
x86_l_10d2:
	/* 0x10d2: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10d7:
	/* 0x10d7: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_10da:
	/* 0x10da: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10dd:
	/* 0x10dd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10e2:
	/* 0x10e2: mov    QWORD PTR [rdx+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10e6:
	/* 0x10e6: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10e9:
	/* 0x10e9: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_10ec:
	/* 0x10ec: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_10f3:
	/* 0x10f3: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_10f7:
	/* 0x10f7: jae    1155 <generic_usdt_actions+0x1155> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x10f7, 0x1155, x86_l_1155);
x86_l_10f9:
	/* 0x10f9: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_10fc:
	/* 0x10fc: movsxd rbp,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_1101:
	/* 0x1101: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1109:
	/* 0x1109: mov    rdi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1110:
	/* 0x1110: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1115:
	/* 0x1115: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111a:
	/* 0x111a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111c:
	/* 0x111c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111f:
	/* 0x111f: je     1155 <generic_usdt_actions+0x1155> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111f, 0x1155, x86_l_1155);
x86_l_1121:
	/* 0x1121: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1124:
	/* 0x1124: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1127:
	/* 0x1127: jle    1189 <generic_usdt_actions+0x1189> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1127, 0x1189, x86_l_1189);
x86_l_1129:
	/* 0x1129: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_112c:
	/* 0x112c: jg     11b1 <generic_usdt_actions+0x11b1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x112c, 0x11b1, x86_l_11b1);
x86_l_1132:
	/* 0x1132: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1135:
	/* 0x1135: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1138:
	/* 0x1138: jb     13aa <generic_usdt_actions+0x13aa> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1138, 0x13aa, x86_l_13aa);
x86_l_113e:
	/* 0x113e: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1141:
	/* 0x1141: je     14c5 <generic_usdt_actions+0x14c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1141, 0x14c5, x86_l_14c5);
x86_l_1147:
	/* 0x1147: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_114a:
	/* 0x114a: je     17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x114a, 0x17aa, x86_l_17aa);
x86_l_1150:
	/* 0x1150: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x1150, 0x17d4, x86_l_17d4);
x86_l_1155:
	/* 0x1155: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1159:
	/* 0x1159: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_115b:
	/* 0x115b: je     1178 <generic_usdt_actions+0x1178> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115b, 0x1178, x86_l_1178);
x86_l_115d:
	/* 0x115d: mov    rsi,QWORD PTR [rip+0x6e37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_1164:
	/* 0x1164: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1169:
	/* 0x1169: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_116e:
	/* 0x116e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1171:
	/* 0x1171: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1176:
	/* 0x1176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1178:
	/* 0x1178: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_117a:
	/* 0x117a: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_1181:
	/* 0x1181: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1183:
	/* 0x1183: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1184:
	/* 0x1184: jmp    17e1 <generic_usdt_actions+0x17e1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1189:
	/* 0x1189: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_118c:
	/* 0x118c: jg     12a2 <generic_usdt_actions+0x12a2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x118c, 0x12a2, x86_l_12a2);
x86_l_1192:
	/* 0x1192: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1194:
	/* 0x1194: je     1544 <generic_usdt_actions+0x1544> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1194, 0x1544, x86_l_1544);
x86_l_119a:
	/* 0x119a: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_119d:
	/* 0x119d: je     13b8 <generic_usdt_actions+0x13b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119d, 0x13b8, x86_l_13b8);
x86_l_11a3:
	/* 0x11a3: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_11a6:
	/* 0x11a6: je     17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a6, 0x17aa, x86_l_17aa);
x86_l_11ac:
	/* 0x11ac: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x11ac, 0x17d4, x86_l_17d4);
x86_l_11b1:
	/* 0x11b1: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_11b9:
	/* 0x11b9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11be:
	/* 0x11be: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_11c1:
	/* 0x11c1: je     17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c1, 0x17aa, x86_l_17aa);
x86_l_11c7:
	/* 0x11c7: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_11ca:
	/* 0x11ca: je     14cc <generic_usdt_actions+0x14cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ca, 0x14cc, x86_l_14cc);
x86_l_11d0:
	/* 0x11d0: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_11d3:
	/* 0x11d3: jne    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d3, 0x17d4, x86_l_17d4);
x86_l_11d9:
	/* 0x11d9: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11de:
	/* 0x11de: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11e3:
	/* 0x11e3: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_11e6:
	/* 0x11e6: je     17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e6, 0x17aa, x86_l_17aa);
x86_l_11ec:
	/* 0x11ec: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_11f1:
	/* 0x11f1: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_11f6:
	/* 0x11f6: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_11f9:
	/* 0x11f9: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_1200:
	/* 0x1200: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_1207:
	/* 0x1207: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_120c:
	/* 0x120c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120e:
	/* 0x120e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1213:
	/* 0x1213: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1218:
	/* 0x1218: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_121b:
	/* 0x121b: je     17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121b, 0x17aa, x86_l_17aa);
x86_l_1221:
	/* 0x1221: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1225:
	/* 0x1225: lea    rdx,[r12+r12*2] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 0ULL);
x86_l_1229:
	/* 0x1229: cmp    BYTE PTR [rax+rdx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 3), 2272037699587ULL);
x86_l_1231:
	/* 0x1231: jne    17a5 <generic_usdt_actions+0x17a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1231, 0x17a5, x86_l_17a5);
x86_l_1237:
	/* 0x1237: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_123b:
	/* 0x123b: add    rcx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_1242:
	/* 0x1242: rorx   eax,DWORD PTR [rax+rdx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_124d:
	/* 0x124d: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124f:
	/* 0x124f: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1252:
	/* 0x1252: jle    163d <generic_usdt_actions+0x163d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1252, 0x163d, x86_l_163d);
x86_l_1258:
	/* 0x1258: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_125b:
	/* 0x125b: jle    16c2 <generic_usdt_actions+0x16c2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x125b, 0x16c2, x86_l_16c2);
x86_l_1261:
	/* 0x1261: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1264:
	/* 0x1264: jle    1761 <generic_usdt_actions+0x1761> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1264, 0x1761, x86_l_1761);
x86_l_126a:
	/* 0x126a: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1272:
	/* 0x1272: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1275:
	/* 0x1275: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1275, 0x1780, x86_l_1780);
x86_l_127b:
	/* 0x127b: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1283:
	/* 0x1283: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1286:
	/* 0x1286: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1286, 0x1780, x86_l_1780);
x86_l_128c:
	/* 0x128c: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1294:
	/* 0x1294: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1297:
	/* 0x1297: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1297, 0x1780, x86_l_1780);
x86_l_129d:
	/* 0x129d: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x129d, 0x1783, x86_l_1783);
x86_l_12a2:
	/* 0x12a2: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_12a5:
	/* 0x12a5: je     13b8 <generic_usdt_actions+0x13b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a5, 0x13b8, x86_l_13b8);
x86_l_12ab:
	/* 0x12ab: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_12ae:
	/* 0x12ae: je     15a5 <generic_usdt_actions+0x15a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ae, 0x15a5, x86_l_15a5);
x86_l_12b4:
	/* 0x12b4: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_12b7:
	/* 0x12b7: jne    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12b7, 0x17d4, x86_l_17d4);
x86_l_12bd:
	/* 0x12bd: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_12c2:
	/* 0x12c2: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_12c7:
	/* 0x12c7: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_12d0:
	/* 0x12d0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12d9:
	/* 0x12d9: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_12dc:
	/* 0x12dc: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12df:
	/* 0x12df: ja     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x12df, 0x17d4, x86_l_17d4);
x86_l_12e5:
	/* 0x12e5: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_12ee:
	/* 0x12ee: jne    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12ee, 0x17d4, x86_l_17d4);
x86_l_12f4:
	/* 0x12f4: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_12fc:
	/* 0x12fc: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1301:
	/* 0x1301: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1309:
	/* 0x1309: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_130d:
	/* 0x130d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1312:
	/* 0x1312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1314:
	/* 0x1314: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1318:
	/* 0x1318: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_131d:
	/* 0x131d: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1324:
	/* 0x1324: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1329:
	/* 0x1329: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_132e:
	/* 0x132e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1330:
	/* 0x1330: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1333:
	/* 0x1333: je     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1333, 0x17d4, x86_l_17d4);
x86_l_1339:
	/* 0x1339: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_133d:
	/* 0x133d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1341:
	/* 0x1341: ja     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1341, 0x17d4, x86_l_17d4);
x86_l_1347:
	/* 0x1347: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_1350:
	/* 0x1350: jne    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1350, 0x17d4, x86_l_17d4);
x86_l_1356:
	/* 0x1356: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_135e:
	/* 0x135e: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1366:
	/* 0x1366: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_136c:
	/* 0x136c: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_1374:
	/* 0x1374: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1378:
	/* 0x1378: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_137b:
	/* 0x137b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1380:
	/* 0x1380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1382:
	/* 0x1382: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1386:
	/* 0x1386: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_138b:
	/* 0x138b: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1392:
	/* 0x1392: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1394:
	/* 0x1394: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1399:
	/* 0x1399: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_139e:
	/* 0x139e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13a1:
	/* 0x13a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a3:
	/* 0x13a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a5:
	/* 0x13a5: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x13a5, 0x17d4, x86_l_17d4);
x86_l_13aa:
	/* 0x13aa: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_13af:
	/* 0x13af: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13b3:
	/* 0x13b3: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x13b3, 0x17d4, x86_l_17d4);
x86_l_13b8:
	/* 0x13b8: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_13bd:
	/* 0x13bd: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_13c2:
	/* 0x13c2: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13cb:
	/* 0x13cb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13d4:
	/* 0x13d4: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_13dc:
	/* 0x13dc: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_13e3:
	/* 0x13e3: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13e8:
	/* 0x13e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ed:
	/* 0x13ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ef:
	/* 0x13ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f2:
	/* 0x13f2: je     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f2, 0x17d4, x86_l_17d4);
x86_l_13f8:
	/* 0x13f8: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_13fc:
	/* 0x13fc: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1400:
	/* 0x1400: ja     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1400, 0x17d4, x86_l_17d4);
x86_l_1406:
	/* 0x1406: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_140f:
	/* 0x140f: jne    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x140f, 0x17d4, x86_l_17d4);
x86_l_1415:
	/* 0x1415: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: mov    rax,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_1420:
	/* 0x1420: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1428:
	/* 0x1428: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_142d:
	/* 0x142d: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1435:
	/* 0x1435: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1439:
	/* 0x1439: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_143e:
	/* 0x143e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1440:
	/* 0x1440: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1444:
	/* 0x1444: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1449:
	/* 0x1449: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_144c:
	/* 0x144c: jne    1619 <generic_usdt_actions+0x1619> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x144c, 0x1619, x86_l_1619);
x86_l_1452:
	/* 0x1452: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1456:
	/* 0x1456: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_145a:
	/* 0x145a: ja     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x145a, 0x17d4, x86_l_17d4);
x86_l_1460:
	/* 0x1460: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_1469:
	/* 0x1469: jne    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1469, 0x17d4, x86_l_17d4);
x86_l_146f:
	/* 0x146f: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_1477:
	/* 0x1477: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_147c:
	/* 0x147c: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1480:
	/* 0x1480: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1487:
	/* 0x1487: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_148f:
	/* 0x148f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1495:
	/* 0x1495: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1499:
	/* 0x1499: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_149c:
	/* 0x149c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a1:
	/* 0x14a1: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_14a4:
	/* 0x14a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a6:
	/* 0x14a6: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_14ad:
	/* 0x14ad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14af:
	/* 0x14af: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b4:
	/* 0x14b4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14b9:
	/* 0x14b9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14bc:
	/* 0x14bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14be:
	/* 0x14be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c0:
	/* 0x14c0: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x14c0, 0x17d4, x86_l_17d4);
x86_l_14c5:
	/* 0x14c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c7:
	/* 0x14c7: jmp    17d8 <generic_usdt_actions+0x17d8> */
	X86_SIM_X86_JMP(0x14c7, 0x17d8, x86_l_17d8);
x86_l_14cc:
	/* 0x14cc: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_14d1:
	/* 0x14d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d3:
	/* 0x14d3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14d8:
	/* 0x14d8: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_14df:
	/* 0x14df: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14e4:
	/* 0x14e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14e9:
	/* 0x14e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14eb:
	/* 0x14eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14ee:
	/* 0x14ee: je     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ee, 0x17d4, x86_l_17d4);
x86_l_14f4:
	/* 0x14f4: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14f8:
	/* 0x14f8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14fd:
	/* 0x14fd: mov    DWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_1505:
	/* 0x1505: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_150c:
	/* 0x150c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1511:
	/* 0x1511: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1516:
	/* 0x1516: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1518:
	/* 0x1518: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_1520:
	/* 0x1520: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1523:
	/* 0x1523: je     15b7 <generic_usdt_actions+0x15b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1523, 0x15b7, x86_l_15b7);
x86_l_1529:
	/* 0x1529: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_152c:
	/* 0x152c: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1533:
	/* 0x1533: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1538:
	/* 0x1538: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_153d:
	/* 0x153d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153f:
	/* 0x153f: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x153f, 0x17d4, x86_l_17d4);
x86_l_1544:
	/* 0x1544: cmp    DWORD PTR [r13+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_154a:
	/* 0x154a: je     156d <generic_usdt_actions+0x156d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154a, 0x156d, x86_l_156d);
x86_l_154c:
	/* 0x154c: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_1551:
	/* 0x1551: mov    rsi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1558:
	/* 0x1558: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155a:
	/* 0x155a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_155f:
	/* 0x155f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1562:
	/* 0x1562: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1564:
	/* 0x1564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1566:
	/* 0x1566: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_156d:
	/* 0x156d: cmp    DWORD PTR [r13+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_1573:
	/* 0x1573: je     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1573, 0x17d4, x86_l_17d4);
x86_l_1579:
	/* 0x1579: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_157e:
	/* 0x157e: mov    rsi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1585:
	/* 0x1585: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_158a:
	/* 0x158a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_158f:
	/* 0x158f: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1594:
	/* 0x1594: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1597:
	/* 0x1597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1599:
	/* 0x1599: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15a0:
	/* 0x15a0: jmp    17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JMP(0x15a0, 0x17d4, x86_l_17d4);
x86_l_15a5:
	/* 0x15a5: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_15ad:
	/* 0x15ad: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15b2:
	/* 0x15b2: jmp    17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JMP(0x15b2, 0x17aa, x86_l_17aa);
x86_l_15b7:
	/* 0x15b7: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_15be:
	/* 0x15be: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15c3:
	/* 0x15c3: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15c8:
	/* 0x15c8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15cd:
	/* 0x15cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15d2:
	/* 0x15d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d4:
	/* 0x15d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d7:
	/* 0x15d7: je     152c <generic_usdt_actions+0x152c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d7, 0x152c, x86_l_152c);
x86_l_15dd:
	/* 0x15dd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15e0:
	/* 0x15e0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15e2:
	/* 0x15e2: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e7:
	/* 0x15e7: mov    WORD PTR [rsp+0x12],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411331ULL);
x86_l_15ee:
	/* 0x15ee: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_15f8:
	/* 0x15f8: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15fd:
	/* 0x15fd: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1604:
	/* 0x1604: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1609:
	/* 0x1609: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_160e:
	/* 0x160e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1610:
	/* 0x1610: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1613:
	/* 0x1613: je     166d <generic_usdt_actions+0x166d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1613, 0x166d, x86_l_166d);
x86_l_1615:
	/* 0x1615: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1617:
	/* 0x1617: jmp    1691 <generic_usdt_actions+0x1691> */
	X86_SIM_X86_JMP(0x1617, 0x1691, x86_l_1691);
x86_l_1619:
	/* 0x1619: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1620:
	/* 0x1620: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1625:
	/* 0x1625: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_162a:
	/* 0x162a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162c:
	/* 0x162c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_162e:
	/* 0x162e: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1632:
	/* 0x1632: jne    1159 <generic_usdt_actions+0x1159> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1632, 0x1159, x86_l_1159);
x86_l_1638:
	/* 0x1638: jmp    17d8 <generic_usdt_actions+0x17d8> */
	X86_SIM_X86_JMP(0x1638, 0x17d8, x86_l_17d8);
x86_l_163d:
	/* 0x163d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1640:
	/* 0x1640: jg     16ee <generic_usdt_actions+0x16ee> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1640, 0x16ee, x86_l_16ee);
x86_l_1646:
	/* 0x1646: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1649:
	/* 0x1649: jg     172c <generic_usdt_actions+0x172c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1649, 0x172c, x86_l_172c);
x86_l_164f:
	/* 0x164f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1651:
	/* 0x1651: je     177d <generic_usdt_actions+0x177d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1651, 0x177d, x86_l_177d);
x86_l_1657:
	/* 0x1657: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165a:
	/* 0x165a: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1662:
	/* 0x1662: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1662, 0x1780, x86_l_1780);
x86_l_1668:
	/* 0x1668: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x1668, 0x1783, x86_l_1783);
x86_l_166d:
	/* 0x166d: mov    DWORD PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_1675:
	/* 0x1675: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_167c:
	/* 0x167c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_167e:
	/* 0x167e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1683:
	/* 0x1683: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1688:
	/* 0x1688: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_168d:
	/* 0x168d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168f:
	/* 0x168f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1691:
	/* 0x1691: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1694:
	/* 0x1694: je     152c <generic_usdt_actions+0x152c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1694, 0x152c, x86_l_152c);
x86_l_169a:
	/* 0x169a: mov    rdi,QWORD PTR [rip+0x6e3a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_16a1:
	/* 0x16a1: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16a6:
	/* 0x16a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16ab:
	/* 0x16ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ad:
	/* 0x16ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b0:
	/* 0x16b0: je     152c <generic_usdt_actions+0x152c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16b0, 0x152c, x86_l_152c);
x86_l_16b6:
	/* 0x16b6: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_16ba:
	/* 0x16ba: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16bd:
	/* 0x16bd: jmp    152c <generic_usdt_actions+0x152c> */
	X86_SIM_X86_JMP(0x16bd, 0x152c, x86_l_152c);
x86_l_16c2:
	/* 0x16c2: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_16c5:
	/* 0x16c5: jg     1710 <generic_usdt_actions+0x1710> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16c5, 0x1710, x86_l_1710);
x86_l_16c7:
	/* 0x16c7: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_16cf:
	/* 0x16cf: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_16d2:
	/* 0x16d2: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16d2, 0x1780, x86_l_1780);
x86_l_16d8:
	/* 0x16d8: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16e0:
	/* 0x16e0: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_16e3:
	/* 0x16e3: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e3, 0x1780, x86_l_1780);
x86_l_16e9:
	/* 0x16e9: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x16e9, 0x1783, x86_l_1783);
x86_l_16ee:
	/* 0x16ee: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_16f1:
	/* 0x16f1: jg     1745 <generic_usdt_actions+0x1745> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16f1, 0x1745, x86_l_1745);
x86_l_16f3:
	/* 0x16f3: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_16fb:
	/* 0x16fb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16fe:
	/* 0x16fe: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fe, 0x1780, x86_l_1780);
x86_l_1704:
	/* 0x1704: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1709:
	/* 0x1709: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_170c:
	/* 0x170c: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170c, 0x1780, x86_l_1780);
x86_l_170e:
	/* 0x170e: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x170e, 0x1783, x86_l_1783);
x86_l_1710:
	/* 0x1710: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1718:
	/* 0x1718: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_171b:
	/* 0x171b: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x171b, 0x1780, x86_l_1780);
x86_l_171d:
	/* 0x171d: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1725:
	/* 0x1725: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1728:
	/* 0x1728: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1728, 0x1780, x86_l_1780);
x86_l_172a:
	/* 0x172a: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x172a, 0x1783, x86_l_1783);
x86_l_172c:
	/* 0x172c: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1734:
	/* 0x1734: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1737:
	/* 0x1737: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1737, 0x1780, x86_l_1780);
x86_l_1739:
	/* 0x1739: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_173e:
	/* 0x173e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1741:
	/* 0x1741: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1741, 0x1780, x86_l_1780);
x86_l_1743:
	/* 0x1743: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x1743, 0x1783, x86_l_1783);
x86_l_1745:
	/* 0x1745: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_174d:
	/* 0x174d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1750:
	/* 0x1750: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1750, 0x1780, x86_l_1780);
x86_l_1752:
	/* 0x1752: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_175a:
	/* 0x175a: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_175d:
	/* 0x175d: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175d, 0x1780, x86_l_1780);
x86_l_175f:
	/* 0x175f: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x175f, 0x1783, x86_l_1783);
x86_l_1761:
	/* 0x1761: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1769:
	/* 0x1769: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_176c:
	/* 0x176c: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x176c, 0x1780, x86_l_1780);
x86_l_176e:
	/* 0x176e: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1776:
	/* 0x1776: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1779:
	/* 0x1779: je     1780 <generic_usdt_actions+0x1780> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1779, 0x1780, x86_l_1780);
x86_l_177b:
	/* 0x177b: jmp    1783 <generic_usdt_actions+0x1783> */
	X86_SIM_X86_JMP(0x177b, 0x1783, x86_l_1783);
x86_l_177d:
	/* 0x177d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1780:
	/* 0x1780: mov    rdi,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1783:
	/* 0x1783: add    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1786:
	/* 0x1786: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178b:
	/* 0x178b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1790:
	/* 0x1790: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1795:
	/* 0x1795: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_179a:
	/* 0x179a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_179f:
	/* 0x179f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a1:
	/* 0x17a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17a3:
	/* 0x17a3: je     17aa <generic_usdt_actions+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17a3, 0x17aa, x86_l_17aa);
x86_l_17a5:
	/* 0x17a5: or     BYTE PTR [r14+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_17aa:
	/* 0x17aa: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17b2:
	/* 0x17b2: mov    rdi,QWORD PTR [rip+0x6e36] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_17b9:
	/* 0x17b9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17be:
	/* 0x17be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17c3:
	/* 0x17c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c5:
	/* 0x17c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17c8:
	/* 0x17c8: je     17d4 <generic_usdt_actions+0x17d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17c8, 0x17d4, x86_l_17d4);
x86_l_17ca:
	/* 0x17ca: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17cf:
	/* 0x17cf: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17d4:
	/* 0x17d4: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17d8:
	/* 0x17d8: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17dc:
	/* 0x17dc: jmp    1159 <generic_usdt_actions+0x1159> */
	X86_SIM_X86_JMP(0x17dc, 0x1159, x86_l_1159);
x86_l_17e1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
