extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char heap_ro_zero;
extern char ima_hash_map;
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
int tetragon_bpf_generic_lsm_core_v511_generic_lsm_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 216ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30:
	/* 0x30: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_38:
	/* 0x38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: je     e2 <generic_lsm_actions+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b, 0xe2, x86_l_e2);
x86_l_41:
	/* 0x41: mov    ebx,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_47:
	/* 0x47: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4a:
	/* 0x4a: jl     e2 <generic_lsm_actions+0xe2> */
	X86_SIM_X86_JCC(X86_CC_L, 0x4a, 0xe2, x86_l_e2);
x86_l_50:
	/* 0x50: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_56:
	/* 0x56: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b:
	/* 0x5b: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_62:
	/* 0x62: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_65:
	/* 0x65: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_67:
	/* 0x67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: je     e2 <generic_lsm_actions+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a, 0xe2, x86_l_e2);
x86_l_6c:
	/* 0x6c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6f:
	/* 0x6f: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_71:
	/* 0x71: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_76:
	/* 0x76: add    ebx,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7a:
	/* 0x7a: and    ebx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_80:
	/* 0x80: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_8b:
	/* 0x8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_90:
	/* 0x90: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_97:
	/* 0x97: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_9f:
	/* 0x9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1:
	/* 0xa1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x98],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ac:
	/* 0xac: je     225 <generic_lsm_actions+0x225> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac, 0x225, x86_l_225);
x86_l_b2:
	/* 0xb2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4:
	/* 0xb4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7:
	/* 0xb7: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_ba:
	/* 0xba: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: xor    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_c1:
	/* 0xc1: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_c9:
	/* 0xc9: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d1:
	/* 0xd1: xor    rcx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_d5:
	/* 0xd5: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_dd:
	/* 0xdd: jmp    249 <generic_lsm_actions+0x249> */
	X86_SIM_X86_JMP(0xdd, 0x249, x86_l_249);
x86_l_e2:
	/* 0xe2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4:
	/* 0xe4: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ec:
	/* 0xec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1:
	/* 0xf1: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_f8:
	/* 0xf8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd:
	/* 0xfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff:
	/* 0xff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_102:
	/* 0x102: je     20e <generic_lsm_actions+0x20e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x102, 0x20e, x86_l_20e);
x86_l_108:
	/* 0x108: movzx  ecx,BYTE PTR [rax+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_10c:
	/* 0x10c: mov    BYTE PTR [rax+0x5f08],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24328ULL);
x86_l_112:
	/* 0x112: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_115:
	/* 0x115: je     1a9 <generic_lsm_actions+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115, 0x1a9, x86_l_1a9);
x86_l_11b:
	/* 0x11b: and    cl,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_11e:
	/* 0x11e: je     1a9 <generic_lsm_actions+0x1a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e, 0x1a9, x86_l_1a9);
x86_l_124:
	/* 0x124: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_129:
	/* 0x129: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12e:
	/* 0x12e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132:
	/* 0x132: mov    QWORD PTR [rsp+0x49],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 313532612608ULL);
x86_l_13b:
	/* 0x13b: mov    QWORD PTR [rsp+0x51],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 347892350976ULL);
x86_l_144:
	/* 0x144: mov    QWORD PTR [rsp+0x59],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 382252089344ULL);
x86_l_14d:
	/* 0x14d: mov    QWORD PTR [rsp+0x61],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 416611827712ULL);
x86_l_156:
	/* 0x156: mov    QWORD PTR [rsp+0x69],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 450971566080ULL);
x86_l_15f:
	/* 0x15f: mov    QWORD PTR [rsp+0x71],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 485331304448ULL);
x86_l_168:
	/* 0x168: mov    QWORD PTR [rsp+0x79],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 519691042816ULL);
x86_l_171:
	/* 0x171: mov    QWORD PTR [rsp+0x81],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781184ULL);
x86_l_17d:
	/* 0x17d: mov    BYTE PTR [rsp+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 588410519552ULL);
x86_l_185:
	/* 0x185: mov    BYTE PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18f:
	/* 0x18f: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ima_hash_map)));
x86_l_196:
	/* 0x196: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_199:
	/* 0x199: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19e:
	/* 0x19e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0:
	/* 0x1a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2:
	/* 0x1a2: movzx  ebx,BYTE PTR [rbx+0x5f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24328ULL);
x86_l_1a9:
	/* 0x1a9: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_1ab:
	/* 0x1ab: jne    20e <generic_lsm_actions+0x20e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ab, 0x20e, x86_l_20e);
x86_l_1ad:
	/* 0x1ad: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1b2:
	/* 0x1b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b9:
	/* 0x1b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1be:
	/* 0x1be: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_1c5:
	/* 0x1c5: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ca:
	/* 0x1ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc:
	/* 0x1cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cf:
	/* 0x1cf: je     204 <generic_lsm_actions+0x204> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cf, 0x204, x86_l_204);
x86_l_1d1:
	/* 0x1d1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1d4:
	/* 0x1d4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1d9:
	/* 0x1d9: mov    rdi,QWORD PTR [rip+0x1f957] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_1e0:
	/* 0x1e0: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e5:
	/* 0x1e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7:
	/* 0x1e7: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e9:
	/* 0x1e9: lea    ecx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1ec:
	/* 0x1ec: cmp    ecx,0xfffff000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294963200ULL);
x86_l_1f2:
	/* 0x1f2: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1f7:
	/* 0x1f7: cmovae ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1fa:
	/* 0x1fa: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_202:
	/* 0x202: jmp    20e <generic_lsm_actions+0x20e> */
	X86_SIM_X86_JMP(0x202, 0x20e, x86_l_20e);
