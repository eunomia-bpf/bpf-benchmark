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
	/* 0x18: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33:
	/* 0x33: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3b:
	/* 0x3b: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: je     e3 <generic_lsm_actions+0xe3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e, 0xe3, x86_l_e3);
x86_l_44:
	/* 0x44: mov    ebx,DWORD PTR [rsi+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_4a:
	/* 0x4a: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4d:
	/* 0x4d: jl     e3 <generic_lsm_actions+0xe3> */
	X86_SIM_X86_JCC(X86_CC_L, 0x4d, 0xe3, x86_l_e3);
x86_l_53:
	/* 0x53: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_5a:
	/* 0x5a: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_61:
	/* 0x61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66:
	/* 0x66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68:
	/* 0x68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b:
	/* 0x6b: je     e3 <generic_lsm_actions+0xe3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b, 0xe3, x86_l_e3);
x86_l_6d:
	/* 0x6d: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_6f:
	/* 0x6f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_75:
	/* 0x75: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_78:
	/* 0x78: add    ebx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_7b:
	/* 0x7b: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_86:
	/* 0x86: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8d:
	/* 0x8d: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_95:
	/* 0x95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9a:
	/* 0x9a: and    ebx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a0:
	/* 0xa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2:
	/* 0xa2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a5:
	/* 0xa5: mov    QWORD PTR [rsp+0x98],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ad:
	/* 0xad: je     22b <generic_lsm_actions+0x22b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad, 0x22b, x86_l_22b);
x86_l_b3:
	/* 0xb3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5:
	/* 0xb5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b8:
	/* 0xb8: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_bb:
	/* 0xbb: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_be:
	/* 0xbe: xor    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_c2:
	/* 0xc2: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_ca:
	/* 0xca: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d2:
	/* 0xd2: xor    rcx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 7ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_de:
	/* 0xde: jmp    24f <generic_lsm_actions+0x24f> */
	X86_SIM_X86_JMP(0xde, 0x24f, x86_l_24f);
x86_l_e3:
	/* 0xe3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5:
	/* 0xe5: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ed:
	/* 0xed: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_f4:
	/* 0xf4: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f9:
	/* 0xf9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fe:
	/* 0xfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100:
	/* 0x100: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_103:
	/* 0x103: je     214 <generic_lsm_actions+0x214> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103, 0x214, x86_l_214);
x86_l_109:
	/* 0x109: movzx  ecx,BYTE PTR [rax+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_10d:
	/* 0x10d: mov    BYTE PTR [rax+0x5f08],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24328ULL);
x86_l_113:
	/* 0x113: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_116:
	/* 0x116: je     1af <generic_lsm_actions+0x1af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116, 0x1af, x86_l_1af);
x86_l_11c:
	/* 0x11c: and    cl,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_11f:
	/* 0x11f: je     1af <generic_lsm_actions+0x1af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f, 0x1af, x86_l_1af);
x86_l_125:
	/* 0x125: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_128:
	/* 0x128: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_12d:
	/* 0x12d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f:
	/* 0x12f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_134:
	/* 0x134: mov    QWORD PTR [rsp+0x49],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 313532612608ULL);
x86_l_13d:
	/* 0x13d: mov    QWORD PTR [rsp+0x51],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 347892350976ULL);
x86_l_146:
	/* 0x146: mov    QWORD PTR [rsp+0x59],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 382252089344ULL);
x86_l_14f:
	/* 0x14f: mov    QWORD PTR [rsp+0x61],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 416611827712ULL);
x86_l_158:
	/* 0x158: mov    QWORD PTR [rsp+0x69],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 450971566080ULL);
x86_l_161:
	/* 0x161: mov    QWORD PTR [rsp+0x71],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 485331304448ULL);
x86_l_16a:
	/* 0x16a: mov    QWORD PTR [rsp+0x79],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 519691042816ULL);
x86_l_173:
	/* 0x173: mov    QWORD PTR [rsp+0x81],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554050781184ULL);
x86_l_17f:
	/* 0x17f: mov    BYTE PTR [rsp+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 588410519552ULL);
x86_l_187:
	/* 0x187: mov    BYTE PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ima_hash_map)));
x86_l_193:
	/* 0x193: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_195:
	/* 0x195: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19a:
	/* 0x19a: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19f:
	/* 0x19f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a4:
	/* 0x1a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6:
	/* 0x1a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8:
	/* 0x1a8: movzx  ebx,BYTE PTR [rbx+0x5f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24328ULL);
x86_l_1af:
	/* 0x1af: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_1b1:
	/* 0x1b1: jne    214 <generic_lsm_actions+0x214> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b1, 0x214, x86_l_214);
x86_l_1b3:
	/* 0x1b3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1b8:
	/* 0x1b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba:
	/* 0x1ba: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bf:
	/* 0x1bf: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_1c6:
	/* 0x1c6: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1cb:
	/* 0x1cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d0:
	/* 0x1d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2:
	/* 0x1d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d5:
	/* 0x1d5: je     20a <generic_lsm_actions+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d5, 0x20a, x86_l_20a);
x86_l_1d7:
	/* 0x1d7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1da:
	/* 0x1da: mov    rdi,QWORD PTR [rip+0x225c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_1e1:
	/* 0x1e1: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e6:
	/* 0x1e6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1eb:
	/* 0x1eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed:
	/* 0x1ed: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ef:
	/* 0x1ef: lea    ecx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1f2:
	/* 0x1f2: cmp    ecx,0xfffff000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294963200ULL);
x86_l_1f8:
	/* 0x1f8: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1fd:
	/* 0x1fd: cmovae ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_200:
	/* 0x200: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_208:
	/* 0x208: jmp    214 <generic_lsm_actions+0x214> */
	X86_SIM_X86_JMP(0x208, 0x214, x86_l_214);
