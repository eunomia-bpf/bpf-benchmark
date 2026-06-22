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
	/* 0xa: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     117f <generic_usdt_actions+0x117f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0x117f, x86_l_117f);
x86_l_3e:
	/* 0x3e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    r13d,DWORD PTR [rax+0x5ef4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_48:
	/* 0x48: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_4c:
	/* 0x4c: jl     117f <generic_usdt_actions+0x117f> */
	X86_SIM_X86_JCC(X86_CC_L, 0x4c, 0x117f, x86_l_117f);
x86_l_52:
	/* 0x52: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_59:
	/* 0x59: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_60:
	/* 0x60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65:
	/* 0x65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67:
	/* 0x67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: je     117f <generic_usdt_actions+0x117f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0x117f, x86_l_117f);
x86_l_70:
	/* 0x70: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_73:
	/* 0x73: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_79:
	/* 0x79: add    r13d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7d:
	/* 0x7d: mov    DWORD PTR [rsp+0x104],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_88:
	/* 0x88: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8f:
	/* 0x8f: lea    rsi,[rsp+0x104] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 260ULL);
x86_l_97:
	/* 0x97: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f:
	/* 0x9f: and    r13d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a6:
	/* 0xa6: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a9:
	/* 0xa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab:
	/* 0xab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae:
	/* 0xae: je     db <generic_usdt_actions+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae, 0xdb, x86_l_db);
x86_l_b0:
	/* 0xb0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3:
	/* 0xb3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6:
	/* 0xb6: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_ba:
	/* 0xba: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: xor    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 3ULL);
x86_l_c1:
	/* 0xc1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: xor    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_c8:
	/* 0xc8: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_cb:
	/* 0xcb: xor    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 5ULL);
x86_l_cf:
	/* 0xcf: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d4:
	/* 0xd4: ja     f8 <generic_usdt_actions+0xf8> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd4, 0xf8, x86_l_f8);
x86_l_d6:
	/* 0xd6: jmp    1164 <generic_usdt_actions+0x1164> */
	X86_SIM_X86_JMP(0xd6, 0x1164, x86_l_1164);
x86_l_db:
	/* 0xdb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e0:
	/* 0xe0: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_e5:
	/* 0xe5: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_e8:
	/* 0xe8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ed:
	/* 0xed: cmp    DWORD PTR [r13+0x0],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f2:
	/* 0xf2: jbe    1164 <generic_usdt_actions+0x1164> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf2, 0x1164, x86_l_1164);
x86_l_f8:
	/* 0xf8: mov    QWORD PTR [rsp+0xf8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_108:
	/* 0x108: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10d:
	/* 0x10d: lea    rax,[rbx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_114:
	/* 0x114: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_11c:
	/* 0x11c: lea    rax,[rbx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_123:
	/* 0x123: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12b:
	/* 0x12b: lea    rax,[rbx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12f:
	/* 0x12f: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_137:
	/* 0x137: lea    rax,[rbx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_13b:
	/* 0x13b: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_143:
	/* 0x143: lea    rax,[rbx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_147:
	/* 0x147: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_14f:
	/* 0x14f: lea    rax,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_153:
	/* 0x153: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15b:
	/* 0x15b: lea    rax,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15f:
	/* 0x15f: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_167:
	/* 0x167: lea    rax,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16b:
	/* 0x16b: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_173:
	/* 0x173: lea    rax,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_177:
	/* 0x177: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_17f:
	/* 0x17f: lea    rax,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_183:
	/* 0x183: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18b:
	/* 0x18b: lea    rax,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_197:
	/* 0x197: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19b:
	/* 0x19b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a0:
	/* 0x1a0: lea    rax,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a4:
	/* 0x1a4: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1ac:
	/* 0x1ac: movsxd rbp,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_1b0:
	/* 0x1b0: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b8:
	/* 0x1b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bd:
	/* 0x1bd: lea    rcx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c6:
	/* 0x1c6: lea    rcx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1d2:
	/* 0x1d2: lea    rcx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6:
	/* 0x1d6: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1de:
	/* 0x1de: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1e5:
	/* 0x1e5: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ef:
	/* 0x1ef: je     226 <generic_usdt_actions+0x226> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ef, 0x226, x86_l_226);
x86_l_1f1:
	/* 0x1f1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1f4:
	/* 0x1f4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7:
	/* 0x1f7: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1f9:
	/* 0x1f9: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fd:
	/* 0x1fd: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_200:
	/* 0x200: jg     234 <generic_usdt_actions+0x234> */
	X86_SIM_X86_JCC(X86_CC_G, 0x200, 0x234, x86_l_234);
x86_l_202:
	/* 0x202: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_205:
	/* 0x205: jg     266 <generic_usdt_actions+0x266> */
	X86_SIM_X86_JCC(X86_CC_G, 0x205, 0x266, x86_l_266);
x86_l_207:
	/* 0x207: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_20a:
	/* 0x20a: jg     457 <generic_usdt_actions+0x457> */
	X86_SIM_X86_JCC(X86_CC_G, 0x20a, 0x457, x86_l_457);
x86_l_210:
	/* 0x210: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_212:
	/* 0x212: je     58a <generic_usdt_actions+0x58a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x212, 0x58a, x86_l_58a);
x86_l_218:
	/* 0x218: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_21b:
	/* 0x21b: je     465 <generic_usdt_actions+0x465> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21b, 0x465, x86_l_465);
x86_l_221:
	/* 0x221: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x221, 0x906, x86_l_906);
x86_l_226:
	/* 0x226: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_229:
	/* 0x229: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_22b:
	/* 0x22b: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22f:
	/* 0x22f: jmp    90d <generic_usdt_actions+0x90d> */
	X86_SIM_X86_JMP(0x22f, 0x90d, x86_l_90d);
x86_l_234:
	/* 0x234: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_237:
	/* 0x237: jg     368 <generic_usdt_actions+0x368> */
	X86_SIM_X86_JCC(X86_CC_G, 0x237, 0x368, x86_l_368);
x86_l_23d:
	/* 0x23d: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_240:
	/* 0x240: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_243:
	/* 0x243: jb     4df <generic_usdt_actions+0x4df> */
	X86_SIM_X86_JCC(X86_CC_B, 0x243, 0x4df, x86_l_4df);
x86_l_249:
	/* 0x249: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_24c:
	/* 0x24c: je     4ea <generic_usdt_actions+0x4ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24c, 0x4ea, x86_l_4ea);
x86_l_252:
	/* 0x252: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_255:
	/* 0x255: jne    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x255, 0x906, x86_l_906);
x86_l_25b:
	/* 0x25b: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_261:
	/* 0x261: jmp    4c8 <generic_usdt_actions+0x4c8> */
	X86_SIM_X86_JMP(0x261, 0x4c8, x86_l_4c8);
x86_l_266:
	/* 0x266: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_269:
	/* 0x269: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26c:
	/* 0x26c: jb     4d7 <generic_usdt_actions+0x4d7> */
	X86_SIM_X86_JCC(X86_CC_B, 0x26c, 0x4d7, x86_l_4d7);
x86_l_272:
	/* 0x272: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_275:
	/* 0x275: je     4fa <generic_usdt_actions+0x4fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x275, 0x4fa, x86_l_4fa);
x86_l_27b:
	/* 0x27b: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_27e:
	/* 0x27e: jne    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x27e, 0x906, x86_l_906);
x86_l_284:
	/* 0x284: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288:
	/* 0x288: mov    r15d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_28c:
	/* 0x28c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_295:
	/* 0x295: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29e:
	/* 0x29e: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2a1:
	/* 0x2a1: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a4:
	/* 0x2a4: ja     4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2a4, 0x4bd, x86_l_4bd);
x86_l_2aa:
	/* 0x2aa: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_2b3:
	/* 0x2b3: jne    4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b3, 0x4bd, x86_l_4bd);
x86_l_2b9:
	/* 0x2b9: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_2c1:
	/* 0x2c1: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2c6:
	/* 0x2c6: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_2ce:
	/* 0x2ce: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d2:
	/* 0x2d2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2d7:
	/* 0x2d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9:
	/* 0x2d9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2dd:
	/* 0x2dd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e2:
	/* 0x2e2: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2e9:
	/* 0x2e9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee:
	/* 0x2ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f3:
	/* 0x2f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5:
	/* 0x2f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f8:
	/* 0x2f8: je     4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f8, 0x4bd, x86_l_4bd);
x86_l_2fe:
	/* 0x2fe: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_302:
	/* 0x302: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_306:
	/* 0x306: ja     4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x306, 0x4bd, x86_l_4bd);
x86_l_30c:
	/* 0x30c: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_315:
	/* 0x315: jne    4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x315, 0x4bd, x86_l_4bd);
x86_l_31b:
	/* 0x31b: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_323:
	/* 0x323: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_32b:
	/* 0x32b: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_331:
	/* 0x331: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_339:
	/* 0x339: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33d:
	/* 0x33d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_340:
	/* 0x340: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_345:
	/* 0x345: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_347:
	/* 0x347: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_34b:
	/* 0x34b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_350:
	/* 0x350: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_357:
	/* 0x357: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_359:
	/* 0x359: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e:
	/* 0x35e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_363:
	/* 0x363: jmp    6c5 <generic_usdt_actions+0x6c5> */
	X86_SIM_X86_JMP(0x363, 0x6c5, x86_l_6c5);
x86_l_368:
	/* 0x368: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_36b:
	/* 0x36b: je     5ef <generic_usdt_actions+0x5ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36b, 0x5ef, x86_l_5ef);
x86_l_371:
	/* 0x371: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_374:
	/* 0x374: je     512 <generic_usdt_actions+0x512> */
	X86_SIM_X86_JCC(X86_CC_E, 0x374, 0x512, x86_l_512);
