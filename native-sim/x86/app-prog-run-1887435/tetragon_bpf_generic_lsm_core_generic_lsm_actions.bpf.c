extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char heap_ro_zero;
extern char lsm_calls;
extern char override_tasks;
extern char policy_conf;
extern char policy_stats;
extern char process_call_heap;
extern char ratelimit_heap;
extern char ratelimit_map;
extern char socktrack_map;
extern char stack_trace_map;
extern char tg_errmetrics_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_lsm_core_generic_lsm_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x1eb67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30:
	/* 0x30: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     d9 <generic_lsm_actions+0xd9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0xd9, x86_l_d9);
x86_l_3e:
	/* 0x3e: mov    ebx,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_44:
	/* 0x44: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_47:
	/* 0x47: jl     d9 <generic_lsm_actions+0xd9> */
	X86_SIM_X86_JCC(X86_CC_L, 0x47, 0xd9, x86_l_d9);
x86_l_4d:
	/* 0x4d: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_53:
	/* 0x53: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_58:
	/* 0x58: mov    rdi,QWORD PTR [rip+0x1eb67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_5f:
	/* 0x5f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_62:
	/* 0x62: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_64:
	/* 0x64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67:
	/* 0x67: je     d9 <generic_lsm_actions+0xd9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67, 0xd9, x86_l_d9);
x86_l_69:
	/* 0x69: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_6e:
	/* 0x6e: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_73:
	/* 0x73: add    ebx,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_77:
	/* 0x77: and    ebx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7d:
	/* 0x7d: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_88:
	/* 0x88: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8d:
	/* 0x8d: mov    rdi,QWORD PTR [rip+0x1eb67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_94:
	/* 0x94: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9c:
	/* 0x9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e:
	/* 0x9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0x68],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a6:
	/* 0xa6: je     170 <generic_lsm_actions+0x170> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa6, 0x170, x86_l_170);
x86_l_ac:
	/* 0xac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae:
	/* 0xae: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1:
	/* 0xb1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_b4:
	/* 0xb4: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_b7:
	/* 0xb7: xor    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c3:
	/* 0xc3: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c8:
	/* 0xc8: xor    rcx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_cc:
	/* 0xcc: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d4:
	/* 0xd4: jmp    191 <generic_lsm_actions+0x191> */
	X86_SIM_X86_JMP(0xd4, 0x191, x86_l_191);
x86_l_d9:
	/* 0xd9: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db:
	/* 0xdb: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e3:
	/* 0xe3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8:
	/* 0xe8: mov    rdi,QWORD PTR [rip+0x1eb67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ef:
	/* 0xef: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f4:
	/* 0xf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6:
	/* 0xf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: je     15c <generic_lsm_actions+0x15c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9, 0x15c, x86_l_15c);
x86_l_fb:
	/* 0xfb: mov    BYTE PTR [rax+0x5f08],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24328ULL);
x86_l_101:
	/* 0x101: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_104:
	/* 0x104: jne    15c <generic_lsm_actions+0x15c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x104, 0x15c, x86_l_15c);
x86_l_106:
	/* 0x106: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10b:
	/* 0x10b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111:
	/* 0x111: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_116:
	/* 0x116: mov    rdi,QWORD PTR [rip+0x1eb67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_11d:
	/* 0x11d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_120:
	/* 0x120: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122:
	/* 0x122: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_125:
	/* 0x125: je     155 <generic_lsm_actions+0x155> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125, 0x155, x86_l_155);
x86_l_127:
	/* 0x127: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_12f:
	/* 0x12f: mov    rdi,QWORD PTR [rip+0x1eb67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_136:
	/* 0x136: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_139:
	/* 0x139: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b:
	/* 0x13b: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d:
	/* 0x13d: lea    ecx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_140:
	/* 0x140: cmp    ecx,0xfffff000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294963200ULL);
x86_l_146:
	/* 0x146: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_14b:
	/* 0x14b: cmovae ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_14e:
	/* 0x14e: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_153:
	/* 0x153: jmp    15c <generic_lsm_actions+0x15c> */
	X86_SIM_X86_JMP(0x153, 0x15c, x86_l_15c);
x86_l_155:
	/* 0x155: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157:
	/* 0x157: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15c:
	/* 0x15c: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_161:
	/* 0x161: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_168:
	/* 0x168: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_16a:
	/* 0x16a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: jmp    b85 <generic_lsm_actions+0xb85> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_170:
	/* 0x170: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17d:
	/* 0x17d: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_17f:
	/* 0x17f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_184:
	/* 0x184: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_189:
	/* 0x189: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_191:
	/* 0x191: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_194:
	/* 0x194: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_196:
	/* 0x196: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_19a:
	/* 0x19a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d:
	/* 0x19d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f:
	/* 0x19f: mov    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a4:
	/* 0x1a4: jmp    1c4 <generic_lsm_actions+0x1c4> */
	X86_SIM_X86_JMP(0x1a4, 0x1c4, x86_l_1c4);