x86_l_20a:
	/* 0x20a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20c:
	/* 0x20c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_214:
	/* 0x214: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_21c:
	/* 0x21c: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_223:
	/* 0x223: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_225:
	/* 0x225: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_226:
	/* 0x226: jmp    d40 <generic_lsm_actions+0xd40> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_22b:
	/* 0x22b: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_230:
	/* 0x230: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_238:
	/* 0x238: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_23a:
	/* 0x23a: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_242:
	/* 0x242: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_247:
	/* 0x247: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_24f:
	/* 0x24f: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_252:
	/* 0x252: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_255:
	/* 0x255: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_257:
	/* 0x257: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25b:
	/* 0x25b: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_260:
	/* 0x260: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_263:
	/* 0x263: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266:
	/* 0x266: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b:
	/* 0x26b: jmp    282 <generic_lsm_actions+0x282> */
	X86_SIM_X86_JMP(0x26b, 0x282, x86_l_282);
x86_l_26d:
	/* 0x26d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272:
	/* 0x272: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_275:
	/* 0x275: mov    r12d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_32);
x86_l_278:
	/* 0x278: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_27c:
	/* 0x27c: je     d0a <generic_lsm_actions+0xd0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27c, 0xd0a, x86_l_d0a);
x86_l_282:
	/* 0x282: lea    eax,[r12*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_28a:
	/* 0x28a: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_28c:
	/* 0x28c: jae    d0a <generic_lsm_actions+0xd0a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x28c, 0xd0a, x86_l_d0a);
x86_l_292:
	/* 0x292: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_295:
	/* 0x295: movsxd r14,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_29a:
	/* 0x29a: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2a5:
	/* 0x2a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aa:
	/* 0x2aa: mov    rdi,QWORD PTR [rip+0x225d3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2b1:
	/* 0x2b1: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2b9:
	/* 0x2b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb:
	/* 0x2bb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd:
	/* 0x2bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c0:
	/* 0x2c0: je     26d <generic_lsm_actions+0x26d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c0, 0x26d, x86_l_26d);
x86_l_2c2:
	/* 0x2c2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c5:
	/* 0x2c5: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_2c9:
	/* 0x2c9: jg     2f8 <generic_lsm_actions+0x2f8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2c9, 0x2f8, x86_l_2f8);
x86_l_2cb:
	/* 0x2cb: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_2cf:
	/* 0x2cf: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4:
	/* 0x2d4: jg     335 <generic_lsm_actions+0x335> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2d4, 0x335, x86_l_335);
x86_l_2d6:
	/* 0x2d6: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2da:
	/* 0x2da: jg     479 <generic_lsm_actions+0x479> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2da, 0x479, x86_l_479);
x86_l_2e0:
	/* 0x2e0: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_2e3:
	/* 0x2e3: je     725 <generic_lsm_actions+0x725> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e3, 0x725, x86_l_725);
x86_l_2e9:
	/* 0x2e9: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2ed:
	/* 0x2ed: je     492 <generic_lsm_actions+0x492> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ed, 0x492, x86_l_492);
x86_l_2f3:
	/* 0x2f3: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0x2f3, 0x9d9, x86_l_9d9);
x86_l_2f8:
	/* 0x2f8: cmp    r14d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 11ULL);
x86_l_2fc:
	/* 0x2fc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_301:
	/* 0x301: jg     44a <generic_lsm_actions+0x44a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x301, 0x44a, x86_l_44a);
x86_l_307:
	/* 0x307: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_30b:
	/* 0x30b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30e:
	/* 0x30e: jb     508 <generic_lsm_actions+0x508> */
	X86_SIM_X86_JCC(X86_CC_B, 0x30e, 0x508, x86_l_508);
x86_l_314:
	/* 0x314: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_318:
	/* 0x318: je     5fa <generic_lsm_actions+0x5fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x318, 0x5fa, x86_l_5fa);
x86_l_31e:
	/* 0x31e: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_322:
	/* 0x322: jne    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x322, 0x9d9, x86_l_9d9);
x86_l_328:
	/* 0x328: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_32b:
	/* 0x32b: mov    eax,DWORD PTR [rcx+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_330:
	/* 0x330: jmp    5c2 <generic_lsm_actions+0x5c2> */
	X86_SIM_X86_JMP(0x330, 0x5c2, x86_l_5c2);
x86_l_335:
	/* 0x335: lea    eax,[r14-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_339:
	/* 0x339: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33c:
	/* 0x33c: jb     5e9 <generic_lsm_actions+0x5e9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x33c, 0x5e9, x86_l_5e9);
x86_l_342:
	/* 0x342: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_346:
	/* 0x346: je     607 <generic_lsm_actions+0x607> */
	X86_SIM_X86_JCC(X86_CC_E, 0x346, 0x607, x86_l_607);
