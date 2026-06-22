extern char config_map;
extern char enforcer_data;
extern char enforcer_missed_notifications;
extern char execve_map;
extern char fdinstall_map;
extern char filter_map;
extern char heap;
extern char heap_ro_zero;
extern char kprobe_calls;
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
int tetragon_bpf_generic_kprobe_v511_generic_kprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0x88],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_19:
	/* 0x19: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_24:
	/* 0x24: mov    rdi,QWORD PTR [rip+0x22920] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2b:
	/* 0x2b: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_33:
	/* 0x33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: je     dac <generic_kprobe_actions+0xdac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d, 0xdac, x86_l_dac);
x86_l_43:
	/* 0x43: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: mov    ebx,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_4c:
	/* 0x4c: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_4f:
	/* 0x4f: jl     dac <generic_kprobe_actions+0xdac> */
	X86_SIM_X86_JCC(X86_CC_L, 0x4f, 0xdac, x86_l_dac);
x86_l_55:
	/* 0x55: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x22920] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_63:
	/* 0x63: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68:
	/* 0x68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a:
	/* 0x6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: je     dac <generic_kprobe_actions+0xdac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d, 0xdac, x86_l_dac);
x86_l_73:
	/* 0x73: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_78:
	/* 0x78: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7d:
	/* 0x7d: add    ebx,DWORD PTR [r14+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_81:
	/* 0x81: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_8c:
	/* 0x8c: mov    rdi,QWORD PTR [rip+0x22920] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_93:
	/* 0x93: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9b:
	/* 0x9b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a0:
	/* 0xa0: and    ebx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_a6:
	/* 0xa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8:
	/* 0xa8: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_aa:
	/* 0xaa: mov    DWORD PTR [rsp+0x5c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_ae:
	/* 0xae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1:
	/* 0xb1: je     ce <generic_kprobe_actions+0xce> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1, 0xce, x86_l_ce);
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
	/* 0xbb: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c0:
	/* 0xc0: xor    rcx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_c4:
	/* 0xc4: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_cc:
	/* 0xcc: jmp    e2 <generic_kprobe_actions+0xe2> */
	X86_SIM_X86_JMP(0xcc, 0xe2, x86_l_e2);
x86_l_ce:
	/* 0xce: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_d3:
	/* 0xd3: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_db:
	/* 0xdb: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_dd:
	/* 0xdd: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e2:
	/* 0xe2: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e5:
	/* 0xe5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8:
	/* 0xe8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb:
	/* 0xeb: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f0:
	/* 0xf0: jmp    117 <generic_kprobe_actions+0x117> */
	X86_SIM_X86_JMP(0xf0, 0x117, x86_l_117);
x86_l_f2:
	/* 0xf2: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f5:
	/* 0xf5: mov    eax,DWORD PTR [r14+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rdx+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_fd:
	/* 0xfd: mov    QWORD PTR [rdx+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_101:
	/* 0x101: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_104:
	/* 0x104: mov    ebx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_32);
x86_l_107:
	/* 0x107: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10a:
	/* 0x10a: mov    r15d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_32);
x86_l_10d:
	/* 0x10d: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_111:
	/* 0x111: je     d85 <generic_kprobe_actions+0xd85> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111, 0xd85, x86_l_d85);
x86_l_117:
	/* 0x117: lea    eax,[r15*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_11f:
	/* 0x11f: cmp    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_122:
	/* 0x122: jae    d85 <generic_kprobe_actions+0xd85> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x122, 0xd85, x86_l_d85);
x86_l_128:
	/* 0x128: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_12b:
	/* 0x12b: movsxd r12,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_130:
	/* 0x130: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_13b:
	/* 0x13b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140:
	/* 0x140: mov    rdi,QWORD PTR [rip+0x22923] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_147:
	/* 0x147: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_14f:
	/* 0x14f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151:
	/* 0x151: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153:
	/* 0x153: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_156:
	/* 0x156: je     107 <generic_kprobe_actions+0x107> */
	X86_SIM_X86_JCC(X86_CC_E, 0x156, 0x107, x86_l_107);
x86_l_158:
	/* 0x158: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15b:
	/* 0x15b: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_15f:
	/* 0x15f: jg     189 <generic_kprobe_actions+0x189> */
	X86_SIM_X86_JCC(X86_CC_G, 0x15f, 0x189, x86_l_189);
x86_l_161:
	/* 0x161: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_165:
	/* 0x165: jg     1c7 <generic_kprobe_actions+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x165, 0x1c7, x86_l_1c7);
x86_l_167:
	/* 0x167: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_16b:
	/* 0x16b: jg     315 <generic_kprobe_actions+0x315> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16b, 0x315, x86_l_315);
x86_l_171:
	/* 0x171: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_174:
	/* 0x174: je     58e <generic_kprobe_actions+0x58e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x174, 0x58e, x86_l_58e);
x86_l_17a:
	/* 0x17a: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_17e:
	/* 0x17e: je     32e <generic_kprobe_actions+0x32e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17e, 0x32e, x86_l_32e);
x86_l_184:
	/* 0x184: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x184, 0xfd, x86_l_fd);
x86_l_189:
	/* 0x189: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_18d:
	/* 0x18d: jg     2e1 <generic_kprobe_actions+0x2e1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x18d, 0x2e1, x86_l_2e1);
x86_l_193:
	/* 0x193: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_198:
	/* 0x198: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19b:
	/* 0x19b: jb     3b1 <generic_kprobe_actions+0x3b1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x19b, 0x3b1, x86_l_3b1);
x86_l_1a1:
	/* 0x1a1: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1a5:
	/* 0x1a5: je     46f <generic_kprobe_actions+0x46f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a5, 0x46f, x86_l_46f);
x86_l_1ab:
	/* 0x1ab: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1af:
	/* 0x1af: jne    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1af, 0xfd, x86_l_fd);
x86_l_1b5:
	/* 0x1b5: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ba:
	/* 0x1ba: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1bd:
	/* 0x1bd: mov    eax,DWORD PTR [r14+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_1c2:
	/* 0x1c2: jmp    651 <generic_kprobe_actions+0x651> */
	X86_SIM_X86_JMP(0x1c2, 0x651, x86_l_651);