x86_l_37a:
	/* 0x37a: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_37d:
	/* 0x37d: jne    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37d, 0x906, x86_l_906);
x86_l_383:
	/* 0x383: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_389:
	/* 0x389: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_38c:
	/* 0x38c: je     607 <generic_usdt_actions+0x607> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38c, 0x607, x86_l_607);
x86_l_392:
	/* 0x392: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_396:
	/* 0x396: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_39b:
	/* 0x39b: mov    eax,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_39f:
	/* 0x39f: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a3:
	/* 0x3a3: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3a6:
	/* 0x3a6: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_3ad:
	/* 0x3ad: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_3b4:
	/* 0x3b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b9:
	/* 0x3b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bb:
	/* 0x3bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3be:
	/* 0x3be: je     738 <generic_usdt_actions+0x738> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3be, 0x738, x86_l_738);
x86_l_3c4:
	/* 0x3c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c9:
	/* 0x3c9: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ce:
	/* 0x3ce: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3d3:
	/* 0x3d3: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3d6:
	/* 0x3d6: lea    rdx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_3da:
	/* 0x3da: cmp    BYTE PTR [rax+rdx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 3), 2272037699587ULL);
x86_l_3e2:
	/* 0x3e2: jne    8d7 <generic_usdt_actions+0x8d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3e2, 0x8d7, x86_l_8d7);
x86_l_3e8:
	/* 0x3e8: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_3ec:
	/* 0x3ec: add    rcx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_3f3:
	/* 0x3f3: rorx   eax,DWORD PTR [rax+rdx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_3fe:
	/* 0x3fe: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_403:
	/* 0x403: jle    770 <generic_usdt_actions+0x770> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x403, 0x770, x86_l_770);
x86_l_409:
	/* 0x409: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_40c:
	/* 0x40c: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_410:
	/* 0x410: jle    7fe <generic_usdt_actions+0x7fe> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x410, 0x7fe, x86_l_7fe);
x86_l_416:
	/* 0x416: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_419:
	/* 0x419: jle    899 <generic_usdt_actions+0x899> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x419, 0x899, x86_l_899);
x86_l_41f:
	/* 0x41f: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_427:
	/* 0x427: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_42a:
	/* 0x42a: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42a, 0x8b3, x86_l_8b3);
x86_l_430:
	/* 0x430: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_438:
	/* 0x438: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_43b:
	/* 0x43b: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43b, 0x8b3, x86_l_8b3);
x86_l_441:
	/* 0x441: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_444:
	/* 0x444: jne    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x444, 0x8b6, x86_l_8b6);
x86_l_44a:
	/* 0x44a: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_452:
	/* 0x452: jmp    8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JMP(0x452, 0x8b3, x86_l_8b3);
x86_l_457:
	/* 0x457: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_45a:
	/* 0x45a: je     4c8 <generic_usdt_actions+0x4c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45a, 0x4c8, x86_l_4c8);
x86_l_45c:
	/* 0x45c: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_45f:
	/* 0x45f: jne    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45f, 0x906, x86_l_906);
x86_l_465:
	/* 0x465: mov    r15d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_469:
	/* 0x469: mov    eax,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_46d:
	/* 0x46d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_472:
	/* 0x472: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_484:
	/* 0x484: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_48c:
	/* 0x48c: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_493:
	/* 0x493: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_498:
	/* 0x498: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49d:
	/* 0x49d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f:
	/* 0x49f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: je     4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a2, 0x4bd, x86_l_4bd);
x86_l_4a4:
	/* 0x4a4: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4a8:
	/* 0x4a8: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4ac:
	/* 0x4ac: ja     4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4ac, 0x4bd, x86_l_4bd);
x86_l_4ae:
	/* 0x4ae: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_4b7:
	/* 0x4b7: je     616 <generic_usdt_actions+0x616> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b7, 0x616, x86_l_616);
x86_l_4bd:
	/* 0x4bd: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_4c3:
	/* 0x4c3: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x4c3, 0x906, x86_l_906);
x86_l_4c8:
	/* 0x4c8: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4cd:
	/* 0x4cd: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d2:
	/* 0x4d2: jmp    8dc <generic_usdt_actions+0x8dc> */
	X86_SIM_X86_JMP(0x4d2, 0x8dc, x86_l_8dc);
x86_l_4d7:
	/* 0x4d7: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4db:
	/* 0x4db: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4df:
	/* 0x4df: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_4e5:
	/* 0x4e5: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x4e5, 0x906, x86_l_906);
x86_l_4ea:
	/* 0x4ea: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_4f2:
	/* 0x4f2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f5:
	/* 0x4f5: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x4f5, 0x906, x86_l_906);
x86_l_4fa:
	/* 0x4fa: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_500:
	/* 0x500: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_508:
	/* 0x508: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50d:
	/* 0x50d: jmp    8dc <generic_usdt_actions+0x8dc> */
	X86_SIM_X86_JMP(0x50d, 0x8dc, x86_l_8dc);
x86_l_512:
	/* 0x512: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_517:
	/* 0x517: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_519:
	/* 0x519: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_51e:
	/* 0x51e: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_525:
	/* 0x525: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_52a:
	/* 0x52a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52f:
	/* 0x52f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_531:
	/* 0x531: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_534:
	/* 0x534: je     906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_E, 0x534, 0x906, x86_l_906);
x86_l_53a:
	/* 0x53a: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53e:
	/* 0x53e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_543:
	/* 0x543: mov    DWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_54b:
	/* 0x54b: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_552:
	/* 0x552: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_557:
	/* 0x557: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55c:
	/* 0x55c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55e:
	/* 0x55e: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_566:
	/* 0x566: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_569:
	/* 0x569: je     6d1 <generic_usdt_actions+0x6d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x569, 0x6d1, x86_l_6d1);
x86_l_56f:
	/* 0x56f: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_572:
	/* 0x572: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_579:
	/* 0x579: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_57e:
	/* 0x57e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_583:
	/* 0x583: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_585:
	/* 0x585: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x585, 0x906, x86_l_906);
x86_l_58a:
	/* 0x58a: cmp    DWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_58f:
	/* 0x58f: je     5b2 <generic_usdt_actions+0x5b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58f, 0x5b2, x86_l_5b2);
x86_l_591:
	/* 0x591: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_596:
	/* 0x596: mov    rsi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_59d:
	/* 0x59d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59f:
	/* 0x59f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_5a4:
	/* 0x5a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5a7:
	/* 0x5a7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a9:
	/* 0x5a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ab:
	/* 0x5ab: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b2:
	/* 0x5b2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_5b8:
	/* 0x5b8: cmp    DWORD PTR [r13+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_5bd:
	/* 0x5bd: je     906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5bd, 0x906, x86_l_906);
x86_l_5c3:
	/* 0x5c3: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_5c8:
	/* 0x5c8: mov    rsi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_5cf:
	/* 0x5cf: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_5d4:
	/* 0x5d4: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_5d9:
	/* 0x5d9: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_5de:
	/* 0x5de: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e1:
	/* 0x5e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e3:
	/* 0x5e3: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_5ea:
	/* 0x5ea: jmp    906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JMP(0x5ea, 0x906, x86_l_906);
x86_l_5ef:
	/* 0x5ef: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_5f5:
	/* 0x5f5: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_5fd:
	/* 0x5fd: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_602:
	/* 0x602: jmp    8dc <generic_usdt_actions+0x8dc> */
	X86_SIM_X86_JMP(0x602, 0x8dc, x86_l_8dc);
x86_l_607:
	/* 0x607: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_60c:
	/* 0x60c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_611:
	/* 0x611: jmp    8dc <generic_usdt_actions+0x8dc> */
	X86_SIM_X86_JMP(0x611, 0x8dc, x86_l_8dc);
x86_l_616:
	/* 0x616: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_61b:
	/* 0x61b: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_623:
	/* 0x623: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_62b:
	/* 0x62b: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_630:
	/* 0x630: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_638:
	/* 0x638: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63c:
	/* 0x63c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_641:
	/* 0x641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643:
	/* 0x643: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_647:
	/* 0x647: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64c:
	/* 0x64c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_64f:
	/* 0x64f: jne    747 <generic_usdt_actions+0x747> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x64f, 0x747, x86_l_747);
x86_l_655:
	/* 0x655: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65a:
	/* 0x65a: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_65d:
	/* 0x65d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_660:
	/* 0x660: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_665:
	/* 0x665: ja     4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x665, 0x4bd, x86_l_4bd);
x86_l_66b:
	/* 0x66b: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_66e:
	/* 0x66e: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_677:
	/* 0x677: jne    4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x677, 0x4bd, x86_l_4bd);
x86_l_67d:
	/* 0x67d: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_685:
	/* 0x685: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_68b:
	/* 0x68b: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_68f:
	/* 0x68f: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_696:
	/* 0x696: mov    esi,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_69e:
	/* 0x69e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6a4:
	/* 0x6a4: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6a8:
	/* 0x6a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ad:
	/* 0x6ad: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6b0:
	/* 0x6b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b2:
	/* 0x6b2: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_6b9:
	/* 0x6b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6bb:
	/* 0x6bb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6c0:
	/* 0x6c0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6c5:
	/* 0x6c5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6c8:
	/* 0x6c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ca:
	/* 0x6ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cc:
	/* 0x6cc: jmp    4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JMP(0x6cc, 0x4bd, x86_l_4bd);
x86_l_6d1:
	/* 0x6d1: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_6d8:
	/* 0x6d8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6dd:
	/* 0x6dd: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6e2:
	/* 0x6e2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6e7:
	/* 0x6e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6ec:
	/* 0x6ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ee:
	/* 0x6ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f1:
	/* 0x6f1: je     572 <generic_usdt_actions+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f1, 0x572, x86_l_572);
x86_l_6f7:
	/* 0x6f7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fc:
	/* 0x6fc: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6fe:
	/* 0x6fe: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_703:
	/* 0x703: mov    WORD PTR [rsp+0x12],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411331ULL);
x86_l_70a:
	/* 0x70a: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_714:
	/* 0x714: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_719:
	/* 0x719: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_720:
	/* 0x720: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_725:
	/* 0x725: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_72a:
	/* 0x72a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72c:
	/* 0x72c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72f:
	/* 0x72f: je     7a7 <generic_usdt_actions+0x7a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72f, 0x7a7, x86_l_7a7);
x86_l_731:
	/* 0x731: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_733:
	/* 0x733: jmp    7cb <generic_usdt_actions+0x7cb> */
	X86_SIM_X86_JMP(0x733, 0x7cb, x86_l_7cb);
