extern char cgroup_map;
extern char filter_cg;
extern char hists;
extern char start;
extern char targ_ms;
extern char targ_per_pidns;
extern char targ_per_process;
extern char targ_per_thread;
extern char targ_tgid;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

static const __u64 __x86_rodata_0[2] = {0ULL, 0ULL};

SEC("xdp")
int bcc_runqlat_handle_switch_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x5: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_6:
	/* 0x6: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_a:
	/* 0xa: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_10:
	/* 0x10: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_cg)));
x86_l_17:
	/* 0x17: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a:
	/* 0x1a: je     33 <handle_switch+0x33> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a, 0x33, x86_l_33);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_map)));
x86_l_23:
	/* 0x23: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25:
	/* 0x25: call   2a <handle_switch+0x2a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_current_task_under_cgroup);
x86_l_2a:
	/* 0x2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d:
	/* 0x2d: je     2d6 <handle_switch+0x2d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d, 0x2d6, x86_l_2d6);
x86_l_33:
	/* 0x33: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38:
	/* 0x38: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d:
	/* 0x3d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_40:
	/* 0x40: call   45 <handle_switch+0x45> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_45:
	/* 0x45: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4a:
	/* 0x4a: jne    bf <handle_switch+0xbf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a, 0xbf, x86_l_bf);
x86_l_4c:
	/* 0x4c: lea    rdx,[r14+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_53:
	/* 0x53: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58:
	/* 0x58: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5d:
	/* 0x5d: call   62 <handle_switch+0x62> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_62:
	/* 0x62: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66:
	/* 0x66: add    r14,0xad0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 2768ULL);
x86_l_6d:
	/* 0x6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72:
	/* 0x72: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_77:
	/* 0x77: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_7a:
	/* 0x7a: call   7f <handle_switch+0x7f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_7f:
	/* 0x7f: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83:
	/* 0x83: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_87:
	/* 0x87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_89:
	/* 0x89: je     bf <handle_switch+0xbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89, 0xbf, x86_l_bf);
x86_l_8b:
	/* 0x8b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_tgid)));
x86_l_92:
	/* 0x92: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95:
	/* 0x95: je     9d <handle_switch+0x9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95, 0x9d, x86_l_9d);
x86_l_97:
	/* 0x97: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99:
	/* 0x99: cmp    eax,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_9b:
	/* 0x9b: jne    bf <handle_switch+0xbf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b, 0xbf, x86_l_bf);
x86_l_9d:
	/* 0x9d: call   a2 <handle_switch+0xa2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_a2:
	/* 0xa2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a7:
	/* 0xa7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_ae:
	/* 0xae: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b3:
	/* 0xb3: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8:
	/* 0xb8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba:
	/* 0xba: call   bf <handle_switch+0xbf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_bf:
	/* 0xbf: lea    rdx,[rbx+0xad0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2768ULL);
x86_l_c6:
	/* 0xc6: lea    r14,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cb:
	/* 0xcb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d3:
	/* 0xd3: call   d8 <handle_switch+0xd8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_d8:
	/* 0xd8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_df:
	/* 0xdf: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e2:
	/* 0xe2: call   e7 <handle_switch+0xe7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_e7:
	/* 0xe7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea:
	/* 0xea: je     2d6 <handle_switch+0x2d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea, 0x2d6, x86_l_2d6);
x86_l_f0:
	/* 0xf0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: call   f8 <handle_switch+0xf8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_f8:
	/* 0xf8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: sub    r15,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_fe:
	/* 0xfe: js     2c5 <handle_switch+0x2c5> */
	X86_SIM_X86_JCC(X86_CC_S, 0xfe, 0x2c5, x86_l_2c5);
x86_l_104:
	/* 0x104: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_per_process)));
x86_l_10b:
	/* 0x10b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e:
	/* 0x10e: je     126 <handle_switch+0x126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e, 0x126, x86_l_126);
x86_l_110:
	/* 0x110: lea    rdx,[rbx+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_117:
	/* 0x117: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_11a:
	/* 0x11a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11f:
	/* 0x11f: call   124 <handle_switch+0x124> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_124:
	/* 0x124: jmp    13d <handle_switch+0x13d> */
	X86_SIM_X86_JMP(0x124, 0x13d, x86_l_13d);