x86_l_204:
	/* 0x204: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_206:
	/* 0x206: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_20e:
	/* 0x20e: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_216:
	/* 0x216: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_21d:
	/* 0x21d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_21f:
	/* 0x21f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_220:
	/* 0x220: jmp    c73 <generic_lsm_actions+0xc73> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_225:
	/* 0x225: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_22a:
	/* 0x22a: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_232:
	/* 0x232: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_234:
	/* 0x234: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23c:
	/* 0x23c: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_241:
	/* 0x241: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_249:
	/* 0x249: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24c:
	/* 0x24c: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_24e:
	/* 0x24e: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_252:
	/* 0x252: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_255:
	/* 0x255: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257:
	/* 0x257: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25c:
	/* 0x25c: jmp    27c <generic_lsm_actions+0x27c> */
	X86_SIM_X86_JMP(0x25c, 0x27c, x86_l_27c);
x86_l_25e:
	/* 0x25e: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_263:
	/* 0x263: mov    QWORD PTR [rbp+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_267:
	/* 0x267: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_269:
	/* 0x269: mov    r13d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_32);
x86_l_26c:
	/* 0x26c: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_26f:
	/* 0x26f: mov    ebx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_32);
x86_l_272:
	/* 0x272: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_276:
	/* 0x276: je     c41 <generic_lsm_actions+0xc41> */
	X86_SIM_X86_JCC(X86_CC_E, 0x276, 0xc41, x86_l_c41);
x86_l_27c:
	/* 0x27c: lea    eax,[rbx*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_283:
	/* 0x283: cmp    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_286:
	/* 0x286: jae    c41 <generic_lsm_actions+0xc41> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x286, 0xc41, x86_l_c41);
x86_l_28c:
	/* 0x28c: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_28e:
	/* 0x28e: movsxd r14,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_293:
	/* 0x293: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_29e:
	/* 0x29e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a3:
	/* 0x2a3: mov    rdi,QWORD PTR [rip+0x1f962] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2aa:
	/* 0x2aa: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2b2:
	/* 0x2b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4:
	/* 0x2b4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b7:
	/* 0x2b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: je     26c <generic_lsm_actions+0x26c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ba, 0x26c, x86_l_26c);
x86_l_2bc:
	/* 0x2bc: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2bf:
	/* 0x2bf: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_2c3:
	/* 0x2c3: jg     2ed <generic_lsm_actions+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2c3, 0x2ed, x86_l_2ed);
x86_l_2c5:
	/* 0x2c5: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_2c9:
	/* 0x2c9: jg     324 <generic_lsm_actions+0x324> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2c9, 0x324, x86_l_324);
x86_l_2cb:
	/* 0x2cb: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2cf:
	/* 0x2cf: jg     461 <generic_lsm_actions+0x461> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2cf, 0x461, x86_l_461);
x86_l_2d5:
	/* 0x2d5: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_2d8:
	/* 0x2d8: je     7b1 <generic_lsm_actions+0x7b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d8, 0x7b1, x86_l_7b1);
x86_l_2de:
	/* 0x2de: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2e2:
	/* 0x2e2: je     47a <generic_lsm_actions+0x47a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e2, 0x47a, x86_l_47a);
x86_l_2e8:
	/* 0x2e8: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x2e8, 0x263, x86_l_263);
x86_l_2ed:
	/* 0x2ed: cmp    r14d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 11ULL);
x86_l_2f1:
	/* 0x2f1: jg     433 <generic_lsm_actions+0x433> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2f1, 0x433, x86_l_433);
x86_l_2f7:
	/* 0x2f7: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_2fb:
	/* 0x2fb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fe:
	/* 0x2fe: jb     59b <generic_lsm_actions+0x59b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2fe, 0x59b, x86_l_59b);
x86_l_304:
	/* 0x304: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_308:
	/* 0x308: je     690 <generic_lsm_actions+0x690> */
	X86_SIM_X86_JCC(X86_CC_E, 0x308, 0x690, x86_l_690);
x86_l_30e:
	/* 0x30e: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_312:
	/* 0x312: jne    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x312, 0x263, x86_l_263);
x86_l_318:
	/* 0x318: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_31a:
	/* 0x31a: mov    edi,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_31f:
	/* 0x31f: jmp    65b <generic_lsm_actions+0x65b> */
	X86_SIM_X86_JMP(0x31f, 0x65b, x86_l_65b);