x86_l_738:
	/* 0x738: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_73d:
	/* 0x73d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_742:
	/* 0x742: jmp    8dc <generic_usdt_actions+0x8dc> */
	X86_SIM_X86_JMP(0x742, 0x8dc, x86_l_8dc);
x86_l_747:
	/* 0x747: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_74e:
	/* 0x74e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_753:
	/* 0x753: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_758:
	/* 0x758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75a:
	/* 0x75a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75d:
	/* 0x75d: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_75f:
	/* 0x75f: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_763:
	/* 0x763: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_765:
	/* 0x765: jne    90d <generic_usdt_actions+0x90d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x765, 0x90d, x86_l_90d);
x86_l_76b:
	/* 0x76b: jmp    4bd <generic_usdt_actions+0x4bd> */
	X86_SIM_X86_JMP(0x76b, 0x4bd, x86_l_4bd);
x86_l_770:
	/* 0x770: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_773:
	/* 0x773: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_777:
	/* 0x777: jg     82a <generic_usdt_actions+0x82a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x777, 0x82a, x86_l_82a);
x86_l_77d:
	/* 0x77d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_780:
	/* 0x780: jg     864 <generic_usdt_actions+0x864> */
	X86_SIM_X86_JCC(X86_CC_G, 0x780, 0x864, x86_l_864);
x86_l_786:
	/* 0x786: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_789:
	/* 0x789: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_78b:
	/* 0x78b: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78b, 0x8b3, x86_l_8b3);
x86_l_791:
	/* 0x791: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_799:
	/* 0x799: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_79c:
	/* 0x79c: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79c, 0x8b3, x86_l_8b3);
x86_l_7a2:
	/* 0x7a2: jmp    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JMP(0x7a2, 0x8b6, x86_l_8b6);
x86_l_7a7:
	/* 0x7a7: mov    DWORD PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_7af:
	/* 0x7af: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7b6:
	/* 0x7b6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b8:
	/* 0x7b8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7bd:
	/* 0x7bd: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_7c2:
	/* 0x7c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7c7:
	/* 0x7c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c9:
	/* 0x7c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cb:
	/* 0x7cb: cmp    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_7d0:
	/* 0x7d0: je     572 <generic_usdt_actions+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d0, 0x572, x86_l_572);
x86_l_7d6:
	/* 0x7d6: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7dd:
	/* 0x7dd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e2:
	/* 0x7e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e7:
	/* 0x7e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e9:
	/* 0x7e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ec:
	/* 0x7ec: je     572 <generic_usdt_actions+0x572> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ec, 0x572, x86_l_572);
x86_l_7f2:
	/* 0x7f2: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_7f6:
	/* 0x7f6: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7f9:
	/* 0x7f9: jmp    572 <generic_usdt_actions+0x572> */
	X86_SIM_X86_JMP(0x7f9, 0x572, x86_l_572);
x86_l_7fe:
	/* 0x7fe: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_801:
	/* 0x801: jg     848 <generic_usdt_actions+0x848> */
	X86_SIM_X86_JCC(X86_CC_G, 0x801, 0x848, x86_l_848);
x86_l_803:
	/* 0x803: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_80b:
	/* 0x80b: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_80e:
	/* 0x80e: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80e, 0x8b3, x86_l_8b3);
x86_l_814:
	/* 0x814: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_81c:
	/* 0x81c: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_81f:
	/* 0x81f: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81f, 0x8b3, x86_l_8b3);
x86_l_825:
	/* 0x825: jmp    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JMP(0x825, 0x8b6, x86_l_8b6);
x86_l_82a:
	/* 0x82a: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_82d:
	/* 0x82d: jg     87d <generic_usdt_actions+0x87d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x82d, 0x87d, x86_l_87d);
x86_l_82f:
	/* 0x82f: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_837:
	/* 0x837: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_83a:
	/* 0x83a: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83a, 0x8b3, x86_l_8b3);
x86_l_83c:
	/* 0x83c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_841:
	/* 0x841: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_844:
	/* 0x844: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x844, 0x8b3, x86_l_8b3);
x86_l_846:
	/* 0x846: jmp    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JMP(0x846, 0x8b6, x86_l_8b6);
x86_l_848:
	/* 0x848: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_850:
	/* 0x850: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_853:
	/* 0x853: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x853, 0x8b3, x86_l_8b3);
x86_l_855:
	/* 0x855: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_85d:
	/* 0x85d: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_860:
	/* 0x860: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x860, 0x8b3, x86_l_8b3);
x86_l_862:
	/* 0x862: jmp    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JMP(0x862, 0x8b6, x86_l_8b6);
x86_l_864:
	/* 0x864: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_86c:
	/* 0x86c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_86f:
	/* 0x86f: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x86f, 0x8b3, x86_l_8b3);
x86_l_871:
	/* 0x871: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_876:
	/* 0x876: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_879:
	/* 0x879: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x879, 0x8b3, x86_l_8b3);
x86_l_87b:
	/* 0x87b: jmp    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JMP(0x87b, 0x8b6, x86_l_8b6);
x86_l_87d:
	/* 0x87d: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_885:
	/* 0x885: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_888:
	/* 0x888: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x888, 0x8b3, x86_l_8b3);
x86_l_88a:
	/* 0x88a: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_892:
	/* 0x892: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_895:
	/* 0x895: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x895, 0x8b3, x86_l_8b3);
x86_l_897:
	/* 0x897: jmp    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JMP(0x897, 0x8b6, x86_l_8b6);
x86_l_899:
	/* 0x899: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_8a1:
	/* 0x8a1: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_8a4:
	/* 0x8a4: je     8b3 <generic_usdt_actions+0x8b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a4, 0x8b3, x86_l_8b3);
x86_l_8a6:
	/* 0x8a6: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8ae:
	/* 0x8ae: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_8b1:
	/* 0x8b1: jne    8b6 <generic_usdt_actions+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b1, 0x8b6, x86_l_8b6);
x86_l_8b3:
	/* 0x8b3: mov    rdi,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b6:
	/* 0x8b6: add    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_8b9:
	/* 0x8b9: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8bd:
	/* 0x8bd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c2:
	/* 0x8c2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8c7:
	/* 0x8c7: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_8cc:
	/* 0x8cc: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_8d1:
	/* 0x8d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d3:
	/* 0x8d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8d5:
	/* 0x8d5: je     8dc <generic_usdt_actions+0x8dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d5, 0x8dc, x86_l_8dc);
x86_l_8d7:
	/* 0x8d7: or     BYTE PTR [r14+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_8dc:
	/* 0x8dc: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_8e4:
	/* 0x8e4: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_8eb:
	/* 0x8eb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f0:
	/* 0x8f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f5:
	/* 0x8f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f7:
	/* 0x8f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8fa:
	/* 0x8fa: je     906 <generic_usdt_actions+0x906> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fa, 0x906, x86_l_906);
x86_l_8fc:
	/* 0x8fc: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_901:
	/* 0x901: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_906:
	/* 0x906: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_90a:
	/* 0x90a: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_90d:
	/* 0x90d: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_915:
	/* 0x915: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_919:
	/* 0x919: jae    115c <generic_usdt_actions+0x115c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x919, 0x115c, x86_l_115c);
x86_l_91f:
	/* 0x91f: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_924:
	/* 0x924: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_927:
	/* 0x927: mov    r14d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_32);
x86_l_92a:
	/* 0x92a: movsxd r15,DWORD PTR [r13+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R14, 2, X86_WIDTH_32), 4ULL);
x86_l_92f:
	/* 0x92f: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_937:
	/* 0x937: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_93e:
	/* 0x93e: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_943:
	/* 0x943: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_948:
	/* 0x948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94a:
	/* 0x94a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94c:
	/* 0x94c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94f:
	/* 0x94f: je     987 <generic_usdt_actions+0x987> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94f, 0x987, x86_l_987);
x86_l_951:
	/* 0x951: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_954:
	/* 0x954: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_958:
	/* 0x958: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_95b:
	/* 0x95b: jg     991 <generic_usdt_actions+0x991> */
	X86_SIM_X86_JCC(X86_CC_G, 0x95b, 0x991, x86_l_991);
x86_l_95d:
	/* 0x95d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_960:
	/* 0x960: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_963:
	/* 0x963: jg     9d3 <generic_usdt_actions+0x9d3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x963, 0x9d3, x86_l_9d3);
x86_l_965:
	/* 0x965: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_968:
	/* 0x968: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_96b:
	/* 0x96b: jg     bec <generic_usdt_actions+0xbec> */
	X86_SIM_X86_JCC(X86_CC_G, 0x96b, 0xbec, x86_l_bec);
x86_l_971:
	/* 0x971: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_973:
	/* 0x973: je     d23 <generic_usdt_actions+0xd23> */
	X86_SIM_X86_JCC(X86_CC_E, 0x973, 0xd23, x86_l_d23);