x86_l_1a6:
	/* 0x1a6: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ab:
	/* 0x1ab: mov    QWORD PTR [rbp+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1af:
	/* 0x1af: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1b1:
	/* 0x1b1: mov    r13d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_32);
x86_l_1b4:
	/* 0x1b4: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1b7:
	/* 0x1b7: mov    ebx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_32);
x86_l_1ba:
	/* 0x1ba: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1be:
	/* 0x1be: je     b56 <generic_lsm_actions+0xb56> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1be, 0xb56, x86_l_b56);
x86_l_1c4:
	/* 0x1c4: lea    eax,[rbx*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_1cb:
	/* 0x1cb: cmp    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1ce:
	/* 0x1ce: jae    b56 <generic_lsm_actions+0xb56> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1ce, 0xb56, x86_l_b56);
x86_l_1d4:
	/* 0x1d4: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_1d6:
	/* 0x1d6: movsxd r14,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_1db:
	/* 0x1db: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1e6:
	/* 0x1e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1eb:
	/* 0x1eb: mov    rdi,QWORD PTR [rip+0x1eb6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f2:
	/* 0x1f2: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_1fa:
	/* 0x1fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc:
	/* 0x1fc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff:
	/* 0x1ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_202:
	/* 0x202: je     1b4 <generic_lsm_actions+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x202, 0x1b4, x86_l_1b4);
x86_l_204:
	/* 0x204: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_207:
	/* 0x207: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_20b:
	/* 0x20b: jg     235 <generic_lsm_actions+0x235> */
	X86_SIM_X86_JCC(X86_CC_G, 0x20b, 0x235, x86_l_235);
x86_l_20d:
	/* 0x20d: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_211:
	/* 0x211: jg     26c <generic_lsm_actions+0x26c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x211, 0x26c, x86_l_26c);
x86_l_213:
	/* 0x213: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_217:
	/* 0x217: jg     3a2 <generic_lsm_actions+0x3a2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x217, 0x3a2, x86_l_3a2);
x86_l_21d:
	/* 0x21d: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_220:
	/* 0x220: je     6eb <generic_lsm_actions+0x6eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x220, 0x6eb, x86_l_6eb);
x86_l_226:
	/* 0x226: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_22a:
	/* 0x22a: je     3bb <generic_lsm_actions+0x3bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22a, 0x3bb, x86_l_3bb);
x86_l_230:
	/* 0x230: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x230, 0x1ab, x86_l_1ab);
x86_l_235:
	/* 0x235: cmp    r14d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 11ULL);
x86_l_239:
	/* 0x239: jg     374 <generic_lsm_actions+0x374> */
	X86_SIM_X86_JCC(X86_CC_G, 0x239, 0x374, x86_l_374);
x86_l_23f:
	/* 0x23f: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_243:
	/* 0x243: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_246:
	/* 0x246: jb     4db <generic_lsm_actions+0x4db> */
	X86_SIM_X86_JCC(X86_CC_B, 0x246, 0x4db, x86_l_4db);
x86_l_24c:
	/* 0x24c: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_250:
	/* 0x250: je     5ca <generic_lsm_actions+0x5ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x250, 0x5ca, x86_l_5ca);
x86_l_256:
	/* 0x256: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_25a:
	/* 0x25a: jne    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25a, 0x1ab, x86_l_1ab);
x86_l_260:
	/* 0x260: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_262:
	/* 0x262: mov    edi,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_267:
	/* 0x267: jmp    598 <generic_lsm_actions+0x598> */
	X86_SIM_X86_JMP(0x267, 0x598, x86_l_598);