x86_l_1c7:
	/* 0x1c7: lea    eax,[r12-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1cc:
	/* 0x1cc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cf:
	/* 0x1cf: jb     f2 <generic_kprobe_actions+0xf2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1cf, 0xf2, x86_l_f2);
x86_l_1d5:
	/* 0x1d5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1d9:
	/* 0x1d9: je     47c <generic_kprobe_actions+0x47c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d9, 0x47c, x86_l_47c);
x86_l_1df:
	/* 0x1df: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_1e3:
	/* 0x1e3: jne    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e3, 0xfd, x86_l_fd);
x86_l_1e9:
	/* 0x1e9: lea    eax,[r15+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1ed:
	/* 0x1ed: mov    eax,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_1f2:
	/* 0x1f2: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1f6:
	/* 0x1f6: mov    ebx,DWORD PTR [r14+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_1fb:
	/* 0x1fb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_204:
	/* 0x204: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_20d:
	/* 0x20d: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_210:
	/* 0x210: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_213:
	/* 0x213: ja     fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x213, 0xfd, x86_l_fd);
x86_l_219:
	/* 0x219: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_221:
	/* 0x221: jne    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x221, 0xfd, x86_l_fd);
x86_l_227:
	/* 0x227: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_22f:
	/* 0x22f: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_234:
	/* 0x234: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_23b:
	/* 0x23b: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f:
	/* 0x23f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_244:
	/* 0x244: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_24d:
	/* 0x24d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_252:
	/* 0x252: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_257:
	/* 0x257: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c:
	/* 0x25c: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_263:
	/* 0x263: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265:
	/* 0x265: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_268:
	/* 0x268: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b:
	/* 0x26b: je     fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26b, 0xfd, x86_l_fd);
x86_l_271:
	/* 0x271: and    ebx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_274:
	/* 0x274: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_277:
	/* 0x277: ja     fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x277, 0xfd, x86_l_fd);
x86_l_27d:
	/* 0x27d: cmp    DWORD PTR [rdx+rbx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 104041287778304ULL);
x86_l_285:
	/* 0x285: jne    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x285, 0xfd, x86_l_fd);
x86_l_28b:
	/* 0x28b: mov    rcx,QWORD PTR [rdx+rbx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 24184ULL);
x86_l_293:
	/* 0x293: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_29b:
	/* 0x29b: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2a1:
	/* 0x2a1: mov    ecx,DWORD PTR [rdx+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_2a8:
	/* 0x2a8: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ac:
	/* 0x2ac: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2af:
	/* 0x2af: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2b4:
	/* 0x2b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6:
	/* 0x2b6: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2ba:
	/* 0x2ba: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf:
	/* 0x2bf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c4:
	/* 0x2c4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c6:
	/* 0x2c6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cb:
	/* 0x2cb: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2d2:
	/* 0x2d2: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2d5:
	/* 0x2d5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7:
	/* 0x2d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9:
	/* 0x2d9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2dc:
	/* 0x2dc: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x2dc, 0xfd, x86_l_fd);
x86_l_2e1:
	/* 0x2e1: cmp    r12d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 12ULL);
x86_l_2e5:
	/* 0x2e5: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ea:
	/* 0x2ea: je     685 <generic_kprobe_actions+0x685> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ea, 0x685, x86_l_685);
x86_l_2f0:
	/* 0x2f0: cmp    r12d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 13ULL);
x86_l_2f4:
	/* 0x2f4: je     510 <generic_kprobe_actions+0x510> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f4, 0x510, x86_l_510);
x86_l_2fa:
	/* 0x2fa: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_2fe:
	/* 0x2fe: jne    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2fe, 0xfd, x86_l_fd);
x86_l_304:
	/* 0x304: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_308:
	/* 0x308: mov    r14,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_310:
	/* 0x310: jmp    956 <generic_kprobe_actions+0x956> */
	X86_SIM_X86_JMP(0x310, 0x956, x86_l_956);
x86_l_315:
	/* 0x315: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_31a:
	/* 0x31a: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_31e:
	/* 0x31e: je     64c <generic_kprobe_actions+0x64c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31e, 0x64c, x86_l_64c);
x86_l_324:
	/* 0x324: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_328:
	/* 0x328: jne    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x328, 0xfd, x86_l_fd);
x86_l_32e:
	/* 0x32e: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_331:
	/* 0x331: lea    eax,[r15+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_335:
	/* 0x335: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_338:
	/* 0x338: mov    r14d,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_33d:
	/* 0x33d: add    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_341:
	/* 0x341: mov    eax,DWORD PTR [rcx+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_346:
	/* 0x346: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_34b:
	/* 0x34b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_354:
	/* 0x354: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_35d:
	/* 0x35d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_365:
	/* 0x365: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36a:
	/* 0x36a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36f:
	/* 0x36f: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_376:
	/* 0x376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378:
	/* 0x378: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37a:
	/* 0x37a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37d:
	/* 0x37d: je     9a6 <generic_kprobe_actions+0x9a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37d, 0x9a6, x86_l_9a6);
x86_l_383:
	/* 0x383: and    r14d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_387:
	/* 0x387: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_38b:
	/* 0x38b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_38e:
	/* 0x38e: ja     39f <generic_kprobe_actions+0x39f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x38e, 0x39f, x86_l_39f);
x86_l_390:
	/* 0x390: cmp    DWORD PTR [rdx+r14*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 104041287778304ULL);
x86_l_399:
	/* 0x399: je     774 <generic_kprobe_actions+0x774> */
	X86_SIM_X86_JCC(X86_CC_E, 0x399, 0x774, x86_l_774);
