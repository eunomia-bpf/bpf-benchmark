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
int tetragon_bpf_multi_kprobe_v61_generic_kprobe_actions_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f:
	/* 0xf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14:
	/* 0x14: mov    rdi,QWORD PTR [rip+0x59b4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1b:
	/* 0x1b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     126 <generic_kprobe_actions+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0x126, x86_l_126);
x86_l_2b:
	/* 0x2b: mov    r14d,DWORD PTR [rax+0x5f04] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_32:
	/* 0x32: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_36:
	/* 0x36: jl     126 <generic_kprobe_actions+0x126> */
	X86_SIM_X86_JCC(X86_CC_L, 0x36, 0x126, x86_l_126);
x86_l_3c:
	/* 0x3c: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_42:
	/* 0x42: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_47:
	/* 0x47: mov    rdi,QWORD PTR [rip+0x59b4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4e:
	/* 0x4e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_53:
	/* 0x53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: je     126 <generic_kprobe_actions+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56, 0x126, x86_l_126);
x86_l_5c:
	/* 0x5c: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_5f:
	/* 0x5f: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_65:
	/* 0x65: add    r14d,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_69:
	/* 0x69: and    r14d,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_70:
	/* 0x70: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_73:
	/* 0x73: mov    BYTE PTR [rsp+0x7],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771073ULL);
x86_l_78:
	/* 0x78: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_80:
	/* 0x80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_85:
	/* 0x85: mov    rdi,QWORD PTR [rip+0x59b4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_conf)));
x86_l_8c:
	/* 0x8c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_96:
	/* 0x96: je     a6 <generic_kprobe_actions+0xa6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96, 0xa6, x86_l_a6);
x86_l_98:
	/* 0x98: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b:
	/* 0x9b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_9e:
	/* 0x9e: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_a2:
	/* 0xa2: jae    ae <generic_kprobe_actions+0xae> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa2, 0xae, x86_l_ae);
x86_l_a4:
	/* 0xa4: jmp    109 <generic_kprobe_actions+0x109> */
	X86_SIM_X86_JMP(0xa4, 0x109, x86_l_109);
x86_l_a6:
	/* 0xa6: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_a8:
	/* 0xa8: cmp    DWORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_ac:
	/* 0xac: jb     109 <generic_kprobe_actions+0x109> */
	X86_SIM_X86_JCC(X86_CC_B, 0xac, 0x109, x86_l_109);
x86_l_ae:
	/* 0xae: movzx  r13d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b2:
	/* 0xb2: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_b7:
	/* 0xb7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ba:
	/* 0xba: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc:
	/* 0xbc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_c2:
	/* 0xc2: call   0 <generic_kprobe_actions> */
	X86_SIM_X86_CALL(x86_l_131, 0xc7ULL);
x86_l_c7:
	/* 0xc7: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_ce:
	/* 0xce: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d1:
	/* 0xd1: jae    109 <generic_kprobe_actions+0x109> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xd1, 0x109, x86_l_109);
x86_l_d3:
	/* 0xd3: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_d8:
	/* 0xd8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_dd:
	/* 0xdd: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e0:
	/* 0xe0: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_e3:
	/* 0xe3: call   0 <generic_kprobe_actions> */
	X86_SIM_X86_CALL(x86_l_131, 0xe8ULL);
x86_l_e8:
	/* 0xe8: lea    ecx,[rax*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_ef:
	/* 0xef: cmp    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_f2:
	/* 0xf2: jae    109 <generic_kprobe_actions+0x109> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf2, 0x109, x86_l_109);
x86_l_f4:
	/* 0xf4: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_f9:
	/* 0xf9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_fe:
	/* 0xfe: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_101:
	/* 0x101: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_104:
	/* 0x104: call   0 <generic_kprobe_actions> */
	X86_SIM_X86_CALL(x86_l_131, 0x109ULL);
x86_l_109:
	/* 0x109: cmp    BYTE PTR [rsp+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_10e:
	/* 0x10e: je     126 <generic_kprobe_actions+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e, 0x126, x86_l_126);
x86_l_110:
	/* 0x110: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_115:
	/* 0x115: mov    rsi,QWORD PTR [rip+0x59b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_11c:
	/* 0x11c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_124:
	/* 0x124: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126:
	/* 0x126: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_128:
	/* 0x128: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_12c:
	/* 0x12c: jmp    d1f <do_action+0xbee> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_d1f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_131 */
x86_l_131:
	/* 0x131: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_132:
	/* 0x132: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_134:
	/* 0x134: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_136:
	/* 0x136: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_138:
	/* 0x138: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_13a:
	/* 0x13a: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_13b:
	/* 0x13b: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_142:
	/* 0x142: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_145:
	/* 0x145: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_148:
	/* 0x148: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_14b:
	/* 0x14b: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_14e:
	/* 0x14e: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_151:
	/* 0x151: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_153:
	/* 0x153: movsxd rbx,DWORD PTR [rdx+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RAX, 2, X86_WIDTH_32), 4ULL);
x86_l_158:
	/* 0x158: mov    DWORD PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_160:
	/* 0x160: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165:
	/* 0x165: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_16c:
	/* 0x16c: lea    rsi,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_171:
	/* 0x171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173:
	/* 0x173: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_176:
	/* 0x176: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178:
	/* 0x178: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_17b:
	/* 0x17b: je     c25 <do_action+0xaf4> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x17b, 0xc25, x86_l_c25);
x86_l_181:
	/* 0x181: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_184:
	/* 0x184: jg     1aa <do_action+0x79> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x184, 0x1aa, x86_l_1aa);
x86_l_186:
	/* 0x186: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_189:
	/* 0x189: jg     1de <do_action+0xad> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x189, 0x1de, x86_l_1de);
x86_l_18b:
	/* 0x18b: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_18e:
	/* 0x18e: jg     316 <do_action+0x1e5> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x18e, 0x316, x86_l_316);
x86_l_194:
	/* 0x194: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_196:
	/* 0x196: je     641 <do_action+0x510> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x196, 0x641, x86_l_641);
x86_l_19c:
	/* 0x19c: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_19f:
	/* 0x19f: je     32d <do_action+0x1fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19f, 0x32d, x86_l_32d);
x86_l_1a5:
	/* 0x1a5: jmp    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JMP(0x1a5, 0xc1b, x86_l_c1b);
x86_l_1aa:
	/* 0x1aa: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_1ad:
	/* 0x1ad: jg     2e5 <do_action+0x1b4> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1ad, 0x2e5, x86_l_2e5);
x86_l_1b3:
	/* 0x1b3: lea    ecx,[rbx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1b6:
	/* 0x1b6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b9:
	/* 0x1b9: jb     440 <do_action+0x30f> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1b9, 0x440, x86_l_440);
x86_l_1bf:
	/* 0x1bf: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1c2:
	/* 0x1c2: je     53e <do_action+0x40d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c2, 0x53e, x86_l_53e);
x86_l_1c8:
	/* 0x1c8: cmp    ebx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_1cb:
	/* 0x1cb: jne    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1cb, 0xc1b, x86_l_c1b);
x86_l_1d1:
	/* 0x1d1: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d4:
	/* 0x1d4: mov    edi,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_1d9:
	/* 0x1d9: jmp    504 <do_action+0x3d3> */
	X86_SIM_X86_SUB_JMP(0x1d9, 0x504, x86_l_504);
