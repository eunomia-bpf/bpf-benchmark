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
int bcc_runqlat_handle_sched_switch_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1:
	/* 0x1: mov    rax,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5:
	/* 0x5: mov    rsi,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9:
	/* 0x9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c:
	/* 0xc: call   0 <handle_sched_switch> */
	X86_SIM_X86_CALL(x86_l_19, 0x11ULL);
x86_l_11:
	/* 0x11: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13:
	/* 0x13: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_14:
	/* 0x14: jmp    370 <handle_switch+0x357> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_370:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_19 */
x86_l_19:
	/* 0x19: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1a:
	/* 0x1a: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1c:
	/* 0x1c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1e:
	/* 0x1e: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f:
	/* 0x1f: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_23:
	/* 0x23: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_26:
	/* 0x26: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_cg)));
x86_l_30:
	/* 0x30: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33:
	/* 0x33: je     4c <handle_switch+0x33> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x33, 0x4c, x86_l_4c);
x86_l_35:
	/* 0x35: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_map)));
x86_l_3c:
	/* 0x3c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e:
	/* 0x3e: call   43 <handle_switch+0x2a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_current_task_under_cgroup);
x86_l_43:
	/* 0x43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: je     2ef <handle_switch+0x2d6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x46, 0x2ef, x86_l_2ef);
x86_l_4c:
	/* 0x4c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51:
	/* 0x51: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56:
	/* 0x56: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_59:
	/* 0x59: call   5e <handle_switch+0x45> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_5e:
	/* 0x5e: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_63:
	/* 0x63: jne    d8 <handle_switch+0xbf> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x63, 0xd8, x86_l_d8);
x86_l_65:
	/* 0x65: lea    rdx,[r14+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_6c:
	/* 0x6c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71:
	/* 0x71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_76:
	/* 0x76: call   7b <handle_switch+0x62> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_7b:
	/* 0x7b: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7f:
	/* 0x7f: add    r14,0xad0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 2768ULL);
x86_l_86:
	/* 0x86: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b:
	/* 0x8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_90:
	/* 0x90: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_93:
	/* 0x93: call   98 <handle_switch+0x7f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_98:
	/* 0x98: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c:
	/* 0x9c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a0:
	/* 0xa0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a2:
	/* 0xa2: je     d8 <handle_switch+0xbf> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xa2, 0xd8, x86_l_d8);
x86_l_a4:
	/* 0xa4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_tgid)));
x86_l_ab:
	/* 0xab: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: je     b6 <handle_switch+0x9d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xae, 0xb6, x86_l_b6);
x86_l_b0:
	/* 0xb0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2:
	/* 0xb2: cmp    eax,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_b4:
	/* 0xb4: jne    d8 <handle_switch+0xbf> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xb4, 0xd8, x86_l_d8);
x86_l_b6:
	/* 0xb6: call   bb <handle_switch+0xa2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0:
	/* 0xc0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_c7:
	/* 0xc7: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cc:
	/* 0xcc: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1:
	/* 0xd1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d3:
	/* 0xd3: call   d8 <handle_switch+0xbf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_d8:
	/* 0xd8: lea    rdx,[rbx+0xad0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2768ULL);
x86_l_df:
	/* 0xdf: lea    r14,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e4:
	/* 0xe4: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e7:
	/* 0xe7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ec:
	/* 0xec: call   f1 <handle_switch+0xd8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_f1:
	/* 0xf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_f8:
	/* 0xf8: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: call   100 <handle_switch+0xe7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_100:
	/* 0x100: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_103:
	/* 0x103: je     2ef <handle_switch+0x2d6> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x103, 0x2ef, x86_l_2ef);
x86_l_109:
	/* 0x109: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: call   111 <handle_switch+0xf8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_111:
	/* 0x111: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_114:
	/* 0x114: sub    r15,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_117:
	/* 0x117: js     2de <handle_switch+0x2c5> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x117, 0x2de, x86_l_2de);
x86_l_11d:
	/* 0x11d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_per_process)));
x86_l_124:
	/* 0x124: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127:
	/* 0x127: je     13f <handle_switch+0x126> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x127, 0x13f, x86_l_13f);
x86_l_129:
	/* 0x129: lea    rdx,[rbx+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_130:
	/* 0x130: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_133:
	/* 0x133: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_138:
	/* 0x138: call   13d <handle_switch+0x124> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_13d:
	/* 0x13d: jmp    156 <handle_switch+0x13d> */
	X86_SIM_X86_SUB_JMP(0x13d, 0x156, x86_l_156);