x86_l_979:
	/* 0x979: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_97c:
	/* 0x97c: je     bfe <generic_usdt_actions+0xbfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97c, 0xbfe, x86_l_bfe);
x86_l_982:
	/* 0x982: jmp    10e1 <generic_usdt_actions+0x10e1> */
	X86_SIM_X86_JMP(0x982, 0x10e1, x86_l_10e1);
x86_l_987:
	/* 0x987: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98c:
	/* 0x98c: jmp    10f3 <generic_usdt_actions+0x10f3> */
	X86_SIM_X86_JMP(0x98c, 0x10f3, x86_l_10f3);
x86_l_991:
	/* 0x991: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_994:
	/* 0x994: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_997:
	/* 0x997: jg     afc <generic_usdt_actions+0xafc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x997, 0xafc, x86_l_afc);
x86_l_99d:
	/* 0x99d: lea    eax,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_9a0:
	/* 0x9a0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9a3:
	/* 0x9a3: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a8:
	/* 0x9a8: jb     c6e <generic_usdt_actions+0xc6e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9a8, 0xc6e, x86_l_c6e);
x86_l_9ae:
	/* 0x9ae: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9b1:
	/* 0x9b1: je     c86 <generic_usdt_actions+0xc86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b1, 0xc86, x86_l_c86);
x86_l_9b7:
	/* 0x9b7: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_9ba:
	/* 0x9ba: jne    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9ba, 0x10e9, x86_l_10e9);
x86_l_9c0:
	/* 0x9c0: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_9c3:
	/* 0x9c3: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_9c6:
	/* 0x9c6: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9c9:
	/* 0x9c9: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ce:
	/* 0x9ce: jmp    10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JMP(0x9ce, 0x10b9, x86_l_10b9);
x86_l_9d3:
	/* 0x9d3: lea    eax,[rcx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_9d6:
	/* 0x9d6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9d9:
	/* 0x9d9: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9de:
	/* 0x9de: jb     c76 <generic_usdt_actions+0xc76> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9de, 0xc76, x86_l_c76);
x86_l_9e4:
	/* 0x9e4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9e7:
	/* 0x9e7: je     c93 <generic_usdt_actions+0xc93> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e7, 0xc93, x86_l_c93);
x86_l_9ed:
	/* 0x9ed: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9f0:
	/* 0x9f0: jne    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9f0, 0x10e9, x86_l_10e9);
x86_l_9f6:
	/* 0x9f6: mov    eax,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_9fb:
	/* 0x9fb: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_9ff:
	/* 0x9ff: mov    r14d,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_a04:
	/* 0xa04: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a0d:
	/* 0xa0d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a16:
	/* 0xa16: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a19:
	/* 0xa19: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a1c:
	/* 0xa1c: ja     10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa1c, 0x10e9, x86_l_10e9);
x86_l_a22:
	/* 0xa22: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_a2a:
	/* 0xa2a: jne    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa2a, 0x10e9, x86_l_10e9);
x86_l_a30:
	/* 0xa30: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_a38:
	/* 0xa38: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a3d:
	/* 0xa3d: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_a44:
	/* 0xa44: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a48:
	/* 0xa48: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a52:
	/* 0xa52: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_a55:
	/* 0xa55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a57:
	/* 0xa57: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_a5b:
	/* 0xa5b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a60:
	/* 0xa60: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_a67:
	/* 0xa67: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a6c:
	/* 0xa6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a71:
	/* 0xa71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a73:
	/* 0xa73: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a76:
	/* 0xa76: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a7b:
	/* 0xa7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7e:
	/* 0xa7e: je     10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7e, 0x10e9, x86_l_10e9);
x86_l_a84:
	/* 0xa84: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_a88:
	/* 0xa88: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_a8c:
	/* 0xa8c: ja     10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa8c, 0x10e9, x86_l_10e9);
x86_l_a92:
	/* 0xa92: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_a9b:
	/* 0xa9b: jne    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa9b, 0x10e9, x86_l_10e9);
x86_l_aa1:
	/* 0xaa1: mov    rcx,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_aa9:
	/* 0xaa9: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_ab1:
	/* 0xab1: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ab7:
	/* 0xab7: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_abe:
	/* 0xabe: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ac2:
	/* 0xac2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_ac5:
	/* 0xac5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_aca:
	/* 0xaca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acc:
	/* 0xacc: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ad0:
	/* 0xad0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad5:
	/* 0xad5: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_adc:
	/* 0xadc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ade:
	/* 0xade: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae3:
	/* 0xae3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ae8:
	/* 0xae8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_aeb:
	/* 0xaeb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aed:
	/* 0xaed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aef:
	/* 0xaef: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_af2:
	/* 0xaf2: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_af7:
	/* 0xaf7: jmp    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JMP(0xaf7, 0x10e9, x86_l_10e9);
x86_l_afc:
	/* 0xafc: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_aff:
	/* 0xaff: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_b02:
	/* 0xb02: je     daa <generic_usdt_actions+0xdaa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb02, 0xdaa, x86_l_daa);
x86_l_b08:
	/* 0xb08: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_b0b:
	/* 0xb0b: je     ca9 <generic_usdt_actions+0xca9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0b, 0xca9, x86_l_ca9);
x86_l_b11:
	/* 0xb11: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_b14:
	/* 0xb14: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b17:
	/* 0xb17: jne    10e4 <generic_usdt_actions+0x10e4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb17, 0x10e4, x86_l_10e4);
x86_l_b1d:
	/* 0xb1d: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_b20:
	/* 0xb20: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_b24:
	/* 0xb24: cmp    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b29:
	/* 0xb29: je     dbe <generic_usdt_actions+0xdbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb29, 0xdbe, x86_l_dbe);
x86_l_b2f:
	/* 0xb2f: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_b32:
	/* 0xb32: mov    eax,DWORD PTR [r13+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_b37:
	/* 0xb37: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b3b:
	/* 0xb3b: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_b40:
	/* 0xb40: add    rdx,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_b47:
	/* 0xb47: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_b4e:
	/* 0xb4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b53:
	/* 0xb53: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b56:
	/* 0xb56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b58:
	/* 0xb58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b5b:
	/* 0xb5b: je     eee <generic_usdt_actions+0xeee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5b, 0xeee, x86_l_eee);
x86_l_b61:
	/* 0xb61: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b65:
	/* 0xb65: lea    rdx,[r14+r14*2] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 0ULL);
x86_l_b69:
	/* 0xb69: cmp    BYTE PTR [rax+rdx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 3), 2272037699587ULL);
x86_l_b71:
	/* 0xb71: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_b77:
	/* 0xb77: jne    10b3 <generic_usdt_actions+0x10b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb77, 0x10b3, x86_l_10b3);
x86_l_b7d:
	/* 0xb7d: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_b81:
	/* 0xb81: add    rcx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_b88:
	/* 0xb88: rorx   eax,DWORD PTR [rax+rdx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_b93:
	/* 0xb93: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b95:
	/* 0xb95: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_b98:
	/* 0xb98: jle    f26 <generic_usdt_actions+0xf26> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb98, 0xf26, x86_l_f26);
x86_l_b9e:
	/* 0xb9e: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_ba1:
	/* 0xba1: jle    fae <generic_usdt_actions+0xfae> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xba1, 0xfae, x86_l_fae);
x86_l_ba7:
	/* 0xba7: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_baa:
	/* 0xbaa: jle    1068 <generic_usdt_actions+0x1068> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xbaa, 0x1068, x86_l_1068);
x86_l_bb0:
	/* 0xbb0: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_bb8:
	/* 0xbb8: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_bbb:
	/* 0xbbb: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bbf:
	/* 0xbbf: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbf, 0x108f, x86_l_108f);
x86_l_bc5:
	/* 0xbc5: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bcd:
	/* 0xbcd: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_bd0:
	/* 0xbd0: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd0, 0x108f, x86_l_108f);
x86_l_bd6:
	/* 0xbd6: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bde:
	/* 0xbde: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_be1:
	/* 0xbe1: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe1, 0x108f, x86_l_108f);
x86_l_be7:
	/* 0xbe7: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0xbe7, 0x1092, x86_l_1092);
x86_l_bec:
	/* 0xbec: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bef:
	/* 0xbef: je     d9d <generic_usdt_actions+0xd9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbef, 0xd9d, x86_l_d9d);
x86_l_bf5:
	/* 0xbf5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bf8:
	/* 0xbf8: jne    10e1 <generic_usdt_actions+0x10e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbf8, 0x10e1, x86_l_10e1);
x86_l_bfe:
	/* 0xbfe: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c03:
	/* 0xc03: mov    r14d,DWORD PTR [r13+r14*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 8ULL);
x86_l_c08:
	/* 0xc08: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_c0c:
	/* 0xc0c: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_c11:
	/* 0xc11: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c16:
	/* 0xc16: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c1f:
	/* 0xc1f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c28:
	/* 0xc28: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_c30:
	/* 0xc30: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_c37:
	/* 0xc37: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c3c:
	/* 0xc3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c41:
	/* 0xc41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c43:
	/* 0xc43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c46:
	/* 0xc46: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c49:
	/* 0xc49: je     c64 <generic_usdt_actions+0xc64> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc49, 0xc64, x86_l_c64);
x86_l_c4b:
	/* 0xc4b: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_c4f:
	/* 0xc4f: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_c53:
	/* 0xc53: ja     c64 <generic_usdt_actions+0xc64> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc53, 0xc64, x86_l_c64);
x86_l_c55:
	/* 0xc55: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_c5e:
	/* 0xc5e: je     dc9 <generic_usdt_actions+0xdc9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5e, 0xdc9, x86_l_dc9);
x86_l_c64:
	/* 0xc64: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c69:
	/* 0xc69: jmp    10e4 <generic_usdt_actions+0x10e4> */
	X86_SIM_X86_JMP(0xc69, 0x10e4, x86_l_10e4);