x86_l_1de:
	/* 0x1de: lea    eax,[rbx-0x6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551610ULL);
x86_l_1e1:
	/* 0x1e1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e4:
	/* 0x1e4: jb     52d <do_action+0x3fc> */
	X86_SIM_X86_SUB_JCC(X86_CC_B, 0x1e4, 0x52d, x86_l_52d);
x86_l_1ea:
	/* 0x1ea: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1ed:
	/* 0x1ed: je     548 <do_action+0x417> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ed, 0x548, x86_l_548);
x86_l_1f3:
	/* 0x1f3: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_1f6:
	/* 0x1f6: jne    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1f6, 0xc1b, x86_l_c1b);
x86_l_1fc:
	/* 0x1fc: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_200:
	/* 0x200: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_205:
	/* 0x205: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_209:
	/* 0x209: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_20c:
	/* 0x20c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20f:
	/* 0x20f: ja     c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x20f, 0xc1b, x86_l_c1b);
x86_l_215:
	/* 0x215: cmp    DWORD PTR [r8+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_21e:
	/* 0x21e: jne    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x21e, 0xc1b, x86_l_c1b);
x86_l_224:
	/* 0x224: mov    r15d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_229:
	/* 0x229: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_231:
	/* 0x231: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_239:
	/* 0x239: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_23e:
	/* 0x23e: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_246:
	/* 0x246: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a:
	/* 0x24a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_24f:
	/* 0x24f: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_252:
	/* 0x252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254:
	/* 0x254: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_258:
	/* 0x258: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c:
	/* 0x25c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_261:
	/* 0x261: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_268:
	/* 0x268: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_26b:
	/* 0x26b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d:
	/* 0x26d: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_270:
	/* 0x270: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_273:
	/* 0x273: je     c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x273, 0xc1b, x86_l_c1b);
x86_l_279:
	/* 0x279: and    r15d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_27d:
	/* 0x27d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_281:
	/* 0x281: ja     c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x281, 0xc1b, x86_l_c1b);
x86_l_287:
	/* 0x287: cmp    DWORD PTR [r8+r15*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 104041287778304ULL);
x86_l_290:
	/* 0x290: jne    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x290, 0xc1b, x86_l_c1b);
x86_l_296:
	/* 0x296: mov    rcx,QWORD PTR [r8+r15*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_29e:
	/* 0x29e: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2a6:
	/* 0x2a6: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_2ac:
	/* 0x2ac: mov    ecx,DWORD PTR [r8+rcx*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_2b4:
	/* 0x2b4: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b8:
	/* 0x2b8: mov    ecx,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_2bd:
	/* 0x2bd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c0:
	/* 0x2c0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2c2:
	/* 0x2c2: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2c6:
	/* 0x2c6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca:
	/* 0x2ca: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cf:
	/* 0x2cf: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_2d6:
	/* 0x2d6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2d9:
	/* 0x2d9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dc:
	/* 0x2dc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de:
	/* 0x2de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0:
	/* 0x2e0: jmp    639 <do_action+0x508> */
	X86_SIM_X86_SUB_JMP(0x2e0, 0x639, x86_l_639);
x86_l_2e5:
	/* 0x2e5: cmp    ebx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 12ULL);
x86_l_2e8:
	/* 0x2e8: je     70a <do_action+0x5d9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2e8, 0x70a, x86_l_70a);
x86_l_2ee:
	/* 0x2ee: cmp    ebx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 13ULL);
x86_l_2f1:
	/* 0x2f1: je     5c7 <do_action+0x496> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2f1, 0x5c7, x86_l_5c7);
x86_l_2f7:
	/* 0x2f7: cmp    ebx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_2fa:
	/* 0x2fa: jne    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2fa, 0xc1b, x86_l_c1b);
x86_l_300:
	/* 0x300: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_305:
	/* 0x305: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_309:
	/* 0x309: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30d:
	/* 0x30d: xor    r13,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_XOR, 9ULL);
x86_l_311:
	/* 0x311: jmp    90f <do_action+0x7de> */
	X86_SIM_X86_SUB_JMP(0x311, 0x90f, x86_l_90f);