x86_l_13f:
	/* 0x13f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_per_thread)));
x86_l_146:
	/* 0x146: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149:
	/* 0x149: je     2fa <handle_switch+0x2e1> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x149, 0x2fa, x86_l_2fa);
x86_l_14f:
	/* 0x14f: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_153:
	/* 0x153: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156:
	/* 0x156: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&hists)));
x86_l_15d:
	/* 0x15d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_160:
	/* 0x160: call   165 <handle_switch+0x14c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_165:
	/* 0x165: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_168:
	/* 0x168: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: je     223 <handle_switch+0x20a> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x16b, 0x223, x86_l_223);
x86_l_171:
	/* 0x171: cmp    BYTE PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_176:
	/* 0x176: jne    190 <handle_switch+0x177> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x176, 0x190, x86_l_190);
x86_l_178:
	/* 0x178: lea    rdi,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17c:
	/* 0x17c: add    rbx,0xcf0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 3312ULL);
x86_l_183:
	/* 0x183: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_188:
	/* 0x188: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: call   190 <handle_switch+0x177> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel_str);
x86_l_190:
	/* 0x190: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_ms)));
x86_l_197:
	/* 0x197: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a:
	/* 0x19a: mov    eax,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1000ULL);
x86_l_19f:
	/* 0x19f: mov    ecx,0xf4240 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1000000ULL);
x86_l_1a4:
	/* 0x1a4: cmove  rcx,rax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_1a8:
	/* 0x1a8: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1ab:
	/* 0x1ab: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1af:
	/* 0x1af: je     26a <handle_switch+0x251> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1af, 0x26a, x86_l_26a);
x86_l_1b5:
	/* 0x1b5: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1b8:
	/* 0x1b8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ba:
	/* 0x1ba: div    rcx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1bd:
	/* 0x1bd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1c0:
	/* 0x1c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2:
	/* 0x1c2: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1c6:
	/* 0x1c6: je     280 <handle_switch+0x267> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c6, 0x280, x86_l_280);
x86_l_1cc:
	/* 0x1cc: cmp    edx,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 65536ULL);
x86_l_1d2:
	/* 0x1d2: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1d5:
	/* 0x1d5: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1d8:
	/* 0x1d8: shrx   edx,edx,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RCX, X86_ALU_SHR);
x86_l_1dd:
	/* 0x1dd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df:
	/* 0x1df: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1e5:
	/* 0x1e5: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1e8:
	/* 0x1e8: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1eb:
	/* 0x1eb: shrx   edx,edx,eax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RAX, X86_ALU_SHR);
x86_l_1f0:
	/* 0x1f0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2:
	/* 0x1f2: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1f5:
	/* 0x1f5: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1f9:
	/* 0x1f9: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1fc:
	/* 0x1fc: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_201:
	/* 0x201: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203:
	/* 0x203: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_206:
	/* 0x206: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_20a:
	/* 0x20a: add    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20c:
	/* 0x20c: shrx   edx,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_211:
	/* 0x211: shr    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_213:
	/* 0x213: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_215:
	/* 0x215: or     eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_217:
	/* 0x217: or     eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_219:
	/* 0x219: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_21b:
	/* 0x21b: add    eax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 32ULL);
x86_l_21e:
	/* 0x21e: jmp    2ce <handle_switch+0x2b5> */
	X86_SIM_X86_SUB_JMP(0x21e, 0x2ce, x86_l_2ce);
x86_l_223:
	/* 0x223: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&hists)));
x86_l_22a:
	/* 0x22a: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_231:
	/* 0x231: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_234:
	/* 0x234: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_239:
	/* 0x239: call   23e <handle_switch+0x225> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_23e:
	/* 0x23e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_241:
	/* 0x241: je     24d <handle_switch+0x234> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x241, 0x24d, x86_l_24d);
x86_l_243:
	/* 0x243: cmp    rax,0xffffffffffffffef */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551599ULL);
x86_l_247:
	/* 0x247: jne    2de <handle_switch+0x2c5> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x247, 0x2de, x86_l_2de);
x86_l_24d:
	/* 0x24d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&hists)));
x86_l_254:
	/* 0x254: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_257:
	/* 0x257: call   25c <handle_switch+0x243> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_25c:
	/* 0x25c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_262:
	/* 0x262: jne    171 <handle_switch+0x158> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x262, 0x171, x86_l_171);
x86_l_268:
	/* 0x268: jmp    2de <handle_switch+0x2c5> */
	X86_SIM_X86_SUB_JMP(0x268, 0x2de, x86_l_2de);