x86_l_34c:
	/* 0x34c: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_350:
	/* 0x350: jne    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x350, 0x9d9, x86_l_9d9);
x86_l_356:
	/* 0x356: lea    eax,[r12+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_35b:
	/* 0x35b: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_35f:
	/* 0x35f: add    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_363:
	/* 0x363: mov    ebx,DWORD PTR [rcx+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_368:
	/* 0x368: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_371:
	/* 0x371: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_37a:
	/* 0x37a: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_37d:
	/* 0x37d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_380:
	/* 0x380: ja     9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x380, 0x9d9, x86_l_9d9);
x86_l_386:
	/* 0x386: cmp    DWORD PTR [r15+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_38f:
	/* 0x38f: jne    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38f, 0x9d9, x86_l_9d9);
x86_l_395:
	/* 0x395: mov    rax,QWORD PTR [r15+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_39d:
	/* 0x39d: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3a2:
	/* 0x3a2: mov    eax,DWORD PTR [r15+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_3aa:
	/* 0x3aa: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3ae:
	/* 0x3ae: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3b3:
	/* 0x3b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b5:
	/* 0x3b5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3b9:
	/* 0x3b9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3be:
	/* 0x3be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c3:
	/* 0x3c3: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_3ca:
	/* 0x3ca: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_3cd:
	/* 0x3cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cf:
	/* 0x3cf: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d4:
	/* 0x3d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d7:
	/* 0x3d7: je     9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d7, 0x9d9, x86_l_9d9);
x86_l_3dd:
	/* 0x3dd: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3e0:
	/* 0x3e0: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3e3:
	/* 0x3e3: ja     9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3e3, 0x9d9, x86_l_9d9);
x86_l_3e9:
	/* 0x3e9: cmp    DWORD PTR [r15+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_3f2:
	/* 0x3f2: jne    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f2, 0x9d9, x86_l_9d9);
x86_l_3f8:
	/* 0x3f8: mov    rcx,QWORD PTR [r15+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_400:
	/* 0x400: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_408:
	/* 0x408: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_40e:
	/* 0x40e: mov    ecx,DWORD PTR [r15+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_416:
	/* 0x416: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_41a:
	/* 0x41a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_41d:
	/* 0x41d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_422:
	/* 0x422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_424:
	/* 0x424: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_42d:
	/* 0x42d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_432:
	/* 0x432: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_434:
	/* 0x434: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_43b:
	/* 0x43b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_43e:
	/* 0x43e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_441:
	/* 0x441: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_443:
	/* 0x443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_445:
	/* 0x445: jmp    9d4 <generic_lsm_actions+0x9d4> */
	X86_SIM_X86_JMP(0x445, 0x9d4, x86_l_9d4);
x86_l_44a:
	/* 0x44a: cmp    r14d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 12ULL);
x86_l_44e:
	/* 0x44e: je     7d5 <generic_lsm_actions+0x7d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44e, 0x7d5, x86_l_7d5);
x86_l_454:
	/* 0x454: cmp    r14d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 13ULL);
x86_l_458:
	/* 0x458: je     69d <generic_lsm_actions+0x69d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x458, 0x69d, x86_l_69d);
x86_l_45e:
	/* 0x45e: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_462:
	/* 0x462: jne    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x462, 0x9d9, x86_l_9d9);
x86_l_468:
	/* 0x468: add    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_46c:
	/* 0x46c: mov    rbx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_474:
	/* 0x474: jmp    9b1 <generic_lsm_actions+0x9b1> */
	X86_SIM_X86_JMP(0x474, 0x9b1, x86_l_9b1);
x86_l_479:
	/* 0x479: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_47e:
	/* 0x47e: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_482:
	/* 0x482: je     5c2 <generic_lsm_actions+0x5c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x482, 0x5c2, x86_l_5c2);
x86_l_488:
	/* 0x488: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_48c:
	/* 0x48c: jne    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48c, 0x9d9, x86_l_9d9);
x86_l_492:
	/* 0x492: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_497:
	/* 0x497: lea    eax,[r12+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_49c:
	/* 0x49c: mov    r15d,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_4a1:
	/* 0x4a1: add    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_4a5:
	/* 0x4a5: mov    ebp,DWORD PTR [rcx+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_4aa:
	/* 0x4aa: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4bc:
	/* 0x4bc: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4c4:
	/* 0x4c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c9:
	/* 0x4c9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ce:
	/* 0x4ce: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_4d5:
	/* 0x4d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d7:
	/* 0x4d7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d9:
	/* 0x4d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4dc:
	/* 0x4dc: je     4ec <generic_lsm_actions+0x4ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4dc, 0x4ec, x86_l_4ec);
x86_l_4de:
	/* 0x4de: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4e2:
	/* 0x4e2: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4e6:
	/* 0x4e6: jbe    7e6 <generic_lsm_actions+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4e6, 0x7e6, x86_l_7e6);
x86_l_4ec:
	/* 0x4ec: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f1:
	/* 0x4f1: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4f6:
	/* 0x4f6: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb:
	/* 0x4fb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4fd:
	/* 0x4fd: jne    272 <generic_lsm_actions+0x272> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4fd, 0x272, x86_l_272);
x86_l_503:
	/* 0x503: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0x503, 0x9d9, x86_l_9d9);
x86_l_508:
	/* 0x508: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_50b:
	/* 0x50b: mov    eax,DWORD PTR [rcx+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_510:
	/* 0x510: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_513:
	/* 0x513: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_515:
	/* 0x515: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_518:
	/* 0x518: ja     a0b <generic_lsm_actions+0xa0b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x518, 0xa0b, x86_l_a0b);
x86_l_51e:
	/* 0x51e: cmp    DWORD PTR [r15+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_527:
	/* 0x527: jne    a0b <generic_lsm_actions+0xa0b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x527, 0xa0b, x86_l_a0b);
x86_l_52d:
	/* 0x52d: mov    rax,QWORD PTR [r15+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_535:
	/* 0x535: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_53a:
	/* 0x53a: mov    rax,QWORD PTR [r15+rax*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 184ULL);
x86_l_542:
	/* 0x542: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_547:
	/* 0x547: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54a:
	/* 0x54a: je     a0b <generic_lsm_actions+0xa0b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54a, 0xa0b, x86_l_a0b);
x86_l_550:
	/* 0x550: cmp    r14d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 10ULL);
x86_l_554:
	/* 0x554: jne    a15 <generic_lsm_actions+0xa15> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x554, 0xa15, x86_l_a15);
x86_l_55a:
	/* 0x55a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_55f:
	/* 0x55f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_561:
	/* 0x561: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_566:
	/* 0x566: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_56a:
	/* 0x56a: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_56e:
	/* 0x56e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_573:
	/* 0x573: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_57a:
	/* 0x57a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_57d:
	/* 0x57d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57f:
	/* 0x57f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_581:
	/* 0x581: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_584:
	/* 0x584: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_589:
	/* 0x589: je     a0b <generic_lsm_actions+0xa0b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x589, 0xa0b, x86_l_a0b);
x86_l_58f:
	/* 0x58f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_591:
	/* 0x591: mov    DWORD PTR [rsp+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_595:
	/* 0x595: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a:
	/* 0x59a: mov    DWORD PTR [rsp+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_59e:
	/* 0x59e: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a2:
	/* 0x5a2: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5a7:
	/* 0x5a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a9:
	/* 0x5a9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ae:
	/* 0x5ae: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b3:
	/* 0x5b3: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_5ba:
	/* 0x5ba: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5bd:
	/* 0x5bd: jmp    8de <generic_lsm_actions+0x8de> */
	X86_SIM_X86_JMP(0x5bd, 0x8de, x86_l_8de);