x86_l_316:
	/* 0x316: mov    edi,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_31b:
	/* 0x31b: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_31e:
	/* 0x31e: je     504 <do_action+0x3d3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x31e, 0x504, x86_l_504);
x86_l_324:
	/* 0x324: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_327:
	/* 0x327: jne    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x327, 0xc1b, x86_l_c1b);
x86_l_32d:
	/* 0x32d: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_330:
	/* 0x330: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_334:
	/* 0x334: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_339:
	/* 0x339: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_33d:
	/* 0x33d: mov    r12d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_342:
	/* 0x342: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34a:
	/* 0x34a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34f:
	/* 0x34f: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap)));
x86_l_356:
	/* 0x356: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b:
	/* 0x35b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d:
	/* 0x35d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_360:
	/* 0x360: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_363:
	/* 0x363: je     957 <do_action+0x826> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x363, 0x957, x86_l_957);
x86_l_369:
	/* 0x369: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36e:
	/* 0x36e: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_371:
	/* 0x371: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_374:
	/* 0x374: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_379:
	/* 0x379: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_37c:
	/* 0x37c: ja     95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x37c, 0x95c, x86_l_95c);
x86_l_382:
	/* 0x382: cmp    DWORD PTR [r8+rbp*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 104041287778304ULL);
x86_l_38b:
	/* 0x38b: jne    95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x38b, 0x95c, x86_l_95c);
x86_l_391:
	/* 0x391: mov    rax,QWORD PTR [r8+rbp*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_399:
	/* 0x399: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_3a1:
	/* 0x3a1: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3a6:
	/* 0x3a6: mov    eax,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_3ae:
	/* 0x3ae: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b2:
	/* 0x3b2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3b7:
	/* 0x3b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9:
	/* 0x3b9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3bd:
	/* 0x3bd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c1:
	/* 0x3c1: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3c4:
	/* 0x3c4: jne    8d5 <do_action+0x7a4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3c4, 0x8d5, x86_l_8d5);
x86_l_3ca:
	/* 0x3ca: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_3ce:
	/* 0x3ce: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3d2:
	/* 0x3d2: ja     957 <do_action+0x826> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x3d2, 0x957, x86_l_957);
x86_l_3d8:
	/* 0x3d8: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_3db:
	/* 0x3db: cmp    DWORD PTR [r13+r12*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104041287778304ULL);
x86_l_3e4:
	/* 0x3e4: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3e9:
	/* 0x3e9: jne    95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x3e9, 0x95c, x86_l_95c);
x86_l_3ef:
	/* 0x3ef: mov    rax,QWORD PTR [r8+r12*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_3f7:
	/* 0x3f7: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_3fc:
	/* 0x3fc: lea    rdx,[r8+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_400:
	/* 0x400: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_407:
	/* 0x407: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_40c:
	/* 0x40c: and    esi,DWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R8, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_414:
	/* 0x414: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_417:
	/* 0x417: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41c:
	/* 0x41c: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_421:
	/* 0x421: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_424:
	/* 0x424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426:
	/* 0x426: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_42b:
	/* 0x42b: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_432:
	/* 0x432: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_435:
	/* 0x435: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_438:
	/* 0x438: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_43b:
	/* 0x43b: jmp    4f6 <do_action+0x3c5> */
	X86_SIM_X86_SUB_JMP(0x43b, 0x4f6, x86_l_4f6);
x86_l_440:
	/* 0x440: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_443:
	/* 0x443: mov    ecx,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_448:
	/* 0x448: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_44b:
	/* 0x44b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44e:
	/* 0x44e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_451:
	/* 0x451: ja     95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x451, 0x95c, x86_l_95c);
x86_l_457:
	/* 0x457: cmp    DWORD PTR [r8+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_460:
	/* 0x460: jne    95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x460, 0x95c, x86_l_95c);
x86_l_466:
	/* 0x466: mov    rcx,QWORD PTR [r8+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_46e:
	/* 0x46e: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_474:
	/* 0x474: mov    rcx,QWORD PTR [r8+rcx*1+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 184ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_481:
	/* 0x481: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: je     95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x484, 0x95c, x86_l_95c);
x86_l_48a:
	/* 0x48a: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_48d:
	/* 0x48d: cmp    ebx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_490:
	/* 0x490: jne    941 <do_action+0x810> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x490, 0x941, x86_l_941);
x86_l_496:
	/* 0x496: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_49b:
	/* 0x49b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d:
	/* 0x49d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4a0:
	/* 0x4a0: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4a4:
	/* 0x4a4: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a7:
	/* 0x4a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ac:
	/* 0x4ac: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_4b3:
	/* 0x4b3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4b6:
	/* 0x4b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b8:
	/* 0x4b8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4bb:
	/* 0x4bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4be:
	/* 0x4be: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_4c3:
	/* 0x4c3: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: je     95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x4c6, 0x95c, x86_l_95c);
x86_l_4cc:
	/* 0x4cc: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ce:
	/* 0x4ce: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d1:
	/* 0x4d1: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d6:
	/* 0x4d6: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4da:
	/* 0x4da: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4df:
	/* 0x4df: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4e4:
	/* 0x4e4: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_4eb:
	/* 0x4eb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ee:
	/* 0x4ee: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f3:
	/* 0x4f3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4f6:
	/* 0x4f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f8:
	/* 0x4f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa:
	/* 0x4fa: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_4fd:
	/* 0x4fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ff:
	/* 0x4ff: jmp    95c <do_action+0x82b> */
	X86_SIM_X86_SUB_JMP(0x4ff, 0x95c, x86_l_95c);
x86_l_504:
	/* 0x504: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_507:
	/* 0x507: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50c:
	/* 0x50c: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_512:
	/* 0x512: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_515:
	/* 0x515: je     912 <do_action+0x7e1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x515, 0x912, x86_l_912);
x86_l_51b:
	/* 0x51b: mov    eax,0x6d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 109ULL);
x86_l_520:
	/* 0x520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_522:
	/* 0x522: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_528:
	/* 0x528: jmp    912 <do_action+0x7e1> */
	X86_SIM_X86_SUB_JMP(0x528, 0x912, x86_l_912);