x86_l_39f:
	/* 0x39f: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a4:
	/* 0x3a4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3a6:
	/* 0x3a6: jne    107 <generic_kprobe_actions+0x107> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a6, 0x107, x86_l_107);
x86_l_3ac:
	/* 0x3ac: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x3ac, 0xfd, x86_l_fd);
x86_l_3b1:
	/* 0x3b1: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3b4:
	/* 0x3b4: mov    eax,DWORD PTR [r14+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_3b9:
	/* 0x3b9: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3bc:
	/* 0x3bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3be:
	/* 0x3be: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c1:
	/* 0x3c1: ja     9ae <generic_kprobe_actions+0x9ae> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c1, 0x9ae, x86_l_9ae);
x86_l_3c7:
	/* 0x3c7: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_3cf:
	/* 0x3cf: jne    9ae <generic_kprobe_actions+0x9ae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3cf, 0x9ae, x86_l_9ae);
x86_l_3d5:
	/* 0x3d5: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_3dd:
	/* 0x3dd: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3e2:
	/* 0x3e2: mov    rax,QWORD PTR [rdx+rax*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 184ULL);
x86_l_3ea:
	/* 0x3ea: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ef:
	/* 0x3ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f2:
	/* 0x3f2: je     9ae <generic_kprobe_actions+0x9ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f2, 0x9ae, x86_l_9ae);
x86_l_3f8:
	/* 0x3f8: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_3fb:
	/* 0x3fb: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_3ff:
	/* 0x3ff: jne    9bb <generic_kprobe_actions+0x9bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ff, 0x9bb, x86_l_9bb);
x86_l_405:
	/* 0x405: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_40a:
	/* 0x40a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40c:
	/* 0x40c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_411:
	/* 0x411: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_415:
	/* 0x415: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_419:
	/* 0x419: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41e:
	/* 0x41e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_423:
	/* 0x423: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_42a:
	/* 0x42a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42c:
	/* 0x42c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_42e:
	/* 0x42e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_431:
	/* 0x431: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_434:
	/* 0x434: je     9ae <generic_kprobe_actions+0x9ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x434, 0x9ae, x86_l_9ae);
x86_l_43a:
	/* 0x43a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43c:
	/* 0x43c: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_440:
	/* 0x440: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_445:
	/* 0x445: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_449:
	/* 0x449: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_452:
	/* 0x452: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_454:
	/* 0x454: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_459:
	/* 0x459: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45e:
	/* 0x45e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_463:
	/* 0x463: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_46a:
	/* 0x46a: jmp    82b <generic_kprobe_actions+0x82b> */
	X86_SIM_X86_JMP(0x46a, 0x82b, x86_l_82b);
x86_l_46f:
	/* 0x46f: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_477:
	/* 0x477: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x477, 0xfd, x86_l_fd);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_481:
	/* 0x481: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_484:
	/* 0x484: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_48a:
	/* 0x48a: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_48f:
	/* 0x48f: je     956 <generic_kprobe_actions+0x956> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48f, 0x956, x86_l_956);
x86_l_495:
	/* 0x495: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_498:
	/* 0x498: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49d:
	/* 0x49d: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_4a1:
	/* 0x4a1: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4a5:
	/* 0x4a5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4aa:
	/* 0x4aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac:
	/* 0x4ac: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b1:
	/* 0x4b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b6:
	/* 0x4b6: lea    r14,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4bb:
	/* 0x4bb: mov    rbp,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_4c2:
	/* 0x4c2: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4cd:
	/* 0x4cd: je     8a7 <generic_kprobe_actions+0x8a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cd, 0x8a7, x86_l_8a7);
x86_l_4d3:
	/* 0x4d3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4d6:
	/* 0x4d6: mov    DWORD PTR [rsp+0x8],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360655889ULL);
x86_l_4de:
	/* 0x4de: mov    QWORD PTR [rsp+0xc],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539608415ULL);
x86_l_4e7:
	/* 0x4e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ec:
	/* 0x4ec: lea    r14,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f1:
	/* 0x4f1: mov    rbp,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_4f8:
	/* 0x4f8: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_4fb:
	/* 0x4fb: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4fe:
	/* 0x4fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_500:
	/* 0x500: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_503:
	/* 0x503: je     92c <generic_kprobe_actions+0x92c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x503, 0x92c, x86_l_92c);
x86_l_509:
	/* 0x509: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_50b:
	/* 0x50b: jmp    94a <generic_kprobe_actions+0x94a> */
	X86_SIM_X86_JMP(0x50b, 0x94a, x86_l_94a);
x86_l_510:
	/* 0x510: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_515:
	/* 0x515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_517:
	/* 0x517: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_51c:
	/* 0x51c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_521:
	/* 0x521: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_526:
	/* 0x526: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_52d:
	/* 0x52d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f:
	/* 0x52f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_532:
	/* 0x532: je     986 <generic_kprobe_actions+0x986> */
	X86_SIM_X86_JCC(X86_CC_E, 0x532, 0x986, x86_l_986);