x86_l_5c2:
	/* 0x5c2: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_5c7:
	/* 0x5c7: cmp    BYTE PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5cf:
	/* 0x5cf: je     9b1 <generic_lsm_actions+0x9b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5cf, 0x9b1, x86_l_9b1);
x86_l_5d5:
	/* 0x5d5: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_5d8:
	/* 0x5d8: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_5dd:
	/* 0x5dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df:
	/* 0x5df: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5e4:
	/* 0x5e4: jmp    9b1 <generic_lsm_actions+0x9b1> */
	X86_SIM_X86_JMP(0x5e4, 0x9b1, x86_l_9b1);
x86_l_5e9:
	/* 0x5e9: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5ec:
	/* 0x5ec: mov    eax,DWORD PTR [rcx+r12*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 4ULL);
x86_l_5f1:
	/* 0x5f1: mov    DWORD PTR [r15+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5f5:
	/* 0x5f5: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0x5f5, 0x9d9, x86_l_9d9);
x86_l_5fa:
	/* 0x5fa: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_602:
	/* 0x602: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0x602, 0x9d9, x86_l_9d9);
x86_l_607:
	/* 0x607: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_60a:
	/* 0x60a: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_60f:
	/* 0x60f: cmp    BYTE PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_617:
	/* 0x617: je     9b1 <generic_lsm_actions+0x9b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x617, 0x9b1, x86_l_9b1);
x86_l_61d:
	/* 0x61d: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_622:
	/* 0x622: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_625:
	/* 0x625: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_629:
	/* 0x629: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_62d:
	/* 0x62d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_632:
	/* 0x632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_634:
	/* 0x634: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_639:
	/* 0x639: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63e:
	/* 0x63e: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_643:
	/* 0x643: mov    rbx,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_64a:
	/* 0x64a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_64d:
	/* 0x64d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_650:
	/* 0x650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652:
	/* 0x652: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_655:
	/* 0x655: je     954 <generic_lsm_actions+0x954> */
	X86_SIM_X86_JCC(X86_CC_E, 0x655, 0x954, x86_l_954);
x86_l_65b:
	/* 0x65b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_660:
	/* 0x660: mov    DWORD PTR [rsp+0x48],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309238562833ULL);
x86_l_668:
	/* 0x668: mov    QWORD PTR [rsp+0x4c],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 326417515359ULL);
x86_l_671:
	/* 0x671: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_676:
	/* 0x676: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_67b:
	/* 0x67b: mov    rbx,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_682:
	/* 0x682: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_685:
	/* 0x685: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68d:
	/* 0x68d: je     97b <generic_lsm_actions+0x97b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68d, 0x97b, x86_l_97b);
x86_l_693:
	/* 0x693: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_696:
	/* 0x696: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_698:
	/* 0x698: jmp    99c <generic_lsm_actions+0x99c> */
	X86_SIM_X86_JMP(0x698, 0x99c, x86_l_99c);
x86_l_69d:
	/* 0x69d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6a2:
	/* 0x6a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a4:
	/* 0x6a4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a9:
	/* 0x6a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ae:
	/* 0x6ae: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b3:
	/* 0x6b3: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_6ba:
	/* 0x6ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bc:
	/* 0x6bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6bf:
	/* 0x6bf: je     9d4 <generic_lsm_actions+0x9d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6bf, 0x9d4, x86_l_9d4);
x86_l_6c5:
	/* 0x6c5: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ca:
	/* 0x6ca: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d3:
	/* 0x6d3: mov    DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_6db:
	/* 0x6db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e0:
	/* 0x6e0: lea    rbx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e5:
	/* 0x6e5: mov    r15,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_6ec:
	/* 0x6ec: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6ef:
	/* 0x6ef: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_6f2:
	/* 0x6f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f4:
	/* 0x6f4: mov    DWORD PTR [rsp+0x44],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776129ULL);
x86_l_6fc:
	/* 0x6fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ff:
	/* 0x6ff: je     8e9 <generic_lsm_actions+0x8e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ff, 0x8e9, x86_l_8e9);
x86_l_705:
	/* 0x705: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_708:
	/* 0x708: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70d:
	/* 0x70d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_712:
	/* 0x712: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_717:
	/* 0x717: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_71e:
	/* 0x71e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_720:
	/* 0x720: jmp    9d4 <generic_lsm_actions+0x9d4> */
	X86_SIM_X86_JMP(0x720, 0x9d4, x86_l_9d4);