x86_l_52d:
	/* 0x52d: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_530:
	/* 0x530: mov    eax,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_535:
	/* 0x535: mov    DWORD PTR [r8+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_539:
	/* 0x539: jmp    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JMP(0x539, 0xc1b, x86_l_c1b);
x86_l_53e:
	/* 0x53e: mov    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_543:
	/* 0x543: jmp    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JMP(0x543, 0xc1b, x86_l_c1b);
x86_l_548:
	/* 0x548: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_54d:
	/* 0x54d: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_550:
	/* 0x550: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_556:
	/* 0x556: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_559:
	/* 0x559: je     90f <do_action+0x7de> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x559, 0x90f, x86_l_90f);
x86_l_55f:
	/* 0x55f: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_562:
	/* 0x562: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_567:
	/* 0x567: mov    DWORD PTR [rsp+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_56b:
	/* 0x56b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_570:
	/* 0x570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572:
	/* 0x572: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_577:
	/* 0x577: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57c:
	/* 0x57c: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_583:
	/* 0x583: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_588:
	/* 0x588: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a:
	/* 0x58a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58d:
	/* 0x58d: je     853 <do_action+0x722> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x58d, 0x853, x86_l_853);
x86_l_593:
	/* 0x593: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_596:
	/* 0x596: mov    DWORD PTR [rsp],0xe0011 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 917521ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rsp+0x4],0x35f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179870047ULL);
x86_l_5a6:
	/* 0x5a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ab:
	/* 0x5ab: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_5b2:
	/* 0x5b2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5b5:
	/* 0x5b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b7:
	/* 0x5b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ba:
	/* 0x5ba: je     8e6 <do_action+0x7b5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5ba, 0x8e6, x86_l_8e6);
x86_l_5c0:
	/* 0x5c0: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5c2:
	/* 0x5c2: jmp    906 <do_action+0x7d5> */
	X86_SIM_X86_SUB_JMP(0x5c2, 0x906, x86_l_906);
x86_l_5c7:
	/* 0x5c7: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_5ca:
	/* 0x5ca: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5cf:
	/* 0x5cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d1:
	/* 0x5d1: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d6:
	/* 0x5d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5db:
	/* 0x5db: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_5e2:
	/* 0x5e2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e7:
	/* 0x5e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e9:
	/* 0x5e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ec:
	/* 0x5ec: je     639 <do_action+0x508> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x5ec, 0x639, x86_l_639);
x86_l_5ee:
	/* 0x5ee: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f7:
	/* 0x5f7: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_5ff:
	/* 0x5ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_604:
	/* 0x604: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_60b:
	/* 0x60b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_610:
	/* 0x610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_612:
	/* 0x612: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_61a:
	/* 0x61a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61d:
	/* 0x61d: je     7ed <do_action+0x6bc> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x61d, 0x7ed, x86_l_7ed);
x86_l_623:
	/* 0x623: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_626:
	/* 0x626: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_62b:
	/* 0x62b: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_632:
	/* 0x632: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_637:
	/* 0x637: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_639:
	/* 0x639: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_63c:
	/* 0x63c: jmp    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JMP(0x63c, 0xc1b, x86_l_c1b);
x86_l_641:
	/* 0x641: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_646:
	/* 0x646: lea    eax,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_64a:
	/* 0x64a: mov    ebp,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_64f:
	/* 0x64f: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_653:
	/* 0x653: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_658:
	/* 0x658: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_65c:
	/* 0x65c: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_661:
	/* 0x661: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_663:
	/* 0x663: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_668:
	/* 0x668: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66c:
	/* 0x66c: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_674:
	/* 0x674: mov    QWORD PTR [rsp+0x78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_679:
	/* 0x679: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_67c:
	/* 0x67c: je     ba2 <do_action+0xa71> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x67c, 0xba2, x86_l_ba2);
x86_l_682:
	/* 0x682: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_687:
	/* 0x687: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_heap)));
x86_l_68e:
	/* 0x68e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_693:
	/* 0x693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_695:
	/* 0x695: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_698:
	/* 0x698: je     ba2 <do_action+0xa71> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x698, 0xba2, x86_l_ba2);
x86_l_69e:
	/* 0x69e: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6a3:
	/* 0x6a3: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_6a6:
	/* 0x6a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ab:
	/* 0x6ab: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6b2:
	/* 0x6b2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6b7:
	/* 0x6b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b9:
	/* 0x6b9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6be:
	/* 0x6be: mov    rcx,QWORD PTR [rdx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6c2:
	/* 0x6c2: mov    QWORD PTR [rbp+0x0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c6:
	/* 0x6c6: mov    rcx,QWORD PTR [rdx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6ca:
	/* 0x6ca: mov    QWORD PTR [rsp+0x58],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6cf:
	/* 0x6cf: mov    QWORD PTR [rbp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d3:
	/* 0x6d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d5:
	/* 0x6d5: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6da:
	/* 0x6da: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_6df:
	/* 0x6df: mov    esi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e3:
	/* 0x6e3: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_6e6:
	/* 0x6e6: je     9d3 <do_action+0x8a2> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6e6, 0x9d3, x86_l_9d3);
x86_l_6ec:
	/* 0x6ec: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_6ef:
	/* 0x6ef: je     9d0 <do_action+0x89f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x6ef, 0x9d0, x86_l_9d0);
x86_l_6f5:
	/* 0x6f5: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_6f7:
	/* 0x6f7: jne    ba2 <do_action+0xa71> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x6f7, 0xba2, x86_l_ba2);
x86_l_6fd:
	/* 0x6fd: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_702:
	/* 0x702: mov    ecx,DWORD PTR [rcx+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_705:
	/* 0x705: jmp    9d3 <do_action+0x8a2> */
	X86_SIM_X86_SUB_JMP(0x705, 0x9d3, x86_l_9d3);
x86_l_70a:
	/* 0x70a: lea    r12d,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_70e:
	/* 0x70e: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_714:
	/* 0x714: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_717:
	/* 0x717: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71c:
	/* 0x71c: je     912 <do_action+0x7e1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x71c, 0x912, x86_l_912);
x86_l_722:
	/* 0x722: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_725:
	/* 0x725: mov    eax,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_72a:
	/* 0x72a: lea    ecx,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_72e:
	/* 0x72e: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_731:
	/* 0x731: mov    ebp,DWORD PTR [r15+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_736:
	/* 0x736: mov    r14d,DWORD PTR [r15+r14*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 4ULL);
x86_l_73b:
	/* 0x73b: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_73f:
	/* 0x73f: ja     750 <do_action+0x61f> */
	X86_SIM_X86_SUB_JCC(X86_CC_A, 0x73f, 0x750, x86_l_750);