x86_l_26c:
	/* 0x26c: lea    eax,[r14-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_270:
	/* 0x270: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_273:
	/* 0x273: jb     5bb <generic_lsm_actions+0x5bb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x273, 0x5bb, x86_l_5bb);
x86_l_279:
	/* 0x279: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_27d:
	/* 0x27d: je     5d7 <generic_lsm_actions+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27d, 0x5d7, x86_l_5d7);
x86_l_283:
	/* 0x283: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_287:
	/* 0x287: jne    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x287, 0x1ab, x86_l_1ab);
x86_l_28d:
	/* 0x28d: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_290:
	/* 0x290: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_295:
	/* 0x295: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_298:
	/* 0x298: mov    r15d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_29d:
	/* 0x29d: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a6:
	/* 0x2a6: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae:
	/* 0x2ae: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_2b1:
	/* 0x2b1: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b4:
	/* 0x2b4: ja     1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2b4, 0x1a6, x86_l_1a6);
x86_l_2ba:
	/* 0x2ba: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_2c2:
	/* 0x2c2: jne    1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c2, 0x1a6, x86_l_1a6);
x86_l_2c8:
	/* 0x2c8: mov    rax,QWORD PTR [rbp+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_2d0:
	/* 0x2d0: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2d5:
	/* 0x2d5: mov    eax,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_2dc:
	/* 0x2dc: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e0:
	/* 0x2e0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2e5:
	/* 0x2e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7:
	/* 0x2e7: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2eb:
	/* 0x2eb: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef:
	/* 0x2ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f4:
	/* 0x2f4: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2fb:
	/* 0x2fb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2fe:
	/* 0x2fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300:
	/* 0x300: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: je     1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x303, 0x1a6, x86_l_1a6);
x86_l_309:
	/* 0x309: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_30d:
	/* 0x30d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_311:
	/* 0x311: ja     1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x311, 0x1a6, x86_l_1a6);
x86_l_317:
	/* 0x317: cmp    DWORD PTR [rbp+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_320:
	/* 0x320: jne    1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x320, 0x1a6, x86_l_1a6);
x86_l_326:
	/* 0x326: mov    rcx,QWORD PTR [rbp+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_32e:
	/* 0x32e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_336:
	/* 0x336: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_33c:
	/* 0x33c: mov    ecx,DWORD PTR [rbp+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_343:
	/* 0x343: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_347:
	/* 0x347: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_34c:
	/* 0x34c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_34f:
	/* 0x34f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_351:
	/* 0x351: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_355:
	/* 0x355: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_359:
	/* 0x359: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35e:
	/* 0x35e: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_365:
	/* 0x365: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_368:
	/* 0x368: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_36b:
	/* 0x36b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36d:
	/* 0x36d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f:
	/* 0x36f: jmp    1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JMP(0x36f, 0x1a6, x86_l_1a6);
x86_l_374:
	/* 0x374: cmp    r14d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 12ULL);
x86_l_378:
	/* 0x378: je     79c <generic_lsm_actions+0x79c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x378, 0x79c, x86_l_79c);
x86_l_37e:
	/* 0x37e: cmp    r14d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 13ULL);
x86_l_382:
	/* 0x382: je     663 <generic_lsm_actions+0x663> */
	X86_SIM_X86_JCC(X86_CC_E, 0x382, 0x663, x86_l_663);
x86_l_388:
	/* 0x388: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_38c:
	/* 0x38c: jne    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38c, 0x1ab, x86_l_1ab);
x86_l_392:
	/* 0x392: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_395:
	/* 0x395: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_39d:
	/* 0x39d: jmp    88b <generic_lsm_actions+0x88b> */
	X86_SIM_X86_JMP(0x39d, 0x88b, x86_l_88b);
x86_l_3a2:
	/* 0x3a2: mov    edi,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_3a7:
	/* 0x3a7: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_3ab:
	/* 0x3ab: je     598 <generic_lsm_actions+0x598> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ab, 0x598, x86_l_598);
x86_l_3b1:
	/* 0x3b1: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_3b5:
	/* 0x3b5: jne    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b5, 0x1ab, x86_l_1ab);
x86_l_3bb:
	/* 0x3bb: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3be:
	/* 0x3be: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_3c1:
	/* 0x3c1: mov    r15d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_3c6:
	/* 0x3c6: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_3c9:
	/* 0x3c9: mov    eax,DWORD PTR [rcx+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_3cd:
	/* 0x3cd: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d2:
	/* 0x3d2: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3db:
	/* 0x3db: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e3:
	/* 0x3e3: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3eb:
	/* 0x3eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f0:
	/* 0x3f0: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_3f7:
	/* 0x3f7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fc:
	/* 0x3fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fe:
	/* 0x3fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_403:
	/* 0x403: je     846 <generic_lsm_actions+0x846> */
	X86_SIM_X86_JCC(X86_CC_E, 0x403, 0x846, x86_l_846);
x86_l_409:
	/* 0x409: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_40d:
	/* 0x40d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_411:
	/* 0x411: ja     846 <generic_lsm_actions+0x846> */
	X86_SIM_X86_JCC(X86_CC_A, 0x411, 0x846, x86_l_846);