x86_l_725:
	/* 0x725: lea    eax,[r12+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_72a:
	/* 0x72a: mov    ebx,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_72e:
	/* 0x72e: lea    eax,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_733:
	/* 0x733: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_737:
	/* 0x737: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73b:
	/* 0x73b: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_740:
	/* 0x740: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_742:
	/* 0x742: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_747:
	/* 0x747: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_74f:
	/* 0x74f: mov    QWORD PTR [rsp+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_757:
	/* 0x757: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_75a:
	/* 0x75a: je     c24 <generic_lsm_actions+0xc24> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75a, 0xc24, x86_l_c24);
x86_l_760:
	/* 0x760: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_765:
	/* 0x765: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_76c:
	/* 0x76c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_771:
	/* 0x771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_773:
	/* 0x773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_776:
	/* 0x776: je     c24 <generic_lsm_actions+0xc24> */
	X86_SIM_X86_JCC(X86_CC_E, 0x776, 0xc24, x86_l_c24);
x86_l_77c:
	/* 0x77c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_781:
	/* 0x781: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_784:
	/* 0x784: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_789:
	/* 0x789: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_78e:
	/* 0x78e: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_795:
	/* 0x795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_797:
	/* 0x797: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_79a:
	/* 0x79a: mov    rax,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_79e:
	/* 0x79e: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a1:
	/* 0x7a1: mov    rax,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7a5:
	/* 0x7a5: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a9:
	/* 0x7a9: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_7ae:
	/* 0x7ae: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b2:
	/* 0x7b2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7b5:
	/* 0x7b5: je     a3e <generic_lsm_actions+0xa3e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b5, 0xa3e, x86_l_a3e);
x86_l_7bb:
	/* 0x7bb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7be:
	/* 0x7be: je     a3a <generic_lsm_actions+0xa3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7be, 0xa3a, x86_l_a3a);
x86_l_7c4:
	/* 0x7c4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7c6:
	/* 0x7c6: jne    c24 <generic_lsm_actions+0xc24> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7c6, 0xc24, x86_l_c24);
x86_l_7cc:
	/* 0x7cc: mov    eax,DWORD PTR [r15+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_7d0:
	/* 0x7d0: jmp    a3e <generic_lsm_actions+0xa3e> */
	X86_SIM_X86_JMP(0x7d0, 0xa3e, x86_l_a3e);
x86_l_7d5:
	/* 0x7d5: add    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_7d9:
	/* 0x7d9: mov    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7e1:
	/* 0x7e1: jmp    9b1 <generic_lsm_actions+0x9b1> */
	X86_SIM_X86_JMP(0x7e1, 0x9b1, x86_l_9b1);
x86_l_7e6:
	/* 0x7e6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7eb:
	/* 0x7eb: cmp    DWORD PTR [rcx+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_7f4:
	/* 0x7f4: je     813 <generic_lsm_actions+0x813> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f4, 0x813, x86_l_813);
x86_l_7f6:
	/* 0x7f6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fb:
	/* 0x7fb: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_800:
	/* 0x800: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_803:
	/* 0x803: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_806:
	/* 0x806: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_808:
	/* 0x808: jne    272 <generic_lsm_actions+0x272> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x808, 0x272, x86_l_272);
x86_l_80e:
	/* 0x80e: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0x80e, 0x9d9, x86_l_9d9);
x86_l_813:
	/* 0x813: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_818:
	/* 0x818: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_81b:
	/* 0x81b: mov    rax,QWORD PTR [rcx+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_823:
	/* 0x823: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_82b:
	/* 0x82b: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_830:
	/* 0x830: mov    eax,DWORD PTR [rcx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_837:
	/* 0x837: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_83b:
	/* 0x83b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_840:
	/* 0x840: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_842:
	/* 0x842: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_846:
	/* 0x846: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_84b:
	/* 0x84b: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_84f:
	/* 0x84f: jne    9e8 <generic_lsm_actions+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x84f, 0x9e8, x86_l_9e8);
x86_l_855:
	/* 0x855: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_858:
	/* 0x858: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_85d:
	/* 0x85d: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_860:
	/* 0x860: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_863:
	/* 0x863: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_868:
	/* 0x868: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_86d:
	/* 0x86d: ja     a01 <generic_lsm_actions+0xa01> */
	X86_SIM_X86_JCC(X86_CC_A, 0x86d, 0xa01, x86_l_a01);