x86_l_26a:
	/* 0x26a: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_26d:
	/* 0x26d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26f:
	/* 0x26f: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_271:
	/* 0x271: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_274:
	/* 0x274: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_276:
	/* 0x276: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_27a:
	/* 0x27a: jne    1cc <handle_switch+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x27a, 0x1cc, x86_l_1cc);
x86_l_280:
	/* 0x280: cmp    eax,0x10000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 65536ULL);
x86_l_285:
	/* 0x285: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_288:
	/* 0x288: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_28b:
	/* 0x28b: shrx   edx,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHR);
x86_l_290:
	/* 0x290: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_292:
	/* 0x292: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_298:
	/* 0x298: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_29b:
	/* 0x29b: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_29e:
	/* 0x29e: shrx   edx,edx,eax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RAX, X86_ALU_SHR);
x86_l_2a3:
	/* 0x2a3: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a5:
	/* 0x2a5: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2a8:
	/* 0x2a8: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_2ac:
	/* 0x2ac: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_2af:
	/* 0x2af: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_2b4:
	/* 0x2b4: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b6:
	/* 0x2b6: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2b9:
	/* 0x2b9: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_2bd:
	/* 0x2bd: add    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2bf:
	/* 0x2bf: shrx   edx,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_2c4:
	/* 0x2c4: shr    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2c6:
	/* 0x2c6: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2c8:
	/* 0x2c8: or     eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_2ca:
	/* 0x2ca: or     eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_2cc:
	/* 0x2cc: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2ce:
	/* 0x2ce: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2d1:
	/* 0x2d1: mov    ecx,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_2d6:
	/* 0x2d6: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2d9:
	/* 0x2d9: inc DWORD PTR [r14+rcx*4] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2de:
	/* 0x2de: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_2e5:
	/* 0x2e5: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ea:
	/* 0x2ea: call   2ef <handle_switch+0x2d6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_2ef:
	/* 0x2ef: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2f3:
	/* 0x2f3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2f4:
	/* 0x2f4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2f6:
	/* 0x2f6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2f8:
	/* 0x2f8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2f9:
	/* 0x2f9: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
x86_l_2fa:
	/* 0x2fa: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_per_pidns)));
x86_l_301:
	/* 0x301: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304:
	/* 0x304: je     364 <handle_switch+0x34b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x304, 0x364, x86_l_364);
x86_l_306:
	/* 0x306: lea    rdx,[rbx+0xb38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_30d:
	/* 0x30d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_312:
	/* 0x312: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_317:
	/* 0x317: call   31c <handle_switch+0x303> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_31c:
	/* 0x31c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_321:
	/* 0x321: lea    rdx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_325:
	/* 0x325: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32a:
	/* 0x32a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32f:
	/* 0x32f: call   334 <handle_switch+0x31b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_334:
	/* 0x334: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_338:
	/* 0x338: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_33c:
	/* 0x33c: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_340:
	/* 0x340: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_347:
	/* 0x347: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34c:
	/* 0x34c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_351:
	/* 0x351: call   356 <handle_switch+0x33d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_356:
	/* 0x356: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b:
	/* 0x35b: sub    rdx,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_35f:
	/* 0x35f: jmp    130 <handle_switch+0x117> */
	X86_SIM_X86_SUB_JMP(0x35f, 0x130, x86_l_130);
x86_l_364:
	/* 0x364: mov    DWORD PTR [rsp],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_36b:
	/* 0x36b: jmp    156 <handle_switch+0x13d> */
	X86_SIM_X86_SUB_JMP(0x36b, 0x156, x86_l_156);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x11ULL: goto x86_l_11;
	case 0x43ULL: goto x86_l_43;
	case 0x5eULL: goto x86_l_5e;
	case 0x7bULL: goto x86_l_7b;
	case 0x98ULL: goto x86_l_98;
	case 0xbbULL: goto x86_l_bb;
	case 0xd8ULL: goto x86_l_d8;
	case 0xf1ULL: goto x86_l_f1;
	case 0x100ULL: goto x86_l_100;
	case 0x111ULL: goto x86_l_111;
	case 0x13dULL: goto x86_l_13d;
	case 0x165ULL: goto x86_l_165;
	case 0x190ULL: goto x86_l_190;
	case 0x23eULL: goto x86_l_23e;
	case 0x25cULL: goto x86_l_25c;
	case 0x2efULL: goto x86_l_2ef;
	case 0x31cULL: goto x86_l_31c;
	case 0x334ULL: goto x86_l_334;
	case 0x356ULL: goto x86_l_356;
	}

}

X86_SIM_LICENSE();