x86_l_417:
	/* 0x417: cmp    DWORD PTR [rbp+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_420:
	/* 0x420: jne    846 <generic_lsm_actions+0x846> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x420, 0x846, x86_l_846);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_42b:
	/* 0x42b: mov    rax,QWORD PTR [rbp+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_433:
	/* 0x433: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_43b:
	/* 0x43b: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_440:
	/* 0x440: mov    eax,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_447:
	/* 0x447: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44b:
	/* 0x44b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_450:
	/* 0x450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_452:
	/* 0x452: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_456:
	/* 0x456: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45a:
	/* 0x45a: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_45e:
	/* 0x45e: jne    832 <generic_lsm_actions+0x832> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45e, 0x832, x86_l_832);
x86_l_464:
	/* 0x464: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_469:
	/* 0x469: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_46c:
	/* 0x46c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46f:
	/* 0x46f: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_474:
	/* 0x474: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_479:
	/* 0x479: ja     84b <generic_lsm_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x479, 0x84b, x86_l_84b);
x86_l_47f:
	/* 0x47f: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_487:
	/* 0x487: jne    84b <generic_lsm_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x487, 0x84b, x86_l_84b);
x86_l_48d:
	/* 0x48d: mov    rax,QWORD PTR [rbp+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_495:
	/* 0x495: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_49a:
	/* 0x49a: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_49e:
	/* 0x49e: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_4a5:
	/* 0x4a5: mov    esi,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_4ac:
	/* 0x4ac: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_4b1:
	/* 0x4b1: and    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_4b3:
	/* 0x4b3: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_4b6:
	/* 0x4b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4bb:
	/* 0x4bb: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c0:
	/* 0x4c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2:
	/* 0x4c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c7:
	/* 0x4c7: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_4ce:
	/* 0x4ce: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4d1:
	/* 0x4d1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4d6:
	/* 0x4d6: jmp    585 <generic_lsm_actions+0x585> */
	X86_SIM_X86_JMP(0x4d6, 0x585, x86_l_585);
x86_l_4db:
	/* 0x4db: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4dd:
	/* 0x4dd: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_4e2:
	/* 0x4e2: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4e5:
	/* 0x4e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e7:
	/* 0x4e7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ea:
	/* 0x4ea: ja     84b <generic_lsm_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4ea, 0x84b, x86_l_84b);
x86_l_4f0:
	/* 0x4f0: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_4f8:
	/* 0x4f8: jne    84b <generic_lsm_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4f8, 0x84b, x86_l_84b);
x86_l_4fe:
	/* 0x4fe: mov    rax,QWORD PTR [rbp+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_506:
	/* 0x506: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_50b:
	/* 0x50b: mov    rax,QWORD PTR [rbp+rax*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 184ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_518:
	/* 0x518: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51b:
	/* 0x51b: je     84b <generic_lsm_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51b, 0x84b, x86_l_84b);
x86_l_521:
	/* 0x521: cmp    r14d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 10ULL);
x86_l_525:
	/* 0x525: jne    8b6 <generic_lsm_actions+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x525, 0x8b6, x86_l_8b6);
x86_l_52b:
	/* 0x52b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_530:
	/* 0x530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_532:
	/* 0x532: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_537:
	/* 0x537: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_53b:
	/* 0x53b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53e:
	/* 0x53e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_543:
	/* 0x543: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_54a:
	/* 0x54a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_54d:
	/* 0x54d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54f:
	/* 0x54f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_551:
	/* 0x551: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_554:
	/* 0x554: je     84b <generic_lsm_actions+0x84b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x554, 0x84b, x86_l_84b);
x86_l_55a:
	/* 0x55a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55c:
	/* 0x55c: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f:
	/* 0x55f: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_564:
	/* 0x564: mov    DWORD PTR [rsp+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_568:
	/* 0x568: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_571:
	/* 0x571: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_576:
	/* 0x576: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_57d:
	/* 0x57d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_582:
	/* 0x582: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_585:
	/* 0x585: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_587:
	/* 0x587: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_589:
	/* 0x589: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58b:
	/* 0x58b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_58d:
	/* 0x58d: jne    1b4 <generic_lsm_actions+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x58d, 0x1b4, x86_l_1b4);
x86_l_593:
	/* 0x593: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x593, 0x1ab, x86_l_1ab);
x86_l_598:
	/* 0x598: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_59e:
	/* 0x59e: cmp    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5a3:
	/* 0x5a3: je     88b <generic_lsm_actions+0x88b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a3, 0x88b, x86_l_88b);
x86_l_5a9:
	/* 0x5a9: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_5ae:
	/* 0x5ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0:
	/* 0x5b0: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_5b6:
	/* 0x5b6: jmp    88b <generic_lsm_actions+0x88b> */
	X86_SIM_X86_JMP(0x5b6, 0x88b, x86_l_88b);