x86_l_c6e:
	/* 0xc6e: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c71:
	/* 0xc71: jmp    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JMP(0xc71, 0x10e9, x86_l_10e9);
x86_l_c76:
	/* 0xc76: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c79:
	/* 0xc79: mov    eax,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_c7e:
	/* 0xc7e: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c81:
	/* 0xc81: jmp    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JMP(0xc81, 0x10e9, x86_l_10e9);
x86_l_c86:
	/* 0xc86: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_c8e:
	/* 0xc8e: jmp    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JMP(0xc8e, 0x10e9, x86_l_10e9);
x86_l_c93:
	/* 0xc93: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_c96:
	/* 0xc96: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_c99:
	/* 0xc99: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c9c:
	/* 0xc9c: mov    r14,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_ca4:
	/* 0xca4: jmp    10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JMP(0xca4, 0x10b9, x86_l_10b9);
x86_l_ca9:
	/* 0xca9: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_cac:
	/* 0xcac: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cb1:
	/* 0xcb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb3:
	/* 0xcb3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cb8:
	/* 0xcb8: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_cbf:
	/* 0xcbf: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cc4:
	/* 0xcc4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cc9:
	/* 0xcc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ccb:
	/* 0xccb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cce:
	/* 0xcce: je     d1b <generic_usdt_actions+0xd1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcce, 0xd1b, x86_l_d1b);
x86_l_cd0:
	/* 0xcd0: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cd4:
	/* 0xcd4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cd9:
	/* 0xcd9: mov    DWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_ce1:
	/* 0xce1: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_ce8:
	/* 0xce8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ced:
	/* 0xced: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cf2:
	/* 0xcf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf4:
	/* 0xcf4: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_cfc:
	/* 0xcfc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cff:
	/* 0xcff: je     e89 <generic_usdt_actions+0xe89> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcff, 0xe89, x86_l_e89);
x86_l_d05:
	/* 0xd05: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d08:
	/* 0xd08: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_d0f:
	/* 0xd0f: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d14:
	/* 0xd14: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_d19:
	/* 0xd19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1b:
	/* 0xd1b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d1e:
	/* 0xd1e: jmp    10e1 <generic_usdt_actions+0x10e1> */
	X86_SIM_X86_JMP(0xd1e, 0x10e1, x86_l_10e1);
x86_l_d23:
	/* 0xd23: cmp    DWORD PTR [r13+r14*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 68719476736ULL);
x86_l_d29:
	/* 0xd29: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d2c:
	/* 0xd2c: je     d58 <generic_usdt_actions+0xd58> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2c, 0xd58, x86_l_d58);
x86_l_d2e:
	/* 0xd2e: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_d32:
	/* 0xd32: mov    rsi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_d39:
	/* 0xd39: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_d3c:
	/* 0xd3c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d3e:
	/* 0xd3e: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d43:
	/* 0xd43: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d46:
	/* 0xd46: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d48:
	/* 0xd48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4a:
	/* 0xd4a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d4d:
	/* 0xd4d: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d50:
	/* 0xd50: mov    QWORD PTR [r12+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d58:
	/* 0xd58: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_d5c:
	/* 0xd5c: cmp    DWORD PTR [r13+r15*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 17179869184ULL);
x86_l_d62:
	/* 0xd62: je     10e4 <generic_usdt_actions+0x10e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd62, 0x10e4, x86_l_10e4);
x86_l_d68:
	/* 0xd68: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_d6c:
	/* 0xd6c: mov    rsi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_d73:
	/* 0xd73: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_d76:
	/* 0xd76: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_d7b:
	/* 0xd7b: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d80:
	/* 0xd80: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_d85:
	/* 0xd85: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8a:
	/* 0xd8a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d8d:
	/* 0xd8d: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d90:
	/* 0xd90: mov    QWORD PTR [r12+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d98:
	/* 0xd98: jmp    10e4 <generic_usdt_actions+0x10e4> */
	X86_SIM_X86_JMP(0xd98, 0x10e4, x86_l_10e4);
x86_l_d9d:
	/* 0xd9d: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_da5:
	/* 0xda5: jmp    10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JMP(0xda5, 0x10b9, x86_l_10b9);
x86_l_daa:
	/* 0xdaa: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_dad:
	/* 0xdad: add    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_db1:
	/* 0xdb1: mov    r14,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_db9:
	/* 0xdb9: jmp    10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JMP(0xdb9, 0x10b9, x86_l_10b9);
x86_l_dbe:
	/* 0xdbe: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_dc4:
	/* 0xdc4: jmp    10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JMP(0xdc4, 0x10b9, x86_l_10b9);
x86_l_dc9:
	/* 0xdc9: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_dce:
	/* 0xdce: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_dd6:
	/* 0xdd6: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_dde:
	/* 0xdde: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_de3:
	/* 0xde3: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_dea:
	/* 0xdea: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dee:
	/* 0xdee: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_df3:
	/* 0xdf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df5:
	/* 0xdf5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_df9:
	/* 0xdf9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfe:
	/* 0xdfe: cmp    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_e03:
	/* 0xe03: jne    ef9 <generic_usdt_actions+0xef9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe03, 0xef9, x86_l_ef9);
x86_l_e09:
	/* 0xe09: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e0e:
	/* 0xe0e: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_e11:
	/* 0xe11: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e14:
	/* 0xe14: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e19:
	/* 0xe19: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e1c:
	/* 0xe1c: ja     c64 <generic_usdt_actions+0xc64> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe1c, 0xc64, x86_l_c64);
x86_l_e22:
	/* 0xe22: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e25:
	/* 0xe25: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_e2d:
	/* 0xe2d: jne    c64 <generic_usdt_actions+0xc64> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe2d, 0xc64, x86_l_c64);
x86_l_e33:
	/* 0xe33: mov    rcx,QWORD PTR [rdx+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_e3b:
	/* 0xe3b: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e41:
	/* 0xe41: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e44:
	/* 0xe44: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_e4b:
	/* 0xe4b: mov    esi,DWORD PTR [r12+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_e53:
	/* 0xe53: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e59:
	/* 0xe59: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e5d:
	/* 0xe5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e62:
	/* 0xe62: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e65:
	/* 0xe65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e67:
	/* 0xe67: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_e6e:
	/* 0xe6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e70:
	/* 0xe70: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e75:
	/* 0xe75: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e7a:
	/* 0xe7a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7f:
	/* 0xe7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e81:
	/* 0xe81: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: jmp    c64 <generic_usdt_actions+0xc64> */
	X86_SIM_X86_JMP(0xe84, 0xc64, x86_l_c64);
x86_l_e89:
	/* 0xe89: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_e90:
	/* 0xe90: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e95:
	/* 0xe95: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_e9a:
	/* 0xe9a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e9f:
	/* 0xe9f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ea4:
	/* 0xea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea6:
	/* 0xea6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea9:
	/* 0xea9: je     d08 <generic_usdt_actions+0xd08> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea9, 0xd08, x86_l_d08);
x86_l_eaf:
	/* 0xeaf: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_eb2:
	/* 0xeb2: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_eb4:
	/* 0xeb4: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb9:
	/* 0xeb9: mov    WORD PTR [rsp+0x12],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411331ULL);
x86_l_ec0:
	/* 0xec0: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_eca:
	/* 0xeca: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_ecf:
	/* 0xecf: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ed6:
	/* 0xed6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_edb:
	/* 0xedb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ee0:
	/* 0xee0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee2:
	/* 0xee2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee5:
	/* 0xee5: je     f5a <generic_usdt_actions+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee5, 0xf5a, x86_l_f5a);
x86_l_ee7:
	/* 0xee7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ee9:
	/* 0xee9: jmp    f7e <generic_usdt_actions+0xf7e> */
	X86_SIM_X86_JMP(0xee9, 0xf7e, x86_l_f7e);
x86_l_eee:
	/* 0xeee: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_ef4:
	/* 0xef4: jmp    10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JMP(0xef4, 0x10b9, x86_l_10b9);
x86_l_ef9:
	/* 0xef9: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_f00:
	/* 0xf00: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f05:
	/* 0xf05: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f0a:
	/* 0xf0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f0c:
	/* 0xf0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f0e:
	/* 0xf0e: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f13:
	/* 0xf13: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f16:
	/* 0xf16: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f1b:
	/* 0xf1b: jne    10f3 <generic_usdt_actions+0x10f3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf1b, 0x10f3, x86_l_10f3);
x86_l_f21:
	/* 0xf21: jmp    10e9 <generic_usdt_actions+0x10e9> */
	X86_SIM_X86_JMP(0xf21, 0x10e9, x86_l_10e9);
x86_l_f26:
	/* 0xf26: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f29:
	/* 0xf29: jg     fde <generic_usdt_actions+0xfde> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf29, 0xfde, x86_l_fde);
x86_l_f2f:
	/* 0xf2f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f32:
	/* 0xf32: jg     102b <generic_usdt_actions+0x102b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf32, 0x102b, x86_l_102b);
x86_l_f38:
	/* 0xf38: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f3a:
	/* 0xf3a: je     1088 <generic_usdt_actions+0x1088> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf3a, 0x1088, x86_l_1088);
x86_l_f40:
	/* 0xf40: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f48:
	/* 0xf48: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f4b:
	/* 0xf4b: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f4f:
	/* 0xf4f: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf4f, 0x108f, x86_l_108f);
x86_l_f55:
	/* 0xf55: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0xf55, 0x1092, x86_l_1092);
x86_l_f5a:
	/* 0xf5a: mov    DWORD PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_f62:
	/* 0xf62: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_f69:
	/* 0xf69: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f6b:
	/* 0xf6b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f70:
	/* 0xf70: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_f75:
	/* 0xf75: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f7a:
	/* 0xf7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7c:
	/* 0xf7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7e:
	/* 0xf7e: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_f80:
	/* 0xf80: je     d08 <generic_usdt_actions+0xd08> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf80, 0xd08, x86_l_d08);
x86_l_f86:
	/* 0xf86: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_f8d:
	/* 0xf8d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f92:
	/* 0xf92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f97:
	/* 0xf97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f99:
	/* 0xf99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9c:
	/* 0xf9c: je     d08 <generic_usdt_actions+0xd08> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9c, 0xd08, x86_l_d08);
x86_l_fa2:
	/* 0xfa2: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_fa6:
	/* 0xfa6: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_fa9:
	/* 0xfa9: jmp    d08 <generic_usdt_actions+0xd08> */
	X86_SIM_X86_JMP(0xfa9, 0xd08, x86_l_d08);