x86_l_324:
	/* 0x324: lea    eax,[r14-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_328:
	/* 0x328: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32b:
	/* 0x32b: jb     681 <generic_lsm_actions+0x681> */
	X86_SIM_X86_JCC(X86_CC_B, 0x32b, 0x681, x86_l_681);
x86_l_331:
	/* 0x331: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_335:
	/* 0x335: je     69d <generic_lsm_actions+0x69d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x335, 0x69d, x86_l_69d);
x86_l_33b:
	/* 0x33b: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_33f:
	/* 0x33f: jne    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33f, 0x263, x86_l_263);
x86_l_345:
	/* 0x345: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_348:
	/* 0x348: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_34d:
	/* 0x34d: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_350:
	/* 0x350: mov    r15d,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_355:
	/* 0x355: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_35e:
	/* 0x35e: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_367:
	/* 0x367: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_36a:
	/* 0x36a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36d:
	/* 0x36d: ja     25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x36d, 0x25e, x86_l_25e);
x86_l_373:
	/* 0x373: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_37b:
	/* 0x37b: jne    25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37b, 0x25e, x86_l_25e);
x86_l_381:
	/* 0x381: mov    rax,QWORD PTR [rbp+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_389:
	/* 0x389: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_38e:
	/* 0x38e: mov    eax,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_395:
	/* 0x395: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_399:
	/* 0x399: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_39e:
	/* 0x39e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a0:
	/* 0x3a0: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a9:
	/* 0x3a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ae:
	/* 0x3ae: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_3b5:
	/* 0x3b5: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ba:
	/* 0x3ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc:
	/* 0x3bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3bf:
	/* 0x3bf: je     25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3bf, 0x25e, x86_l_25e);
x86_l_3c5:
	/* 0x3c5: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3c9:
	/* 0x3c9: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3cd:
	/* 0x3cd: ja     25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3cd, 0x25e, x86_l_25e);
x86_l_3d3:
	/* 0x3d3: cmp    DWORD PTR [rbp+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_3dc:
	/* 0x3dc: jne    25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3dc, 0x25e, x86_l_25e);
x86_l_3e2:
	/* 0x3e2: mov    rcx,QWORD PTR [rbp+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_3ea:
	/* 0x3ea: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_3f2:
	/* 0x3f2: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3f8:
	/* 0x3f8: mov    ecx,DWORD PTR [rbp+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_3ff:
	/* 0x3ff: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_403:
	/* 0x403: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_408:
	/* 0x408: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_40b:
	/* 0x40b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_40d:
	/* 0x40d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_411:
	/* 0x411: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_416:
	/* 0x416: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_41b:
	/* 0x41b: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_422:
	/* 0x422: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_427:
	/* 0x427: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_42a:
	/* 0x42a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_42c:
	/* 0x42c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e:
	/* 0x42e: jmp    25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JMP(0x42e, 0x25e, x86_l_25e);
x86_l_433:
	/* 0x433: cmp    r14d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 12ULL);
x86_l_437:
	/* 0x437: je     866 <generic_lsm_actions+0x866> */
	X86_SIM_X86_JCC(X86_CC_E, 0x437, 0x866, x86_l_866);
x86_l_43d:
	/* 0x43d: cmp    r14d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 13ULL);
x86_l_441:
	/* 0x441: je     72c <generic_lsm_actions+0x72c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x441, 0x72c, x86_l_72c);
x86_l_447:
	/* 0x447: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_44b:
	/* 0x44b: jne    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x44b, 0x263, x86_l_263);
x86_l_451:
	/* 0x451: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_454:
	/* 0x454: mov    r15,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_45c:
	/* 0x45c: jmp    95a <generic_lsm_actions+0x95a> */
	X86_SIM_X86_JMP(0x45c, 0x95a, x86_l_95a);