x86_l_126:
	/* 0x126: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_per_thread)));
x86_l_12d:
	/* 0x12d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130:
	/* 0x130: je     2e5 <handle_switch+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130, 0x2e5, x86_l_2e5);
x86_l_136:
	/* 0x136: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13a:
	/* 0x13a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d:
	/* 0x13d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&hists)));
x86_l_144:
	/* 0x144: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_147:
	/* 0x147: call   14c <handle_switch+0x14c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_14c:
	/* 0x14c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_14f:
	/* 0x14f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_152:
	/* 0x152: je     20a <handle_switch+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152, 0x20a, x86_l_20a);
x86_l_158:
	/* 0x158: cmp    BYTE PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_15d:
	/* 0x15d: jne    177 <handle_switch+0x177> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15d, 0x177, x86_l_177);
x86_l_15f:
	/* 0x15f: lea    rdi,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_163:
	/* 0x163: add    rbx,0xcf0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 3312ULL);
x86_l_16a:
	/* 0x16a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_16f:
	/* 0x16f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_172:
	/* 0x172: call   177 <handle_switch+0x177> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel_str);
x86_l_177:
	/* 0x177: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_ms)));
x86_l_17e:
	/* 0x17e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_181:
	/* 0x181: mov    eax,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1000ULL);
x86_l_186:
	/* 0x186: mov    ecx,0xf4240 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1000000ULL);
x86_l_18b:
	/* 0x18b: cmove  rcx,rax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_18f:
	/* 0x18f: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_192:
	/* 0x192: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_196:
	/* 0x196: je     251 <handle_switch+0x251> */
	X86_SIM_X86_JCC(X86_CC_E, 0x196, 0x251, x86_l_251);
x86_l_19c:
	/* 0x19c: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_19f:
	/* 0x19f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a1:
	/* 0x1a1: div    rcx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1a4:
	/* 0x1a4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1a7:
	/* 0x1a7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9:
	/* 0x1a9: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ad:
	/* 0x1ad: je     267 <handle_switch+0x267> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x267, x86_l_267);
x86_l_1b3:
	/* 0x1b3: cmp    edx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 65536ULL);
x86_l_1b9:
	/* 0x1b9: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1bc:
	/* 0x1bc: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1bf:
	/* 0x1bf: shrx   edx,edx,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RCX, X86_ALU_SHR);
x86_l_1c4:
	/* 0x1c4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c6:
	/* 0x1c6: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1cc:
	/* 0x1cc: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1cf:
	/* 0x1cf: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1d2:
	/* 0x1d2: shrx   edx,edx,eax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RAX, X86_ALU_SHR);
x86_l_1d7:
	/* 0x1d7: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9:
	/* 0x1d9: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1dc:
	/* 0x1dc: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1e0:
	/* 0x1e0: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1e3:
	/* 0x1e3: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_1e8:
	/* 0x1e8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea:
	/* 0x1ea: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1ed:
	/* 0x1ed: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1f1:
	/* 0x1f1: add    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f3:
	/* 0x1f3: shrx   edx,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_1f8:
	/* 0x1f8: shr    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_1fa:
	/* 0x1fa: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fc:
	/* 0x1fc: or     eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fe:
	/* 0x1fe: or     eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_200:
	/* 0x200: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_202:
	/* 0x202: add    eax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 32ULL);
x86_l_205:
	/* 0x205: jmp    2b5 <handle_switch+0x2b5> */
	X86_SIM_X86_JMP(0x205, 0x2b5, x86_l_2b5);
x86_l_20a:
	/* 0x20a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&hists)));
x86_l_211:
	/* 0x211: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_218:
	/* 0x218: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_21b:
	/* 0x21b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_220:
	/* 0x220: call   225 <handle_switch+0x225> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_225:
	/* 0x225: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_228:
	/* 0x228: je     234 <handle_switch+0x234> */
	X86_SIM_X86_JCC(X86_CC_E, 0x228, 0x234, x86_l_234);
x86_l_22a:
	/* 0x22a: cmp    rax,0xffffffffffffffef */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551599ULL);