x86_l_fae:
	/* 0xfae: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_fb1:
	/* 0xfb1: jg     100b <generic_usdt_actions+0x100b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfb1, 0x100b, x86_l_100b);
x86_l_fb3:
	/* 0xfb3: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_fbb:
	/* 0xfbb: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_fbe:
	/* 0xfbe: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fc2:
	/* 0xfc2: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc2, 0x108f, x86_l_108f);
x86_l_fc8:
	/* 0xfc8: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fd0:
	/* 0xfd0: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_fd3:
	/* 0xfd3: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd3, 0x108f, x86_l_108f);
x86_l_fd9:
	/* 0xfd9: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0xfd9, 0x1092, x86_l_1092);
x86_l_fde:
	/* 0xfde: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_fe1:
	/* 0xfe1: jg     1048 <generic_usdt_actions+0x1048> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfe1, 0x1048, x86_l_1048);
x86_l_fe3:
	/* 0xfe3: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_feb:
	/* 0xfeb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fee:
	/* 0xfee: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ff2:
	/* 0xff2: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff2, 0x108f, x86_l_108f);
x86_l_ff8:
	/* 0xff8: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ffd:
	/* 0xffd: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1000:
	/* 0x1000: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1000, 0x108f, x86_l_108f);
x86_l_1006:
	/* 0x1006: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0x1006, 0x1092, x86_l_1092);
x86_l_100b:
	/* 0x100b: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1013:
	/* 0x1013: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1016:
	/* 0x1016: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_101a:
	/* 0x101a: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x101a, 0x108f, x86_l_108f);
x86_l_101c:
	/* 0x101c: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1024:
	/* 0x1024: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1027:
	/* 0x1027: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1027, 0x108f, x86_l_108f);
x86_l_1029:
	/* 0x1029: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0x1029, 0x1092, x86_l_1092);
x86_l_102b:
	/* 0x102b: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1033:
	/* 0x1033: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1036:
	/* 0x1036: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103a:
	/* 0x103a: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103a, 0x108f, x86_l_108f);
x86_l_103c:
	/* 0x103c: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1041:
	/* 0x1041: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1044:
	/* 0x1044: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1044, 0x108f, x86_l_108f);
x86_l_1046:
	/* 0x1046: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0x1046, 0x1092, x86_l_1092);
x86_l_1048:
	/* 0x1048: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1050:
	/* 0x1050: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1053:
	/* 0x1053: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1057:
	/* 0x1057: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1057, 0x108f, x86_l_108f);
x86_l_1059:
	/* 0x1059: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1061:
	/* 0x1061: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1064:
	/* 0x1064: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1064, 0x108f, x86_l_108f);
x86_l_1066:
	/* 0x1066: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0x1066, 0x1092, x86_l_1092);
x86_l_1068:
	/* 0x1068: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1070:
	/* 0x1070: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1073:
	/* 0x1073: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1077:
	/* 0x1077: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1077, 0x108f, x86_l_108f);
x86_l_1079:
	/* 0x1079: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1081:
	/* 0x1081: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1084:
	/* 0x1084: je     108f <generic_usdt_actions+0x108f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1084, 0x108f, x86_l_108f);
x86_l_1086:
	/* 0x1086: jmp    1092 <generic_usdt_actions+0x1092> */
	X86_SIM_X86_JMP(0x1086, 0x1092, x86_l_1092);