x86_l_538:
	/* 0x538: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_541:
	/* 0x541: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_549:
	/* 0x549: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54e:
	/* 0x54e: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_553:
	/* 0x553: mov    rbp,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_55a:
	/* 0x55a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_55d:
	/* 0x55d: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_560:
	/* 0x560: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_562:
	/* 0x562: mov    DWORD PTR [rsp+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_56a:
	/* 0x56a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_56d:
	/* 0x56d: je     841 <generic_kprobe_actions+0x841> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56d, 0x841, x86_l_841);
x86_l_573:
	/* 0x573: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_576:
	/* 0x576: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_57b:
	/* 0x57b: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_580:
	/* 0x580: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_587:
	/* 0x587: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_589:
	/* 0x589: jmp    986 <generic_kprobe_actions+0x986> */
	X86_SIM_X86_JMP(0x589, 0x986, x86_l_986);
x86_l_58e:
	/* 0x58e: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_593:
	/* 0x593: lea    eax,[r15+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_597:
	/* 0x597: mov    ebp,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_59c:
	/* 0x59c: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_5a0:
	/* 0x5a0: mov    ebx,DWORD PTR [r14+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_5a5:
	/* 0x5a5: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_5aa:
	/* 0x5aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b1:
	/* 0x5b1: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5b9:
	/* 0x5b9: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5be:
	/* 0x5be: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_5c1:
	/* 0x5c1: je     c0c <generic_kprobe_actions+0xc0c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c1, 0xc0c, x86_l_c0c);
x86_l_5c7:
	/* 0x5c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cc:
	/* 0x5cc: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_5d3:
	/* 0x5d3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d8:
	/* 0x5d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5da:
	/* 0x5da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5dd:
	/* 0x5dd: je     c0c <generic_kprobe_actions+0xc0c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5dd, 0xc0c, x86_l_c0c);
x86_l_5e3:
	/* 0x5e3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5e8:
	/* 0x5e8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5eb:
	/* 0x5eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f0:
	/* 0x5f0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5f5:
	/* 0x5f5: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5fc:
	/* 0x5fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe:
	/* 0x5fe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_601:
	/* 0x601: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_606:
	/* 0x606: mov    rax,QWORD PTR [rcx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_60a:
	/* 0x60a: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60e:
	/* 0x60e: mov    rax,QWORD PTR [rcx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [rsp+0x80],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61e:
	/* 0x61e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_620:
	/* 0x620: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_625:
	/* 0x625: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_628:
	/* 0x628: je     a47 <generic_kprobe_actions+0xa47> */
	X86_SIM_X86_JCC(X86_CC_E, 0x628, 0xa47, x86_l_a47);
x86_l_62e:
	/* 0x62e: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_631:
	/* 0x631: je     a44 <generic_kprobe_actions+0xa44> */
	X86_SIM_X86_JCC(X86_CC_E, 0x631, 0xa44, x86_l_a44);
x86_l_637:
	/* 0x637: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_639:
	/* 0x639: jne    c0c <generic_kprobe_actions+0xc0c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x639, 0xc0c, x86_l_c0c);
x86_l_63f:
	/* 0x63f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_644:
	/* 0x644: mov    eax,DWORD PTR [rax+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_647:
	/* 0x647: jmp    a47 <generic_kprobe_actions+0xa47> */
	X86_SIM_X86_JMP(0x647, 0xa47, x86_l_a47);
x86_l_64c:
	/* 0x64c: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_651:
	/* 0x651: mov    ebx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_32);
x86_l_654:
	/* 0x654: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_65a:
	/* 0x65a: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_65f:
	/* 0x65f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_664:
	/* 0x664: je     95e <generic_kprobe_actions+0x95e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x664, 0x95e, x86_l_95e);
x86_l_66a:
	/* 0x66a: movsxd rdi,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_66d:
	/* 0x66d: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_672:
	/* 0x672: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_675:
	/* 0x675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_677:
	/* 0x677: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_67a:
	/* 0x67a: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_680:
	/* 0x680: jmp    95e <generic_kprobe_actions+0x95e> */
	X86_SIM_X86_JMP(0x680, 0x95e, x86_l_95e);
x86_l_685:
	/* 0x685: lea    ebx,[r15+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_689:
	/* 0x689: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_68f:
	/* 0x68f: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_694:
	/* 0x694: je     959 <generic_kprobe_actions+0x959> */
	X86_SIM_X86_JCC(X86_CC_E, 0x694, 0x959, x86_l_959);
x86_l_69a:
	/* 0x69a: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_69c:
	/* 0x69c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6a5:
	/* 0x6a5: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_6a9:
	/* 0x6a9: ja     6b9 <generic_kprobe_actions+0x6b9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6a9, 0x6b9, x86_l_6b9);
x86_l_6ab:
	/* 0x6ab: cmp    DWORD PTR [rdx+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_6b3:
	/* 0x6b3: je     c9c <generic_kprobe_actions+0xc9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b3, 0xc9c, x86_l_c9c);
x86_l_6b9:
	/* 0x6b9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6bc:
	/* 0x6bc: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_6c0:
	/* 0x6c0: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6c3:
	/* 0x6c3: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c8:
	/* 0x6c8: mov    ebp,DWORD PTR [rcx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_6cc:
	/* 0x6cc: mov    r15d,DWORD PTR [rcx+r15*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 4ULL);
x86_l_6d1:
	/* 0x6d1: mov    ecx,DWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6d4:
	/* 0x6d4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6d9:
	/* 0x6d9: shl    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_6dd:
	/* 0x6dd: or     r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6e0:
	/* 0x6e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e2:
	/* 0x6e2: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e7:
	/* 0x6e7: mov    WORD PTR [rsp+0x20],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ed:
	/* 0x6ed: mov    WORD PTR [rsp+0x22],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_6f2:
	/* 0x6f2: mov    QWORD PTR [rsp+0x24],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6f7:
	/* 0x6f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6fc:
	/* 0x6fc: lea    r14,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_701:
	/* 0x701: mov    rbp,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_708:
	/* 0x708: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_70b:
	/* 0x70b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_70e:
	/* 0x70e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_710:
	/* 0x710: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_713:
	/* 0x713: je     8c2 <generic_kprobe_actions+0x8c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x713, 0x8c2, x86_l_8c2);
x86_l_719:
	/* 0x719: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_71c:
	/* 0x71c: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_720:
	/* 0x720: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_725:
	/* 0x725: mov    DWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_72d:
	/* 0x72d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_732:
	/* 0x732: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_737:
	/* 0x737: mov    r14,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_73e:
	/* 0x73e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_741:
	/* 0x741: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_744:
	/* 0x744: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_746:
	/* 0x746: mov    DWORD PTR [rsp+0x6c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467969ULL);
x86_l_74e:
	/* 0x74e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_751:
	/* 0x751: je     9e1 <generic_kprobe_actions+0x9e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x751, 0x9e1, x86_l_9e1);
x86_l_757:
	/* 0x757: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_75a:
	/* 0x75a: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_75e:
	/* 0x75e: mov    DWORD PTR [r15+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_762:
	/* 0x762: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76a:
	/* 0x76a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_76f:
	/* 0x76f: jmp    d27 <generic_kprobe_actions+0xd27> */
	X86_SIM_X86_JMP(0x76f, 0xd27, x86_l_d27);