x86_l_461:
	/* 0x461: mov    edi,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_466:
	/* 0x466: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_46a:
	/* 0x46a: je     65b <generic_lsm_actions+0x65b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46a, 0x65b, x86_l_65b);
x86_l_470:
	/* 0x470: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_474:
	/* 0x474: jne    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x474, 0x263, x86_l_263);
x86_l_47a:
	/* 0x47a: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_47d:
	/* 0x47d: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_480:
	/* 0x480: mov    r15d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_485:
	/* 0x485: add    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_488:
	/* 0x488: mov    eax,DWORD PTR [rcx+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_491:
	/* 0x491: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_49a:
	/* 0x49a: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4a3:
	/* 0x4a3: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4aa:
	/* 0x4aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4af:
	/* 0x4af: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_4b6:
	/* 0x4b6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4b9:
	/* 0x4b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb:
	/* 0x4bb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bd:
	/* 0x4bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c0:
	/* 0x4c0: je     915 <generic_lsm_actions+0x915> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c0, 0x915, x86_l_915);
x86_l_4c6:
	/* 0x4c6: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4ca:
	/* 0x4ca: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4ce:
	/* 0x4ce: ja     915 <generic_lsm_actions+0x915> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4ce, 0x915, x86_l_915);
x86_l_4d4:
	/* 0x4d4: cmp    DWORD PTR [rbp+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_4dd:
	/* 0x4dd: jne    915 <generic_lsm_actions+0x915> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4dd, 0x915, x86_l_915);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4e8:
	/* 0x4e8: mov    rax,QWORD PTR [rbp+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_4f0:
	/* 0x4f0: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_4f8:
	/* 0x4f8: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_4fd:
	/* 0x4fd: mov    eax,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_504:
	/* 0x504: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_508:
	/* 0x508: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_50d:
	/* 0x50d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f:
	/* 0x50f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_518:
	/* 0x518: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_51c:
	/* 0x51c: jne    8ff <generic_lsm_actions+0x8ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x51c, 0x8ff, x86_l_8ff);
x86_l_522:
	/* 0x522: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_527:
	/* 0x527: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_52a:
	/* 0x52a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52d:
	/* 0x52d: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_532:
	/* 0x532: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_537:
	/* 0x537: ja     91a <generic_lsm_actions+0x91a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x537, 0x91a, x86_l_91a);
x86_l_53d:
	/* 0x53d: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_545:
	/* 0x545: jne    91a <generic_lsm_actions+0x91a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x545, 0x91a, x86_l_91a);
x86_l_54b:
	/* 0x54b: mov    rax,QWORD PTR [rbp+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_553:
	/* 0x553: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_558:
	/* 0x558: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_55c:
	/* 0x55c: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_563:
	/* 0x563: mov    esi,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_56a:
	/* 0x56a: mov    eax,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4095ULL);
x86_l_56f:
	/* 0x56f: and    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_571:
	/* 0x571: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_574:
	/* 0x574: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_579:
	/* 0x579: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_57e:
	/* 0x57e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_580:
	/* 0x580: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_585:
	/* 0x585: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_58c:
	/* 0x58c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_591:
	/* 0x591: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_596:
	/* 0x596: jmp    648 <generic_lsm_actions+0x648> */
	X86_SIM_X86_JMP(0x596, 0x648, x86_l_648);
x86_l_59b:
	/* 0x59b: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_59d:
	/* 0x59d: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_5a2:
	/* 0x5a2: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_5a5:
	/* 0x5a5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a7:
	/* 0x5a7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5aa:
	/* 0x5aa: ja     91a <generic_lsm_actions+0x91a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5aa, 0x91a, x86_l_91a);
x86_l_5b0:
	/* 0x5b0: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_5b8:
	/* 0x5b8: jne    91a <generic_lsm_actions+0x91a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b8, 0x91a, x86_l_91a);
x86_l_5be:
	/* 0x5be: mov    rax,QWORD PTR [rbp+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_5c6:
	/* 0x5c6: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_5cb:
	/* 0x5cb: mov    rax,QWORD PTR [rbp+rax*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 184ULL);
x86_l_5d3:
	/* 0x5d3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d7:
	/* 0x5d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5da:
	/* 0x5da: je     91a <generic_lsm_actions+0x91a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5da, 0x91a, x86_l_91a);
x86_l_5e0:
	/* 0x5e0: cmp    r14d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 10ULL);
x86_l_5e4:
	/* 0x5e4: jne    988 <generic_lsm_actions+0x988> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5e4, 0x988, x86_l_988);
x86_l_5ea:
	/* 0x5ea: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5ef:
	/* 0x5ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f1:
	/* 0x5f1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5f6:
	/* 0x5f6: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5fa:
	/* 0x5fa: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5fe:
	/* 0x5fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_603:
	/* 0x603: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_60a:
	/* 0x60a: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_60f:
	/* 0x60f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611:
	/* 0x611: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_613:
	/* 0x613: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_616:
	/* 0x616: je     91a <generic_lsm_actions+0x91a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x616, 0x91a, x86_l_91a);
x86_l_61c:
	/* 0x61c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61e:
	/* 0x61e: mov    DWORD PTR [rsp+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_622:
	/* 0x622: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_627:
	/* 0x627: mov    DWORD PTR [rsp+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_62b:
	/* 0x62b: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62f:
	/* 0x62f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_634:
	/* 0x634: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_639:
	/* 0x639: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_640:
	/* 0x640: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_643:
	/* 0x643: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_648:
	/* 0x648: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64a:
	/* 0x64a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64c:
	/* 0x64c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64e:
	/* 0x64e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_650:
	/* 0x650: jne    26c <generic_lsm_actions+0x26c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x650, 0x26c, x86_l_26c);
x86_l_656:
	/* 0x656: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x656, 0x263, x86_l_263);
x86_l_65b:
	/* 0x65b: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_661:
	/* 0x661: cmp    BYTE PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_669:
	/* 0x669: je     95a <generic_lsm_actions+0x95a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x669, 0x95a, x86_l_95a);
x86_l_66f:
	/* 0x66f: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_67c:
	/* 0x67c: jmp    95a <generic_lsm_actions+0x95a> */
	X86_SIM_X86_JMP(0x67c, 0x95a, x86_l_95a);