x86_l_741:
	/* 0x741: cmp    DWORD PTR [r8+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_74a:
	/* 0x74a: je     c37 <do_action+0xb06> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x74a, 0xc37, x86_l_c37);
x86_l_750:
	/* 0x750: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_753:
	/* 0x753: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_755:
	/* 0x755: mov    ebx,DWORD PTR [r8+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_759:
	/* 0x759: or     rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_75c:
	/* 0x75c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_761:
	/* 0x761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_763:
	/* 0x763: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_768:
	/* 0x768: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_76e:
	/* 0x76e: mov    WORD PTR [rsp+0x12],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_773:
	/* 0x773: mov    QWORD PTR [rsp+0x14],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_778:
	/* 0x778: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_77d:
	/* 0x77d: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_784:
	/* 0x784: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_789:
	/* 0x789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78b:
	/* 0x78b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78e:
	/* 0x78e: je     872 <do_action+0x741> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x78e, 0x872, x86_l_872);
x86_l_794:
	/* 0x794: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_797:
	/* 0x797: mov    rax,QWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79b:
	/* 0x79b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7a0:
	/* 0x7a0: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_7a8:
	/* 0x7a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ad:
	/* 0x7ad: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7b4:
	/* 0x7b4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7b9:
	/* 0x7b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bb:
	/* 0x7bb: mov    DWORD PTR [rsp+0x44],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776129ULL);
x86_l_7c3:
	/* 0x7c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_7c9:
	/* 0x7c9: je     96a <do_action+0x839> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x7c9, 0x96a, x86_l_96a);
x86_l_7cf:
	/* 0x7cf: inc DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7d2:
	/* 0x7d2: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7d6:
	/* 0x7d6: mov    DWORD PTR [r14+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7da:
	/* 0x7da: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7df:
	/* 0x7df: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e2:
	/* 0x7e2: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_7e8:
	/* 0x7e8: jmp    912 <do_action+0x7e1> */
	X86_SIM_X86_SUB_JMP(0x7e8, 0x912, x86_l_912);
x86_l_7ed:
	/* 0x7ed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7f2:
	/* 0x7f2: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_7f9:
	/* 0x7f9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fe:
	/* 0x7fe: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_803:
	/* 0x803: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_808:
	/* 0x808: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80a:
	/* 0x80a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80d:
	/* 0x80d: je     626 <do_action+0x4f5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x80d, 0x626, x86_l_626);
x86_l_813:
	/* 0x813: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_816:
	/* 0x816: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_818:
	/* 0x818: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81c:
	/* 0x81c: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_823:
	/* 0x823: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_82d:
	/* 0x82d: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_832:
	/* 0x832: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_837:
	/* 0x837: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_83e:
	/* 0x83e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_841:
	/* 0x841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_843:
	/* 0x843: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_846:
	/* 0x846: je     c58 <do_action+0xb27> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x846, 0xc58, x86_l_c58);
x86_l_84c:
	/* 0x84c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_84e:
	/* 0x84e: jmp    c78 <do_action+0xb47> */
	X86_SIM_X86_SUB_JMP(0x84e, 0xc78, x86_l_c78);
x86_l_853:
	/* 0x853: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_858:
	/* 0x858: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_85f:
	/* 0x85f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_864:
	/* 0x864: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_869:
	/* 0x869: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86b:
	/* 0x86b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86d:
	/* 0x86d: jmp    909 <do_action+0x7d8> */
	X86_SIM_X86_SUB_JMP(0x86d, 0x909, x86_l_909);
x86_l_872:
	/* 0x872: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_877:
	/* 0x877: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_data)));
x86_l_87e:
	/* 0x87e: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_883:
	/* 0x883: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_888:
	/* 0x888: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_88a:
	/* 0x88a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88c:
	/* 0x88c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_88f:
	/* 0x88f: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_892:
	/* 0x892: je     7e2 <do_action+0x6b1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x892, 0x7e2, x86_l_7e2);
x86_l_898:
	/* 0x898: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_89a:
	/* 0x89a: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89e:
	/* 0x89e: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_8a5:
	/* 0x8a5: movabs rax,0x20000006b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934699ULL);
x86_l_8af:
	/* 0x8af: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8b4:
	/* 0x8b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b9:
	/* 0x8b9: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8c0:
	/* 0x8c0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c5:
	/* 0x8c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c8:
	/* 0x8c8: je     ca9 <do_action+0xb78> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x8c8, 0xca9, x86_l_ca9);
x86_l_8ce:
	/* 0x8ce: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8d0:
	/* 0x8d0: jmp    7e2 <do_action+0x6b1> */
	X86_SIM_X86_SUB_JMP(0x8d0, 0x7e2, x86_l_7e2);
x86_l_8d5:
	/* 0x8d5: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8da:
	/* 0x8da: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_8e1:
	/* 0x8e1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8e4:
	/* 0x8e4: jmp    952 <do_action+0x821> */
	X86_SIM_X86_SUB_JMP(0x8e4, 0x952, x86_l_952);