x86_l_5bb:
	/* 0x5bb: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5bd:
	/* 0x5bd: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_5c2:
	/* 0x5c2: mov    DWORD PTR [rbp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5c5:
	/* 0x5c5: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x5c5, 0x1ab, x86_l_1ab);
x86_l_5ca:
	/* 0x5ca: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_5d2:
	/* 0x5d2: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x5d2, 0x1ab, x86_l_1ab);
x86_l_5d7:
	/* 0x5d7: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5d9:
	/* 0x5d9: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_5df:
	/* 0x5df: cmp    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5e4:
	/* 0x5e4: je     88b <generic_lsm_actions+0x88b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e4, 0x88b, x86_l_88b);
x86_l_5ea:
	/* 0x5ea: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ef:
	/* 0x5ef: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_5f1:
	/* 0x5f1: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f6:
	/* 0x5f6: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_5fa:
	/* 0x5fa: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5fe:
	/* 0x5fe: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_603:
	/* 0x603: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_605:
	/* 0x605: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60a:
	/* 0x60a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60f:
	/* 0x60f: mov    rbp,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_616:
	/* 0x616: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_619:
	/* 0x619: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61e:
	/* 0x61e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_621:
	/* 0x621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_623:
	/* 0x623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_626:
	/* 0x626: je     811 <generic_lsm_actions+0x811> */
	X86_SIM_X86_JCC(X86_CC_E, 0x626, 0x811, x86_l_811);
x86_l_62c:
	/* 0x62c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_62f:
	/* 0x62f: mov    DWORD PTR [rsp],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 917521ULL);
x86_l_636:
	/* 0x636: mov    QWORD PTR [rsp+0x4],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179870047ULL);
x86_l_63f:
	/* 0x63f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_644:
	/* 0x644: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_64b:
	/* 0x64b: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_651:
	/* 0x651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_653:
	/* 0x653: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_656:
	/* 0x656: je     858 <generic_lsm_actions+0x858> */
	X86_SIM_X86_JCC(X86_CC_E, 0x656, 0x858, x86_l_858);
x86_l_65c:
	/* 0x65c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_65e:
	/* 0x65e: jmp    878 <generic_lsm_actions+0x878> */
	X86_SIM_X86_JMP(0x65e, 0x878, x86_l_878);
x86_l_663:
	/* 0x663: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_668:
	/* 0x668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66a:
	/* 0x66a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_66f:
	/* 0x66f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_674:
	/* 0x674: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_67b:
	/* 0x67b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_680:
	/* 0x680: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_682:
	/* 0x682: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_685:
	/* 0x685: je     1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x685, 0x1ab, x86_l_1ab);
x86_l_68b:
	/* 0x68b: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_690:
	/* 0x690: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_694:
	/* 0x694: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_699:
	/* 0x699: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a6:
	/* 0x6a6: mov    rbp,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_6ad:
	/* 0x6ad: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6b0:
	/* 0x6b0: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b5:
	/* 0x6b5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_6b8:
	/* 0x6b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ba:
	/* 0x6ba: mov    DWORD PTR [rsp+0x5c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991233ULL);
x86_l_6c2:
	/* 0x6c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: je     7ac <generic_lsm_actions+0x7ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c5, 0x7ac, x86_l_7ac);
x86_l_6cb:
	/* 0x6cb: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6ce:
	/* 0x6ce: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d3:
	/* 0x6d3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6d8:
	/* 0x6d8: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_6df:
	/* 0x6df: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e4:
	/* 0x6e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e6:
	/* 0x6e6: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x6e6, 0x1ab, x86_l_1ab);
x86_l_6eb:
	/* 0x6eb: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6ee:
	/* 0x6ee: mov    r13d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6f3:
	/* 0x6f3: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_6f6:
	/* 0x6f6: mov    r15d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6fb:
	/* 0x6fb: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_700:
	/* 0x700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_702:
	/* 0x702: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_706:
	/* 0x706: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_70e:
	/* 0x70e: mov    QWORD PTR [rsp+0xa0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_716:
	/* 0x716: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_719:
	/* 0x719: je     a9e <generic_lsm_actions+0xa9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x719, 0xa9e, x86_l_a9e);
x86_l_71f:
	/* 0x71f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_724:
	/* 0x724: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_72b:
	/* 0x72b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_730:
	/* 0x730: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_732:
	/* 0x732: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_735:
	/* 0x735: je     a9e <generic_lsm_actions+0xa9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x735, 0xa9e, x86_l_a9e);
x86_l_73b:
	/* 0x73b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_740:
	/* 0x740: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_743:
	/* 0x743: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_748:
	/* 0x748: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_74f:
	/* 0x74f: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_754:
	/* 0x754: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_756:
	/* 0x756: mov    rcx,QWORD PTR [rbp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_75a:
	/* 0x75a: mov    QWORD PTR [r13+0x0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_75e:
	/* 0x75e: mov    rcx,QWORD PTR [rbp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_762:
	/* 0x762: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [r13+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_76b:
	/* 0x76b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_76d:
	/* 0x76d: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_772:
	/* 0x772: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_777:
	/* 0x777: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_77b:
	/* 0x77b: je     8dc <generic_lsm_actions+0x8dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77b, 0x8dc, x86_l_8dc);
x86_l_781:
	/* 0x781: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_785:
	/* 0x785: je     8d9 <generic_lsm_actions+0x8d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x785, 0x8d9, x86_l_8d9);
x86_l_78b:
	/* 0x78b: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_78e:
	/* 0x78e: jne    a9e <generic_lsm_actions+0xa9e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x78e, 0xa9e, x86_l_a9e);
x86_l_794:
	/* 0x794: mov    ecx,DWORD PTR [rbp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_797:
	/* 0x797: jmp    8dc <generic_lsm_actions+0x8dc> */
	X86_SIM_X86_JMP(0x797, 0x8dc, x86_l_8dc);