x86_l_1088:
	/* 0x1088: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_108b:
	/* 0x108b: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_108f:
	/* 0x108f: mov    rdi,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1092:
	/* 0x1092: add    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1095:
	/* 0x1095: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1099:
	/* 0x1099: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_109e:
	/* 0x109e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10a3:
	/* 0x10a3: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_10a8:
	/* 0x10a8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_10ad:
	/* 0x10ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10af:
	/* 0x10af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b1:
	/* 0x10b1: je     10b9 <generic_usdt_actions+0x10b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b1, 0x10b9, x86_l_10b9);
x86_l_10b3:
	/* 0x10b3: or     BYTE PTR [r12+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R12, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_10b9:
	/* 0x10b9: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10c1:
	/* 0x10c1: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_10c8:
	/* 0x10c8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10cd:
	/* 0x10cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d2:
	/* 0x10d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d4:
	/* 0x10d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d7:
	/* 0x10d7: je     10de <generic_usdt_actions+0x10de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d7, 0x10de, x86_l_10de);
x86_l_10d9:
	/* 0x10d9: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10de:
	/* 0x10de: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_10e1:
	/* 0x10e1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10e4:
	/* 0x10e4: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10e9:
	/* 0x10e9: mov    QWORD PTR [rdx+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10ed:
	/* 0x10ed: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10f0:
	/* 0x10f0: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_10f3:
	/* 0x10f3: lea    eax,[rbp*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 4ULL);
x86_l_10fa:
	/* 0x10fa: cmp    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_10fe:
	/* 0x10fe: jae    115c <generic_usdt_actions+0x115c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x10fe, 0x115c, x86_l_115c);
x86_l_1100:
	/* 0x1100: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1103:
	/* 0x1103: movsxd rbp,DWORD PTR [r13+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_R15, 2, X86_WIDTH_32), 4ULL);
x86_l_1108:
	/* 0x1108: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1110:
	/* 0x1110: mov    rdi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1117:
	/* 0x1117: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_111c:
	/* 0x111c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1121:
	/* 0x1121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1123:
	/* 0x1123: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1126:
	/* 0x1126: je     115c <generic_usdt_actions+0x115c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1126, 0x115c, x86_l_115c);
x86_l_1128:
	/* 0x1128: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_112b:
	/* 0x112b: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_112e:
	/* 0x112e: jle    1197 <generic_usdt_actions+0x1197> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x112e, 0x1197, x86_l_1197);
x86_l_1130:
	/* 0x1130: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_1133:
	/* 0x1133: jg     11bf <generic_usdt_actions+0x11bf> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1133, 0x11bf, x86_l_11bf);
x86_l_1139:
	/* 0x1139: lea    eax,[rbp-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_113c:
	/* 0x113c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_113f:
	/* 0x113f: jb     13b8 <generic_usdt_actions+0x13b8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x113f, 0x13b8, x86_l_13b8);
x86_l_1145:
	/* 0x1145: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1148:
	/* 0x1148: je     14d3 <generic_usdt_actions+0x14d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1148, 0x14d3, x86_l_14d3);
x86_l_114e:
	/* 0x114e: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_1151:
	/* 0x1151: je     17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1151, 0x17b8, x86_l_17b8);
x86_l_1157:
	/* 0x1157: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x1157, 0x17e2, x86_l_17e2);
x86_l_115c:
	/* 0x115c: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1160:
	/* 0x1160: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1162:
	/* 0x1162: je     117f <generic_usdt_actions+0x117f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1162, 0x117f, x86_l_117f);
x86_l_1164:
	/* 0x1164: mov    rsi,QWORD PTR [rip+0x6e30] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_116b:
	/* 0x116b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1170:
	/* 0x1170: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1175:
	/* 0x1175: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1178:
	/* 0x1178: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_117d:
	/* 0x117d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117f:
	/* 0x117f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1181:
	/* 0x1181: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_1188:
	/* 0x1188: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1189:
	/* 0x1189: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_118b:
	/* 0x118b: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_118d:
	/* 0x118d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_118f:
	/* 0x118f: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1191:
	/* 0x1191: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1192:
	/* 0x1192: jmp    17ef <generic_usdt_actions+0x17ef> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1197:
	/* 0x1197: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_119a:
	/* 0x119a: jg     12b0 <generic_usdt_actions+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x119a, 0x12b0, x86_l_12b0);
x86_l_11a0:
	/* 0x11a0: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_11a2:
	/* 0x11a2: je     1552 <generic_usdt_actions+0x1552> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a2, 0x1552, x86_l_1552);
x86_l_11a8:
	/* 0x11a8: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_11ab:
	/* 0x11ab: je     13c6 <generic_usdt_actions+0x13c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ab, 0x13c6, x86_l_13c6);
x86_l_11b1:
	/* 0x11b1: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_11b4:
	/* 0x11b4: je     17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b4, 0x17b8, x86_l_17b8);
x86_l_11ba:
	/* 0x11ba: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x11ba, 0x17e2, x86_l_17e2);
x86_l_11bf:
	/* 0x11bf: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_11c7:
	/* 0x11c7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11cc:
	/* 0x11cc: cmp    ebp,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 12ULL);
x86_l_11cf:
	/* 0x11cf: je     17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11cf, 0x17b8, x86_l_17b8);
x86_l_11d5:
	/* 0x11d5: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_11d8:
	/* 0x11d8: je     14da <generic_usdt_actions+0x14da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d8, 0x14da, x86_l_14da);
x86_l_11de:
	/* 0x11de: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_11e1:
	/* 0x11e1: jne    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11e1, 0x17e2, x86_l_17e2);
x86_l_11e7:
	/* 0x11e7: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11ec:
	/* 0x11ec: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11f1:
	/* 0x11f1: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_11f4:
	/* 0x11f4: je     17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f4, 0x17b8, x86_l_17b8);
x86_l_11fa:
	/* 0x11fa: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_11ff:
	/* 0x11ff: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_1204:
	/* 0x1204: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1207:
	/* 0x1207: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_120e:
	/* 0x120e: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_1215:
	/* 0x1215: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_121a:
	/* 0x121a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121c:
	/* 0x121c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1221:
	/* 0x1221: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1226:
	/* 0x1226: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1229:
	/* 0x1229: je     17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1229, 0x17b8, x86_l_17b8);
x86_l_122f:
	/* 0x122f: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1233:
	/* 0x1233: lea    rdx,[r12+r12*2] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 0ULL);
x86_l_1237:
	/* 0x1237: cmp    BYTE PTR [rax+rdx*8+0x211],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 3), 2272037699587ULL);
x86_l_123f:
	/* 0x123f: jne    17b3 <generic_usdt_actions+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x123f, 0x17b3, x86_l_17b3);
x86_l_1245:
	/* 0x1245: lea    rcx,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_1249:
	/* 0x1249: add    rcx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_1250:
	/* 0x1250: rorx   eax,DWORD PTR [rax+rdx*8+0x208],0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 3, X86_WIDTH_32), 2233382993923ULL);
x86_l_125b:
	/* 0x125b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125d:
	/* 0x125d: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1260:
	/* 0x1260: jle    164b <generic_usdt_actions+0x164b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1260, 0x164b, x86_l_164b);
x86_l_1266:
	/* 0x1266: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1269:
	/* 0x1269: jle    16d0 <generic_usdt_actions+0x16d0> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1269, 0x16d0, x86_l_16d0);
x86_l_126f:
	/* 0x126f: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1272:
	/* 0x1272: jle    176f <generic_usdt_actions+0x176f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1272, 0x176f, x86_l_176f);
x86_l_1278:
	/* 0x1278: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1280:
	/* 0x1280: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1283:
	/* 0x1283: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1283, 0x178e, x86_l_178e);
x86_l_1289:
	/* 0x1289: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1291:
	/* 0x1291: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1294:
	/* 0x1294: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1294, 0x178e, x86_l_178e);
x86_l_129a:
	/* 0x129a: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12a2:
	/* 0x12a2: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_12a5:
	/* 0x12a5: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a5, 0x178e, x86_l_178e);
x86_l_12ab:
	/* 0x12ab: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x12ab, 0x1791, x86_l_1791);
x86_l_12b0:
	/* 0x12b0: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_12b3:
	/* 0x12b3: je     13c6 <generic_usdt_actions+0x13c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12b3, 0x13c6, x86_l_13c6);
x86_l_12b9:
	/* 0x12b9: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_12bc:
	/* 0x12bc: je     15b3 <generic_usdt_actions+0x15b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12bc, 0x15b3, x86_l_15b3);
x86_l_12c2:
	/* 0x12c2: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_12c5:
	/* 0x12c5: jne    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12c5, 0x17e2, x86_l_17e2);
x86_l_12cb:
	/* 0x12cb: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_12d0:
	/* 0x12d0: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_12d5:
	/* 0x12d5: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_12de:
	/* 0x12de: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12e7:
	/* 0x12e7: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_12ea:
	/* 0x12ea: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ed:
	/* 0x12ed: ja     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x12ed, 0x17e2, x86_l_17e2);
x86_l_12f3:
	/* 0x12f3: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_12fc:
	/* 0x12fc: jne    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12fc, 0x17e2, x86_l_17e2);
x86_l_1302:
	/* 0x1302: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_130a:
	/* 0x130a: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_130f:
	/* 0x130f: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1317:
	/* 0x1317: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_131b:
	/* 0x131b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1320:
	/* 0x1320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1322:
	/* 0x1322: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1326:
	/* 0x1326: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132b:
	/* 0x132b: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1332:
	/* 0x1332: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1337:
	/* 0x1337: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_133c:
	/* 0x133c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_133e:
	/* 0x133e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1341:
	/* 0x1341: je     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1341, 0x17e2, x86_l_17e2);
x86_l_1347:
	/* 0x1347: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_134b:
	/* 0x134b: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_134f:
	/* 0x134f: ja     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x134f, 0x17e2, x86_l_17e2);
x86_l_1355:
	/* 0x1355: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_135e:
	/* 0x135e: jne    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x135e, 0x17e2, x86_l_17e2);
x86_l_1364:
	/* 0x1364: mov    rcx,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_136c:
	/* 0x136c: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1374:
	/* 0x1374: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_137a:
	/* 0x137a: mov    ecx,DWORD PTR [r14+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_1382:
	/* 0x1382: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1386:
	/* 0x1386: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1389:
	/* 0x1389: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_138e:
	/* 0x138e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1390:
	/* 0x1390: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1394:
	/* 0x1394: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1399:
	/* 0x1399: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_13a0:
	/* 0x13a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a2:
	/* 0x13a2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a7:
	/* 0x13a7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13ac:
	/* 0x13ac: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13af:
	/* 0x13af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b1:
	/* 0x13b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b3:
	/* 0x13b3: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x13b3, 0x17e2, x86_l_17e2);
x86_l_13b8:
	/* 0x13b8: mov    eax,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_13bd:
	/* 0x13bd: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13c1:
	/* 0x13c1: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x13c1, 0x17e2, x86_l_17e2);
x86_l_13c6:
	/* 0x13c6: mov    r12d,DWORD PTR [r13+r15*4+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 8ULL);
x86_l_13cb:
	/* 0x13cb: mov    r15d,DWORD PTR [r13+r15*4+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 12ULL);
x86_l_13d0:
	/* 0x13d0: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13d9:
	/* 0x13d9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13e2:
	/* 0x13e2: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_13ea:
	/* 0x13ea: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_13f1:
	/* 0x13f1: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13f6:
	/* 0x13f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13fb:
	/* 0x13fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fd:
	/* 0x13fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1400:
	/* 0x1400: je     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1400, 0x17e2, x86_l_17e2);
x86_l_1406:
	/* 0x1406: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_140a:
	/* 0x140a: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_140e:
	/* 0x140e: ja     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x140e, 0x17e2, x86_l_17e2);
x86_l_1414:
	/* 0x1414: cmp    DWORD PTR [r14+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_141d:
	/* 0x141d: jne    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x141d, 0x17e2, x86_l_17e2);
x86_l_1423:
	/* 0x1423: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1426:
	/* 0x1426: mov    rax,QWORD PTR [r14+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_142e:
	/* 0x142e: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1436:
	/* 0x1436: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_143b:
	/* 0x143b: mov    eax,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_1443:
	/* 0x1443: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1447:
	/* 0x1447: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_144c:
	/* 0x144c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144e:
	/* 0x144e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1452:
	/* 0x1452: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1457:
	/* 0x1457: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_145a:
	/* 0x145a: jne    1627 <generic_usdt_actions+0x1627> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x145a, 0x1627, x86_l_1627);
x86_l_1460:
	/* 0x1460: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1464:
	/* 0x1464: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1468:
	/* 0x1468: ja     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1468, 0x17e2, x86_l_17e2);
x86_l_146e:
	/* 0x146e: cmp    DWORD PTR [r14+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_1477:
	/* 0x1477: jne    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1477, 0x17e2, x86_l_17e2);
x86_l_147d:
	/* 0x147d: mov    rax,QWORD PTR [r14+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_1485:
	/* 0x1485: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_148a:
	/* 0x148a: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_148e:
	/* 0x148e: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1495:
	/* 0x1495: mov    esi,DWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_149d:
	/* 0x149d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14a3:
	/* 0x14a3: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14a7:
	/* 0x14a7: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_14aa:
	/* 0x14aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14af:
	/* 0x14af: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_14b2:
	/* 0x14b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b4:
	/* 0x14b4: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_14bb:
	/* 0x14bb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14bd:
	/* 0x14bd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14c2:
	/* 0x14c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14c7:
	/* 0x14c7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14ca:
	/* 0x14ca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14cc:
	/* 0x14cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ce:
	/* 0x14ce: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x14ce, 0x17e2, x86_l_17e2);
x86_l_14d3:
	/* 0x14d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d5:
	/* 0x14d5: jmp    17e6 <generic_usdt_actions+0x17e6> */
	X86_SIM_X86_JMP(0x14d5, 0x17e6, x86_l_17e6);