x86_l_873:
	/* 0x873: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_878:
	/* 0x878: cmp    DWORD PTR [r15+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_881:
	/* 0x881: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_886:
	/* 0x886: jne    a0b <generic_lsm_actions+0xa0b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x886, 0xa0b, x86_l_a0b);
x86_l_88c:
	/* 0x88c: mov    rax,QWORD PTR [r15+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_894:
	/* 0x894: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_899:
	/* 0x899: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_89d:
	/* 0x89d: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_8a4:
	/* 0x8a4: mov    esi,DWORD PTR [r15+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_8ac:
	/* 0x8ac: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8b2:
	/* 0x8b2: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8b6:
	/* 0x8b6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8bb:
	/* 0x8bb: mov    QWORD PTR [rsp+0x90],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8c3:
	/* 0x8c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c5:
	/* 0x8c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c7:
	/* 0x8c7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8cc:
	/* 0x8cc: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_8d3:
	/* 0x8d3: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_8d6:
	/* 0x8d6: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8de:
	/* 0x8de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e0:
	/* 0x8e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e2:
	/* 0x8e2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e4:
	/* 0x8e4: jmp    a2b <generic_lsm_actions+0xa2b> */
	X86_SIM_X86_JMP(0x8e4, 0xa2b, x86_l_a2b);
x86_l_8e9:
	/* 0x8e9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ee:
	/* 0x8ee: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8f3:
	/* 0x8f3: lea    rdx,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_8f8:
	/* 0x8f8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_8fb:
	/* 0x8fb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_8fe:
	/* 0x8fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_900:
	/* 0x900: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_903:
	/* 0x903: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_908:
	/* 0x908: je     70d <generic_lsm_actions+0x70d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x908, 0x70d, x86_l_70d);
x86_l_90e:
	/* 0x90e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_913:
	/* 0x913: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_915:
	/* 0x915: mov    WORD PTR [rsp+0x48],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_91a:
	/* 0x91a: mov    WORD PTR [rsp+0x4a],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 317827579907ULL);
x86_l_921:
	/* 0x921: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_92b:
	/* 0x92b: mov    QWORD PTR [rsp+0x4c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_930:
	/* 0x930: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_935:
	/* 0x935: mov    rbx,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_93c:
	/* 0x93c: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_93f:
	/* 0x93f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_942:
	/* 0x942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_944:
	/* 0x944: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_947:
	/* 0x947: je     cb7 <generic_lsm_actions+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x947, 0xcb7, x86_l_cb7);
x86_l_94d:
	/* 0x94d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_94f:
	/* 0x94f: jmp    cd7 <generic_lsm_actions+0xcd7> */
	X86_SIM_X86_JMP(0x94f, 0xcd7, x86_l_cd7);
x86_l_954:
	/* 0x954: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_959:
	/* 0x959: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_95b:
	/* 0x95b: lea    rdx,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_960:
	/* 0x960: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_963:
	/* 0x963: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_966:
	/* 0x966: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_968:
	/* 0x968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96a:
	/* 0x96a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_96f:
	/* 0x96f: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_974:
	/* 0x974: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_979:
	/* 0x979: jmp    9b1 <generic_lsm_actions+0x9b1> */
	X86_SIM_X86_JMP(0x979, 0x9b1, x86_l_9b1);
x86_l_97b:
	/* 0x97b: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_983:
	/* 0x983: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_988:
	/* 0x988: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_98a:
	/* 0x98a: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98f:
	/* 0x98f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_992:
	/* 0x992: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_995:
	/* 0x995: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_998:
	/* 0x998: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99a:
	/* 0x99a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99c:
	/* 0x99c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a1:
	/* 0x9a1: mov    eax,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_9a5:
	/* 0x9a5: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9aa:
	/* 0x9aa: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ac:
	/* 0x9ac: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_9b1:
	/* 0x9b1: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_9b9:
	/* 0x9b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9be:
	/* 0x9be: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_9c5:
	/* 0x9c5: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_9c8:
	/* 0x9c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ca:
	/* 0x9ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9cd:
	/* 0x9cd: je     9d4 <generic_lsm_actions+0x9d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9cd, 0x9d4, x86_l_9d4);
x86_l_9cf:
	/* 0x9cf: inc QWORD PTR [rax+rbx*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RBX, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9d4:
	/* 0x9d4: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d9:
	/* 0x9d9: mov    QWORD PTR [r15+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9dd:
	/* 0x9dd: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9e0:
	/* 0x9e0: mov    ebx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_32);
x86_l_9e3:
	/* 0x9e3: jmp    272 <generic_lsm_actions+0x272> */
	X86_SIM_X86_JMP(0x9e3, 0x272, x86_l_272);
x86_l_9e8:
	/* 0x9e8: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_9ed:
	/* 0x9ed: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9f2:
	/* 0x9f2: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9f9:
	/* 0x9f9: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_9fc:
	/* 0x9fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fe:
	/* 0x9fe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a06:
	/* 0xa06: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0b:
	/* 0xa0b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_a0d:
	/* 0xa0d: jne    272 <generic_lsm_actions+0x272> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa0d, 0x272, x86_l_272);
x86_l_a13:
	/* 0xa13: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0xa13, 0x9d9, x86_l_9d9);
x86_l_a15:
	/* 0xa15: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a1a:
	/* 0xa1a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a1f:
	/* 0xa1f: mov    rdi,QWORD PTR [rip+0x225d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_a26:
	/* 0xa26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a28:
	/* 0xa28: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a2b:
	/* 0xa2b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a30:
	/* 0xa30: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_a32:
	/* 0xa32: jne    272 <generic_lsm_actions+0x272> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa32, 0x272, x86_l_272);
x86_l_a38:
	/* 0xa38: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0xa38, 0x9d9, x86_l_9d9);
x86_l_a3a:
	/* 0xa3a: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a3e:
	/* 0xa3e: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a43:
	/* 0xa43: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a45:
	/* 0xa45: mov    QWORD PTR [rsp+0xd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a51:
	/* 0xa51: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a56:
	/* 0xa56: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a5a:
	/* 0xa5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a5f:
	/* 0xa5f: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a69:
	/* 0xa69: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_a6e:
	/* 0xa6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a70:
	/* 0xa70: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a73:
	/* 0xa73: lea    rbx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a78:
	/* 0xa78: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a7a:
	/* 0xa7a: jmp    a8f <generic_lsm_actions+0xa8f> */
	X86_SIM_X86_JMP(0xa7a, 0xa8f, x86_l_a8f);