x86_l_681:
	/* 0x681: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_683:
	/* 0x683: mov    eax,DWORD PTR [r15+rbx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 4ULL);
x86_l_688:
	/* 0x688: mov    DWORD PTR [rbp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_68b:
	/* 0x68b: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x68b, 0x263, x86_l_263);
x86_l_690:
	/* 0x690: mov    DWORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_698:
	/* 0x698: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x698, 0x263, x86_l_263);
x86_l_69d:
	/* 0x69d: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_69f:
	/* 0x69f: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_6a5:
	/* 0x6a5: cmp    BYTE PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_6ad:
	/* 0x6ad: je     95a <generic_lsm_actions+0x95a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ad, 0x95a, x86_l_95a);
x86_l_6b3:
	/* 0x6b3: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b8:
	/* 0x6b8: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_6ba:
	/* 0x6ba: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6bf:
	/* 0x6bf: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6c3:
	/* 0x6c3: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6c7:
	/* 0x6c7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6cc:
	/* 0x6cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d2:
	/* 0x6d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d7:
	/* 0x6d7: mov    rbp,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_6de:
	/* 0x6de: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6e1:
	/* 0x6e1: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_6e4:
	/* 0x6e4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6e7:
	/* 0x6e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e9:
	/* 0x6e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: je     8de <generic_lsm_actions+0x8de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ec, 0x8de, x86_l_8de);
x86_l_6f2:
	/* 0x6f2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6f5:
	/* 0x6f5: mov    DWORD PTR [rsp+0x48],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309238562833ULL);
x86_l_6fd:
	/* 0x6fd: mov    QWORD PTR [rsp+0x4c],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 326417515359ULL);
x86_l_706:
	/* 0x706: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_70b:
	/* 0x70b: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_712:
	/* 0x712: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_717:
	/* 0x717: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_71a:
	/* 0x71a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71c:
	/* 0x71c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_71f:
	/* 0x71f: je     927 <generic_lsm_actions+0x927> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71f, 0x927, x86_l_927);
x86_l_725:
	/* 0x725: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_727:
	/* 0x727: jmp    947 <generic_lsm_actions+0x947> */
	X86_SIM_X86_JMP(0x727, 0x947, x86_l_947);
x86_l_72c:
	/* 0x72c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_731:
	/* 0x731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_733:
	/* 0x733: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_738:
	/* 0x738: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_73d:
	/* 0x73d: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_744:
	/* 0x744: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_749:
	/* 0x749: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74b:
	/* 0x74b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74e:
	/* 0x74e: je     263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74e, 0x263, x86_l_263);
x86_l_754:
	/* 0x754: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_759:
	/* 0x759: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_75d:
	/* 0x75d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_761:
	/* 0x761: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_769:
	/* 0x769: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_76e:
	/* 0x76e: mov    rbp,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_775:
	/* 0x775: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_778:
	/* 0x778: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_77b:
	/* 0x77b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_77e:
	/* 0x77e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_780:
	/* 0x780: mov    DWORD PTR [rsp+0x44],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776129ULL);
x86_l_788:
	/* 0x788: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78b:
	/* 0x78b: je     876 <generic_lsm_actions+0x876> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78b, 0x876, x86_l_876);
x86_l_791:
	/* 0x791: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_794:
	/* 0x794: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_799:
	/* 0x799: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_79e:
	/* 0x79e: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_7a5:
	/* 0x7a5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7aa:
	/* 0x7aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ac:
	/* 0x7ac: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x7ac, 0x263, x86_l_263);
x86_l_7b1:
	/* 0x7b1: lea    eax,[rbx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_7b4:
	/* 0x7b4: mov    r13d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_7b9:
	/* 0x7b9: lea    eax,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_7bc:
	/* 0x7bc: mov    r15d,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_7c1:
	/* 0x7c1: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_7c6:
	/* 0x7c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c8:
	/* 0x7c8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7cd:
	/* 0x7cd: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_7d5:
	/* 0x7d5: mov    QWORD PTR [rsp+0xd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7dd:
	/* 0x7dd: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_7e0:
	/* 0x7e0: je     b74 <generic_lsm_actions+0xb74> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e0, 0xb74, x86_l_b74);
x86_l_7e6:
	/* 0x7e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7eb:
	/* 0x7eb: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_7f2:
	/* 0x7f2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f7:
	/* 0x7f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f9:
	/* 0x7f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7fc:
	/* 0x7fc: je     b74 <generic_lsm_actions+0xb74> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7fc, 0xb74, x86_l_b74);
x86_l_802:
	/* 0x802: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_807:
	/* 0x807: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_80a:
	/* 0x80a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_80f:
	/* 0x80f: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_816:
	/* 0x816: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_81b:
	/* 0x81b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81d:
	/* 0x81d: mov    rcx,QWORD PTR [rbp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_821:
	/* 0x821: mov    QWORD PTR [r13+0x0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_825:
	/* 0x825: mov    rcx,QWORD PTR [rbp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_829:
	/* 0x829: mov    QWORD PTR [rsp+0x90],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_831:
	/* 0x831: mov    QWORD PTR [r13+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_835:
	/* 0x835: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_837:
	/* 0x837: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_83c:
	/* 0x83c: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_841:
	/* 0x841: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_845:
	/* 0x845: je     9ac <generic_lsm_actions+0x9ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x845, 0x9ac, x86_l_9ac);
x86_l_84b:
	/* 0x84b: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_84f:
	/* 0x84f: je     9a9 <generic_lsm_actions+0x9a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84f, 0x9a9, x86_l_9a9);
x86_l_855:
	/* 0x855: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_858:
	/* 0x858: jne    b74 <generic_lsm_actions+0xb74> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x858, 0xb74, x86_l_b74);
x86_l_85e:
	/* 0x85e: mov    ecx,DWORD PTR [rbp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_861:
	/* 0x861: jmp    9ac <generic_lsm_actions+0x9ac> */
	X86_SIM_X86_JMP(0x861, 0x9ac, x86_l_9ac);