x86_l_8e6:
	/* 0x8e6: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_8ee:
	/* 0x8ee: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8f3:
	/* 0x8f3: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8fa:
	/* 0x8fa: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8fd:
	/* 0x8fd: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_902:
	/* 0x902: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_904:
	/* 0x904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_906:
	/* 0x906: mov    DWORD PTR [r15],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_909:
	/* 0x909: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_90f:
	/* 0x90f: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_912:
	/* 0x912: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_919:
	/* 0x919: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91e:
	/* 0x91e: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_925:
	/* 0x925: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_928:
	/* 0x928: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92a:
	/* 0x92a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_92d:
	/* 0x92d: je     934 <do_action+0x803> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x92d, 0x934, x86_l_934);
x86_l_92f:
	/* 0x92f: inc QWORD PTR [rax+r13*8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_R13, 3, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_934:
	/* 0x934: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_937:
	/* 0x937: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_93c:
	/* 0x93c: jmp    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JMP(0x93c, 0xc1b, x86_l_c1b);
x86_l_941:
	/* 0x941: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_946:
	/* 0x946: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_94d:
	/* 0x94d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_952:
	/* 0x952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_954:
	/* 0x954: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_957:
	/* 0x957: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_959:
	/* 0x959: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_95c:
	/* 0x95c: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_95f:
	/* 0x95f: jne    c25 <do_action+0xaf4> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x95f, 0xc25, x86_l_c25);
x86_l_965:
	/* 0x965: jmp    c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JMP(0x965, 0xc1b, x86_l_c1b);
x86_l_96a:
	/* 0x96a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_96f:
	/* 0x96f: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_976:
	/* 0x976: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_97b:
	/* 0x97b: lea    rdx,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_980:
	/* 0x980: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_985:
	/* 0x985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_987:
	/* 0x987: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98a:
	/* 0x98a: je     7d2 <do_action+0x6a1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x98a, 0x7d2, x86_l_7d2);
x86_l_990:
	/* 0x990: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_993:
	/* 0x993: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_995:
	/* 0x995: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_999:
	/* 0x999: mov    WORD PTR [rsp+0x2],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934595ULL);
x86_l_9a0:
	/* 0x9a0: movabs rax,0x20000003b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934651ULL);
x86_l_9aa:
	/* 0x9aa: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9af:
	/* 0x9af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9b4:
	/* 0x9b4: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9bb:
	/* 0x9bb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c0:
	/* 0x9c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c3:
	/* 0x9c3: je     cce <do_action+0xb9d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x9c3, 0xcce, x86_l_cce);
x86_l_9c9:
	/* 0x9c9: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9cb:
	/* 0x9cb: jmp    cee <do_action+0xbbd> */
	X86_SIM_X86_SUB_JMP(0x9cb, 0xcee, x86_l_cee);
x86_l_9d0:
	/* 0x9d0: mov    ecx,DWORD PTR [rdx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d3:
	/* 0x9d3: mov    QWORD PTR [rsp+0x48],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d8:
	/* 0x9d8: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9da:
	/* 0x9da: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9df:
	/* 0x9df: mov    QWORD PTR [rdx+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e3:
	/* 0x9e3: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9e8:
	/* 0x9e8: add    rdi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_9ec:
	/* 0x9ec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9f1:
	/* 0x9f1: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f6:
	/* 0x9f6: mov    esi,0xc8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 200ULL);
x86_l_9fb:
	/* 0x9fb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9fe:
	/* 0x9fe: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a00:
	/* 0xa00: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a03:
	/* 0xa03: mov    QWORD PTR [rsp+0x80],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a0b:
	/* 0xa0b: jmp    a1b <do_action+0x8ea> */
	X86_SIM_X86_SUB_JMP(0xa0b, 0xa1b, x86_l_a1b);
x86_l_a0d:
	/* 0xa0d: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a11:
	/* 0xa11: cmp    r12,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 20ULL);
x86_l_a15:
	/* 0xa15: je     b50 <do_action+0xa1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa15, 0xb50, x86_l_b50);
x86_l_a1b:
	/* 0xa1b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a23:
	/* 0xa23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a28:
	/* 0xa28: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a2f:
	/* 0xa2f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a34:
	/* 0xa34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a36:
	/* 0xa36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a39:
	/* 0xa39: je     b50 <do_action+0xa1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa39, 0xb50, x86_l_b50);
x86_l_a3f:
	/* 0xa3f: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_a45:
	/* 0xa45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a4a:
	/* 0xa4a: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_a51:
	/* 0xa51: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a54:
	/* 0xa54: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a56:
	/* 0xa56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a59:
	/* 0xa59: je     b50 <do_action+0xa1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa59, 0xb50, x86_l_b50);
x86_l_a5f:
	/* 0xa5f: cmp    DWORD PTR [rax+r12*1+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 279172874239ULL);
x86_l_a65:
	/* 0xa65: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6a:
	/* 0xa6a: je     b50 <do_action+0xa1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa6a, 0xb50, x86_l_b50);
x86_l_a70:
	/* 0xa70: mov    rax,QWORD PTR [rdx+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_a78:
	/* 0xa78: mov    ecx,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a7b:
	/* 0xa7b: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a7e:
	/* 0xa7e: jge    b50 <do_action+0xa1f> */
	X86_SIM_X86_SUB_JCC(X86_CC_GE, 0xa7e, 0xb50, x86_l_b50);
x86_l_a84:
	/* 0xa84: cmp    r12,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 16ULL);
x86_l_a88:
	/* 0xa88: je     af4 <do_action+0x9c3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa88, 0xaf4, x86_l_af4);
x86_l_a8a:
	/* 0xa8a: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a92:
	/* 0xa92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a97:
	/* 0xa97: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a9e:
	/* 0xa9e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa3:
	/* 0xaa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa5:
	/* 0xaa5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa8:
	/* 0xaa8: je     ae7 <do_action+0x9b6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xaa8, 0xae7, x86_l_ae7);
x86_l_aaa:
	/* 0xaaa: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_ab0:
	/* 0xab0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ab5:
	/* 0xab5: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_abc:
	/* 0xabc: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_abf:
	/* 0xabf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ac1:
	/* 0xac1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac4:
	/* 0xac4: je     ae7 <do_action+0x9b6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xac4, 0xae7, x86_l_ae7);
x86_l_ac6:
	/* 0xac6: cmp    DWORD PTR [rax+r12*1+0x44],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 296352743423ULL);
x86_l_acc:
	/* 0xacc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ad1:
	/* 0xad1: mov    rax,QWORD PTR [rdx+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_ad9:
	/* 0xad9: je     af4 <do_action+0x9c3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xad9, 0xaf4, x86_l_af4);
x86_l_adb:
	/* 0xadb: mov    ebp,DWORD PTR [rdx+r12*2+0x5e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 1), 24192ULL);
x86_l_ae3:
	/* 0xae3: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ae5:
	/* 0xae5: jmp    afc <do_action+0x9cb> */
	X86_SIM_X86_SUB_JMP(0xae5, 0xafc, x86_l_afc);