x86_l_774:
	/* 0x774: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_779:
	/* 0x779: mov    rax,QWORD PTR [rdx+r14*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 3), 24184ULL);
x86_l_781:
	/* 0x781: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_789:
	/* 0x789: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_78e:
	/* 0x78e: mov    eax,DWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_795:
	/* 0x795: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_799:
	/* 0x799: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_79e:
	/* 0x79e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a0:
	/* 0x7a0: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_7a4:
	/* 0x7a4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a9:
	/* 0x7a9: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_7ad:
	/* 0x7ad: jne    990 <generic_kprobe_actions+0x990> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ad, 0x990, x86_l_990);
x86_l_7b3:
	/* 0x7b3: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b8:
	/* 0x7b8: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7bb:
	/* 0x7bb: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7be:
	/* 0x7be: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c3:
	/* 0x7c3: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_7c8:
	/* 0x7c8: ja     9ab <generic_kprobe_actions+0x9ab> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7c8, 0x9ab, x86_l_9ab);
x86_l_7ce:
	/* 0x7ce: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_7d1:
	/* 0x7d1: cmp    DWORD PTR [rbp+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_7d9:
	/* 0x7d9: jne    9ae <generic_kprobe_actions+0x9ae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7d9, 0x9ae, x86_l_9ae);
x86_l_7df:
	/* 0x7df: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_7e7:
	/* 0x7e7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_7ec:
	/* 0x7ec: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_7ef:
	/* 0x7ef: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_7f6:
	/* 0x7f6: mov    esi,DWORD PTR [rbp+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_7fd:
	/* 0x7fd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_803:
	/* 0x803: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_807:
	/* 0x807: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_80c:
	/* 0x80c: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_811:
	/* 0x811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_813:
	/* 0x813: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_815:
	/* 0x815: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_81a:
	/* 0x81a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81f:
	/* 0x81f: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_826:
	/* 0x826: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_82b:
	/* 0x82b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_82d:
	/* 0x82d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82f:
	/* 0x82f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_831:
	/* 0x831: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_834:
	/* 0x834: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_836:
	/* 0x836: jne    107 <generic_kprobe_actions+0x107> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x836, 0x107, x86_l_107);
x86_l_83c:
	/* 0x83c: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x83c, 0xfd, x86_l_fd);
x86_l_841:
	/* 0x841: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_846:
	/* 0x846: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_84b:
	/* 0x84b: lea    rdx,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_850:
	/* 0x850: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_853:
	/* 0x853: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_856:
	/* 0x856: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_858:
	/* 0x858: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85b:
	/* 0x85b: je     576 <generic_kprobe_actions+0x576> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85b, 0x576, x86_l_576);
x86_l_861:
	/* 0x861: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_864:
	/* 0x864: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_866:
	/* 0x866: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86b:
	/* 0x86b: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_872:
	/* 0x872: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_87c:
	/* 0x87c: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_881:
	/* 0x881: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_886:
	/* 0x886: lea    rbp,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_88b:
	/* 0x88b: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_892:
	/* 0x892: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_895:
	/* 0x895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_897:
	/* 0x897: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89a:
	/* 0x89a: je     cb6 <generic_kprobe_actions+0xcb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89a, 0xcb6, x86_l_cb6);
x86_l_8a0:
	/* 0x8a0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8a2:
	/* 0x8a2: jmp    cd8 <generic_kprobe_actions+0xcd8> */
	X86_SIM_X86_JMP(0x8a2, 0xcd8, x86_l_cd8);
x86_l_8a7:
	/* 0x8a7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ac:
	/* 0x8ac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ae:
	/* 0x8ae: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8b3:
	/* 0x8b3: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_8b6:
	/* 0x8b6: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_8b9:
	/* 0x8b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8bb:
	/* 0x8bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bd:
	/* 0x8bd: jmp    950 <generic_kprobe_actions+0x950> */
	X86_SIM_X86_JMP(0x8bd, 0x950, x86_l_950);