x86_l_866:
	/* 0x866: add    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_869:
	/* 0x869: mov    r15,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_871:
	/* 0x871: jmp    95a <generic_lsm_actions+0x95a> */
	X86_SIM_X86_JMP(0x871, 0x95a, x86_l_95a);
x86_l_876:
	/* 0x876: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_87b:
	/* 0x87b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_880:
	/* 0x880: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_883:
	/* 0x883: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_886:
	/* 0x886: lea    rdx,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_88b:
	/* 0x88b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88d:
	/* 0x88d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_890:
	/* 0x890: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_895:
	/* 0x895: je     799 <generic_lsm_actions+0x799> */
	X86_SIM_X86_JCC(X86_CC_E, 0x895, 0x799, x86_l_799);
x86_l_89b:
	/* 0x89b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_89e:
	/* 0x89e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8a0:
	/* 0x8a0: mov    WORD PTR [rsp+0x48],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8a5:
	/* 0x8a5: mov    WORD PTR [rsp+0x4a],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 317827579907ULL);
x86_l_8ac:
	/* 0x8ac: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_8b6:
	/* 0x8b6: mov    QWORD PTR [rsp+0x4c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_8bb:
	/* 0x8bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8c0:
	/* 0x8c0: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8c7:
	/* 0x8c7: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8cc:
	/* 0x8cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ce:
	/* 0x8ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8d1:
	/* 0x8d1: je     bf0 <generic_lsm_actions+0xbf0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d1, 0xbf0, x86_l_bf0);
x86_l_8d7:
	/* 0x8d7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8d9:
	/* 0x8d9: jmp    c12 <generic_lsm_actions+0xc12> */
	X86_SIM_X86_JMP(0x8d9, 0xc12, x86_l_c12);
x86_l_8de:
	/* 0x8de: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8e3:
	/* 0x8e3: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_8e6:
	/* 0x8e6: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_8e9:
	/* 0x8e9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8ee:
	/* 0x8ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f0:
	/* 0x8f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f2:
	/* 0x8f2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_8f8:
	/* 0x8f8: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8fd:
	/* 0x8fd: jmp    95a <generic_lsm_actions+0x95a> */
	X86_SIM_X86_JMP(0x8fd, 0x95a, x86_l_95a);
x86_l_8ff:
	/* 0x8ff: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_904:
	/* 0x904: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_90b:
	/* 0x90b: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_910:
	/* 0x910: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_912:
	/* 0x912: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_915:
	/* 0x915: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_91a:
	/* 0x91a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_91c:
	/* 0x91c: jne    26c <generic_lsm_actions+0x26c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x91c, 0x26c, x86_l_26c);
x86_l_922:
	/* 0x922: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x922, 0x263, x86_l_263);
x86_l_927:
	/* 0x927: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_92f:
	/* 0x92f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_934:
	/* 0x934: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_93b:
	/* 0x93b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_93e:
	/* 0x93e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_943:
	/* 0x943: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_945:
	/* 0x945: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_947:
	/* 0x947: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_94c:
	/* 0x94c: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_950:
	/* 0x950: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_954:
	/* 0x954: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_95a:
	/* 0x95a: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_962:
	/* 0x962: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_967:
	/* 0x967: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_96e:
	/* 0x96e: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_973:
	/* 0x973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_975:
	/* 0x975: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_978:
	/* 0x978: je     25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x978, 0x25e, x86_l_25e);
x86_l_97e:
	/* 0x97e: inc QWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R15, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_983:
	/* 0x983: jmp    25e <generic_lsm_actions+0x25e> */
	X86_SIM_X86_JMP(0x983, 0x25e, x86_l_25e);