x86_l_79c:
	/* 0x79c: add    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_79f:
	/* 0x79f: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7a7:
	/* 0x7a7: jmp    88b <generic_lsm_actions+0x88b> */
	X86_SIM_X86_JMP(0x7a7, 0x88b, x86_l_88b);
x86_l_7ac:
	/* 0x7ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7b1:
	/* 0x7b1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_7b9:
	/* 0x7b9: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_7bc:
	/* 0x7bc: lea    rdx,[rsp+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_7c1:
	/* 0x7c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c3:
	/* 0x7c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7cb:
	/* 0x7cb: je     6d3 <generic_lsm_actions+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7cb, 0x6d3, x86_l_6d3);
x86_l_7d1:
	/* 0x7d1: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_7d4:
	/* 0x7d4: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_7d6:
	/* 0x7d6: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7da:
	/* 0x7da: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_7e1:
	/* 0x7e1: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_7eb:
	/* 0x7eb: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7f0:
	/* 0x7f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f5:
	/* 0x7f5: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7fc:
	/* 0x7fc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_7ff:
	/* 0x7ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_801:
	/* 0x801: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_804:
	/* 0x804: je     b05 <generic_lsm_actions+0xb05> */
	X86_SIM_X86_JCC(X86_CC_E, 0x804, 0xb05, x86_l_b05);
x86_l_80a:
	/* 0x80a: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_80c:
	/* 0x80c: jmp    b25 <generic_lsm_actions+0xb25> */
	X86_SIM_X86_JMP(0x80c, 0xb25, x86_l_b25);
x86_l_811:
	/* 0x811: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_816:
	/* 0x816: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_819:
	/* 0x819: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_81c:
	/* 0x81c: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_821:
	/* 0x821: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_823:
	/* 0x823: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_825:
	/* 0x825: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_82b:
	/* 0x82b: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_830:
	/* 0x830: jmp    88b <generic_lsm_actions+0x88b> */
	X86_SIM_X86_JMP(0x830, 0x88b, x86_l_88b);
x86_l_832:
	/* 0x832: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_837:
	/* 0x837: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_83e:
	/* 0x83e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_841:
	/* 0x841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_843:
	/* 0x843: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_846:
	/* 0x846: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_84b:
	/* 0x84b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_84d:
	/* 0x84d: jne    1b4 <generic_lsm_actions+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x84d, 0x1b4, x86_l_1b4);
x86_l_853:
	/* 0x853: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x853, 0x1ab, x86_l_1ab);
x86_l_858:
	/* 0x858: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_860:
	/* 0x860: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_865:
	/* 0x865: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_86c:
	/* 0x86c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_86f:
	/* 0x86f: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_874:
	/* 0x874: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_876:
	/* 0x876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_878:
	/* 0x878: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87d:
	/* 0x87d: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_881:
	/* 0x881: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_885:
	/* 0x885: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_88b:
	/* 0x88b: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_892:
	/* 0x892: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_897:
	/* 0x897: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_89e:
	/* 0x89e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8a1:
	/* 0x8a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a3:
	/* 0x8a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a6:
	/* 0x8a6: je     1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a6, 0x1a6, x86_l_1a6);
x86_l_8ac:
	/* 0x8ac: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8b1:
	/* 0x8b1: jmp    1a6 <generic_lsm_actions+0x1a6> */
	X86_SIM_X86_JMP(0x8b1, 0x1a6, x86_l_1a6);
x86_l_8b6:
	/* 0x8b6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8bb:
	/* 0x8bb: mov    rdi,QWORD PTR [rip+0x1eb6b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_8c2:
	/* 0x8c2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c7:
	/* 0x8c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c9:
	/* 0x8c9: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8cc:
	/* 0x8cc: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_8ce:
	/* 0x8ce: jne    1b4 <generic_lsm_actions+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8ce, 0x1b4, x86_l_1b4);
x86_l_8d4:
	/* 0x8d4: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0x8d4, 0x1ab, x86_l_1ab);
x86_l_8d9:
	/* 0x8d9: mov    ecx,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8dc:
	/* 0x8dc: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_8de:
	/* 0x8de: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8e3:
	/* 0x8e3: mov    QWORD PTR [rdx+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8e7:
	/* 0x8e7: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8ec:
	/* 0x8ec: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_8f0:
	/* 0x8f0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f5:
	/* 0x8f5: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8fa:
	/* 0x8fa: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_8ff:
	/* 0x8ff: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_902:
	/* 0x902: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_904:
	/* 0x904: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_907:
	/* 0x907: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_90c:
	/* 0x90c: jmp    91c <generic_lsm_actions+0x91c> */
	X86_SIM_X86_JMP(0x90c, 0x91c, x86_l_91c);