x86_l_8c2:
	/* 0x8c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8c7:
	/* 0x8c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c9:
	/* 0x8c9: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8ce:
	/* 0x8ce: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_8d1:
	/* 0x8d1: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_8d4:
	/* 0x8d4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8e0:
	/* 0x8e0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e5:
	/* 0x8e5: je     d27 <generic_kprobe_actions+0xd27> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e5, 0xd27, x86_l_d27);
x86_l_8eb:
	/* 0x8eb: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_8ed:
	/* 0x8ed: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f2:
	/* 0x8f2: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_8f9:
	/* 0x8f9: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_903:
	/* 0x903: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_908:
	/* 0x908: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_90d:
	/* 0x90d: mov    r14,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_914:
	/* 0x914: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_917:
	/* 0x917: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91c:
	/* 0x91c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: je     d08 <generic_kprobe_actions+0xd08> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91f, 0xd08, x86_l_d08);
x86_l_925:
	/* 0x925: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_927:
	/* 0x927: jmp    d24 <generic_kprobe_actions+0xd24> */
	X86_SIM_X86_JMP(0x927, 0xd24, x86_l_d24);
x86_l_92c:
	/* 0x92c: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_934:
	/* 0x934: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_939:
	/* 0x939: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93b:
	/* 0x93b: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_940:
	/* 0x940: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_943:
	/* 0x943: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_946:
	/* 0x946: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_948:
	/* 0x948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94a:
	/* 0x94a: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_94e:
	/* 0x94e: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_950:
	/* 0x950: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_956:
	/* 0x956: mov    ebx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_32);
x86_l_959:
	/* 0x959: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_95e:
	/* 0x95e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_966:
	/* 0x966: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_96b:
	/* 0x96b: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_972:
	/* 0x972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_974:
	/* 0x974: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_977:
	/* 0x977: je     97e <generic_kprobe_actions+0x97e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x977, 0x97e, x86_l_97e);
x86_l_979:
	/* 0x979: inc QWORD PTR [rax+r14*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R14, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_97e:
	/* 0x97e: mov    r15d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_32);
x86_l_981:
	/* 0x981: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_986:
	/* 0x986: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_98b:
	/* 0x98b: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x98b, 0xfd, x86_l_fd);
x86_l_990:
	/* 0x990: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_995:
	/* 0x995: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_99a:
	/* 0x99a: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_9a1:
	/* 0x9a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a3:
	/* 0x9a3: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9a6:
	/* 0x9a6: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ab:
	/* 0x9ab: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9ae:
	/* 0x9ae: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9b0:
	/* 0x9b0: jne    107 <generic_kprobe_actions+0x107> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b0, 0x107, x86_l_107);
x86_l_9b6:
	/* 0x9b6: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x9b6, 0xfd, x86_l_fd);
x86_l_9bb:
	/* 0x9bb: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_9c0:
	/* 0x9c0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c5:
	/* 0x9c5: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_9cc:
	/* 0x9cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ce:
	/* 0x9ce: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9d1:
	/* 0x9d1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9d4:
	/* 0x9d4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9d6:
	/* 0x9d6: jne    107 <generic_kprobe_actions+0x107> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9d6, 0x107, x86_l_107);
x86_l_9dc:
	/* 0x9dc: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0x9dc, 0xfd, x86_l_fd);
x86_l_9e1:
	/* 0x9e1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9e6:
	/* 0x9e6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9eb:
	/* 0x9eb: lea    rdx,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_9f0:
	/* 0x9f0: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_9f3:
	/* 0x9f3: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_9f6:
	/* 0x9f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f8:
	/* 0x9f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9fb:
	/* 0x9fb: je     75a <generic_kprobe_actions+0x75a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9fb, 0x75a, x86_l_75a);
x86_l_a01:
	/* 0xa01: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a04:
	/* 0xa04: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a06:
	/* 0xa06: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a0b:
	/* 0xa0b: mov    WORD PTR [rsp+0xa],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672963ULL);
x86_l_a12:
	/* 0xa12: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_a1c:
	/* 0xa1c: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a21:
	/* 0xa21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a26:
	/* 0xa26: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2b:
	/* 0xa2b: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a32:
	/* 0xa32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a34:
	/* 0xa34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a37:
	/* 0xa37: je     d32 <generic_kprobe_actions+0xd32> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa37, 0xd32, x86_l_d32);
x86_l_a3d:
	/* 0xa3d: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a3f:
	/* 0xa3f: jmp    d56 <generic_kprobe_actions+0xd56> */
	X86_SIM_X86_JMP(0xa3f, 0xd56, x86_l_d56);
x86_l_a44:
	/* 0xa44: mov    eax,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a47:
	/* 0xa47: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a49:
	/* 0xa49: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a51:
	/* 0xa51: mov    QWORD PTR [rcx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a55:
	/* 0xa55: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a5a:
	/* 0xa5a: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a5e:
	/* 0xa5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a63:
	/* 0xa63: mov    ecx,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 200ULL);
x86_l_a68:
	/* 0xa68: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a6d:
	/* 0xa6d: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_a72:
	/* 0xa72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a74:
	/* 0xa74: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a77:
	/* 0xa77: jmp    a87 <generic_kprobe_actions+0xa87> */
	X86_SIM_X86_JMP(0xa77, 0xa87, x86_l_a87);