x86_l_ae7:
	/* 0xae7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aec:
	/* 0xaec: mov    rax,QWORD PTR [rdx+r12*2+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 1), 24184ULL);
x86_l_af4:
	/* 0xaf4: mov    ebp,DWORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_af7:
	/* 0xaf7: sub    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_af9:
	/* 0xaf9: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_afc:
	/* 0xafc: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_afe:
	/* 0xafe: jle    a0d <do_action+0x8dc> */
	X86_SIM_X86_SUB_JCC(X86_CC_LE, 0xafe, 0xa0d, x86_l_a0d);
x86_l_b04:
	/* 0xb04: add    eax,0x3ffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 16380ULL);
x86_l_b09:
	/* 0xb09: and    eax,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_b0e:
	/* 0xb0e: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_b11:
	/* 0xb11: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_b16:
	/* 0xb16: cmovge ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_GE);
x86_l_b19:
	/* 0xb19: movzx  ebx,BYTE PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 80ULL);
x86_l_b1e:
	/* 0xb1e: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b23:
	/* 0xb23: lea    rdi,[rcx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_b27:
	/* 0xb27: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b2a:
	/* 0xb2a: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_b31:
	/* 0xb31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b36:
	/* 0xb36: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b38:
	/* 0xb38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3a:
	/* 0xb3a: add    ebp,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b3c:
	/* 0xb3c: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b44:
	/* 0xb44: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_b46:
	/* 0xb46: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b4b:
	/* 0xb4b: jmp    a0d <do_action+0x8dc> */
	X86_SIM_X86_SUB_JMP(0xb4b, 0xa0d, x86_l_a0d);
x86_l_b50:
	/* 0xb50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b55:
	/* 0xb55: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_b5c:
	/* 0xb5c: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b61:
	/* 0xb61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b63:
	/* 0xb63: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b66:
	/* 0xb66: je     b85 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xb66, 0xb85, x86_l_b85);
x86_l_b68:
	/* 0xb68: imul   rcx,QWORD PTR [rsp+0x78],0xfffffffffff0bdc0 */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 515395075520ULL);
x86_l_b71:
	/* 0xb71: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b76:
	/* 0xb76: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b79:
	/* 0xb79: cmp    QWORD PTR [rax],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7c:
	/* 0xb7c: jbe    b85 <do_action+0xa54> */
	X86_SIM_X86_SUB_JCC(X86_CC_BE, 0xb7c, 0xb85, x86_l_b85);
x86_l_b7e:
	/* 0xb7e: mov    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b83:
	/* 0xb83: jmp    b9d <do_action+0xa6c> */
	X86_SIM_X86_SUB_JMP(0xb83, 0xb9d, x86_l_b9d);
x86_l_b85:
	/* 0xb85: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b8a:
	/* 0xb8a: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ratelimit_map)));
x86_l_b91:
	/* 0xb91: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_b94:
	/* 0xb94: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b99:
	/* 0xb99: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9b:
	/* 0xb9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9d:
	/* 0xb9d: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ba2:
	/* 0xba2: lea    eax,[r14+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_ba6:
	/* 0xba6: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_bac:
	/* 0xbac: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb1:
	/* 0xbb1: je     bd7 <do_action+0xaa6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbb1, 0xbd7, x86_l_bd7);
x86_l_bb3:
	/* 0xbb3: or     BYTE PTR [r8+0x1],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967298ULL);
x86_l_bb8:
	/* 0xbb8: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_bbd:
	/* 0xbbd: mov    rsi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_bc4:
	/* 0xbc4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bc7:
	/* 0xbc7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc9:
	/* 0xbc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcb:
	/* 0xbcb: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd0:
	/* 0xbd0: mov    QWORD PTR [r8+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bd7:
	/* 0xbd7: lea    eax,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bdb:
	/* 0xbdb: cmp    DWORD PTR [r15+rax*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 17179869184ULL);
x86_l_be1:
	/* 0xbe1: je     c0a <do_action+0xad9> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xbe1, 0xc0a, x86_l_c0a);
x86_l_be3:
	/* 0xbe3: or     BYTE PTR [r8+0x1],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967300ULL);
x86_l_be8:
	/* 0xbe8: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_bed:
	/* 0xbed: mov    rsi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_trace_map)));
x86_l_bf4:
	/* 0xbf4: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_bf9:
	/* 0xbf9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bfc:
	/* 0xbfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfe:
	/* 0xbfe: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c03:
	/* 0xc03: mov    QWORD PTR [r8+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c0a:
	/* 0xc0a: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_c0e:
	/* 0xc0e: cmp    DWORD PTR [r15+r14*4+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 17179869184ULL);
x86_l_c14:
	/* 0xc14: je     c1b <do_action+0xaea> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc14, 0xc1b, x86_l_c1b);
x86_l_c16:
	/* 0xc16: or     BYTE PTR [r8+0x1],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R8, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 4294967304ULL);
x86_l_c1b:
	/* 0xc1b: mov    QWORD PTR [r8+0x70],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c1f:
	/* 0xc1f: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c22:
	/* 0xc22: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_c25:
	/* 0xc25: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_c2c:
	/* 0xc2c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_c2d:
	/* 0xc2d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_c2f:
	/* 0xc2f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_c31:
	/* 0xc31: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_c33:
	/* 0xc33: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_c35:
	/* 0xc35: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_c36:
	/* 0xc36: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_c37:
	/* 0xc37: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_c3a:
	/* 0xc3a: mov    rax,QWORD PTR [r8+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_c42:
	/* 0xc42: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_c47:
	/* 0xc47: mov    rax,QWORD PTR [r8+rax*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 144ULL);
x86_l_c4f:
	/* 0xc4f: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_c53:
	/* 0xc53: jmp    755 <do_action+0x624> */
	X86_SIM_X86_SUB_JMP(0xc53, 0x755, x86_l_755);