x86_l_988:
	/* 0x988: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_98d:
	/* 0x98d: mov    rdi,QWORD PTR [rip+0x1f963] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_994:
	/* 0x994: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_997:
	/* 0x997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_999:
	/* 0x999: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_99c:
	/* 0x99c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_99e:
	/* 0x99e: jne    26c <generic_lsm_actions+0x26c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x99e, 0x26c, x86_l_26c);
x86_l_9a4:
	/* 0x9a4: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0x9a4, 0x263, x86_l_263);
x86_l_9a9:
	/* 0x9a9: mov    ecx,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ac:
	/* 0x9ac: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9ae:
	/* 0x9ae: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9b6:
	/* 0x9b6: mov    QWORD PTR [rdx+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ba:
	/* 0x9ba: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9bf:
	/* 0x9bf: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_9c3:
	/* 0x9c3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9c8:
	/* 0x9c8: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9cd:
	/* 0x9cd: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_9d2:
	/* 0x9d2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9d5:
	/* 0x9d5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9d7:
	/* 0x9d7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9da:
	/* 0x9da: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9df:
	/* 0x9df: jmp    9ef <generic_lsm_actions+0x9ef> */
	X86_SIM_X86_JMP(0x9df, 0x9ef, x86_l_9ef);
x86_l_9e1:
	/* 0x9e1: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_9e5:
	/* 0x9e5: cmp    r15,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 20ULL);
x86_l_9e9:
	/* 0x9e9: je     b1c <generic_lsm_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e9, 0xb1c, x86_l_b1c);
x86_l_9ef:
	/* 0x9ef: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f6:
	/* 0x9f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9fb:
	/* 0x9fb: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a02:
	/* 0xa02: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a05:
	/* 0xa05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a07:
	/* 0xa07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0a:
	/* 0xa0a: je     b1c <generic_lsm_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0a, 0xb1c, x86_l_b1c);
x86_l_a10:
	/* 0xa10: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_a16:
	/* 0xa16: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a1b:
	/* 0xa1b: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_a22:
	/* 0xa22: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a25:
	/* 0xa25: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a27:
	/* 0xa27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a2a:
	/* 0xa2a: je     b1c <generic_lsm_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2a, 0xb1c, x86_l_b1c);
x86_l_a30:
	/* 0xa30: cmp    DWORD PTR [rax+r15*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 279172874239ULL);
x86_l_a36:
	/* 0xa36: je     b1c <generic_lsm_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa36, 0xb1c, x86_l_b1c);
x86_l_a3c:
	/* 0xa3c: mov    rax,QWORD PTR [rbp+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_a44:
	/* 0xa44: mov    ecx,DWORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a47:
	/* 0xa47: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a4a:
	/* 0xa4a: jge    b1c <generic_lsm_actions+0xb1c> */
	X86_SIM_X86_JCC(X86_CC_GE, 0xa4a, 0xb1c, x86_l_b1c);
x86_l_a50:
	/* 0xa50: cmp    r15,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 16ULL);
x86_l_a54:
	/* 0xa54: je     ab4 <generic_lsm_actions+0xab4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa54, 0xab4, x86_l_ab4);
x86_l_a56:
	/* 0xa56: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5d:
	/* 0xa5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a62:
	/* 0xa62: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a69:
	/* 0xa69: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a6c:
	/* 0xa6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6e:
	/* 0xa6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a71:
	/* 0xa71: je     aac <generic_lsm_actions+0xaac> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa71, 0xaac, x86_l_aac);
x86_l_a73:
	/* 0xa73: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_a79:
	/* 0xa79: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a7e:
	/* 0xa7e: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_a85:
	/* 0xa85: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a88:
	/* 0xa88: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a8a:
	/* 0xa8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8d:
	/* 0xa8d: je     aac <generic_lsm_actions+0xaac> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8d, 0xaac, x86_l_aac);
x86_l_a8f:
	/* 0xa8f: cmp    DWORD PTR [rax+r15*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 296352743423ULL);
x86_l_a95:
	/* 0xa95: mov    rax,QWORD PTR [rbp+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_a9d:
	/* 0xa9d: je     ab4 <generic_lsm_actions+0xab4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa9d, 0xab4, x86_l_ab4);
x86_l_a9f:
	/* 0xa9f: mov    r13d,DWORD PTR [rbp+r15*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 1), 24192ULL);
x86_l_aa7:
	/* 0xaa7: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_aaa:
	/* 0xaaa: jmp    abf <generic_lsm_actions+0xabf> */
	X86_SIM_X86_JMP(0xaaa, 0xabf, x86_l_abf);
x86_l_aac:
	/* 0xaac: mov    rax,QWORD PTR [rbp+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_ab4:
	/* 0xab4: mov    r13d,DWORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ab8:
	/* 0xab8: sub    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_abb:
	/* 0xabb: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_abf:
	/* 0xabf: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_ac2:
	/* 0xac2: jle    9e1 <generic_lsm_actions+0x9e1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xac2, 0x9e1, x86_l_9e1);
x86_l_ac8:
	/* 0xac8: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_acd:
	/* 0xacd: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_ad2:
	/* 0xad2: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_ad6:
	/* 0xad6: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_adb:
	/* 0xadb: cmovge r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_adf:
	/* 0xadf: movzx  ebp,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_ae4:
	/* 0xae4: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ae9:
	/* 0xae9: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_aed:
	/* 0xaed: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af2:
	/* 0xaf2: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_af6:
	/* 0xaf6: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_afd:
	/* 0xafd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b02:
	/* 0xb02: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_b05:
	/* 0xb05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b07:
	/* 0xb07: add    r13d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b0a:
	/* 0xb0a: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b0f:
	/* 0xb0f: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_b12:
	/* 0xb12: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b17:
	/* 0xb17: jmp    9e1 <generic_lsm_actions+0x9e1> */
	X86_SIM_X86_JMP(0xb17, 0x9e1, x86_l_9e1);