x86_l_a79:
	/* 0xa79: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a7d:
	/* 0xa7d: cmp    r14,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 20ULL);
x86_l_a81:
	/* 0xa81: je     bb0 <generic_kprobe_actions+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa81, 0xbb0, x86_l_bb0);
x86_l_a87:
	/* 0xa87: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_a8f:
	/* 0xa8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a94:
	/* 0xa94: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a9b:
	/* 0xa9b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa0:
	/* 0xaa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa2:
	/* 0xaa2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa5:
	/* 0xaa5: je     bb0 <generic_kprobe_actions+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa5, 0xbb0, x86_l_bb0);
x86_l_aab:
	/* 0xaab: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_aae:
	/* 0xaae: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_ab5:
	/* 0xab5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aba:
	/* 0xaba: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_ac1:
	/* 0xac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac3:
	/* 0xac3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac6:
	/* 0xac6: je     bb0 <generic_kprobe_actions+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac6, 0xbb0, x86_l_bb0);
x86_l_acc:
	/* 0xacc: cmp    DWORD PTR [rax+r14*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 279172874239ULL);
x86_l_ad2:
	/* 0xad2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad7:
	/* 0xad7: je     bb0 <generic_kprobe_actions+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad7, 0xbb0, x86_l_bb0);
x86_l_add:
	/* 0xadd: mov    rax,QWORD PTR [rdx+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_ae5:
	/* 0xae5: mov    ecx,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ae8:
	/* 0xae8: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_aeb:
	/* 0xaeb: jge    bb0 <generic_kprobe_actions+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_GE, 0xaeb, 0xbb0, x86_l_bb0);
x86_l_af1:
	/* 0xaf1: cmp    r14,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 16ULL);
x86_l_af5:
	/* 0xaf5: je     b62 <generic_kprobe_actions+0xb62> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf5, 0xb62, x86_l_b62);
x86_l_af7:
	/* 0xaf7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_aff:
	/* 0xaff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b04:
	/* 0xb04: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_b0b:
	/* 0xb0b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b10:
	/* 0xb10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b12:
	/* 0xb12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b15:
	/* 0xb15: je     b55 <generic_kprobe_actions+0xb55> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb15, 0xb55, x86_l_b55);
x86_l_b17:
	/* 0xb17: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_b1a:
	/* 0xb1a: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_b21:
	/* 0xb21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b26:
	/* 0xb26: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_b2d:
	/* 0xb2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2f:
	/* 0xb2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b32:
	/* 0xb32: je     b55 <generic_kprobe_actions+0xb55> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb32, 0xb55, x86_l_b55);
x86_l_b34:
	/* 0xb34: cmp    DWORD PTR [rax+r14*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 296352743423ULL);
x86_l_b3a:
	/* 0xb3a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b3f:
	/* 0xb3f: mov    rax,QWORD PTR [rdx+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_b47:
	/* 0xb47: je     b62 <generic_kprobe_actions+0xb62> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb47, 0xb62, x86_l_b62);
x86_l_b49:
	/* 0xb49: mov    ebx,DWORD PTR [rdx+r14*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 1), 24192ULL);
x86_l_b51:
	/* 0xb51: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b53:
	/* 0xb53: jmp    b6a <generic_kprobe_actions+0xb6a> */
	X86_SIM_X86_JMP(0xb53, 0xb6a, x86_l_b6a);
x86_l_b55:
	/* 0xb55: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b5a:
	/* 0xb5a: mov    rax,QWORD PTR [rdx+r14*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 1), 24184ULL);
x86_l_b62:
	/* 0xb62: mov    ebx,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b65:
	/* 0xb65: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b67:
	/* 0xb67: add    ebx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_b6a:
	/* 0xb6a: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_b6c:
	/* 0xb6c: jle    a79 <generic_kprobe_actions+0xa79> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb6c, 0xa79, x86_l_a79);
x86_l_b72:
	/* 0xb72: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_b77:
	/* 0xb77: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_b7c:
	/* 0xb7c: cmp    ebx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 40ULL);
x86_l_b7f:
	/* 0xb7f: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_b84:
	/* 0xb84: cmovge ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_b87:
	/* 0xb87: movzx  ebp,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b8b:
	/* 0xb8b: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b90:
	/* 0xb90: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b94:
	/* 0xb94: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b97:
	/* 0xb97: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_b9e:
	/* 0xb9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ba3:
	/* 0xba3: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_ba5:
	/* 0xba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba7:
	/* 0xba7: add    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ba9:
	/* 0xba9: mov    ebp,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_32);
x86_l_bab:
	/* 0xbab: jmp    a79 <generic_kprobe_actions+0xa79> */
	X86_SIM_X86_JMP(0xbab, 0xa79, x86_l_a79);
x86_l_bb0:
	/* 0xbb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bb5:
	/* 0xbb5: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_bbc:
	/* 0xbbc: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bc4:
	/* 0xbc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc6:
	/* 0xbc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc9:
	/* 0xbc9: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bce:
	/* 0xbce: je     bed <generic_kprobe_actions+0xbed> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbce, 0xbed, x86_l_bed);
x86_l_bd0:
	/* 0xbd0: imul   rcx,QWORD PTR [rsp+0x70],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 481035337152ULL);
x86_l_bd9:
	/* 0xbd9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bde:
	/* 0xbde: cmp    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be1:
	/* 0xbe1: jbe    bed <generic_kprobe_actions+0xbed> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xbe1, 0xbed, x86_l_bed);
x86_l_be3:
	/* 0xbe3: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_beb:
	/* 0xbeb: jmp    c0c <generic_kprobe_actions+0xc0c> */
	X86_SIM_X86_JMP(0xbeb, 0xc0c, x86_l_c0c);