x86_l_14da:
	/* 0x14da: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_14df:
	/* 0x14df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e1:
	/* 0x14e1: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14e6:
	/* 0x14e6: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_14ed:
	/* 0x14ed: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14f2:
	/* 0x14f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f7:
	/* 0x14f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f9:
	/* 0x14f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14fc:
	/* 0x14fc: je     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14fc, 0x17e2, x86_l_17e2);
x86_l_1502:
	/* 0x1502: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1506:
	/* 0x1506: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_150b:
	/* 0x150b: mov    DWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_1513:
	/* 0x1513: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_151a:
	/* 0x151a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_151f:
	/* 0x151f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1524:
	/* 0x1524: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1526:
	/* 0x1526: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_152e:
	/* 0x152e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1531:
	/* 0x1531: je     15c5 <generic_usdt_actions+0x15c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1531, 0x15c5, x86_l_15c5);
x86_l_1537:
	/* 0x1537: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_153a:
	/* 0x153a: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_1541:
	/* 0x1541: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1546:
	/* 0x1546: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_154b:
	/* 0x154b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154d:
	/* 0x154d: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x154d, 0x17e2, x86_l_17e2);
x86_l_1552:
	/* 0x1552: cmp    DWORD PTR [r13+r15*4+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 68719476736ULL);
x86_l_1558:
	/* 0x1558: je     157b <generic_usdt_actions+0x157b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1558, 0x157b, x86_l_157b);
x86_l_155a:
	/* 0x155a: or     BYTE PTR [r14+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_155f:
	/* 0x155f: mov    rsi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1566:
	/* 0x1566: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1568:
	/* 0x1568: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_156d:
	/* 0x156d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1570:
	/* 0x1570: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1572:
	/* 0x1572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1574:
	/* 0x1574: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_157b:
	/* 0x157b: cmp    DWORD PTR [r13+r15*4+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 85899345920ULL);
x86_l_1581:
	/* 0x1581: je     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1581, 0x17e2, x86_l_17e2);
x86_l_1587:
	/* 0x1587: or     BYTE PTR [r14+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_158c:
	/* 0x158c: mov    rsi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_1593:
	/* 0x1593: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1598:
	/* 0x1598: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_159d:
	/* 0x159d: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_15a2:
	/* 0x15a2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15a5:
	/* 0x15a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a7:
	/* 0x15a7: mov    QWORD PTR [r14+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15ae:
	/* 0x15ae: jmp    17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JMP(0x15ae, 0x17e2, x86_l_17e2);
x86_l_15b3:
	/* 0x15b3: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_15bb:
	/* 0x15bb: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15c0:
	/* 0x15c0: jmp    17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JMP(0x15c0, 0x17b8, x86_l_17b8);
x86_l_15c5:
	/* 0x15c5: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_15cc:
	/* 0x15cc: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15d1:
	/* 0x15d1: lea    rdx,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15d6:
	/* 0x15d6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15db:
	/* 0x15db: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15e0:
	/* 0x15e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e2:
	/* 0x15e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e5:
	/* 0x15e5: je     153a <generic_usdt_actions+0x153a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15e5, 0x153a, x86_l_153a);
x86_l_15eb:
	/* 0x15eb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15ee:
	/* 0x15ee: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_15f0:
	/* 0x15f0: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15f5:
	/* 0x15f5: mov    WORD PTR [rsp+0x12],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411331ULL);
x86_l_15fc:
	/* 0x15fc: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_1606:
	/* 0x1606: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_160b:
	/* 0x160b: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1612:
	/* 0x1612: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1617:
	/* 0x1617: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_161c:
	/* 0x161c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161e:
	/* 0x161e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1621:
	/* 0x1621: je     167b <generic_usdt_actions+0x167b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1621, 0x167b, x86_l_167b);
x86_l_1623:
	/* 0x1623: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1625:
	/* 0x1625: jmp    169f <generic_usdt_actions+0x169f> */
	X86_SIM_X86_JMP(0x1625, 0x169f, x86_l_169f);
x86_l_1627:
	/* 0x1627: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_162e:
	/* 0x162e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1633:
	/* 0x1633: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1638:
	/* 0x1638: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163a:
	/* 0x163a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163c:
	/* 0x163c: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1640:
	/* 0x1640: jne    1160 <generic_usdt_actions+0x1160> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1640, 0x1160, x86_l_1160);
x86_l_1646:
	/* 0x1646: jmp    17e6 <generic_usdt_actions+0x17e6> */
	X86_SIM_X86_JMP(0x1646, 0x17e6, x86_l_17e6);
x86_l_164b:
	/* 0x164b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_164e:
	/* 0x164e: jg     16fc <generic_usdt_actions+0x16fc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x164e, 0x16fc, x86_l_16fc);
x86_l_1654:
	/* 0x1654: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1657:
	/* 0x1657: jg     173a <generic_usdt_actions+0x173a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1657, 0x173a, x86_l_173a);
x86_l_165d:
	/* 0x165d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_165f:
	/* 0x165f: je     178b <generic_usdt_actions+0x178b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x165f, 0x178b, x86_l_178b);
x86_l_1665:
	/* 0x1665: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1668:
	/* 0x1668: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1670:
	/* 0x1670: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1670, 0x178e, x86_l_178e);
x86_l_1676:
	/* 0x1676: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x1676, 0x1791, x86_l_1791);
x86_l_167b:
	/* 0x167b: mov    DWORD PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_1683:
	/* 0x1683: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_168a:
	/* 0x168a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168c:
	/* 0x168c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1691:
	/* 0x1691: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1696:
	/* 0x1696: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_169b:
	/* 0x169b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_169d:
	/* 0x169d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169f:
	/* 0x169f: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_16a2:
	/* 0x16a2: je     153a <generic_usdt_actions+0x153a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16a2, 0x153a, x86_l_153a);
x86_l_16a8:
	/* 0x16a8: mov    rdi,QWORD PTR [rip+0x6e2c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_16af:
	/* 0x16af: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16b4:
	/* 0x16b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16b9:
	/* 0x16b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bb:
	/* 0x16bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16be:
	/* 0x16be: je     153a <generic_usdt_actions+0x153a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16be, 0x153a, x86_l_153a);
x86_l_16c4:
	/* 0x16c4: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_16c8:
	/* 0x16c8: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16cb:
	/* 0x16cb: jmp    153a <generic_usdt_actions+0x153a> */
	X86_SIM_X86_JMP(0x16cb, 0x153a, x86_l_153a);
x86_l_16d0:
	/* 0x16d0: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_16d3:
	/* 0x16d3: jg     171e <generic_usdt_actions+0x171e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16d3, 0x171e, x86_l_171e);
x86_l_16d5:
	/* 0x16d5: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_16dd:
	/* 0x16dd: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_16e0:
	/* 0x16e0: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e0, 0x178e, x86_l_178e);
x86_l_16e6:
	/* 0x16e6: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16ee:
	/* 0x16ee: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_16f1:
	/* 0x16f1: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f1, 0x178e, x86_l_178e);
x86_l_16f7:
	/* 0x16f7: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x16f7, 0x1791, x86_l_1791);
x86_l_16fc:
	/* 0x16fc: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_16ff:
	/* 0x16ff: jg     1753 <generic_usdt_actions+0x1753> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16ff, 0x1753, x86_l_1753);
x86_l_1701:
	/* 0x1701: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1709:
	/* 0x1709: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_170c:
	/* 0x170c: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170c, 0x178e, x86_l_178e);
x86_l_1712:
	/* 0x1712: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1717:
	/* 0x1717: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_171a:
	/* 0x171a: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x171a, 0x178e, x86_l_178e);
x86_l_171c:
	/* 0x171c: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x171c, 0x1791, x86_l_1791);
x86_l_171e:
	/* 0x171e: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1726:
	/* 0x1726: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1729:
	/* 0x1729: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1729, 0x178e, x86_l_178e);
x86_l_172b:
	/* 0x172b: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1733:
	/* 0x1733: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1736:
	/* 0x1736: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1736, 0x178e, x86_l_178e);
x86_l_1738:
	/* 0x1738: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x1738, 0x1791, x86_l_1791);
x86_l_173a:
	/* 0x173a: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1742:
	/* 0x1742: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1745:
	/* 0x1745: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1745, 0x178e, x86_l_178e);
x86_l_1747:
	/* 0x1747: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_174c:
	/* 0x174c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_174f:
	/* 0x174f: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x174f, 0x178e, x86_l_178e);
x86_l_1751:
	/* 0x1751: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x1751, 0x1791, x86_l_1791);
x86_l_1753:
	/* 0x1753: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_175b:
	/* 0x175b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_175e:
	/* 0x175e: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175e, 0x178e, x86_l_178e);
x86_l_1760:
	/* 0x1760: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1768:
	/* 0x1768: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_176b:
	/* 0x176b: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x176b, 0x178e, x86_l_178e);
x86_l_176d:
	/* 0x176d: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x176d, 0x1791, x86_l_1791);
x86_l_176f:
	/* 0x176f: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1777:
	/* 0x1777: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_177a:
	/* 0x177a: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x177a, 0x178e, x86_l_178e);
x86_l_177c:
	/* 0x177c: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1784:
	/* 0x1784: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1787:
	/* 0x1787: je     178e <generic_usdt_actions+0x178e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1787, 0x178e, x86_l_178e);
x86_l_1789:
	/* 0x1789: jmp    1791 <generic_usdt_actions+0x1791> */
	X86_SIM_X86_JMP(0x1789, 0x1791, x86_l_1791);
x86_l_178b:
	/* 0x178b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_178e:
	/* 0x178e: mov    rdi,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1791:
	/* 0x1791: add    rdi,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1794:
	/* 0x1794: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1799:
	/* 0x1799: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_179e:
	/* 0x179e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17a3:
	/* 0x17a3: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_17a8:
	/* 0x17a8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_17ad:
	/* 0x17ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17af:
	/* 0x17af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17b1:
	/* 0x17b1: je     17b8 <generic_usdt_actions+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b1, 0x17b8, x86_l_17b8);
x86_l_17b3:
	/* 0x17b3: or     BYTE PTR [r14+0x1],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967328ULL);
x86_l_17b8:
	/* 0x17b8: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17c0:
	/* 0x17c0: mov    rdi,QWORD PTR [rip+0x6e28] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_17c7:
	/* 0x17c7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cc:
	/* 0x17cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17d1:
	/* 0x17d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d3:
	/* 0x17d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17d6:
	/* 0x17d6: je     17e2 <generic_usdt_actions+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17d6, 0x17e2, x86_l_17e2);
x86_l_17d8:
	/* 0x17d8: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17dd:
	/* 0x17dd: inc QWORD PTR [rax+rcx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RCX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17e2:
	/* 0x17e2: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17e6:
	/* 0x17e6: mov    QWORD PTR [r14+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17ea:
	/* 0x17ea: jmp    1160 <generic_usdt_actions+0x1160> */
	X86_SIM_X86_JMP(0x17ea, 0x1160, x86_l_1160);
x86_l_17ef:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