x86_l_c58:
	/* 0xc58: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_c60:
	/* 0xc60: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c65:
	/* 0xc65: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_c6c:
	/* 0xc6c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c6f:
	/* 0xc6f: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c74:
	/* 0xc74: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c76:
	/* 0xc76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c78:
	/* 0xc78: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_c7b:
	/* 0xc7b: je     626 <do_action+0x4f5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc7b, 0x626, x86_l_626);
x86_l_c81:
	/* 0xc81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c86:
	/* 0xc86: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_c8d:
	/* 0xc8d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c92:
	/* 0xc92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c94:
	/* 0xc94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c97:
	/* 0xc97: je     626 <do_action+0x4f5> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xc97, 0x626, x86_l_626);
x86_l_c9d:
	/* 0xc9d: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ca1:
	/* 0xca1: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ca4:
	/* 0xca4: jmp    626 <do_action+0x4f5> */
	X86_SIM_X86_SUB_JMP(0xca4, 0x626, x86_l_626);
x86_l_ca9:
	/* 0xca9: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_cb1:
	/* 0xcb1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cb6:
	/* 0xcb6: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_cbd:
	/* 0xcbd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_cc0:
	/* 0xcc0: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cc5:
	/* 0xcc5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc7:
	/* 0xcc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc9:
	/* 0xcc9: jmp    7e2 <do_action+0x6b1> */
	X86_SIM_X86_SUB_JMP(0xcc9, 0x7e2, x86_l_7e2);
x86_l_cce:
	/* 0xcce: mov    DWORD PTR [rsp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_cd6:
	/* 0xcd6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cdb:
	/* 0xcdb: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_ce2:
	/* 0xce2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ce5:
	/* 0xce5: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cea:
	/* 0xcea: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cec:
	/* 0xcec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cee:
	/* 0xcee: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_cf1:
	/* 0xcf1: je     7d2 <do_action+0x6a1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xcf1, 0x7d2, x86_l_7d2);
x86_l_cf7:
	/* 0xcf7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cfc:
	/* 0xcfc: mov    rdi,QWORD PTR [rip+0x2810] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&enforcer_missed_notifications)));
x86_l_d03:
	/* 0xd03: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d08:
	/* 0xd08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0a:
	/* 0xd0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d0d:
	/* 0xd0d: je     7d2 <do_action+0x6a1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xd0d, 0x7d2, x86_l_7d2);
x86_l_d13:
	/* 0xd13: mov    ecx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_d17:
	/* 0xd17: add DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d1a:
	/* 0xd1a: jmp    7d2 <do_action+0x6a1> */
	X86_SIM_X86_SUB_JMP(0xd1a, 0x7d2, x86_l_7d2);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x22ULL: goto x86_l_22;
	case 0x53ULL: goto x86_l_53;
	case 0x93ULL: goto x86_l_93;
	case 0xc7ULL: goto x86_l_c7;
	case 0xe8ULL: goto x86_l_e8;
	case 0x109ULL: goto x86_l_109;
	case 0x126ULL: goto x86_l_126;
	case 0x173ULL: goto x86_l_173;
	case 0x254ULL: goto x86_l_254;
	case 0x26dULL: goto x86_l_26d;
	case 0x2c2ULL: goto x86_l_2c2;
	case 0x2e0ULL: goto x86_l_2e0;
	case 0x35dULL: goto x86_l_35d;
	case 0x3b9ULL: goto x86_l_3b9;
	case 0x426ULL: goto x86_l_426;
	case 0x49dULL: goto x86_l_49d;
	case 0x4b8ULL: goto x86_l_4b8;
	case 0x4faULL: goto x86_l_4fa;
	case 0x522ULL: goto x86_l_522;
	case 0x572ULL: goto x86_l_572;
	case 0x58aULL: goto x86_l_58a;
	case 0x5b7ULL: goto x86_l_5b7;
	case 0x5d1ULL: goto x86_l_5d1;
	case 0x5e9ULL: goto x86_l_5e9;
	case 0x612ULL: goto x86_l_612;
	case 0x639ULL: goto x86_l_639;
	case 0x663ULL: goto x86_l_663;
	case 0x695ULL: goto x86_l_695;
	case 0x6b9ULL: goto x86_l_6b9;
	case 0x763ULL: goto x86_l_763;
	case 0x78bULL: goto x86_l_78b;
	case 0x7bbULL: goto x86_l_7bb;
	case 0x80aULL: goto x86_l_80a;
	case 0x843ULL: goto x86_l_843;
	case 0x86dULL: goto x86_l_86d;
	case 0x88cULL: goto x86_l_88c;
	case 0x8c5ULL: goto x86_l_8c5;
	case 0x906ULL: goto x86_l_906;
	case 0x92aULL: goto x86_l_92a;
	case 0x954ULL: goto x86_l_954;
	case 0x987ULL: goto x86_l_987;
	case 0x9c0ULL: goto x86_l_9c0;
	case 0xa00ULL: goto x86_l_a00;
	case 0xa36ULL: goto x86_l_a36;
	case 0xa56ULL: goto x86_l_a56;
	case 0xaa5ULL: goto x86_l_aa5;
	case 0xac1ULL: goto x86_l_ac1;
	case 0xb3aULL: goto x86_l_b3a;
	case 0xb63ULL: goto x86_l_b63;
	case 0xb9dULL: goto x86_l_b9d;
	case 0xbcbULL: goto x86_l_bcb;
	case 0xbfeULL: goto x86_l_bfe;
	case 0xc78ULL: goto x86_l_c78;
	case 0xc94ULL: goto x86_l_c94;
	case 0xcc9ULL: goto x86_l_cc9;
	case 0xceeULL: goto x86_l_cee;
	case 0xd0aULL: goto x86_l_d0a;
	}

}

X86_SIM_LICENSE();