x86_l_a7c:
	/* 0xa7c: lea    rbx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a81:
	/* 0xa81: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a85:
	/* 0xa85: cmp    r15,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 20ULL);
x86_l_a89:
	/* 0xa89: je     bbf <generic_lsm_actions+0xbbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa89, 0xbbf, x86_l_bbf);
x86_l_a8f:
	/* 0xa8f: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a97:
	/* 0xa97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9c:
	/* 0xa9c: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_aa3:
	/* 0xaa3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_aa6:
	/* 0xaa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa8:
	/* 0xaa8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aab:
	/* 0xaab: je     bbf <generic_lsm_actions+0xbbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaab, 0xbbf, x86_l_bbf);
x86_l_ab1:
	/* 0xab1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ab4:
	/* 0xab4: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_abb:
	/* 0xabb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac0:
	/* 0xac0: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_ac7:
	/* 0xac7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac9:
	/* 0xac9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_acc:
	/* 0xacc: je     bbf <generic_lsm_actions+0xbbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xacc, 0xbbf, x86_l_bbf);
x86_l_ad2:
	/* 0xad2: cmp    DWORD PTR [rax+r15*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 279172874239ULL);
x86_l_ad8:
	/* 0xad8: je     bbf <generic_lsm_actions+0xbbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad8, 0xbbf, x86_l_bbf);
x86_l_ade:
	/* 0xade: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae3:
	/* 0xae3: mov    rax,QWORD PTR [rcx+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_aeb:
	/* 0xaeb: mov    ecx,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aee:
	/* 0xaee: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_af1:
	/* 0xaf1: jge    bbf <generic_lsm_actions+0xbbf> */
	X86_SIM_X86_JCC(X86_CC_GE, 0xaf1, 0xbbf, x86_l_bbf);
x86_l_af7:
	/* 0xaf7: cmp    r15,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 16ULL);
x86_l_afb:
	/* 0xafb: je     b66 <generic_lsm_actions+0xb66> */
	X86_SIM_X86_JCC(X86_CC_E, 0xafb, 0xb66, x86_l_b66);
x86_l_afd:
	/* 0xafd: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_b05:
	/* 0xb05: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b0a:
	/* 0xb0a: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_b11:
	/* 0xb11: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_b14:
	/* 0xb14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b16:
	/* 0xb16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b19:
	/* 0xb19: je     b59 <generic_lsm_actions+0xb59> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb19, 0xb59, x86_l_b59);
x86_l_b1b:
	/* 0xb1b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_b25:
	/* 0xb25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_b31:
	/* 0xb31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b33:
	/* 0xb33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b36:
	/* 0xb36: je     b59 <generic_lsm_actions+0xb59> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb36, 0xb59, x86_l_b59);
x86_l_b38:
	/* 0xb38: cmp    DWORD PTR [rax+r15*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 296352743423ULL);
x86_l_b3e:
	/* 0xb3e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b43:
	/* 0xb43: mov    rax,QWORD PTR [rcx+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_b4b:
	/* 0xb4b: je     b66 <generic_lsm_actions+0xb66> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb4b, 0xb66, x86_l_b66);
x86_l_b4d:
	/* 0xb4d: mov    ebx,DWORD PTR [rcx+r15*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 1), 24192ULL);
x86_l_b55:
	/* 0xb55: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b57:
	/* 0xb57: jmp    b73 <generic_lsm_actions+0xb73> */
	X86_SIM_X86_JMP(0xb57, 0xb73, x86_l_b73);
x86_l_b59:
	/* 0xb59: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b5e:
	/* 0xb5e: mov    rax,QWORD PTR [rax+r15*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 1), 24184ULL);
x86_l_b66:
	/* 0xb66: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6b:
	/* 0xb6b: mov    ebx,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b6e:
	/* 0xb6e: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b70:
	/* 0xb70: add    ebx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b73:
	/* 0xb73: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_b75:
	/* 0xb75: jle    a7c <generic_lsm_actions+0xa7c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb75, 0xa7c, x86_l_a7c);
x86_l_b7b:
	/* 0xb7b: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_b80:
	/* 0xb80: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_b85:
	/* 0xb85: cmp    ebx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 40ULL);
x86_l_b88:
	/* 0xb88: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_b8d:
	/* 0xb8d: cmovge ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_b90:
	/* 0xb90: movzx  ebp,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b94:
	/* 0xb94: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b99:
	/* 0xb99: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b9d:
	/* 0xb9d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba2:
	/* 0xba2: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ba6:
	/* 0xba6: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_bad:
	/* 0xbad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bb2:
	/* 0xbb2: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_bb4:
	/* 0xbb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb6:
	/* 0xbb6: add    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bb8:
	/* 0xbb8: mov    ebp,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_32);
x86_l_bba:
	/* 0xbba: jmp    a7c <generic_lsm_actions+0xa7c> */
	X86_SIM_X86_JMP(0xbba, 0xa7c, x86_l_a7c);