x86_l_90e:
	/* 0x90e: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_912:
	/* 0x912: cmp    r15,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 20ULL);
x86_l_916:
	/* 0x916: je     a4f <generic_lsm_actions+0xa4f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x916, 0xa4f, x86_l_a4f);
x86_l_91c:
	/* 0x91c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_924:
	/* 0x924: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_929:
	/* 0x929: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_930:
	/* 0x930: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_935:
	/* 0x935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_937:
	/* 0x937: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93a:
	/* 0x93a: je     a4f <generic_lsm_actions+0xa4f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93a, 0xa4f, x86_l_a4f);
x86_l_940:
	/* 0x940: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_946:
	/* 0x946: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_94b:
	/* 0x94b: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_952:
	/* 0x952: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_955:
	/* 0x955: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_957:
	/* 0x957: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_95a:
	/* 0x95a: je     a4f <generic_lsm_actions+0xa4f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95a, 0xa4f, x86_l_a4f);
x86_l_960:
	/* 0x960: cmp    DWORD PTR [rax+r15*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 279172874239ULL);
x86_l_966:
	/* 0x966: je     a4f <generic_lsm_actions+0xa4f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x966, 0xa4f, x86_l_a4f);
x86_l_96c:
	/* 0x96c: mov    rax,QWORD PTR [rbp+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_974:
	/* 0x974: mov    ecx,DWORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_977:
	/* 0x977: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_97a:
	/* 0x97a: jge    a4f <generic_lsm_actions+0xa4f> */
	X86_SIM_X86_JCC(X86_CC_GE, 0x97a, 0xa4f, x86_l_a4f);
x86_l_980:
	/* 0x980: cmp    r15,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 16ULL);
x86_l_984:
	/* 0x984: je     9e7 <generic_lsm_actions+0x9e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x984, 0x9e7, x86_l_9e7);
x86_l_986:
	/* 0x986: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_98e:
	/* 0x98e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_993:
	/* 0x993: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_99a:
	/* 0x99a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_99f:
	/* 0x99f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a1:
	/* 0x9a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a4:
	/* 0x9a4: je     9df <generic_lsm_actions+0x9df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a4, 0x9df, x86_l_9df);
x86_l_9a6:
	/* 0x9a6: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_9ac:
	/* 0x9ac: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9b1:
	/* 0x9b1: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_9b8:
	/* 0x9b8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9bb:
	/* 0x9bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9bd:
	/* 0x9bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c0:
	/* 0x9c0: je     9df <generic_lsm_actions+0x9df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c0, 0x9df, x86_l_9df);
x86_l_9c2:
	/* 0x9c2: cmp    DWORD PTR [rax+r15*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 296352743423ULL);
x86_l_9c8:
	/* 0x9c8: mov    rax,QWORD PTR [rbp+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_9d0:
	/* 0x9d0: je     9e7 <generic_lsm_actions+0x9e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d0, 0x9e7, x86_l_9e7);
x86_l_9d2:
	/* 0x9d2: mov    r13d,DWORD PTR [rbp+r15*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 1), 24192ULL);
x86_l_9da:
	/* 0x9da: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9dd:
	/* 0x9dd: jmp    9f2 <generic_lsm_actions+0x9f2> */
	X86_SIM_X86_JMP(0x9dd, 0x9f2, x86_l_9f2);
x86_l_9df:
	/* 0x9df: mov    rax,QWORD PTR [rbp+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_9e7:
	/* 0x9e7: mov    r13d,DWORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9eb:
	/* 0x9eb: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9ee:
	/* 0x9ee: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_9f2:
	/* 0x9f2: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_9f5:
	/* 0x9f5: jle    90e <generic_lsm_actions+0x90e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x9f5, 0x90e, x86_l_90e);
x86_l_9fb:
	/* 0x9fb: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_a00:
	/* 0xa00: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_a05:
	/* 0xa05: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_a09:
	/* 0xa09: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_a0e:
	/* 0xa0e: cmovge r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_a12:
	/* 0xa12: movzx  ebp,BYTE PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 80ULL);
x86_l_a17:
	/* 0xa17: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a1c:
	/* 0xa1c: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a20:
	/* 0xa20: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a25:
	/* 0xa25: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a29:
	/* 0xa29: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a30:
	/* 0xa30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a35:
	/* 0xa35: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_a38:
	/* 0xa38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3a:
	/* 0xa3a: add    r13d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a3d:
	/* 0xa3d: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a42:
	/* 0xa42: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_a45:
	/* 0xa45: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a4a:
	/* 0xa4a: jmp    90e <generic_lsm_actions+0x90e> */
	X86_SIM_X86_JMP(0xa4a, 0x90e, x86_l_90e);