x86_l_bed:
	/* 0xbed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bf2:
	/* 0xbf2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf4:
	/* 0xbf4: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_bfb:
	/* 0xbfb: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c00:
	/* 0xc00: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c08:
	/* 0xc08: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0a:
	/* 0xc0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0c:
	/* 0xc0c: lea    eax,[r15+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_c10:
	/* 0xc10: cmp    DWORD PTR [r14+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_c16:
	/* 0xc16: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c1b:
	/* 0xc1b: je     c47 <generic_kprobe_actions+0xc47> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc1b, 0xc47, x86_l_c47);
x86_l_c1d:
	/* 0xc1d: or     BYTE PTR [rdx+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_c21:
	/* 0xc21: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c26:
	/* 0xc26: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c28:
	/* 0xc28: mov    rsi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c2f:
	/* 0xc2f: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c37:
	/* 0xc37: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c39:
	/* 0xc39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3b:
	/* 0xc3b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c40:
	/* 0xc40: mov    QWORD PTR [rdx+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c47:
	/* 0xc47: lea    eax,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c4b:
	/* 0xc4b: cmp    DWORD PTR [r14+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_c51:
	/* 0xc51: je     c83 <generic_kprobe_actions+0xc83> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc51, 0xc83, x86_l_c83);
x86_l_c53:
	/* 0xc53: or     BYTE PTR [rdx+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_c57:
	/* 0xc57: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_c5c:
	/* 0xc5c: mov    rsi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_c63:
	/* 0xc63: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_c68:
	/* 0xc68: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c70:
	/* 0xc70: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_c75:
	/* 0xc75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c77:
	/* 0xc77: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c7c:
	/* 0xc7c: mov    QWORD PTR [rdx+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c83:
	/* 0xc83: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_c87:
	/* 0xc87: cmp    DWORD PTR [r14+r15*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 17179869184ULL);
x86_l_c8d:
	/* 0xc8d: je     fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8d, 0xfd, x86_l_fd);
x86_l_c93:
	/* 0xc93: or     BYTE PTR [rdx+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_c97:
	/* 0xc97: jmp    fd <generic_kprobe_actions+0xfd> */
	X86_SIM_X86_JMP(0xc97, 0xfd, x86_l_fd);
x86_l_c9c:
	/* 0xc9c: mov    rax,QWORD PTR [rdx+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_ca4:
	/* 0xca4: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ca9:
	/* 0xca9: mov    r14,QWORD PTR [rdx+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_cb1:
	/* 0xcb1: jmp    6bc <generic_kprobe_actions+0x6bc> */
	X86_SIM_X86_JMP(0xcb1, 0x6bc, x86_l_6bc);
x86_l_cb6:
	/* 0xcb6: mov    DWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_cbe:
	/* 0xcbe: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cc3:
	/* 0xcc3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc5:
	/* 0xcc5: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cca:
	/* 0xcca: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_cd1:
	/* 0xcd1: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_cd4:
	/* 0xcd4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd6:
	/* 0xcd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd8:
	/* 0xcd8: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_cda:
	/* 0xcda: je     576 <generic_kprobe_actions+0x576> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcda, 0x576, x86_l_576);
x86_l_ce0:
	/* 0xce0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce5:
	/* 0xce5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cea:
	/* 0xcea: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_cf1:
	/* 0xcf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf3:
	/* 0xcf3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf6:
	/* 0xcf6: je     576 <generic_kprobe_actions+0x576> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf6, 0x576, x86_l_576);
x86_l_cfc:
	/* 0xcfc: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d00:
	/* 0xd00: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d03:
	/* 0xd03: jmp    576 <generic_kprobe_actions+0x576> */
	X86_SIM_X86_JMP(0xd03, 0x576, x86_l_576);
x86_l_d08:
	/* 0xd08: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_d10:
	/* 0xd10: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d15:
	/* 0xd15: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d17:
	/* 0xd17: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d1a:
	/* 0xd1a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_d1d:
	/* 0xd1d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_d20:
	/* 0xd20: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d22:
	/* 0xd22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d24:
	/* 0xd24: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_d27:
	/* 0xd27: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_d2d:
	/* 0xd2d: jmp    95e <generic_kprobe_actions+0x95e> */
	X86_SIM_X86_JMP(0xd2d, 0x95e, x86_l_95e);
x86_l_d32:
	/* 0xd32: mov    DWORD PTR [rsp+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_d3a:
	/* 0xd3a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d3f:
	/* 0xd3f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d41:
	/* 0xd41: lea    rdx,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d46:
	/* 0xd46: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4b:
	/* 0xd4b: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_d52:
	/* 0xd52: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d54:
	/* 0xd54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d56:
	/* 0xd56: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_d59:
	/* 0xd59: je     75a <generic_kprobe_actions+0x75a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd59, 0x75a, x86_l_75a);
x86_l_d5f:
	/* 0xd5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d64:
	/* 0xd64: mov    rdi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d6b:
	/* 0xd6b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_d6e:
	/* 0xd6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d70:
	/* 0xd70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d73:
	/* 0xd73: je     75a <generic_kprobe_actions+0x75a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd73, 0x75a, x86_l_75a);
x86_l_d79:
	/* 0xd79: mov    ecx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_d7d:
	/* 0xd7d: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d80:
	/* 0xd80: jmp    75a <generic_kprobe_actions+0x75a> */
	X86_SIM_X86_JMP(0xd80, 0x75a, x86_l_75a);
x86_l_d85:
	/* 0xd85: cmp    BYTE PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_d8a:
	/* 0xd8a: je     dac <generic_kprobe_actions+0xdac> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd8a, 0xdac, x86_l_dac);
x86_l_d8c:
	/* 0xd8c: mov    rsi,QWORD PTR [rip+0x22927] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_d93:
	/* 0xd93: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d98:
	/* 0xd98: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d9d:
	/* 0xd9d: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_da5:
	/* 0xda5: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_daa:
	/* 0xdaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dac:
	/* 0xdac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dae:
	/* 0xdae: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_db5:
	/* 0xdb5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_db6:
	/* 0xdb6: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_dba:
	/* 0xdba: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_dbc:
	/* 0xdbc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_dbe:
	/* 0xdbe: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: jmp    dc4 <generic_kprobe_actions+0xdc4> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_dc4:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