x86_l_bbf:
	/* 0xbbf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bc4:
	/* 0xbc4: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_bcb:
	/* 0xbcb: mov    rbx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_bd3:
	/* 0xbd3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_bd6:
	/* 0xbd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd8:
	/* 0xbd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bdb:
	/* 0xbdb: je     c02 <generic_lsm_actions+0xc02> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbdb, 0xc02, x86_l_c02);
x86_l_bdd:
	/* 0xbdd: imul   rcx,QWORD PTR [rsp+0x90],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 618474290624ULL);
x86_l_be9:
	/* 0xbe9: add    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_bee:
	/* 0xbee: cmp    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf1:
	/* 0xbf1: jbe    c02 <generic_lsm_actions+0xc02> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xbf1, 0xc02, x86_l_c02);
x86_l_bf3:
	/* 0xbf3: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_bfb:
	/* 0xbfb: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c00:
	/* 0xc00: jmp    c1f <generic_lsm_actions+0xc1f> */
	X86_SIM_X86_JMP(0xc00, 0xc1f, x86_l_c1f);
x86_l_c02:
	/* 0xc02: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c07:
	/* 0xc07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c09:
	/* 0xc09: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_c10:
	/* 0xc10: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c15:
	/* 0xc15: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_c18:
	/* 0xc18: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_c1b:
	/* 0xc1b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c1d:
	/* 0xc1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1f:
	/* 0xc1f: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c24:
	/* 0xc24: lea    eax,[r12+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_c29:
	/* 0xc29: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c2e:
	/* 0xc2e: cmp    DWORD PTR [rcx+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_c33:
	/* 0xc33: je     c60 <generic_lsm_actions+0xc60> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc33, 0xc60, x86_l_c60);
x86_l_c35:
	/* 0xc35: or     BYTE PTR [r15+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_c3a:
	/* 0xc3a: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c3f:
	/* 0xc3f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c41:
	/* 0xc41: mov    rsi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c48:
	/* 0xc48: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c50:
	/* 0xc50: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c52:
	/* 0xc52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c54:
	/* 0xc54: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c59:
	/* 0xc59: mov    QWORD PTR [r15+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c60:
	/* 0xc60: lea    eax,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c65:
	/* 0xc65: cmp    DWORD PTR [rcx+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_c6a:
	/* 0xc6a: je     c9d <generic_lsm_actions+0xc9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc6a, 0xc9d, x86_l_c9d);
x86_l_c6c:
	/* 0xc6c: or     BYTE PTR [r15+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c71:
	/* 0xc71: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c76:
	/* 0xc76: mov    rsi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c7d:
	/* 0xc7d: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_c82:
	/* 0xc82: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c8a:
	/* 0xc8a: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c8f:
	/* 0xc8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c91:
	/* 0xc91: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c96:
	/* 0xc96: mov    QWORD PTR [r15+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c9d:
	/* 0xc9d: add    r12d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_ca1:
	/* 0xca1: cmp    DWORD PTR [rcx+r12*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 17179869184ULL);
x86_l_ca7:
	/* 0xca7: je     9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca7, 0x9d9, x86_l_9d9);
x86_l_cad:
	/* 0xcad: or     BYTE PTR [r15+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_cb2:
	/* 0xcb2: jmp    9d9 <generic_lsm_actions+0x9d9> */
	X86_SIM_X86_JMP(0xcb2, 0x9d9, x86_l_9d9);
x86_l_cb7:
	/* 0xcb7: mov    DWORD PTR [rsp+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_cbf:
	/* 0xcbf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cc4:
	/* 0xcc4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc6:
	/* 0xcc6: lea    rdx,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_ccb:
	/* 0xccb: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cd0:
	/* 0xcd0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cd3:
	/* 0xcd3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd5:
	/* 0xcd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd7:
	/* 0xcd7: cmp    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_cdc:
	/* 0xcdc: je     70d <generic_lsm_actions+0x70d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcdc, 0x70d, x86_l_70d);
x86_l_ce2:
	/* 0xce2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce7:
	/* 0xce7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cec:
	/* 0xcec: mov    rdi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_cf3:
	/* 0xcf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf5:
	/* 0xcf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf8:
	/* 0xcf8: je     70d <generic_lsm_actions+0x70d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf8, 0x70d, x86_l_70d);
x86_l_cfe:
	/* 0xcfe: mov    ecx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_d02:
	/* 0xd02: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d05:
	/* 0xd05: jmp    70d <generic_lsm_actions+0x70d> */
	X86_SIM_X86_JMP(0xd05, 0x70d, x86_l_70d);
x86_l_d0a:
	/* 0xd0a: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d0e:
	/* 0xd0e: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_d11:
	/* 0xd11: je     d33 <generic_lsm_actions+0xd33> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd11, 0xd33, x86_l_d33);
x86_l_d13:
	/* 0xd13: mov    rsi,QWORD PTR [rip+0x225e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&lsm_calls)));
x86_l_d1a:
	/* 0xd1a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d1f:
	/* 0xd1f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d24:
	/* 0xd24: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d2c:
	/* 0xd2c: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d31:
	/* 0xd31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d33:
	/* 0xd33: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d35:
	/* 0xd35: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_d38:
	/* 0xd38: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_d3b:
	/* 0xd3b: jmp    e5 <generic_lsm_actions+0xe5> */
	X86_SIM_X86_JMP(0xd3b, 0xe5, x86_l_e5);
x86_l_d40:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