x86_l_22e:
	/* 0x22e: jne    2c5 <handle_switch+0x2c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22e, 0x2c5, x86_l_2c5);
x86_l_234:
	/* 0x234: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&hists)));
x86_l_23b:
	/* 0x23b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_23e:
	/* 0x23e: call   243 <handle_switch+0x243> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_243:
	/* 0x243: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_246:
	/* 0x246: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_249:
	/* 0x249: jne    158 <handle_switch+0x158> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x249, 0x158, x86_l_158);
x86_l_24f:
	/* 0x24f: jmp    2c5 <handle_switch+0x2c5> */
	X86_SIM_X86_JMP(0x24f, 0x2c5, x86_l_2c5);
x86_l_251:
	/* 0x251: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_254:
	/* 0x254: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_256:
	/* 0x256: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_258:
	/* 0x258: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d:
	/* 0x25d: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_261:
	/* 0x261: jne    1b3 <handle_switch+0x1b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x261, 0x1b3, x86_l_1b3);
x86_l_267:
	/* 0x267: cmp    eax,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 65536ULL);
x86_l_26c:
	/* 0x26c: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_26f:
	/* 0x26f: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_272:
	/* 0x272: shrx   edx,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHR);
x86_l_277:
	/* 0x277: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_279:
	/* 0x279: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_27f:
	/* 0x27f: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_282:
	/* 0x282: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_285:
	/* 0x285: shrx   edx,edx,eax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RAX, X86_ALU_SHR);
x86_l_28a:
	/* 0x28a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28c:
	/* 0x28c: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_28f:
	/* 0x28f: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_293:
	/* 0x293: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_296:
	/* 0x296: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_29b:
	/* 0x29b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29d:
	/* 0x29d: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2a0:
	/* 0x2a0: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_2a4:
	/* 0x2a4: add    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a6:
	/* 0x2a6: shrx   edx,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_2ab:
	/* 0x2ab: shr    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2ad:
	/* 0x2ad: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2af:
	/* 0x2af: or     eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_2b1:
	/* 0x2b1: or     eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_2b3:
	/* 0x2b3: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2b5:
	/* 0x2b5: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2b8:
	/* 0x2b8: mov    ecx,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_2bd:
	/* 0x2bd: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2c0:
	/* 0x2c0: inc DWORD PTR [r14+rcx*4] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_2cc:
	/* 0x2cc: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d1:
	/* 0x2d1: call   2d6 <handle_switch+0x2d6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_2d6:
	/* 0x2d6: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2da:
	/* 0x2da: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2db:
	/* 0x2db: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2dd:
	/* 0x2dd: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2df:
	/* 0x2df: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2e0:
	/* 0x2e0: jmp    35b <handle_switch+0x35b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2e5:
	/* 0x2e5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_per_pidns)));
x86_l_2ec:
	/* 0x2ec: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef:
	/* 0x2ef: je     34f <handle_switch+0x34f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ef, 0x34f, x86_l_34f);
x86_l_2f1:
	/* 0x2f1: lea    rdx,[rbx+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_2f8:
	/* 0x2f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd:
	/* 0x2fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_302:
	/* 0x302: call   307 <handle_switch+0x307> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_307:
	/* 0x307: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30c:
	/* 0x30c: lea    rdx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_310:
	/* 0x310: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_315:
	/* 0x315: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31a:
	/* 0x31a: call   31f <handle_switch+0x31f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_31f:
	/* 0x31f: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_323:
	/* 0x323: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_327:
	/* 0x327: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_32b:
	/* 0x32b: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_332:
	/* 0x332: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_337:
	/* 0x337: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_33c:
	/* 0x33c: call   341 <handle_switch+0x341> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_341:
	/* 0x341: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_346:
	/* 0x346: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_34a:
	/* 0x34a: jmp    117 <handle_switch+0x117> */
	X86_SIM_X86_JMP(0x34a, 0x117, x86_l_117);
x86_l_34f:
	/* 0x34f: mov    DWORD PTR [rsp],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_356:
	/* 0x356: jmp    13d <handle_switch+0x13d> */
	X86_SIM_X86_JMP(0x356, 0x13d, x86_l_13d);
x86_l_35b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