x86_l_a4f:
	/* 0xa4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a54:
	/* 0xa54: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_a5b:
	/* 0xa5b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a60:
	/* 0xa60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a62:
	/* 0xa62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a65:
	/* 0xa65: je     a86 <generic_lsm_actions+0xa86> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa65, 0xa86, x86_l_a86);
x86_l_a67:
	/* 0xa67: imul   rcx,QWORD PTR [rsp+0xa0],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 687193767360ULL);
x86_l_a73:
	/* 0xa73: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_a77:
	/* 0xa77: cmp    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7a:
	/* 0xa7a: jbe    a86 <generic_lsm_actions+0xa86> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa7a, 0xa86, x86_l_a86);
x86_l_a7c:
	/* 0xa7c: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_a84:
	/* 0xa84: jmp    a9e <generic_lsm_actions+0xa9e> */
	X86_SIM_X86_JMP(0xa84, 0xa9e, x86_l_a9e);
x86_l_a86:
	/* 0xa86: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a8b:
	/* 0xa8b: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_a92:
	/* 0xa92: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a97:
	/* 0xa97: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_a9a:
	/* 0xa9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a9c:
	/* 0xa9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9e:
	/* 0xa9e: lea    eax,[rbx+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_aa1:
	/* 0xaa1: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa6:
	/* 0xaa6: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_aac:
	/* 0xaac: je     ace <generic_lsm_actions+0xace> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaac, 0xace, x86_l_ace);
x86_l_aae:
	/* 0xaae: or     BYTE PTR [rbp+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_ab2:
	/* 0xab2: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_ab7:
	/* 0xab7: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_abc:
	/* 0xabc: mov    rsi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_ac3:
	/* 0xac3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac5:
	/* 0xac5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac7:
	/* 0xac7: mov    QWORD PTR [rbp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ace:
	/* 0xace: add    ebx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_ad1:
	/* 0xad1: cmp    DWORD PTR [r15+rbx*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 17179869184ULL);
x86_l_ad7:
	/* 0xad7: je     1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad7, 0x1ab, x86_l_1ab);
x86_l_add:
	/* 0xadd: or     BYTE PTR [rbp+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_ae1:
	/* 0xae1: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_ae6:
	/* 0xae6: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_aeb:
	/* 0xaeb: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_af0:
	/* 0xaf0: mov    rsi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_af7:
	/* 0xaf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af9:
	/* 0xaf9: mov    QWORD PTR [rbp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b00:
	/* 0xb00: jmp    1ab <generic_lsm_actions+0x1ab> */
	X86_SIM_X86_JMP(0xb00, 0x1ab, x86_l_1ab);
x86_l_b05:
	/* 0xb05: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_b0d:
	/* 0xb0d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b12:
	/* 0xb12: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_b19:
	/* 0xb19: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_b1c:
	/* 0xb1c: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b21:
	/* 0xb21: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b23:
	/* 0xb23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b25:
	/* 0xb25: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_b28:
	/* 0xb28: je     6d3 <generic_lsm_actions+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb28, 0x6d3, x86_l_6d3);
x86_l_b2e:
	/* 0xb2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b33:
	/* 0xb33: mov    rdi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_b3a:
	/* 0xb3a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b3f:
	/* 0xb3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b41:
	/* 0xb41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b44:
	/* 0xb44: je     6d3 <generic_lsm_actions+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb44, 0x6d3, x86_l_6d3);
x86_l_b4a:
	/* 0xb4a: mov    ecx,DWORD PTR [rsp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_b4e:
	/* 0xb4e: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b51:
	/* 0xb51: jmp    6d3 <generic_lsm_actions+0x6d3> */
	X86_SIM_X86_JMP(0xb51, 0x6d3, x86_l_6d3);
x86_l_b56:
	/* 0xb56: mov    r14d,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_b5b:
	/* 0xb5b: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_b5e:
	/* 0xb5e: je     b78 <generic_lsm_actions+0xb78> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5e, 0xb78, x86_l_b78);
x86_l_b60:
	/* 0xb60: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_b65:
	/* 0xb65: mov    rsi,QWORD PTR [rip+0x1eb72] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_b6c:
	/* 0xb6c: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b71:
	/* 0xb71: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_b76:
	/* 0xb76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b78:
	/* 0xb78: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7a:
	/* 0xb7a: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_b7d:
	/* 0xb7d: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_b80:
	/* 0xb80: jmp    db <generic_lsm_actions+0xdb> */
	X86_SIM_X86_JMP(0xb80, 0xdb, x86_l_db);
x86_l_b85:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