x86_l_b1c:
	/* 0xb1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b21:
	/* 0xb21: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_b28:
	/* 0xb28: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b30:
	/* 0xb30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b32:
	/* 0xb32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b35:
	/* 0xb35: je     b57 <generic_lsm_actions+0xb57> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb35, 0xb57, x86_l_b57);
x86_l_b37:
	/* 0xb37: imul   rcx,QWORD PTR [rsp+0xd0],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 893352197568ULL);
x86_l_b43:
	/* 0xb43: add    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_b48:
	/* 0xb48: cmp    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4b:
	/* 0xb4b: jbe    b57 <generic_lsm_actions+0xb57> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xb4b, 0xb57, x86_l_b57);
x86_l_b4d:
	/* 0xb4d: mov    DWORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_b55:
	/* 0xb55: jmp    b74 <generic_lsm_actions+0xb74> */
	X86_SIM_X86_JMP(0xb55, 0xb74, x86_l_b74);
x86_l_b57:
	/* 0xb57: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b5c:
	/* 0xb5c: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_b63:
	/* 0xb63: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b6b:
	/* 0xb6b: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b70:
	/* 0xb70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: lea    eax,[rbx+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_b77:
	/* 0xb77: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b7c:
	/* 0xb7c: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_b82:
	/* 0xb82: je     ba7 <generic_lsm_actions+0xba7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb82, 0xba7, x86_l_ba7);
x86_l_b84:
	/* 0xb84: or     BYTE PTR [rbp+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_b88:
	/* 0xb88: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_b8d:
	/* 0xb8d: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b95:
	/* 0xb95: mov    rsi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_b9c:
	/* 0xb9c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9e:
	/* 0xb9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba0:
	/* 0xba0: mov    QWORD PTR [rbp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ba7:
	/* 0xba7: lea    eax,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_baa:
	/* 0xbaa: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_bb0:
	/* 0xbb0: je     bd8 <generic_lsm_actions+0xbd8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb0, 0xbd8, x86_l_bd8);
x86_l_bb2:
	/* 0xbb2: or     BYTE PTR [rbp+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_bb6:
	/* 0xbb6: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_bbb:
	/* 0xbbb: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_bc0:
	/* 0xbc0: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bc8:
	/* 0xbc8: mov    rsi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_bcf:
	/* 0xbcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd1:
	/* 0xbd1: mov    QWORD PTR [rbp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bd8:
	/* 0xbd8: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_bdb:
	/* 0xbdb: cmp    DWORD PTR [r15+rbx*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 17179869184ULL);
x86_l_be1:
	/* 0xbe1: je     263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe1, 0x263, x86_l_263);
x86_l_be7:
	/* 0xbe7: or     BYTE PTR [rbp+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_beb:
	/* 0xbeb: jmp    263 <generic_lsm_actions+0x263> */
	X86_SIM_X86_JMP(0xbeb, 0x263, x86_l_263);
x86_l_bf0:
	/* 0xbf0: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_bf8:
	/* 0xbf8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bfd:
	/* 0xbfd: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c04:
	/* 0xc04: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c09:
	/* 0xc09: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c0e:
	/* 0xc0e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c10:
	/* 0xc10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c12:
	/* 0xc12: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_c15:
	/* 0xc15: je     799 <generic_lsm_actions+0x799> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc15, 0x799, x86_l_799);
x86_l_c1b:
	/* 0xc1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c20:
	/* 0xc20: mov    rdi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c27:
	/* 0xc27: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c2a:
	/* 0xc2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2c:
	/* 0xc2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c2f:
	/* 0xc2f: je     799 <generic_lsm_actions+0x799> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2f, 0x799, x86_l_799);
x86_l_c35:
	/* 0xc35: mov    ecx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_c39:
	/* 0xc39: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c3c:
	/* 0xc3c: jmp    799 <generic_lsm_actions+0x799> */
	X86_SIM_X86_JMP(0xc3c, 0x799, x86_l_799);
x86_l_c41:
	/* 0xc41: mov    r14d,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c46:
	/* 0xc46: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_c49:
	/* 0xc49: je     c66 <generic_lsm_actions+0xc66> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc49, 0xc66, x86_l_c66);
x86_l_c4b:
	/* 0xc4b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_c50:
	/* 0xc50: mov    rsi,QWORD PTR [rip+0x1f96f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_c57:
	/* 0xc57: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c5f:
	/* 0xc5f: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_c64:
	/* 0xc64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c66:
	/* 0xc66: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c68:
	/* 0xc68: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_c6b:
	/* 0xc6b: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_c6e:
	/* 0xc6e: jmp    e4 <generic_lsm_actions+0xe4> */
	X86_SIM_X86_JMP(0xc6e, 0xe4, x86_l_e4);
x86_l_c73:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
